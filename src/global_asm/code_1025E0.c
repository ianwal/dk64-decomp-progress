#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80754AD4;

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

extern u8 D_global_asm_8074450C;

s16 func_global_asm_806FDB8C(s16 arg0, u8 *arg1, u8 arg2, f32 arg3, f32 arg4, f32 arg5) {
    Struct80754AD0 *temp_v0;
    Struct80754AD0 *var_v1;
    s16 i;
    u32 len;

    getCenterOfString(arg0, arg1);
    temp_v0 = malloc(sizeof(Struct80754AD0));
    func_global_asm_80611690(temp_v0);
    if (D_global_asm_80754AD0 == NULL) {
        D_global_asm_80754AD0 = temp_v0;
        D_global_asm_80754AD0->next = NULL;
        D_global_asm_80754AD4 = 0;
    } else {
        var_v1 = D_global_asm_80754AD0;
        while (var_v1->next) {
            var_v1 = var_v1->next;
        }
        var_v1->next = temp_v0;
        temp_v0->next = NULL;
    }
    temp_v0->unk1C = D_global_asm_80754AD4++;
    len = strlen(arg1);
    temp_v0->unk4 = malloc(len + 1);
    strcpy(temp_v0->unk4, arg1);
    temp_v0->unkD = func_global_asm_806FBEAC(arg1);
    temp_v0->unk8 = malloc(temp_v0->unkD * sizeof(Struct806FD9FC));
    func_global_asm_80611690(temp_v0->unk8);
    temp_v0->unkC = arg0;
    for (i = 0; i < temp_v0->unkD; i++) {
        if (arg2 == 3) {
            temp_v0->unk8[i].unk0 = (((rand() >> 0xF) % 1440) - 0x50);
            temp_v0->unk8[i].unk4 = (((rand() >> 0xF) % 1120) - 0x50);
            temp_v0->unk8[i].unk20 = (((rand() >> 0xF) % 6283) / 1000.0);
            temp_v0->unk14 = 0.1f;
        } else {
            temp_v0->unk8[i].unk0 = arg3 * 4.0f;
            temp_v0->unk8[i].unk4 = arg4 * 4.0f;
            temp_v0->unk8[i].unk8 = arg5 * 4.0f;
            temp_v0->unk8[i].unk30 = D_global_asm_8074450C == 2 ? 1.0 : 0.1;
            temp_v0->unk14 = 0.2f;
        }
    }
    return temp_v0->unk1C;
}



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
