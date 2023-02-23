#include <os_internal.h>
#include <rcp.h>
#include "viint.h"
#include "osint.h"

OSDevMgr __osViDevMgr = {0};
u32 D_8000EF1C = 0;


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/vimgr/osCreateViManager.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/vimgr/viMgrMain.s")
