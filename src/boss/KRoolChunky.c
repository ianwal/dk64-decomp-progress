#include <ultra64.h>
#include "functions.h"

// .rodata
static const s32 D_boss_80036A90[] = {
    0x00546C5F,
    0x005103E4,
    0x41002741,
    0x01274102,
    0x27284F4B,
    0x00062750,
};

static const s32 D_boss_80036AA8[] = {
    0x284F4B00,
    0x06275000,
};

// .data
static void *D_boss_80035AC0[4] = {
    D_boss_80036A90,
    D_boss_80036AA8,
    D_boss_80036AA8,
    D_boss_80036AA8,
};

static u8 D_boss_80035AD0[4] = {0x03,0x00,0x02,0x01};

static f32 D_boss_80035AD4[4] = {
    0.015f,
    0.025f,
    0.03f,
    0.01f,
};

static f32 D_boss_80035AE4[4] = {
    1.0f,
    1.3f,
    1.8f,
    0.7f,
};

void func_boss_80030920(KRoolChunkyAAD178 *arg0) {
    extra_player_info_pointer->unk1FE = 1;
    func_boss_800290D4(1);
    current_actor_pointer->noclip_byte = 0x24;
    setAction(0x19, current_actor_pointer, 0);
    func_global_asm_80724B5C(1, 8, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    D_global_asm_807FDC90->unkA = current_actor_pointer->x_position;
    D_global_asm_807FDC90->unkC = current_actor_pointer->y_position;
    D_global_asm_807FDC90->unkE = current_actor_pointer->z_position;
    func_global_asm_80724B5C(1, 0x20, &player_pointer->x_position, &player_pointer->y_position, &player_pointer->z_position);
    player_pointer->y_rotation = func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position);
    current_actor_pointer->unkEE = \
    current_actor_pointer->y_rotation = player_pointer->y_rotation + 0x800;
    playActorAnimation(current_actor_pointer, 0x3F9);
    if (func_global_asm_8061CB50()) {
        func_global_asm_8061D4E4(D_global_asm_807F5D10);
    }
    func_global_asm_8061C464(D_global_asm_807F5D10, player_pointer, 4, 0x800, 0x5A, 0, 0x46, 0x64, 0x3A, 0, 0.3f);
}

void func_boss_80030AE0(KRoolChunkyAAD178 *arg0) {
    func_boss_800290D4(0);
    extra_player_info_pointer->unk1F4 = 0;
    if (player_pointer->control_state != 0x36) {
        func_global_asm_806CFF9C(player_pointer);
    }
    func_global_asm_806224CC(D_global_asm_807F5D10, player_pointer);
    extra_player_info_pointer->unk1D8 = 0.01f;
    func_global_asm_8063DA40(0xB, arg0->unk14 <= 0 ? 0 : 4);
    func_global_asm_8063DA40(0xC, arg0->unk14 < 2 ? 0 : 4);
    func_global_asm_8063DA40(0xD, arg0->unk14 < 3 ? 0 : 4);
    func_global_asm_8063DA40(0xE, arg0->unk14 < 4 ? 0 : 4);
    func_global_asm_8063DA40(0xA, 0xA);
}

void func_boss_80030C30(f32 arg0) {
    current_actor_pointer->x_position = ((player_pointer->x_position - D_global_asm_807FDC90->unkA) * current_actor_pointer->unk160) + D_global_asm_807FDC90->unkA;
    current_actor_pointer->y_position = ((player_pointer->y_position - D_global_asm_807FDC90->unkC) * current_actor_pointer->unk160) + D_global_asm_807FDC90->unkC;
    current_actor_pointer->z_position = ((player_pointer->z_position - D_global_asm_807FDC90->unkE) * current_actor_pointer->unk160) + D_global_asm_807FDC90->unkE;
    current_actor_pointer->unk160 += arg0;
    if (0.8 < current_actor_pointer->unk160) {
        current_actor_pointer->unk160 = 0.8;
    }
}

void func_boss_80030D50(void) {
    s32 temp; // TODO: Can this be removed somehow? Messes up a stack offset
    f32 sp20;

    sp20 = func_global_asm_80612794(current_actor_pointer->unk160 * 10240.0);
    current_actor_pointer->x_position += 80.0f * func_global_asm_80612794(current_actor_pointer->y_rotation + 0x400) * sp20;
    sp20 = func_global_asm_80612794(current_actor_pointer->unk160 * 10240.0);
    current_actor_pointer->z_position += 80.0f * func_global_asm_80612790(current_actor_pointer->y_rotation + 0x400) * sp20;
}

void func_boss_80030E58(void) {
    D_global_asm_807FDC90->unk1A |= 1;
    playSoundAtPosition(
        current_actor_pointer->x_position, 
        current_actor_pointer->y_position, 
        current_actor_pointer->z_position, 
        0x2E2, 0xFF, 0x65, 0, 0, 0.0f, 0
    );
}

u8 func_boss_80027BA8(u8 *, u16, f32);
void func_global_asm_806D0468(Actor *arg0, u8 arg1);
s32 func_global_asm_8072881C(s32, s32 *);
extern u8 D_global_asm_807FBD70;

void func_boss_80030EC4(void) {
    KRoolChunkyAAD178 *temp_a3;
    u8 *sp58;
    s16 shadow_dec;
    s16 x, y, z;

    temp_a3 = current_actor_pointer->unk178;
    sp58 = D_boss_80035AC0[temp_a3->unk14];
    initializeCharacterSpawnerActor();
    func_boss_80028878(sp58);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80626110(D_global_asm_807F5D10, 0, 0);
        current_actor_pointer->unk146_s16 = 5;
        current_actor_pointer->control_state = 0x1E;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkCC = 0;
        func_global_asm_80724CA4(2, 1);
        current_actor_pointer->locked_to_pad = 0;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        func_global_asm_806D0430(0.45f);
        func_boss_800290D4(0U);
        setFlag(0x5F, FALSE, FLAG_TYPE_TEMPORARY);
    }
    if (D_global_asm_807FDC90->unk1A & 1) {
        shadow_dec = temp_a3->unk14 > 0 ? 0xA : 5;
        current_actor_pointer->shadow_opacity -= shadow_dec;
        if (current_actor_pointer->shadow_opacity < 0) {
            current_actor_pointer->shadow_opacity = 0;
            D_global_asm_807FDC90->unk1A &= 0xFFFE;
        }
    } else if ((current_actor_pointer->control_state != 0x29) && (extra_player_info_pointer->unk1F0 & 0x40) && (current_actor_pointer->shadow_opacity < 0xFF)) {
        if (!(D_global_asm_807FDC90->unk1A & 0x8000)) {
            playCutscene(current_actor_pointer, 2, 1);
            D_global_asm_807FDC90->unk1A |= 0x8000;
        } else {
            func_global_asm_80641874(2, 0);
        }
        current_actor_pointer->shadow_opacity += 5;
        if (current_actor_pointer->shadow_opacity >= 0x100) {
            current_actor_pointer->shadow_opacity = 0xFF;
        }
    }
    if ((character_change_array->unk2C0 != 1) && ((current_actor_pointer->control_state == 0x42) || (current_actor_pointer->control_state == 0x27))) {
        current_actor_pointer->noclip_byte = 1;
        func_global_asm_8072B324(current_actor_pointer, 0);
        current_actor_pointer->control_state = 0x29;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->control_state_progress = 1;
    }
    switch (current_actor_pointer->control_state) {
    case 0x29:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_8072AB74(0U, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x309U, 0.0f);
            break;
        case 1:
            if (temp_a3->unk14 >= 2) {
                func_boss_80030E58();
            }
            current_actor_pointer->unk132 = 4;
            func_boss_80030920(temp_a3);
            func_global_asm_80614D00(current_actor_pointer, D_boss_80035AE4[temp_a3->unk14], 0.0f);
            current_actor_pointer->control_state_progress++;
            break;
        case 3:
            current_actor_pointer->unk160 = 0.0;
            current_actor_pointer->control_state_progress++;
        case 4:
            func_boss_80030C30(D_boss_80035AD4[temp_a3->unk14]);
            if (temp_a3->unk14 == 3) {
                func_boss_80030D50();
            }
            break;
        case 5:
            current_actor_pointer->control_state_progress++;
            break;
        case 6:
            if ((D_global_asm_807FBD70 == 5) && (player_pointer->control_state == 0x24) && (current_actor_pointer->unk160 > 0.79)) {
                if (temp_a3->unk14 == 3) {
                    current_actor_pointer->control_state = 0x37;
                    current_actor_pointer->control_state_progress = 0;
                    playActorAnimation(player_pointer, 0);
                    playActorAnimation(current_actor_pointer, 0);
                    playCutscene(current_actor_pointer, 0x16, 1);
                    setFlag(0x1B0, 1U, 0U);
                } else {
                    current_actor_pointer->shadow_opacity = 0xFF;
                    current_actor_pointer->unk132 = 1;
                    current_actor_pointer->control_state_progress = 8;
                    playCutscene(current_actor_pointer, 0x17, 1);
                    playActorAnimation(current_actor_pointer, 0);
                }
                func_global_asm_80641874(2, 0xFF);
            }
            func_boss_80030C30(D_boss_80035AD4[temp_a3->unk14]);
            if (temp_a3->unk14 == 3) {
                func_boss_80030D50();
            }
            break;
        case 7:
            current_actor_pointer->shadow_opacity = 0xFF;
            extra_player_info_pointer->unkD4 = 0x12C;
            playCutscene(current_actor_pointer, 0x18, 1);
            func_global_asm_80641874(2, 0xFF);
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            playActorAnimation(current_actor_pointer, 0);
            current_actor_pointer->control_state_progress = 0xA;
            break;
        case 8:
            if (func_global_asm_8061CB50() == 0) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 9:
            temp_a3->unk15 = 0U;
            temp_a3->unk14++;
            sp58 = D_boss_80035AC0[temp_a3->unk14];
        case 10:
        case 11:
        case 12:
            if (func_global_asm_8061CB50() == 0) {
                func_global_asm_806D0468(player_pointer, 1);
                func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
                if (current_actor_pointer->unk132 != 1) {
                    if (func_global_asm_806C9974(0U, -1) != 0) {
                        playAnimation(player_pointer, 0x27);
                        player_pointer->control_state = 0x36;
                        player_pointer->control_state_progress = 0;
                    }
                    current_actor_pointer->unk132 = 1;
                    temp_a3->unk15 = temp_a3->unk16;
                }
                func_boss_80030AE0(temp_a3);
                current_actor_pointer->control_state = sp58[temp_a3->unk15++];
                current_actor_pointer->control_state_progress = 0;
                playActorAnimation(current_actor_pointer, 0x3E4);
                func_boss_80030E58();
            }
            break;
        }
        break;
    case 0x28:
        func_boss_80030E58();
        current_actor_pointer->control_state = sp58[temp_a3->unk15];
        temp_a3->unk15 = (u8) (temp_a3->unk15 + 1);
        current_actor_pointer->control_state_progress = 0;
        break;
    case 0x27:
        switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_8072CFE8(&x, &y, &z);
            func_global_asm_806A1008(D_boss_80035AD0[D_global_asm_807FDC98->unk20[D_global_asm_807FDC90->unk25 & 0x7F].unk0 - 1], 1U);
            current_actor_pointer->unkEC = func_global_asm_80665DE0(x, z, current_actor_pointer->x_position, current_actor_pointer->z_position);
            if (func_global_asm_806CC10C(current_actor_pointer->y_rotation, current_actor_pointer->unkEC) < 0) {
                playActorAnimation(current_actor_pointer, 0x401);
            } else {
                playActorAnimation(current_actor_pointer, 0x402);
            }
            func_global_asm_8072B324(current_actor_pointer, 0);
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, (s16) (current_actor_pointer->unkEC + 0x800), 10.0f);
            func_global_asm_8072AB74(0U, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x309U, 0.0f);
            break;
        case 2:
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            current_actor_pointer->unkB8 = -150.0f;
            current_actor_pointer->control_state_progress++;
        case 3:
            func_global_asm_8072AB74(0U, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x309U, 0.0f);
            break;
        case 4:
            current_actor_pointer->unkB8 *= -1.0f;
            current_actor_pointer->y_rotation += 0x800;
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
            current_actor_pointer->control_state = sp58[temp_a3->unk15++];
            current_actor_pointer->control_state_progress = 0;
            break;
        }
        break;
    case 0x1E:
        temp_a3->unk14 = 0U;
        temp_a3->unk15 = 0U;
        current_actor_pointer->control_state = sp58[temp_a3->unk15++];
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkC;
        break;
    case 0x0:
        switch (current_actor_pointer->control_state_progress) {
            case 0:
                playActorAnimation(current_actor_pointer, 0x3EA);
                current_actor_pointer->control_state_progress++;
                break;
            case 2:
                current_actor_pointer->control_state = sp58[temp_a3->unk15++];
                current_actor_pointer->control_state_progress = 0;
                break;
        }
        break;
    case 0x37:
        switch (current_actor_pointer->control_state_progress) {
            case 0:
                current_actor_pointer->control_state_progress++;
                break;
            case 1:
                if (func_global_asm_80629148()) {
                    player_pointer->object_properties_bitfield &= ~4;
                    playCutscene(current_actor_pointer, 0x1A, 1);
                    current_actor_pointer->control_state_progress++;
                }
                break;
        }
        break;
    default:
        func_boss_80027BA8(sp58, 0x19, 0.0f);
        break;
    }
    if (current_actor_pointer->object_properties_bitfield & 4) {
        func_global_asm_8065D244(1U);
        func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x3C, 0x3C, 1, 0x12C, 0xB4, 0, 1.0f);
    }
    if (func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28) != 0) {
        func_global_asm_8072881C(0x81, &D_global_asm_807FDC90->unk28);
    }
    renderActor(current_actor_pointer, 0U);
}
