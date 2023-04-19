#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1435C0/func_8073E8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1435C0/func_8073F1E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1435C0/func_8073F328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1435C0/func_8073F60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1435C0/func_8073F81C.s")

/*
// TODO: Should be trivial, and yet
s16 func_8073F81C(s16 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 sp4;
    s32 temp_a1;

    temp_a1 = arg1 >> 3;
    if (temp_a1 == 0) {
        return arg0;
    }
    sp4 = (arg3 & 0xFFFF) * temp_a1;
    sp4 = sp4 >> 0x10;
    sp4 += arg2 * temp_a1;
    return arg0 + sp4;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1435C0/func_8073F8A0.s")
