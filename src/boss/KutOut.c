#include "common.h"

// .data
static s16 D_boss_80035B00[] = {
    0x0000,
    0x026C,
    0x0000,
    0xFD94,
};

static s16 D_boss_80035B08[] = {
    0x026C,
    0x0000,
    0xFD94,
    0x0000,
};

static s16 D_boss_80035B10[] = {
    0x0800,
    0x0C00,
    0x0000,
    0x0400,
};

static s16 D_boss_80035B18[] = {
    0x0000,
    0xFFB5,
    0x0000,
    0x004B,
};

static s16 D_boss_80035B20[] = {
    0xFFB5,
    0x0000,
    0x004B,
    0x0000,
};

static s8 D_boss_80035B28 = -1;

static s16 D_boss_80035B2C = 0x0000;

static u8 D_boss_80035B30[] = {7, 3, 1, 0}; // TODO: last 0 is padding?

static u8 D_boss_80035B34 = 0;
static u8 D_boss_80035B38 = 0xFF; // TODO: Just a u8 with padding?

static f32 D_boss_80035B3C = 0.0f;

static s8 D_boss_80035B40 = 0;
static s8 D_boss_80035B44[] = {2, 3, 4, 0}; // TODO: last 0 is padding?

static s8 D_boss_80035B48[] = {1, 0, 0, 0}; // TODO: Just a u8 with padding?

static s16 D_boss_80035B4C[] = {2, 3, 4, 5, 6, 0}; // TODO: last 0 is padding?

static u8 D_boss_80035B58[] = {
    0x02,
    0x01,
    0x03,
    0x04,
    0x00, // TODO: Padding?
    0x00, // TODO: Padding?
    0x00, // TODO: Padding?
    0x00, // TODO: Padding?
};

static s16 D_boss_80035B60[4] = {
    0x00DC,
    0x00DD,
    0x00DE,
    0x00DF,
};

static u8 D_boss_80035B68 = 0;
static u8 D_boss_80035B6C = 0;

static s16 D_boss_80035B70 = 0;

static s16 D_boss_80035B74 = 0x0078;

// .rodata
static const u8 D_boss_80036B80[4] = {0x3D, 0xCC, 0xCC, 0xCD}; // TODO: Unused?

// Jumptable, 4200 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KutOut/func_boss_80031AA0.s")

void func_global_asm_806C8E58(s16);
extern s8 D_80036DC0;
extern f32 D_boss_80036DC4;
extern u8 D_global_asm_807FBDC4;


typedef struct KKOPaaD {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s8 unk12;
    s8 unk13;
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 unk17;
} KKOPaaD;

typedef struct KKOSegmentPaaD {
    Actor *unk0;
    s8 unk4;
    s8 unk5;
} KKOSegmentPaaD;

/*
void func_boss_80031AA0(void) {
    Actor *actor;
    KKOPaaD *PaaD;
    KKOSegmentPaaD *SegPaaD;
    s32 i; // 70
    s8 sp6B;
    s8 sp6A;
    s8 sp69;
    s8 sp68;
    s8 sp67;
    s16 j;
    s32 sp5C;
    f32 pos_z;
    f32 pos_x;
    f32 dx;
    f32 dz;
    s32 temp_v0_6;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_t0_3;
    
    PaaD = gCurrentActorPointer->AAD_as_array[0];
    sp67 = FALSE;
    sp68 = FALSE;
    sp6A = FALSE;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_boss_80035B28 = 0xF;
        D_boss_80035B34 = 0;
        D_boss_80035B3C = 0.0f;
        PaaD->unkC = 0x1E;
        PaaD->unkE = 1;
        PaaD->unk0 = gCurrentActorPointer->y_position;
        PaaD->unk14 = 0;
        D_boss_80035B6C = 0;
        PaaD->unk12 = 0;
        D_boss_80035B70 = 5;
        for (i = 0; i < 8; i++) {
            if (spawnActor(ACTOR_BOSS_KUTOUT_SEGMENT, D_boss_80035B60[i >> 1])) {
                SegPaaD = gLastSpawnedActor->PaaD;
                SegPaaD->unk0 = gCurrentActorPointer;
                SegPaaD->unk4 = i >> 1;
                SegPaaD->unk5 = i & 1;
                gLastSpawnedActor->y_position = gCurrentActorPointer->y_position + 50.0f;
                gLastSpawnedActor->animation_state->scale_x = 0.1f;
                gLastSpawnedActor->animation_state->scale_y = 0.1f;
                gLastSpawnedActor->animation_state->scale_z = 0.1f;
                gLastSpawnedActor->object_properties_bitfield |= 0x400;
            }
        }
        D_boss_80036DC4 = 160000.0f;
        D_80036DC0 = 0;
        if (gPlayerPointer != NULL) {
            gPlayerPointer->control_state = 0x77;
            gPlayerPointer->control_state_progress = 0;
        }
        gCurrentActorPointer->draw_distance = 0x7D0;
        func_global_asm_8066635C(gCurrentActorPointer, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, &gCurrentActorPointer->floor);
        gCurrentActorPointer->control_state = 2;
        playCutscene(NULL, 3, 1U);
    }
    switch (gCurrentActorPointer->control_state) {
    case 3:
        break;
    case 0:
        gPlayerPointer->x_position = gCurrentActorPointer->x_position;
        gPlayerPointer->y_position = gCurrentActorPointer->y_position;
        gPlayerPointer->z_position = gCurrentActorPointer->z_position;
        if (D_boss_80035B38 == -1U) {
            D_boss_80035B38 = gPlayerPointer->noclip_byte;
        }
        gPlayerPointer->object_properties_bitfield &= ~4;
        gPlayerPointer->noclip_byte = 1;
        if (D_global_asm_807FBDC4 != 0) {
            sp5C = D_boss_80035B44[D_80036DC0];
            gCurrentActorPointer->unk146 = 0;
            for (i = 4; i > D_80036DC0; i--) {
                func_global_asm_8068A764(gCurrentActorPointer, D_boss_80035B58[D_boss_80035B48[i]]);

            }
            D_80036DC0++;
            sp5C = D_boss_80035B4C[sp5C];
            func_global_asm_806C8E58(sp5C);
            func_global_asm_806F09F0(gPlayerPointer, sp5C);
            gPlayerPointer->control_state = 0xC;
            gPlayerPointer->control_state_progress = 0;
            func_global_asm_8067AAB8(gCurrentActorPointer, gPlayerPointer, 0, 180.0f, 0x46);
            gCurrentActorPointer->control_state = 1;
            gPlayerPointer->noclip_byte = D_boss_80035B38;
        }
        break;
    case 1:
        gPlayerPointer->object_properties_bitfield |= 4;
        dx = gPlayerPointer->x_position - gCurrentActorPointer->x_position;
        dz = gPlayerPointer->z_position - gCurrentActorPointer->z_position;
        if (((dx > 700.0) || (dx < -700.0)) && ((dz > 700.0) || (dz < -700.0))) {
            if (D_80036DC0 < 5) {
                gCurrentActorPointer->control_state = 0;
                playCutscene(NULL, 2, 1U);
            } else {
                func_global_asm_805FF378(MAP_TROFF_N_SCOFF, 2);
                gCurrentActorPointer->control_state = 3;
            }
        }
        break;
    case 2:
        PaaD->unkE--;
        if (PaaD->unkE < 0) {
            gCurrentActorPointer->control_state = 0;
            func_global_asm_806C8E58(4);
            func_global_asm_806F09F0(gPlayerPointer, 4U);
            PaaD->unk13 = 1;
        }
        break;
    }
    gCurrentActorPointer->y_rotation += 0x32;
    gCurrentActorPointer->y_rotation &= 0xFFF;
    gCurrentActorPointer->y_position = (func_global_asm_80612794(gCurrentActorPointer->y_rotation) * 5.0) + PaaD->unk0;
    if ((gPlayerPointer->control_state == 0x45) && (gPlayerPointer->control_state_progress >= 2) && (D_boss_80036DC4 < 10000.0)) {
        sp6A = TRUE;
    }
    sp69 = 0;
    PaaD->unk4 += PaaD->unk8;
    if (PaaD->unk4 > 1.0f) {
        PaaD->unk4 = 1.0f;
        sp69 = 1;
    } else if (PaaD->unk4 < 0.0f) {
        PaaD->unk4 = 0.0f;
        sp69 = -1;
    }
    if ((sp69 != 0) && (!func_global_asm_8061CB50())) {
        PaaD->unk10++;
    }
    PaaD->unk17 = 0;
    sp6B = PaaD->unk13;
    switch (PaaD->unk13) {
    case 0:
        var_t0_3 = 5;
        if (PaaD->unk12 == 2) {
            var_a1 = 0xC;
            PaaD->unk8 = -0.2f;
        } else {
            var_t0_3 = 0x3C;
            var_a1 = 4;
            PaaD->unk8 = -0.1f;
        }
        if (var_t0_3 < PaaD->unk10) {
            PaaD->unk15++;
            if (PaaD->unk15 < var_a1) {
                PaaD->unk13 = 1;
                playSound(0x37D, 0x7D00U, 63.0f, 1.0f, 0, 0);
                if (PaaD->unk12 == 2) {
                    playSound(0x381, 0x7D00U, 63.0f, 1.0f, 0, 0);
                } else {
                    playSound(0x37F, 0x7D00U, 63.0f, 1.0f, 0, 0);
                }
            } else {
                PaaD->unk13 = 2;
                PaaD->unk15 = 0;
            }
        }
        if ((sp69) && (D_boss_80035B40 == 0)) {
            sp68 = TRUE;
            D_boss_80035B2C = 0;
        }
        break;
    case 1:
        switch (PaaD->unk12) {
            default:
                var_t0_3 = 0xB4;
                PaaD->unk8 = 0.1f;
                break;
            case 3:
                var_t0_3 = 0x3C;
                PaaD->unk8 = 0.1f;
                break;
            case 2:
                var_t0_3 = 0xA;
                PaaD->unk8 = 0.2f;
                break;
        }
        if (sp69 == 1) {
            sp67 = TRUE;
            if (var_t0_3 < PaaD->unk10) {
                PaaD->unk13 = 0;
                PaaD->unk15++;
                playSound(0x17D, 0x3E80U, 63.0f, 1.0f, 0, 0);
            }
            if (sp6A) {
                playSound(0x97, 0x7D00U, 63.0f, 1.0f, 0, 0);
                PaaD->unk16++;
                PaaD->unk15 = 0;
                PaaD->unk13 = 2;
                if (PaaD->unk16 == 3) {
                    playSound(0x385, 0x7D00U, 63.0f, 1.0f, 0, 0);
                    PaaD->unk16 = 0;
                    func_global_asm_8061CAD8();
                    PaaD->unk13 = 4;
                } else {
                    playSound(0x38E, 0x7D00U, 63.0f, 1.0f, 0, 0);
                    playSound(0x383, 0x7D00U, 63.0f, 1.0f, 0, 0);
                }
            }
        }
        break;
    case 2:
        PaaD->unk8 = -0.1f;
        if (PaaD->unk10 >= 0x5B) {
            PaaD->unk15++;
            if (PaaD->unk15 < 3) {
                PaaD->unk13 = 3;
                playSound(0x37D, 0x7D00U, 63.0f, 1.0f, 0, 0);
                playSound(0x380, 0x7D00U, 63.0f, 1.0f, 0, 0);
            } else {
                PaaD->unk13 = 0;
                PaaD->unk15 = 0;
            }
        }
        if ((sp69) && (D_boss_80035B40 == 0)) {
            sp68 = TRUE;
        }
        break;
    case 3:
        PaaD->unk8 = 0.1f;
        if (PaaD->unk10 >= 0x1F) {
            PaaD->unk13 = 2;
            playSound(0x17D, 0x3E80U, 63.0f, 1.0f, 0, 0);
        }
        if (sp69 != 0) {
            PaaD->unk17 = 1;
        }
        break;
    case 4:
        D_boss_80035B3C += 1.0;
        if (D_boss_80035B3C > 24.0) {
            D_boss_80035B3C = 24.0f;
            PaaD->unk10++;
            D_boss_80035B2C = func_global_asm_80612794(PaaD->unk10 << 5) * 200.0f;
            if (PaaD->unk10 == 0x3F) {
                D_boss_80035B3C = 0.0f;
                D_boss_80035B2C = 0;
                D_boss_80035B28 = D_boss_80035B30[D_boss_80035B34];
                D_boss_80035B34++;
                PaaD->unk13 = 5;
            }
        }
        break;
    case 5:
        PaaD->unk10++;
        if (PaaD->unk10 >= 0x3D) {
            PaaD->unk8 = -0.1f;
            func_global_asm_8061CB08();
            PaaD->unk13 = 0;
            PaaD->unk12++;
            if (PaaD->unk12 == 1) {
                func_global_asm_80724994(1U, 7, 0, 0, 0);
            }
            if (PaaD->unk12 == 3) {
                PaaD->unk13 = 7;
            }
        }
        break;
    case 6:
        PaaD->unk8 = -0.1f;
        if (sp69 == -1) {
            sp67 = TRUE;
            if (D_boss_80035B70 < PaaD->unk10) {
                playSound(0x17D, 0x3E80U, 63.0f, 1.0f, 0, 0);
                PaaD->unk10 = 0;
                temp_v1_3 = D_boss_80035B70 + 1;
                if (temp_v1_3 >= 0x10) {
                    temp_v1_3++;
                }
                D_boss_80035B70 = temp_v1_3;
                if (temp_v1_3 >= 0x1A) {
                    temp_v1_3 = func_global_asm_806119A0();
                    PaaD->unk13 = 1;
                    PaaD->unk15++;
                    D_boss_80035B70 = (temp_v1_3 & 3) + 4;
                    playSound(0x37F, 0x7D00U, 63.0f, 1.0f, 0, 0);
                    playSound(0x381, 0x7D00U, 63.0f, 1.0f, 0, 0);
                }
                sp68 = TRUE;
            }
            D_boss_80035B68 = 0x1E;
        }
        break;
    case 7:
        PaaD->unk10++;
        PaaD->unk8 = -0.1f;
        if (PaaD->unk10 >= 0x10) {
            for (j = 0; j < 4; j++) {
                actor = func_global_asm_80688EA4(j);
                deleteActor(actor);
            }
            gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
            gCurrentActorPointer->shadow_opacity = 0;
            playCutscene(NULL, 4, 1U);
            PaaD->unk13 = 8;
        }
        break;
    case 8:
        PaaD->unk8 = -0.1f;
        if (D_global_asm_807FBDC4 != 0) {
            playSong(0x35, 1.0f);
            func_boss_80028478(0x13DU,
                gCurrentActorPointer->x_position,
                gCurrentActorPointer->y_position + 200.0f,
                gCurrentActorPointer->z_position + 40.0f, 0x800, 1U);
            PaaD->unk13 = 9;
        }
        break;
    case 9:
        break;
    }
    if ((PaaD->unk12 == 3) && (PaaD->unk13 == 0)) {
        if (PaaD->unk15 < 2) {
            PaaD->unk13 = 6;
        } else {
            PaaD->unk15 = 0x14;
        }
    }
    if (sp6B != PaaD->unk13) {
        PaaD->unk10 = 0;
    }
    if (sp68) {
        if ((PaaD->unk12 == 2) || (PaaD->unk12 == 3)) {
            PaaD->unk14++;
        } else {
            PaaD->unk14 += (s32) (func_global_asm_806119FC() * 2.99f) + 1;
        }
        if (PaaD->unk14 >= 4) {
            PaaD->unk14 -= 4;
        }
    }
    D_boss_80035B68++;
    if (sp67) {
        temp_v0_6 = (D_boss_80035B68 & 0x1F) - 0x10;
        if (temp_v0_6 < 0) {
            temp_v0_6 = -temp_v0_6;
        }
        if (temp_v0_6 >= 0x10) {
            temp_v0_6 = 0xF;
        }
        pos_x = (D_boss_80035B00[PaaD->unk14] * 0.33) + gCurrentActorPointer->x_position;
        pos_z = (D_boss_80035B08[PaaD->unk14] * 0.33) + gCurrentActorPointer->z_position;
        createLight(pos_x, 400.0f, pos_z, pos_x, 300.0f, pos_z, 200.0f, 0U, temp_v0_6 * 0x10, temp_v0_6 * 0x10, temp_v0_6 * 0x10);
        if (PaaD->unk12 == 1) {
            var_a1 = PaaD->unk14 + 2;
            if (var_a1 >= 4) {
                var_a1 -= 4;
            }
            pos_x = (D_boss_80035B00[var_a1] * 0.33) + gCurrentActorPointer->x_position;
            pos_z = (D_boss_80035B08[var_a1] * 0.33) + gCurrentActorPointer->z_position;
            createLight(pos_x, 400.0f, pos_z, pos_x, 300.0f, pos_z, 200.0f, 0U, temp_v0_6 * 0x10, temp_v0_6 * 0x10, temp_v0_6 * 0x10);
        }
    }
    PaaD->unkC--;
    if (PaaD->unkC < 0) {
        PaaD->unkC = (func_global_asm_806119A0() & 0x7F) + 0x5A;
        func_global_asm_80659670(0.5f, 0.5f, 0.5f, -1);
        func_global_asm_8068B80C();
    }
    D_boss_80035B40 = sp69;
    renderActor(gCurrentActorPointer, 0U);
}
*/

// rodata, close, doable, stack
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KutOut/func_boss_80032B08.s")

s32 func_global_asm_80614644(Actor *, AnimationStateUnk0 *, f32);

/*
void func_boss_80032B08(void) {
    AnimationStateUnk0 *temp_s0;
    s32 var_v0;
    KKOSegmentPaaD *aaD;
    KKOPaaD *aaD2; // sp30
    s16 temp;
    f32 dx;
    f32 dz;

    aaD = gCurrentActorPointer->additional_actor_data;
    aaD2 = aaD->unk0->additional_data_pointer;
    temp_s0 = gCurrentActorPointer->animation_state->unk0;
    if (aaD->unk5 == 0) {
        D_boss_80036DC4 = ((gPlayerPointer->x_position - gCurrentActorPointer->x_position) * (gPlayerPointer->x_position - gCurrentActorPointer->x_position)) + ((gPlayerPointer->z_position - gCurrentActorPointer->z_position) * (gPlayerPointer->z_position - gCurrentActorPointer->z_position));
    }
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_80613C48(gCurrentActorPointer, aaD->unk4 + 0x668, 0.0f, 0.0f);
        gCurrentActorPointer->draw_distance = 0xFA0;
    }
    if (D_boss_80035B28 & (1 << aaD->unk4)) {
        gCurrentActorPointer->z_rotation = (s32)(aaD2->unk4 * 1024.0) - 0x400;
        gCurrentActorPointer->x_rotation = D_boss_80035B2C;
        if (temp_s0 != NULL) {
            if (D_boss_80035B3C != temp_s0->unk4) {
                func_global_asm_80614644(gCurrentActorPointer, temp_s0, D_boss_80035B3C);
            }
        }
    } else {
        gCurrentActorPointer->z_rotation = 0;
        if (temp_s0 != NULL) {
            if (temp_s0->unk10 != aaD->unk4 + 0x66B) {
                func_global_asm_80613C48(gCurrentActorPointer, aaD->unk4 + 0x66B, 0.0f, 0.0f);
                playSound(0x38D, 0x7D00, 63.0f, 1.0f, 0, 0);
            } else {
                func_global_asm_80614644(gCurrentActorPointer, temp_s0, temp_s0->unk4 + 0.75f);
            }
            if (aaD->unk4 == 1) {
                if (temp_s0->unk4 > 24.0f) {
                    temp_s0->unk4 = 24.0f;
                }
                if (temp_s0->unk4 > 15.0f) {
                    gCurrentActorPointer->y_position -= 10.0f;
                }
            } else {
                if (temp_s0->unk4 > 37.0f) {
                    temp_s0->unk4 = 37.0f;
                }
                if (temp_s0->unk4 > 26.0f) {
                    gCurrentActorPointer->y_position -= 10.0f;
                }
            }
            if (gCurrentActorPointer->y_position < 0.0) {
                playSound(0x384, 0x7D00, 63.0f, 1.0f, 0, 0);
                deleteActor(gCurrentActorPointer);
            }
        }
    }
    if (aaD->unk5 == 0) {
        gCurrentActorPointer->noclip_byte = 0xC;
        if (aaD->unk4 == 0) {
            if (aaD2->unk17 == 1) {
                if (aaD->unk0->control_state == 0) {
                    D_boss_80035B74 = 0x28;
                }
                temp = D_boss_80035B74 - 1;
                D_boss_80035B74 = temp;
                if (temp < 0) {
                    dx = D_boss_80035B18[aaD2->unk14];
                    dz = D_boss_80035B20[aaD2->unk14];
                    D_boss_80035B74 = 0xA;
                    func_global_asm_806907F0(
                        gCurrentActorPointer->x_position + dx,
                        gCurrentActorPointer->y_position + 270.0f,
                        gCurrentActorPointer->z_position + dz
                    );
                    func_global_asm_80690A28(0x2C, 1, 0.25f, gPlayerPointer->x_position, gPlayerPointer->y_position, gPlayerPointer->z_position, 2400.0f, gCurrentActorPointer);
                }
            } else {
                D_boss_80035B74 = 0;
            }
        }
        gCurrentActorPointer->x_position = D_boss_80035B00[aaD2->unk14] + aaD->unk0->x_position;
        gCurrentActorPointer->z_position = D_boss_80035B08[aaD2->unk14] + aaD->unk0->z_position;
        gCurrentActorPointer->y_rotation = D_boss_80035B10[aaD2->unk14];
    } else {
        gCurrentActorPointer->noclip_byte = 1;
        var_v0 = aaD2->unk14 + 2;
        if (var_v0 >= 4) {
            var_v0 -= 4;
        }
        gCurrentActorPointer->x_position = D_boss_80035B00[var_v0] + aaD->unk0->x_position;
        gCurrentActorPointer->z_position = D_boss_80035B08[var_v0] + aaD->unk0->z_position;
        gCurrentActorPointer->y_rotation = D_boss_80035B10[var_v0];
        gCurrentActorPointer->object_properties_bitfield |= 0x800000;
        gCurrentActorPointer->unk16A = 0x23;
        gCurrentActorPointer->unk16B = 0x23;
        gCurrentActorPointer->unk16C = 0x46;
        if (aaD2->unk12 != 1) {
            gCurrentActorPointer->object_properties_bitfield &= ~4;
        } else {
            gCurrentActorPointer->object_properties_bitfield |= 4;
        }
    }
    renderActor(gCurrentActorPointer, 0);
}
*/
