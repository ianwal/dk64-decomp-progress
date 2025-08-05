#include "common.h"

// doable
// https://decomp.me/scratch/rlrrZ
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C700/func_global_asm_80627A00.s")

// spline basis matrix ?
extern float D_global_asm_807F5D30[4][4];

// Hmm...
// Kinda looks like [t^3, t^2, t, 1] * basis_matrix * [P0, P1, P2, P3]
/*
f32 func_global_asm_80627A00(f64 arg0, f32 arg1, f32 arg3, f32 arg4, f32 arg5) {
    f32 row1;
    f32 row2;
    f32 row3;
    f32 row4;

    row1 = (arg0 * arg0 * arg0) * ((D_global_asm_807F5D30[3][0] * arg5) +
                        (D_global_asm_807F5D30[0][0] * arg1) +
                        (D_global_asm_807F5D30[1][0] * arg3) +
                        (D_global_asm_807F5D30[2][0] * arg4));

    row2 = (arg0 * arg0) *( (D_global_asm_807F5D30[3][1] * arg5) +
                        (D_global_asm_807F5D30[0][1] * arg1) +
                        (D_global_asm_807F5D30[1][1] * arg3) +
                        (D_global_asm_807F5D30[2][1] * arg4));

    row3 = arg0 * ((D_global_asm_807F5D30[3][2] * arg5) +
                        (D_global_asm_807F5D30[0][2] * arg1) +
                        (D_global_asm_807F5D30[1][2] * arg3) +
                        (D_global_asm_807F5D30[2][2] * arg4));

    row4 = (D_global_asm_807F5D30[3][3] * arg5) +
                        (D_global_asm_807F5D30[0][3] * arg1) +
                        (D_global_asm_807F5D30[1][3] * arg3) +
                        (D_global_asm_807F5D30[2][3] * arg4);

    return (f32)((f64)(row1) +
                 ((f64)row2) +
                 ((f64)row3) +
                 (f64)row4);
}
*/

// Creates the matrix used for some kind of interpolation used by func_global_asm_80627A00()?
// Looks similar but not exact to catmull-rom matrix for tension = 0.5, and there's another fn
// that calls this fn with 0.5. Very suspicious.
//
// Matrix repr. of the function below:
// [-t,            2 * t,   -t, 0]
// [2 - t,         t - 3,    0, 1]
// [t - 2,   3 - (2 * t),    t, 0]
// [t,                -t,    0, 0]
void func_global_asm_80627B58(f32 arg0) { // init_spline_basis_matrix(f32 tension) ?
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
