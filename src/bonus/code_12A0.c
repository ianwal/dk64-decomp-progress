#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x14 - 0x0];
    u8 unk14;
    u8 unk15;
    s16 unk16;
    u8 unk18;
    u8 unk19;
} AAD_bonus_800252A0;

extern u8* D_bonus_8002D8B0[];

// rodata
const u32 D_bonus_8002DC90[] = {
    0x00010200,
    0x03040000,
};

const u32 D_bonus_8002DC98[] = {
    0x04020300,
    0x01000000,
};

const u32 D_bonus_8002DCA0[] = {
    0x02000104,
    0x00030000,
};

const u32 D_bonus_8002DCA8[] = {
    0x03010002,
    0x00040000,
};

// rodata
// const char D_bonus_8002DCB0[] = "HIT";
/*
const f32 D_bonus_8002DCB4 = 0.3f;
const f32 D_bonus_8002DCB8 = 0.09f;
const f32 D_bonus_8002DCE4 = 0.09f;
const f64 D_bonus_8002DD00 = 6.28318548202514648; // TWO_PI
const f64 D_bonus_8002DD08 = 90.0;
const f64 D_bonus_8002DD10 = 0.3;
*/

extern void* D_global_asm_8074E880[];

void func_global_asm_80627948(Actor*, s32, s32, s32);
Gfx *func_global_asm_8068DC54(Gfx *, s32, s32, void *, s32, void *);
Gfx *func_global_asm_806FE078(Gfx *, u8, s32, f32, f32, f32, f32);
int func_global_asm_80717404(); // TODO: Signature

Gfx *func_bonus_800252A0(Gfx *dl, Actor *arg1) {
    AAD_bonus_800252A0 *aaD;
    aaD = arg1->additional_actor_data;
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xC8, 0xC8, 0xC8, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_2000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    dl = func_global_asm_806FE078(dl, aaD->unk19, 8, 30.0f, 36.0f, 0.0f, 1.5f);
    return func_global_asm_8068DC54(dl, 0x26, 0x32, &aaD->unk14, aaD->unk16, &aaD->unk18);
}

Actor* func_bonus_800253E4(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    BaaD2 *tmp;
    if (spawnActor(ACTOR_BANDIT_SLOT, arg0)) {
        tmp = last_spawned_actor->BaaD2;
        last_spawned_actor->x_position = arg1;
        last_spawned_actor->y_position = arg2;
        last_spawned_actor->z_position = arg3;
        tmp->unk0 = current_actor_pointer;
    }
    return last_spawned_actor;
}

u8 func_bonus_80025480(Actor **arg0, u8 arg1) {
    return D_bonus_8002D8B0[arg1][arg0[arg1]->unk15F];
}

void func_bonus_800254B0(s16 x, s16 y, s16 z, s16 count) {
    s16 i;

    for (i = 0; i < count; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(&func_global_asm_80717404);
        func_global_asm_80714950(1);
        drawSpriteAtPosition(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3], 0.3f, x, y, z);
    }
}

void func_bonus_8002563C(s32 arg0) {
    PlayerAdditionalActorData *PaaD = player_pointer->PaaD;
    func_global_asm_8061C464(PaaD->unk104, player_pointer, 4, 0, 0xAA, 0, 0, 0, 0, 0, 0.09f);
    current_actor_pointer->control_state = 3;
    current_actor_pointer->control_state_progress = 1;
    current_actor_pointer->unk168 = 0;
}

void func_bonus_800256C4(Actor **arg0, u8 arg1) {
    u8 i;

    for (i = 0; i < 4; i++) {
        arg0[i]->control_state++;
        arg0[i]->unkF0 = arg1;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_12A0/func_bonus_8002570C.s")

typedef struct {
    Actor *unk0;
    s16 unk4;
} AAD_800261B8;

void func_bonus_800261B8(void) {
    AAD_800261B8 *aaD;
    s16 temp_t0;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->z_rotation = (((rand() >> 0xF) % 6) * 0x3C000) / 360;
    }
    switch (current_actor_pointer->control_state) {
        case 1:
            aaD->unk4 = -0x18;
            current_actor_pointer->control_state++;
            break;
        case 2:
            if (aaD->unk4 < 0) {
                current_actor_pointer->z_rotation += aaD->unk4;
                aaD->unk4 += 2;
            } else {
                current_actor_pointer->control_state++;
                aaD->unk4 = current_actor_pointer->unkF0;
            }
            break;
        case 4:
            temp_t0 = 683 - (current_actor_pointer->z_rotation % 683);
            if (temp_t0 < aaD->unk4) {
                current_actor_pointer->control_state++;
                if (aaD->unk0->control_state < 8) {
                    aaD->unk0->control_state = 5;
                    aaD->unk0->control_state_progress = 0;
                }
                current_actor_pointer->unk160 = func_global_asm_806118FC((aaD->unk4 - temp_t0) * 0.015625);
                current_actor_pointer->unk168 = (current_actor_pointer->z_rotation + temp_t0) & 0xFFF;
                current_actor_pointer->unk15F = current_actor_pointer->unk168 / 683;
                playSoundAtActorPosition(current_actor_pointer, 0x17A, 0xFF, 0x7F, 1);
            }
            // fallthrough
        case 3:
            current_actor_pointer->z_rotation += aaD->unk4;
            current_actor_pointer->z_rotation &= 0xFFF;
            break;
        case 5:
            if (current_actor_pointer->unk160 < 6.2831854820251465) {
                current_actor_pointer->z_rotation = (func_global_asm_80612D1C(current_actor_pointer->unk160) * 90.0) + current_actor_pointer->unk168;
                current_actor_pointer->unk160 += 0.3;
            } else {
                current_actor_pointer->z_rotation = current_actor_pointer->unk168;
                current_actor_pointer->control_state = 0;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_bonus_800264E0(u8 arg0, u8 arg1) {
    playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_global_asm_8069D2AC(0x81, 0, 0x78, getTextString(0x1A, arg1, 1), 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x28, 1.0f);
    setAction(0x44, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        func_global_asm_80627948(player_pointer, 5, 0x21, 5);
    }
}

void func_bonus_800265C0(u8 arg0, u8 arg1) {
    current_actor_pointer->unk11C->control_state = 0;
    func_global_asm_8069D2AC(0x81, 0, 0x78, getTextString(0x1A, arg1, 1), 0, 0x28, 8, 8);
    playSong(0x57, 1.0f);
    setAction(0x43, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        func_global_asm_80627948(player_pointer, 5, 0x21, 5);
    }
}
