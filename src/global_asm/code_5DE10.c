#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_807F7360;
extern u8 D_global_asm_807F7361; // R
extern u8 D_global_asm_807F7362; // G
extern u8 D_global_asm_807F7363; // B
extern u8 D_global_asm_807F7364; // A
extern s16 D_global_asm_807F7366;
extern s16 D_global_asm_807F7368;

void func_global_asm_80659110(u8 arg0) {
    D_global_asm_807F7360 = arg0;
    if (current_map == MAP_AZTEC) {
        D_global_asm_807F7361 = 0x8A; // R
        D_global_asm_807F7362 = 0x52; // G
        D_global_asm_807F7363 = 0x16; // B
    } else {
        D_global_asm_807F7361 = 0; // R
        D_global_asm_807F7362 = 0; // G
        D_global_asm_807F7363 = 0; // B
    }
    D_global_asm_807F7364 = 0; // A
    D_global_asm_807F7366 = 990;
    D_global_asm_807F7368 = 999;
}

u8 func_global_asm_80659190(void) {
    return D_global_asm_807F7360;
}

// Displaylist stuff, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5DE10/func_global_asm_8065919C.s")

/*
Gfx *func_global_asm_8065919C(Gfx *dl) {
    // dl->unk0 = 0xDB080000;
    // dl->unk4 = ((0x1F400 / temp_a2) << 0x10) | ((((D_global_asm_807F7366 * -0x100) + 0x1F400) / temp_a2) & 0xFFFF);

    gSPFogFactor(dl++, 128000 / (D_global_asm_807F7368 - D_global_asm_807F7366), ((D_global_asm_807F7366 * -256)) / (D_global_asm_807F7368 - D_global_asm_807F7366));
    gDPPipeSync(dl++);
    gDPSetFogColor(dl++, D_global_asm_807F7361, D_global_asm_807F7362, D_global_asm_807F7363, D_global_asm_807F7364);
    
    return dl;
}
*/

void *func_global_asm_806592B4(Gfx *arg0) {
    if (D_global_asm_807F7360 != 0) {
        gSPSetGeometryMode(arg0++, 0x10000);
        arg0 = func_global_asm_8065919C(arg0);
    } else {
        gSPGeometryMode(arg0++, 0x10000, 0);
    }
    return arg0;
}
