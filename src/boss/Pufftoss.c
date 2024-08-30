#include <ultra64.h>
#include "functions.h"

const s32 D_boss_80036160[] = {
    0x2C01003C,
    0x4F460A00,
    0x50000000,
};

const s32 D_boss_8003616C[] = {
    0x2B012C0C,
    0x001E4F46,
    0x05002D50,
};

const s32 D_boss_80036178[] = {
    0x2B0C2C11,
    0x001E4F46,
    0x05002D28,
    0x14085000,
};

const s32 D_boss_80036188[] = {
    0x2B112C16,
    0x00144F46,
    0x05002814,
    0x052A0000,
    0x50000000,
};

const s32 D_boss_8003619C[] = {
    0x2B162C1B,
    0x001E4F46,
    0x05002A00,
    0x00460500,
    0x28140550,
};

void func_boss_800292B0(f32 arg0) {
    func_global_asm_80691830(0x6A, 1.2f, 0, 0x96, 0xFF, 0xB, 1.015f, 0.0f, 0.0f, 0.0f);
    playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x221, 0x80, 0x7F, 1, 0, 0.3f, 0);
    last_spawned_actor->y_position = current_actor_pointer->y_position;
    last_spawned_actor->animation_state->scale_y *= arg0;
    func_global_asm_80613C48(last_spawned_actor, 0x4F9, 0.0f, 0.0f);
    func_global_asm_80614D00(last_spawned_actor, 1.5f, 0.0f);
}

void func_boss_800293C0(void) {
    rand();
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    changeActorColor(0x78, 0x78, 0x78, 0xC8);
    func_global_asm_8068588C(current_actor_pointer, (((rand() >> 0xF) % 32767) % 16) + 3, 2.0f, 0.0f, 0.0f, 0.0f, -0x96);
}

// Jumptable, doable
// https://decomp.me/scratch/hG5eF
#pragma GLOBAL_ASM("asm/nonmatchings/boss/Pufftoss/func_boss_80029468.s")

s32 func_boss_80027BA8(void*, s32, f32);
typedef struct {
    union {
        s32 unk0_s32;
        u8 unk0[4];
    };
} TEMP_U8_4;

extern TEMP_U8_4 D_boss_80035A00[];

typedef struct {
    u8 unk0[0x8 - 0x0];
    s16 unk8;
    u8 unkA[0x14 - 0xA];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
} A178_80029468;

/*
void func_boss_80029468(void) {
    f32 temp_f2;
    u8 temp_t8;
    A178_80029468 *a178; // 4C
    TEMP_U8_4 sp44;
    s16 sp42;
    s16 sp40;
    f32 sp3C;

    a178 = current_actor_pointer->unk178;
    sp44.unk0_s32 = D_boss_80035A00[a178->unk14].unk0_s32;
    sp42 = func_global_asm_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkCE = 0x64;
        current_actor_pointer->unk15F = 0;
        D_global_asm_807FDC98->unk46 |= 0x20;
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->noclip_byte = 0x24;
        func_global_asm_80659670(0.0f, 0.0f, 0.0f, -1);
        a178->unk14 = 0;
        a178->unk15 = 0;
        current_actor_pointer->control_state = 0x1E;
        current_actor_pointer->control_state_progress = 0;
    }
    func_global_asm_80724A20();
    switch (current_actor_pointer->control_state) { // switch 5; irregular
        case 0x2D: // switch 5
            switch (current_actor_pointer->control_state_progress) { // switch 6; irregular
                case 0: // switch 6
                    playActorAnimation(current_actor_pointer, 0x219);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 2: // switch 6
                    func_boss_800292B0(1.8f);
                    D_global_asm_807FDC90->unk2C = 0x14;
                    current_actor_pointer->control_state_progress++;
                    break;
                case 3: // switch 6
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        func_boss_800292B0(1.0f);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 5: // switch 6
                    current_actor_pointer->control_state = sp44.unk0[a178->unk15];
                    a178->unk15++;
                    current_actor_pointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x1E: // switch 5
            switch (current_actor_pointer->control_state_progress) { // switch 2
                case 0: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(player_pointer, 0x3B1);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3B7);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 1: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(player_pointer, 0x3B2);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3B8);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 2: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(player_pointer, 0x3B3);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3B9);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 3: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(current_actor_pointer, 0x217);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 4: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(player_pointer, 0x3B4);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3BA);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 5: // switch 2
                    if (func_global_asm_80629148()) {
                        func_global_asm_80613C48(player_pointer, 0x1C7, 0.0f, 0.0f);
                        current_actor_pointer->control_state = sp44.unk0[a178->unk15];
                        a178->unk15++;
                        current_actor_pointer->control_state_progress = 0;
                    }
                    break;
            }
            break;
        case 0x2C: // switch 5
            func_global_asm_8063DA40(sp44.unk0[a178->unk15++], 0xA);
            current_actor_pointer->control_state = sp44.unk0[a178->unk15++];
            current_actor_pointer->control_state_progress = 0;
            break;
        case 0x2B: // switch 5
            a178->unk15++;
            func_global_asm_8063DA40(sp44.unk0[a178->unk15], 0);
            current_actor_pointer->control_state = sp44.unk0[a178->unk15];
            a178->unk15++;
            current_actor_pointer->control_state_progress = 0;
            break;
        case 0x4D: // switch 5
            if (a178->unk14 == 4) {
                current_actor_pointer->control_state = 0x37;
                current_actor_pointer->control_state_progress = 0;
                playCutscene(current_actor_pointer, 4, 1);
                func_global_asm_80697184();
            } else {
                switch (current_actor_pointer->control_state_progress) { // switch 3
                    case 0: // switch 3
                        current_actor_pointer->y_rotation = 0;
                        playActorAnimation(current_actor_pointer, 0x213);
                        playCutscene(current_actor_pointer, 2, 1);
                        func_global_asm_80697184();
                        current_actor_pointer->control_state_progress += 1;
                        break;
                    case 1: // switch 3
                        if (func_global_asm_80629148()) {
                            playActorAnimation(current_actor_pointer, 0x21A);
                            current_actor_pointer->control_state_progress += 1;
                        }
                        break;
                    case 2: // switch 3
                        func_global_asm_8068780C(3, 6, 7, 0xA);
                        func_global_asm_8068780C(0xB, 0xE, 0xF, 0x12);
                        break;
                    case 3: // switch 3
                        if (!(object_timer & 3)) {
                            func_boss_800293C0();
                        }
                        break;
                    case 4: // switch 3
                        func_global_asm_8063DA40(0, 0);
                        func_global_asm_8063DA40(6, 0);
                        func_global_asm_8063DA40(7, 0);
                        func_global_asm_8063DA40(9, 0);
                        func_global_asm_8063DA40(0xB, 0);
                        a178->unk15 = 0;
                        current_actor_pointer->control_state = D_boss_80035A00[++a178->unk14].unk0[0];
                        a178->unk15++;
                        current_actor_pointer->control_state_progress = 0;
                        break;
                }
            }
            break;
        case 0x28: // switch 5
        case 0x2A: // switch 5
            func_global_asm_8072E1A4(0x14, D_global_asm_807FDC94);
            goto block_61;
        case 0x46: // switch 5
            current_actor_pointer->y_rotation += D_global_asm_807FDC90->unk2E;
            if (func_global_asm_806CC10C(current_actor_pointer->y_rotation, sp42) > 0) {
                D_global_asm_807FDC90->unk2E = MAX(0x32, D_global_asm_807FDC90->unk2E + 2);
            } else {
                D_global_asm_807FDC90->unk2E = MIN(-0x32, D_global_asm_807FDC90->unk2E - 2);
            }
block_61:
            switch (current_actor_pointer->control_state_progress) { // switch 4
                case 0: // switch 4
                    temp_t8 = sp44.unk0[a178->unk15];
                    a178->unk15++;
                    a178->unk18 = temp_t8;
                    a178->unk19 = temp_t8;
                    a178->unk8 = sp44.unk0[a178->unk15++];
                    if (current_actor_pointer->control_state == 0x46) {
                        current_actor_pointer->control_state_progress = 2;
                    } else {
                        playActorAnimation(current_actor_pointer, 0x214);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 2: // switch 4
                    if (func_global_asm_8061CB50() == 0) {
                        if (current_actor_pointer->control_state == 0x46) {
                            if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, func_global_asm_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position)) < 0x320) {
                                playActorAnimation(current_actor_pointer, 0x218);
                                current_actor_pointer->control_state_progress++;
                            }
                        } else {
                            playActorAnimation(current_actor_pointer, 0x215);
                            current_actor_pointer->control_state_progress++;
                        }
                    }
                    break;
                case 4: // switch 4
                    playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xF6, 0x37, 0x7F, 1, 0x1E, 0.3f, 0);
                    func_global_asm_80690814(current_actor_pointer, 2);
                    switch (current_actor_pointer->control_state) { // switch 7; irregular
                        case 0x2A: // switch 7
                            func_global_asm_80690A28(0xA9, 1, 1.0f, player_pointer->x_position, player_pointer->y_position + 2.0f, player_pointer->z_position, 450.0f, current_actor_pointer);
                            playActorAnimation(current_actor_pointer, 0x213);
                            current_actor_pointer->control_state = sp44.unk0[a178->unk15];
                            a178->unk15++;
                            current_actor_pointer->control_state_progress = 0;
                            break;
                        case 0x46: // switch 7
                            func_global_asm_8069084C(0x1E, 0x63, 0.7f, current_actor_pointer->y_rotation, 300.0f, 0.0f, current_actor_pointer);
                            D_global_asm_807FDC90->unk2C = a178->unk8;
                            current_actor_pointer->control_state_progress = 8;
                            break;
                        default: // switch 7
                            func_global_asm_8069084C(0x1E, 5, 0.7f, current_actor_pointer->y_rotation, 600.0f, 500.0f, current_actor_pointer);
                            current_actor_pointer->control_state_progress++;
                            break;
                    }
                    break;
                case 6: // switch 4
                    playActorAnimation(current_actor_pointer, 0x213);
                    current_actor_pointer->control_state_progress++;
                    a178->unk18 = a178->unk19;
                    break;
                case 7: // switch 4
                    sp40 = ((rand() >> 0xF) % 1024) - 0x200;
                    sp3C = (func_global_asm_80612794(D_global_asm_807FDC94->y_rotation + sp40) * (D_global_asm_807FDC94->unkB8 * 1.2)) + D_global_asm_807FDC94->x_position;
                    temp_f2 = (func_global_asm_80612790(D_global_asm_807FDC94->y_rotation + sp40) * (D_global_asm_807FDC94->unkB8 * 1.2)) + D_global_asm_807FDC94->z_position;
                    func_global_asm_806907F0(sp3C, D_global_asm_807FDC94->y_position + 500.0f, temp_f2);
                    func_global_asm_80690A28(0x1E, 0x1E, 1.0f, sp3C, D_global_asm_807FDC94->y_position, temp_f2, 600.0f, current_actor_pointer);
                    D_global_asm_807FDC90->unk2C = a178->unk8;
                    current_actor_pointer->control_state_progress = 9;
                    // fallthrough
                case 9: // switch 4
                case 10: // switch 4
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        a178->unk18--;
                        if (a178->unk18) {
                            if (current_actor_pointer->control_state == 0x46) {
                                current_actor_pointer->control_state_progress = 2;
                            } else {
                                current_actor_pointer->control_state_progress = 7;
                            }
                        } else {
                            playActorAnimation(current_actor_pointer, 0x213);
                            current_actor_pointer->control_state = sp44.unk0[a178->unk15];
                            a178->unk15++;
                            current_actor_pointer->control_state_progress = 0;
                        }
                    }
                    break;
            }
            break;
        case 0x37: // switch 5
            if (func_global_asm_80629148()) {
                func_boss_80028478(0xA8, (s16)current_actor_pointer->x_position, (s16)current_actor_pointer->y_position, (s16)current_actor_pointer->z_position, 0x5DC, 1);
                current_actor_pointer->control_state = 0x40;
            }
            break;
        case 0x0: // switch 5
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                case 1:
                    playActorAnimation(current_actor_pointer, 0x213);
                    a178->unk8 = sp44.unk0[++a178->unk15];
                    current_actor_pointer->control_state_progress = 2;
                    break;
                default:
                    if (a178->unk8 != 0) {
                        a178->unk8--;
                    } else {
                        current_actor_pointer->control_state = sp44.unk0[a178->unk15];
                        a178->unk15++;
                        current_actor_pointer->control_state_progress = 0;
                    }
                    break;
            }
            func_global_asm_8072AB74(0x23, 0.0f, 0.0f, 0x202, 0.0f);
            break;
        default: // switch 5
            func_boss_80027BA8(sp44.unk0_s32, 0, 0);
            break;
    }
    if (current_actor_pointer->y_position < current_actor_pointer->unkAC) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC;
        current_actor_pointer->y_velocity = current_actor_pointer->y_acceleration;
    }
    renderActor(current_actor_pointer, 0);
}
*/
