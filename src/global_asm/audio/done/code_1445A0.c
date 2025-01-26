#include <ultra64.h>
#include "functions.h"
#include "n_synthInternals.h"

s32 *func_global_asm_8073E8C0(Struct8073BC74_auxbus_unk1C *, s32, Acmd *);     /* extern */

s32 *func_global_asm_8073F8A0(s32 arg0, Acmd *arg1, s32 arg2, s32 *arg3) {
    Acmd *sp44;
    Struct8073BC74_auxbus *sp40;
    Struct8073BC74_auxbus_unk1C **sp3C;
    u32 i;
    s32 sp34;
    u32 sp30;
    u32 sp2C;
    Acmd *sp28;
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp44 = arg1;
    sp40 = &n_syn->auxBus[arg2];
    sp3C = sp40->unk1C;
    sp34 = 0;
    sp30 = 1;
    sp28 = sp44++;
    sp28->words.w0 = 0x020007C0;
    sp28->words.w1 = 0x2E0;
    *arg3 = 0;
    for (i = 0; i < sp40->unk14; i++) {
        if (
            (sp3C[i]->next != NULL) && 
            (sp3C[i]->next->unk18 == arg2) && 
            (sp3C[i]->next->next != NULL) && 
            (sp3C[i]->next->next->unk8C >= 0x40)) {
            sp44 = func_global_asm_8073E8C0(sp3C[i], arg0, sp44);
            *arg3 += 1;
            sp34++;
            if (sp3C[i]->next->next->unk8C > sp30) {
                sp30 = sp3C[i]->next->next->unk8C;
            }
        }
    }
    if (sp34) {
        sp30 -= 0x3E;
        if (sp30 >= 7U) {
            sp2C = 26755.0f / sqrtf(sp30);
        } else {
            sp2C = 65536.0f / sp30;
        }
        sp24 = sp44++;
        sp24->words.w0 = 0x4E0;
        sp24->words.w1 = (s32) (((sp2C & 0xFFFF) << 0x10) | (sp30 & 0xFFFF));
        sp20 = sp44++;
        sp20->words.w0 = 0x650;
        sp20->words.w1 = (s32) (((sp2C & 0xFFFF) << 0x10) | (sp30 & 0xFFFF));
    }
    for (i = 0; i < sp40->unk14; i++) {
        if ((
            (sp3C[i]->next != NULL) && 
            (sp3C[i]->next->unk18 == arg2) && 
            (((sp3C[i]->next->next == NULL)) ||
            (sp3C[i]->next->next->unk8C < 0x40))) || 
            ((sp3C[i]->next == 0) && (arg2 == 0))) {
            sp1C = sp44;
            sp44 = func_global_asm_8073E8C0(sp3C[i], arg0, sp44);
            if (sp44 != sp1C) {
                *arg3 += 1;
            }
        }
    }
    return sp44;
}
