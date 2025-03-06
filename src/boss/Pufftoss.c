#include <ultra64.h>
#include "functions.h"

// .rodata
static const s32 D_boss_80036160[] = {
    0x2C01003C,
    0x4F460A00,
    0x50000000,
};

static const s32 D_boss_8003616C[] = {
    0x2B012C0C,
    0x001E4F46,
    0x05002D50,
};

static const s32 D_boss_80036178[] = {
    0x2B0C2C11,
    0x001E4F46,
    0x05002D28,
    0x14085000,
};

static const s32 D_boss_80036188[] = {
    0x2B112C16,
    0x00144F46,
    0x05002814,
    0x052A0000,
    0x50000000,
};

static const s32 D_boss_8003619C[] = {
    0x2B162C1B,
    0x001E4F46,
    0x05002A00,
    0x00460500,
    0x28140550,
};

// .data
static void *D_boss_80035A00[5] = {
    D_boss_80036160,
    D_boss_8003616C,
    D_boss_80036178,
    D_boss_80036188,
    D_boss_8003619C,
};

void func_boss_800292B0(f32 arg0) {
    func_global_asm_80691830(0x6A, 1.2f, 0, 0x96, 0xFF, 0xB, 1.015f, 0.0f, 0.0f, 0.0f);
    playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x221, 0x80, 0x7F, 1, 0, 0.3f, 0);
    gLastSpawnedActor->y_position = gCurrentActorPointer->y_position;
    gLastSpawnedActor->animation_state->scale_y *= arg0;
    func_global_asm_80613C48(gLastSpawnedActor, 0x4F9, 0.0f, 0.0f);
    func_global_asm_80614D00(gLastSpawnedActor, 1.5f, 0.0f);
}

void func_boss_800293C0(void) {
    rand();
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    changeActorColor(0x78, 0x78, 0x78, 0xC8);
    func_global_asm_8068588C(gCurrentActorPointer, (RandClamp(32767) % 16) + 3, 2.0f, 0.0f, 0.0f, 0.0f, -0x96);
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

    a178 = gCurrentActorPointer->unk178;
    sp44.unk0_s32 = D_boss_80035A00[a178->unk14].unk0_s32;
    sp42 = func_global_asm_80665DE0(gPlayerPointer->x_position, gPlayerPointer->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position);
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unkCE = 0x64;
        gCurrentActorPointer->unk15F = 0;
        D_global_asm_807FDC98->unk46 |= 0x20;
        gCurrentActorPointer->unk64 |= 4;
        gCurrentActorPointer->noclip_byte = 0x24;
        func_global_asm_80659670(0.0f, 0.0f, 0.0f, -1);
        a178->unk14 = 0;
        a178->unk15 = 0;
        gCurrentActorPointer->control_state = 0x1E;
        gCurrentActorPointer->control_state_progress = 0;
    }
    func_global_asm_80724A20();
    switch (gCurrentActorPointer->control_state) { // switch 5; irregular
        case 0x2D: // switch 5
            switch (gCurrentActorPointer->control_state_progress) { // switch 6; irregular
                case 0: // switch 6
                    playActorAnimation(gCurrentActorPointer, 0x219);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 2: // switch 6
                    func_boss_800292B0(1.8f);
                    D_global_asm_807FDC90->unk2C = 0x14;
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 3: // switch 6
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        func_boss_800292B0(1.0f);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 5: // switch 6
                    gCurrentActorPointer->control_state = sp44.unk0[a178->unk15];
                    a178->unk15++;
                    gCurrentActorPointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x1E: // switch 5
            switch (gCurrentActorPointer->control_state_progress) { // switch 2
                case 0: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gPlayerPointer, 0x3B1);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3B7);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 1: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gPlayerPointer, 0x3B2);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3B8);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gPlayerPointer, 0x3B3);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3B9);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 3: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gCurrentActorPointer, 0x217);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 4: // switch 2
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gPlayerPointer, 0x3B4);
                        playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x3BA);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 5: // switch 2
                    if (func_global_asm_80629148()) {
                        func_global_asm_80613C48(gPlayerPointer, 0x1C7, 0.0f, 0.0f);
                        gCurrentActorPointer->control_state = sp44.unk0[a178->unk15];
                        a178->unk15++;
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                    break;
            }
            break;
        case 0x2C: // switch 5
            func_global_asm_8063DA40(sp44.unk0[a178->unk15++], 0xA);
            gCurrentActorPointer->control_state = sp44.unk0[a178->unk15++];
            gCurrentActorPointer->control_state_progress = 0;
            break;
        case 0x2B: // switch 5
            a178->unk15++;
            func_global_asm_8063DA40(sp44.unk0[a178->unk15], 0);
            gCurrentActorPointer->control_state = sp44.unk0[a178->unk15];
            a178->unk15++;
            gCurrentActorPointer->control_state_progress = 0;
            break;
        case 0x4D: // switch 5
            if (a178->unk14 == 4) {
                gCurrentActorPointer->control_state = 0x37;
                gCurrentActorPointer->control_state_progress = 0;
                playCutscene(gCurrentActorPointer, 4, 1);
                func_global_asm_80697184();
            } else {
                switch (gCurrentActorPointer->control_state_progress) { // switch 3
                    case 0: // switch 3
                        gCurrentActorPointer->y_rotation = 0;
                        playActorAnimation(gCurrentActorPointer, 0x213);
                        playCutscene(gCurrentActorPointer, 2, 1);
                        func_global_asm_80697184();
                        gCurrentActorPointer->control_state_progress += 1;
                        break;
                    case 1: // switch 3
                        if (func_global_asm_80629148()) {
                            playActorAnimation(gCurrentActorPointer, 0x21A);
                            gCurrentActorPointer->control_state_progress += 1;
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
                        gCurrentActorPointer->control_state = D_boss_80035A00[++a178->unk14].unk0[0];
                        a178->unk15++;
                        gCurrentActorPointer->control_state_progress = 0;
                        break;
                }
            }
            break;
        case 0x28: // switch 5
        case 0x2A: // switch 5
            func_global_asm_8072E1A4(0x14, D_global_asm_807FDC94);
            goto block_61;
        case 0x46: // switch 5
            gCurrentActorPointer->y_rotation += D_global_asm_807FDC90->unk2E;
            if (func_global_asm_806CC10C(gCurrentActorPointer->y_rotation, sp42) > 0) {
                D_global_asm_807FDC90->unk2E = MAX(0x32, D_global_asm_807FDC90->unk2E + 2);
            } else {
                D_global_asm_807FDC90->unk2E = MIN(-0x32, D_global_asm_807FDC90->unk2E - 2);
            }
block_61:
            switch (gCurrentActorPointer->control_state_progress) { // switch 4
                case 0: // switch 4
                    temp_t8 = sp44.unk0[a178->unk15];
                    a178->unk15++;
                    a178->unk18 = temp_t8;
                    a178->unk19 = temp_t8;
                    a178->unk8 = sp44.unk0[a178->unk15++];
                    if (gCurrentActorPointer->control_state == 0x46) {
                        gCurrentActorPointer->control_state_progress = 2;
                    } else {
                        playActorAnimation(gCurrentActorPointer, 0x214);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2: // switch 4
                    if (func_global_asm_8061CB50() == 0) {
                        if (gCurrentActorPointer->control_state == 0x46) {
                            if (func_global_asm_806CC14C(gCurrentActorPointer->y_rotation, func_global_asm_80665DE0(gPlayerPointer->x_position, gPlayerPointer->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position)) < 0x320) {
                                playActorAnimation(gCurrentActorPointer, 0x218);
                                gCurrentActorPointer->control_state_progress++;
                            }
                        } else {
                            playActorAnimation(gCurrentActorPointer, 0x215);
                            gCurrentActorPointer->control_state_progress++;
                        }
                    }
                    break;
                case 4: // switch 4
                    playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0xF6, 0x37, 0x7F, 1, 0x1E, 0.3f, 0);
                    func_global_asm_80690814(gCurrentActorPointer, 2);
                    switch (gCurrentActorPointer->control_state) { // switch 7; irregular
                        case 0x2A: // switch 7
                            func_global_asm_80690A28(0xA9, 1, 1.0f, gPlayerPointer->x_position, gPlayerPointer->y_position + 2.0f, gPlayerPointer->z_position, 450.0f, gCurrentActorPointer);
                            playActorAnimation(gCurrentActorPointer, 0x213);
                            gCurrentActorPointer->control_state = sp44.unk0[a178->unk15];
                            a178->unk15++;
                            gCurrentActorPointer->control_state_progress = 0;
                            break;
                        case 0x46: // switch 7
                            func_global_asm_8069084C(0x1E, 0x63, 0.7f, gCurrentActorPointer->y_rotation, 300.0f, 0.0f, gCurrentActorPointer);
                            D_global_asm_807FDC90->unk2C = a178->unk8;
                            gCurrentActorPointer->control_state_progress = 8;
                            break;
                        default: // switch 7
                            func_global_asm_8069084C(0x1E, 5, 0.7f, gCurrentActorPointer->y_rotation, 600.0f, 500.0f, gCurrentActorPointer);
                            gCurrentActorPointer->control_state_progress++;
                            break;
                    }
                    break;
                case 6: // switch 4
                    playActorAnimation(gCurrentActorPointer, 0x213);
                    gCurrentActorPointer->control_state_progress++;
                    a178->unk18 = a178->unk19;
                    break;
                case 7: // switch 4
                    sp40 = RandClamp(1024) - 0x200;
                    sp3C = (func_global_asm_80612794(D_global_asm_807FDC94->y_rotation + sp40) * (D_global_asm_807FDC94->unkB8 * 1.2)) + D_global_asm_807FDC94->x_position;
                    temp_f2 = (func_global_asm_80612790(D_global_asm_807FDC94->y_rotation + sp40) * (D_global_asm_807FDC94->unkB8 * 1.2)) + D_global_asm_807FDC94->z_position;
                    func_global_asm_806907F0(sp3C, D_global_asm_807FDC94->y_position + 500.0f, temp_f2);
                    func_global_asm_80690A28(0x1E, 0x1E, 1.0f, sp3C, D_global_asm_807FDC94->y_position, temp_f2, 600.0f, gCurrentActorPointer);
                    D_global_asm_807FDC90->unk2C = a178->unk8;
                    gCurrentActorPointer->control_state_progress = 9;
                    // fallthrough
                case 9: // switch 4
                case 10: // switch 4
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        a178->unk18--;
                        if (a178->unk18) {
                            if (gCurrentActorPointer->control_state == 0x46) {
                                gCurrentActorPointer->control_state_progress = 2;
                            } else {
                                gCurrentActorPointer->control_state_progress = 7;
                            }
                        } else {
                            playActorAnimation(gCurrentActorPointer, 0x213);
                            gCurrentActorPointer->control_state = sp44.unk0[a178->unk15];
                            a178->unk15++;
                            gCurrentActorPointer->control_state_progress = 0;
                        }
                    }
                    break;
            }
            break;
        case 0x37: // switch 5
            if (func_global_asm_80629148()) {
                func_boss_80028478(0xA8, (s16)gCurrentActorPointer->x_position, (s16)gCurrentActorPointer->y_position, (s16)gCurrentActorPointer->z_position, 0x5DC, 1);
                gCurrentActorPointer->control_state = 0x40;
            }
            break;
        case 0x0: // switch 5
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                case 1:
                    playActorAnimation(gCurrentActorPointer, 0x213);
                    a178->unk8 = sp44.unk0[++a178->unk15];
                    gCurrentActorPointer->control_state_progress = 2;
                    break;
                default:
                    if (a178->unk8 != 0) {
                        a178->unk8--;
                    } else {
                        gCurrentActorPointer->control_state = sp44.unk0[a178->unk15];
                        a178->unk15++;
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                    break;
            }
            func_global_asm_8072AB74(0x23, 0.0f, 0.0f, 0x202, 0.0f);
            break;
        default: // switch 5
            func_boss_80027BA8(sp44.unk0_s32, 0, 0);
            break;
    }
    if (gCurrentActorPointer->y_position < gCurrentActorPointer->unkAC) {
        gCurrentActorPointer->y_position = gCurrentActorPointer->unkAC;
        gCurrentActorPointer->y_velocity = gCurrentActorPointer->y_acceleration;
    }
    renderActor(gCurrentActorPointer, 0);
}
*/
