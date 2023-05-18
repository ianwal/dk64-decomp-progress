#include <ultra64.h>
#include "functions.h"


typedef struct Temp8070D6D8 {
    s32 unk0;
    s32 unk4;
    u16 unk8; // Size
    u16 unkA;
    void *unkC; // Next?
} Temp8070D6D8;

// TODO: What the
void func_8070D380(u32 size, Temp8070D6D8 *arg1, u8 **arg2) {
    memcpy(arg1, *arg2, size);
    *arg2 += size;
}

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
} Struct8070D3CC_arg0;

typedef struct {
    s32 unk0;
} Struct8070D3CC_arg1;

void func_8070D3CC(Struct8070D3CC_arg0 *arg0, Struct8070D3CC_arg1 *arg1) {
    s32 i;
    Struct8070D3CC_arg0 *var_s0;

    func_8070D380(1, arg0, arg1);
    arg0->unk4 = malloc(arg0->unk0 * sizeof(Struct8070D3CC_arg0));
    var_s0 = arg0->unk4;
    for (i = 0; i < arg0->unk0; i++) {
        func_8070D380(sizeof(Struct8070D3CC_arg0), var_s0, arg1);
        var_s0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D654.s")

Temp8070D6D8 *func_8070D6D8(void *arg0) {
    Temp8070D6D8 *temp_s0;
    s32 size;

    temp_s0 = malloc(sizeof(Temp8070D6D8));
    func_8070D380(1, temp_s0, &arg0);
    func_8070D654(temp_s0, &arg0);
    func_8070D380(2, &temp_s0->unk8, &arg0);
    size = temp_s0->unk8;
    temp_s0->unkC = malloc(size);
    memcpy(temp_s0->unkC, arg0, size);
    return temp_s0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D754.s")

/*
? *func_8070D754(? *arg0) {
    ? **var_s0;
    ? *temp_v0;
    ? *var_v1;

    var_s0 = &D_807550C4;
    if ((D_807550C4 != NULL) && (arg0 != *D_807550C4)) {
        var_v1 = D_807550C4;
loop_3:
        var_s0 = &*(var_v1 + 0xC);
        var_v1 = *var_s0;
        if (var_v1 != NULL) {
            if (arg0 != *var_v1) {
                goto loop_3;
            }
        }
    }
    if (*var_s0 == NULL) {
        temp_v0 = malloc(0x10);
        *var_s0 = temp_v0;
        func_80611690(temp_v0);
        (*var_s0)->unk0 = arg0;
        func_80677FA8(ACTOR_TEXT_BUBBLE, 0, arg0);
        D_807FBB44->control_state = 0;
        (*var_s0)->unk4 = D_807FBB44;
        D_807FBB44->additional_actor_data->unk4 = arg0;
    }
    return *var_s0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D82C.s")

extern u8 D_807550CC;

typedef struct {
    s32 unk0;
    Actor* unk4;
} Struct8070D8C0;

typedef struct {
    u8 unk0[0x54 - 0x0];
    u8 unk54;
} AAD_8070D8C0;

void func_8070D82C(s32, s32, s32);

void func_8070D8C0(Actor *arg0, u16 arg1, u8 arg2) {
    Struct8070D8C0 *temp_a0;
    AAD_8070D8C0 *aaD;

    temp_a0 = func_8070D754();
    aaD = ((AAD_8070D8C0*)temp_a0->unk4->additional_actor_data);
    aaD->unk54 = D_807550CC;
    D_807550CC = 0;
    func_8070D82C(temp_a0, arg1, arg2);
    arg0->object_properties_bitfield |= 0x02000000;
}

typedef struct Struct807550C0 Struct807550C0;

struct Struct807550C0 {
    u16 unk0; // Used
    u8 unk2; // Used
    u8 unk3;
    s32 unk4;
    u8 unk8; // Used
    u8 unk9;
    u8 unkA;
    u8 unkB;
    Struct807550C0 *unkC; // Used
};

extern Struct807550C0 *D_807550C0;

Struct807550C0 *func_8070D928(u16 arg0) {
    Struct807550C0 *var_v1;

    var_v1 = D_807550C0;
    while ((var_v1 != NULL) && (var_v1->unk0 != arg0)) {
        var_v1 = var_v1->unkC;
    }
    return var_v1;
}

void func_8070D970(u16 arg0) {
    Struct807550C0 *temp_v0;

    temp_v0 = func_8070D928(arg0);
    if (temp_v0 != 0) {
        temp_v0->unk2--;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D9AC.s")

/*
void func_8070D9AC(void *arg0) {
    s32 temp_a0;
    s32 temp_s2;
    void *temp_s0;
    void *var_s1;

    var_s1 = arg0->unkC;
    temp_s2 = arg0->unk0 & 2;
    if (var_s1 != NULL) {
        do {
            temp_s0 = var_s1;
            var_s1 = var_s1->unkA0;
            if (temp_s2 != 0) {
                temp_a0 = temp_s0->unk14;
                if (temp_a0 != 0) {
                    func_80715908(temp_a0);
                }
            }
            func_8061134C(temp_s0);
        } while (var_s1 != NULL);
    }
    func_8061134C(arg0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DA28.s")

/*
void func_8070DA28(void *arg0) {
    void *temp_a0;
    void *var_s0;

    var_s0 = arg0->unkC;
    if (var_s0 != NULL) {
        do {
            temp_a0 = var_s0;
            var_s0 = var_s0->unk1C;
            func_8070D9AC(temp_a0);
        } while (var_s0 != NULL);
    }
    arg0->unkC = NULL;
    arg0->unk10 = 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DA74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DB7C.s")

/*
// TODO: Which struct is this?
void func_8070DB7C(void *arg0) {
    func_8061134C(arg0->unk4);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DB9C.s")

typedef struct Struct8070DB9C Struct8070DB9C;

struct Struct8070DB9C {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    Struct8070DB9C *unk8;
};

/*
// TODO: Very close
void func_8070DB9C(Struct8070DB9C *arg0) {
    s32 var_s0;
    void *temp_a1;

    temp_a1 = arg0->unk4;
    if (temp_a1 != NULL) {
        func_8061134C(temp_a1);
    }
    if (arg0->unk0 & 1) {
        for (var_s0 = 0; var_s0 < 1; var_s0++) {
            // TODO: Issue here
            func_8070DB7C(&((u8*)arg0->unk8)[var_s0]);
        }
        func_8061134C(arg0->unk8);
        return;
    }
    if (arg0->unk0 & 2) {
        func_8061134C(arg0->unk8->unk4);
        func_8061134C(arg0->unk8);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DCA4.s")

void func_8070DD18(Struct807550C0 *arg0) {
    func_8070DCA4(arg0->unk4);
    func_8061134C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DD44.s")

/*
// TODO: Close
void func_8070DD44(void) {
    Struct807550C0 **var_s0;
    Struct807550C0 *var_v0;

    var_s0 = &D_807550C0;
    var_v0 = D_807550C0;
    while (var_v0 != NULL) {
        if (var_v0->unk8 == 1) {
            if (var_v0->unk2 != 0) {
                var_v0->unk2--;
                var_v0 = *var_s0;
            }
        }
        if (var_v0->unk2 == 0) {
            *var_s0 = var_v0->unkC;
            func_8070DD18(var_v0);
        } else {
            var_s0 += 3;
        }
        var_v0 = *var_s0;
    }
}
*/

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
} Struct8070DDDC;

s32 func_8070DDDC(u16 arg0, s32 arg1) {
    Struct8070DDDC *phi_v0_2;
    s32 sp20;
    void *temp_a0;
    Struct807550C0 **phi_v1;
    Struct8070DDDC *phi_a0;

    phi_a0 = phi_v0_2 = func_8070D928(arg0);
    if (phi_v0_2 == NULL) {
        // TEXT!!!
        temp_a0 = getPointerTableFile(0xC, arg0, 1, 1);
        phi_v1 = &D_807550C0;
        while (*phi_v1 != NULL) {
            phi_v1 = &(*phi_v1)->unkC;
        }
        sp20 = func_8070D6D8(temp_a0);
        func_8066B434(temp_a0, 0x1F1, 0x50);
        phi_v0_2 = malloc(sizeof(Struct8070DDDC));
        *phi_v1 = phi_v0_2;
        phi_v0_2->unk4 = sp20;
        phi_v0_2->unk0 = arg0;
        phi_v0_2->unk8 = arg1;
        phi_v0_2->unk2 = 0;
        phi_v0_2->unkC = 0;
        phi_a0 = phi_v0_2;
    }
    if (phi_v0_2->unk8 != 0) {
        if (phi_v0_2->unk8 == 1) {
            phi_v0_2->unk2 = 2;
        }
    } else {
        phi_v0_2->unk2++;
    }
    return phi_a0->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DED4.s")

extern u8 D_807550C8;

typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
} Struct8070E2AC_arg1_unk8_unk4;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    Struct8070E2AC_arg1_unk8_unk4 *unk4;
} Struct8070E2AC_arg1_unk8;

typedef struct {
    s32 unk0;
    s32 unk4;
    Struct8070E2AC_arg1_unk8 *unk8;
} Struct8070E2AC_arg1;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Struct8070E2AC_arg2;

void func_8070E2AC(s32 arg0, Struct8070E2AC_arg1 *arg1, Struct8070E2AC_arg2 *arg2) {
    s32 i;
    Struct8070E2AC_arg1_unk8 *temp_s2;
    s32 _arg1;
    s32 _arg2;

    temp_s2 = &arg1->unk8[D_807550C8];
    for (i = 0; i < temp_s2->unk0; i++) {
        _arg1 = temp_s2->unk4[i].unk0 + arg2->unkC;
        _arg2 = temp_s2->unk4[i].unk4;
        func_8070DED4(arg0, _arg1, _arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E808.s")

/*
void func_8070E808(Actor *arg0, Actor *arg1) {
    void *sp24;
    void *sp20;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_2;

    sp24 = arg0->additional_actor_data;
    temp_v0 = func_8070D754(arg1);
    if (temp_v0->unk8 == NULL) {
        arg1->object_properties_bitfield &= 0xFDFFFFFF;
        if (sp24->unk54 & 1) {
            func_8060098C(&D_8061DA84, 0x1E, 0, 0, 0);
        }
        arg0->control_state = 4;
        return;
    }
    temp_v0_2 = temp_v0->unk8;
    sp20 = temp_v0;
    func_8070E548(arg0, temp_v0_2->unk0, temp_v0_2->unk2);
    temp_a0 = temp_v0->unk8;
    temp_v0->unk8 = temp_a0->unk4;
    func_8061134C(temp_a0);
}
*/

extern s32 D_807550C4;
extern u8 D_807550CC;

void func_8070E8C8(void) {
    D_807550C0 = NULL;
    D_807550C4 = 0;
}

void func_8070E8DC(u8 arg0) {
    D_807550CC = arg0;
}
