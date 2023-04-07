#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675AFC.s")

// Jumptable
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

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    s8 unk9;
    u8 unkA;
    s8 unkB;
} Struct80748FE8;

extern Struct80748FE8 D_80748FE8[];

void func_8067605C(Actor *arg0, u8 arg1);

/*
// TODO: Shockingly close, t4 t2 mixup in comparison and missing unconditional branch at end of loop
void func_80675EE0(Actor *arg0) {
    AnimationStateUnk0 *temp_v0;
    s32 i;
    s16 temp_f6;
    s32 var_a1;
    s32 var_a3;
    PlayerAdditionalActorData *PaaD;
    u8 unk0;
    u8 var_t3;

    temp_v0 = arg0->animation_state->unk0;
    var_a1 = FALSE;
    i = 0;
    PaaD = arg0->additional_actor_data;
    temp_f6 = temp_v0->unk4;
    var_a3 = FALSE;
    var_t3 = TRUE;

    if (temp_v0->unk10 == -1) {
        arg0->unk132 = 0;
        return;
    }

    if (PaaD->unk11E != -1) {
        i = PaaD->unk11E;
        var_a3 = TRUE;
    }

    do {
        if (D_80748FE8[i].unk0 == -1) {
            var_a1 = TRUE;
        } else if (temp_v0->unk10 == D_80748FE8[i].unk0) {
            if ((temp_f6 >= D_80748FE8[i].unk2) && (D_80748FE8[i].unk4 >= temp_f6)) {
                arg0->unk132 = D_80748FE8[i].unk6;
                arg0->unk136 = D_80748FE8[i].unk8;
                if (D_80748FE8[i].unkA & 1) {
                    arg0->unk64 |= 0x80;
                } else {
                    arg0->unk64 &= ~0x80;
                }
                func_8067605C(arg0, D_80748FE8[i].unk9);
                if (var_t3) {
                    PaaD->unk11E = i;
                } else {
                    PaaD->unk11E = -1;
                }
                return;
            }
            var_t3 = FALSE;
        }
        i++;
        if (var_a3) {
            i = 0;
            var_a3 = FALSE;
            var_a1 = FALSE;
        }
    } while (!var_a1);

    arg0->unk132 = 0;
    arg0->unk136 = 0;
}
*/

typedef struct {
    u16 unk0; // Actor behaviour
    u8 unk2;
    u8 unk3;
    u16 unk4;
} Struct80748F58;

extern s8 D_80748E50[];
extern Struct80748F58 D_80748F58[];

void func_8067618C(Actor *arg0, u8 *arg1);

void func_8067605C(Actor *arg0, u8 arg1) {
    s16 i;
    s32 found;
    s8 *var_s3;

    func_8067618C(arg0, &arg1);
    func_8066EABC(arg0);
    var_s3 = &D_80748E50[arg1 * 9];
    while (var_s3[0] != -1) {
        func_8066EA64(arg0, var_s3[0]);
        found = FALSE;
        i = 0;
        while (i < 0x18 && !found) {
            if ((arg0->unk58 == D_80748F58[i].unk0) && ((var_s3[0] == D_80748F58[i].unk2))) {
                func_8066E5CC(arg0, var_s3[0], D_80748F58[i].unk4);
                found = TRUE;
            } else {
                func_8066E5CC(arg0, var_s3[0], 0);
                i++;
            }
        }
        var_s3++;
    }
}

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
