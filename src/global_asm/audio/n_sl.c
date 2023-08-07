#include <ultra64.h>
#include "functions.h"


extern N_ALGlobals *n_alGlobals=0;
extern N_ALSynth *n_syn;

void n_alInit(N_ALGlobals *g, ALSynConfig *c)
{
    if (!n_alGlobals) { /* already initialized? */
        n_alGlobals = g;
        if (!n_syn) {
            n_syn = &n_alGlobals->drvr;
            n_alSynNew(c);  //n_alSynNew(c);
        }
    }
}

void n_alClose(N_ALGlobals *glob)
{
    if (n_alGlobals) {
        n_alSynDelete();//n_alSynDelete();
        n_alGlobals = 0;
        n_syn = 0;
    }
}
