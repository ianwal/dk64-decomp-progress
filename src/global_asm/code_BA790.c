#include <ultra64.h>
#include "functions.h"


// Jumptable, doable, switch case is not detected by mips2c
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BA790/func_global_asm_806B5A90.s")

void func_global_asm_8072C918(s32, s16, s32);
extern s16 D_80770710[];
extern s16 D_global_asm_80770628[];
extern u8 D_global_asm_807FBB85;
extern u8 D_global_asm_807FBD70;

/*
u8 func_global_asm_806B5A90(s32 arg0, s32 arg1) {
    u8 sp4F;
    s16 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    f32 radius;
    u8 var_v1_2;
    u8 temp_t3;
    s32 anim;
    s32 mul;

    sp4F = FALSE;
    if (current_actor_pointer->unkEE < current_actor_pointer->y_rotation) {
        sp4C = current_actor_pointer->y_rotation - current_actor_pointer->unkEE;
    } else {
        sp4C = current_actor_pointer->unkEE - current_actor_pointer->y_rotation;
    }
    if ((D_global_asm_807FBD70 == 9) || (D_global_asm_807FBB85 != 0)) {
        switch (current_actor_pointer->control_state) {
            default:
                switch (current_actor_pointer->unk58) {
                    case ACTOR_KABOOM:
                        if (is_cutscene_active == 1) {
                            if (current_actor_pointer->object_properties_bitfield & 4) {
                                current_actor_pointer->control_state = 0x38;
                                current_actor_pointer->control_state_progress = 0;
                            } else {
                                func_global_asm_8072D99C();
                            }
                        } else {
                            current_actor_pointer->control_state = 0x37;
                            current_actor_pointer->control_state_progress = 0;
                        }
                        break;
                    case ACTOR_KLOBBER:
                        func_global_asm_806A5C60(current_actor_pointer);
                        func_global_asm_8067DCC0();
                        func_global_asm_8072D99C();
                        break;
                }
                break;
            case 0x37:
            case 0x38:
                break;
        }
    }
    if ((sp4C >= 0x1F5) && (sp4C < 0xE0C)) {
        func_global_asm_80685210(0.5f, 0x32, (object_timer & 1) + 2);
        current_actor_pointer->unkB8 /= 2;
        if (current_actor_pointer->unk6E[0] == -1) {
            func_global_asm_80604CBC(current_actor_pointer, 0x122, 0U, 0U, 0U, 0xFFU, 1.0f, 0);
        }
    } else {
        if ((current_actor_pointer->unk6E[0] != -1) && (D_80770710[D_global_asm_80770628[current_actor_pointer->unk6E[0]]] == 0x122)) {
            func_global_asm_80605314(current_actor_pointer, 0U);
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0x33:
            if (D_global_asm_807FBD70 == 2) {
                current_actor_pointer->y_velocity = 150.0f;
                current_actor_pointer->unkEE = D_global_asm_807FBD6C->unkEE;
            }
            if (current_actor_pointer->control_state_progress) {
                anim = 0;
            } else {
                anim = 2;
            }
            func_global_asm_8072AB74(
                0x33U, D_global_asm_807FDC94->x_position,
                D_global_asm_807FDC94->z_position, anim, 6.0f);
            if (current_actor_pointer->unk58 == ACTOR_KLOBBER) {
                func_global_asm_8072C918(arg0, 0x24E, 0x24D);
            }
            break;
        case 0:
        case 4:
            func_global_asm_80605314(current_actor_pointer, 0U);
            if (current_actor_pointer->control_state_progress == 0) {
                func_global_asm_80665564(current_actor_pointer, 6.0f);
                current_actor_pointer->control_state_progress = 1;
            }
            if (is_cutscene_active != 1) {
                if (current_actor_pointer->unk58 == ACTOR_KLOBBER) {
                    anim = 0x24D;
                } else {
                    anim = 0x24C;
                }
                func_global_asm_8072C918(arg0, 0x24E, anim);
            }
            if (current_actor_pointer->control_state == 0x33) {
                sp4F = TRUE;
                current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkD;
                current_actor_pointer->unkEE 
                    = current_actor_pointer->y_rotation 
                    = func_global_asm_80665DE0(
                        D_global_asm_807FDC94->x_position,
                        D_global_asm_807FDC94->z_position,
                        current_actor_pointer->x_position,
                        current_actor_pointer->z_position);
            }
            break;
        case 0x38:
            switch (current_actor_pointer->control_state_progress) {
                case 1:
                    break;
                case 0:
                    playActorAnimation(current_actor_pointer, 0x24B);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 2:
                    func_global_asm_8067E278(0U, 1U);
                    func_global_asm_8072D99C();
                    break;
            }
            break;
        case 0x37:
            if (current_actor_pointer->control_state_progress >= 2) {
                // Issues mainly start here
                mul = current_actor_pointer->control_state_progress - 0x82;
                sp40 = mul < 0 ? 0 : mul;
                mul = current_actor_pointer->control_state_progress * 6;
                var_v1_2 = mul >= 0x23 ? 0x22 : mul;
                temp_t3 = (1.0 - (sp40 * 0.03125)) * 230.0;
                if (temp_t3) {
                    func_global_asm_8065D254(
                        current_actor_pointer, 0x3C3,
                        0x40, 0x40,
                        (s16)var_v1_2, (s16)var_v1_2,
                        1, 0x96, temp_t3, 0, 1.0f);
                } else {
                    func_global_asm_8072D99C();
                }
                radius = ((22.0 - MIN(0x16, current_actor_pointer->control_state_progress)) / 20.0) * 200.0;
                if (radius > 130.0) {
                    radius = 200.0f;
                }
                createLight(
                    current_actor_pointer->x_position,
                    current_actor_pointer->y_position, 
                    current_actor_pointer->z_position,
                    0.0f, 0.0f, 0.0f, radius, 0U, 0xFFU, 0xFFU, 0xFFU);
            }
            if (current_actor_pointer->control_state_progress < 4) {
                func_global_asm_8072AB74(0x33U,
                D_global_asm_807FDC94->x_position,
                D_global_asm_807FDC94->z_position, 0x20U, 6.0f);
            }
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    playActorAnimation(current_actor_pointer, 0x24B);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 2:
                    func_global_asm_806A5C60(current_actor_pointer);
                    func_global_asm_8067E278(1U, 1U);
                    func_global_asm_8066EA64(current_actor_pointer, 3);
                    func_global_asm_8061EF4C(D_global_asm_807F5D10, 5U, 0x14U, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 4:
                    func_global_asm_80605314(current_actor_pointer, 0U);
                    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                    func_global_asm_80604CBC(current_actor_pointer, 0x136, 0U, 0U, 0U, 0xFFU, 1.0f, 0);
                    func_global_asm_807149FC(5);
                    func_global_asm_807149B8(1U);
                    changeActorColor(0xFFU, 0xFFU, 0xFFU, 1U);
                    func_global_asm_80714998(1U);
                    func_global_asm_80714A08(-0.4f, 0.4f);
                    func_global_asm_8071498C(func_global_asm_8071B8EC);
                    drawSpriteAtPosition(&D_global_asm_80720630, 0.3f, current_actor_pointer->x_position, current_actor_pointer->floor + 7.0f, current_actor_pointer->z_position);
                    current_actor_pointer->object_properties_bitfield &= ~4;
                    current_actor_pointer->control_state_progress++;
                    break;
                case 5:
                    current_actor_pointer->unk138 = NULL;
                    func_global_asm_8066EA90(current_actor_pointer, 3);
                case 1:
                case 3:
                    current_actor_pointer->control_state_progress++;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x24E);
            break;
    }
    renderActor(current_actor_pointer, 0U);
    return sp4F;
}
*/

void func_global_asm_806B63E0(void) {
    initializeCharacterSpawnerActor();
    func_global_asm_806B5A90(10000, 0);
}

void func_global_asm_806B640C(void) {
    Actor178 *temp_s6;
    s16 i;

    temp_s6 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
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
