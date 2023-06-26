#include <ultra64.h>
#include "functions.h"


// jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_800265F0.s")

typedef struct MinecartStruct0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} MinecartStruct0;

void func_80026B6C(MinecartStruct0 *arg0, f32 arg1) {
    arg0->unkA = func_80612794(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->x_position;
    arg0->unkC = extra_player_info_pointer->vehicle_actor_pointer->floor;
    arg0->unkE = func_80612790(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->z_position;
}

extern s32 D_8074E880[];

void func_80026C54(void) {
    func_80714950(((rand() >> 0xF) % 100) + 300);
    func_8071498C(&func_80717D4C);
    func_807149B8(1);
    func_80714A28(4);
    func_80714CC0(D_8074E880[((rand() >> 0xF) % 1000) % 3],
        0.5f,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->x_position - 10.0f),
        current_actor_pointer->y_position,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->z_position - 10.0f));
}

// huge, jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80026DA8.s")

// jumptable, can't auto decompile
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027778.s")

extern f32 D_80028DD0;

void func_80027CF4(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        if (func_8072DE10(10000) != 0 || (((D_807FDC94->x_position - current_actor_pointer->x_position) * (D_807FDC94->x_position - current_actor_pointer->x_position))
                + ((D_807FDC94->y_position - current_actor_pointer->y_position) * (D_807FDC94->y_position - current_actor_pointer->y_position))
                + ((D_807FDC94->z_position - current_actor_pointer->z_position) * (D_807FDC94->z_position - current_actor_pointer->z_position))) < D_80028DD0) {
            func_80614EBC(current_actor_pointer, 0x280);
        }
    }
}

typedef struct {
    u8 unk0[0x34 - 0x0];
    u8 *unk34;
    u8 unk38[0x42 - 0x38];
    u8 unk42;
} AAD_80027DA0;

// TODO: Any cleanup possible?
void func_80027DA0(AAD_80027DA0 *arg0) {
    u8 temp_a2;
    AAD_80027DA0 *temp;
    PlayerAdditionalActorData *PaaD;

    PaaD = D_807FDC94->PaaD;
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

// structs
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027EE8.s")

f32 func_8000AC60(f32);
f32 func_806119A0();
extern f64 D_80028DD8;
typedef struct MinecartStruct1 {
    u8 pad0[0x3A];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
} MinecartStruct1;

/*
// TODO: Good progress made
void func_80027EE8(MinecartStruct1 *arg0) {
    f32 temp_f0_3;

    temp_f0_3 = func_8000AC60((current_actor_pointer->x_position - D_807FDC94->x_position) * (current_actor_pointer->x_position - D_807FDC94->x_position)
                             + (current_actor_pointer->y_position - D_807FDC94->y_position) * (current_actor_pointer->y_position - D_807FDC94->y_position)
                             + (current_actor_pointer->z_position - D_807FDC94->z_position) * (current_actor_pointer->z_position - D_807FDC94->z_position));
    if (temp_f0_3 < 200.0f) {
        arg0->unk3A++;
        if (arg0->unk3A >= 9) {
            func_80608528(current_actor_pointer, 0x1F, 0xFF, 127.0f - (temp_f0_3 - (f32) arg0->unk3C), 0);
            arg0->unk3A = ((func_806119A0() / D_80028DD8) * 3.0);
        }
    }
    arg0->unk3C = temp_f0_3;
}
*/

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_800280BC.s")

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_8002835C.s")

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_800286EC.s")
