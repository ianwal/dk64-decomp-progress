#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C700/func_80627A00.s")

extern float D_807F5D30[4][4];

void func_80627B58(f32 arg0) {
    D_807F5D30[0][0] = -arg0;
    D_807F5D30[0][1] = 2.0 * arg0;
    D_807F5D30[0][2] = -arg0;
    D_807F5D30[0][3] = 0.0f;
    D_807F5D30[1][0] = 2.0 - arg0;
    D_807F5D30[1][1] = arg0 - 3.0;
    D_807F5D30[1][2] = 0.0f;
    D_807F5D30[1][3] = 1.0f;
    D_807F5D30[2][0] = arg0 - 2.0;
    D_807F5D30[2][1] = 3.0 - (2.0 * arg0);
    D_807F5D30[2][2] = arg0;
    D_807F5D30[2][3] = 0.0f;
    D_807F5D30[3][0] = arg0;
    D_807F5D30[3][1] = -arg0;
    D_807F5D30[3][2] = 0.0f;
    D_807F5D30[3][3] = 0.0f;
}
