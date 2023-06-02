#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80732F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80733180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80733A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80733B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80733C34.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80733D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80735624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80735864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_80735958.s")

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

/*
// TODO: Float regalloc lol
void func_80735958(Struct80735958 *arg0, f32 arg1) {
    if (arg0->unk18 != NULL) {
        arg0->unk24 = arg1 * arg0->unk18->unk8;
    } else {
        arg0->unk24 = 0x1E8;
    }
}
*/

typedef struct {
    u8 unk0[0x18 - 0x0];
    s32 unk18;
    u8 unk1C[0x24 - 0x1C];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unk30[0x48 - 0x30];
    s32 unk48;
} Struct807359A0;

void func_807359A0(Struct807359A0 *arg0) {
    s32 pad[3];
    s16 pad2;
    s16 sp20;
    s32 sp1C;

    if (!(arg0->unk2C == 1) || !arg0->unk18) {
        return;
    }

    if (!func_8073D060(arg0->unk18, &sp1C)) {
        return;
    }

    sp20 = 0;
    alEvtqPostEvent(&arg0->unk48, &sp20, arg0->unk24 * sp1C);
}

typedef struct {
    u8 unk0[0x88 - 0x0];
    u8 unk88;
} Struct80735A34;

void func_80735A34(Struct80735A34 *arg0, u8 arg1) {
    arg0->unk88 = arg1;
}
