#include <ultra64.h>
#include "functions.h"


void func_global_asm_8073C040(s32 *, s32, s16, s32);

s32 func_global_asm_8073D160(s16 arg0, s32 arg1, s32 arg2) {
    func_global_asm_8073C040(&((Struct8073BC74_auxbus *)n_syn->auxBus)[arg0].unk24, arg1, arg0, arg2);
    return ((Struct8073BC74_auxbus *)n_syn->auxBus)[arg0].unk24;
}
