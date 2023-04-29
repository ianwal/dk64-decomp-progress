#include <ultra64.h>
#include "functions.h"

// This file manages the heap

typedef struct HeapHeader HeapHeader;

struct HeapHeader {
    HeapHeader *prev;
    s32 size; // Used
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB; // Used
    s32 unkC;
};

typedef struct {
    s32 unk0; // Used
    s8 unk4; // Used
    s8 unk5;
    s8 unk6;
    s8 unk7;
} Struct807F0A58;

extern s32 D_80746A30;
extern u8 D_80746A37;
extern Struct807F0A58 D_807F0A58[];
extern s32 D_807F5A58;
extern s32 D_807F5A5C;
extern HeapHeader *D_807F5A64;
extern s32 D_807F5A68;
extern s32 D_807F5A70[]; // TODO: Datatype is sus
extern HeapHeader *D_807F0990;
extern s32 D_807F5A68;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806109EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610A88.s")

// TODO: Datatypes are sus
void func_80610B84(s32 arg0, s32 arg1, u32 arg2) {
    s32 temp_v0;
    s32 i;

    for (i = 0; i < D_807F5A68; i++) {
        temp_v0 = D_807F5A70[i] - arg0;
        if ((temp_v0 >= 0) && (temp_v0 < arg2)) {
            D_807F5A70[i] = temp_v0 + arg1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/malloc.s")

u8 func_80611154(void) {
    return D_80746A37;
}

void func_80611160(void) {
    D_80746A30 = 0;
}

void func_8061116C(void) {
    func_8065EA44();
}

s32 func_8061118C(void) {
    s32 size;
    HeapHeader *var_v0;

    var_v0 = D_807F0990;
    size = 0;
    while (var_v0 != NULL) {
        size += var_v0->size + sizeof(HeapHeader);
        // TODO: WTF, union in the HeapHeader struct maybe?
        var_v0 = *((u32*)&var_v0->unk8);
    }
    return size;
}

s32 func_806111BC(s32 arg0, s32 arg1) {
    s32 temp_v0 = func_806111F8(arg0, (arg1 + 0xF) & ~0xF);
    if (temp_v0) {
        temp_v0 += 0x10;
        return temp_v0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806111F8.s")

void func_8061130C(HeapHeader *arg0) {
    // TODO: Oof, I don't like the second condition there but it does match...
    if ((arg0 != D_807F5A64) && ((--arg0)->unkB == 0)) {
        func_80611408(arg0);
    }
}

void func_8061134C(HeapHeader *arg0) {
    // TODO: Oof, I don't like the second condition there but it does match...
    if ((arg0 != D_807F5A64) && ((--arg0)->unkB == 0)) {
        func_8061138C(arg0);
    }
}

void func_8061138C(s32 arg0) {
    while (D_807F5A58 >= 0xA00) {
        func_80611730();
    }
    D_807F0A58[D_807F5A58].unk0 = arg0;
    D_807F0A58[D_807F5A58].unk4 = D_807F5A5C;
    D_807F5A58++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611408.s")

// Looks fiddly... hmm
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611534.s")

void func_80611594(HeapHeader *arg0) {
    arg0[-1].unkB = 0;
}

void func_8061159C(HeapHeader *arg0) {
    arg0[-1].unkB = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806115A8.s")

/*
// TODO: Close, might only have 1 param
void func_806115A8(HeapHeader **arg0, HeapHeader *arg1) {
    arg1 = &(*arg0)[-1];
    arg1->unkB = 2;
    D_807F5A70[D_807F5A68++] = arg1;
    if (D_807F5A68 == 0x20) {
        func_80732354(0xD, 0, 0, 0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611614.s")

extern s32 D_807F5A68;

/*
// TODO: Regalloc, datatypes are sus
void func_80611614(HeapHeader **arg0) {
    s32 temp_t7;
    s32 i;
    HeapHeader *temp;

    temp = *arg0 - 1;
    temp->unkB = 0;
    temp_t7 = D_807F5A68 - 1;
    for (i = 0; i < D_807F5A68; i++) {
        if (temp == D_807F5A70[i]) {
            break;
        }
    }
    D_807F5A70[i] = D_807F5A70[temp_t7];
    D_807F5A68 = temp_t7;
    D_807F5A70[temp_t7] = 0;
}
*/

s32 func_80611688(HeapHeader *arg0) {
    return arg0[-1].size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611690.s")

/*
// TODO: Close
void func_80611690(HeapHeader *arg0) {
    u32 *var_v0;
    u16 var_v1;

    var_v0 = arg0;
    var_v1 = arg0[-1].size / 8U;
    while (var_v1--) {
        var_v0[0] = 0;
        var_v0[1] = 0;
        var_v0 += 2;
    }
}
*/

// Appears to be a memset implementation
void func_806116E0(HeapHeader *arg0, s32 arg1) {
    s32 *var_v0;
    u16 var_v1;

    var_v0 = arg0;
    var_v1 = arg0[-1].size / 4U;
    while (var_v1--) {
        *var_v0++ = arg1;
    }
}

void func_80611724(s32 arg0, s32 arg1) {

}

// TODO: Blursed, maybe anti piracy?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611730.s")

void func_80611844(void) {

}
