#include <ultra64.h>
#include "functions.h"

void func_global_asm_8068A858(s32 *, s32 *, s32 *);
extern Gfx* func_menu_8003292C(Gfx *dl);

extern u8 D_menu_800339D0;

extern s32 D_menu_80033FB0;
extern s32 D_menu_80033FB1;
extern s32 D_menu_80033FB2;

void func_menu_80032550(void) {
    Actor *phi_a0_2;

    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkCD = 1;
        current_actor_pointer->object_properties_bitfield &= ~4;
    }
    if (current_actor_pointer->object_properties_bitfield & 4) {
        func_global_asm_8068A858(&D_menu_80033FB0, &D_menu_80033FB1, &D_menu_80033FB2);
    }
    if ((current_actor_pointer->control_state == 0) && (current_actor_pointer->control_state_progress == 0)) {
        if (func_global_asm_80629148()) {
            func_global_asm_80629174();
            playActorAnimation(current_actor_pointer, 0x2A7);
            current_actor_pointer->control_state_progress++;
        }
        // TODO: Get rid of this somehow, surprisingly getting rid of it causes it to not match
        phi_a0_2 = current_actor_pointer;
    }
    renderActor(current_actor_pointer, 0);
}

void func_menu_8003264C(void) {
    s32 var_a0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk15F = 0;
        func_global_asm_80629174();
        current_actor_pointer->control_state = 0;
    }
    initializeCharacterSpawnerActor();
    switch (current_actor_pointer->control_state) {
        case 0:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                playActorAnimation(current_actor_pointer, 0x2D6);
                current_actor_pointer->control_state++;
                current_actor_pointer->control_state_progress = 0;
                global_properties_bitfield &= ~0x30;
            }
            break;
        case 1:
            func_global_asm_8065A660(20.0f, 40.0f);
            if (current_actor_pointer->unk15F != 0xFF) {
                if (0xFF - current_actor_pointer->unk15F < 3) {
                    var_a0 = 0xFF - current_actor_pointer->unk15F;
                } else {
                    var_a0 = 3;
                }
                current_actor_pointer->unk15F += var_a0;
            }
            createLight(
                current_actor_pointer->x_position,
                current_actor_pointer->y_position + 20.0f,
                current_actor_pointer->z_position,
                current_actor_pointer->x_position,
                current_actor_pointer->y_position,
                current_actor_pointer->z_position,
                0.0f,
                1,
                current_actor_pointer->unk15F,
                current_actor_pointer->unk15F,
                current_actor_pointer->unk15F
            );
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                current_actor_pointer->object_properties_bitfield |= 0x800000;
                current_actor_pointer->control_state = 2;
            }
            break;
        case 2:
            current_actor_pointer->unk16A -= 8;
            current_actor_pointer->unk16B -= 8;
            current_actor_pointer->unk16C -= 8;
            if (current_actor_pointer->unk16A < 9) {
                current_actor_pointer->unk16A = 0;
                current_actor_pointer->unk16B = 0;
                current_actor_pointer->unk16C = 0;
                current_actor_pointer->control_state = 3;
                D_menu_800339D0 = 0;
            }
            break;
        case 3:
            if (D_menu_800339D0 < 0xFF) {
                D_menu_800339D0 += 1;
            }
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                current_actor_pointer->control_state = 4;
            }
            break;
        case 4:
            func_global_asm_807145F8();
            current_actor_pointer->control_state += 1;
            break;
    }
    if (current_actor_pointer->control_state >= 3) {
        addActorToTextOverlayRenderArray(func_menu_8003292C, current_actor_pointer, 3);
    }
    renderActor(current_actor_pointer, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_E550/func_menu_8003292C.s")

/*
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern u8 D_global_asm_8074450C;
extern u8 D_menu_800339D0;

Gfx* func_menu_8003292C(Gfx *dl) {
    s32 spD4;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 sp60;
    s32 sp50;
    s32 sp48;
    Gfx *temp_v0_2;
    f32 temp_f6;
    s16 temp_s0_19;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a3;
    s32 temp_s1;
    s32 temp_t0;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_t9;
    s32 var_a0;
    s32 var_a2;
    s32 var_t0;
    s32 var_t4;
    s32 var_v1;
    void *temp_t1;
    void *temp_t2;
    void *temp_v0;
    void *var_s0;

    spCC = getTextString(0xD, 0, 1);
    spC8 = getTextString(0xD, 1, 1);
    spC4 = getTextString(0xD, 2, 1);
    spC0 = func_global_asm_806FD894(1);
    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetRenderMode(dl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    temp_t7 = D_menu_800339D0 * 0xF;
    var_a2 = temp_t7;
    if (temp_t7 >= 0x100) {
        var_a2 = 0xFF;
    }
    temp_s1 = var_a2 & 0xFF;
    gDPSetPrimColor(dl++, 0, 0, temp_s1, temp_s1, temp_s1, 0xFF);
    gDPSetTextureFilter(dl++, G_TF_POINT);
    gDPSetTexturePersp(dl++, G_TP_NONE);
    temp_v0 = func_global_asm_8068C12C(0xB0U);
    var_a0 = 0;
    sp60 = temp_s1;
    var_t0 = (((f32) D_global_asm_80744494 - 82.0f) * 0.5f);
    do {
        temp_t9 = (var_a0 * 4) & 0xFFF;
        temp_a1 = var_a0 + 0x29;
        temp_a2 = var_t0 + 0x29;
        temp_t6 = (temp_a1 * 4) & 0xFFF;
        sp48 = temp_a2;
        sp50 = temp_a1;
        var_v1 = 0;
        var_t4 = (D_global_asm_80744490 - 204.0f) * 0.5f;
loop_4:
        temp_a3 = ((((((var_v1 * 0) + 0x67) >> 1) + 7) >> 3) & 0x1FF);
        gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 102, temp_v0);
        gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, temp_a3, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        temp_t0 = var_v1 + 0x66;
        gDPLoadSync(dl++);
        gDPLoadTile(dl++, G_TX_LOADTILE, (var_v1 * 2) & 0xFFF, temp_t9, (temp_t0 * 2) & 0xFFF, temp_t6);
        gDPPipeSync(dl++);
        gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_4b, temp_a3, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(dl++, G_TX_RENDERTILE, (var_v1 * 4) & 0xFFF, temp_t9, (temp_t0 * 4) & 0xFFF, temp_t6);
        gSPTextureRectangle(dl++, (var_t4 * 4) & 0xFFF, (var_t0 * 4) & 0xFFF, (temp_a1_2 * 4) & 0xFFF, (temp_a2 * 4) & 0xFFF, G_TX_RENDERTILE, var_v1 << 5, (var_a0 << 5) & 0xFFFF, 0x0400, 0x0400);
        var_v1 = temp_t0;
        var_t4 = temp_a1_2;
        if (temp_t0 != 0xCC) {
            goto loop_4;
        }
        var_a0 = sp50;
        var_t0 = sp48;
    } while (var_a0 != 0x52);
    gDPSetTextureFilter(dl++, G_TF_BILERP);
    gDPSetTexturePersp(dl++, G_TP_PERSP);
    temp_f6 = (D_global_asm_80744490 - getCenterOfString(1, (void *) spCC)) * 0.5f;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, sp60);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0)
    dl = printStyledText(dl, 1, (temp_f6 * 4), (((((f32) D_global_asm_80744494 - 82.0f) * 0.5f) - (f32) spC0) * 4), (void *) spCC, 0);
    temp_a2_2 = D_global_asm_8074450C * 0xC8;
    spD4 = temp_a2_2;
    temp_s0_19 = (D_global_asm_80744490 * 0.5f) * 4;
    dl = printText(dl, temp_s0_19, (temp_a2_2 * 4), 0.5f, (void *) spC8);
    dl = printText(dl, temp_s0_19, ((temp_a2_2 + ((f64) spC0 * 0.5)) * 4), 0.5f, (void *) spC4);
    return dl;
}
*/
