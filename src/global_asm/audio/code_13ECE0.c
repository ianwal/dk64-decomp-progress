#include <ultra64.h>
#include "functions.h"

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
    u8 unk0[0x30 - 0x0];
    u8 unk30;
    u8 unk31;
    s16 unk32;
    u8 unk34;
    u8 unk35[0x60 - 0x35];
    Struct8073AB00_unk60 *unk60;
    u8 unk64[0x7C - 0x64];
    f32 unk7C;
    f32 unk80;
} Struct8073AB00;

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

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Struct8073AD50_arg1 *unkC[1]; // TODO: How many elements
} Struct8073A98C_arg1;

void func_global_asm_8073AB00(Struct8073AB00 *arg0, s32 arg1);
void func_global_asm_8073AD50(Struct8073AB00 *arg0, Struct8073AD50_arg1 *arg1, s32 arg2);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
} Struct8073A900_arg0_unk20;

typedef struct {
    u8 unk0[0x20 - 0x0];
    Struct8073A900_arg0_unk20 *unk20;
    u8 unk24[0x30 - 0x24];
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
} Struct8073A900_arg0;

typedef struct {
    u8 unk0[0x24 - 0x0];
    s32 unk24;
} Struct8073A8BC;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_80739FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A518.s")

s16 func_global_asm_8073A690(Struct8073A900_arg0 *arg0, Struct8073AB00 *arg1) {
    u32 sp4;
    u32 sp0;

    sp4 = (arg0->unk36 * arg0->unk33 * arg0->unk30) >> 6;
    sp0 = (arg1->unk60[arg0->unk31].unk9 * (arg0->unk20->unkD * arg1->unk32)) >> 0xE;
    if (arg1->unk60[arg0->unk31].unkD != 0xFF) {
        sp0 = ((arg1->unk60[arg0->unk31].unkD * sp0) + 1) >> 8;
    }
    sp4 *= sp0;
    sp4 = sp4 >> 0xF;
    return sp4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073A7B8.s")

/*
// TODO: Extremely close
u8 func_global_asm_8073A7B8(Struct8073A900_arg0 *arg0, Struct8073AB00 *arg1) {
    s32 sp14;
    s32 sp10;

    sp14 = arg1->unk60[arg0->unk31].unkA & 0x80;
    sp10 = ((arg1->unk60[arg0->unk31].unkA & 0x7F) + (s32)(arg1->unk7C * 127.0f)) * arg1->unk80;
    return (MAX(0, MIN(0x7F, sp10)) | sp14);
}
*/

s32 func_global_asm_8073A8BC(Struct8073A8BC *arg0, s32 arg1) {
    s32 sp4;

    sp4 = arg0->unk24 - arg1;
    if (sp4 >= 0) {
        return sp4;
    } else {
        return 1000;
    }
}

u8 func_global_asm_8073A900(Struct8073A900_arg0 *arg0, Struct8073AB00 *arg1) {
    s32 sp4;

    sp4 = (arg1->unk60[arg0->unk31].unk7 + arg0->unk20->unkC) - 0x40;
    if (sp4 > 0) {

    } else {
        sp4 = 0;
    }
    if (sp4 < 0x7F) {

    } else {
        sp4 = 0x7F;
    }
    return sp4;
}


void func_global_asm_8073A98C(Struct8073AB00 *arg0, Struct8073A98C_arg1 *arg1) {
    s32 i;
    Struct8073AD50_arg1 *sp18;

    sp18 = NULL;
    for (i = 0; sp18 == NULL; i++) {
        sp18 = arg1->unkC[i];
    }
    for (i = 0; i < arg0->unk34; i++) {
        func_global_asm_8073AB00(arg0, i);
        func_global_asm_8073AD50(arg0, sp18, i);
    }
    if (arg1->unk8 != 0) {
        func_global_asm_8073AB00(arg0, i);
        func_global_asm_8073AD50(arg0, arg1->unk8, 9);
    }
}

void func_global_asm_8073AA74(Struct8073AB00 *arg0) {
    s32 i;

    for (i = 0; i < arg0->unk34; i++) {
        arg0->unk60[i].unk0 = 0;
        func_global_asm_8073AB00(arg0, i);
    }
}

void func_global_asm_8073AB00(Struct8073AB00 *arg0, s32 arg1) {
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

void func_global_asm_8073AD50(Struct8073AB00 *arg0, Struct8073AD50_arg1 *arg1, s32 arg2) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13ECE0/func_global_asm_8073B08C.s")
