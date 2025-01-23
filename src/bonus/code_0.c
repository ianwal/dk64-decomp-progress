#include <ultra64.h>
#include "functions.h"

extern void *D_global_asm_8076D1F8;

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

Gfx *func_global_asm_8068DC54(Gfx*, s32, s32, void *, s32, void *);
void func_global_asm_806A2A10(s32, s32, s32);

Gfx *func_bonus_80024000(Gfx *dl, Actor *arg1) {
    A178_80024000 *a178;
    a178 = arg1->unk178;
    if (func_global_asm_805FCA64()) {
        gSPDisplayList(dl++, &D_1000118);
        dl = func_global_asm_8070068C(dl);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        dl = func_global_asm_806FE078(dl, a178->unk9, 8, 30.0f, 36.0f, 0.0f, 1.5f);
        dl = func_global_asm_8068DC54(dl, 0x26, 0x32, &a178->unk2, a178->unk4, &a178->unk8);
    }
    return dl;
}

void func_bonus_800240F0(void) {
    func_global_asm_8072707C(1, 0x40, 0);
    func_global_asm_8072707C(2, 0x40, 0);
    func_global_asm_8072707C(3, 0x40, 0);
    func_global_asm_8072707C(4, 0x40, 0);
    func_global_asm_8072707C(5, 0x40, 0);
}

// Jumptable, doable, close
// https://decomp.me/scratch/6Kwyv
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_0/func_bonus_80024158.s")

/*
void func_global_asm_806C8E58(s16 arg0);
u8 func_global_asm_806FDB8C(s32, s8 *, s32, f32, f32, f32);
extern s32 D_bonus_8002D863[4];
extern s16 D_global_asm_80750AC4;
extern s16 D_global_asm_8076AEF2;
extern u8 D_global_asm_807FBDC4;

typedef struct {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[0x9 - 0x6];
    u8 unk9;
} A178_80024158;

void func_bonus_80024158(void) {
    u8 sp6F;
    u8 sp6E;
    s16 i;
    char *aString;
    u8 boolVal2;
    u8 temp_v1_2;
    u8 boolVal1;
    char *bString;
    s16 temp_v0_2;
    s32 song;
    char *cString;
    s32 var_v1;
    A178_80024158 *a178;
    s32 pad;

    a178 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    sp6F = *D_global_asm_807FDC9C[1].pad0;
    sp6E = D_global_asm_807FDC9C->unkA_u8[0];
    addActorRecolor(
        player_pointer,
        player_pointer->x_position,
        player_pointer->y_position + 30.0f,
        player_pointer->z_position,
        0xFF, 0xFF, 0xFF, 0xFF,
        0
    );
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        boolVal2 = FALSE;
        func_global_asm_80629174();
        D_global_asm_807FDC98->unk46 |= 0x80;
        func_global_asm_806FB370(2, 0, 1);
        func_global_asm_806FB370(5, 0, 1);
        func_global_asm_806FB370(4, 0, 2);
        current_actor_pointer->control_state = 0;
        func_global_asm_806A2A10(0xDC, 0x2A, D_global_asm_807FDC9C->unkA_u8[1]);
        switch (sp6F) { // switch 1
            case 14: // switch 1
                func_global_asm_8063DA78(((rand() >> 0xF) % 32767) % 4, 1, 1);
                // fallthrough
            case 0: // switch 1
            case 4: // switch 1
            case 13: // switch 1
block_4:
                aString = getTextString(0x1A, 2, 1);
                boolVal2 = TRUE;
                break;
            case 15: // switch 1
                func_global_asm_806C8E58(8);
                current_player->control_state = 0xC;
                current_player->control_state_progress = 0;
                playAnimation(current_player, 9);
                current_player->unkB8 = 0.0f;
                func_global_asm_806D03BC();
                goto block_4;
            case 1: // switch 1
            case 10: // switch 1
            case 12: // switch 1
            case 16: // switch 1
                a178->unk2 = 0;
                break;
            case 3: // switch 1
                func_bonus_800240F0();
                break;
            case 5: // switch 1
                func_bonus_800240F0();
                // fallthrough
            case 2: // switch 1
            case 6: // switch 1
            case 7: // switch 1
            case 8: // switch 1
            case 11: // switch 1
                D_global_asm_80750AC4 = 0;
                aString = getTextString(0x1A, 3, 1);
                boolVal2 = TRUE;
                break;
            case 9: // switch 1
                getSpawnerTiedActor((((rand() >> 0xF) % 32767) % 8) + 0x11, 0)->unk15F = 1;
                break;
        }
        if (boolVal2) {
            a178->unk9 = func_global_asm_806FDB8C(1, aString, 8, 0.0f, 0.0f, 0.0f);
            func_global_asm_806FDAB8(a178->unk9, 0.0f);
            a178->unk4 = sp6E;
            a178->unk2 = sp6E;
        }
    }
    if (current_actor_pointer->control_state == 0) {
        for (i = 0; i < D_global_asm_807FBDC4; i++) {
            if (D_global_asm_807FBB70.unk258[i] == 3) {
                boolVal1 = TRUE;
                temp_v1_2 = D_global_asm_807FBB70.unk278[i]->unk2;
                switch (sp6F) { // switch 2
                    case 0: // switch 2
                        temp_v0_2 = a178->unk4;
                        if (temp_v0_2 != 0) {
                            if (temp_v0_2 >= 2) {
                                aString = getTextString(0x1A, 0xF, 1);
                                bString = malloc(strlen(aString) + 5);
                                func_global_asm_8061134C(bString);
                                sprintf(bString, "%d %s", a178->unk4, aString);
                            } else {
                                bString = getTextString(0x1A, 0x10, 1);
                            }
                            func_global_asm_8069D2AC(0, 0, 0x8C, bString, 0, 0x28, 8, 8);
                            boolVal1 = FALSE;
                        }
                        break;
                    case 16: // switch 2
                        if ((a178->unk2 == 0) && (temp_v1_2 != 0x28)) {
                            func_global_asm_8069D2AC(0, 0, 0x8C, getTextString(0x1A, 0x17, 1), 0, 0x28, 8, 8);
                            boolVal1 = FALSE;
                        }
                        if (temp_v1_2 == 0x28) {
                            boolVal1 = FALSE;
                        }
                        break;
                    case 2: // switch 2
                        boolVal1 = TRUE;
                        if (func_global_asm_806F8AD4(0xB, 0) < sp6E) {
                            if (a178->unk4 >= 2) {
                                aString = getTextString(0x1A, 0x11, 1);
                                cString = malloc(strlen(aString) + 5);
                                sprintf(cString, "%d %s", sp6E - func_global_asm_806F8AD4(0xB, 0), aString);
                            } else {
                                cString = getTextString(0x1A, 0x12, 1);
                            }
                            func_global_asm_8069D2AC(0, 0, 0x8C, cString, 0, 0x28, 8, 8);
                            boolVal1 = FALSE;
                        }
                        break;
                    case 7: // switch 2
                    case 8: // switch 2
                    case 9: // switch 2
                    case 11: // switch 2
                    case 15: // switch 2
                        boolVal1 = FALSE;
                        break;
                    case 12: // switch 2
                    case 13: // switch 2
                        boolVal1 = FALSE;
                        if (temp_v1_2 != 0x12) {
                            if (temp_v1_2 == 0x27) {
                                current_actor_pointer->unk15F++;
                                if (current_actor_pointer->unk15F >= 3) {
                                    boolVal1 = FALSE;
                                    func_global_asm_8063DA40(2, 0xA);
                                }
                            } else {
                                boolVal1 = FALSE;
                                func_bonus_800265C0(1, 1);
                            }
                        }
                        break;
                }
                if (boolVal1) {
                    func_bonus_800264E0(1, 0xE);
                    func_global_asm_80726EE0(0);
                }
            }
        }
    }
    if (current_actor_pointer->control_state == 0) {
        switch (sp6F) { // switch 3
            case 15: // switch 3
                func_global_asm_80724A20();
                // fallthrough
            case 4: // switch 3
            case 11: // switch 3
            case 13: // switch 3
            case 14: // switch 3
                if (a178->unk4 == 0) {
                    func_bonus_800264E0(1, 0xE);
                }
                // fallthrough
            case 0: // switch 3
                var_v1 = MAX(0, sp6E - enemies_killed);
                if (var_v1 != a178->unk4) {
                    func_global_asm_806FDAB8(a178->unk9, 3.1415927f);
                    a178->unk4 = MAX(0, sp6E - enemies_killed);
                }
                goto block_71;
            case 7: // switch 3
            case 8: // switch 3
                func_global_asm_80724A20();
                goto block_71;
            case 5: // switch 3
                if ((current_map == MAP_SPLISH_SPLASH_SALVAGE_EASY) && (a178->unk4 == 1)) {
                    if (current_actor_pointer->control_state_progress == 0) {
                        current_actor_pointer->control_state_progress++;
                        func_global_asm_80641874(0, 0);
                        func_global_asm_80641874(1, 0);
                        func_global_asm_80641874(2, 0);
                    }
                }
                // fallthrough
            case 6: // switch 3
                if (a178->unk4 == 0) {
                    func_bonus_800264E0(1, 0xE);
                }
                // fallthrough
            case 2: // switch 3
                var_v1 = MAX(0, sp6E - func_global_asm_806F8AD4(0xB, 0));
                if (var_v1 != a178->unk4) {
                    func_global_asm_806FDAB8(a178->unk9, 3.1415927f);
                    a178->unk4 = MAX(0, sp6E - func_global_asm_806F8AD4(0xB, 0));
                }
block_71:
                if (a178->unk0 >= 2) {
                    addActorToTextOverlayRenderArray(func_bonus_80024000, current_actor_pointer, 3);
                }
                break;
            case 9: // switch 3
            case 10: // switch 3
            case 12: // switch 3
            case 16: // switch 3
                func_global_asm_80724A20();
                break;
        }
    }
    switch (a178->unk0) { // switch 6; irregular
        case 0: // switch 6
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80629174();
                if (D_global_asm_8076AEF2 == 0x11) {
                    func_global_asm_8070E8DC(2);
                }
                loadText(current_actor_pointer, 0, D_bonus_8002D863[sp6F]);
                a178->unk0++;
            }
            break;
        case 1: // switch 6
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                func_global_asm_806A2B08(current_actor_pointer->unk11C);
                switch (current_map) { // switch 7; irregular
                    case MAP_KROOL_BARREL_TINY_MUSHROOM_GAME:
                    case MAP_KROOL_BARREL_DK_TARGET_GAME:
                    case MAP_KROOL_BARREL_LANKY_MAZE:
                    case MAP_KROOL_BARREL_DIDDY_KREMLING_GAME: // switch 7
                    case MAP_KROOL_BARREL_DIDDY_ROCKETBARREL_GAME: // switch 7
                    case MAP_KROOL_BARREL_LANKY_SHOOTING_GAME: // switch 7
                    case MAP_KROOL_BARREL_CHUNKY_HIDDEN_KREMLING_GAME: // switch 7
                    case MAP_KROOL_BARREL_TINY_PONY_TAIL_TWIRL_GAME: // switch 7
                    case MAP_KROOL_BARREL_CHUNKY_SHOOTING_GAME: // switch 7
                    case MAP_KROOL_BARREL_DK_RAMBI_GAME: // switch 7
                        song = 0x75;
                        break;
                    default:
                        if (sp6F != 0) {
                            if (sp6F != 1) {
                                song = 8;
                            } else {
                                song = 0x59;
                            }
                        } else {
                            song = 0x52;
                        }
                        break;
                }
                playSong(song, 1.0f);
                a178->unk0++;
            }
            break;
    }
    switch (current_actor_pointer->control_state) { // switch 5
        case 0x0: // switch 5
            if (((sp6F == 1) || (sp6F == 0) || (sp6F == 2) || (sp6F == 0x10)) && (player_pointer->y_position < 0.0f)) {
                func_bonus_800265C0(1, 1);
            } else if ((sp6F == 4) && (player_pointer->y_position < -20.0f)) {
                playSoundAtActorPosition(current_actor_pointer, 0x362, 0xFF, 0x7F, 0);
                func_bonus_800265C0(0, 1);
                playCutscene(current_actor_pointer, 1, 1);
            } else if (player_pointer->control_state == 0x73) {
                if (sp6F == 1) {
                    func_bonus_800265C0(1, 0x13);
                } else {
                    func_bonus_800265C0(1, 1);
                }
            } else if ((sp6F == 3) && (player_pointer->control_state == 0x31)) {
                func_bonus_800265C0(1, 0x14);
            } else if (current_actor_pointer->unk11C->control_state == 5) {
                if (sp6F == 3) {
                    func_bonus_800264E0(1, 0x15);
                } else {
                    func_bonus_800265C0(1, 0x16);
                }
            }
            break;
        default: // switch 5
            break;
        case 0x1: // switch 5
            current_actor_pointer->unk11C->control_state = 0;
            current_actor_pointer->control_state++;
            break;
        case 0x27: // switch 5
            func_global_asm_806FDAB8(a178->unk9, 3.1415927f);
            a178->unk4--;
            if (a178->unk4 == 0) {
                func_bonus_800264E0(1, 0xE);
            } else {
                current_actor_pointer->control_state = 0;
            }
            break;
        case 0x28: // switch 5
            a178->unk2 = 1;
            current_actor_pointer->control_state = 0;
            break;
        case 0x37: // switch 5
            func_bonus_800265C0(1, 1);
            break;
        case 0x12: // switch 5
            func_bonus_800264E0(1, 0xE);
            break;
    }
}
*/

Gfx *func_bonus_80024D3C(Gfx *dl, s32 arg1) {
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    return dl;
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

void func_bonus_80024E38(void) {
    A178_80024E38 *a178;

    a178 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
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
                func_global_asm_8069D2AC(0x81, 0, 0x78, getTextString(0x1A, 0x15, 1), 0, 0x28, 8, 8);
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
            playSound(0x1E9, 0x7FFFU - ((u32)a178->unk0 * 150U), 64.0f, 1.0f, 0xA, 0x80);
            if (a178->unk0 == 0) {
                a178->unk0 = 0xC8;
            }
            break;
    }
}
