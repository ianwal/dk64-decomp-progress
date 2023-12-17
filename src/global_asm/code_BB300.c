#include <ultra64.h>
#include "functions.h"

extern f32 D_global_asm_807502E8;
extern s16 D_global_asm_807502E0;

extern u8 D_global_asm_807FBD70;

void func_global_asm_8072AB74(s32, f32, f32, s32, f32);

// rodata, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BB300/func_global_asm_806B6600.s")

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
void func_global_asm_806B6600(u8 arg0) {
    Actor178_806B6600 *a178;
    u32 temp_f0;
    AnimationState1C_806B6600 *temp_t0;

    a178 = current_actor_pointer->unk178;
    temp_t0 = current_actor_pointer->animation_state->unk1C;
    if (!arg0) {
        a178->unk0 += (-a178->unk0 * 0.2);
        a178->unk1 = 0;
    } else {
        switch (a178->unk1) {
            case 0:
                a178->unk1 = 1;
                break;
            case 1:
                a178->unk0 += 0x32;
                if (a178->unk0 >= 0xCE) {
                    a178->unk0 = 0xFF;
                    a178->unk1 = 2;
                }
                break;
            case 2:
                a178->unk0 -= 0x50;
                if ((a178->unk0 >= 0x64) && (a178->unk0 < 0xB4)) {
                    func_global_asm_80608528(current_actor_pointer, 0x16C, 0xFF, 0xA0, 6);
                }
                if (a178->unk0 < 0x50) {
                    a178->unk0 = 0;
                    a178->unk1 = 0;
                }
                break;
        }
    }
    temp_f0 = (8000.0f * (a178->unk0 / 255.0));
    temp_t0->unk2 = -temp_f0;
    (++temp_t0)->unk1 = 3;
    temp_t0->unk0 = 0x7F;
    temp_t0->unk2 = temp_f0;
    temp_t0->unk4 = 0;
    temp_t0->unk6 = 0;
}
*/

void func_global_asm_806B6958(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC90->unk35 *= 2;
        D_global_asm_807FDC90->unk2C = 210;
        D_global_asm_807FDC90->unk1F *= 1.5;
        D_global_asm_807FDC90->unk1E *= 1.5;
    }
    if (D_global_asm_807FDC90->unk2C != 0) {
        D_global_asm_807FDC90->unk2C--;
    }
    if ((D_global_asm_807FDC90->unk2C % 30) == 0) {
        D_global_asm_807FDC90->unk1F--;
        D_global_asm_807FDC90->unk1E--;
    }
    if (D_global_asm_807FBB70.unk200 == 4) {
        func_global_asm_80724C2C(-150);
    }
    if ((D_global_asm_807FDC90->unk2C == 0) || (D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) {
        func_global_asm_80608528(current_actor_pointer, 0x3B2, 0xFF, 0x7F, 0x1E);
        func_global_asm_80608528(current_actor_pointer, 0x3B7, 0xFF, 0x7F, 0x1E);
        func_global_asm_806850D0();
        deleteActor(current_actor_pointer);
    }
    if (current_actor_pointer->control_state == 0x23) {
        func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
    } else {
        func_global_asm_8072B7CC(0x237);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806B6C88(s16 arg0, s16 arg1) {
    if (spawnActor(ACTOR_KLAPTRAP_SKELETON, 0x24)) { // Spawn actor: Klaptrap (Skeleton)
        last_spawned_actor->control_state = 0x23;
        func_global_asm_80614EBC(last_spawned_actor, 0x237);
        last_spawned_actor->y_rotation = arg1;
        last_spawned_actor->unkEE = last_spawned_actor->y_rotation;
        func_global_asm_8067B238(last_spawned_actor, 
                      current_actor_pointer, 
                      current_actor_pointer->animation_state->scale_y);
        last_spawned_actor->floor = current_actor_pointer->floor;
        last_spawned_actor->y_acceleration = D_global_asm_807502E8;
        last_spawned_actor->terminal_velocity = D_global_asm_807502E0;
        last_spawned_actor->unkB8 = 0.0f;
        func_global_asm_8072B324(current_actor_pointer, arg0 * 1.25);
        // TODO: Which aaD type are they actually expecting here?
        memcpy(last_spawned_actor->PaaD, 
               current_actor_pointer->PaaD, 
               0x3C);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BB300/func_global_asm_806B6DB0.s")

void func_global_asm_806B75F4(void) {
    func_global_asm_80729B00();
    func_global_asm_806B6DB0(10000);
}

void func_global_asm_806B761C(void) {
    func_global_asm_80729B00();
    if (D_global_asm_807FBD70 == 4) {
        func_global_asm_80724C2C(-100);
    }
    func_global_asm_806B6DB0(10000);
}

void func_global_asm_806B7660(void) {
    func_global_asm_80729B00();
    if (D_global_asm_807FBD70 == 4) {
        func_global_asm_80724C2C(-100);
    }
    func_global_asm_806B6DB0(10000);
}