#include "common.h"

void func_global_asm_80738170(ALSeqPlayer *seqp, u8 arg1, u8 arg2) {
    ALEvent sp18;

    sp18.type = AL_SEQP_MIDI_EVT;
    sp18.msg.midi.ticks = 0;
    sp18.msg.midi.status = arg1 | 0xB0;
    sp18.msg.midi.byte1 = 0x5B;
    sp18.msg.midi.byte2 = arg2;
    alEvtqPostEvent(&seqp->evtq, &sp18, 0);
}

void func_global_asm_807381D8(ALSeqPlayer *seqp, f32 arg1, f32 arg2) {
    N_ALEvent sp18;

    sp18.type = AL_18_EVT;
    sp18.msg.evt18.unk00 = arg1;
    sp18.msg.evt18.unk04 = arg2;
    alEvtqPostEvent(&seqp->evtq, &sp18, 0);
}

void func_global_asm_80738230(ALSeqPlayer *seqp, u8 arg1, u8 arg2) {
    ALEvent sp18;

    sp18.type = AL_SEQP_MIDI_EVT;
    sp18.msg.midi.ticks = 0;
    sp18.msg.midi.status = arg1 | 0xB0;
    sp18.msg.midi.byte1 = 0x5C;
    sp18.msg.midi.byte2 = arg2;
    alEvtqPostEvent(&seqp->evtq, &sp18, 0);
}
