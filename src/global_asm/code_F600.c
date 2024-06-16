#include <ultra64.h>
#include "functions.h"

extern s8 D_global_asm_80746834;

extern OSContStatus D_global_asm_807ECCD0;
extern void *D_global_asm_807ECCE0;
extern OSMesgQueue D_global_asm_807ECCF0;
extern u8 D_global_asm_807ECD08;
extern u8 D_global_asm_807ECD09;
extern u8 D_global_asm_807ECD10;
extern u8 D_global_asm_807ECD28;
extern void *D_global_asm_807ECDE8;
extern void *D_global_asm_807ECDF4;

u8 func_global_asm_8060A900(void) {
    osCreateMesgQueue(&D_global_asm_807ECCF0, &D_global_asm_807ECCE0, 4);
    osSetEventMesg(5, &D_global_asm_807ECCF0, NULL);
    osContInit(&D_global_asm_807ECCF0, &D_global_asm_807ECD09, &D_global_asm_807ECCD0);
    func_dk64_boot_80007360(4);
    if (!(D_global_asm_807ECD09 & 1)) {
        D_global_asm_807ECD09 = 0;
    }
    D_global_asm_807ECD08 = 0;
    D_global_asm_807ECDE8 = &D_global_asm_807ECD10;
    D_global_asm_807ECDF4 = &D_global_asm_807ECD28;
    func_global_asm_8060AA58(0xFF);
    func_global_asm_8060E958();
    return D_global_asm_807ECD09;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060A9BC.s")

extern u8 D_global_asm_807467C4; // should_poll_input

/*
// TODO: Hmm, might need complete segment defintions for this file for this to match
void func_global_asm_8060A9BC(void) {
    func_global_asm_8060AA04();
    if (!(D_global_asm_807467C4 & 0xFF)) {
        D_global_asm_807ECD08 = 1;
        func_dk64_boot_800073D0(&D_global_asm_807ECCF0);
    }
}
*/

void func_global_asm_8060AA04(void) {
    if (D_global_asm_807ECD08 != 0) {
        D_global_asm_80746834 = 2;
        osRecvMesg(&D_global_asm_807ECCF0, NULL, 1);
        D_global_asm_80746834 = 0;
        D_global_asm_807ECD08 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AA58.s")

extern u8 D_global_asm_807ECDFC[];

u8 func_global_asm_8060AB38(s32 arg0) {
    return D_global_asm_807ECDFC[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AB48.s")

extern u8 D_global_asm_807ECDF8;

u8 func_global_asm_8060AC28(void) {
    return D_global_asm_807ECDF8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AC34.s")

/*
// TODO: They're using some stack, we're not, not sure why
void func_global_asm_8060AC34(OSContPad* arg0) {
    if ((D_global_asm_807467C4 == 0) && (D_global_asm_807ECD08 != 0)) {
        func_dk64_boot_80007454(arg0); // subdrag hook function
    }
    D_global_asm_807ECD08 = 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AC7C.s")

void func_global_asm_8060B110(Struct807ECD58 *arg0) {
    D_global_asm_807ECD58.unk0 = arg0->unk0;
    D_global_asm_807ECD58.unk2 = arg0->unk2;
    D_global_asm_807ECD58.unk3 = arg0->unk3;
}
