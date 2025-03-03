#include <ultra64.h>
#include "functions.h"

void func_global_asm_80613BA0(Actor*, s16, f32, f32);
void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_global_asm_80613FB0(Actor*, s32, f32, u8);
void func_global_asm_80614644(Actor*, AnimationStateUnk0*, f32);

extern u8 D_global_asm_80746D5C;

extern u8 *D_global_asm_807F5AF0;
extern s32 D_global_asm_807F5AF4;
extern u16 *D_global_asm_807FBB54;

void *func_global_asm_80612E90(Actor *, s32, u8);

void func_global_asm_806130A4(u32, Gfx *);             /* extern */
void func_global_asm_8061324C(Gfx *, Gfx *, void *, s32); /* extern */
void func_global_asm_806133C8(u32, Gfx *);             /* extern */
void func_global_asm_80687D50(s32, void *);            /* extern */
extern Struct807FB630 D_global_asm_807FB630[];
extern void *D_global_asm_807FB634;
extern u16 D_global_asm_807FBB30;
extern u16 D_global_asm_807FBB32;
extern s32 D_global_asm_80746B64;

void *func_global_asm_80612E90(Actor *arg0, s32 arg1, u8 arg2) {
    s32 delta;
    s32 i;
    ActorModelHeader *temp_v0;

    for (i = 0; i < D_global_asm_807FBB30; i++) {
        if (((s32)arg1 == (s32)D_global_asm_807FB630[i].unk0) && (arg2 == D_global_asm_807FB630[i].unk8)) {
            D_global_asm_807FB630[i].unk2++;
            func_global_asm_80687D50(arg0, D_global_asm_807FB630[i].unk4);
            return D_global_asm_807FB630[i].unk4;
        }
    }
    if ((s32) D_global_asm_807FBB32 >= 0x20) {
        return D_global_asm_807FB634;
    }
    temp_v0 = getPointerTableFile(5, arg1 - 1, 1U, 1U);
    D_global_asm_807FB630[i].unk0 = arg1;
    D_global_asm_807FBB30++;
    D_global_asm_807FB630[i].unk8 = arg2;
    D_global_asm_807FB630[i].unk2 = 1;
    D_global_asm_807FB630[i].unk4 = temp_v0;
    delta = ((s32)temp_v0 - (s32)temp_v0->unk0) + sizeof(ActorModelHeader);
    temp_v0->unk0 += delta;
    temp_v0->unk4_raw += delta;
    for (i = 0; i < temp_v0->unk21; i++) {
        temp_v0->unk4[i] += delta;
    }
    if (temp_v0->unk8 != NULL) {
        temp_v0->unk8 += delta;
    } else {
        temp_v0->unk8 = &D_global_asm_80746B64;
        temp_v0->bone_count = 1;
    }
    temp_v0->unkC += delta;
    temp_v0->unk10 += delta;
    func_global_asm_8061324C(*temp_v0->unk4, temp_v0->unk4, &temp_v0->unk14, delta);
    func_global_asm_8065CDB0(*temp_v0->unk4, temp_v0->unk4);
    func_global_asm_806133C8(*temp_v0->unk4, temp_v0->unk4);
    func_global_asm_80687D50(arg0, temp_v0);
    if (arg2 & 1) {
        func_global_asm_806130A4(*temp_v0->unk4, temp_v0->unk4);
    }
    return temp_v0;
}



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

extern u16 D_global_asm_807FBB30;

u16 func_global_asm_80613448(Actor *arg0) {
    Actor_unk0 *var_v0 = arg0->unk0;
    s32 searchIndex;

    searchIndex = D_global_asm_807FBB30;
    while (searchIndex >= 0) {
        if ((s32)var_v0 == (s32)D_global_asm_807FB630[searchIndex].unk4) {
            break;
        }
        searchIndex--;
    }
    if (searchIndex >= 0) {
        return D_global_asm_807FB630[searchIndex].unk0;
    }
    return 0;
}

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
        scale = 0.15f;
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
        temp_v1->unk80 = 0;
        return 1;
    }
    return 0;
}

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

