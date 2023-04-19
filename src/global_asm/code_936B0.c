#include <ultra64.h>
#include "functions.h"


extern u8 D_80750270;
extern s16 D_807502D0;
extern f32 D_807502E4;
extern f32 D_8075A0B8; // 16.0627460479736328125

extern f32 D_807FC7B0;
extern f32 D_807FC7B4;
extern f32 D_807FC7B8;

void func_80604CBC(s32, s32, u8, s32, s32, s32, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068E9B0.s")

/*
void func_8068E9B0(Actor *arg0) {
    f32 sp2C;
    Actor *vehicle;

    vehicle = arg0->PaaD->vehicle_actor_pointer;
    func_80671C0C(vehicle, 9, arg0->x_position, &sp2C, arg0->z_position);
    if (arg0->y_position < sp2C) {
        arg0->y_position = sp2C;
    }
    arg0->y_rotation = vehicle->y_rotation;
    func_806319C4(arg0, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068EA38.s")

/*
// TODO: Regalloc
void func_8068EA38(Actor **arg0) {
    PlayerAdditionalActorData *PaaD;
    Actor *vehicle;

    PaaD = (*arg0)->PaaD;
    vehicle = (*arg0)->PaaD->vehicle_actor_pointer;
    if (vehicle) {
        if (vehicle->RaaD->unk34 < 5) {
            (*arg0)->x_position = vehicle->x_position;
            (*arg0)->y_position = PaaD->vehicle_actor_pointer->y_position;
            (*arg0)->z_position = PaaD->vehicle_actor_pointer->z_position;
            (*arg0)->y_rotation = PaaD->vehicle_actor_pointer->y_rotation;
            (*arg0)->z_rotation = PaaD->vehicle_actor_pointer->z_rotation;
            (*arg0)->x_rotation = PaaD->vehicle_actor_pointer->x_rotation;
            (*arg0)->unkAC = PaaD->vehicle_actor_pointer->unkAC;
            if (PaaD->vehicle_actor_pointer->unk58 == 0x12E) {
                (*arg0)->unkB8 = vehicle->unkB8 * 10.0f;
            } else {
                (*arg0)->unkB8 = vehicle->unkB8;
            }
        } else {
            (*arg0)->unkB8 = 0.0f;
        }
    }
    func_806319C4(*arg0, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068EB3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068ECF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068EF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068F72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8068FF40.s")

void func_80690058(Actor *arg0, s32 arg1) {
    arg0->animation_state->unk1C = malloc(arg1 * 8);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690190.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690470.s")

/*
// TODO: Not sure what I'm missing here... hmm
void func_80690470(Actor *arg0) {
    Actor *sp18;
    RaceAdditionalActorData *RaaD;
    PlayerAdditionalActorData *PaaD;

    PaaD = arg0->PaaD;
    func_80677FA8(0x13F, 0xDA); // Spawn actor 319, propeller (boat)
    RaaD = D_807FBB44->RaaD;
    RaaD->unk28 = PaaD->unk1A4;
    func_80690094(D_807FBB44, arg0);
    RaaD->unk35 = 0;
    RaaD->unk27 = 0;
    RaaD->unk0 = arg0->y_rotation;
    PaaD->vehicle_actor_pointer = D_807FBB44;
    D_807FBB44->object_properties_bitfield &= 0xFFFDFFFF;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690500.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8069084C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690A28.s")

/*
extern f32 D_807FC7B0;
extern f32 D_807FC7B8;

void func_80690930(s32, s16, s16, s32, f32, f32, f32, f32, f32);

void func_80690A28(s16 arg0, s16 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    func_80690930(func_80665DE0(arg3, arg5, D_807FC7B0, D_807FC7B8), arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690AB0.s")

//typematching this accurately might be a nightmare
void func_80690A28(s16,s16,s32,s32,f32,f32,f32,s32);
void func_80690BE8(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6) {
    s32 sp34;
    f32 sp30;
    f32 sp2C;

    func_80671C0C(arg3, arg4, &sp34, &sp30, &sp2C);
    func_80690A28(arg0, arg1, arg2, sp34, sp30, sp2C, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_80690F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806915B0.s")

extern s32 D_807F5D10;

void func_80661520(f32, f32, f32, f32, f32, f32);

void func_80691830(s16 arg0, f32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    func_80677FA8(0x102, arg0); // Spawn actor: Shockwave (boss)
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

    func_80677FA8(0x107, 0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_8069329C.s")

void func_8061EF4C(Actor*, s32, s32, f32, f32, f32, f32, f32);

extern s32 D_8071A8B0; // TODO: Datatype
extern s32 D_8071ABDC; // TODO: Datatype
extern s32 D_807200EC; // TODO: Datatype
extern s32 D_80720120; // TODO: Datatype
extern u8 D_80750AD0;
extern f32 D_8075A14C;

/*
// TODO: Close, regalloc and something going wrong in the bottom loop
void func_8069329C(void) {
    f32 temp_f20;
    s32 phi_s0;

    func_807149B8(1);
    func_80714950(0x1006E);
    func_8071498C(&D_8071A8B0);
    func_80714CC0(&D_80720120, 2.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 22.0f, current_actor_pointer->z_position);
    for (phi_s0 = 0; phi_s0 < cc_number_of_players; phi_s0++) {
        func_8061EF4C(character_change_array[phi_s0].player_pointer->PaaD->unk104, 7, 0x16, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
    }
    func_806915B0();
    if (D_80750AD0 == 0) {
        temp_f20 = D_8075A14C;
        for (phi_s0 = 0; phi_s0 < 0xC; phi_s0++) {
            func_807149B8(1);
            func_80714950(phi_s0 + 0x0B010000);
            func_8071498C(&D_8071ABDC);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_936B0/func_806970CC.s")

/*
// TODO: Regalloc at the end :(
void func_806970CC(void) {
    s32 temp_v0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkFA = 9000;
    }
    func_80696A6C();
    if ((current_actor_pointer->unkFC != 0) && (func_806725A0(current_actor_pointer, current_actor_pointer->unkEE) == 0)) {
        func_80608528(current_actor_pointer, 0xF5, 0xFF, 0x7F, 0x1E);
        temp_v0 = func_80672A70(current_actor_pointer->unkF4, current_actor_pointer->unkF6, current_actor_pointer);
        current_actor_pointer->unkEE = temp_v0 + (temp_v0 - ((current_actor_pointer->unkEE + 0x800) & 0xFFF));
    }
}
*/

extern u16 D_807FBB34;

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
