#include <ultra64.h>
#include "functions.h"

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CB230/func_806C6530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CB230/func_806C6884.s")

extern f32 D_8075C398;
extern f32 D_8075C39C;

/*
// TODO: Probably needs .data/.rodata defined
void func_806C6884(s16 arg0, s16 arg1, u16 arg2) {
    u16 phi_t0;
    f32 dx;
    f32 dz;

    func_80729B00();
    dx = current_actor_pointer->x_position - D_807FDC94->x_position;
    dz = current_actor_pointer->z_position - D_807FDC94->z_position;
    phi_t0 = sqrtf((dx * dx) + (dz * dz));
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        // TODO: Might need to store actor178 in a temporary variable
        // TODO: Putting u8s at actor 178 causes Boss overlay to not match
        current_actor_pointer->unk178->unk2 = 0;
        current_actor_pointer->unk178->unk0 = 0xFF;
        D_807FDC98->unk3C = 1.0f;
        if (current_actor_pointer->unk58 == ACTOR_SPOTLIGHT_FISH) {
            func_80604CBC(current_actor_pointer, 0x132, 0, 0, 0, 0xA0, 1.0f, 0);
        }
    }
    phi_t0 = phi_t0 - arg1;
    if (phi_t0 < 0) {
        phi_t0 = 0;
    }
    func_8072B324(current_actor_pointer, (2.0 * phi_t0));
    func_8072A920(0x23, arg0, D_807FDC94->x_position, (D_807FDC94->y_position + (arg0 * 3.0)), D_807FDC94->z_position, 0x1E, D_8075C398, 100.0f, arg2 | 0x2000);
    current_actor_pointer->y_position += func_80612794(object_timer * 0x28) * 0.5;
    func_806C6530(current_actor_pointer);
    func_806319C4(current_actor_pointer, 0);
}
*/

void func_806C6B50(void) {
    current_actor_pointer->unkAC = D_8075C39C;
    func_806C6884(0, 0xA, 0x44);
    func_8072881C(0, &D_807FDC90->unk28);
}

void func_806C6BA0(void) {
    func_806C6884(0xA, 0x14, 0x240);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CB230/func_806C6BC8.s")
