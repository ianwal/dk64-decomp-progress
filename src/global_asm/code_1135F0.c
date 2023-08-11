#include <ultra64.h>
#include "functions.h"

extern uSprite *D_global_asm_807550D0;

extern s16 D_global_asm_807FD9D0; //sx
extern s16 D_global_asm_807FD9D2; //sy
extern u8 D_global_asm_807FD9D4;  //fx
extern u8 D_global_asm_807FD9D5;  //fy

#ifndef NONMATCHING
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1135F0/func_global_asm_8070E8F0.s")
#else
void func_global_asm_8070E8F0(Gfx **arg0, uSprite *arg1) {
    D_global_asm_807550D0 = arg1;
    D_global_asm_807FD9D0 = 0x400;
    D_global_asm_807FD9D2 = 0x400;
    D_global_asm_807FD9D4 = 0;
    D_global_asm_807FD9D5 = 0;
    switch (D_global_asm_807550D0->s.SourceImageBitSize) {
        case G_IM_SIZ_8b: //L8070E96C
            if ((D_global_asm_807550D0->s.Stride & 7) == 0) {
                gDPLoadTextureBlock((*arg0)++,D_global_asm_807550D0->s.SourceImagePointer, D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, D_global_asm_807550D0->s.SubImageHeight, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            } else {//L8070EB34
                gDPLoadTextureBlock((*arg0)++,D_global_asm_807550D0->s.SourceImagePointer, D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, D_global_asm_807550D0->s.SubImageHeight, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            }
            break;
        case G_IM_SIZ_16b: //L8070EC7C
            if ((D_global_asm_807550D0->s.Stride & 3) == 0) {
                gDPLoadTextureBlock((*arg0)++,D_global_asm_807550D0->s.SourceImagePointer, D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_16b, 
                    D_global_asm_807550D0->s.SubImageWidth, D_global_asm_807550D0->s.SubImageHeight, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            } else {//L8070EB34
                gDPLoadTextureBlock((*arg0)++,D_global_asm_807550D0->s.SourceImagePointer, D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, D_global_asm_807550D0->s.SubImageHeight, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            }
            break;
        case G_IM_SIZ_32b: //L8070EF94
            if ((D_global_asm_807550D0->s.Stride & 3) == 0) {
                gDPLoadTextureBlock((*arg0)++,D_global_asm_807550D0->s.SourceImagePointer, D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_32b, 
                    D_global_asm_807550D0->s.SubImageWidth, D_global_asm_807550D0->s.SubImageHeight, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            } else {
                gDPLoadTextureBlock((*arg0)++,D_global_asm_807550D0->s.SourceImagePointer, D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, D_global_asm_807550D0->s.SubImageHeight, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            }
            break;
    }
}
#endif

// TODO: This signature is sus
void func_global_asm_8070F2C8(s16 arg0, s16 arg1, u8 arg2, u8 arg3) {
    D_global_asm_807FD9D0 = arg0;
    D_global_asm_807FD9D2 = arg1;
    D_global_asm_807FD9D4 = arg2;
    D_global_asm_807FD9D5 = arg3;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1135F0/func_global_asm_8070F2FC.s")
