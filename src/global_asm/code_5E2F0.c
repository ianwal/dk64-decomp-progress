#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u16 D_80748300;

extern f32 D_80758CA0;
extern f32 D_80758CA4;
extern f32 D_80758CA8;
extern f32 D_80758CAC;

extern f32 *D_8076A0B4;
extern f32 *D_8076A0B8;
extern f32 *D_8076A0BC;

extern u16 D_807F7EC8;

extern u8 D_807F7EF8;
extern f32 D_807F7ECC;
extern f32 D_807F7ED0;
extern f32 D_807F7ED4;
extern f32 D_807F7ED8;
extern f32 D_807F7EDC;
extern f32 D_807F7EE0;
extern f32 D_807F7EE4;
extern f32 D_807F7EE8;
extern s16 D_807F7EFA;
extern u16 D_807F7EFC;
extern u16 D_807F7EFE;

f32 func_80612D10(f32);

void func_806595F0(u8 arg0) {
    D_807F7EF8 = arg0;
}

void func_80659600(u16 arg0) {
    D_807F7EFA = arg0;
}

void func_80659610(u16 arg0) {
    D_807F7EFC = arg0;
}

void func_80659620(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3) {
    *arg0 = D_8076A0B4[arg3];
    *arg1 = D_8076A0B8[arg3];
    *arg2 = D_8076A0BC[arg3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_80659670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065996C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_80659DB0.s")

/*
extern f32 *D_8076A0C0; // pointer to an array of floats
extern f32 *D_8076A0C4;
extern f32 *D_8076A0C8;
extern s32 D_807F6C28;

// TODO: MIN/MAX macros?
void func_80659DB0(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    u8 phi_v1;
    s32 iChunk;

    if (D_807F6C28 <= 0) {
        phi_v1 = 1;
    } else {
        phi_v1 = D_807F6C28;
    }
    iChunk = 0;
    if (arg3 == -1) {
        if (phi_v1 != 0) {
            do {
                if (arg0 <= 1.0f) {
                    D_8076A0C0[iChunk] = arg0;
                } else {
                    D_8076A0C0[iChunk] = 1.0f;
                }
                iChunk++;
                if (arg1 <= 1.0f) {
                    D_8076A0C4[iChunk] = arg1;
                } else {
                    D_8076A0C4[iChunk] = 1.0f;
                }
                if (arg2 <= 1.0f) {
                    D_8076A0C8[iChunk] = arg2;
                } else {
                    D_8076A0C8[iChunk] = 1.0f;
                }
            } while (iChunk < phi_v1);
        }
    } else {
        if (arg0 <= 1.0f) {
            D_8076A0C0[arg3] = arg0;
        } else {
            D_8076A0C0[arg3] = 1.0f;
        }
        if (arg1 <= 1.0f) {
            D_8076A0C4[arg3] = arg1;
        } else {
            D_8076A0C4[arg3] = 1.0f;
        }
        if (arg2 <= 1.0f) {
            D_8076A0C8[arg3] = arg2;
        } else {
            D_8076A0C8[arg3] = 1.0f;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_80659F7C.s")

void func_8065A570(void) {
    D_807F7ECC = func_80612D10(D_80758CA0);
    D_807F7ED0 = func_80612D10(D_80758CA4);
    D_807F7ED4 = 1.0f / (D_807F7ECC - D_807F7ED0);
    D_807F7ED8 = D_807F7ECC;
    D_807F7EDC = D_807F7ED0;
    D_807F7EE0 = D_807F7ED4;
    D_807F7EE4 = 25.0f;
    D_807F7EE8 = 65.0f;
    D_80748300 = 0;
    D_807F7EF8 = 0;
    D_807F7EFA = -1;
    D_807F7EFC = 700;
    D_807F7EFE = 600;
}

void func_8065A648(void) {
    D_80748300 = 0;
}

void func_8065A654(void) {
    D_807F7EC8 = 0;
}

void func_8065A660(f32 arg0, f32 arg1) {
    D_807F7EE4 = arg0;
    D_807F7EE8 = arg1;
    D_807F7ED8 = func_80612D10(arg0 * D_80758CA8);
    D_807F7EDC = func_80612D10(arg1 * D_80758CAC);
    D_807F7EE0 = 1.0f / (D_807F7ED8 - D_807F7EDC);
}

void func_8065A6F8(u16 arg0) {
    D_807F7EFE = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065A708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065A884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065BAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065BE74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065BF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065C240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_8065C334.s")
