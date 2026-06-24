#include "common.h"

extern s8 D_global_asm_80750660;
extern s8 D_global_asm_807506A4;

extern s8 D_global_asm_807FC8D0;

// TODO: Add to aaD union
typedef struct {
    s16 unk0;
    s8 unk2; // keyIndex
    s8 unk3;
    Actor *unk4;
} PadlockAAD;

void func_global_asm_806BD170(void) {
    Actor* highest_priority_padlock;
    s16 keyIndex;
    s16 sp50;
    s16 keysCollected;

    sp50 = -1;
    keyIndex = 0;
    keysCollected = 0;
    while (keyIndex < 8) {
        // Key[keyIndex] Turned Flag
        if (!isFlagSet(PERMFLAG_PROGRESS_KEY_1_TURNED + keyIndex, FLAG_TYPE_PERMANENT)) {
            PadlockAAD *temp_v0;
            s16 temp2 = 260 + (keyIndex * 512);
            // Spawn Padlock
            spawnActor(ACTOR_PADLOCK_KLUMSY, 0xCD);
            gLastSpawnedActor->draw_distance = 2000;
            gLastSpawnedActor->object_properties_bitfield |= 0x800400;
            gLastSpawnedActor->object_properties_bitfield &= ~0x8000;
            
            gLastSpawnedActor->unk16A = 0xFF;
            gLastSpawnedActor->unk16B = 0xFF;
            gLastSpawnedActor->unk16C = 0xFF;
            gLastSpawnedActor->shadow_opacity = 0xFF;

            gLastSpawnedActor->x_position = (func_global_asm_80612794(temp2) * 270.0f) + gCurrentActorPointer->x_position;
            gLastSpawnedActor->z_position = (func_global_asm_80612790(temp2) * 270.0f) + gCurrentActorPointer->z_position;
            gLastSpawnedActor->y_position = 100.0f;
            gLastSpawnedActor->y_rotation = temp2;
            gLastSpawnedActor->unk146 = 0;
            gLastSpawnedActor->control_state = 0;
            temp_v0 = gLastSpawnedActor->additional_actor_data;
            temp_v0->unk0 = 0;
            temp_v0->unk4 = gCurrentActorPointer;
            temp_v0->unk2 = keyIndex;
            // Key Collected Flag
            if (isFlagSet(D_global_asm_80744710[keyIndex], FLAG_TYPE_PERMANENT)) {
                sp50 = keyIndex;
                highest_priority_padlock = gLastSpawnedActor;
                highest_priority_padlock->control_state = 5;
                keysCollected++;
            }
        }
        keyIndex++;
    }
    D_global_asm_807506A4 = 0;
    // Isles: Japes Boulder Smashed
    if (!isFlagSet(PERMFLAG_PROGRESS_JAPES_LOBBY_OPEN, FLAG_TYPE_PERMANENT)) {
        sp50 = -1;
    }
    if (!D_global_asm_80750660) {
        s32 temp = 1;
        if (sp50 != -1) {
            highest_priority_padlock->unk146 = temp;
            highest_priority_padlock->control_state = 1;
            D_global_asm_80750660 = 1;
            D_global_asm_807FC8D0 = sp50;
        }
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C1E70/func_global_asm_806BD3E4.s")

extern s8 D_global_asm_807506B4;
extern s8 D_global_asm_807506A8[];

extern s16 D_global_asm_8076A0A6; // Probably static

extern f32 D_global_asm_807FC8D4;

s32 areAllKeysTurnedIn(void);

typedef struct {
    Actor* unk0;
} Actor178_806BD3E4;

/*
void func_global_asm_806BD3E4(void) {
    Actor178_806BD3E4 *a178;
    s32 sp30;
    s32 sp2C;
    u8 sp2B;
    u8 temp;
    u16 sp28;
    s16 var_v1; // Probably static/volatile
    s16 var_t0;

    var_v1 = D_global_asm_8076A0A6;
    a178 = gCurrentActorPointer->unk178;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        if (areAllKeysTurnedIn()) {
            gCurrentActorPointer->control_state = 0x40;
            return;
        }
        gCurrentActorPointer->draw_distance = 2000;
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        var_v1 = 0;
        D_global_asm_807506B4 = 0;
        spawnActor(ACTOR_KLUMSY_CAGE, 0xC4);
        moveAndScaleActorToAnother(gLastSpawnedActor, gCurrentActorPointer, gCurrentActorPointer->animation_state->scale_y);
        gLastSpawnedActor->unk64 |= 0x20;
        gLastSpawnedActor->object_properties_bitfield |= 0x400;
        gLastSpawnedActor->draw_distance = 0x7D0;
        a178->unk0 = gLastSpawnedActor;
        D_global_asm_807FC8D4 = 1000.0f;
        func_global_asm_806BD170();
        gCurrentActorPointer->control_state = 0;
        if (D_global_asm_80750660 != 0) {
            D_global_asm_80750660 = 0;
        }
        if (isFlagSet(PERMFLAG_PROGRESS_JAPES_LOBBY_OPEN, FLAG_TYPE_PERMANENT) == 0) {
            gCurrentActorPointer->control_state = 1;
        }
    }
    var_t0 = -1;
    if (var_v1) {
        var_t0 = 0;
        while (!(var_v1 & 1)) {
            var_v1 >>= 1;
            var_t0++;
        }
    }
    D_global_asm_807FC8D4 = ((gCurrentActorPointer->x_position - gPlayerPointer->x_position) * (gCurrentActorPointer->x_position - gPlayerPointer->x_position)) + ((gCurrentActorPointer->z_position - gPlayerPointer->z_position) * (gCurrentActorPointer->z_position - gPlayerPointer->z_position));
    sp28 = 0;
    switch (gCurrentActorPointer->control_state) {
        case 1:
            playActorAnimation(gCurrentActorPointer, 0x2EF);
            gCurrentActorPointer->control_state = 2;
            playCutscene(gPlayerPointer, 2, 1);
            break;
        case 2:
            if (func_global_asm_80629148()) {
                playSong(MUSIC_125_K_LUMSY_CELEBRATION, 1.0f);
                playActorAnimation(gCurrentActorPointer, 0x2F1);
                gCurrentActorPointer->control_state = 3;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 3:
            if (gCurrentActorPointer->control_state_progress & 1) {
                gCurrentActorPointer->control_state_progress++;
                sp2B = 0xF;sp28 = 0x28;
            }
            break;
    }
    if ((func_global_asm_8061CB50() == 0) && (gCurrentActorPointer->animation_state->unk64 != 0x2F0)) {
        playActorAnimation(gCurrentActorPointer, 0x2F0);
    }
    if (sp28) {
        func_global_asm_8061F0B0(D_global_asm_807F5D10, sp2B, sp28);
    }
    if (var_t0 >= 0) {
        if (var_t0 == D_global_asm_807506A8[D_global_asm_807506B4]) {
            if (D_global_asm_807506A8[++D_global_asm_807506B4] == -1) {
                playSound(0x1DA, 0x7FFF, 63.0f, 1.0f, 5, 0);
                setFlag(GLOBALFLAG_DEBUG_KLUMSY_2, TRUE, FLAG_TYPE_GLOBAL);
                setFlag(GLOBALFLAG_DEBUG_KLUMSY_1, TRUE, FLAG_TYPE_GLOBAL);
                D_global_asm_807506B4 = -1;
            }
        } else {
            D_global_asm_807506B4 = 0;
        }
    }
    D_global_asm_8076A0A6 = 0;
    renderActor(gCurrentActorPointer, 0);
}
*/

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct80750664;

extern Struct80750664 D_global_asm_80750664[];
extern s16 D_global_asm_80750684[];
extern s8 D_global_asm_807506A4;

typedef struct {
    union {
        struct {
            s32 unk0;
            s32 unk4;
        };
        s8 unk0_s8arr[8];
    };
} Struct807506B8;

extern Struct807506B8 D_global_asm_807506B8;

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    Actor *unk4;
} AAD_806BD7B0;

typedef struct {
    Actor *unk0;
} A178_806BD7B0;

void func_global_asm_806BD7B0(void) {
    AAD_806BD7B0 *aaD;
    f32 sp48;
    f32 sp44;
    Actor *atemp;
    A178_806BD7B0 *AAD178;
    s32 sp38;
    Struct807506B8 sp30;
    f32 temp;
    aaD = gCurrentActorPointer->additional_actor_data;
    switch (gCurrentActorPointer->control_state) {
        case 0:
            break;

        case 5:
            if (D_global_asm_807506A4 && !func_global_asm_8061CB50()) {
                aaD->unk0++;
                if (aaD->unk0 >= 0x29) {
                    D_global_asm_807506A4 = 0;
                    gCurrentActorPointer->control_state = 1;
                }
            } else {
                aaD->unk0 = 0;
            }
            break;

        case 1:
            aaD->unk0 = 0;
            gCurrentActorPointer->control_state = 2;
            break;

        case 2:
            if (D_global_asm_807FC8D4 < SQ(400.0)) {
                gCurrentActorPointer->control_state = 3;
                aaD->unk0 = 0;
                playSong(MUSIC_59_GENERIC_TWINKLY_SOUNDS, 1.0f);
                playSound(0x258, 0x7FFF, 63.0f, 1.0f, 5, 0);
                playCutscene(gCurrentActorPointer, 0, 1);
                playActorAnimation(gCurrentActorPointer, 0x291);
                gCurrentActorPointer->control_state_progress = 0;
                gCurrentActorPointer->unk146 = 1;
            }
            break;

        case 3:
            if (gCurrentActorPointer->control_state_progress == 1) {
                gCurrentActorPointer->control_state_progress++;
                break;
            }
            if (gCurrentActorPointer->control_state_progress == 2) {
                func_global_asm_80602B60(0x3B, 1);
                gCurrentActorPointer->shadow_opacity -= 8;
                if (gCurrentActorPointer->shadow_opacity <= 0) {
                    gCurrentActorPointer->shadow_opacity = 0;
                    aaD->unk0++;
                    if (aaD->unk0 == 1) {
                        playSound(0x1F6, 0x7FFF, 63.0f, 1.0f, 5, 0);
                    }
                    if (aaD->unk0 >= 0xB) {
                        sp30 = D_global_asm_807506B8;
                        gCurrentActorPointer->control_state = 4;
                        playSong(MUSIC_125_K_LUMSY_CELEBRATION, 1.0f);
                        playActorAnimation(aaD->unk4, D_global_asm_80750684[aaD->unk2]);
                        aaD->unk0 = 0;
                        aaD->unk4->control_state = 3;
                        aaD->unk4->control_state_progress = 0;
                        playCutscene(NULL, 1, 1);
                        func_global_asm_8063DA40(sp30.unk0_s8arr[aaD->unk2], 2);
                    }
                }
                if (gCurrentActorPointer->shadow_opacity < 0x80) {
                    gCurrentActorPointer->y_position -= 6.0;
                }
            } else {
                func_global_asm_80714950(0x10064);
                func_global_asm_8071498C(func_global_asm_8071AADC);
                changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
                temp = func_global_asm_806119FC();
                sp48 = (temp * 30.0) + gCurrentActorPointer->x_position;
                temp = func_global_asm_806119FC();
                sp44 = (temp * 30.0) + (gCurrentActorPointer->y_position + 20.0);
                temp = func_global_asm_806119FC();
                temp = (temp * 30.0) + gCurrentActorPointer->z_position;
                drawSpriteAtPosition(&D_global_asm_80720A7C, 1.2f, sp48, sp44, temp);
                break;
            }
            break;

        case 4:
            if (areAllKeysTurnedIn()) {
                AAD178 = aaD->unk4->unk178;
                AAD178->unk0->y_position += 5.0;
                if (aaD->unk0 == 0x10E) {
                    setFlag(PERMFLAG_PROGRESS_K_LUMSY_FREE, TRUE, FLAG_TYPE_PERMANENT);
                    func_global_asm_80712524(D_global_asm_80750664[7].unk0, D_global_asm_80750664[7].unk2);
                }
            }
            sp38 = 0xB4;
            if ((aaD->unk2 == 2) || (aaD->unk2 == 7)) {
                sp38 = 0xB4;
                if (!areAllKeysTurnedIn()) {
                    sp38 = 0x5A;
                }
            }
            aaD->unk0++;
            if (aaD->unk0 == sp38) {
                if ((aaD->unk2 == 2) || (aaD->unk2 == 7)) {
                    setFlag(PERMFLAG_PROGRESS_KEY_1_TURNED + aaD->unk2, TRUE, FLAG_TYPE_PERMANENT);
                    if (!areAllKeysTurnedIn()) {
                        func_global_asm_8061CB08();
                        func_global_asm_80602B60(0x7D, 1);
                        D_global_asm_807506A4 = 1;
                    }
                } else {
                    // fake match
                    if (gCurrentActorPointer->y_position && gCurrentActorPointer->y_position) {
                    }

                    func_global_asm_80712524(
                        D_global_asm_80750664[aaD->unk2].unk0,
                        D_global_asm_80750664[aaD->unk2].unk2);
                }
            }
            break;
    }

    gCurrentActorPointer->unk15E = 0x28;
    renderActor(gCurrentActorPointer, 0);
}

s32 areAllKeysTurnedIn(void) {
    s32 key;
    for (key = 0; key < 8; key++) {
        if (!isFlagSet(key + PERMFLAG_PROGRESS_KEY_1_TURNED, FLAG_TYPE_PERMANENT)) {
            return FALSE;
        }
    }
    return TRUE;
}
