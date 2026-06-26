#include "common.h"

static u16 D_global_asm_80746A50[] = {
    0x8000,
    0x7EBA,
    0x7D74,
    0x7C2D,
    0x7AE7,
    0x79A0,
    0x7859,
    0x7711,
    0x75C9,
    0x7480,
    0x7337,
    0x71EC,
    0x70A1,
    0x6F55,
    0x6E07,
    0x6CB8,
    0x6B68,
    0x6A17,
    0x68C4,
    0x6770,
    0x661A,
    0x64C1,
    0x6367,
    0x620B,
    0x60AD,
    0x5F4C,
    0x5DE9,
    0x5C83,
    0x5B1A,
    0x59AE,
    0x583E,
    0x56CB,
    0x5555,
    0x53DB,
    0x525C,
    0x50D9,
    0x4F51,
    0x4DC5,
    0x4C32,
    0x4A9A,
    0x48FC,
    0x4757,
    0x45AB,
    0x43F7,
    0x423A,
    0x4075,
    0x3EA5,
    0x3CCB,
    0x3AE5,
    0x38F1,
    0x36EF,
    0x34DC,
    0x32B7,
    0x307D,
    0x2E2B,
    0x2BBD,
    0x292E,
    0x2678,
    0x2391,
    0x206C,
    0x1CF6,
    0x0000,
};

static u16 D_global_asm_80746ACC[] = {
    0x1CF6,
    0x1CBB,
    0x1C80,
    0x1C45,
    0x1C08,
    0x1BCC,
    0x1B8F,
    0x1B51,
    0x1B13,
    0x1AD4,
    0x1A95,
    0x1A55,
    0x1A14,
    0x19D3,
    0x1992,
    0x194F,
    0x190C,
    0x18C9,
    0x1884,
    0x183F,
    0x17F9,
    0x17B3,
    0x176B,
    0x1723,
    0x16DA,
    0x1690,
    0x1645,
    0x15F9,
    0x15AC,
    0x155E,
    0x150F,
    0x14BE,
    0x146D,
    0x141A,
    0x13C6,
    0x1370,
    0x1319,
    0x12C1,
    0x1267,
    0x120B,
    0x11AD,
    0x114E,
    0x10EC,
    0x1088,
    0x1022,
    0x0FB9,
    0x0F4D,
    0x0EDE,
    0x0E6C,
    0x0DF7,
    0x0D7D,
    0x0D00,
    0x0C7D,
    0x0BF4,
    0x0B66,
    0x0AD0,
    0x0A31,
    0x0989,
    0x08D3,
    0x080E,
    0x0734,
    0x063D,
    0x0518,
    0x039A,
};

static u16 D_global_asm_80746B4C[] = {
    0x039A,
    0x031E,
    0x028C,
    0x01CD,
};

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
