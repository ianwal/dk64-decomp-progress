#include <ultra64.h>
#include "functions.h"


// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C0EE0/func_806BC1E0.s")

extern s32 D_8075BB30; // TODO: Type
extern s32 D_8075BB38; // TODO: Type

extern Gfx D_01000118;
extern Mtx D_02000180;

void func_806BCF98(Gfx *dl, s32 arg1) {
    gSPDisplayList(dl++, &D_01000118);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_02000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    func_806FC530(func_806FC530(dl, 1, 0x208, 0xC8, &D_8075BB30, 1), 1, 0x208, 0x12C, &D_8075BB38, 1);
}

// Caves Ice Tomato Board State
extern s8 D_807FC8C0[];

// Set Caves Ice Tomato Board Square
void func_806BD094(s16 arg0, s8 arg1) {
    if (arg0 >= 0 && arg0 < 0x10) {
        D_807FC8C0[arg0] = arg1;
    }
}

// Reset Caves Ice Tomato Board
void func_806BD0CC(void) {
    s32 i;

    // Caves: Ice Tomato Board Active
    setFlag(0x30, FALSE, FLAG_TYPE_TEMPORARY);

    for (i = 0; i < 16; i++) {
        D_807FC8C0[i] = -1;
        func_8063DA40(i, 0);
    }

    D_807FC8C0[5] = 0;
    D_807FC8C0[6] = 1;
    D_807FC8C0[9] = 1;
    D_807FC8C0[10] = 0;
}
