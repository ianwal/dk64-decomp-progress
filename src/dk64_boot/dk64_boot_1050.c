#include <ultra64.h>
#include "functions.h"

typedef struct {
    void *unk0;
    void *unk4;
    u8 pad8[0x10];
} dk64_boot_struct_0;

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
extern dk64_boot_struct_0 D_8000DCC4[];
extern OSViMode D_dk64_boot_8000EF20[];
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
    func_dk64_boot_800024E0(arg0, arg1, 0x804FAE00);
    func_dk64_boot_800024E0(arg0, arg1, 0x804FAE00);
}

void func_dk64_boot_800004F4(s32 arg0) {
    OSMesg sp24;
    void (*gaFunc)(OSMesgQueue *, s32);
    osRecvMesg(&D_dk64_boot_80011548, &sp24, OS_MESG_BLOCK);
    switch ((u32)sp24) {
        case 0x29d://L80000538
            if (D_dk64_boot_8000DCB0) {
                gaFunc = 0x805fb300;
                gaFunc(&D_dk64_boot_80011548, 2);
                break;
            }
            osViBlack(1);
            while(1);
        case 0x309: //L80000570
            osSetThreadPri(NULL, 0x12);
            gaFunc = 0x805fb300;
            gaFunc(&D_dk64_boot_80011548, 1);
            while(1);
    }
}

#ifndef NONMATCHING
void func_dk64_boot_800005A8(s32 arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1050/func_dk64_boot_800005A8.s")
#else
void func_dk64_boot_800005A8(s32 arg0) {
    u32 sp34;
    u32 sp30;
    s32 sp20[3] = D_dk64_boot_8000DE74;

    osCreateMesgQueue(&D_dk64_boot_80011548, &D_dk64_boot_80011520, OS_MESG_TYPE_LOOPBACK);
    osSetEventMesg(OS_EVENT_PRENMI, &D_dk64_boot_80011548, (OSMesg)0x29D);
    osCreateThread(&D_dk64_boot_80011560, 0xB, func_dk64_boot_800004F4, NULL, &D_dk64_boot_80012710, 0x64);
    osStartThread(&D_dk64_boot_80011560);
    osCreateViManager(0xFE);
    osViSetMode(D_dk64_boot_8000EF20 + sp20[osTvType]);
    osViBlack(1);
    if (osMemSize < 0x80 || osTvType == OS_TV_PAL) {
        D_8000DCC4[11].unk0 = &romAssetBin;
        D_8000DCC4[11].unk4 = &D_188AF20;
        func_dk64_boot_80000A30();
    } else {
        func_dk64_boot_80000450(&D_11320, &D_113F0, 0x805FB000);
        D_dk64_boot_8000DCB4 = func_dk64_boot_80005070(22050); // osAiSetFrequency
        bzero(0x805FB300, 0x204D00);
        sp34 = 0x80020000;
        sp30 = 0x805FB300;
        func_dk64_boot_80000450(&D_113F0, &D_CBE70, 0x80020000);
        func_dk64_boot_800004B4(&sp34, &sp30);
        osInvalICache(0x805FB300, sp30 + 0x7FA04D00);
        osWriteBackDCacheAll();
        D_8000DCC4[0].unk4 = &D_11320;
        D_8000DCC4[0].unk0 = &D_1050;
        D_8000DCC4[1].unk4 = &D_CBE70;
        D_8000DCC4[1].unk0 = &D_113F0;
        D_8000DCC4[2].unk4 = &D_D6B00;
        D_8000DCC4[2].unk0 = &D_D4B00;
        D_8000DCC4[3].unk4 = &D_D9A40;
        D_8000DCC4[3].unk0 = &D_D6B00;
        D_8000DCC4[4].unk4 = &D_DF600;
        D_8000DCC4[4].unk0 = &D_D9A40;
        D_8000DCC4[5].unk4 = &D_E6780;
        D_8000DCC4[5].unk0 = &D_DF600;
        D_8000DCC4[6].unk4 = &D_EA0B0;
        D_8000DCC4[6].unk0 = &D_E6780;
        D_8000DCC4[6].unk4 = &D_EA0B0;
        D_8000DCC4[6].unk0 = &D_E6780;
        D_8000DCC4[7].unk4 = &D_F41A0;
        D_8000DCC4[7].unk0 = &D_EA0B0;
        D_8000DCC4[8].unk4 = &D_FD2F0;
        D_8000DCC4[8].unk0 = &D_F41A0;
        D_8000DCC4[9].unk4 = &D_101A40;
        D_8000DCC4[9].unk0 = &D_FD2F0;
        D_8000DCC4[10].unk0 = &D_CBE70;
        D_8000DCC4[10].unk4 = &D_D4B00;
        D_8000DCC4[11].unk0 = &romAssetBin;
        D_8000DCC4[11].unk4 = &D_188AF20;
        D_8000DCC4[12].unk0 = &D_101A40;
        D_8000DCC4[12].unk4 = &romAssetBin;
        D_8000DCC4[13].unk0 = &romAssetBin;
        D_8000DCC4[13].unk4 = &romAssetBin;
        D_8000DCC4[14].unk0 = &D_1897860;
        D_8000DCC4[14].unk4 = &D_1A97280;
        D_8000DCC4[15].unk4 = &D_1897860;
        D_8000DCC4[15].unk0 = &D_188AF20;
        D_8000DCC4[16].unk4 = &D_1ABCBF0;
        D_8000DCC4[16].unk0 = &D_1A97280;
        D_8000DCC4[17].unk4 = &D_1FED020;
        D_8000DCC4[17].unk0 = &D_1ABCBF0;
        
        osSetThreadPri(NULL, 0);
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
    tmp_a0 = 0xA02FE1C0;
    while(0xAD170014 != *tmp_a0);
    *tmp_a0 = 0xF0F0F0F0;
    func_dk64_boot_80000980();
}
