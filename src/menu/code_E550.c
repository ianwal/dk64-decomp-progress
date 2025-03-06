#include <ultra64.h>
#include "functions.h"

void func_global_asm_8068A858(s32 *, s32 *, s32 *);
extern Gfx* func_menu_8003292C(Gfx *dl);

// .data
static u8 D_menu_800339D0 = 0;

extern s32 D_menu_80033FB0;
extern s32 D_menu_80033FB1;
extern s32 D_menu_80033FB2;

void func_menu_80032550(void) {
    Actor *phi_a0_2;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->control_state = 0;
        gCurrentActorPointer->control_state_progress = 0;
        gCurrentActorPointer->unkCD = 1;
        gCurrentActorPointer->object_properties_bitfield &= ~4;
    }
    if (gCurrentActorPointer->object_properties_bitfield & 4) {
        func_global_asm_8068A858(&D_menu_80033FB0, &D_menu_80033FB1, &D_menu_80033FB2);
    }
    if ((gCurrentActorPointer->control_state == 0) && (gCurrentActorPointer->control_state_progress == 0)) {
        if (func_global_asm_80629148()) {
            func_global_asm_80629174();
            playActorAnimation(gCurrentActorPointer, 0x2A7);
            gCurrentActorPointer->control_state_progress++;
        }
        // TODO: Get rid of this somehow, surprisingly getting rid of it causes it to not match
        phi_a0_2 = gCurrentActorPointer;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_menu_8003264C(void) {
    s32 var_a0;

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk15F = 0;
        func_global_asm_80629174();
        gCurrentActorPointer->control_state = 0;
    }
    initializeCharacterSpawnerActor();
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                playActorAnimation(gCurrentActorPointer, 0x2D6);
                gCurrentActorPointer->control_state++;
                gCurrentActorPointer->control_state_progress = 0;
                global_properties_bitfield &= ~0x30;
            }
            break;
        case 1:
            func_global_asm_8065A660(20.0f, 40.0f);
            if (gCurrentActorPointer->unk15F != 0xFF) {
                if (0xFF - gCurrentActorPointer->unk15F < 3) {
                    var_a0 = 0xFF - gCurrentActorPointer->unk15F;
                } else {
                    var_a0 = 3;
                }
                gCurrentActorPointer->unk15F += var_a0;
            }
            createLight(
                gCurrentActorPointer->x_position,
                gCurrentActorPointer->y_position + 20.0f,
                gCurrentActorPointer->z_position,
                gCurrentActorPointer->x_position,
                gCurrentActorPointer->y_position,
                gCurrentActorPointer->z_position,
                0.0f,
                1,
                gCurrentActorPointer->unk15F,
                gCurrentActorPointer->unk15F,
                gCurrentActorPointer->unk15F
            );
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                gCurrentActorPointer->object_properties_bitfield |= 0x800000;
                gCurrentActorPointer->control_state = 2;
            }
            break;
        case 2:
            gCurrentActorPointer->unk16A -= 8;
            gCurrentActorPointer->unk16B -= 8;
            gCurrentActorPointer->unk16C -= 8;
            if (gCurrentActorPointer->unk16A < 9) {
                gCurrentActorPointer->unk16A = 0;
                gCurrentActorPointer->unk16B = 0;
                gCurrentActorPointer->unk16C = 0;
                gCurrentActorPointer->control_state = 3;
                D_menu_800339D0 = 0;
            }
            break;
        case 3:
            if (D_menu_800339D0 < 0xFF) {
                D_menu_800339D0 += 1;
            }
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                gCurrentActorPointer->control_state = 4;
            }
            break;
        case 4:
            func_global_asm_807145F8();
            gCurrentActorPointer->control_state += 1;
            break;
    }
    if (gCurrentActorPointer->control_state >= 3) {
        addActorToTextOverlayRenderArray(func_menu_8003292C, gCurrentActorPointer, 3);
    }
    renderActor(gCurrentActorPointer, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_E550/func_menu_8003292C.s")

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern u8 D_global_asm_8074450C;

/*
Gfx* func_menu_8003292C(Gfx *dl) {
    u8 *spCC;
    u8 *spC8;
    u8 *spC4;
    s32 spC0;
    s32 sp50;
    s32 sp48;
    f32 temp_f6;
    s16 temp_s0_19;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_t0;
    s32 temp_t9;
    s32 i;
    s32 var_a2;
    s32 x_offset, y_offset;
    s32 j;
    void *temp_v0;

    spCC = getTextString(0xD, 0, 1);
    spC8 = getTextString(0xD, 1, 1);
    spC4 = getTextString(0xD, 2, 1);
    spC0 = func_global_asm_806FD894(1);
    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetRenderMode(dl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    var_a2 = MIN(D_menu_800339D0 * 0xF, 0xFF);
    gDPSetPrimColor(dl++, 0, 0, var_a2, var_a2, var_a2, 0xFF);
    gDPSetTextureFilter(dl++, G_TF_POINT);
    gDPSetTexturePersp(dl++, G_TP_NONE);
    temp_v0 = func_global_asm_8068C12C(0xB0U);
    y_offset = (D_global_asm_80744494 - 82.0f) * 0.5f;
    for (i = 0; i != 0x52; i += 0x29) {
        temp_a1 = i + 0x29;
        temp_a2 = y_offset + 0x29;
        x_offset = (D_global_asm_80744490 - 204.0f) * 0.5f;
        for (j = 0; j != 0xCC; j += 0x66) {
            temp_t0 = j + 0x66;
            gDPLoadTextureTile_4b(dl++, temp_v0, G_IM_FMT_I, 204, 82,\
                j, i, temp_t0, temp_a1, 0,\
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, \
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(dl++, x_offset, y_offset,\
                temp_a2, temp_a2, G_TX_RENDERTILE,\
                j << 5, (i << 5) & 0xFFFF, 0x0400, 0x0400);
            x_offset += 0x66;
        }
        y_offset += 0x29;
    };
    gDPSetTextureFilter(dl++, G_TF_BILERP);
    gDPSetTexturePersp(dl++, G_TP_PERSP);
    temp_f6 = (D_global_asm_80744490 - getCenterOfString(1, spCC)) * 0.5f;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, var_a2);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0)
    dl = printStyledText(dl, 1, temp_f6 * 4, ((((D_global_asm_80744494 - 82.0f) * 0.5f) - (f32) spC0) * 4), spCC, 0);
    temp_a2_2 = D_global_asm_8074450C * 0xC8;
    temp_s0_19 = (D_global_asm_80744490 * 0.5f) * 4;
    dl = printText(dl, temp_s0_19, temp_a2_2 * 4, 0.5f, spC8);
    dl = printText(dl, temp_s0_19, (s32)(temp_a2_2 + (spC0 * 0.5)) * 4, 0.5f, spC4);
    return dl;
}
*/
