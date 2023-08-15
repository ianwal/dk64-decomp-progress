#include <ultra64.h>
#include "functions.h"

void *func_global_asm_8068DC54(s32, s32, s32, void *, s32, void *);
s32 func_global_asm_806FE078(Gfx *, u8, s32, f32, f32, f32, f32);
void *func_global_asm_8070068C(void *);

// rodata
/*
const u32 D_bonus_8002DC90[] = {
    0x00010200,
    0x03040000,
};

const u32 D_bonus_8002DC98[] = {
    0x04020300,
    0x01000000,
};

const u32 D_bonus_8002DCA0[] = {
    0x02000104,
    0x00030000,
};

const u32 D_bonus_8002DCA8[] = {
    0x03010002,
    0x00040000,
};
*/

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

Gfx *func_bonus_80024000(Gfx *dl, Actor *arg1) {
    A178_80024000 *a178;
    a178 = arg1->unk178;
    if (func_global_asm_805FCA64() != 0) {
        gSPDisplayList(dl++, &D_1000118);
        dl = func_global_asm_8070068C(dl);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
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
    gSPDisplayList(arg0++, &D_1000118);
    // TODO: Get rid of magic constants
    gDPSetCombine(arg0++, 0x119623, 0xFF2FFFFF);
    gDPSetPrimColor(arg0++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    return arg0;
}

// Jumptable, matched but has rodata issues
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024D8C.s")

/*
s32 func_bonus_80024D8C(void) {
    switch (current_map) {
        case MAP_BATTLE_ARENA_BEAVER_BRAWL:
            return 0x261;
        case MAP_BATTLE_ARENA_KRITTER_KARNAGE:
            return 0x262;
        case MAP_BATTLE_ARENA_ARENA_AMBUSH:
            return 0x263;
        case MAP_BATTLE_ARENA_MORE_KRITTER_KARNAGE:
            return 0x264;
        case MAP_BATTLE_ARENA_KAMIKAZE_KREMLINGS:
            return 0x265;
        case MAP_BATTLE_ARENA_FOREST_FRACAS:
            return 0x266;
        case MAP_BATTLE_ARENA_BISH_BASH_BRAWL:
            return 0x267;
        case MAP_BATTLE_ARENA_PLINTH_PANIC:
            return 0x268;
        case MAP_BATTLE_ARENA_PINNACLE_PALAVER:
            return 0x269;
        case MAP_BATTLE_ARENA_SHOCKWAVE_SHOWDOWN:
            return 0x26A;
        default:
            return -1;
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024E38.s")
