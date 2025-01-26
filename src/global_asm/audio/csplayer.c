#include <ultra64.h>
#include "functions.h"
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
extern void func_global_asm_80733D8C(ALCSPlayer *, ALEvent *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733C34.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733D8C.s")

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