#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern OSTime D_global_asm_807445B8;
extern u32 D_global_asm_807445BC;

extern s8 D_global_asm_80750754;
extern s8 D_global_asm_80750AB8;
extern u8 D_global_asm_80750AC0;

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
extern s32 D_global_asm_807552EC;
extern u16 D_global_asm_80755308; // buttons_enabled
extern u8 D_global_asm_8075530C; // joystick_x_bits_enabled
extern u8 D_global_asm_80755310; // joystick_y_bits_enabled
extern u16 D_global_asm_8075531C;
extern u8 D_global_asm_80755324;
extern u8 D_global_asm_80755328; // index into D_global_asm_8075E5C0[]
extern u8 D_global_asm_8075532C;
extern s8 D_global_asm_80755330; // prevent_transition
extern s32 D_global_asm_80755334;
extern s32 D_global_asm_80755338; // cutscene_will_play_next_map
extern s32 D_global_asm_8075533C; // cutscene_to_play_next_map
extern s32 D_global_asm_80755348; // helm_timer
extern u8 D_global_asm_80755350;
extern s8 D_global_asm_8075536C; // Exit
extern Maps D_global_asm_80755384[];

// rodata
extern char D_global_asm_8075E5D4[];
extern f64 D_global_asm_8075E5B0;
extern f64 D_global_asm_8075E4E0;
extern f32 D_global_asm_8075E4D8;
extern f32 D_global_asm_8075E4C0;
extern f32 D_global_asm_8075E4C4;
extern f32 D_global_asm_8075E4C8;
extern f32 D_global_asm_8075E4CC;
extern f64 D_global_asm_8075E4D0;

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
} Struct8075E5C0;

extern const Struct8075E5C0 D_global_asm_8075E5C0[];/* = {
    {0x04, 0x00, 0x01E0},
    {0x00, 0x00, 0x0294},
    {0x01, 0x00, 0x01E0},
    {0x03, 0x00, 0x0258},
    {0x02, 0x00, 0x0258},
};*/

extern f32 D_global_asm_807FD9EC;
extern u8 D_global_asm_807FDA1B;
extern s16 D_global_asm_807FDA1E;

extern s32 D_global_asm_807FBB68;

extern u8 D_global_asm_807FDA1A;
extern u8 D_global_asm_807FDA1C;

extern u8 D_global_asm_807FDA28;
extern s8 D_global_asm_807FDA30[];

void func_global_asm_8060AC34(GlobalASMStruct12*);

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
    if (D_global_asm_8075E4C0 < var_f12) {
    // if (3.141592741f < var_f12) {
        var_f12 = D_global_asm_8075E4C4 - var_f12;
        // var_f12 = 6.283185482f - var_f12;
    }
    if (var_f12 < D_global_asm_8075E4C8) {
    // if (var_f12 < -3.141592741f) {
        var_f12 = D_global_asm_8075E4CC - var_f12;
        // var_f12 = -6.283185482f - var_f12;
    }
    arg0->unk4 += ((var_f12 * 180.0f) - (D_global_asm_8075E4D0 * D_global_asm_807FDA1E));
    // arg0->unk4 += ((var_f12 * 180.0f) - (0.3 * D_global_asm_807FDA1E));
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
    f32 temp = D_global_asm_8075E4D8;
    // f32 temp = 315.0f;

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
    arg0->unkC += (((30.0f - ((temp) - 30.0f)) + 30.0f) * D_global_asm_8075E4E0);
    // arg0->unkC += (((30.0f - ((temp) - 30.0f)) + 30.0f) * 0.2);
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

// TODO: close, float thing needs to be broken up I think
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_807102AC.s")

extern f64 D_global_asm_8075E4E8;
extern f32 D_global_asm_807FD9EC;

/*
u8 func_global_asm_807102AC(Struct8071006C_arg0 *arg0) {
    s32 var_v1;
    u8 temp_v0;
    f64 temp;

    func_global_asm_8070FA58(arg0);
    arg0->unk4 += (func_global_asm_80612794(arg0->unk20) * arg0->unk28);
    func_global_asm_8070FC40(arg0);
    arg0->unk8 = arg0->unk4;
    temp_v0 = arg0->unkB0;
    arg0->unk20 += 0x32;
    arg0->unkB0 = temp_v0 + 1;
    arg0->unkC += (((10.0f - (((1.0 / (arg0->unk10 * 3.0)) * 8.0) - 10.0f)) + 10.0f) * D_global_asm_8075E4E8);
    if (temp_v0 >= 0x6F) {
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
*/

// regalloc
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
            if ((((rand() >> 0xF) % 32767) % 100) < (arg0 * 100.0f)) {
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
            temp_f22 = ((rand() >> 0xF) % 32767) % 320;
            func_global_asm_8070F5CC(0, arg3, (((((rand() >> 0xF) % 32767) % 125) / 800.0) + temp_f26) * 2.5 * arg4, temp_f22, -0xA, (90.0f * arg4));
        }
        if (D_global_asm_807550E0->unk0 != 0) {
            addActorToTextOverlayRenderArray(func_global_asm_80710CA0, NULL, 1);
        }
    }
}
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80711950.s")

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
        if ((((rand() >> 0xF) % 32767) % 100) < (arg0 * 100.0f)) {
            var_s4 = 1;
        } else {
            var_s4 = 0;
        }
    } else {
        var_s4 = arg0;
    }
    D_global_asm_807FDA1B = 0xFF;
    for (i = 0; i < var_s4; i++) {
        temp_f22 = ((rand() >> 0xF) % 0x7FFF) % 320;
        func_global_asm_8070F5CC(2, arg3, (((((rand() >> 0xF) % 0x7FFF) % 125) / 800.0) + 0.1) * 2.5 * arg4, temp_f22, -0xA, 0xFF);
    }
    if (D_global_asm_807550E0->unk0 != 0) {
        addActorToTextOverlayRenderArray(func_global_asm_80710CA0, NULL, 1);
    }
}
*/

s32 func_global_asm_807122B4(void) {
    s16 i;

    if (D_global_asm_807550E0->unk0 != 0) {
        D_global_asm_8077058C = D_global_asm_8077058C * D_global_asm_8075E5B0;
        // D_global_asm_8077058C = D_global_asm_8077058C * 0.9;
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
    return countSetFlags(0x1FD, 40, FLAG_TYPE_PERMANENT) + 10;
}

typedef struct {
    OSTime unk0;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
} Struct80755340;

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
    // Unknown flag block right after Aztec Caption Seen
    setFlag(0x314, TRUE, FLAG_TYPE_PERMANENT);
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
            setFlag(0x5C, TRUE, FLAG_TYPE_TEMPORARY);
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

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80712944.s")

/*
void func_global_asm_80712944(GlobalASMStruct12 *arg0) {
    func_global_asm_8060AC34(arg0); // wrapper for subdragHookFunction()
    arg0->unk2 &= D_global_asm_8075530C;
    arg0->unk3 &= D_global_asm_80755310;
    arg0->unk0 &= D_global_asm_80755308;
    arg0->unk8 &= D_global_asm_8075530C;
    arg0->unk9 &= D_global_asm_80755310;
    arg0->unk6 &= D_global_asm_80755308;
    arg0->unkE &= D_global_asm_8075530C;
    arg0->unkF &= D_global_asm_80755310;
    arg0->unkC &= D_global_asm_80755308;
    arg0->unk14 &= D_global_asm_8075530C;
    arg0->unk15 &= D_global_asm_80755310;
    arg0->unk12 &= D_global_asm_80755308;
}
*/

// osGetTime stuff, probably timestamp maths
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80712A40.s")

void func_global_asm_80712B80(void) {
    if (game_mode == GAME_MODE_DK_TV) {
        func_global_asm_8060B750(D_global_asm_8075E5C0[D_global_asm_80755328].unk0);
        current_character_index[0] = func_global_asm_8060B7C4();
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80712BD4.s")

void func_global_asm_80712EDC(void) {
    D_global_asm_80750AC0 = 1;
    func_global_asm_80712490(MAP_MAIN_MENU, 0, GAME_MODE_MAIN_MENU);
}

void func_global_asm_80712F10(Maps *arg0, s32 *arg1) {
    if ((game_mode_copy == GAME_MODE_MYSTERY_MENU_MINIGAME)
        && (((D_global_asm_807FBB68 & 2) == 0)
            || (current_map == MAP_KROOL_FIGHT_CHUNKY_PHASE)
            || (*arg0 == MAP_DK_ISLES_OVERWORLD))) {
        *arg0 = MAP_MAIN_MENU;
        *arg1 = 0;
        game_mode = GAME_MODE_MAIN_MENU;
        return;
    }
    if ((game_mode_copy == GAME_MODE_SNIDES_BONUS_GAME) && (current_map != *arg0)) {
        *arg0 = MAP_SNIDES_HQ;
        *arg1 = 0;
        game_mode = GAME_MODE_ADVENTURE;
        return;
    }
    if (D_global_asm_80755330 != 0) {
        *arg0 = -1;
    }
}

void func_global_asm_80712FC8(void) {
    Maps map;
    s32 exit;

    if ((D_global_asm_80755334 >= 0x5A) && (newly_pressed_input.button & START_BUTTON)) {
        func_global_asm_80712EDC();
        return;
    }
    if (D_global_asm_8075531C == 0) {
        if (D_global_asm_8075532C >= 3) {
            func_global_asm_807124B8(MAP_NINTENDO_LOGO, 0, GAME_MODE_OPENING_CUTSCENE);
            return;
        }
        func_global_asm_8060B750(D_global_asm_8075E5C0[D_global_asm_80755328].unk0);
        func_global_asm_8060B7D0(&map, &exit);
        func_global_asm_805FF158(1);
        func_global_asm_805FF378(map, exit);
    }
}

void func_global_asm_80713088(void) {
    D_global_asm_8075531C = 0x1E;
    if (newly_pressed_input_copy & A_BUTTON) {
        setIntroStoryPlaying(0);
        func_global_asm_80712490(MAP_MAIN_MENU, 0, GAME_MODE_MAIN_MENU);
    }
}

void func_global_asm_807130D4(void) {
    if (func_global_asm_8061CB50()) {
        D_global_asm_8075531C = 0x1E;
    }
    if ((D_global_asm_80755330 == 1) || (D_global_asm_8075531C == 0) || (newly_pressed_input_copy & A_BUTTON)) {
        setIntroStoryPlaying(0);
        D_global_asm_80755330 = 0;
        func_global_asm_80712490(MAP_MAIN_MENU, 0, GAME_MODE_MAIN_MENU);
        D_global_asm_80755330 = 2;
    }
}

void func_global_asm_80713168(void) {
    if ((D_global_asm_80755334 < 0x1E) || ((newly_pressed_input_copy & (A_BUTTON | START_BUTTON)) == 0)) {
        if (D_global_asm_8075531C == 0) {
            block_3:
            func_global_asm_807124B8(MAP_NINTENDO_LOGO, 0, GAME_MODE_OPENING_CUTSCENE);
        }
    } else {
        goto block_3; // TODO: Yikes, this matches, but we should remove this goto
    }
}

void func_global_asm_807131BC(void) {
    Maps map;
    s32 exit;

    D_global_asm_8075532C = 0;
    func_global_asm_8060B750(D_global_asm_8075E5C0[D_global_asm_80755328].unk0);
    func_global_asm_8060B7D0(&map, &exit);
    func_global_asm_805FF158(1);
    func_global_asm_80712490(map, exit, GAME_MODE_DK_TV);
}

void func_global_asm_8071321C(void) {
    if ((D_global_asm_8075531C == 0) || ((D_global_asm_80755334 >= 0xA) && (newly_pressed_input.button & START_BUTTON))) {
        func_global_asm_807131BC();
    }
}

void func_global_asm_80713270(void) {
    if ((D_global_asm_80755324 != 0) || ((game_mode_copy == GAME_MODE_OPENING_CUTSCENE) && (D_global_asm_80755334 >= 0x5A) && newly_pressed_input.button & START_BUTTON)) {
        func_global_asm_807124B8(MAP_DK_RAP, 0, GAME_MODE_DK_RAP);
    }
}

Gfx *func_global_asm_807132DC(Gfx *dl) {
    dl = func_global_asm_805FD030(dl);
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetScissor(dl++, G_SC_NON_INTERLACE, 10, 10, 309, 229);
    return dl;
}

extern Mtx D_807FDAC0; // TODO: Correct datatype?

Gfx *func_global_asm_8071338C(Gfx *dl) {
    char *string;
    f32 temp;

    string = getTextString(0xC, 0, 1);
    gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gSPMatrix(dl++, &D_807FDAC0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    temp = 20.0f;
    temp *= 2.0f;
    temp *= 4.0f;
    return printStyledText(dl, 1, 0x118, temp, string, 4);
}

Gfx *func_global_asm_80713438(Gfx *dl, u8 arg1) {
    char *sp34;
    char *sp30;
    s32 pad2C;
    f32 sp28;
    f32 temp_f16;
    s32 size;

    sp30 = getTextString(0xC, 1, 1);
    size = strlen(sp30) + 2;
    sp28 = D_global_asm_80744490 * 0.5 * 2;
    temp_f16 = 418.0f;
    sp34 = malloc(size);
    func_global_asm_8061134C(sp34);
    sprintf(sp34, &D_global_asm_8075E5D4, 0x63, sp30);
    // sprintf(sp34, "%c%s", 0x63, sp30);
    sp28 -= 0.5 * getCenterOfString(1, sp34);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, arg1);
    gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    return printStyledText(dl, 1, sp28 * 4.0f, temp_f16 * 4.0f, sp34, 4);
}

extern u8 D_global_asm_8074450C;

typedef struct {
    s32 unk0[2];
} Struct80755370;

extern Struct80755370 D_global_asm_80755370;
extern u8 D_global_asm_807ECD09;

Gfx *func_global_asm_807135B4(Gfx *dl) {
    char *string;
    s32 sp40;
    Struct80755370 sp38;
    f32 sp34;
    f32 sp30;

    sp40 = 0;
    if (((object_timer - 0x5A) >= 0) && !((object_timer - 0x5A) & 0x10)) {
        sp38 = D_global_asm_80755370;
        sp34 = D_global_asm_80744490;
        sp30 = 0xBD - func_global_asm_806FD894(6);
        if (D_global_asm_807ECD09) {
            if (!gameIsInDKTVMode() || current_map == MAP_DK_RAP) {
                return dl;
            } else {
                sp40 = 1;
            }
        }
        sp34 *= 0.5;
        gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        string = getTextString(0xC, sp38.unk0[sp40], 1);
        dl = printText(dl, sp34 * 4.0f, ((f32)D_global_asm_8074450C) * sp30 * 4.0f, 0.7f, string);
    }
    return dl;
}

s32 func_global_asm_8071375C(s32 arg0) {
    return arg0;
}

Gfx *func_global_asm_80713764(Gfx *dl, u8 arg1, f32 arg2) {
    f32 temp;
    f32 temp2;
    temp = D_global_asm_80744490 * 0.5;
    temp2 = (D_global_asm_80744494 * 0.5) + -20.0 + arg2;
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1);
    gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetTextureFilter(dl++, G_TF_POINT);
    return displayImage(dl, 0x2C, 0, 2, 0xE0, 0x80, temp, temp2, 1.0f, 1.0f, 0, 0.0f);
}

Gfx *func_global_asm_807138A4(Gfx *dl) {
    return func_global_asm_807135B4(func_global_asm_807132DC(dl));
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_807138CC.s")

Gfx *func_global_asm_80713AA8(Gfx *dl) {
    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    return dl;
}

// Displaylist stuff, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80713B40.s")

extern s32 D_global_asm_80755378; // TODO: Datatype

/*
Gfx *func_global_asm_80713B40(Gfx *dl) {
    f32 temp_f0;
    Gfx *temp = dl;
    s16 temp_t0;
    s16 temp_v0;
    s16 alpha;

    temp_t0 = (D_global_asm_8075531C - 140);
    if (temp_t0 >= 0 && temp_t0 < 150) {
        temp_v0 = (temp_t0 - 90);
        if (temp_v0 < 0) {
            alpha = 0xFF;
        } else {
            alpha = (60 - temp_v0) * 5;
        }
        if (temp_t0 < 60) {
            alpha = temp_t0 * 5;
        }
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
        temp = func_global_asm_80713AA8(temp);
        gDPSetPrimColor(temp++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
        temp_f0 = ((150 - temp_t0) / 40.0);
        temp = printText(temp, 640, 480.0 - (temp_f0 * 32.0), temp_f0, &D_global_asm_80755378);
    }
    return temp;
}
*/

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80713C8C.s")

Gfx *func_global_asm_80713DFC(Gfx *dl) { // displayHelmTimer()
    s32 stackPad0;
    s32 stackPad1;
    s32 stackPad2;
    s32 stackPad3;
    s32 stackPad4;
    s32 stackPad5;
    s32 stackPad6;
    s32 stackPad7;
    f32 sp1C;

    if (func_global_asm_80712628()) {
        if (!(global_properties_bitfield & 3)) {
            sp1C = D_global_asm_80744490 * 0.5f;
            dl = func_global_asm_807132DC(dl);
            gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            dl = func_global_asm_8068E7B4(dl++, sp1C, 214.0f, D_global_asm_80755348); // drawHelmTimer()
        }
    }
    return dl;
}

s32 func_global_asm_80713EA8(s32 arg0) {
    return arg0;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80713EB0.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
} Struct80713EB0;

extern s16 D_global_asm_807FC828;
extern s16 D_global_asm_807FC82A;
extern s16 D_global_asm_807FC82C;

/*
void func_global_asm_80713EB0(Maps arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    Struct80713EB0 *t;

    if (arg0 >= 0) {
        if (game_mode_copy == 0xE) {
            if (arg2 == 1) {
                if (isFlagSet(0x2A, FLAG_TYPE_GLOBAL) == FALSE) {
                    arg0 = -1;
                }
            }
            if (arg2 == 2) {
                if (isFlagSet(0x2B, FLAG_TYPE_GLOBAL) == FALSE) {
                    arg0 = -1;
                }
            }
        } else {
            func_global_asm_806ABE3C();
            // TODO: Issue is here
            t = &D_global_asm_807FC828;
            temp_v1 = D_global_asm_807FC828 + D_global_asm_807FC82A + D_global_asm_807FC82C + t->unk0 + t->unk2 + t->unk4 + t->unk6;
            if (arg2 == 1) {
                if (temp_v1 < 0x118) {
                    arg0 = -1;
                } else {
                    setFlag(0x2A, TRUE, FLAG_TYPE_GLOBAL);
                }
            }
            if (arg2 == 2) {
                if (temp_v1 < 0x119) {
                    arg0 = -1;
                } else {
                    setFlag(0x2B, TRUE, FLAG_TYPE_GLOBAL);
                }
            }
        }
        if (arg0 >= 0) {
            func_global_asm_80712524(arg0, arg1);
            return;
        }
    }
    if (game_mode_copy == GAME_MODE_END_SEQUENCE_DK_THEATRE) {
        setIntroStoryPlaying(0);
        func_global_asm_80712490(MAP_MAIN_MENU, 0, GAME_MODE_MAIN_MENU);
    } else {
        func_global_asm_807124B8(MAP_NINTENDO_LOGO, 0, 1);
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_114270/func_global_asm_80714060.s")

// TODO: Why can't these return s32?
int gameIsInDKTVMode(void) {
    return game_mode == GAME_MODE_DK_TV
        || game_mode == GAME_MODE_UNKNOWN_4
        || game_mode_copy == GAME_MODE_DK_TV
        || game_mode_copy == GAME_MODE_UNKNOWN_4;
}

int gameIsInAdventureMode(void) {
    return game_mode_copy == GAME_MODE_ADVENTURE || game_mode == GAME_MODE_ADVENTURE;
}

int func_global_asm_80714360(void) {
    return game_mode_copy == GAME_MODE_UNKNOWN_8 || game_mode == GAME_MODE_UNKNOWN_8;
}

int gameIsInQuitGameMode(void) {
    return (game_mode_copy == GAME_MODE_QUIT_GAME || game_mode == GAME_MODE_QUIT_GAME) || (game_mode_copy == GAME_MODE_GAME_OVER || game_mode == GAME_MODE_GAME_OVER);
}

int gameIsInSnidesBonusGameMode(void) {
    return game_mode_copy == GAME_MODE_SNIDES_BONUS_GAME || game_mode == GAME_MODE_SNIDES_BONUS_GAME;
}

int gameIsInMysteryMenuMinigameMode(void) {
    return game_mode_copy == GAME_MODE_MYSTERY_MENU_MINIGAME || game_mode == GAME_MODE_MYSTERY_MENU_MINIGAME;
}

int gameIsInMainMenuMode(void) {
    return game_mode_copy == GAME_MODE_MAIN_MENU;
}

int func_global_asm_80714464(void) {
    return game_mode_copy == GAME_MODE_END_SEQUENCE
        || game_mode_copy == GAME_MODE_END_SEQUENCE_DK_THEATRE
        || game_mode == GAME_MODE_END_SEQUENCE
        || game_mode == GAME_MODE_END_SEQUENCE_DK_THEATRE;
}

void func_global_asm_807144B8(s8 arg0) {
    Maps map;
    s32 exit;

    D_global_asm_807445B8 = osGetTime();
    D_global_asm_80755350 = 0;
    func_global_asm_806C9AE0();
    func_global_asm_80731030(); // clearTemporaryFlags()
    func_global_asm_8060DC3C(arg0, 1);
    current_character_index[0] = 0; // DK
    if (func_global_asm_8060C6B8(0xD, 0, 0, current_file) || story_skip) {
        // Flag: Isles: Escape Cutscene
        if (isFlagSet(0x186, FLAG_TYPE_PERMANENT)) {
            map = MAP_DK_ISLES_OVERWORLD;
            exit = 0;
        } else {
            map = MAP_TRAINING_GROUNDS;
            exit = 1;
        }
    } else {
        D_global_asm_80755338 = 1;
        map = MAP_DK_ISLES_DK_THEATRE;
        D_global_asm_8075533C = 0;
        exit = 0;
    }
    func_global_asm_805FF4D8(map, exit); // initMapChange()
    game_mode = GAME_MODE_ADVENTURE;
}

void func_global_asm_8071458C(void) {
    Maps map;

    func_global_asm_806C9AE0();
    D_global_asm_80750AB8 = 0;
    if (D_global_asm_807552E4.unk0 == 0) {
        D_global_asm_80750AB8 = 1;
        map = MAP_KONG_BATTLE_BATTLE_ARENA;
    } else {
        map = D_global_asm_80755384[D_global_asm_807552E4.unk20];
    }
    func_global_asm_80712490(map, 0, GAME_MODE_ADVENTURE);
}

void func_global_asm_807145F8(void) {
    D_global_asm_80755324 = 1;
}

int func_global_asm_80714608(s32 arg0) {
    return (cc_number_of_players >= 2) && arg0 == D_global_asm_807552E4.unk0;
}

void func_global_asm_80714638(void) {
    func_global_asm_80712EDC();
    D_global_asm_807552EC = 3;
}

void func_global_asm_80714660(void) {

}
