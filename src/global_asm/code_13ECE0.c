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
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s8 unk24;
    s8 unk25;
    s8 unk26;
    s8 unk27;
    s8 unk28;
    s8 unk29;
    s8 unk2A;
    s8 unk2B;
    s8 unk2C;
    s8 unk2D;
    s8 unk2E;
    s8 unk2F;
    s8 unk30;
    s8 unk31;
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

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
} Struct8073AD50_arg1_unk10_unk0;

typedef struct {
    Struct8073AD50_arg1_unk10_unk0 *unk0;
} Struct8073AD50_arg1_unk10;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s16 unkC;
    s16 unkE;
    Struct8073AD50_arg1_unk10 *unk10;
} Struct8073AD50_arg1;

void func_8073AD50(Struct8073AB00 *arg0, Struct8073AD50_arg1 *arg1, s32 arg2) {
    Struct8073AD50_arg1_unk10 *temp;
    arg0->unk60[arg2].unk0 = arg1;
    arg0->unk60[arg2].unk7 = arg1->unk1;
    arg0->unk60[arg2].unk9 = arg1->unk0;
    arg0->unk60[arg2].unk8 = arg1->unk2;
    arg0->unk60[arg2].unk4 = arg1->unkC;
    if (arg1->unkE == 0) {
        return;
    }
    temp = arg1->unk10;
    arg0->unk60[arg2].unk18 = temp->unk0->unk0;
    arg0->unk60[arg2].unk1C = temp->unk0->unk4;
    arg0->unk60[arg2].unk20 = temp->unk0->unk8;
    arg0->unk60[arg2].unk25 = temp->unk0->unkC;
    arg0->unk60[arg2].unk26 = temp->unk0->unkD;
    arg0->unk60[arg2].unk27 = 0;
    arg0->unk60[arg2].unk28 = arg1->unk4;
    arg0->unk60[arg2].unk29 = arg1->unk5;
    arg0->unk60[arg2].unk2A = arg1->unk6;
    arg0->unk60[arg2].unk2B = arg1->unk7;
    arg0->unk60[arg2].unk2C = arg1->unk8;
    arg0->unk60[arg2].unk2D = arg1->unk9;
    arg0->unk60[arg2].unk2E = arg1->unkA;
    arg0->unk60[arg2].unk2F = arg1->unkB;
    arg0->unk60[arg2].unk24 = 0;
    arg0->unk60[arg2].unk31 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_13ECE0/func_8073B08C.s")
