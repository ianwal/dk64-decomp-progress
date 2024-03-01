#include <ultra64.h>
#include "functions.h"

typedef struct global_asm_struct_71 GlobalASMStruct71;

struct global_asm_struct_71 {
    s32 unk0;
    s32 unk4;
    s32 unk8; // Used
    s32 unkC;
    s16 unk10;
    s16 unk12;
    GlobalASMStruct71 *unk14; // Used, prev?
    GlobalASMStruct71 *unk18; // Next?
};

typedef struct HUDDisplay {
	/* 0x000 */ u16* actual_count_pointer;
	/* 0x004 */	u16 hud_count;
	/* 0x006 */	u8 freeze_timer;
	/* 0x007 */	u8 counter_timer;
	/* 0x008 */	s32 screen_x;
	/* 0x00C */	s32 screen_y;
	/* 0x010 */ f32 unk_10;
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ u8 unk_1c;
    /* 0x01D */ u8 unk_1d;
    /* 0x01E */ u8 unk_1e;
    /* 0x01F */ u8 unk_1f;
	/* 0x020 */ u32 hud_state; // 0 = invisible, 1 = appearing, 2 = visible, 3 = disappearing
	/* 0x024 */ s32 unk_24;
	/* 0x028 */	GlobalASMStruct71* counter_pointer;
	/* 0x02C */ u8 unk_2c; // Infinites?
    /* 0x02D */ u8 unk_2d; // Infinites?
    /* 0x02E */ u8 unk_2e;
    /* 0x02F */ u8 unk_2f;
} HUDDisplay;

typedef struct {
    // TODO: Union with friendly field names?
    // TODO: Enum with indexes?
    // 0 = Coloured Banana
    // 1 = Banana Coin
    // 2 = ???
    // 3 = ???
    // 4 = ???
    // 5 = Crystal Coconut
    // 6 = ???
    // 7 = ???
    // 8 = GB Count (Character)
    // 9 = ???
    // 10 = Banana Medal
    // 11 = ???
    // 12 = Blueprint
    // 13 = Coloured Banana?
    // 14 = Banana Coin?
    HUDDisplay hud_item[15];
} PlayerHUD;

extern PlayerHUD *D_global_asm_80754280; // HUD

// rodata
// static const char D_global_asm_8075DA60[] = "o";
// static const char D_global_asm_8075DA64[] = "NA";
// static const char D_global_asm_8075DA68[] = "%d";

PlayerHUD* func_global_asm_806F7FD0(u8 playerIndex) {
    return &D_global_asm_80754280[playerIndex];
}

void func_global_asm_806F8004(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    float sp88[4][4];
    float sp48[4][4];
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 temp_f2_2;
    f32 sp34;

    sp34 = character_change_array[cc_player_index].near;
    guRotateF(&sp88, arg0, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(&sp88, 0.0f, 0.0f, -sp34, &sp3C, &sp40, &sp44);
    guRotateF(&sp48, arg1, 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp48, sp3C, sp40, sp44, arg2, arg3, arg4);
    temp_f2_2 = -sp34 / *arg4;
    *arg2 *= temp_f2_2;
    *arg3 *= temp_f2_2;
    *arg4 = -sp34;
    *arg2 = *arg2 * 10.5;
    *arg3 = *arg3 * 10.5;
    *arg4 = *arg4 * 10.5;
}

void func_global_asm_806F8170(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 temp_v0;

    if (arg0 < 0) {
        func_global_asm_806F8004(16.5f, 0.0f, arg1, arg2, arg3);
        return;
    }
    if (arg0 == 8) {
        func_global_asm_806F8004(1.5 - (D_global_asm_80754280->hud_item[arg0].hud_count * 7), 26.0f, arg1, arg2, arg3);
        return;
    }
    *arg1 = D_global_asm_80754280->hud_item[arg0].unk_10;
    *arg2 = D_global_asm_80754280->hud_item[arg0].unk_14;
    *arg3 = D_global_asm_80754280->hud_item[arg0].unk_18;
}

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F8278.s")

void func_global_asm_806F8278(u8 playerIndex);

/*
void func_global_asm_806F8278(u8 playerIndex) {
    s32 levelIndex;
    s32 totalGBs;
    s32 kong;

    totalGBs = 0;
    for (levelIndex = 0; levelIndex < 14; levelIndex++) {
        for (kong = 0; kong < 5; kong++) {
            totalGBs += D_global_asm_807FC950[playerIndex].character_progress[kong].golden_bananas[levelIndex];
        }
    }
    D_global_asm_80754280->hud_item[playerIndex * 0xF + 9].hud_count = totalGBs;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F833C.s")

void func_global_asm_806F8A8C(u8 arg0, u8 playerIndex, s32 arg2) {
    PlayerHUD* temp = func_global_asm_806F7FD0(playerIndex);
    temp->hud_item[arg0].hud_count = arg2;
}

u16 func_global_asm_806F8AD4(u8 arg0, u8 playerIndex) {
    u16 phi_a2;
    u16 *temp;
    s32 sp1C;
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
                sp1C = func_global_asm_806C8DE0(playerIndex);
                levelIndex = getLevelIndex(D_global_asm_8076A0AB, TRUE);
                phi_a2 = 0;
                switch (arg0) {
                    case 0xC:
                        phi_a2 = func_global_asm_80731A04(0x1D5, levelIndex, levelIndex, sp1C);
                        break;
                    case 0xA:
                        phi_a2 = func_global_asm_80731A04(0x225, levelIndex, levelIndex, sp1C);
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

void func_global_asm_806F8BC4(s32 arg0, u8 arg1, s32 arg2) {
    if ((cc_number_of_players < 2) && (!gameIsInDKTVMode())) {
        // TODO: Can this syntax be simplified
        if ((arg0 != 8) || (func_global_asm_806F8BC4(9, arg1, arg2 + 0xA), (current_map != MAP_SNIDES_HQ))) {
            D_global_asm_80754280->hud_item[arg0].unk_24 = arg1;
            if (D_global_asm_80754280->hud_item[arg0].hud_state == 0) {
                D_global_asm_80754280->hud_item[arg0].counter_timer = arg2;
            } else {
                D_global_asm_80754280->hud_item[arg0].counter_timer = 0;
            }
            D_global_asm_80754280->hud_item[arg0].hud_state = 1;
            if (D_global_asm_80754280->hud_item[arg0].freeze_timer == 0) {
                D_global_asm_80754280->hud_item[arg0].freeze_timer = arg1 != 0;
            }
        }
    }
}

void func_global_asm_806F8CB0(s32 arg0) {
    s32 phi_v1;
    GlobalASMStruct71 *phi_v0;

    // GB Count (Character)?
    if (arg0 == 8) {
        phi_v0 = D_global_asm_80754280->hud_item[arg0].counter_pointer;
        phi_v1 = 0;
        while (phi_v0) {
            phi_v0->unkC = phi_v1;
            phi_v1 += 2;
            phi_v0 = phi_v0->unk18;
        }
    }
}

void func_global_asm_806F8CFC(s32 arg0, s32 arg1) {
    D_global_asm_80754280->hud_item[arg0].counter_timer = 0;
    D_global_asm_80754280->hud_item[arg0].freeze_timer = 0;
    if (arg0 == 8) {
        func_global_asm_806F8D58(9, 0);
    }
}

typedef struct global_asm_struct_72 GlobalASMStruct72;

struct global_asm_struct_72 {
    s32 unk0;
    GlobalASMStruct72 *unk4; // Next?
};

extern GlobalASMStruct71 *D_global_asm_80754284;

void func_global_asm_806F8D58(s32 arg0, s32 arg1) {
    GlobalASMStruct71 *phi_v0 = D_global_asm_80754284;

    D_global_asm_80754280->hud_item[arg0].unk_1c = 0;
    while (phi_v0) {
        phi_v0->unk0 &= ~(1 << arg0);
        phi_v0 = phi_v0->unk4;
    }
    func_global_asm_806F8CFC(arg0, arg1);
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

s32 func_global_asm_806F8EB4() {
    // Count how many fairies have been photographed
    return countSetFlags(0x24D, 20, FLAG_TYPE_PERMANENT);
}

s32 func_global_asm_806C8DE0(s32);

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
            if (isFlagSet(0x179, FLAG_TYPE_PERMANENT)) {
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

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F91B4.s")

/*
void func_global_asm_806F91B4(s32 HUDItemIndex, u8 playerIndex, s16 amount) {
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
    if ((HUDItem[HUDItemIndex].unk_2d == 0 || amount >= 0) && HUDItem[HUDItemIndex].unk_2c == 0) {
        if ((HUDItemIndex != 0xA) && (HUDItemIndex != 0xC)) {
            if ((*HUDItem[HUDItemIndex].actual_count_pointer + amount) < 0) {
                *HUDItem[HUDItemIndex].actual_count_pointer = 0;
            } else {
                *HUDItem[HUDItemIndex].actual_count_pointer += amount;
                // getMaxItemCapacity(HUDItemIndex, playerIndex)
                maxItemCapacity = func_global_asm_806F8EDC(HUDItemIndex, playerIndex);
                if (maxItemCapacity < *HUDItem[HUDItemIndex].actual_count_pointer) {
                    *HUDItem[HUDItemIndex].actual_count_pointer = maxItemCapacity;
                }
                if (HUDItemIndex == 8 && (func_global_asm_805FEF10(&flagIndex) != 0)) {
                    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
                }
                if (amount > 0 && HUDItemIndex == 0) {
                    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 1);
                    amountBefore = sp48->coloured_bananas[levelIndex] + sp48->coloured_bananas_fed_to_tns[levelIndex];
                    if (amountBefore >= 75 && ((amountBefore - amount) < 75)) {
                        // Award banana medal
                        setFlag(func_global_asm_807319D8(0x225, levelIndex, current_character_index[playerIndex]), TRUE, FLAG_TYPE_PERMANENT);
                        func_global_asm_80687C48();
                    }
                    if (amountBefore == 100 && (amountBefore - amount) < 100) {
                        // Play 100 bananas collected jingle
                        playSong(0xAC, 1.0f);
                    }
                }
            }
        }
        if (HUDItemIndex == 8) {
            func_global_asm_806F8278(playerIndex);
        }
    }
}
*/

void func_global_asm_806F93EC(u16 *arg0, Maps map) {
    *arg0 |= 1 << getLevelIndex(map, TRUE);
}

void func_global_asm_806F942C(u16 *arg0, Maps map) {
    *arg0 &= ~(1 << getLevelIndex(map, TRUE));
}

u8 func_global_asm_806F9470(u16 arg0, Maps map) {
    return (1 << getLevelIndex(map, 1)) & arg0;
}

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F9518.s")

/*
// TODO: Pretty close... hmm
void func_global_asm_806F9518(s32 arg0) {
    GlobalASMStruct71 *phi_s1;
    GlobalASMStruct72 **next;

    D_global_asm_80754280->hud_item[arg0].hud_state = 0;
    phi_s1 = D_global_asm_80754280->hud_item[arg0].counter_pointer;
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
    s32 i;
    for (i = 0; i < 15; i++) {
        func_global_asm_806F9518(i);
    }
}

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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F96CC.s")

int func_global_asm_8071BE04(); // TODO: Signature

void *func_global_asm_806FACE8(u32 arg0);

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
    func_global_asm_80714950(arg0);
    func_global_asm_8071498C(&func_global_asm_8071BE04);
    func_global_asm_80714A28(0x21);
    if (arg1 == 3) {
        func_global_asm_807149C8(0xFF, 0, 0, 0xFF);
    }
    temp_s0->unk8 = func_global_asm_80714CC0(func_global_asm_806FACE8(arg1), 1.0f, arg2, arg3, -10.0f);
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

extern f32 D_global_asm_807FD7A0[];
extern f32 D_global_asm_807FD7B8[];
extern f32 D_global_asm_807FD7D0[];

typedef struct {
    u8 unk0[0x340 - 0x0];
    f32 unk340;
    f32 unk344;
    u8 unk348[0x35E - 0x348];
    s16 unk35E;
    f32 unk360;
    f32 unk364;
} Struct806F9AF0_arg0;

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F9B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806F9CD0.s")

/*
// TODO: Very close, registers the wrong way round in an addu
void func_global_asm_806F9CD0(s32 arg0) {
    GlobalASMStruct71 **temp_s0;
    GlobalASMStruct71 *sp30;

    temp_s0 = &D_global_asm_80754280->hud_item[arg0].counter_pointer;
    func_global_asm_806F9608(temp_s0);
    sp30 = (*temp_s0)->unk14;
    func_global_asm_806F96CC(*temp_s0, arg0);
    func_global_asm_806F9744(*temp_s0, arg0, D_global_asm_80754280->hud_item[arg0].screen_x, D_global_asm_80754280->hud_item[arg0].screen_y, 0);
    func_global_asm_806F8DC4(sp30, 0, arg0);
    (*temp_s0)->unk10 = 0;
}
*/

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

// TODO: Which struct is arg1?
s32 func_global_asm_806FA504(s32 arg0, Struct806FA504_arg1 *arg1, s32 arg2, s32 arg3) {
    if (arg1->unk0 == 0) {
        if (arg0 != 8) {
            arg3 = func_global_asm_806F9D8C(arg0, arg1, arg3);
        } else {
            arg3 = func_global_asm_806FA1A4(arg0, arg1, arg3);
        }
    } else if ((arg0 == 8) || (arg0 == 0xA) || (arg0 == 0xC)) {
        func_global_asm_806F8DC4(arg1->unk14, arg2, arg0);
    }
    return arg3;
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

s32 func_global_asm_806FA9C0(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s1;
    s32 var_v1;
    GlobalASMStruct71 *counter;

    counter = D_global_asm_80754280->hud_item[arg0].counter_pointer;
    var_s1 = 0;
    while (counter != NULL) {
        arg1 = func_global_asm_806FA504(arg0, counter, var_s1, arg1);
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
    return arg1;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_global_asm_806FAB20.s")

extern s32 D_global_asm_80754288;

void func_global_asm_806FAC64(u8 arg0) {
    D_global_asm_80754280->hud_item[0xD].actual_count_pointer = &D_global_asm_807FC950[0].character_progress[arg0].coloured_bananas_fed_to_tns[getLevelIndex(D_global_asm_8076A0AB, 0)];
    D_global_asm_80754280->hud_item[0xD].hud_count = *D_global_asm_80754280->hud_item[0xD].actual_count_pointer;
    D_global_asm_80754288 = arg0;
}

// These are sprite textures
// TODO: Label them appropriately
extern s32 D_global_asm_807200A0;
extern s32 D_global_asm_807201A0;
extern s32 D_global_asm_80720268;
extern s32 D_global_asm_8072029C;
extern s32 D_global_asm_807203B0;
extern s32 D_global_asm_807203D4;
extern s32 D_global_asm_807203F8;
extern s32 D_global_asm_8072041C;
extern s32 D_global_asm_80720440;
extern s32 D_global_asm_80720488;
extern s32 D_global_asm_807204BC;
extern s32 D_global_asm_80720508;
extern s32 D_global_asm_8072052C;
extern s32 D_global_asm_80720558;
extern s32 D_global_asm_8072057C;
extern s32 D_global_asm_807205A0;
extern s32 D_global_asm_807205C4;
extern s32 D_global_asm_807205E8;
extern s32 D_global_asm_8072060C;
extern s32 D_global_asm_807206A8;
extern s32 D_global_asm_807207BC;
extern s32 D_global_asm_807207E0;
extern s32 D_global_asm_80720854;
extern s32 D_global_asm_80720878;
extern s32 D_global_asm_80720890;
extern s32 D_global_asm_807208A8;
extern s32 D_global_asm_807208C0;
extern s32 D_global_asm_807208D8;
extern s32 D_global_asm_807209EC;
extern s32 D_global_asm_80720A10;
extern s32 D_global_asm_80720A34;
extern s32 D_global_asm_80720A58;
extern s32 D_global_asm_80721200;
extern s32 D_global_asm_8072121C;
extern s32 D_global_asm_80721250;
extern s32 D_global_asm_8072145C;
extern s32 D_global_asm_807214A0;
extern s32 D_global_asm_807214B8;
extern s32 D_global_asm_807214D0;
extern s32 D_global_asm_807214E8;
extern s32 D_global_asm_80721500;

void *func_global_asm_806FACE8(u32 arg0) {
    void *var_v1;
    u32 kong;

    var_v1 = NULL;
    kong = func_global_asm_806C8DE0(0);
    if (arg0 == 0xD) {
        kong = D_global_asm_80754288;
    }
    switch (arg0) {
        case 0:
        case 13:
            switch (kong) {
                case 1:
                    var_v1 = &D_global_asm_8072057C;
                    break;
                case 0:
                    var_v1 = &D_global_asm_807205E8;
                    break;
                case 3:
                    var_v1 = &D_global_asm_8072060C;
                    break;
                case 2:
                    var_v1 = &D_global_asm_807205C4;
                    break;
                case 4:
                case 5:
                    var_v1 = &D_global_asm_807205A0;
                    break;
            }
            break;
        case 6:
            var_v1 = &D_global_asm_80720488;
            break;
        case 4:
            var_v1 = &D_global_asm_807204BC;
            break;
        case 2:
        case 3:
            switch (kong) {
                case 1:
                    var_v1 = &D_global_asm_807200A0;
                    break;
                case 0:
                    var_v1 = &D_global_asm_807206A8;
                    break;
                case 3:
                    var_v1 = &D_global_asm_80720854;
                    break;
                case 2:
                    var_v1 = &D_global_asm_8072029C;
                    break;
                case 4:
                    var_v1 = &D_global_asm_807201A0;
                    break;
                case 5:
                    var_v1 = &D_global_asm_80720268;
                    break;
            }
            break;
        case 1:
        case 14:
            switch (kong) {
                case 1:
                    var_v1 = &D_global_asm_807203B0;
                    break;
                case 0:
                    var_v1 = &D_global_asm_8072041C;
                    break;
                case 3:
                    var_v1 = &D_global_asm_80720440;
                    break;
                case 2:
                    var_v1 = &D_global_asm_807203F8;
                    break;
                case 4:
                case 5:
                    var_v1 = &D_global_asm_807203D4;
                    break;
            }
            break;
        case 11:
            var_v1 = &D_global_asm_807207BC;
            break;
        case 7:
            switch (kong) {
                case 1:
                    var_v1 = &D_global_asm_80720878;
                    break;
                case 0:
                    var_v1 = &D_global_asm_80720890;
                    break;
                case 3:
                    var_v1 = &D_global_asm_807208A8;
                    break;
                case 2:
                    var_v1 = &D_global_asm_807208D8;
                    break;
                case 4:
                case 5:
                    var_v1 = &D_global_asm_807208C0;
                    break;
            }
            break;
        case 5:
            var_v1 = &D_global_asm_80720508;
            break;
        case 8:
            var_v1 = &D_global_asm_8072052C;
            break;
        case 9:
            var_v1 = &D_global_asm_8072052C;
            break;
        case 10:
            var_v1 = &D_global_asm_80720558;
            break;
        case 12:
            switch (kong) {
                case 1:
                    var_v1 = &D_global_asm_807209EC;
                    break;
                case 0:
                    var_v1 = &D_global_asm_80720A34;
                    break;
                case 3:
                    var_v1 = &D_global_asm_80720A58;
                    break;
                case 2:
                    var_v1 = &D_global_asm_807207E0;
                    break;
                case 4:
                case 5:
                    var_v1 = &D_global_asm_80720A10;
                    break;
            }
            break;
        case 16:
            var_v1 = &D_global_asm_8072145C;
            break;
        case 17:
            var_v1 = &D_global_asm_80721250;
            break;
        case 18:
            var_v1 = &D_global_asm_80721200;
            break;
        case 19:
            var_v1 = &D_global_asm_8072121C;
            break;
        case 20:
            var_v1 = &D_global_asm_807214A0;
            break;
        case 21:
            var_v1 = &D_global_asm_807214B8;
            break;
        case 22:
            var_v1 = &D_global_asm_807214D0;
            break;
        case 23:
            var_v1 = &D_global_asm_807214E8;
            break;
        case 24:
            var_v1 = &D_global_asm_80721500;
            break;
    }
    return var_v1;
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

void func_global_asm_806FB290() {
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
