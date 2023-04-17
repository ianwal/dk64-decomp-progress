#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BA790/func_806B5A90.s")

void func_806B63E0() {
    func_80729B00();
    func_806B5A90(10000, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BA790/func_806B640C.s")

extern f32 D_8075B750;
void func_806086CC(f32 arg0, f32 arg1, f32 arg2, s16 arg3, u8 arg4, s16 arg5, u8 arg6, u8 arg7, f32 arg8, u8 arg9);

/*
// TODO: Very close, missing something with the loop index
void func_806B640C(void) {
    Actor178 *temp_s6;
    s16 i;

    temp_s6 = current_actor_pointer->unk178;
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_8066EA90(current_actor_pointer, 3);
        temp_s6->unk0 = -D_807FDC9C->unkA_s16;
    }
    if (is_cutscene_active == 1) {
        // TODO: Something is up with this loop, I think I'm missing a reference to i somewhere
        for (i = 0; i < D_807FBB70[0].unk254; i++) {
            // Possibly D_807FBB70[i]
            if (D_807FBB70[0].unk258 == 3) {
                current_actor_pointer->noclip_byte = 0x24;
                func_80614EBC(current_actor_pointer, 0x24F);
            }
        }
        func_8068A858(&current_actor_pointer->unk16A, &current_actor_pointer->unk16B, &current_actor_pointer->unk16C);
    }
    if ((current_actor_pointer->control_state != 0x37) && (current_actor_pointer->control_state != 0x38)) {
        if (temp_s6->unk0 > 0) {
            temp_s6->unk0--;
            if (temp_s6->unk0 == 0xA) {
                func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x150, 0xFF, 0x7F, 0x1E, 0x32, D_8075B750, 0);
            }
            if (temp_s6->unk0 == 0) {
                D_807FBB70->unk200 = 9;
            }
        }
    }
    if (func_806B5A90(current_map == MAP_JAPES_MINECART ? 40000 : 10000, temp_s6->unk0) != 0) {
        temp_s6->unk0 = -temp_s6->unk0;
    }
}
*/
