#include <ultra64.h>
#include "functions.h"

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FD8E0.s")

s32 func_global_asm_806FBD5C(s16, void*);
void *func_global_asm_806FC530(void *arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4, u8 arg5);
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;

/*
void func_global_asm_806FD8E0(void *arg0, s16 arg1, void *arg2, s16 arg3, u8 arg4) {
    func_global_asm_806FC530(arg0, arg1, (D_global_asm_80744490 - func_global_asm_806FBD5C(arg1, arg2)) * 2, arg3 * 4, arg2, arg4);
}
*/

// TODO: Does this return the void* from func_global_asm_806FC530?
void func_global_asm_806FD950(void *arg0, s16 arg1, void *arg2, s16 arg3) {
    func_global_asm_806FC530(arg0, arg1, 0x60, arg3 * 4, arg2, 1);
}

typedef struct GlobalASMStruct2 GlobalASMStruct2;

struct GlobalASMStruct2 {
    GlobalASMStruct2 *next;
    s32 unk4;
    s32 unk8;
    u8 padC[0x18 - 0x0C];
    f32 unk18;
    s16 unk1C;
};

extern GlobalASMStruct2 *D_global_asm_80754AD0;
extern u16 D_global_asm_80754AD4;

extern f32 D_global_asm_8075DFB0;
extern f32 D_global_asm_8075DFB4;

extern u8 D_global_asm_807FD890;
extern u16 D_global_asm_807FD892;
extern u8 D_global_asm_807FD894;
extern u8 D_global_asm_807FD895;
extern u8 D_global_asm_807FD896;
extern u8 D_global_asm_807FD897;
extern u8 D_global_asm_807FD898;
extern u8 D_global_asm_807FD899;
extern s32 D_global_asm_807FD8A0;
extern Mtx D_global_asm_807FD928;
extern f32 D_global_asm_807FD968;
extern s32 D_global_asm_807FD978;

void func_global_asm_806FD9A0(void) {
    D_global_asm_80754AD0 = NULL;
    D_global_asm_80754AD4 = 0;
}

GlobalASMStruct2 *func_global_asm_806FD9B4(s16 arg0) {
    GlobalASMStruct2 *var_v1;

    var_v1 = D_global_asm_80754AD0;
    while (var_v1 != NULL && arg0 != var_v1->unk1C) {
        var_v1 = var_v1->next;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FD9FC.s")

/*
s32 func_global_asm_806FD9FC(s32 arg0, s16 arg1, s16 arg2) {
    s32 temp_t2;

    temp_t2 = func_global_asm_806FD9B4(arg1)->unk8[arg2];
    arg0 = temp_t2;
    arg0->unk30->unk4 = temp_t2->unk40->unk4;
    return arg0;
}
*/

f32 func_global_asm_806FDA8C(s16 arg0) {
    return func_global_asm_806FD9B4(arg0)->unk18;
}

void func_global_asm_806FDAB8(s16 arg0, f32 arg1) {
    func_global_asm_806FD9B4(arg0)->unk18 = arg1;
}

void func_global_asm_806FDAEC(s16 arg0) {
    GlobalASMStruct2 *var_a1;
    GlobalASMStruct2 *var_v0;

    var_a1 = D_global_asm_80754AD0;
    var_v0 = NULL;
    while (var_a1 != NULL && arg0 != var_a1->unk1C) {
        var_v0 = var_a1;
        var_a1 = var_a1->next;
    }
    if (var_v0 != NULL) {
        var_v0->next = var_a1->next;
    } else {
        D_global_asm_80754AD0 = var_a1->next;
    }
    func_global_asm_8061130C(var_a1->unk4, var_a1);
    func_global_asm_8061130C(var_a1->unk8, var_a1);
    func_global_asm_8061130C(var_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FDB8C.s")

void func_global_asm_806FDF1C(s16 arg0, s32 arg1) {
    func_dk64_boot_80002A30(func_global_asm_806FD9B4(arg0)->unk4, arg1);
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FDF54.s")

extern f32 D_global_asm_8075DD58;
extern f32 D_global_asm_8075DD5C;
extern f64 D_global_asm_8075DD60;
extern f32 D_global_asm_8075DD68;

/*
void func_global_asm_806FDF54(f32 *arg0, f32 *arg1) {
    while (*arg1 < 0.0f) {
        *arg1 += D_global_asm_8075DD58;
    }
    while (D_global_asm_8075DD5C <= *arg1) {
        *arg1 -= D_global_asm_8075DD5C;
    }
    *arg0 = (func_global_asm_806CC190((*arg0 * 2048.0) / D_global_asm_8075DD60, (*arg1 * 2048.0) / D_global_asm_8075DD60, 5.0f) * D_global_asm_8075DD68) * 0.00048828125;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FE078.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FEDB0.s")

extern f32 D_global_asm_8075DE70;
Gfx *func_global_asm_806FEDB0(s32, u8);

void func_global_asm_806FEF7C(s32 arg0, Actor *arg1) {
    Gfx *dl;

    dl = func_global_asm_806FEDB0(arg0, arg1->PaaD->unk1A4);
    gDPSetRenderMode(dl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, 0xFF);

    func_global_asm_8068C5A8(dl, 0x3C, 3, 1, 0x40, 0x40, 0xA0, 0x78, 5.0f, 5.0f, 0, D_global_asm_8075DE70);
}

s32 func_global_asm_80690F30(s32, s32 *, Actor*, s32, s32, s32, s32 *, s32 *, s32 *);

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} Struct807FD568;

extern Struct807FD568 *D_global_asm_807FD568; // TODO: Unknown struct

void func_global_asm_806FF01C(s32 arg0, Actor *arg1) {
    u8 playerIndex;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    Gfx *dl;

    playerIndex = arg1->PaaD->unk1A4;
    dl = func_global_asm_806FEDB0(arg0, playerIndex);
    if (D_global_asm_807FD568->unk2 & 2 && func_global_asm_806F8AD4(3, playerIndex) != 0 && func_global_asm_80690F30(2, &sp58, arg1, 1, 0, 0, &sp54, &sp50, &sp4C) != 0) {
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0xC8, 0x00, 0xFF);
    } else {
        gDPSetPrimColor(dl++, 0, 0, 0xC8, 0x00, 0x00, 0xFF);
    }
    func_global_asm_8068C5A8(dl, 0x38, 3, 1, 0x40, 0x40, 0xA0, 0x78, 0.5f, 0.5f, 0x2D, 0.0f);
}

void func_global_asm_806FF144(Gfx *dl) {
    gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gSPMatrix(dl++, &D_2000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    dl = func_global_asm_8068C5A8(dl, 0x3A, 3, 1, 0x40, 0x40, 0x3E, 0x3E, 2.0f, 2.0f, 0, 0.0f);
    dl = func_global_asm_8068C5A8(dl, 0x3A, 3, 1, 0x40, 0x40, D_global_asm_80744490 - 0x3E, 0x3E, 2.0f, 2.0f, 0x5A, 0.0f);
    dl = func_global_asm_8068C5A8(dl, 0x3A, 3, 1, 0x40, 0x40, D_global_asm_80744490 - 0x3E, D_global_asm_80744494 - 0x3E, 2.0f, 2.0f, 0xB4, 0.0f);
    func_global_asm_8068C5A8(dl, 0x3A, 3, 1, 0x40, 0x40, 0x3E, D_global_asm_80744494 - 0x3E, 2.0f, 2.0f, 0x10E, 0.0f);
}

void func_global_asm_806FF32C(s32 arg0, Actor *arg1) {
    func_global_asm_806FF144(func_global_asm_806FEDB0(arg0, arg1->PaaD->unk1A4));
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FF358.s")

Gfx *func_global_asm_806FF628(Gfx *dl, s32 arg1) {
    PlayerAdditionalActorData *PaaD;

    PaaD = character_change_array->player_pointer->additional_actor_data;
    dl = func_global_asm_806FEDB0(dl, PaaD->unk1A4);
    if (PaaD->unk1EC == 2) {
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0x00, 0x00, 0x64);
        dl = func_global_asm_8068C5A8(dl, 0x45, 3, 1, 0x40, 0x40, 0xA0, 0x78, 2.0f, 2.0f, 0, 0.0f);
    } else if (PaaD->unk1EC == 1) {
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0xFF, 0x00, 0x64);
        dl = func_global_asm_8068C5A8(dl, 0x44, 3, 1, 0x40, 0x40, 0xA0, 0x78, 2.0f, 2.0f, 0, 0.0f);
    }
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FF75C.s")

extern f64 D_global_asm_8075DE78;

void func_global_asm_806FFB2C(s32 arg0, Actor *arg1) {
    f32 sp3C;
    Gfx *dl;

    sp3C = arg1->control_state_progress * D_global_asm_8075DE78;
    dl = func_global_asm_806FEDB0(arg0, arg1->PaaD->unk1A4);
    gDPSetRenderMode(dl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
    func_global_asm_8068C5A8(dl, 0x3C, 3, 1, 0x40, 0x40, 0xA0, 0x78, 5.0f, 5.0f, 0, sp3C);
}

// Hmm, weird m2c errors
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FFC04.s")

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FFEAC.s")

void func_global_asm_806FFF5C(void) {
    // Texture, maybe pulling it into cache?
    getPointerTableFile(0x19, 0x138B, 1, 1);
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_806FFF88.s")

// Haha what, some crazy one liner
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80700088.s")

s32 func_global_asm_80700088(f32 arg0, s32 arg1);

void func_global_asm_807002AC(u16 *arg0, s16 **arg1, f32 arg2) {
    s16 *temp_v0;
    s16 *var_s0;
    s16 i;

    temp_v0 = malloc(0xA000);
    *arg1 = temp_v0;
    func_global_asm_8061134C(temp_v0);
    var_s0 = *arg1;
    for (i = 0; i < 0x5000; i++) {
        *var_s0 = func_global_asm_80700088(arg2, *arg0++);
        var_s0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_8070033C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_8070068C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807007B8.s")

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807009F4.s")

extern s16 *D_global_asm_8076A0A0;

/*
s16 func_global_asm_807009F4(s16 arg0) {
    s16 temp_t8;
    s16 var_a1;
    s16 var_v0;

    var_v0 = 0;
    var_a1 = 0x1FE;
    if (arg0 == -1) {
        return 0;
    }
    while (TRUE) {
        temp_t8 = (var_v0 + var_a1) / 2;
        if (arg0 < D_global_asm_8076A0A0[temp_t8]) {
            var_a1 = temp_t8 - 1;
        } else {
            var_v0 = temp_t8 + 1;
        }
        if (arg0 >= D_global_asm_8076A0A0[temp_t8] && arg0 < D_global_asm_8076A0A0[temp_t8 + 1]) {
            return temp_t8 + 8;
        }
        if (var_a1 < var_v0) {
            return MAX(0, arg0 - 0x7C1B);
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80700AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80700BF4.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80701098.s")

void func_global_asm_80701C90(void) {
    D_global_asm_807FD890 = 1;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80701CA0.s")

// TODO: Is this signature correct?
void func_global_asm_807024E0(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

// TODO: Is this signature correct?
void func_global_asm_807023E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC) {
    func_global_asm_807024E0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, 1, 0x10, 0, 0);
}

// TODO: Is this signature correct?
void func_global_asm_80702464(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, u8 argD, u8 argE) {
    func_global_asm_807024E0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, 0, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807024E0.s")

extern s16 D_global_asm_80744498; // upper left x rect
extern s16 D_global_asm_8074449C; // upper left y rect
extern s16 D_global_asm_807444A0; // lower right x rect
extern s16 D_global_asm_807444A4; // lower right y rect
extern s16 D_global_asm_807444A8;
extern s16 D_global_asm_807444AC;
extern s16 D_global_asm_807444B0;
extern f64 D_global_asm_8075DF48;

Gfx *func_global_asm_80703374(Gfx *dl, u8 r, u8 g, u8 b, u8 a) {
    if (a != 0) {
        gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
        gSPSetGeometryMode(dl++, G_SHADE | G_SHADING_SMOOTH);
        gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPPipeSync(dl++);
        gDPSetRenderMode(dl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetPrimColor(dl++, 0, 0, r, g, b, a);
        gDPSetCycleType(dl++, G_CYC_1CYCLE);
        gDPSetCombineMode(dl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetScissor(dl++, G_SC_NON_INTERLACE, D_global_asm_80744498, D_global_asm_8074449C, D_global_asm_807444A0, D_global_asm_807444A4);
        gDPFillRectangle(dl++, D_global_asm_80744498, D_global_asm_8074449C, D_global_asm_807444A0, D_global_asm_807444A4);
    }
    gDPPipeSync(dl++);
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807035C4.s")

void func_global_asm_80703850(u8 arg0) {
    f32 temp_f0;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a1;

    temp_f0 = (f32)arg0 / D_global_asm_8075DF48;
    if (func_global_asm_805FCA64() != 0) {
        character_change_array->unk272 = D_global_asm_8074449C + ((((D_global_asm_80744494 >> 1) - D_global_asm_8074449C) - 1) * temp_f0);
        character_change_array->unk276 = D_global_asm_807444A4 + (((D_global_asm_80744494 >> 1) - D_global_asm_807444A4) * temp_f0);
    } else {
        character_change_array->unk272 = D_global_asm_807444AC + ((((D_global_asm_80744494 >> 1) - D_global_asm_807444AC) - 1) * temp_f0);
        character_change_array->unk276 = D_global_asm_807444B0 + (((D_global_asm_80744494 >> 1) - D_global_asm_807444B0) * temp_f0);
    }
    character_change_array->unk270 = D_global_asm_80744498 + ((((D_global_asm_80744490 >> 1) - D_global_asm_80744498) - 1) * temp_f0);
    character_change_array->unk274 = D_global_asm_807444A0 + (((D_global_asm_80744490 >> 1) - D_global_asm_807444A0) * temp_f0);
    character_change_array->unk27A = character_change_array->unk276 - character_change_array->unk272;
    character_change_array->unk278 = character_change_array->unk274 - character_change_array->unk270;
    character_change_array->unk280 = (f32)character_change_array->unk278 / character_change_array->unk27A;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80703AB0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80703CF8.s")

void func_global_asm_807040D0(u16 arg0) {
    D_global_asm_807FD892 = arg0;
}

void func_global_asm_807040E0(u8 arg0, u8 arg1, u8 arg2) {
    D_global_asm_807FD894 = arg0;
    D_global_asm_807FD895 = arg1;
    D_global_asm_807FD896 = arg2;
}

void func_global_asm_80704108(u8 arg0, u8 arg1, u8 arg2) {
    D_global_asm_807FD897 = arg0;
    D_global_asm_807FD898 = arg1;
    D_global_asm_807FD899 = arg2;
}

extern f64 D_global_asm_8075DF78;
extern f64 D_global_asm_8075DF80;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
} Struct80704130;

void func_global_asm_80704130(Struct80704130 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    arg0->unkC = arg1;
    arg0->unkD = arg2;
    arg0->unkE = arg3;
    arg0->unkF = arg4;
    if (arg5 & 0x10) {
        if (arg5 & 0x40) {
            arg0->unk2 += (64.0f * func_global_asm_80612794((arg4 * D_global_asm_8075DF78) + 1024.0));
        } else {
            arg0->unk2 -= (64.0f * func_global_asm_80612794((arg4 * D_global_asm_8075DF80) + 1024.0));
        }
    }
}

// close, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80704298.s")

extern u8 D_global_asm_807FD896;
extern u8 D_global_asm_807FD897;
extern u8 D_global_asm_807FD898;
extern u8 D_global_asm_807FD899;

/*
void func_global_asm_80704298(s32 arg0, u8 arg1, u8 arg2) {
    s32 temp2;
    s32 sp34;
    s16 var_t0;
    s16 var_t1;
    s16 temp = D_global_asm_807FD892;

    if (temp >= 0x4000) {
        var_t0 = temp;
        temp2 = temp - 0x4200;
        var_t0 = temp2 + (arg1 * 0x14);
        var_t1 = var_t0 + 0xA;
    } else {
        var_t0 = temp - (arg1 * 0x14);
        var_t1 = var_t0 - 0xA;
    }
    if (var_t0 < 0) {
        var_t0 = 0;
    }
    if (var_t0 >= 0x100) {
        var_t0 = 0xFF;
    }
    if (var_t1 < 0) {
        var_t1 = 0;
    }
    if (var_t1 >= 0x100) {
        var_t1 = 0xFF;
    }
    func_global_asm_80704130(arg0, D_global_asm_807FD894, D_global_asm_807FD895, D_global_asm_807FD896, var_t0, arg2);
    arg0 += 0x10;
    func_global_asm_80704130(arg0, D_global_asm_807FD894, D_global_asm_807FD895, D_global_asm_807FD896, var_t1, arg2);
    arg0 += 0x10;
    func_global_asm_80704130(arg0, D_global_asm_807FD897, D_global_asm_807FD898, D_global_asm_807FD899, var_t1, (arg2 | 0x40));
    func_global_asm_80704130(arg0, D_global_asm_807FD897, D_global_asm_807FD898, D_global_asm_807FD899, var_t0, (arg2 | 0x40));
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80704444.s")

/*
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} GlobalASMStruct3;

void func_global_asm_80704444(GlobalASMStruct3 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5) {
    arg0->unk0 = arg1;
    arg0->unk2 = arg2;
    arg0->unk4 = 1000;
    arg0->unk8 = (arg3 << arg5);
    arg0->unkA = (arg4 << arg5);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80704484.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80704960.s")

extern f32 D_global_asm_807FD968;
extern f32 D_global_asm_807FD96C;
extern f32 D_global_asm_807FD970;

void func_global_asm_80704AFC(f32 arg0, f32 arg1, f32 arg2) {
    D_global_asm_807FD968 = arg0;
    D_global_asm_807FD96C = arg1;
    D_global_asm_807FD970 = arg2;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80704B20.s")

typedef struct global_asm_struct_1 {
    u8 unk0[0x0C];
    u8 unkC;
    u8 unkD;
    u8 unkE;
} GlobalASMStruct1;

void func_global_asm_80705B14(GlobalASMStruct1 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg0->unkC = arg1;
    arg0->unkD = arg2;
    arg0->unkE = arg3;
}

void func_global_asm_80705B30(void) {
    D_global_asm_807FD8A0 = 0;
    guOrtho(&D_global_asm_807FD928,
        0.0f,
        (D_global_asm_80744490 * 16.0f) - 1.0,
        (D_global_asm_80744494 * 16.0f) - 1.0,
        0.0f,
        D_global_asm_8075DFB0,
        D_global_asm_8075DFB4,
        1.0f
    );
    D_global_asm_807FD968 = -1.0f;
    D_global_asm_807FD978 = 0;
}

void func_global_asm_8070033C(f32, f32, f32, f32, f32, f32, f32, u32, u32, u32);
extern f64 D_global_asm_8075DFB8;
extern f64 D_global_asm_8075DFC0;

void func_global_asm_80705C00(s16 arg0, s16 arg1, u8 arg2) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s16 sp42;
    s16 temp_f4; // sp40
    s16 temp_v1; // sp3E

    sp42 = func_global_asm_80612794(arg0) * D_global_asm_8075DFB8;
    temp_v1 = func_global_asm_80612790(arg0) * D_global_asm_8075DFC0;
    temp_f4 = arg1 - (8.0 * character_change_array->unk2CA);
    switch (arg2) {
        case 1:
            func_global_asm_80659620(&sp4C, &sp48, &sp44, player_pointer->unk12C);
            if (sp4C > 0.5) {
                func_global_asm_8070033C(sp42, temp_f4, temp_v1, 0.0f, 0.0f, 0.0f, 0.0f, sp4C * 255.0f, sp48 * 255.0f, sp44 * 255.0f);
            }
            break;
        case 0:
            func_global_asm_8070033C(sp42, temp_f4, temp_v1, 0.0f, 0.0f, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF);
            break;
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80705F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807063B8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807065F8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_807069A4.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80706F90.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_8070770C.s")

// Jumptable, 2524 bytes
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_80707980.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1025E0/func_global_asm_8070835C.s")

extern f32 D_global_asm_80754CE8;

void func_global_asm_80708574(f32 arg0) {
    // TODO: Clamp macro?
    if (arg0 < 0.0) {
        arg0 = 0.0f;
    }
    if (arg0 > 1.0) {
        arg0 = 1.0f;
    }
    D_global_asm_80754CE8 = arg0;
}
