#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

void func_global_asm_80619500(Actor *arg0) {
    deleteActor(arg0);
}

typedef struct {
    u8 unk0[0x35 - 0x0];
    u8 unk35;
} A178_80619580;

A178_80619580 *func_global_asm_80619520(Actor *arg0) {
    A178_80619580 *a178;

    a178 = NULL;
    // TODO: Proper enum value
    if (arg0->unk58 == 0x134) {
        a178 = arg0->unk178;
    }
    return a178;
}

void func_global_asm_80619540(Actor *arg0) {
    u8 sp1F;
    A178_80619580 *a178;

    a178 = func_global_asm_80619520(arg0);
    getAnimationArg8(&sp1F);
    if (a178 != NULL) {
        a178->unk35 = sp1F;
    }
}

void func_global_asm_80619580(Actor *arg0) {
    A178_80619580 *a178;

    a178 = func_global_asm_80619520(arg0);
    if (a178 != NULL) {
        a178->unk35++;
    }
}

void func_global_asm_806195B4(Actor *arg0) {
    arg0->animation_state->unk88 = (arg0->unkDE >= 0x3DA);
}
