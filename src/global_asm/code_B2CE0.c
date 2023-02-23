#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806ADFE0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AF688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AFA60.s")

/*
extern f64 D_8075B098;

extern s32 D_8072073C; // TODO: Proper datatype
extern s32 D_8071910C; // TODO: Proper datatype

void func_80714C08(s32*, f32, Actor*, s32, s32);
void func_8071498C(s32*);

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806AFB58.s")

void func_806B02EC(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_8072B79C(0, 0x31E, 0x31F);
    }
    func_806AD260(800, 0, 0);
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806B0354.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_806B0848.s")
