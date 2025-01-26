#include <ultra64.h>
#include "functions.h"
#include <os.h>
#include <os_internal.h>
#include "n_synthInternals.h"

#define RANGE 2.0f

Acmd *func_global_asm_8073DF50(ALFx *r, ALDelay *d, s32 arg2, s32 buff, Acmd *p);
Acmd *func_global_asm_8073E268(ALFx *r, s32 arg1, s16 *curr_ptr, s32 buff,s32 count, Acmd *p);
Acmd *func_global_asm_8073E460(ALFx *r, s32 arg1, s16 *curr_ptr, s32 buff, Acmd *p);
Acmd *_n_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p);
f32 _doModFunc(ALDelay *d, s32 count);
Acmd *func_global_asm_8073F8A0(s32 sampleOffset, Acmd *cmdptr, s32 fxBus, s32 *numpulls);

extern u8 D_global_asm_807FF0F4[];
extern u8 D_global_asm_807FF0F6[];

// n_alFxPull
Acmd *func_global_asm_8073D1F0(s32 sampleOffset, Acmd *p, s32 arg2)
{
	Acmd *ptr = p;
	ALFx *r = (ALFx *)n_syn->auxBus[arg2].fx;
	s16 i, buff1, buff2, input, output;
	s16 *in_ptr;
    s16 *out_ptr;
    s32 pad;
    s16 *prev_out_ptr = 0;
	ALDelay *d;
    s32 pad1;
	s32 sp58 = 1;
	u32 j;

	/*
	 * pull channels going into this effect first
	 */
	ptr = func_global_asm_8073F8A0(sampleOffset, p, arg2, &sp58);

	input  = N_AL_AUX_L_OUT;
	output = N_AL_AUX_R_OUT;
	buff1  = N_AL_TEMP_0;
	buff2  = N_AL_TEMP_1;

	if (D_global_asm_807FF0F4[arg2] == 0) {
		aMix(ptr++, 0, 0xc000, N_AL_AUX_L_OUT, input);
		aMix(ptr++, 0, 0x4000, N_AL_AUX_R_OUT, input);
	}

	/* and write the mixed value to the delay line at r->input */
	ptr = func_global_asm_8073E460(r, 0, r->input[0], input, ptr);

	if (D_global_asm_807FF0F4[arg2]) {
		ptr = func_global_asm_8073E460(r, 1, r->input[1], 0x930, ptr);
	}

	for (j = 0; j <= D_global_asm_807FF0F4[arg2]; j++) {
		aClearBuffer(ptr++, output, FIXED_SAMPLE << 1); /* clear the AL_AUX_R_OUT */

		for (i = 0; i < r->section_count; i++) {
			d = &r->delay[i];  /* get the ALDelay structure */
			in_ptr = &r->input[j][-d->input];
			out_ptr = &r->input[j][-d->output];

			if (D_global_asm_807FF0F6[arg2] && D_global_asm_807FF0F4[arg2]) {
				d->ffcoef = -d->ffcoef;
				d->fbcoef = -d->fbcoef;
			}

			if (in_ptr == prev_out_ptr) {
				s16 t = buff2;
				buff2 = buff1;
				buff1 = t;
			} else {  /* load data at in_ptr into buff1 */
				ptr = func_global_asm_8073E268(r, j, in_ptr, buff1, FIXED_SAMPLE, ptr);
			}

			ptr = func_global_asm_8073DF50(r, d, j, buff2, ptr);

			if (d->ffcoef) {
				aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);

				if (!d->rs && !d->lp) {
					ptr = func_global_asm_8073E460(r, j, out_ptr, buff2, ptr);
				}
			}

			if (d->fbcoef) {
				aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
				ptr = func_global_asm_8073E460(r, j, in_ptr, buff1, ptr);
			}

			if (d->lp) {
				ptr = _n_filterBuffer(d->lp, j, buff2, ptr);
			}

			if (!d->rs) {
				ptr = func_global_asm_8073E460(r, j, out_ptr, buff2, ptr);
			}

			if (d->gain) {
				if (D_global_asm_807FF0F4[arg2]) {
					aMix(ptr++, 0, (u16)d->gain, buff2, output);
				} else {
					u32 sp34 = d->gain * 1.4141999483109f;

					if (sp34 > 0x7fff) {
						sp34 = 0x7fff;
					}

					aMix(ptr++, 0, (u16)sp34, buff2, output);
				}
			}

			prev_out_ptr = &r->input[j][d->output];
		}

		if (D_global_asm_807FF0F4[arg2] && j == 0) {
			ptr = func_global_asm_8073E268(r, 1, r->input[1], input, FIXED_SAMPLE, ptr);

			if (D_global_asm_807FF0F6[arg2]) {
				aMix(ptr++, 0, 0x5a82, output, 0x650);
			} else {
				aMix(ptr++, 0, 0x5a82, output, 0x4e0);
			}
		} else {
			// empty
		}

		/*
		 * output already in AL_AUX_R_OUT
		 *      just copy to AL_AUX_L_OUT
		 */
		aDMEMMove(ptr++, output, N_AL_AUX_L_OUT, FIXED_SAMPLE << 1);

		/*
		 * bump the master delay line input pointer
		 * modulo the length
		 */
		r->input[j] += FIXED_SAMPLE;

		if (r->input[j] > &r->base[j][r->length]) {
			r->input[j] -= r->length;
		}
	}

	return ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073DA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073DF50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E268.s")

Acmd *func_global_asm_8073E460(ALFx *arg0, s32 arg1, s16 *arg2, s32 arg3, Acmd *arg4) {
    Acmd *sp34;
    s32 sp30;
    s32 sp2C;
    u32 sp28;
    u32 sp24;
    Acmd *sp20;
    Acmd *sp1C;
    Acmd *sp18;

    sp34 = arg4;
    sp24 = &arg0->base[arg1][arg0->length];
    if ((u32)arg2 < (u32)arg0->base[arg1]) {
        arg2 += arg0->length;
    }
    sp28 = &arg2[184];
    if (sp28 > sp24) {
        sp30 = (s32) (sp28 - sp24) >> 1;
        sp2C = (s32) (sp24 - (s32)arg2) >> 1;
        sp20 = sp34++;
        sp20->words.w0 = (((sp2C * 2) & 0xFFF) << 0xC) | 0x06000000 | (arg3 & 0xFFF);
        sp20->words.w1 = osVirtualToPhysical((void *) arg2);
        sp1C = sp34++;
        sp1C->words.w0 = (((sp30 * 2) & 0xFFF) << 0xC) | 0x06000000 | ((arg3 + (sp2C * 2)) & 0xFFF);
        sp1C->words.w1 = osVirtualToPhysical(arg0->base[arg1]);
        if (1) {}
    } else {
        sp18 = sp34++;
        sp18->words.w0 = (arg3 & 0xFFF) | 0x06170000;
        sp18->words.w1 = osVirtualToPhysical((void *) arg2);
    }
    return sp34;
}

Acmd *_n_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p)
{
	Acmd *ptr = p;
	s16 tmp = count >> 8;

	n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
	n_aPoleFilter(ptr++, lp->first, lp->fgain, tmp, osVirtualToPhysical(lp->fstate[buff]));
	lp->first = 0;

	return ptr;
}

f32 func_global_asm_8073E73C(Struct8073BC74_auxbus_unk20_unk4 *arg0, s32 arg1) {
    f32 sp4;

    arg0->unk14 += (arg0->unk10 * (f32) arg1);
    if (arg0->unk14 > 2.0f) {
        arg0->unk14 -= 4.0f;
    } else {
        arg0->unk14 = arg0->unk14;
    }
    sp4 = arg0->unk14;
    sp4 = sp4 < 0.0f ? -sp4 : sp4;
    sp4 -= 1.0f;
    return arg0->unk1C * sp4;
}

Acmd *func_global_asm_8073FD90(s32, Acmd *);

s32 *func_global_asm_8073E800(s32 arg0, Acmd *arg1) {
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp24 = arg1;
    sp24 = func_global_asm_8073FD90(arg0, sp24);
    sp20 = sp24++;
    sp20->words.w0 = 0x0D000000;
    sp1C = sp24++;
    sp1C->words.w0 = 0x062E0000;
    sp1C->words.w1 = n_syn->sv_dramout;
    return sp24;
}