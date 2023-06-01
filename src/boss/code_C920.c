#include <ultra64.h>
#include "functions.h"

void func_8061C464(s32, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);

extern f32 D_80036AB0;
extern f32 D_80036AB4;
extern f64 D_80036AB8;

typedef struct BossStruct3 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14; // Used
} BossStruct3;

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_C920/func_80030920.s")

/*
// TODO: Regalloc :(
void func_80030920(s32 arg0) {
    extra_player_info_pointer->unk1FE = 1;
    func_800290D4(1);
    current_actor_pointer->noclip_byte = 0x24;
    func_806EB0C0(0x19, current_actor_pointer, 0);
    func_80724B5C(1, 8, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    D_807FDC90->unkA = current_actor_pointer->x_position;
    D_807FDC90->unkC = current_actor_pointer->y_position;
    D_807FDC90->unkE = current_actor_pointer->z_position;
    func_80724B5C(1, 0x20, &player_pointer->x_position, &player_pointer->y_position, &player_pointer->z_position);
    player_pointer->y_rotation = func_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position);
    current_actor_pointer->unkEE = \
    current_actor_pointer->y_rotation = player_pointer->y_rotation + 0x800;
    func_80614EBC(current_actor_pointer, 0x3F9);
    if (func_8061CB50()) {
        func_8061D4E4(D_807F5D10);
    }
    func_8061C464(D_807F5D10, player_pointer, 4, 0x800, 0x5A, 0, 0x46, 0x64, 0x3A, 0, D_80036AB0);
}
*/

void func_80030AE0(BossStruct3 *arg0) {
    func_800290D4(0);
    extra_player_info_pointer->unk1F4 = 0;
    if (player_pointer->control_state != 0x36) {
        func_806CFF9C(player_pointer);
    }
    func_806224CC(D_807F5D10, player_pointer);
    extra_player_info_pointer->unk1D8 = D_80036AB4;
    func_8063DA40(0xB, arg0->unk14 <= 0 ? 0 : 4);
    func_8063DA40(0xC, arg0->unk14 < 2 ? 0 : 4);
    func_8063DA40(0xD, arg0->unk14 < 3 ? 0 : 4);
    func_8063DA40(0xE, arg0->unk14 < 4 ? 0 : 4);
    func_8063DA40(0xA, 0xA);
}

void func_80030C30(f32 arg0) {
    f64 temp_f0;

    temp_f0 = D_80036AB8;
    current_actor_pointer->x_position = ((player_pointer->x_position - D_807FDC90->unkA) * current_actor_pointer->unk160) + D_807FDC90->unkA;
    current_actor_pointer->y_position = ((player_pointer->y_position - D_807FDC90->unkC) * current_actor_pointer->unk160) + D_807FDC90->unkC;
    current_actor_pointer->z_position = ((player_pointer->z_position - D_807FDC90->unkE) * current_actor_pointer->unk160) + D_807FDC90->unkE;
    current_actor_pointer->unk160 += arg0;
    if (temp_f0 < current_actor_pointer->unk160) {
        current_actor_pointer->unk160 = temp_f0;
    }
}

void func_80030D50(void) {
    s32 temp; // TODO: Can this be removed somehow? Messes up a stack offset
    f32 sp20;

    sp20 = func_80612794(current_actor_pointer->unk160 * 10240.0);
    current_actor_pointer->x_position += 80.0f * func_80612794(current_actor_pointer->y_rotation + 0x400) * sp20;
    sp20 = func_80612794(current_actor_pointer->unk160 * 10240.0);
    current_actor_pointer->z_position += 80.0f * func_80612790(current_actor_pointer->y_rotation + 0x400) * sp20;
}

void func_80030E58() {
    D_807FDC90->unk1A |= 1;
    func_806086CC(current_actor_pointer->x_position, 
                  current_actor_pointer->y_position, 
                  current_actor_pointer->z_position, 
                  0x2E2, 0xFF, 0x65, 0, 0, 0.0f, 0);
}

// Jumptable, 3036 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_C920/func_80030EC4.s")

// Jumptable, 4200 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_C920/func_80031AA0.s")

// Quite an interesting Actor + float function, quite big but doable, but might need some struct and array definitions
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_C920/func_80032B08.s")
