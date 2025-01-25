#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
s32 func_global_asm_8073F1E4(Struct8073F1E4 *, s32, ALParam *);

void func_global_asm_8073C820(ALVoice *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        ALFailIf(sp1C == 0, ERR_ALSYN_NO_UPDATE);
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = AL_SEQP_STOP_EVT;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->pvoice, 3, sp1C);
    }
}

extern s32 func_global_asm_8073D1F0(s32, Acmd *, s32);  // Unsure of this sig, used for an & ref, so not important if changed
s32 func_global_asm_8073C8D0(s16 arg0) {
    N_ALMAinBus *sp4;

    sp4 = n_syn->mainBus;
    if ((s32)(sp4->handler) == (s32)&func_global_asm_8073D1F0) {
        return ((Struct8073BC74_auxbus *)n_syn->auxBus)[arg0].unk20;
    } else {
        return 0;
    }
}

s32 func_global_asm_8073C948(s16 arg0) {
    N_ALMAinBus *sp4;

    sp4 = n_syn->mainBus;
    if ((s32)(sp4->handler) == (s32)&func_global_asm_8073D1F0) {
        return ((Struct8073BC74_auxbus *)n_syn->auxBus)[arg0].unk44;
    } else {
        return 0;
    }
}

s32 func_global_asm_8073DA30(s32, s16, s32);

void func_global_asm_8073C9C0(s32 arg0, s16 arg1, s32 arg2) {
    s32 sp1C;

    sp1C = arg0;
    func_global_asm_8073DA30(sp1C, arg1, arg2);
}

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct8073CA04_arg0;

void func_global_asm_8073CA04(Struct8073CA04_arg0 *arg0, s16 arg1, s32 *arg2) {
    if (arg1 == 8) {
        arg0->unk2 = *arg2 * 0.1f;
    } else if (arg1 == 9) {
        arg0->unk0 = *arg2;
    }
    func_global_asm_8073BE54(arg0, n_syn->outputRate);
}
