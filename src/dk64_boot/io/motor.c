#include <ultra64.h>
#include "controller.h"
#include "siint.h"

extern u8 __osContLastCmd;
extern OSPifRam D_80014E50[];

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/motor/osMotorStartStop.s")
#else
s32 osMotorStartStop(OSPfs *pfs, int arg1)
{

    int i;
    s32 ret;
    u8 *ptr;
    __OSContRamReadFormat *ramreadformat;

    ramreadformat = (__OSContRamReadFormat *) D_80014E50[pfs->channel].ramarray;

    if (!(pfs->status & 0x8))
        return PFS_ERR_INVALID;

    __osSiGetAccess();
    D_80014E50[pfs->channel].pifstatus = 1;

    for (i = 0; i < 0x20; i++)
        ramreadformat->data[i] = arg1;

    __osContLastCmd = CONT_CMD_END;
    __osSiRawStartDma(OS_WRITE, D_80014E50[pfs->channel].ramarray);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    __osSiRawStartDma(OS_READ, D_80014E50[pfs->channel].ramarray);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    ret = ramreadformat->rxsize & CHNL_ERR_MASK;
    if (ret == 0) {
        if (!arg1) {
            if (ramreadformat->datacrc != 0)
                ret = PFS_ERR_CONTRFAIL;
        } else {
            if (ramreadformat->datacrc != 0xEB)
                ret = PFS_ERR_CONTRFAIL;
        }
    }
    __osSiRelAccess();
    return ret;
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/motor/_MakeMotorData.s")
#else
static void _MakeMotorData(int channel, OSPifRam *mdata)
{
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int i;

    ramreadformat.dummy = CONT_CMD_NOP;
    ramreadformat.txsize = CONT_CMD_WRITE_MEMPACK_TX;
    ramreadformat.rxsize = CONT_CMD_WRITE_MEMPACK_RX;
    ramreadformat.cmd = CONT_CMD_WRITE_MEMPACK;
    ramreadformat.unk4 = 0x600 >> 3;
    
    ptr = (u8 *)mdata->ramarray;
    ramreadformat.unk5 = (0x600 << 5) | __osContAddressCrc(0x600);
    
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
#endif

s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel)
{
    s32 ret;
    u8 temp[32];
    pfs->queue = mq;
    pfs->channel = channel;
    pfs->activebank = 0xff;
    pfs->status = 0;

    ret = __osPackRamWriteDataSafe(pfs, 254);
    if (ret == 2) //TODO: remove magic constant
        ret = __osPackRamWriteDataSafe(pfs, 128);
    if (ret != 0)
        return ret;

    ret = __osContRamReadData(mq, channel, 1024, temp); // ret = __osContRamRead(mq, channel, 1024, temp);
    if (ret == 2)
        ret = PFS_ERR_CONTRFAIL; //is this right?
    if (ret != 0)
        return ret;
    if (temp[31] == 254)
        return PFS_ERR_DEVICE;

    ret = __osPackRamWriteDataSafe(pfs, 128);
    if (ret == 2) //TODO: remove magic constant
        ret = PFS_ERR_CONTRFAIL;
    if (ret != 0)
        return ret;

    ret = __osContRamReadData(mq, channel, 1024, temp); // ret = __osContRamRead(mq, channel, 1024, temp);
    if (ret == 2)
        ret = PFS_ERR_CONTRFAIL;
    if (ret != 0)
        return ret;
    if (temp[31] != 128)
        return PFS_ERR_DEVICE;

    if (!(pfs->status & 0x8)) {
        _MakeMotorData(channel, &D_80014E50[channel]);
    }
    pfs->status = 0x8;
    return 0;
}