#include <ultra64.h>
#include "functions.h"


// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BA790/func_global_asm_806B5A90.s")

void func_global_asm_806B63E0() {
    func_global_asm_80729B00();
    func_global_asm_806B5A90(10000, 0);
}

void func_global_asm_806B640C(void) {
    Actor178 *temp_s6;
    s16 i;

    temp_s6 = current_actor_pointer->unk178;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8066EA90(current_actor_pointer, 3);
        temp_s6->unk0 = -D_global_asm_807FDC9C->unkA_s16;
    }
    if (is_cutscene_active == 1) {
        for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
            if (D_global_asm_807FBB70.unk258[i] == 3) {
                current_actor_pointer->noclip_byte = 0x24;
                playActorAnimation(current_actor_pointer, 0x24F);
            }
        }
        func_global_asm_8068A858(&current_actor_pointer->unk16A, &current_actor_pointer->unk16B, &current_actor_pointer->unk16C);
    }
    if ((current_actor_pointer->control_state != 0x37) && (current_actor_pointer->control_state != 0x38)) {
        if (temp_s6->unk0 > 0) {
            temp_s6->unk0--;
            if (temp_s6->unk0 == 0xA) {
                playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x150, 0xFF, 0x7F, 0x1E, 0x32, 0.3f, 0);
            }
            if (temp_s6->unk0 == 0) {
                D_global_asm_807FBB70.unk200 = 9;
            }
        }
    }
    if (func_global_asm_806B5A90(current_map == MAP_JAPES_MINECART ? 40000 : 10000, temp_s6->unk0) != 0) {
        temp_s6->unk0 = -temp_s6->unk0;
    }
}
