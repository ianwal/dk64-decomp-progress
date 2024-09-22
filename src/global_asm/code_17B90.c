#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80612E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806130A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806131D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061324C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806133C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806134B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806136B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80613FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061421C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614644.s")

f32 func_global_asm_80614A54(Actor *arg0) {
    return arg0->animation_state->unk0->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614C38.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80614D90.s")

extern u16 *D_807FBB54;

void playAnimation(Actor *arg0, s32 arg1) {
    s32 offset = (arg1 * 7) + (arg0->unk58 - 2);
    playActorAnimation(arg0, D_807FBB54[offset]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/playActorAnimation.s")

extern u8 *D_807F5AF0;

void func_global_asm_80614F28(u8 *arg0) {
    // getAnimationArg8
    *arg0 = *D_807F5AF0++;
}

void func_global_asm_80614F4C(s16 * arg0) {
    // getAnimationArg16
    ((u8*)arg0)++;
    ((u8*)arg0)[-1] = *D_807F5AF0++;
    ((u8*)arg0)[0] = *D_807F5AF0++;
}

void func_global_asm_80614F88(s32 * arg0) {
    // getAnimationArg24
    ((u8*)arg0) += 2;
    ((u8*)arg0)[-2] = *D_807F5AF0++;
    ((u8*)arg0)[-1] = *D_807F5AF0++;
    ((u8*)arg0)[0] = *D_807F5AF0++;
}

void func_global_asm_80614FD8(s32 * arg0) {
    // getAnimationArg32
    ((u8*)arg0) += 3;
    ((u8*)arg0)[-3] = *D_807F5AF0++;
    ((u8*)arg0)[-2] = *D_807F5AF0++;
    ((u8*)arg0)[-1] = *D_807F5AF0++;
    ((u8*)arg0)[0] = *D_807F5AF0++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061503C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061505C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061507C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806150C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806150F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806151BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061522C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806152FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061537C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061540C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061551C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806155F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061562C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806156A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806156DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061580C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806158E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061594C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061599C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806159EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615ADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80615FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061600C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061607C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061612C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806161D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806162C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806163D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806163E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806164C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806165F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806166A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061670C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806167D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806167EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806168E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806169C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616DA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80616E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806174B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806175C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061796C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806179C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80617FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806180FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061849C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806184BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061859C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806187BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806187E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061885C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806188B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806188F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_8061892C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80618F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80619018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806190C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806192A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80619500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80619520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80619540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_80619580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_17B90/func_global_asm_806195B4.s")
