#include <ultra64.h>
#include "functions.h"

// Quite big but pretty doable, needs some struct/array definitions
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_F0D0/func_800330D0.s")

void func_8061EF4C(s32, s32, s32, f32, f32, f32, f32, f32);

extern f64 D_80036C58;
extern s32 D_8071720C; // TODO: Datatype
extern void *D_8074E880[];
extern f32 D_80036DB4;
extern s32 D_807F5D10;

typedef struct BossStruct0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} BossStruct0;

typedef struct BossStruct2 {
    u8 pad0[0x14];
    u8 unk14;
    u8 unk15;
    u8 unk16;
} BossStruct2;

void func_8003340C(BossStruct0 *arg0) {
    if ((current_actor_pointer->animation_state->unk64 != 0x223) && (arg0->unk1 == arg0->unk3)) {
        func_80614EBC(current_actor_pointer, 0x223);
        func_80614D90(current_actor_pointer);
        return;
    }
    if ((current_actor_pointer->animation_state->unk64 != 0x224) && (arg0->unk1 != arg0->unk3)) {
        func_80614EBC(current_actor_pointer, 0x224);
        func_80614D90(current_actor_pointer);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_F0D0/func_800334A4.s")

typedef struct {
    u8 unk0;
    u8 unk1;
} Struct800334A4_arg0;

/*
// TODO: Regalloc & float regalloc
void func_800334A4(Struct800334A4_arg0 *arg0, f32 arg1) {
    f32 temp_f2;

    temp_f2 = func_80612794(((f32)(1.0 - MIN(1.0, current_actor_pointer->animation_state->unk0->unk4 * arg1)) * 1024.0f) + 3072.0f) + 1.0;
    current_actor_pointer->x_position = ((D_807FDCA0->unk14[arg0->unk0].unk0 - D_807FDCA0->unk14[arg0->unk1].unk0) * temp_f2) + D_807FDCA0->unk14[arg0->unk1].unk0;
    current_actor_pointer->z_position = ((D_807FDCA0->unk14[arg0->unk0].unk4 - D_807FDCA0->unk14[arg0->unk1].unk4) * temp_f2) + D_807FDCA0->unk14[arg0->unk1].unk4;
    current_actor_pointer->y_rotation = func_806CC190(current_actor_pointer->y_rotation, func_80665DE0(D_807FDCA0->unk14[arg0->unk1].unk0, D_807FDCA0->unk14[arg0->unk1].unk4, D_807FDCA0->unk14[arg0->unk0].unk0, D_807FDCA0->unk14[arg0->unk0].unk4), 10.0f);
}
*/

void func_800336C0(void) {
    f32 sp24;

    sp24 = current_actor_pointer->animation_state->scale_y / D_80036C58;
    func_80714998(2);
    func_8071498C(&D_8071720C);
    func_807149B8(1);
    func_80714950(1);
    func_80714CC0(D_8074E880[((rand() >> 0xF) % 1000) % 3],
        (f64)sp24,
        current_actor_pointer->x_position,
        current_actor_pointer->y_position,
        current_actor_pointer->z_position);
}

// Oof, I had a crack at this one but it's very fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_F0D0/func_80033784.s")

// Very doable, just gotta figure out some structs
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_F0D0/func_8003392C.s")

/*
void func_8003392C(void *arg0) {
    void *temp_v0;
    void *temp_v1;

    func_80690814(current_actor_pointer, 1);
    temp_v0 = D_807FDCA0->unk14 + (arg0->unk3 * 0xA);
    func_80690A28(0x2C, 2, current_actor_pointer->animation_state->scale_y, temp_v0->unk0, temp_v0->unk2, temp_v0->unk4, 1200.0f, temp_v1);
}
*/

u8 func_800339D8(BossStruct2 *arg0, u8 *arg1) {
    if ((player_pointer->y_position < current_actor_pointer->y_position - 10.0f)) {
        if (arg0->unk14 < 5) {
            arg0->unk15 = arg0->unk16;
            current_actor_pointer->control_state = arg1[arg0->unk15++];
            current_actor_pointer->control_state_progress = 0;
            func_80614EBC(current_actor_pointer, 0);
            return TRUE;
        }
    }
    return FALSE;
}

void func_80033A80(s8 arg0) {
    current_actor_pointer->shadow_opacity += arg0;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->control_state_progress++;
        return;
    }
    if (current_actor_pointer->shadow_opacity >= 0x100) {
        current_actor_pointer->shadow_opacity = 0xFF;
        current_actor_pointer->control_state_progress++;
    }
}

// Jumptable, 7276 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_F0D0/func_80033AF0.s")

void func_8003575C(void) {
    f32 dx, dz;

    switch (current_actor_pointer->control_state_progress) {
        case 1:
            if (current_actor_pointer->control_state == 0) {
                dx = player_pointer->x_position - current_actor_pointer->x_position;
                dz = player_pointer->z_position - current_actor_pointer->z_position;
                if (((dx * dx) + (dz * dz)) < D_80036DB4) {
                    if (player_pointer->control_state != 0x31) {
                        func_806EB0C0(0x2E, current_actor_pointer, 0);
                    }
                    current_actor_pointer->control_state++;
                }
            }
            break;
        case 3:
            func_806782C0(current_actor_pointer);
            break;
    }
    func_8061EF4C(D_807F5D10, 5, 0x14, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
    func_806319C4(current_actor_pointer, 0);
}
