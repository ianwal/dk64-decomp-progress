#include <ultra64.h>
#include "functions.h"

typedef struct GlobalASMStruct2 GlobalASMStruct2;

struct GlobalASMStruct2 {
    GlobalASMStruct2 *next;
    void *unk4;
    void *unk8;
    u8 padC[0x18 - 0x0C];
    f32 unk18;
    s16 unk1C;
};

extern s16 D_global_asm_80744490;
extern GlobalASMStruct2 *D_global_asm_80754AD0;
extern u16 D_global_asm_80754AD4;

Gfx *func_global_asm_806FD8E0(Gfx *dl, s16 style, char *string, s16 y, u8 extraBitfield) {
    s16 x = (D_global_asm_80744490 - getCenterOfString(style, string)) * 2;
    return printStyledText(dl, style, x, y * 4, string, extraBitfield);
}

Gfx *func_global_asm_806FD950(Gfx *dl, s16 style, char *string, s16 y) {
    return printStyledText(dl, style, 96, y * 4, string, 1);
}

void func_global_asm_806FD9A0(void) {
    D_global_asm_80754AD0 = NULL;
    D_global_asm_80754AD4 = 0;
}

GlobalASMStruct2 *func_global_asm_806FD9B4(s16 arg0) {
    GlobalASMStruct2 *var_v1;

    var_v1 = D_global_asm_80754AD0;
    while (var_v1 != NULL && arg0 != var_v1->unk1C) {
        var_v1 = var_v1->next;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FD9FC.s")

/*
s32 func_global_asm_806FD9FC(s32 arg0, s16 arg1, s16 arg2) {
    s32 temp_t2;

    temp_t2 = func_global_asm_806FD9B4(arg1)->unk8[arg2];
    arg0 = temp_t2;
    arg0->unk30->unk4 = temp_t2->unk40->unk4;
    return arg0;
}
*/

f32 func_global_asm_806FDA8C(s16 arg0) {
    return func_global_asm_806FD9B4(arg0)->unk18;
}

void func_global_asm_806FDAB8(s16 arg0, f32 arg1) {
    func_global_asm_806FD9B4(arg0)->unk18 = arg1;
}

void func_global_asm_806FDAEC(s16 arg0) {
    GlobalASMStruct2 *var_a1;
    GlobalASMStruct2 *var_v0;

    var_a1 = D_global_asm_80754AD0;
    var_v0 = NULL;
    while (var_a1 != NULL && arg0 != var_a1->unk1C) {
        var_v0 = var_a1;
        var_a1 = var_a1->next;
    }
    if (var_v0 != NULL) {
        var_v0->next = var_a1->next;
    } else {
        D_global_asm_80754AD0 = var_a1->next;
    }
    free(var_a1->unk4);
    free(var_a1->unk8);
    free(var_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FDB8C.s")

void func_global_asm_806FDF1C(s16 arg0, char *arg1) {
    strcpy(func_global_asm_806FD9B4(arg0)->unk4, arg1);
}

void func_global_asm_806FDF54(f32 *arg0, f32 *arg1) {
    while (*arg1 < 0.0f) {
        *arg1 += 6.283185482f;
    }
    while (6.283185482f <= *arg1) {
        *arg1 -= 6.283185482f;
    }
    *arg0 = (func_global_asm_806CC190((*arg0 * 2048.0) / 3.14159274101257324, (*arg1 * 2048.0) / 3.14159274101257324, 5.0f) * 3.141592741f) * 0.00048828125;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FE078.s")
