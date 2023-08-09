#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2A10.s")

/*
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} AAD_global_asm_806A2A10;

// TODO: Quite close
void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2) {
    func_global_asm_80677FA8(ACTOR_TIMER_CONTROLLER, 0); // spawnActorWrapper(ACTOR_TIMER_CONTROLLER)
    if ((arg0 & 0x8000) != 0) {
        D_global_asm_807FBB44->unk15F = 0xB;
        arg2--;
    } else {
        D_global_asm_807FBB44->unk15F = 6;
    }
    current_actor_pointer->unk11C = D_global_asm_807FBB44;
    extra_player_info_pointer->unk1A8 = D_global_asm_807FBB44;
    ((AAD_global_asm_806A2A10*)D_global_asm_807FBB44->additional_data_pointer)->unkC = arg2;
    D_global_asm_807FBB44->x_position = (s16) (arg0 & 0x7FFF);
    D_global_asm_807FBB44->y_position = arg1;
    D_global_asm_807FBB44->control_state = 1;
    D_global_asm_807FBB44->shadow_opacity = 0;
}
*/

void func_global_asm_806A2B08(Actor *arg0) {
    arg0->control_state = 2;
    arg0->control_state_progress = 0;
    arg0->shadow_opacity = 0xFF;
}

void func_global_asm_806A2B20(Actor *arg0) {
    if (arg0 != 0) {
        arg0->control_state = 1;
        arg0->control_state_progress = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2B38.s")

extern OSTime D_global_asm_807FC7D0;

typedef struct {
    OSTime unk0;
} AAD_global_asm_806A2B38;

/*
// TODO: Close
void func_global_asm_806A2B38(Actor *arg0) {
    OSTime temp_ret;

    temp_ret = osGetTime();
    D_global_asm_807FC7D0 = temp_ret - ((AAD_global_asm_806A2B38*)arg0->additional_actor_data)->unk0;
}
*/

void func_global_asm_806A2B80(Actor *arg0) {
    arg0->control_state = 3;
    arg0->control_state_progress = 0;
}

// Displaylist stuff (actor)
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2B90.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2E30.s")
