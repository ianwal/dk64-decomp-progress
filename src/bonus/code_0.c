#include <ultra64.h>
#include "functions.h"

void *func_global_asm_8068DC54(s32, s32, s32, void *, s32, void *);
s32 func_global_asm_806FE078(Gfx *, u8, s32, f32, f32, f32, f32);

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

// Jumptable, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024E38.s")

extern void *D_global_asm_8076D1F8;

typedef struct {
    u16 unk0;
    s16 unk2;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u16 unk18;
} A178_80024E38;

void func_global_asm_806A5DF0(s32, f32, f32, f32, s32, s32, s32, s32);
void func_global_asm_80737638(void * arg0, enum sfx_e arg1, u32 arg2 , u32 arg3, f32 arg4, u32 arg5, u32 arg6);

void func_global_asm_806A2A10(s32, s32, s32);

/*
void func_bonus_80024E38(void) {
    A178_80024E38 *a178;
    s32 temp_v0_5;

    a178 = current_actor_pointer->unk178;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        a178->unk0 = 0x12C;
        a178->unkA = 0;
        a178->unk8 = 0;
        func_global_asm_80737638(D_global_asm_8076D1F8, 0x1E6, 0, 0x40, 1.0f, 0x80, &a178->unk4);
        func_global_asm_806A2A10(0xDC, 0x2A, D_global_asm_807FDC9C->unkA_u8[1]);
        func_global_asm_8072707C(1, 0x40, 0x10);
        func_global_asm_8072707C(2, 0x40, 0x10);
        func_global_asm_8072707C(3, 0x40, 0x10);
        func_global_asm_8072707C(4, 0x40, 0x10);
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_8061CC30();
        a178->unk18 = playCutscene(NULL, 0, 1);
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (a178->unk18 != 0) {
                a178->unk18--;
            } else {
                func_global_asm_806A2B08(current_actor_pointer->unk11C);
                current_actor_pointer->control_state = 1;
            }
            break;
        case 1:
            if (current_actor_pointer->unk11C->control_state == 5) {
                func_global_asm_8069D2AC(0x81, 0, 0x78, func_global_asm_8070E750(0x1A, 0x15, 1), 0, 0x28, 8, 8);
                func_global_asm_80726EE0(0);
                playSong(0x28, 1.0f);
                func_global_asm_806A5DF0(0x56, 588.0f, 240.0f, 582.0f, 0, 0, func_bonus_80024D8C(), 0);
                current_actor_pointer->control_state = 2;
            }
            if (player_pointer->control_state == 0x39) {
                func_global_asm_805FF898();
                func_global_asm_806C9974(0, 0x40);
                current_actor_pointer->control_state = 2;
            }
            break;
    }
    a178->unk0--;
    a178->unk8 = MAX(8000, a178->unk8 - 150);
    a178->unkA = MIN(a178->unk8, a178->unkA + 1000);
    func_global_asm_80737AC4(a178->unk4, 8, a178->unkA);
    if (extra_player_info_pointer->unk1F0 & 0xC0000) {
        if (a178->unk0 < 0x129) {
            a178->unk0 = 0x12C;
            if (extra_player_info_pointer->unk1F0 & 0x40000) {
                if (((rand() >> 0xF) % 1000) & 1) {
                    playSound(0x1E7, 0x7FFF, 64.0f, 1.0f, 0x14, 0x80);
                } else {
                    playSound(0x1EA, 0x7FFF, 64.0f, 1.0f, 0x14, 0x80);
                }
            } else {
                playSound(0x1E8, 0x7FFF, 64.0f, 1.0f, 0x14, 0x80);
            }
        }
        a178->unk8 = MIN(0x7FFF, a178->unk8 + 18000);
        extra_player_info_pointer->unk1F0 &= 0xFFF3FFFF;
    }
    switch (a178->unk0) {
        case 0x0:
        case 0x14:
        case 0x28:
        case 0x3C:
        case 0x50:
            temp_v0_5 = 0x7FFF - (a178->unk0 * 150);
            playSound(0x1E9, temp_v0_5, 64.0f, 1.0f, 0xA, 0x80);
            if (a178->unk0 == 0) {
                a178->unk0 = 0xC8;
            }
            break;
    }
}
*/
