#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_16550/func_80611850.s")

s32 func_80611DA0(s16);
extern f32 D_807572D0;
extern f32 D_807572D4;
extern f32 D_807572D8;
extern f32 D_807572DC;
extern f32 D_807572E0;
extern f32 D_807572E4;

/*
// TODO: Close, some float nonsense
f32 func_80611850(f32 arg0) {
    s16 phi_a0;

    if (arg0 >= 1.0f) {
        phi_a0 = 0x7FFF;
    } else if (arg0 <= -1.0f) {
        phi_a0 = -0x7FFF;
    } else {
        phi_a0 = arg0 * D_807572D0;
    }
    return (func_80611DA0(phi_a0) * D_807572D4) / D_807572D8;
}
*/

f32 func_806118FC(f32 arg0) {
    s16 phi_a0;

    if (arg0 >= 1.0f) {
        phi_a0 = 0x7FFF;
    } else if (arg0 <= -1.0f) {
        phi_a0 = -0x7FFF;
    } else {
        phi_a0 = arg0 * D_807572DC;
    }
    return (func_80611DF4(phi_a0) * D_807572E0) / D_807572E4;
}
