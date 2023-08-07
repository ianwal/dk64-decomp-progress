#include <ultra64.h>
#include "piint.h"

u32 osPiGetStatus()
{
    return IO_READ(PI_STATUS_REG);
}
