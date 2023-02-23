#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_14CF0/func_8060FFF0.s")

/*
extern ? D_80741F40;
extern ? D_807432D0;
extern ? D_80760840;
extern ? D_80760C60;
extern ? D_807F0570;
extern ? D_807F0588;

void func_8060FFF0(void) {
    D_807F0570.unk0 = &D_807432D0;
    D_807F0588.unk0 = &D_80760C60;
    D_807F0570.unk4 = &D_80741F40;
    D_807F0588.unk4 = &D_80760840;
    D_807F0570.unk8 = &D_80741F40;
    D_807F0588.unk8 = &D_80760840;
    D_807F0570.unkC = &D_80741F40;
    D_807F0588.unkC = &D_80760840;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_14CF0/func_80610044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_14CF0/func_80610268.s")

/*
extern OSMesgQueue D_807659E8;
extern s8 D_80746834;
extern s8 D_807F059C;

// TODO: Everything matches except for a bne where s1 and t8 are swapped, no idea why
void func_80610268(s32 arg0) {
    u32 sp34;

    do {
        D_80746834 = 8;
        osRecvMesg(&D_807659E8, &sp34, 1);
        D_80746834 = 0;
        (&D_807F059C)[sp34 >> 0x10] = 0;
        sp34 = (u16)sp34;
    } while (sp34 != arg0);
}
*/