#include <ultra64.h>
#include "functions.h"

void func_global_asm_80676D00(Actor *arg0, Actor *arg1, s32 arg2, s32 arg3) {
    u8 temp_a2;
    PlayerAdditionalActorData *temp_v0;

    if (arg1 == player_pointer) {
        temp_v0 = arg1->PaaD;
        temp_a2 = temp_v0->unk1A4;
        arg1->PaaD->unk1F0 |= 0x80000;
        if (temp_v0->unkD4 == 0) {
            if (player_pointer->control_state != 0x36) {
                if (func_global_asm_806EB400(player_pointer) != 0) {
                    if (player_pointer->unk58 == ACTOR_CHUNKY && character_change_array[temp_a2].unk2C0 == 2) {
                        if (player_pointer->control_state != 0x31) {
                            if (arg0->interactable & 0x80) {
                                playSoundAtPosition(arg1->x_position, arg1->y_position, arg1->z_position, 0x1E0, 0xFF, 0x64, 0x1E, 0, 0.3f, 0);
                            }
                        }
                        return;
                    }
                    if (arg0->unk58 == ACTOR_KLUMP) {
                        playSoundAtPosition(arg1->x_position, arg1->y_position, arg1->z_position, 0x37, 0xFF, 0x7F, 0x1E, 0x5A, 0.3f, 0);
                        return;
                    }
                    playSoundAtPosition(arg1->x_position, arg1->y_position, arg1->z_position, 0x1E0, 0xFF, 0x7F, 0x1E, 0x5A, 0.3f, 0);
                }
            }
        }
    }
}
