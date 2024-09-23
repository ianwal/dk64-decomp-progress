#include <ultra64.h>
#include "functions.h"
#include "sprites.h"


extern u8 D_global_asm_807FBD70;
extern s32 D_global_asm_80750600[];

// TODO: Are these correct?
extern SpriteData D_global_asm_8071FFA0;

void func_global_asm_806B11C0(u8 boneIndex) {
    f32 x, y, z;

    getBonePosition(current_actor_pointer, boneIndex, &x, &y, &z);
    func_global_asm_80685B44(&D_global_asm_8071FFA0, 0, 1.0f, 3, 5, 0x28, x, current_actor_pointer->floor, z);
    // spawnShockwave
    func_global_asm_806846B4(x, current_actor_pointer->floor, z, 0.05f, 0.04, current_actor_pointer, 0);
}

void func_global_asm_806B1290(void) {
    // TODO: Hahahaha clean this up
    if (D_global_asm_807FDC90->unk18 >= 0x65
        && ((D_global_asm_807FDC90->unk1A & 0x80) && (rand() >> 0xF) % 1000 >= 981
            || !((rand() >> 0xF) % 1000 < 991)
            && current_actor_pointer->object_properties_bitfield & 0x100)) {
        current_actor_pointer->control_state = 0x28;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806B1348(void) {
    if ((D_global_asm_807FDC90->unk18 >= 0x65) && (D_global_asm_807FBD70 == 2) && (func_global_asm_8072DE10(0x2710) != 0)) {
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
    }
}

// Jumptable, close, doable
// https://decomp.me/scratch/ryD0r
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B5EC0/func_global_asm_806B13B4.s")

void func_global_asm_8072C918(s16, s16, s16);

/*
void func_global_asm_806B13B4(u8 arg0) {
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (current_map == MAP_STASH_SNATCH_NORMAL) {
            D_global_asm_807FDC9C->unkD = 0x82;
            D_global_asm_807FDC98->unk46 |= 0x40;
        }
        func_global_asm_8072B79C(0x205, 0x203, 0x204);
        func_global_asm_80724CA4(2, 1);
    }
    if (current_actor_pointer->control_state == 0x27) {
        current_actor_pointer->unk132 = 2;
    } else if (current_actor_pointer->control_state != 0x32) {
        current_actor_pointer->unk132 = 1;
    }
    if (current_actor_pointer->control_state != 0x32 || D_global_asm_807FBB70.unk15 != 0) {
        if (D_global_asm_807FBB70.unk200 == 9 || D_global_asm_807FBB70.unk15 != 0) {
            if (current_actor_pointer->control_state != 0x37) {
                if (current_actor_pointer->health < -1) {
                    func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x20C);
                    current_actor_pointer->y_velocity = 250.0f;
                } else {
                    func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x20B);
                    current_actor_pointer->y_velocity = 200.0f;
                }
                D_global_asm_807FDC90->unk35 = 2;
                current_actor_pointer->unk138 &= 0xFFFF7FFF;
            }
        } else if (D_global_asm_807FBB70.unk200 == 4) {
            func_global_asm_8072DEA8(0x209, 0x31, D_global_asm_807FBB70.unk1FC);
        } else if (D_global_asm_807FBB70.unk200 == 5) {
            func_global_asm_8072DEA8(0x20A, 0x32, D_global_asm_807FBB70.unk1FC);
            current_actor_pointer->y_velocity = 220.0f;
            current_actor_pointer->unk132 = 8;
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0x31:
            if (current_actor_pointer->control_state_progress != 0 || current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
                func_global_asm_8072DE44(0x203);
            }
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4300, 0.0f);
            break;
        case 0x32:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 7.0f);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4300, 0.0f);
                    break;
                case 1:
                    current_actor_pointer->unk132 = 1;
                    func_global_asm_8072DE44(0x203);
                    break;
            }
            break;
        case 0x28:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    playActorAnimation(current_actor_pointer, 0x20D);
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 2:
                    func_global_asm_806B11C0(1);
                    func_global_asm_806B11C0(2);
                    playSoundAtActorPosition(current_actor_pointer, 0x1D5, 0xFF, 0x7F, 1);
                    playSoundAtActorPosition(current_actor_pointer, 0x25A, 0xFF, 0x7F, 1);
                    current_actor_pointer->control_state_progress = 3;
                    break;
                case 4:
                    func_global_asm_8072DE44(0x203);
                    break;
            }
            break;
        case 0x11:
            func_global_asm_80724E48(5);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(current_actor_pointer, 0);
                    playActorAnimation(current_actor_pointer, 0x205);
                    current_actor_pointer->control_state_progress++;
                    // fallthrough
                case 1:
                    func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    if (current_actor_pointer->unkB8 < 1.0f) {
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 2:
                    func_global_asm_8072A450();
                    if (((rand() >> 0xF) % 1000) >= 0x3E4) {
                        func_global_asm_8072DE44(0x203);
                    }
                    break;
            }
            break;
        case 0x27:
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(current_actor_pointer, 0);
                    if (((rand() >> 0xF) % 1000) >= 0x259) {
                        playActorAnimation(current_actor_pointer, 0x208);
                        current_actor_pointer->control_state_progress = 5;
                    } else {
                        playActorAnimation(current_actor_pointer, 0x206);
                        current_actor_pointer->control_state_progress = 1;
                    }
                default:
                    break;
                case 1:
                    if (D_global_asm_807FDC90->unk1A & 0x100) {
                        func_global_asm_8066EA90(current_actor_pointer, 2);
                        func_global_asm_8066EA90(current_actor_pointer, 3);
                    }
                    break;
                case 2:
                    if (D_global_asm_807FDC90->unk1A & 0x100) {
                        D_global_asm_807FDC90->unk1A &= 0xFEFF;
                        playActorAnimation(current_actor_pointer, 0x207);
                        current_actor_pointer->control_state_progress = 3;
                    } else {
                        func_global_asm_8072DE44(0x203);
                    }
                    break;
                case 3:
                    if (D_global_asm_807FDC90->unk1A & 0x100) {
                        D_global_asm_807FDC90->unk1A &= 0xFEFF;
                        playActorAnimation(current_actor_pointer, 0x208);
                        current_actor_pointer->control_state_progress = 5;
                    }
                    break;
                case 4:
                    func_global_asm_8072DE44(0x203);
                    break;
                case 5:
                    current_actor_pointer->unk132 = 4;
                    break;
            }
            break;
        case 0x1:
            if (func_global_asm_8072E54C()) {
                current_actor_pointer->control_state = 0x11;
                current_actor_pointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x10:
        case 0x23:
            if (func_global_asm_8061CB50() == 0) {
                func_global_asm_806B1290();
                func_global_asm_806B1348();
            }
            func_global_asm_80724E48(current_actor_pointer->control_state == 1 ? 2 : 0);
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_80724E48(current_actor_pointer->control_state == 0x35 ? 2 : 3);
            func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            break;
        case 0x37:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 7.0f);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 1:
                    if (arg0 != 0) {
                        func_global_asm_806A5C60(current_actor_pointer);
                    }
                    current_actor_pointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x200, 0.0f);
                    func_global_asm_8072DC7C(8);
                    break;
                case 3:
                    current_actor_pointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x203);
            break;
    }
    switch (current_actor_pointer->control_state) {
        case 0x31:
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(current_actor_pointer->control_state, 1);
            // fallthrough
        default:
            func_global_asm_8072C918(0x6400, 0x203, 0x204);
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806B1D78(u8 arg0) {
    func_global_asm_8068842C(current_actor_pointer, 0, 1);
    func_global_asm_80688460(current_actor_pointer, 0, 1);
    func_global_asm_806883F4(current_actor_pointer, 0, arg0, 0);
}

void func_global_asm_806B1DD4(u8 arg0) {
    u8 phi_v1;
    s32 levelIndex;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        phi_v1 = 0;
        levelIndex = func_global_asm_805FF000(D_global_asm_8076A0AB);
        if ((levelIndex != 9) && (levelIndex != 0xA)) {
            levelIndex = getLevelIndex(D_global_asm_8076A0AB, TRUE);
            phi_v1 = !func_global_asm_80731A04(0x1D5, levelIndex, levelIndex, D_global_asm_80750600[arg0]);
        }
        func_global_asm_806B1D78(phi_v1 != 0 ? arg0 : 5);
        current_actor_pointer->unk15F = phi_v1;
    }
    func_global_asm_806B13B4(current_actor_pointer->unk15F);
}

void func_global_asm_806B1EA8(void) {
    func_global_asm_806B1DD4(4);
}

void func_global_asm_806B1EC8(void) {
    func_global_asm_806B1DD4(2);
}

void func_global_asm_806B1EE8(void) {
    func_global_asm_806B1DD4(3);
}

void func_global_asm_806B1F08(void) {
    func_global_asm_806B1DD4(0);
}

void func_global_asm_806B1F28(void) {
    func_global_asm_806B1DD4(1);
}
