#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80732F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733C34.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80735624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80735864.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
} Struct80735958_unk18;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    Struct80735958_unk18* unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} Struct80735958;

void func_global_asm_80735958(ALCSPlayer *seqp, f32 tempo) {
    // __setUsptFromTempo
    if (seqp->target) {
        seqp->uspt = ((f32)tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 0x1E8;
    }
}