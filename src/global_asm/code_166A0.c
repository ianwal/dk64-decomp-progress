#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_166A0/func_global_asm_806119A0.s")

extern s32 D_global_asm_80746A40;

void func_global_asm_806119F0(s32 arg0) {
    D_global_asm_80746A40 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_166A0/func_global_asm_806119FC.s")

s32 rand(void) {
    return func_global_asm_806119A0() & 0x7FFFFFFF;
}

void func_global_asm_80611A70(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    if ((*arg2 - arg0 < 0.25) && (*arg2 - arg0 >= 0.0)) {
        *arg2 += 0.125;
    }
    if ((*arg3 - arg1 < 0.25) && (*arg3 - arg1 >= 0.0)) {
        *arg3 += 0.125;
    }
    if ((*arg2 - arg0 > -0.25) && (*arg2 - arg0 <= 0.0)) {
        *arg2 -= 0.125;
    }
    if ((*arg3 - arg1 > -0.25) && (*arg3 - arg1 <= 0.0)) {
        *arg3 -= 0.125;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_166A0/func_global_asm_80611BB4.s")
