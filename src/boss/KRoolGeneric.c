#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern void func_global_asm_8071CDE0(void* arg0, s32 arg1);

typedef struct BossStruct2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} BossStruct2;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s8 unk14;
    u8 unk15;
} Struct80027A30_arg0;

typedef struct BossStruct1 {
    u8 unk0; // Map
    u8 unk1;
    s16 unk2; // Flag
    u8 unk4;
    u8 unk5;
} BossStruct1;

typedef struct {
    u8 unk0[0x12 - 0x0];
    u16 unk12;
    u8 unk14;
    u8 unk15;
} A178_80028878;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    s16 unkE;
    s16 unk10;
} A17C_80028878;

// .data
u16 D_boss_800359A0[] = {
    0x0004,
    0x0003,
    0x0006,
    0x0014,
    0x0004,
    0x0000,
};

u16 D_boss_800359AC[] = {
    0x002D,
    0x002D,
    0x002D,
    0x002D,
    0x002D,
    0x0000,
};

u16 D_boss_800359B8[] = {
    0x0004,
    0x0003,
    0x0006,
    0x0003,
    0x0004,
    0x0000,
};

u16 D_boss_800359C4[] = {
    0x000B,
    0x000B,
    0x000B,
    0x000B,
    0x000B,
    0x0000,
};

BossStruct1 D_boss_800359D0[8] = {
    // map                        flag
    { MAP_JAPES_ARMY_DILLO,    0, 0x0068, 0x00, 0x14 },
    { MAP_FUNGI_DOGADON,       0, 0x0069, 0x00, 0x14 },
    { MAP_GALLEON_PUFFTOSS,    0, 0x006B, 0x00, 0x14 },
    { MAP_FACTORY_MAD_JACK,    0, 0x006A, 0x00, 0x14 },
    { MAP_CAVES_ARMY_DILLO,    0, 0x006D, 0x0B, 0x00 },
    { MAP_AZTEC_DOGADON,       0, 0x0067, 0x0B, 0x14 },
    { MAP_CASTLE_KING_KUT_OUT, 0, 0x006C, 0x03, 0x01 },
    { MAP_TEST_MAP,            0, 0x0000, 0x00, 0x00 }, // TODO: Padding?
};

extern SpriteData D_global_asm_8071FE08; // TODO: Sprite
extern u8 D_global_asm_80750AD4;
extern s32 D_global_asm_80767CC0;
extern s32 D_global_asm_8076D1F8;

void func_boss_80027840(u8 *arg0) {
    s16 i;
    Struct80027840 *var_v1;

    if (D_global_asm_807FDC98->unk20 != NULL) {
        free(D_global_asm_807FDC98->unk20);
    }
    D_global_asm_807FDC9C->unk11 = *arg0;
    D_global_asm_807FDC98->unk20 = malloc(*arg0 * sizeof(Struct80027840));
    var_v1 = D_global_asm_807FDC98->unk20;
    for (i = 0; i < *arg0; i++, var_v1++) {
        var_v1->unk0 = arg0[i + 1];
        var_v1->unk1 = 0;
    }
}

void func_boss_800278F4(BossStruct2 *arg0, f32 arg1, s16 arg2, s16 arg3) {
    arg0->unkC += ((arg2 - arg0->unkC) * arg1);
    arg0->unk8 += ((arg3 - arg0->unk8) * arg1);
}

void func_boss_80027950(Struct80027A30_arg0 *arg0, u8 *arg1) {
    u8 temp_s3;
    u8 temp_v1;

    temp_s3 = D_global_asm_807FDC90->unk25;
    do {
        D_global_asm_807FDC90->unk25 = arg1[arg0->unk15] + (((rand() >> 0xF) % 65536) % (((arg1[arg0->unk15 + 1] - arg1[arg0->unk15]) + 1)));
    } while (D_global_asm_807FDC90->unk25 == temp_s3);
    arg0->unk15 += 2;
}

void func_boss_80027A30(Struct80027A30_arg0 *arg0, u8 *arg1) {
    f32 dz, dy, dx;
    s32 d;
    s32 highest;
    u8 temp_a0;
    s16 i;

    highest = 0;
    for (i = arg1[arg0->unk15]; i <= arg1[arg0->unk15 + 1]; i++) {
        temp_a0 = D_global_asm_807FDC98->unk20[i].unk0;
        dz = current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[temp_a0].unk4;
        dx = current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[temp_a0].unk0;
        dy = current_actor_pointer->y_position - D_global_asm_807FDCA0->unk14[temp_a0].unk2;
        d = sqrtf(SQ(dz) + (SQ(dx) + SQ(dy)));
        if (highest < d) {
            highest = d;
            D_global_asm_807FDC90->unk25 = i;
        }
    }
    arg0->unk15 += 2;
}

// Jumptable, 2224 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KRoolGeneric/func_boss_80027BA8.s")

extern u8 D_global_asm_8076A0B1;
extern s8 D_global_asm_8076A0B3;

typedef struct BossUnkPaaD178 {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x8 - 0x6];
    s16 unk8[6]; // Unsure of array size
    u8 pad14;
    u8 unk15;
    u8 unk16;
    u8 pad17;
    u8 unk18[];
} BossUnkPaaD178;

typedef struct BossUnkPaaD17C {
    u8 unk0;
} BossUnkPaaD17C;

/*
u8 func_boss_80027BA8(u8 *arg0, u16 arg1, f32 arg2) {
    BossUnkPaaD178 *temp_s0;
    PlayerAdditionalActorData *temp_v1;
    u8 sp2F;
    u8 sp2E;
    s16 temp_a0;
    s32 cutscene;

    temp_v1 = player_pointer->PaaD;
    temp_s0 = current_actor_pointer->unk178;
    sp2E = FALSE;
    sp2F = TRUE;
    switch (current_actor_pointer->control_state) {
    case 0x54:
        sp2F = FALSE;
        if (current_actor_pointer->control_state_progress) {
            if (func_global_asm_80629148()) {
                sp2F = TRUE;
            }
        } else {
            func_global_asm_80629174();
            sp2F = FALSE;
            current_actor_pointer->control_state_progress = 1;
        }
        break;
    case 0x5F:
        playCutscene(current_actor_pointer, arg0[temp_s0->unk15++], 1);
        break;
    case 0x5E:
        if (is_cutscene_active == 1) {
            sp2F = TRUE;
            func_global_asm_8061D4E4(temp_v1->unk104);
            sp2F = TRUE;
        }
        D_global_asm_8076A0B3 = 0;
        current_actor_pointer->object_properties_bitfield &= ~4;
        D_global_asm_8076A0B1 |= 0x10;
        temp_s0->unk15++;
        temp_s0->unk4 = (arg0[temp_s0->unk15] * 0x1E);
        break;
    case 0x5D:
        temp_s0->unk15++;
        sp2F = TRUE;
        func_global_asm_8072B324(current_actor_pointer, arg0[temp_s0->unk15]);
        sp2F = TRUE;
        break;
    case 0x5C:
        ((BossUnkPaaD17C *)current_actor_pointer->unk17C)->unk0 = arg0[temp_s0->unk15++];
        break;
    case 0x5A:
        sp2F = TRUE;
        loadText(current_actor_pointer, arg0[temp_s0->unk15], arg0[temp_s0->unk15 + 1]);
        sp2F = TRUE;
        temp_s0->unk15 += 2;
        break;
    case 0x42:
block_16:
        sp2F = sp2F;
        func_global_asm_8072AB74(0x42U, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, arg1, arg2);
        if (func_global_asm_8072D13C(current_actor_pointer->control_state, 0) == 0) {
        default:
            sp2F = FALSE;
        }
        break;
    case 0x69:
        D_global_asm_807FDC90->unk1A |= 0x20;
        break;
    case 0x6D:
        break;
    case 0x58:
        current_actor_pointer->object_properties_bitfield |= 4;
        break;
    case 0x59:
        current_actor_pointer->object_properties_bitfield &= ~4;
        break;
    case 0x51:
        sp2F = TRUE;
        playActorAnimation(current_actor_pointer, arg0[temp_s0->unk15 + 1] + (arg0[temp_s0->unk15] << 8));
        sp2F = TRUE;
        temp_s0->unk15 += 2;
        break;
    case 0x55:
        sp2F = FALSE;
        if (current_actor_pointer->control_state_progress == 0) {
            temp_s0->unk8[0] = arg0[temp_s0->unk15 + 1] + (arg0[temp_s0->unk15] << 8);
            temp_s0->unk15 += 2;
            current_actor_pointer->control_state_progress = 1;
        } else {
            temp_s0->unk8[0]--;
            if (temp_s0->unk8[0] == 0) {
                sp2F = TRUE;
            }
        }
        break;
    case 0x23:
        if (current_actor_pointer->control_state_progress == 0) {
            temp_s0->unk15++;
            temp_s0->unk8[0] = arg0[temp_s0->unk15];
            current_actor_pointer->control_state_progress = 1;
            sp2F = FALSE;
            func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkD);
            sp2F = sp2F;
        } else {
            sp2F = FALSE;
            func_global_asm_8072AB74(0x23U, D_global_asm_807FDC90->unk4->x_position, D_global_asm_807FDC90->unk4->z_position, arg1, arg2);
            sp2F = FALSE;
            temp_s0->unk8[0]--;
            if ((temp_s0->unk8[0] == 0) || (temp_v1->unk1F0 & 0x80000)) {
                temp_v1->unk1F0 &= 0xFFF7FFFF;
                sp2F = TRUE;
                func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
                sp2F = TRUE;
            }
        }
        break;
    case 0x52:
        if (!(current_actor_pointer->unk6A & 1)) {
            sp2F = FALSE;
        }
        break;
    case 0x53:
        if (current_actor_pointer->control_state_progress == 0) {
            sp2F = FALSE;
        }
        break;
    case 0x4F:
        temp_s0->unk16 = temp_s0->unk15;
        break;
    case 0x50:
        temp_s0->unk15 = temp_s0->unk16;
        break;
    case 0x66:
        if (D_global_asm_807FDC90->unk1A & 8) {
            temp_s0->unk15 = temp_s0->unk16;
        }
        break;
    case 0x63:
        if (temp_s0->unk8[arg0[temp_s0->unk15]] != 0) {
            temp_s0->unk8[arg0[temp_s0->unk15]]--;
            sp2F = FALSE;
            break;
        }
        temp_s0->unk15++;
        break;
    case 0x62:
        temp_s0->unk8[arg0[temp_s0->unk15]] = arg0[temp_s0->unk15 + 1];
        temp_s0->unk15 += 2;
        sp2E = TRUE;
        break;
    case 0x64:
        temp_s0->unk18[arg0[temp_s0->unk15]] = arg0[temp_s0->unk15 + 1];
        temp_s0->unk15 += 2;
        sp2E = TRUE;
        break;
    case 0x68:
        D_global_asm_807FDC90->unk1A &= 0xFFEF;
        sp2E = TRUE;
        break;
    case 0x65:
        D_global_asm_807FDC90->unk2C = arg0[temp_s0->unk15]++;
        sp2E = TRUE;
        break;
    case 0x67:
        func_boss_80027950(temp_s0, arg0);
        sp2F = FALSE;
        current_actor_pointer->control_state = 0x42;
        current_actor_pointer->control_state_progress = 0;
        goto block_16;
    case 0x4C:
        func_boss_80027A30(temp_s0, arg0);
        sp2F = FALSE;
        current_actor_pointer->control_state = 0x42;
        current_actor_pointer->control_state_progress = 0;
        goto block_16;
    case 0x4B:
        D_global_asm_807FDC90->unk25++;
        if (arg0[temp_s0->unk15 + 1] < D_global_asm_807FDC90->unk25) {
            D_global_asm_807FDC90->unk25 = arg0[temp_s0->unk15];
        }
        temp_s0->unk15 += 2;
        sp2F = FALSE;
        current_actor_pointer->control_state = 0x42;
        current_actor_pointer->control_state_progress = 0;
        goto block_16;
    case 0x41:
        sp2F = FALSE;
        D_global_asm_807FDC90->unk25 = arg0[temp_s0->unk15++];
        current_actor_pointer->control_state = 0x42;
        current_actor_pointer->control_state_progress = 0;
        goto block_16;
    case 0x49:
    case 0x4A:
        sp2F = FALSE;
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->shadow_opacity -= 0xA;
            if (current_actor_pointer->shadow_opacity < 0) {
                current_actor_pointer->shadow_opacity = 0;
                current_actor_pointer->control_state_progress += 1;
            }
            break;
        case 1:
            if (current_actor_pointer->control_state == 0x49) {
                D_global_asm_807FDC90->unk25 = arg0[temp_s0->unk15++];
            } else {
                sp2F = FALSE;
                func_boss_80027950(temp_s0, arg0);
            }
            sp2F = FALSE;
            func_global_asm_8072D13C(0x49U, 0);
            sp2F = FALSE;
            current_actor_pointer->x_position = (f32) D_global_asm_807FDC90->unkA;
            current_actor_pointer->z_position = (f32) D_global_asm_807FDC90->unkE;
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            current_actor_pointer->shadow_opacity += 0xA;
            if (current_actor_pointer->shadow_opacity >= 0x100) {
                current_actor_pointer->shadow_opacity = 0xFF;
                sp2F = TRUE;
            }
            break;
        }
        break;
    }
    if (sp2F) {
        current_actor_pointer->control_state = arg0[temp_s0->unk15++];
        current_actor_pointer->control_state_progress = 0;
    }
    return sp2E;
}
*/

void func_boss_80028458(void) {
    func_global_asm_805FF8F8();
}

void func_boss_80028478(u16 flagIndex, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5) {
    s16 i;
    
    playSong(0x36, 1.0f);
    if (isFlagSet(flagIndex, FLAG_TYPE_PERMANENT)) {
        func_boss_80028458();
        return;
    }
    for (i = 0; i < 6; i++) {
        func_global_asm_8071498C(func_global_asm_8071CDE0);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714950((s32)D_global_asm_807FDC94);
        drawSpriteAtPosition(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3], 1.8f, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position + D_global_asm_807FDC94->unk15E, D_global_asm_807FDC94->z_position);
    }
    func_global_asm_806A5DF0(0x48, arg1, arg2, arg3, arg4, arg5, flagIndex, 0);
}

void func_boss_80028680(void) {
    func_global_asm_806A2A10(-0x7F83, 0xD2, 0xB4);
    func_global_asm_806A2B08(current_actor_pointer->unk11C);
}

Gfx *func_boss_800286B8(Gfx *dl, Actor *arg1) {
    f32 sp90[4][4];
    f32 sp50[4][4];
    Mtx *sp4C;
    char sp3C[13];

    sp4C = malloc(sizeof(Mtx));
    func_global_asm_8061134C(sp4C);
    guScaleF(sp90, 0.6f, 0.6f, 1.0f);
    guTranslateF(sp50, 100.0f, (character_change_array->unk270[3] * 4) - 0x3C, 0);
    guMtxCatF(sp90, sp50, sp90);
    guMtxF2L(sp90, sp4C);
    gSPMatrix(dl++, sp4C, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    sprintf(sp3C, "ROUND %d", D_global_asm_80750AD4);
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++ , G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    dl = func_global_asm_8070068C(dl++);
    return printStyledText(dl, 1, 0, 0, sp3C, 0);
}

void func_boss_80028818(void) {

}

void func_boss_80028820(void) {
    // K. Rool Tiny Phase Toes Complete
    setFlag(0x51, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x52, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x53, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x54, FALSE, FLAG_TYPE_TEMPORARY);
}

void func_boss_80028878(u8 *arg0) {
    A178_80028878 *a178;
    u8 sp43;
    s16 flagIndex;
    s16 var_a0_2;
    u8 var_a0;
    A17C_80028878 *a17C;

    a178 = current_actor_pointer->unk178;
    sp43 = current_map - MAP_KROOL_FIGHT_DK_PHASE;
    a17C = current_actor_pointer->unk17C;
    if (player_pointer->y_position < 30.0f) {
        player_pointer->x_position = 780.0f;
        player_pointer->y_position = 50.0f;
        player_pointer->z_position = 750.0f;
        drawSpriteAtPosition(&D_global_asm_8071FE08, 1.0f, player_pointer->x_position, player_pointer->y_position, player_pointer->z_position);
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806FB370(5, 0, 1);
        func_global_asm_806FB370(2, 0, 1);
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFF;
        if ((a178->unk14 == 0) || (current_actor_pointer->unk58 != ACTOR_BOSS_KROOL_TINY)) {
            if (!isFlagSet(0x5A, FLAG_TYPE_TEMPORARY)) {
                func_global_asm_80709464(0);
            }
            D_global_asm_80750AD4++;
            if (D_global_asm_80750AD4 >= 0xD) {
                func_global_asm_80602B60(0x2B, 0);
                func_global_asm_80709464(0);
                setFlag(0x55, FALSE, FLAG_TYPE_TEMPORARY);
                func_global_asm_80712524(MAP_KROOLS_ARENA, 0);
                D_global_asm_80750AD4 = 0;
                current_actor_pointer->control_state = 0x6A;
                current_actor_pointer->control_state_progress = 0;
            }
        }
        func_global_asm_80737638(D_global_asm_8076D1F8, 0x1E6, 0, 0x40, 1.0f, 0x80, &a17C->unk4);
        func_global_asm_80737638(D_global_asm_8076D1F8, 0x119, 0, 0x40, 1.0f, 0x80, &a17C->unk8);
    }

    if (func_global_asm_80724A20()) {
        // Hmm, some debug code commented out?
    }

    switch (current_actor_pointer->control_state) {
        case 0x37:
            if (current_actor_pointer->control_state_progress == 0) {
                func_global_asm_806A2B20(current_actor_pointer->unk11C);
            }
            break;
        case 0x6A:
            if (current_actor_pointer->control_state_progress == 0) {
                playActorAnimation(current_actor_pointer, 0);
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 0x6C:
            a178->unk12 |= 1;
            func_boss_80028680();
            if ((a178->unk14 != 0) && (current_actor_pointer->unk58 == ACTOR_BOSS_KROOL_TINY)) {
                func_global_asm_806A2B80(current_actor_pointer->unk11C);
            }
            current_actor_pointer->control_state = arg0[a178->unk15];
            a178->unk15++;
            current_actor_pointer->control_state_progress = 0;
            break;
        default:
            if ((current_actor_pointer->unk11C != NULL) && (current_actor_pointer->unk11C->control_state == 5)) {
                func_boss_80028820();
                current_actor_pointer->control_state = 0x6A;
                current_actor_pointer->control_state_progress = 0;
                playCutscene(current_actor_pointer, D_boss_800359C4[sp43], 1);
                setFlag(0x5A, TRUE, FLAG_TYPE_TEMPORARY);
            }
            break;
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (gameIsInMysteryMenuMinigameMode()) {
            setFlag(0x55, FALSE, FLAG_TYPE_TEMPORARY);
        }
        var_a0 = 0x5C;
        if (!isFlagSet(0x5D, FLAG_TYPE_TEMPORARY) || (var_a0 = sp43, (isFlagSet(0x5C, FLAG_TYPE_TEMPORARY)))) {
            func_boss_80028820();
            D_global_asm_80750AD4 = 1;
            if (!isFlagSet(0x5D, FLAG_TYPE_TEMPORARY)) {
                playCutscene(current_actor_pointer, 0x19, 1);
                setFlag(0x5D, TRUE, FLAG_TYPE_TEMPORARY);
            } else {
                playCutscene(current_actor_pointer, D_boss_800359A0[0], 1);
            }
            setFlag(0x5C, FALSE, FLAG_TYPE_TEMPORARY);
            setFlag(0x55, TRUE, FLAG_TYPE_TEMPORARY);
        } else {
            flagIndex = var_a0 + 0x55;
            if (!isFlagSet(flagIndex, FLAG_TYPE_TEMPORARY)) {
                playCutscene(current_actor_pointer, D_boss_800359A0[sp43], 1);
                setFlag(flagIndex, TRUE, FLAG_TYPE_TEMPORARY);
            } else if (isFlagSet(0x5A, FLAG_TYPE_TEMPORARY)) {
                if (isFlagSet(0x5B, FLAG_TYPE_TEMPORARY)) {
                    playCutscene(current_actor_pointer, D_boss_800359AC[sp43], 1);
                    setFlag(0x5A, FALSE, FLAG_TYPE_TEMPORARY);
                } else {
                    func_global_asm_80602B60(0x2B, 0);
                    current_actor_pointer->control_state = 0x6A;
                    current_actor_pointer->control_state_progress = 0;
                    setFlag(0x5B, TRUE, FLAG_TYPE_TEMPORARY);
                    func_global_asm_80712524(MAP_KROOLS_ARENA, 1);
                    D_global_asm_80750AD4 -= 1;
                }
            } else {
                playCutscene(current_actor_pointer, D_boss_800359B8[sp43], 1);
            }
        }
    }
    if ((current_player->control_state == 0x67) || (func_global_asm_80602D4C(0xF) > 0.1)) {
        a17C->unkE = 7500;
        a17C->unk10 = MAX(7500, a17C->unk10 - 1000);
    } else {
        a17C->unkE = MAX(8000, a17C->unkE - 100);
        a17C->unk10 = MIN(a17C->unkE, a17C->unk10 + 1000);
    }
    func_global_asm_80737AC4(a17C->unk4, 8, a17C->unk10);
    func_global_asm_80737AC4(a17C->unk8, 8, a17C->unk10);
    if (a17C->unkD & 0x17) {
        if ((D_global_asm_80767CC0 - a17C->unk0) >= 6U) {
            var_a0_2 = 0x1E8;
            a17C->unk0 = D_global_asm_80767CC0;
            a17C->unkC = 0;
            if (a17C->unkD & 0x10) {
                var_a0_2 = 0x42B;
            } else if (a17C->unkD & 4) {
                var_a0_2 = 0x1EA;
            } else if (a17C->unkD & 2) {
                var_a0_2 = 0x1E7;
            }
            playSound(var_a0_2, 0x58EF, 64.0f, 1.0f, 0x14, 0x80);
        }
        a17C->unkE = MIN(0x7FFF, a17C->unkE + 18000);
        a17C->unkD &= 0xFFE0;
    }
    if (a17C->unkD & 8) {
        if ((D_global_asm_80767CC0 - a17C->unk0) >= 6U) {
            if (a17C->unkC == 0) {
                a17C->unk0 = D_global_asm_80767CC0;
            }
            a17C->unkC++;
            switch (a17C->unkC) {
                case 0x3E:
                    a17C->unkC = 0;
                    a17C->unkD &= 0xFFF7;
                    // fallthrough
                case 0x1:
                case 0x10:
                case 0x1D:
                case 0x29:
                case 0x34:
                    playSound(0x1E9, 0x58EF, 64.0f, 1.0f, 0, 0x80);
                    break;
            }
        }
        a17C->unkE = MIN(0x7FFF, a17C->unkE + 18000);
    }
    if ((a178->unk12 & 1) && (func_global_asm_805FCA64())) {
        addActorToTextOverlayRenderArray(func_boss_800286B8, current_actor_pointer, 3);
    }
}

void func_boss_800290D4(u8 arg0) {
    if (arg0) {
        func_global_asm_8066EA64(current_actor_pointer, 2);
        func_global_asm_8066EA64(current_actor_pointer, 3);
    } else {
        func_global_asm_8066EA90(current_actor_pointer, 2);
        func_global_asm_8066EA90(current_actor_pointer, 3);
    }
}

void func_boss_80029140(s16* arg0) {
    s16 i = 0;
    while (D_boss_800359D0[i].unk0 != 0 && D_boss_800359D0[i].unk0 != current_map) {
        i++;
    }
    if (D_boss_800359D0[i].unk0 != 0 && D_boss_800359D0[i].unk4 == *arg0) {
        if (isFlagSet(D_boss_800359D0[i].unk2, FLAG_TYPE_TEMPORARY)) {
            *arg0 = D_boss_800359D0[i].unk5;
        }
    }
}

void func_boss_8002920C(void) {
    s16 i = 0;
    while (D_boss_800359D0[i].unk0 != 0 && D_boss_800359D0[i].unk0 != current_map) {
        i++;
    }
    if (D_boss_800359D0[i].unk0 != 0) {
        setFlag(D_boss_800359D0[i].unk2, TRUE, FLAG_TYPE_TEMPORARY);
    }
}
