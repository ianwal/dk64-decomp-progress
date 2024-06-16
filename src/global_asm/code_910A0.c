#include <ultra64.h>
#include "functions.h"

void func_global_asm_80612CA0(f32 (*)[4], f32);
extern s32 D_global_asm_807501E8; // TODO: Type

Gfx *func_global_asm_8068C3A0(Gfx *dl, s32 arg1, s16 x, s16 y, s16 arg4) {
    f32 spA0[4][4];
    f32 sp60[4][4];
    Mtx *sp5C;
    s32 pad;

    sp5C = malloc(sizeof(Mtx));
    func_global_asm_8061134C(sp5C);
    gDPPipeSync(dl++);
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, arg1 + 0x80000000);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
    gDPLoadSync(dl++);\
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 256);\
    gDPPipeSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
    func_global_asm_80612CA0(spA0, arg4);
    guTranslateF(sp60, x, y, 0.0f);
    guMtxCatF(spA0, sp60, spA0);
    guMtxF2L(spA0, sp5C);
    gSPMatrix(dl++, sp5C, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPVertex(dl++, osVirtualToPhysical(&D_global_asm_807501E8), 4, 0);
    gSP2Triangles(dl++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSPPopMatrix(dl++, G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_910A0/displayImage.s")

// Displaylist stuff, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_910A0/func_global_asm_8068D264.s")

void func_global_asm_8068D8C8(Gfx *dl, s32 arg1) {
    gSPDisplayList(dl++, &D_1000118);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xA0);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPMatrix(dl++, &D_2000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    // TODO: What does the object_timer expression do? Any better way to represent it?
    displayImage(dl, ((((u32)object_timer >> 1) & 0xF) + 0x8F), 0, 2, 0x20, 0x20, 0x118, 0xD2, 1.0f, 1.0f, 0, 0.0f);
}

// Displaylist stuff, regalloc, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_910A0/func_global_asm_8068D9DC.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 *unk14;
    s32 unk18;
    u8 *unk1C;
} Struct8068D9DC_arg1;

/*
Gfx *func_global_asm_8068D9DC(Gfx *dl, Struct8068D9DC_arg1 *arg1) {
    s32 pad2;
    s32 pad;
    char sp3C[4];
    char sp38[4];

    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x96);

    sprintf(sp3C, "%d", arg1->unk14);
    dl = printStyledText(dl, 3, 0x424, 0x50, sp3C, 1);
    dl = printStyledText(dl, 1, 0x50, 0x50, "HIT", 1);
    sprintf(sp38, "%d", arg1->unk1C);
    return printStyledText(dl, 3, 0x50, 0xB0, sp38, 1);
}
*/

Gfx *func_global_asm_8068DAF4(Gfx *dl, u8 *arg1) {
    char sp38[8];

    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x96);

    sprintf(sp38, "%d", *arg1);
    return printStyledText(dl, 3, 260, 80, sp38, 1);
}

// Displaylist stuff, regalloc, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_910A0/func_global_asm_8068DBA4.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct8068DBA4_arg1;

/*
Gfx *func_global_asm_8068DBA4(Gfx *dl, Struct8068DBA4_arg1 *arg1) {
    char sp34[12];

    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x96);

    sprintf(sp34, "%d", arg1->unk14);
    return printStyledText(dl, 3, 0x370, 0x50, sp34, 1);
}
*/

// Displaylist stuff, huge
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_910A0/func_global_asm_8068DC54.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_910A0/func_global_asm_8068E474.s")

Gfx *func_global_asm_8068E7B4(Gfx *dl, f32 arg1, f32 arg2, s32 seconds) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 pad48;
    s32 pad44;
    s32 minutes;
    char sp3C[4];
    s32 y;

    sp50 = arg2 - (func_global_asm_806FD894(0x86) * 0.5f);
    sprintf(sp3C, ":");
    sp4C = getCenterOfString(6, sp3C) * 0.5f;
    sp54 = arg1 - sp4C;
    y = sp50 * 4.0f;
    minutes = seconds / 60;
    dl = printStyledText(dl, 6, sp54 * 4.0f, y, sp3C, 1);
    sprintf(sp3C, "%2d", minutes);
    sp54 -= getCenterOfString(0x86, sp3C);
    dl = printStyledText(dl, 0x86, sp54 * 4.0f, y, sp3C, 1);
    sprintf(sp3C, "%02d", seconds - (minutes * 60));
    return printStyledText(dl, 0x86, (arg1 + sp4C) * 4.0f, y, sp3C, 1);
}
