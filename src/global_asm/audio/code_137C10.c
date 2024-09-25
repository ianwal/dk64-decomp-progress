#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80732F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733C34.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/audio/code_137C10/func_global_asm_80733D8C.s")

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