#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_80750340;
extern f32 D_8075B5C0;
extern f64 D_8075B708;
extern f64 D_8075B710;

extern s32 D_8076A064;

extern u8 D_807FBD70;

void func_80614D00(Actor*, f32, f32);
void func_8069084C(u8, s32, f32, s16, f32, f32, Actor*);
void func_806907F0(f32, f32, f32);
void func_80690A28(u8, s32, f32, f32, f32, f32, f32, Actor*);
s32 func_80726164(Actor*, s16, s16, s16, void*);
void func_806B3E7C();
void func_8068588C(Actor *, s32, f32, f32, f32, f32, s32);
void func_80714998(s32);
void func_807149C8(u8, u8, u8, u8);
void func_806653C0(Actor*, f32, f32);
void func_80665564(Actor*, f32);
void func_806086CC(f32, f32, f32, s32, s32, s32, s32, s32, f32, s32);
void func_807248B0(Actor*, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B2790.s")

void func_806B2D5C(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B2D64.s")

void func_806B3420(void) {
    f32 dx, dy, dz;
    s32 temp;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk64 |= 0x24;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        D_807FDC90[0].unk2C = 0x5A;
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        func_8067ACB4(current_actor_pointer);
        func_8066EA90(current_actor_pointer, 1);
    }
    dx = current_actor_pointer->x_position - D_807FDC94->x_position;
    dy = current_actor_pointer->y_position - D_807FDC94->y_position;
    dz = current_actor_pointer->z_position - D_807FDC94->z_position;
    if (D_8075B5C0 < ((dx * dx) + (dy * dy) + (dz * dz))) {
        current_actor_pointer->object_properties_bitfield |= 0x80000000;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x80000000;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_807FDC90[0].unk2C) {
                D_807FDC90[0].unk2C--;
            } else {
                func_80614EBC(current_actor_pointer, 0x35D);
                func_80614D00(current_actor_pointer, 0.5f, 0.0f);
                current_actor_pointer->control_state = 1;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 1:
            if (current_actor_pointer->control_state_progress) {
                current_actor_pointer->control_state = 2;
                current_actor_pointer->control_state_progress = 0;
                D_807FDC90[0].unk2C = 0x5A;
            }
            break;
        case 2:
            temp = 2;
            if (D_807FDC90[0].unk2C) {
                D_807FDC90[0].unk2C--;
            } else {
                current_actor_pointer->unk132 = temp;
                func_80614D00(current_actor_pointer, 0.5f, 0.0f);
                current_actor_pointer->control_state = 3;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 3:
            temp = 1;
            if (current_actor_pointer->control_state_progress) {
                current_actor_pointer->unk132 = temp;
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                D_807FDC90[0].unk2C = 0x5A;
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B3680.s")

void func_806B3C30(u8 arg0) {
    func_80690814(current_actor_pointer, arg0);
    func_8069084C(0x32, 1, 0.3f, current_actor_pointer->unkEE, 80.0f, 0.0f, current_actor_pointer);
}

void func_806B3C94(void) {
    func_806907F0(current_actor_pointer->x_position, current_actor_pointer->y_position - 5.0f, current_actor_pointer->z_position);
    func_80690A28(0x51, 1, 0.3f, D_807FDC94->x_position, D_807FDC94->y_position, D_807FDC94->z_position, 80.0f, current_actor_pointer);
}

void func_806B3D18(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (func_8072E0A8(0x96, 0x96)) {
                func_80614EBC(current_actor_pointer, 0x253);
                current_actor_pointer->control_state_progress = 1;
            }
            break;
        case 2:
            func_806B3C30(2);
            current_actor_pointer->control_state_progress = 3;
            break;
    }
}

void func_806B3DA4(void) {
    if (D_807FDC90[0].unk2C) {
        D_807FDC90[0].unk2C--;
        return;
    }
    if (func_8072E0A8(0x96, 0x96)) {
        func_806B3C30(1);
        D_807FDC90[0].unk2C = D_80750340;
    }
}

void func_806B3E08(void) {
    if (D_807FDC90[0].unk2C) {
        D_807FDC90[0].unk2C--;
        if ((object_timer & 1)) {
            func_806B3C94();
        }
    } else if (func_8072E0A8(0x96, 0x96)) {
        D_807FDC90->unk2C = 0x14;
    }
}

void func_806B3E7C(void) {
    if (D_807FDC90->unk2C != 0) {
        D_807FDC90->unk2C--;
        return;
    }
    if ((func_80726164(current_actor_pointer, D_807FDC94->x_position, D_807FDC94->y_position, D_807FDC94->z_position, D_807FDCA0)) && (func_8072E0A8(0x96, 0x96))) {
        current_actor_pointer->control_state = 0x26;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_806B3F3C(void) {
    if (((rand() >> 0xF) % 1000) >= 996) {
        current_actor_pointer->control_state = 0x1C;
        current_actor_pointer->control_state_progress = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B3F90.s")

f32 func_80665E94(f32, f32, f32, f32, f32, f32, s32);
s16 func_806CC190(s16, s16, f32);
s32 func_8072AB74(u8, f32, f32, s32, f32);
extern f64 D_8075B5E0;
extern f64 D_8075B5E8;

typedef struct GlobalASMStruct91 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA; // Used, X?
    s16 unkC; // Used, Y?
    s16 unkE; // Used, Z?
} GlobalASMStruct91;

/*
// TODO: Very doable, float regalloc, I might have got the MIN/MAX macros mixed up?
void func_806B3F90(GlobalASMStruct91 *arg0, u8 arg1) {
    f32 dz;
    f32 dx;
    f32 var_f16;
    f32 var_f18;
    f64 temp_f16;

    dz = arg0->unkE - current_actor_pointer->z_position;
    dx = arg0->unkA - current_actor_pointer->x_position;
    temp_f16 = sqrtf((dz * dz) + (dx * dx));
    if ((temp_f16 / MAX(current_actor_pointer->unkB8, D_8075B5E0)) < D_8075B5E0) {
        var_f18 = D_8075B5E0;
    } else {
        var_f18 = temp_f16 / MIN(current_actor_pointer->unkB8, D_8075B5E0);
    }
    current_actor_pointer->y_velocity = 0.0f;
    if (current_actor_pointer->y_position < arg0->unkC) {
        var_f16 = 0.0f;
    } else {
        var_f16 = current_actor_pointer->y_position - arg0->unkC;
    }
    current_actor_pointer->y_acceleration = -(var_f16 / var_f18);
    current_actor_pointer->z_rotation = func_806CC190(current_actor_pointer->z_rotation, (func_80665E94(arg0->unkA, arg0->unkC, arg0->unkE, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x46) * 2048.0) / D_8075B5E8, 3.3f);
    func_8072AB74(arg1, arg0->unkA, arg0->unkE, 0x2E0, 0.0f);
}
*/

void func_806B4194(void) {
    u8 temp;
    u8 sp2E;
    f32 sp28;
    u32 phi_v0;

    switch (current_actor_pointer->health) {
        case 2:
            sp2E = 200;
            sp28 = 0.5f;
            phi_v0 = 0x20;
            break;
        case 1:
            sp2E = 100;
            sp28 = 1.0f;
            phi_v0 = 0x18;
            break;
        case 0:
            sp2E = 50;
            sp28 = 1.5f;
            phi_v0 = 8;
            break;
        default:
            phi_v0 = 0;
    }
    if (phi_v0 && ((D_8076A064 % phi_v0) == 0)) {
        func_80714998(3);
        func_807149C8(sp2E, sp2E, sp2E, current_actor_pointer->shadow_opacity);
        func_8068588C(current_actor_pointer, 1, sp28, 0.0f, 0.0f, 0.0f, -0x50);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B42A8.s")

void func_806B486C() {
    func_80729B00();
    func_806B42A8(&func_806B3E7C, 0x251, 0x250, 0x10E);
    func_8072881C(0, &D_807FDC90[0].unk28);
}

void func_806B48B8() {
    func_80729B00();
    func_806B42A8(&func_806B3DA4, 0x251, 0x250, 0x10E);
    func_8072881C(0, &D_807FDC90[0].unk28);
}

void func_806B4904() {
    func_80729B00();
    func_806B42A8(&func_806B3D18, 0x254, 0x252, 0x108);
    func_806B4194();
    func_8072881C(0, &D_807FDC90[0].unk28);
}

void func_806B4958() {
    func_80729B00();
    func_806B42A8(&func_806B3E7C, 0x251, 0x250, 0x10E);
    if (current_actor_pointer->control_state != 0x37) {
        func_806B3E08();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B49B0.s")

void func_806B4DCC(void) {
    s32 tmp;
    s32 tmp2;
    Actor178 *sp3C;

    sp3C = current_actor_pointer->unk178;
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
        D_807FDC98->unk46 |= 0x40;
        current_actor_pointer->unk16A = 0xFA;
        current_actor_pointer->unk16B = 0xFA;
        current_actor_pointer->unk16C = 0xFA;
        func_8069E490(0x2D, 0x44);
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x2C1, 0xFF, 0x7F, 0, 0x14, 0.0f, 0);
    }
    sp3C->unk0 = MAX(0, D_807FDC90[0].unkC - D_807FDC9C[0].unk6);
    if (D_807FBD70 == 9) {
        if (current_actor_pointer->control_state != 0x37) {
            current_actor_pointer->control_state = 0x37;
            current_actor_pointer->control_state_progress = 0;
            func_80614EBC(current_actor_pointer, 0x248);
            func_8069E5B8();
            playSong(0x14, 1.0f);
            func_8063DA40(0x7F, 0xA);
        }
    }
    if ((current_actor_pointer->control_state != 0x37) && (current_actor_pointer->control_state != 0x40)) {
        func_8069E4E0(-0x1E);
    }
    func_807248B0(current_actor_pointer, ((D_807FDC90[0].unk30 - current_actor_pointer->animation_state->scale_x) * D_8075B708) + current_actor_pointer->animation_state->scale_x);
    if (D_807FDC90[0].unk2C != 0) {
        D_807FDC90[0].unk2C--;
        if ((object_timer & 4) != 0) {
            current_actor_pointer->object_properties_bitfield |= 0x800000;
        } else {
            current_actor_pointer->object_properties_bitfield &= ~0x800000;
        }
    } else {
        current_actor_pointer->unk132 = 1;
        current_actor_pointer->object_properties_bitfield &= ~0x800000;
        if (D_807FBD70 == 4) {
            current_actor_pointer->unk132 = 2;
            D_807FDC90[0].unk2C = 0x1E;
            D_807FDC90[0].unk30 *= D_8075B710;
            func_8072D9D4();
            playCutscene(current_actor_pointer, 3, 5);
            if ((current_actor_pointer->health & 1) != 0) {
                func_80614EBC(current_actor_pointer, 0x24A);
            } else {
                func_80614EBC(current_actor_pointer, 0x249);
            }
        }
    }
    func_806B49B0(current_actor_pointer->control_state, 0x247, 0x246);
    func_8072881C(0, &D_807FDC90->unk28);
    func_806319C4(current_actor_pointer, 0);
}

void func_806B50F4() {
    func_80729B00();
    func_806B49B0(current_actor_pointer->control_state, 0x23D, 0x23E);
    func_806319C4(current_actor_pointer, 0);
}

void func_806B513C(void) {
    s32 temp_t3;
    void *phi_a0;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_8072B79C(0x30C, 0x30B, 0x30D);
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
    }
    if (current_map == MAP_CASTLE_CHUNKY_TOOLSHED) {
        temp_t3 = extra_player_info_pointer->unk1F0 & 0x40;
        if ((temp_t3 != 0) && (current_actor_pointer->shadow_opacity == 0)) {
            D_807FDC90->unk2C = 0xA;
            current_actor_pointer->noclip_byte = 0x24;
        } else if ((temp_t3 == 0) && (current_actor_pointer->shadow_opacity == 0xFF)) {
            D_807FDC90->unk2C = -0xA;
            current_actor_pointer->noclip_byte = 1;
        }
        if (D_807FDC90->unk2C != 0) {
            current_actor_pointer->shadow_opacity += D_807FDC90->unk2C;
            if (current_actor_pointer->shadow_opacity >= 0x100) {
                current_actor_pointer->shadow_opacity = 0xFF;
                D_807FDC90->unk2C = 0;
            } else if (current_actor_pointer->shadow_opacity < 0) {
                current_actor_pointer->shadow_opacity = 0;
                D_807FDC90->unk2C = 0;
            }
        }
    }
    if ((object_timer & 1)) {
        phi_a0 = &func_806B3E7C;
    } else {
        phi_a0 = &func_806B3F3C;
    }
    func_806B42A8(phi_a0, 0x30E, 0x30B, 0);
}

void func_806B52DC(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FDC98->unk46 |= 0x60;
        D_807FDC98->unk46 &= ~0x08;
        current_actor_pointer->unkB8 = ((rand() >> 0xF) % 100) + 0x12C;
        current_actor_pointer->y_position += (rand() >> 0xF) % 30;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->unkEC = ((rand() >> 0xF) % 7) + 0xF;
    }
    func_8067ACB4(current_actor_pointer);
    func_806653C0(current_actor_pointer, current_actor_pointer->unkB8, 0);
    func_80665564(current_actor_pointer, 0);
    switch (current_actor_pointer->control_state) {
        case 0x6:
            current_actor_pointer->shadow_opacity += current_actor_pointer->unkEC;
            if (current_actor_pointer->shadow_opacity >= 0xFF) {
                current_actor_pointer->shadow_opacity = 0xFF;
                current_actor_pointer->control_state = 0x37;
            }
            break;
        case 0x37:
            current_actor_pointer->shadow_opacity -= current_actor_pointer->unkEC;
            if (current_actor_pointer->shadow_opacity < 0) {
                current_actor_pointer->control_state = 0x3C;
                current_actor_pointer->shadow_opacity = 0;
            }
            break;
        default:
            func_8072B7CC(0x333);
            break;
    }
    func_8072881C(0, &D_807FDC90->unk28);
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_806B54BC.s")
