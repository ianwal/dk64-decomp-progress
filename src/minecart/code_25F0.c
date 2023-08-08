#include <ultra64.h>
#include "functions.h"


// jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_800265F0.s")

typedef struct MinecartStruct0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} MinecartStruct0;

void func_minecart_80026B6C(MinecartStruct0 *arg0, f32 arg1) {
    arg0->unkA = func_global_asm_80612794(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->x_position;
    arg0->unkC = extra_player_info_pointer->vehicle_actor_pointer->floor;
    arg0->unkE = func_global_asm_80612790(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->z_position;
}

extern s32 D_global_asm_8074E880[];

void func_minecart_80026C54(void) {
    func_global_asm_80714950(((rand() >> 0xF) % 100) + 300);
    func_global_asm_8071498C(&func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714A28(4);
    func_global_asm_80714CC0(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        0.5f,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->x_position - 10.0f),
        current_actor_pointer->y_position,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->z_position - 10.0f));
}

// huge, jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_80026DA8.s")

// jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_80027778.s")

extern f32 D_minecart_80028DD0;

void func_minecart_80027CF4(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        if (func_global_asm_8072DE10(10000) != 0 || (((D_global_asm_807FDC94->x_position - current_actor_pointer->x_position) * (D_global_asm_807FDC94->x_position - current_actor_pointer->x_position))
                + ((D_global_asm_807FDC94->y_position - current_actor_pointer->y_position) * (D_global_asm_807FDC94->y_position - current_actor_pointer->y_position))
                + ((D_global_asm_807FDC94->z_position - current_actor_pointer->z_position) * (D_global_asm_807FDC94->z_position - current_actor_pointer->z_position))) < D_minecart_80028DD0) {
            func_global_asm_80614EBC(current_actor_pointer, 0x280);
        }
    }
}

typedef struct {
    u8 unk0[0x34 - 0x0];
    u8 *unk34;
    u8 unk38[0x42 - 0x38];
    u8 unk42;
} AAD_minecart_80027DA0;

// TODO: Any cleanup possible?
void func_minecart_80027DA0(AAD_minecart_80027DA0 *arg0) {
    u8 temp_a2;
    AAD_minecart_80027DA0 *temp;
    PlayerAdditionalActorData *PaaD;

    PaaD = D_global_asm_807FDC94->PaaD;
    temp = PaaD->vehicle_actor_pointer->additional_actor_data;
    temp_a2 = temp->unk34[0] - 0x10;
    if (temp_a2 < arg0->unk34[0]) {
        arg0->unk42 = 1;
    } else {
        if (arg0->unk34[0] < temp_a2) {
            arg0->unk42 = 2;
        } else {
            arg0->unk42 = 0;
        }
    }
}

void func_minecart_80027E04(void) {
    u16 temp_v1;
    PlayerAdditionalActorData *PaaD = D_global_asm_807FDC94->PaaD;

    temp_v1 = current_actor_pointer->animation_state->unk1C->unk4;
    if (temp_v1 >= 0x47D1 && temp_v1 < 0xB830) {
        D_global_asm_807FDC90->unk26 = MAX(9, D_global_asm_807FDC90->unk26 - 5);
    } else if (!(temp_v1 >= 0x3830 && temp_v1 < 0xC7D1)) {
        D_global_asm_807FDC90->unk26 = MIN(D_global_asm_807FDC9C->unkD, D_global_asm_807FDC90->unk26 + 5);
    } else {
        D_global_asm_807FDC90->unk26 = PaaD->vehicle_actor_pointer->unkB8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_80027EE8.s")

f32 func_minecart_8000AC60(f32);
u32 func_global_asm_806119A0();
extern f64 D_minecart_80028DD8;
typedef struct MinecartStruct1 {
    u8 pad0[0x3A];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
} MinecartStruct1;

/*
// TODO: Good progress made
void func_minecart_80027EE8(MinecartStruct1 *arg0) {
    f32 temp_f0_3;
    f32 dx = (current_actor_pointer->x_position - D_global_asm_807FDC94->x_position);
    f32 dy = (current_actor_pointer->y_position - D_global_asm_807FDC94->y_position);
    f32 dz = (current_actor_pointer->z_position - D_global_asm_807FDC94->z_position);

    temp_f0_3 = func_minecart_8000AC60((dx * dx) + (dy * dy) + (dz * dz));
    if (temp_f0_3 < 200.0f) {
        arg0->unk3A++;
        if (arg0->unk3A >= 9) {
            func_global_asm_80608528(current_actor_pointer, 0x1F, 0xFF, 127.0f - (temp_f0_3 - arg0->unk3C), 0);
            arg0->unk3A = ((func_global_asm_806119A0() / D_minecart_80028DD8) * 3.0);
        }
    }
    arg0->unk3C = temp_f0_3;
}
*/

s32 func_global_asm_8072177C(void *, s16, s16, s16, s32, s32, s32, s32, s32);

typedef struct {
    u8 unk0[0x10 - 0x0];
    s16 unk10;
    u8 unk12[0x34 - 0x12];
    s32 unk34;
} A178_minecart_800280BC;

void func_minecart_800280BC(void) {
    A178_minecart_800280BC *sp54;
    Struct807FBB70_unk278 *temp_v1;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    u8 *temp_v0_2;

    sp54 = current_actor_pointer->unk178;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724CA4(2, 1);
        D_global_asm_807FDC90->unk35 = 6;
    }
    if (D_global_asm_807FBB70.unk15 != 0) {
        func_global_asm_80608528(current_actor_pointer, 0xF6, 0xFF, 0x7F, 0x1E);
        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xA, 0x14);
        current_actor_pointer->control_state = 0x40;
        func_global_asm_8067E278(0, 1);
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FBB70.unk254 != 0) {
                temp_v1 = D_global_asm_807FBB70.unk278[0];
                temp_v0_2 = malloc(2);
                temp_v0_2[0] = temp_v1->unk2;
                temp_v0_2[1] = 0xFF;
                sp54->unk34 = temp_v0_2;
                sp54->unk10 = temp_v1->unk4;
                D_global_asm_807FDC90->unk26 = 0x46;
                current_actor_pointer->unkB8 = 0.0f;
                current_actor_pointer->control_state++;
            } else {
                func_global_asm_80724E48(1);
                func_minecart_80027CF4();
                func_global_asm_806319C4(current_actor_pointer, 0);
                break;
            }
        case 1:
            func_global_asm_80724E48(1);
            func_minecart_80027CF4();
            func_minecart_80027E04();
            func_global_asm_8068ECF4(6, 0xFF);
            func_global_asm_8072B438(0x200);
            func_minecart_800253C0(sp54, 0x7FFF, 0x23);
            func_global_asm_80671C0C(current_actor_pointer, 5, &sp44, &sp48, &sp4C);
            func_global_asm_8072177C(current_actor_pointer, sp44, sp48, sp4C, 0xFF, 0xFF, 0xFF, 0xFF, 0);
            func_minecart_80027EE8(sp54);
            break;
        case 2:
            current_actor_pointer->control_state = 0x40;
            func_global_asm_806319C4(current_actor_pointer, 0);
            break;
        default:
            func_global_asm_806319C4(current_actor_pointer, 0);
            break;
    }
}

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_8002835C.s")

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_800286EC.s")
