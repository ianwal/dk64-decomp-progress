#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80747E00;
extern f32 D_80747E04;

extern f64 D_807584F0;
extern f64 D_80758540;
extern f64 D_80758548;
extern f64 D_80758550;

extern u16 D_807F6028;
extern u16 D_807F60A8;

extern u8 D_807F6148;
extern s16 D_807F6140[];
extern s16 D_807F6150[];
extern f32 D_807F6170;
extern f32 D_807F6174;
extern f32 D_807F6178;
extern void* D_807F617C; // Texture
extern f32 D_807F6180;
extern f32 D_807F6184;
extern void* D_807F6188; // Texture
extern void* D_807F618C; // Texture
extern void* D_807F6190; // Texture
extern u8 D_807F6194;
extern f32 D_807F6198;
extern void* D_807F619C; // Texture
extern f32 D_807F61A0;
extern u8 D_807F6938;

void func_80631B80(void) {
    D_807F6148 = 0;
}

void func_80631B8C(s16 arg0) {
    if (D_807F6148 != 4) {
        D_807F6140[D_807F6148] = arg0;
        D_807F6148++;
    }
}

s32 func_80631BCC(s16 arg0) {
    s32 i;

    for (i = 0; i <  D_807F6148; i++) {
        if (arg0 == D_807F6140[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

s16 func_80631C20(u8 arg0) {
    return D_807F6150[arg0];
}

// Doable, little struct definition work needed, couple of loops
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631D8C.s")

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
    u16 unk28; // Used
    u16 unk2A;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
} GlobalASMStruct88;

/*
// TODO: Very close, just stack nonsense
s32 func_80631D8C(u8 arg0) {
    s32 j;
    s32 temp_s2;
    s32 *sp5C;
    s32 sp58;
    s32 i;
    u8 temp_s6;
    u16 phi_s3;
    GlobalASMStruct88 *phi_s0;

    temp_s6 = getLevelIndex(arg0, 1);
    phi_s3 = 0;
    for (i = 0; i < arg0; i++) {
        if (temp_s6 == getLevelIndex(i, 1)) {
            // Load setup for map
            void *temp_v0 = getPointerTableFile(9, i, 1, 1);
            if (temp_v0) {
                func_80631F58(temp_v0, &sp5C, &sp58);
                temp_s2 = *sp5C;
                phi_s0 = sp5C + 1;
                for (j = 0; j < temp_s2; j++) {
                    if (func_80631EB8(phi_s0->unk28) != 0) {
                        phi_s3++;
                    }
                    phi_s0++;
                }
                func_8066B424();
                func_8066B434(temp_v0, 0x13A, 7);
            }
        }
    }
    return phi_s3;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631F58.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631FAC.s")

// Load Model 2 Setup?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632084.s")

// Jumptable, chunk14* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806323C0.s")

s32 func_8063253C(s32 arg0, s32 arg1) {
    return 1;
}

// Doable, object model 2 loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063254C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632E74.s")

// Weird struct in arg1
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806330C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806333F8.s")

// Loop, struct arg1, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80633570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806335B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063367C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063373C.s")

// Loop, struct arg1, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806338B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806338F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063393C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80633A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80633D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80633DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80634768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806348B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80634908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063495C.s")

// Init for Model2Model50_B8
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806349FC.s")

void func_80634E10(Model2Model50_B8*, s16, s16, s16, s16*, s16*, u8);
void func_80634FA0(Model2Model50_B8*, s16, u8, u8*, u8);
void func_80635098(Model2Model50_B8*, s16, s32, s32);
void func_80634F14(s32, s16, u8, u8*, u8);
void func_80634F14(s32, s16, u8, u8*, u8);
void func_80634D64(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, u8 arg6);

void func_80634CC8(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_80634D64(arg0, arg1, arg2, arg3, &arg2, &arg3, 0);
}

void func_80634D14(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 temp2;
    s16 temp;
    func_80634D64(arg0, arg1, temp2, temp, arg2, arg3, 1);
}

void func_80634D64(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, u8 arg6) {
    s32 model2ArrayIndex = func_80659470(arg0);
    Model2Model *model = D_807F6000[model2ArrayIndex].model_pointer;

    switch (D_807F6000[model2ArrayIndex].unk86) {
        case 2:
            func_80634E10(model->unk50, arg1, arg2, arg3, arg4, arg5, arg6);
            break;
        case 1:
            func_80634E10(model->unkB8, arg1, arg2, arg3, arg4, arg5, arg6);
            break;
    }
}

void func_80634E10(Model2Model50_B8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 *arg5, u8 arg6) {
    // TODO: Better match for arg1--, this syntax is weird
    arg1--;
    while (arg0 && arg1) {
        arg1--;
        arg0 = arg0->next;
    }
    if (arg0) {
        if (arg6) {
            *arg4 = arg0->unk38;
            *arg5 = arg0->unk3A;
        } else {
            arg0->unk38 = arg2;
            arg0->unk3A = arg3;
        }
    }
}

void func_80634EA4(s32 arg0, s16 arg1, u8 arg2) {
    func_80634F14(arg0, arg1, arg2, &arg2, 0);
}

void func_80634EDC(s32 arg0, s16 arg1, u8 *arg2) {
    u8 temp;
    func_80634F14(arg0, arg1, temp, arg2, 1);
}

void func_80634F14(s32 arg0, s16 arg1, u8 arg2, u8 *arg3, u8 arg4) {
    s32 model2ArrayIndex = func_80659470(arg0);
    Model2Model *model = D_807F6000[model2ArrayIndex].model_pointer;

    switch (D_807F6000[model2ArrayIndex].unk86) {
        case 2:
            func_80634FA0(model->unk50, arg1, arg2, arg3, arg4);
            break;
        case 1:
            func_80634FA0(model->unkB8, arg1, arg2, arg3, arg4);
            break;
    }
}

void func_80634FA0(Model2Model50_B8 *arg0, s16 arg1, u8 arg2, u8 *arg3, u8 arg4) {
    // TODO: Better match for arg1--, this syntax is weird
    arg1--;
    while (arg0 && arg1) {
        arg1--;
        arg0 = arg0->next;
    }
    if (arg0) {
        if (arg4) {
            *arg3 = arg0->unk48;
        } else {
            arg0->unk48 = arg2;
        }
    }
}

void func_80635018(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 model2ArrayIndex = func_80659470(arg0);
    Model2Model *model = D_807F6000[model2ArrayIndex].model_pointer;

    switch (D_807F6000[model2ArrayIndex].unk86) {
        case 2:
            func_80635098(model->unk50, arg1, arg2, arg3);
            break;
        case 1:
            func_80635098(model->unkB8, arg1, arg2, arg3);
            break;
    }
}

void func_80635098(Model2Model50_B8 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    // TODO: Better match for arg1--, this syntax is weird
    arg1--;
    while (arg0 && arg1) {
        arg1--;
        arg0 = arg0->next;
    }
    if (arg0) {
        if (arg2 != arg0->unk54 || arg3 != arg0->unk50) {
            arg0->unk49 = 1;
        }
        arg0->unk54 = arg2;
        arg0->unk50 = arg3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80635114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80635214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063524C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80635468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80635548.s")

extern s32 D_80747D70;

void func_80635588(void) {
    s32 temp_s1;
    s32 i;

    temp_s1 = D_80747D70;
    for (i = 0; i < temp_s1; i++) {
        func_806355DC(0, 0);
    }
    func_80659350();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806355DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806357F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806358E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80635EF0.s")

void func_80636014(s32 arg0, u8 arg1, u8 arg2) {
    if (arg1 == 1) {
        arg0 = func_80659470(arg0);
    }
    func_8062D094(D_807F6000[arg0].model_pointer, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806362C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636380.s")

/*
// TODO: Which struct is this?
void func_80636380(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1;
    void *phi_s0;
    s32 phi_s1;

    phi_s0 = arg1;
    phi_s1 = 0;
    if (arg1->unk20 > 0) {
        do {
            temp_a0 = phi_s0->unk24;
            if (temp_a0 != 0) {
                func_8066B434(temp_a0, 0xA69, 7);
            }
            temp_a0_2 = phi_s0->unk34;
            if (temp_a0_2 != 0) {
                func_8066B434(temp_a0_2, 0xA6A, 7);
            }
            temp_s1 = phi_s1 + 1;
            phi_s0 += 4;
            phi_s1 = temp_s1;
        } while (temp_s1 < arg1->unk20);
    }
    func_8066B434(arg0, 0xA6E, 7);
    func_8061134C(arg1->unk1C);
    func_8061134C(arg1);
    func_8061134C(arg1->unk14);
    func_8061134C(arg1->unk18);
}
*/

typedef struct struct_807F6160 Struct807F6160;

struct struct_807F6160 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void *unk10; // Pointer to something at least 0x3C big, see func_806364C4
    s32 unk14;
    Struct807F6160 *unk18; // Linked list
};

extern Struct807F6160 *D_807F6160;
extern s32 D_8076A064;

void func_8063643C(void) {
    D_807F6160 = NULL;
}

void func_80636448(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    Struct807F6160 *new;
    Struct807F6160 *old;

    new = malloc(sizeof(Struct807F6160));
    old = D_807F6160;
    D_807F6160 = new;
    new->unk18 = old;
    new->unk0 = arg0;
    new->unk4 = arg1;
    new->unk8 = arg2;
    new->unkC = arg3;
    new->unk14 = D_8076A064 + 2;
    new->unk10 = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806364C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806365D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636784.s")

// Object Model 2 Geometry
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806368F0.s")

f32 func_80636A44(s32 arg0) {
    s32 pad2; // TODO: Why is this needed?
    s32 pad; // TODO: Why is this needed?
    f32 sp1C;
    f32 *model2Geometry;

    // Object Model 2 Geometry
    model2Geometry = getPointerTableFile(4, arg0, 1, 0);
    sp1C = model2Geometry[1];
    func_8066B434(model2Geometry, 0xB87, 7);
    return sp1C;
}

u8 func_80636A8C(s32 arg0) {
    s32 pad; // TODO: Why is this needed?
    s32 pad2; // TODO: Why is this needed?
    s32 phi_v1;
    s32 *model2Geometry;

    // Object Model 2 Geometry
    model2Geometry = getPointerTableFile(4, arg0, 1, 0);
    if (*model2Geometry & 8) {
        phi_v1 = TRUE;
    } else {
        phi_v1 = FALSE;
    }
    func_8066B434(model2Geometry, 0xBA3, 7);
    return phi_v1;
}

// Annoying struct stuff, doable otherwise, maybe object model 2?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636B50.s")

// object model 2, model pointer, behaviour_pointer
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636EFC.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636FFC.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80637B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806392BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806398E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80639968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80639C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80639CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80639F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80639FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063A38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063A848.s")

// object model 2 -> model_pointer -> 0x54, 0xBC -> unk4
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063A8C4.s")

/*
void func_8063A8C4(s16 arg0, u8 arg1, f32 arg2) {
    ObjectModel2 *temp_v0;
    s16 temp_a1;
    Model2Model *temp_v1;
    s16 phi_a0;
    void *phi_v0;

    phi_a0 = arg0;
    if (arg1 == 1) {
        phi_a0 = func_80659470(arg0);
    }
    temp_v0 = &D_807F6000[phi_a0];
    temp_a1 = temp_v0->unk86;
    temp_v1 = temp_v0->model_pointer;
    if (temp_a1 != 1) {
        if (temp_a1 != 2) {
            phi_v0 = sp18;
        } else {
            phi_v0 = temp_v1->unk54;
        }
    } else {
        phi_v0 = temp_v1->unkBC;
    }
    if (phi_v0 != 0) {
        phi_v0->unk4 = arg2;
    }
}
*/

// display list something
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063A968.s")

void func_8063B4A4(void) {
    D_807F6028 = 0;
    D_807F60A8 = 0;
    D_807F6938 = 0;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063B4C0.s")

// big, object model 2
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063B758.s")

// big, object model 2
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063B8D8.s")

// big, object model 2
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063BBB0.s")

// big
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063BEC0.s")

// object model 2 -> 0x48, 0x49, 0x4E, 0x7C -> 0x10, 0x12, 0x38, 0x94, 0x9A
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063BF34.s")

void func_8063C1EC(s32 arg0, u8 arg1) {
    D_807F6000[func_80659470(D_807F6240[arg0])].model_pointer->unk4E |= arg1;
}

void func_8063C248(s32 arg0, u8 arg1) {
    D_807F6000[func_80659470(D_807F6240[arg0])].model_pointer->unk4E &= ~arg1;
}

// object model 2 -> unk7C -> 0x60, 0x64
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063C2A8.s")

s16 func_8063C328(s16 arg0) {
    s16 model2ArrayIndex = func_80659470(arg0);
    if (model2ArrayIndex == -1) {
        return -1;
    }
    return D_807F6000[model2ArrayIndex].object_type;
}

typedef struct {
    void (*unk0)(void); // Function pointer, used
    void (*unk4)(s32); // Function pointer, used
    void (*unk8)(void); // Function pointer, used
    u8 unkC; // Used
    s8 unkD;
    s8 unkE;
    s8 unkF;
} Struct80747D80;

extern Struct80747D80 D_80747D80[];

void func_8063C390(void) {
    s32 i = 0;

    for (i = 0; i < 8; i++) {
        D_80747D80[i].unkC = FALSE;
    }
}

void func_8063C3C0(s16 arg0) {
    if (!D_80747D80[arg0].unkC) {
        D_80747D80[arg0].unk0();
        D_80747D80[arg0].unkC = TRUE;
    }
}

void func_8063C418(s32 arg0, s16 arg1) {
    D_80747D80[arg1].unk4(arg0);
}

void func_8063C450(void) {
    s32 i = 0;

    for (i = 0; i < 8; i++) {
        if (D_80747D80[i].unkC) {
            D_80747D80[i].unk8();
        }
    }
}

void func_8063C4A8(void) {
    D_807F6170 = 255.0f;
    D_807F6174 = 255.0f;
}

// display list stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063C4C4.s")

void func_8063C6D8(void) {
    D_807F6170 -= 1.0;
    if (D_807F6170 < 0.0) {
        D_807F6170 = 255.0f;
    }
    D_807F6174 -= D_807584F0;
    if (D_807F6174 < 0.0) {
        D_807F6174 = 255.0f;
    }
}

void func_8063C784(void) {
    D_807F6178 = 255.0f;
    D_807F617C = getPointerTableFile(0x19, 0x565, 1, 0); // Texture
}

// display list stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063C7C4.s")

void func_8063CA7C(void) {
    D_807F6178 -= 1.0;
    if (D_807F6178 < 0.0) {
        D_807F6178 = 255.0f;
    }
}

void func_8063CADC(void) {
    D_807F6180 = 255.0f;
    D_807F6184 = 255.0f;
    D_807F6188 = getPointerTableFile(7, 0x3B7, 0, 0); // Texture
    D_807F618C = getPointerTableFile(7, 0x3B8, 0, 0); // Texture
}

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063CB40.s")

void func_8063CE64(void) {
    D_807F6180 -= D_80758540;
    if (D_807F6180 < 0.0) {
        D_807F6180 = 255.0f;
    }
    D_807F6184 -= D_80758548;
    if (D_807F6184 < 0.0) {
        D_807F6184 = 255.0f;
    }
}

void func_8063CF0C(void) {
    D_807F6190 = getPointerTableFile(7, 0x3E0, 1, 0); // Texture
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063CF3C.s")

void func_8063D1D8(void) {
    D_80747E00 -= 5.0;
    if (D_80747E00 < 0.0) {
        D_80747E00 = 255.0f;
    }
    D_80747E04 -= 2.0;
    if (D_80747E04 < 0.0) {
        D_80747E04 = 255.0f;
    }
}

typedef struct {
    s16 unk0; // Texture index
    s16 unk2;
    void *unk4; // Pointer to an uncompressed texture
} GlobalASMStruct77;

extern GlobalASMStruct77 D_80747E0C[];

void func_8063D288(void) {
    s32 i;

    D_807F6194 = 0;
    for (i = 0; i < 11; i++) {
        // Texture (Uncompressed)
        D_80747E0C[i].unk4 = getPointerTableFile(7, D_80747E0C[i].unk0, 1, 0);
    }
}

// display list stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063D2E4.s")

void func_8063D468(void) {
    D_807F6194++;
    if (D_807F6194 == 11) {
        D_807F6194 = 0;
    }
}

void func_8063D494(void) {
    D_807F6198 = 0.0f;
}

// display list stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063D4A4.s")

void func_8063D5AC(void) {
    D_807F6198 -= D_80758550;
    if (D_807F6198 < 0.0) {
        D_807F6198 = 255.0f;
    }
}

void func_8063D608(void) {
    D_807F619C = getPointerTableFile(0x19, 0x1765, 1, 0); // Texture
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_8063D638.s")

void func_8063D854(void) {
    switch (current_map) {
        case MAP_CASTLE_BARREL_BLAST:
            D_807F61A0 -= 2.0;
            break;
        case MAP_FUNGI_BARREL_BLAST:
            D_807F61A0 -= 1.0;
            break;
        default:
            D_807F61A0 -= 1.0;
            break;
    }
    if (D_807F61A0 < 0.0) {
        D_807F61A0 = 255.0f;
    }
}
