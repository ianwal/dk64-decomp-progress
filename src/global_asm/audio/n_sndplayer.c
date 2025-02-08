#include <ultra64.h>
#include "functions.h"
#include "n_sndp.h"
#include "n_synthInternals.h"

typedef struct {
    u8 unk0[0x14];
    s32 unk14; // ALEventQueue
    u8 unk18[0x28-0x18];
    s16 unk28;
    u8 unk2A[0x48-0x2A];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
} struct_80735CF4; // Probably something in the audio library.

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct807563CC;
extern N_ALSndPlayer *D_global_asm_807563CC;

typedef struct {
    u8 unk0[0xC];
    void* unkC;
    u8 unk10[0x43-0x10];
    u8 unk43;
} struct_80736FB8;

// All of these structs are probably from the audio library
typedef struct {
    u8 unk0[0x5];
    s8 unk5;
} struct_80737028_2;

typedef struct {
    u8 unk0[4];
    struct_80737028_2* unk4;
} struct_80737028_1;

typedef struct {
    u8 unk0[0x8];
    struct_80737028_1* unk8;
    u8 unkC[0x2C-0xC];
    f32 unk2C;
} struct_80737028_0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s8 unk40;
    s8 unk41;
    s8 unk42;
    s8 unk43;
    s8 unk44;
} Struct_807375E0;

extern s16 *D_global_asm_807FF0E4;

// .data
SoundState *D_global_asm_807563C0 = NULL;
SoundState *D_global_asm_807563C4 = NULL;
SoundState *D_global_asm_807563C8 = NULL;

// TODO: Symbol
N_ALSndPlayer *D_global_asm_807563CC = 0x807FF080;

s16 D_global_asm_807563D0 = 0;

void func_global_asm_80735DBC(N_ALSndpEvent *);
void func_global_asm_807370A4(ALEventQueue *, N_ALSoundState *, u16);
void func_global_asm_8073749C(SoundState *);
void func_global_asm_8073B750(void *);

f32 func_global_asm_80739FE0(s32);

s32 func_global_asm_80735CF4(struct_80735CF4 *);

typedef struct Struct80735AA0 {
    s32 unk0;
    s32 unk4;
    s32 maxSounds;
    ALHeap *heap;
    u16 unk10;
} Struct80735AA0;

typedef struct Struct80735AA0_1 {
    u8 pad0[0x48];
} Struct80735AA0_1;

void func_global_asm_80735AA0(Struct80735AA0 *arg0) {
    u32 sp3C;
    ALEventListItem *sp38;
    N_ALEvent sp28;
    Struct80735AA0_1 *sp24;
    ALLink *temp_t1;

    D_global_asm_807563CC->maxSounds = arg0->maxSounds;
    D_global_asm_807563CC->target = NULL;
    D_global_asm_807563CC->frameTime = 16000;
    sp38 = alHeapAlloc(arg0->heap, 1, arg0->unk0 * 0x48);
    D_global_asm_807563CC->sndState = sp38;
    sp38 = alHeapAlloc(arg0->heap, 1, arg0->unk4 * 0x1C);
    alEvtqNew(&D_global_asm_807563CC->evtq, sp38, arg0->unk4);
    D_global_asm_807563C8 = D_global_asm_807563CC->sndState;
    for (sp3C = 1; sp3C < arg0->unk0; sp3C++) {
        sp24 = D_global_asm_807563CC->sndState;
        alLink(sp3C + sp24, sp3C + sp24 - 1);
    }
    D_global_asm_807FF0E4 = alHeapAlloc(arg0->heap, 2, arg0->unk10);
    for (sp3C = 0; sp3C < arg0->unk10; sp3C++) {
        D_global_asm_807FF0E4[sp3C] = 0x7FFF;
    }

    D_global_asm_807563CC->node.next = NULL;
    D_global_asm_807563CC->node.handler = func_global_asm_80735CF4;
    D_global_asm_807563CC->node.clientData = D_global_asm_807563CC;
    func_global_asm_8073B5D0(D_global_asm_807563CC);
    sp28.type = 0x20;
    alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp28, D_global_asm_807563CC->frameTime);
    D_global_asm_807563CC->nextDelta = alEvtqNextEvent(&D_global_asm_807563CC->evtq, &D_global_asm_807563CC->nextEvent);
}

s32 func_global_asm_80735CF4(struct_80735CF4 *arg0) {
    struct_80735CF4 *sp2C;
    ALEvent sp1C;

    sp2C = arg0;
    do {
        if (sp2C->unk28 == 0x20) {
            if (FALSE);
            sp1C.type = 0x20;
            alEvtqPostEvent(&sp2C->unk14, &sp1C, sp2C->unk48);
        } else {
            func_global_asm_80735DBC(&sp2C->unk28);
            if (FALSE);
        }
        sp2C->unk4C = alEvtqNextEvent(&sp2C->unk14, &sp2C->unk28);
    } while (sp2C->unk4C == 0);
    sp2C->unk50 += sp2C->unk4C;
    return sp2C->unk4C;
}

void func_global_asm_80736FB8(struct_80736FB8 *);
void func_global_asm_80737028(struct_80737028_0 *);
u16 func_global_asm_80737198(u16 *, u16 *);
void func_global_asm_8073B830(void *, s32, s32);
void func_global_asm_8073B900(void *, f32);
void func_global_asm_8073C820(void *, s32);
s32 func_global_asm_8073CAC0(void *, s16 *);
void func_global_asm_8073CDD0(void *, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_global_asm_8073CF00(void *, u8);

typedef struct Struct80735DBC_0 {
    ALLink node;
    ALSound *unk8;
    N_ALVoice voice;
    f32 unk28;
    f32 unk2C;
    void *unk30;
    s32 unk34;
    s16 unk38;
    s16 unk3A;
    s32 unk3C;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 unk44;
} Struct80735DBC_0;

// _n_handleEvent
void func_global_asm_80735DBC(N_ALSndpEvent *event)
{
	ALVoiceConfig config;
	ALSound *sound;
	ALKeyMap *keymap;
	ALPan pan;
	N_ALSndpEvent sp94;
	N_ALSndpEvent sp84;
	ALMicroTime delta;
	s32 fxmix;
	s32 vol;
	s32 tmppan;
	s32 sp70;
	s32 isspecial;
	s32 done = TRUE;
	s32 hasvoice = FALSE;
	struct sndstate *state = NULL;
	struct sndstate *nextstate = NULL;
	s16 numfree;
	s16 numalloced;
	struct sndstate *iterstate;
	N_ALSndpEvent sp44;
	ALMicroTime sp40;

	do {
		if (nextstate != NULL) {
			sp84.common.state = (N_ALSoundState *)state;
			sp84.common.type = event->common.type;
			sp84.common.unk08 = event->common.unk08;
			event = &sp84;
		}

		state = (struct sndstate *)event->common.state;

		sound = state->sound;

		if (sound == NULL) {
			func_global_asm_80737198(&numfree, &numalloced);
			return;
		}

		keymap = sound->keyMap;
		nextstate = (struct sndstate *)state->node.next;

		switch (event->common.type) {
		case AL_SNDP_PLAY_EVT:
			if (state->state != AL_STATE5 && state->state != AL_STATE4) {
				return;
			}

			// config.fxBus = state->fxbus;
            config.fxBus = 0;
			config.priority = state->priority;
			config.unityPitch = 0;
			sp70 = D_global_asm_807563D0 >= D_global_asm_807563CC->maxSounds;

			if (!sp70 || (state->flags & SNDSTATEFLAG_10)) {
				hasvoice = func_global_asm_8073CAC0(&state->voice, &config);
			}

			if (!hasvoice) {
				if (state->flags & (SNDSTATEFLAG_02 | SNDSTATEFLAG_10) || state->unk34 > 0) {
					state->state = AL_STATE4;
					state->unk34--;
					alEvtqPostEvent(&D_global_asm_807563CC->evtq, &event->msg, 33333);
				} else if (sp70) {
					iterstate = D_global_asm_807563C4;

					do {
						if ((iterstate->flags & (SNDSTATEFLAG_02 | SNDSTATEFLAG_10)) == 0
								&& (iterstate->flags & SNDSTATEFLAG_04)
								&& iterstate->state != AL_STATE3) {
							sp70 = 0;
							sp44.common.type = AL_SNDP_END_EVT;
							sp44.common.state = (N_ALSoundState *)iterstate;
							iterstate->state = AL_STATE3;

							alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp44.msg, 1000);
							func_global_asm_8073B830(&iterstate->voice, 0, 1000);
						}

						iterstate = (struct sndstate *)iterstate->node.prev;
					} while (sp70 && iterstate);

					if (sp70 == 0) {
						state->unk34 = 2;
						alEvtqPostEvent(&D_global_asm_807563CC->evtq, &event->msg, 1001);
					} else {
						func_global_asm_80736FB8(state);
					}
				} else {
					func_global_asm_80736FB8(state);
				}
				return;
			}

			// This is the same as above, but delta is calculated later
			state->flags |= SNDSTATEFLAG_04;
			state->envvol = sound->envelope->attackVolume;
			// state->fxbus = config.fxBus;
			delta = sound->envelope->attackTime / state->pitch / state->basepitch;
			state->endtime = D_global_asm_807563CC->curTime + delta;

			vol = MAX(0, (D_global_asm_807FF0E4[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01)) / 0x7fff - 1);
			tmppan = state->pan + sound->samplePan - AL_PAN_CENTER;
			pan = MIN(MAX(tmppan, 0), 127);

			fxmix = (state->fxmix & 0x7f) + (keymap->keyMax & 0xf) * 8;
			fxmix = MIN(127, MAX(0, fxmix));
			fxmix |= state->fxmix & 0x80;

			func_global_asm_8073CDD0(&state->voice, sound->wavetable, state->pitch * state->basepitch, vol, pan, fxmix, 0, 0, 0, delta);
			state->state = AL_PLAYING;
			D_global_asm_807563D0++;

			if ((state->flags & SNDSTATEFLAG_02) == 0) {
				if (delta == 0) {
					state->envvol =  sound->envelope->decayVolume;

					vol = MAX(0, (D_global_asm_807FF0E4[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01)) / 0x7fff - 1);

					delta = sound->envelope->decayTime / state->basepitch / state->pitch;

					state->endtime = D_global_asm_807563CC->curTime + delta;

					func_global_asm_8073B830(&state->voice, vol, delta);

					sp94.common.type = AL_SNDP_STOP_EVT;
					sp94.common.state = (N_ALSoundState *)state;

					alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp94.msg, delta);

					if (state->flags & SNDSTATEFLAG_20) {
						func_global_asm_80737028(state);
					}
				} else {
					sp94.common.type = AL_SNDP_DECAY_EVT;
					sp94.common.state = (N_ALSoundState *)state;
					delta = sound->envelope->attackTime / state->pitch / state->basepitch;

					alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp94.msg, delta);
				}
			}
			break;
		case AL_SNDP_STOP_EVT:
		case AL_SNDP_0400_EVT:
		case AL_SNDP_1000_EVT:
			if (event->common.type != AL_SNDP_1000_EVT || (state->flags & SNDSTATEFLAG_02)) {
				switch (state->state) {
				case AL_PLAYING:
					func_global_asm_807370A4(&D_global_asm_807563CC->evtq, (N_ALSoundState *)state, AL_SNDP_DECAY_EVT);
					delta = sound->envelope->releaseTime / state->basepitch / state->pitch;

					func_global_asm_8073B830(&state->voice, 0, delta);

					if (delta) {
						sp94.common.type = AL_SNDP_END_EVT;
						sp94.common.state = (N_ALSoundState *)state;
						alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp94.msg, delta);
						state->state = AL_STOPPING;
					} else {
						func_global_asm_80736FB8(state);
					}
					break;
				case AL_STATE4:
				case AL_STATE5:
					func_global_asm_80736FB8(state);
					break;
				default:
					break;
				}

				if (event->common.type == AL_SNDP_STOP_EVT) {
					event->common.type = AL_SNDP_1000_EVT;
				}
			}
			break;
		case AL_SNDP_PAN_EVT:
			state->pan = event->common.unk08;

			if (state->state == AL_PLAYING) {
				tmppan = state->pan - AL_PAN_CENTER + sound->samplePan;
				pan = MIN(MAX(tmppan, AL_PAN_LEFT), AL_PAN_RIGHT);

				func_global_asm_8073CF00(&state->voice, pan);
			}
			break;
		case AL_SNDP_PITCH_EVT:
			state->pitch = event->pitch.pitch;

			if (state->state == AL_PLAYING) {
				func_global_asm_8073B900(&state->voice, state->pitch * state->basepitch);

				if (state->flags & SNDSTATEFLAG_20) {
					func_global_asm_80737028(state);
				}
			}
			break;
		case AL_SNDP_FX_EVT:
			state->fxmix = event->common.unk08;

			if (state->state == AL_PLAYING) {
				fxmix = (state->fxmix & 0x7f) + (keymap->keyMax & 0xf) * 8;
				fxmix = MIN(127, MAX(0, fxmix));
				fxmix |= state->fxmix & 0x80;

				func_global_asm_8073C820(&state->voice, fxmix);
			}
			break;
		// case AL_SNDP_4000_EVT:
		// 	state->fxmix = (u8)(state->fxmix & 0x7f) | (u8)(event->common.unk08 & 0x80);

		// 	if (state->state == AL_PLAYING) {
		// 		fxmix = (state->fxmix & 0x7f) + (keymap->keyMax & 0xf) * 8;
		// 		fxmix = MIN(127, MAX(0, fxmix));
		// 		fxmix |= state->fxmix & 0x80;

		// 		func_global_asm_8073C820(&state->voice, fxmix);
		// 	}
		// 	break;
		case AL_SNDP_VOL_EVT:
			state->vol = event->common.unk08;

			if (state->state == AL_PLAYING) {
				vol = MAX(0, (D_global_asm_807FF0E4[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01)) / 0x7fff - 1);

				func_global_asm_8073B830(&state->voice, vol, MAX(1000, state->endtime - D_global_asm_807563CC->curTime));
			}
			break;
		case AL_SNDP_0800_EVT:
			if (state->state == AL_PLAYING) {
				delta = sound->envelope->releaseTime / state->basepitch / state->pitch;

				vol = MAX(0, D_global_asm_807FF0E4[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01) / 0x7fff - 1);

				func_global_asm_8073B830(&state->voice, vol, delta);
			}
			break;
		// case AL_SNDP_FXBUS_EVT:
		// 	state->fxbus = event->common.unk08;

		// 	if (state->fxbus >= n_syn->maxAuxBusses) {
		// 		state->fxbus = 0;
		// 	}

		// 	if (state->state == AL_PLAYING) {
		// 		state->voice.fxBus = state->fxbus;
		// 	}
		// 	break;
		case AL_SNDP_DECAY_EVT:
			if ((state->flags & SNDSTATEFLAG_02) == 0) {
				state->envvol = sound->envelope->decayVolume;
				vol = MAX(0, D_global_asm_807FF0E4[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01) / 0x7fff - 1);
				delta = sound->envelope->decayTime / state->basepitch / state->pitch;

				state->endtime = D_global_asm_807563CC->curTime + delta;

				func_global_asm_8073B830(&state->voice, vol, delta);

				sp94.common.type = AL_SNDP_STOP_EVT;
				sp94.common.state = (N_ALSoundState *)state;

				alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp94.msg, delta);

				if (state->flags & SNDSTATEFLAG_20) {
					func_global_asm_80737028(state);
				}
			}
			break;
		case AL_SNDP_END_EVT:
			func_global_asm_80736FB8(state);
			break;
		case AL_SNDP_0200_EVT:
			if (state->flags & SNDSTATEFLAG_10) {
				sp40 = func_global_asm_80737638(event->msg.msg.generic.data2, event->msg.msg.generic.data, state->vol, state->pan,
						state->pitch, state->fxmix, state->unk30);
			}
			break;
		default:
			break;
		}

		isspecial = event->common.type & (AL_SNDP_PLAY_EVT
				| AL_SNDP_PITCH_EVT
				| AL_SNDP_DECAY_EVT
				| AL_SNDP_END_EVT
				| AL_SNDP_0200_EVT);

		if ((state = nextstate) && !isspecial) {
			done = state->flags & SNDSTATEFLAG_01;
		}
	} while (!done && state && !isspecial);
}

void func_global_asm_80736FB8(struct_80736FB8 *arg0) {
    if (arg0->unk43 & 4) {
        n_alSynStopVoice(&arg0->unkC);
        func_global_asm_8073B750(&arg0->unkC);
    }
    func_global_asm_8073749C(arg0);
    func_global_asm_807370A4(&D_global_asm_807563CC->evtq, arg0, 0xFFFF);
}

void func_global_asm_80737028(struct_80737028_0 *arg0) {
    // TODO: Confirm AL Stuff
    ALEvent sp20;
    f32 sp1C;

    sp1C = func_global_asm_80739FE0(arg0->unk8->unk4->unk5) * arg0->unk2C;
    sp20.type = 0x10;
    sp20.msg.vol.voice = (void*)arg0;
    sp20.msg.vol.delta = *(s32*)(&sp1C);
    alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp20, 0x8235);
}

// _removeEvents
void func_global_asm_807370A4(ALEventQueue *evtq, N_ALSoundState *state, u16 arg2) {
    // _func_global_asm_807370A4
    ALLink *thisNode;
    ALLink *nextNode;
    ALEventListItem *thisItem;
    ALEventListItem *nextItem;
    N_ALSndpEvent *sp1C;
    OSIntMask mask;

    mask = osSetIntMask(1U);
    thisNode = evtq->allocList.next;
    while (thisNode) {
        nextNode = thisNode->next;
        thisItem = thisNode;
        nextItem = nextNode;
        sp1C = (N_ALSndpEvent *)&thisItem->evt;
        if ((sp1C->common.state == state) && (*(u16*)(&sp1C->common.type) & arg2)) {
            if (nextItem != NULL) {
                nextItem->delta += thisItem->delta;
            }
            alUnlink(thisNode);
            alLink(thisNode, evtq);
        }
        thisNode = nextNode;
    }
    osSetIntMask(mask);
}

// sndpCountStates
u16 func_global_asm_80737198(u16 *arg0, u16 *arg1) {
    u16 sp16;
    u16 sp14;
    u16 sp12;
    SoundState *spC;
    SoundState *sp8;
    SoundState *sp4;

    spC = D_global_asm_807563C0;
    sp8 = D_global_asm_807563C8;
    sp4 = D_global_asm_807563C4;
    for (sp16 = 0; spC; sp16++, spC = spC->node.next) {}
    for (sp14 = 0; sp8; sp14++, sp8 = sp8->node.next) {}
    for (sp12 = 0; sp4; sp12++, sp4 = sp4->node.prev) {}
    *arg0 = sp14;
    *arg1 = sp16;
    return sp12;
}

SoundState *func_global_asm_8073726C(ALBank *bank, ALSound *sound) {
    SoundState *ss;
    ALKeyMap *km;
    s32 sp1C;
    u32 mask;

    km = sound->keyMap;
    mask = osSetIntMask(OS_IM_NONE);
    ss = D_global_asm_807563C8;
    if (ss != NULL) {
        D_global_asm_807563C8 = ss->node.next;
        alUnlink(ss);
        if (D_global_asm_807563C0 != NULL) {
            ss->node.next = D_global_asm_807563C0;
            ss->node.prev = NULL;
            D_global_asm_807563C0->node.prev = ss;
            D_global_asm_807563C0 = ss;
        } else {
            ss->node.prev = NULL;
            ss->node.next = ss->node.prev;
            D_global_asm_807563C0 = ss;
            D_global_asm_807563C4 = ss;
        }
        osSetIntMask(mask);
        sp1C = (sound->envelope->decayTime + 1) == 0;
        ss->sound = sound;
        ss->priority = sp1C + 0x40;
        ss->playState = 5;
        ss->pitch = 1.0f;
        ss->unk34 = 2;
        ss->status = km->keyMax & 0xF0;
        ss->unk30 = 0;
        if (ss->status & 0x20) {
            ss->unk28 = func_global_asm_80739FE0((km->keyBase * 100) - 6000);
        } else {
            ss->unk28 = func_global_asm_80739FE0(((km->keyBase * 100) + km->detune) - 6000);
        }
        if (sp1C != 0) {
            ss->status |= 2;
        }
        ss->unk42 = 0;
        ss->pan = 0x40;
        ss->volume = 0x7FFF;
    } else {
        osSetIntMask(mask);
    }
    return ss;
}

// sndpFreeState
void func_global_asm_8073749C(SoundState *arg0) {
    if (D_global_asm_807563C0 == arg0) {
        D_global_asm_807563C0 = arg0->node.next;
    }
    if (D_global_asm_807563C4 == arg0) {
        D_global_asm_807563C4 = arg0->node.prev;
    }
    alUnlink(arg0);
    if (D_global_asm_807563C8 != NULL) {
        arg0->node.next = D_global_asm_807563C8;
        arg0->node.prev = NULL;
        D_global_asm_807563C8->node.prev = arg0;
        D_global_asm_807563C8 = arg0;
    } else {
        arg0->node.prev = NULL;
        arg0->node.next = arg0->node.prev;
        D_global_asm_807563C8 = arg0;
    }
    if (arg0->status & 4) {
        D_global_asm_807563D0--;
    }
    arg0->playState = 0;
    if (arg0->unk30 != NULL) {
        if (*arg0->unk30 == arg0) {
            *arg0->unk30 = 0;
        }
        arg0->unk30 = NULL;
    }
}

// sndSetPriority
void func_global_asm_807375E0(Struct_807375E0 *arg0, u8 arg1) {
    if (arg0 != 0) {
        arg0->unk40 = (s16)arg1;
    }
}

// sndGetState
u8 func_global_asm_80737608(Struct_807375E0 *arg0) {
    if (arg0 != NULL) {
        return arg0->unk44;
    } else {
        return 0;
    }
}

struct sndstate *func_global_asm_80737638(ALBank *arg0, s16 soundnum, u16 vol, ALPan pan, f32 pitch, u8 fxmix, struct sndstate **handleptr)
{
	struct sndstate *state;
	struct sndstate *state2 = NULL;
	ALKeyMap *keymap;
	ALSound *sound;
	s16 sp4e = 0;
	s32 sp48;
	s32 sp44;
	s32 sp40 = 0;
	s32 abspan;
	N_ALEvent evt;
	N_ALEvent evt2;

	if (soundnum != 0) {
		do {
			sound = arg0->instArray[0]->soundArray[soundnum - 1];
			state = func_global_asm_8073726C(arg0, sound);

			if (state != NULL) {
				D_global_asm_807563CC->target = state;
				evt.type = AL_SNDP_PLAY_EVT;
				evt.msg.generic.sndstate = state;
				abspan = pan + state->pan - AL_PAN_CENTER;

				if (abspan > 127) {
					abspan = 127;
				} else if (abspan < 0) {
					abspan = 0;
				}

				state->pan = abspan;
				state->vol = (u32)(vol * state->vol) >> 15;
				state->pitch *= pitch;
				state->fxmix = fxmix;

				sp44 = sound->keyMap->velocityMax * 33333;

				if (state->flags & SNDSTATEFLAG_10) {
					state->flags &= ~SNDSTATEFLAG_10;
					alEvtqPostEvent(&D_global_asm_807563CC->evtq, &evt, sp40 + 1);
					sp48 = sp44 + 1;
					sp4e = soundnum;
				} else {
					alEvtqPostEvent(&D_global_asm_807563CC->evtq, &evt, sp44 + 1);
				}

				state2 = state;
			}

			sp40 += sp44;
			keymap = sound->keyMap;
			soundnum = keymap->velocityMin + (keymap->keyMin & 0xc0) * 4;
            soundnum += (keymap->keyMin & 0x20) << 5;
        } while (soundnum && state);

		if (state2 != NULL) {
			state2->flags |= SNDSTATEFLAG_01;
			state2->unk30 = handleptr;

			if (sp4e != 0) {
				state2->flags |= SNDSTATEFLAG_10;

				evt2.type = AL_SNDP_0200_EVT;
				evt2.msg.generic.sndstate = state2;
				evt2.msg.generic.data = sp4e;
				evt2.msg.generic.data2 = arg0;

				alEvtqPostEvent(&D_global_asm_807563CC->evtq, &evt2, sp48);
			}
		}
	}

	if (handleptr != NULL) {
		*handleptr = state2;
	}

	return state2;
}

void func_global_asm_80737924(SoundState *arg0) {
    s32 pad2[2];
    SoundState *sp1C;
    s16 pad;
    s16 sp18; // TODO: ALEvent

    sp18 = 0x400;
    sp1C = arg0;
    if (arg0 != NULL) {
        sp1C->status &= ~0x10;
        alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp18, 0);
    }
}

void func_global_asm_80737990(u8 arg0) {
    u32 sp2C;
    s32 pad[2];
    SoundState *sp20;
    s16 sp1E;
    s16 sp1C; // TODO: ALEvent
    SoundState *sp18;

    sp2C = osSetIntMask(OS_IM_NONE);
    sp18 = D_global_asm_807563C0;
    while (sp18 != NULL) {
        sp1C = 0x400;
        sp20 = sp18;
        if ((sp18->status & arg0) == arg0) {
            sp20->status &= ~0x10;
            alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp1C, 0);
        }
        sp18 = sp18->node.next;
    }
    osSetIntMask(sp2C);
}

void func_global_asm_80737A4C(void) {
    func_global_asm_80737990(1);
}

void func_global_asm_80737A74(void) {
    func_global_asm_80737990(0x11);
}

void func_global_asm_80737A9C(void) {
    func_global_asm_80737990(3);
}

void func_global_asm_80737AC4(s32 arg0, s16 arg1, s32 arg2) {
    ALEvent sp18;

    // TODO: Is this right?
    sp18.type = arg1;
    sp18.msg.loop.start = arg0;
    sp18.msg.loop.end = arg2;
    if (arg0 != 0) {
        alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp18, 0);
    }
}

u16 func_global_asm_80737B2C(u8 arg0) {
    return D_global_asm_807FF0E4[arg0];
}

void func_global_asm_80737B58(u8 arg0, u16 arg1) {
    SoundState *sp2C;
    s32 sp28;
    ALEvent sp18;

    sp2C = D_global_asm_807563C0;
    D_global_asm_807FF0E4[arg0] = arg1;
    for (sp28 = 0; sp2C; sp28++, sp2C = sp2C->node.next) {
        if ((sp2C->sound->keyMap->keyMin & 0x1F) == arg0) {
            sp18.type = 0x800;
            sp18.msg.vol.voice = sp2C;
            alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp18, 0);
        }
    }
}
