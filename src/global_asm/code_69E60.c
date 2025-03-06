#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_80748E00;
extern u8 D_global_asm_80748E04;

void func_global_asm_80665160(Actor *arg0, s16 arg1, s16 arg2) {
    func_global_asm_8067ACB4(arg0);
    func_global_asm_80665ACC(arg0);
    if (arg0->unkFC != 0) {
        func_global_asm_80672680(arg0->unkEE, arg1, arg0->unkF4, arg0->unkF6, &arg0->unkF2);
        arg0->unkFA = func_global_asm_80672134(arg0->unkF4, arg0->unkF6, arg2, arg0->unkF8);
        if ((arg0->unk64 & 0x200) && (arg0->unk64 & 0x100)) {
            arg0->unkFA = 0;
        }
        arg0->unkEE = arg0->unkF2;
    }
}

void func_global_asm_806651FC(Actor *arg0) {
    f32 temp_f0;
    f32 sp28;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f20;

    var_f20 = arg0->unkB8;
    if (arg0->unkFC != 0) {
        var_f20 = MIN(arg0->unkFA, var_f20);
    }
    if (arg0->animation_state != NULL) {
        var_f0 = arg0->animation_state->scale_y;
    } else {
        var_f0 = 0.15f;
    }
    temp_f2 = var_f0 * 0.16666666675;
    sp28 = temp_f2;
    if ((arg0->interactable & 4) && (arg0->unk6A & 4)) {
        sp28 = temp_f2 * 0.5;
    }
    var_f20 *= sp28;
    if (arg0->unk6A & 1) {
        var_f20 *= ABS(func_global_asm_80612794(arg0->unkDA));
    }
    if (arg0->object_properties_bitfield & 0x400000) {
        var_f20 *= (u32)D_global_asm_80744478 * 0.5;
    }
    arg0->x_position += var_f20 * func_global_asm_80612794(arg0->unkEE);
    arg0->z_position += var_f20 * func_global_asm_80612790(arg0->unkEE);
    arg0->y_position += arg0->y_velocity * sp28;
}

void func_global_asm_806653C0(Actor *arg0, f32 arg1, f32 arg2) {
    f32 sp28;
    f32 var_f0;

    if (arg0->unkFC != 0) {
        if (arg0->unkFA < arg1) {
            arg1 = arg0->unkFA;
        }
    }
    var_f0 = arg0->animation_state != NULL ? arg0->animation_state->scale_y : 0.15f;
    sp28 = var_f0 * 0.16666666675;
    arg1 *= sp28;
    if (arg0->unk6A & 1) {
        arg1 *= ABS(func_global_asm_80612794(arg0->unkDA));
    }
    if (arg0->object_properties_bitfield & 0x400000) {
        arg1 *= ((u32)D_global_asm_80744478 * 0.5);
    }
    arg0->x_position += arg1 * func_global_asm_80612794(arg0->unkEE);
    arg0->z_position += arg1 * func_global_asm_80612790(arg0->unkEE);
    arg0->y_position += arg2 * sp28;
}

void func_global_asm_80665548(void) {
    D_global_asm_80748E00 = 1;
}

u8 func_global_asm_80665558(void) {
    return D_global_asm_80748E04;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_69E60/func_global_asm_80665564.s")

// TODO: What is this....?
typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} Struct80748D40;

extern Struct80748D40 D_global_asm_80748D40[];

/*
void func_global_asm_80665564(Actor *arg0, f32 arg1) {
    f32 sp5C;
    u8 sp5B;
    Struct80748D40 *var_t1;
    u8 sp54;
    u8 sp53;
    u8 var_a2_2;
    f32 var_f0;
    f32 var_f2;
    s16 temp_v0_2;
    ActorAnimationState *temp_v0;
    s16 var_a1;
    s16 var_a2;
    s16 var_t0;
    s16 var_t9;
    s32 var_v1;

    func_global_asm_80666290(arg0, &sp5B, &sp5C, &sp53, &sp54, 0);
    if (arg0->interactable & 1) {
        func_global_asm_806D09E8(arg0);
    }
    arg0->unk6A &= 0xFFFE;
    arg0->distance_from_floor = arg0->y_position - arg0->floor - arg1;
    if ((arg0->y_position - arg0->floor <= arg1) || ((arg0->unk6C & 1) && (arg0->y_velocity < 0.0f))) {
        if ((gCurrentActorPointer->unk6A & 0x200) || (current_map == MAP_GALLEON_SEAL_RACE) || (current_map == MAP_GALLEON_PUFFTOSS) || (current_map == MAP_CASTLE_CAR_RACE)) {
            if (arg0->distance_from_floor < 0.5) {
                temp_v0 = arg0->animation_state;
                if (temp_v0 != NULL) {
                    var_f2 = temp_v0->scale_y;
                } else {
                    var_f2 = 0.15f;
                }
                arg0->y_position = arg0->floor + arg1;
                arg0->distance_from_floor = 0.0f;
                arg0->unk6A |= 1;
                arg0->y_velocity = (arg0->floor + arg1 - arg0->unk8C) * (f32)(40.0 / (var_f2 * 6.66666666999999968));
            }
        } else if (arg0->distance_from_floor < 5.0f) {
            arg0->distance_from_floor = 0.0f;
            arg0->y_position = arg0->floor + arg1;
            arg0->unk6A |= 1;
            if (arg0->y_velocity < -10.0f) {
                arg0->y_velocity = -10.0f;
            }
        }
    }
    D_global_asm_80748E04 = 0;
    if ((sp5B != 0) && !(arg0->unk6A & 1) && (D_global_asm_80748E00 == 0)) {
        if (arg0->y_velocity > 0.0f) {
            arg0->y_velocity = 0.0f;
        }
        arg0->y_position = sp5C + (arg0->y_velocity * 0.025);
        D_global_asm_80748E04 = 1;
    }
    D_global_asm_80748E00 = 0;
    var_f0 = (f32)(arg0->object_properties_bitfield & 0x40000 ? 0.2 : 1.0);
    var_t0 = (arg0->unk6A & 1) ? arg0->unkDA : 0x400;
    var_a1 = arg0->unkD8;
    var_t1 = &D_global_asm_80748D40[arg0->unkD1];
    // TODO: Probably a switch case
    if (current_map != MAP_AZTEC_BEETLE_RACE) {
        if (current_map == MAP_CAVES_BEETLE_RACE) {
            extra_player_info_pointer->unk26 = 0x14;
            goto block_31;
        }
    } else {
block_31:
        if (arg0->unk6A & 0x200) {
            var_t1 = &D_global_asm_80748D40[10];
        }
    }
    if (arg0->unkDE >= 0x3F4) {
        arg0->unkDC = var_a1;
    }
    if (var_t0 >= 0x3F4) {
        var_a1 = arg0->unkDC;
    }
    var_a2 = (var_t1->unk6 << 0xC) / 360;
    if (var_a2 < var_t0) {
        var_a2 = var_t0;
    }
    temp_v0_2 = func_global_asm_806CC10C(arg0->unkDC, var_a1);
    if (temp_v0_2 > 0) {
        var_v1 = temp_v0_2;
    } else {
        var_v1 = -temp_v0_2;
    }
    if (var_v1 >= 0x6AB) {
        if (arg0->unkDE >= 0x3C8) {
            arg0->unkDE = 0x400;
            arg0->unkDC = var_a1;
        } else {
            arg0->unkDE += func_global_asm_806CC10C(arg0->unkDE, 0x400) * (s16)var_f0;
            arg0->unkDE &= 0xFFF;
        }
    } else {
        arg0->unkDC += temp_v0_2 * var_f0;
        arg0->unkDC &= 0xFFF;
        arg0->unkDE += func_global_asm_806CC10C(arg0->unkDE, var_a2) * (s16)var_f0;
        arg0->unkDE &= 0xFFF;
    }
    if (!(arg0->unk6A & 0x20)) {
        var_a2_2 = var_t1->unk3;
    } else {
        var_a2_2 = var_t1->unk2;
    }
    if (((var_a2_2 << 0xC) / 360) < var_t0) {
        arg0->unkE0 = 0.0f;
        return;
    }
    arg0->unkE0 = (0x400 - var_t0) / var_t1->unk0;
}
*/

u8 func_global_asm_80665AAC(Actor *arg0) {
    return D_global_asm_80748D40[arg0->unkD0].unk8;
}

void func_global_asm_80665ACC(Actor *arg0) {
    arg0->object_properties_bitfield |= 0x2; // block playing instrument?
    arg0->object_properties_bitfield |= 0x20; // TODO: What is this used for?
}

f32 func_global_asm_80665AE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp1C;

    if (arg2 >= arg0 && arg3 >= arg1) {
        sp1C = func_global_asm_80611BB4(arg3 - arg1, arg2 - arg0) + 1.570796371f;
    } else if (arg2 >= arg0 && arg3 < arg1) {
        sp1C = 1.570796371f - func_global_asm_80611BB4(arg1 - arg3, arg2 - arg0);
    } else if (arg2 < arg0 && arg3 < arg1) {
        sp1C = func_global_asm_80611BB4(arg1 - arg3, arg0 - arg2) + 4.71238911151885986;
    } else if (arg2 < arg0 && arg3 >= arg1) {
        sp1C = 4.71238911151885986 - func_global_asm_80611BB4(arg3 - arg1, arg0 - arg2);
    }
    return sp1C * 57.29577637f;
}

s16 func_global_asm_80665C18(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s16 sp36;

    if (arg4 < 1.0) {
        arg4 = 1.0f;
    }
    if ((arg2 <= arg0) && (arg3 <= arg1)) {
        sp36 = func_global_asm_80611E60(((arg0 - arg2) * 65535.9) / arg4) >> 4;
    } else if ((arg2 <= arg0) && (arg1 < arg3)) {
        sp36 = (func_global_asm_80611E60(((arg3 - arg1) * 65535.9) / arg4) >> 4) + 0x400;
    } else if ((arg0 < arg2) && (arg1 < arg3)) {
        sp36 = (func_global_asm_80611E60(((arg2 - arg0) * 65535.9) / arg4) >> 4) + 0x800;
    } else if ((arg0 < arg2) && (arg3 <= arg1)) {
        sp36 = (func_global_asm_80611E60(((arg1 - arg3) * 65535.9) / arg4) >> 4) + 0xC00;
    }
    return sp36;
}

s16 func_global_asm_80665DE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0 - arg2;
    temp_f2 = arg1 - arg3;
    return func_global_asm_80665C18(arg0, arg1, arg2, arg3, sqrtf(SQ(temp_f0) + SQ(temp_f2)));
}

f32 func_global_asm_80665E48(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return (func_global_asm_80665DE0(arg0, arg1, arg2, arg3) * 3.141592741f) * 0.00048828125;
}

f32 func_global_asm_80665E94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6) {
    f32 temp_f0;
    f32 temp_f2;
    f32 phi_f14;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg2 - arg5;
    temp_f0 = sqrtf(SQ(temp_f0) + SQ(temp_f2));
    if (temp_f0 < arg6) {
        phi_f14 = arg6;
    } else {
        phi_f14 = temp_f0;
    }
    return func_global_asm_80611BB4(arg4 - arg1, phi_f14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_69E60/func_global_asm_80665F24.s")

LedgeInfo *func_global_asm_8066E2C0(f32, f32, void *, f32, f32, f32, f32, s16 *, void *, void *, void *);

/*
// TODO: Need to give some shape to actor->unk0 (model pointer)
LedgeInfo *func_global_asm_80665F24(Actor *arg0) {
    ActorAnimationState *temp_v0_2;
    f32 var_f0;
    f32 var_f16;
    f32 var_f2;
    u32 *temp_a2;
    void *temp_v0;
    void *var_a1;
    void *var_t0;
    void *var_v1;

    temp_a2 = arg0->unk0;
    var_f16 = 1.0f;
    var_v1 = NULL;
    var_a1 = NULL;
    var_t0 = NULL;
    var_f0 = 0.0f;
    var_f2 = 0.0f;
    if (temp_a2 != NULL) {
        temp_v0 = temp_a2->unkC;
        var_f0 = temp_v0->unk0;
        var_f2 = temp_v0->unk4;
        var_v1 = temp_v0 + 8;
    }
    temp_v0_2 = arg0->animation_state;
    if (temp_v0_2 != NULL) {
        var_f16 = temp_v0_2->scale_y;
        var_a1 = temp_v0_2->bone_array_1;
        var_t0 = temp_v0_2->bone_array_2;
    }
    return func_global_asm_8066E2C0(0.0f, 0.0f, var_a1, 0.0f, var_f16, var_f0, var_f2, &arg0->unkC, var_a1, var_t0, var_v1);
}
*/

void func_global_asm_8066EB50(Actor *actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

void func_global_asm_80665FB4(Actor *arg0) {
    f32 xPos = arg0->x_position;
    f32 yPos = arg0->y_position;
    f32 zPos = arg0->z_position;
    f32 phi_f0;

    if (arg0->animation_state) {
        func_global_asm_806303C4(NULL, 0, arg0, xPos, yPos, zPos, arg0->draw_distance, 0, 1, -1, 1);
    }
    if (arg0->ledge_info_pointer) {
        if (arg0->animation_state) {
            phi_f0 = arg0->animation_state->scale_y;
        } else {
            phi_f0 = 0.15f;
        }
        func_global_asm_8066EB50(arg0, xPos, yPos, zPos, phi_f0);
        arg0->ledge_info_pointer->unk80 = object_timer;
    }
    //return phi_f0;
}

// Loads floors from pointer table 3 for the current map
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_69E60/func_global_asm_80666090.s")
