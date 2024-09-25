#include <ultra64.h>
#include "functions.h"

void *__n_allocParam();
s32 func_global_asm_80739E24(s32);;
void func_global_asm_8073F1E4(CustomPVoice *, s32, ALStartParamAlt *);

typedef struct ALStartParamAlt_0 {
    ALParam *next; // 0
    s32 delta; // 4
    s16 type; // 8 
    s16 unity; // A
    f32 unkC;
    s16 unk10;
    u8 pan;
    u8 fxmix;
    u8 unk14;
    u8 unk15;
    s16 unk16;
    f32 unk18;
    s32 samples;
    s32 wave;
} ALStartParamAlt_0;

void func_global_asm_8073CDD0(ALVoice *v, ALWaveTable *w,
                                f32 pitch, s16 vol, ALPan pan,
                                u8 fxmix, u8 arg6, f32 arg7, u8 arg8, s32 arg9) {
    ALStartParamAlt_0 *update;

    if (v->pvoice != NULL) {
        update = __n_allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);
        update->delta = (s32) (n_syn->paramSamples + ((CustomPVoice *)v->pvoice)->unk88);
        update->next = 0;
        update->type = 0xD;
        update->unity = (s16) v->unityPitch;
        update->pan = pan;
        update->unk10 = vol;
        update->fxmix = fxmix;
        update->unkC = pitch;
        update->unk14 = arg8;
        update->unk15 = arg6;
        update->unk18 = arg7;
        update->samples = func_global_asm_80739E24(arg9);
        update->wave = w;
        func_global_asm_8073F1E4(v->pvoice, AL_FILTER_ADD_UPDATE, update);
    }
}