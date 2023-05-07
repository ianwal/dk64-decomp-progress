#include <ultra64.h>
#include "functions.h"

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_145950/func_80740C50.s")

void func_807407A8(void *, s32, void*);

typedef struct {
    u8 unk0[0x8C - 0x0];
    s8 unk8C;
    s8 unk8D;
    s8 unk8E;
    s8 unk8F;
    s16 unk90;
    s16 unk92;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
} Struct80740F48;

// TODO: Fake match? This makes no sense...
s32 func_80740F48(Struct80740F48 *arg0, s32 arg1, f32 *arg2) {
    f32 *temp = &arg2;
    switch (arg1) {
        case 4:
            arg0->unk92 = 0;
            func_807407A8(arg0, 4, arg2);
            break;
        case 18:
            arg0->unk92 = arg2;
            arg0->unkB8 |= 2;
            break;
        case 19:
            arg0->unk90 = *temp;
            arg0->unkB8 |= 2;
            break;
        case 17:
            arg0->unk8C = arg2;
            break;
        default:
            func_807407A8(arg0, arg1, arg2);
            break;
    }
    return 0;
}
