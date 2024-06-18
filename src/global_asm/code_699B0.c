#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_80748E00;
extern u8 D_global_asm_80748E04;
extern void *D_global_asm_80748E14; // TODO: Datatype
extern u8 D_global_asm_80748E18[];

extern f64 D_global_asm_80758F08;

extern u8 D_global_asm_807F951D;
extern f32 D_global_asm_807F9468;
extern u8 D_global_asm_807F946C;
extern u8 D_global_asm_807F946E;
extern f32 D_global_asm_807F9488;
extern f32 D_global_asm_807F948C;
extern s16 D_global_asm_807F9490[];
extern s16 D_global_asm_807F9498[];
extern s16 D_global_asm_807F94A2;
extern s16 D_global_asm_807F94A4;
extern u8 D_global_asm_807F94AA;
extern u8 D_global_asm_807F94AE;
extern u8 D_global_asm_807F94AF;
extern u8 D_global_asm_807F94B0;
extern u8 D_global_asm_807F94B1;
extern u8 D_global_asm_807F94B3;
extern u8 D_global_asm_807F94B4;
extern u8 D_global_asm_807F94B5;
extern u8 D_global_asm_807F94B7;
extern u8 D_global_asm_807F94BC;
extern u8 D_global_asm_807F9484;
extern u8 D_global_asm_807F9510;
extern s32 *D_global_asm_807F95A8[];
extern s32 D_global_asm_807F9678;
extern u8 D_global_asm_807F967C;
extern u8 D_global_asm_807F967D;

extern s32 *D_global_asm_807FB1A0[];

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
