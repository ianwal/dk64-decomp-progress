#include <ultra64.h>
#include "functions.h"

typedef struct {
    s32 unk0; // *next?
    s32 (*unk4)(s32 a, s32 b, s32 c); 
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct807452A0;

extern Struct807452A0 *D_global_asm_807452A0;
extern u32 D_global_asm_8076A068;

void func_global_asm_80600950(void) {
    D_global_asm_807452A0 = NULL;
}

s32 func_global_asm_8060095C(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 += 0x50505050;
    *arg2 += 0x50505050;
    return arg0 + 0x3FFF00FF;
}

// malloc, small struct?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5650/func_global_asm_8060098C.s")

void func_global_asm_8061130C(void *);

void func_global_asm_80600B10(void) {
    s32 var_s1;
    Struct807452A0 *var_s0;

    var_s0 = D_global_asm_807452A0;
    var_s1 = 0;
    while (var_s0 != NULL && !var_s1) {
        if (D_global_asm_8076A068 >= (var_s0->unk8 & 0x7FFFFFFF)) {
            var_s0->unk4(var_s0->unkC, var_s0->unk10, var_s0->unk14);
            func_global_asm_8061130C(var_s0);
            var_s0 = var_s0->unk0;
        } else {
            var_s1 = 1;
        }
    }
    D_global_asm_807452A0 = var_s0;
}

void func_global_asm_80600BBC(void *arg0) {
    Struct807452A0 *var_s0;
    Struct807452A0 *var_s1;

    var_s0 = D_global_asm_807452A0;
    var_s1 = NULL;
    while (var_s0 != NULL) {
        if (arg0 == var_s0->unk4 || (arg0 == 0 && var_s0->unk8 & 0x80000000)) {
            func_global_asm_8061130C(var_s0);
            var_s0 = var_s0->unk0;
            if (var_s1 != NULL) {
                var_s1->unk0 = var_s0;
            } else {
                D_global_asm_807452A0 = var_s0;
            }
        } else {
            var_s1 = var_s0;
            var_s0 = var_s0->unk0;
        }
    }
}

void func_global_asm_80600C68(void) {
    Struct807452A0 *var_s0;
    Struct807452A0 *var_s1;
    s32 var_s2;

    var_s0 = D_global_asm_807452A0;
    var_s1 = NULL;
    var_s2 = FALSE;
    while (var_s0 != NULL && !var_s2) {
        if ((var_s0->unk8 & 0x7FFFFFFF) < D_global_asm_8076A068) {
            if (var_s0->unk8 & 0x80000000) {
                if (var_s1 != NULL) {
                    var_s1->unk0 = var_s0->unk0;
                } else {
                    D_global_asm_807452A0 = var_s0->unk0;
                }
                func_global_asm_8061130C(var_s0);
            } else {
                var_s1 = var_s0;
            }
            var_s0 = var_s0->unk0;
        } else {
            var_s2 = TRUE;
        }
    }
}
