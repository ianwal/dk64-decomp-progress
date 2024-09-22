#include <ultra64.h>
#include "functions.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 temp;
} Vector3F;

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_80612840.s")

/*
void *func_global_asm_80612840(Vector3F *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Vector3F sp4;

    sp4.x = arg1 - arg4;
    sp4.y = arg2 - arg5;
    sp4.z = arg3 - arg6;
    *arg0 = sp4;
    return arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_806128A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_80612910.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_80612970.s")

// stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_80612A14.s")

/*
f32 func_global_asm_80612A14(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    return (arg0 * arg3) + (arg1 * arg4) + (arg2 * arg5);
}
*/

// close, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17540/func_global_asm_80612A54.s")

/*
Vector3F *func_global_asm_80612A54(Vector3F *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Vector3F sp4;

    sp4.x = (arg2 * arg6) - (arg3 * arg5);
    sp4.y = (arg3 * arg4) - (arg1 * arg6);
    sp4.z = (arg1 * arg5) - (arg2 * arg4);
    *arg0 = sp4;
    return arg0;
}
*/

void func_global_asm_80612AD8(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
}