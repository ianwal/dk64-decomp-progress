#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u8 func_8072E5B0(void) {
    return !(player_pointer->unk6A & 1)
        && !(player_pointer->locked_to_pad == 1)
        && !(player_pointer->control_state == 0x63); // Rocketbarrel
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072E5FC.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} GlobalASMStruct67;

extern GlobalASMStruct67 D_807557A0[];

// TODO: This stack is super sus, fake match?
void func_8072E740(Maps map) {
    s32 i;
    void *loadingZones;
    s32 temp;
    s32 temp2 = 0x27;
    s32 temp3;
    s32 sp30;

    // Loading zones
    loadingZones = getPointerTableFile(0x12, map, 1, 0);
    func_8072E5FC(loadingZones);
    if (loadingZones) {
        func_8066B434(loadingZones, 0xC1, 0x3D);
    }
    for (i = 0; i < temp2; i++) {
        func_8072E7DC(D_807557A0[i].unk2, &sp30);
        D_807557A0[i].unk8 = sp30;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072E7DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072E868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072EA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072EC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072ECFC.s")
