#include <ultra64.h>
#include "functions.h"


// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C0EE0/func_806BC1E0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C0EE0/func_806BCF98.s")

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
