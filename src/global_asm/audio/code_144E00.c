#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_144E00/func_global_asm_80740100.s")

Acmd *func_global_asm_80740A90(Acmd *, CustomPVoice *, s32, s32, s16, s16, s32);

/*
Acmd *func_global_asm_80740100(CustomPVoice *arg0, s16 *arg1, s32 arg2, Acmd *arg3) {
    Acmd *sp7C;
    s16 sp7A;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    CustomPVoice *sp44;
    Acmd *sp40;
    Acmd *sp3C;
    Acmd *sp38;
    CustomPVoice_unk20 *temp_t0_2;
    s32 temp_t0;
    u32 var_s0;

    sp7C = arg3;
    sp4C = 0;
    sp48 = 0;
    sp44 = arg0;
    if (arg2 == 0) {
        return sp7C;
    }
    sp7A = 0;
    sp40 = sp7C++;
    sp40->words.w0 = (s32) ((sp44->unk24 & 0xFFFFFF) | 0x0B000000);
    sp40->words.w1 = (s32) ((sp44->unk20->unk10_s32 + 8) & 0x1FFFFFFF);
    var_s0 = (u32) sp44->unk18 < (u32) (sp44->resampler.unk4 + arg2);
    if (var_s0) {
        var_s0 = sp44->unk1C != 0;
    }
    sp48 = var_s0;
    if (sp48 != 0) {
        sp5C = sp44->unk18 - sp44->resampler.unk4;
    } else {
        sp5C = arg2;
    }
    if (sp44->resampler.unk8 != 0) {
        sp54 = 0x10 - sp44->resampler.unk8;
    } else {
        sp54 = 0;
    }
    sp74 = sp5C - sp54;
    if (sp74 < 0) {
        sp74 = 0;
    }
    sp70 = (s32) (sp74 + 0xF) >> 4;
    sp6C = sp70 * 9;
    if (sp48 != 0) {
        sp7C = func_global_asm_80740A90(sp7C, sp44, sp74, sp6C, (s32) *arg1, (s32) sp7A, sp44->resampler.unkC);
        if (sp44->resampler.unk8 != 0) {
            *arg1 += sp44->resampler.unk8 * 2;
        } else {
            *arg1 += 0x20;
        }
        sp44->resampler.unk8 = (s32) (sp44->unk14 & 0xF);
        sp44->resampler.unk10 = (s32) (sp44->unk20->unk10 + (((u32) sp44->unk14 >> 4) * 9) + 9);
        sp44->resampler.unk4 = (u32) sp44->unk14;
        sp50 = (s32) *arg1;
        while (sp5C < arg2) {
            arg2 -= sp5C;
            sp58 = (((sp70 + 1) << 5) + sp50 + 0x10) & ~0x1F;
            sp50 += sp5C * 2;
            temp_t0 = sp44->unk1C;
            if ((temp_t0 != -1) && (temp_t0 != 0)) {
                sp44->unk1C = (s32) (sp44->unk1C - 1);
            }
            if ((u32) arg2 < (u32) (sp44->unk18 - sp44->unk14)) {
                sp5C = arg2;
            } else {
                sp5C = sp44->unk18 - sp44->unk14;
            }
            sp74 = (sp5C + sp44->resampler.unk8) - 0x10;
            if (sp74 < 0) {
                sp74 = 0;
            }
            sp70 = (s32) (sp74 + 0xF) >> 4;
            sp6C = sp70 * 9;
            sp7C = func_global_asm_80740A90(sp7C, sp44, sp74, sp6C, sp58, (s32) sp7A, sp44->resampler.unkC | 2);
            sp3C = sp7C++;
            sp3C->words.w0 = (s32) ((((sp44->resampler.unk8 * 2) + sp58) & 0xFFFFFF) | 0x0A000000);
            sp3C->words.w1 = (s32) (((sp50 & 0xFFFF) << 0x10) | ((sp5C * 2) & 0xFFFF));
        }
        sp44->resampler.unk8 = (s32) ((sp44->resampler.unk8 + arg2) & 0xF);
        sp44->resampler.unk4 = (u32) (sp44->resampler.unk4 + arg2);
        sp44->resampler.unk10 += (sp70 * 9);
        return sp7C;
    }
    sp5C = sp70 * 0x10;
    temp_t0_2 = sp44->unk20;
    sp68 = (sp44->resampler.unk10 + sp6C) - (temp_t0_2->unk0 + temp_t0_2->unk4);
    if (sp68 < 0) {
        sp68 = 0;
    }
    sp60 = (sp68 / 9) * 0x10;
    if ((sp5C + sp54) < sp60) {
        sp60 = sp5C + sp54;
    }
    sp6C -= sp68;
    if ((sp60 - (sp60 & 0xF)) < arg2) {
        sp4C = 1;
        sp7C = func_global_asm_80740A90(sp7C, sp44, sp5C - sp60, sp6C, (s32) *arg1, (s32) sp7A, sp44->resampler.unkC);
        if (sp44->resampler.unk8 != 0) {
            *arg1 += sp44->resampler.unk8 * 2;
        } else {
            *arg1 += 0x20;
        }
        sp44->resampler.unk8 = (s32) ((sp44->resampler.unk8 + arg2) & 0xF);
        sp44->resampler.unk4 = (u32) (sp44->resampler.unk4 + arg2);
        sp44->resampler.unk10 = (s32) (sp44->resampler.unk10 + (sp70 * 9));
    } else {
        sp44->resampler.unk8 = 0;
        sp44->resampler.unk10 = (s32) (sp44->resampler.unk10 + (sp70 * 9));
    }
    if (sp60 != 0) {
        sp44->resampler.unk8 = 0;
        if (sp4C != 0) {
            sp64 = ((sp54 + sp5C) - sp60) * 2;
        } else {
            sp64 = 0;
        }
        sp38 = sp7C++;
        sp38->words.w0 = (s32) (((*arg1 + sp64) & 0xFFFFFF) | 0x02000000);
        sp38->words.w1 = (s32) (sp60 * 2);
    }
    return sp7C;
}
*/

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_144E00/func_global_asm_807407A8.s")

/*
void func_global_asm_807407A8(CustomPVoice *arg0, s32 arg1, s32 *arg2) {
    CustomPVoice *sp24;

    sp24 = arg0;
    switch (arg1) {
    case 5:
        sp24->unk20 = arg2;
        sp24->resampler.unk10 = sp24->unk20->unk0;
        sp24->resampler.unk4 = 0;
        switch (sp24->unk20->unk8) {
        case 0:
            sp24->unk20->unk4 = ((sp24->unk20->unk4 / 9) * 9);
            sp24->unk24 = (sp24->unk20->unk10->unk0 * 2 * sp24->unk20->unk10->unk4 * 8);
            if (sp24->unk20->unkC != 0) {
                sp24->unk14 = sp24->unk20->unkC->unk0;
                sp24->unk18 = sp24->unk20->unkC->unk4;
                sp24->unk1C = sp24->unk20->unkC->unk8;
                bcopy(&sp24->unk20->unkC->unkC, sp24->unk10, 0x20);
            } else {
                sp24->unk1C = 0;
                sp24->unk14 = sp24->unk18 = sp24->unk1C;
            }
            break;
        case 1:
            if (sp24->unk20->unkC != 0) {
                sp24->unk14 = sp24->unk20->unkC->unk0;
                sp24->unk18 = sp24->unk20->unkC->unk4;
                sp24->unk1C = sp24->unk20->unkC->unk8;
            } else {
                sp24->unk1C = 0;
                sp24->unk14 = sp24->unk18 = sp24->unk1C;
                break;
            }
            break;
        }
        break;
    case 4:
        sp24->resampler.unk8 = 0;
        sp24->resampler.unkC = 1;
        sp24->resampler.unk4 = 0;
        if (sp24->unk20) {
            sp24->resampler.unk10 = sp24->unk20->unk0;
            if (!sp24->unk20->unk8) {
                if (sp24->unk20->unkC) {
                    sp24->unk1C = sp24->unk20->unkC->unk8;
                }
            } else if ((sp24->unk20->unk8 == 1) && (sp24->unk20->unkC)) {
                sp24->unk1C = sp24->unk20->unkC->unk8;
                break;
            }
        }
        break;
    }
}
*/

Acmd *func_global_asm_80740A90(Acmd *arg0, CustomPVoice *arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    s32 sp2C;
    s32 sp28;
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    if (arg3 > 0) {
        sp28 = arg1->unk28(arg1->resampler.unk10, arg3, arg1->resampler.unk0);
        sp2C = sp28 & 7;
        arg3 += sp2C;
        sp24 = arg0++;
        sp24->words.w0 = ((((arg3 - (arg3 & 7)) + 8) & 0xFFF) << 0xC) | 0x04000000 | (arg5 & 0xFFF);
        sp24->words.w1 = (s32) (sp28 - sp2C);
        ;
    } else {
        sp2C = 0;
    }
    if (arg6 & 2) {
        sp20 = arg0++;
        sp20->words.w0 = 0x0F000000;
        sp20->words.w1 = (s32) (arg1->unk10 & 0x1FFFFFFF);
    }
    sp1C = arg0++;
    sp1C->words.w0 = (arg1->unkC & 0x1FFFFFFF & 0xFFFFFF) | 0x01000000;
    sp1C->words.w1 = (s32) (((arg6 & 0xF) << 0x1C) | (((arg2 * 2) & 0xFFF) << 0x10) | ((sp2C & 0xF) << 0xC) | (arg4 & 0xFFF));
    arg1->resampler.unkC = 0;
    return arg0;
}

