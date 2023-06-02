#include <ultra64.h>
#include "functions.h"


void func_806319C4(Actor *, s32);
void func_80699070(s16 *, s16 *, f32, f32, f32, f32, f32, f32);
extern f64 D_8075A588;
extern f64 D_8075A590;
extern f64 D_8075A598;
extern f64 D_8075A5A0;

extern f32 D_8075A550;
extern u8 D_807FBD70;
extern u8 D_807506C0[];

f32 func_80665AE4(s32, s32, s32, s32);

void func_806A1580(void) {
    s16 sp36;
    Actor *sp30;

    sp36 = func_80688E68(current_actor_pointer);
    sp30 = func_807270C0(2, 0);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk130 = 0x46;
        current_actor_pointer->unk131 = 0x32;
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->noclip_byte = 2;
        current_actor_pointer->object_properties_bitfield |= 0x80000000;
        current_actor_pointer->unk64 |= 0x28;
        func_8068848C(current_actor_pointer, 0, 1);
    }
    if ((((player_pointer->x_position - current_actor_pointer->x_position) * (player_pointer->x_position - current_actor_pointer->x_position)) + ((player_pointer->z_position - current_actor_pointer->z_position) * (player_pointer->z_position - current_actor_pointer->z_position))) < D_8075A550) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
    if (sp30) {
        if (sp36 == D_807506C0[sp30->unk15F]) {
            if ((((current_actor_pointer->x_position - player_pointer->x_position) * (current_actor_pointer->x_position - player_pointer->x_position)) + ((current_actor_pointer->z_position - player_pointer->z_position) * (current_actor_pointer->z_position - player_pointer->z_position))) > 900.0f) {
                sp30->unkEC = func_80665AE4(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position) - func_80665AE4(character_change_array->look_at_at_x, character_change_array->look_at_at_z, character_change_array->look_at_eye_x, character_change_array->look_at_eye_z);
            }
            if (func_80688540(current_actor_pointer, 0) == 0) {
                func_80688370(current_actor_pointer, 0, 1.0f);
                func_8068842C(current_actor_pointer, 0, -1);
            }
        } else if (func_80688540(current_actor_pointer, 0) != 0) {
            func_80688460(current_actor_pointer, 0, 1);
            func_806883F4(current_actor_pointer, 0, 0, 0.0f);
        }
        if (D_807FBD70 == 4) {
            if (current_actor_pointer->unk132 == 4) {
                current_actor_pointer->unk132 = 8;
                playSong(0x43, 1.0f);
                func_80679200(sp30, current_actor_pointer, 0x02000000, sp36, 0, 0);
            } else {
                current_actor_pointer->unk132 *= 2;
            }
        }
        if ((player_pointer->unk6A & 1) && !player_pointer->locked_to_pad) {
            current_actor_pointer->unk132 = 1;
        }
    }
    func_806319C4(current_actor_pointer, 0);
}

extern f64 D_8075A558;

void func_8065D254(Actor*, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);

void func_806A18A8(void) {
    A178_806A18A8 *sp44;
    Actor *sp40;

    sp44 = current_actor_pointer->a178_806A18A8;
    sp40 = current_actor_pointer->unk11C;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80724CA4(2, 2);
    }
    func_8067B238(current_actor_pointer, sp40, 0.15f);
    if (current_actor_pointer->control_state != 0) {
        func_806B6600(1);
        if (sp44->unk1 == 0) {
            current_actor_pointer->control_state = 0;
        }
    }
    if (sp40->unkB8 != 0.0f) {
        if ((sp40->unkB8 > 50.0f) && (current_actor_pointer->animation_state->unk64 != 0x233)) {
            func_80614EBC(current_actor_pointer, 0x233);
        } else if ((sp40->unkB8 <= 50.0f) && (current_actor_pointer->animation_state->unk64 != 0x232)) {
            func_80614EBC(current_actor_pointer, 0x232);
        }
        func_80614D00(current_actor_pointer, sp40->unkB8 * D_8075A558, 4.0f);
    } else if (current_actor_pointer->animation_state->unk64 != 0x234) {
        func_80614EBC(current_actor_pointer, 0x234);
    }
    func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0x12C, 0xC8, 0, 1.0f);
    func_806319C4(current_actor_pointer, 0);
}

void func_806A1ABC(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A1AC4.s")

extern f32 D_8075A560;
extern f64 D_8075A568;
extern s32 D_8071FFA0;

void func_807248B0(Actor*, f32);

/*
// TODO: Very close, something iffy with the loop and our stack is too small
void func_806A1AC4(void) {
    s32 *sp40;
    f32 dx;
    f32 temp_f20;
    f32 dz;
    f64 temp_f22;
    s16 i;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        func_80728950(0);
        func_807248B0(current_actor_pointer, 1.2f);
        current_actor_pointer->object_properties_bitfield |= 0x400;
        current_actor_pointer->draw_distance = 1000;
        if (isFlagSet(0xFB, FLAG_TYPE_PERMANENT) != 0) {
            func_80613C48(current_actor_pointer, 0x597, 0, 0);
            func_807289B0(0, 0);
            current_actor_pointer->control_state = 3;
        } else {
            func_80613C48(current_actor_pointer, 0x598, 0, 0);
            func_80614D00(current_actor_pointer, 0, 0);
            current_actor_pointer->noclip_byte = 1;
            current_actor_pointer->object_properties_bitfield &= ~4;
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if ((D_807FBB70.unk254 != 0) && (D_807FBB70.unk258 == 1)) {
                func_8070DA74(current_actor_pointer);
                func_8070D8C0(current_actor_pointer, 0x1F, 1);
                playCutscene(current_actor_pointer, 0x12, 1);
                setFlag(0xFB, TRUE, FLAG_TYPE_PERMANENT);
                current_actor_pointer->control_state = 1;
            } else if ((isFlagSet(0xFB, FLAG_TYPE_PERMANENT) == FALSE) && (isFlagSet(0x21, FLAG_TYPE_TEMPORARY) == FALSE)) {
                dx = current_actor_pointer->x_position - player_pointer->x_position;
                dz = current_actor_pointer->z_position - player_pointer->z_position;
                if (((dx * dx) + (dz * dz)) < D_8075A560) {
                    func_8070D8C0(player_pointer, 0x1F, 0);
                    setFlag(0x21, 1, 2);
                }
            }
            break;
        case 1:
            if ((D_807FBB70.unk254 != 0) && (D_807FBB70.unk258 == 1)) {
                func_80614EBC(current_actor_pointer, 0x328);
                current_actor_pointer->control_state = 2;
                current_actor_pointer->noclip_byte = 2;
                current_actor_pointer->object_properties_bitfield |= 4;
            }
            break;
        case 2:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    // TODO: Issue is here, not sure what's going on
                    i = 0;
                    if ((object_timer & 7) == 0) {
                        temp_f22 = D_8075A568;
                        sp40 = &D_8071FFA0;
                        while (i < 0xC) {
                            temp_f20 = ((((rand() >> 0xF) % 32767) % 171) + 0x96) * temp_f22;
                            func_8071498C(&func_8071E864);
                            func_80714950(i);
                            func_807149B8(1);
                            func_807149C8(0x8C, 0x8C, 0x8C, 0xFF);
                            func_80714998(5);
                            func_80714CC0(sp40, temp_f20, current_actor_pointer->x_position, current_actor_pointer->y_position + 50.0f, current_actor_pointer->z_position);
                            i++;
                        }
                    }
                    break;
                case 2:
                    func_807289B0(0, 0);
                    current_actor_pointer->control_state_progress += 1;
                    break;
                case 4:
                    func_807289B0(0, 2);
                    current_actor_pointer->control_state_progress += 1;
                    break;
                case 6:
                    func_807289B0(0, 0);
                    current_actor_pointer->control_state += 1;
                    break;
            }
            break;
        case 3:
            func_8072881C(0, &current_actor_pointer->unkEC);
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

void func_806A1F28(void) {
    current_actor_pointer->object_properties_bitfield |= 0x400;
    func_806319C4(current_actor_pointer, 0);
}

void func_806A1F64(void) {
    if (func_8061CB50()) {
        func_80613C48(current_actor_pointer, 0x640, 0, 8.0f);
    } else {
        func_80613C48(current_actor_pointer, 0x63F, 0, 8.0f);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806A1FD0(void) {

}

extern s32 D_8071FF18;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} AAD_806A1FD8;

void func_806A5DF0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6, Actor *arg7);

void func_806A1FD8(void) {
    s32 var_v1;
    AAD_806A1FD8 *aaD;
    s32 i;
    u8 var_a1;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    Actor *temp_s0;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk64 |= 8;
        aaD->unk0 = 0;
        aaD->unk4 = 0.0f;
        aaD->unk8 = current_actor_pointer->y_position;
        current_actor_pointer->unk130 = 0x46;
        current_actor_pointer->unk131 = 0x14;
        if (isFlagSet(func_80688C30(func_80688E68(current_actor_pointer)), FLAG_TYPE_PERMANENT) != 0) {
            func_806782C0(current_actor_pointer);
        }
    }
    if ((player_pointer->control_state == 0x2D) && (player_pointer->control_state_progress != 0)) {
        var_a1 = FALSE;
        if (current_actor_pointer->unk114 != NULL) {
            var_v1 = current_actor_pointer->unk114->unk10;
            i = 0;
            while (var_v1 != 0 && !var_a1) {
                temp_s0 = current_actor_pointer->unk114->unk0[i];
                if ((func_8067AF44(temp_s0) != 0) && (temp_s0 == player_pointer)) {
                    var_a1 = TRUE;
                }
                var_v1--;
                i++;
            }
        }
        if (var_a1 && aaD->unk0 == 0) {
            for (i = 1; i < 9; i++) {
                func_80714998(2);
                func_807149B8(1);
                func_8071498C(&func_80717D4C);
                func_80714950(-0x64);
                func_807149C8(0x64, 0x46, 0x1E, 0xFF);
                func_80671C0C(current_actor_pointer, i, &sp54, &sp50, &sp4C);
                func_80714CC0(&D_8071FF18, 2.0f, sp54, sp50 + 10.0, sp4C);
            }
            aaD->unk0 = 0xF;
            func_80608528(current_actor_pointer, 0x1C1, 0xFF, 0x7F, 1);
        }
    }
    if (aaD->unk0 >= 2) {
        aaD->unk0--;
    }
    if (aaD->unk0 == 2) {
        func_806A5DF0(0x8C,
            current_actor_pointer->x_position,
            current_actor_pointer->y_position + 10.0f,
            current_actor_pointer->z_position,
            0,
            1,
            func_80688C30(func_80688E68(current_actor_pointer)),
            0
        );
    }
    if ((aaD->unk0 < 0xA) && (aaD->unk0 != 0)) {
        aaD->unk4 = aaD->unk4 + 1.0;
        if (aaD->unk4 > 20.0) {
            playSong(0x90, 1.0f);
            func_806782C0(current_actor_pointer);
        }
    }
    current_actor_pointer->y_position -= aaD->unk4;
    func_806319C4(current_actor_pointer, 0);
    current_actor_pointer->y_position = aaD->unk8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A6280/func_806A2328.s")

void func_806A285C(void) {
    s16 spBE;
    s16 spBC;
    f32 sp7C[4][4];
    f32 sp3C[4][4];

    func_80699070(&spBE, &spBC, character_change_array[0].look_at_eye_x, character_change_array[0].look_at_eye_y, character_change_array[0].look_at_eye_z, character_change_array[0].look_at_at_x, character_change_array[0].look_at_at_y, character_change_array[0].look_at_at_z);
    current_actor_pointer->y_rotation = spBC;
    current_actor_pointer->z_rotation = spBE;
    guRotateF(&sp7C, (spBE / D_8075A588) * D_8075A590, 1.0f, 0.0f, 0.0f);
    guRotateF(&sp3C, (spBC / D_8075A598) * D_8075A5A0, 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp7C, &sp3C, &sp7C);
    guTranslateF(&sp3C, character_change_array[0].look_at_eye_x, character_change_array[0].look_at_eye_y, character_change_array[0].look_at_eye_z);
    guMtxCatF(&sp7C, &sp3C, &sp7C);
    guMtxXFMF(&sp7C, 0.0f, 0.0f, -11.0f, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    guTranslateF(&current_actor_pointer->unkC, 0.0f, -20.0f, 0.0f);
    func_806319C4(current_actor_pointer, 1);
}
