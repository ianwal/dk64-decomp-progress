#include <ultra64.h>
#include "functions.h"

void func_global_asm_80613CA8(Actor*, s16, f32, f32);

//rodata
const s32 D_boss_80036750[] = {
    0x00546C51,
    0x03E44100,
    0x0027280A,
    0x46281E46,
    0x5F004F28,
    0x32785000,
};

const s32 D_boss_80036768[] = {
    0x4101292C,
    0x4F281464,
    0x50000000,
};

const s32 D_boss_80036774[] = {
    0x4102292C,
    0x4F280A5A,
    0x50000000,
};

const s32 D_boss_80036780[] = {
    0x4103292C,
    0x4F280A5A,
    0x50000000,
    0x00000000,
};

extern u8 D_global_asm_807FBD70;

void func_boss_8002DC60(void) {
    BossActor178 *sp1C = current_actor_pointer->unk178;
    spawnActor(ACTOR_BOSS_KROOL_LIGHT, 0xE3);
    last_spawned_actor->object_properties_bitfield |= 0x400;
    last_spawned_actor->unk11C = current_actor_pointer;
    sp1C->unk0 = last_spawned_actor;
    moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
}

void func_boss_8002DCE0(void) {
    moveAndScaleActorToAnother(current_actor_pointer, current_actor_pointer->unk11C, current_actor_pointer->animation_state->scale_y);
    current_actor_pointer->animation_state->unk48 = current_actor_pointer->unk11C->animation_state->unk48;
    if (current_actor_pointer->animation_state->unk0->unk10 == 0x675) {
        if (current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
            deleteActor(current_actor_pointer);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_boss_8002DD7C(void) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (temp_a0->unk58 == ACTOR_BOSS_KROOL_GLOVE) {
            deleteActor(temp_a0);
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/KRoolDiddy/func_boss_8002DE04.s")
