#include <ultra64.h>
#include "functions.h"

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_80024000.s")

void func_800240F0() {
    func_8072707C(1, 0x40, 0);
    func_8072707C(2, 0x40, 0);
    func_8072707C(3, 0x40, 0);
    func_8072707C(4, 0x40, 0);
    func_8072707C(5, 0x40, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_80024158.s")

extern Gfx D_01000118;

Gfx *func_80024D3C(Gfx *arg0, s32 arg1) {
    gSPDisplayList(arg0++, &D_01000118);
    // TODO: Get rid of magic constants
    gDPSetCombine(arg0++, 0x119623, 0xFF2FFFFF);
    gDPSetPrimColor(arg0++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    return arg0;
}

extern void (*D_8002DB2C[])();

// Jumptable ^
// Very sus, returns with no labels on a switch case
// Polymorphic code?
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_80024D8C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_80024E38.s")
