#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 min_x; // 0
    s16 min_y; // 2
    s16 min_z; // 4
    s16 max_x; // 6
    s16 max_y; // 8
    s16 max_z; // A
    s16 unkC;
    u8 unkE;
    u8 unkF;
} GlobalASMStruct84;

typedef struct global_asm_struct_85 GlobalASMStruct85;
struct global_asm_struct_85 {
    GlobalASMStruct84* unk0; // Bounding Box
    GlobalASMStruct83* unk4;
    GlobalASMStruct85* next;
};

extern GlobalASMStruct85 *D_global_asm_807F9410;

// doable, fiddly, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_684C0/func_global_asm_806637C0.s")

/*
void func_global_asm_806637C0(MapGeometryHeader *arg0) {
    s32 *temp_v0;
    s32 count;
    s32 i;
    GlobalASMStruct85 **var_s1;
    GlobalASMStruct85 *temp_v0_2;
    GlobalASMStruct84 *boundingBoxArray;

    var_s1 = &D_global_asm_807F9410;
    temp_v0 = &((u8*)arg0)[arg0->unk54];
    count = *(s32*)(&((u8*)arg0)[arg0->unk54]);
    boundingBoxArray = &((u8*)arg0)[arg0->unk54 + 4];
    D_global_asm_807F9410 = NULL;
    for (i = 0; i < count; i++) {
        temp_v0_2 = malloc(sizeof(GlobalASMStruct85));
        *var_s1 = temp_v0_2;
        var_s1 = &temp_v0_2->next;
        temp_v0_2->unk0 = &boundingBoxArray[i];
        temp_v0_2->unk4 = NULL;
        temp_v0_2->next = NULL;
    }
}
*/

s32 func_global_asm_806639CC(Actor*, GlobalASMStruct83*);
void func_global_asm_80663A0C(Actor *arg0, GlobalASMStruct84 *arg1);

void func_global_asm_80663844(Actor *arg0) {
    GlobalASMStruct85 *current;
    GlobalASMStruct84 *boundingBox;
    GlobalASMStruct83 *current2;
    GlobalASMStruct83 *temp_v0_4;
    GlobalASMStruct83 **phi_s0;

    current = D_global_asm_807F9410;
    while (current) {
        boundingBox = current->unk0;
        if (boundingBox->min_x <= arg0->x_position
            && boundingBox->min_y <= arg0->y_position
            && boundingBox->min_z <= arg0->z_position
            && arg0->x_position <= boundingBox->max_x
            && arg0->y_position <= boundingBox->max_y
            && arg0->z_position <= boundingBox->max_z
            && !func_global_asm_806639CC(arg0, current->unk4)) {
            func_global_asm_80663A0C(arg0, current->unk0);
            phi_s0 = &current->unk4;
            current2 = current->unk4;
            while (current2) {
                phi_s0 = &current2->next;
                current2 = current2->next;
            }
            temp_v0_4 = malloc(sizeof(GlobalASMStruct83));
            *phi_s0 = temp_v0_4;
            temp_v0_4->unk0 = arg0;
            temp_v0_4->unk4 = arg0->unk54;
            temp_v0_4->unk8 = D_global_asm_807FBB44;
            temp_v0_4->next = NULL;
        }
        current = current->next;
    }
}

s32 func_global_asm_806639CC(Actor *arg0, GlobalASMStruct83 *arg1) {
    while (arg1) {
        if (arg0 == arg1->unk0 && arg1->unk4 == arg0->unk54) {
            return TRUE;
        }
        arg1 = arg1->next;
    }
    return FALSE;
}

// TODO: Add to AAD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC; // Used
    u8 unkE; // Used
    u8 unkF; // Used
} KongMirrorAAD;

void func_global_asm_80663A0C(Actor *arg0, GlobalASMStruct84 *arg1) {
    KongMirrorAAD *temp_v1;

    func_global_asm_80677FA8(ACTOR_REFLECTION_MUSEUM, func_global_asm_80613448(arg0)); // Spawn actor: Kong Mirror (Creepy Castle Museum)
    D_global_asm_807FBB44->unk11C = arg0;
    temp_v1 = D_global_asm_807FBB44->additional_actor_data;
    temp_v1->unkE = arg1->unkE;
    temp_v1->unkC = arg1->unkC;
    temp_v1->unkF = arg1->unkF;
    arg0->unk156++;
}

void func_global_asm_80663A80(void) {
    Actor *temp_v1;
    GlobalASMStruct83 **var_s1;
    GlobalASMStruct83 *temp_a0;
    GlobalASMStruct83 *current83;
    GlobalASMStruct84 *boundingBox;
    GlobalASMStruct85 *current85;

    current85 = D_global_asm_807F9410;
    while (current85 != NULL) {
        current83 = current85->unk4;
        var_s1 = &current85->unk4;
        while (current83 != NULL) {
            boundingBox = current85->unk0;
            temp_v1 = current83->unk0;
            if ((temp_v1->x_position < boundingBox->min_x)
                || (temp_v1->y_position < boundingBox->min_y)
                || (temp_v1->z_position < boundingBox->min_z)
                || (boundingBox->max_x < temp_v1->x_position)
                || (boundingBox->max_y < temp_v1->y_position)
                || (boundingBox->max_z < temp_v1->z_position)) {
                temp_v1->unk156--;
                func_global_asm_806782C0(current83->unk8);
                temp_a0 = current83;
                *var_s1 = current83->next;
                current83 = current83->next;
                func_global_asm_8061130C(temp_a0);
            } else {
                var_s1 = &current83->next;
                current83 = current83->next;
            }
        }
        current85 = current85->next;
    }
}

void func_global_asm_80663BE8(Actor *arg0) {
    GlobalASMStruct83 **var_v1;
    GlobalASMStruct83 *current83;
    GlobalASMStruct85 *current85;

    current85 = D_global_asm_807F9410;
    while (current85 != NULL) {
        var_v1 = &current85->unk4;
        current83 = current85->unk4;
        while (current83 != NULL) {
            Actor *temp = current83->unk8;
            if (arg0 == temp) {
                *var_v1 = current83->next;
                func_global_asm_8061130C(current83);
                return;
            }
            var_v1 = &current83->next;
            current83 = current83->next;
        }
        current85 = current85->next;
    }
}
