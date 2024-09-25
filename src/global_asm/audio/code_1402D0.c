#include <ultra64.h>
#include "functions.h"

void func_global_asm_8073B5D0(ALPlayer *arg0) {
    OSIntMask sp1C;

    sp1C = osSetIntMask(OS_IM_NONE);
    arg0->samplesLeft = n_syn->curSamples;
    arg0->next = n_syn->head;
    n_syn->head = arg0;
    osSetIntMask(sp1C);
}

void func_global_asm_8073B640(ALPlayer *arg0) {
    OSIntMask sp1C;

    sp1C = osSetIntMask(OS_IM_NONE);
    arg0->samplesLeft = n_syn->curSamples;
    arg0->next = n_syn->head;
    n_syn->head = arg0;
    osSetIntMask(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1402D0/func_global_asm_8073B6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_1402D0/func_global_asm_8073B750.s")
