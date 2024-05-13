#include <ultra64.h>
#include "functions.h"

// TODO: Add this to the aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s8 unk8;
} AppleAAD;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
} Struct80750948;

extern Struct80750948 D_global_asm_80750948[];
extern u8 D_global_asm_80750AB4;
extern u8 D_global_asm_80750AB8;
extern u8 D_global_asm_80750ABC;
extern u8 D_global_asm_80750AC0;
extern s8 D_global_asm_80750ACC;
extern s32 D_global_asm_80750B34[];

extern s32 D_global_asm_807552EC;

extern u8 D_global_asm_80770DC9;
extern u8 number_of_exits;

// rodata
const Struct8075C410 D_global_asm_8075C410[] = {
    {2, 0, 0x04, 0x1000},
    {3, 1, 0x01, 0x1000},
    {4, 2, 0x06, 0x1000},
    {5, 3, 0x09, 0x1000},
    {6, 4, 0x0C, 0x1000},
    {7, 5, 0xDB, 0x1000},
    {8, 6, 0x14, 0x1000},
    {9, 0, 0x18, 0x1000},
    {2, 0, 0x1D, 0x0000},
    {2, 0, 0x1D, 0x0000},
};

extern s16 D_global_asm_8076AEE2;
extern f32 D_global_asm_8076AEE4; // x
extern f32 D_global_asm_8076AEE8; // y
extern f32 D_global_asm_8076AEEC; // z
extern s16 D_global_asm_8076AEF0;

extern s32 D_global_asm_807FD56C;
extern u16 D_global_asm_807FD570; // Tranferred actor behaviour index (through loading zone)

extern ExitData *exit_array;
extern ExitData D_global_asm_807FD574;
extern ExitData D_global_asm_807FC908;
extern ExitData D_global_asm_807FC918;
extern s16 D_global_asm_807FC930[];

void func_global_asm_806C7B00(void) {
    s16 i;
    for (i = 0; i < 0xE; i++) {
        D_global_asm_807FC930[i] = 0;
    }
}

s32 func_global_asm_806C7B34(void) {
    return D_global_asm_8075C410[current_character_index[0]].unk0;
}

void func_global_asm_806C7B50(Actors actorIndex, u8 arg1, Actor *player) {
    AppleAAD *temp_v0;

    spawnActor(actorIndex, 0x82);
    moveAndScaleActorToAnother(last_spawned_actor, player, 0.15f);
    temp_v0 = last_spawned_actor->PaaD;
    temp_v0->unk4 = player;
    temp_v0->unk8 = arg1;
}

void func_global_asm_806C7BAC(s32 arg0, s32 arg1) {
    // TODO: Is this aaD type actually correct? The args line up but that's all I know right now
    // Maybe run it through a debugger or something
    OtherAdditionalActorData *temp_v0;

    spawnActor(ACTOR_ROCKETBARREL_ON_KONG, 0x8C);
    moveAndScaleActorToAnother(last_spawned_actor, current_player, 0.15f);
    temp_v0 = last_spawned_actor->additional_actor_data;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
}

void func_global_asm_806C7C10(void) {
    cc_number_of_players = D_global_asm_80750AC0;
    character_change_array = NULL;
    if (cc_number_of_players >= 2) {
        switch (D_global_asm_80750AB8) {
            case 0:
                D_global_asm_80750AB4 = cc_number_of_players;
                break;
            case 1:
                D_global_asm_80750AB4 = 1;
                break;
        }
    } else {
        D_global_asm_80750AB4 = 1;
        D_global_asm_80750AB8 = 0;
    }
}

Struct80750948 *func_global_asm_806C7C94(u8 arg0) {
    u8 i;
    s32 var_v1;
    Struct80750948 *var_a2;

    i = 0;
    var_v1 = 0;
    while (!var_v1) {
        if (cc_number_of_players == D_global_asm_80750948[i].unk0
            && D_global_asm_80750AB8 == D_global_asm_80750948[i].unk1
            && arg0 == D_global_asm_80750948[i].unk3
            && D_global_asm_80750948[i].unk2 & D_global_asm_80750ABC) {
            var_v1 = 1;
        } else {
            i++;
        }
    }
    return &D_global_asm_80750948[i];
}

// Delay slot problem with mips_to_c
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_global_asm_806C7D40.s")

void func_global_asm_806C80E4(void) {
    PlayerAdditionalActorData *PaaD;
    f32 sp30;
    f32 pad;
    f32 phi_f2;

    if (D_global_asm_807FD570 == ACTOR_STEEL_KEG) {
        phi_f2 = 20.0f;
    } else {
        phi_f2 = 0.0f;
    }
    sp30 = func_global_asm_80612794(player_pointer->y_rotation) * phi_f2;
    pad = func_global_asm_80612790(player_pointer->y_rotation) * phi_f2;
    func_global_asm_80689114(D_global_asm_807FD570, player_pointer->x_position + sp30, player_pointer->y_position + 7.0, player_pointer->z_position + pad, 0, 1.0f, player_pointer);
    PaaD = player_pointer->PaaD;
    PaaD->unk1F0 |= 0x1000000;
}

void func_global_asm_806C81DC(s16 arg0, s16 arg1) {
    CharacterChange *cc = character_change_array;
    cc->unk27A = arg1 - arg0;
    cc->unk272 = arg0;
    cc->unk276 = arg1;
    // TODO: What do these typecasts do and can we get rid of them?
    cc->unk280 = (f32)cc->unk278 / (f32)cc->unk27A;
}

// Unrolled loops
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_global_asm_806C8220.s")

extern s16 D_global_asm_807FD584;

extern f32 D_global_asm_80753578[];
extern f32 D_global_asm_807535E8[];

void func_global_asm_806C850C(s32 arg0, u8 arg1) {
    Struct8075C410 *sp2C;
    s32 i;

    if (cc_number_of_players >= 2) {
        current_character_index[arg1] = current_character_index[func_global_asm_8060AB38(arg1)];
    }
    if ((!arg1) && (current_map == MAP_MAIN_MENU)) {
        current_character_index[0] = 0;
    }
    sp2C = &D_global_asm_8075C410[current_character_index[arg1]];
    spawnActor(sp2C->unk0, sp2C->unk8);
    last_spawned_actor->object_properties_bitfield &= ~0x1000;
    last_spawned_actor->object_properties_bitfield |= sp2C->unkC;
    last_spawned_actor->unk16E = 0x42;
    last_spawned_actor->unk16F = 0x42;
    last_spawned_actor->object_properties_bitfield |= 0x01000000;
    if (cc_number_of_players >= 2) {
        last_spawned_actor->unk64 |= 0x200;
    }
    last_spawned_actor->unk68 |= 0xC0;
    last_spawned_actor->animation_state->unk1C = malloc(0x100);
    last_spawned_actor->animation_state->unk1C->unk0 = 0;
    last_spawned_actor->animation_state->unk20 = malloc(0x200);
    last_spawned_actor->animation_state->unk20->unk0 = 0xFF;
    last_spawned_actor->animation_state->unk24 = malloc(0x200);
    last_spawned_actor->animation_state->unk24->unk0 = 0xFF;
    current_player = last_spawned_actor;
    extra_player_info_pointer = current_player->PaaD;
    extra_player_info_pointer->unk247 = -1;
    extra_player_info_pointer->unk1A4 = arg1;
    extra_player_info_pointer->unk11E = -1;
    extra_player_info_pointer->unk244 = 0;
    extra_player_info_pointer->unk120 = -0x64;
    D_global_asm_807FD584 = sp2C->unk4;
    extra_player_info_pointer->unk1EE = last_spawned_actor->unk58;
    func_global_asm_806E2C74(current_player);
    spawnActor(ACTOR_CAMERA, 0);
    extra_player_info_pointer->unk104 = last_spawned_actor;
    if (!arg1) {
        D_global_asm_807F5D10 = last_spawned_actor;
    }
    last_spawned_actor->object_properties_bitfield |= 0x100000;
    func_global_asm_806C8D20(current_player);
    extra_player_info_pointer->unk26 = 0x64;
    current_player->y_acceleration = D_global_asm_80753578[D_global_asm_807FD584];
    current_player->terminal_velocity = D_global_asm_807535E8[D_global_asm_807FD584];
    extra_player_info_pointer->unk250 = 0x78;
    extra_player_info_pointer->unkD4 = 0;
    extra_player_info_pointer->unkD8 = 0;
    extra_player_info_pointer->unkFC_s32 = 0;
    extra_player_info_pointer->unk100 = 0;
    extra_player_info_pointer->unk16 = 0;
    extra_player_info_pointer->unk10C = 0;
    extra_player_info_pointer->unk1A0 = 0;
    extra_player_info_pointer->unk1C0 = 0.15f;
    extra_player_info_pointer->unk1C4 = 0.15f;
    extra_player_info_pointer->unk1C8 = 0.15f;
    extra_player_info_pointer->unk1CC = 0.15f;
    extra_player_info_pointer->unk1D0 = 0.15f;
    extra_player_info_pointer->unk1D4 = 0.15f;
    extra_player_info_pointer->unk245 = 0;
    extra_player_info_pointer->unk21E = 0x1E;
    extra_player_info_pointer->unkC8 = -1;
    extra_player_info_pointer->unkCA = 0;
    extra_player_info_pointer->unkC8 = -1;
    extra_player_info_pointer->unk264 = -1;
    extra_player_info_pointer->unk258 = 1.0f;
    extra_player_info_pointer->unk25C = 1.0f;
    if (isFlagSet(0xCE, FLAG_TYPE_PERMANENT)) {
        extra_player_info_pointer->unk1F0 |= 0x100000;
    }
    func_global_asm_806C8220(1, current_player->unk178, current_player->unk58);
    current_player->unk146 = 0;
    func_global_asm_806F09F0(current_player, current_player->unk58);
    current_player->unkDE = 0x400;
    extra_player_info_pointer->unk1B0 = 0;
    extra_player_info_pointer->unk1AC = NULL;
    for (i = 0; i < 4; i++) {
        D_global_asm_807FD610[arg1].unk20[i] = D_global_asm_807FD610[arg1].unk28;
        D_global_asm_807FD610[arg1].unk10[i] = D_global_asm_807FD610[arg1].unk4;
    }
    func_global_asm_806CFF9C(current_player);
    func_global_asm_806C90C4(arg0);
    func_global_asm_806C8984();
}

extern s16 D_global_asm_807FD584;
extern s16 D_global_asm_80753354[];

void func_global_asm_806C8984(void) {
    f32 playerScale = -1.0f;
    switch (current_map) {
        case MAP_MAIN_MENU:
            spawnActor(ACTOR_MAIN_MENU_CONTROLLER, 0);
            break;
        case MAP_SNIDES_HQ:
            spawnActor(ACTOR_MENU_SNIDE, 0);
            break;
        case MAP_DIVE_BARREL:
        case MAP_ORANGE_BARREL:
        case MAP_BARREL_BARREL:
        case MAP_VINE_BARREL:
            spawnActor(ACTOR_TRAINING_BARREL_CONTROLLER, 0);
            break;
        case MAP_ENGUARDE_ARENA:
        case MAP_RAMBI_ARENA:
            spawnActor(ACTOR_ARENA_CONTROLLER, 0);
            break;
        case MAP_GALLEON_SEAL_RACE:
            if (playerScale < 0.0f) {
                playerScale = 0.8f;
            }
            // fallthrough
        case MAP_CRANKYS_LAB:
            if (playerScale < 0.0f) {
                playerScale = 1.8f;
            }
            // fallthrough
        case MAP_FUNKYS_STORE:
            if (playerScale < 0.0f) {
                playerScale = 1.6f;
            }
            current_player->animation_state->scale[0] *= playerScale;
            current_player->animation_state->scale[1] *= playerScale;
            current_player->animation_state->scale[2] *= playerScale;
            break;
        case MAP_BEAVER_BOTHER_EASY:
        case MAP_BEAVER_BOTHER_NORMAL:
        case MAP_BEAVER_BOTHER_HARD:
            setYAccelerationFrom80753578();
            playActorAnimation(current_player, 0);
            func_global_asm_80613C48(current_player, 0, 0.0f, 0.0f);
            current_player->control_state = 0x7D;
            current_player->control_state_progress = 0;
            current_player->object_properties_bitfield &= 0xFFFF7FFF;
            current_player->shadow_opacity = 0;
            spawnActor(ACTOR_MINIGAME_BOTHER_KLAPTRAP, 0x21);
            playActorAnimation(last_spawned_actor, 0x232);
            last_spawned_actor->unk11C = current_player;
            extra_player_info_pointer->vehicle_actor_pointer = last_spawned_actor;
            break;
        case MAP_JAPES_MINECART:
            func_global_asm_806C7B50(ACTOR_MINECART, 0, current_player);
            break;
        case MAP_BATTY_BARREL_BANDIT_EASY:
        case MAP_BATTY_BARREL_BANDIT_EASY_2:
        case MAP_BATTY_BARREL_BANDIT_NORMAL:
        case MAP_BATTY_BARREL_BANDIT_HARD:
            spawnActor(ACTOR_BANDIT_HANDLE, 0x94);
            extra_player_info_pointer->vehicle_actor_pointer = last_spawned_actor;
            break;
        case MAP_DK_RAP:
            func_global_asm_807215D0(0, 0);
            func_global_asm_807215AC(0x6B, 0x30, 0x50);
            func_global_asm_80721560(0x320, 0x82, 0, 0xFF, 0xFF, 0xFF);
            func_critter_80028840();
            // fallthrough
        case MAP_NINTENDO_LOGO:
        case MAP_TITLE_SCREEN_NOT_FOR_RESALE_VERSION:
            current_player->control_state = 0x77;
            current_player->control_state_progress = 0;
            break;
        case MAP_BUSY_BARREL_BARRAGE_EASY:
        case MAP_BUSY_BARREL_BARRAGE_NORMAL:
        case MAP_BUSY_BARREL_BARRAGE_HARD:
            func_global_asm_806F0D68(current_player);
            extra_player_info_pointer->unk48 = D_global_asm_80753354[D_global_asm_807FD584];
            current_player->control_state = 0x62;
            current_player->control_state_progress = 0;
            playAnimation(current_player, 0x52);
            break;
        case MAP_KROOL_BARREL_CHUNKY_SHOOTING_GAME:
            current_player->control_state = 0x5F;
            current_player->control_state_progress = 0;
            playAnimation(current_player, 0x4B);
            break;
        case MAP_FUNGI_DOGADON:
        case MAP_DK_ISLES_DK_THEATRE:
        case MAP_AZTEC_DOGADON:
        case MAP_BLOOPERS_ENDING:
        case MAP_KLUMSY_ENDING:
            current_player->control_state = 0x77;
            current_player->control_state_progress = 0;
            break;
        case MAP_GALLEON_PUFFTOSS:
            func_global_asm_80690470(current_player);
            break;
    }
}

void func_global_asm_806C8D20(Actor *arg0) {
    arg0->noclip_byte = 0x3C; // Normal collision
}

u8 func_global_asm_806C8D2C(s16 arg0) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (arg0 == D_global_asm_8075C410[i].unk0) {
            return D_global_asm_8075C410[i].unk4;
        }
    }
    return 0;
}

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_global_asm_806C8DE0.s")

// u8 func_global_asm_806C8D2C(s16, s32);

/*
s32 func_global_asm_806C8DE0(s32 playerIndex) {
    s32 phi_v1;
    PlayerAdditionalActorData *PaaD;
    Actor *Player;

    phi_v1 = current_character_index[playerIndex];
    switch (phi_v1) {
        case 6:
        case 7:
            Player = character_change_array[playerIndex].player_pointer;
            PaaD = Player->PaaD;
            phi_v1 = func_global_asm_806C8D2C(PaaD->unk1EE);
    }
    return phi_v1;
}
*/

// TODO: Quite fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_global_asm_806C8E58.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    s32 unkC;
} Struct806C8F8C_arg0;

void func_global_asm_806C8F8C(Struct806C8F8C_arg0 *arg0);

/*
void func_global_asm_806C8E58(s16 arg0) {
    u8 var_a1;
    u8 var_v0;
    u8 *temp_v1;
    u8 temp_t3;

    temp_v1 = &current_character_index[cc_player_index];
    var_a1 = 0;
    var_v0 = 0;
    *temp_v1 = 0;
    while (var_a1 == 0) {
        if (arg0 == D_global_asm_8075C410[var_v0].unk0) {
            var_a1 = 1;
        } else {
            var_v0++;
            *temp_v1 = var_v0;
        }
    }
    func_global_asm_806C8F8C(&D_global_asm_8075C410[var_v0]);
}
*/

void func_global_asm_806C8EE8(void) {
    current_character_index[cc_player_index]++;
    current_character_index[cc_player_index] %= 8;
    extra_player_info_pointer->unk8C = 0;
    func_global_asm_806C8F8C(&D_global_asm_8075C410[current_character_index[cc_player_index]]);
    func_global_asm_8060098C(func_global_asm_806C9C80, 0x14, cc_player_index, 0, 0);
}

void func_global_asm_806C8F8C(Struct806C8F8C_arg0 *arg0) {
    current_player->unk58 = arg0->unk0;
    D_global_asm_807FD584 = arg0->unk4;
    func_global_asm_806136B4(current_player);
    func_global_asm_8066E21C(current_player->ledge_info_pointer);
    func_global_asm_806134B4(current_player, arg0->unkA);
    current_player->ledge_info_pointer = func_global_asm_80665F24(current_player);
    current_player->object_properties_bitfield &= -0x1001;
    current_player->object_properties_bitfield |= arg0->unkC;
    current_player->animation_state->unk1C = malloc(0x100);
    current_player->animation_state->unk1C->unk0 = 0;
    current_player->animation_state->unk20 = malloc(0x100);
    current_player->animation_state->unk20->unk0 = 0xFF;
    current_player->animation_state->unk24 = malloc(0x100);
    current_player->animation_state->unk24->unk0 = 0xFF;
    func_global_asm_806C8220(1, current_player->unk178, current_player->unk58);
    func_global_asm_806F833C(0);
}

void func_global_asm_806C90C4(s32 exitIndex) {
    PlayerAdditionalActorData *PaaD;
    ExitData *exit;

    PaaD = current_player->PaaD;
    exit = getExitData(exitIndex);
    D_global_asm_8076AEE2 = 0;
    global_properties_bitfield &= -0x401;
    switch (exit->has_autowalk) {
        case 2:
            current_player->control_state = 0x4F;
            current_player->control_state_progress = 3;
            func_global_asm_80614D00(current_player, 0.5f, 0);
            PaaD->unk50 = 1;
            current_player->unk6A |= 4;
            func_global_asm_8067ACB4(current_player);
            playAnimation(current_player, 0x34);
            // Fallthrough
        case 0:
            current_player->unkAC = -10000.0f;
            current_player->x_position = exit->x_pos;
            current_player->y_position = current_player->unkA0 = exit->y_pos;
            current_player->z_position = exit->z_pos;
            current_player->y_rotation = (exit->angle / 255.0) * 4095.0;
            current_player->unkEE = current_player->y_rotation;
            break;
        case 1:
            func_global_asm_806F39E8(current_player, exit, 0x32);
    }
    current_player->unk6A &= ~0x200;
    PaaD->unk104->unk15F = exit->unk7 <= 0 ? 1 : exit->unk7;
    if (exit->size & 1) {
        D_global_asm_80770DC9 = 1;
    }
}

void func_global_asm_806C92C4(s32 arg0) {
    func_global_asm_80672C30(current_player);
    func_global_asm_806C9434(arg0);
    current_player->unk9C = current_player->y_position;
}

void func_global_asm_806C9304(Actor *arg0, PlayerAdditionalActorData *arg1) {
    s32 i;

    if (character_change_array[arg1->unk1A4].unk2C0 != 1) {
        func_global_asm_806D0468(current_player, 1);
    }
    if (arg1->unk1C0 != arg0->animation_state->scale_x) {
        for (i = 0; i < 3; i++) {
            arg1->scale1CC[i] = arg1->scale1C0[i];
            arg0->animation_state->scale[i] = arg1->scale1C0[i];
        }
    }
}

void func_global_asm_806C93E4(Actor *arg0, PlayerAdditionalActorData *arg1) {
    func_global_asm_806F12FC(arg0);
    arg1->unk1F0 &= ~0x30;
    arg0->object_properties_bitfield |= 0x8000;
    arg0->shadow_opacity = 0xFF;
}

void func_global_asm_806C9434(s32 arg0) {
    s32 temp; // PAD
    s32 temp3; // PAD
    Actor178 *sp34;
    s32 temp2; // PAD
    PlayerProgress *sp2C;
    PlayerAdditionalActorData *temp_s2;
    u8 phi_s0;

    temp_s2 = current_player->additional_actor_data;
    sp34 = current_player->unk178;
    func_global_asm_806C8DE0(temp_s2->unk1A4);
    sp2C = &D_global_asm_807FC950[temp_s2->unk1A4];
    temp_s2->unk250 = 0x78;
    for (phi_s0 = 0; phi_s0 < 2; phi_s0++) {
        func_global_asm_80605314(current_player, phi_s0);
    }
    func_global_asm_806C90C4(arg0);
    func_global_asm_806C8220(0, sp34, current_player->unk58);
    func_global_asm_80709464(temp_s2->unk1A4);
    current_player->unkB8 = 0.0f;
    temp_s2->unk1F0 &= 0xF7FFFF5F;
    temp_s2->unk200 = 0;
    temp_s2->unk4 = 0.0f;
    if (cc_number_of_players >= 2) {
        func_multiplayer_800268DC(current_player, temp_s2, sp2C);
    }
    func_global_asm_806C9304(current_player, temp_s2);
    if (!func_global_asm_8061CB50()) {
        if (cc_number_of_players >= 2 && D_global_asm_80750AB8 == 1) {
            func_global_asm_8061EA78();
        } else {
            func_global_asm_8061EB04(current_player, temp_s2->unk1A4);
        }
    }
    func_global_asm_806C8D20(current_player);
    func_global_asm_806CFF9C(current_player);
    current_player->z_rotation = 0;
    current_player->x_rotation = 0;
}

void loadExits(Maps map) {
    exit_array = getPointerTableFile(0x17, map, 1, 1);
    number_of_exits = func_global_asm_8066B06C(0x17, map) / sizeof(ExitData);
    func_global_asm_806C9658(map); // Check galleon water level
    D_global_asm_807FC908.x_pos = D_global_asm_807FD574.x_pos;
    D_global_asm_807FC908.y_pos = D_global_asm_807FD574.y_pos;
    D_global_asm_807FC908.z_pos = D_global_asm_807FD574.z_pos;
    D_global_asm_807FC908.angle = 0;
}

void func_global_asm_806C9658(Maps map) {
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
    if (D_global_asm_8076AEE2 & 1) {
        D_global_asm_807FC918.x_pos = D_global_asm_8076AEE4;
        D_global_asm_807FC918.y_pos = D_global_asm_8076AEE8;
        D_global_asm_807FC918.z_pos = D_global_asm_8076AEEC;
        D_global_asm_807FC918.angle = 360.0 * (D_global_asm_8076AEF0 / 4095.0);
        return &D_global_asm_807FC918;
    }
    if (number_of_exits == 0) {
        return &D_global_asm_807FC908;
    }
    if (exitIndex >= number_of_exits) {
        return &exit_array[0];
    }
    return &exit_array[exitIndex];
}

// TODO: Any cleanup possible? Fiddly regalloc
s8 func_global_asm_806C9830(s8 arg0, Actor *arg1) {
    s8 phi_a2 = arg0;
    if (cc_number_of_players >= 2) {
        PlayerAdditionalActorData *PaaD = arg1->PaaD;
        CharacterChange *CC = &character_change_array[PaaD->unk1A4];
        if (CC->unk2A0) {
            Actor *actor = CC->unk2A0;
            if (actor->interactable & 1) {
                phi_a2 = -1;
                if (D_global_asm_807FBB64 & 0x04000000) {
                    func_multiplayer_800268C0(1);
                }
            } else if (actor->interactable & 4) {
                if ((actor->unk58 == ACTOR_PROJECTILE_ORANGE) || (actor->unk58 == ACTOR_PROJECTILE_ORANGE_KRUSHA)) {
                    phi_a2 = -3;
                    if (D_global_asm_807FBB64 & 0x04000000) {
                        func_multiplayer_800268C0(2);
                    }
                } else {
                    phi_a2 = -2;
                    if (D_global_asm_807FBB64 & 0x04000000) {
                        func_multiplayer_800268C0(1);
                    }
                }
            } else if (D_global_asm_807FBB64 & 0x04000000) {
                func_multiplayer_800268C0(1);
            }
        }
    }
    return phi_a2;
}

s32 func_global_asm_806C9974(u8 arg0, s8 arg1) {
    CharacterChange *temp2 = &character_change_array[arg0];
    PlayerProgress *temp = &D_global_asm_807FC950[arg0];

    temp2->unk2E2 |= 0x11;
    if ((cc_number_of_players >= 2) && (arg1 < 0) && (D_global_asm_807552EC == 1)) {
        func_multiplayer_80026E20(arg0, arg1);
    }
    if (arg1 < 0) {
        func_global_asm_8060E7EC(arg0, 0xFF, 5);
    }
    if (!(D_global_asm_807FBB64 & 0x800)) {
        temp->unk2FD += arg1;
    }
    if ((temp->health + temp->unk2FD) <= 0) {
        temp2->unk2E2 |= 0xC0;
        return TRUE;
    } else {
        return FALSE;
    }
}

void func_global_asm_806C9AE0(void) {
    PlayerProgress *PP;
    s32 playerIndex;
    s32 kongIndex;
    
    PP = D_global_asm_807FC950;
    for (playerIndex = 0; playerIndex < 4; playerIndex++, PP++) {
        bzero(PP, sizeof(PlayerProgress));
        if (D_global_asm_80750AC0 >= 2) {
            if (D_global_asm_807552E4.unk0 == 1) {
                for (kongIndex = 0; kongIndex < 6; kongIndex++) {
                    PP->character_progress[kongIndex].weapon = 7;
                }
            }
            for (kongIndex = 0; kongIndex < 6; kongIndex++) {
                PP->character_progress[kongIndex].simian_slam = 1;
            }
            PP->melons = 1;
        } else {
            PP->melons = 1;
        }
        func_global_asm_80709464(playerIndex);
    }
    func_global_asm_806C7B00();
    D_global_asm_80750ACC = 0;
    D_global_asm_807FD56C = 0;
}

void func_global_asm_806C9C1C(s32 playerIndex) {
    s32 i;

    for (i = 0; i < 5; i++) {
        changeCollectableCount(D_global_asm_80750B34[i], playerIndex, 9999);
    }
    func_global_asm_806F833C(0);
}

void func_global_asm_806C9C80(s32 playerIndex, s32 arg1, s32 arg2) {
    CharacterProgress *characterProgress = &D_global_asm_807FC950[playerIndex].character_progress[func_global_asm_806C8DE0(playerIndex)];

    characterProgress->weapon = 7;
    characterProgress->instrument = 0xF;
    characterProgress->simian_slam = 3;
    characterProgress->moves = 3;

    // Camera/Shockwave
    setFlag(0x179, TRUE, FLAG_TYPE_PERMANENT);
    func_global_asm_806C9C1C(playerIndex);
}

void func_global_asm_806C9D20(u8 playerIndex) {
    CharacterChange *cc = &character_change_array[playerIndex];
    cc->unk21C = cc->look_at_eye_x;
    cc->unk220 = cc->look_at_eye_y;
    cc->unk224 = cc->look_at_eye_z;
    cc->unk234 = cc->look_at_at_x;
    cc->unk238 = cc->look_at_at_y;
    cc->unk23C = cc->look_at_at_z;
}

// playerHasGoldenBananaInAtleastOneLevel()
s32 func_global_asm_806C9D7C(void) {
    s32 levelIndex;
    s32 found;
    CharacterProgress *CP;

    found = FALSE;
    CP = &D_global_asm_807FC950[0].character_progress[current_character_index[0]];
    for (levelIndex = 0; levelIndex < 8 && !found; levelIndex++) {
        found = CP->golden_bananas[levelIndex] > 0;
    }
    return found;
}
