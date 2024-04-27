#include <ultra64.h>
#include "functions.h"

extern Struct80717D84 *D_minecart_80028C30;

extern s32 D_global_asm_8071FEF4;
extern s32 D_global_asm_8071FFA0; // TODO: Datatype

extern s32 D_global_asm_8074E880[]; // TODO: Datatype

extern u8 D_global_asm_8074450C;

extern u8 D_global_asm_80750AB4;
extern s16 D_global_asm_807502D0;

extern f32 D_global_asm_8075E728;
extern f32 D_global_asm_8075E72C;
extern f32 D_global_asm_8075E730;
extern f64 D_global_asm_8075E738;
extern f64 D_global_asm_8075E740;
extern f64 D_global_asm_8075E888;
extern f64 D_global_asm_8075E890;
extern f64 D_global_asm_8075E898;
extern f32 D_global_asm_8075E8A0;
extern f64 D_global_asm_8075E8A8;
extern f64 D_global_asm_8075EA70;
extern f64 D_global_asm_8075EA78;
extern f32 D_global_asm_8075EA80;
extern f64 D_global_asm_8075EA88;
extern f32 D_global_asm_8075EA90;
extern f64 D_global_asm_8075EA98;
extern f64 D_global_asm_8075EAA0;
extern f64 D_global_asm_8075EAB8;
extern f64 D_global_asm_8075EAC0;
extern f64 D_global_asm_8075EAC8;

extern f64 D_global_asm_8075EAD8;

extern f64 D_global_asm_8075E6D0;
extern f64 D_global_asm_8075E6D8;

extern f64 D_global_asm_8075E708;
extern f64 D_global_asm_8075E710;
extern f64 D_global_asm_8075E718;
extern f64 D_global_asm_8075E720;

extern f64 D_global_asm_8075E770;
extern f64 D_global_asm_8075E778;
extern f64 D_global_asm_8075E780;

extern f32 D_global_asm_8075E8B0;
extern f32 D_global_asm_8075E8B4;
extern f64 D_global_asm_8075E8B8;
extern f32 D_global_asm_8075E8C0;
extern f64 D_global_asm_8075E8C8;
extern f64 D_global_asm_8075E8D0;
extern f32 D_global_asm_8075E8D8;
extern f32 D_global_asm_8075E8DC;
extern f32 D_global_asm_8075E8E0;

extern f64 D_global_asm_8075E8F8;

extern f32 D_global_asm_8075E950;
extern f32 D_global_asm_8075E954;
extern f32 D_global_asm_8075E958;
extern f32 D_global_asm_8075E95C;
extern f32 D_global_asm_8075E960;
extern f32 D_global_asm_8075E964;
extern f32 D_global_asm_8075E978;
extern f64 D_global_asm_8075E980;
extern f64 D_global_asm_8075E990;
extern f32 D_global_asm_8075E998;
extern f32 D_global_asm_8075EA28;
extern f32 D_global_asm_8075EA2C;
extern f64 D_global_asm_8075EA30;
extern f32 D_global_asm_8075EA38;
extern f64 D_global_asm_8075EA40;
extern f64 D_global_asm_8075EA48;
extern f32 D_global_asm_8075EA50;

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

void func_global_asm_80714670(void) {
    D_global_asm_807FDB00 = NULL;
    D_global_asm_807FDB04 = NULL;
    D_global_asm_807FDB08 = 0;
    func_global_asm_80714A9C();
}

s32 func_global_asm_807146A4(s32 arg0) {
    Struct807FDB00 *var_v1;

    var_v1 = D_global_asm_807FDB00;
    while (var_v1 != NULL) {
        if (arg0 == var_v1->unk4) {
            return var_v1->unk0;
        }
        var_v1 = var_v1->next;
    }
    return D_global_asm_807FDB00->unk0;
}

// TODO: Struct?
void func_global_asm_807146E0(u8 *arg0, u8 *arg1, u8 *arg2) {
    *arg1 = arg0[4];
    *arg2 = arg0[5];
}

// TODO: Struct?
void func_global_asm_807146F4(s16 *arg0, s16 *arg1, s16 *arg2) {
    *arg1 = arg0[7];
    *arg2 = arg0[8];
}

// TODO: Struct?
void func_global_asm_80714708(u8 *arg0, s16 *arg1, s16 *arg2) {
    u8 pad1F;
    u8 pad1E;
    u8 pad1D;
    u8 pad1C;
    u8 sp1B;
    u8 sp1A;

    func_global_asm_807146E0(arg0, &sp1B, &sp1A);
    func_global_asm_807146F4(arg0, arg1, arg2);
    *arg1 *= sp1B;
    *arg2 *= sp1A;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80714778.s")

void func_global_asm_80714944(s32 arg0) {
    D_global_asm_807FDB30 = arg0;
}

void func_global_asm_80714950(s32 arg0) {
    D_global_asm_807FDB2C = arg0;
}

void func_global_asm_8071495C(void) {
    D_global_asm_807FDB1D = 1;
}

void func_global_asm_8071496C(s16 arg0) {
    D_global_asm_807FDB1A = arg0;
}

void func_global_asm_8071497C(u16 arg0) {
    D_global_asm_807FDB34 = arg0;
}

void func_global_asm_8071498C(void *arg0) {
    D_global_asm_807FDB14 = arg0;
}

void func_global_asm_80714998(u8 arg0) {
    D_global_asm_807FDB1C = arg0;
}

void func_global_asm_807149A8(s16 arg0) {
    D_global_asm_807FDB3A = arg0;
}

void func_global_asm_807149B8(u8 arg0) {
    D_global_asm_807FDB18 = arg0;
}

void changeActorColor(u8 red, u8 green, u8 blue, u8 alpha) {
    D_global_asm_807FDB0C = red;
    D_global_asm_807FDB0D = green;
    D_global_asm_807FDB0E = blue;
    D_global_asm_807FDB0F = alpha;
}

void func_global_asm_807149FC(s32 arg0) {
    D_global_asm_807FDB10 = arg0;
}

void func_global_asm_80714A08(f32 arg0, f32 arg1) {
    D_global_asm_807FDB20 = arg0;
    D_global_asm_807FDB24 = arg1;
    D_global_asm_807FDB28 = 1;
}

void func_global_asm_80714A28(u16 arg0) {
    D_global_asm_807FDB36 = arg0;
}

void func_global_asm_80714A38(u8 arg0) {
   D_global_asm_807FDB36 |= arg0;
}

void func_global_asm_80714A58(u16 arg0) {
    D_global_asm_807FDB38 = arg0;
}

void func_global_asm_80714A68(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_global_asm_807FDB3C = arg0;
    D_global_asm_807FDB3E = arg1;
    D_global_asm_807FDB40 = arg2;
    D_global_asm_807FDB42 = arg3;
}

void func_global_asm_80714A9C(void) {
    D_global_asm_807FDB0F = 0;
    D_global_asm_807FDB10 = 1;
    D_global_asm_807FDB14 = 0;
    D_global_asm_807FDB18 = 0;
    D_global_asm_807FDB1C = 1;
    D_global_asm_807FDB1A = 0;
    D_global_asm_807FDB1D = 0;
    D_global_asm_807FDB28 = 0;
    D_global_asm_807FDB2C = 0;
    D_global_asm_807FDB30 = 0;
    D_global_asm_807FDB36 = 0;
    D_global_asm_807FDB38 = -1;
    D_global_asm_807FDB3C = D_global_asm_8074450C * 0xA;
    D_global_asm_807FDB3E = D_global_asm_8074450C * 0xA;
    D_global_asm_807FDB40 = D_global_asm_8074450C * 0x135;
    D_global_asm_807FDB42 = D_global_asm_8074450C * 0xE5;
    D_global_asm_807FDB3A = 0x258;
}

Struct80717D84 *func_global_asm_80714B84(void *sprite, f32 scale, s32 arg2, s32 boneIndex, u8 arg4) {
    f32 x;
    f32 y;
    f32 z;

    func_global_asm_806335B0(arg2, 1, boneIndex, &x, &y, &z);
    return func_global_asm_80714D08(sprite, scale, x, y, z, NULL, arg2, boneIndex, arg4);
}

Struct80717D84 *func_global_asm_80714C08(void *sprite, f32 scale, Actor *actor, s32 boneIndex, u8 arg4) {
    f32 x;
    f32 y;
    f32 z;

    getBonePosition(actor, boneIndex, &x, &y, &z);
    if (!(actor->object_properties_bitfield & 0x200) && (actor->animation_state != NULL) && (D_global_asm_807FDB36 & 0x80)) {
        func_global_asm_80714A38(0x40);
    }
    return func_global_asm_80714D08(sprite, scale, x, y, z, actor, 0, boneIndex, arg4);
}

Struct80717D84 *drawSpriteAtPosition(void* sprite, f32 scale, f32 x, f32 y, f32 z) {
    return func_global_asm_80714D08(sprite, scale, x, y, z, NULL, 0, 0, 0);
}

Struct80717D84 *func_global_asm_80714D08(void *sprite, f32 scale, f32 x, f32 y, f32 z, Actor *actor, s32 arg6, s32 boneIndex, u8 arg8) {
    Struct80717D84 *sp2C;
    s32 i;
    s32 var_v0;
    Struct807FDB00 *var_s0;

    func_global_asm_80714778(scale);
    var_s0 = D_global_asm_807FDB00;
    var_v0 = 0;
    while (!var_v0 && var_s0 != NULL) {
        if (sprite == var_s0->unk0) {
            var_v0 = 1;
        } else {
            var_s0 = var_s0->next;
        }
    }
    if (var_v0 == 0) {
        func_global_asm_80714A9C();
        return NULL;
    }
    sp2C = malloc(sizeof(Struct80717D84));
    if (D_global_asm_807FDB04 != NULL) {
        D_global_asm_807FDB08->unk39C = sp2C;
        sp2C->unk398 = D_global_asm_807FDB08;
    } else {
        D_global_asm_807FDB04 = sp2C;
        sp2C->unk398 = NULL;
    }
    D_global_asm_807FDB08 = sp2C;
    if (D_global_asm_807FDB1D != 0) {
        x *= 4.0f;
        y *= 4.0f;
        z *= 4.0f;
        scale *= 4.0f;
        D_global_asm_807FDB20 *= 4.0f;
        D_global_asm_807FDB24 *= 4.0f;
    }
    sp2C->unk340 = x;
    sp2C->unk344 = y;
    sp2C->unk348 = z;
    if (D_global_asm_807FDB28 != 0) {
        sp2C->unk360 = D_global_asm_807FDB20;
        sp2C->unk364 = D_global_asm_807FDB24;
    } else {
        sp2C->unk360 = scale;
        sp2C->unk364 = scale;
    }
    if (D_global_asm_807FDB0F != 0) {
        sp2C->unk36A = D_global_asm_807FDB0C; // red
        sp2C->unk36B = D_global_asm_807FDB0D; // green
        sp2C->unk36C = D_global_asm_807FDB0E; // blue
        sp2C->unk36D = D_global_asm_807FDB0F; // alpha
    } else {
        sp2C->unk36A = var_s0->unk10; // red
        sp2C->unk36B = var_s0->unk11; // green
        sp2C->unk36C = var_s0->unk12; // blue
        sp2C->unk36D = var_s0->unk13; // alpha
    }
    sp2C->unk36E = D_global_asm_807FDB18;
    sp2C->unk36F = D_global_asm_807FDB1D;
    sp2C->unk368 = D_global_asm_807FDB1A;
    sp2C->unk380 = var_s0->unk8 * var_s0->unk9;
    sp2C->unk334 = arg8;
    sp2C->unk338 = actor;
    sp2C->unk33C = arg6;
    sp2C->unk33E = boneIndex;
    sp2C->unk34E = D_global_asm_807FDB30;
    sp2C->unk350 = D_global_asm_807FDB1C;
    sp2C->unk351 = 0;
    sp2C->unk354 = D_global_asm_807FDB10;
    sp2C->unk358 = 0;
    sp2C->unk35C = D_global_asm_807FDB2C;
    if (D_global_asm_807FBB64 & 0x100) {
        sp2C->unk34C = 0x7D0;
    } else {
        sp2C->unk34C = D_global_asm_807FDB3A;
    }
    sp2C->unk330 = var_s0;
    sp2C->unk39C = 0;
    sp2C->unk328 = D_global_asm_807FDB14;
    sp2C->unk384 = 0;
    sp2C->unk388 = D_global_asm_807FDB38;
    sp2C->unk38A = -1;
    sp2C->unk38C = D_global_asm_807FDB36;
    sp2C->unk38E = D_global_asm_807FDB3C;
    sp2C->unk390 = D_global_asm_807FDB3E;
    sp2C->unk392 = D_global_asm_807FDB40;
    sp2C->unk394 = D_global_asm_807FDB42;
    for (i = 0; i < D_global_asm_80750AB4; i++) {
        sp2C->unk0[i].unk0 = malloc(0x200);
        sp2C->unk0[i].unk4 = malloc(0x200);
    }
    sp2C->unk20 = D_global_asm_80750AB4;
    func_global_asm_8071509C(sp2C);
    func_global_asm_80714A9C();
    return sp2C;
}

// Doable, needs a struct array size 0x10 at Struct807FDB04->unk28
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071509C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80715270.s")

void func_global_asm_8071586C(Actor *arg0) {
    Struct807FDB04 *var_s0;

    var_s0 = D_global_asm_807FDB04;
    while (var_s0 != NULL) {
        if (arg0 == var_s0->unk338) {
            func_global_asm_80715908(var_s0);
        }
        var_s0 = var_s0->next;
    }
}

void func_global_asm_807158C0(void) {
    Struct807FDB04 *temp_s1;
    Struct807FDB04 *var_s0;

    var_s0 = D_global_asm_807FDB04;
    while (var_s0 != NULL) {
        temp_s1 = var_s0->next;
        func_global_asm_80715908(var_s0);
        var_s0 = temp_s1;
    }
}

// OSTime
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80715908.s")

/*
extern s32 D_80000310;
extern void *D_global_asm_807FDB04;
extern void *D_global_asm_807FDB08;

void func_global_asm_80715908(void *arg0) {
    ? sp3F;
    s32 var_s1;
    void *temp_a0;
    void *temp_s0;
    void *temp_s1;
    void *var_s0;

    if (arg0->unk36F == 0) {
        if (arg0->unk38C & 4) {
            func_global_asm_80630588(0, arg0, 4, &sp3F);
        } else {
            func_global_asm_8062D26C(arg0);
        }
    } else {
        func_global_asm_80630588(0, arg0, 3, &sp3F);
    }
    temp_a0 = arg0->unk384;
    if (temp_a0 != NULL) {
        func_global_asm_8061134C(temp_a0);
    }
    var_s1 = 0;
    var_s0 = arg0;
    if (arg0->unk20 > 0) {
        do {
            func_global_asm_8061134C(var_s0->unk0);
            func_global_asm_8061134C(var_s0->unk4);
            var_s1 += 1;
            var_s0 += 8;
        } while (var_s1 < arg0->unk20);
    }
    if (D_80000310 != 0x17D9) {
        osSetTime(func_global_asm_806119A0());
    }
    temp_s0 = arg0->unk398;
    temp_s1 = arg0->unk39C;
    func_global_asm_8061134C(arg0);
    if (temp_s0 != NULL) {
        temp_s0->unk39C = temp_s1;
    } else {
        D_global_asm_807FDB04 = temp_s1;
    }
    if (temp_s1 != NULL) {
        temp_s1->unk398 = temp_s0;
        return;
    }
    D_global_asm_807FDB08 = temp_s0;
}
*/

// Get pointer table file
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80715A3C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80715B30.s")

void func_global_asm_80715E38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f2;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg1 - arg4;
    temp_f16 = arg2 - arg5;
    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f16 * temp_f16));
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80715E94.s")

void func_global_asm_80716F10(Struct80717D84 *arg0, s32 arg1) {
    f32 sp68[4][4];
    f32 sp28[4][4];
    guScaleF(&sp68[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp28[0], arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp68[0], &sp28[0], &sp68[0]);
    guMtxF2L(&sp68[0], &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_80716FB4;

void func_global_asm_80716FB4(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    Struct80717D84_unk384_80716FB4 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80716FB4));
        arg0->unk384->unk0 = (func_global_asm_806119A0() % 36000U) / 100;
        arg0->unk384->unk4 = (func_global_asm_806119A0() % 400U) / 100;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 += var_v1->unk4;
    guScaleF(&sp70[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30[0], arg0->unk384->unk0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guMtxF2L(&sp70[0], &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80717100.s")

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
    arg0->unk340 += (D_global_asm_8075E6D0 * var_v1->unk4 * func_global_asm_80612794(var_v1->unk0));
    arg0->unk348 += (D_global_asm_8075E6D8 * var_v1->unk4 * func_global_asm_80612790(var_v1->unk0));
    var_v1->unk0 += 0x50;
    var_v1->unk4 += var_v1->unk2;
    if (arg0->unk35C != 0) {
        func_global_asm_806595F0(1);
        createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 40.0f, 0, 0xFF, 0xFF, (rand() >> 0xF) % 255);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80717404.s")

extern f64 D_global_asm_8075E6E0;
extern f64 D_global_asm_8075E6E8;
extern f64 D_global_asm_8075E6F0;
extern f64 D_global_asm_8075E6F8;
extern f64 D_global_asm_8075E700;

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
        arg0->unk340 = arg0->unk340 + (4.0 * (D_global_asm_8075E6E0 * temp_s2_2->unk2 * func_global_asm_80612794(var_v1->unk0)));
        arg0->unk344 = arg0->unk344 + (4.0 * (D_global_asm_8075E6E8 * temp_s2_2->unk2 * func_global_asm_80612790(var_v1->unk0)));
    } else {
        arg0->unk340 = arg0->unk340 + (D_global_asm_8075E6F0 * temp_s2_2->unk2 * func_global_asm_80612794(var_v1->unk0));
        arg0->unk348 = arg0->unk348 + (D_global_asm_8075E6F8 * temp_s2_2->unk2 * func_global_asm_80612790(var_v1->unk0));
        if (temp_s2_2->unk0 == 0) {
            arg0->unk344 = arg0->unk344 + var_v1->unk8;
            var_v1->unk8 = var_v1->unk8 - 0.5;
        } else {
            arg0->unk344 = arg0->unk344 + (var_v1->unk8 * D_global_asm_8075E700);
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
        func_global_asm_8071498C(&func_global_asm_80717404);
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
    arg0->unk340 += (D_global_asm_8075E708 * arg0->unk35C * func_global_asm_80612794(var_v1->unk0));
    arg0->unk344 += (D_global_asm_8075E710 * arg0->unk35C * func_global_asm_80612790(var_v1->unk0));
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
            temp_f0 = arg0->unk338->animation_state->scale_y / D_global_asm_8075E718;
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
    arg0->unk344 += (temp_s1->unk8 * D_global_asm_8075E720);
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
            var_v0->unk0 = func_global_asm_80612794(temp_s0->unkEE) * (temp_s0->unkB8 * D_global_asm_8075E728);
            var_v0->unk4 = func_global_asm_80612790(temp_s0->unkEE) * (temp_s0->unkB8 * D_global_asm_8075E72C);
        } else {
            var_v0->unk0 = 0.0f;
            var_v0->unk4 = 0.0f;
        }
        var_v0->unk8 = arg0->unk360;
        var_v0->unkC = D_global_asm_8075E730;
    }
    var_v0 = arg0->unk384;
    temp = D_global_asm_8075E738;
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
        arg0->unk384_f32->unkC += D_global_asm_8075E740;
    }
}

void func_global_asm_807180F4(s32 arg0, s32 arg1) {
    func_global_asm_80717D4C(arg0, arg1);
    func_global_asm_80716FB4(arg0, arg1);
}

void func_global_asm_80718124(f32 scale, f32 x, f32 y, f32 z) {
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_8071498C(&func_global_asm_80718380);
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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071827C.s")

extern f64 D_global_asm_8075E748;

/*
void func_global_asm_8071827C(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];

    guScaleF(&sp70[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30[0], 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guTranslateF(&sp30[0], arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    arg0->unk360 += D_global_asm_8075E748;
    arg0->unk364 += D_global_asm_8075E748;
    if (arg0->unk36D >= 0xA) {
        arg0->unk36D -= 0xA;
    } else {
        arg0->unk36D = 0;
    }
    guMtxF2L(&sp70[0], &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}
*/

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
    guScaleF(&sp70[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30[0], 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guRotateF(&sp30[0], *((f32*)arg0->unk384), 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guTranslateF(&sp30[0], arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    if (arg0->unk36D >= 0xA) {
        arg0->unk36D -= 0xA;
    } else {
        arg0->unk36D = 0;
    }
    guMtxF2L(&sp70[0], &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
    if (arg0->unk36D == 0) {
        *arg1 = 1;
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_807184F4.s")

extern f64 D_global_asm_8075E750;

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_807184F4;

/*
void func_global_asm_807184F4(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    Actor *temp_v0_2;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        arg0->unk384_f32->unk0 = 0.0f;
        arg0->unk384_f32->unk4 = (func_global_asm_806119A0() % 400U) / 100;
    }
    guScaleF(&sp70[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30[0], arg0->unk384->unk0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guRotateF(&sp30[0], 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    temp_v0_2 = arg0->unk338;
    if (temp_v0_2 != NULL) {
        arg0->unk344 = temp_v0_2->unkAC;
    }
    guTranslateF(&sp30[0], arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guMtxF2L(&sp70[0], arg0->unk128[D_global_asm_807444FC]);
    if (arg0->unk35C != 0) {
        arg0->unk384_f32->unk0 += arg0->unk384_f32->unk4;
        // TODO: Need rodata
        arg0->unk360 -= D_global_asm_8075E750;
        arg0->unk364 -= D_global_asm_8075E750;
        if (arg0->unk36D >= 0xA) {
            arg0->unk36D -= 0xA;
        } else {
            arg0->unk36D = 0;
        }
    }
    arg0->unk32C = 3;
}
*/

// Matrix stuff
// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_807186C8.s")

void func_global_asm_807189BC(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_807189BC *var_v1;
    Actor *sp20;

    sp20 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = MAX(2.0, sp20->unkB8 * D_global_asm_8075E770);
        var_v1->unk2 = sp20->y_rotation;
        var_v1->unk4 = ((rand() >> 0xF) % 1000) + 0xC8;
        arg0->unk360 += (((rand() >> 0xF) % 100) / D_global_asm_8075E778);
        arg0->unk364 = arg0->unk360;
        var_v1->unk6 = sp20->unkAC;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 -= (var_v1->unk0 * func_global_asm_80612794(var_v1->unk2));
    arg0->unk348 -= (var_v1->unk0 * func_global_asm_80612790(var_v1->unk2));
    arg0->unk344 += (var_v1->unk4 / D_global_asm_8075E780);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80718BF4.s")

// Matrix stuff, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071910C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_807195D4.s")

extern f32 D_global_asm_8075E840;
extern f32 D_global_asm_8075E844;
extern f64 D_global_asm_8075E848;

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
    arg0->unk340 += (f32)(func_global_asm_80612D1C(arg0->unk384_f32->unk0 * D_global_asm_8075E840) * 2.5);
    arg0->unk344 += (f32)(3.5);
    arg0->unk348 += (f32)(func_global_asm_80612D10(arg0->unk384_f32->unk0 * D_global_asm_8075E844) * 2.5);
    arg0->unk384_f32->unk0 += 8.0;
    arg0->unk384_f32->unk4 += D_global_asm_8075E848;
    guScaleF(&sp6C[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp2C[0], arg0->unk384->unk4, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp6C[0], &sp2C[0], &sp6C[0]);
    guMtxF2L(&sp6C[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_807197B4.s")

extern f64 D_global_asm_8075E850;
extern f64 D_global_asm_8075E858;
extern f64 D_global_asm_8075E860;
extern f64 D_global_asm_8075E868;
extern f64 D_global_asm_8075E870;
extern f64 D_global_asm_8075E878;
extern f64 D_global_asm_8075E880;

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
    var_v1->unk4 += D_global_asm_8075E850;
    var_v1->unk8 += D_global_asm_8075E850;
    arg0->unk340 -= func_global_asm_80612D1C(arg0->unk35C * 2) * D_global_asm_8075E858;
    arg0->unk344 += D_global_asm_8075E860;
    arg0->unk348 -= func_global_asm_80612D10(arg0->unk35C * 2) * D_global_asm_8075E868;
    arg0->unk360 = var_v1->unk4;
    arg0->unk364 = var_v1->unk8;
    arg0->unk360 *= (1.0 + (func_global_asm_80612D1C(var_v1->unk0 * D_global_asm_8075E870) * D_global_asm_8075E880));
    arg0->unk364 *= (1.0 + (func_global_asm_80612D1C(var_v1->unk0 * D_global_asm_8075E878) * D_global_asm_8075E880));
    var_v1->unk0++;
    if ((arg0->unk354 - arg0->unk358) < 0xA) {
        if (arg0->unk36D >= 0x16) {
            arg0->unk36D -= 0x14;
        } else {
            arg0->unk36D = 0;
        }
    }
    guScaleF(&sp78[0], arg0->unk360, arg0->unk364, 0.0f);
    guMtxF2L(&sp78[0], arg0->unk128[D_global_asm_807444FC]);
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
        temp_v0[0] = (arg0->unk360 / D_global_asm_8075E888) * 2.5;
        temp_v0[1] = (object_timer * 0x28U) + (arg0->unk35C << 9);
    }
    var_v1 = arg0->unk384;
    var_v1[0] -= D_global_asm_8075E890;
    if (var_v1[0] < D_global_asm_8075E898) {
        var_v1[0] = D_global_asm_8075E8A0;
    }
    temp = func_global_asm_80612794(var_v1[1]) * var_v1[0];
    temp2 = func_global_asm_80612790(var_v1[1]) * var_v1[0];
    arg0->unk340 += temp;
    arg0->unk348 += temp2;
}

void func_global_asm_80719B88(Struct80717D84 *arg0, s8 *arg1) {
    func_global_asm_80719A0C(arg0, arg1);
    arg0->unk344 += D_global_asm_8075E8A8;
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
        var_v1->unkC = arg0->unk35C * D_global_asm_8075E8B0;
        var_v1->unk10 = ((arg0->unk35C % 3) * 0x64) - 0x64;
        var_v1->unk14 = D_global_asm_8075E8B4;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += D_global_asm_8075E8B8;
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
        arg0->unk384->unk0 = D_global_asm_8075E8C0;
        arg0->unk384->unk4 = arg0->unk35C;
    }
    arg0->unk384->unk0 -= D_global_asm_8075E8C8;
    if (arg0->unk384->unk0 < D_global_asm_8075E8D0) {
        arg0->unk384->unk0 = D_global_asm_8075E8D8;
    }
    temp = func_global_asm_80612D1C(D_global_asm_8075E8DC * arg0->unk384->unk4);
    sp1C = (temp * arg0->unk384->unk0);
    temp = func_global_asm_80612D10(D_global_asm_8075E8E0 * arg0->unk384->unk4);
    temp_f2 = (temp * arg0->unk384->unk0);
    arg0->unk340 += sp1C;
    arg0->unk348 += temp_f2;
    arg0->unk344 += 1.0f;
}

extern f64 D_global_asm_8075E8E8;

void func_global_asm_8071A038(Struct80717D84 *arg0, s32 arg1) {
    f32 sp78[4][4];
    f32 sp38[4][4];
    f32 sp34;
    f32 temp_f0;
    u8 *temp_v0;
    s32 pad;
    f32 sp24;
    f32 temp_f12;

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
    temp_f12 = (temp_f0 / 56.0) * D_global_asm_8075E8E8;
    sp24 = ABS(func_global_asm_80612D1C(temp_f12));
    guScaleF(&sp78[0], arg0->unk360, arg0->unk364, 0.0f);
    guTranslateF(&sp38[0], arg0->unk340 + (sp34 * 0.5), arg0->unk344 - (sp24 * 15.0f), arg0->unk348);
    guMtxCatF(&sp78[0], &sp38[0], &sp78[0]);
    guMtxF2L(&sp78[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071A1E4.s")

extern f64 D_global_asm_8075E8F0;

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
        var_v0->unk4 -= D_global_asm_8075E8F0;
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
    if (D_global_asm_8075E8F8 < var_f0) {
        var_f0 = 1.0f;
    }
    if (extra_player_info_pointer->vehicle_actor_pointer == arg0->unk35C_actor) {
        if (arg0 == D_minecart_80028C30) {
            func_global_asm_806595F0(1);
            createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f0 * 50.0, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071A674.s")

extern Struct80717D84 *D_8002FBB0;
extern f64 D_global_asm_8075E900;

/*
// TODO: Close...
void func_global_asm_8071A674(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    Struct80717D84 **var_v0;

    var_v0 = &D_8002FBB0;
    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (D_global_asm_8075E900 < var_f0) {
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

extern f64 D_global_asm_8075E908;
extern f64 D_global_asm_8075E910;

void func_global_asm_8071A8B0(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f16;
    s16 temp_v0;

    temp_v0 = arg0->unk330->unk16;
    var_f0 = (f32)(temp_v0 - arg0->unk34E) / temp_v0;
    if (D_global_asm_8075E908 < var_f0) {
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
    if (D_global_asm_8075E910 < var_f0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071ABDC.s")

extern f64 D_global_asm_8075E930;
extern f64 D_global_asm_8075E938;
extern f64 D_global_asm_8075E940;
extern f64 D_global_asm_8075E948;

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
            guScaleF(&sp78[0], arg0->unk360, arg0->unk364, 0.0f);
            guRotateF(&sp38[0], sp34, 0.0f, 0.0f, 1.0f);
            guMtxCatF(&sp78[0], &sp38[0], &sp78[0]);
            guMtxF2L(&sp78[0], arg0->unk384);
            arg0->unk36D = 0xC8;
        }
        if (temp_s1->unk58 == 0xC5 && arg0->unk360 < 0.5) {
            arg0->unk340 -= (10.0 * arg0->unk360 * func_global_asm_80612794(temp_s1->unkEE));
            arg0->unk348 -= (10.0 * arg0->unk360 * func_global_asm_80612790(temp_s1->unkEE));
        } else {
            arg0->unk340 += (temp_s1->unkB8 * D_global_asm_8075E930 * func_global_asm_80612794(temp_s1->unkEE));
            arg0->unk348 += (temp_s1->unkB8 * D_global_asm_8075E938 * func_global_asm_80612790(temp_s1->unkEE));
            arg0->unk344 -= D_global_asm_8075E940;
        }
        if (temp_s1->unk58 == 0xFE) {
            arg0->unk344 -= D_global_asm_8075E948;
        }
        memcpy(arg0->unk128[D_global_asm_807444FC], arg0->unk384, 0x40);
        arg0->unk32C = 2;
        return;
    }
    *arg1 = 1;
}

void func_global_asm_8071B1AC(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk344 -= (D_global_asm_8075E950 * 0.5);
    arg0->unk340 += (D_global_asm_8075E954 * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (D_global_asm_8075E958 * func_global_asm_80612790(arg0->unk35C));
}

void func_global_asm_8071B24C(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk344 += (D_global_asm_8075E95C * 0.5);
    arg0->unk340 += (D_global_asm_8075E960 * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (D_global_asm_8075E964 * func_global_asm_80612790(arg0->unk35C));
}

extern f32 D_global_asm_8075E968;
extern f64 D_global_asm_8075E970;

void func_global_asm_8071B2EC(Struct80717D84 *arg0, s32 arg1) {
    f32 sp24;
    Struct80717D84_unk384_8071B2EC *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = arg0->unk338->unkEE;
        arg0->unk384->unk4 = arg0->unk338->unkB8 + 30.0f;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += (D_global_asm_8075E968 * 0.5);
    sp24 = var_v1->unk4 * D_global_asm_8075E970;
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

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk338->unkB8;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += (D_global_asm_8075E978 * 0.5);
    temp_f6 = *var_v1 * D_global_asm_8075E980;
    arg0->unk340 += (temp_f6 * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (temp_f6 * func_global_asm_80612790(arg0->unk35C));
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071B520.s")

extern f64 D_global_asm_8075E988;

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
            arg0->unk344 -= (D_global_asm_8075E988 * ((0xE - (20.0f - (arg0->unk34E + ((f32)arg0->unk351 / arg0->unk350)))) / 14.0));
        }
    }
    if (arg0->unk34E == 0x10) {
        arg0->unk350 = 0xA;
    }
    guScaleF(&sp80[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp40[0], (arg0->unk35C * 0x168) / 4096, 0.0f, 1.0f, 0.0f);
    guMtxCatF(&sp80[0], &sp40[0], &sp80[0]);
    guTranslateF(&sp40[0], arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(&sp80[0], &sp40[0], &sp80[0]);
    guMtxF2L(&sp80[0], arg0->unk128[D_global_asm_807444FC]);
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
    if (D_global_asm_8075E990 < var_f0) {
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
        playSoundAtPosition(arg0->unk340, arg0->unk344, arg0->unk348, 0x14F, 0xFF, 0x7F, 0x1E, 0x4B, D_global_asm_8075E998, 0);
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
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_80714950(-0xA);
        func_global_asm_807149B8(1);
        changeActorColor(0x9B, 0x9B, 0x9B, 0x96);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, 0.8f, (((rand() >> 0xF) % 65535) & 7) + arg0->unk340, arg0->unk344 + 10.0f, (((rand() >> 0xF) % 65535) & 7) + arg0->unk348);
    }
}

extern f64 D_global_asm_8075E9A0;

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
        arg0->unk384->unk4 = (func_global_asm_806119A0() % 10000U) / D_global_asm_8075E9A0;
        var_v1 = arg0->unk384;
    }
    arg0->unk344 = arg0->unk344 + (var_v1->unk4 + 1.0);
    guScaleF(&sp70[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30[0], arg0->unk384->unk0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guMtxF2L(&sp70[0], arg0->unk128[D_global_asm_807444FC]);
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

extern f64 D_global_asm_8075E9A8;
extern f64 D_global_asm_8075E9B0;

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
        var_f12 = arg0->unk364 * ((func_global_asm_80612794(sp24->unk2) * D_global_asm_8075E9A8) + D_global_asm_8075E9B0);
        sp24->unk2 += 0xAA;
        sp24->unk2 &= 0xFFF;
    }
    guScaleF(&sp70[0], arg0->unk360, var_f12, 0.0f);
    guTranslateF(&sp30[0], arg0->unk340 + (sp28->unk4 * sp20), arg0->unk344 + (sp28->unk8 * sp20), arg0->unk348);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guMtxF2L(&sp70[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071C004.s")

extern s32 D_global_asm_807201D4; // TODO: Datatype
void func_global_asm_8071C24C(Struct80717D84 *arg0, u8 *arg1);

/*
void func_global_asm_8071C004(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp_f0;
    s32 pad3;
    s32 pad2;
    s16 sp44[3];
    f32 temp;

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
                func_global_asm_8071498C(&func_global_asm_8071C24C);
                drawSpriteAtPosition(&D_global_asm_807201D4, 0.8f, arg0->unk340, arg0->unk344, arg0->unk348);
            } else {
                temp_f0 = arg0->unk330->unk16 * 2;
                temp = 200.0f * (f32)(1.0 - ((temp_f0 - ((arg0->unk34E * 2) + arg0->unk351)) / temp_f0));
                createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, temp, 0, 0xFF, sp44[1], sp44[2]);
            }
            break;
        case 1:
            temp_f0 = arg0->unk330->unk16 * 2;
            temp = 200.0f * ((temp_f0 - ((arg0->unk34E * 2) + arg0->unk351)) / temp_f0);
            createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, temp, 0, 0xFF, sp44[1], sp44[2]);
            break;
    }
}
*/

void func_global_asm_8071C004(Struct80717D84 *arg0, s8 *arg1);

extern f64 D_global_asm_8075E9B8;
extern s32 D_global_asm_8071FB54;

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
    arg0->unk384_f32->unk0 -= D_global_asm_8075E9B8;
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
        func_global_asm_8071498C(&func_global_asm_8071C004);
        func_global_asm_80714944(7);
        drawSpriteAtPosition(&D_global_asm_8071FB54, 0.667f, arg0->unk340, y + 10.0f, arg0->unk348);
    }
    createLight(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 200.0f, 0, lightColor[0], lightColor[1], lightColor[2]);
}

// Weird m2c errors
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071C48C.s")

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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071C818.s")

extern f64 D_global_asm_8075E9C8;

void func_global_asm_8071C818(Struct80717D84 *arg0, s8 *arg1);

/*
void func_global_asm_8071C818(Struct80717D84 *arg0, s8 *arg1) {
    f64 temp = D_global_asm_8075E9C8;
    float sp70[4][4];
    float sp30[4][4];

    arg0->unk360 -= temp;
    arg0->unk364 -= temp;
    if (arg0->unk360 <= 0.0f) {
        *arg1 = 1;
    }
    arg0->unk35C = arg0->unk35C + 5;
    guScaleF(&sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70, &sp30, &sp70);
    guMtxF2L(&sp70, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

extern f64 D_global_asm_8075E9D0;

void func_global_asm_8071C914(Struct80717D84 *arg0, s32 arg1) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    f32 temp_f0;

    arg0->unk360 = arg0->unk360 * D_global_asm_8075E9D0;
    arg0->unk35C += 0xA;
    arg0->unk364 = arg0->unk360;
    guScaleF(&sp70[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp30[0], arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp70[0], &sp30[0], &sp70[0]);
    guMtxF2L(&sp70[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071C9E8.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071CDE0.s")

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

extern f32 D_global_asm_8075E9E8;
extern f64 D_global_asm_8075E9F0;
extern f64 D_global_asm_8075E9F8;
extern f64 D_global_asm_8075EA00;

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
        var_v1->unk8 = func_global_asm_806119FC() * D_global_asm_8075E9E8;
        var_v1->unkC = (func_global_asm_806119FC() * 90.0f) + 10.0f;
        var_v1->unk10 = actor->y_rotation;
        var_v1->unk14 = func_global_asm_806119FC() * 30.0f;
        var_v1->unk18 = 0.0f;
        var_v1->unk1C = (((f32)(((rand() >> 0xF) % 255) % 2) * 2)) - 1;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = ((var_v1->unk4 - var_v1->unk0) * D_global_asm_8075E9F0) + var_v1->unk0;
    var_v1->unk14 = ((120.0f - var_v1->unk14) * D_global_asm_8075E9F8) + var_v1->unk14;
    var_v1->unk10 = var_v1->unk10 + (var_v1->unk1C * var_v1->unk14);
    var_v1->unk8 = var_v1->unk8 + var_v1->unkC;
    arg0->unk340 = (func_global_asm_80612794(var_v1->unk10) * var_v1->unk0) + actor->x_position;
    arg0->unk348 = (func_global_asm_80612790(var_v1->unk10) * var_v1->unk0) + actor->z_position;
    arg0->unk344 += (D_global_asm_8075EA00 * func_global_asm_80612794(var_v1->unk8));
    var_v1->unk18 = var_v1->unk18 + 1.0f;
    if (var_v1->unk18 > 45.0f) {
        *arg1 = 1;
    }
    if ((object_timer % (u32)arg0->unk35C) == 0) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714950(0x2A);
        func_global_asm_8071498C(&func_global_asm_8071D260);
        func_global_asm_80714A28(0x20);
        drawSpriteAtPosition(arg0->unk330->unk0, arg0->unk360, arg0->unk340, arg0->unk344, arg0->unk348);
    }
}

extern f64 D_global_asm_8075EA08;

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
    guScaleF(&sp80[0], arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(&sp40[0], 90.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(&sp80[0], &sp40[0], &sp80[0]);
    guTranslateF(&sp40[0], arg0->unk340, arg0->unk344, arg0->unk348);
    guMtxCatF(&sp80[0], &sp40[0], &sp80[0]);
    if (arg0->unk36D >= 9) {
        arg0->unk36D -= 9;
    } else {
        *arg1 = 1;
    }
    arg0->unk360 *= D_global_asm_8075EA08;
    arg0->unk364 = arg0->unk360;
    guMtxF2L(&sp80[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 3;
}

extern f32 D_global_asm_80755674;
extern f32 D_global_asm_80755678;

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

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071D94C.s")

extern f32 D_global_asm_8075EA10;
extern f64 D_global_asm_8075EA18;
extern f32 D_global_asm_8075EA20;
extern f32 D_global_asm_8075EA24;

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
        var_f2 = arg0->unkB8 * D_global_asm_8075EA10;
        if (!(var_f2 < 1.0f)) {
            var_f2 = 1.0f;
        }
        if (var_f2 < D_global_asm_8075EA18) {
            *arg2 = 1;
        }
        sp28 = var_f2 * 1.5f * D_global_asm_8075EA20;
        arg1->unk338 = arg0;
    } else {
        var_f2 = D_global_asm_8075EA24;
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
    f64 var_f2_2;
    f64 var_f2;

    sp20 = D_global_asm_8075EA28;
    sp28 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071DC90));
        var_v0 = arg0->unk384;
        var_v0->unk0 = 0.0f;
        var_v0->unk4 = func_global_asm_806119FC() * D_global_asm_8075EA2C;
        if (func_global_asm_806119FC() > 0.5) {
            var_f2 = func_global_asm_806119FC();
        } else {
            var_f2 = 0.5;
        }
        var_v0->unk8 = var_f2 * D_global_asm_8075EA30;
        if (func_global_asm_806119FC() > 0.5) {
            var_v0->unk8 = -var_v0->unk8;
        }
        var_v0->unkC = func_global_asm_806119FC() * D_global_asm_8075EA38;
        if (func_global_asm_806119FC() > 0.5) {
            var_f2_2 = func_global_asm_806119FC();
        } else {
            var_f2_2 = 0.5;
        }
        var_v0->unk10 = var_f2_2 * D_global_asm_8075EA40;
        if (func_global_asm_806119FC() > 0.5) {
            var_v0->unk10 = -var_v0->unk10;
        }
        if (D_global_asm_8075EA48 < func_global_asm_806119FC()) {
            var_v0->unk14 = (f64)func_global_asm_806119FC();
        } else {
            var_v0->unk14 = D_global_asm_8075EA48;
        }
        sp20 = 1.0f;
    }
    var_v0 = arg0->unk384;
    if (var_v0->unk0 < 1.0f) {
        var_v0->unk0 += D_global_asm_8075EA50;
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
    guScaleF(&sp68[0], arg0->unk360, arg0->unk364, 0.0f);
    guTranslateF(&sp28[0], 0.0f, arg0->unk364 * 20.0f, 0.0f);
    guMtxCatF(&sp68[0], &sp28[0], &sp68[0]);
    guRotateF(&sp28[0], arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(&sp68[0], &sp28[0], &sp68[0]);
    guMtxF2L(&sp68[0], arg0->unk128[D_global_asm_807444FC]);
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

// rodata, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071E3EC.s")

extern f64 D_global_asm_8075EA58;
extern f64 D_global_asm_8075EA60;
extern f32 D_global_asm_8075EA68;
extern f32 D_global_asm_8075EA6C;

/*
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
        temp = D_global_asm_8075EA58;
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
    if (var_v1[0] < D_global_asm_8075EA60) {
        sp4C = var_v1[0] / D_global_asm_8075EA60;
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
            sp40 = D_global_asm_8075EA68;
            func_global_asm_806595F0(3);
            func_global_asm_80659610(1000);
            break;
        case 2:
            sp48 = 1.0f;
            sp44 = 0.5f;
            sp40 = D_global_asm_8075EA6C;
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
*/

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
    var_v1[0] -= D_global_asm_8075EA70;
    if (var_v1[0] < D_global_asm_8075EA78) {
        var_v1[0] = D_global_asm_8075EA80;
    }
    sp24 = func_global_asm_80612794(var_v1[1]) * var_v1[0];
    temp_f12 = func_global_asm_80612790(var_v1[1]) * var_v1[0];
    temp = D_global_asm_8075EA88;
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
        var_v0[0] = func_global_asm_806119FC() * D_global_asm_8075EA90;
        var_v0[1] = ((func_global_asm_806119FC() * 0.5) + 1.0) * 5.0;
        var_v0[2] = 15.0f;
    }
    var_v0 = arg0->unk384;
    var_v0[1] -= 1.0f;
    var_v0[2] *= D_global_asm_8075EA98;
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
    f32 x;
    f32 y;
    f32 z;

    getBonePosition(arg0->unk35C, 1, &x, &y, &z);
    temp = D_global_asm_8075EAA0;
    arg0->unk340 += (x - arg0->unk340) * temp;
    arg0->unk344 += (y - arg0->unk344) * temp;
    arg0->unk348 += (z - arg0->unk348) * temp;
}

void func_global_asm_8071EEA4(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk364 = (arg0->unk35C / 100.0) + 1.0;
}

extern f32 D_global_asm_8075EAA8;
extern f64 D_global_asm_8075EAB0;

void func_global_asm_80612CA0(f32 (*)[4], f32);

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
        var_v1->unk0 = D_global_asm_8075EAA8;
        var_v1->unk4 = arg0->unk360;
        var_v1->unk8 = 0.0f;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = ((var_v1->unk4 - var_v1->unk0) * D_global_asm_8075EAB0) + var_v1->unk0;
    var_v1->unk8 = var_v1->unk8 + 5.0f;
    guScaleF(&sp6C[0], arg0->unk360, arg0->unk364, 0.0f);
    func_global_asm_80612CA0(&sp2C[0], var_v1->unk8);
    guMtxCatF(&sp6C[0], &sp2C[0], &sp6C[0]);
    guMtxF2L(&sp6C[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

void func_global_asm_8071EFDC(Struct80717D84 *arg0, s8 *arg1) {
    f64 temp = D_global_asm_8075EAB8;
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
        var_v1[1] = -8.0 - (((rand() >> 0xF) % 100) / D_global_asm_8075EAC0);
        arg0->unk35C += (s16)((rand() >> 0xF) % 800) - 0x190;
        arg0->unk35C %= 0xFFF;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 += (var_v1[0] * func_global_asm_80612794(arg0->unk35C));
    arg0->unk348 += (var_v1[0] * func_global_asm_80612790(arg0->unk35C));
    arg0->unk344 += var_v1[1];
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071F1D0.s")

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
        var_v1[0] -= (var_v1[1] * D_global_asm_8075EAC8);
    }
}

// rodata, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071F3C0.s")

extern f64 D_global_asm_8075EAD0;

/*
void func_global_asm_8071F3C0(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk364 * D_global_asm_8075EAD0;
    }
    var_v1 = arg0->unk384;
    arg0->unk360 = arg0->unk338->animation_state->scale_y * *var_v1;
    arg0->unk364 = arg0->unk360;
}
*/

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
    arg0->unk344 += (1.0 + func_global_asm_80612794(var_v1->unk4)) * (f32)(1.0 + (var_v1->unk0 * D_global_asm_8075EAD8));
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

// stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_8071F660.s")

/*
void func_global_asm_8071F660(Struct80717D84 *arg0, s32 arg1) {
    f32 sp68[4][4];
    f32 sp28[4][4];
    f32 sp24;

    sp24 = ((f32)arg0->unk358 / (arg0->unk354 - 1));
    arg0->unk364 = \
    arg0->unk360 = func_global_asm_80612794(sp24 * 2048.0f) * 3.0;
    guScaleF(&sp68[0], arg0->unk360, arg0->unk364, 0.0f);
    func_global_asm_80612CA0(&sp28[0], sp24 * 180.0f);
    guMtxCatF(&sp68[0], &sp28[0], &sp68[0]);
    guMtxF2L(&sp68[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
*/

extern f32 D_global_asm_8075EAE0;
extern f64 D_global_asm_8075EAE8;
extern f64 D_global_asm_8075EAF0;
extern f64 D_global_asm_8075EAF8;

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
        var_v1->unk0 = D_global_asm_8075EAE0;
        var_v1->unk4 = arg0->unk360;
        var_v1->unk8 = 0.0f;
    }
    var_v1 = arg0->unk384;
    var_v1->unk0 = ((var_v1->unk4 - var_v1->unk0) * D_global_asm_8075EAE8) + var_v1->unk0;
    var_v1->unk8 = var_v1->unk8 + 5.0f;
    arg0->unk360 = (func_global_asm_80612794(object_timer * 0x32) * D_global_asm_8075EAF0) + var_v1->unk0;
    arg0->unk364 = (func_global_asm_80612790(object_timer * 0x19) * D_global_asm_8075EAF8) + var_v1->unk0;
    guScaleF(&sp6C[0], arg0->unk360, arg0->unk364, 0.0f);
    func_global_asm_80612CA0(&sp2C[0], var_v1->unk8);
    guMtxCatF(&sp6C[0], &sp2C[0], &sp6C[0]);
    guMtxF2L(&sp6C[0], arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}

extern s32 D_global_asm_8071FB08; // TODO: Proper datatype

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
            func_global_asm_8071498C(&func_global_asm_8071C818);
            drawSpriteAtPosition(&D_global_asm_8071FB08, 1.6f, arg0->unk340, arg0->unk344, arg0->unk348);
        }
        temp_v0->unk4 += temp_v0->unk0;
        guScaleF(&sp78[0], arg0->unk360, arg0->unk364, 0.0f);
        guRotateF(&sp38[0], temp_v0->unk4, 0.0f, 0.0f, 1.0f);
        guMtxCatF(&sp78[0], &sp38[0], &sp78[0]);
        guMtxF2L(&sp78[0], arg0->unk128[D_global_asm_807444FC]);
        arg0->unk32C = 2;
    }
}
