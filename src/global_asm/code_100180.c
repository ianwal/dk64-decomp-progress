#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x17C - 0x0];
    s16 unk17C;
    u8 unk17E;
} Struct80754A18;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
} Struct80754A34;

extern s32 *D_global_asm_807FD7F0; // Array of 43 texture pointers
extern u8 *D_global_asm_807FD7F4; // Array of 43 u8's
extern Struct80754A18 *D_global_asm_80754A18;
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
    func_global_asm_806FB490(D_global_asm_80754A18->unk17E, arg0, D_global_asm_807FD7F0[2], D_global_asm_80754A18->unk17C, 2, &sp2F, 0x30);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FB914.s")

void func_global_asm_806FBB58(void) {
    D_global_asm_807FD7F0 = malloc(sizeof(s32) * 43);
    func_global_asm_80611690(D_global_asm_807FD7F4 = malloc(sizeof(u8) * 43));
}

s32 func_global_asm_806FBB9C(s16 textureIndex) {
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
    s16 i;
    s16 k;
    s16 j;
    Struct80754A34 *temp_s3;

    i = 0;
    for (j = 0; j < 8; j++) {
        for (k = 0; k < D_global_asm_80754A34[j].unk1; k++) {
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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FBEF0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/printStyledText.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FCC88.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FD094.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FD490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_global_asm_806FD7A8.s")

u8 func_global_asm_806FD894(s16 arg0) {
    if (arg0 & 0x80) {
        arg0 ^= 0x80;
    }
    return D_global_asm_80754A34[arg0].unk2;
}
