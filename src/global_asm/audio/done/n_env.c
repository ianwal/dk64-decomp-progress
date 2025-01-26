#include <ultra64.h>
#include "functions.h"

void __n_freeParam(ALParam *);
void _n_freePVoice(PVoice *);
s32 func_global_asm_8073F1E4(CustomPVoice *, s32, ALParam *);
Acmd *func_global_asm_8073F328(CustomPVoice *, s16 *, s32, s32, Acmd *);
s16 func_global_asm_8073F81C(s16, s32, s16, u16);
void func_global_asm_807407A8(CustomPVoice *, s32, void *);
extern u8 D_global_asm_807FF0F0;
extern u8 D_global_asm_807FF0F1;
extern u8 D_global_asm_807FF0F2;

// .data
s16 n_eqpower[] = {
	0x7fff, 0x7ffc, 0x7ff5, 0x7fe8, 0x7fd7, 0x7fc0, 0x7fa5, 0x7f84,
	0x7f5f, 0x7f34, 0x7f05, 0x7ed0, 0x7e97, 0x7e58, 0x7e15, 0x7dcd,
	0x7d7f, 0x7d2d, 0x7cd6, 0x7c7a, 0x7c1a, 0x7bb4, 0x7b49, 0x7ada,
	0x7a66, 0x79ed, 0x796f, 0x78ed, 0x7866, 0x77da, 0x7749, 0x76b4,
	0x761a, 0x757b, 0x74d8, 0x7430, 0x7384, 0x72d3, 0x721e, 0x7164,
	0x70a6, 0x6fe3, 0x6f1c, 0x6e51, 0x6d81, 0x6cad, 0x6bd5, 0x6af9,
	0x6a18, 0x6933, 0x684a, 0x675d, 0x666c, 0x6577, 0x647e, 0x6381,
	0x6280, 0x617c, 0x6073, 0x5f67, 0x5e57, 0x5d43, 0x5c2c, 0x5b11,
	0x59f2, 0x58d0, 0x57aa, 0x5681, 0x5555, 0x5425, 0x52f2, 0x51bc,
	0x5082, 0x4f46, 0x4e06, 0x4cc3, 0x4b7d, 0x4a35, 0x48e9, 0x479b,
	0x4649, 0x44f5, 0x439e, 0x4245, 0x40e9, 0x3f8a, 0x3e29, 0x3cc6,
	0x3b60, 0x39f8, 0x388d, 0x3721, 0x35b2, 0x3441, 0x32ce, 0x3159,
	0x2fe2, 0x2e69, 0x2cef, 0x2b72, 0x29f4, 0x2875, 0x26f3, 0x2570,
	0x23ec, 0x2266, 0x20df, 0x1f57, 0x1dce, 0x1c43, 0x1ab7, 0x192a,
	0x179c, 0x160e, 0x147e, 0x12ed, 0x115c, 0x0fca, 0x0e38, 0x0ca5,
	0x0b11, 0x097d, 0x07e9, 0x0654, 0x04c0, 0x032a, 0x0195, 0x0000,
};

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
            sp50->unk60 = ((n_eqpower[sp2C->unk13 & 0x7F] & 0xFFFE) | (sp2C->unk13 >> 7));
            if (D_global_asm_807FF0F0 == 0) {
                sp50->unk60 &= 0xFFFE;
            }
            sp50->unk62 = (n_eqpower[0x7F - (sp2C->unk13 & 0x7F)] & 0xFFFE);
            if (D_global_asm_807FF0F2 != 0) {
                sp50->resampler.unk2C = ((sp50->resampler.unk2C >> 1) + 0x20);
            } else if (D_global_asm_807FF0F1 != 0) {
                sp50->resampler.unk2C = 0x40;
            }
            if (sp2C->unk1C != 0) {
                sp50->resampler.unk30 = 1;
                sp50->resampler.unk32 = 1;
            } else {
                sp50->resampler.unk30 = ((n_eqpower[sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
                sp50->resampler.unk32 = ((n_eqpower[0x7F - sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
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
                sp50->unk68 = ((n_eqpower[sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
                sp50->unk6E = ((n_eqpower[0x7F - sp50->resampler.unk2C] * sp50->resampler.unk2E) >> 0xF);
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
                sp50->unk60 = ((n_eqpower[(sp50->unk7C->unkC_s32 & 0x7F)] & 0xFFFE) | (sp50->unk60 & 1));
                sp50->unk62 = ((n_eqpower[0x7F - (sp50->unk7C->unkC_s32 & 0x7F)] & 0xFFFE) | (sp50->unk62 & 1));
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

    sp34 = arg4;
    sp30 = arg0;
    if ((sp30->unk84 != 1) || (arg3 == 0)) {
        return sp34;
    }
    sp34 = func_global_asm_80740C50(sp30, arg1, arg3, arg4);
    if (sp30->unk78 != 0) {
        sp30->unk78 = 0;
        sp30->unk68 = ((s32) (n_eqpower[sp30->resampler.unk2C] * sp30->resampler.unk2E) >> 0xF);
        sp30->unk66 = func_global_asm_8073F60C(sp30->resampler.unk30, sp30->unk68, sp30->unk74, &sp30->unk64);
        sp30->unk6E = ((s32) (n_eqpower[0x7F - sp30->resampler.unk2C] * sp30->resampler.unk2E) >> 0xF);
        sp30->unk6C = func_global_asm_8073F60C(sp30->resampler.unk32, sp30->unk6E, sp30->unk74, &sp30->unk6A);
        n_aSetVolume(sp34++, A_LEFT | A_VOL, sp30->resampler.unk30, sp30->unk60, sp30->unk62);\
        n_aSetVolume(sp34++, A_RIGHT | A_VOL, sp30->unk6E, sp30->unk6C, sp30->unk6A);\
        n_aSetVolume(sp34++, A_RATE, sp30->unk68, sp30->unk66, sp30->unk64);\
        n_aEnvMixer(sp34++, A_INIT | A_NOAUX, sp30->resampler.unk32, osVirtualToPhysical(sp30->resampler.unk28));
        ; // Yes this is necessary and does change compilation
    } else {
        n_aEnvMixer(sp34++, A_CONTINUE | A_NOAUX, 0, osVirtualToPhysical(sp30->resampler.unk28));
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

// __n_getVol
s16 func_global_asm_8073F81C(s16 ivol, s32 samples, s16 ratem, u16 ratel) {
    s32 m;

    samples >>= 3;
    if (samples == 0) {
        return (s16)ivol;
    }
    m = ((ratel * samples));
    m >>= 0x10;
    m += (ratem * samples);
    ivol += m;
    return ivol;
}
