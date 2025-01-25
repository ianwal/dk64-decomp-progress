#include <ultra64.h>
#include "functions.h"

/*
// See func_global_asm_8072881C() for details
void func_global_asm_80688514(Actor *, s32);
*/

typedef struct Struct80687D50 {
    u8 pad0[0x10];
    s16 *unk10;
} Struct80687D50;

void func_global_asm_80687D50(Actor *arg0, Struct80687D50 *arg1) {
    s16 *var_s3;
    s16 temp_s4;
    s16 i;
    s32 j;
    s32 *var_s0;
    s32 *var_s1;
    GlobalASMStruct60 **var_s7;
    GlobalASMStruct60 *temp_v0;

    if (arg0->unk158 != 0) {
        if ((current_map == MAP_MAIN_MENU) || (cc_number_of_players >= 2)) {
            func_global_asm_80688638(&arg0->unk158);
        } else {
            return;
        }
    }
    var_s3 = arg1->unk10;
    var_s7 = &arg0->unk158;
    for (i = *var_s3++; i; i--) {
        *var_s7 = temp_v0 = malloc(sizeof(GlobalASMStruct60));
        temp_s4 = *var_s3++;
        temp_v0->unk1C = 0;
        temp_v0->unkC = 0;
        temp_v0->unk10 = 0.0f;
        temp_v0->unk14 = 0.0f;
        temp_v0->unk18 = 0;
        temp_v0->unk1A = 0;
        temp_v0->unk22 = 1;
        temp_v0->unk20 = 0;
        temp_v0->unk21 = 0;
        temp_v0->unkA = temp_s4;
        temp_v0->unk1E = temp_s4;
        temp_v0->unk8 = *var_s3++;
        var_s7 = &temp_v0->next;
        temp_v0->unk23 = *var_s3++;
        temp_v0->unk0 = malloc(temp_s4 * 4);
        temp_v0->unk4 = malloc(temp_s4 * 4);
        var_s0 = temp_v0->unk0;
        var_s1 = temp_v0->unk4;
        for (j = 0; j < temp_s4; j++) {
            *var_s1 = *var_s0 = getPointerTableFile(0x19, *var_s3, 1U, 0U);
            var_s0++;
            var_s1++;
            var_s3++;
        }
    }
    *var_s7 = NULL;
}



Gfx *func_global_asm_80687EE0(Gfx *dl, Actor *arg1) {
    GlobalASMStruct60 *current;

    current = arg1->unk158;
    while (current != NULL) {
        if (current->unk23 != 0) {
            void* temp2 = current->unk0[current->unkC];
            gSPSegment(dl++, current->unk8, osVirtualToPhysical(temp2));
        }
        current = current->next;
    }
    return dl;
}

void func_global_asm_80687F7C(Actor *arg0) {
    GlobalASMStruct60 *phi_s0;

    phi_s0 = arg0->unk158;
    while (phi_s0) {
        if (phi_s0->unk22 == 0) {
            func_global_asm_80687FC8(phi_s0);
        }
        phi_s0 = phi_s0->next;
    }
}

// close, doable
// https://decomp.me/scratch/mep3M
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8CA50/func_global_asm_80687FC8.s")

/*
// TODO: Just some fiddly last steps with order of operations
// Maybe need to eliminate the last of the temporary variables
void func_global_asm_80687FC8(GlobalASMStruct60 *arg0) {
    s32 temp_f10;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v0_5;
    s32 temp;

    switch ((u8)arg0->unk20) {
        case 0:
            arg0->unk14 += arg0->unk10;
            temp_f10 = arg0->unk14;
            arg0->unkC += temp_f10;
            arg0->unk14 -= temp_f10;
            if (arg0->unkC >= arg0->unk1E) {
                temp_lo = arg0->unkC / arg0->unk1E;
                arg0->unk1A += temp_lo;
                temp = 1;
                if ((arg0->unk1A >= arg0->unk18) && (arg0->unk18 != -1)) {
                    arg0->unkC = arg0->unk1E - 1;
                    arg0->unk22 = temp;
                    arg0->unk14 = 1.0f;
                    if ((u8)arg0->unk21 == 1) {
                        arg0->unk20 = temp;
                    }
                } else {
                    switch ((u8)arg0->unk21) {
                        case 0:
                            arg0->unkC %= arg0->unk1E;
                            if (arg0->unkC < arg0->unk1C) {
                                arg0->unkC = arg0->unk1C;
                            }
                            break;
                        case 1:
                            if (temp_lo != 0) {
                                arg0->unk20 = 1;
                                arg0->unkC = arg0->unk1E - 1;
                                arg0->unk14 = 1.0f;
                            }
                            break;
                    }
                }
            }
            break;
        case 1:
            arg0->unk14 -= arg0->unk10;
            if (arg0->unk14 < 0.0) {
                temp_v0_5 = (s32)arg0->unk14 - 1;
                arg0->unkC += temp_v0_5;
                arg0->unk14 -= temp_v0_5;
            }
            if (arg0->unkC < 0) {
                temp_lo_2 = -arg0->unkC / arg0->unk1E;
                arg0->unk1A += temp_lo_2 + 1;
                if ((arg0->unk1A >= arg0->unk18) && (arg0->unk18 != -1)) {
                    arg0->unkC = 0;
                    arg0->unk22 = 1;
                    arg0->unk14 = 0.0f;
                    if ((u8)arg0->unk21 == 1) {
                        arg0->unk20 = 0;
                    }
                } else {
                    switch ((u8)arg0->unk21) {
                        case 0:
                            arg0->unkC = -arg0->unkC % (arg0->unk1E - 1);
                            if (arg0->unkC != 0) {
                                arg0->unkC = (arg0->unk1E - arg0->unkC) - 1;
                            }
                            break;
                        case 1:
                            if ((temp_lo_2 + 1) != 0) {
                                arg0->unkC = 0;
                                arg0->unk20 = 0;
                                if (arg0->unkC < arg0->unk1C) {
                                    arg0->unkC = arg0->unk1C;
                                }
                                arg0->unk14 = 0.0f;
                            }
                            break;
                    }
                }
            }
            break;
    }
}
*/

s32 func_global_asm_806882DC(Actor *actor, s32 arg1, s16 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (!temp_v0) {
        return 0;
    }
    return temp_v0->unk0[arg2];
}

void func_global_asm_80688320(Actor *actor, s32 arg1, s16 arg2, void *arg3) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if ((temp_v0) && (arg2 < temp_v0->unkA)) {
        temp_v0->unk0[arg2] = arg3;
    }
}

void func_global_asm_80688370(Actor* actor, s32 arg1, f32 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk10 = arg2;
    }
}

void func_global_asm_8068839C(Actor *actor, s32 arg1, u8 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk20 = arg2;
    }
}

void func_global_asm_806883C8(Actor* actor, s32 arg1, u8 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk21 = arg2;
    }
}

void func_global_asm_806883F4(Actor* actor, s32 arg1, s16 arg2, f32 arg3) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unkC = arg2;
        temp_v0->unk14 = arg3;
    }
}

void func_global_asm_8068842C(Actor* actor, s32 arg1, s16 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk18 = arg2;
        temp_v0->unk1A = 0;
        temp_v0->unk22 = 0;
    }
}

void func_global_asm_80688460(Actor* actor, s32 arg1, u8 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk22 = arg2;
    }
}

void func_global_asm_8068848C(Actor* actor, s32 arg1, s16 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk1C = arg2;
    }
}

void func_global_asm_806884B8(Actor* actor, s32 arg1, s16 arg2) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk1E = arg2;
    }
}

void func_global_asm_806884E4(Actor* actor, s32 arg1) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk1E = temp_v0->unkA;
    }
}

void func_global_asm_80688514(Actor* actor, s32 arg1) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (temp_v0) {
        temp_v0->unk1C = 0;
    }
}

s32 func_global_asm_80688540(Actor* actor, s32 arg1) {
    GlobalASMStruct60 *temp_v0 = func_global_asm_80688584(actor, arg1);

    if (!temp_v0) {
        return FALSE;
    }
    // Absolutely baffling why they wrote it like this
    return temp_v0->unk22 == 0 ? TRUE : FALSE;
}

GlobalASMStruct60 *func_global_asm_80688584(Actor *arg0, s32 arg1) {
    GlobalASMStruct60 *current = arg0->unk158;
    while (arg1) {
        if (current) {
            arg1--;
            current = current->next;
        } else {
            return NULL;
        }
    }
    return current;
}

void func_global_asm_80688638(GlobalASMStruct60 **arg0) {
    GlobalASMStruct60 *next;
    GlobalASMStruct60 *temp_s2;
    GlobalASMStruct60 *current;
    s32 i;

    current = *arg0;
    while (current) {
        temp_s2 = current->unk4;
        for (i = 0; i < current->unkA; i++) {
            // TODO: Kinda janky
            func_global_asm_8066B434(((s32*)&temp_s2->unk0)[i], 0x1E6, 0x2C);
        }
        free(current->unk0);
        free(current->unk4);
        next = current->next;
        free(current);
        current = next;
    }
    *arg0 = NULL;
}
