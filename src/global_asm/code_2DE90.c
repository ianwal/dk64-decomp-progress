#include <ultra64.h>
#include "functions.h"


extern u8 D_807F5D84;
extern u8 D_80747B20;

extern f32 D_807F5D94;
extern f64 D_80758150;
extern f32 D_807F5D8C;
extern f32 D_807F5D90;

extern u8 D_80747B40;
extern void *D_807F5DD8;

extern s32 D_80747B28;
extern u8 *D_80747B2C;
extern s32 D_80747B38;

extern f32 D_80747B44;
extern f32 D_80747B48;
extern f32 D_80747B4C;
extern f32 D_80747B50;

f32 func_80665AE4(s32, s32, s32,s32);
void func_80704130(s32, s32, s32, s32, s32, s32);
void func_8062A274(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80002E98(void *arg0, s32 arg1, s32 arg2);

void func_80629190(void) {
    D_807F5D84 = 0;
}

u8 func_8062919C(void) {
    return D_807F5D84;
}

u8 func_806291A8(void) {
    return D_80747B20;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2DE90/func_806291B4.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2DE90/func_80629300.s")

void func_8062A130(s32 arg0, s32 arg1, s32 arg2) {
    f32 temp_f0;
    s32 phi_v0;

    temp_f0 = func_80665AE4(0xA0, 0x78, arg0, arg1);
    if (D_807F5D94 < 20.0) {
        func_80704130(arg2, 0xFF, 0xFF, 0xFF, 0xFF, 0);
        return;
    }
    phi_v0 = 0;
    if (D_807F5D94 < temp_f0) {
        if ((temp_f0 - D_807F5D94) < 25.0) {
            phi_v0 = (s16) (((temp_f0 - D_807F5D94) / 25.0) * D_80758150);
        } else {
            phi_v0 = 0xFF;
        }
    } else {
        phi_v0 = 0;
    }
    func_80704130(arg2, 0xFF, 0xFF, 0xFF, phi_v0, 0);
}

void func_8062A228(s32 arg0, s32 arg1, s32 arg2) {
    func_8062A274(arg0, arg1, arg2, 0, 0);
}

void func_8062A24C(s32 arg0, s32 arg1, s32 arg2) {
    func_8062A274(arg0, arg1, arg2, 0xA0, 0x78);
}

void func_8062A274(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 temp_f0;
    s32 temp_v0;
    s32 temp_v1;
    s16 phi_v0;

    temp_v0 = arg0 - arg3;
    temp_v1 = arg1 - arg4;
    temp_f0 = sqrtf((temp_v0 * temp_v0) + (temp_v1 * temp_v1));
    if (temp_f0 < D_807F5D8C) {
        phi_v0 = 0;
    } else if (D_807F5D90 < temp_f0) {
        phi_v0 = 0xFF;
    } else {
        phi_v0 = ((temp_f0 - D_807F5D8C) / (D_807F5D90 - D_807F5D8C)) * 255.0f;
    }
    func_80704130(arg2, 0xFF, 0xFF, 0xFF, phi_v0, 0);
}

void func_8062A348(void) {
    s32 phi_v1;

    D_80747B2C = malloc((D_80747B28 << 5) + 1);
    phi_v1 = 0;
    while (D_80747B28 << 5 >= phi_v1) {
        // TODO: Might be better as array notation
        *(D_80747B2C + phi_v1) = phi_v1 / D_80747B28;
        phi_v1++;
    }
    D_80747B38 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2DE90/func_8062A3F0.s")

void func_8062A774(void) {
    if (!D_80747B40) {
        D_807F5DD8 = malloc(0x25800);
        func_80002E98(D_807F5DD8, 0, 0x25800);
        D_80747B40 = 1;
    }
}

void func_8062A7D0(void) {
    if (D_80747B40) {
        func_8061134C(D_807F5DD8);
        D_80747B40 = 0;
    }
}

void func_8062A808(s32 arg0, s32 arg1) {
    D_80747B4C = 2.0f;
    D_80747B50 = 2.0f;
    D_80747B44 = arg0;
    D_80747B48 = arg1;
}

s32 func_8062A844(s32 arg0) {
    return arg0;
}
