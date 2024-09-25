#include <ultra64.h>
#include "functions.h"

void func_global_asm_8060FFF0(void) {
    D_global_asm_807F0570.unk0 = &D_global_asm_807432D0;
    D_global_asm_807F0588.unk0 = &D_global_asm_80760C60;
    D_global_asm_807F0570.unk4 = &D_global_asm_80741F40;
    D_global_asm_807F0588.unk4 = &D_global_asm_80760840;
    D_global_asm_807F0570.unk8 = &D_global_asm_80741F40;
    D_global_asm_807F0588.unk8 = &D_global_asm_80760840;
    D_global_asm_807F0570.unkC = &D_global_asm_80741F40;
    D_global_asm_807F0588.unkC = &D_global_asm_80760840;
}

// libultra stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_14CF0/func_global_asm_80610044.s")

extern OSMesgQueue D_global_asm_807659E8;
extern s8 D_global_asm_80746834;
extern s8 D_global_asm_807F059C;

void func_global_asm_80610268(s32 arg0) {
    u32 sp34;

    do {
        D_global_asm_80746834 = 8;
        osRecvMesg(&D_global_asm_807659E8, &sp34, 1);
        D_global_asm_80746834 = 0;
        (&D_global_asm_807F059C)[sp34 >> 0x10] = 0;
        sp34 &= 0xFFFF;
    } while ((s32)sp34 != arg0);
}
