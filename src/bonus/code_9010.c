#include <ultra64.h>
#include "functions.h"

extern s8 D_bonus_8002D910[];
extern s8 D_bonus_8002D91C[];
extern s8 D_bonus_8002D920;
extern s8 D_bonus_8002D924;
extern s8 D_bonus_8002D928;
extern s8 D_bonus_8002D92C;
extern s8 D_bonus_8002D930;
extern s8 D_bonus_8002DEF0[];

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_bonus_8002D010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_bonus_8002D2F0.s")

void func_bonus_8002D6F8(s16 arg0) {
    s32 var_v1_2;
    s32 i;
    s32 j;

    D_bonus_8002D928 = 5;
    j = 0;
    do {
        if (arg0 == D_bonus_8002D91C[j]) {
            D_bonus_8002D928 += 0xF;
        }
        j++; // TODO: Ouch...
        j--; // TODO: Ouch...
    } while (++j < 4);
    i = 0;
    while (i < 0xA && arg0 != D_bonus_8002D910[i]) {
        i++;
    }
    var_v1_2 = i - 1;
    if (var_v1_2 < 0) {
        var_v1_2 = 0xA;
    }
    if (var_v1_2 == D_bonus_8002D920) {
        D_bonus_8002D924++;
        if (D_bonus_8002D924 >= 0xA) {
            D_bonus_8002D924 = 0;
            D_bonus_8002D928 += 0x32;
        }
    } else {
        D_bonus_8002D924 = 0;
    }
    D_bonus_8002D920 = i;
}

void func_bonus_8002D7E8(s16 arg0) {
    s8 phi_v0 = arg0 == 0xD4 ? 0xA : 2;

    if (D_bonus_8002D92C < 6) {
        D_bonus_8002DEF0[D_bonus_8002D92C] = phi_v0;
        D_bonus_8002D92C++;
        D_bonus_8002D930 = 0x14;
    }
    if (D_bonus_8002D92C >= 5) {
        D_bonus_8002D930 = 0;
    }
}
