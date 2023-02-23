#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "synthinternal.h"

//n_alSynNew
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/synthesizer/n_alSynNew.s")

//n_alAudioFrame
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/synthesizer/n_alAudioFrame.s")

ALParam *__n_allocParam(void) {
    ALParam *update = 0;

    if (n_syn->paramList) {        
        update = n_syn->paramList;
        n_syn->paramList = n_syn->paramList->next;
        update->next = 0;
    }
    return update;
}

void __n_freeParam(ALParam *param) 
{
    param->next = n_syn->paramList;
    n_syn->paramList = param;
}

void _n_collectPVoices() 
{
    ALLink       *dl;
    PVoice      *pv;

    while ((dl = n_syn->pLameList.next) != 0) {
        pv = (PVoice *)dl;

        /* ### remove from mixer */

        alUnlink(dl);
        alLink(dl, &n_syn->pFreeList);        
    }
}

void _n_freePVoice(PVoice *pvoice) 
{
    /*
     * move the voice from the allocated list to the lame list
     */
    alUnlink((ALLink *)pvoice);
    alLink((ALLink *)pvoice, &n_syn->pLameList);
}

/*
  Add 0.5 to adjust the average affect of
  the truncation error produced by casting
  a float to an int.
*/
s32 _n_timeToSamplesNoRound(s32 micros)
{
    
    f32 tmp = ((f32)micros) * n_syn->outputRate / 1000000.0f + 0.5f;

    return (s32)tmp;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/synthesizer/func_80739E24.s")
#else
// s32 _timeToSamples(ALSynth *synth, s32 micros)
s32 func_80739E24(s32 micros)
{ return _n_timeToSamplesNoRound(micros) & ~0xf;
}
#endif

static s32 __n_nextSampleTime(ALPlayer **client) 
{
    s32 pad;
    ALMicroTime delta = 0x7fffffff;     /* max delta for s32 */
    ALPlayer *cl;

    //assert(n_syn->head);
    *client = 0;
    
    for (cl = n_syn->head; cl != 0; cl = cl->next) {
        if ((cl->samplesLeft - n_syn->curSamples) < delta) {
            *client = cl;
            delta = cl->samplesLeft - n_syn->curSamples;
        }
    }

    return (*client)->samplesLeft;
}
