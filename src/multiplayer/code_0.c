#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80024000.s")

typedef struct {
    u8 unk0[0x2FE - 0x0];
    u16 unk2FE[4]; // TODO: how many?
} Struct800241F4;

s32 func_800241F4(Struct800241F4 *arg0, s32 arg1) {
    s32 var_v1;
    s32 temp = arg1;

    var_v1 = -arg0->unk2FE[temp];
    if (temp != 0) {
        var_v1 += arg0->unk2FE[0];
    }
    if (temp != 1) {
        var_v1 += arg0->unk2FE[1];
    }
    if (temp != 2) {
        var_v1 += arg0->unk2FE[2];
    }
    if (temp != 3) {
        var_v1 += arg0->unk2FE[3];
    }
    return var_v1;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80024254.s")

typedef struct MultiplayerStruct4 {
    u8 pad0[0x4C];
    u8 unk4C;
} MultiplayerStruct4;
void func_800242FC(MultiplayerStruct4 *);

extern s32 D_807552EC;
extern s8 D_8076A105; // A player index

extern u8 D_80026F70;
// TODO: Is this a PaaD?
typedef struct MultiplayerStruct0 {
    u8 pad0[0x1A4];
    u8 unk1A4;
} MultiplayerStruct0;

void func_806F91B4(s32, u8, s16);
extern s32 D_807552E8;
s32 func_80026BD8(s32);
void func_806C9434(s32);
void func_806CFF9C(Actor*);

void func_800242FC(MultiplayerStruct4 *arg0) {
    s32 temp_v0;
    s32 playerIndex;
    s32 phi_s1;
    s32 phi_s2;

    D_807552EC = 2;
    phi_s2 = 0;
    phi_s1 = -99999;
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        temp_v0 = func_80024254(playerIndex);
        if (phi_s1 < temp_v0) {
            phi_s1 = temp_v0;
            phi_s2 = playerIndex;
        } else if (temp_v0 == phi_s1) {
            phi_s2 = -1;
        }
    }   
    global_properties_bitfield |= 0x40001;
    func_80714638();
    D_8076A105 = phi_s2;
}

// u64 nonsense, bleh, PaaD?
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_800243C8.s")

void func_8002449C(void) {
    s32 temp_v0;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        temp_v0 = func_80024254(playerIndex);
        if ((temp_v0 >= D_807552E4.unkC) || (temp_v0 < -999)) {
            func_800242FC(current_actor_pointer->additional_actor_data);
            return;
        }
    }
}

void func_8002452C(void) {
    s32 a = 0;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (func_80024254(playerIndex)) {
            a++;
        }
    }
    if (a < 2) {
        // TODO: Which aaD type are they actually expecting here?
        func_800242FC(current_actor_pointer->PaaD);
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_800245B0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_800246EC.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_800249D8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80024CA4.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025264.s")

// D_80026FA4 struct array? Loop, very fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025378.s")

s32 func_800253C8(void) {
    return (((rand() >> 0xF) % 32767) % 211) + 90;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025404.s")

s32 func_8063254C(s32, s32 *, f32 *, f32 *, f32 *, s16 *, s16*); /* extern */

void func_80025608(s32 arg0) {
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp_1;
    s16 sp2E;
    s16 sp2C;

    sp38 = 0;
    sp2E = 0;
    sp2C = 0;
    func_8063254C(arg0, &sp38, &sp34, &sp30, &sp_1, &sp2E, &sp2C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025654.s")

/*
//s32 func_80024254(s32);
void func_800243C8();
typedef struct MultiplayerStruct3 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} MultiplayerStruct3;
typedef struct MultiplayerStruct2 {
    u8 pad0[0x8];
    MultiplayerStruct3* unk8;
} MultiplayerStruct2;
MultiplayerStruct2 *func_80025378();
s32 func_80025404();
s32 func_80025608(s32);
s32 func_806F5EB4(s32, s32, s16, s16, s32);
void func_806F5FE8(s32, s16, s16, s16, s32);
extern s32 D_807552E8;
extern s32 D_807552F0;

// TODO: Pretty close, but dealing with fiddly logic and stack stuff is a pain
void func_80025654(MultiplayerStruct4 *arg0) {
    MultiplayerStruct3 *sp20;
    s32 temp_v0;

    sp20 = func_80025378()->unk8;
    if (gameIsInAdventureMode() && ((global_properties_bitfield & 2) == 0)) {
        if (D_807552E8 == 3) {
            func_800243C8();
        }
        temp_v0 = func_80025404();
        if (temp_v0 == -1) {
            if ((arg0->unk4C == 0) && 
                (!func_8067ADB4(0x7A)) && // DK Coin (Multiplayer)
                (func_80025608(0x1D2) == 0) && 
                (func_806F5EB4(0x1D2, 0, sp20->unk0, sp20->unk2, sp20->unk4) == 0)) {
                    func_806F5FE8(0x1D2, sp20->unk0, sp20->unk2, sp20->unk4, 0xA);
            }
        } else if ((D_807552E8 == 5) && (func_80024254(temp_v0) >= D_807552F0)) {
            func_800242FC(arg0);
        }
        if (arg0->unk4C != 0) {
            arg0->unk4C--;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025CE8.s")

// Doable, loop, struct
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80025F84.s")

typedef struct {
    s32 map;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} struct_80026FA4;

struct_80026FA4 *func_80025378();                              /* extern */

/*
void func_80025F84(void) {
    s32 var_s0;
    s32 var_v0;
    struct_80026FA4 *temp_v0;
    struct_80026FA4 *var_s1;

    temp_v0 = func_80025378();
    var_s0 = 0 * 4;
    var_s1 = temp_v0 + var_s0;
    if (temp_v0->unkC != -1) {
        var_v0 = var_s1->unkC;
loop_2:
        func_8063DA40((s16) var_v0, 0);
        var_s0 += 4;
        var_s1 = (u32*)var_s1 + 1;
        if (var_s0 < 0x10) {
            var_v0 = var_s1->unkC;
            if (var_v0 != -1) {
                goto loop_2;
            }
        }
    }
}
*/

void func_80715908(s32);

typedef struct {
    u8 unk0[0x50 - 0x0];
    s32 unk50[8];
    u8 unk70;
} Struct80025FFC;

void func_80025FFC(Struct80025FFC *arg0) {
    s32 temp_a0;
    s32 i;

    if (arg0->unk70 != 0) {
        for (i = 0; i < cc_number_of_players * 2; i++) {
            temp_a0 = arg0->unk50[i];
            if (temp_a0 != NULL) {
                func_80715908(temp_a0);
            }
            arg0->unk50[i] = NULL;
        }
    }
    arg0->unk70 = 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80026094.s")

void func_800268C0(u8 arg0) {
    D_80026F70 |= arg0;
}

void func_806F0C18(Actor*);
void func_806F91B4(s32, u8, s16);
extern s32 D_807552E8;

void func_800268DC(Actor *arg0, PlayerAdditionalActorData *arg1, PlayerProgress *arg2) {
    arg2->crystals = 0;
    arg2->standardAmmo = 0;
    arg2->oranges = 0;
    arg2->homingAmmo = 0;
    arg1->unkD4 = 0x5A;
    func_806F0C18(arg0);
    arg0->object_properties_bitfield &= 0xDFFFFFFF;
    arg1->unk247 = -1;
    arg1->unk246 = 0;
    if (func_80714608(0) != 0) {
        extra_player_info_pointer->unk21E = 0;
    }
    if ((D_807552E8 == 3) || (D_807552E8 == 5)) {
        func_806F91B4(1, arg1->unk1A4, -10);
    }
}

void func_8002698C(MultiplayerStruct0 *arg0) {
    if (D_807552E8 == 2) {
        func_806F91B4(1, arg0->unk1A4, -3);
    }
}

void func_80025F84();
void func_806A5DF0(u16, f32, f32, f32, s32, s32, s32, s32);
extern s32 D_807552E8;

typedef struct {
    u8 unk0[0x4C];
    u8 unk4C;
} struct_unknown_mp_aad;

void func_800269C8(u8 arg0, s8 arg1) {
    Actor *temp_s0;
    struct_unknown_mp_aad* phi_v1;
    s32 temp_v1;
    s32 sp30;
    PlayerProgress *temp_s1;

    temp_s0 = character_change_array[arg0].player_pointer;
    temp_s1 = &D_807FC950[arg0];
    temp_v1 = temp_s1->health + temp_s1->unk2FD + arg1;
    sp30 = *(s8*)(&temp_s1->unk2FA) - temp_v1;
    if ((func_806F8AD4(1U, arg0) != 0) && ((temp_v1 <= 0) || (sp30 >= 2))) {
        struct_unknown_mp_aad* aad = func_8067ADB4(0x13E)->additional_actor_data;
        aad->unk4C = 1;
        func_806F91B4(1, arg0, -0xA);
        if (D_807552E8 == 5) {
            func_80025F84();
        }
        func_806A5DF0(0x7A, temp_s0->x_position, temp_s0->y_position, temp_s0->z_position, (s32) temp_s0->y_rotation, 1, -1, 0);
        temp_s1->unk2FA = 0;
    }
}

void func_80026B0C(s32 arg0) {
    Actor *player = character_change_array[arg0].player_pointer;
    player->noclip_byte = 0xC;
    switch (D_807552E8) {
        case 2:
            func_806F91B4(1, arg0, -3);
            return;
        case 5:
            func_806F91B4(7, arg0, -0x40);
        case 3:
            func_800269C8(arg0, 0);
            return;
        case 4:
            func_806F91B4(7, arg0, -1);
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80026BD8.s")

/*
s32 func_80026BD8(s32 arg0) {
    ExitData *temp_v0;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f24;
    f32 temp_f2;
    f32 var_f20;
    f32 var_f22;
    s32 var_a1;
    s32 var_s1;
    s32 var_s4;
    u8 temp_v1;
    Actor *temp_v1_2;
    CharacterChange *var_a0;

    var_f22 = 0.0f;
    var_s4 = 0;
    temp_f24 = *(f32 *)0x800270F4;
    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        var_f20 = temp_f24;
        temp_v0 = getExitData(var_s1);
        temp_v1 = cc_number_of_players;
        var_a1 = 0;
        if ((s32) temp_v1 > 0) {
            var_a0 = character_change_array;
            do {
                var_a1 += sizeof(CharacterChange);
                temp_v1_2 = var_a0->player_pointer;
                if ((var_a0->does_player_exist != 0) && (temp_v1_2->control_state != 0x84)) {
                    temp_f0 = (f32) temp_v0->x_pos - temp_v1_2->x_position;
                    temp_f2 = (f32) temp_v0->y_pos - temp_v1_2->y_position;
                    temp_f12 = (f32) temp_v0->z_pos - temp_v1_2->z_position;
                    temp_f14 = (temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
                    if (temp_f14 < var_f20) {
                        var_f20 = temp_f14;
                    }
                }
                var_a0 += sizeof(CharacterChange);
            } while (var_a1 < (temp_v1 * sizeof(CharacterChange)));
        }
        if (var_f22 < var_f20) {
            var_f22 = var_f20;
            var_s4 = var_s1;
        }
    };
    return var_s4;
}
*/

void func_80026D40(Actor *arg0, s32 arg1) {
    if ((D_807552E8 == 4) && (func_80024254(arg1) == 0)) {
        D_807FC950[arg1].health = 0;
        arg0->control_state_progress++;
        func_806EB0C0(0x5B, NULL, arg1);
        arg0->noclip_byte = 1;
    } else {
        func_806C9434(func_80026BD8(arg1));
        character_change_array[arg1].unk2E2 |= 1;
        func_806CFF9C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_80026E20.s")

extern s32 D_807552E8;

Actor *func_806C9FD8(Actor *actor);

/*
// TODO: Quite close, regalloc and something up with the start
void func_80026E20(u8 arg0, s8 arg1) {
    Actor *temp_v0;
    PlayerAdditionalActorData *PaaD;
    s32 temp[5];

    if ((D_807FC950[arg0].unk2FD + D_807FC950[arg0].health) > 0) {
        if (character_change_array[arg0].unk2A0 != NULL) {
            temp_v0 = func_806C9FD8(character_change_array[arg0].unk2A0);
            if (temp_v0 != NULL) {
                if (temp_v0->interactable == 1) {
                    PaaD = temp_v0->PaaD;
                    if ((D_807FC950[arg0].unk2FD + D_807FC950[arg0].health + arg1) <= 0) {
                        D_807FC950[PaaD->unk1A4].unk2FE[arg0]++;
                    }
                }
            }
        }
    }
    if (D_807552E8 == 3 || D_807552E8 == 5) {
        func_800269C8(arg0, arg1);
    }
}
*/
