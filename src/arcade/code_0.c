#include "arcade_int.h"

extern u8 D_80032D50;
extern u8 D_80032CA8;
extern u8 D_800342B8;
extern uSprite D_8004BC20[2];
extern uSprite D_8004BC50[2];

extern void func_8060A9BC(void);
extern void func_8060AC7C(void);
extern void func_80610044(Gfx *, s32, s32, s32, s32, s32);
extern Gfx *func_806FD490(Gfx *, s32, s32, s32, s32 *);
extern void func_8070F2FC(Gfx **arg0, s16 arg1, s16 arg2);
extern void func_8070E8F0(Gfx**, Sprite*);


void func_8002419C(void *arg0, Gfx **arg1);
void func_80024940(Gfx **gpp);
void func_80024CF8(Gfx **arg0);
void func_800251D8(Gfx **arg0);
void func_800252D8(Gfx **arg0);
void func_800257D8(void); 
void func_80025960(Gfx **arg0);
void func_800275E8(Gfx **arg0);
void func_80027A38(Gfx **arg0);
void func_800311E0(void);

/* .code */
void func_80024000(void) {
    Gfx *sp2C;
    s32 sp28;

    func_8060A9BC();
    func_80610044(D_8076A050[D_807444FC], D_8076A088, 3, 1, 0x4D2, 1);
    D_807444FC ^= 1;
    object_timer++;
    D_8076A048 = D_807444FC * 0x11B0 + &D_80767CE8;
    func_8060AC7C();
    if (((D_8076A0B1 & 1) != 0) && (D_807FD888 == 31.0f)) {
        sp2C = D_8076A050[D_807444FC];
    } else {
        func_8002419C(D_8076A048, &sp2C);
    }
    sp2C = func_80704484(sp2C, 0);
    if (is_cutscene_active != 3) {
        sp28 = D_8076A048 + 0xDB0;
        func_805FE71C(sp2C, D_807444FC, &D_8076A088, 0);
        func_805FE7B4(sp28, D_8076A048, &D_8076A08C, 1);
        return;
    }
    func_805FE71C(sp2C, D_807444FC, &D_8076A088, 1);
}

void func_8002419C(void *arg0, Gfx **arg1) {
    Gfx *sp44 = (Gfx *)D_8076A050[D_807444FC];
    gSPSegment(sp44++, 0x00, NULL);
    gSPSegment(sp44++, 0x02, osVirtualToPhysical(arg0));
    gSPSegment(sp44++, 0x01, osVirtualToPhysical(D_8076A080));
    gSPDisplayList(sp44++, &D_1000090);
    gSPDisplayList(sp44++, &D_1000040);
    gDPPipeSync(sp44++);
    sp44 = func_805FE4D4(sp44);
    gDPSetColorDither(sp44++,G_CD_MAGICSQ);
    gDPSetAlphaDither(sp44++,G_AD_PATTERN);
    gDPSetFillColor(sp44++, 0x00050005);
    gDPFillRectangle(sp44++, 0, 0, 319, 239);
    func_80024940(&sp44);
    *arg1 = sp44;
}

void func_80024320(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_8060C648(0x15, 0, i, 0, arcade_saved_high_scores[i]);
        func_8060C648(0x12, 0, i, 0, arcade_saved_high_score_initials[i][0]);
        func_8060C648(0x13, 0, i, 0, arcade_saved_high_score_initials[i][1]);
        func_8060C648(0x14, 0, i, 0, arcade_saved_high_score_initials[i][2]);
    }
    D_8004A760 = arcade_saved_high_scores[0];
    func_8060DEA8();
}

void func_8002440C(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        arcade_saved_high_scores[i] = func_8060C6B8(0x15, 0, i, 0);
        arcade_saved_high_score_initials[i][0] = func_8060C6B8(0x12, 0, i, 0);
        arcade_saved_high_score_initials[i][1] = func_8060C6B8(0x13, 0, i, 0);
        arcade_saved_high_score_initials[i][2] = func_8060C6B8(0x14, 0, i, 0);
    }
    D_8004A760 = arcade_saved_high_scores[0];
}

void func_800244E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8004C725 = arg0;
    D_8004C726 = arg1;
    D_8004C727 = arg2;
    D_8004C728 = arg3;
}

void func_80024508(s32 arg0, s32 arg1) {
    D_8004C72C = arg0;
    D_8004C730 = arg1;
}

void func_8002451C(Gfx **gpp, s32 *arg1) {
    Gfx *gp = *gpp; 
    gDPPipeSync(gp++);
    gDPSetCycleType(gp++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gp++, -1);
    gSPSetGeometryMode(gp++, G_SHADE | 0x200000);
    gDPSetPrimColor(gp++, 0, 0, D_8004C725, D_8004C726, D_8004C727, D_8004C728);
    gDPSetCombineMode(gp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(gp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    *gpp = func_806FD490(gp, 2, D_8004C72E, D_8004C732, arg1);
}

// cycle_rng
s32 func_80024644(void) {
    D_8004A738 = (D_8004A738 * 0x41C64E6D) + 12345;
    return D_8004A738 >> 0x10 & 0x7FFF;
}

void arcade_add_points_to_score(s32 round_points) {
    s32 oldScore;

    oldScore = arcade_current_score;
    arcade_current_score += round_points;
    if ((arcade_current_score >= 10000) && (oldScore < 10000)) {
        arcade_lives_internal++; 
        arcade_lives_visual++; 
    }
}

//arcade_maxf
f32 func_800246C8(f32 arg0, f32 arg1) {
    if (arg1 < arg0) {
        return arg1;
    }
    return arg0;
}

//get_first_empty_obj_slot
s32 func_800246EC(void) {
    s32 i;
    for (i = 0; i <= 0x4F; i++) {
        if (D_8004BCD0[i].unk18 == 0) {
            return i;
        }
    }
    return 0;
}

//get_first_empty_obj_slot_after_player
s32 func_80024764(void) {
    s32 i;
    for (i = D_8004C71F + 1; i < 0x50; i++) {
        if (D_8004BCD0[i].unk18 == 0) {
            return i;
        }
    }
    return 0;
}

//get_last_empty_obj_slot
s32 func_800247B8(void) {
    s32 i;
    for (i = 0x4F; i >= 0; i--) {
        if (D_8004BCD0[i].unk18 == 0) {
            return i;
        }
    }
    return 0;
}

s32 func_800247F0(void) {
    s32 i;
    for (i = 0x27; i >= 0; i--) {
        if (D_8004BCD0[i].unk18 == 0) {
            return i;
        }
    }
    return 0;
}

s32 func_80024828(void) {
    s32 i;
    for (i = 0x24; i >= 0; i--) {
        if (D_8004BCD0[i].unk18 == 0) {
            return i;
        }
    }
    return 0;
}

s32 func_80024860(enum ARCADE_OBJ_E arg0) {
    s32 i;
    for (i = 0; i < 0x50; i++) {
        if (arg0 == D_8004BCD0[i].unk18) {
            return i;
        }
    }
    return -1;
}

s32 arcade_get_object_type_count(enum ARCADE_OBJ_E arg0) {
    s32 i;
    s32 count = 0;
    for (i = 0; i < 0x50; i++) {
        if (arg0 == D_8004BCD0[i].unk18) {
            count++;
        }
    }
    return count;
}

#ifndef NONMATCHING //needs .rodata and .data sections defined
// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80024940.s")
#else
void func_80024940(Gfx **gpp) {
    Gfx* sp1C;
    //static D_8004A78C = 1;
    //static D_8004A790 = 0;
    
    sp1C = *gpp;
    if (D_8004A78C) {
        D_8004A78C = 0;
        arcade_background_visual = 1;
        func_80024D90();
        func_8002440C();
    }
    switch(D_8004C724) {
        case 0:// 800249A8
            func_80024E84(&sp1C);
            break;
        case 1:// 800249B8
            func_800251D8(&sp1C);
            break;
        case 5:// 800249C8
            func_800252D8(&sp1C);
            break;
        case 4:// 800249D8
            func_800255F4(&sp1C);
            break;
        case 3:// 800249E8
            func_80024CF8(&sp1C);
            break;
        case 2:// 800249F8
        default:
            func_80025960(&sp1C);
            break;
    }
    func_800319D4(&sp1C);
    D_8004C6D8++;
    *gpp = --sp1C;
    D_8004A790++;
}
#endif

// struct, score, big offset, loops, aaa
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80024A50.s")
#else
void func_80024A50(s32 arg0) {
    /* adds score to high scores */
    u8 pad[0x10];
    volatile u8 spC = D_8004A794; //static???
    int i, j;

    
    for (i = 4; arg0 < i; i--) {
        arcade_saved_high_scores[i] = arcade_saved_high_scores[i - 1];
        for (j = 0; j < 3; j++) {
            arcade_saved_high_score_initials[i][j] = arcade_saved_high_score_initials[i - 1][j];
        }
    }
    arcade_saved_high_scores[arg0] = arcade_current_score;
    for (j = 0; j < 3; j++) {
        arcade_saved_high_score_initials[arg0][j] = spC;
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80024B04.s")
#else
void func_80024B04(void) {
    u8 i;
    s32 max;
    for (i = 0; i < 5; i++) {
        if (arcade_saved_high_scores[i] < arcade_current_score) {
            func_80024A50(i);
            break;
        }
    }
    for (i = 0; i < 3; i++) {
        D_8004A774[i] = ' ';
    }
    D_8004C724 = 3;
    arcade_background_visual = 0;
    D_8004C6DC = 0;
    D_8004C720 = 0;
    max = 0x50;
    for (i = 0; i < max; i++) {
        D_8004BCD0[i].unk18 = 0;
        D_8004BCD0[0] = D_8004BCD0[i];
    }
}
#endif

void func_80024C34(void) {
    if (D_8004A73C == 0) {
        if (D_8004A770 && D_8004A740 && !isFlagSet(0x84, FLAG_TYPE_PERMANENT)) {
            // Arcade Golden Banana Collected
            if (isFlagSet(0x82, FLAG_TYPE_PERMANENT)) {
                // Nintendo Coin Spawn Pending
                setFlag(0x11, TRUE, FLAG_TYPE_TEMPORARY);
            } else {
                // Arcade GB Spawn Pending
                setFlag(0x10, TRUE, FLAG_TYPE_TEMPORARY);
            }
        }
        if (D_8004A740) { // arcade_is_in_nintendo_coin_mode
            func_805FF898();
        } else {
            func_805FF378(MAP_MAIN_MENU, 0);
        }
        D_8004A73C = 1;
    }
}

void func_80024CF8(Gfx **arg0) {
    Gfx *sp1C;
    sp1C = *arg0;
    D_8004C6DC++;
    func_800259D0(&sp1C);
    func_80030FEC(); //update objects
    func_8002B2C0(&sp1C);
    if (D_8004C6DC >= 1981) { // arcade_internal_timer
        if (D_8004A740) { // arcade_is_in_nintendo_coin_mode
            func_80024C34();
        } else {
            func_80024D90();
        }
    }
    *arg0 = sp1C;
}

void func_80024D90(void) {
    s32 temp_v1;
    ArcadeStruct1 *iPtr;

    D_8004C724 = 0; // arcade_should_reload_level
    D_8004A740 = isFlagSet(0x63, FLAG_TYPE_TEMPORARY); // arcade_is_in_nintendo_coin_mode
    arcade_background_visual = 0;
    D_8004C6DC = 0x200; // arcade_internal_timer
    arcade_game_state = 1;

    for (iPtr = D_8004BCD0; iPtr < &D_8004BCD0[0x50]; iPtr++) {
        iPtr->unk18 = 0;
    }

    temp_v1 = func_800246EC();

    D_8004BCD0[temp_v1] = arcade_dk_title_obj_template;
    D_8004BCD0[temp_v1].x_position = 138.0f;
    D_8004BCD0[temp_v1].y_position = 180.0f;
    D_8004BCD0[temp_v1].unk14 = &D_800424D0;
}

void func_80024E84(Gfx **arg0) {
    Gfx *sp24;
    int i;

    sp24 = *arg0;
    D_8004C6DC++;
    func_800259D0(&sp24);
    if (D_8004C6DC & 0x200) {
        func_8002B2C0(&sp24);
    }
    if (D_8004A740 && D_8004C6DC == 0x5FE || newly_pressed_input & 0x9000) {
        arcade_current_score = 0;
        D_8004C723 = 0;
        arcade_lives_internal = 2;
        if (D_8004A740) {
            arcade_lives_internal = 0;
            // Nintendo Coin Collected
            if (isFlagSet(0x84, FLAG_TYPE_PERMANENT)) {
                D_8004C723 = 8;
            // Arcade Golden Banana Collected
            } else if (isFlagSet(0x82, FLAG_TYPE_PERMANENT)) {
                D_8004C723 = 4;
            }
        }//L80024F74
        if (D_8004C723 / 4 + 1 >= 0xA) {
            D_8004A76C = 9;
        } else {
            D_8004A76C = D_8004C723 / 4 + 1;
        }
        arcade_lives_visual = arcade_lives_internal + 1;
        arcade_background_visual = 1;
        D_8004C724 = 1;
        D_8004C6DC = 0;
        arcade_game_state = 1;
        D_8004C721 = 0;
        for (i = 0; i < 80; i++) {
            D_8004BCD0[i].unk18 = 0;
        }
        D_8004BCD0[func_800246EC()] = arcade_pauline_bottom_obj_template;
        D_8004BCD0[func_800246EC()] = arcade_pauline_top_obj_template;
        D_8004BCD0[func_800246EC()] = arcade_dk_title_obj_template;
        if (D_8004A76C == 2 && D_8004A740) {
            D_8004BCD0[func_800246EC()] = arcade_nintendo_coin_obj_template;
        }
        D_8004C708 = 0;
    }//L800251BC
    *arg0 = sp24;
}

void func_800251D8(Gfx **arg0) {
    Gfx *sp1C;
    sp1C = *arg0;
    
    func_80030FEC(); //update objects
    func_800259D0(&sp1C);
    func_8002B2C0(&sp1C);
    if (D_8004C6DC++ >= 761) { // arcade_internal_timer
        func_800257D8();
    }
    *arg0 = sp1C;
}

void func_80025240(void) { // queue_arcade_sfx()
    if (arcade_background_visual == 1) {
        arcade_next_sfx = SFX_4D_ARCADE_25M;
        return;
    }
    if (arcade_background_visual == 2) {
        arcade_next_sfx = SFX_4F_ARCADE_50M;
        return;
    }
    if (arcade_background_visual == 4) {
        arcade_next_sfx = SFX_4E_ARCADE_100M;
        return;
    }
    arcade_next_sfx = -1;
}

void func_800252A4(SFX_E arg0) {
    arcade_next_sfx = arg0;
    if (D_80770DF8 != 0) {
        func_80737924(D_80770DF8);
    }
}

void func_800252D8(Gfx **arg0) {
    Gfx *sp34;
    s32 temp;

    sp34 = *arg0;
    func_800259D0(&sp34);
    if (D_8004C71E < 0xA) { // arcade_bonus_timer
        if ((arcade_next_sfx == SFX_4D_ARCADE_25M) 
            || (arcade_next_sfx == SFX_4E_ARCADE_100M) 
            || (arcade_next_sfx == SFX_4F_ARCADE_50M) 
            || (arcade_next_sfx == -1)) {
            func_800252A4(SFX_48_ARCADE_RUNNING_OUT_OF_TIME); // playSFX(runningOutOfTimeJingle)
        }
    }
    if (D_80770DF8 == 0 && arcade_next_sfx > 0) {
        temp = (s16) arcade_next_sfx;
        func_80737638(D_8076D1F8, temp, 0x7FFF, 0x3F, 1.0f, 0, &D_80770DF8);
    }
    if (D_8004A760 < arcade_current_score) {
        D_8004A760 = arcade_current_score;
    }
    if (D_8004C6DC++ == 0x3C) {
        arcade_lives_visual = arcade_lives_internal;
        arcade_game_state = 0;
        D_8004BCD0[func_80024860(0xD)].unk19 = 2;
    }
    func_80030FEC(); //update objects
    func_8002B2C0(&sp34);
    if (arcade_game_state == 0) {
        if (arcade_background_visual == 2) {
            func_800313B8(); //100m_flame_spawn_check
        }
        if (arcade_background_visual == 4) {
            func_800311E0(); //50m_pie_spawn_check
        }
        if ((newly_pressed_input & START_BUTTON) != 0) {
            func_8002549C();
            D_8004C724 = 4;
        }
    }
    *arg0 = sp34;
}

void func_8002549C(void) {
    int x, y;
    s32 index;
    for (x = 0x60; x < 0xe0; x += 0x10) {
        for (y = 0x8C; y < 0xCC; y += 0x10) {
            index = func_800247B8();
            D_8004BCD0[index] = D_8004A6B8;
            D_8004BCD0[index].x_position = x;
            D_8004BCD0[index].y_position = y;
        }
    }
    D_8004A768 = 0;
    D_8004C70C = D_807ECDE8->unk3;
    D_8004A744 = 0;
}

void func_800255A8(void) {
    s32 temp_v0;
    do {
        temp_v0 = func_80024860(0x1C);
        if (temp_v0 >= 0) {
            D_8004BCD0[temp_v0].unk18 = 0;
        }
    } while (temp_v0 >= 0);
}

void func_800255F4(Gfx **arg0) {
    Gfx *sp2C;

    sp2C = *arg0;
    func_800259D0(&sp2C);
    func_8002B2C0(&sp2C);
    if (newly_pressed_input & U_JPAD
        || (D_807ECDE8->unk3 >= 0x1F && D_8004C70C < 0x1F)
    ) {
        D_8004A768--;
    }
    if (newly_pressed_input & D_JPAD
        || (D_807ECDE8->unk3 < -0x1E && D_8004C70C >= -0x1E)
    ) {
        D_8004A768++;
    }

    if (D_8004A768 >= 3) {
        D_8004A768 = 0;
    }

    if (D_8004A768 < 0) {
        D_8004A768 = 2;
    }
    D_8004C70C = D_807ECDE8->unk3;
    if (newly_pressed_input & CONT_START) {
        func_800255A8();
        D_8004C724 = 5;
    }

    if (newly_pressed_input & (CONT_A | CONT_B)) {
        switch(D_8004A768) {
            case 0:
                func_800255A8();
                D_8004C724 = 5;
                break;
            case 1:
                if (!D_8004A744) {
                    func_8060C8AC(2);
                    func_8002440C();
                    func_80024320();
                    if (D_8004A760 < arcade_current_score)
                        D_8004A760 = arcade_current_score;
                    D_8004A744 = 1;
                }
                break;
            case 2:
                func_80024C34();
                break;
        }
    }
    *arg0 = sp2C;
}

void func_800257D8(void) {
    int i;
    ArcadeStruct1 *tmp_v1;
    for (i = 0; i < 80; i++) {
        D_8004BCD0[i].unk18 = 0;
    }
    for (i = 0; i < (D_8004C723 & 3) + 1; i++) {
        tmp_v1 = &D_8004BCD0[func_800246EC()];
        *tmp_v1 = arcade_dk_how_high_obj_template;
        tmp_v1->y_position -= i * 0x20;
    }//L800258C0

    D_8004C6DC = 0;
    if (D_8004C723 / 4 + 1 >= 0xA) {
        D_8004A76C = 9;
    } else {
        D_8004A76C = D_8004C723 / 4 + 1;
    }
    func_80737638(D_8076D1F8, 0x47, 0x7fff, 0x3f, 1.0f, 0, 0);
    D_8004C724 = 2;
    arcade_game_state = 1;
}

void func_80025960(Gfx **arg0) {
    Gfx *sp1C = *arg0;
    func_800259D0(&sp1C);
    func_8002B2C0(&sp1C);
    if (D_8004C6DC++ >= 0xa1) {
        func_80029968(); //setup stage
        D_8004C724 = 5;
    }
    *arg0 = sp1C;
}

void func_800259D0(Gfx **arg0) {
    Gfx *sp4C = *arg0;
    gDPSetAlphaCompare(sp4C++, G_AC_NONE);
    gDPSetTexturePersp(sp4C++, G_TP_NONE);
    gDPSetTextureFilter(sp4C++, G_TF_BILERP);
    gDPSetTextureConvert(sp4C++, G_TC_FILT);
    gDPSetTextureDetail(sp4C++, G_TD_CLAMP);
    gDPSetTextureLOD(sp4C++, G_TL_TILE);
    gDPSetTextureLUT(sp4C++, G_TT_NONE);
    gDPSetPrimColor(sp4C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetRenderMode(sp4C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(sp4C++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetScissor(sp4C++, G_SC_NON_INTERLACE, 48, 36, 272, 232);

    switch(D_8004C724) {
        case 0://L80025B68
            if (D_8004C6DC & 0x200) {
                func_80026680(&sp4C);
            }
            break;
        case 1:
        case 4:
        case 5://L80025B88
            switch(arcade_background_visual) {
                case 1:
                    func_800268AC(&sp4C);
                    break;
                case 2:
                    func_80026EF4(&sp4C);
                    break;
                case 3:
                    func_800275E8(&sp4C);
                    break;
                default:
                    func_80027A38(&sp4C);
                    break;
            }
            break;
    }
    *arg0 = sp4C;
}

void func_80025C08(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3) {
    int i;
    Gfx *sp60;

    D_8004C719 = 8;
    D_8004C71A = 4;
    D_8004C6D4 = 0x400;
    if (arcade_background_visual == 2) { D_8004C6D0 = &D_80032B90; }
    else if (arcade_background_visual == 4) { D_8004C6D0 = &D_80032BD8; }
    else { D_8004C6D0 = &D_80032B48; }//L80025CC0
    
    guSprite2DInit(
        D_8004BB30 + D_807444FC, D_8004C6D0, NULL, 
        D_8004C719, D_8004C719, D_8004C71A, G_IM_FMT_RGBA, 
        G_IM_SIZ_16b, 0, 0
    );

    guSprite2DInit(
        D_8004BB60 + D_807444FC, D_8004C6D0, NULL, 
        D_8004C719, D_8004C719, 1, G_IM_FMT_RGBA, 
        G_IM_SIZ_16b, 0, 0
    );

    guSprite2DInit(
        D_8004BB90 + D_807444FC, D_8004C6D0, NULL, 
        D_8004C719, D_8004C719, 2, G_IM_FMT_RGBA, 
        G_IM_SIZ_16b, 0, 0
    );

    guSprite2DInit(
        D_8004BBC0 + D_807444FC, D_8004C6D0, NULL, 
        D_8004C719, D_8004C719, 3, G_IM_FMT_RGBA, 
        G_IM_SIZ_16b, 0, 0
    );
    sp60 = *arg0;
    func_8070E8F0(&sp60, D_8004BB30 + D_807444FC);
    func_8070F2C8(0x400, D_8004C6D6, 0, 0);

    for (i = 0; i < arg3 / 4; i++) {
        func_8070F2FC(&sp60, 4 * arg1, 4.0 * (f64)(arg2 + 4 * i + 8));
    }//L80025ED8
    D_8004C71A = arg3 % 4;
    if (D_8004C71A) {
        switch(D_8004C71A) {
            case 1:
                func_8070E8F0(&sp60, D_8004BB60 + D_807444FC);
                break;
            case 2:
                func_8070E8F0(&sp60, D_8004BB90 + D_807444FC);
                break;
            case 3:
                func_8070E8F0(&sp60, D_8004BBC0 + D_807444FC);
                break;
        }
        func_8070F2C8(0x400, D_8004C6D6, 0, 0);
        func_8070F2FC(&sp60, 4 * arg1, 4.0 * (f64)(arg2 + 4 * i + 8));
    }
    *arg0 = sp60;
}

void func_80026050(Gfx **arg0) {
    Gfx *sp2C;
    s32 sp28;
    
    sp2C = *arg0;
    func_80025C08(&sp2C, 0x70, 0x1C, 0x2E);
    func_80025C08(&sp2C, 0x80, 0x1C, 0x2E);
    func_80025C08(&sp2C, 0xB0, 0x38, 0x12);
    if (D_8004C724 == 1) {
        if (D_8004C6DC < 0x190) {
            sp28 = 0x82 - ((D_8004C6DC-0x3C)/0x14)*8;
            if (sp28 >= 0x83) {
                sp28 = 0x82;
            }
            if (sp28 < 0x22)
                sp28 = 0x22;
            func_80025C08(&sp2C, 0xA0, 0x51, sp28);
            func_80025C08(&sp2C, 0xb0, 0x51, sp28);
        }
    }//L80026134
    else {
        func_80025C08(&sp2C, 0x88, 0x50, 0x4);
        func_80025C08(&sp2C, 0x88, 0x5b, 0xc);
        func_80025C08(&sp2C, 0xe8, 0x53, 0xe);
        func_80025C08(&sp2C, 0x50, 0x70, 0xe);
        func_80025C08(&sp2C, 0x78, 0x6e, 0x12);
        func_80025C08(&sp2C, 0xd8, 0x69, 0x8);
        func_80025C08(&sp2C, 0xd8, 0x7d, 0x8);
        func_80025C08(&sp2C, 0x70, 0x87, 0x5);
        func_80025C08(&sp2C, 0x70, 0x99, 0x8);
        func_80025C08(&sp2C, 0xA8, 0x89, 0x16);
        func_80025C08(&sp2C, 0xE8, 0x8D, 0xE);
        func_80025C08(&sp2C, 0x50, 0xAA, 0xE);
        func_80025C08(&sp2C, 0x90, 0xA6, 0x15);
        func_80025C08(&sp2C, 0x80, 0xC1, 0x4);
        func_80025C08(&sp2C, 0x80, 0xD1, 0x8);
        func_80025C08(&sp2C, 0xE8, 0xC7, 0xE);
    }
    //L8002626C
    *arg0 = sp2C;
}

void func_8002628C(Gfx **arg0) {
    Gfx *sp24;
    sp24 = *arg0;
    func_80025C08(&sp24, 0x38, 0xBD, 0x1C);
    func_80025C08(&sp24, 0x100, 0xBD, 0x1C);
    func_80025C08(&sp24, 0x40, 0x9B, 0x1C);
    func_80025C08(&sp24, 0xF8, 0x9B, 0x1C);
    func_80025C08(&sp24, 0x48, 0x7A, 0x1A);
    func_80025C08(&sp24, 0xF0, 0x7A, 0x1A);
    func_80025C08(&sp24, 0x50, 0x58, 0x1C);
    func_80025C08(&sp24, 0xE8, 0x58, 0x1C);
    if (D_8004C708 == 0) {
        func_80025C08(&sp24, 0x98, 0xBD, 0x1C);
        func_80025C08(&sp24, 0x78, 0x9B, 0x1C);
        func_80025C08(&sp24, 0xC0, 0x9B, 0x1C);
        func_80025C08(&sp24, 0x98, 0x7A, 0x1A);
        func_80025C08(&sp24, 0x70, 0x58, 0x1C);
        func_80025C08(&sp24, 0xC8, 0x58, 0x1C);
    }
    *arg0 = sp24;
}

void func_800263EC(Gfx **arg0) {
    Gfx *sp24;
    sp24 = *arg0;
    func_80025C08(&sp24, 0x70, 0x1C, 0x31);
    func_80025C08(&sp24, 0x80, 0x1C, 0x31);
    func_80025C08(&sp24, 0xB0, 0x38, 0x15);
    func_80025C08(&sp24, 0xD0, 0x54, 0x15);
    func_80025C08(&sp24, 0x100, 0x62, 0x1C);
    func_80025C08(&sp24, 0xB8, 0x77, 0x15);
    func_80025C08(&sp24, 0x40, 0x7E, 0x2A);
    func_80025C08(&sp24, 0x70, 0x7E, 0x38);
    func_80025C08(&sp24, 0x80, 0x7E, 0x38);
    func_80025C08(&sp24, 0xE8, 0x85, 0x15);
    func_80025C08(&sp24, 0x100, 0xA8, 0xE);
    func_80025C08(&sp24, 0x38, 0xAF, 0x1C);
    *arg0 = sp24;
}

void func_80026518(Gfx **arg0) {
    Gfx *sp24;
    sp24 = *arg0;
    func_80025C08(&sp24, 0x70, 0x1C, 0x31);
    func_80025C08(&sp24, 0x80, 0x1C, 0x31);
    func_80025C08(&sp24, 0xB0, 0x38, 0x15);
    func_80025C08(&sp24, 0x48, 0xBD, 0x1C);
    func_80025C08(&sp24, 0x80, 0xBD, 0x1C);
    func_80025C08(&sp24, 0xB8, 0xBD, 0x1C);
    func_80025C08(&sp24, 0xF0, 0xBD, 0x1C);
    func_80025C08(&sp24, 0x70, 0x9A, 0x1C);
    func_80025C08(&sp24, 0xC0, 0x9A, 0x1C);
    func_80025C08(&sp24, 0x48, 0x77, 0x1C);
    func_80025C08(&sp24, 0x80, 0x77, 0x1C);
    func_80025C08(&sp24, 0xB8, 0x77, 0x1C);
    func_80025C08(&sp24, 0xF0, 0x77, 0x1C);
    func_80025C08(&sp24, 0x40, 0x62, 0xE);
    func_80025C08(&sp24, 0xF8, 0x62, 0xE);
    *arg0 = sp24;
}

void func_80026680(Gfx **gpp) {
    int i;
    int j;
    Gfx *sp94;
    s32 sp64[0xC] = D_8004A798;
    s32 word;

    sp94 = *gpp;
    D_8004C719 = 8;
    D_8004C71A = 8;
    D_8004C6D4 = 0x400;
    if (D_8004C6DC & 0x182)  D_8004C6D0 = &D_80032C20;
    else                    D_8004C6D0 = &D_80032DF8;
    
    func_80005A90(&D_8004BB00[D_807444FC], D_8004C6D0, 0, 
        D_8004C719, D_8004C719, D_8004C71A, 0, 2, 0, 0
    );
    func_8070E8F0(&sp94, &D_8004BB00[D_807444FC]);
    func_8070F2C8(0x400, D_8004C6D4, 0, 0);
    for (i = 0; i < 0xC; i++) {//L80026800
        word = sp64[i];
        for (j = 0; j < 0x19; j++) {//L8002680C
            if ((1 << j) & word) {
                func_8070F2FC(&sp94,  0x3E0 - j * 0x20, ((i * 8 + 0x3F) * 4.0));
            }
        }
    }
    *gpp = sp94;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_800268AC.s")
#else
void func_800268AC(Gfx **gpp) {
    int i;
    Gfx *sp68;
    int x;
    int y;

    D_8004C719 = 8;
    D_8004C71A = 8;
    D_8004C6D4 = 0x492;

    D_8004C6D0 = &D_80034568;
    func_80005A90(&D_8004BB00[D_807444FC], D_8004C6D0, 0, 
        D_8004C719, D_8004C719, D_8004C71A, 0, 2, 0, 0
    );
    sp68 = *gpp;

    
    func_8070E8F0(&sp68, &D_8004BB00[D_807444FC]);
    func_8070F2C8(0x400, D_8004C6D4, 0, 0);
    for (i = 0; i < 6; i++) {
        func_8070F2FC(&sp68, 0x220 + i*0x20, 0xE0);
    }
    
    if (!((s32)D_8004C708 < 6)) {
        for (i = 0; i < 0xE; i++) {////L800269FC
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x380);
        }
        for (i = 0xE; i < 0x1C; i++) {//L80026A50
            func_8070F2FC(&sp68, 0xC0 + i*0x20, ((0xf7 - (i-0xC)/2)*0.875 + 8.0)*4.0);
        }
    } else {//L80026AC0
        for (i = 0; i < 0x1C; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x368);
        }
    }//L80026B0C

    if (!((s32)D_8004C708 < 5)) {
        for (i  = 0; i < 0x1A; i++) {//L80026B30
            func_8070F2FC(&sp68, 0xC0 + i*0x20, ((0xCF + (i/2))*0.875 + 8.0)*4.0);
        }
    } else {//L80026B98
        for (i = 0; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x2f4);
        }
    }//L80026BC0


    if (!((s32)D_8004C708 < 4)) {
        for (i  = 2; i < 0x1C; i++) {//L80026B30
            func_8070F2FC(&sp68, 0xC0 + i*0x20, ((0xbb - (i/2))*0.875 + 8.0)*4.0);
        }
    } else {//L80026C50
        for (i = 2; i < 0x1C; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x281);
        }
    }//L80026C74

    if (!((s32)D_8004C708 < 3)) {
        for (i = 0; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, ((0x8d + (i/2))*0.875 + 8.0)*4.0);
        }
    } else {//L80026D04
        for (i = 0; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x20d);
        }
    }//L80026D24

    if (!((s32)D_8004C708 < 2)) {
        for (i = 2; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, ((0x79 - (i/2))*0.875 + 8.0)*4.0);
        }
    } else {//L80026DB4
        for (i = 0; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0x100 + i*0x20, 0x19a);
        }
    }//L80026DD8

    if (!((s32)D_8004C708 < 1)) {
        for (i = 0; i < 0x12; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x142);
        }
        for (i = 0x12; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, ((0x53 + ((i - 0x10)/2))*0.875 + 8.0)*4.0);
        }
    } else {//L80026E90
        for (i = 0; i < 0x1A; i++) {
            func_8070F2FC(&sp68, 0xC0 + i*0x20, 0x142);
        }
    } 

    func_80026050(&sp68);
    *gpp = sp68;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80026EF4.s")

void func_800274E0(s32 *arg0, u8 arg1, u8 arg2, s16 arg3) {
    u8 i;
    s32 sp40;

    sp40 = *arg0;
    for (i = arg1; i < arg2; i++) {
        func_8070F2FC(&sp40, (i << 5) + 0xC0, ((arg3 * 0.875) + 8.0) * 4.0);
    }
    *arg0 = sp40;
}

#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_800275E8.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80027A38.s")
#else
//arcade_50m_draw
void func_80027A38(Gfx **arg0) {
    int i, j;
    Gfx *sp6C;

    sp6C = *arg0;
    D_8004C719 = 8;
    D_8004C71A = 10;
    D_8004C6D4 = 1170;

    //50m solid beam
    D_8004C6D0 = &D_80032D50;
    func_80005A90(&D_8004BB00[D_807444FC], D_8004C6D0, 0, 
        D_8004C719, D_8004C719, D_8004C71A, 0, 2, 0, 0
    );
    func_8070E8F0(&sp6C, &D_8004BB00[D_807444FC]);
    func_8070F2C8(0x400, D_8004C6D6, 0, 0);
    for (i = 0; i < 0x6; i++) {
        func_8070F2FC(&sp6C, 0x220 + 0x20*i, 0xe0);
    }
    for (i = 0; i < 0x1C; i++) {
        func_8070F2FC(&sp6C, 0xC0 + 0x20*i, 0x380);
    }
    for (i = 1; i < 0x1B; i++) {
        if (i != 6 && i != 7 && i != 0x13 && i != 0x14) {
            func_8070F2FC(&sp6C, 0xC0 + 0x20*i, 0x268);
        }
    }

    //50m conveyer belt
    D_8004C6D0 = &D_80032CA8;
    func_80005A90(&D_8004BC20[D_807444FC], D_8004C6D0, 0, 
        D_8004C719, D_8004C719, D_8004C71A, 0, 2, 0, 0
    );
    func_8070E8F0(&sp6C, &D_8004BC20[D_807444FC]);
    func_8070F2C8(0x400, D_8004C6D6, 0, 0);
    for (i = 0; i < 0x1A; i++) {
        func_8070F2FC(&sp6C, 0xE0 + 0x20*i, 0x150);
    }
    for (i = 0; i < 0x1C; i++) {
        if (i < 0xC || i >= 0x10) {
            func_8070F2FC(&sp6C, 0xC0 + 0x20*i, 0x1DC);
        }
    }
    for (i = 0; i < 0x1A; i++) {
        func_8070F2FC(&sp6C, 0xE0 + 0x20*i, 0x2f4);
    }

    //50m background grate
    D_8004C6D0 = &D_800342B8;
    func_80005A90(&D_8004BC50[D_807444FC], D_8004C6D0, 0, 
        D_8004C719, D_8004C719, D_8004C71A, 0, 2, 0, 0
    );
    func_8070E8F0(&sp6C, &D_8004BC50[D_807444FC]);
    func_8070F2C8(0x400, D_8004C6D6, 0, 0);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            func_8070F2FC(&sp6C, 0x240 + 0x20*i, ((0x9f - 8*j)*0.875 + 8.0)*4.0);
        }
    }
    func_80026518(&sp6C);
    *arg0 = sp6C;
}
#endif

// death()?
void func_80027E8C(void) {
    func_800252A4(SFX_0_SILENCE);
    func_80737638(D_8076D1F8, SFX_42_ARCADE_JUMPMAN_HIT, 0x7FFF, 0x3F, 1.0f, 0, 0);
    D_8004BCD0[D_8004C71F].unk19 = 8;
    D_8004BCD0[D_8004C71F].x_velocity = 0.0f;
    D_8004BCD0[D_8004C71F].unk10 = 0.0f;
    arcade_game_state = 1;
}

void arcade_25m_setup(void) {
    int v1 = 0x25;
    D_8004BCD0[func_800246EC()] = arcade_pauline_bottom_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_pauline_top_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_help_text_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_dk_25m_obj_template;
    if (D_8004A76C == 2 && D_8004A740)
        D_8004BCD0[func_800246EC()] = arcade_nintendo_coin_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_bonus_osd_obj_template;
    D_8004C71F = func_800246EC();
    D_8004BCD0[D_8004C71F] = arcade_jumpman_obj_template;
    D_8004BCD0[v1] = arcade_oil_drum_obj_template;
    v1--;

    D_8004BCD0[v1] = arcade_hammer_obj_template;
    v1--;

    D_8004BCD0[v1] = arcade_hammer_obj_template;
    D_8004BCD0[v1].x_position = 68.0f;
    D_8004BCD0[v1].y_position = 110.0f;
    v1--;

    D_8004BCD0[v1--] = arcade_barrel_stack_obj_template;

    D_8004BCD0[v1] = arcade_barrel_stack_obj_template;
    D_8004BCD0[v1].x_position = 48.0f;
    D_8004BCD0[v1--].unk1C = 1;
    
    D_8004BCD0[v1] = arcade_barrel_stack_obj_template;
    D_8004BCD0[v1].y_position = 65.0f;
    D_8004BCD0[v1--].unk1C = 2;

    D_8004BCD0[v1] = arcade_barrel_stack_obj_template;
    D_8004BCD0[v1].x_position = 48.0f;
    D_8004BCD0[v1].y_position = 65.0f;
    D_8004BCD0[v1].unk1C = 3;

    D_8004C708 = 7;
}

void arcade_100m_setup(void) {
    s32 i;
    s32 indx;
    f32 f6;

    u8 sp3C[8][2] = D_8004A81C;
    u32 s1 = 1;

    D_8004BCD0[func_800246EC()] = arcade_pauline_bottom_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_pauline_top_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_help_text_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_dk_100m_obj_template;
    if (D_8004A76C == 2 && D_8004A740)
        D_8004BCD0[func_800246EC()] = arcade_nintendo_coin_obj_template;

    for (i = 0; i < 8; i++) {
        indx = func_800246EC();
        D_8004BCD0[indx] = arcade_rivet_obj_template;
        D_8004BCD0[indx].x_position = (f32)sp3C[i][0];
        D_8004BCD0[indx].y_position = (f32)sp3C[i][1];
        D_8004BCD0[indx].unk1C = s1;
        s1 <<= 1;
    }

    indx = func_800246EC();
    D_8004BCD0[indx] = arcade_bonus_osd_obj_template;
    D_8004BCD0[indx].unk14 = &D_800335D8;

    D_8004C71F = func_800246EC();
    D_8004BCD0[D_8004C71F] = arcade_jumpman_obj_template;

    D_8004BCD0[0x25] = arcade_bonus_item_obj_template;
    D_8004BCD0[0x25].unk14 = &D_80038FE8;

    D_8004BCD0[0x24] = arcade_bonus_item_obj_template;
    D_8004BCD0[0x24].x_position = 252.0f;
    D_8004BCD0[0x24].y_position = 208.0f;

    D_8004BCD0[0x23] = arcade_bonus_item_obj_template;
    D_8004BCD0[0x23].unk14 = &D_800391F0;
    D_8004BCD0[0x23].x_position = 84.0f;
    D_8004BCD0[0x23].y_position = 93.0f;

    D_8004BCD0[0x22] = arcade_hammer_obj_template;
    D_8004BCD0[0x22].x_position = 60.0f;
    D_8004BCD0[0x22].y_position = 152.0f;

    D_8004BCD0[0x21] = arcade_hammer_obj_template;
    D_8004BCD0[0x21].x_position = 156.0f;
    D_8004BCD0[0x21].y_position = 114.0f;
}

void arcade_75m_setup(void) {
    s32 a0 = 0x25;
    s32 tmp;
    f32 tmp_f2;

    D_8004BCD0[func_800246EC()] = arcade_pauline_bottom_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_pauline_top_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_help_text_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_dk_75m_obj_template;
    if (D_8004A76C == 2 && D_8004A740)
        D_8004BCD0[func_800246EC()] = arcade_nintendo_coin_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_bonus_osd_obj_template;
    D_8004C71F = func_800246EC();
    D_8004BCD0[D_8004C71F] = arcade_jumpman_obj_template;
    D_8004BCD0[D_8004C71F].x_position = 56.0;
    D_8004BCD0[D_8004C71F].y_position = 231.0;

    D_8004BCD0[a0--] = arcade_elevator_obj_template;

    D_8004BCD0[a0] = arcade_elevator_obj_template;
    D_8004BCD0[a0--].x_position = 144.0f;

    D_8004BCD0[a0] = arcade_elevator_obj_template;
    D_8004BCD0[a0].y_position = 238.0f;
    D_8004BCD0[a0--].unk1B = 1;

    D_8004BCD0[a0] = arcade_elevator_obj_template;
    D_8004BCD0[a0].x_position = 144.0f;
    D_8004BCD0[a0].y_position = 238.0f;
    D_8004BCD0[a0--].unk1B = 1;

    D_8004BCD0[a0] = arcade_bonus_item_obj_template;
    D_8004BCD0[a0].x_position = 260.0f;
    D_8004BCD0[a0].y_position = 103.0f;
    D_8004BCD0[a0--].unk14 = &D_80038FE8;

    D_8004BCD0[a0] = arcade_bonus_item_obj_template;
    D_8004BCD0[a0].x_position = 60.0f;
    D_8004BCD0[a0].y_position = 135.0f;
    D_8004BCD0[a0--].unk14 = &D_800391F0;

    tmp = func_800246EC();
    D_8004BCD0[tmp] = arcade_flame_enemy_obj_template;
    D_8004BCD0[tmp].x_velocity = 0.5;
    D_8004BCD0[tmp].unk1A = 1;
    D_8004BCD0[tmp].x_position = 114.0f;
    D_8004BCD0[tmp].y_position = 135.0f;

    tmp = func_800246EC();
    D_8004BCD0[tmp] = arcade_flame_enemy_obj_template;
    D_8004BCD0[tmp].x_velocity = 0.5;
    D_8004BCD0[tmp].unk1A = 1;
    D_8004BCD0[tmp].x_position = 260.0f;
    D_8004BCD0[tmp].y_position = 103.0f;

    D_8004BC88[0][0] = 40.0f;
    D_8004BC88[1][0] = 40.0f;
    D_8004BC88[2][0] = 40.0f;
    D_8004BC88[3][0] = 104.0f;
    D_8004BC88[4][0] = 104.0f;
    D_8004BC88[5][0] = 104.0f;
    D_8004BC88[0][1] = 95.0f;
    D_8004BC88[3][1] = 95.0f;
    D_8004BC88[1][1] = 143.0f;
    D_8004BC88[4][1] = 143.0f;
    D_8004BC88[2][1] = 191.0f;
    D_8004BC88[5][1] = 191.0f;
    tmp_f2 = (func_800246C8(D_8004A76C, 4.0f) - 2.0)/16 + 0.5;
    D_8004BC88[3][2] = tmp_f2;
    D_8004BC88[0][2] = -tmp_f2;
    D_8004BC88[1][2] = -tmp_f2;
    D_8004BC88[2][2] = -tmp_f2;
    D_8004BC88[4][2] = tmp_f2;
    D_8004BC88[5][2] = tmp_f2;
}

void arcade_50m_setup(void) {
    s32 i;
    int v1 = 0x25;
    D_8004BCD0[func_800246EC()] = arcade_moving_ladder_obj_template;
    i = func_800246EC();
    D_8004BCD0[i] = arcade_moving_ladder_obj_template;
    D_8004BCD0[i].x_position = 244.0f;
    D_8004BCD0[func_800246EC()] = arcade_pauline_bottom_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_pauline_top_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_help_text_obj_template;
    D_8004BCD0[func_800246EC()] = arcade_dk_50m_obj_template;
    if (D_8004A76C == 2 && D_8004A740)
        D_8004BCD0[func_800246EC()] = arcade_nintendo_coin_obj_template;

    i = func_800246EC();
    D_8004BCD0[i] = arcade_bonus_osd_obj_template;
    D_8004BCD0[i].unk14 = &D_80033C48;

    D_8004C71F = func_800246EC();
    D_8004BCD0[D_8004C71F] = arcade_jumpman_obj_template;

    D_8004BCD0[0x25] = arcade_oil_drum_obj_template;
    D_8004BCD0[0x25].x_position = 152.0f;
    D_8004BCD0[0x25].y_position = 127.0f;

    D_8004BCD0[0x24] = arcade_oil_drum_flame_obj_template;
    D_8004BCD0[0x24].x_position = 152.0f;
    D_8004BCD0[0x24].y_position = 113.0f;

    D_8004BCD0[0x23] = arcade_bonus_item_obj_template;
    D_8004BCD0[0x23].unk14 = &D_80038FE8;
    D_8004BCD0[0x23].x_position = 172.0f;

    D_8004BCD0[0x22] = arcade_bonus_item_obj_template;
    D_8004BCD0[0x22].y_position = 167.0f;
    D_8004BCD0[0x22].x_position = 116.0f;

    D_8004BCD0[0x21] = arcade_bonus_item_obj_template;
    D_8004BCD0[0x21].unk14 = &D_800391F0;
    D_8004BCD0[0x21].y_position = 167.0f;
    D_8004BCD0[0x21].x_position = 252.0f;

    D_8004BCD0[0x20] = arcade_hammer_obj_template;
    D_8004BCD0[0x20].x_position = 68.0f;
    D_8004BCD0[0x20].y_position = 148.0f;

    D_8004BCD0[0x1F] = arcade_hammer_obj_template;
    D_8004BCD0[0x1F].x_position = 156.0f;
    D_8004BCD0[0x1F].y_position = 188.0f;

    D_8004BCD0[0x1E] = arcade_pulley_obj_template;

    D_8004BCD0[0x1D] = arcade_pulley_obj_template;
    D_8004BCD0[0x1D].unk1A = 1;
    D_8004BCD0[0x1D].unk1B = 1;
    D_8004BCD0[0x1D].unk1C = 0;
    D_8004BCD0[0x1D].x_position = 256.0f;
    D_8004BCD0[0x1D].y_position = 84.0f;

    D_8004BCD0[0x1C] = arcade_pulley_obj_template;
    D_8004BCD0[0x1C].unk1A = 1;
    D_8004BCD0[0x1C].unk1B = 1;
    D_8004BCD0[0x1C].unk1C = 1;
    D_8004BCD0[0x1C].y_position = 124.0f;
    D_8004BCD0[0x1C].x_position = 139.0f;

    D_8004BCD0[0x1B] = arcade_pulley_obj_template;
    D_8004BCD0[0x1B].y_position = 124.0f;
    D_8004BCD0[0x1B].unk1C = 2;
    D_8004BCD0[0x1B].x_position = 165.0f;

    D_8004BCD0[0x1A] = arcade_pulley_obj_template;
    D_8004BCD0[0x1A].y_position = 204.0f;
    D_8004BCD0[0x1A].unk1C = 3;
    D_8004BCD0[0x1A].x_position = 48.0f;

    D_8004BCD0[0x19] = arcade_pulley_obj_template;
    D_8004BCD0[0x19].unk1A = 1;
    D_8004BCD0[0x19].unk1B = 1;
    D_8004BCD0[0x19].x_position = 256.0f;
    D_8004BCD0[0x19].y_position = 204.0f;
    D_8004BCD0[0x19].unk1C = 3;
}

void func_80029968(void) {
    int i;
    int tmp_v0;

    D_8004C708 = 0;
    arcade_background_visual = D_8004A788[D_8004C723 & 3];
    for (i = 0; i < 0x50; i++) { //clear arcade_obj_array
        D_8004BCD0[i].unk18 = 0;
    }

    switch(arcade_background_visual) {
        case 1:
            arcade_25m_setup();
            break;
        case 2:
            arcade_100m_setup();
            break;
        case 3:
            arcade_75m_setup();
            break;
        default:
            arcade_50m_setup();
            break;
    }
    func_80025240(); //queue stage music
    tmp_v0 = D_8004A76C * 0xA + 0x28;
    if (tmp_v0 >= 0x5B) {
        D_8004C71E = 0x5A;
    } else {
        D_8004C71E = tmp_v0;
    }
    D_8004C710 = 0;
    D_8004C718 = 0xFF;
    D_8004A764 = 0;
    D_8004C6DC = 0;
    arcade_game_state = 1;
    D_8004C6F8 = 1;
    D_8004C721 = 1;
    D_8004A308[0] = 0;
    D_8004A308[1] = 0;
    D_8004A308[2] = 0;
    D_8004A308[3] = 0;

}

s32 func_80029ACC(s32 arg0, s32 arg1) {
    s32 phi_v1;

    if (arg1 < 0x5D) {
        D_8004C6F0 = 0x88;
    } else {
        D_8004C6F0 = 0x36;
    }
    D_8004C6F4 = 0x10A;
    if (arg1 < 0x3F) {
        D_8004C6F8 = 0;
        if ((arg0 >= 0x85) && (arg0 < 0xBC)) {
            phi_v1 = 0x37;
        } else {
            phi_v1 = 0xF8;
        }
    } else if (arg1 < 0x5D) {
        D_8004C6F8 = 1;
        phi_v1 = arg0 / 0x10;
        if (arg0 / 0x10 < 0xB) {
            phi_v1 = 0xB;
        }
        phi_v1 += 0x48;
        if (arg0 >= 0x105) {
            phi_v1 = 0xF8;
        }
    } else if (arg1 < 0x7F) {
        D_8004C6F8 = 2;
        phi_v1 = 0x7C - (arg0 / 0x10);
        if (arg0 < 0x3C) {
            phi_v1 = 0xF8;
        }
    } else if (arg1 < 0xA0) {
        D_8004C6F8 = 3;
        phi_v1 = (arg0 / 0x10) + 0x8A;
        if (arg0 >= 0x105) {
            phi_v1 = 0xF8;
        }
    } else if (arg1 < 0xC3) {
        D_8004C6F8 = 4;
        phi_v1 = 0xBE - (arg0 / 0x10);
        if (arg0 < 0x3C) {
            phi_v1 = 0xF8;
        }
    } else if (arg1 < 0xE1) {
        D_8004C6F8 = 5;
        phi_v1 = (arg0 / 0x10) + 0xCC;
        if (arg0 >= 0x105) {
            phi_v1 = 0xF8;
        }
    } else {
        D_8004C6F8 = 6;
        phi_v1 = 0x100 - (arg0 / 0x10);
        if (phi_v1 >= 0xF8) {
            phi_v1 = 0xF7;
        }
    }
    if (phi_v1 < arg1) {
        D_8004C6F8++;
    }
    return phi_v1;
}

s32 func_80029CD0(s32 arg0, s32 arg1) {
    s32 var_v1;

    D_8004C6F0 = 0x36;
    D_8004C6F4 = 0x10A;
    if (arg1 < 0x6E) {
        D_8004C6F8 = 1;
        if ((arg0 >= 0x4D) && (arg0 < 0xF4) && ((arg0 < 0x6C) || (arg0 >= 0x6D) || (D_8004C718 & 0x40)) && ((arg0 < 0xD4) || (arg0 >= 0xD5) || (D_8004C718 & 0x80))) {
            var_v1 = 0x5D;
        } else {
            var_v1 = 0xF7;
        }
    } else if (arg1 < 0x8C) {
        D_8004C6F8 = 2;
        if ((arg0 >= 0x45) && (arg0 < 0xFC) && ((arg0 < 0x6C) || (arg0 >= 0x6D) || (D_8004C718 & 0x10)) && ((arg0 < 0xD4) || (arg0 >= 0xD5) || (D_8004C718 & 0x20))) {
            var_v1 = 0x84;
        } else {
            var_v1 = 0xF7;
        }
    } else if (arg1 < 0xBE) {
        D_8004C6F8 = 3;
        if ((arg0 >= 0x3D) && (arg0 < 0x104) && ((arg0 < 0x6C) || (arg0 >= 0x6D) || (D_8004C718 & 4)) && ((arg0 < 0xD4) || (arg0 >= 0xD5) || (D_8004C718 & 8))) {
            var_v1 = 0xAA;
        } else {
            var_v1 = 0xF7;
        }
    } else if (arg1 < 0xDC) {
        D_8004C6F8 = 4;
        if (((arg0 < 0x6C) || (arg0 >= 0x6D) || (D_8004C718 & 1)) && ((arg0 < 0xD4) || (arg0 >= 0xD5) || (D_8004C718 & 2))) {
            var_v1 = 0xD0;
        } else {
            var_v1 = 0xF7;
        }
    } else {
        D_8004C6F8 = 5;
        var_v1 = 0xF7;
    }
    if (var_v1 < arg1) {
        D_8004C6F8 += 1;
    }
    return var_v1;
}

s32 func_80029EFC(s32 arg0, s32 arg1) {
    s32 i;
    s32 var_v1;

    if (arg1 < 0x5D) {
        D_8004C6F0 = 0x88;
    } else {
        D_8004C6F0 = 0x36;
    }
    D_8004C6F4 = 0x10A;
    D_8004C6F8 = 1;
    if (arg1 < 0x3F) {
        if (arg0 >= 0x85 && arg0 < 0xBC) {
            var_v1 = 0x37;
            D_8004C6F8 = 0;
        } else {
            var_v1 = 0xF8;
        }
    } else if (arg1 < 0x62) {
        if (arg0 < 0xDC) {
            var_v1 = 0x57;
        } else {
            var_v1 = 0xF8;
        }
    } else if (arg1 < 0x8C) {
        if (arg0 >= 0xFD) {
            var_v1 = 0x67;
        } else if (arg0 >= 0xE5 && arg0 < 0xFC) {
            var_v1 = 0x6F;
        } else if (arg0 >= 0xCD && arg0 < 0xE4) {
            var_v1 = 0x77;
        } else if (arg0 >= 0xAD && arg0 < 0xCC) {
            var_v1 = 0x7F;
        } else if ((arg0 >= 0x65 && arg0 < 0x8C) || arg0 < 0x4C) {
            var_v1 = 0x87;
        } else {
            var_v1 = 0xF8;
        }
    } else if (arg1 < 0x94) {
        if (arg0 >= 0xE5) {
            var_v1 = 0x8F;
        } else {
            var_v1 = 0xF7;
        }
    } else if (arg1 < 0xC6) {
        if (arg0 >= 0xFD) {
            var_v1 = 0xB7;
        } else if (arg0 >= 0xE5 && arg0 < 0xFC) {
            var_v1 = 0xAF;
        } else if (arg0 >= 0xCD && arg0 < 0xE4) {
            var_v1 = 0xA7;
        } else if (arg0 >= 0xB5 && arg0 < 0xCC) {
            var_v1 = 0x9F;
        } else if (arg0 < 0x4C) {
            var_v1 = 0xBF;
        } else {
            var_v1 = 0xF8;
        }
    } else {
        if (arg1 < 0xF0) {
            if ((arg0 >= 0x6D && arg0 < 0x8C) || arg0 >= 0xF5) {
                var_v1 = 0xCF;
            } else if (arg0 >= 0xDD && arg0 < 0xF4) {
                var_v1 = 0xD7;
            } else if (arg0 >= 0xC5 && arg0 < 0xDC) {
                var_v1 = 0xDF;
            } else if ((arg0 >= 0xA5 && arg0 < 0xC4) || arg0 < 0x4C) {
                var_v1 = 0xE7;
            } else {
                var_v1 = 0xF8;
            }
        } else {
            var_v1 = 0xF7;
        }
    }
    if (arg0 >= 0x4D && arg0 < 0x64) {
        for (i = 0; i < 3; i++) {
            if ((D_8004BC88[i][1] < (arg1 + 4)) && ((arg1 - 0x10) < D_8004BC88[i][1])) {
                var_v1 = D_8004BC88[i][1];
            }
        }
    }
    if (arg0 >= 0x8D && arg0 < 0xA4) {
        for (i = 3; i < 6; i++) {
            if ((D_8004BC88[i][1] < (arg1 + 4)) && ((arg1 - 0x10) < D_8004BC88[i][1])) {
                var_v1 = D_8004BC88[i][1];
            }
        }
    }
    return var_v1;
}

s32 func_8002A264(s32 arg0, s32 arg1) {
    s32 var_v1;

    D_8004C6F0 = 0x36;
    D_8004C6F4 = 0x10A;
    if (arg1 < 0x6E) {
        D_8004C6F8 = 0;
        var_v1 = 0x57;
    } else if (arg1 < 0x8C) {
        if (arg0 < 0x9C) {
            var_v1 = 0x7F;
            D_8004C6F8 = 1;
        } else if (arg0 >= 0xA5) {
            var_v1 = 0x7F;
            D_8004C6F8 = 2;
        } else {
            var_v1 = 0xF7;
        }
    } else if (arg1 < 0xBE) {
        D_8004C6F8 = 4;
        if (((arg0 < 0x64) || (arg0 >= 0x6D)) && ((arg0 < 0xCC) || (arg0 >= 0xD5))) {
            var_v1 = 0xA7;
        } else {
            var_v1 = 0xF7;
        }
    } else if (arg1 < 0xDC) {
        D_8004C6F8 = 3;
        var_v1 = 0xCF;
    } else {
        D_8004C6F8 = 5;
        var_v1 = 0xF7;
    }
    if (var_v1 < arg1) {
        D_8004C6F8 += 1;
    }
    return var_v1;
}

s32 func_8002A390(s32 arg0, s32 arg1) {
    if (arcade_background_visual == 1) {
        func_80029ACC(arg0, arg1);
        return;
    }
    if (arcade_background_visual == 2) {
        func_80029CD0(arg0, arg1);
        return;
    }
    if (arcade_background_visual == 3) {
        func_80029EFC(arg0, arg1);
        return;
    }
    return func_8002A264(arg0, arg1);
}

s32 func_8002A408(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if ((arg1 >= arg3) & (arg5 >= arg1) & (arg2 - 4 < arg0) & (arg0 < arg2 + 3)) {
        D_8004C6E0 = arg2;
        D_8004C6E4 = arg3;
        D_8004C6E8 = arg5;
        D_8004C6EC = arg4;
        return 1;
    }
    return 0;
}


s32 func_8002A474(s32 arg0, s32 arg1) {
    if (func_8002A408(arg0, arg1, 0x84, 0xD4, 0xEB, 0xF7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xEC, 0xDA, 0xDA, 0xF2)) {
        return 2;
    }
    if (func_8002A408(arg0, arg1, 0x94, 0xB5, 0xB5, 0xD5)) {
        return 3;
    }
    if (func_8002A408(arg0, arg1, 0x54, 0xB9, 0xB9, 0xD1)) {
        return 4;
    }
    if (func_8002A408(arg0, arg1, 0x74, 0x91, 0xAB, 0xB7)) {
        return 5;
    }
    if (func_8002A408(arg0, arg1, 0xAC, 0x94, 0x94, 0xB4)) {
        return 6;
    }
    if (func_8002A408(arg0, arg1, 0xEC, 0x98, 0x98, 0xB0)) {
        return 7;
    }
    if (func_8002A408(arg0, arg1, 0xDC, 0x6F, 0x8B, 0x97)) {
        return 8;
    }
    if (func_8002A408(arg0, arg1, 0x7C, 0x75, 0x75, 0x91)) {
        return 9;
    }
    if (func_8002A408(arg0, arg1, 0x54, 0x77, 0x77, 0x8F)) {
        return 0xA;
    }
    if (func_8002A408(arg0, arg1, 0x8C, 0x53, 0x64, 0x74)) {
        return 0xB;
    }
    if (func_8002A408(arg0, arg1, 0xEC, 0x56, 0x56, 0x6E)) {
        return 0xC;
    }
    if (func_8002A408(arg0, arg1, 0xB4, 0x37, 0x37, 0x53)) {
        return 0xD;
    }
    D_8004C6E0 = 0;
    D_8004C6E4 = 300;
    D_8004C6EC = 300;
    D_8004C6E8 = 1;
    return 0;
}

s32 func_8002A734(s32 arg0, s32 arg1) {
    if (func_8002A408(arg0, arg1, 0x3C, 0xD0, 0xD0, 0xF7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x9C, 0xD0, 0xD0, 0xF7)) {
        return 2;
    }
    if (func_8002A408(arg0, arg1, 0x104, 0xD0, 0xD0, 0xF7)) {
        return 3;
    }
    if (func_8002A408(arg0, arg1, 0x44, 0xAA, 0xAA, 0xD0)) {
        return 4;
    }
    if (func_8002A408(arg0, arg1, 0x7C, 0xAA, 0xAA, 0xD0)) {
        return 5;
    }
    if (func_8002A408(arg0, arg1, 0xC4, 0xAA, 0xAA, 0xD0)) {
        return 6;
    }
    if (func_8002A408(arg0, arg1, 0xFC, 0xAA, 0xAA, 0xD0)) {
        return 7;
    }
    if (func_8002A408(arg0, arg1, 0x4C, 0x84, 0x84, 0xAA)) {
        return 8;
    }
    if (func_8002A408(arg0, arg1, 0x9C, 0x84, 0x84, 0xAA)) {
        return 9;
    }
    if (func_8002A408(arg0, arg1, 0xF4, 0x84, 0x84, 0xAA)) {
        return 0xA;
    }
    if (func_8002A408(arg0, arg1, 0x54, 0x5D, 0x5D, 0x84)) {
        return 0xB;
    }
    if (func_8002A408(arg0, arg1, 0x74, 0x5D, 0x5D, 0x84)) {
        return 0xC;
    }
    if (func_8002A408(arg0, arg1, 0xCC, 0x5D, 0x5D, 0x84)) {
        return 0xD;
    }
    if (func_8002A408(arg0, arg1, 0xEC, 0x5D, 0x5D, 0x84)) {
        return 0xE;
    }
    D_8004C6E0 = 0;
    D_8004C6E4 = 300;
    D_8004C6EC = 300;
    D_8004C6E8 = 1;
    return 0;
}

s32 func_8002AA24(s32 arg0, s32 arg1) {
    if (func_8002A408(arg0, arg1, 0xB4, 0x37, 0x37, 0x57)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xD4, 0x57, 0x57, 0x77)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x104, 0x67, 0x67, 0x8F)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xBC, 0x7F, 0x7F, 0x9F)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xEC, 0x8F, 0x8F, 0xAF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x104, 0xB7, 0xB7, 0xCF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x44, 0x87, 0x87, 0xBF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x74, 0x87, 0x87, 0xCF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x84, 0x87, 0x87, 0xCF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x3C, 0xBF, 0xBF, 0xE7)) {
        return 1;
    }
    D_8004C6E0 = 0;
    D_8004C6E4 = 300;
    D_8004C6EC = 300;
    D_8004C6E8 = 1;
    return 0;
}

s32 func_8002AC54(s32 arg0, s32 arg1) {
    s32 phi_v0;

    if (func_8002A408(arg0, arg1, 0x4C, 0xCF, 0xCF, 0xF7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x84, 0xCF, 0xCF, 0xF7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xBC, 0xCF, 0xCF, 0xF7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xF4, 0xCF, 0xCF, 0xF7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x74, 0xA7, 0xA7, 0xCF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xC4, 0xA7, 0xA7, 0xCF)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x4C, 0x7F, 0x7F, 0xA7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0x84, 0x7F, 0x7F, 0xA7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xBC, 0x7F, 0x7F, 0xA7)) {
        return 1;
    }
    if (func_8002A408(arg0, arg1, 0xF4, 0x7F, 0x7F, 0xA7)) {
        return 1;
    }
    phi_v0 = D_8004BCD0[0].y_position;
    if (phi_v0 == 0x61) {
        phi_v0 = 0x57;
    } else {
        phi_v0 = 0x74;
    }
    if (func_8002A408(arg0, arg1, 0x44, 0x57, phi_v0, 0x7F)) {
        return 1;
    }

    phi_v0 = D_8004BCD0[1].y_position;
    if (phi_v0 == 0x61) {
        phi_v0 = 0x57;
    } else {
        phi_v0 = 0x74;
    }
    if (func_8002A408(arg0, arg1, 0xFC, 0x57, phi_v0, 0x7F)) {
        return 1;
    }
    D_8004C6E0 = 0;
    D_8004C6E4 = 300;
    D_8004C6EC = 300;
    D_8004C6E8 = 1;
    return 0;
}

s32  func_8002AF2C(s32 arg0, s32 arg1) {
    if (arcade_background_visual == 1) {
        return func_8002A474(arg0, arg1);
    }
    if (arcade_background_visual == 2) {
        return func_8002A734(arg0, arg1);
    }
    if (arcade_background_visual == 3) {
        return func_8002AA24(arg0, arg1);
    }
    return func_8002AC54(arg0, arg1);
}

void func_8002AFA4(Gfx **arg0, s32 arg1) {
    Gfx *sp4C;
    s32 tmp_v0;
    f32 phi_f0;

    if (D_8004A338[D_8004BCD0[arg1].unk18] & 1) {
        phi_f0 = 1024.0f;
    } else {
        phi_f0 = D_8004AA18;
    }
    guSprite2DInit(
        &D_8004AC00[D_807444FC].sprite[arg1], D_8004BCD0[arg1].unk14, 0, 
        D_8004BCD0[arg1].unk1E, D_8004BCD0[arg1].unk1E, D_8004BCD0[arg1].unk1F, G_IM_FMT_RGBA, 
        G_IM_SIZ_16b, 0, 0
    );
    sp4C = *arg0;
    func_8070E8F0(&sp4C, &D_8004AC00[D_807444FC].sprite[arg1]);
    func_8070F2C8(0x400, phi_f0, D_8004BCD0[arg1].unk1A & 1, D_8004BCD0[arg1].unk1B);

    if (D_8004A338[D_8004BCD0[arg1].unk18] & 2) {
        func_8070F2FC(&sp4C, 
            (s32)(D_8004BCD0[arg1].x_position - (f32)D_8004A358[D_8004BCD0[arg1].unk18])*4, 
            (s32)((D_8004BCD0[arg1].y_position - (f32)D_8004A378[D_8004BCD0[arg1].unk18])*0.875 + 8)*4);
    } else {//L8002B1AC
        if (D_8004BCD0[arg1].unk18 == 2) {
            tmp_v0 = (s32)D_8004BCD0[arg1].unk10;
            if (tmp_v0 > 2) {
                tmp_v0 = 5 - tmp_v0;
            }
        } else {
            tmp_v0 = 0;
        }
        func_8070F2FC(&sp4C, 
            (s32)(D_8004BCD0[arg1].x_position - D_8004A358[D_8004BCD0[arg1].unk18])*4, 
            (s32)(4*((D_8004BCD0[arg1].y_position - tmp_v0 - D_8004A378[D_8004BCD0[arg1].unk18])*0.875 + 8.0)));
    }//L8002B2A4
    *arg0 = sp4C;
}

void func_8002B2C0(Gfx **arg0) {
    s32 i;
    Gfx *sp38;

    sp38 = *arg0;
    for (i = 0; i < 0x50; i++) {
        if ((D_8004BCD0[i].unk18 != 0) && (D_8004BCD0[i].unk14 != 0)) {
            if ((D_8004BCD0[i].unk18 >= 8) || (arcade_game_state < 2)) {
                func_8002AFA4(&sp38, i);
            }
        }
    }
    *arg0 = sp38;
}

s32 __arcade_abs_w(s32 arg0) {
    if (arg0 >= 0) {
        return arg0;
    }
    return -arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002B390.s")

extern u8 D_8003B3C8[];
extern u8 D_8003B610[];
extern u8 D_8003B858[];
extern u8 D_8003BAA0[];
extern u8 D_8003BCE8[];
extern u8 D_8003BF30[];
extern u8 D_8003C178[];
extern u8 D_8003C3C0[];
extern u8 D_8003C608[];
extern u8 D_8003C850[];
extern u8 D_8003CA98[];
extern u8 D_8003CCE0[];
extern u8 D_8003CF28[];
extern u8 D_8003D170[];
extern u8 D_8003D3B8[];
extern u8 D_8003D600[];
extern u8 D_8003D848[];

extern s32 D_8004A75C;

/*
// TODO: Doable, it compiles
void func_8002B390(s32 arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f4_2;
    s32 temp_f4;
    s32 temp_t7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s4;
    u8 temp_t2;
    u8 temp_v1;
    u8 var_v0;
    ArcadeStruct1 *temp_a1;
    ArcadeStruct1 *temp_v1_2;

    temp_a1 = &D_8004BCD0[arg0];
    temp_v1 = temp_a1->unk19;
    temp_t7 = temp_a1->unk1A & 2;
    temp_f0 = temp_a1->unk10;
    temp_f4 = temp_f0;
    temp_a1->unk1A = (temp_t7 / 2) | temp_t7;
    temp_a1->unk1B = 0;
    if (temp_v1 == 2) {
        if (D_8004C710 != 0) {
            temp_v0 = temp_f4 & 3;
            if (D_8004C710 & 8) {
                temp_v0_2 = temp_f4 & 3;
                switch (temp_v0_2) {
                    case 0:
                    case 2:
                        temp_a1->unk14 = &D_8003C178;
                        return;
                    case 1:
                        temp_a1->unk14 = &D_8003C608;
                        return;
                    case 3:
                        temp_a1->unk14 = &D_8003CA98;
                        return;
                }
            } else {
                switch (temp_v0) {
                    case 0:
                    case 2:
                        temp_a1->unk14 = &D_8003C3C0;
                        return;
                    case 1:
                        temp_a1->unk14 = &D_8003C850;
                        return;
                    case 3:
                        temp_a1->unk14 = &D_8003CCE0;
                        return;
                }
            }
        } else {
            temp_v0_3 = temp_f4 & 3;
            switch (temp_v0_3) {
                case 0:
                case 2:
                    temp_a1->unk14 = &D_8003B180;
                    return;
                case 1:
                    temp_a1->unk14 = &D_8003B3C8;
                    return;
                case 3:
                    temp_a1->unk14 = &D_8003B610;
                    return;
            }
        }
    } else {
        if (temp_v1 == 3) {
            temp_a1->unk14 = &D_8003CF28;
            return;
        }
        if (temp_v1 == 5) {
            temp_f2 = temp_a1->y_position;
            if (((D_8004C6E8 - temp_f2) < 1.0f) || (temp_f0_2 = temp_f2 - D_8004C6E4, (temp_f0_2 < 1.0f))) {
                temp_a1->unk14 = &D_8003BF30;
            } else if (temp_f0_2 < 6.0f) {
                temp_a1->unk14 = &D_8003B858;
            } else if (temp_f0_2 < 10.0f) {
                temp_a1->unk14 = &D_8003BCE8;
            } else if (temp_f0_2 < 14.0f) {
                temp_a1->unk14 = &D_8003BAA0;
            } else {
                temp_a1->unk14 = &D_8003B858;
            }
            temp_a1->unk1A = (u8)(temp_a1->unk10 / 4.5) & 1;
            return;
        }
        if (temp_v1 == 8) {
            if (temp_f0 > 38.0f) {
                if (arcade_lives_internal == 0) {
                    if (temp_f0 > 48.0f) {
                        if (D_8004A75C < arcade_current_score) {
                            func_80024B04();
                            return;
                        }
                        if (D_8004A740 != 0) {
                            func_80024C34();
                            return;
                        }
                        func_80024D90();
                        return;
                    }
                    var_s4 = 0x6C;
                    if (D_8004A764 == 0) {
                        D_8004A764 = 1;
                        do {
                            var_s0 = 0xA6;
loop_53:
                            temp_v1_2 = &D_8004BCD0[func_800247F0()];
                            temp_v1_2->x_position = D_8004A6B8.x_position;
                            temp_v1_2->y_position = D_8004A6B8.y_position;
                            temp_v1_2->y_velocity = D_8004A6B8.y_velocity;
                            temp_v1_2->x_velocity = D_8004A6B8.x_velocity;
                            temp_f4_2 = var_s0;
                            temp_v1_2->unk10 = D_8004A6B8.unk10;
                            temp_v1_2->unk14 = D_8004A6B8.unk14;
                            var_s0 += 0x10;
                            temp_v1_2->x_position = var_s4;
                            temp_v1_2->y_position = temp_f4_2;
                            temp_v1_2->unk1C = D_8004A6B8.unk1C;
                            temp_v1_2->unk18 = D_8004A6B8.unk18;
                            if (var_s0 != 0xC6) {
                                goto loop_53;
                            }
                            var_s4 += 0x10;
                        } while (var_s4 != 0xCC);
                    }
                } else {
                    arcade_lives_internal -= 1;
                    func_800257D8();
                }
            } else {
                if (temp_f0 > 20.0f) {
                    temp_a1->unk14 = &D_8003D848;
                    return;
                }
                if (temp_f0 > 8.0f) {
                    arcade_game_state = 2;
                    if (temp_f4 & 1) {
                        temp_a1->unk14 = &D_8003D3B8;
                    } else {
                        temp_a1->unk14 = &D_8003D600;
                    }
                    temp_t2 = (u8)temp_a1->unk10 & 3;
                    var_v0 = temp_t2;
                    if (temp_t2 == 2) {
                        temp_a1->unk1A = temp_a1->unk1A ^ 1;
                        var_v0 = (u8)temp_a1->unk10 & 3;
                    }
                    if (var_v0 == 1) {
                        temp_a1->unk1B = temp_a1->unk1B == 0;
                    }
                }
            }
        } else {
            temp_a1->unk14 = &D_8003D170;
        }
    }
}
*/

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002B89C.s")
#else
    extern f32 D_8004AA1C;
    extern f64 D_8004AA20;
    extern f32 D_8004AA28;
    extern f64 D_8004AA30;
    extern f32 D_8004AA38;
    extern f64 D_8004AA40;
    extern f32 D_8004AA64;
    extern f64 D_8004AA68;
    extern f64 D_8004AA78;
    extern f64 D_8004AA80;
    extern f64 D_8004AA88;
    extern f32 D_8004AA90;
    extern s32 D_8004BC80;
    extern s32 D_8004BC84;
    extern s32 D_8004C700;

    extern s32  D_80770DFC;

void func_8002B89C(s32 arg0) {
    f32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    ArcadeStruct1 *sp30 = D_8004BCD0 + arg0;
    s32 tmp_v0;
    int i;
    int pointIndx;
    ArcadeStruct1 *stagePtr;

    if (sp30->unk19 == 8 || arcade_game_state == 0) {
        if (sp30->unk19 == 2) {
            func_8002A390(sp30->unk0, sp30->unk4);
            if (sp30->unk8 < 0.0f) {
                sp30->unk1A &= 1;
            } else if (0.0f < sp30->unk8) {
                sp30->unk1A |= 2;
            }
            if (( D_807ECDE8->unk0 & 0x200 || D_807ECDE8->unk2 < -0x14 )
                && D_8004C6F0 < sp30->unk0
            ) {
                D_8004BC80 += 3;
                sp30->unk8 = D_8004AA1C;
                sp30->unk10 += D_8004AA20;
            } else if ((D_807ECDE8->unk0 & 0x100 || D_807ECDE8->unk2 >= 0x15)
                    && D_8004C6F4 < sp30->unk0
            ) {//L8002B9DC
                D_8004BC80 += 3;
                sp30->unk8 = D_8004AA28;
                sp30->unk10 += D_8004AA30;
            } else {
                 sp30->unk8 = 0.0f;
            }//L8002BA5C
            if (newly_pressed_input & (A_BUTTON | B_BUTTON | Z_TRIG) && !D_8004C710) {
                func_80737638(D_8076D1F8, SFX_41_ARCADE_JUMPMAN_JUMPING, 0x7fff, 0x3F, 1.0f, 0, 0);
                sp30->unk10 = 0.0f;
                sp30->unkC = D_8004AA38;
                sp30->unk8 *= D_8004AA40;
                sp30->unk1D = (s8) (u32) sp30->unk4;
                sp30->unk19 = 3;
            }
        }//L8002BB74
        if (sp30->unk4 < func_8002A390( sp30->unk8 +  sp30->unk0,sp30->unk4) + 3) {
            sp30->unk0 += sp30->unk8;
        } else {
            sp30->unk8 = 0.0f;
        }
        if (sp30->unk19 != 8 
            && arcade_background_visual == 3
            && ( (76.0f < sp30->unk0 && sp30->unk0 < 140.0f) || (140.0f < sp30->unk0 && sp30->unk0 < 164.0f))
            && ( (sp30->unk4  < 116.0f && 239.0f < sp30->unk4) || (239.0f < sp30->unk4))
        ) {
            func_80027E8C();
        } else {////L8002BCC4
            D_8004C700 = func_8002AF2C(sp30->unk0, sp30->unk4);
            sp40 = func_8002A390(sp30->unk0, sp30->unk4);
            D_8004C6FC = D_8004C6F8;
            switch (sp30->unk19) {
                case 2:// 8002BD64
                    if (D_8004C6FC == 0)
                        D_8004BCD0[D_8004C71F].unk0 += D_8004A308[0];
                    if (D_8004C6FC == 1)
                        D_8004BCD0[D_8004C71F].unk0 += D_8004A308[1];
                    if (D_8004C6FC == 2)
                        D_8004BCD0[D_8004C71F].unk0 += D_8004A308[2];
                    if (D_8004C6FC == 3)
                        D_8004BCD0[D_8004C71F].unk0 += D_8004A308[3];
                    
                    if (sp30->unk0 <= D_8004C6F0 - 1)
                        sp30->unk0 = D_8004C6F0;
                    if (D_8004C6F4 + 1 <= sp30->unk0)
                        sp30->unk0 = D_8004C6F4;
                    
                    if (D_8004C6EC < sp30->unk4
                        && ((D_807ECDE8->unk0 & 0x800) | ((D_807ECDE8->unk3 < 0x15) ^ 1))
                        && D_807ECDE8->unk2 < 0x29 && D_807ECDE8->unk2 >= -0x28
                        && !(D_807ECDE8->unk0 & 0x300)
                        && !D_8004C710
                    ) {
                        sp30->unk19 = 5;
                        sp30->unk8 = 0.0f;
                        sp30->unk4--; 
                        sp30->unk0 = D_8004C6E0;
                    } else if (
                        sp30->unk4 < D_8004C6E8
                        && D_8004C6EC <= sp30->unk4
                        && !(D_807ECDE8->unk0 & 0x300)
                        && D_807ECDE8->unk2 < 0x29 && D_807ECDE8->unk2 >= -0x28
                        && ((D_807ECDE8->unk0 & 0x400) | (D_807ECDE8->unk3 < -0x14))
                        && !D_8004C710
                    ) {
                        sp30->unk19 = 5;
                        sp30->unk8 = 0.0f;
                        sp30->unk4++;
                        sp30->unk0 = D_8004C6E0;
                    } else if (sp40 - sp30->unk4 < 2.0f) {
                        sp30->unk4 = sp40;
                    } else {
                        sp30->unk19 = 3;
                        sp30->unk8 = 0.0f;
                        sp30->unkC = 0.0f;
                        sp30->unk1D = (s8) (u32) sp30->unk4;
                    }
                    sp3C = 4;
                    break;
                case 5:// 8002C0FC
                    if (sp40 == sp30->unk4
                        && ( ( (D_807ECDE8->unk0 & 0x300) | (D_807ECDE8->unk2 < 0x15)^1 | (D_807ECDE8->unk2 < -0x14))
                             || (D_8004C6FC == 2 && D_8004A308[2])
                             || (D_8004C6FC == 1 && D_8004A308[1])
                             || (D_8004C6FC == 3 && D_8004A308[3])
                        )
                    ) {
                       sp30->unk19 = 2;
                    } else if (
                        sp40 == sp30->unk4 
                        && newly_pressed_input & (A_BUTTON | B_BUTTON | Z_TRIG)
                    ) {//L8002C198
                        func_80737638(D_8076D1F8, SFX_41_ARCADE_JUMPMAN_JUMPING, 0x7fff, 0x3f, 1.0f, 0, NULL);
                        sp30->unk10 = 0.0f;
                        sp30->unkC = D_8004AA64;
                        sp30->unk8 *= D_8004AA68; 
                        sp30->unk19 = 3;
                        sp30->unk1D = (s8) (u32) sp30->unk4;
                    } else {//L8002C2AC
                        //TODO: FINISH THIS
                    }
                    break;
                case 3:// 8002C420
                    if (D_8004C6F4 < sp30->unk0) {
                        sp30->unk0 = D_8004C6F4;
                        if (sp30->unkC < D_8004AA78) {
                            sp30->unk1A &= 1;
                            sp30->unk8 = -sp30->unk8;
                            sp30->unkC = -sp30->unkC;
                        }
                    } else { //L8002C490
                        if (sp30->unk0 < D_8004C6F0) {
                            sp30->unk0 = D_8004C6F0;
                            if (sp30->unkC < D_8004AA80) {
                                sp30->unk1A |= 2;
                                sp30->unk8 = -sp30->unk8;
                                sp30->unkC = -sp30->unkC;
                            }
                        }
                    }//L8002C4F8
                    sp30->unk4 += sp30->unkC;
                    sp30->unkC += D_8004AA88;
                    if (0.0f <= sp30->unkC && sp30->unkC < D_8004AA88) {
                        sp38 = 0;
                        for (i = 0; i < 0x50; i++) {
                            if (D_8004BCD0[i].unk18 == 1 || D_8004BCD0[i].unk18 == 2) {
                                if (__arcade_abs_w(D_8004BCD0[i].unk0) < 0xD
                                    && D_8004BCD0[i].unk0 - sp30->unk0 < 24.0f
                                    && sp30->unk0 < D_8004BCD0[i].unk0
                                ) {
                                    sp38++;
                                }
                            }//L8002C5EC
                        }
                        if (sp38) {
                            pointIndx = func_800247F0();
                           D_8004BCD0[pointIndx] = arcade_points_text_obj_template;
                           D_8004BCD0[pointIndx].unk0 = sp30->unk0;
                           D_8004BCD0[pointIndx].unk4 = sp30->unk4;
                           if (sp38 == 1) {
                               arcade_add_points_to_score(100);
                           } else if (sp38 == 2) {
                               D_8004BCD0[pointIndx].unk14 = &D_800383B8;
                               arcade_add_points_to_score(300);
                           } else if (sp38 == 3) {
                               D_8004BCD0[pointIndx].unk14 = &D_800385C0;
                               arcade_add_points_to_score(500);
                           }
                        }
                    }//L8002C70C
                    if (15.0f < sp30->unk4 - sp30->unk1D) {
                        func_80737638(D_8076D1F8, SFX_44_ARCADE_SPRING_FALL, 0x7fff, 0x3f, 1.0f, 0, NULL);
                        sp30->unk1D = 0xff;
                    }
                    if (2.5 < sp30->unkC) {
                        sp30->unkC = 2.5f;
                    }
                    if (sp40 < sp30->unk4 && sp30->unk4 - sp40 < 3.0f) {
                        sp30->unk4 = sp40;
                        if (sp30->unk1D  == 0xff) {
                            func_80027E8C();
                        } else {
                            sp30->unk19 = 4;
                            sp30->unkC = 0.0f;
                            sp30->unk8 = 0.0f;
                            sp30->unk10 = 4.0f;
                        }
                    }//L8002C850
                    break;
                case 4:// 8002C858
                    if (0.0f == sp30->unk10) {
                        sp30->unk19 = 2;
                    }
                    break;
                case 8:// 8002C898
                    sp30->unk10 += 0.125;
                    if (8.0f == sp30->unk10) {
                        func_80737638(D_8076D1F8, SFX_54_ARCADE_JUMPMAN_DEATH, 0x7fff, 0x3f, 1.0, 0, NULL);
                    }
                    break;
            }// 8002C908
            if (!(D_8004BC80 < 0x24)) {
                D_8004BC80 = 0;
                tmp_v0 = D_8004BC84;
                tmp_v0++;
                if (tmp_v0 == 7)
                    tmp_v0 = 0;
                if (tmp_v0 & 1) {
                    sp44 = 1.0f; 
                } else {
                    sp44 = D_8004AA90;
                }
                func_80737638(D_8076D1F8, SFX_40_ARCADE_JUMPMAN_MOVING, 0x7fff, 0x3f, 1.0f, 0, &D_80770DFC);
                func_80737AC4(D_80770DFC, 0x10, sp44);
            }//L8002C9C0
            sp40 = func_8002A390(sp30->unk0, sp30->unk4);
            sp30->unk1C = D_8004C6F8;
            D_8004C704 = sp30->unk4 - D_8004C6E4;
            if (D_8004C71E < 0 && sp30->unk19 != 8) {
                func_80027E8C();
            }
            if (D_8004C6F8 == 0 && sp40 == sp30->unk4) {
                func_80737638(D_8076D1F8, SFX_4C_ARCADE_PAULINE_SAVED_STAGE, 0x7fff, 0x3f, 1.0f, 0, NULL);
                func_800252A4(0);
                if (arcade_background_visual == 1) {
                    stagePtr = func_80024860(ARCADE_OBJ_16_DK_25M);
                } else if (arcade_background_visual == 3) {
                    stagePtr = func_80024860(ARCADE_OBJ_18_DK_75M);
                } else if (arcade_background_visual == 4) {
                    stagePtr = func_80024860(ARCADE_OBJ_19_DK_50M);
                }
                //L8002CB6C
                stagePtr->unk19 = 5;
                if (arcade_background_visual != 4) {
                    stagePtr->unk18 = ARCADE_OBJ_18_DK_75M;
                }
                stagePtr->unk10 = 0.0f;
                arcade_game_state = 3;
                sp30->unk14 = &D_8003B180;
                sp30->unk1A = 0;

            } else {//L8002CBB4
                if (sp30->unk19)
                    func_8002B390(arg0);
            }
        }
    }//L8002CBC8
}
#endif

//arcade_barrel_update_sprite
void func_8002CBD8(s32 arg0) {
    ArcadeStruct1 *v0 = D_8004BCD0 + arg0;
    s32 v1 = v0->unk10;

    if (v0->unk19 == 5 
        || v0->unk19 == 7 
        || v0->unk19 == 1
    ) { //on ladder
        if (v0->unk1D) { //blue barrel
            switch(v1 & 1) {
                case 0:
                    v0->unk14 = &D_80035AE0;
                    break;
                case 1:
                    v0->unk14 = &D_80035CE8;
                    break;
            }
        } else { //red barrel
            switch(v1 & 1) {
                case 0:
                    v0->unk14 = &D_80035650;
                    break;
                case 1:
                    v0->unk14 = &D_80035898;
                    break;
            }
        }
    } else {// normal rolling
        if (v0->unk1D) {
            switch(v1 & 3) { //blue barrel
                case 0:
                    v0->unk14 = &D_80035448;
                    break;
                case 1:
                    v0->unk14 = &D_80035240;
                    break;
                case 2:
                    v0->unk14 = &D_80035038;
                    break;
                case 3:
                    v0->unk14 = &D_80034E30;
                    break;
            }
        } else {
            switch(v1 & 3) { //red barrel
                case 0:
                    v0->unk14 = &D_80034C28;
                    break;
                case 1:
                    v0->unk14 = &D_80034A20;
                    break;
                case 2:
                    v0->unk14 = &D_80034818;
                    break;
                case 3:
                    v0->unk14 = &D_80034610;
                    break;
            }
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002CD64.s")
#else

extern f64 D_8004AAB8;
extern f64 D_8004AAC0;
extern f64 D_8004AAC8;
extern f64 D_8004AAD0;
extern f64 D_8004AAD8;
extern f32 D_8004AAE0;

void func_8002CD64(s32 arg0) {
    s32 sp3C;
    s32 sp34;
    f32 sp30;
    ArcadeStruct1 *this;
    f32 tmp_f12;
    s32 flame_indx;


    if (arcade_game_state != 0)
        return;

    this = &D_8004BCD0[arg0];
    if (this->unk19 == 0 || this->unk19 == 1) {
        func_8002CBD8(arg0);
    }
    else {
        this->unk0 += this->unk8;
        sp3C = func_8002A390( this->unk0, this->unk4);
        func_8002AF2C( this->unk0, this->unk4);
        switch(this->unk19) {
            case 2: //L8002CE70
                this->unk8 = (f32)(1 - (this->unk1A << 1));
                this->unk10 += D_8004AA98;
                if ((this->unk4 < D_8004C6E8)
                    && ( D_8004C6F8 + 1 < D_8004C6FC
                        || (D_8004C6FC == this->unk1C && D_8004C704 < 0x12)
                        || (D_8004BCD0[0].unk19 != 5))
                ) {
                    if (this->unk1C & 0x80)
                        break;

                    this->unk1C &= 0xF;
                    if (this->unk1C & 0xFF > 0) {
                        this->unk1C--;
                        this->unk19 = 5;
                        this->unk4  += 1.0f;
                        this->unkC = 1.0f;
                        this->unk8 = 0.0f;
                        this->unk0 = D_8004C6E0;
                    }
                    else {
                        this->unk1C |= 0x80; 
                    }
                }
                else {//L8002CFDC
                    if (!(this->unk1C & 0x47)) {
                        this->unk1C = 0x40 | (4096.0f + func_800246C8((f32)D_8004A76C, 5.0f) * 1512.0f > (f32)func_80024644()) ? TRUE : FALSE;
                    }//L8002D074
                    if ((f32)sp3C - this->unk4 < 3.0f) {
                        this->unk4 = sp3C;
                    }
                    else {
                        this->unk19 = 3;
                        this->unkC = 0.0f;
                        this->unk8 = this->unk8/2;
                    }
                }
                break;
            case 3: //L8002D0FC
                this->unk10 += D_8004AAA0;
                this->unk4 += this->unkC;
                this->unkC += D_8004AAA8;
                if (sp3C < this->unk4
                    && this->unk4 - sp3C < 3.0f
                ) {
                    this->unk4 = sp3C;
                    this->unkC = -this->unkC/3.0f;
                    if (D_8004AAB0 < this->unkC)
                        this->unk19 = 2;
                }//L8002D1C8
                break;
            case 5: //L8002D1E4
                this->unk10 += D_8004AAB8;
                this->unk4 += this->unkC;
                if (D_8004C6E8 < this->unk4) {
                    this->unk1A = (1 - this->unk1A);
                    this->unk19 = 2;
                    this->unk4 = sp3C;
                    this->unk8 = 1 - 2*this->unk1A;
                }//L8002D28C
                break;
            case 7: //L8002D2A8
                this->unk10 +=  D_8004AAC0;
                this->unk4 += this->unkC;
                this->unkC += D_8004AAC8;
                tmp_f12 = func_8002A390(this->unk0, this->unk4);
                if (tmp_f12 < this->unk4
                    && this->unk4 - tmp_f12 < 8.0f
                    && this->unk1C < D_8004C6F8
                ) {
                    this->unkC = 0.0f;
                    if (this->unk1D == 2) {
                        sp34 = func_80024644();
                        this->unk8 = (func_800246C8(3.0f, D_8004A76C)*(sp34 - 0.0f))/D_8004AAD0 + (-this->unk8)*D_8004AAD8;
                    }//L8002D414
                    if (230.0f < this->unk4) {
                        this->unk19 = 3;
                        this->unk1A = 1;
                        this->unk8 = -1.0f;
                        this->unkC = D_8004AAE0;
                    }
                }//L8002D454
                break;
        }//L8002D47C
        if (!(D_8004BCD0[D_8004C71F].unk1C < D_8004C6F8)
            || this->unk1D
        ) {
            if (270.0f < this->unk0) {
                this->unk1A = 1;
                this->unk8 = (1 - ((s8)this->unk1A) << 1);
            }
            else if (this->unk0 < 50.0f) {
                this->unk1A = 0;
                this->unk8 = (1 - ((s8)this->unk1A) << 1);
            }
        }//L8002D504
        if ((278.0f < this->unk0) || (this->unk0 < 2.0f)) {
            this->unk18 = 0;
        }//L8002D548
        if (( 242.0f < this->unk4) & ( this->unk0 < 74.0f)) {
            if (this->unk1D) {
                func_80737638(D_8076D1F8, SFX_42_ARCADE_JUMPMAN_HIT, 0x7fff, 0x3f, D_8004BCD0[D_8004C71F].unk0, 0, NULL);
                flame_indx = func_80024860(ARCADE_OBJ_13_OIL_DRUM_FLAMES);
                if (flame_indx < 0)
                    flame_indx = func_800246EC();
                    D_8004BCD0[flame_indx] = arcade_oil_drum_flame_obj_template;
                D_8004BCD0[flame_indx].unk19 = 3;
                this->unk18 = 0;
            }//L8002D668
            else {
                this->unk18 = 0;
            }
        }//L8002D674
        if (this->unk0 - D_8004BCD0[D_8004C71F].unk0 < 8.0f
            && D_8004BCD0[D_8004C71F].unk0 - this->unk0 < 8.0f
            && this->unk4 - D_8004BCD0[D_8004C71F].unk4 < 3.0f
            && D_8004BCD0[D_8004C71F].unk4 - this->unk4 < 3.0f
        ) {
            func_80027E8C();
        }
        func_8002CBD8(arg0);
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002D6FC.s")

extern u8 D_80037788[];
extern u8 D_80037990[];

extern f64 D_8004AB10;
extern f64 D_8004AB18;
extern f32 D_8004AB20;

#ifndef NONMATCHING
// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002E158.s")
#else
void func_8002E158(s32 arg0) {
    f32 dy;

    if (arcade_game_state != 0)
        return;
    
    D_8004BCD0[arg0].x_position += D_8004BCD0[arg0].x_velocity;
    D_8004BCD0[arg0].unk10 += D_8004AB10;
    switch((s32)D_8004BCD0[arg0].unk10 & 0x1) {
        case 0:
            D_8004BCD0[arg0].unk14 = &D_80037788;
            break;
        case 1:
            D_8004BCD0[arg0].unk14 = &D_80037990;
            break;
    }
    D_8004BCD0[arg0].y_position += 5.0f;
    if (D_8004BCD0[arg0].y_velocity < 5.0f) {
        D_8004BCD0[arg0].y_velocity += D_8004AB18;
    }
    if (D_8004BCD0[arg0].y_position > 81.0f) {
        if (D_8004BCD0[arg0].x_position < 220.0f) {
            D_8004BCD0[arg0].y_position = 81.0f;
            D_8004BCD0[arg0].y_velocity = -3.5f;
            if (40.0f < D_8004BCD0[arg0].x_position) {
                func_80737638(D_8076D1F8, SFX_43_ARCADE_SPRING_SPRINGING, 0x7fff, 0x3f, 1.0f, 0, NULL);
            }
        } else if (D_8004BCD0[arg0].x_velocity != 0.0f) {
            D_8004BCD0[arg0].x_velocity = 0.0f;
            func_80737638(D_8076D1F8, SFX_44_ARCADE_SPRING_FALL, 0x7fff, 0x3f, 1.0f, 0, NULL);
        }
    }
    if (D_8004AB20 < D_8004BCD0[arg0].y_position) {
        D_8004BCD0[arg0].unk18 = 0;
    }
    if (__arcade_abs_w(D_8004BCD0[arg0].x_position - D_8004BCD0[D_8004C71F].x_position) < 7) {
        dy = D_8004BCD0[arg0].y_position - D_8004BCD0[D_8004C71F].y_position;
        if (dy < 4.0f && -8.0f < dy) {
            func_80027E8C();
        }
    }
}
#endif

extern f32 D_8004AB24;
extern u8 D_80032470; // imageData
extern u8 D_800326B8; // imageData
extern u8 D_80032900; // imageData

void func_8002E3D4(s32 arg0) {
    s32 newFlameIndex;

    if (arcade_game_state == 0) {
        D_8004BCD0[arg0].unk1C--;
        if (D_8004BCD0[arg0].unk1C >= 0x15) {
            D_8004BCD0[arg0].unk1C = func_80024644() & 0xF;
            D_8004BCD0[arg0].unk1D = !(D_8004BCD0[arg0].unk1D);
        }
        switch (D_8004BCD0[arg0].unk19) {
            case 2:
                switch (D_8004BCD0[arg0].unk1D) {
                    case 0:
                        D_8004BCD0[arg0].unk14 = &D_80032228;
                        break;
                    case 1:
                        D_8004BCD0[arg0].unk14 = &D_80032470;
                        break;
                }
                newFlameIndex = func_800246C8(D_8004A76C, 5.0f);
                if (arcade_background_visual == 4) {
                    if (D_8004BCD0[arg0].unk10++ == (0x64 - (newFlameIndex * 0x14))) {
                        if (arcade_get_object_type_count(2) < newFlameIndex) {
                            D_8004BCD0[arg0].unk19 = 3;
                            D_8004BCD0[arg0].unk10 = 0.0f;
                        }
                    }
                }
                break;
            case 3:
                if (D_8004BCD0[arg0].unk10++ > 40.0f) {
                    D_8004BCD0[arg0].unk19 = 2;
                    D_8004BCD0[arg0].unk10 = 0;
                    newFlameIndex = func_80024828();
                    D_8004BCD0[newFlameIndex] = arcade_flame_enemy_obj_template;
                    D_8004BCD0[newFlameIndex].unk19 = 3;
                    D_8004BCD0[newFlameIndex].y_velocity = -1;
                    if (arcade_background_visual == 1) {
                        D_8004BCD0[newFlameIndex].x_velocity = D_8004AB24;
                    } else {
                        if (D_8004BCD0[D_8004C71F].x_position < 160) {
                            D_8004BCD0[newFlameIndex].x_velocity = -0.5f;
                        } else {
                            D_8004BCD0[newFlameIndex].x_velocity = 0.5f;
                        }
                        D_8004BCD0[newFlameIndex].unk1A = 0;
                        D_8004BCD0[newFlameIndex].x_position = 160;
                        D_8004BCD0[newFlameIndex].y_position = 135;
                    }
                }
                switch (D_8004BCD0[arg0].unk1D) {
                    case 0:
                        D_8004BCD0[arg0].unk14 = &D_800326B8;
                        break;
                    case 1:
                        D_8004BCD0[arg0].unk14 = &D_80032900;
                        break;
                }
                break;
        }
    }
}

void arcade_pauline_top_update(s32 arg0) {
    ArcadeStruct1 *pauline = & D_8004BCD0[arg0];
    s32 tmp_v1 = 2;
    if (arcade_background_visual == tmp_v1) {
        pauline->unk1A = (D_8004BCD0[D_8004C71F].x_position < 160.0f);
        pauline->x_position = 152.0f;
        if (D_8004C708 == tmp_v1) {
            pauline->unk1A = 0;
            pauline->y_position = 63.0f;
        }
    }//L8002E764
    if (!D_8004C721) {
        pauline->unk14 = NULL;
        return;
    }
    pauline->unk14 = &D_8003E438;
}

void arcade_pauline_bottom_update(s32 arg0) {
    ArcadeStruct1 *pauline = & D_8004BCD0[arg0];
    s32 tmp_v1 = 2;
    if (arcade_background_visual == tmp_v1) {
        pauline->unk1A = (D_8004BCD0[D_8004C71F].x_position < 160.0f);
        pauline->x_position = 152.0f;
        if (D_8004C708 == tmp_v1) {
            pauline->unk1A = 0;
            pauline->y_position = 79.0f;
        }
    }//L8002E818
    if (!D_8004C721) {
        pauline->unk14 = NULL;
        return;
    }
    if (pauline->unk14 == NULL)
        pauline->unk14 = &D_8003DB18;

    if (arcade_game_state == 0) {
        tmp_v1 = pauline->unk1C++ & 0xC8;
        if (tmp_v1 || D_8004C724 == 1) {
            pauline->unk14 = &D_8003DB18;
        }
        else {
            pauline->unk14 = &D_8003DD60;
        }
    }
}

void arcade_nintendo_coin_update(s32 arg0) {
    D_8004BCD0[arg0].unk14 = &D_8003AE58;
    if (D_8004C721) {
        D_8004BCD0[arg0].y_position = D_8004BCD0[func_80024860(ARCADE_OBJ_1A_PAULINE_BOTTOM)].y_position - 8.0f;
        D_8004BCD0[arg0].x_position = D_8004BCD0[func_80024860(ARCADE_OBJ_1A_PAULINE_BOTTOM)].x_position;
    }//L8002E924
    else {
        if (D_8004BCD0[arg0 - 1].unk14 == NULL) {
            D_8004BCD0[arg0].unk14 = NULL;
        }
        D_8004BCD0[arg0].y_position = D_8004BCD0[arg0 - 1].y_position + 20.0f;
        D_8004BCD0[arg0].x_position = D_8004BCD0[arg0 - 1].x_position + 30.0f;
    }
    D_8004BCD0[func_80024860(ARCADE_OBJ_1A_PAULINE_BOTTOM)].unk14 = NULL;
    D_8004BCD0[func_80024860(ARCADE_OBJ_1B_PAULINE_TOP)].unk14 = NULL;
    if (func_80024860(ARCADE_OBJ_1D_HELP_TEXT) >= 0) {
        if ((u32) D_8004BCD0[func_80024860(ARCADE_OBJ_1D_HELP_TEXT)].unk14 != (u32)&D_800389D0)
        {
            D_8004BCD0[func_80024860(ARCADE_OBJ_1D_HELP_TEXT)].unk14 = NULL;
        }
    }
}

void arcade_help_text_update(s32 arg0) {
    s32 tmp_a3 = 2;
    s32 tmp_v0 = 0x10;

    if (arcade_background_visual == tmp_a3) {
        D_8004BCD0[arg0].x_position = 0x80 + 0x28 * (160.0f <= D_8004BCD0[D_8004C71F].x_position);
        if (D_8004C708 == tmp_a3) {
            D_8004BCD0[arg0].y_position = 63.0f;
            D_8004BCD0[arg0].unk1A = 0;
        }
    }//L8002EA68

    if (arcade_game_state == 3) {
        if (D_8004C721 == 0)
            D_8004BCD0[arg0].unk14 = &D_80038BD8;
        else
            D_8004BCD0[arg0].unk14 = &D_800389D0;
        D_8004BCD0[arg0].unk1F = D_8004BCD0[arg0].unk1E = tmp_v0;
    }//L8002EAC8
    else if (!D_8004C721) {
        D_8004BCD0[arg0].unk14 = NULL;
    }
    else if (arcade_game_state == 0) {
        if (!(D_8004BCD0[arg0].unk1C++ & 0xC0)) {
            if (arcade_background_visual == tmp_a3 || arcade_background_visual == 4)
                D_8004BCD0[arg0].unk14 = &D_8003E868;
            else
                D_8004BCD0[arg0].unk14 = &D_8003E680;
        }
        else {
                D_8004BCD0[arg0].unk14 = NULL;
        }
    }//L8002EB38
}

void arcade_pulley_update(s32 arg0) {
    if (arcade_game_state == 0) {
        D_8004BCD0[arg0].unk1D += D_8004A308[D_8004BCD0[arg0].unk1C];
        if (D_8004BCD0[arg0].unk1D < 0) {
            D_8004BCD0[arg0].unk1D += 0x2EE00;
        }
        switch ((D_8004BCD0[arg0].unk1D / 8) % 3) {
            case 0:
                D_8004BCD0[arg0].unk14 = &D_80037B98;
                break;
            case 1:
                D_8004BCD0[arg0].unk14 = &D_80037DA0;
                break;
            case 2:
                D_8004BCD0[arg0].unk14 = &D_80037FA8;
                break;
            default:
                break;
        }
    }
}

void arcade_dk_title_update(s32 arg0) {
    s32 phi_v1;

    phi_v1 = D_8004C6DC;
    if (phi_v1 == 0x3C) {
        func_80737638(D_8076D1F8, SFX_46_ARCADE_INTRO, 0x7FFF, 0x3F, 1.0f, 0, 0);
        phi_v1 = D_8004C6DC;
    }
    if (phi_v1 >= 0x3C) {
        if (phi_v1 >= 0x169) {
            D_8004BCD0[arg0].y_velocity += D_8004AB28;
            //D_8004BCD0[arg0].unkC += 0.05;
            D_8004BCD0[arg0].y_position += D_8004BCD0[arg0].y_velocity;
            D_8004BCD0[arg0].x_position += D_8004BCD0[arg0].x_velocity;
            if ((D_8004BCD0[arg0].y_velocity > 0.0f) && (D_8004BCD0[arg0].y_position >= 38.0f)) {
                D_8004C721 = 1;
                D_8004BCD0[arg0].y_position = 38.0f;
                if (phi_v1 == 0x26C) {
                    func_80737638(D_8076D1F8, SFX_53_ARCADE_DK_GRUNT, 0x7FFF, 0x3F, 1.0f, 0, 0);
                    D_8004BCD0[arg0].unk14 = &D_80041508;
                    phi_v1 = D_8004C6DC;
                }
                if ((phi_v1 == 0x2D0) || (phi_v1 < 0x26C)) {
                    D_8004BCD0[arg0].unk14 = &D_80040540;
                }
                if (D_8004AB30 < D_8004BCD0[arg0].y_velocity) {
                //if (0.06 < D_8004BCD0[arg0].unkC) {
                    D_8004C708 = (s32) (D_8004C708 + 1);
                    func_80737638(D_8076D1F8, SFX_42_ARCADE_JUMPMAN_HIT, 0x7FFF, 0x3F, 1.0f, 0, 0);
                }
                if ((D_8004BCD0[arg0].x_position > 74.0f) && !(D_8004C6DC < 0x1A5)) {
                    D_8004BCD0[arg0].x_velocity = -0.5f;
                    D_8004BCD0[arg0].y_velocity = D_8004AB38;
                    //D_8004BCD0[arg0].unkC = -0.81f;
                }
                else {
                    D_8004BCD0[arg0].x_velocity = 0.0f;
                    D_8004BCD0[arg0].y_velocity = 0.0f;
                }
            }
        } else {
            if (D_8004BCD0[arg0].y_position > 74.0f) {
                D_8004BCD0[arg0].y_velocity = -2.0f;
                D_8004BCD0[arg0].x_velocity = 0.0f;
                D_8004BCD0[arg0].y_position = (f32) (0xC5 - ((s32) (phi_v1 - 0x3C) / 2));
                if ((phi_v1 & 8)) 
                    D_8004BCD0[arg0].unk14 = &D_80044460;
                else
                    D_8004BCD0[arg0].unk14 = &D_80045428;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002EEB8.s")
/*
void func_8002EEB8(s32 arg0) {
    ArcadeStruct1 *DK;
    s32 sp28;
    s32 sp24;

    DK = &D_8004BCD0[arg0];
    if (arcade_game_state == 0 || DK->unk19 == 5) {
        switch(DK->unk19) {
            case 12: //8002EF20
                DK->unk1C--;
                if (DK->unk1C == 0) {
                    DK->unk1C = 0x14;
                    DK->unk19 = 9;
                    DK->unk14 = &D_8003E9F0;
                    DK->unk19 = 0;
                    DK->unk1D = func_800246EC();
                    DK->unk10 += 1.0f;

                    D_8004BCD0[DK->unk1D] = arcade_barrel_obj_template;
                    sp28 = DK->unk10;
                    if (!(sp28 & 7))
                        D_8004BCD0[DK->unk1D].unk1D;
                    
                    if (sp28 == 2 && D_8004C723)
                        DK->unk1C = 2;
                    else if (sp28 == 1) {
                        if (!D_8004C723)
                            DK->unk1C = 2;
                        else
                            DK->unk1C = 5;
                    }
                    else if (sp28) {
                        if (!(func_80024644() < func_800246C8(D_8004A76C, 3.0f)*2000.0f + 2048.0f))
                            break;
                    }
                }//L8002F280
                else {
                    D_8004C71E--;
                }
                break;
            case 9: //8002F29C
                break;
            case 11: //8002F338
                break;
            case 10: //8002F45C
                break; 
            case 5: //8002F668
                break;
        }
    }//L8002F81C
}
//*/

// big
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002F82C.s")

#ifndef NONMATCHING
// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_8002FE28.s")
#else
void func_8002FE28(s32 arg0) {
    if (arcade_game_state == 0) {
        D_8004BCD0[arg0].unk10 += 1.0f;
        if (((s8) D_8004BCD0[arg0].unk10 & 0xFF) < 0xA0) {
            D_8004BCD0[arg0].unk14 = &D_80040540;
        } else {
            if (((s32) D_8004BCD0[arg0].unk10 & 0x1F) == 0) {
                func_80737638(D_8076D1F8, SFX_42_ARCADE_JUMPMAN_HIT, 0x7FFF, 0x3F, 1.0f, 0, 0);
            }
            D_8004BCD0[arg0].unk14 = &D_800424D0;
            D_8004BCD0[arg0].unk1A = ((((s32)D_8004BCD0[arg0].unk10 & 0x20) / 0x20) == 0);
        }
        if (((s32) D_8004BCD0[arg0].unk10 % (0x72 - ((s32) func_800246C8(D_8004A76C, 4.0f) * 0xC))) == 0) {
            D_8004C71E--;
            arg0 = func_800246EC();
            D_8004BCD0[arg0] = arcade_spring_obj_template;
            D_8004BCD0[arg0].unk0 = ((func_80024644() & 0xF) - 0x1C);
            D_8004BCD0[arg0].unk19 = 2;
        }
    }
}
#endif

void arcade_dk_50m_update(s32 arg0) {
    switch(D_8004BCD0[arg0].unk19) {
        case 2://L8003007C
            if (arcade_game_state != 0)
                return;

            if ((D_8004C6DC % 0x78) == 0) {
                D_8004C71E--;
            }

            if (204.0f < D_8004BCD0[arg0].x_position) {
                D_8004BCD0[arg0].x_velocity = -1.0;
            }

            if (D_8004BCD0[arg0].x_position < 68.0f) {
                D_8004BCD0[arg0].x_velocity = 1.0f;
            }

            D_8004BCD0[arg0].unk10++;
            if (((s32)D_8004BCD0[arg0].unk10 & 0xff) < 0xA0) {
                D_8004BCD0[arg0].unk14 = &D_80040540;
            }
            else {
                D_8004BCD0[arg0].unk14 = &D_800424D0;
                D_8004BCD0[arg0].unk1A = !(((s32)D_8004BCD0[arg0].unk10 & 0x20)/0x20);
            }
            break;
        case 5://L80030170
            if (100.0f < D_8004BCD0[arg0].x_position) {
                D_8004BCD0[arg0].x_velocity = -1.0f;
            }
            else if (D_8004BCD0[arg0].x_position < 100.0f) {
                D_8004BCD0[arg0].x_velocity = 1.0f;
            }
            else {
                D_8004BCD0[arg0].x_velocity = 0.0f;
                D_8004BCD0[arg0].unk18 = 0x16;
                D_8004BCD0[arg0].unk10 = 41.0f;
            }
            break;
    }
    if ((D_8004C6DC & 1) == 0) {
        D_8004A308[0] = D_8004BCD0[arg0].x_velocity;
        D_8004BCD0[arg0].x_position += D_8004BCD0[arg0].x_velocity;
    }
}

void arcade_points_text_update(s32 arg0) {
    s32 phi_v1;

    if (D_8004BCD0[arg0].unk10 == 0.0f) {
        func_80737638(D_8076D1F8, SFX_45_ARCADE_POINTS, 0x7FFF, 0x3F, 1.0f, 0, 0);
    }
    phi_v1 = 0;
    if (D_8004BCD0[arg0].unk10 > 40.0f) {
        phi_v1 = 1;
    }
    D_8004BCD0[arg0].unk10++;
    if (phi_v1) {
        D_8004BCD0[arg0].unk18 = 0;
    }
}

void arcade_bonus_item_update(s32 arg0) {
    if ((D_8004BCD0[arg0].x_position == (s32) D_8004BCD0[D_8004C71F].x_position) 
         && (D_8004BCD0[arg0].y_position == (s32) D_8004BCD0[D_8004C71F].y_position)
    ) {
        D_8004BCD0[arg0].unk18 = ARCADE_OBJ_14_POINTS_TEXT;
        if (D_8004A76C == 1) {
            D_8004BCD0[arg0].unk14 = &D_800383B8;
            arcade_add_points_to_score(300);
            return;
        }
        if (D_8004A76C == 2) {
            D_8004BCD0[arg0].unk14 = &D_800385C0;
            arcade_add_points_to_score(500);
            return;
        }
        D_8004BCD0[arg0].unk14 = &D_800387C8;
        arcade_add_points_to_score(800);
    }
}

void arcade_hammer_update(u8 arg0) {
    ArcadeStruct1 *s2;
    ArcadeStruct1 *v1;
    u8 i;
    
    if (arcade_game_state != 0)
        return;
    s2 = &D_8004BCD0[arg0];
    switch(s2->unk19) {
        case 0: //L80030418
        {
            v1 = &D_8004BCD0[D_8004C71F];
            if (s2->x_position - v1->x_position < 8.0f && -8.0f < s2->x_position - v1->x_position ) {
                if (s2->y_position - v1->y_position < 8.0f && -8.0f < s2->y_position - v1->y_position ) {
                    func_800252A4(SFX_49_ARCADE_HAMMER_MUSIC);
                    D_8004C710 = 0x258;
                    s2->unk19 = 2;
                }
            }
            break;
        }
        case 2: //L800304B0
        {
            v1 = &D_8004BCD0[D_8004C71F];
            s2->unk1A = v1->unk1A;
            if ((D_8004C710 & 8) || v1->unk19 != 2) {
                if (!(D_8004C710 < 0xf1) || D_8004C710 & 0x4)
                    s2->unk14 = &D_800393F8;
                else
                    s2->unk14 = &D_80039888;
                
                s2->x_position = v1->x_position;
                s2->y_position = v1->y_position - 16.0f;
            }
            else {//L80030538
                if (!(D_8004C710 < 0xf1) || D_8004C710 & 0x4)
                    s2->unk14 = &D_80039640;
                else
                    s2->unk14 = &D_80039AD0;
                
                if (s2->unk1A)
                    s2->x_position = v1->x_position + 15.0f;
                else
                    s2->x_position = v1->x_position - 15.0f;

                s2->y_position = v1->y_position;
            }
            for (i = 0; i < 0x50; i++) {
                ArcadeStruct1 *iPtr;
                ArcadeStruct1 *v1;

                iPtr = &D_8004BCD0[(u8)i];
                
                if ((iPtr->unk18 == ARCADE_OBJ_01_BARREL) 
                    || (iPtr->unk18 == ARCADE_OBJ_04_PIE) 
                    || (iPtr->unk18 == ARCADE_OBJ_02_FLAME_ENEMY) 
                ) {
                    if (__arcade_abs_w((s32)(iPtr->x_position - s2->x_position)) < 0xD
                        && __arcade_abs_w((s32)(iPtr->y_position - s2->y_position)) < 0x8
                    ) {
                        func_80737638(D_8076D1F8, SFX_4B_ARCADE_HAMMER_ATTACK, 0x7fff, 0x3f, 1.0f, 0, 0);
                        v1 = &D_8004BCD0[(u8)func_800247F0()];
                        *v1 = arcade_bonus_item_obj_template;
                        v1->unk18 = ARCADE_OBJ_07_HAMMER_PARTICLES;
                        v1->unk1D = iPtr->unk18;
                        v1->x_position = s2->x_position;
                        v1->y_position = s2->y_position;
                        iPtr->unk18 = 0;
                        arcade_game_state = 1;
                    }
                }
            }
            if (D_8004C710-- == 1) {
                s2->unk18 = 0; //destroy hammer
                func_800252A4(SFX_0_SILENCE); //play_sfx
                func_80025240(); //queue_background_music
            }
            break;
        }
    }//L8003071C
}

void func_80030734(u8 arg0) {
    u8 temp_a0;
    u8 temp_v0;
    ArcadeStruct1 *temp_s0 = &D_8004BCD0[arg0];

    if (temp_s0->unk1C >= 0x37) {
        temp_s0->unk14 = &D_8003A3F0;
    } else {
        temp_a0 = temp_s0->unk1C / 6 % 3;
        if (temp_a0 == 0) {
            temp_s0->unk14 = &D_80039D18;
        } else if (temp_a0 == 1) {
            temp_s0->unk14 = &D_80039F60;
        } else {
            temp_s0->unk14 = &D_8003A1A8;
        }
    }

    if (temp_s0->unk1C++ == 0x42) {
        temp_s0->unk18 = ARCADE_OBJ_14_POINTS_TEXT;
        temp_v0 = func_80024644() & 3;
    
        if ((temp_s0->unk1D == 2) && (temp_v0 == 0)) {
            temp_s0->unk14 = &D_800387C8;
            arcade_add_points_to_score(800);
        } else if ((temp_s0->unk1D == 2) && (temp_v0 == 1)) {
            temp_s0->unk14 = &D_800385C0;
            arcade_add_points_to_score(500);
        } else {
            temp_s0->unk14 = &D_800383B8;
            arcade_add_points_to_score(300);
        }
        temp_s0->unk10 = 0.0f;
        arcade_game_state = 0;
    }
}

void arcade_rivet_update(u8 arg0) {
    u8 temp_t6;

    if (D_8004BCD0[arg0].x_position == (s32) D_8004BCD0[D_8004C71F].x_position
        && (D_8004BCD0[arg0].y_position - D_8004BCD0[D_8004C71F].y_position < 20.0f) 
        && (D_8004BCD0[arg0].y_position - D_8004BCD0[D_8004C71F].y_position > -2.0f)
    ) {
        D_8004BCD0[arg0].unk1D = 1;
    }
    else if (D_8004BCD0[arg0].unk1D) {
        D_8004BCD0[arg0].unk18 = 0;
        D_8004C718 = D_8004C718 ^ D_8004BCD0[arg0].unk1C;
        if (D_8004C718) {
            temp_t6 = func_800247F0();
            D_8004BCD0[temp_t6] = arcade_points_text_obj_template;
            D_8004BCD0[temp_t6].x_position = D_8004BCD0[D_8004C71F].x_position;
            D_8004BCD0[temp_t6].y_position = D_8004BCD0[D_8004C71F].y_position + 14.0f;
            D_8004BCD0[temp_t6].unk10 = 0.0f;
            
            arcade_add_points_to_score(100);
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80030A04.s")
#else
void func_80030A04(u8 index) {
    f32 phi_f0;
    if (arcade_game_state == 0) {
        D_8004BCD0[index].unk10--;
        if (D_8004BCD0[index].unk10 < 0.0f) {
            D_8004BCD0[index].unk10 = (func_80024644() & 0x7F) + 0x1C2;
        }
        // Ternary works here but doesn't change regalloc
        if (D_8004BCD0[index].unk10 < 200.0f) {
            phi_f0 = 0.2f;
        } else {
            phi_f0 = -0.2f;
        }
        D_8004BCD0[index].y_position += phi_f0;
        if (D_8004BCD0[index].y_position < 97.0f) {
            D_8004BCD0[index].y_position = 97.0f;
        }
        if (D_8004BCD0[index].y_position < 110.0f) {
            D_8004BCD0[index].y_position = 110.0f;
        }
    }
}
#endif

void arcade_pie_update(u8 arg0) {
    if (arcade_game_state == 0) {
        D_8004BCD0[arg0].x_position += D_8004A308[D_8004BCD0[arg0].unk1C];
        if ((D_8004BCD0[arg0].x_position > 288.0f) 
            || (D_8004BCD0[arg0].x_position < 32.0f)
            || ((D_8004BCD0[arg0].x_position == 160.0f) && (D_8004BCD0[arg0].y_position == 127.0f)) 
        ) {
            D_8004BCD0[arg0].unk18 = 0;
        }
        if ((__arcade_abs_w(D_8004BCD0[arg0].x_position - D_8004BCD0[D_8004C71F].x_position) < 0xC)
            && (D_8004BCD0[arg0].y_position - D_8004BCD0[D_8004C71F].y_position < 4.0f) 
            && (D_8004BCD0[arg0].y_position - D_8004BCD0[D_8004C71F].y_position > -8.0f)
        ) {
            func_80027E8C();
        }
    }
}


void func_80030C70(u8 arg0) {
    if (!(D_8004BCD0[func_80024860(0x17)].unk10 > 460.0f)) {
        D_8004BCD0[arg0].unk1A = (D_8004BCD0[arg0].unk1C++ / 8) & 1;
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_80030CEC.s")
#else
void func_80030CEC(u8 arg0) {
    u8 a0;
    if (D_8004BCD0[arg0].unk19 == 4)
        return;
    if ((D_807ECDE8->unk0 & 0x200) || D_807ECDE8->unk2 < -0x14) {
        D_8004C720--;
        switch(D_8004C720) {
            case 0://L80030D74
                D_8004C720 = 8;
            case 0xb://L80030D80
                D_8004BCD0[arg0].unk1D--;
                if (D_8004BCD0[arg0].unk1D >= 0x29) {
                    D_8004BCD0[arg0].unk1D = 0x1d;
                }
                break;
        }
    } else if ((D_807ECDE8->unk0 & 0x100) || D_807ECDE8->unk2 >= 0x15) {//L80030DB0
        D_8004C720--;
        switch(D_8004C720) {
            case 0://L80030D74
                D_8004C720 = 8;
            case 0xb://L80030D80
                D_8004BCD0[arg0].unk1D++;
                if (D_8004BCD0[arg0].unk1D >= 0x1e) {
                    D_8004BCD0[arg0].unk1D -= 0x1e;
                }
                break;
        }
    } else {//L80030E2C
        D_8004C720 = 0xC;
    }//L80030E40
    a0 = D_8004BCD0[arg0].unk1D;
    D_8004BCD0[arg0].unk0 = (f32) (((a0 % 0x10) * 0x10) + 0x54);
    D_8004BCD0[arg0].unk4 = (f32) (((s32) ((a0 / 0xA) << 7) / 7) + 0x4A);
    if (newly_pressed_input & 0x8000) {
        if ((a0 = 0x1D) || (D_8004C6DC == 0x708)) {
            D_8004C6DC = 0x744;
            D_8004BCD0[arg0].unk19 = 4;
            arcade_saved_high_score_initials[D_8004BCD0[arg0].unk1C][0] = D_8004A774[0];
            arcade_saved_high_score_initials[D_8004BCD0[arg0].unk1C][1] = D_8004A774[1];
            arcade_saved_high_score_initials[D_8004BCD0[arg0].unk1C][2] = D_8004A774[2];
            func_80024320();
        } else if (a0 = 0x1C && D_8004BCD0[arg0].unk19) {//L80030F2C
            D_8004BCD0[arg0].unk19--;
            D_8004A774[D_8004BCD0[arg0].unk19] = D_80746800[0x1C]; 
        } else if (D_8004BCD0[arg0].unk19 < 3) {//L80030F70
            D_8004A774[D_8004BCD0[arg0].unk19] = D_80746800[D_8004BCD0[arg0].unk1D];
            D_8004BCD0[arg0].unk19++;
        }
    }
}
#endif

void arcade_barrel_stack_update(u8 arg0) {
    if (D_8004BCD0[arg0].unk1C >= D_8004C71E)
        D_8004BCD0[arg0].unk18 = 0;
}

//arcade update objects
void func_80030FEC(void) {
    u8 i;
    for (i = 0; i < 0x50; i++) {
        switch(D_8004BCD0[i].unk18) {
            case ARCADE_OBJ_01_BARREL: //80031030
                func_8002CD64(i);
                break;
            case ARCADE_OBJ_02_FLAME_ENEMY: //80031040
                func_8002D6FC(i);
                break;
            case ARCADE_OBJ_03_SPRING: //80031050
                func_8002E158(i);
                break;
            case ARCADE_OBJ_13_OIL_DRUM_FLAMES: //80031060
                func_8002E3D4(i);
                break;
            case ARCADE_OBJ_0D_JUMPMAN://80031070
                func_8002B89C(i);
                break;
            case ARCADE_OBJ_1A_PAULINE_BOTTOM://80031080
                arcade_pauline_bottom_update(i);
                break;
            case ARCADE_OBJ_1E_NINTENDO_COIN://80031090
                arcade_nintendo_coin_update(i);
                break;
            case ARCADE_OBJ_1D_HELP_TEXT://800310A0
                arcade_help_text_update(i);
                break;
            case ARCADE_OBJ_1B_PAULINE_TOP://800310B0
                arcade_pauline_top_update(i);
                break;
            case ARCADE_OBJ_12_PULLEY://800310C0
                arcade_pulley_update(i);
                break;
            case ARCADE_OBJ_15_DK_TITLE://800310D0
                arcade_dk_title_update(i);
                break;
            case ARCADE_OBJ_16_DK_25M://800310E0
                func_8002EEB8(i);
                break;
            case ARCADE_OBJ_17_DK_100M://800310F0
                func_8002F82C(i);
                break;
            case ARCADE_OBJ_18_DK_75M://80031100
                func_8002FE28(i);
                break;
            case ARCADE_OBJ_19_DK_50M://80031110
                arcade_dk_50m_update(i);
                break;
            case ARCADE_OBJ_14_POINTS_TEXT://80031120
                arcade_points_text_update(i);
                break;
            case ARCADE_OBJ_05_BONUS_ITEM://80031130
                arcade_bonus_item_update(i);
                break;
            case ARCADE_OBJ_06_HAMMER://80031140
                arcade_hammer_update(i);
                break;
            case ARCADE_OBJ_07_HAMMER_PARTICLES://80031150
                func_80030734(i);
                break;
            case ARCADE_OBJ_0B_RIVET://80031160
                arcade_rivet_update(i);
                break;
            case ARCADE_OBJ_0C_MOVING_LADDER://80031170
                func_80030A04(i);
                break;
            case ARCADE_OBJ_09_NAME_SELECT_CURSOR: //80031180
                func_80030CEC(i);
                break;
            case ARCADE_OBJ_04_PIE: //80031190
                arcade_pie_update(i);
                break;
            case ARCADE_OBJ_0F_100M_COMPLETE_PARTICLE: //800311A0
                func_80030C70(i);
                break;
            case ARCADE_OBJ_0A_BARREL_STACK: //800311B0
                arcade_barrel_stack_update(i);
                break;
            default:
                break;
        }
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_800311E0.s")

/*
void func_800311E0(void) {
    u8 sp1F;
    u8 i;

    if (!(D_8004C6DC & 1)) {
        D_8004A308[1] = 1;
        D_8004A308[2] = -1;
        D_8004A308[3] = (D_8004C6DC / 0x15E) & 1 ? 1 : -1;
    } else {//L80031238
        for (i = 0; i < 4; i++) {\
            D_8004A308[i] = 0;
        }
    }

    if (D_8004C6DC % 0x78 == 0 && arcade_get_object_type_count(ARCADE_OBJ_04_PIE) < 5) {
        sp1F = func_80024764();
        D_8004BCD0[sp1F] = arcade_pie_obj_template;
        if (func_80024644() > 0x4000) {
            if ((D_8004C6DC / 350) & 1)
                D_8004BCD0[sp1F].x_position = 40;
            else
                D_8004BCD0[sp1F].x_position = 280;
        } else {//L80031354
            D_8004BCD0[sp1F].y_position = 127;
            if (func_80024644() > 0x4000) {
                D_8004BCD0[sp1F].unk1C = 1;
                D_8004BCD0[sp1F].x_position = 40;
            } else {
                D_8004BCD0[sp1F].unk1C = 2;
                D_8004BCD0[sp1F].x_position = 280;
            }
        }
    }//L800313AC
}
*/

void func_800313B8(void) {
    u8 sp1f;
    u8 temp_v1;
    s32 t3 = 1;
    
    if (D_8004C6DC % 0xC8 == 0 
        && arcade_get_object_type_count(ARCADE_OBJ_02_FLAME_ENEMY) < 5
    ) {
        sp1f = func_80024764();
        D_8004BCD0[sp1f] = arcade_flame_enemy_obj_template;
        D_8004BCD0[sp1f].unk1A = 0;
        D_8004BCD0[sp1f].x_velocity = -0.5f;
        D_8004BCD0[sp1f].x_position = 244.0f;
        temp_v1 = func_80024644() & 0x7;
        if (temp_v1 >= 4) {
            temp_v1 = 1;
        }
        D_8004BCD0[sp1f].x_position = D_8004A318[2*temp_v1];
        D_8004BCD0[sp1f].y_position = D_8004A318[2*temp_v1 + 1];
        if (160.0f < D_8004BCD0[D_8004C71F].x_position) {
            D_8004BCD0[sp1f].unk1A = 1 -  D_8004BCD0[sp1f].unk1A;
            D_8004BCD0[sp1f].x_velocity = -D_8004BCD0[sp1f].x_velocity;
            D_8004BCD0[sp1f].x_position = 320.0f - D_8004BCD0[sp1f].x_position;
        }
    }//L80031534
    if (!D_8004C718) {
        func_800252A4(SFX_0_SILENCE);
        D_8004C718 = 1;
        D_8004C708 = t3;
        arcade_game_state = 2;
        D_8004BCD0[func_80024860(ARCADE_OBJ_17_DK_100M)].unk19 = 8;
    }
}

void func_8003159C(Gfx **arg0) {
    u8 padA4;
    Gfx *spA0;
    char sp50[0x50];
    int i;

    spA0 = *arg0;
    if (D_8004C724 == 3) {
        func_800244E4(0x00, 0xff, 0xff, 0xff);
        func_80024508(0x78, 0x3b);
        func_800031E0(sp50, &D_8004A840, &D_8004A774);
        //func_800031E0(sp50, "NAME %.3s", &D_8004A774);
        func_8002451C(&spA0, sp50);
        func_80024508(0xA0, 0x41);
        func_800031E0(sp50, &D_8004A84C);
        //func_800031E0(sp50, "---");
        func_8002451C(&spA0, sp50);
        if (D_8004C6DC < 1800) {
            func_80024508(0x60, 0x7b);
            func_800031E0(sp50, &D_8004A850, 30 - D_8004C6DC/60);
            //func_800031E0(sp50, "REGI TIME <%02d>", 30 - D_8004C6DC/60);
        } else {//L800316A0
            func_80024508(0x40, 0x7b);
            func_800031E0(sp50, &D_8004A864);
            //func_800031E0(sp50, "YOUR NAME WAS");
            func_8002451C(&spA0, sp50);

            func_80024508(0xb0, 0x7b);
            func_800031E0(sp50, &D_8004A874);
            //func_800031E0(sp50, "REGISTERED.");

        }//L800316E8
        func_8002451C(&spA0, sp50);
        func_800244E4(0xff, 0x00, 0x00, 0xff);
        func_80024508(0x58, 0x2b);
        func_800031E0(sp50, &D_8004A880);
        //func_800031E0(sp50, "NAME REGISTRATION");
        func_8002451C(&spA0, sp50);

        func_800244E4(0x00, 0xff, 0x00, 0xff);
        func_80024508(0x58, 0x4b);
        func_800031E0(sp50, &D_8004A894);
        //func_800031E0(sp50, "A B C D E F G H I J");
        func_8002451C(&spA0, sp50);
        
        func_80024508(0x58, 0x5b);
        func_800031E0(sp50, &D_8004A8A8);
        //func_800031E0(sp50, "K L M N O P Q R S T");
        func_8002451C(&spA0, sp50);
        
        func_80024508(0x58, 0x6b);
        func_800031E0(sp50, &D_8004A8BC);
        //func_800031E0(sp50, "U V W X Y Z . -");
        func_8002451C(&spA0, sp50);

        func_80024508(0xd4, 0x6b);
        func_800031E0(sp50, &D_8004A8CC);
        //func_800031E0(sp50, "ba");
        func_8002451C(&spA0, sp50);
    }//L800317E0

    func_800244E4(0xFF, 0x00, 0x00, 0xff);
    for (i = 0; i < 5; i++) {
        if (i == 3)
            func_800244E4(0xFF, 0xFF, 0x00, 0xff);
        func_80024508(0x38, 0x8b + i*0x10);
        if (i == D_8004BCD0[0].unk1C
            && D_8004C6DC & 0x20
            && D_8004C724 == 3
        ) {
            func_800031E0(sp50, &D_8004A8D0, &D_8004A82C[i]);
        } else {//L80031888
            func_800031E0(sp50, &D_8004A8D8, D_8004A82C[i], arcade_saved_high_scores[i], arcade_saved_high_score_initials[i]);
        }//L800318B8
        func_8002451C(&spA0, sp50);
    }

    func_800244E4(0x00, 0xff, 0x00, 0xff);
    func_80024508(0xb8, 0xdb);
    func_800031E0(sp50, &D_8004A8EC);
    func_8002451C(&spA0, sp50);

    *arg0 = spA0;
}

void func_80031948(s8 arg0) {
    if (arg0 == D_8004A768) {
        func_800244E4(0xff, 0xff, 0xff, 0xff);
    } else if (arcade_background_visual == 2) {
        func_800244E4(0xff, 0xa0, 0x10, 0xff);
    } else {
        func_800244E4(0, 0xff, 0xff, 0xff);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/arcade/code_0/func_800319D4.s")
#else
void func_800319D4(Gfx **arg0) {
    int i;
    Gfx *sp90;
    char sp40[0x50];
    s32 score;
    u8 sp3B;

    sp90 = *arg0;
    gDPSetScissor(sp90++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    D_8004C6D4 = 0x400;
    D_8004C719 = 8;
    D_8004C6D0 = &D_8003DA90;
    D_8004C71A = 8;
    guSprite2DInit(&D_8004BBF0[D_807444FC], D_8004C6D0, 0,
        D_8004C719, D_8004C719, D_8004C71A,
        G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0
    );
    func_8070E8F0(&sp90, &D_8004BBF0[D_807444FC]);
    func_8070F2C8(0x400, D_8004C6D6, 0, 0);
    for (i = 0; i < arcade_lives_visual; i++) {
        func_8070F2FC(&sp90, (s16)(0x360 + i * 0x20), 0x4C, i);
    }
    func_800244E4(0xff, 0, 00, 0xff);
    if ((D_8004C6D8 & 0x10) || !D_8004C724) {
        func_80024508(0x48, 0x13);
        func_800031E0(sp40, "1UP");
        func_8002451C(&sp90, sp40);
    }//L80031B78

    func_80024508(0x78, 0x13);
    func_800031E0(sp40, "HIGH SCORE");
    func_8002451C(&sp90, sp40);

    func_800244E4(0, 0, 0xff, 0xff);
    func_80024508(0xd8, 0x1b);
    func_800031E0(sp40, "L=%02d", D_8004A76C);
    func_8002451C(&sp90, sp40);

    func_800244E4(0xff, 0xff, 0xff, 0xff);
    func_80024508(0x38, 0x1b);
    func_800031E0(sp40, "%06d    %06d", arcade_current_score, D_8004A760);
    func_8002451C(&sp90, sp40);

    if (D_8004C724 == 5 || D_8004C724 == 4) {//L80031C50
        if (D_8004A764) {
            if (arcade_background_visual == 2) {
                func_800244E4(0xff, 0xa0, 0x10, 0xff);
            } else if (arcade_background_visual == 4) {//L80031C8C
                func_800244E4(0xff, 0xff, 0xff, 0xff);
            } else {
                func_800244E4(0, 0xff, 0xff, 0xff);
            } //L80031CC4
            func_80024508(0x78, 0xa3);
            func_800031E0(sp40, "GAME OVER");
            func_8002451C(&sp90, sp40);
        }//L80031CF4
        if (D_8004C724 == 4) {
            if (!D_8004A768 || arcade_background_visual == 4) {
                func_800244E4(0xff, 0xff, 0xff, 0xff);
            } else if (arcade_background_visual == 2) {
                func_800244E4(0xff, 0xa0, 0x10, 0xff);
            } else {
                func_800244E4(0, 0xff, 0xff, 0xff);
            }//L80031D64
            func_80031948(0);
            func_80024508(0x88, 0x8b);
            func_800031E0(sp40, "RETURN");
            func_8002451C(&sp90, sp40);

            func_80031948(1);
            func_80024508(0x68, 0x9b);
            func_800031E0(sp40, "DELETE HISCORE");
            func_8002451C(&sp90, sp40);

            func_80031948(2);
            func_80024508(0x68, 0xab);
            func_800031E0(sp40, "EXIT DK ARCADE");
            func_8002451C(&sp90, sp40);
        }//L80031DF8
        if (arcade_background_visual == 2) {
            if (D_8004C71E < 0xA) {
                func_800244E4(0, 0, 0xff, 0xff);
            } else {
                func_800244E4(0xff, 0xa0, 0x10, 0xff);
            }
        } else if (arcade_background_visual == 4) {//L80031E54
            if (D_8004C71E < 0xA) {
                func_800244E4(0xf0, 0x30, 0, 0xff);
            } else {
                func_800244E4(0xff, 0xff, 0xff, 0xff);
            }
        } else {
            if (D_8004C71E < 0xA) {
                func_800244E4(0xff, 0, 0, 0xff);
            } else {
                func_800244E4(0x60, 0xe0, 0xff, 0xff);
            }
        }//L80031EE4
        func_80024508(0xe0, 0x30);
        score = MAX(D_8004C71E, 0);
        func_800031E0(sp40, "%02d00", score, score);
        func_8002451C(&sp90, sp40);
        
    }//L80031F30
    if (D_8004C724 == 2) {
        sp3B = (D_8004C723 & 3) + 1;
        func_800244E4(0xff, 0xff, 0xff, 0xff);
        func_80024508(0x48, 0xd7);
        func_800031E0(sp40, "HOW HIGH CAN YOU GET ?");
        func_8002451C(&sp90, sp40);
        func_80024508(0x58, 0xc9);
        func_800031E0(sp40, "@%%m");
        func_8002451C(&sp90, sp40);
        //sp34 = sp3B;
        if (sp3B >= 2) {
            func_80024508(0x58, 0xad);
            func_800031E0(sp40, "%%)m");
            func_8002451C(&sp90, sp40);
        }
        if (sp3B >= 3) {
            func_80024508(0x58, 0x91);
            func_800031E0(sp40, "&%%m");
            func_8002451C(&sp90, sp40);
        }
        if (sp3B >= 4) {
            func_80024508(0x50, 0x75);
            func_800031E0(sp40, "!))m");
            func_8002451C(&sp90, sp40);
        }
    }//L80032054
    if (D_8004C724 == 3) {
        func_8003159C(&sp90);
    }//L80032078
    if (D_8004C724 == 0) {
        if (!(D_8004C6DC & 0x200)) {
            func_800244E4(0, 0xff, 0xff, 0xff);
            func_80024508(0x70, 0x33);
            func_800031E0(sp40, "INSERT COIN");
            func_8002451C(&sp90, sp40);

            func_80024508(0x68, 0x43);
            func_800031E0(sp40, "PLAYER    COIN");
            func_8002451C(&sp90, sp40);

            func_80024508(0x78, 0x53);
            func_800031E0(sp40, "1        1");
            func_8002451C(&sp90, sp40);

            func_80024508(0x38, 0x7b);
            func_800031E0(sp40, "RANK  SCORE  NAME");
            func_8002451C(&sp90, sp40);
            func_8003159C(&sp90);
            func_800244E4(0xff, 0, 0, 0xff);

            func_80024508(0x78, 0x63);
            func_800031E0(sp40, "2        2");
            func_8002451C(&sp90, sp40);
        } else {//L80032190
            if (D_8004C6DC & 0x182) {
                func_800244E4(0xff, 0xa0, 0x10, 0xff);
            } else {
                func_800244E4(0xff, 0xff, 0xff, 0xff);
            }
            func_80024508(0x68, 0xd7);
            func_800031E0(sp40, "c NINTENDO 1981");
            func_8002451C(&sp90, sp40);
        }
    }//L800321EC
    *arg0 = sp90;
    D_8004A83C++;
}
#endif
