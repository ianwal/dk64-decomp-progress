#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
s32 func_global_asm_8073F1E4(CustomPVoice *, s32, ALParam *);

// alsynstopvoice
void func_global_asm_8073B6B0(ALVoice *arg0) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = AL_FILTER_STOP_VOICE;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->pvoice, AL_FILTER_ADD_UPDATE, sp1C);
    }
}