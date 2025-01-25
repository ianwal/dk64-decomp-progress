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

void func_global_asm_80735DBC(ALEvent *);
void func_global_asm_807370A4(ALEventQueue *, ALSoundState *, u16);
void func_global_asm_8073749C(SoundState *);
void func_global_asm_8073B750(void *);

f32 func_global_asm_80739FE0(s8);

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
extern SoundState *D_global_asm_807563C4;

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_8073726C.s")

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