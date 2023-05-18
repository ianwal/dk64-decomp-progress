#include <ultra64.h>
#include "functions.h"


extern u8 D_80750AB4;
extern u8 D_80750AB8;
extern u8 D_80750AC0;

void func_806C9C80(s32, s32, s32);
s32 func_8066B06C(s32, s32);
void func_806C9658(s32);

extern f32 D_8075C788;
extern f64 D_8075C790;
extern f64 D_8075C798;
extern u8 D_80770DC9;
extern u8 number_of_exits;

extern ExitData *exit_array;
extern ExitData D_807FC908;
extern ExitData D_807FD574;
extern ExitData D_807FC918;

extern s16 D_8076AEE2;
extern f32 D_8076AEE4; // x
extern f32 D_8076AEE8; // y
extern f32 D_8076AEEC; // z
extern f64 D_8075C7A8; // angle?
extern s16 D_8076AEF0;
extern f64 D_8075C7A0;

extern u16 D_807FD570; // Tranferred actor behaviour index (through loading zone)

extern s16 D_807FC930[];

void func_806C7B00(void) {
    s16 i;
    for (i = 0; i < 0xE; i++) {
        D_807FC930[i] = 0;
    }
}

s32 func_806C7B34(void) {
    return D_8075C410[current_character_index[0]].unk0;
}

// TODO: Add this to the aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s8 unk8;
} AppleAAD;

void func_806C7B50(u32 arg0, u8 arg1, Actor *arg2) {
    AppleAAD *temp_v0;

    func_80677FA8(arg0, 0x82); // Spawn actor: Apple (Fungi)
    func_8067B238(D_807FBB44, arg2, 0.15f);
    temp_v0 = D_807FBB44->PaaD;
    temp_v0->unk4 = arg2;
    temp_v0->unk8 = arg1;
}

void func_806C7BAC(s32 arg0, s32 arg1) {
    // TODO: Is this aaD type actually correct? The args line up but that's all I know right now
    // Maybe run it through a debugger or something
    OtherAdditionalActorData *temp_v0;

    func_80677FA8(ACTOR_ROCKETBARREL_ON_KONG, 0x8C);
    func_8067B238(D_807FBB44, D_807FBB48, 0.15f);
    temp_v0 = D_807FBB44->additional_actor_data;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
}

void func_806C7C10(void) {
    cc_number_of_players = D_80750AC0;
    character_change_array = NULL;
    if (cc_number_of_players >= 2) {
        switch (D_80750AB8) {
            case 0:
                D_80750AB4 = cc_number_of_players;
                return;
            case 1:
                D_80750AB4 = 1;
                return;
        }
    } else {
        D_80750AB4 = 1;
        D_80750AB8 = 0;
    }
}

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
} Struct80750948;

extern Struct80750948 D_80750948[];
extern u8 D_80750AB8;
extern u8 D_80750ABC;

Struct80750948 *func_806C7C94(u8 arg0) {
    u8 i;
    s32 var_v1;
    Struct80750948 *var_a2;

    i = 0;
    var_v1 = 0;
    while (!var_v1) {
        if (cc_number_of_players == D_80750948[i].unk0
            && D_80750AB8 == D_80750948[i].unk1
            && arg0 == D_80750948[i].unk3
            && D_80750948[i].unk2 & D_80750ABC) {
            var_v1 = 1;
        } else {
            i++;
        }
    }
    return &D_80750948[i];
}

// Delay slot problem with mips_to_c
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C7D40.s")

void func_806C80E4(void) {
    PlayerAdditionalActorData *PaaD;
    f32 sp30;
    f32 pad;
    f32 phi_f2;

    if (D_807FD570 == ACTOR_STEEL_KEG) {
        phi_f2 = 20.0f;
    } else {
        phi_f2 = 0.0f;
    }
    sp30 = func_80612794(player_pointer->y_rotation) * phi_f2;
    pad = func_80612790(player_pointer->y_rotation) * phi_f2;
    func_80689114(D_807FD570, player_pointer->x_position + sp30, player_pointer->y_position + 7.0, player_pointer->z_position + pad, 0, 1.0f, player_pointer);
    PaaD = player_pointer->PaaD;
    PaaD->unk1F0 |= 0x1000000;
}

void func_806C81DC(s16 arg0, s16 arg1) {
    CharacterChange *cc = character_change_array;
    cc->unk27A = arg1 - arg0;
    cc->unk272 = arg0;
    cc->unk276 = arg1;
    // TODO: What do these typecasts do and can we get rid of them?
    cc->unk280 = (f32)cc->unk278 / (f32)cc->unk27A;
}

// Unrolled loops
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C8220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C850C.s")

extern f32 D_8075C4B0;
extern Actor *D_807F5D10;
extern s16 D_807FD584;

extern f32 D_80753578[];
extern f32 D_807535E8[];

void func_806F09F0(Actor*, u16);

/*
// TODO: Good progress made
void func_806C850C(s32 arg0, s32 arg1) {
    Temp10Big *sp2C;
    Struct807FD610 *temp_v0_2;
    PlayerAdditionalActorData *temp_t7;

    arg1 &= 0xFF;

    if (cc_number_of_players >= 2) {
        current_character_index[arg1] = current_character_index[func_8060AB38(arg1)];
    }
    if ((arg1 == 0) && (current_map == MAP_MAIN_MENU)) {
        current_character_index[0] = 0;
    }
    sp2C = &D_8075C410[current_character_index[arg1]];
    func_80677FA8(sp2C->unk0, sp2C->unk8);
    D_807FBB44->object_properties_bitfield &= ~0x1000;
    D_807FBB44->object_properties_bitfield |= sp2C->unkC;
    D_807FBB44->unk16E = 0x42;
    D_807FBB44->unk16F = 0x42;
    D_807FBB44->object_properties_bitfield |= 0x01000000;
    if (cc_number_of_players >= 2) {
        D_807FBB44->unk64 |= 0x200;
    }
    D_807FBB44->unk68 |= 0xC0;
    D_807FBB44->animation_state->unk1C = malloc(0x100);
    D_807FBB44->animation_state->unk1C->unk0 = 0;
    D_807FBB44->animation_state->unk20 = malloc(0x200);
    D_807FBB44->animation_state->unk20->unk0 = 0xFF;
    D_807FBB44->animation_state->unk24 = malloc(0x200);
    D_807FBB44->animation_state->unk24->unk0 = 0xFF;
    D_807FBB48 = D_807FBB44;
    extra_player_info_pointer = D_807FBB44->PaaD;
    extra_player_info_pointer->unk247 = -1;
    extra_player_info_pointer->unk1A4 = arg1;
    extra_player_info_pointer->unk11E = -1;
    extra_player_info_pointer->unk244 = 0;
    D_807FD584 = sp2C->unk4;
    extra_player_info_pointer->unk120 = -0x64;
    extra_player_info_pointer->unk1EE = D_807FBB44->unk58;
    func_806E2C74(D_807FBB48);
    func_80677FA8(0xBC, 0);
    extra_player_info_pointer->unk104 = D_807FBB44;
    if (arg1 == 0) {
        D_807F5D10 = D_807FBB44;
    }
    D_807FBB44->object_properties_bitfield |= 0x100000;
    func_806C8D20(D_807FBB48);
    extra_player_info_pointer->unk26 = 0x64;
    D_807FBB48->y_acceleration = D_80753578[D_807FD584];
    D_807FBB48->terminal_velocity = D_807535E8[D_807FD584];
    extra_player_info_pointer->unk250 = 0x78;
    extra_player_info_pointer->unkD4 = 0;
    extra_player_info_pointer->unkD8 = 0;
    extra_player_info_pointer->unkFC_s32 = 0;
    extra_player_info_pointer->unk100 = 0;
    extra_player_info_pointer->unk16 = 0;
    extra_player_info_pointer->unk10C = 0;
    extra_player_info_pointer->unk1A0 = 0;
    extra_player_info_pointer->unk1C0 = D_8075C4B0;
    extra_player_info_pointer->unk1C4 = D_8075C4B0;
    extra_player_info_pointer->unk1C8 = D_8075C4B0;
    extra_player_info_pointer->unk1CC = D_8075C4B0;
    extra_player_info_pointer->unk1D0 = D_8075C4B0;
    extra_player_info_pointer->unk1D4 = D_8075C4B0;
    extra_player_info_pointer->unk245 = 0;
    extra_player_info_pointer->unk21E = 0x1E;
    extra_player_info_pointer->unkC8 = -1;
    extra_player_info_pointer->unkCA = 0;
    extra_player_info_pointer->unkC8 = -1;
    extra_player_info_pointer->unk264 = -1;
    extra_player_info_pointer->unk258 = 1.0f;
    extra_player_info_pointer->unk25C = 1.0f;
    if (isFlagSet(0xCE, 0) != 0) {
        extra_player_info_pointer->unk1F0 |= 0x100000;
    }
    func_806C8220(1, D_807FBB48->unk178, D_807FBB48->unk58);
    D_807FBB48->unk146 = 0;
    func_806F09F0(D_807FBB48, D_807FBB48->unk58);
    D_807FBB48->unkDE = 0x400;
    extra_player_info_pointer->unk1B0 = 0;
    extra_player_info_pointer->unk1AC = NULL;
    D_807FD610[arg1].unk10 = D_807FD610[arg1].unk4;
    D_807FD610[arg1].unk14 = D_807FD610[arg1].unk4;
    D_807FD610[arg1].unk18 = D_807FD610[arg1].unk4;
    D_807FD610[arg1].unk1C = D_807FD610[arg1].unk4;
    D_807FD610[arg1].unk20 = D_807FD610[arg1].unk28;
    D_807FD610[arg1].unk22 = D_807FD610[arg1].unk28;
    D_807FD610[arg1].unk24 = D_807FD610[arg1].unk28;
    D_807FD610[arg1].unk26 = D_807FD610[arg1].unk28;
    func_806CFF9C(D_807FBB48);
    func_806C90C4(arg0);
    func_806C8984();
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C8984.s")

void func_806C8D20(Actor *arg0) {
    arg0->noclip_byte = 0x3C; // Normal collision
}

u8 func_806C8D2C(s16 arg0) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (arg0 == D_8075C410[i].unk0) {
            return D_8075C410[i].unk7;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C8DE0.s")

// u8 func_806C8D2C(s16, s32);

/*
// TODO: Missing something
s32 func_806C8DE0(s32 playerIndex) {
    s32 phi_v1;

    phi_v1 = current_character_index[playerIndex];
    switch (phi_v1) {
        case 6:
        case 7:
            phi_v1 = func_806C8D2C(character_change_array[playerIndex].player_pointer->PaaD->unk1EE);
    }
    return phi_v1;
}
*/

// TODO: Quite fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C8E58.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    s32 unkC;
} Struct806C8F8C_arg0;

void func_806C8F8C(Struct806C8F8C_arg0 *arg0);

void func_806C8EE8(void) {
    current_character_index[cc_player_index]++;
    current_character_index[cc_player_index] %= 8;
    extra_player_info_pointer->unk8C = 0;
    func_806C8F8C(&D_8075C410[current_character_index[cc_player_index]]);
    func_8060098C(&func_806C9C80, 0x14, cc_player_index, 0, 0);
}

extern s16 D_807FD584;

void func_806C8F8C(Struct806C8F8C_arg0 *arg0) {
    D_807FBB48->unk58 = arg0->unk0;
    D_807FD584 = arg0->unk4;
    func_806136B4(D_807FBB48);
    func_8066E21C(D_807FBB48->ledge_info_pointer);
    func_806134B4(D_807FBB48, arg0->unkA);
    D_807FBB48->ledge_info_pointer = func_80665F24(D_807FBB48);
    D_807FBB48->object_properties_bitfield &= -0x1001;
    D_807FBB48->object_properties_bitfield |= arg0->unkC;
    D_807FBB48->animation_state->unk1C = malloc(0x100);
    D_807FBB48->animation_state->unk1C->unk0 = 0;
    D_807FBB48->animation_state->unk20 = malloc(0x100);
    D_807FBB48->animation_state->unk20->unk0 = 0xFF;
    D_807FBB48->animation_state->unk24 = malloc(0x100);
    D_807FBB48->animation_state->unk24->unk0 = 0xFF;
    func_806C8220(1, D_807FBB48->unk178, D_807FBB48->unk58);
    func_806F833C(0);
}

void func_806C90C4(s32 exitIndex) {
    PlayerAdditionalActorData *PaaD;
    ExitData *exit;

    PaaD = D_807FBB48->PaaD;
    exit = getExitData(exitIndex);
    D_8076AEE2 = 0;
    global_properties_bitfield &= -0x401;
    switch (exit->has_autowalk) {
        case 2:
            D_807FBB48->control_state = 0x4F;
            D_807FBB48->control_state_progress = 3;
            func_80614D00(D_807FBB48, 0.5f, 0);
            PaaD->unk50 = 1;
            D_807FBB48->unk6A |= 4;
            func_8067ACB4(D_807FBB48);
            func_80614E78(D_807FBB48, 0x34);
            // Fallthrough
        case 0:
            D_807FBB48->unkAC = D_8075C788;
            D_807FBB48->x_position = exit->x_pos;
            D_807FBB48->y_position = D_807FBB48->unkA0 = exit->y_pos;
            D_807FBB48->z_position = exit->z_pos;
            D_807FBB48->y_rotation = (exit->angle / D_8075C790) * D_8075C798;
            D_807FBB48->unkEE = D_807FBB48->y_rotation;
            break;
        case 1:
            func_806F39E8(D_807FBB48, exit, 0x32);
    }
    D_807FBB48->unk6A &= ~0x200;
    PaaD->unk104->unk15F = exit->unk7 <= 0 ? 1 : exit->unk7;
    if (exit->size & 1) {
        D_80770DC9 = 1;
    }
}

void func_806C9434(s32 arg0);
void func_80605314(Actor*, u8);

void func_806C92C4(s32 arg0) {
    func_80672C30(D_807FBB48);
    func_806C9434(arg0);
    D_807FBB48->unk9C = D_807FBB48->y_position;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C9304.s")

/*
// TODO: Hmm. Pretty close. Loop is sus
void func_806C9304(Actor *arg0, PlayerAdditionalActorData *arg1) {
    f32 var_f18;
    s32 var_v0;

    if (character_change_array[arg1->unk1A4].unk2C0 != 1) {
        func_806D0468(D_807FBB48, 1, arg0, arg1);
    }
    if (arg0->animation_state->scale_x != arg1->unk1C0) {
        var_v0 = 0;
        while (var_v0 < 2) {
            var_f18 = arg1[var_v0].unk1C0;
            arg1[var_v0].unk1CC = var_f18;
            arg0[var_v0].animation_state->scale_x = var_f18;
            var_v0++;
        }
    }
}
*/

void func_806C93E4(Actor *arg0, PlayerAdditionalActorData *arg1) {
    func_806F12FC(arg0);
    arg1->unk1F0 &= ~0x30;
    arg0->object_properties_bitfield |= 0x8000;
    arg0->shadow_opacity = 0xFF;
}

void func_806C9434(s32 arg0) {
    s32 temp; // PAD
    s32 temp3; // PAD
    Actor178 *sp34;
    s32 temp2; // PAD
    PlayerProgress *sp2C;
    PlayerAdditionalActorData *temp_s2;
    u8 phi_s0;

    temp_s2 = D_807FBB48->additional_actor_data;
    sp34 = D_807FBB48->unk178;
    func_806C8DE0(temp_s2->unk1A4);
    sp2C = &D_807FC950[temp_s2->unk1A4];
    temp_s2->unk250 = 0x78;
    for (phi_s0 = 0; phi_s0 < 2; phi_s0++) {
        func_80605314(D_807FBB48, phi_s0);
    }
    func_806C90C4(arg0);
    func_806C8220(0, sp34, D_807FBB48->unk58);
    func_80709464(temp_s2->unk1A4);
    D_807FBB48->unkB8 = 0.0f;
    temp_s2->unk1F0 &= 0xF7FFFF5F;
    temp_s2->unk200 = 0;
    temp_s2->unk4 = 0.0f;
    if (cc_number_of_players >= 2) {
        func_800268DC(D_807FBB48, temp_s2, sp2C);
    }
    func_806C9304(D_807FBB48, temp_s2);
    if (!func_8061CB50()) {
        if (cc_number_of_players >= 2 && D_80750AB8 == 1) {
            func_8061EA78();
        } else {
            func_8061EB04(D_807FBB48, temp_s2->unk1A4);
        }
    }
    func_806C8D20(D_807FBB48);
    func_806CFF9C(D_807FBB48);
    D_807FBB48->z_rotation = 0;
    D_807FBB48->x_rotation = 0;
}

void loadExits(s32 map) {
    exit_array = getPointerTableFile(0x17, map, 1, 1);
    number_of_exits = func_8066B06C(0x17, map) / sizeof(ExitData);
    func_806C9658(map); // Check galleon water level
    D_807FC908.x_pos = D_807FD574.x_pos;
    D_807FC908.y_pos = D_807FD574.y_pos;
    D_807FC908.z_pos = D_807FD574.z_pos;
    D_807FC908.angle = 0;
}

void func_806C9658(s32 map) {
    if (map == MAP_GALLEON) {
        // Galleon: Water Level Raised
        if (isFlagSet(0xA0, FLAG_TYPE_PERMANENT)) {
            exit_array[18].y_pos = 1629;
            exit_array[23].y_pos = 1629;
        } else {
            exit_array[18].y_pos = 1574;
            exit_array[23].y_pos = 1574;
        }
    }
}

ExitData *getExitData(s32 exitIndex) {
    if (D_8076AEE2 & 1) {
        D_807FC918.x_pos = D_8076AEE4;
        D_807FC918.y_pos = D_8076AEE8;
        D_807FC918.z_pos = D_8076AEEC;
        D_807FC918.angle = D_8075C7A8 * (D_8076AEF0 / D_8075C7A0);
        return &D_807FC918;
    }
    if (number_of_exits == 0) {
        return &D_807FC908;
    }
    if (exitIndex >= number_of_exits) {
        return &exit_array[0];
    }
    return &exit_array[exitIndex];
}

void func_800268C0(s8);

// TODO: Any cleanup possible? Fiddly regalloc
s8 func_806C9830(s8 arg0, Actor *arg1) {
    s8 phi_a2 = arg0;
    if (cc_number_of_players >= 2) {
        PlayerAdditionalActorData *PaaD = arg1->PaaD;
        CharacterChange *CC = &character_change_array[PaaD->unk1A4];
        if (CC->unk2A0) {
            Actor *actor = CC->unk2A0;
            if (actor->interactable & 1) {
                phi_a2 = -1;
                if (D_807FBB64 & 0x04000000) {
                    func_800268C0(1);
                }
            } else if (actor->interactable & 4) {
                if ((actor->unk58 == ACTOR_PROJECTILE_ORANGE) || (actor->unk58 == ACTOR_PROJECTILE_ORANGE_KRUSHA)) {
                    phi_a2 = -3;
                    if (D_807FBB64 & 0x04000000) {
                        func_800268C0(2);
                    }
                } else {
                    phi_a2 = -2;
                    if (D_807FBB64 & 0x04000000) {
                        func_800268C0(1);
                    }
                }
            } else if (D_807FBB64 & 0x04000000) {
                func_800268C0(1);
            }
        }
    }
    return phi_a2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C9974.s")

void func_80026E20(u8, s8);

extern s32 D_807552EC;

/*
// TODO: Close, something going on with the stack
s32 func_806C9974(u8 arg0, s8 arg1) {
    s32 phi_v0;

    character_change_array[arg0].unk2E2 |= 0x11;
    if ((cc_number_of_players >= 2) && (arg1 < 0) && (D_807552EC == 1)) {
        func_80026E20(arg0, arg1); // In the multiplayer overlay
    }
    if (arg1 < 0) {
        func_8060E7EC(arg0, 0xFF, 5);
    }
    if (!(D_807FBB64 & 0x800)) {
        D_807FC950[arg0].unk2FD += arg1;
    }
    phi_v0 = FALSE;
    if ((D_807FC950[arg0].unk2FD + D_807FC950[arg0].health) <= 0) {
        character_change_array[arg0].unk2E2 |= 0xC0;
        phi_v0 = TRUE;
    }
    return phi_v0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_806C9AE0.s")

extern u8 D_80750AC0;
extern s8 D_80750ACC;
extern s32 D_807FD56C;

void func_806C7B00(void);

/*
// TODO: Excruciatingly close
// Something weird going on with a0 and s2
// Stray branch, also
void func_806C9AE0(void) {
    PlayerProgress *PP;
    s32 playerIndex;
    s32 kongIndex;

    for (playerIndex = 0; playerIndex < 4; playerIndex++) {
        PP = &D_807FC950[playerIndex];
        bzero(PP, sizeof(PlayerProgress));
        if (D_80750AC0 >= 2) {
            if (D_807552E4.unk0 == 1) {
                for (kongIndex = 0; kongIndex < 6; kongIndex++) {
                    PP->character_progress[kongIndex].weapon = 7;
                }
            }
            for (kongIndex = 0; kongIndex < 6; kongIndex++) {
                PP->character_progress[kongIndex].simian_slam = 1;
            }
        }
        PP->melons = 1;
        func_80709464(playerIndex);
    }
    func_806C7B00();
    D_80750ACC = 0;
    D_807FD56C = 0;
}
*/

extern s32 D_80750B34[];

void func_806F91B4(s32, u8, s32);

void func_806C9C1C(s32 arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_806F91B4(D_80750B34[i], arg0, 9999);
    }
    func_806F833C(0);
}

void func_806C9C80(s32 playerIndex, s32 arg1, s32 arg2) {
    CharacterProgress *characterProgress = &D_807FC950[playerIndex].character_progress[func_806C8DE0(playerIndex)];

    characterProgress->weapon = 7;
    characterProgress->instrument = 0xF;
    characterProgress->simian_slam = 3;
    characterProgress->moves = 3;

    // Camera/Shockwave
    setFlag(0x179, TRUE, FLAG_TYPE_PERMANENT);
    func_806C9C1C(playerIndex);
}

void func_806C9D20(u8 playerIndex) {
    CharacterChange *cc = &character_change_array[playerIndex];
    cc->unk21C = cc->look_at_eye_x;
    cc->unk220 = cc->look_at_eye_y;
    cc->unk224 = cc->look_at_eye_z;
    cc->unk234 = cc->look_at_at_x;
    cc->unk238 = cc->look_at_at_y;
    cc->unk23C = cc->look_at_at_z;
}

// playerHasGoldenBananaInAtleastOneLevel()
s32 func_806C9D7C(void) {
    s32 levelIndex;
    s32 found;
    CharacterProgress *CP;

    found = FALSE;
    CP = &D_807FC950[0].character_progress[current_character_index[0]];
    for (levelIndex = 0; levelIndex < 8 && !found; levelIndex++) {
        found = CP->golden_bananas[levelIndex] > 0;
    }
    return found;
}