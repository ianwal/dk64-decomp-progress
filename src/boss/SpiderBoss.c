#include "common.h"

extern u8 D_global_asm_807FBB85;
extern u8 D_global_asm_807FBD70;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} A178_8002C964;

void func_boss_8002C520(s16 arg0, s16 arg1, s16 arg2) {
    func_global_asm_807271F4(
        arg0,
        gCurrentActorPointer->x_position + (func_global_asm_80612794(arg2) * arg1),
        D_global_asm_807FDC9C->unk6,
        gCurrentActorPointer->z_position + (func_global_asm_80612790(arg2) * arg1),
        0,
        0,
        0
    );
    gLastSpawnedActor->terminal_velocity *= 2;
    gLastSpawnedActor->draw_distance = 2000;
}

void func_boss_8002C5F4(void) {
    func_boss_8002C520(2, RandClamp(100) + 300, (rand() >> 0xF) % 4096);
    func_boss_8002C520(3, RandClamp(100) + 300, (rand() >> 0xF) % 4096);
    func_boss_8002C520(4, RandClamp(100) + 300, (rand() >> 0xF) % 4096);
    if (!(D_global_asm_807FDC90->unk1A & 0x8000)) {
        D_global_asm_807FDC90->unk1A |= 0x8000;
        playCutscene(gLastSpawnedActor, 2, 1);
    }
}

void func_boss_8002C748(u8 arg0) {
    D_global_asm_807FDC90->unk28 = 2;
    func_global_asm_8068842C(gCurrentActorPointer, arg0, 1);
    func_global_asm_80688460(gCurrentActorPointer, arg0, 1);
    func_global_asm_806883F4(gCurrentActorPointer, arg0, D_global_asm_807FDC90->unk28 & 0xF, 0);
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
    func_global_asm_806883F4(gCurrentActorPointer, 0, sp20, 0);
    func_global_asm_806883F4(gCurrentActorPointer, 1, sp20, 0);
    D_global_asm_807FDC90->unk28 = sp26 | sp20 | sp25;
}

void func_boss_8002C8B4(void) {
    func_global_asm_80690814(gCurrentActorPointer, 1);
    func_global_asm_80690A28(
        0x116, 
        (RandClamp(3) + 1), 
        1.0f, 
        D_global_asm_807FDC94->x_position, 
        D_global_asm_807FDC94->y_position + D_global_asm_807FDC94->unk15E, 
        D_global_asm_807FDC94->z_position, 
        300.0f, 
        gCurrentActorPointer
    );
}

void func_boss_8002C964(void) {
    A178_8002C964 *a178;
    f64 yScale;

    a178 = gCurrentActorPointer->unk178;
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_boss_8002C748(0);
        func_boss_8002C748(1);
        D_global_asm_807FDC98->unk30 = 2.5f;
        D_global_asm_807FDC98->unk46 &= 0xFFF7;
        D_global_asm_807FDC98->unk46 |= 0x200;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        gCurrentActorPointer->unk132 = 4;
        gCurrentActorPointer->control_state = 0x1E;
        func_global_asm_807248B0(gCurrentActorPointer, 2.0 * gCurrentActorPointer->animation_state->scale[0]);
        func_global_asm_806AD9AC();
    }
    if (((D_global_asm_807FBD70 == 9) || (D_global_asm_807FBB85 != 0)) && (gCurrentActorPointer->control_state != 0x37)) {
        if (isFlagSet(PERMFLAG_ITEM_GB_FUNGI_SPIDER_BOSS, FLAG_TYPE_PERMANENT)) {
            func_global_asm_8067E278(0, 1);
            gCurrentActorPointer->control_state = 0x40;
        } else {
            playCutscene(gCurrentActorPointer, 6, 1);
            gCurrentActorPointer->y_velocity = 200.0f;
            func_global_asm_8072D714(D_global_asm_807FBD6C, 0x2F7);
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x28:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    playCutscene(gCurrentActorPointer, 8, 1);
                    playActorAnimation(gCurrentActorPointer, 0);
                    func_global_asm_80613C48(gCurrentActorPointer, 0x589, 0.0f, 0.0f);
                    D_global_asm_807FDC90->unk2C = 0;
                    gCurrentActorPointer->control_state_progress = 1;
                    gCurrentActorPointer->noclip_byte = 1;
                    playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x2FC, 0xFF, 0x7F, 0, 0, 0.0f, 0);
                    // fallthrough
                case 1:
                    D_global_asm_807FDC90->unk2C += 8;
                    if (D_global_asm_807FDC90->unk2C >= 0x259) {
                        gCurrentActorPointer->control_state_progress = 2;
                    }
                    gCurrentActorPointer->y_position += 2.0f;
                    gCurrentActorPointer->y_rotation += D_global_asm_807FDC90->unk2C;
                    yScale = gCurrentActorPointer->animation_state->scale[1];
                    func_global_asm_807248B0(gCurrentActorPointer, ((0.3 - yScale) * 0.05) + yScale);
                    break;
                case 2:
                    D_global_asm_807FDC90->unk2C -= 0x14;
                    if (D_global_asm_807FDC90->unk2C < 0) {
                        D_global_asm_807FDC90->unk2C = 0;
                    }
                    gCurrentActorPointer->y_rotation += D_global_asm_807FDC90->unk2C;
                    if (func_global_asm_80629148()) {
                        gCurrentActorPointer->control_state_progress = 3;
                        gCurrentActorPointer->object_properties_bitfield &= ~4;
                    }
                    break;
                case 3:
                    if (func_global_asm_80629148()) {
                        gCurrentActorPointer->unk15E = 0xA;
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        gCurrentActorPointer->unk132 = 1;
                        gCurrentActorPointer->control_state = 0x23;
                        func_global_asm_8072B324(gCurrentActorPointer, D_global_asm_807FDC9C->unkD);
                        gCurrentActorPointer->noclip_byte = 0x24;
                        playActorAnimation(gCurrentActorPointer, 0x2F4);
                    }
                    break;
            }
            break;
        case 0x1E:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if (func_global_asm_80629148()) {
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        gCurrentActorPointer->control_state_progress = 1;
                    }
                    break;
                case 2:
                    if ((gCurrentActorPointer->y_position - gCurrentActorPointer->floor) > 300.0f) {
                        gCurrentActorPointer->y_position -= 10.0f;
                    } else {
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        gCurrentActorPointer->control_state_progress = 3;
                    }
                    break;
                case 3:
                    if (func_global_asm_80629148()) {
                        gCurrentActorPointer->control_state = 0x27;
                        gCurrentActorPointer->control_state_progress = 0;
                        func_global_asm_80626110(D_global_asm_807F5D10, 0, 0);
                    }
                    break;
            }
            break;
        case 0x27:
            gCurrentActorPointer->y_rotation = func_global_asm_806CC190(gCurrentActorPointer->y_rotation, func_global_asm_80665DE0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position), 8.0f);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_boss_8002C5F4();
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 1:
                    if ((func_global_asm_80726D7C(2) == 0) && (func_global_asm_80726D7C(3) == 0) && (func_global_asm_80726D7C(4) == 0)) {
                        gCurrentActorPointer->control_state_progress = 2;
                        D_global_asm_807FDC90->unk2C = 0x96;
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        gCurrentActorPointer->unk132 = 8;
                        playActorAnimation(gCurrentActorPointer, 0x2FA);
                    }
                    if ((func_global_asm_8061CB50() == 0) && (RandChance(0.005))) {
                        playActorAnimation(gCurrentActorPointer, 0x2FD);
                        gCurrentActorPointer->control_state_progress = 3;
                    }
                    break;
                case 2:
                    if ((D_global_asm_807FDC90->unk2C != 0) && (D_global_asm_807FBD70 != 4)) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        if (D_global_asm_807FBD70 == 4) {
                            playActorAnimation(gCurrentActorPointer, 0x2FC);
                            func_global_asm_8072D9D4();
                            a178->unk2 = 0x96;
                            a178->unk4 = 0x800;
                            gCurrentActorPointer->unkEE = gCurrentActorPointer->y_rotation;
                            if (gCurrentActorPointer->health == 1) {
                                gCurrentActorPointer->control_state = 0x28;
                                gCurrentActorPointer->control_state_progress = 0;
                            }
                        }
                        gCurrentActorPointer->unk132 = 4;
                        D_global_asm_807FDC90->unk28 |= 0x8000;
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                    break;
                case 4:
                    gCurrentActorPointer->control_state_progress = 1;
                    func_boss_8002C8B4();
                    break;
            }
            break;
        case 0x23:
            func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0);
            break;
        case 0x37:
            func_global_asm_806AD260(0x2F7, 1, 0);
            break;
    }
    if (a178->unk2 > 0) {
        a178->unk0 = a178->unk2 * func_global_asm_80612794(a178->unk4);
        a178->unk4 += 0x32;
        a178->unk2--;
        gCurrentActorPointer->z_rotation = -a178->unk0;
        gCurrentActorPointer->x_position = (func_global_asm_80612794(gCurrentActorPointer->unkEE) * a178->unk0) + D_global_asm_807FDC9C->unk4;
        gCurrentActorPointer->z_position = (func_global_asm_80612790(gCurrentActorPointer->unkEE) * a178->unk0) + D_global_asm_807FDC9C->unk8;
        gCurrentActorPointer->y_position = D_global_asm_807FDC9C->unk6 - sqrtf(0x1C390 - SQ(a178->unk0));
    }
    if (D_global_asm_807FDC90->unk28 & 0x8000) {
        func_boss_8002C7CC();
    }
    renderActor(gCurrentActorPointer, 0);
}
