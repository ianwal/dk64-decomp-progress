#include <ultra64.h>
#include "functions.h"

extern OSThread *__osActiveQueue2;

s32 __osGetActiveQueue(void) {
    return __osActiveQueue2;
}
