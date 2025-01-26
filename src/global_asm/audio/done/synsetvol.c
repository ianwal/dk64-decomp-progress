#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
s32 func_global_asm_80739E24(s32);
s32 n_alEnvmixerParam(Struct8073F1E4 *, s32, s32 *);

void func_global_asm_8073B830(ALVoice *arg0, s16 arg1, s32 arg2) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = AL_FILTER_SET_VOLUME;
        sp1C->data.i = arg1;
        sp1C->moredata.i = func_global_asm_80739E24(arg2);
        sp1C->next = 0;
        n_alEnvmixerParam(arg0->pvoice, 3, sp1C);
    }
}
