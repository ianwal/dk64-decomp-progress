#include <ultra64.h>
#include "functions.h"

const s32 D_boss_80036C10[] = {
    0x4F230825,
    0x06325000
};
const s32 D_boss_80036C18[] = {
    0x4F230A25,
    0x052D5000
};
const s32 D_boss_80036C20[] = {
    0x4F230B25,
    0x04285000
};
const s32 D_boss_80036C28[] = {
    0x4F230C28,
    0x04055000
};
const s32 D_boss_80036C30[] = {
    0x5F0A5429,
    0xFB544F23,
    0x0E280401,
    0x50000000
};

const f32 D_boss_80036C40[] = {
    0.8f,
    0.9f,
    1.0f,
    1.1f,
    1.2f,
    0.0f // TODO: Is this just padding?
};

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/MadJack/func_boss_800330D0.s")

extern u8 D_boss_80035B80[4];

typedef struct {
    u8 unk0[0x14 - 0x0];
    u8 unk14;
} Struct800330D0_arg0;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Struct800330D0_arg1;

/*
u8 func_boss_800330D0(Struct800330D0_arg0 *arg0, Struct800330D0_arg1 *arg1) {
    f32 dZ;
    f32 dX;
    s32 closest;
    s32 sp44[0x10];
    s8 temp_a2;
    s8 temp_a3;
    u8 i;
    u8 var_t2;
    u8 var_t4;

    var_t2 = arg1->unk0;
    closest = 9999999;
    var_t4 = var_t2;
    for (i = 0; i < 0x10; i++) {
        dZ = D_global_asm_807FDCA0->unk14[i].unk4 - player_pointer->z_position;
        dX = D_global_asm_807FDCA0->unk14[i].unk0 - player_pointer->x_position;
        sp44[i] = (dZ * dZ) + (dX * dX);
        if (sp44[i] < closest) {
            arg1->unk3 = i;
            closest = sp44[i];
        }
    }
    if (player_pointer->y_position < (current_actor_pointer->y_position - 10.0f)) {
        return D_boss_80035B80[(rand() >> 0xF) % 4];
    }
    temp_a2 = (arg1->unk0 / 4) - (arg1->unk3 / 4);
    temp_a3 = (arg1->unk0 % 4) - (arg1->unk3 % 4);
    if (temp_a2 > 0) {
        var_t2 -= 4;
    } else if (temp_a2 < 0) {
        var_t2 += 4;
    } else if (temp_a3 > 0) {
        var_t2 -= 1;
    } else if (temp_a3 < 0) {
        var_t2++;
    }
    if (arg0->unk14 >= 3) {
        return var_t2;
    }
    if ((var_t2 == arg1->unk2) || ((var_t2 == var_t4))) {
        if ((temp_a2 != 0) || (var_t2 == var_t4)) {
            if ((sp44[(var_t4 - 1) & 0xF] < sp44[(var_t4 + 1) & 0xF]) && (var_t4 & 3)) {
                var_t4--;
            } else if ((sp44[(var_t4 + 1) & 0xF] < sp44[(var_t4 - 1) & 0xF]) && ((var_t4 & 3) != 3)) {
                var_t4++;
            }
        }
        if (((temp_a2 == 0) && (temp_a3 != 0)) || (var_t2 == var_t4)) {
            if ((sp44[(var_t4 - 4) & 0xF] < sp44[(var_t4 + 4) & 0xF]) && (var_t4 >= 4)) {
                var_t4 -= 4;
            } else if ((sp44[(var_t4 + 4) & 0xF] < sp44[(var_t4 - 4) & 0xF]) && (var_t4 < 0xC)) {
                var_t4 += 4;
            }
        }
        // Duplicate return node #37. Try simplifying control flow for better match
        return var_t4;
    }
    return var_t2;
}
*/

void func_global_asm_8061EF4C(s32, s32, s32, f32, f32, f32, f32, f32);

extern f64 D_boss_80036C58;

typedef struct {
    u8 pad0[0x8];
    s16 unk8;
    u8 unkA[0x14 - 0xA];
    u8 phase;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 actions_remaining;
    u8 action_type;
} MadJackFightData;

typedef struct {
    u8 current;
    u8 next;
} MadJackPosData_0;

typedef struct {
    MadJackPosData_0 jack;
    MadJackPosData_0 kong;
    u8 white_switch_position;
    u8 blue_switch_position;
    u8 unk6;
} MadJackPosData;

void func_boss_8003340C(MadJackPosData *arg0) {
    if ((current_actor_pointer->animation_state->unk64 != 0x223) && (arg0->jack.next == arg0->kong.next)) {
        playActorAnimation(current_actor_pointer, 0x223);
        func_global_asm_80614D90(current_actor_pointer);
        return;
    }
    if ((current_actor_pointer->animation_state->unk64 != 0x224) && (arg0->jack.next != arg0->kong.next)) {
        playActorAnimation(current_actor_pointer, 0x224);
        func_global_asm_80614D90(current_actor_pointer);
    }
}

void func_boss_800334A4(MadJackPosData *arg0, f32 arg1) {
    f32 temp_f2;

    temp_f2 = func_global_asm_80612794(((f32)(1.0 - MIN(1.0, current_actor_pointer->animation_state->unk0->unk4 * arg1)) * 1024.0f) + 3072.0f) + 1.0;
    current_actor_pointer->x_position = D_global_asm_807FDCA0->unk14[arg0->jack.next].unk0 + ((D_global_asm_807FDCA0->unk14[arg0->jack.current].unk0 - D_global_asm_807FDCA0->unk14[arg0->jack.next].unk0) * temp_f2);
    current_actor_pointer->z_position = D_global_asm_807FDCA0->unk14[arg0->jack.next].unk4 + ((D_global_asm_807FDCA0->unk14[arg0->jack.current].unk4 - D_global_asm_807FDCA0->unk14[arg0->jack.next].unk4) * temp_f2);
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(D_global_asm_807FDCA0->unk14[arg0->jack.next].unk0, D_global_asm_807FDCA0->unk14[arg0->jack.next].unk4, D_global_asm_807FDCA0->unk14[arg0->jack.current].unk0, D_global_asm_807FDCA0->unk14[arg0->jack.current].unk4), 10.0f);
}

void func_boss_800336C0(void) {
    f32 scale;

    scale = current_actor_pointer->animation_state->scale_y / 0.15;
    func_global_asm_80714998(2);
    func_global_asm_8071498C(func_global_asm_8071720C);
    func_global_asm_807149B8(1);
    func_global_asm_80714950(1);
    drawSpriteAtPosition(
        D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        (f64)scale,
        current_actor_pointer->x_position,
        current_actor_pointer->y_position,
        current_actor_pointer->z_position
    );
}

extern u8 D_boss_80035BDC[];
extern u8 D_boss_80035BE4[];

void func_boss_80033784(MadJackPosData *arg0, u8 arg1) {
    s32 random;
    u8 random_copy;
    s16 temp_a1;
    u8 temp_v0;
    s32 kong_next;

    if (arg1) {
        do {
            do {
                random = rand();
                random = (random >> 0xF) % 8;
                random_copy = random;
                temp_v0 = D_boss_80035BDC[random & 0xFF];
                if (random_copy); // Shifts andi to be earlier
            } while (temp_v0 == (arg0->jack.current + 0x10));
            temp_a1 = D_boss_80035BDC[random_copy];
            if (temp_a1);
            kong_next = arg0->kong.next;
        } while (
            ((kong_next + 0x10) == temp_a1) ||
            ((kong_next + 0x0F) == temp_a1) ||
            ((kong_next + 0x11) == temp_a1) ||
            ((kong_next + 0x0C) == temp_a1) ||
            ((kong_next + 0x14) == temp_a1)
        );
        arg0->white_switch_position = temp_v0;
        do {
            do {
                random = rand();
                random = (random >> 0xF) % 8;
                random_copy = random;
                temp_v0 = D_boss_80035BE4[random & 0xFF];
                if (random_copy);
            } while (temp_v0 == (arg0->jack.current + 0x10));
            temp_a1 = D_boss_80035BE4[random_copy];
            if (temp_a1);
            kong_next = arg0->kong.next;
        } while (
            ((kong_next + 0x10) == temp_a1) ||
            ((kong_next + 0x0F) == temp_a1) ||
            ((kong_next + 0x11) == temp_a1) ||
            ((kong_next + 0x0C) == temp_a1) ||
            ((kong_next + 0x14) == temp_a1)
        );
        arg0->blue_switch_position = temp_v0;
    }
    if (arg0->white_switch_position != 0) {
        func_global_asm_8063DA40(arg0->white_switch_position, arg1);
    }
    if (arg0->blue_switch_position != 0) {
        func_global_asm_8063DA40(arg0->blue_switch_position, arg1);
    }
    if (!arg1) {
        arg0->white_switch_position = 0U;
        arg0->blue_switch_position = 0U;
    }
}

void func_boss_8003392C(MadJackPosData *arg0) {
    func_global_asm_80690814(current_actor_pointer, 1);
    func_global_asm_80690A28(0x2C, 2, current_actor_pointer->animation_state->scale_y, D_global_asm_807FDCA0->unk14[arg0->kong.next].unk0, D_global_asm_807FDCA0->unk14[arg0->kong.next].unk2, D_global_asm_807FDCA0->unk14[arg0->kong.next].unk4, 1200.0f, current_actor_pointer);
}

u8 func_boss_800339D8(MadJackFightData *arg0, u8 *arg1) {
    if ((player_pointer->y_position < current_actor_pointer->y_position - 10.0f)) {
        if (arg0->phase < 5) {
            arg0->unk15 = arg0->unk16;
            current_actor_pointer->control_state = arg1[arg0->unk15++];
            current_actor_pointer->control_state_progress = 0;
            playActorAnimation(current_actor_pointer, 0);
            return TRUE;
        }
    }
    return FALSE;
}

void func_boss_80033A80(s8 arg0) {
    current_actor_pointer->shadow_opacity += arg0;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->control_state_progress++;
        return;
    }
    if (current_actor_pointer->shadow_opacity >= 0x100) {
        current_actor_pointer->shadow_opacity = 0xFF;
        current_actor_pointer->control_state_progress++;
    }
}

// Jumptable, 7276 bytes of code
// Mad Jack
#pragma GLOBAL_ASM("asm/nonmatchings/boss/MadJack/func_boss_80033AF0.s")

typedef struct {
    u8 unk0[4];
    u8 images_per_frame_horizontal;
    u8 images_per_frame_vertical;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 table;
    s16 width;
    s16 height;
    s16 image_count;
    s16 images[];
} SpriteData;

u8 func_boss_80027BA8(u8 *, s32, s32, Actor**);
u8 func_boss_800330D0(MadJackFightData *, MadJackPosData *);
void func_global_asm_80626110(Actor *, s16, s16);
void func_global_asm_8072A450(void);
extern u8 D_80036DD0[];
extern s16 D_807502DC;
extern f32 D_807502F0;
extern u8 *D_boss_80035B84[];
extern u16 D_boss_80035B98[];
extern u8 D_boss_80035BD8[];
extern u8 D_boss_80035BEC[];
extern SpriteData D_global_asm_8071FC58;
extern SpriteData D_global_asm_80720054;
extern SpriteData D_global_asm_80720BE8;
extern u8 D_global_asm_807FBB85;
extern u8 D_global_asm_807FBDC4;

// Issues starting at the first switch case (0x1E) statement. V good progress otherwise
/*
void func_boss_80033AF0(void) {
    MadJackPosData *pos_data;
    u8 *phase_sequence;
    u8 has_fallen;
    u8 pad[3];
    u8 sp7F;
    f32 x;
    f32 y;
    f32 z;
    f32 red_mult;
    f32 green_mult;
    f32 blue_mult;
    s16 i;
    u8 temp_s0;
    s32 j;
    s32 unk_0;
    u8 csp;
    u8 fight_16;
    u8 phase_seq_val;
    u8 square;
    u8 white_square;
    u8 blue_square;
    u8 red;
    u8 green;
    u8 blue;
    MadJackFightData *fight_data;
    Struct807FDCA0_unk14 *current_pillar;

    fight_data = current_actor_pointer->unk178;
    pos_data = (MadJackPosData *)current_actor_pointer->unk17C;
    phase_sequence = D_boss_80035B84[fight_data->phase];
    has_fallen = player_pointer->y_position < (current_actor_pointer->y_position - 10.0f) ? 1 : 0;
    sp7F = 0;
    initializeCharacterSpawnerActor();
    func_global_asm_8067ACB4(current_actor_pointer);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkCC = 1;
        current_actor_pointer->noclip_byte = 0x24;
        if (isFlagSet(0x6A, 2U) != 0) {
            playActorAnimation(current_actor_pointer, 0x226);
            playCutscene(current_actor_pointer, 0x14, 1);
            pos_data->jack.current = 9U;
            pos_data->kong.current = 5U;
            current_actor_pointer->control_state = 0x20;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer->control_state_progress = 0xB;
            current_actor_pointer->locked_to_pad = 0;
        } else {
            current_actor_pointer->unk146 = 0;
            D_global_asm_807FDC90->unk30 = current_actor_pointer->animation_state->scale[1];
            func_global_asm_807248B0(current_actor_pointer, D_global_asm_807FDC90->unk30 * 0.333);
            current_actor_pointer->control_state = 0x1E;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer->y_position += 650.0f;
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            pos_data->jack.current = 0xFU;
        }
        current_actor_pointer->unk6A &= 0xFFFE;
        current_actor_pointer->y_acceleration = D_807502F0;
        current_actor_pointer->terminal_velocity = D_807502DC;
    }
    if (fight_data->phase < 2) {
        if (pos_data->white_switch_position != 0) {
            white_square = pos_data->white_switch_position - 0x10;
            blue_square = pos_data->blue_switch_position - 0x10;
            red = D_boss_80035BEC[white_square] ? 0x46 : 0xFF;
            green = D_boss_80035BEC[white_square] ? 0xA0 : 0xFF;
            if (white_square != pos_data->kong.next) {
                func_global_asm_80659610(0x1388);
                createLight(
                    D_global_asm_807FDCA0->unk14[white_square].unk0, 
                    D_global_asm_807FDCA0->unk14[white_square].unk2 - 0x32,
                    D_global_asm_807FDCA0->unk14[white_square].unk4,
                    0.0f, 0.0f, 0.0f, 240.0f, 0U,
                    red, green, 0xFFU);
            }
            if (blue_square != pos_data->kong.next) {
                func_global_asm_80659610(0x1388);
                createLight(
                    D_global_asm_807FDCA0->unk14[blue_square].unk0,
                    D_global_asm_807FDCA0->unk14[blue_square].unk2 - 0x32,
                    D_global_asm_807FDCA0->unk14[blue_square].unk4,
                    0.0f, 0.0f, 0.0f, 240.0f, 0U,
                    red, green, 0xFFU);
            }
        }
    }
    if (((current_actor_pointer->control_state == 0x27) && (fight_data->phase == 4)) || ((D_global_asm_807FBB85 != 0) && (current_actor_pointer->control_state != 0x37))) {
        if (player_pointer->control_state == 0x36) {
            current_actor_pointer->control_state = 0x2B;
            current_actor_pointer->control_state_progress = 0;
        } else {
            playActorAnimation(current_actor_pointer, 0x226);
            current_actor_pointer->control_state = 0x37;
            current_actor_pointer->control_state_progress = 0;
            
        }
    }
    if ((current_actor_pointer->control_state == 0x23) && (current_actor_pointer->control_state_progress == 1) && (has_fallen == 0) && (pos_data->unk6 != 0)) {
        current_actor_pointer->control_state = 0x2B;
        current_actor_pointer->control_state_progress = 0;
    }
    switch (current_actor_pointer->control_state) {
    case 0x1E:
        for (i = 0; i < 0x10; i++) {
            if (D_boss_80035B98[D_global_asm_807FDC90->unk2C & 0x1F] & (1 << i)) {
                D_80036DD0[i] = 0xFA;
            }
            if (D_80036DD0[i] != 0) {
                red_mult = D_boss_80035BEC[i] ? 0.27 : 1.0;
                green_mult = D_boss_80035BEC[i] ? 0.62 : 1.0;
                func_global_asm_80659610(5000);
                current_pillar = &D_global_asm_807FDCA0->unk14[i];
                z = current_pillar->unk4;
                y = current_pillar->unk2 - 650;
                x = current_pillar->unk0;
                blue_mult = D_80036DD0[i];
                red = blue_mult * red_mult;
                green = blue_mult * green_mult;
                createLight(
                    x, y, z,
                    0.0f, 0.0f, 0.0f,
                    240.0f,
                    0.0f,
                    red, green, D_80036DD0[i]);
                D_80036DD0[i] -= 25;
            }
        }
        if (!(object_timer & 7))  D_global_asm_807FDC90->unk2C++;
        current_actor_pointer = current_actor_pointer;
        if (D_global_asm_807FBDC4 != 0) {
            current_actor_pointer->control_state = 0x1F;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer = current_actor_pointer;
        }
        break;
    case 0x1F:
        temp_s0 = (u32) ((func_global_asm_80612794(object_timer * 0x7D) * 100.0f) + 155.0f);
        func_global_asm_80659610(0x1388);
        createLight(
            D_global_asm_807FDCA0->unk14[5].unk0, 
            D_global_asm_807FDCA0->unk14[5].unk2 - 0x28A,
            D_global_asm_807FDCA0->unk14[5].unk4,
            0.0f, 0.0f, 0.0f, 240.0f, 0U,
            temp_s0, temp_s0, temp_s0);
        if (func_global_asm_80629148() != 0) {
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x19C, 0x64U, 0x7F, 0U, 0U, 0.0f, 0U);
            current_actor_pointer->control_state = 0x20;
            current_actor_pointer->control_state_progress = 0;
        }
        break;
    case 0x20:
        func_global_asm_8072A450();
        current_actor_pointer = current_actor_pointer;
        csp = current_actor_pointer->control_state_progress;
        switch (csp) {
        case 0:
            func_global_asm_80684A00(4, 1);
            sp7F = 1;
            func_global_asm_80729E6C();
            func_global_asm_806653C0(current_actor_pointer, 0.0f, current_actor_pointer->y_velocity);
            func_global_asm_80665564(current_actor_pointer, 0.0f);
            current_actor_pointer = current_actor_pointer;
            if (current_actor_pointer->locked_to_pad == 1) {
                current_actor_pointer->control_state_progress++;
                break;
            }
            break;
        case 1:
            if (func_global_asm_80629148() != 0) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            playActorAnimation(current_actor_pointer, 0x225);
            func_global_asm_80614D90(current_actor_pointer);
            fight_data->actions_remaining = 2U;
            pos_data->kong.current = 0xFFU;
            pos_data->jack.next = D_boss_80035BD8[2 & 0xFF];
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unk6A |= 1;

        case 3:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            current_actor_pointer->control_state_progress++;

        case 4:
            func_global_asm_8067ACB4(current_actor_pointer);
            func_global_asm_80665564(current_actor_pointer, 0.0f);
            func_boss_800334A4(pos_data, 0.025f);
            if (current_actor_pointer->animation_state->unk0->unk4 >= 40.0f) {
                current_actor_pointer->unk6A |= 1;
            } else {
                current_actor_pointer->unk6A = 0;
                func_global_asm_80684A00(4, 1);
                sp7F = 1;
            }
            break;
        case 5:
            pos_data->jack.current = pos_data->jack.next;
            if (fight_data->actions_remaining != 0) {
                pos_data->jack.next = D_boss_80035BD8[--fight_data->actions_remaining];
                current_actor_pointer->control_state_progress = 3;
            } else {
                playActorAnimation(current_actor_pointer, 0x224);
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 6:
            func_global_asm_8072E1A4(0xAU, player_pointer);
            break;
        case 7:
            playActorAnimation(current_actor_pointer, 0x222);
            current_actor_pointer->control_state_progress++;

        case 8:
            if (func_global_asm_80629148() != 0) {
                current_actor_pointer->control_state_progress++;
                playSoundAtActorPosition(current_actor_pointer, 0x128, 0xFFU, 0x19, 0U);
            }
            break;
        case 9:
            if (current_actor_pointer->unk0->unk38 < D_global_asm_807FDC90->unk30) {
                func_global_asm_807248B0(current_actor_pointer, current_actor_pointer->unk0->unk38 * 1.01);
                func_boss_800336C0();
                sp7F = 1;
            } else {
                playActorAnimation(current_actor_pointer, 0x227);
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 11:
            current_actor_pointer->unk6A &= 0xFFFE;
            if (func_global_asm_80629148() != 0) {
                playActorAnimation(current_actor_pointer, 0x22C);
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 13:
            func_global_asm_80626110(D_global_asm_807F5D10, D_global_asm_807FDCA0->unk14[0x11].unk0, D_global_asm_807FDCA0->unk14[0x11].unk4);
            fight_data->phase = 0U;
            fight_data->unk15 = 0U;
            current_actor_pointer->control_state = phase_sequence[0];
            fight_data->unk15++;
            current_actor_pointer->control_state_progress = 0;
            pos_data->kong.current = 5U;
            current_actor_pointer = current_actor_pointer;
            break;
        }
        break;
    case 0x23:
        func_global_asm_8072A450();
        current_actor_pointer = current_actor_pointer;
        csp = current_actor_pointer->control_state_progress;
        switch (csp) {
        case 0:
            phase_seq_val = phase_sequence[fight_data->unk15++];
            fight_data->actions_remaining = phase_seq_val;
            fight_data->action_type = phase_seq_val;
            func_boss_8003340C(pos_data);
            pos_data->jack.next = func_boss_800330D0(fight_data, pos_data);
            current_actor_pointer->control_state_progress = 1;
            current_actor_pointer->unk6A |= 1;

        case 1:
            current_actor_pointer->control_state_progress = 2;
            func_global_asm_80614D00(current_actor_pointer, D_boss_80036C40[fight_data->phase], 0.0f);
            pos_data->unk6 = has_fallen;

        case 2:
            func_global_asm_8067ACB4(current_actor_pointer);
            func_global_asm_80665564(current_actor_pointer, 0.0f);
            func_boss_800334A4(pos_data, current_actor_pointer->animation_state->unk64 == 0x223 ? 0.02173913f : 0.041666664f);
            unk_0 = current_actor_pointer->animation_state->unk64 == 0x223 ? 0x35 : 0x17;
            if (unk_0 <= current_actor_pointer->animation_state->unk0->unk4) {
                current_actor_pointer->unk6A |= 1;
            } else {
                current_actor_pointer->unk6A = 0;
                func_global_asm_80684A00(4, 1);
                sp7F = 1;
            }
            break;
        case 3:
            pos_data->kong.current = pos_data->jack.current;
            pos_data->jack.current = pos_data->jack.next;
            if (has_fallen != 0) {
                fight_data->actions_remaining = fight_data->action_type;
            }
            if (fight_data->actions_remaining != 0) {
                pos_data->jack.next = func_boss_800330D0(fight_data, pos_data);
                fight_data->actions_remaining--;
                func_boss_8003340C(pos_data);
                current_actor_pointer->control_state_progress = 1;
            } else {
                current_actor_pointer->control_state = phase_sequence[fight_data->unk15++];
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        }
        break;
    case 0x25:
    case 0x28:
        func_global_asm_8072E1A4(0xAU, player_pointer);
        if (func_boss_800339D8(fight_data, phase_sequence) != 0) {
            func_boss_80033784(pos_data, 0);
        } else if (func_global_asm_80724A20() == 0) {
            current_actor_pointer = current_actor_pointer;
            csp = current_actor_pointer->control_state_progress;
            switch (csp) {
            case 0:
                func_boss_80033784(pos_data, 0xA);
                fight_data->actions_remaining = phase_sequence[fight_data->unk15++] - 1;
                fight_data->action_type = phase_sequence[fight_data->unk15++];
                playActorAnimation(current_actor_pointer, 0x229);
                current_actor_pointer->control_state_progress = 1;
                break;
            case 2:
                if (current_actor_pointer->control_state == 0x25) {
                    playActorAnimation(current_actor_pointer, 0x228);
                    goto block_134;
                }
                if (!(D_global_asm_807FDC90->unk1A & 0x8000)) {
                    if (player_pointer->locked_to_pad == 1) {
                        playCutscene(current_actor_pointer, 0xF, 1);
                        D_global_asm_807FDC90->unk1A |= 0x8000;
                        goto block_133;
                    }
                } else {
block_133:
                    playActorAnimation(current_actor_pointer, 0x22F);
block_134:
                    current_actor_pointer->control_state_progress = 3;
                }
                break;
            case 3:
                if (current_actor_pointer->control_state == 0x25) {
                    func_global_asm_80684A00(3, 1);
                    sp7F = 1;
                } else {
                    getBonePosition(current_actor_pointer, 1, &x, &y, &z);
                    x += (((rand() >> 0xF) % 100) - 0x32);
                    y += (((rand() >> 0xF) % 100) + 0x32);
                    z += (((rand() >> 0xF) % 100) - 0x32);
                    func_global_asm_807149B8(1U);
                    func_global_asm_8071498C(func_global_asm_8071EDEC);
                    func_global_asm_80714950(current_actor_pointer);
                    drawSpriteAtPosition(&D_global_asm_8071FC58, 1.5f, x, y, z);
                    func_global_asm_80714C08(&D_global_asm_80720054, 3.0f, current_actor_pointer, 1, 2U);
                }
                break;
            case 4:
                if (current_actor_pointer->control_state == 0x25) {
                    func_global_asm_80690814(current_actor_pointer, 3);
                    func_global_asm_80690A28(0x3B, 1, 1.2f, player_pointer->x_position, player_pointer->y_position + 5.0f, player_pointer->z_position, 900.0f, current_actor_pointer);
                } else {
                    pos_data->jack.next = func_boss_800330D0(fight_data, pos_data);
                    func_boss_8003392C(pos_data);
                }
                current_actor_pointer->control_state_progress = 5;
                break;
            case 6:
                if (fight_data->actions_remaining) {
                    fight_data->actions_remaining--;
                    D_global_asm_807FDC90->unk2C = (s16) fight_data->action_type;
                    current_actor_pointer->control_state_progress = 7;
                } else {
                    playActorAnimation(current_actor_pointer, 0x22D);
                    current_actor_pointer->control_state_progress = 8;
                }
                break;
            case 7:
                if (D_global_asm_807FDC90->unk2C) {
                    if (player_pointer->control_state == 0x33) {
                        D_global_asm_807FDC90->unk2C = fight_data->action_type;
                    } else {
                        D_global_asm_807FDC90->unk2C--;
                    }
                } else {
                    current_actor_pointer->control_state_progress = 2;
                }
                break;
            case 9:
                func_boss_80033784(pos_data, 0);
                playActorAnimation(current_actor_pointer, 0x22C);
                current_actor_pointer->control_state_progress = 0xA;
                break;
            case 11:
                current_actor_pointer->control_state = phase_sequence[fight_data->unk15];
                fight_data->unk15 = (u8) (fight_data->unk15 + 1);
                current_actor_pointer->control_state_progress = 0;
                break;
            }
        }
        break;
    case 0x27:
        switch ((u8)current_actor_pointer->unk0) {
        case 0:
        case 1:
        case 2:
            func_global_asm_80697184();
            func_boss_80033784(pos_data, 0);
            playActorAnimation(current_actor_pointer, 0x22E);
            playCutscene(current_actor_pointer, 2, 1);
            func_global_asm_80687474(current_actor_pointer, 1.2f);
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x305, 0xFFU, 0x7F, 0U, 0U, 0.0f, 0U);
            current_actor_pointer->control_state_progress = 3;
            current_actor_pointer = current_actor_pointer;
            break;
        case 4:
            func_global_asm_8068780C(7U, 0xBU, 0x11U, 0x20U);
            func_global_asm_8068780C(0xCU, 0x10U, 0x11U, 0x20U);
            break;
        case 5:
            func_global_asm_806845B8(7U, 0x20U);
            if ((func_global_asm_80629148() != 0) || (func_global_asm_8061CB50() == 0)) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 6:
            if (fight_data->phase < 3) {
                playActorAnimation(current_actor_pointer, 0x22C);
            } else {
                current_actor_pointer->unk0++;
            }
            current_actor_pointer->control_state_progress++;
            current_actor_pointer = current_actor_pointer;
            break;
        case 8:
            func_global_asm_80629174();
            fight_data->unk15 = 0U;
            fight_data->phase++;
            current_actor_pointer->control_state = *D_boss_80035B84[fight_data->phase & 0xFF];
            fight_data->unk15++;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer = current_actor_pointer;
            break;
        }
        break;
    case 0x29:
        csp = current_actor_pointer->control_state_progress;
        switch (csp) {
        case 0:
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            playActorAnimation(current_actor_pointer, 0x231);
            fight_data->unk8 = (s16) (s8) phase_sequence[fight_data->unk15++];
            current_actor_pointer->control_state_progress++;
            current_actor_pointer = current_actor_pointer;
            break;
        case 2:
            func_global_asm_80684A00(2, 1);
            func_global_asm_80684A00(3, 1);
            sp7F = 1;
            break;
        case 3:
            func_global_asm_80684BB0(2, ((((rand() >> 0xF) % 32767) % 6) + 5), 0x28);
            func_global_asm_80684BB0(3, ((((rand() >> 0xF) % 32767) % 6) + 5), 0x28);
            sp7F = 1;
            break;
        case 4:
            func_boss_80033A80(fight_data->unk8);
            break;
        case 5:
            current_actor_pointer->unk0 = phase_sequence[fight_data->unk15++];
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer = current_actor_pointer;
            break;
        }
        break;
    case 0x2B:
        switch ((u8)current_actor_pointer->unk0) {
        case 0:
            playActorAnimation(current_actor_pointer, 0x222);
            D_global_asm_807FDC90->unk2C = 0x5A;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer = current_actor_pointer;
            break;
        case 1:
            if (D_global_asm_807FDC90->unk2C != 0) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                fight_16 = fight_data->unk16;
                fight_data->unk15 = fight_16;
                current_actor_pointer->control_state = phase_sequence[fight_16 & 0xFF];
                fight_data->unk15 = (u8) (fight_data->unk15 + 1);
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        }
        break;
    case 0x37:
        switch ((u8)current_actor_pointer->unk0) {
        case 0:
            playCutscene(current_actor_pointer, 6, 0x81);
            current_actor_pointer->control_state_progress++;
            current_actor_pointer = current_actor_pointer;
            break;
        case 1:
            if (func_global_asm_80629148() != 0) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            func_boss_80033A80(5);
            break;
        case 3:
            if (func_global_asm_80629148() != 0) {
                func_global_asm_8063DA40((s16) pos_data->jack.current, 0x1E);
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 4:
            if (func_global_asm_80629148() != 0) {
                func_global_asm_80685B44(&D_global_asm_80720BE8, 0U, 6.0f, 6U, 0x50U, 0x64, (s16) (s32) current_actor_pointer->x_position, (s16) (s32) (player_pointer->y_position + 100.0f), (s16) (s32) current_actor_pointer->z_position);
                func_global_asm_80685B44(&D_global_asm_80720BE8, 0x14U, 6.0f, 8U, 0x96U, 0x46, (s16) (s32) current_actor_pointer->x_position, (s16) (s32) (player_pointer->y_position + 100.0f), (s16) (s32) current_actor_pointer->z_position);
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 5:
            if (func_global_asm_8061CB50() == 0) {
                func_boss_80033784(pos_data, 0);
                square = pos_data->jack.current;
                for (i = 0; i < 0x10; i++) {
                    if (i != square) {
                        func_global_asm_8063DA40(i, 0x28);
                        square = pos_data->jack.current;
                    }
                }
                func_boss_80028478(0x8AU, D_global_asm_807FDCA0->unk14[square].unk0, D_global_asm_807FDCA0->unk14[square].unk2, D_global_asm_807FDCA0->unk14[square].unk4, 0x5DC, 1U);
                current_actor_pointer->control_state = 0x40;
                for (j = 0; j < 7; j++) {
                    func_global_asm_8072EC94(j, 0U);
                }
            }
            break;
        }
        break;
        case 0x0:
            csp = current_actor_pointer->control_state_progress;
            switch (csp) {
            case 0:
            case 1:
            case 2:
                func_boss_80033784(pos_data, 0);
                playActorAnimation(current_actor_pointer, 0x226);
                current_actor_pointer->control_state_progress = 3;
                current_actor_pointer = current_actor_pointer;
                break;
            case 3:
                if (player_pointer->control_state != 0x33) {
                    fight_data->unk15 = fight_data->unk16;
                    current_actor_pointer->control_state = phase_sequence[fight_data->unk15++];
                    current_actor_pointer->control_state_progress = 0;
                    current_actor_pointer = current_actor_pointer;
                }
                break;
            }
            break;
        default:
            func_boss_80027BA8(phase_sequence, 0, 0, &player_pointer);
            break;
    }
    if (sp7F != 0) {
        if (current_actor_pointer->unk6E[0] == -1) {
            func_global_asm_80604CBC(current_actor_pointer, 0x135, 0x4BU, 1U, 0U, 0xB4U, 1.0f, 0);
        }
    } else {
        func_global_asm_80605314(current_actor_pointer, 0U);
    }
    renderActor(current_actor_pointer, 0U);
}
*/


void func_boss_8003575C(void) {
    f32 dx, dz;

    switch (current_actor_pointer->control_state_progress) {
        case 1:
            if (current_actor_pointer->control_state == 0) {
                dx = player_pointer->x_position - current_actor_pointer->x_position;
                dz = player_pointer->z_position - current_actor_pointer->z_position;
                if (((dx * dx) + (dz * dz)) < 4225.0f) { // 65 units away from the player
                    if (player_pointer->control_state != 0x31) {
                        setAction(0x2E, current_actor_pointer, 0);
                    }
                    current_actor_pointer->control_state++;
                }
            }
            break;
        case 3:
            deleteActor(current_actor_pointer);
            break;
    }
    func_global_asm_8061EF4C(D_global_asm_807F5D10, 5, 0x14, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
    renderActor(current_actor_pointer, 0);
}