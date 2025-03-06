#include <ultra64.h>
#include "functions.h"

extern f32 D_global_asm_8075B1A8;

void func_global_asm_806ADFE0(void) {
    f32 sp88[4][4];
    f32 sp48[4][4];

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unkB8 = RandClamp(50) + 0x46;
        gCurrentActorPointer->y_velocity = gCurrentActorPointer->unkB8 * 2;
        gCurrentActorPointer->y_acceleration = -30.0f;
        gCurrentActorPointer->terminal_velocity = -220.0f;
        gCurrentActorPointer->unk168 = RandClamp(400) + 0xC8;
    }
    gCurrentActorPointer->y_rotation += gCurrentActorPointer->unk168;
    if (gCurrentActorPointer->unk168 > 0) {
        gCurrentActorPointer->unk168 = gCurrentActorPointer->unk168 - 0xA;
    }
    func_global_asm_80666280(1);
    func_global_asm_80729E6C();
    func_global_asm_8067ACB4(gCurrentActorPointer);
    func_global_asm_806651FC(gCurrentActorPointer);
    func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0xC8, 0x80, 0, 1.0f);
    if (gCurrentActorPointer->unk15F != 0) {
        renderActor(gCurrentActorPointer, 0);
    } else {
        guTranslateF(sp88, 0.0f, -30.0f, 0.0f);
        func_global_asm_80612BC0(sp48, 180.0f);
        guMtxCatF(sp88, sp48, sp88);
        guTranslateF(sp48, 0.0f, 30.0f, 0.0f);
        guMtxCatF(sp88, sp48, &gCurrentActorPointer->unkC);
        renderActor(gCurrentActorPointer, 1);
    }
    if (((gCurrentActorPointer->unk6A & 1) != 0) && !(gCurrentActorPointer->unk6C & 1)) {
        playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x56, 0xB4, 0x96, 1, 0x4B, 0.3f, 0);
        gCurrentActorPointer->unkB8 *= 0.6;
        gCurrentActorPointer->y_velocity = gCurrentActorPointer->unkB8 * 3.0f;
        return;
    }
    if (((gCurrentActorPointer->unk6A & 1) != 0) && (gCurrentActorPointer->unk6C & 1)) {
        drawSpriteAtPosition(&D_global_asm_8071FBC8, 1.0f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
        deleteActor(gCurrentActorPointer);
    }
}

void func_global_asm_806AE2B0(s32 modelIndex, s16 arg1, s16 boneIndex, s16 arg3) {
    f32 x, y, z;

    if (spawnActor(ACTOR_KROSSBONES_HEAD, modelIndex)) {
        getBonePosition(gCurrentActorPointer, boneIndex, &x, &y, &z);
        gLastSpawnedActor->floor = gCurrentActorPointer->floor;
        gLastSpawnedActor->y_rotation = gCurrentActorPointer->y_rotation + arg1;
        gLastSpawnedActor->unkEE = gLastSpawnedActor->y_rotation;
        gLastSpawnedActor->unk168 = arg3;
        gLastSpawnedActor->x_position = x;
        gLastSpawnedActor->y_position = y;
        gLastSpawnedActor->z_position = z;
        func_global_asm_807248B0(gLastSpawnedActor, gCurrentActorPointer->animation_state->scale_y);
    }
}

void func_global_asm_806AE394(f32 arg0, f32 arg1) {
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    s16 sp4E;

    getBonePosition(gCurrentActorPointer, 1, &x1, &y1, &z1);
    getBonePosition(gCurrentActorPointer, 2, &x2, &y2, &z2);
    sp4E = func_global_asm_80665DE0(x2, z2, x1, z1);
    func_global_asm_8070033C(x1, y1, z1, x2, y2, z2, 0.6f, 0xFF, 0xFF, 0xFF);
    x1 = (func_global_asm_80612794(sp4E) * arg0) + gCurrentActorPointer->x_position;
    z1 = (func_global_asm_80612790(sp4E) * arg0) + gCurrentActorPointer->z_position;
    createLight(x1, gCurrentActorPointer->y_position, z1, 0.0f, 0.0f, 0.0f, arg1, 0, 0xFF, 0xFF, 0xFF);
    if (gCurrentActorPointer->control_state != 0) {
        if ((((D_global_asm_807FDC94->x_position - x1) * (D_global_asm_807FDC94->x_position - x1)) + ((D_global_asm_807FDC94->y_position - gCurrentActorPointer->y_position) * (D_global_asm_807FDC94->y_position - gCurrentActorPointer->y_position)) + ((D_global_asm_807FDC94->z_position - z1) * (D_global_asm_807FDC94->z_position - z1))) < (arg1 * arg1)) {
            gCurrentActorPointer->y_rotation = func_global_asm_80665DE0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position);
            setAction(0x43, gCurrentActorPointer, 0);
            gCurrentActorPointer->control_state = 0;
            gCurrentActorPointer->control_state_progress = 0;
        }
    }
}

// Jumptable, very close
// https://decomp.me/scratch/zfcEP
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AE588.s")

void func_global_asm_8072C918(s16, s16, s16);

void func_global_asm_8072A450(void);

/*
void func_global_asm_806AE588(void) {
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0x1FD, 0x1FB, 0x1FC);
        func_global_asm_80724CA4(3, 1);
        func_global_asm_8066EA90(gCurrentActorPointer, 3);
        if (current_map == MAP_KROOL_BARREL_DIDDY_KREMLING_GAME) {
            gCurrentActorPointer->unk132 = 1;
        }
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    if (gCurrentActorPointer->control_state != 0x32 || D_global_asm_807FBB70.unk15 != 0) {
        if (D_global_asm_807FBB70.unk200 != 9) {
            if (D_global_asm_807FBB70.unk15 == 0) {
                if (gCurrentActorPointer->control_state != 0x37) {
                    if (gCurrentActorPointer->health < -1) {
                        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x202);
                        gCurrentActorPointer->y_velocity = 250.0f;
                    } else {
                        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x201);
                        gCurrentActorPointer->y_velocity = 200.0f;
                    }
                    D_global_asm_807FDC90->unk35 = 2;
                    gCurrentActorPointer->unk138 &= 0xFFFF7FFF;
                } else if (D_global_asm_807FBB70.unk200 == 4) {
                    func_global_asm_8072DEA8(0x1FF, 0x31, D_global_asm_807FBB70.unk1FC);
                } else if (D_global_asm_807FBB70.unk200 == 5) {
                    func_global_asm_8072DEA8(0x200, 0x32, D_global_asm_807FBB70.unk1FC);
                    gCurrentActorPointer->y_velocity = 220.0f;
                }
            }
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x31:
            if (gCurrentActorPointer->control_state_progress != 0 || gCurrentActorPointer->animation_state->unk0->unk24 == 0.0f) {
                func_global_asm_8072DE44(0x1FB);
            }
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4300, 0.0f);
            break;
        case 0x32:
            gCurrentActorPointer->y_rotation = func_global_asm_806CC190(gCurrentActorPointer->y_rotation, gCurrentActorPointer->unkEE, 7.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4300, 0.0f);
                    break;
                case 1:
                    gCurrentActorPointer->y_velocity = 200.0f;
                    gCurrentActorPointer->unkB8 = 120.0f;
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 3:
                    func_global_asm_8072DE44(0x1FB);
                    break;
            }
            break;
        case 0x11:
            func_global_asm_80724E48(5);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, 0x1FD);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 1:
                    func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    if (gCurrentActorPointer->unkB8 < 1.0f) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2:
                    func_global_asm_8072A450();
                    if (RandChance(0.005)) {
                        func_global_asm_8072DE44(0x1FB);
                    }
                    break;
            }
            break;
        case 0x27:
            func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, 0x1FE);
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 2:
                    gCurrentActorPointer->unk132 = 2;
                    break;
                case 3:
                    gCurrentActorPointer->unk132 = 1;
                    break;
                case 4:
                    func_global_asm_8072DE44(0x1FB);
                    break;
            }
            break;
        case 0x1:
            if (func_global_asm_8072E54C()) {
                gCurrentActorPointer->control_state = 0x11;
                gCurrentActorPointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x23:
            if (D_global_asm_807FBB70.unk200 == 2) {
                if (func_global_asm_8072DE10(10000)) {
                    gCurrentActorPointer->control_state = 0x27;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
            // fallthrough
        case 0x10:
            func_global_asm_80724E48(gCurrentActorPointer->control_state == 1 ? 2 : 0);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_80724E48(gCurrentActorPointer->control_state == 0x35 ? 2 : 3);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            break;
        case 0x37:
            gCurrentActorPointer->y_rotation = func_global_asm_806CC190(gCurrentActorPointer->y_rotation, gCurrentActorPointer->unkEE, 7.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0, 0, 0x200, 0);
                    break;
                case 1:
                    if (current_map == MAP_KROOL_BARREL_DIDDY_KREMLING_GAME) {
                        if (gCurrentActorPointer->unk15F != 0) {
                            func_global_asm_8063DA40(0, 0xA);
                        }
                    }
                    func_global_asm_806A5C60(gCurrentActorPointer);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072AB74(0x37, 0, 0, 0x200, 0);
                    func_global_asm_8072DC7C(8);
                    break;
                case 3:
                    gCurrentActorPointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x1FB);
            break;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x31:
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(gCurrentActorPointer->control_state, 1);
            // fallthrough
        default:
            func_global_asm_8072C918(0x6400, 0x1FB, 0x1FC);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

void func_global_asm_806AEE08(void) {
    if ((RandChance(0.02))
        && func_global_asm_8072DE10(4000)
        && !(D_global_asm_807FDC90->unk1A & 0x80)) {
        gCurrentActorPointer->control_state = 0x25;
        gCurrentActorPointer->control_state_progress = 0;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AEE84.s")

// Kop
void func_global_asm_806AF688(void) {
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0x2C0, 0x2C1, 0x2C1);
        func_global_asm_80724CA4(0xE, 1);
        D_global_asm_807FDC90->unk1A |= 0x800;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    }
    func_global_asm_806AE394(40.0f, 70.0f);
    if ((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) {
        gCurrentActorPointer->control_state = 0x3A;
        gCurrentActorPointer->control_state_progress = 0;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x11:
            func_global_asm_80724E48(2);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, 0x2C0);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 1:
                    func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    if (gCurrentActorPointer->unkB8 < 1.0f) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2:
                    func_global_asm_8072A450();
                    if (RandChance(0.005)) {
                        func_global_asm_8072DE44(0x1FB);
                    }
                    break;
            }
            break;
        case 0x1:
            if (func_global_asm_8072E54C() != 0) {
                gCurrentActorPointer->control_state = 0x11;
                gCurrentActorPointer->control_state_progress = 0;
            }
            func_global_asm_80724E48(gCurrentActorPointer->control_state == 1 ? 2 : 0);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_80724E48(gCurrentActorPointer->control_state == 0x35 ? 2 : 3);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            break;
        case 0x37:
            gCurrentActorPointer->control_state = 0x40;
            break;
        default:
            func_global_asm_8072B7CC(0x2C0);
            break;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x31:
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(gCurrentActorPointer->control_state, 1);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

int func_global_asm_8071910C(); // TODO: Signature

void func_global_asm_806AFA60(u8 arg0) {
    f32 temp_f22;
    f64 temp_f20;
    s16 i;

    for (i = 0; i < 7; i++) {
        temp_f22 = gCurrentActorPointer->animation_state->scale_y / 0.15;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(0);
        func_global_asm_80714C08(&D_global_asm_8072073C, temp_f22 * 0.15, gCurrentActorPointer, arg0, 0);
    }
}

// Jumptable, close, regalloc
// https://decomp.me/scratch/Z6JAV
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806AFB58.s")

/*
void func_global_asm_806AFB58(void) {
    s32 cs;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk146_s16 = -1;
        func_global_asm_8072B79C(0x2D9, 0x2D7, 0x2D8);
        func_global_asm_80724CA4(2, 1);
        gCurrentActorPointer->unkEC = 0x1770;
    }
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (gCurrentActorPointer->control_state != 0x37)) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x2DD);
        D_global_asm_807FDC90->unk35 = 2;
        gCurrentActorPointer->unk138 &= ~0x8000;
    } else if ((D_global_asm_807FBB70.unk200 == 4) || (D_global_asm_807FBB70.unk200 == 5)) {
        if (gCurrentActorPointer->unk146_s16 & 1) {
            D_global_asm_807FDC90->unk1E = 0xF;
            D_global_asm_807FDC90->unk1F = 0xF;
            gCurrentActorPointer->unkEC = -1;
            func_global_asm_806AE2B0(0xC2, 0x800, 1, 0x190);
            gLastSpawnedActor->unk15F = 1;
            func_global_asm_806AFA60(1);
        } else if (gCurrentActorPointer->unk146_s16 & 2) {
            func_global_asm_806AFA60(2);
        }
        gCurrentActorPointer->unk146_s16 *= 2;
        func_global_asm_8072DEA8(0x2DC, 0x31, D_global_asm_807FBB70.unk1FC);
        D_global_asm_807FDC90->unk26 = 0;
        gCurrentActorPointer->unkB8 = 0.0f;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x31:
            if ((gCurrentActorPointer->control_state_progress != 0) || (gCurrentActorPointer->animation_state->unk0->unk24 == 0.0f)) {
                func_global_asm_8072DE44(0x2D7);
            }
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4200, 0.0f);
            cs = gCurrentActorPointer->control_state;
            break;
        case 0x11:
            func_global_asm_80724E48(5);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, 0x2D9);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 1:
                    func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    if (gCurrentActorPointer->unkB8 < 1.0f) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2:
                    func_global_asm_8072A450();
                    if (RandChance(0.005)) {
                        func_global_asm_8072DE44(0x2D7);
                    }
                    break;
            }
            cs = gCurrentActorPointer->control_state;
            break;
        case 0x27:
            if (gCurrentActorPointer->unkEC < 0xFFFF) {
                func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
            }
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    if ((gCurrentActorPointer->animation_state->scale[1] > 0.18) && (RandChance(0.5))) {
                        playActorAnimation(gCurrentActorPointer, 0x2DB);
                    } else {
                        playActorAnimation(gCurrentActorPointer, 0x2DA);
                    }
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 2:
                    gCurrentActorPointer->unk132 = 2;
                    break;
                case 3:
                    gCurrentActorPointer->unk132 = 1;
                    break;
                case 4:
                    func_global_asm_8072DE44(0x2D7);
                    break;
            }
            cs = gCurrentActorPointer->control_state;
            break;
        case 0x1:
            if (func_global_asm_8072E54C() != 0) {
                gCurrentActorPointer->control_state = 0x11;
                gCurrentActorPointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x23:
            if ((D_global_asm_807FBB70.unk200 == 2) && (func_global_asm_8072DE10(gCurrentActorPointer->unkEC) != 0)) {
                gCurrentActorPointer->control_state = 0x27;
                gCurrentActorPointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x10:
            func_global_asm_80724E48(gCurrentActorPointer->control_state == 1 ? 2 : 0);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            cs = gCurrentActorPointer->control_state;
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_80724E48(gCurrentActorPointer->control_state == 0x35 ? 2 : 3);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            cs = gCurrentActorPointer->control_state;
            break;
        case 0x37:
            gCurrentActorPointer->y_rotation = func_global_asm_806CC190(gCurrentActorPointer->y_rotation, gCurrentActorPointer->unkEE, 7.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x202, 0.0f);
                    break;
                case 1:
                    func_global_asm_806A5C60(gCurrentActorPointer);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072DC7C(8);
                    break;
                case 3:
                    gCurrentActorPointer->control_state = 0x40;
                    break;
            }
            cs = gCurrentActorPointer->control_state;
            break;
        default:
            func_global_asm_8072B7CC(0x2D7);
            cs = gCurrentActorPointer->control_state;
            break;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x31:
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(1, cs);
            // fallthrough
        default:
            func_global_asm_8072C918(0x6400, 0x2D7, 0x2D8);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

void func_global_asm_806B02EC(void) {
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0, 0x31E, 0x31F);
    }
    func_global_asm_806AD260(800, 0, 0);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806B0354(void) {
    initializeCharacterSpawnerActor();
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (gCurrentActorPointer->control_state != 0x37)) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x37A);
        gCurrentActorPointer->unk138 &= 0xFFFF7FFF;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x4:
            if (gCurrentActorPointer->animation_state->unk64 == 0x378) {
                gCurrentActorPointer->control_state = 0x23;
                gCurrentActorPointer->control_state_progress = 0;
            } else if ((func_global_asm_8072E22C(0x64) != 0) && (func_global_asm_80726164(gCurrentActorPointer, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0) != 0)) {
                playActorAnimation(gCurrentActorPointer, 0x37B);
                gCurrentActorPointer->control_state = 0x23;
                gCurrentActorPointer->control_state_progress = 0;
                func_global_asm_806852C4(0.7f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 10.0f, gCurrentActorPointer->z_position);
            }
            break;
        case 0x23:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, D_global_asm_807FDC9C->unkD);
                    gCurrentActorPointer->control_state_progress++;
                    // Fallthrough
                case 1:
                    if (RandChance(0.005)) {
                        gCurrentActorPointer->control_state_progress++;
                        playActorAnimation(gCurrentActorPointer, 0x379);
                        func_global_asm_8072B324(gCurrentActorPointer, 0);
                    } else {
                        if (gCurrentActorPointer->animation_state->unk64 == 0x378) {
                            func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
                        } else {
                            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
                        }
                        if ((func_global_asm_8072E22C(0xC8) == 0) || (func_global_asm_80726164(gCurrentActorPointer, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0) == 0)) {
                            playActorAnimation(gCurrentActorPointer, 0x37C);
                            gCurrentActorPointer->control_state = 4;
                            gCurrentActorPointer->control_state_progress = 0;
                            func_global_asm_8072B324(gCurrentActorPointer, 0);
                        }
                    }
                    break;
                case 2:
                    func_global_asm_8072AB74(0, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                    break;
            }
            break;
        case 0x37:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x200, 0.0f);
                    break;
                case 1:
                    func_global_asm_806A5C60(gCurrentActorPointer);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072DC7C(0xA);
                    break;
                case 3:
                    gCurrentActorPointer->control_state = 0x40;
                    break;
            }
            break;
        default:
            func_global_asm_8072B7CC(0x378);
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(gCurrentActorPointer, 0);
}

s32 func_global_asm_806B0770(void) {
    f32 dx, dy, dz;
    Actor *temp_a0;
    s16 i;
    s32 found;
    
    found = FALSE;

    for (i = 0; !found && i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (temp_a0->unk58 == ACTOR_PROJECTILE_ORANGE) {
            dx = temp_a0->x_position - gCurrentActorPointer->x_position;
            dy = temp_a0->y_position - gCurrentActorPointer->y_position;
            dz = temp_a0->z_position - gCurrentActorPointer->z_position;
            if ((SQ(dx) + SQ(dy) + SQ(dz)) < SQ(100.0f)) {
                gCurrentActorPointer->control_state = 0x28;
                gCurrentActorPointer->control_state_progress = 0;
                found = TRUE;
            }
        }
    }  
    return found;
}

// Jumptable, very close, needs actor->unk0 shape
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B2CE0/func_global_asm_806B0848.s")

/*
void func_global_asm_806B0848(void) {
    s32 var_a1;
    Actor *var_s0;
    f64 temp_f0;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_a1_3;
    u8 temp_v1;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk130 = MIN(255, (gCurrentActorPointer->animation_state->scale_y / 0.15) * 100.0);
        gCurrentActorPointer->unk131 = MIN(255, (gCurrentActorPointer->animation_state->scale_y / 0.15) * 100.0);
        func_global_asm_8072B79C(0x35E, 0x35F, 0x360);
    }
    if (D_global_asm_807FBB70.unk200 != 9) {
        if (D_global_asm_807FBB70.unk15 != 0) {
            goto block_10;
        }
        goto block_12;
    }
block_10:
    if (gCurrentActorPointer->control_state != 0x37) {
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x367);
        gCurrentActorPointer->unk138 &= 0xFFFF7FFF;
    } else {
block_12:
        if (D_global_asm_807FBB70.unk200 == 4) {
            func_global_asm_8072DEA8(0x365, 0x31, D_global_asm_807FBB70.unk1FC);
        } else if (D_global_asm_807FBB70.unk200 == 5) {
            func_global_asm_8072DEA8(0x366, 0x31, D_global_asm_807FBB70.unk1FC);
        }
    }
    if (gCurrentActorPointer->control_state == 4) {
        gCurrentActorPointer->control_state = 1;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x37:
            gCurrentActorPointer->y_rotation = func_global_asm_806CC190(gCurrentActorPointer->y_rotation, gCurrentActorPointer->unkEE, 7.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x202, 0.0f);
                    break;
                case 1:
                    func_global_asm_806A5C60(gCurrentActorPointer);
                    gCurrentActorPointer->control_state_progress++;
                    // fallthrough
                case 2:
                    func_global_asm_8072DC7C(8);
                    break;
                case 3:
                    gCurrentActorPointer->control_state = 0x40;
                    break;
            }
            break;
        case 0x31:
            if (gCurrentActorPointer->unk0 == 0) {
                // if (gCurrentActorPointer->unk0->unk24 == 0.0f) {
                    // goto block_31;
                // }
            } else {
block_31:
                func_global_asm_8072DE44(0x35F);
            }
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 0x4200, 0.0f);
            break;
        case 0x27:
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, (object_timer & 1) ? 0x362 : 0x361);
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 2:
                    if (gCurrentActorPointer->animation_state->unk64 != 0x362) {
                        gCurrentActorPointer->unk132 = 2;
                    } else {
                        gCurrentActorPointer->unk132 = 4;
                    }
                    break;
                case 3:
                    if (gCurrentActorPointer->animation_state->unk64 != 0x362) {
                        gCurrentActorPointer->unk132 = 1;
                    } else {
                        gCurrentActorPointer->unk132 = 8;
                    }
                    break;
                case 4:
                    gCurrentActorPointer->unk132 = 1;
                    func_global_asm_8072DE44(0x35F);
                    break;
            }
            break;
        case 0x28:
            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    playActorAnimation(gCurrentActorPointer, 0x363);
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 2:
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 4:
                    D_global_asm_807FDC90->unk4 = gPlayerPointer;
                    func_global_asm_8072DE44(0x35F);
                    break;
            }
            break;
        case 0x11:
            if (func_global_asm_806B0770() == 0) {
                switch (gCurrentActorPointer->control_state_progress) {
                    case 0:
                        func_global_asm_8072B324(gCurrentActorPointer, 0);
                        playActorAnimation(gCurrentActorPointer, 0x35E);
                        gCurrentActorPointer->control_state_progress++;
                        // fallthrough
                    case 1:
                        func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200, 0.0f);
                        if (gCurrentActorPointer->unkB8 < 1.0f) {
                            gCurrentActorPointer->control_state_progress++;
                        }
                        break;
                    case 2:
                        func_global_asm_8072A450();
                        if (RandChance(0.005)) {
                            func_global_asm_8072DE44(0x35F);
                        }
                        break;
                }
            }
            break;
        case 0x1:
            if (func_global_asm_8072E54C() != 0) {
                gCurrentActorPointer->control_state = 0x11;
                gCurrentActorPointer->control_state_progress = 0;
            }
            // fallthrough
        case 0x23:
            if (func_global_asm_8072E22C(0x50) != 0) {
                if (func_global_asm_8072DE10(0x1770) != 0) {
                    gCurrentActorPointer->control_state = 0x27;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
            // fallthrough
        case 0x10:
            func_global_asm_806B0770();
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
            break;
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            break;
        default:
            func_global_asm_8072B7CC(0x2D7);
            break;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x31:
        case 0x37:
        case 0x40:
            break;
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(gCurrentActorPointer->control_state, 1);
            // fallthrough
        default:
            func_global_asm_8072C918(0x6400, 0x35F, 0x360);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
*/
