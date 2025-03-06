#include "common.h"
#include "synthinternal.h"

extern u8 D_global_asm_807FF0F4[2];
extern u8 D_global_asm_807FF0F6[2];

Acmd *func_global_asm_8073FD90(s32 arg0, Acmd *arg1) {
    Acmd *sp4C;
    s32 sp48;
    s32 pad0;
    Acmd *sp40;
    Acmd *sp3C;
    Acmd *sp38;
    Acmd *sp34;
    Acmd *sp30;
    Acmd *sp2C;
    Struct8073BC74 *sp28;
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp4C = arg1;
    sp40 = sp4C++;
    sp40->words.w0 = 0x020004E0;
    sp40->words.w1 = 0x2E0;
    for (sp48 = 0; sp48 < n_syn->maxAuxBusses; sp48++) {
        sp4C = ((N_ALMAinBus *)n_syn->mainBus)->handler(arg0, sp4C, sp48);
        if (D_global_asm_807FF0F4[sp48] != 0) {
            if (D_global_asm_807FF0F6[sp48] != 0) {
                sp3C = sp4C++;
                sp3C->words.w0 = 0x0C008000;
                sp3C->words.w1 = 0x07C004E0;
                if (1) {}
            } else {
                sp38 = sp4C++;
                sp38->words.w0 = 0x0C007FFF;
                sp38->words.w1 = 0x07C00650;
                if (1) {}
            }
        } else {
            if (D_global_asm_807FF0F6[sp48] != 0) {
                sp34 = sp4C++;
                sp34->words.w0 = 0x0C008000;
                sp34->words.w1 = 0x07C00650;
                if (1) {}
            } else {
                sp30 = sp4C++;
                sp30->words.w0 = 0x0C007FFF;
                sp30->words.w1 = 0x07C00650;
                if (1) {}
            }
            sp2C = sp4C++;
            sp2C->words.w0 = 0x0C007FFF;
            sp2C->words.w1 = 0x07C004E0;
        }
        if (((Struct8073BC74_auxbus *)n_syn->auxBus)[sp48].unk44->unk2 > 0) {
            sp28 = ((Struct8073BC74_auxbus *)n_syn->auxBus)[sp48].unk44;
            if (sp28->unk28 != 0) {
                func_global_asm_8073BE54(sp28, n_syn->outputRate);
            }
            sp24 = sp4C++;
            sp24->words.w0 = 0x0B000020;
            sp24->words.w1 = osVirtualToPhysical(sp28->unk8);
            sp20 = sp4C++;
            sp20->words.w0 = 0x0E0004E0;
            sp20->words.w1 = osVirtualToPhysical(sp28->unk2C) & 0xFFFFFF & 0xFFFFFF;
            sp1C = sp4C++;
            sp1C->words.w0 = 0x0E000650;
            sp1C->words.w1 = osVirtualToPhysical(sp28->unk30) & 0xFFFFFF & 0xFFFFFF;
            sp28->unk28 = 0;
        }
    }
    return sp4C;
}
