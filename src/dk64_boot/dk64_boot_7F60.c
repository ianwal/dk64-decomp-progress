#include "common.h"
#include "controller.h"

void __osSiGetAccess(void);
void __osSiRelAccess(void);

extern u8 D_dk64_boot_80014E01;

s32 osContSetCh(u8 arg0) {
    s32 sp1C;

    sp1C = 0;
    __osSiGetAccess();
    if (arg0 >= 5) {
        D_dk64_boot_80014E01 = 4;
    } else {
        D_dk64_boot_80014E01 = arg0;
    }
    __osContLastCmd = 0xFE;
    __osSiRelAccess();
    return sp1C;
}
