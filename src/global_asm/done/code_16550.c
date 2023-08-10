#include <ultra64.h>
#include "functions.h"

u32 func_global_asm_80611DA0(s16);

f32 func_global_asm_80611850(f32 arg0) {
    s16 var_a0;

    if (arg0 >= 1.0f) {
        var_a0 = 0x7FFF;
    } else if (arg0 <= -1.0f) {
        var_a0 = -0x7FFF;
    } else {
        var_a0 = arg0 * 32767.0f;
    }
    return (func_global_asm_80611DA0(var_a0) * 3.141592741f) / 65535.0f;
}

f32 func_global_asm_806118FC(f32 arg0) {
    s16 phi_a0;

    if (arg0 >= 1.0f) {
        phi_a0 = 0x7FFF;
    } else if (arg0 <= -1.0f) {
        phi_a0 = -0x7FFF;
    } else {
        phi_a0 = arg0 * 32767.0f;
    }
    return (func_global_asm_80611DF4(phi_a0) * 3.141592741f) / 65535.0f;
}
