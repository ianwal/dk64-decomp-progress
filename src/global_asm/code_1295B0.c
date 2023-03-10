#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807248B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724B5C.s")

void func_80724C2C(s16 arg0) {
    current_actor_pointer->y_rotation = \
    current_actor_pointer->unkEE = D_807FBD6C->unkEE + 0x800 & 0xFFF;
    current_actor_pointer->unkB8 = arg0;
}

extern s32 D_80755690;

typedef struct {
    s16 count;
    s16 unk2;
    EnemySpawner *firstSpawner;
} EnemySpawnerLocator;

extern EnemySpawnerLocator *D_80755694;

void func_80724C78(s32 arg0) {
    func_80728300(arg0, D_80755690, D_80755694);
}

// TODO: Very doable, just need to define ActorAnimationState->unk1C as an array of 0x8 big structs
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724CA4.s")

// TODO: Doable, more struct definitions needed
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724D28.s")

// TODO: ActorAnimationState->unk20
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80724E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807255A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80725B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80725BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80725DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80725ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80726164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807264B0.s")

typedef struct global_asm_struct_8 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} GlobalASMStruct8;

void func_807266E8(Actor *arg0, GlobalASMStruct8 *arg1) {
    arg0->x_position = arg1->unk4;
    arg0->y_position = arg1->unk6;
    arg0->unk8C = arg1->unk6;
    arg0->z_position = arg1->unk8;
    arg0->y_rotation = arg1->unk2;
}

// Jumptable, references the cutscene model mapping table at D_8075570C
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80726744.s")

u8 func_80726DEC(u8, s32);

u8 func_80726D7C(u8 arg0) {
    return func_80726DEC(arg0, 5) || func_80726DEC(arg0, 6);
}

u8 func_80726DC0(u8 arg0) {
    return func_80726DEC(arg0, 7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80726DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80726E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80726EE0.s")

Actor *func_807270C0(s16, u16); // getSpawnerTiedActor()
void func_80678428(Actor*);

void func_8072707C(s16 arg0, u8 arg1, u16 arg2) {
    Actor *actor = func_807270C0(arg0, arg2);
    if (actor) {
        actor->control_state = arg1;
        actor->control_state_progress = 0;
    }
}

// getSpawnerTiedActor()
Actor *func_807270C0(s16 spawn_trigger, u16 arg1) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_80755694->firstSpawner;
    i = 0;
    while (i < D_80755694->count) {
        if (spawn_trigger == var_v1->spawn_trigger) {
            if (var_v1->spawn_state == 5) {
                var_v1->properties_bitfield |= arg1;
                return var_v1->tied_actor;
            }
            if ((var_v1->spawn_state == 6) && (arg1 & 0x400)) {
                func_80678428(var_v1->tied_actor);
                var_v1->spawn_state = 5;
                return var_v1->tied_actor;
            }
        }
        i++;
        var_v1++;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80727194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807271F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807273A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_8072752C.s")

s32 func_807271F4(s16, s16, s16, s16, s32, s32, s32);

/*
// TODO: Everything matches apart from stack offset
void func_8072752C(s16 arg0, s16 x1, s16 y1, s16 z1, s16 x2, s16 y2, s16 z2, s16 arg7, s16 arg8) {
    s16 sp46;
    f32 sp40;
    s32 dx, dy, dz;

    dx = (x2 - x1) * (x2 - x1);
    dy = (y2 - y1) * (y2 - y1);
    dz = (z2 - z1) * (z2 - z1);
    sp46 = func_80665DE0(x2, z2, x1, z1);
    sp40 = sqrtf(dx + dy + dz);
    if (func_807271F4(arg0, x1, y1, z1, sp46, sqrtf(dx + dz) / (sp40 / arg7), arg8)) {
        D_807FBB44->control_state = 0x17;
        D_807FBB44->control_state_progress = 0;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80727678.s")

// Unknown struct arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807278C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80727958.s")

// TODO: Regalloc v1 a3
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80727F20.s")

extern u8 D_80755698[];

u8 func_80652F24(s16, s16);

/*
// TODO: Regalloc v1 a3
u8 func_80727F20(EnemyInfo *arg0, s32 arg1) {
    f32 dz, dy, dx;

    dz = character_change_array[0].look_at_eye_z - arg0->z_position;
    dx = character_change_array[0].look_at_eye_x - arg0->x_position;
    dy = character_change_array[0].look_at_eye_y - arg0->y_position;

    return ((dz * dz) + ((dx * dx) + (dy * dy)) < arg1)
        && ((D_80755698[arg0->unk44] == 6) || (arg0->unk46 & 0x20) || func_80652F24(0, arg0->unk40));
}
*/

// Very doable, dx,dy,dz and a large conditional check at the end that will need to be simplified
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80728004.s")

// Very doable, dx,dy,dz and a large conditional check at the end that will need to be simplified
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807280C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_8072818C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_8072827C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_80728300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_8072881C.s")

void func_806883F4(Actor *arg0, s32 arg1, s32 arg2, f32 arg3);
void func_8068842C(Actor *arg0, s32 arg1, s32 arg2);
void func_80688460(Actor *arg0, s32 arg1, s32 arg2);
void func_80688370(Actor*, u8, f32);

//s32 func_80688540(Actor*, u8);

/*
// TODO: Pretty close, might be missing a temp variable?
// Datatypes could also differ for the & 0x7F function calls
u8 func_8072881C(s32 arg0, u32 *arg1) {
    u8 phi_v1 = FALSE;
    if ((arg0 & 0x80)
        || (*arg1 + 50 < object_timer
            && (((rand() >> 0xF) % 1000) < 0x3C1) == 0
            && !func_80688540(current_actor_pointer, arg0))) {
        func_80688370(current_actor_pointer, arg0 & 0x7F, 1.0f);
        func_806883C8(current_actor_pointer, arg0 & 0x7F, 1);
        func_8068839C(current_actor_pointer, arg0 & 0x7F, 0);
        func_806884B8(current_actor_pointer, arg0 & 0x7F, 3);
        func_80688514(current_actor_pointer, arg0 & 0x7F);
        func_806883F4(current_actor_pointer, arg0 & 0x7F, 0, 0);
        func_8068842C(current_actor_pointer, arg0 & 0x7F, 2);
        *arg1 = object_timer;
        phi_v1 = TRUE;
    }
    return phi_v1;
}
*/

void func_80728950(u8 arg0) {
    func_8068842C(current_actor_pointer, arg0, 1);
    func_80688460(current_actor_pointer, arg0, 1);
    func_806883F4(current_actor_pointer, arg0, 2, 0);
}

void func_807289B0(u8 arg0, u8 arg1) {
    func_806883F4(current_actor_pointer, arg0, arg1, 0);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_807289E8.s")

void func_80729AA4(u8 arg0) {
    Actor *actor = func_807270C0(arg0, 0); // getSpawnerTiedActor()
    if (!actor) {
        actor = player_pointer;
    }
    actor->unk6A |= 0x100;
}
