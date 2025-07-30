#include "common.h"

// TODO: Is there a file split somewhere in here? Rodata messes up around D_bonus_8002DDD4
// .rodata
extern const f32 D_bonus_8002DD20; // = 3.2f;
extern const f32 D_bonus_8002DD28; // = 385.0f;
extern const f32 D_bonus_8002DDEC; // = 0.8f;

// .data
static s16 D_bonus_8002D8C0[] = {
    0x01B3,
    0x01B4,
    0x01B5,
    0x0000,
};

static s16 D_bonus_8002D8C8[] = {
    0x0004,
    0x0001,
    0x0006,
    0x0009,
    0x000C,
    0x00D5,
};

static s16 D_bonus_8002D8D4[] = {
    0x0336,
    0x0339,
    0x0342,
    0x033F,
    0x033C,
    0xFFFF,
};

static s16 D_bonus_8002D8E0[] = {
    0x0338,
    0x033B,
    0x0344,
    0x0341,
    0x033E,
    0xFFFF,
};

static s16 D_bonus_8002D8EC[] = {
    0x022C,
    0x029B,
    0x00B9,
    0x00C2,
};

static s8 D_bonus_8002D8F4 = 0x32;

static s16 D_bonus_8002D8F8 = 0;

static s16 D_bonus_8002D8FC = 0;

static s16 D_bonus_8002D900[] = {0, 0};

static s8 D_bonus_8002D904 = 0;

static s32 D_bonus_8002D908 = 0; // Padding, unused

static f32 D_bonus_8002D90C = 0.0f;

typedef struct {
    u8 unk0[0x1E - 0];
    s16 unk1E;
    s16 unk20;
} AAD_80026690;

Gfx *func_bonus_80026690(Gfx *dl, Actor *arg1) {
    f32 temp_f20;
    s16 sp6A;
    s16 sp68;
    AAD_80026690 *aaD;

    aaD = arg1->additional_actor_data;
    sp6A = aaD->unk1E;
    sp68 = aaD->unk20;
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(dl++, &D_1000118);
    temp_f20 = D_bonus_8002DD20;
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    dl =   displayImage(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A - 0x34), (s16)(sp68 - 0x34), temp_f20, temp_f20, 0xE1, 0.0f);
    dl =   displayImage(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A + 0x34), (s16)(sp68 - 0x34), temp_f20, temp_f20, 0x13B, 0.0f);
    dl =   displayImage(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A + 0x34), (s16)(sp68 + 0x34), temp_f20, temp_f20, 0x2D, 0.0f);
    return displayImage(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A - 0x34), (s16)(sp68 + 0x34), temp_f20, temp_f20, 0x87, 0.0f);
}

Gfx *func_global_asm_8068DC54(Gfx *, s32, s32, void *, s32, void *);
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;

typedef struct KremlingKoshAAD {
    void* sprite[5];
    u8 unk14[0x1E - 0x14];
    s16 x;
    s16 y;
    u8 unk22;
    u8 timer;
    u8 unk24;
    u8 unk25;
    u8 unk26;
} KremlingKoshAAD;

typedef struct KremlingKoshInit {
    Actor* slots[8];
    s16 hit_requirement;
    s16 hit_requirement_hud;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 no_spawn_percent;
    u8 green_chance;
    u8 time_limit;
    u8 unk2A[2];
    f32 unk2C;
} KremlingKoshInit;

Gfx *func_bonus_80026940(Gfx *dl, Actor *KoshController) {
    s32 pad7C;
    KremlingKoshInit *init;
    s32 pad74;
    s32 pad70;
    s32 pad68;
    s32 pad68_0;
    u8 *text_str;
    s32 pad[0x6];
    s32 x;
    KremlingKoshAAD *aad;
    s8 *sp64;
    s32 style_height_0;
    s32 style_height_1;
    s32 x_0;
    s32 pad30;
    s32 pad2C;
    

    aad = KoshController->additional_actor_data;
    init = KoshController->unk178;
    if ((KoshController->control_state == 0) && (aad->unk26 != 0)) {
        dl = func_bonus_80026690(dl, KoshController);
    }
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xC8, 0xC8, 0xC8, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetRenderMode(dl++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    if (KoshController->control_state != 1) {
        dl = func_global_asm_806FE078(dl, init->unk25, 8, 30.0f, 36.0f, 0.0f, 1.5f);
        dl = func_global_asm_8068DC54(
            dl,
            0x26,
            0x32,
            &init->hit_requirement,
            init->hit_requirement_hud,
            &init->unk24);
    }
    if (aad->unk25 != 0) {
        x = D_global_asm_80744490 >> 1;
        text_str = getTextString(0x1AU, 6, 1);
        gDPPipeSync(dl++);
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, aad->unk25);
        gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        x -= (getCenterOfString(1, text_str) >> 1);
        style_height_0 = func_global_asm_806FD894(1);
        dl = printStyledText(
            dl, 1,
            x * 4,
            ((D_global_asm_80744494 - style_height_0) * 2),
            text_str,
            1U);
        aad->unk25 -= MIN(aad->unk25, 8);
    }
    if (aad->unk24 != 0) {
        x_0 = D_global_asm_80744490 >> 1;
        text_str = getTextString(0x1AU, 8, 1);
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, aad->unk24);
        gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        x_0 -= getCenterOfString(1, text_str) >> 1;
        dl = printStyledText(
            dl,
            1,
            x_0 * 4,
            ((func_global_asm_806FD894(1) + D_global_asm_80744494) * 2),
            text_str,
            1U);
        aad->unk24 -= MIN(aad->unk24, 8);
    }
    return dl;
}

u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);
extern f32 D_bonus_8002DD24;

typedef struct TTTAAD_0 {
    u8 pad0[0x24];
    u8 unk24;
    u8 unk25;
    u8 unk26;
} TTTAAD_0;

typedef struct TTTAAD_1 {
    Actor *unk0[6];
} TTTAAD_1;

typedef struct TempAAD1 {
    u8 unk0[4];
    Actor *unk4;
} TempAAD1;

typedef struct TempAAD2 {
    u8 unk0[5];
    u8 unk5;
    u8 pad6[2];
    s16 unk8;
} TempAAD2;

Gfx *func_bonus_80026CF0(Gfx *dl, Actor *arg1) {
    TTTAAD_0 *aad0;
    TTTAAD_1 *aad1; // 50
    s32 temp_s1;
    s32 i;
    s32 var_s5;
    s8 *temp_v0;
    s16 temp_a0;
    u8 temp_v1;
    Actor *temp_s1_5;
    Actor *tempactor;
    TempAAD2 *temp_s2_2;
    TempAAD1 *temp;
    u8 *str;
    u8 temp1;

    var_s5 = FALSE;
    aad0 = arg1->AAD_as_array[0];
    aad1 = arg1->AAD_as_array[1];
    if ((arg1->control_state == 0) && (aad0->unk26 != 0)) {
        dl = func_bonus_80026690(dl, arg1);
    }
    if (aad0->unk25) {
        temp_s1 = D_global_asm_80744490 >> 1;
        temp_v0 = getTextString(0x1AU, 6, 1);
        gDPPipeSync(dl++);
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, aad0->unk25);
        gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        temp_s1 -= (getCenterOfString(1, temp_v0) >> 1);
        temp1 = func_global_asm_806FD894(1);
        dl = printStyledText(dl, 1,
            temp_s1 * 4,
            (D_global_asm_80744494 - temp1) * 2,
            temp_v0, 1U);
        aad0->unk25 = aad0->unk25 - MIN(aad0->unk25, 8);
    }
    if (aad0->unk24) {
        temp_s1 = D_global_asm_80744490 >> 1;
        temp_v0 = getTextString(0x1AU, 7, 1);
        gDPPipeSync(dl++);
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, aad0->unk24);
        gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        temp_s1 -= (getCenterOfString(1, temp_v0) >> 1);
        temp1 = func_global_asm_806FD894(1);
        dl = printStyledText(dl, 1, 
            temp_s1 * 4,
            (temp1 + D_global_asm_80744494) * 2,
            temp_v0, 1U);
        aad0->unk24 = aad0->unk24 - MIN(aad0->unk24, 8);
    }
    for (i = 0; i < 6; i++) {
        tempactor = aad1->unk0[i];
        temp = tempactor->AAD_as_array[0];
        temp_s1_5 = temp->unk4;
        temp_s2_2 = temp_s1_5->AAD_as_array[0];
        if ((temp_s2_2->unk5 != 0) && (arg1->control_state == 0)) {
            if (temp_s2_2->unk8 < 0) {
                str = getTextString(0x1AU, 9, 1);
                temp_s2_2->unk8 = func_global_asm_806FDB8C(1, str, 9,
                    temp_s1_5->x_position * 0.25,
                    temp_s1_5->y_position * 0.25,
                    temp_s1_5->z_position * 0.25);
            }
            if (!var_s5) {
                gSPDisplayList(dl++, &D_1000118);
                gDPPipeSync(dl++);
                gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                gDPSetRenderMode(dl++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                gSPSetGeometryMode(dl++, G_SHADE | G_SHADING_SMOOTH);
                gDPSetCycleType(dl++, G_CYC_1CYCLE);
                gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                var_s5 = TRUE;
            }
            dl = func_global_asm_806FE078(dl, 
                temp_s2_2->unk8,
                9,
                temp_s1_5->x_position,
                temp_s1_5->y_position + 20.0f,
                temp_s1_5->z_position,
                D_bonus_8002DD24);
        } else {
            if (temp_s2_2->unk8 >= 0) {
                func_global_asm_806FDAEC(temp_s2_2->unk8);
                temp_s2_2->unk8 = -1;
            }
        }
    }
    return dl;
}

typedef struct {
    Actor* unk0[4]; // Used, might be bigger
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u8 unk28; // Used
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    f32 unk2C; // Used
} Struct800271B4;
typedef struct {
    Struct800271B4* unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} AAD_bonus_800271B4;

void func_bonus_800271B4(s16 arg0, s16 arg1, s16 arg2, u8 arg3, Struct800271B4 *arg4) {
    u8 var_a3;
    AAD_bonus_800271B4 *temp_v1;

    var_a3 = arg4->unk28 < RandClamp(100) ? 1 : 0;
    if (spawnActor(ACTOR_MINIGAME_KREMLING, var_a3 ? 0x32 : 0x33)) {
        temp_v1 = gLastSpawnedActor->additional_actor_data;
        playActorAnimation(gLastSpawnedActor, var_a3 ? 0x211 : 0x20F);
        func_global_asm_80614D00(gLastSpawnedActor, arg4->unk2C, 0);
        gLastSpawnedActor->x_position = arg0;
        gLastSpawnedActor->y_position = arg1 - 0x19;
        gLastSpawnedActor->z_position = arg2;
        gLastSpawnedActor->y_rotation = 0xC00;
        temp_v1->unk9 = arg3;
        temp_v1->unk8 = var_a3;
        temp_v1->unk0 = arg4;
        arg4->unk0[arg3] = gLastSpawnedActor;
    }
}

typedef struct bonus_struct_0 {
    u8 pad0[0x9];
    u8 unk9;
} BonusStruct0;

typedef struct {
    s32 unk0[8]; //is this array 8 in size?
    u16 unk20;
    s16 unk22; // Used
    u8 unk24;
    u8 unk25; // Used
    u16 unk26;
} AAD_bonus_800284C0_unk0;

typedef struct {
    AAD_bonus_800284C0_unk0 *unk0; // Used
    u32 unk4;
    u8 unk8; // Used
    u8 unk9;
} AAD_bonus_800284C0;

void func_bonus_80027308(AAD_bonus_800284C0 *arg0, AAD_bonus_800284C0_unk0 *arg1) {
    arg1->unk0[arg0->unk9] = 0;
    deleteActor(gCurrentActorPointer);
}

typedef struct {
    s32 unk0;
    void *unk4[1];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s8 unk18[1];
} Struct8002733C;

void func_bonus_8002733C(Struct8002733C *arg0) {
    s16 i;
    s16 x;

    x = 280;
    for (i = 0; i < 5; i++) {
        if (arg0->unk4[i] != NULL) {
            func_global_asm_80715908(arg0->unk4[i]);
        }
        arg0->unk18[i] = 0;
        func_global_asm_8071495C();
        func_global_asm_807149FC(-1);
        func_global_asm_80714998(2);
        func_global_asm_80714944(i * 3);
        func_global_asm_8071498C(func_global_asm_8071A038);
        func_global_asm_80714950(&arg0->unk18[i]);
        arg0->unk4[i] = drawSpriteAtPosition(&D_global_asm_8071FFD4, 1.0f, x, 210.0f, -10.0f);
        x -= 30;
    }
    playSound(0x3E4, 0x7FFF, 63.0f, 1.0f, 5, 0);
}

void func_bonus_800274A0(f32 arg0, f32 arg1, f32 arg2) {
    playSound(0x59, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
    func_global_asm_806907F0(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position - 10.0f, gCurrentActorPointer->z_position);
    func_global_asm_80690A28(0x23, 1, 0.6f, arg0, arg1, arg2, D_bonus_8002DD28, gCurrentActorPointer);
}

extern f64 D_bonus_8002DD30;
extern f64 D_bonus_8002DD38;
extern Struct807FD610 D_global_asm_807FD610[];

typedef struct {
    s32 unk0;
    s32 unk4[1];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18[1]; // Used
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s16 unk1C;
    s16 unk1E; // Used
    s16 unk20; // Used
    u8 unk22; // Used
    u8 unk23; // Used
    s16 unk24;
    s8 unk26; // Used
    s8 unk27;
    s32 unk28;
    s32 unk2C;
} AAD_bonus_80027548;

u8 func_bonus_80027548(f32 arg0, f32 arg1, f32 arg2) {
    AAD_bonus_80027548 *aaD;
    f32 sp4C[3];
    f32 d;
    s16 i;
    u8 unk;
    u8 sp40;

    aaD = gCurrentActorPointer->additional_actor_data;
    sp40 = 0;
    aaD->unk26 = 1;
    func_global_asm_80626F8C(arg0, arg1, arg2, &sp4C[2], &sp4C[1], 0, 4.0f, 0);
    aaD->unk1E = sp4C[2];
    aaD->unk20 = sp4C[1];
    gCurrentActorPointer->y_rotation = func_global_asm_806CC190(gCurrentActorPointer->y_rotation, func_global_asm_80665DE0(arg0, arg2, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position), 10.0f);
    d = sqrtf(SQ(gCurrentActorPointer->x_position - arg0) + SQ(gCurrentActorPointer->z_position - arg2));
    gCurrentActorPointer->z_rotation = func_global_asm_806CC190(gCurrentActorPointer->z_rotation, ((func_global_asm_80611BB4(gCurrentActorPointer->y_position - arg1, d) * 2048.0) / D_bonus_8002DD30) + D_bonus_8002DD38, 5.0f);
    if ((D_global_asm_807FD610[0].unk2C & 0xE000) && (gCurrentActorPointer->control_state == 0)) {
        sp40 = 1;
        if (aaD->unk22) {
            if ((aaD->unk23) && (!aaD->unk18[0])) {
                s16 i;
                func_bonus_800274A0(arg0, arg1, arg2);
                aaD->unk23--;
                func_global_asm_80715908(aaD->unk4[aaD->unk23]);
                func_global_asm_8060E7EC(0, 0xFF, 3);
                aaD->unk4[aaD->unk23] = 0;
                for (i = 0; i < aaD->unk23; i++) {
                    aaD->unk18[i] = 0xA;
                }
            } else if ((!aaD->unk23) && (gCurrentActorPointer->control_state_progress == 0)) {
                sp40 = 2;
                gCurrentActorPointer->control_state_progress = 1;
            }
        } else if (aaD->unk23 < 5) {
            aaD->unk23 = 5;
            func_bonus_8002733C(aaD);
            gCurrentActorPointer->control_state_progress = 0;
        }
    }
    return sp40;
}

// close, doable
// https://decomp.me/scratch/Rfh5H
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_800277F8.s")

extern f32 D_bonus_8002DD40;
extern f32 D_bonus_8002DD44;
extern f32 D_bonus_8002DD48;
extern f32 D_bonus_8002DD4C;
extern f32 D_bonus_8002DD50;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
} AAD_bonus_800277F8;

typedef struct {
    s32 unk0[4]; // TODO: Might be bigger
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    f32 unk2C;
} A178_800277F8;

void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2);

/*
void func_bonus_800277F8(void) {
    AAD_bonus_800277F8 *aaD;
    A178_800277F8 *a178;
    f32 temp_f2;
    f32 var_f12;
    u8 temp_t2;
    Struct807F5FD4_unk0 *temp_v0;

    aaD = gCurrentActorPointer->additional_actor_data;
    a178 = ((A178_800277F8*)gCurrentActorPointer->unk178);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        a178->unk25 = func_global_asm_806FDB8C(1, getTextString(0x1A, 2, 1), 8, 0.0f, 0.0f, 0.0f);
        func_global_asm_806FDAB8(a178->unk25, 0.0f);
        aaD->unk23 = 5;
        aaD->unk0 = -2;
        aaD->unk22 = 0;
        setAction(0x48, NULL, 0);
        func_global_asm_8061C464(extra_player_info_pointer->unk104, gCurrentActorPointer, 4, 0x800, -7, 0, 0x16, 0x2C, 4, 0, D_bonus_8002DD40);
        playCutscene(NULL, 0, 1);
        gCurrentActorPointer->z_rotation = 0x310;
        switch (current_map) {
            case MAP_KREMLING_KOSH_VERY_EASY:
                a178->unk27 = 0x55;
                a178->unk28 = 0x46;
                a178->unk2C = D_bonus_8002DD44;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x12;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_EASY:
                a178->unk27 = 0x5A;
                a178->unk28 = 0x46;
                a178->unk29 = 0x3C;
                a178->unk2C = 1.0f;
                a178->unk20 = 0x16;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_NORMAL:
                a178->unk27 = 0x57;
                a178->unk28 = 0x50;
                a178->unk2C = D_bonus_8002DD48;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x19;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_HARD:
                a178->unk27 = 0x5C;
                a178->unk28 = 0x50;
                a178->unk2C = D_bonus_8002DD4C;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x1C;
                a178->unk22 = a178->unk20;
                break;
        }
    }
    if (aaD->unk0 > 0) {
        aaD->unk22 = 0;
        if ((gCurrentActorPointer->control_state == 0) && ((D_global_asm_807FD610->unk30 >= 0x1F) || (D_global_asm_807FD610->unk31 >= 0x1F))) {
            temp_f2 = ((func_global_asm_80611BB4(D_global_asm_807FD610->unk2F, D_global_asm_807FD610->unk2E) / D_bonus_8002DD50) * 8.0) + 5.5;
            var_f12 = temp_f2;
            if (temp_f2 > 9.0f) {
                var_f12 = temp_f2 - 8.0f;
            }
            aaD->unk22 = var_f12;
        }
        if (func_bonus_80027548(D_global_asm_807F5FD4->unk0[0][aaD->unk22].unk0, D_global_asm_807F5FD4->unk0[0][aaD->unk22].unk4, D_global_asm_807F5FD4->unk0[0][aaD->unk22].unk8) == 2) {
            aaD->unk25 = 0xFF;
            playSound(0x3BC, 0x7FFF, 63.0f, 1.0f, 0, 0);
        }
        switch (gCurrentActorPointer->control_state) {
            case 0x0:
                if (gCurrentActorPointer->unk11C->control_state == 5) {
                    gCurrentActorPointer->control_state = 0xFF;
                }
                if (a178->unk22 == 0) {
                    func_bonus_800264E0(0, 0);
                    playCutscene(NULL, 1, 0x11);
                    gCurrentActorPointer->control_state = 1;
                } else {
                    if (a178->unk27 < RandClamp(100)) {
                        temp_t2 = RandClamp(255) % 8;
                        if (a178->unk0[temp_t2] == 0) {
                            temp_v0 = &D_global_asm_807F5FD4->unk0[0][temp_t2 + 1];
                            func_bonus_800271B4(temp_v0->unk0, temp_v0->unk4, temp_v0->unk8, temp_t2, a178);
                        }
                    }
                }
                if ((gCurrentActorPointer->unk11C->control_state == 4) && (gCurrentActorPointer->unk11C->control_state_progress != 0xFF)) {
                    gCurrentActorPointer->control_state = 0xFE;
                }
                break;
            case 0xFE:
                aaD->unk24 = 0xFF;
                playSound(0x142, 0x7FFF, 63.0f, 1.0f, 0, 0);
                gCurrentActorPointer->control_state = 0;
                break;
            case 0xFF:
                func_bonus_800265C0(0, 5);
                playCutscene(NULL, 1, 0x11);
                gCurrentActorPointer->control_state = 1;
                break;
        }
    } else if (aaD->unk0 != -2 && aaD->unk0 != -1) {
        if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
            aaD->unk0 = 1;
            func_global_asm_806A2B08(gCurrentActorPointer->unk11C);
            func_bonus_8002733C(aaD);
            playSong(MUSIC_8_BONUS_MINIGAMES, 1.0f);
        }
    } else if (is_cutscene_active != 1) {
        aaD->unk0++;
        func_global_asm_806A2A10(0xDC, 0x2A, a178->unk29);
        loadText(gCurrentActorPointer, 0, 1);
    }
    if (aaD->unk0 >= -1) {
        addActorToTextOverlayRenderArray(func_bonus_80026940, gCurrentActorPointer, 3);
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

// TODO: Similar to above but for TTT
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80027F14.s")

extern u8 D_global_asm_807FBB85;

void func_global_asm_8072881C(s32, void*);

void func_bonus_800284C0(void) {
    AAD_bonus_800284C0 *temp_a2;
    AAD_bonus_800284C0_unk0 *temp_a3;
    s32 var_a1;

    temp_a2 = gCurrentActorPointer->additional_actor_data;
    temp_a3 = temp_a2->unk0;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->noclip_byte = 0x24;
    }
    func_global_asm_8072881C(0, &temp_a2->unk4);
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (D_global_asm_807FBB85 != 0) {
                temp_a3->unk22 = MAX(0, temp_a3->unk22 - (temp_a2->unk8 ? 2 : 1));
                func_global_asm_806FDAB8(temp_a3->unk25, M_PIF);
                playActorAnimation(gCurrentActorPointer, (temp_a2->unk8 ? 0x212 : 0x210));
                gCurrentActorPointer->control_state = 1;
                gCurrentActorPointer->control_state_progress = 0;
                break;
            }
            if (gCurrentActorPointer->control_state_progress != 0) {
                func_bonus_80027308(temp_a2, temp_a3);
            }
            break;
        case 1:
            if (gCurrentActorPointer->control_state_progress != 0) {
                func_bonus_80027308(temp_a2, temp_a3);
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

typedef struct {
    Actor *unk0[6]; // Used
    s16 unk18;
    u8 unk1A;
    u8 unk1B; // Used
    u8 unk1C; // Used
} ARG0_80028648;

typedef struct {
    Actor* unk0; // Used
    Actor* unk4;
    f32 unk8;
    f32 unkC;
    s8 unk10;
    u8 unk11; // Used
    u8 pad12[2];
    f32 unk14;
    f32 unk18;
    u8 unk1C;
} snakeAAD;

typedef struct {
    Actor* unk0; // Used
    s16 unk4;
    s8 unk6; // Used
    s8 unk7;
    s16 unk8; // Used
} turtleAAD;

void func_bonus_80028648(ARG0_80028648 *arg0) {
    s32 i;
    snakeAAD *snakeAAD;
    turtleAAD *turtleAAD;
    Struct807F5FD4_unk0 *temp;
    Actor *temp2;

    for (i = 1; i < 7; i++) {
        if (spawnActor(ACTOR_SNAKE, 0x15)) {
            snakeAAD = gLastSpawnedActor->additional_actor_data;
            snakeAAD->unk0 = gCurrentActorPointer;
            snakeAAD->unk11 = (RandClamp(32767) % ((arg0->unk1C - arg0->unk1B) + 1)) + arg0->unk1B;
            temp = &D_global_asm_807F5FD4->unk0[0][i];
            playActorAnimation(gLastSpawnedActor, 0x1F5);
            gLastSpawnedActor->x_position = temp->unk0;
            gLastSpawnedActor->y_position = temp->unk4;
            gLastSpawnedActor->z_position = temp->unk8;
            gLastSpawnedActor->object_properties_bitfield |= 0x1000;
            gLastSpawnedActor->y_rotation = 0x800;
            arg0->unk0[i - 1] = gLastSpawnedActor;
            temp2 = gLastSpawnedActor;
            if (spawnActor(ACTOR_TURTLE, 0x16)) {
                turtleAAD = gLastSpawnedActor->additional_actor_data;
                turtleAAD->unk0 = temp2;
                turtleAAD->unk6 = i - 1;
                snakeAAD->unk4 = gLastSpawnedActor;
                turtleAAD->unk8 = -1;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002881C.s")

extern f32 D_bonus_8002DD5C;
extern f32 D_bonus_8002DD60;
extern f64 D_bonus_8002DD68;
extern f32 D_bonus_8002DD70;
extern f32 D_bonus_8002DD74;
extern f32 D_bonus_8002DD78;
extern f32 D_bonus_8002DD7C;
extern f32 D_bonus_8002DD80;
extern f64 D_bonus_8002DD88;
extern f64 D_bonus_8002DD90;
extern u8 D_global_asm_807FBD70;

typedef struct TempAAD3 {
    Actor *unk0;
    u8 unk4;
    u8 unk5;
} TempAAD3;

typedef struct TempAAD4 {
    u8 unk0[0x20];
    f32 unk20;
} TempAAD4;

/*
void func_bonus_8002881C(void) {
    s16 *sp50;
    TempAAD4 *sp4C;
    s32 sp40;
    AnimationStateUnk1C *sp3C;
    f32 sp38;
    f32 sp28;
    AnimationStateUnk1C *temp_v0_5;
    f32 temp_f16;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f16;
    f32 var_f2;
    s32 var_v1;
    TempAAD3 *temp_v1;
    snakeAAD *snakeAAD;

    snakeAAD = gCurrentActorPointer->AAD_as_array[0];
    sp50 = snakeAAD->unk0->AAD_as_array[0];
    sp4C = snakeAAD->unk0->AAD_as_array[1];
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->noclip_byte = 0x24;
        snakeAAD->unkC = D_bonus_8002DD5C;
        snakeAAD->unk8 = D_bonus_8002DD5C;
        snakeAAD->unk10 = snakeAAD->unk11;
        gCurrentActorPointer->animation_state->unk1C = malloc(7 * sizeof(AnimationStateUnk1C));
        func_global_asm_80611690(gCurrentActorPointer->animation_state->unk1C);
    }
    temp_v1 = snakeAAD->unk4->AAD_as_array[0];
    if ((D_global_asm_807FBD70 == 4) && (temp_v1->unk4 == 0) && (snakeAAD->unk10 == -1)) {
        snakeAAD->unk8 = D_bonus_8002DD60;
        snakeAAD->unk10 = snakeAAD->unk11;
        temp_v1->unk5 = 0;
    }
    if (*sp50 > 0) {
        if (snakeAAD->unk0->control_state == 0) {
            if (temp_v1->unk4 == 0) {
                if (snakeAAD->unk10 >= 0) {
                    snakeAAD->unk10--;
                }
                if (snakeAAD->unk10 < 0) {
                    snakeAAD->unk8 -= sp4C->unk20;
                }
            } else {
                snakeAAD->unk8 += 40.0f;
                snakeAAD->unk0->control_state = 2U;
            }
        }
    }
    snakeAAD->unkC += ((snakeAAD->unk8 - snakeAAD->unkC) * D_bonus_8002DD68);
    if (temp_v1->unk4 != 0) {
        if (snakeAAD->unk14 < 1.0f) {
            snakeAAD->unk14 += D_bonus_8002DD70;
        } else if (snakeAAD->unk14 > 1.0f) {
            snakeAAD->unk14 = 1.0f;
        }
    } else {
        if (snakeAAD->unk1C != 0) {
            snakeAAD->unk1C--;
            if (!(snakeAAD->unk1C)) {
                playActorAnimation(gCurrentActorPointer, 0x1F6);
            }
        }
    }
    if (gCurrentActorPointer->animation_state->unk1C) {
        sp40 = 0;
        temp_v0_5 = gCurrentActorPointer->animation_state->unk1C;
        sp38 = 1.0f - ((snakeAAD->unkC - 40.0f) / 235.0f);
        temp_f2 = func_global_asm_80612794(snakeAAD->unk4->x_rotation);
        temp_f16 = (D_bonus_8002DD74 * sp38) + 150.0f;
        temp_f2 *= temp_f16;
        var_f12 = func_global_asm_80612790(snakeAAD->unk4->x_rotation) * temp_f16;
        var_f2 = temp_f2;
        sp28 = (snakeAAD->unk14 * 128.0f) + -128.0f;
        if (var_f2 < 0.0f) {
            var_f2 += D_bonus_8002DD78;
        }
        if (var_f12 < 0.0f) {
            var_f12 += D_bonus_8002DD7C;
        }
        for (var_v1 = 4; var_v1 < 7; var_v1++) {
            temp_v0_5[sp40].unk1 = var_v1;
            temp_v0_5[sp40].unk0 = sp28;
            temp_v0_5[sp40].unk2_u16 = var_f2;
            temp_v0_5[sp40].unk4 = 0;
            temp_v0_5[sp40].unk6_u16 = var_f12;
            if (D_bonus_8002DD80 < var_f2) {
                var_f2 += ((D_bonus_8002DD7C - var_f2) * 0.5);
            } else {
                var_f2 *= 0.5;
            }
            if (D_bonus_8002DD80 < var_f12) {
                var_f12 += ((D_bonus_8002DD7C - var_f12) * 0.5);
            } else {
                var_f12 *= 0.5;
            }
            sp40++;
        }
        switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            snakeAAD->unk18 += ((sp38 - snakeAAD->unk18) * D_bonus_8002DD88);
            break;
        case 1:
        case 2:
            snakeAAD->unk18 += ((0.0 - snakeAAD->unk18) * D_bonus_8002DD90);
            break;
        }
        temp_v0_5[sp40].unk1 = 0xE;
        temp_v0_5[sp40].unk2 = 0x61A8;
        temp_v0_5[sp40].unk4 = 0;
        temp_v0_5[sp40].unk6 = 0;
        var_f16 = snakeAAD->unk18 * -128.0f;
        temp_v0_5[sp40].unk0 = var_f16;
        sp40++;
        for (var_v1 = 0xC; var_v1 < 0xD; var_v1++) {
            temp_v0_5[sp40].unk1 = var_v1;
            temp_v0_5[sp40].unk2 = -0x2710;
            temp_v0_5[sp40].unk4 = 0;
            temp_v0_5[sp40].unk6 = 0;
            temp_v0_5[sp40].unk0 = var_f16;
            sp40 += 2;
            var_f16 = snakeAAD->unk18 * -128.0f;
        }
        temp_v0_5[sp40 - 2].unk1 = var_v1;
        temp_v0_5[sp40 - 2].unk2 = -0x2710;
        temp_v0_5[sp40 - 2].unk4 = 0;
        temp_v0_5[sp40 - 2].unk6 = 0;
        temp_v0_5[sp40 - 2].unk0 = var_f16;
        temp_v0_5[sp40].unk0 = 0;
    }
    renderActor(gCurrentActorPointer, 0U);
}
*/


// close
// https://decomp.me/scratch/IsDEU
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80028E3C.s")


extern f64 D_bonus_8002DD98;
extern f32 D_bonus_8002DDA0;
extern f32 D_bonus_8002DDA4;
extern f32 D_bonus_8002DDA8;

typedef struct {
    Actor *unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    f32 unkC;
} AAD_bonus_80028E3C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s8 unk10;
} AAD_bonus_80028E3C_2;

/*
void func_bonus_80028E3C(void) {
    AAD_bonus_80028E3C *aaD;
    AAD_bonus_80028E3C_2 *aaD2;
    f32 temp_f2;
    f64 temp_f0;
    f32 var_f0_2;
    f32 var_f2;
    s16 var_a3;
    s32 var_a0;

    aaD = gCurrentActorPointer->additional_actor_data;
    aaD2 = aaD->unk0->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->y_rotation = (rand() >> 0xF) % 4096;
        gCurrentActorPointer->y_acceleration = -10.0f;
        gCurrentActorPointer->unk6A &= 0xFFFE;
        func_global_asm_80613C48(gCurrentActorPointer, 0x688, 0.0f, 0.0f);
        func_global_asm_80614D00(gCurrentActorPointer, 1.0f, 0.0f);
    }
    if (aaD2->unk10 == -1) {
        if (aaD->unk4 == 0) {
            if (aaD2->unkC < 220.0f) {
                if (aaD->unk5 == 0) {
                    var_a0 = 0x7F;
                    aaD->unk5 = 1;
                    var_a3 = aaD->unk6 % 3;
                    if ((aaD->unk6 / 3) != 0) {
                        var_a3 = 2 - var_a3;
                        var_a0 = 0x64;
                    }
                    playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, D_bonus_8002D8C0[var_a3], 0xFF, var_a0, 0, 0, 0.0f, 0);
                }
                if (aaD2->unkC < 40.0f) {
                    aaD->unk4 = 1;
                    playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x1ED, 0xFF, 0x7F, 0, 0, 0.0f, 0);
                    playSoundAtActorPosition(gCurrentActorPointer, 0x76, 0xFF, 0x7F, 0x1E);
                    gCurrentActorPointer->unkEE = gCurrentActorPointer->y_rotation;
                    gCurrentActorPointer->unkB8 = 10.0f;
                    playActorAnimation(aaD->unk0, 0x1F7);
                }
            }
        }
    }
    if (aaD->unk4 == 0) {
        getBonePosition(aaD->unk0, 1, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
    } else {
        if (gCurrentActorPointer->unk6A & 1) {
            if (!(gCurrentActorPointer->unk6C & 1)) {
                f64 temp = D_bonus_8002DD98;
                gCurrentActorPointer->y_velocity = aaD->unkC * D_bonus_8002DDA0;
                playSoundAtActorPosition(gCurrentActorPointer, 0xFF, (u32)MAX(temp, -aaD->unkC * 1.5), 0x7F, 0xA);
            }
        }
        gCurrentActorPointer->y_velocity += gCurrentActorPointer->y_acceleration;
        aaD->unkC = gCurrentActorPointer->y_velocity;
        func_global_asm_8067ACB4(gCurrentActorPointer);
        func_global_asm_806651FC(gCurrentActorPointer);
        func_global_asm_80665564(gCurrentActorPointer, 0);
    }
    gCurrentActorPointer->y_rotation = gCurrentActorPointer->y_rotation + aaD2->unkC;
    if (gCurrentActorPointer->y_rotation >= 0x1000) {
        gCurrentActorPointer->y_rotation = gCurrentActorPointer->y_rotation - 0x1000;
    }
    temp_f2 = D_bonus_8002DDA4 / aaD2->unkC;
    gCurrentActorPointer->x_rotation = func_global_asm_80612794(gCurrentActorPointer->y_rotation) * -temp_f2;
    gCurrentActorPointer->z_rotation = func_global_asm_80612790(gCurrentActorPointer->y_rotation) * temp_f2;
    temp_f2 = temp_f2 * D_bonus_8002DDA8;
    if (temp_f2 < 1) {
        var_f2 = 1;
    } else {
        var_f2 = MIN(2.5f, temp_f2);
    }
    func_global_asm_80614D00(gCurrentActorPointer, var_f2, 0.0f);
    renderActor(gCurrentActorPointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80029364.s")

// Displaylist stuff, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80029B9C.s")

typedef struct {
    u8 unk0[0x25 - 0x0]; // Unused
    u8 unk25;
    u8 unk26;
    u8 unk27; // Unused
    u8 unk28;
    s16 unk2A;
} AAD_80029B9C;

typedef struct {
    u8 unk0[0x3 - 0x0]; // Unused
    u8 unk3;
    u8 unk4[0x6 - 0x4]; // Unused
    u8 unk6;
    u8 unk7; // Unused
    u8 unk8;
    u8 unk9; // Unused
    s16 unkA;
    u8 unkC[0x11 - 0xC]; // Unused
    u8 unk11;
    u8 unk12;
    u8 unk13; // Unused
    u8 unk14;
    s16 unk16;
} A178_80029B9C;

/*
Gfx *func_bonus_80029B9C(Gfx *dl, Actor *arg1) {
    s32 pad;
    A178_80029B9C *a178;
    AAD_80029B9C *aaD;

    a178 = arg1->unk178;
    aaD = arg1->additional_actor_data;
    if ((arg1->unk58 != 0x7E) && (arg1->control_state == 0) && aaD->unk26) {
        dl = func_bonus_80026690(dl, arg1);
    }
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xC8, 0xC8, 0xC8, 0xFF);
    gDPSetCombineLERP(dl++, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED);
    gDPSetRenderMode(dl++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    switch (arg1->unk58) {
        case 0x7D:
            if (arg1->control_state != 3) {
                dl = func_global_asm_806FE078(dl, a178->unk11, 8, 30.0f, 36.0f, 0.0f, 1.5f);
                dl = func_global_asm_8068DC54(dl, 0x26, 0x32, &a178->unk14, a178->unk16, &a178->unk12);
            }
            break;
        case 0x7C:
            if (arg1->control_state != 3) {
                dl = func_global_asm_806FE078(dl, a178->unk3, 8, 30.0f, 36.0f, 0.0f, 1.5f);
                dl = func_global_asm_8068DC54(dl, 0x26, 0x32, &a178->unk8, a178->unkA, &a178->unk6);
            }
            break;
        case 0x7E:
            switch (arg1->control_state) {
                case 7:
                    break;
                case 0:
                case 1:
                case 2:
                    dl = func_global_asm_806FE078(dl, aaD->unk25, 8, 30.0f, 36.0f, 0.0f, 1.5f);
                    dl = func_global_asm_8068DC54(dl, 0x26, 0x32, &aaD->unk28, aaD->unk2A, &aaD->unk26);
                    break;
            }
            break;
    }
    return dl;
}
*/

// rodata, regalloc, stack
// https://decomp.me/scratch/sacJ1
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80029E54.s")

extern f32 D_bonus_8002DDB8;

typedef struct KrazyKK_KongAAD {
    Actor *unk0;
    u8 unk4;
} KrazyKK_KongAAD;

typedef struct KrazyKK_ControllerAAD178 {
    s16 unk0;
    u8 pad2[2];
    f32 unk4;
    s8 unk8[6];
    s16 unkE;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    s16 unk14;
    s16 unk16;
} KrazyKK_ControllerAAD178;

/*
void func_bonus_80029E54(Actor *arg0) {
    KrazyKK_KongAAD *aaD;
    f32 temp_f22;
    KrazyKK_ControllerAAD178 *temp_s7; // 44
    f32 var_f0;
    s16 *a17C;
    Actor *new_var;
    s32 i;
    tuple_f *temp_a0;

    temp_f22 = D_bonus_8002DDB8;
    new_var = arg0;
    temp_s7 = new_var->unk178;
    for (i = 1; i < 7; i++) {
        if (spawnActor(ACTOR_MINIGAME_KRAZYKONGKLAMOUR_KONG, D_bonus_8002D8C8[i - 1])) {
            aaD = gLastSpawnedActor->additional_actor_data;
            a17C = gLastSpawnedActor->unk17C;
            *a17C = D_bonus_8002D8C8[i - 1];
            aaD->unk0 = arg0;
            aaD->unk0 = new_var;
            aaD->unk4 = i - 1;
            temp_a0 = &D_global_asm_807F5FD4->unk0[0][(temp_s7->unk8[aaD->unk4] & 0x7F) + 1];
            gLastSpawnedActor->x_position = temp_a0->x;
            gLastSpawnedActor->y_position = temp_a0->y;
            gLastSpawnedActor->z_position = temp_a0->z;
            gLastSpawnedActor->control_state = 0;
            gLastSpawnedActor->object_properties_bitfield |= 0x1000;
            gLastSpawnedActor->y_rotation = 0x800;
            if (i != 6) {
                func_global_asm_806F0C18(gLastSpawnedActor);
                playActorAnimation(gLastSpawnedActor, D_bonus_8002D8D4[i - 1]);
            }
            var_f0 = i != 6 ? temp_f22 : 0.25f;
            gLastSpawnedActor->animation_state->scale[0] = var_f0;
            gLastSpawnedActor->animation_state->scale[1] = var_f0;
            gLastSpawnedActor->animation_state->scale[2] = var_f0;
        }
    }
}
*/

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002A010.s")

extern f32 D_bonus_8002DDBC;
extern f32 D_bonus_8002DDC0;
extern f64 D_bonus_8002DDC8;
extern f32 D_bonus_8002DDD0;

/*
void func_bonus_8002A010(void) {
    ActorAnimationState *temp_v0_5;
    KrazyKK_KongAAD *temp_t6;
    tuple_f *temp_v0;
    KrazyKK_ControllerAAD178 *temp_t0;
    f32 x, y, z;
    f32 var_f0;
    s8 var_a3;

    temp_t6 = gCurrentActorPointer->AAD_as_array[0];
    temp_t0 = temp_t6->unk0->unk178;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        if (temp_t6->unk4 != 5) {
            func_global_asm_8066EABC(gCurrentActorPointer);
            func_global_asm_8066E8E4(gCurrentActorPointer, 0.0f, 50.0f, 0.0f, 80.0f, -1);
        }
        gCurrentActorPointer->noclip_byte = 0x24;
    }
    temp_v0 = &D_global_asm_807F5FD4->unk0[0][(temp_t0->unk8[temp_t6->unk4] & 0x7F) + 1];
    gCurrentActorPointer->x_position = temp_v0->x;
    gCurrentActorPointer->y_position = temp_v0->y;
    gCurrentActorPointer->z_position = temp_v0->z;
    func_global_asm_80659620(&x, &y, &z, 0);
    if (x < D_bonus_8002DDBC) {
        gCurrentActorPointer->noclip_byte = 0;
    } else {
        gCurrentActorPointer->noclip_byte = 0x24;
    }
    var_a3 = 0;
    if ((D_global_asm_807FBB85 == 1) && (temp_t0->unk0 >= -9)) {
        var_a3 = 1;
    }
    if (temp_t6->unk4 != 5) {
        if (temp_t0->unk8[temp_t6->unk4] & 0x80) {
            temp_t0->unk8[temp_t6->unk4] &= 0x7F;
            playActorAnimation(gCurrentActorPointer, D_bonus_8002D8D4[temp_t6->unk4]);
        } else if ((x < D_bonus_8002DDC0) && (gCurrentActorPointer->animation_state->unk68 != 0)) {
            playActorAnimation(gCurrentActorPointer, 0);
        }
        if (var_a3) {
            playActorAnimation(gCurrentActorPointer, D_bonus_8002D8E0[temp_t6->unk4]);
            playSound(0x2A2, 0x7FFFU, 63.0f, 1.0f, 0, 0);
            if (temp_t0->unk16) {
                temp_t0->unk16++;
            }
        }
        func_global_asm_806BF920();
    } else {
        gCurrentActorPointer->object_properties_bitfield |= 0x1000;
        gCurrentActorPointer->y_rotation += 0x12C;
        if (temp_t0->unk0 < -0x1C) {
            gCurrentActorPointer->control_state = 0;
        }
        temp_v0_5 = gCurrentActorPointer->animation_state;
        if (gCurrentActorPointer->control_state == 1) {
            var_f0 = temp_v0_5->scale[0] - D_bonus_8002DDC8;
            if (var_f0 < 0.0) {
                var_f0 = 0.0f;
            }
        } else {
            var_f0 = D_bonus_8002DDD0;
        }
        temp_v0_5->scale[0] = var_f0;
        gCurrentActorPointer->animation_state->scale[1] = var_f0;
        gCurrentActorPointer->animation_state->scale[2] = var_f0;
        if (var_a3 != 0) {
            playSound(0x2A1, 0x7FFFU, 63.0f, 1.0f, 0, 0);
            temp_t0->unk0 = 0;
            temp_t0->unk16--;
            gCurrentActorPointer->control_state = 1;
        }
    }
    renderActor(gCurrentActorPointer, 0U);
}
*/

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002A398.s")

typedef struct {
    s32 unk0;
    s8 unk4;
} AAD_PPPFairy;

typedef struct {
    u8 unk0[0x06 - 0x0];
    s16 unk6;
} AAD_bonus_8002AAA4;

void func_bonus_8002AAA4(void) {
    AAD_bonus_8002AAA4 *aaD;
    s32 pad;
    s32 pad2;
    Actor *fairy;
    s32 sp54;
    AnimationStateUnk0 *sp50;
    ActorAnimationState *animationState;
    GlobalASMStruct53 *var_s0;
    f32 dy;
    f32 dx;
    s32 i;
    AAD_PPPFairy *fairyAAD;

    aaD = gCurrentActorPointer->additional_actor_data;
    animationState = gCurrentActorPointer->animation_state;
    sp50 = animationState->unk0;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        playActorAnimation(gCurrentActorPointer, 0x239);
        gCurrentActorPointer->noclip_byte = 0x24;
        animationState = gCurrentActorPointer->animation_state;
    }
    sp54 = animationState->unk64;
    if (sp54 == 0x239) {
        for (i = 0; i < D_global_asm_807FBB34; i++) {
            fairy = D_global_asm_807FB930[i].unk0;
            if (fairy->unk58 == ACTOR_MINIGAME_PERILPATHPANIC_FAIRY) {
                dx = fairy->x_position - gCurrentActorPointer->x_position;
                dy = fairy->y_position - gCurrentActorPointer->y_position;
                if (dx < 5.0 && dx > -5.0 ) {
                    if (dy < 20.0f && dy > -20.0) {
                        fairyAAD = fairy->additional_actor_data;
                        fairyAAD->unk4 = 8;
                        playActorAnimation(gCurrentActorPointer, 0x23B);
                    }
                }
            }
        }
    }
    if (sp54 == 0x239 || sp54 == 0x23B || (sp54 == 0x238 && sp50 != NULL && sp50->unk4 > 48.0f)) {
        if (D_global_asm_807FBB85 == 1) {
            playActorAnimation(gCurrentActorPointer, 0x23C);
            aaD->unk6 = D_bonus_8002D900[0] * ((func_global_asm_806119A0() & 7) + 6);
        }
    }
    if (sp54 == 0x23A) {
        aaD->unk6--;
        if (aaD->unk6 == 0) {
            playActorAnimation(gCurrentActorPointer, 0x238);
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

typedef struct {
    Actor *unk0;
    s8 unk4;
} aaD_bonus_8002AD10;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} a8D_bonus_8002AD10;

void func_bonus_8002AD10(void) {
    Struct807F5FD4_unk0 *pad1;
    aaD_bonus_8002AD10 *var_t0;
    Actor *pad2;
    a8D_bonus_8002AD10 *temp_a2;

    var_t0 = gCurrentActorPointer->additional_actor_data;
    pad2 = var_t0->unk0;
    temp_a2 = pad2->unk178;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        playActorAnimation(gCurrentActorPointer, 0x2B5);
    }
    if (var_t0->unk4 == 0 || var_t0->unk4 >= 5) {
        gCurrentActorPointer->x_position -= 1.5;
    }
    pad1 = &D_global_asm_807F5FD4->unk0[0][3];
    if (gCurrentActorPointer->x_position < pad1->unk0 - 50.0) {
        if (temp_a2->unkA > 0) {
            temp_a2->unkA--;
        }
        deleteActor(gCurrentActorPointer);
    }
    if (var_t0->unk4 != 0) {
        var_t0->unk4--;
        if (var_t0->unk4 < 4) {
            f32 temp;
            if (var_t0->unk4 == 3) {
                playSound(0x2D2, 0x7FFF, 63.0f, 7.12f, 0, 1);
            }
            temp = D_bonus_8002DDEC;
            gCurrentActorPointer->animation_state->scale_x *= temp;
            gCurrentActorPointer->animation_state->scale_y *= temp;
            gCurrentActorPointer->animation_state->scale_z *= temp;
        }
        if (var_t0->unk4 == 0) {
            deleteActor(gCurrentActorPointer);
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002AED8.s")

// regalloc, stack
// https://decomp.me/scratch/kcLfg
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002B920.s")

extern f32 D_bonus_8002DE40;
extern f64 D_bonus_8002DE48;

typedef struct {
    Actor* unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} AAD_bonus_8002B920;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s16 unk28;
    s16 unk2A;
    s8 unk2C;
    s8 unk2D[1];
} AAD_bonus_8002B920_2;

/*
void func_bonus_8002B920(void) {
    AAD_bonus_8002B920 *aaD1;
    AAD_bonus_8002B920_2 *aaD2;
    Actor *temp_t6;

    aaD1 = gCurrentActorPointer->additional_actor_data;
    temp_t6 = aaD1->unk0;
    aaD2 = temp_t6->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        f32 temp;
        playActorAnimation(gCurrentActorPointer, 0x32F);
        gCurrentActorPointer->animation_state->scale_z = \
        gCurrentActorPointer->animation_state->scale_y = \
        gCurrentActorPointer->animation_state->scale_x = temp = D_bonus_8002DE40;
        func_global_asm_80604CBC(gCurrentActorPointer, 0x10E, 0x3C, 1, 0, 0xFF, 1.0f, 0);
    }
    if (gCurrentActorPointer->control_state == 0) {
        f32 sp40;
        if (aaD2->unk2C == 0) {
            if (aaD1->unkC > 0) {
                if (aaD1->unkC == 0x28) {
                    func_global_asm_8060866C(gCurrentActorPointer, 0x801, 0xFF, 3.0f, 2, 0);
                }
                aaD1->unkC--;
                sp40 = 5.0f;
            } else {
                sp40 = 3.0f;
            }
            gCurrentActorPointer->y_rotation -= func_global_asm_806CC10C(func_global_asm_80665DE0(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, aaD1->unk4, aaD1->unk8) + 0x800, gCurrentActorPointer->y_rotation) >> 3;
            gCurrentActorPointer->x_position += func_global_asm_80612794(gCurrentActorPointer->y_rotation) * sp40;
            gCurrentActorPointer->z_position += func_global_asm_80612790(gCurrentActorPointer->y_rotation) * sp40;
            aaD1->unkE--;
            if (aaD1->unkE <= 0) {
                s32 temp_s0_3;
                f32 temp_f10;
                if (aaD1->unkC > 0) {
                    aaD1->unkE = (func_global_asm_806119A0() & 7) + 0xA;
                } else {
                    aaD1->unkE = (func_global_asm_806119A0() & 0x3F) + 0xF;
                }
                temp_s0_3 = func_global_asm_80665DE0(aaD2->unk0, aaD2->unk4, aaD1->unk4, aaD1->unk8) + ((func_global_asm_806119A0() & 7) << 8) + 0x400;
                temp_f10 = func_global_asm_806119FC() * D_bonus_8002DE48;
                aaD1->unk4 = (func_global_asm_80612794(temp_s0_3) * temp_f10) + aaD2->unk0;
                aaD1->unk8 = (func_global_asm_80612790(temp_s0_3) * temp_f10) + aaD2->unk4;
            }
        } else {
            if (aaD2->unk2C == 0x28) {
                func_global_asm_8060866C(gCurrentActorPointer, 0x801, 0xFF, 3.0f, 2, 0);
            }
            gCurrentActorPointer->y_position = (func_global_asm_80612794(aaD2->unk18) * 5.0) + (temp_t6->y_position - 30.0);
        }
    } else {
        gCurrentActorPointer->shadow_opacity -= 4;
        if (gCurrentActorPointer->shadow_opacity < 5) {
            gCurrentActorPointer->shadow_opacity = 0;
            deleteActor(gCurrentActorPointer);
        }
    }
    if (temp_t6->control_state == 2) {
        f32 dz;
        f32 dx;
        dx = ((func_global_asm_80612794(temp_t6->y_rotation) * 65.0f) + temp_t6->x_position) - gCurrentActorPointer->x_position;
        dz = ((func_global_asm_80612790(temp_t6->y_rotation) * 65.0f) + temp_t6->z_position) - gCurrentActorPointer->z_position;
        if (gCurrentActorPointer->control_state == 0) {
            if ((dx < 12.0) && (dx > -12.0) && ((dz < 12.0)) && (dz > -12.0)) {
                s32 var_v0;
                func_global_asm_80605314(gCurrentActorPointer, 0);
                playActorAnimation(gCurrentActorPointer, 0x331);
                if (aaD2->unk2A != 0) {
                    aaD2->unk2A--;
                }
                var_v0 = 0;
                do {
                    if (aaD2->unk2D[var_v0] == 0) {
                        aaD2->unk2D[var_v0] = 0x1E;
                        var_v0 = 1;
                    }
                    var_v0++;
                } while (var_v0 <= 0);
                gCurrentActorPointer->control_state = 1;
                func_global_asm_8060866C(gCurrentActorPointer, 0x16, 0xFF, 1.0f, 0x14, 0);
                gCurrentActorPointer->shadow_opacity = 0xFF;
                gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
            } else if ((SQ(dx) + SQ(dz)) < SQ(30.0f)) {
                aaD1->unkC = 0x3C;
                aaD1->unkE = 1;
            }
        }
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002BE44.s")

/*
void func_global_asm_80614644(Actor *, ActorAnimationState *, s32);
extern f32 D_bonus_8002DE50;
extern f64 D_bonus_8002DE58;
typedef struct BonusStruct1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} BonusStruct1;

typedef struct bonus_additional_actor_data {
    s32 unk0;
    BonusStruct1* unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad0[0x7C - 0x14];
    f32 x_position;
    f32 y_position;
    f32 z_position;
} BonusAdditionalActorData;

void func_bonus_8002BE44(void) {
    ActorAnimationState *sp24;
    BonusAdditionalActorData *temp_a0;
    BonusStruct1 *temp_t8;
    s16 phi_a1;

    temp_a0 = ((BonusAdditionalActorData*)gCurrentActorPointer->additional_data_pointer);
    sp24 = gCurrentActorPointer->animation_state;
    temp_t8 = temp_a0->unk4;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->z_rotation = 0;
        gCurrentActorPointer->y_rotation = 0x800;
        func_global_asm_80613C48(temp_a0, 0x5FB, 0, 0);
        gCurrentActorPointer->animation_state->scale_x =// D_bonus_8002DE50;
        gCurrentActorPointer->animation_state->scale_z =// D_bonus_8002DE50;
        gCurrentActorPointer->animation_state->scale_y = D_bonus_8002DE50;
    }
    gCurrentActorPointer->x_position = temp_a0->x_position;
    gCurrentActorPointer->y_position = temp_a0->y_position - D_bonus_8002DE58;
    gCurrentActorPointer->z_position = temp_a0->z_position;
    if (sp24 && temp_t8) {
        phi_a1 = temp_t8->unk10;
        if (phi_a1 == 0x5FD) {
            phi_a1 = 0x5FE;
        }
        if (phi_a1 != sp24->unk10) {
            func_global_asm_80613C48(gCurrentActorPointer, phi_a1, 0, 0);
        }
        func_global_asm_80614644(gCurrentActorPointer, sp24, temp_t8->unk4);
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002BF98.s")

extern f32 D_bonus_8002D90C;
extern u8 D_global_asm_807FBB85;

typedef struct {
    Actor* unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    s16 unkC;
} AAD_bonus_8002C8EC;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s16 unk28;
    s8 unk2A[1];
    s32 unk2C;
} AAD_bonus_8002C8EC_2;

void func_bonus_8002C8EC(void) {
    s32 pad[3];
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    s16 temp_s0_2;
    s32 var_v0;
    Actor *temp;
    AAD_bonus_8002C8EC *temp_s2;
    AAD_bonus_8002C8EC_2 *temp_s3;
    AAD_bonus_8002C8EC_2 *temp_v1_2;

    temp_s2 = gCurrentActorPointer->additional_actor_data;
    temp = temp_s2->unk0;
    temp_s3 = temp->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        playActorAnimation(gCurrentActorPointer, 0x232);
        gCurrentActorPointer->noclip_byte = 0x24;
        gCurrentActorPointer->animation_state->scale_x = 0.25f;
        gCurrentActorPointer->animation_state->scale_y = 0.25f;
        gCurrentActorPointer->animation_state->scale_z = 0.25f;
    }
    if (gCurrentActorPointer->control_state == 0) {
        sp40 = D_bonus_8002D90C;
        temp_s0_2 = (temp_s2->unk4 * 200) - 1400;
        sp30 = (func_global_asm_80612794(temp_s0_2) * temp_s2->unk8) + temp_s3->unk4;
        sp34 = (func_global_asm_80612790(temp_s0_2) * temp_s2->unk8) + temp_s3->unk8;
        gCurrentActorPointer->y_rotation -= func_global_asm_806CC10C(func_global_asm_80665DE0(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, sp30, sp34) + 0x800, gCurrentActorPointer->y_rotation) >> 5;
        gCurrentActorPointer->x_position += func_global_asm_80612794(gCurrentActorPointer->y_rotation) * sp40;
        gCurrentActorPointer->z_position += func_global_asm_80612790(gCurrentActorPointer->y_rotation) * sp40;
        temp_s2->unkC--;
        if (temp_s2->unkC <= 0) {
            temp_s2->unkC = (func_global_asm_806119A0() & 0x3F) + 0xF;
            temp_s2->unk4 += (func_global_asm_806119A0() & 0xF) + 3;
            temp_s2->unk8 = (func_global_asm_806119FC() * 40.0) + 10.0;
        }
        if (D_global_asm_807FBB85 == 1) {
            gCurrentActorPointer->shadow_opacity = 0xFF;
            gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
            playActorAnimation(gCurrentActorPointer, 0x332);
            gCurrentActorPointer->control_state = 1;
            playSound(0x16, 0x7FFF, 63.0f, 1.0f, 0, 0);
            if (temp_s3->unk28 != 0) {
                temp_s3->unk28--;
            }
            for (var_v0 = 0; var_v0 <= 0; var_v0++) {
                if (temp_s3->unk2A[var_v0] == 0) {
                    temp_s3->unk2A[var_v0] = 0x1E;
                    var_v0 = 1;
                }
            }
        }
    } else {
        gCurrentActorPointer->shadow_opacity -= 4;
        if (gCurrentActorPointer->shadow_opacity < 5) {
            gCurrentActorPointer->shadow_opacity = 0;
            deleteActor(gCurrentActorPointer);
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

// Displaylist stuff, doable, close, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002CC08.s")

extern f32 D_bonus_8002DEB4;

typedef struct {
    u8 unk0[0x23 - 0x0];
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s16 unk28;
} AAD_8002CC08;

/*
Gfx *func_bonus_8002CC08(Gfx *dl, Actor *arg1) {
    AAD_8002CC08 *aaD;
    f32 sp80;
    f32 sp7C;
    f32 temp_f20;
    s16 temp_f16;
    s16 temp_f18;
    u8 temp_v0;
    u8 temp_v1_3;

    aaD = arg1->additional_actor_data;
    func_global_asm_80626F8C(arg1->x_position, arg1->y_position, arg1->z_position, &sp80, &sp7C, 0, 1.0f, cc_player_index);
    temp_f16 = (f32)(sp7C * 4.0);
    temp_f18 = (f32)(sp80 * 4.0);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    if ((arg1->control_state == 0) || (arg1->control_state == 1)) {
        temp_f20 = D_bonus_8002DEB4;
        dl = displayImage(dl, ((((u32)object_timer >> 1) % 12) + 0x83), 0, 2, 0x20, 0x10, (s16)(temp_f18 - 0x34), (s16)(temp_f16 - 0x34), temp_f20, temp_f20, 0xE1, 0.0f);
        dl = displayImage(dl, ((((u32)object_timer >> 1) % 12) + 0x83), 0, 2, 0x20, 0x10, (s16)(temp_f18 + 0x34), (s16)(temp_f16 - 0x34), temp_f20, temp_f20, 0x13B, 0.0f);
        dl = displayImage(dl, ((((u32)object_timer >> 1) % 12) + 0x83), 0, 2, 0x20, 0x10, (s16)(temp_f18 + 0x34), (s16)(temp_f16 + 0x34), temp_f20, temp_f20, 0x2D, 0.0f);
        dl = displayImage(dl, ((((u32)object_timer >> 1) % 12) + 0x83), 0, 2, 0x20, 0x10, (s16)(temp_f18 - 0x34), (s16)(temp_f16 + 0x34), temp_f20, temp_f20, 0x87, 0.0f);
    }
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    switch (arg1->control_state) {
        case 7:
            break;
        case 0:
        case 1:
            dl = func_global_asm_806FE078(dl, aaD->unk23, 8, 30.0f, 36.0f, 0.0f, 1.5f);
            dl = func_global_asm_8068DC54(dl, 0x26, 0x32, &aaD->unk26, aaD->unk28, &aaD->unk24);
            break;
    }
    return dl;
}
*/
