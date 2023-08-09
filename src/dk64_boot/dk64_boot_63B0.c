#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_800057B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_800057DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_80005818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_80005854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_80005880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_800058BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_80005918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_80005948.s")

/*
void func_dk64_boot_80005948(u64 *arg0, u64 *arg1, u64 arg2, s16 arg4) {
    *arg0 = arg2 / arg4;
    *arg1 = arg2 % arg4;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_800059A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/func_dk64_boot_80005A44.s")

extern s32 D_dk64_boot_800100F4;

s32 func_dk64_boot_80005A70(void) {
    return D_dk64_boot_800100F4;
}
