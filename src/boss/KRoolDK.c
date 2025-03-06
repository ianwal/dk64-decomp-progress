#include "common.h"

static const s32 D_boss_80036660[] = {
    0x00546C51,
    0x03E44100,
    0x283C283C,
    0x283C5F00,
    0x2B4F2878,
    0x29037850,
};

static const s32 D_boss_80036678[] = {
    0x28055103,
    0xE441004F,
    0x28142904,
    0x2D500000,
};

static const s32 D_boss_80036688[] = {
    0x28055103,
    0xE441004F,
    0x2C0F2A02,
    0x14290428,
    0x50000000,
};

static const s32 D_boss_8003669C[] = {
    0x28055103,
    0xE441004F,
    0x2C0A2906,
    0x1E500000,
};

// .data
static void *D_boss_80035A50[] = {
    D_boss_80036660,
    D_boss_80036678,
    D_boss_80036688,
    D_boss_8003669C,
};

u8 func_boss_80027BA8(u8 *, u16, f32);
s32 func_global_asm_8072881C(s32, s32 *);
void func_global_asm_8072A450(void);
extern u8 D_global_asm_807FBD70;

typedef struct KRoolDKAAD178 {
    Actor *unk0;
    u8 pad4[0x14 - 0x4];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
} KRoolDKAAD178;

void func_boss_8002D230(void) {
    KRoolDKAAD178 *temp_t0;
    void *temp_t1;
    u8 *sp3C;

    temp_t0 = gCurrentActorPointer->unk178;
    sp3C = D_boss_80035A50[temp_t0->unk14];
    initializeCharacterSpawnerActor();
    func_boss_80028878(sp3C);
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80626110(D_global_asm_807F5D10, 0, 0);
        gCurrentActorPointer->unk146_s16 = 5;
        gCurrentActorPointer->control_state = 0x1E;
        gCurrentActorPointer->control_state_progress = 0;
        gCurrentActorPointer->unkCC = 1;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x2B:
            func_global_asm_80641874(1, 0);
            func_global_asm_80641874(2, 0);
            func_global_asm_80641874(3, 0);
            func_global_asm_80641874(4, 0);
            gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
            gCurrentActorPointer->control_state_progress = 0;
            break;
        case 0x1E:
            temp_t0->unk14 = 0U;
            temp_t0->unk15 = 0U;
            gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
            gCurrentActorPointer->control_state_progress = 0;
            gCurrentActorPointer->unkB8 = D_global_asm_807FDC9C->unkC;
            break;
        case 0x0:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    playActorAnimation(gCurrentActorPointer, 0x3EA);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 2:
                    gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
                    gCurrentActorPointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x29:
        case 0x2A:
            func_global_asm_8072E1A4(0xAU, gPlayerPointer);
            if (D_global_asm_807FBD70 == 4) {
                func_global_asm_80641874(extra_player_info_pointer->unkBE, 1);
                if (temp_t0->unk14 == 3) {
                    gCurrentActorPointer->control_state = 0x37;
                    gCurrentActorPointer->control_state_progress = 0;
                } else {
                    func_global_asm_8072DEA8(0x3EE, 0x31U, gPlayerPointer);
                    playCutscene(gCurrentActorPointer, 1, 1);
                    gCurrentActorPointer->unkB8 = (f32) ((f64) gCurrentActorPointer->unkB8 * 0.7);
                }
            } else if ((D_global_asm_807FBD70 == 2) && ((s32) gCurrentActorPointer->control_state_progress > 0)) {
                playActorAnimation(gCurrentActorPointer, 0);
                gCurrentActorPointer->control_state = 0;
                gCurrentActorPointer->control_state_progress = 0;
            } else {
                if ((gPlayerPointer->control_state != 0x42) && (gPlayerPointer->control_state != 0x44) && (gCurrentActorPointer->control_state_progress > 0)) {
                    playActorAnimation(gCurrentActorPointer, 0);
                    gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
                    gCurrentActorPointer->control_state_progress = 0;
                } else {
                    switch (gCurrentActorPointer->control_state_progress) {
                        case 0:
                            temp_t0->unk18 = sp3C[temp_t0->unk15++];
                            temp_t0->unk19 = sp3C[temp_t0->unk15++];
                            gCurrentActorPointer->control_state_progress++;
        
                        case 1:
                            D_global_asm_807FDC90->unk2C = temp_t0->unk18;
                            gCurrentActorPointer->control_state_progress++;
        
                        case 2:
                            gCurrentActorPointer->unk132 = 1;
                            playActorAnimation(gCurrentActorPointer, 0x3EC);
                            gCurrentActorPointer->control_state_progress++;
                            break;
                        case 4:
                            if (D_global_asm_807FDC90->unk2C) {
                                D_global_asm_807FDC90->unk2C--;
                                gCurrentActorPointer->control_state_progress = 2;
                            } else {
                                gCurrentActorPointer->unk132 = 2;
                                playActorAnimation(gCurrentActorPointer, 0x3E9);
                                D_global_asm_807FDC90->unk2C = temp_t0->unk19;
                                gCurrentActorPointer->control_state_progress++;
                            }
                            break;
                        case 5:
                            if (D_global_asm_807FDC90->unk2C) {
                                D_global_asm_807FDC90->unk2C--;
                            } else if (gCurrentActorPointer->control_state == 0x2A) {
                                gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
                                gCurrentActorPointer->control_state_progress = 0;
                            } else {
                                gCurrentActorPointer->control_state_progress = 1;
                            }
                            break;
                    }
                }
            }
            break;
        case 0x28:
        case 0x2C:
            func_global_asm_8072E1A4(0xAU, gPlayerPointer);
            if ((gPlayerPointer->control_state == 0x42) && ((s32) gCurrentActorPointer->control_state_progress > 0)) {
                playActorAnimation(gCurrentActorPointer, 0);
                gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
                gCurrentActorPointer->control_state_progress = 0;
            } else {
                switch (gCurrentActorPointer->control_state_progress) {
                    case 0:
                        temp_t0->unk18 = sp3C[temp_t0->unk15++];
                        gCurrentActorPointer->control_state_progress++;
        
                    case 1:
                        if (func_global_asm_8061CB50() == 0) {
                            D_global_asm_807FDC90->unk2C = (s16) temp_t0->unk18;
                            D_global_asm_807FDC90->unk2E = 9;
                            playActorAnimation(gCurrentActorPointer, 0x3E7);
                            gCurrentActorPointer->control_state_progress++;
                        }
                        break;
                    case 3:
                        if ((gCurrentActorPointer->control_state == 0x28) || ((gCurrentActorPointer->control_state == 0x2C) && ((D_global_asm_807FDC90->unk2E % 3) == 0))) {
                            func_global_asm_80691830(0xB8, 0.14f, 0x64U, 0xFFU, 0x96, 0x03, temp_t0->unk14 * 0.01 + 1.04, 0.0f, 0.0f, 0.0f);
                            playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x25A, 0xFFU, 0x7F, 1U, 0U, 0.3f, 0U);
                            func_global_asm_80613C48(gLastSpawnedActor, 0x4F9, 0.0f, 0.0f);
                            func_global_asm_80614D00(gLastSpawnedActor, 0.5f, 0.0f);
                        }
                        if ((gCurrentActorPointer->control_state == 0x28) || (((gCurrentActorPointer->control_state == 0x2C)) && (D_global_asm_807FDC90->unk2E == 0))) {
                            gCurrentActorPointer->control_state_progress++;                    
                        } else {
                            D_global_asm_807FDC90->unk2E--;
                            break;
                        }
                        case 4:
                            if (D_global_asm_807FDC90->unk2C) {
                                D_global_asm_807FDC90->unk2C--;
                            } else if (temp_t0->unk16 != 0) {
                                gCurrentActorPointer->control_state_progress = 1;
                            } else {
                                gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
                                gCurrentActorPointer->control_state_progress = 0;
                            }
                        break;
                }
            }
            break;
        case 0x31:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0U, 0.0f, 0.0f, 0x4310U, 0.0f);
                    break;
                case 1:
                    gCurrentActorPointer->unkB8 = -40.0f;
                    gCurrentActorPointer->control_state_progress++;
        
                case 2:
                    func_global_asm_8072AB74(0U, 0.0f, 0.0f, 0x4310U, 0.0f);
                    break;
                case 3:
                    func_global_asm_8072B324(gCurrentActorPointer, D_global_asm_807FDC9C->unkC);
                    temp_t0->unk15 = 0U;
                    temp_t0->unk16 = 0U;
                    temp_t0->unk14++;
                    sp3C = D_boss_80035A50[temp_t0->unk14];
                    playActorAnimation(gCurrentActorPointer, 0x3E3);
                    gCurrentActorPointer->control_state = sp3C[temp_t0->unk15++];
                    gCurrentActorPointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x37:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    playActorAnimation(gCurrentActorPointer, 0);
                    playCutscene(gCurrentActorPointer, 2, 1);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 1:
                    if (func_global_asm_80629148() != 0) {
                        func_global_asm_805FF158(0U);
                        func_global_asm_805FF378(MAP_KROOL_FIGHT_DIDDY_PHASE, 0);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
            }
            break;
        default:
            func_boss_80027BA8(sp3C, 0x10, 0.0f);
            break;
    }
    func_global_asm_8072A450();
    if (func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28) != 0) {
        func_global_asm_8072881C(0x81, &D_global_asm_807FDC90->unk28);
    }
    renderActor(gCurrentActorPointer, 0U);
}
