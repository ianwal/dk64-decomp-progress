#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

const s32 D_boss_800362F0[] = {
    0x09000102,
    0x03040506,
    0x07080000,
};

const s32 D_boss_800362FC[] = {
    0x274F4B00,
    0x0346042A,
    0x48964350,
};

const s32 D_boss_80036308[] = {
    0x41024F46,
    0x044B0003,
    0x46042A48,
    0x78434B00,
    0x03500000,
};

const s32 D_boss_8003631C[] = {
    0x41024F46,
    0x044B0003,
    0x46044B00,
    0x0346042A,
    0x4864434B,
    0x00035000,
};

const s32 D_boss_80036334[] = {
    0x274F4B00,
    0x0346042A,
    0x48964350,
};

const s32 D_boss_80036340[] = {
    0x41024F46,
    0x044B0003,
    0x46042A29,
    0x4878434B,
    0x00035000,
};

const s32 D_boss_80036354[] = {
    0x41024604,
    0x4B000346,
    0x044B0003,
    0x46044B00,
    0x035F0411,
    0x4F282A48,
    0xBE295500,
    0x50294864,
    0x434B0003,
    0x46044B00,
    0x0346044B,
    0x00034604,
    0x4B000350,
};

const s32 D_boss_80036388[] = {
    0x41022C11,
    0x2B114850,
    0x114F434B,
    0x00034604,
    0x2A485050,
};

const s32 D_boss_8003639C[] = {
    0x43410155,
    0xFFFF0000,
};

// .data
void *D_boss_80035A20[] = {
    D_boss_800362FC,
    D_boss_80036308,
    D_boss_8003631C,
    NULL,
    NULL,
};

void *D_boss_80035A34[] = {
    D_boss_80036334,
    D_boss_80036340,
    D_boss_80036354,
    D_boss_80036388,
    D_boss_8003639C,
};

extern SpriteData D_global_asm_80720120;

s32 func_global_asm_80725BA4(s16, s16, s32);

// close
#pragma GLOBAL_ASM("asm/nonmatchings/boss/Dogadon/func_boss_8002A240.s")

/*
void func_boss_8002A240(void) {
    Actor17C *temp_s0;
    f32 temp_f10;

    temp_s0 = current_actor_pointer->unk17C;
    if (temp_s0->unk4 != 0) {
        temp_s0->unk4--;
        temp_f10 = func_global_asm_80612794((temp_s0->unk4 / 10.0) * (temp_s0->unk8 + -0x400) + (temp_s0->unk8 + 0x400)) * 20.0;
        current_actor_pointer->x_position += temp_f10 * func_global_asm_80612794(temp_s0->unk6);
        current_actor_pointer->z_position += temp_f10 * func_global_asm_80612790(temp_s0->unk6);
        if (temp_s0->unk4 == 0) {
            temp_s0->unk8 += 0x400;
        }
    } else if (((rand() >> 0xF) % 1000) >= 0x3AD) {
        temp_s0->unk4 = 0xA;
    }
    current_actor_pointer->y_position += 8.0 * func_global_asm_80612794((u32)object_timer * 200.0);
}
*/

void func_boss_8002A41C(u8 arg0) {
    s32 pad;
    Actor *temp_v0;
    void *sp2C;

    switch (arg0) {
        case 0:
            temp_v0 = func_global_asm_8067ADB4(0x61); // TNT Barrel Spawner (Dogadon)
            if (temp_v0) {
                func_global_asm_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 1, &sp2C, 0);
                return;
            }
            return;
        case 1:
            temp_v0 = func_global_asm_8067ADB4(0x60); // Hunky Chunky Barrel (Dogadon)
            if (temp_v0) {
                func_global_asm_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 1, &sp2C, 0);
            }
            temp_v0 = func_global_asm_8067ADB4(0x61); // TNT Barrel Spawner (Dogadon)
            if (temp_v0) {
                func_global_asm_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 3, &sp2C, 0);
                return;
            }
            break;
        case 2:
            temp_v0 = func_global_asm_8067ADB4(0x60); // Hunky Chunky Barrel (Dogadon)
            if (temp_v0) {
                func_global_asm_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 1, &sp2C, 0);
            }
            temp_v0 = func_global_asm_8067ADB4(0x61); // TNT Barrel Spawner (Dogadon)
            if (temp_v0) {
                func_global_asm_8067AB20(current_actor_pointer, temp_v0, 0x1000000, 2, &sp2C, 0);
            }
            break;
    }
}

void func_boss_8002A55C(u8 arg0, f32 arg1) {
    if (!(arg0 & object_timer)) {
        func_global_asm_807149B8(1);
        changeActorColor(0xFF, 0xD7, 0x58, 0xFF);
        func_global_asm_80714C08(&D_global_asm_80720120, arg1, current_actor_pointer, 1, 0);
    }
}

void func_boss_8002A5CC(void) {
    f32 x, y, z;
    s16 i;

    getBonePosition(current_actor_pointer, 1, &x, &y, &z);
    x += ((rand() >> 0xF) % 80) - 40;
    y += ((rand() >> 0xF) % 100) + 50;
    z += ((rand() >> 0xF) % 80) - 40;
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(func_global_asm_8071EDEC);
    func_global_asm_80714950((s32)current_actor_pointer);
    changeActorColor(0xFF, 0xD7, 0x58, 0xFF);
    drawSpriteAtPosition(&D_global_asm_80720120, 1.5f, x, y, z);
    for (i = 0; i < 4; i++) {
        func_global_asm_80714998(2);
        func_global_asm_8071498C(func_global_asm_8071720C);
        func_global_asm_807149B8(1);
        func_global_asm_80714C08(
            D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
            1.5f,
            current_actor_pointer,
            (((rand() >> 0xF) % 32767) % 22) + 2,
            0
        );
    }
}

void func_boss_8002A8B8(s32 arg0) {
    if (func_global_asm_80725BA4(player_pointer->x_position, player_pointer->z_position, arg0) == 0) {
        player_pointer->x_position = player_pointer->unk88;
        player_pointer->z_position = player_pointer->unk90;
    }
}

// Jumptable, huge
#pragma GLOBAL_ASM("asm/nonmatchings/boss/Dogadon/func_boss_8002A92C.s")
