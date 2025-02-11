#include <ultra64.h>
#include "functions.h"

extern uSprite *D_global_asm_807550D0;

extern s16 D_global_asm_807FD9D0; //sx
extern s16 D_global_asm_807FD9D2; //sy
extern u8 D_global_asm_807FD9D4;  //fx
extern u8 D_global_asm_807FD9D5;  //fy

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1135F0/func_global_asm_8070E8F0.s")

/*
void func_global_asm_8070E8F0(Gfx **arg0, uSprite *arg1) {
    Gfx *dl;
    s16 w, h;
    s16 off_s;
    s16 stride;
    s16 temp;

    dl = *arg0;
    D_global_asm_807550D0 = arg1;
    D_global_asm_807FD9D0 = 0x400;
    D_global_asm_807FD9D2 = 0x400;
    D_global_asm_807FD9D4 = 0;
    D_global_asm_807FD9D5 = 0;
    h = D_global_asm_807550D0->s.SubImageHeight;
    off_s = D_global_asm_807550D0->s.SourceImageOffsetS;
    stride = D_global_asm_807550D0->s.Stride;
    temp = h + off_s;
    switch ((u8)D_global_asm_807550D0->s.SourceImageBitSize) {
        case G_IM_SIZ_8b: //L8070E96C
            if ((stride & 7) == 0) {
                gDPLoadTextureBlock(dl++, 
                    D_global_asm_807550D0->s.SourceImagePointer, (u8)D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, h, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            } else {//L8070EB34
                gDPLoadTextureBlock(dl++, 
                    D_global_asm_807550D0->s.SourceImagePointer, (u8)D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, h, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            }
            break;
        case G_IM_SIZ_16b: //L8070EC7C
            if ((stride & 3) == 0) {
                gDPLoadTextureBlock(dl++, 
                    D_global_asm_807550D0->s.SourceImagePointer, (u8)D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_16b, 
                    D_global_asm_807550D0->s.SubImageWidth, h, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            } else {//L8070EB34
                gDPLoadTextureBlock(dl++, 
                    D_global_asm_807550D0->s.SourceImagePointer, (u8)D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, h, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            }
            break;
        case G_IM_SIZ_32b: //L8070EF94
            if ((stride & 3) == 0) {
                gDPLoadTextureBlock(dl++, 
                    D_global_asm_807550D0->s.SourceImagePointer, (u8)D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_32b, 
                    D_global_asm_807550D0->s.SubImageWidth, h, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            } else {
                gDPLoadTextureBlock(dl++, 
                    D_global_asm_807550D0->s.SourceImagePointer, (u8)D_global_asm_807550D0->s.SourceImageType, G_IM_SIZ_8b, 
                    D_global_asm_807550D0->s.SubImageWidth, h, 
                    D_global_asm_807550D0->s.TlutPointer, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD
                );
            }
            break;
    }
}
*/

// TODO: This signature is sus
void func_global_asm_8070F2C8(s16 arg0, s16 arg1, u8 arg2, u8 arg3) {
    D_global_asm_807FD9D0 = arg0;
    D_global_asm_807FD9D2 = arg1;
    D_global_asm_807FD9D4 = arg2;
    D_global_asm_807FD9D5 = arg3;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1135F0/func_global_asm_8070F2FC.s")

/*
void func_global_asm_8070F2FC(Gfx **arg0, s16 arg1, s16 arg2) {
    Gfx *dl;
    s16 temp_t5;
    s16 temp_t6;
    s16 var_t2;
    s16 var_t3;
    s32 temp_f10;
    s32 temp_f10_2;
    s32 var_a0;
    s32 var_v1;

    dl = *arg0;
    if (D_global_asm_807550D0 == NULL) {
        return;
    }
    temp_t5 = D_global_asm_807550D0->s.SubImageWidth;
    temp_t6 = D_global_asm_807550D0->s.SubImageHeight;
    temp_f10 = arg1 * 0.25f;
    temp_f10_2 = arg2 * 0.25f;
    var_v1 = ((D_global_asm_807550D0->s.SourceImageOffsetS - ((arg1 * 0.25f) - temp_f10)) * 32.0f);
    var_a0 = ((D_global_asm_807550D0->s.SourceImageOffsetT - ((arg2 * 0.25f) - temp_f10_2)) * 32.0f);
    if (D_global_asm_807FD9D4) {
        var_v1 += (temp_t5 << 5) - 0x20;
        var_t2 = D_global_asm_807FD9D0 * -1;
    } else {
        var_t2 = D_global_asm_807FD9D0;
    }
    if (D_global_asm_807FD9D5 != 0) {
        var_a0 += (temp_t6 << 5) - 0x20;
        var_t3 = D_global_asm_807FD9D2 * -1;
    } else {
        var_t3 = D_global_asm_807FD9D2;
    }
    gSPTextureRectangle(dl++, temp_f10 * 4, temp_f10_2 * 4, 
        (temp_f10 + (temp_t5 * (1024.0f / D_global_asm_807FD9D0))) * 4.0f,
        (temp_f10_2 + (temp_t6 * (1024.0f / D_global_asm_807FD9D2))) * 4.0f,
        0, var_v1, var_a0, var_t2, var_t3);
}
*/
