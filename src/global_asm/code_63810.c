#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63810/func_8065EB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63810/func_8065EFF0.s")

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    s16 unk1A;
} GlobalASMStruct51;

void func_8065A708(f32, f32, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern s32 D_807FBB68;
extern s16 D_80748A84;
extern GlobalASMStruct51 D_807F9070[];

/*
void func_8065EFF0(void) {
    s32 i;

    // TODO: Proper bitfield syntax
    if ((current_map == MAP_FUNGI) && ((player_pointer->PaaD->unk1F0 << 0xB) >= 0)) {

    } else if (!(global_properties_bitfield & 2)) {
        for (i = 0; i < D_80748A84; i++) {
            if (!(D_807FBB68 & 4)) {
                func_806595F0(2);
            }
            func_80659600(D_807F9070[i].unk12);
            func_80659610(D_807F9070[i].unk14);
            func_8065A708(
                D_807F9070[i].unk4,
                D_807F9070[i].unk8,
                D_807F9070[i].unkC,
                0.0f,
                0.0f,
                0.0f,
                D_807F9070[i].unk10,
                0,
                D_807F9070[i].unk16,
                D_807F9070[i].unk17,
                D_807F9070[i].unk18
            );
        }
    }
    D_80748A84 = 0;
}
*/

void func_8065F134(s32 arg0, u8 arg1) {
    u8 *sp1C;
    s32 temp_v0;

    temp_v0 = func_80659470(arg0);
    if (temp_v0 != -1) {
        switch (D_807F6000[temp_v0].unk86) {
            case 2:
                sp1C = &D_807F6000[temp_v0].model_pointer->unk5B;
                break;
            case 1:
                sp1C = &D_807F6000[temp_v0].model_pointer->unkC3;
                break;
        }
        *sp1C = arg1;
    }
}
