#include <ultra64.h>
#include "functions.h"


void alSepqSetVol(ALSeqPlayer *seqp, s16 vol)
{
    ALEvent       evt;

    evt.type            = AL_SEQP_VOL_EVT;
    evt.msg.spvol.vol   = vol;
    
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
