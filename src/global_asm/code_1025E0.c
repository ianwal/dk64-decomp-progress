#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80744490;
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

Struct80754AD0 *func_global_asm_806FD9B4(s16 arg0) {
    Struct80754AD0 *current;

    current = D_global_asm_80754AD0;
    while (current != NULL && arg0 != current->unk1C) {
        current = current->next;
    }
    return current;
}

s32 func_global_asm_806FD9FC(Struct806FD9FC *arg0, s16 arg1, s16 arg2) {
    Struct80754AD0 *var_v0;

    var_v0 = func_global_asm_806FD9B4(arg1);
    *arg0 = var_v0->unk8[arg2];
    return arg0;
}

f32 func_global_asm_806FDA8C(s16 arg0) {
    return func_global_asm_806FD9B4(arg0)->unk18;
}

void func_global_asm_806FDAB8(s16 arg0, f32 arg1) {
    func_global_asm_806FD9B4(arg0)->unk18 = arg1;
}

void func_global_asm_806FDAEC(s16 arg0) {
    Struct80754AD0 *var_a1;
    Struct80754AD0 *var_v0;

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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FDB8C.s")

void func_global_asm_806FDF1C(s16 arg0, char *arg1) {
    strcpy(func_global_asm_806FD9B4(arg0)->unk4, arg1);
}

void func_global_asm_806FDF54(f32 *arg0, f32 *arg1) {
    while (*arg1 < 0.0f) {
        *arg1 += MATH_2PI_F;
    }
    while (MATH_2PI_F <= *arg1) {
        *arg1 -= MATH_2PI_F;
    }
    *arg0 = (func_global_asm_806CC190((*arg0 * 2048.0) / 3.14159274101257324, (*arg1 * 2048.0) / 3.14159274101257324, 5.0f) * M_PIF) * 0.00048828125;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FE078.s")
