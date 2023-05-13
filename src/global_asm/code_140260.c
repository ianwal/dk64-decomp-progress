#include <ultra64.h>
#include "functions.h"

void func_8073B560(ALPlayer *arg0) {
    OSIntMask sp1C;

    sp1C = osSetIntMask(1);
    arg0->samplesLeft = n_syn->curSamples;
    arg0->next = n_syn->head;
    n_syn->head = arg0;
    osSetIntMask(sp1C);
}

void func_8073B5D0(ALPlayer *arg0) {
    OSIntMask sp1C;

    sp1C = osSetIntMask(1);
    arg0->samplesLeft = n_syn->curSamples;
    arg0->next = n_syn->head;
    n_syn->head = arg0;
    osSetIntMask(sp1C);
}

void func_8073B640(ALPlayer *arg0) {
    OSIntMask sp1C;

    sp1C = osSetIntMask(1);
    arg0->samplesLeft = n_syn->curSamples;
    arg0->next = n_syn->head;
    n_syn->head = arg0;
    osSetIntMask(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_140260/func_8073B6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_140260/func_8073B750.s")
