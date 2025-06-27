#include "common.h"

s32 func_global_asm_8072881C(s32, s32);

// Not 100% on these signatures
void func_global_asm_8072C918(s16, s16, s16);

void func_global_asm_806AD260(s16 arg0, u8 arg1, s32 arg2) {
    if (arg0 != 0) {
        if (D_global_asm_807FBB70.unk200 == 9 || D_global_asm_807FBB70.unk15 != 0) {
            if (gCurrentActorPointer->control_state != 0x37) {
                gCurrentActorPointer->y_velocity = 200.0f;
                func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, arg0);
            }
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x1:
        case 0x10:
        case 0x15:
        case 0x23:
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, (gCurrentActorPointer->unk6A & 1) ? (u16)arg2 : (u16)arg2 | 2, 0);
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, arg2, 0);
            break;
        case 0x37:
            // TODO: Is there a better way to express case 2 in this switch?
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0, 0, ((u16)arg2 | 0x4200), 0);
                    break;
                case 1:
                    func_global_asm_806A5C60(gCurrentActorPointer);
                    if (arg1 != 0) {
                        gCurrentActorPointer->control_state_progress = 2;
                        break;
                    } else {
                        gCurrentActorPointer->y_velocity = 100.0f;
                        gCurrentActorPointer->control_state_progress++;
                case 2:
                        func_global_asm_8072AB74(0x37, 0, 0, ((u16)arg2 | 0x4200), 0);
                    }
                    break;
                case 3:
                    func_global_asm_8072DC7C(0xA);
                    break;
                case 4:
                    gCurrentActorPointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC((s16)D_global_asm_807FDC98->unk28);
            break;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(gCurrentActorPointer->control_state, 1);
            // fallthrough
        default:
            func_global_asm_8072C918(19600, (s16)D_global_asm_807FDC98->unk28, (s16)D_global_asm_807FDC98->unk2A);
            break;
    }
}

void func_global_asm_806AD54C(void) {
    f32 dx, dz;
    Actor *klaptrap;
    s32 angleSign;

    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_80724CA4(2, 1);
        func_global_asm_8072B79C(0x1F8, 0x1F8, 0x1F9);
        if (current_map == MAP_BEAVER_BOTHER_EASY || current_map == MAP_BEAVER_BOTHER_NORMAL || current_map == MAP_BEAVER_BOTHER_HARD) {
            gCurrentActorPointer->unk132 = 2;
        }
    }
    if ((gCurrentActorPointer->unk132 == 2) && (gCurrentActorPointer->control_state != 0x36)) {
        klaptrap = func_global_asm_8067ADB4(0x11A);
        if (klaptrap) {
            if (klaptrap->control_state != 0) {
                if (!(D_global_asm_807FDC90->unk1A & 0x8000)) {
                    dx = klaptrap->x_position - gCurrentActorPointer->x_position;
                    dz = klaptrap->z_position - gCurrentActorPointer->z_position;
                    if ((SQ(dx) + SQ(dz)) < SQ(40.0f)) {
                        angleSign = ((klaptrap->y_rotation - gCurrentActorPointer->y_rotation) & 0xFFF) >= 0x801 ? 1 : -1;
                        gCurrentActorPointer->unkB8 = D_global_asm_807FDC9C->unkD * 1.8;
                        gCurrentActorPointer->y_rotation += angleSign * 400;
                        gCurrentActorPointer->unkEE = gCurrentActorPointer->y_rotation;
                        D_global_asm_807FDC90->unk1A |= 0x8000;
                        gCurrentActorPointer->control_state = 0x10;
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                }
            } else {
                // Not Snapping
                D_global_asm_807FDC90->unk1A &= ~0x8000;
            }
        }
    }
    func_global_asm_806AD260(0x1FA, 0, 0);
    func_global_asm_80724E48(gCurrentActorPointer->control_state == 0x23 ? 0 : 2);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806AD7AC(void) {
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_80724CA4(2, 1);
        func_global_asm_8072B79C(0x1F8, 0x1F8, 0x1F9);
    }
    func_global_asm_806AD260(0x1FA, 0, 0);
    func_global_asm_80724E48(gCurrentActorPointer->control_state == 0x23 ? 0 : 2);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806AD84C(void) {
    f32 temp_f0;

    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        temp_f0 = 0.05f;
        gCurrentActorPointer->animation_state->scale_x = temp_f0;
        gCurrentActorPointer->animation_state->scale_z = temp_f0;
        gCurrentActorPointer->animation_state->scale_y = 2.0f;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if ((gCurrentActorPointer->unk11C == 0) || ((gCurrentActorPointer->unk11C->unk6A & 1))) {
                gCurrentActorPointer->control_state = 1;
                gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
            } else {
                getBonePosition(gCurrentActorPointer->unk11C, 2, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
                gCurrentActorPointer->z_rotation = gCurrentActorPointer->unk11C->z_rotation;
            }
            break;
        case 1:
            if (gCurrentActorPointer->shadow_opacity >= 0xB) {
                gCurrentActorPointer->shadow_opacity -= 0xA;
            } else {
                deleteActor(gCurrentActorPointer);
            }
            break;
    }
    gCurrentActorPointer->y_rotation = character_change_array[0].unk2C8 & 0xFFF;
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806AD9AC(void) {
    spawnActor(ACTOR_SILK, 0xC0);
    gLastSpawnedActor->unk11C = gCurrentActorPointer;
    gLastSpawnedActor->draw_distance = 2000;
}

void func_global_asm_806AD9F4(void) {
    s32 tmp_t0;
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_global_asm_807FDC98->unk46 |= 0x200;
        func_global_asm_8072B79C(0x2F4, 0x2F4, 0x2F4);
        if (gCurrentActorPointer->y_position != gCurrentActorPointer->floor) {
            gCurrentActorPointer->control_state = 0x1E;
            playActorAnimation(gCurrentActorPointer, 0x2F8);
            func_global_asm_806AD9AC();
        }
    }
    if (((D_global_asm_807FBB70.unk200 == 9) || D_global_asm_807FBB70.unk15) && (gCurrentActorPointer->control_state != 0x37)) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x2F7);
        func_global_asm_8072B324(gCurrentActorPointer, 0);
        gCurrentActorPointer->unkB8 = -200.0f;
    } else if (D_global_asm_807FBB70.unk200 == 4) {
        gCurrentActorPointer->unk132 = 2;
        func_global_asm_8072DEA8(0x2F6, 0x27, D_global_asm_807FBB70.unk1FC);
        gCurrentActorPointer->unkB8 *= 2;
        D_global_asm_807FDC90->unk2C = 0x1F4;
    }
    switch (gCurrentActorPointer->control_state) {
        case 30:
            func_global_asm_8072AB74(0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x4202, 0.0f);
            if (gCurrentActorPointer->control_state_progress != 0) {
                func_global_asm_8072DE44(0x2F4);
            }
            break;
        case 39:
            tmp_t0 = 1;
            func_global_asm_8072AB74(0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x4300, 0.0f);
            gCurrentActorPointer->y_rotation += D_global_asm_807FDC90->unk2C;
            if (D_global_asm_807FDC90->unk2C >= 0x15) {
                D_global_asm_807FDC90->unk2C -= 0x14;
            } else {
                D_global_asm_807FDC90->unk2C = 0;
                gCurrentActorPointer->unkEE = gCurrentActorPointer->y_rotation;
            }
            if ((gCurrentActorPointer->control_state_progress) && (D_global_asm_807FDC90->unk2C == 0)) {
                gCurrentActorPointer->unk132 = tmp_t0;
                func_global_asm_8072DE44(0x2F4);
            }
            break;
        case 40:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, 0x2F5);
                    gCurrentActorPointer->control_state_progress++;
                case 1:
                    func_global_asm_8072AB74(0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x4200, 0.0f);
                    if (gCurrentActorPointer->unkB8 < 1.0f) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 3:
                    func_global_asm_8072DE44(0x2F4);
                    break;
            }
            break;
        case 1:
            if (RandChance(0.005)) {
                if ((gCurrentActorPointer->unk6A & 1)) {
                    gCurrentActorPointer->control_state = 0x28;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
        default:
            func_global_asm_806AD260(0, 1, 0);
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806ADDD8(void) {
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_global_asm_807FDC98->unk46 |= 0x40;
        D_global_asm_807FDC98->unk28 = 0x31AU;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
        case 1:
            if (func_global_asm_8072E22C(300)) {
                playActorAnimation(gCurrentActorPointer, 0x31AU);
                gCurrentActorPointer->control_state = 0x23;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 4:
            if (gCurrentActorPointer->animation_state->unk64 != 0x319) {
                gCurrentActorPointer->control_state = 0x23;
                gCurrentActorPointer->control_state_progress = 0;
            } else if (func_global_asm_8072E22C(100)) {
                playActorAnimation(gCurrentActorPointer, 0x31B);
                gCurrentActorPointer->control_state = 0x1E;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 30:
            if (gCurrentActorPointer->animation_state->unk64 == 0x31AU) {
                gCurrentActorPointer->control_state = 0x23;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 35:
            if ((gCurrentActorPointer->animation_state->unk64 == 0x31AU) && (gCurrentActorPointer->animation_state->unk0->unk4 > 4.0f)) {
                func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            }
            if (!func_global_asm_8072E22C(300)) {
                playActorAnimation(gCurrentActorPointer, 0x31C);
                gCurrentActorPointer->control_state = 0;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x31AU);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
