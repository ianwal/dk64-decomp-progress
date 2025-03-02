#include <ultra64.h>
#include "controller.h"

u16 __osSumcalc(u8 *ptr, int length)
{
    int i;
    u32 sum;
    u8 *tmp;

    sum = 0;
    tmp = ptr;
    for (i = 0; i < length; i++)
    {
        sum += *tmp++;
    }
    return sum & 0xffff;
}

#ifndef NONMATHCING
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/contpfs/__osIdCheckSum.s")
#else
s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum)
{
    u16 data;
    u32 j;
    data = 0;
    *icsum = 0;
    *csum = *icsum;
    for (j = 0; j < 28; j += 2)
    {
        //feels like this should be a compiler optimization not manual..
        //but it doesn't match and I'm pretty sure this is just -O1
        /* ^comment copies from libreultra, I'm pretty positive this file is NOT -O1 for DK64*/
        data = *(u16 *)((u8 *)ptr + j);
        //data = ptr[j];
        *csum += data;
        *icsum += ~data;
    }
    return 0;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/contpfs/__osRepairPackId.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/contpfs/__osCheckPackId.s")

// Nope
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/contpfs/__osGetId.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/contpfs/__osCheckId.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/io/contpfs/__osPfsRWInode.s")
