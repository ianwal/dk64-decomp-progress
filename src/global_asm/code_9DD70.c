#include "common.h"

extern s8 D_global_asm_807F6951;
extern s8 D_global_asm_807F6950;

void func_global_asm_80699070(s16 *arg0, s16 *arg1, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2) {
    f32 dx, dz;

    *arg1 = func_global_asm_80665DE0(x1, z1, x2, z2);
    dx = x2 - x1;
    dz = z2 - z1;
    *arg0 = (func_global_asm_80611BB4(y2 - y1, sqrtf(SQ(dx) + SQ(dz))) * 2048.0) / M_PIF;
}

typedef struct {
    u8 unk0[0x128 - 0x0];
    s16 unk128;
} Struct80699128_arg1;

void func_global_asm_80699128(Gfx *dl, Struct80699128_arg1 *arg1) {
    gSPMatrix(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk88[D_global_asm_807444FC]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk8[D_global_asm_807444FC]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    gSPClearGeometryMode(dl++, G_LIGHTING);
    gDPSetPrimColor(dl++, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    func_global_asm_80614B34(func_global_asm_8065D008(dl, arg1->unk128, 1), arg1);
}

// doable, matrix nonsense, close
// https://decomp.me/scratch/NUaRm
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_80699284.s")

u16 *func_global_asm_806FFF88();

typedef struct {
    PlayerAdditionalActorData *unk0;
    s32 unk4;
    s16 *unk8[2];
    u16 unk10;
} AAD_80699284;

/*
void func_global_asm_80699284(void) {
    AAD_80699284 *aaD;
    f32 temp_f0_2;
    f32 var_f0;
    s16 spEA;
    s16 spE8;
    f32 spA8[4][4];
    f32 sp68[4][4];
    s16 sp66;
    u8 sp5F;
    f64 temp_f0;
    f64 var_f2;
    s32 temp_v0;
    s32 var_v1;
    s32 var_v1_2;

    aaD = gCurrentActorPointer->additional_actor_data;
    sp5F = 0;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        aaD->unk10 = 0x5A;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        gCurrentActorPointer->draw_distance = 0x3E8;
        aaD->unk4 = func_global_asm_806FFF88();
        func_global_asm_80613C48(gCurrentActorPointer, 0x40B, 0.0f, 0.0f);
        func_global_asm_80614D00(gCurrentActorPointer, 0.15f, 0.0f);
    }
    gCurrentActorPointer->object_properties_bitfield &= ~4;
    sp66 = 0x5A - aaD->unk10;
    if (sp66 == 0xD) {
        func_global_asm_80604CBC(gCurrentActorPointer, 0x222, 0, 0, 0, 0xFF, 1.0f, -1);
    }
    if (sp66 == 0x1B) {
        func_global_asm_80605314(gCurrentActorPointer, 0);
    }
    temp_v0 = sp66 - 0x1E;
    if (temp_v0 < 0) {
        var_v1 = 0;
    } else {
        var_v1 = temp_v0;
    }
    if (((var_v1 / 60.0f) * 5.0) > 1.0) {
        var_f0 = 1.0;
    } else {
        var_v1_2 = temp_v0;
        if (temp_v0 < 0) {
            var_v1_2 = 0;
        }
        var_f0 = (var_v1_2 / 60.0f) * 5.0;
    }
    if ((var_f0 < 1.0) && (gCurrentActorPointer->unk58 != ACTOR_UNKNOWN_217)) {
        func_global_asm_807002AC(aaD->unk4, &aaD->unk8[D_global_asm_807444FC], var_f0);
        func_global_asm_80688320(gCurrentActorPointer, 0, 0, aaD->unk8[D_global_asm_807444FC]);
    } else {
        func_global_asm_80688320(gCurrentActorPointer, 0, 0, aaD->unk4);
        if (gCurrentActorPointer->control_state_progress == 0) {
            if (extra_player_info_pointer->unk1EC == 1) {
                changeCollectableCount(0xC, extra_player_info_pointer->unk1A4, 1);
                playSong(MUSIC_46_FAIRY_TICK, 1.0f);
            } else if (extra_player_info_pointer->unk1EC == 2) {
                playSound(0x98, 0x7FFF, 63.0f, 1.0f, 0, 0x80);
            }
            gCurrentActorPointer->control_state_progress++;
        }
        if ((extra_player_info_pointer->unk1EC != 0xFF) && (aaD->unk10 != 0)) {
            addActorToTextOverlayRenderArray(func_global_asm_806FF628, gCurrentActorPointer, 3);
        }
    }
    func_global_asm_80699070(&spE8, &spEA, character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z, character_change_array->look_at_at_x, character_change_array->look_at_at_y, character_change_array->look_at_at_z);
    temp_f0 = sp66;
    if (temp_f0 > 30.0) {
        var_f2 = 30.0;
    } else {
        var_f2 = temp_f0;
    }
    gCurrentActorPointer->y_rotation = spEA;
    temp_f0_2 = var_f2 / 30.0;
    gCurrentActorPointer->z_rotation = spE8 - (2048.0f + (-2048.0f * temp_f0_2));
    guRotateF(spA8, (spE8 / 4095.0) * 360.0, 1.0f, 0.0f, 0.0f);
    guRotateF(sp68, (spEA / 4095.0) * 360.0, 0.0f, 1.0f, 0.0f);
    guMtxCatF(spA8, sp68, spA8);
    guTranslateF(sp68, character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z);
    guMtxCatF(spA8, sp68, spA8);
    guMtxXFMF(spA8, 0.0f, 0.0f, -30.0f * temp_f0_2, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
    if (aaD->unk10 != 0) {
        aaD->unk10--;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
        gCurrentActorPointer->shadow_opacity -= 0xA;
        if (gCurrentActorPointer->shadow_opacity <= 0) {
            sp5F = 1;
        }
    }
    if ((sp5F != 0) || !(aaD->unk0->unk1F0 & 0x8000)) {
        if (aaD->unk0->unk1EC == 1) {
            setAction(0x58, NULL, 0);
        }
        func_global_asm_80605314(gCurrentActorPointer, 0);
        aaD->unk0->unk1F0 &= ~0x8000;
        aaD->unk0->unk1EC = 0xFF;
        if (gCurrentActorPointer->unk58 == ACTOR_UNKNOWN_217) {
            func_global_asm_8066B434(aaD->unk4, 0xF6, 0x45);
        } else {
            func_global_asm_8061134C(aaD->unk4);
        }
        aaD->unk0->vehicle_actor_pointer = NULL;
        deleteActor(gCurrentActorPointer);
        return;
    }
    guTranslateF(&gCurrentActorPointer->unkC, 0.0f, -70.0f, 0.0f);
    renderActor(gCurrentActorPointer, 1);
    addActorToTextOverlayRenderArray(func_global_asm_80699128, gCurrentActorPointer, 3);
}
*/

void func_global_asm_806998C8(void) {
    func_global_asm_80699284();
}

void func_global_asm_806998E8(void) {

}

void func_global_asm_806998F0(void) {
    func_global_asm_80699958(8, 0);
}

void func_global_asm_80699914(void) {
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->draw_distance = 1000;
    }
    func_global_asm_80699958(0x1C, 1);
}

// Huge, lots of ActorAnimationState stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_80699958.s")

typedef struct {
    u8 unk0[0x98 - 0x0];
    f32 unk98[4];
    f32 unkA8[4];
    u8 unkB8[4];
} AAD_8069A614;

void func_global_asm_8069A614(f32 arg0, u8 arg1) {
    s16 i;
    s32 found;
    AAD_8069A614 *aaD;

    aaD = gCurrentActorPointer->additional_actor_data;
    found = FALSE;
    i = 0;
    while (i < 4 && !found) {
        if (!aaD->unkB8[i]) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (found) {
        aaD->unkB8[i] = TRUE;
        switch (arg1) {
            case 0:
                aaD->unkA8[i] = 10.0f;
                aaD->unk98[i] = ABS(arg0 / 843.0);
                break;
            case 1:
                aaD->unkA8[i] = 12.0f;
                aaD->unk98[i] = ABS(arg0 / 480.0);
                break;
        }
    }
}

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069A750.s")

extern u8 D_global_asm_807FBBA9;

/*
s32 func_global_asm_8069A750(void) {
    GlobalASMStruct35 *var_a0;
    s32 temp_v0;
    Actor *temp_t8;
    s32 i;
    s32 a_type;

    for (i = 0; i < D_global_asm_807FBBA9; i++) {
        switch (D_global_asm_807FBB70.unk7C[i]->unk58) {
            case 2:
            case 3:
                break;
            default:
                if (is_cutscene_active); // Purely to get this case to load
                break;
        }
    }
    if (gCurrentActorPointer->unk58 == ACTOR_CASTLE_BRIDGE) {
        return 0;
    }
    return 0;
}
*/

// close, doable, float, struct
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069A7C8.s")

typedef struct {
    f32 unk0;
    u8 unk4;
    f32 unk8;
    s32 unkC;
} AAD_8069A7C8;

/*
void func_global_asm_8069A7C8(void) {
    GlobalASMStruct35 *var_s0;
    GlobalASMStruct35 *var_s2;
    f32 temp_f0;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 var_f24;
    f32 temp_f2;
    f32 var_f2;
    f64 temp_f0_5;
    s32 i;
    u32 temp_v1;
    AAD_8069A7C8 *aaD;

    temp_v1 = gCurrentActorPointer->object_properties_bitfield;
    aaD = gCurrentActorPointer->additional_actor_data;
    var_f24 = 0.0f;
    if (!(temp_v1 & 0x10)) {
        gCurrentActorPointer->object_properties_bitfield = temp_v1 | 0x400;
        gCurrentActorPointer->animation_state->unk24 = malloc(2 * sizeof(AnimationStateUnk24));
        gCurrentActorPointer->animation_state->unk24[0].unk0 = 1;
        gCurrentActorPointer->animation_state->unk24[0].unk1 = 0xFF;
        gCurrentActorPointer->animation_state->unk24[0].unk4 = 0.0f;
        gCurrentActorPointer->animation_state->unk24[0].unkC = 0.0f;
        gCurrentActorPointer->animation_state->unk24[0].unk8 = 0.0f;
        gCurrentActorPointer->animation_state->unk24[1].unk0 = 0xFF;
        gCurrentActorPointer->draw_distance = 0x3E8;
        aaD->unk0 = 0.0f;
        aaD->unk4 = 0;
        aaD->unk8 = 0.0f;
        aaD->unkC = 0;
    }
    var_s0 = &D_global_asm_807FBB70;
    for (i = 0; i < D_global_asm_807FBB70.unk39; i++) {
        temp_f0 = var_s0->unk44;
        temp_f2 = var_s0->unk3C;
        var_f2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
        if (var_f2 > 1347.0f) {
            var_f2 = 1347.0f;
        }
        var_f24 += 1347.0f - var_f2;
        temp_f0_3 = ((Actor*)D_global_asm_807FBB70.unk7C[i])->unkB8 * 0.1;
        if (aaD->unk8 < temp_f0_3) {
            aaD->unk8 = temp_f0_3;
        }
        var_s0++; // += 0xC (f32[3]?)
    }
    if (var_f24 > 1347.0f) {
        var_f24 = 1347.0f;
    }
    var_f24 = var_f24 / 10.0;
    if (aaD->unk0 < var_f24) {
        aaD->unk0 = aaD->unk0 + ((var_f24 - aaD->unk0) * 0.25);
        if (var_f24 < aaD->unk0) {
            aaD->unk0 = var_f24;
        }
    }
    if (var_f24 < aaD->unk0) {
        aaD->unk0 = aaD->unk0 - ((aaD->unk0 - var_f24) * 0.5);
        if (aaD->unk0 < var_f24) {
            aaD->unk0 = var_f24;
        }
    }
    aaD->unkC++;
    if ((f64)aaD->unk8 == 0.0) {
        aaD->unkC = 0;
    }
    if (D_global_asm_807FBB70.unk39 != aaD->unk4) {
        aaD->unk8 = 12.0f;
    }
    aaD->unk8 = aaD->unk8 - (aaD->unk8 / 40.0);
    if (aaD->unk8 < 0.5) {
        aaD->unk8 = 0.0f;
    }
    gCurrentActorPointer->animation_state->unk24->unk8 = 0 - (f64)((func_global_asm_80612D1C(aaD->unkC * 0.5) * aaD->unk8) + aaD->unk0);
    aaD->unk4 = D_global_asm_807FBB70.unk39;
    renderActor(gCurrentActorPointer, 0);
}
*/

extern s16 D_global_asm_807503A0;
extern u8 D_global_asm_807FBD70;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
} AAD_8069AB74;

void func_global_asm_8069AB74(void) {
    f32 z;
    f32 y;
    f32 x;
    Actor124 *temp_v0;
    s32 pad3;
    s32 pad4;
    u16 red; // 5e
    u16 green; // 5c
    u16 blue; // 5a
    AAD_8069AB74 *aaD; // 54

    aaD = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_80613C48(gCurrentActorPointer, 0x402, 0.0f, 1.0f);
        if (current_map == MAP_JAPES_MINECART) {
            playActorAnimation(gCurrentActorPointer, 0x297);
        }
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        aaD->unk0 = 0;
        aaD->unk4 = 1.0f;
    }
    func_global_asm_80614D00(gCurrentActorPointer,
        gCurrentActorPointer->unk124->unk0, 1.0f);
    if (D_global_asm_807FBD70 == 4) {
        aaD->unk0 = D_global_asm_807503A0;
        aaD->unk4 = 0.0f;
    }
    if (aaD->unk0 == 0) {
        temp_v0 = gCurrentActorPointer->unk124;
        red = temp_v0->unk4_s32;
        green = temp_v0->unk8_s32;
        blue = temp_v0->unkC_s32;
        red *= (f64)aaD->unk4;
        green *= (f64)aaD->unk4;
        blue *= (f64)aaD->unk4;
        aaD->unk4 += 0.05;
        if (aaD->unk4 > 1.0) {
            aaD->unk4 = 1.0f;
        }
        if (gCurrentActorPointer->object_properties_bitfield & 0x10) {
            temp_v0 = gCurrentActorPointer->unk124;
            if ((temp_v0->unk10 != 0.0) || (temp_v0->unk14 != 0.0)) {
                func_global_asm_8065A660(temp_v0->unk10, temp_v0->unk14);
            }
            func_global_asm_806595F0(2);
            func_global_asm_80659600(gCurrentActorPointer->unk12C);
            getBonePosition(gCurrentActorPointer, 2, &x, &y, &z);
            createLight(
                gCurrentActorPointer->x_position + 0.3,
                gCurrentActorPointer->y_position,
                gCurrentActorPointer->z_position, 
                x, y, z, 0.0f, 1, red, green, blue);
        }
    } else {
        aaD->unk0--;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_8069AFF0(void) {
    func_global_asm_8069AB74();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069B010.s")

typedef struct {
    s16 unk0; // y rotation
} AAD_8069B3FC;

void func_global_asm_8069B3FC(void) {
    AAD_8069B3FC *aaD;
    s32 j, i;
    f32 x, y, z;
    PlayerAdditionalActorData *PaaD;
    void *sprite;

    aaD = gCurrentActorPointer->additional_actor_data;
    PaaD = gPlayerPointer->PaaD;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->noclip_byte = 1;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        playActorAnimation(gCurrentActorPointer, 0x298);
        aaD->unk0 = 0;
        playSong(MUSIC_59_GENERIC_TWINKLY_SOUNDS, 1.0f);
    } else {
        getBonePosition(gCurrentActorPointer, 1, &x, &y, &z);
        PaaD->unk210 = x;
        PaaD->unk214 = y;
        PaaD->unk218 = z;
        if (gCurrentActorPointer->control_state_progress < 4) {
            for (i = 2; i < 3; i++) {
                for (j = 0; j < 2; j++) {
                    func_global_asm_8071498C(func_global_asm_80717D4C);
                    func_global_asm_807149B8(1);
                    func_global_asm_80714950((RandClamp(10000) % 120) + 0x50);
                    switch (RandClamp(10000) % 3) {
                        case 0:
                            sprite = &D_global_asm_8071FC58;
                            break;
                        case 1:
                            sprite = &D_global_asm_8071FC8C;
                            break;
                        case 2:
                            sprite = &D_global_asm_8071FCC0;
                            break;
                    }
                    func_global_asm_80714C08(sprite, 0.6f, gCurrentActorPointer, i, 0);
                }
            }
        }
        switch (gCurrentActorPointer->control_state_progress) {
            case 0:
                aaD->unk0 += 0x1E;
                break;
            case 1:
                gPlayerPointer->control_state_progress++;
                gCurrentActorPointer->control_state_progress++;
                break;
            case 2:
                aaD->unk0 -= 0x2A;
                if (aaD->unk0 < 0) {
                    aaD->unk0 = 0;
                }
                break;
            case 3:
                aaD->unk0 -= 0x2A;
                if (aaD->unk0 < 0) {
                    aaD->unk0 = 0;
                }
                gPlayerPointer->control_state_progress++;
                gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
                gCurrentActorPointer->shadow_opacity = 0xFF;
                gCurrentActorPointer->control_state_progress++;
                break;
            case 4:
                aaD->unk0 -= 0x2A;
                if (aaD->unk0 < 0) {
                    aaD->unk0 = 0;
                }
                gCurrentActorPointer->shadow_opacity -= 0x28;
                if (gCurrentActorPointer->shadow_opacity < 0x28) {
                    gPlayerPointer->control_state_progress++;
                    func_global_asm_80602B60(0x3B, 0);
                    deleteActor(gCurrentActorPointer);
                }
                break;
        }
    }
    gCurrentActorPointer->y_rotation += aaD->unk0;
    renderActor(gCurrentActorPointer, 0);
}

extern s32 D_global_asm_8076A068;

s32 func_global_asm_8069B85C(void) {
    Actor *temp_v1;
    ActorCollision *collision = gCurrentActorPointer->collision_queue_pointer;

    while (collision) {
        if ((collision->unk0 == 0x8000) && (func_global_asm_8067AF44(collision->collisionSource))) {
            temp_v1 = collision->collisionSource;
            if (temp_v1->interactable & 1) {
                PlayerAdditionalActorData *PaaD = temp_v1->PaaD;
                if ((D_global_asm_8076A068 - PaaD->unk120) < 2U) {
                    return TRUE;
                }
            }
        }
        collision = collision->next;
    }
    return FALSE;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069B908.s")

void func_global_asm_8069B908();

void func_global_asm_8069CD9C(void) {
    f32 dz, dx, dy;
    f32 phi_f0;

    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        phi_f0 = (gCurrentActorPointer->animation_state->scale_x / 0.15);
        phi_f0 -= 1.0;
        if (phi_f0 < 0.0) {
            phi_f0 = 0.0f;
        }
        gCurrentActorPointer->unk130 = 80 * phi_f0;
        gCurrentActorPointer->unk131 = 80 * phi_f0;
        gCurrentActorPointer->draw_distance = 700;
    }
    dz = gCurrentActorPointer->z_position - character_change_array->look_at_eye_z;
    dx = gCurrentActorPointer->x_position - character_change_array->look_at_eye_x;
    dy = gCurrentActorPointer->y_position - character_change_array->look_at_eye_y;
    if ((SQ(dz) + (SQ(dx) + SQ(dy))) < 18000.0) {
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~0x400;
    }
    func_global_asm_8069B908();
}

// Apple Code
void func_global_asm_8069CF54(void) {
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->unk130 = 0x3C;
        gCurrentActorPointer->unk131 = 0x3C;
        func_global_asm_80689114(0x83, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0, 1.0f, gCurrentActorPointer);
    }
    func_global_asm_8069B908();
    if ((!(gCurrentActorPointer->object_properties_bitfield & 0x10)) && (gCurrentActorPointer->unk124->unk8_s32 == 1) && isFlagSet(PERMFLAG_ITEM_GB_FUNGI_APPLE, FLAG_TYPE_PERMANENT)) {
        gCurrentActorPointer->unk132 = 4;
    }
}

void func_global_asm_8069D018(void) {
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->draw_distance = 700;
    }
    func_global_asm_8069B908();
}

void func_global_asm_8069D058(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D078(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D098(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D0B8(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D0D8(void) {
    func_global_asm_8069B908();
}

extern s16 D_global_asm_80744490;

// TODO: Put in aaD union
typedef struct {
    void* unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
} GlobalASMStruct_8069D0F8;

u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);

void func_global_asm_8069D0F8(u8 arg0, s16 arg1, s16 arg2, char *arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {
    GlobalASMStruct_8069D0F8 *temp_s0;

    if (spawnActor(ACTOR_TEXT_OVERLAY, 0)) {
        temp_s0 = gLastSpawnedActor->additional_actor_data;
        if (arg0 & 0x80) {
            temp_s0->unkA = func_global_asm_806FDB8C(arg0 & 0xff7f, arg3, 2, 160.0f, arg2, 0.0f);
            gLastSpawnedActor->unkEE = 1;
            gLastSpawnedActor->y_position = arg2;
            return;
        }
        if (arg1 == 0) {
            gLastSpawnedActor->x_position = (D_global_asm_80744490 - getCenterOfString(arg0, arg3)) * 2;
        } else {
            gLastSpawnedActor->x_position = arg1 * 4;
        }
        gLastSpawnedActor->y_position = arg2 * 4;
        gLastSpawnedActor->z_position = arg0;
        gLastSpawnedActor->unk16A = 0xFF;
        gLastSpawnedActor->unk16B = 0xFF;
        gLastSpawnedActor->unk16C = 0xFF;
        temp_s0->unk0 = malloc(strlen(arg3) + 1);
        _strcpy(temp_s0->unk0, arg3);
        temp_s0->unk4 = arg4;
        temp_s0->unk6 = arg5;
        temp_s0->unk8 = arg6;
        temp_s0->unk9 = arg7;
    }
}

void func_global_asm_8069D2AC(u8 arg0, s16 arg1, s16 arg2, char *arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {
    if ((cc_number_of_players < 2)
        && !gameIsInMainMenuMode()
        && !gameIsInDKTVMode()
        && (gameIsInAdventureMode() || gameIsInDKTheatreMode())) {
        func_global_asm_8069D0F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

Gfx *func_global_asm_8069D358(Gfx *dl, Actor *arg1, s16 xOffset, f32 scale) {
    Mtx *spA4;
    f32 sp64[4][4];
    f32 sp24[4][4];

    spA4 = malloc(sizeof(Mtx));
    func_global_asm_8061134C(spA4);
    guScaleF(sp64, scale, scale, 1.0f);
    guTranslateF(sp24, arg1->x_position + (2.0 * xOffset), arg1->y_position, 0.0f);
    guMtxCatF(sp64, sp24, sp64);
    guMtxF2L(sp64, spA4);
    gSPMatrix(dl++, spA4, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069D424.s")

typedef struct {
    u8 unk0[0xA - 0x0];
    u8 unkA;
} AAD_global_asm_8069D930;

Gfx *func_global_asm_8069D930(Gfx *dl, Actor *arg1) {
    AAD_global_asm_8069D930 *aaD;

    aaD = arg1->additional_actor_data;
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (arg1->unk168++ < 0x64) {
        dl = func_global_asm_806FE078(dl, aaD->unkA, 2, 160.0f, arg1->y_position, 0.0f, 1.0f);
    } else {
        dl = func_global_asm_806FE078(dl, aaD->unkA, 1, 160.0f, arg1->y_position, 0.0f, 1.0f);
    }
    return dl;
}

typedef struct {
    void *unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
} AAD_global_asm_8069DA54;

void func_global_asm_8069DA54(void) {
    AAD_global_asm_8069DA54 *aaD;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (gCurrentActorPointer->unkEE != 0) {
        addActorToTextOverlayRenderArray(func_global_asm_8069D930, gCurrentActorPointer, 3);
        return;
    }
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->unk168 = aaD->unk4;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (gCurrentActorPointer->unk168 != 0) {
                gCurrentActorPointer->unk168--;
            } else {
                gCurrentActorPointer->control_state = 1;
            }
            break;
        case 1:
            if (gCurrentActorPointer->control_state_progress != 3) {
                addActorToTextOverlayRenderArray(func_global_asm_8069D424, gCurrentActorPointer, 3);
            }
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if ((0xFF - aaD->unk8) >= gCurrentActorPointer->unk15F) {
                        gCurrentActorPointer->unk15F = gCurrentActorPointer->unk15F + aaD->unk8;
                    } else {
                        gCurrentActorPointer->unk15F = 0xFF;
                        gCurrentActorPointer->control_state_progress++;
                        gCurrentActorPointer->unk168 = aaD->unk6;
                    }
                    break;
                case 1:
                    if (gCurrentActorPointer->unk168 != 0) {
                        gCurrentActorPointer->unk168--;
                    } else {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2:
                    if (gCurrentActorPointer->unk15F >= aaD->unk9) {
                        gCurrentActorPointer->unk15F -= aaD->unk9;
                    } else {
                        gCurrentActorPointer->control_state_progress++;
                        gCurrentActorPointer->unk15F = 0;
                    }
                    break;
                case 3:
                    free(aaD->unk0);
                    deleteActor(gCurrentActorPointer);
                    break;
            }
            break;
    }
}

void func_global_asm_8069DC10(s32 *arg0, s32 *arg1, u8 arg2);

void func_global_asm_8069DC10(s32 *arg0, s32 *arg1, u8 arg2) {
    s16 i;
    s16 j;

    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < arg2; j++) {
            *arg0++ = arg1[j + (i * arg2)];
        }
    }
}

void *func_global_asm_8069DC80(u8 arg0, void *arg1, u8 arg2, u8 arg3, u8 arg4) {
    void *sp24;

    sp24 = func_global_asm_806FBB9C(arg0 + arg3);
    if (arg1) {
        func_global_asm_8061134C(arg1);
    }
    arg1 = malloc(arg4 << 7);
    func_global_asm_8069DC10(arg1, sp24, arg4);
    func_global_asm_8068842C(gCurrentActorPointer, arg2, -1);
    func_global_asm_80688370(gCurrentActorPointer, arg2, 0);
    func_global_asm_80688320(gCurrentActorPointer, arg2, 0, arg1);
    return arg1;
}

extern s16 D_global_asm_807FC930[];

// TODO: Add to aaD union
typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
} AAD_global_asm_8069DD40;

void func_global_asm_8069DD40(void) {
    s32 pad[3]; // TODO: Can we get rid of this somehow?
    AAD_global_asm_8069DD40 *temp_s1;
    u16 temp_s0;
    s32 levelIndex;

    temp_s1 = gCurrentActorPointer->additional_actor_data;
    if (((gCurrentActorPointer->object_properties_bitfield & 0x10) == 0) || (extra_player_info_pointer->unk1F0 & 0x20000)) {
        levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
        if (levelIndex >= 8) {
            levelIndex = 0;
        }
        temp_s0 = D_global_asm_807FC930[levelIndex];
        temp_s1->unk0 = func_global_asm_8069DC80(0x21, temp_s1->unk0, 0, (temp_s0 / 100), 0x20);
        temp_s1->unk4 = func_global_asm_8069DC80(0x21, temp_s1->unk4, 1, ((temp_s0 % 100) / 10), 0x20);
        temp_s1->unk8 = func_global_asm_8069DC80(0x21, temp_s1->unk8, 2, (temp_s0 % 10), 0x20);
        gCurrentActorPointer->unk16A = 0xFF;
        gCurrentActorPointer->unk16B = 0xFF;
        gCurrentActorPointer->unk16C = 0xFF;
        gCurrentActorPointer->object_properties_bitfield |= 0x800000;
        extra_player_info_pointer->unk1F0 &= ~0x20000;
        if (temp_s0 >= D_global_asm_807446C0[levelIndex]) {
            gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
            gCurrentActorPointer->shadow_opacity = 0;
            gCurrentActorPointer->noclip_byte = 1;
            func_global_asm_8063DA40(8, 2);
            func_global_asm_8063DA40(9, 0xA);
            func_global_asm_8063DA40(0xA, 0xA);
            func_global_asm_8063DA40(0xB, 0xA);
            func_global_asm_8063DA40(0xD, 0xA);
            func_global_asm_8063DA40(0xC, 0xA);
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

// TODO: Add to aaD union
typedef struct {
    void *unk0;
    void *unk4;
} AAD_global_asm_8069DF58;

void func_global_asm_8069DF58(void) {
    AAD_global_asm_8069DF58 *aaD;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        aaD->unk0 = func_global_asm_8069DC80(0x14, aaD->unk0, 0, (gCurrentActorPointer->control_state_progress / 10), 0x10);
        aaD->unk4 = func_global_asm_8069DC80(0x14, aaD->unk4, 1, (gCurrentActorPointer->control_state_progress % 10), 0x10);
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_8069E018(void) {
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_8069E040(void) {
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        playActorAnimation(gCurrentActorPointer, 0x299);
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_8069E088(void) {
    s16 textIndex;

    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_80613C48(gCurrentActorPointer, 0x5ED, 0, 0);
    }
    gCurrentActorPointer->unk15E = 0x14;
    if (gCurrentActorPointer->control_state < 0x1E) {
        gCurrentActorPointer->control_state++;
    }
    if (gCurrentActorPointer->control_state == 0x1E) {
        textIndex = 0;
        gCurrentActorPointer->control_state = 0x64;
        func_global_asm_8070E8DC(1);
        if (!isFlagSet(PERMFLAG_FTT_WRINKLY, FLAG_TYPE_PERMANENT)) { // Wrinkly FTT
            setFlag(PERMFLAG_FTT_WRINKLY, TRUE, FLAG_TYPE_PERMANENT);
        } else {
            textIndex = (func_global_asm_80600530() * 5) + D_global_asm_807F6951 + 1;
        }
        loadText(gCurrentActorPointer, 0x29, textIndex);
    }
    if (D_global_asm_807F6950 != 0) {
        deleteActor(gCurrentActorPointer);
    }
    gCurrentActorPointer->animation_state->scale_x = 0.0f;
    gCurrentActorPointer->animation_state->scale_y = 0.0f;
    gCurrentActorPointer->animation_state->scale_z = 0.0f;
    renderActor(gCurrentActorPointer, 0);
}
