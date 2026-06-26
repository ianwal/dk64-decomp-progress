#include <ultra64.h>
#include "viint.h"

u32 osViGetCurrentMode(void)
{
    register u32 savedMask;
    register u32 modeType;
    savedMask = __osDisableInt();
    modeType = __osViCurr->modep->type;
    __osRestoreInt(savedMask);
    return modeType;
}
