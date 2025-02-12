#include <ultra64.h>
#include "functions.h"

// rodata
/*
extern f64 D_global_asm_8075EB00 = 0.1;
extern f64 D_global_asm_8075EB08 = 0.001;
extern f64 D_global_asm_8075EB10 = 0.001;
extern f64 D_global_asm_8075EB18 = 0.1;
extern f64 D_global_asm_8075EB20 = 0.02;
extern f64 D_global_asm_8075EB28 = 255;
extern f64 D_global_asm_8075EB30 = 0.05;
*/

// .data
static s16 D_global_asm_80755680 = 0;
static f32 D_global_asm_80755684 = 255.0f;
static f32 D_global_asm_80755688 = 255.0f;
static f32 D_global_asm_8075568C = 255.0f;

typedef struct struct807FDB60 {
    u8 pad[0x4];
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    s8 unkB;
    s8 unkC;
    s8 unkD;
    s8 unkE;
} struct807FDB60;

typedef struct ActorRecolorStruct {
    Actor *unk0;
    s16 x;
    s16 y;
    s16 z;
    u8 alpha;
    u8 red;
    u8 green;
    u8 blue;
    u8 unkE;
    u8 unkF;
} ActorRecolorStruct;

extern struct807FDB60 D_807FDB60;
extern ActorRecolorStruct *D_807FDB70;
extern s16 D_807FDB76;
extern s16 D_807FDB78;
extern s16 D_807FDB7A;
extern s8 D_807FDB7C;
extern s8 D_807FDB7D;
extern s8 D_807FDB7E;
extern u8 D_807FDB7F;
extern u8 D_807FDB80;

void func_global_asm_80721560(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) {
    D_807FDB76 = arg0;
    D_807FDB78 = arg1;
    D_807FDB7A = arg2;
    D_807FDB7E = arg3;
    D_807FDB7F = arg4;
    D_807FDB80 = arg5;
}

void func_global_asm_807215AC(s8 arg0, s8 arg1, s8 arg2) {
    D_807FDB60.unkB = arg0;
    D_807FDB60.unkC = arg1;
    D_807FDB60.unkD = arg2;
}

void func_global_asm_807215D0(s8 arg0, s8 arg1) {
    D_807FDB7C = arg0;
    D_807FDB7D = arg1;
}

void func_global_asm_807215EC(void) {
    D_807FDB60.unk8 = 0;
    D_807FDB60.unkB = 0x6B;
    D_807FDB60.unkC = 0x30;
    D_807FDB60.unkD = 0x50;
    D_807FDB60.unkE = 7;
    D_807FDB60.unk6 = D_807FDB60.unk8;
    D_807FDB60.unk4 = D_807FDB60.unk8;
    D_807FDB70 = malloc(sizeof(ActorRecolorStruct) * 0x20);
    func_global_asm_80721560(0x320, 0x82, 0, 0xFF, 0xFF, 0xFF);
    func_global_asm_807215D0(1, 1);
}

void func_global_asm_8072167C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_global_asm_80755680 += (arg3 - D_global_asm_80755680) * 0.1;
    D_global_asm_80755684 += (arg0 - D_global_asm_80755684) * 0.1;
    D_global_asm_80755688 += (arg1 - D_global_asm_80755688) * 0.1;
    D_global_asm_8075568C += (arg2 - D_global_asm_8075568C) * 0.1;
}

extern u8 D_807FDB74;
extern u8 D_807FDB75;

void addActorRecolor(Actor *actor, s16 x, s16 y, s16 z, u8 alpha, u8 red, u8 green, u8 blue, u8 arg8) {
    u8 var_v0;
    ActorRecolorStruct *temp_v1;

    if (D_807FDB74 >= 0x20) {
        D_807FDB74--;
    }
    temp_v1 = &D_807FDB70[D_807FDB74++];
    temp_v1->unk0 = actor;
    temp_v1->x = x;
    temp_v1->y = y;
    temp_v1->z = z;
    temp_v1->alpha = alpha;
    temp_v1->red = red;
    temp_v1->green = green;
    temp_v1->blue = blue;
    temp_v1->unkE = arg8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_126260/func_global_asm_80721814.s")

void func_global_asm_80722280(void) {
    D_807FDB74 = 0;
    D_807FDB75 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_126260/func_global_asm_80722294.s")
