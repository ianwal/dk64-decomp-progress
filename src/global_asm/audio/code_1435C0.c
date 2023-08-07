#include <ultra64.h>
#include "functions.h"

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1435C0/func_global_asm_8073E8C0.s")

typedef struct {
    u8 unk0[0x48 - 0x0];
    s32 unk48;
    f32 unk4C;
    s32 unk50;
    s32 unk54;
    s16 unk58;
    s16 unk5A;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 *unk80;
    s32 unk84;
} Struct8073F1E4;

s32 func_global_asm_8073F1E4(Struct8073F1E4 *arg0, s32 arg1, s32 *arg2) {
    Struct8073F1E4 *sp24;

    sp24 = arg0;
    switch (arg1) {
        case 3:
            if (sp24->unk80 != NULL) {
                sp24->unk80[0] = arg2;
            } else {
                sp24->unk7C = arg2;
            }
            sp24->unk80 = arg2;
            break;
        case 4:
            sp24->unk78 = 1;
            sp24->unk84 = 0;
            sp24->unk5A = 1;
            sp24->unk74 = 0;
            sp24->unk4C = 0.0f;
            sp24->unk50 = 1;
            sp24->unk48 = 0;
            func_global_asm_80740F48(sp24, 4, arg2);
            break;
        case 9:
            sp24->unk84 = 1;
            break;
        default:
            func_global_asm_80740F48(sp24, arg1, arg2);
            break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1435C0/func_global_asm_8073F328.s")

extern f32 D_global_asm_80760554;

s16 func_global_asm_8073F60C(f32 arg0, f32 arg1, s32 arg2, u16 *arg3) {
    s16 spE;
    s16 spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;

    if (arg2 == 0) {
        if (arg0 <= arg1) {
            *arg3 = 0xFFFF;
            return 0x7FFF;
        } else {
            *arg3 = 0;
            return -0x8000;
        }
    }
    sp8 = 1.0f / arg2;
    if (arg1 < 1.0f) {
        arg1 = 1.0f;
    }
    if (arg0 <= 0.0f) {
        arg0 = 1.0f;
    }
    sp4 = (arg1 - arg0) * sp8 * 8.0f;
    spE = sp4;
    sp0 = sp4 - spE;
    spE -= 1;
    sp0 += 1.0f;
    spC = sp0;
    spE += spC;
    sp0 -= spC;
    *arg3 = D_global_asm_80760554 * sp0;
    return spE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1435C0/func_global_asm_8073F81C.s")

/*
// __n_getVol?
// TODO: Something wrong with the shifts
s16 func_global_asm_8073F81C(s16 arg0, s32 arg1, s16 arg2, u16 arg3) {
    s32 sp4;

    arg1 = arg1 >> 3;
    if (arg1 == 0) {
        return arg0;
    }
    sp4 = arg3 * arg1;
    sp4 = sp4 >> 0x10;
    sp4 += arg2 * arg1;
    return arg0 + sp4;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1435C0/func_global_asm_8073F8A0.s")
