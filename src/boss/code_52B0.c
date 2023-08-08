#include <ultra64.h>
#include "functions.h"

extern f32 D_boss_800361B0;
extern f32 D_boss_800361B4;

void func_boss_800292B0(f32 arg0) {
    func_global_asm_80691830(0x6A, 1.2f, 0, 0x96, 0xFF, 0xB, D_boss_800361B0, 0.0f, 0.0f, 0.0f);
    func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x221, 0x80, 0x7F, 1, 0, D_boss_800361B4, 0);
    D_global_asm_807FBB44->y_position = current_actor_pointer->y_position;
    D_global_asm_807FBB44->animation_state->scale_y *= arg0;
    func_global_asm_80613C48(D_global_asm_807FBB44, 0x4F9, 0.0f, 0.0f);
    func_global_asm_80614D00(D_global_asm_807FBB44, 1.5f, 0.0f);
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
