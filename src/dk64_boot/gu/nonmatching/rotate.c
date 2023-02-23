#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/gu/nonmatching/rotate/guRotateF.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/gu/nonmatching/rotate/guRotate.s")

/*
void guRotate(Mtx *m, float a, float x, float y, float z) {
    float sp20[4][4];
    guRotateF(&sp20, a, x, y, z);
    guMtxF2L(&sp20, m);
}
*/
