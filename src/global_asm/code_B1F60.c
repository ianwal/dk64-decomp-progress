#include <ultra64.h>
#include "functions.h"


void func_80724E48(u8);
void func_8072B79C(s32, s32, s32);
void func_806782C0(Actor *);
s32 func_8072881C(s32, s32);
s32 func_8072AB74(u8, f32, f32, s32, f32);
s32 func_8072D714(s32, s32);

extern f64 D_8075AE10;
extern f32 D_8075AE18;

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B1F60/func_806AD260.s")

void func_806AD54C(void) {
    f32 dx, dz;
    Actor *klaptrap;
    s32 angleSign;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80724CA4(2, 1);
        func_8072B79C(0x1F8, 0x1F8, 0x1F9);
        if (current_map == MAP_BEAVER_BOTHER_EASY || current_map == MAP_BEAVER_BOTHER_NORMAL || current_map == MAP_BEAVER_BOTHER_HARD) {
            current_actor_pointer->unk132 = 2;
        }
    }
    if ((current_actor_pointer->unk132 == 2) && (current_actor_pointer->control_state != 0x36)) {
        klaptrap = func_8067ADB4(0x11A);
        if (klaptrap) {
            if (klaptrap->control_state != 0) {
                if (!(D_807FDC90->unk1A & 0x8000)) {
                    dx = klaptrap->x_position - current_actor_pointer->x_position;
                    dz = klaptrap->z_position - current_actor_pointer->z_position;
                    if (((dx * dx) + (dz * dz)) < 1600.0f) {
                        angleSign = ((klaptrap->y_rotation - current_actor_pointer->y_rotation) & 0xFFF) >= 0x801 ? 1 : -1;
                        current_actor_pointer->unkB8 = D_807FDC9C->unkD * D_8075AE10;
                        current_actor_pointer->y_rotation += angleSign * 400;
                        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                        D_807FDC90->unk1A |= 0x8000;
                        current_actor_pointer->control_state = 0x10;
                        current_actor_pointer->control_state_progress = 0;
                    }
                }
            } else {
                // Not Snapping
                D_807FDC90->unk1A &= ~0x8000;
            }
        }
    }
    func_806AD260(0x1FA, 0, 0);
    func_80724E48(current_actor_pointer->control_state == 0x23 ? 0 : 2);
    func_806319C4(current_actor_pointer, 0);
}

void func_806AD7AC(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80724CA4(2, 1);
        func_8072B79C(0x1F8, 0x1F8, 0x1F9);
    }
    func_806AD260(0x1FA, 0, 0);
    func_80724E48(current_actor_pointer->control_state == 0x23 ? 0 : 2);
    func_806319C4(current_actor_pointer, 0);
}

void func_806AD84C(void) {
    f32 temp_f0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_f0 = D_8075AE18;
        current_actor_pointer->animation_state->scale_x = temp_f0;
        current_actor_pointer->animation_state->scale_z = temp_f0;
        current_actor_pointer->animation_state->scale_y = 2.0f;
        current_actor_pointer->object_properties_bitfield |= 0x400;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if ((current_actor_pointer->unk11C == 0) || ((current_actor_pointer->unk11C->unk6A & 1))) {
                current_actor_pointer->control_state = 1;
                current_actor_pointer->object_properties_bitfield &= ~0x8000;
            } else {
                func_80671C0C(current_actor_pointer->unk11C, 2, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
                current_actor_pointer->z_rotation = current_actor_pointer->unk11C->z_rotation;
            }
            break;
        case 1:
            if (current_actor_pointer->shadow_opacity >= 0xB) {
                current_actor_pointer->shadow_opacity -= 0xA;
            } else {
                func_806782C0(current_actor_pointer);
            }
            break;
    }
    current_actor_pointer->y_rotation = character_change_array[0].unk2C8 & 0xFFF;
    func_806319C4(current_actor_pointer, 0);
}

void func_806AD9AC(void) {
    func_80677FA8(ACTOR_SILK, 0xC0); // Spawn actor: Spider Silk String (miniboss)
    D_807FBB44->unk11C = current_actor_pointer;
    D_807FBB44->draw_distance = 2000;
}

void func_806AD9F4(void) {
    s32 tmp_t0;
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FDC98->unk46 |= 0x200;
        func_8072B79C(0x2F4, 0x2F4, 0x2F4);
        if (current_actor_pointer->y_position != current_actor_pointer->floor) {
            current_actor_pointer->control_state = 0x1E;
            func_80614EBC(current_actor_pointer, 0x2F8);
            func_806AD9AC();
        }
    }
    if (((D_807FBB70.unk200 == 9) || D_807FBB70.unk15) && (current_actor_pointer->control_state != 0x37)) {
        func_8072D714(D_807FBB70.unk1FC, 0x2F7);
        func_8072B324(current_actor_pointer, 0);
        current_actor_pointer->unkB8 = -200.0f;
    } else if (D_807FBB70.unk200 == 4) {
        current_actor_pointer->unk132 = 2;
        func_8072DEA8(0x2F6, 0x27, D_807FBB70.unk1FC);
        current_actor_pointer->unkB8 *= 2;
        D_807FDC90->unk2C = 0x1F4;
    }
    switch (current_actor_pointer->control_state) {
        case 30:
            func_8072AB74(0, D_807FDC94->x_position, D_807FDC94->z_position, 0x4202, 0.0f);
            if (current_actor_pointer->control_state_progress != 0) {
                func_8072DE44(0x2F4);
            }
            break;
        case 39:
            tmp_t0 = 1;
            func_8072AB74(0, D_807FDC94->x_position, D_807FDC94->z_position, 0x4300, 0.0f);
            current_actor_pointer->y_rotation += D_807FDC90->unk2C;
            if (D_807FDC90->unk2C >= 0x15) {
                D_807FDC90->unk2C -= 0x14;
            } else {
                D_807FDC90->unk2C = 0;
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            }
            if ((current_actor_pointer->control_state_progress) && (D_807FDC90->unk2C == 0)) {
                current_actor_pointer->unk132 = tmp_t0;
                func_8072DE44(0x2F4);
            }
            break;
        case 40:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_8072B324(current_actor_pointer, 0);
                    func_80614EBC(current_actor_pointer, 0x2F5);
                    current_actor_pointer->control_state_progress++;
                case 1:
                    func_8072AB74(0, D_807FDC94->x_position, D_807FDC94->z_position, 0x4200, 0.0f);
                    if (current_actor_pointer->unkB8 < 1.0f) {
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 3:
                    func_8072DE44(0x2F4);
                    break;
            }
            break;
        case 1:
            if (((rand() >> 0xF) % 1000) >= 996) {
                if ((current_actor_pointer->unk6A & 1)) {
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
        default:
            func_806AD260(0, 1, 0);
            break;
    }
    func_8072881C(0, &D_807FDC90->unk28);
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B1F60/func_806ADDD8.s")

void func_8072B7CC(s32);

/*
// TODO: Bleh, everything matches except for stack size
void func_806ADDD8(void) {
    s32 temp = 0x31A;
    // Might not need this
    u8 pad = current_actor_pointer->control_state;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FDC98->unk46 |= 0x40;
        D_807FDC98->unk28 = temp;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
        case 1:
            if (func_8072E22C(300)) {
                func_80614EBC(current_actor_pointer, 0x31A);
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 4:
            if (current_actor_pointer->animation_state->unk64 != 0x319) {
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
            } else if (func_8072E22C(100)) {
                func_80614EBC(current_actor_pointer, 0x31B);
                current_actor_pointer->control_state = 0x1E;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 30:
            if (current_actor_pointer->animation_state->unk64 == 0x31A) {
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 35:
            if ((current_actor_pointer->animation_state->unk64 == 0x31A) && (current_actor_pointer->animation_state->unk0->unk4 > 4.0f)) {
                func_8072AB74(current_actor_pointer->control_state, D_807FDC94->x_position, D_807FDC94->z_position, 0, 0.0f);
            }
            if (!func_8072E22C(300)) {
                func_80614EBC(current_actor_pointer, 0x31C);
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        default:
            func_8072B7CC(temp);
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/
