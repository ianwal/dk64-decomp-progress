#include <ultra64.h>
#include "functions.h"

void func_global_asm_80613CA8(Actor*, s16, f32, f32);

// .rodata
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

// .data
void *D_boss_80035A80[] = {
    D_boss_80036840,
    D_boss_80036850,
    D_boss_80036850,
    D_boss_80036850,
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

void func_boss_8002EA14(void) {
    // TODO: BossActor178?
    Actor178 *sp1C = current_actor_pointer->unk178;
    func_boss_8002E9B8(0x406, 0x674);
    func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC + (sp1C->unk14 * 0xA) + 0xF);
}

u8 func_boss_80027BA8(u8 *, u16, f32);
u8 func_global_asm_8061CB98(u8);
s32 func_global_asm_8072881C(s32, s32 *);
void func_global_asm_8072A450(void);

typedef struct KRoolLankyAAD178 {
    Actor *unk0;
    u8 pad4[0x14 - 0x4];
    u8 unk14;
    u8 unk15;
} KRoolLankyAAD178;

void func_boss_8002EA7C(void) {
    KRoolLankyAAD178 *temp_t0;
    u8 *sp28;

    temp_t0 = current_actor_pointer->unk178;
    sp28 = D_boss_80035A80[temp_t0->unk14];
    initializeCharacterSpawnerActor();
    func_boss_80028878(sp28);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk146_s16 = 1;
        current_actor_pointer->control_state = 0x1E;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkCC = 1;
        func_global_asm_80724CA4(2, 1);
        func_boss_8002DC60();
        current_actor_pointer->y_acceleration = 0.0f;
    }
    if ((player_pointer->control_state == 0x48) && !(D_global_asm_807FDC90->unk1A & 0x8000)) {
        playCutscene(current_actor_pointer, 0, 1);
        D_global_asm_807FDC90->unk1A |= 0x8000;
    }
    if ((func_global_asm_8061CB98(0) == 0) && ((func_global_asm_8061CB98(1) == 0)) && ((player_pointer->control_state != 0x67) || (current_actor_pointer->control_state != 0x42))) {
        switch (current_actor_pointer->control_state) {
        case 0x2B:
            switch (current_actor_pointer->control_state_progress) {
            case 0:
                func_global_asm_8072B324(current_actor_pointer, 0);
                playCutscene(player_pointer, 9, 1);
                func_boss_8002E9B8(0x3F5, 0x679);
                current_actor_pointer->control_state_progress += 1;
                break;
            case 2:
                func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkD);
                func_boss_8002E9B8(0x3F4, 0x678);
                current_actor_pointer->control_state_progress += 1;
                break;
            case 3:
                if (D_global_asm_807FBB70.unk1B != 0) {
                    current_actor_pointer->control_state = 0x31;
                    current_actor_pointer->control_state_progress = 0;
                } else if (D_global_asm_807FBB70.unk200 == 2) {
                    func_boss_8002E7A0(NULL);
                    current_actor_pointer->control_state = 0x2C;
                    current_actor_pointer->control_state_progress = 0;
                }
                func_global_asm_8072AB74(0x23U, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0U, 0.0f);
                break;
            }
            break;
        case 0x2C:
            if (current_actor_pointer->control_state_progress == 0) {
                setAction(0x36, current_actor_pointer, 0U);
                func_boss_8002EA14();
                current_actor_pointer->control_state = 0x42;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 0x1E:
            temp_t0->unk14 = 0U;
            temp_t0->unk15 = 0U;
            current_actor_pointer->control_state = sp28[temp_t0->unk15++];
            current_actor_pointer->control_state_progress = 0;
            break;
        case 0x0:
            switch (current_actor_pointer->control_state_progress) {
            case 0:
                func_boss_8002E9B8(0x3F5, 0x679);
                current_actor_pointer->control_state_progress++;
                break;
            case 2:
                func_boss_8002EA14();
                current_actor_pointer->control_state = sp28[temp_t0->unk15++];
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_8066EB40(player_pointer, player_pointer->ledge_info_pointer->unkC * 2);
                func_global_asm_8066E5F8(player_pointer, 6, 1U);
                func_global_asm_8066E5F8(player_pointer, 7, 1U);
                func_global_asm_8066E5F8(player_pointer, 8, 1U);
                func_global_asm_8066E5F8(player_pointer, 9, 1U);
                func_global_asm_8066E5F8(player_pointer, 0xA, 1U);
                func_global_asm_8066E5F8(player_pointer, 0xB, 1U);
                break;
            }
            break;
        case 0x31:
            switch (current_actor_pointer->control_state_progress) {
            case 0:
                if (temp_t0->unk14 == 3) {
                    current_actor_pointer->control_state = 0x37;
                    current_actor_pointer->control_state_progress = 0;
                } else {
                    playActorAnimation(current_actor_pointer, 0x3F2);
                    playActorAnimation(temp_t0->unk0, 0x3F1);
                    func_global_asm_8072B324(current_actor_pointer, 0);
                    current_actor_pointer->control_state_progress += 1;
                }
                break;
            case 1:
                func_global_asm_8072AB74(0U, 0.0f, 0.0f, 0x310U, 0.0f);
                break;
            case 2:
                func_boss_8002E7A0(NULL);
                func_boss_8002EA14();
                temp_t0->unk15 = 0U;
                temp_t0->unk14++;
                sp28 = D_boss_80035A80[temp_t0->unk14];
                current_actor_pointer->control_state = sp28[temp_t0->unk15++];
                current_actor_pointer->control_state_progress = 0;
                break;
            }
            break;
        case 0x37:
            switch (current_actor_pointer->control_state_progress) {
            case 0:
                deleteActor(temp_t0->unk0);
                playActorAnimation(current_actor_pointer, 0);
                playCutscene(current_actor_pointer, 5, 1);
                current_actor_pointer->control_state_progress += 1;
                break;
            case 1:
                if (func_global_asm_80629148() != 0) {
                    func_global_asm_805FF158(0U);
                    func_global_asm_805FF378(MAP_KROOL_FIGHT_TINY_PHASE, 0);
                    current_actor_pointer->control_state_progress += 1;
                }
                break;
            }
            break;
        default:
            func_boss_80027BA8(sp28, 0x10, 0.0f);
            break;
        }
    } else if (current_actor_pointer->animation_state->unk64 == 0x406) {
        func_global_asm_80614D00(current_actor_pointer, 0.0f, 0.0f);
    }
    func_global_asm_8072A450();
    if (func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28) != 0) {
        func_global_asm_8072881C(0x81, &D_global_asm_807FDC90->unk28);
    }
    renderActor(current_actor_pointer, 0U);
}
