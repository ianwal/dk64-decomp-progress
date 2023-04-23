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
        func_80677FA8(0x12B, 0, arg0);
        D_807FBB44->control_state = 0;
        (*var_s0)->unk4 = D_807FBB44;
        D_807FBB44->additional_actor_data->unk4 = arg0;
    }
    return *var_s0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D8C0.s")

extern u8 D_807550CC;

/*
// TODO: What type does func_8070D754 return?
void func_8070D8C0(Actor *arg0, u16 arg1, u8 arg2) {
    void *temp_a0;
    void *temp_v0;

    temp_v0 = func_8070D754();
    temp_a0 = temp_v0;
    temp_v0->unk4->unk174->unk54 = D_807550CC;
    D_807550CC = 0;
    func_8070D82C(temp_a0, arg1, arg2, &D_807550CC);
    arg0->object_properties_bitfield |= 0x02000000;
}
*/

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DDDC.s")

/*
s32 func_8070D6D8(void *);

// TODO: Nice little puzzle to solve...
s32 func_8070DDDC(u16 arg0, s32 arg1) {
    s32 sp20;
    u8 temp_v1_2;
    void **temp_v1;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *phi_v0;
    void **phi_v1;
    void *phi_v0_2;
    void *phi_a0;

    temp_v0 = func_8070D928(arg0);
    phi_v0_2 = temp_v0;
    phi_a0 = temp_v0;
    if (temp_v0 == NULL) {
        // TEXT!!!
        temp_a0 = getPointerTableFile(0xC, arg0, 1, 1);
        phi_v1 = &D_807550C0;
        if (D_807550C0 != 0) {
            phi_v0 = D_807550C0;
            do {
                temp_v1 = phi_v0 + 0xC;
                temp_v0_2 = *temp_v1;
                phi_v0 = temp_v0_2;
                phi_v1 = temp_v1;
            } while (temp_v0_2 != 0);
        }
        sp20 = func_8070D6D8(temp_a0);
        func_8066B434(temp_a0, 0x1F1, 0x50);
        temp_v0_3 = malloc(0x10);
        *phi_v1 = temp_v0_3;
        temp_v0_3->unk4 = sp20;
        temp_v0_3->unk0 = arg0;
        temp_v0_3->unk2 = 0;
        temp_v0_3->unkC = 0;
        temp_v0_3->unk8 = arg1;
        phi_v0_2 = temp_v0_3;
        phi_a0 = temp_v0_3;
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
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E2AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070E808.s")

extern s32 D_807550C4;
extern u8 D_807550CC;

void func_8070E8C8(void) {
    D_807550C0 = NULL;
    D_807550C4 = 0;
}

void func_8070E8DC(u8 arg0) {
    D_807550CC = arg0;
}
