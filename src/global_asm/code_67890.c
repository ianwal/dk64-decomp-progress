#include <ultra64.h>
#include "functions.h"


typedef struct {
    s32 unk0[4];
    s32 unk10[4];
    s32 unk20[4];
    s32 unk30;
    s32 unk34;
    s16 unk38; // Used
    s16 unk3A;
    s32 unk3C;
} GlobalASMStruct89;

extern GlobalASMStruct89 *D_global_asm_807F93F0;
extern s32 D_global_asm_807F93F8;

// Load map texture, malloc, loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_global_asm_80662B90.s")

s32 func_global_asm_80663040(s32 arg0) {
    s32 i;
    for (i = 0; i < D_global_asm_807F93F8; i++) {
        if (arg0 == D_global_asm_807F93F0[i].unk38) {
            return TRUE;
        }
    }
    return FALSE;
}

// Doable, mid sized struct loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_global_asm_8066308C.s")

typedef struct {
    f32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} Struct807F93F4;

extern Struct807F93F4 *D_global_asm_807F93F4;

Gfx *func_global_asm_806634A4(Gfx *dl) {
    s32 i;
    s32 var_s1;
    s32 found;
    f32 lowest;
    f32 var_f2;

    lowest = 100000000.0f;
    do {
        found = FALSE;
        var_f2 = 0.0f;
        for (i = 0; i < D_global_asm_807F93F8; i++) {
            if (D_global_asm_807F93F4[i].unk11 != 0) {
                if (D_global_asm_807F93F4[i].unk0 < lowest) {
                    if (var_f2 < D_global_asm_807F93F4[i].unk0) {
                        var_s1 = i;
                        var_f2 = D_global_asm_807F93F4[i].unk0;
                        found = TRUE;
                    }
                }
            }
        }
        lowest = var_f2;
        if (found) {
            dl = func_global_asm_80663594(dl, var_s1);
        }
    } while (found);
    return dl;
}

// Displaylist stuff, doable, close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_global_asm_80663594.s")

extern f32 (*D_807F93FC)[4][4]; // How many?
extern void *D_807F9400; // Texture pointer

/*
Gfx *func_global_asm_80663594(Gfx *dl, s32 arg1) {
    gDPPipeSync(dl++);
    gDPSetRenderMode(dl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    gDPSetCombineLERP(dl++, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetPrimColor(dl++, 0, 0, 0x64, 0x64, 0x64, D_global_asm_807F93F4[arg1].unk10);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock(dl++, D_807F9400, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, D_global_asm_807F93F4[arg1].unk12, D_global_asm_807F93F4[arg1].unk13, 0x00FC, 0x00FC);
    gSPVertex(dl++, osVirtualToPhysical(D_807F93FC[arg1]), 4, 0);
    gSP2Triangles(dl++, 0, 1, 2, 0, 0, 2, 3, 0);
    gDPPipeSync(dl++);
    return dl;
}
*/