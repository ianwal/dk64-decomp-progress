#include <ultra64.h>
#include "functions.h"


void func_806FB480(void) {

}

void func_806FB488(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FB490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FB714.s")

s32 func_806FB490(u8, s32, s32, s16, s32, s8 *, s32);

typedef struct {
    u8 unk0[0x17C - 0x0];
    s16 unk17C;
    u8 unk17E;
} Struct80754A18;

extern s32 *D_807FD7F0; // Array of 43 texture pointers
extern u8 *D_807FD7F4; // Array of 43 u8's
extern Struct80754A18 *D_80754A18;

void func_806FB8B0(s32 arg0) {
    s8 sp2F;

    sp2F = 0;
    func_806FBB9C(2);
    func_806FB490(D_80754A18->unk17E, arg0, D_807FD7F0[2], D_80754A18->unk17C, 2, &sp2F, 0x30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FB914.s")

void func_806FBB58() {
    D_807FD7F0 = malloc(sizeof(s32) * 43);
    func_80611690(D_807FD7F4 = malloc(sizeof(u8) * 43));
}

s32 func_806FBB9C(s16 textureIndex) {
    if (!D_807FD7F4[textureIndex]) {
        // Texture
        D_807FD7F0[textureIndex] = getPointerTableFile(0xE, textureIndex, 1, 1);
        D_807FD7F4[textureIndex] = 3;
    } else {
        D_807FD7F4[textureIndex] = 3;
    }
    return D_807FD7F0[textureIndex];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FBC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FBD5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FBEAC.s")

/*
// TODO: Doable, hmm
s16 func_806FBEAC(u8 *arg0) {
    s16 count;
    u8 temp_v0;
    u8 *var_a0;

    count = 0;
    var_a0 = &arg0[1];
    if (arg0[0] != 0) {
        do {
            if (var_a0[-1] != 0x20) {
                count++;
            }
            temp_v0 = var_a0[0];
            var_a0++;
        } while (temp_v0 != 0);
    }
    return count;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FBEF0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FC530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FCC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FD094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FD490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FD7A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_100180/func_806FD894.s")

extern u8 D_80754A34[];

/*
// TODO: Very odd regalloc, might need a struct array at D_80754A34
u8 func_806FD894(s16 arg0) {
    if (arg0 & 0x80) {
        arg0 ^= 0x80;
    }
    return D_80754A34[(arg0 * 4 - arg0 << 1) + 2];
}
*/
