#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x18 - 0x0];
    s32 unk18;
    u8 unk1C[0x24 - 0x1C];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unk30[0x48 - 0x30];
    s32 unk48;
} Struct807359A0;

void func_global_asm_807359A0(Struct807359A0 *arg0) {
    s32 pad[3];
    s16 pad2;
    s16 sp20;
    s32 sp1C;

    if (!(arg0->unk2C == 1) || !arg0->unk18) {
        return;
    }

    if (!func_global_asm_8073D060(arg0->unk18, &sp1C)) {
        return;
    }

    sp20 = 0;
    alEvtqPostEvent(&arg0->unk48, &sp20, arg0->unk24 * sp1C);
}

typedef struct {
    u8 unk0[0x88 - 0x0];
    u8 unk88;
} Struct80735A34;

void func_global_asm_80735A34(Struct80735A34 *arg0, u8 arg1) {
    arg0->unk88 = arg1;
}
