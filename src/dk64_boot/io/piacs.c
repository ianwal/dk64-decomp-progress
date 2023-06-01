#include <ultra64.h>
#include "functions.h"

extern s32 D_80010200;
extern void *D_80016320;
extern OSMesgQueue D_80016328;

void __osPiCreateAccessQueue(void) {
    D_80010200 = TRUE;
    osCreateMesgQueue(&D_80016328, &D_80016320, 1);
    osSendMesg(&D_80016328, NULL, 0);
}

void __osPiGetAccess(void) {
    void *sp1C;

    if (!D_80010200) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(&D_80016328, &sp1C, 1);
}

void __osPiRelAccess(void) {
    osSendMesg(&D_80016328, NULL, 0);
}
