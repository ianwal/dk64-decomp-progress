#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_800010C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_80001700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_80001AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_80001C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_80001DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_800022D4.s")

s32 func_80001AF4(void);
s32 func_80001C48(void);
s32 func_80001DB0(void);
extern u32 D_80013AB4;
extern s32 D_80013AB8;
extern u8 *D_80013AC0;
extern s32 D_80013AEC;

/*
// TODO: Regalloc v0/v1/t9
s32 func_800022D4(s32 *arg0) {
    s32 var_v1;
    u32 var_a1;

    var_a1 = D_80013AB4;
    var_v1 = D_80013AB8;
    while (var_v1 == 0) {
        var_a1 |= D_80013AC0[D_80013AEC++] << var_v1;
        var_v1 += 8;
    }
    var_v1--;
    *arg0 = var_a1 & 1;
    var_a1 = var_a1 >> 1;
    while (var_v1 < 2U) {
        var_a1 |= D_80013AC0[D_80013AEC++] << var_v1;
        var_v1 += 8;
    }
    // TODO: Problem is here
    var_v1 = var_a1 & 3;
    D_80013AB4 = var_a1 >> 2;
    D_80013AB8 = var_v1 - 2;
    if (var_v1 == 2) {
        return func_80001DB0();
    } else if (var_v1 == 0) {
        return func_80001AF4();
    } else if (var_v1 == 1) {
        return func_80001C48();
    } else {
        return 2;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1CC0/func_800023F4.s")
