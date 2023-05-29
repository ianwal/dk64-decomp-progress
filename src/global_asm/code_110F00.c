#include <ultra64.h>
#include "functions.h"


void func_8070C89C(float (*mf)[4], f32, f32, f32);
void func_8070C8F4(float (*mf)[4], f32, f32, f32);
void func_8070C990(float (*mf)[4], f32, f32, f32);
void func_8070CAB4(float (*mf)[4], f32);
void func_8070CB2C(float (*mf)[4], f32);
void func_8070CBA4(float (*mf)[4], f32);
void func_8070CCC4(float (*mf)[4]);
void func_8070CD44(float (*mf)[4], f32, f32, f32);
void func_8070CDD0(f32 (*arg0)[4], f32 (*arg1)[4], f32 arg2, f32 arg3, f32 arg4);
void func_8070D07C(Mtx*, Mtx*, f32, f32, f32, f32, f32, f32);

extern f64 D_8075E470;
extern f64 D_8075E478;
extern f64 D_8075E480;

// tiny, round float, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_110F00/func_8070C200.s")

void func_8070C210(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    func_8070CCC4(mf);
    mf[0][0] = arg1;
    mf[1][1] = arg2;
    mf[2][2] = arg3;
    mf[3][3] = 1.0f;
    mf[3][0] = arg4;
    mf[3][1] = arg5;
    mf[3][2] = arg6;
}

void func_8070C210(float (*mf)[4], f32, f32, f32, f32, f32, f32);

void func_8070C27C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp28[4][4];

    func_8070C210(&sp28, arg1, arg2, arg3, arg4, arg5, arg6);
    guMtxF2L(&sp28, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_110F00/func_8070C2D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_110F00/func_8070C590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_110F00/func_8070C808.s")

/*
// TODO: Order of operations nonsense
void func_8070C808(float (*mf)[4], f32 *arg1, f32 *arg2, f32 *arg3) {
    *arg1 = (*arg1 * mf[0][0]) + (*arg2 * mf[1][0]) + (*arg3 * mf[2][0]) + mf[3][0];
    *arg2 = (*arg1 * mf[0][1]) + (*arg2 * mf[1][1]) + (*arg3 * mf[2][1]) + mf[3][1];
    *arg3 = (*arg1 * mf[0][2]) + (*arg2 * mf[1][2]) + (*arg3 * mf[2][2]) + mf[3][2];
}
*/

void func_8070C89C(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f2;

    func_8070CCC4(mf);
    temp_f0 = arg2 / arg3;
    temp_f2 = arg1 / arg3;
    mf[1][1] = temp_f2;
    mf[1][2] = temp_f0;
    mf[2][1] = -temp_f0;
    mf[2][2] = temp_f2;
}

void func_8070C8F4(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3) {
    f32 phi_f0;
    f32 phi_f2;

    phi_f0 = arg2 / arg3;
    phi_f2 = arg1 / arg3;
    if (arg2 == 0.0) {
        phi_f0 = 0.0f;
    }
    if (arg1 == 0.0) {
        phi_f2 = 0.0f;
    }
    func_8070CCC4(mf);
    mf[2][0] = phi_f0;
    mf[0][2] = -phi_f0;
    mf[0][0] = phi_f2;
    mf[2][2] = phi_f2;
}

void func_8070C990(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f2;

    func_8070CCC4(mf);
    temp_f0 = arg2 / arg3;
    temp_f2 = arg1 / arg3;
    mf[0][0] = temp_f2;
    mf[0][1] = temp_f0;
    mf[1][1] = temp_f2;
    mf[1][0] = -temp_f0;
}

void func_8070C9E8(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3) {
    Mtx sp18;

    func_8070C89C(&sp18, arg1, arg2, arg3);
    guMtxF2L(&sp18, arg0);
}

void func_8070CA2C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3) {
    Mtx sp18;

    func_8070C8F4(&sp18, arg1, arg2, arg3);
    guMtxF2L(&sp18, arg0);
}

void func_8070CA70(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3) {
    Mtx sp18;

    func_8070C990(&sp18, arg1, arg2, arg3);
    guMtxF2L(&sp18, arg0);
}

void func_8070CAB4(float (*mf)[4], f32 arg1) {
    f32 pad; // TODO: Get rid of this if possible
    f32 temp_f0;
    f32 sp24;
    f32 temp_f12;

    temp_f12 = arg1 * D_8075E470;
    temp_f0 = func_80612D1C(temp_f12);
    sp24 = func_80612D10(temp_f12);
    func_8070CCC4(mf);
    mf[1][2] = temp_f0;
    mf[2][1] = -temp_f0;
    mf[1][1] = sp24;
    mf[2][2] = sp24;
}

void func_8070CB2C(float (*mf)[4], f32 arg1) {
    f32 pad; // TODO: Get rid of this if possible
    f32 temp_f0;
    f32 sp24;
    f32 temp_f12;

    temp_f12 = arg1 * D_8075E478;
    temp_f0 = func_80612D1C(temp_f12);
    sp24 = func_80612D10(temp_f12);
    func_8070CCC4(mf);
    mf[2][0] = temp_f0;
    mf[0][2] = -temp_f0;
    mf[0][0] = sp24;
    mf[2][2] = sp24;
}

void func_8070CBA4(float (*mf)[4], f32 arg1) {
    f32 pad; // TODO: Get rid of this if possible
    f32 temp_f0;
    f32 sp24;
    f32 temp_f12;

    temp_f12 = arg1 * D_8075E480;
    temp_f0 = func_80612D1C(temp_f12);
    sp24 = func_80612D10(temp_f12);
    func_8070CCC4(mf);
    mf[0][1] = temp_f0;
    mf[1][0] = -temp_f0;
    mf[0][0] = sp24;
    mf[1][1] = sp24;
}

void func_8070CC1C(Mtx *arg0, f32 arg1) {
    Mtx sp18;

    func_8070CAB4(&sp18, arg1);
    guMtxF2L(&sp18, arg0);
}

void func_8070CC54(Mtx *arg0, f32 arg1) {
    Mtx sp18;

    func_8070CB2C(&sp18, arg1);
    guMtxF2L(&sp18, arg0);
}

void func_8070CC8C(Mtx *arg0, f32 arg1) {
    Mtx sp18;

    func_8070CBA4(&sp18, arg1);
    guMtxF2L(&sp18, arg0);
}

void func_8070CCC4(float (*mf)[4]) {
    mf[0][0] = 1.0f;
    mf[1][0] = 0.0f;
    mf[2][0] = 0.0f;
    mf[3][0] = 0.0f;
    mf[0][1] = 0.0f;
    mf[1][1] = 1.0f;
    mf[2][1] = 0.0f;
    mf[3][1] = 0.0f;
    mf[0][2] = 0.0f;
    mf[1][2] = 0.0f;
    mf[2][2] = 1.0f;
    mf[3][2] = 0.0f;
    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
}

void func_8070CD14(Mtx *arg0) {
    Mtx sp18;

    func_8070CCC4(&sp18);
    guMtxF2L(&sp18, arg0);
}

void func_8070CD44(float (*mf)[4], f32 arg1, f32 arg2, f32 arg3) {
    func_8070CCC4(mf);
    mf[3][0] = arg1;
    mf[3][1] = arg2;
    mf[3][2] = arg3;
}

void func_8070CD8C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3) {
    float sp18[4][4];

    func_8070CD44(&sp18, arg1, arg2, arg3);
    guMtxF2L(&sp18, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_110F00/func_8070CDD0.s")

/*
// TODO: Surprisingly close but very fiddly
void func_8070CDD0(f32 (*arg0)[4], f32 (*arg1)[4], f32 arg2, f32 arg3, f32 arg4) {
    f32 sp30;
    f32 sp2C;
    f32 sp24;
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f20;
    f32 temp_f8;
    f32 phi_f12;
    f32 phi_f14;
    f32 phi_f16;
    f32 phi_f18;
    f32 phi_f20;

    if ((arg2 == 0.0f) && (arg4 == 0.0f)) {
        if (arg3 == 0.0f) {
            func_8070CCC4(arg0);
            func_8070CCC4(arg1);
            return;
        }
        sp24 = 0.0f;
        sp2C = 0.0f;
        sp30 = 1.0f;
        phi_f12 = 1.0f;
        phi_f14 = 0.0f;
        phi_f16 = 0.0f;
        phi_f18 = 0.0f;
        phi_f20 = -1.0f;
    } else {
        temp_f16 = 1.0 / sqrtf(arg2 * arg2 + (arg3 * arg3) + (arg4 * arg4));
        temp_f20 = arg3 * temp_f16;
        arg2 *= temp_f16;
        arg4 *= temp_f16;
        temp_f0 = sqrtf((arg2 * arg2) + (arg4 * arg4));
        temp_f16_2 = 1.0 / temp_f0;
        temp_f8 = -arg4 * temp_f16_2;
        sp24 = -arg2 * temp_f16_2;
        sp2C = -arg4;
        sp30 = temp_f20 * temp_f8;
        phi_f12 = temp_f8;
        phi_f14 = temp_f20 * sp24;
        phi_f16 = -arg2;
        phi_f18 = temp_f0;
        phi_f20 = -temp_f20;
    }

    // Setup matrix 1
    arg0[0][0] = phi_f12;
    arg0[1][0] = phi_f14;
    arg0[2][0] = phi_f16;
    arg0[3][0] = 0.0f;
    arg0[0][1] = 0.0f;
    arg0[1][1] = phi_f18;
    arg0[2][1] = phi_f20;
    arg0[3][1] = 0.0f;
    arg0[0][2] = -sp24;
    arg0[1][2] = sp30;
    arg0[3][2] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
    arg0[2][2] = sp2C;

    // Setup matrix 2
    arg1[0][0] = phi_f12;
    arg1[1][0] = 0.0f;
    arg1[3][0] = 0.0f;
    arg1[0][1] = phi_f14;
    arg1[1][1] = phi_f18;
    arg1[2][0] = -sp24;
    arg1[3][1] = 0.0f;
    arg1[0][2] = phi_f16;
    arg1[1][2] = phi_f20;
    arg1[2][1] = sp30;
    arg1[3][2] = 0.0f;
    arg1[0][3] = 0.0f;
    arg1[1][3] = 0.0f;
    arg1[2][3] = 0.0f;
    arg1[3][3] = 1.0f;
    arg1[2][2] = sp2C;
}
*/

void func_8070D020(Mtx *arg0, Mtx *arg1, f32 arg2, f32 arg3, f32 arg4) {
    Mtx sp60;
    Mtx sp20;

    func_8070CDD0(&sp60, &sp20, arg2, arg3, arg4);
    guMtxF2L(&sp60, arg0);
    guMtxF2L(&sp20, arg1);
}

// TODO: It's going to be very similar to func_8070CDD0, better match that one first to get familiar with what it's doing
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_110F00/func_8070D07C.s")

void func_8070D300(Mtx *arg0, Mtx *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    Mtx sp68;
    Mtx sp28;

    func_8070D07C(&sp68, &sp28, arg2, arg3, arg4, arg5, arg6, arg7);
    guMtxF2L(&sp68, arg0);
    guMtxF2L(&sp28, arg1);
}
