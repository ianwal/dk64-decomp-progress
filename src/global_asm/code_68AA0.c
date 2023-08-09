#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_80747D70;
extern s16 D_global_asm_807F9424;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    s8 unk7[1];
    s8 unk8[1];
    s8 unk9;
    s16 unkA;
} Struct807F9420;

extern Struct807F9420 *D_global_asm_807F9420;

void func_global_asm_80663DA0(void) {
    s32 i;
    u8 temp_v0;
    s32 temp_v0_2;
    s32 count;

    count = 0;
    D_global_asm_807F9424 = 0;
    for (i = 0; i < D_global_asm_80747D70; i++) {
        if (func_global_asm_80663FCC(i) != 0) {
            D_global_asm_807F9424 += 1;
        }
    }
    D_global_asm_807F9420 = NULL;
    if (D_global_asm_807F9424 != 0) {
        D_global_asm_807F9420 = malloc(D_global_asm_807F9424 * sizeof(Struct807F9420));
        for (i = 0; i < D_global_asm_80747D70; i++) {
            temp_v0 = func_global_asm_80663FCC(i);
            if (temp_v0 != 0) {
                D_global_asm_807F9420[count].unk0 = D_global_asm_807F6000[i].x_position;
                D_global_asm_807F9420[count].unk2 = D_global_asm_807F6000[i].y_position;
                D_global_asm_807F9420[count].unk4 = D_global_asm_807F6000[i].z_position;
                D_global_asm_807F9420[count].unk6 = temp_v0;
                D_global_asm_807F9420[count].unk7[0] = func_global_asm_806531B8(D_global_asm_807F6000[i].x_position, D_global_asm_807F6000[i].y_position, D_global_asm_807F6000[i].z_position, 0);
                temp_v0_2 = func_global_asm_80658B08(D_global_asm_807F9420[count].unk7[0], &D_global_asm_807F9420[count].unk8, 4);
                if (temp_v0_2 != 4) {
                    D_global_asm_807F9420[count].unk8[temp_v0_2] = -1;
                }
                count += 1;
            }
        }
    }
}

u8 func_global_asm_80663FCC(s16 model2ArrayIndex) {
    switch (D_global_asm_807F6000[model2ArrayIndex].object_type) {
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

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68AA0/func_global_asm_80664044.s")

void func_global_asm_80603340(f32, f32, f32, u8, s32, f32);

/*
void func_global_asm_80664044(u8 arg0, u8 arg1, u8 arg2, f32 arg3) {
    s32 found;
    s32 j;
    s32 i;

    for (i = 0; i < D_global_asm_807F9424; i++) {
        if (arg0 == D_global_asm_807F9420[i].unk6) {
            found = FALSE;
            j = 0;
            while (TRUE) {
                if (D_global_asm_807F9420[i].unk7[j] == character_change_array->chunk) {
                    found = TRUE;
                }
                j++;
                if (j >= 5 || found || D_global_asm_807F9420[i].unk7[j] == -1) {
                    break;
                }
            }
            if (found) {
                func_global_asm_80603340(D_global_asm_807F9420[i].unk0, D_global_asm_807F9420[i].unk2, D_global_asm_807F9420[i].unk4, arg1, arg2, arg3);
            }
        }
    }
}
*/
