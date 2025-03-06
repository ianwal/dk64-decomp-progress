#include "common.h"

// TODO: Add this to the aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s8 unk8;
} AppleAAD;

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
    moveAndScaleActorToAnother(gLastSpawnedActor, player, 0.15f);
    temp_v0 = gLastSpawnedActor->additional_actor_data;
    temp_v0->unk4 = player;
    temp_v0->unk8 = arg1;
}

void func_global_asm_806C7BAC(Actor *arg0, Actor *arg1) {
    // TODO: Is this aaD type actually correct? The args line up but that's all I know right now
    // Maybe run it through a debugger or something
    OtherAdditionalActorData *temp_v0;

    spawnActor(ACTOR_ROCKETBARREL_ON_KONG, 0x8C);
    moveAndScaleActorToAnother(gLastSpawnedActor, gCurrentPlayer, 0.15f);
    temp_v0 = gLastSpawnedActor->additional_actor_data;
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

void func_global_asm_80708BB8(CharacterChange2DC *);                 /* extern */
extern f32 D_global_asm_807444C4;
extern s32 D_global_asm_80744588[];
extern s8 D_global_asm_80750AD0;
extern OSContPad D_global_asm_807ECD10[];
extern u16 D_global_asm_807FD570;
extern s32 D_global_asm_807FBB68;

void func_global_asm_806C7D40(s32 arg0) {
    CharacterChange *temp_v0;
    PlayerProgress *temp_v0_3;
    s32 var_v0;
    s32 i;
    CharacterChange *temp_s0;
    Struct80750948 *temp_v0_2;

    character_change_array = malloc(cc_number_of_players * 0x2F0);
    func_global_asm_80611690(character_change_array);
    for (i = 0; i < cc_number_of_players; i++) {
        temp_s0 = &character_change_array[i];
        temp_s0->does_player_exist = TRUE;
        cc_player_index = i;
        func_global_asm_806C850C(arg0++, i);
        temp_s0->playerPointer = gCurrentPlayer;
        if (i == 0) {
            gPlayerPointer = gCurrentPlayer;
        }
        temp_s0->look_at_eye_z = 100.0f;
        temp_s0->look_at_eye_y = 100.0f;
        temp_s0->look_at_eye_x = 100.0f;
        temp_s0->unk224 = 100.0f;
        temp_s0->unk220 = 100.0f;
        temp_s0->unk21C = 100.0f;
        temp_s0->look_at_at_z = 0.0f;
        temp_s0->look_at_at_y = 0.0f;
        temp_s0->look_at_at_x = 0.0f;
        temp_s0->look_at_up_z = 0.0f;
        temp_s0->look_at_up_x = 0.0f;
        temp_s0->look_at_up_y = 1.0f;
        temp_v0_2 = func_global_asm_806C7C94(i);
        temp_s0->unk270[0] = temp_v0_2->unk4;
        temp_s0->unk270[1] = temp_v0_2->unk6;
        temp_s0->unk270[2] = temp_v0_2->unk8;
        temp_s0->unk270[3] = temp_v0_2->unkA;
        if (osViGetCurrentMode() == D_global_asm_80744588[(osTvType + osTvType) + 1]) {
            temp_s0->unk270[0] <<= 1;
            temp_s0->unk270[1] <<= 1;
            temp_s0->unk270[2]++;
            temp_s0->unk270[2] <<= 1;
            temp_s0->unk270[2]--;
            temp_s0->unk270[3]++;
            temp_s0->unk270[3] <<= 1;
            temp_s0->unk270[3]--;
        }
        temp_s0->unk278_arr[0] = temp_s0->unk270[2] - temp_s0->unk270[0];
        temp_s0->unk278_arr[1] = temp_s0->unk270[3] - temp_s0->unk270[1];
        temp_s0->fov_y = 45.0f;
        temp_s0->near = 10.0f;
        temp_s0->unk280 = (f32)temp_s0->unk278_arr[0] / temp_s0->unk278_arr[1];
        temp_s0->far = D_global_asm_807444C4;
        temp_s0->chunk = 0;
        temp_s0->unk294 = &D_global_asm_807ECD10[i];
        temp_s0->new_controller_inputs = &newly_pressed_input[i];
        temp_s0->action_initiated = -1;
        temp_s0->unk2C0 = 1;
        temp_s0->unk2C1 = 1;
        temp_s0->unk2EA = 0;
        temp_s0->unk2EB = 0;
        func_global_asm_80708BB8(&temp_s0->unk2DC);
        if (
            ((D_global_asm_807FBB64 & 1) && (!(D_global_asm_807FBB68 & 2))) ||
            (D_global_asm_807FC950[i].health + D_global_asm_807FC950[i].unk2FD) <= 0
        ) {
            func_global_asm_80709464(i);
        }
    }
    if (D_global_asm_807FD570 != 0) {
        func_global_asm_806C80E4();
        D_global_asm_807FD570 = 0;
    }
    if (cc_number_of_players >= 2) {
        spawnActor(ACTOR_UNKNOWN_318, 0);
    }
    var_v0 = D_global_asm_80750AB8 == 0;
    if (var_v0 != 0) {
        var_v0 = ((s32) cc_number_of_players < 2) ^ 1;
    }
    D_global_asm_80750AD0 = var_v0;
}



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
    sp30 = func_global_asm_80612794(gPlayerPointer->y_rotation) * phi_f2;
    pad = func_global_asm_80612790(gPlayerPointer->y_rotation) * phi_f2;
    func_global_asm_80689114(D_global_asm_807FD570, gPlayerPointer->x_position + sp30, gPlayerPointer->y_position + 7.0, gPlayerPointer->z_position + pad, 0, 1.0f, gPlayerPointer);
    PaaD = gPlayerPointer->PaaD;
    PaaD->unk1F0 |= 0x1000000;
}

void func_global_asm_806C81DC(s16 arg0, s16 arg1) {
    CharacterChange *cc = character_change_array;
    cc->unk27A = arg1 - arg0;
    cc->unk270[1] = arg0;
    cc->unk270[3] = arg1;
    // TODO: What do these typecasts do and can we get rid of them?
    cc->unk280 = (f32)cc->unk278 / (f32)cc->unk27A;
}

// Unrolled loops
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CC800/func_global_asm_806C8220.s")

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
    gLastSpawnedActor->object_properties_bitfield &= ~0x1000;
    gLastSpawnedActor->object_properties_bitfield |= sp2C->unkC;
    gLastSpawnedActor->unk16E = 0x42;
    gLastSpawnedActor->unk16F = 0x42;
    gLastSpawnedActor->object_properties_bitfield |= 0x01000000;
    if (cc_number_of_players >= 2) {
        gLastSpawnedActor->unk64 |= 0x200;
    }
    gLastSpawnedActor->unk68 |= 0xC0;
    gLastSpawnedActor->animation_state->unk1C = malloc(0x100);
    gLastSpawnedActor->animation_state->unk1C->unk0 = 0;
    gLastSpawnedActor->animation_state->unk20 = malloc(0x200);
    gLastSpawnedActor->animation_state->unk20->unk0 = 0xFF;
    gLastSpawnedActor->animation_state->unk24 = malloc(0x200);
    gLastSpawnedActor->animation_state->unk24->unk0 = 0xFF;
    gCurrentPlayer = gLastSpawnedActor;
    extra_player_info_pointer = gCurrentPlayer->PaaD;
    extra_player_info_pointer->unk247 = -1;
    extra_player_info_pointer->unk1A4 = arg1;
    extra_player_info_pointer->unk11E = -1;
    extra_player_info_pointer->unk244 = 0;
    extra_player_info_pointer->unk120 = -0x64;
    D_global_asm_807FD584 = sp2C->unk4;
    extra_player_info_pointer->unk1EE = gLastSpawnedActor->unk58;
    func_global_asm_806E2C74(gCurrentPlayer);
    spawnActor(ACTOR_CAMERA, 0);
    extra_player_info_pointer->unk104 = gLastSpawnedActor;
    if (!arg1) {
        D_global_asm_807F5D10 = gLastSpawnedActor;
    }
    gLastSpawnedActor->object_properties_bitfield |= 0x100000;
    func_global_asm_806C8D20(gCurrentPlayer);
    extra_player_info_pointer->unk26 = 0x64;
    gCurrentPlayer->y_acceleration = D_global_asm_80753578[D_global_asm_807FD584];
    gCurrentPlayer->terminal_velocity = D_global_asm_807535E8[D_global_asm_807FD584];
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
    if (isFlagSet(PERMFLAG_PROGRESS_IS_NIGHTTIME, FLAG_TYPE_PERMANENT)) {
        extra_player_info_pointer->unk1F0 |= 0x100000;
    }
    func_global_asm_806C8220(1, gCurrentPlayer->unk178, gCurrentPlayer->unk58);
    gCurrentPlayer->unk146 = 0;
    func_global_asm_806F09F0(gCurrentPlayer, gCurrentPlayer->unk58);
    gCurrentPlayer->unkDE = 0x400;
    extra_player_info_pointer->unk1B0 = 0;
    extra_player_info_pointer->unk1AC = NULL;
    for (i = 0; i < 4; i++) {
        D_global_asm_807FD610[arg1].unk20[i] = D_global_asm_807FD610[arg1].unk28;
        D_global_asm_807FD610[arg1].unk10[i] = D_global_asm_807FD610[arg1].unk4;
    }
    func_global_asm_806CFF9C(gCurrentPlayer);
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
            gCurrentPlayer->animation_state->scale[0] *= playerScale;
            gCurrentPlayer->animation_state->scale[1] *= playerScale;
            gCurrentPlayer->animation_state->scale[2] *= playerScale;
            break;
        case MAP_BEAVER_BOTHER_EASY:
        case MAP_BEAVER_BOTHER_NORMAL:
        case MAP_BEAVER_BOTHER_HARD:
            setYAccelerationFrom80753578();
            playActorAnimation(gCurrentPlayer, 0);
            func_global_asm_80613C48(gCurrentPlayer, 0, 0.0f, 0.0f);
            gCurrentPlayer->control_state = 0x7D;
            gCurrentPlayer->control_state_progress = 0;
            gCurrentPlayer->object_properties_bitfield &= 0xFFFF7FFF;
            gCurrentPlayer->shadow_opacity = 0;
            spawnActor(ACTOR_MINIGAME_BOTHER_KLAPTRAP, 0x21);
            playActorAnimation(gLastSpawnedActor, 0x232);
            gLastSpawnedActor->unk11C = gCurrentPlayer;
            extra_player_info_pointer->vehicle_actor_pointer = gLastSpawnedActor;
            break;
        case MAP_JAPES_MINECART:
            func_global_asm_806C7B50(ACTOR_MINECART, 0, gCurrentPlayer);
            break;
        case MAP_BATTY_BARREL_BANDIT_EASY:
        case MAP_BATTY_BARREL_BANDIT_EASY_2:
        case MAP_BATTY_BARREL_BANDIT_NORMAL:
        case MAP_BATTY_BARREL_BANDIT_HARD:
            spawnActor(ACTOR_BANDIT_HANDLE, 0x94);
            extra_player_info_pointer->vehicle_actor_pointer = gLastSpawnedActor;
            break;
        case MAP_DK_RAP:
            func_global_asm_807215D0(0, 0);
            func_global_asm_807215AC(0x6B, 0x30, 0x50);
            func_global_asm_80721560(0x320, 0x82, 0, 0xFF, 0xFF, 0xFF);
            func_critter_80028840();
            // fallthrough
        case MAP_NINTENDO_LOGO:
        case MAP_TITLE_SCREEN_NOT_FOR_RESALE_VERSION:
            gCurrentPlayer->control_state = 0x77;
            gCurrentPlayer->control_state_progress = 0;
            break;
        case MAP_BUSY_BARREL_BARRAGE_EASY:
        case MAP_BUSY_BARREL_BARRAGE_NORMAL:
        case MAP_BUSY_BARREL_BARRAGE_HARD:
            func_global_asm_806F0D68(gCurrentPlayer);
            extra_player_info_pointer->unk48 = D_global_asm_80753354[D_global_asm_807FD584];
            gCurrentPlayer->control_state = 0x62;
            gCurrentPlayer->control_state_progress = 0;
            playAnimation(gCurrentPlayer, 0x52);
            break;
        case MAP_KROOL_BARREL_CHUNKY_SHOOTING_GAME:
            gCurrentPlayer->control_state = 0x5F;
            gCurrentPlayer->control_state_progress = 0;
            playAnimation(gCurrentPlayer, 0x4B);
            break;
        case MAP_FUNGI_DOGADON:
        case MAP_DK_ISLES_DK_THEATRE:
        case MAP_AZTEC_DOGADON:
        case MAP_BLOOPERS_ENDING:
        case MAP_KLUMSY_ENDING:
            gCurrentPlayer->control_state = 0x77;
            gCurrentPlayer->control_state_progress = 0;
            break;
        case MAP_GALLEON_PUFFTOSS:
            func_global_asm_80690470(gCurrentPlayer);
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

s32 func_global_asm_806C8DE0(s32 playerIndex) {
    s32 phi_v1;
    PlayerAdditionalActorData *PaaD;
    Actor *Player;

    phi_v1 = current_character_index[playerIndex];
    switch (phi_v1) {
        case 6:
        case 7:
            Player = character_change_array[playerIndex].playerPointer;
            PaaD = Player->AAD_as_array[playerIndex];
            phi_v1 = func_global_asm_806C8D2C(PaaD->unk1EE);
    }
    return phi_v1;
}

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
    s32 *var_a2;
    s32 valid;
    s32 i;
    u8 j;

    valid = FALSE;
    i = 0 & 0xFF;
    current_character_index[cc_player_index] = 0;
    var_a2 = &D_global_asm_8075C410[i];
    while (!valid) {
        j = i + 1;
        if (arg0 == *var_a2) {
            valid = TRUE;
        } else {
            i = j & 0xFF;
            var_a2 = &D_global_asm_8075C410[i];
            current_character_index[cc_player_index] = j;
        }
    }
    func_global_asm_806C8F8C(var_a2);
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
    gCurrentPlayer->unk58 = arg0->unk0;
    D_global_asm_807FD584 = arg0->unk4;
    func_global_asm_806136B4(gCurrentPlayer);
    func_global_asm_8066E21C(gCurrentPlayer->ledge_info_pointer);
    func_global_asm_806134B4(gCurrentPlayer, arg0->unkA);
    gCurrentPlayer->ledge_info_pointer = func_global_asm_80665F24(gCurrentPlayer);
    gCurrentPlayer->object_properties_bitfield &= -0x1001;
    gCurrentPlayer->object_properties_bitfield |= arg0->unkC;
    gCurrentPlayer->animation_state->unk1C = malloc(0x100);
    gCurrentPlayer->animation_state->unk1C->unk0 = 0;
    gCurrentPlayer->animation_state->unk20 = malloc(0x100);
    gCurrentPlayer->animation_state->unk20->unk0 = 0xFF;
    gCurrentPlayer->animation_state->unk24 = malloc(0x100);
    gCurrentPlayer->animation_state->unk24->unk0 = 0xFF;
    func_global_asm_806C8220(1, gCurrentPlayer->unk178, gCurrentPlayer->unk58);
    func_global_asm_806F833C(0);
}

void func_global_asm_806C90C4(s32 exitIndex) {
    PlayerAdditionalActorData *PaaD;
    ExitData *exit;

    PaaD = gCurrentPlayer->PaaD;
    exit = getExitData(exitIndex);
    D_global_asm_8076AEE2 = 0;
    global_properties_bitfield &= -0x401;
    switch (exit->has_autowalk) {
        case 2:
            gCurrentPlayer->control_state = 0x4F;
            gCurrentPlayer->control_state_progress = 3;
            func_global_asm_80614D00(gCurrentPlayer, 0.5f, 0);
            PaaD->unk50 = 1;
            gCurrentPlayer->unk6A |= 4;
            func_global_asm_8067ACB4(gCurrentPlayer);
            playAnimation(gCurrentPlayer, 0x34);
            // Fallthrough
        case 0:
            gCurrentPlayer->unkAC = -10000.0f;
            gCurrentPlayer->x_position = exit->pos.x;
            gCurrentPlayer->y_position = gCurrentPlayer->unkA0 = exit->pos.y;
            gCurrentPlayer->z_position = exit->pos.z;
            gCurrentPlayer->y_rotation = (exit->angle / 255.0) * 4095.0;
            gCurrentPlayer->unkEE = gCurrentPlayer->y_rotation;
            break;
        case 1:
            func_global_asm_806F39E8(gCurrentPlayer, exit, 0x32);
    }
    gCurrentPlayer->unk6A &= ~0x200;
    PaaD->unk104->unk15F = exit->unk7 <= 0 ? 1 : exit->unk7;
    if (exit->size & 1) {
        D_global_asm_80770DC9 = 1;
    }
}

void func_global_asm_806C92C4(s32 arg0) {
    func_global_asm_80672C30(gCurrentPlayer);
    func_global_asm_806C9434(arg0);
    gCurrentPlayer->unk9C = gCurrentPlayer->y_position;
}

void func_global_asm_806C9304(Actor *arg0, PlayerAdditionalActorData *arg1) {
    s32 i;

    if (character_change_array[arg1->unk1A4].unk2C0 != 1) {
        func_global_asm_806D0468(gCurrentPlayer, 1);
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

    temp_s2 = gCurrentPlayer->additional_actor_data;
    sp34 = gCurrentPlayer->unk178;
    func_global_asm_806C8DE0(temp_s2->unk1A4);
    sp2C = &D_global_asm_807FC950[temp_s2->unk1A4];
    temp_s2->unk250 = 0x78;
    for (phi_s0 = 0; phi_s0 < 2; phi_s0++) {
        func_global_asm_80605314(gCurrentPlayer, phi_s0);
    }
    func_global_asm_806C90C4(arg0);
    func_global_asm_806C8220(0, sp34, gCurrentPlayer->unk58);
    func_global_asm_80709464(temp_s2->unk1A4);
    gCurrentPlayer->unkB8 = 0.0f;
    temp_s2->unk1F0 &= 0xF7FFFF5F;
    temp_s2->unk200 = 0;
    temp_s2->unk4 = 0.0f;
    if (cc_number_of_players >= 2) {
        func_multiplayer_800268DC(gCurrentPlayer, temp_s2, sp2C);
    }
    func_global_asm_806C9304(gCurrentPlayer, temp_s2);
    if (!func_global_asm_8061CB50()) {
        if (cc_number_of_players >= 2 && D_global_asm_80750AB8 == 1) {
            func_global_asm_8061EA78();
        } else {
            func_global_asm_8061EB04(gCurrentPlayer, temp_s2->unk1A4);
        }
    }
    func_global_asm_806C8D20(gCurrentPlayer);
    func_global_asm_806CFF9C(gCurrentPlayer);
    gCurrentPlayer->z_rotation = 0;
    gCurrentPlayer->x_rotation = 0;
}

void loadExits(Maps map) {
    exit_array = getPointerTableFile(TABLE_23_EXITS, map, 1, 1);
    number_of_exits = func_global_asm_8066B06C(TABLE_23_EXITS, map) / sizeof(ExitData);
    func_global_asm_806C9658(map); // Check galleon water level
    D_global_asm_807FC908.pos.x = D_global_asm_807FD574.pos.x;
    D_global_asm_807FC908.pos.y = D_global_asm_807FD574.pos.y;
    D_global_asm_807FC908.pos.z = D_global_asm_807FD574.pos.z;
    D_global_asm_807FC908.angle = 0;
}

void func_global_asm_806C9658(Maps map) {
    if (map == MAP_GALLEON) {
        // Galleon: Water Level Raised
        if (isFlagSet(PERMFLAG_PROGRESS_IS_GALLEON_WATER_RAISED, FLAG_TYPE_PERMANENT)) {
            exit_array[18].pos.y = 1629;
            exit_array[23].pos.y = 1629;
        } else {
            exit_array[18].pos.y = 1574;
            exit_array[23].pos.y = 1574;
        }
    }
}

ExitData *getExitData(s32 exitIndex) {
    if (D_global_asm_8076AEE2 & 1) {
        D_global_asm_807FC918.pos.x = D_global_asm_8076AEE4;
        D_global_asm_807FC918.pos.y = D_global_asm_8076AEE8;
        D_global_asm_807FC918.pos.z = D_global_asm_8076AEEC;
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

s32 func_global_asm_806C9974(u8 playerIndex, s8 arg1) {
    CharacterChange *temp2 = &character_change_array[playerIndex];
    PlayerProgress *temp = &D_global_asm_807FC950[playerIndex];

    temp2->unk2DC.unk6 |= 0x11;
    if ((cc_number_of_players >= 2) && (arg1 < 0) && (D_global_asm_807552EC == 1)) {
        func_multiplayer_80026E20(playerIndex, arg1);
    }
    if (arg1 < 0) {
        func_global_asm_8060E7EC(playerIndex, 0xFF, 5);
    }
    if (!(D_global_asm_807FBB64 & 0x800)) {
        temp->unk2FD += arg1;
    }
    if ((temp->health + temp->unk2FD) <= 0) {
        temp2->unk2DC.unk6 |= 0xC0;
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
    setFlag(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, TRUE, FLAG_TYPE_PERMANENT);
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
