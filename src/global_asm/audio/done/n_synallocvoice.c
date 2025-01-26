#include <ultra64.h>
#include "functions.h"
#include "n_synthInternals.h"


s32     n_alEnvmixerParam(N_PVoice *p, s32 paramID, void *param);
s32 func_global_asm_8073CC94(N_PVoice **pvoice, s16 priority);

// n_alSynAllocVoice
s32 func_global_asm_8073CAC0(N_ALVoice *voice, ALVoiceConfig *vc)
{
	N_PVoice *pvoice = 0;
    s32 sp20;
	ALParam *update; // 1c
	s32 stolen; // 18

	voice->priority   = vc->priority;
	voice->unityPitch = vc->unityPitch;
	voice->table      = 0;
	voice->fxBus      = vc->fxBus;
	voice->state      = AL_STOPPED;
	voice->pvoice     = 0;

	stolen = func_global_asm_8073CC94( &pvoice, vc->priority);

	if (pvoice) {    /* if we were able to allocate a voice */
		if (stolen) {
			pvoice->offset = 552;
			pvoice->vvoice->pvoice = 0; /* zero stolen voice */
			pvoice->vvoice = voice;
			voice->pvoice = pvoice;

			/*
			 * ramp down stolen voice
			 */
			update = __n_allocParam();

			if (update) {
				update->delta      = n_syn->paramSamples;
				update->type       = AL_FILTER_SET_VOLUME;
				update->data.i     = 0;
				update->moredata.i = 368; /* pvoice->offset - 184 */

				n_alEnvmixerParam(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
			} else {
				// empty
			}

			/*
			 * stop stolen voice
			 */
			update = __n_allocParam();

			if (update) {
				update->delta = n_syn->paramSamples + pvoice->offset;
				update->type = AL_FILTER_STOP_VOICE;
				update->next = 0;
				n_alEnvmixerParam(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
			} else {
				// empty
			}
		} else {
			pvoice->offset = 0;
			pvoice->vvoice = voice;
			voice->pvoice = pvoice;
		}
	}

	return (pvoice != 0);
}

s32 func_global_asm_8073CC94(N_PVoice **pvoice, s16 priority) {
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

