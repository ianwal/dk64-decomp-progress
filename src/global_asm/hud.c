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
	/* 0x007 */	s8 counter_timer;
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

extern PlayerHUD *D_80754280; // HUD

PlayerHUD* func_806F7FD0(u8 playerIndex) {
    return &D_80754280[playerIndex];
}

void func_806F8004(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
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

void func_806F8170(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 temp_v0;

    if (arg0 < 0) {
        func_806F8004(16.5f, 0.0f, arg1, arg2, arg3);
        return;
    }
    if (arg0 == 8) {
        func_806F8004(1.5 - (D_80754280->hud_item[arg0].hud_count * 7), 26.0f, arg1, arg2, arg3);
        return;
    }
    *arg1 = D_80754280[0].hud_item[arg0].unk_10;
    *arg2 = D_80754280[0].hud_item[arg0].unk_14;
    *arg3 = D_80754280[0].hud_item[arg0].unk_18;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F8278.s")

/*
// TODO: Not sure why this doesn't match
// Similar mismatch to func_806FB370, and func_806FB3D0
void func_806F8278(u8 playerIndex) {
    s32 levelIndex;
    s32 totalGBs;
    s32 kong;

    totalGBs = 0;
    for (levelIndex = 0; levelIndex < 14; levelIndex++) {
        for (kong = 0; kong < 5; kong++) {
            totalGBs += D_807FC950[playerIndex].character_progress[kong].golden_bananas[levelIndex];
        }
    }
    D_80754280[playerIndex].hud_item[9].hud_count = totalGBs;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F833C.s")

void func_806F8A8C(u8 arg0, u8 playerIndex, s32 arg2) {
    PlayerHUD* temp = func_806F7FD0(playerIndex);
    temp->hud_item[arg0].hud_count = arg2;
}

u16 func_806F8AD4(u8 arg0, u8 playerIndex) {
    u16 phi_a2;
    u16 *temp;
    s32 sp1C;
    HUDDisplay *HUDItem;
    s32 levelIndex;

    phi_a2 = 0;
    HUDItem = &func_806F7FD0(playerIndex)->hud_item[arg0];
    switch (HUDItem->unk_2c) {
        case 0:
            // Astonishing...
            temp = HUDItem->actual_count_pointer;
            if (temp) {
                phi_a2 = *((u16*)HUDItem->actual_count_pointer);
            } else {
                sp1C = func_806C8DE0(playerIndex);
                levelIndex = getLevelIndex(D_8076A0AB, TRUE);
                phi_a2 = 0;
                switch (arg0) {
                    case 0xC:
                        phi_a2 = func_80731A04(0x1D5, levelIndex, levelIndex, sp1C);
                        break;
                    case 0xA:
                        phi_a2 = func_80731A04(0x225, levelIndex, levelIndex, sp1C);
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

void func_806F8BC4(s32 arg0, u8 arg1, s32 arg2) {
    if ((cc_number_of_players < 2) && (!gameIsInDKTVMode())) {
        // TODO: Can this syntax be simplified
        if ((arg0 != 8) || (func_806F8BC4(9, arg1, arg2 + 0xA), (current_map != MAP_SNIDES_HQ))) {
            D_80754280[0].hud_item[arg0].unk_24 = arg1;
            if (D_80754280[0].hud_item[arg0].hud_state == 0) {
                D_80754280[0].hud_item[arg0].counter_timer = arg2;
            } else {
                D_80754280[0].hud_item[arg0].counter_timer = 0;
            }
            D_80754280[0].hud_item[arg0].hud_state = 1;
            if (D_80754280[0].hud_item[arg0].freeze_timer == 0) {
                D_80754280[0].hud_item[arg0].freeze_timer = arg1 != 0;
            }
        }
    }
}

void func_806F8CB0(s32 arg0) {
    s32 phi_v1;
    GlobalASMStruct71 *phi_v0;

    // GB Count (Character)?
    if (arg0 == 8) {
        phi_v0 = D_80754280[0].hud_item[arg0].counter_pointer;
        phi_v1 = 0;
        while (phi_v0) {
            phi_v0->unkC = phi_v1;
            phi_v1 += 2;
            phi_v0 = phi_v0->unk18;
        }
    }
}

void func_806F8CFC(s32 arg0, s32 arg1) {
    D_80754280[0].hud_item[arg0].counter_timer = 0;
    D_80754280[0].hud_item[arg0].freeze_timer = 0;
    if (arg0 == 8) {
        func_806F8D58(9, 0);
    }
}

typedef struct global_asm_struct_72 GlobalASMStruct72;

struct global_asm_struct_72 {
    s32 unk0;
    GlobalASMStruct72 *unk4; // Next?
};

extern GlobalASMStruct71 *D_80754284;

void func_806F8D58(s32 arg0, s32 arg1) {
    GlobalASMStruct71 *phi_v0 = D_80754284;

    D_80754280->hud_item[arg0].unk_1c = 0;
    while (phi_v0) {
        phi_v0->unk0 &= ~(1 << arg0);
        phi_v0 = phi_v0->unk4;
    }
    func_806F8CFC(arg0, arg1);
}

void func_806F8DC4(u8 *arg0, s32 arg1, s32 arg2) {
    s32 levelIndex;
    s32 kongIndex;

    levelIndex = getLevelIndex(D_8076A0AB, TRUE);
    kongIndex = func_806C8DE0(0);
    *arg0 = 0x7F;
    switch (arg2) {
        case 0xC:
            if (func_80731A04(0x1D5, levelIndex, levelIndex, kongIndex)) {
                *arg0 = 0xFF;
            }
            break;
        case 0xA:
            if (func_80731A04(0x225, levelIndex, levelIndex, kongIndex)) {
                *arg0 = 0xFF;
            }
            break;
        case 8:
            if (arg1 < D_807FC950[0].character_progress[kongIndex].golden_bananas[levelIndex]) {
                *arg0 = 0xFF;
            }
            break;
    }
}

s32 func_806F8EB4() {
    // Count how many fairies have been photographed
    return func_80731AA8(0x24D, 20, FLAG_TYPE_PERMANENT);
}

// Jumptable, getMaxItemCapacity(HUDItemIndex, playerIndex)
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F8EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F91B4.s")

/*
// TODO: Very close :eyes:
void func_806F91B4(s32 HUDItemIndex, u8 playerIndex, s16 amount) {
    s32 flagIndex;
    CharacterProgress *sp48;
    HUDDisplay *HUDItem;
    PlayerHUD *playerHUD;
    s32 amountBefore;
    s32 maxItemCapacity;
    u8 levelIndex;
    u16 *temp_v1;

    sp48 = &D_807FC950[playerIndex].character_progress[func_806C8DE0(playerIndex)];
    playerHUD = func_806F7FD0(playerIndex);
    HUDItem = &playerHUD->hud_item[HUDItemIndex];
    if ((HUDItem->unk_2d == 0 || amount >= 0) && HUDItem->unk_2c == 0) {
        if ((HUDItemIndex != 0xA) && (HUDItemIndex != 0xC)) {
            if ((*HUDItem->actual_count_pointer + amount) < 0) {
                *HUDItem->actual_count_pointer = 0;
            } else {
                *HUDItem->actual_count_pointer += amount;
                // getMaxItemCapacity(HUDItemIndex, playerIndex)
                maxItemCapacity = func_806F8EDC(HUDItemIndex, playerIndex);
                if (maxItemCapacity < *HUDItem->actual_count_pointer) {
                    *HUDItem->actual_count_pointer = maxItemCapacity;
                }
                if (HUDItemIndex == 8 && (func_805FEF10(&flagIndex) != 0)) {
                    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
                }
                if (amount > 0 && HUDItemIndex == 0) {
                    levelIndex = getLevelIndex(D_8076A0AB, 1);
                    amountBefore = sp48->coloured_bananas[levelIndex] + sp48->coloured_bananas_fed_to_tns[levelIndex];
                    if (amountBefore >= 75 && ((amountBefore - amount) < 75)) {
                        // Award banana medal
                        setFlag(func_807319D8(0x225, levelIndex, current_character_index[playerIndex]), TRUE, FLAG_TYPE_PERMANENT);
                        func_80687C48();
                    }
                    if (amountBefore == 100 && (amountBefore - amount) < 100) {
                        // Play 100 bananas collected jingle
                        playSong(0xAC, 1.0f);
                    }
                }
            }
        }
        if (HUDItemIndex == 8) {
            func_806F8278(playerIndex);
        }
    }
}
*/

void func_806F93EC(u16 *arg0, Maps map) {
    *arg0 |= 1 << getLevelIndex(map, TRUE);
}

void func_806F942C(u16 *arg0, Maps map) {
    *arg0 &= ~(1 << getLevelIndex(map, TRUE));
}

u8 func_806F9470(u16 arg0, Maps map) {
    return (1 << getLevelIndex(map, 1)) & arg0;
}

extern f64 D_8075DAD0;

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

void func_806F94AC(Struct806F94AC_arg0 *arg0, s32 arg1) {
    f32 temp_f12;
    f32 var_f2;
    f32 temp;
    Struct806F94AC_arg0_unk330 *temp_v0;

    temp = (arg0->unk330->unk9 * arg0->unk330->unkE);
    var_f2 = 32.0f / temp;
    if (arg1 == 9) {
        var_f2 = 32.0f / temp * D_8075DAD0;
    }
    arg0->unk360 *= var_f2;
    arg0->unk364 *= var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F9518.s")

/*
// TODO: Pretty close... hmm
void func_806F9518(s32 arg0) {
    GlobalASMStruct71 *phi_s1;
    GlobalASMStruct72 **next;

    D_80754280[0].hud_item[arg0].hud_state = 0;
    phi_s1 = D_80754280[0].hud_item[arg0].counter_pointer;
    while (phi_s1) {
        next = &phi_s1->unk18;
        if (phi_s1->unk0 == 1) {
            func_80715908(phi_s1->unk14->unk8);
        }
        func_8061130C(phi_s1->unk14);
        func_8061130C(phi_s1);
        phi_s1->unk0 = NULL;
        phi_s1 = *next;
    }
}
*/

void func_806F95C8(void) {
    s32 i;
    for (i = 0; i < 15; i++) {
        func_806F9518(i);
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

void func_806F9608(Struct806F9744_arg0 **arg0) {
    *arg0 = malloc(0x1C);
    func_80611690(*arg0);
    (*arg0)->unk0 = 1;
    (*arg0)->unk14 = malloc(0xC);
    func_80611690((*arg0)->unk14);
}

void func_806F966C(Struct806F9744_arg0 **arg0) {
    *arg0 = malloc(0x1C);
    func_80611690(*arg0);
    (*arg0)->unk0 = 0;
    (*arg0)->unk14 = malloc(0x88);
    func_80611690((*arg0)->unk14);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F96CC.s")

int func_8071BE04(); // TODO: Signature

void func_806F9744(Struct806F9744_arg0 *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 temp[2]; // TODO: Hmm
    s32 sp2C;
    Struct806F9744_arg0_unk14 *temp_s0;

    temp_s0 = arg0->unk14;
    sp2C = 2;
    func_8071495C();
    func_807149FC(-1);
    if (arg1 == 0xE) {
        sp2C = 1;
    }
    func_80714998(sp2C);
    func_80714944(arg4);
    func_80714950(arg0);
    func_8071498C(&func_8071BE04);
    func_80714A28(0x21);
    if (arg1 == 3) {
        func_807149C8(0xFF, 0, 0, 0xFF);
    }
    temp_s0->unk8 = func_80714CC0(func_806FACE8(arg1), 1.0f, arg2, arg3, -10.0f);
    temp_s0->unk2 = 0;
    if (arg1 == 7) {
        temp_s0->unk4 = 1;
    } else {
        temp_s0->unk4 = 0;
    }
    // TODO: unk8 is otherSpriteControl*?
    func_806F94AC(temp_s0->unk8, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F9848.s")

extern f32 D_807FD7A0[];
extern f32 D_807FD7B8[];
extern f32 D_807FD7D0[];

typedef struct {
    u8 unk0[0x340 - 0x0];
    f32 unk340;
    f32 unk344;
    u8 unk348[0x35E - 0x348];
    s16 unk35E;
    f32 unk360;
    f32 unk364;
} Struct806F9AF0_arg0;

void func_806F9AF0(Struct806F9AF0_arg0 *arg0, s8 *arg1) {
    s32 temp = arg0->unk35E;
    if (D_807FD7A0[temp] == -200.0f) {
        *arg1 = 1;
        return;
    }
    arg0->unk340 = D_807FD7A0[temp];
    arg0->unk344 = D_807FD7B8[temp];
    arg0->unk360 = D_807FD7D0[temp];
    arg0->unk364 = D_807FD7D0[temp];
    D_807FD7A0[temp] = -200.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F9B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F9CD0.s")

/*
// TODO: Very close, registers the wrong way round in an addu
void func_806F9CD0(s32 arg0) {
    GlobalASMStruct71 **temp_s0;
    GlobalASMStruct71 *sp30;

    temp_s0 = &D_80754280[0].hud_item[arg0].counter_pointer;
    func_806F9608(temp_s0);
    sp30 = (*temp_s0)->unk14;
    func_806F96CC(*temp_s0, arg0);
    func_806F9744(*temp_s0, arg0, D_80754280[0].hud_item[arg0].screen_x, D_80754280[0].hud_item[arg0].screen_y, 0);
    func_806F8DC4(sp30, 0, arg0);
    (*temp_s0)->unk10 = 0;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806F9D8C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FA1A4.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void *unk14;
} Struct806FA504_arg1;

// TODO: Which struct is arg1?
s32 func_806FA504(s32 arg0, Struct806FA504_arg1 *arg1, s32 arg2, s32 arg3) {
    if (arg1->unk0 == 0) {
        if (arg0 != 8) {
            arg3 = func_806F9D8C(arg0, arg1, arg3);
        } else {
            arg3 = func_806FA1A4(arg0, arg1, arg3);
        }
    } else if ((arg0 == 8) || (arg0 == 0xA) || (arg0 == 0xC)) {
        func_806F8DC4(arg1->unk14, arg2, arg0);
    }
    return arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FA5A4.s")

// TODO: This matches but is ugly, can we minify it somehow
// Ternary doesn't work
s32 func_806FA7A4(s32 arg0) {
    s32 phi_v1;

    phi_v1 = 1;
    if (arg0 == 5) {
        phi_v1 = 150;
    }
    return phi_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FA7BC.s")

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FA9C0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FAB20.s")

extern s32 D_80754288;

void func_806FAC64(u8 arg0) {
    D_80754280[0].hud_item[0xD].actual_count_pointer = &D_807FC950[0].character_progress[arg0].coloured_bananas_fed_to_tns[getLevelIndex(D_8076A0AB, 0)];
    D_80754280[0].hud_item[0xD].hud_count = *D_80754280[0].hud_item[0xD].actual_count_pointer;
    D_80754288 = arg0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FACE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FAFE4.s")

void func_806FB218(void) {
    s32 i;

    func_806FAFE4();
    for (i = 0; i < 0xF; i++) {
        if (D_80754280[0].hud_item[i].freeze_timer != 0) {
            func_806F8CFC(i, 0);
        }
    }
}

void func_806FB290() {
    func_806FAFE4();
    func_806F95C8();
}

// Quite fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FB2B8.s")

// setHudItemAsInfinite(hudItemIndex, playerIndex, unknownValue)
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FB370.s")

/*
// TODO: Something up with datatypes or struct sizes?
// Similar mismatch to func_806F8278, and func_806FB3D0
void func_806FB370(u8 HUDItemIndex, u8 playerIndex, u8 arg2) {
    HUDDisplay *temp_v0;

    temp_v0 = &D_80754280[playerIndex].hud_item[HUDItemIndex];
    if (temp_v0->unk_2d == 0) {
        temp_v0->unk_2c = arg2;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/hud/func_806FB3D0.s")

/*
// TODO: Same deal as above
u8 func_806FB3D0(u8 HUDItemIndex, u8 playerIndex) {
    return D_80754280[playerIndex].hud_item[HUDItemIndex].unk_2c;
}
*/

s32 func_806FB418(void) {
    s32 kongIndex;
    s32 levelIndex;
    s32 GBCount = 0;

    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        for (levelIndex = 0; levelIndex < 8; levelIndex++) {
            GBCount += D_807FC950[0].character_progress[kongIndex].golden_bananas[levelIndex];
        }
    }
    return GBCount;
}
