#include <ultra64.h>
#include "functions.h"

void func_807382A0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    s32 sp2C;
    u8 sp2B;
    u8 sp2A;
    u8 sp29;
    u8 sp28;
    s32 sp24;
    s16 sp22;
    s16 sp20; // TODO: ALEvent
    s32 sp1C;

    sp20 = 2;
    sp24 = 0;
    sp28 = arg2;
    sp29 = arg3;
    sp2A = arg4;
    sp2C = 0;
    sp1C = arg1;
    alEvtqPostEvent(arg0 + 0x48, &sp20, sp1C);
}
