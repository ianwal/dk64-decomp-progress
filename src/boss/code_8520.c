#include <ultra64.h>
#include "functions.h"

void func_8002C520(s16, s16, s16);
Actor *func_807271F4(s32, s16, s16, s16, s16, s32, s32);

void func_8002C520(s16 arg0, s16 arg1, s16 arg2) {
    func_807271F4(arg0,
                  current_actor_pointer->x_position + (func_80612794(arg2) * arg1),
                  D_807FDC9C->unk6,
                  current_actor_pointer->z_position + (func_80612790(arg2) * arg1),
                  0,
                  0,
                  0);
    D_807FBB44->terminal_velocity *= 2;
    D_807FBB44->draw_distance = 2000;
}

void func_8002C5F4(void) {
    func_8002C520(2, ((rand() >> 0xF) % 100) + 300, (rand() >> 0xF) % 4096);
    func_8002C520(3, ((rand() >> 0xF) % 100) + 300, (rand() >> 0xF) % 4096);
    func_8002C520(4, ((rand() >> 0xF) % 100) + 300, (rand() >> 0xF) % 4096);
    if (!(D_807FDC90->unk1A & 0x8000)) {
        D_807FDC90->unk1A |= 0x8000;
        playCutscene(D_807FBB44, 2, 1);
    }
}

void func_8002C748(u8 arg0) {
    D_807FDC90->unk28 = 2;
    func_8068842C(current_actor_pointer, arg0, 1);
    func_80688460(current_actor_pointer, arg0, 1);
    func_806883F4(current_actor_pointer, arg0, D_807FDC90->unk28 & 0xF, 0);
}

void func_8002C7CC(void) {
    u16 sp26;
    u8 sp25;
    u8 sp20;

    sp25 = D_807FDC90->unk28 & 0x80;
    sp20 = D_807FDC90->unk28 & 0xF;
    sp26 = 0;
    if (sp25) {
        sp20++;
        if (sp20 >= 2) {
            sp25 = 0;
        } else {
            sp26 = 0x8000;
        }
    } else {
        sp20--;
        if (sp20 <= 0) {
            sp25 = 0x80;
        } else {
            sp26 = 0x8000;
        }
    }
    func_806883F4(current_actor_pointer, 0, sp20, 0);
    func_806883F4(current_actor_pointer, 1, sp20, 0);
    D_807FDC90->unk28 = sp26 | sp20 | sp25;
}

void func_8002C8B4(void) {
    func_80690814(current_actor_pointer, 1);
    func_80690A28(0x116, 
                (((rand() >> 0xF) % 3) + 1), 
                1.0f, 
                D_807FDC94->x_position, 
                D_807FDC94->y_position + D_807FDC94->unk15E, 
                D_807FDC94->z_position, 
                300.0f, 
                current_actor_pointer);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_8520/func_8002C964.s")
