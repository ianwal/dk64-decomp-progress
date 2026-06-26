#include <ultra64.h>
#include <rcp.h>

void __osSpSetStatus(u32 data) {
    IO_WRITE(SP_STATUS_REG, data);
}
