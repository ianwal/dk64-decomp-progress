#include <ultra64.h>
#include "functions.h"


void func_8066EC6C(LedgeInfo *);
void func_8066F06C(LedgeInfo *);
void func_80679290(Actor *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_8066C2D0(s32, s32, f32, f32, f32, f32, f32, f32, f32);

s32 func_80672328(Actor*, f32, f32);
s32 func_80672680(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16* arg4);
s32 func_806726DC(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 arg5);

extern s32 D_807FB53C;
extern Actor *D_807FB540;
extern s16 D_807FB544;
extern u8 D_807FB546;
extern s16 D_807FB5EC;
extern s16 D_807FB5EE;
extern s16 D_807FB5F0;
extern s16 D_807FB5F2;
extern s16 D_807FB5F8;
extern s16 D_807FB5FA;
extern u8 D_807FB602;
extern u8 D_807FB604;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066C2D0.s")

// Doable, model2 matrix stuff, might need some more structs/arrays defined though
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066C610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066C7F4.s")

void func_8066C8B0(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    func_8066C2D0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066C904.s")

// Loads walls for the current map from pointer table 2
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066C958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066CB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066CCD8.s")

void func_8066CDD0() {
    func_8066CDF8();
    func_806687E0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066CDF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066CEE4.s")

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

s32 func_8066D250(Struct8066D250 *arg0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066D2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066D4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066DB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066DD34.s")

void func_8066E21C(LedgeInfo *ledgeInfo) {
    LedgeInfo8C *current;
    LedgeInfo8C *next;
    LedgeInfo90 *current2;
    LedgeInfo90 *next2;

    if (ledgeInfo) {
        current = ledgeInfo->unk8C;
        while (current) {
            next = current->next;
            func_8061130C(current);
            current = next;
        }
        current2 = ledgeInfo->unk90;
        while (current2) {
            next2 = current2->next;
            func_8061130C(current2);
            current2 = next2;
        }
        if (ledgeInfo->unkA0) {
            func_8061130C(ledgeInfo->unkA0);
        }
        if (ledgeInfo->unk98) {
            func_8061130C(ledgeInfo->unk98);
        }
        func_8061130C(ledgeInfo);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066E2C0.s")

LedgeInfo8C *func_8066EAEC(Actor*, s32);

void func_8066E5CC(Actor *arg0, s32 arg1, u16 arg2) {
    LedgeInfo8C *temp_v0 = func_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk24 = arg2;
    }
}

void func_8066E5F8(Actor *arg0, s32 arg1, u8 arg2) {
    LedgeInfo8C *temp_v0 = func_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk27 |= arg2;
    }
}

void func_8066E62C(Actor *arg0, s32 arg1, u8 arg2) {
    LedgeInfo8C *temp_v0 = func_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk27 &= ~arg2;
    }
}

void func_8066E664(Actor *arg0, s32 arg1, u8 arg2) {
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

void func_8066E6C8(Actor *arg0, s32 arg1, u8 arg2) {
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

void func_8066E72C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, void *arg7, s32 arg8) {
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

void func_8066E854(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
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

void func_8066E8E4(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
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

// TODO: Matches, but kinda ugly
// Any cleanup possible?
void func_8066E990(Actor *arg0) {
    LedgeInfo *sp24;
    LedgeInfo *var_v0;
    LedgeInfo8C *temp_s1;
    LedgeInfo8C *var_s0;

    var_v0 = arg0->ledge_info_pointer;
    if (var_v0 != NULL) {
        var_s0 = var_v0->unk8C;
        if (var_s0 != NULL) {
            sp24 = var_v0;
            do {
                temp_s1 = var_s0->next;
                func_8061130C(var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
            var_v0 = sp24;
        }
        var_v0->unk8C = NULL;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066E9EC.s")

/*
// TODO: Pretty close, surprisingly fiddly
f32 func_8066E9EC(Actor *arg0, s32 arg1, f32 arg2) {
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

void func_8066EA64(Actor *arg0, s32 arg1) {
    LedgeInfo8C *temp_v0 = func_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk26 = 1;
    }
}

void func_8066EA90(Actor *arg0, s32 arg1) {
    LedgeInfo8C *temp_v0 = func_8066EAEC(arg0, arg1);
    if (temp_v0) {
        temp_v0->unk26 = 0;
    }
}

void func_8066EABC(Actor *arg0) {
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

LedgeInfo8C *func_8066EAEC(Actor *arg0, s32 arg1) {
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

void func_8066EB40(Actor *arg0, f32 arg1) {
    LedgeInfo *ledgeInfo = arg0->ledge_info_pointer;
    ledgeInfo->unk14 = arg1;
}

void func_8066EB50(Actor *actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
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

void func_8066EBF4(Actor *arg0) {
    if (arg0->ledge_info_pointer) {
        if (!(arg0->object_properties_bitfield & 0x80000000) || ((arg0->object_properties_bitfield & 0x10) == 0)) {
            func_8066EC6C(arg0->ledge_info_pointer);
        }
        if (!(arg0->unk64 & 8) || !(arg0->object_properties_bitfield & 0x10)) {
            func_8066F06C(arg0->ledge_info_pointer);
        }
    }
}

// Loop, memcpy, matrix
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066EC6C.s")

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

s32 func_8066EE50(Struct8066EE50_1 *arg0, Struct8066EE50_2 *arg1) {
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
    if (func_8066D250(&sp20) != 0) {
        return 0;
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
    sp20.unk12 = func_8066D4DC(&sp20, &sp20.unk13, arg0);
    arg1->unk4B = func_8066D2F4(&sp20);
    arg1->unk4D = 0;
    arg1->unk4F = 0;
    arg1->unk51 = 0;
    arg1->unk50 = 0xFF;
    arg1->unk48 = sp20.unk12;
    arg1->unk4C = sp20.unk13;
    func_8066DD34(arg1);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066F06C.s")

extern u8 D_807444FC;

/*
// TODO: Close, doable
void func_8066F06C(LedgeInfo *arg0) {
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
            var_v1 = D_807444FC;
        } else {
            var_v1 = D_807444FC ^ 1;
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

u8 func_8066F274(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3);

u8 func_8066F1F8(Actor *arg0, s16 arg1) {
    s16 sp1E;
    s16 sp1C;
    s8 sp1B;

    D_807FB544 = arg1;
    D_807FB540 = arg0;
    D_807FB546 = 1;
    D_807FB604 = 1;
    func_8066F274(arg0, &sp1E, &sp1C, &sp1B);
    return D_807FB546;
}

u8 func_8066F250(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3) {
    D_807FB604 = 0;
    return func_8066F274(arg0, arg1, arg2, arg3);
}

void func_8066F400(Actor *);
u8 func_8066F4AC(Actor *, s16 *, s16 *);
u8 func_80670FA4(Actor *, s16 *, s16 *);
void func_80672C70(s32);
void func_80672E90(s32, s32, s32);
void func_80674E14(Actor *);
s8 func_80676ED0(Actor *, s16 *, s16 *);
extern u8 D_807FB547;
extern u8 D_807FB605;
extern u8 D_807FB606;

u8 func_8066F274(Actor *arg0, s16 *arg1, s16 *arg2, s8 *arg3) {
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
    func_80672E90(temp_v0->unk0, temp_v0->unk4, temp_v0->unk8);
    func_80672C70(arg0->unk58);
    D_807FB602 = 0;
    D_807FB547 = 0;
    D_807FB605 = 0;
    D_807FB606 = 0;
    if (arg0->noclip_byte & 0x20) {
        func_80674E14(arg0);
    }
    if (arg0->noclip_byte & 8) {
        sp23 = func_80670FA4(arg0, arg1, arg2);
        sp22 = func_8066F4AC(arg0, arg1, arg2);
        *arg3 = func_80676ED0(arg0, arg1, arg2);
    } else {
        *arg3 = 0;
    }
    func_8066F400(arg0);
    arg0->unkFD = D_807FB547;
    if (D_807FB606 != 0) {
        arg0->unk64 |= 0x100;
    } else {
        arg0->unk64 &= ~0x100;
    }
    return sp23 != 0 || sp22 != 0;
}

void func_8066F400(Actor *arg0) {
    if (D_807FB602) {
        if (arg0->interactable & 1) {
            PlayerAdditionalActorData *PaaD = arg0->PaaD;
            if (PaaD->unkD4 == 0) {
                if (D_807FB602 & 1) {
                    func_80679290(arg0, 0, 8, 0, 0, 0, 1);
                }
                if (D_807FB602 & 2) {
                    func_80679290(arg0, 0, 8, 0, 0, 0, 1);
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066F4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066F84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066FC0C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066FD6C.s")

// Scales and rotates a matrix on the stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_8066FE08.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80670548.s")

// Another matrix on the stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80670C5C.s")

void func_80670F04(LedgeInfo *arg0) {
    s16 temp_v0 = arg0->unk48;

    D_807FB5EC = temp_v0 - 0x32;
    if (D_807FB5EC < 0) {
        D_807FB5EC = D_807FB5EC + 0xFFF;
    }
    D_807FB5EE = temp_v0 + 0x32;
    if (D_807FB5EC >= 0x1000) {
        D_807FB5EE += -0xFFF;
    }
    D_807FB5F0 = D_807FB5EC + 0x800;
    if (D_807FB5F0 >= 0x1000) {
        D_807FB5F0 = D_807FB5F0 - 0xFFF;
    }
    D_807FB5F2 = D_807FB5EE + 0x800;
    if (D_807FB5F2 >= 0x1000) {
        D_807FB5F2 = D_807FB5F2 - 0xFFF;
    }
}

s32 func_806730A4(s32, s32, s32, s32);
s32 func_806734E4(s32, s32, s32, s32, s16 *, s16 *);
extern s8 D_807FB548;
extern u8 D_807FB61C;

void func_80671260(Actor *arg0);

u8 func_80670FA4(Actor *arg0, s16 *arg1, s16 *arg2) {
    s32 pad[2]; // TODO: Yucky
    LedgeInfo *ledgeInfo;
    LedgeInfo8C *current;
    u8 var_s1;

    ledgeInfo = arg0->ledge_info_pointer;
    ledgeInfo->unk24 = 0;
    D_807FB548 = 0;
    var_s1 = 0;
    if (func_806730A4(ledgeInfo->unk0, ledgeInfo->unk4, ledgeInfo->unk8, ledgeInfo->unkC) != 0) {
        if (arg0->unk64 & 0x80) {
            D_807FB605 = 1;
        }
        func_80671880(arg0, 0);
        current = ledgeInfo->unk8C;
        while (current != NULL) {
            if (current->unk26 != 0) {
                if ((current->unk1C != 0) && !(current->unk27 & 1)) {
                    var_s1 |= func_806734E4(current->unk10, current->unk14, current->unk18, current->unk1C, arg1, arg2);
                }
            }
            current = current->next;
        }
        if (((var_s1 != 0) || (D_807FB605 != 0)) && (D_807FB61C != 0)) {
            func_80671260(arg0);
        }
        D_807FB605 = 0;
    }
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_806710E0.s")

/*
extern s16 D_807FB544;
extern s8 D_807FB546;
extern s32 D_807FB5D0;

void func_806710E0(void *arg0, ? arg1, ? arg2, ? arg3) {
    s16 sp36;
    s32 sp30;
    s32 sp28;
    s32 temp_at;
    s32 temp_t7;
    LedgeInfo *temp_v1;
    LedgeInfo *temp_v1_2;

    sp36 = func_806CC14C(arg0->unk48, D_807FB544);
    temp_at = func_806CC14C((arg0->unk48 + 0x800) & 0xFFF, D_807FB544) < 0x321;
    if ((sp36 < 0x321) || (temp_at != 0)) {
        func_806CC14C(arg0->unk48, extra_player_info_pointer->unkEA);
        func_806CC14C((arg0->unk48 + 0x800) & 0xFFF, extra_player_info_pointer->unkEA);
        temp_v1 = D_807FB540->ledge_info_pointer;
        func_806744A8(arg0, temp_v1->unk0, temp_v1->unk4, temp_v1->unk8, temp_v1->unkC);
        temp_t7 = D_807FB5D0;
        sp28 = temp_t7;
        sp30 = func_80612794(D_807FB544) * 20.0f;
        temp_v1_2 = D_807FB540->ledge_info_pointer;
        func_806744A8(arg0, temp_v1_2->unk0 + sp30, temp_v1_2->unk4, temp_v1_2->unk8 + (func_80612790(D_807FB544) * 20.0f), temp_v1_2->unkC);
        if ((temp_t7 - 2) < D_807FB5D0) {
            D_807FB546 = 0;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671260.s")

s32 func_80671528(Actor *, f32 *, f32 *, f32 *, s32);
s32 func_806732A8(f32, f32, s32, s16);
extern s16 D_80753D50[];
extern s16 D_80753D60[];
extern s32 D_807FB5C4;
extern s32 D_807FB5CC;
extern s16 D_807FD584;

extern s32 D_807FB5DC;
extern s16 D_807FB5F6;

typedef struct {
    s8 unk0[0xE0 - 0x0];
    f32 unkE0;
    f32 unkE4;
    s8 unkE8;
} AAD80671260;

/*
void func_80671260(Actor *arg0) {
    AAD80671260 *sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f8;
    f32 var_f16;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        var_f16 = D_80753D50[D_807FD584];
    } else {
        var_f16 = D_80753D60[D_807FD584];
    }
    if (arg0->interactable & 1) {
        sp48 = arg0->additional_actor_data;
        func_80671528(arg0, &sp38, &sp3C, &sp40, 1);
        temp_f0 = var_f16 / 8.0f;
        temp_f8 = sp38 * temp_f0;
        temp_f12 = D_807FB5CC / 8.0f;
        sp40 *= temp_f0;
        sp48->unkE0 = (D_807FB5C4 / 8.0f) - temp_f8;
        sp48->unkE4 = temp_f12 - sp40;
        sp48->unkE8 = 1;
        func_8066FC0C(arg0, func_806732A8(temp_f12, 8.0f, D_807FB5DC, D_807FB5F6), arg0->ledge_info_pointer);
    }
    func_806713E4(arg0, 1);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_806713E4.s")

extern s32 D_807FB5C4;
extern s32 D_807FB5CC;
extern s32 D_807FB5D0;

s32 func_806717FC(Actor *arg0);

/*
void func_806713E4(Actor *arg0, u8 arg1) {
    LedgeInfo *ledgeInfo;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 var_f10;

    if (D_807FB5D0 < func_806717FC(arg0)) {
        ledgeInfo = arg0->ledge_info_pointer;
        func_80671528(arg0, &sp24, &sp28, &sp2C, arg1);
        temp_f12 = D_807FB5C4 / 8.0f;
        temp_f14 = D_807FB5CC / 8.0f;
        if (D_807FB548 != 0) {
            temp_f0 = func_806717FC(arg0) / 8.0f;
            var_f10 = sp2C * temp_f0;
            sp24 *= temp_f0;
        } else {
            temp_f0 = (D_807FB5D0 + 6) / 8.0f;
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671528.s")

s32 func_806717FC(Actor *arg0) {
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671A6C.s")

u8 func_80671C0C(Actor *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 var_v0_2;
    LedgeInfo90 *current;
    u8 var_v0;
    LedgeInfo *temp_t7;
    f32 temp = 8.f;

    temp_t7 = arg0->ledge_info_pointer;
    var_v0 = 0;
    if (temp_t7 != NULL) {
        func_80671A6C(temp_t7, 1);
        current = arg0->ledge_info_pointer->unk90;
        var_v0_2 = arg1 - 1;
        while ((current != NULL) && (var_v0_2 != 0)) {
            current = current->next;
            var_v0_2 -= 1;
        }
        if (current == NULL) {
            *arg4 = 0.0f;
            *arg3 = 0.0f;
            *arg2 = 0.0f;
            return 0;
        }
        var_v0 = 1;
        
        *arg2 = current->unkC / temp;
        *arg3 = current->unk10 / temp;
        *arg4 = current->unk14 / temp;
        return var_v0;
    }
    return var_v0;
}

void func_80671D10(Actor *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671D64.s")

// extern u8 D_807444FC;

/*
// TODO: Yikes
s32 func_80671D64(Actor *arg0, s32 arg1) {
    LedgeInfo *temp_v0;
    LedgeInfo90 *var_a1;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a2;
    u8 var_v1;

    temp_v0 = arg0->ledge_info_pointer;
    var_a2 = arg1 - 1;
    if (object_timer == temp_v0->unk88) {
        var_v1 = D_807444FC;
    } else {
        var_v1 = D_807444FC ^ 1;
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671E00.s")

// Object model 2 loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80671F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80672134.s")

extern f64 D_80759150;

/*
// TODO: Extremely close
s16 func_80672134(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 var_a3;
    s16 temp_v0_2;
    s16 var_a1;
    f32 var_f2;
    s16 var_v0;

    if (arg1 >= arg0 && arg2 >= arg0 && arg1 >= arg2) {
        return 9999;
    } else if (arg2 < arg0 && arg1 >= arg2) {
        return 9999;
    } else {
        var_a3 = arg2 + 0x800;
        if (var_a3 >= 0x1000) {
            var_a3 = var_a3 - 0x1000;
        }
        temp_v0_2 = func_80672A70(arg0, arg1);
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
        if (var_f2 < D_80759150) {
            var_f2 = 0.0f;
        }
        return arg3 * var_f2;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80672328.s")

extern f64 D_80759158;
extern f64 D_80759160;
extern f64 D_80759168;
extern f64 D_80759170;

s32 func_806725A0(Actor *arg0, s16 arg1);
s32 func_80611E60(s32, s32);

/*
// TODO: Pretty close
// Float, s16 and stack nonsense
s32 func_80672328(Actor *arg0, f32 arg1, f32 arg2) {
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
        phi_a2 = func_80611E60((temp_v1 * D_80759158) / temp_f0, temp_a1) >> 4;
    }
    if (((temp_f6 - temp_f8) >= 0) && ((temp_f16 - temp_f18) < 0)) {
        phi_a2 = (func_80611E60(((temp_f18 - temp_f16) * D_80759160) / temp_f0, temp_f16 - temp_f18) >> 4) + 0x400;
    }
    if (((temp_f6 - temp_f8) < 0) && ((temp_f16 - temp_f18) < 0)) {
        phi_a2 = (func_80611E60(((temp_f8 - temp_f6) * D_80759168) / temp_f0, temp_f16 - temp_f18) >> 4) + 0x800;
    }
    if (((temp_f6 - temp_f8) < 0) && ((temp_f16 - temp_f18) >= 0)) {
        phi_a2 = (func_80611E60(((temp_f16 - temp_f18) * D_80759170) / temp_f0, temp_f16 - temp_f18) >> 4) + 0xC00;
    }
    return func_806725A0(arg0, phi_a2) ? TRUE : FALSE;
}
*/

s32 func_806725A0(Actor *arg0, s16 arg1) {
    s16 sp26, sp24;

    return func_80672680(sp24, arg1, arg0->unkF4, arg0->unkF6, &sp26);
}

s32 func_806725E4(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 sp26, sp24;

    return func_806726DC(sp24, arg2, arg0, arg1, &sp26, arg3);
}

s32 func_80672630(Actor *arg0, s16 arg1, s16 arg2) {
    s16 sp26, sp24;

    return func_806726DC(sp24, arg1, arg0->unkF4, arg0->unkF6, &sp26, arg2);
}

s32 func_80672680(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16* arg4) {
    return func_806726DC(arg0, arg1, arg2, arg3, arg4, 0xA);
}

s32 func_806726DC(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 arg5) {
    u8 phi_a0;
    s16 phi_t2 = arg2 + arg5;
    s16 phi_t3 = arg3 - arg5;

    if (arg3 >= arg2) {
        if ((phi_t2 < phi_t3) && (arg1 >= phi_t2) && (phi_t3 >= arg1)) {
            *arg4 = arg1;
            return TRUE;
        }
        *arg4 = func_806728F0(arg2, arg3, arg1);
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
                *arg4 = func_806728F0(arg2, arg3, arg1);
                break;
            case 1:
            case 2:
                if ((phi_t2 < phi_t3) && (arg1 >= phi_t2) && (phi_t3 >= arg1)) {
                    *arg4 = arg1;
                    return TRUE;
                }
                *arg4 = func_806728F0(arg2, arg3, arg1);
                break;
            case 3:
                *arg4 = func_806728F0(arg2, arg3, arg1);
                break;
        }
    }
    return FALSE;
}

s32 func_806728F0(s16 arg0, s16 arg1, s16 arg2) {
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
            phi_v1 = func_80672A70(arg0, arg1);
        }
    } else if ((phi_v1 < arg0) && (arg1 < phi_v1)) {
        phi_v1 = func_80672A70(arg0, arg1);
    }
    return phi_v1;
}

s16 func_80672A70(s16 arg0, s16 arg1) {
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

void func_80672AFC(Actor *actor) {
    LedgeInfo *ledgeInfo = actor->ledge_info_pointer;
    if (ledgeInfo) {
        ledgeInfo->unk88 = object_timer;
    }
}

void func_80672B1C(Actor *actor) {
    if (actor->noclip_byte & 8) {
        if (actor->ledge_info_pointer->unk6C) {
            actor->unkFC |= func_80670548();
        } else {
            actor->ledge_info_pointer->unk60 = 0;
        }
        if (actor->object_properties_bitfield & 0x20) {
            if (actor->ledge_info_pointer->unk24) {
                if (func_80672328(actor, actor->ledge_info_pointer->unk1C, actor->ledge_info_pointer->unk20) != 0) {
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

u8 func_80672BD4(Actor *arg0) {
    return arg0->locked_to_pad
        || arg0->ledge_info_pointer->unk6C
        || arg0->ledge_info_pointer->unk24
        || (arg0->unk6A & 8)
        || (arg0->unk6A & 0x400);
}

void func_80672C30(Actor *arg0) {
    arg0->locked_to_pad = 0;
    if (arg0->ledge_info_pointer) {
        arg0->ledge_info_pointer->unk6C = 0;
        arg0->ledge_info_pointer->unk24 = 0;
    }
    arg0->unk6A &= ~0x8;
    arg0->unk6A &= ~0x400;
    arg0->unk64 |= 0x2000;
}

void func_80672C70(s32 arg0) {
    D_807FB53C = arg0;
    if ((arg0 != 0) && (arg0 != 0xBC)) {
        D_807FB5F8 = 2;
        D_807FB5FA = 0xA;
    } else {
        D_807FB5F8 = 0x64;
        D_807FB5FA = 0x64;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_70FD0/func_80672CBC.s")

void func_80672E64(void) {

}

void func_80672E6C() {
    func_806119A0();
}