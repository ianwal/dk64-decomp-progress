#include "common.h"

ALParam *__n_allocParam();
s32 n_alEnvmixerParam(CustomPVoice *, s32, ALParam *);

void n_alSynStopVoice(N_ALVoice *v) {
    ALParam *sp1C;

    if (v->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)v->pvoice)->unk88;
        sp1C->type = AL_FILTER_STOP_VOICE;
        sp1C->next = 0;
        n_alEnvmixerParam(v->pvoice, AL_FILTER_ADD_UPDATE, sp1C);
    }
}
