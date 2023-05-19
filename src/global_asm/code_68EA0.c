#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806641A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806643C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_806644B0.s")

extern s16 D_807F9434;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct807F9430;

extern Struct807F9430 *D_807F9430;

void func_806645B8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_807F9434; i++) {
        if (arg0 == D_807F9430[i].unkA) {
            D_807F9430[i].unkA = -1;
        }
    }
}

s32 func_8066461C(s16 arg0) {
    switch (arg0) {
        case 1: // Thin Flame? (2D)
        case 0x10: // Flame (2D)
        case 0x74: // Golden Banana
        case 0xF3: // Torch
        case 0x138: // Torch
        case 0x288: // Rareware GB
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_8066466C.s")

extern s32 D_807213D0; // TODO: Datatype
extern f32 D_80758E18;
extern f32 D_80758E1C;

void func_80717DB4(void);

void func_80664834(s16 arg0) {
    if (((rand() % 10000) % 12) == 0) {
        func_807149B8(1);
        func_80714998(7);
        func_80714950(((rand() % 10000) % 50) - 0x78);
        func_8071498C(&func_80717DB4);
        func_807149C8(0xFF, 0xC8, 0xC8, 0xC8);
        func_80714A08(D_80758E18, D_80758E1C);
        func_80714A28(4);
        func_80714CC0(
            &D_807213D0,
            0.0f,
            (D_807F9430[arg0].unk2 + (((rand() % 10000) % 100) / 20.0)) - 2.5,
            D_807F9430[arg0].unk4 + 4.0,
            (D_807F9430[arg0].unk6 + (((rand() % 10000) % 100) / 20.0)) - 2.5
        );
    }
}

extern s32 D_80720A7C; // TODO: Datatype

void func_80664A38(s16 arg0) {
    f32 sp34;

    if (((rand() % 10000) % 10) == 0) {
        sp34 = D_807F9430[arg0].unk8 / 25.0;
        func_807149B8(1);
        func_80714998(2);
        func_80714A28(4);
        func_80714CC0(
            &D_80720A7C,
            0.4f,
            D_807F9430[arg0].unk2 + (((((rand() % 10000) % 300) / 20.0) - 7.5) * sp34),
            D_807F9430[arg0].unk4 + ((((rand() % 10000) % 600) / 20.0) * sp34),
            D_807F9430[arg0].unk6 + (((((rand() % 10000) % 300) / 20.0) - 7.5) * sp34)
        );
    }
}
