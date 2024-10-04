#include <ultra64.h>
#include "functions.h"

ALEventListItem *func_global_asm_80732444(s32, s32, s32, u8, s32); /* extern */
s32 func_global_asm_80733180(void *);
void func_global_asm_80737F40(ALCSPlayer *);
void func_global_asm_8073AA74(ALCSPlayer *);

void func_global_asm_80732F10(ALCSPlayer *seqp, ALSeqpConfig *c) {
    // alCSPNew
    s32 i;
    u8 pad[8];
    ALEventListItem *items;
    ALVoiceState *vs;
    ALVoiceState *voices;

    ALHeap *hp = c->heap;

    seqp->bank = 0;
    seqp->target = 0;
    seqp->drvr = n_syn;
    seqp->chanMask = 0xFFFF;
    func_global_asm_80737F40(seqp);
    seqp->uspt = 0x1E8;
    seqp->nextDelta = 0;
    seqp->state = AL_STOPPED;
    seqp->vol = 0x7FFF;
    seqp->debugFlags = c->debugFlags;
    seqp->frameTime = AL_USEC_PER_FRAME;
    seqp->curTime = 0;
    seqp->initOsc = c->initOsc;
    seqp->updateOsc = c->updateOsc;
    seqp->stopOsc = c->stopOsc;
    seqp->unk7C = 0.0f;
    seqp->unk80 = 1.0f;
    seqp->unk84 = 0;
    seqp->unk89 = 0;
    seqp->unk88 = c->maxVoices;
    seqp->nextEvent.type = AL_SEQP_API_EVT;
    seqp->maxChannels = c->maxChannels;
    seqp->chanState = func_global_asm_80732444(0, 0, hp, c->maxChannels, 0x34);
    func_global_asm_8073AA74(seqp);
    voices = func_global_asm_80732444(0, 0, hp, c->maxVoices, sizeof(ALVoiceState));
    seqp->vFreeList = NULL;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;
    }
    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;
    items = func_global_asm_80732444(0, 0, hp, c->maxEvents, 0x1C);
    alEvtqNew(&seqp->evtq, items, c->maxEvents);
    seqp->node.next = NULL;
    seqp->node.handler = func_global_asm_80733180;
    seqp->node.clientData = seqp;
    func_global_asm_8073B640(seqp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733180.s")

extern void func_global_asm_80733D8C(ALCSPlayer *, ALEvent *);
extern void func_global_asm_807359A0(ALCSPlayer *);
extern void func_global_asm_80735624(ALCSPlayer *, ALEvent *);

void func_global_asm_80733A88(ALCSPlayer *seqp) {
    // __CSPHandleNextSeqEvent
    ALEvent	evt;

    /* sct 1/5/96 - Do nothing if we don't have a target sequence. */
    if (seqp->target == NULL)
	return;

    func_global_asm_807385F0(seqp->target, &evt, 1);

    switch (evt.type)
    {
      case AL_SEQ_MIDI_EVT:
          func_global_asm_80733D8C(seqp, &evt);
	  func_global_asm_807359A0(seqp);
	  break;

      case AL_TEMPO_EVT:
          func_global_asm_80735624(seqp, &evt);
	  func_global_asm_807359A0(seqp);
	  break;

      case AL_SEQ_END_EVT:
	  seqp->state = AL_STOPPING;      
	  evt.type    = AL_SEQP_STOP_EVT;
	  alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
	  break;

      case AL_TRACK_END:
      case AL_CSP_LOOPSTART:
      case AL_CSP_LOOPEND:
	  func_global_asm_807359A0(seqp);
	  break;
      default:
      break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733C34.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/csplayer/func_global_asm_80733D8C.s")

extern void func_global_asm_80735958(ALCSPlayer *, f32);
extern void  func_global_asm_80735864(ALEventQueue *, ALEventListItem *);

void func_global_asm_80735624(ALCSPlayer *seqp, ALEvent *event) {
    // __CSPHandleMetaMsg
    ALTempoEvent    *tevt = &event->msg.tempo;
    // ALEvent         evt;
    s32             tempo;
    s32             oldUspt;
    u32             ticks;
    ALMicroTime         tempDelta,curDelta = 0;
    ALEventListItem     *thisNode,*nextNode,*firstTemp = 0;


    if (event->msg.tempo.status == AL_MIDI_Meta)
    {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO)
        {
	    oldUspt = seqp->uspt;
	    tempo = (tevt->byte1 << 16) | (tevt->byte2 <<  8) | (tevt->byte3 <<  0);
	    func_global_asm_80735958(seqp, (f32)tempo);	/* sct 1/8/96 */

	    thisNode = (ALEventListItem*)seqp->evtq.allocList.next;
	    while(thisNode)
	    {
		curDelta += thisNode->delta;
		nextNode = (ALEventListItem*)thisNode->node.next;
		if(thisNode->evt.type == AL_CSP_NOTEOFF_EVT)
		{
		    alUnlink((ALLink*)thisNode);

		    if(firstTemp)
			alLink((ALLink*)thisNode,(ALLink*)firstTemp);
		    else
		    {
			thisNode->node.next = 0;
			thisNode->node.prev = 0;
			firstTemp = thisNode;
		    }
		    tempDelta = curDelta;         /* record the current delta */
		    if(nextNode) /* don't do this if no nextNode */
		    {
			curDelta -= thisNode->delta;  /* subtract out this delta */
			nextNode->delta += thisNode->delta; /* add it to next event */
		    }
		    thisNode->delta = tempDelta; /* set this event delta from current */
		}
		thisNode = nextNode;
	    }

	    thisNode = firstTemp;
	    while(thisNode)
	    {
		nextNode = (ALEventListItem*)thisNode->node.next;
		ticks = thisNode->delta/oldUspt;
		thisNode->delta = ticks * seqp->uspt;
		func_global_asm_80735864(&seqp->evtq,thisNode);
		thisNode = nextNode;
	    }
        }
    }
}

void  func_global_asm_80735864(ALEventQueue *evtq, ALEventListItem *item) {
    // __CSPRepostEvent
    OSIntMask           mask;
    ALLink              *node;
    ALEventListItem     *nextItem;
    
    mask = osSetIntMask(OS_IM_NONE);

    for (node = &evtq->allocList; node != 0; node = node->next)
    {
        if (!node->next)  /* end of the list */
        {
            alLink((ALLink *)item, node);
            break;
        }
        else
        {
            nextItem = (ALEventListItem *)node->next;
            if (item->delta < nextItem->delta)
            {
                nextItem->delta -= item->delta;
                alLink((ALLink *)item, node);
                break;
            }
            item->delta -= nextItem->delta;
        }
    }
    osSetIntMask(mask);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
} Struct80735958_unk18;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    Struct80735958_unk18* unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} Struct80735958;

void func_global_asm_80735958(ALCSPlayer *seqp, f32 tempo) {
    // __setUsptFromTempo
    if (seqp->target) {
        seqp->uspt = ((f32)tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 0x1E8;
    }
}