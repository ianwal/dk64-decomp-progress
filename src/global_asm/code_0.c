#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FB300.s")

void func_global_asm_805FB5C4(OSMesgQueue *, s32);
void func_global_asm_805FBFF4(void *);
extern void func_dk64_boot_80000450(s32 devAddr, s32 arg1, void *dramAddr);
extern OverlayInfoStruct D_8000DCC4[];
extern void func_arcade_80024000(void);
extern void func_boss_80024000(void);
extern void func_menu_80024000(MenuStruct80024000 *);
extern void func_jetpac_80024000(void);
extern Gfx *func_bonus_80024000(Gfx *, Actor *);
extern void func_race_80024000(void);
extern void func_critter_80024000(Critter *, u8 *, f32);
extern void func_minecart_80024000(u8, u8);
extern OSMesgQueue D_80761050;
extern void *D_80761068;
extern OSThread D_80761430;
extern u64 D_global_asm_80761680;
extern OSMesgQueue *D_global_asm_807655E0;

// Solely for pointers
extern s32 D_80010720;
extern s32 D_80016630;
extern s32 D_global_asm_807FF100;
extern s32 D_80027110;
extern s32 D_80027100;
extern s32 D_80028E20;
extern s32 D_80028E10;
extern s32 D_8002DF10;
extern s32 D_bonus_8002DEF0;
extern s32 D_80030170;
extern s32 D_80030160;
extern s32 D_8002A1E0;
extern s32 D_critter_8002A1B0;
extern s32 D_80036DF0;
extern s32 D_80036DC0;
extern s32 D_80045C00;
extern s32 D_jetpac_8002EC30;
extern s32 D_80033FD0;
extern s32 D_80033F10;
extern s32 D_8004C750;
extern s32 D_arcade_8004AC00;

#define setOverlay(i, start, ovl_end, code_end) \
    D_8000DCC4[i].rdram_start = start; \
    D_8000DCC4[i].overlay_end = ovl_end; \
    D_8000DCC4[i].rdram_code_end = code_end; \
    D_8000DCC4[i].rdram_data_end = ovl_end;

/*
void func_global_asm_805FB300(OSMesgQueue *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_global_asm_805FB5C4(arg0, arg1);
    }
    D_global_asm_807655E0 = arg0;
    setOverlay(0, func_dk64_boot_80000450, &D_80016630, &D_80010720); // Boot
    setOverlay(1, func_global_asm_805FB300, &D_global_asm_807FF100, &D_80761050); // Global ASM
    setOverlay(2, func_multiplayer_80024000, &D_80027110, &D_80027100); // Multiplayer
    setOverlay(3, func_minecart_80024000, &D_80028E20, &D_80028E10); // Minecart
    setOverlay(4, func_bonus_80024000, &D_8002DF10, &D_bonus_8002DEF0); // Bonus
    setOverlay(5, func_race_80024000, &D_80030170, &D_80030160); // Race
    setOverlay(6, func_critter_80024000, &D_8002A1E0, &D_critter_8002A1B0); // Critter
    setOverlay(7, func_boss_80024000, &D_80036DF0, &D_80036DC0); // Boss
    setOverlay(8, func_jetpac_80024000, &D_80045C00, &D_jetpac_8002EC30); // Jetpac
    setOverlay(9, func_menu_80024000, &D_80033FD0, &D_80033F10); // Menu
    setOverlay(10, func_arcade_80024000, &D_8004C750, &D_arcade_8004AC00); // Arcade
    osDpSetStatus(4U);
    osCreatePiManager(0x96, &D_80761050, &D_80761068, 0xF2);
    D_global_asm_80761680 = 0x12345678;
    osCreateThread(&D_80761430, 3, func_global_asm_805FBFF4, NULL, &D_global_asm_807655E0, 0xA);
    osStartThread(&D_80761430);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_0/func_global_asm_805FB5C4.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct80744464;

void __osSpSetStatus(u32);
extern OSThread D_80761430;
extern OSTime D_807655E8;
extern s8 D_global_asm_80744460;
extern Struct80744464 D_global_asm_80744464;
#define BUFFER_TIME OS_NSEC_TO_CYCLES(48484843)

/*
void func_global_asm_805FB5C4(OSMesgQueue *arg0, s32 arg1) {
    OSTime target_time;
    Struct80744464 sp34;
    OSTime buffer_time;
    u8 buffer[4];
    void *sp20;

    sp34 = D_global_asm_80744464;
    if (arg1 == 2) {
        osViBlack(1U);
        func_global_asm_80601CF0(1);
        D_global_asm_80744460 = 1;
        while (TRUE) {}
    }
    osRecvMesg(arg0, &sp20, 1);
    D_global_asm_80744460 = 1;
    func_global_asm_80601CF0(1);
    osStopThread(&D_80761430);
    osSetThreadPri(NULL, 0xB);
    D_807655E8 = osGetTime();
    while (osGetTime() < D_807655E8 + BUFFER_TIME);
    osViBlack(1U);
    __osSpSetStatus(0xAAAA82);
    osDpSetStatus(0x1D6U);
    func_global_asm_8060E930();
    while (TRUE) {}
}
*/