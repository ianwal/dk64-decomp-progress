#include <ultra64.h>
#include "functions.h"

extern OSContStatus D_807ECCD0;
extern void *D_807ECCE0;
extern OSMesgQueue D_807ECCF0;
extern s8 D_807ECD08;
extern u8 D_807ECD09;
extern u8 D_807ECD10;
extern u8 D_807ECD28;
extern void *D_807ECDE8;
extern void *D_807ECDF4;

u8 func_8060A900(void) {
    osCreateMesgQueue(&D_807ECCF0, &D_807ECCE0, 4);
    osSetEventMesg(5, &D_807ECCF0, NULL);
    osContInit(&D_807ECCF0, &D_807ECD09, &D_807ECCD0);
    func_80007360(4);
    if (!(D_807ECD09 & 1)) {
        D_807ECD09 = 0;
    }
    D_807ECD08 = 0;
    D_807ECDE8 = &D_807ECD10;
    D_807ECDF4 = &D_807ECD28;
    func_8060AA58(0xFF);
    func_8060E958();
    return D_807ECD09;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_8060A9BC.s")

extern u8 D_807467C4; // should_poll_input

/*
// TODO: Hmm, might need complete segment defintions for this file for this to match
void func_8060A9BC(void) {
    func_8060AA04();
    if (!D_807467C4) {
        D_807ECD08 = 1;
        func_800073D0(&D_807ECCF0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_8060AA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_8060AA58.s")

extern u8 D_807ECDFC[];

u8 func_8060AB38(s32 arg0) {
    return D_807ECDFC[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_8060AB48.s")

extern u8 D_807ECDF8;

u8 func_8060AC28(void) {
    return D_807ECDF8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_8060AC34.s")

void func_80007454(GlobalASMStruct12*); // Probably some libultra stuff related to PI/Controller

/*
// TODO: They're using some stack, we're not, not sure why
void func_8060AC34(GlobalASMStruct12* arg0) {
    if ((D_807467C4 == 0) && (D_807ECD08 != 0)) {
        func_80007454(arg0); // subdrag hook function
    }
    D_807ECD08 = 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_8060AC7C.s")

void func_8060B110(Struct807ECD58 *arg0) {
    D_807ECD58.unk0 = arg0->unk0;
    D_807ECD58.unk2 = arg0->unk2;
    D_807ECD58.unk3 = arg0->unk3;
}
