#include <ultra64.h>
#include "functions.h"


extern s32 *D_8076A080;
extern s32 D_807FF100;
extern s32 D_8000DDE4;
extern s32 D_8076A084;
extern u8 D_807467CC;
extern u8 D_8076A0B2;
extern Mtx D_80769018;
extern u16 D_8076A09C;
extern f32 D_807444B8;
extern f32 D_807444BC;
extern f32 D_807444C4;
extern f32 D_807444C8;
extern u8 D_8076A0B1; // map_state
extern u8 D_8076A0B3; // cutscene_bar_state

extern u8 D_80746830;
extern s32 D_8076A090;
extern s32 D_8076A094;
extern s32 D_8076A098;
extern u16 D_80750AC4;
extern u8 D_8076A0A4;
extern s32 D_8076A068;
extern u16 *D_807ECDF4;
extern s32 D_8076A06C;
extern u8 D_80744500;
extern u8 D_80750AC0; // number_of_players?
extern s32 D_807F6010;
extern s32 *D_8076A0A0;
extern s16 D_8076A0AA;
extern s32 next_exit;
extern u8 D_807F6008;
extern u8 D_80745BDC[]; // Might be a struct array
extern f32 D_807565D8;
extern f32 D_807FD888; // loading_zone_fadeout_progress
extern f32 loading_zone_transition_speed;
extern u8 D_807444F8;
extern u8 loading_zone_transition_type;

extern Mtx D_80767E68;
extern Mtx D_80767CE8;
extern Mtx D_80768E98;

f32 func_8062A850(void);
void func_8060B140(s32, s32*, s32*, s32, s32, s32, s32);
void func_8060AA04();
void func_80631B80();
void func_806C9AE0();
void func_80731030();
void func_805FF118();
void func_8063DB0C();

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FB300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FB5C4.s")

extern s32 D_8000DDCC;
extern OSIoMesg D_807ECE00;
extern OSMesgQueue D_807655F0;
extern OSMesg D_80765608;

extern OSMesgQueue D_807656D0;
extern OSMesg D_807656E8;

extern OSMesgQueue D_807659E8;
extern OSMesg D_80765A00;

extern OSMesg D_8076A128;
extern OSMesg D_8076A108;

extern OSTimer D_8076A130;

void func_805FB750(s32 arg0, s32 arg1, void* arg2) {
    s32 sp2C;

    sp2C = D_8000DDCC;
    osWritebackDCache(arg2, arg1);
    osPiStartDma(&D_807ECE00, 0, 0, sp2C + arg0, arg2, arg1, &D_807655F0);
    osRecvMesg(&D_807655F0, 0, 1);
    osInvalDCache(arg2, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FB7E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FB944.s")

void func_805FB7E4();
void func_80610350(u8, u8);
extern OSViMode *D_8000EF20[];
extern s16 D_80744494;
extern s16 D_80744498;
extern s16 D_8074449C;
extern s16 D_807444A0;
extern s16 D_807444A4;
extern s16 D_807444A8;
extern s16 D_807444AC;
extern s16 D_807444B0;
extern s16 D_807444B4;
extern u8 D_8074450C;
extern s8 D_80744510;
extern s32 D_80744584[][2];
extern s8 D_807445A0;
extern s8 D_807445A4;
extern s16 D_80744490;

/*
void func_805FB944(u8 arg0) {
    s32 sp18;
    s16 temp_v1;
    s32 temp_v0;
    s32 temp_a0;
    s32 var_a2;
    u8 var_a1 = 1;

    sp18 = 0;
    func_806003EC(D_8076A0AA);
    var_a2 = sp18;
    if (current_map == MAP_NINTENDO_LOGO) {
        D_8074450C = 2;
    } else {
        D_8074450C = 1;
    }
    switch (is_cutscene_active) {
    case 3:
        var_a1 = 9;
    case 4:
        if (var_a1 == 1) {
            var_a1 = 0xA;
        }
        D_80744498 = 0;
        D_8074449C = 0;
        D_807444A0 = (D_8074450C * 0x140) - 1;
        D_807444A4 = (D_8074450C * 0xF0) - 1;
        break;
    default:
        var_a2 = func_8060042C(current_map);
        var_a1 = 1;
        if (D_807FBB64 & 1) {
            var_a1 = 7;
        } else if (D_807FBB64 & 0x1000) {
            var_a1 = 6;
        } else if (D_807FBB64 & 0x104000) {
            var_a1 = 8;
        } else if (D_807FBB64 & 0x80000) {
            var_a1 = 4;
        } else if (D_807FBB64 & 0x2000) {
            var_a1 = 5;
        } else if (D_807FBB64 & 0x04000000) {
            var_a1 = 3;
        } else if (D_807FBB64 & 0x40000000) {
            var_a1 = 2;
        }
        temp_v0 = D_8074450C;
        temp_v1 = temp_v0 * 0xA;
        D_80744498 = temp_v1;
        D_8074449C = temp_v1;
        D_807444A0 = (temp_v0 * 0x136) - 1;
        D_807444A4 = (temp_v0 * 0xE6) - 1;
        break;
    }
    func_80610350(arg0, var_a1);
    if (D_807445A4 == 0) {
        osViSetMode(&D_8000EF20[D_80744584[osTvType][D_8074450C]]);
        if (D_807445A0 == 0) {
            osViBlack(1U);
        }
        D_80744510 = 0;
        D_807445A0 = 0;
    } else {
        D_80744510 = 1;
        D_807445A0 = 1;
        D_807445A4 = 0;
        func_805FB7E4();
    }
    osViSetSpecialFeatures(0x42U);
    D_80744490 = D_8074450C * 0x140;
    D_80744494 = D_8074450C * 0xF0;
    temp_a0 = D_8074450C * 0x1E;
    D_807444AC = D_8074449C + temp_a0;
    D_807444B0 = D_807444A4 - temp_a0;
    D_807444A8 = D_8074449C;
    D_807444B4 = D_807444A4;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FBC5C.s")

extern s32 D_8076A07C;
extern OSMesgQueue D_8076A110;
extern s32 D_8000DDE8;
extern s32 D_8000DDE4;

extern s32 D_80767CD8;

/*
// TODO: Pretty close
void func_805FBC5C(void) {
    // This might be a static struct field access
    D_8076A084 = D_8000DDE8 - D_8000DDE4;
    osCreateMesgQueue(&D_807655F0, &D_80765608, 0x32);
    osCreateMesgQueue(&D_807656D0, &D_807656E8, 0xC0);
    func_8060EC80(&D_80767A40, &D_80767A40, 0x19, osTvType, 1);
    osCreateMesgQueue(&D_807659E8, &D_80765A00, 0x10);
    func_8060ED6C(&D_80767A40, &D_80767CD8, &D_807659E8, 1, 1);
    current_map = next_map;
    func_805FB944(0);
    D_8076A07C = 5;
    func_8060FFF0();
    func_8060A900();
    func_80600D50();
    setIntroStoryPlaying(0);
    func_8073239C();
    osWriteBackDCacheAll();
    osCreateMesgQueue(&D_8076A110, &D_8076A108, 2);
    osSetTimer(&D_8076A130, 0, 0xD693A4, &D_8076A110, D_8076A128);
    playSound(0x23C, 0x7FFF, 63.0f, 1.0f, 0, 0);
}
*/

void func_805FBE04(void) {
    s32 stackpad1;
    f32 FOV;

    osWriteBackDCacheAll();
    osInvalDCache((void*)0x80000000, 0x800000);
    D_8076A080 = &D_807FF100;
    func_8060B140(D_8000DDE4, D_8076A080, &D_8076A084, 0, 0, 0, 0);
    D_8076A0A4 = 0;
    func_8060AA04();
    object_timer = 0;
    D_8076A068 = 0;
    D_807467CC = 0;
    current_exit = 4;
    global_properties_bitfield = 0x30030;
    D_8076A0B1 |= 1;
    D_8076A0B2 = 0;
    D_807FD888 = 31.0f; // loading_zone_fadeout_progress
    D_8076A0B1 |= 4;
    func_80631B80();
    func_806C9AE0();
    func_80731030();
    func_805FF118();
    func_8063DB0C();
    FOV = func_8062A850(); // getFieldOfView()
    guTranslate(&D_80767E68, 0.0f, 0.0f, 0.0f);
    guTranslate(&D_80769018, 0.0f, 0.0f, 0.0f);
    guPerspective(&D_80767CE8, &D_8076A09C, D_807444B8, D_807444BC * FOV, D_807444C8, D_807444C4, 1.0f);
    guPerspective(&D_80768E98, &D_8076A09C, D_807444B8, D_807444BC * FOV, D_807444C8, D_807444C4, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FBFF4.s")

extern s32 D_8076A070;
extern s32 osTvType;
extern s8 D_80744460;
extern u16 D_8074682C;
extern u8 D_80744504;
extern u8 D_807F059C;
extern u64 D_80761680;
extern s32 D_807655E0;
extern u8 D_807444F0;
extern s32 D_80767CC0;

/*
// TODO: Remarkably close, just missing some NOPs
void func_805FBFF4(s32 arg0) {
    s32 phi_s4;
    OSMesg* sp38;

    phi_s4 = 1;
    if (osTvType == OS_TV_PAL) {
        D_807444BC = 1.25f;
    }
    func_805FBC5C();
    osViSetSpecialFeatures(0x42);
    func_805FBE04();
    D_8076A070 = D_80767CC0 - 2;
    osRecvMesg(&D_8076A110, &sp38, 1);
    while (TRUE) {
        D_8074682C = 0xC8;

        while (D_80744460) {}

        if (D_8076A0B1 & 1 && !D_8076A0B2) {
            func_805FE7FC();
            if (D_807444F8 == 2) {
                global_properties_bitfield |= 0x200;
                D_80744504 = 8;
            }
        }

        switch (is_cutscene_active) {
            case 6:
                func_8070A934(next_map, next_exit);
                break;
            case 3:
                func_80024000();
                break;
            case 4:
                func_80024000();
                break;
            case 5:
                break;
            default:
                func_805FC2B0();
                break;
        }

        func_80600B10();
        func_8066AF40();
        func_80610268(0x4D2);
        if (D_807F059C) {
            func_80610268(0x929);
        }
        func_80600674(); // calculateLagBoost()
        if ((is_cutscene_active == 0) || (is_cutscene_active == 1) || (is_cutscene_active == 7)) {
            func_80658CCC();
            func_80700BF4();
        }
        func_80611730();
        if (D_80761680 != 0x12345678) {
            func_80732354(2, 0, 0, 0);
        }
        if (phi_s4) {
            osSendMesg(D_807655E0, 0x309, 1);
            phi_s4 = 0;
        }
        if (D_8076A0B1 & 1 && D_807FD888 == 31.0f) {
            D_8076A0B2--;
        }
        D_807444F0 = is_cutscene_active;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FC2B0.s")

extern s32 *D_8076A048;
extern void* D_8076A050[];
extern s32 D_8076A150;
extern s32 D_8076A088;
extern s32 D_8076A08C;
void func_8068C2EC();

/*
void func_805FC2B0(void) {
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;
    s32 phi_v0;

    func_8060A9BC();
    if (D_8076A0A4 != 0) {
        phi_v0 = 0;
    } else {
        phi_v0 = 1;
    }
    //func_80610044(((*0x807444FC * 4) + 0x80770000)->unk-5FB0, D_8076A088, 3, phi_v0 & 0xFF, 0x4D2, 1);
    if (D_8076A0A4 != 0) {
        //func_80610044((D_807444FC * 0x11B0) + 0xDB0 + &D_80767CE8, D_8076A08C, 0, 1, 0x929, 1);
    }
    D_807444FC ^= 1;
    object_timer++;
    if ((global_properties_bitfield & 2) == 0) {
        D_8076A068++;
    }
    *D_8076A048 = (D_807444FC * 0x11B0) + &D_80767CE8;
    func_8060AC7C();
    if (func_805FC668() != 0) {
        func_8065D1AC();
        func_806789E4();
        func_80715270(1);
        func_80603450();
        func_806057F8();
        func_806025D4();
        func_805FCA94(D_8076A048);
    } else {
        func_8065A648();
        func_806787CC();
        func_805FCA94(D_8076A048);
        func_8065D1AC();
        func_8068A508();
        func_8066CDD0();
        func_8066CCD8();
        func_80661054();
        func_80678824();
        func_80663A80();
        func_80715270(0);
        func_80603450();
        func_806025D4();
        func_806057F8();
        func_806F6F28();
    }
    func_8070DD44();
    temp_v0 = *(&D_8076A050 + (D_807444FC * 4));
    //temp_v0 = D_8076A050[D_807444FC * 4];
    D_8076A150 = temp_v0;
    if (((D_8076A0B1 & 1) != 0) && (D_807FD888 == 31.0f)) {
        sp2C = temp_v0;
        sp28 = D_8076A048 + 0xDB0;
        func_8068C2EC();
    } else {
        func_805FD088(D_8076A048, &sp2C, &sp28);
    }
    if ((global_properties_bitfield & 0x100) != 0) {
        global_properties_bitfield &= ~0x100;
        func_807094D0(2, &global_properties_bitfield);
    } else if ((global_properties_bitfield & 0x200) != 0) {
        D_80744504--;
        if (D_80744504 == 0) {
            global_properties_bitfield &= ~0x200;
            func_807094D0(3, &global_properties_bitfield);
        }
    } else {
        sp2C = func_80704484(sp2C, loading_zone_transition_type);
    }
    if ((D_8076A0A4 != 0) && (is_cutscene_active != 6)) {
        func_805FE71C(sp2C, D_807444FC, &D_8076A088, 0);
        func_805FE7B4(sp28, D_8076A048, &D_8076A08C, 1);
        return;
    }
    func_805FE71C(sp2C, D_807444FC, &D_8076A088, 1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FC668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FC98C.s")

u64 func_80005818(u64, u64);
u64 func_80005918(OSTime, u64);
extern OSTime D_807445B8;
extern OSTime D_807445C0;
extern u32 D_80750AB0;

/*
// TODO: Regalloc t0 t1
s32 func_805FC98C(void) {
    OSTime sp18;
    OSTime temp_t8;
    u32 temp_t7;
    OSTime currentTime;

    currentTime = osGetTime();
    temp_t8 = (currentTime - D_807445B8);
    if (global_properties_bitfield & 2) {
        temp_t8 = temp_t8 - currentTime + D_807445C0;
    }
    return func_80005818(func_80005818(func_80005918(temp_t8, 0x40), 3000), 1000000) + D_80750AB0;
}
*/

u8 func_805FCA64(void) { // getCutsceneBarState()
    return !(D_8076A0B1 & 0x10) && !D_8076A0B3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FCA94.s")

extern u8 D_8074450C;

/* rom */
extern Gfx **D_1000020;
extern Gfx **D_1000030;
extern Gfx **D_1000068;
extern Gfx **D_1000040;

void *func_805FCFD8(Gfx *arg0) {
    if (D_8074450C == 2) {
        gSPDisplayList(arg0++, &D_1000068);
    } else {
        gSPDisplayList(arg0++, &D_1000040);
    }
    return arg0++;
}

void *func_805FD030(Gfx *arg0) {
    if (D_8074450C == 2) {
        gSPDisplayList(arg0++, &D_1000030);
    } else {
        gSPDisplayList(arg0++, &D_1000020);
    }
    return arg0++;
}

// display list something
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FD088.s")

// display list something?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FE398.s")

// display list arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FE4D4.s")

extern s32 D_8076A058;

void func_805FE544(u8 arg0) {
    if (D_807FBB64 & 1) {
        D_8076A058 = 6000;
    } else {
        D_8076A058 = arg0 * 3000;
    }
    D_8076A050[0] = (void*)malloc(D_8076A058 * 8);
    D_8076A050[1] = (void*)malloc(D_8076A058 * 8);
    func_805FE71C(func_805FE634(D_8076A050[0], 0), 0, &D_8076A088, 1);
    func_805FE71C(func_805FE634(D_8076A050[1], 1), 1, &D_8076A088, 1);
}

// display list something?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FE634.s")

// display list something?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FE71C.s")

// display list something?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_805FE7B4.s")

void func_80712A40(void);
void func_80605510(void);
void func_8068C080(void);
void func_8070F570(void);
void func_80600950(void);

void func_8060A4D0(s32 arg0, f32 arg1);

void func_8066ADA0(void);
void func_806FBB58(void);
void func_806FD9A0(void);

void func_80705B30();
void func_807215EC();
void func_8072ED90();
void func_80658BD0();

void func_80630300();
void func_80650E20(s32* arg0);
void func_8062F050(s32* arg0);
void func_8065D170();
void func_806588E0(s32 arg0);
void func_80688940();
void func_80631C3C();
void func_8063643C();

void func_806C7C10(void);
void func_806D0430(f32 arg0);
void func_805FE544(u8 arg0);

void func_80631FAC(Maps arg0, s32 arg1);
void func_806886E0(s32* arg0, s32 arg1, s32 arg2);
void func_80663DA0();
void func_8065A570();
void func_80677D80();
void func_8068A7B0();

void func_80626264(void*);
void func_80712B80();
void func_806C7D40(s32 arg0);
void func_80714670();

void func_80724C78(void* arg0);
void func_8061EA78();
void func_806F4778();
void func_8070E8C8();
void func_8060098C(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_80026FD0(s32 arg0);
void func_8002EC08(s32 arg0);

void func_8066BDE0(void);

void func_80701C90(void);
void func_80629190(void);
void func_80600590(s32 arg0);

void func_806641A0();

void func_80712BD4();
void func_805FF670();
void func_805FB944(s32);

void func_805FE7FC(void) {
    s32 *mapGeometry;
    void *sp28;
    s32 *mapSetup;
    f32 phi_f0;
    s32 map;
    u8 player_count;

    D_80746830 = 1;
    D_8076A090 = 0;
    D_8076A094 = 0;
    D_8076A098 = 0;
    global_properties_bitfield &= 0xFFEB3FFC;
    func_80712A40();
    D_80750AC4 = 0;
    D_8076A0A4 = 0;
    D_807444FC = 0;
    object_timer = 0;
    D_8076A068 = 0;
    func_80605510();
    enemies_killed = 0;
    *D_807ECDF4 = 0;
    func_8068C080();
    D_8076A0B1 &= 0xFFCF;
    func_8070F570();
    if (is_cutscene_active == 1) {
        is_cutscene_active = 0;
    }
    D_8076A06C = object_timer;
    D_80744500 = 0;
    func_80600950();
    current_map = next_map;
    map = current_map;
    if (current_map != MAP_MAIN_MENU) {
        if (current_map != MAP_TITLE_SCREEN_NOT_FOR_RESALE_VERSION) {
            global_properties_bitfield |= 0x30030;
        } else {
            global_properties_bitfield &= 0xFFFCFFCF;
        }
    } else {
        global_properties_bitfield &= 0xFFFEFFCF;
    }

    if (map == MAP_DK_ARCADE) {
        is_cutscene_active = 3;
    } else if (map == MAP_JETPAC) {
        is_cutscene_active = 4;
    } else {
        is_cutscene_active = 0;
    }

    func_805FB944(1);
    if (D_80750AC0 > 1) {
        if (!(D_807FBB64 & 0x4000000)) {
            D_80750AC0 = 1;
        }
    }
    func_806C7C10();
    func_806D0430(0.0f);
    func_805FE544(D_80750AC0);

    if (current_map != MAP_ENGUARDE_ARENA) {
        if (current_map == MAP_RAMBI_ARENA) {
            current_character_index[0] = 6;
        }
    } else {
        current_character_index[0] = 7;
    }

    D_807F6010 = 0;
    func_8066ADA0();
    func_806FBB58();
    func_806FD9A0();
    func_807040E0(0xFF, 0xFF, 0xFF);
    func_80704108(0xFF, 0xFF, 0xFF);
    if (!is_cutscene_active) {
        D_8076A0A0 = getPointerTableFile(0x13, MAP_TEST_MAP, 1, 1);
        func_80705B30();
        func_807215EC();
        func_806F3760(current_map); // Load autowalk file
        func_8072ED90();
        func_80658BD0();
        func_80722E00(current_map); // Load path file
        mapGeometry = getPointerTableFile(1, current_map, 1, 1);
        func_80630300();
        func_80650E20(mapGeometry);
        func_8062F050(mapGeometry);
        loadExits(current_map);
        func_8065D170();
        func_806588E0(current_map); // Load per map file, pointer table 20
        func_80688940();
        func_80631C3C();
        func_8063643C();
        mapSetup = getPointerTableFile(9, current_map, 1, 1);
        func_80631FAC(current_map, 1);
        func_806886E0(mapSetup, 0, 0);
        func_80663DA0();
        func_8065A570();
        func_80677D80();
        func_8068A7B0(); // spawnPersistentActors()
        func_8072E740(current_map);
        func_80626264(sp28 = getPointerTableFile(8, current_map, 1, 1));
        if (sp28) {
            func_8066B434(sp28, 0x8D0, 2);
        }
        func_80712B80();
        func_806C7D40(next_exit);
        func_80714670();
        sp28 = getPointerTableFile(0x10, current_map, 1, 1);
        func_80724C78(sp28);
        if (sp28) {
            func_8066B434(sp28, 0x8DD, 2);
        }
        func_8061EA78();
        func_8068C2EC();
        func_806F4778();
        func_8070E8C8();
        func_8060098C(&func_806025AC, 2, 0, 0, 0);
        if (D_807FBB64 & 0x1000) {
            sp28 = getPointerTableFile(0x16, current_map, 1, 1);
            func_80026FD0(sp28);
            if (sp28) {
                func_8066B434(sp28, 0x8ED, 2);
            }
        }
        if (D_807FBB64 & 0x2000) {
            func_8002EC08(current_map);
        }
        func_8066BDE0();
        D_807F6008 = 0;
        if (!isIntroStoryPlaying() && is_cutscene_active != 2) {
            if (current_map == MAP_HELM && isFlagSet(0x302, FLAG_TYPE_PERMANENT)) {
                playSong(0x74, 1.0f);
            } else {
                phi_f0 = 1.0f;
                if (D_80745BDC[current_map * 4] == 6 || D_80745BDC[current_map * 4] == 0x1F) {
                    phi_f0 = D_807565D8;
                }
                playSong(D_80745BDC[current_map * 4], phi_f0);
            }
        }
        if (current_map == MAP_DK_ISLES_OVERWORLD || current_map == MAP_ENGUARDE_ARENA) {
            playSong(0x60, 1.0f);
        }
        func_8060A4D0(0, 1.0f);
        func_8060A4D0(1, 1.0f);
        func_8060A4D0(2, 1.0f);
        func_805FFEF8(current_map);
        func_806641A0();
    }
    func_80712BD4();
    func_805FF670();
    D_8076A0B1 ^= 1;
    D_807FD888 = 31.0f;
    D_8076A0B1 |= 4;
    loading_zone_transition_speed = -1.0f;
    if (D_807444F8 != 2 && loading_zone_transition_type == 1) {
        playSong(0x2B, 1.0f);
    }
    func_80701C90();
    func_80629190();
    func_80664CB0(D_8076A0AA);
    func_80600590(current_map);
    D_80746830 = 0;
}

extern u8 D_8074447C;
extern u8 D_80744480;
extern u8 D_80744484;
extern u8 D_80744488;

void func_805FEE84(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_8074447C = arg0;
    D_80744480 = arg1;
    D_80744484 = arg2;
    D_80744488 = arg3;
}

void func_805FEEB8(s32 *arg0, s32 arg1) {
    s32 temp_hi;

    temp_hi = *arg0 % arg1;
    if (temp_hi) {
        *arg0 += arg1 - temp_hi;
    }
}
