#include <ultra64.h>
#include <rcp.h>

void osSpTaskYield(void)
{
    __osSpSetStatus(SP_SET_YIELD);
}
