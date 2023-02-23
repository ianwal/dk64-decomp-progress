#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_807452A0;

void func_80600950(void) {
    D_807452A0 = 0;
}

s32 func_8060095C(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 += 0x50505050;
    *arg2 += 0x50505050;
    return arg0 + 0x3FFF00FF;
}

// malloc, small struct?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5650/func_8060098C.s")

// small struct
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5650/func_80600B10.s")

// similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5650/func_80600BBC.s")

// similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5650/func_80600C68.s")
