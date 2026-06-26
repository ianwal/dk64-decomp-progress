#include "common.h"

typedef struct DelayedCSData DelayedCSData;

struct DelayedCSData {
    DelayedCSData* next;
    s32 (*function)(s32 a, s32 b, s32 c); 
    s32 action_frame;
    s32 args[3];
};

extern DelayedCSData *D_global_asm_807452A0;
extern u32 D_global_asm_8076A068[1];

void func_global_asm_80600950(void) {
    D_global_asm_807452A0 = NULL;
}

void* func_global_asm_8060095C(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 += 0x50505050;
    *arg2 += 0x50505050;
    return (void*)(arg0 + 0x3FFF00FF);
}

void func_global_asm_8060098C(void *func, s32 time_delta, s32 arg2, s32 arg3, s32 arg4) {
    DelayedCSData *next;
    DelayedCSData *local;
    DelayedCSData *sp3C;
    s32 frame;
    u32 temp_a0;
    s32 sp30;
    s32 (* func_def)(s32, void*);
    u32 sp28;
    u32 sp24;
    DelayedCSData *current;
    s32 pad;

    sp3C = NULL;
    local = malloc(sizeof(DelayedCSData));
    sp28 = 0xC6F0AFA9;
    sp24 = 0x5FAFBA0C;
    func_def = func_global_asm_8060095C(((s32)osPiReadIo + 0xC000FF01), &sp28, &sp24);
    func_def(sp24, &sp30);
    if (sp30 != sp28) {
        time_delta *= 2;
    }
    local->function = func;
    local->args[0] = arg2;
    local->args[1] = arg3;
    local->args[2] = arg4;
    local->action_frame = time_delta + D_global_asm_8076A068[0];
    local->next = NULL;
    current = D_global_asm_807452A0;
    if (current) {
        next = current->next;
        if (next) {
            temp_a0 = local->action_frame & 0x7FFFFFFF;
            if (temp_a0 >= (u32) (current->action_frame & 0x7FFFFFFF)) {
loop_5:
                sp3C = current;
                current = next;
                next = next->next;
                if (next) {
                    if (temp_a0 >= (current->action_frame & 0x7FFFFFFF)) {
                        goto loop_5;
                    }
                }
            }
        }
        if ((local->action_frame & 0x7FFFFFFF) < (u32) (current->action_frame & 0x7FFFFFFF)) {
            local->next = current;
            if (sp3C) {
                sp3C->next = local;
            } else {
                D_global_asm_807452A0 = local;
            }
        } else {
            current->next = local;
        }
    } else {
        D_global_asm_807452A0 = local;
    }
}

void func_global_asm_80600B10(void) {
    s32 var_s1;
    DelayedCSData *var_s0;

    var_s0 = D_global_asm_807452A0;
    var_s1 = 0;
    while (var_s0 != NULL && !var_s1) {
        if (D_global_asm_8076A068[0] >= (var_s0->action_frame & 0x7FFFFFFF)) {
            var_s0->function(var_s0->args[0], var_s0->args[1], var_s0->args[2]);
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
        if ((var_s0->action_frame & 0x7FFFFFFF) < D_global_asm_8076A068[0]) {
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
