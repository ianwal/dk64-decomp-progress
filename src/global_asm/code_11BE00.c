#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern Struct80717D84 *D_minecart_80028C30;

extern SpriteData D_global_asm_8071FB54;
extern SpriteData D_global_asm_8071FEF4;
extern SpriteData D_global_asm_8071FFA0; // TODO: Datatype

extern s16 D_global_asm_807502D0;

extern Struct807FDB00 *D_global_asm_807FDB00;
extern Struct807FDB04 *D_global_asm_807FDB04;
extern Struct80717D84 *D_global_asm_807FDB08;
extern u8 D_global_asm_807FDB0C; // red
extern u8 D_global_asm_807FDB0D; // green
extern u8 D_global_asm_807FDB0E; // blue
extern u8 D_global_asm_807FDB0F; // alpha
extern s32 D_global_asm_807FDB10;
extern void *D_global_asm_807FDB14; // TODO: Function pointer
extern u8 D_global_asm_807FDB18;
extern s16 D_global_asm_807FDB1A;
extern u8 D_global_asm_807FDB1C;
extern u8 D_global_asm_807FDB1D;
extern f32 D_global_asm_807FDB20;
extern f32 D_global_asm_807FDB24;
extern u8 D_global_asm_807FDB28;
extern s32 D_global_asm_807FDB2C;
extern s32 D_global_asm_807FDB30;
extern u16 D_global_asm_807FDB34;
extern u16 D_global_asm_807FDB36;
extern s16 D_global_asm_807FDB38;
extern s16 D_global_asm_807FDB3A;
extern s16 D_global_asm_807FDB3C;
extern s16 D_global_asm_807FDB3E;
extern s16 D_global_asm_807FDB40;
extern s16 D_global_asm_807FDB42;

void func_global_asm_80714778(f32);
void func_global_asm_80714A9C(void);
void func_global_asm_80717404(otherSpriteControl *, s8 *);
void func_global_asm_80718380(Struct80717D84 *arg0, s8 *arg1);

// .data
static Struct80717D84_unk384_8071C9E8_sub6 D_global_asm_80755650[] = {
    { 0x01D4, 0x0078, 0x026D },
    { 0x01EE, 0x0082, 0x02F6 },
    { 0x02E5, 0x008C, 0x0254 },
    { 0x02C3, 0x0078, 0x02FA },
    { 0x025A, 0x006E, 0x0312 },
    { 0x025E, 0x0096, 0x026A },
};

static f32 D_global_asm_80755674 = -0.1f;
static f32 D_global_asm_80755678 = 2.0f;
static s8 D_global_asm_8075567C = 1;

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_80717100.s")

/*
void func_global_asm_80717100(otherSpriteControl *arg0, s8 *arg1) {
    Struct80717D84_unk384_80717100 *var_v1;

    if (arg0->unk384 == NULL) {
        var_v1 = arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80717100));
        var_v1->unk0 = (rand() >> 0xF) % 4095;
        var_v1->unk2 = arg0->unk35C;
        var_v1->unk4 = arg0->unk35C >> 0x10;
        var_v1->unk6 = arg0->xPos;
        var_v1->unk8 = arg0->zPos;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = var_v1->unk4 + var_v1->unk0;
    arg0->xPos = var_v1->unk6 + (var_v1->unk2 * func_global_asm_80612794(var_v1->unk0));
    arg0->zPos = var_v1->unk8 + (var_v1->unk2 * func_global_asm_80612790(var_v1->unk0));
}
*/

void func_global_asm_8071720C(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_8071720C *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071720C));
        var_v1 = arg0->unk384;
        var_v1->unk0 = (rand() >> 0xF) % 4095;
        var_v1->unk2 = RandClamp(10) + 2;
        var_v1->unk4 = 0;
        var_v1->unk6 = -0x32 - (RandClamp(10000) % 600);
    }
    var_v1 = arg0->unk384;
    arg0->unk344 -= (var_v1->unk6 / 100.0);
    var_v1->unk6 += 0x14;
    arg0->unk340 += (0.04 * var_v1->unk4 * func_global_asm_80612794(var_v1->unk0));
    arg0->unk348 += (0.04 * var_v1->unk4 * func_global_asm_80612790(var_v1->unk0));
    var_v1->unk0 += 0x50;
    var_v1->unk4 += var_v1->unk2;
    if (arg0->unk35C != 0) {
        func_global_asm_806595F0(1);
        createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 40.0f, 0, 0xFF, 0xFF, (rand() >> 0xF) % 255);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_80717404.s")

/*
void func_global_asm_80717404(otherSpriteControl *arg0, s8 *arg1) {
    s32 pad;
    f64 sp28;
    s16 *temp_s2;
    Struct80717D84_unk384_80717404 *var_s1;
    s32 r;

    temp_s2 = &arg0->unk35C;
    if (arg0->unk384 == NULL) {
        var_s1 = malloc(sizeof(Struct80717D84_unk384_80717404));
        arg0->unk384 = var_s1;
        if (temp_s2[0]) {
            var_s1->unk0 = (RandClamp(200) + temp_s2[0]) - 100;
        } else {
            var_s1->unk0 = (rand() >> 0xF) % 4095;
        }
        if (arg0->unk36F) {
            sp28 = 4.0;
        } else {
            sp28 = 1.0;
        }
        var_s1->unk4 = (RandClamp(10) + 5) * sp28;
        var_s1->unk8 = RandClamp(6) + temp_s2[1];
    }
    var_s1 = arg0->unk384;
    if (arg0->unk36F) {
        arg0->xPos += (4.0 * (0.01 * temp_s2[1] * func_global_asm_80612794(var_s1->unk0)));
        arg0->yPos += (4.0 * (0.01 * temp_s2[1] * func_global_asm_80612790(var_s1->unk0)));
    } else {
        arg0->xPos += (0.04 * temp_s2[1] * func_global_asm_80612794(var_s1->unk0));
        arg0->zPos += (0.04 * temp_s2[1] * func_global_asm_80612790(var_s1->unk0));
        if (!temp_s2[0]) {
            arg0->yPos += var_s1->unk8;
            var_s1->unk8 = var_s1->unk8 - 0.5;
        } else {
            arg0->yPos += (var_s1->unk8 * 0.2);
        }
    }
    temp_s2[1] += var_s1->unk4;
}
*/

void func_global_asm_80717760(Struct80717D84 *arg0, s8 *arg1) {
    s32 temp_v0;

    arg0->unk36D = 0;
    if (arg0->unk35C != 0) {
        arg0->unk35C--;
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(func_global_asm_80717404);
        func_global_asm_80714950(0xA);
        drawSpriteAtPosition(D_global_asm_8074E880[RandClamp(1000) % 3], 0.8f, arg0->unk340, arg0->unk344, arg0->unk348);
        return;
    }
    *arg1 = 1;
}

void func_global_asm_80717814(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_80717814 *temp_v0;
    Struct80717D84_unk384_80717814 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80717814));
        var_v1 = arg0->unk384_80717814;
        var_v1->unk0 = (rand() >> 0xF) % 4095;
        var_v1->unk2 = RandClamp(10) + 2;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 += (0.2 * arg0->unk35C * func_global_asm_80612794(var_v1->unk0));
    arg0->unk344 += (0.2 * arg0->unk35C * func_global_asm_80612790(var_v1->unk0));
    var_v1->unk0 += 0x46;
    arg0->unk35C += var_v1->unk2;
}

void func_global_asm_80717930(Struct80717D84 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 var_f6;
    Struct80717D84_unk384_80717930 *temp_s1;
    Actor *temp_v0_2;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80717930));
        temp_s1 = arg0->unk384;
        temp_s1->unk0 = (rand() >> 0xF) % 4095;
        temp_s1->unk2 = arg0->unk340;
        temp_s1->unk4 = arg0->unk348;
        if (arg0->unk35C & 0x8000) {
            arg0->unk35C &= 0xFFFF7FFF;
            temp_s1->unk6 = 0xC8;
            temp_s1->unk8 = 0xA;
        } else {
            temp_s1->unk6 = 0x46;
            temp_s1->unk8 = 0xF;
        }
        if (arg0->unk338 != NULL) {
            temp_f0 = arg0->unk338->animation_state->scale_y / 0.15;
            temp_s1->unk8 = temp_s1->unk8 * temp_f0;
            arg0->unk35C = arg0->unk35C * temp_f0;
        }
    }
    temp_s1 = arg0->unk384;
    if (arg0->unk38C & 2) {
        arg0->unk340 = player_pointer->x_position + (func_global_asm_80612794(temp_s1->unk0) * arg0->unk35C);
        arg0->unk348 = player_pointer->z_position + (func_global_asm_80612790(temp_s1->unk0) * arg0->unk35C);
    } else {
        arg0->unk340 = temp_s1->unk2 + (func_global_asm_80612794(temp_s1->unk0) * arg0->unk35C);
        arg0->unk348 = temp_s1->unk4 + (func_global_asm_80612790(temp_s1->unk0) * arg0->unk35C);
    }
    arg0->unk344 += (temp_s1->unk8 * 0.1);
    temp_s1->unk0 += temp_s1->unk6;
}

void func_global_asm_80717B64(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_80717B64 *var_v1;
    s32 var_v1_2;
    f32 temp_f16;
    f32 temp_f0_2;

    temp_f16 = (arg0->unk34C * 3) / 4;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(6);
        var_v1 = arg0->unk384;
        var_v1->unk0 = 0;
        var_v1->unk2 = arg0->unk330->unk16 * arg0->unk350;
        var_v1->unk4 = arg0->unk36D;
    }
    var_v1 = arg0->unk384;
    if (var_v1->unk2 == var_v1->unk0) {
        *arg1 = 1;
    } else {
        var_v1->unk0++;
    }
    temp_f0_2 = sqrtf(SQ(character_change_array->look_at_eye_z - arg0->unk348) + (SQ(character_change_array->look_at_eye_x - arg0->unk340) + SQ(character_change_array->look_at_eye_y - arg0->unk344)));
    if (temp_f0_2 < temp_f16) {
        arg0->unk36D = var_v1->unk4;
        return;
    }
    var_v1_2 = var_v1->unk4 * ((temp_f0_2 - temp_f16) / (arg0->unk34C - temp_f16));
    if (var_v1->unk4 < var_v1_2) {
        var_v1_2 = var_v1->unk4;
    }
    arg0->unk36D = var_v1->unk4 - var_v1_2;
}

void func_global_asm_80717CE8(Struct80717D84 *arg0, s32 arg1) {
    if (arg0->unk36D != 0xFF) {
        arg0->unk36D += 0x14;
    }
    if (arg0->unk36D >= 0xEB) {
        arg0->unk36D = 0xFF;
    }
    arg0->unk344 = arg0->unk344 - (arg0->unk35C / 100.0);
}

void func_global_asm_80717D4C(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk344 = arg0->unk344 - (arg0->unk35C / 100.0);
}

void func_global_asm_80717D84(Struct80717D84 *arg0, s8 *arg1) {
    if (arg0->unk35C < arg0->unk36D) {
        arg0->unk36D -= arg0->unk35C;
        return;
    }
    arg0->unk36D = 0;
    *arg1 = 1;
}

void func_global_asm_80717DB4(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384 *temp;
    if (arg0->unk384 == NULL) {
        temp = malloc(0x10);
        arg0->unk384 = temp;
        temp->unk0 = arg0->unk340;
        temp->unk4 = arg0->unk348;
        temp->unk8 = 0;
        temp->unkA = 0;
        temp->unkC = ((rand() % 10000) % 150) - 0x4B;
        temp->unkE = ((rand() % 10000) % 150) - 0x4B;
    }
    temp = arg0->unk384;
    arg0->unk340 = (func_global_asm_80612794(temp->unk8) * 6.0) + temp->unk0;
    arg0->unk348 = (func_global_asm_80612794(temp->unkA) * 6.0) + temp->unk4;
    temp->unk8 += temp->unkC;
    temp->unkA += temp->unkE;
    arg0->unk344 = arg0->unk344 - (arg0->unk35C / 100.0);
}

void func_global_asm_80717F1C(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_f32 *var_v0;
    Actor *temp_s0;
    f64 temp;

    if (arg0->unk384 == NULL) {
        temp_s0 = arg0->unk338;
        var_v0 = malloc(0x10);
        arg0->unk384 = var_v0;
        if (temp_s0 != NULL) {
            var_v0->unk0 = func_global_asm_80612794(temp_s0->unkEE) * (temp_s0->unkB8 * 0.025f);
            var_v0->unk4 = func_global_asm_80612790(temp_s0->unkEE) * (temp_s0->unkB8 * 0.025f);
        } else {
            var_v0->unk0 = 0.0f;
            var_v0->unk4 = 0.0f;
        }
        var_v0->unk8 = arg0->unk360;
        var_v0->unkC = 0.2f;
    }
    var_v0 = arg0->unk384;
    temp = 0.93;
    arg0->unk344 -= (arg0->unk35C / 100.0);
    arg0->unk340 += var_v0->unk0;
    arg0->unk348 += var_v0->unk4;
    var_v0->unk0 = var_v0->unk0 * temp;
    var_v0->unk4 = var_v0->unk4 * temp;
}

void func_global_asm_80718080(Struct80717D84 *arg0, s32 arg1) {
    func_global_asm_80717F1C(arg0, arg1);
    arg0->unk360 = arg0->unk384_f32->unkC * arg0->unk384_f32->unk8;
    arg0->unk364 = arg0->unk360;
    if (arg0->unk384_f32->unkC < 2.0f) {
        arg0->unk384_f32->unkC += 0.2;
    }
}

void func_global_asm_807180F4(Struct80717D84 *arg0, s32 arg1) {
    func_global_asm_80717D4C(arg0, arg1);
    func_global_asm_80716FB4(arg0, arg1);
}

void func_global_asm_80718124(f32 scale, f32 x, f32 y, f32 z) {
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_8071498C(func_global_asm_80718380);
    drawSpriteAtPosition(&D_global_asm_8071FEF4, scale, x, y, z);
}

void func_global_asm_80718188(Struct80717D84 *arg0, s8 *arg1) {
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(2);
        arg0->unk384_s16->unk0 = 0;
    }
    arg0->unk344 += arg0->unk384_s16->unk0;
    arg0->unk384_s16->unk0 -= 1;
    if (arg0->unk384_s16->unk0 < D_global_asm_807502D0) {
        arg0->unk384_s16->unk0 = D_global_asm_807502D0;
    }
    if (arg0->unk344 < arg0->unk35C) {
        *arg1 = 1;
        func_global_asm_80718124(arg0->unk360 * 1.5, arg0->unk340, arg0->unk35C, arg0->unk348);
    }
}

void func_global_asm_8071827C(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];

    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp70, sp30, sp70);
    guTranslateF(sp30, arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(sp70, sp30, sp70);
    arg0->unk360 += 0.07;
    arg0->unk364 += 0.07;
    if (arg0->unk36D >= 0xA) {
        arg0->unk36D -= 0xA;
    } else {
        arg0->unk36D = 0;
    }
    guMtxF2L(sp70, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

typedef struct {
    f32 unk0;
} Struct80717D84_unk384_80718380;

void func_global_asm_80718380(Struct80717D84 *arg0, s8 *arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80718380));
        *((f32*)arg0->unk384) = (func_global_asm_806119A0() % 36000U) / 100;
    }
    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp70, sp30, sp70);
    guRotateF(sp30, *((f32*)arg0->unk384), 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp70, sp30, sp70);
    guTranslateF(sp30, arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(sp70, sp30, sp70);
    if (arg0->unk36D >= 0xA) {
        arg0->unk36D -= 0xA;
    } else {
        arg0->unk36D = 0;
    }
    guMtxF2L(sp70, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
    if (arg0->unk36D == 0) {
        *arg1 = 1;
    }
}

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_807184F4;

void func_global_asm_807184F4(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    Actor *temp_v0_2;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        arg0->unk384_f32->unk0 = 0.0f;
        arg0->unk384_f32->unk4 = (func_global_asm_806119A0() % 400U) / 100;
    }
    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, arg0->unk384->unk0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp70, sp30, sp70);
    guRotateF(sp30, 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp70, sp30, sp70);
    temp_v0_2 = arg0->unk338;
    if (temp_v0_2 != NULL) {
        arg0->unk344 = temp_v0_2->unkAC;
    }
    guTranslateF(sp30, arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(sp70, sp30, sp70);
    guMtxF2L(sp70, arg0->unk128[D_global_asm_807444FC]);
    if (arg0->unk35C != 0) {
        arg0->unk384_f32->unk0 += arg0->unk384_f32->unk4;
        arg0->unk360 -= 0.02;
        arg0->unk364 -= 0.02;
        if (arg0->unk36D >= 0xA) {
            arg0->unk36D -= 0xA;
        } else {
            arg0->unk36D = 0;
        }
    }
    arg0->unk32C = 3;
}

// Matrix stuff
// rodata, close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_807186C8.s")

extern f32 D_807FDB50;
extern f32 D_807FDB54;
extern f32 D_807FDB58;

/*
void func_global_asm_807186C8(otherSpriteControl *arg0, s32 arg1) {
    Mtx spA0;
    Mtx sp60;
    tuple_f sp54;
    tuple_f sp48;
    tuple_f sp3C;
    s32 i;

    if (arg0->unk384_807186C8 == NULL) {
        arg0->unk384_807186C8 = malloc(sizeof(Struct80717D84_unk384_807186C8));
        arg0->unk384_807186C8->unk0 = 0.0f;
        arg0->unk384_807186C8->unk4.f[0] = D_807FDB50;
        arg0->unk384_807186C8->unk4.f[1] = D_807FDB54;
        arg0->unk384_807186C8->unk4.f[2] = D_807FDB58;
        arg0->unk384_807186C8->unk10.f[0] = arg0->xPos;
        arg0->unk384_807186C8->unk10.f[1] = arg0->yPos;
        arg0->unk384_807186C8->unk10.f[2] = arg0->zPOs;
        arg0->unk384_807186C8->unk1C = 0.01f;
        arg0->unk384_807186C8->unk20 = (func_global_asm_806119A0() % 36000U) / 100U;
        arg0->unk384_807186C8->unk24 = (func_global_asm_806119A0() % 400U) / 100U;
    }
    sp54.f[0] = arg0->unk384_807186C8->unk4.f[0];
    sp54.f[1] = arg0->unk384_807186C8->unk4.f[1];
    sp54.f[2] = arg0->unk384_807186C8->unk4.f[2];
    sp48.f[0] = arg0->unk384_807186C8->unk10.f[0];
    sp48.f[1] = arg0->unk384_807186C8->unk10.f[1];
    sp48.f[2] = arg0->unk384_807186C8->unk10.f[2];
    for (i = 0; i < 3; i++) {
        sp3C.f[i] = (arg0->unk384_807186C8->unk0 * (sp54.f[i] - sp48.f[i])) + sp48.f[i];
    }
    arg0->xPos = sp3C.f[0];
    arg0->yPos = sp3C.f[1];
    arg0->zPos = sp3C.f[2];
    arg0->unk384_807186C8->unk0 += arg0->unk384_807186C8->unk1C;
    arg0->unk384_807186C8->unk1C += 0.001;
    arg0->xScale *= 0.975;
    arg0->yScale *= 0.975;
    arg0->unk384_807186C8->unk20 += arg0->unk384_807186C8->unk24;
    guScaleF(&spA0, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp60, arg0->unk384_807186C8->unk20, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&spA0, &sp60, &spA0);
    guMtxF2L(&spA0, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

void func_global_asm_807189BC(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_807189BC *var_v1;
    Actor *sp20;

    sp20 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = MAX(2.0, sp20->unkB8 * 0.01);
        var_v1->unk2 = sp20->y_rotation;
        var_v1->unk4 = RandClamp(1000) + 0xC8;
        arg0->unk360 += (RandClamp(100) / 500.0);
        arg0->unk364 = arg0->unk360;
        var_v1->unk6 = sp20->unkAC;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 -= (var_v1->unk0 * func_global_asm_80612794(var_v1->unk2));
    arg0->unk348 -= (var_v1->unk0 * func_global_asm_80612790(var_v1->unk2));
    arg0->unk344 += (var_v1->unk4 / 500.0);
    if (var_v1->unk6 <= arg0->unk344) {
        *arg1 = 1;
        func_global_asm_80718124(arg0->unk360 * 1.5, arg0->unk340, var_v1->unk6, arg0->unk348);
    }
    if (arg0->unk36D >= 0xC) {
        arg0->unk36D -= 0xA;
        return;
    }
    *arg1 = 1;
    arg0->unk36D = 0;
}

void func_global_asm_80718BF4(otherSpriteControl *arg0, s8 *arg1) {
    f64 temp_f8;
    f32 sp3C;
    f32 temp_f6;
    f32 var_f2;
    f32 sp30;

    if (arg0->unk384_80718BF4 == NULL) {
        arg0->unk384_80718BF4 = malloc(sizeof(Struct80717D84_unk384_80718BF4));
        arg0->unk384_80718BF4->unk0 = 0.0f;
        arg0->unk384_80718BF4->unk4 = 0.0f;
        arg0->unk384_80718BF4->unk8 = arg0->xPos;
        arg0->unk384_80718BF4->unkC = arg0->zPos;
        arg0->unk384_80718BF4->unk10 = (((func_global_asm_806119A0() % 10000U) / 10000.0) * 0.19);
        arg0->unk384_80718BF4->unk14 = (((func_global_asm_806119A0() % 10000U) / 10000.0) * 0.077);
        if ((func_global_asm_806119A0() / 10000U) & 1) {
            arg0->unk384_80718BF4->unk10 = 0.0 - arg0->unk384_80718BF4->unk10;
            arg0->unk384_80718BF4->unk14 = 0.0 - arg0->unk384_80718BF4->unk14;
        }
        sp30 = arg0->yPos;
        func_global_asm_80667110(arg0->xPos, arg0->zPos, &sp30);
        if (func_global_asm_8066715C(&arg0->unk384_80718BF4->unk18) == 0) {
            arg0->unk384_80718BF4->unk18 = 0.0f;
        }
        arg0->unk384_80718BF4->unk1C = object_timer;
    }
    sp3C = func_global_asm_80612D1C(arg0->unk384_80718BF4->unk10 * arg0->unk384_80718BF4->unk0);
    temp_f6 = func_global_asm_80612D1C(arg0->unk384_80718BF4->unk14 * arg0->unk384_80718BF4->unk0) * 6.0f;
    arg0->xPos = arg0->unk384_80718BF4->unk8 + (sp3C * 6.0f);
    arg0->zPos = arg0->unk384_80718BF4->unkC + temp_f6;
    arg0->unk384_80718BF4->unk0++;
    arg0->unk384_80718BF4->unk4 += 0.02;
    if (arg0->unk384_80718BF4->unk4 > 1.0) {
        arg0->unk384_80718BF4->unk4 = 1.0f;
    }
    arg0->yPos += arg0->unk384_80718BF4->unk4;
    switch (arg0->unk35C) {
    case 0:
        arg0->xScale = (arg0->unk384_80718BF4->unk0 * 0.01) + 0.01;
        if (arg0->xScale > 0.12) {
            arg0->xScale = 0.12;
        }
        break;
    case 1:
        arg0->xScale = (arg0->unk384_80718BF4->unk0 * 0.005) + 0.05;
        if (arg0->xScale > 0.07) {
            arg0->xScale = 0.07;
        }
        break;
    case 2:
        arg0->xScale = (arg0->unk384_80718BF4->unk0 * 0.02) + 0.02;
        if (arg0->xScale > 0.24) {
            arg0->xScale = 0.24;
        }
        break;
    }
    arg0->yScale = arg0->xScale;
    sp3C = func_global_asm_80612D1C(arg0->unk384_80718BF4->unk0 * 0.17);
    temp_f8 = func_global_asm_80612D1C(arg0->unk384_80718BF4->unk0 * 0.2267) * 0.03;
    arg0->xScale += (sp3C * 0.03);
    arg0->yScale += temp_f8;
    if ((arg0->unk384_80718BF4->unk1C + 100.0f) < object_timer) {
        *arg1 = 1;
    }
    if (arg0->unk384_80718BF4->unk18 <= arg0->yPos) {
        *arg1 = 1;
        func_global_asm_80718124(0.3f, arg0->xPos, arg0->yPos, arg0->zPos);
    }
}



extern SpriteData D_global_asm_8072073C;
extern SpriteData D_global_asm_807212B0;
extern SpriteData D_global_asm_807212C8;

void func_global_asm_8071910C(otherSpriteControl *arg0, s32 arg1) {
    Mtx sp98;
    Mtx sp58;
    f32 sp54;
    f32 var_f0; // 50
    f32 sp4C;
    f32 var_f16;
    f32 sp44;
    s16 var_a3;

    if (arg0->unk384_8071910C == NULL) {
        arg0->unk384_8071910C = malloc(sizeof(Struct80717D84_unk384_8071910C));
        arg0->unk384_8071910C->unk0 = (f32) (((f64) (f32) ((u32) (func_global_asm_806119A0() / 10000U) % 100U) / 25.0) + 5.0 + ((f64) ((s32) arg0->unk35C >> 8) * 3.0));
        var_f16 = (func_global_asm_806119A0() / 10000U) % 1000U;
        sp54 = (var_f16 / 500.0f) + (f32) (arg0->unk35C & 0xFF);
        var_f0 = (func_global_asm_806119A0() / 10000U) % 360U;
        sp4C = func_global_asm_80612D1C(var_f0 * (MATH_PI_F / 180.0f)) * sp54;
        var_f0 = func_global_asm_80612D10(var_f0 * (MATH_PI_F / 180.0f));
        arg0->unk384_8071910C->unk4 = sp4C;
        arg0->unk384_8071910C->unk8 = var_f0 * sp54;
        arg0->unk384_8071910C->unkC = (func_global_asm_806119A0() % 36000U) / 100U;
        sp44 = arg0->yPos;
        if (func_global_asm_80667110(arg0->xPos, arg0->zPos, &sp44) != 0) {
            arg0->unk384_8071910C->unk10 = sp44;
        } else {
            arg0->unk384_8071910C->unk10 = 0.0f;
        }
        arg0->unk384_8071910C->unk14 = 0;
    }
    arg0->unk384_8071910C->unk0 += -0.63;
    arg0->xPos += arg0->unk384_8071910C->unk4;
    arg0->zPos += arg0->unk384_8071910C->unk8;
    arg0->yPos += arg0->unk384_8071910C->unk0;
    if (arg0->yPos < arg0->unk384_8071910C->unk10) {
        var_a3 = 0x56;
        if (arg0->unk330->unk0 == &D_global_asm_8072073C) {
            var_a3 = 0x1B1;
        } else if ((arg0->unk330->unk0 == &D_global_asm_807212C8) || (arg0->unk330->unk0 == &D_global_asm_807212B0)) {
            var_a3 = 7;
        }
        playSoundAtPosition(arg0->xPos, arg0->yPos, arg0->zPos, var_a3, arg0->transparency4 * 0.7, 0x96, 1U, 0x4BU, 0.3f, 0U);
        arg0->unk384_8071910C->unk0 = 5.0f;
        if (arg0->unk384_8071910C->unk14 != 2) {
            arg0->unk384_8071910C->unk14++;
        }
    }
    if (arg0->unk384_8071910C->unk14 == 2) {
        if (arg0->transparency4 >= 0xB) {
            arg0->transparency4 -= 0xA;
        } else {
            arg0->transparency4 = 0U;
        }
    }
    arg0->unk384_8071910C->unkC += 5.9;
    guScaleF(&sp98, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp58, arg0->unk384_8071910C->unkC, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp98, &sp58, &sp98);
    guMtxF2L(&sp98, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

// rodata, regalloc, float, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_807195D4.s")

/*
void func_global_asm_807195D4(otherSpriteControl *arg0, s32 arg1) {
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 sp6C[4][4];
    f32 sp2C[4][4];

    if (arg0->unk384_807195D4 == NULL) {
        arg0->unk384_807195D4 = malloc(sizeof(Struct80717D84_unk384_807195D4));
        arg0->unk384_807195D4->unk0 = arg0->unk35C * 2;
        arg0->unk384_807195D4->unk4 = 0.0f;
        arg0->transparency4 = 0;
    }
    if (arg0->transparency4 >= 0xDD) {
        arg0->transparency4 = 0xFF;
    } else {
        arg0->transparency4 += 0x14;
    }
    spB0 = func_global_asm_80612D1C(arg0->unk384_807195D4->unk0 * 0.01745329238f) * 2.5;
    spAC = func_global_asm_80612D10(arg0->unk384_807195D4->unk0 * 0.01745329238f) * 2.5;
    arg0->xPos += spB0;
    arg0->yPos += 3.5;
    arg0->zPos += spAC;
    arg0->unk384_807195D4->unk0 += 8.0;
    arg0->unk384_807195D4->unk4 += 7.3;
    guScaleF(sp6C, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(sp2C, arg0->unk384->unk4, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp6C, sp2C, sp6C);
    guMtxF2L(sp6C, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

void func_global_asm_807197B4(otherSpriteControl *arg0, s32 arg1) {
    f32 sp78[4][4];
    f32 sp3C[15];
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 temp;

    if (arg0->unk384_807197B4 == NULL) {
        arg0->unk384_807197B4 = malloc(sizeof(Struct80717D84_unk384_807197B4));
        arg0->unk384_807197B4->unk0 = 0;
        arg0->unk384_807197B4->unk4 = arg0->xScale;
        arg0->unk384_807197B4->unk8 = arg0->yScale;
    }
    arg0->unk384_807197B4->unk4 += 0.0015;
    arg0->unk384_807197B4->unk8 += 0.0015;
    sp2C = func_global_asm_80612D1C(arg0->unk35C * 2) * 0.2;
    sp30 = func_global_asm_80612D10(arg0->unk35C * 2) * 0.2;
    arg0->xPos -= sp2C;
    arg0->yPos += 0.119999999999999996;
    arg0->zPos -= sp30;
    arg0->xScale = arg0->unk384_807197B4->unk4;
    arg0->yScale = arg0->unk384_807197B4->unk8;
    sp34 = func_global_asm_80612D1C(arg0->unk384_807197B4->unk0 * 0.17);
    sp38 = func_global_asm_80612D1C(arg0->unk384_807197B4->unk0 * 0.2267);
    arg0->xScale *= (1.0 + (sp34 * 0.15));
    arg0->yScale *= (1.0 + (sp38 * 0.15));
    arg0->unk384_807197B4->unk0++;
    if ((arg0->unk354 - arg0->unk358) < 0xA) {
        if (arg0->transparency4 >= 0x16) {
            arg0->transparency4 -= 0x14;
        } else {
            arg0->transparency4 = 0;
        }
    }
    guScaleF(sp78, arg0->xScale, arg0->yScale, 0.0f);
    guMtxF2L(sp78, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

void func_global_asm_80719A0C(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp;
    f32 *temp_v0;
    f32 *var_v1;
    f32 temp2;

    if (arg0->unk384 == NULL) {
        temp_v0 = malloc(8);
        arg0->unk384 = temp_v0;
        temp_v0[0] = (arg0->unk360 / 0.36) * 2.5;
        temp_v0[1] = (object_timer * 0x28U) + (arg0->unk35C << 9);
    }
    var_v1 = arg0->unk384;
    var_v1[0] -= 0.2;
    if (var_v1[0] < 0.8) {
        var_v1[0] = 0.8f;
    }
    temp = func_global_asm_80612794(var_v1[1]) * var_v1[0];
    temp2 = func_global_asm_80612790(var_v1[1]) * var_v1[0];
    arg0->unk340 += temp;
    arg0->unk348 += temp2;
}

void func_global_asm_80719B88(Struct80717D84 *arg0, s8 *arg1) {
    func_global_asm_80719A0C(arg0, arg1);
    arg0->unk344 += 0.8;
    arg0->unk36D -= MIN(arg0->unk36D, 0x10);
    if (!(arg0->unk36D)) {
        *arg1 = 1;
    }
}

void func_global_asm_80719C00(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_80719C00 *var_v1;
    f32 var_f2;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80719C00));
        var_v1 = arg0->unk384;
        var_v1->unk0 = arg0->unk340;
        var_v1->unk4 = arg0->unk348;
        var_v1->unk8 = 0.0f;
        var_v1->unkC = arg0->unk35C * 455.1111145f;
        var_v1->unk10 = ((arg0->unk35C % 3) * 0x64) - 0x64;
        var_v1->unk14 = 375.0f;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += 0.3;
    if (var_v1->unk14 < 15.0f) {
        var_f2 = var_v1->unk14;
    } else {
        var_f2 = 15.0f;
    }
    var_v1->unk14 -= var_f2;
    arg0->unk36D = MIN(255.0f, var_v1->unk14);
    var_v1->unk8 += 1.5;
    var_v1->unkC += var_v1->unk10;
    arg0->unk340 = (func_global_asm_80612794(var_v1->unkC) * var_v1->unk8) + var_v1->unk0;
    arg0->unk348 = (func_global_asm_80612790(var_v1->unkC) * var_v1->unk8) + var_v1->unk4;
    if (arg0->unk36D == 0) {
        *arg1 = 1;
    }
}

void func_global_asm_80719EF4(Struct80717D84 *arg0, s32 arg1) {
    f32 sp1C;
    f32 temp_f2;
    f32 temp;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80719EF4));
        arg0->unk384->unk0 = 3.2f;
        arg0->unk384->unk4 = arg0->unk35C;
    }
    arg0->unk384->unk0 -= 0.2;
    if (arg0->unk384->unk0 < 0.8) {
        arg0->unk384->unk0 = 0.8f;
    }
    temp = func_global_asm_80612D1C((MATH_PI_F / 180.0f) * arg0->unk384->unk4);
    sp1C = (temp * arg0->unk384->unk0);
    temp = func_global_asm_80612D10((MATH_PI_F / 180.0f) * arg0->unk384->unk4);
    temp_f2 = (temp * arg0->unk384->unk0);
    arg0->unk340 += sp1C;
    arg0->unk348 += temp_f2;
    arg0->unk344 += 1.0f;
}

void func_global_asm_8071A038(Struct80717D84 *arg0, s32 arg1) {
    f32 sp78[4][4];
    f32 sp38[4][4];
    f32 sp34;
    f32 temp_f0;
    u8 *temp_v0;
    s32 pad;
    f32 sp24;

    temp_f0 = (arg0->unk34E * 2) + arg0->unk351;
    temp_v0 = arg0->unk35C;
    if (temp_f0 < 28.0f) {
        sp34 = temp_f0;
    } else {
        sp34 = 56.0f - temp_f0;
    }
    if (*temp_v0 != 0) {
        arg0->unk340 = arg0->unk340 - 12.0f;
        *temp_v0 -= 1;
    }
    sp24 = ABS(func_global_asm_80612D1C((temp_f0 / 56.0) * 6.28318548202514648));
    guScaleF(sp78, arg0->unk360, arg0->unk364, 0.0f);
    guTranslateF(sp38, arg0->unk340 + (sp34 * 0.5), arg0->unk344 - (sp24 * 15.0f), arg0->unk348);
    guMtxCatF(sp78, sp38, sp78);
    guMtxF2L(sp78, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

// regalloc, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071A1E4.s")

/*
void func_global_asm_8071A1E4(otherSpriteControl *arg0, s8 *arg1) {
    tuple_f *var_v0;
    s32 pad;
    s32 pad2;
    f32 sp8C[4][4];
    f32 sp4C[4][4];
    s8 sp4B;
    s8 sp4A;
    s8 sp49;
    s8 sp48;
    s16 sp46;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    if (arg0->unk384_tuplef == NULL) {
        sp48 = -(func_global_asm_806119A0() / 10000U) % 30;
        sp46 = (func_global_asm_806119A0() / 10000U) % 180;
        guRotateF(&sp8C, sp48, 0.0f, 1.0f, 0.0f);
        // TODO: Regalloc here, arg0->unk35C is using v0 instead of t5
        sp4B = arg0->unk35C >> 0x10;
        sp4A = arg0->unk35C >> 8;
        sp49 = arg0->unk35C;
        arg0->unk384_tuplef = malloc(sizeof(tuple_f));
        guAlignF(sp4C, sp46, sp4B, sp4A, sp49);
        guMtxCatF(sp8C, sp4C, sp8C);
        guMtxXFMF(sp8C, 0.0f, 0.0f, -2.0f, &sp40, &sp3C, &sp38);
        arg0->unk384_tuplef->x = sp40 * 0.5;
        if (sp3C < 0.0f) {
            arg0->unk384_tuplef->y = -sp3C * 0.5;
        } else {
            arg0->unk384_tuplef->y = sp3C * 0.5;
        }
        arg0->unk384_tuplef->z = sp38 * 0.5;
    }
    arg0->xPos += arg0->unk384_tuplef->x;
    arg0->yPos += arg0->unk384_tuplef->y;
    arg0->zPos += arg0->unk384_tuplef->z;
    if ((arg0->unk354 - arg0->unk358) < 0xA) {
        arg0->unk384_tuplef->y -= 0.1;
        if (arg0->transparency4 >= 0x16) {
            arg0->transparency4 -= 0x14;
            return;
        }
        arg0->transparency4 = 0;
    }
}
*/

void func_global_asm_8071A440(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    if (extra_player_info_pointer->vehicle_actor_pointer == arg0->unk35C_actor) {
        if (arg0 == D_minecart_80028C30) {
            func_global_asm_806595F0(1);
            createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f0 * 50.0, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
        }
    }
}

extern otherSpriteControl *D_8002FBB0[];

void func_global_asm_8071A674(otherSpriteControl *arg0, s8 *arg1) {
    // Race overlay only (uses unprotected reference to an array in the race overlay)
    f32 var_f0;
    s32 i;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    for (i = 0; i < 4; i++) {
        if (D_8002FBB0[i] == arg0) {
            func_global_asm_806595F0(1);
            createLight(
                arg0->xPos, arg0->yPos, arg0->zPos,
                0.0f, 0.0f, 0.0f,
                var_f0 * 50.0, 0, 0xFF,
                (-80.0f * var_f0) + 255.0f,
                (-205.0f * var_f0) + 255.0f);
            return;
        }
    }
}

void func_global_asm_8071A8B0(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f16;
    s16 temp_v0;

    temp_v0 = arg0->unk330->unk16;
    var_f0 = (f32)(temp_v0 - arg0->unk34E) / temp_v0;
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    // TODO: What's going on here...?
    if (((u32)arg0->unk35C >> 0x10) != 0) {
        var_f16 = (arg0->unk35C & 0xFFFF) * var_f0;
    } else {
        var_f16 = arg0->unk35C & 0xFFFF;
    }
    func_global_asm_806595F0(1);
    createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f16, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
}

void func_global_asm_8071AADC(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f2;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    if (((u32)arg0->unk35C >> 0x10) != 0) {
        var_f2 = (arg0->unk35C & 0xFFFF) * var_f0;
    } else {
        var_f2 = arg0->unk35C & 0xFFFF;
    }
    func_global_asm_806595F0(1);
    createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f2, 0, 0xFF, 0xFF, 0xFF);
}

// Close, regalloc, float
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071ABDC.s")

/*
void func_global_asm_8071ABDC(otherSpriteControl *arg0, s8 *arg1) {
    Mtx sp80; // Unused
    Mtx sp40; // Unused
    // sp3c
    f32 sp38;
    // sp34
    f32 sp30;
    u16 temp;
    s16 temp_t9; // 2C
    f32 sp28;
    f32 temp_f12; // 24

    if (arg0->unk384_8071ABDC == NULL) {
        arg0->unk384_8071ABDC = malloc(sizeof(Struct80717D84_unk384_8071ABDC));
        temp_t9 = (arg0->unk35C >> 0x10) & 0xFF;
        if (temp_t9 == 0) {
            sp28 = (func_global_asm_806119A0() / 10000) % 100;
            arg0->unk384_8071ABDC->unk0 = ((sp28 / 20.0) - 2.5);
        } else {
            sp28 = (func_global_asm_806119A0() / 10000) % 100;
            arg0->unk384_8071ABDC->unk0 = ((sp28 / 10.0) - 2.5);
        }
        temp_f12 = ((arg0->unk35C & 0xFFFF) * 0x1E) * 0.017453292f;
        sp38 = func_global_asm_80612D1C(temp_f12) * 2.5;
        temp_f12 = func_global_asm_80612D10(temp_f12) * 2.5;
        arg0->unk384_8071ABDC->unk4 = sp38;
        arg0->unk384_8071ABDC->unk8 = temp_f12;
        switch (temp_t9) {
            case 2:
                arg0->unk384_8071ABDC->unk4 *= 4;
                arg0->unk384_8071ABDC->unk8 *= 4;
                break;
            case 1:
                arg0->unk384_8071ABDC->unk4 *= 2;
                arg0->unk384_8071ABDC->unk8 *= 2;
                break;
        }
        sp30 = arg0->yPos;
        if (func_global_asm_80667110(arg0->xPos, arg0->zPos, &sp30)) {
            arg0->unk384_8071ABDC->unkC = sp30;
        } else {
            arg0->unk384_8071ABDC->unkC = 0.0f;
        }
    }
    if (arg0->unk34E >= 9) {
        arg0->unk384_8071ABDC->unk0 += -0.63;
        arg0->unk384_8071ABDC->unk4 *= 0.9;
        arg0->unk384_8071ABDC->unk8 *= 0.9;
    }
    if (arg0->unk34E >= ((arg0->unk35C >> 0x18) & 0xFF)) {
        if (arg0->transparency4 >= 0x3C) {
            arg0->transparency4 -= 0x3C;
        } else {
            arg0->transparency4 = 0U;
        }
    }
    arg0->xPos += arg0->unk384_8071ABDC->unk4;
    arg0->zPos += arg0->unk384_8071ABDC->unk8;
    arg0->yPos += arg0->unk384_8071ABDC->unk0;
    if (arg0->yPos < arg0->unk384_8071ABDC->unkC) {
        *arg1 = 1;
    }
}
*/


void func_global_asm_8071AF30(Struct80717D84 *arg0, s8 *arg1) {
    f32 sp78[4][4];
    f32 sp38[4][4];
    s32 sp34;
    Actor *temp_s1;

    temp_s1 = arg0->unk35C_actor;
    if (temp_s1->object_properties_bitfield & 4) {
        if (arg0->unk384 == NULL) {
            arg0->unk384 = malloc(0x40);
            sp34 = (func_global_asm_806119A0() % 36000U) / 100;
            guScaleF(sp78, arg0->unk360, arg0->unk364, 0.0f);
            guRotateF(&sp38[0], sp34, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp78, sp38, sp78);
            guMtxF2L(sp78, arg0->unk384);
            arg0->unk36D = 0xC8;
        }
        if (temp_s1->unk58 == ACTOR_CUTSCENE_DIDDY && arg0->unk360 < 0.5) {
            arg0->unk340 -= (10.0 * arg0->unk360 * func_global_asm_80612794(temp_s1->unkEE));
            arg0->unk348 -= (10.0 * arg0->unk360 * func_global_asm_80612790(temp_s1->unkEE));
        } else {
            arg0->unk340 += (temp_s1->unkB8 * 0.003 * func_global_asm_80612794(temp_s1->unkEE));
            arg0->unk348 += (temp_s1->unkB8 * 0.003 * func_global_asm_80612790(temp_s1->unkEE));
            arg0->unk344 -= 0.1;
        }
        if (temp_s1->unk58 == ACTOR_CUTSCENE_OBJECT) {
            arg0->unk344 -= 0.6;
        }
        memcpy(arg0->unk128[D_global_asm_807444FC], arg0->unk384, 0x40);
        arg0->unk32C = 2;
        return;
    }
    *arg1 = 1;
}

void func_global_asm_8071B1AC(Struct80717D84 *arg0, s32 arg1) {
    f32 temp = 0.35f;
    arg0->unk344 -= (temp * 0.5);
    arg0->unk340 += (0.35f * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (0.35f * func_global_asm_80612790(arg0->unk35C));
}

void func_global_asm_8071B24C(Struct80717D84 *arg0, s32 arg1) {
    f32 temp = 0.35f;
    arg0->unk344 += (temp * 0.5);
    arg0->unk340 += (0.35f * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (0.35f * func_global_asm_80612790(arg0->unk35C));
}

void func_global_asm_8071B2EC(Struct80717D84 *arg0, s32 arg1) {
    f32 sp24;
    Struct80717D84_unk384_8071B2EC *var_v1;
    f32 temp;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = arg0->unk338->unkEE;
        arg0->unk384->unk4 = arg0->unk338->unkB8 + 30.0f;
    }
    var_v1 = arg0->unk384;
    temp = 0.35f;
    arg0->unk344 += (temp * 0.5);
    sp24 = var_v1->unk4 * 0.02;
    arg0->unk340 += (sp24 * func_global_asm_80612794(var_v1->unk0));
    arg0->unk348 += (sp24 * func_global_asm_80612790(arg0->unk384->unk0));
    arg0->unk384->unk4 -= 15.0f;
    if (arg0->unk384->unk4 < 0.0f) {
        arg0->unk384->unk4 = 0.0f;
    }
}

void func_global_asm_8071B44C(Struct80717D84 *arg0, s32 arg1) {
    f32 temp_f6;
    f32 *var_v1;
    f32 temp;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk338->unkB8;
    }
    var_v1 = arg0->unk384;
    temp = 0.35f;
    arg0->unk344 += (temp * 0.5);
    temp_f6 = *var_v1 * 0.02;
    arg0->unk340 += (temp_f6 * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (temp_f6 * func_global_asm_80612790(arg0->unk35C));
}

void func_global_asm_8071B520(otherSpriteControl *arg0, s8 *arg1) {
    Mtx sp80;
    Mtx sp40;
    f32 sp3C;
    f32 var_f2;
    f32 temp1;
    u16 temp2;

    sp3C = arg0->yPos;
    if (!func_global_asm_80667110(arg0->xPos, arg0->zPos, &sp3C) || (ABS(sp3C - arg0->yPos) > 10.0)) {
        temp1 = arg0->unk34E + ((f32)arg0->unk351 / arg0->gif_update_frequency);
        if (arg0->unk34E > 6) {
            arg0->yPos -= (0.3 * ((14 - (s32)(20.0f - temp1)) / 14.0));
        }
    }
    if (arg0->unk34E == 16) {
        arg0->gif_update_frequency = 10;
    }
    guScaleF(&sp80, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp40, (arg0->unk35C * 360) / 4096, 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp80, &sp40, &sp80);
    guTranslateF(&sp40, arg0->xPos, arg0->yPos, arg0->zPos);
    guMtxCatF(&sp80, &sp40, &sp80);
    guMtxF2L(&sp80, &arg0->unk128[D_global_asm_807444FC]);
    if (arg0->unk34E >= 0x13) {
        arg0->transparency4 -= 0x14;
    }
    arg0->unk32C = 3;
}

void func_global_asm_8071B758(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    u8 temp_t0;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    temp_t0 = ((-155.0f * var_f0) + 255.0f);
    createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 50.0f, 0, temp_t0, temp_t0, temp_t0);
}

void func_global_asm_8071B89C(Struct80717D84 *arg0, s32 arg1) {
    f32 temp_f0;
    s16 var_v0;

    var_v0 = arg0->unk34E;
    if (var_v0 >= 5) {
        var_v0 = 4;
    }
    temp_f0 = (var_v0 / (4.0f / 1.0f)) * 3.0;
    arg0->unk360 = temp_f0;
    arg0->unk364 = temp_f0;
}

void func_global_asm_8071B8EC(Struct80717D84 *arg0, s8 *arg1) {
    if (arg0->unk358 == 0) {
        if (arg0->unk36D < 0xE1) {
            arg0->unk36D += 0x1E;
        } else {
            arg0->unk36D = 0xFF;
        }
    }
    if ((arg0->unk34E == 3) || (arg0->unk34E == 0x11) || (arg0->unk34E == 0x15)) {
        playSoundAtPosition(arg0->unk340, arg0->unk344, arg0->unk348, 0x14F, 0xFF, 0x7F, 0x1E, 0x4B, 0.3f, 0);
    }
    if ((arg0->unk354 - arg0->unk358) < 3) {
        if (arg0->unk36D >= 0xB) {
            arg0->unk36D -= 0xA;
            return;
        }
        *arg1 = 1;
        return;
    }
    if (RandClamp(100) >= 0x5B) {
        func_global_asm_80714998(3);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_80714950(-0xA);
        func_global_asm_807149B8(1);
        changeActorColor(0x9B, 0x9B, 0x9B, 0x96);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, 0.8f, (RandClamp(65535) & 7) + arg0->unk340, arg0->unk344 + 10.0f, (RandClamp(65535) & 7) + arg0->unk348);
    }
}

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_8071BB14;

void func_global_asm_8071BB14(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    Struct80717D84_unk384_8071BB14 *var_v1;

    var_v1 = arg0->unk384;
    if (var_v1 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071BB14));
        arg0->unk384->unk0 = ((func_global_asm_806119A0() % 36000U) / 100);
        arg0->unk384->unk4 = (func_global_asm_806119A0() % 10000U) / 7000.0;
        var_v1 = arg0->unk384;
    }
    arg0->unk344 = arg0->unk344 + (var_v1->unk4 + 1.0);
    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, arg0->unk384->unk0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp70, sp30, sp70);
    guMtxF2L(sp70, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_8071BC80;

void func_global_asm_8071BC80(Struct80717D84 *arg0, s32 arg1) {
    f32 sp90[4][4];
    f32 sp50[4][4];
    Struct80717D84_unk384_8071BC80 *var_v0;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    var_v0 = arg0->unk384;
    if (var_v0 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071BC80));
        guRotateF(sp90, -(f32)((func_global_asm_806119A0() % 36000U) / 1000), 1.0f, 0.0f, 0.0f);
        guRotateF(sp50, (arg0->unk35C * 0x168) / 4096, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp90, sp50, sp90);
        guMtxXFMF(sp90, 0.0f, 0.0f, 10.0f, &sp48, &sp44, &sp40);
        arg0->unk384_f32->unk0 = sp48;
        arg0->unk384_f32->unk4 = sp44;
        arg0->unk384_f32->unk8 = sp40;
    }
    var_v0 = arg0->unk384;
    arg0->unk340 += var_v0->unk0;
    arg0->unk344 += var_v0->unk4;
    arg0->unk348 += var_v0->unk8;
}

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    u8 unk4;
} Struct80717D84_unk35C_unk14;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    Struct80717D84_unk35C_unk14 *unk14;
} Struct80717D84_unk35C;

void func_global_asm_8071BE04(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    f32 var_f12;
    Struct80717D84_unk35C *sp28;
    Struct80717D84_unk35C_unk14 *sp24;
    f32 sp20;

    sp28 = arg0->unk35C;
    sp24 = sp28->unk14;
    sp20 = func_global_asm_80612794(sp28->unk10);
    arg0->unk36D = sp24->unk0 * sp20;
    sp20 = (1.0f - sp20);
    var_f12 = arg0->unk364;
    if (sp24->unk4 != 0) {
        var_f12 = arg0->unk364 * ((func_global_asm_80612794(sp24->unk2) * 0.15) + 0.85);
        sp24->unk2 += 0xAA;
        sp24->unk2 &= 0xFFF;
    }
    guScaleF(sp70, arg0->unk360, var_f12, 0.0f);
    guTranslateF(sp30, arg0->unk340 + (sp28->unk4 * sp20), arg0->unk344 + (sp28->unk8 * sp20), arg0->unk348);
    guMtxCatF(sp70, sp30, sp70);
    guMtxF2L(sp70, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

extern SpriteData D_global_asm_807201D4; // TODO: Datatype
void func_global_asm_8071C24C(Struct80717D84 *arg0, u8 *arg1);

void func_global_asm_8071C004(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp_f0;
    s32 pad3;
    s32 pad2;
    s16 sp44[3];
    f32 temp;
    f32 temp2;

    if (current_map == MAP_HELM_LOBBY) {
        sp44[0] = 0xFF;sp44[1] = 0x46;sp44[2] = 0;
    } else {
        sp44[0] = 0xFF;sp44[1] = 0xFF;sp44[2] = 0xFF;
    }
    switch (arg0->unk35C) {
        case 0:
            if ((arg0->unk34E == 0xA) && (arg0->unk351 == 0)) {
                playSoundAtPosition(arg0->unk340, arg0->unk344, arg0->unk348, 0xE4, 0xFF, 0x7F, 0x1E, 0x46, 9.0f, 0);
                func_global_asm_807149FC(-1);
                func_global_asm_807149B8(1);
                func_global_asm_8071498C(func_global_asm_8071C24C);
                drawSpriteAtPosition(&D_global_asm_807201D4, 0.8f, arg0->unk340, arg0->unk344, arg0->unk348);
            } else {
                temp_f0 = arg0->unk330->unk16 * 2;
                temp2 = (((arg0->unk34E * 2) + arg0->unk351));
                temp =  1.0 - ((temp_f0 - temp2) / temp_f0);
                temp = 200.0f * temp;
                createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0, 0, 0, temp, 0, 0xFF, sp44[1], sp44[2]);
            }
            break;
        case 1:
            temp_f0 = arg0->unk330->unk16 * 2;
            temp2 = (((arg0->unk34E * 2) + arg0->unk351));
            temp = ((temp_f0 - temp2) / temp_f0);
            temp = 200.0f * temp;
            createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0, 0, 0, temp, 0, 0xFF, sp44[1], sp44[2]);
            break;
    }
}

void func_global_asm_8071C24C(Struct80717D84 *arg0, u8 *arg1) {
    s32 pad;
    f32 y;
    s16 lightColor[3];

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        arg0->unk384_f32->unk0 = 6.0f;
    }
    if (current_map == MAP_HELM_LOBBY) {
        lightColor[0] = 0xFF;lightColor[1] = 0x46;lightColor[2] = 0;
    } else {
        lightColor[0] = 0xFF;lightColor[1] = 0xFF;lightColor[2] = 0xFF;
    }
    arg0->unk340 += 1.0f;
    arg0->unk344 += arg0->unk384_f32->unk0;
    arg0->unk384_f32->unk0 -= 0.15;
    y = arg0->unk344;
    if (func_global_asm_80667110(arg0->unk340, arg0->unk348, &y) == 0) {
        *arg1 = 1;
    } else if (arg0->unk344 < y) {
        if (arg0->unk384_f32->unk0 < 0.0) {
            *arg1 = 1;
        }
    }
    if (*arg1 != 0) {
        playSoundAtPosition(arg0->unk340, arg0->unk344, arg0->unk348, 0xEA, 0xFF, 0x7F, 0x1E, 0x46, 9.0f, 0);
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(1);
        func_global_asm_8071498C(func_global_asm_8071C004);
        func_global_asm_80714944(7);
        drawSpriteAtPosition(&D_global_asm_8071FB54, 0.667f, arg0->unk340, y + 10.0f, arg0->unk348);
    }
    createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 200.0f, 0, lightColor[0], lightColor[1], lightColor[2]);
}

void func_global_asm_8071C48C(otherSpriteControl *arg0, s8 *arg1) {
    f32 var_f2;
    f32 var_f16;
    s32 var_t3;

    var_f2 = (f32) (arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (var_f2 > 0.7) {
        var_f2 = 1.0f;
    }
    if (((u32)arg0->unk35C >> 0x10) != 0) {
        var_f16 = (arg0->unk35C & 0xFFFF) * var_f2;
    } else {
        var_f16 = (arg0->unk35C & 0xFFFF);
    }
    func_global_asm_806595F0(1U);
    createLight(
        arg0->xPos, arg0->yPos, arg0->zPos, 0.0f,
        0.0f,
        0.0f,
        var_f16,
        0, 0, (-80.0f * var_f2) + 255.0f, 0xFF);
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_8071C620;

void func_global_asm_8071C620(Struct80717D84 *arg0, s32 arg1) {
    f32 sp90[4][4];
    f32 sp50[4][4];
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    Struct80717D84_unk384_8071C620 *var_v0;

    var_v0 = arg0->unk384;
    if (var_v0 == NULL) {
        arg0->unk384 = malloc(0xC);
        guRotateF(sp90, (func_global_asm_806119A0() % 36000U) / 100, 1.0f, 0.0f, 0.0f);
        guRotateF(sp50, (func_global_asm_806119A0() % 36000U) / 100, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp90, sp50, sp90);
        guRotateF(sp90, (func_global_asm_806119A0() % 36000U) / 100, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp90, sp50, sp90);
        guMtxXFMF(sp90, 0.0f, 0.0f, 0.5f, &sp4C, &sp48, &sp44);
        arg0->unk384_f32->unk0 = sp4C;
        arg0->unk384_f32->unk4 = sp48;
        arg0->unk384_f32->unk8 = sp44;
    }
    var_v0 = arg0->unk384;
    arg0->unk340 += var_v0->unk0;
    arg0->unk344 += var_v0->unk4;
    arg0->unk348 += var_v0->unk8;
}

void func_global_asm_8071C818(Struct80717D84 *arg0, s8 *arg1) {
    float sp70[4][4];
    float sp30[4][4];

    arg0->unk360 -= 0.05;
    arg0->unk364 -= 0.05;
    if (arg0->unk360 <= 0.0f) {
        *arg1 = 1;
    }
    arg0->unk35C = arg0->unk35C + 5;
    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp70, sp30, sp70);
    guMtxF2L(sp70, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

void func_global_asm_8071C914(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    f32 temp_f0;

    arg0->unk360 = arg0->unk360 * 1.07;
    arg0->unk35C += 0xA;
    arg0->unk364 = arg0->unk360;
    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp70, sp30, sp70);
    guMtxF2L(sp70, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

// Matrix stuff, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071C9E8.s")

extern SpriteData D_global_asm_8071FB08;

/*
void func_global_asm_8071C9E8(otherSpriteControl *arg0, s8 *arg1) {
    Mtx spA0;
    Mtx sp60;
    Struct80717D84_unk384_8071C9E8 *temp_v0;
    u8 sp5B;
    s16 sp58;
    f32 temp;
    s32 pad;

    if (arg0->unk384_8071C9E8 == NULL) {
        sp5B = RandClamp(1000) % 6;
        arg0->unk384_8071C9E8 = malloc(sizeof(Struct80717D84_unk384_8071C9E8));
        temp_v0 = arg0->unk384_8071C9E8;
        temp_v0->unk4 = (RandClamp(5) + 0xA);
        temp_v0->unk6.unk0 = D_global_asm_80755650[sp5B].unk0;
        temp_v0->unk6.unk2 = D_global_asm_80755650[sp5B].unk2;
        temp_v0->unk6.unk4 = D_global_asm_80755650[sp5B].unk4;
        temp_v0->unkC = 0;
        temp_v0->unk2 = arg0->yPos;
    }
    temp_v0 = arg0->unk384_8071C9E8;
    if (player_pointer->z_position < 340.0f) {
        temp_v0->unk6.unk0 = 0x12C;
        temp_v0->unk6.unk2 = 0x96;
        temp_v0->unk6.unk4 = 0x64;
    }
    sp58 = func_global_asm_80665DE0(temp_v0->unk6.unk0, temp_v0->unk6.unk4, arg0->xPos, arg0->zPos);
    temp = RandClamp(10) + 5;
    temp_v0->unk0 = func_global_asm_806CC190(temp_v0->unk0, sp58, temp);
    temp_v0->unk2 = (((temp_v0->unk6.unk2 - temp_v0->unk2) * 0.1) + temp_v0->unk2);
    arg0->xPos += (temp_v0->unk4 * func_global_asm_80612794(temp_v0->unk0));
    arg0->zPos += (temp_v0->unk4 * func_global_asm_80612790(temp_v0->unk0));
    arg0->yPos = ((func_global_asm_80612794(((temp_v0->unk4 + 0x32) * object_timer)) * 40.0) + (f64) (temp_v0->unk2 + 0x28));
    if (RandChance(0.01)) {
        sp5B = RandClamp(1000) % 6;
        temp_v0->unk6.unk0 = D_global_asm_80755650[sp5B].unk0;
        temp_v0->unk6.unk2 = D_global_asm_80755650[sp5B].unk2;
        temp_v0->unk6.unk4 = D_global_asm_80755650[sp5B].unk4;
    }
    func_global_asm_806595F0(1U);
    createLight(arg0->xPos, arg0->yPos, arg0->zPos, 0.0f, 0.0f, 0.0f, 150.0f, 0U, 0x96U, 0x96U, 0xFFU);
    if (!(object_timer & 3)) {
        func_global_asm_807149B8(1U);
        func_global_asm_8071498C(&func_global_asm_8071C818);
        drawSpriteAtPosition(&D_global_asm_8071FB08, 1.6f, arg0->xPos, arg0->yPos, arg0->zPos);
    }
    temp_v0->unkC += temp_v0->unk4;
    guScaleF(&spA0, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp60, temp_v0->unkC, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&spA0, &sp60, &spA0);
    guMtxF2L(&spA0, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

void func_global_asm_8071CDE0(otherSpriteControl *arg0, s8 *arg1) {
    Mtx sp98;
    Mtx sp58;
    Struct80717D84_unk384_8071CDE0 *var_v1;
    Actor *temp_t0; // 50
    s16 pad;
    s16 sp4C;

    if (arg0->unk384_8071CDE0 == NULL) {
        rand();
        var_v1 = malloc(sizeof(Struct80717D84_unk384_8071CDE0));
        arg0->unk384_8071CDE0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk2 = arg0->yPos;
        var_v1->unk4 = (RandClamp(5) + 0xA);
        var_v1->unk6 = 0;
    }
    var_v1 = arg0->unk384;
    temp_t0 = arg0->unk35C;
    sp4C = func_global_asm_80665DE0(temp_t0->x_position, temp_t0->z_position, arg0->xPos, arg0->zPos);
    var_v1->unk0 = func_global_asm_806CC190(var_v1->unk0, sp4C, RandClamp(10) + 5);
    var_v1->unk2 = ((((temp_t0->y_position + temp_t0->unk15E) - var_v1->unk2) * 0.1) + var_v1->unk2);
    arg0->xPos += (var_v1->unk4 * func_global_asm_80612794(var_v1->unk0));
    arg0->zPos += (var_v1->unk4 * func_global_asm_80612790(var_v1->unk0));
    arg0->yPos = ((func_global_asm_80612794(((var_v1->unk4 + 0x32) * object_timer)) * 40.0) + (var_v1->unk2 + 0x28));
    func_global_asm_806595F0(1U);
    createLight(arg0->xPos, arg0->yPos, arg0->zPos, 0.0f, 0.0f, 0.0f, 150.0f, 0U, 0x96U, 0x96U, 0xFFU);
    if (!(object_timer & 3)) {
        func_global_asm_807149B8(1U);
        func_global_asm_8071498C(&func_global_asm_8071C818);
        drawSpriteAtPosition(&D_global_asm_8071FB08, 1.6f, arg0->xPos, arg0->yPos, arg0->zPos);
    }
    var_v1->unk6 += var_v1->unk4;
    guScaleF(&sp98, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp58, var_v1->unk6, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp98, &sp58, &sp98);
    guMtxF2L(&sp98, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}



extern u16 D_global_asm_807FC930[];

void func_global_asm_8071D0F0(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_8071D0F0 *var_t0;
    u16 *temp_v1;
    Actor *sp2C;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;

    sp2C = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071D0F0));
        var_t0 = arg0->unk384;
        var_t0->unk0 = 30.0f;
    }
    var_t0 = arg0->unk384;
    getBonePosition(sp2C, 1, &var_t0->unk4, &var_t0->unk8, &var_t0->unkC);
    temp_f0 = var_t0->unk0 / 30.0;
    arg0->unk340 = ((player_pointer->x_position - var_t0->unk4) * temp_f0) + var_t0->unk4;
    arg0->unk344 = ((player_pointer->y_position - var_t0->unk8) * temp_f0) + var_t0->unk8;
    arg0->unk348 = ((player_pointer->z_position - var_t0->unkC) * temp_f0) + var_t0->unkC;
    var_t0->unk0 -= 1.0f;
    if (var_t0->unk0 == 0.0f) {
        extra_player_info_pointer->unk1F0 |= 0x20000;
        temp_v1 = &D_global_asm_807FC930[getLevelIndex(D_global_asm_8076A0AB, 0)];
        *temp_v1 += 1;
        *arg1 = 1;
    }
}

void func_global_asm_8071D260(Struct80717D84 *arg0, s8 *arg1) {
    arg0->unk36D -= arg0->unk35C;
    if (arg0->unk35C >= arg0->unk36D) {
        *arg1 = 1;
    }
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Struct80717D84_unk384_8071D28C;

void func_global_asm_8071D28C(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f6;
    Actor *actor;
    Struct80717D84_unk384_8071D28C *temp_v0;
    Struct80717D84_unk384_8071D28C *var_v1;

    actor = arg0->unk338;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071D28C));
        var_v1 = arg0->unk384;
        temp_f0 = actor->x_position - arg0->unk340;
        temp_f2 = actor->z_position - arg0->unk348;
        var_v1->unk0 = sqrtf(SQ(temp_f0) + SQ(temp_f2));
        var_v1->unk4 = (func_global_asm_806119FC() * 20.0f) + 10.0f;
        var_v1->unk8 = func_global_asm_806119FC() * 4095.0f;
        var_v1->unkC = (func_global_asm_806119FC() * 90.0f) + 10.0f;
        var_v1->unk10 = actor->y_rotation;
        var_v1->unk14 = func_global_asm_806119FC() * 30.0f;
        var_v1->unk18 = 0.0f;
        var_v1->unk1C = (((f32)(RandClamp(255) % 2) * 2)) - 1;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = ((var_v1->unk4 - var_v1->unk0) * 0.15) + var_v1->unk0;
    var_v1->unk14 = ((120.0f - var_v1->unk14) * 0.01) + var_v1->unk14;
    var_v1->unk10 = var_v1->unk10 + (var_v1->unk1C * var_v1->unk14);
    var_v1->unk8 = var_v1->unk8 + var_v1->unkC;
    arg0->unk340 = (func_global_asm_80612794(var_v1->unk10) * var_v1->unk0) + actor->x_position;
    arg0->unk348 = (func_global_asm_80612790(var_v1->unk10) * var_v1->unk0) + actor->z_position;
    arg0->unk344 += (0.6 * func_global_asm_80612794(var_v1->unk8));
    var_v1->unk18 = var_v1->unk18 + 1.0f;
    if (var_v1->unk18 > 45.0f) {
        *arg1 = 1;
    }
    if ((object_timer % (u32)arg0->unk35C) == 0) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714950(0x2A);
        func_global_asm_8071498C(func_global_asm_8071D260);
        func_global_asm_80714A28(0x20);
        drawSpriteAtPosition(arg0->unk330->unk0, arg0->unk360, arg0->unk340, arg0->unk344, arg0->unk348);
    }
}

void func_global_asm_8071D5BC(Struct80717D84 *arg0, s8 *arg1) {
    f32 sp80[4][4];
    f32 sp40[4][4];
    s32 temp_f8;

    temp_f8 = arg0->unk360 * 20.0f;
    if (player_pointer->y_position <= arg0->unk344) {
        if (arg0->unk344 < (player_pointer->y_position + player_pointer->unk15E)) {
            if ((((player_pointer->x_position - arg0->unk340) * (player_pointer->x_position - arg0->unk340)) + ((player_pointer->z_position - arg0->unk348) * (player_pointer->z_position - arg0->unk348))) < (temp_f8 * temp_f8)) {
                setAction(0x2E, NULL, 0);
            }
        }
    }
    guScaleF(sp80, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp40, 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp80);
    guTranslateF(sp40, arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(sp80, sp40, sp80);
    if (arg0->unk36D >= 9) {
        arg0->unk36D -= 9;
    } else {
        *arg1 = 1;
    }
    arg0->unk360 *= 1.08;
    arg0->unk364 = arg0->unk360;
    guMtxF2L(sp80, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_8071D784;

void func_global_asm_8071D784(Struct80717D84 *arg0, s8 *arg1) {
    f32 sp90[4][4];
    f32 sp50[4][4];
    s32 pad;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        guRotateF(sp90, -(f32)((func_global_asm_806119A0() % 36000U) / 1000), 1.0f, 0.0f, 0.0f);
        guRotateF(sp50, (arg0->unk35C * 0x168) / 4096, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp90, sp50, sp90);
        guMtxXFMF(sp90, 0.0f, 0.0f, D_global_asm_80755678, &sp48, &sp44, &sp40);
        arg0->unk384_f32->unk0 = sp48;
        arg0->unk384_f32->unk4 = sp44;
        arg0->unk384_f32->unk8 = sp40;
    }
    arg0->unk340 += arg0->unk384_f32->unk0;
    arg0->unk344 += arg0->unk384_f32->unk4;
    arg0->unk384_f32->unk4 += D_global_asm_80755674;
    arg0->unk348 = arg0->unk348 + arg0->unk384_f32->unk8;
    if (arg0->unk344 <= player_pointer->y_position) {
        *arg1 = 1;
    }
}

// close, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071D94C.s")

void func_global_asm_8071D94C(Actor *arg0, otherSpriteControl *arg1, s8 *arg2);

/*
void func_global_asm_8071D94C(Actor *arg0, otherSpriteControl *arg1, s8 *arg2) {
    s16 temp;
    s16 sp34;
    f32 sp30;
    f32 var_f2;
    f32 sp28;
    Struct80717D84_unk384_f32 *sp24;
    f32 temp2;
    f32 temp3;

    arg1->unk384 = malloc(0x10);
    sp24 = arg1->unk384;
    arg1->xPos += (2.0f * (func_global_asm_806119FC() - 0.5f));
    arg1->yPos += (2.0f * (func_global_asm_806119FC() - 0.5f));
    arg1->zPos += (2.0f * (func_global_asm_806119FC() - 0.5f));
    if (arg0 != NULL) {
        sp34 = (arg0->y_rotation + (func_global_asm_806119A0() & 0x1FF) + 0x700) & 0xFFF;
        var_f2 = arg0->unkB8 * 0.01666666754f;
        if (!(var_f2 < 1.0f)) {
            var_f2 = 1.0f;
        }
        if (var_f2 < 0.3) {
            *arg2 = 1;
        }
        sp28 = var_f2 * 1.5f * 1.8f;
        arg1->unk338 = arg0;
    } else {
        var_f2 = 0.8f;
        sp34 = func_global_asm_806119A0() % 4095U;
        sp28 = (func_global_asm_806119FC() + 1.0f) * 3.0f;
    }
    temp2 = func_global_asm_806119FC();
    arg1->transparency4 = 0x82;
    arg1->xScale *= ((1.0f + temp2) * 0.5);
    arg1->yScale = arg1->xScale;
    sp30 = func_global_asm_806119FC() * var_f2;
    sp24->unk0 = func_global_asm_80612794(sp34) * sp30;
    sp24->unk4 = func_global_asm_80612790(sp34) * sp30;
    sp24->unk8 = sp28;
    func_global_asm_8066715C(&sp24->unkC);
}
*/

void func_global_asm_8071DB74(Struct80717D84 *arg0, u8 *arg1) {
    Struct80717D84_unk384_f32 *var_v1;

    if (arg0->unk384_f32 == NULL) {
        func_global_asm_8071D94C(NULL, arg0, arg1);
    }
    var_v1 = arg0->unk384_f32;
    var_v1->unk8 = var_v1->unk8 + -0.5f;
    arg0->unk340 = arg0->unk340 + var_v1->unk0;
    arg0->unk344 = arg0->unk344 + var_v1->unk8;
    arg0->unk348 = arg0->unk348 + var_v1->unk4;
    if (*arg1 == 0) {
        if (arg0->unk338 != NULL) {
            if (arg0->unk344 <= arg0->unk338->unkAC) {
                *arg1 = 1;
            }
        } else if (arg0->unk344 <= var_v1->unkC) {
            *arg1 = 1;
        }
        if (*arg1 != 0) {
            func_global_asm_80718124(arg0->unk360 * 5.0f, arg0->unk340, arg0->unk344, arg0->unk348);
        }
    }
}

void func_global_asm_8071DC90(Struct80717D84 *arg0, s8 *arg1) {
    PlayerAdditionalActorData *PaaD;
    Actor *sp28;
    Struct80717D84_unk384_8071DC90 *var_v0;
    f32 sp20;
    f64 var_f2;

    sp20 = 0.3f;
    sp28 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071DC90));
        var_v0 = arg0->unk384;
        var_v0->unk0 = 0.0f;
        var_v0->unk4 = func_global_asm_806119FC() * 4095.0f;
        var_f2 = MAX(func_global_asm_806119FC(), 0.5);
        var_v0->unk8 = var_f2 * 300.0;
        if (func_global_asm_806119FC() > 0.5) {
            var_v0->unk8 = -var_v0->unk8;
        }
        var_v0->unkC = func_global_asm_806119FC() * 4095.0f;
        var_f2 = MAX(func_global_asm_806119FC(), 0.5);
        var_v0->unk10 = var_f2 * 300.0;
        if (func_global_asm_806119FC() > 0.5) {
            var_v0->unk10 = -var_v0->unk10;
        }
        var_v0->unk14 = MAX(func_global_asm_806119FC(), 0.3);
        sp20 = 1.0f;
    }
    var_v0 = arg0->unk384;
    if (var_v0->unk0 < 1.0f) {
        var_v0->unk0 += 0.03333333507f;
    }
    var_v0->unk4 = (var_v0->unk4 + var_v0->unk8);
    var_v0->unk4 = (s16)var_v0->unk4 & 0xFFF;
    var_v0->unkC = (var_v0->unkC + var_v0->unk10);
    var_v0->unkC = (s16)var_v0->unkC & 0xFFF;
    arg0->unk340 = ((((func_global_asm_80612794(var_v0->unk4) * (15.0f * var_v0->unk0)) + sp28->x_position) - arg0->unk340) * sp20) + arg0->unk340;
    arg0->unk348 = ((((func_global_asm_80612790(var_v0->unk4) * (15.0f * var_v0->unk0)) + sp28->z_position) - arg0->unk348) * sp20) + arg0->unk348;
    arg0->unk344 = ((((((func_global_asm_80612794(var_v0->unkC) * (var_v0->unk14 * var_v0->unk0)) + 1.0f) * 15.0f) + sp28->y_position) - arg0->unk344) * sp20) + arg0->unk344;
    PaaD = sp28->PaaD; 
    if (!(PaaD->unk1F0 & 0x10)) {
        *arg1 = 1;
    }
}

void func_global_asm_8071E028(Struct80717D84 *arg0, s32 arg1) {
    f32 sp68[4][4];
    f32 sp28[4][4];
    guScaleF(sp68, arg0->unk360, arg0->unk364, 0.0f);
    guTranslateF(sp28, 0.0f, arg0->unk364 * 20.0f, 0.0f);
    guMtxCatF(sp68, sp28, sp68);
    guRotateF(sp28, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp68, sp28, sp68);
    guMtxF2L(sp68, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

void func_global_asm_8071E110(Struct80717D84 *arg0, u8 arg1, u16 arg2, f32 arg3, f32 arg4, s32 arg5) {
    Struct80717D84_unk384_8071E110 *temp_v0;

    temp_v0 = malloc(sizeof(Struct80717D84_unk384_8071E110));
    arg0->unk384 = temp_v0;
    temp_v0->unk0 = arg1;
    temp_v0->unk4 = arg4;
    temp_v0->unk8 = arg3;
    temp_v0->unkC = 1.0f / arg5;
    temp_v0->unk10 = 0.0f;
    temp_v0->unk14 = arg2;
}

void func_global_asm_8071E1C8(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp_f0;
    s32 pad2;
    f32 sp3C;
    s32 pad[3];
    f32 sp2C;
    Actor *temp_s2;
    f32 var_f2;
    Struct80717D84_unk384_8071E110 *temp_v0;
    f32 temp;

    if (arg0->unk384 == NULL) {
        *arg1 = 1;
        return;
    }
    temp_v0 = arg0->unk384;
    temp_s2 = arg0->unk35C_actor;
    if (func_global_asm_8067AF44(temp_s2) == 0) {
        *arg1 = 1;
        return;
    }
    temp = (temp_v0->unk10 * ((1 - (temp_v0->unk0 * 2)) * 2048));
    temp = (s16)temp & 0xFFF;
    sp2C = func_global_asm_80612794(temp) * temp_v0->unk8;
    temp_v0->unk14 += (2.0 * ((1 - (temp_v0->unk0 * 2)) * 4096) * temp_v0->unkC);
    temp_v0->unk14 = (s16)temp_v0->unk14 & 0xFFF;
    sp3C = func_global_asm_80612794(temp_v0->unk14) * sp2C;
    temp_f0 = func_global_asm_80612790(temp_v0->unk14) * sp2C;
    var_f2 = temp_v0->unk10 * temp_v0->unk4;
    if (temp_v0->unk0 == 0.0f) {
        var_f2 = temp_v0->unk4 - var_f2;
    }
    arg0->unk340 = temp_s2->x_position + sp3C;
    arg0->unk348 = temp_s2->z_position + temp_f0;
    arg0->unk344 = temp_s2->y_position + var_f2;
    temp_v0->unk10 = temp_v0->unk10 + temp_v0->unkC;
    if (temp_v0->unk10 >= 1.0f) {
        *arg1 = 1;
    }
}

void func_global_asm_8071E3EC(Struct80717D84 *arg0, s8 *arg1) {
    f32 *var_v1;
    f32 temp_f0;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f64 temp;
    f64 var_f0;
    f64 temp3;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        var_v1 = arg0->unk384;
        var_v1[0] = 0;
        var_v1[1] = 0;
        var_v1[2] = func_global_asm_806531B8(arg0->unk340, arg0->unk344, arg0->unk348, 0);
    }
    var_v1 = arg0->unk384;
    if (var_v1[1] == 0.0) {
        temp = 300.0;
        var_v1[0] += 30.0;
        if (temp < var_v1[0]) {
            var_v1[0] = 300.0f;
            var_v1[1] = 1.0f;
        }
    } else {
        var_v1[0] = var_v1[0] - 30.0;
        if (var_v1[0] < 30.0) {
            *arg1 = 1;
            var_v1[0] = 30.0f;
        }
    }
    if (var_v1[0] < 300.0) {
        sp4C = var_v1[0] / 300.0;
    } else {
        sp4C = 1.0f;
    }
    func_global_asm_80659610(1000);
    func_global_asm_80659600(var_v1[2]);
    switch (arg0->unk35C) {
        case 0:
            sp48 = 1.0f;
            sp44 = 1.0f;
            sp40 = 1.0f;
            func_global_asm_806595F0(2);
            func_global_asm_80659610(1000);
            break;
        case 1:
            sp48 = 1.0f;
            sp44 = 0.5f;
            sp40 = 0.3f;
            func_global_asm_806595F0(3);
            func_global_asm_80659610(1000);
            break;
        case 2:
            sp48 = 1.0f;
            sp44 = 0.5f;
            sp40 = 0.3f;
            func_global_asm_806595F0(2);
            func_global_asm_80659610(2000);
            break;
        case 3:
            sp48 = 1.0f;
            sp44 = 1.0f;
            sp40 = 1.0f;
            func_global_asm_806595F0(2);
            func_global_asm_80659610(2000);
            break;
    }
    temp_f0 = 255.0f * sp4C;
    createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_v1[0], 0, temp_f0 * sp48, temp_f0 * sp44, temp_f0 * sp40);
}

void func_global_asm_8071E864(Struct80717D84 *arg0, s8 *arg1) {
    f32 sp24;
    f32 temp_f12;
    f32 *var_v1;
    f64 temp;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1[0] = 10.0f;
        var_v1[1] = arg0->unk35C * 0x154;
    }
    var_v1 = arg0->unk384;
    var_v1[0] -= 0.2;
    if (var_v1[0] < 0.8) {
        var_v1[0] = 0.8f;
    }
    sp24 = func_global_asm_80612794(var_v1[1]) * var_v1[0];
    temp_f12 = func_global_asm_80612790(var_v1[1]) * var_v1[0];
    temp = 1.08;
    arg0->unk360 *= temp;
    arg0->unk364 *= temp;
    if (arg0->unk360 > 8.0) {
        arg0->unk36D -= 0x32;
        if (arg0->unk36D < 0x33) {
            *arg1 = 1;
        }
    }
    arg0->unk340 += sp24;
    arg0->unk348 += temp_f12;
}

void func_global_asm_8071EA24(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v0;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        var_v0 = arg0->unk384;
        var_v0[0] = func_global_asm_806119FC() * 4095.0f;
        var_v0[1] = ((func_global_asm_806119FC() * 0.5) + 1.0) * 5.0;
        var_v0[2] = 15.0f;
    }
    var_v0 = arg0->unk384;
    var_v0[1] -= 1.0f;
    var_v0[2] *= 0.95;
    arg0->unk340 += (var_v0[2] * func_global_asm_80612794(var_v0[0]));
    arg0->unk348 += (var_v0[2] * func_global_asm_80612790(var_v0[0]));
    arg0->unk344 += var_v0[1];
}

void func_global_asm_8071EB70(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;
    f32 d;
    f32 temp_f16;
    f32 dz;
    f32 dx;
    f32 dy;
    s32 var_f12; // Amazingly this is correct

    temp_f16 = (arg0->unk35C * 3) / 4;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk36D;
    }
    var_v1 = arg0->unk384;
    dx = character_change_array->unk224 - arg0->unk348;
    dy = character_change_array->unk21C - arg0->unk340;
    dz = character_change_array->unk220 - arg0->unk344;
    d = sqrtf(SQ(dx) + (SQ(dy) + SQ(dz)));
    if (d < temp_f16) {
        arg0->unk36D = *var_v1;
        return;
    }
    var_f12 = (*var_v1 * ((d - temp_f16) / (arg0->unk35C - temp_f16)));
    if (*var_v1 < var_f12) {
        var_f12 = *var_v1;
    }
    arg0->unk36D = *var_v1 - var_f12;
}

void func_global_asm_8071EDEC(Struct80717D84 *arg0, s32 arg1) {
    f64 temp;
    f32 x, y, z;

    getBonePosition(arg0->unk35C, 1, &x, &y, &z);
    temp = 0.1;
    arg0->unk340 += (x - arg0->unk340) * temp;
    arg0->unk344 += (y - arg0->unk344) * temp;
    arg0->unk348 += (z - arg0->unk348) * temp;
}

void func_global_asm_8071EEA4(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk364 = (arg0->unk35C / 100.0) + 1.0;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_8071EEE0;

void func_global_asm_8071EEE0(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_8071EEE0 *var_v1;
    f32 sp6C[4][4];
    f32 sp2C[4][4];

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        var_v1 = arg0->unk384;
        var_v1->unk0 = 0.01f;
        var_v1->unk4 = arg0->unk360;
        var_v1->unk8 = 0.0f;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = ((var_v1->unk4 - var_v1->unk0) * 0.1) + var_v1->unk0;
    var_v1->unk8 = var_v1->unk8 + 5.0f;
    guScaleF(sp6C, arg0->unk360, arg0->unk364, 0.0f);
    func_global_asm_80612CA0(sp2C, var_v1->unk8);
    guMtxCatF(sp6C, sp2C, sp6C);
    guMtxF2L(sp6C, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

void func_global_asm_8071EFDC(Struct80717D84 *arg0, s8 *arg1) {
    f64 temp = 1.05;
    arg0->unk36D -= 5;
    arg0->unk360 *= temp;
    arg0->unk364 *= temp;
    if (arg0->unk36D < 6) {
        *arg1 = 1;
    }
}

void func_global_asm_8071F034(Struct80717D84 *arg0, s32 arg1) {
    if (arg0->unk34E == 0) {
        arg0->unk340 = player_pointer->x_position;
        arg0->unk344 = player_pointer->y_position;
        arg0->unk348 = player_pointer->z_position;
    }
}

void func_global_asm_8071F078(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1[0] = (RandClamp(100) / 10.0) + 2.0;
        var_v1[1] = -8.0 - (RandClamp(100) / 70.0);
        arg0->unk35C += (s16)RandClamp(800) - 0x190;
        arg0->unk35C %= 0xFFF;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 += (var_v1[0] * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (var_v1[0] * func_global_asm_80612790(arg0->unk35C));
    arg0->unk344 += var_v1[1];
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071F1D0.s")

extern s8 D_global_asm_8075567C;

/*
void func_global_asm_8071F1D0(otherSpriteControl *arg0, s8 *arg1) {
    tuple_f *var_v1;
    tuple_f *var_v0;
    s32 temp3;

    if (arg0->unk384_tuplef == NULL) {
        var_v0 = malloc(sizeof(tuple_f));
        temp3 = D_global_asm_8075567C;
        arg0->unk384_tuplef = var_v0;
        var_v1 = arg0->unk384_tuplef;
        var_v1->x = arg0->xPos;
        var_v1->y = arg0->zPos;
        var_v1->z = temp3;
        D_global_asm_8075567C = -temp3;
    }
    var_v1 = arg0->unk384_tuplef;
    arg0->xPos = (func_global_asm_80612794(arg0->unk35C) * 14.0f) + var_v1->x;
    arg0->zPos = (func_global_asm_80612790(arg0->unk35C) * 14.0f) + var_v1->y;
    arg0->yPos += 0.5f;
    if (arg0->transparency4 >= 5) {
        arg0->transparency4 -= 4;
    } else {
        *arg1 = 1;
    }
    arg0->unk35C += (s32)(var_v1->z * 200.0);
}
*/

void func_global_asm_8071F2F8(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1[0] = arg0->unk35C & 0xFFFF;
        var_v1[1] = arg0->unk35C >> 0x10;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += var_v1[0];
    if (var_v1[0] > -20.0f) {
        var_v1[0] -= (var_v1[1] * 0.01);
    }
}

void func_global_asm_8071F3C0(Struct80717D84 *arg0, s32 arg1) {
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        arg0->unk384->unk0 = arg0->unk364 * 6.66666666666666696;
    }
    arg0->unk360 = arg0->unk338->animation_state->scale_y * arg0->unk384->unk0;
    arg0->unk364 = arg0->unk360;
}

void func_global_asm_8071F444(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp_f16;
    f32 temp_f6;
    Struct80717D84_unk384_8071F444 *var_v1;

    if (arg0->unk384 == NULL) {
        if (object_timer & 1) {
            arg0->unk360 = arg0->unk360 * -1.0f;
        }
        arg0->unk384 = malloc(8); // BUG?: Why does it only malloc 8 here when the struct size is 0x10?
        var_v1 = arg0->unk384;
        var_v1->unk0 = RandClamp(20) + 5;
        var_v1->unk4 = 0.0f;
        var_v1->unk8 = RandClamp(100) + 0xA;
        var_v1->unkC = 0.0f;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += (1.0 + func_global_asm_80612794(var_v1->unk4)) * (f32)(1.0 + (var_v1->unk0 * 0.4));
    arg0->unk340 += func_global_asm_80612794(var_v1->unkC) * (f32)(var_v1->unk8 * 0.5);
    if (arg0->unk350 == 0) {
        arg0->unk34E = (func_global_asm_80612794(var_v1->unkC) * 2.5) + 2.5;
    }
    var_v1->unk4 += 100.0f;
    var_v1->unkC += 50.0f;
    if (arg0->unk344 > 960.0f) {
        *arg1 = 1;
    }
}

void func_global_asm_8071F660(Struct80717D84 *arg0, s32 arg1) {
    f32 sp68[4][4];
    f32 sp28[4][4];
    f32 sp24;

    sp24 = ((f32)arg0->unk358 / (arg0->unk354 - 1));
    arg0->unk360 = func_global_asm_80612794(sp24 * 2048.0f) * 3.0;
    arg0->unk364 = arg0->unk360;
    guScaleF(sp68, arg0->unk360, arg0->unk364, 0.0f);
    func_global_asm_80612CA0(sp28, sp24 * 180.0f);
    guMtxCatF(sp68, sp28, sp68);
    guMtxF2L(sp68, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_8071F758;

void func_global_asm_8071F758(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_8071F758 *var_v1;
    f32 sp6C[4][4];
    f32 sp2C[4][4];

    var_v1 = arg0->unk384;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        var_v1 = arg0->unk384;
        var_v1->unk0 = 0.01f;
        var_v1->unk4 = arg0->unk360;
        var_v1->unk8 = 0.0f;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = ((var_v1->unk4 - var_v1->unk0) * 0.1) + var_v1->unk0;
    var_v1->unk8 = var_v1->unk8 + 5.0f;
    arg0->unk360 = (func_global_asm_80612794(object_timer * 0x32) * 0.1) + var_v1->unk0;
    arg0->unk364 = (func_global_asm_80612790(object_timer * 0x19) * 0.1) + var_v1->unk0;
    guScaleF(sp6C, arg0->unk360, arg0->unk364, 0.0f);
    func_global_asm_80612CA0(sp2C, var_v1->unk8);
    guMtxCatF(sp6C, sp2C, sp6C);
    guMtxF2L(sp6C, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Struct80717D84_unk384_8071F8E4;

void func_global_asm_8071F8E4(Struct80717D84 *arg0, u8 *arg1) {
    f32 sp78[4][4];
    f32 sp38[4][4];
    Struct80717D84_unk384_8071F8E4 *temp_v0;

    if (arg0->unk384 != NULL) {
        temp_v0 = arg0->unk384;
        temp_v0->unk20 = temp_v0->unk20 + temp_v0->unk24;
        if (temp_v0->unk20 >= 1.0) {
            *arg1 = 0xFF;
            temp_v0->unk20 = 1.0f;
        }
        arg0->unk340 = (temp_v0->unk14 * temp_v0->unk20) + temp_v0->unk8;
        arg0->unk344 = (temp_v0->unk18 * temp_v0->unk20) + temp_v0->unkC;
        arg0->unk348 = (temp_v0->unk1C * temp_v0->unk20) + temp_v0->unk10;
        if (!(object_timer & 3)) {
            func_global_asm_807149B8(1);
            func_global_asm_8071498C(func_global_asm_8071C818);
            drawSpriteAtPosition(&D_global_asm_8071FB08, 1.6f, arg0->unk340, arg0->unk344, arg0->unk348);
        }
        temp_v0->unk4 += temp_v0->unk0;
        guScaleF(sp78, arg0->unk360, arg0->unk364, 0.0f);
        guRotateF(sp38, temp_v0->unk4, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp78, sp38, sp78);
        guMtxF2L(sp78, arg0->unk128[D_global_asm_807444FC]);
        arg0->unk32C = 2;
    }
}
