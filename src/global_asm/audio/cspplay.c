#include "common.h"

void func_global_asm_80737E50(ALCSPlayer * seqp) {
    // alCSPPlay
    ALEvent evt;

    evt.type = AL_SEQP_PLAY_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
