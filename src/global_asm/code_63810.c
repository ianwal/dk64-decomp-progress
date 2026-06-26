#include "common.h"

extern s16 D_global_asm_80748A84;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    s16 unk1A;
} GlobalASMStruct51;

extern GlobalASMStruct51 D_global_asm_807F9070[];

extern s32 D_global_asm_807FBB68;

// needs ctx from this file for GlobalASMStruct51
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63810/func_global_asm_8065EB10.s")

void func_global_asm_8065EFF0(void) {
    s32 i;

    if (!(current_map != MAP_FUNGI || gPlayerPointer->PaaD->unk1F0 & 0x100000)) {
        D_global_asm_80748A84 = 0;
    } else {
        if (!(global_properties_bitfield & 2)) {
            for (i = 0; i < D_global_asm_80748A84; i++) {
                if (!(D_global_asm_807FBB68 & 4)) {
                    func_global_asm_806595F0(2);
                }
                func_global_asm_80659600(D_global_asm_807F9070[i].unk12);
                func_global_asm_80659610(D_global_asm_807F9070[i].unk14);
                createLight(
                    D_global_asm_807F9070[i].unk4,
                    D_global_asm_807F9070[i].unk8,
                    D_global_asm_807F9070[i].unkC,
                    0.0f,
                    0.0f,
                    0.0f,
                    D_global_asm_807F9070[i].unk10,
                    0,
                    D_global_asm_807F9070[i].unk16,
                    D_global_asm_807F9070[i].unk17,
                    D_global_asm_807F9070[i].unk18
                );
            }
        }
        D_global_asm_80748A84 = 0;
    }
}

void func_global_asm_8065F134(s32 arg0, u8 arg1) {
    u8 *sp1C;
    s32 temp_v0;

    temp_v0 = func_global_asm_80659470(arg0);
    if (temp_v0 != -1) {
        switch (D_global_asm_807F6000[temp_v0].unk86) {
            case 2:
                sp1C = &D_global_asm_807F6000[temp_v0].model_pointer->unk5B;
                break;
            case 1:
                sp1C = &D_global_asm_807F6000[temp_v0].model_pointer->unkC3;
                break;
        }
        *sp1C = arg1;
    }
}
