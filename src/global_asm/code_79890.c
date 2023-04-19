#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_80674B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_80674E14.s")

// Matrix nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_80675180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_80675234.s")

/*
f32 func_80675234(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f12;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg1 - arg4;
    temp_f14 = arg2 - arg5;
    temp_f2_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14)) - arg6;
    var_f12 = temp_f2_2;
    if (temp_f2_2 < 0.0) {
        var_f12 = 0.0f;
    }
    return var_f12 / 8.0f;
}
*/

typedef struct Struct_806752D4 Struct806752D4;

struct Struct_806752D4 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Struct806752D4 *next;
};

extern Struct806752D4 *D_807FB620;
extern Struct806752D4 *D_807FB624;
extern s32 D_807FB628;

void func_806752D4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    Struct806752D4 *temp_v0;

    temp_v0 = malloc(sizeof(Struct806752D4));
    temp_v0->unk0 = arg1;
    temp_v0->unk4 = arg2;
    temp_v0->unk8 = arg3;
    temp_v0->unkC = arg4;
    temp_v0->unk10 = arg5;
    temp_v0->unk14 = arg6;
    temp_v0->unk18 = arg0;
    temp_v0->next = NULL;
    if (D_807FB620 != NULL) {
        D_807FB624->next = temp_v0;
    } else {
        D_807FB620 = temp_v0;
    }
    D_807FB624 = temp_v0;
    D_807FB628++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_80675380.s")

// Very close
/*
void func_80675380(Actor *arg0, Actor *arg1) {
    void *sp3C;
    s32 temp_v1;
    s32 i;
    Struct806752D4 *temp_s3;
    Struct806752D4 *var_s0;
    Struct806752D4 *var_s1;

    sp3C = malloc(D_807FB628 * 0x1C);
    var_s0 = D_807FB620;
    i = 0;
    var_s1 = sp3C;
    while (i < D_807FB628) {
        var_s1->unk0 = var_s0->unk0;
        var_s1->unk4 = var_s0->unk4;
        var_s1->unk8 = var_s0->unk8;
        var_s1->unkC = var_s0->unkC;
        var_s1->unk10 = var_s0->unk10;
        var_s1->unk14 = var_s0->unk14;
        var_s1->unk18 = var_s0->unk18;
        temp_s3 = var_s0->next;
        func_8061130C(var_s0);
        var_s1++;
        i++;
        var_s0 = temp_s3;
    }
    func_80679200(arg1, arg0, 0x8000, 0, D_807FB628, sp3C);
}
*/

// Matrix nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_80675478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_806755A8.s")
