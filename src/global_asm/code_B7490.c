#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80750340;

extern u8 D_global_asm_807FBD70;

void func_global_asm_8072A86C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4);
u8 func_global_asm_8072D13C(u8 arg0, s32 arg1);

void func_global_asm_806B2790(void) {
    u8 var_a2;
    f32 var_f0;

    initializeCharacterSpawnerActor();
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (current_actor_pointer->control_state != 0x37)) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x2E1);
        D_global_asm_807FDC98->unk46 |= 8;
    }
    func_global_asm_80685020(0x1F, 0);
    switch (current_actor_pointer->control_state) {
        case 0x27:
            var_a2 = 0;
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    playActorAnimation(current_actor_pointer, 0x2E0);
                    var_a2 = 0;
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 2:
                    var_a2 = 1;
                    current_actor_pointer->unkB8 = 150.0f;
                    current_actor_pointer->unk132 = 2;
                    break;
                case 3:
                    current_actor_pointer->unk132 = 1;
                    var_a2 = 1;
                    break;
                case 4:
                    func_global_asm_8072DE44(0x2DE);
                    var_a2 = 0;
                    break;
            }
            if (var_a2) {
                func_global_asm_8072A86C(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 100.0f, 0x2240);
            }
            break;
        case 0x1:
            current_actor_pointer->x_rotation += (800.0f * func_global_asm_80612794(D_global_asm_807FDC90->unk18 * 0xA));
            if (((rand() >> 0xF) % 1000) >= 0x3D5) {
                func_global_asm_8072AA80();
            }
            func_global_asm_8072A920(current_actor_pointer->control_state, 0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC90->unkC, D_global_asm_807FDC94->z_position, 0x1E, 3.3f, 100.0f, 0x2040);
            break;
        case 0x10:
        case 0x23:
            current_actor_pointer->x_rotation += (800.0f * func_global_asm_80612794(D_global_asm_807FDC90->unk18 * 0xF));
            var_f0 = MIN(current_actor_pointer->unkAC - current_actor_pointer->unk15E, D_global_asm_807FDC94->y_position);
            func_global_asm_8072A920(current_actor_pointer->control_state, 0, D_global_asm_807FDC94->x_position, var_f0, D_global_asm_807FDC94->z_position, 0x1E, 3.3f, 100.0f, 0x2040);
            if (D_global_asm_807FBD70 == 2) {
                current_actor_pointer->control_state = 0x27;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            var_f0 = MIN(D_global_asm_807FDC90->unkC, current_actor_pointer->unkAC - current_actor_pointer->unk15E);
            func_global_asm_8072A920(current_actor_pointer->control_state, 0, D_global_asm_807FDC90->unkA, var_f0, D_global_asm_807FDC90->unkE, 0x1E, 3.3f, 100.0f, 0x2040);
            break;
        case 0x37:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, 0, 7.0f);
                    break;
                case 1:
                    func_global_asm_8072DC7C(0x14);
                    break;
                case 2:
                    current_actor_pointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x2DE);
            break;
    }
    switch (current_actor_pointer->control_state) {
        case 0x31:
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(current_actor_pointer->control_state, 1);
            // fallthrough
        default:
            func_global_asm_8072C918(0x6400, 0x2DE, 0x2DE);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806B2D5C(void) {

}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_global_asm_806B2D64.s")

void func_global_asm_806B3420(void) {
    f32 dx, dy, dz;
    s32 temp;

    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk64 |= 0x24;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        D_global_asm_807FDC90->unk2C = 0x5A;
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_8067ACB4(current_actor_pointer);
        func_global_asm_8066EA90(current_actor_pointer, 1);
    }
    dx = current_actor_pointer->x_position - D_global_asm_807FDC94->x_position;
    dy = current_actor_pointer->y_position - D_global_asm_807FDC94->y_position;
    dz = current_actor_pointer->z_position - D_global_asm_807FDC94->z_position;
    if (90000.0f < ((dx * dx) + (dy * dy) + (dz * dz))) {
        current_actor_pointer->object_properties_bitfield |= 0x80000000;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x80000000;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                playActorAnimation(current_actor_pointer, 0x35D);
                func_global_asm_80614D00(current_actor_pointer, 0.5f, 0.0f);
                current_actor_pointer->control_state = 1;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 1:
            if (current_actor_pointer->control_state_progress) {
                current_actor_pointer->control_state = 2;
                current_actor_pointer->control_state_progress = 0;
                D_global_asm_807FDC90->unk2C = 0x5A;
            }
            break;
        case 2:
            temp = 2;
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                current_actor_pointer->unk132 = temp;
                func_global_asm_80614D00(current_actor_pointer, 0.5f, 0.0f);
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
                D_global_asm_807FDC90->unk2C = 0x5A;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// close, switch case woes
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_global_asm_806B3680.s")

s32 func_global_asm_8072AB74(u8, f32, f32, s32, f32);

extern s32 D_global_asm_8072073C;
extern s32 D_global_asm_8071ABDC;

void func_global_asm_8066E9EC(Actor*, s32, f32);

/*
void func_global_asm_806B3680(void) {
    f32 var_f12;
    f32 dx;
    f32 dz;
    f32 scale;
    f32 sp54;
    f32 dy;
    s32 *sp44;
    s16 i;

    scale = current_actor_pointer->animation_state->scale_y * 800.0f;
    sp54 = 1.1f;
    if (current_map == MAP_CASTLE_KING_KUT_OUT) {
        if (!(player_pointer->unk6A & 4)) {
            scale = 0.0f;
            sp54 = 0.4f;
        } else {
            scale = scale * 0.75;
            sp54 = 0.7f;
        }
    }
    scale = scale * scale;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk64 |= 4;
        func_global_asm_8067ACB4(current_actor_pointer);
    }
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (current_actor_pointer->control_state != 0x27)) {
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
    } else if (current_actor_pointer->control_state != 0x27) {
        dx = D_global_asm_807FDC94->x_position - current_actor_pointer->x_position;
        dy = D_global_asm_807FDC94->y_position - current_actor_pointer->y_position;
        dz = D_global_asm_807FDC94->z_position - current_actor_pointer->z_position;
        if (((dx * dx) + (dy * dy) + (dz * dz)) < scale) {
            current_actor_pointer->control_state = 0x27;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_80685020(0x1F, 0);
    switch (current_actor_pointer->control_state) {
        case 4:
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 2, 0.0f);
            if (current_actor_pointer->y_position < current_actor_pointer->unkAC) {
                current_actor_pointer->y_position = current_actor_pointer->unkAC;
                current_actor_pointer->y_velocity = current_actor_pointer->y_acceleration;
            }
            // fallthrough
        case 0:
            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
            break;
        default:
            switch (current_actor_pointer->control_state) {
                case 0:
                    playSoundAtActorPosition(current_actor_pointer, 0x1C2, 0xFF, 0x7F, 0);
                    D_global_asm_807FDC90->unk30 = 2.0 * current_actor_pointer->animation_state->scale_y;
                default:
                    current_actor_pointer->control_state_progress++;
                    break;
                case 1:
                    if (current_actor_pointer->animation_state->scale_y < D_global_asm_807FDC90->unk30) {
                        func_global_asm_807248B0(current_actor_pointer, current_actor_pointer->animation_state->scale_y * 1.01);
                    } else {
                        for (i = 0; i < 0xC; i++) {
                            func_global_asm_807149B8(1);
                            func_global_asm_807149FC(2);
                            func_global_asm_80714950(i + 0x0B020000);
                            func_global_asm_8071498C(func_global_asm_8071ABDC);
                            func_global_asm_80714998(1);
                            drawSpriteAtPosition(&D_global_asm_8072073C, 2.0 * current_actor_pointer->animation_state->scale_y, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                        }
                        playSoundAtActorPosition(current_actor_pointer, 0x3D, 0xFF, 0x7F, 0);
                        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x35C, 0xFF, 0x7F, 0, 0x32, 0.3f, 0);
                        func_global_asm_8067E278(0, 1);
                        func_global_asm_8066E9EC(current_actor_pointer, 1, current_actor_pointer->ledge_info_pointer->unkC * sp54);
                        func_global_asm_8066EB40(current_actor_pointer, current_actor_pointer->ledge_info_pointer->unkC * sp54);
                        current_actor_pointer->object_properties_bitfield &= ~4;
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 5:
                    current_actor_pointer->control_state = 0x40;
                    break;
            }
            break;
        case 2:
        case 3:
            var_f12 = MIN(D_global_asm_807FDC90->unkC, current_actor_pointer->unkAC - current_actor_pointer->unk15E);
            func_global_asm_8072A920(current_actor_pointer->control_state, 0, D_global_asm_807FDC90->unkA, var_f12, D_global_asm_807FDC90->unkE, 0x1E, 3.3f, 100.0f, 0x2040);
            break;
        case 0x27:
            func_global_asm_8072B7CC(0x32E);
            break;
    }
    switch (current_actor_pointer->control_state) {
        case 2:
        case 3:
            func_global_asm_8072D13C(current_actor_pointer->control_state, 1);
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806B3C30(u8 arg0) {
    func_global_asm_80690814(current_actor_pointer, arg0);
    func_global_asm_8069084C(0x32, 1, 0.3f, current_actor_pointer->unkEE, 80.0f, 0.0f, current_actor_pointer);
}

void func_global_asm_806B3C94(void) {
    func_global_asm_806907F0(current_actor_pointer->x_position, current_actor_pointer->y_position - 5.0f, current_actor_pointer->z_position);
    func_global_asm_80690A28(0x51, 1, 0.3f, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, 80.0f, current_actor_pointer);
}

void func_global_asm_806B3D18(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (func_global_asm_8072E0A8(0x96, 0x96)) {
                playActorAnimation(current_actor_pointer, 0x253);
                current_actor_pointer->control_state_progress = 1;
            }
            break;
        case 2:
            func_global_asm_806B3C30(2);
            current_actor_pointer->control_state_progress = 3;
            break;
    }
}

void func_global_asm_806B3DA4(void) {
    if (D_global_asm_807FDC90->unk2C) {
        D_global_asm_807FDC90->unk2C--;
        return;
    }
    if (func_global_asm_8072E0A8(0x96, 0x96)) {
        func_global_asm_806B3C30(1);
        D_global_asm_807FDC90->unk2C = D_global_asm_80750340;
    }
}

void func_global_asm_806B3E08(void) {
    if (D_global_asm_807FDC90->unk2C) {
        D_global_asm_807FDC90->unk2C--;
        if (object_timer & 1) {
            func_global_asm_806B3C94();
        }
    } else if (func_global_asm_8072E0A8(0x96, 0x96)) {
        D_global_asm_807FDC90->unk2C = 0x14;
    }
}

void func_global_asm_806B3E7C(void) {
    if (D_global_asm_807FDC90->unk2C != 0) {
        D_global_asm_807FDC90->unk2C--;
        return;
    }
    if (func_global_asm_80726164(current_actor_pointer, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0) && func_global_asm_8072E0A8(0x96, 0x96)) {
        current_actor_pointer->control_state = 0x26;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806B3F3C(void) {
    if (((rand() >> 0xF) % 1000) >= 996) {
        current_actor_pointer->control_state = 0x1C;
        current_actor_pointer->control_state_progress = 0;
    }
}

// doable regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_global_asm_806B3F90.s")

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

void func_global_asm_806B3F90(GlobalASMStruct91 *arg0, u8 arg1);

/*
// TODO: Very doable, float regalloc, I might have got the MIN/MAX macros mixed up?
void func_global_asm_806B3F90(GlobalASMStruct91 *arg0, u8 arg1) {
    f32 dz;
    f32 dx;
    f32 var_f16;
    f32 var_f18;
    f64 temp_f16;

    dz = arg0->unkE - current_actor_pointer->z_position;
    dx = arg0->unkA - current_actor_pointer->x_position;
    temp_f16 = sqrtf((dz * dz) + (dx * dx));
    if ((temp_f16 / MAX(0.0001, current_actor_pointer->unkB8)) < 0.0001) {
        var_f18 = 0.0001;
    } else {
        var_f18 = temp_f16 / MIN(current_actor_pointer->unkB8, 0.0001);
    }
    current_actor_pointer->y_velocity = 0.0f;
    if (current_actor_pointer->y_position < arg0->unkC) {
        var_f16 = 0.0f;
    } else {
        var_f16 = current_actor_pointer->y_position - arg0->unkC;
    }
    current_actor_pointer->y_acceleration = -(var_f16 / var_f18);
    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, (func_global_asm_80665E94(arg0->unkA, arg0->unkC, arg0->unkE, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x46) * 2048.0) / 3.14159274101257324, 3.3f);
    func_global_asm_8072AB74(arg1, arg0->unkA, arg0->unkE, 0x2E0, 0.0f);
}
*/

void func_global_asm_806B4194(void) {
    u8 temp;
    u8 shade;
    f32 scale;
    u32 phi_v0;

    switch (current_actor_pointer->health) {
        case 2:
            shade = 200;
            scale = 0.5f;
            phi_v0 = 32;
            break;
        case 1:
            shade = 100;
            scale = 1.0f;
            phi_v0 = 24;
            break;
        case 0:
            shade = 50;
            scale = 1.5f;
            phi_v0 = 8;
            break;
        default:
            phi_v0 = 0;
    }
    if (phi_v0 && ((object_timer % phi_v0) == 0)) {
        func_global_asm_80714998(3);
        changeActorColor(shade, shade, shade, current_actor_pointer->shadow_opacity);
        func_global_asm_8068588C(current_actor_pointer, 1, scale, 0.0f, 0.0f, 0.0f, -0x50);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B7490/func_global_asm_806B42A8.s")

void func_global_asm_806B486C(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B42A8(&func_global_asm_806B3E7C, 0x251, 0x250, 0x10E);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}

void func_global_asm_806B48B8(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B42A8(&func_global_asm_806B3DA4, 0x251, 0x250, 0x10E);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}

void func_global_asm_806B4904(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B42A8(&func_global_asm_806B3D18, 0x254, 0x252, 0x108);
    func_global_asm_806B4194();
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}

void func_global_asm_806B4958(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B42A8(&func_global_asm_806B3E7C, 0x251, 0x250, 0x10E);
    if (current_actor_pointer->control_state != 0x37) {
        func_global_asm_806B3E08();
    }
}

extern f32 D_global_asm_807502EC;

void func_global_asm_806B49B0(u8 arg0, s16 arg1, s16 arg2) {
    Actor178 *a178;
    s32 pad2;
    s32 pad;
    s16 sp32;

    a178 = current_actor_pointer->unk178;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724CA4(1, 1);
        D_global_asm_807FDC90->unk30 = current_actor_pointer->animation_state->scale_y;
        current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkC;
        a178->unk0 = D_global_asm_807FDC9C[0].unkA_u8[0];
        current_actor_pointer->y_acceleration = D_global_asm_807502EC;
    }
    sp32 = D_global_asm_807FDC9C->unk6 + a178->unk0;
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (arg0 != 0x37)) {
        current_actor_pointer->control_state = 0x37;
        current_actor_pointer->control_state_progress = 0;
    }
    switch (arg0) {
        case 0x2:
        case 0x3:
            if (current_actor_pointer->control_state_progress == 0) {
                playActorAnimation(current_actor_pointer, arg1);
                current_actor_pointer->control_state_progress++;
            }
            func_global_asm_8072AB74(arg0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0xE1, 0.0f);
            if (current_actor_pointer->y_position < sp32) {
                if (current_actor_pointer->control_state_progress == 2) {
                    current_actor_pointer->y_position += ((f32)D_global_asm_807FDC9C[0].unkA_u8[1] * 0.03125);
                } else {
                    current_actor_pointer->y_position += ((f32)D_global_asm_807FDC9C[0].unkA_u8[1] * 0.015625);
                }
            }
            current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, 0, 5.0f);
            break;
        case 0x26:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                case 1:
                case 2:
                    playActorAnimation(current_actor_pointer, arg2);
                    current_actor_pointer->control_state_progress = 3;
                    // Fallthrough
                case 3:
                    func_global_asm_806B3F90(D_global_asm_807FDC90, 0x26);
                    break;
            }
            break;
        case 0x37:
            func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x22, 0.0f);
            if (current_actor_pointer->unk6A & 1) {
                current_actor_pointer->control_state = 0x40;
            }
        case 0x40:
            break;
        default:
            func_global_asm_8072B7CC(arg1);
            break;
    }
    switch (arg0) {
        case 2:
        case 3:
            func_global_asm_8072D13C(arg0, 1);
            return;
        case 38:
            if (func_global_asm_8072D13C(arg0, 1) != 0) {
                current_actor_pointer->control_state = D_global_asm_807FDC9C->unk10;
                current_actor_pointer->control_state_progress = 0;
            }
            return;
    }
}

void func_global_asm_806B4DCC(void) {
    s32 tmp;
    s32 tmp2;
    Actor178 *sp3C;

    sp3C = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
        D_global_asm_807FDC98->unk46 |= 0x40;
        current_actor_pointer->unk16A = 0xFA;
        current_actor_pointer->unk16B = 0xFA;
        current_actor_pointer->unk16C = 0xFA;
        func_global_asm_8069E490(0x2D, 0x44);
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x2C1, 0xFF, 0x7F, 0, 0x14, 0.0f, 0);
    }
    sp3C->unk0 = MAX(0, D_global_asm_807FDC90->unkC - D_global_asm_807FDC9C->unk6);
    if (D_global_asm_807FBD70 == 9) {
        if (current_actor_pointer->control_state != 0x37) {
            current_actor_pointer->control_state = 0x37;
            current_actor_pointer->control_state_progress = 0;
            playActorAnimation(current_actor_pointer, 0x248);
            func_global_asm_8069E5B8();
            playSong(0x14, 1.0f);
            func_global_asm_8063DA40(0x7F, 0xA);
        }
    }
    if ((current_actor_pointer->control_state != 0x37) && (current_actor_pointer->control_state != 0x40)) {
        func_global_asm_8069E4E0(-0x1E);
    }
    func_global_asm_807248B0(current_actor_pointer, ((D_global_asm_807FDC90->unk30 - current_actor_pointer->animation_state->scale_x) * 0.05) + current_actor_pointer->animation_state->scale_x);
    if (D_global_asm_807FDC90->unk2C != 0) {
        D_global_asm_807FDC90->unk2C--;
        if ((object_timer & 4) != 0) {
            current_actor_pointer->object_properties_bitfield |= 0x800000;
        } else {
            current_actor_pointer->object_properties_bitfield &= ~0x800000;
        }
    } else {
        current_actor_pointer->unk132 = 1;
        current_actor_pointer->object_properties_bitfield &= ~0x800000;
        if (D_global_asm_807FBD70 == 4) {
            current_actor_pointer->unk132 = 2;
            D_global_asm_807FDC90->unk2C = 0x1E;
            D_global_asm_807FDC90->unk30 *= 0.7;
            func_global_asm_8072D9D4();
            playCutscene(current_actor_pointer, 3, 5);
            if ((current_actor_pointer->health & 1) != 0) {
                playActorAnimation(current_actor_pointer, 0x24A);
            } else {
                playActorAnimation(current_actor_pointer, 0x249);
            }
        }
    }
    func_global_asm_806B49B0(current_actor_pointer->control_state, 0x247, 0x246);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806B50F4(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B49B0(current_actor_pointer->control_state, 0x23D, 0x23E);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806B513C(void) {
    s32 temp_t3;
    void *phi_a0;

    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0x30C, 0x30B, 0x30D);
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
    }
    if (current_map == MAP_CASTLE_CHUNKY_TOOLSHED) {
        temp_t3 = extra_player_info_pointer->unk1F0 & 0x40;
        if ((temp_t3 != 0) && (current_actor_pointer->shadow_opacity == 0)) {
            D_global_asm_807FDC90->unk2C = 0xA;
            current_actor_pointer->noclip_byte = 0x24;
        } else if ((temp_t3 == 0) && (current_actor_pointer->shadow_opacity == 0xFF)) {
            D_global_asm_807FDC90->unk2C = -0xA;
            current_actor_pointer->noclip_byte = 1;
        }
        if (D_global_asm_807FDC90->unk2C != 0) {
            current_actor_pointer->shadow_opacity += D_global_asm_807FDC90->unk2C;
            if (current_actor_pointer->shadow_opacity >= 0x100) {
                current_actor_pointer->shadow_opacity = 0xFF;
                D_global_asm_807FDC90->unk2C = 0;
            } else if (current_actor_pointer->shadow_opacity < 0) {
                current_actor_pointer->shadow_opacity = 0;
                D_global_asm_807FDC90->unk2C = 0;
            }
        }
    }
    if ((object_timer & 1)) {
        phi_a0 = &func_global_asm_806B3E7C;
    } else {
        phi_a0 = &func_global_asm_806B3F3C;
    }
    func_global_asm_806B42A8(phi_a0, 0x30E, 0x30B, 0);
}

void func_global_asm_806B52DC(void) {
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0x60;
        D_global_asm_807FDC98->unk46 &= ~0x08;
        current_actor_pointer->unkB8 = ((rand() >> 0xF) % 100) + 0x12C;
        current_actor_pointer->y_position += (rand() >> 0xF) % 30;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->unkEC = ((rand() >> 0xF) % 7) + 0xF;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806653C0(current_actor_pointer, current_actor_pointer->unkB8, 0);
    func_global_asm_80665564(current_actor_pointer, 0);
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
            func_global_asm_8072B7CC(0x333);
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(current_actor_pointer, 0);
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
} Actor178_806B54BC;

void func_global_asm_806B54BC(void) {
    Actor178_806B54BC *temp_s1;
    f32 x, y, z;
    f32 temp_f4;
    s16 temp_s0_3;
    s32 temp;

    temp_s1 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    if ((current_actor_pointer->control_state != 0x40) && (current_actor_pointer->control_state != 0x37) && ((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0))) {
        func_global_asm_80605314(current_actor_pointer, 0);
        playActorAnimation(current_actor_pointer, 0x331);
        current_actor_pointer->control_state = 0x37;
        current_actor_pointer->control_state_progress = 0;
        playSoundAtActorPosition(player_pointer, 0x16, 0xFF, 0x7F, 0x1E);
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0x20;
        D_global_asm_807FDC98->unk46 &= 0xFFF7;
        current_actor_pointer->unkB8 = 40.0f;
        current_actor_pointer->control_state = 0x23;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkEC = ((rand() >> 0xF) % 7) + 0xF;
        temp_s1->unk0 = current_actor_pointer->x_position;
        temp_s1->unk4 = current_actor_pointer->y_position;
        temp_s1->unk8 = current_actor_pointer->z_position;
        temp_s1->unk10 = 1;
        temp_s1->unkC = current_actor_pointer->y_position;
        temp_s1->unk12 = (func_global_asm_806119A0() & 0xFF) + 0x78;
    }
    if ((current_actor_pointer->control_state != 0x37) && (current_actor_pointer->unk6E[0] == -1)) {
        func_global_asm_80604CBC(current_actor_pointer, 0x10E, 0, 0, 0, 0xFF, 1.0f, 0);
    }
    switch (current_actor_pointer->control_state) {
        case 0x26:
            temp_s1->unk0 = player_pointer->x_position;
            temp_s1->unk4 = player_pointer->y_position;
            temp_s1->unk8 = player_pointer->z_position;
            temp_s1->unk12 = (func_global_asm_806119A0() & 0xFF) + 0x78;
            // fallthrough
        case 0x23:
            temp = func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, temp_s1->unk0, temp_s1->unk8) + 0x800;
            current_actor_pointer->y_rotation -= func_global_asm_806CC10C(temp, current_actor_pointer->y_rotation) >> 4;
            temp_s1->unk10--;
            if (temp_s1->unk10 <= 0) {
                func_global_asm_80724B5C(1, 0, &x, &y, &z);
                temp_s1->unk10 = (func_global_asm_806119A0() & 0x3F) + 0xF;
                temp_s0_3 = func_global_asm_80665DE0(x, z, temp_s1->unk0, temp_s1->unk8);
                temp_s0_3 += ((func_global_asm_806119A0() & 7) << 8) + 0x400;
                temp_f4 = func_global_asm_806119FC() * 180.0;
                temp_s1->unk0 = func_global_asm_80612794(temp_s0_3) * temp_f4 + x;
                temp_s1->unk4 = temp_s1->unkC;
                temp_s1->unk8 = func_global_asm_80612790(temp_s0_3) * temp_f4 + z;
                current_actor_pointer->control_state = 0x23;
            }
            if (current_actor_pointer->control_state == 0x23) {
                temp_s1->unk12--;
                if (temp_s1->unk12 <= 0) {
                    temp_s1->unk10 = 0x3C;
                    current_actor_pointer->control_state = 0x26;
                }
            }
            y = (temp_s1->unk4 - current_actor_pointer->y_position) * 0.0625;
            if (y > 8.0) {
                y = 8.0f;
            }
            if (y < -8.0) {
                y = -8.0f;
            }
            current_actor_pointer->x_position += func_global_asm_80612794(current_actor_pointer->y_rotation) * 8.0;
            current_actor_pointer->y_position += y;
            current_actor_pointer->z_position += func_global_asm_80612790(current_actor_pointer->y_rotation) * 8.0;
            break;
        case 0x37:
            current_actor_pointer->object_properties_bitfield &= ~0x8000;
            current_actor_pointer->shadow_opacity -= 8;
            current_actor_pointer->y_position = current_actor_pointer->y_position - 10.0;
            if (current_actor_pointer->shadow_opacity < 0) {
                current_actor_pointer->shadow_opacity = 0;
                current_actor_pointer->control_state = 0x40;
                current_actor_pointer->control_state_progress = 0;
                current_actor_pointer->noclip_byte = 1;
                if (current_map == MAP_CASTLE_TRASH_CAN) {
                    enemies_killed++;
                    if ((enemies_killed == 5) && (isFlagSet(0x15F, FLAG_TYPE_PERMANENT) == FALSE)) {
                        func_global_asm_8063DA40(4, 0xA);
                    }
                }
            }
            break;
        default:
            func_global_asm_8072B7CC(0x32F);
            break;
    }
    renderActor(current_actor_pointer, 0);
}
