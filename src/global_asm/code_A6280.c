#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_806319C4(Actor *, s32);
void func_80613C48(Actor*,s16,f32,f32);
void func_80699070(s16 *, s16 *, f32, f32, f32, f32, f32, f32);
extern f64 D_8075A588;
extern f64 D_8075A590;
extern f64 D_8075A598;
extern f64 D_8075A5A0;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A1580.s")

extern f32 D_8075A550;
extern u8 D_807FBD70;
extern u8 D_807506C0[];

f32 func_80665AE4(s32, s32, s32, s32);
void func_80688370(Actor*, s32, f32);
void func_806883F4(Actor*, s32, s32, f32);
void func_80679200(Actor*, Actor*, s32, u8, s32, s32);

/*
// TODO: Everything matches, but the stack is too big
// Perhaps a dxz macro?
void func_806A1580(void) {
    f32 dx, dz;
    s16 sp36;
    Actor *sp30;

    sp36 = func_80688E68(current_actor_pointer);
    sp30 = func_807270C0(2, 0);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk130 = 0x46;
        current_actor_pointer->unk131 = 0x32;
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->noclip_byte = 2;
        current_actor_pointer->object_properties_bitfield |= 0x80000000;
        current_actor_pointer->unk64 |= 0x28;
        func_8068848C(current_actor_pointer, 0, 1);
    }
    dx = player_pointer->x_position - current_actor_pointer->x_position;
    dz = player_pointer->z_position - current_actor_pointer->z_position;
    if (((dx * dx) + (dz * dz)) < D_8075A550) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
    if (sp30) {
        if (sp36 == D_807506C0[sp30->unk15F]) {
            dx = current_actor_pointer->x_position - player_pointer->x_position;
            dz = current_actor_pointer->z_position - player_pointer->z_position;
            if (((dx * dx) + (dz * dz)) > 900.0f) {
                sp30->unkEC = func_80665AE4(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position) - func_80665AE4(character_change_array->look_at_at_x, character_change_array->look_at_at_z, character_change_array->look_at_eye_x, character_change_array->look_at_eye_z);
            }
            if (func_80688540(current_actor_pointer, 0) == 0) {
                func_80688370(current_actor_pointer, 0, 1.0f);
                func_8068842C(current_actor_pointer, 0, -1);
            }
        } else if (func_80688540(current_actor_pointer, 0) != 0) {
            func_80688460(current_actor_pointer, 0, 1);
            func_806883F4(current_actor_pointer, 0, 0, 0.0f);
        }
        if (D_807FBD70 == 4) {
            if (current_actor_pointer->unk132 == 4) {
                current_actor_pointer->unk132 = 8;
                playSong(0x43, 1.0f);
                func_80679200(sp30, current_actor_pointer, 0x02000000, sp36, 0, 0);
            } else {
                current_actor_pointer->unk132 *= 2;
            }
        }
        if ((player_pointer->unk6A & 1) && !player_pointer->locked_to_pad) {
            current_actor_pointer->unk132 = 1;
        }
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A18A8.s")

void func_806A1ABC(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A1AC4.s")

void func_806A1F28() {
    current_actor_pointer->object_properties_bitfield |= 0x400;
    func_806319C4(current_actor_pointer, 0);
}

void func_806A1F64() {
    if (func_8061CB50()) {
        func_80613C48(current_actor_pointer, 0x640, 0, 8.0f);
    } else {
        func_80613C48(current_actor_pointer, 0x63F, 0, 8.0f);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806A1FD0(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A1FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A2328.s")

void func_806A285C(void) {
    s16 spBE;
    s16 spBC;
    f32 sp7C[4][4];
    f32 sp3C[4][4];

    func_80699070(&spBE, &spBC, character_change_array[0].look_at_eye_x, character_change_array[0].look_at_eye_y, character_change_array[0].look_at_eye_z, character_change_array[0].look_at_at_x, character_change_array[0].look_at_at_y, character_change_array[0].look_at_at_z);
    current_actor_pointer->y_rotation = spBC;
    current_actor_pointer->z_rotation = spBE;
    guRotateF(&sp7C, (spBE / D_8075A588) * D_8075A590, 1.0f, 0.0f, 0.0f);
    guRotateF(&sp3C, (spBC / D_8075A598) * D_8075A5A0, 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp7C, &sp3C, &sp7C);
    guTranslateF(&sp3C, character_change_array[0].look_at_eye_x, character_change_array[0].look_at_eye_y, character_change_array[0].look_at_eye_z);
    guMtxCatF(&sp7C, &sp3C, &sp7C);
    guMtxXFMF(&sp7C, 0.0f, 0.0f, -11.0f, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    guTranslateF(&current_actor_pointer->unkC, 0.0f, -20.0f, 0.0f);
    func_806319C4(current_actor_pointer, 1);
}
