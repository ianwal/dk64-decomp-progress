#include <ultra64.h>
#include "functions.h"

typedef struct global_asm_struct_2 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} GlobalASMStruct2;

void func_80732420(GlobalASMStruct2 *arg0, u32 arg1, u32 arg2) {
    arg0->unk0 = arg1;
    arg0->unk8 = arg2;
    arg0->unk4 = arg0->unk0;
    arg0->unkC = 0;
}

s32 func_80732444(s32 arg0, s32 arg1, GlobalASMStruct2 *arg2, s32 arg3, s32 arg4) {
    s32 sp4;
    s32 sp0;

    sp0 = 0;
    sp4 = ((arg3 * arg4) + 0xF) & ~0xF;
    if (!((arg2->unk4 + sp4) > (arg2->unk0 + arg2->unk8))) {
        sp0 = arg2->unk4;
        arg2->unk4 += sp4;
    } else {

    }
    return sp0;
}
