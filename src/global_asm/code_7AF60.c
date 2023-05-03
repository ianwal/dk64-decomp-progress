#include <ultra64.h>
#include "functions.h"


s32 func_806D0DE4(Actor *arg0, Actor *arg1);
u8 func_806767E0(s32, s32, s32);
u8 func_80676CB0(s32, s32);

extern u8 D_807F6902;
extern f64 D_807591E0;

void func_80676260(Actor *arg0, Actor *arg1, s32 arg2) {
    func_806D0DE4(arg0, arg1);
}

u8 func_80676280(Actor *arg0, s32 arg1, s32 arg2) {
    return func_806D10D0(arg1) && D_807F6902 == 0;
}

u8 func_806762C0(s32 arg0, s32 arg1, s32 arg2) {
    return func_806767E0(arg0, arg1, arg2) && func_80676280(arg0, arg1, arg2);
}

u8 func_80676308(Actor *arg0, Actor *arg1, s32 arg2) {
    s16 diff = arg0->health - arg1->unk136;
    if (diff <= 0) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676338.s")

// TODO: Not exactly sure what's wrong here
// Tricky floating point typecasty stuff I suspect


s32 func_8067641C(Actor*, Actor*, s32);

/*
s32 func_80676338(Actor *arg0, Actor *arg1, s32 arg2) {
    u8 temp = func_806CC14C(func_80665DE0(arg0->x_position, arg0->z_position, arg1->x_position, arg1->z_position), arg0->y_rotation) < 0x200;
    return temp
        && func_8067641C(arg0, arg1, arg2);
}
*/

// TODO: Similar layout as above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_8067641C.s")

u8 func_806764D8(Actor *arg0, Actor *arg1, s32 arg2) {
    return D_807591E0 < func_80665E94(arg0->x_position, arg0->y_position, arg0->z_position, arg1->x_position, arg1->y_position, arg1->z_position, 0);
}

u8 func_80676540(s32 arg0, Actor *arg1, Actor *arg2) {
    return func_806764D8(arg0, arg1, arg2) && arg1->y_velocity < -100.0f;
}

u8 func_80676590(Actor *arg0, Actor *arg1, s32 arg2) {
    return arg0->distance_from_floor < 10.0f && arg0->y_position < arg1->y_position;
}

u8 func_806765E8(Actor *arg0, Actor *arg1, s32 arg2) {
    f32 position[3];

    if (arg0->unkCC) {
        func_80671C0C(arg0, arg0->unkCC, &position[2], &position[1], &position[0]);
    } else {
        position[2] = arg0->x_position;
        position[1] = arg0->y_position;
        position[0] = arg0->z_position;
    }

    return arg1->distance_from_floor < 10.f && arg1->y_position < position[1];
}

u8 func_80676690(s32 arg0, s32 arg1, s32 arg2) {
    return func_80676CB0(arg2, 1) && func_8067641C(arg0, arg1, arg2);
}

u8 func_806766E0(s32 arg0, s32 arg1, s32 arg2) {
    return func_80676CB0(arg2, 2) && func_8067641C(arg0, arg1, arg2);
}

void func_80676730(s32 arg0, s32 arg1, s32 arg2) {
    func_80676CB0(arg2, 1);
}

void func_8067675C(s32 arg0, s32 arg1, s32 arg2) {
    func_80676CB0(arg2, 3);
}

void func_80676788(s32 arg0, s32 arg1, s32 arg2) {
    func_80676CB0(arg2, 5);
}

void func_806767B4(s32 arg0, s32 arg1, s32 arg2) {
    func_80676CB0(arg2, 4);
}

u8 func_806767E0(s32 arg0, s32 arg1, s32 arg2) {
    return func_80676CB0(arg2, 2);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_8067680C.s")

// CharacterChange and ActorAdditionalData struct usages
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_806769A8.s")

/*
// TODO: beql and bnel instead of bne and beq
// Returning the conditional doesn't work
int func_806769A8(s32 arg0, Actor *arg1, s32 arg2) {
    if ((arg1->unk58 == ACTOR_CHUNKY) && (character_change_array[arg1->PaaD->unk1A4].unk2C0 != 1)) {
        return TRUE;
    }
    return FALSE;
}
*/

// CharacterChange and ActorAdditionalData struct usages
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676A0C.s")

/*
// TODO: beql and bnel instead of bne and beq
// Returning the conditional doesn't work
int func_80676A0C(s32 arg0, Actor *arg1, s32 arg2) {
    if ((arg1->unk58 == 5) && (character_change_array[arg1->PaaD->unk1A4].unk2C0 != 1)) {
        return TRUE;
    }
    return FALSE;
}
*/

u8 func_80676A70(s32 arg0, s32 arg1, s32 arg2) {
    return func_806769A8(arg0, arg1, arg2) && func_8067680C(arg0, arg1, arg2);
}

// CharacterChange and ActorAdditionalData struct usages
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676AB8.s")

u8 func_80676B38(Actor *arg0, void *arg1, s32 arg2) {
    // Actor->isGrounded?
    return func_80676AB8(arg0, arg1, arg2) && arg0->unk6A & 1;
}

u8 func_80676B70(Actor *arg0, void *arg1, s32 arg2) {
    return func_80676AB8(arg0, arg1, arg2)
        && (func_80676540(arg1, arg0, arg2)
            || func_80714608(0));
}

// CharacterChange and ActorAdditionalData struct usages
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676BCC.s")

/*
// TODO: Regalloc
u8 func_80676BCC(s32 arg0, Actor *arg1, s32 arg2) {
    PlayerAdditionalActorData *PaaD = arg1->PaaD;
    u8 temp = PaaD->unk1A4;
    return (character_change_array[PaaD->unk1A4].unk2C0 == 2);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676C10.s")

/*
// TODO: Issue with func_806769A8 signature?
// TODO: Regalloc?
u8 func_80676C10(s32 arg0, Actor *arg1, s32 arg2) {
    s32 phi_v1 = arg1->PaaD->unkD4 != 0 ? 1 : 0;
    return phi_v1 || func_806769A8(arg0, arg1, arg2);
}
*/

u8 func_80676C64(s32 arg0, Actor *arg1, s32 arg2) {
    if (func_80676CB0(arg2, 1) && arg1->control_state == 0x1C) {
        return TRUE;
    }
    return FALSE;
}

// Small struct and a loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7AF60/func_80676D00.s")

s32 func_806EB400(Actor *);           // extern
extern f32 D_80759250;
extern f32 D_80759254;
extern f32 D_80759258;

/*
// TODO: Extremely close, just two instructions swapped
void func_80676D00(Actor *arg0, Actor *arg1, s32 arg2, s32 arg3) {
    u8 temp_a2;
    PlayerAdditionalActorData *temp_v0;

    if (arg1 == player_pointer) {
        temp_v0 = arg1->PaaD;
        temp_a2 = temp_v0->unk1A4;
        arg1->PaaD->unk1F0 |= 0x80000;
        if (temp_v0->unkD4 == 0) {
            if (player_pointer->control_state != 0x36) {
                if (func_806EB400(player_pointer) != 0) {
                    if (player_pointer->unk58 == 6) {
                        if (character_change_array[temp_a2].unk2C0 == 2) {
                            if (player_pointer->control_state != 0x31) {
                                if (arg0->interactable & 0x80) {
                                    func_806086CC(arg1->x_position, arg1->y_position, arg1->z_position, 0x1E0, 0xFF, 0x64, 0x1E, 0, D_80759250, 0);
                                }
                            }
                            return;
                        }
                    }
                    if (arg0->unk58 == 0xBB) {
                        func_806086CC(arg1->x_position, arg1->y_position, arg1->z_position, 0x37, 0xFF, 0x7F, 0x1E, 0x5A, D_80759254, 0);
                        return;
                    }
                    func_806086CC(arg1->x_position, arg1->y_position, arg1->z_position, 0x1E0, 0xFF, 0x7F, 0x1E, 0x5A, D_80759258, 0);
                }
            }
        }
    }
}
*/
