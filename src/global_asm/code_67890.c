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

extern GlobalASMStruct89 *D_807F93F0;
extern s32 D_807F93F8;

// Load map texture, malloc, loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_80662B90.s")

s32 func_80663040(s32 arg0) {
    s32 i;
    for (i = 0; i < D_807F93F8; i++) {
        if (arg0 == D_807F93F0[i].unk38) {
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_8066308C.s")

s32 func_80663594(s32, s32);

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

extern Struct807F93F4 *D_807F93F4;
extern f32 D_80758DE8;

s32 func_806634A4(s32 arg0) {
    s32 var_v0;
    s32 var_s1;
    s32 var_s0;
    f32 var_f20;
    f32 var_f2;

    var_f20 = D_80758DE8;
    do {
        var_s0 = 0;
        var_f2 = 0.0f;
        for (var_v0 = 0; var_v0 < D_807F93F8; var_v0++) {
            if (D_807F93F4[var_v0].unk11 != 0) {
                if (D_807F93F4[var_v0].unk0 < var_f20) {
                    if (var_f2 < D_807F93F4[var_v0].unk0) {
                        var_s1 = var_v0;
                        var_f2 = D_807F93F4[var_v0].unk0;
                        var_s0 = 1;
                    }
                }
            }
        }
        var_f20 = var_f2;
        if (var_s0 != 0) {
            arg0 = func_80663594(arg0, var_s1);
        }
    } while (var_s0 != 0);
    return arg0;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_80663594.s")
