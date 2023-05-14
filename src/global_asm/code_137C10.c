#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80732F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80733180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80733A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80733B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80733C34.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80733D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80735624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80735864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_80735958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_137C10/func_807359A0.s")

typedef struct {
    u8 unk0[0x88 - 0x0];
    u8 unk88;
} Struct80735A34;

void func_80735A34(Struct80735A34 *arg0, u8 arg1) {
    arg0->unk88 = arg1;
}
