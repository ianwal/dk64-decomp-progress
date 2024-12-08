#include <ultra64.h>
#include "functions.h"


u8 func_global_asm_8072E5B0(void) {
    return !(player_pointer->unk6A & 1)
        && !(player_pointer->locked_to_pad == 1)
        && !(player_pointer->control_state == 0x63); // Rocketbarrel
}

typedef struct TriggerRawItem {
    s16 x;
    s16 y;
    s16 z;
    s16 radius;
    s16 height;
    s16 unkA;
    u8 activation_type;
    u8 default_active_state;
    u8 padE[2];
    u16 type;
    u16 map;
    u16 exit;
    u8 pad16[0x38 - 0x16];
} TriggerRawItem;

typedef struct TriggerData {
    TriggerRawItem raw;
    u8 not_in_zone;
    u8 active;
} TriggerData;

typedef struct TriggerFile {
    s16 count;
    TriggerRawItem items[];
} TriggerFile;

typedef struct TriggersRDRAM {
    s16 count;
    TriggerData *data;
} TriggersRDRAM;

extern TriggersRDRAM *D_global_asm_80755A14;

void func_global_asm_8072E5FC(TriggerFile *arg0) {
    TriggerRawItem *var_s2;
    TriggerData *var_v1;
    s16 i;

    D_global_asm_80755A14->count = 0;
    D_global_asm_80755A14->data = NULL;
    if (arg0 == NULL) {
        return;
    }
    var_s2 = &arg0->items;
    D_global_asm_80755A14->count = arg0->count;
    for (i = 0; i < D_global_asm_80755A14->count; i++) {
        if (i == 0) {
            var_v1++;
            D_global_asm_80755A14->data = malloc(D_global_asm_80755A14->count * sizeof(TriggerData));
            var_v1 = D_global_asm_80755A14->data;
        } else {
            var_v1++;
        }
        var_v1->raw = *var_s2++;
        var_v1->not_in_zone = 0;
        var_v1->active = (u8) var_v1->raw.default_active_state;
    }
}



typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
} GlobalASMStruct67;

extern GlobalASMStruct67 D_global_asm_807557A0[];

s32 func_global_asm_8072E7DC(s16 arg0, Actor **arg1);

// TODO: This stack is super sus, fake match?
void func_global_asm_8072E740(Maps map) {
    s32 i;
    void *loadingZones;
    s32 temp;
    s32 temp2 = 0x27;
    s32 temp3;
    s32 sp30;

    // Loading zones
    loadingZones = getPointerTableFile(0x12, map, 1, 0);
    func_global_asm_8072E5FC(loadingZones);
    if (loadingZones) {
        func_global_asm_8066B434(loadingZones, 0xC1, 0x3D);
    }
    for (i = 0; i < temp2; i++) {
        func_global_asm_8072E7DC(D_global_asm_807557A0[i].unk2, &sp30);
        D_global_asm_807557A0[i].unk8 = sp30;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/triggers/func_global_asm_8072E7DC.s")

/*
// TODO: Quite close, out stack is too small and something is missing at the end
s32 func_global_asm_8072E7DC(s16 arg0, Actor **arg1) {
    Actor *sp4;
    Actor *temp_a1;
    s32 i;
    s32 found;

    found = FALSE;
    i = 0;
    while (!found && i < D_global_asm_807FBB34) {
        temp_a1 = D_global_asm_807FB930[i].unk0;
        if (D_global_asm_807FB930[i].unk0->unk58 == arg0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/triggers/func_global_asm_8072E868.s")

extern u8 D_global_asm_807FBDC4;
extern s16 D_global_asm_807FDCB8;
extern s16 D_global_asm_807FDCBC;

/*
void func_global_asm_8072E868(void) {
    s32 sp4C;
    GlobalASMStruct35 *var_s0;
    Struct807FBB70_unk278 *temp_v0;
    s32 (*temp_v0_3)();
    s32 temp_a0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v1;
    GlobalASMStruct67 *temp_v0_4;
    TriggerData *var_s0_2;
    TriggerData *var_s2;
    void *var_v0;

    if (D_global_asm_807FBDC4 > 0) {
        var_s0 = &D_global_asm_807FBB70;
        do {
            temp_a0 = var_s0->unk258[0];
            temp_v0 = var_s0->unk278[0];
            if (temp_a0 != 1) {
                if (temp_a0 != 2) {
                    var_v0 = &D_global_asm_807FBB70.unk0[D_global_asm_807FBDC4];
                } else {
                    func_global_asm_8072EC94(temp_v0->unk0, 0);
                    var_v0 = &D_global_asm_807FBB70.unk0[D_global_asm_807FBDC4];
                }
            } else {
                func_global_asm_8072EC94(temp_v0->unk0, 1);
                var_v0 = &D_global_asm_807FBB70.unk0[D_global_asm_807FBDC4];
            }
            var_s0 += 4;
        } while (var_s0 < var_v0);
    }
    var_s2 = D_global_asm_80755A14->unk4;
    sp4C = 0;
    if (D_global_asm_80755A14->unk0 > 0) {
        do {
            if (func_global_asm_8072EA90(var_s2) != 0) {
                var_s1 = 0;
                var_s0_2 = var_s2;
                if (var_s2->unkE > 0) {
                    do {
                        temp_v0_3 = &D_global_asm_807557A0[var_s0_2->unk10].unkC;
                        if ((temp_v0_3 == NULL) || (temp_v0_3() != 0)) {
                            var_v1 = 0;
                            temp_v0_4 = &D_global_asm_807557A0[var_s0_2->unk10];
                            if (temp_v0_4->unk2 == 0xA) {
                                var_v1 = 1;
                            }
                            func_global_asm_8067AB20(current_actor_pointer, temp_v0_4->unk8, 0x01000000, temp_v0_4->unk7, var_s0_2 + 0x12, var_v1);
                            D_global_asm_807FDCB8 = var_s2->unk0;
                            D_global_asm_807FDCBA = var_s2->unk2;
                            D_global_asm_807FDCBC = var_s2->unk4;
                        }
                        var_s1 += 1;
                        var_s0_2 += 0xA;
                    } while (var_s1 < var_s2->unkE);
                }
            }
            temp_v0_2 = sp4C + 1;
            sp4C = temp_v0_2;
            var_s2 += 0x3A;
        } while (temp_v0_2 < D_global_asm_80755A14->unk0);
    }
}
*/

extern s16 D_global_asm_8076A0AA;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD[0x38 - 0xD];
    u8 unk38;
    u8 unk39;
} Struct8072EA90;

u8 func_global_asm_8072EA90(Struct8072EA90 *arg0) {
    u8 var_t3;
    u8 playerIndex;
    s32 pad;
    u8 var_t4;
    f32 d;

    var_t3 = FALSE;
    var_t4 = 0;
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (character_change_array[playerIndex].does_player_exist != 0) {
            if (arg0->unk8 == -1 || (arg0->unk2 <= character_change_array[playerIndex].player_pointer->y_position && character_change_array[playerIndex].player_pointer->y_position < (arg0->unk2 + arg0->unk8))) {
                d = ((arg0->unk0 - character_change_array[playerIndex].player_pointer->x_position) * (arg0->unk0 - character_change_array[playerIndex].player_pointer->x_position)) + ((arg0->unk4 - character_change_array[playerIndex].player_pointer->z_position) * (arg0->unk4 - character_change_array[playerIndex].player_pointer->z_position));
                if (d < (arg0->unk6 * arg0->unk6)) {
                    var_t3 = TRUE;
                }
            }
        }
    }
    switch (arg0->unkC) {
        case 0:
            if (var_t3) {
                if (arg0->unk38 == 1 && arg0->unk39 != 0) {
                    var_t4 = 1;
                }
            }
            break;
        case 1:
            if (!var_t3) {
                if (arg0->unk38 == 0 && arg0->unk39 != 0) {
                    var_t4 = 1;
                }
            }
            break;
        case 2:
            if (var_t3) {
                if (arg0->unk39 != 0) {
                    var_t4 = 1;
                }
            }
            break;
    }
    if (var_t4 != 0) {
        if (func_global_asm_807318AC(D_global_asm_8076A0AA, arg0->unkA) == 0) {
            var_t4 = 0;
        }
    }
    if (var_t3 != 0) {
        arg0->unk38 = 0;
    } else {
        arg0->unk38 = 1;
    }
    return var_t4;
}

void func_global_asm_8072EC94(s32 arg0, u8 arg1) {
    s32 i;
    s32 found;
    TriggerData *var_v1;

    found = FALSE;
    var_v1 = D_global_asm_80755A14->data;
    for (i = 0; i < D_global_asm_80755A14->count && !found; i++) {
        if (arg0 == var_v1->raw.unkA) {
            var_v1->active = arg1;
            found = TRUE;
        }
        var_v1++;
    }
}

void func_global_asm_8072ECFC(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;
    s32 found;
    TriggerData *var_v1;

    found = FALSE;
    var_v1 = D_global_asm_80755A14->data;
    for (i = 0; i < D_global_asm_80755A14->count && !found; i++) {
        if (arg0 == var_v1->raw.unkA) {
            var_v1->raw.x = arg1;
            var_v1->raw.y = arg2;
            var_v1->raw.z = arg3;
            found = TRUE;
        }
        var_v1++;
    }
}
