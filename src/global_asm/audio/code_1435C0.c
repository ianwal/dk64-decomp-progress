#include <ultra64.h>
#include "functions.h"

void __n_freeParam(ALParam *);
void _n_freePVoice(PVoice *);
s32 func_global_asm_8073F1E4(CustomPVoice *, s32, ALParam *);
Acmd *func_global_asm_8073F328(CustomPVoice *, s16 *, s32, s32, Acmd *);
s16 func_global_asm_8073F81C(s16, s32, s16, u16);
void func_global_asm_807407A8(CustomPVoice *, s32, void *);
extern s16 D_global_asm_80756490[];
extern u8 D_global_asm_807FF0F0;
extern u8 D_global_asm_807FF0F1;
extern u8 D_global_asm_807FF0F2;

Acmd *func_global_asm_8073E8C0(CustomPVoice *arg0, s32 arg1, s32 arg2) {
    // alEnvmixerPull
    s32 sp54;
    CustomPVoice *sp50;
    s16 sp4E;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s16 sp3E;
    s32 sp38;
    CustomPVoice_unk7C *sp34;
    s32 sp30;
    CustomPVoice_unk7C *sp2C;
    s32 sp28;
    CustomPVoice_unk7C *sp24;
    CustomPVoice_unk7C *sp20;

    sp54 = arg2;
    sp50 = arg0;
    sp44 = arg1;
    sp3E = 0;
    sp30 = 0xB8;
    sp4E = 0;
    while (sp50->unk7C) {
        sp48 = sp44;
        sp44 = sp50->unk7C->unk4;
        sp40 = (((sp44 - sp48) + 0xB7) / 184) * 0xB8;
        if (sp40 == 0) {
            sp44 = sp48;
        }
        if (sp40 > sp30 ) break;
        switch (sp50->unk7C->unk8) {
        case 13:
            sp2C = sp50->unk7C;
            if (sp2C->unkA != 0) {
                sp50->resampler.unk1C = 1;
            }
            func_global_asm_807407A8(sp50, 5, sp2C->unk20);
            sp50->unk84 = 1;
            sp50->unk78 = 1;
            sp50->unk70_s32 = 0;
            sp50->unk74 = (((sp2C->unk1C + 0xB7) / 184) * 0xB8);
            sp28 = (sp2C->unk10 + sp2C->unk10) / 2;
            sp50->resampler.unk2E = sp28;
            sp50->resampler.unk2C = sp2C->unk12;
            sp50->unk60 = ((D_global_asm_80756490[sp2C->unk13 & 0x7F] & 0xFFFE) | (sp2C->unk13 >> 7));
            if (D_global_asm_807FF0F0 == 0) {
                sp50->unk60 &= 0xFFFE;
            }
            sp50->unk62 = (D_global_asm_80756490[0x7F - (sp2C->unk13 & 0x7F)] & 0xFFFE);
            if (D_global_asm_807FF0F2 != 0) {
                sp50->resampler.unk2C = ((sp50->resampler.unk2C >> 1) + 0x20);
            } else if (D_global_asm_807FF0F1 != 0) {
                sp50->resampler.unk2C = 0x40;
            }
            if (sp2C->unk1C != 0) {
                sp50->resampler.unk30 = 1;
                sp50->resampler.unk32 = 1;
            } else {
                sp50->resampler.unk30 = ((D_global_asm_80756490[sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
                sp50->resampler.unk32 = ((D_global_asm_80756490[0x7F - sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
            }
            sp50->resampler.unk18 = sp2C->unkC_f32;
            sp50->unk92 = sp2C->unk15;
            sp50->unk90 = sp2C->unk18;
            sp50->unkB8 = 1;
            sp50->unk8C = sp2C->unk14;
            break;
        case 11:
        case 12:
        case 16:
            sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp40, sp54);
            if (sp50->unk70_s32 >= sp50->unk74) {
                sp50->unk68 = ((D_global_asm_80756490[sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
                sp50->unk6E = ((D_global_asm_80756490[0x7F - sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
                sp50->unk70_s32 = sp50->unk74;
                sp50->resampler.unk30 = sp50->unk68;
                sp50->resampler.unk32 = sp50->unk6E;
            } else {
                sp50->resampler.unk30 = func_global_asm_8073F81C(sp50->resampler.unk30, sp50->unk70_s32, sp50->unk66, sp50->unk64);
                sp50->resampler.unk32 = func_global_asm_8073F81C(sp50->resampler.unk32, sp50->unk70_s32, sp50->unk6C, sp50->unk6A);
            }
            if (sp50->resampler.unk30 == 0) {
                sp50->resampler.unk30 = 1;
            }
            if (sp50->resampler.unk32 == 0) {
                sp50->resampler.unk32 = 1;
            }
            if (sp50->unk7C->unk8 == 0xC) {
                if (D_global_asm_807FF0F2 != 0) {
                    sp50->resampler.unk2C = ((sp50->unk7C->unkE >> 1) + 0x20);
                } else if (D_global_asm_807FF0F1 != 0) {
                    sp50->resampler.unk2C = 0x40;
                } else {
                    sp50->resampler.unk2C = sp50->unk7C->unkC_s32;
                }
            }
            if (sp50->unk7C->unk8 == 0xB) {
                sp50->unk70_s32 = 0;
                sp38 = sp50->unk7C->unkC_s32;
                sp38 = (sp38 + sp38) / 2;
                sp50->resampler.unk2E = sp38;
                sp50->unk74 = (((sp50->unk7C->unk10_s32 + 0xB7) / 184) * 0xB8);
            }
            if (sp50->unk7C->unk8 == 0x10) {
                if (((((sp50->unk60 ^ sp50->unk62) & 1) ^ ((sp50->unk7C->unkC_s32 + 1) >> 7)) != 0) && (D_global_asm_807FF0F0 != 0)) {
                    if (sp50->resampler.unk2C >= 0x41) {
                        sp50->unk60 ^= 1;
                    } else {
                        sp50->unk62 ^= 1;
                    }
                }
                sp50->unk60 = ((D_global_asm_80756490[(sp50->unk7C->unkC_s32 & 0x7F)] & 0xFFFE) | (sp50->unk60 & 1));
                sp50->unk62 = ((D_global_asm_80756490[0x7F - (sp50->unk7C->unkC_s32 & 0x7F)] & 0xFFFE) | (sp50->unk62 & 1));
            }
            sp50->unk78 = 1;
            break;
        case 14:
            sp24 = sp50->unk7C;
            if (sp24->unkA != 0) {
                sp50->resampler.unk1C = 1;
            }
            func_global_asm_807407A8(sp50, 5, sp24->unkC_s32);
            sp50->unk84 = 1;
            break;
        case 15:
            sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp40, sp54);
            func_global_asm_8073F1E4(sp50, 4, 0);
            break;
        case 0:
            sp20 = sp50->unk7C;
            sp20->unkC_ptr->unk88 = 0;
            _n_freePVoice(sp20->unkC_s32);
            break;
        case 7:
            sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp40, sp54);
            sp50->resampler.unk18 = sp50->unk7C->unkC_f32;
            break;
        case 8:
            sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp40, sp54);
            sp50->resampler.unk1C = 1;
            break;
        case 5:
            sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp40, sp54);
            func_global_asm_807407A8(sp50, 5, sp50->unk7C->unkC_s32);
            break;
        default:
            sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp40, sp54);
            func_global_asm_8073F1E4(sp50, sp50->unk7C->unk8, sp50->unk7C->unkC_s32);
            break;
        }
        sp3E += sp40 * 2;
        sp30 -= sp40;
        sp34 = sp50->unk7C;
        sp50->unk7C = sp50->unk7C->unk0;
        if (sp50->unk7C == NULL) {
            sp50->unk80 = 0;
        }
        __n_freeParam(sp34);
    }
    sp54 = func_global_asm_8073F328(sp50, &sp4E, &sp3E, sp30, sp54);
    if (sp50->unk70_s32 > sp50->unk74) {
        sp50->unk70_s32 = sp50->unk74;
    }
    return sp54;
}

s32 func_global_asm_8073F1E4(CustomPVoice *arg0, s32 arg1, ALParam *arg2) {
    CustomPVoice *sp24;

    sp24 = arg0;
    switch (arg1) {
        case 3:
            if (sp24->unk80 != NULL) {
                *sp24->unk80 = arg2;
            } else {
                sp24->unk7C = arg2;
            }
            sp24->unk80 = arg2;
            break;
        case 4:
            sp24->unk78 = 1;
            sp24->unk84 = 0;
            sp24->resampler.unk2E = 1;
            sp24->unk74 = 0;
            sp24->resampler.unk20 = 0.0f;
            sp24->resampler.unk24 = 1;
            sp24->resampler.unk1C = 0;
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
