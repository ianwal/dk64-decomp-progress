#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80757F70[];
Actor *func_807270C0(s16 arg0, s32 arg1);

void func_80627C10(u8 arg0) {
    s32 index = arg0 * 3;
    D_807FBB44->unk16A = D_80757F70[index + 0];
    D_807FBB44->unk16B = D_80757F70[index + 1];
    D_807FBB44->unk16C = D_80757F70[index + 2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_80627C5C.s")

Actor *func_80627EA8(s16 arg0) {
    Actor *actor;

    if (arg0) {
        actor = func_807270C0(arg0, 0); // getSpawnerTiedActor()
    }
    if (!arg0 || !actor) {
        actor = player_pointer;
    }
    return actor;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_80627F04.s")

s32 func_80629148(void) {
    s32 phi_v1 = FALSE;
    if (current_actor_pointer->unk6A & 0x100) {
        current_actor_pointer->unk6A &= ~0x100;
        phi_v1 = TRUE;
    }
    return phi_v1;
}

void func_80629174(void) {
    current_actor_pointer->unk6A &= ~0x100;
}
