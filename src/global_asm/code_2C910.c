#include <ultra64.h>
#include "functions.h"


const u8 D_global_asm_80757F70[] = {    
    0xFF,
    0xFF,
    0xFF,
    0xC8,
    0x00,
    0x32,
    0xDC,
    0xC8,
    0x00,
    0x32,
    0xC8,
    0x00,
    0xCA,
    0x5B,
    0xFF,
    0x00,
    0x96,
    0xFF,
    0x32,
    0x32,
    0xFA,
    0x00,
    0x00,
    0x00,
};

/*
const char D_global_asm_80757F88[] = ":";
const f64 D_global_asm_807580A8 = 0.01;
const f64 D_global_asm_807580B0 = 127.5;
const f64 D_global_asm_807580B8 = 255.0;
const f64 D_global_asm_807580C0 = 32767.0;
const f64 D_global_asm_807580C8 = 16383.5;
const f64 D_global_asm_807580D0 = 127.0;
const f64 D_global_asm_807580D8 = 255.0;
const f64 D_global_asm_807580E0 = 32767.0;
const f64 D_global_asm_807580E8 = 16383.5;
const f64 D_global_asm_807580F0 = 127.0;
const f64 D_global_asm_807580F8 = 255.0;
*/

void func_global_asm_80627C10(u8 arg0) {
    s32 index = arg0 * 3;
    last_spawned_actor->unk16A = D_global_asm_80757F70[index + 0];
    last_spawned_actor->unk16B = D_global_asm_80757F70[index + 1];
    last_spawned_actor->unk16C = D_global_asm_80757F70[index + 2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_global_asm_80627C5C.s")

/*
// Seems doable, struct on the stack?
void func_global_asm_80627C5C(s32 arg0, s16 arg1, u8 arg2) {
    ? sp98;
    ? sp58;
    ? sp44;
    s16 sp42;
    s32 sp38;
    void *sp34;
    ? *temp_v0;
    ? *var_s0;
    s16 temp_a3_2;
    s16 var_v1;
    s32 temp_a1;
    s32 temp_a3;

    temp_a3 = arg0 & 0xFF;
    temp_v0 = getTextString(1, temp_a3, 1, temp_a3);
    var_s0 = temp_v0;
    if (strchr(temp_v0, ':') != 0) {
        temp_a3_2 = func_dk64_boot_80002C74(var_s0, ":") + 1;
        sp42 = temp_a3_2;
        func_dk64_boot_80002A64(&sp44, var_s0, temp_a3_2, temp_a3_2);
        *(&sp44 + sp42) = 0;
        func_global_asm_8069D2AC(0xA, 0x14, 0x18, &sp44, 0, arg1, 0x32, 0x32);
        func_global_asm_80627C10(arg2);
        var_s0 += strlen(&sp44);
    }
    sp38 = arg1;
    if (getCenterOfString(6, var_s0) >= 0x12D) {
        temp_a1 = strlen(var_s0) / 2;
        var_v1 = temp_a1;
        if (*(temp_a1 + var_s0) != 0x20) {
            do {
                var_v1 -= 1;
            } while (*(var_v1 + var_s0) != 0x20);
        }
        sp34 = var_v1 + var_s0;
        sp42 = var_v1;
        func_dk64_boot_80002A64(&sp98, var_s0, var_v1);
        (sp + sp42)->unk98 = 0;
        func_dk64_boot_80002A64(&sp58, sp34 + 1, 0xFF);
        func_global_asm_8069D2AC(0, 0, 0xCD, &sp98, 0, sp38, 0x32, 0x32);
        func_global_asm_80627C10(arg2);
        func_global_asm_8069D2AC(0, 0, 0xD7, &sp58, 0, sp38, 0x32, 0x32);
        func_global_asm_80627C10(arg2);
        return;
    }
    func_global_asm_8069D2AC(0, 0, 0xCD, var_s0, 0, sp38, 0x32, 0x32);
    func_global_asm_80627C10(arg2);
}
*/

Actor *func_global_asm_80627EA8(s16 spawn_trigger) {
    Actor *actor;

    if (spawn_trigger) {
        actor = getSpawnerTiedActor(spawn_trigger, 0);
    }
    if (!spawn_trigger || !actor) {
        actor = player_pointer;
    }
    return actor;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_global_asm_80627F04.s")

/*
void func_critter_80028EE8(u8, s32, s16, u8, u16, u16);
void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_global_asm_8061421C(Actor *);
void func_global_asm_8061D968(u8, u8);
void func_global_asm_806C8E58(s16);
void func_global_asm_80713EB0(s16, s32, s32);
void func_global_asm_80721560(s16, s16, s16, u8, u8, u8);
void func_global_asm_807289E8(s16, s16, s16, s16);
s32 func_global_asm_8072E7DC(s16, Actor **);
void func_global_asm_80737924(SoundState *);
extern void *D_8076D1FC;
extern ? D_807F5D6C;
extern SoundState *D_807F5D70[];
extern s16 D_807F5D7C;
extern ? D_global_asm_807457E4;
extern ? D_global_asm_80747750;
extern s8 D_global_asm_8075536C;
extern s16 D_global_asm_8076AEF2;
extern void *D_global_asm_8076D1F8;
extern s32 D_global_asm_807FBB68;
extern f32 loading_zone_transition_speed;
extern s8 loading_zone_transition_type;

void func_global_asm_80627F04(s32 arg0, u32 arg1, u32 arg2) {
    s16 spA6;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    void *sp9C;
    Actor *sp98;
    Actor *sp94;
    Actor *sp90;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    s16 sp72;
    s32 sp48;
    s32 sp44;
    s32 sp3C;
    s32 sp38;
    Actor *temp_v0;
    Actor *temp_v0_2;
    Actor *temp_v0_3;
    Actor *temp_v0_4;
    Actor *temp_v0_5;
    Actor *temp_v0_6;
    Actor *temp_v0_8;
    Actor *var_v0_2;
    Actor *var_v1_2;
    Actor17C *temp_v1;
    Actor17C *temp_v1_3;
    AnimationStateUnk0 *temp_v0_7;
    f64 var_f0;
    f64 var_f0_2;
    f64 var_f0_3;
    f64 var_f0_4;
    f64 var_f2;
    f64 var_f2_2;
    s16 temp_v1_2;
    s16 var_v0_4;
    s16 var_v0_5;
    s16 var_v1;
    s16 var_v1_3;
    s32 temp_lo;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_6;
    u32 temp_a1;
    u32 temp_t2;
    u32 temp_t9;

    sp9C = player_pointer->additional_actor_data;
    func_global_asm_8072E7DC(0xC, &sp94);
    temp_a1 = arg1 >> 0x10;
    temp_t2 = arg2 >> 0x10;
    spA0 = (s16) temp_a1;
    temp_t9 = arg0 & 0xFF;
    sp44 = (s32) (s16) arg1;
    spA2 = (s16) arg1;
    sp3C = (s32) (s16) temp_t2;
    spA4 = (s16) temp_t2;
    sp38 = (s32) (s16) arg2;
    spA6 = (s16) arg2;
    switch (temp_t9) {
    case 0x45:
        func_global_asm_80726E60(2U, 0x40U);
        return;
    case 0x42:
        var_v0 = 0x5A;
        if (sp44 != 0) {
            var_v0 = sp44;
        }
        func_global_asm_80627C5C((s16) temp_a1 & 0xFF, (s16) var_v0, unksp3F);
        return;
    case 0x41:
        func_global_asm_805FF8F8();
        return;
    case 0x3D:
        func_global_asm_805FF378((enum map_e) D_global_asm_8076AEF2, 0);
        return;
    case 0x3E:
        func_global_asm_805FF378(MAP_DK_ISLES_OVERWORLD, 0xC);
        return;
    case 0x40:
        func_global_asm_807127F4(0);
        return;
    case 0x36:
        func_global_asm_806C8E58((s16) ((s16) temp_a1 + 2), temp_a1);
        func_global_asm_806F0C18(player_pointer);
        return;
    case 0x33:
        temp_v1 = func_global_asm_80627EA8((s16) temp_a1)->unk17C;
        temp_v1->unk30 = 0xFE;
        temp_v1->unk33 = (s8) sp44;
        temp_v1->unk22 = (s8) sp3C;
        temp_v1->unk31 = 1;
        temp_v1->unk32 = (s8) sp38;
        return;
    case 0x34:
        func_global_asm_80627EA8((s16) temp_a1)->unk17C->unk30 = 0xFF;
        return;
    case 0x0:
        sp9C->unk70 = (s16) player_pointer->y_rotation;
        sp9C->unk6C = (f32) (s16) temp_a1;
        sp9C->unk74 = (f32) sp44;
        setAction(0x17, NULL, 0U);
        return;
    case 0x1:
        func_critter_80028EE8((sp3C + 6) & 0xFF, 0, 0xC8, (s16) temp_a1 & 0xFF, 0, sp44 + 0x28, 0x64, 0xFF);
        return;
    case 0x2:
        sp9C->unk1F0 = (s32) (sp9C->unk1F0 | 8);
        return;
    case 0x3:
        sp9C->unk1F0 = (s32) (sp9C->unk1F0 & ~8);
        return;
    case 0x24:
        func_global_asm_80724994(1U, (s16) temp_a1, unksp46, unksp3E, (s16) sp38);
        return;
    case 0x5:
        func_global_asm_807271F4((s16) temp_a1, 0, 0, 0, 0, 0, 0);
        return;
    case 0x4:
        if ((s16) temp_a1 != 0) {
            func_global_asm_80724994(3U, (s16) temp_a1, unksp46, unksp3E, (s16) sp38);
            return;
        }
        if (sp44 == 2) {
            current_player->animation_state->unk0->unk10 = -1;
            playActorAnimation(current_player, (s32) *(&D_global_asm_80747750 + (sp3C * 2)));
            if (sp38 != 0) {
                func_global_asm_80614D00(current_player, (f32) ((f64) sp38 / 100.0), 0.0f);
                return;
            }
        }
    default:
        return;
    case 0x6:
        func_global_asm_8061CF90(getSpawnerTiedActor((s16) temp_a1, 0U), unksp46);
        return;
    case 0x7:
        func_global_asm_8061D968((s16) temp_a1 & 0xFF, unksp47);
        return;
    case 0x2D:
        func_global_asm_8061CF80((s16) temp_a1);
        return;
    case 0x2E:
        func_global_asm_80627EA8((s16) temp_a1)->unk15E = (u8) sp44;
        return;
    case 0x25:
        func_global_asm_806F397C(player_pointer, NULL, (s16) temp_a1, 0);
        return;
    case 0x26:
        func_global_asm_80641874((s16) temp_a1, unksp46);
        return;
    case 0x27:
        sp48 = (s32) unksp3F;
        func_global_asm_80656E58((s16) temp_a1, unksp46, 0U, unksp3F);
        func_global_asm_80656E58((s16) temp_a1, unksp46, 1U, unksp4B);
        func_global_asm_80656E58((s16) temp_a1, unksp46, 2U, unksp4B);
        func_global_asm_80656E58((s16) temp_a1, unksp46, 3U, unksp4B);
        return;
    case 0x8:
        func_global_asm_8061D934((s16) temp_a1 & 0xFF);
        return;
    case 0x2B:
        setIntroStoryPlaying((s16) temp_a1 & 0xFF);
        return;
    case 0x9:
        func_global_asm_8061DAAC((s16) temp_a1, unksp46, unksp3E);
        return;
    case 0x10:
        func_global_asm_8061F0B0(D_global_asm_807F5D10, unksp47, (s16) temp_a1 & 0xFFFF);
        return;
    case 0xA:
        if ((s16) temp_a1 != 0) {
            temp_v0 = getSpawnerTiedActor((s16) temp_a1, 0U);
            if (sp44 != 0) {
                temp_v0->object_properties_bitfield |= 4;
                return;
            }
            temp_v0->object_properties_bitfield &= ~4;
            return;
        }
        sp72 = 2;
        var_v0_2 = getSpawnerTiedActor(1, 0U);
        var_v1 = 2;
        if (var_v0_2 != NULL) {
            do {
                if (sp44 != 0) {
                    var_v0_2->object_properties_bitfield |= 4;
                } else {
                    var_v0_2->object_properties_bitfield &= ~4;
                }
                temp_v1_2 = var_v1 + 1;
                sp72 = temp_v1_2;
                var_v0_2 = getSpawnerTiedActor(var_v1, 0U);
                var_v1 = temp_v1_2;
            } while (var_v0_2 != NULL);
            return;
        }
        break;
    case 0xB:
        func_global_asm_807289E8((s16) temp_a1, unksp46, unksp3E, unksp3A);
        return;
    case 0x11:
        func_global_asm_806291B4(temp_a1 & 0xFF);
        return;
    case 0xC:
        func_global_asm_8067AB20(D_global_asm_807F5D10, sp94, 0x01000000, 1U, &spA0, 0U);
        return;
    case 0xD:
        func_global_asm_8067AB20(D_global_asm_807F5D10, sp94, 0x01000000, 0x10U, &spA0, 0U);
        spA6 = -1;
        func_global_asm_8067AB20(D_global_asm_807F5D10, sp94, 0x01000000, 0xEU, &spA0, 0U);
        return;
    case 0x12:
        func_global_asm_8067AB20(D_global_asm_807F5D10, sp94, 0x01000000, 0x14U, &spA0, 0U);
        return;
    case 0x31:
        if (sp38 != 0) {
            func_global_asm_80721560(0x320, 0x82, 0, 0x64, 0x64, 0x64);
            func_global_asm_807215D0(1, 1);
            return;
        }
        func_global_asm_80721560(0x320, 0x82, 0, (s16) temp_a1 & 0xFF, sp44, sp3C);
        func_global_asm_807215D0(1, 0);
        return;
    case 0x32:
        func_global_asm_8065F49C((s32) (s16) temp_a1, (f32) sp44, (f32) sp3C, (f32) ((f64) sp38 * 0.01));
        return;
    case 0xE:
        func_global_asm_80729AA4((s16) temp_a1 & 0xFF);
        return;
    case 0x16:
        temp_v0_2 = getSpawnerTiedActor((s16) temp_a1, 0U);
        if (temp_v0_2 != NULL) {
            if (D_global_asm_807FBB68 & 2) {
                sp98 = temp_v0_2;
                moveAndScaleActorToAnother(player_pointer, temp_v0_2, temp_v0_2->animation_state->scale[1]);
            } else {
                sp98 = temp_v0_2;
                moveAndScaleActorToAnother(player_pointer, temp_v0_2, 0.15f);
                character_change_array->unk2C0 = 1;
            }
            func_global_asm_806CFF9C(player_pointer);
            player_pointer->object_properties_bitfield |= 4;
            sp98->control_state = 0x40;
            return;
        }
        break;
    case 0x20:
        temp_v0_3 = getSpawnerTiedActor((s16) temp_a1, 0U);
        if (temp_v0_3 != NULL) {
            moveAndScaleActorToAnother(temp_v0_3, player_pointer, player_pointer->animation_state->scale[1]);
            player_pointer->control_state = 0x77;
            player_pointer->control_state_progress = 0;
            return;
        }
        break;
    case 0x29:
        if (func_global_asm_8061B4B0() == 0) {
            func_global_asm_80712524((enum map_e) (s16) temp_a1, sp44);
            return;
        }
        break;
    case 0x43:
        if (func_global_asm_8061B4B0() == 0) {
            D_global_asm_8075536C = (s8) sp3C;
            func_global_asm_80712524((enum map_e) (s16) temp_a1, sp44);
            return;
        }
        break;
    case 0x3F:
        func_global_asm_80713EB0((s16) temp_a1, sp44, sp3C);
        return;
    case 0x2A:
        temp_v0_4 = getSpawnerTiedActor((s16) temp_a1, 0U);
        if (temp_v0_4 != NULL) {
            temp_v0_4->control_state = 0x3C;
            return;
        }
        break;
    case 0x28:
        temp_v0_5 = getSpawnerTiedActor((s16) temp_a1, 0U);
        sp98 = temp_v0_5;
        if (temp_v0_5 != NULL) {
            temp_v0_6 = getSpawnerTiedActor(unksp46, 0U);
            if (temp_v0_6 != NULL) {
                sp90 = temp_v0_6;
                moveAndScaleActorToAnother(sp98, temp_v0_6, temp_v0_6->animation_state->scale[1]);
                temp_v0_7 = sp90->animation_state->unk0;
                func_global_asm_80613CA8(sp98, temp_v0_7->unk10, temp_v0_7->unk4, 0);
                func_global_asm_8061421C(sp98);
                sp98->object_properties_bitfield |= 4;
                temp_v0_6->object_properties_bitfield &= ~4;
                return;
            }
        }
        break;
    case 0x13:
        if ((s16) temp_a1 != 0) {
            sp98 = getSpawnerTiedActor((s16) temp_a1, 0U);
        } else {
            sp98 = player_pointer;
            func_global_asm_80672C30(player_pointer);
        }
        func_global_asm_80724B5C(unksp47, unksp3F, &sp98->x_position, &sp98->y_position, &sp98->z_position);
        func_global_asm_8067A69C(NULL, sp98, sp98->x_position, sp98->z_position, 2U, 1U);
        temp_lo = (s32) (sp38 << 0xC) / 360;
        sp98->unkEE = (s16) temp_lo;
        sp98->y_rotation = (s16) temp_lo;
        sp98->unk9C = sp98->y_position;
        renderActor(sp98, 0U);
        func_global_asm_80614A64(sp98);
        return;
    case 0x14:
        if ((s16) temp_a1 >= 0) {
            if ((s16) temp_a1 != 0) {
                var_v1_2 = getSpawnerTiedActor((s16) temp_a1, 0U);
            } else {
                var_v1_2 = player_pointer;
                sp98 = var_v1_2;
            }
            if (sp3C != 0) {
                var_f0 = (f64) sp3C;
            } else {
                var_f0 = 127.5;
            }
            var_v0_3 = 0x7F;
            if (sp38 != 0) {
                var_v0_3 = sp38;
            }
            D_807F5D7C = playSoundAtPosition(var_v1_2->x_position, var_v1_2->y_position, var_v1_2->z_position, unksp46, (u8) (u32) var_f0, (s16) var_v0_3, 0U, 0U, 0.0f, 0U);
            return;
        }
        if (sp44 < 0x800) {
            if (sp3C != 0) {
                var_f2 = ((f64) sp3C / 255.0) * 32767.0;
            } else {
                var_f2 = 16383.5;
            }
            if (sp38 != 0) {
                var_f0_2 = (f64) sp38 / 127.0;
            } else {
                var_f0_2 = 0.0;
            }
            cfc1 = 0;
            if (cfc1 & 0x78) {
                if (!(cfc1 & 0x78)) {
                    var_a2 = (s32) (var_f2 - 2147483648.0) | 0x80000000;
                } else {
                    goto block_96;
                }
            } else {
                var_a2 = (s32) var_f2;
                if (var_a2 < 0) {
block_96:
                    var_a2 = -1;
                }
            }
            func_global_asm_80737638(D_global_asm_8076D1F8, (enum sfx_e) unksp46, var_a2 & 0xFFFF, 0x3FU, (f32) var_f0_2, 0U, -((s16) temp_a1 * 4) + &D_807F5D6C);
            return;
        }
        if (sp3C != 0) {
            var_f2_2 = ((f64) sp3C / 255.0) * 32767.0;
        } else {
            var_f2_2 = 16383.5;
        }
        if (sp38 != 0) {
            var_f0_3 = (f64) sp38 / 127.0;
        } else {
            var_f0_3 = 0.0;
        }
        if (cfc1 & 0x78) {
            if (!(cfc1 & 0x78)) {
                var_a2_2 = (s32) (var_f2_2 - 2147483648.0) | 0x80000000;
            } else {
                goto block_108;
            }
        } else {
            var_a2_2 = (s32) var_f2_2;
            if (var_a2_2 < 0) {
block_108:
                var_a2_2 = -1;
            }
        }
        func_global_asm_80737638(D_8076D1FC, (enum sfx_e) (s16) (sp44 - 0x7FF), var_a2_2 & 0xFFFF, 0x3FU, (f32) var_f0_3, 0U, -((s16) temp_a1 * 4) + &D_807F5D6C);
        return;
    case 0x19:
        if ((s16) temp_a1 > 0) {
            var_v0_4 = (s16) temp_a1;
        } else {
            var_v0_4 = -(s16) temp_a1;
        }
        if (var_v0_4 <= 0) {
            var_v0_5 = 0;
        } else {
            var_v1_3 = -(s16) temp_a1;
            if ((s16) temp_a1 > 0) {
                var_v1_3 = (s16) temp_a1;
            }
            var_v0_5 = var_v1_3 - 1;
        }
        func_global_asm_80737924(*(&D_807F5D70 + (var_v0_5 * 4)), temp_a1);
        return;
    case 0x1A:
        func_global_asm_80737924(*(&D_global_asm_807457E4 + (D_807F5D7C * 4)), temp_a1);
        return;
    case 0x38:
        if ((s16) temp_a1 != 0) {
            sp98 = getSpawnerTiedActor((s16) temp_a1, 0U);
        } else {
            sp98 = player_pointer;
        }
        if (sp3C != 0) {
            var_v0_6 = sp3C;
        } else {
            var_v0_6 = 0xFF;
        }
        func_global_asm_80604CBC(sp98, unksp46, 0U, 1U, 0U, (u8) var_v0_6, 1.0f, (s8) sp38);
        return;
    case 0x37:
        if ((s16) temp_a1 != 0) {
            sp98 = getSpawnerTiedActor((s16) temp_a1, 0U);
        } else {
            sp98 = player_pointer;
        }
        func_global_asm_80605314(sp98, 0U);
        return;
    case 0x1B:
        func_global_asm_80602B60((s32) (s16) temp_a1, 0U);
        return;
    case 0x44:
        func_global_asm_80602488((s16) temp_a1 & 0xFF);
        return;
    case 0x3C:
        temp_v1_3 = getSpawnerTiedActor(1, 0U)->unk17C;
        temp_v1_3->unkD = (u8) (temp_v1_3->unkD | (s16) temp_a1);
        return;
    case 0x3B:
        func_global_asm_80627EA8((s16) temp_a1)->unk146 = (u16) sp44;
        return;
    case 0x1C:
        func_global_asm_80627EA8((s16) temp_a1)->y_rotation = character_change_array->unk2C8 & 0xFFF;
        return;
    case 0x30:
        temp_v0_8 = func_global_asm_80627EA8((s16) temp_a1);
        if (sp44 >= 0) {
            temp_v0_8->unk16A = (u8) sp44;
            temp_v0_8->object_properties_bitfield |= 0x800000;
            temp_v0_8->unk16B = (u8) sp3C;
            temp_v0_8->unk16C = (u8) sp38;
            return;
        }
        temp_v0_8->object_properties_bitfield &= 0xFF7FFFFF;
        return;
    case 0x2C:
        sp98 = func_global_asm_80627EA8((s16) temp_a1);
        func_global_asm_80724B5C(unksp47, unksp3F, &sp84, &sp80, &sp7C);
        sp98->y_rotation = func_global_asm_80665DE0(sp84, sp7C, sp98->x_position, sp98->z_position);
        return;
    case 0x2F:
        func_global_asm_8063DA40((s16) temp_a1, unksp3A);
        if (sp44 != 0) {
            func_global_asm_8063DA40((s16) sp44, unksp3A);
        }
        if (sp3C != 0) {
            func_global_asm_8063DA40(unksp3E, unksp3A);
            return;
        }
        break;
    case 0x15:
        func_global_asm_8063DA40((s16) temp_a1, unksp46);
        return;
    case 0x17:
        if (sp44 != 0) {
            var_f0_4 = (f64) sp44 / 255.0;
        } else {
            var_f0_4 = 0.0;
        }
        playSong((s32) (s16) temp_a1, (f32) var_f0_4);
        return;
    case 0x18:
        func_global_asm_8070E8DC(1U);
    case 0x39:
        loadText(func_global_asm_80627EA8((s16) temp_a1), unksp46, unksp3F);
        return;
    case 0x1E:
        spawnActor(ACTOR_SQUAWKS_1, 0x1D);
        last_spawned_actor->unkF0 = (s16) sp3C;
        loadText(last_spawned_actor, (s16) temp_a1 & 0xFFFF, unksp47);
        return;
    case 0x1D:
        func_global_asm_8061CAD8();
        return;
    case 0x21:
        func_global_asm_8061C2C4(D_global_asm_807F5D10, 0x8000);
        return;
    case 0x22:
        if ((s16) temp_a1 != 0) {
            func_global_asm_805FF378((enum map_e) (s16) temp_a1, sp44);
            return;
        }
        func_global_asm_80712830(player_pointer, 0);
        return;
    case 0x23:
        loading_zone_transition_type = (s8) (s16) temp_a1;
        loading_zone_transition_speed = (f32) ((f64) sp44 / 100.0);
        return;
    case 0x3A:
        func_global_asm_8071268C();
        return;
    case 0x35:
        if ((s16) temp_a1 == 0) {
            func_global_asm_80687C48();
        }
        break;
    }
}
*/

s32 func_global_asm_80629148(void) {
    s32 phi_v1 = FALSE;
    if (current_actor_pointer->unk6A & 0x100) {
        current_actor_pointer->unk6A &= ~0x100;
        phi_v1 = TRUE;
    }
    return phi_v1;
}

void func_global_asm_80629174(void) {
    current_actor_pointer->unk6A &= ~0x100;
}
