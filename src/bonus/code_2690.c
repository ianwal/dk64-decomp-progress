#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80026690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80026940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80026CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_800271B4.s")

typedef struct bonus_struct_0 {
    u8 pad0[0x9];
    u8 unk9;
} BonusStruct0;

void func_80027308(BonusStruct0 *arg0, s32 *arg1) {
    *(arg1 + (arg0->unk9)) = 0;
    func_806782C0(current_actor_pointer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002733C.s")

void func_806907F0(f32, f32, f32);
void func_80690A28(s32, s32, f32, f32, f32, f32, f32, Actor *);
extern f32 D_8002DD28;

void func_800274A0(f32 arg0, f32 arg1, f32 arg2) {
    Actor *temp_v0;

    playSound(0x59, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
    temp_v0 = current_actor_pointer;
    func_806907F0(temp_v0->x_position, temp_v0->y_position - 10.0f, temp_v0->z_position);
    func_80690A28(0x23, 1, 0.6f, arg0, arg1, arg2, D_8002DD28, current_actor_pointer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80027548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_800277F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80027F14.s")

// Baad2 Use?
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_800284C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80028648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002881C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80028E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80029364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80029B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80029E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002A010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002A398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002AAA4.s")

// AnimationState, aaD
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002AD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002AED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002B920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002BE44.s")

/*
// TODO: what a mess
void func_80613C48(Actor*, s16, f32, f32);
void func_80614644(Actor *, ActorAnimationState *, s32);
void func_806319C4(Actor *, s32);
extern f32 D_8002DE50;
extern f64 D_8002DE58;
typedef struct BonusStruct1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} BonusStruct1;

typedef struct bonus_additional_actor_data {
    s32 unk0;
    BonusStruct1* unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad0[0x7C - 0x14];
    f32 x_position;
    f32 y_position;
    f32 z_position;
} BonusAdditionalActorData;

void func_8002BE44() {
    ActorAnimationState *sp24;
    BonusAdditionalActorData *temp_a0;
    BonusStruct1 *temp_t8;
    s16 phi_a1;

    temp_a0 = ((BonusAdditionalActorData*)current_actor_pointer->additional_data_pointer);
    sp24 = current_actor_pointer->animation_state;
    temp_t8 = temp_a0->unk4;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->z_rotation = 0;
        current_actor_pointer->y_rotation = 0x800;
        func_80613C48(temp_a0, 0x5FB, 0, 0);
        current_actor_pointer->animation_state->scale_x =// D_8002DE50;
        current_actor_pointer->animation_state->scale_z =// D_8002DE50;
        current_actor_pointer->animation_state->scale_y = D_8002DE50;
    }
    current_actor_pointer->x_position = temp_a0->x_position;
    current_actor_pointer->y_position = temp_a0->y_position - D_8002DE58;
    current_actor_pointer->z_position = temp_a0->z_position;
    if (sp24 && temp_t8) {
        phi_a1 = temp_t8->unk10;
        if (phi_a1 == 0x5FD) {
            phi_a1 = 0x5FE;
        }
        if (phi_a1 != sp24->unk10) {
            func_80613C48(current_actor_pointer, phi_a1, 0, 0);
        }
        func_80614644(current_actor_pointer, sp24, temp_t8->unk4);
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002BF98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002C8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002CC08.s")
