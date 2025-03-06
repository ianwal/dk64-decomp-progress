#include <ultra64.h>
#include "functions.h"


void func_global_asm_806C71A0(void) {

}

void func_global_asm_806C71A8(void) {

}

void func_global_asm_806C71B0(void) {

}

void func_global_asm_806C71B8(void) {

}

void func_global_asm_806C71C0(void) {

}

void func_global_asm_806C71C8(void) {

}

void func_global_asm_806C71D0(void) {

}

void func_global_asm_806C71D8(void) {

}

void func_global_asm_806C71E0(void) {

}

void func_global_asm_806C71E8(void) {

}

void func_global_asm_806C71F0(void) {

}

void func_global_asm_806C71F8(void) {

}

void func_global_asm_806C7200(void) {

}

void func_global_asm_806C7208(void) {

}

void func_global_asm_806C7210(void) {

}

void func_global_asm_806C7218(void) {

}

void func_global_asm_806C7220(void) {

}

void func_global_asm_806C7228(void) {

}

void func_global_asm_806C7230(void) {

}

void func_global_asm_806C7238(void) {

}

void func_global_asm_806C7240(void) {

}

void func_global_asm_806C7248(void) {

}

void func_global_asm_806C7250(void) {

}

void func_global_asm_806C7258(void) {

}

void func_global_asm_806C7260(void) {

}

void func_global_asm_806C7268(void) {

}

// float, regalloc
// https://decomp.me/scratch/poTWc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CBEA0/func_global_asm_806C7270.s")

typedef struct {
    s16 duration;
    s16 cooldown;
    u8 squish_from;
    s8 text_count;
} EndSequenceCardStruct;

extern EndSequenceCardStruct D_global_asm_807506D0[];
extern s8 D_global_asm_80750754;
extern s16 D_global_asm_80750758;
extern f32 D_global_asm_8075075C[][2];

extern s16 D_global_asm_807FC8E0;
extern s16 D_global_asm_807FC8E2;
extern s16 D_global_asm_807FC8E4;
extern f32 D_global_asm_807FC8E8;
extern f32 D_global_asm_807FC8EC;
extern u8 *D_global_asm_807FC8F0;

Gfx *func_global_asm_806C75A4(Gfx *dl, Actor *arg1);

/*
void func_global_asm_806C7270(void) {
    s32 temp1;
    f32 temp_f0;
    s32 temp;
    s32 var_v1;

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FC8F0 = getPointerTableFile(TABLE_19_UNKNOWN, 7, 1, 1);
        D_global_asm_807FC8E0 = 0;
        var_v1 = 0;
        while (D_global_asm_807FC8F0[var_v1] != 0x2A) {
            if (D_global_asm_807FC8F0[var_v1] == 0xA) {
                D_global_asm_807FC8F0[var_v1] = 0;
                D_global_asm_807FC8E0 += 1;
            }
            var_v1 += 1;
        }
        if (D_global_asm_80750754 == -2) {
            D_global_asm_807FC8E4 = 800;
            D_global_asm_80750754 = -1;
            D_global_asm_807FC8E2 = 0;
            D_global_asm_807FC8E8 = 0;
        } else if (D_global_asm_80750754 == -1) {
            D_global_asm_807FC8E4 = 60;
            D_global_asm_807FC8E2 = 0;
            D_global_asm_807FC8E8 = 0;
        }
    }
    if (D_global_asm_807FC8E2 > 0) {
        D_global_asm_807FC8E2 -= 1;
    }
    if (D_global_asm_807FC8E2 == 0) {
        D_global_asm_807FC8E2 = 0;
        D_global_asm_807FC8E4 -= 1;
        if (D_global_asm_807FC8E4 <= 0) {
            if (D_global_asm_80750754 >= 0) {
                D_global_asm_80750758 += D_global_asm_807506D0[D_global_asm_80750754].text_count;
            }
            if (D_global_asm_80750758 >= D_global_asm_807FC8E0) {
                D_global_asm_80750758 = 0;
            }
            D_global_asm_80750754 += 1;
            D_global_asm_807FC8E2 = D_global_asm_807506D0[D_global_asm_80750754].duration;
            D_global_asm_807FC8E4 = D_global_asm_807506D0[D_global_asm_80750754].cooldown;
        }
    }
    if (D_global_asm_807FC8E2 < 0xB) {
        D_global_asm_807FC8E8 -= 0.1f;
        if (D_global_asm_807FC8E8 < 0.0f) {
            D_global_asm_807FC8E8 = 0.0f;
        }
        D_global_asm_807FC8EC = 1;
    } else {
        temp = D_global_asm_807506D0[D_global_asm_80750754].duration - D_global_asm_807FC8E2;
        temp1 = temp;
        temp >>= 1;
        if (temp < 0x16) {
            temp_f0 = temp1 & 1;
            temp_f0 /= 2.0;
            if (temp_f0);
            D_global_asm_807FC8E8 = D_global_asm_8075075C[temp][0] + ((D_global_asm_8075075C[temp][2] - D_global_asm_8075075C[temp][0]) * temp_f0);
            D_global_asm_807FC8EC = D_global_asm_8075075C[temp][1] + ((D_global_asm_8075075C[temp][3] - D_global_asm_8075075C[temp][1]) * temp_f0);
        } else {
            D_global_asm_807FC8E8 = 1.0f;
            D_global_asm_807FC8EC = 1.0f;
        }
    }
    addActorToTextOverlayRenderArray(func_global_asm_806C75A4, gCurrentActorPointer, 3);
}
*/

// Displaylist stuff, matrix
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CBEA0/func_global_asm_806C75A4.s")

typedef struct struct80750814 {
    u8 data[4];
} struct80750814;

extern struct80750814 D_global_asm_80750814;
extern f32 D_global_asm_80750818[];
extern f32 D_global_asm_80750828[];

/*
Gfx *func_global_asm_806C75A4(Gfx *dl, Actor *arg1) {
    f32 sp10C;
    f32 sp108;
    struct80750814 sp104;
    f32 spC4[4][4];
    f32 sp84[4][4];
    Gfx *temp_a0;
    Gfx *var_s3;
    Mtx *temp_v0_2;
    f32 temp_s0;
    f32 var_f0;
    f32 var_f12;
    f32 var_f2;
    s16 y;
    s16 i;
    s16 var_v1;
    s32 temp_v0;
    s8 *str;
    s8 direction;
    s8 temp_v0_3;
    u8 temp_t4;

    sp104 = D_global_asm_80750814;
    if (D_global_asm_80750754 < 0) {
        return dl;
    }
    direction = D_global_asm_807506D0[D_global_asm_80750754].squish_from;
    temp_s0 = D_global_asm_80750818[direction];
    var_v1 = D_global_asm_80750828[direction] * D_global_asm_807FC8EC;
    var_v1 += ((D_global_asm_807FC8E8 - 0.5) * temp_s0);
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    sp104.data[direction] = var_v1;
    func_global_asm_805FEE84(sp104.data[1], sp104.data[3], sp104.data[0], sp104.data[2]);
    if (D_global_asm_807FC8E8 == 0.0f) {
        return dl;
    }
    temp_v0_2 = malloc(sizeof(Mtx));
    func_global_asm_8061134C(temp_v0_2);
    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gSPMatrix(dl++, 0x020000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, temp_v0_2, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    var_f12 = 1.0f;
    var_f2 = 1.0f;
    if (direction & 1) {
        // left/right
        var_f2 = D_global_asm_807FC8EC;
    } else {
        // top/bottom
        var_f12 = D_global_asm_807FC8EC;
    }
    guScaleF(spC4, var_f2 * 0.55, var_f12 * 0.55, 1.0f);
    switch (direction) {
    default:
        var_f0 = sp10C;
        break;
    case 0:
        // Top
        var_f0 = 160.0f;
        sp108 = (temp_s0 * D_global_asm_807FC8E8) + -55.0;
        break;
    case 2:
        // Bottom
        var_f0 = 160.0f;
        sp108 = 265.0 - (temp_s0 * D_global_asm_807FC8E8);
        break;
    case 1:
        // Left
        sp108 = 120.0f;
        var_f0 = ((temp_s0 * D_global_asm_807FC8E8) + -70.0) + 8.0;
        break;
    case 3:
        // Right
        sp108 = 120.0f;
        var_f0 = (390.0 - (temp_s0 * D_global_asm_807FC8E8)) - 8.0;
        break;
    }
    guTranslateF(sp84, (f32) ((f64) var_f0 * 4.0), (f32) ((f64) sp108 * 4.0), 0.0f);
    guMtxCatF(spC4, sp84, spC4);
    guMtxF2L(spC4, temp_v0_2);
    str = D_global_asm_807FC8F0;
    for (i = 0; i < D_global_asm_80750758; str++) {
        if (*str == '\0') i++;
    }
    y = D_global_asm_807506D0[D_global_asm_80750754].text_count * -35;
    for (i = 0; i < D_global_asm_807506D0[D_global_asm_80750754].text_count; i++) {
        var_s3 = printStyledText(var_s3, 1, ((getCenterOfString(1, str) * 2) * -1), y, str, 0U);
        y += 0x60;
        while (*str) str++;
        str++;
    }
    gSPPopMatrix(dl++, G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    return dl;
}
*/
