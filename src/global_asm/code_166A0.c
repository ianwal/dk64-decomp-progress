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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_166A0/func_global_asm_80611A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_166A0/func_global_asm_80611BB4.s")
