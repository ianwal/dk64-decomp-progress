#include <ultra64.h>
#include "functions.h"

void func_global_asm_80735A50(ALSeqPlayer *seqp, ALBank *b) {
    ALEvent evt;

    evt.type = AL_SEQP_BANK_EVT;
    evt.msg.spbank.bank = b;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
