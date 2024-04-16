#include <ultra64.h>
#include "functions.h"

// rodata
const s32 D_boss_80035C00[] = {
    0x54410057,
    0x27434F46,
    0x031448DC,
    0x444B0003,
    0x11500000,
};

const s32 D_boss_80035C14[] = {
    0x44238C4C,
    0x0003114F,
    0x46041448,
    0xB4444B00,
    0x03115000,
};

const s32 D_boss_80035C28[] = {
    0x4423AA4C,
    0x0003114F,
    0x46051448,
    0x8C444B00,
    0x03115000,
};

const s32 D_boss_80035C3C[] = {
    0x5F05285F,
    0x071E0000,
};

const s32 D_boss_80035C44[] = {
    0x1F544100,
    0x57483C54,
    0x434F4603,
    0x1448DC44,
    0x4B000311,
    0x50000000,
};

const s32 D_boss_80035C5C[] = {
    0x44238C4C,
    0x00032A5F,
    0x022B2913,
    0x2C2D4F4B,
    0x00031146,
    0x041448B4,
    0x44500000,
};

const s32 D_boss_80035C78[] = {
    0x4423AA4C,
    0x00032A2B,
    0x291B132C,
    0x2D4F4B00,
    0x03114605,
    0x14488C44,
    0x50000000,
};

const s32 D_boss_80035C94[] = {
    0x5F052844,
    0x23AA4C00,
    0x032A291A,
    0x13134B00,
    0x032A575F,
    0x072E542F,
    0x4F300647,
    0x48B42F26,
    0x2F500000,
};

const s32 D_boss_80035CB8[] = {
    0x05080B09,
    0x0A0C0000,
};

const s32 D_boss_80035CC0[] = {
    0x04000102,
    0x03000000,
};

extern void *D_global_asm_80720120;

typedef struct {
    u8 unk0[0x6 - 0x0];
    u8 unk6[1]; // TODO: How many elements?
} Struct8002450C;

void func_global_asm_8072AB74(s32, f32, f32, s32, f32);
s32 func_boss_80024568(Struct8002450C*, u8, f32, f32, f32);

// TODO: Close, just gotta figure out sp48 and D_boss_8003598C
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_boss_80024000.s")

/*
typedef struct {
    u16 unk0;
} Struct80024000;

extern s32 D_global_asm_8071FFA0;
extern Struct80024000 D_boss_8003598C[];

void func_boss_80024000(void) {
    Struct80024000 sp48[6];
    s16 i;

    for (i = 0; i < 6; i++) {
        sp48[i] = D_boss_8003598C[i];
        func_global_asm_8067E2E4(current_actor_pointer, sp48[i].unk0, 3.0f);
    }
    for (i = 0; i < 0xC; i++) {
        func_global_asm_8071498C(&func_global_asm_8071E864);
        func_global_asm_80714950(i);
        func_global_asm_807149B8(1);
        func_global_asm_807149C8(0x8C, 0x8C, 0x8C, 0xFF);
        func_global_asm_80714998(3);
        func_global_asm_80714CC0(&D_global_asm_8071FFA0, 2.5f, current_actor_pointer->x_position, current_actor_pointer->y_position + 40.0f, current_actor_pointer->z_position);
    }
}
*/

// Flag check, animation state, unrolled loops
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_boss_8002413C.s")

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct800358E0;

extern u8 D_boss_800358D8[];
extern Struct800358E0 D_boss_800358E0[];
extern u8 D_boss_80035994[];

/*
void func_boss_8002413C(void) {
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
    func_global_asm_80724D28(1, 0xD);
    func_global_asm_80724DB0(1, 5);
    func_global_asm_80724CA4(1, 5);
    var_v0 = current_actor_pointer->animation_state->unk24;
    var_a0 = current_actor_pointer->animation_state->unk20;
    var_a1 = current_actor_pointer->animation_state->unk1C;
    for (i = 0; i < 5; i++) {
        var_v0[i - 1].unk0 = D_boss_800358D8[i];
        var_v0[i - 1].unk1 = 0xFF;
        temp_a2_2 = &D_boss_800358E0[i + var_a3 * 5];
        var_v0[i - 1].unk4 = temp_a2_2->unk0;
        var_v0[i - 1].unk8 = temp_a2_2->unk1;
        var_v0[i - 1].unkC = temp_a2_2->unk2;
        var_a0[i - 1].unk0 = D_boss_800358D8[i];
        var_a0[i - 1].unk1 = 0xFF;
        var_a0[i - 1].unk4 = temp_a2_2->unk4;
        var_a0[i - 1].unk8 = temp_a2_2->unk8;
        var_a0[i - 1].unkC = temp_a2_2->unkC;
        var_a1[i - 1].unk0 = -0x80;
        var_a1[i - 1].unk1 = D_boss_800358D8[i];
        var_a1[i - 1].unk2 = 0;
        var_a1[i - 1].unk4 = 0;
        var_a1[i - 1].unk6 = 0;
    }
    for (j = 0; j < 8; j++) {
        var_v0[j - 1].unk0 = D_boss_80035994[j];
        var_v0[j].unk1 = 0xFF;
        var_v0[j].unk4 = 0.0f;
        var_v0[j].unk8 = 0.0f;
        var_v0[j].unkC = 0.0f;
    }
}
*/

void func_boss_80024300(void) {
    AnimationStateUnk24 *var_a0;
    s16 var_a3;
    s16 i;
    s32 var_v1;

    var_a0 = current_actor_pointer->animation_state->unk24;
    var_a3 = 0;
    var_v1 = 0xFF;
    switch (D_global_asm_807FDC90->unk2C) {
        case 19:
            var_a3 = 0x22;
            break;
        case 17:
            var_a3 = 0xF6;
            break;
        case 15:
            var_a3 = 0x17;
            break;
        case 13:
            var_a3 = 0xED;
            break;
        case 11:
            var_a3 = 0x18;
            break;
        case 9:
            var_a3 = 0x22;
            var_v1 = 0xC8;
            break;
        case 7:
            var_a3 = 0xED;
            var_v1 = 0x82;
            break;
        case 5:
            var_a3 = 0x18;
            var_v1 = 0x46;
            break;
        case 3:
            var_a3 = 0x3C;
            break;
    }
    if (var_a3 != 0) {
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, var_a3, var_v1, 0x7F, 1, 0x1E, 0.3f, 0);
    }
    current_actor_pointer->animation_state->unk24[5].unk4 = 99999.0f;
    for (i = 0; i < 0xD; i++) {
        if (var_a0->unk8 >= 1800.0f) {
            var_a0->unk4 = 99999.0f;
            var_a0->unk8 = 99999.0f;
            var_a0->unkC = 99999.0f;
            var_a0++;
        } else {
            var_a0->unk4 += 200.0f * func_global_asm_80612794(i * 0x190);
            var_a0->unkC += 200.0f * func_global_asm_80612790(i * 0x190);
            var_a0->unk8 += 100.0f;
            var_a0++;
        }
    }
}

void func_boss_8002450C(Struct8002450C *arg0, u8 arg1, u8 arg2) {    
    arg0->unk6[arg1] = arg2;
}

void func_boss_80024524(u8 arg0, s16 arg1) {
    AnimationStateUnk1C *temp_v0;

    temp_v0 = &current_actor_pointer->animation_state->unk1C[arg0];
    if (arg0 == 3) {
        temp_v0->unk1 = 0x2F;
    }
    temp_v0->unk2 = arg1;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_boss_80024568.s")

void func_boss_80024EAC(void) {
    s32 temp_v0;
    u16 sp2A;

    sp2A = current_actor_pointer->animation_state->unk64;
    func_global_asm_806CC10C(D_global_asm_807FDC90->unk8, current_actor_pointer->y_rotation);
    func_global_asm_8072AB74(0x45, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x16, 0.0f);
    temp_v0 = func_global_asm_806CC10C(D_global_asm_807FDC90->unk8, current_actor_pointer->y_rotation);
    if (temp_v0 > 0) {
        if (sp2A != 0x260) {
            playActorAnimation(current_actor_pointer, 0x260);
        }
    } else if (temp_v0 < 0) {
        if (sp2A != 0x25F) {
            playActorAnimation(current_actor_pointer, 0x25F);
        }
    } else if (sp2A != 0x25A) {
        playActorAnimation(current_actor_pointer, 0x25A);
        func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
    }
}

void func_boss_80024FA8(s32 arg0, Struct8002450C *arg1, s32 arg2, u8 *arg3) {
    u8 i = 0;
    u8 phi_v0 = 0;

    switch (current_actor_pointer->control_state_progress) {
        case 2:
            while (arg3[i] != 0xFF) {
                func_boss_8002450C(arg1, arg3[i++], 1);
            }
            current_actor_pointer->control_state_progress = 3;
            return;
        case 3:
            while (arg3[i] != 0xFF) {
                if ((current_actor_pointer->control_state == 0x27) || (current_actor_pointer->control_state == 0x2E)) {
                    phi_v0 = func_boss_80024568(arg1, arg3[i++], 50.0f, 70.0f, 90.0f);
                } else {
                    phi_v0 = func_boss_80024568(arg1, arg3[i++], 10.0f, 15.0f, 50.0f);
                }
            }
            if (phi_v0 != 0) {
                current_actor_pointer->control_state_progress = 4;
                func_global_asm_8068842C(current_actor_pointer, 1, 1);
            }
            return;
    }
}

void func_boss_800251A0(s32 arg0, Struct8002450C *arg1, s32 arg2, u8 *arg3) {
    u8 i = 0;
    s32 phi_v1 = 0;

    switch (current_actor_pointer->control_state_progress) {
        case 2:
            while (arg3[i] != 0xFF) {
                func_boss_8002450C(arg1, arg3[i++], 3);
            }
            current_actor_pointer->control_state_progress = 3;
            break;
        case 3:
            while (arg3[i] != 0xFF) {
                phi_v1 = func_boss_80024568(arg1, arg3[i++], 10.0f, 20.0f, 30.0f) & 0xFF;
            }
            if (phi_v1 != 0) {
                current_actor_pointer->control_state_progress = 4;
                func_global_asm_8068842C(current_actor_pointer, 1, 1);
            }
            break;
    }
}

void func_boss_8002531C(void) {
    func_global_asm_8066EA90(current_actor_pointer, 3);
    func_global_asm_8066EA90(current_actor_pointer, 4);
    func_global_asm_8066EA90(current_actor_pointer, 5);
}

void func_boss_80025364(void) {
    func_global_asm_8066EA64(current_actor_pointer, 3);
    func_global_asm_8066EA64(current_actor_pointer, 4);
    func_global_asm_8066EA64(current_actor_pointer, 5);
}

void func_boss_800253AC(void) {
    f32 temp2;

    temp2 = ((f32)((f32)(((MAX(current_actor_pointer->y_velocity, 0.0) / 150.0)) * 0.12) + 0.3) * 4.0f);
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(&func_global_asm_8071AF30);
    func_global_asm_807149A8(1000);
    func_global_asm_80714950(current_actor_pointer);
    func_global_asm_80714C08(&D_global_asm_80720120, temp2, current_actor_pointer, 3, 0);
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(&func_global_asm_8071AF30);
    func_global_asm_807149A8(1000);
    func_global_asm_80714950(current_actor_pointer);
    func_global_asm_80714C08(&D_global_asm_80720120, temp2, current_actor_pointer, 4, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_0/func_boss_800254D0.s")

void func_boss_80027770(void) {
    u8 var_v1;

    if (!(object_timer & 3)) {
        if (!(object_timer & 0xF)) {
            var_v1 = 0xC;
        } else {
            var_v1 = ((((rand() >> 0xF) % 32767) % 7) + 0x1D);
        }
        func_global_asm_80714998(3);
        func_global_asm_807149C8(0x50, 0x50, 0x50, 0xC8);
        func_global_asm_8068588C(current_actor_pointer, var_v1, 2.0f, 0.0f, 0.0f, 0.0f, -0x78);
    }
}
