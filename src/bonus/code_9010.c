#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s8 D_8002D92C;
extern s8 D_8002D930;
extern s8 D_8002DEF0[];

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D6F8.s")

void func_8002D7E8(s16 arg0) {
    s8 phi_v0 = arg0 == 0xD4 ? 0xA : 2;

    if (D_8002D92C < 6) {
        D_8002DEF0[D_8002D92C] = phi_v0;
        D_8002D92C++;
        D_8002D930 = 0x14;
    }
    if (D_8002D92C >= 5) {
        D_8002D930 = 0;
    }
}
