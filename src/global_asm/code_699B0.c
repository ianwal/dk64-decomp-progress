#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Temp20Big;

extern Temp20Big D_global_asm_80748BA0[];
extern s8 D_global_asm_807F9440[];
extern s32 D_global_asm_807F9448;

void func_global_asm_80664CB0(s16 arg0) {
    s32 i;
    s32 max = 0xD;

    D_global_asm_807F9448 = 0;
    for (i = 0; i < max; i++) {
        if (arg0 == D_global_asm_80748BA0[i].unk0) {
            if (D_global_asm_807F9448 != 8) {
                D_global_asm_807F9440[D_global_asm_807F9448] = i;
                D_global_asm_807F9448++;
            }
        }
    }
}

// doable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_699B0/func_global_asm_80664D20.s")
