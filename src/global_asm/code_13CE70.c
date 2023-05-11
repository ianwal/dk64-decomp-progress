#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x48 - 0x0];
    ALEventQueue unk48;
} Struct80738320;

void func_80738170(Struct80738320 *arg0, u8 arg1, u8 arg2) {
    ALEvent sp18;

    sp18.type = AL_SEQP_MIDI_EVT;
    sp18.msg.midi.ticks = 0;
    sp18.msg.midi.status = arg1 | 0xB0;
    sp18.msg.midi.byte1 = 0x5B;
    sp18.msg.midi.byte2 = arg2;
    alEvtqPostEvent(&arg0->unk48, &sp18, 0);
}

void func_807381D8(Struct80738320 *arg0, f32 arg1, f32 arg2) {
    ALEvent sp18;

    sp18.type = 0x18;
    sp18.msg.evt18.unk00 = arg1;
    sp18.msg.evt18.unk04 = arg2;
    alEvtqPostEvent(&arg0->unk48, &sp18, 0);
}

void func_80738230(Struct80738320 *arg0, u8 arg1, u8 arg2) {
    ALEvent sp18;

    sp18.type = AL_SEQP_MIDI_EVT;
    sp18.msg.midi.ticks = 0;
    sp18.msg.midi.status = arg1 | 0xB0;
    sp18.msg.midi.byte1 = 0x5C;
    sp18.msg.midi.byte2 = arg2;
    alEvtqPostEvent(&arg0->unk48, &sp18, 0);
}
