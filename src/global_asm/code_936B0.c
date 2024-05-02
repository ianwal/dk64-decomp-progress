#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_8071FFA0;
extern s32 D_global_asm_80720020; // TODO: Type
extern s32 D_global_asm_80720054; // TODO: Datatype
extern s32 D_global_asm_807200EC; // TODO: Datatype
extern s32 D_global_asm_80720120; // TODO: Datatype
extern s32 D_global_asm_807201D4;
extern s32 D_global_asm_807202D0; // TODO: Type
extern s32 D_global_asm_80720BE8;

extern u8 D_global_asm_80750270;
extern s16 D_global_asm_807502D0;
extern f32 D_global_asm_807502E4;
extern f32 D_global_asm_80750300;
extern s16 D_global_asm_80750344;
extern u8 D_global_asm_80750AD0;

extern u32 D_global_asm_8076A068;

extern s16 D_global_asm_80770628[];
extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];

extern f32 D_global_asm_807FC7B0;
extern f32 D_global_asm_807FC7B4;
extern f32 D_global_asm_807FC7B8;

extern u8 D_global_asm_807FBB85;

void func_global_asm_8061EF4C(Actor*, s32, s32, f32, f32, f32, f32, f32);
void func_global_asm_8061F2B8(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);
s32 func_global_asm_8070033C(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32);

void func_global_asm_8068E9B0(Actor **arg0) {
    f32 sp2C;
    PlayerAdditionalActorData *PaaD = (*arg0)->PaaD;

    getBonePosition(PaaD->vehicle_actor_pointer, 9, &(*arg0)->x_position, &sp2C, &(*arg0)->z_position);
    if ((*arg0)->y_position < sp2C) {
        (*arg0)->y_position = sp2C;
    }
    (*arg0)->y_rotation = PaaD->vehicle_actor_pointer->y_rotation;
    renderActor(*arg0, 0);
}

void func_global_asm_8068EA38(Actor **arg0) {
    PlayerAdditionalActorData *PaaD;
    RaceAdditionalActorData *RaaD;
    Actor *vehicle;

    PaaD = (*arg0)->PaaD;
    vehicle = PaaD->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if (RaaD->unk34 < 5) {
            (*arg0)->x_position = PaaD->vehicle_actor_pointer->x_position;
            (*arg0)->y_position = PaaD->vehicle_actor_pointer->y_position;
            (*arg0)->z_position = PaaD->vehicle_actor_pointer->z_position;
            (*arg0)->y_rotation = PaaD->vehicle_actor_pointer->y_rotation;
            (*arg0)->z_rotation = PaaD->vehicle_actor_pointer->z_rotation;
            (*arg0)->x_rotation = PaaD->vehicle_actor_pointer->x_rotation;
            (*arg0)->unkAC = PaaD->vehicle_actor_pointer->unkAC;
            if (PaaD->vehicle_actor_pointer->unk58 == ACTOR_CAR_FACTORY_PLAYER) {
                (*arg0)->unkB8 = PaaD->vehicle_actor_pointer->unkB8 * 10.0f;
            } else {
                (*arg0)->unkB8 = PaaD->vehicle_actor_pointer->unkB8;
            }
        } else {
            (*arg0)->unkB8 = 0.0f;
        }
    }
    renderActor(*arg0, 0);
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct8068EB3C_arg4;

s32 func_global_asm_8068EB3C(f32 arg0, f32 arg1, f32 arg2, Struct8068EB3C_arg4 *arg3, Struct8068EB3C_arg4 *arg4, Struct8068EB3C_arg4 *arg5, Struct8068EB3C_arg4 *arg6, f32 *arg7, f32 *arg8, f32 *arg9) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    func_global_asm_8061F2B8(arg0, arg1, arg2, arg3->unk0, arg3->unk4, arg3->unk8, arg4->unk0, arg4->unk4, arg4->unk8, &sp48, &sp4C, &sp50);
    func_global_asm_8061F2B8(arg0, arg1, arg2, arg5->unk0, arg5->unk4, arg5->unk8, arg6->unk0, arg6->unk4, arg6->unk8, &sp54, &sp58, &sp5C);
    if ((((arg0 - sp48) * (arg0 - sp48)) + ((arg1 - sp4C) * (arg1 - sp4C)) + ((arg2 - sp50) * (arg2 - sp50))) < (((arg2 - sp5C) * (arg2 - sp5C)) + (((arg0 - sp54) * (arg0 - sp54)) + ((arg1 - sp58) * (arg1 - sp58))))) {
        *arg7 = sp48;
        *arg8 = sp4C;
        *arg9 = sp50;
        return 0;
    } else {
        *arg7 = sp54;
        *arg8 = sp58;
        *arg9 = sp5C;
        return 1;
    }
}

void func_global_asm_8068ECF4(s32 arg0, u8 arg1) {
    ActorAnimationState *temp_v0;
    f32 temp_f2;
    f32 var_f2;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 var_f6;
    s16 var_v0;
    u8 temp_t4;
    f32 z;
    f32 var_f0;
    f32 x;

    getBonePosition(current_actor_pointer, arg0, &sp48, &sp44, &sp40);
    x = sp48 - character_change_array->look_at_eye_x;
    z = character_change_array->look_at_eye_z - sp40;
    temp_f2 = ((651.8986206f * func_global_asm_80611BB4(z, x)));
    temp_f2 = (s16)(temp_f2 + 1024.0f) & 0xFFF;
    if (current_actor_pointer->y_rotation < temp_f2) {
        var_v0 = temp_f2 - current_actor_pointer->y_rotation;
    } else {
        var_v0 = current_actor_pointer->y_rotation - temp_f2;
    }
    if (var_v0 >= 0x801) {
        var_v0 = 0x1000 - var_v0;
    }
    if (var_v0 < 0x384) {
        var_f0 = (1024.0f - var_v0) * 0.001428571413f;
        if (var_f0 < 1.0f) {
            var_f2 = var_f0;
        } else {
            var_f2 = 1.0f;
        }
        var_f6 = arg1;
        temp_t4 = (var_f2 * var_f6);
        if (temp_t4 != 0) {
            temp_v0 = current_actor_pointer->animation_state;
            var_f0 = 3.3f;
            if (temp_v0 != NULL) {
                var_f0 *= temp_v0->scale_y;
            }
            changeActorColor(0xFF, 0xFF, 0xFF, temp_t4);
            func_global_asm_80714C08(&D_global_asm_80720054, var_f0, current_actor_pointer, arg0, 2);
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_8068EF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_8068F72C.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
} Struct8068FF40_arg1;

typedef struct {
    u16 unk0;
    u16 unk2;
} Struct8068FF40_arg2;

void func_global_asm_8068FF40(u8 arg0, Struct8068FF40_arg1 *arg1, Struct8068FF40_arg2 *arg2) {
    f32 var_f0;
    f32 var_f2;
    AnimationStateUnk1C *temp_v1;

    temp_v1 = current_actor_pointer->animation_state->unk1C;
    if (arg0) {
        var_f0 = 500.0f;
        var_f2 = 0.0f;
    } else {
        var_f0 = 0.0f;
        var_f2 = arg1->unkC * (400.0 - (0.7 * current_actor_pointer->unkB8));
    }
    arg2->unk2 = func_global_asm_806CC190(arg2->unk2, var_f0, 5.0f);
    arg2->unk0 = func_global_asm_806CC190(arg2->unk0, (s32)var_f2 & 0xFFF, 3.0f);
    temp_v1->unk0 = -0x80;
    temp_v1->unk1 = 1;
    temp_v1->unk2 = arg2->unk2 * 0x10;
    temp_v1->unk4 = arg2->unk0 * 0x10;
    temp_v1->unk6 = 0;
    temp_v1[1].unk0 = 0;
}

void func_global_asm_80690058(Actor *arg0, s32 arg1) {
    arg0->animation_state->unk1C = malloc(arg1 * sizeof(AnimationStateUnk1C));
    func_global_asm_80611690(arg0->animation_state->unk1C);
}

void func_global_asm_80690094(Actor *arg0, Actor *player) {
    u8 sp37 = 0;
    PlayerAdditionalActorData *PaaD = player->PaaD;

    setAction(0x4C, arg0, PaaD->unk1A4);
    if (current_map == MAP_GALLEON_PUFFTOSS) {
        sp37 = 0x3C;
    }
    func_global_asm_80604CBC(arg0, 0x115, sp37, 1, 0, 0xFF, 1.0f, 0);
    func_global_asm_80604CBC(arg0, 0x116, sp37, 1, 1, 0xFF, 1.0f, 0);
    func_global_asm_80688370(arg0, 0, 1.0f);
    func_global_asm_8068842C(arg0, 0, -1);
    func_global_asm_80690058(arg0, 2);
    moveAndScaleActorToAnother(arg0, player, 0.15f);
}

typedef struct {
    f32 unk0;
    f32 unk4; // Used
} Struct80690190;

void func_global_asm_80690190(Struct80690190 *arg0, s32 arg1) {
    s16 temp_a1;

    temp_a1 = D_global_asm_80770628[current_actor_pointer->unk6E[0]];
    if (current_actor_pointer->y_position < (current_actor_pointer->unkAC + 4.0f)) {
        D_global_asm_80770B68[temp_a1] = (current_actor_pointer->unkB8 / 300.0) + 1.0;
        D_global_asm_80770BC0[temp_a1] = 1.0f;
    } else {
        D_global_asm_80770B68[temp_a1] = arg0->unk4 + 1.2;
        D_global_asm_80770BC0[temp_a1] = 5.0f;
    }
    temp_a1 = D_global_asm_80770628[current_actor_pointer->unk70];
    if (current_actor_pointer->y_position < (current_actor_pointer->unkAC + 4.0f)) {
        if (D_global_asm_80770BC0[temp_a1] == 0.0f) {
            D_global_asm_80770B68[temp_a1] = ((((u32)func_global_asm_806119A0() / 4294967295.0) * 0.05) + 0.975) * (0.2 + (current_actor_pointer->unkB8 / 300.0));
            D_global_asm_80770BC0[temp_a1] = 1.0f;
        }
    } else {
        D_global_asm_80770B68[temp_a1] = (arg0->unk4 * 1.5) + 0.2;
        D_global_asm_80770BC0[temp_a1] = 8.0f;
    }
}

void func_global_asm_806903BC(Actor *actor, RaceAdditionalActorData *arg1) {
    ExitData *exit;
    s16 angle;

    exit = getExitData(arg1->unk36);
    actor->x_position = exit->x_pos;
    actor->y_position = exit->y_pos;
    actor->z_position = exit->z_pos;
    angle = exit->angle * 16.06274605f;
    actor->y_rotation = angle;
    actor->unkEE = angle;
    arg1->unk0 = angle;
}

void func_global_asm_80690470(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;
    RaceAdditionalActorData *RaaD;
    s32 pad;
    Actor *propeller;

    PaaD = arg0->PaaD;
    spawnActor(ACTOR_PROPELLER, 0xDA);
    propeller = last_spawned_actor;
    RaaD = propeller->RaaD;
    RaaD->unk28 = PaaD->unk1A4;
    func_global_asm_80690094(propeller, arg0);
    RaaD->unk35 = 0;
    RaaD->unk27 = 0;
    RaaD->unk0 = arg0->y_rotation;
    PaaD->vehicle_actor_pointer = propeller;
    propeller->object_properties_bitfield &= 0xFFFDFFFF;
}

typedef struct {
    u8 unk0[0x28 - 0x0];
    u8 unk28;
    u8 unk29[0x34 - 0x29];
    u8 unk34;
} AAD_global_asm_80690500;

typedef struct {
    u8 unk0[0xF3 - 0x0];
    u8 unkF3;
} AAD_global_asm_80690500_unk104;

typedef struct {
    s32 unk0;
} A178_80690500;

void func_global_asm_80690500(void) {
    AAD_global_asm_80690500 *aaD;
    Actor *player;
    PlayerAdditionalActorData *PaaD;
    A178_80690500 *a178;
    AAD_global_asm_80690500_unk104 *aaD_104;
    u8 sp4B;
    f32 x;
    f32 y;
    f32 z;

    aaD = current_actor_pointer->additional_actor_data;
    a178 = current_actor_pointer->unk178;
    player = character_change_array[aaD->unk28].player_pointer;
    PaaD = player->PaaD;
    aaD_104 = PaaD->unk104->additional_actor_data;
    sp4B = current_actor_pointer->unk6A & 1;
    aaD->unk34 = 2;
    func_global_asm_80690190(aaD, a178);
    if (is_cutscene_active == 0) {
        if (aaD_104->unkF3 != 4) {
            func_global_asm_8061C6A8(PaaD->unk104, current_actor_pointer, 4, 0x800, 0xA0, 0, 6, 0x12C, 0x8F, 0, 0.2f);
        }
    }
    func_global_asm_8068F72C(aaD, a178, 1, 1);
    func_global_asm_8068FF40(sp4B, aaD, a178);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->y_acceleration = D_global_asm_80750300;
        current_actor_pointer->noclip_byte = 0x3C;
        setAction(0x4C, current_actor_pointer, PaaD->unk1A4);
    }
    if (func_global_asm_8061CB50() == 0 || (func_global_asm_8061CB50() != 0 && player_pointer->unk6A & 0x100)) {
        getBonePosition(current_actor_pointer, 1, &x, &y, &z);
        createLight(x, y, z, 0.0f, 0.0f, 0.0f, 300.0f, 0, 0xFF, 0xFF, 0xFF);
        if (isFlagSet(0x6B, FLAG_TYPE_TEMPORARY) == 0) {
            if (func_global_asm_8061CB50() != 0) {
                if (player_pointer->unk6A & 0x100) {
                    getBonePosition(current_actor_pointer, 2, &x, &y, &z);
                    func_global_asm_8070033C(x, y, z, 0.0f, 0.0f, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF);
                }
            }
            if (func_global_asm_8061CB50() == 0) {
                player_pointer->unk6A &= 0xFEFF;
            }
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806907B8(void) {
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806907E0(void) {
    D_global_asm_80750270 = 1;
}

void func_global_asm_806907F0(f32 arg0, f32 arg1, f32 arg2) {
    D_global_asm_807FC7B0 = arg0;
    D_global_asm_807FC7B4 = arg1;
    D_global_asm_807FC7B8 = arg2;
}

void func_global_asm_80690814(Actor *arg0, s32 arg1) {
    getBonePosition(arg0, arg1, &D_global_asm_807FC7B0, &D_global_asm_807FC7B4, &D_global_asm_807FC7B8);
}

void func_global_asm_8069084C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, f32 arg4, f32 arg5, Actor *arg6) {
    s32 temp;
    s32 temp2;
    f32 sp28[6];

    sp28[0] = (arg3 / 4095.0) * TWO_PI;
    sp28[1] = arg4;
    sp28[2] = arg5;
    sp28[3] = arg2;
    sp28[4] = arg1;
    sp28[5] = D_global_asm_80750270;
    func_global_asm_806891D8(arg0, D_global_asm_807FC7B0, D_global_asm_807FC7B4, D_global_asm_807FC7B8, 0, arg2, arg6, &sp28);
    D_global_asm_80750270 = 0;
}

void func_global_asm_80690930(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, Actor *arg8) {
    f32 sp2C;
    f32 sp28;
    f32 temp_f0_2;
    f32 temp_f14_2;
    f32 temp_f2_2;

    temp_f0_2 = sqrtf(((arg4 - D_global_asm_807FC7B0) * (arg4 - D_global_asm_807FC7B0)) + ((arg5 - D_global_asm_807FC7B4) * (arg5 - D_global_asm_807FC7B4)) + ((arg6 - D_global_asm_807FC7B8) * (arg6 - D_global_asm_807FC7B8)));
    temp_f2_2 = (arg4 - D_global_asm_807FC7B0);
    sp28 = arg5 - D_global_asm_807FC7B4;
    sp2C = temp_f0_2;
    func_global_asm_8069084C(arg1, arg2, arg3, arg0, sqrtf(((arg4 - D_global_asm_807FC7B0) * (arg4 - D_global_asm_807FC7B0)) + ((arg6 - D_global_asm_807FC7B8) * (arg6 - D_global_asm_807FC7B8))) / (sp2C / arg7), sp28 / (sp2C / arg7), arg8);
}

void func_global_asm_80690A28(s16 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Actor *arg7) {
    func_global_asm_80690930(func_global_asm_80665DE0(arg3, arg5, D_global_asm_807FC7B0, D_global_asm_807FC7B8), arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void func_global_asm_80690AB0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, Actor *arg9) {
    s16 temp_t0;
    s16 temp_t6;
    s16 var_s0;

    var_s0 = func_global_asm_80665DE0(arg5, arg7, D_global_asm_807FC7B0, D_global_asm_807FC7B8);
    if (arg1 < func_global_asm_806CC14C(arg0, var_s0)) {
        temp_t0 = (arg0 - arg1) & 0xFFF;
        temp_t6 = (arg0 + arg1) & 0xFFF;
        if (func_global_asm_806CC14C(var_s0, temp_t0) < func_global_asm_806CC14C(var_s0, temp_t6)) {
            var_s0 = temp_t0;
        } else {
            var_s0 = temp_t6;
        }
    }
    func_global_asm_80690930(var_s0, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

void func_global_asm_80690BE8(s16 arg0, s16 arg1, f32 arg2, Actor *arg3, s32 boneIndex, f32 arg5, Actor *arg6) {
    f32 x;
    f32 y;
    f32 z;

    getBonePosition(arg3, boneIndex, &x, &y, &z);
    func_global_asm_80690A28(arg0, arg1, arg2, x, y, z, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_80690C60.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_80690F30.s")

void func_global_asm_806915B0(void) {
    f32 randomZ;
    f32 randomY;
    f32 randomX;
    s32 i;
    s32 max;

    if (D_global_asm_80750AD0 != 0) {
        max = 3;
    } else {
        max = 6;
    }
    for (i = 0; i < max; i++) {
        randomX = ((((func_global_asm_806119A0()) / 10000U) % 200) / 5.0) - 20.0;
        randomY = ((((func_global_asm_806119A0()) / 10000U) % 200) / 5.0) - 20.0;
        randomZ = ((((func_global_asm_806119A0()) / 10000U) % 200) / 5.0) - 20.0;
        func_global_asm_807149B8(1);
        changeActorColor(0x8C, 0x8C, 0x8C, 0x64);
        func_global_asm_80714950(i * -0x14);
        func_global_asm_80714998(3);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        drawSpriteAtPosition(
            &D_global_asm_8071FFA0,
            2.0f,
            current_actor_pointer->x_position +         randomX,
            current_actor_pointer->y_position + 42.0f + randomY,
            current_actor_pointer->z_position +         randomZ
        );
    }
}

void func_global_asm_80691830(s16 modelIndex, f32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    spawnActor(ACTOR_BOSS_SHOCKWAVE, modelIndex);
    moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, arg1);
    last_spawned_actor->unkF0 = modelIndex;
    last_spawned_actor->unk16A = arg2;
    last_spawned_actor->unk16B = arg3;
    last_spawned_actor->unk16C = arg4;
    last_spawned_actor->unk15F = arg5;
    last_spawned_actor->unk168 = 1;
    last_spawned_actor->unk160 = arg6;
    if (arg7 != 0.0f) {
        func_global_asm_80661520(current_actor_pointer->x_position, current_actor_pointer->z_position, arg7, 2.0f, arg8, arg9);
    }
    func_global_asm_8061F0B0(D_global_asm_807F5D10, 0x50, 0x14);
}

// TODO: Add to AAD union
typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s8 unk10;
    s8 unk11;
} TempAAD2;

void func_global_asm_80691930(u8 arg0, u8 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5) {
    TempAAD2 *temp_v0;

    spawnActor(ACTOR_BOSS_DOGADON_SHOCKWAVE, 0);
    moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, 0.15f);
    temp_v0 = last_spawned_actor->additional_actor_data;
    temp_v0->unk11 = arg0;
    temp_v0->unk8 = arg2;
    temp_v0->unkC = arg3;
    temp_v0->unk0 = arg1;
    last_spawned_actor->y_position = current_actor_pointer->unkA8;
    last_spawned_actor->unk15F = arg4;
    last_spawned_actor->unk168 = arg5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_806919E0.s")

typedef struct {
    s32 unk0;
    u8 unk4[0x12 - 0x4];
    u8 unk12;
    u8 unk13;
} AAD_global_asm_806921DC;

void func_global_asm_806921DC(u8 arg0) {
    AAD_global_asm_806921DC *sp2C;

    sp2C = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6E[0] = -2;
        current_actor_pointer->unk6A &= ~1;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.283185482f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 40.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 30.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(1);
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(&func_global_asm_8071C914);
        func_global_asm_80714950((rand() >> 0xF) % 360);
        func_global_asm_807149A8(2000);
        switch (arg0) {
            case 0:
                changeActorColor(0xFF, 0xD7, 0x58, 0xFF);
                func_global_asm_80714C08(&D_global_asm_80720120, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
                break;
            case 1:
                changeActorColor(0xC8, 0xC8, 0xFA, 0x9B);
                func_global_asm_80714C08(&D_global_asm_80720BE8, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
                break;
        }
        sp2C->unk13 = current_actor_pointer->unk124->unk10;
        sp2C->unk0 = D_global_asm_8076A068;
        sp2C->unk12 = 0;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 4.0f);
    if ((current_actor_pointer->unk6A & 1)
        || (current_actor_pointer->unkFC != 0)
        || (D_global_asm_807FBB85 != 0)
        || (sp2C->unk0 + 0x18) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

void func_global_asm_80692500(void) {
    func_global_asm_806921DC(0);
}

void func_global_asm_80692520(void) {
    func_global_asm_806921DC(1);
}

void func_global_asm_80692540(void) {
    func_global_asm_806919E0(&D_global_asm_807201D4);
}

void func_global_asm_80692564(void) {
    func_global_asm_806919E0(&D_global_asm_807201D4);
}

void func_global_asm_80692588(void) {
    func_global_asm_806919E0(&D_global_asm_807201D4);
}

void func_global_asm_806925AC(void) {
    AnotherAdditionalActorData *sp1C;

    sp1C = current_actor_pointer->AaaD;
    func_global_asm_806919E0(&D_global_asm_807201D4);
    if (sp1C->unk13 == 1) {
        current_actor_pointer->y_velocity += D_global_asm_807502E4;
        if (current_actor_pointer->y_velocity < D_global_asm_807502D0) {
            current_actor_pointer->y_velocity = D_global_asm_807502D0;
        }
    }
}

typedef struct {
    s32 unk0;
} AAD_global_asm_80692640;

void func_global_asm_80692640(void) {
    AAD_global_asm_80692640 *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.283185482f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 50.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 40.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714C08(&D_global_asm_80720020, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk0 = D_global_asm_8076A068;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0x96, 0x78, 0, 1.0f);
    if (current_actor_pointer->unkFC != 0
        || (current_actor_pointer->unk6A & 1)
        || D_global_asm_807FBB70.unk15 != 0
        || D_global_asm_807FBB70.unk200 == 9) {
        if (current_actor_pointer->unk11C == NULL
        || (current_actor_pointer->unk11C->unk58 != ACTOR_TTT_GUN)
        || (current_actor_pointer->unk11C->unk58 == ACTOR_TTT_GUN && (current_actor_pointer->unkFC != 0 || (current_actor_pointer->unk6A & 1)))) {
            func_global_asm_807149B8(0);
            func_global_asm_807149FC(1);
            func_global_asm_8071498C(&func_global_asm_8071D260);
            func_global_asm_80714950(0xC);
            drawSpriteAtPosition(&D_global_asm_807202D0, 0.75f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        }
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x61, 0xFF, 0x7F, 0x1E, 0, 0.0f, 0);
        deleteActor(current_actor_pointer);
    }
    if ((aaD->unk0 + D_global_asm_80750344) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

void func_global_asm_80690C60(u16 arg0, void *arg1, void *arg2, u8 arg3);

extern s32 D_global_asm_8072029C; // TODO: Type
extern s32 D_global_asm_80720BA0; // TODO: Type
extern s16 D_global_asm_8075035C;
extern s16 D_global_asm_80750370;
extern u8 D_global_asm_80750AD0;
extern u32 D_global_asm_8076A068;
extern u8 D_global_asm_807FBB85;
extern s32 D_global_asm_8071FB34; // Sprite?
extern s32 D_global_asm_807201A0; // Sprite?
extern s16 D_global_asm_80750358;
extern s16 D_global_asm_8075036C;

extern s32 D_global_asm_807200A0; // TODO: Type
extern s16 D_global_asm_80750350;
extern s16 D_global_asm_80750364;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
} AAD_80692940;

void func_global_asm_80692940(void) {
    AAD_80692940 *aaD;
    s32 i;
    s32 sp3C;
    u16 var_a0;
    u8 var_v0_2;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 50.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 40.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714A28(4);
        func_global_asm_80714C08(&D_global_asm_807200A0, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk14 = current_actor_pointer->unk124->unkC;
        aaD->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= 0x01080000;
        current_actor_pointer->unk16E = 0x3C;
        current_actor_pointer->unk16F = 0x3C;
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        aaD->unk1C = 0;
    }
    sp3C = D_global_asm_80750350;
    if (aaD->unk13 & 2) {
        var_a0 = 2;
        if (cc_number_of_players >= 2) {
            var_a0 = 3;
        }
        func_global_asm_80690C60(var_a0, current_actor_pointer, &D_global_asm_807200A0, 0);
    }
    if (aaD->unk13 & 4) {
        sp3C = D_global_asm_80750364;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    if (current_map == MAP_KROOL_FIGHT_DIDDY_PHASE) {
        current_actor_pointer->unkFA = 0x2328;
        var_v0_2 = current_actor_pointer->unkFC != 0 && func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->unkEE) == 0;
    } else {
        var_v0_2 = current_actor_pointer->unkFD;
    }
    if ((var_v0_2 != 0) || (func_global_asm_80665558() != 0) || ((current_actor_pointer->unk6A & 1) && (func_global_asm_8066641C() == 1)) || (D_global_asm_807FBB85 != 0) || ((current_actor_pointer->unk124->unk14 != 0.0f) && ((aaD->unk0 + 1) < D_global_asm_8076A068))) {
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x1006E);
        func_global_asm_8071498C(func_global_asm_8071A8B0);
        drawSpriteAtPosition(&D_global_asm_8071FB34, 0.45f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        playSoundAtActorPosition(current_actor_pointer, 0x8D, 0xFF, 0x7F, 0x1E);
        deleteActor(current_actor_pointer);
        if (D_global_asm_80750AD0 == 0) {
            for (i = 0; i != 0xC; i += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(i + 0x0B000000);
                func_global_asm_8071498C(func_global_asm_8071ABDC);
                drawSpriteAtPosition(&D_global_asm_807200EC, 0.35f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
    }
    if (cc_number_of_players >= 2) {
        sp3C = sp3C * 1.4f;
    }
    if (current_map == MAP_AZTEC_TINY_TEMPLE) {
        sp3C *= 1.2;
    }
    if ((aaD->unk0 + sp3C) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
} AAD_80692E50;

void func_global_asm_80692E50(void) {
    AAD_80692E50 *aaD;
    u16 var_a0;
    s32 sp3C;
    s32 i;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 60.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 50.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714A28(4);
        func_global_asm_80714C08(&D_global_asm_8072029C, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk14 = current_actor_pointer->unk124->unkC;
        aaD->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= 0x01080000;
        current_actor_pointer->unk16E = 0x3C;
        current_actor_pointer->unk16F = 0x3C;
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        aaD->unk1C = 0;
    }
    sp3C = D_global_asm_8075035C;
    if (aaD->unk13 & 2) {
        var_a0 = 2;
        if (cc_number_of_players >= 2) {
            var_a0 = 3;
        }
        func_global_asm_80690C60(var_a0, current_actor_pointer, &D_global_asm_8072029C, 0);
    }
    if (aaD->unk13 & 4) {
        sp3C = D_global_asm_80750370;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    if ((current_actor_pointer->unkFD != 0) || (func_global_asm_80665558() != 0) || ((current_actor_pointer->unk6A & 1) && (func_global_asm_8066641C() == 1)) || (D_global_asm_807FBB85 != 0) || ((current_actor_pointer->unk124->unk14 != 0.0f) && ((aaD->unk0 + 1) < D_global_asm_8076A068))) {
        if (D_global_asm_80750AD0 == 0) {
            for (i = 0; i != 0xC; i += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(i + 0x05000000);
                func_global_asm_80714998(1);
                func_global_asm_8071498C(func_global_asm_8071ABDC);
                drawSpriteAtPosition(&D_global_asm_80720BA0, 0.35f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
        playSoundAtActorPosition(current_actor_pointer, 0x91, 0xFF, 0x7F, 0x1E);
        deleteActor(current_actor_pointer);
    }
    if (cc_number_of_players >= 2) {
        sp3C *= 1.4f;
    }
    if ((aaD->unk0 + sp3C) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

void func_global_asm_8069329C(void) {
    s32 i;

    func_global_asm_807149B8(1);
    func_global_asm_80714950(0x1006E);
    func_global_asm_8071498C(&func_global_asm_8071A8B0);
    drawSpriteAtPosition(&D_global_asm_80720120, 2.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 22.0f, current_actor_pointer->z_position);
    for (i = 0; i < cc_number_of_players; i++) {
        func_global_asm_8061EF4C(character_change_array[i].player_pointer->PaaD->unk104, 7, 0x16, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
    }
    func_global_asm_806915B0();
    if (D_global_asm_80750AD0 == 0) {
        for (i = 0; i < 0xC; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_80714950(i + 0x0B010000);
            func_global_asm_8071498C(&func_global_asm_8071ABDC);
            drawSpriteAtPosition(&D_global_asm_807200EC, 0.35f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        }
    }
    playSoundAtActorPosition(current_actor_pointer, 0xF6, 0xFF, 0x7F, 0x1E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_8069346C.s")

extern s32 D_global_asm_80720268; // TODO: Type

typedef struct {
    s32 unk0; // Used
    u8 unk4; // Used
    u8 unk5[0x13 - 0x5];
    u8 unk13; // Used
    u8 unk14[0x1C - 0x14];
    s32 unk1C; // Used
} AAD_80693EC0;

void func_global_asm_80693EC0(void) {
    AAD_80693EC0 *aaD;
    char pad[2];
    u8 sp47;
    s16 temp_v0;
    s16 var_a1;
    s16 temp_v0_2;

    aaD = current_actor_pointer->additional_actor_data;
    sp47 = 0;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        playSoundAtActorPosition(current_actor_pointer, 0xF4, 0xFF, 0x7F, 5);
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = (current_actor_pointer->unk124->unk4 / 4) * 2.6;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 60.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 50.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        changeActorColor(0, 0xFF, 0, 0xFF);
        func_global_asm_80714C08(&D_global_asm_80720268, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk0 = D_global_asm_8076A068;
        aaD->unk4 = 0;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
        current_actor_pointer->unkFA = 0x2328;
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        if (aaD->unk13 == 0x63) {
            aaD->unk4 = 2;
        }
        aaD->unk1C = 0;
    }
    if ((aaD->unk0 + 0xA) < D_global_asm_8076A068) {
        current_actor_pointer->object_properties_bitfield &= 0xFFF7FFFF;
    }
    func_global_asm_80690C60(1, current_actor_pointer, NULL, 1);
    func_global_asm_8067ACB4(current_actor_pointer);
    if ((current_actor_pointer->unkFC != 0) && (func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->unkEE) == 0)) {
        playSoundAtActorPosition(current_actor_pointer, 0xF5, 0xFF, 0x7F, 0x1E);
        temp_v0 = func_global_asm_80672A70(current_actor_pointer->unkF4, current_actor_pointer->unkF6);
        var_a1 = ((current_actor_pointer->unkEE + 0x800) & 0xFFF);
        temp_v0_2 = (temp_v0 - var_a1);
        current_actor_pointer->unkEE = (temp_v0 + temp_v0_2);
        if (current_actor_pointer->unkEE < 0) {
            current_actor_pointer->unkEE += 0xFFF;
        }
        if (current_actor_pointer->unkEE >= 0x1000) {
            current_actor_pointer->unkEE -= 0xFFF;
        }
        if (func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->unkEE) == 0) {
            sp47 = 1;
        }
    }
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0x4B, 0x78, 0, 1.0f);
    current_actor_pointer->y_velocity += D_global_asm_807502E4;
    if (current_actor_pointer->y_velocity < D_global_asm_807502D0) {
        current_actor_pointer->y_velocity = D_global_asm_807502D0;
    }
    if ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1)) {
        switch (aaD->unk4) {
            case 0:
                current_actor_pointer->y_velocity = 200.0f;
                break;
            case 1:
                current_actor_pointer->y_velocity = 150.0f;
                break;
            case 2:
                current_actor_pointer->y_velocity = 100.0f;
                func_global_asm_8066EB40(current_actor_pointer, 200.0f);
                func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 180.0f, -1);
                break;
            case 3:
                current_actor_pointer->y_velocity = 80.0f;
                break;
        }
        playSoundAtActorPosition(current_actor_pointer, 0xF5, 0xFF, 0x7F, 0x1E);
        aaD->unk4 = aaD->unk4 + 1;
        current_actor_pointer->unkB8 = (current_actor_pointer->unkB8 / 3.0) * 2.5;
    }
    if ((current_actor_pointer->unk64 & 0x100) || (sp47 != 0)) {
        D_global_asm_807FBB85 = 1;
    }
    if (((current_actor_pointer->unk6A & 1) && (aaD->unk4 == 4)) || (D_global_asm_807FBB85 != 0)) {
        func_global_asm_8069329C();
        deleteActor(current_actor_pointer);
    }
    if ((aaD->unk0 + D_global_asm_80750344) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    u8 unk13;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
} AAD_806944BC;

void func_global_asm_806944BC(void) {
    AAD_806944BC *aaD;
    u16 var_a0;
    s32 sp3C;
    s32 var_s1;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 60.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 50.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714A28(4);
        func_global_asm_80714C08(&D_global_asm_807201A0, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk14 = current_actor_pointer->unk124->unkC;
        aaD->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= 0x01080000;
        current_actor_pointer->unk16E = 0x3C;
        current_actor_pointer->unk16F = 0x3C;
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        aaD->unk1C = 0;
    }
    sp3C = D_global_asm_80750358;
    if (aaD->unk13 & 2) {
        var_a0 = 2;
        if (cc_number_of_players >= 2) {
            var_a0 = 3;
        }
        func_global_asm_80690C60(var_a0, current_actor_pointer, &D_global_asm_807201A0, 0);
    }
    if (aaD->unk13 & 4) {
        sp3C = D_global_asm_8075036C;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    if ((func_global_asm_80665558() != 0) || (current_actor_pointer->unkFD != 0) || ((current_actor_pointer->unk6A & 1) && (func_global_asm_8066641C() == 1)) || (D_global_asm_807FBB85 != 0) || ((current_actor_pointer->unk124->unk14 != 0.0f) && ((aaD->unk0 + 1) < D_global_asm_8076A068))) {
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x1006E);
        func_global_asm_8071498C(func_global_asm_8071A8B0);
        drawSpriteAtPosition(&D_global_asm_8071FB34, 0.45f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        playSoundAtActorPosition(current_actor_pointer, 0x1E5, 0xFF, 0x7F, 0x1E);
        deleteActor(current_actor_pointer);
        if (D_global_asm_80750AD0 == 0) {
            for (var_s1 = 0; var_s1 != 0xC; var_s1 += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(var_s1 + 0x0B000000);
                func_global_asm_8071498C(func_global_asm_8071ABDC);
                drawSpriteAtPosition(&D_global_asm_807200EC, 0.35f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
    }
    if (cc_number_of_players >= 2) {
        sp3C = sp3C * 1.4f;
    }
    if ((aaD->unk0 + sp3C) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_80694948.s")

extern s32 D_global_asm_807206A8; // TODO: Datatype
extern s32 D_global_asm_807206DC; // TODO: Datatype
extern s16 D_global_asm_80750360;
extern s16 D_global_asm_80750374;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    u8 unk13;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
} AAD_80694D20;

void func_global_asm_80694D20(void) {
    AAD_80694D20 *aaD;
    s32 i;
    s32 sp3C;
    u16 var_a0;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 50.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 40.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714A28(4);
        func_global_asm_80714C08(&D_global_asm_807206A8, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk14 = current_actor_pointer->unk124->unkC;
        aaD->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= 0x01080000;
        current_actor_pointer->unk16E = 0x3C;
        current_actor_pointer->unk16F = 0x3C;
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        aaD->unk1C = 0;
    }
    sp3C = D_global_asm_80750360;
    if (aaD->unk13 & 2) {
        var_a0 = 2;
        if (cc_number_of_players >= 2) {
            var_a0 = 3;
        }
        func_global_asm_80690C60(var_a0, current_actor_pointer, &D_global_asm_807206A8, 0);
    }
    if (aaD->unk13 & 4) {
        sp3C = D_global_asm_80750374;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    if ((current_actor_pointer->unkFD != 0) || (func_global_asm_80665558() != 0) || ((current_actor_pointer->unk6A & 1) && (func_global_asm_8066641C() == 1)) || (D_global_asm_807FBB85 != 0) || ((current_actor_pointer->unk124->unk14 != 0.0f) && ((aaD->unk0 + 1) < D_global_asm_8076A068))) {
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x1006E);
        func_global_asm_8071498C(func_global_asm_8071A8B0);
        drawSpriteAtPosition(&D_global_asm_8071FB34, 0.45f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        playSoundAtActorPosition(current_actor_pointer, 0xFF, 0xFF, 0x7F, 5);
        deleteActor(current_actor_pointer);
        if (D_global_asm_80750AD0 == 0) {
            for (i = 0; i != 0xC; i += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(i + 0x0B000000);
                func_global_asm_8071498C(func_global_asm_8071ABDC);
                drawSpriteAtPosition(&D_global_asm_807206DC, 0.35f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
    }
    if (cc_number_of_players >= 2) {
        sp3C = sp3C * 1.4f;
    }
    if ((aaD->unk0 + sp3C) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

s32 func_global_asm_806951B0(Actor *arg0) {
    if (arg0->unk58 != ACTOR_PROJECTILE_FEATHER) {
        return TRUE;
    }
    if (arg0->control_state == 0) {
        return TRUE;
    }
    return FALSE;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_806951E8.s")

void func_global_asm_80695724(f32, u8);

extern s32 D_global_asm_8072006C; // Sprite
extern s16 D_global_asm_80750344;
extern u32 D_global_asm_8076A068;
extern u8 D_global_asm_807FBB85;

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    s32 unkC;
    s8 unk10;
    s8 unk11;
    u8 unk12;
} AAD_80695724;

void func_global_asm_80695724(f32 arg0, u8 arg1) {
    s32 pad2;
    s32 pad3;
    u8 red;
    u8 green;
    u8 blue;
    ActorAnimationState *temp_v0;
    s32 pad[14];
    AAD_80695724 *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (arg1 == 1) {
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x306, 0xFF, 0x7F, 0, 0, 0.3f, 0);
        }
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->y_rotation = current_actor_pointer->unkEE;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->unk132 = (u8)current_actor_pointer->unk124->unk10;
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale[0] = 2.0 * temp_v0->scale[0];
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale[1] = 2.0 * temp_v0->scale[1];
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale[2] = 2.0 * temp_v0->scale[2];
        aaD->unk8 = -(func_global_asm_80611BB4(current_actor_pointer->y_velocity, current_actor_pointer->unkB8) * 57.295776f);
        current_actor_pointer->noclip_byte = 0x3C;
        aaD->unk0 = D_global_asm_8076A068;
        aaD->unk12 = 0;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
        aaD->unk10 = 0;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, arg0);
    switch (arg1) {
        case 1:
            red = 0xFF;
            green = 0;
            blue = 0;
            break;
        case 0:
            red = 0xFF;
            green = 0xFF;
            blue = 0xFF;
            break;
    }
    func_global_asm_806595F0(1);
    createLight(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0.0f, 0.0f, 0.0f, 80.0f, 0, red, green, blue);
    if (arg1 == 1) {
        if ((aaD->unk12 == 0) && ((current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkFD != 0) || (D_global_asm_807FBB85 != 0))) {
            func_global_asm_80714950(0x1006E);
            func_global_asm_8071498C(func_global_asm_8071A8B0);
            drawSpriteAtPosition(&D_global_asm_8072006C, 1.2f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            func_global_asm_8068581C(NULL, 0, 0.8f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, -0x50);
            playSoundAtActorPosition(current_actor_pointer, 0xF6, 0xFF, 0x3F, 0x14);
            aaD->unk12 = 2;
        } else {
            if (aaD->unk12) {
                aaD->unk12--;
                if (!(aaD->unk12)) {
                    deleteActor(current_actor_pointer);
                }
            }
        }
        if ((aaD->unk0 + D_global_asm_80750344) < D_global_asm_8076A068) {
            deleteActor(current_actor_pointer);
        }
    }
}

void func_global_asm_80695B50(void) {
    AnotherAdditionalActorData *sp1C = current_actor_pointer->AaaD;
    func_global_asm_80695724(0, 1);
    func_global_asm_80612BC0(&current_actor_pointer->unkC, sp1C->unk8);
    renderActor(current_actor_pointer, 1);
}

extern s32 D_global_asm_8071FBC8; // Sprite
extern s32 D_global_asm_8071FC40; // Sprite
extern s16 D_global_asm_80750344;
extern u32 D_global_asm_8076A068;
extern u8 D_global_asm_807FBB85;
extern s32 D_global_asm_80720340; // Sprite
extern s32 D_global_asm_80720804; // TODO: Type
extern f32 D_global_asm_80750274;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} AAD_80695BAC;

void func_global_asm_80695BAC(void) {
    AAD_80695BAC *aaD;
    s32 i;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkFA = 0x270F;
        current_actor_pointer->unk6E[0] = -2;
        current_actor_pointer->unk6A &= ~1;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 110.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 100.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714C08(&D_global_asm_80720804, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
        if (aaD->unk13 != 0xA) {
            func_global_asm_80714998(2);
            func_global_asm_807149B8(1);
            drawSpriteAtPosition(&D_global_asm_8071FBC8, 1.5f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        }
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 4.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xE, 0xE, 1, 0x96, 0x78, 0, 1.0f);
    if (current_actor_pointer->unk6A & 4) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_8071498C(func_global_asm_807189BC);
        func_global_asm_80714950(current_actor_pointer);
        drawSpriteAtPosition(&D_global_asm_8071FC40, 0.3f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    }
    if (((current_actor_pointer->unkFC != 0) && ((D_global_asm_8076A068 - aaD->unk0) >= 6)) || (D_global_asm_807FBB85 != 0)) {
        if ((D_global_asm_807FBB85 != 0) && (aaD->unk13 != 0xA)) {
            func_global_asm_807149B8(1);
            func_global_asm_80714950(0x100D2);
            func_global_asm_8071498C(func_global_asm_8071A8B0);
            drawSpriteAtPosition(&D_global_asm_80720120, 2.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
            func_global_asm_8061EF4C(player_pointer->PaaD->unk104, 7, 0x16, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
            func_global_asm_806915B0();
            for (i = 0; i != 0xC; i += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(i + 0x0B000000);
                func_global_asm_8071498C(func_global_asm_8071ABDC);
                drawSpriteAtPosition(&D_global_asm_807206DC, 0.35f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
        if (aaD->unk13 != 0xA) {
            playSoundAtActorPosition(current_actor_pointer, 0x3C, 0xFF, 0x7F, 0x1E);
        }
        deleteActor(current_actor_pointer);
    }
    if ((aaD->unk0 + D_global_asm_80750344) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

typedef struct {
    s32 unk0;
} AAD_806960A4;

void func_global_asm_806960A4(void) {
    AAD_806960A4 *sp74;
    f32 randomXOffset;
    f32 randomYOffset;
    f32 randomZOffset;
    s32 i;

    sp74 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkFA = 0x270F;
        current_actor_pointer->unk6E[0] = -2;
        current_actor_pointer->unk6A &= ~1;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.2831855f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x1C;
        func_global_asm_8066EB40(current_actor_pointer, 110.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 100.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714C08(&D_global_asm_80720804, current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        sp74->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 4.0f);
    current_actor_pointer->y_velocity += D_global_asm_80750274;
    if (current_actor_pointer->y_velocity < D_global_asm_807502D0) {
        current_actor_pointer->y_velocity = D_global_asm_807502D0;
    }
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xE, 0xE, 1, 0x96, 0x78, 0, 1.0f);
    if ((current_actor_pointer->unk6A & 1) || ((current_actor_pointer->unkFC != 0) && ((D_global_asm_8076A068 - sp74->unk0) >= 6)) || (D_global_asm_807FBB85 != 0)) {
        for (i = 0; i != 0x10; i += 2) {
            randomXOffset = (((rand() >> 0xF) % 8191) / 200.0) - 20.0;
            randomYOffset = (((rand() >> 0xF) % 8191) / 200.0) - 20.0;
            randomZOffset = (((rand() >> 0xF) % 8191) / 200.0) - 20.0;
            func_global_asm_8071496C(i);
            func_global_asm_807149B8(1);
            if (i == 0) {
                func_global_asm_80714950(0x1006E);
                func_global_asm_8071498C(func_global_asm_8071A8B0);
            } else {
                func_global_asm_8071498C(func_global_asm_80717D4C);
                func_global_asm_80714950(-0x96 - ((rand() >> 0xF) % 50));
            }
            drawSpriteAtPosition(&D_global_asm_80720340, 1.6f, current_actor_pointer->x_position + randomXOffset, current_actor_pointer->y_position + randomYOffset, current_actor_pointer->z_position + randomZOffset);
        }
        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0x14, 0xF);
        playSoundAtActorPosition(current_actor_pointer, 0x3C, 0xFF, 0x7F, 0x1E);
        deleteActor(current_actor_pointer);
    }
    if ((sp74->unk0 + D_global_asm_80750344) < D_global_asm_8076A068) {
        deleteActor(current_actor_pointer);
    }
}

// extremely close, float regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_global_asm_80696574.s")

extern s16 D_global_asm_807502D0;
extern f32 D_global_asm_807502F8;

typedef struct {
    u8 unk0[0x88 - 0x0];
    Actor *unk88; // Used
    u8 unk8C[0x104 - 0x8C];
    s32 unk104; // Used
} AAD_807FBB70_1FC;

typedef struct {
    s32 unk0; // Used
} AAD_80696574;

/*
void func_global_asm_80696574(void) {
    AAD_807FBB70_1FC *aaD1FC;
    s16 i;
    u8 sp79;
    u8 sp78;
    u8 sp77;
    u8 unk76;
    u8 unk75;
    u8 unk74;
    u8 unk73;
    u8 unk72;
    u8 unk71;
    u8 sp70;
    u8 unk6F;
    u8 unk6E;
    u8 unk6D;
    u8 sp6C;
    s32 bitmask;
    AAD_80696574 *aaD;

    aaD = ((AAD_80696574*)current_actor_pointer->additional_actor_data);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        bitmask = 0x80000;
        current_actor_pointer->unkA0 = \
        current_actor_pointer->unk9C = current_actor_pointer->y_position;
        if (D_global_asm_807FBB64 & bitmask) {
            current_actor_pointer->noclip_byte = 0x3C;
        } else {
            current_actor_pointer->noclip_byte = 0x1C;
        }
        aaD->unk0 = D_global_asm_8076A068;
        current_actor_pointer->object_properties_bitfield |= bitmask;
        func_global_asm_80666290(current_actor_pointer, &sp79, &sp70, &sp78, &sp6C, sp77);
        current_actor_pointer->y_acceleration = D_global_asm_807502F8 - (((rand() >> 0xF) % 32767) % 10);
        current_actor_pointer->unk6A &= 0xFFFE;
    }
    if (D_global_asm_807FBB70.unk200 == 5) {
        aaD1FC = D_global_asm_807FBB70.unk1FC->additional_actor_data;
        if ((aaD1FC->unk88 != NULL) && (((aaD1FC->unk88->unk58 == 0x1D)) || (aaD1FC->unk88->unk58 == 0x50))) {
            func_global_asm_8061F0B0(aaD1FC->unk104, 0xA, 0x14);
            setAction(0x34, current_actor_pointer, 0);
            func_global_asm_80685B44(&D_global_asm_8071FFA0, 0, 1.0f, 4, 0x14, 0x96, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            deleteActor(current_actor_pointer);
        }
    } else {
        for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
            if (D_global_asm_807FBB70.unk258[i] == 1) {
                current_actor_pointer->control_state = 1;
            }
        }
        if (current_actor_pointer->control_state == 1) {
            func_global_asm_80666280(1);
            func_global_asm_8067ACB4(current_actor_pointer);
            func_global_asm_806651FC(current_actor_pointer);
            func_global_asm_80665564(current_actor_pointer, ((func_global_asm_80612790(current_actor_pointer->z_rotation + 0x800) * 0.5) + 0.5) * 15.0);
            if ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1)) {
                if (current_actor_pointer->control_state_progress < 2) {
                    current_actor_pointer->control_state_progress++;
                    current_actor_pointer->y_velocity = (current_actor_pointer->unkA0 - current_actor_pointer->y_position) * 1.5;
                    func_global_asm_8061F0B0(extra_player_info_pointer->unk104, 0xA, 0x14);
                    playSoundAtActorPosition(current_actor_pointer, 0x1C1, 0xFF, 0x7F, 0x1E);
                    func_global_asm_80685B44(&D_global_asm_8071FFA0, 0, 1.0f, 4, 0x14, 0x96, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                }
            }
            if (!(current_actor_pointer->unk6A & 1)) {
                current_actor_pointer->z_rotation -= ABS(current_actor_pointer->y_velocity * 0.5);
            }
            current_actor_pointer->y_velocity += current_actor_pointer->y_acceleration;
            if (current_actor_pointer->y_velocity < D_global_asm_807502D0) {
                current_actor_pointer->y_velocity = D_global_asm_807502D0;
            }
        }
        func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, (s16)(current_actor_pointer->animation_state->scale[1] * 300.0f), (s16)(current_actor_pointer->animation_state->scale[1] * 300.0f), 1, 0x96, 0x96, 0, 1.0f);
    }
    renderActor(current_actor_pointer, 0);
}
*/

typedef struct {
    s32 unk0; // Used
    s32 unk4;
    f32 unk8; // Used
    s32 unkC;
    u8 unk10; // Used
    u8 unk11; // Used
    u8 unk12;
    u8 unk13;
    s32 unk14;
    s16 unk18; // Used
} AAD_80696A6C;

void func_global_asm_80696A6C(void) {
    AAD_80696A6C *sp44;
    s16 temp_v0;
    s16 var_a3;
    Actor *temp;
    s32 temp2;

    sp44 = current_actor_pointer->additional_actor_data;
    func_global_asm_80695724(15.0f, 0);
    if (current_map == MAP_GALLEON_PUFFTOSS) {
        if (current_actor_pointer->y_position < current_actor_pointer->unkAC) {
            current_actor_pointer->y_position = current_actor_pointer->unkAC;
            current_actor_pointer->y_velocity = current_actor_pointer->y_acceleration;
        }
    }
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x64, 0x64, 1, 0x4B, 0x78, 0, 1.0f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        sp44->unk18 = current_actor_pointer->unkB8;
        current_actor_pointer->draw_distance = 0x3E8;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        sp44->unk0 += 0x78;
        if (current_actor_pointer->unk6E[0] == -1) {
            func_global_asm_80604CBC(current_actor_pointer, 0x114, 0x1E, 1, 0, 0xFF, 1.0f, 0);
            D_global_asm_80770B68[D_global_asm_80770628[current_actor_pointer->unk6E[0]]] = 0.75f;
            D_global_asm_80770BC0[D_global_asm_80770628[current_actor_pointer->unk6E[0]]] = 1.0f;
        }
        sp44->unk10 = 0xF;
        sp44->unk11 = 0;
        func_global_asm_807248B0(current_actor_pointer, current_actor_pointer->unk124->unkC * 0.15);
    }
    sp44->unk11++;
    if (sp44->unk10 < (sp44->unk11)) {
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x15B, 0xFF, 0x6E, 0, 0x1E, 0.3f, 0);
        temp2 = sp44->unk10;
        sp44->unk11 = 0;
        if (temp2 >= 3) {
            sp44->unk10--;
        }
    }
    if ((sp44->unk0 - 0x64) < D_global_asm_8076A068) {
        current_actor_pointer->object_properties_bitfield &= 0xFFF7FFFF;
    }
    if (((sp44->unk0 + D_global_asm_80750344) < D_global_asm_8076A068) || ((current_actor_pointer->unkFD != 0) && (current_actor_pointer->unk58 != ACTOR_PUFFTUP)) || (D_global_asm_807FBB85 != 0)) {
        func_global_asm_8067E278(0, 1);
        func_global_asm_80605314(current_actor_pointer, 0);
        deleteActor(current_actor_pointer);
        temp = current_actor_pointer->unk11C;
        if ((temp != NULL) && (temp->unk58 == ACTOR_BOSS_ARMY_DILLO) && (temp->control_state != 0x37)) {
            current_actor_pointer->unk11C->control_state_progress++;
        }
    }
    temp_v0 = func_global_asm_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
    if (temp_v0 < current_actor_pointer->y_rotation) {
        var_a3 = current_actor_pointer->y_rotation - temp_v0;
    } else {
        var_a3 = temp_v0 - current_actor_pointer->y_rotation;
    }
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, temp_v0, 10.0f);
    switch (current_actor_pointer->control_state) {
        case 0:
            if (var_a3 >= 0x3E9) {
                current_actor_pointer->control_state = 1;
                current_actor_pointer->control_state_progress = 0;
            }
            // fallthrough
        case 2:
            if ((current_actor_pointer->control_state == 2) && (current_actor_pointer->unkB8 > 100.0f)) {
                current_actor_pointer->control_state = 0;
            }
            current_actor_pointer->unkB8 = MIN(current_actor_pointer->unkB8 + 20.0f, sp44->unk18);
            current_actor_pointer->unkEE = func_global_asm_806CC190(current_actor_pointer->unkEE, current_actor_pointer->y_rotation, 1.0f);
            current_actor_pointer->unkF0 = func_global_asm_806CC190(current_actor_pointer->unkF0, (func_global_asm_80665E94(player_pointer->x_position, player_pointer->y_position + player_pointer->unk15E, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x14) * 2048.0) / 3.1415927410125732, 30.0f);
            current_actor_pointer->y_velocity = func_global_asm_80612794(current_actor_pointer->unkF0) * -current_actor_pointer->unkB8;
            sp44->unk8 = -(func_global_asm_80611BB4(current_actor_pointer->y_velocity, current_actor_pointer->unkB8) * 57.295776f);
            break;
        case 1:
            current_actor_pointer->unkB8 = MAX(current_actor_pointer->unkB8 - 10.0f, 5.0f);
            if (current_actor_pointer->unkB8 <= 5.0f) {
                current_actor_pointer->control_state = 2;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
    }
    if (current_actor_pointer->unk58 == ACTOR_FIRE_UNUSED) {
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(func_global_asm_8071AF30);
        func_global_asm_807149A8(0x3E8);
        func_global_asm_80714950(current_actor_pointer);
        func_global_asm_80714C08(&D_global_asm_80720120, 1.0f, current_actor_pointer, 1, 0);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806970CC(void) {
    s16 temp_v0;
    s16 temp;
    s16 temp2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkFA = 9000;
    }
    func_global_asm_80696A6C();
    if ((current_actor_pointer->unkFC != 0) && (func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->unkEE) == 0)) {
        playSoundAtActorPosition(current_actor_pointer, 0xF5, 0xFF, 0x7F, 0x1E);
        temp_v0 = func_global_asm_80672A70(current_actor_pointer->unkF4, current_actor_pointer->unkF6);
        temp = ((current_actor_pointer->unkEE) + 0x800) & 0xFFF;
        temp2 = (temp_v0 - temp);
        current_actor_pointer->unkEE = temp_v0 + temp2;
    }
}

void func_global_asm_80697184(void) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (temp_a0->interactable & 4) {
            func_global_asm_80679200(temp_a0, current_actor_pointer, 8, 0, 0, 0);
        }
    }
}
