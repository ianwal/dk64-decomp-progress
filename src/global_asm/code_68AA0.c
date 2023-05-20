#include <ultra64.h>
#include "functions.h"

s8 func_806531B8(f32, f32, f32, s16);
s16 func_80658B08(s8, void *, s16);
extern s32 D_80747D70;
extern s16 D_807F9424;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s8 unk8[1];
    s8 unk9;
    s16 unkA;
} Struct807F9420;

extern Struct807F9420 *D_807F9420;

void func_80663DA0(void) {
    s32 i;
    u8 temp_v0;
    s32 temp_v0_2;
    s32 count;

    count = 0;
    D_807F9424 = 0;
    for (i = 0; i < D_80747D70; i++) {
        if (func_80663FCC(i) != 0) {
            D_807F9424 += 1;
        }
    }
    D_807F9420 = NULL;
    if (D_807F9424 != 0) {
        D_807F9420 = malloc(D_807F9424 * sizeof(Struct807F9420));
        for (i = 0; i < D_80747D70; i++) {
            temp_v0 = func_80663FCC(i);
            if (temp_v0 != 0) {
                D_807F9420[count].unk0 = D_807F6000[i].x_position;
                D_807F9420[count].unk2 = D_807F6000[i].y_position;
                D_807F9420[count].unk4 = D_807F6000[i].z_position;
                D_807F9420[count].unk6 = temp_v0;
                D_807F9420[count].unk7 = func_806531B8(D_807F6000[i].x_position, D_807F6000[i].y_position, D_807F6000[i].z_position, 0);
                temp_v0_2 = func_80658B08(D_807F9420[count].unk7, &D_807F9420[count].unk8, 4);
                if (temp_v0_2 != 4) {
                    D_807F9420[count].unk8[temp_v0_2] = -1;
                }
                count += 1;
            }
        }
    }
}

u8 func_80663FCC(s16 model2ArrayIndex) {
    switch (D_807F6000[model2ArrayIndex].object_type) {
        case 0x1: // Thin Flame? (2D)
        case 0xC: // Flames (2D)
        case 0x10: // Flame (2D)
        case 0xF3: // Torch
        case 0x134: // Flame
        case 0x135: // Flame
        case 0x138: // Torch
            return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68AA0/func_80664044.s")
