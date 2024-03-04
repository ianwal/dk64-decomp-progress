#include <ultra64.h>
#include "functions.h"

// rodata
/*
static const f64 D_global_asm_8075EB40 = 300.0;
static const f32 D_global_asm_8075EB48 = 999999.0f;
static const f64 D_global_asm_8075EB50 = 0.0050000000000000001;
static const f32 D_global_asm_8075EB58 = 999999.0f;
static const f64 D_global_asm_8075EB60 = 0.0500000000000000028;
static const f64 D_global_asm_8075EB70 = 0.400000000000000022;
static const f64 D_global_asm_8075EB78 = 3.14159274101257324;
*/

void func_global_asm_80722E00(s32 map) {
    void *paths;

    paths = getPointerTableFile(0xF, map, 1, 1);
    func_global_asm_80722E48(paths);
    func_global_asm_8066B434(paths, 0x47, 0x27);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80722E48.s")

// Used in func_global_asm_80722FEC as well as func_global_asm_807245D8.
typedef struct global_asm_struct_3 {
    s32 unk0; // Pointer
    s16 unk4; // Unknown, seen value of 2
} GlobalASMStruct3;

extern GlobalASMStruct3 *D_global_asm_807FDB90[];

s32 func_global_asm_80722FEC(u8 arg0) {
    if (D_global_asm_807FDB90[arg0]) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723020.s")

typedef struct {
    Actor *unk0;
    u8 pad4[0x14 - 0x4];
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 unk17;
    s32 unk18;
    s32 unk1C;
    s8  unk20;
    s8  unk21;
} GlobalASMStruct00;

extern GlobalASMStruct00* D_global_asm_807FDBF8[];

void func_global_asm_80723284(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk20 = arg1;
    }
}

void func_global_asm_807232B8(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk16 = arg1;
    }
}

void func_global_asm_807232EC(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk15 = arg1;
    }
}

void func_global_asm_80723320(s32 arg0, s32 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk18 = arg1;
    }
}

void func_global_asm_8072334C(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk21 = arg1;
    }
}

void func_global_asm_80723380(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk14 = arg1;
    }
}

void func_global_asm_807233B4(Actor *arg0) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FDBF8[i] != NULL) {
            if (arg0 == D_global_asm_807FDBF8[i]->unk0) {
                func_global_asm_80723428(i);
            }
        }
    }
}

void func_global_asm_80723428(s32 arg0) {
    if (arg0 == -1 || D_global_asm_807FDBF8[arg0]) {
        free(D_global_asm_807FDBF8[arg0]);
        D_global_asm_807FDBF8[arg0] = NULL;
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_807238D4.s")

u8 func_global_asm_80723C98(s32 arg0) {
    if (arg0 == -1 || !D_global_asm_807FDBF8[arg0]) {
        return 0;
    }
    return D_global_asm_807FDBF8[arg0]->unk21;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723CCC.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80724154.s")

f32 func_global_asm_80724308(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, f32 arg5);

/*
void func_global_asm_80724154(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4, f32 *arg5) {
    f32 test;
    f32 var_f22;
    f32 highest;
    s32 var_s0;
    s32 i;

    highest = 999999.0f;
    var_s0 = *arg4;
    var_f22 = *arg5 - 0.5;
    i = 0x14;
    if (var_f22 < 0.0) {
        if (var_s0 > 0) {
            var_s0--;
            var_f22 += 1.0f;
        } else {
            var_f22 = 0.0f;
        }
    }
    while (i-- != 0) {
        test = func_global_asm_80724308(arg0, arg1, arg2, arg3, var_s0, var_f22);
        if (test < highest) {
            *arg4 = var_s0;
            *arg5 = var_f22;
            highest = test;
        }
        var_f22 += 0.05;
        if (var_f22 >= 1.0f && var_s0 < D_global_asm_807FDB90[arg0]->unk4) {
            var_s0++;
            var_f22 -= 1.0f;
        } else if (var_f22 >= 1.0f) {
            var_f22 = 1.0f;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80724308.s")

s16 func_global_asm_807245D8(s32 arg0) {
    return D_global_asm_807FDB90[arg0]->unk4;
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_807245F0.s")

void func_global_asm_80724874(Actor *arg0) {
    if (arg0->unk118 != NULL) {
        free(arg0->unk118);
        arg0->unk118 = NULL;
    }
}
