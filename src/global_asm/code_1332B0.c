#include <ultra64.h>
#include "functions.h"


u8 func_8072E5B0(void) {
    return !(player_pointer->unk6A & 1)
        && !(player_pointer->locked_to_pad == 1)
        && !(player_pointer->control_state == 0x63); // Rocketbarrel
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072E5FC.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
} GlobalASMStruct67;

extern GlobalASMStruct67 D_807557A0[];

s32 func_8072E7DC(s16 arg0, Actor **arg1);

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

/*
extern u16 D_807FBB34;

// TODO: Quite close, out stack is too small and something is missing at the end
s32 func_8072E7DC(s16 arg0, Actor **arg1) {
    Actor *sp4;
    Actor *temp_a1;
    s32 i;
    s32 found;

    found = FALSE;
    i = 0;
    while (!found && i < D_807FBB34) {
        temp_a1 = D_807FB930[i].unk0;
        if (D_807FB930[i].unk0->unk58 == arg0) {
            found = TRUE;
        } else {
            i += 1;
        }
        sp4 = temp_a1;
    }
    *arg1 = sp4;
    return found;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072E868.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC[0x39 - 0xC];
    u8 unk39;
} Struct80755A14_unk4;

typedef struct {
    s16 unk0;
    s16 unk2;
    Struct80755A14_unk4 *unk4;
} Struct80755A14;

extern Struct80755A14 *D_80755A14;
extern u8 D_807FBDC4;
extern s16 D_807FDCB8;
extern s16 D_807FDCBC;

/*
void func_8072E868(void) {
    s32 sp4C;
    GlobalASMStruct35 *var_s0;
    Struct807FBB70_unk278 *temp_v0;
    s32 (*temp_v0_3)();
    s32 temp_a0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v1;
    GlobalASMStruct67 *temp_v0_4;
    Struct80755A14_unk4 *var_s0_2;
    Struct80755A14_unk4 *var_s2;
    void *var_v0;

    if (D_807FBDC4 > 0) {
        var_s0 = &D_807FBB70;
        do {
            temp_a0 = var_s0->unk258[0];
            temp_v0 = var_s0->unk278[0];
            if (temp_a0 != 1) {
                if (temp_a0 != 2) {
                    var_v0 = &D_807FBB70.unk0[D_807FBDC4];
                } else {
                    func_8072EC94(temp_v0->unk0, 0);
                    var_v0 = &D_807FBB70.unk0[D_807FBDC4];
                }
            } else {
                func_8072EC94(temp_v0->unk0, 1);
                var_v0 = &D_807FBB70.unk0[D_807FBDC4];
            }
            var_s0 += 4;
        } while (var_s0 < var_v0);
    }
    var_s2 = D_80755A14->unk4;
    sp4C = 0;
    if (D_80755A14->unk0 > 0) {
        do {
            if (func_8072EA90(var_s2) != 0) {
                var_s1 = 0;
                var_s0_2 = var_s2;
                if (var_s2->unkE > 0) {
                    do {
                        temp_v0_3 = &D_807557A0[var_s0_2->unk10].unkC;
                        if ((temp_v0_3 == NULL) || (temp_v0_3() != 0)) {
                            var_v1 = 0;
                            temp_v0_4 = &D_807557A0[var_s0_2->unk10];
                            if (temp_v0_4->unk2 == 0xA) {
                                var_v1 = 1;
                            }
                            func_8067AB20(current_actor_pointer, temp_v0_4->unk8, 0x01000000, temp_v0_4->unk7, var_s0_2 + 0x12, var_v1);
                            D_807FDCB8 = var_s2->unk0;
                            D_807FDCBA = var_s2->unk2;
                            D_807FDCBC = var_s2->unk4;
                        }
                        var_s1 += 1;
                        var_s0_2 += 0xA;
                    } while (var_s1 < var_s2->unkE);
                }
            }
            temp_v0_2 = sp4C + 1;
            sp4C = temp_v0_2;
            var_s2 += 0x3A;
        } while (temp_v0_2 < D_80755A14->unk0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1332B0/func_8072EA90.s")

void func_8072EC94(s32 arg0, u8 arg1) {
    s32 i;
    s32 found;
    Struct80755A14_unk4 *var_v1;

    found = FALSE;
    var_v1 = D_80755A14->unk4;
    for (i = 0; i < D_80755A14->unk0 && !found; i++) {
        if (arg0 == var_v1->unkA) {
            var_v1->unk39 = arg1;
            found = TRUE;
        }
        var_v1++;
    }
}

void func_8072ECFC(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;
    s32 found;
    Struct80755A14_unk4 *var_v1;

    found = FALSE;
    var_v1 = D_80755A14->unk4;
    for (i = 0; i < D_80755A14->unk0 && !found; i++) {
        if (arg0 == var_v1->unkA) {
            var_v1->unk0 = arg1;
            var_v1->unk2 = arg2;
            var_v1->unk4 = arg3;
            found = TRUE;
        }
        var_v1++;
    }
}
