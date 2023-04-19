#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064F450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064F6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064F6F8.s")

typedef struct {
    s32 unk0;
    s32 unk4;
} GlobalASMStruct9;

void func_80650684(GlobalASMStruct9*);
//display list struct ? idk
void func_8064F804(GlobalASMStruct9 *arg0) {
    if (arg0) {
        func_8061134C(arg0->unk0);
        func_8061134C(arg0->unk4);
        func_80650684(arg0);
        func_8061130C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064F84C.s")

void func_8064F954(s32 arg0) {
    func_806500E0();
    func_8064F97C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064F97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064FA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8064FB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_806500E0.s")

typedef struct {
    GlobalASMStruct9* unk0; // Used
    void *unk4; // TODO: Which struct?
    void *unk8; // TODO: Which struct?
    u8 unkC; // Used
    s8 unkD;
    s8 unkE;
    s8 unkF;
} GlobalASMStruct10;

extern GlobalASMStruct10 D_807F6960[];
extern u8 D_807444FC;
extern s8 D_807F6BEC;

void func_8065051C(void) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        D_807F6960[i].unk0 = NULL;
    }
}

void func_8065054C(GlobalASMStruct9 *arg0, void *arg1, void *arg2) {
    s32 found = FALSE;
    s32 i = 0;

    while (!found && i < 0x28) {
        if (!D_807F6960[i].unk0) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (found) {
        D_807F6960[i].unk0 = arg0;
        D_807F6960[i].unk4 = arg1;
        D_807F6960[i].unk8 = arg2;
        D_807F6960[i].unkC = D_807444FC ^ 1;
    } else {
        func_80732354(0xB, 0, 0, 0);
    }
}

void func_806505F0(GlobalASMStruct9 *arg0) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (D_807F6960[i].unk0 && arg0 == D_807F6960[i].unk8) {
            D_807F6960[i].unk0 = NULL;
        }
    }
}

void func_80650684(GlobalASMStruct9 *arg0) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (arg0 == D_807F6960[i].unk0) {
            D_807F6960[i].unk0 = NULL;
        }
    }
}

void func_806506E8(GlobalASMStruct9 *arg0) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        if (arg0 == D_807F6960[i].unk0 && D_807F6960[i].unkC == D_807444FC) {
            // TODO: Sizeof which struct?
            memcpy(D_807F6960[i].unk8, D_807F6960[i].unk4, 0x40);
            D_807F6960[i].unk0 = NULL;
            D_807F6BEC = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_806508B4.s")

// Doable, needs ObjectModel2 -> 0x78 defined
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_8065092C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650B50.s")

// Doable, needs ObjectModel2 -> 0x78 defined
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_54150/func_80650D8C.s")
