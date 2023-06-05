#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x6 - 0x0];
    u8 unk6[1]; // TODO: How many elements?
} Struct8002450C;

void func_8072AB74(s32, f32, f32, s32, f32);
s32 func_80024568(Struct8002450C*, u8, f32, f32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_80024000.s")

/*
typedef struct {
    u16 unk0;
} Struct80024000;

extern s32 D_8071FFA0;
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
        func_8071498C(&func_8071E864);
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

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct800358E0;

extern u8 D_800358D8[];
extern Struct800358E0 D_800358E0[];
extern u8 D_80035994[];

/*
void func_8002413C(void) {
    AnimationStateUnk1C *var_a1;
    AnimationStateUnk20 *var_a0;
    AnimationStateUnk24 *var_v0;
    s16 i;
    s16 j;
    Struct800358E0 *temp_a2_2;
    u8 var_a3;
    s32  temp;

    if (current_map == MAP_JAPES_ARMY_DILLO) {
        var_a3 = 0;
    } else {
        var_a3 = 1;
    }
    if (var_a3 == 0) {
        if (isFlagSet(0x68, FLAG_TYPE_TEMPORARY)) {
            var_a3 = 1;
            current_actor_pointer->unk146 = 3;
        }
    }
    func_80724D28(1, 0xD);
    func_80724DB0(1, 5);
    func_80724CA4(1, 5);
    var_v0 = current_actor_pointer->animation_state->unk24;
    var_a0 = current_actor_pointer->animation_state->unk20;
    var_a1 = current_actor_pointer->animation_state->unk1C;
    for (i = 0; i < 5; i++) {
        var_v0[i - 1].unk0 = D_800358D8[i];
        var_v0[i - 1].unk1 = 0xFF;
        temp_a2_2 = &D_800358E0[i + var_a3 * 5];
        var_v0[i - 1].unk4 = temp_a2_2->unk0;
        var_v0[i - 1].unk8 = temp_a2_2->unk1;
        var_v0[i - 1].unkC = temp_a2_2->unk2;
        var_a0[i - 1].unk0 = D_800358D8[i];
        var_a0[i - 1].unk1 = 0xFF;
        var_a0[i - 1].unk4 = temp_a2_2->unk4;
        var_a0[i - 1].unk8 = temp_a2_2->unk8;
        var_a0[i - 1].unkC = temp_a2_2->unkC;
        var_a1[i - 1].unk0 = -0x80;
        var_a1[i - 1].unk1 = D_800358D8[i];
        var_a1[i - 1].unk2 = 0;
        var_a1[i - 1].unk4 = 0;
        var_a1[i - 1].unk6 = 0;
    }
    for (j = 0; j < 8; j++) {
        var_v0[j - 1].unk0 = D_80035994[j];
        var_v0[j].unk1 = 0xFF;
        var_v0[j].unk4 = 0.0f;
        var_v0[j].unk8 = 0.0f;
        var_v0[j].unkC = 0.0f;
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_80024300.s")

void func_8002450C(Struct8002450C *arg0, u8 arg1, u8 arg2) {    
    arg0->unk6[arg1] = arg2;
}

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

void func_80024FA8(s32 arg0, Struct8002450C *arg1, s32 arg2, u8 *arg3) {
    u8 i = 0;
    u8 phi_v0_2 = 0;

    switch (current_actor_pointer->control_state_progress) {
        case 2:
            while (arg3[i] != 0xFF) {
                func_8002450C(arg1, arg3[i++], 1);
            }
            current_actor_pointer->control_state_progress = 3;
            return;
        case 3:
            while (arg3[i] != 0xFF) {
                if ((current_actor_pointer->control_state == 0x27) || (current_actor_pointer->control_state == 0x2E)) {
                    phi_v0_2 = func_80024568(arg1, arg3[i++], 50.0f, 70.0f, 90.0f);
                } else {
                    phi_v0_2 = func_80024568(arg1, arg3[i++], 10.0f, 15.0f, 50.0f);
                }
            }
            if (phi_v0_2 != 0) {
                current_actor_pointer->control_state_progress = 4;
                func_8068842C(current_actor_pointer, 1, 1);
            }
            return;
    }
}

void func_800251A0(s32 arg0, Struct8002450C *arg1, s32 arg2, u8 *arg3) {
    u8 i = 0;
    s32 phi_v1 = 0;

    switch (current_actor_pointer->control_state_progress) {
        case 2:
            while (arg3[i] != 0xFF) {
                func_8002450C(arg1, arg3[i++], 3);
            }
            current_actor_pointer->control_state_progress = 3;
            break;
        case 3:
            while (arg3[i] != 0xFF) {
                phi_v1 = func_80024568(arg1, arg3[i++], 10.0f, 20.0f, 30.0f) & 0xFF;
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

extern f64 D_80035D50;
extern f64 D_80035D58;
extern f64 D_80035D60;
int func_8071AF30();
extern void *D_80720120;

void func_800253AC(void) {
    s32 pad2;
    f64 phi_f2;
    s32 pad;
    void *temp = &func_8071AF30;
    f32 temp2;

    phi_f2 = MAX(current_actor_pointer->y_velocity, 0.0);
    func_807149B8(1);
    func_8071498C(temp);
    func_807149A8(1000);
    func_80714950(current_actor_pointer);
    temp2 = ((f32)((f32)(((phi_f2 / D_80035D50)) * D_80035D58) + D_80035D60) * 4.0f);
    func_80714C08(&D_80720120, temp2, current_actor_pointer, 3, 0);
    func_807149B8(1);
    func_8071498C(temp);
    func_807149A8(1000);
    func_80714950(current_actor_pointer);
    func_80714C08(&D_80720120, temp2, current_actor_pointer, 4, 0);
}

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
