#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_807085D0.s")

typedef struct global_asm_struct_21 {
    f32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
} GlobalASMStruct21;

void func_80708BB8(GlobalASMStruct21 *arg0) {
    if ((D_807FBB64 & 0x800)) {
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

// TODO: arg1 might also be PlayerProgress*, needs some padding split apart though
// Other than that this function looks doable
void func_80708C24(s32 arg0, CharacterChange *arg1, PlayerProgress *arg2, s32 arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_80708C24.s")

void func_80026B0C(s32);
s32 func_8070943C();

/*
// Regalloc :(
void func_80708C24(s32 arg0, CharacterChange *arg1, PlayerProgress *arg2, s32 arg3) {
    s32 temp_v1_2;
    s32 temp_lo;
    s32 pad;
    u32 sp28;

    sp28 = (u8)arg1->unk2E2;
    if ((arg1->unk2E2 & 0x10)) {
        arg1->unk2E2 ^= 0x10;
        if (arg2->unk2FD > 0) {
            temp_lo = arg2->melons * func_8070943C();
            temp_v1_2 = arg2->health + arg2->unk2FD;
            arg2->health = MIN(temp_v1_2, temp_lo);
        } else if (arg2->unk2FD < 0) {
            if (gameIsInAdventureMode() || gameIsInMysteryMenuMinigameMode()) {
                arg2->health += arg2->unk2FD;
            }
            if (arg2->health <= 0) {
                arg2->health = 0;
                arg1->unk2E6 = 0xC;
                if (cc_number_of_players >= 2) {
                    func_80026B0C(arg0);
                }
            } else {
                playSound(0x24B, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
        }
        arg2->unk2FD = 0;
    }
    if ((!(global_properties_bitfield & 2) && func_805FCA64()) || (sp28 & 0x80)) {
        arg1->unk2E5--;
        if (arg1->unk2E5 == 0) {
            arg1->unk2E5 = 0x11;
            arg1->unk2E4 = 3;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_80708DA4.s")

extern s8 D_80744504;

s16 func_80708DA4(s32, s16, CharacterChange*);

s32 func_80709344(s32 arg0) {
    s16 i;
    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist) {
            if (!(character_change_array[i].unk2E2 & 0x20)
            && (((character_change_array[i].unk2E4
                || character_change_array[i].unk2E2)
                && (D_80744504 == 0))
                || (character_change_array[i].unk2E2 & 0x10))) {
                arg0 = func_80708DA4(arg0, i, &character_change_array[i]);
            }
        }
    }
    return arg0;
}

// Segments per melon
s32 func_8070943C(void) {
    return cc_number_of_players > 1 ? 10 : 4;
}

void func_80709464(u8 playerIndex) {
    PlayerProgress *temp = &D_807FC950[playerIndex];
    temp->health = temp->melons * func_8070943C();
    temp->unk2FD = 0;
}
