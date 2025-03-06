#include <ultra64.h>
#include "functions.h"

// .data
static s8 D_critter_80029F80[] = {
    0x00,
    0x00,
    0x00,
    0x00,
};

static s8 D_critter_80029F84[] = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x08,
    0x00,
    0x01,
    0x00,
    0x04,
    0x00,
    0x02,
};

static u16 D_critter_80029F90[] = {
    0x0800,
    0x0400,
    0x0200,
    0x0100,
};

extern f32 D_critter_8002A1B0;

void func_critter_80027340(s32 arg0) {
    s32 phi_s0;
    s32 phi_s2;

    phi_s2 = arg0;
    for (phi_s0 = 2; phi_s0 > -1; phi_s0--) {
        func_global_asm_8068842C(gCurrentActorPointer, phi_s0, 1);
        func_global_asm_80688370(gCurrentActorPointer, phi_s0, 0);
        func_global_asm_806883F4(gCurrentActorPointer, phi_s0, (phi_s2 % 10) + 1, 0);
        func_global_asm_80688460(gCurrentActorPointer, phi_s0, 0);
        phi_s2 /= 10;
    }
}

typedef struct {
    s16 unk0;
} AAD_critter_80027448;

typedef struct {
    s8 unk0;
    s8 unk1; // Character Index
} Struct807446E0;

extern s16 D_global_asm_807446D0[];
extern s8 D_global_asm_807446E0[];
extern u16 D_global_asm_807FC930[];

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
    f32 temp;
    s8 sp47;
    s8 sp46;
    f32 dy;
    s16 var_v0;

    aaD = gCurrentActorPointer->additional_actor_data;
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
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk64 |= 0x20;
        if (current_map == MAP_TROFF_N_SCOFF) {
            playActorAnimation(gCurrentActorPointer, 0x39F);
            gCurrentActorPointer->control_state_progress = 4;
            if (D_global_asm_807FC930[levelIndex] < sp64) {
                func_global_asm_806F8BC4(0, 1, 0);
            }
        } else {
            func_global_asm_806F8BC4(9, 1, 0);
            if (isFlagSet(PERMFLAG_B_LOCKER_CLEARED_JAPES + levelIndex, FLAG_TYPE_PERMANENT)) {
                gCurrentActorPointer->control_state_progress = 4;
            }
            playActorAnimation(gCurrentActorPointer, 0x39E);
            func_critter_80027340(sp64);
        }
        aaD->unk0 = 0;
        D_critter_8002A1B0 = 0.0f;
        D_critter_80029F84[0] = 0;
        D_critter_80029F80[0] = 0;
    } else if (D_critter_80029F84[0]) {
        // yuck
        if (current_character_index[0] == D_global_asm_807446E0[(levelIndex + levelIndex) + 1]) {
            if ((func_global_asm_806FB418() < sp64) && (levelIndex != 7)) {
                sp64 = D_global_asm_807446E0[levelIndex + levelIndex];
                sp47 = TRUE;
            }
            if (levelIndex == 7) {
                if (D_critter_80029F84[0] == 1) {
                    sp46 = TRUE;
                } else {
                    sp64 = D_global_asm_807446E0[7 + 7];
                    sp47 = TRUE;
                }
            }
        }
    }
    gCurrentActorPointer->unk15E = 0x23;
    if (current_map != MAP_TROFF_N_SCOFF) {
        dx = gPlayerPointer->x_position - gCurrentActorPointer->x_position;
        dy = 2.0 * (gPlayerPointer->y_position - gCurrentActorPointer->y_position);
        dz = gPlayerPointer->z_position - gCurrentActorPointer->z_position;
        d = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
        if ((d < 300.0) && !isFlagSet(PERMFLAG_FTT_B_LOCKER, FLAG_TYPE_PERMANENT)) {
            func_global_asm_8070E8DC(1);
            loadText(gCurrentActorPointer, 0x1D, 0);
            playCutscene(gCurrentActorPointer, 1, 1);
            setFlag(PERMFLAG_FTT_B_LOCKER, TRUE, FLAG_TYPE_PERMANENT);
        } else if ((sp46 != 0) && (d < 200.0) && (func_global_asm_8061CB50() == 0) && (gPlayerPointer->control_state == 0x24) && (gPlayerPointer->control_state_progress == 2) && (dz > -35.0)) {
            if (dx > -27.0) {
                if (dx < 27.0) {
                    if ((((gPlayerPointer->y_rotation < 0x200)) || (gPlayerPointer->y_rotation > 0xE00))) {
                        D_critter_80029F84[0] = 2;
                        playSound(0x145, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xA, 0xA);
                        gCurrentActorPointer->control_state_progress = 0xA;
                        aaD->unk0 = 0;
                        playActorAnimation(gCurrentActorPointer, 0x3A1);
                    }
                }
            }
        }
        switch (gCurrentActorPointer->control_state_progress) {
            case 10:
                aaD->unk0++;
                if (aaD->unk0 == 0xA) {
                    func_critter_80027340(sp64);
                    playSound(0xE, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                }
                if (aaD->unk0 >= 0x2E) {
                    gCurrentActorPointer->control_state_progress = 0;
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
                    playCutscene(gCurrentActorPointer, 0x1B, 5);
                    if (func_global_asm_806FB418() < sp64) {
                        loadText(gCurrentActorPointer, 0x1D, 1);
                        playActorAnimation(gCurrentActorPointer, 0x3A1);
                        gCurrentActorPointer->control_state_progress = 1;
                    } else {
                        setFlag(levelIndex + PERMFLAG_B_LOCKER_CLEARED_JAPES, TRUE, FLAG_TYPE_PERMANENT);
                        var_v0 = (sp47) ? levelIndex + 2 : 2;
                        loadText(gCurrentActorPointer, 0x1D, var_v0);
                        playActorAnimation(gCurrentActorPointer, 0x3A0);
                        gCurrentActorPointer->control_state_progress = 2;
                        aaD->unk0 = 0;
                    }
                }
                break;
            case 1:
                if (d > 110.0) {
                    gCurrentActorPointer->control_state_progress = 0;
                }
                break;
            case 2:
                if (!func_global_asm_8061CB38() && (aaD->unk0 >= 0x14)) {
                    if (aaD->unk0 == 0x32) {
                        playActorAnimation(gCurrentActorPointer, 0x3A2);
                    }
                    if (aaD->unk0 >= 0x3D) {
                        func_global_asm_807149B8(0);
                        func_global_asm_807149FC(1);
                        drawSpriteAtPosition(
                            &D_global_asm_80720A7C,
                            0.5f,
                            ((func_global_asm_806119FC() * 35.0) + gCurrentActorPointer->x_position) - 15.0,
                            (func_global_asm_806119FC() * 35.0) + gCurrentActorPointer->y_position,
                            ((func_global_asm_806119FC() * 35.0) + gCurrentActorPointer->z_position) - 15.0
                        );
                    }
                    if (aaD->unk0 >= 0x51) {
                        gCurrentActorPointer->animation_state->scale[0] *= 0.9;
                        gCurrentActorPointer->animation_state->scale[1] = gCurrentActorPointer->animation_state->scale[0];
                        gCurrentActorPointer->animation_state->scale[2] = gCurrentActorPointer->animation_state->scale[0];
                    }
                    aaD->unk0++;
                } else {
                    if (aaD->unk0 < 0x14) {
                        aaD->unk0++;
                    }
                }
                break;
            case 3:
                gCurrentActorPointer->animation_state->scale[0] = 0.0f;
                gCurrentActorPointer->animation_state->scale[1] = 0.0f;
                gCurrentActorPointer->animation_state->scale[2] = 0.0f;
                func_global_asm_80605314(gCurrentActorPointer, 0);
                gCurrentActorPointer->control_state_progress = 4;
                func_global_asm_807149B8(0);
                func_global_asm_807149FC(1);
                drawSpriteAtPosition(
                    &D_global_asm_8071FE08,
                    0.5f,
                    gCurrentActorPointer->x_position,
                    gCurrentActorPointer->y_position + 7.0f,
                    gCurrentActorPointer->z_position
                );
                break;
            case 4:
                gCurrentActorPointer->animation_state->scale[0] = 0.0f;
                gCurrentActorPointer->animation_state->scale[1] = 0.0f;
                gCurrentActorPointer->animation_state->scale[2] = 0.0f;
                break;
        }
        D_critter_8002A1B0 = d;
        if (newly_pressed_input[0] != 0) {
            if (newly_pressed_input[0] & D_critter_80029F90[D_critter_80029F80[0]]) {
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
    renderActor(gCurrentActorPointer, 0);
    if (gCurrentActorPointer->control_state_progress != 4) {
        gCurrentActorPointer->object_properties_bitfield |= 4;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~4;
        gCurrentActorPointer->noclip_byte = 1;
    }
}

void func_critter_80027DC0(void) {
    s32 temp[2];
    Actor *sp34;
    f32 dx;
    f32 dz;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80604CBC(gCurrentActorPointer, 0x10F, 0x46, 1, 0, 0x1E, 1.0f, 0);
        gCurrentActorPointer->control_state = 0;
        // Is the camera not unlocked?
        if (!isFlagSet(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, FLAG_TYPE_PERMANENT)) {
            gCurrentActorPointer->control_state = 1;
        // Is the Rareware GB room open?
        } else if (isFlagSet(PERMFLAG_PROGRESS_RAREWARE_ROOM_OPEN, FLAG_TYPE_PERMANENT)) {
            playActorAnimation(gCurrentActorPointer, 0x2B5);
        // Has the player photographed all 20 fairies?
        } else if (countSetFlags(PERMFLAG_ITEM_FAIRY_JAPES_POOL, 20, FLAG_TYPE_PERMANENT) == 20) {
            playActorAnimation(gCurrentActorPointer, 0x2B5);
            gCurrentActorPointer->control_state = 3;
        }
    }
    dx = gCurrentActorPointer->x_position - gPlayerPointer->x_position;
    dz = gCurrentActorPointer->z_position - gPlayerPointer->z_position;
    switch (gCurrentActorPointer->control_state) {
        case 1:
            if (((SQ(dx) + SQ(dz)) < SQ(100.0f)) != 0) {
                // Unlock the camera
                setFlag(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, TRUE, FLAG_TYPE_PERMANENT);
                playCutscene(gPlayerPointer, 0, 1);
                func_global_asm_80629174();
                gCurrentActorPointer->control_state = 2;
            }
            break;
        case 2:
            sp34 = gCurrentActorPointer;
            if (gCurrentActorPointer->control_state_progress != 0) {
                gCurrentActorPointer->control_state_progress++;
                if (gCurrentActorPointer->control_state_progress < 0x4B) {
                    gCurrentActorPointer = gPlayerPointer;
                    if ((object_timer & 3) == 0) {
                        func_global_asm_80684900(0);
                    }
                    gCurrentActorPointer = sp34;
                } else {
                    gCurrentActorPointer = gPlayerPointer;
                    gPlayerPointer->control_state = 0x2D;
                    gPlayerPointer->control_state_progress = 0;
                    playAnimation(gPlayerPointer, 0x42);
                    playSoundAtActorPosition(gPlayerPointer, 0xF2, 0xFF, 0x7F, 0);
                    gCurrentActorPointer = sp34;
                    gCurrentActorPointer->control_state_progress = 0;
                    func_global_asm_80605314(gPlayerPointer, 1);
                }
            } else if (func_global_asm_80629148()) {
                gCurrentActorPointer->control_state_progress = 1;
                func_global_asm_80604CBC(gPlayerPointer, 0x104, 0x3C, 1, 1, 0xFF, 1.0f, 0);
                func_global_asm_806F8BC4(6, 0, 0);
                changeCollectableCount(6, extra_player_info_pointer->unk1A4, 999);
            }
            break;
        case 3:
            if (((SQ(dx) + SQ(dz)) < SQ(100.0f)) != 0) {
                playCutscene(gCurrentActorPointer, 1, 1);
                func_global_asm_80629174();
                gCurrentActorPointer->control_state = 4;
            }
            break;
        case 4:
            break;
    }
    renderActor(gCurrentActorPointer, 0);
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

    aaD = gCurrentActorPointer->additional_actor_data;
    sp40 = gCurrentActorPointer->animation_state->unk0;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->control_state = 0x78;
        if (isFlagSet(PERMFLAG_PROGRESS_RAREWARE_ROOM_OPEN, FLAG_TYPE_PERMANENT)) {
            if (!isFlagSet(GLOBALFLAG_UNK_23, FLAG_TYPE_GLOBAL)) {
                gCurrentActorPointer->control_state = 1;
            } else {
                if (!isFlagSet(PERMFLAG_UNK_18A, FLAG_TYPE_PERMANENT)) {
                    if (isFlagSet(GLOBALFLAG_UNK_24, FLAG_TYPE_GLOBAL)) {
                        gCurrentActorPointer->control_state = 0xA;
                    } else {
                        gCurrentActorPointer->control_state = 0x64;
                    }
                }
            }
            playActorAnimation(gCurrentActorPointer, 0x43B);
        } else {
            gCurrentActorPointer->control_state = 0;
        }
        aaD->unk20 = gCurrentActorPointer->x_position;
        aaD->unk24 = gCurrentActorPointer->y_position;
        aaD->unk28 = gCurrentActorPointer->z_position;
        aaD->unk4 = 0.028571429f;
        aaD->unk0 = 2.0f;
        aaD->unk14 = aaD->unk20;
        aaD->unk1C = aaD->unk28;
    }
    dx = gCurrentActorPointer->x_position - gPlayerPointer->x_position;
    dz = gCurrentActorPointer->z_position - gPlayerPointer->z_position;
    if (gCurrentActorPointer->control_state != 1) {
        gCurrentActorPointer->y_rotation -= func_global_asm_806CC10C(func_global_asm_80665DE0(gPlayerPointer->x_position, gPlayerPointer->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position), gCurrentActorPointer->y_rotation) >> 3;
    }
    gCurrentActorPointer->unk15E = 0xF;
    switch (gCurrentActorPointer->control_state) {
        case 0x0:
            if (isFlagSet(PERMFLAG_PROGRESS_RAREWARE_ROOM_OPEN, FLAG_TYPE_PERMANENT)) {
                playActorAnimation(gCurrentActorPointer, 0x43B);
                gCurrentActorPointer->control_state = 1;
            }
            break;
        case 0x64:
            if (((SQ(dx) + SQ(dz)) < SQ(50.0f)) != 0) {
                if (newly_pressed_input[0] & 0x8000) {
                    playCutscene(gCurrentActorPointer, 4, 1);
                    func_global_asm_80629174();
                    gCurrentActorPointer->control_state = 0x65;
                }
            }
            if (isFlagSet(GLOBALFLAG_UNK_24, FLAG_TYPE_GLOBAL)) {
                gCurrentActorPointer->control_state = 0xA;
            }
            break;
        case 0x65:
            if (func_global_asm_8061CB50() == 0) {
                gCurrentActorPointer->control_state = 0x64;
            }
            break;
        case 0x1:
            var_f12 = sp40->unk4 / 19.0;
            if (var_f12 < aaD->unk0) {
                aaD->unk8 = gCurrentActorPointer->x_position;
                aaD->unkC = aaD->unk24;
                aaD->unk10 = gCurrentActorPointer->z_position;
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
            gCurrentActorPointer->x_position = aaD->unk8 + (var_f12 * (aaD->unk14 - aaD->unk8));
            gCurrentActorPointer->z_position = aaD->unk10 + (var_f12 * (aaD->unk1C - aaD->unk10));
            if (D_global_asm_807FBD70 == 4) {
                playActorAnimation(gCurrentActorPointer, 0x43C);
                gCurrentActorPointer->control_state = 2;
                aaD->unk0 = 0.0f;
            }
            break;
        case 0x2:
            aaD->unk0 += 1.0;
            if (aaD->unk0 > 49.0) {
                playCutscene(gCurrentActorPointer, 2, 1);
                func_global_asm_80629174();
                aaD->unk0 = 0;
                gCurrentActorPointer->control_state = 0x64;
            } else if (aaD->unk0 < 20.0) {
                d = sqrtf(SQ(dx) + SQ(dz));
                if (d > 1.0) {
                    temp_f4 = 3.0 / d;
                    gCurrentActorPointer->x_position += dx * temp_f4;
                    gCurrentActorPointer->z_position += dz * temp_f4;
                }
            }
            break;
        case 0xA:
            if (((SQ(dx) + SQ(dz)) < SQ(50.0f)) != 0) {
                gCurrentActorPointer->control_state = 0xB;
                playCutscene(gCurrentActorPointer, 3, 1);
            }
            break;
        case 0xB:
            break;
    }
    func_global_asm_8072881C(0, &gCurrentActorPointer->unk160);
    if (gCurrentActorPointer->control_state == 0) {
        gCurrentActorPointer->object_properties_bitfield &= ~4;
    } else {
        gCurrentActorPointer->object_properties_bitfield |= 4;
        func_global_asm_80665564(gCurrentActorPointer, 0.0f);
        func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0x23, 0xF, 1, 0x4B, 0x78, gCurrentActorPointer->y_rotation, 1.0f);
    }
    renderActor(gCurrentActorPointer, 0);
}
*/
