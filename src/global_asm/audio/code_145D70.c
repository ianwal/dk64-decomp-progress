#include <ultra64.h>
#include "functions.h"
#include "synthinternal.h"

typedef struct CustomPVoice {
    ALLink node;
    u8 pad8[0x2C - 0x8];
    ALResampler resampler;
} CustomPVoice;

Acmd *func_global_asm_80740100(CustomPVoice *, s16 *, s32, Acmd *);
extern f64 D_global_asm_80760580;
extern f32 D_global_asm_80760588;

void *func_global_asm_80741070(CustomPVoice *arg0, s16 *arg1, Acmd *arg2) {
    Acmd *sp34;
    s16 sp32;
    s32 sp2C;
    s32 sp28;
    f32 sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp34 = arg2;
    sp32 = 0x170;
    if (arg0->resampler.upitch != 0) {
        sp34 = func_global_asm_80740100(arg0, &sp32, 0xB8, arg2);
        sp20 = sp34++;
        sp20->words.w0 = (sp32 & 0xFFFFFF) | 0x0A000000;
        sp20->words.w1 = ((*arg1 & 0xFFFF) << 0x10) | 0x170;
        if (1) {}
    } else {
        if (arg0->resampler.ratio > D_global_asm_80760580) {
            arg0->resampler.ratio = D_global_asm_80760588;
        }
        arg0->resampler.ratio = (s32) (arg0->resampler.ratio * 32768.0f);
        arg0->resampler.ratio /= 32768.0f;
        sp24 = arg0->resampler.delta + (arg0->resampler.ratio * 184.0f);
        sp2C = (s32) sp24;
        arg0->resampler.delta = sp24 - sp2C;
        sp34 = func_global_asm_80740100(arg0, &sp32, sp2C, arg2);
        sp28 = arg0->resampler.ratio * 32768.0f;
        sp1C = sp34++;
        sp1C->words.w0 = (osVirtualToPhysical(arg0->resampler.state) & 0xFFFFFF) | 0x05000000;
        sp1C->words.w1 = ((arg0->resampler.first & 3) << 0x1E) | ((sp28 & 0xFFFF) << 0xE) | ((sp32 & 0xFFF) * 4);
        arg0->resampler.first = 0;
    }
    return sp34;
}

void func_global_asm_807407A8(void*, s32, void*);

s32 func_global_asm_807412B4(void* arg0, s32 arg1, void* arg2) {
    void* sp1C;

    sp1C = arg0;
    if (1) {} else {}
    func_global_asm_807407A8(arg0, arg1, arg2);
    if (1) {} else {}
    return 0;
}
