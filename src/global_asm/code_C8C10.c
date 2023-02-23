#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C3F10.s")

void func_806C43A8() {
    s32 song = 0;
    switch(current_map) {
        case MAP_JAPES_MINECART:
            song = 3;
            break;
        case MAP_CASTLE_MINECART:
            song = 0x6A;
            break;
        case MAP_FUNGI_MINECART:
            song = 0x4A;
    }
    if (song != 0) {
        playSong(song, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C4414.s")

void func_806C4904() {
    func_806C4414(0, 1, 2, 0xF, 0x10, 0x32, 0x18);
}

void func_806C4948() {
    func_806C4414(6, 7, 8, 0x10, 0xE, 0x32, 0xD7);
}

void func_806C498C() {
    func_806C4414(1, 2, 3, 4, 5, 0x19, 0x13E);
}

void func_806C49D0() {
    func_80729B00();
    switch(current_map) {
        case MAP_AZTEC:
            func_806C3F10(2, 6, 0);
            break;
        case MAP_JAPES_MINECART:
            func_806C4904();
            break;
        case MAP_FUNGI_MINECART:
            func_806C4948();
            break;
        case MAP_CASTLE_MINECART:
            func_806C498C();
            break;
        case MAP_FUNGI:
            if (D_807FDC9C[0].unk13 == 6) {
                func_806C3F10(2, 7, 0x1A);
            } else {
                func_806C3F10(2, 3, 0);
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C4AC4.s")

void func_806C4E8C(void) {
    func_806FB370(5, 0, 0);
}

void func_806C4EB4() {
    func_8063DA40(0x2C, 0xB);
    func_806C4E8C();
}

void func_806C4EE0(u8 arg0, u8 arg1) {
    D_807FDC90[0].unk2E = 0;
    func_8070E8DC(1);
    func_8070D8C0(current_actor_pointer, 0xF, arg0);
    current_actor_pointer->control_state = 0x29;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->unk168 = arg1;
    current_actor_pointer->unkF0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C4F5C.s")

void func_806C55D8(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C55E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C5C20.s")

// Doable, nice size too
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C5FEC.s")

// ? func_80602B60(?, ?);                              /* extern */
// ? func_8061CB08(Actor *);                           /* extern */
// ? func_806319C4(Actor *, ?);                        /* extern */
void func_80659670(f32, f32, void *, s32 *, s32, s16); /* extern */
// ? func_8070D8C0(Actor *, ?, ?);                     /* extern */

/*
// TODO: Very close!
void func_806C5FEC(void) {
    PlayerAdditionalActorData *temp_a0;
    YetAnotherAdditionalActorData5 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_v1->unk1C = 0;
        current_actor_pointer->object_properties_bitfield |= 0x400;
    }
    temp_v1->unk1C++;
    switch (temp_v1->unk1E) {
    case 1:
        if (player_pointer->control_state_progress == 3) {
            func_8070D8C0(current_actor_pointer, 0x1E, 3);
            temp_v1->unk1E = 2;
        } else if (temp_v1->unk10->control_state != 0x83) {
            temp_v1->unk1E = 3;
        }
        break;
    case 2:
        if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
            temp_v1->unk1E = 3;
            func_8061CB08(current_actor_pointer);
        }
        break;
    default:
        if (temp_v1->unk10->control_state != 0x83) {
            temp_a0 = temp_v1->unk10->PaaD;
            temp_a0->unk1F4 &= ~0x10;
            temp_v1->unk10->object_properties_bitfield &= 0xBFFFFFFF;
            temp_v1->unk10->object_properties_bitfield |= 1;
            temp_v1->unk10->z_rotation = temp_v1->unk16;
            temp_v1->unk10->x_rotation = temp_v1->unk14;
            global_properties_bitfield |= 0x10030;
            func_80659670(temp_v1->unk0, temp_v1->unk4, temp_a0, &global_properties_bitfield, temp_v1->unk8, temp_v1->unk1A);
            func_80602B60(0x3B, 0);
            func_806782C0(temp_v1->unkC);
            func_806782C0(current_actor_pointer);
            return;
        }
        break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C61C8.s")
