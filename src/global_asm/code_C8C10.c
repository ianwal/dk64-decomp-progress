#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C3F10.s")

extern f32 D_8075C260;
extern f32 D_8075C264;
extern f32 D_8075C268;
extern s32 D_807F5D10;

void func_8061C518(s32, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_8061C464(s32, Actor *, s32, s16, s32, s32, s32, s32, s32, s32, f32);
void func_806B49B0(u8 arg0, s16 arg1, s16 arg2);

/*
// TODO: Close...
void func_806C3F10(u8 arg0, u8 arg1, u8 arg2) {
    Actor178 *var_v1;
    // s16 temp_v0;
    s32 var_v0;

    var_v1 = current_actor_pointer->unk178;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FDC98->unk46 |= 0x20;
        if (arg2 != 0) {
            playCutscene(current_actor_pointer, arg2, 1);
        } else {
            func_8061C518(D_807F5D10, current_actor_pointer, 4, 0x800, 0x19, 0, 0xA, 0x14, 0xC, 0, D_8075C260);
        }
        D_807FDC9C->unk10 = 0x27;
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
    }
    var_v1->unk0 = MAX(0, D_807FDC90->unkC - D_807FDC9C->unk6);
    // temp_v0 = D_807FDC90->unkC - D_807FDC9C->unk6;
    // if (temp_v0 < 0) {
        // var_v1->unk0 = 0;
    // } else {
        // var_v1->unk0 = temp_v0;
    // }
    switch (current_actor_pointer->control_state) {
        case 39:
            if ((D_807FDC90->unk1A & 4) && (arg0 == (D_807FDC90->unk25 & 0x7F))) {
                if (character_change_array->unk2C0 == 0) {
                    func_8070D8C0(current_actor_pointer, 0x10, 1, current_actor_pointer);
                    current_actor_pointer->control_state = 0x29;
                    current_actor_pointer->control_state_progress = 0;
                    D_807FDC9C->unk10 = 0x29;
                    extra_player_info_pointer->unk1F0 |= 0x10000;
                    func_806EB0C0(0x54, NULL, 0);
                    D_807FDC90->unk1A |= 0x8000;
                } else {
                    func_8070D8C0(current_actor_pointer, 0x10, 0, current_actor_pointer);
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    D_807FDC9C->unk10 = 0x28;
                    if (arg2 == 0) {
                        func_8061C464(D_807F5D10, current_actor_pointer, 4, 0x800, 0x19, 0, 0xA, 0x14, 0xC, 0x78, D_8075C264);
                    }
                }
            }
            // fallthrough
        case 40:
            func_806B49B0(2, 0x23D, 0x23E);
            return;
        case 38:
        case 41:
            if (D_807FDC90->unk1A & 0x8000) {
                if ((D_807FDC90->unk1A & 4) && (arg1 == (D_807FDC90->unk25 & 0x7F))) {
                    if (arg2 == 0) {
                        func_806225C0(D_807F5D10);
                    }
                    playCutscene(player_pointer, 3, 5);
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    D_807FDC9C->unk10 = 0x28;
                    extra_player_info_pointer->unk1F0 &= 0xFFFEFFFF;
                    D_807FDC90->unk1A &= 0x7FFF;
                } else {
                    if (arg2 == 0) {
                        func_8061C464(D_807F5D10, player_pointer, 4, object_timer * 0x14, 0x1E, 0, 0xA, 0x1E, 0xC, 0, D_8075C268);
                    }
                    player_pointer->y_rotation = current_actor_pointer->y_rotation;
                    player_pointer->x_position = current_actor_pointer->x_position;
                    player_pointer->y_position = current_actor_pointer->y_position - 2.0f;
                    player_pointer->z_position = current_actor_pointer->z_position;
                    player_pointer->unk6A &= 0xFFFE;
                    player_pointer->locked_to_pad = 0;
                }
            }
            if (current_actor_pointer->control_state == 0x26) {
                var_v0 = 0x26;
            } else {
                var_v0 = 2;
            }
            func_806B49B0(var_v0, 0x23D, 0x23E);
            // fallthrough
        case 0:
            return;
    }
}
*/


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
            if (D_807FDC9C->unk13 == 6) {
                func_806C3F10(2, 7, 0x1A);
            } else {
                func_806C3F10(2, 3, 0);
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}

// Actor->180???
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C4AC4.s")

void func_806C4E8C(void) {
    func_806FB370(5, 0, 0);
}

void func_806C4EB4() {
    func_8063DA40(0x2C, 0xB);
    func_806C4E8C();
}

void func_806C4EE0(u8 arg0, u8 arg1) {
    D_807FDC90->unk2E = 0;
    func_8070E8DC(1);
    func_8070D8C0(current_actor_pointer, 0xF, arg0);
    current_actor_pointer->control_state = 0x29;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->unk168 = arg1;
    current_actor_pointer->unkF0 = 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C4F5C.s")

void func_806C55D8(void) {

}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C55E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_806C5C20.s")

void func_80659670(f32, f32, f32, s16);

void func_806C5FEC(void) {
    YetAnotherAdditionalActorData5 *temp_v1;
    PlayerAdditionalActorData *temp_a0;

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
                func_8061CB08();
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
                func_80659670(temp_v1->unk0, temp_v1->unk4, temp_v1->unk8, temp_v1->unk1A);
                func_80602B60(0x3B, 0);
                func_806782C0(temp_v1->unkC);
                func_806782C0(current_actor_pointer);
                return;
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806C61C8(void) {
    f32 sp24;
    f32 sp20;
    f32 temp_f0;
    f32 var_f18;
    s16 temp_v0;
    s16 var_v0;
    u8 temp_t2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEC = 0x3C;
        func_80614EBC(current_actor_pointer, 0x23D);
        if (player_pointer->control_state == 0xC) {
            func_80614E78(player_pointer, 0x87);
        }
    }
    sp24 = (func_80612794(player_pointer->y_rotation) * 50.0f) + player_pointer->x_position;
    sp20 = (func_80612790(player_pointer->y_rotation) * 50.0f) + player_pointer->z_position;
    current_actor_pointer->y_rotation = (player_pointer->y_rotation + 0x800) & 0xFFF;
    if (current_actor_pointer->unkEC == 0x3C) {
        current_actor_pointer->x_position = (func_80612794(current_actor_pointer->unkEE) * 10.0f) + sp24;
        current_actor_pointer->z_position = (func_80612790(current_actor_pointer->unkEE) * 10.0f) + sp20;
    }
    current_actor_pointer->y_position = (func_80612794(object_timer * 0x64) * 5.0f) + (current_actor_pointer->unk15F + player_pointer->y_position + 3.0f + current_actor_pointer->unkEC);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (current_actor_pointer->unkF0 != 0) {
            current_actor_pointer->unk15F = 0x14;
            func_8069E490(0x2D, func_8073195C(current_actor_pointer->unkF0));
        }
    }
    if (current_actor_pointer->unkF0 != 0) {
        func_8069E4E0(-0x1E);
    }
    current_actor_pointer->unkEE += 60.0f * func_80612794(object_timer * 0x32);
    if (current_actor_pointer->object_properties_bitfield & 0x02000000) {
        current_actor_pointer->unk168 = 0x14;
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
    }
    if (current_actor_pointer->unk168 == 0) {
        current_actor_pointer->unkEC++;
        if (current_actor_pointer->unkEC >= 0x3D) {
            if (current_actor_pointer->unkF0 != 0) {
                func_8069E5B8();
            }
            func_806782C0(current_actor_pointer);
            func_8061CB08();
            if (player_pointer->control_state == 0xC) {
                func_80614E78(player_pointer, 9);
            }
        }
    } else {
        if (current_actor_pointer->unkEC >= 0x10) {
            current_actor_pointer->unkEC--;
        }
    }
    func_806319C4(current_actor_pointer, 0);
}
