#include <ultra64.h>
#include "functions.h"

extern u16 D_global_asm_80746A50[];
extern u16 D_global_asm_80746ACC[];
extern u16 D_global_asm_80746B4C[];

s32 func_global_asm_80611D20(s32 arg0) {
    u16 *var_a2;
    s32 var_a1;
    s32 var_v1;
    s32 i;
    s32 temp;
    s32 temp2;
    s32 temp3;
    s32 temp4;

    if (arg0 >= 0x7FE0) {
        var_v1 = 7;
        var_a1 = 3;
        var_a2 = &D_global_asm_80746B4C;
        arg0 -= 0x7FE0;
    } else if (arg0 >= 0x7800) {
        var_v1 = 0x1F;
        var_a1 = 5;
        var_a2 = &D_global_asm_80746ACC;
        arg0 -= 0x7800;
    } else {
        var_v1 = 0x1FF;
        var_a1 = 9;
        var_a2 = &D_global_asm_80746A50;
    }
    i = arg0 >> var_a1;
    temp = var_a2[i];
    temp4 = var_a2[i + 1];
    temp2 = temp - temp4;
    temp3 = arg0 & var_v1;
    return temp - ((temp2 * temp3) >> var_a1);
}

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
