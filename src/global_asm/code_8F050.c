#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// TODO: What are the actual datatypes?
s32 func_8068A3A0(s32, u32 *);
s32 func_8068A404(s32, s32, s32);
void func_806883F4(Actor*, s32, s16, f32);

void func_8068A350(Actor *arg0, s32 arg1, s16 arg2) {
    func_8068842C(arg0, arg1, -1);
    func_80688460(arg0, arg1, 1);
    func_806883F4(arg0, arg1, arg2, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_8068A3A0.s")

/*
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} GlobalASMStruct76;

extern GlobalASMStruct76 D_80750100[];

// TODO: Fiddly, might want another look at the mips_to_c output
s32 func_8068A3A0(s32 arg0, u32 *arg1) {
    u32 phi_v0;
    s32 phi_v1;

    phi_v1 = FALSE;
    *arg1 = 0;
    for (phi_v0 = 0; phi_v0 < 7; phi_v0++) {
        if (arg0 == D_80750100[phi_v0].unk0) {
            phi_v1 = TRUE;
            break;
        } else {
            *arg1 = phi_v0;
        }
    }
    return phi_v1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_8068A404.s")

void func_8068A4C8(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C;

    if (func_8068A3A0(arg1, &sp1C)) {
        func_8068A404(arg0, sp1C, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_8068A508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_8068A764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_8068A784.s")
