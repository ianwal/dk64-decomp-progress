#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern Struct80717D84 *D_minecart_80028C30;

extern SpriteData D_global_asm_8071FB54;
extern SpriteData D_global_asm_8071FEF4;
extern SpriteData D_global_asm_8071FFA0; // TODO: Datatype

extern s16 D_global_asm_807502D0;

extern f32 D_global_asm_80755674;
extern f32 D_global_asm_80755678;

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
int func_global_asm_80717404(); // TODO: Signature
void func_global_asm_80718380(Struct80717D84 *arg0, s8 *arg1);

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_80717100.s")

/*
void func_global_asm_80717100(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_80717100 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80717100));
        var_v1 = arg0->unk384_80717100;
        var_v1->unk0 = (rand() >> 0xF) % 4095;
        var_v1->unk2 = arg0->unk35C;
        var_v1->unk4 = arg0->unk35C >> 0x10;
        var_v1->unk6 = arg0->unk340;
        var_v1->unk8 = arg0->unk348;
    }
    var_v1 = arg0->unk384_80717100;
    var_v1->unk0 = var_v1->unk4 + var_v1->unk0;
    arg0->unk340 = var_v1->unk6 + (var_v1->unk2 * func_global_asm_80612794(var_v1->unk0));
    arg0->unk348 = var_v1->unk8 + (var_v1->unk2 * func_global_asm_80612790(var_v1->unk0));
}
*/

void func_global_asm_8071720C(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_8071720C *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071720C));
        var_v1 = arg0->unk384;
        var_v1->unk0 = (rand() >> 0xF) % 4095;
        var_v1->unk2 = ((rand() >> 0xF) % 10) + 2;
        var_v1->unk4 = 0;
        var_v1->unk6 = -0x32 - (((rand() >> 0xF) % 10000) % 600);
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
void func_global_asm_80717404(Struct80717D84 *arg0, s32 arg1) {
    f64 sp28;
    void *temp_s2;
    void *temp_s2_2;
    void *temp_v0;
    void *var_v1;

    var_v1 = arg0->unk384;
    if (var_v1 == NULL) {
        temp_v0 = malloc(0xC);
        arg0->unk384 = temp_v0;
        temp_s2 = arg0->unk35C;
        if (temp_s2->unk0 != 0) {
            temp_v0->unk0 = (((rand() >> 0xF) % 200) + temp_s2->unk0) - 0x64;
        } else {
            temp_v0->unk0 = (rand() >> 0xF) % 4095;
        }
        if (arg0->unk36F != 0) {

        }
        sp28 = 0.0;
        temp_v0->unk4 = (((rand() >> 0xF) % 10) + 5) * 0.0;
        temp_v0->unk8 = temp_s2->unk2 + ((rand() >> 0xF) % 6);
        var_v1 = arg0->unk384;
    }
    temp_s2_2 = &arg0->unk35C;
    if (arg0->unk36F != 0) {
        arg0->unk340 = arg0->unk340 + (4.0 * (0.01 * temp_s2_2->unk2 * func_global_asm_80612794(var_v1->unk0)));
        arg0->unk344 = arg0->unk344 + (4.0 * (0.01 * temp_s2_2->unk2 * func_global_asm_80612790(var_v1->unk0)));
    } else {
        arg0->unk340 = arg0->unk340 + (0.04 * temp_s2_2->unk2 * func_global_asm_80612794(var_v1->unk0));
        arg0->unk348 = arg0->unk348 + (0.04 * temp_s2_2->unk2 * func_global_asm_80612790(var_v1->unk0));
        if (temp_s2_2->unk0 == 0) {
            arg0->unk344 = arg0->unk344 + var_v1->unk8;
            var_v1->unk8 = var_v1->unk8 - 0.5;
        } else {
            arg0->unk344 = arg0->unk344 + (var_v1->unk8 * 0.2);
        }
    }
    temp_s2_2->unk2 = temp_s2_2->unk2 + var_v1->unk4;
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
        drawSpriteAtPosition(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3], 0.8f, arg0->unk340, arg0->unk344, arg0->unk348);
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
        var_v1->unk2 = ((rand() >> 0xF) % 10) + 2;
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
    temp_f0_2 = sqrtf(((character_change_array->look_at_eye_z - arg0->unk348) * (character_change_array->look_at_eye_z - arg0->unk348)) + (((character_change_array->look_at_eye_x - arg0->unk340) * (character_change_array->look_at_eye_x - arg0->unk340)) + ((character_change_array->look_at_eye_y - arg0->unk344) * (character_change_array->look_at_eye_y - arg0->unk344))));
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
// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_807186C8.s")

void func_global_asm_807189BC(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_807189BC *var_v1;
    Actor *sp20;

    sp20 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = MAX(2.0, sp20->unkB8 * 0.01);
        var_v1->unk2 = sp20->y_rotation;
        var_v1->unk4 = ((rand() >> 0xF) % 1000) + 0xC8;
        arg0->unk360 += (((rand() >> 0xF) % 100) / 500.0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_80718BF4.s")

// Matrix stuff, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071910C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_807195D4.s")

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_807195D4;

/*
void func_global_asm_807195D4(Struct80717D84 *arg0, s32 arg1) {
    f32 temp;
    f32 sp6C[4][4];
    f32 sp2C[4][4];

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        arg0->unk384_f32->unk0 = arg0->unk35C * 2;
        arg0->unk384_f32->unk4 = 0.0f;
        arg0->unk36D = 0;
    }
    if (arg0->unk36D >= 0xDD) {
        arg0->unk36D = 0xFF;
    } else {
        arg0->unk36D += 0x14;
    }
    arg0->unk340 += (f32)(func_global_asm_80612D1C(arg0->unk384_f32->unk0 * 0.01745329238f) * 2.5);
    arg0->unk344 += (f32)(3.5);
    arg0->unk348 += (f32)(func_global_asm_80612D10(arg0->unk384_f32->unk0 * 0.01745329238f) * 2.5);
    arg0->unk384_f32->unk0 += 8.0;
    arg0->unk384_f32->unk4 += 7.3;
    guScaleF(sp6C, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp2C, arg0->unk384->unk4, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp6C, sp2C, sp6C);
    guMtxF2L(sp6C, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_807197B4.s")

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_807197B4;

/*
void func_global_asm_807197B4(Struct80717D84 *arg0, s32 arg1) {
    f32 sp78[4][4];
    f32 sp34;
    f32 sp2C;
    f32 temp_f0;
    f64 temp_f10;
    Struct80717D84_unk384_807197B4 *var_v1;
    u8 temp_v0_2;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_807197B4));
        var_v1 = arg0->unk384;
        var_v1->unk0 = 0;
        var_v1->unk4 = arg0->unk360;
        var_v1->unk8 = arg0->unk364;
    }
    var_v1 = arg0->unk384;
    var_v1->unk4 += 0.0015;
    var_v1->unk8 += 0.0015;
    arg0->unk340 -= func_global_asm_80612D1C(arg0->unk35C * 2) * 0.2;
    arg0->unk344 += 0.119999999999999996;
    arg0->unk348 -= func_global_asm_80612D10(arg0->unk35C * 2) * 0.2;
    arg0->unk360 = var_v1->unk4;
    arg0->unk364 = var_v1->unk8;
    arg0->unk360 *= (1.0 + (func_global_asm_80612D1C(var_v1->unk0 * 0.17) * 0.15));
    arg0->unk364 *= (1.0 + (func_global_asm_80612D1C(var_v1->unk0 * 0.2267) * 0.15));
    var_v1->unk0++;
    if ((arg0->unk354 - arg0->unk358) < 0xA) {
        if (arg0->unk36D >= 0x16) {
            arg0->unk36D -= 0x14;
        } else {
            arg0->unk36D = 0;
        }
    }
    guScaleF(sp78, arg0->unk360, arg0->unk364, 0.0f);
    guMtxF2L(sp78, arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

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
    temp = func_global_asm_80612D1C(0.01745329238f * arg0->unk384->unk4);
    sp1C = (temp * arg0->unk384->unk0);
    temp = func_global_asm_80612D10(0.01745329238f * arg0->unk384->unk4);
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

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80717D84_unk384_8071A1E4;

/*
void func_global_asm_8071A1E4(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_8071A1E4 *var_v0;
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

    var_v0 = arg0->unk384;
    if (var_v0 == NULL) {
        sp48 = -(func_global_asm_806119A0() / 10000U) % 30;
        sp46 = (func_global_asm_806119A0() / 10000U) % 180;
        guRotateF(&sp8C[0], sp48, 0.0f, 1.0f, 0.0f);
        // TODO: Regalloc here, arg0->unk35C is using v0 instead of t5
        sp4B = arg0->unk35C >> 0x10;
        sp4A = arg0->unk35C >> 8;
        sp49 = arg0->unk35C;
        arg0->unk384 = malloc(0xC);
        guAlignF(&sp4C[0], sp46, sp4B, sp4A, sp49);
        guMtxCatF(&sp8C[0], &sp4C[0], &sp8C[0]);
        guMtxXFMF(&sp8C[0], 0.0f, 0.0f, -2.0f, &sp40, &sp3C, &sp38);
        arg0->unk384_f32->unk0 = sp40 * 0.5;
        if (sp3C < 0.0f) {
            arg0->unk384_f32->unk4 = -sp3C * 0.5;
        } else {
            arg0->unk384_f32->unk4 = sp3C * 0.5;
        }
        arg0->unk384_f32->unk8 = sp38 * 0.5;
    }
    var_v0 = arg0->unk384;
    arg0->unk340 += var_v0->unk0;
    arg0->unk344 += var_v0->unk4;
    arg0->unk348 += var_v0->unk8;
    if ((arg0->unk354 - arg0->unk358) < 0xA) {
        var_v0->unk4 -= 0.1;
        if (arg0->unk36D >= 0x16) {
            arg0->unk36D -= 0x14;
            return;
        }
        arg0->unk36D = 0;
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

// TODO: Close, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071A674.s")

extern Struct80717D84 *D_8002FBB0;

/*
void func_global_asm_8071A674(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    Struct80717D84 **var_v0;

    var_v0 = &D_8002FBB0;
    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    while (*var_v0 != D_8002FBB0) {
        var_v0++;
        if (*var_v0 == arg0) {
            func_global_asm_806595F0(1);
            createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f0 * 50.0, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
            return;
        }
    }
}
*/

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071ABDC.s")

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

// Matrix stuff, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071B520.s")

/*
void func_global_asm_8071B520(Struct80717D84 *arg0, s32 arg1) {
    f32 sp80[4][4];
    f32 sp40[4][4];
    f32 sp3C;
    f32 var_f10;
    f32 var_f2;
    f32 var_f4;
    s16 temp_v0;
    u8 temp_t6;
    u8 temp_t7;

    sp3C = arg0->unk344;
    if (func_global_asm_80667110(arg0->unk340, arg0->unk348, &sp3C) != 0) {
        // TODO: This is probably a macro, which one?
        // Kinda like ABS but not zero based?
        if (arg0->unk344 < sp3C) {
            var_f2 = sp3C - arg0->unk344;
        } else {
            var_f2 = -(sp3C - arg0->unk344);
        }
        if (var_f2 > 10.0) {
            goto block_5;
        }
    } else {
block_5:
        if (arg0->unk34E >= 7) {
            arg0->unk344 -= (0.3 * ((0xE - (20.0f - (arg0->unk34E + ((f32)arg0->unk351 / arg0->unk350)))) / 14.0));
        }
    }
    if (arg0->unk34E == 0x10) {
        arg0->unk350 = 0xA;
    }
    guScaleF(sp80, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp40, (arg0->unk35C * 0x168) / 4096, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp80, sp40, sp80);
    guTranslateF(sp40, arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(sp80, sp40, sp80);
    guMtxF2L(sp80, arg0->unk128[D_global_asm_807444FC]);
    if (arg0->unk34E >= 0x13) {
        arg0->unk36D -= 0x14;
    }
    arg0->unk32C = 3;
}
*/

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
    if (((rand() >> 0xF) % 100) >= 0x5B) {
        func_global_asm_80714998(3);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_80714950(-0xA);
        func_global_asm_807149B8(1);
        changeActorColor(0x9B, 0x9B, 0x9B, 0x96);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, 0.8f, (((rand() >> 0xF) % 65535) & 7) + arg0->unk340, arg0->unk344 + 10.0f, (((rand() >> 0xF) % 65535) & 7) + arg0->unk348);
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
        guRotateF(&sp90[0], -(f32)((func_global_asm_806119A0() % 36000U) / 1000), 1.0f, 0.0f, 0.0f);
        guRotateF(&sp50[0], (arg0->unk35C * 0x168) / 4096, 0.0f, 1.0f, 0.0f);
        guMtxCatF(&sp90[0], &sp50[0], &sp90[0]);
        guMtxXFMF(&sp90[0], 0.0f, 0.0f, 10.0f, &sp48, &sp44, &sp40);
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

// Weird m2c errors
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071C48C.s")

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
        guRotateF(&sp90[0], (func_global_asm_806119A0() % 36000U) / 100, 1.0f, 0.0f, 0.0f);
        guRotateF(&sp50[0], (func_global_asm_806119A0() % 36000U) / 100, 0.0f, 0.0f, 1.0f);
        guMtxCatF(&sp90[0], &sp50[0], &sp90[0]);
        guRotateF(&sp90[0], (func_global_asm_806119A0() % 36000U) / 100, 0.0f, 1.0f, 0.0f);
        guMtxCatF(&sp90[0], &sp50[0], &sp90[0]);
        guMtxXFMF(&sp90[0], 0.0f, 0.0f, 0.5f, &sp4C, &sp48, &sp44);
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

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071C9E8.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_11BE00/func_global_asm_8071CDE0.s")

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
        var_v1->unk0 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
        var_v1->unk4 = (func_global_asm_806119FC() * 20.0f) + 10.0f;
        var_v1->unk8 = func_global_asm_806119FC() * 4095.0f;
        var_v1->unkC = (func_global_asm_806119FC() * 90.0f) + 10.0f;
        var_v1->unk10 = actor->y_rotation;
        var_v1->unk14 = func_global_asm_806119FC() * 30.0f;
        var_v1->unk18 = 0.0f;
        var_v1->unk1C = (((f32)(((rand() >> 0xF) % 255) % 2) * 2)) - 1;
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
        guRotateF(&sp90[0], -(f32)((func_global_asm_806119A0() % 36000U) / 1000), 1.0f, 0.0f, 0.0f);
        guRotateF(&sp50[0], (arg0->unk35C * 0x168) / 4096, 0.0f, 1.0f, 0.0f);
        guMtxCatF(&sp90[0], &sp50[0], &sp90[0]);
        guMtxXFMF(&sp90[0], 0.0f, 0.0f, D_global_asm_80755678, &sp48, &sp44, &sp40);
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

void func_global_asm_8071D94C(Actor *arg0, Struct80717D84 *arg1, s8 *arg2);

/*
void func_global_asm_8071D94C(Actor *arg0, Struct80717D84 *arg1, s8 *arg2) {
    s16 temp;
    s16 sp34;
    f32 sp30;
    f32 var_f2;
    f32 sp28;
    Struct80717D84_unk384_f32 *sp24;
    f64 temp2;

    arg1->unk384 = malloc(0x10);
    sp24 = arg1->unk384;
    arg1->unk340 += (2.0f * (func_global_asm_806119FC() - 0.5f));
    arg1->unk344 += (2.0f * (func_global_asm_806119FC() - 0.5f));
    arg1->unk348 += (2.0f * (func_global_asm_806119FC() - 0.5f));
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
    arg1->unk360 *= (func_global_asm_806119FC() + 1.0f) * 0.5;
    arg1->unk36D = 0x82;
    arg1->unk364 = arg1->unk360;
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
    d = sqrtf((dx * dx) + ((dy * dy) + (dz * dz)));
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
        var_v1[0] = (((rand() >> 0xF) % 100) / 10.0) + 2.0;
        var_v1[1] = -8.0 - (((rand() >> 0xF) % 100) / 70.0);
        arg0->unk35C += (s16)((rand() >> 0xF) % 800) - 0x190;
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
void func_global_asm_8071F1D0(Struct80717D84 *arg0, s8 *arg1) {
    f32 *var_v1;
    s32 temp2;
    s32 temp3;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        temp3 = D_global_asm_8075567C;
        var_v1 = arg0->unk384;
        var_v1[0] = arg0->unk340;
        var_v1[1] = arg0->unk348;
        var_v1[2] = temp3;
        D_global_asm_8075567C = -temp3;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 = (func_global_asm_80612794(arg0->unk35C) * 14.0f) + *var_v1;
    arg0->unk348 = (func_global_asm_80612790(arg0->unk35C) * 14.0f) + var_v1[1];
    arg0->unk344 += 0.5f;
    if (arg0->unk36D >= 5) {
        arg0->unk36D -= 4;
    } else {
        *arg1 = 1;
    }
    temp2 = var_v1[2] * 200.0;
    arg0->unk35C += temp2;
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
        var_v1->unk0 = ((rand() >> 0xF) % 20) + 5;
        var_v1->unk4 = 0.0f;
        var_v1->unk8 = ((rand() >> 0xF) % 100) + 0xA;
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

extern SpriteData D_global_asm_8071FB08; // TODO: Proper datatype

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
