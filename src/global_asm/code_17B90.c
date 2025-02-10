#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

void func_global_asm_80613BA0(Actor*, s16, f32, f32);
void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_global_asm_80613FB0(Actor*, s32, f32, u8);
void func_global_asm_80614644(Actor*, AnimationStateUnk0*, f32);

extern u8 D_global_asm_80746D5C;

extern u8 *D_807F5AF0;
extern s32 D_807F5AF4;
extern u16 *D_807FBB54;

void *func_global_asm_80612E90(Actor *, s32, u16);

// Displaylist stuff?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80612E90.s")

// Displaylist stuff, searching a DL for 0xD9 (G_GEOMETRYMODE) commands
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806130A4.s")

void func_global_asm_80613194(Actor *actor, s16 arg1) {
    if (actor->unk50 == 0) {
        actor->unk50 = func_global_asm_80612E90(actor, arg1, 0);
    }
}

void func_global_asm_806131D4(Actor *actor, s16 arg1) {
    if (actor->unk50 == 0) {
        actor->unk50 = func_global_asm_80612E90(actor, arg1, 1);
    }
}

void func_global_asm_80613214(Actor *actor) {
    if (actor->unk50 != 0) {
        func_global_asm_80613794(actor, 2);
        actor->unk50 = 0;
    }
}

// Displaylist stuff, looks for 0xDE (G_DL) commands in a loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061324C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613358.s")

// Displaylist stuff, looks for 0xFD (G_SETTIMG) commands in a loop
// Possibly the code responsible for loading textures dynamically
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806133C8.s")

typedef struct {
    u16 modelIndex;
    s16 unk2;
    Actor_unk0 *unk4;
    s32 unk8;
} Struct807FB630;

extern Struct807FB630 D_807FB630[];
extern u16 D_807FBB30;

u16 func_global_asm_80613448(Actor *arg0) {
    Actor_unk0 *var_v0 = arg0->unk0;
    s32 searchIndex;

    searchIndex = D_807FBB30;
    while (searchIndex >= 0) {
        if (var_v0 == D_807FB630[searchIndex].unk4) {
            break;
        }
        searchIndex--;
    }
    if (searchIndex >= 0) {
        return D_807FB630[searchIndex].modelIndex;
    }
    return 0;
}

// matrix initialization
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806134B4.s")

extern f32 D_global_asm_80757360;

typedef struct Struct80614C38_0 Struct80614C38;
struct Struct80614C38_0 {
    void *unk0;
    void *unk4;
    u8 unk8;
    u8 pad9[0x12 - 0x9];
    Struct80614C38 *next;
};

typedef struct ActorModelHeader {
    u8 pad0[0x14];
    Struct80614C38 * unk14;
    u8 pad18[0x20 - 0x18];
    u8 bone_count;
    u8 pad21[0x28 - 0x21];
} ActorModelHeader;

/*
s32 func_global_asm_806134B4(Actor *arg0, u16 arg1) {
    s32 temp_a3;
    s32 i;
    f32 scale;
    ActorAnimationState *temp_v0_2;
    ActorAnimationState *temp_v1;
    ActorModelHeader *temp_v0;

    temp_v0 = func_global_asm_80612E90(arg0, arg1, 0);
    if (temp_v0) {
        arg0->unk0 = temp_v0;
        arg0->unk4C = 0;
        arg0->unk50 = 0;
        temp_v0_2 = malloc(0x170 + (temp_v0->bone_count * sizeof(ActorAnimationState_unk170)));
        arg0->animation_state = temp_v0_2;
        arg0->animation_state->unk0 = &temp_v0_2->unk90[0];
        arg0->animation_state->unk4 = &temp_v0_2->unk90[1];
        arg0->animation_state->unk8 = &temp_v0_2->unk90[2];
        arg0->animation_state->unkC = &temp_v0_2->unk90[3];
        arg0->animation_state->bone_arrays[0] = &temp_v0_2->unk170;
        temp_v1 = arg0->animation_state;
        temp_v1->bone_arrays[1] = temp_v1->bone_arrays[0] + temp_v0->bone_count;
        for (i = 0; i < temp_v0->bone_count; i++) {
            guMtxIdent(arg0->animation_state->bone_arrays[0] + i);
            guMtxIdent(arg0->animation_state->bone_arrays[1] + i);
        }
        guMtxIdentF(&arg0->unkC);
        temp_v1 = arg0->animation_state;
        scale = D_global_asm_80757360;
        temp_v1->unk1C = 0;
        temp_v1->unk20 = 0;
        temp_v1->unk24 = 0;
        temp_v1->scale_x = scale;
        temp_v1->scale_y = scale;
        temp_v1->scale_z = scale;
        temp_v1->unk0->unk4 = 0.0f;
        temp_v1->unk0->unk8 = 0.0f;
        temp_v1->unk0->unk0 = 0;
        // 1
        temp_v1->unk0->unk10 = -1;
        temp_v1->unk0->unk1C = 0;
        temp_v1->unk0->unk14 = 0.0f;
        temp_v1->unk0->unk18 = 0.0f;
        temp_v1->unk0->unk24 = 1.0f;
        temp_v1->unk0->unk34 = 0.0f;

        temp_v1->unk4->unk0 = 0;
        temp_v1->unk4->unk34 = 0.0f;

        temp_v1->unk8->unk0 = 0;
        temp_v1->unk8->unk34 = 0.0f;

        temp_v1->unkC->unk0 = 0;
        temp_v1->unkC->unk34 = 0.0f;

        temp_v1->unk68 = 0;
        temp_v1->unk64 = 0;

        temp_v1->unk70 = 0;
        temp_v1->unk78 = 0;
        temp_v1->unk7C = 0;
        temp_v1->unk84 = 0;
        temp_v1->unk88 = 0;

        temp_v1->unk10 = 0.0f;
        temp_v1->unk44 = 0.0f;
        temp_v1->unk58 = 0.0f;
        temp_v1->unk48 = 1.0f;
        temp_v1->unk80 = 0.0f;
        return 1;
    }
    return 0;
}
*/

void func_global_asm_80613944(Actor *, AnimationStateUnk0 *);

void func_global_asm_806136B4(Actor *arg0) {
    func_global_asm_80613794(arg0, 0);
    func_global_asm_80613794(arg0, 1);
    func_global_asm_80613794(arg0, 2);
    func_global_asm_80688638(&arg0->unk158);
    func_global_asm_80613944(arg0, arg0->animation_state->unk0);
    func_global_asm_80613944(arg0, arg0->animation_state->unk4);
    func_global_asm_80613944(arg0, arg0->animation_state->unk8);
    func_global_asm_80613944(arg0, arg0->animation_state->unkC);
    if (arg0->animation_state->unk1C != NULL) {
        func_global_asm_8061134C(arg0->animation_state->unk1C);
    }
    if (arg0->animation_state->unk20 != NULL) {
        func_global_asm_8061134C(arg0->animation_state->unk20);
    }
    if (arg0->animation_state->unk24 != NULL) {
        func_global_asm_8061134C(arg0->animation_state->unk24);
    }
    func_global_asm_8061134C(arg0->animation_state);
}

// Displaylist stuff, looks for 0xFD (G_SETTIMG) commands in a loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613944.s")

extern Struct807FB7B0 D_807FB7B0[];
extern u16 D_807FBB32;

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613AF8.s")

extern u16 *D_807FBB58;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613BA0.s")

void func_global_asm_80613C48(Actor *arg0, s16 arg1, f32 arg2, f32 arg3) {
    AnimationStateUnk0 *temp_v0;

    temp_v0 = arg0->animation_state->unk0;
    if (arg1 == temp_v0->unk10) {
        temp_v0->unk24 = temp_v0->unk0->unk0;
        return;
    }
    func_global_asm_80613CA8(arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613FB0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061421C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614644.s")

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

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614C38.s")

/*
Gfx *func_global_asm_80614C38(Gfx *dl, Actor *arg1, ActorModelHeader *arg2) {
    u16 hand_state;
    u32 var_v0;
    u8 temp_v1;
    Struct80614C38 *var_s0;
    void* p_addr;

    var_s0 = arg2->unk14;
    hand_state = arg1->unk146;
    while (var_s0) {
        temp_v1 = var_s0->unk8;
        p_addr = (hand_state >> ((temp_v1 - 7) & 0xFF)) & 1 ? osVirtualToPhysical(var_s0->unk0) : osVirtualToPhysical(var_s0->unk4);
        gSPSegment(dl++, temp_v1, p_addr);
        var_s0 = var_s0->next;
    }
    return dl;
}
*/

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/playActorAnimation.s")

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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616A9C.s")

extern f64 D_global_asm_80757370;
extern f64 D_global_asm_80757378;
extern f64 D_global_asm_80757380;

/*
s32 func_global_asm_80616A9C(Actor *arg0) {
    s16 sp26;
    u8 sp25;
    s16 sp22;
    u8 sp21;
    u8 sp20;
    f32 var_f6_2;
    f64 var_f6;

    D_807F5AF0 += 1;
    getAnimationArg16(&sp26);
    getAnimationArg8(&sp25);
    getAnimationArg8(&sp20);
    getAnimationArg16(&sp22);
    getAnimationArg8(&sp21);
    var_f6 = sp25;
    var_f6_2 = sp20;
    playSound(sp26, (var_f6 * D_global_asm_80757370) / D_global_asm_80757378, var_f6_2, sp22 / D_global_asm_80757380, sp21, 0);
    return 1;
}
*/

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

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616E08.s")

extern s32 D_global_asm_807457C8;
extern f64 D_global_asm_807573A8;

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
    func_global_asm_8060866C(arg0, temp_v0, sp2B, sp2A / D_global_asm_807573A8, sp29, 0x4B);
    return 1;
}

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617238.s")

extern f32 D_global_asm_807573D0;

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
        playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, sp36, sp33, sp32, sp35, sp34, D_global_asm_807573D0, 0);
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806175C4.s")

extern f64 D_global_asm_807573D8;
extern f64 D_global_asm_807573E0;
extern f64 D_global_asm_807573E8;
extern f64 D_global_asm_807573F0;
extern f32 D_global_asm_807573F8;

/*
s32 func_global_asm_806175C4(Actor *arg0) {
    s16 sp46;
    u8 sp45;
    u8 sp44;
    u8 sp43;
    u8 sp42;
    f32 var_f2;
    f64 temp_f0;

    D_807F5AF0 += 1;
    getAnimationArg16(&sp46);
    getAnimationArg8(&sp43);
    getAnimationArg8(&sp42);
    getAnimationArg8(&sp45);
    getAnimationArg8(&sp44);
    temp_f0 = ((((arg0->animation_state->scale_x / D_global_asm_807573E0) * 200.0) + D_global_asm_807573E8) * sp43) / D_global_asm_807573F0;
    if (D_global_asm_807573D8 < temp_f0) {
        var_f2 = D_global_asm_807573D8;
    } else {
        var_f2 = temp_f0;
    }
    playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, sp46, var_f2, sp42, sp45, sp44, D_global_asm_807573F8, 0);
    return 1;
}
*/

// m2c errors
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617770.s")

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

extern f64 D_global_asm_80757400;
extern u8 D_global_asm_80746D60[];

s32 func_global_asm_80617BD8(Actor *arg0) {
    u8 sp1F;
    u8 sp1E;

    D_807F5AF0++;
    getAnimationArg8(&sp1F);
    getAnimationArg8(&sp1E);
    playSong(D_global_asm_80746D60[sp1F], sp1E / D_global_asm_80757400);
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

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617DFC.s")

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

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618104.s")

extern SpriteData D_global_asm_8071FE08; // TODO: Sprite?
extern SpriteData D_global_asm_8071FF18; // TODO: Sprite?

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

// rodata, doable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618608.s")

extern SpriteData D_global_asm_8072006C;
extern SpriteData D_global_asm_80720B58;
extern s32 D_global_asm_807FBB68;

/*
extern f32 D_global_asm_80757448;

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
            func_global_asm_80714C08(&D_global_asm_80720B58, D_global_asm_80757448, arg0, sp3F, 0);
        }
        return;
    }
    playSoundAtActorPosition(arg0, 0x8A, 0x96, 0x7F, 0x32);
    func_global_asm_80714950(arg0);
    func_global_asm_8071498C(func_global_asm_8071A440);
    func_global_asm_80714C08(&D_global_asm_8072006C, 0.4f, arg0, sp3F, 2);
}
*/

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

extern f64 D_global_asm_80757450;

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
    sp3F *= (arg0->animation_state->scale[1] / D_global_asm_80757450);
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

extern f32 D_global_asm_80757458;
extern f32 D_global_asm_8075745C;

void func_global_asm_80618C00(Actor *actor, u8 boneIndex) {
    f32 x, y, z;
    f32 yScale;

    yScale = D_global_asm_80757458;
    getBonePosition(actor, boneIndex, &x, &y, &z);
    if ((actor->unk58 == ACTOR_CHUNKY) || (actor->unk58 == ACTOR_KRUSHA)) {
        yScale = D_global_asm_8075745C;
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

// rodata, loop, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618D68.s")

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

s32 func_global_asm_8071D94C(Actor *, Struct80717D84 *, u8 *);
extern s32 D_global_asm_80746B80[]; // TODO: Datatype
extern s32 D_global_asm_80746BD4[]; // TODO: Datatype
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

extern f64 D_global_asm_80757468;
extern f64 D_global_asm_80757470;
extern f64 D_global_asm_80757478;
extern f64 D_global_asm_80757480;
extern f32 D_global_asm_80757488;
extern f32 D_global_asm_8075748C;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    f32 unk10;
} AAD_806192A4;

void func_global_asm_806192A4(Actor *arg0) {
    u16 sp46;
    u16 sp44;
    u16 idleParticleModelIndex;
    u16 sp40;
    f32 scale;
    AAD_806192A4 *aaD;

    scale = arg0->animation_state->scale[1] / D_global_asm_80757468;
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
                scale *= D_global_asm_80757470;
                break;
            case ACTOR_KLUMP:
                scale *= D_global_asm_80757478;
                changeActorColor(0, 0xFF, 0, 0xFF);
                break;
            case ACTOR_LANKY:
            case ACTOR_TINY:
                func_global_asm_80714998(0);
                scale *= D_global_asm_80757480;
                aaD->unk10 = D_global_asm_80757488;
                break;
            case ACTOR_DIDDY:
                func_global_asm_80714998(0);
                scale *= 0.25;
                aaD->unk10 = D_global_asm_8075748C;
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

void func_global_asm_80619500(Actor *arg0) {
    deleteActor(arg0);
}

typedef struct {
    u8 unk0[0x35 - 0x0];
    u8 unk35;
} A178_80619580;

A178_80619580 *func_global_asm_80619520(Actor *arg0) {
    A178_80619580 *a178;

    a178 = NULL;
    // TODO: Proper enum value
    if (arg0->unk58 == 0x134) {
        a178 = arg0->unk178;
    }
    return a178;
}

void func_global_asm_80619540(Actor *arg0) {
    u8 sp1F;
    A178_80619580 *a178;

    a178 = func_global_asm_80619520(arg0);
    getAnimationArg8(&sp1F);
    if (a178 != NULL) {
        a178->unk35 = sp1F;
    }
}

void func_global_asm_80619580(Actor *arg0) {
    A178_80619580 *a178;

    a178 = func_global_asm_80619520(arg0);
    if (a178 != NULL) {
        a178->unk35++;
    }
}

void func_global_asm_806195B4(Actor *arg0) {
    arg0->animation_state->unk88 = (arg0->unkDE >= 0x3DA);
}
