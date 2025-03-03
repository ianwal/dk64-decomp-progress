#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_80750AB8;
extern s32 D_global_asm_80750FF0;

// .data
extern f32 D_global_asm_807531E0[];
extern f32 D_global_asm_807531FC[]; // Kong Walking Maximum Velocity
extern f32 D_global_asm_80753250[];
extern s16 D_global_asm_80753354[];
extern f32 D_global_asm_807534B8[];
extern s16 D_global_asm_807534D4[];
extern f32 D_global_asm_807535CC[];
extern f32 D_global_asm_807536E4[];
extern s16 D_global_asm_8075380C[];
extern s16 D_global_asm_8075381C[];
extern s16 D_global_asm_8075382C[];
extern s16 D_global_asm_8075385C[];
extern s16 D_global_asm_8075395C[];
extern f32 D_global_asm_8075396C[];
extern f32 D_global_asm_80753988[];
extern s16 D_global_asm_80753B34[];
extern f32 D_global_asm_80753BA4[];
extern f32 D_global_asm_80753BC0[];
extern f32 D_global_asm_80753BDC[];
extern f32 D_global_asm_80753BF8[];
extern s16 D_global_asm_80753C94[];
extern f32 D_global_asm_80753D08[];
extern f32 D_global_asm_80753DC8[];
extern f32 D_global_asm_80753DE4[];
extern s16 D_global_asm_80753E64[];

extern f64 D_global_asm_8075D328;// = 0.8;
extern s32 D_global_asm_80767CC0;
extern s32 D_global_asm_807FBB68;
extern u8 D_global_asm_807FBB8C;
extern u8 D_global_asm_807FC8B9;
extern f32 D_global_asm_807FD888;

s32 handleInputsForControlState(s32 arg0);
f32 func_global_asm_806E0454(f32, f32);
void func_global_asm_8072FE60(f32);
void func_global_asm_806E1630(void);
void func_global_asm_806DF390(Actor*, PlayerAdditionalActorData*, u8);
void func_global_asm_806DF3D0(Actor*, PlayerAdditionalActorData*, u8);
void func_global_asm_806CD424(s16, f32, f32); // TODO: Is this signature correct?

void func_global_asm_806DF390(Actor *arg0, PlayerAdditionalActorData *arg1, u8 arg2) {
    s32 phi_a3;

    phi_a3 = 0x4A;
    if (arg2) {
        phi_a3 = 0x4C;
    }
    arg1->unk1A3 = 0;
    playAnimation(arg0, phi_a3);
}

void func_global_asm_806DF3D0(Actor *arg0, PlayerAdditionalActorData *arg1, u8 arg2) {
    s32 sp1C = 0x4B;
    s32 phi_a3 = 2;

    if (func_global_asm_806F8AD4(3, arg1->unk1A4)) {
        phi_a3 = 3;
    }
    func_global_asm_806F8BC4(phi_a3, 0, 0);
    if (arg2 != 0) {
        sp1C = 0x4D;
    }
    playAnimation(arg0, sp1C);
}

void func_global_asm_806DF44C(Actor* arg0, PlayerAdditionalActorData *arg1, u8 arg2) {
    if (arg1->unk8C != 0) {
        func_global_asm_806DF390(arg0, arg1, arg2);
        return;
    }
    func_global_asm_806DF3D0(arg0, arg1, arg2);
}

void func_global_asm_806DF494(s16 *arg0, s16 arg1, s16 arg2) {
    s16 var_v0;
    s16 var_a2;

    arg1 &= 0xFFF;
    var_v0 = (arg1 - *arg0);
    if (var_v0) {
        var_a2 = ABS(var_v0);
        var_v0 /= var_a2;
        if (var_a2 >= 0x801) {
            var_a2 = 0x1000 - var_a2;
            var_v0 *= -1;
        }
        if (var_a2 < ABS(arg2)) {
            *arg0 = arg1;
        } else {
            *arg0 += (var_v0 * arg2);
            *arg0 &= 0xFFF;
        }
    }
}

void func_global_asm_806DF5A0(s16 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 var_v0;
    s16 var_a2;

    arg1 &= 0xFFF;
    var_v0 = (arg1 - *arg0);
    if (var_v0) {
        var_a2 = ABS(var_v0);
        var_v0 &= 0xFFF;
        if (var_a2 >= 0x801) {
            var_a2 = 0x1000 - var_a2;
        }
        if (arg2 >= var_a2) {
            *arg0 = arg1;
        } else if (arg3 < var_v0) {
            *arg0 = *arg0 - arg2;
        } else {
            *arg0 = *arg0 + arg2;
        }
        *arg0 &= 0xFFF;
    }
}

void func_global_asm_806DF670(s16 *arg0, s16 arg1, s16 arg2) {
    s16 temp_v0 = arg1 - *arg0;
    if (temp_v0 != 0) {
        // TODO: Is there a better way to express this?
        if (((temp_v0 & 0xFFF) << 0x10 >> 0x10) + arg2 >= 0x1000) {
            *arg0 = arg1;
        } else {
            *arg0 = (*arg0 + arg2) & 0xFFF;
        }
    }
}

// doable, stack, regalloc
// https://decomp.me/scratch/hyCim
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/handleInputsForControlState.s")

typedef struct {
    void (*unk0)(void); // Start Button Pressed Handler
    void (*unk4)(void); // Always Called (before input handlers)
    void (*unk8)(void); // A Button Pressed Handler
    void (*unkC)(void); // B Button Pressed Handler
    void (*unk10)(void); // Z Button Pressed Handler
    void (*unk14)(void); // A Button Released Handler
    void (*unk18)(void); // B Button Released Handler
    void (*unk1C)(void); // Z Button Released Handler
    void (*unk20)(void); // L Button Pressed Handler
    void (*unk24)(void); // R Button Pressed Handler
    void (*unk28)(void);
    void (*unk2C)(void); // R Button Released Handler
    void (*unk30)(void); // C-Up Pressed Handler
    void (*unk34)(void); // C-Left Pressed Handler
    void (*unk38)(void); // C-Right Pressed Handler
    void (*unk3C)(void); // C-Down Pressed Handler
    void (*unk40)(void); // Always Called (after input handlers)
} ControlStateInputHandler;
extern ControlStateInputHandler D_global_asm_80751004[]; // TODO: rodata?

extern u16 D_global_asm_807ECDF0;

/*
s32 handleInputsForControlState(s32 controlState) {
    ControlStateInputHandler *inputHandler;
    f32 temp_f18;
    f32 var_f14; // sp44
    f32 var_f2; // sp40
    f32 temp_f8;
    f32 var_f16; // sp38
    s16 var_t0;
    s32 var_a0;
    s32 oldControlState; // sp2C
    f32 temp_f12;

    oldControlState = current_player->control_state;

    // Read button inputs
    D_global_asm_807FD610[cc_player_index].unk2A = func_global_asm_806DFF34(D_global_asm_807ECDEC->button, &D_global_asm_80750FF0);
    D_global_asm_807FD610[cc_player_index].unk2C = func_global_asm_806DFF34(D_global_asm_807ECDF0, &D_global_asm_80750FF0);

    // Buttons disabled?
    if (extra_player_info_pointer->unk1F4 & 0x20) {
        D_global_asm_807FD610[cc_player_index].unk2A = 0;
        D_global_asm_807FD610[cc_player_index].unk2C = 0;
    }

    // Read joystick inputs and clamp between -80 and 80
    D_global_asm_807ECDEC->stick_x = MIN(MAX(D_global_asm_807ECDEC->stick_x, -80), 80);
    D_global_asm_807ECDEC->stick_y = MIN(MAX(D_global_asm_807ECDEC->stick_y, -80), 80);
    D_global_asm_807FD610[cc_player_index].unk2E = D_global_asm_807ECDEC->stick_x;
    D_global_asm_807FD610[cc_player_index].unk2F = D_global_asm_807ECDEC->stick_y;

    // Joystick disabled?
    if (extra_player_info_pointer->unk1F4 & 0x20) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
        D_global_asm_807FD610[cc_player_index].unk2F = 0;
    }
    // Joystick movement halved?
    if (extra_player_info_pointer->unk1F0 & 0x100) {
        D_global_asm_807FD610[cc_player_index].unk2E *= 0.5;
        D_global_asm_807FD610[cc_player_index].unk2F *= 0.5;
    }
    // Joystick inverted?
    if (extra_player_info_pointer->unk1F0 & 0x80) {
        D_global_asm_807FD610[cc_player_index].unk2E = -D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2F = -D_global_asm_807FD610[cc_player_index].unk2F;
    }

    // Compute absolute joystick magnitude
    D_global_asm_807FD610[cc_player_index].unk30 = ABS(D_global_asm_807FD610[cc_player_index].unk2E);
    D_global_asm_807FD610[cc_player_index].unk31 = ABS(D_global_asm_807FD610[cc_player_index].unk2F);

    // Joystick deadzone
    if (D_global_asm_807FD610[cc_player_index].unk30 < 5 && D_global_asm_807FD610[cc_player_index].unk31 < 5) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
        D_global_asm_807FD610[cc_player_index].unk30 = 0;
        D_global_asm_807FD610[cc_player_index].unk2F = 0;
        D_global_asm_807FD610[cc_player_index].unk31 = 0;
    }
    if (D_global_asm_807FD610[cc_player_index].unk30 < 2) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
        D_global_asm_807FD610[cc_player_index].unk30 = 0;
    }
    if (D_global_asm_807FD610[cc_player_index].unk31 < 2) {
        D_global_asm_807FD610[cc_player_index].unk2F = 0;
        D_global_asm_807FD610[cc_player_index].unk31 = 0;
    }
    var_f14 = D_global_asm_807FD610[cc_player_index].unk30 * D_global_asm_807FD610[cc_player_index].unk30;
    var_f2 = D_global_asm_807FD610[cc_player_index].unk31 * D_global_asm_807FD610[cc_player_index].unk31;
    var_f16 = sqrtf(var_f14 + var_f2);
    if (var_f2 < var_f14) {
        temp_f12 = var_f14;
        var_f14 = var_f2;
        var_f2 = temp_f12;
    }
    if (var_f2 != 0.0f) {
        var_f16 *= (f32)(1.0 - ((var_f14 / var_f2) * 0.15));
    }
    if (var_f16 > 70.0f) {
        var_f16 = 70.0f;
    }
    temp_f8 = D_global_asm_807FD610[cc_player_index].unk4;
    D_global_asm_807FD610[cc_player_index].unk4 = var_f16;
    D_global_asm_807FD610[cc_player_index].unkC = var_f16 - temp_f8;
    if (var_f16 != 0.0f) {
        D_global_asm_807FD610[cc_player_index].unk0 = 0;
        D_global_asm_807FD610[cc_player_index].unk8 = (var_f16 - 5.0f) / 65.0f;
    } else {
        D_global_asm_807FD610[cc_player_index].unk0++;
        D_global_asm_807FD610[cc_player_index].unk8 = 0.0f;
    }
    if (var_f16 != 0.0f) {
        var_t0 = (func_global_asm_80611BB4(D_global_asm_807FD610[cc_player_index].unk2E, -D_global_asm_807FD610[cc_player_index].unk2F) * 4096.0f) / MATH_2PI_F;
        D_global_asm_807FD610[cc_player_index].unk28 = (character_change_array[cc_player_index].unk2C8 + var_t0);
        D_global_asm_807FD610[cc_player_index].unk28 &= 0xFFF;
    } else {
        var_t0 = D_global_asm_807FD610[cc_player_index].unk20[0];
    }
    for (var_a0 = 3; var_a0 != 0; var_a0--) {
        D_global_asm_807FD610[cc_player_index].unk20[var_a0] = D_global_asm_807FD610[cc_player_index].unk20[var_a0 - 1];
        D_global_asm_807FD610[cc_player_index].unk10[var_a0] = D_global_asm_807FD610[cc_player_index].unk10[var_a0 - 1];
    }
    D_global_asm_807FD610[cc_player_index].unk20[var_a0] = var_t0;
    D_global_asm_807FD610[cc_player_index].unk10[var_a0] = var_f16;

    // Handle inputs for this control state
    inputHandler = &D_global_asm_80751004[controlState];
    inputHandler->unk4();
    if (D_global_asm_807FD610[cc_player_index].unk2A & START_BUTTON) {
        inputHandler->unk0();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & A_BUTTON) {
        inputHandler->unk8();
    } else {
        inputHandler->unk14();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & B_BUTTON) {
        inputHandler->unkC();
    } else {
        inputHandler->unk18();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) {
        inputHandler->unk10();
    } else {
        inputHandler->unk1C();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG) {
        inputHandler->unk24();
    } else {
        inputHandler->unk2C();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & L_TRIG) {
        inputHandler->unk20();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & U_CBUTTONS) {
        inputHandler->unk30();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & D_CBUTTONS) {
        inputHandler->unk3C();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & L_CBUTTONS) {
        inputHandler->unk34();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & R_CBUTTONS) {
        inputHandler->unk38();
    }
    inputHandler->unk40();
    return current_player->control_state - oldControlState;
}
*/

u16 func_global_asm_806DFF34(u16 arg0, u16 *arg1) {
    u16 i;
    u16 j;

    j = 0;
    i = 0;
    while (*arg1) {
        j |= *arg1;
        if (*arg1++ & arg0) {
            i |= *arg1;
        }
        arg1++;
    }
    return (i | (arg0 & ~j));
}

f32 func_global_asm_806DFFA0(f32 arg0, s16 arg1, s16 arg2) {
    return func_global_asm_80612790(arg2 - arg1) * arg0;
}

void func_global_asm_806DFFDC(s16 arg0) {
    f32 temp_f0;

    temp_f0 = func_global_asm_806DFFA0(extra_player_info_pointer->unk4, extra_player_info_pointer->unkA, arg0);
    if (temp_f0 > 0.0f) {
        extra_player_info_pointer->unk4 = temp_f0;
    } else {
        extra_player_info_pointer->unk4 = 0.0f;
    }
    extra_player_info_pointer->unkA = arg0;
}

void func_global_asm_806E0050(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unkA = current_actor_pointer->y_rotation;
}

void func_global_asm_806E007C(void) {
    f32 temp_f2;
    f32 phi_f0 = extra_player_info_pointer->unk38;
    if (extra_player_info_pointer->unkC8 == 0) {
        phi_f0 *= 0.5;
    }
    if (extra_player_info_pointer->unkD6 != 0) {
        phi_f0 *= 0.5;
    }
    if ((D_global_asm_807FD610[cc_player_index].unk4 != 0.0f) && ((extra_player_info_pointer->unk1F4 & 8) == 0)) {
        temp_f2 = extra_player_info_pointer->unk34;
        extra_player_info_pointer->unk4 = ((D_global_asm_807FD610[cc_player_index].unk8 * (phi_f0 - temp_f2)) + temp_f2);
        extra_player_info_pointer->unkA = D_global_asm_807FD610[cc_player_index].unk28;
    } else {
        extra_player_info_pointer->unk4 = 0.0f;
        extra_player_info_pointer->unkA = current_actor_pointer->y_rotation;
    }
}

void func_global_asm_806E0178(void) {
    f32 phi_f0;
    f32 phi_f2;

    func_global_asm_806E007C();
    phi_f2 = D_global_asm_807FD610[cc_player_index].unk8;
    if (phi_f2 < 0.3) {
        phi_f2 = 0.3f;
    }
    phi_f0 = ABS(current_actor_pointer->unkEE - extra_player_info_pointer->unkA);
    if (phi_f0 > 2048) {
        phi_f0 = 4096 - phi_f0;
    }
    phi_f0 = MIN(400, phi_f0);
    phi_f0 *= 0.2;
    func_global_asm_806DF494(&current_actor_pointer->unkEE, extra_player_info_pointer->unkA,  phi_f0 * phi_f2);
}

void func_global_asm_806E0294(void) {
    f32 phi_f0;
    f32 phi_f2;

    func_global_asm_806E007C();
    phi_f2 = D_global_asm_807FD610[cc_player_index].unk8;
    if (D_global_asm_807FD610[cc_player_index].unk8 < 0.3) {
        phi_f2 = 0.3f;
    }
    phi_f0 = ABS(current_actor_pointer->unkEE - extra_player_info_pointer->unkA);
    if (phi_f0 > 2048.0f) {
        phi_f0 = 4096.0f - phi_f0;
    }
    phi_f0 = MIN(400, phi_f0);
    phi_f0 *= (extra_player_info_pointer->unk48 / 400.0);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * phi_f2);
}

f32 func_global_asm_806E03C8(f32 arg0, f32 arg1) {
    f32 phi_f2;

    if (D_global_asm_807FD610[cc_player_index].unk30) {
        phi_f2 = MIN(70, D_global_asm_807FD610[cc_player_index].unk30);
        phi_f2 -= 2.0f;
        phi_f2 /= 68.0f;
        return ((arg1 - arg0) * phi_f2) + arg0;
    }
    return 0.0f;
}

f32 func_global_asm_806E0454(f32 arg0, f32 arg1) {
    f32 phi_f2;

    if (D_global_asm_807FD610[cc_player_index].unk31) {
        phi_f2 = MIN(70, D_global_asm_807FD610[cc_player_index].unk31);
        phi_f2 -= 2.0f;
        phi_f2 /= 68.0f;
        return ((arg1 - arg0) * phi_f2) + arg0;
    }
    return 0.0f;
}

void func_global_asm_806E04E0(void) {
    f32 phi_f2;
    f32 phi_f0;
    f32 phi_f3;

    func_global_asm_806E007C();
    if (D_global_asm_807FD610[cc_player_index].unkC > 0.0f) {
        phi_f2 = D_global_asm_807FD610[cc_player_index].unkC;
    } else {
        phi_f2 = -D_global_asm_807FD610[cc_player_index].unkC;
    }
    if (phi_f2 < 14.0f) {
        phi_f3 = (D_global_asm_807FD610[cc_player_index].unk8 * 0.7) + 0.3;
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        phi_f0 = MIN(400, phi_f0);
        phi_f0 *= (extra_player_info_pointer->unk48 / 400.0);
        phi_f2 = phi_f0 * phi_f3;
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f2);
    }
}

void func_global_asm_806E0654(void) {
    func_global_asm_806E007C();
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEA, extra_player_info_pointer->unk48);
}

void func_global_asm_806E0694(void) {
    func_global_asm_806E007C();
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
}

void func_global_asm_806E06E8(void) {
    s16 phi_a1;

    if (current_actor_pointer->unkDA < 0x3C7) {
        phi_a1 = current_actor_pointer->unkD8 + 0x800;
    } else {
        phi_a1 = current_actor_pointer->unkEE + 0x800;
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, phi_a1, extra_player_info_pointer->unk48 / 4);
    extra_player_info_pointer->unk4 = 0.0f;
}

void func_global_asm_806E077C(void) {
    s16 phi_a1;

    if (current_actor_pointer->unkDA < 0x3C7) {
        phi_a1 = current_actor_pointer->unkD8;
    } else {
        phi_a1 = current_actor_pointer->unkEE;
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, phi_a1, extra_player_info_pointer->unk48 / 4);
    extra_player_info_pointer->unk4 = 0.0f;
}

void func_global_asm_806E07F8(void) {
    f32 phi_f0;
    s16 temp_v0_3;
    u8 phi_v0;
    s8 temp;

    func_global_asm_806E007C();
    phi_f0 = ABS(current_actor_pointer->y_rotation - current_actor_pointer->unkEE);
    if (phi_f0 > 2048.0f) {
        phi_f0 = 4096.0f - phi_f0;
    }
    phi_f0 = MIN(400.0f, phi_f0);
    phi_f0 *= (0.25 + (0.75 * (current_actor_pointer->unkB8 / extra_player_info_pointer->unk38)));

    // TODO: Can we get rid of this?
    if(phi_f0);

    func_global_asm_806DF494(
        &current_actor_pointer->y_rotation,
        current_actor_pointer->unkEE,
        extra_player_info_pointer->unk48 / 4);
    if (current_actor_pointer->control_state == 0x14) {
        return;
    }
    if (current_actor_pointer->control_state == 0xF) {
        temp_v0_3 = current_actor_pointer->animation_state->unk0->unk10;
        if ((temp_v0_3 == 0x1F2) || (temp_v0_3 == 0x1B3)) {
            if (D_global_asm_807FD610[cc_player_index].unk2E < -0x1E) {
                playAnimation(current_actor_pointer, 0x61);
                current_actor_pointer->control_state = 0x10;
                current_actor_pointer->control_state_progress = 0;
            } else if (D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) {
                playAnimation(current_actor_pointer, 0x5F);
                current_actor_pointer->control_state = 0x11;
                current_actor_pointer->control_state_progress = 0;
            } else if (D_global_asm_807FD610[cc_player_index].unk2F >= 0x1F) {
                playAnimation(current_actor_pointer, 0x63);
                current_actor_pointer->control_state = 0x12;
                current_actor_pointer->control_state_progress = 0;
            } else if (D_global_asm_807FD610[cc_player_index].unk2F < -0x1E) {
                playAnimation(current_actor_pointer, 0x65);
                current_actor_pointer->control_state = 0x13;
                current_actor_pointer->control_state_progress = 0;
            }
        }
    }
    // Joystick range check
    if (((D_global_asm_807FD610[cc_player_index].unk2E < 0x1E) && ((current_actor_pointer->control_state == 0x11))) || ((((D_global_asm_807FD610[cc_player_index].unk2F > -0x1E) )) && ((current_actor_pointer->control_state == 0x13))) || ((D_global_asm_807FD610[cc_player_index].unk2F < 0x1E) && (current_actor_pointer->control_state == 0x12)) || ((D_global_asm_807FD610[cc_player_index].unk2E >= -0x1D) && (current_actor_pointer->control_state == 0x10))) {
        if ((current_character_index[cc_player_index] == 2) && (current_actor_pointer->control_state != 0x12)) {
            playActorAnimation(current_actor_pointer, 0x191);
        } else {
            if (current_actor_pointer->control_state_progress == 1) {
                switch (current_actor_pointer->control_state) {
                    case 17:
                        playAnimation(current_actor_pointer, 0x60);
                        break;
                    case 16:
                        playAnimation(current_actor_pointer, 0x62);
                        break;
                    case 18:
                        playAnimation(current_actor_pointer, 0x64);
                        break;
                    case 19:
                        playAnimation(current_actor_pointer, 0x66);
                        break;
                }
            } else {
                playAnimation(current_actor_pointer, 0x68);
            }
        }

        current_actor_pointer->control_state = 0xF;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E0BEC(void) {
    f32 phi_f0;
    f32 phi_f2;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        phi_f2 = D_global_asm_807FD610[cc_player_index].unk8;
        phi_f2 *= phi_f2;
        if (phi_f2 < 0.2) {
            phi_f2 = 0.2f;
        }
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        phi_f0 = MIN(400, phi_f0);
        phi_f0 *= extra_player_info_pointer->unk48 / 400.0;
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * phi_f2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E0D40.s")

/*
// TODO: Something missing...
void func_global_asm_806E0D40(void) {
    f32 var_f0;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        var_f0 = ABS( current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (var_f0 > 2048.0f) {
            var_f0 = 4096.0f - var_f0;
        }
        if (var_f0 > 400.0f) {

        }
        current_actor_pointer->y_rotation -= ((D_global_asm_807FD610[cc_player_index].unk2E * extra_player_info_pointer->unk48) / 400);
        if (current_actor_pointer->y_rotation >= 0x1000) {
            current_actor_pointer->y_rotation -= 0x1000;
        }
        if (current_actor_pointer->y_rotation < 0) {
            current_actor_pointer->y_rotation += 0x1000;
        }
    }
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        extra_player_info_pointer->unk1A0 = ((D_global_asm_807FD610[cc_player_index].unk2F * 0xCC) * 0.599999999999999978) + 63000.0;
    }
}
*/

// TODO: Good progress
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E0FAC.s")

typedef struct {
    u8 unk0[0x96 - 0x0];
    u16 unk96[1]; // TODO: How many elements?
    u8 unk98[0xA4 - 0x98];
    u16 unkA4[1]; // TODO: How many elements?
    u8 unkA6[0x478 - 0xA6];
    u16 unk478[1]; // TODO: How many elements?
    u16 unk47A;
    s32 unk47C;
    s32 unk480;
    s16 unk484;
    u16 unk486[1]; // TODO: How many elements?
} Struct807FBB54;

extern Struct807FBB54 D_global_asm_807FBB54;

/*
void func_global_asm_806E0FAC(void) {
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f2;
    f32 var_f2_2;
    s16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a1_5;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        if (current_actor_pointer->unkB8 == 0.0f) {
            temp_f2 = D_global_asm_807FD610[cc_player_index].unk8;
            var_f2 = temp_f2 * temp_f2;
            if (var_f2 < 0.2) {
                var_f2 = 0.2f;
            }
            var_f0 = current_actor_pointer->y_rotation - extra_player_info_pointer->unkA;
            if (var_f0 >= 2048.0f) {
                var_f0 -= 4096.0f;
            }
            if (var_f0 <= -2048.0f) {
                var_f0 += 4096.0f;
            }
            if (var_f0 > 400.0f) {
                var_f0 = 400.0f;
            }
            if (var_f0 < -400.0f) {
                var_f0 = -400.0f;
            }
            temp_f0 = (var_f0 * (extra_player_info_pointer->unk48 / 400.0)) * var_f2;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, ABS(temp_f0));
            if (temp_f0 != 0.0f) {
                if (current_actor_pointer->control_state != 0x3C) {
                    if (current_actor_pointer->control_state == 0x62) {
                        temp_a1_2 = D_global_asm_807FBB54.unk478[current_actor_pointer->unk58];
                        if (temp_a1_2 != current_actor_pointer->animation_state->unk64) {
                            playActorAnimation(current_actor_pointer, temp_a1_2);
                        }
                        func_global_asm_80614D00(current_actor_pointer, temp_f0 / 80.0, 0.0f);
                    }
                } else {
                    temp_a1_3 = D_global_asm_807FBB54.unkA4[current_actor_pointer->unk58];
                    if (temp_a1_3 != current_actor_pointer->animation_state->unk64) {
                        playActorAnimation(current_actor_pointer, temp_a1_3);
                    }
                    func_global_asm_80614D00(current_actor_pointer, temp_f0 / 80.0, 0.0f);
                }
            }
            // goto block_32;
        }
        // goto block_25;
    }
block_25:
    if (current_actor_pointer->control_state != 0x3C) {
        if (current_actor_pointer->control_state == 0x62) {
            temp_a1_4 = D_global_asm_807FBB54.unk486[current_actor_pointer->unk58];
            if (temp_a1_4 != current_actor_pointer->animation_state->unk64) {
                playActorAnimation(current_actor_pointer, temp_a1_4);
            }
        }
    } else if (current_actor_pointer->control_state_progress == 1) {
        temp_a1_5 = D_global_asm_807FBB54.unk96[current_actor_pointer->unk58];
        if (temp_a1_5 != current_actor_pointer->animation_state->unk64) {
            playActorAnimation(current_actor_pointer, temp_a1_5);
        }
    }
    extra_player_info_pointer->unk4 = 0.0f;
}
*/

void func_global_asm_806E1334(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2F < 0) {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BDC[D_global_asm_807FD584], D_global_asm_80753BF8[D_global_asm_807FD584]);
    } else {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BA4[D_global_asm_807FD584], D_global_asm_80753BC0[D_global_asm_807FD584]);
    }
    if (extra_player_info_pointer->unk4 != 0.0f) {
        extra_player_info_pointer->unk8 = extra_player_info_pointer->unk4 > 0.0f ? 1 : -1;
    } else {
        extra_player_info_pointer->unk8 = 0;
    }
    func_global_asm_8072FE60(D_global_asm_807FD610[cc_player_index].unk2F / 80.0);
    current_actor_pointer->y_rotation += D_global_asm_807FD610[cc_player_index].unk2E;
    current_actor_pointer->y_rotation &= 0xFFF;
    func_global_asm_806E1630();
}

void func_global_asm_806E14DC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2F < 0) {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BDC[D_global_asm_807FD584], D_global_asm_80753BF8[D_global_asm_807FD584]);
    } else {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BA4[D_global_asm_807FD584], D_global_asm_80753BC0[D_global_asm_807FD584]);
    }
    if (extra_player_info_pointer->unk4 != 0.0f) {
        extra_player_info_pointer->unk8 = extra_player_info_pointer->unk4 > 0.0f ? 1 : -1;
    } else {
        extra_player_info_pointer->unk8 = 0;
    }
    func_global_asm_8072FE60(D_global_asm_807FD610[cc_player_index].unk2F / 80.0);
}

void func_global_asm_806E1630(void) {
    s16 phi_a1 = FALSE;
    if (extra_player_info_pointer->unk19C < extra_player_info_pointer->unk19E) {
        if ((current_actor_pointer->y_rotation < extra_player_info_pointer->unk19C) || (extra_player_info_pointer->unk19E < current_actor_pointer->y_rotation)) {
            phi_a1 = TRUE;
        }
    } else {
        if ((extra_player_info_pointer->unk19E < current_actor_pointer->y_rotation) && (current_actor_pointer->y_rotation < extra_player_info_pointer->unk19C)) {
            phi_a1 = TRUE;
        }
    }
    if (phi_a1) {
        if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, extra_player_info_pointer->unk19C) < func_global_asm_806CC14C(current_actor_pointer->y_rotation, extra_player_info_pointer->unk19E)) {
            current_actor_pointer->y_rotation = extra_player_info_pointer->unk19C;
        } else {
            current_actor_pointer->y_rotation = extra_player_info_pointer->unk19E;
        }
    }
}

void func_global_asm_806E1728(void) {
    f32 temp_f0 = func_global_asm_806E03C8(D_global_asm_80753DC8[D_global_asm_807FD584], D_global_asm_80753DE4[D_global_asm_807FD584]);
    if (D_global_asm_807FD610[cc_player_index].unk2E < 0) {
        extra_player_info_pointer->unk4 = -temp_f0;
        extra_player_info_pointer->unk8 = -1;
    } else {
        extra_player_info_pointer->unk4 = temp_f0;
        if (temp_f0 != 0.0f) {
            extra_player_info_pointer->unk8 = 1;
        } else {
            extra_player_info_pointer->unk8 = 0;
        }
    }
}

void func_global_asm_806E17F4(void) {
    func_global_asm_806E007C();
    func_global_asm_806DF494(&current_actor_pointer->unkEE, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806DFFDC(current_actor_pointer->y_rotation);
}

void func_global_asm_806E1864(void) {

}

void func_global_asm_806E186C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    current_actor_pointer->z_rotation = 0;
    current_actor_pointer->x_rotation = 0;
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (extra_player_info_pointer->unkC8 == -1)) {
        if (current_actor_pointer->unkE0 != 0.0f) {
            current_actor_pointer->unkEE = current_actor_pointer->unkDC;
            current_actor_pointer->unkB8 = 200.0f;
            extra_player_info_pointer->unk3E = 0x1E;
            extra_player_info_pointer->unk40 = current_actor_pointer->unkDC;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584] * 0.5;
        } else {
            extra_player_info_pointer->unk3C = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        }
        extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
        current_actor_pointer->control_state = 0x17;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk50 = 0;
        playAnimation(current_actor_pointer, 0x10);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E1A50(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    // TODO: Get rid of this typecast if possible
    if ((u32) (D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if (((current_actor_pointer->unk6A & 1) == 0) || 
             (current_actor_pointer->unkE0 == 0.0f)) {
            extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
            current_actor_pointer->control_state = 0x17;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            playActorAnimation(current_actor_pointer, 0xB0);
            extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        }
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E1BA4.s")

/*
void func_global_asm_806E1BA4(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (!(current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkE0 == 0.0f))) {
        extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
        current_actor_pointer->unkB8 = MIN(current_actor_pointer->unkB8, extra_player_info_pointer->unk38);
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
        extra_player_info_pointer->unk2C = 20.0f;
        current_actor_pointer->control_state = 0x17;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        playAnimation(current_actor_pointer, 0x10);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}
*/

void func_global_asm_806E1D38(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (!(current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkE0 == 0.0f))) {
        current_actor_pointer->control_state = 0x17;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        playActorAnimation(current_actor_pointer, 0xAF);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E1E54(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if (current_actor_pointer->y_acceleration == -260.0f) {
            current_actor_pointer->y_acceleration = -31.0f;
        } else {
            setYAccelerationFrom80753578();
        }
        current_actor_pointer->control_state = 0x14;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        playAnimation(current_actor_pointer, 0x67);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E1F8C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (extra_player_info_pointer->unk8D == 0)) {
        current_actor_pointer->control_state = 0x41;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        playActorAnimation(current_actor_pointer, 0x156);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E208C(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) && D_global_asm_807FC950[cc_player_index].character_progress[3].moves >= 2 && current_map != MAP_AZTEC_BEETLE_RACE) {
        setAction(9, NULL, cc_player_index);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E2140(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (D_global_asm_80767CC0 - extra_player_info_pointer->unk58 < 0xFU && (!(current_actor_pointer->unk6A & 1) || current_actor_pointer->unkE0 == 0.0f)) {
        current_actor_pointer->control_state = 0x61;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        playAnimation(current_actor_pointer, 0x50);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

// handle gunshots, jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E225C.s")

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E2B20.s")

/*
u8 func_global_asm_806E2B20(Actor *arg0) {
    f32 x;
    f32 y;
    f32 z;
    f32 phi_f20;
    f32 bone10X;
    f32 bone4X;
    f32 bone10Y;
    f32 bone4Y;
    f32 bone10Z;
    f32 bone4Z;
    s16 sp66;
    s16 sp64;
    u8 phi_v1;

    phi_v1 = 0;
    phi_f20 = 0;
    getBonePosition(arg0, 4, &bone4X, &bone4Y, &bone4Z);
    getBonePosition(arg0, 10, &bone10X, &bone10Y, &bone10Z);
    while (phi_f20 <= 1.0 && !phi_v1) {
        phi_v1 = func_global_asm_80671E00(
            bone4X + ((bone10X - bone4X) * phi_f20),
            bone4Y + ((bone10Y - bone4Y) * phi_f20),
            bone4Z + ((bone10Z - bone4Z) * phi_f20),
            10.0f,
            &sp66,
            &sp64,
            NULL,
            NULL
        );
        phi_f20 += 0.2;
    }
    return phi_v1;
}
*/

void func_global_asm_806E2C74(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;

    PaaD = arg0->PaaD;
    switch (arg0->unk58) {
        case ACTOR_DK:
        case ACTOR_LANKY:
        case ACTOR_TINY:
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
            PaaD->unk90 = 1;
            return;
        default:
            PaaD->unk90 = 1 - PaaD->unk90;
            return;
    }
}

u8 playerCanThrowOrange(void) {
    return !func_global_asm_80714608(0)
        && !(D_global_asm_807FBB64 & 0x200)
        && func_global_asm_806F8AD4(4, cc_player_index)
        && current_character_index[cc_player_index] < 6
        && func_global_asm_8067ACDC(current_actor_pointer, 4, 0) < D_global_asm_80753E64[D_global_asm_807FD584]
        && (isFlagSet(PERMFLAG_ITEM_MOVE_ORANGETHROWING, FLAG_TYPE_PERMANENT) // Is orange barrel completed?
            || (D_global_asm_807FBB64 & 0x10000000)
            || (cc_number_of_players > 1)
            || gameIsInDKTVMode()
            || gameIsInMysteryMenuMinigameMode());
}

void func_global_asm_806E2DE8(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS) && playerCanThrowOrange()) {
        playAnimation(current_actor_pointer, 0x47);
        current_actor_pointer->control_state = 0x2C; // Throwing orange
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E2E6C(void) {
    if (D_global_asm_807FD568->weapon & 1) {
        func_global_asm_806E225C(0, 0);
    }
}

void func_global_asm_806E2EA8(void) {
    func_global_asm_806E225C(1, 0);
}

void func_global_asm_806E2ECC(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == B_BUTTON) {
        playAnimation(current_actor_pointer, 0x54);
    } else {
        func_global_asm_806E225C(0, 0);
    }
}

void func_global_asm_806E2F3C(void) {
    s32 phi_v1 = 1;
    if (cc_number_of_players >= 2) {
        phi_v1 = !func_global_asm_806E56EC();
    }
    if (phi_v1 != 0) {
        if ((current_actor_pointer->control_state != 0x62) && (current_actor_pointer->unk6A & 1)) {
            extra_player_info_pointer->unk48 = D_global_asm_80753354[D_global_asm_807FD584];
            current_actor_pointer->control_state = 0x62;
            current_actor_pointer->control_state_progress = 0;
            playAnimation(current_actor_pointer, 0x52);
        }
    }
}

void func_global_asm_806E2FE8(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG)) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
}

// regalloc v1 a2
// https://decomp.me/scratch/0BloP
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E3040.s")

extern f32 D_global_asm_8075371C[];
extern f32 D_global_asm_8075378C[];

/*
void func_global_asm_806E3040(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU)) {
        if (current_character_index[cc_player_index] != 6) {
            if (!(current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkE0 == 0.0f)) {
                if (extra_player_info_pointer->unk20 > 70.0f) {
                    current_actor_pointer->control_state = 0x1D;
                    current_actor_pointer->control_state_progress = 0;
                    extra_player_info_pointer->unk54 = D_global_asm_8075378C[D_global_asm_807FD584];
                    extra_player_info_pointer->unk50 = 0;
                    playAnimation(current_actor_pointer, 0x1A);
                    extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
                } else {
                    current_actor_pointer->control_state = 0x3E;
                    current_actor_pointer->control_state_progress = 0;
                    extra_player_info_pointer->unk54 = D_global_asm_8075371C[D_global_asm_807FD584];
                    extra_player_info_pointer->unk50 = 0;
                    playAnimation(current_actor_pointer, 0xE);
                    extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
                }
            }
        }
    }
}
*/

void func_global_asm_806E31FC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if ((current_actor_pointer->control_state == 0x17) && (((current_actor_pointer->unk6A & 1) == 0) || (current_actor_pointer->unkE0 == 0.0f))) {
            current_actor_pointer->control_state = 0x17;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            playAnimation(current_actor_pointer, 0x10);
        }
    }
}

void func_global_asm_806E330C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if ((current_actor_pointer->control_state == 0x61) && (((current_actor_pointer->unk6A & 1) == 0) || (current_actor_pointer->unkE0 == 0.0f))) {
            current_actor_pointer->control_state = 0x61;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            playAnimation(current_actor_pointer, 0x50);
        }
    }
}

void func_global_asm_806E341C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280;
    }
    if ((D_global_asm_80767A40.unk280 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 0x58;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk50 = 0;
        extra_player_info_pointer->unk3E = 0;
        extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280 - 0x1E;
    }
}

void func_global_asm_806E34D8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & R_TRIG) {
        current_actor_pointer->unkEE = (current_actor_pointer->unkEE + 0x800) & 0xFFF;
    }
}

void func_global_asm_806E352C(void) {
    current_actor_pointer->unk6A &= ~0x40;
    extra_player_info_pointer->unk100 = D_global_asm_80753C94[D_global_asm_807FD584];
    current_actor_pointer->control_state = 0x17;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->unkB8 = 0.0f;
    extra_player_info_pointer->unk54 = D_global_asm_80753D08[D_global_asm_807FD584];
    extra_player_info_pointer->unk50 = 0;
    playAnimation(current_actor_pointer, 0x10);
}

void func_global_asm_806E35D8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    // TODO: Get rid of this typecast if possible
    if ((u32) (D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 0x5A;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk3E = 0;
        extra_player_info_pointer->unk50 = 0;
        playAnimation(current_actor_pointer, 0x74);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E36B4.s")

/*
void func_global_asm_806E36B4(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((u32) (D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 0x4C;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        switch ((u32)extra_player_info_pointer->unk1AC->unk58) {
            // TODO: Use Actors enum
            case 0x3D:
            case 0x3F:
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x55:
            case 0x82:
                playActorAnimation(current_actor_pointer, 0x1CB);
                break;
            default:
                playAnimation(current_actor_pointer, 0x30);
                break;
        }
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}
*/

void func_global_asm_806E380C(void) {
    func_global_asm_806CFEA4();
}

void func_global_asm_806E382C(void) {
    setYAccelerationFrom80753578();
}

void func_global_asm_806E384C(void) {
    s32 temp_f18;
    f32 temp_f2;
    f32 phi_f0;

    phi_f0 = extra_player_info_pointer->unk1A0 + 0x9E8;
    if (phi_f0 >= 32768) {
        phi_f0 -= 65536;
    }
    phi_f0 /= 16;
    if (current_actor_pointer->unk6E[0] == -1) {
        func_global_asm_80604CBC(current_actor_pointer, 0x114, 0, 0, 0, 0xFF, 1.0f, 0);
    }
    current_actor_pointer->y_acceleration = (-2 * D_global_asm_807536E4[D_global_asm_807FD584] * func_global_asm_80612790(phi_f0)) + D_global_asm_807536E4[D_global_asm_807FD584];
    if (current_actor_pointer->y_velocity < 0) {
        current_actor_pointer->y_acceleration -= (current_actor_pointer->y_velocity / 100.0);
    }
    if (current_actor_pointer->unk6A & 1) {
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    } else {
        temp_f2 = func_global_asm_80612794(phi_f0) * 8.0f;
        if (temp_f2 >= 0) {
            phi_f0 = current_actor_pointer->y_rotation;
        } else {
            phi_f0 = current_actor_pointer->y_rotation + 0x800;
            if (phi_f0 > 4096) {
                phi_f0 -= 4096;
            }
        }
        extra_player_info_pointer->unk2C = ABS(temp_f2);
        func_global_asm_806CD424(phi_f0, 900, extra_player_info_pointer->unk38);
        extra_player_info_pointer->unk30 = ((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / 10000.0f) + 1.0f;
    }
    extra_player_info_pointer->unk1A2 = 1;
}

void func_global_asm_806E3B00(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        if (func_global_asm_806F8AD4(5, cc_player_index) && (extra_player_info_pointer->unk1A3)) {
            func_global_asm_806E384C();
        } else {
            func_global_asm_80605314(current_actor_pointer, 0);
            current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = ((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / 10000.0f) + 1.0f;
        }
    } else {
        current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
    }
    func_global_asm_806CD8EC();
}

void func_global_asm_806E3C14(void) {
    func_global_asm_806F142C(current_actor_pointer);
}

void func_global_asm_806E3C38(void) {
    f32 temp_f0;

    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        func_global_asm_80605314(current_actor_pointer, 0);
    }
    current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
    temp_f0 = current_actor_pointer->unkB8;
    extra_player_info_pointer->unk30 = ((temp_f0 * temp_f0) / 10000.0f) + 1.0f;
    func_global_asm_806CD8EC();
}

void func_global_asm_806E3CEC(void) {
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
}

void func_global_asm_806E3D14(f32 arg0) {
    f32 phi_f0;

    if (extra_player_info_pointer->unk1A0 < 0x8000) {
        phi_f0 = extra_player_info_pointer->unk1A0 + 0x10000;
    } else {
        phi_f0 = extra_player_info_pointer->unk1A0;
    }
    if (arg0 < phi_f0) {
        phi_f0 -= 3000.0f;
        phi_f0 = MAX(arg0, phi_f0);
    }
    if (phi_f0 < arg0) {
        phi_f0 += 3000.0f;
        phi_f0 = MIN(arg0, phi_f0);
    }
    extra_player_info_pointer->unk1A0 = phi_f0;
}

// rodata regalloc close
// https://decomp.me/scratch/Tovqc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E3E40.s")

extern u8 D_global_asm_807FD6E0;
extern u8 D_global_asm_807FD6E1;

/*
void func_global_asm_806E3E40(void) {
    f32 sp34; // sp34
    s32 pad; // sp30
    f32 var_f12;
    f32 var_f2;

    if (!func_global_asm_806F8AD4(5, cc_player_index) || !extra_player_info_pointer->unk1A3) {
        return;
    }

    if (D_global_asm_807FD610[cc_player_index].unk2C & 0x2000) {
        D_global_asm_807FD6E0 = 0;
        D_global_asm_807FD6E1 = 0;
    }
    sp34 = (current_actor_pointer->unkEE - current_actor_pointer->y_rotation);
    if (sp34 < 0) {
        sp34 += 4096;
    }
    var_f2 = func_global_asm_80612794(sp34) * current_actor_pointer->unkB8;
    if (ABS(var_f2) > 10) {
        var_f12 = sp34 > 2048 ? 1024 : 3072;
        var_f12 += current_actor_pointer->y_rotation;
        if (var_f12 >= 4096) {
            var_f12 -= 4096;
        }
        extra_player_info_pointer->unk2C = 8;
        func_global_asm_806CD424(var_f12, 0, extra_player_info_pointer->unk38);
    }
    sp34 = func_global_asm_80612790(sp34) * current_actor_pointer->unkB8;
    var_f2 = current_actor_pointer->y_velocity;
    if (var_f2 > 0) {
        var_f2 = 0;
    }
    if (ABS(sp34) > 10) {
        var_f12 = 63000.0 + (((func_global_asm_80611BB4(ABS(var_f2), sp34) - 1.570796371f) * 16384.0) / 1.57079637050628662);
    } else {
        var_f12 = 63000.0f;
    }
    func_global_asm_806E3D14(var_f12);
    if (((ABS(sp34) > 10) || (current_actor_pointer->y_velocity < 0))) {
        if (D_global_asm_807FD6E1 == 0) {
            D_global_asm_807FD6E0 = 4;
        }
    }
    if (D_global_asm_807FD6E0 != 0) {
        D_global_asm_807FD6E0 -= 1;
        if (D_global_asm_807FD6E0 == 0) {
            D_global_asm_807FD6E1 = 8;
        }
        func_global_asm_806E384C();
    } else {
        func_global_asm_80605314(current_actor_pointer, 0);
    }
    if (D_global_asm_807FD6E1 != 0) {
        D_global_asm_807FD6E1--;
    }
}
*/

void func_global_asm_806E41B4(void) {
    playAnimation(current_actor_pointer, 0x15);
    current_actor_pointer->control_state_progress = 7;
}

void func_global_asm_806E41EC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
    // Barrel Barrel Complete Flag Check
    if ((D_global_asm_807FBB8C != 0) && (isFlagSet(PERMFLAG_ITEM_MOVE_BARRELTHROWING, FLAG_TYPE_PERMANENT) || ((D_global_asm_807FBB64 * 8) < 0) || (cc_number_of_players >= 2) || gameIsInMysteryMenuMinigameMode())) {
        setAction(3, NULL, cc_player_index);
        return;
    }
    if (!func_global_asm_806E4580() && (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) && (current_actor_pointer->unk6A & 1)) {
        if (current_character_index[cc_player_index] == 6) {
            if (D_global_asm_807FD610[cc_player_index].unk2A & 0x2000) {
                current_actor_pointer->control_state = 0x2F;
                current_actor_pointer->control_state_progress = 0;
                playAnimation(current_actor_pointer, 0x48);
                extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
                extra_player_info_pointer->unk38 = D_global_asm_8075381C[D_global_asm_807FD584];
                extra_player_info_pointer->unk30 = D_global_asm_8075382C[D_global_asm_807FD584];
                extra_player_info_pointer->unk48 = D_global_asm_8075385C[D_global_asm_807FD584];
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                return;
            }
            current_actor_pointer->control_state = 0x29;
            current_actor_pointer->control_state_progress = 0;
            playActorAnimation(current_actor_pointer, 0x1DF);
            extra_player_info_pointer->unk64 = 0;
            extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
            return;
        }
        if (!func_global_asm_80714608(0) && D_global_asm_807531E0[D_global_asm_807FD584] <= extra_player_info_pointer->unk20 && (current_actor_pointer->unkE0 == 0.0f)) {
            playAnimation(current_actor_pointer, 0x44);
            current_actor_pointer->control_state = 0x29;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer->unkEA = current_actor_pointer->unkEE;
            current_actor_pointer->unkB8 = 150.0f;
            extra_player_info_pointer->unk38 = 150.0f;
        } else {
            playAnimation(current_actor_pointer, 0x3F);
            current_actor_pointer->control_state = 0x26;
            current_actor_pointer->control_state_progress = 0;
        }
        extra_player_info_pointer->unkC8 = 0x32;
        extra_player_info_pointer->unk64 = 0;
    }
}

s32 func_global_asm_806E4580(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) && D_global_asm_807FBB70.unk2 && D_global_asm_807FBB70.unk14 == 8) {
        extra_player_info_pointer->unk220 = D_global_asm_807FBB70.unk4;
        extra_player_info_pointer->unk224 = D_global_asm_807FBB70.unk8;
        extra_player_info_pointer->unk228 = D_global_asm_807FBB70.unkC;
        setAction(0x1F, NULL, cc_player_index);
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806E4634(void) {
    f32 temp_f2;
    f32 phi_f0;

    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        phi_f0 = current_actor_pointer->distance_from_floor;
        if (current_actor_pointer->unk6A & 2) {
            temp_f2 = current_actor_pointer->y_position - current_actor_pointer->unkAC;
            if (!(phi_f0 < temp_f2)) {
                phi_f0 = temp_f2;
            }
        }
        if ((phi_f0 > 3.0f) && current_character_index[cc_player_index] != 6) {
            setAction(0xF, NULL, cc_player_index);
        }
    }
}

// TODO: Very close, just an issue with the branches in the first switch case
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E4740.s")

extern f32 D_global_asm_8075318C[];

/*
void func_global_asm_806E4740(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        if (D_global_asm_8075318C[D_global_asm_807FD584] < extra_player_info_pointer->unk20) {
            switch (current_character_index[cc_player_index]) {
                case 3:
                    current_actor_pointer->y_velocity = 200.0f;
                case 5:
                    setYAccelerationFrom80753578();
                    current_actor_pointer->control_state = 0x2B;
                    current_actor_pointer->control_state_progress = 0;
                    playAnimation(current_actor_pointer, 0x45);
                    extra_player_info_pointer->unkC8 = 0x32;
                    break;
                default:
                case 0:
                    switch (current_character_index[cc_player_index]) {
                        case 2:
                            if (D_global_asm_807FC950[cc_player_index].character_progress[2].moves > 0) {
                                setAction(0x25, NULL, cc_player_index);
                            }
                            break;
                        case 4:
                            if (D_global_asm_807FC950[cc_player_index].character_progress[4].moves > 1) {
                                setAction(0x26, NULL, cc_player_index);
                            }
                            break;
                        case 1:
                            if (D_global_asm_807FC950[cc_player_index].character_progress[1].moves > 0) {
                                extra_player_info_pointer->unk48 = 0x64;
                                current_actor_pointer->control_state = 0x2E;
                                current_actor_pointer->control_state_progress = 0;
                                playAnimation(current_actor_pointer, 0x48);
                                extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584] * 4;
                                extra_player_info_pointer->unk38 = D_global_asm_8075381C[D_global_asm_807FD584] * 2;
                                extra_player_info_pointer->unk30 = D_global_asm_8075382C[D_global_asm_807FD584];
                            }
                            break;
                        case 6:
                            current_actor_pointer->control_state = 0x2F;
                            current_actor_pointer->control_state_progress = 0;
                            playAnimation(current_actor_pointer, 0x48);
                            extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
                            extra_player_info_pointer->unk38 = D_global_asm_8075381C[D_global_asm_807FD584];
                            extra_player_info_pointer->unk30 = D_global_asm_8075382C[D_global_asm_807FD584];
                            extra_player_info_pointer->unk48 = D_global_asm_8075385C[D_global_asm_807FD584];
                            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                            break;
                    }
                    break;
            }
        }
    }
}
*/

extern f32 D_global_asm_80750FF4;

void func_global_asm_806E4AD8(void) {
    s16 sp3E;
    s16 sp3C;
    u8 temp2;
    u8 var_t0;
    f32 var_f0;
    var_t0 = 1;
    if ((D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG) && (extra_player_info_pointer->unk1AC->unkFC == 0)) {
        var_f0 = extra_player_info_pointer->unk1AC->unk58 == ACTOR_BOULDER ? D_global_asm_80750FF4 : 30.0f;
        if ((func_global_asm_80671E00(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, var_f0, &sp3E, &sp3C, 1, 0)) && !func_global_asm_806725E4(sp3E, sp3C, current_actor_pointer->y_rotation, 0)) {
            var_t0 = 0;
        }
        if (var_t0) {
            current_actor_pointer->control_state = 0x4A;
            current_actor_pointer->control_state_progress = 0;
            switch ((u32)extra_player_info_pointer->unk1AC->unk58) {
                case ACTOR_BOULDER:
                case ACTOR_VASE_OVAL:
                case ACTOR_VASE_DOTS:
                case ACTOR_VASE_TRIANGLE:
                case ACTOR_VASE_PLUS:
                case ACTOR_STEEL_KEG:
                case ACTOR_APPLE:
                    playActorAnimation(current_actor_pointer, 0x1CD);
                    return;
                default:
                    playAnimation(current_actor_pointer, 0x2C);
                    break;
            }
        }
    }
}

void func_global_asm_806E4C6C(void) {
    if ((extra_player_info_pointer->unk1AC->unk58 != ACTOR_STEEL_KEG) && (extra_player_info_pointer->unk1AC->unk58 != ACTOR_APPLE)) {
        current_actor_pointer->control_state = 0x4B;
        current_actor_pointer->control_state_progress = 0;
        switch (extra_player_info_pointer->unk1AC->unk58) {
            case ACTOR_BOULDER:
            case ACTOR_VASE_OVAL:
            case ACTOR_VASE_DOTS:
            case ACTOR_VASE_TRIANGLE:
            case ACTOR_VASE_PLUS:
                playActorAnimation(current_actor_pointer, 0x1CC);
                return;
            default:
                playAnimation(current_actor_pointer, 0x2D);
                break;
        }
    }
}

void func_global_asm_806E4D14(void) {
    u32 actorBehaviourIndex = extra_player_info_pointer->unk1AC->unk58;
    if ((actorBehaviourIndex != ACTOR_STEEL_KEG) && (actorBehaviourIndex != ACTOR_APPLE)) {
        current_actor_pointer->y_velocity = 200.0f;
        current_actor_pointer->control_state = 0x4D;
        current_actor_pointer->control_state_progress = 0;
        playAnimation(current_actor_pointer, 0x2D);
    }
}

void func_global_asm_806E4D84(void) {
    if (!func_global_asm_806E56EC()) {
        if (extra_player_info_pointer->unkC8 == -1) {
            if (current_character_index[cc_player_index] != 6 || current_actor_pointer->unkB8 < D_global_asm_807531E0[D_global_asm_807FD584]) {
                current_actor_pointer->control_state = 0x3C;
                current_actor_pointer->control_state_progress = 0;
                playAnimation(current_actor_pointer, 0xA);
                extra_player_info_pointer->unk48 = D_global_asm_807534D4[D_global_asm_807FD584];
            }
            extra_player_info_pointer->unk30 = D_global_asm_807534B8[D_global_asm_807FD584];
        }
    }
}

void func_global_asm_806E4E88(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS) && playerCanThrowOrange()) {
        func_global_asm_80618104(current_actor_pointer);
        func_global_asm_80617770(current_actor_pointer, 0x21, 0x19);
    }
    if (D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS) {
        if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk60) < 0xFU) {
            if (extra_player_info_pointer->unk8C != 0) {
                func_global_asm_806F0B34(current_actor_pointer);
            }
            extra_player_info_pointer->unk8C = 0;
            func_global_asm_806EAB44(current_actor_pointer, 0);
        } else if (!func_global_asm_80714608(0) && !(D_global_asm_807FBB64 & 0x80000200) && (D_global_asm_807FD568->weapon & 1)) {
            if (((extra_player_info_pointer->unk1F0 & 0x30) == 0) && (character_change_array[cc_player_index].unk2C0 == 1)) {
                func_global_asm_806DF44C(current_actor_pointer, extra_player_info_pointer, 1);
            }
        }
        extra_player_info_pointer->unk60 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E5044(void) {
    if (((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS)) && (playerCanThrowOrange())) {
        func_global_asm_80618104(current_actor_pointer);
        func_global_asm_80617770(current_actor_pointer, 0x21, 0x19);
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS)) {
        if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk60) < 0xFU) {
            if (extra_player_info_pointer->unk8C != 0) {
                func_global_asm_806F0B34(current_actor_pointer);
            }
            extra_player_info_pointer->unk8C = 0;
            func_global_asm_806EAB44(current_actor_pointer, 0);
        } else if (!func_global_asm_80714608(0) && !(D_global_asm_807FBB64 & 0x200) && (D_global_asm_807FD568->weapon & 1) && (character_change_array[cc_player_index].unk2C0 == 1)) {
            func_global_asm_806DF44C(current_actor_pointer, extra_player_info_pointer, 1);
            character_change_array[cc_player_index].fov_y = 45.0f;
        }
        extra_player_info_pointer->unk60 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E521C(void) {
    if (func_global_asm_80714608(0)) {
        switch (current_actor_pointer->control_state) {
            case 0x31:
            case 0x32:
                if (extra_player_info_pointer->unk8C == 0) {
                    func_global_asm_806E4D84();
                }
        }
    }
}

s32 func_global_asm_806E527C(void) {
    Actor *temp_v0;
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    for (i = 0; i < D_global_asm_807FBB34 && var_v1 == 0; i++) {
        temp_v0 = D_global_asm_807FB930[i].unk0;
        var_v1 = temp_v0->object_properties_bitfield & 0x02000000;
    }
    return var_v1;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E52D0.s")

s32 func_global_asm_806E5488(Actor *arg0);

/*
void func_global_asm_806E52D0(void) {
    u8 temp_v1;

    if ((D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS)
        && (object_timer >= 3U)
        && (D_global_asm_807FD568->instrument & 1)
        && !(D_global_asm_807FBB64 & 0x4000)
        && !(D_global_asm_807FBB68 & 1)
        && (character_change_array[cc_player_index].unk2C0 != 2)
        && (func_global_asm_806E5488(current_actor_pointer) == 0)
        && (func_global_asm_806E527C() == 0)
        && (extra_player_info_pointer->unk245 == 0)) {
        temp_v1 = func_global_asm_806E560C(current_actor_pointer);
        if (current_map != MAP_KROOL_FIGHT_LANKY_PHASE || temp_v1) {
            if (func_global_asm_806F8AD4(7, cc_player_index) || temp_v1) {
                setAction(0x53, NULL, extra_player_info_pointer->unk1A4);
                if (!(D_global_asm_807FBB68 & 2)) {
                    current_actor_pointer->noclip_byte = 1;
                }
                if (!temp_v1) {
                    changeCollectableCount(7, cc_player_index, -1);
                }
            }
            if (!temp_v1) {
                func_global_asm_806F8BC4(7, 0, 0);
            }
        }
    }
}
*/

s32 func_global_asm_806E5488(Actor *arg0) {
    if (arg0->locked_to_pad == 1) {
        f32 dx = arg0->unk94 - arg0->unk88;
        f32 dz = arg0->unk98 - arg0->unk90;
        if (sqrtf(SQ(dx) + SQ(dz)) > 1.0) {
            return TRUE;
        }
    }
    if (arg0->unk6A & 8) {
        f32 dx = arg0->x_position - arg0->unk88;
        f32 dy = arg0->y_position - arg0->unk8C;
        f32 dz = arg0->z_position - arg0->unk90;
        if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) > 1.0) {
            return TRUE;
        }
    }
    // Prop Behavior: Mushroom (0x88)
    if ((arg0->locked_to_pad == 1) && (func_global_asm_8063C328(arg0->unk10C) == 0x88)) {
        return TRUE;
    }
    // Prop Behavior: Wooden Platform (Castle) (0x219)
    if ((arg0->locked_to_pad == 1) && (func_global_asm_8063C328(arg0->unk10C) == 0x219)) {
        return TRUE;
    }
    // Prop Behavior: Metal Platform (0x132)
    if ((arg0->locked_to_pad == 1) && (func_global_asm_8063C328(arg0->unk10C) == 0x132)) {
        return TRUE;
    }
    return FALSE;
}

u8 func_global_asm_806E560C(Actor *arg0) {
    u8 sp1F;

    sp1F = FALSE;
    if (arg0->locked_to_pad == 1) {
        switch (func_global_asm_8063C328(arg0->unk10C)) {
            case 0xA8:
                if (arg0->unk58 == ACTOR_DK) {
                    sp1F = TRUE;
                }
                break;
            case 0xA9:
                if (arg0->unk58 == ACTOR_DIDDY) {
                    sp1F = TRUE;
                }
                break;
            case 0xAA:
                if (arg0->unk58 == ACTOR_TINY) {
                    sp1F = TRUE;
                }
                break;
            case 0xAB:
                if (arg0->unk58 == ACTOR_CHUNKY) {
                    sp1F = TRUE;
                }
                break;
            case 0xAC:
                if (arg0->unk58 == ACTOR_LANKY) {
                    sp1F = TRUE;
                }
                break;
        }
    }
    return sp1F;
}

extern u8 D_global_asm_807F6903;
extern f32 D_global_asm_807536AC[];
extern s32 D_global_asm_8076A094;
extern u8 D_global_asm_8076A0B2;

s32 func_global_asm_806E56EC(void) {
    s32 i;

    if (D_global_asm_807FBB70.unk2 != 0) {
        switch (D_global_asm_807FBB70.unk14) {
            case 9:
                if (extra_player_info_pointer->unk268 == 0) {
                    extra_player_info_pointer->unk204 = D_global_asm_807FBB70.unk4;
                    extra_player_info_pointer->unk208 = D_global_asm_807FBB70.unk8;
                    extra_player_info_pointer->unk20C = D_global_asm_807FBB70.unkC;
                    extra_player_info_pointer->unk21C = D_global_asm_807FBB70.unk10;
                    setAction(0x1E, NULL, cc_player_index);
                    func_global_asm_806C93E4(current_actor_pointer, extra_player_info_pointer);
                    return TRUE;
                }
                break;
            case 5:
                if (D_global_asm_807F6903 == 0) {
                    D_global_asm_8076A094++;
                    if (D_global_asm_8076A094 < 0x5DD) {
                        extra_player_info_pointer->unk204 = D_global_asm_807FBB70.unk4;
                        extra_player_info_pointer->unk208 = D_global_asm_807FBB70.unk8;
                        extra_player_info_pointer->unk20C = D_global_asm_807FBB70.unkC;
                        setAction(0x1C, NULL, cc_player_index);
                        func_global_asm_806C93E4(current_actor_pointer, extra_player_info_pointer);
                        return TRUE;
                    }
                }
                break;
            case 3:
                if (D_global_asm_807F6903 == 0) {
                    D_global_asm_8076A094++;
                    if (D_global_asm_8076A094 < 0x5DD) {
                        extra_player_info_pointer->unk204 = D_global_asm_807FBB70.unk4;
                        extra_player_info_pointer->unk208 = D_global_asm_807FBB70.unk8;
                        extra_player_info_pointer->unk20C = D_global_asm_807FBB70.unkC;
                        setAction(0x1D, NULL, cc_player_index);
                        func_global_asm_806C93E4(current_actor_pointer, extra_player_info_pointer);
                        return TRUE;
                    }
                }
                break;
            case 10:
                if (D_global_asm_8076A0B2 == 0) {
                    playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xE6, 0xFF, 0x7F, 0, 0, 0.3f, 0);
                    func_global_asm_805FF158(0);
                    func_global_asm_805FF9AC(D_global_asm_807FBB70.unk10, D_global_asm_807FBB70.unk12, 0, 0);
                }
                return TRUE;
            case 4:
                if (!(extra_player_info_pointer->unk1F0 & 0x40)) {
                    func_global_asm_806F1250(player_pointer);
                    extra_player_info_pointer->unk1FE = D_global_asm_807FBB70.unk10;
                }
                return TRUE;
            case 0:
                if ((u32)object_timer >= 4) {
                    playCutscene(current_actor_pointer, 0x26, 5);
                    playSoundAtActorPosition(current_actor_pointer, 0x18, 0xFF, 0x7F, 0x19);
                    current_actor_pointer->control_state = 0x18;
                    current_actor_pointer->control_state_progress = 0;
                    current_actor_pointer->noclip_byte = 1;
                    extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584] * 2.5;
                    extra_player_info_pointer->unk50 = 0x28;
                    playAnimation(current_actor_pointer, 0x22);
                    func_global_asm_8060098C(func_global_asm_806E5C2C, 0x14, D_global_asm_807FBB70.unk10, D_global_asm_807FBB70.unk12, 0);
                    for (i = 0; i != 0x14; i++) {
                        func_global_asm_807149B8(1);
                        func_global_asm_8071498C(func_global_asm_8071F034);
                        func_global_asm_8071496C(i);
                        drawSpriteAtPosition(&D_global_asm_8072014C, 0.8f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                    }
                    func_global_asm_80686CF8(player_pointer);
                    return TRUE;
                }
                break;
            case 2:
                current_actor_pointer->control_state = 0x1B;
                current_actor_pointer->control_state_progress = 0;
                extra_player_info_pointer->unk54 = D_global_asm_807536AC[D_global_asm_807FD584];
                extra_player_info_pointer->unk50 = 0;
                playAnimation(current_actor_pointer, 0x14);
                return TRUE;
            case 6:
                current_actor_pointer->control_state = 0x6E;
                current_actor_pointer->control_state_progress = 0;
                current_actor_pointer->y_velocity = 0.0f;
                current_actor_pointer->y_acceleration = (D_global_asm_807FBB70.unk10 * 0.2) + 2.0;
                extra_player_info_pointer->unkC0 = D_global_asm_807FBB70.unk12;
                playActorAnimation(current_actor_pointer, 0x169);
                return TRUE;
            case 7:
                current_actor_pointer->noclip_byte = 1;
                extra_player_info_pointer->unk242 = D_global_asm_807FBB70.unk10;
                current_actor_pointer->control_state = 0x76;
                current_actor_pointer->control_state_progress = 0;
                playAnimation(current_actor_pointer, 0x86);
                return TRUE;
            default:
                break;
        }
    }
    return FALSE;
}

void func_global_asm_806E5C2C(Maps map, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        setIntroStoryPlaying(2);
        func_global_asm_805FF158(0);
    }
    func_global_asm_805FF9AC(map, 0, 0, 0);
}

int func_global_asm_806E5C74(void) {
    f32 temp_f2;
    f32 phi_f0;

    phi_f0 = current_actor_pointer->distance_from_floor;
    if (current_actor_pointer->unk6A & 2) {
        temp_f2 = current_actor_pointer->y_position - current_actor_pointer->unkAC;
        if (!(phi_f0 < temp_f2)) {
            phi_f0 = temp_f2;
        }
    }
    return D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG
        && extra_player_info_pointer->unk1CC * 66.0 < phi_f0
        && current_character_index[cc_player_index] != 6
        && D_global_asm_807FD568->simian_slam != 0;
}

void func_global_asm_806E5D60(void) {
    if (func_global_asm_806E5C74()) {
        switch (D_global_asm_807FD568->simian_slam) {
            case 2:
                playAnimation(current_actor_pointer, 0x17);
                func_global_asm_80613AF8(current_actor_pointer, 0x18, 0, 3.0f);
                func_global_asm_80614D00(current_actor_pointer, 1.35f, 0);
                break;
            case 3:
                playAnimation(current_actor_pointer, 0x19);
                break;
            default:
                playAnimation(current_actor_pointer, 0x16);
                func_global_asm_80613AF8(current_actor_pointer, 0x17, 0, 3.0f);
                func_global_asm_80614D00(current_actor_pointer, 1.35f, 0);
                break;
        }
        current_actor_pointer->control_state = 0x1C;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E5E58(void) {

}

void func_global_asm_806E5E60(void) {

}

void func_global_asm_806E5E68(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x20)) {
        setAction(0x24, NULL, cc_player_index);
    }
}

void func_global_asm_806E5EA8(void) {
    setAction(0x24, NULL, cc_player_index);
}

void func_global_asm_806E5ED4(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS)
        && (D_global_asm_807FD568->weapon & 1)
        && (character_change_array[cc_player_index].unk2C0 == 1)
        && !(extra_player_info_pointer->unk1F0 & 0x30)
        && !func_global_asm_80714608(0)) {
        setAction(0x14, NULL, cc_player_index);
    }
}

void func_global_asm_806E5FA0(void) {
    if (((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS))
        && (D_global_asm_807FD568->weapon & 1)
        && !(D_global_asm_807FBB64 & 0x200)
        && (character_change_array[cc_player_index].unk2C0 == 1)
        && !(extra_player_info_pointer->unk1F0 & 0x30)
        && !func_global_asm_80714608(0)) {
        setAction(0x15, NULL, cc_player_index);
    }
}

void func_global_asm_806E607C(void) {
    PlayerAdditionalActorData *temp_v0; // TODO: Probably not actually a PaaD

    temp_v0 = extra_player_info_pointer->unk104->PaaD;
    temp_v0->unkAC |= 4;
    if (((D_global_asm_807FD610[cc_player_index].unk2C & R_TRIG))) {
        if ((D_global_asm_807FBB64 & 1) || ((cc_number_of_players >= 2) && (D_global_asm_80750AB8 == 0))) {
            if (temp_v0->unkAC & 0x10000) {
                func_global_asm_806261CC(extra_player_info_pointer->unk104);
                return;
            }
            func_global_asm_80626110(extra_player_info_pointer->unk104, 0, 0);
            return;
        }
        if ((temp_v0->unkAC & 0x4000) == 0) {
            temp_v0->unkAC ^= 2;
            if ((temp_v0->unkF0_u8[1] < 3) && (temp_v0->unkF4_u8[1] == 0) && (temp_v0->unkF0_u8[3] != 2)) {
                temp_v0->unkF0_u8[1] = 0x14;
                temp_v0->unkB2 = current_actor_pointer->y_rotation;
                extra_player_info_pointer->unk104->distance_from_floor = temp_v0->unkB8;
                temp_v0->unkF4_u8[1] = 0xA;
            }
        }
    }
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC;
    s32 unk10; s32 unk14; s32 unk18; s32 unk1C;
    s32 unk20; s32 unk24; s32 unk28; s32 unk2C;
    s32 unk30; s32 unk34; s32 unk38; s32 unk3C;
    s32 unk40; s32 unk44; s32 unk48; s32 unk4C;
    s32 unk50; s32 unk54; s32 unk58; s32 unk5C;
    s32 unk60; s32 unk64; s32 unk68; s32 unk6C;
    s32 unk70; s32 unk74; s32 unk78; s32 unk7C;
    s32 unk80; s32 unk84; s32 unk88; s32 unk8C;
    s32 unk90; s32 unk94; s32 unk98; s32 unk9C;
    s32 unkA0; s32 unkA4; s32 unkA8; s32 unkAC;
} AAD_global_asm_806E61D0;

void func_global_asm_806E61D0(void) {
    AAD_global_asm_806E61D0 *temp_v0;

    if (((D_global_asm_807FBB64 & 1) == 0) && ((cc_number_of_players < 2) || (D_global_asm_80750AB8 != 0))) {
        temp_v0 = extra_player_info_pointer->unk104->additional_actor_data;
        temp_v0->unk4 = 0;
        temp_v0->unkAC &= ~4;
    }
}

void func_global_asm_806E6234(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & START_BUTTON)
        && !func_global_asm_8061CB50()
        && (D_global_asm_807FD888 == 0.0f)
        && (gameIsInAdventureMode() || gameIsInMysteryMenuMinigameMode() || gameIsInDKTVMode())
        && !func_global_asm_8062919C()
        && !func_global_asm_806291A8()) {
        D_global_asm_807FC8B9 = cc_player_index;
        global_properties_bitfield |= 1;
    }
}

void func_global_asm_806E6318(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E6368(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E63B8(void) {
    f32 temp_f0;

    if (D_global_asm_807FD610[cc_player_index].unk4 != 0.0f) {
        temp_f0 = extra_player_info_pointer->unk34;
        extra_player_info_pointer->unk4 = (D_global_asm_807FD610[cc_player_index].unk8 * (extra_player_info_pointer->unk38 - temp_f0)) + temp_f0;
    } else {
        extra_player_info_pointer->unk4 = 0.0f;
    }
    extra_player_info_pointer->unk4 /= 4;
    if (D_global_asm_807FD610[cc_player_index].unk4 != 0.0f) {
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, D_global_asm_807FD610[cc_player_index].unk28, extra_player_info_pointer->unk48);
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, 0, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x10);
}

void func_global_asm_806E64D0(void) {
    s16 phi_a1;
    s32 phi_v0;

    if (D_global_asm_807FD610[cc_player_index].unk30) {
        phi_a1 = D_global_asm_80753B34[D_global_asm_807FD584] * (D_global_asm_807FD610[cc_player_index].unk2E >= 0 ? 1 : -1);
        phi_a1 &= 0xFFF;
    } else {
        phi_a1 = 0;
    }
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, phi_a1, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, extra_player_info_pointer->unk12, 0x10);
    extra_player_info_pointer->unk38 = D_global_asm_80753988[D_global_asm_807FD584];
}

// fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_E4090/func_global_asm_806E65BC.s")

extern s16 D_global_asm_80753B44[];
extern s16 D_global_asm_80753B54[];
extern s16 D_global_asm_80753B64[];

/*
void func_global_asm_806E65BC(void) {
    f64 temp_f0;
    s16 phi_t1;
    s16 phi_a1;
    f64 phi_f2;
    s32 phi_v0;

    phi_t1 = current_character_index[cc_player_index] == 7 ? 0x19 : 0x10;
    if (D_global_asm_807FD610[cc_player_index].unk30 != 0) {
        current_actor_pointer->y_rotation = (current_actor_pointer->y_rotation - (D_global_asm_807FD610[cc_player_index].unk2E / 2)) & 0xFFF;
        phi_v0 = -1;
        if (D_global_asm_807FD610[cc_player_index].unk2E >= 0) {
            phi_v0 = 1;
        }
        phi_a1 = (phi_v0 * D_global_asm_80753B54[D_global_asm_807FD584]) & 0xFFF;
    } else {
        phi_a1 = 0;
    }
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, phi_a1, 0x10);
    if (D_global_asm_807FD610[cc_player_index].unk2F != 0) {
        temp_f0 = D_global_asm_807FD610[cc_player_index].unk2F * 0.125;
        if (temp_f0 > 0.0) {
            phi_f2 = temp_f0;
        } else {
            phi_f2 = -temp_f0;
        }
        func_global_asm_806DF494(&current_actor_pointer->z_rotation, ((D_global_asm_807FD610[cc_player_index].unk2F * D_global_asm_80753B44[D_global_asm_807FD584]) / 70) & 0xFFF, phi_f2 + phi_t1);
        return;
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, D_global_asm_80753B64[D_global_asm_807FD584], 0x10);
}
*/

void func_global_asm_806E67D8(void) {
    f32 phi_f0;
    f32 phi_f0_2;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        phi_f0_2 = ((D_global_asm_807FD610[cc_player_index].unk8 * 0.5) + 0.5);
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        phi_f0 = MIN(400, phi_f0);
        phi_f0 *= (extra_player_info_pointer->unk48 / 400.0);
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * phi_f0_2);
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, 0, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x10);
    extra_player_info_pointer->unk12 = 0;
    extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
    extra_player_info_pointer->unk10 = D_global_asm_8075395C[D_global_asm_807FD584];
    extra_player_info_pointer->unk38 = D_global_asm_80753988[D_global_asm_807FD584] * D_global_asm_807FD610[cc_player_index].unk8;
    if ((D_global_asm_807FD610[cc_player_index].unk2A & B_BUTTON)) {
        extra_player_info_pointer->unk38 *= 1.33;
    }
}

void func_global_asm_806E6A38(void) {
    f32 phi_f0;
    f32 phi_f0_2;
    f32 phi_f0_3;
    f32 temp;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        temp = ((D_global_asm_807FD610[cc_player_index].unk8 * 0.5) + 0.5);
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        if (phi_f0 > 400.0f) {
            phi_f0 = 400.0f;
        }
        phi_f0 *= 0.45;
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * temp);
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, 0, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x10);
}

void func_global_asm_806E6B98(void) {
    s16 phi_v0;
    s8 pad;
    s16 rot;
    s16 phi_a2;

    phi_v0 = current_actor_pointer->y_rotation;
    phi_a2 = 0x10;
    if (D_global_asm_807FD610[cc_player_index].unk30 != 0) {
        if (current_character_index[cc_player_index] == 7) {
            phi_v0 -= (D_global_asm_807FD610[cc_player_index].unk2E * 0.8);
        } else {
            phi_v0 -= (D_global_asm_807FD610[cc_player_index].unk2E * 0.5);
        }
        current_actor_pointer->y_rotation = phi_v0 & 0xFFF;
        if (D_global_asm_807FD610[cc_player_index].unk2E >= 0) {
            phi_v0 = 1;
        } else {
            phi_v0 = -1;
        }
        rot = phi_v0;
        rot *= D_global_asm_80753B34[D_global_asm_807FD584];
        rot &= 0xFFF;
    } else {
        rot = 0;
    }
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, rot, phi_a2);
    rot = ((D_global_asm_80753B44[D_global_asm_807FD584] * D_global_asm_807FD610[cc_player_index].unk2F) / 70);
    rot &= 0xFFF;
    if (current_character_index[cc_player_index] == 7) {
        phi_a2 = (ABS(0.5 * D_global_asm_807FD610[cc_player_index].unk2F)) + 16.0;
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, rot, phi_a2);
}

void func_global_asm_806E6DE8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        setAction(1, NULL, cc_player_index);
    }
}

void func_global_asm_806E6E7C(void) {
    extra_player_info_pointer->unk12 = 0;
    extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
    if (extra_player_info_pointer->unk10 == 0) {
        extra_player_info_pointer->unk10 = 1;
        extra_player_info_pointer->unk38 = D_global_asm_8075396C[D_global_asm_807FD584];
    }
}
