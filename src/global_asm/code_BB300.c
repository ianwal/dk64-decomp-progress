#include <ultra64.h>
#include "functions.h"



extern f32 D_807502E8;
extern s16 D_807502E0;
extern u8 D_807FBD70;

void func_8072AB74(s32, f32, f32, s32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BB300/func_806B6600.s")

extern f64 D_8075B760;
extern f32 D_8075B768; // TODO: f64?

typedef struct {
    u8 unk0;
    u8 unk1;
} Actor178_806B6600;

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} AnimationState1C_806B6600;

/*
// TODO: Progress made, rodata issue?
void func_806B6600(u8 arg0) {
    Actor178_806B6600 *temp_v0;
    f32 temp_f0;
    u8 temp_t5;
    u8 temp_t9;
    u8 var_v1;
    AnimationState1C_806B6600 *temp_t0;
    AnimationState1C_806B6600 *temp_t0_2;

    temp_v0 = current_actor_pointer->unk178;
    temp_t0 = current_actor_pointer->animation_state->unk1C;
    if (!arg0) {
        temp_v0->unk0 += (-temp_v0->unk0 * D_8075B760);
        temp_v0->unk1 = 0;
        var_v1 = temp_v0->unk0;
    } else {
        switch (temp_v0->unk1) {
            default:
                var_v1 = temp_v0->unk0;
                break;
            case 0:
                temp_v0->unk1 = 1;
                var_v1 = temp_v0->unk0;
                break;
            case 1:
                temp_t5 = temp_v0->unk0 + 0x32;
                var_v1 = temp_t5;
                temp_v0->unk0 = temp_t5;
                if (var_v1 >= 0xCE) {
                    temp_v0->unk0 = 0xFF;
                    temp_v0->unk1 = 2;
                    var_v1 = 0xFF;
                }
                break;
            case 2:
                temp_t9 = temp_v0->unk0 - 0x50;
                var_v1 = temp_t9;
                temp_v0->unk0 = temp_t9;
                if ((var_v1 >= 0x64) && (var_v1 < 0xB4)) {
                    func_80608528(current_actor_pointer, 0x16C, 0xFF, 0xA0, 6);
                    var_v1 = temp_v0->unk0;
                }
                if (var_v1 < 0x50) {
                    temp_v0->unk0 = 0;
                    temp_v0->unk1 = 0;
                    var_v1 = 0;
                }
                break;
        }
    }
    temp_f0 = 8000.0f * (var_v1 / D_8075B768);
    temp_t0->unk2 = -temp_f0;
    temp_t0_2 = &temp_t0[1];
    temp_t0_2->unk1 = 3;
    temp_t0_2->unk0 = 0x7F;
    temp_t0_2->unk2 = temp_f0;
    temp_t0_2->unk4 = 0;
    temp_t0_2->unk6 = 0;
}
*/

void func_806B6958(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FDC90->unk35 *= 2;
        D_807FDC90->unk2C = 210;
        D_807FDC90->unk1F *= 1.5;
        D_807FDC90->unk1E *= 1.5;
    }
    if (D_807FDC90->unk2C != 0) {
        D_807FDC90->unk2C--;
    }
    if ((D_807FDC90->unk2C % 30) == 0) {
        D_807FDC90->unk1F--;
        D_807FDC90->unk1E--;
    }
    if (D_807FBB70->unk200 == 4) {
        func_80724C2C(-150);
    }
    if ((D_807FDC90->unk2C == 0) || (D_807FBB70->unk200 == 9) || (D_807FBB70->unk15 != 0)) {
        func_80608528(current_actor_pointer, 0x3B2, 0xFF, 0x7F, 0x1E);
        func_80608528(current_actor_pointer, 0x3B7, 0xFF, 0x7F, 0x1E);
        func_806850D0();
        func_806782C0(current_actor_pointer);
    }
    if (current_actor_pointer->control_state == 0x23) {
        func_8072AB74(0x23, D_807FDC94->x_position, D_807FDC94->z_position, 0x200, 0.0f);
    } else {
        func_8072B7CC(0x237);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806B6C88(s16 arg0, s16 arg1) {
    if (func_80677FA8(0xD3, 0x24)) { // Spawn actor: Klaptrap (Skeleton)
        D_807FBB44->control_state = 0x23;
        func_80614EBC(D_807FBB44, 0x237);
        D_807FBB44->y_rotation = arg1;
        D_807FBB44->unkEE = D_807FBB44->y_rotation;
        func_8067B238(D_807FBB44, 
                      current_actor_pointer, 
                      current_actor_pointer->animation_state->scale_y);
        D_807FBB44->floor = current_actor_pointer->floor;
        D_807FBB44->y_acceleration = D_807502E8;
        D_807FBB44->terminal_velocity = D_807502E0;
        D_807FBB44->unkB8 = 0.0f;
        func_8072B324(current_actor_pointer, arg0 * 1.25);
        // TODO: Which aaD type are they actually expecting here?
        memcpy(D_807FBB44->PaaD, 
               current_actor_pointer->PaaD, 
               0x3C);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BB300/func_806B6DB0.s")

void func_806B75F4() {
    func_80729B00();
    func_806B6DB0(10000);
}

void func_806B761C() {
    func_80729B00();
    if (D_807FBD70 == 4) {
        func_80724C2C(-100);
    }
    func_806B6DB0(10000);
}

void func_806B7660() {
    func_80729B00();
    if (D_807FBD70 == 4) {
        func_80724C2C(-100);
    }
    func_806B6DB0(10000);
}