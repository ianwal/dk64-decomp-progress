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
void func_8070D380(u32 arg0, Temp8070D6D8 *arg1, u8 **arg2) {
    memcpy(arg1, *arg2, arg0);
    *arg2 += arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D654.s")

Temp8070D6D8 *func_8070D6D8(void *arg0) {
    Temp8070D6D8 *temp_s0;
    s32 size;

    temp_s0 = malloc(0x10);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D928.s")

/*
extern u16 *D_807550C0;

u16 *func_8070D928(s32 arg0) {
    s32 temp_t6;
    u16 *var_v1;

    var_v1 = D_807550C0;
    temp_t6 = arg0 & 0xFFFF;
    if ((var_v1 != NULL) && (temp_t6 != *var_v1)) {
loop_2:
        var_v1 = var_v1->unkC;
        if (var_v1 != NULL) {
            if (temp_t6 != *var_v1) {
                goto loop_2;
            }
        }
    }
    return var_v1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070D970.s")

/*
// TODO: Which struct is this?
void func_8070D970(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_8070D928(arg0 & 0xFFFF);
    if (temp_v0 != 0) {
        temp_v0->unk2--;
    }
}
*/

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DCA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DD18.s")

/*
// TODO: Which struct is this?
void func_8070DD18(void *arg0) {
    func_8070DCA4(arg0->unk4);
    func_8061134C(arg0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DD44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_8070DDDC.s")

/*
s32 func_8070D6D8(void *);
void *func_8070D928(u16);
extern void *D_807550C0;

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
    if (temp_v0 == 0) {
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
    temp_v1_2 = phi_v0_2->unk8;
    if (temp_v1_2 != 0) {
        if (temp_v1_2 == 1) {
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

extern s32 D_807550C0; // TODO: Some kind of struct pointer, possibly Temp8070D6D8
extern s32 D_807550C4;
extern u8 D_807550CC;

void func_8070E8C8(void) {
    D_807550C0 = 0;
    D_807550C4 = 0;
}

void func_8070E8DC(u8 arg0) {
    D_807550CC = arg0;
}
