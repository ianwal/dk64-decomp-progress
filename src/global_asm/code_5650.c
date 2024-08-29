#include <ultra64.h>
#include "functions.h"

typedef struct DelayedCSData DelayedCSData;

struct DelayedCSData{
    DelayedCSData* next;
    s32 (*function)(s32 a, s32 b, s32 c); 
    s32 action_frame;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern DelayedCSData *D_global_asm_807452A0;
extern u32 D_global_asm_8076A068;

void func_global_asm_80600950(void) {
    D_global_asm_807452A0 = NULL;
}

void* func_global_asm_8060095C(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 += 0x50505050;
    *arg2 += 0x50505050;
    return (void*)(arg0 + 0x3FFF00FF);
}

// malloc, small struct?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5650/func_global_asm_8060098C.s")

/*
void func_global_asm_8060098C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    DelayedCSData *sp40;
    DelayedCSData *sp3C;
    s32 sp30;
    s32 sp28;
    s32 sp24;
    DelayedCSData *temp_v0;
    DelayedCSData *var_t0;
    DelayedCSData *var_v0;
    DelayedCSData *var_v1;
    s32 temp_t9;
    u32 temp_a0;
    s32 (* func_def)(s32, void*);

    sp3C = NULL;
    temp_v0 = malloc(0x18);
    sp28 = -0x390F5057;
    sp24 = 0x5FAFBA0C;
    sp40 = temp_v0;
    func_def = func_global_asm_8060095C((s32) ((s32)osPiReadIo + 0xC000FF01), &sp28, &sp24);
    func_def(sp24, &sp30);
    var_t0 = sp3C;
    if (sp30 != sp28) {
        arg1 *= 2;
    }
    sp40->function = arg0;
    sp40->unkC = arg2;
    sp40->unk10 = arg3;
    sp40->unk14 = arg4;
    sp40->next = NULL;
    temp_t9 = D_global_asm_8076A068 + arg1;
    sp40->action_frame = temp_t9;
    var_v1 = D_global_asm_807452A0;
    if (var_v1 != NULL) {
        var_v0 = var_v1->next;
        if (var_v0 != NULL) {
            temp_a0 = temp_t9 & 0x7FFFFFFF;
            if (temp_a0 >= (u32) (var_v1->action_frame & 0x7FFFFFFF)) {
loop_5:
                var_t0 = var_v1;
                var_v1 = var_v0;
                var_v0 = var_v0->next;
                if (var_v0 != NULL) {
                    if (temp_a0 >= (u32) (var_v1->action_frame & 0x7FFFFFFF)) {
                        goto loop_5;
                    }
                }
            }
        }
        if ((u32) (sp40->action_frame & 0x7FFFFFFF) < (u32) (var_v1->action_frame & 0x7FFFFFFF)) {
            sp40->next = var_v1;
            if (var_t0 != NULL) {
                var_t0->next = sp40;
                return;
            }
            goto block_12;
        }
        var_v1->next = sp40;
        return;
    }
block_12:
    D_global_asm_807452A0 = sp40;
}
*/

void func_global_asm_80600B10(void) {
    s32 var_s1;
    DelayedCSData *var_s0;

    var_s0 = D_global_asm_807452A0;
    var_s1 = 0;
    while (var_s0 != NULL && !var_s1) {
        if (D_global_asm_8076A068 >= (var_s0->action_frame & 0x7FFFFFFF)) {
            var_s0->function(var_s0->unkC, var_s0->unk10, var_s0->unk14);
            free(var_s0);
            var_s0 = var_s0->next;
        } else {
            var_s1 = 1;
        }
    }
    D_global_asm_807452A0 = var_s0;
}

void func_global_asm_80600BBC(void *arg0) {
    DelayedCSData *var_s0;
    DelayedCSData *var_s1;

    var_s0 = D_global_asm_807452A0;
    var_s1 = NULL;
    while (var_s0 != NULL) {
        if (arg0 == var_s0->function || (arg0 == NULL && var_s0->action_frame & 0x80000000)) {
            free(var_s0);
            var_s0 = var_s0->next;
            if (var_s1 != NULL) {
                var_s1->next = var_s0;
            } else {
                D_global_asm_807452A0 = var_s0;
            }
        } else {
            var_s1 = var_s0;
            var_s0 = var_s0->next;
        }
    }
}

void func_global_asm_80600C68(void) {
    DelayedCSData *var_s0;
    DelayedCSData *var_s1;
    s32 var_s2;

    var_s0 = D_global_asm_807452A0;
    var_s1 = NULL;
    var_s2 = FALSE;
    while (var_s0 != NULL && !var_s2) {
        if ((var_s0->action_frame & 0x7FFFFFFF) < D_global_asm_8076A068) {
            if (var_s0->action_frame & 0x80000000) {
                if (var_s1 != NULL) {
                    var_s1->next = var_s0->next;
                } else {
                    D_global_asm_807452A0 = var_s0->next;
                }
                free(var_s0);
            } else {
                var_s1 = var_s0;
            }
            var_s0 = var_s0->next;
        } else {
            var_s2 = TRUE;
        }
    }
}
