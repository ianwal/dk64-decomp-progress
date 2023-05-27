#include <ultra64.h>
#include "functions.h"


extern u8 D_8074450C;

typedef struct Struct807FDB00 Struct807FDB00; 

struct Struct807FDB00 {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x24 - 0x8];
    Struct807FDB00 *next;
};

typedef struct Struct807FDB04 Struct807FDB04;

struct Struct807FDB04 {
    u8 unk0[0x338 - 0x0];
    Actor *unk338;
    u8 unk33C[0x39C - 0x33C];
    Struct807FDB04 *next;
};

// TODO: Is this a huge static struct?
// If so, we can match this whole file pretty much
extern Struct807FDB00 *D_807FDB00;
extern Struct807FDB04 *D_807FDB04;
extern s32 D_807FDB08;
extern u8 D_807FDB0C;
extern u8 D_807FDB0D;
extern u8 D_807FDB0E;
extern u8 D_807FDB0F;
extern s32 D_807FDB10;
extern s32 D_807FDB14;
extern u8 D_807FDB18;
extern u16 D_807FDB1A;
extern u8 D_807FDB1C;
extern u8 D_807FDB1D;
extern f32 D_807FDB20;
extern f32 D_807FDB24;
extern u8 D_807FDB28;
extern s32 D_807FDB2C;
extern s32 D_807FDB30;
extern u16 D_807FDB34;
extern u16 D_807FDB36;
extern s16 D_807FDB38;
extern u16 D_807FDB3A;
extern s16 D_807FDB3C;
extern s16 D_807FDB3E;
extern s16 D_807FDB40;
extern s16 D_807FDB42;

void func_80714A9C(void);

void func_80714670(void) {
    D_807FDB00 = NULL;
    D_807FDB04 = NULL;
    D_807FDB08 = 0;
    func_80714A9C();
}

s32 func_807146A4(s32 arg0) {
    Struct807FDB00 *var_v1;

    var_v1 = D_807FDB00;
    while (var_v1 != NULL) {
        if (arg0 == var_v1->unk4) {
            return var_v1->unk0;
        }
        var_v1 = var_v1->next;
    }
    return D_807FDB00->unk0;
}

// TODO: Struct?
void func_807146E0(u8 *arg0, u8 *arg1, u8 *arg2) {
    *arg1 = arg0[4];
    *arg2 = arg0[5];
}

// TODO: Struct?
void func_807146F4(s16 *arg0, s16 *arg1, s16 *arg2) {
    *arg1 = arg0[7];
    *arg2 = arg0[8];
}

// TODO: Struct?
void func_80714708(u8 *arg0, s16 *arg1, s16 *arg2) {
    u8 pad1F;
    u8 pad1E;
    u8 pad1D;
    u8 pad1C;
    u8 sp1B;
    u8 sp1A;

    func_807146E0(arg0, &sp1B, &sp1A);
    func_807146F4(arg0, arg1, arg2);
    *arg1 *= sp1B;
    *arg2 *= sp1A;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80714778.s")

void func_80714944(s32 arg0) {
    D_807FDB30 = arg0;
}

void func_80714950(s32 arg0) {
    D_807FDB2C = arg0;
}

void func_8071495C(void) {
    D_807FDB1D = 1;
}

void func_8071496C(s16 arg0) {
    D_807FDB1A = arg0;
}

void func_8071497C(u16 arg0) {
    D_807FDB34 = arg0;
}

void func_8071498C(void *arg0) {
    D_807FDB14 = arg0;
}

void func_80714998(u8 arg0) {
    D_807FDB1C = arg0;
}

void func_807149A8(u16 arg0) {
    D_807FDB3A = arg0;
}

void func_807149B8(u8 arg0) {
    D_807FDB18 = arg0;
}

void func_807149C8(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_807FDB0C = arg0;
    D_807FDB0D = arg1;
    D_807FDB0E = arg2;
    D_807FDB0F = arg3;
}

void func_807149FC(s32 arg0) {
    D_807FDB10 = arg0;
}

void func_80714A08(f32 arg0, f32 arg1) {
    D_807FDB20 = arg0;
    D_807FDB24 = arg1;
    D_807FDB28 = 1;
}

void func_80714A28(u16 arg0) {
    D_807FDB36 = arg0;
}

void func_80714A38(u8 arg0) {
   D_807FDB36 |= arg0;
}

void func_80714A58(u16 arg0) {
    D_807FDB38 = arg0;
}

void func_80714A68(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_807FDB3C = arg0;
    D_807FDB3E = arg1;
    D_807FDB40 = arg2;
    D_807FDB42 = arg3;
}

void func_80714A9C(void) {
    D_807FDB0F = 0;
    D_807FDB10 = 1;
    D_807FDB14 = 0;
    D_807FDB18 = 0;
    D_807FDB1C = 1;
    D_807FDB1A = 0;
    D_807FDB1D = 0;
    D_807FDB28 = 0;
    D_807FDB2C = 0;
    D_807FDB30 = 0;
    D_807FDB36 = 0;
    D_807FDB38 = -1;
    D_807FDB3C = D_8074450C * 0xA;
    D_807FDB3E = D_8074450C * 0xA;
    D_807FDB40 = D_8074450C * 0x135;
    D_807FDB42 = D_8074450C * 0xE5;
    D_807FDB3A = 0x258;
}

void *func_80714D08(void*, f32, f32, f32, f32, s32, s32, s32, s32);

void *func_80714B84(void *arg0, f32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_806335B0(arg2, 1, arg3, &sp3C, &sp38, &sp34);
    return func_80714D08(arg0, arg1, sp3C, sp38, sp34, 0, arg2, arg3, arg4);
}

void *func_80714C08(void *arg0, f32 arg1, Actor *arg2, s32 arg3, u8 arg4) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_80671C0C(arg2, arg3, &sp3C, &sp38, &sp34);
    if (!(arg2->object_properties_bitfield & 0x200) && (arg2->animation_state != NULL) && (D_807FDB36 & 0x80)) {
        func_80714A38(0x40);
    }
    return func_80714D08(arg0, arg1, sp3C, sp38, sp34, arg2, 0, arg3, arg4);
}

void *func_80714CC0(void* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return func_80714D08(arg0, arg1, arg2, arg3, arg4, 0, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80714D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071509C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715270.s")

void func_8071586C(Actor *arg0) {
    Struct807FDB04 *var_s0;

    var_s0 = D_807FDB04;
    while (var_s0 != NULL) {
        if (arg0 == var_s0->unk338) {
            func_80715908(var_s0);
        }
        var_s0 = var_s0->next;
    }
}

void func_807158C0(void) {
    Struct807FDB04 *temp_s1;
    Struct807FDB04 *var_s0;

    var_s0 = D_807FDB04;
    while (var_s0 != NULL) {
        temp_s1 = var_s0->next;
        func_80715908(var_s0);
        var_s0 = temp_s1;
    }
}

// OSTime
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715908.s")

// Get pointer table file
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715A3C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715B30.s")

void func_80715E38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f2;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg1 - arg4;
    temp_f16 = arg2 - arg5;
    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f16 * temp_f16));
}

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80715E94.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80716F10.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80716FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071720C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717B64.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} Struct80717D84_unk384;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_f32;

typedef struct {
    s16 unk0;
} Struct80717D84_unk384_s16;

typedef struct {
    u8 unk0[0x338 - 0x0];
    Actor *unk338;
    s32 unk33C;
    f32 unk340;
    f32 unk344;
    f32 unk348;
    u8 unk34C[0x35C - 0x34C];
    s32 unk35C;
    f32 unk360;
    f32 unk364;
    u8 unk368[0x36D - 0x368];
    u8 unk36D;
    u8 unk36E[0x384 - 0x36E];
    union {
        Struct80717D84_unk384 *unk384;
        Struct80717D84_unk384_f32 *unk384_f32;
        Struct80717D84_unk384_s16 *unk384_s16;
    };
} Struct80717D84;

void func_80717CE8(Struct80717D84 *arg0, s32 arg1) {
    if (arg0->unk36D != 0xFF) {
        arg0->unk36D += 0x14;
    }
    if (arg0->unk36D >= 0xEB) {
        arg0->unk36D = 0xFF;
    }
    arg0->unk344 = arg0->unk344 - (arg0->unk35C / 100.0);
}

void func_80717D4C(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk344 = arg0->unk344 - (arg0->unk35C / 100.0);
}

void func_80717D84(Struct80717D84 *arg0, s8 *arg1) {
    if (arg0->unk35C < arg0->unk36D) {
        arg0->unk36D -= arg0->unk35C;
        return;
    }
    arg0->unk36D = 0;
    *arg1 = 1;
}

void func_80717DB4(Struct80717D84 *arg0, s32 arg1) {
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
    arg0->unk340 = (func_80612794(temp->unk8) * 6.0) + temp->unk0;
    arg0->unk348 = (func_80612794(temp->unkA) * 6.0) + temp->unk4;
    temp->unk8 += temp->unkC;
    temp->unkA += temp->unkE;
    arg0->unk344 = arg0->unk344 - (arg0->unk35C / 100.0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717F1C.s")

extern f32 D_8075E728;
extern f32 D_8075E72C;
extern f32 D_8075E730;
extern f64 D_8075E738;

/*
// TODO: Close, rodata?
void func_80717F1C(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_f32 *var_v0;
    Actor *temp_s0;

    if (arg0->unk384 == NULL) {
        temp_s0 = arg0->unk338;
        var_v0 = malloc(0x10);
        arg0->unk384 = var_v0;
        if (temp_s0 != NULL) {
            var_v0->unk0 = func_80612794(temp_s0->unkEE) * (temp_s0->unkB8 * D_8075E728);
            var_v0->unk4 = func_80612790(temp_s0->unkEE) * (temp_s0->unkB8 * D_8075E72C);
        } else {
            var_v0->unk0 = 0.0f;
            var_v0->unk4 = 0.0f;
        }
        var_v0->unk8 = arg0->unk360;
        var_v0->unkC = D_8075E730;
    }
    var_v0 = arg0->unk384;
    arg0->unk344 -= (arg0->unk35C / 100.0);
    arg0->unk340 += var_v0->unk0;
    arg0->unk348 += var_v0->unk4;
    var_v0->unk0 = var_v0->unk0 * D_8075E738;
    var_v0->unk4 = var_v0->unk4 * D_8075E738;
}
*/

extern f64 D_8075E740;
extern s16 D_807502D0;
extern s32 D_80718380; // Function pointer?
extern s32 D_8071FEF4;

void func_80718080(Struct80717D84 *arg0, s32 arg1) {
    func_80717F1C(arg0, arg1);
    arg0->unk360 = arg0->unk384_f32->unkC * arg0->unk384_f32->unk8;
    arg0->unk364 = arg0->unk360;
    if (arg0->unk384_f32->unkC < 2.0f) {
        arg0->unk384_f32->unkC += D_8075E740;
    }
}

void func_807180F4(s32 arg0, s32 arg1) {
    func_80717D4C(arg0, arg1);
    func_80716FB4(arg0, arg1);
}

void func_80718124(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_807149B8(1);
    func_80714998(3);
    func_8071498C(&D_80718380);
    func_80714CC0(&D_8071FEF4, arg0, arg1, arg2, arg3);
}

void func_80718188(Struct80717D84 *arg0, s8 *arg1) {
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(2);
        arg0->unk384_s16->unk0 = 0;
    }
    arg0->unk344 += arg0->unk384_s16->unk0;
    arg0->unk384_s16->unk0 -= 1;
    if (arg0->unk384_s16->unk0 < D_807502D0) {
        arg0->unk384_s16->unk0 = D_807502D0;
    }
    if (arg0->unk344 < arg0->unk35C) {
        *arg1 = 1;
        func_80718124(arg0->unk360 * 1.5, arg0->unk340, arg0->unk35C, arg0->unk348);
    }
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071827C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718380.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807184F4.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807186C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807189BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071910C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807195D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807197B4.s")

extern f64 D_8075E888;
extern f64 D_8075E890;
extern f64 D_8075E898;
extern f32 D_8075E8A0;
extern f64 D_8075E8A8;

void func_80719A0C(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp;
    f32 *temp_v0;
    f32 *var_v1;
    f32 temp2;

    if (arg0->unk384 == NULL) {
        temp_v0 = malloc(8);
        arg0->unk384 = temp_v0;
        temp_v0[0] = (arg0->unk360 / D_8075E888) * 2.5;
        temp_v0[1] = (object_timer * 0x28U) + (arg0->unk35C << 9);
    }
    var_v1 = arg0->unk384;
    var_v1[0] -= D_8075E890;
    if (var_v1[0] < D_8075E898) {
        var_v1[0] = D_8075E8A0;
    }
    temp = func_80612794(var_v1[1]) * var_v1[0];
    temp2 = func_80612790(var_v1[1]) * var_v1[0];
    arg0->unk340 += temp;
    arg0->unk348 += temp2;
}

void func_80719B88(Struct80717D84 *arg0, s8 *arg1) {
    func_80719A0C(arg0, arg1);
    arg0->unk344 += D_8075E8A8;
    arg0->unk36D -= MIN(arg0->unk36D, 0x10);
    if (!(arg0->unk36D)) {
        *arg1 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80719C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80719EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A1E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071AADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071ABDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B2EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C818.s")

/*
// TODO: Is this a different struct?
// 0x35C is alpha in this function
extern u8 D_807444FC;
extern f64 D_8075E9C8;

void func_8071C818(otherSpriteControl *arg0, s8 *arg1) {
    float sp70[4][4];
    float sp30[4][4];
    f64 temp_f2;

    temp_f2 = D_8075E9C8;
    arg0->xScale -= temp_f2;
    arg0->yScale -= temp_f2;
    if (arg0->xScale <= 0.0f) {
        *arg1 = 1;
    }
    arg0->unk35C += 5;
    guScaleF(&sp70, arg0->xScale, arg0->yScale, 0.0f);
    guRotateF(&sp30, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70, &sp30, &sp70);
    guMtxF2L(&sp70, arg0 + (D_807444FC << 6) + 0x128);
    arg0->unk32C = 2;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071CDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D28C.s")

// More sprite stuff?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071DB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071DC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E3EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EEE0.s")

extern f64 D_8075EAB8;
extern f64 D_8075EAC0;

void func_8071EFDC(Struct80717D84 *arg0, s8 *arg1) {
    f64 temp = D_8075EAB8;
    arg0->unk36D -= 5;
    arg0->unk360 *= temp;
    arg0->unk364 *= temp;
    if (arg0->unk36D < 6) {
        *arg1 = 1;
    }
}

// TODO: Which struct is this?
typedef struct {
    u8 unk0[0x340 - 0x0];
    f32 unk340;
    f32 unk344;
    f32 unk348;
    s16 unk34C;
    s16 unk34E;
} Struct8071F034_arg0;

void func_8071F034(Struct8071F034_arg0 *arg0, s32 arg1) {
    if (arg0->unk34E == 0) {
        arg0->unk340 = player_pointer->x_position;
        arg0->unk344 = player_pointer->y_position;
        arg0->unk348 = player_pointer->z_position;
    }
}

void func_8071F078(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1[0] = (((rand() >> 0xF) % 100) / 10.0) + 2.0;
        var_v1[1] = -8.0 - (((rand() >> 0xF) % 100) / D_8075EAC0);
        arg0->unk35C += (s16)((rand() >> 0xF) % 800) - 0x190;
        arg0->unk35C %= 0xFFF;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 += (var_v1[0] * func_80612794(arg0->unk35C));
    arg0->unk348 += (var_v1[0] * func_80612790(arg0->unk35C));
    arg0->unk344 += var_v1[1];
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F444.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F660.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F758.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F8E4.s")
