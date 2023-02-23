#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 __osContLastCmd;
extern s32 *D_80014DC0;

s32 func_800073D0(OSMesgQueue *arg0) {
    s32 temp_v0;

    __osSiGetAccess();
    if (__osContLastCmd != 1) {
        func_800074E0();
        __osSiRawStartDma(1, &D_80014DC0);
        osRecvMesg(arg0, NULL, 1);
    }
    temp_v0 = __osSiRawStartDma(0, &D_80014DC0);
    __osContLastCmd = 1;
    __osSiRelAccess();
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_7FD0/func_80007454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_7FD0/func_800074E0.s")
