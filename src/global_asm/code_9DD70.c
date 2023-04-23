#include <ultra64.h>
#include "functions.h"


extern s8 D_807F6951;
extern s8 D_807F6950;

void func_80613C48(Actor*, s16, f32, f32);
void func_8070D8C0(Actor*, s32, u8);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_80699070.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_80699128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_80699284.s")

void func_806998C8(void) {
    func_80699284();
}

void func_806998E8(void) {

}

void func_806998F0(void) {
    func_80699958(8, 0);
}

void func_80699914(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 1000;
    }
    func_80699958(0x1C, 1);
}

// Huge, lots of ActorAnimationState stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_80699958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069A614.s")

// TODO: Needs proper definition for D_807FBB70
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069A750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069A7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069AB74.s")

void func_8069AFF0(void) {
    func_8069AB74();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069B010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069B3FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069B85C.s")

extern s32 D_8076A068;

/*
// TODO: Regalloc :(
s32 func_8069B85C(void) {
    Actor *temp_v1;
    ActorCollision *collision = current_actor_pointer->collision_queue_pointer;

    while (collision) {
        if ((collision->unk0 == 0x8000) && (func_8067AF44(collision->collisionSource))) {
            temp_v1 = collision->collisionSource;
            if ((temp_v1->interactable & 1) && ((D_8076A068 - temp_v1->PaaD->unk120) < 2U)) {
                return TRUE;
            }
        }
        collision = collision->next;
    }
    return FALSE;
}
*/

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069B908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069CD9C.s")

void func_8069B908();
extern f64 D_8075A3F8;
extern f64 D_8075A400;

/*
// TODO: Just some float nonsense to sort out
void func_8069CD9C(void) {
    f32 dx, dy, dz;
    f32 phi_f0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        phi_f0 = (current_actor_pointer->animation_state->scale_x / D_8075A3F8) - 1.0;
        if (phi_f0 < 0.0) {
            phi_f0 = 0.0f;
        }
        current_actor_pointer->unk130 = phi_f0 * 80;
        current_actor_pointer->unk131 = phi_f0 * 80;
        current_actor_pointer->draw_distance = 700;
    }
    dz = current_actor_pointer->z_position - character_change_array->look_at_eye_z;
    dx = current_actor_pointer->x_position - character_change_array->look_at_eye_x;
    dy = current_actor_pointer->y_position - character_change_array->look_at_eye_y;
    if (((dx * dx) + (dy * dy) + (dz * dz)) < D_8075A400) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
    func_8069B908();
}
*/

void func_8069CF54(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk130 = 0x3C;
        current_actor_pointer->unk131 = 0x3C;
        func_80689114(0x83, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 1.0f, current_actor_pointer);
    }
    func_8069B908();
    if ((!(current_actor_pointer->object_properties_bitfield & 0x10)) && (current_actor_pointer->unk124->unk8_s32 == 1) && isFlagSet(0xFD, FLAG_TYPE_PERMANENT)) {
        current_actor_pointer->unk132 = 4;
    }
}

void func_8069D018(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 700;
    }
    func_8069B908();
}

void func_8069D058(void) {
    func_8069D018();
}

void func_8069D078(void) {
    func_8069D018();
}

void func_8069D098(void) {
    func_8069D018();
}

void func_8069D0B8(void) {
    func_8069D018();
}

void func_8069D0D8(void) {
    func_8069B908();
}

extern s16 D_80744490;

// TODO: Put in PaaD union
typedef struct {
    void* unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
} GlobalASMStruct_8069D0F8;

void func_8069D0F8(u8 arg0, s16 arg1, s16 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7);

u8 func_806FDB8C(s16, s32, s32, f32, f32, f32);
s32 func_806FBD5C(s16, s32);

void func_8069D0F8(u8 arg0, s16 arg1, s16 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {
    GlobalASMStruct_8069D0F8 *temp_s0;

    if (func_80677FA8(0xE8, 0) != 0) {
        temp_s0 = D_807FBB44->additional_actor_data;
        if (arg0 & 0x80) {
            temp_s0->unkA = func_806FDB8C(arg0 & 0xff7f, arg3, 2, 160.0f, arg2, 0.0f);
            D_807FBB44->unkEE = 1;
            D_807FBB44->y_position = arg2;
            return;
        }
        if (arg1 == 0) {
            D_807FBB44->x_position = (D_80744490 - func_806FBD5C(arg0, arg3)) * 2;
        } else {
            D_807FBB44->x_position = arg1 * 4;
        }
        D_807FBB44->y_position = arg2 * 4;
        D_807FBB44->z_position = arg0;
        D_807FBB44->unk16A = 0xFF;
        D_807FBB44->unk16B = 0xFF;
        D_807FBB44->unk16C = 0xFF;
        temp_s0->unk0 = malloc(func_80002F18(arg3) + 1);
        func_80002A30(temp_s0->unk0, arg3);
        temp_s0->unk4 = arg4;
        temp_s0->unk6 = arg5;
        temp_s0->unk8 = arg6;
        temp_s0->unk9 = arg7;
    }
}

void func_8069D2AC(u8 arg0, s16 arg1, s16 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {
    if ((cc_number_of_players < 2)
        && !gameIsInMainMenuMode()
        && !gameIsInDKTVMode()
        && (gameIsInAdventureMode() || gameIsInDKTheatreMode())) {
        func_8069D0F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069D358.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069D424.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069D930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069DA54.s")

// Negative struct offset in loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069DC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_8069DC80.s")

void func_8069DC10(s32, void*, u8);
s32 func_806FBB9C(s16 textureIndex);

/*
// TODO: Bleh, stack nonsense, beqzl vs beqz
void *func_8069DC80(u8 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    s32 sp24;
    void *temp_v0;

    sp24 = func_806FBB9C(arg0 + arg3);
    if (arg1) {
        func_8061134C(arg1);
    }
    temp_v0 = malloc(arg4 << 7);
    func_8069DC10(temp_v0, sp24, arg4);
    func_8068842C(current_actor_pointer, arg2, -1);
    func_80688370(current_actor_pointer, arg2, 0);
    func_80688320(current_actor_pointer, arg2, 0, temp_v0);
    return temp_v0;
}
*/

extern u16 D_807446C0[];
extern s16 D_807FC930[];

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} AAD_8069DD40;

void func_8069DD40(void) {
    s32 pad[3]; // TODO: Can we get rid of this somehow?
    AAD_8069DD40 *temp_s1;
    u16 temp_s0;
    s32 levelIndex;

    temp_s1 = current_actor_pointer->additional_actor_data;
    if (((current_actor_pointer->object_properties_bitfield & 0x10) == 0) || (extra_player_info_pointer->unk1F0 & 0x20000)) {
        levelIndex = getLevelIndex(D_8076A0AB, FALSE);
        if (levelIndex >= 8) {
            levelIndex = 0;
        }
        temp_s0 = D_807FC930[levelIndex];
        temp_s1->unk0 = func_8069DC80(0x21, temp_s1->unk0, 0, (temp_s0 / 100) & 0xFF, 0x20);
        temp_s1->unk4 = func_8069DC80(0x21, temp_s1->unk4, 1, ((temp_s0 % 100) / 10) & 0xFF, 0x20);
        temp_s1->unk8 = func_8069DC80(0x21, temp_s1->unk8, 2, (temp_s0 % 10) & 0xFF, 0x20);
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        extra_player_info_pointer->unk1F0 &= 0xFFFDFFFF;
        if (temp_s0 >= D_807446C0[levelIndex]) {
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity = 0;
            current_actor_pointer->noclip_byte = 1;
            func_8063DA40(8, 2);
            func_8063DA40(9, 0xA);
            func_8063DA40(0xA, 0xA);
            func_8063DA40(0xB, 0xA);
            func_8063DA40(0xD, 0xA);
            func_8063DA40(0xC, 0xA);
        }
    }
    func_806319C4(current_actor_pointer, 0);
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_8069DF58;

void func_8069DF58(void) {
    AAD_8069DF58 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        temp_v1->unk0 = func_8069DC80(0x14, temp_v1->unk0, 0, (current_actor_pointer->control_state_progress / 10) & 0xFF, 0x10);
        temp_v1->unk4 = func_8069DC80(0x14, temp_v1->unk4, 1, (current_actor_pointer->control_state_progress % 10) & 0xFF, 0x10);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_8069E018(void) {
    func_806319C4(current_actor_pointer, 0);
}

void func_8069E040() {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_80614EBC(current_actor_pointer, 0x299);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_8069E088(void) {
    s16 phi_s0_2;

    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_80613C48(current_actor_pointer, 0x5ED, 0, 0);
    }
    current_actor_pointer->unk15E = 0x14;
    if (current_actor_pointer->control_state < 0x1E) {
        current_actor_pointer->control_state++;
    }
    if (current_actor_pointer->control_state == 0x1E) {
        phi_s0_2 = 0;
        current_actor_pointer->control_state = 0x64;
        func_8070E8DC(1);
        if (!isFlagSet(0x178, FLAG_TYPE_PERMANENT)) { // Wrinkly FTT
            setFlag(0x178, TRUE, FLAG_TYPE_PERMANENT);
        } else {
            phi_s0_2 = (func_80600530() * 5) + D_807F6951 + 1;
        }
        func_8070D8C0(current_actor_pointer, 0x29, phi_s0_2);
    }
    if (D_807F6950 != 0) {
        func_806782C0(current_actor_pointer);
    }
    current_actor_pointer->animation_state->scale_x = 0.0f;
    current_actor_pointer->animation_state->scale_y = 0.0f;
    current_actor_pointer->animation_state->scale_z = 0.0f;
    func_806319C4(current_actor_pointer, 0);
}
