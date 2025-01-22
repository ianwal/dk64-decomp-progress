#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern Struct80717D84 *D_minecart_80028C30;

extern SpriteData D_global_asm_8071FB54;
extern SpriteData D_global_asm_8071FEF4;
extern SpriteData D_global_asm_8071FFA0; // TODO: Datatype

extern u8 D_global_asm_8074450C;

extern u8 D_global_asm_80750AB4;
extern s16 D_global_asm_807502D0;

extern f32 D_global_asm_80755674;
extern f32 D_global_asm_80755678;

// .rodata
extern f64 D_global_asm_8075E6D0;
extern f64 D_global_asm_8075E6D8;
extern f64 D_global_asm_8075E6E0;
extern f64 D_global_asm_8075E6E8;
extern f64 D_global_asm_8075E6F0;
extern f64 D_global_asm_8075E6F8;
extern f64 D_global_asm_8075E700;
extern f64 D_global_asm_8075E708;
extern f64 D_global_asm_8075E710;
extern f64 D_global_asm_8075E718;
extern f64 D_global_asm_8075E720;
extern f32 D_global_asm_8075E728;
extern f32 D_global_asm_8075E72C;
extern f32 D_global_asm_8075E730;
extern f64 D_global_asm_8075E738;
extern f64 D_global_asm_8075E740;
extern f64 D_global_asm_8075E748;
extern f64 D_global_asm_8075E750;

extern f64 D_global_asm_8075E770;
extern f64 D_global_asm_8075E778;
extern f64 D_global_asm_8075E780;

extern f32 D_global_asm_8075E840;
extern f32 D_global_asm_8075E844;
extern f64 D_global_asm_8075E848;
extern f64 D_global_asm_8075E850;
extern f64 D_global_asm_8075E858;
extern f64 D_global_asm_8075E860;
extern f64 D_global_asm_8075E868;
extern f64 D_global_asm_8075E870;
extern f64 D_global_asm_8075E878;
extern f64 D_global_asm_8075E880;
extern f64 D_global_asm_8075E888;
extern f64 D_global_asm_8075E890;
extern f64 D_global_asm_8075E898;
extern f32 D_global_asm_8075E8A0;
extern f64 D_global_asm_8075E8A8;
extern f32 D_global_asm_8075E8B0;
extern f32 D_global_asm_8075E8B4;
extern f64 D_global_asm_8075E8B8;
extern f32 D_global_asm_8075E8C0;
extern f64 D_global_asm_8075E8C8;
extern f64 D_global_asm_8075E8D0;
extern f32 D_global_asm_8075E8D8;
extern f32 D_global_asm_8075E8DC;
extern f32 D_global_asm_8075E8E0;
extern f64 D_global_asm_8075E8E8;
extern f64 D_global_asm_8075E8F0;
extern f64 D_global_asm_8075E8F8;
extern f64 D_global_asm_8075E900;
extern f64 D_global_asm_8075E908;
extern f64 D_global_asm_8075E910;
extern f64 D_global_asm_8075E930;
extern f64 D_global_asm_8075E938;
extern f64 D_global_asm_8075E940;
extern f64 D_global_asm_8075E948;
extern f32 D_global_asm_8075E950;
extern f32 D_global_asm_8075E954;
extern f32 D_global_asm_8075E958;
extern f32 D_global_asm_8075E95C;
extern f32 D_global_asm_8075E960;
extern f32 D_global_asm_8075E964;
extern f32 D_global_asm_8075E968;
extern f64 D_global_asm_8075E970;
extern f32 D_global_asm_8075E978;
extern f64 D_global_asm_8075E980;
extern f64 D_global_asm_8075E988;
extern f64 D_global_asm_8075E990;
extern f32 D_global_asm_8075E998;
extern f64 D_global_asm_8075E9A0;
extern f64 D_global_asm_8075E9A8;
extern f64 D_global_asm_8075E9B0;
extern f64 D_global_asm_8075E9B8;
extern f64 D_global_asm_8075E9C8;
extern f64 D_global_asm_8075E9D0;
extern f32 D_global_asm_8075E9E8;
extern f64 D_global_asm_8075E9F0;
extern f64 D_global_asm_8075E9F8;
extern f64 D_global_asm_8075EA00;
extern f64 D_global_asm_8075EA08;
extern f32 D_global_asm_8075EA10;
extern f64 D_global_asm_8075EA18;
extern f32 D_global_asm_8075EA20;
extern f32 D_global_asm_8075EA24;
extern f32 D_global_asm_8075EA28;
extern f32 D_global_asm_8075EA2C;
extern f64 D_global_asm_8075EA30;
extern f32 D_global_asm_8075EA38;
extern f64 D_global_asm_8075EA40;
extern f64 D_global_asm_8075EA48;
extern f32 D_global_asm_8075EA50;
extern f64 D_global_asm_8075EA58;
extern f64 D_global_asm_8075EA60;
extern f32 D_global_asm_8075EA68;
extern f32 D_global_asm_8075EA6C;
extern f64 D_global_asm_8075EA70;
extern f64 D_global_asm_8075EA78;
extern f32 D_global_asm_8075EA80;
extern f64 D_global_asm_8075EA88;
extern f32 D_global_asm_8075EA90;
extern f64 D_global_asm_8075EA98;
extern f64 D_global_asm_8075EAA0;
extern f32 D_global_asm_8075EAA8;
extern f64 D_global_asm_8075EAB0;
extern f64 D_global_asm_8075EAB8;
extern f64 D_global_asm_8075EAC0;
extern f64 D_global_asm_8075EAC8;
extern f64 D_global_asm_8075EAD0;
extern f64 D_global_asm_8075EAD8;
extern f32 D_global_asm_8075EAE0;
extern f64 D_global_asm_8075EAE8;
extern f64 D_global_asm_8075EAF0;
extern f64 D_global_asm_8075EAF8;

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
    f32 x, y, z;

    func_global_asm_806335B0(arg2, 1, boneIndex, &x, &y, &z);
    return func_global_asm_80714D08(sprite, scale, x, y, z, NULL, arg2, boneIndex, arg4);
}

Struct80717D84 *func_global_asm_80714C08(void *sprite, f32 scale, Actor *actor, s32 boneIndex, u8 arg4) {
    f32 x, y, z;

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
    u8 sp3F;
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

// Displaylist stuff, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_global_asm_80715E94.s")

void func_global_asm_80716F10(Struct80717D84 *arg0, s32 arg1) {
    f32 sp68[4][4];
    f32 sp28[4][4];
    guScaleF(sp68, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp28, arg0->unk35C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp68, sp28, sp68);
    guMtxF2L(sp68, &arg0->unk128[D_global_asm_807444FC]);
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
    guScaleF(sp70, arg0->unk360, arg0->unk364, 0.0f);
    guRotateF(sp30, arg0->unk384->unk0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp70, sp30, sp70);
    guMtxF2L(sp70, &arg0->unk128[D_global_asm_807444FC]);
    arg0->unk32C = 2;
}
