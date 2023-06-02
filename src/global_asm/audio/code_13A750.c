#include <ultra64.h>
#include "functions.h"

void func_80735A50(ALSeqPlayer *arg0, s32 arg1) {
    s32 pad[2];
    s32 sp1C;
    s16 sp1A;
    s16 sp18; // TODO: ALEvent

    sp18 = 0xE;
    sp1C = arg1;
    alEvtqPostEvent(&arg0->evtq, &sp18, 0);
}
