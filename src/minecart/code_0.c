#include <ultra64.h>
#include "functions.h"


s32 func_8070E750(s32, s32, s32);

void func_80024000(u8 arg0, u8 arg1) {
    playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_8069D2AC(0x81, 0, 0x78, func_8070E750(0x1A, arg1, 1), 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x28, 1.0f);
    func_806EB0C0(0x44, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        playCutscene(player_pointer, 5, 5);
    }
}

void func_800240DC(u8 arg0, u8 arg1) {
    s32 temp = func_8070E750(0x1A, arg1, 1);
    func_8069D2AC(0x81, 0, 0x78, temp, 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x2A, 1.0f);
    func_806EB0C0(0x43, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        playCutscene(player_pointer, 5, 5);
    }
}

extern s32 D_8071A440; // TODO: Proper datatype
extern s32 D_80028C30; // TODO: Proper datatype
extern s32 D_8072006C; // TODO: Proper datatype

u8 func_806119A0(void);

void func_800241A0(s16 *arg0, u8 arg1, u8 arg2) {
    // TODO: Get rid of this typecast if possible
    if (((func_806119A0() & 0xFF) >= (u32)arg2) && (*arg0 == 0)) {
        func_80608528(current_actor_pointer, 0x8A, 0x96, 0x7F, 0x32);
        func_80714950(current_actor_pointer);
        func_8071498C(&D_8071A440);
        D_80028C30 = func_80714C08(&D_8072006C, 0.4f, current_actor_pointer, arg1 + 7, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024254.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s16 unk3C;
    u8 unk3E;
    u8 unk3F;
} Struct80024254_arg0;

/*
// TODO: Regalloc
void func_80024254(Struct80024254_arg0 *arg0) {
    if (current_actor_pointer->unkB8 != arg0->unk3E) {
        if (current_actor_pointer->unkB8 < arg0->unk3E) {
            if (arg0->unk3E < current_actor_pointer->unkB8 + 8.0f) {
                current_actor_pointer->unkB8 = arg0->unk3E;
            } else {
                current_actor_pointer->unkB8 += 8.0f;
            }
        } else if (arg0->unk3E < current_actor_pointer->unkB8) {
            if (current_actor_pointer->unkB8 - 8.0f < arg0->unk3E) {
                current_actor_pointer->unkB8 = arg0->unk3E;
            } else {   
                current_actor_pointer->unkB8 -= 8.0f;
            }
        }
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_8002430C.s")

void func_8065A660(f32, f32);
void func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_80024768(void) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    if (extra_player_info_pointer->unk1F0 & 0x10000002) {
        func_80671C0C(current_actor_pointer, 2, &sp38, &sp3C, &sp40);
        func_80671C0C(current_actor_pointer, 1, &sp44, &sp48, &sp4C);
    } else {
        func_80671C0C(current_actor_pointer, 1, &sp38, &sp3C, &sp40);
        func_80671C0C(current_actor_pointer, 2, &sp44, &sp48, &sp4C);
    }
    func_8065A6F8(0xC8);
    func_8065A660(20.0f, 40.0f);
    func_8065A708(sp38, sp3C, sp40, sp44, sp48, sp4C, 0.0f, 1, 0xFF, 0xFF, 0xFF);
}

extern s32 D_80028C34; // TODO: Datatype
extern s32 D_80028C3C; // TODO: Datatype
extern s32 D_80028C40; // TODO: Datatype
extern f32 D_80028C80;
extern f64 D_80028C88;
extern f64 D_80028C90;
extern f64 D_80028C98;
extern s16 D_807502D0;
extern f32 D_807502F8;
extern s16 D_80750338;
extern s32 D_8076A0A8;

s32 func_8002430C(s32, s32 *, s16, s32);

typedef struct {
    s16 unk0;
    s16 unk2;
    Actor *unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    f32 unk28;
} AAD_80024890;

void func_80024890(void) {
    AAD_80024890 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_v1->unk24 = D_80028C80;
        temp_v1->unk28 = 5.0f;
    }
    func_8002430C(1, D_8076A0A8 == 6 ? &D_80028C34 : &D_80028C3C, 0x7FFF, 0x23);
    func_80024768();
}

void func_80024914(void) {
    f32 temp;
    s32 temp2; // TODO: Hmm..
    s16 temp_a1;
    Actor *temp_v0_2;
    AAD_80024890 *temp_s0;

    temp = current_actor_pointer->animation_state->scale_y * D_80028C88;
    temp_s0 = current_actor_pointer->additional_actor_data;
    temp_a1 = temp_s0->unk0;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->terminal_velocity = D_807502D0;
        temp_s0->unk24 = 3.0f;
        temp_s0->unk28 = 12.0f;
    }
    if (temp_s0->unk10 == 0x90) {
        current_actor_pointer->unkB8 = 130.0f;
        current_actor_pointer->y_acceleration = D_807502F8 * D_80028C90;
        if (temp_s0->unk0 == 0) {
            current_actor_pointer->y_velocity = D_80750338 * D_80028C98;
        }
    } else {
        current_actor_pointer->y_acceleration = D_807502F8;
    }
    temp_s0->unk0 = temp_s0->unk0 + (current_actor_pointer->y_velocity * temp);
    func_80729E6C();
    if (temp_s0->unk0 < 0) {
        temp_s0->unk0 = 0;
        if (temp_a1 != 0) {
            func_80608528(current_actor_pointer, 0x8B, 0xFF, 0x7F, 0x1E);
        }
    }
    func_8002430C(3, &D_80028C40, temp_s0->unk2, 0x19);
    if ((player_pointer->unk12C != 0x12) && (player_pointer->unk12C != 0xB)) {
        func_80024768();
    }
    if (current_actor_pointer->control_state != 0) {
        temp_v0_2 = temp_s0->unk4;
        func_80671C0C(current_actor_pointer, 9, &temp_v0_2->x_position, &temp_v0_2->y_position, &temp_v0_2->z_position);
    }
}

// long, structs
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024B00.s")

// struct, loop
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024E78.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_80024FD0.s")

typedef struct minecart_struct_0 {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
} MinecartStruct0;

void func_8002538C(MinecartStruct0 *arg0) {
    arg0->unk20 = arg0->unk20 + arg0->unk24;
    if (arg0->unk28 < arg0->unk20) {
        arg0->unk20 = arg0->unk28;
    }
}

// huge, struct, float, loop
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_800253C0.s")
