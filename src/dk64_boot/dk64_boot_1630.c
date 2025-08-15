#include "common.h"
#include "piint.h"

void func_dk64_boot_80000AA0(void);
void func_dk64_boot_80000E48(void *arg0, s32 arg1, s32 arg2, const u8 *arg3);
void func_dk64_boot_80000EEC(s16* arg0[8][8], s32 arg1, s32 arg2, u8 arg3);

extern u8 D_dk64_boot_8000ED24[]; // "          NOT INSTALLED"
extern u8 D_dk64_boot_8000ED40[]; // "          NOT INSTALLED"
extern u8 D_dk64_boot_8000ED58[]; // "THE Nhf EXPANSION PAK ACCESSORY"
extern u8 D_dk64_boot_8000ED78[]; // "MUST BE INSTALLED IN THE Nhf~ FOR"
extern u8 D_dk64_boot_8000ED9C[]; // "THIS GAME[ SEE THE Nhf EXPANSION"
extern u8 D_dk64_boot_8000EDC0[]; // "   PAK INSTRUCTION BOOKLET["

extern OSThread D_dk64_boot_800138C0;
extern u8* D_dk64_boot_80013A70; // pointer to the stack for D_dk64_boot_800138C0

extern u16 D_dk64_boot_80100000[0];
extern u8 D_dk64_boot_80133E80[]; // stack for D_dk64_boot_800138C0

typedef struct{
    s32 unk0;
    s32 unk4;
} dk64_boot_struct_1_s;

// close, regalloc. might need -O3??
// https://decomp.me/scratch/WtY0n
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1630/func_dk64_boot_80000A30.s")

/*
void func_dk64_boot_80000A30(void) {
    D_dk64_boot_80013A70 = &D_dk64_boot_80133E80;
    osCreateThread(&D_dk64_boot_800138C0, 2, func_dk64_boot_80000AA0, NULL, D_dk64_boot_80013A70, 0xA);
    osStartThread(&D_dk64_boot_800138C0);
    while (TRUE) {};
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1630/func_dk64_boot_80000AA0.s")

void func_dk64_boot_80000CD4(void) {
    s16 *tmp_v0 = (void*)0x80100000;
    int i;
    s32 pad0;
    void * sp38;
    s32 sp34;
    dk64_boot_struct_1_s *tmp_s0;
    s32 pad1;
    s32 pad2;

    if (osTvType == OS_TV_PAL) {
        i = 0;
        do {
            tmp_v0[i++] = 0;
        } while(i < 0x12C00);
    } else {
        tmp_s0 = (void*)0x80280000;
        func_dk64_boot_8000102C(0x38, 0x10, tmp_s0);
        func_dk64_boot_8000102C(tmp_s0->unk0 + 0x4C, 0x10, tmp_s0);
        func_dk64_boot_8000102C(tmp_s0->unk0, tmp_s0->unk4 - tmp_s0->unk0, tmp_s0);
        sp38 = tmp_s0;
        sp34 = 0x80380000;
        func_dk64_boot_800024E0(&sp38, &sp34, 0x803C0000);
        func_dk64_boot_80000D8C((void*)0x80100000);
    }
}

void func_dk64_boot_80000D8C(void *arg0) {
    if (osTvType != OS_TV_PAL) {
        func_dk64_boot_80000E48(arg0, 0x15, 0x8C, D_dk64_boot_8000ED24);
        func_dk64_boot_80000E48(arg0, 0x15, 0x96, D_dk64_boot_8000ED40);
        func_dk64_boot_80000E48(arg0, 0x15, 0xAA, D_dk64_boot_8000ED58);
        func_dk64_boot_80000E48(arg0, 0x15, 0xb4, D_dk64_boot_8000ED78);
        func_dk64_boot_80000E48(arg0, 0x15, 0xbe, D_dk64_boot_8000ED9C);
        func_dk64_boot_80000E48(arg0, 0x15, 0xc8, D_dk64_boot_8000EDC0);
    }
}

void func_dk64_boot_80000E48(void *arg0, s32 arg1, s32 arg2, const u8 *arg3) {
    s32 i;
    for (i = 0; arg3[i] != 0; arg1 += 9, i++) {
        if (0x20 != arg3[i]) {
            func_dk64_boot_80000EEC(arg0, arg1, arg2, arg3[i]);
        } else {
            arg1 -= 2;
        }
    }
    osWritebackDCache(arg0, 0x25800);
}

// close
// https://decomp.me/scratch/IV2xv
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_1630/func_dk64_boot_80000EEC.s")

/*
void func_dk64_boot_80000EEC(s16* dst, s32 x, s32 y, u8 chr) {
    s32 row;
    s32 col;
    s32 mask;
    s32 a1;
    s32 v0;
    s32 a2;
    u8 *glyph;
    s32 notmask;
    u8 byte;
    s32 off;

    // Adjust character index if >= 0x79 (?)
    if (chr >= 0x79) {
        chr = (u8)((chr + 2) & 0xFF);
    }

    // Compute starting dst position (?)
    off = (y * 5) * 64; // TODO: Might be << 6 instead of * 64?
    off += x;
    dst += off;

    // Lookup glyph base in font table (?)
    v0 = (chr << 2) + 0x8037FEFC;
    glyph = v0;

    a2 = 0;
    while (a2 != 8) { // rows
        mask = 0xF0;
        a1 = 0;
        while (a1 != 8) { // columns
            {
                // 1st pixel pair
                byte = glyph[a1 >> 1];
                if (byte & mask) {
                    *dst = -1;
                } else {
                    *dst = 1;
                }
            }

            {
                // 2nd pixel pair
                byte = glyph[(a1 + 1) >> 1];
                notmask = (~mask) & 0xFF;
                dst++;
                if (byte & notmask) {
                    *dst = -1;
                } else {
                    *dst = 1;
                }
                mask = (~notmask) & 0xFF;
            }

            {
                // 3rd pixel pair
                byte = glyph[(a1 + 2) >> 1];
                dst++;
                if (byte & mask) {
                    *dst = -1;
                } else {
                    *dst = 1;
                }
                notmask = (~mask) & 0xFF;
            }

            {
                // 4th pixel pair
                byte = glyph[(a1 + 3) >> 1];
                dst++;
                if (byte & notmask) {
                    *dst = -1;
                } else {
                    *dst = 1;
                }
                mask = (~notmask) & 0xFF;
            }

            a1 += 4;
            dst++;
        }

        a2++;
        glyph += 0x100;   // advance to next glyph row (?)
        dst += 0x138;     // stride to next framebuffer row (?)
    }
}
*/

void func_dk64_boot_8000102C(s32 offset, s32 size, void *dramAddr) {
    while(size & 0xf)
    {
        size++;
    }
    osWritebackDCache(dramAddr, size);
    osPiRawStartDma(OS_READ, gOverlayTable[11].rom_code_start + offset, dramAddr, size);
    do{}while(osPiGetStatus() & PI_STATUS_DMA_BUSY);
    osInvalDCache(dramAddr, size);
}
