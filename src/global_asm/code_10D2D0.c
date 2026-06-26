#include "common.h"

extern s8 D_global_asm_80744504;

typedef struct global_asm_struct_21 {
    f32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
} Struct80708BB8;

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_global_asm_807085D0.s")

/*
Gfx *func_global_asm_807085D0(Gfx *dl, PlayerProgress *arg1, CharacterProgress *arg2, CharacterChange *arg3) {
    f32 temp0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 inv_y_scale;
    f32 temp_f6;
    f32 x_scale; // e8
    s16 a;
    f32 y;
    s16 i;
    u8 temp_s0;
    s8 health;
    s32 x;
    s32 pad;
    f32 temp2;
    f32 temp1;

    health = arg1->health;
    temp_f20 = arg3->unk2E0 / 65535.0;
    temp_s0 = ((arg1->melons * 70) - 70);
    if ((global_properties_bitfield & 3) || (func_global_asm_80714464())) {
        return dl;
    }
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    for (i = 0; i < arg1->melons; i++) {
        a = (i * 0X400) + (object_timer * 200);
        x_scale = (func_global_asm_80612794(a) * 0.3) + 3.0;
        inv_y_scale = (func_global_asm_80612794(a + 0x800) * 0.3) + 3.0;
        temp_f20_2 = func_global_asm_80612794((a >> 1) + 0x200) * 10.0;
        temp_f6 = ((func_global_asm_80612794(a) * 0.5) + 0.5) * 30.0;
        gDPPipeSync(dl++);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, MIN(80.0f, temp_f20 * 511.0f));
        x = (((i * 140) + 0x280) + temp_f20_2) - temp_s0;
        y = (s16)(temp_f20 * 200.0) + temp_f6;
        dl = displayImage(dl, 0x5D, 
            0, 2, 0x30, 0x2A, x, y, 
            x_scale, -inv_y_scale, 0, 0.0f);
        gDPPipeSync(dl++);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, MIN(255.0f, temp_f20 * 511.0f));
        if (health > 0) {
            dl = displayImage(dl, 
                MIN(health - 1, 3) + 0x5A, 0, 2,
                0x30, 0x2A, x, y,
                x_scale, -inv_y_scale, 0, 0.0f);
        }
        health = MAX(0, health - 4);
    }
    gDPPipeSync(dl++);
    return dl;
}
*/

void func_global_asm_80708BB8(Struct80708BB8 *arg0) {
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

void func_global_asm_80708C24(s32 playerIndex, CharacterChange *arg1, PlayerProgress *arg2, s32 arg3) {
    s32 segmentsPerMelon;
    u8 sp28;

    sp28 = arg1->unk2DC.unk6;
    if (sp28 & 0x10) {
        arg1->unk2DC.unk6 ^= 0x10;
        if (arg2->unk2FD > 0) {
            segmentsPerMelon = func_global_asm_8070943C();
            arg2->health = MIN(arg2->health + arg2->unk2FD, arg2->melons * segmentsPerMelon);
        } else if (arg2->unk2FD < 0) {
            if (gameIsInAdventureMode() || gameIsInMysteryMenuMinigameMode()) {
                arg2->health += arg2->unk2FD;
            }
            if (arg2->health <= 0) {
                arg2->health = 0;
                arg1->unk2DC.unkA = 0xC;
                if (cc_number_of_players >= 2) {
                    func_multiplayer_80026B0C(playerIndex);
                }
            } else {
                playSound(0x24B, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
        }
        arg2->unk2FD = 0;
    }
    if ((!(global_properties_bitfield & 2) && func_global_asm_805FCA64()) || (sp28 & 0x80)) {
        arg1->unk2DC.unk9--;
        if (arg1->unk2DC.unk9 == 0) {
            arg1->unk2DC.unk9 = 0x11;
            arg1->unk2DC.unk8 = 3;
        }
    }
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_10D2D0/func_global_asm_80708DA4.s")

/*
Gfx *func_global_asm_80708DA4(Gfx *dl, s16 playerIndex, CharacterChange* arg2) {
    CharacterProgress *sp38;
    PlayerProgress *sp28;
    s32 temp_a0;
    u8 temp;
    u8 var_t0;

    sp38 = &D_global_asm_807FC950[playerIndex].character_progress[func_global_asm_806C8DE0(arg1)];
    sp28 = &D_global_asm_807FC950[playerIndex];
    temp_a0 = cc_number_of_players == 1;
    var_t0 = arg2->unk2E4;
    temp = arg2->unk2DC.unk6;
    if (!temp_a0) {
        var_t0 = 0;
    }
    if (!temp_a0) {
        func_global_asm_80708C24(playerIndex, arg2, sp28, sp38);
        arg2->unk2DC.unk6 &= 0xFFEA;
    }
    if (temp & 0x10) {
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
    if (temp & 1) {
        arg2->unk2DC.unk6 ^= 1;
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
    } else if (temp & 4) {
        arg2->unk2E5 = 1;
        arg2->unk2E4 = 2;
        arg2->unk2DC.unk6 ^= 4;
        arg2->unk2DC.unk6 &= 8;
    } else {
        switch (var_t0) {
            case 1:
                arg2->unk2E0 = func_global_asm_80612D1C(((arg2->unk2E5 / 18.0) * 1.57079637050628662) + 1.57079637050628662) * 65535.0;
                if (arg2->unk2E5-- == 0) {
                    arg2->unk2E4 = 2;
                    arg2->unk2E5 = 0x32;
                }
                break;
            case 2:
                func_global_asm_80708C24(playerIndex, arg2, sp28, sp38);
                break;
            case 3:
                arg2->unk2E0 = func_global_asm_80612D1C((1.57079637050628662 - ((arg2->unk2E5 / 18.0) * 1.57079637050628662)) + 1.57079637050628662) * 65535.0;
                if (arg2->unk2E5-- == 0) {
                    arg2->unk2E4 = 0;
                }
                break;
        }
    }
    if (func_global_asm_805FCA64() || (arg2->unk2DC.unk6 & 0x80)) {
        if (arg2->unk2E4 != 0 || arg2->unk2DC.unk6 != 0) {
            dl = func_global_asm_807085D0(dl, sp28, sp38, arg2);
        }
    }
    return dl;
}
*/

Gfx *func_global_asm_80709344(Gfx *dl) {
    s16 i;
    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist) {
            if (!(character_change_array[i].unk2DC.unk6 & 0x20)
            && (((character_change_array[i].unk2DC.unk8
                || character_change_array[i].unk2DC.unk6)
                && (D_global_asm_80744504 == 0))
                || (character_change_array[i].unk2DC.unk6 & 0x10))) {
                dl = func_global_asm_80708DA4(dl, i, &character_change_array[i]);
            }
        }
    }
    return dl;
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
