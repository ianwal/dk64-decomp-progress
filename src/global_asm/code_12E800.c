#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_8071FB34;
extern s32 D_global_asm_8071FF18;
extern f64 D_global_asm_8075FF20;

extern f64 D_global_asm_8075FF38;

// doable, close
// https://decomp.me/scratch/KfxB4
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/initializeCharacterSpawnerActor.s")

extern s8 D_global_asm_807FBB85;

typedef struct {
    EnemyInfo *unk0;
    Actor *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u16 unk18; // used
} AAD_global_asm_80729B00;

/*
void initializeCharacterSpawnerActor(void) {
    D_global_asm_807FDC90 = current_actor_pointer->additional_actor_data;
    D_global_asm_807FDC94 = D_global_asm_807FDC90->unk4;
    D_global_asm_807FDC98 = D_global_asm_807FDC90->unk0;
    D_global_asm_807FDC9C = D_global_asm_807FDC98;
    D_global_asm_807FDCA0 = D_global_asm_807FDC90->unk1C_s32;
    D_global_asm_807FDC90->unk18 = D_global_asm_807FDC90->unk18 + 1;
    if (current_actor_pointer->object_properties_bitfield & 0x20000000) {
        if ((current_actor_pointer->control_state != 0x37) && (current_actor_pointer->control_state != 0x36)) {
            if (D_global_asm_807FDC90->unk16 != D_global_asm_807FDC94->animation_state->unk0->unk10) {
                current_actor_pointer->object_properties_bitfield &= ~0x20000000;
            }
        }
    }
    if (current_actor_pointer->interactable & 2) {
        if (((is_cutscene_active == 1) && (D_global_asm_807FDC98->unk46 & 8)) || ((D_global_asm_807FDC94 != NULL) && (D_global_asm_807FDC94->control_state == 0x42))) {
            if ((current_actor_pointer->control_state >= 0x23) && (current_actor_pointer->control_state < 0x36)) {
                current_actor_pointer->noclip_byte = 1;
                current_actor_pointer->control_state = 0x3A;
                current_actor_pointer->control_state_progress = 0;
            }
        }
        if ((D_global_asm_807FBB70.unk1B != 0) && (current_actor_pointer->control_state != 0x39)) {
            if (D_global_asm_807FDC98->unk46 & 0x800) {
                D_global_asm_807FBB70.unk15 = 1;
            } else {
                func_global_asm_8067AC38();
                current_actor_pointer->unk138 = 0;
                current_actor_pointer->object_properties_bitfield &= 0xFFFD7FFF;
                current_actor_pointer->noclip_byte = 1;
                current_actor_pointer->control_state = 0x39;
                current_actor_pointer->control_state_progress = 0;
                playActorAnimation(current_actor_pointer, D_global_asm_807FDC98->unk2A);
                playSoundAtActorPosition(current_actor_pointer, 0x16, 0xFF, 0x7F, 0x14);
                current_actor_pointer->y_velocity = -220.0f;
            }
        }
        if ((D_global_asm_807FDC98->unk46 & 0x4000)) {
            if ((current_actor_pointer->unk6A & 4)) {
                if ((current_actor_pointer->y_position + current_actor_pointer->unk15E) < current_actor_pointer->unkAC) {
                    D_global_asm_807FBB70.unk15 = 1;
                }
            }
        }
        if ((current_map == MAP_FUNGI) && (D_global_asm_807FDC94->interactable & 1)) {
            if ((D_global_asm_807FDC94->PaaD->unk1F0 ^ D_global_asm_807FDC94->PaaD->unk1F8) & 0x100000) {
                func_global_asm_80605314(current_actor_pointer, 0);
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                D_global_asm_807FBB85 = 1;
            }
        }
    }
    if ((current_actor_pointer->unk58 != ACTOR_KABOOM)) {
        if ((current_actor_pointer->control_state == 0x37) && (current_actor_pointer->unk138 != 0)) {
            current_actor_pointer->unk138 = 0;
        }
    }
    func_global_asm_806663F8();
}
*/

void func_global_asm_80729E6C(void) {
    current_actor_pointer->y_velocity += current_actor_pointer->y_acceleration;
    if (current_actor_pointer->y_velocity < current_actor_pointer->terminal_velocity) {
        current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_80729EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072A450.s")

extern f64 D_global_asm_8075FD20;

void func_global_asm_8072A450(void);

/*
// TODO: Float nonsense
void func_global_asm_8072A450(void) {
    ActorAnimationState *temp_v0_2;
    f32 temp_f0;
    Struct8075EB80 *temp_v1;

    if (!(current_actor_pointer->object_properties_bitfield & 0x01000000)) {
        if (current_actor_pointer->object_properties_bitfield & 4) {
            if (!(D_global_asm_807FDC98->unk46 & 0x100)) {
                temp_v0_2 = current_actor_pointer->animation_state;
                temp_v1 = &D_global_asm_8075EB80[D_global_asm_807FDC98->unk44];
                func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, (temp_v0_2->scale_x * temp_v1->unk14 * D_global_asm_807FDC98->unk30), (temp_v0_2->scale_z * temp_v1->unk15 * D_global_asm_807FDC98->unk30), 1, 0x12C, (current_actor_pointer->shadow_opacity * D_global_asm_8075FD20), current_actor_pointer->y_rotation, 1.0f);
            }
        }
    }
}
*/

extern f64 D_global_asm_8075FD28;
extern s32 D_global_asm_80720120; // TODO: Datatype

// killEnemy
void func_global_asm_8072A714(void) {
    if ((current_actor_pointer->interactable & 2) && (func_global_asm_80666A94() || func_global_asm_80666AA0())) {
        if (func_global_asm_80666AA0()) {
            drawSpriteAtPosition(
                &D_global_asm_80720120,
                current_actor_pointer->animation_state->scale_y * D_global_asm_8075FD28,
                current_actor_pointer->x_position,
                current_actor_pointer->y_position,
                current_actor_pointer->z_position
            );
        }
        current_actor_pointer->control_state = 0x40;
        enemies_killed++;
    }
}

void func_global_asm_8072A7DC(void) {
    if ((D_global_asm_807FDC90->unk1A & 0x40) == 0) {
        if ((current_actor_pointer->x_position == current_actor_pointer->unk88) && (current_actor_pointer->z_position == current_actor_pointer->unk90)) {
            D_global_asm_807FDC90->unk38++;
            if (D_global_asm_807FDC90->unk38 >= 0x1F) {
                D_global_asm_807FDC90->unk1A |= 0x40;
            }
        } else {
            D_global_asm_807FDC90->unk38 = 0;
        }
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072A86C.s")

/*
void func_global_asm_8072A86C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4) {
    current_actor_pointer->y_velocity = func_global_asm_80612794(current_actor_pointer->unkF0) * -arg3;
    func_global_asm_8072AB74(arg0, arg1, arg2, (arg4 | 0x1080) & 0xFFFF, current_actor_pointer->unk15E * 0.5);
}
*/

extern f64 D_global_asm_8075FD30;
extern f64 D_global_asm_8075FD38;

void func_global_asm_8072A86C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4);

void func_global_asm_8072A920(s16 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, f32 arg6, f32 arg7, u16 arg8) {
    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, (func_global_asm_80665E94(arg2, arg3, arg4, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, arg5) * 2048.0) / D_global_asm_8075FD30, arg6);
    current_actor_pointer->unkF0 = func_global_asm_806CC190(current_actor_pointer->unkF0, (func_global_asm_80665E94(arg2, arg1 + arg3, arg4, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, arg5) * 2048.0) / D_global_asm_8075FD38, arg6);
    func_global_asm_8072A86C(arg0, arg2, arg4, arg7, arg8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072AA80.s")

/*
// TODO: Surprisingly close
void func_global_asm_8072AA80(void) {
    s16 phi_a0;

    if (D_global_asm_807FDC9C->unkA_s16) {
        phi_a0 = D_global_asm_807FDC9C->unk6 + current_actor_pointer->unk15E + D_global_asm_807FDC9C->unkA_s16;
    } else {
        phi_a0 = (s16)current_actor_pointer->unkAC - current_actor_pointer->unk15E;
    }
    D_global_asm_807FDC90->unkC = (((rand() >> 0xF) % 32767)
        % ((phi_a0 - D_global_asm_807FDC9C->unk6 + current_actor_pointer->unk15E) + 1))
        + D_global_asm_807FDC9C->unk6 + current_actor_pointer->unk15E;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072AB74.s")

extern f64 D_global_asm_8075FD40;

void func_global_asm_80729EB0(s32, f32, f32, u16);
s32 func_global_asm_80725BA4(s16, s16, Struct807FDCA0*);

s32 func_global_asm_807264B0(Actor *arg0, f32 arg1, f32 arg2, void *arg3);

/*
// TODO: Seems doable, progress made...
u8 func_global_asm_8072AB74(u8 arg0, f32 x, f32 z, u16 arg3, f32 arg4) {
    s16 sp52;
    s16 *sp4C;
    u8 sp43;
    f32 sp34;
    f32 dx;
    f32 temp_f12;
    f32 dz;
    s32 var_v1_2;

    sp43 = 0;
    sp4C = &D_global_asm_807FDC90->unk8;
    D_global_asm_807FDC90->unk1C = D_global_asm_807FDC90->unk1A;
    D_global_asm_807FDC90->unk1A &= 0xBD7F;
    dx = current_actor_pointer->x_position - x;
    dz = current_actor_pointer->z_position - z;
    temp_f12 = current_actor_pointer->animation_state->scale_y / D_global_asm_8075FD40;
    if (((dx * dx) + (dz * dz)) < (1600.0f * temp_f12)) {
        D_global_asm_807FDC90->unk1A |= 0x80;
        if (func_global_asm_806CC14C(*sp4C, current_actor_pointer->y_rotation) >= 0x191) {
            current_actor_pointer->unkB8 *= D_global_asm_807FDC98->unk34;
        }
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    if ((current_actor_pointer->unkB8 != 0.0f) || (arg3 & 4)) {
        func_global_asm_80729EB0(arg0, x, z, arg3);
    }
    if (!(arg3 & 0x1001)) {
        func_global_asm_80729E6C();
    }
    if (!(D_global_asm_807FDC98->unk46 & 0x200)) {
        func_global_asm_80666280(2);
    }
    if ((D_global_asm_807FDCA0->unk19 == 1) && ((arg0 != 0x37) || !(D_global_asm_807FDC98->unk46 & 0x10))) {
        func_global_asm_80666280(1);
    }
    if (arg3 & 0x4000) {
        current_actor_pointer->unkFC = 0;
    }
    if ((arg0 != 0x37) && !(D_global_asm_807FDC90->unk1A & 2)) {
        func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->y_rotation);
    }
    if (arg3 & 2) {
        if (!(arg3 & 1)) {
            func_global_asm_806653C0(current_actor_pointer, 0.0f, current_actor_pointer->y_velocity);
        }
        func_global_asm_80665564(current_actor_pointer, arg4);
        if (!(arg3 & 0x2000)) {
            func_global_asm_8072A714();
        }
        if (!(arg3 & 0x10)) {
            func_global_asm_8072A450();
        }
        return 0;
    }
    if (!(arg3 & 0x20)) {
        func_global_asm_8072B438(arg3);
    }
    if (arg3 & 0x800) {
        func_global_asm_806653C0(current_actor_pointer, 0.0f, current_actor_pointer->y_velocity);
    } else if (arg3 & 1) {
        func_global_asm_806653C0(current_actor_pointer, current_actor_pointer->unkB8, 0.0f);
    } else {
        func_global_asm_806651FC(current_actor_pointer);
    }
    if (!(arg3 & 8)) {
        func_global_asm_80665564(current_actor_pointer, arg4);
    } else if ((D_global_asm_807FDCA0->unk19 != 1) && (arg3 & 0x10)) {
        func_global_asm_8066635C(current_actor_pointer, current_actor_pointer->x_position, current_actor_pointer->unk8C, current_actor_pointer->z_position, &current_actor_pointer->floor);
    }
    if (!(arg3 & 0x2000)) {
        func_global_asm_8072A714();
    }
    if (!(arg3 & 0x10)) {
        func_global_asm_8072A450();
    }
    current_actor_pointer->unkFC = 0;
    current_actor_pointer->unkFD = 0;
    if ((D_global_asm_807FDC98->unk46 & 0x20) || (current_actor_pointer->interactable & 0x40)) {
        return 0;
    }
    if ((arg0 == 0x37) && (D_global_asm_807FDC98->unk46 & 0x10)) {
        if (func_global_asm_80725BA4(current_actor_pointer->x_position, current_actor_pointer->z_position, D_global_asm_807FDCA0) == 0) {
            var_v1_2 = -1;
            if (current_actor_pointer->unkB8 >= 0.0f) {
                var_v1_2 = 1;
            }
            current_actor_pointer->unkB8 = var_v1_2 * 0x1E;
        } else {
            D_global_asm_807FDC90->unk1A |= 0x4000;
        }
        return 0;
    }
    if (func_global_asm_80725BA4(current_actor_pointer->x_position, current_actor_pointer->z_position, D_global_asm_807FDCA0) != 0) {
        D_global_asm_807FDC90->unk1A |= 0x4000;
        // if (func_global_asm_807264B0(current_actor_pointer, current_actor_pointer->unk88, current_actor_pointer->unk90, D_global_asm_807FDCA0, &sp52) == 0) {
        if (func_global_asm_807264B0(current_actor_pointer, current_actor_pointer->unk88, current_actor_pointer->unk90, D_global_asm_807FDCA0) == 0) {
            sp34 = func_global_asm_80612794(current_actor_pointer->unkEE);
            if (func_global_asm_80725BA4((sp34 * current_actor_pointer->unkB8) + current_actor_pointer->x_position, (func_global_asm_80612790(current_actor_pointer->unkEE) * current_actor_pointer->unkB8) + current_actor_pointer->z_position, D_global_asm_807FDCA0) == 0) {
                if (D_global_asm_807FDC90->unk22-- == 0) {
                    *sp4C += 0x800;
                    *sp4C &= 0xFFF;
                    D_global_asm_807FDC90->unk22 = D_global_asm_807FDC90->unk23 * 4;
                }
            }
            goto block_63;
        }
        if ((arg0 == 0x37) || (arg0 == 0)) {
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->x_position = D_global_asm_807FDC90->unk10;
            current_actor_pointer->z_position = D_global_asm_807FDC90->unk14;
            return 0;
        }
block_63:
        D_global_asm_807FDC90->unk10 = current_actor_pointer->x_position;
        D_global_asm_807FDC90->unk14 = current_actor_pointer->z_position;
        goto block_66;
    }
    sp43 = 1;
    D_global_asm_807FDC90->unk1A |= 0x200;
    current_actor_pointer->x_position = D_global_asm_807FDC90->unk10;
    current_actor_pointer->z_position = D_global_asm_807FDC90->unk14;
    if (D_global_asm_807FDC90->unk22-- == 0) {
        *sp4C += 0x800;
        *sp4C &= 0xFFF;
        D_global_asm_807FDC90->unk22 = D_global_asm_807FDC90->unk23 * 6;
    }
block_66:
    return sp43;
}
*/

void func_global_asm_8072B324(Actor *arg0, s32 arg1) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    PaaD->unk26 = arg1;
}

void func_global_asm_8072B330(u16 arg0) {
    f32 phi_f2 = MIN(3.0, current_actor_pointer->unkB8 * D_global_asm_807FDC98->unk38);

    if (current_actor_pointer->unk6A & 4) {
        phi_f2 *= 0.5;
    }
    if (!(D_global_asm_807FDC98->unk3C < phi_f2)) {
        phi_f2 = D_global_asm_807FDC98->unk3C;
    }
    if ((!(arg0 & 0x400) || !(phi_f2 < 1.0)) && !(arg0 & 0x200) && (phi_f2 != current_actor_pointer->animation_state->unk48)) {
        func_global_asm_80614D00(current_actor_pointer, phi_f2, 0);
    }
}

void func_global_asm_8072B438(u16 arg0) {
    s32 temp_v1;
    f32 var_f12;

    temp_v1 = D_global_asm_807FDC90->unk26;
    if ((current_actor_pointer->unkB8 < -60.0f) && (current_actor_pointer->unk6A & 1) && ((object_timer % 5U) == 0)) {
        func_global_asm_8072DAA4();
    }
    if (current_actor_pointer->unkB8 != temp_v1) {
        if (current_actor_pointer->unkB8 < temp_v1) {
            current_actor_pointer->unkB8 = MIN(temp_v1, (current_actor_pointer->unkB8 + D_global_asm_807FDC90->unk35));
        } else if (temp_v1 < current_actor_pointer->unkB8) {
            current_actor_pointer->unkB8 = MAX(temp_v1, (current_actor_pointer->unkB8 - D_global_asm_807FDC90->unk35));
        }
    }
    func_global_asm_8072B330(arg0);
}

void func_global_asm_8072B59C(u8 arg0, s16 arg1, s32 arg2) {
    current_actor_pointer->control_state = arg0;
    current_actor_pointer->control_state_progress = 0;
    if (arg2 != current_actor_pointer->animation_state->unk64) {
        playActorAnimation(current_actor_pointer, arg2);
    }
    func_global_asm_8072B324(current_actor_pointer, arg1);
}

void func_global_asm_8072B608(void) {
    f32 var_f2;

    func_global_asm_80612794(((object_timer % 4095U) * 4) % 4095);
    func_global_asm_80612790(((object_timer % 4095U) * 4) % 4095);
    if (((object_timer * 4) % 150U) >= 76) {
        var_f2 = ((object_timer * 4) % 150U) - 75 + 100.0f;
    } else {
        f32 temp = 100.0f;
        var_f2 = (50.0 + temp) - ((object_timer * 4) % 150U);
    }
    createLight(
        current_actor_pointer->x_position,
        current_actor_pointer->y_position + 10.0f,
        current_actor_pointer->z_position,
        0.0f,
        0.0f,
        0.0f,
        var_f2,
        0,
        0xFF,
        0xFF,
        0xFF
    );
}

void func_global_asm_8072B79C(s16 arg0, s16 arg1, s16 arg2) {
    D_global_asm_807FDC98->unk26 = arg0;
    D_global_asm_807FDC98->unk28 = arg1;
    D_global_asm_807FDC98->unk2A = arg2;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072B7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072C670.s")

/*
// TODO: Get rid of the GOTOs
u8 func_global_asm_8072C670(u8 arg0, s8 *arg1) {
    u8 temp_v0;
    u8 temp_v1;
    u8 var_v1;
    PlayerAdditionalActorData *PaaD;

    PaaD = D_global_asm_807FDC94->additional_actor_data;
    *arg1 = 1;
    if (current_actor_pointer->interactable & 2) {
        if (current_actor_pointer->control_state != 0x15) {
            if (D_global_asm_807FDC94->unk58 == ACTOR_CHUNKY) {
                if (character_change_array->unk2C0 == 2) {
                    if (cc_number_of_players != 1) {
                        goto block_5;
                    }
                    goto block_7;
                }
                goto block_5;
            }
block_5:
            if (D_global_asm_807FDC94->interactable & 1) {
                if (PaaD->unk1F0 & 0x10) {
block_7:
                    var_v1 = 7;
                } else {
                    goto block_8;
                }
            } else {
                goto block_8;
            }
        } else {
block_8:
            if (D_global_asm_807FDC90->unk37 == 7) {
                if (arg0) {
                    if (!(D_global_asm_807FDC90->unk1A & 0x200)) {
                        if (D_global_asm_807FDC90->unk20 == 0) {
                            D_global_asm_807FDC90->unk20 = 0x10;
                            if (func_global_asm_80725ED4(0x81, current_actor_pointer, D_global_asm_807FDCA0, &D_global_asm_807FDC90->unkA, &D_global_asm_807FDC90->unkC, &D_global_asm_807FDC90->unkE) == 0) {
                                var_v1 = 0x10;
                            } else {
                                var_v1 = 7;
                            }
                        } else {
                            goto block_15;
                        }
                    } else {
                        goto block_15;
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                if (D_global_asm_807FDC90->unk20 != 0) {
                    D_global_asm_807FDC90->unk20--;
                }
                if (D_global_asm_807FDC94->interactable & 1) {
                    if (PaaD->unkD4 != 0) {
                        var_v1 = 1;
                        if (!(D_global_asm_807FBB64 & 0x100000)) {
                            *arg1 = 0;
                        } else {
                            goto block_21;
                        }
                    } else {
                        goto block_21;
                    }
                } else {
block_21:
                    if (D_global_asm_807FDC90->unk1A & 0x400) {
                        var_v1 = D_global_asm_807FDC90->unk37;
                    } else {
                        if (D_global_asm_807FDC9C->unk10 == 7) {
                            var_v1 = 1;
                        } else {
                            var_v1 = D_global_asm_807FDC9C->unk10;
                        }
                    }
                }
            }
        }
    } else {
        var_v1 = D_global_asm_807FDC9C->unk10;
    }
    if (var_v1 == 9) {
        var_v1 = 1;
    }
    return var_v1;
}
*/

void func_global_asm_8072C870(u8 arg0, u8 arg1, s32 arg2) {
    if (arg0 == 7) {
        if (func_global_asm_80725ED4(1, current_actor_pointer, D_global_asm_807FDCA0, &D_global_asm_807FDC90->unkA, &D_global_asm_807FDC90->unkC, &D_global_asm_807FDC90->unkE) == 0) {
            arg0 = 0x10;
            func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkD);
        }
    }
    D_global_asm_807FDC90->unk36 = arg0;
    func_global_asm_8072B59C(arg0, arg1, arg2);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072C918.s")

void func_global_asm_8072CFE8(s16 *arg0, s16 *arg1, s16 *arg2) {
    u8 temp_v1;
    u8 temp = D_global_asm_807FDC90->unk25 & 0x7F;
    temp_v1 = D_global_asm_807FDC98->unk20[((temp) + 1) < D_global_asm_807FDC9C->unk11 ? (u8)((temp) + 1) : 0].unk0;
    *arg0 = D_global_asm_807FDCA0->unk14[temp_v1].unk0;
    *arg1 = D_global_asm_807FDCA0->unk14[temp_v1].unk2;
    *arg2 = D_global_asm_807FDCA0->unk14[temp_v1].unk4;
}

void func_global_asm_8072D08C(void) {
    u8 sp1F;
    u8 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp1F = D_global_asm_807FDC90->unk25 & 0x7F;
    sp1E = D_global_asm_807FDC98->unk20[sp1F].unk0;
    func_global_asm_8072CFE8(&sp1C, &sp1A, &sp18);
    func_global_asm_80665DE0(sp1C, sp18, D_global_asm_807FDCA0->unk14[sp1E].unk0, D_global_asm_807FDCA0->unk14[sp1E].unk4);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072D13C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072D714.s")

extern f64 D_global_asm_8075FF10;
extern f64 D_global_asm_8075FF18;

void func_bonus_8002D7E8(u16);

/*
void func_global_asm_8072D714(Actor *arg0, s32 arg1) {
    f32 temp_f0_2;
    f32 temp_f12;
    f32 var_f2_2;
    f32 var_f2_3;
    f64 temp_f0;
    f64 var_f2;
    ActorAnimationState *temp_v1;

    if (arg0 != NULL) {
        temp_f0 = (current_actor_pointer->health - 1) * D_global_asm_8075FF10;
        if (temp_f0 > 2.0) {
            var_f2 = 2.0;
        } else {
            var_f2 = temp_f0;
        }
        current_actor_pointer->unkEE = (arg0->unkEE + 0x800) & 0xFFF;
        if (arg0 == D_global_asm_807FDC94) {
            if (func_global_asm_806CC14C(arg0->unkEE, arg0->y_rotation) >= 0x401) {
                current_actor_pointer->unkEE += 0x800;
            }
        }
        func_global_asm_8072B59C(0x37, 0, arg1);
        temp_f0_2 = arg0->unkB8;
        temp_f12 = 66.0f * (var_f2 + 0.5); // TODO: Rodata issue here... Hmm...
        if (temp_f12 < temp_f0_2) {
            var_f2_2 = temp_f0_2;
        } else {
            var_f2_2 = temp_f12;
        }
        if (var_f2_2 < 150.0f) {
            if (temp_f12 < temp_f0_2) {
                var_f2_3 = temp_f0_2;
            } else {
                var_f2_3 = temp_f12;
            }
            current_actor_pointer->unkB8 = -var_f2_3;
        } else {
            current_actor_pointer->unkB8 = -150.0f;
        }
        temp_v1 = arg0->animation_state;
        if (temp_v1 != NULL) {
            current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * (temp_v1->scale_y / D_global_asm_8075FF18);
        }
    } else {
        func_global_asm_8072B59C(0x37, 0, arg1);
        current_actor_pointer->unkB8 = -60.0f;
    }
    current_actor_pointer->unk138 &= 0xFFFF7FFF;
    current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
    if ((arg0 == NULL) || (arg0 == D_global_asm_807FDC94) || (arg0->unk58 == ACTOR_PROJECTILE_FEATHER)) {
        func_global_asm_8072D9D4();
    }
    enemies_killed += 1;
    if (current_map == MAP_RAMBI_ARENA) {
        func_bonus_8002D7E8(current_actor_pointer->unk58);
    }
}
*/

void func_global_asm_8072D99C(void) {
    current_actor_pointer->noclip_byte = 1;
    current_actor_pointer->control_state = 0x40;
    enemies_killed++;
}

void func_global_asm_8072D9D4(void) {
    drawSpriteAtPosition(&D_global_asm_8071FB34, 0.55f, current_actor_pointer->x_position, current_actor_pointer->y_position + (current_actor_pointer->unk15E * 0.5), current_actor_pointer->z_position);
}

void func_global_asm_8072DA60(void) {
    drawSpriteAtPosition(&D_global_asm_8071FB34,
                  0.55f,
                  D_global_asm_807FBD6C->x_position,
                  D_global_asm_807FBD6C->y_position,
                  D_global_asm_807FBD6C->z_position);
}

void func_global_asm_8072DAA4(void) {
    func_global_asm_80714998(2);
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(func_global_asm_80717D4C);
    func_global_asm_80714950(-0x28 - ((rand() >> 0xF) % 15));
    drawSpriteAtPosition(&D_global_asm_8071FF18,
                  (((rand() >> 0xF) % 1000) / D_global_asm_8075FF20) + 0.5,
                  current_actor_pointer->x_position,
                  current_actor_pointer->y_position,
                  current_actor_pointer->z_position);
}

void func_global_asm_8072DB68(s32 arg0) {
    u8 amount;
    s16 i;

    if (func_global_asm_806F8AD4(0xB, cc_player_index) >= 4) {
        amount = 3;
    } else {
        amount = func_global_asm_806F8AD4(0xB, cc_player_index);
    }
    changeCollectableCount(0xB, cc_player_index, -amount);
    func_global_asm_806F8BC4(0xB, 0, 0);
    playSong(0x41, 1.0f);
    for (i = 0; i < amount; i++) {
        func_global_asm_806A5DF0(0x36, player_pointer->x_position, player_pointer->y_position, player_pointer->z_position, (player_pointer->y_rotation + (i * 200)) - 200, 1, -1, 0);
    }
}

void func_global_asm_8072DC7C(u8 arg0) {
    func_global_asm_8072AB74(0x37, 0, 0, 0x32, 0);
    current_actor_pointer->shadow_opacity -= arg0;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->control_state_progress++;
        current_actor_pointer->shadow_opacity = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072DCF4.s")

/*
extern f64 D_global_asm_8075FF28;
extern f64 D_global_asm_8075FF30;

s32 func_global_asm_8072DCF4(Actor *arg0, Actor *arg1, u16 arg2) {
    s16 temp_f6;
    s16 temp_f8;
    s32 phi_a0;

    temp_f8 = ((D_global_asm_8075FF28 - func_global_asm_80665AE4(arg1->x_position, arg1->z_position, arg0->x_position, arg0->z_position)) / D_global_asm_8075FF28) * 65536.0;
    temp_f6 = (arg0->y_rotation / D_global_asm_8075FF30) * 65536.0;
    if (temp_f6 < temp_f8) {
        phi_a0 = temp_f8 - temp_f6;
    } else {
        phi_a0 = temp_f6 - temp_f8;
    }
    if ((phi_a0 < arg2) && !func_global_asm_8061CB50()) {
        return TRUE;
    }
    return FALSE;
}
*/

s32 func_global_asm_8072DE10(u16 arg0) {
    return func_global_asm_8072DCF4(current_actor_pointer, D_global_asm_807FDC94, arg0);
}

void func_global_asm_8072DE44(s32 arg0) {
    current_actor_pointer->control_state = D_global_asm_807FDC9C->unk10;
    current_actor_pointer->control_state_progress = 0;
    playActorAnimation(current_actor_pointer, arg0);
    func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
}

void func_global_asm_8072DEA8(s32 arg0, u8 arg1, Actor *arg2) {
    Actor *temp_v0;
    f32 temp_f0;
    f32 var_f2;
    f32 var_f2_2;

    func_global_asm_8072D9D4();
    playSoundAtActorPosition(current_actor_pointer, 0x1CA, 0xFF, 0x7F, 0x14);
    if (arg2 != NULL) {
        if (arg2->interactable & 4) {
            current_actor_pointer->unkEE = (arg2->unkEE + 0x800) & 0xFFF;
        } else {
            current_actor_pointer->unkEE = (arg2->y_rotation + 0x800) & 0xFFF;
        }
        func_global_asm_8072B59C(arg1, 0, arg0);
        temp_f0 = arg2->unkB8;
        if (temp_f0 > 60.0f) {
            var_f2 = temp_f0;
        } else {
            var_f2 = 60.0f;
        }
        if (var_f2 < 150.0f) {
            if (temp_f0 > 60.0f) {
                var_f2_2 = temp_f0;
            } else {
                var_f2_2 = 60.0f;
            }
            current_actor_pointer->unkB8 = -var_f2_2;
        } else {
            current_actor_pointer->unkB8 = -150.0f;
        }
    } else {
        func_global_asm_8072B59C(arg1, 0, arg0);
    }
    if (arg2 == D_global_asm_807FDC94) {
        D_global_asm_807FDC90->unk16 = D_global_asm_807FDC94->animation_state->unk0->unk10;
        temp_v0 = current_actor_pointer;
        temp_v0->object_properties_bitfield |= 0x20000000;
    }
}

void func_global_asm_8072E02C(void) {
    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, 0, 5.0f);
    current_actor_pointer->x_rotation += (-current_actor_pointer->x_rotation * D_global_asm_8075FF38);
}

// regalloc, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_12E800/func_global_asm_8072E0A8.s")

/*
u8 func_global_asm_8072E0A8(s32 arg0, s16 arg1) {
    u8 sp1F;
    f32 dx;
    f32 dz;
    s32 temp_v0_2;
    s16 phi_v1;

    dz = D_global_asm_807FDC94->z_position - current_actor_pointer->z_position;
    dx = D_global_asm_807FDC94->x_position - current_actor_pointer->x_position;
    sp1F = FALSE;
    if (((dx * dx) + (dz * dz)) < (arg0 * arg0)) {
        sp1F = TRUE;
    }
    temp_v0_2 = func_global_asm_80665DE0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
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
        && D_global_asm_807FDC94->control_state != 0x42;
}
*/

void func_global_asm_8072E1A4(u8 arg0, Actor *arg1) {
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(arg1->x_position, arg1->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position), arg0);
}

u8 func_global_asm_8072E22C(u16 arg0) {
    f32 dx = current_actor_pointer->x_position - D_global_asm_807FDC94->x_position;
    f32 dy = current_actor_pointer->y_position - D_global_asm_807FDC94->y_position;
    f32 dz = current_actor_pointer->z_position - D_global_asm_807FDC94->z_position;
    return ((dx * dx) + (dy * dy) + (dz * dz)) < (arg0 * arg0);
}

void func_global_asm_8072E2B0(Actor *arg0, f32 *x, f32 *y, f32 *z) {
    if (arg0->unkCC) {
        getBonePosition(arg0, arg0->unkCC, x, y, z);
    } else {
        *x = arg0->x_position;
        *y = arg0->y_position;
        *z = arg0->z_position;
    }
}

extern f64 D_global_asm_8075FF40;
extern f64 D_global_asm_8075FF48;

void func_global_asm_8072E320(f32 arg0) {
    f32 var_f2;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, current_actor_pointer->unk88, current_actor_pointer->unk90), 3.3f);
    var_f2 = MIN(MAX(arg0 * func_global_asm_806CC10C(current_actor_pointer->y_rotation, current_actor_pointer->unkEE), -900.0f), 900.0f);
    current_actor_pointer->x_rotation = ((var_f2 - current_actor_pointer->x_rotation) * D_global_asm_8075FF40) + current_actor_pointer->x_rotation;
    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, (func_global_asm_80665E94(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, current_actor_pointer->unk88, current_actor_pointer->unk8C, current_actor_pointer->unk90, 0x1E) * 2048.0) / D_global_asm_8075FF48, 3.3f);
}

u8 func_global_asm_8072E54C(void) {
    s32 var_v1;

    var_v1 = (D_global_asm_807FDC98->unk46 & 0x2000) == 0;
    if (var_v1 != 0) {
        var_v1 = (((rand() >> 0xF) % 1000) < 0x3E4) ^ 1;
    }
    return var_v1;
}
