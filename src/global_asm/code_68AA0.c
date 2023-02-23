#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68AA0/func_80663DA0.s")

s32 func_80663FCC(s16 model2ArrayIndex) {
    switch (D_807F6000[model2ArrayIndex].object_type) {
        case 0x1: // Thin Flame? (2D)
        case 0xC: // Flames (2D)
        case 0x10: // Flame (2D)
        case 0xF3: // Torch
        case 0x134: // Flame
        case 0x135: // Flame
        case 0x138: // Torch
            return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68AA0/func_80664044.s")
