#include <ultra64.h>
#include "functions.h"

extern s32 D_8071FB34;
extern s32 D_80717D4C;
extern s32 D_8071FF18;
extern f64 D_8075FF20;
void func_806A5DF0(s32, f32, f32, f32, s32, s32, s32, s32);
void func_806F91B4(u8, u8, s16);
s16 func_806CC190(s16, s16, f32);
s16 func_806CC190(s16, s16, f32);

extern f64 D_8075FF38;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_80729B00.s")

extern s8 D_807FBB85;

typedef struct {
    EnemyInfo *unk0;
    Actor *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u16 unk18; // used
} AAD_80729B00;

void func_80608528(Actor *, s32, s32, s16, s32);
void func_80605314(Actor *, s32);
void func_806663F8(void);

/*
// TODO: Doable, very close!!!
void func_80729B00(void) {
    EnemyInfo *temp_t9;
    AAD_80729B00 *temp_t7;

    temp_t7 = current_actor_pointer->additional_actor_data;
    D_807FDC90 = temp_t7;
    D_807FDC94 = temp_t7->unk4;
    temp_t9 = temp_t7->unk0;
    D_807FDC98 = temp_t9;
    D_807FDC9C = temp_t9;
    D_807FDCA0 = temp_t9->unk1C;
    temp_t7->unk18++;
    if (current_actor_pointer->object_properties_bitfield & 0x20000000) {
        if ((current_actor_pointer->control_state != 0x37)
            && (current_actor_pointer->control_state != 0x36)
            && (D_807FDC90->unk16 != D_807FDC94->animation_state->unk0->unk10)) {
            current_actor_pointer->object_properties_bitfield &= 0xDFFFFFFF;
        }
    }
    if (current_actor_pointer->interactable & 2) {
        if (((is_cutscene_active == 1) && (D_807FDC98->unk46 & 8)) || ((D_807FDC94 != NULL) && (D_807FDC94->control_state == 0x42))) {
            if ((current_actor_pointer->control_state >= 0x23) && (current_actor_pointer->control_state < 0x36)) {
                current_actor_pointer->noclip_byte = 1;
                current_actor_pointer->control_state = 0x3A;
                current_actor_pointer->control_state_progress = 0;
            }
        }
        if ((D_807FBB70[0].unk1B != 0) && (current_actor_pointer->control_state != 0x39)) {
            if (D_807FDC98->unk46 & 0x800) {
                D_807FBB70[0].unk15 = 1;
            } else {
                func_8067AC38();
                current_actor_pointer->unk138 = 0;
                current_actor_pointer->object_properties_bitfield &= 0xFFFD7FFF;
                current_actor_pointer->noclip_byte = 1;
                current_actor_pointer->control_state = 0x39;
                current_actor_pointer->control_state_progress = 0;
                func_80614EBC(current_actor_pointer, D_807FDC98->unk2A);
                func_80608528(current_actor_pointer, 0x16, 0xFF, 0x7F, 0x14);
                current_actor_pointer->y_velocity = -220.0f;
            }
        }
        if ((D_807FDC98->unk46 & 0x4000) && (current_actor_pointer->unk6A & 4)) {
            if ((current_actor_pointer->y_position + current_actor_pointer->unk15E) < current_actor_pointer->unkAC) {
                D_807FBB70[0].unk15 = 1;
            }
        }
        if ((current_map == MAP_FUNGI) && (D_807FDC94->interactable & 1)) {
            if ((D_807FDC94->PaaD->unk1F0 ^ D_807FDC94->PaaD->unk1F8) & 0x100000) {
                func_80605314(current_actor_pointer, 0);
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                D_807FBB85 = 1;
            }
        }
    }
    if ((current_actor_pointer->unk58 != 0xAF) && (current_actor_pointer->control_state == 0x37) && (current_actor_pointer->unk138 != 0)) {
        current_actor_pointer->unk138 = 0;
    }
    func_806663F8();
}
*/

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

u8 func_8072AB74(u8 arg0, f32 arg1, f32 arg2, u16 arg3, f32 arg4);

/*
// TODO: t8 a3 regalloc? Odd one
void func_8072A86C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4) {
    current_actor_pointer->y_velocity = func_80612794(current_actor_pointer->unkF0) * -arg3;
    func_8072AB74(arg0, arg1, arg2, (arg4 | 0x1080) & 0xFFFF, current_actor_pointer->unk15E * 0.5);
}
*/

extern f64 D_8075FD30;
extern f64 D_8075FD38;

void func_8072A86C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4);

void func_8072A920(s16 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, f32 arg6, f32 arg7, u16 arg8) {
    current_actor_pointer->z_rotation = func_806CC190(current_actor_pointer->z_rotation, (func_80665E94(arg2, arg3, arg4, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, arg5) * 2048.0) / D_8075FD30, arg6);
    current_actor_pointer->unkF0 = func_806CC190(current_actor_pointer->unkF0, (func_80665E94(arg2, arg1 + arg3, arg4, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, arg5) * 2048.0) / D_8075FD38, arg6);
    func_8072A86C(arg0, arg2, arg4, arg7, arg8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072AA80.s")

/*
// TODO: Surprisingly close
void func_8072AA80(void) {
    s16 phi_a0;

    if (D_807FDC9C->unkA_s16) {
        phi_a0 = D_807FDC9C->unk6 + current_actor_pointer->unk15E + D_807FDC9C->unkA_s16;
    } else {
        phi_a0 = (s16)current_actor_pointer->unkAC - current_actor_pointer->unk15E;
    }
    D_807FDC90->unkC = (((rand() >> 0xF) % 32767)
        % ((phi_a0 - D_807FDC9C->unk6 + current_actor_pointer->unk15E) + 1))
        + D_807FDC9C->unk6 + current_actor_pointer->unk15E;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_8072AB74.s")

extern f64 D_8075FD40;

void func_80729EB0(s32, f32, f32, u16);
void func_806653C0(Actor*, f32, f32);
s32 func_80725BA4(f32, f32, Struct807FDCA0*);

/*
// TODO: Seems doable, progress made...
u8 func_8072AB74(u8 arg0, f32 x, f32 z, u16 arg3, f32 arg4) {
    s16 sp52;
    s16 *sp4C;
    u8 sp43;
    f32 sp34;
    f32 dx;
    f32 temp_f12;
    f32 dz;
    s32 var_v1_2;

    sp43 = 0;
    sp4C = &D_807FDC90->unk8;
    D_807FDC90->unk1C = D_807FDC90->unk1A;
    D_807FDC90->unk1A &= 0xBD7F;
    dx = current_actor_pointer->x_position - x;
    dz = current_actor_pointer->z_position - z;
    temp_f12 = current_actor_pointer->animation_state->scale_y / D_8075FD40;
    if (((dx * dx) + (dz * dz)) < (1600.0f * temp_f12)) {
        D_807FDC90->unk1A |= 0x80;
        if (func_806CC14C(*sp4C, current_actor_pointer->y_rotation) >= 0x191) {
            current_actor_pointer->unkB8 *= D_807FDC98->unk34;
        }
    }
    func_8067ACB4(current_actor_pointer);
    if ((current_actor_pointer->unkB8 != 0.0f) || (arg3 & 4)) {
        func_80729EB0(arg0, x, z, arg3);
    }
    if (!(arg3 & 0x1001)) {
        func_80729E6C();
    }
    if (!(D_807FDC98->unk46 & 0x200)) {
        func_80666280(2);
    }
    if ((D_807FDCA0->unk19 == 1) && ((arg0 != 0x37) || !(D_807FDC98->unk46 & 0x10))) {
        func_80666280(1);
    }
    if (arg3 & 0x4000) {
        current_actor_pointer->unkFC = 0;
    }
    if ((arg0 != 0x37) && !(D_807FDC90->unk1A & 2)) {
        func_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->y_rotation);
    }
    if (arg3 & 2) {
        if (!(arg3 & 1)) {
            func_806653C0(current_actor_pointer, 0.0f, current_actor_pointer->y_velocity);
        }
        func_80665564(current_actor_pointer, arg4);
        if (!(arg3 & 0x2000)) {
            func_8072A714();
        }
        if (!(arg3 & 0x10)) {
            func_8072A450();
        }
        return 0;
    }
    if (!(arg3 & 0x20)) {
        func_8072B438(arg3);
    }
    if (arg3 & 0x800) {
        func_806653C0(current_actor_pointer, 0.0f, current_actor_pointer->y_velocity);
    } else if (arg3 & 1) {
        func_806653C0(current_actor_pointer, current_actor_pointer->unkB8, 0.0f);
    } else {
        func_806651FC(current_actor_pointer);
    }
    if (!(arg3 & 8)) {
        func_80665564(current_actor_pointer, arg4);
    } else if ((D_807FDCA0->unk19 != 1) && (arg3 & 0x10)) {
        func_8066635C(current_actor_pointer, current_actor_pointer->x_position, current_actor_pointer->unk8C, current_actor_pointer->z_position, &current_actor_pointer->floor);
    }
    if (!(arg3 & 0x2000)) {
        func_8072A714();
    }
    if (!(arg3 & 0x10)) {
        func_8072A450();
    }
    current_actor_pointer->unkFC = 0;
    current_actor_pointer->unkFD = 0;
    if ((D_807FDC98->unk46 & 0x20) || (current_actor_pointer->interactable & 0x40)) {
        return 0;
    }
    if ((arg0 == 0x37) && (D_807FDC98->unk46 & 0x10)) {
        if (func_80725BA4(current_actor_pointer->x_position, current_actor_pointer->z_position, D_807FDCA0) == 0) {
            var_v1_2 = -1;
            if (current_actor_pointer->unkB8 >= 0.0f) {
                var_v1_2 = 1;
            }
            current_actor_pointer->unkB8 = var_v1_2 * 0x1E;
            return 0;
        }
        D_807FDC90->unk1A |= 0x4000;
        return 0;
    }
    if (func_80725BA4(current_actor_pointer->x_position, current_actor_pointer->z_position, D_807FDCA0) != 0) {
        D_807FDC90->unk1A |= 0x4000;
        if (func_807264B0(current_actor_pointer, current_actor_pointer->unk88, current_actor_pointer->unk90, D_807FDCA0, &sp52) == 0) {
            sp34 = func_80612794(current_actor_pointer->unkEE);
            if (func_80725BA4((sp34 * current_actor_pointer->unkB8) + current_actor_pointer->x_position, (func_80612790(current_actor_pointer->unkEE) * current_actor_pointer->unkB8) + current_actor_pointer->z_position, D_807FDCA0) == 0) {
                if (D_807FDC90->unk22-- == 0) {
                    *sp4C += 0x800;
                    *sp4C &= 0xFFF;
                    D_807FDC90->unk22 = D_807FDC90->unk23 * 4;
                }
            }
            goto block_63;
        }
        if ((arg0 == 0x37) || (arg0 == 0)) {
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->x_position = D_807FDC90->unk10;
            current_actor_pointer->z_position = D_807FDC90->unk14;
            return 0;
        }
block_63:
        D_807FDC90->unk10 = current_actor_pointer->x_position;
        D_807FDC90->unk14 = current_actor_pointer->z_position;
        goto block_66;
    }
    sp43 = 1;
    D_807FDC90->unk1A |= 0x200;
    current_actor_pointer->x_position = D_807FDC90->unk10;
    current_actor_pointer->z_position = D_807FDC90->unk14;
    if (D_807FDC90->unk22-- == 0) {
        *sp4C += 0x800;
        *sp4C &= 0xFFF;
        D_807FDC90->unk22 = D_807FDC90->unk23 * 6;
    }
block_66:
    return sp43;
}
*/

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

/*
void func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

// TODO: .rodata nonsense?
void func_8072B608(void) {
    f32 var_f2;
    f32 var_f6;
    f64 var_f10;
    s32 temp_t8;
    u32 temp_hi;

    func_80612794(((object_timer % 4095) * 4) % 4095);
    func_80612790(((object_timer % 4095) * 4) % 4095);
    temp_hi = (object_timer * 4) % 150;
    if (temp_hi >= 0x4C) {
        temp_t8 = temp_hi - 0x4B;
        var_f6 = temp_t8;
        var_f2 = var_f6 + 100.0f;
    } else {
        var_f10 = temp_hi;
        var_f2 = (100.0f + 50.0) - var_f10;
    }
    func_8065A708(current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position, 0.0f, 0.0f, 0.0f, var_f2, 0, 0xFF, 0xFF, 0xFF);
}
*/

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
            func_8072B324(current_actor_pointer, D_807FDC9C->unkD);
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
s32 func_8061CB50(void);
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
    if ((phi_a0 < arg2) && !func_8061CB50()) {
        return TRUE;
    }
    return FALSE;
}
*/

s32 func_8072DE10(u16 arg0) {
    return func_8072DCF4(current_actor_pointer, D_807FDC94, arg0);
}

void func_8072DE44(s32 arg0) {
    current_actor_pointer->control_state = D_807FDC9C->unk10;
    current_actor_pointer->control_state_progress = 0;
    func_80614EBC(current_actor_pointer, arg0);
    func_8072B324(current_actor_pointer, D_807FDC9C->unkC);
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

extern f64 D_8075FF40;
extern f64 D_8075FF48;

/*
// TODO: Quite close...
void func_8072E320(f32 arg0) {
    f32 var_f0;
    f32 var_f2;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    current_actor_pointer->y_rotation = func_806CC190(current_actor_pointer->y_rotation, func_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, current_actor_pointer->unk88, current_actor_pointer->unk90), 3.3f);
    if ((func_806CC10C(current_actor_pointer->y_rotation, current_actor_pointer->unkEE) * arg0) > -900.0f) {
        var_f0 = func_806CC10C(current_actor_pointer->y_rotation, current_actor_pointer->unkEE) * arg0;
    } else {
        var_f0 = -900.0f;
    }
    if (var_f0 < 900.0f) {
        if ((func_806CC10C(current_actor_pointer->y_rotation, current_actor_pointer->unkEE) * arg0) > -900.0f) {
            var_f2 = func_806CC10C(current_actor_pointer->y_rotation, current_actor_pointer->unkEE) * arg0;
        } else {
            var_f2 = -900.0f;
        }
    } else {
        var_f2 = 900.0f;
    }
    current_actor_pointer->x_rotation = ((var_f2 - current_actor_pointer->x_rotation) * D_8075FF40) + current_actor_pointer->x_rotation;
    func_80665E94(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, current_actor_pointer->unk88, current_actor_pointer->unk8C, current_actor_pointer->unk90, 0x1E);
    current_actor_pointer->z_rotation = func_806CC190(current_actor_pointer->z_rotation, (var_f0 * 2048.0) / D_8075FF48, 3.3f);
}
*/

u8 func_8072E54C(void) {
    s32 var_v1;

    var_v1 = (D_807FDC98->unk46 & 0x2000) == 0;
    if (var_v1 != 0) {
        var_v1 = (((rand() >> 0xF) % 1000) < 0x3E4) ^ 1;
    }
    return var_v1;
}
