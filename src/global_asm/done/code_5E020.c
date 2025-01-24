#include <ultra64.h>
#include "functions.h"

typedef struct global_asm_struct_78 {
    s32 unk0;
    s32 unk4; // Index into object model 2 array?
    struct global_asm_struct_78 *unk8; // Linked list?
} global_asm_struct_78;

extern global_asm_struct_78 *D_global_asm_807F7370[100];

void func_global_asm_80659320(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_global_asm_807F7370); i++) {
        D_global_asm_807F7370[i] = NULL;
    }
}

void func_global_asm_80659350(void) {
    s32 i;
    global_asm_struct_78 *temp;
    global_asm_struct_78 *temp_1;

    for (i = 0; i < ARRAY_COUNT(D_global_asm_807F7370); i++) {
        temp = D_global_asm_807F7370[i];
        while (temp) {
            temp_1 = temp->unk8;
            free(temp);
            temp = temp_1;
        }
    }
    func_global_asm_80659320();
}

void func_global_asm_806593C8(s32 arg0, s32 arg1) {
    global_asm_struct_78 *temp_v0;
    global_asm_struct_78 *var_a1;
    global_asm_struct_78 *var_v1;

    var_a1 = &D_global_asm_807F7370[func_global_asm_80659544(arg0)];
    var_v1 = var_a1->unk0;
    while ((var_v1 != NULL) && (arg0 != var_v1->unk0)) {
        var_a1 = &var_v1->unk8;
        var_v1 = var_v1->unk8;
    }
    if (var_v1 == NULL) {
        temp_v0 = malloc(sizeof(global_asm_struct_78));
        var_a1->unk0 = temp_v0;
        temp_v0->unk0 = arg0;
        temp_v0->unk4 = arg1;
        temp_v0->unk8 = 0;
        return;
    }
    var_v1->unk4 = arg1;
}

// Returns an index into object model2 array
s32 func_global_asm_80659470(s32 arg0) {
    global_asm_struct_78 *phi_v1;

    phi_v1 = D_global_asm_807F7370[func_global_asm_80659544(arg0)];
    while (phi_v1) {
        if (arg0 == phi_v1->unk0) {
            return phi_v1->unk4;
        }
        phi_v1 = phi_v1->unk8;
    }
    return -1;
}

void func_global_asm_806594C8(s32 arg0) {
    // TODO: Clean up these temp variables
    // Probably don't need so much indirection
    global_asm_struct_78 **temp_v1;
    global_asm_struct_78 *phi_a0;
    global_asm_struct_78 **phi_v1;

    temp_v1 = &D_global_asm_807F7370[func_global_asm_80659544(arg0)];
    phi_a0 = *temp_v1;
    phi_v1 = temp_v1;
    while (phi_a0 && arg0 != phi_a0->unk0) {
        phi_v1 = &phi_a0->unk8;
        phi_a0 = phi_a0->unk8;
    }
    if (phi_a0) {
        *phi_v1 = phi_a0->unk8;
        free(phi_a0);
    }
}

s32 func_global_asm_80659544(s32 arg0) {
    // Yes the ternary is required
    // ABS macro doesn't match
    return (arg0 > 0 ? arg0 : -arg0) % 100; //maybe should be `ARRAY_COUNT(D_global_asm_807F7370)` instead of 100?
}

void func_global_asm_80659574(void) {
    global_asm_struct_78 *var_v0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_global_asm_807F7370); i++) {
        var_v0 = &D_global_asm_807F7370[i]->unk0;
        while (var_v0 != NULL) {
            var_v0 = var_v0->unk8;
        }
    }
}

// Did they literally make the same function twice?
void func_global_asm_806595B0(void) {
    global_asm_struct_78 *var_v0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_global_asm_807F7370); i++) {
        var_v0 = &D_global_asm_807F7370[i]->unk0;
        while (var_v0 != NULL) {
            var_v0 = var_v0->unk8;
        }
    }
}
