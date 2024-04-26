#include <ultra64.h>
#include "functions.h"

int func_global_asm_8071827C(); // TODO: Signature
int func_global_asm_807197B4(); // TODO: Signature

extern s32 D_global_asm_8071FC0C; // TODO: Datatype
extern s32 D_global_asm_8071FC40;
extern s32 D_global_asm_8071FE08;
extern s32 D_global_asm_8071FED0; // TODO: Datatype
extern s32 D_global_asm_8071FF18;
extern s32 D_global_asm_8071FF40;
extern s32 D_global_asm_8071FF58;
extern s32 D_global_asm_8071FFA0; // TODO: Datatype
extern s32 *D_global_asm_8072006C;
extern s32 D_global_asm_80720120;
extern s32 D_global_asm_80720558;
extern s32 D_global_asm_8072073C;
extern s32 D_global_asm_80720B58; // TODO: Datatype
extern s32 D_global_asm_807210EC;
extern s32 D_global_asm_80721158;
extern s32 D_global_asm_8072139C;

void func_global_asm_80718BF4(void);

extern s32 D_global_asm_8074E880[];
extern u8 D_global_asm_80750AD0;

typedef struct {
    s32 unk0[4];
} Struct8074E898;

extern Struct8074E898 D_global_asm_8074E898;
extern s32 D_global_asm_80720B24;

void func_global_asm_807184F4(Struct80717D84 *arg0, s32 arg1);
void func_global_asm_80685E78(Actor*);

typedef struct {
    s32 unk0;
    s16 unk4;
    s8 unk6;
} AAD_global_asm_80685708;

void func_global_asm_80686390(Actor*, f32, f32, f32, f32);
void func_global_asm_80685F60(Actor *actor);

void func_global_asm_80684550(Actor *actor, u8 boneIndex, f32 scale) {
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(&func_global_asm_8071AF30);
    func_global_asm_80714950(actor);
    func_global_asm_80714A28(4);
    func_global_asm_80714C08(&D_global_asm_80720120, scale, current_actor_pointer, boneIndex, 0);
}

void func_global_asm_806845B8(u8 arg0, u8 arg1) {
    f32 scale;
    u8 sp2B;

    if ((object_timer & 3) == 0) {
        scale = current_actor_pointer->animation_state->scale_y / 0.15;
        sp2B = (((rand() >> 0xF) % 0x7FFF) % ((arg1 - arg0) + 1)) + arg0;
        func_global_asm_80714998(3);
        changeActorColor(0xE6, 0xE6, 0xE6, 0xE6);
        func_global_asm_8068588C(current_actor_pointer, sp2B, scale, 0.0f, 0.0f, 0.0f, -0x78);
    }
}

// spawnShockwave(xPosition, yPosition, zPosition, xzScale, yScale, parentActor, arg6)
void func_global_asm_806846B4(f32 xPosition, f32 yPosition, f32 zPosition, f32 xzScale, f32 yScale, Actor *arg5, u8 arg6) {
    s32 modelIndex;

    modelIndex = 0xAD;
    if (arg5) {
        switch (arg5->unk58) {
            case ACTOR_TINY:
            case ACTOR_KASPLAT_TINY:
                modelIndex = 0xD1;
                break;
            case ACTOR_LANKY:
            case ACTOR_KASPLAT_LANKY:
                modelIndex = 0xD0;
                break;
            case ACTOR_CHUNKY:
            case ACTOR_KASPLAT_CHUNKY:
                modelIndex = 0xCF;
                break;
            case ACTOR_DIDDY:
            case ACTOR_KASPLAT_DIDDY:
                modelIndex = 0xAE;
                break;
        }
    }
    spawnActor(ACTOR_SHOCKWAVE, modelIndex);
    last_spawned_actor->unk11C = arg5;
    last_spawned_actor->animation_state->scale_x = xzScale;
    last_spawned_actor->animation_state->scale_z = xzScale;
    last_spawned_actor->animation_state->scale_y = yScale;
    last_spawned_actor->x_position = xPosition;
    last_spawned_actor->y_position = yPosition;
    last_spawned_actor->z_position = zPosition;
    if (arg5 && (arg5->interactable & 1)) {
        if (arg6) {
            last_spawned_actor->unk168 = 0xF;
            last_spawned_actor->unk160 = 1.11;
            last_spawned_actor->unk15F = 1;
        } else {
            last_spawned_actor->unk168 = 0x19;
            last_spawned_actor->unk160 = 1.09;
        }
    } else {
        last_spawned_actor->unk168 = 0x20;
        last_spawned_actor->unk160 = 1.07;
        last_spawned_actor->unk15F = 0;
    }
}

void func_global_asm_80684850(u8 arg0) {
    if ((object_timer & 0x1F) == 0) {
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0x3C);
        func_global_asm_8071498C(&func_global_asm_807197B4);
        if (arg0) {
            func_global_asm_80714C08(&D_global_asm_8071FF58, 0.05f, current_actor_pointer, arg0, 0);
            return;
        }
        drawSpriteAtPosition(&D_global_asm_8071FF58, 0.05f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    }
}

void func_global_asm_80684900(u8 arg0) {
    if (arg0 != 0) {
        func_global_asm_80714950(((rand() >> 0xF) % 10) + 0x8008);
    } else {
        func_global_asm_80714950(((rand() >> 0xF) % 8) + 6);
    }
    func_global_asm_807149FC(2);
    func_global_asm_8071498C(&func_global_asm_80717930);
    func_global_asm_807149B8(1);
    func_global_asm_80714A28(4);
    func_global_asm_80714C08(&D_global_asm_8072139C, (((rand() >> 0xF) % 50) / 80.0) + 0.1, current_actor_pointer, 8, 0);
}

void func_global_asm_80684A00(s16 boneIndex, s8 arg1) {
    f32 x, y, z, scale;

    scale = current_actor_pointer->animation_state->scale_y / 0.15;
    getBonePosition(current_actor_pointer, boneIndex, &x, &y, &z);
    func_global_asm_80714950((((rand() >> 0xF) % 100) + 400) * arg1);
    func_global_asm_8071498C(&func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    drawSpriteAtPosition(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        scale * 0.8,
        ((rand() >> 0xF) % 20) + (x - 10.0f),
        y,
        ((rand() >> 0xF) % 20) + (z - 10.0f)
    );
}

void func_global_asm_80684BB0(s16 boneIndex, s16 arg1, s16 arg2) {
    f32 x;
    f32 y;
    f32 z;
    f32 scale;

    scale = current_actor_pointer->animation_state->scale_y / 0.15;
    getBonePosition(current_actor_pointer, boneIndex, &x, &y, &z);
    func_global_asm_80714950(arg1 + (arg2 << 0x10));
    func_global_asm_8071498C(&func_global_asm_8071F2F8);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(MAX(2.0, arg2 * 0.02));
    drawSpriteAtPosition(
        D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        scale * 0.8,
        ((rand() >> 0xF) % 60) + (x - 30.0f),
        y,
        ((rand() >> 0xF) % 60) + (z - 30.0f)
    );
}

void func_global_asm_80684D98(u8 arg0) {
    f32 randomX;
    f32 randomZ;
    f32 randomY;
    s32 i;

    if (((func_global_asm_806119A0() / 10000U) % arg0) == 0) {
        if (D_global_asm_80750AD0 == 0) {
            for (i = 0; i < 4; i++) {
                randomX = (f32)((func_global_asm_806119A0() / 10000U) % 200) / 10.0 - 5.0;
                randomY = (f32)((func_global_asm_806119A0() / 10000U) % 200) / 10.0 - 5.0;
                randomZ = (f32)((func_global_asm_806119A0() / 10000U) % 200) / 10.0 - 5.0;
                func_global_asm_807149B8(1);
                func_global_asm_80714950(1);
                func_global_asm_807149FC(-1);
                func_global_asm_8071498C(&func_global_asm_80718BF4);
                func_global_asm_80714A28(4);
                drawSpriteAtPosition(
                    &D_global_asm_8071FC40,
                    0.0f,
                    current_actor_pointer->x_position + randomX,
                    current_actor_pointer->y_position + randomY,
                    current_actor_pointer->z_position + randomZ
                );
            }
        }
    }
}

void func_global_asm_80685020(u8 arg0, u8 arg1) {
    if ((arg0 & object_timer) == 0) {
        func_global_asm_8071498C(&func_global_asm_80718BF4);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714A28(4);
        if (arg1) {
            func_global_asm_80714C08(&D_global_asm_8071FC40, 0, current_actor_pointer, arg1, 0);
            return;
        }
        drawSpriteAtPosition(&D_global_asm_8071FC40, 0, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    }
}

int func_global_asm_8071910C();

void func_global_asm_806850D0(void) {
    f32 scale;
    s32 temp_s0;

    scale = current_actor_pointer->animation_state->scale_y / 0.15;
    func_global_asm_807149B8(0);
    func_global_asm_807149FC(1);
    drawSpriteAtPosition(&D_global_asm_8071FE08,
        scale * 0.75,
        current_actor_pointer->x_position,
        current_actor_pointer->y_position,
        current_actor_pointer->z_position
    );
    for (temp_s0 = 0; temp_s0 < 7; temp_s0++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(&func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(0);
        drawSpriteAtPosition(&D_global_asm_8072073C,
            scale * 0.15,
            current_actor_pointer->x_position,
            current_actor_pointer->y_position,
            current_actor_pointer->z_position
        );
    }
}

void func_global_asm_80685210(f32 arg0, s16 arg1, s16 arg2) {
    if ((((u32)object_timer % 3) == 0) && (arg1 < current_actor_pointer->unkB8)) {
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_80714950(-0x32);
        func_global_asm_80714A28(4);
        func_global_asm_80714C08(&D_global_asm_8071FF18, arg0, current_actor_pointer, arg2, 0);
    }
}

void func_global_asm_806852C4(f32 scale, f32 x, f32 y, f32 z) {
    s16 i;

    for (i = 0; i < 8; i++) {
        func_global_asm_8071498C(&func_global_asm_80719A0C);
        func_global_asm_80714950(i);
        func_global_asm_807149B8(1);
        changeActorColor(0xFF, 0xFF, 0xFF, 0xC8);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, scale, x, y, z);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_global_asm_80685390.s")

/*
typedef struct {
    f32 *unk0;
    s32 unk4;
    s32 unk8;
} Struct8074E88C;

extern Struct8074E88C D_global_asm_8074E88C;

typedef struct {
    f32 unk0;
    u16 unk4;
    u8 unk6;
} AAD_global_asm_80685390;

// TODO: Eh doable, kinda fiddly
void func_global_asm_80685390(void) {
    AAD_global_asm_80685390 *temp_v0;
    Struct8074E88C sp20;

    temp_v0 = current_actor_pointer->additional_actor_data;
    sp20 = D_global_asm_8074E88C;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_v0->unk0 = current_actor_pointer->animation_state->scale_y;
    }
    temp_v0->unk4++;
    switch (current_actor_pointer->control_state) {
        case 0:
            current_actor_pointer->animation_state->scale_y = sp20.unk0[temp_v0->unk6] * (temp_v0->unk4 * temp_v0->unk0 * 0.3333333433f);
            if (temp_v0->unk4 > 3.0f) {
                current_actor_pointer->control_state = 1;
                temp_v0->unk4 = 0;
                func_global_asm_8068842C(current_actor_pointer, 0, 1);
                func_global_asm_80688370(current_actor_pointer, 0, 0.5f);
            }
            break;
        case 1:
            if (func_global_asm_80688540(current_actor_pointer, 0) == 0) {
                deleteActor(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_80685520(f32 scale, u8 arg1, f32 x, f32 y, f32 z) {
    s32 temp_s0;
    s32 i;

    if (D_global_asm_80750AD0 == 0) {
        if (arg1 > 0) {
            func_global_asm_806852C4(scale, x, y, z);
        }
        if (arg1 >= 2) {
            for (i = 0; i < 8; i++) {
                func_global_asm_8071498C(&func_global_asm_80719B88);
                func_global_asm_80714950(i);
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(-1);
                changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
                drawSpriteAtPosition(&D_global_asm_8071FF40, scale * 0.5, x, y, z);
            }
        }
        if (arg1 >= 3) {
            for (i = 0; i < 9; i++) {
                func_global_asm_8071498C(&func_global_asm_80719C00);
                func_global_asm_80714950(i);
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(-1);
                changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
                drawSpriteAtPosition(D_global_asm_8074E880[i % 3], scale, x, y, z);
            }
        }
    }
}

void func_global_asm_80685708(Actor *arg0, u8 arg1) {
    AAD_global_asm_80685708* aaD;
    Struct8074E898 sp34;
    f32 p1 = (arg0->animation_state->scale_y / 0.15);
    s32 pad;

    sp34 = D_global_asm_8074E898;
    if (arg1) {
        func_global_asm_80685520(p1 * 0.36, arg1, arg0->x_position, arg0->y_position + 4.0f, arg0->z_position);
        spawnActor(ACTOR_SHOCKWAVE_SLAM, sp34.unk0[arg1]);
        moveAndScaleActorToAnother(last_spawned_actor, arg0, arg0->animation_state->scale_y * 0.5f);
        aaD = last_spawned_actor->additional_actor_data;
        aaD->unk6 = arg1 - 1;
    }
}

void func_global_asm_8068581C(Actor *actor, s16 boneIndex, f32 scale, f32 x, f32 y, f32 z, s32 arg6) {
    func_global_asm_80714998(2);
    changeActorColor(0xFF, 0xFF, 0xFF, 0xC8);
    func_global_asm_8068588C(actor, boneIndex, scale, x, y, z, arg6);
}

void func_global_asm_8068588C(Actor *actor, s16 boneIndex, f32 scale, f32 x, f32 y, f32 z, s32 arg6) {
    func_global_asm_807149B8(1);
    func_global_asm_806858E8(actor, boneIndex, scale, x, y, z, arg6);
}

void func_global_asm_806858E8(Actor *actor, s16 boneIndex, f32 scale, f32 x, f32 y, f32 z, s32 arg6) {
    if (actor != NULL) {
        if (boneIndex != 0) {
            getBonePosition(actor, boneIndex, &x, &y, &z);
        }
    }
    func_global_asm_8071498C(&func_global_asm_80718080);
    func_global_asm_80714950(arg6);
    drawSpriteAtPosition(&D_global_asm_8071FFA0, scale, x, y + 5.0f, z)->unk338 = actor;
}

void func_global_asm_80685984(f32 scale, f32 x, f32 y, f32 z) {
    s32 pad;

    if (((rand() >> 0xF) % 100) >= 0x33) {
        func_global_asm_80714998(2);
        func_global_asm_80714950((rand() >> 0xF) % 360);
        func_global_asm_807149B8(1);
        changeActorColor(0x9B, 0x9B, 0x9B, 0xC8);
        func_global_asm_8071498C(&func_global_asm_80719EF4);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, scale, (((rand() >> 0xF) % 100000) % 10) + (x - 5.0f), y, (((rand() >> 0xF) % 100000) % 10) + (z - 5.0f));
    }
}

void func_global_asm_80685B44(void *sprite, u8 arg1, f32 scale, u8 arg3, u8 arg4, s16 arg5, s16 x, s16 y, s16 z) {
    s8 randomZOffset;
    s8 randomXOffset;
    s16 i;

    for (i = 0; i < arg3; i++) {
        randomXOffset = (((rand() >> 0xF) % 32767) % (arg4 * 2)) + -arg4;
        randomZOffset = (((rand() >> 0xF) % 32767) % (arg4 * 2)) + -arg4;
        func_global_asm_80714950(-arg5 - ((rand() >> 0xF) % 80));
        func_global_asm_8071498C(&func_global_asm_807180F4);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(2);
        if (arg1) {
            func_global_asm_8071496C(arg1);
        }
        drawSpriteAtPosition(sprite, scale, x + randomXOffset, y, z + randomZOffset);
    }
}

void func_global_asm_80685D84(Actor *actor) {
    if (!(actor->unk64 & 4)) {
        if ((actor->object_properties_bitfield & 0x10) && ((actor->unk6A ^ actor->unk6C) & 4)) {
            func_global_asm_80686390(actor, 0, actor->x_position, actor->unkAC, actor->z_position);
        }
        if (actor->unk6A & 4) {
            func_global_asm_80685F60(actor);
        }
    }
    if ((actor->unk68 & 0x40) && func_global_asm_80665AAC(actor) && (!(actor->unk6A & 0x800)) && actor->floor <= actor->y_position) {
        func_global_asm_806A081C(actor);
    }
    if (actor->unk68 & 0x80) {
        func_global_asm_80663844(actor);
    }
}

// rodata, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_global_asm_80685E78.s")

/*
void func_global_asm_80685E78(Actor *arg0) {
    f32 sp28;
    ActorAnimationState *temp_v0;

    temp_v0 = arg0->animation_state;
    if (temp_v0 != NULL) {
        sp28 = temp_v0->scale_y / 0.15;
    } else {
        sp28 = 1.0;
    }
    func_global_asm_80714998(3);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(1);
    func_global_asm_8071498C(&func_global_asm_807184F4);
    func_global_asm_80714A28(4);
    changeActorColor(0xC8, 0xFF, 0xFF, 0xC8);
    drawSpriteAtPosition(&D_global_asm_8071FED0, sp28 * 0.6, arg0->x_position, arg0->unkAC, arg0->z_position)->unk338 = arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_global_asm_80685F60.s")

extern s16 D_global_asm_80753A08[];
extern s16 D_global_asm_80753A18[];

/*
// TODO: Close, something up with phi_v1
void func_global_asm_80685F60(Actor *actor) {
    f32 phi_f0;
    u8 phi_v1;

    phi_v1 = 0;
    if ((actor->unk0 != NULL) && (actor->animation_state != NULL)) {
        if (actor->interactable == 1) {
            if (character_change_array[cc_player_index].unk2C0 == 1) {
                phi_f0 = D_global_asm_80753A08[actor->unk58];
            } else {
                phi_f0 = D_global_asm_80753A18[actor->unk58];
            }
        } else {
            phi_f0 = actor->unk15E;
        }
        if ((actor->unkAC - phi_f0) <= actor->y_position) {
            if ((object_timer & 3) == 0) {
                phi_v1 = (actor->unkB8 != 0.0) || ((actor->unk118) && (actor->unk118->unk10 != 0)) ? 1 : 0;
            }
            if (phi_v1) {
                func_global_asm_80714950(1);
            } else {
                phi_v1 = (actor->unkB8 == 0.0) && (((object_timer % 24U) == 0) || (actor->unkBC != 0.0)) ? 1 : 0;
            }
            if (phi_v1) {
                func_global_asm_80685E78(actor);
            }
        }
    }
}
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_global_asm_8068613C.s")

/*
// TODO: Pretty close
void func_global_asm_8068613C(Actor *arg0) {
    f64 sp48;
    ActorAnimationState *temp_v0;
    f32 var_f20;
    u8 temp_v1;
    u8 i;

    temp_v0 = arg0->animation_state;
    if (temp_v0 != NULL) {
        var_f20 = temp_v0->scale_y / 0.15;
    } else {
        var_f20 = 1.0f;
    }
    if (arg0->unk58 == ACTOR_BOSS_PROJECTILE_FIREBALL) {
        var_f20 *= 2;
        func_global_asm_8068588C(arg0, 0, 4.0f, arg0->x_position, arg0->y_position, arg0->z_position, -0x96);
        deleteActor(arg0);
    }
    playSoundAtActorPosition(arg0, 0xC, 0xFF, 0x7F, 1);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(1);
    changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
    drawSpriteAtPosition(&D_global_asm_8071FC0C, var_f20 * 0.65, arg0->x_position, arg0->unkAC + 15.0f, arg0->z_position);
    if (D_global_asm_80750AD0 == 0) {
        temp_v1 = (func_global_asm_806119A0() & 3) + 4;
        for (i = 0; i < temp_v1; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(&func_global_asm_8071DB74);
            func_global_asm_80714A28(4);
            drawSpriteAtPosition(&D_global_asm_80720B58, var_f20 * 0.1, arg0->x_position, arg0->unkAC, arg0->z_position);
        }
    }
}
*/

void func_global_asm_80686340(void) {
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(0x14);
    func_global_asm_8071498C(&func_global_asm_8071827C);
    changeActorColor(0xFF, 0xFF, 0xFF, 0xC8);
    func_global_asm_80714A28(4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_global_asm_80686390.s")

void func_global_asm_8068696C(Actor *actor) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714950(actor);
        func_global_asm_8071498C(&func_global_asm_8071DC90);
        drawSpriteAtPosition(D_global_asm_8074E880[i % 3], 0.7f, actor->x_position, actor->y_position, actor->z_position);
    }
}

void func_global_asm_80686A5C(Actor *actor, f32 arg1, f32 arg2, s32 arg3) {
    s32 i;
    for (i = 0; i < 3; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714950(actor);
        func_global_asm_8071498C(func_global_asm_8071E1C8);
        func_global_asm_8071E110(drawSpriteAtPosition(D_global_asm_8074E880[i], 0.7f, actor->x_position, actor->y_position, actor->z_position), 1, (i * 1365.3334f), arg1, arg2, arg3);
    }
    for (i = 0; i < 3; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714950(actor);
        func_global_asm_8071498C(func_global_asm_8071E1C8);
        func_global_asm_8071E110(drawSpriteAtPosition(D_global_asm_8074E880[i], 0.7f, actor->x_position, actor->y_position, actor->z_position), 0, (i * 1365.3334f), arg1, arg2, arg3);
    }
}

extern s32 D_global_asm_8074E880[];

void func_global_asm_80686CF8(Actor *actor) {
    s32 i;

    for (i = 0; i < 0x1E; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_8071498C(func_global_asm_8071EA24);
        func_global_asm_8071496C(i / 7);
        drawSpriteAtPosition(D_global_asm_8074E880[i % 3], 1.4f, actor->x_position, actor->y_position + 10.0f, actor->z_position);
    }
}

void func_global_asm_80686E40(f32 x, f32 y, f32 z, s32 arg3) {
    s32 i;
    s32 var_s4;
    s32 var_s5;

    if (D_global_asm_80750AD0 != 0) {
        var_s5 = 3;
    } else {
        var_s5 = 0x10;
    }
    if (D_global_asm_80750AD0 != 0) {
        var_s4 = 0;
    } else {
        var_s4 = 2;
    }
    for (i = 0; i < var_s5; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_8071498C(&func_global_asm_80717930);
        func_global_asm_8071496C(i >> var_s4);
        func_global_asm_80714950(arg3);
        drawSpriteAtPosition(D_global_asm_8074E880[i % 3], 0.5f, x, y, z);
    }
}

void func_global_asm_80686F90(u8 arg0, s16 arg1, s16 arg2) {
    spawnActor(ACTOR_BOSS_DOGADON_LIGHTBEAM, 0xC0);
    if (arg0) {
        getBonePosition(current_actor_pointer, arg0, &last_spawned_actor->x_position, &last_spawned_actor->y_position, &last_spawned_actor->z_position);
    } else {
        last_spawned_actor->x_position = current_actor_pointer->x_position;
        last_spawned_actor->y_position = current_actor_pointer->y_position;
        last_spawned_actor->z_position = current_actor_pointer->z_position;
    }
    last_spawned_actor->y_rotation = arg1;
    last_spawned_actor->z_rotation = arg2;
    last_spawned_actor->animation_state->scale_y *= 0.01;
}

void func_global_asm_80687080(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = ((rand() >> 0xF) % 75) + 180;
        current_actor_pointer->unk16C = 0x28;
        current_actor_pointer->shadow_opacity = 0xFF;
    }
    if (current_actor_pointer->animation_state->scale_y > 1.0) {
        current_actor_pointer->shadow_opacity -= 0x28;
        if (current_actor_pointer->shadow_opacity < 0) {
            deleteActor(current_actor_pointer);
        }
    } else {
        current_actor_pointer->animation_state->scale_y *= 1.8;
        current_actor_pointer->animation_state->scale_x *= 1.1;
        current_actor_pointer->animation_state->scale_z *= 1.1;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806871DC(u8 arg0) {
    s16 var_s4;
    u8 var_v0;
    u8 var_s2;

    var_s2 = ((object_timer & 3) * 4) + 3;
    for (var_s4 = 0; var_s4 < 4; var_s4++) {
        if (var_s2 == 0x10) {
            var_v0 = 0x14;
        } else if (var_s2 == 0x11) {
            var_v0 = 0x15;
        } else {
            var_v0 = var_s2;
        }
        switch (arg0) {
            case 3:
                if (var_v0 < 0xA) {
                    break;
                }
            case 1:
                func_global_asm_80714998(1);
                changeActorColor(0xB4, 0xB4, 0xB4, 0xC8);
                func_global_asm_8068588C(current_actor_pointer, var_v0, 2.0f, 0.0f, 0.0f, 0.0f, -0x78);
                break;
            case 2:
                if (var_v0 < 0xA) {
                    break;
                }
            case 0:
                func_global_asm_807149B8(1);
                func_global_asm_8071498C(func_global_asm_80717D4C);
                func_global_asm_80714950(-1000);
                changeActorColor(0xFF, 0xD7, 0x58, 0xFF);
                func_global_asm_80714C08(&D_global_asm_80720120, (((rand() >> 0xF) % 100) / 30.0) + 1.0, current_actor_pointer, var_v0, 0);
                break;
        }
        var_s2++;
    }
}

void func_global_asm_80687400(void) {
    playSound(0x2D4, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_global_asm_807149FC(0xC8);
    func_global_asm_8071495C();
    func_global_asm_8071498C(&func_global_asm_8071EFDC);
    drawSpriteAtPosition(&D_global_asm_80721158, 1.0f, 160.0f, 120.0f, -10.0f);
}

void func_global_asm_80687474(Actor *arg0, f32 arg1) {
    spawnActor(ACTOR_SHOCKWAVE_MAD_JACK, 0x5D);
    last_spawned_actor->object_properties_bitfield |= 0x400;
    playActorAnimation(last_spawned_actor, 0x334);
    moveAndScaleActorToAnother(last_spawned_actor, arg0, arg0->animation_state->scale_y * arg1);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_global_asm_806874EC.s")

void func_global_asm_806877C8(u8 arg0) {
    func_global_asm_807149B8(1);
    func_global_asm_80714C08(&D_global_asm_8072006C, 1.0f, current_actor_pointer, arg0, 0);
}

void func_global_asm_8068780C(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    f32 x1;
    f32 y1;
    f32 z1;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    u16 sp46; // Padding, not used
    u8 boneIndex1;
    u8 boneIndex2;

    boneIndex1 = (((rand() >> 0xF) % 32767) % ((arg1 - arg0) + 1)) + arg0;
    boneIndex2 = (((rand() >> 0xF) % 32767) % ((arg3 - arg2) + 1)) + arg2;
    getBonePosition(current_actor_pointer, boneIndex1, &x1, &y1, &z1);
    getBonePosition(current_actor_pointer, boneIndex2, &x2, &y2, &z2);
    func_global_asm_80626F8C(x1, y1, z1, &sp58, &sp54, 0, 1.0f, 0);
    func_global_asm_80626F8C(x2, y2, z2, &sp50, &sp4C, 0, 1.0f, 0);
    sp5C = ((func_global_asm_80665DE0(sp50, sp4C, sp58, sp54) * 0x168) / 4096) + 0x5A;
    if (sp5C < 270.0f) {
        sp5C += 180.0f;
    }
    sp48 = sqrtf(((sp58 - sp50) * (sp58 - sp50)) + ((sp54 - sp4C) * (sp54 - sp4C)));
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(1);
    func_global_asm_80714950(sp5C);
    func_global_asm_8071498C(&func_global_asm_8071E028);
    drawSpriteAtPosition(&D_global_asm_80720B24, sp48 * 0.008, (x1 + x2) * 0.5, (y1 + y2) * 0.5, (z1 + z2) * 0.5);
    if (((rand() >> 0xF) % 1000) & 1) {
        func_global_asm_806595F0(1);
        createLight(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0.0f, 0.0f, 0.0f, 150.0f, 0, 0x96, 0x64, 0xFF);
    }
    if ((current_actor_pointer->unk58 == ACTOR_BOSS_ARMY_DILLO) && (((rand() >> 0xF) % 1000) >= 0x385)) {
        s16 temp;
        func_global_asm_806877C8(((((rand() >> 0xF) % 32767) % 10) + 0xD));
        temp = ((rand() >> 0xF) % 1000) >= 0x1F5 ? 0x8A : 0xA1;
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, temp, 0xFF, 0x7F, 0x28, 0, 0.3f, 0);
    }
}

void func_global_asm_80687C48(void) {
    playSound(0xF2, 0x7FFF, 63.0f, 1.0f, 0, 0);
    playSong(0x97, 1.0f);
    func_global_asm_807149FC(0xC8);
    func_global_asm_8071495C();
    func_global_asm_8071498C(&func_global_asm_8071EFDC);
    drawSpriteAtPosition(&D_global_asm_80720558, 1.0f, 160.0f, 120.0f, -10.0f);
}

void func_global_asm_80687CC8(void) {
    playSound(0xF2, 0x7FFF, 63.0f, 1.0f, 0, 0);
    playSong(0x97, 1.0f);
    func_global_asm_807149FC(0xC8);
    func_global_asm_8071495C();
    func_global_asm_8071498C(&func_global_asm_8071EFDC);
    drawSpriteAtPosition(&D_global_asm_807210EC, 1.0f, 160.0f, 120.0f, -10.0f);
}
