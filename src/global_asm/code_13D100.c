#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x48 - 0x0];
    ALEventQueue unk48;
} Struct80738320;

void func_80738400(Struct80738320 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    ALEvent sp18;

    sp18.type = 0x19;
    sp18.msg.evt19.unk00 = arg1;
    sp18.msg.evt19.unk01 = arg2;
    sp18.msg.evt19.unk02 = arg3;
    sp18.msg.evt19.param = arg4;
    alEvtqPostEvent(&arg0->unk48, &sp18, 0);
}
