#include "common.h"

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

Gfx *func_global_asm_8065919C(Gfx *dl) {
    gSPFogFactor(dl++,
        0x1F400 / (D_global_asm_807F7368 - D_global_asm_807F7366),
        ((s32)((-D_global_asm_807F7366 << 8) + 0x1F400U) / (D_global_asm_807F7368 - D_global_asm_807F7366))
    );
    gDPPipeSync(dl++);
    gDPSetFogColor(dl++, D_global_asm_807F7361, D_global_asm_807F7362, D_global_asm_807F7363, D_global_asm_807F7364);
    
    return dl;
}

Gfx *func_global_asm_806592B4(Gfx *dl) {
    if (D_global_asm_807F7360 != 0) {
        gSPSetGeometryMode(dl++, 0x10000);
        dl = func_global_asm_8065919C(dl);
    } else {
        gSPGeometryMode(dl++, 0x10000, 0);
    }
    return dl;
}
