#include <ultra64.h>
#include "functions.h"

void func_8072AB74(s32, f32, f32, s32, f32);
s32 func_80024568(s32, s32, f32, f32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_80024000.s")

/*
typedef struct {
    u16 unk0;
} Struct80024000;

extern s32 D_8071FFA0;
extern s32 D_8071E864;
extern Struct80024000 D_8003598C[];

// TODO: Close, just gotta figure out sp48 and D_8003598C
void func_80024000(void) {
    Struct80024000 sp48[6];
    s16 i;

    for (i = 0; i < 6; i++) {
        sp48[i] = D_8003598C[i];
        func_8067E2E4(current_actor_pointer, sp48[i].unk0, 3.0f);
    }
    for (i = 0; i < 0xC; i++) {
        func_8071498C(&D_8071E864);
        func_80714950(i);
        func_807149B8(1);
        func_807149C8(0x8C, 0x8C, 0x8C, 0xFF);
        func_80714998(3);
        func_80714CC0(&D_8071FFA0, 2.5f, current_actor_pointer->x_position, current_actor_pointer->y_position + 40.0f, current_actor_pointer->z_position);
    }
}
*/

// Flag check, animation state, unrolled loops
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_8002413C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_80024300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_8002450C.s")

/*
// TODO: t8 t9 regalloc...
void func_8002450C(u8 *arg0, u8 arg1, s8 arg2) {
    arg0[arg1 + 6] = arg2;
}
*/

void func_80024524(u8 arg0, s16 arg1) {
    AnimationStateUnk1C *temp_v0;

    temp_v0 = &current_actor_pointer->animation_state->unk1C[arg0];
    if (arg0 == 3) {
        temp_v0->unk1 = 0x2F;
    }
    temp_v0->unk2 = arg1;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_80024568.s")

void func_80024EAC(void) {
    s32 temp_v0_2;
    u16 sp2A;

    sp2A = current_actor_pointer->animation_state->unk64;
    func_806CC10C(D_807FDC90->unk8, current_actor_pointer->y_rotation);
    func_8072AB74(0x45, D_807FDC94->x_position, D_807FDC94->z_position, 0x16, 0.0f);
    temp_v0_2 = func_806CC10C(D_807FDC90->unk8, current_actor_pointer->y_rotation);
    if (temp_v0_2 > 0) {
        if (sp2A != 0x260) {
            func_80614EBC(current_actor_pointer, 0x260);
        }
    } else if (temp_v0_2 < 0) {
        if (sp2A != 0x25F) {
            func_80614EBC(current_actor_pointer, 0x25F);
        }
    } else if (sp2A != 0x25A) {
        func_80614EBC(current_actor_pointer, 0x25A);
        func_80614D00(current_actor_pointer, 1.0f, 0.0f);
    }
}

void func_80024FA8(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u8 i = 0;
    u8 phi_v0_2 = 0;

    switch (current_actor_pointer->control_state_progress) {
        case 2:
            while (arg3[i] != 0xFF) {
                func_8002450C(arg1, arg3[i++] & 0xFF, 1);
            }
            current_actor_pointer->control_state_progress = 3;
            return;
        case 3:
            while (arg3[i] != 0xFF) {
                if ((current_actor_pointer->control_state == 0x27) || (current_actor_pointer->control_state == 0x2E)) {
                    phi_v0_2 = func_80024568(arg1, arg3[i++] & 0xFF, 50.0f, 70.0f, 90.0f);
                } else {
                    phi_v0_2 = func_80024568(arg1, arg3[i++] & 0xFF, 10.0f, 15.0f, 50.0f);
                }
            }
            if (phi_v0_2 != 0) {
                current_actor_pointer->control_state_progress = 4;
                func_8068842C(current_actor_pointer, 1, 1);
            }
            return;
    }
}

void func_800251A0(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u8 i = 0;
    s32 phi_v1 = 0;

    switch (current_actor_pointer->control_state_progress) {
        case 2:
            while (arg3[i] != 0xFF) {
                func_8002450C(arg1, arg3[i++] & 0xFF, 3);
            }
            current_actor_pointer->control_state_progress = 3;
            break;
        case 3:
            while (arg3[i] != 0xFF) {
                phi_v1 = func_80024568(arg1, arg3[i++] & 0xFF, 10.0f, 20.0f, 30.0f) & 0xFF;
            }
            if (phi_v1 != 0) {
                current_actor_pointer->control_state_progress = 4;
                func_8068842C(current_actor_pointer, 1, 1);
            }
            break;
    }
}

void func_8002531C(void) {
    func_8066EA90(current_actor_pointer, 3);
    func_8066EA90(current_actor_pointer, 4);
    func_8066EA90(current_actor_pointer, 5);
}

void func_80025364(void) {
    func_8066EA64(current_actor_pointer, 3);
    func_8066EA64(current_actor_pointer, 4);
    func_8066EA64(current_actor_pointer, 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_800253AC.s")

extern f64 D_80035D50;
extern f64 D_80035D58;
extern f64 D_80035D60;
extern void *D_8071AF30;
extern void *D_80720120;

/*
// Doable, just need the energy
void func_800253AC(void) {
    void *temp;
    f64 phi_f2;

    phi_f2 = MAX(current_actor_pointer->y_velocity, 0.0);
    func_807149B8(1);
    func_8071498C(&D_8071AF30);
    func_807149A8(1000);
    func_80714950(current_actor_pointer);
    phi_f2 /= D_80035D50;
    phi_f2 *= D_80035D58;
    phi_f2 += D_80035D60;
    phi_f2 *= 4.0f;
    func_80714C08(&D_80720120, phi_f2, current_actor_pointer, 3, 0);
    func_807149B8(1);
    func_8071498C(&D_8071AF30);
    func_807149A8(1000);
    func_80714950(current_actor_pointer);
    func_80714C08(&D_80720120, phi_f2, current_actor_pointer, 4, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_800254D0.s")

void func_80027770(void) {
    u8 var_v1;

    if (!(object_timer & 3)) {
        if (!(object_timer & 0xF)) {
            var_v1 = 0xC;
        } else {
            var_v1 = ((((rand() >> 0xF) % 32767) % 7) + 0x1D);
        }
        func_80714998(3);
        func_807149C8(0x50, 0x50, 0x50, 0xC8);
        func_8068588C(current_actor_pointer, var_v1, 2.0f, 0.0f, 0.0f, 0.0f, -0x78);
    }
}
