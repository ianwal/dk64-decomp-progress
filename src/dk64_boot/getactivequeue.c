#include "common.h"

extern OSThread *__osActiveQueue2;

s32 __osGetActiveQueue(void) {
    return __osActiveQueue2;
}
