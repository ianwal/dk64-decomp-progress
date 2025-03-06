#include "common.h"

void func_global_asm_80613CA8(Actor*, s16, f32, f32);

//. rodata
static const s32 D_boss_80036750[] = {
    0x00546C51,
    0x03E44100,
    0x0027280A,
    0x46281E46,
    0x5F004F28,
    0x32785000,
};

static const s32 D_boss_80036768[] = {
    0x4101292C,
    0x4F281464,
    0x50000000,
};

static const s32 D_boss_80036774[] = {
    0x4102292C,
    0x4F280A5A,
    0x50000000,
};

static const s32 D_boss_80036780[] = {
    0x4103292C,
    0x4F280A5A,
    0x50000000,
    0x00000000,
};

// .data
static void *D_boss_80035A60[4] = {
    D_boss_80036750,
    D_boss_80036768,
    D_boss_80036774,
    D_boss_80036780,
};

static u8 D_boss_80035A70[] = {0xA, 0xB, 0xC, 0xD, 0xE, 0xF};

extern u8 D_global_asm_807FBD70;

void func_boss_8002DC60(void) {
    BossActor178 *sp1C = gCurrentActorPointer->unk178;
    spawnActor(ACTOR_BOSS_KROOL_LIGHT, 0xE3);
    gLastSpawnedActor->object_properties_bitfield |= 0x400;
    gLastSpawnedActor->unk11C = gCurrentActorPointer;
    sp1C->unk0 = gLastSpawnedActor;
    moveAndScaleActorToAnother(gLastSpawnedActor, gCurrentActorPointer, gCurrentActorPointer->animation_state->scale_y);
}

void func_boss_8002DCE0(void) {
    moveAndScaleActorToAnother(gCurrentActorPointer, gCurrentActorPointer->unk11C, gCurrentActorPointer->animation_state->scale_y);
    gCurrentActorPointer->animation_state->unk48 = gCurrentActorPointer->unk11C->animation_state->unk48;
    if (gCurrentActorPointer->animation_state->unk0->unk10 == 0x675) {
        if (gCurrentActorPointer->animation_state->unk0->unk24 == 0.0f) {
            deleteActor(gCurrentActorPointer);
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_boss_8002DD7C(void) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (temp_a0->unk58 == ACTOR_BOSS_KROOL_GLOVE) {
            deleteActor(temp_a0);
        }
    }
}

u8 func_boss_80027BA8(u8 *, u16, f32);
s32 func_global_asm_8072881C(s32, s32 *);
void func_global_asm_8072A450(void);

typedef struct KRoolDiddyAAD178 {
    Actor *unk0;
    u8 pad4[0x14 - 0x4];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
} KRoolDiddyAAD178;

void func_boss_8002DE04(void) {
    KRoolDiddyAAD178 *a178;
    u8 *sp38;
    s32 var_a1;
    f32 sp30;
    u8 control_state;

    a178 = gCurrentActorPointer->unk178;
    sp38 = D_boss_80035A60[a178->unk14];
    sp30 = gPlayerPointer->unk6A & 1 ? 0.7 : 1.0;
    initializeCharacterSpawnerActor();
    func_boss_80028878(sp38);
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80626110(D_global_asm_807F5D10, 0, 0);
        gCurrentActorPointer->unk146_s16 = 5;
        gCurrentActorPointer->control_state = 0x1E;
        gCurrentActorPointer->control_state_progress = 0;
        gCurrentActorPointer->unkCC = 1;
        playActorAnimation(gCurrentActorPointer, 0x3E3);
        func_global_asm_80724CA4(2, 1);
    }
    if (gCurrentActorPointer->control_state != 0x28) {
        func_global_asm_80724E48(5);
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x1E:
            a178->unk14 = 0U;
            a178->unk15 = 0U;
            gCurrentActorPointer->control_state = sp38[a178->unk15++];
            gCurrentActorPointer->control_state_progress = 0;
            gCurrentActorPointer->unkB8 = D_global_asm_807FDC9C->unkC;
            break;
        case 0x27:
            playActorAnimation(gCurrentActorPointer, 0x3E1);
            gCurrentActorPointer->control_state = sp38[a178->unk15++];
            gCurrentActorPointer->control_state_progress = 0;
            break;
        case 0x2C:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    D_global_asm_807FDC90->unk2C = 0x14;
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 1:
                    func_global_asm_8072E1A4(0xAU, gPlayerPointer);
                    if (D_global_asm_807FDC90->unk2C) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        func_global_asm_8063DA40(((a178->unk14 * 2) + 8), 0xA);
                        func_global_asm_8063DA40(((a178->unk14 * 2) + 9), 0xA);
                        gCurrentActorPointer->control_state = sp38[a178->unk15++];
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                    break;
            }
            break;
        case 0x0:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    playActorAnimation(gCurrentActorPointer, 0x3EA);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 1:
                    func_global_asm_8072E1A4(0xAU, gPlayerPointer);
                    break;
                case 2:
                    gCurrentActorPointer->control_state = sp38[a178->unk15++];
                    gCurrentActorPointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x28:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    a178->unk18 = sp38[a178->unk15++];
                    a178->unk19 = sp38[a178->unk15++];
                    gCurrentActorPointer->control_state_progress++;
                case 1:
                    if (func_global_asm_8061CB50() == 0) {
                        D_global_asm_807FDC90->unk2C = a178->unk18;
                        playActorAnimation(gCurrentActorPointer, 0x3EF);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 3:
                    gCurrentActorPointer->unk146 = 6;
                    func_global_asm_80690814(gCurrentActorPointer, 4);
                    func_global_asm_8069084C(0xAA, 1, gCurrentActorPointer->animation_state->scale[1], 0, (f32) a178->unk19 * sp30, 0.0f, gCurrentActorPointer);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 5:
                    playActorAnimation(gCurrentActorPointer, 0x3F0);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 7:
                    gCurrentActorPointer->unk146 = 5;
                    gCurrentActorPointer->control_state_progress++;
                case 8:
                    func_global_asm_80724E48(0U);
                    if (gCurrentActorPointer->animation_state->unk1C->unk2_u16 < 0x7FFF) {
                        gCurrentActorPointer->animation_state->unk1C->unk2_u16 = -1;
                    }
                    func_global_asm_8072E1A4(0xAU, gPlayerPointer);
                    if (D_global_asm_807FDC90->unk2C) {
                        if ((gPlayerPointer->unk6A & 1) && (D_global_asm_807FDC90->unk2C >= 0xB)) {
                            D_global_asm_807FDC90->unk2C = 0xA;
                        }
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        gCurrentActorPointer->control_state = sp38[a178->unk15++];
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                    break;
            }
            break;
        case 0x29:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    gCurrentActorPointer->unk146 = 5;
                    playActorAnimation(gCurrentActorPointer, a178->unk14 ? 0x409 : 0x408);
                    func_global_asm_80614D90(gCurrentActorPointer);
                    func_global_asm_80613C48(a178->unk0, 0x675, 0.0f, 0.0f);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 2:
                    gCurrentActorPointer->control_state = sp38[a178->unk15++];
                    gCurrentActorPointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x31:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    gCurrentActorPointer->unk146 = 5;
                    playActorAnimation(gCurrentActorPointer, 0);
                    func_boss_8002DD7C();
                    playCutscene(gCurrentActorPointer, 1, 1);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 1:
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gCurrentActorPointer, 0x403);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2:
                    if (func_global_asm_80629148()) {
                        func_global_asm_8061F0B0(D_global_asm_807F5D10, 5U, 0x14U);
                        if (a178->unk14 == 3) {
                            gCurrentActorPointer->control_state = 0x37;
                            gCurrentActorPointer->control_state_progress = 0;
                        } else {
                            func_boss_8002DC60();
                            gCurrentActorPointer->unk146 = 1;
                            playActorAnimation(gCurrentActorPointer, 0x404);
                            func_global_asm_80614D90(gCurrentActorPointer);
                            func_global_asm_80613C48(a178->unk0, 0x673, 0.0f, 0.0f);
                            gCurrentActorPointer->control_state_progress++;
                        }
                    }
                    break;
                case 3:
                    if (func_global_asm_80629148()) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 4:
                    func_global_asm_8072B324(gCurrentActorPointer, D_global_asm_807FDC9C->unkC);
                    a178->unk15 = 0U;
                    a178->unk14++;
                    sp38 = D_boss_80035A60[a178->unk14];
                    playActorAnimation(gCurrentActorPointer, 0x406);
                    func_global_asm_80614D90(gCurrentActorPointer);
                    func_global_asm_80613C48(a178->unk0, 0x674, 0.0f, 0.0f);
                    gCurrentActorPointer->control_state = sp38[a178->unk15++];
                    gCurrentActorPointer->control_state_progress = 0;
                    break;
            }
            break;
        case 0x37:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    gCurrentActorPointer->y_rotation = func_global_asm_80665DE0(
                        D_global_asm_807FDCA0->unk14[4].unk0, 
                        D_global_asm_807FDCA0->unk14[4].unk4, 
                        gCurrentActorPointer->x_position, 
                        gCurrentActorPointer->z_position);
                    playActorAnimation(gCurrentActorPointer, 0);
                    playCutscene(gCurrentActorPointer, 2, 1);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 1:
                    if (func_global_asm_80629148()) {
                        func_global_asm_805FF158(0U);
                        func_global_asm_805FF378(MAP_KROOL_FIGHT_LANKY_PHASE, 0);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
            }
            break;
        default:
            func_boss_80027BA8(sp38, 0x10, 0.0f);
            break;
    }
    func_global_asm_8072A450();
    if (func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28)) {
        func_global_asm_8072881C(0x81, &D_global_asm_807FDC90->unk28);
    }
    renderActor(gCurrentActorPointer, 0U);
}
