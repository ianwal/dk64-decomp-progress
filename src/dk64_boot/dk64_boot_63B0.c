#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ull_rshift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ull_rem.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ull_div.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ll_lshift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ll_rem.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ll_div.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ll_mul.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ull_divremi.s")

/*
void __ull_divremi(u64 *arg0, u64 *arg1, u64 arg2, s16 arg4) {
    *arg0 = arg2 / arg4;
    *arg1 = arg2 % arg4;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ll_mod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_63B0/__ll_rshift.s")

extern s32 D_dk64_boot_800100F4;

s32 func_dk64_boot_80005A70(void) {
    return D_dk64_boot_800100F4;
}
