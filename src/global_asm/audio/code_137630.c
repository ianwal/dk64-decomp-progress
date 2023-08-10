#include <ultra64.h>
#include "functions.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Struct80732DEC;

typedef struct {
    s32 unk0;
    u8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    u16 unk22;
    u16 unk24;
    s16 unk26;
    union {
        u8 unk28[4];
        f32 unk28_f32;
    };
} Struct80732B3C;

extern Struct80732B3C *D_global_asm_807FF030;
extern Struct80732B3C *D_global_asm_807FF034;

f32 func_global_asm_80732930(u8);
f32 func_global_asm_80739FE0(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137630/func_global_asm_80732930.s")

/*
// No idea why this doesn't match, something to do with the shift
f32 func_global_asm_80732930(u8 arg0) {
    f32 sp4;
    f32 sp0;

    sp4 = 1.030992985f;
    sp0 = 1.0f;
    while (arg0) {
        if (arg0 & 1) {
            sp0 *= sp4;
        }
        sp4 *= sp4;
        arg0 >>= 1;
    }
    return sp0;
}
*/

s32 func_global_asm_807329AC(Struct80732B3C **arg0, f32 *arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    Struct80732B3C *sp2C;
    s32 sp28;

    sp28 = 0;
    if (arg5 == 0) {
        return 0;
    }
    if (D_global_asm_807FF030 != NULL) {
        sp2C = D_global_asm_807FF030;
        D_global_asm_807FF030 = D_global_asm_807FF030->unk0;
        sp2C->unk4 = arg2;
        *arg0 = sp2C;
        sp28 = arg5 << 0xE;
        switch (arg2) {
            case 0x1:
                sp2C->unk24 = 0;
                sp2C->unk22 = 0x103 - arg3;
                sp2C->unk28[0] = arg4 >> 1;
                sp2C->unk28[1] = 0x7F - sp2C->unk28[0];
                *arg1 = sp2C->unk28[1];
                break;
            case 0x80:
                sp2C->unk28_f32 = func_global_asm_80732930(arg4);
                sp2C->unk24 = 0;
                sp2C->unk22 = 0x103 - arg3;
                *arg1 = 1.0f;
                break;
            default:
                break;
        }
    }
    return sp28;
}

s32 func_global_asm_80732B3C(Struct80732B3C *arg0, f32 *arg1) {
    f32 sp2C;
    Struct80732B3C *sp28;
    s32 sp24;

    sp28 = arg0;
    sp24 = 0x3E80;
    switch (sp28->unk4) {
        case 0x1:
            sp28->unk24++;
            if (sp28->unk24 >= sp28->unk22) {
                sp28->unk24 = 0;
            }
            sp2C = (f32)sp28->unk24 / sp28->unk22;
            sp2C = func_global_asm_80612D1C(sp2C * 6.283185482f);
            sp2C = sp2C * sp28->unk28[0];
            *arg1 = sp28->unk28[1] + sp2C;
            break;
        case 0x80:
            sp28->unk24++;
            if (sp28->unk24 >= sp28->unk22) {
                sp28->unk24 = 0;
            }
            sp2C = (f32)sp28->unk24 / sp28->unk22;
            sp2C = func_global_asm_80612D1C(sp2C * 6.283185482f) * sp28->unk28_f32;
            *arg1 = func_global_asm_80739FE0(sp2C);
            break;
        default:
            break;
    }
    return sp24;
}

void func_global_asm_80732D80(s32 *arg0) {
    s32 *sp4;

    sp4 = arg0;
    *arg0 = D_global_asm_807FF030;
    D_global_asm_807FF030 = arg0;
}

f32 func_global_asm_80732DAC(f32 arg0) {
    return func_global_asm_80612D1C(arg0 / 10430.37988f);
}

void func_global_asm_80732DEC(Struct80732DEC *arg0, s32 arg1) {
    Struct80732B3C *sp24;
    s32 i;

    D_global_asm_807FF034 = func_global_asm_80732444(0, 0, arg0->unkC, arg1, 0x2C);
    D_global_asm_807FF030 = D_global_asm_807FF034;
    D_global_asm_807FF030 = D_global_asm_807FF034;
    sp24 = D_global_asm_807FF034;
    for (i = 0; i < (arg1 - 1); i++) {
        sp24->unk0 = &D_global_asm_807FF034[i + 1];
        sp24 = sp24->unk0;
    }
    sp24->unk0 = NULL;
    arg0->unk10 = &func_global_asm_807329AC;
    arg0->unk14 = &func_global_asm_80732B3C;
    arg0->unk18 = &func_global_asm_80732D80;
}
