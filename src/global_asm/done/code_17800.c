#include <ultra64.h>
#include "functions.h"

extern f32 D_global_asm_80757310;
extern f32 D_global_asm_80757314;
extern f32 D_global_asm_80757318;

f32 func_global_asm_80612B00(f32 arg0, s16 arg1) {
    f32 var_f2;
    s16 i;

    var_f2 = 1.0f;
    if (arg1) {
        for (i = 0; i < arg1; i++) {
            var_f2 *= arg0;
        }
    }
    return var_f2;
}

f32 func_global_asm_80612B48(s16 arg0) {
    s16 i = 0;
    while (arg0) {
        arg0 /= 10;
        i++;
    }
    return i - 1;
}

void func_global_asm_80612BC0(f32 (*arg0)[4], f32 arg1) {
    f32 sp24;
    f32 sp20;

    arg1 *= D_global_asm_80757310;
    sp24 = func_global_asm_80612D1C(arg1);
    sp20 = func_global_asm_80612D10(arg1);
    guMtxIdentF(arg0);
    arg0[1][2] = sp24;
    arg0[2][1] = -sp24;
    arg0[1][1] = sp20;
    arg0[2][2] = sp20;
}

void func_global_asm_80612C30(f32 (*arg0)[4], f32 arg1) {
    f32 sp24;
    f32 sp20;

    arg1 *= D_global_asm_80757314;
    sp24 = func_global_asm_80612D1C(arg1);
    sp20 = func_global_asm_80612D10(arg1);
    guMtxIdentF(arg0);
    arg0[2][0] = sp24;
    arg0[0][2] = -sp24;
    arg0[0][0] = sp20;
    arg0[2][2] = sp20;
}

void func_global_asm_80612CA0(f32 (*arg0)[4], f32 arg1) {
    f32 sp24;
    f32 sp20;

    arg1 *= D_global_asm_80757318;
    sp24 = func_global_asm_80612D1C(arg1);
    sp20 = func_global_asm_80612D10(arg1);
    guMtxIdentF(arg0);
    arg0[0][1] = sp24;
    arg0[1][0] = -sp24;
    arg0[0][0] = sp20;
    arg0[1][1] = sp20;
}
