#include <ultra64.h>
#include "functions.h"


extern u8 D_80748E00;
extern u8 D_80748E04;
extern void *D_80748E14; // TODO: Datatype
extern u8 D_80748E18[];
extern f64 D_80758F08;

extern u8 D_807F951D;
extern f32 D_807F9468;
extern u8 D_807F946C;
extern u8 D_807F946E;
extern f32 D_807F9488;
extern f32 D_807F948C;
extern s16 D_807F9490;
extern s16 D_807F9498;
extern s16 D_807F94A2;
extern s16 D_807F94A4;
extern u8 D_807F94AA;
extern u8 D_807F94AE;
extern u8 D_807F94AF;
extern u8 D_807F94B0;
extern u8 D_807F94B1;
extern u8 D_807F94B3;
extern u8 D_807F94B4;
extern u8 D_807F94B5;
extern u8 D_807F94B7;
extern u8 D_807F94BC;
extern u8 D_807F9484;
extern u8 D_807F9510;
extern s32 *D_807F95A8[];
extern s32 D_807F9678;
extern u8 D_807F967C;
extern u8 D_807F967D;

extern s32 *D_807FB1A0[];

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Temp20Big;

extern Temp20Big D_80748BA0[];
extern s8 D_807F9440[];
extern s32 D_807F9448;

void func_80664CB0(s16 arg0) {
    s32 i;
    s32 max = 0xD;

    D_807F9448 = 0;
    for (i = 0; i < max; i++) {
        if (arg0 == D_80748BA0[i].unk0) {
            if (D_807F9448 != 8) {
                D_807F9440[D_807F9448] = i;
                D_807F9448++;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80664D20.s")

void func_80665ACC(Actor *arg0);
u16 func_80672134(s16, s16, s16, s16);

void func_80665160(Actor *arg0, s16 arg1, s16 arg2) {
    func_8067ACB4(arg0);
    func_80665ACC(arg0);
    if (arg0->unkFC != 0) {
        func_80672680(arg0->unkEE, arg1, arg0->unkF4, arg0->unkF6, &arg0->unkF2);
        arg0->unkFA = func_80672134(arg0->unkF4, arg0->unkF6, arg2, arg0->unkF8);
        if ((arg0->unk64 & 0x200) && (arg0->unk64 & 0x100)) {
            arg0->unkFA = 0;
        }
        arg0->unkEE = arg0->unkF2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806651FC.s")

f32 func_80612794(s16);
extern s32 D_80744478;
extern f32 D_80758E30;
extern f64 D_80758E38;

/*
// TODO: Doable, float nonsense, close
void func_806651FC(Actor *arg0) {
    f32 temp_f0;
    f32 sp28;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f20;

    var_f20 = arg0->unkB8;
    if (arg0->unkFC != 0) {
        var_f20 = MIN(arg0->unkFA, var_f20);
        // temp_f0 = arg0->unkFA;
        // if (temp_f0 < var_f20) {
            // var_f20 = temp_f0;
        // }
    }
    if (arg0->animation_state != NULL) {
        var_f0 = arg0->animation_state->scale_y;
    } else {
        var_f0 = D_80758E30;
    }
    temp_f2 = var_f0 * D_80758E38;
    sp28 = temp_f2;
    if ((arg0->interactable & 4) && (arg0->unk6A & 4)) {
        sp28 = temp_f2 * 0.5;
    }
    var_f20 *= sp28;
    if (arg0->unk6A & 1) {
        var_f20 *= ABS(func_80612794(arg0->unkDA));
    }
    if (arg0->object_properties_bitfield & 0x400000) {
        var_f20 *= D_80744478 * 0.5;
    }
    arg0->x_position += var_f20 * func_80612794(arg0->unkEE);
    arg0->z_position += var_f20 * func_80612790(arg0->unkEE);
    arg0->y_position += arg0->y_velocity * sp28;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806653C0.s")

f32 func_80612794(s16);
extern s32 D_80744478;
extern f32 D_80758E40;
extern f64 D_80758E48;

/*
// TODO: Close, float nonsense. Hmmm, .rodata/.bss?
void func_806653C0(Actor *arg0, f32 arg1, f32 arg2) {
    f32 sp28;
    f32 temp_f16;
    f32 var_f0;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f2;
    f64 var_f6;

    var_f20 = arg1;
    if (arg0->unkFC != 0) {
        if (arg0->unkFA < arg1) {
            var_f20 = arg0->unkFA;
        }
    }
    var_f0 = arg0->animation_state != NULL ? arg0->animation_state->scale_y : D_80758E40;
    temp_f16 = var_f0 * D_80758E48;
    sp28 = temp_f16;
    var_f20 *= temp_f16;
    if (arg0->unk6A & 1) {
        var_f20 *= ABS(func_80612794(arg0->unkDA));
    }
    if (arg0->object_properties_bitfield & 0x400000) {
        var_f20 *= (D_80744478 * 0.5);
    }
    arg0->x_position += var_f20 * func_80612794(arg0->unkEE);
    arg0->z_position += var_f20 * func_80612790(arg0->unkEE);
    arg0->y_position += arg2 * sp28;
}
*/

void func_80665548(void) {
    D_80748E00 = 1;
}

u8 func_80665558(void) {
    return D_80748E04;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665564.s")

extern f32 D_80758E50;
extern f64 D_80758E58;
extern f64 D_80758E60;
extern f64 D_80758E68;
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

extern Struct80748D40 D_80748D40[];

/*
// TODO: Doable, good progress made
void func_80665564(Actor *arg0, f32 arg1) {
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

    func_80666290(arg0, &sp5B, &sp5C, &sp53, &sp54, 0);
    if (arg0->interactable & 1) {
        func_806D09E8(arg0);
    }
    arg0->unk6A &= 0xFFFE;
    arg0->distance_from_floor = arg0->y_position - arg0->floor - arg1;
    if ((arg0->y_position - arg0->floor <= arg1) || ((arg0->unk6C & 1) && (arg0->y_velocity < 0.0f))) {
        if ((current_actor_pointer->unk6A & 0x200) || (current_map == MAP_GALLEON_SEAL_RACE) || (current_map == MAP_GALLEON_PUFFTOSS) || (current_map == MAP_CASTLE_CAR_RACE)) {
            if (arg0->distance_from_floor < 0.5) {
                temp_v0 = arg0->animation_state;
                if (temp_v0 != NULL) {
                    var_f2 = temp_v0->scale_y;
                } else {
                    var_f2 = D_80758E50;
                }
                arg0->y_position = arg0->floor + arg1;
                arg0->distance_from_floor = 0.0f;
                arg0->unk6A |= 1;
                arg0->y_velocity = (arg0->floor + arg1 - arg0->unk8C) * (40.0 / (var_f2 * D_80758E58));
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
    D_80748E04 = 0;
    if ((sp5B != 0) && !(arg0->unk6A & 1) && (D_80748E00 == 0)) {
        if (arg0->y_velocity > 0.0f) {
            arg0->y_velocity = 0.0f;
        }
        arg0->y_position = sp5C + (arg0->y_velocity * D_80758E60);
        D_80748E04 = 1;
    }
    D_80748E00 = 0;
    if (arg0->object_properties_bitfield & 0x40000) {
        var_f0 = D_80758E68;
    } else {
        var_f0 = 1.0;
    }
    var_t0 = 0x400;
    if (arg0->unk6A & 1) {
        var_t0 = arg0->unkDA;
    }
    var_a1 = arg0->unkD8;
    var_t1 = &D_80748D40[arg0->unkD1];
    // TODO: Probably a switch case
    if (current_map != MAP_AZTEC_BEETLE_RACE) {
        if (current_map == MAP_CAVES_BEETLE_RACE) {
            extra_player_info_pointer->unk26 = 0x14;
            goto block_31;
        }
    } else {
block_31:
        if (arg0->unk6A & 0x200) {
            var_t1 = &D_80748D40[10];
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
    temp_v0_2 = func_806CC10C(arg0->unkDC, var_a1);
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
            arg0->unkDE += func_806CC10C(arg0->unkDE, 0x400) * (s16)var_f0;
            arg0->unkDE &= 0xFFF;
        }
    } else {
        arg0->unkDC += temp_v0_2 * var_f0;
        arg0->unkDC &= 0xFFF;
        arg0->unkDE += func_806CC10C(arg0->unkDE, var_a2) * (s16)var_f0;
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

u8 func_80665AAC(Actor *arg0) {
    return D_80748D40[arg0->unkD0].unk8;
}

void func_80665ACC(Actor *arg0) {
    arg0->object_properties_bitfield |= 0x2; // block playing instrument?
    arg0->object_properties_bitfield |= 0x20; // TODO: What is this used for?
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665C18.s")

s32 func_80611E60(s32);
extern f64 D_80758E90;
extern f64 D_80758E98;
extern f64 D_80758EA0;
extern f64 D_80758EA8;

/*
s16 func_80665C18(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s16 sp36;
    f32 var_f24;

    var_f24 = arg4;
    if (var_f24 < 1.0) {
        var_f24 = 1.0f;
    }
    if ((arg2 <= arg0) && (arg3 <= arg1)) {
        sp36 = func_80611E60(((arg0 - arg2) * D_80758E90) / var_f24) >> 4;
    } else if ((arg2 <= arg0) && (arg1 < arg3)) {
        sp36 = (func_80611E60(((arg3 - arg1) * D_80758E98) / var_f24) >> 4) + 0x400;
    } else if ((arg0 < arg2) && (arg1 < arg3)) {
        sp36 = (func_80611E60(((arg2 - arg0) * D_80758EA0) / var_f24) >> 4) + 0x800;
    } else if ((arg0 < arg2) && (arg3 <= arg1)) {
        sp36 = (func_80611E60(((arg1 - arg3) * D_80758EA8) / var_f24) >> 4) + 0xC00;
    }
    return sp36;
}
*/

//forward decl necessary
//looks like its taking the linear distance between 2 points (2D)
s16 func_80665C18(f32,f32,f32,f32,f32);
s16 func_80665DE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0 - arg2;
    temp_f2 = arg1 - arg3;
    return func_80665C18(arg0, arg1, arg2, arg3, 
                    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)));
}

extern f32 D_80758EB0;

f32 func_80665E48(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return (func_80665DE0(arg0, arg1, arg2, arg3) * D_80758EB0) * 0.00048828125;
}

f32 func_80611BB4(f32, f32);

f32 func_80665E94(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6) {
    f32 temp_f0;
    f32 temp_f2;
    f32 phi_f14;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg2 - arg5;
    temp_f0 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    if (temp_f0 < arg6) {
        phi_f14 = arg6;
    } else {
        phi_f14 = temp_f0;
    }
    return func_80611BB4(arg4 - arg1, phi_f14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665F24.s")

LedgeInfo *func_8066E2C0(f32, f32, void *, f32, f32, f32, f32, s16 *, void *, void *, void *);

/*
// TODO: Need to give some shape to actor->unk0 (model pointer)
LedgeInfo *func_80665F24(Actor *arg0) {
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
    return func_8066E2C0(0.0f, 0.0f, var_a1, 0.0f, var_f16, var_f0, var_f2, &arg0->unkC, var_a1, var_t0, var_v1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80665FB4.s")

/*
extern f32 D_80758EB4;

void func_8066EB50(Actor *actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

void func_80665FB4(Actor *arg0) {
    f32 phi_f0;

    f32 xPos = arg0->x_position;
    f32 yPos = arg0->y_position;
    f32 zPos = arg0->z_position;

    if (arg0->animation_state) {
        func_806303C4(yPos, zPos, arg0->draw_distance, 0, 1, -1, 1);
    }
    if (arg0->ledge_info_pointer) {
        if (arg0->animation_state) {
            phi_f0 = arg0->animation_state->scale_y;
        } else {
            phi_f0 = D_80758EB4;
        }
        func_8066EB50(arg0, xPos, yPos, zPos, phi_f0);
        arg0->ledge_info_pointer->unk80 = object_timer;
    }
    //return phi_f0;
}
*/

// Loads floors from pointer table 3 for the current map
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666090.s")

void func_80666280(u8 arg0) {
    D_807F94B4 = arg0;
}

void func_80666428(Actor*, f32, f32, f32, s32, s32, s32, s32, u8);

void func_80666290(Actor *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    D_807F94BC = 0;
    D_807F94B3 = 0;
    if (arg0->unkCC && !arg0->locked_to_pad && arg0->object_properties_bitfield & 0x10) {
        func_80671C0C(arg0, arg0->unkCC, &sp3C, &sp38, &sp34);
    } else {
        sp3C = arg0->x_position;
        sp38 = arg0->unk8C;
        sp34 = arg0->z_position;
    }
    func_80666428(arg0, sp3C, sp38, sp34, arg1, arg2, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066635C.s")

/*
// TODO: Might return u8 from somewhere
void func_8066635C(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4) {
    u8 sp3F;
    u8 sp3E;
    s32 sp38;
    s32 sp34;

    if (arg0->unk58 == ACTOR_CAMERA) {
        D_807F94B3 = 1;
    } else {
        D_807F94B3 = 0;
    }
    D_807F94BC = 1;
    func_80666428(0, arg1, arg2, arg3, &sp3F, &sp38, &sp3E, &sp34, 0);
    *arg4 = D_807F948C;
}
*/

void func_806663F8(void) {
    D_807F94AE = 0;
    D_807F94AF = 0;
    D_807F94B0 = 0;
    D_807F94B7 = 0;
}

u8 func_8066641C(void) {
    return D_807F951D;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666428.s")

u8 func_80666A88(void) {
    return D_807F946E;
}

u8 func_80666A94(void) {
    return D_807F94AE;
}

u8 func_80666AA0(void) {
    return D_807F94AF;
}

u8 func_80666AAC(void) {
    return D_807F94B0;
}

u8 func_80666AB8(void) {
    return D_807F94B7;
}

void func_80666AC4(s16 *arg0, s16 *arg1) {
    *arg0 = D_807F94A2;
    *arg1 = D_807F94A4;
}

u8 func_80666AE0(void) {
    return D_807F94B1;
}

u8 func_80666AEC(void) {
    return D_807F94AA;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80666D88.s")

extern f32 D_80752F7C[];
extern f32 D_80752F98[];
extern f32 D_80752FB4[];
extern f32 D_80752FD0[];
extern f32 D_80752FEC[];
extern f32 D_80753008[];
extern f32 D_807F9460;
extern s8 D_807F9464;

extern s16 D_807FD584;

/*
// TODO: Regalloc v0 v1 a2
void func_80666D88(f32 arg0, f32 arg1, u8 arg2, Actor *arg3, u8 arg4) {
    f32 *var_v0;
    f32 *var_v1;
    f32 var_f0;
    f32 var_f12;
    f32 var_f16;
    f32 var_f2;
    s32 temp2;

    if (arg0 < arg1) {
        if (arg3 != NULL && arg3->interactable & 1) {
            switch (character_change_array[cc_player_index].unk2C0) {
                default:
                    // TODO: Any way to match this without having the statements on the same line?
                    var_v0 = &D_80752F98;var_v1 = &D_80752F7C;
                    break;
                case 2:
                    var_v0 = &D_80753008;
                    var_v1 = &D_80752FEC;
                    break;
                case 0:
                    var_v0 = &D_80752FD0;
                    var_v1 = &D_80752FB4;
                    break;
            }
            var_f0 = var_v0[D_807FD584];
            var_f2 = var_v1[D_807FD584];
        } else {
            var_f0 = 10.0f;
            var_f2 = 20.0f;
        }
        if (arg4 != 0) {
            var_f0 /= 2;
        }
        if (arg2 == 1) {
            var_f16 = var_f0 * 6.0f;
        } else {
            var_f16 = var_f0;
        }
        if (var_f16 < arg1 - arg0) {
            s32 temp = 1;
            var_f12 = arg2 == 1 ? var_f2 * 6.0f : var_f2;
            if (arg1 - arg0 < var_f12) {
                D_807F9464 = temp;
                D_807F9460 = arg1 - var_f12;
                if (arg2 != 0) {
                    D_807F9460 /= 6.0f;
                }
            }
        }
    }
}
*/

s32 func_80666F04(f32 arg0, f32 arg1, u8 arg2, u8 arg3) {
    f32 phi_f0;
    s32 phi_v1;

    phi_v1 = 0;
    if (arg3 == 0xFF && arg0 < arg1) {
        phi_f0 = arg2 == 1 ? D_80758F08 : 25;
        if ((arg1 - arg0) < phi_f0) {
            D_807F946C = 1;
            D_807F9468 = arg1 - phi_f0;
            phi_v1 = 1;
            if (arg2) {
                D_807F9468 /= 6.0f;
            }
            D_807F9468 += 6.0;
        }
    }
    return phi_v1;
}

s32 func_80666FC8(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    f32 phi_f0;
    s32 phi_v0;
    s32 phi_v1;
    f32 phi_f2;

    phi_f0 = arg3 == 1 ? 60.0 : 10.0;

    if (arg0 <= arg2)
        phi_v0 = TRUE;
    else if ((arg0 - arg2) < phi_f0)
        phi_v0 = TRUE;
    else
        phi_v0 = FALSE;

    if (arg1 <= arg2)
        phi_v1 = TRUE;
    else if ((arg1 - arg2) < phi_f0)
        phi_v1 = TRUE;
    else
        phi_v1 = FALSE;

    if (!(phi_v0 || phi_v1)) {
        return FALSE;
    }
    if (!phi_v1) {
        return FALSE;
    }
    if (!phi_v0) {
        return TRUE;
    }
    
    if (arg2 < arg0) {
        phi_f0 = arg0 - arg2;
    } else {
        phi_f0 = arg2 - arg0;
    }
    if (arg2 < arg1) {
        phi_f2 = arg1 - arg2;
    } else {
        phi_f2 = arg2 - arg1;
    }

    if (phi_f0 < phi_f2) {
        return FALSE;
    }
    return TRUE;
}

u8 func_80667180(f32 arg0, f32 arg1, f32 *arg2, s32 arg3);

// TODO: What does this return? Fake match?
s32 func_80667110(f32 arg0, f32 arg1, f32 *arg2) {
    D_807F9484 = 0;
    D_807F9510 = 0;
    func_80667180(arg0, arg1, arg2, 0);
    D_807F94A4 = D_807F9498;
    D_807F94A2 = D_807F9490;
}

u8 func_8066715C(f32 *arg0) {
    *arg0 = D_807F9488;
    return D_807F9484;
}

u8 func_80667174(void) {
    return D_807F94B5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80667180.s")

// s32 func_80666FC8(f32, f32, s32, u8, f32, s32);
s32 func_806672B8(f32, f32, f32 *, s32);
u8 func_806679BC(f32, f32, f32 *);
extern s8 D_807F94B6;

/*
// TODO: Close
u8 func_80667180(f32 arg0, f32 arg1, f32 *arg2, s32 arg3) {
    u8 sp3F;
    f32 sp38;
    f32 sp34;
    u8 temp_v1;
    s32 var_v1;

    sp38 = *arg2;
    sp3F = func_806679BC(arg0, arg1, &sp38);
    sp34 = *arg2;
    temp_v1 = (func_806672B8(arg0, arg1, &sp34, arg3) * 2) + sp3F;
    switch (temp_v1) {
        case 0:
            break;
        case 1:
            *arg2 = sp38;
            break;
        case 2:
            *arg2 = sp34;
            D_807F94B6 = 1;
            break;
        case 3:
            if (func_80666FC8(sp38, sp34, *arg2 + 4.0, 0) != 0) {
                *arg2 = sp34;
                D_807F94B6 = 1;
            } else {
                *arg2 = sp38;
            }
            break;
    }
    if (temp_v1 != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806672B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066785C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806679BC.s")

extern f64 D_80758F68;

s32 func_80668520(f32 *arg0, f32 arg1, f32 arg2, f32 *arg3) {
    f32 var_f12;
    f64 temp_f0;

    // TODO: Can we use any macros here? ABS? MIN? MAX?
    temp_f0 = arg2 * 6.0f;
    if (D_80758F68 < temp_f0) {
        var_f12 = temp_f0 - D_80758F68;
    } else {
        var_f12 = -(temp_f0 - D_80758F68);
    }
    if (var_f12 < 40.0f) {
        D_807F94AE = 1;
    }
    if (func_80666FC8(*arg0, 684.0f, arg1, 1) != 0) {
        *arg3 = 114.0f;
        return TRUE;
    }
    return FALSE;
}

typedef struct {
    f32 unk0;
    s16 unk4;
    u8 unk6;
    s8 unk7;
} Struct807F94C0;

extern s16 D_807F94A8;
extern Struct807F94C0 D_807F94C0[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
} Struct806685E0_arg0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Struct8066893C;

s32 func_8066893C(Struct8066893C*);
void func_806689F0(s32, void*, s32);

void func_806685E0(Struct806685E0_arg0 *arg0, f32 arg1) {
    Struct807F94C0 *var_v0;

    if (D_807F9510 != 0xA) {
        D_807F94C0[D_807F9510].unk0 = arg1 / 6.0f;
        if (func_8066893C(arg0) != 0) {
            var_v0 = &D_807F94C0[D_807F9510];
            var_v0->unk6 = 1;
        } else {
            var_v0 = &D_807F94C0[D_807F9510];
            var_v0->unk6 = 2;
        }
        if (arg0->unk12 & 1) {
            var_v0->unk6 = var_v0->unk6 | 4;
        }
        if (arg0->unk12 & 0x400) {
            var_v0->unk6 = var_v0->unk6 | 8;
        }
        func_806689F0(0, arg0, 0);
        D_807F94C0[D_807F9510].unk4 = D_807F94A8;
        D_807F9510 += 1;
    }
}

// Doable, small malloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806686F4.s")

// Doable, small struct loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806687E0.s")

// Doable, small struct loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806688B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066893C.s")

/*
// TODO: I don't know why this doesn't match
s32 func_8066893C(Struct8066893C *arg0) {
    f32 sp1C;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 sp4;
    s32 var_v0;

    var_v0 = 0;
    sp14 = arg0->unk4 - arg0->unk0;
    sp1C = arg0->unk10 - arg0->unkC;
    sp8 = arg0->unk2 - arg0->unk0;
    sp10 = arg0->unkE - arg0->unkC;
    sp4 = (sp1C * sp8) - (sp10 * sp14);
    if (sp4 <= 0.0) {
        var_v0 = 1;
    }
    return var_v0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806689F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80668E9C.s")

s32 func_80669930(void*);
void func_80669830(s32, void*, s32);

void func_80669588(s32 arg0, f32 arg1) {
    if (D_807F9510 != 0xA) {
        D_807F94C0[D_807F9510].unk0 = arg1;
        if (func_80669930(arg0) != 0) {
            D_807F94C0[D_807F9510].unk6 = 1;
        } else {
            D_807F94C0[D_807F9510].unk6 = 2;
        }
        func_80669830(0, arg0, 0);
        D_807F94C0[D_807F9510].unk4 = D_807F94A8;
        D_807F9510 += 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806696A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_806699C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669A6C.s")

typedef struct {
    f32     unk0;
    f32     unk4;
    f32     unk8;
    f32     unkC;
    f32     unk10;
    f32     unk14;
    f32     unk18;
    f32     unk1C;
    f32     unk20;
} GlobalASMStruct80;

int func_80669BE8(GlobalASMStruct80 *arg0, f32 arg1, f32 arg2) {
    if (arg1 < arg0->unk0) {
        return FALSE;
    }
    if (arg2 < arg0->unk8) {
        return FALSE;
    }
    if (arg0->unkC < arg1) {
        return FALSE;
    }
    if (arg0->unk14 < arg2) {
        return FALSE;
    }
    return TRUE;
}

int func_80669C6C(GlobalASMStruct80 *arg0, f32 arg1) {
    if (arg1 < arg0->unk4) {
        return FALSE;
    }
    if (arg0->unk10 < arg1) {
        return FALSE;
    }
    return TRUE;
}

s32 func_80669CB4(GlobalASMStruct80 *arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f14_3;
    f32 var_f14_4;

    temp_f0 = arg0->unk0;
    temp_f2 = arg0->unk4;
    temp_f12 = arg0->unk8;
    if (temp_f0 < temp_f2) {
        var_f14 = temp_f0;
    } else {
        var_f14 = temp_f2;
    }
    if (!(var_f14 < temp_f12)) {
        var_f14 = temp_f12;
    }
    if (arg1 < var_f14) {
        return 0;
    }
    if (temp_f2 < temp_f0) {
        var_f14_2 = temp_f0;
    } else {
        var_f14_2 = temp_f2;
    }
    if (!(temp_f12 < var_f14_2)) {
        var_f14_2 = temp_f12;
    }
    if (var_f14_2 < arg1) {
        return 0;
    }
    temp_f0_2 = arg0->unk18;
    temp_f2_2 = arg0->unk1C;
    temp_f12_2 = arg0->unk20;
    if (temp_f0_2 < temp_f2_2) {
        var_f14_3 = temp_f0_2;
    } else {
        var_f14_3 = temp_f2_2;
    }
    if (!(var_f14_3 < temp_f12_2)) {
        var_f14_3 = temp_f12_2;
    }
    if (arg2 < var_f14_3) {
        return 0;
    }
    if (temp_f2_2 < temp_f0_2) {
        var_f14_4 = temp_f0_2;
    } else {
        var_f14_4 = temp_f2_2;
    }
    if (!(temp_f12_2 < var_f14_4)) {
        var_f14_4 = temp_f12_2;
    }
    if (var_f14_4 < arg2) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_80669E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A08C.s")

s32 func_8066AC10(f32);
void func_8066ACA4(s32, s32, s32);

void func_8066A584(s32 arg0, f32 arg1) {
    if (D_807F9510 != 0xA) {
        D_807F94C0[D_807F9510].unk0 = arg1;
        if (func_8066AC10(arg1) != 0) {
            D_807F94C0[D_807F9510].unk6 = 1;
        } else {
            D_807F94C0[D_807F9510].unk6 = 2;
        }
        func_8066ACA4(0, arg0, 0);
        D_807F94C0[D_807F9510].unk4 = D_807F94A8;
        D_807F9510 += 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A834.s")

// TODO: Hmmm, matrix?
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
} Struct8066AC10;

/*
// TODO: Pretty close...
s32 func_8066A834(Struct8066AC10 *arg0, f32 arg1, f32 arg2) {
    f32 sp1C;
    f32 sp20;
    f32 var_f0;
    f32 var_f12;

    if (arg0->unk24 < arg0->unk28) {
        var_f12 = arg0->unk24;
    } else {
        var_f12 = arg0->unk28;
    }
    if (!(var_f12 < arg0->unk2C)) {
        var_f12 = arg0->unk2C;
    }
    if (arg0->unk3C < arg0->unk40) {
        sp20 = arg0->unk3C;
    } else {
        sp20 = arg0->unk40;
    }
    if (!(sp20 < arg0->unk44)) {
        sp20 = arg0->unk44;
    }
    if (arg0->unk28 < arg0->unk24) {
        sp1C = arg0->unk24;
    } else {
        sp1C = arg0->unk28;
    }
    if (!(arg0->unk2C < sp1C)) {
        sp1C = arg0->unk2C;
    }
    if (arg0->unk40 < arg0->unk3C) {
        var_f0 = arg0->unk3C;
    } else {
        var_f0 = arg0->unk40;
    }
    if (!(arg0->unk44 < var_f0)) {
        var_f0 = arg0->unk44;
    }
    return (!(arg1 < var_f12) && !(sp1C < arg1) && !(arg2 < sp20) && var_f0 < arg2) ? 1 : 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066A988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066AC10.s")

/*
s32 func_8066AC10(Struct8066AC10 *arg0) {
    f32 sp4[9]; // TODO: Try 10 size

    sp4[6] = arg0->unk2C - arg0->unk24;
    sp4[8] = arg0->unk44 - arg0->unk3C;
    sp4[2] = arg0->unk28 - arg0->unk24;
    sp4[4] = arg0->unk40 - arg0->unk3C;
    return (sp4[2] * sp4[8]) - (sp4[6] * sp4[4]) <= 0.0;
}
*/

// TODO: Similar to above ^^ same struct arg1?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066ACA4.s")

extern s32 D_8000DDCC;
extern void *D_807F9520;
extern s32 *D_807F9528[];
extern s32 D_807F9628[];
extern s32 D_807F9680;
extern u8 D_807FB220;
extern u8 D_807FB221;

void func_8060B140(s32, s32*, s32*, s32, s32, s32, s32);

void func_8066ADA0(void) {
    s32 i;
    s32 sp40;

    sp40 = 0x80;
    D_807F9520 = malloc(0x80);
    func_8060B140(D_8000DDCC, D_807F9520, &sp40, 0, 0, 0, 0);
    for (i = 0; i < 0x20; i++) {
        D_807F9528[i] = NULL;
        D_807F95A8[i] = 0;
    }
    for (i = 0; i < 0x14; i++) {
        D_807F9628[i] = 0;
    }
    D_807F9680 = 0;
    D_807F967C = 0;
    D_807F9678 = 0;
    D_807F967D = 0;
    for (i = 0; i < 0x20; i++) {
        if (D_80748E18[i] != 0) {
            D_807FB1A0[i] = getPointerTableFile(0x1A, i, 1, 1); // Uncompressed file sizes
        } else {
            D_807FB1A0[i] = NULL;
        }
    }
    D_807FB220 = 0;
    D_807FB221 = 0;
}

void func_8066AEE4(s32 arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;

    sp24 = arg0;
    sp20 = arg1;
    if (!D_80748E14) {
        D_80748E14 = malloc(0x2400);
    }
    func_800024E0(&sp24, &sp20, D_80748E14);
    func_8061130C(arg0);
}

//forward decl needed
void func_8066B4AC(s32,s32,s32);
s32  func_8066B9F4(void*);

s32 func_8066B5C8(s32, s32);
extern OSMesgQueue D_807656D0;
extern s32 D_807F9680;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct807F9688;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8; // Used
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Struct807FA8A0;

extern Struct807F9688 D_807F9688[];
extern Struct807FA8A0 D_807FA8A0[];

extern s8 D_80746834;
extern void *D_80748E14;
extern s32 D_807F9680;

void func_8066AF40(void) {
    s32 i;

    for (i = 0; i < D_807F9680; i++) {
        D_80746834 = 7;
        osRecvMesg(&D_807656D0, NULL, 1);
        D_80746834 = 0;
        if (D_807FA8A0[i].unk8 != 0) {
            func_8066AEE4(D_807FA8A0[i].unk0, D_807FA8A0[i].unk4);
        }
    }
    if (D_80748E14 != NULL) {
        func_8061130C(D_80748E14);
        D_80748E14 = NULL;
    }
    D_807F9680 = 0;
}

s32 func_8066B4D4(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);

s32 func_8066B020(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;

    func_8066B5F4(arg0);
    func_8066B4D4(arg0, arg1, &sp1C, &sp18);
    if (sp18 == 0) {
        return 0;
    }
    return sp1C;
}

// getUncompressedFileSize()?
s32 func_8066B06C(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;

    if (D_80748E18[arg0] != 0) {
        sp18 = *(D_807FB1A0[arg0] + arg1);
    } else {
        func_8066B5F4(arg0);
        func_8066B4D4(arg0, arg1, &sp1C, &sp18);
    }
    return sp18;
}

void func_8066B0DC(void) {
    D_807F967C = 1;
}

void func_8066B0EC(s32 arg0) {
    D_807F9678 = arg0;
}

void *getPointerTableFile(s32 pointerTableIndex, s32 fileIndex, u8 arg2, u8 arg3) {
    s32 temp;
    u32 sp50;
    s32 sp4C;
    void *var_v0;
    s32 var_a1;
    void *sp40;

    func_8066B5F4(pointerTableIndex);
    if (!arg3) {
        if ((fileIndex >= 0x80000000) && (fileIndex < 0xA0000000)) {
            func_8066B8C8(fileIndex, pointerTableIndex, 0);
            D_807F967C = 0;
            D_807F9678 = 0;
            return fileIndex;
        }
        var_v0 = func_8066B5C8(pointerTableIndex, fileIndex);
        if (var_v0 != 0) {
            func_8066B8C8(var_v0, pointerTableIndex, fileIndex);
            D_807F967C = 0;
            D_807F9678 = 0;
            return var_v0;
        }
    }
    func_8066B4D4(pointerTableIndex, fileIndex, &sp50, &sp4C);
    if (sp4C == 0) {
        D_807F967C = 0;
        D_807F9678 = 0;
        return NULL;
    }
    if (D_80748E18[pointerTableIndex] != 0) {
        var_a1 = D_807FB1A0[pointerTableIndex][fileIndex];
    } else {
        var_a1 = sp4C;
    }
    if (D_807F9678 == 0) {
        var_v0 = malloc(var_a1);
    } else {
        var_v0 = func_806111BC(D_807F9678, var_a1);
    }
    if (arg2 != 0) {
        if (D_80748E18[pointerTableIndex] != 0) {
            sp40 = malloc(sp4C);
            func_8060B140(sp50, sp40, &sp4C, 0, 0, 0, 0);
            func_8066AEE4(sp40, var_v0);
        } else {
            func_8060B140(sp50, var_v0, &sp4C, 0, 0, 0, 0);
        }
    } else {
        if (D_807F9680 == 0xC0) {
            func_80732354(6, 0, 0, 0);
        }
        D_807FA8A0[D_807F9680].unk8 = D_80748E18[pointerTableIndex];
        if (D_80748E18[pointerTableIndex] != 0) {
            D_807FA8A0[D_807F9680].unk0 = malloc(sp4C);
            D_807FA8A0[D_807F9680].unk4 = var_v0;
        } else {
            D_807FA8A0[D_807F9680].unk4 = var_v0;
            D_807FA8A0[D_807F9680].unk0 = var_v0;
        }
        osInvalDCache(D_807FA8A0[D_807F9680].unk0, sp4C);
        osPiStartDma(&D_807F9688[D_807F9680].unk0, 0, 0, sp50, D_807FA8A0[D_807F9680].unk0, sp4C, &D_807656D0);
        D_807F9680 += 1;
    }
    func_8066B4AC(pointerTableIndex, fileIndex, var_v0);
    func_8066B8C8(var_v0, pointerTableIndex, fileIndex);
    D_807F967C = 0;
    D_807F9678 = 0;
    return var_v0;
}

void func_8066B424(void) {
    D_807F967D = 1;
}

void func_8066BC00(s32 arg0, s32 arg1, s32 arg2);

// It's usually a file from a pointer table in arg0
void func_8066B434(void *arg0, s32 arg1, s32 arg2) {
    s32 sp1C;
    s32 sp18;

    if (func_8066B9F4(arg0) == 0) {
        func_8066BC00(arg0, &sp1C, &sp18);
        func_8066B4AC(sp1C, sp18, 0);
        if (D_807F967D == 0) {
            func_8061134C(arg0);
        } else {
            func_8061130C(arg0);
        }
    }
    D_807F967D = 0;
}

void func_8066B4AC(s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0 = D_807F95A8[arg0];
    if (temp_v0) {
        *(temp_v0 + arg1) = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B4D4.s")

extern s32 D_8000DDCC;

s32 func_800057B0(s32, s32, f32, s32);

/*
// TODO: Pretty close, s16/u16 and stack nonsense
s32 func_8066B4D4(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s16 var_t0;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp2C;
    s32 temp_v0;
    s32 *temp_t1;

    temp_t1 = &D_807F9528[arg0][arg1];
    temp_v0 = temp_t1[0];
    var_t0 = arg1;
    if (temp_v0 & 0x80000000) {
        sp2C = 8;
        func_8060B140(D_8000DDCC + (temp_v0 & 0x7FFFFFFF), &sp38, &sp2C, 0, 0, 0, 0);
        var_t0 = func_800057B0(sp38, sp3C, 0, 0x30);
        func_8066B4D4(arg0, var_t0, arg2, arg3);
    } else {
        *arg2 = D_8000DDCC + temp_v0;
        *arg3 = temp_t1[1] - temp_v0;
    }
    return var_t0;
}
*/

s32 func_8066B5C8(s32 arg0, s32 arg1) {
    s32 phi_v1;

    phi_v1 = 0;
    if (D_807F95A8[arg0]) {
        phi_v1 = D_807F95A8[arg0][arg1];
    }
    return phi_v1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066B5F4.s")

typedef struct global_asm_struct_40 GlobalASMStruct40;

struct global_asm_struct_40 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    GlobalASMStruct40 *unk14; // Doubly linked list?
    GlobalASMStruct40 *unk18; // Doubly linked list?
};

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
} GlobalASMStruct65;

u32 func_8066C2B4(u32);
GlobalASMStruct40 *func_8066B924(GlobalASMStruct40 *arg0, u32 arg1, s32 arg2, s32 arg3);
void func_8066B7F4(GlobalASMStruct40 *arg0, u32 arg1, s32 *arg2, s32 *arg3);
void func_8066BA2C(s32 arg0, u8 *arg1, u16 *arg2, s32 *arg3);
void func_8066BE20(s32);
void func_8066BECC(GlobalASMStruct40 *arg0);
GlobalASMStruct40 *func_8066BF0C(GlobalASMStruct65 *arg0, s32 arg1, s32 arg2);
void func_8066BFF0(GlobalASMStruct40 *arg0, GlobalASMStruct40 *arg1, s32 *arg2);

extern s32 D_807F9628[];

s32 func_8066B75C(GlobalASMStruct40 *arg0) {
    s32 sp1C;

    if (arg0 == NULL) {
        return 0;
    }
    sp1C = func_8066B75C(arg0->unk14);
    return func_8066B75C(arg0->unk18) + sp1C + 1;
}

void func_8066B7AC(s32 arg0, s32 arg1, s32 arg2) {
    func_8066B7F4(D_807F9628[func_8066C2B4(arg0)], arg0, arg1, arg2);
}

void func_8066B7F4(GlobalASMStruct40 *arg0, u32 arg1, s32 *arg2, s32 *arg3) {
    u8 sp2F;
    u16 sp2C;
    s32 sp28;

    if (arg0 == NULL) {
        sp2F = 0;
        sp2C = 0;
        sp28 = 0;
        func_8066BA2C(arg1, &sp2F, &sp2C, &sp28);
        func_80732354(7, sp2F, sp2C, object_timer - sp28);
    }
    if (arg1 == arg0->unk0) {
        *arg2 = arg0->unk4;
        *arg3 = arg0->unk8;
        return;
    }
    if (arg0->unk0 < arg1) {
        func_8066B7F4(arg0->unk18, arg1, arg2, arg3);
        return;
    }
    func_8066B7F4(arg0->unk14, arg1, arg2, arg3);
}

void func_8066B8C8(u32 arg0, s32 arg1, s32 arg2) {
    u32 sp1C = func_8066C2B4(arg0);
    D_807F9628[sp1C] = func_8066B924(D_807F9628[sp1C], arg0, arg1, arg2);
}

GlobalASMStruct40 *func_8066B924(GlobalASMStruct40 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    if (arg0 == NULL) {
        arg0 = malloc(sizeof(GlobalASMStruct40));
        arg0->unkC = 1;
        arg0->unk0 = arg1;
        arg0->unk4 = arg2;
        arg0->unk8 = arg3;
        arg0->unk10 = D_807F967C;
        arg0->unk18 = NULL;
        arg0->unk14 = NULL;
    } else {
        if (arg1 == arg0->unk0) {
            arg0->unkC++;
            if (D_807F967C != 0) {
                arg0->unk10 = 1;
            }
        } else if (arg0->unk0 < arg1) {
            arg0->unk18 = func_8066B924(arg0->unk18, arg1, arg2, arg3);
        } else {
            arg0->unk14 = func_8066B924(arg0->unk14, arg1, arg2, arg3);
        }
    }
    return arg0;
}

// TODO: Is this GlobalASMStruct40 again?
typedef struct {
    s32 unk0;
    s16 unk4;
    s8 unk6;
    u8 unk7;
    s16 unk8;
    u16 unkA;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    s32 unk14;
    s32 unk18;
} Struct8066BB44;

s32 func_8066BB44(Struct8066BB44 *arg0, u32 arg1);

s32 func_8066B9F4(void *arg0) {
    return func_8066BB44(D_807F9628[func_8066C2B4(arg0)], arg0);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u16 unk8;
    u8 unkA;
} Struct807FB228;

extern Struct807FB228 D_807FB228[];

void func_8066BA2C(s32 arg0, u8 *arg1, u16 *arg2, s32 *arg3) {
    s32 var_v0;

    var_v0 = D_807FB221 - 1;
    if (var_v0 < 0) {
        var_v0 = 0x3F;
    }
    while (var_v0 != D_807FB220) {
        if (arg0 == D_807FB228[var_v0].unk4) {
            *arg1 = D_807FB228[var_v0].unkA;
            *arg2 = D_807FB228[var_v0].unk8;
            *arg3 = D_807FB228[var_v0].unk0;
            return;
        }
        var_v0 -= 1;
        if (var_v0 < 0) {
            var_v0 = 0x3F;
        }
    }
}

void func_8066BAB8(s32 arg0, u8 arg1, u16 arg2) {
    D_807FB228[D_807FB221].unk0 = object_timer;
    D_807FB228[D_807FB221].unk4 = arg0;
    D_807FB228[D_807FB221].unkA = arg1;
    D_807FB228[D_807FB221].unk8 = arg2;
    D_807FB221++;
    if (D_807FB221 == 0x40) {
        D_807FB221 = 0;
    }
    if (D_807FB220 == D_807FB221) {
        D_807FB220++;
        if (D_807FB220 == 0x40) {
            D_807FB220 = 0;
        }
    }
}

s32 func_8066BB44(Struct8066BB44 *arg0, u32 arg1) {
    s8 sp2F;
    s16 sp2C;
    s32 sp28;

    if (arg0 == NULL) {
        sp2F = 0;
        sp2C = 0;
        sp28 = 0;
        func_8066BA2C(arg1, &sp2F, &sp2C, &sp28);
        return 0;
    }
    if (arg1 == arg0->unk0) {
        if (arg0->unk10 == 0) {
            arg0->unkC = arg0->unkC - 1;
        }
        func_8066BAB8(arg1, arg0->unk7, arg0->unkA);
        return arg0->unkC;
    }
    if (arg0->unk0 < arg1) {
        return func_8066BB44(arg0->unk18, arg1);
    }
    return func_8066BB44(arg0->unk14, arg1);
}

void func_8066BC00(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C = func_8066C2B4(arg0);
    D_807F9628[sp1C] = func_8066BC5C(D_807F9628[sp1C], arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BC5C.s")

/*
// TODO: Quite close, similar issue as below
GlobalASMStruct40 *func_8066BC5C(GlobalASMStruct40 *arg0, u32 arg1, s32 *arg2, s32 *arg3) {
    GlobalASMStruct40 *phi_s0;

    // phi_s0 = arg0;
    if (arg0) {
        if (arg1 == arg0->unk0) {
            *arg2 = arg0->unk4;
            *arg3 = arg0->unk8;
            if (!arg0->unk14 && !arg0->unk18) {
                func_8061130C(arg0);
                arg0 = NULL;
            } else {
                if (!arg0->unk14) {
                    arg0 = arg0->unk18;
                    func_8061130C(arg0);
                } else if (!arg0->unk18) {
                    arg0 = arg0->unk14;
                    func_8061130C(arg0);
                } else {
                    arg0->unk18 = func_8066BD54(arg0->unk18, arg0, &arg0->unk4, &arg0->unk8, &arg0->unkC, &arg0->unk10);
                }
            }
        } else if (arg0->unk0 < arg1) {
            arg0->unk18 = func_8066BC5C(arg0->unk18, arg1, arg2, arg3);
        } else {
            arg0->unk14 = func_8066BC5C(arg0->unk14, arg1, arg2, arg3);
        }
    }
    return arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BD54.s")

/*
// TODO: a0/s0 mixup in one spot... Not sure how to fix
GlobalASMStruct40 *func_8066BD54(GlobalASMStruct40 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s8 *arg5) {
    GlobalASMStruct40 *pad;

    if (!arg0->unk14) {
        *arg1 = arg0->unk0;
        *arg2 = arg0->unk4;
        *arg3 = arg0->unk8;
        *arg4 = arg0->unkC;
        *arg5 = arg0->unk10;
        arg0 = arg0->unk18;
        func_8061130C(arg0);
    } else {
        arg0->unk14 = func_8066BD54(arg0->unk14, arg1, arg2, arg3, arg4, arg5);
    }
    return arg0;
}
*/

void func_8066BDE0() {
    int i;
    for (i = 0; i < 0x14; i++) {
        func_8066BE20(i);
    }
}

void func_8066BE20(s32 arg0) {
    s32 temp_v0;
    s32 *sp30;
    s32 sp2C;
    s32 sp28;

    sp28 = 0;
    temp_v0 = func_8066B75C(D_807F9628[arg0]);
    if (temp_v0 != 0) {
        sp30 = malloc(temp_v0 * sizeof(GlobalASMStruct65));
        func_8066BFF0(D_807F9628[arg0], sp30, &sp28);
        func_8066C0DC(sp30, 0, temp_v0 - 1);
        sp2C = func_8066BF0C(sp30, 0, temp_v0 - 1);
        func_8066BECC(D_807F9628[arg0]);
        D_807F9628[arg0] = sp2C;
        func_8061130C(sp30);
    }
}

// Recursion :O
void func_8066BECC(GlobalASMStruct40 *arg0) {
    if (arg0) {
        func_8066BECC(arg0->unk14);
        func_8066BECC(arg0->unk18);
        func_8061130C(arg0);
    }
}

GlobalASMStruct40 *func_8066BF0C(GlobalASMStruct65 *arg0, s32 arg1, s32 arg2) {
    GlobalASMStruct40 *temp_v0;
    s32 temp_t7;

    temp_v0 = malloc(sizeof(GlobalASMStruct40));
    temp_t7 = (arg1 + arg2) / 2;
    temp_v0->unk0 = arg0[temp_t7].unk0;
    temp_v0->unk4 = arg0[temp_t7].unk4;
    temp_v0->unk8 = arg0[temp_t7].unk8;
    temp_v0->unkC = arg0[temp_t7].unkC;
    temp_v0->unk10 = arg0[temp_t7].unk10;
    if (arg1 != temp_t7) {
        temp_v0->unk14 = func_8066BF0C(arg0, arg1, temp_t7 - 1);
    } else {
        temp_v0->unk14 = NULL;
    }
    if (arg2 != temp_t7) {
        temp_v0->unk18 = func_8066BF0C(arg0, temp_t7 + 1, arg2);
    } else {
        temp_v0->unk18 = NULL;
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066BFF0.s")

/*
// TODO: Close, not sure what's wrong
void func_8066BFF0(GlobalASMStruct40 *arg0, GlobalASMStruct40 *arg1, s32 *arg2) {
    while (arg0) {
        arg1[*arg2].unk0 = arg0->unk0;
        arg1[*arg2].unk4 = arg0->unk4;
        arg1[*arg2].unk8 = arg0->unk8;
        arg1[*arg2].unkC = arg0->unkC;
        arg1[*arg2].unk10 = arg0->unk10;
        *arg2 += 1;
        func_8066BFF0(arg0->unk14, arg1, arg2);
        arg0 = arg0->unk18;
    }
}
*/

// Doable but kinda annoying
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_8066C0DC.s")

u32 func_8066C2B4(u32 arg0) {
    return (u32) (arg0 >> 0xC) % 0x14U;
}