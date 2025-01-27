#include <ultra64.h>
#include "functions.h"
#include "n_synthInternals.h"

void *func_global_asm_80741070(CustomPVoice *, s16 *, Acmd *);

void *func_global_asm_80740C50(CustomPVoice *arg0, s16 *arg1, s32 arg2, Acmd *arg3) {
    // Unsure of arg2 type, doesn't seem used?
    Acmd *sp2C;
    u8 pad[4];
    f32 sp24;
    Acmd *sp20;
    Acmd *sp1C;
    Acmd *sp18;

    sp2C = arg3;
    sp2C = func_global_asm_80741070(arg0, arg1, arg3);
    if ((arg0->unk8C != 0) && (arg0->unk8C < 0x40)) {
        if (arg0->unk8C >= 6) {
            sp24 = 26755.0f / sqrtf(arg0->unk8C + 1.0f);
        } else {
            sp24 = 65536.0f / ((f32) arg0->unk8C + 1.0f);
        }
        if (sp24 < 7723.0f) {
            sp24 = 7723.0f;
        }
        sp20 = sp2C++;
        sp20->words.w0 = (*arg1 & 0xFFFF);
        sp20->words.w1 = ((((u32) sp24 & 0xFFFF) << 0x10) | ((arg0->unk8C + 1) & 0xFFFF));
    }
    if (arg0->unk92 > 0) {
        if (arg0->unkB8 != 0) {
            func_global_asm_8073BE54(&arg0->unk90, 22050.0f);
        }
        sp1C = sp2C++;
        sp1C->words.w0 = 0x0B000020;
        sp1C->words.w1 = osVirtualToPhysical(&arg0->unk98);
        if (arg0->unkB8 == 2) {
            arg0->unkB8 = 0;
        }
        sp18 = sp2C++;
        sp18->words.w0 = ((*arg1 & 0xFFFF) | (((arg0->unkB8 & 0xFF) << 0x10) | 0x0E000000));
        sp18->words.w1 = (osVirtualToPhysical(arg0->unkBC) & 0xFFFFFF & 0xFFFFFF);
        arg0->unkB8 = 0;
    }
    return sp2C;
}

void func_global_asm_807407A8(void *, s32, void*);

typedef struct {
    u8 unk0[0x8C - 0x0];
    s8 unk8C;
    s8 unk8D;
    s8 unk8E;
    s8 unk8F;
    s16 unk90;
    s16 unk92;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
} Struct80740F48;

s32 func_global_asm_80740F48(N_PVoice *filter, s32 paramID, void *param)
{
	f32 *f = (f32 *) &param;

	switch (paramID) {
	case (AL_FILTER_RESET):
		filter->fx.unk02 = 0;
		func_global_asm_807407A8(filter, AL_FILTER_RESET, param);
		break;
	case (AL_FILTER_12):
		filter->fx.unk02 = (s32) param;
		filter->unkb8 |= 2;
		break;
	case (AL_FILTER_13):
		filter->fx.unk00 = *f;
		filter->unkb8 |= 2;
		break;
	case (AL_FILTER_11):
		filter->unk8c = (u8)param;
		break;
	default:
		func_global_asm_807407A8(filter, paramID, param);
		break;
	}

	return 0;
}
