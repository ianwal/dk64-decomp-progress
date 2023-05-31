#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct80717D84_unk384_80717814;

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
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} Struct80717D84_unk384_80717100;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct80717D84_unk384_8071720C;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct80717D84_unk384_80717B64;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct80717D84_unk384_8071DC90;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct80717D84_unk384_8071E110;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_8071F444;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} Struct80717D84_unk384_80717930;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct80717D84_unk384_807189BC;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct80717D84_unk384_80719C00;

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_80719EF4;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80717D84_unk384_8071D0F0;

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80717D84_unk384_8071B2EC;

typedef struct {
    u8 unk0[0x16 - 0x0];
    s16 unk16;
} Struct80717D84_unk330;

typedef struct {
    u8 unk0[0x128 - 0x0];
    float unk128[4][4]; // TODO: How many?
    u8 unk168[0x32C - 0x168];
    u8 unk32C;
    u8 unk32D[0x330 - 0x32D];
    Struct80717D84_unk330 *unk330;
    s32 unk334;
    Actor *unk338;
    s32 unk33C;
    f32 unk340;
    f32 unk344;
    f32 unk348;
    s16 unk34C;
    s16 unk34E;
    u8 unk350;
    u8 unk351;
    u8 unk352;
    u8 unk353;
    s32 unk354;
    s32 unk358;
    union {
        s32 unk35C;
        u32 unk35C_u32;
        Actor *unk35C_actor;
    };
    f32 unk360;
    f32 unk364;
    u8 unk368[0x36D - 0x368];
    u8 unk36D;
    u8 unk36E[0x384 - 0x36E];
    union {
        Struct80717D84_unk384 *unk384;
        Struct80717D84_unk384_f32 *unk384_f32;
        Struct80717D84_unk384_s16 *unk384_s16;
        Struct80717D84_unk384_80717100 *unk384_80717100;
        Struct80717D84_unk384_80717814 *unk384_80717814;
    };
    s32 unk388;
    u16 unk38C;
} Struct80717D84;

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

extern u8 D_8074450C;

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

extern f64 D_8075E708;
extern f64 D_8075E710;
extern s32 D_80717404; // TODO: Datatype
extern s32 D_8074E880[]; // TODO: Datatype
extern s32 D_80718380; // Function pointer?
extern s32 D_8071FEF4;

extern s16 D_807502D0;

extern f64 D_8075EAD8;

extern f32 D_8075E728;
extern f32 D_8075E72C;
extern f32 D_8075E730;
extern f64 D_8075E738;
extern f64 D_8075E740;
extern f64 D_8075E888;
extern f64 D_8075E890;
extern f64 D_8075E898;
extern f32 D_8075E8A0;
extern f64 D_8075E8A8;
extern f64 D_8075EA70;
extern f64 D_8075EA78;
extern f32 D_8075EA80;
extern f64 D_8075EA88;
extern f32 D_8075EA90;
extern f64 D_8075EA98;
extern f64 D_8075EAA0;
extern f64 D_8075EAB8;
extern f64 D_8075EAC0;
extern f64 D_8075EAC8;

extern f64 D_8075E6D0;
extern f64 D_8075E6D8;

extern f32 D_8075E950;
extern f32 D_8075E954;
extern f32 D_8075E958;
extern f32 D_8075E95C;
extern f32 D_8075E960;
extern f32 D_8075E964;
extern f32 D_8075E978;
extern f64 D_8075E980;
extern f64 D_8075E990;
extern s32 D_80717D4C; // TODO: Datatype
extern s32 D_8071FFA0; // TODO: Datatype
extern f32 D_8075E998;
extern f32 D_8075EA28;
extern f32 D_8075EA2C;
extern f64 D_8075EA30;
extern f32 D_8075EA38;
extern f64 D_8075EA40;
extern f64 D_8075EA48;
extern f32 D_8075EA50;

extern f64 D_8075E718;
extern f64 D_8075E720;

extern f64 D_8075E770;
extern f64 D_8075E778;
extern f64 D_8075E780;

extern f32 D_8075E8B0;
extern f32 D_8075E8B4;
extern f64 D_8075E8B8;

extern f32 D_8075E8C0;
extern f64 D_8075E8C8;
extern f64 D_8075E8D0;
extern f32 D_8075E8D8;
extern f32 D_8075E8DC;
extern f32 D_8075E8E0;

extern Struct80717D84 *D_80028C30;
extern f64 D_8075E8F8;

void *func_80714D08(void*, f32, f32, f32, f32, s32, s32, s32, s32);
s32 func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, u32, u32, u32);
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

// Doable, needs a struct array size 0x10 at Struct807FDB04->unk28
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

/*
? func_8061134C(void *);                            // extern
? func_8062D26C(void *, void *, ?);                 // extern
? func_80630588(?, void *, ?, ? *);                 // extern
extern s32 D_80000310;
extern void *D_807FDB04;
extern void *D_807FDB08;
OSTime func_806119A0(void);

void func_80715908(void *arg0) {
    ? sp3F;
    s32 temp_v0;
    s32 var_s1;
    void *temp_a0;
    void *temp_s0;
    void *temp_s1;
    void *var_s0;

    if (arg0->unk36F == 0) {
        if (arg0->unk38C & 4) {
            func_80630588(0, arg0, 4, &sp3F);
        } else {
            func_8062D26C(arg0, arg0, 4);
        }
    } else {
        func_80630588(0, arg0, 3, &sp3F);
    }
    temp_a0 = arg0->unk384;
    if (temp_a0 != NULL) {
        func_8061134C(temp_a0);
    }
    var_s1 = 0;
    var_s0 = arg0;
    if (arg0->unk20 > 0) {
        do {
            func_8061134C(var_s0->unk0);
            func_8061134C(var_s0->unk4);
            var_s1 += 1;
            var_s0 += 8;
        } while (var_s1 < arg0->unk20);
    }
    if (D_80000310 != 0x17D9) {
        temp_v0 = ;
        osSetTime(func_806119A0());
    }
    temp_s0 = arg0->unk398;
    temp_s1 = arg0->unk39C;
    func_8061134C(arg0);
    if (temp_s0 != NULL) {
        temp_s0->unk39C = temp_s1;
    } else {
        D_807FDB04 = temp_s1;
    }
    if (temp_s1 != NULL) {
        temp_s1->unk398 = temp_s0;
        return;
    }
    D_807FDB08 = temp_s0;
}
*/

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

/*
// TODO: Regalloc
void func_80717100(Struct80717D84 *arg0, s32 arg1) {
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
    arg0->unk340 = var_v1->unk6 + (var_v1->unk2 * func_80612794(var_v1->unk0));
    arg0->unk348 = var_v1->unk8 + (var_v1->unk2 * func_80612790(var_v1->unk0));
}
*/

void func_8071720C(Struct80717D84 *arg0, s32 arg1) {
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
    arg0->unk340 += (D_8075E6D0 * var_v1->unk4 * func_80612794(var_v1->unk0));
    arg0->unk348 += (D_8075E6D8 * var_v1->unk4 * func_80612790(var_v1->unk0));
    var_v1->unk0 += 0x50;
    var_v1->unk4 += var_v1->unk2;
    if (arg0->unk35C != 0) {
        func_806595F0(1);
        func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 40.0f, 0, 0xFF, 0xFF, (rand() >> 0xF) % 255);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80717404.s")

extern f64 D_8075E6E0;
extern f64 D_8075E6E8;
extern f64 D_8075E6F0;
extern f64 D_8075E6F8;
extern f64 D_8075E700;

/*
void func_80717404(Struct80717D84 *arg0, s32 arg1) {
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
        arg0->unk340 = arg0->unk340 + (4.0 * (D_8075E6E0 * temp_s2_2->unk2 * func_80612794(var_v1->unk0)));
        arg0->unk344 = arg0->unk344 + (4.0 * (D_8075E6E8 * temp_s2_2->unk2 * func_80612790(var_v1->unk0)));
    } else {
        arg0->unk340 = arg0->unk340 + (D_8075E6F0 * temp_s2_2->unk2 * func_80612794(var_v1->unk0));
        arg0->unk348 = arg0->unk348 + (D_8075E6F8 * temp_s2_2->unk2 * func_80612790(var_v1->unk0));
        if (temp_s2_2->unk0 == 0) {
            arg0->unk344 = arg0->unk344 + var_v1->unk8;
            var_v1->unk8 = var_v1->unk8 - 0.5;
        } else {
            arg0->unk344 = arg0->unk344 + (var_v1->unk8 * D_8075E700);
        }
    }
    temp_s2_2->unk2 = temp_s2_2->unk2 + var_v1->unk4;
}
*/

void func_80717760(Struct80717D84 *arg0, s8 *arg1) {
    s32 temp_v0;

    arg0->unk36D = 0;
    if (arg0->unk35C != 0) {
        arg0->unk35C--;
        func_807149B8(1);
        func_8071498C(&D_80717404);
        func_80714950(0xA);
        func_80714CC0(D_8074E880[((rand() >> 0xF) % 1000) % 3], 0.8f, arg0->unk340, arg0->unk344, arg0->unk348);
        return;
    }
    *arg1 = 1;
}

void func_80717814(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_80717814 *temp_v0;
    Struct80717D84_unk384_80717814 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80717814));
        var_v1 = arg0->unk384_80717814;
        var_v1->unk0 = (rand() >> 0xF) % 4095;
        var_v1->unk2 = ((rand() >> 0xF) % 10) + 2;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 += (D_8075E708 * arg0->unk35C * func_80612794(var_v1->unk0));
    arg0->unk344 += (D_8075E710 * arg0->unk35C * func_80612790(var_v1->unk0));
    var_v1->unk0 += 0x46;
    arg0->unk35C += var_v1->unk2;
}

void func_80717930(Struct80717D84 *arg0, s32 arg1) {
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
            temp_f0 = arg0->unk338->animation_state->scale_y / D_8075E718;
            temp_s1->unk8 = temp_s1->unk8 * temp_f0;
            arg0->unk35C = arg0->unk35C * temp_f0;
        }
    }
    temp_s1 = arg0->unk384;
    if (arg0->unk38C & 2) {
        arg0->unk340 = player_pointer->x_position + (func_80612794(temp_s1->unk0) * arg0->unk35C);
        arg0->unk348 = player_pointer->z_position + (func_80612790(temp_s1->unk0) * arg0->unk35C);
    } else {
        arg0->unk340 = temp_s1->unk2 + (func_80612794(temp_s1->unk0) * arg0->unk35C);
        arg0->unk348 = temp_s1->unk4 + (func_80612790(temp_s1->unk0) * arg0->unk35C);
    }
    arg0->unk344 += (temp_s1->unk8 * D_8075E720);
    temp_s1->unk0 += temp_s1->unk6;
}

void func_80717B64(Struct80717D84 *arg0, s8 *arg1) {
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

void func_80717F1C(Struct80717D84 *arg0, s32 arg1) {
    Struct80717D84_unk384_f32 *var_v0;
    Actor *temp_s0;
    f64 temp;

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
    temp = D_8075E738;
    arg0->unk344 -= (arg0->unk35C / 100.0);
    arg0->unk340 += var_v0->unk0;
    arg0->unk348 += var_v0->unk4;
    var_v0->unk0 = var_v0->unk0 * temp;
    var_v0->unk4 = var_v0->unk4 * temp;
}

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

void func_807189BC(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_807189BC *var_v1;
    Actor *sp20;

    sp20 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = MAX(2.0, sp20->unkB8 * D_8075E770);
        var_v1->unk2 = sp20->y_rotation;
        var_v1->unk4 = ((rand() >> 0xF) % 1000) + 0xC8;
        arg0->unk360 += (((rand() >> 0xF) % 100) / D_8075E778);
        arg0->unk364 = arg0->unk360;
        var_v1->unk6 = sp20->unkAC;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 -= (var_v1->unk0 * func_80612794(var_v1->unk2));
    arg0->unk348 -= (var_v1->unk0 * func_80612790(var_v1->unk2));
    arg0->unk344 += (var_v1->unk4 / D_8075E780);
    if (var_v1->unk6 <= arg0->unk344) {
        *arg1 = 1;
        func_80718124(arg0->unk360 * 1.5, arg0->unk340, var_v1->unk6, arg0->unk348);
    }
    if (arg0->unk36D >= 0xC) {
        arg0->unk36D -= 0xA;
        return;
    }
    *arg1 = 1;
    arg0->unk36D = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_80718BF4.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071910C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807195D4.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_807197B4.s")

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

void func_80719C00(Struct80717D84 *arg0, s8 *arg1) {
    Struct80717D84_unk384_80719C00 *var_v1;
    f32 var_f2;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80719C00));
        var_v1 = arg0->unk384;
        var_v1->unk0 = arg0->unk340;
        var_v1->unk4 = arg0->unk348;
        var_v1->unk8 = 0.0f;
        var_v1->unkC = arg0->unk35C * D_8075E8B0;
        var_v1->unk10 = ((arg0->unk35C % 3) * 0x64) - 0x64;
        var_v1->unk14 = D_8075E8B4;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += D_8075E8B8;
    if (var_v1->unk14 < 15.0f) {
        var_f2 = var_v1->unk14;
    } else {
        var_f2 = 15.0f;
    }
    var_v1->unk14 -= var_f2;
    arg0->unk36D = MIN(255.0f, var_v1->unk14);
    var_v1->unk8 += 1.5;
    var_v1->unkC += var_v1->unk10;
    arg0->unk340 = (func_80612794(var_v1->unkC) * var_v1->unk8) + var_v1->unk0;
    arg0->unk348 = (func_80612790(var_v1->unkC) * var_v1->unk8) + var_v1->unk4;
    if (arg0->unk36D == 0) {
        *arg1 = 1;
    }
}

void func_80719EF4(Struct80717D84 *arg0, s32 arg1) {
    f32 sp1C;
    f32 temp_f2;
    f32 temp;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_80719EF4));
        arg0->unk384->unk0 = D_8075E8C0;
        arg0->unk384->unk4 = arg0->unk35C;
    }
    arg0->unk384->unk0 -= D_8075E8C8;
    if (arg0->unk384->unk0 < D_8075E8D0) {
        arg0->unk384->unk0 = D_8075E8D8;
    }
    temp = func_80612D1C(D_8075E8DC * arg0->unk384->unk4);
    sp1C = (temp * arg0->unk384->unk0);
    temp = func_80612D10(D_8075E8E0 * arg0->unk384->unk4);
    temp_f2 = (temp * arg0->unk384->unk0);
    arg0->unk340 += sp1C;
    arg0->unk348 += temp_f2;
    arg0->unk344 += 1.0f;
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A038.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A1E4.s")

void func_8071A440(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (D_8075E8F8 < var_f0) {
        var_f0 = 1.0f;
    }
    if (extra_player_info_pointer->vehicle_actor_pointer == arg0->unk35C_actor) {
        if (arg0 == D_80028C30) {
            func_806595F0(1);
            func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f0 * 50.0, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071A674.s")

extern Struct80717D84 *D_8002FBB0;
extern f64 D_8075E900;

/*
// TODO: Close...
void func_8071A674(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    Struct80717D84 **var_v0;

    var_v0 = &D_8002FBB0;
    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (D_8075E900 < var_f0) {
        var_f0 = 1.0f;
    }
    while (*var_v0 != D_8002FBB0) {
        var_v0++;
        if (*var_v0 == arg0) {
            func_806595F0(1);
            func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f0 * 50.0, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
            return;
        }
    }
}
*/

extern f64 D_8075E908;
extern f64 D_8075E910;

void func_8071A8B0(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f16;
    s16 temp_v0;

    temp_v0 = arg0->unk330->unk16;
    var_f0 = (f32)(temp_v0 - arg0->unk34E) / temp_v0;
    if (D_8075E908 < var_f0) {
        var_f0 = 1.0f;
    }
    // TODO: What's going on here...?
    if (((u32)arg0->unk35C >> 0x10) != 0) {
        var_f16 = (arg0->unk35C & 0xFFFF) * var_f0;
    } else {
        var_f16 = arg0->unk35C & 0xFFFF;
    }
    func_806595F0(1);
    func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f16, 0, 0xFF, (-80.0f * var_f0) + 255.0f, (-205.0f * var_f0) + 255.0f);
}

void func_8071AADC(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f2;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (D_8075E910 < var_f0) {
        var_f0 = 1.0f;
    }
    if (((u32)arg0->unk35C >> 0x10) != 0) {
        var_f2 = (arg0->unk35C & 0xFFFF) * var_f0;
    } else {
        var_f2 = arg0->unk35C & 0xFFFF;
    }
    func_806595F0(1);
    func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_f2, 0, 0xFF, 0xFF, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071ABDC.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071AF30.s")

void func_8071B1AC(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk344 -= (D_8075E950 * 0.5);
    arg0->unk340 += (D_8075E954 * func_80612794(arg0->unk35C));
    arg0->unk348 += (D_8075E958 * func_80612790(arg0->unk35C));
}

void func_8071B24C(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk344 += (D_8075E95C * 0.5);
    arg0->unk340 += (D_8075E960 * func_80612794(arg0->unk35C));
    arg0->unk348 += (D_8075E964 * func_80612790(arg0->unk35C));
}

extern f32 D_8075E968;
extern f64 D_8075E970;

void func_8071B2EC(Struct80717D84 *arg0, s32 arg1) {
    f32 sp24;
    Struct80717D84_unk384_8071B2EC *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(8);
        var_v1 = arg0->unk384;
        var_v1->unk0 = arg0->unk338->unkEE;
        arg0->unk384->unk4 = arg0->unk338->unkB8 + 30.0f;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += (D_8075E968 * 0.5);
    sp24 = var_v1->unk4 * D_8075E970;
    arg0->unk340 += (sp24 * func_80612794(var_v1->unk0));
    arg0->unk348 += (sp24 * func_80612790(arg0->unk384->unk0));
    arg0->unk384->unk4 -= 15.0f;
    if (arg0->unk384->unk4 < 0.0f) {
        arg0->unk384->unk4 = 0.0f;
    }
}

void func_8071B44C(Struct80717D84 *arg0, s32 arg1) {
    f32 temp_f6;
    f32 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk338->unkB8;
    }
    var_v1 = arg0->unk384;
    arg0->unk344 += (D_8075E978 * 0.5);
    temp_f6 = *var_v1 * D_8075E980;
    arg0->unk340 += (temp_f6 * func_80612794(arg0->unk35C));
    arg0->unk348 += (temp_f6 * func_80612790(arg0->unk35C));
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071B520.s")

void func_8071B758(Struct80717D84 *arg0, s32 arg1) {
    f32 var_f0;
    u8 temp_t0;

    var_f0 = (f32)(arg0->unk330->unk16 - arg0->unk34E) / arg0->unk330->unk16;
    if (D_8075E990 < var_f0) {
        var_f0 = 1.0f;
    }
    temp_t0 = ((-155.0f * var_f0) + 255.0f);
    func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, 50.0f, 0, temp_t0, temp_t0, temp_t0);
}

void func_8071B89C(Struct80717D84 *arg0, s32 arg1) {
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

void func_8071B8EC(Struct80717D84 *arg0, s8 *arg1) {
    if (arg0->unk358 == 0) {
        if (arg0->unk36D < 0xE1) {
            arg0->unk36D += 0x1E;
        } else {
            arg0->unk36D = 0xFF;
        }
    }
    if ((arg0->unk34E == 3) || (arg0->unk34E == 0x11) || (arg0->unk34E == 0x15)) {
        func_806086CC(arg0->unk340, arg0->unk344, arg0->unk348, 0x14F, 0xFF, 0x7F, 0x1E, 0x4B, D_8075E998, 0);
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
        func_80714998(3);
        func_8071498C(&D_80717D4C);
        func_80714950(-0xA);
        func_807149B8(1);
        func_807149C8(0x9B, 0x9B, 0x9B, 0x96);
        func_80714CC0(&D_8071FFA0, 0.8f, (((rand() >> 0xF) % 65535) & 7) + arg0->unk340, arg0->unk344 + 10.0f, (((rand() >> 0xF) % 65535) & 7) + arg0->unk348);
    }
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BB14.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BC80.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071BE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C004.s")

extern s32 D_807201D4; // TODO: Datatype
void func_8071C24C(void); // TODO: Signature

/*
// TODO: Close
void func_8071C004(Struct80717D84 *arg0, s8 *arg1) {
    f32 temp_f0;
    s16 sp44[3];
    f32 temp;

    if (current_map == MAP_HELM_LOBBY) {
        sp44[0] = 0xFF;
        sp44[1] = 0x46;
        sp44[2] = 0;
    } else {
        sp44[2] = 0xFF;
        sp44[1] = 0xFF;
        sp44[0] = 0xFF;
    }
    switch (arg0->unk35C) {
        case 0:
            if ((arg0->unk34E == 0xA) && (arg0->unk351 == 0)) {
                func_806086CC(arg0->unk340, arg0->unk344, arg0->unk348, 0xE4, 0xFF, 0x7F, 0x1E, 0x46, 9.0f, 0);
                func_807149FC(-1);
                func_807149B8(1);
                func_8071498C(&func_8071C24C);
                func_80714CC0(&D_807201D4, 0.8f, arg0->unk340, arg0->unk344, arg0->unk348);
                return;
            }
            temp_f0 = (arg0->unk330->unk16 * 2);
            temp = 200.0f * (1.0 - ((temp_f0 - ((arg0->unk34E * 2) + arg0->unk351)) / temp_f0));
            func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, temp, 0, 0xFF, sp44[1], sp44[2]);
            return;
        case 1:
            temp_f0 = (arg0->unk330->unk16 * 2);
            temp = 200.0f * ((temp_f0 - ((arg0->unk34E * 2) + arg0->unk351)) / temp_f0);
            func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, temp, 0, 0xFF, sp44[1], sp44[2]);
            return;
    }
}
*/

// Similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C48C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C818.s")

extern u8 D_807444FC;
extern f64 D_8075E9C8;

/*
// TODO: Close
void func_8071C818(Struct80717D84 *arg0, s8 *arg1) {
    f64 temp = D_8075E9C8;
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
    guMtxF2L(&sp70, &arg0->unk128[D_807444FC]);
    arg0->unk32C = 2;
}
*/

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C914.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071C9E8.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071CDE0.s")

extern u16 D_807FC930[];

void func_8071D0F0(Struct80717D84 *arg0, s8 *arg1) {
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
    func_80671C0C(sp2C, 1, &var_t0->unk4, &var_t0->unk8, &var_t0->unkC);
    temp_f0 = var_t0->unk0 / 30.0;
    arg0->unk340 = ((player_pointer->x_position - var_t0->unk4) * temp_f0) + var_t0->unk4;
    arg0->unk344 = ((player_pointer->y_position - var_t0->unk8) * temp_f0) + var_t0->unk8;
    arg0->unk348 = ((player_pointer->z_position - var_t0->unkC) * temp_f0) + var_t0->unkC;
    var_t0->unk0 -= 1.0f;
    if (var_t0->unk0 == 0.0f) {
        extra_player_info_pointer->unk1F0 |= 0x20000;
        temp_v1 = &D_807FC930[getLevelIndex(D_8076A0AB, 0)];
        *temp_v1 += 1;
        *arg1 = 1;
    }
}

void func_8071D260(Struct80717D84 *arg0, s8 *arg1) {
    arg0->unk36D -= arg0->unk35C;
    if (arg0->unk35C >= arg0->unk36D) {
        *arg1 = 1;
    }
}

// Doable, fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D28C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D5BC.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071D94C.s")

extern f32 D_8075EA10;
extern f64 D_8075EA18;
extern f32 D_8075EA20;
extern f32 D_8075EA24;

void func_8071D94C(Actor *arg0, Struct80717D84 *arg1, s8 *arg2);

/*
// TODO: Close
void func_8071D94C(Actor *arg0, Struct80717D84 *arg1, s8 *arg2) {
    s16 temp;
    s16 sp34;
    f32 sp30;
    f32 var_f2;
    f32 sp28;
    Struct80717D84_unk384_f32 *sp24;
    f64 temp2;

    arg1->unk384 = malloc(0x10);
    sp24 = arg1->unk384;
    arg1->unk340 += (2.0f * (func_806119FC() - 0.5f));
    arg1->unk344 += (2.0f * (func_806119FC() - 0.5f));
    arg1->unk348 += (2.0f * (func_806119FC() - 0.5f));
    if (arg0 != NULL) {
        sp34 = (arg0->y_rotation + (func_806119A0() & 0x1FF) + 0x700) & 0xFFF;
        var_f2 = arg0->unkB8 * D_8075EA10;
        if (!(var_f2 < 1.0f)) {
            var_f2 = 1.0f;
        }
        if (var_f2 < D_8075EA18) {
            *arg2 = 1;
        }
        sp28 = var_f2 * 1.5f * D_8075EA20;
        arg1->unk338 = arg0;
    } else {
        var_f2 = D_8075EA24;
        sp34 = func_806119A0() % 4095U;
        sp28 = (func_806119FC() + 1.0f) * 3.0f;
    }
    arg1->unk360 *= (func_806119FC() + 1.0f) * 0.5;
    arg1->unk36D = 0x82;
    arg1->unk364 = arg1->unk360;
    sp30 = func_806119FC() * var_f2;
    sp24->unk0 = func_80612794(sp34) * sp30;
    sp24->unk4 = func_80612790(sp34) * sp30;
    sp24->unk8 = sp28;
    func_8066715C(&sp24->unkC);
}
*/

void func_8071DB74(Struct80717D84 *arg0, u8 *arg1) {
    Struct80717D84_unk384_f32 *var_v1;

    if (arg0->unk384_f32 == NULL) {
        func_8071D94C(NULL, arg0, arg1);
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
            func_80718124(arg0->unk360 * 5.0f, arg0->unk340, arg0->unk344, arg0->unk348);
        }
    }
}

void func_8071DC90(Struct80717D84 *arg0, s8 *arg1) {
    PlayerAdditionalActorData *PaaD;
    Actor *sp28;
    Struct80717D84_unk384_8071DC90 *var_v0;
    f32 sp20;
    f64 var_f2_2;
    f64 var_f2;

    sp20 = D_8075EA28;
    sp28 = arg0->unk35C_actor;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(sizeof(Struct80717D84_unk384_8071DC90));
        var_v0 = arg0->unk384;
        var_v0->unk0 = 0.0f;
        var_v0->unk4 = func_806119FC() * D_8075EA2C;
        if (func_806119FC() > 0.5) {
            var_f2 = func_806119FC();
        } else {
            var_f2 = 0.5;
        }
        var_v0->unk8 = var_f2 * D_8075EA30;
        if (func_806119FC() > 0.5) {
            var_v0->unk8 = -var_v0->unk8;
        }
        var_v0->unkC = func_806119FC() * D_8075EA38;
        if (func_806119FC() > 0.5) {
            var_f2_2 = func_806119FC();
        } else {
            var_f2_2 = 0.5;
        }
        var_v0->unk10 = var_f2_2 * D_8075EA40;
        if (func_806119FC() > 0.5) {
            var_v0->unk10 = -var_v0->unk10;
        }
        if (D_8075EA48 < func_806119FC()) {
            var_v0->unk14 = (f64)func_806119FC();
        } else {
            var_v0->unk14 = D_8075EA48;
        }
        sp20 = 1.0f;
    }
    var_v0 = arg0->unk384;
    if (var_v0->unk0 < 1.0f) {
        var_v0->unk0 += D_8075EA50;
    }
    var_v0->unk4 = (var_v0->unk4 + var_v0->unk8);
    var_v0->unk4 = (s16)var_v0->unk4 & 0xFFF;
    var_v0->unkC = (var_v0->unkC + var_v0->unk10);
    var_v0->unkC = (s16)var_v0->unkC & 0xFFF;
    arg0->unk340 = ((((func_80612794(var_v0->unk4) * (15.0f * var_v0->unk0)) + sp28->x_position) - arg0->unk340) * sp20) + arg0->unk340;
    arg0->unk348 = ((((func_80612790(var_v0->unk4) * (15.0f * var_v0->unk0)) + sp28->z_position) - arg0->unk348) * sp20) + arg0->unk348;
    arg0->unk344 = ((((((func_80612794(var_v0->unkC) * (var_v0->unk14 * var_v0->unk0)) + 1.0f) * 15.0f) + sp28->y_position) - arg0->unk344) * sp20) + arg0->unk344;
    PaaD = sp28->PaaD; 
    if (!(PaaD->unk1F0 & 0x10)) {
        *arg1 = 1;
    }
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E028.s")

void func_8071E110(Struct80717D84 *arg0, u8 arg1, u16 arg2, f32 arg3, f32 arg4, s32 arg5) {
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

void func_8071E1C8(Struct80717D84 *arg0, s8 *arg1) {
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
    if (func_8067AF44(temp_s2) == 0) {
        *arg1 = 1;
        return;
    }
    temp = (temp_v0->unk10 * ((1 - (temp_v0->unk0 * 2)) * 2048));
    temp = (s16)temp & 0xFFF;
    sp2C = func_80612794(temp) * temp_v0->unk8;
    temp_v0->unk14 += (2.0 * ((1 - (temp_v0->unk0 * 2)) * 4096) * temp_v0->unkC);
    temp_v0->unk14 = (s16)temp_v0->unk14 & 0xFFF;
    sp3C = func_80612794(temp_v0->unk14) * sp2C;
    temp_f0 = func_80612790(temp_v0->unk14) * sp2C;
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071E3EC.s")

extern f64 D_8075EA58;
extern f64 D_8075EA60;
extern f32 D_8075EA68;
extern f32 D_8075EA6C;

s32 func_806531B8(f32, f32, f32, s32);

/*
// TODO: Float regalloc
void func_8071E3EC(Struct80717D84 *arg0, s8 *arg1) {
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
        var_v1[0] = 0.0f;
        var_v1[1] = 0.0f;
        var_v1[2] = func_806531B8(arg0->unk340, arg0->unk344, arg0->unk348, 0);
    }
    var_v1 = arg0->unk384;
    if (var_v1[1] == 0.0) {
        temp = D_8075EA58;
        var_v1[0] = var_v1[0] + 30.0;
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
    if (var_v1[0] < D_8075EA60) {
        sp4C = var_v1[0] / D_8075EA60;
    } else {
        sp4C = 1.0f;
    }
    func_80659610(1000);
    func_80659600(var_v1[2]);
    switch (arg0->unk35C) {
        case 0:
            sp48 = 1.0f;
            sp44 = 1.0f;
            sp40 = 1.0f;
            func_806595F0(2);
            func_80659610(1000);
            break;
        case 1:
            sp48 = 1.0f;
            sp44 = 0.5f;
            sp40 = D_8075EA68;
            func_806595F0(3);
            func_80659610(1000);
            break;
        case 2:
            sp48 = 1.0f;
            sp44 = 0.5f;
            sp40 = D_8075EA6C;
            func_806595F0(2);
            func_80659610(2000);
            break;
        case 3:
            sp48 = 1.0f;
            sp44 = 1.0f;
            sp40 = 1.0f;
            func_806595F0(2);
            func_80659610(0x7D0);
            break;
    }
    temp_f0 = 255.0f * sp4C;
    func_8065A708(arg0->unk340, arg0->unk344, arg0->unk348, 0.0f, 0.0f, 0.0f, var_v1[0], 0, temp_f0 * sp48, temp_f0 * sp44, temp_f0 * sp40);
}
*/

void func_8071E864(Struct80717D84 *arg0, s8 *arg1) {
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
    var_v1[0] -= D_8075EA70;
    if (var_v1[0] < D_8075EA78) {
        var_v1[0] = D_8075EA80;
    }
    sp24 = func_80612794(var_v1[1]) * var_v1[0];
    temp_f12 = func_80612790(var_v1[1]) * var_v1[0];
    temp = D_8075EA88;
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

void func_8071EA24(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v0;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        var_v0 = arg0->unk384;
        var_v0[0] = func_806119FC() * D_8075EA90;
        var_v0[1] = ((func_806119FC() * 0.5) + 1.0) * 5.0;
        var_v0[2] = 15.0f;
    }
    var_v0 = arg0->unk384;
    var_v0[1] -= 1.0f;
    var_v0[2] *= D_8075EA98;
    arg0->unk340 += (var_v0[2] * func_80612794(var_v0[0]));
    arg0->unk348 += (var_v0[2] * func_80612790(var_v0[0]));
    arg0->unk344 += var_v0[1];
}

void func_8071EB70(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f14;
    f32 temp_f0;
    f32 temp_f2;
    s32 var_f12; // Amazingly this is correct

    temp_f16 = (arg0->unk35C * 3) / 4;
    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk36D;
    }
    var_v1 = arg0->unk384;
    temp_f0 = character_change_array->unk224 - arg0->unk348;
    temp_f2 = character_change_array->unk21C - arg0->unk340;
    temp_f14 = character_change_array->unk220 - arg0->unk344;
    temp_f0_2 = sqrtf((temp_f0 * temp_f0) + ((temp_f2 * temp_f2) + (temp_f14 * temp_f14)));
    if (temp_f0_2 < temp_f16) {
        arg0->unk36D = *var_v1;
        return;
    }
    var_f12 = (*var_v1 * ((temp_f0_2 - temp_f16) / (arg0->unk35C - temp_f16)));
    if (*var_v1 < var_f12) {
        var_f12 = *var_v1;
    }
    arg0->unk36D = *var_v1 - var_f12;
}

void func_8071EDEC(Struct80717D84 *arg0, s32 arg1) {
    f64 temp;
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    func_80671C0C(arg0->unk35C, 1, &sp34, &sp30, &sp2C);
    temp = D_8075EAA0;
    arg0->unk340 += (sp34 - arg0->unk340) * temp;
    arg0->unk344 += (sp30 - arg0->unk344) * temp;
    arg0->unk348 += (sp2C - arg0->unk348) * temp;
}

void func_8071EEA4(Struct80717D84 *arg0, s32 arg1) {
    arg0->unk364 = (arg0->unk35C / 100.0) + 1.0;
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071EEE0.s")

void func_8071EFDC(Struct80717D84 *arg0, s8 *arg1) {
    f64 temp = D_8075EAB8;
    arg0->unk36D -= 5;
    arg0->unk360 *= temp;
    arg0->unk364 *= temp;
    if (arg0->unk36D < 6) {
        *arg1 = 1;
    }
}

void func_8071F034(Struct80717D84 *arg0, s32 arg1) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F1D0.s")

extern s8 D_8075567C;

/*
// TODO: Close
void func_8071F1D0(Struct80717D84 *arg0, s8 *arg1) {
    f32 *var_v1;
    s32 temp2;
    s32 temp3;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(0xC);
        temp3 = D_8075567C;
        var_v1 = arg0->unk384;
        var_v1[0] = arg0->unk340;
        var_v1[1] = arg0->unk348;
        var_v1[2] = temp3;
        D_8075567C = -temp3;
    }
    var_v1 = arg0->unk384;
    arg0->unk340 = (func_80612794(arg0->unk35C) * 14.0f) + *var_v1;
    arg0->unk348 = (func_80612790(arg0->unk35C) * 14.0f) + var_v1[1];
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

void func_8071F2F8(Struct80717D84 *arg0, s32 arg1) {
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
        var_v1[0] -= (var_v1[1] * D_8075EAC8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F3C0.s")

extern f64 D_8075EAD0;

/*
// TODO: Minor float regalloc
void func_8071F3C0(Struct80717D84 *arg0, s32 arg1) {
    f32 *var_v1;

    if (arg0->unk384 == NULL) {
        arg0->unk384 = malloc(4);
        var_v1 = arg0->unk384;
        *var_v1 = arg0->unk364 * D_8075EAD0;
    }
    var_v1 = arg0->unk384;
    arg0->unk360 = arg0->unk338->animation_state->scale_y * *var_v1;
    arg0->unk364 = arg0->unk360;
}
*/

void func_8071F444(Struct80717D84 *arg0, s8 *arg1) {
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
    arg0->unk344 += (1.0 + func_80612794(var_v1->unk4)) * (f32)(1.0 + (var_v1->unk0 * D_8075EAD8));
    arg0->unk340 += func_80612794(var_v1->unkC) * (f32)(var_v1->unk8 * 0.5);
    if (arg0->unk350 == 0) {
        arg0->unk34E = (func_80612794(var_v1->unkC) * 2.5) + 2.5;
    }
    var_v1->unk4 += 100.0f;
    var_v1->unkC += 50.0f;
    if (arg0->unk344 > 960.0f) {
        *arg1 = 1;
    }
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F660.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F758.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_119370/func_8071F8E4.s")
