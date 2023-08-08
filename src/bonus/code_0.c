#include <ultra64.h>
#include "functions.h"

void *func_global_asm_8068DC54(s32, s32, s32, void *, s32, void *);
s32 func_global_asm_806FE078(Gfx *, u8, s32, f32, f32, f32, f32);
void *func_global_asm_8070068C(void *);

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} A178_80024000;

extern Gfx D_01000118;
extern Mtx D_02000180;

Gfx *func_bonus_80024000(Gfx *dl, Actor *arg1) {
    A178_80024000 *a178;
    a178 = arg1->unk178;
    if (func_global_asm_805FCA64() != 0) {
        gSPDisplayList(dl++, &D_01000118);
        dl = func_global_asm_8070068C(dl);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPMatrix(dl++, &D_02000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        dl = func_global_asm_8068DC54(func_global_asm_806FE078(dl, a178->unk9, 8, 30.0f, 36.0f, 0.0f, 1.5f), 0x26, 0x32, &a178->unk2, a178->unk4, &a178->unk8);
    }
    return dl;
}

void func_bonus_800240F0() {
    func_global_asm_8072707C(1, 0x40, 0);
    func_global_asm_8072707C(2, 0x40, 0);
    func_global_asm_8072707C(3, 0x40, 0);
    func_global_asm_8072707C(4, 0x40, 0);
    func_global_asm_8072707C(5, 0x40, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024158.s")

Gfx *func_bonus_80024D3C(Gfx *arg0, s32 arg1) {
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
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024D8C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024E38.s")
