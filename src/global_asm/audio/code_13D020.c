#include "common.h"

typedef struct {
    u8 unk0[0x48 - 0x0];
    ALEventQueue unk48;
} Struct80738320;

void func_global_asm_80738320(Struct80738320 *arg0, s32 arg1) {
    ALEvent sp18;

    sp18.type = AL_SEQP_META_EVT;
    sp18.msg.meta.unk4 = 0xFF;
    sp18.msg.meta.unk5 = 0x51;
    sp18.msg.meta.unk7 = (arg1 & 0xFF0000) >> 0x10;
    sp18.msg.meta.unk8 = (arg1 & 0xFF00) >> 8;
    sp18.msg.meta.unk9 = arg1 & 0xFF;
    alEvtqPostEvent(&arg0->unk48, &sp18, 0);
}
