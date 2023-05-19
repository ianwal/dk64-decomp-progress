#include <ultra64.h>
#include "functions.h"

extern s8 D_8002D92C;
extern s8 D_8002D930;
extern s8 D_8002DEF0[];

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D6F8.s")

extern s8 D_8002D910[];
extern s8 D_8002D91C[];
extern s8 D_8002D920;
extern s8 D_8002D924;
extern s8 D_8002D928;

/*
// TODO: Very close
void func_8002D6F8(s16 arg0) {
    s32 var_v1_2;
    s8 temp_t9;
    s32 i;
    s32 j;
    s32 max = 4;

    D_8002D928 = 5;
    for (j = 0; j < max; j++) {
        temp_t9 = D_8002D91C[j];
        if (arg0 == temp_t9) {
            D_8002D928 += 0xF;
        }
    }
    i = 0;
    while (i < 0xA && arg0 != D_8002D910[i]) {
        i++;
    }
    var_v1_2 = i - 1;
    if (var_v1_2 < 0) {
        var_v1_2 = 0xA;
    }
    if (var_v1_2 == D_8002D920) {
        D_8002D924++;
        if (D_8002D924 >= 0xA) {
            D_8002D924 = 0;
            D_8002D928 += 0x32;
        }
    } else {
        D_8002D924 = 0;
    }
    D_8002D920 = i;
}
*/

void func_8002D7E8(s16 arg0) {
    s8 phi_v0 = arg0 == 0xD4 ? 0xA : 2;

    if (D_8002D92C < 6) {
        D_8002DEF0[D_8002D92C] = phi_v0;
        D_8002D92C++;
        D_8002D930 = 0x14;
    }
    if (D_8002D92C >= 5) {
        D_8002D930 = 0;
    }
}
