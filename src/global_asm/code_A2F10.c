#include <ultra64.h>
#include "functions.h"

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069E210.s")

void func_806A5DF0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6, Actor *arg7);

void func_8069E490(u16 arg0, s16 arg1) {
    func_806A5DF0(arg0, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, arg1, current_actor_pointer);
}

extern u16 D_807FBB34;

void func_8069E4E0(s16 arg0) {
    Actor *temp_a1;
    s16 i;

    for (i = 0; i < D_807FBB34; i++) {
        temp_a1 = D_807FB930[i].unk0;
        if (current_actor_pointer == temp_a1->unk11C) {
            func_8067A70C(current_actor_pointer, temp_a1, current_actor_pointer->x_position, current_actor_pointer->y_position + arg0, current_actor_pointer->z_position, 2, 1);
        }
    }
}

void func_8069E5B8(void) {
    Actor *temp_a0;
    s16 phi_s0;

    for (phi_s0 = 0; phi_s0 < D_807FBB34; phi_s0++) {
        temp_a0 = D_807FB930[phi_s0].unk0;
        if (current_actor_pointer == temp_a0->unk11C) {
            func_80679200(temp_a0, current_actor_pointer, 0x02000000, 1, 0, 0);
        }
    }
}

// TODO: Yikes, needs a dx dz macro or something...
int func_8069E660(Actor *arg0, f32 arg1, f32 arg2) {
    return (arg0->y_position - 8.0f) <= current_actor_pointer->y_position
        && current_actor_pointer->y_position < (arg0->y_position + arg1)
        && ((((arg0->x_position - current_actor_pointer->x_position) * (arg0->x_position - current_actor_pointer->x_position)) + ((arg0->z_position - current_actor_pointer->z_position) * (arg0->z_position - current_actor_pointer->z_position))) < arg2)
        && (arg0->noclip_byte != 1);
}

// Jumptable, a fun one though
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069E724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069E774.s")

extern u8 D_80750AB8;
extern f64 D_8075A498;
extern f64 D_8075A4A0;
extern f64 D_8075A4A8;
extern f64 D_8075A4B0;
extern f64 D_8075A4B8;
extern f64 D_8075A4C0;

// TODO: Add to aaD union
typedef struct {
    f32 unk0; // Used
    f32 unk4;
    f32 unk8;
    u16 unkC; // Used
    u16 unkE;
    u8 unk10; // Used
    u8 unk11; // Used
    u8 unk12; // Used
} AAD_8069E774;

void func_8066E8E4(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
f32 func_8066E9EC(Actor *arg0, s32 arg1, f32 arg2);
void func_8066EB40(Actor *arg0, f32 arg1);
void func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
void func_8066E5F8(s32 arg0, s32 arg1, u8 arg2);

/*
// TODO: Doable, great progress made
void func_8069E774(void) {
    u16 sp8E;
    f32 sp88;
    u8 sp87;
    PlayerAdditionalActorData *PaaD;
    u8 sp7F;
    Actor *sp78;
    s32 *sp74;
    AAD_8069E774 *var_t0;
    s32 playerIndex;
    Actor *player;
    PlayerAdditionalActorData *pad;
    s32 sp60;

    sp8E = 300;
    sp87 = 0;
    sp7F = 0;
    var_t0 = current_actor_pointer->additional_actor_data;
    if ((current_actor_pointer->unk11C != NULL) && (current_actor_pointer->unk11C->interactable & 1)) {
        sp78 = current_actor_pointer->unk11C;
        sp7F = 1;
    } else {
        sp78 = player_pointer;
    }
    PaaD = sp78->additional_actor_data;
    if ((cc_number_of_players >= 2) && (D_80750AB8 == 1)) {
        pad = player_pointer->PaaD;
        sp74 = &pad->unk1F0;
    } else {
        sp74 = &PaaD->unk1F0;
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        var_t0->unkC = sp78->ledge_info_pointer->unk14;
        current_actor_pointer->draw_distance = 1000;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_8068842C(current_actor_pointer, 0, 1);
        func_80688370(current_actor_pointer, 0, 1.0f);
        func_80688460(current_actor_pointer, 0, 1);
        *sp74 |= 0x02000000;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        switch (func_80613448(current_actor_pointer)) {
            case 0xAD:
                var_t0->unk10 = 0xFF;
                var_t0->unk11 = 0xFF;
                var_t0->unk12 = 0x32;
                break;
            case 0xAE:
                var_t0->unk10 = 0xFF;
                var_t0->unk11 = 0x32;
                var_t0->unk12 = 0x32;
                break;
            case 0xD1:
                var_t0->unk10 = 0xCA;
                var_t0->unk11 = 0x5B;
                var_t0->unk12 = 0xFF;
                break;
            case 0xD0:
                var_t0->unk10 = 0;
                var_t0->unk11 = 0x96;
                var_t0->unk12 = 0xFF;
                break;
            case 0xCF:
                var_t0->unk10 = 0x32;
                var_t0->unk11 = 0xFF;
                var_t0->unk12 = 0x32;
                break;
        }
        if (sp7F != 0) {
            var_t0->unk0 = 2.0f;
        } else {
            var_t0->unk0 = 1.5f;
        }
        if (current_actor_pointer->unk15F != 0) {
            func_8066E8E4(current_actor_pointer, 0, 0, 0, 1.0f, 0);
        }
    }
    if (func_8061CB50() != 0) {
        func_8061F0B0(PaaD->unk104, 0xA, 0xA);
    }
    current_actor_pointer->animation_state->scale_x *= current_actor_pointer->unk160;
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->animation_state->scale_y *= D_8075A498;
    current_actor_pointer->animation_state->scale_y += (D_8075A4A0 * func_80612794(current_actor_pointer->unkEE));
    current_actor_pointer->unkEE += 0x1F4;
    current_actor_pointer->y_rotation += 0x32;
    current_actor_pointer->control_state += 1;
    // ./diff.sh 0xA3800
    // TODO: v0 v1 regalloc here
    if (current_actor_pointer->control_state == current_actor_pointer->unk168) {
        func_80688460(current_actor_pointer, 0, 0);
    } else if (current_actor_pointer->unk168 < current_actor_pointer->control_state) {
        sp8E = 300 - ((current_actor_pointer->control_state - current_actor_pointer->unk168) * 40);
        if (func_80688540(current_actor_pointer, 0) == 0) {
            sp87 = 1;
            *sp74 &= 0xFDFFFFFF;
            func_8066EB40(sp78, var_t0->unkC);
            func_8066E9EC(sp78, func_8069E724(sp78->unk58), 0.0f);
            func_806782C0(current_actor_pointer);
        }
    }
    func_806595F0(1);
    func_8065A708(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, 0, current_actor_pointer->animation_state->scale_x * sp8E * var_t0->unk0, 0, var_t0->unk10, var_t0->unk11, var_t0->unk12);
    if (current_map != MAP_DK_RAP) {
        if ((sp7F == 0) || (current_actor_pointer->unk15F != 0)) {
            sp60 = 0x2E;
            if (func_80714608(0) != 0) {
                sp60 = 0xE;
            }
            sp88 = current_actor_pointer->animation_state->scale_x * sp8E;
            sp88 *= sp88;
            for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
                player = character_change_array[playerIndex].player_pointer;
                if ((sp7F == 0) || ((playerIndex != PaaD->unk1A4) && (player->control_state != 0x84))) {
                    if (func_8069E660(player, player->unk15E, sp88) != 0) {
                        func_806EB0C0(sp60, current_actor_pointer, playerIndex);
                    }
                }
            }
            if (current_actor_pointer->unk15F != 0) {
                func_8066EB40(current_actor_pointer, 2.0 * ((current_actor_pointer->animation_state->scale_x * sp8E) * D_8075A4A8));
                func_8066E9EC(current_actor_pointer, 1, (current_actor_pointer->animation_state->scale_x * sp8E) * D_8075A4B0);
            }
        } else if (sp87 == 0) {
            func_8066EB40(current_actor_pointer->unk11C, 2.0 * ((current_actor_pointer->animation_state->scale_x * sp8E) * D_8075A4B8));
            func_8066E9EC(current_actor_pointer->unk11C, func_8069E724(sp78->unk58), (current_actor_pointer->animation_state->scale_x * sp8E) * D_8075A4C0);
            func_8066E5F8(sp78, func_8069E724(sp78->unk58), 3);
        }
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

s32 func_8069EF50(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 dx = player_pointer->x_position - arg0;
    f32 dz = player_pointer->z_position - arg2;

    if (((dx * dx) + (dz * dz)) < (arg4 * arg4)) {
        if ((arg1 <= player_pointer->y_position) && (player_pointer->y_position < (arg1 + arg3))) {
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069F020.s")

extern f64 D_8075A4C8;
extern s32 D_807FBB68;

GlobalASMStruct60 *func_80688584(Actor*, s32);

/*
// TODO: Doable, good progress made
// Something sus going on with the big function call
// Something sus going on with gotos
// Something sus going on with missing logic in some if statements
void func_8069F020(void) {
    u8 sp67;
    u16 sp64;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 var_f0;
    f32 var_f0_2;

    sp67 = current_actor_pointer->unkF0 == 0xBB ? 0x28 : 0x23;
    sp64 = current_actor_pointer->unkF0 == 0x6A ? 0x78 : 0x190;
    if (is_cutscene_active == 1) {
        func_806782C0(current_actor_pointer);
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 1000;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_8068842C(current_actor_pointer, 0, 1);
        func_80688370(current_actor_pointer, 0, 0.5f);
        func_80688460(current_actor_pointer, 0, 1);
        current_actor_pointer->unkEE = 0x3C;
    }
    if (current_actor_pointer->unk168 != 0) {
        var_f0 = 1.0f;
        if (current_actor_pointer->unkEE < 0x1E) {
            var_f0 = current_actor_pointer->unkEE / 30.0;
        }
        func_806595F0(1);
        if (current_actor_pointer->unk16A < 0) {
            // TODO: Hmm
        }
        if (current_actor_pointer->unk16B < 0) {
            // TODO: Hmm
        }
        // TODO: Missing args here
        func_8065A708(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, 0, 300.0f, 0, 0, 0, current_actor_pointer->unk16C * var_f0);
        current_actor_pointer->animation_state->scale_x *= current_actor_pointer->unk160;
        current_actor_pointer->animation_state->scale_z *= current_actor_pointer->unk160;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (current_actor_pointer->unk168 == 0) {
                current_actor_pointer->animation_state->scale_x *= current_actor_pointer->unk160;
                current_actor_pointer->animation_state->scale_z *= current_actor_pointer->unk160;
            }
            if ((current_actor_pointer->animation_state->unk0->unk24 == 0.0f) || (current_actor_pointer->animation_state->unk0->unk4 > 5.0f)) {
                current_actor_pointer->control_state = 1;
                func_80688460(current_actor_pointer, 0, 0);
            }
            break;
        case 1:
            if (current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
                if (func_80688584(current_actor_pointer, 0)->unkC < 0xE) {
                    goto block_33;
                }
                goto block_34;
            }
    block_33:
            if (current_actor_pointer->animation_state->unk0->unk4 > 9.0f) {
    block_34:
                current_actor_pointer->control_state = 2;
                if ((current_actor_pointer->unk15F != 0) && (func_80677FA8(ACTOR_BOSS_SHOCKWAVE, current_actor_pointer->unkF0) != 0)) {
                    if (current_actor_pointer->animation_state->unk0->unk4 > 9.0f) {
                        func_80613C48(D_807FBB44, 0x4F9, 0.0f, 0.0f);
                        func_80614D00(D_807FBB44, current_actor_pointer->animation_state->unk48, 0);
                    }
                    func_8067B238(D_807FBB44, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
                    D_807FBB44->unkF0 = current_actor_pointer->unkF0;
                    D_807FBB44->animation_state->scale_x = current_actor_pointer->animation_state->scale_x + D_8075A4C8;
                    D_807FBB44->animation_state->scale_z = current_actor_pointer->animation_state->scale_z + D_8075A4C8;
                    D_807FBB44->unk15F = current_actor_pointer->unk15F - 1;
                    D_807FBB44->unk160 = current_actor_pointer->unk160;
                }
            }
            break;
        case 2:
            if (func_80688540(current_actor_pointer, 0) == 0) {
                current_actor_pointer->control_state = 3;
                if (current_actor_pointer->unk168 != 0) {
                    current_actor_pointer->object_properties_bitfield &= ~4;
                } else {
                    func_806782C0(current_actor_pointer);
                }
            }
            break;
        case 3:
            current_actor_pointer->unkEE -= 1;
            if (current_actor_pointer->unkEE == 0) {
                func_806782C0(current_actor_pointer);
            }
            break;
    }
    if ((current_actor_pointer->unkF0 != 0x6A) && !(D_807FBB68 & 2)) {
        if ((current_actor_pointer->object_properties_bitfield & 4) && (current_actor_pointer->object_properties_bitfield & 0x10)) {
            sp50 = current_actor_pointer->y_position;
            func_80671C0C(current_actor_pointer, 1, &sp5C, &sp58, &sp54);
            sp58 += 50.0f;
            if (func_80667110(sp5C, sp54, &sp58) != 0) {
                if (sp58 < sp50) {
                    var_f0_2 = sp50 - sp58;
                } else {
                    var_f0_2 = sp58 - sp50;
                }
                if ((var_f0_2 < 40.0f) || !(current_actor_pointer->object_properties_bitfield & 0x10)) {
                    current_actor_pointer->y_position = sp58;
                }
            }
        }
    }
    if ((current_actor_pointer->unk168 == 0) || (current_actor_pointer->control_state != 3)) {
        if ((func_8069EF50(current_actor_pointer->x_position, current_actor_pointer->y_position - 20.0f, current_actor_pointer->z_position, sp67, current_actor_pointer->animation_state->scale_x * sp64) != 0)
         && (func_8069EF50(current_actor_pointer->x_position, current_actor_pointer->y_position - 20.0f, current_actor_pointer->z_position, sp67, current_actor_pointer->animation_state->scale_x * (sp64 - 0x14)) == 0)) {
            func_806EB0C0(0x2E, current_actor_pointer, 0);
        }
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069F904.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069FA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_8069FDA0.s")

extern s32 D_80744478;
extern u8 D_80750AD4;
void func_8069F904(void);
void func_8069FA40(void);

/*
void func_8069FDA0(void) {
    s16 sp22;
    f32 temp_f12;
    f64 temp_f2;
    s32 temp_v1;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEE = current_actor_pointer->unk160;
    }
    temp_f2 = D_80744478 * 0.5;
    if (temp_f2 < current_actor_pointer->unk160) {
        current_actor_pointer->unk160 = current_actor_pointer->unk160 - temp_f2;
        temp_f12 = current_actor_pointer->unk160 / current_actor_pointer->unkEE;
        current_actor_pointer->unkE0 = (temp_f12 * -8.0) + 12.0;
        current_actor_pointer->y_rotation = 255.0f * temp_f12;
        if ((current_actor_pointer->unk15F >= 0x14) && (current_actor_pointer->unk15F < 0x1E)) {
            func_8068C350(&func_8069F904, current_actor_pointer, 3);
        } else {
            func_8068C350(&func_8069FA40, current_actor_pointer, 3);
        }
        if ((current_actor_pointer->unk15F == 0) && (current_actor_pointer->unk160 == 3)) {
            func_80677FA8(ACTOR_TEXT_OVERLAY, 0);
            D_807FBB44->unk160 = current_actor_pointer->unkEE;
            D_807FBB44->unk15F = D_80750AD4;
            D_807FBB44->y_position = 80.0f;
            D_807FBB44->x_position = 640.0f;
            playSound(D_80750AD4 + 0x3F3, 0x7FFF, 63.0f, 1.0f, 0, 0);
            return;
        }
        if ((current_actor_pointer->unk15F >= 0x1E) && (current_actor_pointer->unk15F < 0x25) && (current_actor_pointer->unk160 == 5)) {
            func_80677FA8(ACTOR_TEXT_OVERLAY, 0);
            D_807FBB44->unk160 = current_actor_pointer->unkEE;
            if (current_actor_pointer->unk15F == 0x23) {
                D_807FBB44->unk15F = 0x24;
            } else if (current_actor_pointer->unk15F == 0x24) {
                D_807FBB44->unk15F = 0x25;
            } else {
                D_807FBB44->unk15F = 0x26;
            }
            D_807FBB44->y_position = 80.0f;
            D_807FBB44->x_position = 500.0f;
        }
    } else {
        temp_v1 = current_actor_pointer->unk15F & 0x3F;
        if ((current_actor_pointer->unk15F & 0xC0) && (temp_v1 != 0)) {
            sp22 = 0x3FC - temp_v1;
            func_80677FA8(ACTOR_TEXT_OVERLAY, 0);
            D_807FBB44->unk160 = current_actor_pointer->unkEE;
            D_807FBB44->unk15F = ((current_actor_pointer->unk15F & 0xC0) + (current_actor_pointer->unk15F & 0x3F)) - 1;
            if (current_actor_pointer->unk15F & 0x80) {
                sp22 += 2;
            }
            playSound(sp22, 0x7FFF, 63.0f, 1.0f, 0, 0);
            D_807FBB44->y_position = 80.0f;
            D_807FBB44->x_position = 600.0f;
        }
        func_806782C0(current_actor_pointer);
    }
}
*/

extern f32 D_80750394;

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_806A018C;

void func_806A018C(void) {
    AAD_806A018C *temp_s1;

    temp_s1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk0;
        current_actor_pointer->unkEE = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 1;
        temp_s1->unk0 = (rand() >> 0xF) % 70;
        temp_s1->unk4 = (rand() >> 0xF) % 200;
    }
    func_8067ACB4(current_actor_pointer);
    func_806651FC(current_actor_pointer);
    func_80665564(current_actor_pointer, 0);
    current_actor_pointer->y_velocity += D_80750394;
    current_actor_pointer->z_rotation += temp_s1->unk4;
    current_actor_pointer->x_rotation += temp_s1->unk0;
    if ((current_actor_pointer->unkFC != 0) || ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1))) {
        func_806782C0(current_actor_pointer);
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806A02F0(void) {
    func_806A018C();
}

void func_806A0310(void) {
    func_806A018C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A0330.s")

extern s32 D_807F5D10;
extern f32 D_80750398;
extern f32 D_8075A504;
extern f32 D_8075A508;
extern u8 D_807FBD70;
extern s32 D_8071BB14;
extern s32 D_80720BE8;

void func_8065D254(Actor*, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);

/*
void func_806A0330(void) {
    f32 sp68;
    f32 sp64;
    f32 sp60;
    s32 var_s0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x1C;
        current_actor_pointer->y_velocity = 0.0f;
        current_actor_pointer->draw_distance = 2000;
        current_actor_pointer->floor = D_8075A504;
        func_80665564(current_actor_pointer, 0.0f);
    }
    if (func_8061CB50() != 0) {
        current_actor_pointer->unk132 = 2;
    } else {
        current_actor_pointer->unk132 = 1;
    }
    func_8067ACB4(current_actor_pointer);
    func_806651FC(current_actor_pointer);
    func_80665564(current_actor_pointer, 0.0f);
    current_actor_pointer->y_velocity += D_80750398;
    if (D_8075A508 != current_actor_pointer->floor) {
        func_8065D244(1);
        func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x18, 0x18, 1, 0x96, 0xB4, 0, 1.0f);
    } else {
        func_806782C0(current_actor_pointer);
    }
    if ((D_807FBD70 == 4) || (current_actor_pointer->unkFC != 0) || ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1))) {
        func_8061F0B0(D_807F5D10, 0xF, 0xF);
        func_80608528(current_actor_pointer, 0x162, 0xE1, 0x3C, 1);
        var_s0 = 1;
        do {
            func_80671C0C(current_actor_pointer, var_s0, &sp68, &sp64, &sp60);
            func_8071496C(var_s0);
            func_807149B8(1);
            func_8071498C(&D_8071BB14);
            func_807149C8(0xFF, 0xFF, 0xFF, 0x96);
            func_80714CC0(&D_80720BE8, 1.5f, sp68, sp64, sp60);
            var_s0 += 1;
        } while (var_s0 != 7);
        func_806782C0(current_actor_pointer);
    }
    func_806319C4(current_actor_pointer, 0, current_actor_pointer);
}
*/

void func_806A05D4(void) {
    func_806319C4(current_actor_pointer, 0);
}

extern f64 D_8075A510;
extern f64 D_8075A518;
extern f64 D_8075A520;
extern f64 D_8075A528;
extern f64 D_8075A530;
extern f64 D_8075A538;

typedef struct {
    s8 unk0[0x200 - 0x0];
    s16 unk200;
} AAD_806A05FC;

void func_806A05FC(void) {
    ActorAnimationState *temp_v0;
    f64 temp_f0;
    s32 var_v0_2;
    s32 var_v0_3;
    AAD_806A05FC *temp_a3;

    temp_a3 = current_actor_pointer->unk11C->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->shadow_opacity = 0xFF;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        current_actor_pointer->unk160 = current_actor_pointer->unk11C->unk15E * D_8075A510 * D_8075A518;
    }
    current_actor_pointer->x_position = current_actor_pointer->unk11C->x_position;
    current_actor_pointer->y_position = current_actor_pointer->unk11C->y_position;
    current_actor_pointer->z_position = current_actor_pointer->unk11C->z_position;
    if (current_actor_pointer->shadow_opacity & 8) {
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale_x = (((current_actor_pointer->unk160 * D_8075A520) - temp_v0->scale_x) * D_8075A528) + temp_v0->scale_x;
    } else {
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale_x = (((current_actor_pointer->unk160 * D_8075A530) - temp_v0->scale_x) * D_8075A538) + temp_v0->scale_x;
    }
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    if (temp_a3->unk200 > 0) {
        var_v0_2 = temp_a3->unk200;
    } else {
        var_v0_2 = 0;
    }
    if (var_v0_2 < 0xFF) {
        if (temp_a3->unk200 > 0) {
            var_v0_3 = temp_a3->unk200;
        } else {
            var_v0_3 = 0;
        }
        current_actor_pointer->shadow_opacity = var_v0_3;
    } else {
        current_actor_pointer->shadow_opacity = 0xFF;
    }
    if ((current_actor_pointer->shadow_opacity == 0) || (current_actor_pointer->unk11C->control_state != 0x7C)) {
        func_806782C0(current_actor_pointer);
        return;
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806A081C(Actor *arg0) {
    func_80677FA8(ACTOR_KONG_REFLECTION, func_80613448(arg0));
    D_807FBB44->unk11C = arg0;
    arg0->unk6A |=  0x800;
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A0864.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A0B74.s")

void func_806A0F78(Actor *arg0, u8 arg1, u8 arg2) {
    func_8068842C(arg0, 0, 1);
    func_80688460(arg0, 0, 1);
    func_806883F4(arg0, 0, arg1, 0.0f);
    func_8068842C(arg0, 1, 1);
    func_80688460(arg0, 1, 1);
    func_806883F4(arg0, 1, arg2, 0.0f);
}

extern u16 D_807FBB34;

void func_806A1008(u8 arg0, u8 arg1) {
    Actor *temp_a0;
    s16 var_v0;

    for (var_v0 = 0; var_v0 < D_807FBB34; var_v0++) {
        temp_a0 = D_807FB930[var_v0].unk0;
        if (temp_a0->unk58 == ACTOR_ROPE && (temp_a0->unk15F / 3) == arg0) {
            temp_a0->control_state = arg1;
            temp_a0->control_state_progress = 0;
        }
    }
}

// AnimationState->unk24
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A10BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_806A112C.s")

extern u8 D_807503D4;
extern u8 D_807503E0;
extern f64 D_8075A540;

/*
// TODO: Pretty close, need some structs
void func_806A112C(void) {
    f32 sp38;
    f32 temp_f20;
    s16 var_s0_3;
    s32 temp_v0_2;
    s32 var_s2;
    s8 var_s0_2;
    u32 temp_v0;
    u8 temp_v0_3;
    void *temp_a1;
    void *temp_a2;
    void *temp_s5;

    temp_v0 = current_actor_pointer->object_properties_bitfield;
    temp_s5 = current_actor_pointer->additional_actor_data;
    if (!(temp_v0 & 0x10)) {
        current_actor_pointer->object_properties_bitfield = temp_v0 | 0x400;
        func_80724D28(0, 7);
        var_s0_2 = 0;
        do {
            temp_v0_2 = var_s0_2 * 0x10;
            *(current_actor_pointer->animation_state->unk24 + temp_v0_2) = var_s0_2;
            var_s0_2 = var_s0_2 + 1;
            (current_actor_pointer->animation_state->unk24 + temp_v0_2)->unk1 = 0xFF;
        } while (var_s0_2 < 7);
        if (current_actor_pointer->unk15F == 0) {
            sp38 = current_actor_pointer->animation_state->scale_y / D_8075A540;
            *temp_s5 = getPointerTableFile(0x13, 6, 1, 1);
            var_s2 = 1;
            func_806A0F78(current_actor_pointer, D_807503D4, D_807503E0);
            temp_f20 = 75.0f * sp38;
            var_s0_3 = 1;
            do {
                func_80677FA8(ACTOR_ROPE, 0xE1);
                *D_807FBB44->additional_actor_data = *temp_s5;
                D_807FBB44->unk15F = var_s0_3;
                D_807FBB44->y_rotation = current_actor_pointer->y_rotation + ((var_s0_3 / 3) << 0xA);
                D_807FBB44->x_position = current_actor_pointer->x_position - (func_80612794(D_807FBB44->y_rotation) * temp_f20);
                D_807FBB44->y_position = current_actor_pointer->y_position + (((var_s0_3 % 3) & 0xFF) * 0x11);
                D_807FBB44->z_position = current_actor_pointer->z_position - (func_80612790(D_807FBB44->y_rotation) * temp_f20);
                func_807248B0(D_807FBB44, current_actor_pointer->animation_state->scale_y);
                temp_a2 = var_s2 + 0x80750000;
                temp_a1 = var_s2 + 0x80750000;
                var_s2 = (var_s2 + 1) & 0xFF;
                func_806A0F78(D_807FBB44, temp_a1->unk3D4, temp_a2->unk3E0);
                var_s0_3 += 1;
            } while (var_s0_3 < 0xC);
            current_actor_pointer->x_position -= temp_f20 * func_80612794(current_actor_pointer->y_rotation);
            current_actor_pointer->z_position -= temp_f20 * func_80612790(current_actor_pointer->y_rotation);
        }
    }
    switch (current_actor_pointer->control_state) {
        case 1:
            current_actor_pointer->unk168 += 1;
            if (current_actor_pointer->unk168 == 7) {
                current_actor_pointer->control_state += 1;
                current_actor_pointer->unk168 = 0;
            }
            break;
        case 2:
            func_806A10BC(temp_s5);
            current_actor_pointer->unk168 += 1;
            if (current_actor_pointer->unk168 == 0xB) {
                current_actor_pointer->control_state += 1;
            }
            break;
        case 3:
            func_806A10BC(temp_s5);
            current_actor_pointer->unk168 += 1;
            if (current_actor_pointer->unk168 >= 0x34) {
                current_actor_pointer->unk168 = ((rand() >> 0xF) % 1000) % 3;
                current_actor_pointer->control_state = 0;
            }
            break;
        case 10:
            current_actor_pointer->unk168 = 0xB;
            func_806A10BC(temp_s5);
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/
