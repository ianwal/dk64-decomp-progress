#include <ultra64.h>
#include "functions.h"
#include "n_synthInternals.h"
#include <os.h>
#include <R4300.h>

#define ADPCMFBYTES      9
#define LFSAMPLES        4


Acmd *func_global_asm_80740A90(Acmd *, CustomPVoice *, s32, s32, s16, s16, s32);

// n_alAdpcmPull
Acmd *func_global_asm_80740100(N_PVoice *filter, s16 *outp, s32 outCount, Acmd *p)
{
	Acmd *ptr = p;
	s16 inp;
	s32 tsam;
	s32 nframes;
	s32 nbytes;
	s32 overFlow;
	s32 startZero;
	s32 nOver;
	s32 nSam;
	s32 op;
	s32 nLeft;
	s32 bEnd;
	s32 decoded = 0;
	s32 looped = 0;

	N_PVoice *f = filter;

	if (outCount == 0) {
		return ptr;
	}

	inp = N_AL_DECODER_IN;

	aLoadADPCM(ptr++, f->dc_bookSize, K0_TO_PHYS(f->dc_table->waveInfo.adpcmWave.book->book));

	looped = (outCount + f->dc_sample > f->dc_loop.end) && (f->dc_loop.count != 0);

	if (looped) {
		nSam = f->dc_loop.end - f->dc_sample;
	} else {
		nSam = outCount;
	}

	if (f->dc_lastsam) {
		nLeft = ADPCMFSIZE - f->dc_lastsam;
	} else {
		nLeft = 0;
	}

	tsam = nSam - nLeft;

	if (tsam<0) {
		tsam = 0;
	}

	nframes = (tsam + ADPCMFSIZE - 1) >> LFSAMPLES;
	nbytes =  nframes*ADPCMFBYTES;

	if (looped) {
		ptr = func_global_asm_80740A90(ptr, f, tsam, nbytes, *outp, inp, f->dc_first);

		/*
		 * Fix up output pointer, which will be used as the input pointer
		 * by the following module.
		 */
		if (f->dc_lastsam) {
			*outp += (f->dc_lastsam<<1);
		} else {
			*outp += (ADPCMFSIZE<<1);
		}

		/*
		 * Now fix up state info to reflect the loop start point
		 */
		f->dc_lastsam = f->dc_loop.start &0xf;
		f->dc_memin = f->dc_table->base + ADPCMFBYTES * ((s32) (f->dc_loop.start>>LFSAMPLES) + 1);
		f->dc_sample = f->dc_loop.start;

		bEnd = *outp;

		while (outCount > nSam) {
			outCount -= nSam;

			/*
			 * Put next one after the end of the last lot - on the
			 * frame boundary (32 byte) after the end.
			 */
			op = (bEnd + ((nframes+1)<<(LFSAMPLES+1)) + 16) & ~0x1f;

			/*
			 * The actual end of data
			 */
			bEnd += (nSam<<1);

			/*
			 * -1 is loop forever - the loop count is not exact now
			 * for small loops!
			 */
			if (f->dc_loop.count != -1 && f->dc_loop.count != 0) {
				f->dc_loop.count--;
			}

			/*
			 * What's left to compute.
			 */
			nSam = MIN(outCount, f->dc_loop.end - f->dc_loop.start);
			tsam = nSam - ADPCMFSIZE + f->dc_lastsam;

			if (tsam < 0) {
				tsam = 0;
			}

			nframes = (tsam+ADPCMFSIZE - 1) >> LFSAMPLES;
			nbytes =  nframes*ADPCMFBYTES;
			ptr = func_global_asm_80740A90(ptr, f, tsam, nbytes, op, inp, f->dc_first | A_LOOP);

			/*
			 * Merge the two sections in DMEM.
			 */
			aDMEMMove(ptr++, op + (f->dc_lastsam << 1), bEnd, nSam << 1);
		}

		f->dc_lastsam = (outCount + f->dc_lastsam) & 0xf;
		f->dc_sample += outCount;
		f->dc_memin += ADPCMFBYTES*nframes;

		return ptr;
	}

	/*
	 * The unlooped case, which is executed most of the time
	 */

	nSam = nframes << LFSAMPLES;

	/*
	 * overFlow is the number of bytes past the end
	 * of the bitstream I try to generate
	 */
	overFlow = f->dc_memin + nbytes - (s32)(f->dc_table->base + f->dc_table->len);

	if (overFlow < 0) {
		overFlow = 0;
	}

	nOver = (overFlow / ADPCMFBYTES) << LFSAMPLES;

	if (nOver > nSam + nLeft) {
		nOver = nSam + nLeft;
	}

	nbytes -= overFlow;

	if (nOver - (nOver & 0xf) < outCount) {
		decoded = 1;
		ptr = func_global_asm_80740A90(ptr, f, nSam - nOver, nbytes, *outp, inp, f->dc_first);

		if (f->dc_lastsam) {
			*outp += f->dc_lastsam << 1;
		} else {
			*outp += ADPCMFSIZE << 1;
		}

		f->dc_lastsam = (outCount + f->dc_lastsam) & 0xf;
		f->dc_sample += outCount;
		f->dc_memin += ADPCMFBYTES * nframes;
	} else {
		f->dc_lastsam = 0;
		f->dc_memin += ADPCMFBYTES * nframes;
	}

	/*
	 * Put zeros in if necessary
	 */
	if (nOver) {
		f->dc_lastsam = 0;

		if (decoded) {
			startZero = (nLeft + nSam - nOver) << 1;
		} else {
			startZero = 0;
		}

		aClearBuffer(ptr++, startZero + *outp, nOver << 1);
	}

	return ptr;
}

// n_alLoadParam
void func_global_asm_807407A8(N_PVoice *filter, s32 paramID, void *param)
{
	N_PVoice *a = filter;

	switch (paramID) {
	case (AL_FILTER_SET_WAVETABLE):
		a->dc_table = (ALWaveTable *) param;
		a->dc_memin = a->dc_table->base;
		a->dc_sample = 0;

		switch (a->dc_table->type) {
		case (AL_ADPCM_WAVE):
			a->dc_table->len = ADPCMFBYTES * ((s32) (a->dc_table->len/ADPCMFBYTES));

			a->dc_bookSize = 2*a->dc_table->waveInfo.adpcmWave.book->order*
				a->dc_table->waveInfo.adpcmWave.book->npredictors*ADPCMVSIZE;

			if (a->dc_table->waveInfo.adpcmWave.loop) {
				a->dc_loop.start = a->dc_table->waveInfo.adpcmWave.loop->start;
				a->dc_loop.end = a->dc_table->waveInfo.adpcmWave.loop->end;
				a->dc_loop.count = a->dc_table->waveInfo.adpcmWave.loop->count;

				bcopy(a->dc_table->waveInfo.adpcmWave.loop->state, a->dc_lstate, sizeof(ADPCM_STATE));
			} else {
				a->dc_loop.start = a->dc_loop.end = a->dc_loop.count = 0;
			}
			break;
		case (AL_RAW16_WAVE):
			if (a->dc_table->waveInfo.rawWave.loop) {
				a->dc_loop.start = a->dc_table->waveInfo.rawWave.loop->start;
				a->dc_loop.end = a->dc_table->waveInfo.rawWave.loop->end;
				a->dc_loop.count = a->dc_table->waveInfo.rawWave.loop->count;
			} else {
				a->dc_loop.start = a->dc_loop.end = a->dc_loop.count = 0;
			}
			break;
		default:
			break;
		}
		break;
	case (AL_FILTER_RESET):
		a->dc_lastsam = 0;
		a->dc_first   = 1;
		a->dc_sample = 0;

		/* sct 2/14/96 - Check table since it is initialized to null and */
		/* Get loop info according to table type. */
		if (a->dc_table) {
			a->dc_memin  = a->dc_table->base;

			if (a->dc_table->type == AL_ADPCM_WAVE) {
				if (a->dc_table->waveInfo.adpcmWave.loop) {
					a->dc_loop.count = a->dc_table->waveInfo.adpcmWave.loop->count;
				}
			} else if (a->dc_table->type == AL_RAW16_WAVE) {
				if (a->dc_table->waveInfo.rawWave.loop) {
					a->dc_loop.count = a->dc_table->waveInfo.rawWave.loop->count;
				}
			}
		}
        break;
	default:
		break;
	}
}

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

