#include <ultra64.h>
#include "functions.h"

void func_global_asm_8065D254(Actor*, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_global_asm_80683AD8();

extern f64 D_global_asm_80759560;
extern s32 D_global_asm_8071FC8C;

typedef struct {
    u16 unk0;
    u8 unk2; // Actor Spawner ID
    u8 unk3;
    s16 unk4; // Permanent Flag Index
} GlobalASMStruct47;

extern GlobalASMStruct47 D_global_asm_8074E7A0[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067B450.s")

/*
// Don't know what this needs, our stack is too big though
u8 func_global_asm_8067B450(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((current_map == D_global_asm_8074E7A0[i].unk0) && (func_global_asm_80688E68(4) == D_global_asm_8074E7A0[i].unk2)) {
            return isFlagSet(D_global_asm_8074E7A0[i].unk4, FLAG_TYPE_PERMANENT);
        }
    }  
    return 0;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067B4C8.s")

void func_global_asm_8067BA3C() {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 2000;
    }
    func_global_asm_8067B4C8();
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067BA7C.s")

void func_global_asm_8067BC68(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BC88(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BCA8(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BCC8(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BCE8(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BD08(void) {
    func_global_asm_8067BA7C(0x13);
}

extern u8 D_global_asm_807FBBA8;

void func_global_asm_8067BD28(void) {
    s32 phi_v1;
    PlayerAdditionalActorData *PaaD = player_pointer->PaaD;

    phi_v1 = FALSE;
    if (D_global_asm_807FBBA8 && (PaaD->unk1F0 & 0x200000)) {
        phi_v1 = TRUE;
    }
    if (((current_actor_pointer->object_properties_bitfield & 0x10) == 0) || (phi_v1 != 0)) {
        func_global_asm_80689114(0x55, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 1.0f, current_actor_pointer);
    }
}

u8 func_global_asm_8067BF84(s16 arg0, u8 *arg1, u8 *arg2, u8 *arg3);

void func_global_asm_8067BDB8(void) {
    func_global_asm_8067BA7C(0x95);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    current_actor_pointer->y_position = current_actor_pointer->floor;
}

void func_global_asm_8067BDF8() {
    s8 sp1F;
    s32 temp_a1;

    sp1F = 0;
    // TODO: Which aaD type are they actually expecting here?
    temp_a1 = current_actor_pointer->PaaD;
    func_global_asm_8067BF84(0x13, temp_a1, temp_a1 + 1, &sp1F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067BE30.s")

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s8 unk4;
} AAD_global_asm_8067BE30;

/*
// TODO: Good progress made, not sure what the last steps are...
void func_global_asm_8067BE30(void) {
    AAD_global_asm_8067BE30 *temp_t0;
    s16 i;

    temp_t0 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 2000;
        temp_t0->unk0 = 0x1A;
    }
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        switch (D_global_asm_807FBB70.unk258[i]) {
            case 1:
                temp_t0->unk0 = 0x60;
                break;
            case 2:
                temp_t0->unk0 = 0;
                break;
            case 3:
                temp_t0->unk0 = 0x1A;
                break;
        }
    }
    if (temp_t0->unk0 != 0) {
        if (func_global_asm_8067BF84(temp_t0->unk0, &temp_t0->unk2, &temp_t0->unk3, &temp_t0->unk4) != 0) {
            temp_t0->unk0 = 0x1A;
        }
    } else {
        if (D_global_asm_807FBB70.unk38 != 0) {
            temp_t0->unk4 = 1;
        }
        func_global_asm_806319C4(current_actor_pointer, 0);
    }
}
*/

void func_global_asm_8067BF4C() {
    s32 temp_v0;

    // TODO: Which aaD type are they actually expecting here?
    temp_v0 = current_actor_pointer->PaaD;
    func_global_asm_8067BF84(0x1A, temp_v0 + 2, temp_v0 + 3, temp_v0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067BF84.s")

extern f32 D_global_asm_80759450;
extern f64 D_global_asm_80759458;
extern s32 D_global_asm_8071FE08; // TODO: Datatype

/*
// TODO: Good progress made
u8 func_global_asm_8067BF84(s16 arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    f32 temp_f0_2;
    f32 var_f20;
    u8 sp47;
    u8 playerIndex;
    f32 dz;
    f32 dx;

    sp47 = 0;
    var_f20 = D_global_asm_80759450;
    if (current_actor_pointer->object_properties_bitfield & 0x10) {
        func_global_asm_80688370(current_actor_pointer, 0, 0.5f);
        func_global_asm_806883C8(current_actor_pointer, 0, 0);
        func_global_asm_8068839C(current_actor_pointer, 0, 0);
        func_global_asm_8068842C(current_actor_pointer, 0, -1);
        if ((D_global_asm_807FBBA8 != 0) || (*arg1 != 0) || (*arg3 != 0)) {
            *arg3 = 0;
            sp47 = 1;
        }
        if (sp47 != 0) {
            for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
                if (character_change_array[playerIndex].does_player_exist != 0) {
                    dz = character_change_array[playerIndex].player_pointer->z_position - current_actor_pointer->z_position;
                    dx = character_change_array[playerIndex].player_pointer->x_position - current_actor_pointer->x_position;
                    
                    temp_f0_2 = sqrtf((dz * dz) + (dx * dx));
                    if (temp_f0_2 < var_f20) {
                        var_f20 = temp_f0_2;
                    }
                }
            }
            if (var_f20 > 12.0) {
                *arg1 = 0;
            } else {
                *arg1 = 1;
                sp47 = 0;
            }
        }
    } else {
        sp47 = 1;
        *arg1 = 0;
        current_actor_pointer->y_velocity = -10.0f;
        func_global_asm_806651FC(current_actor_pointer);
        func_global_asm_80665564(current_actor_pointer, 0);
        if (func_global_asm_80672BD4(current_actor_pointer) != 0) {
            *arg2 = 1;
        } else {
            *arg2 = 0;
        }
    }
    if (sp47 != 0) {
        func_global_asm_80689114(arg0, current_actor_pointer->x_position, current_actor_pointer->y_position + D_global_asm_80759458, current_actor_pointer->z_position, 0, 1.0f, current_actor_pointer);
        if (current_actor_pointer->object_properties_bitfield & 0x10) {
            func_global_asm_80608528(current_actor_pointer, 0x31, 0xFF, 0x7F, 1);
            func_global_asm_807149B8(0);
            func_global_asm_807149FC(1);
            func_global_asm_80714CC0(&D_global_asm_8071FE08, 0.5f, current_actor_pointer->x_position, current_actor_pointer->y_position + 7.0f, current_actor_pointer->z_position);
        }
    }
    if (*arg2 != 0) {
        current_actor_pointer->y_velocity = -10.0f;
        func_global_asm_806651FC(current_actor_pointer);
        func_global_asm_80665564(current_actor_pointer, 0);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
    return sp47;
}
*/

extern f64 D_global_asm_80759460;
extern f64 D_global_asm_80759468;
extern f64 D_global_asm_80759470;

typedef struct {
    u8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} AAD_global_asm_8067C2B8;

void func_global_asm_8067C2B8(void) {
    AAD_global_asm_8067C2B8 *temp_v0;

    temp_v0 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk68 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x80;
        temp_v0->unk0 = 0;
        temp_v0->unk8 = 0;
        temp_v0->unk4 = 0.0f;
    }
    if (!(current_actor_pointer->unk68 & 4)) {
        current_actor_pointer->unkB8 = 0.0f;
    }
    if (D_global_asm_807FBB70.unk90 != 0) {
        temp_v0->unk8 = 1;
    }
    if (D_global_asm_807FBB70.unk91 != 0) {
        if (temp_v0->unk0 == 0) {
            func_global_asm_80604CBC(current_actor_pointer, 0x10C, 0, 1, 0, 0xFF, 1.0f, 0);
            temp_v0->unk0 = 1;
        }
        temp_v0->unk4 = D_global_asm_807FBB70.unk94 / D_global_asm_80759460;
        current_actor_pointer->unkEE = D_global_asm_807FBB70.unk92;
        if (current_actor_pointer->unkB8 < temp_v0->unk4) {
            current_actor_pointer->unkB8 += D_global_asm_80759468;
            if (temp_v0->unk4 < current_actor_pointer->unkB8) {
                current_actor_pointer->unkB8 = temp_v0->unk4;
            }
        } else {
            current_actor_pointer->unkB8 -= 1.5;
            if (current_actor_pointer->unkB8 < 0.0f) {
                current_actor_pointer->unkB8 = 0.0f;
            }
        }
        current_actor_pointer->unkFA = 0x64;
        func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->unkEE);
        func_global_asm_806651FC(current_actor_pointer);
        func_global_asm_80665564(current_actor_pointer, 0.0f);
        current_actor_pointer->y_position = current_actor_pointer->floor;
        if (temp_v0->unk8 == 0) {
            current_actor_pointer->noclip_byte = 0x3C;
        }
    } else {
        if ((temp_v0->unk0 != 0) && (current_actor_pointer->unkB8 == 0.0)) {
            temp_v0->unk0 = 0;
            func_global_asm_80605314(current_actor_pointer, 0);
        }
        temp_v0->unk4 = 0.0f;
        if (current_actor_pointer->unkB8 < 0.0f) {
            current_actor_pointer->unkB8 += D_global_asm_80759470;
            if (temp_v0->unk4 < current_actor_pointer->unkB8) {
                current_actor_pointer->unkB8 = temp_v0->unk4;
            }
        } else {
            current_actor_pointer->unkB8 -= 1.5;
            if (current_actor_pointer->unkB8 < 0.0f) {
                current_actor_pointer->unkB8 = 0.0f;
            }
        }
        current_actor_pointer->unkFA = 0x64;
        func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->unkEE);
        func_global_asm_806651FC(current_actor_pointer);
        func_global_asm_80665564(current_actor_pointer, 0.0f);
        if (temp_v0->unk8 == 0) {
            if ((current_actor_pointer->unkB8 == 0.0) || !(current_actor_pointer->object_properties_bitfield & 0x10)) {
                current_actor_pointer->noclip_byte = 2;
            } else {
                current_actor_pointer->noclip_byte = 0x3C;
            }
        }
        current_actor_pointer->y_position = current_actor_pointer->floor;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_8067C67C(void) {
    func_global_asm_8067C71C();
}

void func_global_asm_8067C69C(void) {
    func_global_asm_8067C71C();
}

void func_global_asm_8067C6BC(void) {
    func_global_asm_8067C71C();
}

void func_global_asm_8067C6DC(void) {
    func_global_asm_8069B908();
}

void func_global_asm_8067C6FC(void) {
    func_global_asm_8067C71C();
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067C71C.s")

int func_global_asm_8071910C(); // TODO: Signature
extern s32 D_global_asm_8071FE08; // TODO: Datatype
extern s32 D_global_asm_8071FE64; // TODO: Datatype
extern s32 D_global_asm_8071FE88; // TODO: Datatype
extern s32 D_global_asm_8071FEAC; // TODO: Datatype
extern f64 D_global_asm_80759550;

u32 func_global_asm_806119A0(void);

// TODO: Pretty close
void func_global_asm_8067DCC0(void) {
    f32 temp_f20;
    s32 temp_s0;
    s32 i;
    s32 pad;

    temp_f20 = current_actor_pointer->animation_state->scale_y / D_global_asm_80759550;
    func_global_asm_8060E7EC(0, 0xB4, 0xA);
    func_global_asm_807149B8(0);
    func_global_asm_807149FC(1);
    func_global_asm_80714CC0(&D_global_asm_8071FE08, temp_f20 * 0.75, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    func_global_asm_80608528(current_actor_pointer, 0x23, 0xFF, 0x7F, 1);
    for (i = 0; i < 7; i++) {
        temp_s0 = (s32)(func_global_asm_806119A0() / 10000) % 3;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(&func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(2);
        switch (temp_s0) {
            case 0:
                func_global_asm_80714CC0(&D_global_asm_8071FE64, temp_f20 * 0.25, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                break;
            case 1:
                func_global_asm_80714CC0(&D_global_asm_8071FE88, temp_f20 * 0.25, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                break;
            case 2:
                func_global_asm_80714CC0(&D_global_asm_8071FEAC, temp_f20 * 0.25, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                break;
        }
    }
}

int func_global_asm_8071ABDC();
extern s32 D_global_asm_80720120;
extern s32 D_global_asm_80720340;
extern s32 D_global_asm_8072038C;
extern f32 D_global_asm_80759558;

void func_global_asm_8067DF44(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5) {
    f64 sp80;
    f32 sp7C;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s32 i;

    if (arg5 != 0) {
        func_global_asm_806086CC(arg0, arg1, arg2, 0xF6, 0xFF, 0x7F, 0x19, 0x1E, D_global_asm_80759558, 0);
    }
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(&func_global_asm_8071B89C);
    func_global_asm_80714CC0(&D_global_asm_80720120, 0.0f, arg0, arg1 + 5.0f, arg2);
    sp80 = arg3;
    sp7C = arg3 * 1.5;
    for (i = 0; i < 5; i++) {
        temp_f22 = (((rand() >> 0xF) % 20) - 0xA) * arg3;
        temp_f24 = (((rand() >> 0xF) % 20) - 0xA) * arg3;
        temp_f20 = (((rand() >> 0xF) % 20) - 0xA) * arg3;
        func_global_asm_8071496C(4);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_8071498C(&func_global_asm_8071BB14);
        func_global_asm_80714CC0(&D_global_asm_80720340, sp7C, arg0 + temp_f22, arg1 + temp_f24, arg2 + temp_f20);
    }
    func_global_asm_8071496C(4);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(1);
    func_global_asm_8071498C(&func_global_asm_8071BB14);
    func_global_asm_80714CC0(&D_global_asm_80720340, sp7C, arg0, arg1, arg2);
    if (arg4 != 0) {
        for (i = 0; i < 0xC; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_807149FC(2);
            func_global_asm_80714950(i + 0x0B020000);
            func_global_asm_8071498C(&func_global_asm_8071ABDC);
            func_global_asm_80714998(1);
            func_global_asm_80714CC0(&D_global_asm_8072038C, sp80 * 0.5, arg0, arg1, arg2);
        }
    }
}

void func_global_asm_8067E278(u8 arg0, u8 arg1) {
    func_global_asm_8067DF44(current_actor_pointer->x_position,
                  current_actor_pointer->y_position,
                  current_actor_pointer->z_position,
                  current_actor_pointer->animation_state->scale_y / D_global_asm_80759560,
                  arg0,
                  arg1);
}

void func_global_asm_8067E2E4(Actor *arg0, u8 arg1, f32 arg2) {
    f32 sp2C, sp28, sp24;

    func_global_asm_80671C0C(current_actor_pointer, arg1, &sp2C, &sp28, &sp24);
    func_global_asm_8067DF44(sp2C, sp28, sp24, arg2, 0, 1);
}

void func_global_asm_8067E348(void) {
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

void func_global_asm_8067E3D0(void) {
    func_global_asm_8067E348();
    current_actor_pointer->control_state = 0x14;
    current_actor_pointer->noclip_byte = 1;
    current_actor_pointer->object_properties_bitfield &= ~0x8000;
    current_actor_pointer->shadow_opacity = 0;
    func_global_asm_806F8D58(5, 0);
}

void func_global_asm_8067E43C(void) {
    s16 i;

    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if ((D_global_asm_807FBB70.unk258[i] == 1) && (D_global_asm_807FBB70.unk278[i]->unk0) == 0xFF) {
            func_global_asm_8067E3D0();
        }
    }
}

void func_global_asm_8067E4D4() {
    func_global_asm_8067E784();
    if (current_actor_pointer->control_state == 0) {
        func_global_asm_8067E43C();
    }
}

void func_global_asm_8067E510(void) {
    s16 i;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->animation_state->scale_x *= 1.5;
        current_actor_pointer->animation_state->scale_y *= 1.5;
        current_actor_pointer->animation_state->scale_z *= 1.5;
        current_actor_pointer->draw_distance = 2000;
    }
    if (current_actor_pointer->control_state == 0) {
        for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
            if (D_global_asm_807FBB70.unk258[i] == 1) {
                func_global_asm_807149B8(0);
                func_global_asm_807149FC(1);
                func_global_asm_80714CC0(&D_global_asm_8071FE08, 0.5f, current_actor_pointer->x_position, current_actor_pointer->y_position + 7.0f, current_actor_pointer->z_position);
                func_global_asm_806782C0(current_actor_pointer);
            }
        }
    }
    func_global_asm_8067E784();
}

void func_global_asm_8067E69C() {
    func_global_asm_8067E784();
    func_global_asm_8067E43C();
}

void func_global_asm_8067E6C4() {
    func_global_asm_8067E784();
}

void func_global_asm_8067E6E4() {
    func_global_asm_8067E784();
}

void func_global_asm_8067E704() {
    func_global_asm_8067E784();
}

void func_global_asm_8067E724() {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->draw_distance = 800;
    }
    func_global_asm_8067E784();
}

void func_global_asm_8067E764(void) {
    func_global_asm_8067E784();
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067E784.s")

void func_global_asm_8067FAC8(void) {
    s16 i;

    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if ((D_global_asm_807FBB70.unk258[i] == 1) && (D_global_asm_807FBB70.unk278[i]->unk0 == 1)) {
            func_global_asm_8067DCC0();
            func_global_asm_806782C0(current_actor_pointer);
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067FB6C.s")

void func_global_asm_80680774(void) {
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

void func_global_asm_8068086C() {
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

u8 func_global_asm_80680908(void) {
    u8 phi_v1 = 0x64;
    switch (current_map) {
        case MAP_FACTORY:
            if (func_global_asm_80688E68(current_actor_pointer) == 0xD
            || func_global_asm_80688E68(current_actor_pointer) == 0xF) {
                phi_v1 = 2;
            }
            break;
        case MAP_FUNGI_DK_BARN:
            if (func_global_asm_80688E68(current_actor_pointer) == 3) {
                phi_v1 = 2;
            }
            break;
        case MAP_FUNGI:
            if (func_global_asm_80688E68(current_actor_pointer) == 0x12) {
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806809F0.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
} AAD_global_asm_80681B14;

extern s16 D_global_asm_8074E7E0[];

void func_global_asm_80681B14(void) {
    AAD_global_asm_80681B14 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (isFlagSet(0x302, 0) != 0) {
            func_global_asm_806782C0(current_actor_pointer);
            return;
        }
    }
    func_global_asm_806809F0();
    if ((current_actor_pointer->control_state == 0xC) && (temp_v1->unkD < 3)) {
        setFlag(D_global_asm_8074E7E0[temp_v1->unkA], 1, 2);
        func_global_asm_8067DCC0();
        func_global_asm_806782C0(current_actor_pointer);
    }
}

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
} AAD_global_asm_80681BD8;

void func_global_asm_80681BD8(void) {
    AAD_global_asm_80681BD8 *sp2C;
    s32 sp28;
    s32 i;
    s32 var_s1;

    sp2C = current_actor_pointer->additional_actor_data;
    func_global_asm_806809F0();
    if (isFlagSet(0x17F, FLAG_TYPE_PERMANENT) == FALSE) {
        current_actor_pointer->control_state = 0x14;
        current_actor_pointer->noclip_byte = 1;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->shadow_opacity = 0;
    } else {
        if (isFlagSet(0x187, FLAG_TYPE_PERMANENT) == FALSE) {
            if (current_actor_pointer->control_state == 0xB) {
                var_s1 = 0;
                i = 0;
                do {
                    var_s1 += isFlagSet(i + 0x182, FLAG_TYPE_PERMANENT) != FALSE;
                    i++;
                } while (i < 4);
                if (var_s1 == 4) {
                    playCutscene(player_pointer, 3, 1);
                    setFlag(0x187, TRUE, FLAG_TYPE_PERMANENT);
                }
            }
        }
        switch (sp2C->unk6) {
            case 0xB1:
                sp28 = 0x182;
                break;
            case 0xB6:
                sp28 = 0x183;
                break;
            case 0xB4:
                sp28 = 0x184;
                break;
            case 0xB5:
                sp28 = 0x185;
                break;
        }
        if (isFlagSet(sp28, FLAG_TYPE_PERMANENT) != FALSE) {
            sp2C->unkC = 1;
            sp2C->unkA = 0;
            if (current_actor_pointer->control_state == 0) {
                current_actor_pointer->control_state = 0x14;
                current_actor_pointer->noclip_byte = 1;
                current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
                current_actor_pointer->shadow_opacity = 0;
            }
        } else {
            if (current_actor_pointer->control_state == 0x14) {
                current_actor_pointer->noclip_byte = 2;
                current_actor_pointer->control_state = 0x15;
            }
        }
    }
    if ((current_actor_pointer->control_state == 0xC) && (sp2C->unkD < 3)) {
        func_global_asm_8067DCC0();
        func_global_asm_806782C0(current_actor_pointer);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80681E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806822FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80682AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80682DF4.s")

void func_global_asm_80682DF4(Actor *, u16 *, s32);

/*
extern u16 D_global_asm_807FBB54[];
void func_global_asm_80682DF4(Actor *arg0, u16 *arg1, s32 arg2) {
    func_global_asm_80614EBC(arg0, D_global_asm_807FBB54[(((arg2 * 7) + *arg1) - 2)]);
}
*/

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4; // Used
    u8 unk5;
} GlobalASMStruct45;

extern GlobalASMStruct45 D_global_asm_8074E814[];
void func_global_asm_80682AB4(void *);
void func_global_asm_806F09F0(Actor *, u16);

typedef struct {
    s32 unk0;
    s16 unk4;
    s8 unk6;
    u8 unk7;
    Actor *unk8[5];
    Actor *unk1C;
} Struct80682E38_arg0;

typedef struct {
    s16 unk0;
} AAD_global_asm_80682E38;

void func_global_asm_80682E38(Struct80682E38_arg0 *arg0) {
    s32 var_a2;
    s16 var_a1;
    Actors var_s0;
    s32 i;
    AAD_global_asm_80682E38 *temp_s0;

    func_global_asm_80677FA8(ACTOR_SPOTLIGHT, 0xA8);
    arg0->unk1C = D_global_asm_807FBB44;
    D_global_asm_807FBB44->x_position = (func_global_asm_80612794(current_actor_pointer->y_rotation) * 35.0f) + current_actor_pointer->x_position;
    D_global_asm_807FBB44->y_position = (current_actor_pointer->y_position - 10.0f) - 2.0f;
    D_global_asm_807FBB44->z_position = (func_global_asm_80612790(current_actor_pointer->y_rotation) * 35.0f) + current_actor_pointer->z_position;
    for (i = 0; i < 5; i++) {
        if (isFlagSet(func_global_asm_805FF018(current_actor_pointer->unk58, i), FLAG_TYPE_PERMANENT) != FALSE) {
            var_s0 = ACTOR_TAGBARREL_KONG;
            var_a1 = D_global_asm_8074E814[i].unk0;
        } else {
            var_s0 = ACTOR_TAGBARREL_LOCKED;
            var_a1 = 0xD2;
        }
        func_global_asm_80677FA8(var_s0, var_a1);
        arg0->unk8[i] = D_global_asm_807FBB44;
        D_global_asm_807FBB44->y_rotation = current_actor_pointer->y_rotation;
        D_global_asm_807FBB44->object_properties_bitfield |= 0x40000000;
        if (var_s0 == 0x13C) {
            temp_s0 = D_global_asm_807FBB44->additional_actor_data;
            temp_s0->unk0 = D_global_asm_8074E814[i].unk2;
            func_global_asm_806F09F0(D_global_asm_807FBB44, temp_s0->unk0);
            if (i == arg0->unk6) {
                var_a2 = 0x8B;
            } else {
                var_a2 = 0x8A;
            }
            func_global_asm_80682DF4(D_global_asm_807FBB44, temp_s0, var_a2);
        } else {
            RaceAdditionalActorData2 *RaaD2 = D_global_asm_807FBB44->RaaD2;
            RaaD2->unk0 = i;
        }
    }
    func_global_asm_80682AB4(arg0);
}

typedef struct {
    s32 unk0[5];
} Struct8074E834;

extern Struct8074E834 D_global_asm_8074E834;

typedef struct {
    u8 unk0;
} AAD_global_asm_8068304C;

void func_global_asm_8068304C(void) {
    Struct8074E834 sp2C;
    AAD_global_asm_8068304C *sp28;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        sp2C = D_global_asm_8074E834;
        sp28 = current_actor_pointer->additional_actor_data;
        current_actor_pointer->object_properties_bitfield |= 0x1000;
        func_global_asm_8068842C(current_actor_pointer, 0, 1);
        func_global_asm_80688460(current_actor_pointer, 0, 1);
        func_global_asm_806883F4(current_actor_pointer, 0, sp2C.unk0[sp28->unk0], 0);
        func_global_asm_80614EBC(current_actor_pointer, 0x329);
    }
    current_actor_pointer->unk16D = current_actor_pointer->unk15F;
    current_actor_pointer->y_rotation += 0x32;
    current_actor_pointer->y_rotation &= 0xFFF;
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Function pointer in a local variable, needs some PaaD untangling
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80683158.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806832F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806833DC.s")

/*
// Needs some PaaD untangling I think
// Switch case for control_state_progress?
void func_global_asm_806833DC(YetAnotherAdditionalActorData *arg0) {
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
                if ((temp_v0 == 0xB) && (func_global_asm_8061CB50(&current_actor_pointer) == 0)) {
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
            func_global_asm_806C93E4(temp_a0, temp_a1, &current_actor_pointer);
            func_global_asm_806C9304(arg0->unk0, temp_a1);
            sp20 = phi_v0;
            func_global_asm_80659620(&arg0->unk2C, &arg0->unk30, &arg0->unk34, phi_v0);
            func_global_asm_80659670(1.0f, 1.0f, 1.0f, sp20);
            current_actor_pointer->y_rotation = arg0->unk22;
            current_actor_pointer->noclip_byte = 1;
            temp_v0_4 = sp34->unk5A;
            global_properties_bitfield &= 0xFFFCFFCF;
            arg0->unk6 = 0;
            if (temp_v0_4 != (&D_global_asm_8074E814 + (arg0->unk6 * 6))->unk2) {
                do {
                    arg0->unk6 = arg0->unk6 + 1;
                } while (temp_v0_4 != (&D_global_asm_8074E814 + (arg0->unk6 * 6))->unk2);
            }
            arg0->unk7 = arg0->unk6;
            phi_a1 = arg0->unk6;
            if (current_map != MAP_HELM) {
                playSong(0x65, 1.0f);
                func_global_asm_80602CE0(0x65, 0x7E - *(&D_global_asm_8074E848 + (arg0->unk6 * 4)), 1);
                phi_a1 = arg0->unk6;
            }
            setFlag(func_global_asm_805FF018(current_actor_pointer->unk58, phi_a1), TRUE, FLAG_TYPE_PERMANENT);
            func_global_asm_80682E38(arg0);
            func_global_asm_80627878(sp30->unk104);
            arg0->unk38 = sp34->unkE6;
            sp34->unkE6 = current_actor_pointer->y_rotation;
            func_global_asm_8060DEC8(); // saveTheGame()
            playCutscene(current_actor_pointer, 0xE, 0xC);
            func_global_asm_8061B650(sp30->unk104);
            func_global_asm_806FB218();
            current_actor_pointer->control_state = 1;
            current_actor_pointer->control_state_progress = 0;
        }
    } else {
block_6:
        if (D_global_asm_807FBB70.unk200 == 4) {
            temp_t1 = D_global_asm_807FBB70.unk1FC;
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
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806836D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80683A80.s")

/*
// TODO: This is probably wrong
typedef struct {
    Actor *unk8;
} Struct80683A80_arg0;

extern s32 D_global_asm_8074E87C[];

// TODO: sus
s32 func_global_asm_80683A80(Struct80683A80_arg0 *arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = 0;
    if ((arg0[arg1 + 2].unk8->unk58 ^ 0x13C) == 0) {
        var_a2 = func_global_asm_8070E750(2, D_global_asm_8074E87C[arg1 - 8], 1);
    }
    return var_a2;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80683AD8.s")

void func_global_asm_8068408C(Actor *arg0) {
    s32 kongIndex;

    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        if (isFlagSet(func_global_asm_805FF018(arg0->unk58, kongIndex), FLAG_TYPE_PERMANENT)) {
            func_global_asm_8068A764(arg0, D_global_asm_8074E814[kongIndex].unk4);
        }
    }
}

void func_global_asm_8068412C(void) {
    YetAnotherAdditionalActorData *YaaD;

    YaaD = current_actor_pointer->YaaD;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        YaaD->unk22 = current_actor_pointer->y_rotation;
        YaaD->unk24 = current_actor_pointer->y_position;
        current_actor_pointer->unk146 = 0;
        current_actor_pointer->unk15E = 0;
        func_global_asm_80714998(2);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_807149A8(1000);
        func_global_asm_80714A28(4);
        func_global_asm_80714CC0(&D_global_asm_8071FC8C,
                      1.3f,
                      current_actor_pointer->x_position,
                      current_actor_pointer->y_position + 13.0,
                      current_actor_pointer->z_position);
        if (func_global_asm_80689F2C()) {
            current_actor_pointer->draw_distance = 2000;
        } else {
            current_actor_pointer->draw_distance = 350;
        }
        current_actor_pointer->floor = current_actor_pointer->y_position;
        func_global_asm_80665564(current_actor_pointer, 0.0f);
        current_actor_pointer->locked_to_pad = 0;
        current_actor_pointer->object_properties_bitfield |= 2;
    }
    func_global_asm_8068408C(current_actor_pointer);
    func_global_asm_80680774();
    func_global_asm_8067ACB4(current_actor_pointer);

    switch (current_actor_pointer->control_state) {
        case 0:
            if (YaaD->unk4) {
                YaaD->unk4--;
                if (!YaaD->unk4) {
                    current_actor_pointer->noclip_byte = 2;
                }
            } else {
                func_global_asm_806833DC(YaaD);
            }
            if (current_actor_pointer->control_state_progress == 0xA) {
                if ((player_pointer->unk6A & 4) || func_global_asm_806C9D7C()) {
                    current_actor_pointer->control_state_progress = 0;
                } else {
                    if ((player_pointer->locked_to_pad != 1) && (player_pointer->unk6A & player_pointer->unk6C & 1)) {
                        func_global_asm_806832F4(player_pointer->unk58, 1);
                    }
                }
            }
            break;
        case 1:
            func_global_asm_806836D0(YaaD);
            func_global_asm_8068C350(&func_global_asm_80683AD8, current_actor_pointer, 3);
            break;
        case 2:
            if (YaaD->unk4) {
                YaaD->unk4--;
            } else {
                func_global_asm_8067AAB8(current_actor_pointer, YaaD->unk0, YaaD->unk38, 180.0f, 0x46);
                func_global_asm_80679200(YaaD->unk0, current_actor_pointer, 0x40, 1, 0, 0);
                func_global_asm_806FB2B8();
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                if (func_global_asm_806832F4(player_pointer->unk58, 0)) {
                    current_actor_pointer->control_state_progress = 0xA;
                }
                YaaD->unk4 = 0x1E;
            }
            break;
    }
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x64, 0x78, 0, 1.0f);
    if (current_actor_pointer->control_state != 1) {
        current_actor_pointer->y_rotation += 0x32;
        current_actor_pointer->y_rotation &= 0xFFF;
        current_actor_pointer->y_position = func_global_asm_80612794(YaaD->unk28) * 5.0f + YaaD->unk24;
        YaaD->unk28 += 0x32;
        YaaD->unk28 &= 0xFFF;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_806844EC() {
    func_global_asm_8068412C();
}

void func_global_asm_8068450C() {
    func_global_asm_8068412C();
}

void func_global_asm_8068452C() {
    func_global_asm_8068412C();
}
