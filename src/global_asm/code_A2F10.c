#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069E210.s")

void func_806A5DF0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6, Actor *arg7);

void func_8069E490(u16 arg0, s16 arg1) {
    func_806A5DF0(arg0, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, arg1, current_actor_pointer);
}

void func_8067A70C(Actor *, void *, f32, f32, f32, s32, s32);
extern u16 D_807FBB34;

void func_8069E4E0(s16 arg0) {
    Actor *temp_a1;
    s16 i;

    for (i = 0; i < D_807FBB34; i++) {
        temp_a1 = D_807FB930[i].unk0;
        if (current_actor_pointer == temp_a1->unk11C) {
            func_8067A70C(current_actor_pointer, temp_a1, current_actor_pointer->x_position, current_actor_pointer->y_position + arg0, current_actor_pointer->z_position, 2, 1);
        }
    }
}

void func_8069E5B8(void) {
    Actor *temp_a0;
    s16 phi_s0;

    for (phi_s0 = 0; phi_s0 < D_807FBB34; phi_s0++) {
        temp_a0 = D_807FB930[phi_s0].unk0;
        if (current_actor_pointer == temp_a0->unk11C) {
            func_80679200(temp_a0, current_actor_pointer, 0x02000000, 1, 0, 0);
        }
    }
}

// TODO: Yikes, needs a dx dz macro or something...
int func_8069E660(Actor *arg0, f32 arg1, f32 arg2) {
    return (arg0->y_position - 8.0f) <= current_actor_pointer->y_position
        && current_actor_pointer->y_position < (arg0->y_position + arg1)
        && ((((arg0->x_position - current_actor_pointer->x_position) * (arg0->x_position - current_actor_pointer->x_position)) + ((arg0->z_position - current_actor_pointer->z_position) * (arg0->z_position - current_actor_pointer->z_position))) < arg2)
        && (arg0->noclip_byte != 1);
}

// Jumptable, a fun one though
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069E724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069E774.s")

s32 func_8069EF50(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 dx = player_pointer->x_position - arg0;
    f32 dz = player_pointer->z_position - arg2;

    if (((dx * dx) + (dz * dz)) < (arg4 * arg4)) {
        if ((arg1 <= player_pointer->y_position) && (player_pointer->y_position < (arg1 + arg3))) {
            return TRUE;
        }
    }
    return FALSE;
}

// Huge, surprisingly doable though
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069F020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069F904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069FA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069FDA0.s")

extern f32 D_80750394;

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_806A018C;

void func_80665564(Actor*, f32);

void func_806A018C(void) {
    AAD_806A018C *temp_s1;

    temp_s1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk0;
        current_actor_pointer->unkEE = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 1;
        temp_s1->unk0 = (rand() >> 0xF) % 70;
        temp_s1->unk4 = (rand() >> 0xF) % 200;
    }
    func_8067ACB4(current_actor_pointer);
    func_806651FC(current_actor_pointer);
    func_80665564(current_actor_pointer, 0);
    current_actor_pointer->y_velocity += D_80750394;
    current_actor_pointer->z_rotation += temp_s1->unk4;
    current_actor_pointer->x_rotation += temp_s1->unk0;
    if ((current_actor_pointer->unkFC != 0) || ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1))) {
        func_806782C0(current_actor_pointer);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806A02F0(void) {
    func_806A018C();
}

void func_806A0310(void) {
    func_806A018C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A0330.s")

void func_806A05D4(void) {
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A05FC.s")

void func_806A081C(Actor *arg0) {
    func_80677FA8(ACTOR_KONG_REFLECTION, func_80613448(arg0));
    D_807FBB44->unk11C = arg0;
    arg0->unk6A |=  0x800;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A0864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A0B74.s")

void func_806883F4(Actor *arg0, s32 arg1, u8 arg2, f32 arg3);

void func_806A0F78(Actor *arg0, u8 arg1, u8 arg2) {
    func_8068842C(arg0, 0, 1);
    func_80688460(arg0, 0, 1);
    func_806883F4(arg0, 0, arg1, 0.0f);
    func_8068842C(arg0, 1, 1);
    func_80688460(arg0, 1, 1);
    func_806883F4(arg0, 1, arg2, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A1008.s")

// AnimationState->unk24
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A10BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A112C.s")
