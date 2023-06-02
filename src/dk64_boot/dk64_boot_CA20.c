#include <ultra64.h>
#include "functions.h"

#include <os_internal.h>
#include <rcp.h>
#include "piint.h"

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_CA20/osEPiRawStartDma.s")

/*
// TODO: I think we need the 2.0I version of EPI_SYNC
s32 osEPiRawStartDma(OSPiHandle *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    u32 stat;
    u32 domain;

    EPI_SYNC(pihandle, stat, domain);
    
    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS(pihandle->baseAddress | devAddr));
    switch (direction)
    {
    case OS_READ:
        IO_WRITE(PI_WR_LEN_REG, size - 1);
        break;
    case OS_WRITE:
        IO_WRITE(PI_RD_LEN_REG, size - 1);
        break;
    default:
        return -1;
    }
    return 0;
}
*/
