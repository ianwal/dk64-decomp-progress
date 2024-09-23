#include <ultra64.h>
#include "functions.h"

#include "synthinternal.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073D1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073DA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073DF50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E63C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_141EF0/func_global_asm_8073E800.s")
