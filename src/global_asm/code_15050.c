#include <ultra64.h>
#include "functions.h"


// TODO: Hmmm, could this file be managing the heap?
// It would explain the negative struct offsets

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806109EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80610E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/malloc.s")

extern s32 D_80746A30;
extern u8 D_80746A37;

u8 func_80611154(void) {
    return D_80746A37;
}

void func_80611160(void) {
    D_80746A30 = 0;
}

void func_8061116C(void) {
    func_8065EA44();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_8061118C.s")

s32 func_806111BC(s32 arg0, s32 arg1) {
    s32 temp_v0 = func_806111F8(arg0, (arg1 + 0xF) & ~0xF);
    if (temp_v0) {
        temp_v0 += 0x10;
        return temp_v0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806111F8.s")

// Used in resolveActorCollisions(), param 1 appears to be the a pointer to the struct ActorCollision
// TODO: Also used in tons more places, not always with that struct
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_8061130C.s")

// Negative struct offset, odd
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_8061134C.s")

typedef struct {
    s32 unk0; // Used
    s8 unk4; // Used
    s8 unk5;
    s8 unk6;
    s8 unk7;
} Struct807F0A58;

// Also used in func_80611730
extern Struct807F0A58 D_807F0A58[];
extern s32 D_807F5A58;
extern s32 D_807F5A5C;

void func_8061138C(s32 arg0) {
    while (D_807F5A58 >= 0xA00) {
        func_80611730();
    }
    D_807F0A58[D_807F5A58].unk0 = arg0;
    D_807F0A58[D_807F5A58].unk4 = D_807F5A5C;
    D_807F5A58++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611534.s")

// TODO: idk if this is the best way to do this
void func_80611594(u8 *arg0) {
    arg0[-5] = 0;
}

// TODO: idk if this is the best way to do this
void func_8061159C(u8 *arg0) {
    arg0[-5] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806115A8.s")

/*
extern s32 D_807F5A68;
extern void* D_807F5A70[];

void func_806115A8(u8 *arg0) {
    arg0[-5] = 2;
    D_807F5A70[D_807F5A68++] = arg0;
    if (D_807F5A68 == 0x20) {
        func_80732354(0xD, 0, 0, 0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611614.s")

// TODO: idk if this is the best way to do this
s32 func_80611688(s32 *arg0) {
    return arg0[-3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_806116E0.s")

void func_80611724(s32 arg0, s32 arg1) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_15050/func_80611730.s")

void func_80611844(void) {

}
