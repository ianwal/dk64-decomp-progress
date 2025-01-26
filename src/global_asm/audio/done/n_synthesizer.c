#include <ultra64.h>
#include "functions.h"
#include "n_synthInternals.h"

ALFxRef func_global_asm_8073D160( s16 bus,ALSynConfig *c, ALHeap *hp);
Acmd *n_alFxPull( s32 sampleOffset, Acmd *p, s32 arg2);
void alN_PVoiceNew(N_PVoice *mv, ALDMANew dmaNew, ALHeap *hp);

typedef struct ParamStruct {
    ALParam param;
    u8 pad1C[8];
} ParamStruct;

void n_alSynNew(ALSynConfig *c) {
	s32 i;
	s32 j;
    s32 pad;
	N_PVoice *pv;
    s32 pad1;
	N_PVoice *pvoices;
	ALHeap *hp = c->heap; //  2c
    s32 pad2;
	ParamStruct *params;
	ALParam *paramPtr;

	n_syn->head          = NULL;
	n_syn->numPVoices    = c->maxPVoices;
	n_syn->curSamples    = 0;
	n_syn->paramSamples  = 0;
	n_syn->outputRate    = c->outputRate;
	n_syn->maxOutSamples = FIXED_SAMPLE;
	n_syn->dma           = (ALDMANew) c->dmaproc;

	/******* save new *******************************/
	n_syn->sv_dramout = 0;
	n_syn->sv_first = 1;

	if (c->maxFXbusses > 2) {
		n_syn->maxAuxBusses = 2;
	} else if (c->maxFXbusses < 1) {
		n_syn->maxAuxBusses = 1;
	} else {
		n_syn->maxAuxBusses = c->maxFXbusses;
	}

	/******* aux new *******************************/
	n_syn->auxBus = (N_ALAuxBus *)alHeapAlloc(hp, n_syn->maxAuxBusses, sizeof(N_ALAuxBus));

	for (i = 0; i < n_syn->maxAuxBusses; i++) {
		n_syn->auxBus[i].sourceCount = 0;
		n_syn->auxBus[i].maxSources = c->maxPVoices;
		n_syn->auxBus[i].sources = alHeapAlloc(hp, c->maxPVoices, sizeof(void *));

		if (c->fxTypes[i]) {
			n_syn->auxBus[i].fx = func_global_asm_8073D160(i, c, hp);
		} else {
			n_syn->auxBus[i].fx = NULL;
		}

		n_syn->auxBus[i].unk44 = alHeapAlloc(hp, 1, sizeof(struct auxbus44));
		n_syn->auxBus[i].unk44->fx.unk02 = 0;
		n_syn->auxBus[i].unk44->unk2c = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));
		n_syn->auxBus[i].unk44->unk30 = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));
	}

	/******* main new *******************************/
	n_syn->mainBus = (N_ALMainBus *)alHeapAlloc(hp, 1, sizeof(N_ALMainBus));

	/******* fx new *******************************/
	n_syn->mainBus->filter.handler = (N_ALCmdHandler)n_alFxPull;

	n_syn->pFreeList.next = 0;
	n_syn->pFreeList.prev = 0;
	n_syn->pLameList.next = 0;
	n_syn->pLameList.prev = 0;
	n_syn->pAllocList.next = 0;
	n_syn->pAllocList.prev = 0;

	pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(N_PVoice));

	for (i = 0; i < c->maxPVoices; i++) {
		pv = &pvoices[i];
		alLink((ALLink *)pv, &n_syn->pFreeList);
		pv->vvoice = 0;
		alN_PVoiceNew(pv, n_syn->dma, hp);

		for (j = 0; j < n_syn->maxAuxBusses; j++) {
			n_syn->auxBus[j].sources[n_syn->auxBus[j].sourceCount++] = pv;
		}
	}

	params = alHeapAlloc(hp, c->maxUpdates, sizeof(ParamStruct));
	n_syn->paramList = 0;

	for (i = 0; i < c->maxUpdates; i++) {
		paramPtr = &params[i];
		paramPtr->next = n_syn->paramList;

		n_syn->paramList = paramPtr;
	}

	n_syn->heap = hp;
}

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

void _n_freePVoice(N_PVoice *pvoice) {
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

s32 __n_nextSampleTime(ALPlayer **client) {
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
