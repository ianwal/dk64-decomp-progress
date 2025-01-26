#include <ultra64.h>
#include "functions.h"

f32 func_global_asm_80739FE0(s32 arg0) {
    f32 sp4;
    f32 sp0;

    sp0 = 1.0f;
    if (arg0 >= 0) {
        sp4 = 1.0005778f;
    } else {
        sp4 = 0.99942255f;
        arg0 = -arg0;
    }
    while (arg0 != 0) {
        if (arg0 & 1) {
            sp0 *= sp4;
        }
        sp4 *= sp4;
        arg0 >>= 1;
    }
    return sp0;
}
