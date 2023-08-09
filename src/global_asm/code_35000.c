#include <ultra64.h>
#include "functions.h"


void func_global_asm_806306D0(Chunk14 *current);

extern Chunk14 *D_global_asm_807F5FF0;
extern Chunk14 *D_global_asm_807F5FF4;
extern Chunk14 *D_global_asm_807F5FF8;
extern Chunk14 *D_global_asm_807F5FFC;

void func_global_asm_80630300(void) {
    D_global_asm_807F5FF0 = NULL;
    D_global_asm_807F5FF4 = NULL;
    D_global_asm_807F5FF8 = NULL;
    D_global_asm_807F5FFC = NULL;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s16 unk4C;
    u8 unk4E; // Used
    u8 unk4F;
} GlobalASMStruct59;

s32 func_global_asm_80630324(u8 arg0, GlobalASMStruct59 *arg1) {
    if (arg0 == 2) {
        arg0 = arg1->unk4E;
        if (arg0 & 2) {
            return FALSE;
        }
        if (arg0 & 1) {
            return TRUE;
        }
        return FALSE;
    }
    switch (arg0) {
        case 0:
        case 1:
            return FALSE;
        case 5:
            return TRUE;
        default:
            return FALSE;
    }
}

void func_global_asm_8063039C(void) {
    func_global_asm_806306D0(D_global_asm_807F5FF4);
    D_global_asm_807F5FF4 = NULL;
}

Chunk14 *func_global_asm_806303C4(Chunk14 *arg0, u8 arg1, Model2Model *arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, s16 arg7, u8 arg8, s16 arg9, u8 argA) {
    Chunk14 *temp_v0;
    Chunk14 *phi_v1;
    s32 phi_v0;
    Chunk14 *phi_a1;

    phi_v0 = FALSE;
    phi_v1 = NULL;
    if (argA == 1) {
        arg0 = D_global_asm_807F5FF0;
    }
    if (argA == 2) {
        arg0 = D_global_asm_807F5FF4;
    }
    if (argA == 3) {
        arg0 = D_global_asm_807F5FF8;
    }
    if (argA == 4) {
        arg0 = D_global_asm_807F5FFC;
    }
    phi_a1 = arg0;
    while (arg0 && !phi_v0) {
        if (arg2 == arg0->unk0) {
            phi_v0 = TRUE;
        } else {
            phi_v1 = arg0;
            arg0 = arg0->next;
        }
    }
    if (phi_v0) {
        arg0->unk4 = arg3;
        arg0->unk8 = arg4;
        arg0->unkC = arg5;
        arg0->unk1C = arg6;
        if (arg9 != -1) {
            arg0->unk20 = arg9;
        }
        arg0->unk23 = 1;
    } else {
        temp_v0 = malloc(sizeof(Chunk14));
        temp_v0->unk24 = arg1;
        temp_v0->unk0 = arg2;
        temp_v0->unk4 = arg3;
        temp_v0->unk8 = arg4;
        temp_v0->unkC = arg5;
        temp_v0->unk1C = arg6;
        temp_v0->unk1E = arg7;
        temp_v0->unk22 = arg8;
        temp_v0->unk23 = 1;
        temp_v0->unk10 = 0.0f;
        temp_v0->unk20 = 0;
        temp_v0->next = NULL;
        if (phi_v1) {
            phi_v1->next = temp_v0;
            temp_v0->next2 = phi_v1;
        } else {
            phi_a1 = temp_v0;
            temp_v0->next2 = NULL;
        }
    }
    if (argA == 1) {
        D_global_asm_807F5FF0 = phi_a1;
    }
    if (argA == 2) {
        D_global_asm_807F5FF4 = phi_a1;
    }
    if (argA == 3) {
        D_global_asm_807F5FF8 = phi_a1;
    }
    if (argA == 4) {
        D_global_asm_807F5FFC = phi_a1;
    }
    return phi_a1;
}

void func_global_asm_8061130C(void *);

Chunk14 *func_global_asm_80630588(Chunk14 *arg0, Model2Model *arg1, u8 arg2, u8 *arg3) {
    u8 phi_v0;
    Chunk14 *phi_t0;
    Chunk14 *phi_a2;

    phi_v0 = FALSE;
    phi_t0 = NULL;
    if (arg2 == 1) {
        arg0 = D_global_asm_807F5FF0;
    }
    if (arg2 == 2) {
        arg0 = D_global_asm_807F5FF4;
    }
    if (arg2 == 3) {
        arg0 = D_global_asm_807F5FF8;
    }
    if (arg2 == 4) {
        arg0 = D_global_asm_807F5FFC;
    }
    phi_a2 = arg0;
    while (arg0 && !phi_v0) {
        if (arg1 == arg0->unk0) {
            phi_v0 = TRUE;
        } else {
            phi_t0 = arg0;
            arg0 = arg0->next;
        }
    }
    if (phi_v0) {
        if (phi_t0) {
            phi_t0->next = arg0->next;
        } else {
            phi_a2 = arg0->next;
        }
        if (arg0->next) {
            arg0->next->next2 = phi_t0;
        }
        func_global_asm_8061130C(arg0);
    }
    *arg3 = phi_v0;
    if (arg2 == 1) {
        D_global_asm_807F5FF0 = phi_a2;
    }
    if (arg2 == 2) {
        D_global_asm_807F5FF4 = phi_a2;
    }
    if (arg2 == 3) {
        D_global_asm_807F5FF8 = phi_a2;
    }
    if (arg2 == 4) {
        D_global_asm_807F5FFC = phi_a2;
    }
    return phi_a2;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_806306D0.s")

/*
// TODO: Very close, adding a temp variable for next doesn't work
void func_global_asm_806306D0(Chunk14 *current) {
    while (current) {
        func_global_asm_8061130C(current);
        current = current->next;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_8063070C.s")

/*
// TODO: Pretty close, not sure exactly what it's doing
Chunk14 *func_global_asm_8063070C(Chunk14 *arg0) {
    while (arg0) {
        if ((arg0->unk22 == 1) && (arg0->unk23 == 0)) {
            if (arg0->next2) {
                arg0->next2->next = arg0->next;
            } else {
                arg0 = arg0->next;
            }
            if (arg0->next) {
                arg0->next->next2 = arg0->next2;
            }
            func_global_asm_8061130C(arg0);
        }
        arg0 = arg0->next;
    }
    return arg0;
}
*/

void func_global_asm_806307AC(Chunk14 *current) {
    while (current) {
        current->unk23 = 0;
        current = current->next;
    }
}

void func_global_asm_806307CC(Chunk14 *arg0, Model2Model *arg1, u8 arg2, u8 arg3, s8 *arg4) {
    s8 found = FALSE;

    if (arg2 == 1) {
        arg0 = D_global_asm_807F5FF0;
    }
    if (arg2 == 2) {
        arg0 = D_global_asm_807F5FF4;
    }
    if (arg2 == 3) {
        arg0 = D_global_asm_807F5FF8;
    }
    if (arg2 == 4) {
        arg0 = D_global_asm_807F5FFC;
    }
    while (arg0 && !found) {
        if (arg1 == arg0->unk0) {
            found = TRUE;
        } else {
            arg0 = arg0->next;
        }
    }
    if (found) {
        if (arg3) {
            arg0->unk10 = -1.0f;
        } else {
            arg0->unk1C = -2;
        }
    }
    *arg4 = found;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_80630890.s")

extern f32 D_global_asm_807581D0;
extern f32 D_global_asm_807581D4;
extern f64 D_global_asm_807581D8;

/*
// TODO: Pretty close
Chunk14 *func_global_asm_80630890(Chunk14 *arg0, f32 arg1, f32 arg2, f32 arg3, Chunk14 **arg4) {
    Chunk14 *phi_a1;
    Chunk14 *phi_v0;
    Chunk14 *phi_v1;
    Chunk14 *temp_v0_4;
    f32 dz;
    f64 phi_f16;
    f64 temp_f12;
    f32 phi_f14;
    f32 phi_f18;
    f32 phi_f2;
    f32 dx;
    s32 found;
    f32 dy;
    Chunk14 *phi_t0_2;

    phi_v0 = arg0;
    phi_f18 = 0.0f;
    phi_f16 = 0.0;
    *arg4 = NULL;
    while (phi_v0) {
        dx = phi_v0->unk4 - arg1;
        dy = phi_v0->unk8 - arg2;
        dz = phi_v0->unkC - arg3;
        if (phi_f16 != phi_v0->unk10) {
            phi_v0->unk10 = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
        }
        phi_v0 = phi_v0->next;
    }
    phi_t0_2 = arg0;
    phi_a1 = arg0;
    if (arg0) {
        if ((arg0->unk10 < arg0->unk1C) || (arg0->unk1C == -2)) {
            *arg4 = arg0;
            if (arg0->unk1C == -2) {
                phi_f18 = D_global_asm_807581D0;
            } else {
                phi_f18 = arg0->unk10;
            }
        }
        phi_a1 = arg0->next;
        if (phi_a1) {
            temp_f12 = D_global_asm_807581D8;
            do {
                found = FALSE;
                phi_a1 = phi_t0_2;
                if (((phi_f18 < phi_a1->unk10) && (phi_a1->unk10 < phi_a1->unk1C)) || (phi_a1->unk1C == -2)) {
                    *arg4 = phi_a1;
                    if (phi_a1->unk1C == -2) {
                        phi_f18 = D_global_asm_807581D4;
                    } else {
                        phi_f18 = phi_a1->unk10;
                    }
                }
                if (phi_a1->unk1C < phi_a1->unk10) {
                    phi_f14 = temp_f12;
                } else {
                    phi_f14 = phi_a1->unk10;
                }
                phi_v1 = phi_a1->next2;
                while (phi_v1 && !found) {
                    if (phi_v1->unk1C < phi_v1->unk10) {
                        phi_f2 = temp_f12;
                    } else {
                        phi_f2 = phi_v1->unk10;
                    }
                    if ((phi_f14 <= phi_f2) || (phi_a1->unk1C == -2)) {
                        found = TRUE;
                        if (phi_v1 != phi_a1->next2) {
                            phi_a1->next2->next = phi_a1->next;
                            if (phi_a1->next) {
                                phi_a1->next->next2 = phi_a1->next2;
                            }
                            temp_v0_4 = phi_v1->next;
                            phi_v1->next = phi_a1;
                            phi_a1->next = temp_v0_4;
                            if (temp_v0_4) {
                                temp_v0_4->next2 = phi_a1;
                            }
                            phi_a1->next2 = phi_v1;
                        }
                    }
                    phi_v1 = phi_v1->next2;
                }
                if (!found) {
                    phi_a1->next2->next = phi_a1->next;
                    if (phi_a1->next) {
                        phi_a1->next->next2 = phi_a1->next2;
                    }
                    phi_a1->next2 = NULL;
                    phi_a1->next = phi_t0_2;
                    phi_t0_2->next2 = phi_a1;
                }
                phi_a1 = phi_a1->next;
                phi_t0_2 = phi_a1;
            } while (phi_a1);
        }
    }
    return phi_a1;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_80630B70.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_80630DCC.s")

// Matrix stuff, Actor* Arg0, f32[][] arg1?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_8063162C.s")

// Similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_35000/func_global_asm_806317D4.s")

s32 func_global_asm_8063162C(Actor *, s16 *);
s32 func_global_asm_806317D4(Actor *, s16 *, f32, f32, f32);

void func_global_asm_806319C4(Actor *arg0, u8 arg1) {
    f32 sp78[4][4];
    f32 sppad[4][4];
    s16 phi_a0;
    s16 temp_f2;
    s16 temp;
    s16 temp_t7;
    s16 temp_yrot;

    if ((arg0->object_properties_bitfield & 1)) {
        phi_a0 = (arg0->y_rotation - arg0->unkDC) & 0xFFF;
        if (phi_a0 >= 0x801) {
            phi_a0 = phi_a0 - 0x1000;
        }
        temp_f2 = (0x400 - arg0->unkDE) & 0xFFF;
        temp = func_global_asm_80612790(phi_a0) * temp_f2;
        temp = (temp + arg0->z_rotation) & 0xFFF;
        temp_t7 = ((s16)(func_global_asm_80612794(phi_a0) * temp_f2) + arg0->x_rotation) & 0xFFF;
        temp_yrot = arg0->y_rotation;
        if (arg1 != 0) {
            func_global_asm_806317D4(arg0, &sp78, temp_t7, temp, temp_yrot);
            guMtxCatF(&arg0->unkC, &sp78, &arg0->unkC);
        } else {
            func_global_asm_806317D4(arg0, &arg0->unkC, temp_t7, temp, temp_yrot);
        }
    } else {
        if (arg1 != 0) {
            func_global_asm_8063162C(arg0, &sp78);
            guMtxCatF(&arg0->unkC, &sp78, &arg0->unkC);
        } else {
            func_global_asm_8063162C(arg0, &arg0->unkC);
        }
    }
}
