#include "common.h"


extern N_ALSynth *n_syn;

void n_alSynDelete(void) {
    n_syn->head = NULL;
}
