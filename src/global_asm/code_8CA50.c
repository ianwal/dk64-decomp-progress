#include <ultra64.h>
#include "functions.h"

/*
// See func_global_asm_8072881C() for details
void func_global_asm_80688514(Actor *, s32);
*/

GlobalASMStruct60 *func_global_asm_80688584(Actor*, s32);
void func_global_asm_80687FC8(GlobalASMStruct60 *arg0);

// malloc and initialization for GlobalASMStruct60
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8CA50/func_global_asm_80687D50.s")

// Displaylist stuff? Actor arg1
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8CA50/func_global_asm_80687EE0.s")

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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8CA50/func_global_asm_80687FC8.s")

/*
// TODO: Just some fiddly last steps with order of operations
// Maybe need to eliminate the last of the temporary variables
void func_global_asm_80687FC8(GlobalASMStruct60 *arg0) {
    s32 temp_f10;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v0_5;

    switch ((u8)arg0->unk20) {
        case 0:
            arg0->unk14 += arg0->unk10;
            temp_f10 = arg0->unk14;
            arg0->unkC += temp_f10;
            arg0->unk14 -= temp_f10;
            if (arg0->unkC >= arg0->unk1E) {
                temp_lo = arg0->unkC / arg0->unk1E;
                arg0->unk1A += temp_lo;
                if ((arg0->unk1A >= arg0->unk18) && (arg0->unk18 != -1)) {
                    arg0->unkC = arg0->unk1E - 1;
                    arg0->unk22 = 1;
                    arg0->unk14 = 1.0f;
                    if ((u8)arg0->unk21 == 1) {
                        arg0->unk20 = 1;
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

void func_global_asm_80688320(Actor *actor, s32 arg1, s16 arg2, s32 arg3) {
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

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8CA50/func_global_asm_80688638.s")

/*
void func_global_asm_80688638(GlobalASMStruct60 **arg0) {
    GlobalASMStruct60 *temp_s0;
    GlobalASMStruct60 *temp_s2;
    GlobalASMStruct60 *phi_s2;
    s32 phi_s0;

    phi_s2 = *arg0;
    while (phi_s2) {
        temp_s2 = phi_s2->unk4;
        for (phi_s0 = 0; phi_s0 < phi_s2->unkA; phi_s0++) {
            func_global_asm_8066B434(temp_s2->unk0, 0x1E6, 0x2C);
            temp_s2++;
        }
        free(phi_s2->unk0);
        free(phi_s2->unk4);
        temp_s0 = phi_s2->next;
        free(phi_s2);
        phi_s2 = temp_s0;
    }
    *arg0 = NULL;
}
*/
