#include <ultra64.h>
#include "functions.h"

void func_race_80026004(Actor178*, s32, f32);

void func_global_asm_806CD424(s16, f32, f32);

extern s16 D_global_asm_807530B0[];
extern f32 D_global_asm_807531C4[];
extern f32 D_global_asm_807531FC[];
extern f32 D_global_asm_80753250[];
extern f32 D_global_asm_807534E4[];
extern f32 D_global_asm_80753500[];
extern s16 D_global_asm_8075351C[];
extern f32 D_global_asm_807535CC[];
extern s16 D_global_asm_807537FC[];
extern s16 D_global_asm_8075380C[];
extern s16 D_global_asm_8075383C[];
extern s16 D_global_asm_8075384C[];
extern f32 D_global_asm_80753908[];
extern f32 D_global_asm_80753924[];
extern f32 D_global_asm_80753940[];
extern s16 D_global_asm_807539DC[];
extern s16 D_global_asm_807539EC[];
extern f32 D_global_asm_80753D70[];
extern f32 D_global_asm_80753D8C[];

extern s32 D_global_asm_80767CC0;

extern u32 D_global_asm_807FBB68;
extern s32 D_global_asm_807FD6F0[];
extern s16 D_global_asm_807FD6F2;

extern void (*action_initiation_function_list[])(void);

u8 setAction(s16 actionIndex, Actor *actor, u8 playerIndex) {
    if (character_change_array[playerIndex].action_initiated < actionIndex) {
        character_change_array[playerIndex].action_initiated = actionIndex;
        character_change_array[playerIndex].unk2A0 = actor;
        character_change_array[playerIndex].unk2A8 = D_global_asm_807FD6F0[0];
        character_change_array[playerIndex].unk2AC = D_global_asm_807FD6F0[1];
        character_change_array[playerIndex].unk2B0 = D_global_asm_807FD6F0[2];
        if (actor) {
            character_change_array[playerIndex].unk2A4 = actor->unk54;
        }
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806EB178(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_global_asm_807FD6F0[0] = arg1;
    D_global_asm_807FD6F0[1] = arg2;
    D_global_asm_807FD6F0[2] = arg3;
}

void func_global_asm_806EB194(void) {
    if (character_change_array[cc_player_index].action_initiated >= 0) {
        if (character_change_array[cc_player_index].unk2A0
            && (!func_global_asm_8067AF44(character_change_array[cc_player_index].unk2A0) || character_change_array[cc_player_index].unk2A0->unk54 != character_change_array[cc_player_index].unk2A4)) {
            character_change_array[cc_player_index].unk2A0 = NULL;
        }
        action_initiation_function_list[character_change_array[cc_player_index].action_initiated]();
    }
    character_change_array[cc_player_index].action_initiated = -1;
}

void func_global_asm_806EB2B8(void) {
    func_global_asm_806CFECC();
    gCurrentActorPointer->control_state = 0x22;
    gCurrentActorPointer->control_state_progress = 0;
    gCurrentActorPointer->y_velocity = 100.0f;
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk2C = 100.0f;
    if (extra_player_info_pointer->unk3C == 0) {
        func_global_asm_806CD424(extra_player_info_pointer->unkA, extra_player_info_pointer->unk4, extra_player_info_pointer->unk38);
    }
    extra_player_info_pointer->unk2C = 10.0f;
    playActorAnimation(gCurrentActorPointer, 0x17B);
}

void func_global_asm_806EB364(void) {
    if (current_character_index[cc_player_index] == 6) {
        func_global_asm_806CFF9C(gCurrentPlayer);
        return;
    }
    gCurrentActorPointer->control_state = 0x3D;
    gCurrentActorPointer->control_state_progress = 0;
    if (extra_player_info_pointer->unk4E == 0x22) {
        playActorAnimation(gCurrentActorPointer, 0x131);
        return;
    }
    playAnimation(gCurrentActorPointer, 0xD);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_global_asm_806EB400.s")

/*
int func_global_asm_806EB400(Actor *arg0) {
    int phi_v1;
    PlayerAdditionalActorData *PaaD = arg0->PaaD;

    phi_v1 = PaaD->unkD4 == 0
        || character_change_array[cc_player_index].action_initiated == 0x3F;

    if ((current_character_index[cc_player_index] != 7) && PaaD->unk1F0 & 0x8000) {
        return 0;
    }
    switch (arg0->control_state) {
        case 0x34:
        case 0x36:
            phi_v1 &= 1;
            break;
        default:
            phi_v1 = 0;
    }
    return phi_v1;
}
*/

void func_global_asm_806EB4B4(void) {
    gCurrentActorPointer->control_state = 0x23;
    gCurrentActorPointer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0x3BC);
}

void func_global_asm_806EB4F8(void) {
    gCurrentActorPointer->control_state = 0x5F;
    gCurrentActorPointer->control_state_progress = 0;
    extra_player_info_pointer->unk1A3 = 0;
    playAnimation(gCurrentActorPointer, 0x4A);
}

void func_global_asm_806EB544(void) {
    s32 phi_a3;

    phi_a3 = 2;
    if (func_global_asm_806F8AD4(3, extra_player_info_pointer->unk1A4)) {
        phi_a3 = 3;
    }
    func_global_asm_806F8BC4(phi_a3, 0, 0);
    gCurrentActorPointer->control_state = 0x60;
    gCurrentActorPointer->control_state_progress = 0;
    extra_player_info_pointer->unk1A3 = 0;
    playAnimation(gCurrentActorPointer, 0x4B);
}

void func_global_asm_806EB5C8(void) {
    switch (current_character_index[cc_player_index]) {
        case 0:
        case 1:
        case 2:
            gCurrentActorPointer->y_velocity = 50.0f;
            gCurrentActorPointer->y_acceleration = -2.5f;
            break;
        case 3:
            gCurrentActorPointer->y_velocity = 140.0f;
            gCurrentActorPointer->y_acceleration = -20.0f;
            break;
        case 4:
        case 5:
            gCurrentActorPointer->y_velocity = 40.0f;
            gCurrentActorPointer->y_acceleration = -7.0f;
            break;
    }
    gCurrentActorPointer->control_state = 0x2A;
    gCurrentActorPointer->control_state_progress = 0;
    playAnimation(gCurrentActorPointer, 0x43);
    extra_player_info_pointer->unk64 = 0;
    extra_player_info_pointer->unkC8 = 0x32;
}

void func_global_asm_806EB6D8(void) {
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk38 = 170.0f;
    gCurrentActorPointer->control_state = 0x3F;
    gCurrentActorPointer->control_state_progress = 0;
    extra_player_info_pointer->unk4E = 0;
    playActorAnimation(gCurrentActorPointer, 0x14F);
}

void func_global_asm_806EB744(void) {
    s32 temp_t6; // TODO: Is this needed still? Padding
    s16 phi_v1;
    PlayerAdditionalActorData *PaaD;

    PaaD = extra_player_info_pointer->unk104->PaaD;
    phi_v1 = PaaD->unkB8;
    if (PaaD->unkEF != 0) {
        PaaD->unkF0_u8[0] = PaaD->unkEF;
        phi_v1 = 0x80;
    }
    func_global_asm_80627878(extra_player_info_pointer->unk104);
    func_global_asm_8062217C(extra_player_info_pointer->unk104, 0);
    PaaD->unkF0_u8[3] = character_change_array[cc_player_index].unk2A8;
    if (PaaD->unkF0_u8[3] == 3) {
        func_global_asm_80605314(gCurrentPlayer, 0);
        playSound(0x26, 0x7FFF, 63.0f, 1.0f, 0, 0);
        if (character_change_array[cc_player_index].unk2AC != 0) {
            func_global_asm_806F0D68(gCurrentPlayer);
        }
    }
    PaaD->unkBC = 0x80;
    extra_player_info_pointer->unk104->distance_from_floor = phi_v1;
    PaaD->unkB8 = phi_v1;
    PaaD->unkB2 = gCurrentPlayer->y_rotation + 0x800;
    gCurrentPlayer->unkB8 = 0.0f;
    gCurrentPlayer->unk6A |= 0x2000;
}

void func_global_asm_806EB8CC(void) {
    func_global_asm_806EB744();
    gCurrentPlayer->control_state = 2;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->control_state_progress = 0xA;
    if (extra_player_info_pointer->unk8C != 0) {
        playActorAnimation(gCurrentPlayer, 0x23);
    } else {
        playActorAnimation(gCurrentPlayer, 0x13);
    }
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
}

void func_global_asm_806EB964(void) {
    playSound(0x1B9, 0x7FFF, 63.0f, 1.0f, 0xA, 0);
    func_global_asm_806EB744();
    gCurrentPlayer->control_state = 4;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->control_state_progress = 0xA;
    playActorAnimation(gCurrentPlayer, 0x13);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
    func_global_asm_806F8BC4(6, 1, 0);
}

void func_global_asm_806EBA04(void) {
    func_global_asm_806EB744();
    gCurrentPlayer->control_state = 3;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->control_state_progress = 0xA;
    playActorAnimation(gCurrentPlayer, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
}

void func_global_asm_806EBA74(void) {
    func_global_asm_806EB744();
    gCurrentPlayer->control_state = 5;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->control_state_progress = 0xA;
    playActorAnimation(gCurrentPlayer, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
    func_global_asm_806F8BC4(6, 1, 0);
}

void func_global_asm_806EBAF4(void) {
    gCurrentActorPointer->control_state = 0x4F;
    gCurrentActorPointer->control_state_progress = 2;
    playAnimation(gCurrentActorPointer, 0x34);
    extra_player_info_pointer->unk50 = 0;
}

void func_global_asm_806EBB44(void) {
    global_properties_bitfield |= 0x4000;
    gCurrentPlayer->control_state = 1;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    func_global_asm_80614D48(gCurrentPlayer, 0.0f, 0.0f);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
}

void func_global_asm_806EBBD0(void) {
    gCurrentPlayer->control_state = 6;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    func_global_asm_80614D48(gCurrentPlayer, 0.0f, 0.0f);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    gCurrentPlayer->object_properties_bitfield &= -5;
}

void func_global_asm_806EBC60(void) {
    gCurrentPlayer->control_state = 0x6B;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    func_global_asm_80614D48(gCurrentPlayer, 0.0f, 0.0f);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    gCurrentPlayer->object_properties_bitfield &= -5;
}

void func_global_asm_806EBCF0(void) {
    gCurrentPlayer->control_state = 7;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentPlayer, 0x7A);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
    gCurrentPlayer->object_properties_bitfield &= ~0x40000;
    gCurrentPlayer->unkB8 = 0.0f;
}

void func_global_asm_806EBDAC(void) {
    extra_player_info_pointer->unk1F0 |= 8;
}

void func_global_asm_806EBDC4(void) {
    gCurrentPlayer->control_state = 0x69;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    func_global_asm_80614D48(gCurrentPlayer, 0, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    gCurrentPlayer->object_properties_bitfield &= ~0x1000000;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
}

void func_global_asm_806EBE8C(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    Actor178 *temp = vehicle->unk178;

    if (vehicle->control_state < 3) {
        func_race_80026004(temp, 0x1E, 1.0f);
    }
}

void func_global_asm_806EBED0(void) {
    extra_player_info_pointer->vehicle_actor_pointer->y_velocity += 200.0f;
    if (extra_player_info_pointer->vehicle_actor_pointer->y_velocity > 200.0f) {
        extra_player_info_pointer->vehicle_actor_pointer->y_velocity = 200.0f;
    }
    func_global_asm_8072DB68(3);
}

void func_global_asm_806EBF34(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    vehicle->y_velocity += 300.0f;
    func_global_asm_8072DB68(3);
}

void func_global_asm_806EBF74(void) {
    func_global_asm_806F1250(gCurrentPlayer);
    extra_player_info_pointer->unk1FE = character_change_array[cc_player_index].unk2A8;
}

void func_global_asm_806EBFD0(void) {
    playActorAnimation(gCurrentPlayer, 0x1A);
    gCurrentPlayer->control_state = 0x78;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EC014(void) {
    func_global_asm_806CF42C(gCurrentActorPointer);
    func_global_asm_806CFF9C(gCurrentActorPointer);
}

void func_global_asm_806EC044(void) {
    f32 sp24;

    sp24 = 1.0f;
    func_global_asm_806F0C18(gCurrentActorPointer);
    gCurrentPlayer->control_state = 0x6C;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0x3B);
    if (current_character_index[0] == 0) {
        sp24 = 0.5f;
    }
    func_global_asm_80614D00(gCurrentPlayer, sp24, 0.0f);
    func_global_asm_80672C30(gCurrentPlayer);
    // Optimization: Weird that they didn't reuse the result of the func_global_asm_80659470 call
    gCurrentPlayer->x_position = D_global_asm_807F6000[func_global_asm_80659470(gCurrentPlayer->unk10C)].x_position;
    gCurrentPlayer->y_position = D_global_asm_807F6000[func_global_asm_80659470(gCurrentPlayer->unk10C)].y_position + 5.0f;
    gCurrentPlayer->z_position = D_global_asm_807F6000[func_global_asm_80659470(gCurrentPlayer->unk10C)].z_position;
    gCurrentPlayer->x_rotation = 0;
    gCurrentPlayer->z_rotation = 0;
    playCutscene(gCurrentPlayer, 0, 1);
    func_global_asm_806F8BC4(0, 1, 0);
}

void func_global_asm_806EC1A8(void) {
    PlayerAdditionalActorData *temp_v0; // TODO: Probably not a PaaD
    s16 phi_v0;

    temp_v0 = extra_player_info_pointer->unk104->additional_actor_data;
    temp_v0->unkAC |= 4;
    gCurrentPlayer->control_state = 0x6D;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    gCurrentPlayer->object_properties_bitfield &= -2;
    if (current_map == MAP_GALLEON_SEAL_RACE) {
        gCurrentPlayer->noclip_byte = 1;
    }
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
    func_global_asm_80613C48(gCurrentPlayer, gCurrentPlayer->unk58 == ACTOR_DK ? 0x53 : 0x1C7, 0, 0);
}

void func_global_asm_806EC2CC(void) {
    Actor *vehicle;

    gCurrentPlayer->control_state = 0x75;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    gCurrentPlayer->object_properties_bitfield &= -2;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    moveAndScaleActorToAnother(gCurrentPlayer, vehicle, vehicle->animation_state->scale_x);
    gCurrentPlayer->noclip_byte = 1;
    func_global_asm_80613C48(gCurrentPlayer, 0x22A, 0, 0);
}

void func_global_asm_806EC3BC(void) {
    extra_player_info_pointer->unk12 = D_global_asm_807539EC[D_global_asm_807FD584];
    extra_player_info_pointer->unk14 = gCurrentActorPointer->y_rotation;
    extra_player_info_pointer->unk10 = D_global_asm_807539DC[D_global_asm_807FD584];
    gCurrentActorPointer->control_state = 0x4F;
    gCurrentActorPointer->control_state_progress = 1;
    if (gCurrentActorPointer->y_velocity > 0.0f) {
        gCurrentActorPointer->y_velocity = 0.0f;
    }
    playAnimation(gCurrentActorPointer, 0x36);
    func_global_asm_80613AF8(gCurrentActorPointer, 0x31, 0, 8.0f);
    func_global_asm_80614D00(gCurrentActorPointer, 0.5f, 0);
}

// doable, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_global_asm_806EC4AC.s")

extern s16 D_global_asm_807538D8[];
extern s16 D_global_asm_807538E8[];
extern s16 D_global_asm_807538F8[];
extern s16 D_global_asm_807539FC[];
extern f32 D_global_asm_80753A5C[];
extern f32 D_global_asm_80753988[];
extern s16 D_global_asm_8075388C[];

/*
// TODO: Doable, progress made, stack is still too big and there's a bunch of issues in the bottom half of the function
void func_global_asm_806EC4AC(void) {
    f32 temp_f12;
    f32 var_f14;
    f32 var_f20;
    f32 var_f2;

    func_global_asm_806CF398(gCurrentPlayer);
    var_f20 = ABS(D_global_asm_80753A5C[D_global_asm_807FD584]);
    var_f2 = gCurrentPlayer->unkA0 - gCurrentPlayer->unkAC;
    if (D_global_asm_807538D8[D_global_asm_807FD584] < var_f2) {
        var_f2 = D_global_asm_807538D8[D_global_asm_807FD584];
    }
    temp_f12 = D_global_asm_807538F8[D_global_asm_807FD584] - D_global_asm_807538E8[D_global_asm_807FD584];
    temp_f12 *= (var_f2 / D_global_asm_807538D8[D_global_asm_807FD584]);
    temp_f12 += D_global_asm_807538E8[D_global_asm_807FD584];
    temp_f12 -= ((gCurrentPlayer->unkAC - D_global_asm_8075388C[D_global_asm_807FD584]) - gCurrentPlayer->y_position);
    temp_f12 *= 40.0f;
    if (temp_f12 > 0.0f) {
        var_f14 = gCurrentPlayer->y_velocity * (0.5 + ((40.0f * var_f2) / (2.0f * (D_global_asm_807538D8[D_global_asm_807FD584] * 40.0f))));
        var_f20 = MAX((var_f14 * var_f14) / (2.0f * temp_f12), var_f20);
    } else {
        var_f14 = 0.0f;
    }
    gCurrentPlayer->y_velocity = var_f14;
    extra_player_info_pointer->unk1C = var_f20;
    extra_player_info_pointer->unk10 = 0;
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    gCurrentActorPointer->unkB8 = MIN(gCurrentActorPointer->unkB8, D_global_asm_80753988[D_global_asm_807FD584]);
    gCurrentPlayer->control_state = 0x4E;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentActorPointer, 0x35);
    extra_player_info_pointer->unk48 = D_global_asm_807539FC[D_global_asm_807FD584];
}
*/

void func_global_asm_806EC708(void) {
    gCurrentPlayer->control_state = 0x51;
    gCurrentPlayer->control_state_progress = 0;
    extra_player_info_pointer->unk54 = D_global_asm_80753908[D_global_asm_807FD584];
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
    extra_player_info_pointer->unk2C = D_global_asm_80753924[D_global_asm_807FD584];
    extra_player_info_pointer->unk30 = D_global_asm_80753940[D_global_asm_807FD584];
    playAnimation(gCurrentPlayer, 0x3E);
    func_global_asm_80614D00(gCurrentActorPointer, 1.0f, 0);
    extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
}

void func_global_asm_806EC800(void) {
    gCurrentPlayer->control_state = 0x50;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentActorPointer->y_velocity = -10.0f;
    extra_player_info_pointer->unk50 = 0;
    if (gCurrentActorPointer->unkB8 < D_global_asm_807531C4[D_global_asm_807FD584]) {
        gCurrentActorPointer->unkB8 = gCurrentActorPointer->unkB8;
    } else {
        gCurrentActorPointer->unkB8 = D_global_asm_807531C4[D_global_asm_807FD584];
    }
    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
    playAnimation(gCurrentPlayer, 0x3C);
}

extern Actor *D_global_asm_807FBB90;

void func_global_asm_806EC8C4(void) {
    extra_player_info_pointer->unk1B0 = D_global_asm_807FBB90;
    extra_player_info_pointer->unk1B4 = extra_player_info_pointer->unk1B0->unk54;
    switch ((u32)extra_player_info_pointer->unk1B0->unk58) {
        case 0x3D:
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x55:
        case 0x82:
            playActorAnimation(gCurrentPlayer, 0x1C8);
            break;
        default:
            playAnimation(gCurrentPlayer, 0x2B);
            break;
    }
    gCurrentPlayer->control_state = 0x47;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EC994(void) {
    playAnimation(gCurrentPlayer, 8);
    func_global_asm_80614D00(gCurrentPlayer, 1.0f, 0);
    func_global_asm_80613AF8(gCurrentPlayer, 0x2E, 0, 6.0f);
    gCurrentPlayer->control_state = 0x46;
    gCurrentPlayer->control_state_progress = 0;
    extra_player_info_pointer->unk38 = D_global_asm_807534E4[D_global_asm_807FD584];
    extra_player_info_pointer->unk2C = D_global_asm_80753500[D_global_asm_807FD584];
    extra_player_info_pointer->unk48 = D_global_asm_8075351C[D_global_asm_807FD584];
    extra_player_info_pointer->unk4C = -1;
}

void func_global_asm_806ECA74(void) {
    gCurrentActorPointer->control_state = 0x24;
    gCurrentActorPointer->control_state_progress = 0;
    playActorAnimation(gCurrentActorPointer, 0x1B2);
    extra_player_info_pointer->unkC8 = 0x32;
}

void func_global_asm_806ECAC4(void) {
    f32 phi_f0;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f0 = D_global_asm_80753D70[D_global_asm_807FD584];
    } else {
        phi_f0 = D_global_asm_80753D8C[D_global_asm_807FD584];
    }
    gCurrentPlayer->control_state = 0x5B;
    gCurrentPlayer->control_state_progress = 0;
    extra_player_info_pointer->unk10C = phi_f0;
    gCurrentPlayer->y_position = extra_player_info_pointer->unkF0_f32 - extra_player_info_pointer->unk10C;
    gCurrentPlayer->unkEE = gCurrentPlayer->unkF4 + 0x14;
    gCurrentPlayer->y_velocity = 0.0f;
    playAnimation(gCurrentPlayer, 0x75);
    func_global_asm_80614D90(gCurrentPlayer);
}

void func_global_asm_806ECBD4(void) {
    gCurrentPlayer->unk6A |= 0x40;
    gCurrentPlayer->unk64 &= -0x2001;
    gCurrentPlayer->control_state = 0x57;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentPlayer, 0x69);
    func_global_asm_80614D90(gCurrentPlayer);
}

void func_global_asm_806ECC48(void) {
    void *sp1C = extra_player_info_pointer->unk104->additional_actor_data;
    gCurrentPlayer->unk6A |= 0x40;
    gCurrentPlayer->unk64 &= -0x2001;
    gCurrentPlayer->control_state = 0x59;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentPlayer, 0x70);
    func_global_asm_80614D90(gCurrentPlayer);
    func_global_asm_8061F164(sp1C, 0x14);
}

void func_global_asm_806ECCDC(void) {
    void *temp_a2;

    temp_a2 = extra_player_info_pointer->unk104->additional_actor_data;
    gCurrentActorPointer->control_state = 0x17;
    gCurrentActorPointer->control_state_progress = 0;
    if ((D_global_asm_807FBB68 & 2) != 0) {
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584] * 1.3;
    } else {
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
    }
    gCurrentPlayer->unkB8 = extra_player_info_pointer->unk124;
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk3C = 0xA;
    playAnimation(gCurrentActorPointer, 0x10);
    func_global_asm_8061F164(temp_a2, 0x14);
}

void func_global_asm_806ECDD4(void) {
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        func_global_asm_806EEAF8(D_global_asm_807FBB68 & 2 ? 0 : 1);
    }
}

void func_global_asm_806ECE2C(void) {
    if ((cc_number_of_players >= 2) || (gCurrentPlayer->unk58 != ACTOR_CHUNKY) || (character_change_array[cc_player_index].unk2C0 == 1)) {
        gCurrentPlayer->y_velocity = 260.0f;
        setYAccelerationFrom80753578();
        extra_player_info_pointer->unk50 = 0;
        extra_player_info_pointer->unk48 = 0x64;
        playAnimation(gCurrentPlayer, 0x1F);
        func_global_asm_80614D00(gCurrentPlayer, 1.0f, 0);
        gCurrentPlayer->control_state = 0x30;
        gCurrentPlayer->control_state_progress = 0;
        func_global_asm_806CF42C(gCurrentPlayer);
    }
}

void func_global_asm_806ECF1C(void) {
    gCurrentPlayer->y_velocity = 260.0f;
    setYAccelerationFrom80753578();
    extra_player_info_pointer->unk50 = 0;
    playAnimation(gCurrentPlayer, 0x20);
    func_global_asm_80614D00(gCurrentPlayer, 1.0f, 0);
    gCurrentPlayer->control_state = 0x30;
    gCurrentPlayer->control_state_progress = 0;
    func_global_asm_806CF42C(gCurrentPlayer);
}

void func_global_asm_806ECF9C(void) {
    f32 temp_f0;

    extra_player_info_pointer->unk50 = D_global_asm_807537FC[D_global_asm_807FD584];
    extra_player_info_pointer->unk68 += D_global_asm_8075383C[D_global_asm_807FD584];
    temp_f0 = D_global_asm_8075384C[D_global_asm_807FD584];
    if (temp_f0 < extra_player_info_pointer->unk68) {
        extra_player_info_pointer->unk68 = temp_f0;
    }
    gCurrentPlayer->y_velocity = 0.0f;
    extra_player_info_pointer->unk50 = 0;
}

void func_global_asm_806ED050(void) {
    if ((gCurrentActorPointer->control_state != 2) && (current_character_index[cc_player_index] == 6)) {
        gCurrentActorPointer->control_state = 0x29;
        gCurrentActorPointer->control_state_progress = 0;
        playAnimation(gCurrentActorPointer, 0x3F);
        extra_player_info_pointer->unk64 = 0;
        extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
    }
}

void func_global_asm_806ED0FC(void) {
    Actor *temp_v0;

    func_global_asm_806CA2AC();
    func_global_asm_806CF398(gCurrentPlayer);
    extra_player_info_pointer->unk8C = 0;
    func_global_asm_806F0C18(gCurrentActorPointer);
    func_global_asm_80605314(gCurrentActorPointer, 0);
    func_global_asm_80605314(gCurrentActorPointer, 1);
    playAnimation(gCurrentPlayer, 0x21);
    temp_v0 = character_change_array[cc_player_index].unk2A0;
    if (temp_v0) {
        extra_player_info_pointer->unkBC = temp_v0->unk58;
        extra_player_info_pointer->unkBE = func_global_asm_80688E68(character_change_array[cc_player_index].unk2A0);
    } else {
        extra_player_info_pointer->unkBC = 0;
        extra_player_info_pointer->unkBE = -1;
    }
    if (gCurrentActorPointer->unk6A & 4) {
        gCurrentPlayer->control_state = 0x43;
        gCurrentPlayer->control_state_progress = 0;
    } else {
        gCurrentPlayer->control_state = 0x42;
        gCurrentPlayer->control_state_progress = 0;
    }
}

// TODO: Could use some cleanup, can we use ABS? Can we use a temp var for vehicle?
void func_global_asm_806ED244(void) {
    f32 phi_f2;
    f32 phi_f2_2;
    f32 phi_f2_3;
    f32 phi_f8;
    f32 phi_f2_4;
    f32 phi_f2_5;

    if (extra_player_info_pointer->vehicle_actor_pointer->unkB8 >= 0.0f) {
        func_global_asm_8072DB68(3);
    }
    if (character_change_array[cc_player_index].unk2A0) {
        if (character_change_array[cc_player_index].unk2A0->unkB8 != 0.0f) {
            if (character_change_array[cc_player_index].unk2A0->unkB8 > 0.0f) {
                phi_f2_4 = character_change_array[cc_player_index].unk2A0->unkB8;
            } else {
                phi_f2_4 = -character_change_array[cc_player_index].unk2A0->unkB8;
            }
            extra_player_info_pointer->vehicle_actor_pointer->unkB8 = 2.0 * phi_f2_4;
        } else {
            if (extra_player_info_pointer->vehicle_actor_pointer->unkB8 > 0.0f) {
                phi_f2 = extra_player_info_pointer->vehicle_actor_pointer->unkB8;
            } else {
                phi_f2 = -extra_player_info_pointer->vehicle_actor_pointer->unkB8;
            }
            if (phi_f2 < 50.0f) {
                extra_player_info_pointer->vehicle_actor_pointer->unkB8 = -50.0f;
            } else {
                if (extra_player_info_pointer->vehicle_actor_pointer->unkB8 > 0.0f) {
                    phi_f2_2 = extra_player_info_pointer->vehicle_actor_pointer->unkB8;
                } else {
                    phi_f2_2 = -extra_player_info_pointer->vehicle_actor_pointer->unkB8;
                }
                extra_player_info_pointer->vehicle_actor_pointer->unkB8 = -phi_f2_2;
            }
        }
    } else {
        if (extra_player_info_pointer->vehicle_actor_pointer->unkB8 > 0.0f) {
            phi_f2_3 = extra_player_info_pointer->vehicle_actor_pointer->unkB8;
        } else {
            phi_f2_3 = -extra_player_info_pointer->vehicle_actor_pointer->unkB8;
        }
        if (phi_f2_3 < 50.0f) {
            extra_player_info_pointer->vehicle_actor_pointer->unkB8 = -50.0f;
        } else {
            if (extra_player_info_pointer->vehicle_actor_pointer->unkB8 > 0.0f) {
                phi_f2_5 = extra_player_info_pointer->vehicle_actor_pointer->unkB8;
            } else {
                phi_f2_5 = -extra_player_info_pointer->vehicle_actor_pointer->unkB8;
            }
            extra_player_info_pointer->vehicle_actor_pointer->unkB8 = -phi_f2_5;
        }
    }
    playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x292);
    if (gCurrentPlayer->control_state != 9) {
        playAnimation(gCurrentPlayer, 0x83);
    }
}

void func_global_asm_806ED420(void) {
    if (extra_player_info_pointer->unkD4 == 0) {
        func_global_asm_806CA2AC();
        func_global_asm_8072DB68(3);
        switch (current_character_index[cc_player_index]) {
            case 3:
                playSoundAtActorPosition(gCurrentPlayer, 0xB9, 0xFF, 0x7F, 0x14);
                break;
            case 2:
                playSoundAtActorPosition(gCurrentPlayer, 0xD2, 0xFF, 0x7F, 0x14);
                break;
        }
        extra_player_info_pointer->unkD4 = D_global_asm_807530B0[D_global_asm_807FD584];
        gCurrentPlayer->unkB8 /= 2;
    }
}

void func_global_asm_806ED508(u16 actorBehaviourIndex) {
    u16 flagIndex;
    s16 sp24;

    switch (actorBehaviourIndex) {
        case ACTOR_RAMBI_CRATE:
            // Rambi First Time Text (FTT)
            flagIndex = PERMFLAG_CUTSCENE_RAMBI_FTCS;
            sp24 = 0x23;
            break;
        case 0x81: // TODO: ACTOR_ENGUARDE_CRATE
            // Enguarde First Time Text (FTT)
            flagIndex = PERMFLAG_CUTSCENE_ENGUARDE_FTCS;
            sp24 = 0x24;
            break;
    }
    if (!isFlagSet(flagIndex, FLAG_TYPE_PERMANENT)) {
        if (actorBehaviourIndex == 0x81) { // TODO: ACTOR_ENGUARDE_CRATE
            gCurrentPlayer->unkB8 = 0.0f;
        }
        playCutscene(NULL, sp24, 5);
        setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
    }
}

void func_global_asm_806ED5C0(Actor *arg0) {
    u16 flagIndex;
    u16 actorBehaviourIndex;
    s32 spawnerID;

    actorBehaviourIndex = arg0->unk58;
    spawnerID = func_global_asm_80688E68(arg0); // getSpawnerID(actor)

    switch (current_map) {
        case MAP_FACTORY:
            if (spawnerID == 0x11) {
                return;
            }
            break;
        case MAP_FUNGI:
            if (spawnerID == 0x17) {
                return;
            }
    }

    switch (actorBehaviourIndex) {
        case ACTOR_HUNKY_CHUNKY_BARREL:
            flagIndex = PERMFLAG_CUTSCENE_HUNKY_CHUNKY_FTCS; // Hunky Chunky First Time Text
            break;
        case ACTOR_MINI_MONKEY_BARREL:
            flagIndex = PERMFLAG_CUTSCENE_MINI_MONKEY_FTCS; // Mini Monkey First Time Text
            break;
        case ACTOR_STRONG_KONG_BARREL:
            flagIndex = PERMFLAG_CUTSCENE_STRONG_KONG_FTCS; // Strong Kong First Time Text
            break;
        case ACTOR_ORANGSTAND_SPRINT_BARREL:
            flagIndex = PERMFLAG_CUTSCENE_ORANGSTAND_SPRINT_FTCS; // Orangstand Sprint First Time Text
            break;
        default:
            return;
    }

    if (!isFlagSet(flagIndex, FLAG_TYPE_PERMANENT)) {
        playCutscene(NULL, 0x16, 5);
        setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_global_asm_806ED6B0.s")

void func_global_asm_806EDFF8(void) {
    func_global_asm_806C8E58(extra_player_info_pointer->unk1EE);
    func_global_asm_806CFF9C(gCurrentPlayer);
}

void func_global_asm_806EE02C(void) {
    func_global_asm_806CF398(gCurrentPlayer);
    gCurrentPlayer->control_state = 0x55;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE06C(void) {
    func_global_asm_806CF398(gCurrentPlayer);
    gCurrentPlayer->control_state = 0x56;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentPlayer, 0x87);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
}

void func_global_asm_806EE10C(void) {
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        func_global_asm_806CA2AC();
        if (func_global_asm_806C9974(cc_player_index, -1)) {
            if (gCurrentPlayer->unk6A & 4) {
                playAnimation(gCurrentPlayer, 0x29);
            } else {
                playAnimation(gCurrentPlayer, 0x27);
            }
            gCurrentPlayer->control_state = 0x36;
            gCurrentPlayer->control_state_progress = 0;
        }
        extra_player_info_pointer->unkD4 = D_global_asm_807530B0[D_global_asm_807FD584];
    }
}

void func_global_asm_806EE1C4(void) {
    if (extra_player_info_pointer->unk1AC != 0) {
        func_global_asm_8067A784(gCurrentActorPointer,
                      extra_player_info_pointer->unk1AC,
                      gCurrentPlayer->y_rotation,
                      gCurrentActorPointer->y_velocity,
                      gCurrentActorPointer->unkB8);
        extra_player_info_pointer->unk1AC = 0;
        extra_player_info_pointer->unk1B0 = 0;
    }
    func_global_asm_806CA2AC();
    playAnimation(gCurrentActorPointer, 0x1C);
    gCurrentPlayer->control_state = 0x20;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE26C(void) {
    func_global_asm_806CA2AC();
    playAnimation(gCurrentActorPointer, 0x1C);
    gCurrentPlayer->control_state = 0x21;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE2B8(void) {
    s32 sp24;
    s8 phi_a1;

    sp24 = TRUE;
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        phi_a1 = -1;
        func_global_asm_806CA2AC();
        if (character_change_array[cc_player_index].unk2A0 && character_change_array[cc_player_index].unk2A0->unk58 == ACTOR_KOSHA) {
            phi_a1 = -2;
        }
        if (func_global_asm_806C9974(cc_player_index, phi_a1)) {
            sp24 = FALSE;
            if (gCurrentPlayer->unk6A & 4) {
                playAnimation(gCurrentPlayer, 0x29);
            } else {
                playAnimation(gCurrentPlayer, 0x27);
            }
            gCurrentPlayer->control_state = 0x36;
            gCurrentPlayer->control_state_progress = 0;
        } else {
            playSoundAtActorPosition(gCurrentActorPointer, 0x16, 0xFF, 0x7F, 0);
            playAnimation(gCurrentActorPointer, 0x1E);
            gCurrentActorPointer->control_state = 0x20;
            gCurrentActorPointer->control_state_progress = 1;
        }
    }
    if ((extra_player_info_pointer->unkD4 == 0) && (cc_number_of_players < 2)) {
        extra_player_info_pointer->unkD4 = D_global_asm_807530B0[D_global_asm_807FD584];
    }
    if (sp24) {
        func_global_asm_8061F0B0(extra_player_info_pointer->unk104, 0x14, 0x14);
    }
}

void func_global_asm_806EE454(void) {
    s32 sp24;

    sp24 = TRUE;
    func_global_asm_806CA2AC();
    if (func_global_asm_806EB400(gCurrentPlayer) && func_global_asm_806C9974(cc_player_index, -1)) {
        sp24 = FALSE;
        if ((gCurrentPlayer->unk6A & 4) != 0) {
            playAnimation(gCurrentPlayer, 0x29);
        } else {
            playAnimation(gCurrentPlayer, 0x27);
        }
        gCurrentPlayer->control_state = 0x36;
        gCurrentPlayer->control_state_progress = 0;
    } else {
        playSoundAtActorPosition(gCurrentActorPointer, 0x16, 0xFF, 0x7F, 0);
        playAnimation(gCurrentActorPointer, 0x1E);
        gCurrentActorPointer->control_state = 0x20;
        gCurrentActorPointer->control_state_progress = 1;
    }
    if ((extra_player_info_pointer->unkD4 == 0) && (cc_number_of_players < 2)) {
        extra_player_info_pointer->unkD4 = D_global_asm_807530B0[D_global_asm_807FD584];
    }
    if (sp24) {
        func_global_asm_8061F0B0(extra_player_info_pointer->unk104, 0x14, 0x14);
    }
}

void func_global_asm_806EE5A4(void) {
    func_global_asm_806CA2AC();
    func_global_asm_80602B60(0x6B, 0);
    gCurrentActorPointer->unk168 = character_change_array[cc_player_index].unk2A8;
    playAnimation(gCurrentActorPointer, 0x1D);
    gCurrentPlayer->control_state = 0x6F;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE634(void) {
    setYAccelerationFrom80753578();
    func_global_asm_806CFF1C(gCurrentActorPointer);
}

void func_global_asm_806EE660(void) {
    func_global_asm_806CF398(gCurrentPlayer);
    playAnimation(gCurrentPlayer, 0x32);
    gCurrentPlayer->control_state = 0x52;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE6B0(void) {
    func_global_asm_806CF398(gCurrentPlayer);
    playAnimation(gCurrentPlayer, 0x86);
    gCurrentPlayer->control_state = 0x53;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE700(void) {
    func_global_asm_806CF398(gCurrentPlayer);
    func_global_asm_806CFF9C(gCurrentPlayer);
    gCurrentPlayer->control_state = 0x54;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806EE74C(void) {
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        if ((current_map != MAP_CAVES_BEETLE_RACE) && (current_map != MAP_AZTEC_BEETLE_RACE)) {
            func_global_asm_806EEAF8(0x40);
        } else {
            PlayerAdditionalActorData *PaaD = extra_player_info_pointer->vehicle_actor_pointer->PaaD;
            PaaD->unk45 = 1;
        }
    }
}

void func_global_asm_806EE7B8(void) {
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        func_global_asm_806EEAF8(D_global_asm_807FD6F2);
        setYAccelerationFrom80753578();
    }
}

void func_global_asm_806EE7F4(void) {
    if (D_global_asm_807FBB68 & 2) {
        func_global_asm_806F1048(gCurrentPlayer);
        func_global_asm_80602B60(0xC, 0);
    }
    if ((func_global_asm_806EB400(gCurrentPlayer)) && (((D_global_asm_807FBB68 & 2) == 0) || !func_global_asm_8061CB50())) {
        func_global_asm_806EEAF8(1);
        setYAccelerationFrom80753578();
    }
}

void func_global_asm_806EE878(void) {
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        if (!character_change_array[cc_player_index].unk2A0) {
            func_global_asm_80687474(gCurrentPlayer, 3.2f);
        }
        func_global_asm_806EEAF8(1);
        setYAccelerationFrom80753578();
        func_global_asm_80697184();
    }
}

void func_global_asm_806EE924(void) {
    if (func_global_asm_806EB400(gCurrentPlayer)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        func_global_asm_806EEAF8(1);
        setYAccelerationFrom80753578();
    }
}

void func_global_asm_806EE994(void) {
    if (func_global_asm_806EB400(gCurrentActorPointer)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        gCurrentActorPointer->noclip_byte = 1;
        gCurrentActorPointer->control_state = 0x34;
        gCurrentActorPointer->control_state_progress = 0;
        playActorAnimation(gCurrentActorPointer, 0);
        func_global_asm_806C9974(cc_player_index, -0x40);
        setYAccelerationFrom80753578();
        func_global_asm_80614D00(gCurrentActorPointer, 0, 0);
    }
}

void func_global_asm_806EEA5C(void) {
    s32 phi_v0;

    if (func_global_asm_806EB400(gCurrentPlayer)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        phi_v0 = 1;
        if (extra_player_info_pointer->unkDC && (extra_player_info_pointer->unkDC->unk58 == ACTOR_KOSHA)) {
            phi_v0 = 2;
        }
        func_global_asm_806EEAF8(phi_v0);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_global_asm_806EEAF8.s")

void func_global_asm_806EF830(void) {
    PlayerAdditionalActorData *temp_v0_4;

    switch (gCurrentPlayer->control_state) {
        case 0x36:
        case 0x39:
        case 0x3A:
        case 0x71:
        case 0x73:
        case 0x74:
            break;
        default:
            func_global_asm_806CA2AC();
            gCurrentPlayer->object_properties_bitfield &= ~0x8000;
            playAnimation(gCurrentPlayer, 0x27);
            gCurrentPlayer->control_state = 0x39;
            gCurrentPlayer->control_state_progress = 0;
            extra_player_info_pointer->unk11C = 0x19;
            func_global_asm_8061B610(extra_player_info_pointer->unk104);
            if ((current_map != MAP_CAVES_BEETLE_RACE) && (current_map != MAP_AZTEC_BEETLE_RACE)) {
                func_global_asm_806C9974(cc_player_index, -0x40);
                return;
            }
            // TODO: Which aaD type are they actually expecting here? VaaD, RaaD?
            temp_v0_4 = extra_player_info_pointer->vehicle_actor_pointer->PaaD;
            temp_v0_4->unk45 = 1;
            break;
    }
}

void func_global_asm_806EF944(void) {
    if ((func_global_asm_806EB400(gCurrentPlayer) != 0) && (gCurrentPlayer->control_state != 0x3B) && !func_global_asm_8061CB50()) {
        func_global_asm_806CA2AC();
        func_global_asm_806CF42C(gCurrentPlayer);
        gCurrentPlayer->noclip_byte = 1;
        playAnimation(gCurrentPlayer, 0x2A);
        gCurrentPlayer->control_state = 0x3B;
        gCurrentPlayer->control_state_progress = 0;
        func_global_asm_806C9974(cc_player_index, -0x40);
        playCutscene(gCurrentPlayer, 0xB, 0x85);
        gCurrentPlayer->unkB8 = 0.0f;
    }
}

void func_global_asm_806EFA08(void) {
    extra_player_info_pointer->unk1FC = 1;
}

void func_global_asm_806EFA1C(void) {
    gCurrentActorPointer->control_state = 0x6A; // learning_gun
    gCurrentActorPointer->control_state_progress = 0;
}

typedef struct {
    u16 unk0[5];
} Struct8075D380;

const Struct8075D380 D_global_asm_8075D380 = {
    {
        0x000A,
        0x000B,
        0x000C,
        0x000D,
        0x000E,
    }
};

void func_global_asm_806EFA3C(void) {
    Struct8075D380 sp24;
    s32 temp; // TODO: wtf
    f32 scale;

    sp24 = D_global_asm_8075D380;
    scale = gCurrentPlayer->animation_state->scale_x;
    spawnActor(ACTOR_POTION, 0xB9);
    if (gCurrentPlayer->unk58 == ACTOR_DK) {
        scale *= 1.25;
    }
    moveAndScaleActorToAnother(gLastSpawnedActor, gCurrentPlayer, scale);
    playActorAnimation(gLastSpawnedActor, sp24.unk0[current_character_index[extra_player_info_pointer->unk1A4]]);
    gLastSpawnedActor->object_properties_bitfield |= 0x40000000;
    playAnimation(gCurrentPlayer, 0x88);
    gCurrentActorPointer->control_state = 0x79;
    gCurrentActorPointer->control_state_progress = 0;
}

void func_global_asm_806EFB4C(void) {
    func_global_asm_80602B60(0x6B, 0);
    func_global_asm_806CA2AC();
    func_global_asm_806C9F74(gCurrentPlayer);
    func_global_asm_806CF42C(gCurrentPlayer);
    playAnimation(gCurrentPlayer, 0x5B);
    gCurrentPlayer->control_state = 0x70;
    gCurrentPlayer->control_state_progress = 0;
    if (gCurrentPlayer->unkFC) {
        gCurrentPlayer->y_rotation = func_global_asm_80672A70(gCurrentPlayer->unkF4, gCurrentPlayer->unkF6);
    } else {
        gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
            character_change_array[cc_player_index].look_at_eye_x,
            character_change_array[cc_player_index].look_at_eye_z,
            gCurrentPlayer->x_position,
            gCurrentPlayer->z_position
        );
    }
    func_global_asm_80627948(gCurrentPlayer, 0x15, 0x1F, 5);
}

void func_global_asm_806EFC38(void) {
    func_global_asm_806CA2AC();
    func_global_asm_806CF42C(gCurrentPlayer);
    func_global_asm_806C9F74(gCurrentPlayer);
    if (gCurrentPlayer->control_state != 0x6D) {
        playAnimation(gCurrentPlayer, 0x5B);
        gCurrentPlayer->control_state = 0x71;
        gCurrentPlayer->control_state_progress = 0;
    }
    gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
        character_change_array[cc_player_index].look_at_eye_x,
        character_change_array[cc_player_index].look_at_eye_z,
        gCurrentPlayer->x_position,
        gCurrentPlayer->z_position
    );
    if (current_map == MAP_JAPES_ARMY_DILLO) {
        playCutscene(gCurrentPlayer, 2, 1);
        gCurrentPlayer->control_state_progress = 0xFF;
        extra_player_info_pointer->unk23C = 0xFFFF;
    } else {
        playCutscene(gCurrentPlayer, 5, 5);
        extra_player_info_pointer->unk23C = 0x64;
    }
}

void func_global_asm_806EFD50(void) {
    func_global_asm_806CA2AC();
    func_global_asm_806CF42C(gCurrentPlayer);
    playAnimation(gCurrentPlayer, 0x5B);
    gCurrentPlayer->control_state = 0x72;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
        character_change_array[cc_player_index].look_at_eye_x,
        character_change_array[cc_player_index].look_at_eye_z,
        gCurrentPlayer->x_position,
        gCurrentPlayer->z_position
    );
    playCutscene(gCurrentPlayer, 0x15, 5);
}

void func_global_asm_806EFDFC(void) {
    Actor *vehicle;

    func_global_asm_806C8E58(extra_player_info_pointer->unk1EE);
    func_global_asm_806CF42C(gCurrentPlayer);
    func_global_asm_806CA2AC();
    gCurrentPlayer->noclip_byte = 1;
    if (gCurrentPlayer->control_state != 0x7D) {
        if (gCurrentPlayer->unk6A & 4) {
            playAnimation(gCurrentPlayer, 0x34);
        } else if (!(gCurrentPlayer->unk6A & 2)) {
            playAnimation(gCurrentPlayer, 0x5D);
        }
    }
    gCurrentPlayer->control_state = 0x73;
    gCurrentPlayer->control_state_progress = 0;
    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (!vehicle || vehicle->unk58 != ACTOR_MINECART_BONUS) {
        gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
            character_change_array[cc_player_index].look_at_eye_x,
            character_change_array[cc_player_index].look_at_eye_z,
            gCurrentPlayer->x_position,
            gCurrentPlayer->z_position
        );
    }
    gCurrentPlayer->y_velocity = 0.0f;
    extra_player_info_pointer->unk23C = 0x5A;
    setYAccelerationFrom80753578();
}

void func_global_asm_806EFF34(void) {
    Actor *vehicle;

    func_global_asm_806C8E58(extra_player_info_pointer->unk1EE);
    func_global_asm_806CF42C(gCurrentPlayer);
    func_global_asm_806CA2AC();
    gCurrentPlayer->noclip_byte = 1;
    if (gCurrentPlayer->control_state != 0x7D) {
        if (gCurrentPlayer->unk6A & 4) {
            playAnimation(gCurrentPlayer, 0x34);
        } else if (!(gCurrentPlayer->unk6A & 2)) {
            playAnimation(gCurrentPlayer, 0x5C);
        }
    }
    gCurrentPlayer->control_state = 0x74;
    gCurrentPlayer->control_state_progress = 0;
    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (!vehicle || vehicle->unk58 != ACTOR_MINECART_BONUS) {
        gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
            character_change_array[cc_player_index].look_at_eye_x,
            character_change_array[cc_player_index].look_at_eye_z,
            gCurrentPlayer->x_position,
            gCurrentPlayer->z_position
        );
    }
    gCurrentPlayer->y_velocity = 0.0f;
    extra_player_info_pointer->unk23C = 0x5A;
    setYAccelerationFrom80753578();
}

void func_global_asm_806F006C(void) {

}

void func_global_asm_806F0074(void) {

}

void func_global_asm_806F007C(void) {
    gCurrentActorPointer->control_state = 0x84;
    gCurrentActorPointer->control_state_progress = 0;
    playActorAnimation(gCurrentActorPointer, 0);
}

void func_global_asm_806F00BC(void) {
    func_global_asm_806CA2AC();
    extra_player_info_pointer->unk1F0 &= ~0x20;
    gCurrentPlayer->unk132 = 2;
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    gCurrentPlayer->control_state = 0x7A;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806F014C(void) {
    extra_player_info_pointer->unk1F4 |= 8;
    func_global_asm_806CFF9C(gCurrentPlayer);
}

void func_global_asm_806F0184(void) {
    func_global_asm_806CA2AC();
    extra_player_info_pointer->unk1F0 &= ~0x20;
    gCurrentPlayer->control_state = 0x7B;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806F01D8(void) {
    func_global_asm_806CA2AC();
    func_global_asm_806F00BC();
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
}

void func_global_asm_806F0238(void) {
    playAnimation(gCurrentPlayer, 9);
    gCurrentPlayer->control_state = 0xC;
    gCurrentPlayer->control_state_progress = 0;
}

void func_global_asm_806F027C(void) {
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    setYAccelerationFrom80753578();
    if (gCurrentPlayer->control_state != 0x7C) {
        func_global_asm_806CA2AC();
        gCurrentPlayer->control_state = 0x7C;
        gCurrentPlayer->control_state_progress = 0;
        playActorAnimation(gCurrentPlayer, 0x13);
        spawnActor(ACTOR_TRAP_BUBBLE, 0xC5);
        gLastSpawnedActor->unk11C = gCurrentPlayer;
        func_global_asm_806C8D20(gCurrentPlayer);
    }
}

void func_global_asm_806F0344(void) {
    setYAccelerationFrom80753578();
    gCurrentPlayer->control_state = 0x7D;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->object_properties_bitfield &= ~4;
    spawnActor(ACTOR_MINIGAME_BOTHER_KLAPTRAP, 0x21);
    playActorAnimation(gLastSpawnedActor, 0x232);
    gLastSpawnedActor->unk11C = gCurrentPlayer;
}

// Stupidly close
// https://decomp.me/scratch/EphMR
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_global_asm_806F03C4.s")

/*
void func_global_asm_806F03C4(void) {
    s32 sp1C;

    switch (gCurrentPlayer->unk58) {
        case ACTOR_DK:
            sp1C = 7;
            break;
        case ACTOR_DIDDY:
            sp1C = 0;
            break;
        case ACTOR_LANKY:
            extra_player_info_pointer->unk1F0 |= 0x100;
            sp1C = 4;
            break;
        case ACTOR_TINY:
            if (character_change_array[cc_player_index].unk2C0 == 1) {
                sp1C = 8;
            } else {
                sp1C = 0x1F;
            }
            break;
        case ACTOR_CHUNKY:
            sp1C = 9;
            break;
        default:
            break;
    }
    gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
        character_change_array[cc_player_index].look_at_eye_x, 
        character_change_array[cc_player_index].look_at_eye_z,
        gCurrentPlayer->x_position,
        gCurrentPlayer->z_position
    );
    if (D_global_asm_807FBB68 & 2) {
        extra_player_info_pointer->unk1F0 &= ~0x100;
        playActorAnimation(gCurrentPlayer, 0x165);
    } else {
        if (gCurrentPlayer->control_state != 0x56) {
            playCutscene(gCurrentPlayer, sp1C, 5);
        }
        playAnimation(gCurrentPlayer, 0x5A);
    }
    gCurrentPlayer->control_state = 0x67;
    gCurrentPlayer->control_state_progress = 0;
}
*/

void func_global_asm_806F0624(void) {
    extra_player_info_pointer->unk1F4 |= 0x10;
    func_global_asm_806E9964(extra_player_info_pointer);
    gCurrentPlayer->control_state = 0x83;
    gCurrentPlayer->control_state_progress = 0;
    gCurrentPlayer->object_properties_bitfield |= 0x40000004;
    gCurrentPlayer->object_properties_bitfield &= ~1;
}

void func_global_asm_806F06A4(void) {
    gCurrentPlayer->control_state = 0x87;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
}

void func_global_asm_806F0700(void) {
    f32 temp_f0;

    gCurrentPlayer->control_state = 0x88;
    gCurrentPlayer->control_state_progress = 0;
    playActorAnimation(gCurrentPlayer, 0);
    temp_f0 = 0.01;
    gCurrentPlayer->x_position = extra_player_info_pointer->unk22C;
    gCurrentPlayer->y_position = extra_player_info_pointer->unk230;
    gCurrentPlayer->z_position = extra_player_info_pointer->unk234;
    gCurrentPlayer->x_rotation = -0x3E6;
    gCurrentPlayer->animation_state->scale_x = temp_f0;
    gCurrentPlayer->animation_state->scale_y = temp_f0;
    gCurrentPlayer->animation_state->scale_z = temp_f0;
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
}

void func_global_asm_806F07CC(void) {
    playSoundAtActorPosition(gCurrentPlayer, 0xF3, 0xFF, 0x7F, 0x19);
    gCurrentPlayer->control_state = 0x19;
    gCurrentPlayer->control_state_progress = 0;
    extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584] * 2.6;
    extra_player_info_pointer->unk50 = 0xC;
    playAnimation(gCurrentPlayer, 0x10);
}

void func_global_asm_806F0878(void) {
    if (gCurrentPlayer->unk78 == 0xC) {
        playSoundAtActorPosition(gCurrentPlayer, 0x76, 0x64, 0x7F, 0);
    }
    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
    func_global_asm_806CF398(gCurrentPlayer);
    gCurrentPlayer->control_state = 0x15;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentPlayer, 6);
    gCurrentPlayer->unk6A |= 0x20;
    func_global_asm_80614D90(gCurrentPlayer);
}

void func_global_asm_806F0930(void) {
    if (gCurrentPlayer->unk78 == 0xC) {
        playSoundAtActorPosition(gCurrentPlayer, 0x76, 0xFF, 0x7F, 0);
    }
    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
    func_global_asm_806CF398(gCurrentPlayer);
    gCurrentPlayer->control_state = 0x16;
    gCurrentPlayer->control_state_progress = 0;
    playAnimation(gCurrentPlayer, 7);
    gCurrentPlayer->unk6A |= 0x20;
    func_global_asm_80614D90(gCurrentPlayer);
}
