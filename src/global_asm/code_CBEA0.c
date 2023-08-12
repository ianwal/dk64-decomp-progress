#include <ultra64.h>
#include "functions.h"


void func_global_asm_806C71A0(void) {

}

void func_global_asm_806C71A8(void) {

}

void func_global_asm_806C71B0(void) {

}

void func_global_asm_806C71B8(void) {

}

void func_global_asm_806C71C0(void) {

}

void func_global_asm_806C71C8(void) {

}

void func_global_asm_806C71D0(void) {

}

void func_global_asm_806C71D8(void) {

}

void func_global_asm_806C71E0(void) {

}

void func_global_asm_806C71E8(void) {

}

void func_global_asm_806C71F0(void) {

}

void func_global_asm_806C71F8(void) {

}

void func_global_asm_806C7200(void) {

}

void func_global_asm_806C7208(void) {

}

void func_global_asm_806C7210(void) {

}

void func_global_asm_806C7218(void) {

}

void func_global_asm_806C7220(void) {

}

void func_global_asm_806C7228(void) {

}

void func_global_asm_806C7230(void) {

}

void func_global_asm_806C7238(void) {

}

void func_global_asm_806C7240(void) {

}

void func_global_asm_806C7248(void) {

}

void func_global_asm_806C7250(void) {

}

void func_global_asm_806C7258(void) {

}

void func_global_asm_806C7260(void) {

}

void func_global_asm_806C7268(void) {

}

// stack, float, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CBEA0/func_global_asm_806C7270.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4;
    s8 unk5;
} Struct807506D0;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct8075075C;

extern Struct807506D0 D_global_asm_807506D0[];
extern s8 D_global_asm_80750754;
extern s16 D_global_asm_80750758;
extern Struct8075075C D_global_asm_8075075C[];

extern f32 D_global_asm_8075C3E0;
extern s16 D_global_asm_807FC8E0;
extern s16 D_global_asm_807FC8E2;
extern s16 D_global_asm_807FC8E4;
extern f32 D_global_asm_807FC8E8;
extern f32 D_global_asm_807FC8EC;
extern u8 *D_global_asm_807FC8F0;
extern void func_global_asm_806C75A4(); // TODO: Signature

/*
void func_global_asm_806C7270(void) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    s32 temp_t9;
    s32 temp_v1;
    s32 var_v1;
    u8 var_a0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FC8F0 = getPointerTableFile(0x13, 7, 1, 1);
        D_global_asm_807FC8E0 = 0;
        var_v1 = 0;
        while (D_global_asm_807FC8F0[var_v1] != 0x2A) {
            if (D_global_asm_807FC8F0[var_v1] == 0xA) {
                D_global_asm_807FC8F0[var_v1] = 0;
                D_global_asm_807FC8E0 += 1;
            }
            var_v1 += 1;
        }
        if (D_global_asm_80750754 == -2) {
            D_global_asm_807FC8E4 = 0x320;
            D_global_asm_80750754 = -1;
            D_global_asm_807FC8E2 = 0;
            D_global_asm_807FC8E8 = 0;
        } else if (D_global_asm_80750754 == -1) {
            D_global_asm_807FC8E4 = 0x3C;
            D_global_asm_807FC8E2 = 0;
            D_global_asm_807FC8E8 = 0;
        }
    }
    if (D_global_asm_807FC8E2 > 0) {
        D_global_asm_807FC8E2 -= 1;
    }
    if (D_global_asm_807FC8E2 == 0) {
        D_global_asm_807FC8E2 = 0;
        D_global_asm_807FC8E4 -= 1;
        if (D_global_asm_807FC8E4 <= 0) {
            if (D_global_asm_80750754 >= 0) {
                D_global_asm_80750758 += D_global_asm_807506D0[D_global_asm_80750754].unk5;
            }
            if (D_global_asm_80750758 >= D_global_asm_807FC8E0) {
                D_global_asm_80750758 = 0;
            }
            D_global_asm_80750754 += 1;
            D_global_asm_807FC8E2 = D_global_asm_807506D0[D_global_asm_80750754].unk0;
            D_global_asm_807FC8E4 = D_global_asm_807506D0[D_global_asm_80750754].unk2;
        }
    }
    if (D_global_asm_807FC8E2 < 0xB) {
        D_global_asm_807FC8E8 -= D_global_asm_8075C3E0;
        if (D_global_asm_807FC8E8 < 0.0f) {
            D_global_asm_807FC8E8 = 0;
        }
        D_global_asm_807FC8EC = 1.0f;
    } else {
        temp_v1 = D_global_asm_807506D0[D_global_asm_80750754].unk0 - D_global_asm_807FC8E2;
        temp_t9 = temp_v1 >> 1;
        if (temp_t9 < 0x16) {
            temp_f2 = D_global_asm_8075075C[temp_t9].unk0;
            temp_f12 = D_global_asm_8075075C[temp_t9].unk4;
            temp_f0 = (temp_v1 & 1) / 2.0;
            D_global_asm_807FC8E8 = ((D_global_asm_8075075C[temp_t9].unk8 - temp_f2) * temp_f0) + temp_f2;
            D_global_asm_807FC8EC = ((D_global_asm_8075075C[temp_t9].unkC - temp_f12) * temp_f0) + temp_f12;
        } else {
            D_global_asm_807FC8E8 = 1.0f;
            D_global_asm_807FC8EC = 1.0f;
        }
    }
    func_global_asm_8068C350(&func_global_asm_806C75A4, current_actor_pointer, 3);
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CBEA0/func_global_asm_806C75A4.s")
