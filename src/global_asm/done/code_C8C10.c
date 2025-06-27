#include "common.h"

void func_global_asm_806C3F10(u8 arg0, u8 arg1, u8 arg2) {
    Actor178 *a178;

    a178 = gCurrentActorPointer->unk178;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_global_asm_807FDC98->unk46 |= 0x20;
        if (arg2) {
            playCutscene(gCurrentActorPointer, arg2, 1);
        } else {
            func_global_asm_8061C518(D_global_asm_807F5D10, gCurrentActorPointer, 4, 0x800, 0x19, 0, 0xA, 0x14, 0xC, 0, 0.1f);
        }
        D_global_asm_807FDC9C->unk10 = 0x27;
        gCurrentActorPointer->control_state = 0x27;
        gCurrentActorPointer->control_state_progress = 0;
    }
    a178->unk0 = MAX(0, D_global_asm_807FDC90->unkC - D_global_asm_807FDC9C->unk6);
    switch (gCurrentActorPointer->control_state) {
        case 39:
            if ((D_global_asm_807FDC90->unk1A & 4) && ((D_global_asm_807FDC90->unk25 & 0x7F) == arg0)) {
                if (!character_change_array->unk2C0) {
                    loadText(gCurrentActorPointer, 0x10, 1);
                    gCurrentActorPointer->control_state = 0x29;
                    gCurrentActorPointer->control_state_progress = 0;
                    D_global_asm_807FDC9C->unk10 = 0x29;
                    extra_player_info_pointer->unk1F0 |= 0x10000;
                    setAction(0x54, NULL, 0);
                    D_global_asm_807FDC90->unk1A |= 0x8000;
                } else {
                    loadText(gCurrentActorPointer, 0x10, 0);
                    gCurrentActorPointer->control_state = 0x28;
                    gCurrentActorPointer->control_state_progress = 0;
                    D_global_asm_807FDC9C->unk10 = 0x28;
                    if (!arg2) {
                        func_global_asm_8061C464(D_global_asm_807F5D10, gCurrentActorPointer, 4, 0x800, 0x19, 0, 0xA, 0x14, 0xC, 0x78, 0.1f);
                    }
                }
            }
            // fallthrough
        case 40:
            func_global_asm_806B49B0(2, 0x23D, 0x23E);
            return;
        case 38:
        case 41:
            if (D_global_asm_807FDC90->unk1A & 0x8000) {
                if ((D_global_asm_807FDC90->unk1A & 4) && ((D_global_asm_807FDC90->unk25 & 0x7F) == arg1)) {
                    if (!arg2) {
                        func_global_asm_806225C0(D_global_asm_807F5D10);
                    }
                    playCutscene(gPlayerPointer, 3, 5);
                    gCurrentActorPointer->control_state = 0x28;
                    gCurrentActorPointer->control_state_progress = 0;
                    D_global_asm_807FDC9C->unk10 = 0x28;
                    extra_player_info_pointer->unk1F0 &= 0xFFFEFFFF;
                    D_global_asm_807FDC90->unk1A &= 0x7FFF;
                } else {
                    if (!arg2) {
                        func_global_asm_8061C464(D_global_asm_807F5D10, gPlayerPointer, 4, (s16)(object_timer * 0x14), 0x1E, 0, 0xA, 0x1E, 0xC, 0, 0.2f);
                    }
                    gPlayerPointer->y_rotation = gCurrentActorPointer->y_rotation;
                    gPlayerPointer->x_position = gCurrentActorPointer->x_position;
                    gPlayerPointer->y_position = gCurrentActorPointer->y_position - 2.0f;
                    gPlayerPointer->z_position = gCurrentActorPointer->z_position;
                    gPlayerPointer->unk6A &= 0xFFFE;
                    gPlayerPointer->locked_to_pad = 0;
                }
            }
            func_global_asm_806B49B0(gCurrentActorPointer->control_state == 0x26 ? 0x26 : 2, 0x23D, 0x23E);
            // fallthrough
        case 0:
            return;
    }
}

void func_global_asm_806C43A8(void) {
    MUSIC_E song = MUSIC_0_SILENCE;
    switch (current_map) {
        case MAP_JAPES_MINECART:
            song = MUSIC_3_JUNGLE_JAPES_MINECART;
            break;
        case MAP_CASTLE_MINECART:
            song = MUSIC_106_CREEPY_CASTLE_MINECART;
            break;
        case MAP_FUNGI_MINECART:
            song = MUSIC_74_FUNGI_FOREST_MINECART;
    }
    if (song != 0) {
        playSong(song, 1.0f);
    }
}

extern s16 D_global_asm_80750AC8;

typedef struct {
    s16 unk0;
} SquawksItemDeliveryAAD2;

void func_global_asm_806C4414(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    SquawksItemDeliveryAAD2 *sp4C; // Used
    PlayerAdditionalActorData* sp48;
    Actor *sp44; // Used
    s32 sp40; // Used

    sp4C = gCurrentActorPointer->AAD_as_array[1];
    sp48 = character_change_array[0].playerPointer->PaaD;
    sp44 = sp48->vehicle_actor_pointer;
    D_global_asm_80750AC8 = arg5;
    createLight(
        gCurrentActorPointer->x_position,
        gCurrentActorPointer->y_position,
        gCurrentActorPointer->z_position,
        0.0f, 0.0f, 0.0f, 80.0f, 0U,
        0xFFU, 0xFFU, 0xFFU);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        sp40 = -1;
        if ((isFlagSet(arg6, 0U)) || (gameIsInDKTVMode())) {
            if (arg3 == D_global_asm_807FDC9C->unk13) {
                func_global_asm_806C43A8();
            }
            gCurrentActorPointer->control_state = 0x40;
            return;
        }
        func_global_asm_80724CA4(1, 1);
        if (arg3 == D_global_asm_807FDC9C->unk13) {
            sp40 = arg0;
        } else {
            setAction(0x46, NULL, 0U);
            if (func_global_asm_806F8AD4(0xBU, 0U) < arg5) {
                gCurrentActorPointer->unk15F = 0;
                sp40 = arg1;
            } else {
                if (isFlagSet(arg6, 0U) == 0) {
                    sp40 = arg2;
                }
                gCurrentActorPointer->unk15F = 0x80;
            }
        }
        sp4C->unk0 = 0xF;
        if (sp40 >= 0) {
            playCutscene(NULL, sp40, 1U);
        }
        if (sp44 != NULL) {
            sp44->unk168 = 0;
        }
    }
    if ((arg4 == D_global_asm_807FDC9C->unk13) && (gCurrentActorPointer->unk15F & 0x80) && (D_global_asm_807FDC90->unk2C == 0x5A)) {
        if (!isFlagSet(arg6, FLAG_TYPE_PERMANENT)) {
            func_global_asm_8069E490(0x2DU, arg6);
            playSong(MUSIC_20_OH_BANANA, 1.0f);
        }
    }
    func_global_asm_8069E4E0(-0x1E);
    func_global_asm_80724E48(0U);
    gCurrentActorPointer->y_rotation = (D_global_asm_807FDC94->y_rotation + 0x800) & 0xFFF;
    gCurrentActorPointer->x_position = (func_global_asm_80612794(gCurrentActorPointer->unkEE) * 12.0f) + D_global_asm_807FDC94->x_position;
    gCurrentActorPointer->z_position = (func_global_asm_80612790(gCurrentActorPointer->unkEE) * 15.0f) + D_global_asm_807FDC94->z_position;
    gCurrentActorPointer->y_position = (func_global_asm_80612794((s16) (object_timer * 0x64)) * 5.0f) + (D_global_asm_807FDC94->y_position + sp4C->unk0);
    gCurrentActorPointer->unkEE += 0x3C;
    switch (gCurrentActorPointer->unk15F & 0x7F) {
    case 0:
        if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
            D_global_asm_807FDC90->unk2C = 0x1E;
        } else {
            gCurrentActorPointer->unk15F++;
        }
        break;
    case 1:
        if (gCurrentActorPointer->object_properties_bitfield & 0x02000000) {
            D_global_asm_807FDC90->unk2C = 0x1E;
        } else {
            gCurrentActorPointer->unk15F++;
            if ((arg4 == D_global_asm_807FDC9C->unk13) && (func_global_asm_806F8AD4(0xBU, 0U) >= arg5)) {
                D_global_asm_807FDC90->unk2C = 0x78;
            }
        }
        break;
    }
    if (D_global_asm_807FDC90->unk2C != 0) {
        D_global_asm_807FDC90->unk2C--;
    }
    if (D_global_asm_807FDC90->unk2C) {
        return;
    }
    sp4C->unk0++;
    if (sp4C->unk0 < 0x3D) {
        return;
    }
    gCurrentActorPointer->control_state = 0x40;
    func_global_asm_806C43A8();
    if (arg4 != D_global_asm_807FDC9C->unk13) {
        return;
    }
    if ((isFlagSet(arg6, FLAG_TYPE_PERMANENT)) || (func_global_asm_806F8AD4(0xBU, 0U) >= arg5)) {
        func_global_asm_805FF544();
        return;
    }
    func_global_asm_806ACC00(1U);
}



void func_global_asm_806C4904(void) {
    func_global_asm_806C4414(0, 1, 2, 0xF, 0x10, 0x32, 0x18);
}

void func_global_asm_806C4948(void) {
    func_global_asm_806C4414(6, 7, 8, 0x10, 0xE, 0x32, 0xD7);
}

void func_global_asm_806C498C(void) {
    func_global_asm_806C4414(1, 2, 3, 4, 5, 0x19, 0x13E);
}

void func_global_asm_806C49D0(void) {
    initializeCharacterSpawnerActor();
    switch (current_map) {
        case MAP_AZTEC:
            func_global_asm_806C3F10(2, 6, 0);
            break;
        case MAP_JAPES_MINECART:
            func_global_asm_806C4904();
            break;
        case MAP_FUNGI_MINECART:
            func_global_asm_806C4948();
            break;
        case MAP_CASTLE_MINECART:
            func_global_asm_806C498C();
            break;
        case MAP_FUNGI:
            if (D_global_asm_807FDC9C->unk13 == 6) {
                func_global_asm_806C3F10(2, 7, 0x1A);
            } else {
                func_global_asm_806C3F10(2, 3, 0);
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

typedef struct {
    s16 unk0;
} A178_806C4AC4;

typedef struct {
    s16 unk0;
} A180_806C4AC4;

u8 func_global_asm_806C4AC4(u16 arg0, u16 arg1) {
    u8 sp4F;
    s32 pad;
    A180_806C4AC4 *a180;
    s32 pad2;
    f32 sp3C;
    A178_806C4AC4 *a178;

    sp4F = 0;
    a178 = gCurrentActorPointer->unk178;
    a180 = gCurrentActorPointer->unk180;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_global_asm_807FDC98->unk46 |= 0x20;
        gCurrentActorPointer->unkB8 = D_global_asm_807FDC9C->unkC;
    }
    a178->unk0 = MAX(0, D_global_asm_807FDC90->unkC - D_global_asm_807FDC9C->unk6);
    if ((gCurrentActorPointer->control_state != 2) && (gCurrentActorPointer->control_state != 0x26)) {
        if (gCurrentActorPointer->control_state == 0x37) {
            func_global_asm_8072AB74(0x37, 0, 0, 0x22, 0);
        }
    } else {
        extra_player_info_pointer->unk1F4 |= 0x40;
        sp3C = func_global_asm_80665AE4(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, gPlayerPointer->x_position, gPlayerPointer->z_position);
        gCurrentActorPointer->unkEC = sp3C - func_global_asm_80665AE4(character_change_array->look_at_at_x, character_change_array->look_at_at_z, character_change_array->look_at_eye_x, character_change_array->look_at_eye_z);
        func_global_asm_806B49B0(gCurrentActorPointer->control_state, D_global_asm_807FDC98->unk28, D_global_asm_807FDC98->unk2A);
        gCurrentActorPointer->unk15F = (arg1 - D_global_asm_807FDC90->unk2C) + 1;
        if (D_global_asm_807FBB70.unk0 != 0) {
            if (D_global_asm_807FBB70.unk1 != gCurrentActorPointer->unk15F) {
                sp4F = 1;
            } else {
                D_global_asm_807FDC90->unk2C--;
                if (D_global_asm_807FDC90->unk2C == 0) {
                    sp4F = 2;
                }
            }
        }
        if (current_character_index[0] != 1) {
            sp4F = 1;
        }
        if (a180->unk0 != 0) {
            a180->unk0--;
        } else if (gCurrentActorPointer->unk168 < arg1) {
            playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x1DD, 0xFF, 0x7F, 0x14, 0x14, 0, 0);
            spawnActor(ACTOR_VULTURE_RACE_HOOP, 0);
            gCurrentActorPointer->unk168++;
            gLastSpawnedActor->unk15F = gCurrentActorPointer->unk168;
            gLastSpawnedActor->x_position = gCurrentActorPointer->x_position;
            gLastSpawnedActor->y_position = gCurrentActorPointer->y_position - 10.0f;
            gLastSpawnedActor->z_position = gCurrentActorPointer->z_position;
            gLastSpawnedActor->y_rotation = gCurrentActorPointer->y_rotation;
            gLastSpawnedActor->unk11C = gCurrentActorPointer;
            a180->unk0 = arg0;
        }
        addActorToTextOverlayRenderArray(func_global_asm_8068E474, gCurrentActorPointer, 3);
    }
    renderActor(gCurrentActorPointer, 0);
    return sp4F;
}

void func_global_asm_806C4E8C(void) {
    func_global_asm_806FB370(5, 0, 0);
}

void func_global_asm_806C4EB4(void) {
    func_global_asm_8063DA40(0x2C, 0xB);
    func_global_asm_806C4E8C();
}

void func_global_asm_806C4EE0(u8 textIndex, u8 arg1) {
    D_global_asm_807FDC90->unk2E = 0;
    func_global_asm_8070E8DC(1);
    loadText(gCurrentActorPointer, 0xF, textIndex);
    gCurrentActorPointer->control_state = 0x29;
    gCurrentActorPointer->control_state_progress = 0;
    gCurrentActorPointer->unk168 = arg1;
    gCurrentActorPointer->unkF0 = 0;
}

s32 func_global_asm_8072881C(s32, s32 *);
void func_global_asm_8072A450(void);

typedef struct {
    s16 unk0;
} VultureRaceAAD3;

void func_global_asm_806C4F5C(void) {
    s32 pad;
    VultureRaceAAD3 *sp28;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    u8 temp_v0;

    sp28 = gCurrentActorPointer->AAD_as_array[3];
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->control_state = 0x1E;
        func_global_asm_8072B79C(0x244, 0x244, 0x246);
        gCurrentActorPointer->unk15E *= 0.5;
    }
    extra_player_info_pointer->unk1F4 &= ~0x40;
    switch (gCurrentActorPointer->control_state) {
    case 0:
    case 14:
    case 15:
    case 30:
        func_global_asm_806BFBF4();
        if (func_global_asm_80629148() != 0) {
            func_global_asm_8063DA40(0x2D, 0x14);
            gCurrentActorPointer->draw_distance = 0x3E8;
            D_global_asm_807FDC98->unk46 |= 0x24;
            loadText(gCurrentActorPointer, 0xFU, 0U);
            playActorAnimation(gCurrentActorPointer, 0x244);
            gCurrentActorPointer->control_state = 0x27;
            D_global_asm_807FDC90->unk2E = 0xF0;
        }
        break;
    case 39:
        extra_player_info_pointer->unk1F4 |= 0x40;
        func_global_asm_806B49B0(2U, 0x244, 0x246);
        if ((D_global_asm_807FDC90->unk1A & 4) && ((D_global_asm_807FDC90->unk25 & 0x7F) == 3)) {
            gCurrentActorPointer->control_state = 0x28;
            gCurrentActorPointer->control_state_progress = 0;
            playActorAnimation(gCurrentActorPointer, 0x244);
        }
        break;
    case 40:
        extra_player_info_pointer->unk1F4 |= 0x40;
        switch (gCurrentActorPointer->control_state_progress) {
        case 0:
        case 1:
        case 2:
            if ((gCurrentActorPointer->floor + 10.0f) < gCurrentActorPointer->y_position) {
                gCurrentActorPointer->y_position -= 2.0f;
            }
            temp_f0 = gPlayerPointer->x_position - gCurrentActorPointer->x_position;
            temp_f2 = gPlayerPointer->y_position - gCurrentActorPointer->y_position;
            temp_f12 = gPlayerPointer->z_position - gCurrentActorPointer->z_position;
            if ((SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f12)) < 6400.0f) {
                gCurrentActorPointer->control_state_progress = 3;
                playCutscene(gCurrentActorPointer, 0x1A, 1U);
                playActorAnimation(gCurrentActorPointer, 0x245);
            } else {
                if (D_global_asm_807FDC90->unk2E != 0) {
                    D_global_asm_807FDC90->unk2E--;
                } else {
                    gCurrentActorPointer->control_state = 0x29;
                    gCurrentActorPointer->control_state_progress = 0;
                    D_global_asm_807FDC90->unk2E = 0;
                    func_global_asm_8070E8DC(1U);
                    loadText(gCurrentActorPointer, 0xFU, 2U);
                }
            }
            break;
        case 3:
            if (func_global_asm_8061CB50() == 0) {
                func_global_asm_8063DA40(0x2C, 0x1E);
                sp28->unk0 = 0x78;
                D_global_asm_807FDC90->unk2C = 0xA;
                gCurrentActorPointer->control_state = 2;
                gCurrentActorPointer->control_state_progress = 0;
                func_global_asm_806FB370(5U, 0U, 1U);
                playActorAnimation(gCurrentActorPointer, 0x244);
            }
            break;
        }
        func_global_asm_8072A450();
        break;
    case 41:
        if (gCurrentActorPointer->unkF0 == 0) {
            playCutscene(gCurrentActorPointer, 0x1C, 1U);
            gCurrentActorPointer->unkF0 += 1;
        } else if (func_global_asm_8061CB50() == 0) {
            if (gCurrentActorPointer->unk168 == 0) {
                func_global_asm_806C4EB4();
                func_global_asm_806ACC00(3U);
                gCurrentActorPointer->control_state = 0x2A;
                gCurrentActorPointer->control_state_progress = 0;
            } else if (gCurrentActorPointer->unkF0 == 1) {
                func_global_asm_8063DA40(0xEB, 0xA);
                gCurrentActorPointer->unkF0 += 1;
            }
            gCurrentActorPointer->y_position += 3.0f;
            D_global_asm_807FDC90->unk2E += 1;
            if (D_global_asm_807FDC90->unk2E >= 0x83) {
                D_global_asm_807FDC98->unk46 &= 0xFFFB;
                func_global_asm_806C4EB4();
                gCurrentActorPointer->control_state = 0x3C;
            }
        }
        func_global_asm_8072A450();
        break;
    case 42:
        func_global_asm_80724A20();
        break;
    case 48:
        gCurrentActorPointer->y_rotation = 0xA82;
        gPlayerPointer->y_rotation = 0xA82;
        func_global_asm_80724B5C(8U, 2U, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
        func_global_asm_80672C30(gPlayerPointer);
        func_global_asm_80724B5C(8U, 2U, &gPlayerPointer->x_position, &gPlayerPointer->y_position, &gPlayerPointer->z_position);
        gPlayerPointer->y_position -= 25.0f;
        gCurrentActorPointer->control_state = 0x28;
        gCurrentActorPointer->control_state_progress = 0;
        playActorAnimation(gCurrentActorPointer, 0x244);
        D_global_asm_807FDC90->unk25 = 2;
        func_global_asm_806FB370(5U, 0U, 1U);
        break;
    }
    temp_v0 = func_global_asm_806C4AC4(0x78U, 0xAU);
    switch (temp_v0) {
    case 1:
        func_global_asm_806C4EE0(2U, 0U);
        break;
    case 2:
        func_global_asm_806C4EE0(3U, 1U);
        break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}



void func_global_asm_806C55D8(void) {

}

typedef struct {
    s16 unk0;
} A180_806C55E0;

void func_global_asm_806C55E0(void) {
    f32 dx;
    A180_806C55E0 *a180;
    f32 dz;

    a180 = gCurrentActorPointer->unk180;
    initializeCharacterSpawnerActor();
    if (!(extra_player_info_pointer->unk1F0 & 0x100000)) {
        gCurrentActorPointer->control_state = 0x40;
        return;
    }
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_8072B79C(0x357, 0x357, 0x359);
        D_global_asm_807FDC98->unk46 |= 0x20;
        gCurrentActorPointer->control_state = 0x1E;
        gCurrentActorPointer->draw_distance = 0x3E8;
        func_global_asm_80728950(0);
    }
    switch (gCurrentActorPointer->control_state) {
        case 30:
            func_global_asm_80684850(1);
            func_global_asm_80724A20();
            break;
        case 39:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if (func_global_asm_8061CB50() == 0) {
                        func_global_asm_807289B0(0, 0);
                        playCutscene(gCurrentActorPointer, 0x13, 1);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 1:
                    if (func_global_asm_80629148()) {
                        playActorAnimation(gCurrentActorPointer, 0x354);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 3:
                    loadText(gCurrentActorPointer, 0x15, 0);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 4:
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        gCurrentActorPointer->control_state = 0x28;
                    }
                    break;
            }
            break;
        case 40:
            if (gPlayerPointer->control_state == 0x63) {
                dx = gCurrentActorPointer->x_position - gPlayerPointer->x_position;
                dz = gCurrentActorPointer->z_position - gPlayerPointer->z_position;
                if ((SQ(dx) + SQ(dz)) < SQ(100.0f)) {
                    playCutscene(gCurrentActorPointer, 0x15, 1);
                    loadText(gCurrentActorPointer, 0x15, 1);
                    gCurrentActorPointer->control_state = 0x29;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
            break;
        case 41:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        playActorAnimation(gCurrentActorPointer, 0x358);
                        gCurrentActorPointer->control_state_progress = 1;
                    }
                    break;
                case 2:
                    func_global_asm_8061CB08();
                    D_global_asm_807FDC98->unk46 |= 0x24;
                    gCurrentActorPointer->control_state = 2;
                    func_global_asm_806FB370(5, 0, 1);
                    func_global_asm_806F8BC4(5, 1, 0);
                    a180->unk0 = 0x78;
                    D_global_asm_807FDC90->unk2C = 0x10;
                    gCurrentActorPointer->unk168 = 0;
                    playActorAnimation(gCurrentActorPointer, 0x357);
                    break;
            }
            break;
        case 42:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    gCurrentActorPointer->x_rotation = 0;
                    gCurrentActorPointer->z_rotation = 0;
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        func_global_asm_806C4E8C();
                        if ((gCurrentActorPointer->animation_state->unk64 == 0x35A) && (gPlayerPointer->control_state == 0x63)) {
                            func_global_asm_806ACC00(4);
                            gCurrentActorPointer->control_state_progress = 3;
                        } else {
                            gCurrentActorPointer->control_state_progress++;
                            gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
                        }
                    }
                    break;
                case 1:
                    func_global_asm_8072DC7C(5);
                    break;
                case 2:
                    gCurrentActorPointer->control_state = 0x3C;
                    break;
                case 3:
                    func_global_asm_80724A20();
                    break;
            }
            break;
        case 48:
            playActorAnimation(gCurrentActorPointer, 0x355);
            func_global_asm_807266E8(gCurrentActorPointer, D_global_asm_807FDC9C);
            D_global_asm_807FDC90->unk25 = 0;
            gCurrentActorPointer->unk168 = 0;
            func_global_asm_80672C30(gPlayerPointer);
            gPlayerPointer->y_position = gCurrentActorPointer->y_position;
            gPlayerPointer->x_position = (func_global_asm_80612794(gCurrentActorPointer->y_rotation) * 50.0f) + gCurrentActorPointer->x_position;
            gPlayerPointer->z_position = (func_global_asm_80612790(gCurrentActorPointer->y_rotation) * 50.0f) + gCurrentActorPointer->z_position;
            gPlayerPointer->y_rotation = func_global_asm_80665DE0(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, gPlayerPointer->x_position, gPlayerPointer->z_position);
            playCutscene(gCurrentActorPointer, 0x15, 1);
            loadText(gCurrentActorPointer, 0x15, 1);
            gCurrentActorPointer->control_state = 0x29;
            gCurrentActorPointer->control_state_progress = 0;
            break;
    }
    extra_player_info_pointer->unk1F4 &= ~0x40;
    switch (func_global_asm_806C4AC4(0x78, 0x10)) {
        case 1:
            func_global_asm_807266E8(gCurrentActorPointer, D_global_asm_807FDC9C);
            loadText(gCurrentActorPointer, 0x15, 2);
            playActorAnimation(gCurrentActorPointer, 0x35A);
            gCurrentActorPointer->control_state = 0x2A;
            gCurrentActorPointer->control_state_progress = 0;
            playCutscene(gCurrentActorPointer, 0x16, 1);
            break;
        case 2:
            func_global_asm_807266E8(gCurrentActorPointer, D_global_asm_807FDC9C);
            loadText(gCurrentActorPointer, 0x15, 3);
            playActorAnimation(gCurrentActorPointer, 0x35B);
            gCurrentActorPointer->control_state = 0x2A;
            gCurrentActorPointer->control_state_progress = 0;
            playCutscene(gCurrentActorPointer, 0x14, 1);
            break;
    }
    if (gCurrentActorPointer->control_state != 0x1E) {
        func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    }
}

extern s16 D_global_asm_807FD802;
extern s16 D_global_asm_807FD804;
extern s16 D_global_asm_807FD806;
extern s16 D_global_asm_8076A0AA;

// Banana Fairy
void func_global_asm_806C5C20(void) {
    f32 sp54;
    f32 sp50;
    f32 dz;
    f32 dx;
    s32 sp44; // TODO: What is this?
    f32 temp_f2_2;
    s32 temp_t1;

    initializeCharacterSpawnerActor();
    func_global_asm_80672C30(gCurrentActorPointer);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_global_asm_807FDC98->unk46 |= 0x40;
        gCurrentActorPointer->draw_distance = 0xFA;
        func_global_asm_80724CA4(2, 1);
    }
    if (RandChance(0.03)) {
        gCurrentActorPointer->unkB8 = D_global_asm_807FDC9C->unkC * 4;
    }
    func_global_asm_80724E48(6);
    func_global_asm_8072AB74(1, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x2C9, 0);
    if (!(object_timer & 3)) {
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(func_global_asm_8071C818);
        drawSpriteAtPosition(&D_global_asm_8071FB08, 1.6f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
    }
    if (!(extra_player_info_pointer->unk1F0 & 0x8000)) {
        dz = character_change_array->look_at_eye_z - gCurrentActorPointer->z_position;
        dx = character_change_array->look_at_eye_x - gCurrentActorPointer->x_position;
        temp_f2_2 = sqrtf(SQ(dz) + SQ(dx)) - character_change_array->near;
        if ((D_global_asm_807FD804 >= 0x8A) && (D_global_asm_807FD804 < 0xB1) && (D_global_asm_807FD806 >= 0x61) && (D_global_asm_807FD806 < 0x88) && (temp_f2_2 < D_global_asm_807FD802)) {
            if ((extra_player_info_pointer->unk1EC != 1) && (func_global_asm_8072DE10(0x1388) != 0)) {
                playActorAnimation(gCurrentActorPointer, 0x2B6);
            }
            extra_player_info_pointer->unk1EC = 1;
        } else {
            if (extra_player_info_pointer->unk1EC != 2) {
                playActorAnimation(gCurrentActorPointer, 0x2B5);
            }
            extra_player_info_pointer->unk1EC = 2;
        }
    }
    if (((extra_player_info_pointer->unk1F0 & 0x8000)) && (extra_player_info_pointer->unk1EC == 1)) {
        if (gCurrentActorPointer->control_state != 0x40) {
            setFlag(func_global_asm_80731784(D_global_asm_8076A0AA, func_global_asm_80727194(gCurrentActorPointer), &sp44), TRUE, FLAG_TYPE_PERMANENT);
            func_global_asm_8060DEC8(); // saveTheGame()
        }
        gCurrentActorPointer->control_state = 0x40;
    }
    if (gCurrentActorPointer->control_state != 0x40) {
        playSong(MUSIC_66_FAIRY_NEARBY, 1.0f);
    } else {
        func_global_asm_80602B60(0x42, 0);
    }
    func_global_asm_80626F8C(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 10.0f, gCurrentActorPointer->z_position, &sp54, &sp50, 0, 1.0f, 0);
    D_global_asm_807FD804 = sp54;
    D_global_asm_807FD806 = sp50;
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C5FEC(void) {
    YetAnotherAdditionalActorData5 *temp_v1;
    PlayerAdditionalActorData *temp_a0;

    temp_v1 = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        temp_v1->unk1C = 0;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    }
    temp_v1->unk1C++;
    switch (temp_v1->unk1E) {
        case 1:
            if (gPlayerPointer->control_state_progress == 3) {
                loadText(gCurrentActorPointer, 0x1E, 3);
                temp_v1->unk1E = 2;
            } else if (temp_v1->unk10->control_state != 0x83) {
                temp_v1->unk1E = 3;
            }
            break;
        case 2:
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                temp_v1->unk1E = 3;
                func_global_asm_8061CB08();
            }
            break;
        default:
            if (temp_v1->unk10->control_state != 0x83) {
                temp_a0 = temp_v1->unk10->PaaD;
                temp_a0->unk1F4 &= ~0x10;
                temp_v1->unk10->object_properties_bitfield &= 0xBFFFFFFF;
                temp_v1->unk10->object_properties_bitfield |= 1;
                temp_v1->unk10->z_rotation = temp_v1->unk16;
                temp_v1->unk10->x_rotation = temp_v1->unk14;
                global_properties_bitfield |= 0x10030;
                func_global_asm_80659670(temp_v1->unk0, temp_v1->unk4, temp_v1->unk8, temp_v1->unk1A);
                func_global_asm_80602B60(0x3B, 0);
                deleteActor(temp_v1->unkC);
                deleteActor(gCurrentActorPointer);
                return;
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C61C8(void) {
    f32 sp24;
    f32 sp20;

    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->unkEC = 0x3C;
        playActorAnimation(gCurrentActorPointer, 0x23D);
        if (gPlayerPointer->control_state == 0xC) {
            playAnimation(gPlayerPointer, 0x87);
        }
    }
    sp24 = (func_global_asm_80612794(gPlayerPointer->y_rotation) * 50.0f) + gPlayerPointer->x_position;
    sp20 = (func_global_asm_80612790(gPlayerPointer->y_rotation) * 50.0f) + gPlayerPointer->z_position;
    gCurrentActorPointer->y_rotation = (gPlayerPointer->y_rotation + 0x800) & 0xFFF;
    if (gCurrentActorPointer->unkEC == 0x3C) {
        gCurrentActorPointer->x_position = (func_global_asm_80612794(gCurrentActorPointer->unkEE) * 10.0f) + sp24;
        gCurrentActorPointer->z_position = (func_global_asm_80612790(gCurrentActorPointer->unkEE) * 10.0f) + sp20;
    }
    gCurrentActorPointer->y_position = (func_global_asm_80612794(object_timer * 0x64) * 5.0f) + (gCurrentActorPointer->unk15F + gPlayerPointer->y_position + 3.0f + gCurrentActorPointer->unkEC);
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        if (gCurrentActorPointer->unkF0 != 0) {
            gCurrentActorPointer->unk15F = 0x14;
            func_global_asm_8069E490(0x2D, func_global_asm_8073195C(gCurrentActorPointer->unkF0));
        }
    }
    if (gCurrentActorPointer->unkF0 != 0) {
        func_global_asm_8069E4E0(-0x1E);
    }
    gCurrentActorPointer->unkEE += 60.0f * func_global_asm_80612794(object_timer * 0x32);
    if (gCurrentActorPointer->object_properties_bitfield & 0x02000000) {
        gCurrentActorPointer->unk168 = 0x14;
    }
    if (gCurrentActorPointer->unk168 != 0) {
        gCurrentActorPointer->unk168--;
    }
    if (gCurrentActorPointer->unk168 == 0) {
        gCurrentActorPointer->unkEC++;
        if (gCurrentActorPointer->unkEC >= 0x3D) {
            if (gCurrentActorPointer->unkF0 != 0) {
                func_global_asm_8069E5B8();
            }
            deleteActor(gCurrentActorPointer);
            func_global_asm_8061CB08();
            if (gPlayerPointer->control_state == 0xC) {
                playAnimation(gPlayerPointer, 9);
            }
        }
    } else {
        if (gCurrentActorPointer->unkEC >= 0x10) {
            gCurrentActorPointer->unkEC--;
        }
    }
    renderActor(gCurrentActorPointer, 0);
}
