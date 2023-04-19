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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_806634A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_67890/func_80663594.s")
