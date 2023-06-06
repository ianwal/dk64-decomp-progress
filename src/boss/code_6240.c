#include <ultra64.h>
#include "functions.h"

extern s32 D_80720120;
extern s32 D_8071EDEC;
extern s32 D_8074E880[];

s32 func_80725BA4(s16, s16, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_6240/func_8002A240.s")

/*
// TODO: Quite close
void func_8002A240(void) {
    Actor17C *temp_s0;
    f32 temp_f10;

    temp_s0 = current_actor_pointer->unk17C;
    if (temp_s0->unk4 != 0) {
        temp_s0->unk4--;
        temp_f10 = func_80612794((temp_s0->unk4 / 10.0) * (temp_s0->unk8 + -0x400) + (temp_s0->unk8 + 0x400)) * 20.0;
        current_actor_pointer->x_position += temp_f10 * func_80612794(temp_s0->unk6);
        current_actor_pointer->z_position += temp_f10 * func_80612790(temp_s0->unk6);
        if (temp_s0->unk4 == 0) {
            temp_s0->unk8 += 0x400;
        }
    } else if (((rand() >> 0xF) % 1000) >= 0x3AD) {
        temp_s0->unk4 = 0xA;
    }
    current_actor_pointer->y_position += 8.0 * func_80612794((u32)object_timer * 200.0);
}
*/

void func_8002A41C(u8 arg0) {
    s32 pad;
    Actor *temp_v0;
    void *sp2C;

    switch (arg0) {
        case 0:
            temp_v0 = func_8067ADB4(0x61); // TNT Barrel Spawner (Dogadon)
            if (temp_v0) {
                func_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 1, &sp2C, 0);
                return;
            }
            return;
        case 1:
            temp_v0 = func_8067ADB4(0x60); // Hunky Chunky Barrel (Dogadon)
            if (temp_v0) {
                func_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 1, &sp2C, 0);
            }
            temp_v0 = func_8067ADB4(0x61); // TNT Barrel Spawner (Dogadon)
            if (temp_v0) {
                func_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 3, &sp2C, 0);
                return;
            }
            break;
        case 2:
            temp_v0 = func_8067ADB4(0x60); // Hunky Chunky Barrel (Dogadon)
            if (temp_v0) {
                func_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 1, &sp2C, 0);
            }
            temp_v0 = func_8067ADB4(0x61); // TNT Barrel Spawner (Dogadon)
            if (temp_v0) {
                func_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 2, &sp2C, 0);
            }
            break;
    }
}

void func_8002A55C(u8 arg0, f32 arg1) {
    if (!(arg0 & object_timer)) {
        func_807149B8(1);
        func_807149C8(0xFF, 0xD7, 0x58, 0xFF);
        func_80714C08(&D_80720120, arg1, current_actor_pointer, 1, 0);
    }
}

void func_8002A5CC(void) {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    s16 phi_s0;
    s32 tmp_s2;

    func_80671C0C(current_actor_pointer, 1, &sp6C, &sp68, &sp64);
    sp6C += ((rand() >> 0xF) % 80) - 40;
    sp68 += ((rand() >> 0xF) % 100) + 50;
    sp64 += ((rand() >> 0xF) % 80) - 40;
    func_807149B8(1);
    func_8071498C(&D_8071EDEC);
    func_80714950(current_actor_pointer);
    func_807149C8(0xFF, 0xD7, 0x58, 0xFF);
    func_80714CC0(&D_80720120, 1.5f, sp6C, sp68, sp64);
    tmp_s2 = &func_8071720C;
    for (phi_s0 = 0; phi_s0 < 4; phi_s0++) {
        func_80714998(2);
        func_8071498C(tmp_s2);
        func_807149B8(1);
        func_80714C08(D_8074E880[((rand() >> 0xF) % 1000) % 3],
                      1.5f,
                      current_actor_pointer,
                      (((rand() >> 0xF) % 32767) % 22) + 2,
                      0);
    }
}

void func_8002A8B8(s32 arg0) {
    if (func_80725BA4(player_pointer->x_position, player_pointer->z_position, arg0) == 0) {
        player_pointer->x_position = player_pointer->unk88;
        player_pointer->z_position = player_pointer->unk90;
    }
}

// Jumptable, huge
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_6240/func_8002A92C.s")
