#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9CE20/func_80698120.s")

// void func_80608528(f32, Actor *, s32, s32, s32, s32);
void func_80608528(Actor *arg0, s16 arg1, u8 arg2, s16 arg3, u8 arg4);
// f32 func_80612D1C(f32, u32);
// ? func_806319C4(void *, ?);
void func_8072EE7C(Actor *, s32, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32);
void func_8072EF7C(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8, s16 arg9, s16 argA, s16 argB, s16 argC);
extern s32 D_80744478;
extern s16 D_8075037C;
extern s16 D_80750380;
extern f32 D_8075A240;
extern f64 D_8075A248;
extern f64 D_8075A250;
extern f64 D_8075A258;
extern f32 D_8075A260;
extern f32 D_8075A264;
extern f32 D_8075A268;
extern f32 D_8075A26C;
extern f32 D_8075A270;
extern f32 D_8075A274;
extern f64 D_8075A278;
extern f64 D_8075A280;
extern f32 D_8075A288;
extern f32 D_8075A28C;
extern f64 D_8075A290;
extern f64 D_8075A298;
extern f64 D_8075A2A0;
extern f64 D_8075A2A8;
extern f64 D_8075A2B0;
extern f64 D_8075A2B8;
extern f64 D_8075A2C0;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 unk28;
} AAD_80698120;

/*
// TODO: Doable, good progress made
void func_80698120(u8 arg0) {
    PlayerAdditionalActorData *PaaD;
    u8 sp63;
    f32 var_f0_2;
    f32 var_f2;
    s16 var_v1;
    s16 var_v1_2;
    u8 var_t0;
    AnimationStateUnk1C *temp_v0_2;
    AnimationStateUnk1C *temp_v0_4;
    AnimationStateUnk1C *var_t0_2;
    AAD_80698120 *aaD;
    AAD_80698120 *var_t1_2;

    aaD = current_actor_pointer->additional_actor_data;
    PaaD = character_change_array->player_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        aaD->unk0 = 0.0f;
        aaD->unk4 = D_8075A240;
        aaD->unkC = 0;
        aaD->unk8 = 0.75f;
        aaD->unk10 = 0.0f;
        aaD->unk1C = current_actor_pointer->y_position;
        aaD->unk20 = 0.0f;
        aaD->unk24 = ((rand() >> 0xF) % 100) / D_8075A248 + D_8075A250;
        aaD->unk18 = 0.0f;
        current_actor_pointer->animation_state->unk1C = malloc(0x80);
        func_8072EE7C(current_actor_pointer, 0, 0, 0, arg0 * D_8075A258, D_8075A260, 100.0f, 20.0f, 8.0f, 0, 0.0f, 0.0f, 0);
        for (var_v1 = 1; var_v1 < arg0; var_v1++) {
            func_8072EF7C(current_actor_pointer, 0, var_v1 + 1, var_v1 - 1, var_v1, D_8075A264, 0.0f, 0.0f, 0, 0, 0, 0, 0);
        }
        current_actor_pointer->unk130 = 0x3C;
        current_actor_pointer->unk131 = 0xC8;
        var_t1_2->unk14 = 0;
        var_t1_2->unk15 = 0;
        aaD->unk28 = isFlagSet(0x183, FLAG_TYPE_PERMANENT) != FALSE
            || (D_807FBB64 & 0x10000000) != 0
            || gameIsInDKTVMode() != FALSE;
    }
    if ((player_pointer->control_state == 0x63) || (aaD->unk28 == 0) || ((current_actor_pointer->unk124->unk0 == 1) && !(PaaD->unk1F0 & 0x40))) {
        current_actor_pointer->object_properties_bitfield &= 0xFBFFFFFB;
    } else {
        current_actor_pointer->object_properties_bitfield |= 0x04000004;
    }
    for (var_v1_2 = 0; var_v1_2 < D_807FBB70.unk254; var_v1_2++) {
        if (D_807FBB70.unk278[var_v1_2++] == 0) {
            aaD->unk16 = 0x50;
        }
    }
    var_v1_2 = 0;
    if (aaD->unk16 != 0) {
        current_actor_pointer->y_position = current_actor_pointer->y_position - 1.0;
        aaD->unk16 = aaD->unk16 - 1;
        aaD->unk1C = aaD->unk1C - 1.0;
    }
    var_t0_2 = current_actor_pointer->animation_state->unk1C;
    if (aaD->unk0 > 2.0f) {
        if ((aaD->unkC < D_8075A268) && (D_8075A268 <= (aaD->unkC + aaD->unk4))) {
            if (current_actor_pointer->unk58 == ACTOR_CHAIN) {
                // func_80608528(D_8075A268, temp_s0_2, 0x257, ((aaD->unk0 * 100.0) / 15.0f) & 0xFF, 0x7F, 5);
                func_80608528(current_actor_pointer, 0x257, ((aaD->unk0 * 100.0) / 15.0f), 0x7F, 5);
                var_v1_2 = 0;
            } else {
                // func_80608528(D_8075A268, temp_s0_2, 0x1C, ((aaD->unk0 * 100.0) / 15.0f) & 0xFF, 0x7F, 5);
                func_80608528(current_actor_pointer, 0x1C, ((aaD->unk0 * 100.0) / 15.0f), 0x7F, 5);
                var_v1_2 = 0;
            }
        }
        if ((aaD->unkC < D_8075A26C) && (D_8075A26C <= (aaD->unkC + aaD->unk4))) {
            if (current_actor_pointer->unk58 == ACTOR_CHAIN) {
                func_80608528(current_actor_pointer, 0x258, ((aaD->unk0 * 25.0) / 15.0f), 0x7F, 0x14);
            } else {
                func_80608528(current_actor_pointer, 0x1D, ((aaD->unk0 * 25.0) / 15.0f), 0x7F, 0x14);
            }
        }
    }
    if ((current_actor_pointer->unk58 != ACTOR_CHAIN) && (aaD->unk0 > 10.0f)) {
        if ((aaD->unkC < D_8075A270) && (D_8075A270 <= (aaD->unkC + aaD->unk4))) {
            func_80608528(current_actor_pointer, 0x1E, 0xFF, 0x7F, 0x14);
        }
        if ((aaD->unkC < D_8075A274) && (D_8075A274 <= (aaD->unkC + aaD->unk4))) {
            func_80608528(current_actor_pointer, 0x1E, 0xFF, 0x7F, 0x14);
        }
    }

    switch (current_actor_pointer->unk58) {
        case ACTOR_CHAIN:
        case ACTOR_UNKNOWN_68:
            sp63 = 1;
            break;
        case ACTOR_VINE:
        case ACTOR_VINE_BROWN:
            sp63 = 2;
            break;
    }

    aaD->unkC += ((aaD->unk4 * D_80744478) * 0.5);
    aaD->unk10 = func_80612D1C(aaD->unkC) * aaD->unk0;
    do {
        temp_v0_2 = &var_t0_2[var_v1_2];
        temp_v0_2->unk0 = -0x80;
        temp_v0_2->unk1 = var_v1_2 + sp63;
        temp_v0_2->unk4 = 0;
        temp_v0_2->unk6 = 0;
        var_v1_2++;
        temp_v0_2->unk2 = (aaD->unk10 / D_8075A280) * D_8075A278;
        aaD->unk10 = aaD->unk10 * aaD->unk8;
    } while (var_v1_2 < 0xE);

    // Vines (brown and green)
    if ((current_actor_pointer->unk58 == ACTOR_VINE) || (current_actor_pointer->unk58 == ACTOR_VINE_BROWN)) {
        temp_v0_4 = &var_t0_2[var_v1_2];
        temp_v0_4->unk0 = -0x80;
        temp_v0_4->unk1 = 1;
        temp_v0_4->unk2 = 0;
        temp_v0_4->unk6 = 0;
        var_v1_2++;
        temp_v0_4->unk4 = (aaD->unk18 / D_8075A280) * D_8075A278;
        aaD->unk18 += 20.0f;
        if (aaD->unk18 > 360.0f) {
            aaD->unk18 -= 360.0f;
        }
    }
    var_t0_2[var_v1_2].unk0 = 0;

    // Leaving vine
    if (player_pointer->control_state == 0x58) {
        aaD->unk15 = 5;
    } else {
        if (aaD->unk15 != 0) {
            aaD->unk15--;
        }
    }
    if ((player_pointer->unk6A & 0x40) && (aaD->unk14 == 0) && (current_actor_pointer == PaaD->unk130)) {
        aaD->unk0 = 15.0f;
        if (func_806CC14C(player_pointer->y_rotation, current_actor_pointer->y_rotation) < 0x400) {
            aaD->unkC = D_8075A288;
        } else {
            aaD->unkC = 0.0f;
        }
    }
    if (D_8075A28C <= aaD->unkC) {
        aaD->unkC -= D_8075A28C;
    }
    if (aaD->unkC < 0.0f) {
        aaD->unkC += D_8075A28C;
    }
    if ((player_pointer->unk6A & 0x40) && (current_actor_pointer == PaaD->unk130)) {
        aaD->unk14 = 1;
        aaD->unk0 += D_8075A290;
        if (aaD->unk0 > 15.0f) {
            aaD->unk0 = 15.0f;
        }
    } else {
        aaD->unk14 = 0;
        aaD->unk0 = aaD->unk0 + ((0.0 - aaD->unk0) * D_8075A298);
        if (aaD->unk0 < 2.0) {
            aaD->unk0 = 0.0f;
        }
    }
    if ((player_pointer->unk6A & 0x40) && (current_actor_pointer == PaaD->unk130)) {
        if ((PaaD->unk138 < 1.5) && ((((aaD->unkC > 4.0)) && (aaD->unkC < D_8075A2A0)) || ((aaD->unkC < D_8075A2A8) && (D_8075A2B0 < aaD->unkC)))) {
            PaaD->unk14C = D_8075037C * (aaD->unk0 / 15.0f);
            PaaD->unk150 = D_80750380 * (aaD->unk0 / 15.0f);
        } else {
            PaaD->unk14C = 200.0f;
            PaaD->unk150 = 200.0f;
        }
        PaaD->unk154 = current_actor_pointer->y_rotation & 0xFFF;
        if ((aaD->unkC < D_8075A2B8) || (D_8075A2C0 < aaD->unkC)) {
            PaaD->unk154 = (PaaD->unk154 + 0x800) & 0xFFF;
        }
    }
    // Vines (brown and green)
    if ((current_actor_pointer->unk58 == ACTOR_VINE_BROWN) || (current_actor_pointer->unk58 == ACTOR_VINE)) {
        current_actor_pointer->y_position = (func_80612D1C(aaD->unk20) * 5.0) + aaD->unk1C;
        aaD->unk20 += aaD->unk24;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

void func_80698FEC(void) {
    func_80698120(0xE);
}

void func_8069900C(void) {
    func_80698120(0xB);
}

void func_8069902C(void) {
    func_80698120(0xB);
}

void func_8069904C(void) {
    func_80698120(0xE);
}
