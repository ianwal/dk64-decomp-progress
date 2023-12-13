#include <ultra64.h>
#include "functions.h"

extern s8 D_global_asm_80750660;
extern s8 D_global_asm_807506A4;

extern s8 D_global_asm_807FC8D0;

// TODO: Add to aaD union
typedef struct {
    s16 unk0;
    s8 unk2; // keyIndex
    s8 unk3;
    Actor *unk4;
} PadlockAAD;

void func_global_asm_806BD170(void) {
    Actor* highest_priority_padlock;
    s16 keyIndex;
    s16 sp50;
    s16 keysCollected;

    sp50 = -1;
    keyIndex = 0;
    keysCollected = 0;
    while (keyIndex < 8) {
        // Key[keyIndex] Turned Flag
        if (!isFlagSet(0x1BC + keyIndex, FLAG_TYPE_PERMANENT)) {
            PadlockAAD *temp_v0;
            s16 temp2 = 260 + (keyIndex * 512);
            // Spawn Padlock
            func_global_asm_80677FA8(ACTOR_PADLOCK_KLUMSY, 0xCD);
            D_global_asm_807FBB44->draw_distance = 2000;
            D_global_asm_807FBB44->object_properties_bitfield |= 0x800400;
            D_global_asm_807FBB44->object_properties_bitfield &= ~0x8000;
            
            D_global_asm_807FBB44->unk16A = 0xFF;
            D_global_asm_807FBB44->unk16B = 0xFF;
            D_global_asm_807FBB44->unk16C = 0xFF;
            D_global_asm_807FBB44->shadow_opacity = 0xFF;

            D_global_asm_807FBB44->x_position = (func_global_asm_80612794(temp2) * 270.0f) + current_actor_pointer->x_position;
            D_global_asm_807FBB44->z_position = (func_global_asm_80612790(temp2) * 270.0f) + current_actor_pointer->z_position;
            D_global_asm_807FBB44->y_position = 100.0f;
            D_global_asm_807FBB44->y_rotation = temp2;
            D_global_asm_807FBB44->unk146 = 0;
            D_global_asm_807FBB44->control_state = 0;
            temp_v0 = D_global_asm_807FBB44->additional_actor_data;
            temp_v0->unk0 = 0;
            temp_v0->unk4 = current_actor_pointer;
            temp_v0->unk2 = keyIndex;
            // Key Collected Flag
            if (isFlagSet(D_global_asm_80744710[keyIndex], FLAG_TYPE_PERMANENT)) {
                sp50 = keyIndex;
                highest_priority_padlock = D_global_asm_807FBB44;
                highest_priority_padlock->control_state = 5;
                keysCollected++;
            }
        }
        keyIndex++;
    }
    D_global_asm_807506A4 = 0;
    // Isles: Japes Boulder Smashed
    if (!isFlagSet(0x1BB, FLAG_TYPE_PERMANENT)) {
        sp50 = -1;
    }
    if (!D_global_asm_80750660) {
        s32 temp = 1;
        if (sp50 != -1) {
            highest_priority_padlock->unk146 = temp;
            highest_priority_padlock->control_state = 1;
            D_global_asm_80750660 = 1;
            D_global_asm_807FC8D0 = sp50;
        }
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C1E70/func_global_asm_806BD3E4.s")

extern s8 D_global_asm_807506B4;
extern s8 D_global_asm_807506A8[];

extern s16 D_global_asm_8076A0A6; // Probably static

extern f32 D_global_asm_807FC8D4;

s32 areAllKeysTurnedIn(void);

typedef struct {
    Actor* unk0;
} Actor178_806BD3E4;

/*
void func_global_asm_806BD3E4(void) {
    Actor178_806BD3E4 *sp34;
    s32 sp30;
    s32 sp2C;
    u8 sp2B;
    u8 temp;
    u16 sp28;
    s16 var_v1; // Probably static
    s16 var_t0;

    var_v1 = D_global_asm_8076A0A6;
    sp34 = current_actor_pointer->unk178;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (areAllKeysTurnedIn()) {
            current_actor_pointer->control_state = 0x40;
            return;
        }
        current_actor_pointer->draw_distance = 2000;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        var_v1 = 0;
        D_global_asm_807506B4 = 0;
        func_global_asm_80677FA8(ACTOR_KLUMSY_CAGE, 0xC4);
        func_global_asm_8067B238(D_global_asm_807FBB44, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
        D_global_asm_807FBB44->unk64 |= 0x20;
        D_global_asm_807FBB44->object_properties_bitfield |= 0x400;
        D_global_asm_807FBB44->draw_distance = 0x7D0;
        sp34->unk0 = D_global_asm_807FBB44;
        D_global_asm_807FC8D4 = 1000.0f;
        func_global_asm_806BD170();
        current_actor_pointer->control_state = 0;
        if (D_global_asm_80750660 != 0) {
            D_global_asm_80750660 = 0;
        }
        if (isFlagSet(0x1BB, FLAG_TYPE_PERMANENT) == 0) {
            current_actor_pointer->control_state = 1;
        }
    }
    var_t0 = -1;
    if (var_v1) {
        var_t0 = 0;
        while (!(var_v1 & 1)) {
            var_v1 >>= 1;
            var_t0++;
        }
    }
    D_global_asm_807FC8D4 = ((current_actor_pointer->x_position - player_pointer->x_position) * (current_actor_pointer->x_position - player_pointer->x_position)) + ((current_actor_pointer->z_position - player_pointer->z_position) * (current_actor_pointer->z_position - player_pointer->z_position));
    sp28 = 0;
    switch (current_actor_pointer->control_state) {
        case 1:
            func_global_asm_80614EBC(current_actor_pointer, 0x2EF);
            current_actor_pointer->control_state = 2;
            playCutscene(player_pointer, 2, 1);
            break;
        case 2:
            if (func_global_asm_80629148()) {
                playSong(0x7D, 1.0f);
                func_global_asm_80614EBC(current_actor_pointer, 0x2F1);
                current_actor_pointer->control_state = 3;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 3:
            if (current_actor_pointer->control_state_progress & 1) {
                current_actor_pointer->control_state_progress++;
                sp2B = 0xF;sp28 = 0x28;
            }
            break;
    }
    if ((func_global_asm_8061CB50() == 0) && (current_actor_pointer->animation_state->unk64 != 0x2F0)) {
        func_global_asm_80614EBC(current_actor_pointer, 0x2F0);
    }
    if (sp28) {
        func_global_asm_8061F0B0(D_global_asm_807F5D10, sp2B, sp28);
    }
    if (var_t0 >= 0) {
        if (var_t0 == D_global_asm_807506A8[D_global_asm_807506B4]) {
            if (D_global_asm_807506A8[++D_global_asm_807506B4] == -1) {
                playSound(0x1DA, 0x7FFF, 63.0f, 1.0f, 5, 0);
                setFlag(0x28, TRUE, FLAG_TYPE_GLOBAL);
                setFlag(0x26, TRUE, FLAG_TYPE_GLOBAL);
                D_global_asm_807506B4 = -1;
            }
        } else {
            D_global_asm_807506B4 = 0;
        }
    }
    D_global_asm_8076A0A6 = 0;
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C1E70/func_global_asm_806BD7B0.s")

s32 areAllKeysTurnedIn(void) {
    s32 key;
    for (key = 0; key < 8; key++) {
        if (!isFlagSet(key + 0x1BC, FLAG_TYPE_PERMANENT)) {
            return FALSE;
        }
    }
    return TRUE;
}
