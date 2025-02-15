#include <ultra64.h>
#include "functions.h"

extern u8 *D_807F5AF0;
extern u16 *D_807FBB54;
extern u8 D_global_asm_80746D5C;
extern Struct807FB7B0 D_807FB7B0[];
extern u16 D_807FBB32;

void func_global_asm_80613BA0(Actor*, s16, f32, f32);
void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_global_asm_80613FB0(Actor*, s32, f32, u8);
void func_global_asm_80614644(Actor*, AnimationStateUnk0*, f32);

void func_global_asm_80613A50(Actor *arg0, s8 arg1) {
    s16 temp1;
    s16 temp2;
    f32 temp3;
    AnimationStateUnk0 *aaS0;
    AnimationStateUnk0 *aaS8;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    aaS0 = aaS->unk0;
    aaS8 = aaS->unk8;
    temp1 = (aaS0->unk18 - aaS0->unk14) + 1.0f;
    temp2 = (aaS8->unk18 - aaS8->unk14) + 1.0f;
    temp3 = (aaS8->unk4 * temp1) / temp2;
    temp3 += arg1;
    func_global_asm_80614644(arg0, aaS0, temp3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80613AF8.s")

extern u16 *D_807FBB58;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80613BA0.s")

void func_global_asm_80613C48(Actor *arg0, s16 arg1, f32 arg2, f32 arg3) {
    AnimationStateUnk0 *temp_v0;

    temp_v0 = arg0->animation_state->unk0;
    if (arg1 == temp_v0->unk10) {
        temp_v0->unk24 = temp_v0->unk0->unk0;
        return;
    }
    func_global_asm_80613CA8(arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80613CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80613FB0.s")

/*
void func_global_asm_80613FB0(Actor *arg0, s32 arg1, f32 arg2, u8 arg3) {
    u16 idx;

    idx = (arg1 * 7) + (arg0->unk58 - 2);
    func_global_asm_80614014(arg0, D_807FBB58[idx], arg2, arg3);
}
*/

typedef struct {
    f32 unk0;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
} Struct80614014;

void func_global_asm_80614014(Actor *arg0, u16 arg1, f32 arg2, u8 arg3) {
    AnimationStateUnk0 *aaS4;
    Struct80614014 *temp_v0;

    aaS4 = arg0->animation_state->unk4;
    if (aaS4->unk0 != NULL) {
        func_global_asm_80613944(arg0, aaS4);
    }
    temp_v0 = func_global_asm_80614130(arg1);
    if (temp_v0 != NULL) {
        aaS4->unk0 = temp_v0;
        aaS4->unk10 = arg1;
        aaS4->unk1C = temp_v0->unk4;
        aaS4->unk14 = 0.0f;
        aaS4->unk18 = temp_v0->unk12 - 1;
        aaS4->unk34 = 0.0f;
        aaS4->unk24 = temp_v0->unk0;
        aaS4->unk2C = temp_v0->unk0;
        aaS4->unk28 = temp_v0->unk0;
        aaS4->unk30 = 0.0f;
        arg0->animation_state->unk28 = 0;
        arg0->animation_state->unk2C = 0xFF;
        arg0->animation_state->unk2E = arg3;
    } else {
        aaS4->unk0 = NULL;
        aaS4->unk10 = -1;
        aaS4->unk1C = 0;
        aaS4->unk14 = 0.0f;
        aaS4->unk34 = 0.0f;
        aaS4->unk24 = 0.0f;
        aaS4->unk2C = 0.0f;
        aaS4->unk28 = 0.0f;
        aaS4->unk30 = 0.0f;
        aaS4->unk18 = 0;
    }
    func_global_asm_80614644(arg0, aaS4, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80614130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_8061421C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80614644.s")

f32 func_global_asm_80614A54(Actor *arg0) {
    return arg0->animation_state->unk0->unk4;
}

s32 func_global_asm_806195D0(f32, f32);

void func_global_asm_80614A64(Actor *arg0) {
    if (arg0->x_position >= -8192.0f) {
        if (arg0->y_position >= -8192.0f) {
            if ((arg0->z_position >= -8192.0f) && (arg0->x_position <= 8192.0f) && (arg0->y_position <= 8192.0f) && (arg0->z_position <= 8192.0f)) {
                arg0->unk8 = arg0->animation_state->bone_arrays[D_global_asm_807444FC];
                func_global_asm_806195D0(arg0->z_position, 8192.0f);
                func_global_asm_80672AFC(arg0);
                arg0->object_properties_bitfield |= 0x200;
            }
        }
    }
}

Gfx *func_global_asm_80614C38(Gfx *, Actor *, ActorModelHeader *);

Gfx *func_global_asm_80614B34(Gfx *dl, Actor *arg1) {
    ActorModelHeader *var_s0;
    s32 var_v1;

    var_s0 = arg1->unk0;
    if (arg1->unk4C != NULL) {
        var_s0 = arg1->unk4C;
    }
    if (arg1->unk50 != NULL) {
        var_s0 = arg1->unk50;
    }
    dl = func_global_asm_80687EE0(dl, arg1);
    dl = func_global_asm_80614C38(dl, arg1, var_s0);
    gSPSegment(dl++, 0x04, osVirtualToPhysical(arg1->unk8));
    gSPSegment(dl++, 0x03, osVirtualToPhysical(var_s0->unk0));
    for (var_v1 = 0; var_v1 < var_s0->unk21; var_v1++) {
        gSPDisplayList(dl++, var_s0->unk4[var_v1]);
    }
    return dl;
}

Gfx *func_global_asm_80614C38(Gfx *dl, Actor *arg1, ActorModelHeader *arg2) {
    u16 hand_state;
    u8 var_v0;
    u8 temp_v1;
    Struct80614C38 *var_s0;
    void* p_addr;

    var_s0 = arg2->unk14;
    hand_state = arg1->unk146;
    while (var_s0) {
        var_v0 = var_s0->unk8 - 7;
        if ((hand_state >> var_v0) & 1) {
            gSPSegment(dl++, var_s0->unk8, osVirtualToPhysical(var_s0->unk0));
        } else {
            gSPSegment(dl++, var_s0->unk8, osVirtualToPhysical(var_s0->unk4));
        }
        var_s0 = var_s0->unkC;
    }
    return dl;
}

void func_global_asm_80614D00(Actor *arg0, f32 arg1, f32 arg2) {
    ActorAnimationState *temp_v0;

    temp_v0 = arg0->animation_state;
    if (arg2 > 0.0f) {
        temp_v0->unk58 = arg2;
        temp_v0->unk50 = arg1;
        temp_v0->unk54 = 0.0f;
        temp_v0->unk4C = temp_v0->unk48;
        return;
    }
    temp_v0->unk48 = arg1;
    temp_v0->unk58 = 0.0f;
}

void func_global_asm_80614D48(Actor *arg0, f32 arg1, f32 arg2) {
    AnimationStateUnk0 *temp_v0;

    temp_v0 = arg0->animation_state->unk0;
    if (arg2 > 0.0f) {
        temp_v0->unk34 = arg2;
        temp_v0->unk2C = arg1;
        temp_v0->unk30 = 0.0f;
        temp_v0->unk28 = (f32) temp_v0->unk24;
        return;
    }
    temp_v0->unk24 = arg1;
    temp_v0->unk34 = 0.0f;
}

extern s32 D_807F5AF4;
extern s32 (*D_global_asm_80746BEC[])(Actor*);

void func_global_asm_80614D90(Actor *arg0) {
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk68 != 0) {
        D_807F5AF4 = 1;
        D_807F5AF0 = aaS->unk6C;
        while ((aaS->unk78 == 0) && (D_807F5AF4 != 0)) {
            D_807F5AF4 = D_global_asm_80746BEC[D_807F5AF0[0]](arg0);
        }
        aaS->unk6C = D_807F5AF0;
        if (aaS->unk70 != NULL) {
            D_807F5AF0 = aaS->unk74;
            aaS->unk70(arg0);
        }
    }
}

void playAnimation(Actor *arg0, s32 arg1) {
    s32 offset = (arg1 * 7) + (arg0->unk58 - 2);
    playActorAnimation(arg0, D_807FBB54[offset]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/playActorAnimation.s")

/*
extern s32 D_807FBB50[];

void playActorAnimation(Actor *arg0, s32 arg1) {
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    aaS->unk70 = 0;
    aaS->unk78 = 0;
    aaS->unk7C = 0;
    aaS->unk80 = 0;
    aaS->unk88 = 0;
    if (arg1 == 0) {
        aaS->unk68 = 0;
        D_807F5AF0 = 0;
        D_807F5AF4 = 0;
    } else {
        aaS->unk64 = arg1;
        aaS->unk68 = D_807FBB50[arg1] + D_807F5AF0;
        aaS->unk6C = aaS->unk68;
        D_807F5AF0 = aaS->unk68;
    }
}
*/

void getAnimationArg8(u8 *arg0) {
    *arg0 = *D_807F5AF0++;
}

void getAnimationArg16(s16 *arg0) {
    ((u8*)arg0)++;
    ((u8*)arg0)[-1] = *D_807F5AF0++;
    ((u8*)arg0)[0] = *D_807F5AF0++;
}

void getAnimationArg24(s32 *arg0) {
    ((u8*)arg0) += 2;
    ((u8*)arg0)[-2] = *D_807F5AF0++;
    ((u8*)arg0)[-1] = *D_807F5AF0++;
    ((u8*)arg0)[0] = *D_807F5AF0++;
}

void getAnimationArg32(s32 *arg0) {
    ((u8*)arg0) += 3;
    ((u8*)arg0)[-3] = *D_807F5AF0++;
    ((u8*)arg0)[-2] = *D_807F5AF0++;
    ((u8*)arg0)[-1] = *D_807F5AF0++;
    ((u8*)arg0)[0] = *D_807F5AF0++;
}

s32 func_global_asm_8061503C(Actor *arg0) {
    D_807F5AF0++;
    return 1;
}

s32 func_global_asm_8061505C(Actor *arg0) {
    D_807F5AF0++;
    return 0;
}

s32 func_global_asm_8061507C(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    arg0->animation_state->unk88 = sp1E;
    return 1;
}

s32 func_global_asm_806150C8(Actor *arg0) {
    s32 temp_v1;
    ActorAnimationState *AAS;

    AAS = arg0->animation_state;
    if (AAS->unk88) {
        AAS->unk88--;
    }
    D_807F5AF0++;
    return 1;
}

s32 func_global_asm_806150F8(Actor *arg0) {
    s32 temp_a1;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk88) {
        aaS->unk88--;
        return 0;
    }
    D_807F5AF0++;
    return 1;
}

s32 func_global_asm_80615134(Actor *arg0) {
    ActorAnimationState *aaS;
    AnimationStateUnk0 *var_v1;

    aaS = arg0->animation_state;
    var_v1 = aaS->unk84 ? aaS->unk4 : aaS->unk0;
    D_807F5AF0++;
    if ((var_v1->unk24 != 0.0f) || ((var_v1->unk2C != 0.0f) && (var_v1->unk34 != 0.0f))) {
        aaS = arg0->animation_state;
        aaS->unk78 |= 1;
    }
    return 0;
}

s32 func_global_asm_806151BC(Actor *arg0) {
    u8 sp1F;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    if (sp1F) {
        arg0->animation_state->unk7C = sp1F - 1;
        arg0->animation_state->unk78 |= 2;
        return 0;
    }
    return 1;
}

s32 func_global_asm_8061522C(Actor *arg0) {
    u8 random;
    u8 sp1E;
    u8 sp1D;

    D_807F5AF0++;
    getAnimationArg8(&sp1E);
    getAnimationArg8(&sp1D);
    random = (RandClamp(32767) % ((sp1D - sp1E) + 1)) + sp1E;
    if (random) {
        arg0->animation_state->unk7C = random - 1;
        arg0->animation_state->unk78 |= 2;
        return 0;
    }
    return 1;
}

s32 func_global_asm_806152FC(Actor *arg0) {
    D_807F5AF0++;
    arg0->animation_state->unk78 |= 4;
    return 0;
}

s32 func_global_asm_80615328(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    arg0->animation_state->unk78 |= sp1E;
    return 0;
}

s32 func_global_asm_8061537C(Actor *arg0) {
    f32 sp1C;

    D_807F5AF0++;
    getAnimationArg32(&sp1C);
    if (sp1C < 0.0f) {
        sp1C = arg0->animation_state->unk88;
    }
    arg0->animation_state->unk80 = sp1C;
    arg0->animation_state->unk78 |= 8;
    return 0;
}

s32 func_global_asm_8061540C(Actor *arg0) {
    f32 sp24;
    AnimationStateUnk0 *var_v0;

    if (arg0->animation_state->unk84 != 0) {
        var_v0 = arg0->animation_state->unk4;
    } else {
        var_v0 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg32(&sp24);
    if (sp24 < 0.0f) {
        sp24 = arg0->animation_state->unk88;
    }
    if ((arg0->animation_state->unk48 * var_v0->unk24) > 0.0f) {
        if (sp24 <= var_v0->unk4) {
            return 1;
        }
        goto block_10;
    }
    if (var_v0->unk4 <= sp24) {
        return 1;
    }
block_10:
    arg0->animation_state->unk80 = sp24;
    arg0->animation_state->unk78 |= 8;
    return 0;
}

s32 func_global_asm_8061551C(Actor *arg0) {
    D_807F5AF0++;
    if (arg0->animation_state->unk8->unk0 != 0) {
        arg0->animation_state->unk78 |= 0x10;
    }
    return 0;
}

s32 func_global_asm_80615558(Actor *arg0) {
    f32 sp1C;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    D_807F5AF0++;
    getAnimationArg32(&sp1C);
    if (aaS->unk8->unk0) {
        if (sp1C < aaS->unk44) {
            aaS->unk44 = sp1C;
            aaS->unk40 = (aaS->unk44 - (aaS->unk10 * aaS->unk44));
        }
        arg0->animation_state->unk78 |= 0x10;
    }
    return 0;
}

s32 func_global_asm_806155F4(Actor *arg0) {
    if (arg0->animation_state->unk88 != 0) {
        D_807F5AF0++;
        return 1;
    }
    return 0;
}

s32 func_global_asm_8061562C(Actor *arg0) {
    if (arg0->animation_state->unk88 == 0) {
        D_807F5AF0++;
        return 1;
    }
    return 0;
}

s32 func_global_asm_80615664(Actor *arg0) {
    if (arg0->animation_state->unk4->unk0 == 0) {
        D_807F5AF0++;
        return 1;
    }
    return 0;
}

s32 func_global_asm_806156A0(Actor *arg0) {
    if (arg0->animation_state->unk28 == arg0->animation_state->unk2C) {
        D_807F5AF0++;
        return 1;
    }
    return 0;
}

s32 func_global_asm_806156DC(Actor *arg0) {
    f32 sp24;
    AnimationStateUnk0 *var_v1;

    if (arg0->animation_state->unk84 != 0) {
        var_v1 = arg0->animation_state->unk4;
    } else {
        var_v1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg32(&sp24);
    if (sp24 < var_v1->unk0->unk12) {
        var_v1->unk14 = sp24;
    }
    return 1;
}

s32 func_global_asm_80615774(Actor *arg0) {
    f32 sp24;
    AnimationStateUnk0 *var_v1;

    if (arg0->animation_state->unk84 != 0) {
        var_v1 = arg0->animation_state->unk4;
    } else {
        var_v1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg32(&sp24);
    if (sp24 < var_v1->unk0->unk12) {
        var_v1->unk18 = sp24;
    }
    return 1;
}

s32 func_global_asm_8061580C(Actor *arg0) {
    f32 sp24;
    f32 sp20;
    AnimationStateUnk0 *var_v1;

    if (arg0->animation_state->unk84 != 0) {
        var_v1 = arg0->animation_state->unk4;
    } else {
        var_v1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg32(&sp24);
    getAnimationArg32(&sp20);
    if (sp24 < var_v1->unk0->unk12) {
        var_v1->unk14 = sp24;
    }
    if (sp20 < var_v1->unk0->unk12) {
        var_v1->unk18 = sp20;
    }
    return 1;
}

s32 func_global_asm_806158E8(Actor *arg0) {
    AnimationStateUnk0_0 *temp_a0;
    AnimationStateUnk0 *var_v1;

    if (arg0->animation_state->unk84 != 0) {
        var_v1 = arg0->animation_state->unk4;
    } else {
        var_v1 = arg0->animation_state->unk0;
    }
    temp_a0 = var_v1->unk0;
    D_807F5AF0++;
    var_v1->unk14 = 0.0f;
    var_v1->unk18 = temp_a0->unk12 - 1;
    var_v1->unk1C = temp_a0->unk4;
    return 1;
}

s32 func_global_asm_8061594C(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    func_global_asm_80613C48(arg0, sp1E, 0.0f, 1.0f);
    return 1;
}

s32 func_global_asm_8061599C(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    func_global_asm_80613BA0(arg0, sp1E, 0, 1.0f);
    return 1;
}

s32 func_global_asm_806159EC(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    func_global_asm_80613CA8(arg0, sp1E, 0, 0.0f);
    return 1;
}

s32 func_global_asm_80615A3C(Actor *arg0) {
    s16 sp1E;
    f32 sp18;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    getAnimationArg32(&sp18);
    func_global_asm_80613C48(arg0, sp1E, 0.0f, sp18);
    return 1;
}

s32 func_global_asm_80615A94(Actor *arg0) {
    s8 sp1F;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    func_global_asm_80613A50(arg0, sp1F);
    return 1;
}

s32 func_global_asm_80615ADC(Actor *arg0) {
    u16 sp1E;
    u8 sp1D;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    getAnimationArg8(&sp1D);
    func_global_asm_80614014(arg0, sp1E, 0.0f, sp1D);
    return 1;
}

s32 func_global_asm_80615B34(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    func_global_asm_80613AF8(arg0, sp1E, 0.0f, 1.0f);
    return 1;
}

s32 func_global_asm_80615B84(Actor *arg0) {
    s16 sp1E;
    f32 sp18;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    getAnimationArg32(&sp18);
    func_global_asm_80613AF8(arg0, sp1E, 0.0f, sp18);
    return 1;
}

s32 func_global_asm_80615BDC(Actor *arg0) {
    u16 sp1E;
    u8 sp1D;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    getAnimationArg8(&sp1D);
    func_global_asm_80613FB0(arg0, sp1E, 0, sp1D);
    return 1;
}

s32 func_global_asm_80615C34(Actor *arg0) {
    u8 sp27;
    AnimationStateUnk0 *var_a1;

    if (arg0->animation_state->unk84) {
        var_a1 = arg0->animation_state->unk4;
    } else {
        var_a1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg8(&sp27);
    if (sp27 == 0xFF) {
        sp27 = arg0->animation_state->unk88;
    }
    func_global_asm_80614644(arg0, var_a1, sp27);
    return 1;
}

s32 func_global_asm_80615CE4(Actor *arg0) {
    u8 sp27;
    AnimationStateUnk0 *var_a1;

    if (arg0->animation_state->unk84 != 0) {
        var_a1 = arg0->animation_state->unk4;
    } else {
        var_a1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg8(&sp27);
    func_global_asm_80614644(arg0, var_a1, D_global_asm_80746D5C);
    if (D_global_asm_80746D5C != 0) {
        D_global_asm_80746D5C += sp27;
    } else {
        D_global_asm_80746D5C = 0;
    }
    return 1;
}

s32 func_global_asm_80615DA4(Actor *arg0) {
    u8 sp27;
    AnimationStateUnk0 *sp20;

    if (arg0->animation_state->unk84 != 0) {
        sp20 = arg0->animation_state->unk4;
    } else {
        sp20 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg8(&sp27);
    sp20->unk1E = sp20->unkC;
    sp20->unk20 = sp27;
    sp20->unk1C |= 8;
    if (sp20->unkC < sp20->unk4) {
        sp20->unk8 = sp20->unk4 - sp20->unkC;
    } else {
        sp20->unk8 = -(sp20->unk4 - sp20->unkC);
    }
    sp20->unkE = sp27;
    arg0->animation_state->unk78 |= 0x20;
    return 1;
}

s32 func_global_asm_80615E74(Actor *arg0) {
    u8 sp2F;
    u8 sp2E;
    AnimationStateUnk0 *sp28;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk84 != 0) {
        sp28 = aaS->unk4;
    } else {
        sp28 = aaS->unk0;
    }
    D_807F5AF0++;
    getAnimationArg8(&sp2F);
    getAnimationArg8(&sp2E);
    if (sp28->unkC == sp2F) {
        sp28->unk1E = sp28->unkC;
        sp28->unk20 = sp2E;
        sp28->unk1C |= 8;
        if (sp28->unkC < sp28->unk4) {
            sp28->unk8 = sp28->unk4 - sp28->unkC;
        } else {
            sp28->unk8 = -(sp28->unk4 - sp28->unkC);
        }
        sp28->unkE = sp2E;
        arg0->animation_state->unk78 |= 0x20;
    } else {
        sp28->unkC = (sp28->unkC + sp2E) - sp2F;
        sp28->unkE = (sp28->unkE + sp2E) - sp2F;
        sp28->unk4 = sp28->unk4 + (sp2E - sp2F);
    }
    return 1;
}

s32 func_global_asm_80615FA0(Actor *arg0) {
    s16 sp26;
    AnimationStateUnk0 *var_v1;

    if (arg0->animation_state->unk84 != 0) {
        var_v1 = arg0->animation_state->unk4;
    } else {
        var_v1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg16(&sp26);
    var_v1->unk1C |= sp26;
    return 1;
}

s32 func_global_asm_8061600C(Actor *arg0) {
    s16 sp26;
    AnimationStateUnk0 *var_v1;

    if (arg0->animation_state->unk84 != 0) {
        var_v1 = arg0->animation_state->unk4;
    } else {
        var_v1 = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg16(&sp26);
    var_v1->unk1C &= ~sp26;
    return 1;
}

s32 func_global_asm_8061607C(Actor *arg0) {
    f32 var_f0;
    f32 sp20;
    AnimationStateUnk0 *sp1C;

    if (arg0->animation_state->unk84 != 0) {
        sp1C = arg0->animation_state->unk4;
    } else {
        sp1C = arg0->animation_state->unk0;
    }
    D_807F5AF0++;
    getAnimationArg32(&sp20);
    if (sp1C->unk0 != NULL) {
        var_f0 = sp1C->unk0->unk0;
    } else {
        var_f0 = 0;
    }
    if (sp20 > 0.0f) {
        sp1C->unk34 = sp20;
        sp1C->unk2C = var_f0;
        sp1C->unk30 = 0.0f;
        sp1C->unk28 = sp1C->unk24;
    } else {
        sp1C->unk24 = var_f0;
        sp1C->unk34 = 0.0f;
    }
    return 1;
}

s32 func_global_asm_8061612C(Actor *arg0) {
    f32 sp24;
    f32 sp20;
    AnimationStateUnk0 *sp1C;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk84 != 0) {
        sp1C = aaS->unk4;
    } else {
        sp1C = aaS->unk0;
    }
    D_807F5AF0++;
    getAnimationArg32(&sp24);
    getAnimationArg32(&sp20);
    if (sp20 > 0.0f) {
        sp1C->unk34 = sp20;
        sp1C->unk2C = sp24;
        sp1C->unk30 = 0.0f;
        sp1C->unk28 = sp1C->unk24;
    } else {
        sp1C->unk24 = sp24;
        sp1C->unk34 = 0.0f;
    }
    return 1;
}

s32 func_global_asm_806161D0(Actor *arg0) {
    ActorAnimationState *aaS;
    AnimationStateUnk0 *var_v1;

    aaS = arg0->animation_state;
    if (aaS->unk84 != 0) {
        var_v1 = aaS->unk4;
    } else {
        var_v1 = aaS->unk0;
    }
    D_807F5AF0++;
    if (var_v1->unk24 < 0) {
        var_v1->unk24 = 0 - var_v1->unk24;
        if (var_v1->unk34 != 0.0f) {
            var_v1->unk2C = 0 - var_v1->unk2C;
            var_v1->unk28 = 0 - var_v1->unk28;
        }
    }
    return 1;
}

s32 func_global_asm_80616254(Actor *arg0) {
    ActorAnimationState *aaS;
    AnimationStateUnk0 *var_v1;

    aaS = arg0->animation_state;
    if (aaS->unk84 != 0) {
        var_v1 = aaS->unk4;
    } else {
        var_v1 = aaS->unk0;
    }
    D_807F5AF0++;
    var_v1->unk24 = 0 - var_v1->unk24;
    if (var_v1->unk34 != 0.0f) {
        var_v1->unk2C = 0 - var_v1->unk2C;
        var_v1->unk28 = 0 - var_v1->unk28;
    }
    return 1;
}

s32 func_global_asm_806162C4(Actor *arg0) {
    f32 sp1C;
    f32 sp18;

    D_807F5AF0++;
    getAnimationArg32(&sp1C);
    getAnimationArg32(&sp18);
    func_global_asm_80614D00(arg0, sp1C, sp18);
    return 1;
}

s32 func_global_asm_80616318(Actor *arg0) {
    u16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    playAnimation(arg0, sp1E);
    D_807F5AF0 = arg0->animation_state->unk6C;
    return D_807F5AF4;
}

s32 func_global_asm_80616374(Actor *arg0) {
    u16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    playActorAnimation(arg0, sp1E);
    D_807F5AF0 = arg0->animation_state->unk6C;
    return D_807F5AF4;
}

s32 func_global_asm_806163D0(Actor *arg0) {
    arg0->animation_state->unk78 |= 0x8000;
    return 0;
}

s32 func_global_asm_806163E8(Actor *arg0) {
    f32 sp24;
    AnimationStateUnk0 *sp20;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk84 != 0) {
        sp20 = aaS->unk4;
    } else {
        sp20 = aaS->unk0;
    }
    sp20 = sp20;
    D_807F5AF0++;
    getAnimationArg32(&sp24);
    arg0->animation_state->unk88 = sp20->unk4 - sp24;
    return 1;
}

s32 func_global_asm_80616470(Actor *arg0) {
    u16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    arg0->animation_state->unk88 = arg0->control_state - sp1E;
    return 1;
}

s32 func_global_asm_806164C4(Actor *arg0) {
    u16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    arg0->animation_state->unk88 = arg0->control_state_progress - sp1E;
    return 1;
}

s32 func_global_asm_80616518(Actor *arg0) {
    u16 sp26;
    AnimationStateUnk0 *sp20;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk84 != 0) {
        sp20 = aaS->unk4;
    } else {
        sp20 = aaS->unk0;
    }
    D_807F5AF0++;
    getAnimationArg16(&sp26);
    arg0->animation_state->unk88 = sp20->unk10 - sp26;
    return 1;
}

s32 func_global_asm_80616594(Actor *arg0) {
    u16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    arg0->animation_state->unk88 = extra_player_info_pointer->unk4E - sp1E;
    return 1;
}

s32 func_global_asm_806165F0(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    D_807F5AF0 = arg0->animation_state->unk68 + sp1E;
    return 1;
}

s32 func_global_asm_80616644(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    if (arg0->animation_state->unk88 != 0) {
        D_807F5AF0 = arg0->animation_state->unk68 + sp1E;
    }
    return 1;
}

s32 func_global_asm_806166A8(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    if (arg0->animation_state->unk88 == 0) {
        D_807F5AF0 = arg0->animation_state->unk68 + sp1E;
    }
    return 1;
}

s32 func_global_asm_8061670C(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    if (arg0->animation_state->unk88 > 0) {
        D_807F5AF0 = arg0->animation_state->unk68 + sp1E;
    }
    return 1;
}

s32 func_global_asm_80616770(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    if (arg0->animation_state->unk88 < 0) {
        D_807F5AF0 = arg0->animation_state->unk68 + sp1E;
    }
    return 1;
}

s32 func_global_asm_806167D4(Actor *arg0) {
    D_807F5AF0 = arg0->animation_state->unk68;
    return 1;
}

s32 func_global_asm_806167EC(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0 += (arg0->animation_state->unk88 * 2) + 1;
    getAnimationArg16(&sp1E);
    D_807F5AF0 = arg0->animation_state->unk68 + sp1E;
    return 1;
}

s32 func_global_asm_80616850(Actor *arg0) {
    s32 sp24;
    u16 sp22;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    sp24 = arg0->animation_state->unk88;
    D_807F5AF0++;
    getAnimationArg16(&sp22);
    aaS->unk5C = aaS->unk64;
    aaS->unk60 = D_807F5AF0 - aaS->unk68;
    playActorAnimation(arg0, sp22);
    D_807F5AF0 = aaS->unk6C;
    aaS->unk88 = sp24;
    return D_807F5AF4;
}

s32 func_global_asm_806168E4(Actor *arg0) {
    u16 sp1E;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    aaS->unk5C = aaS->unk64;
    aaS->unk60 = D_807F5AF0 - aaS->unk68;
    playAnimation(arg0, sp1E);
    D_807F5AF0 = aaS->unk6C;
    return D_807F5AF4;
}

s32 func_global_asm_80616964(Actor *arg0) {
    s32 sp1C;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    sp1C = arg0->animation_state->unk88;
    playActorAnimation(arg0, aaS->unk5C);
    D_807F5AF0 = aaS->unk68 + aaS->unk60;
    aaS->unk5C = 0;
    aaS->unk60 = 0;
    aaS->unk88 = sp1C;
    return 1;
}

extern s32 (*D_global_asm_80746D64[])(Actor *arg0);

s32 func_global_asm_806169C0(Actor *arg0) {
    s16 sp1E;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    D_global_asm_80746D64[sp1E](arg0);
    return D_807F5AF4;
}

s32 func_global_asm_80616A1C(Actor *arg0) {
    s16 sp1E;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    aaS->unk70 = D_global_asm_80746D64[sp1E];
    aaS->unk74 = D_807F5AF0;
    if (sp1E != 0) {
        aaS->unk70(arg0);
    }
    return D_807F5AF4;
}

s32 func_global_asm_80616A9C(Actor *arg0) {
    s16 sp26;
    u8 sp25;
    s16 sp22;
    u8 sp21;
    u8 sp20;

    D_807F5AF0++;
    getAnimationArg16(&sp26);
    getAnimationArg8(&sp25);
    getAnimationArg8(&sp20);
    getAnimationArg16(&sp22);
    getAnimationArg8(&sp21);
    playSound(sp26, (s32)((sp25 * 32767.0) / 255.0), sp20, sp22 / 127.0, sp21, 0);
    return 1;
}

s32 func_global_asm_80616BA4(Actor *arg0) {
    u8 controlState;

    D_807F5AF0++;
    getAnimationArg8(&controlState);
    arg0->control_state = controlState;
    arg0->control_state_progress = 0;
    return 1;
}

s32 func_global_asm_80616BF0(Actor *arg0) {
    D_807F5AF0++;
    arg0->control_state_progress = 0;
    arg0->control_state++;
    return 1;
}

s32 func_global_asm_80616C1C(Actor *arg0) {
    u8 controlStateProgress;

    D_807F5AF0++;
    getAnimationArg8(&controlStateProgress);
    arg0->control_state_progress = controlStateProgress;
    return 1;
}

s32 func_global_asm_80616C64(Actor *arg0) {
    D_807F5AF0++;
    arg0->control_state_progress++;
    return 1;
}

s32 func_global_asm_80616C8C(Actor *arg0) {
    D_807F5AF0++;
    arg0->unk11C->control_state_progress++;
    return 1;
}

s32 func_global_asm_80616CB8(Actor *arg0) {
    u8 sp1F;
    u8 sp1E;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    getAnimationArg8(&sp1E);
    arg0->animation_state->unk88 = (RandClamp(32767) % ((sp1E - sp1F) + 1)) + sp1F;
    return 1;
}

s32 func_global_asm_80616D5C(Actor *arg0) {
    D_807F5AF0++;
    arg0->animation_state->unk84 = 1;
    return 1;
}

s32 func_global_asm_80616D84(Actor *arg0) {
    D_807F5AF0++;
    arg0->animation_state->unk84 = 0;
    return 1;
}

s32 func_global_asm_80616DA8(Actor *arg0) {
    return 0;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
} A17C_80616DB4;

s32 func_global_asm_80616DB4(Actor *arg0) {
    A17C_80616DB4 *a17C;
    u8 sp1B;

    a17C = arg0->unk17C;
    D_807F5AF0++;
    getAnimationArg8(&sp1B);
    a17C->unkD |= sp1B;
    return 1;
}

// jumptable, rodata, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80616E08.s")

/*
s32 func_global_asm_80616E08(Actor *arg0) {
    s16 sp4E;
    u8 sp4D;
    s16 sp4A;
    u8 sp49;
    u8 var_v1;
    u8 pad;

    D_807F5AF0++;
    getAnimationArg16(&sp4E);
    getAnimationArg8(&sp4D);
    getAnimationArg16(&sp4A);
    getAnimationArg8(&sp49);
    if (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 2) {
        if (sp4E == 1) {
            sp4D *= 0.5;
        }
        var_v1 = 0xA;
        func_global_asm_8061EF4C(extra_player_info_pointer->unk104, var_v1, 8U, arg0->x_position, arg0->y_position, arg0->z_position, 100.0f, 800.0f);
    } else if (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 0) {
        var_v1 = 0xFF;
        sp4D *= 0.5;
    } else {
        switch (arg0->unk58) {
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
            var_v1 = 0x46;
            break;
        case ACTOR_RAMBI:
            var_v1 = 0x5A;
            break;
        case ACTOR_DK:
        case ACTOR_LANKY:
            var_v1 = 0x32;
            break;
        default:
            var_v1 = 0x50;
            break;
        }
    }
    sp4E = func_global_asm_8060A7C0(sp4E, arg0, arg0->unk78);
    if ((sp4E == 2) || (sp4E == 8)) {
        sp49 = 0xA;
    }
    playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, sp4E, (u8) (s32) sp4D, (s16) (s32) sp4A, (u8) (s32) sp49, (u8) (s32) var_v1, 0.3f, 0U);
    return 1;
}
*/

extern s32 D_global_asm_807457C8;
extern f64 D_global_asm_807573A8;
void func_global_asm_80737924(s32);


s32 func_global_asm_80617140(Actor *arg0) {
    s16 sp2E;
    s16 unkC;
    u8 sp2B;
    u8 sp2A;
    u8 sp29;
    s16 temp_v0;

    D_807F5AF0++;
    getAnimationArg16(&sp2E);
    getAnimationArg8(&sp2B);
    getAnimationArg8(&sp2A);
    getAnimationArg8(&sp29);
    if (D_global_asm_807457C8 != 0) {
        func_global_asm_80737924(D_global_asm_807457C8);
        D_global_asm_807457C8 = 0;
    }
    temp_v0 = func_global_asm_8060A7C0(sp2E, arg0, arg0->unk78);
    if (temp_v0 == 8) {
        sp29 = 4;
    }
    func_global_asm_8060866C(arg0, temp_v0, sp2B, sp2A / 127.0, sp29, 0x4B);
    return 1;
}

s32 func_global_asm_80617238(Actor *arg0) {
    s16 sp3E;
    u8 sp3D;
    u8 var_v0;
    u8 sp3B;

    sp3B = 0xFF;
    D_807F5AF0++;
    getAnimationArg16(&sp3E);
    getAnimationArg8(&sp3D);
    if (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 2) {
        var_v0 = 0xA;
    } else if (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 0) {
        var_v0 = 0xFF;
        sp3B = var_v0 * 0.5;
    } else {
        switch (arg0->unk58) {
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
        case ACTOR_RAMBI:
            var_v0 = 0x5A;
            break;
        case ACTOR_DK:
        case ACTOR_LANKY:
            var_v0 = 0x32;
            break;
        default:
            var_v0 = 0x50;
            break;
        }
    }
    playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, sp3E, (u8) (s32) sp3B, 0x7F, (u8) (s32) sp3D, (u8) var_v0, 0.3f, 0U);
    return 1;
}

s32 func_global_asm_80617400(Actor *arg0) {
    s16 sp36;
    u8 sp35;
    u8 sp34;
    u8 sp33;
    u8 sp32;

    D_807F5AF0++;
    getAnimationArg16(&sp36);
    getAnimationArg8(&sp33);
    getAnimationArg8(&sp32);
    getAnimationArg8(&sp35);
    getAnimationArg8(&sp34);
    if (arg0->object_properties_bitfield & 4) {
        playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, sp36, sp33, sp32, sp35, sp34, 0.3f, 0);
    }
    return 1;
}

s32 func_global_asm_806174B4(Actor *arg0) {
    f32 x;
    f32 y;
    f32 z;
    s16 sp4A;
    u8 sp49;
    s32 pad;
    u8 sp43;
    u8 boneIndex;
    u8 sp41;
    u8 sp40;
    u8 sp3F;
    f32 sp38;

    D_807F5AF0++;
    getAnimationArg16(&sp4A);
    getAnimationArg8(&sp40);
    getAnimationArg8(&sp3F);
    getAnimationArg8(&sp49);
    getAnimationArg8(&sp43);
    getAnimationArg32(&sp38);
    getAnimationArg8(&boneIndex);
    getAnimationArg8(&sp41);
    if (arg0->object_properties_bitfield & 4) {
        if (boneIndex) {
            getBonePosition(arg0, boneIndex, &x, &y, &z);
        } else {
            x = arg0->x_position;
            y = arg0->y_position;
            z = arg0->z_position;
        }
        playSoundAtPosition(x, y, z, sp4A, sp40, sp3F, sp49, sp43, sp38, sp41);
    }
    return 1;
}

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_806175C4.s")

/*
s32 func_global_asm_806175C4(Actor *arg0) {
    s16 sp46;
    u8 sp45;
    u8 sp44;
    u8 sp43;
    u8 sp42;
    f32 var_f2;

    D_807F5AF0++;
    getAnimationArg16(&sp46);
    getAnimationArg8(&sp43);
    getAnimationArg8(&sp42);
    getAnimationArg8(&sp45);
    getAnimationArg8(&sp44);
    var_f2 = MIN(((((arg0->animation_state->scale_x / 0.4381361) * 200.0) + 55.0) * sp43) / 255.0, 255.0);
    playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, sp46, var_f2, sp42, sp45, sp44, 0.3f, 0);
    return 1;
}
*/

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_18750/func_global_asm_80617770.s")

void func_global_asm_80609B80(f32, f32, s16, s32, s16, s32, s32, s32, s32, f32); /* extern */
extern s16 *D_807FBB5C;

/*
void func_global_asm_80617770(Actor *arg0, u32 arg1, u8 arg2) {
    u8 var_v0;
    u8 var_v1;
    u16 slot;

    slot = ((s32)(arg1 * 7) + arg0->unk58) - 2;
    var_v1 = 0xFF;
    if (D_807FBB5C[slot] == 0) {
        if (extra_player_info_pointer->unkC4) {
            var_v1 = 0xFF;
            func_global_asm_80737924(extra_player_info_pointer->unkC4);
        }
    }
    if (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 2) {
        var_v0 = 0xA;
    } else if (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 0) {
        var_v0 = 0x50;
        var_v1 *= 0.5;
    } else {
        if ((arg0->unk58 == ACTOR_DK) || (arg0->unk58 == ACTOR_LANKY)) {
            var_v0 = 0x32;
        } else {
            var_v0 = 0x3C;
        }
    }
    func_global_asm_80609B80(arg0->x_position, arg0->y_position, D_807FBB5C[slot], arg0->z_position, D_807FBB5C[slot], var_v1, 0x7F, (s32) arg2, var_v0, 0.3f);
}
*/


s32 func_global_asm_8061796C(Actor *arg0) {
    s16 sp1E;
    u8 sp1D;

    D_807F5AF0++;
    getAnimationArg16(&sp1E);
    getAnimationArg8(&sp1D);
    func_global_asm_80617770(arg0, sp1E, sp1D);
    return 1;
}

s32 func_global_asm_806179C0(Actor *arg0) {
    s16 sp2E;
    u8 sp2D;
    u8 sp2C;
    u8 sp2B;
    s8 sp2A;

    D_807F5AF0++;
    getAnimationArg16(&sp2E);
    getAnimationArg8(&sp2D);
    getAnimationArg8(&sp2B);
    getAnimationArg8(&sp2C);
    getAnimationArg8(&sp2A);
    func_global_asm_80605314(arg0, sp2D);
    func_global_asm_80604CBC(arg0, sp2E, sp2C, 1, sp2D, sp2B, 1.0f, sp2A);
    return 1;
}

s32 func_global_asm_80617A60(Actor *arg0) {
    f32 sp1C;
    u8 sp1B;
    u8 sp1A;

    D_807F5AF0++;
    getAnimationArg8(&sp1A);
    getAnimationArg32(&sp1C);
    getAnimationArg8(&sp1B);
    func_global_asm_80604BE8(arg0->unk6E[sp1A], sp1C, sp1B);
    return 1;
}

s32 func_global_asm_80617AF0(Actor *arg0) {
    u8 sp1F;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    func_global_asm_80605314(arg0, sp1F);
    return 1;
}

s32 func_global_asm_80617B38(Actor *arg0) {
    s16 sp2E;
    u8 sp2D;
    u8 sp2C;
    s8 sp2B;

    D_807F5AF0++;
    getAnimationArg16(&sp2E);
    getAnimationArg8(&sp2D);
    getAnimationArg8(&sp2C);
    getAnimationArg8(&sp2B);
    func_global_asm_80604CBC(arg0, sp2E, sp2C, 1, sp2D, 0xFF, 1.0f, sp2B);
    arg0->unk72 = arg0->animation_state->unk0->unk10;
    return 1;
}

extern u8 D_global_asm_80746D60[];

s32 func_global_asm_80617BD8(Actor *arg0) {
    u8 sp1F;
    u8 sp1E;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    getAnimationArg8(&sp1E);
    playSong(D_global_asm_80746D60[sp1F], sp1E / 255.0);
    return 1;
}

s32 func_global_asm_80617C6C(Actor *arg0) {
    u8 sp1F;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    func_global_asm_80602B60(D_global_asm_80746D60[sp1F], 0);
    return 1;
}

s32 func_global_asm_80617CC0(Actor *arg0) {
    u16 fileIndex;
    u8 textIndex;

    D_807F5AF0++;
    getAnimationArg16(&fileIndex);
    getAnimationArg8(&textIndex);
    loadText(arg0, fileIndex, textIndex);
    return 1;
}

s32 func_global_asm_80617D14(Actor *arg0) {
    return 1;
}

void func_global_asm_80617D20(Actor *arg0) {
    ActorAnimationState *temp_v0;
    AnimationStateUnk0 *var_v1;

    temp_v0 = arg0->animation_state;
    if (temp_v0->unk84 != 0) {
        var_v1 = temp_v0->unk4;
    } else {
        var_v1 = temp_v0->unk0;
    }
    func_global_asm_80617DFC(arg0, var_v1->unk4);
}

void func_global_asm_80617D70(Actor *arg0) {
    func_global_asm_80617DFC(arg0, arg0->animation_state->unk88);
}

void func_global_asm_80617D94(s32 arg0) {
    u8 sp27;

    getAnimationArg8(&sp27);
    while (sp27) {
        D_807F5AF0 += 4;
        getAnimationArg8(&sp27);
    }
}

s32 func_global_asm_80617DFC(Actor *arg0, s16 arg1) {
    u8 sp2F;
    s16 sp2C;
    s16 sp2A;

    D_807F5AF0 += 1;
    while (TRUE) {
        getAnimationArg8(&sp2F);
        getAnimationArg16(&sp2C);
        switch (sp2F) {
        case 0:
            D_807F5AF0 -= 2;
            return 1;
        case 1:
            if (arg1 == sp2C) {
                getAnimationArg16(&sp2A);
                D_807F5AF0 = arg0->animation_state->unk68 + sp2A;
                return 1;
            }
            break;
        case 2:
            if (arg1 < sp2C) {
                getAnimationArg16(&sp2A);
                D_807F5AF0 = arg0->animation_state->unk68 + sp2A;
                return 1;
            }
            break;
        case 3:
            if (sp2C < arg1) {
                getAnimationArg16(&sp2A);
                D_807F5AF0 = arg0->animation_state->unk68 + sp2A;
                return 1;
            }
            break;
        case 4:
            if (arg1 == sp2C) {
                getAnimationArg16(&sp2A);
                arg0->animation_state->unk88 = sp2A;
                func_global_asm_80617D94(arg0);
                return 1;
            }
            break;
        case 5:
            if (arg1 < sp2C) {
                getAnimationArg16(&sp2A);
                arg0->animation_state->unk88 = sp2A;
                func_global_asm_80617D94(arg0);
                return 1;
            }
            break;
        case 6:
            if (sp2C < arg1) {
                getAnimationArg16(&sp2A);
                arg0->animation_state->unk88 = sp2A;
                func_global_asm_80617D94(arg0);
                return 1;
            }
            break;
        case 7:
            getAnimationArg16(&sp2A);
            arg0->animation_state->unk88 = sp2A;
            func_global_asm_80617D94(arg0);
            return 1;
        }
        D_807F5AF0 += 2;
    }
}



s32 func_global_asm_80617FFC(Actor *arg0) {
    f32 sp1C;

    D_807F5AF0++;
    getAnimationArg32(&sp1C);
    arg0->animation_state->unk8C = sp1C;
    return 1;
}

s32 func_global_asm_80618048(Actor *arg0) {
    f32 var_f0;
    ActorAnimationState *aaS;

    aaS = arg0->animation_state;
    if (aaS->unk30 & 1) {
        var_f0 = D_global_asm_80744478 * 0.5f;
    } else {
        var_f0 = 1.0f;
    }
    aaS->unk8C = aaS->unk8C - var_f0;
    if (arg0->animation_state->unk8C <= 0.0) {
        D_807F5AF0++;
        return 1;
    }
    return 0;
}

void func_global_asm_806180FC(Actor *arg0) {

}

s32 func_global_asm_80671E00(f32, f32, f32, f32, s16*, s16*, s32, s32);
extern f32 D_global_asm_80753E48[];
extern s16 D_global_asm_80753E64[];

void func_global_asm_80618104(Actor *arg0) {
    f32 var_f0;
    f32 sp50;
    s32 sp48[2];
    PlayerAdditionalActorData *sp44;
    s16 var_a2;
    s16 sp40;
    s16 sp3E;

    sp44 = arg0->PaaD;
    func_global_asm_806F8BC4(4, 0U, 0);
    if ((func_global_asm_806F8AD4(4U, sp44->unk1A4) != 0) && (func_global_asm_8067ACDC(arg0, 4U, NULL) < D_global_asm_80753E64[D_global_asm_807FD584])) {
        changeCollectableCount(4, sp44->unk1A4, -1);
        sp50 = arg0->animation_state->scale[1] * 2.6666667064030967;
        switch (arg0->unk58) {
        case ACTOR_DK:
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
            var_f0 = 30.0f;
            break;
        case ACTOR_DIDDY:
        case ACTOR_TINY:
            var_f0 = 20.0f;
            break;
        default:
            var_f0 = 30.0f;
            break;
        }
        if (func_global_asm_80671E00(arg0->x_position,
                arg0->y_position + 30.0,
                arg0->z_position,
                var_f0, &sp40, &sp3E, 1, NULL)) {
            if (arg0->control_state == 2) {
                var_a2 = func_global_asm_80665DE0(
                    character_change_array[cc_player_index].look_at_at_x,
                    character_change_array[cc_player_index].look_at_at_z,
                    character_change_array[cc_player_index].look_at_eye_x,
                    character_change_array[cc_player_index].look_at_eye_z);
            } else {
                var_a2 = arg0->y_rotation;
            }
            if (!func_global_asm_806725E4(sp40, sp3E, var_a2, 0)) {
                func_global_asm_806907E0();
            }
        }
        if (arg0->control_state == 2) {
            func_global_asm_80690814(current_player, 6);
            sqrtf(SQ(character_change_array[cc_player_index].look_at_at_x - character_change_array[cc_player_index].look_at_eye_x) + SQ(character_change_array[cc_player_index].look_at_at_z - character_change_array[cc_player_index].look_at_eye_z));
            func_global_asm_8069084C(0x29, (s16) D_global_asm_807FD568->weapon, sp50, func_global_asm_80665DE0(character_change_array[cc_player_index].look_at_at_x, character_change_array[cc_player_index].look_at_at_z, character_change_array[cc_player_index].look_at_eye_x, character_change_array[cc_player_index].look_at_eye_z), D_global_asm_80753E48[D_global_asm_807FD584], 0.0f, arg0);
            return;
        }
        func_global_asm_80690814(arg0, 7);
        func_global_asm_8069084C(0x29, (s16) D_global_asm_807FD568->weapon, sp50, arg0->y_rotation, D_global_asm_80753E48[D_global_asm_807FD584], 0.0f, arg0);
    }
}

void func_global_asm_80618430(Actor *arg0) {
    u8 boneIndex;

    getAnimationArg8(&boneIndex);
    func_global_asm_8071498C(func_global_asm_8071B1AC);
    func_global_asm_80714998(2);
    func_global_asm_80714950(arg0->y_rotation);
    func_global_asm_807149B8(1);
    func_global_asm_80714C08(&D_global_asm_8071FF18, 0.4f, arg0, boneIndex, 0);
}

void func_global_asm_8061849C(Actor *arg0) {
    extra_player_info_pointer->unk1F0 |= 0x40000;
}

void func_global_asm_806184BC(Actor *arg0) {
    u8 boneIndex;

    getAnimationArg8(&boneIndex);
    if (boneIndex == 0xFF) {
        func_global_asm_807149B8(0);
        func_global_asm_807149FC(1);
        drawSpriteAtPosition(&D_global_asm_8071FE08, 0.7f, arg0->x_position, arg0->y_position + 7.0f, arg0->z_position);
    } else {
        func_global_asm_8071498C(func_global_asm_8071B24C);
        func_global_asm_80714998(2);
        func_global_asm_80714950((arg0->y_rotation + 0x800) & 0xFFF);
        func_global_asm_807149B8(1);
        func_global_asm_80714A28(0x80);
        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.4f, arg0, boneIndex, 0);
    }
}

void func_global_asm_8061859C(Actor *arg0) {
    u8 boneIndex;

    getAnimationArg8(&boneIndex);
    func_global_asm_8071498C(func_global_asm_8071B44C);
    func_global_asm_80714998(2);
    func_global_asm_80714950(arg0->unkEE);
    func_global_asm_807149B8(1);
    func_global_asm_80714C08(&D_global_asm_8071FF18, 0.4f, arg0, boneIndex, 0);
}

extern s32 D_global_asm_807FBB68;

void func_global_asm_80618608(Actor *arg0) {
    u8 sp3F;
    s16 i;

    getAnimationArg8(&sp3F);
    if (D_global_asm_807FBB68 & 2) {
        for (i = 0; i < 0x14; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(func_global_asm_8071DB74);
            func_global_asm_80714A28(4);
            func_global_asm_80714C08(&D_global_asm_80720B58, 0.1f, arg0, sp3F, 0);
        }
        return;
    }
    playSoundAtActorPosition(arg0, 0x8A, 0x96, 0x7F, 0x32);
    func_global_asm_80714950(arg0);
    func_global_asm_8071498C(func_global_asm_8071A440);
    func_global_asm_80714C08(&D_global_asm_8072006C, 0.4f, arg0, sp3F, 2);
}

void func_global_asm_80618728(Actor *arg0) {
    func_global_asm_807149A8(0x7D0);
    func_global_asm_80714998(3);
    func_global_asm_806858E8(arg0, 0x16, 0.8f, 0.0f, 0.0f, 0.0f, -0x78);
    func_global_asm_807149A8(0x7D0);
    func_global_asm_80714998(3);
    func_global_asm_806858E8(arg0, 0x17, 0.8f, 0.0f, 0.0f, 0.0f, -0x78);
}

void func_global_asm_806187BC(s32 arg0) {
    s16 sp1E;
    s16 sp1C;

    getAnimationArg16(&sp1E);
    getAnimationArg16(&sp1C);
}

void func_global_asm_806187E8(Actor *arg0) {
    s16 sp1E;

    getAnimationArg16(&sp1E);
    arg0->unk146_s16 |= sp1E;
}

void func_global_asm_80618820(Actor *arg0) {
    s16 sp1E;

    getAnimationArg16(&sp1E);
    arg0->unk146_s16 &= ~sp1E;
}

void func_global_asm_8061885C(Actor *arg0) {
    s32 sp1C;

    getAnimationArg32(&sp1C);
}

void func_global_asm_80618880(Actor *arg0) {
    if (extra_player_info_pointer->unk64 != 0) {
        extra_player_info_pointer->unk64 = 0;
        arg0->animation_state->unk88 = 0;
    } else {
        arg0->animation_state->unk88 = 1;
    }
}

void func_global_asm_806188B8(Actor *arg0) {
    if (arg0->y_velocity < 0.0f) {
        arg0->animation_state->unk88 = 1;
    } else {
        arg0->animation_state->unk88 = 0;
    }
}

void func_global_asm_806188F4(Actor *arg0) {
    if (arg0->unk6A & arg0->unk6C & 1) {
        arg0->animation_state->unk88 = 1;
    } else {
        arg0->animation_state->unk88 = 0;
    }
}

void func_global_asm_8061892C(Actor *arg0) {
    s16 sp1E;

    getAnimationArg16(&sp1E);
    arg0->y_velocity = sp1E;
}

void func_global_asm_80618968(Actor *arg0) {
    f32 sp1C;

    getAnimationArg32(&sp1C);
    arg0->y_acceleration = sp1C;
}

void func_global_asm_80618998(Actor *arg0) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s16 sp42;
    s16 sp40;
    u8 sp3F;
    u8 sp3E;
    s32 var_v1;

    func_global_asm_8072E2B0(arg0, &sp4C, &sp48, &sp44);
    getAnimationArg8(&sp3E);
    getAnimationArg8(&sp3F);
    getAnimationArg16(&sp42);
    getAnimationArg16(&sp40);
    sp3F *= (arg0->animation_state->scale[1] / 0.15);
    if ((arg0->unk58 == ACTOR_BOSS_MAD_JACK) || ((arg0->unk6A & 1) && ((arg0->object_properties_bitfield & 4) || (arg0->unk58 == ACTOR_TOY_MONSTER)) && (is_cutscene_active != 1))) {
        if (sp3F >= 0x15) {
            var_v1 = 0x14;
        } else {
            var_v1 = sp3F;
        }
        func_global_asm_8061EF4C(extra_player_info_pointer->unk104, sp3E, var_v1, sp4C, sp48, sp44, sp42, sp40);
    }
}

void func_global_asm_80618B6C(Actor *arg0) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;
    s16 sp30;
    u8 sp2F;
    u8 sp2E;

    func_global_asm_8072E2B0(arg0, &sp3C, &sp38, &sp34);
    getAnimationArg8(&sp2E);
    getAnimationArg8(&sp2F);
    getAnimationArg16(&sp32);
    getAnimationArg16(&sp30);
    func_global_asm_8061EF4C(extra_player_info_pointer->unk104, sp2E, sp2F, sp3C, sp38, sp34, sp32, sp30);
}

void func_global_asm_80618C00(Actor *actor, u8 boneIndex) {
    f32 x, y, z;
    f32 yScale;

    yScale = 0.04F;
    getBonePosition(actor, boneIndex, &x, &y, &z);
    if ((actor->unk58 == ACTOR_CHUNKY) || (actor->unk58 == ACTOR_KRUSHA)) {
        yScale = 0.1f;
    }
    func_global_asm_806846B4(x, actor->floor, z, 0.03f, yScale, actor, 0);
}

void func_global_asm_80618C8C(Actor *arg0) {
    u8 boneIndex = arg0->unk58 == ACTOR_DK ? 2 : 8;
    func_global_asm_80618C00(arg0, boneIndex);
    extra_player_info_pointer->unkCA = 0x28;
}

void func_global_asm_80618CD8(Actor *arg0) {
    u8 sp1F;

    getAnimationArg8(&sp1F);
    if (sp1F & 0x80) {
        arg0->unk132 = sp1F & 0x7F;
    } else {
        func_global_asm_8066EA64(arg0, sp1F);
    }
}

void func_global_asm_80618D20(Actor *arg0) {
    u8 sp1F;

    getAnimationArg8(&sp1F);
    if (sp1F & 0x80) {
        arg0->unk132 = sp1F & 0x7F;
    } else {
        func_global_asm_8066EA90(arg0, sp1F);
    }
}

extern s32 D_global_asm_80746B80[]; // TODO: Datatype
extern f32 D_global_asm_80757460;

void func_global_asm_80618D68(Actor *arg0) {
    s32 i;
    u8 sp43;
    u8 sp42;

    getAnimationArg8(&sp43);
    getAnimationArg8(&sp42);
    for (i = sp43; i < sp42; i++) {
        func_global_asm_8071498C(func_global_asm_8071D28C);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1U);
        func_global_asm_8071496C(1);
        func_global_asm_80714950(1);
        func_global_asm_80714A28(0x20U);
        func_global_asm_80714C08(D_global_asm_80746B80[i], 0.2f, arg0, 7, 0U);
    }
}

void func_global_asm_80618E4C(Actor *arg0) {
    u8 sp1F;

    getAnimationArg8(&sp1F);
    if (sp1F != 0) {
        arg0->object_properties_bitfield &= ~0x40000000;
        global_properties_bitfield |= 0x10030;
    } else {
        arg0->object_properties_bitfield |= 0x40000000;
        global_properties_bitfield &= ~0x10030;
        func_global_asm_806D9924(arg0);
    }
}

extern s16 D_global_asm_80746E10[];

typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
} AAD_80618EE8;

void func_global_asm_80618EE8(Actor *arg0) {
    AAD_80618EE8 *aaD;
    spawnActor(ACTOR_INSTRUMENT_LOGO, D_global_asm_80746E10[arg0->unk58]);
    moveAndScaleActorToAnother(last_spawned_actor, arg0, arg0->animation_state->scale[0]);
    last_spawned_actor->z_rotation = arg0->z_rotation;
    last_spawned_actor->x_rotation = arg0->x_rotation;
    aaD = ((AAD_80618EE8*)last_spawned_actor->additional_actor_data);
    getAnimationArg8(&aaD->unk6);
}

void func_global_asm_80618F74(Actor *arg0) {
    u8 sp1F;
    Actor *vehicle;

    getAnimationArg8(&sp1F);
    if (sp1F != 0) {
        spawnActor(ACTOR_SPOTLIGHT, 0xA8);
        moveAndScaleActorToAnother(last_spawned_actor, arg0, arg0->animation_state->scale[0]);
        extra_player_info_pointer->vehicle_actor_pointer = last_spawned_actor;
    } else {
        vehicle = extra_player_info_pointer->vehicle_actor_pointer;
        if ((vehicle != NULL) && (vehicle->unk58 == ACTOR_SPOTLIGHT)) {
            deleteActor(vehicle);
            extra_player_info_pointer->vehicle_actor_pointer = NULL;
        }
    }
}

extern f32 D_807F5AF8[3];
extern f32 D_807F5AFC;
extern f32 D_807F5B00;

void func_global_asm_80619018(Actor *arg0) {
    u8 sp1F;

    getAnimationArg8(&sp1F);
    if (sp1F != 0) {
        if (arg0->unk12C != -1) {
            func_global_asm_80659620(&D_807F5AF8, &D_807F5AFC, &D_807F5B00, arg0->unk12C);
            func_global_asm_80659670(107.0f, 48.0f, 80.0f, arg0->unk12C);
        }
    } else {
        if (arg0->unk12C != -1) {
            func_global_asm_80659670(D_807F5AF8[0], D_807F5AF8[1], D_807F5AF8[2], arg0->unk12C);
        }
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    f32 unk10;
} AAD_806192A4;

s32 func_global_asm_8071D94C(Actor *, Struct80717D84 *, u8 *);
extern s32 D_global_asm_80746BD4[]; // TODO: Datatype
extern s32 D_global_asm_80746B80[]; // TODO: Datatype
extern u8 D_global_asm_80750AD0;

void func_global_asm_806190C0(Actor *arg0) {
    u16 sp4E;
    u16 sp4C;
    u8 sp4B;
    u8 boneIndex;
    s8 sp49;
    u8 sp48;
    s16 sp46;
    f32 sp40;
    f32 x;
    f32 y;
    f32 z;
    Struct80717D84 *var_a1;
    u8 sp2F;

    getAnimationArg16(&sp4E);
    getAnimationArg16(&sp4C);
    getAnimationArg8(&sp4B);
    getAnimationArg8(&boneIndex);
    getAnimationArg8(&sp49);
    getAnimationArg8(&sp48);
    getAnimationArg16(&sp46);
    if (D_global_asm_80750AD0 == 0) {
        sp40 = sp4C * 0.00048828125f;
        func_global_asm_807149B8(1);
        func_global_asm_80714998(sp4B);
        func_global_asm_807149FC(sp46);
        if (!boneIndex) {
            x = arg0->x_position;
            y = arg0->y_position;
            z = arg0->z_position;
        } else {
            getBonePosition(arg0, boneIndex, &x, &y, &z);
        }
        y += sp49 * sp40;
        if (sp48 != 0) {
            func_global_asm_8071498C(D_global_asm_80746BD4[sp48]);
        }
        var_a1 = drawSpriteAtPosition(D_global_asm_80746B80[sp4E], sp40, x, y, z);
        sp2F = 0;
        switch (sp48) {
            case 1:
                func_global_asm_8071D94C(arg0, var_a1, &sp2F);
                break;
            case 2:
                var_a1->unk35C = 1;
                break;
            case 4:
                var_a1->unk35C = -0x32 - RandClamp(50);
                break;
        }
        if (sp2F != 0) {
            func_global_asm_80715908(var_a1);
        }
    }
}

void func_global_asm_806192A4(Actor *arg0) {
    u16 sp46;
    u16 sp44;
    u16 idleParticleModelIndex;
    u16 sp40;
    f32 scale;
    AAD_806192A4 *aaD;

    scale = arg0->animation_state->scale[1] / 0.15;
    getAnimationArg16(&sp46);
    getAnimationArg16(&sp44);
    getAnimationArg16(&idleParticleModelIndex);
    getAnimationArg16(&sp40);
    spawnActor(ACTOR_PARTICLE_IDLE, idleParticleModelIndex);
    moveAndScaleActorToAnother(last_spawned_actor, arg0, arg0->animation_state->scale[0]);
    last_spawned_actor->y_rotation = arg0->y_rotation;
    last_spawned_actor->z_rotation = arg0->z_rotation;
    last_spawned_actor->x_rotation = arg0->x_rotation;
    aaD = last_spawned_actor->additional_actor_data;
    aaD->unk10 = 0.0f;
    if (sp46 != 0xFFFF) {
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        switch (arg0->unk58) {
            default:
                scale *= 0.2;
                break;
            case ACTOR_KLUMP:
                scale *= 0.4;
                changeActorColor(0, 0xFF, 0, 0xFF);
                break;
            case ACTOR_LANKY:
            case ACTOR_TINY:
                func_global_asm_80714998(0);
                scale *= 0.18;
                aaD->unk10 = -1.4f;
                break;
            case ACTOR_DIDDY:
                func_global_asm_80714998(0);
                scale *= 0.25;
                aaD->unk10 = -1.4f;
                break;
        }
    }
    last_spawned_actor->y_position -= aaD->unk10;
    if (sp46 != 0xFFFF) {
        func_global_asm_80714C08(D_global_asm_80746B80[sp46], scale, last_spawned_actor, 1, 2);
    }
    aaD->unk0 = sp44;
    aaD->unk4 = arg0;
    aaD->unk8 = arg0->unk54;
    aaD->unkC = arg0->animation_state->unk64;
    aaD->unk2 = sp40;
}
