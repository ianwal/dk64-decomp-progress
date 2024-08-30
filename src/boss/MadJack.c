#include <ultra64.h>
#include "functions.h"

const s32 D_boss_80036C10[] = {
    0x4F230825,
    0x06325000
};
const s32 D_boss_80036C18[] = {
    0x4F230A25,
    0x052D5000
};
const s32 D_boss_80036C20[] = {
    0x4F230B25,
    0x04285000
};
const s32 D_boss_80036C28[] = {
    0x4F230C28,
    0x04055000
};
const s32 D_boss_80036C30[] = {
    0x5F0A5429,
    0xFB544F23,
    0x0E280401,
    0x50000000
};

const f32 D_boss_80036C40[] = {
    0.8f,
    0.9f,
    1.0f,
    1.1f,
    1.2f,
    0.0f // TODO: Is this just padding?
};

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/MadJack/func_boss_800330D0.s")

extern u8 D_boss_80035B80[4];

typedef struct {
    u8 unk0[0x14 - 0x0];
    u8 unk14;
} Struct800330D0_arg0;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Struct800330D0_arg1;

/*
u8 func_boss_800330D0(Struct800330D0_arg0 *arg0, Struct800330D0_arg1 *arg1) {
    f32 dZ;
    f32 dX;
    s32 closest;
    s32 sp44[0x10];
    s8 temp_a2;
    s8 temp_a3;
    u8 i;
    u8 var_t2;
    u8 var_t4;

    var_t2 = arg1->unk0;
    closest = 9999999;
    var_t4 = var_t2;
    for (i = 0; i < 0x10; i++) {
        dZ = D_global_asm_807FDCA0->unk14[i].unk4 - player_pointer->z_position;
        dX = D_global_asm_807FDCA0->unk14[i].unk0 - player_pointer->x_position;
        sp44[i] = (dZ * dZ) + (dX * dX);
        if (sp44[i] < closest) {
            arg1->unk3 = i;
            closest = sp44[i];
        }
    }
    if (player_pointer->y_position < (current_actor_pointer->y_position - 10.0f)) {
        return D_boss_80035B80[(rand() >> 0xF) % 4];
    }
    temp_a2 = (arg1->unk0 / 4) - (arg1->unk3 / 4);
    temp_a3 = (arg1->unk0 % 4) - (arg1->unk3 % 4);
    if (temp_a2 > 0) {
        var_t2 -= 4;
    } else if (temp_a2 < 0) {
        var_t2 += 4;
    } else if (temp_a3 > 0) {
        var_t2 -= 1;
    } else if (temp_a3 < 0) {
        var_t2 += 1;
    }
    if (arg0->unk14 >= 3) {
        return var_t2;
    }
    if ((var_t2 == arg1->unk2) || ((var_t2 == var_t4))) {
        if ((temp_a2 != 0) || (var_t2 == var_t4)) {
            if ((sp44[(var_t4 - 1) & 0xF] < sp44[(var_t4 + 1) & 0xF]) && (var_t4 & 3)) {
                var_t4--;
            } else if ((sp44[(var_t4 + 1) & 0xF] < sp44[(var_t4 - 1) & 0xF]) && ((var_t4 & 3) != 3)) {
                var_t4++;
            }
        }
        if (((temp_a2 == 0) && (temp_a3 != 0)) || (var_t2 == var_t4)) {
            if ((sp44[(var_t4 - 4) & 0xF] < sp44[(var_t4 + 4) & 0xF]) && (var_t4 >= 4)) {
                var_t4 -= 4;
            } else if ((sp44[(var_t4 + 4) & 0xF] < sp44[(var_t4 - 4) & 0xF]) && (var_t4 < 0xC)) {
                var_t4 += 4;
            }
        }
        // Duplicate return node #37. Try simplifying control flow for better match
        return var_t4;
    }
    return var_t2;
}
*/

void func_global_asm_8061EF4C(s32, s32, s32, f32, f32, f32, f32, f32);

extern f64 D_boss_80036C58;

typedef struct BossStruct0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} BossStruct0;

typedef struct BossStruct2 {
    u8 pad0[0x14];
    u8 unk14;
    u8 unk15;
    u8 unk16;
} BossStruct2;

void func_boss_8003340C(BossStruct0 *arg0) {
    if ((current_actor_pointer->animation_state->unk64 != 0x223) && (arg0->unk1 == arg0->unk3)) {
        playActorAnimation(current_actor_pointer, 0x223);
        func_global_asm_80614D90(current_actor_pointer);
        return;
    }
    if ((current_actor_pointer->animation_state->unk64 != 0x224) && (arg0->unk1 != arg0->unk3)) {
        playActorAnimation(current_actor_pointer, 0x224);
        func_global_asm_80614D90(current_actor_pointer);
    }
}

typedef struct {
    u8 unk0;
    u8 unk1;
} Struct800334A4_arg0;

void func_boss_800334A4(Struct800334A4_arg0 *arg0, f32 arg1) {
    f32 temp_f2;

    temp_f2 = func_global_asm_80612794(((f32)(1.0 - MIN(1.0, current_actor_pointer->animation_state->unk0->unk4 * arg1)) * 1024.0f) + 3072.0f) + 1.0;
    current_actor_pointer->x_position = D_global_asm_807FDCA0->unk14[arg0->unk1].unk0 + ((D_global_asm_807FDCA0->unk14[arg0->unk0].unk0 - D_global_asm_807FDCA0->unk14[arg0->unk1].unk0) * temp_f2);
    current_actor_pointer->z_position = D_global_asm_807FDCA0->unk14[arg0->unk1].unk4 + ((D_global_asm_807FDCA0->unk14[arg0->unk0].unk4 - D_global_asm_807FDCA0->unk14[arg0->unk1].unk4) * temp_f2);
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(D_global_asm_807FDCA0->unk14[arg0->unk1].unk0, D_global_asm_807FDCA0->unk14[arg0->unk1].unk4, D_global_asm_807FDCA0->unk14[arg0->unk0].unk0, D_global_asm_807FDCA0->unk14[arg0->unk0].unk4), 10.0f);
}

void func_boss_800336C0(void) {
    f32 scale;

    scale = current_actor_pointer->animation_state->scale_y / 0.15;
    func_global_asm_80714998(2);
    func_global_asm_8071498C(func_global_asm_8071720C);
    func_global_asm_807149B8(1);
    func_global_asm_80714950(1);
    drawSpriteAtPosition(
        D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        (f64)scale,
        current_actor_pointer->x_position,
        current_actor_pointer->y_position,
        current_actor_pointer->z_position
    );
}

// Oof, I had a crack at this one but it's very fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/boss/MadJack/func_boss_80033784.s")

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Struct8003392C;

void func_boss_8003392C(Struct8003392C *arg0) {
    func_global_asm_80690814(current_actor_pointer, 1);
    func_global_asm_80690A28(0x2C, 2, current_actor_pointer->animation_state->scale_y, D_global_asm_807FDCA0->unk14[arg0->unk3].unk0, D_global_asm_807FDCA0->unk14[arg0->unk3].unk2, D_global_asm_807FDCA0->unk14[arg0->unk3].unk4, 1200.0f, current_actor_pointer);
}

u8 func_boss_800339D8(BossStruct2 *arg0, u8 *arg1) {
    if ((player_pointer->y_position < current_actor_pointer->y_position - 10.0f)) {
        if (arg0->unk14 < 5) {
            arg0->unk15 = arg0->unk16;
            current_actor_pointer->control_state = arg1[arg0->unk15++];
            current_actor_pointer->control_state_progress = 0;
            playActorAnimation(current_actor_pointer, 0);
            return TRUE;
        }
    }
    return FALSE;
}

void func_boss_80033A80(s8 arg0) {
    current_actor_pointer->shadow_opacity += arg0;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->control_state_progress++;
        return;
    }
    if (current_actor_pointer->shadow_opacity >= 0x100) {
        current_actor_pointer->shadow_opacity = 0xFF;
        current_actor_pointer->control_state_progress++;
    }
}

// Jumptable, 7276 bytes of code
// Mad Jack
#pragma GLOBAL_ASM("asm/nonmatchings/boss/MadJack/func_boss_80033AF0.s")

void func_boss_8003575C(void) {
    f32 dx, dz;

    switch (current_actor_pointer->control_state_progress) {
        case 1:
            if (current_actor_pointer->control_state == 0) {
                dx = player_pointer->x_position - current_actor_pointer->x_position;
                dz = player_pointer->z_position - current_actor_pointer->z_position;
                if (((dx * dx) + (dz * dz)) < 4225.0f) { // 65 units away from the player
                    if (player_pointer->control_state != 0x31) {
                        setAction(0x2E, current_actor_pointer, 0);
                    }
                    current_actor_pointer->control_state++;
                }
            }
            break;
        case 3:
            deleteActor(current_actor_pointer);
            break;
    }
    func_global_asm_8061EF4C(D_global_asm_807F5D10, 5, 0x14, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 200.0f, 400.0f);
    renderActor(current_actor_pointer, 0);
}
