#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_8071FBC8;
extern s32 D_global_asm_8072073C; // TODO: Proper datatype

extern f32 D_global_asm_8075B1A8;

s32 func_global_asm_80726164(Actor*, s16, s16, s16, void*);
void func_global_asm_8072AB74(s32, f32, f32, s32, f32);

void func_global_asm_80612BC0(f32*, f32);

void func_global_asm_8070033C(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32);

void func_global_asm_806ADFE0(void) {
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
    func_global_asm_80666280(1);
    func_global_asm_80729E6C();
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0xC8, 0x80, 0, 1.0f);
    if (current_actor_pointer->unk15F != 0) {
        renderActor(current_actor_pointer, 0);
    } else {
        guTranslateF(&sp88[0], 0.0f, -30.0f, 0.0f);
        func_global_asm_80612BC0(&sp48[0], 180.0f);
        guMtxCatF(&sp88[0], &sp48[0], &sp88[0]);
        guTranslateF(&sp48[0], 0.0f, 30.0f, 0.0f);
        guMtxCatF(&sp88[0], &sp48[0], &current_actor_pointer->unkC);
        renderActor(current_actor_pointer, 1);
    }
    if (((current_actor_pointer->unk6A & 1) != 0) && !(current_actor_pointer->unk6C & 1)) {
        func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x56, 0xB4, 0x96, 1, 0x4B, 0.3f, 0);
        current_actor_pointer->unkB8 *= 0.6;
        current_actor_pointer->y_velocity = current_actor_pointer->unkB8 * 3.0f;
        return;
    }
    if (((current_actor_pointer->unk6A & 1) != 0) && (current_actor_pointer->unk6C & 1)) {
        func_global_asm_80714CC0(&D_global_asm_8071FBC8, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        deleteActor(current_actor_pointer);
    }
}

void func_global_asm_806AE2B0(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    if (spawnActor(ACTOR_KROSSBONES_HEAD, arg0)) { // Spawn actor: Unknown 237
        func_global_asm_80671C0C(current_actor_pointer, arg2, &sp2C, &sp28, &sp24);
        last_spawned_actor->floor = current_actor_pointer->floor;
        last_spawned_actor->y_rotation = current_actor_pointer->y_rotation + arg1;
        last_spawned_actor->unkEE = last_spawned_actor->y_rotation;
        last_spawned_actor->unk168 = arg3;
        last_spawned_actor->x_position = sp2C;
        last_spawned_actor->y_position = sp28;
        last_spawned_actor->z_position = sp24;
        func_global_asm_807248B0(last_spawned_actor, current_actor_pointer->animation_state->scale_y);
    }
}

void func_global_asm_806AE394(f32 arg0, f32 arg1) {
    f32 x1;
    f32 y1;
    f32 z1;
    f32 x2;
    f32 y2;
    f32 z2;
    s16 sp4E;

    func_global_asm_80671C0C(current_actor_pointer, 1, &x1, &y1, &z1);
    func_global_asm_80671C0C(current_actor_pointer, 2, &x2, &y2, &z2);
    sp4E = func_global_asm_80665DE0(x2, z2, x1, z1);
    func_global_asm_8070033C(x1, y1, z1, x2, y2, z2, 0.6f, 0xFF, 0xFF, 0xFF);
    x1 = (func_global_asm_80612794(sp4E) * arg0) + current_actor_pointer->x_position;
    z1 = (func_global_asm_80612790(sp4E) * arg0) + current_actor_pointer->z_position;
    func_global_asm_8065A708(x1, current_actor_pointer->y_position, z1, 0.0f, 0.0f, 0.0f, arg1, 0, 0xFF, 0xFF, 0xFF);
    if (current_actor_pointer->control_state != 0) {
        if ((((D_global_asm_807FDC94->x_position - x1) * (D_global_asm_807FDC94->x_position - x1)) + ((D_global_asm_807FDC94->y_position - current_actor_pointer->y_position) * (D_global_asm_807FDC94->y_position - current_actor_pointer->y_position)) + ((D_global_asm_807FDC94->z_position - z1) * (D_global_asm_807FDC94->z_position - z1))) < (arg1 * arg1)) {
            current_actor_pointer->y_rotation = func_global_asm_80665DE0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
            func_global_asm_806EB0C0(0x43, current_actor_pointer, 0);
            current_actor_pointer->control_state = 0;
            current_actor_pointer->control_state_progress = 0;
        }
    }
}

// Jumptable, very close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AE588.s")

void func_global_asm_8072C918(s16, s16, s16);

/*
void func_global_asm_806AE588(void) {
    s32 var_v1;
    s32 var_v1_2;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 var_a0;
    u8 var_a1;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0x1FD, 0x1FB, 0x1FC);
        func_global_asm_80724CA4(3, 1);
        func_global_asm_8066EA90(current_actor_pointer, 3);
        if (current_map == MAP_KROOL_BARREL_DIDDY_KREMLING_GAME) {
            current_actor_pointer->unk132 = 1;
        }
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    if (current_actor_pointer->control_state != 0x32 || D_global_asm_807FBB70.unk15 != 0) {
        if (D_global_asm_807FBB70.unk200 != 9 && D_global_asm_807FBB70.unk15 == 0) {
            if (current_actor_pointer->control_state != 0x37) {
                if (current_actor_pointer->health < -1) {
                    func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x202);
                    current_actor_pointer->y_velocity = 250.0f;
                } else {
                    func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x201);
                    current_actor_pointer->y_velocity = 200.0f;
                }
                D_global_asm_807FDC90->unk35 = 2;
                current_actor_pointer->unk138 &= 0xFFFF7FFF;
            } else if (D_global_asm_807FBB70.unk200 == 4) {
                func_global_asm_8072DEA8(0x1FF, 0x31, D_global_asm_807FBB70.unk1FC);
            } else if (D_global_asm_807FBB70.unk200 == 5) {
                func_global_asm_8072DEA8(0x200, 0x32, D_global_asm_807FBB70.unk1FC);
                current_actor_pointer->y_velocity = 220.0f;
            }
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0x31:
            if (current_actor_pointer->control_state_progress != 0 || current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
                func_global_asm_8072DE44(0x1FB);
            }
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4300, 0.0f);
            break;
        case 0x32:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 7.0f);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4300, 0.0f);
                    break;
                case 1:
                    current_actor_pointer->y_velocity = 200.0f;
                    current_actor_pointer->unkB8 = 120.0f;
                    current_actor_pointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 3:
                    func_global_asm_8072DE44(0x1FB);
                    break;
            }
            break;
        case 0x11:
            func_global_asm_80724E48(5);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(current_actor_pointer, 0);
                    func_global_asm_80614EBC(current_actor_pointer, 0x1FD);
                    current_actor_pointer->control_state_progress++;
                    // fallthrough
                case 1:
                    func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    current_actor_pointer = current_actor_pointer;
                    if (current_actor_pointer->unkB8 < 1.0f) {
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 2:
                    func_global_asm_8072A450(current_actor_pointer);
                    if (((rand() >> 0xF) % 1000) >= 0x3E4) {
                        func_global_asm_8072DE44(0x1FB);
                    }
                    break;
            }
            break;
        case 0x27:
            func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            switch (current_actor_pointer->control_state_progress) {                    // switch 3; irregular
                case 0:                             // switch 3
                    func_global_asm_8072B324(current_actor_pointer, 0);
                    func_global_asm_80614EBC(current_actor_pointer, 0x1FE);
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 2:                             // switch 3
                    current_actor_pointer->unk132 = 2;
                    break;
                case 3:                             // switch 3
                    current_actor_pointer->unk132 = 1;
                    break;
                case 4:                             // switch 3
                    func_global_asm_8072DE44(0x1FB);
                    break;
            }
            break;
        case 0x1:
            if (func_global_asm_8072E54C() != 0) {
                current_actor_pointer->control_state = 0x11;
                current_actor_pointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x23:
            if (D_global_asm_807FBB70.unk200 == 2) {
                if (func_global_asm_8072DE10(10000) != 0) {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            // fallthrough
        case 0x10:
            func_global_asm_80724E48(current_actor_pointer->control_state == 1 ? 2 : 0);
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_80724E48(current_actor_pointer->control_state == 0x35 ? 2 : 3);
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            break;
        case 0x37:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x40E00000);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 1:
                    if (current_map == MAP_KROOL_BARREL_DIDDY_KREMLING_GAME) {
                        if (current_actor_pointer->unk15F != 0) {
                            func_global_asm_8063DA40(0, 0xA);
                        }
                    }
                    func_global_asm_806A5C60(current_actor_pointer);
                    current_actor_pointer->control_state_progress += 1;
                    // fallthrough
                case 2:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x200, 0.0f);
                    func_global_asm_8072DC7C(8);
                    break;
                case 3:
                    current_actor_pointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x1FB);
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
            func_global_asm_8072C918(0x6400, 0x1FB, 0x1FC);
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806AEE08(void) {
    if ((((rand() >> 0xF) % 1000) >= 981)
        && func_global_asm_8072DE10(4000)
        && !(D_global_asm_807FDC90->unk1A & 0x80)) {
        current_actor_pointer->control_state = 0x25;
        current_actor_pointer->control_state_progress = 0;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AEE84.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AF688.s")

int func_global_asm_8071910C(); // TODO: Signature

void func_global_asm_806AFA60(u8 arg0) {
    f32 temp_f22;
    f64 temp_f20;
    s16 i;

    for (i = 0; i < 7; i++) {
        temp_f22 = current_actor_pointer->animation_state->scale_y / 0.15;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(&func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(0);
        func_global_asm_80714C08(&D_global_asm_8072073C, temp_f22 * 0.15, current_actor_pointer, arg0, 0);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AFB58.s")

void func_global_asm_806B02EC(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0, 0x31E, 0x31F);
    }
    func_global_asm_806AD260(800, 0, 0);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806B0354(void) {
    func_global_asm_80729B00();
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (current_actor_pointer->control_state != 0x37)) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x37A);
        current_actor_pointer->unk138 &= 0xFFFF7FFF;
    }
    switch (current_actor_pointer->control_state) {
        case 0x4:
            if (current_actor_pointer->animation_state->unk64 == 0x378) {
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
            } else if ((func_global_asm_8072E22C(0x64) != 0) && (func_global_asm_80726164(current_actor_pointer, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0) != 0)) {
                func_global_asm_80614EBC(current_actor_pointer, 0x37B);
                current_actor_pointer->control_state = 0x23;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_806852C4(0.7f, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
            }
            break;
        case 0x23:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkD);
                    current_actor_pointer->control_state_progress += 1;
                    // Fallthrough
                case 1:
                    if (((rand() >> 0xF) % 1000) >= 0x3E4) {
                        current_actor_pointer->control_state_progress += 1;
                        func_global_asm_80614EBC(current_actor_pointer, 0x379);
                        func_global_asm_8072B324(current_actor_pointer, 0);
                    } else {
                        if (current_actor_pointer->animation_state->unk64 == 0x378) {
                            func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
                        } else {
                            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
                        }
                        if ((func_global_asm_8072E22C(0xC8) == 0) || (func_global_asm_80726164(current_actor_pointer, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0) == 0)) {
                            func_global_asm_80614EBC(current_actor_pointer, 0x37C);
                            current_actor_pointer->control_state = 4;
                            current_actor_pointer->control_state_progress = 0;
                            func_global_asm_8072B324(current_actor_pointer, 0);
                        }
                    }
                    break;
                case 2:
                    func_global_asm_8072AB74(0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    break;
            }
            break;
        case 0x37:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 1:
                    func_global_asm_806A5C60(current_actor_pointer);
                    current_actor_pointer->control_state_progress += 1;
                    // fallthrough
                case 2:
                    func_global_asm_8072DC7C(0xA);
                    break;
                case 3:
                    current_actor_pointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x378);
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(current_actor_pointer, 0);
}

s32 func_global_asm_806B0770(void) {
    f32 dx, dy, dz;
    Actor *temp_a0;
    s16 i;
    s32 found;
    
    found = FALSE;

    for (i = 0; !found && i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (temp_a0->unk58 == ACTOR_PROJECTILE_ORANGE) {
            dx = temp_a0->x_position - current_actor_pointer->x_position;
            dy = temp_a0->y_position - current_actor_pointer->y_position;
            dz = temp_a0->z_position - current_actor_pointer->z_position;
            if (((dx * dx) + (dy * dy) + (dz * dz)) < 10000.0f) {
                current_actor_pointer->control_state = 0x28;
                current_actor_pointer->control_state_progress = 0;
                found = TRUE;
            }
        }
    }  
    return found;
}

// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806B0848.s")

/*
void func_global_asm_806B0848(void) {
    s32 var_a1;
    Actor *temp_s0;
    Actor *var_s0;
    f64 temp_f0;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_a1_3;
    u8 temp_v1;
    u8 var_a0;
    u8 var_v0;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_f0 = (current_actor_pointer->animation_state->scale[1] / 0.15) * 100.0;
        if (temp_f0 > 255.0) {
            current_actor_pointer->unk130 = 255.0;
        } else {
            current_actor_pointer->unk130 = temp_f0;
        }
        temp_f0 = (current_actor_pointer->animation_state->scale[1] / 0.15) * 100.0;
        if (temp_f0 > 255.0) {
            current_actor_pointer->unk131 = 255.0;
        } else {
            current_actor_pointer->unk131 = temp_f0;
        }
        //func_global_asm_8072B79C(0.15, 0, 0x35E, 0x35F, 0x360);
        func_global_asm_8072B79C(0x35E, 0x35F, 0x360);
    }
    if (D_global_asm_807FBB70.unk200 != 9) {
        if (D_global_asm_807FBB70.unk15 != 0) {
            goto block_10;
        }
        goto block_12;
    }
block_10:
    if (current_actor_pointer->control_state != 0x37) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x367);
        current_actor_pointer->unk138 &= 0xFFFF7FFF;
    } else {
block_12:
        if (D_global_asm_807FBB70.unk200 == 4) {
            func_global_asm_8072DEA8(0x365, 0x31, D_global_asm_807FBB70.unk1FC);
        } else if (D_global_asm_807FBB70.unk200 == 5) {
            func_global_asm_8072DEA8(0x366, 0x31, D_global_asm_807FBB70.unk1FC);
        }
    }
    var_a0 = current_actor_pointer->control_state;
    var_v0 = var_a0;
    if (var_a0 == 4) {
        current_actor_pointer->control_state = 1;
        var_a0 = current_actor_pointer->control_state;
        var_v0 = var_a0;
    }
    switch (var_v0) {
        case 0x37:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x40E00000);
            var_s0 = current_actor_pointer;
            temp_a1 = var_s0->control_state_progress;
            switch (temp_a1) {                      // switch 1; irregular
                case 0:                             // switch 1
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x202, 0.0f);
block_80:
                    var_s0 = current_actor_pointer;
                    break;
                case 1:                             // switch 1
                    func_global_asm_806A5C60(var_s0, temp_a1);
                    current_actor_pointer->control_state_progress += 1;
                    // fallthrough
                case 2:                             // switch 1
                    func_global_asm_8072DC7C(8);
                    goto block_80;
                case 3:                             // switch 1
                    var_s0->control_state = 0x40;
                    goto block_80;
            }
            break;
        case 0x31:
            if (current_actor_pointer->unk0 == 0) {
                // if (current_actor_pointer->unk0->unk24 == 0.0f) {
                    // goto block_31;
                // }
            } else {
block_31:
                func_global_asm_8072DE44(0x35F);
            }
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4200, 0.0f);
            goto block_80;
        case 0x27:
            func_global_asm_8072AB74(var_a0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            var_s0 = current_actor_pointer;
            temp_a1_2 = var_s0->control_state_progress;
            switch (temp_a1_2) {                    // switch 2; irregular
                case 0:                             // switch 2
                    func_global_asm_8072B324(var_s0, 0);
                    var_a1 = 0x361;
                    if (object_timer & 1) {
                        var_a1 = 0x362;
                    }
                    func_global_asm_80614EBC(current_actor_pointer, var_a1);
                    current_actor_pointer->control_state_progress = 1;
                    goto block_80;
                case 2:                             // switch 2
                    if (var_s0->animation_state->unk64 != 0x362) {
                        var_s0->unk132 = 2;
                    } else {
                        var_s0->unk132 = 4;
                    }
                    goto block_80;
                case 3:                             // switch 2
                    if (var_s0->animation_state->unk64 != 0x362) {
                        var_s0->unk132 = 1;
                    } else {
                        var_s0->unk132 = 8;
                    }
                    goto block_80;
                case 4:                             // switch 2
                    var_s0->unk132 = 1;
                    func_global_asm_8072DE44(0x35F);
                    goto block_80;
            }
            break;
        case 0x28:
            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            var_s0 = current_actor_pointer;
            temp_v1 = var_s0->control_state_progress;
            switch (temp_v1) {                      // switch 3; irregular
                case 0:                             // switch 3
                    func_global_asm_8072B324(var_s0, 0);
                    func_global_asm_80614EBC(current_actor_pointer, 0x363);
                    current_actor_pointer->control_state_progress = 1;
                    goto block_80;
                case 2:                             // switch 3
                    var_s0->control_state_progress = temp_v1 + 1;
                    goto block_80;
                case 4:                             // switch 3
                    D_global_asm_807FDC90->unk4 = player_pointer;
                    func_global_asm_8072DE44(0x35F);
                    goto block_80;
            }
            break;
        case 0x11:
            if (func_global_asm_806B0770() == 0) {
                temp_s0 = current_actor_pointer;
                temp_a1_3 = temp_s0->control_state_progress;
                switch (temp_a1_3) {                // switch 4; irregular
                    case 0:                         // switch 4
                        func_global_asm_8072B324(temp_s0, 0);
                        func_global_asm_80614EBC(current_actor_pointer, 0x35E);
                        current_actor_pointer->control_state_progress += 1;
                        // fallthrough
                    case 1:                         // switch 4
                        func_global_asm_8072AB74(temp_s0->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                        if (current_actor_pointer->unkB8 < 1.0f) {
                            current_actor_pointer->control_state_progress += 1;
                        }
                        break;
                    case 2:                         // switch 4
                        func_global_asm_8072A450(temp_s0, temp_a1_3);
                        if (((rand() >> 0xF) % 1000) >= 0x3E4) {
                            func_global_asm_8072DE44(0x35F);
                        }
                        break;
                }
            }
            goto block_80;
        case 0x1:
            if (func_global_asm_8072E54C() != 0) {
                current_actor_pointer->control_state = 0x11;
                current_actor_pointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x23:
            if (func_global_asm_8072E22C(0x50) != 0) {
                if (func_global_asm_8072DE10(0x1770) != 0) {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            // fallthrough
        case 0x10:
            func_global_asm_806B0770();
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            goto block_80;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_8072AB74(var_a0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            goto block_80;
        default:
            func_global_asm_8072B7CC(0x2D7);
            goto block_80;
    }
    temp_a0 = var_s0->control_state;
    switch (temp_a0) {                              // switch 5; irregular
        case 0x31:                                  // switch 5
        case 0x37:                                  // switch 5
        case 0x40:                                  // switch 5
            break;
        case 0x2:                                   // switch 5
        case 0x3:                                   // switch 5
            func_global_asm_8072D13C(temp_a0, 1);
            // fallthrough
        default:                                    // switch 5
            func_global_asm_8072C918(0x6400, 0x35F, 0x360);
            var_s0 = current_actor_pointer;
            break;
    }
    renderActor(var_s0, 0);
}
*/
