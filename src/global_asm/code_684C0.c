#include <ultra64.h>
#include "functions.h"


typedef struct global_asm_struct_83 GlobalASMStruct83;
struct global_asm_struct_83 {
    Actor* unk0;
    u32 unk4;
    Actor* unk8;
    GlobalASMStruct83 *next;
};

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
    GlobalASMStruct84* unk0;
    GlobalASMStruct83* unk4;
    GlobalASMStruct85* next;
};

extern GlobalASMStruct85 *D_807F9410;

// TODO: Doable, fiddly struct loop with D_807F9410, could use file specifc ctx
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_684C0/func_806637C0.s")

s32 func_806639CC(Actor*, GlobalASMStruct83*);
void func_80663A0C(Actor *arg0, GlobalASMStruct84 *arg1);

void func_80663844(Actor *arg0) {
    GlobalASMStruct85 *current;
    GlobalASMStruct84 *boundingBox;
    GlobalASMStruct83 *current2;
    GlobalASMStruct83 *temp_v0_4;
    GlobalASMStruct83 **phi_s0;

    current = D_807F9410;
    while (current) {
        boundingBox = current->unk0;
        if (boundingBox->min_x <= arg0->x_position
            && boundingBox->min_y <= arg0->y_position
            && boundingBox->min_z <= arg0->z_position
            && arg0->x_position <= boundingBox->max_x
            && arg0->y_position <= boundingBox->max_y
            && arg0->z_position <= boundingBox->max_z
            && !func_806639CC(arg0, current->unk4)) {
            func_80663A0C(arg0, current->unk0);
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
            temp_v0_4->unk8 = D_807FBB44;
            temp_v0_4->next = NULL;
        }
        current = current->next;
    }
}

s32 func_806639CC(Actor *arg0, GlobalASMStruct83 *arg1) {
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

void func_80663A0C(Actor *arg0, GlobalASMStruct84 *arg1) {
    KongMirrorAAD *temp_v1;

    func_80677FA8(0x7B, func_80613448(arg0)); // Spawn actor: Kong Mirror (Creepy Castle Museum)
    D_807FBB44->unk11C = arg0;
    temp_v1 = D_807FBB44->additional_actor_data;
    temp_v1->unkE = arg1->unkE;
    temp_v1->unkC = arg1->unkC;
    temp_v1->unkF = arg1->unkF;
    arg0->unk156++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_684C0/func_80663A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_684C0/func_80663BE8.s")
