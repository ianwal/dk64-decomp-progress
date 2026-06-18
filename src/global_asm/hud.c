#include "common.h"

typedef struct global_asm_struct_72 GlobalASMStruct72;

struct global_asm_struct_72 {
    s32 unk0;
    GlobalASMStruct72 *unk4; // Next?
};

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    s16 unkE;
} Struct806F94AC_arg0_unk330;

typedef struct {
    u8 unk0[0x330 - 0x0];
    Struct806F94AC_arg0_unk330 *unk330;
    u8 unk334[0x360 - 0x334];
    f32 unk360;
    f32 unk364;
} Struct806F94AC_arg0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s32 unk8;
} Struct806F9744_arg0_unk14;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Struct806F9744_arg0_unk14 *unk14;
} Struct806F9744_arg0;

typedef struct {
    u8 unk0[0x340 - 0x0];
    f32 unk340;
    f32 unk344;
    u8 unk348[0x35E - 0x348];
    s16 unk35E;
    f32 unk360;
    f32 unk364;
} Struct806F9AF0_arg0;

extern f32 D_global_asm_807FD7A0[];
extern f32 D_global_asm_807FD7B8[];
extern f32 D_global_asm_807FD7D0[];

extern s32 D_global_asm_80754288;

extern PlayerHUD *D_global_asm_80754280; // HUD

extern GlobalASMStruct71 *D_global_asm_80754284;

extern s16 D_global_asm_80744544;
extern u16 D_global_asm_80750AC4;
extern u16 D_global_asm_80750AC8;

// rodata
// static const char D_global_asm_8075DA60[] = "o";
// static const char D_global_asm_8075DA64[] = "NA";
// static const char D_global_asm_8075DA68[] = "%d";

PlayerHUD* func_global_asm_806F7FD0(u8 playerIndex) {
    return &D_global_asm_80754280[playerIndex];
}

void func_global_asm_806F8004(f32 xRotation, f32 yRotation, f32 *xOut, f32 *yOut, f32 *zOut) {
    float sp88[4][4];
    float sp48[4][4];
    f32 z;
    f32 y;
    f32 x;
    f32 temp_f2_2;
    f32 sp34;

    sp34 = character_change_array[cc_player_index].near;
    guRotateF(sp88, xRotation, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp88, 0.0f, 0.0f, -sp34, &x, &y, &z);
    guRotateF(sp48, yRotation, 0.0f, 1.0f, 0.0f);
    guMtxXFMF(sp48, x, y, z, xOut, yOut, zOut);
    temp_f2_2 = -sp34 / *zOut;
    *xOut *= temp_f2_2;
    *yOut *= temp_f2_2;
    *zOut = -sp34;
    *xOut = *xOut * 10.5;
    *yOut = *yOut * 10.5;
    *zOut = *zOut * 10.5;
}

void func_global_asm_806F8170(s32 HUDItemIndex, f32 *xOut, f32 *yOut, f32 *zOut) {
    s32 temp_v0;

    if (HUDItemIndex < 0) {
        func_global_asm_806F8004(16.5f, 0.0f, xOut, yOut, zOut);
        return;
    }
    if (HUDItemIndex == 8) {
        func_global_asm_806F8004(1.5 - (D_global_asm_80754280->hud_item[HUDItemIndex].hud_count * 7), 26.0f, xOut, yOut, zOut);
        return;
    }
    *xOut = D_global_asm_80754280->hud_item[HUDItemIndex].unk_10;
    *yOut = D_global_asm_80754280->hud_item[HUDItemIndex].unk_14;
    *zOut = D_global_asm_80754280->hud_item[HUDItemIndex].unk_18;
}

void func_global_asm_806F8278(u8 playerIndex) {
    s32 new_var;
    PlayerProgress *new_var2;
    s32 levelIndex;
    s32 totalGBs;
    s32 kong;

    totalGBs = 0;
    new_var2 = &D_global_asm_807FC950[playerIndex];
    new_var = 14;
    for (levelIndex = 0; levelIndex < new_var; levelIndex++) {
        for (kong = 0; kong < 5; kong++) {
            totalGBs += new_var2->character_progress[kong].golden_bananas[levelIndex];
        }
    }

    D_global_asm_80754280->hud_item[(playerIndex * 0xF) + 9].hud_count = totalGBs;
}

void func_global_asm_806F833C(s32 arg0) {
    u32 HUDItemIndex;
    s32 playerIndex;
    s16 sp96;
    PlayerProgress *pad88;
    u8 levelIndex;
    u8 var_s7;
    HUDDisplay *playerHUD;
    CharacterProgress *sp84;

    sp96 = D_global_asm_80744544;
    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 1);
    if (cc_number_of_players > 1) {
        sp96 = 0;
    }
    if (arg0 != 0) {
        D_global_asm_80754280 = malloc(cc_number_of_players * sizeof(PlayerHUD));
        func_global_asm_80611690(D_global_asm_80754280);
        D_global_asm_80754284 = NULL;
    }
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        pad88 = &D_global_asm_807FC950[playerIndex];
        sp84 = &pad88->character_progress[func_global_asm_806C8DE0(playerIndex)];
        playerHUD = func_global_asm_806F7FD0(playerIndex);
        for (HUDItemIndex = 0; HUDItemIndex < 0xF; HUDItemIndex++) {
            var_s7 = 0;
            if (arg0 != 0) {
                playerHUD[HUDItemIndex].hud_state = 0;
                playerHUD[HUDItemIndex].counter_timer = 0;
                playerHUD[HUDItemIndex].unk_24 = 0;
                playerHUD[HUDItemIndex].freeze_timer = 0;
                playerHUD[HUDItemIndex].counter_pointer = NULL;
                playerHUD[HUDItemIndex].unk_2c = 0;
            }
            if (gameIsInDKTVMode()) {
                playerHUD[HUDItemIndex].unk_2c = 1;
            }
            switch (HUDItemIndex) {
                case 0:
                    playerHUD[HUDItemIndex].actual_count_pointer = &sp84->coloured_bananas[levelIndex];
                    playerHUD[HUDItemIndex].screen_x = 30;playerHUD[HUDItemIndex].screen_y = 38;
                    func_global_asm_806F8004(15.5f, 26.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 13:
                    playerHUD[HUDItemIndex].actual_count_pointer = NULL;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 38;
                    func_global_asm_806F8004(-5.5f, -26.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 8:
                    playerHUD[HUDItemIndex].actual_count_pointer = &sp84->golden_bananas[levelIndex];
                    playerHUD[HUDItemIndex].screen_x = 30;playerHUD[HUDItemIndex].screen_y = 72;
                    func_global_asm_806F8004(1.5f, 26.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 12:
                    playerHUD[HUDItemIndex].actual_count_pointer = NULL;
                    playerHUD[HUDItemIndex].screen_x = 194;playerHUD[HUDItemIndex].screen_y = 208;
                    func_global_asm_806F8004(-26.5f, 26.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 10:
                    playerHUD[HUDItemIndex].actual_count_pointer = NULL;
                    playerHUD[HUDItemIndex].screen_x = 82;playerHUD[HUDItemIndex].screen_y = 208;
                    func_global_asm_806F8004(-26.5f, 26.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 9:
                    playerHUD[HUDItemIndex].actual_count_pointer = NULL;
                    playerHUD[HUDItemIndex].screen_x = 122;playerHUD[HUDItemIndex].screen_y = 208;
                    break;
                case 5:
                    if (sp96 & 0x20) {
                        pad88->crystals = func_global_asm_806F8EDC(5, playerIndex);
                        var_s7 = 1;
                    }
                    playerHUD[HUDItemIndex].actual_count_pointer = &pad88->crystals;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 140;
                    func_global_asm_806F8004(-5.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 2:
                    playerHUD[HUDItemIndex].actual_count_pointer = &pad88->standardAmmo;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 72;
                    func_global_asm_806F8004(8.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 3:
                    if (sp96 & 4) {
                        pad88->homingAmmo = func_global_asm_806F8EDC(3, playerIndex);
                        var_s7 = 1;
                    }
                    playerHUD[HUDItemIndex].actual_count_pointer = &pad88->homingAmmo;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 72;
                    func_global_asm_806F8004(8.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 4:
                    if (sp96 & 8) {
                        pad88->oranges = func_global_asm_806F8EDC(4, playerIndex);
                        var_s7 = 1;
                    }
                    playerHUD[HUDItemIndex].actual_count_pointer = &pad88->oranges;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 106;
                    func_global_asm_806F8004(1.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 6:
                    if (sp96 & 0x10) {
                        pad88->film = func_global_asm_806F8EDC(6, playerIndex);
                        var_s7 = 1;
                    }
                    playerHUD[HUDItemIndex].actual_count_pointer = &pad88->film;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 208;
                    func_global_asm_806F8004(-19.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 11:
                    playerHUD[HUDItemIndex].actual_count_pointer = &D_global_asm_80750AC4;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 38;
                    func_global_asm_806F8004(16.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 1:
                    if (sp96 & 2) {
                        sp84->coins = func_global_asm_806F8EDC(1, playerIndex);
                        var_s7 = 1;
                    }
                    playerHUD[HUDItemIndex].actual_count_pointer = &sp84->coins;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 38;
                    func_global_asm_806F8004(16.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 7:
                    if (sp96 & 0x40) {
                        sp84->instrument_ammo = func_global_asm_806F8EDC(7, playerIndex);
                        var_s7 = 1;
                    }
                    playerHUD[HUDItemIndex].actual_count_pointer = &sp84->instrument_ammo;
                    playerHUD[HUDItemIndex].screen_x = 290;playerHUD[HUDItemIndex].screen_y = 174;
                    func_global_asm_806F8004(-12.5f, -19.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
                case 14:
                    playerHUD[HUDItemIndex].actual_count_pointer = &D_global_asm_80750AC8;
                    playerHUD[HUDItemIndex].screen_x = 30;playerHUD[HUDItemIndex].screen_y = 38;
                    func_global_asm_806F8004(15.5f, 26.0f, &playerHUD[HUDItemIndex].unk_10, &playerHUD[HUDItemIndex].unk_14, &playerHUD[HUDItemIndex].unk_18);
                    break;
            }
            playerHUD[HUDItemIndex].unk_2d = var_s7;
            if (var_s7 & 0xFF) {
                playerHUD[HUDItemIndex].unk_2c = 1;
            }
            if (playerHUD[HUDItemIndex].actual_count_pointer != NULL) {
                playerHUD[HUDItemIndex].hud_count = *playerHUD[HUDItemIndex].actual_count_pointer;
            }
        }
        func_global_asm_806F8278(playerIndex);
    }
    if (current_map == MAP_HELM || current_map == MAP_CAVES_BEETLE_RACE) {
        func_global_asm_806FB370(5, 0, 1);
    }
}

void func_global_asm_806F8A8C(u8 arg0, u8 playerIndex, s32 arg2) {
    PlayerHUD* temp = func_global_asm_806F7FD0(playerIndex);
    temp->hud_item[arg0].hud_count = arg2;
}

u16 func_global_asm_806F8AD4(u8 arg0, u8 playerIndex) {
    u16 phi_a2;
    u16 *temp;
    s32 kong;
    HUDDisplay *HUDItem;
    s32 levelIndex;

    phi_a2 = 0;
    HUDItem = &func_global_asm_806F7FD0(playerIndex)->hud_item[arg0];
    switch (HUDItem->unk_2c) {
        case 0:
            // Astonishing...
            temp = HUDItem->actual_count_pointer;
            if (temp) {
                phi_a2 = *((u16*)HUDItem->actual_count_pointer);
            } else {
                kong = func_global_asm_806C8DE0(playerIndex);
                levelIndex = getLevelIndex(D_global_asm_8076A0AB, TRUE);
                phi_a2 = 0;
                switch (arg0) {
                    case 0xC:
                        phi_a2 = func_global_asm_80731A04(0x1D5, levelIndex, levelIndex, kong);
                        break;
                    case 0xA:
                        phi_a2 = func_global_asm_80731A04(0x225, levelIndex, levelIndex, kong);
                        break;
                }
            }
            break;
        case 1:
            phi_a2 = 20;
            break;
        case 2:
            break;
    }
    return phi_a2;
}

void func_global_asm_806F8BC4(s32 HUDItemIndex, u8 arg1, s32 arg2) {
    if ((cc_number_of_players < 2) && (!gameIsInDKTVMode())) {
        // TODO: Can this syntax be simplified
        if ((HUDItemIndex != 8) || (func_global_asm_806F8BC4(9, arg1, arg2 + 0xA), (current_map != MAP_SNIDES_HQ))) {
            D_global_asm_80754280->hud_item[HUDItemIndex].unk_24 = arg1;
            if (D_global_asm_80754280->hud_item[HUDItemIndex].hud_state == 0) {
                D_global_asm_80754280->hud_item[HUDItemIndex].counter_timer = arg2;
            } else {
                D_global_asm_80754280->hud_item[HUDItemIndex].counter_timer = 0;
            }
            D_global_asm_80754280->hud_item[HUDItemIndex].hud_state = 1;
            if (D_global_asm_80754280->hud_item[HUDItemIndex].freeze_timer == 0) {
                D_global_asm_80754280->hud_item[HUDItemIndex].freeze_timer = arg1 != 0;
            }
        }
    }
}

void func_global_asm_806F8CB0(s32 HUDItemIndex) {
    s32 phi_v1;
    GlobalASMStruct71 *phi_v0;

    // GB Count (Character)?
    if (HUDItemIndex == 8) {
        phi_v0 = D_global_asm_80754280->hud_item[HUDItemIndex].counter_pointer;
        phi_v1 = 0;
        while (phi_v0) {
            phi_v0->unkC = phi_v1;
            phi_v1 += 2;
            phi_v0 = phi_v0->unk18;
        }
    }
}

void func_global_asm_806F8CFC(s32 HUDItemIndex, s32 arg1) {
    D_global_asm_80754280->hud_item[HUDItemIndex].counter_timer = 0;
    D_global_asm_80754280->hud_item[HUDItemIndex].freeze_timer = 0;
    if (HUDItemIndex == 8) {
        func_global_asm_806F8D58(9, 0);
    }
}

void func_global_asm_806F8D58(s32 HUDItemIndex, s32 arg1) {
    GlobalASMStruct71 *phi_v0 = D_global_asm_80754284;

    D_global_asm_80754280->hud_item[HUDItemIndex].unk_1c = 0;
    while (phi_v0) {
        phi_v0->unk0 &= ~(1 << HUDItemIndex);
        phi_v0 = phi_v0->unk4;
    }
    func_global_asm_806F8CFC(HUDItemIndex, arg1);
}

void func_global_asm_806F8DC4(u8 *arg0, s32 arg1, s32 arg2) {
    s32 levelIndex;
    s32 kongIndex;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, TRUE);
    kongIndex = func_global_asm_806C8DE0(0);
    *arg0 = 0x7F;
    switch (arg2) {
        case 0xC:
            if (func_global_asm_80731A04(0x1D5, levelIndex, levelIndex, kongIndex)) {
                *arg0 = 0xFF;
            }
            break;
        case 0xA:
            if (func_global_asm_80731A04(0x225, levelIndex, levelIndex, kongIndex)) {
                *arg0 = 0xFF;
            }
            break;
        case 8:
            if (arg1 < D_global_asm_807FC950[0].character_progress[kongIndex].golden_bananas[levelIndex]) {
                *arg0 = 0xFF;
            }
            break;
    }
}

s32 func_global_asm_806F8EB4(void) {
    // Count how many fairies have been photographed
    return countSetFlags(PERMFLAG_ITEM_FAIRY_JAPES_POOL, 20, FLAG_TYPE_PERMANENT);
}

// getMaxItemCapacity ?
u16 func_global_asm_806F8EDC(s32 HUDItemIndex, s32 playerIndex) {
    s32 kong;
    u16 var_a0;
    s32 var_v1;
    s32 temp_a0;
    s32 var_v0;

    kong = func_global_asm_806C8DE0(playerIndex);
    var_a0 = 100;
    switch (HUDItemIndex) {
        case 1:
            var_a0 = 999;
            break;
        case 2:
            var_a0 = ((1 << D_global_asm_807FC950[playerIndex].character_progress[kong].ammo_belt) * 50);
            break;
        case 3:
            if (cc_number_of_players >= 2) {
                var_a0 = 10;
            } else {
                var_a0 = ((1 << D_global_asm_807FC950[playerIndex].character_progress[kong].ammo_belt) * 50);
            }
            break;
        case 4:
            var_a0 = ((D_global_asm_807FC950[playerIndex].character_progress[kong].ammo_belt * 5) + 20);
            break;
        case 5:
            if (cc_number_of_players >= 2) {
                var_a0 = 3000;
            } else if (func_global_asm_806F6EDC() != 0) {
                var_a0 = ((func_global_asm_806F8EB4() * 150) + 3000);
            } else {
                var_a0 = 0;
            }
            break;
        case 7:
            if (cc_number_of_players >= 2) {
                var_a0 = 20;
            } else {
                temp_a0 = D_global_asm_807FC950[playerIndex].character_progress[kong].instrument;
                var_v1 = 1;
                if (temp_a0 & 1) {
                    var_v0 = temp_a0;
                    while (var_v0) {
                        var_v1++;
                        var_v0 >>= 1;
                    }
                    var_a0 = (var_v1 * 5);
                } else {
                    var_a0 = 0;
                }
            }
            break;
        case 6:
            if (isFlagSet(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, FLAG_TYPE_PERMANENT)) {
                var_a0 = (func_global_asm_806F8EB4() + 10);
            } else {
                var_a0 = 0;
            }
            break;
        case 9:
            var_a0 = 200;
            break;
    }
    return var_a0;
}

void changeCollectableCount(s32 HUDItemIndex, u8 playerIndex, s16 amount) {
    HUDDisplay *HUDItem;
    CharacterProgress *sp48;
    s32 maxItemCapacity;
    s32 levelIndex;
    s32 flagIndex;
    s32 amountBefore; // 38
    s32 pad;
    s32 pad2;

    sp48 = &D_global_asm_807FC950[playerIndex].character_progress[func_global_asm_806C8DE0(playerIndex)];
    HUDItem = func_global_asm_806F7FD0(playerIndex);
    if (((HUDItem[HUDItemIndex].unk_2d == 0) || (amount >= 0)) && (HUDItem[HUDItemIndex].unk_2c == 0)) {
        if ((HUDItemIndex != 0xA) && (HUDItemIndex != 0xC)) {
            if (((*HUDItem[HUDItemIndex].actual_count_pointer) + amount) < 0) {
                *HUDItem[HUDItemIndex].actual_count_pointer = 0;
            } else {
                *HUDItem[HUDItemIndex].actual_count_pointer += amount;
                maxItemCapacity = func_global_asm_806F8EDC(HUDItemIndex, playerIndex);
                if (maxItemCapacity < (*HUDItem[HUDItemIndex].actual_count_pointer)) {
                    *HUDItem[HUDItemIndex].actual_count_pointer = maxItemCapacity;
                }
                if ((HUDItemIndex == 8) && (func_global_asm_805FEF10(&flagIndex) != 0)) {
                    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
                }
                if ((amount > 0) && (HUDItemIndex == 0)) {
                    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 1);
                    amountBefore = sp48->coloured_bananas[levelIndex] + sp48->coloured_bananas_fed_to_tns[levelIndex];
                    if ((amountBefore >= 75) && ((amountBefore - amount) < 75)) {
                        // Award banana medal
                        setFlag(func_global_asm_807319D8(PERMFLAG_ITEM_MEDAL_JAPES_DK, levelIndex, current_character_index[playerIndex]), TRUE, FLAG_TYPE_PERMANENT);
                        func_global_asm_80687C48();
                    }
                    if ((amountBefore == 100) && ((amountBefore - amount) < 100)) {
                        // Play 100 bananas collected jingle
                        playSong(0xAC, 1.0f);
                    }
                }
            }

            // fake match
            if (0) {
            }
        }
        if (HUDItemIndex == 8) {
            func_global_asm_806F8278(playerIndex);
        }
    }
}

void func_global_asm_806F93EC(u16 *arg0, Maps map) {
    *arg0 |= 1 << getLevelIndex(map, TRUE);
}

void func_global_asm_806F942C(u16 *arg0, Maps map) {
    *arg0 &= ~(1 << getLevelIndex(map, TRUE));
}

u8 func_global_asm_806F9470(u16 arg0, Maps map) {
    return (1 << getLevelIndex(map, 1)) & arg0;
}

void func_global_asm_806F94AC(Struct806F94AC_arg0 *arg0, s32 arg1) {
    f32 temp_f12;
    f32 var_f2;
    f32 temp;
    Struct806F94AC_arg0_unk330 *temp_v0;

    temp = (arg0->unk330->unk9 * arg0->unk330->unkE);
    var_f2 = 32.0f / temp;
    if (arg1 == 9) {
        var_f2 = 32.0f / temp * 1.2;
    }
    arg0->unk360 *= var_f2;
    arg0->unk364 *= var_f2;
}

// TODO: Pretty close... hmm
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F9518.s")

/*
void func_global_asm_806F9518(s32 HUDItemIndex) {
    GlobalASMStruct71 *phi_s1;
    GlobalASMStruct72 **next;

    D_global_asm_80754280->hud_item[HUDItemIndex].hud_state = 0;
    phi_s1 = D_global_asm_80754280->hud_item[HUDItemIndex].counter_pointer;
    while (phi_s1) {
        next = &phi_s1->unk18;
        if (phi_s1->unk0 == 1) {
            func_global_asm_80715908(phi_s1->unk14->unk8);
        }
        free(phi_s1->unk14);
        free(phi_s1);
        phi_s1->unk0 = NULL;
        phi_s1 = *next;
    }
}
*/

void func_global_asm_806F95C8(void) {
    s32 HUDItemIndex;
    for (HUDItemIndex = 0; HUDItemIndex < 15; HUDItemIndex++) {
        func_global_asm_806F9518(HUDItemIndex);
    }
}

void func_global_asm_806F9608(Struct806F9744_arg0 **arg0) {
    *arg0 = malloc(0x1C);
    func_global_asm_80611690(*arg0);
    (*arg0)->unk0 = 1;
    (*arg0)->unk14 = malloc(0xC);
    func_global_asm_80611690((*arg0)->unk14);
}

void func_global_asm_806F966C(Struct806F9744_arg0 **arg0) {
    *arg0 = malloc(0x1C);
    func_global_asm_80611690(*arg0);
    (*arg0)->unk0 = 0;
    (*arg0)->unk14 = malloc(0x88);
    func_global_asm_80611690((*arg0)->unk14);
}

void func_global_asm_806F96CC(GS71_F32 *arg0, u32 arg1) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = 0;
    var_v1 = 0;
    arg0->unkC = 0;
    switch (arg1) {
        case 0:
        case 13:
        case 14:
            var_v0 = -1;
            break;
        case 9:
        case 10:
        case 12:
            var_v1 = 1;
            break;
        default:
            var_v0 = 1;
            break;
    }
    arg0->unk4 = var_v0 * 0x30;
    arg0->unk8 = var_v1 * 0x30;
}

void func_global_asm_806F9744(Struct806F9744_arg0 *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 temp[2]; // TODO: Hmm
    s32 sp2C;
    Struct806F9744_arg0_unk14 *temp_s0;

    temp_s0 = arg0->unk14;
    sp2C = 2;
    func_global_asm_8071495C();
    func_global_asm_807149FC(-1);
    if (arg1 == 0xE) {
        sp2C = 1;
    }
    func_global_asm_80714998(sp2C);
    func_global_asm_80714944(arg4);
    func_global_asm_80714950((s32)arg0);
    func_global_asm_8071498C(func_global_asm_8071BE04);
    func_global_asm_80714A28(0x21);
    if (arg1 == 3) {
        changeActorColor(0xFF, 0, 0, 0xFF);
    }
    temp_s0->unk8 = drawSpriteAtPosition(func_global_asm_806FACE8(arg1), 1.0f, arg2, arg3, -10.0f);
    temp_s0->unk2 = 0;
    if (arg1 == 7) {
        temp_s0->unk4 = 1;
    } else {
        temp_s0->unk4 = 0;
    }
    // TODO: unk8 is otherSpriteControl*?
    func_global_asm_806F94AC(temp_s0->unk8, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F9848.s")

void func_global_asm_806F9AF0(Struct806F9AF0_arg0 *arg0, s8 *arg1) {
    s32 temp = arg0->unk35E;
    if (D_global_asm_807FD7A0[temp] == -200.0f) {
        *arg1 = 1;
        return;
    }
    arg0->unk340 = D_global_asm_807FD7A0[temp];
    arg0->unk344 = D_global_asm_807FD7B8[temp];
    arg0->unk360 = D_global_asm_807FD7D0[temp];
    arg0->unk364 = D_global_asm_807FD7D0[temp];
    D_global_asm_807FD7A0[temp] = -200.0f;
}

extern void *D_global_asm_80750518;

void func_global_asm_806F9B64(s32 arg0) {
    GlobalASMStruct71 **counter;
    GlobalASMStruct71 *previousCounter;
    s32 i;
    void **var_s2;

    // Below is equivalent to &D_global_asm_80754280->hud_item[arg0].counter_pointer
    // but need to change the syntax to fix regalloc.
    counter = &(*(arg0 + D_global_asm_80754280->hud_item)).counter_pointer;
    func_global_asm_806F966C(counter);
    func_global_asm_806F96CC(*counter, 0);
    (*counter)->unk10 = 0;
    previousCounter = (*counter)->unk14;
    previousCounter->unk0 = D_global_asm_80754280->hud_item[arg0].screen_x + 20;
    previousCounter->unk4 = D_global_asm_80754280->hud_item[arg0].screen_y - 20;
    var_s2 = &D_global_asm_80750518;
    for (i = 0; i < 5; i++) {
        func_global_asm_8071495C();
        func_global_asm_807149FC(-1);
        func_global_asm_8071498C(func_global_asm_806F9AF0);
        func_global_asm_80714950(i);
        D_global_asm_807FD7A0[i] = -100.0f;
        drawSpriteAtPosition(var_s2[i], 1.0f, -200.0f, 0.0f, -10.0f);
    }
}

void func_global_asm_806F9CD0(s32 arg0) {
    GlobalASMStruct71 **temp_s0;
    GlobalASMStruct71 *sp30;

    // Below is equivalent to &D_global_asm_80754280->hud_item[arg0].counter_pointer
    // but need to change the syntax to fix regalloc.
    temp_s0 = &(*(arg0 + D_global_asm_80754280->hud_item)).counter_pointer;
    func_global_asm_806F9608(temp_s0);
    sp30 = (*temp_s0)->unk14;
    func_global_asm_806F96CC(*temp_s0, arg0);
    func_global_asm_806F9744(*temp_s0, arg0, D_global_asm_80754280->hud_item[arg0].screen_x, D_global_asm_80754280->hud_item[arg0].screen_y, 0);
    func_global_asm_806F8DC4(sp30, 0, arg0);
    (*temp_s0)->unk10 = 0;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F9D8C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806FA1A4.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void *unk14;
} Struct806FA504_arg1;

Gfx *func_global_asm_806F9D8C(s32, void*, Gfx*);
Gfx *func_global_asm_806FA1A4(s32, void*, Gfx*);

// TODO: Which struct is arg1?
Gfx *func_global_asm_806FA504(s32 arg0, Struct806FA504_arg1 *arg1, s32 arg2, Gfx *dl) {
    if (arg1->unk0 == 0) {
        if (arg0 != 8) {
            dl = func_global_asm_806F9D8C(arg0, arg1, dl);
        } else {
            dl = func_global_asm_806FA1A4(arg0, arg1, dl);
        }
    } else if ((arg0 == 8) || (arg0 == 0xA) || (arg0 == 0xC)) {
        func_global_asm_806F8DC4(arg1->unk14, arg2, arg0);
    }
    return dl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806FA5A4.s")

// TODO: This matches but is ugly, can we minify it somehow
// Ternary doesn't work
s32 func_global_asm_806FA7A4(s32 arg0) {
    s32 phi_v1;

    phi_v1 = 1;
    if (arg0 == 5) {
        phi_v1 = 150;
    }
    return phi_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806FA7BC.s")

Gfx *func_global_asm_806FA9C0(s32 arg0, Gfx *dl) {
    s32 var_a0;
    s32 var_s1;
    s32 var_v1;
    GlobalASMStruct71 *counter;

    counter = D_global_asm_80754280->hud_item[arg0].counter_pointer;
    var_s1 = 0;
    while (counter != NULL) {
        dl = func_global_asm_806FA504(arg0, counter, var_s1, dl);
        if (counter->unk0 == 1) {
            var_s1++;
        }
        counter = counter->unk18;
    }
    if (D_global_asm_80754280->hud_item[arg0].counter_timer != 0) {
        D_global_asm_80754280->hud_item[arg0].counter_timer--;
    } else {
        counter = D_global_asm_80754280->hud_item[arg0].counter_pointer;
        var_v1 = 0;
        var_a0 = 0;
        while (counter != NULL) {
            var_a0++;
            if (counter->unkC != 0) {
                counter->unkC--;
            } else {
                if (counter->unk10 > 0) {
                    counter->unk10 -= 102.4f;
                }
                if (counter->unk10 < 0) {
                    counter->unk10 = 0;
                    var_v1++;
                }
            }
            counter = counter->unk18;
        }
        if (var_a0 == var_v1) {
            D_global_asm_80754280->hud_item[arg0].hud_state = 0;
        }
    }
    return dl;
}

Gfx *func_global_asm_806FAB20(Gfx *dl) {
    s32 HUDItemIndex;

    if (cc_number_of_players >= 2) {
        return dl;
    }
    gDPPipeSync(dl++);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (HUDItemIndex = 0; HUDItemIndex < 0xF; HUDItemIndex++) {
        switch (D_global_asm_80754280->hud_item[HUDItemIndex].hud_state) {
            case 0:
                func_global_asm_806F9518(HUDItemIndex);
                break;
            case 1:
                dl = func_global_asm_806FA5A4(HUDItemIndex, dl);
                break;
            case 2:
                dl = func_global_asm_806FA7BC(HUDItemIndex, dl);
                break;
            case 3:
                dl = func_global_asm_806FA9C0(HUDItemIndex, dl);
                break;
        }
    }
    return dl;
}

void func_global_asm_806FAC64(u8 arg0) {
    D_global_asm_80754280->hud_item[0xD].actual_count_pointer = &D_global_asm_807FC950[0].character_progress[arg0].coloured_bananas_fed_to_tns[getLevelIndex(D_global_asm_8076A0AB, 0)];
    D_global_asm_80754280->hud_item[0xD].hud_count = *D_global_asm_80754280->hud_item[0xD].actual_count_pointer;
    D_global_asm_80754288 = arg0;
}

void *func_global_asm_806FACE8(u32 arg0) {
    void *sprite;
    u32 kong;

    sprite = NULL;
    kong = func_global_asm_806C8DE0(0);
    if (arg0 == 0xD) {
        kong = D_global_asm_80754288;
    }
    switch (arg0) {
        case 0:
        case 13:
            switch (kong) {
                case 1:
                    sprite = &D_global_asm_8072057C;
                    break;
                case 0:
                    sprite = &D_global_asm_807205E8;
                    break;
                case 3:
                    sprite = &D_global_asm_8072060C;
                    break;
                case 2:
                    sprite = &D_global_asm_807205C4;
                    break;
                case 4:
                case 5:
                    sprite = &D_global_asm_807205A0;
                    break;
            }
            break;
        case 6:
            sprite = &D_global_asm_80720488;
            break;
        case 4:
            sprite = &D_global_asm_807204BC;
            break;
        case 2:
        case 3:
            switch (kong) {
                case 1:
                    sprite = &D_global_asm_807200A0;
                    break;
                case 0:
                    sprite = &D_global_asm_807206A8;
                    break;
                case 3:
                    sprite = &D_global_asm_80720854;
                    break;
                case 2:
                    sprite = &D_global_asm_8072029C;
                    break;
                case 4:
                    sprite = &D_global_asm_807201A0;
                    break;
                case 5:
                    sprite = &D_global_asm_80720268;
                    break;
            }
            break;
        case 1:
        case 14:
            switch (kong) {
                case 1:
                    sprite = &D_global_asm_807203B0;
                    break;
                case 0:
                    sprite = &D_global_asm_8072041C;
                    break;
                case 3:
                    sprite = &D_global_asm_80720440;
                    break;
                case 2:
                    sprite = &D_global_asm_807203F8;
                    break;
                case 4:
                case 5:
                    sprite = &D_global_asm_807203D4;
                    break;
            }
            break;
        case 11:
            sprite = &D_global_asm_807207BC;
            break;
        case 7:
            switch (kong) {
                case 1:
                    sprite = &D_global_asm_80720878;
                    break;
                case 0:
                    sprite = &D_global_asm_80720890;
                    break;
                case 3:
                    sprite = &D_global_asm_807208A8;
                    break;
                case 2:
                    sprite = &D_global_asm_807208D8;
                    break;
                case 4:
                case 5:
                    sprite = &D_global_asm_807208C0;
                    break;
            }
            break;
        case 5:
            sprite = &D_global_asm_80720508;
            break;
        case 8:
            sprite = &D_global_asm_8072052C;
            break;
        case 9:
            sprite = &D_global_asm_8072052C;
            break;
        case 10:
            sprite = &D_global_asm_80720558;
            break;
        case 12:
            switch (kong) {
                case 1:
                    sprite = &D_global_asm_807209EC;
                    break;
                case 0:
                    sprite = &D_global_asm_80720A34;
                    break;
                case 3:
                    sprite = &D_global_asm_80720A58;
                    break;
                case 2:
                    sprite = &D_global_asm_807207E0;
                    break;
                case 4:
                case 5:
                    sprite = &D_global_asm_80720A10;
                    break;
            }
            break;
        case 16:
            sprite = &D_global_asm_8072145C;
            break;
        case 17:
            sprite = &D_global_asm_80721250;
            break;
        case 18:
            sprite = &D_global_asm_80721200;
            break;
        case 19:
            sprite = &D_global_asm_8072121C;
            break;
        case 20:
            sprite = &D_global_asm_807214A0;
            break;
        case 21:
            sprite = &D_global_asm_807214B8;
            break;
        case 22:
            sprite = &D_global_asm_807214D0;
            break;
        case 23:
            sprite = &D_global_asm_807214E8;
            break;
        case 24:
            sprite = &D_global_asm_80721500;
            break;
    }
    return sprite;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806FAFE4.s")

void func_global_asm_806FB218(void) {
    s32 i;

    func_global_asm_806FAFE4();
    for (i = 0; i < 0xF; i++) {
        if (D_global_asm_80754280->hud_item[i].freeze_timer != 0) {
            func_global_asm_806F8CFC(i, 0);
        }
    }
}

void func_global_asm_806FB290(void) {
    func_global_asm_806FAFE4();
    func_global_asm_806F95C8();
}

// Quite fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806FB2B8.s")

/*
void func_global_asm_806FB2B8(void) {
    GlobalASMStruct71 **var_s1;
    GlobalASMStruct71 *current;
    s32 i;

    var_s1 = &D_global_asm_80754284;
    current = D_global_asm_80754284;
    if (D_global_asm_80754284) {
        while (current->unk4) {
            var_s1 = &current->unk4;
            current = current->unk4;
        }
        for (i = 0; i != 0xF; i++) {
            if ((*var_s1)->unk0 & (1 << i)) {
                func_global_asm_806F8BC4(i, 1, 0);
            }
        }
        free(*var_s1);
        *var_s1 = NULL;
    }
}
*/

// setHudItemAsInfinite(hudItemIndex, playerIndex, unknownValue)
void func_global_asm_806FB370(u8 HUDItemIndex, u8 playerIndex, u8 arg2) {
    HUDDisplay *temp_v0;

    temp_v0 = &D_global_asm_80754280->hud_item[playerIndex * 0xF + HUDItemIndex];
    if (temp_v0->unk_2d == 0) {
        temp_v0->unk_2c = arg2;
    }
}

u8 func_global_asm_806FB3D0(u8 HUDItemIndex, u8 playerIndex) {
    return D_global_asm_80754280->hud_item[playerIndex * 0xF + HUDItemIndex].unk_2c;
}

s32 func_global_asm_806FB418(void) {
    s32 kongIndex;
    s32 levelIndex;
    s32 GBCount = 0;

    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        for (levelIndex = 0; levelIndex < 8; levelIndex++) {
            GBCount += D_global_asm_807FC950[0].character_progress[kongIndex].golden_bananas[levelIndex];
        }
    }
    return GBCount;
}
