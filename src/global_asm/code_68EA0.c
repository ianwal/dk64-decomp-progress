#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806641A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806643C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806644B0.s")

// Doable, loop over struct array size 0xC
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806645B8.s")

/*
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct807F9430;

extern Struct807F9430 D_807F9430[];
extern s16 D_807F9434;

void func_806645B8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_807F9430[0].unk4; i++) {
        if (arg0 == D_807F9430[i].unkA) {
            D_807F9430[i].unkA = -1;
        }
    }
}
*/

s32 func_8066461C(s16 arg0) {
    switch (arg0) {
        case 1: // Thin Flame? (2D)
        case 0x10: // Flame (2D)
        case 0x74: // Golden Banana
        case 0xF3: // Torch
        case 0x138: // Torch
        case 0x288: // Rareware GB
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_8066466C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_80664834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_80664A38.s")
