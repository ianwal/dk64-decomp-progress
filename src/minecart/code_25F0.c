#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
extern s32 D_80717D4C; // TODO: Datatype

void func_80026C54(void) {
    func_80714950(((rand() >> 0xF) % 100) + 300);
    func_8071498C(&D_80717D4C);
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

// probably doable, disable &&/|| for cleaner output
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027CF4.s")

// small, structs, TRIPLE dereference
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027DA0.s")

// structs
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027E04.s")

// structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_80027EE8.s")

/* WIP: not too bad
f32 func_8000AC60(f32);
void func_80608528(Actor *, s32, s32, s16, s32);
s32 func_806119A0();
extern f64 D_80028DD8;
typedef struct MinecartStruct1 {
    u8 pad0[0x3A];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
} MinecartStruct1;

void func_80027EE8(MinecartStruct1 *arg0) {
    f32 temp_f0_3;
    f64 temp_f18;
    s32 temp_v0_2;
    u8 temp_t7;
    f64 phi_f18;

    temp_f0_3 = func_8000AC60((current_actor_pointer->x_position - D_807FDC94->x_position) * (current_actor_pointer->x_position - D_807FDC94->x_position)
                             + (current_actor_pointer->y_position - D_807FDC94->y_position) * (current_actor_pointer->y_position - D_807FDC94->y_position)
                             + (current_actor_pointer->z_position - D_807FDC94->z_position) * (current_actor_pointer->z_position - D_807FDC94->z_position));
    if (temp_f0_3 < 200.0f) {
        arg0->unk3A++;
        if (arg0->unk3A >= 9) {
            func_80608528(current_actor_pointer, 0x1F, 0xFF, 127.0f - (temp_f0_3 - (f32) arg0->unk3C), 0);
            phi_f18 = func_806119A0();
            if (phi_f18 < 0) {
                phi_f18 = phi_f18 + 4294967296.0;
            }
            arg0->unk3A = (u8) (u32) ((phi_f18 / D_80028DD8) * 3.0);
        }
    }
    arg0->unk3C = (s16) temp_f0_3;
}*/

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_800280BC.s")

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_8002835C.s")

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_800286EC.s")
