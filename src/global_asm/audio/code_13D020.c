#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x48 - 0x0];
    ALEventQueue unk48;
} Struct80738320;

void func_80738320(Struct80738320 *arg0, s32 arg1) {
    ALEvent sp18;

    sp18.type = 7;
    sp18.msg.evt7.unk04 = 0xFF;
    sp18.msg.evt7.unk05 = 0x51;
    sp18.msg.evt7.unk07 = (arg1 & 0xFF0000) >> 0x10;
    sp18.msg.evt7.unk08 = (arg1 & 0xFF00) >> 8;
    sp18.msg.evt7.unk09 = arg1 & 0xFF;
    alEvtqPostEvent(&arg0->unk48, &sp18, 0);
}
