#include "common.h"

// Cubic-spline basis matrix; populated by func_global_asm_80627B58().
extern f32 D_global_asm_807F5D30[4][4];

// Evaluates a cubic spline at parameter t (= arg0) over control points P0..P3
// (= arg1, arg3, arg4, arg5):
//     result = [t^3, t^2, t, 1] * basis_matrix * [P0, P1, P2, P3]
// Each c[j] folds the control points through column j of the basis matrix.
f32 func_global_asm_80627A00(f64 arg0, f32 arg1, f32 arg3, f32 arg4, f32 arg5) {
    f32 c0 = D_global_asm_807F5D30[0][0] * arg1 + D_global_asm_807F5D30[1][0] * arg3 + D_global_asm_807F5D30[2][0] * arg4 + D_global_asm_807F5D30[3][0] * arg5;
    f32 c1 = D_global_asm_807F5D30[0][1] * arg1 + D_global_asm_807F5D30[1][1] * arg3 + D_global_asm_807F5D30[2][1] * arg4 + D_global_asm_807F5D30[3][1] * arg5;
    f32 c2 = D_global_asm_807F5D30[0][2] * arg1 + D_global_asm_807F5D30[1][2] * arg3 + D_global_asm_807F5D30[2][2] * arg4 + D_global_asm_807F5D30[3][2] * arg5;
    f32 c3 = D_global_asm_807F5D30[0][3] * arg1 + D_global_asm_807F5D30[1][3] * arg3 + D_global_asm_807F5D30[2][3] * arg4 + D_global_asm_807F5D30[3][3] * arg5;
    f32 sq = arg0 * arg0;
    f32 cube = sq * arg0;
    return cube * c0 + sq * c1 + arg0 * c2 + c3;
}

// Builds the cubic-spline basis matrix used by func_global_asm_80627A00() from a
// tension parameter (arg0). With tension 0.5 this is the Catmull-Rom basis (another
// function calls it with 0.5).
//
// Resulting matrix (t = tension):
//     [  -t,      2*t,   -t, 0 ]
//     [ 2-t,      t-3,    0, 1 ]
//     [ t-2,  3-(2*t),    t, 0 ]
//     [   t,       -t,    0, 0 ]
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
