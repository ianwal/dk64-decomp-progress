#include <ultra64.h>
#include "functions.h"

u32 func_global_asm_80611DA0(s16);
extern f32 D_global_asm_807572D0;
extern f32 D_global_asm_807572D4;
extern f32 D_global_asm_807572D8;
extern f32 D_global_asm_807572DC;
extern f32 D_global_asm_807572E0;
extern f32 D_global_asm_807572E4;

f32 func_global_asm_80611850(f32 arg0) {
    s16 var_a0;

    if (arg0 >= 1.0f) {
        var_a0 = 0x7FFF;
    } else if (arg0 <= -1.0f) {
        var_a0 = -0x7FFF;
    } else {
        var_a0 = arg0 * D_global_asm_807572D0;
    }
    return (func_global_asm_80611DA0(var_a0) * D_global_asm_807572D4) / D_global_asm_807572D8;
}

f32 func_global_asm_806118FC(f32 arg0) {
    s16 phi_a0;

    if (arg0 >= 1.0f) {
        phi_a0 = 0x7FFF;
    } else if (arg0 <= -1.0f) {
        phi_a0 = -0x7FFF;
    } else {
        phi_a0 = arg0 * D_global_asm_807572DC;
    }
    return (func_global_asm_80611DF4(phi_a0) * D_global_asm_807572E0) / D_global_asm_807572E4;
}
