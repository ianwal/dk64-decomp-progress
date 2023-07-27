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

/*
void *func_8065919C(void *arg0) {
    s32 temp_a2;
    void *temp_a0;
    void *temp_a0_2;

    arg0->unk0 = 0xDB080000;
    temp_a2 = D_807F7368 - D_807F7366;
    temp_a0_2 = arg0 + 8;
    arg0->unk4 = ((0x1F400 / temp_a2) << 0x10) | ((((D_807F7366 * -0x100) + 0x1F400) / temp_a2) & 0xFFFF);
    temp_a0_2->unk0 = 0xE7000000;
    temp_a0 = temp_a0_2 + 8;
    temp_a0_2->unk4 = 0;
    temp_a0->unk0 = 0xF8000000;
    temp_a0->unk4 = (D_807F7361 << 0x18) | (D_807F7362 << 0x10) | (D_807F7363 << 8) | D_807F7364;
    return temp_a0 + 8;
}
*/

void *func_8065919C(void *);

void *func_806592B4(Gfx *arg0) {
    if (D_807F7360 != 0) {
        gSPSetGeometryMode(arg0++, 0x10000);
        arg0 = func_8065919C(arg0);
    } else {
        gSPGeometryMode(arg0++, 0x10000, 0);
    }
    return arg0;
}
