#include <ultra64.h>
#include "functions.h"


void guMtxF2L(f32 mf[4][4], Mtx *m) {
    s32 r, c;
    s32 tmp1;
    s32 tmp2;
    s32 *m1 = &m->m[0][0];
    s32 *m2 = &m->m[2][0];
    for (r = 0; r < 4; r++) {
        for (c = 0; c < 2; c++) {
            tmp1 = mf[r][2 * c] * 65536.0f;
            tmp2 = mf[r][2 * c + 1] * 65536.0f;
            *m1++ = (tmp1 & 0xffff0000) | ((tmp2 >> 0x10) & 0xffff);
            *m2++ = ((tmp1 << 0x10) & 0xffff0000) | (tmp2 & 0xffff);
        }
    }
}

void guMtxIdentF(f32 (*mf)[4]) {
    s32 r, c;
    for (r = 0; r < 4; r++) {
        for (c = 0; c < 4; c++) {
            if (r == c) {
                mf[r][c] = 1.0f;
            } else {
                mf[r][c] = 0.0f;
            }
        }
    }
}

void guMtxL2F(float mf[4][4], Mtx *m)
{
	int		i, j;
	unsigned int	e1,e2;
	unsigned int	*ai,*af;
	int		q1,q2;

	ai=(unsigned int *) &m->m[0][0];
	af=(unsigned int *) &m->m[2][0];

	for (i=0; i<4; i++)
	for (j=0; j<2; j++) {
		e1 = (*ai & 0xffff0000) | ((*af >> 16) & 0xffff);
		e2 = ((*(ai++) << 16) & 0xffff0000) | (*(af++) & 0xffff);
		q1 = *((int *)&e1); 
		q2 = *((int *)&e2); 

		mf[i][j*2] = FIX32TOF(q1);
		mf[i][j*2+1] = FIX32TOF(q2);
	}
}

void guMtxIdent(Mtx *m) {
    Mtx sp18;

    guMtxIdentF(&sp18);
    guMtxF2L(&sp18, m);
}
