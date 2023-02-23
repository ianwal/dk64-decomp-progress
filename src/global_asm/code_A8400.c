#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80720A10;
extern s32 D_807209EC;
extern s32 D_807207E0;
extern s32 D_80720A34;
extern s32 D_80720A58;

extern s32 D_807204BC;
extern s32 D_80720508;
extern s32 D_807205C4;
extern s32 D_807205E8;
extern s32 D_80720768;
extern s32 *D_807207BC;
extern s32 D_807211D0;
extern s32 D_80721378;
extern f32 D_8075A9B0;
extern f32 D_8075A9B4;

extern s32 D_80720710;

extern s32 D_80720FE0;
extern s32 D_80720F98;
extern s32 D_80720FBC;
extern s32 D_80721028;
extern s32 D_80721004;
extern f32 D_8075AA70;
extern f32 D_8075AA74;

void func_80686A5C(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
void func_80665564(Actor *arg0, f32 arg1);
void func_806A6DB4(s32 arg0);
void func_806086CC(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, s32 arg9);
void func_8065D254(Actor *actor, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, f32 arg10);
void func_80686CF8(Actor *actor);
void func_806319C4(Actor *arg0, s32 arg1);

void func_806A664C(f32 arg0);
void func_80714A08(f32 arg0, f32 arg1);
void func_806A5EAC(s32 *arg0, s32 *arg1, f32 arg2);

void func_806A3700(s32 arg0, s32 arg1) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A370C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A3E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A4284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A495C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A4B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A4DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A57C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A5EAC.s")

/*
// TODO: Which aaD is arg0?
void func_806A5EAC(void *arg0, s32 arg1, f32 arg2) {
    f32 phi_f12;

    phi_f12 = arg2;
    if (D_807FBB68 & 0x10) {
        phi_f12 = 2.0f * arg2;
    }
    arg2 = phi_f12;
    func_807149FC(phi_f12, -1);
    func_807149B8(1);
    func_80714998(2);
    arg0->unk4 = func_80714C08(arg2, arg1, arg2 * D_8075A9A8, current_actor_pointer, 1, 2);
}
*/

void func_806A5F44(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806A5EAC(sp1C, &D_80720710, 1.0f);
    }
}

void func_806A5FA4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806A5EAC(sp1C, &D_80720508, 1.0f);
    }
}

void func_806A6004(void *arg0, s32 arg1) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (arg1 != player_pointer->unk58) {
            func_807149C8(0xFF, 0xFF, 0xFF, 0x64);
        }
        func_806A5EAC(sp1C, arg0, 1.0f);
    }
}

void func_806A6094(void) {
    func_806A6004(&D_807209EC, 3);
}

void func_806A60BC(void) {
    func_806A6004(&D_80720A10, 6);
}

void func_806A60E4(void) {
    func_806A6004(&D_807207E0, 4);
}

void func_806A610C(void) {
    func_806A6004(&D_80720A34, 2);
}

void func_806A6134(void) {
    func_806A6004(&D_80720A58, 5);
}

void func_806A615C(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_80714A08(D_8075A9B0, D_8075A9B4);
        func_806A5EAC(sp1C, &D_80720768, 1.0f);
    }
}

void func_806A61D0(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_807204BC, 1.0f);
    }
}

void func_806A6230(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    s32 temp_v1;

    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        temp_v1 = D_807FBB64; // shadow_display_bitfield, shockwave_bitfield, long_distance_actor_spawn
        if (((temp_v1 << 0xC) < 0) || (temp_v1 & 0x2000)) {
            current_actor_pointer->unk15F = 1;
        }
        func_806A5EAC(sp1C, &D_807207BC, 1.0f);
    }
}

void func_806A62B4(void) {
    func_806A6230();
}

void func_806A62D4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_807149C8(0xFF, 0xFF, 0, 0xFF);
        func_806A5EAC(sp1C, &D_807211D0, 1.5f);
    }
}

void func_806A6348(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_807205C4, 1.0f);
    }
}

void func_806A63A8(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_807205E8, 1.0f);
    }
}

void func_806A6408(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_806A664C(12.0f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_806A5EAC(sp1C, &D_80721378, 2.0f);
    }
}

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A6468.s")

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A6574.s")

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A664C.s")

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A6DB4.s")

void func_806A734C(void) {
    func_806A6DB4(1);
}

void func_806A736C(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_80686CF8(current_actor_pointer);
    }
    // TODO: Get rid of typecasts
    if ((u16)PaaD->unk8 == 1) {
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x73, 0xFF, 0x7F, 1, 0, 0.0f, 0);
        playSong(0x3B, 0.7f);
    } else if ((u16)PaaD->unk8 == 0xA) {
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x19C, 0xB4, 0x7F, 1, 0, 0.0f, 0);
    }
    func_806A6DB4(0);
    if (current_actor_pointer->y_position < current_actor_pointer->unkAC) {
        current_actor_pointer->unkB8 = 0.0f;
        current_actor_pointer->y_position = current_actor_pointer->unkAC;
        current_actor_pointer->y_velocity = current_actor_pointer->y_acceleration;
    }
    func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x96, 0x78, 0, 1.0f);
}

void func_806A7518(void) {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_80686A5C(current_actor_pointer, 20.0f, 40.0f, 0x1E);
        current_actor_pointer->floor = D_8075AA70;
        func_80665564(current_actor_pointer, 0.0f);
    }
    func_806A6DB4(0);
    if (D_8075AA74 != current_actor_pointer->floor) {
        func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x19, 0x19, 1, 0x96, 0x78, 0, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A7600.s")

void func_806A7B04(void) {
    func_806A7600(&D_80720FBC);
}

void func_806A7B28(void) {
    func_806A7600(&D_80720F98);
}

void func_806A7B4C(void) {
    func_806A7600(&D_80721028);
}

void func_806A7B70(void) {
    func_806A7600(&D_80721004);
}

void func_806A7B94(void) {
    func_806A7600(&D_80720FE0);
}

void func_806A7BB8(void) {
    func_806A7600(&D_80721004);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A7BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_806A7EF0.s")

void func_806A8070(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x40000000;
    }
    func_806319C4(current_actor_pointer, 0);
}
