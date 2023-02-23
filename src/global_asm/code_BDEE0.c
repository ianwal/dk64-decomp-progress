#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_8071720C;
extern s32 D_80717D4C;
extern s32 D_8074E880[];
extern u8 D_80750628[];
extern f32 D_8075B9E0;

void func_80612BC0(Mtx*, f32);
void func_80612C30(Mtx*, f32);
void func_80611A70(f32, f32, f32*, f32*);
f32 func_80611BB4(f32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806B91E0.s")

void func_806B9CB0() {
    func_80729B00();
    func_806319C4(current_actor_pointer, 0);
}

void func_806B9CE0(u8 arg0, s8 arg1) {
    switch (arg0) {
        case 0:
            func_8071498C(&D_8071720C);
            break;
        case 1:
            func_80714950(-0x258);
            func_8071498C(&D_80717D4C);
            break;
    }
    func_807149B8(1);
    func_80714CC0(
        D_8074E880[((rand() >> 0xF) % 1000) % 3],
        (((rand() >> 0xF) % 256) * 0.001953125) + 0.5,
        ((rand() >> 0xF) % 6) + (current_actor_pointer->x_position - 3.0f),
        current_actor_pointer->y_position + arg1,
        ((rand() >> 0xF) % 6) + (current_actor_pointer->z_position - 3.0f)
    );
}

s32 func_806B9EB4(u8 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Mtx sp80;
    Mtx sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 temp;
    f32 sp2C;

    if (D_80750628[arg0]) {
        func_80671C0C(D_807FDCA0->unk1C, D_80750628[arg0], &sp3C, &sp38, &sp34);
        func_80611A70(arg2, arg4, &sp3C, &sp34);
        sp2C = func_80611BB4(sp3C - arg2, sp34 - arg4);
        guTranslateF(&sp80, 0.0f, -arg1, 0.0f);
        func_80612C30(&sp40, (current_actor_pointer->y_rotation * 360) / 4096);
        guMtxCatF(&sp80, &sp40, &sp80);
        func_80612BC0(&sp40, -90.0f);
        guMtxCatF(&sp80, &sp40, &sp80);
        guAlignF(&sp40, (sp2C * D_8075B9E0) + 180.0f, sp3C - arg2, sp38 - arg3, sp34 - arg4);
        guMtxCatF(&sp80, &sp40, &sp80);
        guTranslateF(&sp40, 0.0f, arg1, 0.0f);
        guMtxCatF(&sp80, &sp40, &sp80);
        guScaleF(&sp40,
                 current_actor_pointer->animation_state->scale_x,
                 current_actor_pointer->animation_state->scale_y,
                 current_actor_pointer->animation_state->scale_z);
        guMtxCatF(&sp80, &sp40, &sp80);
        guTranslateF(&sp40,
                     current_actor_pointer->x_position,
                     current_actor_pointer->y_position,
                     current_actor_pointer->z_position);
        guMtxCatF(&sp80, &sp40, &current_actor_pointer->unkC);
        return TRUE;
    }
    return FALSE;
}

void func_806BA130(void) {
    current_actor_pointer->interactable = 2;
    current_actor_pointer->control_state = 0x23;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->health = 1;
    current_actor_pointer->unk132 = 1;
    D_807FDC90[0].unk4 = player_pointer;
    func_80614EBC(current_actor_pointer, D_807FDC98->unk2A);
    current_actor_pointer->y_rotation = (((rand() >> 0xF) % 1024) + player_pointer->y_rotation) - 0x200;
    current_actor_pointer->unkB8 = ((rand() >> 0xF) % 100) + 50;
    current_actor_pointer->y_velocity = ((rand() >> 0xF) % 150) + 100;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806BA240.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806BA76C.s")

void func_806BA8C8(void) {
    switch (current_actor_pointer->control_state) {
        case 0x2:
        case 0x3:
            func_8072D13C(current_actor_pointer->control_state, 0);
        default:
            func_8072C918(10000, 0, 0);
            break;
        case 0x15:
        case 0x37:
        case 0x40:
            break;
    }
}

// Huge, float matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806BA93C.s")

void func_806BB32C(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk16A = 0xFA;
        current_actor_pointer->unk16B = 0xFA;
        current_actor_pointer->unk16C = 0xFA;
    }
    if (current_actor_pointer->control_state == 0x17) {
        func_806B9CE0(0, 0);
    }
    if (D_807FDC90[0].unk2E != 0) {
        D_807FDC90[0].unk2E--;
        current_actor_pointer->unkFC = 0;
        if ((D_807FDC90[0].unk2E == 0) && (D_807FDC94 == player_pointer)) {
            current_actor_pointer->noclip_byte = 0x24;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806BB400.s")

extern f32 D_8075BAEC;
extern f32 D_8075BAF0;
void func_807248B0(Actor*, f32);
s16 func_80665DE0(f32, f32, f32, f32);
void func_8072AB74(s32, f32, f32, s32, f32);
void func_806D0430(f32);

/*
// TODO: Very close, 1 extra instruction related to default case in the second switch
void func_806BB400(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806D0430(D_8075BAEC);
        player_pointer->object_properties_bitfield |= 0x400;
        player_pointer->draw_distance = 0x7D0;
        current_actor_pointer->object_properties_bitfield &= -5;
        func_807248B0(current_actor_pointer, 1.0f);
        current_actor_pointer->unk15F = 0;
        current_actor_pointer->y_rotation = func_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
        func_80614EBC(current_actor_pointer, 0x21B);
        D_807FDC98->unk46 |= 8;
        D_807FDC98->unk28 = 0x21C;
    }
    switch (current_actor_pointer->control_state) {
        case 0x4:
            current_actor_pointer->control_state = 0x23;
            current_actor_pointer->control_state_progress = 0;
            // fallthrough
        case 0x23:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_8072AB74(0x37, 0.0f, 0.0f, 0x202, 0.0f);
                    break;
                default:
                    current_actor_pointer->control_state_progress = 1;
                    // break;
                case 1:
                    if (current_actor_pointer->animation_state->unk64 != 0x21C) {
                        func_80614EBC(current_actor_pointer, 0x21C);
                    }
                    func_8072AB74(current_actor_pointer->control_state, D_807FDC94->x_position, D_807FDC94->z_position, 0, 0.0f);
                    break;
                case 2:
                    break;
            }
            break;
        case 0x37:
            func_806D0430(D_8075BAF0);
            current_actor_pointer->control_state = 0x40;
            break;
    }
    D_807FDCA0->unk20 = 0;
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806BB604.s")

//need these forward declarations to match, not sure if type is right
void func_80604CBC(Actor*,s32,s32,s32,s32,s32,f32,s32);

void func_806BB81C() {
    func_80604CBC(current_actor_pointer, 0x11F, 0, 0, 0, 0xFF, 1.0f, 0);
    playSong(0x3B, 1.0f);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_806BB874.s")

void func_806BC080() {
    func_806BB32C();
    if ((D_807FDC9C[0].unkA == 0) || (func_806BA240(0, 0x446) == 0)) {
        func_806AD260(0x2ED, 1, 0);
        func_806319C4(current_actor_pointer, 0);
    }
}

void func_806BC0E4() {
    func_806BB32C();
    if ((D_807FDC9C[0].unkA == 0) || (func_806BA240(0x32, 0x44E) == 0)) {
        func_806AD260(0x2EC, 1, 0);
        func_806319C4(current_actor_pointer, 0);
    }
}

void func_806BC148() {
    func_806BB32C();
    if ((D_807FDC9C[0].unkA == 0) || (func_806BA240(0x14, 0x44A) == 0)) {
        func_806AD260(0x2EE, 1, 0);
        func_806319C4(current_actor_pointer, 0);
    }
}

void func_806BC1AC() {
    func_806BB32C();
    func_806BA93C(0x24, 0x14, 0x1E);
}
