#include <ultra64.h>
#include "functions.h"

void func_80738400(ALSeqPlayer *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    ALEvent sp18;

    sp18.type = 0x19;
    sp18.msg.evt19.unk00 = arg1;
    sp18.msg.evt19.unk01 = arg2;
    sp18.msg.evt19.unk02 = arg3;
    sp18.msg.evt19.param = arg4;
    alEvtqPostEvent(&arg0->evtq, &sp18, 0);
}
