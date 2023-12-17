#include <ultra64.h>
#include "functions.h"

const s32 D_boss_80036160[] = {
    0x2C01003C,
    0x4F460A00,
    0x50000000,
};

const s32 D_boss_8003616C[] = {
    0x2B012C0C,
    0x001E4F46,
    0x05002D50,
};

const s32 D_boss_80036178[] = {
    0x2B0C2C11,
    0x001E4F46,
    0x05002D28,
    0x14085000,
};

const s32 D_boss_80036188[] = {
    0x2B112C16,
    0x00144F46,
    0x05002814,
    0x052A0000,
    0x50000000,
};

const s32 D_boss_8003619C[] = {
    0x2B162C1B,
    0x001E4F46,
    0x05002A00,
    0x00460500,
    0x28140550,
};

void func_boss_800292B0(f32 arg0) {
    func_global_asm_80691830(0x6A, 1.2f, 0, 0x96, 0xFF, 0xB, 1.015f, 0.0f, 0.0f, 0.0f);
    func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x221, 0x80, 0x7F, 1, 0, 0.3f, 0);
    last_spawned_actor->y_position = current_actor_pointer->y_position;
    last_spawned_actor->animation_state->scale_y *= arg0;
    func_global_asm_80613C48(last_spawned_actor, 0x4F9, 0.0f, 0.0f);
    func_global_asm_80614D00(last_spawned_actor, 1.5f, 0.0f);
}

void func_boss_800293C0(void) {
    rand();
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_807149C8(0x78, 0x78, 0x78, 0xC8);
    func_global_asm_8068588C(current_actor_pointer, (((rand() >> 0xF) % 32767) % 16) + 3, 2.0f, 0.0f, 0.0f, 0.0f, -0x96);
}

// Jumptable, 3544 bytes of code, oof
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_52B0/func_boss_80029468.s")
