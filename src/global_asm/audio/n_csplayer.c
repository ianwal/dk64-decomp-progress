#include "common.h"
#include "n_synthInternals.h"
#include "n_seqp.h"

s32 func_global_asm_80733180(void *);
void func_global_asm_80737F40(ALCSPlayer *);

void func_global_asm_80732F10(N_ALCSPlayer *seqp, ALSeqpConfig *c) {
    // alCSPNew
    s32 i;
    u8 pad[8];
    ALEventListItem *items;
    ALVoiceState *vs;
    N_ALVoiceState *voices;

    ALHeap *hp = c->heap;

    seqp->bank = 0;
    seqp->target = 0;
    seqp->drvr = n_syn;
    seqp->chanMask = 0xFFFF;
    func_global_asm_80737F40(seqp);
    seqp->uspt = 0x1E8;
    seqp->nextDelta = 0;
    seqp->state = AL_STOPPED;
    seqp->vol = 0x7FFF;
    seqp->debugFlags = c->debugFlags;
    seqp->frameTime = AL_USEC_PER_FRAME;
    seqp->curTime = 0;
    seqp->initOsc = c->initOsc;
    seqp->updateOsc = c->updateOsc;
    seqp->stopOsc = c->stopOsc;
    seqp->unk7c = 0.0f;
    seqp->unk80 = 1.0f;
    seqp->queue = 0;
    seqp->unk89 = 0;
    seqp->unk88 = c->maxVoices;
    seqp->nextEvent.type = AL_SEQP_API_EVT;
    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapAlloc(hp, c->maxChannels, 0x34);
    __n_initChanState(seqp);
    voices = alHeapAlloc(hp, c->maxVoices, sizeof(N_ALVoiceState));
    seqp->vFreeList = NULL;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;
    }
    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;
    items = alHeapAlloc(hp, c->maxEvents, 0x1C);
    alEvtqNew(&seqp->evtq, items, c->maxEvents);
    seqp->node.next = NULL;
    seqp->node.handler = func_global_asm_80733180;
    seqp->node.clientData = seqp;
    func_global_asm_8073B640(seqp);
}

extern void func_global_asm_80733A88(N_ALCSPlayer *);
extern void func_global_asm_80733D8C(N_ALCSPlayer *, N_ALEvent *);
extern void func_global_asm_807359A0(ALCSPlayer *);
extern void func_global_asm_80735624(ALCSPlayer *, ALEvent *);
extern void func_global_asm_8073B900(N_ALVoice *v, f32 pitch);
extern f32 func_global_asm_8073BDC4(s32);
extern void func_global_asm_8073B9B0(N_ALVoice *, f32);
extern void func_global_asm_8073C820(N_ALVoice *, u8);
extern u8 func_global_asm_8073A7B8(N_ALVoiceState *, N_ALCSPlayer *);

// __n_CSPVoiceHandler
ALMicroTime func_global_asm_80733180(void *node)
{
	N_ALCSPlayer    *seqp = (N_ALCSPlayer *) node;
	N_ALEvent        evt;
	N_ALVoice       *voice;
	ALMicroTime      delta;
	N_ALVoiceState  *vs;
	void            *oscState;
	f32              oscValue;
	u8               chan;
    s32              pad;

	do {
		switch (seqp->nextEvent.type) {
		case (AL_SEQ_REF_EVT):
			func_global_asm_80733A88(seqp);
			break;

		case (AL_SEQP_API_EVT):
			evt.type = AL_SEQP_API_EVT;
			alEvtqPostEvent(&seqp->evtq, (N_ALEvent *)&evt, seqp->frameTime);
			break;

		case (AL_NOTE_END_EVT):
			voice = seqp->nextEvent.msg.note.voice;

			n_alSynStopVoice(voice);
			func_global_asm_8073B750(voice);
			vs = (N_ALVoiceState *)voice->clientPrivate;

			if (vs->flags) {
				__n_seqpStopOsc((N_ALSeqPlayer*)seqp,vs);
			}

			__n_unmapVoice((N_ALSeqPlayer*)seqp, voice);
			break;

		case (AL_SEQP_ENV_EVT):
			voice = seqp->nextEvent.msg.vol.voice;
			vs = (N_ALVoiceState *)voice->clientPrivate;

			if (vs->envPhase == AL_PHASE_ATTACK) {
				vs->envPhase = AL_PHASE_DECAY;
			}

			delta = seqp->nextEvent.msg.vol.delta;
			vs->envEndTime = seqp->curTime + delta;
			vs->envGain = seqp->nextEvent.msg.vol.vol;
			func_global_asm_8073B830(voice, __n_vsVol(vs, (N_ALSeqPlayer*)seqp), delta);
			break;

		case (AL_TREM_OSC_EVT):
			vs = seqp->nextEvent.msg.osc.vs;
			oscState = seqp->nextEvent.msg.osc.oscState;
			delta = (*seqp->updateOsc)(oscState,&oscValue);
			vs->tremelo = (u8)oscValue;
			func_global_asm_8073B830(&vs->voice, __n_vsVol(vs,(N_ALSeqPlayer*)seqp), __n_vsDelta(vs,seqp->curTime));
			evt.type = AL_TREM_OSC_EVT;
			evt.msg.osc.vs = vs;
			evt.msg.osc.oscState = oscState;
			alEvtqPostEvent(&seqp->evtq, &evt, delta);
			break;

		case (AL_VIB_OSC_EVT):
			vs = seqp->nextEvent.msg.osc.vs;
			oscState = seqp->nextEvent.msg.osc.oscState;
			chan = seqp->nextEvent.msg.osc.chan;
			delta = (*seqp->updateOsc)(oscState,&oscValue);
			vs->vibrato = oscValue;
			func_global_asm_8073B900( &vs->voice, vs->pitch * vs->vibrato * seqp->chanState[chan].pitchBend);

			if (seqp->chanState[chan].unk11) {
				func_global_asm_8073B9B0(&vs->voice,
						440.0f
                        * func_global_asm_8073BDC4(vs->key - vs->sound->keyMap->keyBase)
						* seqp->chanState[chan].pitchBend
						* vs->vibrato);
			}

			evt.type = AL_VIB_OSC_EVT;
			evt.msg.osc.vs = vs;
			evt.msg.osc.oscState = oscState;
			evt.msg.osc.chan = chan;
			alEvtqPostEvent(&seqp->evtq, &evt, delta);
			break;

		case (AL_SEQP_MIDI_EVT):
		case (AL_CSP_NOTEOFF_EVT):	/* nextEvent is a note off midi message */
			func_global_asm_80733D8C(seqp, &seqp->nextEvent);
			break;

		case (AL_SEQP_META_EVT):
			func_global_asm_80735624(seqp, &seqp->nextEvent);
			break;

		case (AL_SEQP_VOL_EVT):
			seqp->vol =  seqp->nextEvent.msg.spvol.vol;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				func_global_asm_8073B830(&vs->voice,
						__n_vsVol(vs, (N_ALSeqPlayer*)seqp),
						__n_vsDelta(vs, seqp->curTime));
			}
			break;

		case (AL_18_EVT):
			seqp->unk7c = seqp->nextEvent.msg.evt18.unk00;
			seqp->unk80 = seqp->nextEvent.msg.evt18.unk04;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				func_global_asm_8073C820(&vs->voice, func_global_asm_8073A7B8(vs, seqp));
			}
			break;

		case (AL_19_EVT):
			if (seqp->nextEvent.msg.evt19.unk01 < 8) {
				ALFxRef fx = func_global_asm_8073C8D0(seqp->nextEvent.msg.evt19.unk00);

				if (fx) {
					func_global_asm_8073C9C0(fx,
							(seqp->nextEvent.msg.evt19.unk02 << 3) | (seqp->nextEvent.msg.evt19.unk01 & 7),
							&seqp->nextEvent.msg.evt19.param);
				}
			} else {
				ALFxRef fx = func_global_asm_8073C948(seqp->nextEvent.msg.evt19.unk00);

				if (fx) {
					func_global_asm_8073CA04(fx, seqp->nextEvent.msg.evt19.unk01, &seqp->nextEvent.msg.evt19.param);
				}
			}
			break;

		case (AL_SEQP_PLAY_EVT):
			if (seqp->state != AL_PLAYING) {
				seqp->state = AL_PLAYING;
				func_global_asm_807359A0(seqp);
				/* seqp must be AL_PLAYING before we call this routine. */
			}
			break;

		case (AL_SEQP_STOP_EVT):
			if (seqp->state == AL_STOPPING ) {
				for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
					n_alSynStopVoice(&vs->voice);
					func_global_asm_8073B750(&vs->voice);

					if (vs->flags) {
						__n_seqpStopOsc((N_ALSeqPlayer*)seqp,vs);
					}

					__n_unmapVoice((N_ALSeqPlayer*)seqp, &vs->voice);
				}

				seqp->state = AL_STOPPED;

				/* alEvtqFlush(&seqp->evtq); - Don't flush event queue
				   anymore. */
				/* sct 1/3/96 - Don't overwrite nextEvent with
				   AL_SEQP_API_EVT or set nextDelta to
				   AL_USEC_PER_FRAME since we're not stopping event
				   processing. */
				/* sct 1/3/96 - Don't return here since we keep
				   processing events as usual. */
			}
			break;

		case (AL_SEQP_STOPPING_EVT):
			if (seqp->state == AL_PLAYING) {
				/* sct 12/29/95 - Remove events associated with the
				 * stopping sequence.  For compact sequence player,
				 * also remove all queued note off events since they
				 * are not contained in a compact sequence but are
				 * generated in response to note ons.  Note that
				 * flushing AL_SEQP_MIDI_EVTs may flush events that
				 * were posted after the call to alSeqpStop, so the
				 * application must queue these events either when
				 * the player is fully stopped, or when it is
				 * playing. */
				alEvtqFlushType(&seqp->evtq, AL_SEQ_REF_EVT);
				alEvtqFlushType(&seqp->evtq, AL_CSP_NOTEOFF_EVT);
				alEvtqFlushType(&seqp->evtq, AL_SEQP_MIDI_EVT);

				/* sct 1/3/96 - Check to see which voices need to be
				   killed and release them. */
				/* Unkilled voices should have note end events
				   occurring prior to KILL_TIME. */
				for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
					if (__n_voiceNeedsNoteKill ((N_ALSeqPlayer*)seqp, &vs->voice, KILL_TIME)) {
						__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp, &vs->voice, KILL_TIME);
					}
				}

				for (chan = 0; chan < 16; chan++) {
					seqp->chanState[chan].unk0d = seqp->chanState[chan].unk0e;

					if (seqp->chanState[chan].unk0d == 0) {
						seqp->chanMask &= (1 << chan) ^ 0xffff;
					} else {
						seqp->chanMask |= 1 << chan;
					}
				}

				seqp->state = AL_STOPPING;
				evt.type = AL_SEQP_STOP_EVT;
				alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
			}
			break;

		case (AL_SEQP_PRIORITY_EVT):
			chan = seqp->nextEvent.msg.sppriority.chan;
			seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.priority;
			break;

		case (AL_SEQP_SEQ_EVT):
			/* Must be done playing to change sequences. */

			seqp->target = seqp->nextEvent.msg.spseq.seq;
			seqp->chanMask = 0xffff;

			if (seqp->bank) {
				__n_initFromBank((N_ALSeqPlayer *)seqp, seqp->bank);
			}
			break;

		case (AL_SEQP_BANK_EVT):
			/* Must be fully stopped to change banks. */

			seqp->bank = seqp->nextEvent.msg.spbank.bank;
			__n_initFromBank((N_ALSeqPlayer *)seqp, seqp->bank);
			break;

			/* sct 11/6/95 - these events should
			   now be handled by func_global_asm_80733A88 */

		case (AL_SEQ_END_EVT):
		case (AL_TEMPO_EVT):
		case (AL_SEQ_MIDI_EVT):
			break;
		}

		seqp->nextDelta = alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent);
	} while (seqp->nextDelta == 0);

	/*
	 * assume that next callback won't be more than half an
	 * hour away
	 */
	seqp->curTime += seqp->nextDelta;		/* sct 11/7/95 */
	return seqp->nextDelta;
}

void func_global_asm_80733A88(N_ALCSPlayer *seqp) {
    // __CSPHandleNextSeqEvent
    ALEvent	evt;

    /* sct 1/5/96 - Do nothing if we don't have a target sequence. */
    if (seqp->target == NULL)
	return;

    n_alCSeqNextEvent(seqp->target, &evt, 1);

    switch (evt.type)
    {
      case AL_SEQ_MIDI_EVT:
          func_global_asm_80733D8C(seqp, &evt);
	  func_global_asm_807359A0(seqp);
	  break;

      case AL_TEMPO_EVT:
          func_global_asm_80735624(seqp, &evt);
	  func_global_asm_807359A0(seqp);
	  break;

      case AL_SEQ_END_EVT:
	  seqp->state = AL_STOPPING;      
	  evt.type    = AL_SEQP_STOP_EVT;
	  alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
	  break;

      case AL_TRACK_END:
      case AL_CSP_LOOPSTART:
      case AL_CSP_LOOPEND:
	  func_global_asm_807359A0(seqp);
	  break;
      default:
      break;
    }
}

void func_global_asm_80733B88(N_ALCSPlayer *seqp, u8 channel)
{
	N_ALVoiceState *vs;

	for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
		if (vs->channel == channel && vs->envPhase != AL_PHASE_RELEASE) {
			s16 volume = __n_vsVol(vs, (N_ALSeqPlayer *) seqp);

			func_global_asm_8073B830(&vs->voice, volume, __n_vsDelta(vs, seqp->curTime));
		}
	}
}

void func_global_asm_80733C34(N_ALCSPlayer *seqp, u8 channel)
{
	N_ALVoiceState *vs;
	s16 sp2a;
	s8 sp29 = (s8)seqp->chanState[channel].unk12 - 64;
	f32 sp24 = seqp->chanState[channel].pitchBend;

	for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		if (vs->channel == channel) {
			sp2a = seqp->chanState[channel].unk11;

			func_global_asm_8073BA60(&vs->voice, sp2a);

			if (sp2a) {
				func_global_asm_8073B9B0(&vs->voice, func_global_asm_8073BDC4((vs->key - vs->sound->keyMap->keyBase) + sp29) * 440 * sp24);
			}
		}
	}
}

extern s32 D_global_asm_807FF040[];
extern f32 func_global_asm_80739FE0(s32);
extern void    func_global_asm_8073CDD0(N_ALVoice *v, ALWaveTable *w,f32 pitch, s16 vol,
				ALPan pan, u8 fxmix, u8 arg6, f32 arg7, u8 arg8, ALMicroTime t);

// __n_CSPHandleMIDIMsg
void func_global_asm_80733D8C(N_ALCSPlayer *seqp, N_ALEvent *event)
{
	N_ALVoice          *voice;
	N_ALVoiceState     *vs;
	s32                 status;
	u8                  chan;
	u8                  key;
	u8                  vel;
	u8                  byte1;
	u8                  byte2;
	ALMIDIEvent         *midi = &event->msg.midi;
	s16                 vol;
	N_ALEvent           evt;
	ALMicroTime         deltaTime;
	N_ALVoiceState     *vstate;
	ALPan   		    pan;
	ALChanState        *chanstate;
	s32                 sp90;
	ALVoiceConfig       config;
	ALSound            *sound;
	s16                 cents;
	f32                 pitch,oscValue;
	u8                  fxmix;
	u8                  sp76;
	f32                 sp70;
	void               *oscState;
	ALInstrument       *inst;
	u8                  sp67;
	u8                  sp66;
	s32                 sp60;

	status = midi->status & AL_MIDI_StatusMask;
	chan = midi->status & AL_MIDI_ChannelMask;
	byte1 = key  = midi->byte1;
	byte2 = vel  = midi->byte2;

	switch (status) {
	case (AL_MIDI_NoteOn):

		if (vel != 0) /* a real note on */ {
			// oscState = 0;

			/* If we're not playing, don't process note ons. */
			if (seqp->state != AL_PLAYING || (seqp->chanMask & (1 << chan)) == 0) {
				if (midi->duration) {
					evt.type = AL_CSP_NOTEOFF_EVT;
					evt.msg.midi.status = chan | 0x80;
					evt.msg.midi.byte1 = key;
					evt.msg.midi.byte2 = 0;

					deltaTime = seqp->uspt * midi->duration;
					D_global_asm_807FF040[chan] = deltaTime;

					alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
				}

				break;
			}

			chanstate = &seqp->chanState[chan];

			sound = __n_lookupSoundQuick((N_ALSeqPlayer*)seqp, key, vel, chan);
			ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK,
					ERR_ALSEQP_NO_SOUND);

			config.priority = chanstate->priority;
			config.fxBus = chanstate->unk0b;
			config.unityPitch = 0;

			vstate = __n_mapVoice((N_ALSeqPlayer*)seqp, key, vel, chan);
			ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK,
					ERR_ALSEQP_NO_VOICE );

			voice = &vstate->voice;

			func_global_asm_8073CAC0(voice, &config);

			/*
			 * set up the voice state structure
			 */
			vstate->sound = sound;
			vstate->envPhase = AL_PHASE_ATTACK;

			if (chanstate->sustain > AL_SUSTAIN) {
				vstate->phase = AL_PHASE_SUSTAIN;
			} else {
				vstate->phase = AL_PHASE_NOTEON;
			}

			cents = (key - sound->keyMap->keyBase) * 100 + sound->keyMap->detune;

			if (chanstate->unk24) {
				cents += chanstate->unk27;
			}

			vstate->pitch = func_global_asm_80739FE0(cents);

			if (chanstate->unk24) {
				vstate->envGain = chanstate->attackVolume;
				vstate->envEndTime = seqp->curTime + chanstate->attackTime;
			} else {
				vstate->envGain = sound->envelope->attackVolume;
				vstate->envEndTime = seqp->curTime + sound->envelope->attackTime;
			}

			/*
			 * setup tremelo and vibrato if active
			 */
			vstate->flags = 0;

			if (chanstate->unk24) {
				sp90 = chanstate->tremType;
			} else {
				inst = seqp->chanState[chan].instrument;
				sp90 = inst->tremType;
			}

			oscValue = (f32)_AL_VOL_FULL; /* set this as a default */

			if (sp90) {
				if (seqp->initOsc) {
					if (chanstate->unk24) {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,chanstate->tremType,
								chanstate->tremRate,chanstate->tremDepth,chanstate->tremDelay, chanstate->unk31);
					} else {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,inst->tremType,
								inst->tremRate,inst->tremDepth,inst->tremDelay, chanstate->unk31);
					}

					if (deltaTime) /* a deltaTime of zero means don't run osc */ {
						evt.type = AL_TREM_OSC_EVT;
						evt.msg.osc.vs = vstate;
						evt.msg.osc.oscState = oscState;
						alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
						vstate->flags |= 0x01; /* set tremelo flag bit */
						vstate->oscState = oscState;
					}
				}
			}

			vstate->tremelo = (u8)oscValue;

			/* will default if not changed by initOsc */

			oscValue = 1.0f; /* set this as a default */

			if (chanstate->unk24) {
				sp90 = chanstate->vibType;
			} else {
				sp90 = inst->vibType;
			}

			if (sp90) {
				if (seqp->initOsc) {
					if (chanstate->unk24) {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,chanstate->vibType,
								chanstate->vibRate,chanstate->vibDepth,chanstate->vibDelay, chanstate->unk31);
					} else {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,inst->vibType,
								inst->vibRate,inst->vibDepth,inst->vibDelay, chanstate->unk31);
					}

					if (deltaTime)  /* a deltaTime of zero means don't run osc. */ {
						evt.type = AL_VIB_OSC_EVT;
						evt.msg.osc.vs = vstate;
						evt.msg.osc.oscState = oscState;
						evt.msg.osc.chan = chan;
						alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
						vstate->flags |= 0x02; /* set the vibrato flag bit */
						vstate->oscState2 = oscState;
					}
				}
			}

			vstate->vibrato = oscValue; /* will default if not changed by initOsc */

			/*
			 * calculate the note on parameters
			 */
			pitch = vstate->pitch * chanstate->pitchBend * vstate->vibrato;

			fxmix = func_global_asm_8073A7B8(vstate, seqp);

			sp76 = chanstate->unk11;

			if (sp76) {
				sp70 = 440 * func_global_asm_8073BDC4(cents / 100 + chanstate->unk12 - 64) * chanstate->pitchBend;
			} else {
				sp70 = 127.0f;
			}

			pan = __n_vsPan(vstate, (N_ALSeqPlayer*)seqp);
			vol = __n_vsVol(vstate, (N_ALSeqPlayer*)seqp);

			if (chanstate->unk24) {
				deltaTime = chanstate->attackTime;
			} else {
				deltaTime = sound->envelope->attackTime;
			}

			func_global_asm_8073CDD0(voice, sound->wavetable,
					pitch, vol, pan, fxmix, sp76, sp70, chanstate->unk13, deltaTime);

			/*
			 * set up callbacks for envelope
			 */
			evt.type = AL_SEQP_ENV_EVT;
			evt.msg.vol.voice = voice;

			if (chanstate->unk24) {
				evt.msg.vol.vol = chanstate->decayVolume;
				evt.msg.vol.delta = chanstate->decayTime;
			} else {
				evt.msg.vol.vol = sound->envelope->decayVolume;
				evt.msg.vol.delta = sound->envelope->decayTime;
			}

			alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);

			if (midi->duration) {
				/*
				 * set up note off evt. if no duration don't do this
				 */
				evt.type            = AL_CSP_NOTEOFF_EVT;
				evt.msg.midi.status = chan | AL_MIDI_NoteOff;
				evt.msg.midi.byte1  = key;
				evt.msg.midi.byte2  = 0;   /* not needed ? */
				deltaTime = seqp->uspt * midi->duration;
				D_global_asm_807FF040[chan] = deltaTime;

				/* max time would be about one hour ten minutes */
				alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
			}

			if ((chanstate->unk10 & 1) && seqp->queue) {
				osSendMesg(seqp->queue, (OSMesg)((D_global_asm_807FF040[chan] & 0xffffff00) | (chanstate->unk10 >> 2)), OS_MESG_NOBLOCK);
			}

			break;
		}

		/*
		 * NOTE: intentional fall-through for note on with zero
		 * velocity (Should never happen with compact midi sequence,
		 * but could happen with real time midi.)
		 */

	case (AL_MIDI_NoteOff):
		vstate = __n_lookupVoice((N_ALSeqPlayer*)seqp, key, chan);
		ALFlagFailIf(!vstate, seqp->debugFlags & NOTE_OFF_ERR_MASK,
				ERR_ALSEQP_OFF_VOICE );

		chanstate = &seqp->chanState[chan];

		if (vstate->phase == AL_PHASE_SUSTAIN) {
			vstate->phase = AL_PHASE_SUSTREL;
		} else {
			vstate->phase = AL_PHASE_RELEASE;

			if (chanstate->unk24) {
				__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp, &vstate->voice,
						chanstate->releaseTime);
			} else {
				__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp, &vstate->voice,
						vstate->sound->envelope->releaseTime);
			}
		}

		if ((chanstate->unk10 & 2) && seqp->queue) {
			osSendMesg(seqp->queue, (OSMesg)(key << 16 | 8 | chanstate->unk10 >> 2), OS_MESG_NOBLOCK);
		}

		break;

	case (AL_MIDI_PolyKeyPressure):
		/*
		 * Aftertouch per key (hardwired to volume). Note that
		 * aftertouch affects only notes that are already
		 * sounding.
		 */
		vstate = __n_lookupVoice((N_ALSeqPlayer*)seqp, key, chan);
		ALFailIf(!vstate,  ERR_ALSEQP_POLY_VOICE );

		vstate->velocity = byte2;
		func_global_asm_8073B830( &vstate->voice,
				__n_vsVol(vstate, (N_ALSeqPlayer*)seqp),
				__n_vsDelta(vstate,seqp->curTime));
		break;

	case (AL_MIDI_ChannelPressure):
		/*
		 * Aftertouch per channel (hardwired to volume). Note that
		 * aftertouch affects only notes that are already
		 * sounding.
		 */
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
			if (vs->channel == chan) {
				vs->velocity = byte1;
				func_global_asm_8073B830( &vs->voice,
						__n_vsVol(vs, (N_ALSeqPlayer*)seqp),
						__n_vsDelta(vs,seqp->curTime));
			}
		}
		break;

	case (AL_MIDI_ControlChange):
		switch (byte1) {
		case (AL_MIDI_PAN_CTRL):
			seqp->chanState[chan].pan = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					pan = __n_vsPan(vs, (N_ALSeqPlayer*)seqp);
					func_global_asm_8073CF00( &vs->voice, pan);
				}
			}
			break;
		case (0xfd):
			seqp->chanState[chan].unk0f = byte2;
			break;
		case (0xff):
			if (seqp->chanState[chan].unk0f == 0) {
				seqp->chanState[chan].unk0f = 0x90;
			}

			if (seqp->chanState[chan].unk0e != byte2) {
				if (seqp->chanState[chan].unk0e == seqp->chanState[chan].unk0d) {
					seqp->chanState[chan].unk0e = byte2;
				} else {
					seqp->chanState[chan].unk0e = byte2;
					break;
				}
			} else {
				break;
			}

			midi->byte1 = 0xfe;
			// fall-through
		case (0xfe):
			sp67 = seqp->chanState[chan].unk0d;
			sp66 = seqp->chanState[chan].unk0e;
			vel = seqp->chanState[chan].unk0f;
			sp60 = sp66 - sp67;

			if (sp60 > 0) {
				if (vel & 0x80) {
					vel = (vel & 0x7f) << 1;
				}

				if (sp60 > vel) {
					sp60 = vel;
				}
			} else {
				vel &= 0x7f;

				if (sp60 < -vel) {
					sp60 = -vel;
				}
			}

			sp67 += sp60;
			seqp->chanState[chan].unk0d = sp67;

			if (sp67 != sp66) {
				alEvtqPostEvent(&seqp->evtq, event, seqp->uspt * 100);
			}

			if (sp67) {
				seqp->chanMask |= 1 << chan;
			} else {
				seqp->chanMask &= ~(1 << chan);
			}

			func_global_asm_80733B88(seqp, chan);
			break;
		case (0xfc):
			seqp->chanState[chan].unk0d = byte2;
			seqp->chanState[chan].unk0e = byte2;

			if (byte2 == 0) {
				seqp->chanMask &= (1 << chan) ^ 0xffff;
			} else {
				seqp->chanMask |= 1 << chan;
			}

			func_global_asm_80733B88(seqp, chan);
			break;
		case (0x21):
			seqp->chanState[chan].unk11 = byte2;
			func_global_asm_80733C34(seqp, chan);
			break;
		case (0x22):
			seqp->chanState[chan].unk12 = byte2;
			func_global_asm_80733C34(seqp, chan);
			break;
		case (0x23):
			seqp->chanState[chan].unk13 = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					func_global_asm_8073CFB0(&vs->voice, byte2);
				}
			}
			break;
		case (0x1e):
			if (seqp->queue) {
				osSendMesg(seqp->queue, (OSMesg)((byte2 & 7) | 0x10 | ((seqp->node.samplesLeft << 5) & 0xffffff00)), OS_MESG_NOBLOCK);
			}
			break;
		case (AL_MIDI_VOLUME_CTRL):
			seqp->chanState[chan].vol = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE)) {
					vol = __n_vsVol(vs, (N_ALSeqPlayer*)seqp);
					func_global_asm_8073B830(&vs->voice, vol, __n_vsDelta(vs,seqp->curTime));
				}
			}
			break;
		case (AL_MIDI_PRIORITY_CTRL):
			/* leave current voices where they are */
			seqp->chanState[chan].priority = byte2;
			break;
		case (AL_MIDI_SUSTAIN_CTRL):
			seqp->chanState[chan].sustain = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if ((vs->channel == chan) && (vs->phase != AL_PHASE_RELEASE)) {
					if ( byte2 > AL_SUSTAIN ) {
						/*
						 * sustain pedal down
						 */
						if (vs->phase == AL_PHASE_NOTEON) {
							vs->phase = AL_PHASE_SUSTAIN;
						}
					} else {
						/*
						 * sustain pedal up
						 */
						if (vs->phase == AL_PHASE_SUSTAIN) {
							vs->phase = AL_PHASE_NOTEON;
						} else if (vs->phase == AL_PHASE_SUSTREL) {
							vs->phase = AL_PHASE_RELEASE;

							// @bug: chanstate is uninitialised
							if (chanstate->unk24) {
								__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp,
										&vs->voice,
										(seqp->chanState[chan].releaseTime < AL_USEC_PER_FRAME ? AL_USEC_PER_FRAME : seqp->chanState[chan].releaseTime));
							} else {
								__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp,
										&vs->voice,
										vstate->sound->envelope->releaseTime < AL_USEC_PER_FRAME ? AL_USEC_PER_FRAME : vstate->sound->envelope->releaseTime);
							}
						}
					}
				}
			}
			break;
		case (AL_MIDI_FX1_CTRL):
			seqp->chanState[chan].fxmix = (seqp->chanState[chan].fxmix & 0x80) | byte2;
			byte2 = seqp->chanState[chan].fxmix >> 7;
			// fall-through
		case (0x41):
			seqp->chanState[chan].fxmix = (seqp->chanState[chan].fxmix & 0x7f) | (byte2 << 7);

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					func_global_asm_8073C820(&vs->voice, seqp->chanState[chan].fxmix);
				}
			}
			break;
		case (0x5c):
			if ((byte2 < n_syn->maxAuxBusses) && (byte2 >= 0)) { // This >= 0 isn't necessary due to it being a u8
                seqp->chanState[chan].unk0b = byte2;
			}
			break;
		case (AL_MIDI_FX_CTRL_6):
			// snd_start_mp3_by_filenum(byte2);
			break;
		case (0x20):
			seqp->chanState[chan].unk32 = byte2;
			break;
		// case (AL_MIDI_FX_CTRL_0):
		// 	seqp->chanState[chan].attackTime = var8005f150[byte2];
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (AL_MIDI_FX_CTRL_1):
		// 	seqp->chanState[chan].attackVolume = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (AL_MIDI_FX_CTRL_2):
		// 	seqp->chanState[chan].decayTime = var8005f150[byte2];
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (AL_MIDI_FX_CTRL_3):
		// 	seqp->chanState[chan].decayVolume = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (AL_MIDI_FX_CTRL_4):
		// 	seqp->chanState[chan].releaseTime = var8005f150[byte2];
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x02):
		// 	seqp->chanState[chan].unk27 = byte2 - 64;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x03):
		// 	seqp->chanState[chan].bendRange /= 100;
		// 	seqp->chanState[chan].bendRange *= 100;
		// 	seqp->chanState[chan].bendRange += byte2;
		// 	break;
		// case (0x04):
		// 	seqp->chanState[chan].bendRange %= 100;
		// 	seqp->chanState[chan].bendRange += byte2 * 100;
		// 	break;
		// case (0x0b):
		// 	if (byte2) {
		// 		byte2 += 0x80;
		// 	}

		// 	seqp->chanState[chan].vibType = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x0c):
		// 	seqp->chanState[chan].vibRate = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x0d):
		// 	seqp->chanState[chan].vibDepth = byte2 * 2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x0e):
		// 	seqp->chanState[chan].vibDelay = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x0f):
		// 	seqp->chanState[chan].tremType = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x11):
		// 	seqp->chanState[chan].tremRate = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x12):
		// 	seqp->chanState[chan].tremDepth = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x13):
		// 	seqp->chanState[chan].tremDelay = byte2;
		// 	seqp->chanState[chan].unk24 = 1;
		// 	break;
		// case (0x01):
		// 	byte2 *= 2;

		// 	for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		// 		if (vs->channel == chan && vs->oscState2) {
		// 			struct oscstate *sp5c = vs->oscState2;

		// 			switch (sp5c->unk04 & 0xffffff7f) {
		// 			case 0x02:
		// 				sp5c->unk10 = -_depth2Cents(byte2);
		// 				// fall-through
		// 			case 0x03:
		// 			case 0x04:
		// 			case 0x05:
		// 				sp5c->unk0c = _depth2Cents(byte2);
		// 				break;
		// 			case 0x07:
		// 			case 0x09:
		// 			case 0x0d:
		// 				sp5c->unk0c = _depth2Cents(byte2) / 2.0f;
		// 				break;
		// 			case 0x0a:
		// 				sp5c->unk0c = _depth2Cents(byte2) * 2.0f;
		// 				break;
		// 			default:
		// 				sp5c->unk0c = _depth2Cents(byte2);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 	break;
		// case 0x19:
		// 	seqp->chanState[chan].unk31 = byte2;
		// 	break;
		default:
			break;
		}
		break;
	case (AL_MIDI_ProgramChange):
		/* sct 1/16/96 - We must have a valid bank in order to process the program change. */
		sp90 = (seqp->chanState[chan].unk32 << 7) + key;

		if (sp90 < seqp->bank->instCount) {
			ALInstrument *inst = seqp->bank->instArray[sp90];
			__n_setInstChanState((N_ALSeqPlayer*)seqp, inst, chan);	/* sct 11/6/95 */
		} else {
			// empty
		}
		break;
	case (AL_MIDI_PitchBendChange):
		{
			s32 bendVal;
			f32 bendRatio;
			s32 cents;

			/* get 14-bit unsigned midi value */
			bendVal = ((byte2 << 7) + byte1) - 8192;

			/* calculate pitch bend in cents */
			cents = seqp->chanState[chan].bendRange * bendVal / 8192;

			/* calculate the corresponding ratio  */
			bendRatio = func_global_asm_80739FE0(cents);
			seqp->chanState[chan].pitchBend = bendRatio;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					func_global_asm_8073B900( &vs->voice, vs->pitch * bendRatio * vs->vibrato);

					if (seqp->chanState[chan].unk11) {
						func_global_asm_8073B9B0(&vs->voice, 440 * func_global_asm_8073BDC4(vs->key - vs->sound->keyMap->keyBase) * bendRatio * vs->vibrato);
					}
				}
			}

		}
		break;

	default:
		break;
	}
}

extern void func_global_asm_80735958(ALCSPlayer *, f32);
extern void  func_global_asm_80735864(ALEventQueue *, ALEventListItem *);

void func_global_asm_80735624(ALCSPlayer *seqp, ALEvent *event) {
    // __CSPHandleMetaMsg
    ALTempoEvent    *tevt = &event->msg.tempo;
    // ALEvent         evt;
    s32             tempo;
    s32             oldUspt;
    u32             ticks;
    ALMicroTime         tempDelta,curDelta = 0;
    ALEventListItem     *thisNode,*nextNode,*firstTemp = 0;

    if (event->msg.tempo.status == AL_MIDI_Meta)
    {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO)
        {
	    oldUspt = seqp->uspt;
	    tempo = (tevt->byte1 << 16) | (tevt->byte2 <<  8) | (tevt->byte3 <<  0);
	    func_global_asm_80735958(seqp, (f32)tempo);	/* sct 1/8/96 */

	    thisNode = (ALEventListItem*)seqp->evtq.allocList.next;
	    while(thisNode)
	    {
		curDelta += thisNode->delta;
		nextNode = (ALEventListItem*)thisNode->node.next;
		if(thisNode->evt.type == AL_CSP_NOTEOFF_EVT)
		{
		    alUnlink((ALLink*)thisNode);

		    if(firstTemp)
			alLink((ALLink*)thisNode,(ALLink*)firstTemp);
		    else
		    {
			thisNode->node.next = 0;
			thisNode->node.prev = 0;
			firstTemp = thisNode;
		    }
		    tempDelta = curDelta;         /* record the current delta */
		    if(nextNode) /* don't do this if no nextNode */
		    {
			curDelta -= thisNode->delta;  /* subtract out this delta */
			nextNode->delta += thisNode->delta; /* add it to next event */
		    }
		    thisNode->delta = tempDelta; /* set this event delta from current */
		}
		thisNode = nextNode;
	    }

	    thisNode = firstTemp;
	    while(thisNode)
	    {
		nextNode = (ALEventListItem*)thisNode->node.next;
		ticks = thisNode->delta/oldUspt;
		thisNode->delta = ticks * seqp->uspt;
		func_global_asm_80735864(&seqp->evtq,thisNode);
		thisNode = nextNode;
	    }
        }
    }
}

void  func_global_asm_80735864(ALEventQueue *evtq, ALEventListItem *item) {
    // __CSPRepostEvent
    OSIntMask           mask;
    ALLink              *node;
    ALEventListItem     *nextItem;
    
    mask = osSetIntMask(OS_IM_NONE);

    for (node = &evtq->allocList; node != 0; node = node->next)
    {
        if (!node->next)  /* end of the list */
        {
            alLink((ALLink *)item, node);
            break;
        }
        else
        {
            nextItem = (ALEventListItem *)node->next;
            if (item->delta < nextItem->delta)
            {
                nextItem->delta -= item->delta;
                alLink((ALLink *)item, node);
                break;
            }
            item->delta -= nextItem->delta;
        }
    }
    osSetIntMask(mask);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
} Struct80735958_unk18;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    Struct80735958_unk18* unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} Struct80735958;

void func_global_asm_80735958(ALCSPlayer *seqp, f32 tempo) {
    // __setUsptFromTempo
    if (seqp->target) {
        seqp->uspt = ((f32)tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 0x1E8;
    }
}

extern s32 func_global_asm_8073D060(ALCSeq *, u32 *);

void func_global_asm_807359A0(ALCSPlayer *seqp) {
    // __CSPPostNextSeqEvent
    ALEvent sp20;
    u32 sp1C;

    if (!(seqp->state == AL_PLAYING) || (!seqp->target)) {
        return;
    }

    if (!func_global_asm_8073D060(seqp->target, &sp1C)) {
        return;
    }

    sp20.type = AL_SEQ_REF_EVT;
    alEvtqPostEvent(&seqp->evtq, &sp20, seqp->uspt * sp1C);
}

typedef struct {
    u8 unk0[0x88 - 0x0];
    u8 unk88;
} Struct80735A34;

void func_global_asm_80735A34(Struct80735A34 *arg0, u8 arg1) {
    arg0->unk88 = arg1;
}
