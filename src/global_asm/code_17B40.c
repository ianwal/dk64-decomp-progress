#include <ultra64.h>
#include "functions.h"

extern f32 D_global_asm_80757350;

f32 func_global_asm_80612E40(f32 arg0) {
    s32 temp_f4;

    temp_f4 = arg0;
    if (D_global_asm_80757350 < (arg0 - (f32) temp_f4)) {
        temp_f4++;
    }
    return temp_f4;
}
