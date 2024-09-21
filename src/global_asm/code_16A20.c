#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_16A20/func_global_asm_80611D20.s")

s32 func_global_asm_80611D20(s32);

u16 func_global_asm_80611DA0(s16 arg0) {
    s32 temp_a1;

    temp_a1 = arg0 >= 0 ? arg0 : -arg0;
    temp_a1 = func_global_asm_80611D20(temp_a1);
    if (arg0 < 0) {
        temp_a1 = 0xFFFF - temp_a1;
    }
    return temp_a1;
}

s16 func_global_asm_80611DF4(s16 arg0) {
    s32 temp_a1;
    s16 var_a0;

    temp_a1 = arg0 >= 0 ? arg0 : -arg0;
    temp_a1 = func_global_asm_80611D20(temp_a1);
    if (arg0 >= 0) {
        temp_a1 = 0x7FFF - temp_a1;
    } else {
        temp_a1 = temp_a1 - 0x8000;
    }
    return temp_a1;
}
