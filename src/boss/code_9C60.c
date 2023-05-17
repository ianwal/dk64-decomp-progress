#include <ultra64.h>
#include "functions.h"

void func_80613CA8(Actor*, s16, f32, f32);
void func_8002FB7C(u8);
void func_806319C4(Actor*, s8);

extern u16 D_807FBB34;
extern f64 D_80036A18;

void func_8002DC60(void) {
    BossActor178 *sp1C = current_actor_pointer->unk178;
    func_80677FA8(0xDD, 0xE3); // Spawn actor 221 "light piece" (lanky phase)
    D_807FBB44->object_properties_bitfield |= 0x400;
    D_807FBB44->unk11C = current_actor_pointer;
    sp1C->unk0 = D_807FBB44;
    func_8067B238(D_807FBB44, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
}

void func_8002DCE0(void) {
    func_8067B238(current_actor_pointer, current_actor_pointer->unk11C, current_actor_pointer->animation_state->scale_y);
    current_actor_pointer->animation_state->unk48 = current_actor_pointer->unk11C->animation_state->unk48;
    if (current_actor_pointer->animation_state->unk0->unk10 == 0x675) {
        if (current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
            func_806782C0(current_actor_pointer);
        }
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_8002DD7C(void) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_807FBB34; i++) {
        temp_a0 = D_807FB930[i].unk0;
        // Actor behaviour: Damage Source (K. Rool's Glove)
        if (temp_a0->unk58 == 0xAA) {
            func_806782C0(temp_a0);
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_8002DE04.s")

void func_8002E7A0(Actor *arg0) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_807FBB34; i++) {
        temp_a0 = D_807FB930[i].unk0;
        if (!arg0 || temp_a0 != arg0) {
            // Actor behaviour: Banana Peel (Lanky Phase)
            if (temp_a0->unk58 == 0xDE) {
                temp_a0->object_properties_bitfield &= ~0x8000;
                temp_a0->control_state = 1;
                temp_a0->control_state_progress = 0;
            }
        }
    }
}

void func_8002E82C(void) {
    Actor *temp_v0_2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_8002E7A0(current_actor_pointer);
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
    if ((D_807FBB70.unk15 != 0) || (D_807FBB70.unk200 == 9)) {
        temp_v0_2 = D_807FBB70.unk1FC;
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
            func_806782C0(current_actor_pointer);
        }
    }
    func_806319C4(current_actor_pointer, 0);
}

void func_8002E9B8(s32 arg0, s16 arg1) {
    BossActor178 *sp1C = current_actor_pointer->boss178;
    func_80614EBC(current_actor_pointer, arg0);
    func_80614D90(current_actor_pointer);
    func_80613CA8(sp1C->unk0, arg1, 0.0f, 6.0f);
}

void func_8002EA14() {
    // TODO: BossActor178?
    Actor178 *sp1C = current_actor_pointer->unk178;
    func_8002E9B8(0x406, 0x674);
    func_8072B324(current_actor_pointer, D_807FDC9C->unkC + (sp1C->unk14 * 0xA) + 0xF);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_8002EA7C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_8002F100.s")

void func_8002FB7C(u8 arg0) {
    AnimationStateUnk20 *temp_v0;

    temp_v0 = current_actor_pointer->animation_state->unk20;
    temp_v0->unk0 = 2;
    temp_v0->unk1 = 4;
    temp_v0->unk4 = 1;
    temp_v0->unk4 += arg0 * (D_80036A18 + D_80036A18 * func_80612794(object_timer << 7));
    temp_v0->unk8 = temp_v0->unk4;
    temp_v0->unkC = 1;
}

void func_8002FC48(s32 arg0, u8 arg1) {
    func_8068842C(arg0, 0, 1);
    func_80688460(arg0, 0, 1);
    func_806883F4(arg0, 0, arg1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_8002FC98.s")

/*
extern f64 D_80036A20;

void func_8002FC98(Actor *arg0, u8 arg1, s32 arg2, u8 arg3) {
    Actor17C *temp_s4;
    f64 temp_f20;
    s16 i;

    temp_s4 = arg0->unk17C;
    temp_f20 = D_80036A20;
    for (i = 0; i < 4; i++) {
        if (arg1 & (1 << i)) {
            if (i != 0) {
                arg0 = temp_s4[i].unk0;
            }
            if ((arg2 != -1) && (arg2 != 0)) {
                if ((arg2 == 1) || (arg2 == 2)) {
                    arg0->unk132 = arg2;
                } else {
                    func_80614EBC(arg0, arg2);
                    if (arg3 != 0) {
                        func_80614D00(arg0, arg3 * temp_f20, 0);
                    }
                }
            } else {
                arg0->unk138 = arg2;
            }
        }
    }
}
*/

extern u8 D_807FBD70;

void func_8002FDF8(Actor* arg0, u8 arg1) {
    s32 phi_v0;
    Actor *temp;

    if (current_actor_pointer->unk15F == 2) {
        phi_v0 = 4;
    } else {
        phi_v0 = arg1;
    }
    func_8002FB7C(phi_v0);
    if (D_807FBD70 == 4) {
        func_8002FC98(arg0, 0xF, 0, 0);
        // Note: This temporary variable appears to be required for this function to match
        temp = current_actor_pointer;
        func_8002FC48(temp, 0xA - temp->health);
        func_80614EBC(current_actor_pointer, 0x415);
    }
    if ((D_807FBD70 == 5) || (D_807FBD70 == 4)) {
        func_8072DA60();
    }
}

void func_8002FEC0(Actor* arg0[], u8 arg1, s32 arg2) {
    func_80677FA8(0xE5, arg2); // Spawn actor 229 (K. Rool's toe)
    func_8067B238(D_807FBB44, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
    D_807FBB44->object_properties_bitfield |= 0x1400;
    D_807FBB44->unk11C = current_actor_pointer;
    D_807FBB44->noclip_byte = current_actor_pointer->noclip_byte;
    D_807FBB44->object_properties_bitfield = current_actor_pointer->object_properties_bitfield;
    arg0[arg1] = D_807FBB44;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9C60/func_8002FF74.s")

void func_80724DB0(s32, s32);

void func_80030888(void) {
    Actor* temp;
    Actor178* temp_2;
    s32 phi_v0_2;

    temp = current_actor_pointer->unk11C;
    temp_2  = temp->unk178;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80724DB0(2, 1);
    }
    if (current_actor_pointer->unk15F == 1) {
        phi_v0_2 = temp_2->unk14;
    } else {
        phi_v0_2 = 0U;
    }
    func_8002FDF8(temp, phi_v0_2);
    func_806319C4(current_actor_pointer, 0);
}