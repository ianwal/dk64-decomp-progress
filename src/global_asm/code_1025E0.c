#include "common.h"

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
    _strcpy(temp_v0->unk4, arg1);
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
    _strcpy(func_global_asm_806FD9B4(arg0)->unk4, arg1);
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

// Jumptable, Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FE078.s")

Gfx *func_global_asm_806FCC88(Gfx *, Struct80754AD0 *);
Gfx *func_global_asm_806FD094(Gfx *, Struct80754AD0 *);
s32 func_global_asm_806FD7A8(s16, u8);
extern Struct80754A34 D_global_asm_80754A34[];

/*
Gfx *func_global_asm_806FE078(Gfx *dl, s16 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Struct80754AD0 *temp_v0;
    f32 var_f24;
    f32 var_f26;
    f32 var_f28;
    f32 sp7C;
    s16 i, var_s5;
    u8 var_s7;
    f32 sp70;
    u8 var_s6;
    u8 temp_a0;
    u8 temp_v1_2;
    u8 ch;
    f32 center;

    var_f26 = arg3;
    temp_v0 = func_global_asm_806FD9B4(arg1);
    i = 0;
    center = getCenterOfString(temp_v0->unkC, temp_v0->unk4);
    var_f28 = ((D_global_asm_80744490 - (center * arg6)) / 2) + -3.0f;
    sp7C = D_global_asm_80744490 >> 3;
    var_f24 = temp_v0->unk10;
    sp70 = MATH_2PI_F / temp_v0->unkD;
    var_s5 = 1;
    var_s6 = TRUE;
    var_s7 = TRUE;
    ch = temp_v0->unk4[0];
    while (ch) {
        if (ch != ' ') {
            temp_v1_2 = func_global_asm_806FD7A8(temp_v0->unkC, ch) * arg6;
            temp_a0 = temp_v1_2 / 2;
            switch (arg2) {
            case 8:
                temp_v0->unk8[i].unkC = (temp_a0 + var_f26) * 4.0f;
                temp_v0->unk8[i].unk10 = arg4 * 4.0f;
                var_f26 += temp_v1_2;
                temp_v0->unk8[i].unk34 = (func_global_asm_80612D1C(temp_v0->unk18) * 0.5) + arg6;
                if (temp_v0->unk18 > 0.0f) {
                    temp_v0->unk18 -= 0.1;
                } else {
                    temp_v0->unk18 = 0.0f;
                }
                break;
            case 6:
                var_s6 = FALSE;
                var_s7 = FALSE;
                temp_v0->unk8[i].unk0 = (var_f26 + 20.0f) * 4.0f;
                temp_v0->unk8[i].unk4 = arg4 * 4.0f;
                var_f26 += 28.0f;
                temp_v0->unk8[i].unk20 = func_global_asm_80612D1C(temp_v0->unk18) * 0.35;
                temp_v0->unk8[i].unk30 = 1.5f;
                break;
            case 5:
                var_s6 = FALSE;
                var_s7 = FALSE;
                temp_v0->unk8[i].unk0 = (temp_a0 + var_f28) * 4.0f;
                temp_v0->unk8[i].unk4 = arg4 * 4.0f;
                var_f28 += temp_v1_2;
                temp_v0->unk8[i].unk20 = 0.0f;
                temp_v0->unk8[i].unk30 = (func_global_asm_80612D1C(var_f24) * 0.05) + 1.0;
                var_f24 += sp70;
                temp_v0->unk10 += 0.1;
                break;
            case 4:
                temp_v0->unk8[i].unkC = (temp_a0 + var_f28) * 4.0f;
                temp_v0->unk8[i].unk10 = arg4 * 4.0f;
                var_f28 += temp_v1_2;
                temp_v0->unk8[i].unk34 = 1.0f;
                break;
            case 3:
                temp_v0->unk8[i].unkC = (temp_a0 + var_f28) * 4.0f;
                temp_v0->unk8[i].unk10 = arg4 * 4.0f;
                var_f28 += temp_v1_2;
                temp_v0->unk8[i].unk2C = 0.0f;
                temp_v0->unk8[i].unk34 = (func_global_asm_80612D1C(var_f24) * 0.3) + 1.2;
                var_f24 += sp70;
                temp_v0->unk10 += 0.04;
                break;
            case 1:
                var_f24 -= (temp_a0 * 0.013f);
                temp_v0->unk8[i].unkC = (((func_global_asm_80612D1C(var_f24) * sp7C) + var_f26) * 4.0f);
                temp_v0->unk8[i].unk10 = (((func_global_asm_80612D10(var_f24) * sp7C) + arg4) * 4.0f);
                temp_v0->unk8[i].unk2C = (3.1415927f - var_f24);
                var_f24 -= (temp_v1_2 * 0.013f);
                break;
            case 2:
                temp_v0->unk8[i].unkC = ((temp_a0 + var_f28) * 4.0f);
                temp_v0->unk8[i].unk10 = ((func_global_asm_80612D1C(var_f24 * 2) * 5.0) + arg4) * 4.0;
                var_f28 += temp_v1_2;
                var_f24 += sp70;
                temp_v0->unk8[i].unk20 = (func_global_asm_80612D1C(var_f24 * 2) * 0.5);
                temp_v0->unk10 -= 0.01;
                temp_v0->unk8[i].unk34 = arg6;
                break;
            case 9:
                temp_v0->unk8[i].unkC = var_f26 - temp_a0 * 4;
                temp_v0->unk8[i].unk10 = arg4;
                temp_v0->unk8[i].unk14 = arg5;
                var_f26 -= temp_v1_2 * 4;
                var_f24 += sp70;
                temp_v0->unk8[i].unk34 = ((func_global_asm_80612D1C(var_f24) * (0.2 * arg6)) + arg6);
                temp_v0->unk8[i].unk2C = MATH_PI_F;
                temp_v0->unk10 -= 0.08;
                break;
            case 10:
                temp_v0->unk8[i].unkC = var_f26;
                temp_v0->unk8[i].unk10 = arg4;
                temp_v0->unk8[i].unk14 = (temp_v1_2 + arg5);
                arg5 += (temp_v1_2 * 4);
                var_f24 += sp70;
                temp_v0->unk8[i].unk34 = ((func_global_asm_80612D1C(var_f24) * (0.2 * arg6)) + arg6);
                temp_v0->unk8[i].unk24 = MATH_HALFPI_F;
                temp_v0->unk8[i].unk28 = -MATH_HALFPI_F;
                temp_v0->unk8[i].unk2C = 0.0f;
                temp_v0->unk10 -= 0.08;
                break;
            }
            if (var_s6) {
                temp_v0->unk8[i].unk0 = temp_v0->unk8[i].unk0 + (temp_v0->unk8[i].unkC - temp_v0->unk8[i].unk0) * temp_v0->unk14;
                temp_v0->unk8[i].unk4 = temp_v0->unk8[i].unk4 + (temp_v0->unk8[i].unk10 - temp_v0->unk8[i].unk4) * temp_v0->unk14;
                temp_v0->unk8[i].unk8 = temp_v0->unk8[i].unk8 + (temp_v0->unk8[i].unk14 - temp_v0->unk8[i].unk8) * temp_v0->unk14;
                func_global_asm_806FDF54(&temp_v0->unk8[i].unk18, &temp_v0->unk8[i].unk24);
                func_global_asm_806FDF54(&temp_v0->unk8[i].unk1C, &temp_v0->unk8[i].unk28);
                func_global_asm_806FDF54(&temp_v0->unk8[i].unk20, &temp_v0->unk8[i].unk2C);
            }
            if (var_s7) {
                temp_v0->unk8[i].unk30 = temp_v0->unk8[i].unk30 + (temp_v0->unk8[i].unk34 - temp_v0->unk8[i].unk30) * temp_v0->unk14;
            }
            i++;
        } else {
            switch (arg2) {
            case 1:
                var_f24 -= D_global_asm_80754A34[temp_v0->unkC].kerning_space * 0.013f;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 8:
                var_f28 += D_global_asm_80754A34[temp_v0->unkC].kerning_space;
                break;
            case 6:
                var_f26 += 32.0f;
                break;
            case 10:
                arg5 += D_global_asm_80754A34[temp_v0->unkC].kerning_space;
                break;
            default:
                var_f26 += D_global_asm_80754A34[temp_v0->unkC].kerning_space;
                break;
            }
            var_f24 -= (D_global_asm_80754A34[temp_v0->unkC].kerning_space * 0.019);
        }
        if (var_f24 < 0.0f) {
            var_f24 += MATH_2PI_F;
        }
        ch = temp_v0->unk4[var_s5++];
    }
    gDPPipeSync(dl++);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    switch (arg2) {
    case 0x9:
    case 0xA:
        return func_global_asm_806FD094(dl, temp_v0);
    case 0xFF:
        temp_v0->unk10 += 0.04;
        return func_global_asm_806FD094(dl, temp_v0);
    case 0x8:
        if (!func_global_asm_805FCA64()) {
            return dl;
        }
        break;
    case 0x1:
        temp_v0->unk10 += 0.02;
        break;
    }
    temp_v0->unk10 += 0.04;
    return func_global_asm_806FCC88(dl, temp_v0);
}
*/