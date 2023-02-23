#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B76B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B7830.s")

extern f32 D_8075B878;

void func_806907F0(f32, f32, f32);
void func_80690A28(s16, s32, f32, f32, f32, f32, f32, Actor*);

void func_806B7BB8(s32 arg0) {
    s32 phi_v1;

    if ((current_map != MAP_CAVES_SHACK_CHUNKY) && (current_map != MAP_CAVES_IGLOO_DIDDY)) {
        phi_v1 = 30;
    } else {
        phi_v1 = 99;
    }
    func_806907F0(D_807FDC94->x_position, D_807FDC94->y_position + 100.0f, D_807FDC94->z_position);
    func_80690A28(phi_v1, 1, 0.5f, D_807FDC94->x_position, D_807FDC94->y_position, D_807FDC94->z_position, D_8075B878, current_actor_pointer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B7C74.s")

extern f64 D_8075B880;
extern f64 D_8075B888;
extern f64 D_8075B890;

typedef struct GlobalASMStruct90 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} GlobalASMStruct90;

extern s16 D_80744490;
extern s16 D_80744494;

/*
// TODO: Doable, annoying float stuff
void func_806B7C74(GlobalASMStruct90 *arg0, f32 arg1, f32 arg2) {
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;

    if (arg1 < arg0->unk0) {
        // Problem here
        arg0->unk8 -= D_8075B880;
        if (arg0->unk8 < -5.0f) {
            arg0->unk8 = -5.0f;
        }
    } else if (arg0->unk0 < arg1) {
        // Problem here
        arg0->unk8 += D_8075B888;
        if (arg0->unk8 > 5.0f) {
            arg0->unk8 = 5.0f;
        }
    }
    if (arg2 < arg0->unk4) {
        // Problem here
        arg0->unkC -= D_8075B890;
        if (arg0->unkC < -5.0f) {
            arg0->unkC = -5.0f;
        }
    } else if (arg0->unk4 < arg2) {
        // Problem here
        arg0->unkC += D_8075B890;
        if (arg0->unkC > 5.0f) {
            arg0->unkC = 5.0f;
        }
    }
    // Here down is all good I think
    var_f2 = MAX(arg0->unk0 + arg0->unk8, 0.0f);
    if (var_f2 < D_80744490) {
        var_f2_2 = MAX(arg0->unk0 + arg0->unk8, 0.0f);
        arg0->unk0 = var_f2_2;
    } else {
        arg0->unk0 = D_80744490;
    }
    var_f2_3 = MAX(arg0->unk4 + arg0->unkC, 0.0f);
    if (var_f2_3 < D_80744494) {
        var_f2_4 = MAX(arg0->unk4 + arg0->unkC, 0.0f);
        arg0->unk4 = var_f2_4;
    } else {
    arg0->unk4 = D_80744494;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B7EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B83E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B86AC.s")

void func_806B8878(void) {
    func_806B88B8();
}

void func_806B8898(void) {
    func_806B88B8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_806B88B8.s")
