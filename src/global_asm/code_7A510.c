#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675D70.s")

/*
// TODO: Pretty close
void func_80675D70(Actor *arg0) {
    if (D_807FBB70[0].unk200 < 2) {
        D_807FBB70[0].unk1FC = arg0;
        D_807FBB70[0].unk200 = 1;
    }
    if (D_807FBB70[0].unk201 < 0xF) {
        D_807FBB70[D_807FBB70[0].unk201].unk204 = arg0;
        D_807FBB70[D_807FBB70[0].unk201].unk244 = 2;
        D_807FBB70[0].unk201++;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675DD0.s")

/*
void func_80675DD0(void *arg0, void *arg1) {
    u8 temp_v0;
    u8 phi_v0;

    arg0->unk134 -= arg1->unk136;
    if (arg0->unk134 <= 0) {
        D_807FBB70[0].unk200 = 9;
        return;
    }
    temp_v0 = D_807FBB70[0].unk200;
    phi_v0 = temp_v0;
    if (temp_v0 == 6) {
        D_807FBB70[0].unk200 = 4;
        phi_v0 = 4 & 0xFF;
    }
    if (phi_v0 == 7) {
        D_807FBB70[0].unk200 = 5;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675E3C.s")

s32 func_80675C70(s16, s16, s16);

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} GlobalASMStruct57;

/*
// TODO: Astonishingly close, extra NOP
s32 func_80675E3C(GlobalASMStruct57 *arg0, s16 arg1, s16 arg2) {
    s16 temp_s1;
    s32 temp_s2;

    do {
        temp_s1 = arg0->unk0;
        temp_s2 = arg0->unk4;
        if (!func_80675C70(arg1, arg2, temp_s1)) {
            arg0++;
        }
    } while (temp_s1);

    return temp_s2;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_8067605C.s")

void func_8067618C(Actor *arg0, u8 *arg1) {
    if ((current_map == MAP_FUNGI_DOGADON) && (arg0->unk58 == ACTOR_CHUNKY) && (arg0->control_state == 0x1E)) {
        *arg1 = 0x15;
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
} GlobalASMStruct55;

extern GlobalASMStruct55 D_8074D0C4[];

void func_806761D0(Actor *arg0) {
    arg0->health = D_8074D0C4[arg0->unk58].unk0;
}

void func_806761EC(Actor *arg0) {
    arg0->unk136 = D_8074D0C4[arg0->unk58].unk2;
}

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    void* unk4;
} GlobalASMStruct56;

extern GlobalASMStruct56 D_8074C608[];

u8 func_80676208(Actor *arg0) {
    return D_8074C608[arg0->unk58].unk0;
}

s32 func_80676220(s16 arg0) {
    // Actor behaviour: Klump, Robo-Kremling, Kosha
    if ((arg0 == 0xBB) || (arg0 == 0xEB) || (arg0 == 0x123)) {
        return FALSE;
    }
    return TRUE;
}
