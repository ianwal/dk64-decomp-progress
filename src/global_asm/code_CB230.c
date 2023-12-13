#include <ultra64.h>
#include "functions.h"

/*
D_global_asm_8075C380 .float 40000.0f
D_global_asm_8075C388 .double 35.0
D_global_asm_8075C390 .double 220.0
D_global_asm_8075C398 .float 3.3f
D_global_asm_8075C39C .float 99999.0f
D_global_asm_8075C3A0 .double 0.13
D_global_asm_8075C3A8 .double 0.02
D_global_asm_8075C3B0 .double 0.05
D_global_asm_8075C3B8 .double 150.0
D_global_asm_8075C3C0 .double 0.01
*/

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
            if ((40000.0f < (((current_actor_pointer->x_position - player_pointer->x_position) * (current_actor_pointer->x_position - player_pointer->x_position))
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
    sp8C->unk0 = (func_global_asm_80612794(object_timer * 0x82) * 35.0) + 220.0;
    func_global_asm_8065A708(sp64, sp68, sp6C, sp70, sp74, sp78, 0.0f, 1, sp8C->unk0, sp8C->unk0, sp8C->unk0);
}

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
    func_global_asm_8072A920(0x23, arg0, D_global_asm_807FDC94->x_position, (D_global_asm_807FDC94->y_position + (arg0 * 3.0)), D_global_asm_807FDC94->z_position, 0x1E, 3.3f, 100.0f, arg2 | 0x2000);
    current_actor_pointer->y_position += 0.5 * func_global_asm_80612794(object_timer * 0x28);
    func_global_asm_806C6530();
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_806C6B50(void) {
    current_actor_pointer->unkAC = 99999.0f;
    func_global_asm_806C6884(0, 0xA, 0x44);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}

void func_global_asm_806C6BA0(void) {
    func_global_asm_806C6884(0xA, 0x14, 0x240);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CB230/func_global_asm_806C6BC8.s")

extern u8 D_global_asm_807FBD70;

/*
void func_global_asm_806C6BC8(void) {
    u32 *temp;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 0x7D0;
        current_actor_pointer->unk130 = 0xFF;
        current_actor_pointer->unk131 = 0xFF;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
        D_global_asm_807FDC90->unk30 = current_actor_pointer->animation_state->scale[1];
        D_global_asm_807FDC90->unk2E = 0x96;
        D_global_asm_807FDC98->unk46 |= 0x60;
        func_global_asm_806A2A10(0xDC, 0x2A, 0x64, &D_global_asm_807FDC90);
        func_global_asm_806A2B08(D_global_asm_807FBB44);
    }
    if (D_global_asm_807FDC90->unk1A & 0x80) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    temp = current_actor_pointer->unk0;
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FDC90->unk2C != 0) {
                sp54 = ((f32)D_global_asm_807FDC90->unk2C / D_global_asm_807FDC90->unk2E);
                func_global_asm_80671C0C(current_actor_pointer, 2, &sp50, &sp4C, &sp48);
                func_global_asm_807248B0(player_pointer, (sp54 * 0.13) + 0.02);
                player_pointer->x_position += ((sp50 - player_pointer->x_position) * 0.05);
                player_pointer->y_position += ((sp4C - player_pointer->y_position) * 0.05);
                player_pointer->z_position += ((sp48 - player_pointer->z_position) * 0.05);
                D_global_asm_807FDC90->unk2C--;
                if (D_global_asm_807FDC90->unk2C == 0) {
                    func_global_asm_805FF9AC(player_pointer->x_position, player_pointer->z_position, 0x33, 0, 0, 1);
                }
            }
            break;
        case 39:
            if (D_global_asm_807FDC90->unk2E != 0) {
                *temp += 2;
                D_global_asm_807FDC90->unk2E--;
                func_global_asm_807248B0(
                    current_actor_pointer,
                    D_global_asm_807FDC90->unk30 + ((0.01 - D_global_asm_807FDC90->unk30) * ((f64)D_global_asm_807FDC90->unk2E / 150.0))
                );
            } else {
                *temp = 2;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 2:
            if (D_global_asm_807FBD70 == 4) {
                func_global_asm_80614EBC(current_actor_pointer, 0);
                func_global_asm_80614D00(current_actor_pointer, 0.0f, 0.0f);
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                playCutscene(current_actor_pointer, 0x18, 1);
                D_global_asm_807FDC90->unk2C = func_global_asm_8061CC30() - 0x1E;
                D_global_asm_807FDC90->unk2E = D_global_asm_807FDC90->unk2C;
                current_actor_pointer->noclip_byte = 1;
            } else {
                switch (*temp) {
                    case 5:
                        func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
                        current_actor_pointer->control_state_progress = 0;
                        break;
                    case 3:
                        func_global_asm_8072B324(current_actor_pointer, 0);
                        func_global_asm_80614EBC(current_actor_pointer, 0x2BB);
                        current_actor_pointer->control_state_progress = 4;
                        // fallthrough
                    case 0:
                    case 4:
                        func_global_asm_80685020(3, 1);
                        if ((current_actor_pointer->control_state_progress == 0) && (((rand() >> 0xF) % 1000) >= 0x3DF)) {
                            current_actor_pointer->control_state_progress = 3;
                        }
                        if ((current_actor_pointer->unk11C->control_state == 5) || (player_pointer->unk58 != ACTOR_DIDDY)) {
                            func_global_asm_80614EBC(current_actor_pointer, 0x2BA);
                            func_global_asm_80614D00(current_actor_pointer, 0.0f, 0.0f);
                            func_global_asm_8063DA40(0x33, 0);
                            func_global_asm_806782C0(current_actor_pointer->unk11C);
                            current_actor_pointer->control_state_progress = 1;
                        }
                        func_global_asm_8072A920(2, 0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkC, D_global_asm_807FDC90->unkE, 0x46, 30.0f, 100.0f, 0x200);
                        func_global_asm_8072D13C(2, 0);
                        break;
                    case 1:
                        func_global_asm_8072DC7C(5);
                        break;
                    case 2:
                        *temp = 0x3B;
                        break;
                }
            }
            break;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/
