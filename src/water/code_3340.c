#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u32 D_8002A1C0;
extern u32 D_8002A1C8;
extern u32 D_8002A1C4;
extern u16 D_8002A1CE;
extern u16 D_8002A1CC;

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80027340.s")

void func_80688370(Actor *, s32, s32);
void func_806883F4(Actor *, s32, s16);
void func_8068842C(Actor *, s32, s32);
void func_80688460(Actor *, s32, s32);

/*
// TODO: Kinda close... hmm
void func_80027340(s32 arg0) {
    s32 phi_s0;
    s32 phi_s2;

    phi_s0 = 2;
    phi_s2 = arg0;
    while (phi_s0 >= 0) {
        func_8068842C(current_actor_pointer, phi_s0, 1);
        func_80688370(current_actor_pointer, phi_s0, 0);
        func_806883F4(current_actor_pointer, phi_s0, (phi_s2 % 10) + 1);
        func_80688460(current_actor_pointer, phi_s0, 0);
        phi_s2 /= 10;
        phi_s0--;
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80027448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80027DC0.s")

extern f32 D_8002A110;
extern f32 D_8002A114;

void func_80604CBC(Actor*, s32, s32, s32, s32, s32, f32, s32);

/*
// TODO: Regalloc, everything else matches :(
void func_80027DC0(void) {
    s32 temp[2];
    Actor *sp34;
    f32 dx;
    f32 dz;
    f32 temp2;
    s32 phi_t5;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80604CBC(current_actor_pointer, 0x10F, 0x46, 1, 0, 0x1E, 1.0f, 0);
        current_actor_pointer->control_state = 0;
        // Is the camera not unlocked?
        if (!isFlagSet(0x179, FLAG_TYPE_PERMANENT)) {
            current_actor_pointer->control_state = 1;
        // Is the Rareware GB room open?
        } else if (isFlagSet(0x189, FLAG_TYPE_PERMANENT)) {
            func_80614EBC(current_actor_pointer, 0x2B5);
        // Has the player photographed all 20 fairies?
        } else if (func_80731AA8(0x24D, 20, FLAG_TYPE_PERMANENT) == 20) {
            func_80614EBC(current_actor_pointer, 0x2B5);
            current_actor_pointer->control_state = 3;
        }
    }
    dx = current_actor_pointer->x_position - player_pointer->x_position;
    dz = current_actor_pointer->z_position - player_pointer->z_position;
    switch (current_actor_pointer->control_state) {
        case 1:
            temp2 = (dx * dx) + (dz * dz);
            phi_t5 = temp2 < D_8002A110;
            if (phi_t5) {
                // Unlock the camera
                setFlag(0x179, TRUE, FLAG_TYPE_PERMANENT);
                playCutscene(player_pointer, 0, 1);
                func_80629174();
                current_actor_pointer->control_state = 2;
            }
            break;
        case 2:
            sp34 = current_actor_pointer;
            if (current_actor_pointer->control_state_progress != 0) {
                current_actor_pointer->control_state_progress++;
                if (current_actor_pointer->control_state_progress < 0x4B) {
                    current_actor_pointer = player_pointer;
                    if ((object_timer & 3) == 0) {
                        func_80684900(0);
                    }
                    current_actor_pointer = sp34;
                } else {
                    current_actor_pointer = player_pointer;
                    player_pointer->control_state = 0x2D;
                    player_pointer->control_state_progress = 0;
                    func_80614E78(player_pointer, 0x42);
                    func_80608528(player_pointer, 0xF2, 0xFF, 0x7F, 0);
                    current_actor_pointer = sp34;
                    current_actor_pointer->control_state_progress = 0;
                    func_80605314(player_pointer, 1);
                }
            } else if (func_80629148()) {
                current_actor_pointer->control_state_progress = 1;
                func_80604CBC(player_pointer, 0x104, 0x3C, 1, 1, 0xFF, 1.0f, 0);
                func_806F8BC4(6, 0, 0);
                func_806F91B4(6, extra_player_info_pointer->unk1A4, 999);
            }
            break;
        case 3:
            temp2 = (dx * dx) + (dz * dz);
            phi_t5 = temp2 < D_8002A114;
            if (phi_t5) {
                playCutscene(current_actor_pointer, 1, 1);
                func_80629174();
                current_actor_pointer->control_state = 4;
            }
            break;
        case 4:
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80028120.s")

void func_80028840() {
    D_8002A1C0 = getPointerTableFile(0x13, 4, 1, 1);
    D_8002A1C8 = getPointerTableFile(0x13, 5, 1, 1);
    D_8002A1C4 = 0;
    D_8002A1CE = 0;
    D_8002A1CC = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_800288A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80028A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80028DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80028EE8.s")

// Weird struct/array accesses. Probably doable.
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_8002904C.s")

s32 func_80029110(s32 arg0) {
    return ~arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_80029118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_3340/func_800296DC.s")
