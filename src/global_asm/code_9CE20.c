#include <ultra64.h>
#include "functions.h"

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9CE20/func_global_asm_80698120.s")

void func_global_asm_8072EF7C(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8, s16 arg9, s16 argA, s16 argB, s16 argC);

extern s16 D_global_asm_8075037C;
extern s16 D_global_asm_80750380;

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
} AAD_global_asm_80698120;

/*
void func_global_asm_80698120(u8 arg0) {
    PlayerAdditionalActorData *PaaD;
    u8 sp63;
    s16 i;
    f32 var_f2;
    s16 var_t0;
    AnimationStateUnk1C *temp_v0;
    AAD_global_asm_80698120 *aaD;
    s32 pad2;
    s32 pad;

    aaD = current_actor_pointer->additional_actor_data;
    PaaD = character_change_array->player_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        aaD->unk0 = 0.0f;
        aaD->unk4 = 0.104719758f;
        aaD->unkC = 0;
        aaD->unk8 = 0.75f;
        aaD->unk10 = 0.0f;
        aaD->unk1C = current_actor_pointer->y_position;
        aaD->unk20 = 0.0f;
        aaD->unk24 = RandClamp(100) / 1000.0 + 0.1;
        aaD->unk18 = 0.0f;
        current_actor_pointer->animation_state->unk1C = malloc(0x80);
        func_global_asm_8072EE7C(
            current_actor_pointer,
            0,
            0,
            0,
            0,
            arg0 * 0.33333299999999999,
            0.15f,
            100.0f,
            20.0f,
            8.0f,
            0.0f,
            0,
            0.0f,
            0.0f,
            0
        );
        for (i = 1; i < arg0; i++) {
            func_global_asm_8072EF7C(current_actor_pointer, 0, i + 1, i - 1, i, 0.3333329856f, 0.0f, 0.0f, 0, 0, 0, 0, 0);
        }
        current_actor_pointer->unk130 = 0x3C;
        current_actor_pointer->unk131 = 0xC8;
        aaD->unk14 = 0;
        aaD->unk15 = 0;
        aaD->unk28 = isFlagSet(0x183, FLAG_TYPE_PERMANENT)
            || (D_global_asm_807FBB64 & 0x10000000)
            || gameIsInDKTVMode();
    }
    if ((player_pointer->control_state == 0x63) || (aaD->unk28 == 0) || ((reinterpret_cast(s32, current_actor_pointer->unk124->unk0) == 1) && !(PaaD->unk1F0 & 0x40))) {
        current_actor_pointer->object_properties_bitfield &= 0xFBFFFFFB;
    } else {
        current_actor_pointer->object_properties_bitfield |= 0x04000004;
    }
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if (D_global_asm_807FBB70.unk278[i] == 0) {
            aaD->unk16 = 0x50;
        }
    }
    i = 0;
    if (aaD->unk16) {
        current_actor_pointer->y_position = current_actor_pointer->y_position - 1.0;
        aaD->unk16 = aaD->unk16 - 1;
        aaD->unk1C = aaD->unk1C - 1.0;
    }
    temp_v0 = current_actor_pointer->animation_state->unk1C;
    if (aaD->unk0 > 2.0f) {
        if ((aaD->unkC < 3.926990986f) && (3.926990986f <= (aaD->unkC + aaD->unk4))) {
            if (current_actor_pointer->unk58 == ACTOR_CHAIN) {
                playSoundAtActorPosition(current_actor_pointer, 0x257, ((aaD->unk0 * 100.0) / 15.0f), 0x7F, 5);
                i = 0;
            } else {
                playSoundAtActorPosition(current_actor_pointer, 0x1C, ((aaD->unk0 * 100.0) / 15.0f), 0x7F, 5);
                i = 0;
            }
        }
        if ((aaD->unkC < 0.7853981853f) && (0.7853981853f <= (aaD->unkC + aaD->unk4))) {
            if (current_actor_pointer->unk58 == ACTOR_CHAIN) {
                playSoundAtActorPosition(current_actor_pointer, 0x258, ((aaD->unk0 * 25.0) / 15.0f), 0x7F, 0x14);
            } else {
                playSoundAtActorPosition(current_actor_pointer, 0x1D, ((aaD->unk0 * 25.0) / 15.0f), 0x7F, 0x14);
            }
        }
    }
    if ((current_actor_pointer->unk58 != ACTOR_CHAIN) && (aaD->unk0 > 10.0f)) {
        if ((aaD->unkC < 2.356194496f) && (2.356194496f <= (aaD->unkC + aaD->unk4))) {
            playSoundAtActorPosition(current_actor_pointer, 0x1E, 0xFF, 0x7F, 0x14);
        }
        if ((aaD->unkC < 5.497786999f) && (5.497786999f <= (aaD->unkC + aaD->unk4))) {
            playSoundAtActorPosition(current_actor_pointer, 0x1E, 0xFF, 0x7F, 0x14);
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

    aaD->unkC += ((aaD->unk4 * D_global_asm_80744478) * 0.5);
    aaD->unk10 = func_global_asm_80612D1C(aaD->unkC) * aaD->unk0;
    for (;i < 0xE; i++) {
        temp_v0 = &temp_v0[i];
        temp_v0->unk0 = -0x80;
        temp_v0->unk1 = i + sp63;
        temp_v0->unk4 = 0;
        temp_v0->unk6 = 0;
        temp_v0->unk2 = (aaD->unk10 / 360.0) * 65535.0;
        aaD->unk10 = aaD->unk10 * aaD->unk8;
    }

    // Vines (brown and green)
    if ((current_actor_pointer->unk58 == ACTOR_VINE) || (current_actor_pointer->unk58 == ACTOR_VINE_BROWN)) {
        temp_v0 = &temp_v0[i];
        temp_v0->unk0 = -0x80;
        temp_v0->unk1 = 1;
        temp_v0->unk2 = 0;
        temp_v0->unk6 = 0;
        temp_v0->unk4 = (aaD->unk18 / 360.0) * 65535.0;
        i++;
        aaD->unk18 += 20.0f;
        if (aaD->unk18 > 360.0f) {
            aaD->unk18 -= 360.0f;
        }
    }
    temp_v0[i].unk0 = 0;

    // Leaving vine
    if (player_pointer->control_state == 0x58) {
        aaD->unk15 = 5;
    } else {
        if (aaD->unk15) {
            aaD->unk15--;
        }
    }
    if ((player_pointer->unk6A & 0x40) && (aaD->unk14 == 0) && (current_actor_pointer == PaaD->unk130)) {
        aaD->unk0 = 15.0f;
        if (func_global_asm_806CC14C(player_pointer->y_rotation, current_actor_pointer->y_rotation) < 0x400) {
            aaD->unkC = 3.141592741f;
        } else {
            aaD->unkC = 0.0f;
        }
    }
    if (6.283185482f <= aaD->unkC) {
        aaD->unkC -= 6.283185482f;
    }
    if (aaD->unkC < 0.0f) {
        aaD->unkC += 6.283185482f;
    }
    if ((player_pointer->unk6A & 0x40) && (current_actor_pointer == PaaD->unk130)) {
        aaD->unk14 = 1;
        aaD->unk0 += 0.2;
        if (aaD->unk0 > 15.0f) {
            aaD->unk0 = 15.0f;
        }
    } else {
        aaD->unk14 = 0;
        aaD->unk0 = aaD->unk0 + ((0.0 - aaD->unk0) * 0.03);
        if (aaD->unk0 < 2.0) {
            aaD->unk0 = 0.0f;
        }
    }
    if ((player_pointer->unk6A & 0x40) && (current_actor_pointer == PaaD->unk130)) {
        if ((PaaD->unk138 < 1.5) && ((((aaD->unkC > 4.0)) && (aaD->unkC < 4.71238899230957031)) || ((aaD->unkC < 1.57079637050628662) && (0.9 < aaD->unkC)))) {
            PaaD->unk14C = D_global_asm_8075037C * (aaD->unk0 / 15.0f);
            PaaD->unk150 = D_global_asm_80750380 * (aaD->unk0 / 15.0f);
        } else {
            PaaD->unk14C = 200.0f;
            PaaD->unk150 = 200.0f;
        }
        PaaD->unk154 = current_actor_pointer->y_rotation & 0xFFF;
        if ((aaD->unkC < 1.57079637050628662) || (4.71238911151885986 < aaD->unkC)) {
            PaaD->unk154 = (PaaD->unk154 + 0x800) & 0xFFF;
        }
    }
    // Vines (brown and green)
    if ((current_actor_pointer->unk58 == ACTOR_VINE_BROWN) || (current_actor_pointer->unk58 == ACTOR_VINE)) {
        current_actor_pointer->y_position = (func_global_asm_80612D1C(aaD->unk20) * 5.0) + aaD->unk1C;
        aaD->unk20 += aaD->unk24;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_80698FEC(void) {
    func_global_asm_80698120(0xE);
}

void func_global_asm_8069900C(void) {
    func_global_asm_80698120(0xB);
}

void func_global_asm_8069902C(void) {
    func_global_asm_80698120(0xB);
}

void func_global_asm_8069904C(void) {
    func_global_asm_80698120(0xE);
}
