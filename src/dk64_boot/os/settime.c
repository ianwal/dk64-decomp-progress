#include <ultra64.h>
#include "osint.h"

void osSetTime(OSTime time) {
    __osCurrentTime = time;
}
