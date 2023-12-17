#include <ultra64.h>
#include "functions.h"

void func_global_asm_80613CA8(Actor*, s16, f32, f32);
void func_boss_8002FB7C(u8);

/*
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

// possible file split
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

// possible file split
const s32 D_boss_800368C0[] = {
    0x00546C51,
    0x03E44101,
    0x273C4102,
    0x27002801,
    0x005103E4,
    0x4F4B0104,
    0x271E4B01,
    0x04271E28,
    0x0C500000,
};

const s32 D_boss_800368E4[] = {
    0x6C4F4B01,
    0x0427144B,
    0x01042714,
    0x4B010427,
    0x00280A50,
};

const s32 D_boss_800368F8[] = {
    0x6C4F4101,
    0x270F4103,
    0x270F4102,
    0x270F4104,
    0x2700280A,
    0x50000000,
};

const s32 D_boss_80036910[] = {
    0x6C4F4B01,
    0x04270A27,
    0x0A670104,
    0x270A270A,
    0x67010427,
    0x00280A50,
    0x4F270150,
    0x0A27FF50,
    0x0A27FF50,
    0x0A27FF50,
    0x0A285050,
    0x4F27FF5A,
    0x0A27FF5A,
    0x0A27055A,
    0x0A270A5A,
    0x0A284650,
};

const s32 D_boss_80036950[] = {
    0x4F270578,
    0x0A270A78,
    0x0A27FF78,
    0x0A270978,
    0x0A270678,
    0x0A283C50,
};

const s32 D_boss_80036968[] = {
    0x4F270C78,
    0x0A270378,
    0x0A270A78,
    0x0A27FF78,
    0x0A270578,
    0x0A283250,
};
*/

extern u8 D_global_asm_807FBD70;

void func_boss_8002DC60(void) {
    BossActor178 *sp1C = current_actor_pointer->unk178;
    spawnActor(ACTOR_BOSS_KROOL_LIGHT, 0xE3); // Spawn actor 221 "light piece" (lanky phase)
    last_spawned_actor->object_properties_bitfield |= 0x400;
    last_spawned_actor->unk11C = current_actor_pointer;
    sp1C->unk0 = last_spawned_actor;
    func_global_asm_8067B238(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
}

void func_boss_8002DCE0(void) {
    func_global_asm_8067B238(current_actor_pointer, current_actor_pointer->unk11C, current_actor_pointer->animation_state->scale_y);
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
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_boss_8002DE04.s")

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
    func_global_asm_80614EBC(current_actor_pointer, arg0);
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
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_boss_8002EA7C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_boss_8002F100.s")

// rodata
extern f64 D_boss_80036A18; // = 0.4

void func_boss_8002FB7C(u8 arg0) {
    AnimationStateUnk20 *temp_v0;

    temp_v0 = current_actor_pointer->animation_state->unk20;
    temp_v0->unk0 = 2;
    temp_v0->unk1 = 4;
    temp_v0->unk4 = 1;
    // temp_v0->unk4 += arg0 * (0.4 + 0.4 * func_global_asm_80612794(object_timer << 7));
    temp_v0->unk4 += arg0 * (D_boss_80036A18 + D_boss_80036A18 * func_global_asm_80612794(object_timer << 7));
    temp_v0->unk8 = temp_v0->unk4;
    temp_v0->unkC = 1;
}

void func_boss_8002FC48(Actor *arg0, u8 arg1) {
    func_global_asm_8068842C(arg0, 0, 1);
    func_global_asm_80688460(arg0, 0, 1);
    func_global_asm_806883F4(arg0, 0, arg1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_boss_8002FC98.s")

/*
void func_boss_8002FC98(Actor *arg0, u8 arg1, s32 arg2, u8 arg3) {
    Actor17C *temp_s4;
    f64 temp_f20;
    s16 i;

    temp_s4 = arg0->unk17C;
    temp_f20 = 0.01;
    for (i = 0; i < 4; i++) {
        if (arg1 & (1 << i)) {
            if (i != 0) {
                arg0 = temp_s4[i].unk0;
            }
            if ((arg2 != -1) && (arg2 != 0)) {
                if ((arg2 == 1) || (arg2 == 2)) {
                    arg0->unk132 = arg2;
                } else {
                    func_global_asm_80614EBC(arg0, arg2);
                    if (arg3 != 0) {
                        func_global_asm_80614D00(arg0, arg3 * temp_f20, 0);
                    }
                }
            } else {
                arg0->unk138 = arg2;
            }
        }
    }
}
*/

void func_boss_8002FDF8(Actor* arg0, u8 arg1) {
    s32 phi_v0;
    Actor *temp;

    if (current_actor_pointer->unk15F == 2) {
        phi_v0 = 4;
    } else {
        phi_v0 = arg1;
    }
    func_boss_8002FB7C(phi_v0);
    if (D_global_asm_807FBD70 == 4) {
        func_boss_8002FC98(arg0, 0xF, 0, 0);
        // Note: This temporary variable appears to be required for this function to match
        temp = current_actor_pointer;
        func_boss_8002FC48(temp, 0xA - temp->health);
        func_global_asm_80614EBC(current_actor_pointer, 0x415);
    }
    if ((D_global_asm_807FBD70 == 5) || (D_global_asm_807FBD70 == 4)) {
        func_global_asm_8072DA60();
    }
}

void func_boss_8002FEC0(Actor* arg0[], u8 arg1, s32 arg2) {
    spawnActor(ACTOR_BOSS_KROOL_TOE, arg2); // Spawn actor 229 (K. Rool's toe)
    func_global_asm_8067B238(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
    last_spawned_actor->object_properties_bitfield |= 0x1400;
    last_spawned_actor->unk11C = current_actor_pointer;
    last_spawned_actor->noclip_byte = current_actor_pointer->noclip_byte;
    last_spawned_actor->object_properties_bitfield = current_actor_pointer->object_properties_bitfield;
    arg0[arg1] = last_spawned_actor;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_boss_8002FF74.s")

void func_boss_80030888(void) {
    Actor* temp;
    Actor178* temp_2;
    s32 phi_v0_2;

    temp = current_actor_pointer->unk11C;
    temp_2  = temp->unk178;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724DB0(2, 1);
    }
    if (current_actor_pointer->unk15F == 1) {
        phi_v0_2 = temp_2->unk14;
    } else {
        phi_v0_2 = 0U;
    }
    func_boss_8002FDF8(temp, phi_v0_2);
    renderActor(current_actor_pointer, 0);
}
