#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/gu/nonmatching/position/guPositionF.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/gu/nonmatching/position/guPosition.s")

/*
// TODO: Not sure why this doesn't match
// Calling convention? Compiler flag?
void guPosition(Mtx *m, float r, float p, float h, float s, float x, float y, float z) {
    float mf[4][4];
    guPositionF(&mf, r, p, h, s, x, y, z);
    guMtxF2L(&mf, m);
}
*/
