#include <ultra64.h>
#include "functions.h"


s32 func_global_asm_80629148(void);
void func_global_asm_8068A858(s32 *, s32 *, s32 *);
extern s32 D_menu_80033FB0;
extern s32 D_menu_80033FB1;
extern s32 D_menu_80033FB2;

void func_menu_80032550(void) {
    Actor *phi_a0_2;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkCD = 1;
        current_actor_pointer->object_properties_bitfield &= ~4;
    }
    if (current_actor_pointer->object_properties_bitfield & 4) {
        func_global_asm_8068A858(&D_menu_80033FB0, &D_menu_80033FB1, &D_menu_80033FB2);
    }
    if ((current_actor_pointer->control_state == 0) && (current_actor_pointer->control_state_progress == 0)) {
        if (func_global_asm_80629148()) {
            func_global_asm_80629174();
            func_global_asm_80614EBC(current_actor_pointer, 0x2A7);
            current_actor_pointer->control_state_progress++;
        }
        // TODO: Get rid of this somehow, surprisingly getting rid of it causes it to not match
        phi_a0_2 = current_actor_pointer;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Jumptable, 736 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_E550/func_menu_8003264C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_E550/func_menu_8003292C.s")
