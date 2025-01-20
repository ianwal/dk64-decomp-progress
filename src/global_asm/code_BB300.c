#include <ultra64.h>
#include "functions.h"

extern f32 D_global_asm_807502E8;
extern s16 D_global_asm_807502E0;

extern u8 D_global_asm_807FBD70;

typedef struct {
    u8 unk0;
    u8 unk1;
} Actor178_806B6600;

void func_global_asm_806B6600(u8 arg0) {
    Actor178_806B6600 *a178;
    u16 temp_f0;
    AnimationStateUnk1C *temp_t0;
    f32 temp;
    f32 temp1;

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
                    playSoundAtActorPosition(current_actor_pointer, 0x16C, 0xFF, 0xA0, 6);
                }
                if (a178->unk0 < 0x50) {
                    a178->unk0 = 0;
                    a178->unk1 = 0;
                }
                break;
        }
    }
    temp1 = (a178->unk0 / 255.0);
    temp = 8000.0f * temp1;
    temp_t0[0].unk2_u16 = -temp;
    temp_t0[1].unk1 = 3;
    temp_t0++;
    temp_t0[0].unk0 = 0x7F;
    temp_t0[0].unk2_u16 = temp;
    temp_t0[0].unk4 = 0;
    temp_t0[0].unk6 = 0;
}

void func_global_asm_806B6958(void) {
    initializeCharacterSpawnerActor();
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
        playSoundAtActorPosition(current_actor_pointer, 0x3B2, 0xFF, 0x7F, 0x1E);
        playSoundAtActorPosition(current_actor_pointer, 0x3B7, 0xFF, 0x7F, 0x1E);
        func_global_asm_806850D0();
        deleteActor(current_actor_pointer);
    }
    if (current_actor_pointer->control_state == 0x23) {
        func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0);
    } else {
        func_global_asm_8072B7CC(0x237);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806B6C88(s16 arg0, s16 arg1) {
    if (spawnActor(ACTOR_KLAPTRAP_SKELETON, 0x24)) {
        last_spawned_actor->control_state = 0x23;
        playActorAnimation(last_spawned_actor, 0x237);
        last_spawned_actor->y_rotation = arg1;
        last_spawned_actor->unkEE = last_spawned_actor->y_rotation;
        moveAndScaleActorToAnother(
            last_spawned_actor, 
            current_actor_pointer, 
            current_actor_pointer->animation_state->scale_y
        );
        last_spawned_actor->floor = current_actor_pointer->floor;
        last_spawned_actor->y_acceleration = D_global_asm_807502E8;
        last_spawned_actor->terminal_velocity = D_global_asm_807502E0;
        last_spawned_actor->unkB8 = 0.0f;
        func_global_asm_8072B324(current_actor_pointer, arg0 * 1.25);
        memcpy(last_spawned_actor->additional_actor_data,
               current_actor_pointer->additional_actor_data,
               0x3C);
    }
}

// Close, Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BB300/func_global_asm_806B6DB0.s")

s32 func_global_asm_8072881C(s32, s32 *);
void func_global_asm_8072C918(s32, s16, s16);

typedef struct KlaptrapAAD178 {
    u8 pad0[2];
    s16 unk2;
} KlaptrapAAD178;

/*
void func_global_asm_806B6DB0(s32 arg0) {
    KlaptrapAAD178 *aad178; // 34
    s16 var_a2; // 32
    u8 sp31; // 31
    s8 var_t1;
    Actor *temp; // 2C
    f32 dz;
    f32 dx;

    aad178 = current_actor_pointer->AAD_as_array[1];
    if (current_actor_pointer->unkEE < current_actor_pointer->y_rotation) {
        var_a2 = current_actor_pointer->y_rotation - current_actor_pointer->unkEE;
    } else {
        var_a2 = current_actor_pointer->unkEE - current_actor_pointer->y_rotation;
    }
    dx = current_actor_pointer->x_position - D_global_asm_807FDC94->x_position;
    dz = current_actor_pointer->z_position - D_global_asm_807FDC94->z_position;
    sp31 = FALSE;
    if (((dx * dx) + (dz * dz)) < 2500.0f) {
        sp31 = TRUE;
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk34 = 1.0f;
        func_global_asm_80724CA4(2, 2);
        current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkC;
    }
    if ((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) {
        if (current_actor_pointer->control_state != 0x37) {
            temp = D_global_asm_807FBB70.unk1FC;
            current_actor_pointer->y_velocity = 200.0f;
            func_global_asm_8072D714(temp, 0x236);
            if ((temp && (temp->unk58 == ACTOR_PROJECTILE_ORANGE)) || ((current_map == MAP_AZTEC_TINY_TEMPLE) && (D_global_asm_807FDC9C->unk13 < 0x11))) {
                D_global_asm_807FDC90->unk1A |= 1;
            }
        }
    }
    if ((current_actor_pointer->control_state == 0x23) && (current_actor_pointer->unkB8 > 90.0f) && (var_a2 > 0x1F4) && (var_a2 < 0xE0C)) {
        var_a2 = current_actor_pointer->unkEE - current_actor_pointer->y_rotation;
        if (((var_a2) < 0) || ((var_a2) > 0x800)) {
            aad178->unk2 = 0x8C;
        } else {
            aad178->unk2 = -0x8C;
        }
        func_global_asm_8072B59C(0x14U, 0xA, 0x235);
    }
    switch (current_actor_pointer->control_state) {
    case 0x14:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            D_global_asm_807FDC90->unk2C = 0x1E;
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            if (D_global_asm_807FDC90->unk2C != 0) {
                current_actor_pointer->y_rotation += aad178->unk2;
                aad178->unk2 += (-aad178->unk2 * 0.01);
                D_global_asm_807FDC90->unk2C--;
                if (!(object_timer & 3)) {
                    func_global_asm_8072DAA4();
                }
            } else {
                current_actor_pointer->control_state_progress = 2;
            }
            break;
        case 2:
            func_global_asm_80605314(current_actor_pointer, 0U);
            func_global_asm_8072B59C(1U, D_global_asm_807FDC9C->unkC, 0x232);
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            break;
        }
        func_global_asm_80724E48(5U);
        func_global_asm_806B6600(0U);
        func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x300U, 0.0f);
        break;
    case 0x1:
        if (((rand() >> 0xF) % 1000) >= 0x3E3) {
            current_actor_pointer->control_state = 0x11;
            current_actor_pointer->control_state_progress = 0;
        }
    case 0x10:
    case 0x23:
        func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
        func_global_asm_80724E48(current_actor_pointer->control_state == 1 ? 2 : 0);
        func_global_asm_806B6600(sp31);
        func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x400U, 0.0f);
        break;
    case 0x2:
    case 0x3:
    case 0x7:
    case 0x35:
        func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
        func_global_asm_80724E48(current_actor_pointer->control_state == 0x35 ? 2 : 3);
        func_global_asm_806B6600(0U);
        func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x400U, 0.0f);
        break;
    case 0x11:
        func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
        func_global_asm_806B6600(0U);
        func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 2U, 0.0f);
        switch (current_actor_pointer->control_state_progress) {
        case 1:
            break;
        case 0:
            func_global_asm_8072B324(current_actor_pointer, 0);
            playActorAnimation(current_actor_pointer, 0x234);
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            func_global_asm_8072B59C(1U, D_global_asm_807FDC9C->unkC, 0x232);
            break;
        }
        break;
    case 0x37:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_8072AB74(0x37U, 0.0f, 0.0f, 0x20U, 0.0f);
            break;
        case 1:
            func_global_asm_806A5C60(current_actor_pointer);
            current_actor_pointer->y_velocity = 100.0f;
            current_actor_pointer->control_state_progress++;
        case 2:
            func_global_asm_8072AB74(0x37U, 0.0f, 0.0f, 0x20U, 0.0f);
            break;
        case 3:
            if (D_global_asm_807FDC90->unk1A & 1) {
                current_actor_pointer->control_state_progress++;
            } else {
                func_global_asm_806B6C88(D_global_asm_807FDC9C->unkD, func_global_asm_80665DE0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position));
                current_actor_pointer->control_state_progress = 5;
            }
            break;
        case 4:
            func_global_asm_8072DC7C(5U);
            break;
        case 5:
            current_actor_pointer->control_state = 0x40;
            break;
        }
        break;
    case 0x16:
        D_global_asm_807FDC90->unk1A |= 1;
    default:
        func_global_asm_8072B7CC(0x232);
        break;
    }
    switch (current_actor_pointer->control_state) {
    case 0x37:
    case 0x40:
        break;
    case 0x2:
    case 0x3:
        func_global_asm_8072D13C(current_actor_pointer->control_state, 1);
    default:
        func_global_asm_8072C918(arg0, 0x232, 0x233);
        break;
    }
    renderActor(current_actor_pointer, 0U);
}
*/


void func_global_asm_806B75F4(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B6DB0(10000);
}

void func_global_asm_806B761C(void) {
    initializeCharacterSpawnerActor();
    if (D_global_asm_807FBD70 == 4) {
        func_global_asm_80724C2C(-100);
    }
    func_global_asm_806B6DB0(10000);
}

void func_global_asm_806B7660(void) {
    initializeCharacterSpawnerActor();
    if (D_global_asm_807FBD70 == 4) {
        func_global_asm_80724C2C(-100);
    }
    func_global_asm_806B6DB0(10000);
}