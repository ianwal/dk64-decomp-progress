#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
s32 func_global_asm_8073F1E4(Struct8073F1E4 *, s32, ALParam *);

void func_global_asm_8073C820(Struct8073F1E4_container *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->unk8 != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + arg0->unk8->unk88;
        sp1C->type = 0x10;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->unk8, 3, sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141520/func_global_asm_8073C8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141520/func_global_asm_8073C948.s")

s32 func_global_asm_8073DA30(s32, s16, s32);

void func_global_asm_8073C9C0(s32 arg0, s16 arg1, s32 arg2) {
    s32 sp1C;

    sp1C = arg0;
    func_global_asm_8073DA30(sp1C, arg1, arg2);
}

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct8073CA04_arg0;

void func_global_asm_8073CA04(Struct8073CA04_arg0 *arg0, s16 arg1, s32 *arg2) {
    if (arg1 == 8) {
        arg0->unk2 = *arg2 * 0.1f;
    } else if (arg1 == 9) {
        arg0->unk0 = *arg2;
    }
    func_global_asm_8073BE54(arg0, n_syn->outputRate);
}
