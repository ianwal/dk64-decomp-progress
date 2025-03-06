#include "common.h"
#include "controller.h"

void __osSiGetAccess();
s32 __osSiRawStartDma(s32, void *);
void __osSiRelAccess(void);
extern OSPifRam __osEepPifRam;
void __osPackEepReadData(u8);

s32 osEepromRead(OSMesgQueue *mq, u8 address, u8 *buffer) {
    s32 ret;
    s32 i;
    u16 type;
    u8 *ptr;
    OSContStatus sdata;
    __OSContEepromFormat eepromformat;

    ret = 0;
    i = 0;
    ptr = (u8*)&__osEepPifRam;
    __osSiGetAccess();
    ret = __osEepStatus(mq, &sdata);
    if (!ret) {
        type = sdata.type & (CONT_EEPROM | CONT_EEP16K);
        switch (type) {
            case CONT_EEPROM:
                if (address >= EEPROM_MAXBLOCKS) {
                    ret = -1;
                }
                break;
            case CONT_EEPROM | CONT_EEP16K:
                if (address >= EEP16K_MAXBLOCKS) {
                    ret = -1;
                }
                break;
            default:
                ret = 8;
        }
    }
    if (ret) {
        __osSiRelAccess();
        return ret;
    }
    while (sdata.status & CONT_EEPROM_BUSY) {
        __osEepStatus(mq, &sdata);
    }
    __osPackEepReadData(address);
    __osSiRawStartDma(1, &__osEepPifRam);
    osRecvMesg(mq, NULL, 1);
    __osSiRawStartDma(0, &__osEepPifRam);
    __osContLastCmd = 4;
    osRecvMesg(mq, NULL, 1);

    for (i = 0; i < MAXCONTROLLERS; i++) {
        ptr++;
    }
    eepromformat = *(__OSContEepromFormat *)ptr;
    ret = CHNL_ERR(eepromformat);

    if (ret == 0) {
        for (i = 0; i < ARRLEN(eepromformat.data); i++) {
            *buffer++ = eepromformat.data[i];
        }
    }
    __osSiRelAccess();
    return ret;
}

void __osPackEepReadData(u8 address) {
    u8 *ptr;
    __OSContEepromFormat eepromformat;
    s32 i;

    ptr = &__osEepPifRam.ramarray;
    __osEepPifRam.pifstatus = CONT_CMD_EXE;
    eepromformat.txsize = CONT_CMD_READ_EEPROM_TX;
    eepromformat.rxsize = CONT_CMD_READ_EEPROM_RX;
    eepromformat.cmd = CONT_CMD_READ_EEPROM;
    eepromformat.address = address;
    for (i = 0; i < 4; i++) {
        *ptr++ = 0;
    }
    *(__OSContEepromFormat *)(ptr) = eepromformat;
    ptr += sizeof(__OSContEepromFormat);
    ptr[0] = CONT_CMD_END;
}
