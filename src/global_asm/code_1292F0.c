#include <ultra64.h>
#include "functions.h"

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1292F0/func_global_asm_807245F0.s")

void func_global_asm_80724874(Actor *arg0) {
    if (arg0->unk118 != NULL) {
        free(arg0->unk118);
        arg0->unk118 = NULL;
    }
}
