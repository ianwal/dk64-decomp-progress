#include <ultra64.h>
#include "functions.h"


u8 func_806C9974(u8, s32);
void func_80614D48(Actor*, f32, f32);
extern s32 D_807FD6F0[];
void func_806CD424(s16, f32, f32);
extern void (*action_initiation_function_list[])(void);

void func_80605314(Actor*, u8);
void func_8062217C(Actor*, s32);
void func_80627878(Actor*);
void func_806F0D68(Actor*);
void func_80613AF8(Actor*, s32, f32, f32);
void func_806EEAF8(s16);

extern s16 D_807FD584;
extern s16 D_807539DC[];
extern s16 D_807539EC[];
extern f32 D_807531C4[];
extern f32 D_80753250[];
extern f32 D_807531FC[];
extern f64 D_8075D408;
extern u32 D_807FBB68;
extern s16 D_8075380C[];
extern s16 D_807530B0[];
extern s16 D_807530B0[];
extern s16 D_807FD6F2;
extern f32 D_8075D5D8;
extern f32 D_807535CC[];
extern f64 D_8075D5E0;
extern s32 D_80767CC0;
extern f32 D_80753924[];
extern f32 D_80753940[];
extern f32 D_80753908[];
extern s16 D_807537FC[];
extern s16 D_8075384C[];
extern s16 D_8075383C[];
extern f32 D_807534E4[];
extern f32 D_80753500[];
extern s16 D_8075351C[];
extern f32 D_80753D70[];
extern f32 D_80753D8C[];

u8 func_806EB0C0(s16 arg0, Actor *actor, u8 playerIndex) {
    if (character_change_array[playerIndex].action_initiated < arg0) {
        character_change_array[playerIndex].action_initiated = arg0;
        character_change_array[playerIndex].unk2A0 = actor;
        character_change_array[playerIndex].unk2A8 = D_807FD6F0[0];
        character_change_array[playerIndex].unk2AC = D_807FD6F0[1];
        character_change_array[playerIndex].unk2B0 = D_807FD6F0[2];
        if (actor) {
            character_change_array[playerIndex].unk2A4 = actor->unk54;
        }
        return TRUE;
    }
    return FALSE;
}

void func_806EB178(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_807FD6F0[0] = arg1;
    D_807FD6F0[1] = arg2;
    D_807FD6F0[2] = arg3;
}

void func_806EB194(void) {
    if (character_change_array[cc_player_index].action_initiated >= 0) {
        if (character_change_array[cc_player_index].unk2A0
            && (!func_8067AF44(character_change_array[cc_player_index].unk2A0) || character_change_array[cc_player_index].unk2A0->unk54 != character_change_array[cc_player_index].unk2A4)) {
            character_change_array[cc_player_index].unk2A0 = NULL;
        }
        action_initiation_function_list[character_change_array[cc_player_index].action_initiated]();
    }
    character_change_array[cc_player_index].action_initiated = -1;
}

void func_806EB2B8(void) {
    func_806CFECC();
    current_actor_pointer->control_state = 0x22;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->y_velocity = 100.0f;
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk2C = 100.0f;
    if (extra_player_info_pointer->unk3C == 0) {
        func_806CD424(extra_player_info_pointer->unkA, extra_player_info_pointer->unk4, extra_player_info_pointer->unk38);
    }
    extra_player_info_pointer->unk2C = 10.0f;
    func_80614EBC(current_actor_pointer, 0x17B);
}

void func_806EB364(void) {
    if (current_character_index[cc_player_index] == 6) {
        func_806CFF9C(D_807FBB48);
        return;
    }
    current_actor_pointer->control_state = 0x3D;
    current_actor_pointer->control_state_progress = 0;
    if (extra_player_info_pointer->unk4E == 0x22) {
        func_80614EBC(current_actor_pointer, 0x131);
        return;
    }
    func_80614E78(current_actor_pointer, 0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806EB400.s")

/*
// TODO: Closer now, bottom might not be a switch case, aaa
int func_806EB400(Actor *arg0) {
    int phi_v1;
    u8 phi_a1;
    PlayerAdditionalActorData *PaaD = arg0->PaaD;

    phi_v1 = PaaD->unkD4 == 0
        || character_change_array[cc_player_index].action_initiated == 0x3F;

    if ((current_character_index[cc_player_index] == 7) || PaaD->unk1F0 & 0x8000) {
        return 0;
    }
    switch (arg0->control_state) {
        case 0x34:
        case 0x36:
            phi_a1 = phi_v1 & 1;
            break;
        default:
            phi_a1 = 0;
    }
    return phi_a1;
}
*/

void func_806EB4B4(void) {
    current_actor_pointer->control_state = 0x23;
    current_actor_pointer->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0x3BC);
}

void func_806EB4F8(void) {
    current_actor_pointer->control_state = 0x5F;
    current_actor_pointer->control_state_progress = 0;
    extra_player_info_pointer->unk1A3 = 0;
    func_80614E78(current_actor_pointer, 0x4A);
}

void func_806EB544(void) {
    s32 phi_a3;

    phi_a3 = 2;
    if (func_806F8AD4(3, extra_player_info_pointer->unk1A4)) {
        phi_a3 = 3;
    }
    func_806F8BC4(phi_a3, 0, 0);
    current_actor_pointer->control_state = 0x60;
    current_actor_pointer->control_state_progress = 0;
    extra_player_info_pointer->unk1A3 = 0;
    func_80614E78(current_actor_pointer, 0x4B);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806EB5C8.s")

void func_806EB6D8(void) {
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk38 = 170.0f;
    current_actor_pointer->control_state = 0x3F;
    current_actor_pointer->control_state_progress = 0;
    extra_player_info_pointer->unk4E = 0;
    func_80614EBC(current_actor_pointer, 0x14F);
}

void func_806EB744(void) {
    s32 temp_t6; // TODO: Is this needed still? Padding
    s16 phi_v1;
    PlayerAdditionalActorData *PaaD;

    PaaD = extra_player_info_pointer->unk104->PaaD;
    phi_v1 = PaaD->unkB8;
    if (PaaD->unkEF != 0) {
        PaaD->unkF0_u8[0] = PaaD->unkEF;
        phi_v1 = 0x80;
    }
    func_80627878(extra_player_info_pointer->unk104);
    func_8062217C(extra_player_info_pointer->unk104, 0);
    PaaD->unkF0_u8[3] = character_change_array[cc_player_index].unk2A8;
    if (PaaD->unkF0_u8[3] == 3) {
        func_80605314(D_807FBB48, 0);
        playSound(0x26, 0x7FFF, 63.0f, 1.0f, 0, 0);
        if (character_change_array[cc_player_index].unk2AC != 0) {
            func_806F0D68(D_807FBB48);
        }
    }
    PaaD->unkBC = 0x80;
    extra_player_info_pointer->unk104->distance_from_floor = phi_v1;
    PaaD->unkB8 = phi_v1;
    PaaD->unkB2 = D_807FBB48->y_rotation + 0x800;
    D_807FBB48->unkB8 = 0.0f;
    D_807FBB48->unk6A |= 0x2000;
}

void func_806EB8CC(void) {
    func_806EB744();
    D_807FBB48->control_state = 2;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->control_state_progress = 0xA;
    if (extra_player_info_pointer->unk8C != 0) {
        func_80614EBC(D_807FBB48, 0x23);
    } else {
        func_80614EBC(D_807FBB48, 0x13);
    }
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
}

void func_806EB964(void) {
    playSound(0x1B9, 0x7FFF, 63.0f, 1.0f, 0xA, 0);
    func_806EB744();
    D_807FBB48->control_state = 4;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->control_state_progress = 0xA;
    func_80614EBC(D_807FBB48, 0x13);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
    func_806F8BC4(6, 1, 0);
}

void func_806EBA04(void) {
    func_806EB744();
    D_807FBB48->control_state = 3;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->control_state_progress = 0xA;
    func_80614EBC(D_807FBB48, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
}

void func_806EBA74(void) {
    func_806EB744();
    D_807FBB48->control_state = 5;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->control_state_progress = 0xA;
    func_80614EBC(D_807FBB48, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
    func_806F8BC4(6, 1, 0);
}

void func_806EBAF4(void) {
    current_actor_pointer->control_state = 0x4F;
    current_actor_pointer->control_state_progress = 2;
    func_80614E78(current_actor_pointer, 0x34);
    extra_player_info_pointer->unk50 = 0;
}

void func_806EBB44(void) {
    global_properties_bitfield |= 0x4000;
    D_807FBB48->control_state = 1;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    func_80614D48(D_807FBB48, 0.0f, 0.0f);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
}

void func_806EBBD0(void) {
    D_807FBB48->control_state = 6;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    func_80614D48(D_807FBB48, 0.0f, 0.0f);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    D_807FBB48->object_properties_bitfield &= -5;
}

void func_806EBC60(void) {
    D_807FBB48->control_state = 0x6B;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    func_80614D48(D_807FBB48, 0.0f, 0.0f);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    D_807FBB48->object_properties_bitfield &= -5;
}

void func_806EBCF0(void) {
    D_807FBB48->control_state = 7;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(D_807FBB48, 0x7A);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
    D_807FBB48->object_properties_bitfield &= ~0x40000;
    D_807FBB48->unkB8 = 0.0f;
}

void func_806EBDAC(void) {
    extra_player_info_pointer->unk1F0 |= 8;
}

void func_806EBDC4(void) {
    D_807FBB48->control_state = 0x69;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    func_80614D48(D_807FBB48, 0, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    D_807FBB48->object_properties_bitfield &= ~0x1000000;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806EBE8C.s")

/*
// TODO: Incorrect order of operation for loading function params for the call after the if statement
void func_80026004(Actor178*, s32, f32);

void func_806EBE8C(void) {
    Actor *vehicle;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle->control_state < 3) {
        func_80026004(vehicle->unk178, 0x1E, 1.0f);
    }
}
*/

void func_806EBED0(void) {
    extra_player_info_pointer->vehicle_actor_pointer->y_velocity += 200.0f;
    if (extra_player_info_pointer->vehicle_actor_pointer->y_velocity > 200.0f) {
        extra_player_info_pointer->vehicle_actor_pointer->y_velocity = 200.0f;
    }
    func_8072DB68(3);
}

void func_806EBF34(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    vehicle->y_velocity += 300.0f;
    func_8072DB68(3);
}

void func_806EBF74(void) {
    func_806F1250(D_807FBB48);
    extra_player_info_pointer->unk1FE = character_change_array[cc_player_index].unk2A8;
}

void func_806EBFD0(void) {
    func_80614EBC(D_807FBB48, 0x1A);
    D_807FBB48->control_state = 0x78;
    D_807FBB48->control_state_progress = 0;
}

void func_806EC014(void) {
    func_806CF42C(current_actor_pointer);
    func_806CFF9C(current_actor_pointer);
}

void func_806EC044(void) {
    f32 sp24;

    sp24 = 1.0f;
    func_806F0C18(current_actor_pointer);
    D_807FBB48->control_state = 0x6C;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0x3B);
    if (current_character_index[0] == 0) {
        sp24 = 0.5f;
    }
    func_80614D00(D_807FBB48, sp24, 0.0f);
    func_80672C30(D_807FBB48);
    // Optimization: Weird that they didn't reuse the result of the func_80659470 call
    D_807FBB48->x_position = D_807F6000[func_80659470(D_807FBB48->unk10C)].x_position;
    D_807FBB48->y_position = D_807F6000[func_80659470(D_807FBB48->unk10C)].y_position + 5.0f;
    D_807FBB48->z_position = D_807F6000[func_80659470(D_807FBB48->unk10C)].z_position;
    D_807FBB48->x_rotation = 0;
    D_807FBB48->z_rotation = 0;
    playCutscene(D_807FBB48, 0, 1);
    func_806F8BC4(0, 1, 0);
}

void func_806EC1A8(void) {
    PlayerAdditionalActorData *temp_v0; // TODO: Probably not a PaaD
    s16 phi_v0;

    temp_v0 = extra_player_info_pointer->unk104->additional_actor_data;
    temp_v0->unkAC |= 4;
    D_807FBB48->control_state = 0x6D;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    D_807FBB48->object_properties_bitfield &= -2;
    if (current_map == MAP_GALLEON_SEAL_RACE) {
        D_807FBB48->noclip_byte = 1;
    }
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
    func_80613C48(D_807FBB48, D_807FBB48->unk58 == 2 ? 0x53 : 0x1C7, 0, 0);
}

void func_806EC2CC(void) {
    Actor *vehicle;

    D_807FBB48->control_state = 0x75;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
    D_807FBB48->object_properties_bitfield &= -2;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    func_8067B238(D_807FBB48, vehicle, vehicle->animation_state->scale_x);
    D_807FBB48->noclip_byte = 1;
    func_80613C48(D_807FBB48, 0x22A, 0, 0);
}

void func_806EC3BC(void) {
    extra_player_info_pointer->unk12 = D_807539EC[D_807FD584];
    extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
    extra_player_info_pointer->unk10 = D_807539DC[D_807FD584];
    current_actor_pointer->control_state = 0x4F;
    current_actor_pointer->control_state_progress = 1;
    if (current_actor_pointer->y_velocity > 0.0f) {
        current_actor_pointer->y_velocity = 0.0f;
    }
    func_80614E78(current_actor_pointer, 0x36);
    func_80613AF8(current_actor_pointer, 0x31, 0, 8.0f);
    func_80614D00(current_actor_pointer, 0.5f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806EC4AC.s")

extern s16 D_807538D8[];
extern s16 D_807538E8[];
extern s16 D_807538F8[];
extern s16 D_807539FC[];
extern f32 D_80753A5C[];
extern f32 D_80753988[];
extern s16 D_8075388C[];

/*
// TODO: Doable, progress made, stack is still too big and there's a bunch of issues in the bottom half of the function
void func_806EC4AC(void) {
    f32 temp_f12;
    f32 var_f14;
    f32 var_f18;
    f32 var_f20;
    f32 var_f2;

    func_806CF398(D_807FBB48);
    var_f20 = ABS(D_80753A5C[D_807FD584]);
    var_f2 = D_807FBB48->unkA0 - D_807FBB48->unkAC;
    if (D_807538D8[D_807FD584] < var_f2) {
        var_f2 = D_807538D8[D_807FD584];
    }
    temp_f12 = ((((D_807538F8[D_807FD584]) - D_807538E8[D_807FD584]) * (var_f2 / D_807538D8[D_807FD584])) + D_807538E8[D_807FD584]) - ((D_807FBB48->unkAC - D_8075388C[D_807FD584]) - D_807FBB48->y_position) * 40.0f;
    if (temp_f12 > 0.0f) {
        var_f14 = D_807FBB48->y_velocity * (0.5 + ((var_f2 * 40.0f) / (2.0f * (D_807538D8[D_807FD584] * 40.0f))));
        var_f18 = (var_f14 * var_f14) / (2.0f * temp_f12);
        if (var_f18 < var_f20) {
            var_f18 = var_f20;
        }
    } else {
        var_f14 = 0.0f;
        var_f18 = var_f20;
    }
    D_807FBB48->y_velocity = var_f14;
    extra_player_info_pointer->unk1C = var_f18;
    extra_player_info_pointer->unk10 = 0;
    extra_player_info_pointer->unk30 = D_80753250[D_807FD584];
    if (current_actor_pointer->unkB8 < D_80753988[D_807FD584]) {
        current_actor_pointer->unkB8 = current_actor_pointer->unkB8;
    } else {
        current_actor_pointer->unkB8 = D_80753988[D_807FD584];
    }
    D_807FBB48->control_state = 0x4E;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(current_actor_pointer, 0x35);
    extra_player_info_pointer->unk48 = D_807539FC[D_807FD584];
}
*/

void func_806EC708(void) {
    D_807FBB48->control_state = 0x51;
    D_807FBB48->control_state_progress = 0;
    extra_player_info_pointer->unk54 = D_80753908[D_807FD584];
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = D_807531FC[D_807FD584];
    extra_player_info_pointer->unk2C = D_80753924[D_807FD584];
    extra_player_info_pointer->unk30 = D_80753940[D_807FD584];
    func_80614E78(D_807FBB48, 0x3E);
    func_80614D00(current_actor_pointer, 1.0f, 0);
    extra_player_info_pointer->unk58 = D_80767CC0 - 0x1E;
}

void func_806EC800(void) {
    D_807FBB48->control_state = 0x50;
    D_807FBB48->control_state_progress = 0;
    current_actor_pointer->y_velocity = -10.0f;
    extra_player_info_pointer->unk50 = 0;
    if (current_actor_pointer->unkB8 < D_807531C4[D_807FD584]) {
        current_actor_pointer->unkB8 = current_actor_pointer->unkB8;
    } else {
        current_actor_pointer->unkB8 = D_807531C4[D_807FD584];
    }
    extra_player_info_pointer->unk38 = D_807531FC[D_807FD584];
    func_80614E78(D_807FBB48, 0x3C);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806EC8C4.s")

void func_806EC994(void) {
    func_80614E78(D_807FBB48, 8);
    func_80614D00(D_807FBB48, 1.0f, 0);
    func_80613AF8(D_807FBB48, 0x2E, 0, 6.0f);
    D_807FBB48->control_state = 0x46;
    D_807FBB48->control_state_progress = 0;
    extra_player_info_pointer->unk38 = D_807534E4[D_807FD584];
    extra_player_info_pointer->unk2C = D_80753500[D_807FD584];
    extra_player_info_pointer->unk48 = D_8075351C[D_807FD584];
    extra_player_info_pointer->unk4C = -1;
}

void func_806ECA74(void) {
    current_actor_pointer->control_state = 0x24;
    current_actor_pointer->control_state_progress = 0;
    func_80614EBC(current_actor_pointer, 0x1B2);
    extra_player_info_pointer->unkC8 = 0x32;
}

void func_806ECAC4(void) {
    f32 phi_f0;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f0 = D_80753D70[D_807FD584];
    } else {
        phi_f0 = D_80753D8C[D_807FD584];
    }
    D_807FBB48->control_state = 0x5B;
    D_807FBB48->control_state_progress = 0;
    extra_player_info_pointer->unk10C = phi_f0;
    D_807FBB48->y_position = extra_player_info_pointer->unkF0_f32 - extra_player_info_pointer->unk10C;
    D_807FBB48->unkEE = D_807FBB48->unkF4 + 0x14;
    D_807FBB48->y_velocity = 0.0f;
    func_80614E78(D_807FBB48, 0x75);
    func_80614D90(D_807FBB48);
}

void func_806ECBD4(void) {
    D_807FBB48->unk6A |= 0x40;
    D_807FBB48->unk64 &= -0x2001;
    D_807FBB48->control_state = 0x57;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(D_807FBB48, 0x69);
    func_80614D90(D_807FBB48);
}

void func_806ECC48(void) {
    void *sp1C = extra_player_info_pointer->unk104->additional_actor_data;
    D_807FBB48->unk6A |= 0x40;
    D_807FBB48->unk64 &= -0x2001;
    D_807FBB48->control_state = 0x59;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(D_807FBB48, 0x70);
    func_80614D90(D_807FBB48);
    func_8061F164(sp1C, 0x14);
}

void func_806ECCDC(void) {
    void *temp_a2;

    temp_a2 = extra_player_info_pointer->unk104->additional_actor_data;
    current_actor_pointer->control_state = 0x17;
    current_actor_pointer->control_state_progress = 0;
    if ((D_807FBB68 & 2) != 0) {
        extra_player_info_pointer->unk54 = D_807535CC[D_807FD584] * D_8075D408;
    } else {
        extra_player_info_pointer->unk54 = D_807535CC[D_807FD584];
    }
    D_807FBB48->unkB8 = extra_player_info_pointer->unk124;
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk3C = 0xA;
    func_80614E78(current_actor_pointer, 0x10);
    func_8061F164(temp_a2, 0x14);
}

void func_806ECDD4(void) {
    if (func_806EB400(D_807FBB48)) {
        func_806EEAF8(D_807FBB68 & 2 ? 0 : 1);
    }
}

void func_806ECE2C(void) {
    if ((cc_number_of_players >= 2) || (D_807FBB48->unk58 != 6) || (character_change_array[cc_player_index].unk2C0 == 1)) {
        D_807FBB48->y_velocity = 260.0f;
        func_806CFE7C();
        extra_player_info_pointer->unk50 = 0;
        extra_player_info_pointer->unk48 = 0x64;
        func_80614E78(D_807FBB48, 0x1F);
        func_80614D00(D_807FBB48, 1.0f, 0);
        D_807FBB48->control_state = 0x30;
        D_807FBB48->control_state_progress = 0;
        func_806CF42C(D_807FBB48);
    }
}

void func_806ECF1C(void) {
    D_807FBB48->y_velocity = 260.0f;
    func_806CFE7C();
    extra_player_info_pointer->unk50 = 0;
    func_80614E78(D_807FBB48, 0x20);
    func_80614D00(D_807FBB48, 1.0f, 0);
    D_807FBB48->control_state = 0x30;
    D_807FBB48->control_state_progress = 0;
    func_806CF42C(D_807FBB48);
}

void func_806ECF9C(void) {
    f32 temp_f0;

    extra_player_info_pointer->unk50 = D_807537FC[D_807FD584];
    extra_player_info_pointer->unk68 += D_8075383C[D_807FD584];
    temp_f0 = D_8075384C[D_807FD584];
    if (temp_f0 < extra_player_info_pointer->unk68) {
        extra_player_info_pointer->unk68 = temp_f0;
    }
    D_807FBB48->y_velocity = 0.0f;
    extra_player_info_pointer->unk50 = 0;
}

void func_806ED050(void) {
    if ((current_actor_pointer->control_state != 2) && (current_character_index[cc_player_index] == 6)) {
        current_actor_pointer->control_state = 0x29;
        current_actor_pointer->control_state_progress = 0;
        func_80614E78(current_actor_pointer, 0x3F);
        extra_player_info_pointer->unk64 = 0;
        extra_player_info_pointer->unk68 = D_8075380C[D_807FD584];
    }
}

void func_806ED0FC(void) {
    Actor *temp_v0;

    func_806CA2AC();
    func_806CF398(D_807FBB48);
    extra_player_info_pointer->unk8C = 0;
    func_806F0C18(current_actor_pointer);
    func_80605314(current_actor_pointer, 0);
    func_80605314(current_actor_pointer, 1);
    func_80614E78(D_807FBB48, 0x21);
    temp_v0 = character_change_array[cc_player_index].unk2A0;
    if (temp_v0) {
        extra_player_info_pointer->unkBC = temp_v0->unk58;
        extra_player_info_pointer->unkBE = func_80688E68(character_change_array[cc_player_index].unk2A0);
    } else {
        extra_player_info_pointer->unkBC = 0;
        extra_player_info_pointer->unkBE = -1;
    }
    if (current_actor_pointer->unk6A & 4) {
        D_807FBB48->control_state = 0x43;
        D_807FBB48->control_state_progress = 0;
    } else {
        D_807FBB48->control_state = 0x42;
        D_807FBB48->control_state_progress = 0;
    }
}

// TODO: Could use some cleanup, can we use ABS? Can we use a temp var for vehicle?
void func_806ED244(void) {
    f32 phi_f2;
    f32 phi_f2_2;
    f32 phi_f2_3;
    f32 phi_f8;
    f32 phi_f2_4;
    f32 phi_f2_5;

    if (extra_player_info_pointer->vehicle_actor_pointer->unkB8 >= 0.0f) {
        func_8072DB68(3);
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
    func_80614EBC(extra_player_info_pointer->vehicle_actor_pointer, 0x292);
    if (D_807FBB48->control_state != 9) {
        func_80614E78(D_807FBB48, 0x83);
    }
}

void func_806ED420(void) {
    if (extra_player_info_pointer->unkD4 == 0) {
        func_806CA2AC();
        func_8072DB68(3);
        switch (current_character_index[cc_player_index]) {
            case 3:
                func_80608528(D_807FBB48, 0xB9, 0xFF, 0x7F, 0x14);
                break;
            case 2:
                func_80608528(D_807FBB48, 0xD2, 0xFF, 0x7F, 0x14);
                break;
        }
        extra_player_info_pointer->unkD4 = D_807530B0[D_807FD584];
        D_807FBB48->unkB8 /= 2;
    }
}

void func_806ED508(u16 actorBehaviourIndex) {
    u16 flagIndex;
    s16 sp24;

    switch (actorBehaviourIndex) {
        case ACTOR_RAMBI_CRATE:
            // Rambi First Time Text (FTT)
            flagIndex = 0x16D;
            sp24 = 0x23;
            break;
        case 0x81: // TODO: ACTOR_ENGUARDE_CRATE
            // Enguarde First Time Text (FTT)
            flagIndex = 0x16E;
            sp24 = 0x24;
            break;
    }
    if (!isFlagSet(flagIndex, FLAG_TYPE_PERMANENT)) {
        if (actorBehaviourIndex == 0x81) { // TODO: ACTOR_ENGUARDE_CRATE
            D_807FBB48->unkB8 = 0.0f;
        }
        playCutscene(NULL, sp24, 5);
        setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
    }
}

void func_806ED5C0(Actor *arg0) {
    u16 flagIndex;
    u16 actorBehaviourIndex;
    s32 spawnerID;

    actorBehaviourIndex = arg0->unk58;
    spawnerID = func_80688E68(arg0); // getSpawnerID(actor)

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
            flagIndex = 0x169; // Hunky Chunky First Time Text
            break;
        case ACTOR_MINI_MONKEY_BARREL:
            flagIndex = 0x168; // Mini Monkey First Time Text
            break;
        case ACTOR_STRONG_KONG_BARREL:
            flagIndex = 0x16B; // Strong Kong First Time Text
            break;
        case ACTOR_ORANGSTAND_SPRINT_BARREL:
            flagIndex = 0x16A; // Orangstand Sprint First Time Text
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806ED6B0.s")

void func_806EDFF8(void) {
    func_806C8E58(extra_player_info_pointer->unk1EE);
    func_806CFF9C(D_807FBB48);
}

void func_806EE02C(void) {
    func_806CF398(D_807FBB48);
    D_807FBB48->control_state = 0x55;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE06C(void) {
    func_806CF398(D_807FBB48);
    D_807FBB48->control_state = 0x56;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(D_807FBB48, 0x87);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk38 = 0.0f;
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
}

void func_806EE10C(void) {
    if (func_806EB400(D_807FBB48)) {
        func_806CA2AC();
        if (func_806C9974(cc_player_index, -1)) {
            if (D_807FBB48->unk6A & 4) {
                func_80614E78(D_807FBB48, 0x29);
            } else {
                func_80614E78(D_807FBB48, 0x27);
            }
            D_807FBB48->control_state = 0x36;
            D_807FBB48->control_state_progress = 0;
        }
        extra_player_info_pointer->unkD4 = D_807530B0[D_807FD584];
    }
}

void func_806EE1C4(void) {
    if (extra_player_info_pointer->unk1AC != 0) {
        func_8067A784(current_actor_pointer,
                      extra_player_info_pointer->unk1AC,
                      D_807FBB48->y_rotation,
                      current_actor_pointer->y_velocity,
                      current_actor_pointer->unkB8);
        extra_player_info_pointer->unk1AC = 0;
        extra_player_info_pointer->unk1B0 = 0;
    }
    func_806CA2AC();
    func_80614E78(current_actor_pointer, 0x1C);
    D_807FBB48->control_state = 0x20;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE26C(void) {
    func_806CA2AC();
    func_80614E78(current_actor_pointer, 0x1C);
    D_807FBB48->control_state = 0x21;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE2B8(void) {
    s32 sp24;
    s8 phi_a1;

    sp24 = TRUE;
    if (func_806EB400(D_807FBB48)) {
        phi_a1 = -1;
        func_806CA2AC();
        if (character_change_array[cc_player_index].unk2A0 && character_change_array[cc_player_index].unk2A0->unk58 == 0x123) {
            phi_a1 = -2;
        }
        if (func_806C9974(cc_player_index, phi_a1)) {
            sp24 = FALSE;
            if (D_807FBB48->unk6A & 4) {
                func_80614E78(D_807FBB48, 0x29);
            } else {
                func_80614E78(D_807FBB48, 0x27);
            }
            D_807FBB48->control_state = 0x36;
            D_807FBB48->control_state_progress = 0;
        } else {
            func_80608528(current_actor_pointer, 0x16, 0xFF, 0x7F, 0);
            func_80614E78(current_actor_pointer, 0x1E);
            current_actor_pointer->control_state = 0x20;
            current_actor_pointer->control_state_progress = 1;
        }
    }
    if ((extra_player_info_pointer->unkD4 == 0) && (cc_number_of_players < 2)) {
        extra_player_info_pointer->unkD4 = D_807530B0[D_807FD584];
    }
    if (sp24) {
        func_8061F0B0(extra_player_info_pointer->unk104, 0x14, 0x14);
    }
}

void func_806EE454(void) {
    s32 sp24;

    sp24 = TRUE;
    func_806CA2AC();
    if (func_806EB400(D_807FBB48) && func_806C9974(cc_player_index, -1)) {
        sp24 = FALSE;
        if ((D_807FBB48->unk6A & 4) != 0) {
            func_80614E78(D_807FBB48, 0x29);
        } else {
            func_80614E78(D_807FBB48, 0x27);
        }
        D_807FBB48->control_state = 0x36;
        D_807FBB48->control_state_progress = 0;
    } else {
        func_80608528(current_actor_pointer, 0x16, 0xFF, 0x7F, 0);
        func_80614E78(current_actor_pointer, 0x1E);
        current_actor_pointer->control_state = 0x20;
        current_actor_pointer->control_state_progress = 1;
    }
    if ((extra_player_info_pointer->unkD4 == 0) && (cc_number_of_players < 2)) {
        extra_player_info_pointer->unkD4 = D_807530B0[D_807FD584];
    }
    if (sp24) {
        func_8061F0B0(extra_player_info_pointer->unk104, 0x14, 0x14);
    }
}

void func_806EE5A4(void) {
    func_806CA2AC();
    func_80602B60(0x6B, 0);
    current_actor_pointer->unk168 = character_change_array[cc_player_index].unk2A8;
    func_80614E78(current_actor_pointer, 0x1D);
    D_807FBB48->control_state = 0x6F;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE634(void) {
    func_806CFE7C();
    func_806CFF1C(current_actor_pointer);
}

void func_806EE660(void) {
    func_806CF398(D_807FBB48);
    func_80614E78(D_807FBB48, 0x32);
    D_807FBB48->control_state = 0x52;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE6B0(void) {
    func_806CF398(D_807FBB48);
    func_80614E78(D_807FBB48, 0x86);
    D_807FBB48->control_state = 0x53;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE700(void) {
    func_806CF398(D_807FBB48);
    func_806CFF9C(D_807FBB48);
    D_807FBB48->control_state = 0x54;
    D_807FBB48->control_state_progress = 0;
}

void func_806EE74C(void) {
    if (func_806EB400(D_807FBB48)) {
        if ((current_map != MAP_CAVES_BEETLE_RACE) && (current_map != MAP_AZTEC_BEETLE_RACE)) {
            func_806EEAF8(0x40);
        } else {
            PlayerAdditionalActorData *PaaD = extra_player_info_pointer->vehicle_actor_pointer->PaaD;
            PaaD->unk45 = 1;
        }
    }
}

void func_806EE7B8(void) {
    if (func_806EB400(D_807FBB48)) {
        func_806EEAF8(D_807FD6F2);
        func_806CFE7C();
    }
}

void func_806EE7F4(void) {
    if (D_807FBB68 & 2) {
        func_806F1048(D_807FBB48);
        func_80602B60(0xC, 0);
    }
    if ((func_806EB400(D_807FBB48)) && (((D_807FBB68 & 2) == 0) || !func_8061CB50())) {
        func_806EEAF8(1);
        func_806CFE7C();
    }
}

void func_806EE878(void) {
    if (func_806EB400(D_807FBB48)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        if (!character_change_array[cc_player_index].unk2A0) {
            func_80687474(D_807FBB48, 3.2f);
        }
        func_806EEAF8(1);
        func_806CFE7C();
        func_80697184();
    }
}

void func_806EE924(void) {
    if (func_806EB400(D_807FBB48)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        func_806EEAF8(1);
        func_806CFE7C();
    }
}

void func_806EE994(void) {
    if (func_806EB400(current_actor_pointer)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        current_actor_pointer->noclip_byte = 1;
        current_actor_pointer->control_state = 0x34;
        current_actor_pointer->control_state_progress = 0;
        func_80614EBC(current_actor_pointer, 0);
        func_806C9974(cc_player_index, -0x40);
        func_806CFE7C();
        func_80614D00(current_actor_pointer, 0, 0);
    }
}

void func_806EEA5C(void) {
    s32 phi_v0;

    if (func_806EB400(D_807FBB48)) {
        extra_player_info_pointer->unkDC = character_change_array[cc_player_index].unk2A0;
        phi_v0 = 1;
        if (extra_player_info_pointer->unkDC && (extra_player_info_pointer->unkDC->unk58 == 0x123)) {
            phi_v0 = 2;
        }
        func_806EEAF8(phi_v0);
    }
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806EEAF8.s")

void func_806EF830(void) {
    PlayerAdditionalActorData *temp_v0_4;

    switch (D_807FBB48->control_state) {
        case 0x36:
        case 0x39:
        case 0x3A:
        case 0x71:
        case 0x73:
        case 0x74:
            break;
        default:
            func_806CA2AC();
            D_807FBB48->object_properties_bitfield &= ~0x8000;
            func_80614E78(D_807FBB48, 0x27);
            D_807FBB48->control_state = 0x39;
            D_807FBB48->control_state_progress = 0;
            extra_player_info_pointer->unk11C = 0x19;
            func_8061B610(extra_player_info_pointer->unk104);
            if ((current_map != MAP_CAVES_BEETLE_RACE) && (current_map != MAP_AZTEC_BEETLE_RACE)) {
                func_806C9974(cc_player_index, -0x40);
                return;
            }
            // TODO: Which aaD type are they actually expecting here? VaaD, RaaD?
            temp_v0_4 = extra_player_info_pointer->vehicle_actor_pointer->PaaD;
            temp_v0_4->unk45 = 1;
            break;
    }
}

void func_806EF944(void) {
    if ((func_806EB400(D_807FBB48) != 0) && (D_807FBB48->control_state != 0x3B) && !func_8061CB50()) {
        func_806CA2AC();
        func_806CF42C(D_807FBB48);
        D_807FBB48->noclip_byte = 1;
        func_80614E78(D_807FBB48, 0x2A);
        D_807FBB48->control_state = 0x3B;
        D_807FBB48->control_state_progress = 0;
        func_806C9974(cc_player_index, -0x40);
        playCutscene(D_807FBB48, 0xB, 0x85);
        D_807FBB48->unkB8 = 0.0f;
    }
}

void func_806EFA08(void) {
    extra_player_info_pointer->unk1FC = 1;
}

void func_806EFA1C(void) {
    current_actor_pointer->control_state = 0x6A; // learning_gun
    current_actor_pointer->control_state_progress = 0;
}

typedef struct {
    u16 unk0[5];
} Struct8075D380;

extern Struct8075D380 D_8075D380;

void func_806EFA3C(void) {
    Struct8075D380 sp24;
    s32 temp; // TODO: wtf
    f32 scale;

    sp24 = D_8075D380;
    scale = D_807FBB48->animation_state->scale_x;
    func_80677FA8(0x140, 0xB9); // Spawn potion actor 320
    if (D_807FBB48->unk58 == 2) {
        scale = scale * 1.25;
    }
    func_8067B238(D_807FBB44, D_807FBB48, scale);
    func_80614EBC(D_807FBB44, sp24.unk0[current_character_index[extra_player_info_pointer->unk1A4]]);
    D_807FBB44->object_properties_bitfield |= 0x40000000;
    func_80614E78(D_807FBB48, 0x88);
    current_actor_pointer->control_state = 0x79;
    current_actor_pointer->control_state_progress = 0;
}

void func_806EFB4C(void) {
    func_80602B60(0x6B, 0);
    func_806CA2AC();
    func_806C9F74(D_807FBB48);
    func_806CF42C(D_807FBB48);
    func_80614E78(D_807FBB48, 0x5B);
    D_807FBB48->control_state = 0x70;
    D_807FBB48->control_state_progress = 0;
    if (D_807FBB48->unkFC) {
        D_807FBB48->y_rotation = func_80672A70(D_807FBB48->unkF4, D_807FBB48->unkF6);
    } else {
        D_807FBB48->y_rotation = func_80665DE0(character_change_array[cc_player_index].look_at_eye_x,
                                               character_change_array[cc_player_index].look_at_eye_z,
                                               D_807FBB48->x_position,
                                               D_807FBB48->z_position);
    }
    func_80627948(D_807FBB48, 0x15, 0x1F, 5);
}

void func_806EFC38(void) {
    func_806CA2AC();
    func_806CF42C(D_807FBB48);
    func_806C9F74(D_807FBB48);
    if (D_807FBB48->control_state != 0x6D) {
        func_80614E78(D_807FBB48, 0x5B);
        D_807FBB48->control_state = 0x71;
        D_807FBB48->control_state_progress = 0;
    }
    D_807FBB48->y_rotation = func_80665DE0(character_change_array[cc_player_index].look_at_eye_x,
                                           character_change_array[cc_player_index].look_at_eye_z,
                                           D_807FBB48->x_position,
                                           D_807FBB48->z_position);
    if (current_map == MAP_JAPES_ARMY_DILLO) {
        playCutscene(D_807FBB48, 2, 1);
        D_807FBB48->control_state_progress = 0xFF;
        extra_player_info_pointer->unk23C = 0xFFFF;
    } else {
        playCutscene(D_807FBB48, 5, 5);
        extra_player_info_pointer->unk23C = 0x64;
    }
}

void func_806EFD50(void) {
    func_806CA2AC();
    func_806CF42C(D_807FBB48);
    func_80614E78(D_807FBB48, 0x5B);
    D_807FBB48->control_state = 0x72;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->y_rotation = func_80665DE0(character_change_array[cc_player_index].look_at_eye_x,
                                        character_change_array[cc_player_index].look_at_eye_z,
                                        D_807FBB48->x_position,
                                        D_807FBB48->z_position);
    playCutscene(D_807FBB48, 0x15, 5);
}

void func_806EFDFC(void) {
    Actor *vehicle;

    func_806C8E58(extra_player_info_pointer->unk1EE);
    func_806CF42C(D_807FBB48);
    func_806CA2AC();
    D_807FBB48->noclip_byte = 1;
    if (D_807FBB48->control_state != 0x7D) {
        if (D_807FBB48->unk6A & 4) {
            func_80614E78(D_807FBB48, 0x34);
        } else if (!(D_807FBB48->unk6A & 2)) {
            func_80614E78(D_807FBB48, 0x5D);
        }
    }
    D_807FBB48->control_state = 0x73;
    D_807FBB48->control_state_progress = 0;
    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (!vehicle || vehicle->unk58 != 0x57) {
        D_807FBB48->y_rotation = func_80665DE0(character_change_array[cc_player_index].look_at_eye_x,
                                               character_change_array[cc_player_index].look_at_eye_z,
                                               D_807FBB48->x_position,
                                               D_807FBB48->z_position);
    }
    D_807FBB48->y_velocity = 0.0f;
    extra_player_info_pointer->unk23C = 0x5A;
    func_806CFE7C();
}

void func_806EFF34(void) {
    Actor *vehicle;

    func_806C8E58(extra_player_info_pointer->unk1EE);
    func_806CF42C(D_807FBB48);
    func_806CA2AC();
    D_807FBB48->noclip_byte = 1;
    if (D_807FBB48->control_state != 0x7D) {
        if (D_807FBB48->unk6A & 4) {
            func_80614E78(D_807FBB48, 0x34);
        } else if (!(D_807FBB48->unk6A & 2)) {
            func_80614E78(D_807FBB48, 0x5C);
        }
    }
    D_807FBB48->control_state = 0x74;
    D_807FBB48->control_state_progress = 0;
    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (!vehicle || vehicle->unk58 != 0x57) {
        D_807FBB48->y_rotation = func_80665DE0(character_change_array[cc_player_index].look_at_eye_x,
                                               character_change_array[cc_player_index].look_at_eye_z,
                                               D_807FBB48->x_position,
                                               D_807FBB48->z_position);
    }
    D_807FBB48->y_velocity = 0.0f;
    extra_player_info_pointer->unk23C = 0x5A;
    func_806CFE7C();
}

void func_806F006C(void) {

}

void func_806F0074(void) {

}

void func_806F007C(void) {
    current_actor_pointer->control_state = 0x84;
    current_actor_pointer->control_state_progress = 0;
    func_80614EBC(current_actor_pointer, 0);
}

void func_806F00BC(void) {
    func_806CA2AC();
    extra_player_info_pointer->unk1F0 &= ~0x20;
    D_807FBB48->unk132 = 2;
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk30 = D_80753250[D_807FD584];
    D_807FBB48->control_state = 0x7A;
    D_807FBB48->control_state_progress = 0;
}

void func_806F014C(void) {
    extra_player_info_pointer->unk1F4 |= 8;
    func_806CFF9C(D_807FBB48);
}

void func_806F0184(void) {
    func_806CA2AC();
    extra_player_info_pointer->unk1F0 &= ~0x20;
    D_807FBB48->control_state = 0x7B;
    D_807FBB48->control_state_progress = 0;
}

void func_806F01D8(void) {
    func_806CA2AC();
    func_806F00BC();
    extra_player_info_pointer->vehicle_actor_pointer = character_change_array[cc_player_index].unk2A0;
}

void func_806F0238(void) {
    func_80614E78(D_807FBB48, 9);
    D_807FBB48->control_state = 0xC;
    D_807FBB48->control_state_progress = 0;
}

void func_806F027C(void) {
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk30 = D_80753250[D_807FD584];
    func_806CFE7C();
    if (D_807FBB48->control_state != 0x7C) {
        func_806CA2AC();
        D_807FBB48->control_state = 0x7C;
        D_807FBB48->control_state_progress = 0;
        func_80614EBC(D_807FBB48, 0x13);
        func_80677FA8(0x117, 0xC5); // Spawn trap bubble (spider miniboss) actor 279
        D_807FBB44->unk11C = D_807FBB48;
        func_806C8D20(D_807FBB48);
    }
}

void func_806F0344(void) {
    func_806CFE7C();
    D_807FBB48->control_state = 0x7D;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->object_properties_bitfield &= ~4;
    func_80677FA8(0x11A, 0x21); // Spawn actor (beaver bother?)
    func_80614EBC(D_807FBB44, 0x232);
    D_807FBB44->unk11C = D_807FBB48;
}

// Character Change, Jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EFDC0/func_806F03C4.s")

void func_806F0624(void) {
    extra_player_info_pointer->unk1F4 |= 0x10;
    func_806E9964(extra_player_info_pointer);
    D_807FBB48->control_state = 0x83;
    D_807FBB48->control_state_progress = 0;
    D_807FBB48->object_properties_bitfield |= 0x40000004;
    D_807FBB48->object_properties_bitfield &= ~1;
}

void func_806F06A4(void) {
    D_807FBB48->control_state = 0x87;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
}

void func_806F0700(void) {
    f32 temp_f0;

    D_807FBB48->control_state = 0x88;
    D_807FBB48->control_state_progress = 0;
    func_80614EBC(D_807FBB48, 0);
    temp_f0 = D_8075D5D8;
    D_807FBB48->x_position = extra_player_info_pointer->unk22C;
    D_807FBB48->y_position = extra_player_info_pointer->unk230;
    D_807FBB48->z_position = extra_player_info_pointer->unk234;
    D_807FBB48->x_rotation = -0x3E6;
    D_807FBB48->animation_state->scale_x = temp_f0;
    D_807FBB48->animation_state->scale_y = temp_f0;
    D_807FBB48->animation_state->scale_z = temp_f0;
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk4C = -1;
}

void func_806F07CC(void) {
    func_80608528(D_807FBB48, 0xF3, 0xFF, 0x7F, 0x19);
    D_807FBB48->control_state = 0x19;
    D_807FBB48->control_state_progress = 0;
    extra_player_info_pointer->unk54 = D_807535CC[D_807FD584] * D_8075D5E0;
    extra_player_info_pointer->unk50 = 0xC;
    func_80614E78(D_807FBB48, 0x10);
}

void func_806F0878(void) {
    if (D_807FBB48->unk78 == 0xC) {
        func_80608528(D_807FBB48, 0x76, 0x64, 0x7F, 0);
    }
    extra_player_info_pointer->unk38 = D_807531FC[D_807FD584];
    func_806CF398(D_807FBB48);
    D_807FBB48->control_state = 0x15;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(D_807FBB48, 6);
    D_807FBB48->unk6A |= 0x20;
    func_80614D90(D_807FBB48);
}

void func_806F0930(void) {
    if (D_807FBB48->unk78 == 0xC) {
        func_80608528(D_807FBB48, 0x76, 0xFF, 0x7F, 0);
    }
    extra_player_info_pointer->unk38 = D_807531FC[D_807FD584];
    func_806CF398(D_807FBB48);
    D_807FBB48->control_state = 0x16;
    D_807FBB48->control_state_progress = 0;
    func_80614E78(D_807FBB48, 7);
    D_807FBB48->unk6A |= 0x20;
    func_80614D90(D_807FBB48);
}
