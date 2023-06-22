#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FD8E0.s")

s32 func_806FBD5C(s16, void*);
void *func_806FC530(void *arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4, u8 arg5);
extern s16 D_80744490;

/*
// TODO: Small regalloc
void func_806FD8E0(void *arg0, s16 arg1, void *arg2, s16 arg3, u8 arg4) {
    func_806FC530(arg0, arg1, (D_80744490 - func_806FBD5C(arg1, arg2)) * 2, arg3 * 4, arg2, arg4);
}
*/

// TODO: Does this return the void* from func_806FC530?
void func_806FD950(void *arg0, s16 arg1, void *arg2, s16 arg3) {
    func_806FC530(arg0, arg1, 0x60, arg3 * 4, arg2, 1);
}

extern s16 D_80744490;
extern s16 D_80744494;

typedef struct GlobalASMStruct2 GlobalASMStruct2;

struct GlobalASMStruct2 {
    GlobalASMStruct2 *next;
    s32 unk4;
    s32 unk8;
    u8 padC[0x18 - 0x0C];
    f32 unk18;
    s16 unk1C;
};

extern GlobalASMStruct2 *D_80754AD0;
extern u16 D_80754AD4;

extern f32 D_8075DFB0;
extern f32 D_8075DFB4;

extern u8 D_807FD890;
extern u16 D_807FD892;
extern u8 D_807FD894;
extern u8 D_807FD895;
extern u8 D_807FD896;
extern u8 D_807FD897;
extern u8 D_807FD898;
extern u8 D_807FD899;
extern s32 D_807FD8A0;
extern Mtx D_807FD928;
extern f32 D_807FD968;
extern s32 D_807FD978;

void func_806FD9A0(void) {
    D_80754AD0 = NULL;
    D_80754AD4 = 0;
}

GlobalASMStruct2 *func_806FD9B4(s16 arg0) {
    GlobalASMStruct2 *var_v1;

    var_v1 = D_80754AD0;
    while (var_v1 != NULL && arg0 != var_v1->unk1C) {
        var_v1 = var_v1->next;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FD9FC.s")

/*
s32 func_806FD9FC(s32 arg0, s16 arg1, s16 arg2) {
    s32 temp_t2;

    temp_t2 = func_806FD9B4(arg1)->unk8[arg2];
    arg0 = temp_t2;
    arg0->unk30->unk4 = temp_t2->unk40->unk4;
    return arg0;
}
*/

f32 func_806FDA8C(s16 arg0) {
    return func_806FD9B4(arg0)->unk18;
}

void func_806FDAB8(s16 arg0, f32 arg1) {
    func_806FD9B4(arg0)->unk18 = arg1;
}

void func_806FDAEC(s16 arg0) {
    GlobalASMStruct2 *var_a1;
    GlobalASMStruct2 *var_v0;

    var_a1 = D_80754AD0;
    var_v0 = NULL;
    while (var_a1 != NULL && arg0 != var_a1->unk1C) {
        var_v0 = var_a1;
        var_a1 = var_a1->next;
    }
    if (var_v0 != NULL) {
        var_v0->next = var_a1->next;
    } else {
        D_80754AD0 = var_a1->next;
    }
    func_8061130C(var_a1->unk4, var_a1);
    func_8061130C(var_a1->unk8, var_a1);
    func_8061130C(var_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FDB8C.s")

void func_806FDF1C(s16 arg0, s32 arg1) {
    func_80002A30(func_806FD9B4(arg0)->unk4, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FDF54.s")

extern f32 D_8075DD58;
extern f32 D_8075DD5C;
extern f64 D_8075DD60;
extern f32 D_8075DD68;

/*
// TODO: Float nonsense :( Maybe rodata?
void func_806FDF54(f32 *arg0, f32 *arg1) {
    while (*arg1 < 0.0f) {
        *arg1 += D_8075DD58;
    }
    while (D_8075DD5C <= *arg1) {
        *arg1 -= D_8075DD5C;
    }
    *arg0 = (func_806CC190((*arg0 * 2048.0) / D_8075DD60, (*arg1 * 2048.0) / D_8075DD60, 5.0f) * D_8075DD68) * 0.00048828125;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FE078.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FEDB0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FEF7C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF01C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF144.s")

void func_806FF32C(s32 arg0, Actor *arg1) {
    func_806FF144(func_806FEDB0(arg0, arg1->PaaD->unk1A4));
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF358.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF628.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF75C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFB2C.s")

// Hmm, weird m2c errors
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFEAC.s")

void func_806FFF5C(void) {
    // Texture, maybe pulling it into cache?
    getPointerTableFile(0x19, 0x138B, 1, 1);
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80700088.s")

s32 func_80700088(f32 arg0, s32 arg1);

void func_807002AC(u16 *arg0, s16 **arg1, f32 arg2) {
    s16 *temp_v0;
    s16 *var_s0;
    s16 i;

    temp_v0 = malloc(0xA000);
    *arg1 = temp_v0;
    func_8061134C(temp_v0);
    var_s0 = *arg1;
    for (i = 0; i < 0x5000; i++) {
        *var_s0 = func_80700088(arg2, *arg0++);
        var_s0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_8070033C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_8070068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807007B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807009F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80700AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80700BF4.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80701098.s")

void func_80701C90(void) {
    D_807FD890 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80701CA0.s")

// TODO: Is this signature correct?
void func_807024E0(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

// TODO: Is this signature correct?
void func_807023E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC) {
    func_807024E0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, 1, 0x10, 0, 0);
}

// TODO: Is this signature correct?
void func_80702464(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, u8 argD, u8 argE) {
    func_807024E0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, 0, 0);
}

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807024E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80703374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807035C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80703850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80703AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80703CF8.s")

void func_807040D0(u16 arg0) {
    D_807FD892 = arg0;
}

void func_807040E0(u8 arg0, u8 arg1, u8 arg2) {
    D_807FD894 = arg0;
    D_807FD895 = arg1;
    D_807FD896 = arg2;
}

void func_80704108(u8 arg0, u8 arg1, u8 arg2) {
    D_807FD897 = arg0;
    D_807FD898 = arg1;
    D_807FD899 = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80704130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80704298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80704444.s")

/*
// TODO: Regalloc
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} GlobalASMStruct3;

void func_80704444(GlobalASMStruct3 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5) {
    arg0->unk0 = arg1;
    arg0->unk2 = arg2;
    arg0->unk4 = 1000;
    arg0->unk8 = (arg3 << arg5);
    arg0->unkA = (arg4 << arg5);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80704484.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80704960.s")

extern f32 D_807FD968;
extern f32 D_807FD96C;
extern f32 D_807FD970;

void func_80704AFC(f32 arg0, f32 arg1, f32 arg2) {
    D_807FD968 = arg0;
    D_807FD96C = arg1;
    D_807FD970 = arg2;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80704B20.s")

typedef struct global_asm_struct_1 {
    u8 unk0[0x0C];
    u8 unkC;
    u8 unkD;
    u8 unkE;
} GlobalASMStruct1;

void func_80705B14(GlobalASMStruct1 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg0->unkC = arg1;
    arg0->unkD = arg2;
    arg0->unkE = arg3;
}

void func_80705B30(void) {
    D_807FD8A0 = 0;
    guOrtho(&D_807FD928,
        0.0f,
        (D_80744490 * 16.0f) - 1.0,
        (D_80744494 * 16.0f) - 1.0,
        0.0f,
        D_8075DFB0,
        D_8075DFB4,
        1.0f
    );
    D_807FD968 = -1.0f;
    D_807FD978 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80705C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80705F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807063B8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807065F8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807069A4.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80706F90.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_8070770C.s")

// Jumptable, 2524 bytes
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80707980.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_8070835C.s")

extern f32 D_80754CE8;

void func_80708574(f32 arg0) {
    // TODO: Clamp macro?
    if (arg0 < 0.0) {
        arg0 = 0.0f;
    }
    if (arg0 > 1.0) {
        arg0 = 1.0f;
    }
    D_80754CE8 = arg0;
}
