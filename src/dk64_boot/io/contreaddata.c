#include <ultra64.h>
#include "functions.h"
#include "controller.h"

// contreaddata.c

extern OSPifRam D_80014DC0; // __osContPifRam
extern u8 D_80014E01; // __osMaxControllers

void func_dk64_boot_800074E0(void);

s32 func_dk64_boot_800073D0(OSMesgQueue *arg0) {
    s32 temp_v0;

    __osSiGetAccess();
    if (__osContLastCmd != CONT_CMD_READ_BUTTON) {
        func_dk64_boot_800074E0();
        __osSiRawStartDma(OS_WRITE, &D_80014DC0);
        osRecvMesg(arg0, NULL, OS_MESG_BLOCK);
    }
    temp_v0 = __osSiRawStartDma(OS_READ, &D_80014DC0);
    __osContLastCmd = CONT_CMD_READ_BUTTON;
    __osSiRelAccess();
    return temp_v0;
}

void func_dk64_boot_80007454(OSContPad *data) //void osContGetReadData(OSContPad *data)
{
    u8 *ptr;
    __OSContReadFormat readformat;
    int i;
    ptr = (u8 *)&D_80014DC0.ramarray;
    for (i = 0; i < D_80014E01; i++, ptr += sizeof(__OSContReadFormat), data++)
    {
        readformat = *(__OSContReadFormat *)ptr;
        data->errno = CHNL_ERR(readformat);
        if (data->errno == 0)
        {
            data->button = readformat.button;
            data->stick_x = readformat.stick_x;
            data->stick_y = readformat.stick_y;
        }
    }
}

void func_dk64_boot_800074E0(void) //static void __osPackReadData(void)
{
    u8 *ptr;
    __OSContReadFormat readformat;
    int i;

    ptr = (u8*)&D_80014DC0.ramarray;
    for (i = 0; i < ARRLEN(D_80014DC0.ramarray); i++)
    {
        D_80014DC0.ramarray[i] = 0;
    }
    D_80014DC0.pifstatus = CONT_CMD_EXE;
    readformat.dummy = CONT_CMD_NOP;
    readformat.txsize = CONT_CMD_READ_BUTTON_TX;
    readformat.rxsize = CONT_CMD_READ_BUTTON_RX;
    readformat.cmd = CONT_CMD_READ_BUTTON;
    readformat.button = -1;
    readformat.stick_x = -1;
    readformat.stick_y = -1;
    for(i = 0; i < D_80014E01; i++){
        *(__OSContReadFormat*)ptr = readformat;
        ptr += sizeof(__OSContReadFormat);
    }
    *ptr = CONT_CMD_END;
}
