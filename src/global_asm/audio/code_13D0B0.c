#include "common.h"

s32 func_global_asm_807383B0(ALSeqPlayer *arg0) {
    if (!arg0->target) {
        return 0;
    }
    // TODO: Oof, I think our audio headers may be the wrong version...
    return arg0->uspt / ((f32*)arg0->target)[2];
}
