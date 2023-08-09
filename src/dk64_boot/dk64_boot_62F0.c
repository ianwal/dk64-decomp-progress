#include <ultra64.h>
#include "functions.h"
#include "viint.h"

void func_dk64_boot_800056F0(OSMesgQueue *arg0, OSMesg arg1, s32 arg2) {
    register s32 temp_v0;

    temp_v0 = __osDisableInt();
    __osViNext->msgq = arg0;
    __osViNext->msg = arg1;
    __osViNext->retraceCount = arg2;
    __osRestoreInt(temp_v0);
}
