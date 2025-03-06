#include "common.h"

f32 func_global_asm_80612E40(f32 arg0) {
    s32 temp_f4;

    temp_f4 = arg0;
    if (0.00001f < (arg0 - (f32) temp_f4)) {
        temp_f4++;
    }
    return temp_f4;
}
