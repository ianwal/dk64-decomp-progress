#include <ultra64.h>
#include "functions.h"

void *func_global_asm_80612840(tuple_f *arg0, tuple_f a0, tuple_f a1) {
    tuple_f result;

    result.x = (a0.x - a1.x);
    result.y = (a0.y - a1.y);
    result.z = (a0.z - a1.z);

    *arg0 = result;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_806128A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_80612910.s")

void *func_global_asm_80612970(tuple_f *arg0, tuple_f arg1) {
    tuple_f result;
    f32 d;

    d = sqrtf(SQ(arg1.x) + SQ(arg1.y) + SQ(arg1.z));
    if (d != 0) {
        result.x = arg1.x / d;
        result.y = arg1.y / d;
        result.z = arg1.z / d;
    }

    *arg0 = result;
    return arg0;
}

f32 func_global_asm_80612A14(tuple_f a0, tuple_f a1) {
    return (a0.x * a1.x) + (a0.y * a1.y) + (a0.z * a1.z);
}

tuple_f *func_global_asm_80612A54(tuple_f *arg0, tuple_f arg1, tuple_f arg4) {
    tuple_f result;

    result.x = (arg1.y * arg4.z) - (arg1.z * arg4.y);
    result.y = (arg1.z * arg4.x) - (arg1.x * arg4.z);
    result.z = (arg1.x * arg4.y) - (arg1.y * arg4.x);

    *arg0 = result;
    return arg0;
}

// TODO: Use tuple_f?
void func_global_asm_80612AD8(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
}
