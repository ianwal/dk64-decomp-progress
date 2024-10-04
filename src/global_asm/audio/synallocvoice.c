#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/synallocvoice/func_global_asm_8073CAC0.s")

/*
Very close, weird thing with the return where it's adding an extra instruction
ALParam *__n_allocParam();
s32 func_global_asm_8073CC94(CustomPVoice **, s16);
s32 func_global_asm_8073F1E4(CustomPVoice *, s32, ALParam *);

s32 func_global_asm_8073CAC0(ALVoice *voice, ALVoiceConfig *vc)
{
    CustomPVoice  *pvoice = 0;
    ALFilter *f;
    ALParam *update;
    s32 stolen;
    
#ifdef _DEBUG
    // need two updates if voice is stolen
    if (drvr->paramList == 0) {
        __osError(ERR_ALSYN_NO_UPDATE, 0);
        return 0;
    } else if (drvr->paramList->next == 0) {
        __osError(ERR_ALSYN_NO_UPDATE, 0);
        return 0;
    }
#endif    

    voice->priority     = vc->priority;
    voice->unityPitch   = vc->unityPitch;
    voice->table        = 0;
    voice->fxBus        = vc->fxBus;
    voice->state        = AL_STOPPED;        
    voice->pvoice       = 0;

    stolen = func_global_asm_8073CC94(&pvoice, vc->priority);
        
    if (pvoice) {    // if we were able to allocate a voice
       
            
        if (stolen) {
                
            pvoice->unk88 = 552; // Normally 512?
            pvoice->vvoice->pvoice = 0; // zero stolen voice
            pvoice->vvoice = voice;
            voice->pvoice = pvoice;
                
            // ramp down stolen voice
            update = __n_allocParam();
            if (update) {
                update->delta      = n_syn->paramSamples;
                update->type       = AL_FILTER_SET_VOLUME;
                update->data.i     = 0;
                update->moredata.i = 0x170;
                func_global_asm_8073F1E4(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
                if (FALSE);
            }

            // stop stolen voice
            update = __n_allocParam();
            if (update) {
                update->delta  = n_syn->paramSamples + pvoice->unk88;
                update->type   = AL_FILTER_STOP_VOICE;
                update->next   = 0;
                func_global_asm_8073F1E4(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
            } else {
#ifdef _DEBUG                
                __osError(ERR_ALSYN_NO_UPDATE, 0);
#endif
            }

        } else {
            pvoice->unk88 = 0;
        }
            
        pvoice->vvoice = voice;     // assign new voice
        voice->pvoice  = pvoice;
    }
    return pvoice != NULL;    
}
*/

s32 func_global_asm_8073CC94(CustomPVoice **pvoice, s16 priority) {
    // _allocatePVoice
    ALLink *dl;
    CustomPVoice *pv;
    s32 stolen = FALSE;

    if ((dl = n_syn->pLameList.next) != NULL) { /* check the lame list first */
        *pvoice = dl;
        alUnlink(dl);
        alLink(dl, &n_syn->pAllocList);
    } else if ((dl = n_syn->pFreeList.next) != 0) { /* from the free list */
        *pvoice = dl;
        alUnlink(dl);
        alLink(dl, &n_syn->pAllocList);
    } else { /* steal one */
        for (dl = n_syn->pAllocList.next; dl; dl = dl->next) {
            pv = dl;
            if ((pv->vvoice->priority <= priority) && (pv->unk88 == 0)) {
                *pvoice = pv;
                priority = pv->vvoice->priority;
                stolen = TRUE;
            }
        }
    }
    return stolen;
}

