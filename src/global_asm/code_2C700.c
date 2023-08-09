#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C700/func_global_asm_80627A00.s")

extern float D_global_asm_807F5D30[4][4];

/*
// Hmm...
f32 func_global_asm_80627A00(f64 arg0, f32 arg1, f32 arg3, f32 arg4, f32 arg5) {
    return ((((arg0 * arg0) * arg0) * ((D_global_asm_807F5D30[3][0] * arg5) + ((D_global_asm_807F5D30[0][0] * arg1) + (D_global_asm_807F5D30[1][0] * arg3) + (D_global_asm_807F5D30[2][0] * arg4)))) + ((arg0 * arg0) * ((D_global_asm_807F5D30[3][1] * arg5) + ((D_global_asm_807F5D30[0][1] * arg1) + (D_global_asm_807F5D30[1][1] * arg3) + (D_global_asm_807F5D30[2][1] * arg4))))) + ((arg0 * ((D_global_asm_807F5D30[3][2] * arg5) + ((D_global_asm_807F5D30[0][2] * arg1) + (D_global_asm_807F5D30[1][2] * arg3) + (D_global_asm_807F5D30[2][2] * arg4)))) + (D_global_asm_807F5D30[3][3] * arg5) + ((D_global_asm_807F5D30[0][3] * arg1) + (D_global_asm_807F5D30[1][3] * arg3) + (D_global_asm_807F5D30[2][3] * arg4)));
}
*/

void func_global_asm_80627B58(f32 arg0) {
    D_global_asm_807F5D30[0][0] = -arg0;
    D_global_asm_807F5D30[0][1] = 2.0 * arg0;
    D_global_asm_807F5D30[0][2] = -arg0;
    D_global_asm_807F5D30[0][3] = 0.0f;
    D_global_asm_807F5D30[1][0] = 2.0 - arg0;
    D_global_asm_807F5D30[1][1] = arg0 - 3.0;
    D_global_asm_807F5D30[1][2] = 0.0f;
    D_global_asm_807F5D30[1][3] = 1.0f;
    D_global_asm_807F5D30[2][0] = arg0 - 2.0;
    D_global_asm_807F5D30[2][1] = 3.0 - (2.0 * arg0);
    D_global_asm_807F5D30[2][2] = arg0;
    D_global_asm_807F5D30[2][3] = 0.0f;
    D_global_asm_807F5D30[3][0] = arg0;
    D_global_asm_807F5D30[3][1] = -arg0;
    D_global_asm_807F5D30[3][2] = 0.0f;
    D_global_asm_807F5D30[3][3] = 0.0f;
}
