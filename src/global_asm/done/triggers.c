#include <ultra64.h>
#include "functions.h"

typedef struct TriggerRawItem_sub10 {
    s16 type;
    u16 args[4];
} TriggerRawItem_sub10;

typedef struct TriggerRawItem {
    s16 x;
    s16 y;
    s16 z;
    s16 radius;
    s16 height;
    s16 unkA;
    u8 activation_type;
    u8 default_active_state;
    u8 unkE;
    u8 unkF;
    TriggerRawItem_sub10 data[4];
} TriggerRawItem;

typedef struct TriggerData {
    TriggerRawItem raw;
    u8 not_in_zone;
    u8 active;
} TriggerData;

typedef struct TriggerFile {
    s16 count;
    TriggerRawItem items[1];
} TriggerFile;

typedef struct TriggersRDRAM {
    s16 count;
    TriggerData *data;
} TriggersRDRAM;

typedef struct {
    s16 unk0;
    u16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    void *unkC; // TODO: u8(void) signature for func pointer
} GlobalASMStruct67;

// .data
GlobalASMStruct67 D_global_asm_807557A0[] = {
    {0, 0x000B, 0, 0, 0x01, 0, NULL},
    {0, 0x000B, 0, 0, 0x02, 0, NULL},
    {0, 0x000B, 0, 0, 0x03, 0, NULL},
    {0, 0x000D, 0, 0, 0x01, 0, NULL},
    {0, 0x000E, 0, 0, 0x01, 0, NULL},
    {0, 0x000A, 0, 0, 0x01, 0, NULL},
    {0, 0x000A, 0, 0, 0x02, 0, NULL},
    {0, 0x000C, 0, 0, 0x01, 0, NULL},
    {0, 0x000C, 0, 0, 0x02, 0, NULL},
    {0, 0x000C, 0, 0, 0x03, 0, NULL},
    {0, 0x000F, 0, 0, 0x01, 0, NULL},
    {0, 0x000B, 0, 0, 0x04, 0, NULL},
    {0, 0x000C, 0, 0, 0x04, 0, NULL},
    {0, 0x000C, 0, 0, 0x05, 0, NULL},
    {0, 0x000F, 0, 0, 0x02, 0, NULL},
    {0, 0x000C, 0, 0, 0x06, 0, NULL},
    {0, 0x000C, 0, 0, 0x07, 0, NULL},
    {0, 0x000C, 0, 0, 0x08, 0, NULL},
    {0, 0x000C, 0, 0, 0x09, 0, NULL},
    {0, 0x000C, 0, 0, 0x0A, 0, NULL},
    {0, 0x000C, 0, 0, 0x0B, 0, NULL},
    {0, 0x000C, 0, 0, 0x0C, 0, NULL},
    {0, 0x000C, 0, 0, 0x0D, 0, NULL},
    {0, 0x000C, 0, 0, 0x0E, 0, NULL},
    {0, 0x000C, 0, 0, 0x0F, 0, NULL},
    {0, 0x000F, 0, 0, 0x03, 0, NULL},
    {0, 0x000C, 0, 0, 0x11, 0, NULL},
    {0, 0x000C, 0, 0, 0x12, 0, NULL},
    {0, 0x000C, 0, 0, 0x13, 0, NULL},
    {0, 0x000C, 0, 0, 0x15, 0, NULL},
    {0, 0x000C, 0, 0, 0x16, 0, NULL},
    {0, 0x000C, 0, 0, 0x17, 0, NULL},
    {0, 0x000F, 0, 0, 0x01, 0, func_global_asm_8072E5B0},
    {0, 0x000C, 0, 0, 0x18, 0, NULL},
    {0, 0x000C, 0, 0, 0x00, 0, NULL},
    {0, 0x000C, 0, 0, 0x19, 0, NULL},
    {0, 0x000C, 0, 0, 0x1A, 0, NULL},
    {0, 0x000C, 0, 0, 0x1B, 0, NULL},
    {0, 0x000C, 0, 0, 0x1C, 0, NULL},
};

u8 unused_80755A10 = 0x27;

// TODO: Symbol for ptr
// extern TriggersRDRAM D_807FDCB0;
extern TriggersRDRAM *D_global_asm_80755A14 = 0x807FDCB0;

extern s16 D_global_asm_8076A0AA;

extern u8 D_global_asm_807FBDC4;
extern s16 D_global_asm_807FDCB8;
extern s16 D_global_asm_807FDCBA;
extern s16 D_global_asm_807FDCBC;

u8 func_global_asm_8072EA90(TriggerData *);

u8 func_global_asm_8072E5B0(void) {
    return !(player_pointer->unk6A & 1)
        && !(player_pointer->locked_to_pad == 1)
        && !(player_pointer->control_state == 0x63); // Rocketbarrel
}

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

// TODO: This stack is super sus, fake match?
void func_global_asm_8072E740(Maps map) {
    s32 i;
    void *loadingZones;
    s32 temp;
    s32 temp2 = 0x27;
    s32 temp3;
    s32 sp30;

    // Loading zones
    loadingZones = getPointerTableFile(TABLE_18_TRIGGERS, map, 1, 0);
    func_global_asm_8072E5FC(loadingZones);
    if (loadingZones) {
        func_global_asm_8066B434(loadingZones, 0xC1, 0x3D);
    }
    for (i = 0; i < temp2; i++) {
        func_global_asm_8072E7DC(D_global_asm_807557A0[i].unk2, &sp30);
        D_global_asm_807557A0[i].unk8 = sp30;
    }
}

s32 func_global_asm_8072E7DC(s16 arg0, Actor **arg1) {
    s32 pad;
    s32 targ_actor;
    Actor *temp_a1;
    s32 i;
    s32 found;

    found = FALSE;
    i = 0;
    while ((!found) && (i < D_global_asm_807FBB34)) {
        temp_a1 = D_global_asm_807FB930[i].unk0;
        if (temp_a1->unk58 == (u32)arg0) {
            found = TRUE;
        } else {
            i++;
        }
    }
    *arg1 = temp_a1;
    return found;
}

void func_global_asm_8072E868(void) {
    s32 pad[2];
    s32 j;
    GlobalASMStruct35 *var_s0;
    Struct807FBB70_unk278 *temp_v0;
    s32 (*temp_v0_3)();
    s32 k;
    s32 var_v1;
    GlobalASMStruct67 *temp_v0_4;
    TriggerRawItem_sub10 *var_s0_2;
    TriggerData *var_s2;
    void *var_v0;
    s32 i;
    
    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        switch (D_global_asm_807FBB70.unk258[i]) {
            default:
                break;
            case 1:
                func_global_asm_8072EC94(temp_v0->unk0, 1);
                break;
            case 2:
                func_global_asm_8072EC94(temp_v0->unk0, 0);
                break;
        }
    }
    var_s2 = D_global_asm_80755A14->data;
    for (j = 0; j < D_global_asm_80755A14->count; j++) {
        if (func_global_asm_8072EA90(var_s2)) {
            for (k = 0; k < var_s2->raw.unkE; k++) {
                temp_v0_3 = D_global_asm_807557A0[var_s2->raw.data[k].type].unkC;
                if (temp_v0_3) {
                    if (!temp_v0_3()) {
                        continue;
                    }
                }
                if (D_global_asm_807557A0[var_s2->raw.data[k].type].unk2 == 0xA) {
                    var_v1 = TRUE;
                } else {
                    var_v1 = FALSE;
                }
                func_global_asm_8067AB20(
                    current_actor_pointer,
                    D_global_asm_807557A0[var_s2->raw.data[k].type].unk8,
                    0x01000000,
                    D_global_asm_807557A0[var_s2->raw.data[k].type].unk7,
                    &var_s2->raw.data[k].args,
                    var_v1);
                D_global_asm_807FDCB8 = var_s2->raw.x;
                D_global_asm_807FDCBA = var_s2->raw.y;
                D_global_asm_807FDCBC = var_s2->raw.z;
            }
        }
        var_s2++;
    }
}

u8 func_global_asm_8072EA90(TriggerData *arg0) {
    u8 var_t3;
    u8 playerIndex;
    s32 pad;
    u8 var_t4;
    f32 d;

    var_t3 = FALSE;
    var_t4 = 0;
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (character_change_array[playerIndex].does_player_exist != 0) {
            if (arg0->raw.height == -1 || (arg0->raw.y <= character_change_array[playerIndex].player_pointer->y_position && character_change_array[playerIndex].player_pointer->y_position < (arg0->raw.y + arg0->raw.height))) {
                d = ((arg0->raw.x - character_change_array[playerIndex].player_pointer->x_position) * (arg0->raw.x - character_change_array[playerIndex].player_pointer->x_position)) + ((arg0->raw.z - character_change_array[playerIndex].player_pointer->z_position) * (arg0->raw.z - character_change_array[playerIndex].player_pointer->z_position));
                if (d < (arg0->raw.radius * arg0->raw.radius)) {
                    var_t3 = TRUE;
                }
            }
        }
    }
    switch (arg0->raw.activation_type) {
        case 0:
            if (var_t3) {
                if (arg0->not_in_zone == 1 && arg0->active != 0) {
                    var_t4 = 1;
                }
            }
            break;
        case 1:
            if (!var_t3) {
                if (arg0->not_in_zone == 0 && arg0->active != 0) {
                    var_t4 = 1;
                }
            }
            break;
        case 2:
            if (var_t3) {
                if (arg0->active != 0) {
                    var_t4 = 1;
                }
            }
            break;
    }
    if (var_t4 != 0) {
        if (func_global_asm_807318AC(D_global_asm_8076A0AA, arg0->raw.unkA) == 0) {
            var_t4 = 0;
        }
    }
    if (var_t3 != 0) {
        arg0->not_in_zone = 0;
    } else {
        arg0->not_in_zone = 1;
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
