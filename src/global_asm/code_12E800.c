#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80614D00(Actor *, f32, f32);
extern s32 D_8071FB34;
extern s32 D_80717D4C;
extern s32 D_8071FF18;
extern f64 D_8075FF20;
void func_806A5DF0(s32, f32, f32, f32, s32, s32, s32, s32);
void func_806F8BC4(s32, s32, s32);
void func_806F91B4(u8, u8, s16);
s16 func_806CC190(s16, s16, f32);
s32 func_80665DE0(f32, f32, f32, f32);
s16 func_806CC190(s16, s16, f32);

extern f64 D_8075FF38;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_80729B00.s")

void func_80729E6C(void) {
    current_actor_pointer->y_velocity += current_actor_pointer->y_acceleration;
    if (current_actor_pointer->y_velocity < current_actor_pointer->terminal_velocity) {
        current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_80729EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072A450.s")

extern f64 D_8075FD28;
extern s32 D_80720120; // TODO: Datatype

// killEnemy
void func_8072A714(void) {
    if ((current_actor_pointer->interactable & 2) && (func_80666A94() || func_80666AA0())) {
        if (func_80666AA0()) {
            func_80714CC0(
                &D_80720120,
                current_actor_pointer->animation_state->scale_y * D_8075FD28,
                current_actor_pointer->x_position,
                current_actor_pointer->y_position,
                current_actor_pointer->z_position
            );
        }
        current_actor_pointer->control_state = 0x40;
        enemies_killed++;
    }
}

void func_8072A7DC(void) {
    if ((D_807FDC90->unk1A & 0x40) == 0) {
        if ((current_actor_pointer->x_position == current_actor_pointer->unk88) && (current_actor_pointer->z_position == current_actor_pointer->unk90)) {
            D_807FDC90->unk38++;
            if (D_807FDC90->unk38 >= 0x1F) {
                D_807FDC90->unk1A |= 0x40;
            }
        } else {
            D_807FDC90->unk38 = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072A86C.s")

void func_8072AB74(u8, f32, f32, u16, f32);

/*
// TODO: t8 a3 regalloc? Odd one
void func_8072A86C(u8 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4) {
    current_actor_pointer->y_velocity = func_80612794(current_actor_pointer->unkF0) * -arg3;
    func_8072AB74(arg0, arg1, arg2, (arg4 | 0x1080) & 0xFFFF, current_actor_pointer->unk15E * 0.5);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072A920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072AA80.s")

/*
// TODO: Surprisingly close, might have type conflicts with D_807FDC9C[0].unkA
void func_8072AA80(void) {
    s16 phi_a0;

    if (D_807FDC9C[0].unkA) {
        phi_a0 = D_807FDC9C[0].unk6 + current_actor_pointer->unk15E + D_807FDC9C[0].unkA;
    } else {
        phi_a0 = (s16)current_actor_pointer->unkAC - current_actor_pointer->unk15E;
    }
    D_807FDC90->unkC = (((rand(phi_a0) >> 0xF) % 32767)
        % ((phi_a0 - D_807FDC9C[0].unk6 + current_actor_pointer->unk15E) + 1))
        + D_807FDC9C[0].unk6 + current_actor_pointer->unk15E;
}
*/

// TODO: Huge, and actually seems super doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072AB74.s")

void func_8072B324(Actor *arg0, s32 arg1) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    PaaD->unk26 = arg1;
}

void func_8072B330(u16 arg0) {
    f32 phi_f2 = MIN(3.0, current_actor_pointer->unkB8 * D_807FDC98->unk38);

    if (current_actor_pointer->unk6A & 4) {
        phi_f2 *= 0.5;
    }
    if (!(D_807FDC98->unk3C < phi_f2)) {
        phi_f2 = D_807FDC98->unk3C;
    }
    if ((!(arg0 & 0x400) || !(phi_f2 < 1.0)) && !(arg0 & 0x200) && (phi_f2 != current_actor_pointer->animation_state->unk48)) {
        func_80614D00(current_actor_pointer, phi_f2, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072B438.s")

void func_8072B59C(u8 arg0, s16 arg1, s32 arg2) {
    current_actor_pointer->control_state = arg0;
    current_actor_pointer->control_state_progress = 0;
    if (arg2 != current_actor_pointer->animation_state->unk64) {
        func_80614EBC(current_actor_pointer, arg2);
    }
    func_8072B324(current_actor_pointer, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072B608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072B79C.s")

/*
// Regalloc
void func_8072B79C(s16 arg0, u16 arg1, s16 arg2) {
    D_807FDC98->unk26 = arg0;
    D_807FDC98->unk28 = arg1;
    D_807FDC98->unk2A = arg2;
}
*/

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072B7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072C670.s")

void func_8072C870(u8 arg0, u8 arg1, s32 arg2) {
    if (arg0 == 7) {
        if (func_80725ED4(1, current_actor_pointer, D_807FDCA0, &D_807FDC90->unkA, &D_807FDC90->unkC, &D_807FDC90->unkE) == 0) {
            arg0 = 0x10;
            func_8072B324(current_actor_pointer, D_807FDC9C[0].unkD);
        }
    }
    D_807FDC90->unk36 = arg0;
    func_8072B59C(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072C918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072CFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072D08C.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072D13C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072D714.s")

void func_8072D99C(void) {
    current_actor_pointer->noclip_byte = 1;
    current_actor_pointer->control_state = 0x40;
    enemies_killed++;
}

void func_8072D9D4(void) {
    func_80714CC0(&D_8071FB34, 0.55f, current_actor_pointer->x_position, current_actor_pointer->y_position + (current_actor_pointer->unk15E * 0.5), current_actor_pointer->z_position);
}

void func_8072DA60(void) {
    func_80714CC0(&D_8071FB34,
                  0.55f,
                  D_807FBD6C->x_position,
                  D_807FBD6C->y_position,
                  D_807FBD6C->z_position);
}

void func_8072DAA4(void) {
    func_80714998(2);
    func_807149B8(1);
    func_8071498C(&D_80717D4C);
    func_80714950(-0x28 - ((rand() >> 0xF) % 15));
    func_80714CC0(&D_8071FF18,
                  (((rand() >> 0xF) % 1000) / D_8075FF20) + 0.5,
                  current_actor_pointer->x_position,
                  current_actor_pointer->y_position,
                  current_actor_pointer->z_position);
}

void func_8072DB68(s32 arg0) {
    u8 phi_v1;
    s16 phi_s0;

    if (func_806F8AD4(0xB, cc_player_index) >= 4) {
        phi_v1 = 3;
    } else {
        phi_v1 = func_806F8AD4(0xB, cc_player_index);
    }
    func_806F91B4(0xB, cc_player_index, -phi_v1);
    func_806F8BC4(0xB, 0, 0);
    playSong(0x41, 1.0f);
    for (phi_s0 = 0; phi_s0 < phi_v1; phi_s0++) {
        func_806A5DF0(0x36, player_pointer->x_position, player_pointer->y_position, player_pointer->z_position, (player_pointer->y_rotation + (phi_s0 * 0xC8)) - 0xC8, 1, -1, 0);
    }
}

void func_8072DC7C(u8 arg0) {
    func_8072AB74(0x37, 0.0f, 0.0f, 0x32, 0.0f);
    current_actor_pointer->shadow_opacity -= arg0;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->control_state_progress++;
        current_actor_pointer->shadow_opacity = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072DCF4.s")

/*
s32 func_8061CB50(f64, s32); // TODO: This signature is sus
f32 func_80665AE4(s32, s32, s32, s32);
extern f64 D_8075FF28;
extern f64 D_8075FF30;

s32 func_8072DCF4(Actor *arg0, Actor *arg1, u16 arg2) {
    s16 temp_f6;
    s16 temp_f8;
    s32 phi_a0;

    temp_f8 = ((D_8075FF28 - func_80665AE4(arg1->x_position, arg1->z_position, arg0->x_position, arg0->z_position)) / D_8075FF28) * 65536.0;
    temp_f6 = (arg0->y_rotation / D_8075FF30) * 65536.0;
    if (temp_f6 < temp_f8) {
        phi_a0 = temp_f8 - temp_f6;
    } else {
        phi_a0 = temp_f6 - temp_f8;
    }
    if ((phi_a0 < arg2) && !func_8061CB50(D_8075FF28, phi_a0)) {
        return TRUE;
    }
    return FALSE;
}
*/

void func_8072DE10(u16 arg0) {
    func_8072DCF4(current_actor_pointer, D_807FDC94, arg0);
}

void func_8072DE44(s32 arg0) {
    current_actor_pointer->control_state = D_807FDC9C[0].unk10;
    current_actor_pointer->control_state_progress = 0;
    func_80614EBC(current_actor_pointer, arg0);
    func_8072B324(current_actor_pointer, D_807FDC9C[0].unkC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072DEA8.s")

void func_8072E02C(void) {
    current_actor_pointer->z_rotation = func_806CC190(current_actor_pointer->z_rotation, 0, 5.0f);
    current_actor_pointer->x_rotation += (-current_actor_pointer->x_rotation * D_8075FF38);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072E0A8.s")

/*
// Quite close, float regalloc and stack/datatype issues
u8 func_8072E0A8(s32 arg0, s16 arg1) {
    u8 sp1F;
    f32 dx;
    f32 dz;
    s32 temp_v0_2;
    s16 phi_v1;

    dz = D_807FDC94->z_position - current_actor_pointer->z_position;
    dx = D_807FDC94->x_position - current_actor_pointer->x_position;
    sp1F = FALSE;
    if (((dx * dx) + (dz * dz)) < (arg0 * arg0)) {
        sp1F = TRUE;
    }
    temp_v0_2 = func_80665DE0(D_807FDC94->x_position, D_807FDC94->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
    if (temp_v0_2 < current_actor_pointer->y_rotation) {
        phi_v1 = current_actor_pointer->y_rotation - temp_v0_2;
    } else {
        phi_v1 = temp_v0_2 - current_actor_pointer->y_rotation;
    }
    if (phi_v1 > 0x800) {
        phi_v1 = 0x1000 - phi_v1;
    }
    return phi_v1 < arg1
        && sp1F
        && D_807FDC94->control_state != 0x42;
}
*/

void func_8072E1A4(u8 arg0, Actor *arg1) {
    current_actor_pointer->y_rotation = func_806CC190(current_actor_pointer->y_rotation, func_80665DE0(arg1->x_position, arg1->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position), arg0);
}

u8 func_8072E22C(u16 arg0) {
    f32 dx = current_actor_pointer->x_position - D_807FDC94->x_position;
    f32 dy = current_actor_pointer->y_position - D_807FDC94->y_position;
    f32 dz = current_actor_pointer->z_position - D_807FDC94->z_position;
    return ((dx * dx) + (dy * dy) + (dz * dz)) < (arg0 * arg0);
}

void func_8072E2B0(Actor *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    if (arg0->unkCC) {
        func_80671C0C(arg0, arg0->unkCC, arg1, arg2, arg3);
    } else {
        *arg1 = arg0->x_position;
        *arg2 = arg0->y_position;
        *arg3 = arg0->z_position;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072E320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072E54C.s")
