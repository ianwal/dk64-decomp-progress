#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// Footstep SFX?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F4C0/func_8060A7C0.s")

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
} GlobalASMStruct50;

extern s16 D_80745BDE[];
extern GlobalASMStruct50 D_80746340[];

/*
// TODO: Pretty close... Hmm.
s16 func_8060A7C0(s16 arg0, Actor *arg1, u8 arg2) {
    s32 phi_v1;
    s32 i;

    phi_v1 = FALSE;
    for (i = 0; i < 0xE; i++) {
        if ((arg0 == D_80746340[i].unk0) && (arg2 == D_80746340[i].unk2)) {
            phi_v1 = TRUE;
            break;
        }
    }
    if (phi_v1) {
        if (((current_actor_pointer->interactable & 1)) && (character_change_array[extra_player_info_pointer->unk1A4].unk2C0 == 2)) {
            return 0x97;
        }
        if ((arg1->unk6A & 4) != 0) {
            return 0xA;
        }
        if (!D_80746340[0].unk4) {
            return D_80745BDE[current_map * 2];
        }
        return D_80746340[0].unk4;
    }
    return arg0;
}
*/
