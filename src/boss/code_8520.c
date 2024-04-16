#include <ultra64.h>
#include "functions.h"

void func_boss_8002C520(s16, s16, s16);

void func_boss_8002C520(s16 arg0, s16 arg1, s16 arg2) {
    func_global_asm_807271F4(arg0,
                  current_actor_pointer->x_position + (func_global_asm_80612794(arg2) * arg1),
                  D_global_asm_807FDC9C->unk6,
                  current_actor_pointer->z_position + (func_global_asm_80612790(arg2) * arg1),
                  0,
                  0,
                  0);
    last_spawned_actor->terminal_velocity *= 2;
    last_spawned_actor->draw_distance = 2000;
}

void func_boss_8002C5F4(void) {
    func_boss_8002C520(2, ((rand() >> 0xF) % 100) + 300, (rand() >> 0xF) % 4096);
    func_boss_8002C520(3, ((rand() >> 0xF) % 100) + 300, (rand() >> 0xF) % 4096);
    func_boss_8002C520(4, ((rand() >> 0xF) % 100) + 300, (rand() >> 0xF) % 4096);
    if (!(D_global_asm_807FDC90->unk1A & 0x8000)) {
        D_global_asm_807FDC90->unk1A |= 0x8000;
        playCutscene(last_spawned_actor, 2, 1);
    }
}

void func_boss_8002C748(u8 arg0) {
    D_global_asm_807FDC90->unk28 = 2;
    func_global_asm_8068842C(current_actor_pointer, arg0, 1);
    func_global_asm_80688460(current_actor_pointer, arg0, 1);
    func_global_asm_806883F4(current_actor_pointer, arg0, D_global_asm_807FDC90->unk28 & 0xF, 0);
}

void func_boss_8002C7CC(void) {
    u16 sp26;
    u8 sp25;
    u8 sp20;

    sp25 = D_global_asm_807FDC90->unk28 & 0x80;
    sp20 = D_global_asm_807FDC90->unk28 & 0xF;
    sp26 = 0;
    if (sp25) {
        sp20++;
        if (sp20 >= 2) {
            sp25 = 0;
        } else {
            sp26 = 0x8000;
        }
    } else {
        sp20--;
        if (sp20 <= 0) {
            sp25 = 0x80;
        } else {
            sp26 = 0x8000;
        }
    }
    func_global_asm_806883F4(current_actor_pointer, 0, sp20, 0);
    func_global_asm_806883F4(current_actor_pointer, 1, sp20, 0);
    D_global_asm_807FDC90->unk28 = sp26 | sp20 | sp25;
}

void func_boss_8002C8B4(void) {
    func_global_asm_80690814(current_actor_pointer, 1);
    func_global_asm_80690A28(0x116, 
                (((rand() >> 0xF) % 3) + 1), 
                1.0f, 
                D_global_asm_807FDC94->x_position, 
                D_global_asm_807FDC94->y_position + D_global_asm_807FDC94->unk15E, 
                D_global_asm_807FDC94->z_position, 
                300.0f, 
                current_actor_pointer);
}

extern u8 D_global_asm_807FBB85;
extern u8 D_global_asm_807FBD70;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} A178_8002C964;

void func_global_asm_8072AB74(s32, f32, f32, s32, f32);

void func_boss_8002C964(void) {
    A178_8002C964 *a178;
    f64 yScale;

    a178 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_boss_8002C748(0);
        func_boss_8002C748(1);
        D_global_asm_807FDC98->unk30 = 2.5f;
        D_global_asm_807FDC98->unk46 &= 0xFFF7;
        D_global_asm_807FDC98->unk46 |= 0x200;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        current_actor_pointer->unk132 = 4;
        current_actor_pointer->control_state = 0x1E;
        func_global_asm_807248B0(current_actor_pointer, 2.0 * current_actor_pointer->animation_state->scale[0]);
        func_global_asm_806AD9AC();
    }
    if (((D_global_asm_807FBD70 == 9) || (D_global_asm_807FBB85 != 0)) && (current_actor_pointer->control_state != 0x37)) {
        if (isFlagSet(0xF7, FLAG_TYPE_PERMANENT) != 0) {
            func_global_asm_8067E278(0, 1);
            current_actor_pointer->control_state = 0x40;
        } else {
            playCutscene(current_actor_pointer, 6, 1);
            current_actor_pointer->y_velocity = 200.0f;
            func_global_asm_8072D714(D_global_asm_807FBD6C, 0x2F7);
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0x28:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    playCutscene(current_actor_pointer, 8, 1);
                    playActorAnimation(current_actor_pointer, 0);
                    func_global_asm_80613C48(current_actor_pointer, 0x589, 0.0f, 0.0f);
                    D_global_asm_807FDC90->unk2C = 0;
                    current_actor_pointer->control_state_progress = 1;
                    current_actor_pointer->noclip_byte = 1;
                    playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x2FC, 0xFF, 0x7F, 0, 0, 0.0f, 0);
                    // fallthrough
                case 1:
                    D_global_asm_807FDC90->unk2C += 8;
                    if (D_global_asm_807FDC90->unk2C >= 0x259) {
                        current_actor_pointer->control_state_progress = 2;
                    }
                    current_actor_pointer->y_position += 2.0f;
                    current_actor_pointer->y_rotation += D_global_asm_807FDC90->unk2C;
                    yScale = current_actor_pointer->animation_state->scale[1];
                    func_global_asm_807248B0(current_actor_pointer, ((0.3 - yScale) * 0.05) + yScale);
                    break;
                case 2:
                    D_global_asm_807FDC90->unk2C -= 0x14;
                    if (D_global_asm_807FDC90->unk2C < 0) {
                        D_global_asm_807FDC90->unk2C = 0;
                    }
                    current_actor_pointer->y_rotation += D_global_asm_807FDC90->unk2C;
                    if (func_global_asm_80629148()) {
                        current_actor_pointer->control_state_progress = 3;
                        current_actor_pointer->object_properties_bitfield &= ~4;
                    }
                    break;
                case 3:
                    if (func_global_asm_80629148()) {
                        current_actor_pointer->unk15E = 0xA;
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        current_actor_pointer->unk132 = 1;
                        current_actor_pointer->control_state = 0x23;
                        func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkD);
                        current_actor_pointer->noclip_byte = 0x24;
                        playActorAnimation(current_actor_pointer, 0x2F4);
                    }
                    break;
            }
            break;
        case 0x1E:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    if (func_global_asm_80629148()) {
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        current_actor_pointer->control_state_progress = 1;
                    }
                    break;
                case 2:
                    if ((current_actor_pointer->y_position - current_actor_pointer->floor) > 300.0f) {
                        current_actor_pointer->y_position -= 10.0f;
                    } else {
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        current_actor_pointer->control_state_progress = 3;
                    }
                    break;
                case 3:
                    if (func_global_asm_80629148()) {
                        current_actor_pointer->control_state = 0x27;
                        current_actor_pointer->control_state_progress = 0;
                        func_global_asm_80626110(D_global_asm_807F5D10, 0, 0);
                    }
                    break;
            }
            break;
        case 0x27:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position), 8.0f);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_boss_8002C5F4();
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 1:
                    if ((func_global_asm_80726D7C(2) == 0) && (func_global_asm_80726D7C(3) == 0) && (func_global_asm_80726D7C(4) == 0)) {
                        current_actor_pointer->control_state_progress = 2;
                        D_global_asm_807FDC90->unk2C = 0x96;
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        current_actor_pointer->unk132 = 8;
                        playActorAnimation(current_actor_pointer, 0x2FA);
                    }
                    if ((func_global_asm_8061CB50() == 0) && (((rand() >> 0xF) % 1000) >= 0x3E4)) {
                        playActorAnimation(current_actor_pointer, 0x2FD);
                        current_actor_pointer->control_state_progress = 3;
                    }
                    break;
                case 2:
                    if ((D_global_asm_807FDC90->unk2C != 0) && (D_global_asm_807FBD70 != 4)) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        if (D_global_asm_807FBD70 == 4) {
                            playActorAnimation(current_actor_pointer, 0x2FC);
                            func_global_asm_8072D9D4();
                            a178->unk2 = 0x96;
                            a178->unk4 = 0x800;
                            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                            if (current_actor_pointer->health == 1) {
                                current_actor_pointer->control_state = 0x28;
                                current_actor_pointer->control_state_progress = 0;
                            }
                        }
                        current_actor_pointer->unk132 = 4;
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        current_actor_pointer->control_state_progress = 0;
                    }
                    break;
                case 4:
                    current_actor_pointer->control_state_progress = 1;
                    func_boss_8002C8B4();
                    break;
            }
            break;
        case 0x23:
            func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            break;
        case 0x37:
            func_global_asm_806AD260(0x2F7, 1, 0);
            break;
    }
    if (a178->unk2 > 0) {
        a178->unk0 = a178->unk2 * func_global_asm_80612794(a178->unk4);
        a178->unk4 += 0x32;
        a178->unk2--;
        current_actor_pointer->z_rotation = -a178->unk0;
        current_actor_pointer->x_position = (func_global_asm_80612794(current_actor_pointer->unkEE) * a178->unk0) + D_global_asm_807FDC9C->unk4;
        current_actor_pointer->z_position = (func_global_asm_80612790(current_actor_pointer->unkEE) * a178->unk0) + D_global_asm_807FDC9C->unk8;
        current_actor_pointer->y_position = D_global_asm_807FDC9C->unk6 - sqrtf(0x1C390 - (a178->unk0 * a178->unk0));
    }
    if (D_global_asm_807FDC90->unk28 & 0x8000) {
        func_boss_8002C7CC();
    }
    renderActor(current_actor_pointer, 0);
}
