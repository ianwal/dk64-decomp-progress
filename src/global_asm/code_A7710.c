#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_806A2A10.s")

/*
// TODO: Quite close, our stack's too big, and datatype on the temporary variable
void func_806A2A10(s16 arg0, s16 arg1, u8 arg2) {
    s8 temp = arg2;
    func_80677FA8(0xB0, 0); // spawnActorWrapper(ACTOR_TIMER_CONTROLLER)
    if ((arg0 & 0x8000) != 0) {
        D_807FBB44->unk15F = 0xB;
        temp--;
    } else {
        D_807FBB44->unk15F = 6;
    }
    current_actor_pointer->unk11C = D_807FBB44;
    extra_player_info_pointer->unk1A8 = D_807FBB44;
    D_807FBB44->additional_data_pointer[3] = temp & 0xFF;
    D_807FBB44->x_position = (s16) (arg0 & 0x7FFF);
    D_807FBB44->y_position = arg1;
    D_807FBB44->control_state = 1;
    D_807FBB44->shadow_opacity = 0;
}
*/

void func_806A2B08(Actor *arg0) {
    arg0->control_state = 2;
    arg0->control_state_progress = 0;
    arg0->shadow_opacity = 0xFF;
}

void func_806A2B20(Actor *arg0) {
    if (arg0 != 0) {
        arg0->control_state = 1;
        arg0->control_state_progress = 0;
    }
}

// actor + libultra + weird struct offset, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_806A2B38.s")

void func_806A2B80(Actor *arg0) {
    arg0->control_state = 3;
    arg0->control_state_progress = 0;
}

// actor + displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_806A2B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_806A2E30.s")

void func_806A36F4(void) {

}
