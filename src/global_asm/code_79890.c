#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_global_asm_80674B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_global_asm_80674E14.s")

// Matrix nonsense, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_global_asm_80675180.s")

typedef struct {
    u8 unk0[0x70 - 0x0];
    Mtx *unk70;
    Mtx (*unk74)[1];
} Struct80675180_arg0;

typedef struct {
    u8 unk0[0x20 - 0x0];
    u32 unk20;
} Struct80675180_arg4;

/*
void func_global_asm_80675180(Struct80675180_arg0 *arg0, f32 arg1, f32 arg2, f32 arg3, Struct80675180_arg4 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    u8 temp = D_global_asm_807444FC;

    if (arg4->unk20 == -1) {
        memcpy(sp70, arg0->unk70, 0x40);
    } else {
        guMtxL2F(sp70, &arg0->unk74[temp][arg4->unk20]);
    }
    func_global_asm_8062FF10(sp30, sp70);
    guMtxXFMF(sp30, arg1, arg2, arg3, arg5, arg6, arg7);
}
*/

f32 func_global_asm_80675234(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;
    f32 var_f12;

    temp_f0 = arg0 - arg3;
    temp_f2 = arg1 - arg4;
    temp_f14 = arg2 - arg5;
    var_f12 = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14)) - arg6;
    if (var_f12 < 0.0) {
        var_f12 = 0.0f;
    }
    return var_f12 / 8;
}

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

extern Struct806752D4 *D_global_asm_807FB620;
extern Struct806752D4 *D_global_asm_807FB624;
extern s32 D_global_asm_807FB628;

void func_global_asm_806752D4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
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
    if (D_global_asm_807FB620 != NULL) {
        D_global_asm_807FB624->next = temp_v0;
    } else {
        D_global_asm_807FB620 = temp_v0;
    }
    D_global_asm_807FB624 = temp_v0;
    D_global_asm_807FB628++;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Struct80675380;

void func_global_asm_80675380(Actor *arg0, Actor *arg1) {
    Struct80675380 *var_s1;
    Struct806752D4 *var_s0;
    Struct806752D4 *temp_s3;
    s32 i;

    var_s1 = malloc(D_global_asm_807FB628 * sizeof(Struct80675380));
    var_s0 = D_global_asm_807FB620;
    for (i = 0; i < D_global_asm_807FB628; i++) {
        var_s1[i].unk0 = var_s0->unk0;
        var_s1[i].unk4 = var_s0->unk4;
        var_s1[i].unk8 = var_s0->unk8;
        var_s1[i].unkC = var_s0->unkC;
        var_s1[i].unk10 = var_s0->unk10;
        var_s1[i].unk14 = var_s0->unk14;
        var_s1[i].unk18 = var_s0->unk18;
        temp_s3 = var_s0->next;
        free(var_s0);
        var_s0 = temp_s3;
    }
    func_global_asm_80679200(arg1, arg0, 0x8000, 0, D_global_asm_807FB628, var_s1);
}

// Matrix nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_79890/func_global_asm_80675478.s")

s32 func_global_asm_806742C0(s16, s16, s32, s32);

void func_global_asm_806755A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_v1;
    s32 pad;
    f32 temp_f0;
    s16 sp32;
    s32 var_t0;
    s32 var_v0;

    var_t0 = arg2 - arg0;
    var_v0 = ABS(arg2 - arg0);
    if (var_v0 < 0x2711) {
        var_v1 = arg3 - arg1;
        if ((ABS(var_v1)) < 0x2711) {
            temp_f0 = sqrtf((var_t0 * var_t0) + (var_v1 * var_v1));
            if (temp_f0 != 0.0) {
                if (var_t0 >= 0) {
                    if (var_v1 >= 0) {
                        sp32 = func_global_asm_80611E60((var_t0 * 65535.9) / temp_f0) >> 4;
                    }
                }
                if (var_t0 >= 0) {
                    if (var_v1 < 0) {
                        sp32 = (func_global_asm_80611E60(((arg1 - arg3) * 65535.9) / temp_f0) >> 4) + 0x400;
                    }
                }
                if (var_t0 < 0) {
                    if (var_v1 < 0) {
                        sp32 = (func_global_asm_80611E60(((arg0 - arg2) * 65535.9) / temp_f0) >> 4) + 0x800;
                    }
                }
                if (var_t0 < 0) {
                    if (var_v1 >= 0) {
                        sp32 = (func_global_asm_80611E60((var_v1 * 65535.9) / temp_f0) >> 4) + 0xC00;
                    }
                }
                func_global_asm_806742C0(sp32 + 0x400, sp32 - 0x400, arg4, arg5);
            }
        }
    }
}
