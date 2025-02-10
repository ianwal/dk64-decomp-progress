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
    a178 = current_actor_pointer->unk178;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        comparisonActor = D_global_asm_807FB930[i].unk0;
        if ((comparisonActor->unk58 == ACTOR_SPOTLIGHT_FISH) || (comparisonActor->unk58 == ACTOR_SPOTLIGHT_SQUAWKS)) {
            d = ((comparisonActor->x_position - player_pointer->x_position) * (comparisonActor->x_position - player_pointer->x_position))
                + ((comparisonActor->y_position - player_pointer->y_position) * (comparisonActor->y_position - player_pointer->y_position))
                + ((comparisonActor->z_position - player_pointer->z_position) * (comparisonActor->z_position - player_pointer->z_position));
            if (d < closestDistance) {
                closestDistance = d;
                closestActor = comparisonActor;
            }
        }
    }
    if (closestActor != current_actor_pointer) {
        current_actor_pointer->control_state = 0x40;
        return;
    }
    switch (current_actor_pointer->unk58) {
        case ACTOR_SPOTLIGHT_FISH:
            if (current_actor_pointer->object_properties_bitfield & 0x100) {
                getBonePosition(current_actor_pointer, 1, &x1, &y1, &z1);
            } else {
                x1 = current_actor_pointer->x_position;
                y1 = current_actor_pointer->y_position;
                z1 = current_actor_pointer->z_position;
            }
            if ((40000.0f < (((current_actor_pointer->x_position - player_pointer->x_position) * (current_actor_pointer->x_position - player_pointer->x_position))
                + ((current_actor_pointer->y_position - player_pointer->y_position) * (current_actor_pointer->y_position - player_pointer->y_position))
                + ((current_actor_pointer->z_position - player_pointer->z_position) * (current_actor_pointer->z_position - player_pointer->z_position)))) && (current_actor_pointer->object_properties_bitfield & 0x100)) {
                getBonePosition(current_actor_pointer, 2, &x2, &y2, &z2);
            } else {
                x2 = player_pointer->x_position;
                y2 = player_pointer->y_position;
                z2 = player_pointer->z_position;
            }
            func_global_asm_8065A660(30.0f, 80.0f);
            break;
        case ACTOR_SPOTLIGHT_SQUAWKS:
            x1 = current_actor_pointer->x_position;
            y1 = current_actor_pointer->y_position;
            z1 = current_actor_pointer->z_position;
            x2 = (func_global_asm_80612794(current_actor_pointer->y_rotation) * 40.0f) + current_actor_pointer->x_position;
            y2 = current_actor_pointer->y_position - 20.0f;
            z2 = (func_global_asm_80612790(current_actor_pointer->y_rotation) * 40.0f) + current_actor_pointer->z_position;
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
    dx = current_actor_pointer->x_position - D_global_asm_807FDC94->x_position;
    dz = current_actor_pointer->z_position - D_global_asm_807FDC94->z_position;
    d = sqrtf(SQ(dx) + SQ(dz));
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        a178 = current_actor_pointer->unk178;
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        a178->unk2 = 0;
        a178->unk0 = 0xFF;
        D_global_asm_807FDC98->unk3C = 1.0f;
        if (current_actor_pointer->unk58 == ACTOR_SPOTLIGHT_FISH) {
            func_global_asm_80604CBC(current_actor_pointer, 0x132, 0, 0, 0, 0xA0, 1.0f, 0);
        }
    }
    if (d - arg1 < 0) {
        d = 0;
    } else  {
        d = d - arg1;
    }
    func_global_asm_8072B324(current_actor_pointer, (2.0 * d));
    func_global_asm_8072A920(0x23, arg0, D_global_asm_807FDC94->x_position, (D_global_asm_807FDC94->y_position + (arg0 * 3.0)), D_global_asm_807FDC94->z_position, 0x1E, 3.3f, 100.0f, arg2 | 0x2000);
    current_actor_pointer->y_position += 0.5 * func_global_asm_80612794(object_timer * 40);
    func_global_asm_806C6530();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C6B50(void) {
    current_actor_pointer->unkAC = 99999.0f;
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
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 0x7D0;
        current_actor_pointer->unk130 = 0xFF;
        current_actor_pointer->unk131 = 0xFF;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
        D_global_asm_807FDC90->unk30 = current_actor_pointer->animation_state->scale[1];
        D_global_asm_807FDC90->unk2E = 0x96;
        D_global_asm_807FDC98->unk46 |= 0x60;
        func_global_asm_806A2A10(0xDC, 0x2A, 0x64, &D_global_asm_807FDC90);
        func_global_asm_806A2B08(last_spawned_actor);
    }
    if (D_global_asm_807FDC90->unk1A & 0x80) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FDC90->unk2C != 0) {
                sp54 = ((f32)D_global_asm_807FDC90->unk2C / D_global_asm_807FDC90->unk2E);
                getBonePosition(current_actor_pointer, 2, &x, &y, &z);
                func_global_asm_807248B0(player_pointer, (sp54 * 0.13) + 0.02);
                player_pointer->x_position += (x - player_pointer->x_position) * 0.05;
                player_pointer->y_position += (y - player_pointer->y_position) * 0.05;
                player_pointer->z_position += (z - player_pointer->z_position) * 0.05;
                D_global_asm_807FDC90->unk2C--;
                if (D_global_asm_807FDC90->unk2C == 0) {
                    func_global_asm_805FF9AC(0x33, 0, 0, 1);
                }
            }
            break;
        case 39:
            if (D_global_asm_807FDC90->unk2E != 0) {
                current_actor_pointer->y_position += 2.0f;
                D_global_asm_807FDC90->unk2E--;
                func_global_asm_807248B0(
                    current_actor_pointer,
                    D_global_asm_807FDC90->unk30 + ((0.01 - D_global_asm_807FDC90->unk30) * ((f64)D_global_asm_807FDC90->unk2E / 150.0))
                );
            } else {
                current_actor_pointer->control_state = 2;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 2:
            if (D_global_asm_807FBD70 == 4) {
                playActorAnimation(current_actor_pointer, 0);
                func_global_asm_80614D00(current_actor_pointer, 0.0f, 0.0f);
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_8061CC30();
                D_global_asm_807FDC90->unk2C = playCutscene(current_actor_pointer, 0x18, 1) - 0x1E;
                D_global_asm_807FDC90->unk2E = D_global_asm_807FDC90->unk2C;
                current_actor_pointer->noclip_byte = 1;
            } else {
                switch (current_actor_pointer->control_state_progress) {
                    case 5:
                        func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
                        current_actor_pointer->control_state_progress = 0;
                        break;
                    case 3:
                        func_global_asm_8072B324(current_actor_pointer, 0);
                        playActorAnimation(current_actor_pointer, 0x2BB);
                        current_actor_pointer->control_state_progress = 4;
                        // fallthrough
                    case 0:
                    case 4:
                        func_global_asm_80685020(3, 1);
                        if ((current_actor_pointer->control_state_progress == 0) && (RandChance(0.01))) {
                            current_actor_pointer->control_state_progress = 3;
                        }
                        if ((current_actor_pointer->unk11C->control_state == 5) || (player_pointer->unk58 != ACTOR_DIDDY)) {
                            playActorAnimation(current_actor_pointer, 0x2BA);
                            func_global_asm_80614D00(current_actor_pointer, 0.0f, 0.0f);
                            func_global_asm_8063DA40(0x33, 0);
                            deleteActor(current_actor_pointer->unk11C);
                            current_actor_pointer->control_state_progress = 1;
                        }
                        func_global_asm_8072A920(2, 0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkC, D_global_asm_807FDC90->unkE, 0x46, 30.0f, 100.0f, 0x200);
                        func_global_asm_8072D13C(2, 0);
                        break;
                    case 1:
                        func_global_asm_8072DC7C(5);
                        break;
                    case 2:
                        current_actor_pointer->control_state = 0x3B;
                        break;
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
