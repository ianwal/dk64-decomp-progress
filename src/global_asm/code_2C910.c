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

// doable, struct on stack?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_global_asm_80627C5C.s")

/*
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

void func_critter_80028EE8(u8, s32, s16, u8, u16, u16, u8, u8);
void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_global_asm_8061421C(Actor *);
void func_global_asm_806C8E58(s16);
void func_global_asm_80713EB0(s16, s32, s32);
void func_global_asm_807289E8(s16, s16, s16, s16);
void func_global_asm_80737924(SoundState *);
void func_global_asm_80627C5C(u8, s16, u8);
extern void *D_global_asm_8076D1FC;
extern f32 D_807F5D6C[];
extern SoundState *D_807F5D70[];
extern s16 D_807F5D7C;
extern SoundState *D_global_asm_807457E4[];
extern u16 D_global_asm_80747750[];
extern s8 D_global_asm_8075536C;
extern s16 D_global_asm_8076AEF2;
extern void *D_global_asm_8076D1F8;
extern s32 D_global_asm_807FBB68;
extern f32 loading_zone_transition_speed;
extern s8 loading_zone_transition_type;

typedef struct Struct80627F04_17C {
    u8 unk0[0xD];
    u8 unkD;
    u8 unkE[0x22 - 0xE];
    u8 unk22;
    u8 unk23[0x30 - 0x23];
    s8 unk30;
    s8 unk31;
    s8 unk32;
    s8 unk33;
} Struct80627F04_17C;

// I hate this
typedef union Struct80627F04_dp {
    s32 dp_32;
    struct {
        u16 dp_16u;
        u16 dp_16l;
    };
    struct {
        u8 dp_8u[3];
        u8 dp_8l;
    };
} Struct80627F04_dp;

/*
void func_global_asm_80627F04(s32 arg0, s32 arg1, s32 arg2) {
    s16 spA6;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    PlayerAdditionalActorData *sp9C;
    Actor *actor_v2;
    Actor *sp94;
    Actor *sp90;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    s16 i; // 72
    f32 var_f0;
    f32 var_f2;
    s16 var_v1_3;
    s32 temp_lo;
    s32 var_a2;
    s32 var_v0;
    s32 var_v0_3;
    u8 tmp;
    Actor *actor_v;
    s32 temp_s0; // Not on stack
    Struct80627F04_17C *temp_v1;
    Struct80627F04_dp sp48;
    Struct80627F04_dp sp44;
    Struct80627F04_dp sp3C;
    Struct80627F04_dp sp38;

    sp9C = player_pointer->additional_actor_data;
    func_global_asm_8072E7DC(0xC, &sp94);
    temp_s0 = arg1 >> 0x10;
    sp3C.dp_32 = (s16)arg2 >> 0x10;
    spA0 = temp_s0;
    tmp = arg0;
    sp44.dp_32 = (s16)arg1;
    spA2 = (s16)arg1;
    spA4 = arg2;
    sp38.dp_32 = (s16)arg2;
    spA6 = (s16)arg2;
    switch (tmp) {
    case 0x45:
        func_global_asm_80726E60(2U, 0x40U);
        return;
    case 0x42:
        var_v0 = sp44.dp_32 ? sp44.dp_16l : 0x5A;
        func_global_asm_80627C5C(temp_s0, var_v0, sp3C.dp_8l);
        return;
    case 0x41:
        func_global_asm_805FF8F8();
        return;
    case 0x3D:
        func_global_asm_805FF378(D_global_asm_8076AEF2, 0);
        return;
    case 0x3E:
        func_global_asm_805FF378(MAP_DK_ISLES_OVERWORLD, 0xC);
        return;
    case 0x40:
        func_global_asm_807127F4(0);
        return;
    case 0x36:
        func_global_asm_806C8E58(temp_s0 + 2);
        func_global_asm_806F0C18(player_pointer);
        return;
    case 0x33:
        temp_v1 = func_global_asm_80627EA8(temp_s0)->unk17C;
        temp_v1->unk30 = -2;
        temp_v1->unk33 = sp44.dp_32;
        temp_v1->unk22 = sp3C.dp_32;
        temp_v1->unk31 = 1;
        temp_v1->unk32 = sp38.dp_32;
        return;
    case 0x34:
        temp_v1 = func_global_asm_80627EA8(temp_s0)->unk17C;
        temp_v1->unk30 = -1;
        return;
    case 0x0:
        sp9C->unk70 = player_pointer->y_rotation;
        sp9C->unk6C = temp_s0;
        sp9C->unk74 = sp44.dp_32;
        setAction(0x17, NULL, 0U);
        return;
    case 0x1:
        func_critter_80028EE8(sp3C.dp_32 + 6, 0, 0xC8, temp_s0, 0, sp44.dp_32 + 0x28, 0x64, 0xFF);
        return;
    case 0x2:
        sp9C->unk1F0 |= 8;
        return;
    case 0x3:
        sp9C->unk1F0 &= ~8;
        return;
    case 0x24:
        func_global_asm_80724994(1U, temp_s0, sp44.dp_32, sp3C.dp_32, sp38.dp_32);
        return;
    case 0x5:
        func_global_asm_807271F4(temp_s0, 0, 0, 0, 0, 0, 0);
        return;
    case 0x4:
        if (temp_s0 != 0) {
            func_global_asm_80724994(3U, temp_s0, sp44.dp_32, sp3C.dp_32, sp38.dp_32);
            return;
        }
        if (sp44.dp_32 == 2) {
            current_player->animation_state->unk0->unk10 = -1;
            playActorAnimation(current_player, D_global_asm_80747750[sp3C.dp_32]);
            if (sp38.dp_32 != 0) {
                func_global_asm_80614D00(current_player, (f64)sp38.dp_32 / 100.0, 0.0f);
                return;
            }
        }
    default:
        return;
    case 0x6:
        actor_v = getSpawnerTiedActor(temp_s0, 0U);
        func_global_asm_8061CF90(actor_v, sp44.dp_32);
        return;
    case 0x7:
        func_global_asm_8061D968(temp_s0, sp44.dp_32);
        return;
    case 0x2D:
        func_global_asm_8061CF80(temp_s0);
        return;
    case 0x2E:
        func_global_asm_80627EA8(temp_s0)->unk15E = sp44.dp_32;
        return;
    case 0x25:
        func_global_asm_806F397C(player_pointer, NULL, temp_s0, 0);
        return;
    case 0x26:
        func_global_asm_80641874(temp_s0, sp44.dp_32);
        return;
    case 0x27:
        func_global_asm_80656E58(temp_s0, sp44.dp_32, 0U, sp3C.dp_32);
        func_global_asm_80656E58(temp_s0, sp44.dp_32, 1U, sp3C.dp_32);
        func_global_asm_80656E58(temp_s0, sp44.dp_32, 2U, sp3C.dp_32);
        func_global_asm_80656E58(temp_s0, sp44.dp_32, 3U, sp3C.dp_32);
        return;
    case 0x8:
        func_global_asm_8061D934(temp_s0);
        return;
    case 0x2B:
        setIntroStoryPlaying(temp_s0);
        return;
    case 0x9:
        func_global_asm_8061DAAC(temp_s0, sp44.dp_32, sp3C.dp_32);
        return;
    case 0x10:
        func_global_asm_8061F0B0(D_global_asm_807F5D10, sp44.dp_32, temp_s0);
        return;
    case 0xA:
        if (temp_s0) {
            actor_v = getSpawnerTiedActor(temp_s0, 0U);
            if (sp44.dp_32) {
                actor_v->object_properties_bitfield |= 4;
            } else {
                actor_v->object_properties_bitfield &= ~4;
            }
            return;
        }
        actor_v = getSpawnerTiedActor(1, 0);
        i = 2;
        while (actor_v) {
            if (sp44.dp_32) {
                actor_v->object_properties_bitfield |= 4;
            } else {
                actor_v->object_properties_bitfield &= ~4;
            }
            actor_v = getSpawnerTiedActor(i++, 0);
        }
        break;
    case 0xB:
        func_global_asm_807289E8(temp_s0, sp44.dp_32, sp3C.dp_32, sp38.dp_32);
        return;
    case 0x11:
        func_global_asm_806291B4(temp_s0);
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
        if (sp38.dp_32) {
            func_global_asm_80721560(0x320, 0x82, 0, 0x64, 0x64, 0x64);
            func_global_asm_807215D0(1, 1);
            return;
        }
        func_global_asm_80721560(0x320, 0x82, 0, temp_s0, sp44.dp_32, sp3C.dp_32);
        func_global_asm_807215D0(1, 0);
        return;
    case 0x32:
        func_global_asm_8065F49C(temp_s0, sp44.dp_32, sp3C.dp_32, sp38.dp_32 * 0.01);
        return;
    case 0xE:
        func_global_asm_80729AA4(temp_s0);
        return;
    case 0x16:
        actor_v2 = getSpawnerTiedActor(temp_s0, 0U);
        if (actor_v2 != NULL) {
            if (D_global_asm_807FBB68 & 2) {
                moveAndScaleActorToAnother(player_pointer, actor_v2, actor_v2->animation_state->scale[1]);
            } else {
                moveAndScaleActorToAnother(player_pointer, actor_v2, 0.15f);
                character_change_array->unk2C0 = 1;
            }
            func_global_asm_806CFF9C(player_pointer);
            player_pointer->object_properties_bitfield |= 4;
            actor_v2->control_state = 0x40;
            return;
        }
        break;
    case 0x20:
        actor_v = getSpawnerTiedActor(temp_s0, 0U);
        if (actor_v != NULL) {
            moveAndScaleActorToAnother(actor_v, player_pointer, player_pointer->animation_state->scale[1]);
            player_pointer->control_state = 0x77;
            player_pointer->control_state_progress = 0;
            return;
        }
        break;
    case 0x29:
        if (!func_global_asm_8061B4B0()) {
            func_global_asm_80712524(temp_s0, sp44.dp_32);
            return;
        }
        break;
    case 0x43:
        if (func_global_asm_8061B4B0() == 0) {
            D_global_asm_8075536C = sp3C.dp_32;
            func_global_asm_80712524(temp_s0, sp44.dp_32);
            return;
        }
        break;
    case 0x3F:
        func_global_asm_80713EB0(temp_s0, sp44.dp_32, sp3C.dp_32);
        return;
    case 0x2A:
        actor_v = getSpawnerTiedActor(temp_s0, 0U);
        if (actor_v != NULL) {
            actor_v->control_state = 0x3C;
            return;
        }
        break;
    case 0x28:
        actor_v2 = getSpawnerTiedActor(temp_s0, 0U);
        if (actor_v2 != NULL) {
            actor_v = getSpawnerTiedActor(sp44.dp_32, 0U);
            if (actor_v != NULL) {
                sp90 = actor_v;
                moveAndScaleActorToAnother(actor_v2, actor_v, actor_v->animation_state->scale[1]);
                func_global_asm_80613CA8(actor_v2, sp90->animation_state->unk0->unk10, sp90->animation_state->unk0->unk4, 0);
                func_global_asm_8061421C(actor_v2);
                actor_v2->object_properties_bitfield |= 4;
                actor_v->object_properties_bitfield &= ~4;
                return;
            }
        }
        break;
    case 0x13:
        if (temp_s0 != 0) {
            actor_v2 = getSpawnerTiedActor(temp_s0, 0U);
        } else {
            actor_v2 = player_pointer;
            func_global_asm_80672C30(player_pointer);
        }
        func_global_asm_80724B5C(sp44.dp_32, sp3C.dp_32, &actor_v2->x_position, &actor_v2->y_position, &actor_v2->z_position);
        func_global_asm_8067A69C(NULL, actor_v2, actor_v2->x_position, actor_v2->z_position, 2U, 1U);
        temp_lo = (s32) (sp38.dp_32 << 0xC) / 360;
        actor_v2->unkEE = temp_lo;
        actor_v2->y_rotation = temp_lo;
        actor_v2->unk9C = actor_v2->y_position;
        renderActor(actor_v2, 0U);
        func_global_asm_80614A64(actor_v2);
        return;
    case 0x14:
        if (temp_s0 >= 0) {
            if (temp_s0 != 0) {
                actor_v2 = getSpawnerTiedActor(temp_s0, 0U);
            } else {
                actor_v2 = player_pointer;
            }
            if (sp3C.dp_32 != 0) {
                var_f0 = (f64)sp3C.dp_32;
            } else {
                var_f0 = 127.5;
            }
            var_v0_3 = 0x7F;
            if (sp38.dp_32 != 0) {
                var_v0_3 = sp38.dp_32;
            }
            D_807F5D7C = playSoundAtPosition(
                actor_v2->x_position,
                actor_v2->y_position,
                actor_v2->z_position,
                sp44.dp_32,
                var_f0,
                var_v0_3,
                0U, 0U, 0.0f, 0U);
            return;
        }
        if (sp44.dp_32 < 0x800) {
            if (sp3C.dp_32 != 0) {
                var_f2 = (sp3C.dp_32 / 255.0) * 32767.0;
            } else {
                var_f2 = 16383.5;
            }
            if (sp38.dp_32 != 0) {
                var_f0 = sp38.dp_32 / 127.0;
            } else {
                var_f0 = 0.0;
            }
            func_global_asm_80737638(D_global_asm_8076D1F8, sp44.dp_32, var_f2, 0x3FU, var_f0, 0U, &D_807F5D6C[-temp_s0]);
            return;
        }
        if (sp3C.dp_32 != 0) {
            var_f2 = (sp3C.dp_32 / 255.0) * 32767.0;
        } else {
            var_f2 = 16383.5;
        }
        if (sp38.dp_32 != 0) {
            var_f0 = sp38.dp_32 / 127.0;
        } else {
            var_f0 = 0.0;
        }
        func_global_asm_80737638(D_global_asm_8076D1FC, sp44.dp_32 - 0x7FF, var_f2, 0x3FU, var_f0, 0U, &D_807F5D6C[temp_s0]);
        return;
    case 0x19:
        var_v1_3 = ABS(temp_s0);
        if (var_v1_3 <= 0) {
            var_v1_3 = 0;
        } else {
            var_v1_3--;
        }
        func_global_asm_80737924(D_807F5D70[var_v1_3]);
        return;
    case 0x1A:
        func_global_asm_80737924(D_global_asm_807457E4[D_807F5D7C]);
        return;
    case 0x38:
        if (temp_s0 != 0) {
            actor_v2 = getSpawnerTiedActor(temp_s0, 0U);
        } else {
            actor_v2 = player_pointer;
        }
        if (sp3C.dp_32 != 0) {
            var_v0_3 = sp3C.dp_32;
        } else {
            var_v0_3 = 0xFF;
        }
        func_global_asm_80604CBC(actor_v2, sp44.dp_32, 0U, 1U, 0U, var_v0_3, 1.0f, sp38.dp_32);
        return;
    case 0x37:
        if (temp_s0 != 0) {
            actor_v2 = getSpawnerTiedActor(temp_s0, 0U);
        } else {
            actor_v2 = player_pointer;
        }
        func_global_asm_80605314(actor_v2, 0U);
        return;
    case 0x1B:
        func_global_asm_80602B60(temp_s0, 0U);
        return;
    case 0x44:
        func_global_asm_80602488(temp_s0);
        return;
    case 0x3C:
        temp_v1 = getSpawnerTiedActor(1, 0U)->unk17C;
        temp_v1->unkD |= temp_s0;
        return;
    case 0x3B:
        func_global_asm_80627EA8(temp_s0)->unk146 = sp44.dp_32;
        return;
    case 0x1C:
        func_global_asm_80627EA8(temp_s0)->y_rotation = character_change_array->unk2C8 & 0xFFF;
        return;
    case 0x30:
        actor_v = func_global_asm_80627EA8(temp_s0);
        if (sp44.dp_32 >= 0) {
            actor_v->unk16A = sp44.dp_32;
            actor_v->object_properties_bitfield |= 0x800000;
            actor_v->unk16B = sp3C.dp_32;
            actor_v->unk16C = sp38.dp_32;
            return;
        }
        actor_v->object_properties_bitfield &= ~0x800000;
        return;
    case 0x2C:
        actor_v2 = func_global_asm_80627EA8(temp_s0);
        func_global_asm_80724B5C(sp44.dp_32, sp3C.dp_32, &sp84, &sp80, &sp7C);
        actor_v2->y_rotation = func_global_asm_80665DE0(sp84, sp7C, actor_v2->x_position, actor_v2->z_position);
        return;
    case 0x2F:
        func_global_asm_8063DA40(temp_s0, sp38.dp_32);
        if (sp44.dp_32 != 0) {
            func_global_asm_8063DA40(sp44.dp_32, sp38.dp_32);
        }
        if (sp3C.dp_32 != 0) {
            func_global_asm_8063DA40(sp3C.dp_32, sp38.dp_32);
            return;
        }
        break;
    case 0x15:
        func_global_asm_8063DA40(temp_s0, sp44.dp_32);
        return;
    case 0x17:
        if (sp44.dp_32 != 0) {
            var_f0 = sp44.dp_32 / 255.0;
        } else {
            var_f0 = 0.0;
        }
        playSong(temp_s0, var_f0);
        return;
    case 0x18:
        func_global_asm_8070E8DC(1U);
    case 0x39:
        loadText(func_global_asm_80627EA8(temp_s0), sp44.dp_32, sp3C.dp_32);
        return;
    case 0x1E:
        spawnActor(ACTOR_SQUAWKS_1, 0x1D);
        last_spawned_actor->unkF0 = sp3C.dp_32;
        loadText(last_spawned_actor, temp_s0, sp44.dp_32);
        return;
    case 0x1D:
        func_global_asm_8061CAD8();
        return;
    case 0x21:
        func_global_asm_8061C2C4(D_global_asm_807F5D10, 0x8000);
        return;
    case 0x22:
        if (temp_s0 != 0) {
            func_global_asm_805FF378(temp_s0, sp44.dp_32);
            return;
        }
        func_global_asm_80712830(player_pointer, 0);
        return;
    case 0x23:
        loading_zone_transition_type = temp_s0;
        loading_zone_transition_speed = sp44.dp_32 / 100.0;
        return;
    case 0x3A:
        func_global_asm_8071268C();
        return;
    case 0x35:
        if (temp_s0 == 0) {
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
