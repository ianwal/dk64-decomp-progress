#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_80697230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_806978FC.s")

/*
// TODO: Missing another temp variable, hmm
extern s32 *D_807FC7C0;

void func_806978FC(void) {
    s16 phi_s0;

    D_807FC7C0 = malloc(0xC0);
    for (phi_s0 = 0; phi_s0 < 0x30; phi_s0++) {
        D_807FC7C0[phi_s0] = getPointerTableFile(0x19, phi_s0 + 0x1654, 1, 1);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_80697988.s")

extern f32 D_8075A214;
extern f64 D_8075A218;
void func_80697230(void);

typedef struct {
    union {
        f32 unk0;
        u8 unk0_u8[4];
    };
    void* unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 unk11;
} AAD_80697988;

void func_80604CBC(Actor*, s32, s32, s32, s32, u8, f32, s32);

/*
// TODO: Doable, made some progress
void func_80697988(void) {
    f64 temp_f0;
    AAD_80697988 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEE = current_actor_pointer->unk15F;
        temp_v1->unk4 = malloc(0x1000);
        if (current_actor_pointer->unk15F != 0) {
            current_actor_pointer->noclip_byte = 0x24;
        }
        if (temp_v1->unk11 == 1) {
            func_80604CBC(current_actor_pointer, 0x128, 1, 1, 0, 0xFF, D_8075A214, 0);
            func_80604CBC(current_actor_pointer, 0x139, 0x3C, 1, 1, 0xFF, 1.0f, 0);
        }
    }
    if (temp_v1->unk11 != 0) {
        if (temp_v1->unk11 == 1) {
            current_actor_pointer->x_position += temp_v1->unkC * func_80612794(current_actor_pointer->y_rotation);
            current_actor_pointer->z_position += temp_v1->unkC * func_80612790(current_actor_pointer->y_rotation);
            if (current_actor_pointer->unk15F != 0) {
                current_actor_pointer->unk15F = current_actor_pointer->unk15F - 1;
            }
            if (current_actor_pointer->unk168 == 0x20) {
                current_actor_pointer->unk168 = 0x10;
                temp_v1->unk10 = 0;
            }
            if (temp_v1->unk10 >= 0x10) {
                func_8061130C(temp_v1->unk4);
                func_806782C0(current_actor_pointer);
            }
        }
    } else {
        if (current_actor_pointer->unk15F != 0) {
            temp_v1->unk8 = temp_v1->unk8 + temp_v1->unkC;
            temp_v1->unk0 = MIN(temp_v1->unk8 * D_8075A218, 32.0);
        } else {
            temp_v1->unk8 = temp_v1->unk8 + (((current_actor_pointer->unk168 - temp_v1->unk10) + 0x10) * (temp_v1->unkC * 0.0625));
        }
        if ((temp_v1->unk10 - current_actor_pointer->unk168) >= 0x10) {
            if (current_actor_pointer->unk15F-- != 0) {
                func_80691930(0, temp_v1->unk0_u8[1], temp_v1->unk8, temp_v1->unkC, 0, 0x10);
                if (current_actor_pointer->unk15F == 0) {
                    current_actor_pointer->unk168 = 0x10;
                } else {
                    temp_v1->unk10 = 0;
                }
            } else {
                func_8061130C(temp_v1->unk4);
                func_806782C0(current_actor_pointer);
            }
        }
    }
    func_8068C350(&func_80697230, current_actor_pointer, 1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_80697CEC.s")
