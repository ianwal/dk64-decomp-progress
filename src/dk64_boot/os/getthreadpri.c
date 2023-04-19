#include <ultra64.h>
#include "functions.h"


extern OSThread *__osRunningThread;

OSPri osGetThreadPri(OSThread *thread)
{
    if (thread == NULL)
        thread = __osRunningThread;
    return thread->priority;
}
