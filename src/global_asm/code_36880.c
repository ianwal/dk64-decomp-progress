#include <ultra64.h>
#include "functions.h"


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
} GlobalASMStruct88;

s32 func_80631EB8(u16);
extern u8 D_80747D78;

void func_80631F58(s32 *arg0, s32 **arg1, void **arg2);

void func_80631C3C(void) {
    void *temp_v0;
    GlobalASMStruct88 *var_s0;
    s32 temp_s2;
    s32 *sp58;
    s32 sp54;
    s32 i;
    u8 temp_s3;
    s32 var_s1;

    if (D_80747D78 == 0) {
        D_80747D78 = 1;
        for (i = 0; i < 8; i++) {
            D_807F6150[i] = 0;
        }
        for (i = 0; i < 0xDD; i++) {
            temp_v0 = getPointerTableFile(9, i, 1, 1);
            if (temp_v0 != NULL) {
                temp_s3 = getLevelIndex(i, 1);
                func_80631F58(temp_v0, &sp58, &sp54);
                temp_s2 = *sp58;
                var_s0 = sp58 + 1;
                for (var_s1 = 0; var_s1 < temp_s2; var_s1++) {
                    if (func_80631EB8(var_s0->unk28) != 0) {
                        D_807F6150[temp_s3]++;
                    }
                    var_s0++;
                }
                func_8066B424();
                func_8066B434(temp_v0, 0x10C, 7);
            }
        }
    }
}

s32 func_80631D8C(u8 arg0) {
    s32 temp;
    s32 j;
    s32 temp_s2;
    s32 i;
    s32 *sp5C;
    s32 sp58;
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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631F58.s")

/*
// TODO: Regalloc
void func_80631F58(s32 *arg0, s32 **arg1, void **arg2) {
    s32 count;
    if (arg0 == NULL) {
        *arg1 = NULL;
        *arg2 = NULL;
        return;
    }
    *arg1 = arg0;
    count = arg0[0];
    arg0 += count * 0xC;
    arg0 += 1;
    count = arg0[0];
    arg0 += count * 0x9;
    arg0 += 1;
    *arg2 = arg0;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80631FAC.s")

// Load Model 2 Setup?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632084.s")

// Jumptable, chunk14* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806323C0.s")

s32 func_8063253C(s32 arg0, s32 arg1) {
    return 1;
}

extern s32 D_80747D70;

s32 func_8063254C(s32 arg0, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s16 *arg5, s16 *arg6) {
    s32 found;
    s32 i;
    found = FALSE;
    i = *arg1;

    while (!found && i < D_80747D70) {
        if (arg0 == D_807F6000[i].object_type) {
            found = TRUE;
            *arg5 = D_807F6000[i].unk88;
            *arg6 = D_807F6000[i].unk8A;
            *arg2 = D_807F6000[i].x_position;
            *arg3 = D_807F6000[i].y_position;
            *arg4 = D_807F6000[i].z_position;
        }
        i++;
    }
    *arg1 = i;
    return found;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632860.s")

typedef struct {
    u16 unk0; // Map
    u16 unk2;
} Struct80747D50;

extern Struct80747D50 D_80747D50[];

void func_80632E10(s16 arg0, u8 *arg1) {
    s32 i = 0;
    s32 max = 8;
    s32 map;
    Struct80747D50 *temp;

    map = current_map;temp = D_80747D50; // Unreal...

    while (i < max) {
        if (temp->unk0 == map && temp->unk2 == arg0) {
            *arg1 |= 1;
            return;
        } else {
            i++;
            temp++;
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632E74.s")

typedef struct {
    u16 unk0; // Map
    u16 unk2;
    u16 unk4;
} Struct80747D30;

extern Struct80747D30 D_80747D30[];

typedef struct {
    u8 unk0[0x1E - 0x0];
    s16 unk1E;
} Struct80632F20;

void func_80632F20(s32 arg0, Struct80632F20 *arg1) {
    s32 i;
    s32 max;
    s32 map;
    Struct80747D30 *var_a3;

    max = 5;
    i = 0;map = current_map;var_a3 = &D_80747D30; // Cringe...

    while (i < max) {
        if (map == var_a3->unk0 && arg0 == var_a3->unk2) {
            arg1->unk1E = var_a3->unk4;
            return;
        } else {
            i++;
            var_a3++;
        }
    }
}

u8 func_80632F74(f32 arg0, f32 arg1, f32 arg2) {
    f32 sp1C;

    sp1C = arg1 + 10.0f;
    if (func_80667110(arg0, arg2, &sp1C) != 0) {
        return func_80667174();
    }
    return 0xF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80632FCC.s")

/*
// TODO: Regalloc
void func_80632FCC(s16 arg0, u8 arg1) {
    s32 pad[5];
    Model2Model54_BC *var_a0_2;
    s32 pad2;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg1 == 1) {
        arg0 = func_80659470(arg0);
    }
    sp28 = D_807F6000[arg0].y_position + 20.0f;
    if (func_80667110(D_807F6000[arg0].x_position, D_807F6000[arg0].z_position, &sp28) != 0) {
        func_80666AC4(&sp26, &sp24);
        switch (D_807F6000[arg0].unk24->unk1C) {
            case 1:
                var_a0_2 = D_807F6000[arg0].model_pointer->unkBC;
                break;
            case 2:
                var_a0_2 = D_807F6000[arg0].model_pointer->unk54;
                break;
        }
        if (var_a0_2 != NULL) {
            var_a0_2->unk20 = sp26;
            var_a0_2->unk22 = sp24;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806330C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_806333F8.s")

// Loop, struct arg1, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80633570.s")

void func_806335B0(s32 arg0, u8 arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    s32 var_v0;
    OM2_unk74 *var_v1;

    if (arg1 == 1) {
        arg0 = func_80659470(arg0);
    }
    var_v1 = D_807F6000[arg0].unk74;
    var_v0 = arg2 - 1;
    while (var_v1 != 0 && var_v0 != 0) {
        var_v1 = var_v1->next;
        var_v0 -= 1;
    }
    if (var_v1 != 0) {
        *arg3 = var_v1->unk0;
        *arg4 = var_v1->unk4;
        *arg5 = var_v1->unk8;
    } else {
        *arg5 = 0.0f;
        *arg4 = 0.0f;
        *arg3 = 0.0f;
    }
}

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

void func_806362C4(s32 arg0, u8 arg1) {
    Model2Model54_BC *temp_a3;
    Model2Model54_BC **sp18;
    ObjectModel2 *temp_v0;
    s16 temp_v1;

    if (arg1 == 1) {
        arg0 = func_80659470(arg0);
    }
    temp_v0 = &D_807F6000[arg0];
    switch (temp_v0->unk86) {
        case 2:
            sp18 = &temp_v0->model_pointer->unk54;
            break;
        case 1:
            sp18 = &temp_v0->model_pointer->unkBC;
            break;
    }
    if (sp18 != NULL) {
        temp_a3 = *sp18;
        if (temp_a3 != NULL) {
            func_8066B434(temp_a3->unk0, 0xA56, 7);
            func_8061130C(temp_a3);
            *sp18 = NULL;
        }
    }
}

// TODO: Any overlap with documented structs?
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
    s16 unk22;
    void *unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    void *unk34;
} Struct80636380;

void func_80636380(s32 arg0, Struct80636380 *arg1) {
    Struct80636380 *phi_s0;
    s32 i;

    phi_s0 = arg1;
    i = 0;
    while (i < arg1->unk20) {
        if (phi_s0->unk24 != 0) {
            func_8066B434(phi_s0->unk24, 0xA69, 7);
        }
        if (phi_s0->unk34 != 0) {
            func_8066B434(phi_s0->unk34, 0xA6A, 7);
        }
        // TODO: Not good at all.
        // I think arg1 is an array of pointers
        ((s32)phi_s0) += 4;
        i++;
    }
    func_8066B434(arg0, 0xA6E, 7);
    func_8061134C(arg1->unk1C);
    func_8061134C(arg1);
    func_8061134C(arg1->unk14);
    func_8061134C(arg1->unk18);
}

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
    new->unk14 = object_timer + 2;
    new->unk10 = arg4;
}

// Doable, small struct loop
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_80636C00.s")

extern s32 D_80747D70;
extern s16 D_80747D74;

void func_80636B50(void *arg0, void *arg1, u8 arg2);

/*
// TODO: Pretty close, I think the params in the last function calls might need to be temp variables
void func_80636C00(void) {
    u32 sp20;
    u8 var_a2;
    Model2Model *temp_a3;
    ObjectModel2 *temp_a0;
    s32 temp_v1_2;
    u8 temp_v1;
    OM2_unk24 *temp_v0;

    if (D_80747D70 != 0) {
        D_80747D74 += 1;
        if (D_80747D74 >= D_80747D70) {
            D_80747D74 = 0;
        }
        temp_a0 = &D_807F6000[D_80747D74];
        temp_v0 = temp_a0->unk24;
        if (temp_v0->unk0 & 0x10) {
            if ((temp_a0->unk8C & 0x20) && (object_timer != temp_v0->unk8)) {
                temp_a0->unk8C &= 0xFFDF;
                temp_v0->unk3C--;
                if (temp_v0->unk3C != 0) {
                    var_a2 = 0;
                } else {
                    var_a2 = 1;
                }
                temp_a3 = D_807F6000[D_80747D74].model_pointer;
                func_80636B50(temp_a3->unkA0[0], temp_a3->unkA0[0] + (((temp_a3->unkA0[2] - temp_a3->unkA0[0]) >> 3) * 8), var_a2);
                func_80636B50(temp_a3->unkA0[2], temp_a3->unkA0[2] + (((temp_a3->unkB0 - temp_a3->unkA0[2]) >> 3) * 8), var_a2);
            }
        }
    }
}
*/

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

void func_8063A8C4(s16 arg0, u8 arg1, f32 arg2) {
    Model2Model *temp_v1;
    Model2Model54_BC *phi_v0;

    if (arg1 == 1) {
        arg0 = func_80659470(arg0);
    }
    temp_v1 = D_807F6000[arg0].model_pointer;
    if (D_807F6000[arg0].unk86 != 1) {
        if (D_807F6000[arg0].unk86 != 2) {

        } else {
            phi_v0 = temp_v1->unk54;
        }
    } else {
        phi_v0 = temp_v1->unkBC;
    }
    if (phi_v0 != NULL) {
        phi_v0->unk4 = arg2;
    }
}

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

s32 func_8063C2A8(s16 arg0) {
    OM2_unk7C *temp_v1;

    // TODO: Find a way to get rid of s16 typecast...?
    temp_v1 = D_807F6000[(s16)func_80659470(arg0)].unk7C;
    if (temp_v1 != NULL) {
        if ((temp_v1->unk60 == 1) && (temp_v1->unk64 == 0)) {
            return 0;
        }
        return 1;
    }
    return 1;
}

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
