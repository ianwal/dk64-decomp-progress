#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// Doable, big, interesting
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C1E70/func_806BD170.s")

void func_80677FA8(s32, s32);
extern s8 D_80750660;
extern s8 D_807506A4;
extern s8 D_807FC8D0;

// TODO: Add to aaD union
typedef struct {
    s16 unk0;
    s8 unk2; // keyIndex
    s8 unk3;
    Actor *unk4;
} PadlockAAD;

/*
void func_806BD170(void) {
    PadlockAAD *temp_v0;
    s8 keyIndex;
    s16 sp50;
    s16 temp_s2;

    sp50 = -1;
    for (keyIndex = 0; keyIndex < 8; keyIndex++) {
        // Key[keyIndex] Turned Flag
        if (!isFlagSet(0x1BC + keyIndex, FLAG_TYPE_PERMANENT)) {
            // Spawn Padlock
            func_80677FA8(0x14E, 0xCD);
            temp_s2 = 260 + (keyIndex * 512);
            D_807FBB44->draw_distance = 2000;
            D_807FBB44->object_properties_bitfield |= 0x800400;
            D_807FBB44->object_properties_bitfield &= ~0x8000;
            D_807FBB44->unk16A = 0xFF;
            D_807FBB44->unk16B = 0xFF;
            D_807FBB44->unk16C = 0xFF;
            D_807FBB44->shadow_opacity = 0xFF;
            D_807FBB44->x_position = (func_80612794(temp_s2) * 270.0f) + current_actor_pointer->x_position;
            D_807FBB44->z_position = (func_80612790(temp_s2) * 270.0f) + current_actor_pointer->z_position;
            D_807FBB44->y_position = 100.0f;
            D_807FBB44->y_rotation = temp_s2;
            D_807FBB44->unk146 = 0;
            D_807FBB44->control_state = 0;
            temp_v0 = D_807FBB44->additional_actor_data;
            temp_v0->unk0 = 0;
            temp_v0->unk2 = keyIndex;
            temp_v0->unk4 = current_actor_pointer;
            // Key Collected Flag
            if (isFlagSet(D_80744710[keyIndex], FLAG_TYPE_PERMANENT)) {
                sp50 = keyIndex;
                D_807FBB44->control_state = 5;
            }
        }
    }
    D_807506A4 = 0;
    // Isles: Japes Boulder Smashed
    if (!isFlagSet(0x1BB, FLAG_TYPE_PERMANENT)) {
        sp50 = -1;
    }
    if ((D_80750660 == 0) && (sp50 != -1)) {
        D_807FBB44->unk146 = 1;
        D_807FBB44->control_state = 1;
        D_80750660 = 1;
        D_807FC8D0 = sp50;
    }
}
*/

// Doable, big, interesting
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C1E70/func_806BD3E4.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C1E70/func_806BD7B0.s")

s32 areAllKeysTurnedIn() {
    s32 key;
    for (key = 0; key < 8; key++) {
        if (!isFlagSet(key + 0x1BC, FLAG_TYPE_PERMANENT)) {
            return FALSE;
        }
    }
    return TRUE;
}