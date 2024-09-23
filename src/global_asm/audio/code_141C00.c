#include <ultra64.h>
#include "functions.h"
#include "synthinternal.h"

ALParam *__n_allocParam();
s32 func_global_asm_8073F1E4(Struct8073F1E4 *, s32, ALParam *);

void func_global_asm_8073CF00(Struct8073F1E4_container *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->unk8 != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + arg0->unk8->unk88;
        sp1C->type = 0xC;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->unk8, 3, sp1C);
    }
}

void func_global_asm_8073CFB0(Struct8073F1E4_container *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->unk8 != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + arg0->unk8->unk88;
        sp1C->type = 0x11;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->unk8, 3, sp1C);
    }
}

s32 func_global_asm_8073D060(ALCSeq *arg0, u32 *arg1) {
    u32 spC;
    u32 sp8;
    s32 sp4;

    sp8 = -1U;
    sp4 = arg0->lastDeltaTicks;
    if (arg0->validTracks == 0) {
        return 0;
    }
    for (spC = 0; spC < 0x10; spC++) {
        if (((u32) arg0->validTracks >> spC) & 1) {
            if (arg0->deltaFlag != 0) {
                arg0->evtDeltaTicks[spC] -= sp4;
            }
            if ((u32) arg0->evtDeltaTicks[spC] < sp8) {
                sp8 = arg0->evtDeltaTicks[spC];
            }
        }
    }
    arg0->deltaFlag = 0;
    *arg1 = sp8;
    return 1;
}