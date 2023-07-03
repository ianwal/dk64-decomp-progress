#include <ultra64.h>
#include "functions.h"

extern u8 D_807F7360;
extern u8 D_807F7361;
extern u8 D_807F7362;
extern u8 D_807F7363;
extern u8 D_807F7364;
extern u16 D_807F7366;
extern u16 D_807F7368;

void func_80659110(u8 arg0) {
    D_807F7360 = arg0;
    if (current_map == MAP_AZTEC) {
        D_807F7361 = 0x8A;
        D_807F7362 = 0x52;
        D_807F7363 = 0x16;
    } else {
        D_807F7361 = 0;
        D_807F7362 = 0;
        D_807F7363 = 0;
    }
    D_807F7364 = 0;
    D_807F7366 = 990;
    D_807F7368 = 999;
}

u8 func_80659190(void) {
    return D_807F7360;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5DE10/func_8065919C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5DE10/func_806592B4.s")
