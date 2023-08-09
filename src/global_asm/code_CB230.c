#include <ultra64.h>
#include "functions.h"

extern f32 D_global_asm_8075C380;
extern f64 D_global_asm_8075C388;
extern f64 D_global_asm_8075C390;

typedef struct {
    s16 unk0;
} A8D_global_asm_806C6530;

void func_global_asm_806C6530(void) {
    A8D_global_asm_806C6530 *sp8C;
    Actor *temp_v0;
    Actor *var_t3;
    f32 temp_f0;
    s16 i;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    s32 temp_f18;
    s32 var_a2;

    var_t3 = NULL;
    var_a2 = 999999;
    sp8C = current_actor_pointer->unk178;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_v0 = D_global_asm_807FB930[i].unk0;
        if ((temp_v0->unk58 == ACTOR_SPOTLIGHT_FISH) || (temp_v0->unk58 == ACTOR_SPOTLIGHT_SQUAWKS)) {
            temp_f18 = ((temp_v0->x_position - player_pointer->x_position) * (temp_v0->x_position - player_pointer->x_position))
                + ((temp_v0->y_position - player_pointer->y_position) * (temp_v0->y_position - player_pointer->y_position))
                + ((temp_v0->z_position - player_pointer->z_position) * (temp_v0->z_position - player_pointer->z_position));
            if (temp_f18 < var_a2) {
                var_a2 = temp_f18;
                var_t3 = temp_v0;
            }
        }
    }
    if (var_t3 != current_actor_pointer) {
        current_actor_pointer->control_state = 0x40;
        return;
    }
    switch (current_actor_pointer->unk58) {
        case ACTOR_SPOTLIGHT_FISH:
            if (current_actor_pointer->object_properties_bitfield & 0x100) {
                func_global_asm_80671C0C(current_actor_pointer, 1, &sp64, &sp68, &sp6C);
            } else {
                sp64 = current_actor_pointer->x_position;
                sp68 = current_actor_pointer->y_position;
                sp6C = current_actor_pointer->z_position;
            }
            if ((D_global_asm_8075C380 < (((current_actor_pointer->x_position - player_pointer->x_position) * (current_actor_pointer->x_position - player_pointer->x_position))
                + ((current_actor_pointer->y_position - player_pointer->y_position) * (current_actor_pointer->y_position - player_pointer->y_position))
                + ((current_actor_pointer->z_position - player_pointer->z_position) * (current_actor_pointer->z_position - player_pointer->z_position)))) && (current_actor_pointer->object_properties_bitfield & 0x100)) {
                func_global_asm_80671C0C(current_actor_pointer, 2, &sp70, &sp74, &sp78);
            } else {
                sp70 = player_pointer->x_position;
                sp74 = player_pointer->y_position;
                sp78 = player_pointer->z_position;
            }
            func_global_asm_8065A660(30.0f, 80.0f);
            break;
        case ACTOR_SPOTLIGHT_SQUAWKS:
            sp64 = current_actor_pointer->x_position;
            sp68 = current_actor_pointer->y_position;
            sp6C = current_actor_pointer->z_position;
            sp70 = (func_global_asm_80612794(current_actor_pointer->y_rotation) * 40.0f) + current_actor_pointer->x_position;
            sp74 = current_actor_pointer->y_position - 20.0f;
            sp78 = (func_global_asm_80612790(current_actor_pointer->y_rotation) * 40.0f) + current_actor_pointer->z_position;
            func_global_asm_8065A660(20.0f, 40.0f);
            break;
    }
    sp8C->unk0 = (func_global_asm_80612794(object_timer * 0x82) * D_global_asm_8075C388) + D_global_asm_8075C390;
    func_global_asm_8065A708(sp64, sp68, sp6C, sp70, sp74, sp78, 0.0f, 1, sp8C->unk0, sp8C->unk0, sp8C->unk0);
}

extern f32 D_global_asm_8075C398;
extern f32 D_global_asm_8075C39C;

void func_global_asm_806C6530(void);

typedef struct {
    s16 unk0;
    u8 unk2;
} A178_806C6884;

void func_global_asm_806C6884(s16 arg0, s16 arg1, u16 arg2) {
    u16 phi_t0;
    f32 dx;
    f32 dz;
    A178_806C6884 *temp;
    f32 temp2;

    func_global_asm_80729B00();
    dx = current_actor_pointer->x_position - D_global_asm_807FDC94->x_position;
    dz = current_actor_pointer->z_position - D_global_asm_807FDC94->z_position;
    phi_t0 = sqrtf((dx * dx) + (dz * dz));
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        temp = current_actor_pointer->unk178;
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        temp->unk2 = 0;
        temp->unk0 = 0xFF;
        D_global_asm_807FDC98->unk3C = 1.0f;
        if (current_actor_pointer->unk58 == ACTOR_SPOTLIGHT_FISH) {
            func_global_asm_80604CBC(current_actor_pointer, 0x132, 0, 0, 0, 0xA0, 1.0f, 0);
        }
    }
    if (phi_t0 - arg1 < 0) {
        phi_t0 = 0;
    } else  {
        phi_t0 = phi_t0 - arg1;
    }
    func_global_asm_8072B324(current_actor_pointer, (2.0 * phi_t0));
    func_global_asm_8072A920(0x23, arg0, D_global_asm_807FDC94->x_position, (D_global_asm_807FDC94->y_position + (arg0 * 3.0)), D_global_asm_807FDC94->z_position, 0x1E, D_global_asm_8075C398, 100.0f, arg2 | 0x2000);
    current_actor_pointer->y_position += 0.5 * func_global_asm_80612794(object_timer * 0x28);
    func_global_asm_806C6530();
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_806C6B50(void) {
    current_actor_pointer->unkAC = D_global_asm_8075C39C;
    func_global_asm_806C6884(0, 0xA, 0x44);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}

void func_global_asm_806C6BA0(void) {
    func_global_asm_806C6884(0xA, 0x14, 0x240);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CB230/func_global_asm_806C6BC8.s")
