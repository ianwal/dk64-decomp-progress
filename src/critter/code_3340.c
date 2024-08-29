#include <ultra64.h>
#include "functions.h"

extern f32 D_critter_8002A1B0;

s32 func_global_asm_8061CB38();

void func_critter_80027340(s32 arg0) {
    s32 phi_s0;
    s32 phi_s2;

    phi_s2 = arg0;
    for (phi_s0 = 2; phi_s0 > -1; phi_s0--) {
        func_global_asm_8068842C(current_actor_pointer, phi_s0, 1);
        func_global_asm_80688370(current_actor_pointer, phi_s0, 0);
        func_global_asm_806883F4(current_actor_pointer, phi_s0, (phi_s2 % 10) + 1, 0);
        func_global_asm_80688460(current_actor_pointer, phi_s0, 0);
        phi_s2 /= 10;
    }
}

// Jumptable, close
// https://decomp.me/scratch/wrAMt
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80027448.s")

typedef struct {
    s16 unk0;
} AAD_critter_80027448;

typedef struct {
    s8 unk0;
    s8 unk1; // Character Index
} Struct807446E0;

extern s16 D_global_asm_807446D0[];
extern Struct807446E0 D_global_asm_807446E0[];
extern u16 D_global_asm_807FC930[];
extern s8 D_critter_80029F80[];
extern s8 D_critter_80029F84[];
extern u16 D_critter_80029F90[];
extern s32 D_global_asm_8071FE08; // TODO: Datatype
extern s32 D_global_asm_80720A7C; // TODO: Datatype

/*
void func_critter_80027448(void) {
    s32 levelIndex; // sp6C
    s32 pad; // sp68
    s32 sp64; // sp64
    AAD_critter_80027448 *aaD; // sp60
    f32 dx; // sp5C
    s32 pad2; // sp58
    f32 dz; // sp54
    f32 d; // sp50
    s32 pad3;
    s32 pad4;
    s8 sp47;
    s8 sp46;
    f32 dy;
    s16 var_v0;

    aaD = current_actor_pointer->additional_actor_data;
    sp46 = 0;
    sp47 = 0;
    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    if (levelIndex >= 8) {
        levelIndex = 7;
    }
    if (current_map == MAP_TROFF_N_SCOFF) {
        sp64 = D_global_asm_807446C0[levelIndex];
    } else {
        sp64 = D_global_asm_807446D0[levelIndex];
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk64 |= 0x20;
        if (current_map == MAP_TROFF_N_SCOFF) {
            playActorAnimation(current_actor_pointer, 0x39F);
            current_actor_pointer->control_state_progress = 4;
            if (D_global_asm_807FC930[levelIndex] < sp64) {
                func_global_asm_806F8BC4(0, 1, 0);
            }
        } else {
            func_global_asm_806F8BC4(9, 1, 0);
            if (isFlagSet(0x1CD + levelIndex, FLAG_TYPE_PERMANENT)) {
                current_actor_pointer->control_state_progress = 4;
            }
            playActorAnimation(current_actor_pointer, 0x39E);
            func_critter_80027340(sp64);
        }
        aaD->unk0 = 0;
        D_critter_8002A1B0 = 0.0f;
        D_critter_80029F84[0] = 0;
        D_critter_80029F80[0] = 0;
    } else if (D_critter_80029F84[0] != 0) {
        if (current_character_index[0] == D_global_asm_807446E0[levelIndex].unk1) {
            if ((func_global_asm_806FB418() < sp64) && (levelIndex != 7)) {
                sp64 = D_global_asm_807446E0[levelIndex].unk0;
                sp47 = 1;
            }
            if (levelIndex == 7) {
                if (D_critter_80029F84[0] == 1) {
                    sp46 = 1;
                } else {
                    sp47 = 1;
                    sp64 = D_global_asm_807446E0[7].unk0;
                }
            }
        }
    }
    current_actor_pointer->unk15E = 0x23;
    if (current_map != MAP_TROFF_N_SCOFF) {
        dx = player_pointer->x_position - current_actor_pointer->x_position;
        dy = 2.0 * (player_pointer->y_position - current_actor_pointer->y_position);
        dz = player_pointer->z_position - current_actor_pointer->z_position;
        d = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
        if ((d < 300.0) && !isFlagSet(0x17E, FLAG_TYPE_PERMANENT)) {
            func_global_asm_8070E8DC(1);
            loadText(current_actor_pointer, 0x1D, 0);
            playCutscene(current_actor_pointer, 1, 1);
            setFlag(0x17E, TRUE, FLAG_TYPE_PERMANENT);
        } else if ((sp46 != 0) && (d < 200.0) && (func_global_asm_8061CB50() == 0) && (player_pointer->control_state == 0x24) && (player_pointer->control_state_progress == 2) && (dz > -35.0)) {
            if ((dx > -27.0) && (dx < 27.0) && ((((player_pointer->y_rotation < 0x200) != 0)) || (player_pointer->y_rotation >= 0xE01))) {
                D_critter_80029F84[0] = 2;
                playSound(0x145, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xA, 0xA);
                current_actor_pointer->control_state_progress = 0xA;
                aaD->unk0 = 0;
                playActorAnimation(current_actor_pointer, 0x3A1);
            }
        }
        switch (current_actor_pointer->control_state_progress) {
            case 10:
                aaD->unk0++;
                if (aaD->unk0 == 0xA) {
                    func_critter_80027340(sp64);
                    playSound(0xE, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                }
                if (aaD->unk0 >= 0x2E) {
                    current_actor_pointer->control_state_progress = 0;
                    if (func_global_asm_806FB418() < sp64) {

                    }
                }
                break;
            case 0:
                if ((current_map == MAP_HELM_LOBBY) && (*current_character_index != 4)) {
                    D_critter_8002A1B0 = 0.0f;
                }
                if ((d < 70.0) && (D_critter_8002A1B0 >= 70.0)) {
                    func_global_asm_8070E8DC(1);
                    playCutscene(current_actor_pointer, 0x1B, 5);
                    if (func_global_asm_806FB418() < sp64) {
                        loadText(current_actor_pointer, 0x1D, 1);
                        playActorAnimation(current_actor_pointer, 0x3A1);
                        current_actor_pointer->control_state_progress = 1;
                    } else {
                        setFlag(levelIndex + 0x1CD, TRUE, FLAG_TYPE_PERMANENT);
                        var_v0 = (sp47) ? levelIndex + 2 : 2;
                        loadText(current_actor_pointer, 0x1D, var_v0);
                        playActorAnimation(current_actor_pointer, 0x3A0);
                        current_actor_pointer->control_state_progress = 2;
                        aaD->unk0 = 0;
                    }
                }
                break;
            case 1:
                if (d > 110.0) {
                    current_actor_pointer->control_state_progress = 0;
                }
                break;
            case 2:
                if (!func_global_asm_8061CB38() && (aaD->unk0 >= 0x14)) {
                    if (aaD->unk0 == 0x32) {
                        playActorAnimation(current_actor_pointer, 0x3A2);
                    }
                    if (aaD->unk0 >= 0x3D) {
                        func_global_asm_807149B8(0);
                        func_global_asm_807149FC(1);
                        drawSpriteAtPosition(
                            &D_global_asm_80720A7C,
                            0.5f,
                            ((func_global_asm_806119FC() * 35.0) + current_actor_pointer->x_position) - 15.0,
                            (func_global_asm_806119FC() * 35.0) + current_actor_pointer->y_position,
                            ((func_global_asm_806119FC() * 35.0) + current_actor_pointer->z_position) - 15.0
                        );
                    }
                    if (aaD->unk0 >= 0x51) {
                        current_actor_pointer->animation_state->scale[0] *= 0.9;
                        current_actor_pointer->animation_state->scale[1] = current_actor_pointer->animation_state->scale[0];
                        current_actor_pointer->animation_state->scale[2] = current_actor_pointer->animation_state->scale[0];
                    }
                    aaD->unk0++;
                } else {
                    if (aaD->unk0 < 0x14) {
                        aaD->unk0++;
                    }
                }
                break;
            case 3:
                current_actor_pointer->animation_state->scale[0] = 0.0f;
                current_actor_pointer->animation_state->scale[1] = 0.0f;
                current_actor_pointer->animation_state->scale[2] = 0.0f;
                func_global_asm_80605314(current_actor_pointer, 0);
                current_actor_pointer->control_state_progress = 4;
                func_global_asm_807149B8(0);
                func_global_asm_807149FC(1);
                drawSpriteAtPosition(
                    &D_global_asm_8071FE08,
                    0.5f,
                    current_actor_pointer->x_position,
                    current_actor_pointer->y_position + 7.0f,
                    current_actor_pointer->z_position
                );
                break;
            case 4:
                current_actor_pointer->animation_state->scale[0] = 0.0f;
                current_actor_pointer->animation_state->scale[1] = 0.0f;
                current_actor_pointer->animation_state->scale[2] = 0.0f;
                break;
        }
        D_critter_8002A1B0 = d;
        if (newly_pressed_input[0] != 0) {
            if (D_critter_80029F90[D_critter_80029F80[0]] & newly_pressed_input[0]) {
                D_critter_80029F80[0]++;
                if (D_critter_80029F80[0] == 4) {
                    D_critter_80029F80[0] = 0;
                    playSound(0x1EE, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                    D_critter_80029F84[0] = 1;
                }
            } else {
                D_critter_80029F80[0] = 0;
            }
        }
    }
    renderActor(current_actor_pointer, 0);
    if (current_actor_pointer->control_state_progress != 4) {
        current_actor_pointer->object_properties_bitfield |= 4;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~4;
        current_actor_pointer->noclip_byte = 1;
    }
}
*/

void func_critter_80027DC0(void) {
    s32 temp[2];
    Actor *sp34;
    f32 dx;
    f32 dz;

    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80604CBC(current_actor_pointer, 0x10F, 0x46, 1, 0, 0x1E, 1.0f, 0);
        current_actor_pointer->control_state = 0;
        // Is the camera not unlocked?
        if (!isFlagSet(0x179, FLAG_TYPE_PERMANENT)) {
            current_actor_pointer->control_state = 1;
        // Is the Rareware GB room open?
        } else if (isFlagSet(0x189, FLAG_TYPE_PERMANENT)) {
            playActorAnimation(current_actor_pointer, 0x2B5);
        // Has the player photographed all 20 fairies?
        } else if (countSetFlags(0x24D, 20, FLAG_TYPE_PERMANENT) == 20) {
            playActorAnimation(current_actor_pointer, 0x2B5);
            current_actor_pointer->control_state = 3;
        }
    }
    dx = current_actor_pointer->x_position - player_pointer->x_position;
    dz = current_actor_pointer->z_position - player_pointer->z_position;
    switch (current_actor_pointer->control_state) {
        case 1:
            if ((((dx * dx) + (dz * dz)) < 10000.0f) != 0) {
                // Unlock the camera
                setFlag(0x179, TRUE, FLAG_TYPE_PERMANENT);
                playCutscene(player_pointer, 0, 1);
                func_global_asm_80629174();
                current_actor_pointer->control_state = 2;
            }
            break;
        case 2:
            sp34 = current_actor_pointer;
            if (current_actor_pointer->control_state_progress != 0) {
                current_actor_pointer->control_state_progress++;
                if (current_actor_pointer->control_state_progress < 0x4B) {
                    current_actor_pointer = player_pointer;
                    if ((object_timer & 3) == 0) {
                        func_global_asm_80684900(0);
                    }
                    current_actor_pointer = sp34;
                } else {
                    current_actor_pointer = player_pointer;
                    player_pointer->control_state = 0x2D;
                    player_pointer->control_state_progress = 0;
                    playAnimation(player_pointer, 0x42);
                    playSoundAtActorPosition(player_pointer, 0xF2, 0xFF, 0x7F, 0);
                    current_actor_pointer = sp34;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80605314(player_pointer, 1);
                }
            } else if (func_global_asm_80629148()) {
                current_actor_pointer->control_state_progress = 1;
                func_global_asm_80604CBC(player_pointer, 0x104, 0x3C, 1, 1, 0xFF, 1.0f, 0);
                func_global_asm_806F8BC4(6, 0, 0);
                changeCollectableCount(6, extra_player_info_pointer->unk1A4, 999);
            }
            break;
        case 3:
            if ((((dx * dx) + (dz * dz)) < 10000.0f) != 0) {
                playCutscene(current_actor_pointer, 1, 1);
                func_global_asm_80629174();
                current_actor_pointer->control_state = 4;
            }
            break;
        case 4:
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// Jumptable, doable, float, regalloc, close
// https://decomp.me/scratch/YxzWl
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80028120.s")

s32 func_global_asm_8072881C(s32, f64 *);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8; // x
    f32 unkC; // y
    f32 unk10; // z
    f32 unk14; // x
    f32 unk18; // y
    f32 unk1C; // z
    f32 unk20; // x
    f32 unk24; // y
    f32 unk28; // z
} AAD_80028120;

extern u8 D_global_asm_807FBD70;

/*
void func_critter_80028120(void) {
    f32 dx;
    f32 dz;
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f12; // 54
    f32 d;
    f32 var_f0;
    s32 sp48;
    AAD_80028120 *aaD;
    AnimationStateUnk0 *sp40;

    aaD = current_actor_pointer->additional_actor_data;
    sp40 = current_actor_pointer->animation_state->unk0;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->control_state = 0x78;
        if (isFlagSet(0x189, FLAG_TYPE_PERMANENT)) {
            if (!isFlagSet(0x23, FLAG_TYPE_GLOBAL)) {
                current_actor_pointer->control_state = 1;
            } else {
                if (!isFlagSet(0x18A, FLAG_TYPE_PERMANENT)) {
                    if (isFlagSet(0x24, FLAG_TYPE_GLOBAL)) {
                        current_actor_pointer->control_state = 0xA;
                    } else {
                        current_actor_pointer->control_state = 0x64;
                    }
                }
            }
            playActorAnimation(current_actor_pointer, 0x43B);
        } else {
            current_actor_pointer->control_state = 0;
        }
        aaD->unk20 = current_actor_pointer->x_position;
        aaD->unk24 = current_actor_pointer->y_position;
        aaD->unk28 = current_actor_pointer->z_position;
        aaD->unk4 = 0.028571429f;
        aaD->unk0 = 2.0f;
        aaD->unk14 = aaD->unk20;
        aaD->unk1C = aaD->unk28;
    }
    dx = current_actor_pointer->x_position - player_pointer->x_position;
    dz = current_actor_pointer->z_position - player_pointer->z_position;
    if (current_actor_pointer->control_state != 1) {
        current_actor_pointer->y_rotation -= func_global_asm_806CC10C(func_global_asm_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position), current_actor_pointer->y_rotation) >> 3;
    }
    current_actor_pointer->unk15E = 0xF;
    switch (current_actor_pointer->control_state) {
        case 0x0:
            if (isFlagSet(0x189, FLAG_TYPE_PERMANENT)) {
                playActorAnimation(current_actor_pointer, 0x43B);
                current_actor_pointer->control_state = 1;
            }
            break;
        case 0x64:
            if ((((dx * dx) + (dz * dz)) < 2500.0f) != 0) {
                if (newly_pressed_input[0] & 0x8000) {
                    playCutscene(current_actor_pointer, 4, 1);
                    func_global_asm_80629174();
                    current_actor_pointer->control_state = 0x65;
                }
            }
            if (isFlagSet(0x24, FLAG_TYPE_GLOBAL)) {
                current_actor_pointer->control_state = 0xA;
            }
            break;
        case 0x65:
            if (func_global_asm_8061CB50() == 0) {
                current_actor_pointer->control_state = 0x64;
            }
            break;
        case 0x1:
            var_f12 = sp40->unk4 / 19.0;
            if (var_f12 < aaD->unk0) {
                aaD->unk8 = current_actor_pointer->x_position;
                aaD->unkC = aaD->unk24;
                aaD->unk10 = current_actor_pointer->z_position;
                sp48 = func_global_asm_806119FC() * 4096.0;
                temp_f2 = func_global_asm_806119FC() * 65.0;
                temp_f4 = (func_global_asm_80612790(sp48) * temp_f2);
                aaD->unk14 = aaD->unk20 + temp_f4;
                aaD->unk18 = aaD->unk24;
                temp_f4 = (func_global_asm_80612794(sp48) * temp_f2);
                aaD->unk1C = aaD->unk28 + temp_f4;
            }
            aaD->unk0 = var_f12;
            var_f12 = (var_f12 - 0.5) * 2.5;
            if (var_f12 > 1.0) {
                var_f12 = 1.0f;
            }
            if (var_f12 < 0.0) {
                var_f12 = 0.0f;
            }
            current_actor_pointer->x_position = aaD->unk8 + (var_f12 * (aaD->unk14 - aaD->unk8));
            current_actor_pointer->z_position = aaD->unk10 + (var_f12 * (aaD->unk1C - aaD->unk10));
            if (D_global_asm_807FBD70 == 4) {
                playActorAnimation(current_actor_pointer, 0x43C);
                current_actor_pointer->control_state = 2;
                aaD->unk0 = 0.0f;
            }
            break;
        case 0x2:
            aaD->unk0 += 1.0;
            if (aaD->unk0 > 49.0) {
                playCutscene(current_actor_pointer, 2, 1);
                func_global_asm_80629174();
                aaD->unk0 = 0;
                current_actor_pointer->control_state = 0x64;
            } else if (aaD->unk0 < 20.0) {
                d = sqrtf((dx * dx) + (dz * dz));
                if (d > 1.0) {
                    temp_f4 = 3.0 / d;
                    current_actor_pointer->x_position += dx * temp_f4;
                    current_actor_pointer->z_position += dz * temp_f4;
                }
            }
            break;
        case 0xA:
            if ((((dx * dx) + (dz * dz)) < 2500.0f) != 0) {
                current_actor_pointer->control_state = 0xB;
                playCutscene(current_actor_pointer, 3, 1);
            }
            break;
        case 0xB:
            break;
    }
    func_global_asm_8072881C(0, &current_actor_pointer->unk160);
    if (current_actor_pointer->control_state == 0) {
        current_actor_pointer->object_properties_bitfield &= ~4;
    } else {
        current_actor_pointer->object_properties_bitfield |= 4;
        func_global_asm_80665564(current_actor_pointer, 0.0f);
        func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x23, 0xF, 1, 0x4B, 0x78, current_actor_pointer->y_rotation, 1.0f);
    }
    renderActor(current_actor_pointer, 0);
}
*/
