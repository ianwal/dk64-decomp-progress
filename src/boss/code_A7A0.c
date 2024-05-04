#include <ultra64.h>
#include "functions.h"

void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_boss_8002FB7C(u8);

// RODATA
const s32 D_boss_80036840[] = {
    0x546C0041,
    0x0141025F,
    0x014F4B00,
    0x07500000,
};

const s32 D_boss_80036850[] = {
    0x4F4B0007,
    0x50000000,
};

void func_boss_8002E7A0(Actor *arg0) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (!arg0 || temp_a0 != arg0) {
            // Actor behaviour: Banana Peel (Lanky Phase)
            if (temp_a0->unk58 == ACTOR_BOSS_KROOL_PEEL) {
                temp_a0->object_properties_bitfield &= ~0x8000;
                temp_a0->control_state = 1;
                temp_a0->control_state_progress = 0;
            }
        }
    }
}

void func_boss_8002E82C(void) {
    Actor *temp_v0_2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_boss_8002E7A0(current_actor_pointer);
        current_actor_pointer->unk168 = 600;
        current_actor_pointer->noclip_byte = 2;
    }
    if (player_pointer->control_state != 0x67) {
        if (current_actor_pointer->unk168 != 0) {
            current_actor_pointer->unk168--;
        } else {
            current_actor_pointer->object_properties_bitfield &= ~0x8000;
            current_actor_pointer->control_state = 1;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    if ((D_global_asm_807FBB70.unk15 != 0) || (D_global_asm_807FBB70.unk200 == 9)) {
        temp_v0_2 = D_global_asm_807FBB70.unk1FC;
        if ((temp_v0_2->control_state == 0x2B) && (temp_v0_2->control_state_progress == 3)) {
            current_actor_pointer->control_state = 1;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer->unk11C->control_state = 0x64;
            current_actor_pointer->unk11C->control_state_progress = 0;
            temp_v0_2->control_state_progress = 0;
            temp_v0_2->control_state = 0x31;
        }
    }
    if (current_actor_pointer->control_state == 1) {
        current_actor_pointer->noclip_byte = 1;
        current_actor_pointer->shadow_opacity -= 0xA;
        if (current_actor_pointer->shadow_opacity < 0) {
            deleteActor(current_actor_pointer);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_boss_8002E9B8(s32 arg0, s16 arg1) {
    BossActor178 *sp1C = current_actor_pointer->boss178;
    playActorAnimation(current_actor_pointer, arg0);
    func_global_asm_80614D90(current_actor_pointer);
    func_global_asm_80613CA8(sp1C->unk0, arg1, 0.0f, 6.0f);
}

void func_boss_8002EA14() {
    // TODO: BossActor178?
    Actor178 *sp1C = current_actor_pointer->unk178;
    func_boss_8002E9B8(0x406, 0x674);
    func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC + (sp1C->unk14 * 0xA) + 0xF);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_A7A0/func_boss_8002EA7C.s")
