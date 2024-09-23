#include <ultra64.h>
#include "functions.h"

#include "synthinternal.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073D1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073DA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073DF50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E460.s")

Acmd *func_global_asm_8073E63C(Struct8073BC74_auxbus_unk20_unk4_unk20 *arg0, s32 arg1, s32 arg2, Acmd *arg3) {
    Acmd *sp24;
    s16 sp22;
    Acmd *sp1C;
    Acmd *sp18;

    sp24 = arg3;
    sp22 = (s16) (arg2 >> 8);
    sp1C = sp24++;
    sp1C->words.w0 = 0x0B000020;
    sp1C->words.w1 = osVirtualToPhysical(&arg0->unk8);
    sp18 = sp24++;
    sp18->words.w0 = ((arg0->unk28 & 0xFF) << 0x10) | 0x0E000000 | (arg0->unk2 & 0xFFFF);
    sp18->words.w1 = (osVirtualToPhysical(arg0->unk2C[arg1]) & 0xFFFFFF) | ((sp22 & 0xFF) << 0x18);
    arg0->unk28 = 0;
    return sp24;
}

f32 func_global_asm_8073E73C(Struct8073BC74_auxbus_unk20_unk4 *arg0, s32 arg1) {
    f32 sp4;

    arg0->unk14 += (arg0->unk10 * (f32) arg1);
    if (arg0->unk14 > 2.0f) {
        arg0->unk14 -= 4.0f;
    } else {
        arg0->unk14 = arg0->unk14;
    }
    sp4 = arg0->unk14;
    sp4 = sp4 < 0.0f ? -sp4 : sp4;
    sp4 -= 1.0f;
    return arg0->unk1C * sp4;
}

Acmd *func_global_asm_8073FD90(s32, Acmd *);

s32 *func_global_asm_8073E800(s32 arg0, Acmd *arg1) {
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp24 = arg1;
    sp24 = func_global_asm_8073FD90(arg0, sp24);
    sp20 = sp24++;
    sp20->words.w0 = 0x0D000000;
    sp1C = sp24++;
    sp1C->words.w0 = 0x062E0000;
    sp1C->words.w1 = n_syn->sv_dramout;
    return sp24;
}