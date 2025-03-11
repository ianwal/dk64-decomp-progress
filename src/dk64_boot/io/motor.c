#include <ultra64.h>
#include "controller.h"
#include "siint.h"
#include "macros.h"

extern u8 __osContLastCmd;
static OSPifRam __MotorDataBuf[MAXCONTROLLERS] ALIGNED(8);

#define READFORMAT(ptr) ((__OSContRamReadFormat*)(ptr))

s32 __osMotorAccess(OSPfs* pfs, s32 flag) {
    int i;
    s32 ret;
    u8* ptr = (u8*)&__MotorDataBuf[pfs->channel];

    if (!(pfs->status & PFS_MOTOR_INITIALIZED)) {
        return 5;
    }

    __osSiGetAccess();
    __MotorDataBuf[pfs->channel].pifstatus = CONT_CMD_EXE;
    ptr += pfs->channel;

    for (i = 0; i < BLOCKSIZE; i++) {
        READFORMAT(ptr)->data[i] = flag;
    }

    __osContLastCmd = CONT_CMD_END;
    __osSiRawStartDma(OS_WRITE, &__MotorDataBuf[pfs->channel]);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__MotorDataBuf[pfs->channel]);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);

    ret = READFORMAT(ptr)->rxsize & CHNL_ERR_MASK;
    if (!ret) {
        if (!flag) {
            if (READFORMAT(ptr)->datacrc != 0) {
                ret = PFS_ERR_CONTRFAIL;
            }
        } else {
            if (READFORMAT(ptr)->datacrc != 0xEB) {
                ret = PFS_ERR_CONTRFAIL;
            }
        }
    }

    __osSiRelAccess();

    return ret;
}

static void _MakeMotorData(int channel, OSPifRam *mdata)
{
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int i;

    ramreadformat.dummy = CONT_CMD_NOP;
    ramreadformat.txsize = CONT_CMD_WRITE_PAK_TX;
    ramreadformat.rxsize = CONT_CMD_WRITE_PAK_RX;
    ramreadformat.cmd = CONT_CMD_WRITE_PAK;
    ramreadformat.addrh = 0x600 >> 3;
    
    ptr = (u8 *)mdata->ramarray;
    ramreadformat.addrl = (0x600 << 5) | __osContAddressCrc(0x600);
    
    if (channel != 0)
    {
        for (i = 0; i < channel; i++)
        {
            *ptr++ = 0;
        }
    }
    *(__OSContRamReadFormat *)ptr = ramreadformat;
    ptr += sizeof(__OSContRamReadFormat);
    ptr[0] = CONT_CMD_END;
}

s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel)
{
    s32 ret;
    u8 temp[32];
    pfs->queue = mq;
    pfs->channel = channel;
    pfs->activebank = 0xff;
    pfs->status = 0;

    ret = __osPfsSelectBank(pfs, 254);
    if (ret == 2) //TODO: remove magic constant
        ret = __osPfsSelectBank(pfs, 128);
    if (ret != 0)
        return ret;

    ret = __osContRamRead(mq, channel, 1024, temp); // ret = __osContRamRead(mq, channel, 1024, temp);
    if (ret == 2)
        ret = PFS_ERR_CONTRFAIL; //is this right?
    if (ret != 0)
        return ret;
    if (temp[31] == 254)
        return PFS_ERR_DEVICE;

    ret = __osPfsSelectBank(pfs, 128);
    if (ret == 2) //TODO: remove magic constant
        ret = PFS_ERR_CONTRFAIL;
    if (ret != 0)
        return ret;

    ret = __osContRamRead(mq, channel, 1024, temp); // ret = __osContRamRead(mq, channel, 1024, temp);
    if (ret == 2)
        ret = PFS_ERR_CONTRFAIL;
    if (ret != 0)
        return ret;
    if (temp[31] != 128)
        return PFS_ERR_DEVICE;

    if (!(pfs->status & 0x8)) {
        _MakeMotorData(channel, &__MotorDataBuf[channel]);
    }
    pfs->status = 0x8;
    return 0;
}
