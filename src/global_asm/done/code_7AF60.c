#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_807F6902;

s32 func_global_asm_806EB400(Actor *);

void func_global_asm_80676260(Actor *arg0, Actor *arg1, s32 arg2) {
    func_global_asm_806D0DE4(arg0, arg1);
}

u8 func_global_asm_80676280(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    return func_global_asm_806D10D0(arg1) && D_global_asm_807F6902 == 0;
}

u8 func_global_asm_806762C0(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    return func_global_asm_806767E0(arg0, arg1, arg2) && func_global_asm_80676280(arg0, arg1, arg2);
}

u8 func_global_asm_80676308(Actor *arg0, Actor *arg1, s32 arg2) {
    s16 diff = arg0->health - arg1->unk136;
    if (diff <= 0) {
        return TRUE;
    }
    return FALSE;
}

// TODO: Can we clean this up any more?
u8 func_global_asm_80676338(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    u8 var_a0;

    var_a0 = func_global_asm_806CC14C(func_global_asm_80665DE0((s16)arg0->x_position, (s16)arg0->z_position, (s16)arg1->x_position, (s16)arg1->z_position), arg0->y_rotation) < 0x200;
    if (var_a0) {
        var_a0 = func_global_asm_8067641C(arg0, arg1, arg2);
    }
    return var_a0;
}

u8 func_global_asm_8067641C(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    return (func_global_asm_806CC14C(func_global_asm_80665DE0((s16)arg0->x_position, (s16)arg0->z_position, (s16)arg1->x_position, (s16)arg1->z_position), arg1->y_rotation) < 0x3A9);
}

u8 func_global_asm_806764D8(Actor *arg0, Actor *arg1, Actor *arg2) {
    return 0.7 < func_global_asm_80665E94(arg0->x_position, arg0->y_position, arg0->z_position, arg1->x_position, arg1->y_position, arg1->z_position, 0);
}

u8 func_global_asm_80676540(Actor *arg0, Actor *arg1, Actor *arg2) {
    return func_global_asm_806764D8(arg0, arg1, arg2) && arg1->y_velocity < -100.0f;
}

u8 func_global_asm_80676590(Actor *arg0, Actor *arg1, s32 arg2) {
    return arg0->distance_from_floor < 10.0f && arg0->y_position < arg1->y_position;
}

u8 func_global_asm_806765E8(Actor *arg0, Actor *arg1, s32 arg2) {
    f32 position[3];

    if (arg0->unkCC) {
        getBonePosition(arg0, arg0->unkCC, &position[2], &position[1], &position[0]);
    } else {
        position[2] = arg0->x_position;
        position[1] = arg0->y_position;
        position[0] = arg0->z_position;
    }

    return arg1->distance_from_floor < 10.f && arg1->y_position < position[1];
}

u8 func_global_asm_80676690(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 1) && func_global_asm_8067641C(arg0, arg1, arg2);
}

u8 func_global_asm_806766E0(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 2) && func_global_asm_8067641C(arg0, arg1, arg2);
}

u8 func_global_asm_80676730(s32 arg0, s32 arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 1);
}

u8 func_global_asm_8067675C(s32 arg0, s32 arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 3);
}

u8 func_global_asm_80676788(s32 arg0, s32 arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 5);
}

u8 func_global_asm_806767B4(s32 arg0, s32 arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 4);
}

u8 func_global_asm_806767E0(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    return func_global_asm_80676CB0(arg2, 2);
}

extern u8 D_global_asm_807FBBA9;

s32 func_global_asm_8067680C(Actor *arg0, Actor *arg1, Struct80676CB0 *arg2) {
    u32 var_v0;
    f32 var_f0;
    f32 var_f12;
    f32 var_f14;
    PlayerAdditionalActorData *PaaD;

    if (arg1->interactable & 1) {
        PaaD = arg1->PaaD;
        if (PaaD->unk1F0 & 0x01000000) {
            return TRUE;
        }
    }
    if (!func_global_asm_8067641C(arg0, arg1, arg2)) {
        return FALSE;
    }
    var_f0 = arg0->animation_state->scale[1] * arg0->unk0->unk1C;
    var_f12 = arg0->y_position + var_f0;
    var_f14 = ABS(var_f12 - arg1->y_position);
    var_v0 = arg0->unk58;
    switch (var_v0) {
        case ACTOR_BARREL_DIDDY_5DI:
        case ACTOR_TNT_BARREL:
        case ACTOR_STEEL_KEG:
        case ACTOR_BARREL:
        case ACTOR_BARREL_BANANA: 
            var_f0 = 8.0f;
            break;
        case ACTOR_VASE_OVAL:
        case ACTOR_VASE_DOTS:
        case ACTOR_VASE_TRIANGLE:
        case ACTOR_VASE_PLUS:
        case ACTOR_CANNON_BALL:
            var_f0 = 14.0f;
            break;
        case ACTOR_BOULDER:
        case ACTOR_APPLE:
            var_f0 = 25.0f;
            break;
        default:
            var_f0 = 0.0f;
            break;
    }
    if (var_f0 < var_f14) {
        return FALSE;
    }
    if (D_global_asm_807FBBA9) {
        return FALSE;
    }
    if ((arg0->unk68 & 1) == 0) {
        return FALSE;
    }
    return TRUE;
}

int func_global_asm_806769A8(s32 arg0, Actor *arg1, s32 arg2) {
    if (arg1->unk58 == ACTOR_CHUNKY) {
        u8 temp = arg1->PaaD->unk1A4;
        if (character_change_array[temp].unk2C0 != 1) {
            return TRUE;
        }
    }
    return FALSE;
}

int func_global_asm_80676A0C(s32 arg0, Actor *arg1, s32 arg2) {
    if (arg1->unk58 == ACTOR_TINY) {
        u8 temp = arg1->PaaD->unk1A4;
        if (character_change_array[temp].unk2C0 != 1) {
            return TRUE;
        }
    }
    return FALSE;
}

u8 func_global_asm_80676A70(s32 arg0, Actor *arg1, s32 arg2) {
    return func_global_asm_806769A8(arg0, arg1, arg2) && func_global_asm_8067680C(arg0, arg1, arg2);
}

// TODO: Simplify this
u8 func_global_asm_80676AB8(Actor *arg0, Actor *arg1, Actor *arg2) {
    u8 var_v1;
    u8 temp = arg0->PaaD->unk1A4;

    var_v1 = 0;
    if (arg1->interactable & 2) {
        var_v1 = (character_change_array[temp].unk2C0 == 2);
        if (var_v1 != 0) {
            if (cc_number_of_players == 1) {
                var_v1 = (arg0->unk58 == ACTOR_CHUNKY);
            }
        }
    }
    return var_v1;
}

u8 func_global_asm_80676B38(Actor *arg0, Actor *arg1, Actor *arg2) {
    // Actor->isGrounded?
    return func_global_asm_80676AB8(arg0, arg1, arg2) && arg0->unk6A & 1;
}

u8 func_global_asm_80676B70(Actor *arg0, Actor *arg1, Actor *arg2) {
    return func_global_asm_80676AB8(arg0, arg1, arg2)
        && (func_global_asm_80676540(arg1, arg0, arg2)
            || func_global_asm_80714608(0));
}

u8 func_global_asm_80676BCC(s32 arg0, Actor *arg1, s32 arg2) {
    u8 temp = arg1->PaaD->unk1A4;
    return (character_change_array[temp].unk2C0 == 2);
}

u8 func_global_asm_80676C10(s32 arg0, Actor *arg1, s32 arg2) {
    PlayerAdditionalActorData* paad = arg1->PaaD;
    s32 phi_v1 = paad->unkD4 != 0 ? 1 : 0;
    return phi_v1 || func_global_asm_806769A8(arg0, arg1, arg2);
}

u8 func_global_asm_80676C64(s32 arg0, Actor *arg1, Struct80676CB0 *arg2) {
    if (func_global_asm_80676CB0(arg2, 1) && arg1->control_state == 0x1C) {
        return TRUE;
    }
    return FALSE;
}

u8 func_global_asm_80676CB0(Struct80676CB0 *arg0, u8 arg1) {
    s32 i;
    Struct80676CB0_unk10 *var_a3;

    var_a3 = arg0->unk10;
    for (i = 0; i < arg0->unkC; i++) {
        if (arg1 == var_a3[i].unk14) {
            return TRUE;
        }
    }
    return FALSE;
}
