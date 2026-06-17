#include "common.h"

extern s8 D_global_asm_80745844;
extern s8 opening_cutscene_transition;
extern s8 D_global_asm_80745844;
extern s8 inputs_enabled_timer;
extern s8 is_in_submenu;
extern s8 is_night;
extern s8 is_raining;
extern s8 menu_cutscene_index;
extern s16 menu_cutscene_timer;
extern s16 D_menu_800336A4[];
extern s8 current_file_selection;
extern s8 menu_selection_available;

// Rodata
// const char D_menu_80033B30[] = "%s";
// const char D_menu_80033B34[] = "%s";
// const char D_menu_80033B38[] = "%s %d";
// const char D_menu_80033B40[] = "%d%%"; // Not yet matched
// const char D_menu_80033B48[] = "%03d"; // Not yet matched
// const char D_menu_80033B50[] = "%03d:%02d"; // Not yet matched
// const char D_menu_80033B5C[] = "%s %d"; // Not yet matched
// const char D_menu_80033B64[] = "%s";
// const char D_menu_80033B68[] = "%s %d";
// const char D_menu_80033B70[] = "%s"; // Not yet matched
// const char D_menu_80033B74[] = "%s %d"; // Not yet matched
// const char D_menu_80033B7C[] = "%s %d"; // Not yet matched
// const char D_menu_80033B84[] = "%d %s"; // Not yet matched
// const char D_menu_80033B8C[] = "%d %s"; // Not yet matched
// const char D_menu_80033B94[] = "%d %s"; // Not yet matched
// const char D_menu_80033B9C[] = "%d %s"; // Not yet matched
// const char D_menu_80033BA4[] = "%d %s"; // Not yet matched
// const char D_menu_80033BAC[] = "%d %s"; // Not yet matched
// const char D_menu_80033BB4[] = "%d"; // Not yet matched
// const char D_menu_80033BB8[] = "P %d"; // Not yet matched
// const char D_menu_80033BC0[] = "%d"; // Not yet matched
// const char D_menu_80033BC4[] = "%d"; // Not yet matched
// const char D_menu_80033BC8[] = "%d"; // Not yet matched
// const char D_menu_80033BCC[] = "%s:%s"; // Not yet matched
// const char D_menu_80033BD4[] = "%s:%s"; // Not yet matched
// const char D_menu_80033BDC[] = "???"; // Not yet matched
// const char D_menu_80033BF0[] = "%s"; // Not yet matched
// const char D_menu_80033BF4[] = "%s %d."; // Not yet matched
// const char D_menu_80033BFC[] = "%d."; // Not yet matched
// const char D_menu_80033C00[] = "%c %c %c"; // Not yet matched
// const char D_menu_80033C0C[] = "%d"; // Not yet matched
// const f64 D_menu_80033C10 = 0.005;
// const f64 D_menu_80033C18 = 0.005;
// const f32 D_menu_80033C20 = 0.45f;
// const f64 D_menu_80033C28 = 0.01;
// const f64 D_menu_80033C30 = 0.83;
// const f64 D_menu_80033C38 = 0.17;
// const f64 D_menu_80033C40 = 0.8;
// const f64 D_menu_80033C48 = 0.2;
// const f64 D_menu_80033C50 = 0.6;
// const f64 D_menu_80033C58 = 0.4;
// const f32 text_transition_speed = 0.3f;
// const f32 text_label_scale = 0.7f;
// const f32 adventure_barrel_scale = 1.2f;
// const f32 options_barrel_scale = 1.2f;
// const f32 mystery_barrel_scale = 1.2f;
// const f32 battle_barrel_scale = 1.2f;
// const f32 sound_barrel_scale = 1.2f;
// const f32 adventure_icon_scale = 0.6f;
// const f32 options_icon_scale = 0.8f;
// const f32 mystery_icon_scale = 0.8f;
// const f32 battle_icon_scale = 0.6f;
// const f32 sound_icon_scale = 0.6f;
// const f32 D_menu_80033C90 = 0.3f;
// const f64 D_menu_80033C98 = 0.85;
// const f32 D_menu_80033CA0 = 0.1f;
// const f32 D_menu_80033CA4 = 0.3f;
// const f32 D_menu_80033CA8 = 0.6f;
// const f32 D_menu_80033CAC = 0.8f;
// const f32 D_menu_80033CB0 = 0.45f;
// const f32 D_menu_80033CB4 = 0.45f;
// const f32 D_menu_80033CB8 = 0.7f;
// const f64 D_menu_80033CC0 = -239.0;
// const f32 D_menu_80033CC8 = 1.8f;
// const f32 D_menu_80033CCC = 1.8f;
// const f32 D_menu_80033CD0 = 1.8f;
// const f32 D_menu_80033CD4 = 0.6f;
// const f32 D_menu_80033CD8 = -479.0f;
// const f32 D_menu_80033CDC = 0.8f;
// const f32 D_menu_80033CE0 = 0.8f;
// const f32 D_menu_80033CE4 = 0.8f;
// const f32 D_menu_80033CE8 = 1.8f;
// const f32 D_menu_80033CEC = 1.8f;
// const f32 D_menu_80033CF0 = 0.6f;
// const f32 D_menu_80033CF4 = 0.6f;
// const f32 D_menu_80033CF8 = 1.8f;
// const f32 D_menu_80033CFC = 1.8f;
// const f64 D_menu_80033D00 = 0.78;
// const f32 D_menu_80033D44 = 13.1f;
// const f64 D_menu_80033D48 = 1.333;
// const f32 D_menu_80033D50 = 0.13f;
// const f32 D_menu_80033D54 = 1.3f;
// const f32 D_menu_80033D58 = 0.2f;
// const f32 menu_rotation_speed_left = -0.1f;
// const f32 menu_rotation_speed_right = 0.1f;
// const f64 D_menu_80033D80 = 0.8;
// const f32 D_menu_80033E0C = 3.141f;
// const f32 D_menu_80033E10 = 0.3f;
// const f32 D_menu_80033E14 = -0.3f;
// const f64 D_menu_80033E68 = 360.0;
// const f64 D_menu_80033E70 = 0.9;
// const f32 D_menu_80033E78 = 1365.0f;
// const f32 D_menu_80033E7C = 1.1f;
// const f32 D_menu_80033E80 = 0.825f;
// const f32 D_menu_80033E84 = 6.2f;
// const f32 D_menu_80033EC0 = 0.1f;
// const f32 D_menu_80033EC4 = 13.1f;
// const f64 D_menu_80033EC8 = 0.1;
// const f32 D_menu_80033ED0 = 10020.0f;
// const f32 DK_barrel_scale = 0.14f;
// const f64 D_menu_80033ED8 = 0.2;
// const f64 D_menu_80033EE0 = 0.4;

extern f32 foreground_shading_intensity;
extern s8 D_menu_80033F38;
extern s8 D_menu_80033F50;
extern f32 day_night_transition;
extern f32 menu_rotation_speed;
extern f32 menu_icon_transition_scale;
extern f32 menu_selection_speed;

void func_menu_80030894(MenuAdditionalActorData*,void*,s32,s32,f32,u8,s32); // Param 1 is ActorAdditionalData

void func_menu_80027E10(void) {
    s32 phi_a0 = 1;
    switch (D_global_asm_80745844) {
        case 0:
            phi_a0 = 2;
            break;
        case 2:
            phi_a0 = 4;
            break;
    }
    func_global_asm_80737C20(phi_a0);
}

void func_menu_80027E60(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s32 phi_v1 = FALSE;

    if (opening_cutscene_transition != 0) {
        opening_cutscene_transition++;
        if (opening_cutscene_transition >= 0xB) {
            phi_v1 = TRUE;
        }
    }
    if ((MaaD->unk0 == 0.0) && (phi_v1 || arg1 & 1)) {
        MaaD->unk12 = 1;
        MaaD->unk16 = -1;
        MaaD->unk0 = 1.0f;
        func_menu_80030340(arg0, 0, NULL, 0);
        func_global_asm_8061D4E4(D_global_asm_807F5D10);
        playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        opening_cutscene_transition = 0;
    }
}

Gfx *func_menu_80027F34(Actor *arg0, Gfx *dl) {
    return dl;
}

void func_menu_80027F40(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    gPlayerPointer->x_position = 109.0f;
    gPlayerPointer->y_position = 6.0f;
    gPlayerPointer->z_position = 55.0f;
    MaaD->unk0 = 0.0f;
    opening_cutscene_transition = 0;
    global_properties_bitfield |= 0x10000;
}

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct800337FC;

extern s16 D_menu_800336A0;
extern s16 D_menu_80033724[];
extern Struct800337FC D_menu_800337FC;

void func_menu_8002FC1C(Actor*, MenuAdditionalActorData*, s32);
void func_menu_8002FD38(MenuAdditionalActorData*, s32, s32);
void func_menu_8002FE08(MenuAdditionalActorData*, s32);

void func_menu_80027FAC(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD; // sp5C
    Struct800337FC sp54; // sp54
    Actor *sp50;
    s8 sp4F; // sp4F
    f32 var_f16;
    s32 var_v0_2;
    s16 temp;
    s16 i;
    s16 initialMax;
    s16 max;

    MaaD = arg0->additional_actor_data;
    sp54 = D_menu_800337FC;
    sp4F = 0;
    if (inputs_enabled_timer > 0) {
        inputs_enabled_timer--;
    } else {
        inputs_enabled_timer = 0;
    }
    menu_selection_available = 0;
    if (MaaD->unk0 == 0.0f) {
        if (menu_icon_transition_scale == 0.0f) {
            if (inputs_enabled_timer == 0) {
                if (MaaD->unk4 == 0.0f) {
                    menu_selection_available = 1;
                    switch (MaaD->unk17) {
                        case 2:
                            if (!isFlagSet(GLOBALFLAG_MULTIPLAYER_MENU, FLAG_TYPE_GLOBAL)) {
                                menu_selection_available = -1;
                            }
                            break;
                        case 3:
                            if (!isFlagSet(GLOBALFLAG_MYSTERY_MENU, FLAG_TYPE_GLOBAL)) {
                                menu_selection_available = -1;
                            }
                            break;
                    }
                    func_menu_8002FD38(MaaD, 5, arg1);
                }
                func_menu_8002FE08(MaaD, 5);
            }
        }
    }
    current_file_selection = 0;
    if (menu_selection_speed != 0.0f) {
        menu_icon_transition_scale += menu_selection_speed;
        if (menu_icon_transition_scale > 1) {
            menu_icon_transition_scale = 1;
            MaaD->unk16 = 0;
            switch (MaaD->unk17) {
                default:
                    MaaD->unk13 = 2;
                    break;
                case 1:
                    MaaD->unk13 = 8;
                    break;
                case 2:
                    MaaD->unk13 = 6;
                    break;
                case 3:
                    MaaD->unk13 = 0xA;
                    break;
                case 4:
                    MaaD->unk13 = 9;
                    break;
            }
            if (func_global_asm_8061CB50()) {
                func_global_asm_8061D4E4(D_global_asm_807F5D10);
            }
            func_global_asm_80726E60(0x40, 0x3C);
            if (is_raining) {
                sp4F = -1;
            }
            is_night = 0;
        }
    }
    func_menu_8002FC1C(arg0, MaaD, 0);
    menu_cutscene_timer--;
    if (menu_cutscene_timer <= 0) {
        switch (D_menu_800336A4[menu_cutscene_index]) {
            case -2:
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index + 1];
                menu_cutscene_index += 2;
                sp4F = 1;
                break;
            case -3:
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index + 1];
                menu_cutscene_index += 2;
                sp4F = -1;
                break;
            case -4:
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index + 1];
                menu_cutscene_index += 2;
                is_night = 1;
                break;
            case -5:
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index + 1];
                menu_cutscene_index += 2;
                is_night = 0;
                break;
            default:
                if (D_menu_800336A4[menu_cutscene_index] < -5) {
                    temp = -6 - D_menu_800336A4[menu_cutscene_index];
                    if (inputs_enabled_timer == 0) {
                        playActorAnimation(gPlayerPointer, D_menu_80033724[temp]);
                    }
                    menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index + 1];
                    menu_cutscene_index += 2;
                } else if (D_menu_800336A4[menu_cutscene_index] >= 0) {
                    playCutscene(NULL, D_menu_800336A4[menu_cutscene_index], 1);
                    menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index + 1];
                    menu_cutscene_index += 2;
                } else {
                    i = 0;
                    max = func_global_asm_806119FC() * 10.0f;
                    menu_cutscene_timer = (func_global_asm_806119A0() & 0x7F) + 300;
                    menu_cutscene_index = 0;
                    if (max >= 0xB) {
                        max = 0;
                    }
                    initialMax = max;
                    while (D_menu_800336A0 & (1 << max)) {
                        max++;
                        if (max == 0xB) {
                            max = 0;
                        }
                        if (max == initialMax) {
                            D_menu_800336A0 = 0;
                        }
                    }
                    D_menu_800336A0 |= (1 << max);
                    while (i != max) {
                        while (D_menu_800336A4[menu_cutscene_index] != -1) {
                            menu_cutscene_index++;
                        }
                        menu_cutscene_index++;
                        i++;
                    }
                }
                break;
        }
    }
    if (sp4F) {
        func_global_asm_8072E7DC(0xC, &sp50);
        if (sp4F < 0) {
            is_raining = 0;
            var_v0_2 = 2;
        } else {
            is_raining = 1;
            var_v0_2 = 1;
        }
        func_global_asm_8067AB20(D_global_asm_807F5D10, sp50, 0x01000000, var_v0_2, &sp54, 0);
    }
    if (is_night) {
        var_f16 = 0.0f;
        day_night_transition = day_night_transition + 0.005;
        if (day_night_transition > 1.0) {
            day_night_transition = 1.0f;
        }
    } else {
        var_f16 = 1.0f;
        if (day_night_transition > 0.0) {
            day_night_transition -= 0.005;
        } else if (is_raining) {
            var_f16 = 0.45f;
        }
    }
    foreground_shading_intensity += ((var_f16 - foreground_shading_intensity) * 0.01);
    func_global_asm_80659670((foreground_shading_intensity * 0.83) + 0.17, (foreground_shading_intensity * 0.8) + 0.2, (foreground_shading_intensity * 0.6) + 0.4, -1);
    func_global_asm_80708574(day_night_transition);
}

extern char **label_string_pointer_array;

typedef struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    s8 unk17;
} Struct800317E8;

s32 func_menu_800317E8(Struct800317E8 *arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, s32 arg5, s8 arg6, f32 arg7);

Gfx *func_menu_800286C8(Actor *arg0, Gfx *dl) {
    s32 pad2;
    s32 spD0;
    s32 pad;
    void *aaD = arg0->additional_actor_data;
    f32 spC4;
    f32 spC0;
    s32 pad3;
    f32 sp7C[4][4];
    f32 sp3C[4][4];
    Mtx *sp38;

    global_properties_bitfield |= 0x10;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    spD0 = func_menu_800317E8(aaD, 160.0f, 20.0f, &spC4, &spC0, 5, 1, 0.3f);
    sp38 = malloc(sizeof(Mtx));
    func_global_asm_8061134C(sp38);
    guScaleF(sp7C, 0.7f, 0.7f, 1.0f);
    guTranslateF(sp3C, spC4 * 4.0, spC0 * 4.0, 0);
    guMtxCatF(sp7C, sp3C, sp7C);
    guMtxF2L(sp7C, sp38);
    gSPMatrix(dl++, sp38, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return printStyledText(dl, 1, 0, 0, label_string_pointer_array[spD0], 0x80);
}

extern s8 D_8076A0D0[];

void func_menu_80028834(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD;

    MaaD = arg0->MaaD;
    is_in_submenu = 0;
    inputs_enabled_timer = 0;
    gPlayerPointer->control_state = 0x85;
    gPlayerPointer->control_state_progress = 0;
    D_global_asm_80745844 = func_global_asm_8060C6B8(0x1E, 0, 0, 0);
    func_menu_80027E10();
    MaaD->unk17 = D_8076A0D0[1];
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 160, 210, 0.75f, 2, 0);
    func_menu_80030894(MaaD, (s32)&D_global_asm_80721444, 0,   0,   1.2f, 2, 0x12);
    func_menu_80030894(MaaD, (s32)&D_global_asm_80721444, 1,   0,   1.2f, 2, 0x12);
    func_menu_80030894(MaaD, (s32)&D_global_asm_80721444, 2,   0,   1.2f, 2, 0x12);
    func_menu_80030894(MaaD, (s32)&D_global_asm_80721444, 3,   0,   1.2f, 2, 0x12);
    func_menu_80030894(MaaD, (s32)&D_global_asm_80721444, 4,   0,   1.2f, 2, 0x12);
    func_menu_80030894(MaaD, &D_global_asm_8072052C, 0,   0,   0.6f, 2, 6);
    func_menu_80030894(MaaD, &D_global_asm_807211D0, 1,   0,   0.8f, 2, 6);
    // Is the mystery menu not unlocked?
    if (!isFlagSet(GLOBALFLAG_MYSTERY_MENU, FLAG_TYPE_GLOBAL)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_80721094, 2, 0, 0.8f, 2, 7);
    // Is the multiplayer menu not unlocked?
    if (!isFlagSet(GLOBALFLAG_MULTIPLAYER_MENU, FLAG_TYPE_GLOBAL)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_807210EC, 3, 0, 0.6f, 2, 6);
    func_menu_80030894(MaaD, &D_global_asm_80721170, 4, 0, 0.6f, 2, 6);
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    gPlayerPointer->x_position = 700.0f;
    gPlayerPointer->y_position = 100.0f;
    gPlayerPointer->z_position = 70.0f;
    menu_cutscene_index = 0;
    while (D_menu_800336A4[menu_cutscene_index] != -1) {
        menu_cutscene_index++;
    }
    menu_cutscene_timer = 0x1E;
    is_raining = 0;
    is_night = 0;
    day_night_transition = 0.0f;
    foreground_shading_intensity = 1.0f;
    global_properties_bitfield &= 0xFFFEFFFF;
}

void func_menu_80028C18(void) {

}

extern s8 D_menu_80033F48;

void func_menu_80028C20(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD;
    s32 three = 3;

    MaaD = arg0->MaaD;
    if (MaaD->unk0 == 0.0f) {
        if (MaaD->unk4 == 0.0f) {
            if (arg1 & 1) {
                MaaD->unk16 = 0;
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                if (MaaD->unk17 == 2) {
                    MaaD->unk13 = 4;
                } else {
                    D_menu_80033F48 = MaaD->unk17;
                    if (D_menu_80033F48 == three) {
                        D_menu_80033F48 = 2;
                    }
                    MaaD->unk13 = three;
                }
            } else if (arg1 & 2) {
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 1;
            } else {
                func_menu_8002FD38(MaaD, 4, arg1);
            }
        }
        func_menu_8002FE08(MaaD, 4);
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
}

Gfx *func_menu_80028D3C(Actor *arg0, Gfx *dl) {
    s32 pad;
    s32 sp100;
    f32 spFC;
    f32 spF8;
    f32 temp3[4][4];
    f32 temp2[4][4];
    f32 temp[4][4];
    void *aaD = arg0->additional_actor_data;
    s32 pad2;
    char sp2C[4]; // TODO: How big?

    global_properties_bitfield &= ~0x10;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    sp100 = func_menu_800317E8(aaD, 160.0f, 15.0f, &spFC, &spF8, 4, 1, 0.3f);
    if (sp100 == 2) {
        _sprintf(sp2C, "%s", label_string_pointer_array[5]);
    } else {
        if (sp100 == 3) {
            sp100 = 2;
        }
        if (func_menu_800322D0(sp100) != 0) {
            _sprintf(sp2C, "%s", label_string_pointer_array[6]);
        } else {
            _sprintf(sp2C, "%s %d", label_string_pointer_array[7], sp100 + 1);
        }
    }
    return printText(dl, spFC * 4.0f, spF8 * 4.0f, 0.6f, sp2C);
}

void func_menu_80028EA8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData* MaaD;

    MaaD = arg0->MaaD;
    MaaD->unk17 = current_file_selection;
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0x78, 0.75f, 2, 4);
    if (func_menu_800322D0(0)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, (s32)&D_global_asm_8072052C, 0, 0, 1.0f, 2, 2);
    if (func_menu_800322D0(1)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, (s32)&D_global_asm_8072052C, 1, 0, 1.0f, 2, 2);
    if (func_menu_800322D0(2)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, (s32)&D_global_asm_8072052C, 3, 0, 1.0f, 2, 2);
    func_menu_80030894(MaaD, &D_global_asm_807204BC, 2, 0, 1.0f, 2, 2);
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
}

extern u8 D_menu_80033818; // Current input index
extern u16 D_menu_8003381C[] ;//= {U_JPAD, L_JPAD, U_JPAD, D_JPAD, R_JPAD, D_JPAD, Z_TRIG}; // Required input sequence
extern s8 gCrashDebuggerEnabled; // Enable stack trace upon crash

// Button code on controller to enable stack trace upon crash
// Accessible from the sound menu
void func_menu_8002907C(void) {
    if (D_menu_8003381C[D_menu_80033818] == *(u16*)(&newly_pressed_input[0])) {
        D_menu_80033818 = D_menu_80033818 + 1;
        if (D_menu_80033818 > 6U) {
            gCrashDebuggerEnabled = TRUE;
            playSound(0x23C, 0x7FFF, 63.0f, 1.0f, 0, 0);
            D_menu_80033818 = 0;
        }
    } else {
        if (newly_pressed_input[0] != 0) {
            D_menu_80033818 = 0;
        }
    }
}

void func_menu_8002FC1C(Actor *, MenuAdditionalActorData *, s32);
void func_global_asm_8060AA58(u8);

void func_menu_80029114(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    if ((MaaD->unk0 == 0.0f) && (MaaD->unk4 == 0.0f)) {
        if (arg1 & 1) {
            func_global_asm_8060AA58(1);
            func_global_asm_807144B8(D_menu_80033F48);
        } else if ((arg1 & 2) != 0) {
            playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
            MaaD->unk16 = 0;
            MaaD->unk13 = 2;
        }
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_800291CC.s")

extern s8 D_menu_80033804[];
extern s32 D_menu_8003380C;
extern s32 D_menu_80033810;
extern s32 D_menu_80033814;
extern f32 D_menu_80033F4C;
extern s8 D_menu_80033F51;
extern s32 func_menu_8002FB88(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4);

/*
Gfx *func_menu_800291CC(Actor *arg0, Gfx *dl) {
    f32 spD0;
    f32 spCC;
    s8 spA4;
    MenuAdditionalActorData *MaaD;
    f32 temp_f20;
    s16 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f2;
    f32 var_f20;
    s16 temp_s0;
    s32 i;
    s16 temp_s0_2;

    var_f20 = 66.0f;
    MaaD = arg0->MaaD;
    for (i = 0; i < 5; i++) {
        func_menu_800317E8(MaaD, var_f20, 85.0f, &spD0, &spCC, 4, 0, 1.5f);
        if (D_menu_80033804[i]) {
            dl = func_menu_8002FB88(dl, i, spD0, spCC, 3.0f * 0.85);
        } else {
            dl = func_menu_8002FB88(dl, i | 0x80, spD0, spCC, 3.0f);
        }
        var_f20 += 55.0f;
    }
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_menu_800317E8(MaaD, 160.0f, 180.0f, &spD0, &spCC, 5, 1, 2.0f);
    D_menu_80033F4C = spCC * 4.0f;
    temp_s0 = (s32) D_menu_80033F4C - 0x140;
    _sprintf(&spA4, "%d%%", D_menu_80033F51);
    dl = printStyledText(dl, 1, 0x280, temp_s0, &spA4, 0x81U);
    temp_s0 += 0x8C;
    _sprintf(&spA4, "%03d", D_menu_8003380C);
    dl = printStyledText(dl, 1, 0x280, temp_s0, &spA4, 0x81U);
    temp_s0 += 0x8C;
    _sprintf(&spA4, "%03d:%02d", D_menu_80033810, D_menu_80033814);
    dl = printStyledText(dl, 1, 0x280, temp_s0, &spA4, 0x81U);
    temp_f2 = func_global_asm_80612794((object_timer * 0x78) & 0xFFF);
    temp_f2 = (temp_f2 * 0.1f) + 0.5f;
    temp_f22 = temp_s0 + 40.0f;
    spD0 = 85.0f * 4.0f;
    temp_f20 = 0.5f * 4.0f;
    spCC = ((temp_f22 * 0.25f) + (32.0f * temp_f2)) * 4.0f;
    dl = displayImage(dl, 0xA1U, 3, 0, 0x40, 0x40, spD0, spCC, temp_f20, -(temp_f2 * 4.0f), 0, 0.0f);
    gDPPipeSync(dl++);
    spCC = temp_f22;
    temp_f20 = temp_f20 * 0.75f;
    temp_f24 = -temp_f20;
    spD0 = 340.0f;
    dl = displayImage(dl, 0xA0U, 3, 0, 0x20, 0x20, 340.0f, spCC, temp_f20, temp_f24 * 0.5f, object_timer % 360U, 0.0f);
    gDPPipeSync(dl++);
    dl = displayImage(dl, 0xA0U, 3, 0, 0x20, 0x20, spD0, spCC, temp_f20, temp_f24, (object_timer * 0xC) % 360U, 0.0f);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_menu_800317E8(MaaD, 160.0f, 15.0f, &spD0, &spCC, 5, 1, 0.3f);
    _sprintf(&spA4, "%s %d", label_string_pointer_array[7], D_menu_80033F48 + 1);
    return printText(dl, spD0 * 4.0f, spCC * 4.0f, 0.6f, &spA4);
}
*/

#define INSTRUCTION_OBSFUSCATE 0x1EFF0

s32 func_menu_800297A8(s32 arg0) {
    return arg0 + INSTRUCTION_OBSFUSCATE;
}

// Suspect, CRC, polymorphic code? Tamper protection?
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_800297B8.s")

extern void *D_global_asm_80750518[];
extern s16 D_global_asm_807505B0[];
extern u32 D_global_asm_80750AB0;
extern s32 func_global_asm_80671880;

/*
void func_menu_800297B8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD;
    CharacterProgress *var_s4;
    SpriteData *var_a1;
    s32 k;
    s32 j;
    s32 i;
    u32 sp64;
    s16 *kong_flags;
    u8 temp;

    MaaD = arg0->MaaD;
    var_s4 = &D_global_asm_807FC950[0].character_progress[0];
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2U, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2U, 0);
    func_menu_80030894(MaaD, &D_global_asm_8072052C, 0x76, 0x91, 0.6f, 2U, 9);
    D_menu_80033F4C = 1600.0f;
    func_global_asm_8060DC3C(D_menu_80033F48, 0);
    D_menu_80033804[0] = 1;
    kong_flags = &D_global_asm_807505B0[2];
    for (i = 1; i < 5; i++) {
        temp = isFlagSet(kong_flags[-1], 0U);
        kong_flags++;
        D_menu_80033804[i] = temp;
    }
    for (i = 0; i < 5; i++) {
        var_a1 = D_menu_80033804[i] ? D_global_asm_80750518[i] : &D_global_asm_807211D0;
        func_menu_80030894(MaaD, var_a1, i, i, 0.8f, 2U, 0xF);
    }
    osPiReadIo(func_menu_800297A8(0xB0000454 - INSTRUCTION_OBSFUSCATE), &sp64);
    if (func_menu_800297A8(0x0109082B - INSTRUCTION_OBSFUSCATE) != sp64) {
        func_global_asm_80671880 = 0x03E00008;
    }
    D_menu_8003380C = 0;
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 8; k++) {
            D_menu_8003380C += var_s4->golden_bananas[k];
        }
        var_s4++;
    }
    D_menu_80033814 = D_global_asm_80750AB0 / 60;
    D_menu_80033810 = (s32) D_menu_80033814 / 60;
    D_menu_80033814 -= (D_menu_80033810 * 60);
    D_menu_80033F51 = func_menu_80032304();
}
*/


void func_menu_80029AAC(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    if (MaaD->unk0 == 0.0f) {
        if (MaaD->unk4 == 0.0f) {
            if ((arg1 & 1) != 0) {
                if (func_menu_800322D0(MaaD->unk17) == 0) {
                    MaaD->unk16 = 0;
                    MaaD->unk13 = 5;
                    D_menu_80033F48 = MaaD->unk17;
                } else {
                    playSound(0x98, 0x7FFF, 63.0f, 1.0f, 0, 0);
                }
            } else if ((arg1 & 2) != 0) {
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 2;
            } else {
                func_menu_8002FD38(MaaD, 3, arg1);
            }
        }
        func_menu_8002FE08(MaaD, 3);
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
}

Gfx *func_menu_80029BB4(Actor *arg0, Gfx *dl) {
    s32 pad124;
    s32 fileIndex;
    s32 pad11C;
    s32 pad118;
    s32 pad114;
    f32 sp110;
    f32 sp10C;
    s16 sp100;
    s32 padFC;
    s32 padF8;
    s16 spFE;
    f32 temp3[4][4];
    f32 temp2[4][4];
    f32 temp[4][4];
    void *aaD = arg0->additional_actor_data;
    char sp34[4];

    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    fileIndex = func_menu_800317E8(aaD, 160.0f, 25.0f, &sp110, &sp10C, 3, 1, 0.45f);
    spFE = sp110 * 4.0f;
    sp100 = sp10C * 4.0f;
    if (func_menu_800322D0(fileIndex)) {
        _sprintf(sp34, "%s", label_string_pointer_array[6]);
    } else {
        _sprintf(sp34, "%s %d", label_string_pointer_array[7], fileIndex + 1);
    }
    dl = printText(dl, spFE, sp100, 0.6f, sp34);
    sp100 -= 0x3C;
    return printText(dl, sp110 * 4.0f, sp100, 0.6f, label_string_pointer_array[8]);
}

void func_menu_80029D30(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s32 temp;

    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    if (func_menu_800322D0(0)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, (s32)&D_global_asm_8072052C, 0, 0, 1.0f, 2, 3);
    if (func_menu_800322D0(1)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, (s32)&D_global_asm_8072052C, 1, 0, 1.0f, 2, 3);
    if (func_menu_800322D0(2)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, (s32)&D_global_asm_8072052C, 2, 0, 1.0f, 2, 3);
    func_menu_80030894(MaaD, &D_global_asm_807204BC, 0xA0, 0x78, 1.0f, 2, 4);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0xD2, 0.75f, 2, 0);
}

extern s8 D_menu_80033FAC;

void func_menu_80029EF8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    if ((MaaD->unk0 == 0.0f) && (MaaD->unk4 == 0.0f)) {
        if (arg1 & 1) {
            if ((arg1 & 8) && (D_menu_80033FAC != 0)) {
                func_global_asm_8071495C();
                drawSpriteAtPosition(&D_global_asm_8071FBC8, 10.3f, 240.0f, 120.0f, -10.0f);
                func_global_asm_8071495C();
                drawSpriteAtPosition(&D_global_asm_8071FE08, 10.3f, 240.0f, 120.0f, -10.0f);
                playSound(0xF6, 0x7FFF, 63.0f, 1.0f, 0, 0);
                func_global_asm_8060C830(D_menu_80033F48, 1);
                MaaD->unk16 = 0;
                MaaD->unk13 = 2;
            } else if ((arg1 & 4) && (D_menu_80033FAC != 0)) {
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 2;
            }
        } else if (arg1 & 2) {
            playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
            MaaD->unk16 = 0;
            MaaD->unk13 = 2;
        }
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
}

// Displaylist stuff, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002A088.s")

/*
Gfx *func_menu_8002A088(Actor *arg0, Gfx *dl) {
    f32 sp118;
    f32 sp114;
    u8 unk108[0x114 - 0x108];
    s16 sp106;
    s8 sp3C[0x106 - 0x3C];
    Struct800317E8 *aaD;
    s16 temp_f4;

    aaD = arg0->additional_actor_data;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_menu_800317E8(aaD, 160.0f, 25.0f, &sp118, &sp114, 5, 0, 0.45f);
    sp106 = sp118 * 4.0f;
    temp_f4 = (sp114 * 4.0f);
    if (func_menu_800322D0(D_menu_80033F48)) {
        _sprintf(&sp3C, "%s", label_string_pointer_array[6]);
    } else {
        _sprintf(&sp3C, "%s %d", label_string_pointer_array[7], D_menu_80033F48 + 1);
    }
    dl = printText(dl, sp106, temp_f4, 0.6f, &sp3C);
    dl = printText(dl, sp118 * 4.0f, temp_f4 - 60, 0.6f, label_string_pointer_array[8]);
    func_menu_800317E8(aaD, 160.0f, 80.0f, &sp118, &sp114, 5, 0, 2.0f);
    dl = printText(dl, sp118 * 4.0f, sp114 * 4.0f, 0.6f, label_string_pointer_array[9]);
    func_menu_800317E8(aaD, 80.0f, 120.0f, &sp118, &sp114, 5, 0, 2.0f);
    dl = printText(dl, sp118 * 4.0f, sp114 * 4.0f, 0.6f, label_string_pointer_array[10]);
    return printText(dl, 1280 - (s32)(sp118 * 4.0f), sp114 * 4.0f, 0.6f, label_string_pointer_array[11]);
}
*/

void func_menu_8002A36C(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    D_menu_80033FAC = 0;
    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_807204BC, 0xA0, 0x80, 1.0f, 2, 8);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0xD2, 0.75f, 2, 0);
}

extern s16 D_menu_80033670;
extern s8 D_global_asm_80744538;
extern s8 D_global_asm_8076A104;
extern s8 barrel_visibility_timer;

void func_menu_8002A468(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    if (MaaD->unk0 == 0.0f) {
        if (MaaD->unk4 == 0.0f) {
            if ((arg1 & 1) != 0) {
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 7;
            } else if ((arg1 & 2) != 0) {
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 1;
                barrel_visibility_timer = 3;
            } else {
                func_menu_8002FD38(MaaD, 2, arg1);
            }
            if (MaaD->unk17 == 0) {
                if (((D_menu_80033670 & 0x10) == 0) && ((arg1 & 0x10) != 0)) {
                    playSound(0x75, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    D_global_asm_80744538++;
                    if (D_global_asm_80744538 >= 3) {
                        D_global_asm_80744538 = 0;
                    }
                } else if ((( D_menu_80033670 & 0x20) == 0) && ((arg1 & 0x20) != 0)) {
                    playSound(0x75, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    D_global_asm_80744538 += -1;
                    if (D_global_asm_80744538 < 0) {
                        D_global_asm_80744538 = 2;
                    }
                }
            }
        }
        func_menu_8002FE08(MaaD, 2);
    }
    D_global_asm_8076A104 = MaaD->unk17;
    func_menu_8002FC1C(arg0, MaaD, 1);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002A638.s")

typedef struct {
    s8 unk0[4];
} Struct8076A0E8;

extern s8 D_global_asm_8076A0E4[];
extern Struct8076A0E8 D_global_asm_8076A0E8[];
extern s8 D_global_asm_8076A100[];

void func_menu_8002AA98(s32 arg0, s32 arg1) {
    s32 var_a2;
    s32 i;
    s8 temp_v0 = D_global_asm_8076A0E4[arg0];

    var_a2 = FALSE;
    if (D_global_asm_8076A100[arg0] >= 0) {
        D_global_asm_8076A0E8[temp_v0].unk0[D_global_asm_8076A100[arg0]] = -1;
    }
    for (i = 0; i < 4 && !var_a2; i++) {
        if (D_global_asm_8076A0E8[arg1].unk0[i] == -1) {
            var_a2 = TRUE;
            D_global_asm_8076A100[arg0] = i;
            D_global_asm_8076A0E8[arg1].unk0[i] = arg0;
        }
    }
    D_global_asm_8076A0E4[arg0] = arg1;
}

void func_menu_8002AB28(s32 arg0) {
    s8 temp_v0;

    temp_v0 = D_global_asm_8076A0E4[arg0];
    if (D_global_asm_8076A100[arg0] >= 0) {
        if (!(temp_v0 & 0x80)) {
            D_global_asm_8076A0E8[temp_v0].unk0[D_global_asm_8076A100[arg0]] = -1;
        }
    }
    D_global_asm_8076A100[arg0] = -1;
    D_global_asm_8076A0E4[arg0] = -0x80;
}

extern s8 D_8076A0D6;

void func_menu_8002AB80(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *temp_s0;
    Struct8076A0E8 *var_v0;
    s32 var_s0;
    s32 i;

    temp_s0 = arg0->additional_actor_data;
    temp_s0->unk17 = D_8076A0D6;
    func_menu_80030894(temp_s0, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s0, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s0, &D_global_asm_80720C34, 0xA0, 0x78, 0.75f, 2, 4);
    for (i = 0; i < 6; i++) {
        for (var_s0 = 0; var_s0 < 4; var_s0++) {\
            D_global_asm_8076A0E8[i].unk0[var_s0] = -1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            func_menu_8002AA98(i, i);
        } else {
            D_global_asm_8076A0E4[i] = -0x80;
            func_menu_8002AB28(i);
        }
    }
}

s32 func_menu_8002ACD4(s32 arg0) {
    s32 found;
    s32 var_v1;
    s32 temp;

    temp = D_global_asm_8076A0E4[arg0];
    var_v1 = D_global_asm_8076A100[arg0];
    found = FALSE;
    D_global_asm_8076A0E8[temp].unk0[var_v1] = -1;
    while (!found) {
        var_v1++;
        if (var_v1 >= 4) {
            var_v1 = 0;
        }
        if (D_global_asm_8076A0E8[temp].unk0[var_v1] == -1) {
            found = TRUE;
            D_global_asm_8076A100[arg0] = var_v1;
            D_global_asm_8076A0E8[temp].unk0[var_v1] = arg0;
        }
    }
    return var_v1;
}

s32 func_menu_8002AD50(s32 arg0) {
    s32 found;
    s32 var_v1;
    s32 temp;

    temp = D_global_asm_8076A0E4[arg0];
    var_v1 = D_global_asm_8076A100[arg0];
    found = FALSE;
    D_global_asm_8076A0E8[temp].unk0[var_v1] = -1;
    while (!found) {
        var_v1--;
        if (var_v1 < 0) {
            var_v1 = 3;
        }
        if (D_global_asm_8076A0E8[temp].unk0[var_v1] == -1) {
            found = TRUE;
            D_global_asm_8076A100[arg0] = var_v1;
            D_global_asm_8076A0E8[temp].unk0[var_v1] = arg0;
        }
    }
    return var_v1;
}

// Huge, something to do with inputs
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002ADC8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002B708.s")

extern s16 D_menu_8003386C[];
extern s8 D_menu_80033FAD;
extern s8 D_menu_80033FAE;
extern s8 D_menu_80033FAF;
extern s8 D_global_asm_8074451C;
extern s16 D_global_asm_80744544;

typedef struct {
    u8 unk0[0x17 - 0x0];
    u8 unk17;
} AAD_menu_8002C0C8;

typedef struct {
    Actor *unk0;
    s32 unk4;
    s8 unk8;
} AAD_MultiplayerMenuKong;

void func_menu_8002C0C8(Actor *arg0, s32 arg1) {
    s32 globalFlagIndex;
    s32 i;
    AAD_menu_8002C0C8 *temp_s6;
    AAD_MultiplayerMenuKong *temp_v1;

    temp_s6 = arg0->additional_actor_data;
    func_menu_8002F8EC();
    D_menu_80033FAF = 1;
    globalFlagIndex = GLOBALFLAG_MULTIPLAYER_DIDDY;
    for (i = 1; i < 5; i++) {
        if (isFlagSet(globalFlagIndex, FLAG_TYPE_GLOBAL)) {
            D_menu_80033FAF |= 1 << i;
        }
        globalFlagIndex++;
    }
    if (D_global_asm_80744544 & 1) {
        D_menu_80033FAF |= 0x20;
    }
    D_menu_80033FAE = 0;
    D_menu_80033FAD = 0;
    if (D_global_asm_8076A104 != 0) {
        if (D_global_asm_8074451C >= 5) {
            D_global_asm_8074451C = 0;
        }
    }
    temp_s6->unk17 = D_global_asm_8074451C;
    for (i = 0; i < 4; i++) {
        Actor17C *temp;
        spawnActor(ACTOR_MAIN_MENU_MULTIPLAYER_KONG, D_menu_8003386C[D_global_asm_8076A0E4[i] & 0x7F]);
        temp = gLastSpawnedActor->unk17C;
        temp->unk0_s16[0] = D_menu_8003386C[D_global_asm_8076A0E4[i] & 0x7F];
        gLastSpawnedActor->control_state = i;
        gLastSpawnedActor->control_state_progress = D_global_asm_8076A0E4[i] & 0x7F;
        temp_v1 = gLastSpawnedActor->additional_actor_data;
        temp_v1->unk0 = arg0;
        temp_v1->unk8 = 0;
    }
    func_menu_80030894(temp_s6, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_80720C34, 0xA0, 0x7D, 0.75f, 2, 4);
    func_menu_80030894(temp_s6, &D_global_asm_80720D80, 0xA0, 0x10, 0.5f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_807211AC, 0xA0, 0xDC, 0.75f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_807211D0, 1, 1, 0.8f, 2, 0xF);
    func_menu_80030894(temp_s6, &D_global_asm_807211D0, 2, 2, 0.8f, 2, 0xF);
    func_menu_80030894(temp_s6, &D_global_asm_807211D0, 3, 3, 0.8f, 2, 0xF);
    func_menu_80030894(temp_s6, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0xB);
    func_menu_80030894(temp_s6, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0xB);
    func_menu_80030894(temp_s6, &D_global_asm_80720C34, 0xA0, 0x16D, 0.75f, 2, 4);
    func_menu_80030894(temp_s6, &D_global_asm_80720D5C, 0xA0, 0xDC, 0.5f, 2, 0xB);
    func_menu_80030894(temp_s6, &D_global_asm_80720D80, 0xA0, 0x10, 0.5f, 2, 0x13);
    func_menu_80030894(temp_s6, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0xD);
    func_menu_80030894(temp_s6, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0xD);
    func_menu_80030894(temp_s6, &D_global_asm_80720C34, 0xA0, 0x23F, 0.75f, 2, 4);
    func_menu_80030894(temp_s6, &D_global_asm_80720D5C, 0xA0, 0xDC, 0.5f, 2, 0xD);
}

void func_menu_8002FC1C(Actor*, MenuAdditionalActorData*, s32);

void func_menu_8002C584(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    if (MaaD->unk0 == 0.0 && arg1 & 1) {
        playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
        MaaD->unk16 = 0;
        MaaD->unk13 = 7;
    }
    func_menu_8002FC1C(arg0, MaaD, 0);
    func_menu_8002F8EC();
    global_properties_bitfield &= ~0x10;
    global_properties_bitfield |= 0x10000;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002C634.s")

extern u8 D_menu_80033F20[];
extern u8 D_menu_80033F24[];
extern s16 D_80744524[];
extern s8 D_global_asm_8076A105;
extern u8 D_menu_80033878;
extern u8 D_menu_8003387C[];

typedef struct MultiKongAAD {
    Actor *controller;
    s32 unk4;
    s8 unk8;
} MultiKongAAD;

typedef struct {
    u16 unk0;
} AAD_8002C91C;

void func_menu_8002C91C(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s32 i;
    MultiKongAAD *temp_v0;
    AAD_8002C91C *a17C;

    for (i = 0; i < 4; i++) {
        if (!(D_global_asm_8076A0E4[i] & 0x80)) {
            D_menu_8003387C[D_menu_80033878] = D_global_asm_8076A0E4[i] & 0x7F;
            D_menu_80033F20[D_menu_80033878] = i;
            D_menu_80033F24[i] = D_menu_80033878;
            if (D_menu_80033878 == D_global_asm_8076A105) D_80744524[i]++;
            D_menu_80033878++;
        }
    }
    func_menu_8002F8EC();
    MaaD->unk17 = 0;
    for (i = 0; i < D_menu_80033878; i++) {
        spawnActor(ACTOR_MAIN_MENU_MULTIPLAYER_KONG, D_menu_8003386C[D_menu_8003387C[i]]);
        a17C = gLastSpawnedActor->unk17C;
        a17C->unk0 = D_menu_8003386C[D_menu_8003387C[i]];
        gLastSpawnedActor->control_state = D_menu_80033F20[i] | 0x80;
        gLastSpawnedActor->control_state_progress = D_menu_8003387C[i];
        temp_v0 = gLastSpawnedActor->additional_actor_data;
        temp_v0->controller = arg0;
        temp_v0->unk8 = (i == D_global_asm_8076A105) + 1;
    }
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
}

// TODO: Huge, very doable, need energy
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002CB18.s")

extern u8 D_menu_80033F24[];
extern u8 D_menu_80033878;

typedef struct {
    f32 unk0;
    f32 unk4;
} Menu80033894;

extern Menu80033894 D_menu_80033894[];
extern s32 D_menu_800338B4[3][6];

/*
void func_menu_8002CB18(void) {
    ActorAnimationState *temp_v0;
    f32 temp_f10;
    Struct800317E8 *aad2;
    MultiKongAAD *aaD1;
    s8 delete_actor;
    f32 x, y;
    s16 temp_t7;
    s32 temp_s1_2;
    u8 var_t0;
    Menu80033894 *temp_v0_4;

    aaD1 = gCurrentActorPointer->additional_actor_data;
    aad2 = aaD1->controller->additional_actor_data;
    delete_actor = FALSE;
    func_global_asm_806BF920();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->animation_state->scale[0] *= 2.0f;
        gCurrentActorPointer->animation_state->scale[1] *= 2.0f;
        gCurrentActorPointer->animation_state->scale[2] *= 2.0f;
        playActorAnimation(gCurrentActorPointer, D_menu_800338B4[aaD1->unk8][gCurrentActorPointer->control_state_progress & 0xF]);
        func_global_asm_806F0C18(gCurrentActorPointer);
        gCurrentActorPointer->object_properties_bitfield |= 0x1000;
        aaD1->unk4 = D_global_asm_8076A100[gCurrentActorPointer->control_state & 0xF];
        func_global_asm_8068A4C8(gCurrentActorPointer, gCurrentActorPointer->control_state_progress + 2, D_global_asm_8076A100[gCurrentActorPointer->control_state & 0xF]);
    }
    if (!(gCurrentActorPointer->control_state & 0x80)) {
        if (aaD1->unk4 != D_global_asm_8076A100[gCurrentActorPointer->control_state]) {
            func_global_asm_8068A4C8(gCurrentActorPointer, gCurrentActorPointer->control_state_progress + 2, D_global_asm_8076A100[var_t0]);
            aaD1->unk4 = D_global_asm_8076A100[gCurrentActorPointer->control_state];
        }
        temp_t7 = D_global_asm_8076A0E4[gCurrentActorPointer->control_state] & 0x7F;
        if (temp_t7 != gCurrentActorPointer->control_state_progress) {
            spawnActor(ACTOR_MAIN_MENU_MULTIPLAYER_KONG, D_menu_8003386C[temp_t7]);
            gLastSpawnedActor->unk17C->unk0_s16[0] = D_menu_8003386C[temp_t7];
            gLastSpawnedActor->control_state = gCurrentActorPointer->control_state;
            gLastSpawnedActor->control_state_progress = temp_t7;
            ((MultiKongAAD *)gLastSpawnedActor->additional_actor_data)->controller = aaD1->controller;
            delete_actor = TRUE;
        }
        temp_v0_4 = &D_menu_80033894[gCurrentActorPointer->control_state];
        func_menu_800317E8(aad2, temp_v0_4->unk0, temp_v0_4->unk4, &x, &y, 2, 0, 1.8f);
        gCurrentActorPointer->x_position = gPlayerPointer->x_position + (x - 160.0f);
        gCurrentActorPointer->y_position = (gPlayerPointer->y_position - (y - 120.0f)) - 20.0f;
        gCurrentActorPointer->z_position = gPlayerPointer->z_position - 300.0f;
        if (D_global_asm_8076A0E4[gCurrentActorPointer->control_state] & 0x80) {
            gCurrentActorPointer->object_properties_bitfield &= ~4;
        } else {
            gCurrentActorPointer->object_properties_bitfield |= 4;
        }
    } else {
        temp_s1_2 = 0x140 / D_menu_80033878;
        func_menu_800317E8(aad2, 160.0f, 150.0f, &x, &y, 2, 0, 1.8f);
        temp_f10 = ((D_menu_80033F24[gCurrentActorPointer->control_state & 0xF] * temp_s1_2) + (temp_s1_2 >> 1)) - 0xA0;
        gCurrentActorPointer->x_position = gPlayerPointer->x_position + (temp_f10 * 0.78);
        gCurrentActorPointer->y_position = (gPlayerPointer->y_position - (y - 120.0f)) + 16.0f;
        gCurrentActorPointer->z_position = gPlayerPointer->z_position - 300.0f;
    }
    if (aad2->unk0 > 1.0f) {
        delete_actor = TRUE;
    }
    if (delete_actor) {
        deleteActor(gCurrentActorPointer);
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

extern s16 D_menu_80033670;
extern s8 D_global_asm_8074583C;
extern s8 D_global_asm_80745840;
extern s8 D_global_asm_80745844;

typedef struct MenuStruct7 {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
} MenuStruct7;
extern Struct80757044 D_global_asm_80744548[];
extern Struct80757044 D_global_asm_80744568[];

void func_global_asm_8060A398(s32);

void func_menu_8002CFA4(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s8 sp23 = FALSE;

    func_menu_8002907C();
    if (MaaD->unk0 == 0.0f) {
        if (MaaD->unk4 == 0.0f) {
            switch (MaaD->unk17) {
                case 0:
                    if (!(D_menu_80033670 & 0x10) && (arg1 & 0x10)) {
                        D_global_asm_80745844++;
                        if (D_global_asm_80745844 > 2) {
                            D_global_asm_80745844 = 0;
                        }
                        sp23 = TRUE;
                    } else if (!(D_menu_80033670 & 0x20) && (arg1 & 0x20)) {
                        D_global_asm_80745844--;
                        if (D_global_asm_80745844 < 0) {
                            D_global_asm_80745844 = 2;
                        }
                        sp23 = TRUE;
                    }
                    if (sp23) {
                        func_menu_80027E10();
                    }
                    break;
                case 1:
                    if (arg1 & 0x10) {
                        D_global_asm_8074583C++;
                        playSound(0x2A0, 0x7FFF, 63.0f, 1.0f, 0, 0);
                        if (D_global_asm_8074583C > 0x28) {
                            D_global_asm_8074583C = 0x28;
                        }
                    } else if (arg1 & 0x20) {
                        D_global_asm_8074583C--;
                        playSound(0x2A0, 0x7FFF, 63.0f, 1.0f, 0, 0);
                        if (D_global_asm_8074583C < 0) {
                            D_global_asm_8074583C = 0;
                        }
                    }
                    func_global_asm_80737B58(0, ((D_global_asm_8074583C * 0x61A8) / 40));
                    func_global_asm_80737B58(1, ((D_global_asm_8074583C * 0x61A8) / 40));
                    func_global_asm_80737B58(2, ((D_global_asm_8074583C * 0x61A8) / 40));
                    func_global_asm_80737B58(3, ((D_global_asm_8074583C * 0x61A8) / 40));
                    break;
                case 2:
                    if (arg1 & 0x10) {
                        D_global_asm_80745840++;
                        if (D_global_asm_80745840 >= 0x29) {
                            D_global_asm_80745840 = 0x28;
                        }
                    } else if (arg1 & 0x20) {
                        D_global_asm_80745840--;
                        if (D_global_asm_80745840 < 0) {
                            D_global_asm_80745840 = 0;
                        }
                    }
                    func_global_asm_8060A398(0);
                    func_global_asm_8060A398(2);
                    break;
                case 3:
                    if (arg1 & 0x100) {
                        D_global_asm_80745844 = 0;
                        D_global_asm_8074583C = 0x28;
                        D_global_asm_80745840 = 0x28;
                        func_global_asm_80737B58(0, ((D_global_asm_8074583C * 0x61A8) / 40));
                        func_global_asm_80737B58(1, ((D_global_asm_8074583C * 0x61A8) / 40));
                        func_global_asm_80737B58(2, ((D_global_asm_8074583C * 0x61A8) / 40));
                        func_global_asm_80737B58(3, ((D_global_asm_8074583C * 0x61A8) / 40));
                        func_global_asm_8060A398(0);
                        func_global_asm_8060A398(2);
                        sp23 = 1;
                        func_menu_80027E10();
                    }
                    break;
            }
            if (arg1 & 2) {
                if (func_global_asm_8060C6B8(0x1E, 0, 0, 0) != D_global_asm_80745844) {
                    func_global_asm_8060C648(0x1E, 0, 0, 0, D_global_asm_80745844);
                    func_global_asm_8060DEA8();
                }
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 1;
            } else {
                func_menu_8002FD38(MaaD, 4, arg1);
            }
        }
        func_menu_8002FE08(MaaD, 4);
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
    if (sp23) {
        playSound(0x74, 0x7FFF, 63.0f, 1.0f, 0, 0);
    }
}

Gfx *func_menu_8002F980(Gfx *, Struct800317E8 *, s8 **, s8, u32 *, s32, f32 *, f32, s32);
extern s8 D_global_asm_8074583C;
extern s8 D_global_asm_80745840;
extern s8 D_global_asm_80745844;
extern s16 D_menu_80033674;

Gfx *func_menu_8002D520(Actor *arg0, Gfx *dl) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s32 sp60;
    s8 pad[4];
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s16 pad4;
    s16 temp_f10;
    s8 pad3[2];
    s8 var_v0;
    char sp40[4];

    global_properties_bitfield &= ~0x10;
    func_menu_800317E8(MaaD, 160.0f, 20.0f, &sp58, &sp54, 2, 0, 1.5f);
    dl = printStyledText(dl, 1, 0x280, sp54 * 4.0f, label_string_pointer_array[32], 0x81U);
    dl = func_menu_8002F980(dl, MaaD, &label_string_pointer_array[33], 4, &sp60, 1, &sp50, 80.0f, -1);
    D_menu_80033674 = 0x3E8;
    dl = dl;
    func_menu_800317E8(MaaD, 160.0f, 150.0f, &sp58, &sp54, 2, 0, 1.5f);
    temp_f10 = sp54 * 4.0f;
    sp58 = (sp58 - sp50) * 4.0f;
    switch (sp60) {
        case 0:
            dl = printStyledText(dl, 1, sp58, temp_f10, label_string_pointer_array[D_global_asm_80745844 + 37], 0x81U);
            break;
        case 1:
        case 2:
            dl = printStyledText(dl, 1, sp58, temp_f10, label_string_pointer_array[40], 0x81U);
            var_v0 = sp60 == 1 ? D_global_asm_8074583C : D_global_asm_80745840;
            _sprintf(sp40, "%d", (var_v0 + 1) >> 1);
            dl = printStyledText(dl, 1, sp58, temp_f10 + 0x78, &sp40, 0x81U);
            break;
        case 3:
            D_menu_80033674 = 0;
            break;
    }
    return dl;
}

void func_menu_8002D7EC(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0x7D, 0.75f, 2, 4);
    func_menu_80030894(MaaD, &D_global_asm_80720D38, 0xA0, 0xC8, 1.0f, 2, 0xC);
}

extern u8 D_global_asm_80744530;
extern s16 D_global_asm_80744544;
extern u8 D_global_asm_807550C8;
extern s16 D_menu_80033670;
extern s8 D_menu_800338FC;

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 unk8[0x13 - 0x8];
    u8 unk13;
    u8 unk14; // Unused?
    u8 unk15; // Unused?
    u8 unk16;
    u8 unk17;
} AAD_8002D8AC;

void func_menu_8002D8AC(Actor *arg0, s32 arg1) {
    AAD_8002D8AC *aaD;
    s8 optionChanged;
    s32 i;

    aaD = arg0->additional_actor_data;
    optionChanged = FALSE;
    if (aaD->unk0 == 0.0f) {
        if (aaD->unk4 == 0.0f) {
            switch (aaD->unk17) {
                case 0:
                    if ((arg1 & 0x30) && !(D_menu_80033670 & 0x30)) {
                        widescreen_enabled = 1 - widescreen_enabled;
                        optionChanged = TRUE;
                    }
                    break;
                case 1:
                    if ((arg1 & 0x30) && !(D_menu_80033670 & 0x30)) {
                        story_skip = 1 - story_skip;
                        optionChanged = TRUE;
                    }
                    break;
                case 2:
                    if (arg1 & 0x100) {
                        func_global_asm_8060C8AC(0xFF);
                        playSound(0x23C, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    }
                    break;
                case 3:
                    if ((arg1 & 0x30) && !(D_menu_80033670 & 0x30)) {
                        D_global_asm_80744530 = 1 - D_global_asm_80744530;
                        optionChanged = TRUE;
                    }
                    break;
                case 4:
                    if ((arg1 & 0x10) && !(D_menu_80033670 & 0x10)) {
                        D_global_asm_807550C8++;
                        optionChanged = TRUE;
                    }
                    if ((arg1 & 0x20) && !(D_menu_80033670 & 0x20)) {
                        D_global_asm_807550C8--;
                        optionChanged = TRUE;
                    }
                    D_global_asm_807550C8 &= 3;
                    if (optionChanged) {
                        for (i = 0; i < 101; i++) {
                            func_global_asm_8061134C((label_string_pointer_array[i]));
                        }
                        func_global_asm_8061134C(label_string_pointer_array);
                        func_menu_800324CC();
                    }
                    break;
            }
            if (arg1 & 2) {
                func_global_asm_8060C648(0x1F, 0, 0, 0, D_global_asm_807550C8);
                func_global_asm_8060C648(0x20, 0, 0, 0, D_global_asm_80744530);
                func_global_asm_8060DEA8();
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                aaD->unk16 = 0;
                aaD->unk13 = 1;
            } else {
                func_menu_8002FD38(aaD, D_menu_800338FC, arg1);
            }
        }
        func_menu_8002FE08(aaD, D_menu_800338FC);
    }
    func_menu_8002FC1C(arg0, aaD, 1);
    if (newly_pressed_input_copy & (U_CBUTTONS | D_CBUTTONS)) {
        D_global_asm_80744544 ^= 0x100;
    }
    if (optionChanged) {
        playSound(0x74, 0x7FFF, 63.0f, 1.0f, 0, 0);
    }
}

extern s16 D_menu_80033674;

Gfx *func_menu_8002DBDC(Actor *arg0, Gfx *dl) {
    Struct800317E8 *aaD;
    u32 sp68;
    f32 x;
    f32 sp60;
    f32 sp5C;
    s32 pad6;
    s16 y;
    s32 pad;
    s32 pad2;
    s32 pad3;
    s32 pad4;
    s32 pad5;
    s32 pad7;

    aaD = arg0->additional_actor_data;
    global_properties_bitfield &= ~0x10;
    func_menu_800317E8(aaD, 160.0f, 20.0f, &x, &sp60, D_menu_800338FC, 0, 1.5f);
    dl = printStyledText(dl, 1, 640, sp60 * 4.0f, label_string_pointer_array[41], 0x81);
    dl = func_menu_8002F980(dl, aaD, &label_string_pointer_array[42], D_menu_800338FC, &sp68, 1, &sp5C, 80.0f, -1);
    D_menu_80033674 = 1000;
    func_menu_800317E8(aaD, 160.0f, 150.0f, &x, &sp60, 2, 0, 1.5f);
    y = sp60 * 4.0f;
    x = (x - sp5C) * 4.0f;
    switch (sp68) {
        case 0:
            dl = printStyledText(dl, 1, x, y + 64, label_string_pointer_array[47 + widescreen_enabled], 0x81);
            break;
        case 1:
            dl = printStyledText(dl, 1, x, y + 64, label_string_pointer_array[49 + story_skip], 0x81);
            break;
        case 2:
            D_menu_80033674 = 0;
            break;
        case 3:
            dl = printStyledText(dl, 1, x, y + 64, label_string_pointer_array[52 + D_global_asm_80744530], 0x81);
            break;
        case 4:
            dl = printStyledText(dl, 1, x, y + 64, label_string_pointer_array[51], 0x81);
            break;
    }
    return dl;
}

void func_menu_8002DEE8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0x7D, 0.75f, 2, 4);
    func_menu_80030894(MaaD, &D_global_asm_80720D38, 0xA0, 0xC8, 1.0f, 2, 0xC);
}

typedef struct DKTheatreWarpStruct {
    s16 map;
    s16 cutscene;
} DKTheatreWarpStruct;

typedef struct MysteryMenuWarpStruct {
    s16 map;
    s16 kong;
} MysteryMenuWarpStruct;

typedef struct MysteryMenuMovesStruct {
    MysteryMenuWarpStruct warp;
    s8 special_moves;
    s8 slam;
    s8 instrument;
    s8 melons;
} MysteryMenuMovesStruct;

extern u8 D_global_asm_80744514;
extern s8 D_8074453C[];
extern s16 D_global_asm_80744544;
extern s16 D_menu_80033670;
extern DKTheatreWarpStruct D_menu_80033900[];
extern MysteryMenuMovesStruct D_menu_80033938[];
extern MysteryMenuWarpStruct D_menu_80033978[];
extern s8 D_menu_80033988[]; // Mys Menu Vertical Max
extern s16 D_menu_80033998[];
extern s8 D_menu_800339A8;
extern s8 barrel_visibility_timer;

void func_menu_8002DFA8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s8 sp3B;
    s8 max_vertical;
    s8 sp39;
    s8 screen;
    s32 temp_a0_2;

    sp3B = FALSE;
    if (MaaD->unk0 == 0.0f) {
        if (MaaD->unk4 == 0.0f) {
            screen = MaaD->unk17;
            max_vertical = D_menu_80033988[screen];
            if (max_vertical > 0) {
                if ((arg1 & 0x10) && !(D_menu_80033670 & 0x10) && (max_vertical != 1)) {
                    sp3B = TRUE;
                    do {
                        D_8074453C[screen]++;
                        if (D_8074453C[screen] >= max_vertical) {
                            D_8074453C[screen] = 0;
                        }
                    } while (!(D_menu_80033998[screen] & (1 << D_8074453C[screen])));
                }
                if ((arg1 & 0x20) && !(D_menu_80033670 & 0x20) && (max_vertical != 1)) {
                    sp3B = TRUE; \
                    do {
                        D_8074453C[screen]--;
                        if (D_8074453C[screen] < 0) {
                            D_8074453C[screen] = max_vertical - 1;
                        }
                    } while (!(D_menu_80033998[screen] & (1 << D_8074453C[screen])));
                }
                sp39 = D_8074453C[screen];
                if (arg1 & 1) {
                    switch (screen) {
                    case 0:
                        if (sp39 != 0xD) {
                            func_global_asm_80712634(
                                D_menu_80033900[sp39].map,
                                D_menu_80033900[sp39].cutscene);
                        } else {
                            // End Sequence
                            func_global_asm_807127F4(1);
                        }
                        D_global_asm_80744514 = 3;
                        break;
                    case 1:
                        switch (D_menu_80033978[sp39].map) {
                            case MAP_RAMBI_ARENA:
                                playSound(0x2C9, 0x7FFFU, 63.0f, 1.0f, 0, 0);
                                MaaD->unk16 = 0;
                                MaaD->unk13 = 0xC;
                                D_menu_800339A8 = 0;
                                break;
                            case MAP_ENGUARDE_ARENA:
                                playSound(0x2C9, 0x7FFFU, 63.0f, 1.0f, 0, 0);
                                MaaD->unk16 = 0;
                                MaaD->unk13 = 0xC;
                                D_menu_800339A8 = 1;
                                break;
                            default:
                                func_global_asm_807126B0(
                                    D_menu_80033978[sp39].map, 0,
                                    D_menu_80033978[sp39].kong, 3, 3, 1, 3);
                                    D_global_asm_80744514 = 5;
                                break;
                        }
                        break;
                    case 2:
                        func_global_asm_807126B0(
                            D_menu_80033938[sp39].warp.map,
                            0,
                            D_menu_80033938[sp39].warp.kong,
                            D_menu_80033938[sp39].special_moves,
                            D_menu_80033938[sp39].slam,
                            D_menu_80033938[sp39].instrument,
                            D_menu_80033938[sp39].melons);
                            D_global_asm_80744514 = 4;
                        break;
                    }
                }
                if (arg1 & 0x100) {
                    if (screen == 3) {
                        D_global_asm_80744544 ^= 1;
                        sp3B = TRUE;
                    } else if (screen == 4) {
                        temp_a0_2 = 1 << (sp39 + 1);
                        sp3B = TRUE;
                        D_global_asm_80744544 ^= temp_a0_2;
                        if (sp39 == 6) {
                            if (D_global_asm_80744544 & temp_a0_2) {
                                D_global_asm_80744544 |= 0xFEFE;
                            } else {
                                D_global_asm_80744544 &= 1;
                            }
                        }
                    }
                }
            }
            if (arg1 & 2) {
                playSound(0x2C9, 0x7FFFU, 63.0f, 1.0f, 0, 0);
                MaaD->unk16 = 0;
                MaaD->unk13 = 1;
                barrel_visibility_timer = 3;
            } else {
                func_menu_8002FD38(MaaD, 5, arg1);
            }
        }
        func_menu_8002FE08(MaaD, 5);
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
    if (sp3B) {
        playSound(0x74, 0x7FFFU, 63.0f, 1.0f, 0, 0);
    }
}

extern s8 D_8074453D;
extern s8 D_8074453E;
extern s8 D_80744540;
extern s8 D_menu_80033990[];
extern s16 D_menu_800339A4;

Gfx *func_menu_8002E420(Actor *arg0, Gfx *dl) {
    MenuAdditionalActorData *MaaD;
    u32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    s16 pad10a;
    s16 sp108;
    s8 sp40[200];

    MaaD = arg0->MaaD;
    global_properties_bitfield &= ~0x10;
    func_menu_800317E8(MaaD, 160.0f, 20.0f, &sp114, &sp110, 2, 0, 1.5f);
    sp108 = sp110 * 4.0f;
    dl = printStyledText(dl, 1, 0x280, sp108, label_string_pointer_array[54], 0x81U);
    dl = func_menu_8002F980(dl, MaaD, &label_string_pointer_array[55], 5, &sp118, 1, &sp10C, 140.0f, D_menu_800339A4);
    _sprintf(&sp40, "%d", D_menu_80033990[sp118]);
    dl = printStyledText(dl, 3, 0x2A8, sp108 + 0xC8, &sp40, 1U);
    D_menu_80033674 = 0x3E8;
    func_menu_800317E8(MaaD, 160.0f, 160.0f, &sp114, &sp110, 1, 0, 1.5f);
    sp108 = sp110 * 4.0f;
    sp114 = (sp114 - sp10C) * 4.0f;
    if (D_menu_80033988[sp118] > 0) {
        switch (sp118) {
        case 0:
            dl = printStyledText(dl, 1, sp114, sp108 + 0x40, label_string_pointer_array[0x3C + *D_8074453C], 0x81U);
            break;
        case 1:
            dl = printStyledText(dl, 1, sp114, sp108 + 0x40, label_string_pointer_array[0x52 + D_8074453D], 0x81U);
            break;
        case 2:
            dl = printStyledText(dl, 1, sp114, sp108 + 0x40, label_string_pointer_array[0x4A + D_8074453E], 0x81U);
            break;
        case 3:
            _sprintf(&sp40, "%s:%s", label_string_pointer_array[0x5E], label_string_pointer_array[0x31 + (D_global_asm_80744544 & 1)]);
            dl = printStyledText(dl, 1, sp114, sp108 + 0x40, (u8 *) &sp40, 0x81U);
            break;
        case 4:
            _sprintf(&sp40, "%s:%s", label_string_pointer_array[0x56 + D_80744540], label_string_pointer_array[0x31 + (((1 << (D_80744540 + 1)) & D_global_asm_80744544) != 0)]);
            dl = printStyledText(dl, 1, sp114, sp108 + 0x40, (u8 *) &sp40, 0x81U);
            break;
        }
    } else {
        dl = printStyledText(dl, 1, sp114, sp108 + 0x40, "???", 0x81U);
    }
    return dl;
}

// rodata
const char D_menu_80033BE0[] = "-"; // Not yet matched
const char D_menu_80033BE4[] = "  -"; // Not yet matched
const char D_menu_80033BE8[] = "    -"; // Not yet matched

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002E8B8.s")

extern s8 D_menu_80033989;
extern s8 D_menu_8003398A;
extern s8 D_menu_8003398B;
extern s8 D_menu_8003398C;
extern s16 D_menu_800339A4;

/*
void func_menu_8002E8B8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD;
    s32 i;
    s32 j;
    s8 *var_a1;
    s16 *var_a2;

    MaaD = arg0->MaaD;
    MaaD->unk17 = D_8076A0D0[10];
    switch (D_global_asm_80744514) {
        case 0:
        break;
        default:
        MaaD->unk17 = 0;
        break;
        case 4:
        MaaD->unk17 = 2;
        break;
        case 5:
        MaaD->unk17 = 1;
        break;
    }
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2U, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0x78, 0.75f, 2U, 4);
    func_menu_80030894(MaaD, &D_global_asm_80721094, 0x78, 0x50, 1.25f, 2U, 0xE);
    func_menu_80030894(MaaD, &D_global_asm_80720D38, 0x11D, 0xD2, 0.75f, 2U, 0x11);
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x11D, 0xD2, 0.75f, 2U, 0x10);
    var_a1 = &D_menu_80033988[0];
    D_menu_80033988[0] = 0xE;
    D_menu_80033988[1] = 4;
    D_menu_80033988[2] = 8;
    D_menu_80033988[3] = 1;
    D_menu_80033988[4] = 7;
    D_menu_80033998[0] = -1;
    D_menu_80033998[1] = -1;
    D_menu_80033998[2] = -1;
    D_menu_80033998[3] = -1;
    D_menu_80033998[4] = -1;
    D_menu_800339A4 = 0;
    if (isFlagSet(1, 1U)) {
        D_menu_800339A4 |= 1;
        D_menu_80033998[0] = 3;
        j = 4;
        for (i = 2; i < 0xE; i++) {
            if (isFlagSet(i, 1U)) {
                D_menu_80033998[0] |= j;
            }
            j <<= 1;
        }
    } else {
        var_a1[0] = 0;
    }
    if (isFlagSet(0xE, 1U)) {
        D_menu_800339A4 |= 2;
        D_menu_80033998[1] = 0;
        for (i = 0xF, j = 1; i < 0x13; i++) {
            if (isFlagSet(i, 1U)) {
                D_menu_80033998[1] |= j;
            }
            j <<= 1;
        }
    } else {
        D_menu_80033989 = 0;
    }
    if (isFlagSet(0x13, 1U)) {
        D_menu_800339A4 |= 4;
        D_menu_80033998[2] = 0;
        for (i = 0x14, j = 1; i < 0x1C; i++) {
            if (isFlagSet(i, 1U)) {
                D_menu_80033998[2] |= j;
            }
            j <<= 1;
        }
    } else {
        D_menu_8003398A = 0;
    }
    if (!isFlagSet(0x21, 1U)) {
        D_menu_8003398B = 0;
    } else {
        D_menu_800339A4 |= 8;
    }
    if (!isFlagSet(0x22, 1U)) {
        D_menu_8003398C = 0;
    } else {
        D_menu_800339A4 |= 0x10;
    }
    for (j = 0; j < 5; j++) {
        while ((D_menu_80033988[j] > 0) && ((D_menu_80033998[j] & (1 << D_8074453C[j])) == 0)) {
            D_8074453C[j]++;
            if (D_8074453C[j] >= D_menu_80033988[j]) {
                D_8074453C[j] = 0;
                D_menu_80033988[j] = 0;
            }
        }
    }
}
*/


void func_menu_8002ECE8(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        D_global_asm_80744548[i].score = func_global_asm_8060C6B8(0x19, 0, i, 0);
        D_global_asm_80744548[i].initials[0] = func_global_asm_8060C6B8(0x16, 0, i, 0);
        D_global_asm_80744548[i].initials[1] = func_global_asm_8060C6B8(0x17, 0, i, 0);
        D_global_asm_80744548[i].initials[2] = func_global_asm_8060C6B8(0x18, 0, i, 0);
        D_global_asm_80744548[i].pad = 0;
        D_global_asm_80744568[i].score = func_global_asm_8060C6B8(0x1D, 0, i, 0);
        D_global_asm_80744568[i].initials[0] = func_global_asm_8060C6B8(0x1A, 0, i, 0);
        D_global_asm_80744568[i].initials[1] = func_global_asm_8060C6B8(0x1B, 0, i, 0);
        D_global_asm_80744568[i].initials[2] = func_global_asm_8060C6B8(0x1C, 0, i, 0);
        D_global_asm_80744568[i].pad = 0;
    }
}

void func_menu_8002EE18(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        func_global_asm_8060C648(0x19, 0, i, 0, D_global_asm_80744548[i].score);
        func_global_asm_8060C648(0x16, 0, i, 0, D_global_asm_80744548[i].initials[0]);
        func_global_asm_8060C648(0x17, 0, i, 0, D_global_asm_80744548[i].initials[1]);
        func_global_asm_8060C648(0x18, 0, i, 0, D_global_asm_80744548[i].initials[2]);
        func_global_asm_8060C648(0x1D, 0, i, 0, D_global_asm_80744568[i].score);
        func_global_asm_8060C648(0x1A, 0, i, 0, D_global_asm_80744568[i].initials[0]);
        func_global_asm_8060C648(0x1B, 0, i, 0, D_global_asm_80744568[i].initials[1]);
        func_global_asm_8060C648(0x1C, 0, i, 0, D_global_asm_80744568[i].initials[2]);
    }
    func_global_asm_8060DEA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002EF68.s")

typedef struct Struct800339B8 {
    s16 map_id;
    s16 exit_id;
} Struct800339B8;

extern Struct800339B8 D_menu_800339B8[];
extern s8 D_menu_800339C0;
extern s8 D_menu_80033F60;
extern s8 D_menu_80033F61;

/*
void func_menu_8002EF68(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD;
    Struct80757044 *var_a2;
    s32 var_v0;
    s8 var_v1;
    u8 *temp_v1;

    MaaD = arg0->MaaD;
    if (D_menu_800339A8 == 0) {
        var_a2 = D_global_asm_80744548;
    } else {
        var_a2 = D_global_asm_80744568;
    }
    if (MaaD->unk0 == 0.0f) {
        if (D_menu_80033F60 < 0) {
            if (arg1 & 1) {
                func_global_asm_807126B0(D_menu_800339B8[D_menu_800339A8].map_id, 0, D_menu_800339B8[D_menu_800339A8].exit_id, 3, 3, 1, 3);
                D_global_asm_80744514 = D_menu_800339A8 + 6;
            }
            if (arg1 & 2) {
                playSound(0x2C9, 0x7FFF, 63.0f, 1.0f, 0U, 0U);
                MaaD->unk16 = 0;
                MaaD->unk13 = 0xA;
            }
        } else {
            var_v1 = arg1 & 0xC ? D_menu_800339C0 + 1 : 0;
            var_v0 = 0;
            if ((var_v1 == 1) || (var_v1 > 0xF)) {
                D_menu_800339C0 = var_v1;
                var_v0 = arg1;
                if (var_v1 > 0xF) {
                    D_menu_800339C0 = 0xF;
                    if ((object_timer & 1) == 0) {
                        var_v0 = 0;
                    }
                }
            }
            temp_v1 = &var_a2[D_menu_80033F60].initials[D_menu_80033F61];
            if (var_v0 & 4) {
                switch (*temp_v1) {
                default:
                    *temp_v1 = *temp_v1 - 1;
                    break;
                case ' ':
                    *temp_v1 = '.';
                    break;
                case '.':
                    *temp_v1 = 'Z';
                    break;
                case 'A':
                    *temp_v1 = ' ';
                    break;
                }
            } else if (var_v0 & 8) {
                switch (*temp_v1) {
                default:
                    *temp_v1 = *temp_v1 + 1;
                    break;
                case ' ':
                    *temp_v1 = 'A';
                    break;
                case '.':
                    *temp_v1 = ' ';
                    break;
                case 'Z':
                    *temp_v1 = '.';
                    break;
                }
            }
            if (arg1 & 1) {
                if (++D_menu_80033F61 == 3) {
                    D_menu_80033F60 = -1;
                    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2U, 0);
                    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2U, 0);
                    func_menu_8002EE18();
                }
            } else if ((arg1 & 2) && (D_menu_80033F61 > 0)) {
                D_menu_80033F61--;
            }
        }
    }
    func_menu_8002FC1C(arg0, MaaD, 1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002F284.s")


void func_menu_8002F6C8(Actor *arg0, s32 arg1) {
    PlayerAdditionalActorData* PaaD = arg0->PaaD; // TODO: Might be MaaD

    if (D_menu_80033F60 == -1) {
        func_menu_80030894(PaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
        func_menu_80030894(PaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    }
}

// Doable, unrolled loop
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002F75C.s")

extern s8 D_menu_800339A8;
extern s16 D_global_asm_80744518;

/*
void func_menu_8002F75C(void) {
    MenuStruct7 *var_v0;
    s32 var_a2;
    s32 i;

    if (D_menu_800339A8 == 0) {
        var_v0 = &D_global_asm_80744548;
    } else {
        var_v0 = &D_global_asm_80744568;
    }
    for (i = 0; i < 4; i++) {
        if (D_global_asm_80744518 >= var_v0[i].unk0) {
            for (var_a2 = 0; var_a2 <= 4; var_a2++) {
                // var_v0[var_a2] = var_v0[var_a2 + 1];
                var_v0[var_a2].unk0 = var_v0[var_a2 + 1].unk0;
                var_v0[var_a2].unk2 = var_v0[var_a2 + 1].unk2;
                var_v0[var_a2].unk3 = var_v0[var_a2 + 1].unk3;
                var_v0[var_a2].unk4 = var_v0[var_a2 + 1].unk4;
                var_v0[var_a2].unk5 = var_v0[var_a2 + 1].unk5;
            }
            var_v0[i].unk0 = D_global_asm_80744518;
            var_v0[i].unk2 = 0x2E;
            var_v0[i].unk3 = 0x2E;
            var_v0[i].unk4 = 0x2E;
            D_menu_80033F60 = i;
            D_menu_80033F61 = 0;
            return;
        }
    }
    D_menu_80033F60 = -1;
}
*/

void func_menu_8002F8EC(void) {
    character_change_array->look_at_eye_x = gPlayerPointer->x_position;
    character_change_array->look_at_eye_y = gPlayerPointer->y_position + 13.1f;
    character_change_array->look_at_eye_z = gPlayerPointer->z_position - 50.0f;
    character_change_array->look_at_at_x = gPlayerPointer->x_position;
    character_change_array->look_at_at_y = character_change_array->look_at_eye_y;
    character_change_array->look_at_at_z = gPlayerPointer->z_position - 100.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002F980.s")

extern s32 D_menu_800339C4; // TODO: Datatype

typedef struct {
    s32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    s8 unk17;
} Struct8002F980_arg1;

/*
// TODO: Progress made, kinda fiddly
s32 func_menu_8002F980(Gfx *arg0, Struct8002F980_arg1 *arg1, s32 *arg2, s32 arg3, s32 *arg4, s16 arg5, f32 *arg6, f32 arg7, s16 arg8) {
    s32 var_v1;
    f32 var_f0;
    f32 sp3C;
    f32 sp38;

    var_v1 = arg1->unk17;
    if (arg1->unk4 != 0.0f) {
        if (arg1->unk4 > 0.5f) {
            var_v1++;
        }
        if (var_v1 >= arg3) {
            var_v1 = 0;
        }
    }
    var_f0 = arg1->unk4 - 0.5f;
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    var_f0 = (0.5f - var_f0) * 800.0f;
    if (menu_rotation_speed < 0.0f) {
        var_f0 = -var_f0;
    }
    // func_menu_800317E8(0.0f, 0.5f, arg1, var_f0 + 160.0, arg7, &sp3C, &sp38, 2, 0, 2.0f);
    func_menu_800317E8(arg1, var_f0 + 160.0, arg7, &sp3C, &sp38, 2, 0, 2.0f);
    if (arg8 & (1 << var_v1)) {
        arg0 = printStyledText(arg0, arg5, sp3C * 4.0f, sp38 * 4.0f, arg2[var_v1], 0x81);
    } else {
        arg0 = printStyledText(arg0, arg5, sp3C * 4.0f, sp38 * 4.0f, &D_menu_800339C4, 0x81);
    }
    *arg6 = var_f0;
    *arg4 = var_v1;
    return arg0;
}
*/

// TODO: Also used in arcade?
extern f32 D_menu_80033F68[];
extern f32 D_menu_80033F80[];
extern f32 D_menu_80033F98[];

s32 func_menu_8002FB88(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    arg1 &= 0x7F;
    arg2 *= 4.0f;
    arg3 *= 4.0f;
    D_menu_80033F68[arg1] = arg2 - 32.0;
    D_menu_80033F80[arg1] = arg3 - 100.0;
    D_menu_80033F98[arg1] = arg4 * 1.333;
    return arg0;
}

void func_menu_8002FC1C(Actor *arg0, MenuAdditionalActorData *MaaD, s32 arg2) {
    if (MaaD->unk16 == 0) {
        MaaD->unk0 += 0.13f;
        if (1.3f < MaaD->unk0) {
            MaaD->unk0 = 1.0f;
            MaaD->unk12 = MaaD->unk13;
            MaaD->unk16 = -1;
            func_menu_80030340(arg0, 0, NULL, 0);
            playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        }
    } else {
        if (MaaD->unk0 > 0.0f) {
            MaaD->unk0 -= 0.2f;
            if (MaaD->unk0 < 0.0f) {
                MaaD->unk0 = 0.0f;
                if (arg2 != 0) {
                    playSound(0x3C, 0x61A8, 63.0f, 1.0f, 0, 0);
                    D_menu_80033F50 = 3;
                }
            }
        }
    }
}

void func_menu_8002FD38(MenuAdditionalActorData *MaaD, s32 arg1, s32 arg2) {
    if (arg2 & 4) {
        playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        menu_rotation_speed = -0.1f;
        MaaD->unk17--;
        MaaD->unk4 = 1.0f;
        if (MaaD->unk17 < 0) {
            MaaD->unk17 += arg1;
        }
        menu_selection_available = 0;
    } else if (arg2 & 8) {
        playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        menu_rotation_speed = 0.1f;
        menu_selection_available = 0;
    }
}

void func_menu_8002FE08(MenuAdditionalActorData *MaaD, s32 arg1) {
    if (menu_rotation_speed > 0.0f) {
        MaaD->unk4 += menu_rotation_speed;
        if (MaaD->unk4 >= 1.0f) {
            MaaD->unk4 = 0.0f;
            MaaD->unk17++;
            if (MaaD->unk17 >= arg1) {
                MaaD->unk17 -= arg1;
            }
            menu_rotation_speed = 0.0f;
        }
    } else if (menu_rotation_speed < 0.0f) {
        MaaD->unk4 += menu_rotation_speed;
        if (MaaD->unk4 <= 0.0f) {
            menu_rotation_speed = 0.0f;
            MaaD->unk4 = 0.0f;
        }
    }
}

extern s8 D_menu_80033F30;
extern void *D_menu_80033F34;

extern s8 D_menu_80033738;
extern s8 D_menu_800339A8;
extern s8 D_menu_80033F50;
extern s8 D_menu_80033F60;
extern f32 dk_screen_transition_height;
extern f32 menu_icon_transition_scale;

// Main Menu Controller Code
void func_menu_8002FEBC(void) {
    MenuAdditionalActorData *MaaD;
    PlayerAdditionalActorData *PaaD;
    s32 i;

    MaaD = gCurrentActorPointer->MaaD;
    PaaD = gPlayerPointer->PaaD;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        global_properties_bitfield |= 0x10;
        func_menu_800324CC();
        func_menu_8002ECE8();
        if (D_global_asm_80744514 == 0) {
            for (i = 0; i < 0xD; i++) D_8076A0D0[i] = 0;
        } else {
            gPlayerPointer->x_position = 700.0f;
            gPlayerPointer->y_position = 0.0f;
            gPlayerPointer->z_position = 70.0f;
        }
        D_menu_80033F50 = 0;
        D_menu_80033738 = 0;
        D_menu_80033F60 = -1;
        dk_screen_transition_height = 0.0f;
        spawnActor(ACTOR_BARREL_MAIN_MENU, 0xD7);
        MaaD = MaaD;
        gLastSpawnedActor->x_position = gPlayerPointer->x_position;
        gLastSpawnedActor->y_position = gPlayerPointer->y_position;
        gLastSpawnedActor->z_position = gPlayerPointer->z_position;
        gLastSpawnedActor->y_rotation = gPlayerPointer->y_rotation;
        if (D_global_asm_80744514) {
            D_menu_80033738 = 0x15;
            gPlayerPointer->control_state = 0x85;
            gPlayerPointer->control_state_progress = 0;
            playActorAnimation(gPlayerPointer, 0x347);
            gPlayerPointer->control_state_progress = 6;
            func_global_asm_8061B650(D_global_asm_807F5D10);
            menu_icon_transition_scale = 1.0f;
            PaaD->unk23C = 0x50;
        }
        switch (D_global_asm_80744514) {
            case 1:
                MaaD->unk12 = 1;
                break;
            case 2:
                MaaD->unk12 = 0xB;
                break;
            case 3:
            case 4:
            case 5:
                MaaD->unk12 = 0xA;
                break;
            case 6:
            case 7:
                MaaD->unk12 = 0xC;
                D_menu_800339A8 = D_global_asm_80744514 - 6;
                func_menu_8002F75C();
                break;
            default:
                playActorAnimation(gLastSpawnedActor, 0x349);
                gPlayerPointer->control_state = 0x86;
                gPlayerPointer->control_state_progress = 0;
                MaaD->unk12 = 0;
                break;
        }
        gPlayerPointer->animation_state->scale[0] *= 0.8;
        gPlayerPointer->animation_state->scale[1] *= 0.8;
        gPlayerPointer->animation_state->scale[2] *= 0.8;
        MaaD->unk17 = 0;
        MaaD->unkC = 0;
        MaaD->unkE = 0;
        MaaD->unk16 = 1;
        MaaD->unk10 = 0;
        MaaD->unk0 = 1.0f;
        MaaD->unk4 = 0.0f;
        D_menu_80033F34 = malloc(0x80);
        D_menu_80033F30 = 0;
        func_menu_80030340(gCurrentActorPointer, 0, NULL, 0);
        D_global_asm_80744514 = 0;
        func_global_asm_8060AA58(0xFF);
        func_global_asm_8060CB9C();
    }
    func_menu_80030340(gCurrentActorPointer, 2, NULL, 0);
    addActorToTextOverlayRenderArray(func_menu_80030258, gCurrentActorPointer, 3U);
}

void func_menu_80030250(void) {

}

Gfx *func_menu_80030258(Gfx *dl, Actor *arg1) {
    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    return func_menu_80030340(arg1, 1, dl, 0);
}

extern s8 D_8076A0D0[];

typedef struct {
    u8 unk0[0xC - 0x0];
    s16 unkC; // Used
    s16 unkE; // Used
    u8 unk10;
    u8 unk11;
    s8 unk12; // Used
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    s8 unk17; // Used
} AAD_80030340;

Gfx *func_menu_80030340(Actor *actor, s32 arg1, Gfx *dl, s32 arg3) {
    AAD_80030340 *aaD;
    u32 sp18;
    u16 temp_v0;

    aaD = actor->additional_actor_data;
    sp18 = 0;
    if (character_change_array->new_controller_inputs->button & A_BUTTON) {
        sp18 = 1;
    }
    if (character_change_array->new_controller_inputs->button & B_BUTTON) {
        sp18 |= 2;
    }
    if (character_change_array->new_controller_inputs->button & U_CBUTTONS) {
        sp18 |= 0x40;
    }
    if (character_change_array->new_controller_inputs->button & D_CBUTTONS) {
        sp18 |= 0x80;
    }
    if (character_change_array->new_controller_inputs->button & Z_TRIG) {
        sp18 |= 0x100;
    }
    if (D_global_asm_807ECDEC->stick_x < -40) {
        sp18 |= 4;
    } else if (D_global_asm_807ECDEC->stick_x >= 41) {
        sp18 |= 8;
    }
    if (D_global_asm_807ECDEC->stick_y < -40) {
        sp18 |= 0x20;
    } else if (D_global_asm_807ECDEC->stick_y >= 41) {
        sp18 |= 0x10;
    }
    switch (arg1) {
        case 0:
            D_menu_80033F38 = 1;
            menu_rotation_speed = 0.0f;
            menu_selection_speed = 0.0f;
            menu_icon_transition_scale = 0.0f;
            global_properties_bitfield &= 0xFFFEFFFF;
            aaD->unkC = 0;
            aaD->unkE = 0;
            is_in_submenu = 1;
            break;
        case 1:
            break;
        case 2:
            D_8076A0D0[aaD->unk12] = aaD->unk17;
            func_global_asm_80659670(1.0f, 1.0f, 1.0f, 0);
            break;
    }
    switch (aaD->unk12) {
        case 0:
            if (arg1 == 1) {
                func_menu_80027F34(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_80027E60(actor, sp18);
            } else {
                func_menu_80027F40(actor, arg3);
            }
            break;
        case 1:
            if (arg1 == 1) {
                func_menu_800286C8(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_80027FAC(actor, sp18);
            } else {
                func_menu_80028834(actor, arg3);
            }
            break;
        case 2:
            if (arg1 == 1) {
                func_menu_80028D3C(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_80028C20(actor, sp18);
            } else {
                func_menu_80028EA8(actor, arg3);
            }
            break;
        case 3:
            if (arg1 == 1) {
                func_menu_800291CC(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_80029114(actor, sp18);
            } else {
                func_menu_800297B8(actor, arg3);
            }
            break;
        case 4:
            if (arg1 == 1) {
                func_menu_80029BB4(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_80029AAC(actor, sp18);
            } else {
                func_menu_80029D30(actor, arg3);
            }
            break;
        case 5:
            if (arg1 == 1) {
                func_menu_8002A088(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_80029EF8(actor, sp18);
            } else {
                func_menu_8002A36C(actor, arg3);
            }
            break;
        case 6:
            if (arg1 == 1) {
                func_menu_8002A638(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002A468(actor, sp18);
            } else {
                func_menu_8002AB80(actor, arg3);
            }
            break;
        case 7:
            if (arg1 == 1) {
                func_menu_8002B708(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002ADC8(actor, sp18);
            } else {
                func_menu_8002C0C8(actor, arg3);
            }
            break;
        case 11:
            if (arg1 == 1) {
                func_menu_8002C634(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002C584(actor, sp18);
            } else {
                func_menu_8002C91C(actor, arg3);
            }
            break;
        case 8:
            if (arg1 == 1) {
                func_menu_8002D520(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002CFA4(actor, sp18);
            } else {
                func_menu_8002D7EC(actor, arg3);
            }
            break;
        case 9:
            if (arg1 == 1) {
                func_menu_8002DBDC(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002D8AC(actor, sp18);
            } else {
                func_menu_8002DEE8(actor, arg3);
            }
            break;
        case 10:
            if (arg1 == 1) {
                func_menu_8002E420(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002DFA8(actor, sp18);
            } else {
                func_menu_8002E8B8(actor, arg3);
            }
            break;
        case 12:
            if (arg1 == 1) {
                func_menu_8002F284(actor, dl);
                return;
            }
            if (arg1 == 2) {
                func_menu_8002EF68(actor, sp18);
            } else {
                func_menu_8002F6C8(actor, arg3);
            }
            break;
        default:
            break;
    }
    if (D_menu_80033F50 > 0) {
        D_menu_80033F50--;
    }
    D_menu_80033670 = sp18;
    return dl;
}

extern int func_menu_80030C14(); // TODO: Signature

typedef struct {
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
} Struct80717D84_80030894;

void func_menu_80030894(MenuAdditionalActorData *arg0, void *sprite, s32 x, s32 y, f32 scale, u8 arg5, s32 arg6) {
    Struct80717D84 *sp3C;
    Struct80717D84_80030894 *temp_v0;
    f32 dX;
    f32 dY;
    f32 d;
    f32 temp_f2;

    func_global_asm_80714998(arg5);
    func_global_asm_8071495C();
    func_global_asm_807149FC(-1);
    func_global_asm_80714950((s32)arg0);
    func_global_asm_8071498C(func_menu_80030C14);
    func_global_asm_80714A28(1);
    sp3C = drawSpriteAtPosition(sprite, scale, x, y, -10.0f);
    temp_v0 = malloc(sizeof(Struct80717D84_80030894));
    sp3C->unk384 = temp_v0;
    temp_v0->unk0 = arg6;
    temp_v0->unk4 = arg0->unk15;
    temp_v0->unk8 = sp3C->unk340;
    temp_v0->unkC = sp3C->unk344;
    switch (arg6) {
        case 14:
            sp3C->unk360 = -sp3C->unk360;
            // fallthrough
        case 0:
        case 1:
        case 11:
        case 12:
        case 13:
        case 16:
        case 17:
        case 19:
            dX = 640.0f - temp_v0->unk8;
            dY = 480.0f - temp_v0->unkC;
            d = sqrtf(SQ(dX) + SQ(dY));
            temp_f2 = 1040.0f - d;
            temp_v0->unk10 = -(dX / d) * temp_f2;
            temp_v0->unk14 = -(dY / d) * temp_f2;
            temp_v0->unk18 = sp3C->unk360;
            break;
        case 2:
        case 3:
        case 10:
            temp_v0->unk8 = x;
            temp_v0->unk10 = scale;
            temp_v0->unk14 = 0.0f;
            break;
        case 15:
            temp_v0->unk8 = x;
            break;
        default:
            temp_v0->unk10 = scale;
            temp_v0->unk14 = 0.0f;
            break;
    }
    if (D_menu_80033F38 == 0) {
        sp3C->unk36A = 0x80;
        sp3C->unk36B = 0x80;
        sp3C->unk36C = 0x80;
    }
    D_menu_80033F38 = 1;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80030A90_malloc;

void func_menu_80030A90(Struct80717D84 *arg0, s32 arg1) {
    s32 temp;
    s16 sp72;
    float sp30[4][4];
    Struct80030A90_malloc *var_v0;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0x10);
        var_v0 = arg0->unk384;
        sp72 = func_global_asm_806119A0() * 0x10;
        var_v0->unk0 = func_global_asm_80612794(sp72) * 60.0f;
        var_v0->unk4 = func_global_asm_80612790(sp72) * 60.0f;
        var_v0->unk8 = func_global_asm_806119FC() * 3.141f;
        arg0->unk340 += (var_v0->unk0 * 3.0f);
        arg0->unk344 += (var_v0->unk4 * 3.0f);
        if (var_v0->unk0 > 0.0f) {
            var_v0->unkC = 0.3f;
        } else {
            var_v0->unkC = -0.3f;
        }
    }
    var_v0 = arg0->unk384;
    arg0->unk340 += var_v0->unk0;
    arg0->unk344 += var_v0->unk4;
    var_v0->unk8 += var_v0->unkC;
    guRotateF(sp30, var_v0->unk8, 0, 0, 1.0f);
    guMtxF2L(sp30, &arg0->unk128[D_global_asm_807444FC]);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80030C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8003155C.s")

s32 func_menu_800317E8(Struct800317E8 *arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, s32 arg5, s8 arg6, f32 arg7) {
    f32 var_f0;
    f32 var_f18;
    s32 var_v1;

    arg1 -= 160.0f;
    arg2 -= 120.0f;
    var_f18 = sqrtf((arg1 * arg1) + (arg2 * arg2));
    if (var_f18 < 20.0f) {
        var_f18 = 20.0f;
    }
    var_v1 = arg0->unk17;
    if (arg0->unk4 != 0.0f) {
        if (arg0->unk4 > 0.5f) {
            var_v1++;
        }
        if (var_v1 >= arg5) {
            var_v1 -= arg5;
        }
    }
    var_f0 = arg0->unk0 * 0.5f;
    if (arg6 == 1) {
        var_f0 += arg0->unk4;
    }
    var_f0 = (2.0f * var_f0) - 1.0f;
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    var_f0 = 1.0f - var_f0;
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    var_f0 = ((100.0f / var_f18) * var_f0 * arg7) + 1.0f;
    *arg3 = (arg1 * var_f0) + 160.0f;
    *arg4 = (arg2 * var_f0) + 120.0f;
    *arg4 = (arg2 * var_f0) + 120.0f + arg0->unkC;
    return var_v1;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80031980;

f32 func_menu_80031980(Struct80031980 *arg0, f32 arg1, f32 *arg2) {
    f32 sp[4];

    sp[0] = arg0->unkC + (((arg0->unk0 + arg0->unk0) + ((-2.0f) * arg0->unk4)) + arg0->unk8);
    sp[1] = ((((-3.0f) * arg0->unk0) + (3.0f * arg0->unk4)) + ((-2.0f) * arg0->unk8)) - (*arg0).unkC;
    sp[2] = arg0->unk8;
    sp[3] = arg0->unk0;
    if (arg2 != NULL) {
        *arg2 = ((((3.0f * sp[0]) * arg1) + (sp[1] + sp[1])) * arg1) + ((0, sp[2]));
    }
    return (((((sp[0] * arg1) + sp[1]) * arg1) + sp[2]) * arg1) + sp[3];
}

void func_menu_80031A5C(void) {
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            playActorAnimation(gCurrentActorPointer, 0x345);
            gCurrentActorPointer->y_rotation = 0;
            gCurrentActorPointer->control_state_progress = 1;
            playCutscene(gCurrentActorPointer, 0x13, 5);
            return;
        case 2:
            gCurrentActorPointer->control_state_progress++;
            return;
        case 4:
            if (opening_cutscene_transition == 0) {
                opening_cutscene_transition = 1;
            }
            // fallthrough
        default:
        case 1:
        case 3:
            return;
    }
}

extern s16 D_global_asm_80754CE0;
extern f32 D_menu_80033678[];
extern f32 dk_screen_transition_height;
extern s8 D_menu_80033738;

typedef struct {
    u8 unk0[0x23C - 0x0];
    u16 unk23C;
} AAD_80031B08;

void func_menu_80031B08(void) {
    AAD_80031B08 *aaD;
    s32 i;

    aaD = gCurrentActorPointer->additional_actor_data;
    dk_screen_transition_height += 4.5f;
    if (dk_screen_transition_height > 0.0f) {
        dk_screen_transition_height = 0.0f;
    }
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            gCurrentActorPointer->y_rotation = 0x800;
            gCurrentActorPointer->control_state_progress = 1;
            playActorAnimation(gCurrentActorPointer, 0x346);
            func_global_asm_8061B650(D_global_asm_807F5D10);
            dk_screen_transition_height = -35.0f;
            break;
        case 1:
            if (dk_screen_transition_height == 0.0f) {
                playActorAnimation(gCurrentActorPointer, 0x347);
                gCurrentActorPointer->control_state_progress = 2;
                aaD->unk23C = 0;
            }
            break;
        case 2:
            aaD->unk23C++;
            if (aaD->unk23C == 3) {
                playSound(0x3C, 0x61A8, 63.0f, 1.0f, 0, 0);
                D_menu_80033F50 = 3;
            }
            break;
        case 3:
            if (character_change_array->new_controller_inputs->button & 0x8000) {
                if (menu_selection_available == 1) {
                    playActorAnimation(gCurrentActorPointer, 0x348);
                    gCurrentActorPointer->control_state_progress = 4;
                    inputs_enabled_timer = 0x3C;
                } else if (menu_selection_available == -1) {
                    playSound(0x98, 0x61A8, 63.0f, 1.0f, 0, 0);
                }
            }
            break;
        case 5:
            menu_selection_speed = 0.1f;
            menu_icon_transition_scale = menu_selection_speed;
            inputs_enabled_timer = 0;
            aaD->unk23C = 0;
            gCurrentActorPointer->control_state_progress = 6;
            break;
        case 6:
        case 7:
        case 8:
            aaD->unk23C++;
            if (aaD->unk23C >= 0x3E9) {
                aaD->unk23C = 0x3E8;
            }
            if (aaD->unk23C == 8) {
                func_global_asm_8071495C();
                drawSpriteAtPosition(&D_global_asm_8071FE08, 8.3f, 160.0f, 120.0f, -10.0f);
                playSound(0x23, 0x7FFF, 63.0f, 1.0f, 0, 0);
                playSound(0x17, 0x7FFF, 63.0f, 1.0f, 0, 0);
                for (i = 0; i != 5; i++) {
                    func_global_asm_8071498C(func_menu_80030A90);
                    func_global_asm_8071495C();
                    drawSpriteAtPosition(&D_global_asm_8071FE64, 1.8f, 160.0f, 120.0f, -10.0f);
                }
            }
            if (aaD->unk23C >= 0xC) {
                global_properties_bitfield &= 0xFFFEFFFF;
            }
            break;
    }
    if (barrel_visibility_timer != 0) {
        barrel_visibility_timer -= 1;
    }
    if (gCurrentActorPointer->control_state_progress < 6) {
        if (dk_screen_transition_height > -30.0) {
            global_properties_bitfield |= 0x10000;
        } else {
            barrel_visibility_timer = 3;
        }
    }
    D_menu_80033738 = 0x14;
    gCurrentActorPointer->y_position = -dk_screen_transition_height;
    character_change_array->look_at_eye_x = gCurrentActorPointer->x_position;
    character_change_array->look_at_eye_y = ((D_menu_80033678[D_menu_80033F50] * 50.0) + (gCurrentActorPointer->y_position + 13.1f + dk_screen_transition_height)) - 0.1;
    character_change_array->look_at_eye_z = gCurrentActorPointer->z_position - 50.0f;
    character_change_array->look_at_at_x = gCurrentActorPointer->x_position;
    character_change_array->look_at_at_y = character_change_array->look_at_eye_y;
    character_change_array->look_at_at_z = 10020.0f;
    D_global_asm_80754CE0 = D_menu_80033678[D_menu_80033F50] * 400.0f;
    renderActor(gCurrentActorPointer, 0);
}

// TODO: float & stack nonsense, close
// https://decomp.me/scratch/Rb4u3
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80032024.s")

typedef struct {
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
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
} Struct8003378C;

extern Struct8003378C D_menu_8003378C;

/*
void func_menu_80032024(void) {
    MenuAdditionalActorData *MaaD;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 pad4;
    f32 sp54;
    f32 sp50;
    f32 newX;
    f32 newZ;
    s32 pad3;
    s32 pad2;
    s32 pad;

    MaaD = gCurrentActorPointer->MaaD;
    if (gPlayerPointer->control_state_progress < 6) {
        if (D_menu_80033738 == 0x14) {
            deleteActor(gCurrentActorPointer);
            D_menu_80033738++;
            spawnActor(ACTOR_BARREL_MAIN_MENU, 0xD7);
            gLastSpawnedActor->animation_state->scale_x = 0.14f;
            gLastSpawnedActor->animation_state->scale_y = 0.14f;
            gLastSpawnedActor->animation_state->scale_z = 0.14f;
        } else if (D_menu_80033738 == 0x15) {
            getBonePosition(gPlayerPointer, 2, &sp6C, &sp64, &sp5C);
            getBonePosition(gPlayerPointer, 3, &sp70, &sp68, &sp60);
            newX = (sp70 + sp6C);
            newZ = (sp60 + sp5C);
            gCurrentActorPointer->x_position = newX * 0.5f;
            gCurrentActorPointer->y_position = sp64;
            gCurrentActorPointer->z_position = newZ * 0.5f;
            MaaD->unk0 = gCurrentActorPointer->x_position;
            MaaD->unk4 = gCurrentActorPointer->y_position;
            MaaD->unk8 = gCurrentActorPointer->z_position;
            gCurrentActorPointer->y_rotation = 0;
            gCurrentActorPointer->z_rotation = 0x400;
            func_global_asm_80626F8C(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, &sp54, &sp50, 0, 1.0f, 0);
            sp50 -= 120.0f;
            if (sp50 < -35.0f && sp50 > -75.0f) {
                D_menu_8003378C.unk0 = sp50;
                D_menu_8003378C.unk44 = sp50;
            }
        }
    } else {
        gCurrentActorPointer->x_position = MaaD->unk0;
        gCurrentActorPointer->y_position = MaaD->unk4 - (menu_icon_transition_scale * 19.0f);
        gCurrentActorPointer->z_position = MaaD->unk8 - (menu_icon_transition_scale * 50.0f);
    }
    renderActor(gCurrentActorPointer, 0);
    if (barrel_visibility_timer != 0) {
        gCurrentActorPointer->object_properties_bitfield &= ~4;
    } else {
        gCurrentActorPointer->object_properties_bitfield |= 4;
    }
}
*/

s32 func_menu_800322D0(s32 fileIndex) {
    return !func_global_asm_8060C6B8(0xD, 0, 0, fileIndex);
}

extern s16 D_global_asm_807FC828[];

// Calculate game percentage
s32 func_menu_80032304(void) {
    f32 completionPercentage;

    func_global_asm_806ABE3C();
    completionPercentage = 0.0f;
    completionPercentage += ((f32)D_global_asm_807FC828[0] * 0.4);
    completionPercentage += ((f32)D_global_asm_807FC828[2] * 0.25);
    completionPercentage += ((f32)D_global_asm_807FC828[5] * 0.2);
    completionPercentage += ((f32)D_global_asm_807FC828[3] * 0.2);
    completionPercentage += ((f32)D_global_asm_807FC828[1] * 0.5);
    completionPercentage += ((f32)D_global_asm_807FC828[4] * 0.5);
    completionPercentage += ((f32)D_global_asm_807FC828[6] * 0.5);
    if (D_global_asm_807FC828[0] == 201) {
        completionPercentage -= 0.4;
    }
    if (completionPercentage == 100.0) {
        if (isFlagSet(PERMFLAG_ITEM_ISLES_RAREWARE_GB, FLAG_TYPE_PERMANENT)) {
            if (isFlagSet(PERMFLAG_ITEM_ISLES_RAREWARE_GB, FLAG_TYPE_PERMANENT)) {
                completionPercentage += 1.0;
            }
        }
    }
    return completionPercentage;
}

void func_menu_800324CC(void) {
    s32 temp_v0;
    s32 i;

    label_string_pointer_array = malloc(101 * sizeof(s32));
    i = 0;
    while (i != 101) {
        label_string_pointer_array[i++] = getTextString(0x25, i, 0);
    }
}
