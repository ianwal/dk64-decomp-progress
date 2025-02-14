#include <ultra64.h>
#include "functions.h"


// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/IceTomato/func_global_asm_806BC1E0.s")

// Caves Ice Tomato Board State
extern s8 D_global_asm_807FC8C0[];

void func_global_asm_80614644(Actor *, AnimationStateUnk0 *, f32);
void func_global_asm_806A2A10(s32, s32, s32);
extern u16 D_807ECD60;
extern s8 D_global_asm_80750650;
extern s8 D_global_asm_807FC8D0;

/*
typedef struct IceTomatoAAD178 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    s16 unk34;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
} IceTomatoAAD178;

void func_global_asm_806BC1E0(void) {
    f32 sp70;
    AnimationStateUnk0 *sp64;
    s8 sp44[16];
    Actor *timer;
    ActorAnimationState *temp_v0_7;
    f32 dx;
    f32 c;
    f32 temp_f12;
    f32 temp_f12_3;
    f32 b;
    f32 dz;
    f32 temp_f2_4;
    f32 a;
    f32 var_f2;
    f64 temp_f0_3;
    s16 delta_row;
    s16 delta_col;
    s16 var_a0;
    s16 adr;
    s16 var_a1_2;
    s16 var_a2;
    s16 score_0;
    s16 max_dist;
    s16 score_1;
    s16 adc;
    s32 i;
    s8 temp_v0_6;
    s8 j;
    IceTomatoAAD178 *aad178;

    aad178 = current_actor_pointer->unk178;
    sp64 = current_actor_pointer->animation_state->unk0;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        aad178->unk4 = 0.0f;
        func_global_asm_806BD0CC();
        current_actor_pointer->shadow_opacity = 0x80;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        aad178->unk24 = current_actor_pointer->x_position;
        aad178->unk28 = current_actor_pointer->y_position;
        aad178->unk2C = current_actor_pointer->z_position;
        aad178->unk30 = current_actor_pointer->animation_state->scale[1];
        func_global_asm_80629174();
    }
    switch (aad178->unk38) {
    case 0:
        if (!isFlagSet(0x10F, 0U)) {
            dx = current_actor_pointer->x_position - player_pointer->x_position;
            dz = current_actor_pointer->z_position - player_pointer->z_position;
            if ((SQ(dx) + SQ(dz)) < SQ(120.0)) {
                playCutscene(current_actor_pointer, 0, 1U);
                aad178->unk39 = 0U;
                aad178->unk38 = 1U;
            }
        }
        break;
    case 1:
        if (func_global_asm_80629148()) {
            aad178->unk38 = 2U;
        }
        break;
    case 2:
        switch (aad178->unk39) {
        default:
            break;
        case 0:
            addActorToTextOverlayRenderArray(func_global_asm_806BCF98, current_actor_pointer, 5U);
            if ((D_global_asm_807ECD58.button & 0x8000) && !(D_807ECD60 & 0x8000)) {
                func_global_asm_8061CB08();
                aad178->unk39 = 1U;
                player_pointer->control_state = 0xC;
                player_pointer->control_state_progress = 0;
                func_global_asm_806CFF9C(player_pointer);
            }
            if ((D_global_asm_807ECD58.button & 0x4000) && !(D_807ECD60 & 0x4000)) {
                func_global_asm_8061CB08();
                aad178->unk39 = 2U;
                player_pointer->control_state = 0xC;
                player_pointer->control_state_progress = 0;
                func_global_asm_806CFF9C(player_pointer);
            }
            break;
        case 1:
            playCutscene(current_actor_pointer, 1, 1U);
            aad178->unk39 = 3U;
            break;
        case 3:
            if (func_global_asm_80629148()) {
                D_global_asm_80750650 = 1;
                aad178->unk38 = 3U;
                aad178->unk4 = 0.025f;
                aad178->unk0 = 0.0f;
                aad178->unk8 = current_actor_pointer->x_position;
                aad178->unkC = current_actor_pointer->y_position;
                aad178->unk14 = 294.0f;
                aad178->unk18 = 0.0f;
                aad178->unk10 = current_actor_pointer->z_position;
                aad178->unk36 = 3;
                aad178->unk37 = 0;
                aad178->unk1C = 359.0f;
                aad178->unk20 = -500.0f;
                playActorAnimation(current_actor_pointer, 0x31C);
                func_global_asm_806A2A10(0xDC, 0x2A, 0x3C);
                setFlag(0x30, 1U, 2U);
                playSong(0x78, 1.0f);
                func_global_asm_806A2B08(current_actor_pointer->unk11C);
            }
            break;
        case 2:
            if (!func_global_asm_8061CB50()) {
                dx = current_actor_pointer->x_position - player_pointer->x_position;
                dz = current_actor_pointer->z_position - player_pointer->z_position;
                if ((SQ(dx) + SQ(dz)) > SQ(160.0)) {
                    aad178->unk39 = 0U;
                    aad178->unk38 = 0U;
                }
            }
            break;
        }
        break;
    case 3:
    case 4:
        if (aad178->unk4 == 0.0f) {
            if (aad178->unk38 == 3) {
                aad178->unk38 = 4U;
            }
            timer = current_actor_pointer->unk11C;
            if ((timer) && (timer->control_state == 5)) {
                score_0 = 0;
                score_1 = 0;
                for (i = 0; i < 0x10; i++) {
                    if (D_global_asm_807FC8C0[i] == 1) {
                        score_0++;
                    }
                    if (D_global_asm_807FC8C0[i] == 0) {
                        score_1++;
                    }
                }
                setFlag(0x30, 0U, 2U);
                playActorAnimation(current_actor_pointer, 0x31C);
                D_global_asm_80750650 = 1;
                aad178->unk38 = score_0 < score_1 ? 6 : 7;
                aad178->unk4 = 0.0125f;
                aad178->unk0 = 0.0f;
                aad178->unkC = 0.0f;
                aad178->unk8 = current_actor_pointer->x_position;
                aad178->unk10 = current_actor_pointer->z_position;
                aad178->unk34 = 0x1E;
                aad178->unk14 = aad178->unk24;
                aad178->unk18 = aad178->unk28;
                aad178->unk1C = aad178->unk2C;
                aad178->unk20 = -500.0f;
            } else {
                playActorAnimation(current_actor_pointer, 0);
                D_global_asm_80750650 = 0;
                max_dist = 4;
                var_a2 = 0;
                for (j = 0; j < 0x10; j++) {
                    if ((D_global_asm_807FC8C0[j] == 0) || (D_global_asm_807FC8C0[j] == -1)) {
                        delta_col = (j & 3) - aad178->unk36;
                        delta_row = (j >> 2) - aad178->unk37;
                        adc = ABS(delta_col);
                        adr = ABS(delta_row);
                        adc = MAX(adc, adr);
                        if (adc > 0) {
                            if (adc < max_dist) {
                                sp44[0] = j;
                                var_a2 = 1;
                                max_dist = adc;
                            } else {
                                if (adc == max_dist) {
                                    var_a2++;
                                    sp44[var_a2] = j;
                                }
                            }
                        }
                    }
                }
                if (var_a2 > 0) {
                    temp_v0_6 = sp44[(s32)(func_global_asm_806119FC() * (var_a2 - 1))];
                    var_a1_2 = (temp_v0_6 & 3) - aad178->unk36;
                    var_a0 = (temp_v0_6 >> 2) - aad178->unk37;
                    var_a1_2 = MAX(-1, var_a1_2);
                    var_a1_2 = MIN(1, var_a1_2);
                    var_a0 = MAX(-1, var_a0);
                    var_a0 = MIN(1, var_a0);
                    aad178->unk36 += var_a1_2;
                    aad178->unk37 += var_a0;
                }
                aad178->unk0 = 0.0f;
                aad178->unk4 = 0.01369863f;
                temp_f0_3 = aad178->unk36;
                aad178->unk8 = aad178->unk14;
                aad178->unkC = 0.0f;
                aad178->unk10 = aad178->unk1C;
                aad178->unk18 = 0.0f;
                aad178->unk14 = ((temp_f0_3 * -11.666666666666666) + 329.0 + (aad178->unk37 * -28.666666666666668));
                aad178->unk20 = -250.0f;
                aad178->unk1C = ((temp_f0_3 * 28.333333333333332) + 274.0 + (aad178->unk37 * -11.333333333333334));
            }
        }
        break;
    case 6:
        if ((aad178->unk34 == 0) && (aad178->unk4 == 0.0f)) {
            func_global_asm_80602B60(0x78, 1U);
            playSong(0x56, 1.0f);
            playActorAnimation(current_actor_pointer, 0x31C);
            deleteActor(current_actor_pointer->unk11C);
            playCutscene(current_actor_pointer, 2, 1U);
            aad178->unk38 = 8U;
        }
        break;
    case 8:
        if (func_global_asm_80629148() != 0) {
            func_global_asm_806BD0CC();
            if (isFlagSet(0x10F, 0U) == 0) {
                func_global_asm_8063DA40(0x10, 0xA);
            }
            aad178->unk38 = 0xAU;
            func_global_asm_80602B60(0x56, 1U);
            playSong(0x67, 1.0f);
        }
        break;
    case 10:
        break;
    case 7:
        if ((aad178->unk34 == 0) && (aad178->unk4 == 0.0f)) {
            deleteActor(current_actor_pointer->unk11C);
            playActorAnimation(current_actor_pointer, 0x31C);
            playCutscene(current_actor_pointer, 3, 1U);
            aad178->unk38 = 9U;
            func_global_asm_80602B60(0x78, 1U);
            playSong(0x57, 1.0f);
        }
        break;
    case 9:
        if (func_global_asm_80629148() != 0) {
            func_global_asm_80602B60(0x57, 1U);
            playSong(0x67, 1.0f);
            func_global_asm_806BD0CC();
            aad178->unk39 = 0U;
            aad178->unk38 = 2U;
        }
        break;
    default:
        break;
    }
    current_actor_pointer->object_properties_bitfield |= 0x400;
    current_actor_pointer->unk15E = 0x14;
    aad178->unk34--;
    if (aad178->unk34 < 0) {
        aad178->unk34 = 0;
    }
    sp70 = aad178->unk30;
    temp_f2_4 = aad178->unk4;
    if ((temp_f2_4 != 0.0f) && (aad178->unk34 == 0)) {
        temp_f12 = aad178->unk0;
        aad178->unk0 = (f32) (temp_f12 + temp_f2_4);
        if (D_global_asm_80750650 == 0) {
            if ((temp_f12 < 0.63f) && (aad178->unk0 >= 0.63f)) {
                func_global_asm_8063DA78((s16) (aad178->unk36 + (aad178->unk37 * 4)), 1, 1);
                playSoundAtActorPosition(current_actor_pointer, 0x361, 0xFFU, 0x7F, 0xAU);
            }
        } else {
            sp70 += (aad178->unk0 - 0.5f) * 0.25f;
        }
        if (aad178->unk0 >= 1.0) {
            aad178->unk0 = 0.0f;
            aad178->unk4 = 0.0f;
            current_actor_pointer->x_position = aad178->unk14;
            current_actor_pointer->y_position = aad178->unk18;
            current_actor_pointer->z_position = aad178->unk1C;
        } else {
            var_f2 = aad178->unk0;
            if (D_global_asm_80750650 == 0) {
                var_f2 = 2.0 * aad178->unk0;
                if (var_f2 > 1.0) {
                    var_f2 = 1.0f;
                }
            }
            current_actor_pointer->x_position = aad178->unk8 + (var_f2 * (aad178->unk14 - aad178->unk8));
            current_actor_pointer->z_position = aad178->unk10 + (var_f2 * (aad178->unk1C - aad178->unk10));
            if (D_global_asm_80750650 == 0) {
                temp_f12_3 = aad178->unkC;
                current_actor_pointer->y_position = temp_f12_3 + (var_f2 * (aad178->unk18 - temp_f12_3));
            } else {
                a = aad178->unk20;
                b = aad178->unkC;
                c = aad178->unk0;
                current_actor_pointer->y_position = 
                    (b + 
                        (
                            (
                                (f32) ((aad178->unk18 - b) - (a * 0.5))
                                 * c) + ((c * c * a) * 0.5)));
            }
        }
        if ((D_global_asm_80750650 == 0) && (sp64 != NULL) && (aad178->unk0 != 0.0f)) {
            if (sp64->unk10 != 0x5C3) {
                func_global_asm_80613C48(current_actor_pointer, 0x5C3, 0.0f, 0.0f);
            }
            func_global_asm_80614644(current_actor_pointer, sp64, aad178->unk0 * 40.0f);
        }
    }
    temp_v0_7 = current_actor_pointer->animation_state;
    temp_v0_7->scale[1] += ((sp70 - temp_v0_7->scale[1]) * 0.25f);
    renderActor(current_actor_pointer, 0U);
}
*/

Gfx *func_global_asm_806BCF98(Gfx *dl, s32 arg1) {
    gSPDisplayList(dl++, &D_1000118);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    dl = printStyledText(dl, 1, 520, 200, "q YES", 1);
    return printStyledText(dl, 1, 520, 300, "b NO", 1);
}

// Set Caves Ice Tomato Board Square
void func_global_asm_806BD094(s16 arg0, s8 arg1) {
    if (arg0 >= 0 && arg0 < 0x10) {
        D_global_asm_807FC8C0[arg0] = arg1;
    }
}

// Reset Caves Ice Tomato Board
void func_global_asm_806BD0CC(void) {
    s32 i;

    // Caves: Ice Tomato Board Active
    setFlag(0x30, FALSE, FLAG_TYPE_TEMPORARY);

    for (i = 0; i < 16; i++) {
        D_global_asm_807FC8C0[i] = -1;
        func_global_asm_8063DA40(i, 0);
    }

    D_global_asm_807FC8C0[5] = 0;
    D_global_asm_807FC8C0[6] = 1;
    D_global_asm_807FC8C0[9] = 1;
    D_global_asm_807FC8C0[10] = 0;
}
