#include <ultra64.h>
#include "functions.h"

ALParam *__n_allocParam();
void func_global_asm_8073F1E4(CustomPVoice *, s32, ALParam *);

void func_global_asm_8073B900(ALVoice *arg0, f32 arg1) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = 7;
        sp1C->data.f = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->pvoice, 3, sp1C);
    }
}

void func_global_asm_8073B9B0(ALVoice *arg0, f32 arg1) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = 0x13;
        sp1C->data.f = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->pvoice, 3, sp1C);
    }
}

void func_global_asm_8073BA60(ALVoice *arg0, u8 arg1) {
    ALParam *sp1C;

    if (arg0->pvoice != NULL) {
        sp1C = __n_allocParam();
        if (sp1C == NULL) {
            return;
        }
        sp1C->delta = n_syn->paramSamples + ((CustomPVoice *)arg0->pvoice)->unk88;
        sp1C->type = 0x12;
        sp1C->data.i = arg1;
        sp1C->next = 0;
        func_global_asm_8073F1E4(arg0->pvoice, 3, sp1C);
    }
}

void func_global_asm_8073BB10(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 temp[6];

    if (arg1 >= (arg0 - 200.0f)) {
        arg1 = arg0 - 200.0f;
    }
    sp3C = func_global_asm_80611BB4(arg1 * M_PIF, arg0);
    sp38 = sp3C * sp3C;
    sp34 = (sp3C * 1.414213657f) / arg2;
    arg3[0] = sp38 / (1.0f + sp38 + sp34);
    arg3[1] = arg3[0] * 2.0f;
    arg3[2] = arg3[0];
    arg4[1] = ((sp38 - 1.0f) * 2.0f) / (1.0f + sp38 + sp34);
    arg4[2] = ((1.0f + sp38) - sp34) / (1.0f + sp38 + sp34);
}

void func_global_asm_8073BC74(Struct8073BC74 *arg0) {
    s32 sp14;
    s32 sp10;
    s16 spE;
    f32 sp8;
    f32 sp4;
    f32 sp0;

    sp10 = arg0->unk0 * 16384.0f;
    spE = sp10 >> 0xF;
    arg0->unk2 = 16384.0f - spE;
    arg0->unk28 = 0;
    for (sp14 = 0; sp14 < 8; sp14++) {
        arg0->unk8[sp14] = 0;
    }
    arg0->unk8[sp14] = spE;
    sp14++;
    sp0 = 16384.0f;
    sp4 = sp8 = spE / sp0;
    if (sp14 < 0x10) {
        do {
            sp4 *= sp8;
            arg0->unk8[sp14] = sp4 * sp0;
        } while ((sp14 += 1) < 0x10); // LOL
    }
}

f32 func_global_asm_8073BDC4(s32 arg0) {
    f32 sp4;
    f32 sp0;

    arg0 = arg0;
    sp0 = 1.0f;
    if (arg0 >= 0) {
        sp4 = 1.059463143f;
    } else {
        sp4 = 0.9438742995f;
        arg0 = -arg0;
    }
    while (arg0 != 0) {
        if (arg0 & 1) {
            sp0 *= sp4;
        }
        sp4 *= sp4;
        arg0 = arg0 >> 1;
    }
    return sp0;
}

void func_global_asm_8073BE54(Struct8073BC74 *arg0, f32 arg1) {
    s32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    if (arg0->unk2 == 0) {
        return;
    }
    if (arg0->unk2 < 0xA) {
        arg0->unk2 = 0xA;
    }
    func_global_asm_8073BB10(arg1, arg0->unk0 + 10.0f, arg0->unk2 / 10.0f, &sp30, &sp24);
    for (sp3C = 3; sp3C < 8; sp3C += 1) {
        arg0->unk8[sp3C] = 0;
    }
    arg0->unk8[0] = sp30[0] * (26768.0f - (arg0->unk2 * 128.0f));
    arg0->unkA = sp30[1] * (26768.0f - (arg0->unk2 * 128.0f));
    arg0->unkC = 0;
    arg0->unk18 = sp24[1] * -16384.0f;
    arg0->unk1A = sp24[2] * -16384.0f;
    for (sp3C = 0xA; sp3C < 0x10; sp3C += 1) {
        arg0->unk8[sp3C] = 0;
    }
}

extern s32 *D_global_asm_80756458[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C[4]; // TODO: How many elements?
    s32 unk20[1]; // TODO: How many elements?
} Struct8073C040_arg1;

typedef struct Struct8073C040_SP28_sub20 {
    s16 unk0;
    u8 pad2[0x2C - 2];
    void *unk2C;
    void *unk30;
} Struct8073C040_SP28_sub20;

typedef struct Struct8073C040_SP28_sub24 {
    u8 pad0[0x14];
    void *unk14;
    void *unk18;
    u8 pad1C[0x24 - 0x1C];
    f32 unk24;
    s32 unk28;
} Struct8073C040_SP28_sub24;

typedef struct Struct8073C040_SP28 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u8 padE[2];
    f32 unk10;
    f32 unk14;
    s32 unk18;
    f32 unk1C;
    Struct8073C040_SP28_sub20 *unk20;
    Struct8073C040_SP28_sub24 *unk24;
} Struct8073C040_SP28;

typedef struct Struct8073C040_SP24 {
    u32 unk0;
    Struct8073C040_SP28 *unk4;
    u8 unk8;
    u8 pad9[0x20 - 0x9];
    s16 *unk20;
    s16 *unk24;
    s16 *unk28;
    s16 *unk2C;
} Struct8073C040_SP24;

void func_global_asm_8073C040(Struct8073BC74 **arg0, Struct8073C040_arg1 *arg1, s16 arg2, s32 arg3) {
    // Might (?) be alfxnew
    u16 i, j, k;
    s32 *sp2C;
    Struct8073C040_SP28 *sp28;
    Struct8073C040_SP24 *sp24;

    sp2C = NULL;
    sp24 = alHeapAlloc(arg3, 1U, 0x30);
    *arg0 = sp24;
    switch (arg1->unk1C[arg2]) {
        case 6:
            sp2C = arg1->unk20[arg2];
            break;
        default:
            sp2C = &D_global_asm_80756458;
            break;
    }
    j = 0;
    sp24->unk8 = sp2C[j++];
    sp24->unk0 = sp2C[j++];
    sp24->unk4 = alHeapAlloc(arg3, sp24->unk8, 0x28);
    sp24->unk20 = alHeapAlloc(arg3, sp24->unk0, 2);
    sp24->unk28 = sp24->unk20;
    sp24->unk24 = alHeapAlloc(arg3, sp24->unk0, 2);
    sp24->unk2C = (void *) sp24->unk24;
    for (k = 0; k < sp24->unk0; k++) {
        sp24->unk24[k] = 0;
        sp24->unk20[k] = sp24->unk24[k];
    }
    for (i = 0; i < sp24->unk8; i++) {
        sp28 = &sp24->unk4[i];
        sp28->unk0 = sp2C[j++];
        sp28->unk4 = sp2C[j++];
        sp28->unkA = sp2C[j++];
        sp28->unk8 = sp2C[j++];
        sp28->unkC = sp2C[j++];
        if (sp2C[j]) {
            sp28->unk10 = ((sp2C[j++] / 1000.0f) * 2.0f) / ((ALSynConfig*) arg1)->outputRate;
            sp28->unk1C = (sp2C[j++] / 173123.4f) * (u32)(sp28->unk4 - sp28->unk0);
            sp28->unk14 = 1.0f;
            sp28->unk18 = 0;
            sp28->unk24 = alHeapAlloc(arg3, 1U, 0x38);
            sp28->unk24->unk14 = alHeapAlloc(arg3, 1U, 0x20);
            sp28->unk24->unk18 = alHeapAlloc(arg3, 1U, 0x20);
            sp28->unk24->unk24 = 0.0f;
            sp28->unk24->unk28 = 1;
        } else {
            sp28->unk24 = NULL;
            j++;
            j++;
        }
        if (sp2C[j]) {
            sp28->unk20 = alHeapAlloc(arg3, 1U, 0x38);
            sp28->unk20->unk2C = alHeapAlloc(arg3, 1U, 8);
            sp28->unk20->unk30 = alHeapAlloc(arg3, 1U, 8);
            sp28->unk20->unk0 = (s16) sp2C[j];
            j++;
            func_global_asm_8073BC74(sp28->unk20);
        } else {
            sp28->unk20 = NULL;
            j++;
        }
    }
}

void func_global_asm_8073C604(CustomPVoice *arg0, s32 (*arg1)(CustomResampler *), ALHeap *arg2) {
    arg0->unkC = alHeapAlloc(arg2, 1, 0x20);
    arg0->unk10 = alHeapAlloc(arg2, 1, 0x20);
    arg0->unk28 = arg1(&arg0->resampler);
    arg0->resampler.unk8 = 0;
    arg0->resampler.unkC = 1;
    arg0->resampler.unk10 = 0;
    arg0->resampler.unk14 = alHeapAlloc(arg2, 1, 0x20);
    arg0->resampler.unk20 = 0.0f;
    arg0->resampler.unk24 = 1;
    arg0->resampler.unk18 = 1.0f;
    arg0->resampler.unk1C = 0;
    arg0->resampler.unk28 = alHeapAlloc(arg2, 1, 0x50);
    arg0->unk78 = 1;
    arg0->unk84 = 0;
    arg0->resampler.unk2E = 1;
    arg0->unk68 = 1;
    arg0->unk6E = 1;
    arg0->resampler.unk30 = 1;
    arg0->resampler.unk32 = 1;
    arg0->unk60 = 0;
    arg0->unk62 = 0;
    arg0->unk66 = 1;
    arg0->unk64 = 0;
    arg0->unk66 = 1;
    arg0->unk64 = 0;
    arg0->unk70 = 0;
    arg0->unk74 = 0;
    arg0->resampler.unk2C = 0;
    arg0->unk7C = 0;
    arg0->unk80 = 0;
    arg0->unk8C = 0;
    arg0->unk92 = 0;
    arg0->unk90 = 0;
    arg0->unkBC = alHeapAlloc(arg2, 1, 8);
    arg0->unkB8 = 0;
}

