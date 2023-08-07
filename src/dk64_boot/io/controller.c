#include <ultra64.h>
#include "functions.h"
#include <ultra64.h>
#include <rcp.h>
#include "controller.h"
#include "siint.h"

#define HALF_A_SECOND OS_USEC_TO_CYCLES(500000)

extern u32 D_dk64_boot_800100D0; // __osContinitialized
extern OSPifRam D_dk64_boot_80014DC0; // __osContPifRam
extern u8 D_dk64_boot_80014E01; // __osMaxControllers
extern OSMesgQueue D_dk64_boot_80014E28; // __osEepromTimerQ
extern OSMesg D_dk64_boot_80014E40; // __osEepromTimerMsg

s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *data)
{
    OSMesg dummy;
    s32 ret;
    OSTime t;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;

    ret = 0;
    if (D_dk64_boot_800100D0)
        return ret;
    D_dk64_boot_800100D0 = TRUE;
    t = osGetTime();
    if (t < HALF_A_SECOND)
    {
        osCreateMesgQueue(&timerMesgQueue, &dummy, 1);
        osSetTimer(&mytimer, HALF_A_SECOND - t, 0, &timerMesgQueue, &dummy);
        osRecvMesg(&timerMesgQueue, &dummy, OS_MESG_BLOCK);
    }
    D_dk64_boot_80014E01 = MAXCONTROLLERS;
    __osPackRequestData(CONT_CMD_REQUEST_STATUS);

    ret = __osSiRawStartDma(OS_WRITE, &D_dk64_boot_80014DC0);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);

    ret = __osSiRawStartDma(OS_READ, &D_dk64_boot_80014DC0);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);
    __osContGetInitData(bitpattern, data);
    __osContLastCmd = CONT_CMD_REQUEST_STATUS;
    __osSiCreateAccessQueue();
    osCreateMesgQueue(&D_dk64_boot_80014E28, &D_dk64_boot_80014E40, 1);
    return ret;
}

void __osContGetInitData(u8 *pattern, OSContStatus *data)
{
    u8 *ptr;
    __OSContRequesFormat requestformat;
    int i;
    u8 bits;
    bits = 0;
    ptr = (u8 *)&D_dk64_boot_80014DC0;
    for (i = 0; i < D_dk64_boot_80014E01; i++, ptr += sizeof(__OSContRequesFormat), data++)
    {
        requestformat = *(__OSContRequesFormat *)ptr;
        data->errno = CHNL_ERR(requestformat);
        if (data->errno == 0)
        {
            data->type = (requestformat.typel << 8) | requestformat.typeh;
            data->status = requestformat.status;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}

void __osPackRequestData(u8 cmd)
{
    u8 *ptr;
    __OSContRequesFormat requestformat;
    int i;
    for (i = 0; i < ARRLEN(D_dk64_boot_80014DC0.ramarray); i++)
    {
        D_dk64_boot_80014DC0.ramarray[i] = 0;
    }
    D_dk64_boot_80014DC0.pifstatus = CONT_CMD_EXE;
    ptr = (u8 *)&D_dk64_boot_80014DC0.ramarray;
    requestformat.dummy = CONT_CMD_NOP;
    requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
    requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
    requestformat.cmd = cmd;
    requestformat.typeh = CONT_CMD_NOP;
    requestformat.typel = CONT_CMD_NOP;
    requestformat.status = CONT_CMD_NOP;
    requestformat.dummy1 = CONT_CMD_NOP;

    for (i = 0; i < D_dk64_boot_80014E01; i++)
    {
        *(__OSContRequesFormat *)ptr = requestformat;
        ptr += sizeof(__OSContRequesFormat);
    }
    ptr[0] = CONT_CMD_END;
}
