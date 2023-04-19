#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FD8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FD950.s")

extern s16 D_80744490;
extern s16 D_80744494;

extern s32 D_80754AD0; // TODO: Might be an pointer to/array of structs of type GlobalASMStruct2
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
    D_80754AD0 = 0;
    D_80754AD4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FD9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FD9FC.s")

// TODO: Any overlap with existing/known structs?
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x18 - 0x08];
    f32 unk18;
} GlobalASMStruct2;

GlobalASMStruct2 *func_806FD9B4(s16);

f32 func_806FDA8C(s16 arg0) {
    return func_806FD9B4(arg0)->unk18;
}

void func_806FDAB8(s16 arg0, f32 arg1) {
    func_806FD9B4(arg0)->unk18 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FDAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FDB8C.s")

void func_806FDF1C(s16 arg0, s32 arg1) {
    func_80002A30(func_806FD9B4(arg0)->unk4, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FDF54.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FE078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FEDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FEF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF144.s")

void func_806FF32C(s32 arg0, Actor *arg1) {
    func_806FF144(func_806FEDB0(arg0, arg1->PaaD->unk1A4));
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FF75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFB2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFEAC.s")

void func_806FFF5C(void) {
    // Texture, maybe pulling it into cache?
    getPointerTableFile(0x19, 0x138B, 1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_806FFF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80700088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807002AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_8070033C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_8070068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807007B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807009F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80700AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80700BF4.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80701098.s")

void func_80701C90(void) {
    D_807FD890 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80701CA0.s")

// Yikes, lots of params. Perhaps it's passing a struct by value on the stack?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_807023E8.s")

// Yikes, lots of params. Perhaps it's passing a struct by value on the stack?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_80702464.s")

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
// TODO: REGALLOC'D
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} GlobalASMStruct3;

void func_80704444(GlobalASMStruct3 *arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4, u8 arg5) {
    arg0->unk0 = arg1;
    arg0->unk2 = arg2;
    arg0->unk4 = 1000;
    arg0->unk8 = arg3 << arg5;
    arg0->unkA = arg4 << arg5;
}*/

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
