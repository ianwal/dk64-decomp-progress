#include <ultra64.h>
#include "functions.h"


extern f32 D_8075AE20;
extern f64 D_8075AE28;
extern s32 D_8071FBC8;

void func_806086CC(f32, f32, f32, s32, s32, s32, s32, s32, f32, s32);
void func_80665564(Actor*, f32);
void func_8065D254(Actor*, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_80612BC0(f32*, f32);

void func_806ADFE0(void) {
    f32 sp88[4][4];
    f32 sp48[4][4];

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkB8 = ((rand() >> 0xF) % 50) + 0x46;
        current_actor_pointer->y_velocity = current_actor_pointer->unkB8 * 2;
        current_actor_pointer->y_acceleration = -30.0f;
        current_actor_pointer->terminal_velocity = -220.0f;
        current_actor_pointer->unk168 = ((rand() >> 0xF) % 400) + 0xC8;
    }
    current_actor_pointer->y_rotation += current_actor_pointer->unk168;
    if (current_actor_pointer->unk168 > 0) {
        current_actor_pointer->unk168 = current_actor_pointer->unk168 - 0xA;
    }
    func_80666280(1);
    func_80729E6C();
    func_8067ACB4(current_actor_pointer);
    func_806651FC(current_actor_pointer);
    func_80665564(current_actor_pointer, 0.0f);
    func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0xC8, 0x80, 0, 1.0f);
    if (current_actor_pointer->unk15F != 0) {
        func_806319C4(current_actor_pointer, 0);
    } else {
        guTranslateF(&sp88[0], 0.0f, -30.0f, 0.0f);
        func_80612BC0(&sp48[0], 180.0f);
        guMtxCatF(&sp88[0], &sp48[0], &sp88[0]);
        guTranslateF(&sp48[0], 0.0f, 30.0f, 0.0f);
        guMtxCatF(&sp88[0], &sp48[0], &current_actor_pointer->unkC);
        func_806319C4(current_actor_pointer, 1);
    }
    if (((current_actor_pointer->unk6A & 1) != 0) && !(current_actor_pointer->unk6C & 1)) {
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x56, 0xB4, 0x96, 1, 0x4B, D_8075AE20, 0);
        current_actor_pointer->unkB8 *= D_8075AE28;
        current_actor_pointer->y_velocity = current_actor_pointer->unkB8 * 3.0f;
        return;
    }
    if (((current_actor_pointer->unk6A & 1) != 0) && (current_actor_pointer->unk6C & 1)) {
        func_80714CC0(&D_8071FBC8, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        func_806782C0(current_actor_pointer);
    }
}

void func_807248B0(Actor*, f32);

void func_806AE2B0(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    if (func_80677FA8(0xED, arg0)) { // Spawn actor: Unknown 237
        func_80671C0C(current_actor_pointer, arg2, &sp2C, &sp28, &sp24);
        D_807FBB44->floor = current_actor_pointer->floor;
        D_807FBB44->y_rotation = current_actor_pointer->y_rotation + arg1;
        D_807FBB44->unkEE = D_807FBB44->y_rotation;
        D_807FBB44->unk168 = arg3;
        D_807FBB44->x_position = sp2C;
        D_807FBB44->y_position = sp28;
        D_807FBB44->z_position = sp24;
        func_807248B0(D_807FBB44, current_actor_pointer->animation_state->scale_y);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AE394.s")

extern f32 D_8075AE30;

void func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
void func_8070033C(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32);

/*
// TODO: Our stack is too big, only issue
void func_806AE394(f32 arg0, f32 arg1) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 pad;
    f32 sp50[6];
    s16 sp4E;

    func_80671C0C(current_actor_pointer, 1, &sp50[5], &sp50[4], &sp50[3]);
    func_80671C0C(current_actor_pointer, 2, &sp50[2], &sp50[1], &sp50[0]);
    sp4E = func_80665DE0(sp50[2], sp50[0], sp50[5], sp50[3]);
    func_8070033C(sp50[5], sp50[4], sp50[3], sp50[2], sp50[1], sp50[0], D_8075AE30, 0xFF, 0xFF, 0xFF);
    sp50[5] = (func_80612794(sp4E) * arg0) + current_actor_pointer->x_position;
    sp50[3] = (func_80612790(sp4E) * arg0) + current_actor_pointer->z_position;
    func_8065A708(sp50[5], current_actor_pointer->y_position, sp50[3], 0.0f, 0.0f, 0.0f, arg1, 0, 0xFF, 0xFF, 0xFF);
    if (current_actor_pointer->control_state != 0) {
        dx = D_807FDC94->x_position - sp50[5];
        dy = D_807FDC94->y_position - current_actor_pointer->y_position;
        dz = D_807FDC94->z_position - sp50[3];
        if (((dx * dx) + (dy * dy) + (dz * dz)) < (arg1 * arg1)) {
            current_actor_pointer->y_rotation = func_80665DE0(D_807FDC94->x_position, D_807FDC94->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
            func_806EB0C0(0x43, current_actor_pointer, 0);
            current_actor_pointer->control_state = 0;
            current_actor_pointer->control_state_progress = 0;
        }
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AE588.s")

void func_806AEE08(void) {
    if ((((rand() >> 0xF) % 1000) >= 981)
        && func_8072DE10(4000)
        && !(D_807FDC90->unk1A & 0x80)) {
        current_actor_pointer->control_state = 0x25;
        current_actor_pointer->control_state_progress = 0;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AEE84.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AF688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AFA60.s")

/*
extern f64 D_8075B098;

extern s32 D_8072073C; // TODO: Proper datatype
extern s32 D_8071910C; // TODO: Proper datatype

// TODO: May need .data defined? s3 s2 regalloc
void func_806AFA60(u8 arg0) {
    f32 temp_f22;
    f64 temp_f20;
    s16 i;

    temp_f20 = D_8075B098;
    for (i = 0; i < 7; i++) {
        temp_f22 = current_actor_pointer->animation_state->scale_y / temp_f20;
        func_807149B8(1);
        func_807149FC(0xA);
        func_8071498C(&D_8071910C);
        func_80714998(2);
        func_80714950(0);
        func_80714C08(&D_8072073C, temp_f22 * temp_f20, current_actor_pointer, arg0, 0);
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AFB58.s")

void func_806B02EC(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_8072B79C(0, 0x31E, 0x31F);
    }
    func_806AD260(800, 0, 0);
    func_806319C4(current_actor_pointer, 0);
}

extern f32 D_8075B1A8;

s32 func_80726164(Actor*, s16, s16, s16, void*);
void func_8072AB74(s32, f32, f32, s32, f32);

void func_806B0354(void) {
    func_80729B00();
    if (((D_807FBB70->unk200 == 9) || (D_807FBB70->unk15 != 0)) && (current_actor_pointer->control_state != 0x37)) {
        func_8072D714(D_807FBB70->unk1FC, 0x37A);
        current_actor_pointer->unk138 &= 0xFFFF7FFF;
    }
    switch (current_actor_pointer->control_state) {
        case 0x4:
            if (current_actor_pointer->animation_state->unk64 == 0x378) {
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
            } else if ((func_8072E22C(0x64) != 0) && (func_80726164(current_actor_pointer, D_807FDC94->x_position, D_807FDC94->y_position, D_807FDC94->z_position, D_807FDCA0) != 0)) {
                func_80614EBC(current_actor_pointer, 0x37B);
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
                func_806852C4(D_8075B1A8, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
            }
            break;
        case 0x23:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_8072B324(current_actor_pointer, D_807FDC9C->unkD);
                    current_actor_pointer->control_state_progress += 1;
                    // Fallthrough
                case 1:
                    if (((rand() >> 0xF) % 1000) >= 0x3E4) {
                        current_actor_pointer->control_state_progress += 1;
                        func_80614EBC(current_actor_pointer, 0x379);
                        func_8072B324(current_actor_pointer, 0);
                    } else {
                        if (current_actor_pointer->animation_state->unk64 == 0x378) {
                            func_8072AB74(0x23, D_807FDC94->x_position, D_807FDC94->z_position, 0, 0.0f);
                        } else {
                            func_8072E1A4(0xA, D_807FDC94);
                        }
                        if ((func_8072E22C(0xC8) == 0) || (func_80726164(current_actor_pointer, D_807FDC94->x_position, D_807FDC94->y_position, D_807FDC94->z_position, D_807FDCA0) == 0)) {
                            func_80614EBC(current_actor_pointer, 0x37C);
                            current_actor_pointer->control_state = 4;
                            current_actor_pointer->control_state_progress = 0;
                            func_8072B324(current_actor_pointer, 0);
                        }
                    }
                    break;
                case 2:
                    func_8072AB74(0, D_807FDC94->x_position, D_807FDC94->z_position, 0x200, 0.0f);
                    break;
            }
            break;
        case 0x37:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_8072AB74(0, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 1:
                    func_806A5C60(current_actor_pointer);
                    current_actor_pointer->control_state_progress += 1;
                    // fallthrough
                case 2:
                    func_8072DC7C(0xA);
                    break;
                case 3:
                    current_actor_pointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_8072B7CC(0x378);
            break;
    }
    func_8072881C(0, &D_807FDC90->unk28);
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806B0770.s")

extern f32 D_8075B1AC;
extern u16 D_807FBB34;

/*
// TODO: Might need .rodata for D_8075B1AC?
s32 func_806B0770(void) {
    f32 dx, dy, dz;
    Actor *temp_a0;
    s16 phi_v0;
    s32 phi_v1;
    f32 temp;

    phi_v1 = FALSE;
    phi_v0 = 0;
    if (D_807FBB34 > 0) {
        temp = D_8075B1AC;
        do {
            temp_a0 = D_807FB930[phi_v0].unk0;
            if (temp_a0->unk58 == 0x29) {
                dx = temp_a0->x_position - current_actor_pointer->x_position;
                dy = temp_a0->y_position - current_actor_pointer->y_position;
                dz = temp_a0->z_position - current_actor_pointer->z_position;
                if (((dx * dx) + (dy * dy) + (dz * dz)) < temp) {
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    phi_v1 = TRUE;
                }
            }
            phi_v0++;
        } while (!phi_v1 && phi_v0 < D_807FBB34);
    }  
    return phi_v1;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806B0848.s")
