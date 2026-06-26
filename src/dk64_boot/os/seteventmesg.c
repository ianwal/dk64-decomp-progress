#include <ultra64.h>
#include "osint.h"
#include "macros.h"

__OSEventState __osEventStateTab[OS_NUM_EVENTS] ALIGNED(8);

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg)
{
	register u32 saveMask = __osDisableInt();
	__OSEventState *es;

	es = &__osEventStateTab[event];
	es->messageQueue = mq;
	es->message = msg;
	__osRestoreInt(saveMask);
}
