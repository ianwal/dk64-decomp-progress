#include <ultra64.h>
#include "functions.h"

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_global_asm_80697230.s")

extern s32 *D_global_asm_807FC7C0;

void func_global_asm_806978FC(void) {
    s16 phi_s0;
    s16 i;

    phi_s0 = 0;
    D_global_asm_807FC7C0 = malloc(0xC0);
    for (i = 0; i < 0x30; i++) {
        D_global_asm_807FC7C0[phi_s0] = getPointerTableFile(0x19, phi_s0 + 0x1654, 1, 1);
        phi_s0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_global_asm_80697988.s")

extern f32 D_global_asm_8075A214;
extern f64 D_global_asm_8075A218;
void func_global_asm_80697230(void);

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
} AAD_global_asm_80697988;

/*
// TODO: Doable, made some progress
void func_global_asm_80697988(void) {
    f64 temp_f0;
    AAD_global_asm_80697988 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEE = current_actor_pointer->unk15F;
        temp_v1->unk4 = malloc(0x1000);
        if (current_actor_pointer->unk15F != 0) {
            current_actor_pointer->noclip_byte = 0x24;
        }
        if (temp_v1->unk11 == 1) {
            func_global_asm_80604CBC(current_actor_pointer, 0x128, 1, 1, 0, 0xFF, D_global_asm_8075A214, 0);
            func_global_asm_80604CBC(current_actor_pointer, 0x139, 0x3C, 1, 1, 0xFF, 1.0f, 0);
        }
    }
    if (temp_v1->unk11 != 0) {
        if (temp_v1->unk11 == 1) {
            current_actor_pointer->x_position += temp_v1->unkC * func_global_asm_80612794(current_actor_pointer->y_rotation);
            current_actor_pointer->z_position += temp_v1->unkC * func_global_asm_80612790(current_actor_pointer->y_rotation);
            if (current_actor_pointer->unk15F != 0) {
                current_actor_pointer->unk15F = current_actor_pointer->unk15F - 1;
            }
            if (current_actor_pointer->unk168 == 0x20) {
                current_actor_pointer->unk168 = 0x10;
                temp_v1->unk10 = 0;
            }
            if (temp_v1->unk10 >= 0x10) {
                func_global_asm_8061130C(temp_v1->unk4);
                func_global_asm_806782C0(current_actor_pointer);
            }
        }
    } else {
        if (current_actor_pointer->unk15F != 0) {
            temp_v1->unk8 = temp_v1->unk8 + temp_v1->unkC;
            temp_v1->unk0 = MIN(temp_v1->unk8 * D_global_asm_8075A218, 32.0);
        } else {
            temp_v1->unk8 = temp_v1->unk8 + (((current_actor_pointer->unk168 - temp_v1->unk10) + 0x10) * (temp_v1->unkC * 0.0625));
        }
        if ((temp_v1->unk10 - current_actor_pointer->unk168) >= 0x10) {
            if (current_actor_pointer->unk15F-- != 0) {
                func_global_asm_80691930(0, temp_v1->unk0_u8[1], temp_v1->unk8, temp_v1->unkC, 0, 0x10);
                if (current_actor_pointer->unk15F == 0) {
                    current_actor_pointer->unk168 = 0x10;
                } else {
                    temp_v1->unk10 = 0;
                }
            } else {
                func_global_asm_8061130C(temp_v1->unk4);
                func_global_asm_806782C0(current_actor_pointer);
            }
        }
    }
    func_global_asm_8068C350(&func_global_asm_80697230, current_actor_pointer, 1);
}
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_global_asm_80697CEC.s")

void func_global_asm_8065D254(Actor *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_global_asm_806651FC(Actor *);
extern s32 D_global_asm_8071ABDC; // TODO: Datatype
extern s32 D_global_asm_8071FBA0; // TODO: Datatype
extern f32 D_global_asm_8075A220;
extern f32 D_global_asm_8075A224;
extern f64 D_global_asm_8075A228;
extern f64 D_global_asm_8075A230;
extern s32 D_global_asm_8076A068;
extern u8 D_global_asm_807FBB85;

typedef struct {
    s32 unk0[3];
} Struct807502C0;

extern Struct807502C0 D_global_asm_807502C0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
    u8 unk13;
} AAD_global_asm_80697CEC;

/*
// TODO: Doable, problem is in the last loop, rodata?
void func_global_asm_80697CEC(void) {
    Struct807502C0 sp68;
    f64 temp_f20;
    f64 temp_f22;
    s16 i;
    AAD_global_asm_80697CEC *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        sp68 = D_global_asm_807502C0;
        current_actor_pointer->unk6E[0] = -2;
        current_actor_pointer->unk6A &= ~1;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / D_global_asm_8075A220) * D_global_asm_8075A224;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 40.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 30.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        func_global_asm_807149FC(-1);
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_807149A8(0x7D0);
        if (aaD->unk13 == 1) {
            func_global_asm_807149C8(0, 0xFF, 0, 0xC8);
        } else {
            func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
        }
        if (aaD->unk13 == 3) {
            func_global_asm_8071498C(&func_global_asm_8071F758);
        }
        func_global_asm_80714C08(sp68.unk0[aaD->unk13], current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk0 = D_global_asm_8076A068;
        aaD->unk12 = 0;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
        current_actor_pointer->control_state_progress = aaD->unk13;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 4.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x14, 0x14, 1, 0x96, 0x78, 0, 1.0f);
    if ((current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkFC != 0) || (D_global_asm_807FBB85 != 0)) {
        if (aaD->unk13 == 3) {
            func_global_asm_80608528(current_actor_pointer, 0x16, 0xFF, 0x7F, 0x14);
        }
        if (D_global_asm_807FBB85 == 0) {
            temp_f22 = D_global_asm_8075A228;
            temp_f20 = D_global_asm_8075A230;
            for (i = 0; i < 0xC; i += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(i + 0x0B000000);
                func_global_asm_8071498C(&D_global_asm_8071ABDC);
                func_global_asm_80714CC0(&D_global_asm_8071FBA0, (((rand() >> 0xF) % 10) * temp_f20) + temp_f22, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
        func_global_asm_806782C0(current_actor_pointer);
    }
}
*/
