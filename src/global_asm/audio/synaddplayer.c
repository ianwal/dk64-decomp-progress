#include "common.h"

void func_global_asm_8073B560(ALPlayer *client) {
    OSIntMask sp1C;

    sp1C = osSetIntMask(OS_IM_NONE);
    client->samplesLeft = n_syn->curSamples;
    client->next = n_syn->head;
    n_syn->head = client;
    osSetIntMask(sp1C);
}

