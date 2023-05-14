#include <ultra64.h>
#include "functions.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct807324D0_unk4;

typedef struct {
    s16 unk0;
    s16 unk2;
    Struct807324D0_unk4 unk4[4];
} Struct807324D0;

void func_807324D0(Struct807324D0 *arg0, s32 arg1) {
    s32 sp4;
    s32 sp0;

    sp4 = arg1;
    for (sp0 = 0; sp0 < arg0->unk2; sp0++) {
        arg0->unk4[sp0].unk0 += sp4;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    s16 unkA;
    s32 unkC;
    s32 unk10;
} GlobalASMStruct69;

typedef struct {
    s32 unk0;
    s32 unk4;
    GlobalASMStruct69 *unk8;
    s16 unkC;
    u8 unkE;
} Struct807327F4;

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s32 unk10[1]; // TODO: How many elements?
} Struct80732730;

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC[1]; // TODO: How many elements?
} Struct80732618;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4[1]; // TODO: How many elements?
} Struct80732534;

void func_80732730(Struct80732730 *arg0, s32 arg1, s32 arg2);
void func_807327F4(Struct807327F4 *arg0, s32 arg1, s32 arg2);
void func_80732894(GlobalASMStruct69 *arg0, s32 arg1, s32 arg2);
void func_80732618(Struct80732618 *arg0, s32 arg1, s32 arg2);

void func_80732534(Struct80732534 *arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = arg0;
    sp20 = arg1;
    if (arg0->unk0 != 0x4231) {
        return;
    }
    for (sp1C = 0; sp1C < arg0->unk2; sp1C++) {
        arg0->unk4[sp1C] += sp24;
        if (arg0->unk4[sp1C] != 0) {
            func_80732618(arg0->unk4[sp1C], sp24, sp20);
        }
    }
}

void func_80732618(Struct80732618 *arg0, s32 arg1, s32 arg2) {
    s32 i;

    if (arg0->unk2 != 0) {
        return;
    }
    arg0->unk2 = 1;
    if (arg0->unk8 != 0) {
        arg0->unk8 += arg1;
        func_80732730(arg0->unk8, arg1, arg2);
    }
    for (i = 0; i < arg0->unk0; i++) {
        arg0->unkC[i] += arg1;
        if (arg0->unkC[i] != 0) {
            func_80732730(arg0->unkC[i], arg1, arg2);
        }
    }
}

void func_80732730(Struct80732730 *arg0, s32 arg1, s32 arg2) {
    s32 i;

    if (arg0->unk3 != 0) {
        return;
    }
    arg0->unk3 = 1;
    for (i = 0; i < arg0->unkE; i++) {
        arg0->unk10[i] += arg1;
        func_807327F4(arg0->unk10[i], arg1, arg2);
    }
}

void func_807327F4(Struct807327F4 *arg0, s32 arg1, s32 arg2) {
    if (arg0->unkE != 0) {
        return;
    }
    arg0->unkE = 1;
    arg0->unk0 = arg0->unk0 + arg1;
    arg0->unk4 = arg0->unk4 + arg1;
    arg0->unk8 = (s32)arg0->unk8 + arg1;
    func_80732894(arg0->unk8, arg1, arg2);
}

void func_80732894(GlobalASMStruct69 *arg0, s32 arg1, s32 arg2) {
    if (arg0->unk9 != 0) {
        return;
    }
    arg0->unk9 = 1;
    arg0->unk0 += arg2;
    if (arg0->unk8 == 0) {
        arg0->unk10 += arg1;
        if (arg0->unkC != 0) {
            arg0->unkC += arg1;
        }
    } else if (arg0->unk8 == 1) {
        if (arg0->unkC != 0) {
            arg0->unkC += arg1;
        }
    }
}
