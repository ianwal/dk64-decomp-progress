#include "common.h"

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
} GlobalASMStruct50;

extern MapSongData D_global_asm_80745BDC[];
extern GlobalASMStruct50 D_global_asm_80746340[];

s16 func_global_asm_8060A7C0(s16 arg0, Actor *arg1, u8 arg2) {
    s32 phi_v1;
    s32 i;

    i = 0;
    phi_v1 = FALSE;
    while (i < 0xE && !phi_v1) {
        if ((arg0 == D_global_asm_80746340[i].unk0) && (arg2 == D_global_asm_80746340[i].unk2)) {
            phi_v1 = TRUE;
        } else {
            i++;
        }
    }
    if (phi_v1) {
        if (((gCurrentActorPointer->interactable & 1)) && (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 2)) {
            return 0x97;
        }
        if ((arg1->unk6A & 4) != 0) {
            return 0xA;
        }
        if (!D_global_asm_80746340[i].unk4) {
            return D_global_asm_80745BDC[current_map].default_output_floor_sfx;
        }
        return D_global_asm_80746340[i].unk4;
    }
    return arg0;
}
