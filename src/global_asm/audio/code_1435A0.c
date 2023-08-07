#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x16 - 0x0];
    s16 unk16;
} Struct8073E8A0;

void func_global_asm_8073E8A0(Struct8073E8A0 *arg0, s16 arg1) {
    arg0->unk16 = arg1;
}
