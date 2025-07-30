#include "common.h"

extern s8 D_global_asm_80750754;

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Struct80755264;

extern Struct80755264 D_global_asm_80755264[];
extern u8 D_global_asm_8077058C;
extern s32 D_global_asm_807FD9F0[];
extern u8 D_global_asm_807FDA1C;

typedef struct {
    u16 unk0;
    s16 unk2;
    s32 unk4;
} Struct807122B4;

extern Struct807122B4 *D_global_asm_807550E0;
extern u16 D_global_asm_80755308; // buttons_enabled
extern u8 D_global_asm_8075530C; // joystick_x_bits_enabled
extern u8 D_global_asm_80755310; // joystick_y_bits_enabled
extern s8 D_global_asm_80755330; // prevent_transition
extern s32 D_global_asm_80755338; // cutscene_will_play_next_map
extern s32 D_global_asm_8075533C; // cutscene_to_play_next_map
extern u8 D_global_asm_80755350;
extern s8 D_global_asm_8075536C; // Exit

extern f32 D_global_asm_807FD9EC;
extern u8 D_global_asm_807FDA1B;
extern s16 D_global_asm_807FDA1E;

extern s32 D_global_asm_807FBB68;

extern u8 D_global_asm_807FDA1A;
extern u8 D_global_asm_807FDA1C;

extern u8 D_global_asm_807FDA28;
extern s8 D_global_asm_807FDA30[];

void func_global_asm_8060AC34(OSContPad *);

void func_global_asm_8070F570(void) {
    s16 i;

    D_global_asm_807550E0->unk0 = 0;
    D_global_asm_807FDA1C = 6;
    for (i = 0; i < 0x80; i++) {
        D_global_asm_807FDA30[i] = i;
    }
    D_global_asm_807FDA1A = 0x7F;
    D_global_asm_807FDA28 = 0;
}

// Doable, needs some structs defined though
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_8070F5CC.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Struct8070FA58;

void func_global_asm_8070FA58(Struct8070FA58 *arg0) {
    f32 sp30;
    f32 temp_f2_2;
    f32 temp_f0;
    f32 temp_f2;
    s16 sp26;
    f32 sp20;
    f32 var_f12;

    temp_f0 = character_change_array->look_at_eye_z - arg0->unk1C;
    temp_f2 = character_change_array->look_at_eye_x - arg0->unk18;
    temp_f2_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    arg0->unk18 = character_change_array->look_at_eye_x;
    arg0->unk1C = character_change_array->look_at_eye_z;
    var_f12 = character_change_array->unk2C4 - arg0->unk14;
    if (3.141592741f < var_f12) {
        var_f12 = MATH_2PI_F - var_f12;
    }
    if (var_f12 < -3.141592741f) {
        var_f12 = -MATH_2PI_F - var_f12;
    }
    arg0->unk4 += ((var_f12 * 180.0f) - (0.3 * D_global_asm_807FDA1E));
    sp30 = temp_f2_2;
    arg0->unk4 += (4.0f * temp_f2_2 * func_global_asm_80612D1C(var_f12));
    sp26 = func_global_asm_80665DE0(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, character_change_array->unk21C, character_change_array->unk224);
    temp_f0 = character_change_array->look_at_eye_z - character_change_array->unk224;
    temp_f2 = character_change_array->look_at_eye_x - character_change_array->unk21C;
    sp20 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    arg0->unk4 -= (2.0 * sp20 * func_global_asm_80612794(func_global_asm_806CC10C(character_change_array->unk2C8, sp26)));
    arg0->unk14 = character_change_array->unk2C4;
}

typedef struct {
    s32 unk0;
    f32 unk4;
} Struct8070FC40_arg0;

void func_global_asm_8070FC40(Struct8070FC40_arg0 *arg0) {
    f32 temp2 = arg0->unk4; // TODO: Hmm...
    f32 temp = 315.0f;

    if (arg0->unk4 > temp) {
        arg0->unk4 = (arg0->unk4 - temp) + 2.0f;
    }
    if (arg0->unk4 < 2.0f) {
        arg0->unk4 = temp - arg0->unk4;
    }
    arg0->unk4 = (s32)arg0->unk4 % 320;
}

// Big, need structs
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_8070FCCC.s")

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14[0x20 - 0x14];
    s16 unk20;
    u8 unk22[0x28 - 0x22];
    f32 unk28;
    u8 unk2C[0xB0 - 0x2C];
    u8 unkB0;
    u8 unkB1;
} Struct8071006C_arg0;

u8 func_global_asm_8071006C(Struct8071006C_arg0 *arg0) {
    f32 temp;
    func_global_asm_8070FA58(arg0);
    func_global_asm_8070FC40(arg0);
    arg0->unk8 = arg0->unk4;
    if (arg0->unkB0++ >= 0xF) {
        if (arg0->unkB1 >= 0x50) {
            arg0->unkB1 -= 0x50;
        }
    }
    temp = 1.0f / ((f64)arg0->unk10 * 4.0f) * 60.0f;
    arg0->unkC += (((30.0f - ((temp) - 30.0f)) + 30.0f) * 0.2);
    return (arg0->unkC > 240.0f || arg0->unkB1 < 0x50);
}

u8 func_global_asm_80710174(Struct8071006C_arg0 *arg0) {
    f32 temp;
    func_global_asm_8070FA58(arg0);
    arg0->unk4 += func_global_asm_80612794(arg0->unk20) * arg0->unk28;
    func_global_asm_8070FC40(arg0);
    arg0->unk8 = arg0->unk4;
    arg0->unk20 += 0x14;
    temp = 1.0 / (arg0->unk10 * 4.0) * 8.0;
    arg0->unkC = arg0->unkC + ((10.0f - (((temp) - 10.0f)) + 10.0f) * 0.25);
    if (arg0->unkB0++ >= 0x3D) {
        if (arg0->unkB1 >= 0xA) {
            arg0->unkB1 -= 0xA;
        }
    }
    return (arg0->unkC > 240.0f || arg0->unkB1 < 0xA);
}

u8 func_global_asm_807102AC(Struct8071006C_arg0 *arg0) {
    s32 var_v1;
    f32 temp;

    func_global_asm_8070FA58(arg0);
    arg0->unk4 += (func_global_asm_80612794(arg0->unk20) * arg0->unk28);
    func_global_asm_8070FC40(arg0);
    arg0->unk8 = arg0->unk4;
    temp = ((1.0 / (arg0->unk10 * 3.0)) * 8.0);
    arg0->unkC = arg0->unkC + ((10.0f - (((temp) - 10.0f)) + 10.0f) * 0.07);
    arg0->unk20 += 0x32;
    if (arg0->unkB0++ >= 0x6F) {
        if (arg0->unkB1 >= 0xA) {
            arg0->unkB1 -= 0xA;
        }
    }
    var_v1 = 0;
    if (D_global_asm_807FD9EC < arg0->unkC) {
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        var_v1 = arg0->unkB1 < 0xA;
    }
    return var_v1;
}

// regalloc, permutable
// https://decomp.me/scratch/sk00B
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_807103E0.s")

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    f32 unk28;
    u8 unk2C[0xB1 - 0x2C];
    u8 unkB1;
    u8 unkB2;
    u8 unkB3;
} Struct807103E0;

/*
u8 func_global_asm_807103E0(Struct807103E0 *arg0) {
    func_global_asm_8070FA58(arg0); // TODO: Consolidate structs?
    arg0->unk4 += func_global_asm_80612794(arg0->unk22 * 0.5) * (f32)(arg0->unk28 * 0.05);
    func_global_asm_8070FC40(arg0); // TODO: Consolidate structs?
    arg0->unk8 = arg0->unk4;
    arg0->unkC += (1.0 + func_global_asm_80612794(arg0->unk22)) * (f32)(1.0 + (arg0->unk20 * 0.08));
    arg0->unk22 += 0x64;
    // Problem is here, end of the line
    arg0->unk24 = (func_global_asm_80612794(arg0->unk22 * 0.5) * 0.5 + 0.5) * ((arg0->unkB3 * 4) - (arg0->unkB3 * -4)) + (arg0->unkB3 * -4);
    if (((ABS(arg0->unk10)) * 140.0f) < arg0->unkC) {
        if (arg0->unkB1 >= 0xA) {
            arg0->unkB1 -= 0xA;
        }
    }
    return D_global_asm_807FD9EC < arg0->unkC || arg0->unkB1 < 0xA;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_807105D4.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80710CA0.s")

// rodata, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80711410.s")

extern f64 D_global_asm_8075E550;
extern f64 D_global_asm_8075E558;
extern f64 D_global_asm_8075E560;
extern f64 D_global_asm_8075E568;
extern f32 *D_global_asm_8076A0B4;

/*
void func_global_asm_80711410(f32 arg0, s16 arg1, f32 arg2, s16 arg3, f32 arg4) {
    f32 temp_f22;
    f64 temp_f12;
    f64 temp_f26;
    f64 var_f0;
    s32 i;
    s32 var_s5;

    if (global_properties_bitfield & 0x10) {
        D_global_asm_807FDA1E = func_global_asm_80612D10(character_change_array->unk2C4) * arg1;
        temp_f12 = (arg0 * D_global_asm_8075E558) / D_global_asm_8075E560;
        if (D_global_asm_8075E550 < temp_f12) {
            var_f0 = D_global_asm_8075E550;
        } else {
            var_f0 = temp_f12;
        }
        D_global_asm_8077058C = var_f0 * arg2;
        if (arg0 < 1.0) {
            if ((RandClamp(32767) % 100) < (arg0 * 100.0f)) {
                var_s5 = 1;
            } else {
                var_s5 = 0;
            }
        } else {
            var_s5 = arg0;
        }
        D_global_asm_807FDA1B = (*D_global_asm_8076A0B4 * 100.0f) + 100.0f;
        temp_f26 = D_global_asm_8075E568;
        for (i = 0; i != var_s5; i++) {
            temp_f22 = RandClamp(32767) % 320;
            func_global_asm_8070F5CC(0, arg3, (((RandClamp(32767) % 125) / 800.0) + temp_f26) * 2.5 * arg4, temp_f22, -0xA, (90.0f * arg4));
        }
        if (D_global_asm_807550E0->unk0 != 0) {
            addActorToTextOverlayRenderArray(func_global_asm_80710CA0, NULL, 1);
        }
    }
}
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80711950.s")

/*
void func_global_asm_80711950(f32 arg0, s16 arg1, s16 arg2) {
    f64 var_f18;
    s32 var_s0;
    s32 var_s4;
    u32 temp_hi;
    u32 r;
    f32 temp;

    if (global_properties_bitfield & 0x10) {
        D_global_asm_807FDA1E = (func_global_asm_80612D10(character_change_array->unk2C4) * (f32) arg1);
        if (arg0 < 1.0) {
            temp = arg0 * 100.0f;
            r = (func_global_asm_806119A0() / 10000U) % 100U;
            if (temp > r) {
                var_s4 = 1;
            } else {
                var_s4 = 0;
            }
        } else {
            var_s4 = arg0;
        }
        D_global_asm_807FDA1B = 0xFF;
        var_s0 = 0;
        for (var_s0 = 0; var_s0 < var_s4; var_s0++) {
            var_f18 = (func_global_asm_806119A0() / 10000U) % 125U;
            r = (func_global_asm_806119A0() / 10000U) % 320U;
            func_global_asm_8070F5CC(1, arg2, ((f32) (var_f18 / 1000.0) + 0.075), r, -0xA, 0xC8U);
        }
        if (D_global_asm_807550E0->unk0 != 0) {
            addActorToTextOverlayRenderArray(func_global_asm_80710CA0, NULL, 1U);
        }
    }
}
*/


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80711BD0.s")

// close, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80711F90.s")

/*
void func_global_asm_80711F90(f32 arg0, s16 arg1, s32 arg2, s16 arg3, f32 arg4) {
    f32 temp_f22;
    s32 i;
    s32 var_s4;

    D_global_asm_807FDA1E = func_global_asm_80612D10(character_change_array->unk2C4) * arg1;
    if (arg0 < 1.0) {
        if ((RandClamp(32767) % 100) < (arg0 * 100.0f)) {
            var_s4 = 1;
        } else {
            var_s4 = 0;
        }
    } else {
        var_s4 = arg0;
    }
    D_global_asm_807FDA1B = 0xFF;
    for (i = 0; i < var_s4; i++) {
        temp_f22 = RandClamp(0x7FFF) % 320;
        func_global_asm_8070F5CC(2, arg3, (((RandClamp(0x7FFF) % 125) / 800.0) + 0.1) * 2.5 * arg4, temp_f22, -0xA, 0xFF);
    }
    if (D_global_asm_807550E0->unk0 != 0) {
        addActorToTextOverlayRenderArray(func_global_asm_80710CA0, NULL, 1);
    }
}
*/

s32 func_global_asm_807122B4(void) {
    s16 i;

    if (D_global_asm_807550E0->unk0 != 0) {
        D_global_asm_8077058C = D_global_asm_8077058C * 0.9;
        addActorToTextOverlayRenderArray(func_global_asm_80710CA0, NULL, 1);
        return FALSE;
    }
    if (D_global_asm_807FDA1C != 6) {
        D_global_asm_8077058C = 0;
        func_global_asm_8061134C(D_global_asm_807550E0->unk4);
        for (i = 0; i < D_global_asm_80755264[D_global_asm_807FDA1C].unk0; i++) {
            func_global_asm_8066B434(D_global_asm_807FD9F0[i], 0x34A, 0x64);
        }
        D_global_asm_807FDA1C = 6;
        D_global_asm_807FDA28 = 0;
        return TRUE;
    }
    // BUG: Missing return?
}

void func_global_asm_80712490(Maps newMap, s32 newExit, u8 newGameMode) {
    func_global_asm_805FF378(newMap, newExit);
    game_mode = newGameMode;
}

void func_global_asm_807124B8(Maps newMap, s32 cutsceneIndex, u8 newGameMode) {
    if (!func_global_asm_80712798()) {
        func_global_asm_805FF158(0);
        func_global_asm_80712490(newMap, D_global_asm_8075536C, newGameMode);
        D_global_asm_80755338 = 1;
        D_global_asm_8075533C = cutsceneIndex;
        D_global_asm_8075536C = 0;
    }
}

void func_global_asm_80712524(Maps newMap, s32 cutsceneIndex) {
    func_global_asm_807124B8(newMap, cutsceneIndex, game_mode);
}

// getHelmTimerStartTime()
s32 func_global_asm_80712548(void) {
    // Count blueprints turned + 10
    return countSetFlags(PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK, 40, FLAG_TYPE_PERMANENT) + 10;
}

extern Struct80755340 D_global_asm_80755340;
extern u16 D_global_asm_80755358[];

void func_global_asm_80712574(void) {
    u32 i;
    s32 found;

    found = FALSE;
    D_global_asm_80755340.unk10 = 1;
    D_global_asm_80755340.unk11 = 0;
    D_global_asm_80755340.unk0 = osGetTime();
    D_global_asm_80755340.unkC = func_global_asm_80712548() * 0x3C;
    for (i = 0; i < 10 && !found; i++) {
        if (D_global_asm_80755358[i] < D_global_asm_80755340.unkC) {
            D_global_asm_80755340.unk11 = i;
            found = TRUE;
        }
    }
}

void func_global_asm_8071261C(void) {
    D_global_asm_80755350 = 0;
}

u8 func_global_asm_80712628(void) {
    return D_global_asm_80755350;
}

void func_global_asm_80712634(Maps newMap, s32 arg1) {
    func_global_asm_807124B8(newMap, arg1, GAME_MODE_DK_THEATRE);
    D_global_asm_80755330 = 0;
}

// TODO: Why can't this return s32?
int gameIsInDKTheatreMode(void) {
    return game_mode_copy == GAME_MODE_DK_THEATRE || game_mode == GAME_MODE_DK_THEATRE;
}

void func_global_asm_8071268C(void) {
    if (game_mode_copy == GAME_MODE_DK_THEATRE) {
        D_global_asm_80755330 = 1;
    }
}

void func_global_asm_807126B0(Maps newMap, s32 newExit, s32 characterIndex, s8 moves, s8 simianSlam, s8 instrument, s8 melons) {
    s32 kongIndex;

    current_character_index[0] = characterIndex;
    D_global_asm_807FC950[0].melons = melons;
    D_global_asm_807FC950[0].health = melons * 4;

    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        D_global_asm_807FC950[0].character_progress[kongIndex].moves = moves;
        D_global_asm_807FC950[0].character_progress[kongIndex].simian_slam = simianSlam;
        D_global_asm_807FC950[0].character_progress[kongIndex].instrument = instrument;
    }

    func_global_asm_80712490(newMap, newExit, GAME_MODE_MYSTERY_MENU_MINIGAME);
}

void func_global_asm_80712774(Maps newMap) {
    func_global_asm_80712490(newMap, 0, GAME_MODE_SNIDES_BONUS_GAME);
}

s32 func_global_asm_80712798(void) {
    return game_mode_copy != game_mode;
}

void func_global_asm_807127B4(void) {
    func_global_asm_805FFFC8();
    // Dummy flag to give the game over cutscene in the mystery menu
    setFlag(PERMFLAG_PROGRESS_HAS_QUIT_GAME, TRUE, FLAG_TYPE_PERMANENT);
    func_global_asm_807124B8(MAP_HELM_LEVEL_INTROS_GAME_OVER, 0x17, GAME_MODE_QUIT_GAME); // initMapFade()
}

void func_global_asm_807127F4(s32 isDKTheatre) {
    u8 newGameMode;

    if (!isDKTheatre) {
        newGameMode = GAME_MODE_END_SEQUENCE;
    } else {
        newGameMode = GAME_MODE_END_SEQUENCE_DK_THEATRE;
    }
    func_global_asm_807124B8(MAP_DK_ISLES_DK_THEATRE, 0xB, newGameMode); // initMapFade()
    D_global_asm_80750754 = -2;
}

void func_global_asm_80712830(Actor *arg0, s32 exit) {
    Actor *temp_a2; // TODO: This is just padding too... hmm
    Maps map;
    s32 stackpad;
    Maps sp20;
    s32 sp1C;

    func_global_asm_80709464(exit);
    if (D_global_asm_807FBB64 & 1) {
        arg0->control_state_progress++;
        if (D_global_asm_807FBB68 & 2) {
            // K. Rool: Reset Tiny Phase Progress Flags and Round Counter
            setFlag(TEMPFLAG_RESET_TINY_PHASE, TRUE, FLAG_TYPE_TEMPORARY);
            map = MAP_DK_ISLES_OVERWORLD;
            exit = 0xC;
        } else {
            map = MAP_TROFF_N_SCOFF;
            if (current_map == MAP_FUNGI_SPIDER) {
                map = MAP_FUNGI_REAR_PART_OF_MILL;
                exit = 1;
            } else {
                exit = 2;
            }
        }
        func_global_asm_805FF378(map, exit);
        return;
    }
    if (D_global_asm_807FBB64 & 0x400) {
        arg0->control_state_progress++;
        func_global_asm_805FF800(&sp20, &sp1C);
        func_global_asm_805FF378(sp20, sp1C);
        return;
    }
    if (cc_number_of_players >= 2) {
        func_multiplayer_80026D40(arg0, exit);
    } else {
        func_global_asm_805FF1B0(exit);
    }
}

void func_global_asm_80712944(OSContPad *arg0) {
    s32 i;
    
    func_global_asm_8060AC34(arg0); // wrapper for subdragHookFunction()
    for (i = 0; i < 4; i++) {
        arg0[i].stick_x &= D_global_asm_8075530C;
        arg0[i].stick_y &= D_global_asm_80755310;
        arg0[i].button &= D_global_asm_80755308;
    }
}

extern OSTime D_global_asm_807445B8;
extern OSTime D_global_asm_807445C0;
extern s8 D_global_asm_80746B60;
extern s32 D_global_asm_80755320;
extern s8 D_global_asm_80755324;

void func_global_asm_80712A40(void) {
    OSTime delta;

    func_global_asm_8060B6CC();
    if ((game_mode == 3) || (game_mode == 4)) {
        func_global_asm_806119F0(0x8E32B6F7U);
        D_global_asm_80746B60 = 1;
    } else {
        func_global_asm_806119F0(osGetTime());
        D_global_asm_80746B60 = 0;
    }
    D_global_asm_8075530C = 0;
    D_global_asm_80755310 = 0;
    game_mode_copy = game_mode;
    D_global_asm_80755324 = 0;
    D_global_asm_80755320 = 0;
    if (global_properties_bitfield & 2) {
        delta = osGetTime() - D_global_asm_807445C0;
        D_global_asm_807445B8 += delta;
        if (D_global_asm_80755340.unk10 != 0) {
            D_global_asm_80755340.unk0 += delta;
        }
    }
}

