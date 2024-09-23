#include <ultra64.h>
#include "functions.h"
#include "synthinternal.h"

ALParam *__n_allocParam();
s32 func_global_asm_8073F1E4(Struct8073F1E4 *, s32, ALParam *);

void func_global_asm_8073CF00(Struct8073F1E4_container *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->unk8 != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + arg0->unk8->unk88;
        sp1C->type = 0xC;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->unk8, 3, sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141C00/func_global_asm_8073CFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141C00/func_global_asm_8073D060.s")
