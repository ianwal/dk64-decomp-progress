#include <ultra64.h>
#include "functions.h"


// Hmm, possibly audio stuff?

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_80739FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A7B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073A98C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073AA74.s")

typedef struct {
    s32 unk0;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    u8 unk18[0x32 - 0x18];
    s8 unk32;
    s8 unk33;
} Struct8073AB00_unk60;

typedef struct {
    u8 unk0[0x60 - 0x0];
    Struct8073AB00_unk60 *unk60;
} Struct8073AB00;

void func_8073AB00(Struct8073AB00 *arg0, s32 arg1) {
    arg0->unk60[arg1].unk6 = 0;
    arg0->unk60[arg1].unkA = 0;
    arg0->unk60[arg1].unk7 = 0x40;
    arg0->unk60[arg1].unk9 = 0x7F;
    arg0->unk60[arg1].unk8 = 5;
    arg0->unk60[arg1].unkC = 0;
    arg0->unk60[arg1].unk4 = 0xC8;
    arg0->unk60[arg1].unk14 = 1.0f;
    arg0->unk60[arg1].unk10 = 0;
    arg0->unk60[arg1].unkD = 0xFF;
    arg0->unk60[arg1].unkE = 0xFF;
    arg0->unk60[arg1].unkF = 0;
    arg0->unk60[arg1].unkB = 0;
    arg0->unk60[arg1].unk13 = 0;
    arg0->unk60[arg1].unk12 = 0;
    arg0->unk60[arg1].unk11 = 0;
    arg0->unk60[arg1].unk32 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073AD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073B08C.s")
