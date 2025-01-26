#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
void n_alEnvmixerParam(CustomPVoice *, s32, ALParam *);

void func_global_asm_8073BA60(ALVoice *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = 0x12;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        n_alEnvmixerParam(arg0->pvoice, 3, sp1C);
    }
}
