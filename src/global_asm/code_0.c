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
extern OSMesgQueue D_global_asm_807655F0;
extern OSMesg D_global_asm_80765608;

extern OSMesgQueue D_global_asm_807656D0;
extern OSMesg D_global_asm_807656E8;

extern OSMesgQueue D_global_asm_807659E8;
extern OSMesg D_global_asm_80765A00;

extern OSMesg D_global_asm_8076A108;
extern OSMesg D_global_asm_8076A128;
extern OSTimer D_global_asm_8076A130;

f32 func_global_asm_8062A850(void);
void func_global_asm_8060B140(s32, s32*, s32*, s32, s32, s32, s32);
void func_global_asm_8060AA04();
void func_global_asm_80631B80();
void func_global_asm_806C9AE0();
void func_global_asm_80731030(); // clearTemporaryFlags()
void func_global_asm_805FF118();
void func_global_asm_8063DB0C();

void func_global_asm_80712A40(void);
void func_global_asm_80605510(void);
void func_global_asm_8068C080(void);
void func_global_asm_8070F570(void);
void func_global_asm_80600950(void);

void func_global_asm_8060A4D0(s32 arg0, f32 arg1);

void func_global_asm_8066ADA0(void);
void func_global_asm_806FBB58(void);
void func_global_asm_806FD9A0(void);

void func_global_asm_80705B30();
void func_global_asm_807215EC();
void func_global_asm_8072ED90();
void func_global_asm_80658BD0();

void func_global_asm_80630300();
void func_global_asm_80650E20(s32* arg0);
void func_global_asm_8062F050(s32* arg0);
void func_global_asm_8065D170();
void func_global_asm_806588E0(s32 arg0);
void func_global_asm_80688940();
void func_global_asm_80631C3C();
void func_global_asm_8063643C();

void func_global_asm_806C7C10(void);
void func_global_asm_806D0430(f32 arg0);
void func_global_asm_805FE544(u8 arg0);

void func_global_asm_80631FAC(Maps arg0, s32 arg1);
void func_global_asm_806886E0(s32* arg0, s32 arg1, s32 arg2);
void func_global_asm_80663DA0();
void func_global_asm_8065A570();
void func_global_asm_80677D80();
void func_global_asm_8068A7B0();

void func_global_asm_80626264(void*);
void func_global_asm_80712B80();
void func_global_asm_806C7D40(s32 arg0);
void func_global_asm_80714670();

void func_global_asm_80724C78(void* arg0);
void func_global_asm_8061EA78();
void func_global_asm_806F4778();
void func_global_asm_8070E8C8();
void func_global_asm_8060098C(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_critter_80026FD0(s32 arg0);
void setupRaceOnMapLoad(Maps map);

void func_global_asm_8066BDE0(void);

void func_global_asm_80701C90(void);
void func_global_asm_80629190(void);
void func_global_asm_80600590(s32 arg0);

void func_global_asm_806641A0();

void func_global_asm_80712BD4();
void func_global_asm_805FF670();
void func_global_asm_805FB944(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FB300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FB5C4.s")

void func_global_asm_805FB750(s32 arg0, s32 arg1, void* arg2) {
    s32 sp2C;

    sp2C = D_dk64_boot_8000DDCC;
    osWritebackDCache(arg2, arg1);
    osPiStartDma(&D_global_asm_807ECE00, 0, 0, sp2C + arg0, arg2, arg1, &D_global_asm_807655F0);
    osRecvMesg(&D_global_asm_807655F0, 0, 1);
    osInvalDCache(arg2, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FB7E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FB944.s")

void func_global_asm_805FB7E4();
void func_global_asm_80610350(u8, u8);
extern OSViMode *D_dk64_boot_8000EF20[];
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
extern s8 D_global_asm_80744510;
extern s32 D_global_asm_80744584[][2];
extern s8 D_global_asm_807445A0;
extern s8 D_global_asm_807445A4;
extern s16 D_global_asm_80744490;

/*
void func_global_asm_805FB944(u8 arg0) {
    s32 sp18;
    s16 temp_v1;
    s32 temp_v0;
    s32 temp_a0;
    s32 var_a2;
    u8 var_a1 = 1;

    sp18 = 0;
    func_global_asm_806003EC(D_global_asm_8076A0AA);
    var_a2 = sp18;
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
        temp_v0 = D_global_asm_8074450C;
        temp_v1 = temp_v0 * 0xA;
        D_global_asm_80744498 = temp_v1;
        D_global_asm_8074449C = temp_v1;
        D_global_asm_807444A0 = (temp_v0 * 0x136) - 1;
        D_global_asm_807444A4 = (temp_v0 * 0xE6) - 1;
        break;
    }
    func_global_asm_80610350(arg0, var_a1);
    if (D_global_asm_807445A4 == 0) {
        osViSetMode(&D_dk64_boot_8000EF20[D_global_asm_80744584[osTvType][D_global_asm_8074450C]]);
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
    temp_a0 = D_global_asm_8074450C * 0x1E;
    D_global_asm_807444AC = D_global_asm_8074449C + temp_a0;
    D_global_asm_807444B0 = D_global_asm_807444A4 - temp_a0;
    D_global_asm_807444A8 = D_global_asm_8074449C;
    D_global_asm_807444B4 = D_global_asm_807444A4;
}
*/

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FBC5C.s")

extern s32 D_global_asm_8076A07C;
extern OSMesgQueue D_global_asm_8076A110;

extern s32 D_global_asm_80767CD8;

typedef struct {
    u8 *unk0;
    u8 *unk4;
    u8 pad8[0x10];
} dk64_boot_struct_0;
extern dk64_boot_struct_0 D_dk64_boot_8000DCC4[];

void func_global_asm_8060EC80(OSMesgQueue *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4);

/*
// TODO: Pretty close
void func_global_asm_805FBC5C(void) {
    D_global_asm_8076A084 = D_dk64_boot_8000DCC4[12].unk4 - D_dk64_boot_8000DCC4[12].unk0;
    osCreateMesgQueue(&D_global_asm_807655F0, &D_global_asm_80765608, 0x32);
    osCreateMesgQueue(&D_global_asm_807656D0, &D_global_asm_807656E8, 0xC0);
    func_global_asm_8060EC80(&D_global_asm_80767A40, &D_global_asm_80767A40, 0x19, osTvType, 1);
    osCreateMesgQueue(&D_global_asm_807659E8, &D_global_asm_80765A00, 0x10);
    func_global_asm_8060ED6C(&D_global_asm_80767A40, &D_global_asm_80767CD8, &D_global_asm_807659E8, 1, 1);
    current_map = next_map;
    func_global_asm_805FB944(0);
    D_global_asm_8076A07C = 5;
    func_global_asm_8060FFF0();
    func_global_asm_8060A900();
    func_global_asm_80600D50();
    setIntroStoryPlaying(0);
    func_global_asm_8073239C();
    osWriteBackDCacheAll();
    osCreateMesgQueue(&D_global_asm_8076A110, &D_global_asm_8076A108, 2);
    osSetTimer(&D_global_asm_8076A130, 0, 0xD693A4, &D_global_asm_8076A110, D_global_asm_8076A128);
    playSound(0x23C, 0x7FFF, 63.0f, 1.0f, 0, 0);
}
*/

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FBFF4.s")

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
// TODO: Remarkably close, just missing some NOPs
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
            func_global_asm_80732354(2, 0, 0, 0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FC2B0.s")

extern s32 *D_global_asm_8076A048;
extern void* D_global_asm_8076A050[];
extern s32 D_global_asm_8076A150;
extern s32 D_global_asm_8076A088;
extern s32 D_global_asm_8076A08C;
void func_global_asm_8068C2EC();

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
    temp_v0 = *(&D_global_asm_8076A050 + (D_global_asm_807444FC * 4));
    //temp_v0 = D_global_asm_8076A050[D_global_asm_807444FC * 4];
    D_global_asm_8076A150 = temp_v0;
    if (((D_global_asm_8076A0B1 & 1) != 0) && (D_global_asm_807FD888 == 31.0f)) {
        sp2C = temp_v0;
        sp28 = D_global_asm_8076A048 + 0xDB0;
        func_global_asm_8068C2EC();
    } else {
        func_global_asm_805FD088(D_global_asm_8076A048, &sp2C, &sp28);
    }
    if ((global_properties_bitfield & 0x100) != 0) {
        global_properties_bitfield &= ~0x100;
        func_global_asm_807094D0(2, &global_properties_bitfield);
    } else if ((global_properties_bitfield & 0x200) != 0) {
        D_global_asm_80744504--;
        if (D_global_asm_80744504 == 0) {
            global_properties_bitfield &= ~0x200;
            func_global_asm_807094D0(3, &global_properties_bitfield);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FC668.s")

// regalloc, rodata?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FC98C.s")

u64 func_dk64_boot_80005818(u64, u64);
u64 func_dk64_boot_80005918(OSTime, u64);
extern OSTime D_global_asm_807445B8;
extern OSTime D_global_asm_807445C0;
extern u32 D_global_asm_80750AB0;

/*
s32 func_global_asm_805FC98C(void) {
    OSTime sp18;
    OSTime temp_t8;
    u32 temp_t7;
    OSTime currentTime;

    currentTime = osGetTime();
    temp_t8 = (currentTime - D_global_asm_807445B8);
    if (global_properties_bitfield & 2) {
        temp_t8 = temp_t8 - currentTime + D_global_asm_807445C0;
    }
    return func_dk64_boot_80005818(func_dk64_boot_80005818(func_dk64_boot_80005918(temp_t8, 0x40), 3000), 1000000) + D_global_asm_80750AB0;
}
*/

u8 func_global_asm_805FCA64(void) { // getCutsceneBarState()
    return !(D_global_asm_8076A0B1 & 0x10) && !D_global_asm_8076A0B3;
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FCA94.s")

void *func_global_asm_805FCFD8(Gfx *arg0) {
    if (D_global_asm_8074450C == 2) {
        gSPDisplayList(arg0++, &D_1000068);
    } else {
        gSPDisplayList(arg0++, &D_1000040);
    }
    return arg0++;
}

void *func_global_asm_805FD030(Gfx *arg0) {
    if (D_global_asm_8074450C == 2) {
        gSPDisplayList(arg0++, &D_1000030);
    } else {
        gSPDisplayList(arg0++, &D_1000020);
    }
    return arg0++;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FD088.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FE398.s")

extern s32 D_global_asm_80744470[];
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
Gfx *func_global_asm_805FE634(Gfx *dl, u8 arg1);

Gfx *func_global_asm_805FE4D4(Gfx *arg0) {
    gDPSetColorImage(arg0++, 0, 2, D_global_asm_80744490, osVirtualToPhysical(D_global_asm_80744470[D_global_asm_807444FC]));
    return arg0;
}

void func_global_asm_805FE544(u8 arg0) {
    if (D_global_asm_807FBB64 & 1) {
        D_global_asm_8076A058 = 6000;
    } else {
        D_global_asm_8076A058 = arg0 * 3000;
    }
    D_global_asm_8076A050[0] = (void*)malloc(D_global_asm_8076A058 * 8);
    D_global_asm_8076A050[1] = (void*)malloc(D_global_asm_8076A058 * 8);
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

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FE71C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FE7B4.s")

/*
void func_global_asm_805FE7B4(Gfx *arg0, s32 arg1, s32 *arg2, u8 arg3) {
    void *var_v0;

    var_v0 = arg0;
    if (arg3) {
        gSPSetGeometryMode(arg0++, 0);
    }
    gSPEndDisplayList(arg0++);
    // TODO: What is this doing?
    *arg2 = (((var_v0 + 8) - arg1) - 0xDB0) >> 3;
}
*/

void func_global_asm_805FE7FC(void) {
    s32 *mapGeometry;
    void *sp28;
    s32 *mapSetup;
    f32 phi_f0;
    s32 map;
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
        func_global_asm_8060098C(&func_global_asm_806025AC, 2, 0, 0, 0);
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
