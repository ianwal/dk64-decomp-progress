#include <ultra64.h>
#include "functions.h"

extern s32 D_dk64_boot_8000DDCC;
extern s32 D_dk64_boot_8000DDE4;

extern u8 D_global_asm_8074447C;
extern u8 D_global_asm_80744480;
extern u8 D_global_asm_80744484;
extern u8 D_global_asm_80744488;
extern f32 D_global_asm_807444B8;
extern f32 D_global_asm_807444BC;
extern f32 D_global_asm_807444C4;
extern f32 D_global_asm_807444C8;
extern u8 D_global_asm_807444F8;
extern u8 D_global_asm_80744500;
extern u8 D_global_asm_8074450C;
extern u8 D_global_asm_80745BDC[]; // Might be a struct array

extern s32 *D_global_asm_8076A080;
extern s32 D_global_asm_8076A084;
extern u8 D_global_asm_807467CC;
extern u8 D_global_asm_8076A0B2;
extern Mtx D_global_asm_80769018;
extern s32 D_global_asm_8076A090;
extern s32 D_global_asm_8076A094;
extern s32 D_global_asm_8076A098;
extern u16 D_global_asm_8076A09C;
extern u8 D_global_asm_8076A0B1; // map_state
extern u8 D_global_asm_8076A0B3; // cutscene_bar_state

extern u8 D_global_asm_80746830;

extern u8 D_global_asm_80750AC0; // number_of_players?
extern u16 D_global_asm_80750AC4;

extern Mtx D_global_asm_80767E68;
extern Mtx D_global_asm_80767CE8;
extern Mtx D_global_asm_80768E98;

extern s32 D_global_asm_8076A058;
extern s32 D_global_asm_8076A068;
extern s32 D_global_asm_8076A06C;
extern s32 *D_global_asm_8076A0A0;
extern u8 D_global_asm_8076A0A4;
extern s16 D_global_asm_8076A0AA;

extern u16 *D_global_asm_807ECDF4;

extern s32 D_global_asm_807FF100;
extern u8 D_global_asm_807F6008;
extern s32 D_global_asm_807F6010;
extern s32 next_exit;
extern f32 D_global_asm_807FD888; // loading_zone_fadeout_progress
extern f32 loading_zone_transition_speed;
extern u8 loading_zone_transition_type;

extern OSIoMesg D_global_asm_807ECE00;
extern UnkMQStruct D_global_asm_807655F0;
extern OSMesg D_global_asm_80765608;

extern UnkMQStruct D_global_asm_807656D0;
extern OSMesg D_global_asm_807656E8;

extern UnkMQStruct D_global_asm_807659E8;
extern OSMesg D_global_asm_80765A00;

extern OSMesg D_global_asm_8076A108;
extern OSMesg D_global_asm_8076A128;
extern OSTimer D_global_asm_8076A130;

void func_global_asm_8060B140(s32, s32*, s32*, s32, s32, s32, s32);

void func_global_asm_80605510(void);

void func_global_asm_80650E20(s32* arg0);

void func_global_asm_806886E0(s32* arg0, s32 arg1, s32 arg2);

void func_global_asm_80626264(void*);
void func_global_asm_806C7D40(s32 arg0);

void func_global_asm_80712BD4(void);
void func_global_asm_805FB944(u8);

void func_global_asm_805FB750(s32 arg0, s32 arg1, void* arg2) {
    s32 sp2C;

    sp2C = D_dk64_boot_8000DDCC;
    osWritebackDCache(arg2, arg1);
    osPiStartDma(&D_global_asm_807ECE00, 0, 0, sp2C + arg0, arg2, arg1, &D_global_asm_807655F0.mq);
    osRecvMesg(&D_global_asm_807655F0.mq, 0, 1);
    osInvalDCache(arg2, arg1);
}

void func_dk64_boot_800024E0(u8 **, u32 *, s32);
void osWriteBackDCacheAll(void);
extern u16 *D_global_asm_80744470[2];

void func_global_asm_805FB7E4(void) {
    s32 empty;
    s32 sp58;
    s32 *temp_s0;
    u16 *var_v1; // 50
    u16 *sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    u32 sp38;
    u16 *end;
    s32 y, x;

    var_v1 = D_global_asm_80744470[0];
    end = &var_v1[0x12C00];
    while (var_v1 < end) {
        *var_v1++ = 1;
    }
    osWriteBackDCacheAll();
    temp_s0 = &D_global_asm_80744470[1][0x6400];
    func_global_asm_805FB750(0x38, 0x10, temp_s0);
    func_global_asm_805FB750(temp_s0[0] + 0x178, 0x10, temp_s0);
    func_global_asm_805FB750(temp_s0[0], temp_s0[1] - temp_s0[0], temp_s0);
    sp3C = temp_s0;
    sp38 = D_global_asm_80744470[1];
    sp4C = D_global_asm_80744470[1];
    func_dk64_boot_800024E0(&sp3C, &sp38, &D_global_asm_80744470[1][0xAF00]);
    var_v1 = &D_global_asm_80744470[0][0x7840];
    for (y = 0; y < 0x30; y++) {
        for (x = 0; x < 0xC0; x++) {
            *var_v1++ = *sp4C++;
        }
        var_v1 += 0x80;
    }
    var_v1 = D_global_asm_80744470[1];
    end = &var_v1[0x12C00];
    while (var_v1 < end) {
        *var_v1++ = 1;
    }
    osWriteBackDCacheAll();
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_450/func_global_asm_805FB944.s")

void func_global_asm_80610350(u8, u8, s32);

extern OSViMode D_dk64_boot_8000EF20[];
extern s16 D_global_asm_80744494;
extern s16 D_global_asm_80744498;
extern s16 D_global_asm_8074449C;
extern s16 D_global_asm_807444A0;
extern s16 D_global_asm_807444A4;
extern s16 D_global_asm_807444A8;
extern s16 D_global_asm_807444AC;
extern s16 D_global_asm_807444B0;
extern s16 D_global_asm_807444B4;
extern u8 D_global_asm_8074450C;
extern u8 D_global_asm_80744510;
extern s32 D_global_asm_80744588[];
extern s8 D_global_asm_807445A0;
extern s8 D_global_asm_807445A4;
extern s16 D_global_asm_80744490;

/*
void func_global_asm_805FB944(u8 arg0) {
    u8 var_a1 = 1;
    s32 var_a2;
    u32 temp;

    var_a2 = 0;
    func_global_asm_806003EC(D_global_asm_8076A0AA);
    if (current_map == MAP_NINTENDO_LOGO) {
        D_global_asm_8074450C = 2;
    } else {
        D_global_asm_8074450C = 1;
    }
    switch (is_cutscene_active) {
        case 3:
            var_a1 = 9;
        case 4:
            if (var_a1 == 1) {
                var_a1 = 0xA;
            }
            D_global_asm_80744498 = 0;
            D_global_asm_8074449C = 0;
            D_global_asm_807444A0 = (D_global_asm_8074450C * 0x140) - 1;
            D_global_asm_807444A4 = (D_global_asm_8074450C * 0xF0) - 1;
            break;
        default:
            var_a2 = func_global_asm_8060042C(current_map);
            var_a1 = 1;
            if (D_global_asm_807FBB64 & 1) {
                var_a1 = 7;
            } else if (D_global_asm_807FBB64 & 0x1000) {
                var_a1 = 6;
            } else if (D_global_asm_807FBB64 & 0x104000) {
                var_a1 = 8;
            } else if (D_global_asm_807FBB64 & 0x80000) {
                var_a1 = 4;
            } else if (D_global_asm_807FBB64 & 0x2000) {
                var_a1 = 5;
            } else if (D_global_asm_807FBB64 & 0x04000000) {
                var_a1 = 3;
            } else if (D_global_asm_807FBB64 & 0x40000000) {
                var_a1 = 2;
            }
            D_global_asm_80744498 = D_global_asm_8074450C * 0xA;
            D_global_asm_8074449C = D_global_asm_8074450C * 0xA;
            D_global_asm_807444A0 = (D_global_asm_8074450C * 0x136) - 1;
            D_global_asm_807444A4 = (D_global_asm_8074450C * 0xE6) - 1;
            break;
    }
    func_global_asm_80610350(arg0, var_a1, var_a2);
    if (D_global_asm_807445A4 == 0) {
        osViSetMode(&D_dk64_boot_8000EF20[D_global_asm_80744588[osTvType + osTvType + D_global_asm_8074450C - 1]]);
        if (D_global_asm_807445A0 == 0) {
            osViBlack(1U);
        }
        D_global_asm_80744510 = 0;
        D_global_asm_807445A0 = 0;
    } else {
        D_global_asm_80744510 = 1;
        D_global_asm_807445A0 = 1;
        D_global_asm_807445A4 = 0;
        func_global_asm_805FB7E4();
    }
    osViSetSpecialFeatures(0x42U);
    D_global_asm_80744490 = D_global_asm_8074450C * 0x140;
    D_global_asm_80744494 = D_global_asm_8074450C * 0xF0;
    D_global_asm_807444AC = D_global_asm_8074449C + (D_global_asm_8074450C * 0x1E);
    D_global_asm_807444B0 = D_global_asm_807444A4 - (D_global_asm_8074450C * 0x1E);
    D_global_asm_807444A8 = D_global_asm_8074449C;
    D_global_asm_807444B4 = D_global_asm_807444A4;
}
*/

extern s32 D_global_asm_8076A07C;
extern OSMesgQueue D_global_asm_8076A110;

extern s32 D_global_asm_80767CD8;

extern dk64_boot_struct_0 D_dk64_boot_8000DCC4[];

void func_global_asm_8060EC80(OSMesgQueue *arg0, void *arg1, s32 arg2, u8 arg3, u8 arg4);

extern s32 D_80767A40; // I hate this, but fixes a compilation issue
void func_global_asm_805FBC5C(void) {
    UnkMQStruct *mq;
    D_global_asm_8076A084 = D_dk64_boot_8000DCC4[12].unk4 - D_dk64_boot_8000DCC4[12].unk0;
    osCreateMesgQueue(&D_global_asm_807655F0.mq, &D_global_asm_807655F0.msgs[0], 0x32);
    osCreateMesgQueue(&D_global_asm_807656D0.mq, &D_global_asm_807656D0.msgs[0], 0xC0);
    func_global_asm_8060EC80(
        &D_global_asm_80767A40.unk0,
        &D_80767A40,
        0x19,
        D_global_asm_80744588[osTvType + osTvType], 1);
    osCreateMesgQueue(&D_global_asm_807659E8.mq, &D_global_asm_807659E8.msgs[0], 0x10);
    func_global_asm_8060ED6C(
        &D_global_asm_80767A40,
        &D_global_asm_80767CD8,
        &D_global_asm_807659E8.mq, 1, 1);
    current_map = next_map;
    func_global_asm_805FB944(0);
    D_global_asm_8076A07C = 5;
    func_global_asm_8060FFF0();
    func_global_asm_8060A900();
    func_global_asm_80600D50();
    setIntroStoryPlaying(0);
    func_global_asm_8073239C();
    osWriteBackDCacheAll();
    mq = &D_global_asm_8076A110;
    osCreateMesgQueue(
        mq,
        &D_global_asm_8076A108, 2);
    osSetTimer(
        &D_global_asm_8076A130,
        0xD693A4,
        0,
        mq,
        mq->msgs[0]);
    playSound(0x23C, 0x7FFF, 63.0f, 1.0f, 0, 0);
}

void func_global_asm_805FBE04(void) {
    s32 stackpad1;
    f32 FOV;

    osWriteBackDCacheAll();
    osInvalDCache((void*)0x80000000, 0x800000);
    D_global_asm_8076A080 = &D_global_asm_807FF100;
    func_global_asm_8060B140(D_dk64_boot_8000DDE4, D_global_asm_8076A080, &D_global_asm_8076A084, 0, 0, 0, 0);
    D_global_asm_8076A0A4 = 0;
    func_global_asm_8060AA04();
    object_timer = 0;
    D_global_asm_8076A068 = 0;
    D_global_asm_807467CC = 0;
    current_exit = 4;
    global_properties_bitfield = 0x30030;
    D_global_asm_8076A0B1 |= 1;
    D_global_asm_8076A0B2 = 0;
    D_global_asm_807FD888 = 31.0f; // loading_zone_fadeout_progress
    D_global_asm_8076A0B1 |= 4;
    func_global_asm_80631B80();
    func_global_asm_806C9AE0();
    func_global_asm_80731030(); // clearTemporaryFlags()
    func_global_asm_805FF118();
    func_global_asm_8063DB0C();
    FOV = func_global_asm_8062A850(); // getFieldOfView()
    guTranslate(&D_global_asm_80767E68, 0.0f, 0.0f, 0.0f);
    guTranslate(&D_global_asm_80769018, 0.0f, 0.0f, 0.0f);
    guPerspective(&D_global_asm_80767CE8, &D_global_asm_8076A09C, D_global_asm_807444B8, D_global_asm_807444BC * FOV, D_global_asm_807444C8, D_global_asm_807444C4, 1.0f);
    guPerspective(&D_global_asm_80768E98, &D_global_asm_8076A09C, D_global_asm_807444B8, D_global_asm_807444BC * FOV, D_global_asm_807444C8, D_global_asm_807444C4, 1.0f);
}

// close, just missing some nops
// https://decomp.me/scratch/lJIx2
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_450/func_global_asm_805FBFF4.s")

extern s32 D_global_asm_8076A070;
extern s32 osTvType;
extern s8 D_global_asm_80744460;
extern u16 D_global_asm_8074682C;
extern u8 D_global_asm_80744504;
extern u8 D_global_asm_807F059C;
extern u64 D_global_asm_80761680;
extern s32 D_global_asm_807655E0;
extern u8 D_global_asm_807444F0;
extern s32 D_global_asm_80767CC0;

/*
void func_global_asm_805FBFF4(s32 arg0) {
    s32 phi_s4;
    OSMesg* sp38;

    phi_s4 = 1;
    if (osTvType == OS_TV_PAL) {
        D_global_asm_807444BC = 1.25f;
    }
    func_global_asm_805FBC5C();
    osViSetSpecialFeatures(0x42);
    func_global_asm_805FBE04();
    D_global_asm_8076A070 = D_global_asm_80767CC0 - 2;
    osRecvMesg(&D_global_asm_8076A110, &sp38, 1);
    while (TRUE) {
        D_global_asm_8074682C = 0xC8;

        while (D_global_asm_80744460) {}

        if (D_global_asm_8076A0B1 & 1 && !D_global_asm_8076A0B2) {
            func_global_asm_805FE7FC();
            if (D_global_asm_807444F8 == 2) {
                global_properties_bitfield |= 0x200;
                D_global_asm_80744504 = 8;
            }
        }

        switch (is_cutscene_active) {
            case 6:
                func_global_asm_8070A934(next_map, next_exit);
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
                func_global_asm_805FC2B0();
                break;
        }

        func_global_asm_80600B10();
        func_global_asm_8066AF40();
        func_global_asm_80610268(0x4D2);
        if (D_global_asm_807F059C) {
            func_global_asm_80610268(0x929);
        }
        func_global_asm_80600674(); // calculateLagBoost()
        if ((is_cutscene_active == 0) || (is_cutscene_active == 1) || (is_cutscene_active == 7)) {
            func_global_asm_80658CCC();
            func_global_asm_80700BF4();
        }
        func_global_asm_80611730();
        if (D_global_asm_80761680 != 0x12345678) {
            raiseException(2, 0, 0, 0);
        }
        if (phi_s4) {
            osSendMesg(D_global_asm_807655E0, 0x309, 1);
            phi_s4 = 0;
        }
        if (D_global_asm_8076A0B1 & 1 && D_global_asm_807FD888 == 31.0f) {
            D_global_asm_8076A0B2--;
        }
        D_global_asm_807444F0 = is_cutscene_active;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_450/func_global_asm_805FC2B0.s")

extern s32 *D_global_asm_8076A048;
extern s32 D_8076A150;
extern s32 D_global_asm_8076A088;
extern s32 D_global_asm_8076A08C;

/*
void func_global_asm_805FC2B0(void) {
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;
    s32 phi_v0;

    func_global_asm_8060A9BC();
    if (D_global_asm_8076A0A4 != 0) {
        phi_v0 = 0;
    } else {
        phi_v0 = 1;
    }
    //func_global_asm_80610044(((*0x807444FC * 4) + 0x80770000)->unk-5FB0, D_global_asm_8076A088, 3, phi_v0 & 0xFF, 0x4D2, 1);
    if (D_global_asm_8076A0A4 != 0) {
        //func_global_asm_80610044((D_global_asm_807444FC * 0x11B0) + 0xDB0 + &D_global_asm_80767CE8, D_global_asm_8076A08C, 0, 1, 0x929, 1);
    }
    D_global_asm_807444FC ^= 1;
    object_timer++;
    if ((global_properties_bitfield & 2) == 0) {
        D_global_asm_8076A068++;
    }
    *D_global_asm_8076A048 = (D_global_asm_807444FC * 0x11B0) + &D_global_asm_80767CE8;
    func_global_asm_8060AC7C();
    if (func_global_asm_805FC668() != 0) {
        func_global_asm_8065D1AC();
        func_global_asm_806789E4();
        func_global_asm_80715270(1);
        func_global_asm_80603450();
        func_global_asm_806057F8();
        func_global_asm_806025D4();
        func_global_asm_805FCA94(D_global_asm_8076A048);
    } else {
        func_global_asm_8065A648();
        func_global_asm_806787CC();
        func_global_asm_805FCA94(D_global_asm_8076A048);
        func_global_asm_8065D1AC();
        func_global_asm_8068A508();
        func_global_asm_8066CDD0();
        func_global_asm_8066CCD8();
        func_global_asm_80661054();
        func_global_asm_80678824();
        func_global_asm_80663A80();
        func_global_asm_80715270(0);
        func_global_asm_80603450();
        func_global_asm_806025D4();
        func_global_asm_806057F8();
        func_global_asm_806F6F28();
    }
    func_global_asm_8070DD44();
    temp_v0 = D_global_asm_8076A050[D_global_asm_807444FC];
    D_8076A150 = temp_v0;
    if (((D_global_asm_8076A0B1 & 1) != 0) && (D_global_asm_807FD888 == 31.0f)) {
        sp2C = temp_v0;
        sp28 = D_global_asm_8076A048 + 0xDB0;
        func_global_asm_8068C2EC();
    } else {
        func_global_asm_805FD088(D_global_asm_8076A048, &sp2C, &sp28);
    }
    if ((global_properties_bitfield & 0x100) != 0) {
        global_properties_bitfield &= ~0x100;
        func_global_asm_807094D0(2);
    } else if ((global_properties_bitfield & 0x200) != 0) {
        D_global_asm_80744504--;
        if (D_global_asm_80744504 == 0) {
            global_properties_bitfield &= ~0x200;
            func_global_asm_807094D0(3);
        }
    } else {
        sp2C = func_global_asm_80704484(sp2C, loading_zone_transition_type);
    }
    if ((D_global_asm_8076A0A4 != 0) && (is_cutscene_active != 6)) {
        func_global_asm_805FE71C(sp2C, D_global_asm_807444FC, &D_global_asm_8076A088, 0);
        func_global_asm_805FE7B4(sp28, D_global_asm_8076A048, &D_global_asm_8076A08C, 1);
        return;
    }
    func_global_asm_805FE71C(sp2C, D_global_asm_807444FC, &D_global_asm_8076A088, 1);
}
*/

// OSTime stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_450/func_global_asm_805FC668.s")

void func_global_asm_806FB2B8();
extern OSTime D_global_asm_807445B0;
extern OSTime D_global_asm_807445B8;
extern OSTime D_global_asm_807445C0;
extern s8 D_global_asm_807445C8;

/*
s32 func_global_asm_805FC668(void) {
    Actor *temp_v0;
    enum actors_e var_v0;
    OSTime temp_time;

    if ((current_map == MAP_MAIN_MENU) || ((func_global_asm_80714360() == 0) && (gameIsInAdventureMode() == 0) && (gameIsInMysteryMenuMinigameMode() == 0) && (gameIsInSnidesBonusGameMode() == 0))) {
        global_properties_bitfield &= ~1;
    }
    if (global_properties_bitfield & 2) {
        if ((global_properties_bitfield & 0x40) && ((gameIsInAdventureMode() != 0) || (gameIsInMysteryMenuMinigameMode() != 0))) {
            func_global_asm_80602B60(0x22, 0U);
            global_properties_bitfield &= 0xFFEBFFBD;
            if (((s32) cc_number_of_players < 2) && (gameIsInMysteryMenuMinigameMode() == 0)) {
                var_v0 = ACTOR_PAUSE_MENU;
            } else {
                var_v0 = ACTOR_PAUSE_MENU_MYSTERY_MENU;
            }
            temp_v0 = func_global_asm_8067ADB4(var_v0);
            if (temp_v0) {
                deleteActor(temp_v0);
            }
            D_global_asm_807445B0 = osGetTime() - D_global_asm_807445C0;
            func_global_asm_806FB2B8();
        }
    } else {
        D_global_asm_807445B8 += D_global_asm_807445B0;
        D_global_asm_807445C0 = 0;
        D_global_asm_807445B0 = 0;
        if (D_global_asm_807445C8 > 0) {
            if (!(global_properties_bitfield & 1)) {
                D_global_asm_807445C8 = 0;
            } else {
                if (--D_global_asm_807445C8 <= 0) {
                    if (((gameIsInAdventureMode() != 0) || (gameIsInMysteryMenuMinigameMode() != 0)) && !(global_properties_bitfield & 0x40000)) {
                        playSong(0x22, 1.0f);
                        playSong(0x29, 1.0f);
                        if ((cc_number_of_players < 2) && (gameIsInMysteryMenuMinigameMode() == 0)) {
                            spawnActor(ACTOR_PAUSE_MENU, 0);
                            global_properties_bitfield |= 0x100000;
                        } else {
                            spawnActor(ACTOR_PAUSE_MENU_MYSTERY_MENU, 0);
                        }
                        last_spawned_actor->unk64 |= 2;
                    }
                    D_global_asm_807445C0 = osGetTime();
                    global_properties_bitfield ^= 1;
                    global_properties_bitfield |= 2;
                }
            }
        }
        if ((global_properties_bitfield & 1) && (D_global_asm_807445C8 <= 0)) {
            func_global_asm_806FB290();
            D_global_asm_807445C8 = 2;
        }
    }
    return global_properties_bitfield & 2;
}
*/

extern OSTime D_global_asm_807445B8;
extern OSTime D_global_asm_807445C0;
extern u32 D_global_asm_80750AB0;

u32 func_global_asm_805FC98C(void) {
    OSTime sp18;
    OSTime temp_t8;
    u32 temp_t7;
    OSTime currentTime;

    currentTime = osGetTime();
    temp_t8 = (currentTime - D_global_asm_807445B8);
    if (global_properties_bitfield & 2) {
        temp_t8 = temp_t8 - currentTime + D_global_asm_807445C0;
    }
    return D_global_asm_80750AB0 + (u32)(temp_t8 * 64 / 3000 / 1000000);
}

u8 func_global_asm_805FCA64(void) { // getCutsceneBarState()
    return !(D_global_asm_8076A0B1 & 0x10) && !D_global_asm_8076A0B3;
}

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_450/func_global_asm_805FCA94.s")

extern f32 D_global_asm_807444CC;
extern f32 D_global_asm_807444D0;
extern f32 D_global_asm_807444D4;
extern f32 D_global_asm_807444D8;
extern f32 D_global_asm_807444DC;
extern f32 D_global_asm_807444E0;
extern s32 D_global_asm_807445CC;
extern u8 D_global_asm_80750AB4;
extern u8 D_global_asm_80750AB8;
extern u16 D_global_asm_8076A09C;

typedef struct Struct805FD088 {
    Mtx unk0;
    Mtx unk40;
    Mtx unk80;
    Mtx unkC0;
    Mtx unk100;
    Mtx unk140;
    Mtx unk180;
    Mtx unk1C0;
    Mtx unk200;
    u8 pad240[0xDB0 - 0x240];
    Gfx dl[];
} Struct805FD088;

/*
void func_global_asm_805FCA94(Struct805FD088 *arg0) {
    s32 pad[4];
    f32 var_f6;
    f32 var_f20; // AC
    f32 fov; // A8;
    f32 offset; // A4
    s32 i;
    CameraPaad *camera_aad;
    CharacterChange *cc;
    PlayerAdditionalActorData *player_aad;
    f32 temp0;

    fov = func_global_asm_8062A850();
    if ((cc_number_of_players > 1) && (D_global_asm_80750AB8 == 1)) {
        temp0 = func_global_asm_806276AC();
        func_global_asm_8062754C(temp0);
    }
    for (i = 0; i < D_global_asm_80750AB4; i++) {
        cc = &character_change_array[i];
        if (cc->does_player_exist) {
            if (ABS(cc->look_at_eye_x - cc->look_at_at_x) < 0.5) {
                offset = 0.0f;
                if (ABS(cc->look_at_eye_z - cc->look_at_at_z) < 0.5) {
                    offset = 1.0f;
                }
            } else {
                offset = 0.0f;
            }
            guLookAtHilite(
                &cc->unk8[D_global_asm_807444FC],
                &cc->unk190[D_global_asm_807444FC],
                &cc->unk1D0[D_global_asm_807444FC],
                cc->look_at_eye_x + offset,
                cc->look_at_eye_y,
                cc->look_at_eye_z + offset,
                cc->look_at_at_x,
                cc->look_at_at_y,
                cc->look_at_at_z,
                cc->look_at_up_x,
                cc->look_at_up_y,
                cc->look_at_up_z,
                D_global_asm_807444CC,
                D_global_asm_807444D0,
                D_global_asm_807444D4,
                D_global_asm_807444D8,
                D_global_asm_807444DC,
                D_global_asm_807444E0, 0x20, 0x20);
            var_f20 = character_change_array[i].unk280;
            player_aad = character_change_array[i].player_pointer->PaaD;
            camera_aad = player_aad->unk104->CaaD;
            if (player_aad->unk1F0 & 0x100) {
                var_f20 += 0.5 * func_global_asm_80612D1C(D_global_asm_807445CC * 0.1);
            } else if (player_aad->unk1F0 & 0x02000000) {
                var_f20 += 0.05 * func_global_asm_80612D1C(D_global_asm_807445CC * 0.4);
            } else if ((camera_aad->unkFA) && (character_change_array[i].unk220 < (camera_aad->unk90 + 3.0f))) {
                var_f20 += 0.04 * func_global_asm_80612D1C(D_global_asm_807445CC * 0.1);
            }
            guPerspective(
                &character_change_array[i].unk88[D_global_asm_807444FC],
                &character_change_array[i].unk188,
                character_change_array[i].fov_y,
                var_f20 * fov,
                character_change_array[i].near, character_change_array[i].far, 1.0f);
        }
    }
    if (ABS(character_change_array[0].look_at_eye_x - character_change_array[0].look_at_at_x) < 0.5) {
        if (ABS(character_change_array[0].look_at_eye_z - character_change_array[0].look_at_at_z) < 0.5) {
            offset = 1.0f;
        } else {
            offset = 0.0f;
        }
    } else {
        offset = 0.0f;
    }
    guPerspective(
        arg0,
        &D_global_asm_8076A09C,
        character_change_array[0].fov_y,
        var_f20 * fov,
        character_change_array[0].near,
        character_change_array[0].far,
        1.0f);
    guLookAt(&arg0->unk200,
        character_change_array[0].look_at_eye_x + offset, 
        character_change_array[0].look_at_eye_y, 
        character_change_array[0].look_at_eye_z + offset, 
        character_change_array[0].look_at_at_x, 
        character_change_array[0].look_at_at_y, 
        character_change_array[0].look_at_at_z, 
        character_change_array[0].look_at_up_x, 
        character_change_array[0].look_at_up_y, 
        character_change_array[0].look_at_up_z);
    D_global_asm_807445CC++;
}
*/

Gfx *func_global_asm_805FCFD8(Gfx *dl) {
    if (D_global_asm_8074450C == 2) {
        gSPDisplayList(dl++, &D_1000068);
    } else {
        gSPDisplayList(dl++, &D_1000040);
    }
    return dl++;
}

Gfx *func_global_asm_805FD030(Gfx *dl) {
    if (D_global_asm_8074450C == 2) {
        gSPDisplayList(dl++, &D_1000030);
    } else {
        gSPDisplayList(dl++, &D_1000020);
    }
    return dl++;
}

Gfx *func_global_asm_8062BF24(Gfx *, s32);
Gfx *func_global_asm_8068C20C(Gfx *, u8);
Struct80750948 *func_global_asm_806C7C94(u8);
Gfx *func_global_asm_807007B8(Gfx *);
Gfx *func_global_asm_80701CA0(Gfx *);
Gfx *func_global_asm_80704960(Gfx *);
Gfx *func_global_asm_80714060(Gfx *);
extern u8 D_global_asm_8074447C;
extern u8 D_global_asm_80744480;
extern u8 D_global_asm_80744484;
extern u8 D_global_asm_80744488;
extern u8 D_global_asm_8074448C;
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern s16 D_global_asm_80744498;
extern s16 D_global_asm_8074449C;
extern s16 D_global_asm_807444A0;
extern s16 D_global_asm_807444A4;
extern s16 D_global_asm_807444A8;
extern s16 D_global_asm_807444AC;
extern s16 D_global_asm_807444B0;
extern s16 D_global_asm_807444B4;
extern f32 D_global_asm_807444B8;
extern f32 D_global_asm_807444BC;
extern f32 D_global_asm_807444C4;
extern f32 D_global_asm_807444C8;
extern u8 D_global_asm_807467E4;
extern u8 D_global_asm_80750AB8;
extern void *D_8076A060;
extern u16 D_global_asm_8076A09C;
extern u8 D_global_asm_8076A0B1;
extern u8 D_global_asm_8076A0B3;

void func_global_asm_805FD088(Struct805FD088 *arg0, Gfx **arg1, Gfx **arg2) {
    Gfx *dl; // 114
    Gfx *dl_0;

    dl = D_global_asm_8076A050[D_global_asm_807444FC];
    dl_0 = &arg0->dl[0];
    gSPPerspNormalize(dl_0++, D_global_asm_8076A09C);
    gSPClipRatio(dl_0++, FRUSTRATIO_3);
    gSPSegment(dl++, 0x00, 0x00000000);
    gSPSegment(dl++, 0x02, osVirtualToPhysical(arg0));
    gSPSegment(dl++, 0x01, osVirtualToPhysical(D_global_asm_8076A080));
    gSPSegment(dl_0++, 0x00, 0x00000000);
    gSPSegment(dl_0++, 0x02, osVirtualToPhysical(arg0));
    gSPSegment(dl_0++, 0x01, osVirtualToPhysical(D_global_asm_8076A080));
    gSPDisplayList(dl++, &D_1000090);
    gSPDisplayList(dl_0++, &D_1000090);
    {
    f32 temp_f0;
    f32 temp0;
    f32 temp_f2;
    u32 vf;
    s16 n, d;
    Struct80750948 *temp_v0_6;
    s16 x, y;
    dl = func_global_asm_805FCFD8(dl);
    dl_0 = func_global_asm_805FCFD8(dl_0);
    gDPSetScissorFrac(dl++, G_SC_NON_INTERLACE, 0, 0, D_global_asm_80744490 * 4.0f, D_global_asm_80744494 * 4.0f);
    gDPSetScissorFrac(dl_0++, G_SC_NON_INTERLACE, 0, 0, D_global_asm_80744490 * 4.0f, D_global_asm_80744494 * 4.0f);
    guTranslate(&arg0->unk180, 0.0f, 0.0f, 0.0f);
    guOrtho(&arg0->unk80, 0.0f, (f32) D_global_asm_80744490 - 1.0, (f32) D_global_asm_80744494 - 1.0, 0.0f, -20000.0f, 20000.0f, 1.0f);
    guOrtho(&arg0->unkC0, 0.0f, (f32) D_global_asm_80744490 * 4.0 - 1.0, (f32) D_global_asm_80744494 * 4.0 - 1.0, 0.0f, -20000.0f, 20000.0f, 1.0f);
    guOrtho(&arg0->unk140, 0.0f, 2.0 * (f32) D_global_asm_80744490 - 1.0, 2.0 * (f32) D_global_asm_80744494 - 1.0, 0.0f, -20000.0f, 20000.0f, 1.0f);
    guOrtho(&arg0->unk100, (f32) character_change_array->unk270[0] * 4.0, (f32) character_change_array->unk270[2] * 4.0 - 1.0, (f32) character_change_array->unk270[3] * 4.0 - 1.0, (f32) character_change_array->unk270[1] * 4.0, -20000.0f, 20000.0f, 1.0f);
    temp0 = func_global_asm_8062A850();
    guPerspective(arg0, &D_global_asm_8076A09C, D_global_asm_807444B8, temp0 * D_global_asm_807444BC, D_global_asm_807444C8, D_global_asm_807444C4, 1.0f);
    gSPMatrix(dl_0++, &D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl_0++, &D_2000200, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(dl_0++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    dl_0 = func_global_asm_805FD030(dl_0);
    dl = func_global_asm_805FE398(dl);
    gDPPipeSync(dl++);
    dl = func_global_asm_805FE4D4(dl);
    gDPSetColorDither(dl++, G_CD_MAGICSQ);
    gDPSetAlphaDither(dl++, G_AD_PATTERN);
    dl = func_global_asm_80704960(dl);
    gSPClipRatio(dl++, FRUSTRATIO_3);
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA)
    gSPSetGeometryMode(dl++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    dl = func_global_asm_8062BF24(dl, arg0);
    dl = func_global_asm_80701CA0(dl);
    if (cc_number_of_players == 1) {
        dl = func_global_asm_807007B8(dl);
    }
    dl = func_global_asm_8068C20C(dl, 1);
    dl = func_global_asm_80629300(dl);
    dl = func_global_asm_8062A844(dl);
    if ((current_map == MAP_DK_RAP) || (current_map == MAP_MAIN_MENU) || ((func_global_asm_80714464() != 0) && (current_map != MAP_BLOOPERS_ENDING))) {
        D_global_asm_8076A0B1 &= 0xFFEF;
        D_global_asm_8076A0B3 = 0;
    }
    if (((D_global_asm_8076A0B1 & 0x10) || (D_global_asm_8076A0B3 != 0)) && ((cc_number_of_players == 1) || (D_global_asm_80750AB8 == 1))) {
        gDPPipeSync(dl++);
        gDPSetCycleType(dl++, G_CYC_FILL);
        gDPSetRenderMode(dl++, G_RM_NOOP, G_RM_NOOP2);
        gSPClearGeometryMode(dl++, G_ZBUFFER);
        gDPSetFillColor(dl++, 0x00010001);
        gDPSetScissorFrac(dl++, G_SC_NON_INTERLACE,
            D_global_asm_80744498 * 4.0f,
            D_global_asm_8074449C * 4.0f,
            D_global_asm_807444A0 * 4.0f,
            D_global_asm_807444A4 * 4.0f);

        if (D_global_asm_8076A0B3) {
            D_global_asm_8076A0B3 -= 0xF;
            temp_f2 = (1.0 - (D_global_asm_8076A0B3 / 255.0));
            temp_f0 = (D_global_asm_807444AC - D_global_asm_807444A8) * temp_f2;
            gDPFillRectangle(dl++,
                0,
                MAX(D_global_asm_807444A8 - temp_f0, 0.0f),
                MAX(D_global_asm_80744490, 0),
                MAX(D_global_asm_807444AC - temp_f0, 0.0f));
            gDPFillRectangle(dl++, 0,
                D_global_asm_807444B0 + temp_f0,
                D_global_asm_80744490,
                D_global_asm_807444B4 + temp_f0);
            character_change_array->unk270[1] = D_global_asm_807444AC - temp_f0;
            character_change_array->unk270[3] = D_global_asm_807444B0 + temp_f0;
        } else {
            gDPFillRectangle(dl++, 0, D_global_asm_807444A8, D_global_asm_80744490, D_global_asm_807444AC);
            gDPFillRectangle(dl++, 0, D_global_asm_807444B0, D_global_asm_80744490, D_global_asm_807444B4);
            character_change_array->unk270[1] = D_global_asm_807444AC;
            character_change_array->unk270[3] = D_global_asm_807444B0;
        }
        character_change_array->unk27A = character_change_array->unk270[3] - character_change_array->unk270[1];
        character_change_array->unk280 = (f32) character_change_array->unk278 / (f32) character_change_array->unk27A;
        gDPPipeSync(dl++);
        gDPSetRenderMode(dl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    }
    if ((D_global_asm_8074447C) || (D_global_asm_80744480) || (D_global_asm_80744484) || (D_global_asm_80744488) || (D_global_asm_8074448C)) {
        temp_v0_6 = func_global_asm_806C7C94(0);
        character_change_array->unk270[0] = temp_v0_6->unk4 + D_global_asm_8074447C;
        character_change_array->unk270[2] = temp_v0_6->unk8 - D_global_asm_80744480;
        character_change_array->unk270[1] = temp_v0_6->unk6 + D_global_asm_80744484;
        character_change_array->unk270[3] = temp_v0_6->unkA - D_global_asm_80744488;
        gDPPipeSync(dl++);
        gDPSetCycleType(dl++, G_CYC_FILL);
        gDPSetRenderMode(dl++, G_RM_NOOP, G_RM_NOOP2);
        gSPClearGeometryMode(dl++, G_ZBUFFER);
        gDPSetFillColor(dl++, 0x00010001);
        gDPSetScissorFrac(dl++, 
            G_SC_NON_INTERLACE,
            D_global_asm_80744498 * 4.0f,
            D_global_asm_8074449C * 4.0f,
            D_global_asm_807444A0 * 4.0f,
            D_global_asm_807444A4 * 4.0f);
        if (D_global_asm_8074447C) {
            gDPFillRectangle(dl++,
                temp_v0_6->unk4, 
                temp_v0_6->unk6, 
                character_change_array->unk270[0], 
                temp_v0_6->unkA);
        }
        if (D_global_asm_80744480) {
            gDPFillRectangle(dl++, 
            character_change_array->unk270[2], 
            temp_v0_6->unk6, 
            temp_v0_6->unk8, 
            temp_v0_6->unkA);
        }
        if (D_global_asm_80744484) {
            gDPFillRectangle(dl++, 
            character_change_array->unk270[0], 
            temp_v0_6->unk6, 
            character_change_array->unk270[2], 
            character_change_array->unk270[1]);
        }
        if (D_global_asm_80744488) {
            gDPFillRectangle(dl++, 
            character_change_array->unk270[0], 
            character_change_array->unk270[3], 
            character_change_array->unk270[2], 
            temp_v0_6->unkA);
        }
        gDPPipeSync(dl++);
        character_change_array->unk278 = character_change_array->unk270[2] - character_change_array->unk270[0];
        character_change_array->unk27A = character_change_array->unk270[3] - character_change_array->unk270[1];
        if (
            (!D_global_asm_8074447C) &&
            (!D_global_asm_80744480) && 
            (!D_global_asm_80744484) && 
            (!D_global_asm_80744488)) {
            D_global_asm_8074448C = 0;
        } else {
            D_global_asm_8074448C = 1;
        }
        D_global_asm_8074447C = 0;
        D_global_asm_80744480 = 0;
        D_global_asm_80744484 = 0;
        D_global_asm_80744488 = 0;
        n = temp_v0_6->unk8 - temp_v0_6->unk4;
        d = temp_v0_6->unkA - temp_v0_6->unk6;
        character_change_array->unk280 = (f32)(n) / (f32)(d);
        gDPSetRenderMode(dl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    }
    dl = func_global_asm_805FD030(dl);
    dl = func_global_asm_8068C20C(dl, 3);
    dl = func_global_asm_8062CA0C(dl, character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z);
    dl = func_global_asm_8068C20C(dl, 5);
    dl = func_global_asm_8068C20C(dl, 7);
    if (D_global_asm_807467E4) {
        D_global_asm_807467E4--;
    }
    dl = func_global_asm_80709344(dl);
    dl = func_global_asm_806FAB20(dl);
    dl = func_global_asm_80714060(dl);
    func_global_asm_806FBC34();
    func_global_asm_8068C0B4();
    func_global_asm_80722280();
    *arg1 = dl;
    *arg2 = dl_0;
    }
}

Gfx *func_global_asm_805FE398(Gfx *dl) {
    gDPPipeSync(dl++);
    gDPSetRenderMode(dl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(dl++, G_CYC_FILL);
    gSPClearGeometryMode(dl++, G_ZBUFFER);
    gDPSetDepthImage(dl++, osVirtualToPhysical(D_8076A060));
    gDPSetColorImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_global_asm_80744490, osVirtualToPhysical(D_8076A060));
    gDPSetFillColor(dl++, 0xFFFCFFFC);
    gDPFillRectangle(dl++, 0, 0, D_global_asm_80744490 - 1, D_global_asm_80744494 - 1);
    gDPPipeSync(dl++);
    return dl;
}

Gfx *func_global_asm_805FE4D4(Gfx *dl) {
    gDPSetColorImage(dl++, 0, 2, D_global_asm_80744490, osVirtualToPhysical(D_global_asm_80744470[D_global_asm_807444FC]));
    return dl;
}

void func_global_asm_805FE544(u8 arg0) {
    if (D_global_asm_807FBB64 & 1) {
        D_global_asm_8076A058 = 6000;
    } else {
        D_global_asm_8076A058 = arg0 * 3000;
    }
    D_global_asm_8076A050[0] = malloc(D_global_asm_8076A058 * sizeof(Gfx));
    D_global_asm_8076A050[1] = malloc(D_global_asm_8076A058 * sizeof(Gfx));
    func_global_asm_805FE71C(func_global_asm_805FE634(D_global_asm_8076A050[0], 0), 0, &D_global_asm_8076A088, 1);
    func_global_asm_805FE71C(func_global_asm_805FE634(D_global_asm_8076A050[1], 1), 1, &D_global_asm_8076A088, 1);
}

Gfx *func_global_asm_805FE634(Gfx *dl, u8 arg1) {
    gDPPipeSync(dl++);
    gDPSetRenderMode(dl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(dl++, G_CYC_FILL);
    gDPSetColorImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_global_asm_80744490, D_global_asm_80744470[arg1]);
    gDPSetFillColor(dl++, 0x00010001);
    gDPPipeSync(dl++);
    gDPFillRectangle(dl++, 0, 0, D_global_asm_80744490 - 1, D_global_asm_80744494 - 1);
    return dl;
}

void func_global_asm_805FE71C(Gfx *dl, u8 arg1, s32 *arg2, u8 arg3) {
    Gfx *dl2 = dl;
    if (arg3) {
        gDPFullSync(dl2++);
    }
    gSPEndDisplayList(dl2++);
    *arg2 = (dl2 - D_global_asm_8076A050[arg1]);
    if (*arg2 >= D_global_asm_8076A058) {
        raiseException(0x12, 0, 0, 0);
    }
}

void func_global_asm_805FE7B4(Gfx *dl, Gfx *arg1, s32 *arg2, u8 arg3) {
    Gfx *dl2;

    dl2 = dl;
    if (arg3) {
        gDPFullSync(dl2++);
    }
    gSPEndDisplayList(dl2++);
    *arg2 = (((dl2 - 0x1B6) - arg1));
}

void func_global_asm_805FE7FC(void) {
    s32 *mapGeometry;
    void *sp28;
    s32 *mapSetup;
    f32 phi_f0;
    Maps map;
    u8 player_count;

    D_global_asm_80746830 = 1;
    D_global_asm_8076A090 = 0;
    D_global_asm_8076A094 = 0;
    D_global_asm_8076A098 = 0;
    global_properties_bitfield &= 0xFFEB3FFC;
    func_global_asm_80712A40();
    D_global_asm_80750AC4 = 0;
    D_global_asm_8076A0A4 = 0;
    D_global_asm_807444FC = 0;
    object_timer = 0;
    D_global_asm_8076A068 = 0;
    func_global_asm_80605510();
    enemies_killed = 0;
    *D_global_asm_807ECDF4 = 0;
    func_global_asm_8068C080();
    D_global_asm_8076A0B1 &= 0xFFCF;
    func_global_asm_8070F570();
    if (is_cutscene_active == 1) {
        is_cutscene_active = 0;
    }
    D_global_asm_8076A06C = object_timer;
    D_global_asm_80744500 = 0;
    func_global_asm_80600950();
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

    func_global_asm_805FB944(1);
    if (D_global_asm_80750AC0 > 1) {
        if (!(D_global_asm_807FBB64 & 0x4000000)) {
            D_global_asm_80750AC0 = 1;
        }
    }
    func_global_asm_806C7C10();
    func_global_asm_806D0430(0.0f);
    func_global_asm_805FE544(D_global_asm_80750AC0);

    if (current_map != MAP_ENGUARDE_ARENA) {
        if (current_map == MAP_RAMBI_ARENA) {
            current_character_index[0] = 6;
        }
    } else {
        current_character_index[0] = 7;
    }

    D_global_asm_807F6010 = 0;
    func_global_asm_8066ADA0();
    func_global_asm_806FBB58();
    func_global_asm_806FD9A0();
    func_global_asm_807040E0(0xFF, 0xFF, 0xFF);
    func_global_asm_80704108(0xFF, 0xFF, 0xFF);
    if (!is_cutscene_active) {
        D_global_asm_8076A0A0 = getPointerTableFile(0x13, MAP_TEST_MAP, 1, 1);
        func_global_asm_80705B30();
        func_global_asm_807215EC();
        func_global_asm_806F3760(current_map); // Load autowalk file
        func_global_asm_8072ED90();
        func_global_asm_80658BD0();
        func_global_asm_80722E00(current_map); // Load path file
        mapGeometry = getPointerTableFile(1, current_map, 1, 1);
        func_global_asm_80630300();
        func_global_asm_80650E20(mapGeometry);
        func_global_asm_8062F050(mapGeometry);
        loadExits(current_map);
        func_global_asm_8065D170();
        func_global_asm_806588E0(current_map); // Load per map file, pointer table 20
        func_global_asm_80688940();
        func_global_asm_80631C3C();
        func_global_asm_8063643C();
        mapSetup = getPointerTableFile(9, current_map, 1, 1);
        func_global_asm_80631FAC(current_map, 1);
        func_global_asm_806886E0(mapSetup, 0, 0);
        func_global_asm_80663DA0();
        func_global_asm_8065A570();
        func_global_asm_80677D80();
        func_global_asm_8068A7B0(); // spawnPersistentActors()
        func_global_asm_8072E740(current_map);
        func_global_asm_80626264(sp28 = getPointerTableFile(8, current_map, 1, 1));
        if (sp28) {
            func_global_asm_8066B434(sp28, 0x8D0, 2);
        }
        func_global_asm_80712B80();
        func_global_asm_806C7D40(next_exit);
        func_global_asm_80714670();
        sp28 = getPointerTableFile(0x10, current_map, 1, 1);
        func_global_asm_80724C78(sp28);
        if (sp28) {
            func_global_asm_8066B434(sp28, 0x8DD, 2);
        }
        func_global_asm_8061EA78();
        func_global_asm_8068C2EC();
        func_global_asm_806F4778();
        func_global_asm_8070E8C8();
        func_global_asm_8060098C(func_global_asm_806025AC, 2, 0, 0, 0);
        if (D_global_asm_807FBB64 & 0x1000) {
            sp28 = getPointerTableFile(0x16, current_map, 1, 1);
            func_critter_80026FD0(sp28);
            if (sp28) {
                func_global_asm_8066B434(sp28, 0x8ED, 2);
            }
        }
        if (D_global_asm_807FBB64 & 0x2000) {
            setupRaceOnMapLoad(current_map);
        }
        func_global_asm_8066BDE0();
        D_global_asm_807F6008 = 0;
        if (!isIntroStoryPlaying() && is_cutscene_active != 2) {
            if (current_map == MAP_HELM && isFlagSet(0x302, FLAG_TYPE_PERMANENT)) {
                playSong(0x74, 1.0f);
            } else {
                phi_f0 = 1.0f;
                if (D_global_asm_80745BDC[current_map * 4] == 6 || D_global_asm_80745BDC[current_map * 4] == 0x1F) {
                    phi_f0 = 0.549333155155f;
                }
                playSong(D_global_asm_80745BDC[current_map * 4], phi_f0);
            }
        }
        if (current_map == MAP_DK_ISLES_OVERWORLD || current_map == MAP_ENGUARDE_ARENA) {
            playSong(0x60, 1.0f);
        }
        func_global_asm_8060A4D0(0, 1.0f);
        func_global_asm_8060A4D0(1, 1.0f);
        func_global_asm_8060A4D0(2, 1.0f);
        func_global_asm_805FFEF8(current_map);
        func_global_asm_806641A0();
    }
    func_global_asm_80712BD4();
    func_global_asm_805FF670();
    D_global_asm_8076A0B1 ^= 1;
    D_global_asm_807FD888 = 31.0f;
    D_global_asm_8076A0B1 |= 4;
    loading_zone_transition_speed = -1.0f;
    if (D_global_asm_807444F8 != 2 && loading_zone_transition_type == 1) {
        playSong(0x2B, 1.0f);
    }
    func_global_asm_80701C90();
    func_global_asm_80629190();
    func_global_asm_80664CB0(D_global_asm_8076A0AA);
    func_global_asm_80600590(current_map);
    D_global_asm_80746830 = 0;
}

void func_global_asm_805FEE84(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_global_asm_8074447C = arg0;
    D_global_asm_80744480 = arg1;
    D_global_asm_80744484 = arg2;
    D_global_asm_80744488 = arg3;
}

void func_global_asm_805FEEB8(s32 *arg0, s32 arg1) {
    s32 temp_hi;

    temp_hi = *arg0 % arg1;
    if (temp_hi) {
        *arg0 += arg1 - temp_hi;
    }
}
