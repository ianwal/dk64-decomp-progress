#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9CE20/func_80698120.s")

// void func_80608528(f32, Actor *, s32, s32, s32, s32);
void func_80608528(Actor *arg0, s16 arg1, u8 arg2, s16 arg3, u8 arg4);
// f32 func_80612D1C(f32, u32);
// ? func_806319C4(void *, ?);
// ? func_8072EE7C(Actor *, ?, ?, ?, f32, f32, f32, f32, f32, s32, f32, f32, s32);
// ? func_8072EF7C(Actor *, ?, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32);
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
// Needs proper definition of D_807FBB70
void func_80698120(u8 arg0) {
    AAD_80698120 *sp7C;
    void *sp78;
    s16 sp76;
    PlayerAdditionalActorData *PaaD;
    u8 sp63;
    s32 sp54;
    s32 sp50;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f2;
    f64 temp_f0;
    f64 temp_f0_3;
    f64 temp_f0_4;
    f64 temp_f0_5;
    f64 temp_f16;
    f64 var_f16;
    s16 temp_t3;
    s16 var_v1;
    s16 var_v1_2;
    s16 var_v1_3;
    s32 temp_v0;
    s8 var_a0;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_v0_3;
    u32 var_v0;
    u8 temp_v1;
    u8 var_t0;
    void *temp_v0_2;
    void *temp_v0_4;
    void *var_t0_2;
    AAD_80698120 *var_t1;
    AAD_80698120 *var_t1_2;

    var_t1 = current_actor_pointer->additional_actor_data;
    PaaD = character_change_array->player_pointer->additional_actor_data;
    var_v0 = current_actor_pointer->object_properties_bitfield;
    if (!(var_v0 & 0x10)) {
        var_t1->unk0 = 0.0f;
        var_t1->unk10 = 0.0f;
        var_t1->unk4 = D_8075A240;
        var_t1->unk8 = 0.75f;
        var_t1->unkC = 0.0f;
        var_t1->unk20 = 0.0f;
        var_t1->unk1C = current_actor_pointer->y_position;
        sp7C = var_t1;
        temp_f16 = ((rand() >> 0xF) % 100) / D_8075A248;
        var_t1->unk18 = 0.0f;
        var_t1->unk24 = temp_f16 + D_8075A250;
        current_actor_pointer->animation_state->unk1C = malloc(0x80);
        var_f16 = arg0;
        func_8072EE7C(current_actor_pointer, 0, 0, 0, var_f16 * D_8075A258, D_8075A260, 100.0f, 20.0f, 8.0f, 0, 0.0f, 0.0f, 0);
        var_t1_2 = sp7C;
        var_v1 = 1;
        var_t0 = arg0;
        if (arg0 > 0) {
            do {
                temp_v0 = var_v1 + 1;
                sp50 = temp_v0;
                sp54 = var_t0;
                sp7C = var_t1_2;
                func_8072EF7C(current_actor_pointer, 0, (var_v1 - 1) & 0xFF, var_v1 & 0xFF, temp_v0, D_8075A264, 0.0f, 0.0f, 0, 0, 0, 0, 0);
                var_v1 = temp_v0;
            } while (var_t0 >= temp_v0);
        }
        current_actor_pointer->unk130 = 0x3C;
        current_actor_pointer->unk131 = 0xC8;
        var_t1_2->unk14 = 0;
        var_t1_2->unk15 = 0;
        sp7C = var_t1_2;
        var_a0 = isFlagSet(0x183, FLAG_TYPE_PERMANENT) != FALSE;
        var_t1 = var_t1_2;
        if (var_a0 == 0) {
            var_a0 = (D_807FBB64 & 0x10000000) != 0;
            if (var_a0 == 0) {
                sp7C = var_t1;
                var_a0 = gameIsInDKTVMode() != FALSE;
            }
        }
        var_t1->unk28 = var_a0;
        var_v0 = current_actor_pointer->object_properties_bitfield;
    }
    if ((player_pointer->control_state == 0x63) || (var_t1->unk28 == 0) || ((current_actor_pointer->unk124->unk0 == 1) && !(PaaD->unk1F0 & 0x40))) {
        current_actor_pointer->object_properties_bitfield = var_v0 & 0xFBFFFFFB;
    } else {
        current_actor_pointer->object_properties_bitfield = var_v0 | 0x04000004;
    }
    var_v1_2 = 0;
    if (D_807FBB70->unk254 > 0) {
        do {
            temp_t3 = D_807FBB70[var_v1_2]->unk278;
            var_v1_2 += 1;
            if (temp_t3 == 0) {
                var_t1->unk16 = 0x50;
            }
        } while (var_v1_2 < D_807FBB70->unk254);
        var_v1_2 = 0;
    }
    if (var_t1->unk16 != 0) {
        current_actor_pointer->y_position = current_actor_pointer->y_position - 1.0;
        var_t1->unk16 = var_t1->unk16 - 1;
        var_t1->unk1C = var_t1->unk1C - 1.0;
    }
    temp_f2 = var_t1->unk0;
    var_t0_2 = current_actor_pointer->animation_state->unk1C;
    if (temp_f2 > 2.0f) {
        var_f0 = var_t1->unkC;
        if ((var_f0 < D_8075A268) && (D_8075A268 <= (var_f0 + var_t1->unk4))) {
            if (current_actor_pointer->unk58 == 0x74) {
                sp76 = 0;
                sp78 = var_t0_2;
                sp7C = var_t1;
                // func_80608528(D_8075A268, temp_s0_2, 0x257, ((temp_f2 * 100.0) / 15.0f) & 0xFF, 0x7F, 5);
                func_80608528(current_actor_pointer, 0x257, ((temp_f2 * 100.0) / 15.0f), 0x7F, 5);
                var_v1_2 = 0;
            } else {
                sp76 = 0;
                sp78 = var_t0_2;
                sp7C = var_t1;
                // func_80608528(D_8075A268, temp_s0_2, 0x1C, ((temp_f2 * 100.0) / 15.0f) & 0xFF, 0x7F, 5);
                func_80608528(current_actor_pointer, 0x1C, ((temp_f2 * 100.0) / 15.0f), 0x7F, 5);
                var_v1_2 = 0;
            }
            var_f0 = var_t1->unkC;
        }
        if ((var_f0 < D_8075A26C) && (D_8075A26C <= (var_f0 + var_t1->unk4))) {
            temp_f2_2 = var_t1->unk0;
            temp_f0 = 15.0f;
            if (current_actor_pointer->unk58 == 0x74) {
                sp76 = var_v1_2;
                sp78 = var_t0_2;
                sp7C = var_t1;
                func_80608528(current_actor_pointer, 0x258, ((temp_f2_2 * 25.0) / temp_f0), 0x7F, 0x14);
            } else {
                sp76 = var_v1_2;
                sp78 = var_t0_2;
                sp7C = var_t1;
                func_80608528(current_actor_pointer, 0x1D, ((temp_f2_2 * 25.0) / temp_f0), 0x7F, 0x14);
            }
            var_t1 = sp7C;
        }
    }
    var_f0_2 = var_t1->unkC;
    var_f2 = var_t1->unk4;
    if ((current_actor_pointer->unk58 != 0x74) && (var_t1->unk0 > 10.0f)) {
        if ((var_f0_2 < D_8075A270) && (D_8075A270 <= (var_f0_2 + var_f2))) {
            sp76 = var_v1_2;
            sp78 = var_t0_2;
            sp7C = var_t1;
            func_80608528(current_actor_pointer, 0x1E, 0xFF, 0x7F, 0x14);
            var_f0_2 = var_t1->unkC;
            var_f2 = var_t1->unk4;
        }
        if ((var_f0_2 < D_8075A274) && (D_8075A274 <= (var_f0_2 + var_f2))) {
            sp76 = var_v1_2;
            sp78 = var_t0_2;
            sp7C = var_t1;
            func_80608528(current_actor_pointer, 0x1E, 0xFF, 0x7F, 0x14);
            var_f0_2 = var_t1->unkC;
            var_f2 = var_t1->unk4;
        }
    }
    temp_a0 = current_actor_pointer->unk58;
    if (temp_a0 != 0x21) {
        if (temp_a0 != 0x44) {
            if (temp_a0 != 0x45) {
                if (temp_a0 == 0x74) {
                    goto block_47;
                }
            } else {
                goto block_48;
            }
        } else {
block_47:
            sp63 = 1;
        }
    } else {
block_48:
        sp63 = 2;
    }
    var_t1->unkC = var_f0_2 + ((var_f2 * D_80744478) * 0.5);
    sp7C = var_t1;
    sp78 = var_t0_2;
    sp76 = var_v1_2;
    var_v1_3 = var_v1_2;
    var_t1->unk10 = func_80612D1C(var_t1->unkC, temp_a0) * var_t1->unk0;
    do {
        temp_v0_2 = var_t0_2 + (var_v1_3 * 8);
        temp_v0_2->unk0 = -0x80;
        temp_v0_2->unk1 = var_v1_3 + sp63;
        temp_v0_2->unk4 = 0;
        temp_v0_2->unk6 = 0;
        var_v1_3 += 1;
        temp_v0_2->unk2 = (var_t1->unk10 / D_8075A280) * D_8075A278;
        var_t1->unk10 = var_t1->unk10 * var_t1->unk8;
    } while (var_v1_3 < 0xE);
    temp_v0_3 = current_actor_pointer->unk58;
    // Vines (brown and green)
    if ((temp_v0_3 == 0x45) || (temp_v0_3 == 0x21)) {
        temp_v0_4 = var_t0_2 + (var_v1_3 * 8);
        temp_v0_4->unk0 = -0x80;
        temp_v0_4->unk1 = 1;
        temp_v0_4->unk2 = 0;
        temp_v0_4->unk6 = 0;
        var_v1_3 += 1;
        temp_v0_4->unk4 = (var_t1->unk18 / D_8075A280) * D_8075A278;
        var_t1->unk18 = var_t1->unk18 + 20.0f;
        temp_f12 = var_t1->unk18;
        if (temp_f12 > 360.0f) {
            var_t1->unk18 = temp_f12 - 360.0f;
        }
    }
    *(var_t0_2 + (var_v1_3 * 8)) = 0;
    // Leaving vine
    if (player_pointer->control_state == 0x58) {
        var_t1->unk15 = 5;
        goto block_59;
    }
    temp_v1 = var_t1->unk15;
    if (temp_v1 != 0) {
        var_t1->unk15 = temp_v1 - 1;
block_59:
    }
    if ((player_pointer->unk6A & 0x40) && (var_t1->unk14 == 0) && (current_actor_pointer == PaaD->unk130)) {
        var_t1->unk0 = 15.0f;
        sp7C = var_t1;
        if (func_806CC14C(player_pointer->y_rotation, current_actor_pointer->y_rotation) < 0x400) {
            var_t1->unkC = D_8075A288;
        } else {
            var_t1->unkC = 0.0f;
        }
    }
    if (D_8075A28C <= var_t1->unkC) {
        var_t1->unkC -= D_8075A28C;
    }
    if (var_t1->unkC < 0.0f) {
        var_t1->unkC += D_8075A28C;
    }
    if ((player_pointer->unk6A & 0x40) && (current_actor_pointer == PaaD->unk130)) {
        var_t1->unk14 = 1;
        var_t1->unk0 += D_8075A290;
        if (var_t1->unk0 > 15.0f) {
            var_t1->unk0 = 15.0f;
        }
    } else {
        var_t1->unk14 = 0;
        var_t1->unk0 = var_t1->unk0 + ((0.0 - var_t1->unk0) * D_8075A298);
        if (var_t1->unk0 < 2.0) {
            var_t1->unk0 = 0.0f;
        }
    }
    if ((player_pointer->unk6A & 0x40) && (current_actor_pointer == PaaD->unk130)) {
        if ((PaaD->unk138 < 1.5) && ((((var_t1->unkC > 4.0)) && (var_t1->unkC < D_8075A2A0)) || ((var_t1->unkC < D_8075A2A8) && (D_8075A2B0 < var_t1->unkC)))) {
            PaaD->unk14C = D_8075037C * (var_t1->unk0 / 15.0f);
            PaaD->unk150 = D_80750380 * (var_t1->unk0 / 15.0f);
        } else {
            PaaD->unk14C = 200.0f;
            PaaD->unk150 = 200.0f;
        }
        PaaD->unk154 = current_actor_pointer->y_rotation & 0xFFF;
        if ((var_t1->unkC < D_8075A2B8) || (D_8075A2C0 < var_t1->unkC)) {
            PaaD->unk154 = (PaaD->unk154 + 0x800) & 0xFFF;
        }
    }
    temp_a0_2 = current_actor_pointer->unk58;
    // Vines (brown and green)
    if ((temp_a0_2 == 0x21) || (temp_a0_2 == 0x45)) {
        sp7C = var_t1;
        current_actor_pointer->y_position = (func_80612D1C(var_t1->unk20, temp_a0_2) * 5.0) + var_t1->unk1C;
        var_t1->unk20 += var_t1->unk24;
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
