#include "common.h"

extern u8 D_1050;
extern u8 D_11320;
extern u8 D_113F0;
extern u8 D_CBE70;
extern u8 D_D4B00;
extern u8 D_D6B00;
extern u8 D_D9A40;
extern u8 D_DF600;
extern u8 D_E6780;
extern u8 D_EA0B0;
extern u8 D_F41A0;
extern u8 D_FD2F0;
extern u8 D_101A40;
extern u8 romAssetBin;
extern u8 D_188AF20;
extern u8 D_1897860;
extern u8 D_1A97280;
extern u8 D_1ABCBF0;
extern u8 D_1FED020;

extern s8 D_dk64_boot_8000DCB0;
extern s32 D_dk64_boot_8000DCB4;
extern OverlayInfoStruct gOverlayTable[];
extern OSViMode osViModeTable[];
extern s32 D_dk64_boot_8000DE74[3];

extern OSMesg D_dk64_boot_80011520;
extern OSMesgQueue D_dk64_boot_80011548;
extern OSThread D_dk64_boot_80011560;
extern OSThread D_dk64_boot_80012710;
extern u32 D_dk64_boot_800138C0;

void func_dk64_boot_80000450(s32 devAddr, s32 arg1, void *dramAddr) {
    u32 size = arg1 - devAddr;
    osInvalDCache(dramAddr, size);
    osPiRawStartDma(OS_READ, devAddr, dramAddr, size);
    do { } while(osPiGetStatus() & PI_STATUS_DMA_BUSY);
}

void func_dk64_boot_800004B4(s32 *arg0, s32 *arg1) {
    func_dk64_boot_800024E0(arg0, arg1, (void*)0x804FAE00);
    func_dk64_boot_800024E0(arg0, arg1, (void*)0x804FAE00);
}

void func_dk64_boot_800004F4(s32 arg0) {
    OSMesg sp24;
    void (*gaFunc)(OSMesgQueue *, s32);
    osRecvMesg(&D_dk64_boot_80011548, &sp24, OS_MESG_BLOCK);
    switch ((u32)sp24) {
        case 0x29d:
            if (D_dk64_boot_8000DCB0) {
                gaFunc = (void*)0x805fb300; //TODO-shift: this number is hardcoded to the overlay starting address
                gaFunc(&D_dk64_boot_80011548, 2);
                break;
            }
            osViBlack(1);
            while(1);
        case 0x309:
            osSetThreadPri(NULL, 0x12);
            gaFunc = (void*)0x805fb300; //TODO-shift: this number is hardcoded to the overlay starting address
            gaFunc(&D_dk64_boot_80011548, 1);
            while(1);
    }
}

#ifndef NONMATCHING
void func_dk64_boot_800005A8(void *arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1050/func_dk64_boot_800005A8.s")
#else
void func_dk64_boot_800005A8(void *arg0) {
    u32 sp34;
    u32 sp30;
    s32 sp20[3] = D_dk64_boot_8000DE74;

    osCreateMesgQueue(&D_dk64_boot_80011548, &D_dk64_boot_80011520, OS_MESG_TYPE_LOOPBACK);
    osSetEventMesg(OS_EVENT_PRENMI, &D_dk64_boot_80011548, (OSMesg)0x29D);
    osCreateThread(&D_dk64_boot_80011560, 0xB, func_dk64_boot_800004F4, NULL, &D_dk64_boot_80012710, 0x64);
    osStartThread(&D_dk64_boot_80011560);
    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(osViModeTable + sp20[osTvType]);
    osViBlack(1);
    if (osMemSize < 0x80 || osTvType == OS_TV_PAL) {
        gOverlayTable[11].unk0 = &romAssetBin;
        gOverlayTable[11].unk4 = &D_188AF20;
        func_dk64_boot_80000A30();
    } else {
        func_dk64_boot_80000450(rspText_ROM_START, rspText_ROM_END, rspText_VRAM);
        D_dk64_boot_8000DCB4 = osAiSetFrequency(22050); // osAiSetFrequency
        bzero(0x805FB300, 0x204D00); //clear beginning of overlay until end of RAM
        sp34 = 0x80020000;
        sp30 = 0x805FB300;
        func_dk64_boot_80000450(&D_113F0, &D_CBE70, 0x80020000);
        func_dk64_boot_800004B4(&sp34, &sp30);
        osInvalICache(0x805FB300, sp30 + 0x7FA04D00);
        osWritebackDCacheAll();
        gOverlayTable[0].rom_data_end = &D_11320;
        gOverlayTable[0].rom_code_start = &D_1050;
        gOverlayTable[1].rom_data_end = &D_CBE70;
        gOverlayTable[1].rom_code_start = &D_113F0;
        gOverlayTable[2].rom_data_end = &D_D6B00;
        gOverlayTable[2].rom_code_start = &D_D4B00;
        gOverlayTable[3].rom_data_end = &D_D9A40;
        gOverlayTable[3].rom_code_start = &D_D6B00;
        gOverlayTable[4].rom_data_end = &D_DF600;
        gOverlayTable[4].rom_code_start = &D_D9A40;
        gOverlayTable[5].rom_data_end = &D_E6780;
        gOverlayTable[5].rom_code_start = &D_DF600;
        gOverlayTable[6].rom_data_end = &D_EA0B0;
        gOverlayTable[6].rom_code_start = &D_E6780;
        gOverlayTable[6].rom_data_end = &D_EA0B0;
        gOverlayTable[6].rom_code_start = &D_E6780;
        gOverlayTable[7].rom_data_end = &D_F41A0;
        gOverlayTable[7].rom_code_start = &D_EA0B0;
        gOverlayTable[8].rom_data_end = &D_FD2F0;
        gOverlayTable[8].rom_code_start = &D_F41A0;
        gOverlayTable[9].rom_data_end = &D_101A40;
        gOverlayTable[9].rom_code_start = &D_FD2F0;
        gOverlayTable[10].rom_code_start = &D_CBE70;
        gOverlayTable[10].rom_data_end = &D_D4B00;
        //
        gOverlayTable2[11].rom_code_start = &romAssetBin;
        gOverlayTable2[11].rom_data_end = &D_188AF20;
        gOverlayTable2[12].rom_code_start = &D_101A40;
        gOverlayTable2[12].rom_data_end = &romAssetBin;
        gOverlayTable2[13].rom_code_start = &romAssetBin;
        gOverlayTable2[13].rom_data_end = &romAssetBin;
        gOverlayTable2[14].rom_code_start = &D_1897860;
        gOverlayTable2[14].rom_data_end = &D_1A97280;
        gOverlayTable2[15].rom_data_end = &D_1897860;
        gOverlayTable2[15].rom_code_start = &D_188AF20;
        gOverlayTable2[16].rom_data_end = &D_1ABCBF0;
        gOverlayTable2[16].rom_code_start = &D_1A97280;
        gOverlayTable2[17].rom_data_end = &D_1FED020;
        gOverlayTable2[17].rom_code_start = &D_1ABCBF0;
        osSetThreadPri(NULL, OS_PRIORITY_IDLE);
        D_dk64_boot_8000DCB0 = 1;
        ((void (*)(OSMesgQueue *, s32))0x805FB300)(&D_dk64_boot_80011548, 0);
    }
    while(1);
}
#endif

void func_dk64_boot_80000980(void) {
    osCreateThread(&D_dk64_boot_80012710, 1, func_dk64_boot_800005A8, NULL, &D_dk64_boot_800138C0, 0);
    osStartThread(&D_dk64_boot_80012710);
}

void func_dk64_boot_800009D0(void) {
    u32 *tmp_a0;
    osInitialize();
    tmp_a0 = (void*)0xA02FE1C0;
    while(0xAD170014 != *tmp_a0);
    *tmp_a0 = 0xF0F0F0F0;
    func_dk64_boot_80000980();
}
