#include <ultra64.h>
#include "functions.h"
#include "sndp.h"

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

extern SoundState *D_global_asm_807563C0;

extern u16 *D_global_asm_807FF0E4;

void func_global_asm_80735DBC(N_ALEvent *);
void func_global_asm_807370A4(ALEventQueue *, ALSoundState *, u16);
void func_global_asm_8073749C(SoundState *);
void func_global_asm_8073B750(void *);

f32 func_global_asm_80739FE0(s32);

s32 func_global_asm_80735CF4(struct_80735CF4 *);
extern SoundState *D_global_asm_807563C8;

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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_80735DBC.s")

void func_global_asm_80736FB8(struct_80736FB8 *);
void func_global_asm_80737028(struct_80737028_0 *);
u16 func_global_asm_80737198(u16 *, u16 *);
void func_global_asm_8073B830(void *, s32, s32);
void func_global_asm_8073B900(void *, f32);
void func_global_asm_8073C820(void *, s32);
s32 func_global_asm_8073CAC0(void *, s16 *);
void func_global_asm_8073CDD0(void *, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_global_asm_8073CF00(void *, u8);
extern SoundState *D_global_asm_807563C4;
extern s16 D_global_asm_807563D0;

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

/*
void func_global_asm_80735DBC(N_ALEvent *arg0) {
    ALVoiceConfig spB0;
    ALSound *spAC;
    void *spA8;
    u8 spA7;
    void *sp98;
    s16 sp94;
    enum sfx_e sp8C;
    void *sp88;
    N_ALEvent sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    Struct80735DBC_0 *sp60;
    Struct80735DBC_0 *sp5C;
    u16 sp5A;
    u16 sp58;
    Struct80735DBC_0 *sp54;
    void *sp48;
    N_ALEvent sp44;
    s32 sp40;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    u16 temp_s0;
    u8 temp_s0_2;
    u8 temp_t6;
    u8 temp_t8;

    sp68 = 1;
    sp64 = 0;
    sp60 = NULL;
    sp5C = NULL;
    do {
        if (sp5C != NULL) {
            sp84.msg.generic.data[0].i = sp60;
            sp84.type = arg0->type;
            sp84.msg.generic.data[1].i = arg0->msg.vol.delta;
            arg0 = &sp84;
        }
        sp60 = arg0->msg.generic.data[0].i;
        spAC = sp60->unk8;
        if (spAC == NULL) {
            func_global_asm_80737198(&sp5A, &sp58);
            return;
        }
        spA8 = spAC->keyMap;
        sp5C = sp60->node.next;
        switch (arg0->type) {
        case 0x1:
            if ((sp60->unk44 != 5) && (sp60->unk44 != 4)) {
                return;
            }
            spB0.fxBus = 0;
            spB0.priority = sp60->unk40;
            spB0.unityPitch = 0;
            sp70 = (D_global_asm_807563D0 < D_global_asm_807563CC->maxSounds) ^ 1;
            if ((!sp70) || (sp60->unk43 & 0x10)) {
                sp64 = func_global_asm_8073CAC0(sp60 + 0xC, &spB0);
            }
            if (sp64 == 0) {
                if ((sp60->unk43 & 0x12) || (sp60->unk34 > 0)) {
                    sp60->unk44 = 4U;
                    sp60->unk34 = (s32) (sp60->unk34 - 1);
                    alEvtqPostEvent(D_global_asm_807563CC + 0x14, arg0, 0x8235);
                } else if (sp70 != 0) {
                    sp54 = D_global_asm_807563C4;
                    do {
                        temp_t8 = sp54->unk43;
                        if (!(temp_t8 & 0x12) && (temp_t8 & 4) && (sp54->unk44 != 3)) {
                            sp44.type = 0x80;
                            sp44.msg.generic.data[0].i = sp54;
                            sp54->unk44 = 3U;
                            sp70 = 0;
                            alEvtqPostEvent(&D_global_asm_807563CC->evtq, &sp44, 0x3E8);
                            func_global_asm_8073B830(&sp54->voice, 0, 0x3E8);
                        }
                        sp54 = sp54->node.prev;
                    } while ((sp70 != 0) && (sp54 != NULL));
                    if (sp70 == 0) {
                        sp60->unk34 = 2;
                        alEvtqPostEvent(D_global_asm_807563CC + 0x14, arg0, 0x3E9);
                    } else {
                        func_global_asm_80736FB8(sp60);
                    }
                } else {
                    func_global_asm_80736FB8(sp60);
                }
                return;
            }
            sp60->unk43 |= 4;
            sp60->unk3A = (s16) spAC->envelope->attackVolume;
            sp80 = (s32) ((spAC->envelope->attackTime / sp60->unk2C) / sp60->unk28);
            sp60->unk3C = (s32) (D_global_asm_807563CC->unk50 + sp80);
            if ((((s32) D_global_asm_807FF0E4[spA8->unk2 & 0x1F] * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) <= 0) {
                sp78 = 0;
            } else {
                sp78 = ((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) - 1;
            }
            sp74 = (sp60->unk41 + spAC->unkC) - 0x40;
            if (sp74 > 0) {
                var_s0 = sp74;
            } else {
                var_s0 = 0;
            }
            if (var_s0 < 0x7F) {
                if (sp74 > 0) {
                    var_s1 = sp74;
                } else {
                    var_s1 = 0;
                }
                spA7 = (u8) var_s1;
            } else {
                spA7 = 0x7F;
            }
            sp7C = (sp60->unk42 & 0x7F) + ((spA8->unk3 & 0xF) * 8);
            if (sp7C < 0) {
                var_s0_2 = 0;
            } else {
                var_s0_2 = sp7C;
            }
            if (var_s0_2 >= 0x80) {
                sp7C = 0x7F;
            } else {
                if (sp7C < 0) {
                    var_s1_2 = 0;
                } else {
                    var_s1_2 = sp7C;
                }
                sp7C = var_s1_2;
            }
            sp7C |= sp60->unk42 & 0x80;
            func_global_asm_8073CDD0(sp60 + 0xC, spAC->unk8, sp60->unk2C * sp60->unk28, sp78, (s32) spA7, sp7C, 0, 0.0f, 0, sp80);
            sp60->unk44 = 1U;
            D_global_asm_807563D0 += 1;
            if (!(sp60->unk43 & 2)) {
                if (sp80 == 0) {
                    sp60->unk3A = (s16) spAC->unk0->unkD;
                    if (((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) <= 0) {
                        sp78 = 0;
                    } else {
                        sp78 = ((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) - 1;
                    }
                    sp80 = (s32) (((f32) spAC->unk0->unk4 / sp60->unk28) / sp60->unk2C);
                    sp60->unk3C = (s32) (D_global_asm_807563CC->unk50 + sp80);
                    func_global_asm_8073B830(sp60 + 0xC, sp78, sp80);
                    sp94 = 2;
                    sp98 = sp60;
                    alEvtqPostEvent(D_global_asm_807563CC + 0x14, (ALEvent *) &sp94, sp80);
                    if (sp60->unk43 & 0x20) {
                        func_global_asm_80737028(sp60);
                    }
                } else {
                    sp94 = 0x40;
                    sp98 = sp60;
                    sp80 = (s32) (((f32) *spAC->unk0 / sp60->unk2C) / sp60->unk28);
                    alEvtqPostEvent(D_global_asm_807563CC + 0x14, (ALEvent *) &sp94, sp80);
                }
            }
        case 0x2:
        case 0x400:
        case 0x1000:
            if ((arg0->unk0 != 0x1000) || (sp60->unk43 & 2)) {
                temp_s0_2 = sp60->unk44;
                switch (temp_s0_2) {
                case 1:
                    func_global_asm_807370A4(D_global_asm_807563CC + 0x14, sp60, 0x40);
                    sp80 = (s32) (((f32) spAC->unk0->unk8 / sp60->unk28) / sp60->unk2C);
                    func_global_asm_8073B830(sp60 + 0xC, 0, sp80);
                    if (sp80 != 0) {
                        sp94 = 0x80;
                        sp98 = sp60;
                        alEvtqPostEvent(D_global_asm_807563CC + 0x14, (ALEvent *) &sp94, sp80);
                        sp60->unk44 = 2U;
                    } else {
                        func_global_asm_80736FB8(sp60);
                    }
                    break;
                case 4:
                case 5:
                    func_global_asm_80736FB8(sp60);
                    break;
                }
                if (arg0->unk0 == 2) {
                    arg0->unk0 = 0x1000;
                }
            }
            break;
        case 0x4:
            sp60->unk41 = (u8) arg0->unk8;
            if (sp60->unk44 == 1) {
                sp74 = (sp60->unk41 + spAC->unkC) - 0x40;
                if (sp74 > 0) {
                    var_s0_3 = sp74;
                } else {
                    var_s0_3 = 0;
                }
                if (var_s0_3 < 0x7F) {
                    if (sp74 > 0) {
                        var_s1_3 = sp74;
                    } else {
                        var_s1_3 = 0;
                    }
                    spA7 = (u8) var_s1_3;
                } else {
                    spA7 = 0x7F;
                }
                func_global_asm_8073CF00(sp60 + 0xC, spA7);
            }
            break;
        case 0x10:
            sp60->unk2C = (bitwise f32) arg0->unk8;
            if (sp60->unk44 == 1) {
                func_global_asm_8073B900(sp60 + 0xC, sp60->unk2C * sp60->unk28);
                if (sp60->unk43 & 0x20) {
                    func_global_asm_80737028(sp60);
                }
            }
            break;
        case 0x100:
            sp60->unk42 = (u8) arg0->unk8;
            if (sp60->unk44 == 1) {
                sp7C = (sp60->unk42 & 0x7F) + ((spA8->unk3 & 0xF) * 8);
                if (sp7C < 0) {
                    var_s0_4 = 0;
                } else {
                    var_s0_4 = sp7C;
                }
                if (var_s0_4 >= 0x80) {
                    sp7C = 0x7F;
                } else {
                    if (sp7C < 0) {
                        var_s1_4 = 0;
                    } else {
                        var_s1_4 = sp7C;
                    }
                    sp7C = var_s1_4;
                }
                sp7C |= sp60->unk42 & 0x80;
                func_global_asm_8073C820(sp60 + 0xC, sp7C);
            }
            break;
        case 0x8:
            sp60->unk38 = (s16) arg0->unk8;
            if (sp60->unk44 == 1) {
                if (((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) <= 0) {
                    sp78 = 0;
                } else {
                    sp78 = ((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) - 1;
                }
                if ((sp60->unk3C - D_global_asm_807563CC->unk50) < 0x3E8) {
                    var_s0_5 = 0x3E8;
                } else {
                    var_s0_5 = sp60->unk3C - D_global_asm_807563CC->unk50;
                }
                func_global_asm_8073B830(sp60 + 0xC, sp78, var_s0_5);
            }
            break;
        case 0x800:
            if (sp60->unk44 == 1) {
                sp80 = (s32) (((f32) spAC->unk0->unk8 / sp60->unk28) / sp60->unk2C);
                if (((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) <= 0) {
                    sp78 = 0;
                } else {
                    sp78 = ((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) - 1;
                }
                func_global_asm_8073B830(sp60 + 0xC, sp78, sp80);
            }
            break;
        case 0x40:
            if (!(sp60->unk43 & 2)) {
                sp60->unk3A = (s16) spAC->unk0->unkD;
                if (((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) <= 0) {
                    sp78 = 0;
                } else {
                    sp78 = ((s32) (*(D_global_asm_807FF0E4 + ((spA8->unk2 & 0x1F) * 2)) * ((s32) (sp60->unk3A * sp60->unk38 * spAC->unkD) / 16129)) / 32767) - 1;
                }
                sp80 = (s32) (((f32) spAC->unk0->unk4 / sp60->unk28) / sp60->unk2C);
                sp60->unk3C = (s32) (D_global_asm_807563CC->unk50 + sp80);
                func_global_asm_8073B830(sp60 + 0xC, sp78, sp80);
                sp94 = 2;
                sp98 = sp60;
                alEvtqPostEvent(D_global_asm_807563CC + 0x14, (ALEvent *) &sp94, sp80);
                if (sp60->unk43 & 0x20) {
                    func_global_asm_80737028(sp60);
                }
            }
            break;
        case 0x80:
            func_global_asm_80736FB8(sp60);
            break;
        case 0x200:
            if (sp60->unk43 & 0x10) {
                sp40 = func_global_asm_80737638(arg0->unkC, arg0->unk8, (u32) sp60->unk38, (u32) sp60->unk41, sp60->unk2C, (u32) sp60->unk42, sp60->unk30);
            }
            break;
        default:
            break;
        }
        sp6C = (u16)arg0->type & 0x2D1;
        sp60 = sp5C;
        if ((sp5C != NULL) && (sp6C == 0)) {
            sp68 = sp60->unk43 & 1;
        }
    } while ((sp68 == 0) && (sp60 != NULL) && !sp6C);
}
*/

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

void func_global_asm_807370A4(ALEventQueue *evtq, ALSoundState *state, u16 arg2) {
    // __removeEVents
    ALLink *thisNode;
    ALLink *nextNode;
    ALEventListItem *thisItem;
    ALEventListItem *nextItem;
    ALSndpEvent *sp1C;
    OSIntMask mask;

    mask = osSetIntMask(1U);
    thisNode = evtq->allocList.next;
    while (thisNode) {
        nextNode = thisNode->next;
        thisItem = thisNode;
        nextItem = nextNode;
        sp1C = (ALSndpEvent *)&thisItem->evt;
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

extern SoundState *D_global_asm_807563C0;

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

extern s16 D_global_asm_807563D0;

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

void func_global_asm_807375E0(Struct_807375E0 *arg0, u8 arg1) {
    if (arg0 != 0) {
        arg0->unk40 = (s16)arg1;
    }
}

u8 func_global_asm_80737608(Struct_807375E0 *arg0) {
    if (arg0 != NULL) {
        return arg0->unk44;
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_80737638.s")

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