#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x84 - 0x0];
    s32 unk84;
} Struct80737E90;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Struct80737EA4_unk20_unkC;

// TODO: WTF?
typedef struct {
    union {
        s16 unk0[2];
        Struct80737EA4_unk20_unkC *unkC;
    };
} Struct80737EA4_unk20;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    Struct80737EA4_unk20 *unk20;
} Struct80737EA4;

typedef struct {
    u8 unk0[0xD - 0x0];
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11[0x34 - 0x11];
} Struct80737F0C_unk60;

typedef struct {
    u8 unk0[0x30 - 0x0];
    u16 unk30;
    u16 unk32;
    u8 unk34;
    u8 unk38[0x60 - 0x35];
    Struct80737F0C_unk60 *unk60;  
} Struct80737F0C;

void func_global_asm_80737E50(ALSeqPlayer* arg0) {
    ALEvent sp18;

    sp18.type = AL_SEQP_PLAY_EVT;
    alEvtqPostEvent(&arg0->evtq, &sp18, 0);
}

void func_global_asm_80737E90(Struct80737E90 *arg0, s32 arg1) {
    arg0->unk84 = arg1;
}

void func_global_asm_80737EA4(Struct80737EA4 *arg0, u8 arg1, u8 arg2) {
    Struct80737EA4_unk20_unkC *sp4;

    if (arg1 < arg0->unk20[0].unk0[0]) { // TODO: Wtf?
        sp4 = arg0->unk20[arg1 + 3].unkC; // TODO: Wtf?
        if (sp4 != NULL) {
            sp4->unk3 = (arg2 * 2) | (sp4->unk3 & 1);
        }
    }
}

void func_global_asm_80737F0C(Struct80737F0C *arg0, s32 arg1, u8 arg2) {
    arg0->unk60[arg1].unk10 = arg2;
}

void func_global_asm_80737F40(Struct80737F0C *arg0) {
    s32 i;

    arg0->unk30 = 0xFFFF;
    for (i = 0; i < arg0->unk34; i++) {
        arg0->unk60[i].unkE = 0xFF;
        arg0->unk60[i].unkD = 0xFF;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13CB50/func_global_asm_80737FD8.s")

/*
void func_global_asm_80737FD8(ALSeqPlayer *arg0, s32 arg1) {
    func_global_asm_807382A0(arg0, 0, arg1 | 0xB0, 0xFF, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13CB50/func_global_asm_8073801C.s")

/*
void func_global_asm_8073801C(ALSeqPlayer *arg0, s32 arg1) {
    arg0->chanMask |= 1 << arg1;
    func_global_asm_807382A0(arg0, 0, arg1 | 0xB0, 0xFF, 0xFF);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13CB50/func_global_asm_80738080.s")

/*
void func_global_asm_80738080(ALSeqPlayer *arg0, s32 arg1, u8 arg2) {
    func_global_asm_807382A0(arg0, 0, arg1 | 0xB0, 0xFF, arg2);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13CB50/func_global_asm_807380CC.s")

/*
void func_global_asm_807380CC(ALSeqPlayer *arg0, s32 arg1, u8 arg2) {
    func_global_asm_807382A0(arg0, 0, arg1 | 0xB0, 0x41, arg2);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13CB50/func_global_asm_80738118.s")

/*
void func_global_asm_80738118(ALSeqPlayer *arg0, s32 arg1, u8 arg2) {
    func_global_asm_807382A0(arg0, 0, arg1 | 0xB0, 0xFC, arg2);
}
*/

