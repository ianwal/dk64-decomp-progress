#include <ultra64.h>
#include "functions.h"

/*
// .rodata
const char D_global_asm_8075E490[] = "%s";
const char D_global_asm_8075E494[] = "%d";
const char D_global_asm_8075E498[] = "%c";
const f64 D_global_asm_8075E4A0 = 124.800003051757812;
const f64 D_global_asm_8075E4A8 = 124.800003051757812;
*/

typedef struct {
    u8 unk0; // Used
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Struct8070D568;

typedef struct {
    u8 unk0; // Used
    u8 unk1;
    u8 unk2;
    u8 unk3;
    Struct8070D568 *unk4;
} Struct8070D654;

typedef struct Temp8070D6D8 {
    u8 unk0; // Used
    u8 unk1;
    u8 unk2;
    u8 unk3;
    Struct8070D654 *unk4;
    u16 unk8; // Size
    u16 unkA;
    void *unkC; // Next?
} Temp8070D6D8;

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

// TODO: What the
void func_global_asm_8070D380(u32 size, Temp8070D6D8 *arg1, u8 **arg2) {
    memcpy(arg1, *arg2, size);
    *arg2 += size;
}

void func_global_asm_8070D3CC(Struct8070D3CC_arg0 *arg0, Struct8070D3CC_arg1 *arg1) {
    s32 i;
    Struct8070D3CC_arg0 *var_s0;

    func_global_asm_8070D380(1, arg0, arg1);
    arg0->unk4 = malloc(arg0->unk0 * sizeof(Struct8070D3CC_arg0));
    var_s0 = arg0->unk4;
    for (i = 0; i < arg0->unk0; i++) {
        func_global_asm_8070D380(sizeof(Struct8070D3CC_arg0), var_s0, arg1);
        var_s0++;
    }
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070D464.s")

void func_global_asm_8070D568(Struct8070D654 *arg0, void *arg1) {
    s32 i;
    Struct8070D568 *temp_v0;
    void *temp_v0_2;
    Struct8070D568 *var_s0;

    func_global_asm_8070D380(1, arg0, arg1);
    temp_v0 = malloc(arg0->unk0 * sizeof(Struct8070D568));
    arg0->unk4 = temp_v0;
    var_s0 = temp_v0;
    for (i = 0; i < arg0->unk0; i++) {
        func_global_asm_8070D380(1, var_s0, arg1);
        if (var_s0->unk0 & 4) {
            temp_v0_2 = malloc(4);
            var_s0->unk4 = temp_v0_2;
            func_global_asm_8070D380(4, temp_v0_2, arg1);
        } else {
            var_s0->unk4 = NULL;
        }
        func_global_asm_8070D464(var_s0, arg1);
        func_global_asm_8070D380(4, &var_s0->unkC, arg1);
        var_s0++;
    }
}

void func_global_asm_8070D654(Temp8070D6D8 *arg0, void *arg1) {
    s32 i;
    Struct8070D654 *var_s0;

    arg0->unk4 = malloc(arg0->unk0 * sizeof(Struct8070D654));
    var_s0 = arg0->unk4;
    for (i = 0; i < arg0->unk0; i++) {
        func_global_asm_8070D568(var_s0, arg1);
        var_s0++;
    }
}

Temp8070D6D8 *func_global_asm_8070D6D8(void *arg0) {
    Temp8070D6D8 *temp_s0;
    s32 size;

    temp_s0 = malloc(sizeof(Temp8070D6D8));
    func_global_asm_8070D380(1, temp_s0, &arg0);
    func_global_asm_8070D654(temp_s0, &arg0);
    func_global_asm_8070D380(2, &temp_s0->unk8, &arg0);
    size = temp_s0->unk8;
    temp_s0->unkC = malloc(size);
    memcpy(temp_s0->unkC, arg0, size);
    return temp_s0;
}

typedef struct Struct8070D754_temp_v0 Struct8070D754_temp_v0;

struct Struct8070D754_temp_v0 {
    Actor *unk0; // Wrinkly
    Actor *unk4; // Textbox
    s32 unk8;
    Struct8070D754_temp_v0 *next;
};

extern Struct8070D754_temp_v0 *D_global_asm_807550C4;

typedef struct {
    s32 unk0;
    Struct8070D754_temp_v0 *unk4;
} TextBubbleAAD;

// TODO: Any cleanup possible?
Struct8070D754_temp_v0 *func_global_asm_8070D754(Actor *arg0) {
    Struct8070D754_temp_v0 **nextPointer;

    nextPointer = &D_global_asm_807550C4;
    while ((*nextPointer != NULL) && (arg0 != (*nextPointer)->unk0)) {
        nextPointer = &(*nextPointer)->next;
    }

    if (*nextPointer == NULL) {
        TextBubbleAAD *textAAD;
        *nextPointer = malloc(sizeof(Struct8070D754_temp_v0));
        func_global_asm_80611690(*nextPointer);
        (*nextPointer)->unk0 = arg0;
        spawnActor(ACTOR_TEXT_BUBBLE, 0);
        last_spawned_actor->control_state = 0;
        (*nextPointer)->unk4 = last_spawned_actor;
        textAAD = last_spawned_actor->additional_actor_data;
        textAAD->unk4 = arg0;
    }
    return *nextPointer;
}

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s32 unk4;
} Struct8070D82C_malloc;

typedef struct {
    Struct8070D82C_malloc *unk0;
} Struct8070D82C_v1;

typedef struct Struct8070D82C_v0 Struct8070D82C_v0;

struct Struct8070D82C_v0 {
    Struct8070D82C_v0 *next;
    Struct8070D82C_v1 *unk4;
};

typedef struct {
    s32 unk0;
    Actor* unk4;
    Struct8070D82C_v0 *unk8;
} Struct8070D8C0;

void func_global_asm_8070D82C(Struct8070D8C0*, u16, u8);

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070D82C.s")

/*
void func_global_asm_8070D82C(Struct8070D8C0 *arg0, u16 arg1, u8 arg2) {
    Struct8070D82C_v1 *var_v1;
    Struct8070D82C_v0 *var_v0;

    var_v1 = &arg0->unk8;
    if (arg0->unk8) {
        var_v0 = var_v0->next;
        do {
            var_v1 = &var_v0->unk4;
            var_v0 = var_v0->next;
        } while (var_v0);
    }
    var_v1->unk0 = malloc(8);
    var_v1->unk0->unk0 = arg1;
    var_v1->unk0->unk2 = arg2;
    var_v1->unk0->unk4 = 0;
    if (arg0->unk4->control_state == 4) {
        arg0->unk4->control_state = 0;
    }
}
*/

typedef struct {
    u8 unk0[0x54 - 0x0];
    u8 unk54;
} AAD_global_asm_8070D8C0;

extern u8 D_global_asm_807550CC;

void loadText(Actor *arg0, u16 fileIndex, u8 textIndex) {
    Struct8070D8C0 *temp_a0;
    AAD_global_asm_8070D8C0 *aaD;

    temp_a0 = func_global_asm_8070D754(arg0);
    aaD = ((AAD_global_asm_8070D8C0*)temp_a0->unk4->additional_actor_data);
    aaD->unk54 = D_global_asm_807550CC;
    D_global_asm_807550CC = 0;
    func_global_asm_8070D82C(temp_a0, fileIndex, textIndex);
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

extern Struct807550C0 *D_global_asm_807550C0;

Struct807550C0 *func_global_asm_8070D928(u16 arg0) {
    Struct807550C0 *var_v1;

    var_v1 = D_global_asm_807550C0;
    while ((var_v1 != NULL) && (var_v1->unk0 != arg0)) {
        var_v1 = var_v1->unkC;
    }
    return var_v1;
}

void func_global_asm_8070D970(u16 arg0) {
    Struct807550C0 *temp_v0;

    temp_v0 = func_global_asm_8070D928(arg0);
    if (temp_v0 != 0) {
        temp_v0->unk2--;
    }
}

void func_global_asm_8070D9AC(Struct806A57C0_2 *arg0) {
    void *temp_a0;
    s32 temp_s2;
    Struct806A57C0_3 *temp_s0;
    Struct806A57C0_3 *var_s1;

    var_s1 = arg0->unkC;
    temp_s2 = arg0->unk0 & 2;
    while (var_s1 != NULL) {
        temp_s0 = var_s1;
        var_s1 = var_s1->unkA0;
        if (temp_s2 != 0) {
            temp_a0 = temp_s0->unk14;
            if (temp_a0 != 0) {
                func_global_asm_80715908(temp_a0);
            }
        }
        func_global_asm_8061134C(temp_s0);
    }
    func_global_asm_8061134C(arg0);
}

void func_global_asm_8070DA28(AAD_global_asm_806A4DDC *arg0) {
    Struct806A57C0_2 *temp_a0;
    Struct806A57C0_2 *var_s0;

    var_s0 = arg0->unkC;
    while (var_s0 != NULL) {
        temp_a0 = var_s0;
        var_s0 = var_s0->next;
        func_global_asm_8070D9AC(temp_a0);
    }
    arg0->unkC = NULL;
    arg0->unk10 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070DA74.s")

typedef struct Struct8070DB9C Struct8070DB9C;

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct8070DB9C_unk4;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Struct8070DB9C_unk4_10;

struct Struct8070DB9C {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    union {
        Struct8070DB9C_unk4 *unk4;
        Struct8070DB9C_unk4_10 *unk4_10;
    };
    Struct8070DB9C *unk8;
    s32 unkC;
};

void func_global_asm_8070DB7C(Struct8070DB9C *arg0) {
    func_global_asm_8061134C(arg0->unk4);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070DB9C.s")

/*
void func_global_asm_8070DB9C(Struct8070DB9C *arg0) {
    s32 var_s0;
    void *temp_a1;

    temp_a1 = arg0->unk4;
    if (temp_a1 != NULL) {
        func_global_asm_8061134C(temp_a1);
    }
    if (arg0->unk0 & 1) {
        for (var_s0 = 0; var_s0 < 1; var_s0++) {
            // TODO: Issue here
            func_global_asm_8070DB7C(&((u8*)arg0->unk8)[var_s0]);
        }
        func_global_asm_8061134C(arg0->unk8);
        return;
    }
    if (arg0->unk0 & 2) {
        func_global_asm_8061134C(arg0->unk8->unk4);
        func_global_asm_8061134C(arg0->unk8);
    }
}
*/

void func_global_asm_8070DC40(Struct8070DB9C *arg0) {
    s32 i;

    for (i = 0; i < arg0->unk0; i++) {
        func_global_asm_8070DB9C(&arg0->unk4_10[i]);
    }
    func_global_asm_8061134C(arg0->unk4);
}

void func_global_asm_8070DCA4(Struct8070DB9C *arg0) {
    s32 i;

    for (i = 0; i < arg0->unk0; i++) {
        func_global_asm_8070DC40(&arg0->unk4[i]);
    }
    func_global_asm_8061134C(arg0->unk4);
    func_global_asm_8061134C(arg0->unkC);
    func_global_asm_8061134C(arg0);
}

void func_global_asm_8070DD18(Struct807550C0 *arg0) {
    func_global_asm_8070DCA4(arg0->unk4);
    func_global_asm_8061134C(arg0);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070DD44.s")

/*
void func_global_asm_8070DD44(void) {
    Struct807550C0 **var_s0;
    Struct807550C0 *var_v0;

    var_s0 = &D_global_asm_807550C0;
    var_v0 = D_global_asm_807550C0;
    while (var_v0 != NULL) {
        if (var_v0->unk8 == 1) {
            if (var_v0->unk2 != 0) {
                var_v0->unk2--;
                var_v0 = *var_s0;
            }
        }
        if (var_v0->unk2 == 0) {
            *var_s0 = var_v0->unkC;
            func_global_asm_8070DD18(var_v0);
        } else {
            var_s0 += 3;
        }
        var_v0 = *var_s0;
    }
}
*/

typedef struct Struct8070E548 Struct8070E548;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    f32 unkC; // f32?
} Struct8070E548_unk4;

struct Struct8070E548 {
    s32 unk0;
    Struct8070E548_unk4 *unk4;
    s32 unk8;
    s32 unkC;
    u16 unk10; // f32?
    s16 unk12;
    s32 unk14;
    s32 unk18;
    Struct8070E548 *unk1C; // Next
};

typedef struct {
    u8 unk0;
    s32 unk4;
    u16 unk8;
    Struct8070E548 *unkC;
} AAD_global_asm_8070E548;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    Struct8070E548_unk4 *unk4;
} Struct8070DDDC_unk4;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    Struct8070DDDC_unk4 *unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
} Struct8070DDDC;

s32 func_global_asm_8070DDDC(u16 arg0, s32 arg1) {
    Struct8070DDDC *phi_v0_2;
    s32 sp20;
    void *temp_a0;
    Struct807550C0 **phi_v1;
    Struct8070DDDC *phi_a0;

    phi_a0 = phi_v0_2 = func_global_asm_8070D928(arg0);
    if (phi_v0_2 == NULL) {
        // TEXT!!!
        temp_a0 = getPointerTableFile(0xC, arg0, 1, 1);
        phi_v1 = &D_global_asm_807550C0;
        while (*phi_v1 != NULL) {
            phi_v1 = &(*phi_v1)->unkC;
        }
        sp20 = func_global_asm_8070D6D8(temp_a0);
        func_global_asm_8066B434(temp_a0, 0x1F1, 0x50);
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070DED4.s")

extern u8 D_global_asm_807550C8;

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

void func_global_asm_8070E2AC(s32 arg0, Struct8070E2AC_arg1 *arg1, Struct8070E2AC_arg2 *arg2) {
    s32 i;
    Struct8070E2AC_arg1_unk8 *temp_s2;
    s32 _arg1;
    s32 _arg2;

    temp_s2 = &arg1->unk8[D_global_asm_807550C8];
    for (i = 0; i < temp_s2->unk0; i++) {
        _arg1 = temp_s2->unk4[i].unk0 + arg2->unkC;
        _arg2 = temp_s2->unk4[i].unk4;
        func_global_asm_8070DED4(arg0, _arg1, _arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070E34C.s")

// very close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/func_global_asm_8070E548.s")

void func_global_asm_8070E34C(void *arg0, void *arg1, s32 arg2);

/*
void func_global_asm_8070E548(Actor *arg0, u16 arg1, u8 arg2) {
    Struct8070DDDC *temp_s2;
    s32 i;
    Struct8070E548 **nextPtr;
    AAD_global_asm_8070E548 *aaD;
    Struct8070E548_unk4 *var_s1;
    Struct8070E548 *current;

    aaD = arg0->additional_actor_data;
    if (arg0->object_properties_bitfield & 0x10) {
        func_global_asm_8070D970(aaD->unk8);
    }
    temp_s2 = func_global_asm_8070DDDC(arg1, 0);
    aaD->unk8 = arg1;
    var_s1 = temp_s2->unk4[arg2].unk4;
    nextPtr = &aaD->unkC;
    for (i = 0; i < temp_s2->unk4[arg2].unk0; i++) {
        current = *nextPtr;
        while (current != NULL) {
            nextPtr = &current->unk1C;
            current = *nextPtr;
        }
        if (var_s1->unk0 & 1) {
            func_global_asm_8070E2AC(aaD, var_s1, temp_s2);
            current = *nextPtr;
        } else if (var_s1->unk0 & 2) {
            func_global_asm_8070E34C(aaD, var_s1, temp_s2);
            current = *nextPtr;
        }
        if (current != NULL) {
            current->unk8 = var_s1->unk4;
            current = *nextPtr;
        }
        while (current != NULL && *nextPtr != NULL) {
            nextPtr = &current->unk1C;
            current = *nextPtr;
        }
        current->unk10 = var_s1->unkC * 30.0f;
        var_s1++;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_112080/getTextString.s")

typedef struct {
    u8 unk0[0x54 - 0x0];
    u8 unk54;
} AAD_global_asm_8070E808;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    s32 unk4;
} Struct8070D754_unk8;

typedef struct {
    s32 unk0;
    s32 unk4;
    Struct8070D754_unk8 *unk8;
} Struct8070D754;

extern s32 D_global_asm_8061DA84; // TODO: Datatype

void func_global_asm_8070E808(Actor *arg0, Actor *arg1) {
    AAD_global_asm_8070E808 *sp24;
    Struct8070D754 *temp_v0;
    Struct8070D754_unk8 *temp_a0;

    sp24 = arg0->additional_actor_data;
    temp_v0 = func_global_asm_8070D754(arg1);
    if (temp_v0->unk8 == NULL) {
        arg1->object_properties_bitfield &= 0xFDFFFFFF;
        if (sp24->unk54 & 1) {
            func_global_asm_8060098C(&D_global_asm_8061DA84, 0x1E, 0, 0, 0);
        }
        arg0->control_state = 4;
        return;
    }
    func_global_asm_8070E548(arg0, temp_v0->unk8->unk0, temp_v0->unk8->unk2);
    temp_a0 = temp_v0->unk8;
    temp_v0->unk8 = temp_a0->unk4;
    func_global_asm_8061134C(temp_a0);
}

extern u8 D_global_asm_807550CC;

void func_global_asm_8070E8C8(void) {
    D_global_asm_807550C0 = NULL;
    D_global_asm_807550C4 = NULL;
}

void func_global_asm_8070E8DC(u8 arg0) {
    D_global_asm_807550CC = arg0;
}
