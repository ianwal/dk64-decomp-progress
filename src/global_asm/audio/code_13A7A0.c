#include <ultra64.h>
#include "functions.h"

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
extern Struct807563CC *D_807563CC;

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

typedef struct Struct80737990 Struct80737990;

struct Struct80737990 {
    Struct80737990 *next;
    u8 unk4[0x43 - 0x4];
    u8 unk43;
};

extern Struct80737990 *D_807563C0;

extern u16 *D_807FF0E4;

void func_global_asm_80735DBC(ALEvent *);
void func_global_asm_807370A4(s32, void *, s32);
void func_global_asm_8073749C(void *);
void func_global_asm_8073B6B0(void *);
void func_global_asm_8073B750(void *);

f32 func_global_asm_80739FE0(s8);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_80735AA0.s")

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

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_80735DBC.s")

void func_global_asm_80736FB8(struct_80736FB8 *arg0) {
    if (arg0->unk43 & 4) {
        func_global_asm_8073B6B0(&arg0->unkC);
        func_global_asm_8073B750(&arg0->unkC);
    }
    func_global_asm_8073749C(arg0);
    func_global_asm_807370A4(&D_807563CC->unk14, arg0, 0xFFFF);
}

void func_global_asm_80737028(struct_80737028_0 *arg0) {
    // TODO: Confirm AL Stuff
    ALEvent sp20;
    f32 sp1C;

    sp1C = func_global_asm_80739FE0(arg0->unk8->unk4->unk5) * arg0->unk2C;
    sp20.type = 0x10;
    sp20.msg.vol.voice = (void*)arg0;
    sp20.msg.vol.delta = *(s32*)(&sp1C);
    alEvtqPostEvent(&D_807563CC->unk14, &sp20, 0x8235);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_807370A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_80737198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_8073726C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_8073749C.s")

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

void func_global_asm_80737924(Struct80737990 *arg0) {
    s32 pad2[2];
    Struct80737990 *sp1C;
    s16 pad;
    s16 sp18; // TODO: ALEvent

    sp18 = 0x400;
    sp1C = arg0;
    if (arg0 != NULL) {
        sp1C->unk43 &= ~0x10;
        alEvtqPostEvent(&D_807563CC->unk14, &sp18, 0);
    }
}

void func_global_asm_80737990(u8 arg0) {
    u32 sp2C;
    s32 pad[2];
    Struct80737990 *sp20;
    s16 sp1E;
    s16 sp1C; // TODO: ALEvent
    Struct80737990 *sp18;

    sp2C = osSetIntMask(OS_IM_NONE);
    sp18 = D_807563C0;
    while (sp18 != NULL) {
        sp1C = 0x400;
        sp20 = sp18;
        if ((sp18->unk43 & arg0) == arg0) {
            sp20->unk43 &= ~0x10;
            alEvtqPostEvent(&D_807563CC->unk14, &sp1C, 0);
        }
        sp18 = sp18->next;
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
        alEvtqPostEvent(&D_807563CC->unk14, &sp18, 0);
    }
}

u16 func_global_asm_80737B2C(u8 arg0) {
    return D_807FF0E4[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13A7A0/func_global_asm_80737B58.s")
