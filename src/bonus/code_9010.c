#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s8 D_8002D92C;
extern s8 D_8002D930;
extern s8 D_8002DEF0[];

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_9010/func_8002D6F8.s")

/*
extern s8 D_8002D910[];
extern s8 D_8002D91C[];
extern s8 D_8002D920;
extern s8 D_8002D924;
extern s8 D_8002D928;

void func_8002D6F8(s16 arg0) {
    s32 var_v1_2;
    s8 *var_v1;
    s8 temp_t9;
    s32 i;

    D_8002D928 = 5;
    var_v1 = &D_8002D91C;
    do {
        temp_t9 = *var_v1;
        var_v1++;
        if (arg0 == temp_t9) {
            D_8002D928 += 0xF;
        }
    } while (var_v1 < &D_8002D920);
    i = 0;
    if (arg0 != D_8002D910[0]) {
loop_5:
        i++;
        if (i < 0xA) {
            if (arg0 != D_8002D910[i]) {
                goto loop_5;
            }
        }
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
