#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 unk0;
} A178_global_asm_806C6530;

void func_global_asm_806C6530(void);

typedef struct {
    s16 unk0;
    u8 unk2;
} A178_806C6884;

extern u8 D_global_asm_807FBD70;

void func_global_asm_806C6530(void) {
    A178_global_asm_806C6530 *a178;
    Actor *comparisonActor;
    Actor *closestActor;
    s32 pad;
    s16 i;
    f32 z2, y2, x2;
    f32 z1, y1, x1;
    s32 d;
    s32 closestDistance;

    closestActor = NULL;
    closestDistance = 999999;
    a178 = gCurrentActorPointer->unk178;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        comparisonActor = D_global_asm_807FB930[i].unk0;
        if ((comparisonActor->unk58 == ACTOR_SPOTLIGHT_FISH) || (comparisonActor->unk58 == ACTOR_SPOTLIGHT_SQUAWKS)) {
            d = ((comparisonActor->x_position - gPlayerPointer->x_position) * (comparisonActor->x_position - gPlayerPointer->x_position))
                + ((comparisonActor->y_position - gPlayerPointer->y_position) * (comparisonActor->y_position - gPlayerPointer->y_position))
                + ((comparisonActor->z_position - gPlayerPointer->z_position) * (comparisonActor->z_position - gPlayerPointer->z_position));
            if (d < closestDistance) {
                closestDistance = d;
                closestActor = comparisonActor;
            }
        }
    }
    if (closestActor != gCurrentActorPointer) {
        gCurrentActorPointer->control_state = 0x40;
        return;
    }
    switch (gCurrentActorPointer->unk58) {
        case ACTOR_SPOTLIGHT_FISH:
            if (gCurrentActorPointer->object_properties_bitfield & 0x100) {
                getBonePosition(gCurrentActorPointer, 1, &x1, &y1, &z1);
            } else {
                x1 = gCurrentActorPointer->x_position;
                y1 = gCurrentActorPointer->y_position;
                z1 = gCurrentActorPointer->z_position;
            }
            if ((40000.0f < (((gCurrentActorPointer->x_position - gPlayerPointer->x_position) * (gCurrentActorPointer->x_position - gPlayerPointer->x_position))
                + ((gCurrentActorPointer->y_position - gPlayerPointer->y_position) * (gCurrentActorPointer->y_position - gPlayerPointer->y_position))
                + ((gCurrentActorPointer->z_position - gPlayerPointer->z_position) * (gCurrentActorPointer->z_position - gPlayerPointer->z_position)))) && (gCurrentActorPointer->object_properties_bitfield & 0x100)) {
                getBonePosition(gCurrentActorPointer, 2, &x2, &y2, &z2);
            } else {
                x2 = gPlayerPointer->x_position;
                y2 = gPlayerPointer->y_position;
                z2 = gPlayerPointer->z_position;
            }
            func_global_asm_8065A660(30.0f, 80.0f);
            break;
        case ACTOR_SPOTLIGHT_SQUAWKS:
            x1 = gCurrentActorPointer->x_position;
            y1 = gCurrentActorPointer->y_position;
            z1 = gCurrentActorPointer->z_position;
            x2 = (func_global_asm_80612794(gCurrentActorPointer->y_rotation) * 40.0f) + gCurrentActorPointer->x_position;
            y2 = gCurrentActorPointer->y_position - 20.0f;
            z2 = (func_global_asm_80612790(gCurrentActorPointer->y_rotation) * 40.0f) + gCurrentActorPointer->z_position;
            func_global_asm_8065A660(20.0f, 40.0f);
            break;
    }
    a178->unk0 = (func_global_asm_80612794(object_timer * 0x82) * 35.0) + 220.0;
    createLight(x1, y1, z1, x2, y2, z2, 0.0f, 1, a178->unk0, a178->unk0, a178->unk0);
}

void func_global_asm_806C6884(s16 arg0, s16 arg1, u16 arg2) {
    u16 d;
    f32 dx, dz;
    A178_806C6884 *a178;

    initializeCharacterSpawnerActor();
    dx = gCurrentActorPointer->x_position - D_global_asm_807FDC94->x_position;
    dz = gCurrentActorPointer->z_position - D_global_asm_807FDC94->z_position;
    d = sqrtf(SQ(dx) + SQ(dz));
    if ((gCurrentActorPointer->object_properties_bitfield & 0x10) == 0) {
        a178 = gCurrentActorPointer->unk178;
        gCurrentActorPointer->unk64 |= 4;
        gCurrentActorPointer->object_properties_bitfield |= 0x800000;
        gCurrentActorPointer->unk16A = 0xFF;
        gCurrentActorPointer->unk16B = 0xFF;
        gCurrentActorPointer->unk16C = 0xFF;
        a178->unk2 = 0;
        a178->unk0 = 0xFF;
        D_global_asm_807FDC98->unk3C = 1.0f;
        if (gCurrentActorPointer->unk58 == ACTOR_SPOTLIGHT_FISH) {
            func_global_asm_80604CBC(gCurrentActorPointer, 0x132, 0, 0, 0, 0xA0, 1.0f, 0);
        }
    }
    if (d - arg1 < 0) {
        d = 0;
    } else  {
        d = d - arg1;
    }
    func_global_asm_8072B324(gCurrentActorPointer, (2.0 * d));
    func_global_asm_8072A920(0x23, arg0, D_global_asm_807FDC94->x_position, (D_global_asm_807FDC94->y_position + (arg0 * 3.0)), D_global_asm_807FDC94->z_position, 0x1E, 3.3f, 100.0f, arg2 | 0x2000);
    gCurrentActorPointer->y_position += 0.5 * func_global_asm_80612794(object_timer * 40);
    func_global_asm_806C6530();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C6B50(void) {
    gCurrentActorPointer->unkAC = 99999.0f;
    func_global_asm_806C6884(0, 0xA, 0x44);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}

void func_global_asm_806C6BA0(void) {
    func_global_asm_806C6884(0xA, 0x14, 0x240);
}

void func_global_asm_806C6BC8(void) {
    f32 sp54;
    f32 x, y, z;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->draw_distance = 0x7D0;
        gCurrentActorPointer->unk130 = 0xFF;
        gCurrentActorPointer->unk131 = 0xFF;
        gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
        gCurrentActorPointer->control_state = 0x27;
        gCurrentActorPointer->control_state_progress = 0;
        D_global_asm_807FDC90->unk30 = gCurrentActorPointer->animation_state->scale[1];
        D_global_asm_807FDC90->unk2E = 0x96;
        D_global_asm_807FDC98->unk46 |= 0x60;
        func_global_asm_806A2A10(0xDC, 0x2A, 0x64, &D_global_asm_807FDC90);
        func_global_asm_806A2B08(gLastSpawnedActor);
    }
    if (D_global_asm_807FDC90->unk1A & 0x80) {
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~0x400;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (D_global_asm_807FDC90->unk2C != 0) {
                sp54 = ((f32)D_global_asm_807FDC90->unk2C / D_global_asm_807FDC90->unk2E);
                getBonePosition(gCurrentActorPointer, 2, &x, &y, &z);
                func_global_asm_807248B0(gPlayerPointer, (sp54 * 0.13) + 0.02);
                gPlayerPointer->x_position += (x - gPlayerPointer->x_position) * 0.05;
                gPlayerPointer->y_position += (y - gPlayerPointer->y_position) * 0.05;
                gPlayerPointer->z_position += (z - gPlayerPointer->z_position) * 0.05;
                D_global_asm_807FDC90->unk2C--;
                if (D_global_asm_807FDC90->unk2C == 0) {
                    func_global_asm_805FF9AC(0x33, 0, 0, 1);
                }
            }
            break;
        case 39:
            if (D_global_asm_807FDC90->unk2E != 0) {
                gCurrentActorPointer->y_position += 2.0f;
                D_global_asm_807FDC90->unk2E--;
                func_global_asm_807248B0(
                    gCurrentActorPointer,
                    D_global_asm_807FDC90->unk30 + ((0.01 - D_global_asm_807FDC90->unk30) * ((f64)D_global_asm_807FDC90->unk2E / 150.0))
                );
            } else {
                gCurrentActorPointer->control_state = 2;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 2:
            if (D_global_asm_807FBD70 == 4) {
                playActorAnimation(gCurrentActorPointer, 0);
                func_global_asm_80614D00(gCurrentActorPointer, 0.0f, 0.0f);
                gCurrentActorPointer->control_state = 0;
                gCurrentActorPointer->control_state_progress = 0;
                func_global_asm_8061CC30();
                D_global_asm_807FDC90->unk2C = playCutscene(gCurrentActorPointer, 0x18, 1) - 0x1E;
                D_global_asm_807FDC90->unk2E = D_global_asm_807FDC90->unk2C;
                gCurrentActorPointer->noclip_byte = 1;
            } else {
                switch (gCurrentActorPointer->control_state_progress) {
                    case 5:
                        func_global_asm_8072B324(gCurrentActorPointer, D_global_asm_807FDC9C->unkC);
                        gCurrentActorPointer->control_state_progress = 0;
                        break;
                    case 3:
                        func_global_asm_8072B324(gCurrentActorPointer, 0);
                        playActorAnimation(gCurrentActorPointer, 0x2BB);
                        gCurrentActorPointer->control_state_progress = 4;
                        // fallthrough
                    case 0:
                    case 4:
                        func_global_asm_80685020(3, 1);
                        if ((gCurrentActorPointer->control_state_progress == 0) && (RandChance(0.01))) {
                            gCurrentActorPointer->control_state_progress = 3;
                        }
                        if ((gCurrentActorPointer->unk11C->control_state == 5) || (gPlayerPointer->unk58 != ACTOR_DIDDY)) {
                            playActorAnimation(gCurrentActorPointer, 0x2BA);
                            func_global_asm_80614D00(gCurrentActorPointer, 0.0f, 0.0f);
                            func_global_asm_8063DA40(0x33, 0);
                            deleteActor(gCurrentActorPointer->unk11C);
                            gCurrentActorPointer->control_state_progress = 1;
                        }
                        func_global_asm_8072A920(2, 0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkC, D_global_asm_807FDC90->unkE, 0x46, 30.0f, 100.0f, 0x200);
                        func_global_asm_8072D13C(2, 0);
                        break;
                    case 1:
                        func_global_asm_8072DC7C(5);
                        break;
                    case 2:
                        gCurrentActorPointer->control_state = 0x3B;
                        break;
                }
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
