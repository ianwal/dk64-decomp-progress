#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 *unk4;
    s16 *unk8;
    u8 unkC[0x90 - 0xC];
    Mtx unk90[15][2]; // Not sure on whether it's 15 or not
    u8 unk810[1]; // TODO: How many elements?
} AAD_critter_8002904C;

// PTR TABLE 0x13
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Struct8002A1C0;

extern Struct8002A1C0 *D_critter_8002A1C0;
extern Actor *D_critter_8002A1C4;
extern u16* D_critter_8002A1C8[];
extern u16 D_critter_8002A1CE;
extern u16 D_critter_8002A1CC;

Gfx *func_critter_80028A9C(Gfx *dl, AAD_critter_8002904C *arg1, s8 *arg2, u8 arg3);
void *func_dk64_boot_80002DE4(void*, char*);

void func_critter_80028840(void) {
    D_critter_8002A1C0 = getPointerTableFile(0x13, 4, 1, 1);
    D_critter_8002A1C8[0] = getPointerTableFile(0x13, 5, 1, 1);
    D_critter_8002A1C4 = NULL;
    D_critter_8002A1CE = 0;
    D_critter_8002A1CC = 1;
}

s16 func_critter_800288A8(AAD_critter_8002904C *arg0, u8 *arg1, s16 arg2) {
    s16 temp_f16;
    s8 *temp_v0;
    s16 sp94[14];
    s16 sp70[18];
    u8 sp4C[0x24];
    u8 count;
    s16 i;

    strcpy(&sp4C, arg1);
    temp_v0 = func_dk64_boot_80002DE4(&sp4C, " ");
    temp_f16 = getCenterOfString(6, temp_v0) * 0.5 * 4.0;
    count = 0;
    sp70[count] = arg2;
    sp94[count++] = arg2 + temp_f16;
    arg2 += (temp_f16 * 2) + 0x14;
    while (temp_v0 = func_dk64_boot_80002DE4(NULL, " "), temp_v0 != NULL) {
        temp_f16 = getCenterOfString(6, temp_v0) * 0.5 * 4.0;
        sp70[count] = arg2;
        sp94[count++] = arg2 + temp_f16;
        arg2 += (temp_f16 * 2) + 0x14;
    }
    arg0->unk2 = count;
    arg0->unk8 = malloc(count * 2);
    arg0->unk4 = malloc(count * 2);
    for (i = 0; i < count; i++) {
        arg0->unk4[i] = sp70[i];
        arg0->unk8[i] = sp94[i];
    }
    return sp94[0];
}

// Displaylist stuff, close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_4840/func_critter_80028A9C.s")

/*
Gfx *func_critter_80028A9C(Gfx *dl, AAD_critter_8002904C *arg1, s8 *arg2, u8 arg3) {
    f32 sp98[4][4];
    f32 sp58[4][4];
    u8 sp57 = 100;
    f32 sp50;
    s16 temp_t1;
    s16 sp4C;

    guMtxIdentF(&sp98);
    if (arg1->unk810[arg3]) {
        sp50 = arg1->unk810[arg3] / 12.0f;
        arg1->unk810[arg3]--;
        temp_t1 = arg1->unk8[arg3] - arg1->unk4[arg3];
        guTranslateF(&sp98, -temp_t1, -26.0f, 0.0f);
        guScaleF(&sp58,
            (func_global_asm_80612794(sp50 * 2048.0f) * 0.5) + 1.0,
            (func_global_asm_80612794(sp50 * 2048.0f) * 0.8) + 1.0,
            1.0f);
        guMtxCatF(sp98, sp58, sp98);
        guTranslateF(&sp58, temp_t1, 26.0f, 0.0f);
        guMtxCatF(sp98, sp58, sp98);
        sp57 = (func_global_asm_80612794(sp50 * 2048.0f) * 127.0f) + 128.0f;
    }
    guTranslateF(sp58, arg1->unk4[arg3], arg1->unk0, 0.0f);
    guMtxCatF(sp98, sp58, sp98);
    guMtxF2L(sp98, &arg1->unk90[D_global_asm_807444FC]);
    gSPMatrix(dl++, &arg1->unk90[D_global_asm_807444FC][arg3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, sp57);
    return printStyledText(dl, 6, 0, 0, arg2, 0U);
}
*/

Gfx *func_critter_80028DE8(Gfx *dl, Actor *arg1) {
    void *var_a2;
    u8 i;
    AAD_critter_8002904C *aaD;
    char sp38[7 * 4];

    aaD = arg1->additional_actor_data;
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    strcpy(sp38, &aaD->unk810[0x10]);
    i = 0;
    dl = func_critter_80028A9C(dl, aaD, func_dk64_boot_80002DE4(sp38, " "), i++);
    while (var_a2 = func_dk64_boot_80002DE4(NULL, " ")) {
        dl = func_critter_80028A9C(dl, aaD, var_a2, i++);
    }
    return dl;
}

extern s16 D_global_asm_80744490;

void func_critter_80028EE8(u8 arg0, s32 arg1, s16 arg2, u8 arg3, u16 arg5, u16 arg6) {
    AAD_critter_8002904C *aaD;
    s16 sp2A;
    s16 i;

    sp2A = (D_global_asm_80744490 - getCenterOfString(
        arg0,
        &D_critter_8002A1C0[0] + arg3)) * 2;
    if (D_critter_8002A1C4 != NULL) {
        aaD = D_critter_8002A1C4->additional_actor_data;
        free(aaD->unk8);
        free(aaD->unk4);
    } else {
        spawnActor(ACTOR_DK_RAP_CONTROLLER, 0);
        aaD = last_spawned_actor->additional_actor_data;
        aaD->unk0 = arg2 * 4;
        D_critter_8002A1C4 = last_spawned_actor;
        D_critter_8002A1C4->unkEC = 0;
    }
    D_critter_8002A1C4->x_position = func_critter_800288A8(
        aaD,
        &D_critter_8002A1C0[0] + arg3,
        sp2A);
    D_critter_8002A1C4->unkEE = 0;
    D_critter_8002A1C4->unk168 = arg6 + 0xE;
    strcpy(&aaD->unk810[0x10], &D_critter_8002A1C0[0] + arg3);
    for (i = 1; i < 0x10; i++) {
        aaD->unk810[i] = 0;
    }
    aaD->unk810[0] = 0xC;
}

void func_critter_8002904C(void) {
    AAD_critter_8002904C *aaD;
    s32 temp;
    aaD = current_actor_pointer->additional_actor_data;
    if (D_critter_8002A1CC < 0xF0) {
        if (D_critter_8002A1CE >= *(D_critter_8002A1C8[0] + D_critter_8002A1CC)) {
            D_critter_8002A1CC++;
            aaD->unk810[++current_actor_pointer->unkEE] = 0xC;
        }
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
        addActorToTextOverlayRenderArray(func_critter_80028DE8, current_actor_pointer, 3);
    }
    D_critter_8002A1CE++;
}
