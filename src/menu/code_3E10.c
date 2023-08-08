#include <ultra64.h>
#include "functions.h"


extern s8 D_global_asm_80745844;
void func_menu_80030340(Actor*, s32, s32, s32);
void func_global_asm_8061D4E4(Actor*);
extern s8 opening_cutscene_transition;
extern s8 D_global_asm_80745844;
extern f32 adventure_barrel_scale;
extern f32 adventure_icon_scale;
extern f32 battle_barrel_scale;
extern f32 battle_icon_scale;
extern f32 day_night_transition;
extern f32 foreground_shading_intensity;
extern s8 inputs_enabled_timer;
extern s8 is_in_submenu;
extern s8 is_night;
extern s8 is_raining;
extern s8 menu_cutscene_index;
extern f32 mystery_barrel_scale;
extern f32 mystery_icon_scale;
extern f32 options_barrel_scale;
extern f32 options_icon_scale;
extern f32 sound_barrel_scale;
extern f32 sound_icon_scale;
extern s16 menu_cutscene_timer;
extern s16 D_menu_800336A4[];
extern void *D_global_asm_807211D0;
extern void *D_global_asm_80721444;
extern void *D_global_asm_80721094;
extern void *D_global_asm_807210EC;
extern void *D_global_asm_80721170;
extern s32 D_global_asm_80720C34;
extern s8 current_file_selection;
extern u8 D_menu_80033F38;
extern void *D_global_asm_8072052C;
extern s32 D_global_asm_807204BC;
extern s32 D_global_asm_80720CF0;
extern s32 D_global_asm_80720D14;
extern s32 D_global_asm_80720D14;
extern s32 D_global_asm_80720C34;
extern s32 D_global_asm_80720D38;
extern f32 D_menu_80033D50;
extern f32 D_menu_80033D58;
extern s8 D_menu_80033F50;
extern f32 D_menu_80033D54;
extern f32 menu_rotation_speed;
extern f32 menu_rotation_speed_left;
extern f32 menu_rotation_speed_right;
extern s8 menu_selection_available;
extern f32 menu_icon_transition_scale;
extern f32 DK_barrel_scale;

void func_menu_80030894(MenuAdditionalActorData*,s32,u16,u16,f32,u8,u8); // Param 1 is ActorAdditionalData

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
        func_menu_80030340(arg0, 0, 0, 0);
        func_global_asm_8061D4E4(D_global_asm_807F5D10);
        playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        opening_cutscene_transition = 0;
    }
}

s32 func_menu_80027F34(s32 arg0, s32 arg1) {
    return arg1;
}

void func_menu_80027F40(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    player_pointer->x_position = 109.0f;
    player_pointer->y_position = 6.0f;
    player_pointer->z_position = 55.0f;
    MaaD->unk0 = 0.0f;
    opening_cutscene_transition = 0;
    global_properties_bitfield |= 0x10000;
}

// doable, close
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80027FAC.s")

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct800337FC;

extern s16 D_menu_800336A0;
extern s16 D_menu_80033724[];
extern Struct800337FC D_menu_800337FC;
extern f64 D_menu_80033C10;
extern f64 D_menu_80033C18;
extern f32 D_menu_80033C20;
extern f64 D_menu_80033C28;
extern f64 D_menu_80033C30;
extern f64 D_menu_80033C38;
extern f64 D_menu_80033C40;
extern f64 D_menu_80033C48;
extern f64 D_menu_80033C50;
extern f64 D_menu_80033C58;
extern f32 menu_selection_speed;

void func_menu_8002FC1C(Actor*, MenuAdditionalActorData*, s32);
void func_menu_8002FD38(MenuAdditionalActorData*, s32, s32);
void func_menu_8002FE08(MenuAdditionalActorData*, s32);

/*
void func_menu_80027FAC(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD; // sp5C
    Struct800337FC sp54; // sp54
    Actor *sp50;
    s8 sp4F; // sp4F
    s16 temp_a1;
    f32 var_f16;
    s16 initialMax;
    s32 var_v0;
    s16 i;
    s16 max;
    s32 var_v0_2;
    s8 temp;

    MaaD = arg0->additional_actor_data;
    sp54 = D_menu_800337FC;
    sp4F = 0;
    if (inputs_enabled_timer > 0) {
        inputs_enabled_timer -= 1;
    } else {
        inputs_enabled_timer = 0;
    }
    menu_selection_available = 0;
    if (MaaD->unk0 == 0.0f) {
        if (menu_icon_transition_scale == 0.0f) {
            if (inputs_enabled_timer == 0) {
                if (MaaD->unk4 == 0.0f) {
                    menu_selection_available = 1;
                    temp = MaaD->unk17;
                    switch (temp) {
                        case 2:
                            if (!isFlagSet(0x1C, FLAG_TYPE_GLOBAL)) {
                                menu_selection_available = -1;
                            }
                            break;
                        case 3:
                            if (!isFlagSet(0, FLAG_TYPE_GLOBAL)) {
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
            temp = MaaD->unk17;
            MaaD->unk16 = 0;
            switch (temp) {
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
        temp_a1 = D_menu_800336A4[menu_cutscene_index];
        switch (temp_a1) {
            case -5:
                menu_cutscene_index += 2;
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index];
                is_night = 0;
                break;
            case -4:
                menu_cutscene_index += 2;
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index];
                is_night = 1;
                break;
            case -3:
                menu_cutscene_index += 2;
                sp4F = -1;
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index];
                break;
            case -2:
                menu_cutscene_index += 2;
                sp4F = 1;
                menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index];
                break;
            default:
                if (temp_a1 < -5) {
                    if (inputs_enabled_timer == 0) {
                        func_global_asm_80614EBC(player_pointer, D_menu_80033724[-6 - temp_a1]);
                    }
                    menu_cutscene_index += 2;
                    menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index];
                } else if (temp_a1 >= 0) {
                    playCutscene(NULL, temp_a1, 1);
                    menu_cutscene_index += 2;
                    menu_cutscene_timer = D_menu_800336A4[menu_cutscene_index];
                } else {
                    max = func_global_asm_806119FC() * 10.0f;
                    menu_cutscene_timer = (func_global_asm_806119A0() & 0x7F) + 300;
                    menu_cutscene_index = 0;
                    if (max >= 0xB) {
                        max = 0;
                    }
                    var_v0 = 1 << max;
                    initialMax = max;
                    if (D_menu_800336A0 & var_v0) {
                        do {
                            max++;
                            if (max == 0xB) {
                                max = 0;
                            }
                            var_v0 = 1 << max;
                            if (max == initialMax) {
                                D_menu_800336A0 = 0;
                            }
                        } while (D_menu_800336A0 & var_v0);
                    }
                    D_menu_800336A0 |= var_v0;
                    for (i = 0; i != max; i++) {
                        while (D_menu_800336A4[menu_cutscene_index] != -1) {
                            menu_cutscene_index++;
                        }
                        menu_cutscene_index += 1;
                    }
                }
                break;
        }
    }
    if (sp4F != 0) {
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
        day_night_transition = day_night_transition + D_menu_80033C10;
        if (day_night_transition > 1.0) {
            day_night_transition = 1.0f;
        }
    } else {
        var_f16 = 1.0f;
        if (day_night_transition > 0.0) {
            day_night_transition -= D_menu_80033C18;
        } else if (is_raining) {
            var_f16 = D_menu_80033C20;
        }
    }
    foreground_shading_intensity += ((var_f16 - foreground_shading_intensity) * D_menu_80033C28);
    func_global_asm_80659670((foreground_shading_intensity * D_menu_80033C30) + D_menu_80033C38, (foreground_shading_intensity * D_menu_80033C40) + D_menu_80033C48, (foreground_shading_intensity * D_menu_80033C50) + D_menu_80033C58, -1);
    func_global_asm_80708574(day_night_transition);
}
*/

// Displaylist stuff, stack
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_800286C8.s")

s32 *label_string_pointer_array;
extern f32 text_label_scale;
extern f32 text_transition_speed;

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
Gfx *func_global_asm_806FC530(Gfx*, s16, s16, s16, void *, s32);

/*
Gfx *func_menu_800286C8(Actor *arg0, Gfx *dl) {
    s32 pad2;
    s32 spD0;
    s32 pad;
    void *aaD = arg0->additional_actor_data;
    f32 spC4;
    f32 spC0;
    HeapHeader *sp38; // BC, needs to be 38
    f32 sp7C[4][4];
    f32 sp3C[4][4];

    global_properties_bitfield |= 0x10;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    spD0 = func_menu_800317E8(aaD, 160.0f, 20.0f, &spC4, &spC0, 5, 1, text_transition_speed);
    sp38 = malloc(0x40);
    func_global_asm_8061134C(sp38);
    func_menu_80008580(&sp7C, text_label_scale, text_label_scale, 1.0f);
    func_menu_80005D80(&sp3C, spC4 * 4.0, spC0 * 4.0, 0);
    func_menu_800088B0(&sp7C, &sp3C, &sp7C);
    func_menu_8000A6C0(&sp7C, sp38);
    gSPMatrix(dl++, sp38, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return func_global_asm_806FC530(dl, 1, 0, 0, label_string_pointer_array[spD0], 0x80);
}
*/

s8 current_menu_selection;

// TODO: Might be a fake match since func_menu_80030894 probably takes a void* as an arg instead of s32
// We'll see when .rodata and .data shake out I guess...
void func_menu_80028834(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD;

    MaaD = arg0->MaaD;
    is_in_submenu = 0;
    inputs_enabled_timer = 0;
    player_pointer->control_state = 0x85;
    player_pointer->control_state_progress = 0;
    D_global_asm_80745844 = func_global_asm_8060C6B8(0x1E, 0, 0, 0);
    func_menu_80027E10();
    MaaD->unk17 = current_menu_selection;
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80721444, 0, 0, adventure_barrel_scale, 2, 0x12);
    func_menu_80030894(MaaD, &D_global_asm_80721444, 1, 0, options_barrel_scale, 2, 0x12);
    func_menu_80030894(MaaD, &D_global_asm_80721444, 2, 0, mystery_barrel_scale, 2, 0x12);
    func_menu_80030894(MaaD, &D_global_asm_80721444, 3, 0, battle_barrel_scale, 2, 0x12);
    func_menu_80030894(MaaD, &D_global_asm_80721444, 4, 0, sound_barrel_scale, 2, 0x12);
    func_menu_80030894(MaaD, &D_global_asm_8072052C, 0, 0, adventure_icon_scale, 2, 6);
    func_menu_80030894(MaaD, &D_global_asm_807211D0, 1, 0, options_icon_scale, 2, 6);
    // Is the mystery menu not unlocked?
    if (!isFlagSet(0, FLAG_TYPE_GLOBAL)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_80721094, 2, 0, mystery_icon_scale, 2, 7);
    // Is the multiplayer menu not unlocked?
    if (!isFlagSet(0x1C, FLAG_TYPE_GLOBAL)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_807210EC, 3, 0, battle_icon_scale, 2, 6);
    func_menu_80030894(MaaD, &D_global_asm_80721170, 4, 0, sound_icon_scale, 2, 6);
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    player_pointer->x_position = 700.0f;
    player_pointer->y_position = 100.0f;
    player_pointer->z_position = 70.0f;
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

extern char *D_menu_80033B30;
extern char *D_menu_80033B34;
extern char *D_menu_80033B38;
extern f32 D_menu_80033C90;
s32 func_menu_800322D0(s32);

Gfx *func_global_asm_806ABB98(Gfx*, s16, s16, f32, void*);

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
    s32 sp2C;

    global_properties_bitfield &= ~0x10;
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    sp100 = func_menu_800317E8(aaD, 160.0f, 15.0f, &spFC, &spF8, 4, 1, D_menu_80033C90);
    if (sp100 == 2) {
        func_dk64_boot_800031E0(&sp2C, &D_menu_80033B30, label_string_pointer_array[5]);
    } else {
        if (sp100 == 3) {
            sp100 = 2;
        }
        if (func_menu_800322D0(sp100) != 0) {
            func_dk64_boot_800031E0(&sp2C, &D_menu_80033B34, label_string_pointer_array[6]);
        } else {
            func_dk64_boot_800031E0(&sp2C, &D_menu_80033B38, label_string_pointer_array[7], sp100 + 1);
        }
    }
    return func_global_asm_806ABB98(dl, spFC * 4.0f, spF8 * 4.0f, 0.600000023842f, &sp2C);
}

void func_menu_80028EA8(Actor *arg0, s32 arg1) {
    PlayerAdditionalActorData* PaaD;

    PaaD = arg0->PaaD; // TODO: Probably MaaD
    PaaD->unk17 = current_file_selection;
    func_menu_80030894(PaaD, &D_global_asm_80720C34, 0xA0, 0x78, 0.75f, 2, 4);
    arg1 = &D_global_asm_8072052C;
    if (func_menu_800322D0(0)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(PaaD, arg1, 0, 0, 1.0f, 2, 2);
    if (func_menu_800322D0(1)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(PaaD, arg1, 1, 0, 1.0f, 2, 2);
    if (func_menu_800322D0(2)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(PaaD, arg1, 3, 0, 1.0f, 2, 2);
    func_menu_80030894(PaaD, &D_global_asm_807204BC, 2, 0, 1.0f, 2, 2);
    func_menu_80030894(PaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(PaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
}

void func_menu_8002907C(void);

extern u8 D_menu_80033818; // Current input index
extern u16 D_menu_8003381C[] = {U_JPAD, L_JPAD, U_JPAD, D_JPAD, R_JPAD, D_JPAD, Z_TRIG}; // Required input sequence
extern s8 D_global_asm_807563B4; // Enable stack trace upon crash

// Button code on controller to enable stack trace upon crash
// Accessible from the sound menu
void func_menu_8002907C(void) {
    u8 progress = D_menu_80033818;
    if (D_menu_8003381C[D_menu_80033818] == *(u16*)(&newly_pressed_input+0)) {
        D_menu_80033818 = D_menu_80033818 + 1;
        if (D_menu_80033818 > 6U) {
            D_global_asm_807563B4 = TRUE;
            playSound(0x23C, 0x7FFF, 63.0f, 1.0f, 0, 0);
            D_menu_80033818 = 0;
        }
    } else {
        if (*(u16*)(&newly_pressed_input + 0) != 0) {
            D_menu_80033818 = 0;
        }
    }
}

void func_menu_8002FC1C(Actor *, MenuAdditionalActorData *, s32);
void func_global_asm_8060AA58(s32);

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

s32 func_menu_800297A8(s32 arg0) {
    return arg0 + 0x1EFF0;
}

// Suspect, CRC, polymorphic code? Tamper protection?
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_800297B8.s")

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

// Displaylist stuff, close
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80029BB4.s")

extern s32 D_menu_80033B64;
extern s32 D_menu_80033B68;
extern f32 D_menu_80033CB0;

/*
Gfx *func_menu_80029BB4(Actor *arg0, Gfx *dl) {
    s32 sp120;
    s32 pad118;
    s32 pad114;
    f32 sp110;
    f32 sp10C;
    s32 pad108;
    s32 pad104;
    s32 pad100;
    s16 spFE;
    s16 temp_f4;
    s32 padF8;
    f32 temp3[4][4];
    f32 temp2[4][4];
    f32 temp[4][4];
    s32 sp34;
    void *aaD = arg0->additional_actor_data;

    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    sp120 = func_menu_800317E8(aaD, 160.0f, 25.0f, &sp110, &sp10C, 3, 1, D_menu_80033CB0);
    temp_f4 = sp10C * 4.0f;
    spFE = sp110 * 4.0f;
    if (func_menu_800322D0(sp120) != 0) {
        func_dk64_boot_800031E0(&sp34, &D_menu_80033B64, label_string_pointer_array[6]);
    } else {
        func_dk64_boot_800031E0(&sp34, &D_menu_80033B68, label_string_pointer_array[7], sp120 + 1);
    }
    dl = func_global_asm_806ABB98(dl, spFE, temp_f4, 0.6f, &sp34);
    return func_global_asm_806ABB98(dl, sp110 * 4.0f, temp_f4 - 0x3C, 0.6f, label_string_pointer_array[8]);
}
*/

// TODO: Might be a fake match since func_menu_80030894 probably takes a void* as an arg instead of s32
// We'll see when .rodata and .data shake out I guess...
void func_menu_80029D30(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    s32 temp;

    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    if (func_menu_800322D0(0)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_8072052C, 0, 0, 1.0f, 2, 3);
    if (func_menu_800322D0(1)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_8072052C, 1, 0, 1.0f, 2, 3);
    if (func_menu_800322D0(2)) {
        D_menu_80033F38 = 0;
    }
    func_menu_80030894(MaaD, &D_global_asm_8072052C, 2, 0, 1.0f, 2, 3);
    func_menu_80030894(MaaD, &D_global_asm_807204BC, 0xA0, 0x78, 1.0f, 2, 4);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0xD2, 0.75f, 2, 0);
}

extern void* D_global_asm_8071FBC8;
extern void* D_global_asm_8071FE08;
extern s8 D_menu_80033FAC;

void func_global_asm_8060C830(u8, s32);

void func_menu_80029EF8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;
    if ((MaaD->unk0 == 0.0f) && (MaaD->unk4 == 0.0f)) {
        if (arg1 & 1) {
            if ((arg1 & 8) && (D_menu_80033FAC != 0)) {
                func_global_asm_8071495C();
                func_global_asm_80714CC0(&D_global_asm_8071FBC8, 10.3f, 240.0f, 120.0f, -10.0f);
                func_global_asm_8071495C();
                func_global_asm_80714CC0(&D_global_asm_8071FE08, 10.3f, 240.0f, 120.0f, -10.0f);
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

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002A088.s")

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
                    D_global_asm_80744538 += 1;
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

// close
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002AB80.s")

extern s8 D_global_asm_8076A0D6;

/*
void func_menu_8002AB80(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *temp_s0;
    Struct8076A0E8 *var_v0;
    s32 var_s0;
    s32 i;

    temp_s0 = arg0->additional_actor_data;
    temp_s0->unk17 = D_global_asm_8076A0D6;
    func_menu_80030894(temp_s0, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s0, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s0, &D_global_asm_80720C34, 0xA0, 0x78, 0.75f, 2, 4);
    // TODO: This loop is the problem
    for (i = 0; i < 6; i++) {
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            D_global_asm_8076A0E8[i].unk0[var_s0] = -1;
        }
    }
    for (var_s0 = 0; var_s0 < 4; var_s0++) {
        if (var_s0 == 0) {
            func_menu_8002AA98(var_s0, var_s0);
        } else {
            D_global_asm_8076A0E4[var_s0] = -0x80;
            func_menu_8002AB28(var_s0);
        }
    }
}
*/

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
extern f32 D_menu_80033CDC;
extern f32 D_menu_80033CE0;
extern f32 D_menu_80033CE4;
extern s8 D_menu_80033FAD;
extern s8 D_menu_80033FAE;
extern s8 D_menu_80033FAF;
extern s32 D_global_asm_80720D5C;
extern s32 D_global_asm_80720D80;
extern s32 D_global_asm_807211AC;
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

void func_menu_8002F8EC();

void func_menu_8002C0C8(Actor *arg0, s32 arg1) {
    s32 var_s1;
    s32 i;
    AAD_menu_8002C0C8 *temp_s6;
    AAD_MultiplayerMenuKong *temp_v1;

    temp_s6 = arg0->additional_actor_data;
    func_menu_8002F8EC();
    D_menu_80033FAF = 1;
    var_s1 = 0x1D;
    for (i = 1; i < 5; i++) {
        if (isFlagSet(var_s1, 1) != 0) {
            D_menu_80033FAF |= 1 << i;
        }
        var_s1 += 1;
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
        func_global_asm_80677FA8(ACTOR_MAIN_MENU_MULTIPLAYER_KONG, D_menu_8003386C[D_global_asm_8076A0E4[i] & 0x7F]);
        temp = D_global_asm_807FBB44->unk17C;
        temp->unk0_s16[0] = D_menu_8003386C[D_global_asm_8076A0E4[i] & 0x7F];
        D_global_asm_807FBB44->control_state = i;
        D_global_asm_807FBB44->control_state_progress = D_global_asm_8076A0E4[i] & 0x7F;
        temp_v1 = D_global_asm_807FBB44->additional_actor_data;
        temp_v1->unk0 = arg0;
        temp_v1->unk8 = 0;
    }
    func_menu_80030894(temp_s6, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_80720C34, 0xA0, 0x7D, 0.75f, 2, 4);
    func_menu_80030894(temp_s6, &D_global_asm_80720D80, 0xA0, 0x10, 0.5f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_807211AC, 0xA0, 0xDC, 0.75f, 2, 0);
    func_menu_80030894(temp_s6, &D_global_asm_807211D0, 1, 1, D_menu_80033CDC, 2, 0xF);
    func_menu_80030894(temp_s6, &D_global_asm_807211D0, 2, 2, D_menu_80033CE0, 2, 0xF);
    func_menu_80030894(temp_s6, &D_global_asm_807211D0, 3, 3, D_menu_80033CE4, 2, 0xF);
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

// Weird negative struct offset stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002C91C.s")

// TODO: Huge, very doable, need energy
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002CB18.s")

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002CFA4.s")

extern s16 D_menu_80033670;
extern s8 D_global_asm_8074583C;
extern s8 D_global_asm_80745840;
extern s8 D_global_asm_80745844;

void func_global_asm_8060DEA8();
typedef struct MenuStruct7 {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
} MenuStruct7;
extern MenuStruct7 D_global_asm_80744548[];
extern MenuStruct7 D_global_asm_80744568[];

s32 func_global_asm_80737B58(s32, u16);
void func_global_asm_8060A398(s32);

/*
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
                        // Regalloc is here
                        D_global_asm_8074583C++;
                        playSound(0x2A0, 0x7FFF, 63.0f, 1.0f, 0, 0);
                        if (D_global_asm_8074583C > 0x28) {
                            D_global_asm_8074583C = 0x28;
                        }
                    } else if (arg1 & 0x20) {
                        // Regalloc is here
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
*/

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002D520.s")

void func_menu_8002D7EC(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0x7D, 0.75f, 2, 4);
    func_menu_80030894(MaaD, &D_global_asm_80720D38, 0xA0, 0xC8, 1.0f, 2, 0xC);
}

// Jumptable, 816 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002D8AC.s")

// Jumptable, 780 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002DBDC.s")

void func_menu_8002DEE8(Actor *arg0, s32 arg1) {
    MenuAdditionalActorData *MaaD = arg0->MaaD;

    MaaD->unk17 = 0;
    func_menu_80030894(MaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    func_menu_80030894(MaaD, &D_global_asm_80720C34, 0xA0, 0x7D, 0.75f, 2, 4);
    func_menu_80030894(MaaD, &D_global_asm_80720D38, 0xA0, 0xC8, 1.0f, 2, 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002DFA8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002E420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002E8B8.s")

void func_menu_8002ECE8(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        D_global_asm_80744548[i].unk0 = func_global_asm_8060C6B8(0x19, 0, i, 0);
        D_global_asm_80744548[i].unk2 = func_global_asm_8060C6B8(0x16, 0, i, 0);
        D_global_asm_80744548[i].unk3 = func_global_asm_8060C6B8(0x17, 0, i, 0);
        D_global_asm_80744548[i].unk4 = func_global_asm_8060C6B8(0x18, 0, i, 0);
        D_global_asm_80744548[i].unk5 = 0;
        D_global_asm_80744568[i].unk0 = func_global_asm_8060C6B8(0x1D, 0, i, 0);
        D_global_asm_80744568[i].unk2 = func_global_asm_8060C6B8(0x1A, 0, i, 0);
        D_global_asm_80744568[i].unk3 = func_global_asm_8060C6B8(0x1B, 0, i, 0);
        D_global_asm_80744568[i].unk4 = func_global_asm_8060C6B8(0x1C, 0, i, 0);
        D_global_asm_80744568[i].unk5 = 0;
    }
}

void func_menu_8002EE18(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        func_global_asm_8060C648(0x19, 0, i, 0, D_global_asm_80744548[i].unk0);
        func_global_asm_8060C648(0x16, 0, i, 0, D_global_asm_80744548[i].unk2);
        func_global_asm_8060C648(0x17, 0, i, 0, D_global_asm_80744548[i].unk3);
        func_global_asm_8060C648(0x18, 0, i, 0, D_global_asm_80744548[i].unk4);
        func_global_asm_8060C648(0x1D, 0, i, 0, D_global_asm_80744568[i].unk0);
        func_global_asm_8060C648(0x1A, 0, i, 0, D_global_asm_80744568[i].unk2);
        func_global_asm_8060C648(0x1B, 0, i, 0, D_global_asm_80744568[i].unk3);
        func_global_asm_8060C648(0x1C, 0, i, 0, D_global_asm_80744568[i].unk4);
    }
    func_global_asm_8060DEA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002EF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002F284.s")

extern s8 D_menu_80033F60;
void func_menu_8002F6C8(Actor *arg0, s32 arg1) {
    PlayerAdditionalActorData* PaaD = arg0->PaaD; // TODO: Might be MaaD

    if (D_menu_80033F60 == -1) {
        func_menu_80030894(PaaD, &D_global_asm_80720CF0, 0x122, 0xD2, 0.75f, 2, 0);
        func_menu_80030894(PaaD, &D_global_asm_80720D14, 0x23, 0xD2, 0.75f, 2, 0);
    }
}

// Doable, unrolled loop
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002F75C.s")

/*
extern s8 D_menu_800339A8;
extern s8 D_menu_80033F60;
extern s8 D_menu_80033F61;
extern s16 D_global_asm_80744518;

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

extern f32 D_menu_80033D44;

void func_menu_8002F8EC() {
    character_change_array->look_at_eye_x = player_pointer->x_position;
    character_change_array->look_at_eye_y = player_pointer->y_position + D_menu_80033D44;
    character_change_array->look_at_eye_z = player_pointer->z_position - 50.0f;
    character_change_array->look_at_at_x = player_pointer->x_position;
    character_change_array->look_at_at_y = character_change_array->look_at_eye_y;
    character_change_array->look_at_at_z = player_pointer->z_position - 100.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002F980.s")

extern s32 D_menu_800339C4; // TODO: Datatype
extern f32 D_menu_80033F44;

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
    s32 temp[2];
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
    if (D_menu_80033F44 < 0.0f) {
        var_f0 = -var_f0;
    }
    // func_menu_800317E8(0.0f, 0.5f, arg1, var_f0 + 160.0, arg7, &sp3C, &sp38, 2, 0, 2.0f);
    func_menu_800317E8(arg1, var_f0 + 160.0, arg7, &sp3C, &sp38, 2, 0, 2.0f);
    if (arg8 & (1 << var_v1)) {
        arg0 = func_global_asm_806FC530(arg0, arg5, sp3C * 4.0f, sp38 * 4.0f, arg2[var_v1], 0x81);
    } else {
        arg0 = func_global_asm_806FC530(arg0, arg5, sp3C * 4.0f, sp38 * 4.0f, &D_menu_800339C4, 0x81);
    }
    *arg6 = var_f0;
    *arg4 = var_v1;
    return arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002FB88.s")

extern f64 D_menu_80033D48;
extern f32 D_menu_80033F68[];
extern f32 D_menu_80033F80[];
extern f32 D_menu_80033F98[];

/*
// TODO: Not sure...
s32 func_menu_8002FB88(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_v1;

    temp_v1 = (arg1 & 0x7F);
    D_menu_80033F68[temp_v1] = (arg2 * 4.0f) - 32.0;
    D_menu_80033F80[temp_v1] = (arg3 * 4.0f) - 100.0;
    D_menu_80033F98[temp_v1] = arg4 * D_menu_80033D48;
    return arg0;
}
*/

void func_menu_8002FC1C(Actor *arg0, MenuAdditionalActorData *MaaD, s32 arg2) {
    if (MaaD->unk16 == 0) {
        MaaD->unk0 += D_menu_80033D50;
        if (D_menu_80033D54 < MaaD->unk0) {
            MaaD->unk0 = 1.0f;
            MaaD->unk12 = MaaD->unk13;
            MaaD->unk16 = -1;
            func_menu_80030340(arg0, 0, 0, 0);
            playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        }
    } else {
        if (MaaD->unk0 > 0.0f) {
            MaaD->unk0 -= D_menu_80033D58;
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
        menu_rotation_speed = menu_rotation_speed_left;
        MaaD->unk17--;
        MaaD->unk4 = 1.0f;
        if (MaaD->unk17 < 0) {
            MaaD->unk17 += arg1;
        }
        menu_selection_available = 0;
    } else if (arg2 & 8) {
        playSound(0x2C9, 0x7FFF, 63.0f, 1.25f, 0, 0);
        menu_rotation_speed = menu_rotation_speed_right;
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

// Jumptable, 916 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8002FEBC.s")

void func_menu_80030250(void) {

}

extern Gfx **D_1000118;
extern Mtx D_20000C0;

void func_menu_80030258(Gfx *dl, s32 arg1) {
    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    func_menu_80030340(arg1, 1, dl, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80030340.s")

// Jumptable, 508 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80030894.s")

s32 func_global_asm_806119A0();
extern f32 D_menu_80033E0C;
extern f32 D_menu_80033E10;
extern f32 D_menu_80033E14;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80030A90_malloc;

extern func_menu_80008620(void*, f32, f32, f32, f32);

void func_menu_80030A90(Struct80717D84 *arg0, s32 arg1) {
    s32 temp;
    s16 sp72;
    f32 sp30[4][4];
    Struct80030A90_malloc *var_v0;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0x10);
        var_v0 = arg0->unk384;
        sp72 = func_global_asm_806119A0() * 0x10;
        var_v0->unk0 = func_global_asm_80612794(sp72) * 60.0f;
        var_v0->unk4 = func_global_asm_80612790(sp72) * 60.0f;
        var_v0->unk8 = func_global_asm_806119FC() * D_menu_80033E0C;
        arg0->unk340 += (var_v0->unk0 * 3.0f);
        arg0->unk344 += (var_v0->unk4 * 3.0f);
        if (var_v0->unk0 > 0.0f) {
            var_v0->unkC = D_menu_80033E10;
        } else {
            var_v0->unkC = D_menu_80033E14;
        }
    }
    var_v0 = arg0->unk384;
    arg0->unk340 += var_v0->unk0;
    arg0->unk344 += var_v0->unk4;
    var_v0->unk8 += var_v0->unkC;
    func_menu_80008620(&sp30, var_v0->unk8, 0, 0, 1.0f);
    func_menu_8000A6C0(&sp30, &arg0->unk128[D_global_asm_807444FC]);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80030C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_8003155C.s")

f32 func_menu_8000AC60(f32, f32);

s32 func_menu_800317E8(Struct800317E8 *arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, s32 arg5, s8 arg6, f32 arg7) {
    f32 var_f0;
    f32 var_f18;
    s32 var_v1;

    arg1 -= 160.0f;
    arg2 -= 120.0f;
    var_f18 = func_menu_8000AC60((arg1 * arg1) + (arg2 * arg2), arg1);
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

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80031980.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80031980;

/*
f32 func_menu_80031980(Struct80031980 *arg0, f32 arg1, f32 *arg2) {
    f32 temp =  ( (2.0f * arg0->unk0) + (-2.0f * arg0->unk4) +          arg0->unk8)  + arg0->unkC;
    f32 temp2 = ((-3.0f * arg0->unk0) +  (3.0f * arg0->unk4) + (-2.0f * arg0->unk8)) - arg0->unkC;
    if (arg2 != NULL) {
        *arg2 =           arg0->unk8 + (3.0f * temp * arg1) + (2.0f * temp2 * arg1);
    }
    return arg0->unk0 +   arg0->unk8 + (      temp * arg1) + (       temp2 * arg1);
}
*/

// Jumptable, 172 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80031A5C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80031B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80032024.s")

extern s8 D_menu_80033738;

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

void func_global_asm_80626F8C(f32, f32, f32, f32*, f32*, s32, f32, s32);

/*
// TODO: Pretty close
void func_menu_80032024(void) {
    MenuAdditionalActorData *MaaD;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp54;
    f32 sp50;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 pad;

    MaaD = current_actor_pointer->MaaD;
    if (player_pointer->control_state_progress < 6) {
        if (D_menu_80033738 == 0x14) {
            func_global_asm_806782C0(current_actor_pointer);
            D_menu_80033738++;
            func_global_asm_80677FA8(ACTOR_BARREL_MAIN_MENU, 0xD7);
            temp_f0 = DK_barrel_scale;
            D_global_asm_807FBB44->animation_state->scale_x = temp_f0;
            D_global_asm_807FBB44->animation_state->scale_y = temp_f0;
            D_global_asm_807FBB44->animation_state->scale_z = temp_f0;
        } else if (D_menu_80033738 == 0x15) {
            func_global_asm_80671C0C(player_pointer, 2, &sp6C, &sp64, &sp5C);
            func_global_asm_80671C0C(player_pointer, 3, &sp70, &sp68, &sp60);
            current_actor_pointer->x_position = (sp70 + sp6C) * 0.5f;
            current_actor_pointer->y_position = sp64;
            current_actor_pointer->z_position = (sp60 + sp5C) * 0.5f;
            MaaD->unk0 = current_actor_pointer->x_position;
            MaaD->unk4 = current_actor_pointer->y_position;
            MaaD->unk8 = current_actor_pointer->z_position;
            current_actor_pointer->y_rotation = 0;
            current_actor_pointer->z_rotation = 0x400;
            func_global_asm_80626F8C(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, &sp54, &sp50, 0, 1.0f, 0);
            temp_f0_2 = sp50 - 120.0f;
            if (temp_f0_2 < -35.0f && temp_f0_2 > -75.0f) {
                D_menu_8003378C.unk0 = temp_f0_2;
                D_menu_8003378C.unk44 = temp_f0_2;
            }
        }
    } else {
        current_actor_pointer->x_position = MaaD->unk0;
        current_actor_pointer->y_position = MaaD->unk4 - (menu_icon_transition_scale * 19.0f);
        current_actor_pointer->z_position = MaaD->unk8 - (menu_icon_transition_scale * 50.0f);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
    if (barrel_visibility_timer != 0) {
        current_actor_pointer->object_properties_bitfield &= ~4;
    } else {
        current_actor_pointer->object_properties_bitfield |= 4;
    }
}
*/

s32 func_menu_800322D0(s32 arg0) {
    return !func_global_asm_8060C6B8(0xD, 0, 0, arg0);
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_3E10/func_menu_80032304.s")

extern f64 D_menu_80033ED8;
extern f64 D_menu_80033EE0;
extern s16 D_global_asm_807FC828[];

/*
// TODO: Typecast nonsense
// Calculating game percentage?
s32 func_menu_80032304(void) {
    f32 var_f0;

    func_global_asm_806ABE3C();
    var_f0 = 0.0f;
    var_f0 += (D_global_asm_807FC828[5] * D_menu_80033ED8);
    var_f0 += (D_global_asm_807FC828[2] * 0.25);
    var_f0 += (D_global_asm_807FC828[3] * D_menu_80033ED8);
    var_f0 += (D_global_asm_807FC828[1] * 0.5);
    var_f0 += (D_global_asm_807FC828[4] * 0.5);
    var_f0 += (D_global_asm_807FC828[6] * 0.5);
    var_f0 += (D_global_asm_807FC828[0] * D_menu_80033EE0);
    if (D_global_asm_807FC828[0] == 201) {
        var_f0 -= D_menu_80033EE0;
    }
    if (var_f0 == 100.0) {
        if (isFlagSet(0x12D, FLAG_TYPE_PERMANENT) != 0) {
            if (isFlagSet(0x12D, FLAG_TYPE_PERMANENT) != 0) {
                var_f0 += 1.0;
            }
        }
    }
    return var_f0;
}
*/

void func_menu_800324CC(void) {
    s32 temp_v0;
    s32 i;

    label_string_pointer_array = malloc(101 * sizeof(s32));
    i = 0;
    while (i != 101) {
        label_string_pointer_array[i++] = func_global_asm_8070E750(0x25, i, 0);
    }
}
