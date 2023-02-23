#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13C920/func_80737C20.s")

/*
extern s8 D_807FF0F0;
extern s8 D_807FF0F1;
extern s8 D_807FF0F2;

// TODO: Sus, maybe mips3?
void func_80737C20(u8 arg0) {
    s32 sp24;
    s32 temp_t0;

    D_807FF0F0 = 0;
    D_807FF0F1 = 0;
    D_807FF0F2 = 0;
    switch (arg0) {
    case 1:
        D_807FF0F1 = 1;
        break;
    case 3:
        D_807FF0F2 = 1;
        break;
    case 4:
        D_807FF0F0 = 1;
        break;
    }
    sp24 = 0;
    do {
        func_80737CF4(sp24, 0);
        temp_t0 = sp24 + 1;
        sp24 = temp_t0;
    } while (temp_t0 < 2);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13C920/func_80737CF4.s")
