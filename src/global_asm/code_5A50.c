#include <ultra64.h>
#include "functions.h"


extern s32 D_8000DDCC;
extern s32 D_8076D200;

void func_80737E50(ALSeqPlayer*);
void func_80737F0C(s32, s32, u8);
void func_80738080(s32, u8, u8);
void func_807380CC(ALSeqPlayer*, s32, u8);
void func_80738118(s32, s32, u8);
void func_807382A0(s32, s32, u8, u8, u8);
void func_8060B140(s32, s32*, s32*, s32, s32, s32, s32);

// Struct on the stack? Big malloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5A50/func_80600D50.s")

void func_806010A0(void) {
    s32 sp34, sp30, sp2C;

    sp34 = 0x80;
    func_8060B140(D_8000DDCC, &D_8076D200, &sp34, 0, 0, 0, 0);
    sp30 = 0x2C0;
    sp2C = D_8076D200;
    func_8060B140(D_8000DDCC + sp2C, &D_8076D200, &sp30, 0, 0, 0, 0);
}

void func_80601120(u8 arg0) {
    if (func_80737E30(D_8076BF20[arg0]) == 0) {
        func_80737E50(D_8076BF20[arg0]);
    }
}

void func_8060116C(u8 arg0) {
    func_80737E30(D_8076BF20[arg0]);
}

void func_806011A0(u8 arg0, s32 arg1) {
    func_80737E90(D_8076BF20[arg0], arg1, arg0);
}

void func_806011D4(s32 arg0, s32 arg1, s32 arg2) {

}

void func_806011E4(u8 arg0, s32 arg1, u8 arg2) {
    func_80737F0C(D_8076BF20[arg0], arg1, arg2);
}

void func_80601224(u8 arg0, s32 arg1) {
    func_80737FD8(D_8076BF20[arg0], arg1, arg0);
}

void func_80601258(u8 arg0, s32 arg1) {
    func_8073801C(D_8076BF20[arg0], arg1, arg0);
}

void func_8060128C(u8 arg0, s32 arg1, u8 arg2) {
    func_80738080(D_8076BF20[arg0], arg1, arg2);
}

void func_806012D4(u8 arg0, u8 arg1, u8 arg2) {
    func_807380CC(D_8076BF20[arg0], arg1, arg2);
}

void func_8060131C(u8 arg0, s32 arg1, u8 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            func_8060128C(arg0, i & 0xFF, arg2);
        }
    }
}

void func_806013A0(u8 arg0, u8 arg1, u8 arg2) {
    func_80738118(D_8076BF20[arg0], arg1, arg2);
}

void func_806013E8(u8 arg0, s32 arg1, u8 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            func_80738118(D_8076BF20[arg0], i, arg2);
        }
    }
}

void func_80601484(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            if (arg2 != 0) {
                func_80601258(arg0, i);
            } else {
                func_80601224(arg0, i);
            }
        }
    }
}

void func_8060151C(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            if (arg2 != 0) {
                D_8076BF20[arg0]->chanMask |= arg1;
            } else {
                D_8076BF20[arg0]->chanMask &= (arg1 ^ 0xFFFF);
            }
        }
    }
}

// TODO: Double check datatypes, it's fine for now though
void func_806015E0(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            func_80738230(D_8076BF20[arg0], i & 0xFF, arg2 & 0xFF);
        }
    }
}

void func_80601678(u8 arg0, u8 arg1, u8 arg2) {
    func_807382A0(D_8076BF20[arg0], 0, arg1 | 0xB0, 0x21, arg2);
}

void func_806016D0(u8 arg0, u8 arg1, u8 arg2) {
    func_807382A0(D_8076BF20[arg0], 0, arg1 | 0xB0, 0x22, arg2);
}

void func_80601728(u8 arg0, u8 arg1, u8 arg2) {
    func_807382A0(D_8076BF20[arg0], 0, arg1 | 0xB0, 0x23, arg2);
}

void func_80601780(u8 arg0, s32 arg1) {
    func_80738320(D_8076BF20[arg0], arg1, arg0);
}

void func_806017B4(u8 arg0) {
    func_807383B0(D_8076BF20[arg0]);
}

void func_806017E8(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    func_80738400(D_8076BF20[arg0], arg1, arg2, arg3, arg4);
}

void func_80601848(u8 arg0, f32 arg1, f32 arg2) {
    func_807381D8(D_8076BF20[arg0], arg1, arg2);
}

void func_8060188C(u8 arg0, s32 arg1) {
    D_8076BF20[arg0]->nextDelta += arg1;
}

ALMicroTime func_806018B4(u8 arg0) {
    return D_8076BF20[arg0]->curTime;
}

typedef struct {
    u8 unk0[0xF8];
} struct_8076BF48;

typedef struct {
    u8 unk0[0xEC];
} struct_sub_8076C328;

typedef struct {
    struct_sub_8076C328 unk0[4];
} struct_8076C328;

void func_80738E58(struct_8076BF48*, struct_8076C328*, u8, s32);                   /* extern */
extern struct_8076BF48 D_8076BF48[];
extern struct_8076C328 D_8076C328[];

void func_806018D4(u8 arg0, u8 arg1, s32 arg2) {
    func_80738E58(&D_8076BF48[arg0], &D_8076C328[arg0], arg1, arg2);
}

void func_80738BB8(struct_8076BF48*, struct_sub_8076C328 *, u8, u8);             /* extern */

void func_8060193C(u8 arg0, u8 arg1) {
    func_80738BB8(
        &D_8076BF48[arg0], 
        &D_8076C328[arg0].unk0[arg1],
        arg0,
        arg1);
}

void func_806019B8(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_807382A0(D_8076BF20[arg0], arg1, arg2, arg3, arg4);
}

