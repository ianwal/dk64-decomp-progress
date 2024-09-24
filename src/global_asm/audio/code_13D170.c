#include <ultra64.h>
#include "functions.h"



u32 func_global_asm_8073928C(ALCSeq *, u32);

void func_global_asm_80738470(ALCSeq *seq, ALCMidiHdr *music_midi_bin) {
    // alCSeqNew
    u32 i;
    u32 tmpOff;
    s32 track_bitfield;

    seq->base = music_midi_bin;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    seq->deltaFlag = 1;
    for (i = 0; i < 0x10U; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = 0;
        seq->curBULen[i] = 0;
        tmpOff = seq->base->trackOffset[i];
        if (tmpOff) {
            track_bitfield = 1 << i;
            seq->validTracks |= track_bitfield;
            seq->curLoc[i] = (u8*)((u32)music_midi_bin + tmpOff);
            seq->evtDeltaTicks[i] = func_global_asm_8073928C(seq, i);
        } else {
            seq->curLoc[i] = 0;
        }
    }
    seq->qnpt = 1.0f / seq->base->division;
}

void func_global_asm_807385F0(ALCSeq *arg0, ALEvent *arg1, s32 arg2) {
    // alCSeqNextEvent
    u32 i;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    u32 temp_t7;

    sp30 = -1U;
    sp28 = arg0->lastDeltaTicks;
    for (i = 0; i < 0x10U; i++) {
        if ((arg0->validTracks >> i) & 1) {
            if (arg0->deltaFlag != 0) {
                arg0->evtDeltaTicks[i] -= sp28;
            }
            if (arg0->evtDeltaTicks[i] < sp30) {
                sp30 = arg0->evtDeltaTicks[i];
                sp2C = i;
            }
        }
    }
    func_global_asm_8073876C(arg0, sp2C, arg1, arg2);
    arg1->msg.midi.ticks = sp30;
    arg0->lastTicks += sp30;
    arg0->lastDeltaTicks = sp30;
    if (arg1->type != AL_TRACK_END) {
        arg0->evtDeltaTicks[sp2C] += func_global_asm_8073928C(arg0, sp2C);
    }
    arg0->deltaFlag = 1;
}

u8 func_global_asm_80739098(ALCSeq *, s32);

s32 func_global_asm_8073876C(ALCSeq *seq, s32 track, ALEvent *event, s32 arg3) {
    // __alCSeqGetTrackEvent
    u32     offset;
    u8      status, loopCt, curLpCt, *tmpPtr;
    

    status = func_global_asm_80739098(seq,track);     /* read the status byte */

    if (status == AL_MIDI_Meta) /* running status not allowed on meta events!! */
    {
        u8 type = func_global_asm_80739098(seq,track);
        
        if (type == AL_MIDI_META_TEMPO)
        {
            event->type = AL_TEMPO_EVT;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.byte1 = func_global_asm_80739098(seq,track);
            event->msg.tempo.byte2 = func_global_asm_80739098(seq,track);
            event->msg.tempo.byte3 = func_global_asm_80739098(seq,track);
            seq->lastStatus[track] = 0;  /* lastStatus not supported after meta */
        }
        else if (type == AL_MIDI_META_EOT)
        {
            u32     flagMask;
            
            flagMask = 0x01 << track;
            seq->validTracks = seq->validTracks ^ flagMask;
            
            if(seq->validTracks) /* there is music left don't end */
                event->type = AL_TRACK_END;
            else         /* no more music send AL_SEQ_END_EVT msg */
                event->type = AL_SEQ_END_EVT;
        }
        else if (type == AL_CMIDI_LOOPSTART_CODE)
        {
            status = func_global_asm_80739098(seq,track); /* get next two bytes, ignore them */
            event->msg.midi.duration = (status << 8);
            status = func_global_asm_80739098(seq,track);
            event->msg.midi.duration += status;
            seq->lastStatus[track] = 0;
            event->type = AL_CSP_LOOPSTART;
        }
        else if (type == AL_CMIDI_LOOPEND_CODE)
        {
            tmpPtr = seq->curLoc[track];
            loopCt = *tmpPtr++;
            curLpCt = *tmpPtr;
            if((curLpCt == 0) || (arg3 == 0)) /* done looping */
            {
                *tmpPtr = loopCt; /* reset current loop count */
                seq->curLoc[track] = tmpPtr + 5; /* move pointer to end of event */
            }
            else 
            {
                if(curLpCt != 0xFF) /* not a loop forever */
                    *tmpPtr = curLpCt - 1;   /* decrement current loop count */
                tmpPtr++;                    /* get offset from end of event */
                offset = (*tmpPtr++) << 24;
                offset += (*tmpPtr++) << 16;
                offset += (*tmpPtr++) << 8;
                offset += *tmpPtr++;
                seq->curLoc[track] = tmpPtr - offset;
            }
            seq->lastStatus[track] = 0;
            event->type = AL_CSP_LOOPEND;
        }

#ifdef _DEBUG        
        else
            __osError(ERR_ALSEQMETA, 1, type);
#endif
        
    }
    else
    {
        event->type = AL_SEQ_MIDI_EVT;
        if (status & 0x80)  /* if high bit is set, then new status */
        {
            
            event->msg.midi.status = (status & 0xF0) | track;
            event->msg.midi.byte1 = func_global_asm_80739098(seq,track);
            seq->lastStatus[track] = event->msg.midi.status;
        }
        else     /* running status */
        {
#ifdef _DEBUG
            if(seq->lastStatus[track] == 0)
                __osError(ERR_ALCSEQZEROSTATUS, 1, track);
#endif
            event->msg.midi.status = seq->lastStatus[track];
            event->msg.midi.byte1 = status;
        }
        
        if (((event->msg.midi.status & 0xf0) != AL_MIDI_ProgramChange) &&
            ((event->msg.midi.status & 0xf0) != AL_MIDI_ChannelPressure))
        {
            event->msg.midi.byte2 = func_global_asm_80739098(seq,track);
            if((event->msg.midi.status & 0xf0) == AL_MIDI_NoteOn)
            {
                event->msg.midi.duration = func_global_asm_8073928C(seq,track);
#ifdef _DEBUG                
                if(event->msg.midi.byte2 == 0)
                    __osError( ERR_ALCSEQZEROVEL, 1, track);
#endif                
            }
        }
        else
            event->msg.midi.byte2 = 0;
    }
    return TRUE;
}

u32 func_global_asm_80738BA0(ALCSeq *seq) {
    return seq->lastTicks;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13D170/func_global_asm_80738BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13D170/func_global_asm_80738C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13D170/func_global_asm_80738D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13D170/func_global_asm_80738E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13D170/func_global_asm_80739098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_13D170/func_global_asm_8073928C.s")

