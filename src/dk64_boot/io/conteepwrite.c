#include <os_internal.h>
#include "controller.h"
#include "siint.h"
#include <rcp.h>

void __osPackEepWriteData(u8 address, u8 *buffer);

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/conteepwrite/osEepromWrite.s")
#else
s32 osEepromWrite(OSMesgQueue *mq, u8 address, u8 *buffer)
{

    s32 ret;
    int i;
    u32 type;
    u8 *ptr;
    __OSContEepromFormat eepromformat;
    OSContStatus sdata;
 
    ret = 0;
    __osSiGetAccess();
    ret = __osEepStatus(mq, &sdata);

    if (!ret) {
        type = sdata.type & (CONT_EEPROM | CONT_EEP16K);
        switch (type) {
            default:
                ret = CONT_NO_RESPONSE_ERROR;
                break;
            case CONT_EEPROM://L800079B0
                if (address >= EEPROM_MAXBLOCKS)
                    ret = -1;
                break;
            case CONT_EEPROM | CONT_EEP16K://L800079C4
                if (address >= EEP16K_MAXBLOCKS)
                    ret = -1;
                break;
        }
    }
    if (ret) {
        __osSiRelAccess();
        return ret;
    }
   
    while (sdata.status & CONT_EEPROM_BUSY)
    {
        __osEepStatus(mq, &sdata);
    }
    __osPackEepWriteData(address, buffer);
    __osSiRawStartDma(OS_WRITE, &__osEepPifRam); //send command to pif
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    __osSiRawStartDma(OS_READ, &__osEepPifRam); //recv response
    __osContLastCmd = CONT_CMD_WRITE_EEPROM;
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    ptr = (u8*)__osEepPifRam.ramarray + 4;
    eepromformat = *(__OSContEepromFormat *)ptr;

    //probably indicates an error, from PIF
    ret = CHNL_ERR(eepromformat); //TODO: remove magic constants

    __osSiRelAccess();
    return ret;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/conteepwrite/__osPackEepWriteData.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/conteepwrite/__osEepStatus.s")
