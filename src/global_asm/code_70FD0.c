#include <ultra64.h>
#include "functions.h"

void func_global_asm_8066C2D0(s32, s32, f32, f32, f32, f32, f32, f32, f32);
void func_global_asm_8066CDF8(void);
LedgeInfo8C *func_global_asm_8066EAEC(Actor*, s32);
void func_global_asm_8066EC6C(LedgeInfo *);
void func_global_asm_8066F06C(LedgeInfo *);
u8 func_global_asm_8066F274(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3);
void func_global_asm_8066F400(Actor *);
u8 func_global_asm_8066F4AC(Actor *, s16 *, s16 *);
u8 func_global_asm_80670FA4(Actor *, s16 *, s16 *);
void func_global_asm_80671260(Actor *arg0);
void func_global_asm_80672C70(s32);
void func_global_asm_80672E90(s32, s32, s32);
s32 func_global_asm_806730A4(s32, s32, s32, s32);
s32 func_global_asm_806734E4(s32, s32, s32, s32, s16 *, s16 *);
void func_global_asm_80674E14(Actor *);
void func_global_asm_80679290(Actor *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6);

s32 func_global_asm_80672328(Actor*, f32, f32);
s32 func_global_asm_80672680(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16* arg4);
s32 func_global_asm_806726DC(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 arg5);

extern s32 D_global_asm_807FB53C;
extern Actor *D_global_asm_807FB540;
extern s16 D_global_asm_807FB544;
extern u8 D_global_asm_807FB546;
extern u8 D_global_asm_807FB547;
extern s8 D_global_asm_807FB548;
extern s16 D_global_asm_807FB5EC;
extern s16 D_global_asm_807FB5EE;
extern s16 D_global_asm_807FB5F0;
extern s16 D_global_asm_807FB5F2;
extern s16 D_global_asm_807FB5F8;
extern s16 D_global_asm_807FB5FA;
extern u8 D_global_asm_807FB602;
extern u8 D_global_asm_807FB604;
extern u8 D_global_asm_807FB605;
extern u8 D_global_asm_807FB606;
extern u8 D_global_asm_807FB61C;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066C2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066C610.s")

/*
void func_global_asm_8066C610(s16 arg0, s8 arg1, f32 (*arg2)[4]) {
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 sp8C[4][4];
    f32 sp4C[4][4];
    s32 sp48;
    void *sp44;
    OM2_unk24 *temp_v0_2;
    OM2_unk78 *temp_v0;
    ObjectModel2 *temp_v1;

    temp_v1 = &D_global_asm_807F6000[arg0];
    temp_v0 = temp_v1->unk78;
    if (temp_v0 != NULL) {
        sp48 = *(temp_v0 + (D_global_asm_807444FC * 4));
    } else {
        sp48 = 0;
    }
    temp_v0_2 = temp_v1->unk24;
    sp44 = temp_v0_2->unk60 + temp_v0_2;
    func_global_asm_806357F8(arg0, &spEC, &spE8, &spE4, &spE0, &spDC, &spD8, &spD4, &spD0, 0);
    guScaleF(sp8C, spD4, spD4, spD4);
    guRotateF(sp4C, spE0, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp8C, sp4C, sp8C);
    guRotateF(sp4C, spDC, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp8C, sp4C, sp8C);
    guRotateF(sp4C, spD8, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp8C, sp4C, sp8C);
    guTranslateF(sp4C, spEC, spE8, spE4);
    if (arg1 != -1) {
        guMtxCatF(sp8C, sp4C, sp8C);
        func_global_asm_8066C7F4((arg1 << 5) + sp44, sp48, arg2);
        guMtxCatF(arg2, sp8C, arg2);
        return;
    }
    guMtxCatF(sp8C, sp4C, arg2);
}
*/

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066C7F4.s")

void func_global_asm_8066C8B0(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    func_global_asm_8066C2D0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void func_global_asm_8066C904(OM2_unk28 *arg0) {
    void *temp = arg0->unk18;
    if (temp != NULL) {
        if (arg0->unk15 & 1) {
            free(temp);
        }
    }
    arg0->unk15 &= 0xFFFE;
}

// Loads walls for the current map from pointer table 2
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066C958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066CB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066CCD8.s")

extern s32 D_global_asm_80747D70;
extern s16 D_global_asm_80748E40;

/*
// TODO: Hmm, are OM2_unk28 and OM2_unk48 substructs?
void func_global_asm_8066CCD8(void) {
    OM2_unk48 *temp_a0_2;
    ObjectModel2 *var_v1;
    OM2_unk28 *temp_a0;

    if (D_global_asm_80747D70 != 0) {
        D_global_asm_80748E40 += 1;
        if (D_global_asm_80748E40 >= D_global_asm_80747D70) {
            D_global_asm_80748E40 = 0;
        }
        var_v1 = &D_global_asm_807F6000[D_global_asm_80748E40];
        temp_a0 = var_v1->unk28;
        if (var_v1->unk28->unk15 & 1) {
            if ((object_timer - var_v1->unk28->unk10) >= 0x1FU) {
                func_global_asm_8066C904(temp_a0);
            }
        }
        var_v1 = &D_global_asm_807F6000[D_global_asm_80748E40];
        temp_a0_2 = var_v1->unk48;
        if (temp_a0_2->unk24 & 1) {
            if ((object_timer - temp_a0_2->unk8) >= 0x1FU) {
                func_global_asm_806348B4(temp_a0_2);
            }
        }
    }
}
*/

void func_global_asm_8066CDD0(void) {
    func_global_asm_8066CDF8();
    func_global_asm_806687E0();
}

void func_global_asm_8066CDF8(void) {
    s32 i;

    for (i = 0; i < D_807FB538; i++) {
        if ((D_807FB534[i].unk0 != NULL) && ((object_timer - D_807FB534[i].unk8) >= 0x15U)) {
            if (D_807FB549 == 0) {
                free(D_807FB534[i].unk4);
                D_807FB534[i].unk4 = NULL;
            }
            free(D_807FB534[i].unk0);
            D_807FB534[i].unk0 = NULL;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066CEE4.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 unk13;
} Struct8066D250;

s32 func_global_asm_8066D250(Struct8066D250 *arg0) {
    s16 temp_a1;
    s16 temp_v0;
    s16 temp_v1;

    temp_v0 = arg0->unk6;
    temp_v1 = arg0->unk0;
    if ((temp_v0 == temp_v1) && (arg0->unk2 == arg0->unk8) && (arg0->unk4 == arg0->unkA)) {
        return TRUE;
    }
    temp_a1 = arg0->unkC;
    if ((temp_v0 == temp_a1) && (arg0->unkE == arg0->unk8) && (arg0->unk10 == arg0->unkA)) {
        return TRUE;
    }
    if ((temp_a1 == temp_v1) && (arg0->unk2 == arg0->unkE) && (arg0->unk4 == arg0->unk10)) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066D2F4.s")

/*
s32 func_global_asm_8066D2F4(Struct8066D250 *arg0) {
    // TODO: Convert the stack stuff into an array/struct
    f32 sp28;
    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f8;
    f32 temp_f8_2;
    f32 var_f12;
    f32 var_f2;
    f64 temp_f0_2;
    f64 temp_f2;
    s32 var_v0;

    temp_f8 = arg0->unkC - arg0->unk0;
    temp_f18 = arg0->unk6 - arg0->unk0;
    temp_f16 = arg0->unkE - arg0->unk2;
    temp_f4 = arg0->unk10 - arg0->unk4;
    temp_f6 = arg0->unk8 - arg0->unk2;
    temp_f10 = arg0->unkA - arg0->unk4;
    temp_f8_2 = (temp_f16 * temp_f10) - (temp_f6 * temp_f4);
    sp28 = (temp_f4 * temp_f18) - (temp_f10 * temp_f8);
    temp_f6_2 = (temp_f8 * temp_f6) - (temp_f18 * temp_f16);
    temp_f0 = sqrtf((temp_f6_2 * temp_f6_2) + (temp_f8_2 * temp_f8_2));
    temp_f2 = temp_f0;
    if ((temp_f2 < 0.01) && (temp_f2 > -0.01)) {
        var_f2 = 1.57f;
    } else {
        if (sp28 > 0.0f) {
            var_f12 = sp28;
        } else {
            var_f12 = -sp28;
        }
        var_f2 = func_global_asm_80611BB4(var_f12, temp_f0);
    }
    temp_f0_2 = var_f2 * 57.29577791868205;
    if (temp_f0_2 < 10.0) {
        return 1;
    }
    if (temp_f0_2 < 45.0) {
        return 2;
    } else {
        return 0;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066D4DC.s")

// close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066DB40.s")

typedef struct {
    s16 unk0[9];
    s16 unk12;
    u8 unk14;
    u8 unk15;
    u8 unk16;
} Struct8066DB40_arg0;

typedef struct {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    f32 unk20;
    s16 unk24;
    s16 unk26;
} Struct8066DB40_arg1;

typedef struct {
    s32 sp4C[9];
    s16 sp70;
    s8 sp72;
    s8 sp73;
    u8 sp74;
    s8 sp75;
    s8 sp76;
    s8 sp77;
    u8 sp78;
    s8 sp79;
} Struct8066DB40_stack4C;

/*
s32 func_global_asm_8066DB40(Struct8066DB40_arg0 *arg0, Struct8066DB40_arg1 *arg1) {
    s32 pad;
    Struct8066DB40_stack4C sp4C;    
    f32 sp48;
    s64 sp40;
    s64 sp38;
    s64 sp30;
    s64 sp28;
    s32 pad2;

    sp4C.sp4C[0] = arg0->unk0[0];
    sp4C.sp4C[1] = arg0->unk0[1];
    sp4C.sp4C[2] = arg0->unk0[2];
    sp4C.sp4C[3] = arg0->unk0[3];
    sp4C.sp4C[4] = arg0->unk0[4];
    sp4C.sp4C[5] = arg0->unk0[5];
    sp4C.sp4C[6] = arg0->unk0[6];
    sp4C.sp4C[7] = arg0->unk0[7];
    sp4C.sp4C[8] = arg0->unk0[8];
    sp4C.sp4C[0] *= 8;sp4C.sp4C[1] *= 8;sp4C.sp4C[2] *= 8;
    sp4C.sp4C[3] *= 8;
    sp4C.sp4C[4] *= 8;
    sp4C.sp4C[5] *= 8;
    sp4C.sp4C[6] *= 8;sp4C.sp4C[7] *= 8;sp4C.sp4C[8] *= 8;

    sp4C.sp70 = arg0->unk12;
    sp4C.sp74 = arg0->unk14;
    sp4C.sp75 = 0;
    sp4C.sp77 = 0;
    if (arg0->unk16 & 4) {
        sp4C.sp79 = 1;
    } else {
        sp4C.sp79 = 0;
    }
    sp4C.sp78 = arg0->unk15;
    sp4C.sp73 = 1;
    func_global_asm_8066DD34(&sp28);
    arg1->unk0 = sp28;
    arg1->unk8 = sp30;
    arg1->unk10 = sp38;
    arg1->unk18 = sp40;
    arg1->unk20 = sp48;
    arg1->unk24 = MIN(arg0->unk0[1], arg0->unk0[4]);
    arg1->unk24 = MIN(arg1->unk24, arg0->unk0[7]);
    arg1->unk26 = MAX(arg0->unk0[1], arg0->unk0[4]);
    arg1->unk26 = MAX(arg1->unk26, arg0->unk0[7]);
    return 1;
}
*/

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066DD34.s")

void func_global_asm_8066E21C(LedgeInfo *ledgeInfo) {
    LedgeInfo8C *current;
    LedgeInfo8C *next;
    LedgeInfo90 *current2;
    LedgeInfo90 *next2;

    if (ledgeInfo) {
        current = ledgeInfo->unk8C;
        while (current) {
            next = current->next;
            free(current);
            current = next;
        }
        current2 = ledgeInfo->unk90;
        while (current2) {
            next2 = current2->next;
            free(current2);
            current2 = next2;
        }
        if (ledgeInfo->unkA0) {
            free(ledgeInfo->unkA0);
        }
        if (ledgeInfo->unk98) {
            free(ledgeInfo->unk98);
        }
        free(ledgeInfo);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066E2C0.s")

void func_global_asm_8066E5CC(Actor *arg0, s32 arg1, u16 arg2) {
    LedgeInfo8C *temp_v0 = func_global_asm_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk24 = arg2;
    }
}

void func_global_asm_8066E5F8(Actor *arg0, s32 arg1, u8 arg2) {
    LedgeInfo8C *temp_v0 = func_global_asm_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk27 |= arg2;
    }
}

void func_global_asm_8066E62C(Actor *arg0, s32 arg1, u8 arg2) {
    LedgeInfo8C *temp_v0 = func_global_asm_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk27 &= ~arg2;
    }
}

void func_global_asm_8066E664(Actor *arg0, s32 arg1, u8 arg2) {
    LedgeInfo *ledgeInfo;
    LedgeInfoA0 *phi_a2;
    s32 i;

    ledgeInfo = arg0->ledge_info_pointer;
    if (arg0->ledge_info_pointer) {
        phi_a2 = ledgeInfo->unkA0;
        for (i = 0; i < ledgeInfo->unk9C; i++) {
            if (arg1 == phi_a2[i].unk28) {
                phi_a2[i].unk2A = arg2;
            }
        }
    }
}

void func_global_asm_8066E6C8(Actor *arg0, s32 arg1, u8 arg2) {
    LedgeInfo *ledgeInfo;
    LedgeInfo98 *phi_a2;
    s32 i;

    ledgeInfo = arg0->ledge_info_pointer;
    if (arg0->ledge_info_pointer) {
        phi_a2 = ledgeInfo->unk98;
        for (i = 0; i < ledgeInfo->unk94; i++) {
            if (arg1 == phi_a2[i].unk54) {
                phi_a2[i].unk56 = arg2;
            }
        }
    }
}

void func_global_asm_8066E72C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, void *arg7, s32 arg8) {
    LedgeInfo *ledgeInfo = malloc(0xC4); // TODO: sizeof(LedgeInfo) + something?

    ledgeInfo->unk0 = arg0 * 8.0f;
    ledgeInfo->unk4 = arg1 * 8.0f;
    ledgeInfo->unk8 = arg2 * 8.0f;
    ledgeInfo->unkC = arg4 * arg3 * 8.0f;
    ledgeInfo->unk10 = arg5 * arg3 * 8.0f;
    ledgeInfo->unk14 = arg4;
    ledgeInfo->unk18 = arg5;
    ledgeInfo->unk70 = arg6;
    ledgeInfo->unk74 = arg7;
    ledgeInfo->unk78 = arg8;
    ledgeInfo->unk7C = -1;
    ledgeInfo->unk80 = -2;
    ledgeInfo->unk84 = -1;
    ledgeInfo->unk88 = -1;
    ledgeInfo->unk60 = 0;
    ledgeInfo->unk6C = 0;
    ledgeInfo->unk24 = 0;
    ledgeInfo->unk8C = NULL;
    ledgeInfo->unk90 = NULL;
    ledgeInfo->unk94 = 0;
    ledgeInfo->unk98 = NULL;
    ledgeInfo->unk9C = 0;
    ledgeInfo->unkA0 = NULL;
    ledgeInfo->unkA4 = 0;
    ledgeInfo->unkA8 = 0;
    ledgeInfo->unkAC = 0;
}

void func_global_asm_8066E854(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 pad[3];
    LedgeInfo *temp_a1;
    LedgeInfo90 *temp_v0;
    LedgeInfo90 *temp_v1;
    LedgeInfo90 **phi_a0;

    temp_a1 = arg0->ledge_info_pointer;
    temp_v0 = malloc(sizeof(LedgeInfo90));
    temp_v0->next = NULL;
    temp_v0->unk0 = arg1;
    temp_v0->unk4 = arg2;
    temp_v0->unk8 = arg3;
    temp_v0->unk18 = arg4;
    temp_v0->unkC = 0;
    temp_v0->unk10 = 0;
    temp_v0->unk14 = 0;
    temp_v1 = temp_a1->unk90;
    phi_a0 = &temp_a1->unk90;
    while (temp_v1) {
        phi_a0 = &temp_v1->next;
        temp_v1 = temp_v1->next;
    }
    *phi_a0 = temp_v0;
}

void func_global_asm_8066E8E4(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    LedgeInfo8C **var_a0;
    LedgeInfo8C *var_v1;
    LedgeInfo8C *temp_v0;
    LedgeInfo *temp_a1;

    temp_a1 = arg0->ledge_info_pointer;
    temp_v0 = malloc(sizeof(LedgeInfo8C));
    temp_v0->next = NULL;
    var_a0 = &temp_a1->unk8C;
    temp_v0->unk0 = arg1;
    temp_v0->unk4 = arg2;
    temp_v0->unk8 = arg3;
    temp_v0->unkC = arg4;
    temp_v0->unk20 = arg5;
    temp_v0->unk10 = 0;
    temp_v0->unk14 = 0;
    temp_v0->unk18 = 0;
    temp_v0->unk1C = 0;
    temp_v0->unk26 = 1;
    temp_v0->unk24 = 0;
    temp_v0->unk27 = 0;
    var_v1 = temp_a1->unk8C;
    while (var_v1 != NULL) {
        var_a0 = &var_v1->next;
        var_v1 = var_v1->next;
    }
    *var_a0 = temp_v0;
}

void func_global_asm_8066E990(Actor *arg0) {
    LedgeInfo *ledgeInfo;
    LedgeInfo8C *current;
    LedgeInfo8C *next;

    ledgeInfo = arg0->ledge_info_pointer;
    if (ledgeInfo) {
        current = ledgeInfo->unk8C;
        while (current) {
            next = current->next;
            free(current);
            current = next;
        }
        ledgeInfo->unk8C = NULL;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066E9EC.s")

/*
// TODO: Pretty close, surprisingly fiddly
f32 func_global_asm_8066E9EC(Actor *arg0, s32 arg1, f32 arg2) {
    LedgeInfo8C *phi_v1;

    arg1--;
    phi_v1 = arg0->ledge_info_pointer->unk8C;
    while (phi_v1) {
        if (phi_v1->next) {
            if (arg1) {
                arg1--;
            } else {
                break;
            }
            phi_v1 = phi_v1->next;
        } else {
            break;
        }
    }

    if (phi_v1) {
        if (arg2 != -1.0f) {
            phi_v1->unkC = arg2;
        }
        return phi_v1->unkC;
    }
    return -1.0f;
}
*/

void func_global_asm_8066EA64(Actor *arg0, s32 arg1) {
    LedgeInfo8C *temp_v0 = func_global_asm_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk26 = 1;
    }
}

void func_global_asm_8066EA90(Actor *arg0, s32 arg1) {
    LedgeInfo8C *temp_v0 = func_global_asm_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk26 = 0;
    }
}

void func_global_asm_8066EABC(Actor *arg0) {
    LedgeInfo *ledgeInfo;
    LedgeInfo8C *current;

    ledgeInfo = arg0->ledge_info_pointer;
    if (ledgeInfo != NULL) {
        current = ledgeInfo->unk8C;
        while (current != NULL) {
            current->unk26 = 0;
            current = current->next;
        }
    }
}

LedgeInfo8C *func_global_asm_8066EAEC(Actor *arg0, s32 arg1) {
    LedgeInfo *ledgeInfo;
    LedgeInfo8C *current;

    ledgeInfo = arg0->ledge_info_pointer;
    arg1--;
    if (ledgeInfo != NULL) {
        current = ledgeInfo->unk8C;
        while (arg1 != 0 && current != NULL) {
            arg1--;
            current = current->next;
        }
        if (current != NULL) {
            return current;
        }
        return NULL;
    }
    return NULL;
}

void func_global_asm_8066EB40(Actor *arg0, f32 arg1) {
    LedgeInfo *ledgeInfo = arg0->ledge_info_pointer;
    ledgeInfo->unk14 = arg1;
}

void func_global_asm_8066EB50(Actor *actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    LedgeInfo *ledgeInfo = actor->ledge_info_pointer;
    if (actor->unk64 & 0x800) {
        arg4 = actor->unk120;
    }
    ledgeInfo->unk0 = arg1 * 8.0f;
    ledgeInfo->unk4 = arg2 * 8.0f;
    ledgeInfo->unk8 = arg3 * 8.0f;
    ledgeInfo->unkC = ledgeInfo->unk14 * arg4 * 8.0f;
    ledgeInfo->unk10 = ledgeInfo->unk18 * arg4 * 8.0f;
}

void func_global_asm_8066EBF4(Actor *arg0) {
    if (arg0->ledge_info_pointer) {
        if (!(arg0->object_properties_bitfield & 0x80000000) || ((arg0->object_properties_bitfield & 0x10) == 0)) {
            func_global_asm_8066EC6C(arg0->ledge_info_pointer);
        }
        if (!(arg0->unk64 & 8) || !(arg0->object_properties_bitfield & 0x10)) {
            func_global_asm_8066F06C(arg0->ledge_info_pointer);
        }
    }
}

// Loop, memcpy, matrix
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066EC6C.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
} Struct8066EE50_1;

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
    s16 unk48;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 unk4F;
    u8 unk50;
    u8 unk51;
} Struct8066EE50_2;

s32 func_global_asm_8066EE50(Struct8066EE50_1 *arg0, Struct8066EE50_2 *arg1) {
    Struct8066D250 sp20;

    sp20.unk0 = arg0->unk0;
    sp20.unk2 = arg0->unkC;
    sp20.unk4 = arg0->unk18;
    sp20.unk6 = arg0->unk4;
    sp20.unk8 = arg0->unk10;
    sp20.unkA = arg0->unk1C;
    sp20.unkC = arg0->unk8;
    sp20.unkE = arg0->unk14;
    sp20.unk10 = arg0->unk20;
    if (func_global_asm_8066D250(&sp20) != 0) {
        return FALSE;
    }
    arg1->unk24 = arg0->unk0 * 8.0f;
    arg1->unk28 = arg0->unkC * 8.0f;
    arg1->unk2C = arg0->unk18 * 8.0f;
    arg1->unk30 = arg0->unk4 * 8.0f;
    arg1->unk34 = arg0->unk10 * 8.0f;
    arg1->unk38 = arg0->unk1C * 8.0f;
    arg1->unk3C = arg0->unk8 * 8.0f;
    arg1->unk40 = arg0->unk14 * 8.0f;
    arg1->unk44 = arg0->unk20 * 8.0f;
    sp20.unk12 = func_global_asm_8066D4DC(&sp20, &sp20.unk13, arg0);
    arg1->unk4B = func_global_asm_8066D2F4(&sp20);
    arg1->unk4D = 0;
    arg1->unk4F = 0;
    arg1->unk51 = 0;
    arg1->unk50 = 0xFF;
    arg1->unk48 = sp20.unk12;
    arg1->unk4C = sp20.unk13;
    func_global_asm_8066DD34(arg1);
    return TRUE;
}

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066F06C.s")

/*
void func_global_asm_8066F06C(LedgeInfo *arg0) {
    s32 temp;
    s32 i;
    LedgeInfo98 *spB0;
    float sp6C[4][4];
    s32 *var_s1;
    s32 *var_s2;
    s32 *var_s3;
    s32 temp_s6;
    s32 temp_t2;
    s32 j;
    u8 var_v1;

    if (arg0->unk98 != NULL) {
        if (object_timer == arg0->unk88) {
            var_v1 = D_global_asm_807444FC;
        } else {
            var_v1 = D_global_asm_807444FC ^ 1;
        }
        temp_s6 = &arg0->unk74[var_v1];
        spB0 = arg0->unk98;
        for (i = 0; i < arg0->unk94; i++) {
            var_s1 = &spB0->unk24;
            var_s2 = &spB0->unk30;
            var_s3 = &spB0->unk3C;
            for (j = 0; j != 0xC; j += 4) {
                if (spB0->unk48 == -1) {
                    memcpy(&sp6C, arg0->unk70, 0x40);
                    guMtxXFMF(&sp6C, spB0->unk0, spB0->unkC, spB0->unk18, var_s1, var_s2, var_s3);
                } else {
                    guMtxXFML(((spB0->unk48 >> 6) << 6) + temp_s6, spB0->unk0, spB0->unkC, spB0->unk18, var_s1, var_s2, var_s3);
                }
                spB0 += 4;
                var_s1++;
                var_s2++;
                var_s3++;
            }
            spB0++;
        }
    }
}
*/

u8 func_global_asm_8066F1F8(Actor *arg0, s16 arg1) {
    s16 sp1E;
    s16 sp1C;
    s8 sp1B;

    D_global_asm_807FB544 = arg1;
    D_global_asm_807FB540 = arg0;
    D_global_asm_807FB546 = 1;
    D_global_asm_807FB604 = 1;
    func_global_asm_8066F274(arg0, &sp1E, &sp1C, &sp1B);
    return D_global_asm_807FB546;
}

u8 func_global_asm_8066F250(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3) {
    D_global_asm_807FB604 = 0;
    return func_global_asm_8066F274(arg0, arg1, arg2, arg3);
}

u8 func_global_asm_8066F274(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3) {
    LedgeInfo *temp_v0;
    u8 sp23;
    u8 sp22;

    sp23 = 0;
    sp22 = 0;
    temp_v0 = arg0->ledge_info_pointer;
    if (arg0->object_properties_bitfield & 0x10000) {
        *arg1 = 0;
        *arg2 = 0xFFF;
    }
    if ((temp_v0 == NULL) || !(arg0->object_properties_bitfield & 0x10)) {
        *arg3 = 0;
        return 0;
    }
    func_global_asm_80672E90(temp_v0->unk0, temp_v0->unk4, temp_v0->unk8);
    func_global_asm_80672C70(arg0->unk58);
    D_global_asm_807FB602 = 0;
    D_global_asm_807FB547 = 0;
    D_global_asm_807FB605 = 0;
    D_global_asm_807FB606 = 0;
    if (arg0->noclip_byte & 0x20) {
        func_global_asm_80674E14(arg0);
    }
    if (arg0->noclip_byte & 8) {
        sp23 = func_global_asm_80670FA4(arg0, arg1, arg2);
        sp22 = func_global_asm_8066F4AC(arg0, arg1, arg2);
        *arg3 = func_global_asm_80676ED0(arg0, arg1, arg2);
    } else {
        *arg3 = 0;
    }
    func_global_asm_8066F400(arg0);
    arg0->unkFD = D_global_asm_807FB547;
    if (D_global_asm_807FB606 != 0) {
        arg0->unk64 |= 0x100;
    } else {
        arg0->unk64 &= ~0x100;
    }
    return sp23 != 0 || sp22 != 0;
}

void func_global_asm_8066F400(Actor *arg0) {
    if (D_global_asm_807FB602) {
        if (arg0->interactable & 1) {
            PlayerAdditionalActorData *PaaD = arg0->PaaD;
            if (PaaD->unkD4 == 0) {
                if (D_global_asm_807FB602 & 1) {
                    func_global_asm_80679290(arg0, 0, 8, 0, 0, 0, 1);
                }
                if (D_global_asm_807FB602 & 2) {
                    func_global_asm_80679290(arg0, 0, 8, 0, 0, 0, 1);
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066F4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066F84C.s")

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066FC0C.s")

s32 func_global_asm_8066FD6C(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;
    switch (arg0->unk58) {
        case 5:
            PaaD = arg0->PaaD;
            if (character_change_array[PaaD->unk1A4].unk2C0 == 1) {
                return 0x32;
            }
            return 0x14;
        case 3:
            return 0x32;
        case 2:
            return 0x32;
        case 4:
            return 0x32;
        case 21:
            return 0x12C;
        default:
            return 0x32;
    }
}

// Scales and rotates a matrix on the stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_8066FE08.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80670548.s")

// Another matrix on the stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80670C5C.s")

void func_global_asm_80670F04(LedgeInfo *arg0) {
    s16 temp_v0 = arg0->unk48;

    D_global_asm_807FB5EC = temp_v0 - 0x32;
    if (D_global_asm_807FB5EC < 0) {
        D_global_asm_807FB5EC = D_global_asm_807FB5EC + 0xFFF;
    }
    D_global_asm_807FB5EE = temp_v0 + 0x32;
    if (D_global_asm_807FB5EC >= 0x1000) {
        D_global_asm_807FB5EE += -0xFFF;
    }
    D_global_asm_807FB5F0 = D_global_asm_807FB5EC + 0x800;
    if (D_global_asm_807FB5F0 >= 0x1000) {
        D_global_asm_807FB5F0 = D_global_asm_807FB5F0 - 0xFFF;
    }
    D_global_asm_807FB5F2 = D_global_asm_807FB5EE + 0x800;
    if (D_global_asm_807FB5F2 >= 0x1000) {
        D_global_asm_807FB5F2 = D_global_asm_807FB5F2 - 0xFFF;
    }
}

u8 func_global_asm_80670FA4(Actor *arg0, s16 *arg1, s16 *arg2) {
    s32 pad[2]; // TODO: Yucky
    LedgeInfo *ledgeInfo;
    LedgeInfo8C *current;
    u8 var_s1;

    ledgeInfo = arg0->ledge_info_pointer;
    ledgeInfo->unk24 = 0;
    D_global_asm_807FB548 = 0;
    var_s1 = 0;
    if (func_global_asm_806730A4(ledgeInfo->unk0, ledgeInfo->unk4, ledgeInfo->unk8, ledgeInfo->unkC) != 0) {
        if (arg0->unk64 & 0x80) {
            D_global_asm_807FB605 = 1;
        }
        func_global_asm_80671880(arg0, 0);
        current = ledgeInfo->unk8C;
        while (current != NULL) {
            if (current->unk26 != 0) {
                if ((current->unk1C != 0) && !(current->unk27 & 1)) {
                    var_s1 |= func_global_asm_806734E4(current->unk10, current->unk14, current->unk18, current->unk1C, arg1, arg2);
                }
            }
            current = current->next;
        }
        if (((var_s1 != 0) || (D_global_asm_807FB605 != 0)) && (D_global_asm_807FB61C != 0)) {
            func_global_asm_80671260(arg0);
        }
        D_global_asm_807FB605 = 0;
    }
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_806710E0.s")

/*
extern s16 D_global_asm_807FB544;
extern s8 D_global_asm_807FB546;
extern s32 D_global_asm_807FB5D0;

void func_global_asm_806710E0(void *arg0, ? arg1, ? arg2, ? arg3) {
    s16 sp36;
    s32 sp30;
    s32 sp28;
    s32 temp_at;
    s32 temp_t7;
    LedgeInfo *temp_v1;
    LedgeInfo *temp_v1_2;

    sp36 = func_global_asm_806CC14C(arg0->unk48, D_global_asm_807FB544);
    temp_at = func_global_asm_806CC14C((arg0->unk48 + 0x800) & 0xFFF, D_global_asm_807FB544) < 0x321;
    if ((sp36 < 0x321) || (temp_at != 0)) {
        func_global_asm_806CC14C(arg0->unk48, extra_player_info_pointer->unkEA);
        func_global_asm_806CC14C((arg0->unk48 + 0x800) & 0xFFF, extra_player_info_pointer->unkEA);
        temp_v1 = D_global_asm_807FB540->ledge_info_pointer;
        func_global_asm_806744A8(arg0, temp_v1->unk0, temp_v1->unk4, temp_v1->unk8, temp_v1->unkC);
        temp_t7 = D_global_asm_807FB5D0;
        sp28 = temp_t7;
        sp30 = func_global_asm_80612794(D_global_asm_807FB544) * 20.0f;
        temp_v1_2 = D_global_asm_807FB540->ledge_info_pointer;
        func_global_asm_806744A8(arg0, temp_v1_2->unk0 + sp30, temp_v1_2->unk4, temp_v1_2->unk8 + (func_global_asm_80612790(D_global_asm_807FB544) * 20.0f), temp_v1_2->unkC);
        if ((temp_t7 - 2) < D_global_asm_807FB5D0) {
            D_global_asm_807FB546 = 0;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671260.s")

s32 func_global_asm_80671528(Actor *, f32 *, f32 *, f32 *, s32);
s32 func_global_asm_806732A8(f32, f32, s32, s16);
extern s16 D_global_asm_80753D50[];
extern s16 D_global_asm_80753D60[];
extern s32 D_global_asm_807FB5C4;
extern s32 D_global_asm_807FB5CC;
extern s16 D_global_asm_807FD584;

extern s32 D_global_asm_807FB5DC;
extern s16 D_global_asm_807FB5F6;

typedef struct {
    s8 unk0[0xE0 - 0x0];
    f32 unkE0;
    f32 unkE4;
    s8 unkE8;
} AAD80671260;

/*
void func_global_asm_80671260(Actor *arg0) {
    AAD80671260 *sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f8;
    f32 var_f16;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        var_f16 = D_global_asm_80753D50[D_global_asm_807FD584];
    } else {
        var_f16 = D_global_asm_80753D60[D_global_asm_807FD584];
    }
    if (arg0->interactable & 1) {
        sp48 = arg0->additional_actor_data;
        func_global_asm_80671528(arg0, &sp38, &sp3C, &sp40, 1);
        temp_f0 = var_f16 / 8.0f;
        temp_f8 = sp38 * temp_f0;
        temp_f12 = D_global_asm_807FB5CC / 8.0f;
        sp40 *= temp_f0;
        sp48->unkE0 = (D_global_asm_807FB5C4 / 8.0f) - temp_f8;
        sp48->unkE4 = temp_f12 - sp40;
        sp48->unkE8 = 1;
        func_global_asm_8066FC0C(arg0, func_global_asm_806732A8(temp_f12, 8.0f, D_global_asm_807FB5DC, D_global_asm_807FB5F6), arg0->ledge_info_pointer);
    }
    func_global_asm_806713E4(arg0, 1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_806713E4.s")

extern s32 D_global_asm_807FB5C4;
extern s32 D_global_asm_807FB5CC;
extern s32 D_global_asm_807FB5D0;

s32 func_global_asm_806717FC(Actor *arg0);

/*
void func_global_asm_806713E4(Actor *arg0, u8 arg1) {
    LedgeInfo *ledgeInfo;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 var_f10;

    if (D_global_asm_807FB5D0 < func_global_asm_806717FC(arg0)) {
        ledgeInfo = arg0->ledge_info_pointer;
        func_global_asm_80671528(arg0, &sp24, &sp28, &sp2C, arg1);
        temp_f12 = D_global_asm_807FB5C4 / 8.0f;
        temp_f14 = D_global_asm_807FB5CC / 8.0f;
        if (D_global_asm_807FB548 != 0) {
            temp_f0 = func_global_asm_806717FC(arg0) / 8.0f;
            var_f10 = sp2C * temp_f0;
            sp24 *= temp_f0;
        } else {
            temp_f0 = (D_global_asm_807FB5D0 + 6) / 8.0f;
            var_f10 = sp2C * temp_f0;
            sp24 *= temp_f0;
        }
        sp2C = var_f10;
        ledgeInfo->unk1C = temp_f12 - sp24;
        ledgeInfo->unk24 = 1;
        ledgeInfo->unk20 = temp_f14 - sp2C;
    }
}
*/

// Actor & Matrix
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671528.s")

s32 func_global_asm_806717FC(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;
    switch (arg0->unk58) {
        case ACTOR_TINY:
            PaaD = arg0->PaaD;
            if (character_change_array[PaaD->unk1A4].unk2C0 != 1) {
                return 20;
            }
            return 50;
        case ACTOR_DIDDY:
            return 50;
        case ACTOR_DK:
            return 50;
        default:
            return 50;
    }
}

// Actor & Matrix
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671880.s")

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671A6C.s")

typedef struct  {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
} fmtx_temp;

typedef struct {
    u8 unk0[0x70 - 0x0];
    f32 *unk70;
    f32 *unk74[1]; // TODO: How many?
    u8 unk78[0x84 - 0x78];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
} Struct80671A6C;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    void *next;
} Struct80671A6C_unk90;

/*
void func_global_asm_80671A6C(Struct80671A6C *arg0, u8 arg1) {
    fmtx_temp *temp_s6;
    u8 var_v0;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp5C[4][4];
    Struct80671A6C_unk90 *current;

    if ((arg1) || object_timer != arg0->unk84) {
        if (object_timer == arg0->unk88) {
            var_v0 = D_global_asm_807444FC;
        } else {
            var_v0 = D_global_asm_807444FC ^ 1;
        }
        current = arg0->unk90;
        temp_s6 = arg0->unk74[var_v0];
        while (current != NULL) {
            if (current->unk18 == -1) {
                memcpy(sp5C, arg0->unk70, 0x40);
                guMtxXFMF(sp5C, current->unk0, current->unk4, current->unk8, &spA4, &spA0, &sp9C);
            } else {
                guMtxXFML(&temp_s6[current->unk18], current->unk0, current->unk4, current->unk8, &spA4, &spA0, &sp9C);
            }
            current->unkC = spA4 * 8.0f;
            current->unk10 = spA0 * 8.0f;
            current->unk14 = sp9C * 8.0f;
            current = current->next;
        }
        arg0->unk84 = object_timer;
    }
}
*/

u8 getBonePosition(Actor *actor, s32 boneIndex, f32 *x, f32 *y, f32 *z) {
    s32 var_v0_2;
    LedgeInfo90 *current;
    u8 var_v0;
    LedgeInfo *temp_t7;
    f32 temp = 8.f;

    temp_t7 = actor->ledge_info_pointer;
    var_v0 = 0;
    if (temp_t7 != NULL) {
        func_global_asm_80671A6C(temp_t7, 1);
        current = actor->ledge_info_pointer->unk90;
        var_v0_2 = boneIndex - 1;
        while ((current != NULL) && (var_v0_2 != 0)) {
            current = current->next;
            var_v0_2 -= 1;
        }
        if (current == NULL) {
            *z = 0.0f;
            *y = 0.0f;
            *x = 0.0f;
            return 0;
        }
        var_v0 = 1;
        
        *x = current->unkC / temp;
        *y = current->unk10 / temp;
        *z = current->unk14 / temp;
        return var_v0;
    }
    return var_v0;
}

void func_global_asm_80671D10(Actor *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 phi_v0 = arg1 - 1;
    LedgeInfo90 *phi_v1 = arg0->ledge_info_pointer->unk90;

    while (phi_v1 && phi_v0) {
        phi_v1 = phi_v1->next;
        phi_v0--;
    }

    *arg2 = phi_v1->unk0;
    *arg3 = phi_v1->unk4;
    *arg4 = phi_v1->unk8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671D64.s")

// extern u8 D_global_asm_807444FC;

/*
// TODO: Yikes
s32 func_global_asm_80671D64(Actor *arg0, s32 arg1) {
    LedgeInfo *temp_v0;
    LedgeInfo90 *var_a1;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a2;
    u8 var_v1;

    temp_v0 = arg0->ledge_info_pointer;
    var_a2 = arg1 - 1;
    if (object_timer == temp_v0->unk88) {
        var_v1 = D_global_asm_807444FC;
    } else {
        var_v1 = D_global_asm_807444FC ^ 1;
    }
    var_a1 = temp_v0->unk90;
    if (var_a2 != 0) {
        temp_v1 = -(var_a2 & 3);
        temp_v0_2 = temp_v1 + var_a2;
        if (temp_v1 != 0) {
            do {
                var_a2 -= 1;
                var_a1 = var_a1->next;
            } while (temp_v0_2 != var_a2);
            if (var_a2 != 0) {
                goto loop_7;
            }
        } else {
            do {
loop_7:
                var_a2 -= 4;
                var_a1 = var_a1->next->next->next->next;
            } while (var_a2 != 0);
        }
    }
    return ((var_a1->unk18 >> 6) << 6) + (temp_v0 + (var_v1 * 4))->unk74;
}
*/

// TODO: Very similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671E00.s")

// Object model 2 loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80671F54.s")

s16 func_global_asm_80672134(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 var_a3;
    s16 temp_v0_2;
    s16 var_a1;
    f32 var_f2;
    s16 var_v0;

    if (arg1 >= arg0) {
        if (arg2 >= arg0 && arg1 >= arg2) {
            return 9999;
        }
    } else {
        if (!(arg2 < arg0) || arg1 >= arg2) {
            return 9999;
        }
    }
    var_a3 = arg2 + 0x800;
    if (var_a3 >= 0x1000) {
        var_a3 = var_a3 - 0x1000;
    }
    temp_v0_2 = func_global_asm_80672A70(arg0, arg1);
    var_a1 = ABS(arg0 - temp_v0_2);
    if (var_a1 >= 0x800) {
        var_a1 = 0xFFF - var_a1;
    }
    var_v0 = ABS(var_a3 - temp_v0_2);
    if (var_v0 >= 0x800) {
        var_v0 = 0xFFF - var_v0;
    }
    if (var_a1 != 0) {
        var_f2 = (f32)var_v0 / var_a1;
    } else {
        var_f2 = 0.0f;
    }
    if (var_f2 > 1.0) {
        var_f2 = 1.0f;
    }
    if (var_f2 < 0.2) {
        var_f2 = 0.0f;
    }
    return arg3 * var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_global_asm_80672328.s")

s32 func_global_asm_806725A0(Actor *arg0, s16 arg1);
s32 func_global_asm_80611E60(s32, s32);

/*
// TODO: Pretty close
// Float, s16 and stack nonsense
s32 func_global_asm_80672328(Actor *arg0, f32 arg1, f32 arg2) {
    s32 temp_f6;
    s32 temp_v1;
    s32 temp_f16;
    s32 temp_a1;
    s32 temp_f8;
    s32 temp_f18;
    s32 phi_a2;
    s32 phi_v1;
    f32 temp_f0;

    temp_f8 = arg0->unk88 * 8.0f;
    temp_f6 = arg1 * 8.0f;
    temp_f18 = arg0->unk90 * 8.0f;
    temp_v1 = temp_f6 - temp_f8;
    temp_f16 = arg2 * 8.0f;
    temp_a1 = temp_f16 - temp_f18;
    temp_f0 = sqrtf((temp_v1 * temp_v1) + (temp_a1 * temp_a1));
    if (temp_f0 == 0.0) {
        return TRUE;
    }
    if ((temp_v1 >= 0) && (temp_a1 >= 0)) {
        phi_a2 = func_global_asm_80611E60((temp_v1 * 65535.9) / temp_f0, temp_a1) >> 4;
    }
    if (((temp_f6 - temp_f8) >= 0) && ((temp_f16 - temp_f18) < 0)) {
        phi_a2 = (func_global_asm_80611E60(((temp_f18 - temp_f16) * 65535.9) / temp_f0, temp_f16 - temp_f18) >> 4) + 0x400;
    }
    if (((temp_f6 - temp_f8) < 0) && ((temp_f16 - temp_f18) < 0)) {
        phi_a2 = (func_global_asm_80611E60(((temp_f8 - temp_f6) * 65535.9) / temp_f0, temp_f16 - temp_f18) >> 4) + 0x800;
    }
    if (((temp_f6 - temp_f8) < 0) && ((temp_f16 - temp_f18) >= 0)) {
        phi_a2 = (func_global_asm_80611E60(((temp_f16 - temp_f18) * 65535.9) / temp_f0, temp_f16 - temp_f18) >> 4) + 0xC00;
    }
    return func_global_asm_806725A0(arg0, phi_a2) ? TRUE : FALSE;
}
*/

s32 func_global_asm_806725A0(Actor *arg0, s16 arg1) {
    s16 sp26, sp24;

    return func_global_asm_80672680(sp24, arg1, arg0->unkF4, arg0->unkF6, &sp26);
}

s32 func_global_asm_806725E4(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 sp26, sp24;

    return func_global_asm_806726DC(sp24, arg2, arg0, arg1, &sp26, arg3);
}

s32 func_global_asm_80672630(Actor *arg0, s16 arg1, s16 arg2) {
    s16 sp26, sp24;

    return func_global_asm_806726DC(sp24, arg1, arg0->unkF4, arg0->unkF6, &sp26, arg2);
}

s32 func_global_asm_80672680(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16* arg4) {
    return func_global_asm_806726DC(arg0, arg1, arg2, arg3, arg4, 0xA);
}

s32 func_global_asm_806726DC(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 arg5) {
    u8 phi_a0;
    s16 phi_t2 = arg2 + arg5;
    s16 phi_t3 = arg3 - arg5;

    if (arg3 >= arg2) {
        if ((phi_t2 < phi_t3) && (arg1 >= phi_t2) && (phi_t3 >= arg1)) {
            *arg4 = arg1;
            return TRUE;
        }
        *arg4 = func_global_asm_806728F0(arg2, arg3, arg1);
    } else {
        phi_a0 = 0;
        if (phi_t2 >= 0x1000) {
            phi_t2 -= 0x1000;
            phi_a0 = 1;
        }
        if (phi_t3 < 0) {
            phi_t3 += 0x1000;
            phi_a0 += 2;
        }
        switch (phi_a0) {
            case 0:
                if ((arg1 >= phi_t2) || (phi_t3 >= arg1)) {
                    *arg4 = arg1;
                    return TRUE;
                }
                *arg4 = func_global_asm_806728F0(arg2, arg3, arg1);
                break;
            case 1:
            case 2:
                if ((phi_t2 < phi_t3) && (arg1 >= phi_t2) && (phi_t3 >= arg1)) {
                    *arg4 = arg1;
                    return TRUE;
                }
                *arg4 = func_global_asm_806728F0(arg2, arg3, arg1);
                break;
            case 3:
                *arg4 = func_global_asm_806728F0(arg2, arg3, arg1);
                break;
        }
    }
    return FALSE;
}

s32 func_global_asm_806728F0(s16 arg0, s16 arg1, s16 arg2) {
    s16 phi_a3;
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a0;
    s16 phi_v1;

    phi_a3 = arg0 + 0xA;
    phi_t0 = arg1 - 0xA;
    phi_a0 = ABS(arg0 - arg2);
    if (phi_a0 >= 0x801) {
        phi_a0 = 0xFFF - phi_a0;
    }
    phi_v0 = ABS(arg1 - arg2);
    if (phi_v0 >= 0x801) {
        phi_v0 = 0xFFF - phi_v0;
    }
    if (phi_v0 >= phi_a0) {
        if (phi_a3 >= 0x1000) {
            phi_a3 -= 0xFFF;
        }
        phi_v1 = phi_a3;
    } else {
        if (phi_t0 < 0) {
            phi_t0 += 0xFFF;
        }
        phi_v1 = phi_t0;
    }
    if (arg1 >= arg0) {
        if ((phi_v1 < arg0) || (arg1 < phi_v1)) {
            phi_v1 = func_global_asm_80672A70(arg0, arg1);
        }
    } else if ((phi_v1 < arg0) && (arg1 < phi_v1)) {
        phi_v1 = func_global_asm_80672A70(arg0, arg1);
    }
    return phi_v1;
}

s16 func_global_asm_80672A70(s16 arg0, s16 arg1) {
    s16 temp_v0;

    if (arg1 >= arg0) {
        return (arg0 + arg1) >> 1;
    }
    temp_v0 = (((arg1 - arg0) + 0xFFF) / 2) + arg0;
    if (temp_v0 >= 0x1000) {
        temp_v0 -= 0xFFF;
    }
    return temp_v0;
}

void func_global_asm_80672AFC(Actor *actor) {
    LedgeInfo *ledgeInfo = actor->ledge_info_pointer;
    if (ledgeInfo) {
        ledgeInfo->unk88 = object_timer;
    }
}

void func_global_asm_80672B1C(Actor *actor) {
    if (actor->noclip_byte & 8) {
        if (actor->ledge_info_pointer->unk6C) {
            actor->unkFC |= func_global_asm_80670548();
        } else {
            actor->ledge_info_pointer->unk60 = 0;
        }
        if (actor->object_properties_bitfield & 0x20) {
            if (actor->ledge_info_pointer->unk24) {
                if (func_global_asm_80672328(actor, actor->ledge_info_pointer->unk1C, actor->ledge_info_pointer->unk20) != 0) {
                    actor->x_position = actor->ledge_info_pointer->unk1C;
                    actor->z_position = actor->ledge_info_pointer->unk20;
                }
            }
        }
    } else {
        if (actor->ledge_info_pointer) {
            actor->ledge_info_pointer->unk6C = 0;
        }
    }
}

u8 func_global_asm_80672BD4(Actor *arg0) {
    return arg0->locked_to_pad
        || arg0->ledge_info_pointer->unk6C
        || arg0->ledge_info_pointer->unk24
        || (arg0->unk6A & 8)
        || (arg0->unk6A & 0x400);
}

void func_global_asm_80672C30(Actor *arg0) {
    arg0->locked_to_pad = 0;
    if (arg0->ledge_info_pointer) {
        arg0->ledge_info_pointer->unk6C = 0;
        arg0->ledge_info_pointer->unk24 = 0;
    }
    arg0->unk6A &= ~0x8;
    arg0->unk6A &= ~0x400;
    arg0->unk64 |= 0x2000;
}

void func_global_asm_80672C70(s32 arg0) {
    D_global_asm_807FB53C = arg0;
    if ((arg0 != 0) && (arg0 != 0xBC)) {
        D_global_asm_807FB5F8 = 2;
        D_global_asm_807FB5FA = 0xA;
    } else {
        D_global_asm_807FB5F8 = 0x64;
        D_global_asm_807FB5FA = 0x64;
    }
}

extern s32 D_global_asm_807FB53C;
extern s8 D_global_asm_807FB548;

s32 func_global_asm_80672CBC(s8 arg0) {
    PlayerAdditionalActorData *PaaD;

    switch (arg0) {
        case 0:
            if (D_global_asm_807FB53C == 0xBC) {
                return TRUE;
            }
            break;
        case 1:
            if (D_global_asm_807FB53C != 0xBC) {
                return TRUE;
            }
            break;
        case 2:
            if ((D_global_asm_807FB53C != 5) || (character_change_array->unk2C0 == 1)) {
                return TRUE;
            }
            break;
        case 3:
            if ((D_global_asm_807FB53C == 5) && (character_change_array->unk2C0 != 1)) {
                return TRUE;
            }
            break;
        case 4:
            if (D_global_asm_807FB53C == 8) {
                return TRUE;
            }
            break;
        case 5:
            D_global_asm_807FB548 = 1;
            return TRUE;
        case 6:
            PaaD = player_pointer->PaaD;
            if ((D_global_asm_807FB53C == 3) && (PaaD->unk1A3 != 0)) {
                return TRUE;
            }
            break;
        case 7:
            PaaD = player_pointer->PaaD;
            if ((D_global_asm_807FB53C == 6) && ((character_change_array->unk2C0 != 1) || (PaaD->unk1CC != PaaD->unk1C0))) {
                return TRUE;
            }
            break;
        case 8:
            if (D_global_asm_807FB53C == 9) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void func_global_asm_80672E64(void) {

}

void func_global_asm_80672E6C(void) {
    func_global_asm_806119A0();
}
