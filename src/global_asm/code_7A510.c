#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    void *unk4; // Pointer to struct, see func_80675810
} GlobalASMStruct57;

s32 func_80675E3C(GlobalASMStruct57 *arg0, s16 arg1, s16 arg2);

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct8074C604;

extern Struct8074C604 D_8074C604[];

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    void* unk4;
} GlobalASMStruct56;

extern GlobalASMStruct56 D_8074C608[];

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 (*unk4)(Actor *, Actor *, void *);
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Struct80675810;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Struct80675810_arg1_unk10;

typedef struct {
    s32 unk0;
    s32 unk4;
    Actor *unk8;
    s32 unkC;
    Struct80675810_arg1_unk10 *unk10;
    s32 unk14;
    s32 unk18;
} Struct80675810_arg1;

void func_80675D70(Actor *arg0);
void func_80675DD0(Actor *arg0, Actor *arg1);
void func_80675AFC(Actor *arg0, Actor *arg1);

void func_80675810(Actor *arg0, Struct80675810_arg1 *arg1) {
    Actor *temp_s2;
    Struct80675810 *var_s1;
    s32 var_s4;
    u8 var_v1;
    s32 i;
    s32 temp;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    PlayerAdditionalActorData* paad;

    temp_s2 = arg1->unk8;
    i = 0;
    var_s4 = FALSE;
    if ((func_8067AF44(temp_s2) != 0) && (temp_s2->unk54 == arg1->unk10->unk18)) {
        temp_2 = D_8074C604[arg0->unk58].unk0;
        if (temp_2 == 0) {
            if (temp_s2->object_properties_bitfield & 0x20000) {
                func_80675D70(temp_s2);
            }
        } else {
            var_s1 = func_80675E3C(temp_2, temp_s2->unk58, temp_s2->interactable);
            if ((!(temp_s2->object_properties_bitfield & 0x80000) && !(arg0->object_properties_bitfield & 0x80000)) || ((arg0 != temp_s2->unk11C) && (temp_s2 != arg0->unk11C))) {
                if (var_s1 == NULL) {
                    if (temp_s2->object_properties_bitfield & 0x20000) {
                        func_80675D70(temp_s2);
                    }
                } else {
                    while (!var_s4) {
                        if ((var_s1[i].unk0 & arg0->unk132) && (var_s1[i].unk2 & temp_s2->unk132)) {
                            if (var_s1[i].unk4 != NULL) {
                                var_v1 = var_s1[i].unk4(arg0, temp_s2, arg1);
                            } else {
                                var_v1 = 1;
                            }
                            if (var_v1 != 0) {
                                // TODO: Problem is here
                                temp = var_s1[i].unk8;
                                temp_4 = D_807FBB70.unk200;
                                temp_3 = D_807FBB70.unk201;
                                if (temp_4 < temp) {
                                    D_807FBB70.unk1FC = temp_s2;
                                    D_807FBB70.unk200 = var_s1[i].unk8;
                                }
                                if (temp_3 < 0xF) {
                                    D_807FBB70.unk204[D_807FBB70.unk201] = temp_s2;
                                    D_807FBB70.unk244[D_807FBB70.unk201] = var_s1[i].unk9;
                                    D_807FBB70.unk201++;
                                    if (temp_s2->interactable & 1) {
                                        paad = temp_s2->PaaD;
                                        if (paad->unkD4 != 0) {
                                            if ((D_8074C608[arg0->unk58].unk0 != 0) && (((D_807FBB70.unk243[D_807FBB70.unk201] == 5)) || (D_807FBB70.unk243[D_807FBB70.unk201] == 0xF))) {
                                                D_807FBB70.unk201--;
                                            }
                                        }
                                        if ((arg0->interactable & 2) && (func_80676220(arg0->unk58) != 0)) {
                                            temp_s2->unk64 |= 0x1000;
                                        }
                                    }
                                }
                                switch (var_s1[i].unkA) {
                                    case 0:
                                    case 2:
                                        var_s4 = TRUE;
                                        break;
                                }
                            }
                        }
                        if (var_s1[i].unkA == 0) {
                            var_s4 = TRUE;
                        }
                        i++;
                    }
                    if (arg0->object_properties_bitfield & 0x20000000) {
                        D_807FBB70.unk200 = 1;
                    }
                    if ((D_807FBB70.unk200 == 6) || (D_807FBB70.unk200 == 7)) {
                        func_80675DD0(arg0, temp_s2);
                    }
                    func_80675AFC(arg0, temp_s2);
                }
            }
        }
    }
}

// TODO: Needs proper definition of D_807FBB70
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675AFC.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675C70.s")

void func_80675D70(Actor *arg0) {
    if (D_807FBB70.unk200 < 2) {
        D_807FBB70.unk1FC = arg0;
        D_807FBB70.unk200 = 1;
    }
    if (D_807FBB70.unk201 < 0xF) {
        D_807FBB70.unk204[D_807FBB70.unk201] = arg0;
        D_807FBB70.unk244[D_807FBB70.unk201] = 2;
        D_807FBB70.unk201 += 1;
    }
}

void func_80675DD0(Actor *arg0, Actor *arg1) {
    arg0->health -= arg1->unk136;
    if (arg0->health <= 0) {
        D_807FBB70.unk200 = 9;
        return;
    }
    if (D_807FBB70.unk200 == 6) {
        D_807FBB70.unk200 = 4;
    }
    if (D_807FBB70.unk200 == 7) {
        D_807FBB70.unk200 = 5;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7A510/func_80675E3C.s")

s32 func_80675C70(s16, s16, s16);

/*
// TODO: Astonishingly close, extra NOP
s32 func_80675E3C(GlobalASMStruct57 *arg0, s16 arg1, s16 arg2) {
    s16 temp_s1;
    void *temp_s2;

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
