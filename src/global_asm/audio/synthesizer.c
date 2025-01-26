#include <ultra64.h>
#include "functions.h"

#include "synthinternal.h"

//n_alSynNew
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/synthesizer/n_alSynNew.s")

s32 __n_nextSampleTime(ALPlayer **);                    /* extern */
Acmd *func_global_asm_8073E800(s32, Acmd *);        /* extern */

Acmd *n_alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen) {
    ALPlayer *client;
    s16 sp3A;
    Acmd *cmdlEnd;
    Acmd *cmdPtr;
    s32 nOut;
    s16 *lOutBuf;

    sp3A = 0;
    cmdlEnd = cmdList;
    lOutBuf = outBuf;
    if (n_syn->head == NULL) {
        *cmdLen = 0;
        return cmdList;
    }
    
    for (n_syn->paramSamples = __n_nextSampleTime(&client);
        (n_syn->paramSamples - n_syn->curSamples) < outLen;
        n_syn->paramSamples = __n_nextSampleTime(&client)
    ) {
        n_syn->paramSamples &= ~0xF;
        client->samplesLeft += _n_timeToSamplesNoRound((*client->handler)(client));
        
    }
    n_syn->paramSamples &= ~0xF;
    while (outLen > 0) {
        nOut = MIN(n_syn->maxOutSamples, outLen);
        cmdPtr = cmdlEnd;
        n_syn->sv_dramout = (s32) lOutBuf;
        cmdlEnd = func_global_asm_8073E800(n_syn->curSamples, cmdPtr);
        outLen -= nOut;
        lOutBuf += nOut << 1;
        n_syn->curSamples += nOut;
    }
    *cmdLen = (s32) (cmdlEnd - cmdList);
    _n_collectPVoices();
    return cmdlEnd;
}

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

s32 func_global_asm_80739E24(s32 micros) {
    return _n_timeToSamplesNoRound(micros) & ~0xf;
}

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
