#include <ultra64.h>
#include "functions.h"


typedef struct global_asm_struct_78 GlobalASMStruct78;

struct global_asm_struct_78 {
    s32 unk0;
    s32 unk4; // Index into object model 2 array?
    GlobalASMStruct78 *unk8; // Linked list?
};

extern GlobalASMStruct78 *D_807F7370[];

void func_80659320(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        D_807F7370[i] = NULL;
    }
}

void func_80659350(void) {
    s32 i;
    GlobalASMStruct78 *temp;
    GlobalASMStruct78 *temp_1;

    for (i = 0; i < 100; i++) {
        temp = D_807F7370[i];
        while (temp) {
            temp_1 = temp->unk8;
            func_8061130C(temp);
            temp = temp_1;
        }
    }
    func_80659320();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E020/func_806593C8.s")

/*
// TODO: Quite close
void func_806593C8(s32 arg0, s32 arg1) {
    GlobalASMStruct78 *temp_v0;
    GlobalASMStruct78 *temp_v1;

    temp_v1 = D_807F7370[func_80659544(arg0)];
    while (temp_v1 && arg0 != temp_v1->unk0) {
        temp_v1 = temp_v1->unk8;
    }

    if (!temp_v1) {
        temp_v0 = malloc(sizeof(GlobalASMStruct78));
        temp_v1->unk8 = temp_v0;
        temp_v0->unk0 = arg0;
        temp_v0->unk4 = arg1;
        temp_v0->unk8 = NULL;
    } else {
        temp_v1->unk4 = arg1;
    }
}
*/

// Returns an index into object model2 array
s32 func_80659470(s32 arg0) {
    GlobalASMStruct78 *phi_v1;

    phi_v1 = D_807F7370[func_80659544(arg0)];
    while (phi_v1) {
        if (arg0 == phi_v1->unk0) {
            return phi_v1->unk4;
        }
        phi_v1 = phi_v1->unk8;
    }
    return -1;
}

void func_806594C8(s32 arg0) {
    // TODO: Clean up these temp variables
    // Probably don't need so much indirection
    GlobalASMStruct78 **temp_v1;
    GlobalASMStruct78 *phi_a0;
    GlobalASMStruct78 **phi_v1;

    temp_v1 = &D_807F7370[func_80659544(arg0)];
    phi_a0 = *temp_v1;
    phi_v1 = temp_v1;
    while (phi_a0 && arg0 != phi_a0->unk0) {
        phi_v1 = &phi_a0->unk8;
        phi_a0 = phi_a0->unk8;
    }
    if (phi_a0) {
        *phi_v1 = phi_a0->unk8;
        func_8061130C(phi_a0);
    }
}

s32 func_80659544(s32 arg0) {
    // Yes the ternary is required
    // ABS macro doesn't match
    return (arg0 > 0 ? arg0 : -arg0) % 100;
}

void func_80659574(void) {
    GlobalASMStruct78 *var_v0;
    s32 i;

    for (i = 0; i < 100; i++) {
        var_v0 = &D_807F7370[i]->unk0;
        while (var_v0 != NULL) {
            var_v0 = var_v0->unk8;
        }
    }
}

// Did they literally make the same function twice?
void func_806595B0(void) {
    GlobalASMStruct78 *var_v0;
    s32 i;

    for (i = 0; i < 100; i++) {
        var_v0 = &D_807F7370[i]->unk0;
        while (var_v0 != NULL) {
            var_v0 = var_v0->unk8;
        }
    };
}