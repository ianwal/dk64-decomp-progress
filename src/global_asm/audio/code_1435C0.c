#include <ultra64.h>
#include "functions.h"

// Jumptable, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1435C0/func_global_asm_8073E8C0.s")

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

Acmd *func_global_asm_80740C50(CustomPVoice *, s16 *, s32, Acmd *);
extern s16 D_global_asm_80756490[];

Acmd *func_global_asm_8073F328(CustomPVoice *arg0, s16 *arg1, s32 arg2, s32 arg3, Acmd *arg4) {
    // unsure on arg2
    Acmd *sp34;
    CustomPVoice *sp30;
    Acmd *sp2C;
    Acmd *sp28;
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp34 = arg4;
    sp30 = arg0;
    if ((sp30->unk84 != 1) || (arg3 == 0)) {
        return sp34;
    }
    sp34 = func_global_asm_80740C50(sp30, arg1, arg3, arg4);
    if (sp30->unk78 != 0) {
        sp30->unk78 = 0;
        sp30->unk68 = ((s32) (D_global_asm_80756490[sp30->resampler.unk2C] * sp30->resampler.unk2E) >> 0xF);
        sp30->unk66 = func_global_asm_8073F60C(sp30->resampler.unk30, sp30->unk68, sp30->unk74, &sp30->unk64);
        sp30->unk6E = ((s32) (D_global_asm_80756490[0x7F - sp30->resampler.unk2C] * sp30->resampler.unk2E) >> 0xF);
        sp30->unk6C = func_global_asm_8073F60C(sp30->resampler.unk32, sp30->unk6E, sp30->unk74, &sp30->unk6A);
        sp2C = sp34++;
        sp2C->words.w0 = ((sp30->resampler.unk30 & 0xFFFF) | 0x09060000);
        sp2C->words.w1 = (((sp30->unk60 & 0xFFFF) << 0x10) | (sp30->unk62 & 0xFFFF));
        sp28 = sp34++;
        sp28->words.w0 = ((sp30->unk6E & 0xFFFF) | 0x09040000);
        sp28->words.w1 = (((sp30->unk6C & 0xFFFF) << 0x10) | (sp30->unk6A & 0xFFFF));
        sp24 = sp34++;
        sp24->words.w0 = ((sp30->unk68 & 0xFFFF) | 0x09000000);
        sp24->words.w1 = (((sp30->unk66 & 0xFFFF) << 0x10) | (sp30->unk64 & 0xFFFF));
        sp20 = sp34++;
        sp20->words.w0 = ((sp30->resampler.unk32 & 0xFFFF) | 0x03010000);
        sp20->words.w1 = osVirtualToPhysical(sp30->resampler.unk28);
        ; // Yes this is necessary and does change compilation
    } else {
        sp1C = sp34++;
        sp1C->words.w0 = 0x03000000;
        sp1C->words.w1 = osVirtualToPhysical(sp30->resampler.unk28);
    }
    *arg1 += 0x170;
    sp30->unk70++;
    return sp34;
}



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
    *arg3 = 65535.0f * sp0;
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
