#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/gu/nonmatching/lookathil/guLookAtHiliteF.s")

void guLookAtHilite(Mtx *m, LookAt *l, Hilite *h, float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp, float xl1, float yl1, float zl1, float xl2, float yl2, float zl2, int twidth, int theight) {
    float sp58[4][4];
    guLookAtHiliteF(&sp58[0], l, h, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp, xl1, yl1, zl1, xl2, yl2, zl2, twidth, theight);
    guMtxF2L(&sp58[0], m);
}
