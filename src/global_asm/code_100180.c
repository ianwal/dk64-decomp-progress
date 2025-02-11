#include <ultra64.h>
#include "functions.h"

// rodata
static const u32 D_global_asm_8075DC20[] = {
    0x41424344,
    0x45464748,
    0x494A4B4C,
    0x4D4E4F50,
    0x51525354,
    0x55565758,
    0x595A2E2D,
    0x3F7B7D3A,
    0x3D303132,
    0x33343536,
    0x3738393C,
    0x3E6D2921,
    0x40232425,
    0x5E266361,
    0x62000000,
};

typedef struct {
    s16 x_start;
    u8 width;
    u8 unk3;
} Struct80754A18_inner;

typedef struct {
    Struct80754A18_inner character[96];
} Struct80754A18;

extern void **D_global_asm_807FD7F0; // Array of 43 texture pointers
extern u8 *D_global_asm_807FD7F4; // Array of 43 u8's
extern Struct80754A18 *D_global_asm_80754A18[7];
extern Struct80754A34 D_global_asm_80754A34[];

s32 func_global_asm_806FB490(u8, s32, s32, s16, s32, s8 *, s32);

void func_global_asm_806FB480(void) {

}

void func_global_asm_806FB488(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FB490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FB714.s")

void func_global_asm_806FB8B0(s32 arg0) {
    s8 sp2F;

    sp2F = 0;
    func_global_asm_806FBB9C(2);
    func_global_asm_806FB490(D_global_asm_80754A18[0]->character[0x5F].width, arg0, D_global_asm_807FD7F0[2], D_global_asm_80754A18[0]->character[0x5F].x_start, 2, &sp2F, 0x30);
}

// Jumptable, doable, string processing
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FB914.s")

void func_global_asm_806FBB58(void) {
    D_global_asm_807FD7F0 = malloc(sizeof(s32) * 43);
    func_global_asm_80611690(D_global_asm_807FD7F4 = malloc(sizeof(u8) * 43));
}

void *func_global_asm_806FBB9C(s16 textureIndex) {
    if (!D_global_asm_807FD7F4[textureIndex]) {
        // Texture
        D_global_asm_807FD7F0[textureIndex] = getPointerTableFile(0xE, textureIndex, 1, 1);
        D_global_asm_807FD7F4[textureIndex] = 3;
    } else {
        D_global_asm_807FD7F4[textureIndex] = 3;
    }
    return D_global_asm_807FD7F0[textureIndex];
}

void func_global_asm_806FBC34(void) {
    s16 i, k, j;

    i = 0;
    for (j = 0; j < 8; j++) {
        for (k = 0; k < D_global_asm_80754A34[j].file_count; k++) {
            if (D_global_asm_807FD7F4[i++]) {
                if (--D_global_asm_807FD7F4[i - 1] == 0) {
                    func_global_asm_8066B434(D_global_asm_807FD7F0[i - 1], 0x156, 0x23);
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/getCenterOfString.s")

s16 func_global_asm_806FBEAC(u8 *arg0) {
    s16 count;

    count = 0;
    while (*arg0++) {
        if (arg0[-1] != 0x20) {
            count++;
        }
    }
    return count;
}

Gfx *func_global_asm_806FBEF0(Gfx *dl, u8 arg1, s16 arg2) {
    s16 textureIndex;

    textureIndex = (D_global_asm_80754A34[arg1].width + arg2) - 1;
    func_global_asm_806FBB9C(textureIndex);
    switch (arg1) {
        case 6:
            gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1143, 94);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 22, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x02BC, 0x0030);
            break;
        case 0:
            gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 2047, 64);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_4b, 32, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x07FC, 0x003C);\
            break;
        case 1:
            gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1823, 108);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 19, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x012C, 0x005C);\
            break;
        case 2:
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 64);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_4b, 32, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x07FC, 0x001C);\
            break;
        case 3:
        case 7:
            gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 256);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);\
            break;
        case 4:
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 2047, 32);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_4b, 64, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x0FFC, 0x001C);\
            break;
        case 5:
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (s32)D_global_asm_807FD7F0[textureIndex] + 0x80000000);\
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPLoadSync(dl++);\
            gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 2047, 32);\
            gDPPipeSync(dl++);\
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_4b, 64, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);\
            gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x0FFC, 0x001C);\
            break;
    }
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/printStyledText.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FCC88.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FD094.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FD490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FD7A8.s")

s32 func_global_asm_806FB914(s16, u8 *, s32);

/*
s16 func_global_asm_806FD7A8(s16 arg0, u8 arg1) {
    Struct80754A34 *var_a0;
    Struct80754A18 *text_data;
    s32 temp_a2;
    u8 var_v1;
    s32 val;

    temp_a2 = arg0;
    if (arg0 & 0x80) {
        var_a0 = &D_global_asm_80754A34[(s16) (arg0 ^ 0x80)];
        var_v1 = var_a0->kerning_animation;
    } else if (arg1 == ' ') {
        var_a0 = &D_global_asm_80754A34[temp_a2];
        var_v1 = var_a0->kerning_space;
    } else {
        val = func_global_asm_806FB914(temp_a2, &arg1, temp_a2);
        text_data = D_global_asm_80754A18[arg1];
        var_v1 = text_data->character[temp_a2].width;
        var_a0 = &D_global_asm_80754A34[temp_a2];
    }
    return var_v1 + var_a0->kerning_character;
}
*/

u8 func_global_asm_806FD894(s16 arg0) {
    if (arg0 & 0x80) {
        arg0 ^= 0x80;
    }
    return D_global_asm_80754A34[arg0].height;
}
