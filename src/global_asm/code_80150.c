#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_80612794(s32);
void func_8065D254(Actor*, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_80665564(Actor*, f32);
void func_8067AAB8(Actor* arg0, s32 arg1, s16 arg2, f32 arg3, s16 arg4);
void func_8067ACB4(Actor*);
void func_8067DF44(f32, f32, f32, f32, u8, u8);
void func_80683AD8();

extern f64 D_80759560;
extern s32 D_8071FC8C;

typedef struct {
    u16 unk0;
    u8 unk2; // Actor Spawner ID
    u8 unk3;
    s16 unk4; // Permanent Flag Index
} GlobalASMStruct47;

extern GlobalASMStruct47 D_8074E7A0[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067B450.s")

/*
// Don't know what this needs, our stack is too big though
u8 func_8067B450(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((current_map == D_8074E7A0[i].unk0) && (func_80688E68(4) == D_8074E7A0[i].unk2)) {
            return isFlagSet(D_8074E7A0[i].unk4, FLAG_TYPE_PERMANENT);
        }
    }  
    return 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067B4C8.s")

void func_8067BA3C() {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 2000;
    }
    func_8067B4C8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067BA7C.s")

void func_8067BC68(void) {
    func_8067BA7C(0x13);
}

void func_8067BC88(void) {
    func_8067BA7C(0x13);
}

void func_8067BCA8(void) {
    func_8067BA7C(0x13);
}

void func_8067BCC8(void) {
    func_8067BA7C(0x13);
}

void func_8067BCE8(void) {
    func_8067BA7C(0x13);
}

void func_8067BD08(void) {
    func_8067BA7C(0x13);
}

void func_80689114(s32, f32, f32, f32, s32, f32, Actor *);
extern u8 D_807FBBA8;

void func_8067BD28(void) {
    s32 phi_v1;
    PlayerAdditionalActorData *PaaD = player_pointer->PaaD;

    phi_v1 = FALSE;
    if (D_807FBBA8 && (PaaD->unk1F0 & 0x200000)) {
        phi_v1 = TRUE;
    }
    if (((current_actor_pointer->object_properties_bitfield & 0x10) == 0) || (phi_v1 != 0)) {
        func_80689114(0x55, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 1.0f, current_actor_pointer);
    }
}

void func_80665564(Actor*, f32);

void func_8067BDB8() {
    func_8067BA7C(0x95);
    func_80665564(current_actor_pointer, 0.0f);
    current_actor_pointer->y_position = current_actor_pointer->floor;
}

void func_8067BDF8() {
    s8 sp1F;
    s32 temp_a1;

    sp1F = 0;
    // TODO: Which aaD type are they actually expecting here?
    temp_a1 = current_actor_pointer->PaaD;
    func_8067BF84(0x13, temp_a1, temp_a1 + 1, &sp1F);
}

// Doable, needs some solid aaD knowledge though
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067BE30.s")

void func_8067BF4C() {
    s32 temp_v0;

    // TODO: Which aaD type are they actually expecting here?
    temp_v0 = current_actor_pointer->PaaD;
    func_8067BF84(0x1A, temp_v0 + 2, temp_v0 + 3, temp_v0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067BF84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067C2B8.s")

void func_8067C67C(void) {
    func_8067C71C();
}

void func_8067C69C(void) {
    func_8067C71C();
}

void func_8067C6BC(void) {
    func_8067C71C();
}

void func_8067C6DC(void) {
    func_8069B908();
}

void func_8067C6FC(void) {
    func_8067C71C();
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067C71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067DCC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067DF44.s")

void func_8067E278(u8 arg0, u8 arg1) {
    func_8067DF44(current_actor_pointer->x_position,
                  current_actor_pointer->y_position,
                  current_actor_pointer->z_position,
                  current_actor_pointer->animation_state->scale_y / D_80759560,
                  arg0,
                  arg1);
}

void func_8067E2E4(s32 arg0, u8 arg1, f32 arg2) {
    f32 sp2C, sp28, sp24;

    func_80671C0C(current_actor_pointer, arg1, &sp2C, &sp28, &sp24);
    func_8067DF44(sp2C, sp28, sp24, arg2, 0, 1);
}

void func_8067E348(void) {
    OtherAdditionalActorData *temp_v0;

    temp_v0 = current_actor_pointer->OaaD;
    current_actor_pointer->animation_state->scale_x = temp_v0->unkC;
    current_actor_pointer->animation_state->scale_y = temp_v0->unkC;
    current_actor_pointer->animation_state->scale_z = temp_v0->unkC;
    current_actor_pointer->y_position = temp_v0->unk14;
    temp_v0->unk8 = 0;
    temp_v0->unk18 = 0;
    temp_v0->unk10 = temp_v0->unkC;
    current_actor_pointer->control_state = 0;
    current_actor_pointer->noclip_byte = 2;
    current_actor_pointer->object_properties_bitfield &= ~0x200000;
}

void func_8067E3D0(void) {
    func_8067E348();
    current_actor_pointer->control_state = 0x14;
    current_actor_pointer->noclip_byte = 1;
    current_actor_pointer->object_properties_bitfield &= ~0x8000;
    current_actor_pointer->shadow_opacity = 0;
    func_806F8D58(5, 0);
}

// Might use CharacterChange ptr
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067E43C.s")

void func_8067E4D4() {
    func_8067E784();
    if (current_actor_pointer->control_state == 0) {
        func_8067E43C();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067E510.s")

void func_8067E69C() {
    func_8067E784();
    func_8067E43C();
}

void func_8067E6C4() {
    func_8067E784();
}

void func_8067E6E4() {
    func_8067E784();
}

void func_8067E704() {
    func_8067E784();
}

void func_8067E724() {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->draw_distance = 800;
    }
    func_8067E784();
}

void func_8067E764(void) {
    func_8067E784();
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067E784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067FAC8.s")

/*
// TODO: Doable, but fiddly, good clues on D_807FBB70 shape
void func_8067FAC8(void) {
    s16 phi_s0;

    for (phi_s0 = 0; phi_s0 < D_807FBB70[0].unk254; phi_s0++) {
        if ((D_807FBB70[phi_s0].unk258 == 1) && (D_807FBB70[phi_s0].unk278 == 1)) {
            func_8067DCC0();
            func_806782C0(current_actor_pointer);
        }
    }
}
*/

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8067FB6C.s")

void func_80680774(void) {
    if ((character_change_array->unk2C0 != 1) || (((extra_player_info_pointer->unk1F4 & 0x40) != 0)) || (((current_character_index[0] >= 5)))) {
        current_actor_pointer->unk132 = 4;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        current_actor_pointer->shadow_opacity = 0x7F;
    } else if ((character_change_array->unk2C0 == 1) && ((extra_player_info_pointer->unk1F0 & 0x40) == 0) && (current_character_index[0] < 5)) {
        current_actor_pointer->object_properties_bitfield |= 0x8000;
        current_actor_pointer->unk132 = 1;
    }
    if (extra_player_info_pointer->unkCA != 0) {
        current_actor_pointer->unk132 = 4;
    }
}

void func_8068086C() {
    if (current_character_index[0] >= 5) {
        current_actor_pointer->unk132 = 4;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        current_actor_pointer->shadow_opacity = 0x7F;
    } else {
        current_actor_pointer->object_properties_bitfield |= 0x8000;
        current_actor_pointer->unk132 = 1;
    }
    if (extra_player_info_pointer->unkCA != 0) {
        current_actor_pointer->unk132 = 4;
    }
}

u8 func_80680908(void) {
    u8 phi_v1 = 0x64;
    switch (current_map) {
        case MAP_FACTORY:
            if (func_80688E68(current_actor_pointer) == 0xD
            || func_80688E68(current_actor_pointer) == 0xF) {
                phi_v1 = 2;
            }
            break;
        case MAP_FUNGI_DK_BARN:
            if (func_80688E68(current_actor_pointer) == 3) {
                phi_v1 = 2;
            }
            break;
        case MAP_FUNGI:
            if (func_80688E68(current_actor_pointer) == 0x12) {
                phi_v1 = 2;
            }
            break;
        case MAP_AZTEC_LOBBY:
        case MAP_DK_ISLES_SNIDES_ROOM:
            phi_v1 = 2;
            break;
    }
    return phi_v1;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_806809F0.s")

// Doable and interesting, reading which flag to set from an array
// Just needs some patience, energy, and a defintion for unkD in an aaD
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80681B14.s")

// Similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80681BD8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80681E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_806822FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80682AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80682DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80682E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_8068304C.s")

/*
extern ? D_8074E834;

void func_8068304C(void) {
    ? sp2C;
    void *sp28;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        sp2C.unk0 = D_8074E834.unk0;
        sp2C.unk4 = D_8074E834.unk4;
        sp2C.unk8 = D_8074E834.unk8;
        sp2C.unkC = D_8074E834.unkC;
        sp2C.unk10 = D_8074E834.unk10;
        sp28 = current_actor_pointer->additional_actor_data;
        current_actor_pointer->object_properties_bitfield |= 0x1000;
        func_8068842C(current_actor_pointer, 0, 1);
        func_80688460(current_actor_pointer, 0, 1);
        func_806883F4(current_actor_pointer, 0, (sp + (*sp28 * 4))->unk2E, 0);
        func_80614EBC(current_actor_pointer, 0x329);
    }
    current_actor_pointer->unk16D = current_actor_pointer->unk15F;
    current_actor_pointer->y_rotation += 0x32;
    current_actor_pointer->y_rotation &= 0xFFF;
    func_806319C4(current_actor_pointer, 0);
}
*/

// Function pointer in a local variable, needs some PaaD untangling
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80683158.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_806832F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_806833DC.s")

/*
// Needs some PaaD untangling I think
// Switch case for control_state_progress?
void func_806833DC(YetAnotherAdditionalActorData *arg0) {
    void *sp34;
    void *sp30;
    s32 sp28;
    s32 sp20;
    s16 temp_v0_3;
    s16 temp_v0_4;
    u16 temp_v0_2;
    u8 temp_v0;
    Actor *temp_a0;
    void *temp_a1;
    Actor *temp_t1;
    void *temp_v0_5;
    s32 phi_v0;
    s32 phi_a1;

    temp_v0 = current_actor_pointer->control_state_progress;
    if (temp_v0 != 0) {
        if (temp_v0 != 1) {
            if (temp_v0 != 0xA) {
                if ((temp_v0 == 0xB) && (func_8061CB50(&current_actor_pointer) == 0)) {
                    current_actor_pointer->noclip_byte = 2;
                    current_actor_pointer->control_state_progress = 0;
                }
            } else {
                goto block_6;
            }
        } else {
            temp_v0_2 = arg0->unk4;
            if (temp_v0_2 != 0) {
                arg0->unk4 = temp_v0_2 - 1;
                return;
            }
            temp_a0 = arg0->unk0;
            temp_v0_3 = temp_a0->unk12C;
            temp_a1 = temp_a0->unk174;
            phi_v0 = temp_v0_3;
            if (temp_v0_3 == -1) {
                phi_v0 = 0;
            }
            sp28 = phi_v0;
            sp34 = temp_a0;
            sp30 = temp_a1;
            func_806C93E4(temp_a0, temp_a1, &current_actor_pointer);
            func_806C9304(arg0->unk0, temp_a1);
            sp20 = phi_v0;
            func_80659620(&arg0->unk2C, &arg0->unk30, &arg0->unk34, phi_v0);
            func_80659670(1.0f, 1.0f, 1.0f, sp20);
            current_actor_pointer->y_rotation = arg0->unk22;
            current_actor_pointer->noclip_byte = 1;
            temp_v0_4 = sp34->unk5A;
            global_properties_bitfield &= 0xFFFCFFCF;
            arg0->unk6 = 0;
            if (temp_v0_4 != (&D_8074E814 + (arg0->unk6 * 6))->unk2) {
                do {
                    arg0->unk6 = arg0->unk6 + 1;
                } while (temp_v0_4 != (&D_8074E814 + (arg0->unk6 * 6))->unk2);
            }
            arg0->unk7 = arg0->unk6;
            phi_a1 = arg0->unk6;
            if (current_map != MAP_HELM) {
                playSong(0x65, 1.0f);
                func_80602CE0(0x65, 0x7E - *(&D_8074E848 + (arg0->unk6 * 4)), 1);
                phi_a1 = arg0->unk6;
            }
            setFlag(func_805FF018(current_actor_pointer->unk58, phi_a1), TRUE, FLAG_TYPE_PERMANENT);
            func_80682E38(arg0);
            func_80627878(sp30->unk104);
            arg0->unk38 = sp34->unkE6;
            sp34->unkE6 = current_actor_pointer->y_rotation;
            func_8060DEC8(); // saveTheGame()
            playCutscene(current_actor_pointer, 0xE, 0xC);
            func_8061B650(sp30->unk104);
            func_806FB218();
            current_actor_pointer->control_state = 1;
            current_actor_pointer->control_state_progress = 0;
        }
    } else {
block_6:
        if (D_807FBB70->unk200 == 4) {
            temp_t1 = D_807FBB70->unk1FC;
            arg0->unk0 = temp_t1;
            temp_t1->unk144 = 1;
            temp_v0_5 = arg0->unk0->unk174;
            temp_v0_5->unk1F0 |= 0x20000000;
            current_actor_pointer->control_state_progress = 1;
            arg0->unk4 = 2;
            arg0->unk3C = 0;
        }
    }
}
*/

// Doable, might need some structs?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_806836D0.s")

// Doable, needs some structs
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80683A80.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_80683AD8.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4; // Used
    u8 unk5;
} GlobalASMStruct45;

extern GlobalASMStruct45 D_8074E814[];

void func_8068408C(Actor *arg0) {
    s32 kongIndex;

    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        if (isFlagSet(func_805FF018(arg0->unk58, kongIndex), FLAG_TYPE_PERMANENT)) {
            func_8068A764(arg0, D_8074E814[kongIndex].unk4);
        }
    }
}

void func_8068412C(void) {
    YetAnotherAdditionalActorData *YaaD;

    YaaD = current_actor_pointer->YaaD;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        YaaD->unk22 = current_actor_pointer->y_rotation;
        YaaD->unk24 = current_actor_pointer->y_position;
        current_actor_pointer->unk146 = 0;
        current_actor_pointer->unk15E = 0;
        func_80714998(2);
        func_807149FC(-1);
        func_807149B8(1);
        func_807149A8(1000);
        func_80714A28(4);
        func_80714CC0(&D_8071FC8C,
                      1.3f,
                      current_actor_pointer->x_position,
                      current_actor_pointer->y_position + 13.0,
                      current_actor_pointer->z_position);
        if (func_80689F2C()) {
            current_actor_pointer->draw_distance = 2000;
        } else {
            current_actor_pointer->draw_distance = 350;
        }
        current_actor_pointer->floor = current_actor_pointer->y_position;
        func_80665564(current_actor_pointer, 0.0f);
        current_actor_pointer->locked_to_pad = 0;
        current_actor_pointer->object_properties_bitfield |= 2;
    }
    func_8068408C(current_actor_pointer);
    func_80680774();
    func_8067ACB4(current_actor_pointer);

    switch (current_actor_pointer->control_state) {
        case 0:
            if (YaaD->unk4) {
                YaaD->unk4--;
                if (!YaaD->unk4) {
                    current_actor_pointer->noclip_byte = 2;
                }
            } else {
                func_806833DC(YaaD);
            }
            if (current_actor_pointer->control_state_progress == 0xA) {
                if ((player_pointer->unk6A & 4) || func_806C9D7C()) {
                    current_actor_pointer->control_state_progress = 0;
                } else {
                    if ((player_pointer->locked_to_pad != 1) && (player_pointer->unk6A & player_pointer->unk6C & 1)) {
                        func_806832F4(player_pointer->unk58, 1);
                    }
                }
            }
            break;
        case 1:
            func_806836D0(YaaD);
            func_8068C350(&func_80683AD8, current_actor_pointer, 3);
            break;
        case 2:
            if (YaaD->unk4) {
                YaaD->unk4--;
            } else {
                func_8067AAB8(current_actor_pointer, YaaD->unk0, YaaD->unk38, 180.0f, 0x46);
                func_80679200(YaaD->unk0, current_actor_pointer, 0x40, 1, 0, 0);
                func_806FB2B8();
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                if (func_806832F4(player_pointer->unk58, 0)) {
                    current_actor_pointer->control_state_progress = 0xA;
                }
                YaaD->unk4 = 0x1E;
            }
            break;
    }
    func_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x64, 0x78, 0, 1.0f);
    if (current_actor_pointer->control_state != 1) {
        current_actor_pointer->y_rotation += 0x32;
        current_actor_pointer->y_rotation &= 0xFFF;
        current_actor_pointer->y_position = func_80612794(YaaD->unk28) * 5.0f + YaaD->unk24;
        YaaD->unk28 += 0x32;
        YaaD->unk28 &= 0xFFF;
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_806844EC() {
    func_8068412C();
}

void func_8068450C() {
    func_8068412C();
}

void func_8068452C() {
    func_8068412C();
}