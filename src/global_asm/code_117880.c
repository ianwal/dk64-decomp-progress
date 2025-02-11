#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern OSTime D_global_asm_807445B8;

extern s8 D_global_asm_80750AB8;
extern u8 D_global_asm_80750AC0;

extern s32 D_global_asm_807552EC;
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
extern Maps D_global_asm_80755384[];

extern s32 D_global_asm_807FBB68;

extern u8 D_global_asm_807FDA1C;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
} Struct8075E5C0;

extern const Struct8075E5C0 D_global_asm_8075E5C0[] = {
    {0x04, 0x00, 0x01E0},
    {0x00, 0x00, 0x0294},
    {0x01, 0x00, 0x01E0},
    {0x03, 0x00, 0x0258},
    {0x02, 0x00, 0x0258},
};

void func_global_asm_80712B80(void) {
    if (game_mode == GAME_MODE_DK_TV) {
        func_global_asm_8060B750(D_global_asm_8075E5C0[D_global_asm_80755328].unk0);
        current_character_index[0] = func_global_asm_8060B7C4();
    }
}

// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_117880/func_global_asm_80712BD4.s")

extern Mtx D_807FDAC0;
extern u8 D_global_asm_807467CC;
extern u16 D_global_asm_80755308;
extern u8 D_global_asm_8075530C;
extern u8 D_global_asm_80755310;

/*
void func_global_asm_80712BD4(void) {
    u8 temp_v0;
    s16 temp_a1;
    s16 temp_v0_2;
    u16 temp_a2;
    u8 temp_t6;
    s16 temp;

    temp_v0 = isFlagSet(0x302, FLAG_TYPE_PERMANENT);
    D_global_asm_80755334 = 0;
    D_global_asm_80755330 = 0;
    if (D_global_asm_807467CC == 0) {
        func_global_asm_8060E1A8();
    }
    if ((getLevelIndex(current_map, 1U) == 8) && 
        !(D_global_asm_807FBB68 & 2) && 
        (current_map != MAP_KROOLS_SHOE) && 
        (!func_global_asm_80712628()) &&
        (temp_v0 == 0)) {
        func_global_asm_80712574();
    }
    guScale(&D_807FDAC0, 0.5f, 0.5f, 1.0f);
    switch (game_mode_copy) {
        case GAME_MODE_NINTENDO_LOGO:
            D_global_asm_8075531C = 60 * 30;
            D_global_asm_80755308 = 0;
            D_global_asm_80755338 = 1;
            D_global_asm_8075533C = 0;
            break;
        case GAME_MODE_OPENING_CUTSCENE:
            D_global_asm_8075531C = 60 * 30;
            D_global_asm_80755308 = START_BUTTON;
            D_global_asm_80755338 = 1;
            D_global_asm_8075533C = 0;
            break;
        case GAME_MODE_DK_RAP:
            D_global_asm_8075531C = 190 * 30;
            D_global_asm_80755308 = START_BUTTON;
            D_global_asm_80755338 = 1;
            D_global_asm_8075533C = 0;
            break;
        case GAME_MODE_DK_TV:
            D_global_asm_8075532C += 1;
            D_global_asm_8075531C = func_global_asm_8060B49C(character_change_array->player_pointer, D_global_asm_8075E5C0[D_global_asm_80755328].unk0);
            D_global_asm_8075531C = MIN(D_global_asm_8075531C, D_global_asm_8075E5C0[D_global_asm_80755328].unk2);
            D_global_asm_80755328++;
            D_global_asm_80755328 %= 5U;
            D_global_asm_80755308 = START_BUTTON;
            break;
        case GAME_MODE_QUIT_GAME:
            D_global_asm_8075531C = (s32)(34.66666666f * 30);
            game_mode = 9;
            game_mode_copy = 9;
        case GAME_MODE_GAME_OVER:
            D_global_asm_80755308 = START_BUTTON | A_BUTTON;
            break;
        case GAME_MODE_MAIN_MENU:
            D_global_asm_807552EC = 0;
        case GAME_MODE_ADVENTURE:
        case GAME_MODE_MYSTERY_MENU_MINIGAME:
        case GAME_MODE_SNIDES_BONUS_GAME:
            D_global_asm_8075531C = 1;
            D_global_asm_80755308 = 0xFFFF;
            D_global_asm_8075530C = 0xFF;
            D_global_asm_80755310 = 0xFF;
            break;
        case GAME_MODE_END_SEQUENCE:
            D_global_asm_8075531C = 1;
            D_global_asm_8075530C = 0;
            D_global_asm_80755310 = 0;
            D_global_asm_80755308 = 0;
            spawnActor(ACTOR_END_SEQUENCE_CONTROLLER, 0);
            break;
        case GAME_MODE_END_SEQUENCE_DK_THEATRE:
            spawnActor(ACTOR_END_SEQUENCE_CONTROLLER, 0);
        case GAME_MODE_DK_THEATRE:
            D_global_asm_8075531C = 0x1E;
            break;
    }
    func_global_asm_8060DEC8();
}
*/

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

    if ((D_global_asm_80755334 >= 0x5A) && (newly_pressed_input[0] & START_BUTTON)) {
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
    if ((D_global_asm_8075531C == 0) || ((D_global_asm_80755334 >= 0xA) && (newly_pressed_input[0] & START_BUTTON))) {
        func_global_asm_807131BC();
    }
}

void func_global_asm_80713270(void) {
    if ((D_global_asm_80755324 != 0) || ((game_mode_copy == GAME_MODE_OPENING_CUTSCENE) && (D_global_asm_80755334 >= 0x5A) && newly_pressed_input[0] & START_BUTTON)) {
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
    sprintf(sp34, "%c%s", 0x63, sp30);
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
    if ((((s32)object_timer - 0x5A) >= 0) && !(((s32)object_timer - 0x5A) & 0x10)) {
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_117880/func_global_asm_807138CC.s")

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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_117880/func_global_asm_80713B40.s")

extern s32 D_global_asm_80755378; // TODO: Datatype

/*
Gfx *func_global_asm_80713B40(Gfx *dl) {
    f32 temp_f0;
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
        dl = func_global_asm_80713AA8(dl);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
        temp_f0 = ((150 - temp_t0) / 40.0);
        dl = printText(dl, 640, 480.0 - (temp_f0 * 32.0), temp_f0, &D_global_asm_80755378);
    }
    return dl;
}
*/

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_117880/func_global_asm_80713C8C.s")

extern OSTime D_global_asm_807445B0;
extern Struct80755340 D_global_asm_80755340;
extern u16 D_global_asm_80755358[];

/*
void func_global_asm_80713C8C(void) {
    u64 temp_ret;

    D_global_asm_8075531C = 1;
    if (!D_global_asm_80755340.unk10) {
        return;
    }
    if (isFlagSet(0x302, 0U)) {
        func_global_asm_8071261C();
        playSong(0x74, 1.0f);
        return;
    }
    D_global_asm_80755340.unk0 += D_global_asm_807445B0;
    if ((global_properties_bitfield & 2)) {
        return;
    }
    temp_ret = osGetTime();
    temp_ret = __ll_mul(temp_ret - D_global_asm_80755340.unk0, 0x40);
    temp_ret = __ull_div(temp_ret, 3000);
    D_global_asm_80755340.unk8 = D_global_asm_80755340.unkC - __ull_div(temp_ret, 1000000);
    if (D_global_asm_80755340.unk11 < 0xAU) {
        if (D_global_asm_80755340.unk8 == D_global_asm_80755358[D_global_asm_80755340.unk11]) {
            playSound(0x2D4, 0x7FFFU, 63.0f, 1.0f, 0, 0);
            D_global_asm_80755340.unk11++;
        }
    }
    if (D_global_asm_80755340.unk8 <= 0) {
        func_global_asm_807127B4();
    }
}
*/


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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_117880/func_global_asm_80713EB0.s")

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

extern s8 D_global_asm_807552E0;
void func_global_asm_80713C8C(void);

Gfx *func_global_asm_80714060(Gfx *dl) {
    s8 sp38[0x28];

    if ((D_global_asm_80755338) && (object_timer == 1)) {
        D_global_asm_80755338 = 0;
        if (D_global_asm_8075533C >= 0) {
            playCutscene(NULL, D_global_asm_8075533C, 1U);
        }
    }
    if (D_global_asm_807552E0) {
        dl = func_global_asm_807132DC(dl);
        sprintf(&sp38, "SECURITY %d", D_global_asm_807552E0);
        dl = printText(dl, 0x280, 0x1E0, 1.0f, &sp38);
    }
    D_global_asm_807552E0 = 0;
    gDPPipeSync(dl++);
    if (D_global_asm_80755334 < 0x5A) {
        D_global_asm_80755334 += 1;
    }
    if ((func_global_asm_80712628()) && (game_mode_copy != GAME_MODE_ADVENTURE)) {
        func_global_asm_8071261C();
    }
    if ((D_global_asm_8075531C) && (game_mode_copy == game_mode)) {
        D_global_asm_8075531C--;
        switch (game_mode_copy) {
            case GAME_MODE_NINTENDO_LOGO:
            case GAME_MODE_OPENING_CUTSCENE:
                func_global_asm_80713270();
                break;
            case GAME_MODE_DK_RAP:
                func_global_asm_8071321C();
                break;
            case GAME_MODE_DK_TV:
                func_global_asm_80712FC8();
                break;
            case GAME_MODE_QUIT_GAME:
            case GAME_MODE_GAME_OVER:
                func_global_asm_80713168();
                break;
            case GAME_MODE_END_SEQUENCE_DK_THEATRE:
                func_global_asm_80713088();
                break;
            case GAME_MODE_DK_THEATRE:
                func_global_asm_807130D4();
                break;
            case GAME_MODE_ADVENTURE:
                func_global_asm_80713C8C();
                break;
        }
    }
    switch (game_mode_copy) {
        case GAME_MODE_NINTENDO_LOGO:
        case GAME_MODE_OPENING_CUTSCENE:
            dl = func_global_asm_8071375C(dl);
            break;
        case GAME_MODE_DK_RAP:
            dl = func_global_asm_807138A4(dl);
            break;
        case GAME_MODE_DK_TV:
            dl = func_global_asm_807138CC(dl);
            break;
        case GAME_MODE_QUIT_GAME:
        case GAME_MODE_GAME_OVER:
            dl = func_global_asm_80713B40(dl);
            break;
        case GAME_MODE_ADVENTURE:
            dl = func_global_asm_80713DFC(dl);
            break;
        case GAME_MODE_MAIN_MENU:
            dl = func_global_asm_80713EA8(dl);
            break;
        case GAME_MODE_DK_THEATRE:
            break;
    }
    return dl;
}



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
