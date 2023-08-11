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

extern u8 D_menu_800339D0;
int func_menu_8003292C();

void func_menu_8003264C(void) {
    Actor *temp_s0;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    s32 temp_v0;
    s32 var_a0;
    u8 var_v0;
    u8 var_v0_2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk15F = 0;
        func_global_asm_80629174();
        current_actor_pointer->control_state = 0;
    }
    func_global_asm_80729B00();
    switch (current_actor_pointer->control_state) {
        case 0:
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80629174();
                func_global_asm_80614EBC(current_actor_pointer, 0x2D6);
                current_actor_pointer->control_state++;
                current_actor_pointer->control_state_progress = 0;
                global_properties_bitfield &= ~0x30;
            }
            break;
        case 1:
            func_global_asm_8065A660(20.0f, 40.0f);
            if (current_actor_pointer->unk15F != 0xFF) {
                if (0xFF - current_actor_pointer->unk15F < 3) {
                    var_a0 = 0xFF - current_actor_pointer->unk15F;
                } else {
                    var_a0 = 3;
                }
                current_actor_pointer->unk15F += var_a0;
            }
            func_global_asm_8065A708(
                current_actor_pointer->x_position,
                current_actor_pointer->y_position + 20.0f,
                current_actor_pointer->z_position,
                current_actor_pointer->x_position,
                current_actor_pointer->y_position,
                current_actor_pointer->z_position,
                0.0f,
                1,
                current_actor_pointer->unk15F,
                current_actor_pointer->unk15F,
                current_actor_pointer->unk15F
            );
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80629174();
                current_actor_pointer->object_properties_bitfield |= 0x800000;
                current_actor_pointer->control_state = 2;
            }
            break;
        case 2:
            current_actor_pointer->unk16A -= 8;
            current_actor_pointer->unk16B -= 8;
            current_actor_pointer->unk16C -= 8;
            if (current_actor_pointer->unk16A < 9) {
                current_actor_pointer->unk16A = 0;
                current_actor_pointer->unk16B = 0;
                current_actor_pointer->unk16C = 0;
                current_actor_pointer->control_state = 3;
                D_menu_800339D0 = 0;
            }
            break;
        case 3:
            if (D_menu_800339D0 < 0xFF) {
                D_menu_800339D0 += 1;
            }
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80629174();
                current_actor_pointer->control_state = 4;
            }
            break;
        case 4:
            func_global_asm_807145F8();
            current_actor_pointer->control_state += 1;
            break;
    }
    if (current_actor_pointer->control_state >= 3) {
        func_global_asm_8068C350(&func_menu_8003292C, current_actor_pointer, 3);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_E550/func_menu_8003292C.s")
