#include <ultra64.h>
#include "functions.h"

void func_global_asm_80613CA8(Actor*, s16, f32, f32);
extern u8 D_global_asm_807FBD70;

// .rodata
const s32 D_boss_800368C0[] = {
    0x00546C51,
    0x03E44101,
    0x273C4102,
    0x27002801,
    0x005103E4,
    0x4F4B0104,
    0x271E4B01,
    0x04271E28,
    0x0C500000,
};

const s32 D_boss_800368E4[] = {
    0x6C4F4B01,
    0x0427144B,
    0x01042714,
    0x4B010427,
    0x00280A50,
};

const s32 D_boss_800368F8[] = {
    0x6C4F4101,
    0x270F4103,
    0x270F4102,
    0x270F4104,
    0x2700280A,
    0x50000000,
};

const s32 D_boss_80036910[] = {
    0x6C4F4B01,
    0x04270A27,
    0x0A670104,
    0x270A270A,
    0x67010427,
    0x00280A50,
    0x4F270150,
    0x0A27FF50,
    0x0A27FF50,
    0x0A27FF50,
    0x0A285050,
    0x4F27FF5A,
    0x0A27FF5A,
    0x0A27055A,
    0x0A270A5A,
    0x0A284650,
};

const s32 D_boss_80036950[] = {
    0x4F270578,
    0x0A270A78,
    0x0A27FF78,
    0x0A270978,
    0x0A270678,
    0x0A283C50,
};

const s32 D_boss_80036968[] = {
    0x4F270C78,
    0x0A270378,
    0x0A270A78,
    0x0A27FF78,
    0x0A270578,
    0x0A283250,
};

// .data
extern void *D_boss_80035A90[] = {
    D_boss_800368C0,
    D_boss_800368E4,
    D_boss_800368F8,
    D_boss_80036910,
    D_boss_800368C0,
};

extern void *D_boss_80035AA4[] = {
    D_boss_80036950,
    D_boss_80036968,
    D_boss_80036950,
    D_boss_80036968,
};

void func_boss_8002FC98(Actor *, u8, s32, u8);

u8 func_boss_80027BA8(u8 *, u16, f32);
void func_global_asm_806A2B38(Actor *);
void func_global_asm_806D0468(Actor *arg0, u8 arg1);
s32 func_global_asm_8072881C(s32, s32 *);
void func_global_asm_8072A450(void);
extern u8 D_global_asm_807FBD70;

void func_boss_8002F100(void) {
    KRoolChunkyAAD178 *temp_t0;
    u8 *temp_a0;
    u8 pad[8];
    f32 sp3C;

    temp_t0 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk132 = 8;
        setIntroStoryPlaying(0U);
        func_global_asm_80626110(D_global_asm_807F5D10, 0, 0);
        current_actor_pointer->unk146 = 5;
        current_actor_pointer->unkCC = 1;
        func_global_asm_80724CA4(2, 1);
        current_actor_pointer->control_state = 0x1E;
        current_actor_pointer->control_state_progress = 0;
        if (isFlagSet(0x54, 2U) != 0) {
            temp_t0->unk14 = 4U;
            current_actor_pointer->control_state = 0x37;
            current_actor_pointer->control_state_progress = 0;
        } else {
            if (isFlagSet(0x53, 2U) != 0) {
                temp_t0->unk14 = 3;
            } else {
                if (isFlagSet(0x52, 2U) != 0) {
                    temp_t0->unk14 = 2;
                } else {
                    if (isFlagSet(0x51, 2U) != 0) {
                        temp_t0->unk14 = 1;
                    }
                }
            }
        }
        if ((temp_t0->unk14 != 0) && (current_actor_pointer->control_state != 0x37)) {
            current_actor_pointer->control_state = 0x31;
            current_actor_pointer->control_state_progress = 0;
            func_global_asm_80724B5C(1U, 0U, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
        }
    }
    temp_a0 = D_boss_80035A90[temp_t0->unk14];
    func_boss_80028878(temp_a0);
    switch (current_actor_pointer->control_state) {
    case 0x28:
        if ((D_global_asm_807FBD70 == 5) && (character_change_array->unk2C0 != 1)) {
            current_actor_pointer->noclip_byte = 1;
            player_pointer->noclip_byte = 1;
            playCutscene(NULL, 2, 1);
            current_actor_pointer->control_state = 0x29;
            func_global_asm_806A2B38(current_actor_pointer->unk11C);
            func_global_asm_805FF158(1U);
            setIntroStoryPlaying(1U);
            func_global_asm_805FF378(MAP_KROOLS_SHOE, 0);
            player_pointer->x_position = (func_global_asm_80612794((s16) (current_actor_pointer->y_rotation + 0x320)) * 30.0) + current_actor_pointer->x_position;
            player_pointer->z_position = (func_global_asm_80612790((s16) (current_actor_pointer->y_rotation + 0x320)) * 30.0) + current_actor_pointer->z_position;
            sp3C = func_global_asm_80612794(current_actor_pointer->y_rotation + 0x384);
            func_global_asm_806F3BEC(player_pointer, 
                (sp3C * 15.0f) + current_actor_pointer->x_position,
                (func_global_asm_80612790(current_actor_pointer->y_rotation + 0x384) * 15.0f) + current_actor_pointer->z_position,
                0x50U);
        } else {
            switch (current_actor_pointer->control_state_progress) {
            case 0:
                if (temp_t0->unk16 != 0) {
                    func_global_asm_80641874(0, 0);
                }
                playActorAnimation(current_actor_pointer, 0x3FF);
                D_global_asm_807FDC90->unk2C = temp_a0[temp_t0->unk15++] * 0x1E;
                current_actor_pointer->control_state_progress++;
                break;
            case 1:
                if (D_global_asm_807FDC90->unk2C) {
                    D_global_asm_807FDC90->unk2C--;
                } else {
                    playActorAnimation(current_actor_pointer, 0x400);
                    current_actor_pointer->control_state_progress++;
                }
                break;
            case 3:
                if (character_change_array->unk2C0 != 1) {
                    func_global_asm_806D0468(player_pointer, 1);
                }
                func_global_asm_80641874(0, 0xFF);
                playActorAnimation(current_actor_pointer, 0x3E4);
                current_actor_pointer->control_state = temp_a0[temp_t0->unk15++];
                current_actor_pointer->control_state_progress = 0;
                break;
            }
        }
        break;
    case 0x27:
        func_global_asm_8072AB74(0U, 0.0f, 0.0f, 0x4310U, 0.0f);
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_8072B324(current_actor_pointer, 0);
            temp_t0->unk18 = (u8) temp_a0[temp_t0->unk15++];
            current_actor_pointer->control_state_progress++;
        case 1:
            D_global_asm_807FDC90->unk2C = 4;
            playActorAnimation(current_actor_pointer, 0x3E7);
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(
                current_actor_pointer->y_rotation, 
                func_global_asm_80665DE0(D_global_asm_807FDCA0->unk14->unk0, D_global_asm_807FDCA0->unk14->unk4, current_actor_pointer->x_position, current_actor_pointer->z_position)
                , 10.0f);
            break;
        case 3:
            if ((D_global_asm_807FDC90->unk2C) && (((u32) object_timer % 5U) == 0)) {
                func_global_asm_80691830(0xB8, 0.14f, 0x64U, 0xFFU, 0x96, 3, temp_t0->unk14 * 0.01 + 1.04, 0.0f, 0.0f, 0.0f);
                if (D_global_asm_807FDC90->unk2C-- < 4) {
                    last_spawned_actor->unk168 = 0;
                } else {
                    playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x25A, 0xFFU, 0x7F, 1U, 0U, 0.3f, 0U);
                }
                func_global_asm_80613C48(last_spawned_actor, 0x4F9, 0.0f, 0.0f);
                func_global_asm_80614D00(last_spawned_actor, 0.5f, 0.0f);
            } else if (D_global_asm_807FDC90->unk2C == 0) {
                D_global_asm_807FDC90->unk2C = temp_t0->unk18;
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 4:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
                playActorAnimation(current_actor_pointer, 0x3E4);
                current_actor_pointer->control_state = temp_a0[temp_t0->unk15++];
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        }
        break;
    case 0x1E:
        temp_t0->unk14 = 0U;
        temp_t0->unk15 = 0U;
        current_actor_pointer->control_state = temp_a0[temp_t0->unk15++];
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkC;
        break;
    case 0x0:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            playActorAnimation(current_actor_pointer, 0x3EA);
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            current_actor_pointer->control_state = temp_a0[temp_t0->unk15++];
            current_actor_pointer->control_state_progress = 0;
            break;
        }
        break;
    case 0x31:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806D0468(player_pointer, 0);
            func_global_asm_806D0468(player_pointer, 1);
            playCutscene(current_actor_pointer, 1, 1);
            playActorAnimation(current_actor_pointer, 0x3FB);
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            playActorAnimation(current_actor_pointer, 0x3E4);
            current_actor_pointer->control_state = temp_a0[temp_t0->unk15++];
            current_actor_pointer->control_state_progress = 0;
            break;
        }
        break;
    case 0x37:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            playActorAnimation(current_actor_pointer, 0);
            playCutscene(current_actor_pointer, 0x15, 1);
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            if (func_global_asm_80629148() != 0) {
                func_global_asm_805FF158(0U);
                func_global_asm_805FF378(MAP_KROOL_FIGHT_CHUNKY_PHASE, 0);
                current_actor_pointer->control_state_progress++;
            }
            break;
        }
        break;
    default:
        func_boss_80027BA8(temp_a0, 0x10, 0.0f);
        break;
    }
    func_global_asm_8072A450();
    if (func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28) != 0) {
        func_global_asm_8072881C(0x81, &D_global_asm_807FDC90->unk28);
    }
    renderActor(current_actor_pointer, 0U);
}



void func_boss_8002FB7C(u8 arg0) {
    AnimationStateUnk20 *temp_v0;

    temp_v0 = current_actor_pointer->animation_state->unk20;
    temp_v0->unk0 = 2;
    temp_v0->unk1 = 4;
    temp_v0->unk4 = 1;
    temp_v0->unk4 += arg0 * (0.04 + 0.04 * func_global_asm_80612794(object_timer << 7));
    temp_v0->unk8 = temp_v0->unk4;
    temp_v0->unkC = 1;
}

void func_boss_8002FC48(Actor *arg0, u8 arg1) {
    func_global_asm_8068842C(arg0, 0, 1);
    func_global_asm_80688460(arg0, 0, 1);
    func_global_asm_806883F4(arg0, 0, arg1, 0);
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KRoolTiny/func_boss_8002FC98.s")

typedef struct {
    s32 unk0[4];
} A17C_8002FC98;

/*
void func_boss_8002FC98(Actor *arg0, u8 arg1, s32 arg2, u8 arg3) {
    A17C_8002FC98 *a17C;
    s16 i;

    a17C = arg0->unk17C;
    for (i = 0; i < 4; i++) {
        if (arg1 & (1 << i)) {
            if (i != 0) {
                arg0 = a17C->unk0[i - 1];
            }
            switch (arg2) {
                case -1:
                case 0:
                    arg0->unk132 = arg2;
                    break;
                case 1:
                case 2:
                    arg0->unk132 = arg2;
                    arg0->unk138 = arg2;
                    break;
                default:
                    playActorAnimation(arg0, arg2);
                    if (arg3 != 0) {
                        func_global_asm_80614D00(arg0, arg3 * 0.01, 0);
                    }
                    break;
            }
        }
    }
}
*/

void func_boss_8002FDF8(Actor* arg0, u8 arg1) {
    s32 phi_v0;
    Actor *temp;

    if (current_actor_pointer->unk15F == 2) {
        phi_v0 = 4;
    } else {
        phi_v0 = arg1;
    }
    func_boss_8002FB7C(phi_v0);
    if (D_global_asm_807FBD70 == 4) {
        func_boss_8002FC98(arg0, 0xF, 0, 0);
        // Note: This temporary variable appears to be required for this function to match
        temp = current_actor_pointer;
        func_boss_8002FC48(temp, 10 - temp->health);
        playActorAnimation(current_actor_pointer, 0x415);
    }
    if ((D_global_asm_807FBD70 == 5) || (D_global_asm_807FBD70 == 4)) {
        func_global_asm_8072DA60();
    }
}

void func_boss_8002FEC0(Actor* toes[], u8 toeIndex, s32 modelIndex) {
    spawnActor(ACTOR_BOSS_KROOL_TOE, modelIndex);
    moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
    last_spawned_actor->object_properties_bitfield |= 0x1400;
    last_spawned_actor->unk11C = current_actor_pointer;
    last_spawned_actor->noclip_byte = current_actor_pointer->noclip_byte;
    last_spawned_actor->object_properties_bitfield = current_actor_pointer->object_properties_bitfield;
    toes[toeIndex] = last_spawned_actor;
}

u8 func_boss_80027BA8(u8 *, u16, f32);
s32 func_global_asm_8061F2B8(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);

typedef struct KRoolFootAAD178 {
    Actor *unk0;
    u8 pad4[0x8 - 0x4];
    s16 unk8;
    u8 padA[0x12 - 0xA];
    u16 unk12;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
} KRoolFootAAD178;

typedef struct KRoolFootAAD17C {
    Actor *toes[3];
} KRoolFootAAD17C;

void func_boss_8002FF74(void) {
    KRoolFootAAD178 *temp_s1;
    KRoolFootAAD17C *sp68;
    u8 *sp64;
    f32 sp60;
    u8 temp_a0;
    u8 var_a1;

    temp_s1 = current_actor_pointer->unk178;
    sp68 = current_actor_pointer->unk17C;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        setIntroStoryPlaying(0U);
        func_global_asm_806FB370(2U, 0U, 1U);
        player_pointer->control_state = 0x5F;
        player_pointer->control_state_progress = 0;
        playAnimation(player_pointer, 0x4B);
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_80724DB0(2, 1);
        func_boss_8002FEC0(sp68, 0U, 0x6D);
        func_boss_8002FEC0(sp68, 1U, 0x6E);
        func_boss_8002FEC0(sp68, 2U, 0x6F);
        temp_s1->unk12 = 0U;
        if (isFlagSet(0x51, FLAG_TYPE_TEMPORARY) != 0) {
            func_boss_8002FC48(current_actor_pointer, 4U);
            current_actor_pointer->unk15F = 2;
            sp68->toes[0]->unk15F = 1;
            temp_s1->unk12 = 1U;
        }
        if (isFlagSet(0x52, FLAG_TYPE_TEMPORARY) != 0) {
            func_boss_8002FC48(sp68->toes[0], 4U);
            sp68->toes[0]->unk15F = 2;
            sp68->toes[1]->unk15F = 1;
            temp_s1->unk12 = 2;
        }
        if (isFlagSet(0x53, FLAG_TYPE_TEMPORARY) != 0) {
            func_boss_8002FC48(sp68->toes[1], 4U);
            sp68->toes[1]->unk15F = 2;
            sp68->toes[2]->unk15F = 1;
            temp_s1->unk12 = 3U;
        }
        temp_s1->unk14 = 0U;
        func_boss_8002FC98(current_actor_pointer, 0xFU, 0x40E, 0);
    }
    sp64 = D_boss_80035AA4[temp_s1->unk14];
    if (current_actor_pointer->control_state != 0) {
        func_global_asm_8061F2B8(
            player_pointer->x_position, 
            player_pointer->y_position,
            player_pointer->z_position,
            D_global_asm_807FDCA0->unk14->unk0,
            D_global_asm_807FDCA0->unk14->unk2, 
            D_global_asm_807FDCA0->unk14->unk4, 
            D_global_asm_807FDCA0->unk14[1].unk0, 
            D_global_asm_807FDCA0->unk14[1].unk2, 
            D_global_asm_807FDCA0->unk14[1].unk4, 
            &player_pointer->x_position,
            &sp60,
            &player_pointer->z_position);
        player_pointer->y_rotation = 0xFD2;
        extra_player_info_pointer->unk38 = 150.0f;
    }
    func_boss_8002FDF8(current_actor_pointer, temp_s1->unk14);
    func_boss_8002FC98(current_actor_pointer, 1 << temp_s1->unk12, 1, 0);
    switch (current_actor_pointer->control_state) {
    case 0x1F:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            D_global_asm_807FDC90->unk2C = sp64[temp_s1->unk15++];
            current_actor_pointer->control_state_progress++;
        case 1:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                current_actor_pointer->control_state = sp64[temp_s1->unk15++];
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        }
        break;
    case 0x37:
        if (current_actor_pointer->control_state_progress == 0) {
            player_pointer->control_state = 0x5F;
            player_pointer->control_state_progress = 0;
            playAnimation(player_pointer, 0x4A);
            func_global_asm_805FF158(1U);
            setIntroStoryPlaying(1U);
            func_global_asm_805FF378(MAP_KROOL_FIGHT_TINY_PHASE, 0);
            setFlag(temp_s1->unk12 + 0x51, 1U, FLAG_TYPE_TEMPORARY);
            current_actor_pointer->control_state_progress++;
            break;
        }
        break;
    case 0x0:
        func_global_asm_80724A20();
        break;
    case 0x1:
        func_boss_8002FC98(current_actor_pointer, 0xFU, 0x410, 0);
        current_actor_pointer->control_state = sp64[temp_s1->unk15++];
        current_actor_pointer->control_state_progress = 0;
        break;
    case 0x27:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->control_state_progress++;
            func_boss_8002FC98(current_actor_pointer, 0xFU, -1, 0);
            temp_s1->unk18 = sp64[temp_s1->unk15++];
            temp_s1->unk19 = sp64[temp_s1->unk15++] + (temp_s1->unk12 * 0xA);
            temp_s1->unk8 = sp64[temp_s1->unk15++];
            if (temp_s1->unk18 == 0xFF) {
                temp_s1->unk18 = 8 >> (s32) ((player_pointer->x_position - 117.0f) / 50.0f);
            }
            func_boss_8002FC98(current_actor_pointer, temp_s1->unk18, 0x413, 0);
            D_global_asm_807FDC90->unk2C = 0x14;
            break;
        case 1:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            current_actor_pointer->control_state_progress++;
            func_boss_8002FC98(current_actor_pointer, temp_s1->unk18, 0x414, temp_s1->unk19 + (temp_s1->unk12 * 0xF));
            D_global_asm_807FDC90->unk2C = temp_s1->unk8;
        case 3:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                current_actor_pointer->control_state = sp64[temp_s1->unk15++];
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        }
        break;
    case 0x28:
        func_boss_8002FC98(current_actor_pointer, 1 << temp_s1->unk12, 2, 0);
        if ((temp_s1->unk14 == temp_s1->unk12) && (current_actor_pointer->unk138 == 0)) {
            current_actor_pointer->control_state = 0x37;
            current_actor_pointer->control_state_progress = 0;
            break;
        }
        switch (current_actor_pointer->control_state_progress) {
            case 0:
                D_global_asm_807FDC90->unk2C = sp64[temp_s1->unk15++];
                func_boss_8002FC98(current_actor_pointer, 1 << temp_s1->unk12, 0x411, 0);
                current_actor_pointer->control_state_progress++;
                break;
            case 1:
            case 2:
                if (D_global_asm_807FDC90->unk2C) {
                    D_global_asm_807FDC90->unk2C--;
                } else {
                    if ((current_actor_pointer->control_state_progress == 1) && (current_actor_pointer->unk138 != 0)) {
                        func_boss_8002FC98(current_actor_pointer, 1 << temp_s1->unk12, 0x412, 0);
                    }
                    D_global_asm_807FDC90->unk2C = 0xA;
                    current_actor_pointer->control_state_progress++;
                }
                break;
            case 3:
                if (current_actor_pointer->unk138 == 0) {
                    temp_s1->unk14++;
                    temp_s1->unk15 = 0U;
                    sp64 = D_boss_80035AA4[temp_s1->unk14];
                }
                current_actor_pointer->control_state = sp64[temp_s1->unk15++];
                current_actor_pointer->control_state_progress = 0;
                break;
        }
        break;
    case 0x29:
        if (current_actor_pointer->control_state_progress == 0) {

        }
        break;
    default:
        func_boss_80027BA8(sp64, 0, 0);
        break;
    }
    renderActor(current_actor_pointer, 0U);
}



void func_boss_80030888(void) {
    Actor* temp;
    Actor178* temp_2;
    s32 phi_v0_2;

    temp = current_actor_pointer->unk11C;
    temp_2  = temp->unk178;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724DB0(2, 1);
    }
    if (current_actor_pointer->unk15F == 1) {
        phi_v0_2 = temp_2->unk14;
    } else {
        phi_v0_2 = 0U;
    }
    func_boss_8002FDF8(temp, phi_v0_2);
    renderActor(current_actor_pointer, 0);
}
