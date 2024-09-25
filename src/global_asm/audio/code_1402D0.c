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