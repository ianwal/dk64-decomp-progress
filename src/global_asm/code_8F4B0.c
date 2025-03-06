#include "common.h"

extern u8 D_global_asm_807501E0;

extern u8 D_global_asm_807FC620;
extern u8 D_global_asm_807FC621;
extern u8 D_global_asm_807FC622;

// spawnPersistantActors
void func_global_asm_8068A7B0(void) {
    spawnActor(ACTOR_UNKNOWN_10, 0);
    spawnActor(ACTOR_UNKNOWN_11, 0);
    spawnActor(ACTOR_LOADING_ZONE_CONTROLLER, 0);
    spawnActor(ACTOR_PROP_CONTROLLER, 0);
    spawnActor(ACTOR_UNKNOWN_14, 0);
    spawnActor(ACTOR_UNKNOWN_15, 0);
}

void func_global_asm_8068A810(void) {
    func_global_asm_8072E868();
}

void func_global_asm_8068A830(void) {
    func_global_asm_80727678();
    func_global_asm_80727958();
}

typedef struct Struct80750194 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
} Struct80750194;

extern Struct80750194 D_global_asm_80750194[];
extern rgb D_global_asm_807501C0[];
extern u8 D_global_asm_807FC621;
extern u8 D_global_asm_807FC622;

void func_global_asm_8068A858(u8 *arg0, u8 *arg1, u8 *arg2) {
    rgb *temp_v0;
    f32 sp40;
    f32 sp3C;
    f32 var_f2;

    if (gCurrentActorPointer->object_properties_bitfield & 4) {
        switch (D_global_asm_807FC622) {
        case 0:
            *arg0 = 0xFF;
            *arg1 = 0xFF;
            *arg2 = 0xFF;
            break;
        case 1:
            if (!(object_timer & 0xF)) {
                goto block_9;
            }
            break;
        case 2:
            if (!(object_timer & 0x3)) {
block_9:
                temp_v0 = &D_global_asm_807501C0[(u8)((func_global_asm_80612790(200 * object_timer) * 4.0f) + 4.0f)];
                *arg0 = temp_v0->red;
                *arg1 = temp_v0->green;
                *arg2 = temp_v0->blue;
            }
            break;
        
        }
        if ((D_global_asm_807FC621 & 0x80) && (D_global_asm_807FC621 & 0x7F)) {
            D_global_asm_807FC621 &= 0x7F;
            sp40 = D_global_asm_80750194[D_global_asm_807FC621 - 1].unk8;
            sp3C = D_global_asm_80750194[D_global_asm_807FC621 - 1].unkA;
            var_f2 = D_global_asm_80750194[D_global_asm_807FC621 - 1].unkC;
            if (D_global_asm_807FC622) {
                sp40 += 80.0f * func_global_asm_80612794(object_timer * 400);
                var_f2 += 80.0f * func_global_asm_80612790(object_timer * 200);
            }
            func_global_asm_8065A660(D_global_asm_80750194[D_global_asm_807FC621 - 1].unk0, D_global_asm_80750194[D_global_asm_807FC621 - 1].unk1);
            createLight(
                D_global_asm_80750194[D_global_asm_807FC621 - 1].unk2,
                D_global_asm_80750194[D_global_asm_807FC621 - 1].unk4, 
                D_global_asm_80750194[D_global_asm_807FC621 - 1].unk6,
                sp40, sp3C, var_f2,
                0.0f, 1U, 
                *arg0, *arg1, *arg2);
        }
    }
}

s32 func_global_asm_8068ABE0(s16 arg0) {
    s16 cutsceneIndex;
    s32 sp20;
    s32 found;
    s32 i;
    Maps map;
    s32 exit; // 20

    cutsceneIndex = -1;
    i = 0, found = 0;
    while (!found && i < 8) {
        if (current_map == D_global_asm_80744734[i]) {
            found = 1;
        } else {
            i++;
        }
    }
    if (found) {
        if (!isFlagSet(PERMFLAG_LEVEL_ENTERED_JAPES + i, FLAG_TYPE_PERMANENT)) {
            exit = 0;
            switch (arg0) {
                case 0x7:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0xF;
                    break;
                case 0x26:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x10;
                    break;
                case 0x1A:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x11;
                    break;
                case 0x1E:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x12;
                    break;
                case 0x30:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x13;
                    break;
                case 0x48:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x14;
                    break;
                case 0x57:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x15;
                    exit = 0x15;
                    break;
                case 0x11:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x16;
                    break;
            }
            if (cutsceneIndex != -1) {
                setFlag(PERMFLAG_LEVEL_ENTERED_JAPES + i, TRUE, FLAG_TYPE_PERMANENT);
                if (story_skip) {
                    func_global_asm_805FF378(arg0, exit);
                    return TRUE;
                } else {
                    func_global_asm_80712524(map, cutsceneIndex);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void func_global_asm_805FF9AC(Maps, s32, s32, s16);
void func_global_asm_80608DA8(s32, u8, s32, s32, s32);
void func_global_asm_80659F7C(f32, f32, f32, f32, s32);
void func_global_asm_80711BD0(f32, s16, s16, u8);
extern u16 D_global_asm_8076A0A6;
extern s16 D_global_asm_807FDCB8;
extern s16 D_global_asm_807FDCBC;
extern u16 D_global_asm_80744700[];
extern u8 D_global_asm_80750190;
extern u8 D_global_asm_807FBDC4;

typedef struct LZControllerAAD {
    u8 unk0;
    u8 pad1[0x4 - 0x01];
    f32 unk4;
    s16 unk8;
    u8 padA[2];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    u8 unk20;
    u8 unk21;
} LZControllerAAD;

void func_global_asm_8068AD7C(void) {
    Struct807FBB70_unk278 *temp_s0;
    s32 i; // 60
    s32 var_s0;
    s32 var_v0;
    LZControllerAAD *TaaD;
    f32 temp;

    TaaD = gCurrentActorPointer->AAD_as_array[0];
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        TaaD->unk0 = 0U;
        TaaD->unk1A = -1;
        TaaD->unk21 = 0U;
        func_global_asm_80659620(&TaaD->unkC, &TaaD->unk10, &TaaD->unk14, 0);
    }
    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        if (i);
        temp_s0 = D_global_asm_807FBB70.unk278[i];
        switch (D_global_asm_807FBB70.unk258[i]) {
        case 0xFF:
            TaaD->unk1E = 0;
            TaaD->unk0 = 0xFF;
            break;
        case 0xF:
            func_global_asm_80704AFC(
                temp_s0->unk0 / 255.0, 
                temp_s0->unk2 / 255.0,
                temp_s0->unk4 / 255.0
            );
            break;
        case 0xE:
            TaaD->unkC = temp_s0->unk0 / 255.0;
            TaaD->unk10 = temp_s0->unk2 / 255.0;
            TaaD->unk14 = temp_s0->unk4 / 255.0;
            TaaD->unk1A = temp_s0->unk6;
            break;
        case 0x10:
            TaaD->unk1C = temp_s0->unk6;
            TaaD->unk1E = TaaD->unk1C;
            break;
        case 0x1:
            if ((current_map != MAP_FUNGI) || !(extra_player_info_pointer->unk1F0 & 0x200000)) {
                TaaD->unk0 = temp_s0->unk0;
                TaaD->unk1A = temp_s0->unk2;
                TaaD->unk4 = (f32)(temp_s0->unk4) / 100.0;
                TaaD->unk8 = temp_s0->unk6;
                break;
            }
            break;
        case 0x2:
            if ((current_map != MAP_FUNGI) || !(extra_player_info_pointer->unk1F0 & 0x200000)) {
                TaaD->unk0 = 0xFF;
                break;
            }
            break;
        case 0x3:
            if (!(global_properties_bitfield & 0x400)) {
                if (temp_s0->unk4) {
                    setIntroStoryPlaying(2U);
                    func_global_asm_805FF158(0U);
                }
                if (temp_s0->unk0 == MAP_HELM) {
                    if (func_global_asm_8068ABE0(temp_s0->unk0) == 0) {
                        func_global_asm_805FF378(temp_s0->unk0, temp_s0->unk2);
                    }
                } else {
                    func_global_asm_805FF378(temp_s0->unk0, temp_s0->unk2);
                }
                func_global_asm_806F3BEC(gPlayerPointer, D_global_asm_807FDCB8, D_global_asm_807FDCBC, 0x46U);
                break;
            }
            break;
        case 0x15:
            if (!(global_properties_bitfield & 0x400)) {
                func_global_asm_805FF4D8(temp_s0->unk0, temp_s0->unk2);
                break;
            }
            break;
        case 0x4:
            if (!(global_properties_bitfield & 0x400)) {
                switch (temp_s0->unk4) {
                    case 1:
                        setIntroStoryPlaying(2U);
                    default:
                        func_global_asm_805FF158(0U);
                        break;
                    case 0:
                        break;
                }
                func_global_asm_805FF9AC(temp_s0->unk0, temp_s0->unk2, 0, 0);
                func_global_asm_806F3BEC(gPlayerPointer, D_global_asm_807FDCB8, D_global_asm_807FDCBC, 0x46U);
                break;
            }
            break;
        case 0x5:
            if (!(global_properties_bitfield & 0x400)) {
                func_global_asm_805FF628(temp_s0->unk0, temp_s0->unk2);
                func_global_asm_806F3BEC(gPlayerPointer, D_global_asm_807FDCB8, D_global_asm_807FDCBC, 0x46U);
                break;
            }
            break;
        case 0x6:
            extra_player_info_pointer->unk100 = 1;
            func_global_asm_806C92C4(temp_s0->unk0);
            break;
        case 0x7:
            if (!(global_properties_bitfield & 0x400)) {
                func_global_asm_805FF9AC(temp_s0->unk0, temp_s0->unk2, temp_s0->unk4, 2);
                func_global_asm_806F3BEC(gPlayerPointer, D_global_asm_807FDCB8, D_global_asm_807FDCBC, 0x46U);
                break;
            }
            break;
        case 0x8:
            if (!(global_properties_bitfield & 0x400)) {
                func_global_asm_805FF898();
                func_global_asm_806F3BEC(gPlayerPointer, D_global_asm_807FDCB8, D_global_asm_807FDCBC, 0x46U);
                break;
            }
            break;
        case 0x19:
            func_global_asm_805FF8F8();
            break;
        case 0x9:
            func_global_asm_805FF660(temp_s0->unk0);
            break;
        case 0xA:
            character_change_array->playerPointer->PaaD->unk1F0 |= 0x40000800;
            break;
        case 0xB:
            func_global_asm_805FF378(D_global_asm_80744700[getLevelIndex(current_map, 0U)], current_exit);
            func_global_asm_806F3BEC(gPlayerPointer, D_global_asm_807FDCB8, D_global_asm_807FDCBC, 0x46U);
            break;
        case 0xC:
            var_v0 = temp_s0->unk2 ? 0 : 0x8000;
            func_global_asm_806F397C(gPlayerPointer, NULL, temp_s0->unk0 + var_v0, 0);
            break;
        case 0xD:
            if (gPlayerPointer->unkB8 > 250.0f) {
                playSoundAtActorPosition(gPlayerPointer, temp_s0->unk0, 0xFFU, 0x7F, 0x1EU);
                break;
            }
            break;
        case 0x16:
            playSong(temp_s0->unk0, 1.0f);
            break;
        case 0x17:
            func_global_asm_80602B60(temp_s0->unk0, 0U);
            break;
        case 0x11:
            gCurrentPlayer->y_acceleration = temp_s0->unk0 / 10.0;
            break;
        case 0x12:
            gCurrentPlayer->unk6A |= 0x200;
            break;
        case 0x13:
            gCurrentPlayer->unk6A &= ~0x200;
            break;
        case 0x14:
            D_global_asm_807FC621 = temp_s0->unk0;
            D_global_asm_807FC622 = temp_s0->unk2;
            if (D_global_asm_807FC622) {
                func_global_asm_807215AC(0x35, 0x18, 0x28);
                func_global_asm_80721560(0x320, 0x82, 0, 0x64, 0x64, 0x64);
                break;
            }
            break;
        case 0x18:
            func_global_asm_80600044(getLevelIndex(current_map, 0U));
            break;
        case 0x1C:
            D_global_asm_8076A0A6 = *newly_pressed_input;
            break;
        case 0x1A:
            character_change_array->playerPointer->PaaD->unk1F0 |= 0x80000000;
            break;
        case 0x1B:
            func_global_asm_80653F68(temp_s0->unk2);
            break;
        }
    }
    if (TaaD->unk1E) {
        TaaD->unk1E--;
        temp = (f32) TaaD->unk1E / (f32) TaaD->unk1C;
        func_global_asm_80659F7C(TaaD->unkC, TaaD->unk10, TaaD->unk14, temp, TaaD->unk1A);
        if (TaaD->unk1E == 0) {
            func_global_asm_80659DB0(TaaD->unkC, TaaD->unk10, TaaD->unk14, TaaD->unk1A);
        }
    }
    switch (TaaD->unk0) {
    case 0x6:
        func_global_asm_80711BD0(TaaD->unk4, TaaD->unk8, TaaD->unk1A, 4);
        break;
    case 0x7:
        func_global_asm_80711BD0(TaaD->unk4, TaaD->unk8, TaaD->unk1A, 5);
        break;
    case 0x5:
        func_global_asm_80711BD0(TaaD->unk4, TaaD->unk8, TaaD->unk1A, 3);
        break;
    case 0x1:
        func_global_asm_80711950(TaaD->unk4, TaaD->unk8, TaaD->unk1A);
        break;
    case 0x4:
        func_global_asm_80711F90(TaaD->unk4, TaaD->unk8, 1.0f, TaaD->unk1A, 4.0f);
        break;
    case 0x3:
        if (RandClamp(50) == 0xF) {
            D_global_asm_807FC620 = 1;
        }
    case 0x2:
        if (TaaD->unk21) {
            TaaD->unk21--;
        }
        if (D_global_asm_807FC620) {
            TaaD->unk18 = 0x28U;
            D_global_asm_807FC620 = 0;
        }
        if (TaaD->unk18) {
            if ((TaaD->unk18 == 0x28) || (RandClamp(10) == 5)) {
                func_global_asm_80659670(1.0f, 1.0f, 1.0f, TaaD->unk1A);
                if ((D_global_asm_80750190 == 0) && (TaaD->unk21 == 0)) {
                    var_s0 = 70;
                    if (current_map == MAP_CASTLE) {
                        var_s0 = 45;
                    }
                    func_global_asm_80608DA8(0x9C, var_s0, 0x7F, 0x1E, (rand() >> 0xF) % 3);
                    if (current_map == MAP_GALLEON_PUFFTOSS) {
                        TaaD->unk21 = 80;
                    } else {
                        TaaD->unk21 = 50;
                    }
                }
                TaaD->unk1E = MAX(TaaD->unk1E, 4);
                TaaD->unk1C = TaaD->unk1E;
            }
            TaaD->unk18--;
        }
        func_global_asm_80711410(TaaD->unk4, TaaD->unk8, 1.0f, TaaD->unk1A, 1.0f);
        break;
    case 0xFF:
        if (func_global_asm_807122B4()) {
            TaaD->unk0 = 0U;
        }
        break;
    }
    func_global_asm_8066466C();
    func_global_asm_80664D20();
    D_global_asm_807FC621 |= 0x80;
}

void func_global_asm_8068B80C(void) {
    D_global_asm_807FC620 = 1;
}

void func_global_asm_8068B81C(void) {
    D_global_asm_807FC621 = 0;
    D_global_asm_807FC622 = 0;
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
    f32 unk4;
    s16 unk8;
} AAD_global_asm_8068B830;

void func_global_asm_8068B830(s16 arg0, s16 arg1, s16 arg2) {
    Actor *sp1C;
    AAD_global_asm_8068B830 *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = (f32)arg1 / 100.0; // TODO: Get rid of this typecast?
    temp_v0->unk8 = arg2;
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s16 unk1C;
    s16 unk1E;
} AAD_global_asm_8068B8A4;

void func_global_asm_8068B8A4(f32 arg0) {
    Actor *sp1C;
    AAD_global_asm_8068B8A4 *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unkC = arg0;
    temp_v0->unk10 = arg0;
    temp_v0->unk14 = arg0;
    if (temp_v0->unk18 == 0) {
        temp_v0->unk1C = 1;
        temp_v0->unk1E = temp_v0->unk1C;
    }
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
} AAD_global_asm_8068B8FC;

void func_global_asm_8068B8FC(void) {
    Actor *sp1C;
    AAD_global_asm_8068B8FC *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = 0xFF;
}

extern u8 D_global_asm_807FBDC4;

void func_global_asm_8068B930(void) {
    Struct807FBB70_unk278 *temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        if (D_global_asm_807FBB70.unk258[i] == 1) {
            func_global_asm_8063DA40(temp_v0->unk0, temp_v0->unk2);
        }
    }
    func_global_asm_8062BAE4();
}

void func_global_asm_8068B9B4(void) {
    Struct807FBB70_unk278 *temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        if (D_global_asm_807FBB70.unk258[i] == 1) {
            func_global_asm_80689A80(temp_v0->unk2, temp_v0);
        }
    }
}

// TODO: Probably overlap with an existing aaD
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC; // Used
} AAD_global_asm_8068BA2C;

void func_global_asm_8068BA2C(void) {
    s16 i;
    AAD_global_asm_8068BA2C *sp58;
    Struct807FBB70_unk278 *temp_v1;
    u8 var_s3;
    s32 var_v0;
    PlayerAdditionalActorData *temp_s1;

    temp_s1 = gCurrentPlayer->PaaD;
    var_s3 = 0;
    sp58 = temp_s1->unk104->additional_actor_data;
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        temp_v1 = D_global_asm_807FBB70.unk278[i];
        switch (D_global_asm_807FBB70.unk258[i]) {
            case 1:
                if (temp_v1->unk2 != 0) {
                    var_v0 = 4;
                } else {
                    var_v0 = 0;
                }
                playCutscene(NULL, temp_v1->unk0, var_v0 | 1);
                break;
            case 2:
                func_global_asm_8072167C(temp_v1->unk0, temp_v1->unk2, temp_v1->unk4, temp_v1->unk6);
                break;
            case 3:
                var_s3 = 1;
                if (!(temp_s1->unk1F0 & 0x04000000)) {
                    temp_s1->unk1F0 |= 0x04000000;
                }
                break;
        }
    }
    if (var_s3 == 0) {
        temp_s1->unk1F0 &= ~0x04000000;
    }
    if (sp58->unkAC & 1) {
        createLight(character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z, character_change_array->look_at_at_x, character_change_array->look_at_at_y, character_change_array->look_at_at_z, 0.0f, 1, 0xFF, 0xFF, 0xFF);
    }
}

// Jumptable, Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068BBF8.s")

void func_global_asm_8061DBD4(Actor *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
extern s16 D_807FC624;

/*
void func_global_asm_8068BBF8(void) {
    CameraPaad *CaaD;
    s16 sp52;
    s16 sp50;
    s16 temp_v1_3;
    s16 temp_v0;
    f32 sp48;
    f32 var_f2;
    f32 sp40;
    f32 sp3C;
    s16 sp3A;
    CharacterChange *cc;
    s32 var_v1;
    s32 var_v1_2;

    CaaD = gCurrentActorPointer->AAD_as_array[0];
    temp_v1_3 = 0;
    sp3A = 0x1E;
    sp40 = 0.08f;
    sp3C = 8.0f;
    cc = &character_change_array[CaaD->unkFB];
    cc->unk2CC = gCurrentActorPointer->unkEC;
    gCurrentActorPointer->unkEC = gCurrentActorPointer->x_rotation;
    cc->unk2CA = cc->look_at_eye_y;
    sp48 = func_global_asm_80665E48(cc->look_at_eye_z, cc->look_at_eye_x, cc->look_at_at_z, cc->look_at_at_x);
    var_f2 = func_global_asm_80665E48(0.0f, cc->look_at_eye_y, sqrtf(SQ(cc->look_at_at_z - cc->look_at_eye_z) + SQ(cc->look_at_at_x - cc->look_at_eye_x)), cc->look_at_at_y) + MATH_PI_F;
    if (var_f2 > MATH_2PI_F) {
        var_f2 -= MATH_2PI_F;
    }
    if (var_f2 > MATH_PI_F) {
        var_f2 = MATH_PI_F - (var_f2 - MATH_PI_F);
    }
    cc->unk2D4 = MATH_2PI_F - sp48;
    cc->unk2D8 = MATH_2PI_F - var_f2;
    func_global_asm_806C9D20(CaaD->unkFB);
    sp52 = func_global_asm_80665DE0(cc->look_at_eye_x, cc->look_at_eye_z, cc->look_at_at_x, cc->look_at_at_z);
    func_global_asm_8061DBD4(gCurrentActorPointer,
        &cc->look_at_eye_x, &cc->look_at_eye_y, &cc->look_at_eye_z,
        &cc->look_at_at_x, &cc->look_at_at_y, &cc->look_at_at_z,
        &cc->look_at_up_x, &cc->look_at_up_y, &cc->look_at_up_z);
    temp_v0 = func_global_asm_80665DE0(cc->look_at_eye_x, cc->look_at_eye_z, cc->look_at_at_x, cc->look_at_at_z);
    if (gPlayerPointer == CaaD->unk0) {
        if ((current_map == MAP_GALLEON_KROOLS_SHIP) || (current_map == MAP_GALLEON_MECHANICAL_FISH)) {
            gCurrentActorPointer->x_rotation = func_global_asm_80612794(D_807FC624) * 100.0f;
            if (current_map == MAP_GALLEON_KROOLS_SHIP) {
                if (D_807FC624 < 0x1E) {
                    playSound(0x15, 0x7FFFU, 64.0f, 1.0f, 0xA, 0x80);
                }
                if ((D_807FC624 > 0x801) && (D_807FC624 < 0x81E)) {
                    playSound(0x14, 0x7FFFU, 64.0f, 1.0f, 0xA, 0x80);
                }
            }
            D_807FC624 = D_807FC624 + 0x1E & 0xFFF;
            return;
        }
        if (is_cutscene_active != 1) {
            switch (CaaD->unk0->control_state) {
            case 0x63:
                sp40 = 0.02f;
                sp3C = 15.0f;
                goto block_29;
            case 0x7:
            case 0x8:
            case 0x9:
            case 0xA:
            case 0xB:
            case 0xF:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
                sp3A = 0x64;
                sp40 = 0.1f;
            case 0x4F:
            case 0x69:
            case 0x6D:
block_29:
                temp_v1_3 = sp52 - temp_v0;
                if (temp_v1_3 > 0x800) {
                    temp_v1_3 -= 0x1000;
                } else if (temp_v1_3 < -0x800) {
                    temp_v1_3 += 0x1000;
                }
                break;
            }
            var_v1 = MAX(-sp3A, temp_v1_3);
            var_v1_2 = sp3A;
            if (var_v1 < sp3A) {
                var_v1_2 = MAX(temp_v1_3, var_v1);
            }
            gCurrentActorPointer->x_rotation = ((((var_v1_2 * sp3C) - gCurrentActorPointer->x_rotation) * sp40) + gCurrentActorPointer->x_rotation);
        }
    }
}
*/

typedef struct {
    void *texturePointer; // Texture Pointer (from table 0xE)
    u16 textureIndex; // Texture Index
    u8 unk6;
    u8 unk7;
} Struct807FC690;

extern Struct807FC690 D_global_asm_807FC690[];

void func_global_asm_8068C080(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        D_global_asm_807FC690[i].unk6 = 0;
    }
}

void func_global_asm_8068C0B4(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FC690[i].unk6 != 0) {
            D_global_asm_807FC690[i].unk6--;
            if (D_global_asm_807FC690[i].unk6 == 0) {
                func_global_asm_8066B434(D_global_asm_807FC690[i].texturePointer, 0x6A, 0x46);
            }
        }
    }
}

// Returns a texture pointer for a given texture index
void *func_global_asm_8068C12C(u16 textureIndex) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if ((textureIndex == D_global_asm_807FC690[i].textureIndex) && (D_global_asm_807FC690[i].unk6 != 0)) {
            D_global_asm_807FC690[i].unk6 = 2;
            return D_global_asm_807FC690[i].texturePointer;
        }
    }
    
    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FC690[i].unk6 == 0) {
            D_global_asm_807FC690[i].texturePointer = getPointerTableFile(TABLE_14_TEXTURES_HUD, textureIndex, 0, 0);
            D_global_asm_807FC690[i].unk6 = 2;
            D_global_asm_807FC690[i].textureIndex = textureIndex;
            return D_global_asm_807FC690[i].texturePointer;
        }
    }

    D_global_asm_807FC690[0].unk6 = 2;
    return D_global_asm_807FC690[0].texturePointer;
}

typedef struct {
    Gfx *(*unk0)(Gfx*, Actor*); // Used
    Actor *unk4; // Used
    u8 unk8; // Used
    s8 unk9;
    s8 unkA;
    s8 unkB;
} TempCBig;

extern TempCBig D_global_asm_807FC630[];

// Displaylist stuff, uses TempCBig, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068C20C.s")

/*
Gfx *func_global_asm_8068C20C(Gfx *dl, u8 arg1) {
    s32 j;
    u8 i;

    i = D_global_asm_807501E0;

    while (i) {
        j = i - 1;
        i = j;
        if (arg1 == D_global_asm_807FC630[j].unk8) {
            gDPPipeSync(dl++);
            dl = D_global_asm_807FC630[i].unk0(dl, D_global_asm_807FC630[i].unk4);
        }
    }

    if (arg1 == 7) {
        D_global_asm_807501E0 = 0;
    }
    return dl;
}
*/

void func_global_asm_8068C2EC(void) {
    D_global_asm_807501E0 = 0;
}

void func_global_asm_8068C2F8(Actor *arg0) {
    u8 i;
    for (i = 0; i < D_global_asm_807501E0; i++) {
        if (arg0 == D_global_asm_807FC630[i].unk4) {
            D_global_asm_807FC630[i].unk8 = 8;
        }
    }
}

// TODO: Arg0 is a function pointer of signature: Gfx* func(Gfx *dl, Actor *arg1);
void addActorToTextOverlayRenderArray(void *arg0, Actor *arg1, u8 arg2) {
    if (D_global_asm_807501E0 < 8) {
        D_global_asm_807FC630[D_global_asm_807501E0].unk0 = arg0;
        D_global_asm_807FC630[D_global_asm_807501E0].unk4 = arg1;
        D_global_asm_807FC630[D_global_asm_807501E0].unk8 = arg2;
        D_global_asm_807501E0++;
    }
}
