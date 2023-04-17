#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_806883F4(Actor*, s32, u8, f32);
extern u8 D_807FBD70;
extern s32 D_80750600[];

// TODO: Are these 4 correct?
extern s32 D_8071FFA0;
extern f32 D_8075B2A0;
void func_806846B4(f32, f32, f32, f32, f32, Actor*, s32);
void func_80685B44(void*, s32, f32, s32, s32, s32, s32, s32, s32);

void func_806B11C0(u8 arg0) {
    f32 sp3C, sp38, sp34;

    func_80671C0C(current_actor_pointer, arg0, &sp3C, &sp38, &sp34);
    func_80685B44(&D_8071FFA0, 0, 1.0f, 3, 5, 0x28, sp3C, current_actor_pointer->floor, sp34);
    // spawnShockwave
    func_806846B4(sp3C, current_actor_pointer->floor, sp34, 0.05f, D_8075B2A0, current_actor_pointer, 0);
}

void func_806B1290(void) {
    // TODO: Hahahaha clean this up
    if (D_807FDC90->unk18 >= 0x65
        && ((D_807FDC90->unk1A & 0x80) && (rand() >> 0xF) % 1000 >= 981
            || !((rand() >> 0xF) % 1000 < 991)
            && current_actor_pointer->object_properties_bitfield & 0x100)) {
        current_actor_pointer->control_state = 0x28;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_806B1348(void) {
    if ((D_807FDC90->unk18 >= 0x65) && (D_807FBD70 == 2) && (func_8072DE10(0x2710) != 0)) {
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
    }
}

// Huge, jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B5EC0/func_806B13B4.s")

void func_806B1D78(u8 arg0) {
    func_8068842C(current_actor_pointer, 0, 1);
    func_80688460(current_actor_pointer, 0, 1);
    func_806883F4(current_actor_pointer, 0, arg0, 0);
}

void func_806B1DD4(u8 arg0) {
    u8 phi_v1;
    s32 levelIndex;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        phi_v1 = 0;
        levelIndex = func_805FF000(D_8076A0AB);
        if ((levelIndex != 9) && (levelIndex != 0xA)) {
            levelIndex = getLevelIndex(D_8076A0AB, TRUE);
            phi_v1 = !func_80731A04(0x1D5, levelIndex, levelIndex, D_80750600[arg0]);
        }
        func_806B1D78(phi_v1 != 0 ? arg0 : 5);
        current_actor_pointer->unk15F = phi_v1;
    }
    func_806B13B4(current_actor_pointer->unk15F);
}

void func_806B1EA8(void) {
    func_806B1DD4(4);
}

void func_806B1EC8(void) {
    func_806B1DD4(2);
}

void func_806B1EE8(void) {
    func_806B1DD4(3);
}

void func_806B1F08(void) {
    func_806B1DD4(0);
}

void func_806B1F28(void) {
    func_806B1DD4(1);
}
