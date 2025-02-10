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

// rodata
static const u32 D_bonus_8002DC90[] = {
    0x00010200,
    0x03040000,
};

static const u32 D_bonus_8002DC98[] = {
    0x04020300,
    0x01000000,
};

static const u32 D_bonus_8002DCA0[] = {
    0x02000104,
    0x00030000,
};

static const u32 D_bonus_8002DCA8[] = {
    0x03010002,
    0x00040000,
};

// .data
static u8 *D_bonus_8002D8B0[] = {
    D_bonus_8002DC90,
    D_bonus_8002DC98,
    D_bonus_8002DCA0,
    D_bonus_8002DCA8,
};

Gfx *func_global_asm_8068DC54(Gfx *, s32, s32, void *, s32, void *);
void func_global_asm_80717404(otherSpriteControl *, s8 *); // TODO: Signature

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

Actor* func_bonus_800253E4(s32 model, s16 x, s16 y, s16 z) {
    BaaD2 *tmp;
    if (spawnActor(ACTOR_BANDIT_SLOT, model)) {
        tmp = last_spawned_actor->BaaD2;
        last_spawned_actor->x_position = x;
        last_spawned_actor->y_position = y;
        last_spawned_actor->z_position = z;
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
        func_global_asm_8071498C(func_global_asm_80717404);
        func_global_asm_80714950(1);
        drawSpriteAtPosition(D_global_asm_8074E880[RandClamp(1000) % 3], 0.3f, x, y, z);
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

// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_12A0/func_bonus_8002570C.s")

typedef struct HandleAAD {
    Actor *reels[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s8 unk18;
    u8 unk19;
    u8 unk1A;
    s8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    s8 unk1F;
    void *unk20;
} HandleAAD;

void func_global_asm_806A2A10(s32, s32, s32);
u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);
void func_global_asm_80737924(s32);
extern SpriteData D_global_asm_80720CF0;
extern SoundState *D_global_asm_807457E4[];

/*
void func_bonus_8002570C(void) {
    PlayerAdditionalActorData *sp4C;
    SoundState *temp_a0;
    u8 i;
    s32 t;
    u32 u;
    HandleAAD *aaD;
    u8 div;

    sp4C = player_pointer->additional_actor_data;
    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->x_position = 52.0f;
        current_actor_pointer->z_position = 18.0f;
        aaD->unk19 = func_global_asm_806FDB8C(1, "HIT", 8, 0.0f, 0.0f, 0.0f);
        func_global_asm_806FDAB8(aaD->unk19, 0.0f);
        aaD->unk16 = 3;
        aaD->unk14 = 3;
        aaD->reels[0] = func_bonus_800253E4(0x90, -0x15, 1, 0x12);
        aaD->reels[1] = func_bonus_800253E4(0x91, -7, 1, 0x12);
        aaD->reels[2] = func_bonus_800253E4(0x92, 7, 1, 0x12);
        aaD->reels[3] = func_bonus_800253E4(0x93, 0x15, 1, 0x12);
        setAction(0x49, NULL, 0U);
        func_global_asm_8061C6A8(sp4C->unk104, player_pointer, 6, 0, 0xAA, 0, 0, 0, 0, 0, 1.0f);
        playCutscene(NULL, 1, 1);
        switch (current_map) {
        case MAP_BATTY_BARREL_BANDIT_EASY:
            aaD->unk1C = 0x2DU;
            aaD->unk1E = 0x20U;
            aaD->unk1D = 0x20U;
            break;
        case MAP_BATTY_BARREL_BANDIT_EASY_2:
            aaD->unk1C = 0x2DU;
            aaD->unk1E = 0x34U;
            aaD->unk1D = 0x20U;
            break;
        case MAP_BATTY_BARREL_BANDIT_NORMAL:
            aaD->unk1C = 0x28U;
            aaD->unk1E = 0x34U;
            aaD->unk1D = 0x2AU;
            break;
        case MAP_BATTY_BARREL_BANDIT_HARD:
            aaD->unk1C = 0x23U;
            aaD->unk1E = 0x40U;
            aaD->unk1D = 0x37U;
            break;
        }
    }
    if ((aaD->unk1A != 0) && (current_actor_pointer->unk11C->control_state == 5)) {
        current_actor_pointer->control_state = 1;
        current_actor_pointer->control_state_progress = 0;
    }
    switch (current_actor_pointer->control_state) {
    case 0:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (is_cutscene_active != 1) {
                loadText(current_actor_pointer, 0U, 3U);
                current_actor_pointer->control_state_progress += 1;
            }
            break;
        case 1:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                current_actor_pointer->control_state = 3;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_8071495C();
                func_global_asm_80714998(2U);
                func_global_asm_807149FC(-1);
                aaD->unk20 = drawSpriteAtPosition(&D_global_asm_80720CF0, 1.0f, 40.0f, 200.0f, 5.0f);
                break;
            }
            break;
        }
        break;
    case 3:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806A2A10(0xDC, 0x2A, aaD->unk1C);
            current_actor_pointer->control_state_progress = 1;
        case 1:
            if (aaD->reels[3]->control_state == 0) {
                current_actor_pointer->control_state = 2;
            }
            break;
        }
        break;
    case 4:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            aaD->unk10 = 0x400;
            aaD->unk12 = 0x40;
            current_actor_pointer->control_state_progress += 1;
            playSoundAtActorPosition(current_actor_pointer, 0x179, 0xFFU, 0x7F, 1U);
            if (aaD->unk1A == 0) {
                aaD->unk1A = 1U;
                func_global_asm_806A2B08(current_actor_pointer->unk11C);
                playSong(8, 1.0f);
            }
            break;
        case 1:
            current_actor_pointer->z_rotation = (func_global_asm_80612794(aaD->unk10) * -1024.0f) + 1024.0f;
            aaD->unk10 += aaD->unk12;
            if (aaD->unk10 >= 0x800) {
                aaD->unk12 = -0x40;
                div = 2;
                func_bonus_800256C4(aaD,
                    (u32) (aaD->unk1E +
                    ((aaD->unk1D - aaD->unk1E) *
                    ((aaD->unk16 - 1) / (f32) div))));
                current_actor_pointer->unk6E[0] = playSound(0x24D, 0x7FFFU, 64.0f, 1.0f, 0, 0);
                func_global_asm_8061C464(sp4C->unk104, current_player, 4, 0, 0x78, 0, 0, 0, 0, 0, 0.09f);
            } else if (aaD->unk10 < 0x400) {
                current_actor_pointer->control_state = 5;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        }
        break;
    case 5:
        if (current_actor_pointer->unk168 == 4) {
            current_actor_pointer->control_state = 7;
            current_actor_pointer->control_state_progress = 0;
            break;
        }
        if (current_actor_pointer->control_state_progress != 0) {
            func_bonus_800254B0(
                aaD->reels[current_actor_pointer->unk168]->x_position, 
                aaD->reels[current_actor_pointer->unk168]->y_position, 
                aaD->reels[current_actor_pointer->unk168]->z_position + 20.0f, 0xF);
            aaD->reels[current_actor_pointer->unk168]->control_state++;
            current_actor_pointer->unk168++;
            current_actor_pointer->control_state = 6;
            current_actor_pointer->control_state_progress = 0;
            break;
        }
        break;
    case 7:
        temp_a0 = D_global_asm_807457E4[current_actor_pointer->unk6E[0]];
        if (temp_a0) {
            func_global_asm_80737924(temp_a0);
        }
    case 1:
        if (current_actor_pointer->unk11C->control_state != 5) {
            if ((func_bonus_80025480(aaD, 0) == 0) && 
                (func_bonus_80025480(aaD, 0) == func_bonus_80025480(aaD, 1)) &&
                (func_bonus_80025480(aaD, 1) == func_bonus_80025480(aaD, 2)) &&
                (func_bonus_80025480(aaD, 2) == func_bonus_80025480(aaD, 3))) {
                func_global_asm_806FDAB8(aaD->unk19, MATH_PI_F);
                aaD->unk16--;
                if (aaD->unk16 == 0) {
                    player_pointer->control_state_progress = 1;
                    func_bonus_800264E0(0U, 0U);
                    current_actor_pointer->control_state = 8;
                    aaD->unk10 = 0;
                    aaD->unk1A = 0U;
                    playCutscene(NULL, 0, 0x11);
                } else {
                    func_global_asm_8069D2AC(0U, 0, 0xB4, getTextString(0x1AU, 0xB, 1), 0U, 0x28U, 8U, 8U);
                    func_bonus_8002563C(aaD);
                }
            } else {
                func_global_asm_8069D2AC(0U, 0, 0xB4, getTextString(0x1AU, 0xC, 1), 0U, 0x28U, 8U, 8U);
                func_bonus_8002563C(aaD);
            }
        } else {
            player_pointer->control_state_progress = 2U;
            func_bonus_800265C0(0, 1);
            current_actor_pointer->control_state = 9;
            aaD->unk10 = 0;
            aaD->unk1A = 0U;
            playCutscene(NULL, 0, 0x11);
        }
        break;
    case 8:
        for (i = 0; i < 4; i++) {
            if (!((s32)((aaD->unk10 - (i * 8)) + 0x18) % 32)) {
                func_bonus_800254B0(
                    aaD->reels[i]->x_position,
                    aaD->reels[i]->y_position,
                    aaD->reels[i]->z_position + 20.0f, 0xF);
            }
        }
    case 9:
        aaD->unk10++;
        break;
    }
    if ((current_actor_pointer->control_state > 0) && (current_actor_pointer->control_state < 8)) {
        addActorToTextOverlayRenderArray(func_bonus_800252A0, current_actor_pointer, 3U);
    }
    if (current_actor_pointer->control_state >= 8) {
        if (aaD->unk20) {
            func_global_asm_80715908(aaD->unk20);
            aaD->unk20 = NULL;
        }
    }
    renderActor(current_actor_pointer, 0U);
}
*/

typedef struct {
    Actor *unk0;
    s16 unk4;
} AAD_800261B8;

void func_bonus_800261B8(void) {
    AAD_800261B8 *aaD;
    s16 temp_t0;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->z_rotation = (RandClamp(6) * 0x3C000) / 360;
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

void func_bonus_800264E0(u8 arg0, u8 textIndex) {
    playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_global_asm_8069D2AC(0x81, 0, 0x78, getTextString(0x1A, textIndex, 1), 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x28, 1.0f);
    setAction(0x44, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0) {
        func_global_asm_80627948(player_pointer, 5, 0x21, 5);
    }
}

void func_bonus_800265C0(u8 arg0, u8 textIndex) {
    current_actor_pointer->unk11C->control_state = 0;
    func_global_asm_8069D2AC(0x81, 0, 0x78, getTextString(0x1A, textIndex, 1), 0, 0x28, 8, 8);
    playSong(0x57, 1.0f);
    setAction(0x43, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0) {
        func_global_asm_80627948(player_pointer, 5, 0x21, 5);
    }
}
