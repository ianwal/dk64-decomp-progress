#include <ultra64.h>
#include "functions.h"

extern u8 D_80750270;
extern s16 D_807502D0;
extern f32 D_807502E4;

extern f64 D_8075A070;
extern f32 D_8075A0B8; // 16.0627460479736328125
extern f64 D_8075A0C0;
extern f64 D_8075A0C8;

extern f32 D_807FC7B0;
extern f32 D_807FC7B4;
extern f32 D_807FC7B8;

void func_8068E9B0(Actor **arg0) {
    f32 sp2C;
    PlayerAdditionalActorData *PaaD = (*arg0)->PaaD;

    func_80671C0C(PaaD->vehicle_actor_pointer, 9, &(*arg0)->x_position, &sp2C, &(*arg0)->z_position);
    if ((*arg0)->y_position < sp2C) {
        (*arg0)->y_position = sp2C;
    }
    (*arg0)->y_rotation = PaaD->vehicle_actor_pointer->y_rotation;
    func_806319C4(*arg0, 0);
}

void func_8068EA38(Actor **arg0) {
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
    func_806319C4(*arg0, 0);
}

void func_8061F2B8(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct8068EB3C_arg4;

s32 func_8068EB3C(f32 arg0, f32 arg1, f32 arg2, Struct8068EB3C_arg4 *arg3, Struct8068EB3C_arg4 *arg4, Struct8068EB3C_arg4 *arg5, Struct8068EB3C_arg4 *arg6, f32 *arg7, f32 *arg8, f32 *arg9) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    func_8061F2B8(arg0, arg1, arg2, arg3->unk0, arg3->unk4, arg3->unk8, arg4->unk0, arg4->unk4, arg4->unk8, &sp48, &sp4C, &sp50);
    func_8061F2B8(arg0, arg1, arg2, arg5->unk0, arg5->unk4, arg5->unk8, arg6->unk0, arg6->unk4, arg6->unk8, &sp54, &sp58, &sp5C);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068ECF4.s")

extern f32 D_80759F70;
extern f32 D_80759F74;
extern f32 D_80759F78;

extern s32 D_80720054; // TODO: Datatype

/*
// TODO: Very close
void func_8068ECF4(s32 arg0, u8 arg1) {
    ActorAnimationState *temp_v0;
    f32 temp_f0;
    f32 temp_f2;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 var_f0;
    f32 var_f2;
    f32 var_f6;
    s16 var_v0;
    u8 temp_t4;

    func_80671C0C(current_actor_pointer, arg0, &sp48, &sp44, &sp40);
    temp_f2 = (s16)(((func_80611BB4(character_change_array->look_at_eye_z - sp40, sp48 - character_change_array->look_at_eye_x) * D_80759F70) + 1024.0f)) & 0xFFF;
    if (current_actor_pointer->y_rotation < temp_f2) {
        var_v0 = temp_f2 - current_actor_pointer->y_rotation;
    } else {
        var_v0 = current_actor_pointer->y_rotation - temp_f2;
    }
    if (var_v0 >= 0x801) {
        var_v0 = 0x1000 - var_v0;
    }
    if (var_v0 < 0x384) {
        temp_f0 = (1024.0f - var_v0) * D_80759F74;
        if (temp_f0 < 1.0f) {
            var_f2 = temp_f0;
        } else {
            var_f2 = 1.0f;
        }
        var_f6 = arg1;
        temp_t4 = (var_f2 * var_f6);
        if (temp_t4 != 0) {
            temp_v0 = current_actor_pointer->animation_state;
            var_f0 = D_80759F78;
            if (temp_v0 != NULL) {
                var_f0 = D_80759F78 * temp_v0->scale_y;
            }
            func_807149C8(0xFF, 0xFF, 0xFF, temp_t4);
            func_80714C08(&D_80720054, var_f0, current_actor_pointer, arg0, 2);
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068EF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068F72C.s")

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

void func_8068FF40(u8 arg0, Struct8068FF40_arg1 *arg1, Struct8068FF40_arg2 *arg2) {
    f32 var_f0;
    f32 var_f2;
    AnimationStateUnk1C *temp_v1;

    temp_v1 = current_actor_pointer->animation_state->unk1C;
    if (arg0) {
        var_f0 = 500.0f;
        var_f2 = 0.0f;
    } else {
        var_f0 = 0.0f;
        var_f2 = arg1->unkC * (400.0 - (D_8075A070 * current_actor_pointer->unkB8));
    }
    arg2->unk2 = func_806CC190(arg2->unk2, var_f0, 5.0f);
    arg2->unk0 = func_806CC190(arg2->unk0, (s32)var_f2 & 0xFFF, 3.0f);
    temp_v1->unk0 = -0x80;
    temp_v1->unk1 = 1;
    temp_v1->unk2 = arg2->unk2 * 0x10;
    temp_v1->unk4 = arg2->unk0 * 0x10;
    temp_v1->unk6 = 0;
    temp_v1[1].unk0 = 0;
}

void func_80690058(Actor *arg0, s32 arg1) {
    arg0->animation_state->unk1C = malloc(arg1 * sizeof(AnimationStateUnk1C));
    func_80611690(arg0->animation_state->unk1C);
}

void func_80690094(Actor *arg0, Actor *arg1) {
    u8 sp37 = 0;
    PlayerAdditionalActorData *PaaD = arg1->PaaD;

    func_806EB0C0(0x4C, arg0, PaaD->unk1A4);
    if (current_map == MAP_GALLEON_PUFFTOSS) {
        sp37 = 0x3C;
    }
    func_80604CBC(arg0, 0x115, sp37, 1, 0, 0xFF, 1.0f, 0);
    func_80604CBC(arg0, 0x116, sp37, 1, 1, 0xFF, 1.0f, 0);
    func_80688370(arg0, 0, 1.0f);
    func_8068842C(arg0, 0, -1);
    func_80690058(arg0, 2);
    func_8067B238(arg0, arg1, 0.15f);
}

u32 func_806119A0();
extern f64 D_8075A078;
extern f64 D_8075A080;
extern f64 D_8075A088;
extern f64 D_8075A090;
extern f64 D_8075A098;
extern f64 D_8075A0A0;
extern f64 D_8075A0A8;
extern f64 D_8075A0B0;
extern s16 D_80770628[];
extern f32 D_80770B68[];
extern f32 D_80770BC0[];

typedef struct {
    f32 unk0;
    f32 unk4; // Used
} Struct80690190;

void func_80690190(Struct80690190 *arg0, s32 arg1) {
    s16 temp_a1;

    temp_a1 = D_80770628[current_actor_pointer->unk6E[0]];
    if (current_actor_pointer->y_position < (current_actor_pointer->unkAC + 4.0f)) {
        D_80770B68[temp_a1] = (current_actor_pointer->unkB8 / D_8075A078) + 1.0;
        D_80770BC0[temp_a1] = 1.0f;
    } else {
        D_80770B68[temp_a1] = arg0->unk4 + D_8075A080;
        D_80770BC0[temp_a1] = 5.0f;
    }
    temp_a1 = D_80770628[current_actor_pointer->unk70];
    if (current_actor_pointer->y_position < (current_actor_pointer->unkAC + 4.0f)) {
        if (D_80770BC0[temp_a1] == 0.0f) {
            D_80770B68[temp_a1] = (((func_806119A0() / D_8075A088) * D_8075A090) + D_8075A098) * (D_8075A0A8 + (current_actor_pointer->unkB8 / D_8075A0A0));
            D_80770BC0[temp_a1] = 1.0f;
        }
    } else {
        D_80770B68[temp_a1] = (arg0->unk4 * 1.5) + D_8075A0B0;
        D_80770BC0[temp_a1] = 8.0f;
    }
}

void func_806903BC(Actor *actor, RaceAdditionalActorData *arg1) {
    ExitData *exit;
    s16 angle;

    exit = getExitData(arg1->unk36);
    actor->x_position = exit->x_pos;
    actor->y_position = exit->y_pos;
    actor->z_position = exit->z_pos;
    angle = exit->angle * D_8075A0B8; // 16.0627460479736328125
    actor->y_rotation = angle;
    actor->unkEE = angle;
    arg1->unk0 = angle;
}

void func_80690470(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;
    RaceAdditionalActorData *RaaD;
    s32 pad;
    Actor *sp18;

    PaaD = arg0->PaaD;
    func_80677FA8(ACTOR_PROPELLER, 0xDA);
    sp18 = D_807FBB44;
    RaaD = sp18->RaaD;
    RaaD->unk28 = PaaD->unk1A4;
    func_80690094(sp18, arg0);
    RaaD->unk35 = 0;
    RaaD->unk27 = 0;
    RaaD->unk0 = arg0->y_rotation;
    PaaD->vehicle_actor_pointer = sp18;
    sp18->object_properties_bitfield &= 0xFFFDFFFF;
}

s32 func_8061C6A8(s32, Actor *, s32, s32, s32, s32, s32, s32, s32, s32, f32);
s32 func_8070033C(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
extern f32 D_80750300;
extern f32 D_8075A0BC;

typedef struct {
    u8 unk0[0x28 - 0x0];
    u8 unk28;
    u8 unk29[0x34 - 0x29];
    u8 unk34;
} AAD_80690500;

typedef struct {
    u8 unk0[0xF3 - 0x0];
    u8 unkF3;
} AAD_80690500_unk104;

typedef struct {
    s32 unk0;
} A178_80690500;

void func_80690500(void) {
    AAD_80690500 *aaD;
    Actor *player;
    PlayerAdditionalActorData *PaaD;
    A178_80690500 *a178;
    AAD_80690500_unk104 *aaD_104;
    u8 sp4B;
    f32 sp44;
    f32 sp40;
    f32 sp3C;

    aaD = current_actor_pointer->additional_actor_data;
    a178 = current_actor_pointer->unk178;
    player = character_change_array[aaD->unk28].player_pointer;
    PaaD = player->PaaD;
    aaD_104 = PaaD->unk104->additional_actor_data;
    sp4B = current_actor_pointer->unk6A & 1;
    aaD->unk34 = 2;
    func_80690190(aaD, a178);
    if (is_cutscene_active == 0) {
        if (aaD_104->unkF3 != 4) {
            func_8061C6A8(PaaD->unk104, current_actor_pointer, 4, 0x800, 0xA0, 0, 6, 0x12C, 0x8F, 0, D_8075A0BC);
        }
    }
    func_8068F72C(aaD, a178, 1, 1);
    func_8068FF40(sp4B, aaD, a178);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->y_acceleration = D_80750300;
        current_actor_pointer->noclip_byte = 0x3C;
        func_806EB0C0(0x4C, current_actor_pointer, PaaD->unk1A4);
    }
    if (func_8061CB50() == 0 || (func_8061CB50() != 0 && player_pointer->unk6A & 0x100)) {
        func_80671C0C(current_actor_pointer, 1, &sp44, &sp40, &sp3C);
        func_8065A708(sp44, sp40, sp3C, 0.0f, 0.0f, 0.0f, 300.0f, 0, 0xFF, 0xFF, 0xFF);
        if (isFlagSet(0x6B, 2) == 0) {
            if (func_8061CB50() != 0) {
                if (player_pointer->unk6A & 0x100) {
                    func_80671C0C(current_actor_pointer, 2, &sp44, &sp40, &sp3C);
                    func_8070033C(sp44, sp40, sp3C, 0.0f, 0.0f, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF);
                }
            }
            if (func_8061CB50() == 0) {
                player_pointer->unk6A &= 0xFEFF;
            }
        }
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806907B8(void) {
    func_806319C4(current_actor_pointer, 0);
}

void func_806907E0(void) {
    D_80750270 = 1;
}

void func_806907F0(f32 arg0, f32 arg1, f32 arg2) {
    D_807FC7B0 = arg0;
    D_807FC7B4 = arg1;
    D_807FC7B8 = arg2;
}

void func_80690814(Actor *arg0, s32 arg1) {
    func_80671C0C(arg0, arg1, &D_807FC7B0, &D_807FC7B4, &D_807FC7B8);
}

void func_8069084C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, f32 arg4, f32 arg5, Actor *arg6) {
    s32 temp;
    s32 temp2;
    f32 sp28[6];

    sp28[0] = (arg3 / D_8075A0C0) * D_8075A0C8;
    sp28[1] = arg4;
    sp28[2] = arg5;
    sp28[3] = arg2;
    sp28[4] = arg1;
    sp28[5] = D_80750270;
    func_806891D8(arg0, D_807FC7B0, D_807FC7B4, D_807FC7B8, 0, arg2, arg6, &sp28);
    D_80750270 = 0;
}

void func_80690930(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, Actor *arg8) {
    f32 sp2C;
    f32 sp28;
    f32 temp_f0_2;
    f32 temp_f14_2;
    f32 temp_f2_2;

    temp_f0_2 = sqrtf(((arg4 - D_807FC7B0) * (arg4 - D_807FC7B0)) + ((arg5 - D_807FC7B4) * (arg5 - D_807FC7B4)) + ((arg6 - D_807FC7B8) * (arg6 - D_807FC7B8)));
    temp_f2_2 = (arg4 - D_807FC7B0);
    sp28 = arg5 - D_807FC7B4;
    sp2C = temp_f0_2;
    func_8069084C(arg1, arg2, arg3, arg0, sqrtf(((arg4 - D_807FC7B0) * (arg4 - D_807FC7B0)) + ((arg6 - D_807FC7B8) * (arg6 - D_807FC7B8))) / (sp2C / arg7), sp28 / (sp2C / arg7), arg8);
}

void func_80690A28(s16 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Actor *arg7) {
    func_80690930(func_80665DE0(arg3, arg5, D_807FC7B0, D_807FC7B8), arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void func_80690AB0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, Actor *arg9) {
    s16 temp_t0;
    s16 temp_t6;
    s16 var_s0;

    var_s0 = func_80665DE0(arg5, arg7, D_807FC7B0, D_807FC7B8);
    if (arg1 < func_806CC14C(arg0, var_s0)) {
        temp_t0 = (arg0 - arg1) & 0xFFF;
        temp_t6 = (arg0 + arg1) & 0xFFF;
        if (func_806CC14C(var_s0, temp_t0) < func_806CC14C(var_s0, temp_t6)) {
            var_s0 = temp_t0;
        } else {
            var_s0 = temp_t6;
        }
    }
    func_80690930(var_s0, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

void func_80690BE8(s16 arg0, s16 arg1, f32 arg2, Actor *arg3, s32 arg4, f32 arg5, Actor *arg6) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    func_80671C0C(arg3, arg4, &sp34, &sp30, &sp2C);
    func_80690A28(arg0, arg1, arg2, sp34, sp30, sp2C, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690F30.s")

extern s32 D_8071FFA0;
extern u8 D_80750AD0;

void func_806915B0(void) {
    f32 randomZ;
    f32 randomY;
    f32 randomX;
    s32 i;
    s32 max;

    if (D_80750AD0 != 0) {
        max = 3;
    } else {
        max = 6;
    }
    for (i = 0; i < max; i++) {
        randomX = ((((func_806119A0()) / 10000) % 200) / 5.0) - 20.0;
        randomY = ((((func_806119A0()) / 10000) % 200) / 5.0) - 20.0;
        randomZ = ((((func_806119A0()) / 10000) % 200) / 5.0) - 20.0;
        func_807149B8(1);
        func_807149C8(0x8C, 0x8C, 0x8C, 0x64);
        func_80714950(i * -0x14);
        func_80714998(3);
        func_8071498C(func_80717D4C);
        func_80714CC0(
            &D_8071FFA0,
            2.0f,
            current_actor_pointer->x_position +         randomX,
            current_actor_pointer->y_position + 42.0f + randomY,
            current_actor_pointer->z_position +         randomZ
        );
    }
}

void func_80661520(f32, f32, f32, f32, f32, f32);

void func_80691830(s16 arg0, f32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    func_80677FA8(ACTOR_BOSS_SHOCKWAVE, arg0); // Spawn actor: Shockwave (boss)
    func_8067B238(D_807FBB44, current_actor_pointer, arg1);
    D_807FBB44->unkF0 = arg0;
    D_807FBB44->unk16A = arg2;
    D_807FBB44->unk16B = arg3;
    D_807FBB44->unk16C = arg4;
    D_807FBB44->unk15F = arg5;
    D_807FBB44->unk168 = 1;
    D_807FBB44->unk160 = arg6;
    if (arg7 != 0.0f) {
        func_80661520(current_actor_pointer->x_position, current_actor_pointer->z_position, arg7, 2.0f, arg8, arg9);
    }
    func_8061F0B0(D_807F5D10, 0x50, 0x14);
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

void func_80691930(u8 arg0, u8 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5) {
    TempAAD2 *temp_v0;

    func_80677FA8(ACTOR_BOSS_DOGADON_SHOCKWAVE, 0);
    func_8067B238(D_807FBB44, current_actor_pointer, 0.15f);
    temp_v0 = D_807FBB44->additional_actor_data;
    temp_v0->unk11 = arg0;
    temp_v0->unk8 = arg2;
    temp_v0->unkC = arg3;
    temp_v0->unk0 = arg1;
    D_807FBB44->y_position = current_actor_pointer->unkA8;
    D_807FBB44->unk15F = arg4;
    D_807FBB44->unk168 = arg5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806919E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806921DC.s")

void func_80692500(void) {
    func_806921DC(0);
}

void func_80692520(void) {
    func_806921DC(1);
}

// TODO: What datatype is this?
extern s32 D_807201D4;

void func_80692540(void) {
    func_806919E0(&D_807201D4);
}

void func_80692564(void) {
    func_806919E0(&D_807201D4);
}

void func_80692588(void) {
    func_806919E0(&D_807201D4);
}

void func_806925AC(void) {
    AnotherAdditionalActorData *sp1C;

    sp1C = current_actor_pointer->AaaD;
    func_806919E0(&D_807201D4);
    if (sp1C->unk13 == 1) {
        current_actor_pointer->y_velocity += D_807502E4;
        if (current_actor_pointer->y_velocity < D_807502D0) {
            current_actor_pointer->y_velocity = D_807502D0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80692640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80692940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80692E50.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8069329C.s")

void func_8061EF4C(Actor*, s32, s32, f32, f32, f32, f32, f32);

int func_8071ABDC();
extern s32 D_807200EC; // TODO: Datatype
extern s32 D_80720120; // TODO: Datatype
extern u8 D_80750AD0;
extern f32 D_8075A14C;

/*
void func_8069329C(void) {
    f32 temp_f20;
    s32 i;

    func_807149B8(1);
    func_80714950(0x1006E);
    func_8071498C(&func_8071A8B0);
    func_80714CC0(&D_80720120, 2.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 22.0f, current_actor_pointer->z_position);
    for (i = 0; i < cc_number_of_players; i++) {
        func_8061EF4C(character_change_array[i].player_pointer->PaaD->unk104, 7, 0x16, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
    }
    func_806915B0();
    if (D_80750AD0 == 0) {
        temp_f20 = D_8075A14C;
        for (i = 0; i < 0xC; i++) {
            func_807149B8(1);
            func_80714950(i + 0x0B010000);
            func_8071498C(&func_8071ABDC);
            func_80714CC0(&D_807200EC, temp_f20, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        }
    }
    func_80608528(current_actor_pointer, 0xF6, 0xFF, 0x7F, 0x1E);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8069346C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80693EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806944BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80694948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80694D20.s")

s32 func_806951B0(Actor *arg0) {
    if (arg0->unk58 != ACTOR_PROJECTILE_FEATHER) {
        return TRUE;
    }
    if (arg0->control_state == 0) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806951E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80695724.s")

void func_80695724(f32, s32);
void func_80695B50() {
    AnotherAdditionalActorData *sp1C = current_actor_pointer->AaaD;
    func_80695724(0, 1);
    func_80612BC0(&current_actor_pointer->unkC, sp1C->unk8);
    func_806319C4(current_actor_pointer, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80695BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806960A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80696574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80696A6C.s")

void func_806970CC(void) {
    s16 temp_v0;
    s16 temp;
    s16 temp2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkFA = 9000;
    }
    func_80696A6C();
    if ((current_actor_pointer->unkFC != 0) && (func_806725A0(current_actor_pointer, current_actor_pointer->unkEE) == 0)) {
        func_80608528(current_actor_pointer, 0xF5, 0xFF, 0x7F, 0x1E);
        temp_v0 = func_80672A70(current_actor_pointer->unkF4, current_actor_pointer->unkF6);
        temp = ((current_actor_pointer->unkEE) + 0x800) & 0xFFF;
        temp2 = (temp_v0 - temp);
        current_actor_pointer->unkEE = temp_v0 + temp2;
    }
}

void func_80697184(void) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_807FBB34; i++) {
        temp_a0 = D_807FB930[i].unk0;
        if (temp_a0->interactable & 4) {
            func_80679200(temp_a0, current_actor_pointer, 8, 0, 0, 0);
        }
    }
}
