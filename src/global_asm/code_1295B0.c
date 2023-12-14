#include <ultra64.h>
#include "functions.h"

typedef struct Struct80755690_unk4 Struct80755690_unk4;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    s8 unk7;
    s16 unk8;
} Struct80755690_unk4_unk14;

struct Struct80755690_unk4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u8 unkE;
    u8 unkF;
    s16 unk10;
    s16 unk12;
    Struct80755690_unk4_unk14 *unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    Struct80755690_unk4 *unk1C;
    s8 unk20;
    s8 unk21;
    s8 unk22;
    s8 unk23;
};

typedef struct {
    s16 unk0;
    s16 unk2;
    Struct80755690_unk4 *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Struct80755690;

typedef struct {
    s16 count;
    s16 unk2;
    EnemySpawner *firstSpawner;
} EnemySpawnerLocator;

typedef struct global_asm_struct_8 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} GlobalASMStruct8;

extern Struct80755690 *D_global_asm_80755690;
extern EnemySpawnerLocator *D_global_asm_80755694;
extern u8 D_global_asm_80755698[];

void func_global_asm_807248B0(Actor *arg0, f32 arg1) {
    LedgeInfo *temp_v0;

    arg0->animation_state->scale_x = arg1;
    arg0->animation_state->scale_y = arg1;
    arg0->animation_state->scale_z = arg1;
    temp_v0 = arg0->ledge_info_pointer;
    if (temp_v0 != NULL) {
        arg0->unk15E = (temp_v0->unkC * arg1) * 0.5;
    }
}

void func_global_asm_80724994(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 *sp24;
    Actor *sp20;

    sp24 = malloc(8);
    func_global_asm_8061134C(sp24);
    sp24[0] = arg1;
    sp24[1] = arg2;
    sp24[2] = arg3;
    sp24[3] = arg4;
    func_global_asm_8072E7DC(0xB, &sp20);
    func_global_asm_8067AB20(NULL, sp20, 0x01000000, arg0, sp24, 0);
}

s32 func_global_asm_80724A20(void) {
    s16 i;
    s32 found;

    found = FALSE;
    for (i = 0; !found && i < D_global_asm_807FBB70.unk254; i++) {
        if (D_global_asm_807FBB70.unk258[i] == 3) {
            found = TRUE;
            current_actor_pointer->control_state = D_global_asm_807FBB70.unk278[i]->unk2;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    return found;
}

void func_global_asm_80724A9C(u8 arg0, u8 arg1, u8 arg2) {
    Struct80755690_unk4 *var_v0;
    s16 i;

    var_v0 = D_global_asm_80755690->unk4;
    for (i = 0; i < D_global_asm_80755690->unk0; i++) {
        if (var_v0->unk18 == arg0) {
            if (arg1 < var_v0->unk10) {
                if (arg2) {
                    var_v0->unk14[arg1].unk6 |= 0x80;
                    return;
                }
                var_v0->unk14[arg1].unk6 &= 0xFF7F;
            }
            break;
        }
        var_v0++;
    }
}

void func_global_asm_80724B5C(u8 arg0, u8 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    Struct80755690_unk4 *var_v0;
    s16 i;

    var_v0 = D_global_asm_80755690->unk4;
    for (i = 0; i < D_global_asm_80755690->unk0; i++) {
        if (var_v0->unk18 == arg0) {
            if (arg1 < var_v0->unk10) {
                *arg2 = var_v0->unk14[arg1].unk0;
                *arg3 = var_v0->unk14[arg1].unk2;
                *arg4 = var_v0->unk14[arg1].unk4;
            }
            break;
        }
        var_v0++;
    }
}

void func_global_asm_80724C2C(s16 arg0) {
    current_actor_pointer->y_rotation = \
    current_actor_pointer->unkEE = D_global_asm_807FBD6C->unkEE + 0x800 & 0xFFF;
    current_actor_pointer->unkB8 = arg0;
}

void func_global_asm_80724C78(void* arg0) {
    func_global_asm_80728300(arg0, D_global_asm_80755690, D_global_asm_80755694);
}

void func_global_asm_80724CA4(s16 arg0, s16 arg1) {
    AnimationStateUnk1C *temp_v0;
    current_actor_pointer->animation_state->unk1C = malloc(8 + (arg1 * 8U));
    func_global_asm_80611690(current_actor_pointer->animation_state->unk1C);
    temp_v0 = current_actor_pointer->animation_state->unk1C;
    temp_v0->unk0 = 0x7F;
    temp_v0->unk1 = arg0;
    temp_v0[arg1].unk0 = 0;
}

void func_global_asm_80724D28(s16 arg0, s16 arg1) {
    AnimationStateUnk24 *temp_v0;

    current_actor_pointer->animation_state->unk24 = malloc(arg1 * 0x10U + 0x10);
    func_global_asm_80611690(current_actor_pointer->animation_state->unk24);
    temp_v0 = current_actor_pointer->animation_state->unk24;
    temp_v0->unk0 = arg0;
    temp_v0->unk1 = arg0 + 1;
    temp_v0[arg1].unk0 = 0xFF;
}

void func_global_asm_80724DB0(s16 arg0, s16 arg1) {
    AnimationStateUnk20 *temp_v0;

    current_actor_pointer->animation_state->unk20 = malloc((arg1 * 0x10U) + 0x10);
    func_global_asm_80611690(current_actor_pointer->animation_state->unk20);
    temp_v0 = current_actor_pointer->animation_state->unk20;
    temp_v0->unk4 = 1.0f;
    temp_v0->unk8 = 1.0f;
    temp_v0->unkC = 1.0f;
    temp_v0->unk0 = arg0;
    temp_v0->unk1 = arg0;
    temp_v0[arg1].unk0 = 0xFF;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80724E48.s")

// Fiddly floats
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_807255A8.s")

u8 func_global_asm_80725B38(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return (arg0 >= arg2)
        && (arg4 >= arg0)
        && (arg1 >= arg3)
        && (arg5 >= arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80725BA4.s")

void func_global_asm_8061F2B8(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);

u8 func_global_asm_80725DC0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    func_global_asm_8061F2B8(arg4, 0.0f, arg5, arg0, 0.0f, arg1, arg2, 0.0f, arg3, &sp4C, &sp48, &sp44);
    return ((sp4C - arg4) * (sp4C - arg4) + (sp44 - arg5) * (sp44 - arg5)) < (arg6 * arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80725ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80726164.s")

// arg0 Actor, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_807264B0.s")

void func_global_asm_807266E8(Actor *arg0, GlobalASMStruct8 *arg1) {
    arg0->x_position = arg1->unk4;
    arg0->y_position = arg1->unk6;
    arg0->unk8C = arg1->unk6;
    arg0->z_position = arg1->unk8;
    arg0->y_rotation = arg1->unk2;
}

// Jumptable, references the cutscene model mapping table at D_global_asm_8075570C
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80726744.s")

u8 func_global_asm_80726D7C(u8 arg0) {
    return func_global_asm_80726DEC(arg0, 5) || func_global_asm_80726DEC(arg0, 6);
}

u8 func_global_asm_80726DC0(u8 arg0) {
    return func_global_asm_80726DEC(arg0, 7);
}

u8 func_global_asm_80726DEC(u8 arg0, u8 arg1) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (var_v1->spawn_trigger == arg0) {
            return (var_v1->spawn_state == arg1);
        }
        var_v1++;
    }
    return 0;
}

void func_global_asm_80726E60(u16 arg0, u8 arg1) {
    Actor *temp_v1;
    EnemySpawner *var_v0;
    s16 i;

    var_v0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (var_v0->spawn_state == 5) {
            temp_v1 = var_v0->tied_actor;
            if (temp_v1->interactable & arg0) {
                temp_v1->control_state = arg1;
            }
        }
        var_v0++;
    }
}

void func_global_asm_80726EE0(u8 arg0) {
    EnemySpawner *var_s0;
    s16 i;

    var_s0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++)  {
        if (!(var_s0->properties_bitfield & 0x80)) {
            if (var_s0->spawn_state == 5 && (var_s0->tied_actor->interactable & 2)) {
                func_global_asm_80679290(var_s0->tied_actor, 0, 8, 0, 0, 0, 1);
            } else if (var_s0->spawn_state == 6 && (var_s0->tied_actor->interactable & 2)) {
                var_s0->spawn_state = 7;
                var_s0->respawn_time = var_s0->respawn_timer_init * 0x1E;
                func_global_asm_8061CFCC(var_s0->tied_actor);
                func_global_asm_806782C0(var_s0->tied_actor);
            }
            switch (arg0) {
                case 0:
                case 1:
                    var_s0->properties_bitfield |= 2;
                    break;
                case 2:
                    var_s0->properties_bitfield &= ~2;
                    break;
                default:
                    break;
            }
        }
        var_s0++;
    }
}

void func_global_asm_8072707C(s16 arg0, u8 arg1, u16 arg2) {
    Actor *actor = func_global_asm_807270C0(arg0, arg2);
    if (actor) {
        actor->control_state = arg1;
        actor->control_state_progress = 0;
    }
}

// getSpawnerTiedActor()
Actor *func_global_asm_807270C0(s16 spawn_trigger, u16 arg1) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (spawn_trigger == var_v1->spawn_trigger) {
            if (var_v1->spawn_state == 5) {
                var_v1->properties_bitfield |= arg1;
                return var_v1->tied_actor;
            }
            if ((var_v1->spawn_state == 6) && (arg1 & 0x400)) {
                func_global_asm_80678428(var_v1->tied_actor);
                var_v1->spawn_state = 5;
                return var_v1->tied_actor;
            }
        }
        var_v1++;
    }
    return NULL;
}

u8 func_global_asm_80727194(Actor *arg0) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (arg0 == var_v1->tied_actor) {
            if (var_v1->spawn_state == 5) {
                return var_v1->spawn_trigger;
            }
        }
        var_v1++;
    }
    return 0;
}

Actor *func_global_asm_807271F4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s16 i;
    Struct8075EB80 *temp_v0;
    EnemySpawner *var_s0;

    var_s0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (arg0 == var_s0->spawn_trigger) {
            if (var_s0->spawn_state != 5) {
                temp_v0 = &D_global_asm_8075EB80[var_s0->alternative_enemy_spawn];
                if (func_global_asm_80677FA8(temp_v0->unk0, temp_v0->unk2) != 0) {
                    var_s0->properties_bitfield |= 4;
                    func_global_asm_80726744(D_global_asm_807FBB44, var_s0);
                    if (arg1 != 0) {
                        D_global_asm_807FBB44->x_position = arg1;
                        D_global_asm_807FBB44->y_position = arg2;
                        D_global_asm_807FBB44->z_position = arg3;
                        D_global_asm_807FBB44->unkEE = arg4;
                        D_global_asm_807FBB44->y_rotation = arg4;
                    }
                    D_global_asm_807FBB44->unkB8 = arg5;
                    D_global_asm_807FBB44->y_velocity = arg6;
                    D_global_asm_807FBB44->unk6A = 0;
                    return D_global_asm_807FBB44;
                }
            }
        }
        var_s0++;
    }
    return NULL;
}

void func_global_asm_807273A8(s16 arg0, u8 arg1) {
    u8 temp_t0;
    s16 sp34;

    temp_t0 = D_global_asm_807FDC98->unk20[arg1].unk0;
    sp34 = (func_global_asm_80665AE4(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0->unk14[temp_t0].unk0, D_global_asm_807FDCA0->unk14[temp_t0].unk4) * 4096.0f) / 360.0f;
    if (func_global_asm_807271F4(arg0, D_global_asm_807FDCA0->unk14[temp_t0].unk0, D_global_asm_807FDCA0->unk14[temp_t0].unk2, D_global_asm_807FDCA0->unk14[temp_t0].unk4, sp34, ((rand() >> 0xF) % 100) + 0x64, ((rand() >> 0xF) % 100) + 0xC8) != 0) {
        D_global_asm_807FBB44->control_state = 0x17;
        D_global_asm_807FBB44->control_state_progress = 0;
    }
}

void func_global_asm_8072752C(s16 arg0, s16 x1, s16 y1, s16 z1, s16 x2, s16 y2, s16 z2, s16 arg7, s16 arg8) {
    s16 sp46;
    f32 sp40;
    s32 pad[2];

    sp46 = func_global_asm_80665DE0(x2, z2, x1, z1);
    sp40 = sqrtf(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) + ((z2 - z1) * (z2 - z1)));
    if (func_global_asm_807271F4(arg0, x1, y1, z1, sp46, sqrtf(((x2 - x1) * (x2 - x1)) + ((z2 - z1) * (z2 - z1))) / (sp40 / arg7), arg8)) {
        D_global_asm_807FBB44->control_state = 0x17;
        D_global_asm_807FBB44->control_state_progress = 0;
    }
}

// Current map access as struct
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80727678.s")

void func_global_asm_807278C0(EnemyInfo *arg0) {
    u8 temp_v0;

    if (current_map == MAP_FUNGI && extra_player_info_pointer->unk1F0 & 0x100000 && D_global_asm_80755698[arg0->enemy_type] != 0xA) {
        switch (arg0->enemy_type) {
            case 28: // TODO: Enemy type enum
                arg0->unk44 = 0x63;
                return;
            case 9: // TODO: Enemy type enum
                arg0->unk44 = 0x54;
                return;
            case 44: // TODO: Enemy type enum
                arg0->unk44 = 0x67;
                return;
        }
    } else {
        arg0->unk44 = arg0->enemy_type;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80727958.s")

u8 func_global_asm_80727F20(EnemyInfo *arg0, s32 arg1) {
    return (((character_change_array[0].look_at_eye_x - arg0->x_position) * (character_change_array[0].look_at_eye_x - arg0->x_position))
        + ((character_change_array[0].look_at_eye_y - arg0->y_position) * (character_change_array[0].look_at_eye_y - arg0->y_position))
        + ((character_change_array[0].look_at_eye_z - arg0->z_position) * (character_change_array[0].look_at_eye_z - arg0->z_position)) < arg1)
        && ((D_global_asm_80755698[arg0->unk44] == 6)
            || (arg0->unk46 & 0x20)
            || func_global_asm_80652F24(0, arg0->unk40));
}

u8 func_global_asm_80728004(EnemyInfo *arg0, s32 arg1) {
    return (arg1 > (((character_change_array[0].look_at_eye_x - arg0->unk18->x_position) * (character_change_array[0].look_at_eye_x - arg0->unk18->x_position))
        + ((character_change_array[0].look_at_eye_y - arg0->unk18->y_position) * (character_change_array[0].look_at_eye_y - arg0->unk18->y_position))
        + ((character_change_array[0].look_at_eye_z - arg0->unk18->z_position) * (character_change_array[0].look_at_eye_z - arg0->unk18->z_position))))
        && ((arg0->unk18->interactable & 0x40)
            || (arg0->unk46 & 0x20)
            || func_global_asm_80652F24(0, arg0->unk40));
}

u8 func_global_asm_807280C8(EnemyInfo *arg0, s32 arg1) {
    return (arg1 < (((character_change_array[0].look_at_eye_x - arg0->unk18->x_position) * (character_change_array[0].look_at_eye_x - arg0->unk18->x_position))
        + ((character_change_array[0].look_at_eye_y - arg0->unk18->y_position) * (character_change_array[0].look_at_eye_y - arg0->unk18->y_position))
        + ((character_change_array[0].look_at_eye_z - arg0->unk18->z_position) * (character_change_array[0].look_at_eye_z - arg0->unk18->z_position))))
        || (!(arg0->unk18->interactable & 0x40)
            && !(arg0->unk46 & 0x20)
            && !func_global_asm_80652F24(0, arg0->unk40));
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_8072818C.s")

/*
u8 func_global_asm_8072818C(EnemyInfo *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = sqrtf(arg1) * 1.5;
    return ((arg0->unk18->interactable & 2) && !(arg0->unk46 & 0x20) && arg0->unk12 == 2)
        && ((temp_f0) * (temp_f0)) < 
            ((character_change_array[0].look_at_eye_z - arg0->unk18->z_position) * (character_change_array[0].look_at_eye_z - arg0->unk18->z_position))
            + ((character_change_array[0].look_at_eye_y - arg0->unk18->y_position) * (character_change_array[0].look_at_eye_y - arg0->unk18->y_position))
            + ((character_change_array[0].look_at_eye_x - arg0->unk18->x_position) * (character_change_array[0].look_at_eye_x - arg0->unk18->x_position));
}
*/

void func_global_asm_8072827C(Struct80755690_unk4 *arg0) {
    s16 i;
    Struct80755690_unk4 *var_v0;

    var_v0 = D_global_asm_80755690->unk4;
    for (i = 0; i < D_global_asm_80755690->unk0; i++) {
        var_v0->unk1C = 0;
        var_v0->unk20 = 0;
        if (var_v0->unk18 == arg0->unkE) {
            arg0->unk1C = var_v0;
            break;
        } else {
            var_v0++;
        }
    }
    if (arg0->unk1C == NULL) {
        arg0->unk1C = D_global_asm_80755690->unk4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80728300.s")

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_8072881C.s")

/*
u8 func_global_asm_8072881C(u8 arg0, u32 *arg1) {
    u8 phi_v1 = FALSE;
    if ((arg0 & 0x80)
        || (*arg1 + 50 < object_timer
            && !(((rand() >> 0xF) % 1000) < 0x3C1)
            && !func_global_asm_80688540(current_actor_pointer, arg0))) {
        func_global_asm_80688370(current_actor_pointer, arg0, 1.0f);
        func_global_asm_806883C8(current_actor_pointer, arg0, 1);
        func_global_asm_8068839C(current_actor_pointer, arg0, 0);
        func_global_asm_806884B8(current_actor_pointer, arg0, 3);
        func_global_asm_80688514(current_actor_pointer, arg0);
        func_global_asm_806883F4(current_actor_pointer, arg0, 0, 0);
        func_global_asm_8068842C(current_actor_pointer, arg0, 2);
        *arg1 = object_timer;
        phi_v1 = TRUE;
    }
    return phi_v1;
}
*/

void func_global_asm_80728950(u8 arg0) {
    func_global_asm_8068842C(current_actor_pointer, arg0, 1);
    func_global_asm_80688460(current_actor_pointer, arg0, 1);
    func_global_asm_806883F4(current_actor_pointer, arg0, 2, 0);
}

void func_global_asm_807289B0(u8 arg0, u8 arg1) {
    func_global_asm_806883F4(current_actor_pointer, arg0, arg1, 0);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_807289E8.s")

void func_global_asm_80729AA4(u8 arg0) {
    Actor *actor = func_global_asm_807270C0(arg0, 0); // getSpawnerTiedActor()
    if (!actor) {
        actor = player_pointer;
    }
    actor->unk6A |= 0x100;
}
