#include "common.h"


void n_alFxNew(s32 *, s32, s16, s32);

s32 func_global_asm_8073D160(s16 arg0, s32 arg1, s32 arg2) {
    n_alFxNew(&((Struct8073BC74_auxbus *)n_syn->auxBus)[arg0].unk24, arg1, arg0, arg2);
    return ((Struct8073BC74_auxbus *)n_syn->auxBus)[arg0].unk24;
}
