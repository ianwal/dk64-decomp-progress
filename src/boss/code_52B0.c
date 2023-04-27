#include <ultra64.h>
#include "functions.h"

extern f32 D_800361B0;
extern f32 D_800361B4;

void func_80613C48(Actor*, s32, f32, f32);

void func_800292B0(f32 arg0) {
    func_80691830(0x6A, 1.2f, 0, 0x96, 0xFF, 0xB, D_800361B0, 0.0f, 0.0f, 0.0f);
    func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x221, 0x80, 0x7F, 1, 0, D_800361B4, 0);
    D_807FBB44->y_position = current_actor_pointer->y_position;
    D_807FBB44->animation_state->scale_y *= arg0;
    func_80613C48(D_807FBB44, 0x4F9, 0.0f, 0.0f);
    func_80614D00(D_807FBB44, 1.5f, 0.0f);
}

void func_800293C0(void) {
    rand();
    func_807149B8(1);
    func_80714998(3);
    func_807149C8(0x78, 0x78, 0x78, 0xC8);
    func_8068588C(current_actor_pointer, (((rand() >> 0xF) % 32767) % 16) + 3, 2.0f, 0.0f, 0.0f, 0.0f, -0x96);
}

// Jumptable, 3544 bytes of code, oof
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_52B0/func_80029468.s")
