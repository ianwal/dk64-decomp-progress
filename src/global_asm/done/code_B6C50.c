#include "common.h"

void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2);

void func_global_asm_806B1F50(void) {
    u8 brightness;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0xA0;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        gCurrentActorPointer->control_state = 0;
        gCurrentActorPointer->control_state_progress = 0;
        spawnActor(ACTOR_KLUMSY_CAGE, 0x7D);
        D_global_asm_807FDC90->unk4 = gLastSpawnedActor;
        moveAndScaleActorToAnother(gLastSpawnedActor, gCurrentActorPointer, 0.3f);
        gLastSpawnedActor->x_position = (func_global_asm_80612794(gCurrentActorPointer->y_rotation) * 14.0f) + gCurrentActorPointer->x_position;
        gLastSpawnedActor->z_position = (func_global_asm_80612790(gCurrentActorPointer->y_rotation) * 14.0f) + gCurrentActorPointer->z_position;
        func_global_asm_8066EA90(gLastSpawnedActor, 3);
        func_global_asm_8066EA90(gLastSpawnedActor, 1);
        func_global_asm_80665564(gLastSpawnedActor, 14.0f);
        gCurrentActorPointer->unk68 &= 0xFFBF;
        gLastSpawnedActor->object_properties_bitfield |= 0x1000;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_807149A8(gLastSpawnedActor->draw_distance * 0.75);
        func_global_asm_80714C08(&D_global_asm_8072030C, 0.28f, gLastSpawnedActor, 1, 2);
        playActorAnimation(gCurrentActorPointer, 0x300);
        func_global_asm_80604CBC(gCurrentActorPointer, 0x135, 0x64, 0, 0, 0x78, 1.0f, 0);
    }
    if ((D_global_asm_807FBB70.unk15 != 0) || (D_global_asm_807FBB70.unk200 == 9)) {
        gCurrentActorPointer->unk11C->control_state = 0;
        playCutscene(gCurrentActorPointer, 6, 5);
        gCurrentActorPointer->noclip_byte = 1;
        gCurrentActorPointer->control_state = 0x37;
        gCurrentActorPointer->control_state_progress = 0;
    } else if (D_global_asm_807FBB70.unk200 == 4) {
        gCurrentActorPointer->control_state_progress++;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x27:
            break;
        case 0x0:
            if (func_global_asm_80629148()) {
                func_global_asm_806A2A10(0xDC, 0x2A, 0x1E);
                func_global_asm_806A2B08(gCurrentActorPointer->unk11C);
                gCurrentActorPointer->control_state = 7;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 0x37:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0x3C:
                    gCurrentActorPointer->object_properties_bitfield &= ~4;
                    gCurrentActorPointer->unk68 &= 0xFFBF;
                    playSoundAtActorPosition(gCurrentActorPointer, 0xED, 0xFF, 0x7F, 0x14);
                    func_global_asm_8067DF44(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, (gCurrentActorPointer->animation_state->scale_y * 2) / 0.15, 0, 1);
                    deleteActor(D_global_asm_807FDC94);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 0x64:
                    deleteActor(gCurrentActorPointer->unk11C);
                    gCurrentActorPointer->control_state = 0x40;
                    playSong(MUSIC_42_FAILURE, 1.0f);
                    // Fallthrough
                default:
                    gCurrentActorPointer->control_state_progress++;
                    break;
                }
            break;
        default:
            if (gCurrentActorPointer->unk11C != NULL) {
                if (gCurrentActorPointer->unk11C->control_state == 5) {
                    gCurrentActorPointer->unk138 &= 0xFFFF7FFF;
                    func_global_asm_80605314(gCurrentActorPointer, 0);
                    func_global_asm_80726EE0(0);
                    func_global_asm_8071586C(D_global_asm_807FDC94);
                    deleteActor(gCurrentActorPointer->unk11C);
                    gCurrentActorPointer->control_state = 0x27;
                    gCurrentActorPointer->control_state_progress = 0;
                    playCutscene(gCurrentActorPointer, 3, 1);
                    playActorAnimation(gCurrentActorPointer, 0x307);
                    gCurrentActorPointer->y_rotation += 0x800;
                    gCurrentActorPointer->z_position += 5.0f;
                }
            }
            if ((gCurrentActorPointer->control_state_progress != 0) && (func_global_asm_8067AF44(D_global_asm_807FDC94) != 0) && ((object_timer % 7U) == 0)) {
                brightness = 180 + (30 * -gCurrentActorPointer->control_state_progress);
                func_global_asm_80714998(3);
                changeActorColor(brightness, brightness, brightness, gCurrentActorPointer->shadow_opacity);
                func_global_asm_8068588C(D_global_asm_807FDC94, 1, 1.0f, 0.0f, 0.0f, 0.0f, -0x96);
            }
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806B24B8(void) {
    Actor *rabbit;
    f32 dx;
    f32 dz;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        rabbit = func_global_asm_8067ADB4(ACTOR_RABBIT_CAVES);
        if (rabbit != NULL) {
            D_global_asm_807FDC90->unk4 = rabbit;
        }
        D_global_asm_807FDC9C->unk10 = 0x23;
        func_global_asm_80613C48(gCurrentActorPointer, 0x599, 0, 0);
        gCurrentActorPointer->unk68 &= 0xFFBF;
        func_global_asm_80604CBC(gCurrentActorPointer, 0x139, 0x78, 0, 1, 0x3C, 0.56f, 0);
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    }
    if ((object_timer % 10U) == 0) {
        func_global_asm_807149B8(1);
        func_global_asm_80714C08(&D_global_asm_80720340, gCurrentActorPointer->animation_state->scale_y * 6.66666666999999968 * 0.9, gCurrentActorPointer, 1, 2);
    }
    if (func_global_asm_8067AF44(D_global_asm_807FDC94) == 0) {
        D_global_asm_807FDC90->unk4 = gPlayerPointer;
        D_global_asm_807FDC94 = D_global_asm_807FDC90->unk4;
    }
    if ((D_global_asm_807FBB70.unk15 != 0) || (D_global_asm_807FBB70.unk200 == 9)) {
        gCurrentActorPointer->noclip_byte = 1;
        gCurrentActorPointer->control_state = 0x40;
        func_global_asm_8067DF44(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, gCurrentActorPointer->animation_state->scale_y / 0.15, 0, 1);
    }
    if (gCurrentActorPointer->control_state == 0x23) {
        if (gCurrentActorPointer->unkF0 == 0) {
            dx = gCurrentActorPointer->x_position - D_global_asm_807FDC94->x_position;
            dz = gCurrentActorPointer->z_position - D_global_asm_807FDC94->z_position;
            if (sqrtf(SQ(dx) + SQ(dz)) < 30.0f) {
                playSoundAtActorPosition(gCurrentActorPointer, 0x2CA, 0xFF, 0x7F, 0x14);
                gCurrentActorPointer->unkF0 = 1;
            }
        }
        func_global_asm_8072AB74(0x23, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0);
    } else {
        func_global_asm_8072B7CC(0x1F8);
    }
    renderActor(gCurrentActorPointer, 0);
}
