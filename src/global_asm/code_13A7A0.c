#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80735AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80735CF4.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80735DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80736FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80737028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_807370A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80737198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_8073726C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_8073749C.s")

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

void func_807375E0(Struct_807375E0 *arg0, u8 arg1) {
    if (arg0 != 0) {
        arg0->unk40 = (s16)arg1;
    }
}

u8 func_80737608(Struct_807375E0 *arg0) {
    if (arg0 != NULL) {
        return arg0->unk44;
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80737638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80737924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80737990.s")

void func_80737A4C(void) {
    func_80737990(1);
}

void func_80737A74(void) {
    func_80737990(0x11);
}

void func_80737A9C(void) {
    func_80737990(3);
}

extern s32 D_807563CC;

void func_80737AC4(s32 arg0, s16 arg1, s32 arg2) {
    ALEvent sp18;

    // TODO: Is this right?
    sp18.type = arg1;
    sp18.msg.loop.start = arg0;
    sp18.msg.loop.end = arg2;
    if (arg0 != 0) {
        alEvtqPostEvent(D_807563CC + 0x14, &sp18, 0);
    }
}

extern u16 *D_807FF0E4;

u16 func_80737B2C(u8 arg0) {
    return D_807FF0E4[arg0];
}


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13A7A0/func_80737B58.s")
