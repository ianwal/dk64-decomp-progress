#include <ultra64.h>
#include "functions.h"

extern s32 __osPiAccessQueueEnabled;
extern void *D_dk64_boot_80016320;
extern OSMesgQueue __osPiAccessQueue;

void __osPiCreateAccessQueue(void) {
    __osPiAccessQueueEnabled = TRUE;
    osCreateMesgQueue(&__osPiAccessQueue, &D_dk64_boot_80016320, 1);
    osSendMesg(&__osPiAccessQueue, NULL, 0);
}

void __osPiGetAccess(void) {
    void *sp1C;

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(&__osPiAccessQueue, &sp1C, 1);
}

void __osPiRelAccess(void) {
    osSendMesg(&__osPiAccessQueue, NULL, 0);
}
