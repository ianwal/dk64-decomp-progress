#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
void _n_freePVoice(PVoice *);
s32 func_global_asm_8073F1E4(CustomPVoice *, s32, ALParam *);

// alsynfreevoice
void func_global_asm_8073B750(ALVoice *v) {
    ALFilter *f;
    ALFreeParam *update;

    if (v->pvoice != NULL) {
        if (((CustomPVoice *)v->pvoice)->unk88 != 0) {
            update = __n_allocParam();
            ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);
            update->delta = n_syn->paramSamples + ((CustomPVoice *)v->pvoice)->unk88;
            update->type = AL_FILTER_FREE_VOICE;
            update->pvoice = v->pvoice;
            func_global_asm_8073F1E4(v->pvoice, AL_FILTER_ADD_UPDATE, update);
        } else {
            _n_freePVoice(v->pvoice);
        }
        v->pvoice = NULL;
    }
}