#include <ultra64.h>
#include "functions.h"

#define SI_Q_BUF_LEN 1

extern u32 D_dk64_boot_800101E0; // __osSiAccessQueueEnabled
extern void *D_dk64_boot_800162C0;
extern OSMesgQueue D_dk64_boot_800162C8; // __osSiAccessQueue

void __osSiCreateAccessQueue(void) {
    D_dk64_boot_800101E0 = TRUE;
    osCreateMesgQueue(&D_dk64_boot_800162C8, &D_dk64_boot_800162C0, SI_Q_BUF_LEN);
    osSendMesg(&D_dk64_boot_800162C8, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
    OSMesg dummyMesg;

    if (!D_dk64_boot_800101E0) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(&D_dk64_boot_800162C8, &dummyMesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
    osSendMesg(&D_dk64_boot_800162C8, NULL, OS_MESG_NOBLOCK);
}
