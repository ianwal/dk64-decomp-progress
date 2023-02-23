#include <os_internal.h>
#include <rcp.h>
#include "piint.h"

#define UPDATE_REG(reg, var)           \
    if (cHandle->var != pihandle->var) \
        IO_WRITE(reg, pihandle->var);

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/epirawread/osEPiRawReadIo.s")
#else
s32 osEPiRawReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data)
{
    register u32 stat;
    register u32 domain;

    EPI_SYNC(pihandle,stat,domain);
    
    *data = IO_READ(pihandle->baseAddress | devAddr);
    return 0;
}
#endif