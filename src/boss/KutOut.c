#include <ultra64.h>
#include "functions.h"

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

static u8 D_boss_80035B28 = 0xFF;

static s16 D_boss_80035B2C = 0x0000;

static u8 D_boss_80035B30[] = {7, 3, 1, 0}; // TODO: last 0 is padding?

static u8 D_boss_80035B34[] = {0, 0, 0, 0}; // TODO: Just a u8 with padding?
static s32 D_boss_80035B38 = 0xFF000000; // TODO: Just a u8 with padding?

static f32 D_boss_80035B3C = 0.0f;

static u8 D_boss_80035B40[] = {0, 0, 0, 0}; // TODO: Just a u8 with padding?
static u8 D_boss_80035B44[] = {2, 3, 4, 0}; // TODO: last 0 is padding?

static u8 D_boss_80035B48[] = {1, 0, 0, 0}; // TODO: Just a u8 with padding?

static u16 D_boss_80035B4C[] = {2, 3, 4, 5, 6, 0}; // TODO: last 0 is padding?

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

static u8 D_boss_80035B68[4] = {0, 0, 0, 0};
static u8 D_boss_80035B6C[4] = {0, 0, 0, 0};

static s16 D_boss_80035B70[2] = {0, 0};

static s16 D_boss_80035B74 = 0x0078;

// .rodata
static const u8 D_boss_80036B80[4] = {0x3D, 0xCC, 0xCC, 0xCD}; // TODO: Unused?

// Jumptable, 4200 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KutOut/func_boss_80031AA0.s")

// rodata, close, doable, stack
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KutOut/func_boss_80032B08.s")

s32 func_global_asm_80614644(Actor *, AnimationStateUnk0 *, f32);

extern f32 D_boss_80036DC4;

typedef struct {
    Actor *unk0;
    s8 unk4;
    s8 unk5;
} AAD_boss_80032B08;

typedef struct {
    f32 unk0;
    f32 unk4;
    s8 unk8[0x12 - 0x8];
    s8 unk12;
    s8 unk13; // Unused
    s8 unk14;
    s8 unk15; // Unused
    s8 unk16; // Unused
    s8 unk17;
} AAD_boss_80032B08_2;

/*
void func_boss_80032B08(void) {
    AnimationStateUnk0 *temp_s0;
    s32 var_v0;
    AAD_boss_80032B08 *aaD;
    AAD_boss_80032B08_2 *aaD2; // sp30

    aaD = gCurrentActorPointer->additional_actor_data;
    aaD2 = aaD->unk0->additional_data_pointer;
    temp_s0 = gCurrentActorPointer->animation_state->unk0;
    if (aaD->unk5 == 0) {
        D_boss_80036DC4 = ((gPlayerPointer->x_position - gCurrentActorPointer->x_position) * (gPlayerPointer->x_position - gCurrentActorPointer->x_position)) + ((gPlayerPointer->z_position - gCurrentActorPointer->z_position) * (gPlayerPointer->z_position - gCurrentActorPointer->z_position));
    }
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
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
                D_boss_80035B74--;
                if (D_boss_80035B74 < 0) {
                    D_boss_80035B74 = 0xA;
                    func_global_asm_806907F0(
                        gCurrentActorPointer->x_position + D_boss_80035B18[aaD2->unk14],
                        gCurrentActorPointer->y_position + 270.0f,
                        gCurrentActorPointer->z_position + D_boss_80035B20[aaD2->unk14]
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
