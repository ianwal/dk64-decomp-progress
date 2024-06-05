#include <ultra64.h>
#include "functions.h"


typedef struct {
    s32 unk0[4];
    s32 unk10[4];
    s32 unk20[4];
    s32 unk30;
    s32 unk34;
    s16 unk38; // Used
    s16 unk3A;
    s32 unk3C;
} GlobalASMStruct89;

extern GlobalASMStruct89 *D_global_asm_807F93F0;
extern s32 D_global_asm_807F93F8;

// Load map texture, malloc, loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_global_asm_80662B90.s")

s32 func_global_asm_80663040(s32 arg0) {
    s32 i;
    for (i = 0; i < D_global_asm_807F93F8; i++) {
        if (arg0 == D_global_asm_807F93F0[i].unk38) {
            return TRUE;
        }
    }
    return FALSE;
}

// Doable, mid sized struct loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_global_asm_8066308C.s")

typedef struct {
    f32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} Struct807F93F4;

extern Struct807F93F4 *D_global_asm_807F93F4;

s32 func_global_asm_806634A4(s32 arg0) {
    s32 i;
    s32 var_s1;
    s32 found;
    f32 lowest;
    f32 var_f2;

    lowest = 100000000.0f;
    do {
        found = FALSE;
        var_f2 = 0.0f;
        for (i = 0; i < D_global_asm_807F93F8; i++) {
            if (D_global_asm_807F93F4[i].unk11 != 0) {
                if (D_global_asm_807F93F4[i].unk0 < lowest) {
                    if (var_f2 < D_global_asm_807F93F4[i].unk0) {
                        var_s1 = i;
                        var_f2 = D_global_asm_807F93F4[i].unk0;
                        found = TRUE;
                    }
                }
            }
        }
        lowest = var_f2;
        if (found) {
            arg0 = func_global_asm_80663594(arg0, var_s1);
        }
    } while (found);
    return arg0;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_global_asm_80663594.s")
