#include <ultra64.h>
#include "functions.h"

extern u32 D_global_asm_80746A40;

u32 func_global_asm_806119A0(void) {
    s64 sp18;
    s64 temp_v0;

    sp18 = D_global_asm_80746A40;
    temp_v0 = __ll_mul(sp18, 0x01DF5E0D) + 1;
    D_global_asm_80746A40 = temp_v0 & 0xFFFFFFFF;
    return D_global_asm_80746A40;
}

void func_global_asm_806119F0(s32 arg0) {
    D_global_asm_80746A40 = arg0;
}

f32 func_global_asm_806119FC(void) {
    f32 var_f6;
    u32 temp_v0;

    var_f6 = func_global_asm_806119A0();
    return var_f6 * 2.3283064e-10f;
}

s32 rand(void) {
    return func_global_asm_806119A0() & 0x7FFFFFFF;
}

void func_global_asm_80611A70(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    if ((*arg2 - arg0 < 0.25) && (*arg2 - arg0 >= 0.0)) {
        *arg2 += 0.125;
    }
    if ((*arg3 - arg1 < 0.25) && (*arg3 - arg1 >= 0.0)) {
        *arg3 += 0.125;
    }
    if ((*arg2 - arg0 > -0.25) && (*arg2 - arg0 <= 0.0)) {
        *arg2 -= 0.125;
    }
    if ((*arg3 - arg1 > -0.25) && (*arg3 - arg1 <= 0.0)) {
        *arg3 -= 0.125;
    }
}

extern f32 D_global_asm_807572F0;
extern f32 D_global_asm_807572F4;
extern f32 D_global_asm_807572F8;
extern f32 D_global_asm_807572FC;
extern f32 D_global_asm_80757300;
extern f32 D_global_asm_80757304;
extern f32 D_global_asm_80757308;

f32 func_global_asm_80611BB4(f32 arg0, f32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 var_f2;

    if (arg0 == 0.0f) {
        var_f2 = arg1 >= 0.0f ? 0.0f : D_global_asm_807572F0;
    } else if (arg1 == 0.0f) {
        var_f2 = arg0 > 0.0f ? D_global_asm_807572F4 : D_global_asm_807572F8;
    } else {
        temp_f0 = sqrtf((arg0 * arg0) + (arg1 * arg1));
        if (arg1 < arg0) {
            temp_f0_2 = func_global_asm_80611850(arg1 / temp_f0);
            var_f2 = temp_f0_2;
            if (arg0 < 0.0f) {
                var_f2 = D_global_asm_807572FC - temp_f0_2;
            }
        } else {
            temp_f12 = D_global_asm_80757300 - func_global_asm_80611850(arg0 / temp_f0);
            var_f2 = temp_f12;
            if (arg1 < 0.0f) {
                var_f2 = D_global_asm_80757304 - temp_f12;
            }
            if (var_f2 < 0.0f) {
                var_f2 += D_global_asm_80757308;
            }
        }
    }
    return var_f2;
}
