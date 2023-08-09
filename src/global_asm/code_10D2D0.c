#include <ultra64.h>
#include "functions.h"


// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_global_asm_807085D0.s")

typedef struct global_asm_struct_21 {
    f32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
} GlobalASMStruct21;

void func_global_asm_80708BB8(GlobalASMStruct21 *arg0) {
    if ((D_global_asm_807FBB64 & 0x800)) {
        arg0->unk6 = 0x20;
    } else {
        arg0->unk6 = 1;
    }
    if (gameIsInDKTVMode()) {
        arg0->unk6 = 0x20;
    }
    arg0->unkA = 0;
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unk0 = 4.0f;
}

void func_global_asm_80708C24(s32 arg0, CharacterChange *arg1, PlayerProgress *arg2, s32 arg3);

// regalloc, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_global_asm_80708C24.s")

void func_multiplayer_80026B0C(s32);
s32 func_global_asm_8070943C();

/*
void func_global_asm_80708C24(s32 arg0, CharacterChange *arg1, PlayerProgress *arg2, s32 arg3) {
    s32 pad2;
    s32 pad3;
    s32 segmentsPerMelon;
    u32 sp28;

    sp28 = (u8)arg1->unk2E2;
    if ((arg1->unk2E2 & 0x10)) {
        arg1->unk2E2 = arg1->unk2E2 ^ 0x10;
        if (arg2->unk2FD > 0) {
            segmentsPerMelon = func_global_asm_8070943C();
            arg2->health = MIN(arg2->health + arg2->unk2FD, arg2->melons * segmentsPerMelon);
        } else if (arg2->unk2FD < 0) {
            if (gameIsInAdventureMode() || gameIsInMysteryMenuMinigameMode()) {
                arg2->health += arg2->unk2FD;
            }
            if (arg2->health <= 0) {
                arg2->health = 0;
                arg1->unk2E6 = 0xC;
                if (cc_number_of_players >= 2) {
                    func_multiplayer_80026B0C(arg0);
                }
            } else {
                playSound(0x24B, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
        }
        arg2->unk2FD = 0;
    }
    if ((!(global_properties_bitfield & 2) && func_global_asm_805FCA64()) || (sp28 & 0x80)) {
        arg1->unk2E5--;
        if (arg1->unk2E5 == 0) {
            arg1->unk2E5 = 0x11;
            arg1->unk2E4 = 3;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_global_asm_80708DA4.s")

s32 func_global_asm_806C8DE0(s16);
s32 func_global_asm_807085D0(s32, PlayerProgress *, CharacterProgress *, void *);
extern f64 D_global_asm_8075E408;
extern f64 D_global_asm_8075E410;
extern f64 D_global_asm_8075E418;
extern f64 D_global_asm_8075E420;

s16 func_global_asm_80708DA4(s32 arg0, s16 arg1, CharacterChange* arg2);

/*
s16 func_global_asm_80708DA4(s32 arg0, s16 arg1, CharacterChange* arg2) {
    CharacterProgress *sp38;
    PlayerProgress *sp28;
    s32 temp_a0;
    u16 temp_t3_3;
    u8 var_t0;

    sp38 = &D_global_asm_807FC950[arg1].character_progress[func_global_asm_806C8DE0(arg1)];
    sp28 = &D_global_asm_807FC950[arg1];
    temp_a0 = cc_number_of_players == 1;
    var_t0 = arg2->unk2E4;
    if (temp_a0 == 0) {
        var_t0 = 0;
    }
    if (temp_a0 == 0) {
        func_global_asm_80708C24(arg1, arg2, sp28, sp38);
        arg2->unk2E2 &= 0xFFEA;
    }
    if ((u8)arg2->unk2E2 & 0x10) {
        switch (var_t0) {
            case 2:
                arg2->unk2E5 = 0x32;
                break;
            case 3:
                arg2->unk2E5 = 18.0 - arg2->unk2E5;
                arg2->unk2E4 = 1;
                break;
        }
    }
    if ((u8)arg2->unk2E2 & 1) {
        arg2->unk2E2 = arg2->unk2E2 ^ 1;
        switch (var_t0) {
            case 1:
                break;
            case 0:
                arg2->unk2E5 = 0x12;
                arg2->unk2E4 = 1;
                break;
            case 3:
                arg2->unk2E5 = 18.0 - arg2->unk2E5;
                arg2->unk2E4 = 1;
                break;
        }
    } else if ((u8)arg2->unk2E2 & 4) {
        arg2->unk2E5 = 1;
        arg2->unk2E4 = 2;
        temp_t3_3 = arg2->unk2E2 ^ 4;
        arg2->unk2E2 = temp_t3_3;
        arg2->unk2E2 = temp_t3_3 & 8;
    } else {
        switch (var_t0) {
            case 1:
                arg2->unk2E0 = func_global_asm_80612D1C(((arg2->unk2E5 / 18.0) * D_global_asm_8075E408) + D_global_asm_8075E408) * D_global_asm_8075E410;
                if (arg2->unk2E5-- == 0) {
                    arg2->unk2E4 = 2;
                    arg2->unk2E5 = 0x32;
                }
                break;
            case 2:
                func_global_asm_80708C24(arg1, arg2, sp28, sp38);
                break;
            case 3:
                arg2->unk2E0 = func_global_asm_80612D1C((D_global_asm_8075E418 - ((arg2->unk2E5 / 18.0) * D_global_asm_8075E418)) + D_global_asm_8075E418) * D_global_asm_8075E420;
                if (arg2->unk2E5-- == 0) {
                    arg2->unk2E4 = 0;
                }
                break;
        }
    }
    if (func_global_asm_805FCA64() || (arg2->unk2E2 & 0x80)) {
        if (arg2->unk2E4 != 0 || arg2->unk2E2 != 0) {
            arg0 = func_global_asm_807085D0(arg0, sp28, sp38, arg2);
        }
    }
    return arg0;
}
*/

extern s8 D_global_asm_80744504;

s32 func_global_asm_80709344(s32 arg0) {
    s16 i;
    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist) {
            if (!(character_change_array[i].unk2E2 & 0x20)
            && (((character_change_array[i].unk2E4
                || character_change_array[i].unk2E2)
                && (D_global_asm_80744504 == 0))
                || (character_change_array[i].unk2E2 & 0x10))) {
                arg0 = func_global_asm_80708DA4(arg0, i, &character_change_array[i]);
            }
        }
    }
    return arg0;
}

// Segments per melon
s32 func_global_asm_8070943C(void) {
    return cc_number_of_players > 1 ? 10 : 4;
}

void func_global_asm_80709464(u8 playerIndex) {
    PlayerProgress *temp = &D_global_asm_807FC950[playerIndex];
    temp->health = temp->melons * func_global_asm_8070943C();
    temp->unk2FD = 0;
}
