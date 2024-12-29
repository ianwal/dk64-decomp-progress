#include <ultra64.h>
#include "functions.h"

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2A10.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
} AAD_global_asm_806A2A10;

/*
void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2) {
    spawnActor(ACTOR_TIMER_CONTROLLER, 0);
    if (arg0 & 0x8000) {
        arg2--;
        last_spawned_actor->unk15F = 0xB;
    } else {
        last_spawned_actor->unk15F = 6;
    }
    current_actor_pointer->unk11C = last_spawned_actor;
    extra_player_info_pointer->unk1A8 = last_spawned_actor;
    ((AAD_global_asm_806A2A10*)last_spawned_actor->additional_data_pointer)->unkC = arg2;
    last_spawned_actor->x_position = (s16)(arg0 & 0x7FFF);
    last_spawned_actor->y_position = arg1;
    last_spawned_actor->control_state = 1;
    last_spawned_actor->shadow_opacity = 0;
}
*/

void func_global_asm_806A2B08(Actor *arg0) {
    arg0->control_state = 2;
    arg0->control_state_progress = 0;
    arg0->shadow_opacity = 0xFF;
}

void func_global_asm_806A2B20(Actor *arg0) {
    if (arg0 != 0) {
        arg0->control_state = 1;
        arg0->control_state_progress = 0;
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2B38.s")

extern OSTime D_global_asm_807FC7D0;

typedef struct {
    OSTime unk0;
} AAD_global_asm_806A2B38;

/*
void func_global_asm_806A2B38(Actor *arg0) {
    D_global_asm_807FC7D0 = osGetTime() - 
        ((AAD_global_asm_806A2B38 *)arg0->additional_actor_data)->unk0;
}
*/

void func_global_asm_806A2B80(Actor *arg0) {
    arg0->control_state = 3;
    arg0->control_state_progress = 0;
}

extern SpriteData D_global_asm_8071FC58;

Gfx *func_global_asm_806A2B90(Gfx *dl, Actor *arg1) {
    AAD_global_asm_806A2A10 *sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 var_v0; // 48
    Struct80754AD0 *temp; // 44
    f32 sp40;
    s32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp5C = arg1->additional_actor_data;
    if (func_global_asm_805FCA64()) {
        gSPDisplayList(dl++, &D_1000118);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1->shadow_opacity);
        gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        sp30 = arg1->unk15F;
        if (sp30 == 0xB) {
            dl = func_global_asm_8070068C(dl);
            temp = func_global_asm_806FD9B4(sp5C->unk10);
            dl = printStyledText(dl, 0x86, 
                arg1->x_position * 4.0f,
                ((character_change_array->unk276 * 4) - 0x3C),
                temp->unk4, 1U);
        } else {
            var_v0 = 8;
            sp40 = 6.2831854820251465 - (2.0 * arg1->unk160);
            if (arg1->unk168 == 3) {
                var_v0 = -7;
            }
            dl = func_global_asm_806FE078(dl, 
                sp5C->unk10, sp30, 
                arg1->x_position + var_v0, 
                arg1->y_position + 5.0f, 0.0f, 1.0f);
            if (arg1->control_state == 2) {
                dl = func_global_asm_8070068C(dl);
                func_global_asm_8071495C();
                sp34 = func_global_asm_80612D1C(sp40);
                sp38 = func_global_asm_80612D10(sp40);
                drawSpriteAtPosition(&D_global_asm_8071FC58, 0.5f,
                    (sp34 * 40.0) + (40.0f + arg1->x_position), 
                    (sp38 * 25.0) + arg1->y_position,
                    0.0f);
            }
        }
    }
    return dl;
}



// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2E30.s")
