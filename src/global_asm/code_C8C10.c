#include <ultra64.h>
#include "functions.h"

void func_global_asm_8061C518(Actor*, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_global_asm_806B49B0(u8 arg0, s16 arg1, s16 arg2);

void func_global_asm_806C3F10(u8 arg0, u8 arg1, u8 arg2) {
    Actor178 *a178;

    a178 = current_actor_pointer->unk178;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0x20;
        if (arg2) {
            playCutscene(current_actor_pointer, arg2, 1);
        } else {
            func_global_asm_8061C518(D_global_asm_807F5D10, current_actor_pointer, 4, 0x800, 0x19, 0, 0xA, 0x14, 0xC, 0, 0.1f);
        }
        D_global_asm_807FDC9C->unk10 = 0x27;
        current_actor_pointer->control_state = 0x27;
        current_actor_pointer->control_state_progress = 0;
    }
    a178->unk0 = MAX(0, D_global_asm_807FDC90->unkC - D_global_asm_807FDC9C->unk6);
    switch (current_actor_pointer->control_state) {
        case 39:
            if ((D_global_asm_807FDC90->unk1A & 4) && ((D_global_asm_807FDC90->unk25 & 0x7F) == arg0)) {
                if (!character_change_array->unk2C0) {
                    loadText(current_actor_pointer, 0x10, 1);
                    current_actor_pointer->control_state = 0x29;
                    current_actor_pointer->control_state_progress = 0;
                    D_global_asm_807FDC9C->unk10 = 0x29;
                    extra_player_info_pointer->unk1F0 |= 0x10000;
                    setAction(0x54, NULL, 0);
                    D_global_asm_807FDC90->unk1A |= 0x8000;
                } else {
                    loadText(current_actor_pointer, 0x10, 0);
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    D_global_asm_807FDC9C->unk10 = 0x28;
                    if (!arg2) {
                        func_global_asm_8061C464(D_global_asm_807F5D10, current_actor_pointer, 4, 0x800, 0x19, 0, 0xA, 0x14, 0xC, 0x78, 0.1f);
                    }
                }
            }
            // fallthrough
        case 40:
            func_global_asm_806B49B0(2, 0x23D, 0x23E);
            return;
        case 38:
        case 41:
            if (D_global_asm_807FDC90->unk1A & 0x8000) {
                if ((D_global_asm_807FDC90->unk1A & 4) && ((D_global_asm_807FDC90->unk25 & 0x7F) == arg1)) {
                    if (!arg2) {
                        func_global_asm_806225C0(D_global_asm_807F5D10);
                    }
                    playCutscene(player_pointer, 3, 5);
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    D_global_asm_807FDC9C->unk10 = 0x28;
                    extra_player_info_pointer->unk1F0 &= 0xFFFEFFFF;
                    D_global_asm_807FDC90->unk1A &= 0x7FFF;
                } else {
                    if (!arg2) {
                        func_global_asm_8061C464(D_global_asm_807F5D10, player_pointer, 4, (s16)(object_timer * 0x14), 0x1E, 0, 0xA, 0x1E, 0xC, 0, 0.2f);
                    }
                    player_pointer->y_rotation = current_actor_pointer->y_rotation;
                    player_pointer->x_position = current_actor_pointer->x_position;
                    player_pointer->y_position = current_actor_pointer->y_position - 2.0f;
                    player_pointer->z_position = current_actor_pointer->z_position;
                    player_pointer->unk6A &= 0xFFFE;
                    player_pointer->locked_to_pad = 0;
                }
            }
            func_global_asm_806B49B0(current_actor_pointer->control_state == 0x26 ? 0x26 : 2, 0x23D, 0x23E);
            // fallthrough
        case 0:
            return;
    }
}

void func_global_asm_806C43A8(void) {
    s32 song = 0;
    switch (current_map) {
        case MAP_JAPES_MINECART:
            song = 3;
            break;
        case MAP_CASTLE_MINECART:
            song = 0x6A;
            break;
        case MAP_FUNGI_MINECART:
            song = 0x4A;
    }
    if (song != 0) {
        playSong(song, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_global_asm_806C4414.s")

void func_global_asm_806C4904(void) {
    func_global_asm_806C4414(0, 1, 2, 0xF, 0x10, 0x32, 0x18);
}

void func_global_asm_806C4948(void) {
    func_global_asm_806C4414(6, 7, 8, 0x10, 0xE, 0x32, 0xD7);
}

void func_global_asm_806C498C(void) {
    func_global_asm_806C4414(1, 2, 3, 4, 5, 0x19, 0x13E);
}

void func_global_asm_806C49D0(void) {
    initializeCharacterSpawnerActor();
    switch (current_map) {
        case MAP_AZTEC:
            func_global_asm_806C3F10(2, 6, 0);
            break;
        case MAP_JAPES_MINECART:
            func_global_asm_806C4904();
            break;
        case MAP_FUNGI_MINECART:
            func_global_asm_806C4948();
            break;
        case MAP_CASTLE_MINECART:
            func_global_asm_806C498C();
            break;
        case MAP_FUNGI:
            if (D_global_asm_807FDC9C->unk13 == 6) {
                func_global_asm_806C3F10(2, 7, 0x1A);
            } else {
                func_global_asm_806C3F10(2, 3, 0);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

extern int func_global_asm_8068E474(); // TODO: Signature

typedef struct {
    s16 unk0;
} A178_806C4AC4;

typedef struct {
    s16 unk0;
} A180_806C4AC4;

u8 func_global_asm_806C4AC4(u16 arg0, u16 arg1) {
    u8 sp4F;
    s32 pad;
    A180_806C4AC4 *a180;
    s32 pad2;
    f32 sp3C;
    A178_806C4AC4 *a178;

    sp4F = 0;
    a178 = current_actor_pointer->unk178;
    a180 = current_actor_pointer->unk180;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0x20;
        current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkC;
    }
    a178->unk0 = MAX(0, D_global_asm_807FDC90->unkC - D_global_asm_807FDC9C->unk6);
    if ((current_actor_pointer->control_state != 2) && (current_actor_pointer->control_state != 0x26)) {
        if (current_actor_pointer->control_state == 0x37) {
            func_global_asm_8072AB74(0x37, 0, 0, 0x22, 0);
        }
    } else {
        extra_player_info_pointer->unk1F4 |= 0x40;
        sp3C = func_global_asm_80665AE4(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position);
        current_actor_pointer->unkEC = sp3C - func_global_asm_80665AE4(character_change_array->look_at_at_x, character_change_array->look_at_at_z, character_change_array->look_at_eye_x, character_change_array->look_at_eye_z);
        func_global_asm_806B49B0(current_actor_pointer->control_state, D_global_asm_807FDC98->unk28, D_global_asm_807FDC98->unk2A);
        current_actor_pointer->unk15F = (arg1 - D_global_asm_807FDC90->unk2C) + 1;
        if (D_global_asm_807FBB70.unk0 != 0) {
            if (D_global_asm_807FBB70.unk1 != current_actor_pointer->unk15F) {
                sp4F = 1;
            } else {
                D_global_asm_807FDC90->unk2C--;
                if (D_global_asm_807FDC90->unk2C == 0) {
                    sp4F = 2;
                }
            }
        }
        if (current_character_index[0] != 1) {
            sp4F = 1;
        }
        if (a180->unk0 != 0) {
            a180->unk0--;
        } else if (current_actor_pointer->unk168 < arg1) {
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x1DD, 0xFF, 0x7F, 0x14, 0x14, 0, 0);
            spawnActor(ACTOR_VULTURE_RACE_HOOP, 0);
            current_actor_pointer->unk168++;
            last_spawned_actor->unk15F = current_actor_pointer->unk168;
            last_spawned_actor->x_position = current_actor_pointer->x_position;
            last_spawned_actor->y_position = current_actor_pointer->y_position - 10.0f;
            last_spawned_actor->z_position = current_actor_pointer->z_position;
            last_spawned_actor->y_rotation = current_actor_pointer->y_rotation;
            last_spawned_actor->unk11C = current_actor_pointer;
            a180->unk0 = arg0;
        }
        addActorToTextOverlayRenderArray(func_global_asm_8068E474, current_actor_pointer, 3);
    }
    renderActor(current_actor_pointer, 0);
    return sp4F;
}

void func_global_asm_806C4E8C(void) {
    func_global_asm_806FB370(5, 0, 0);
}

void func_global_asm_806C4EB4(void) {
    func_global_asm_8063DA40(0x2C, 0xB);
    func_global_asm_806C4E8C();
}

void func_global_asm_806C4EE0(u8 textIndex, u8 arg1) {
    D_global_asm_807FDC90->unk2E = 0;
    func_global_asm_8070E8DC(1);
    loadText(current_actor_pointer, 0xF, textIndex);
    current_actor_pointer->control_state = 0x29;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->unk168 = arg1;
    current_actor_pointer->unkF0 = 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C8C10/func_global_asm_806C4F5C.s")

void func_global_asm_806C55D8(void) {

}

void func_global_asm_8061CB08(void);
typedef struct {
    s16 unk0;
} A180_806C55E0;

void func_global_asm_806C55E0(void) {
    f32 dx;
    A180_806C55E0 *a180;
    f32 dz;

    a180 = current_actor_pointer->unk180;
    initializeCharacterSpawnerActor();
    if (!(extra_player_info_pointer->unk1F0 & 0x100000)) {
        current_actor_pointer->control_state = 0x40;
        return;
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8072B79C(0x357, 0x357, 0x359);
        D_global_asm_807FDC98->unk46 |= 0x20;
        current_actor_pointer->control_state = 0x1E;
        current_actor_pointer->draw_distance = 0x3E8;
        func_global_asm_80728950(0);
    }
    switch (current_actor_pointer->control_state) {
        case 30:
            func_global_asm_80684850(1);
            func_global_asm_80724A20();
            break;
        case 39:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    if (func_global_asm_8061CB50() == 0) {
                        func_global_asm_807289B0(0, 0);
                        playCutscene(current_actor_pointer, 0x13, 1);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 1:
                    if (func_global_asm_80629148()) {
                        playActorAnimation(current_actor_pointer, 0x354);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 3:
                    loadText(current_actor_pointer, 0x15, 0);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 4:
                    if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        current_actor_pointer->control_state = 0x28;
                    }
                    break;
            }
            break;
        case 40:
            if (player_pointer->control_state == 0x63) {
                dx = current_actor_pointer->x_position - player_pointer->x_position;
                dz = current_actor_pointer->z_position - player_pointer->z_position;
                if (((dx * dx) + (dz * dz)) < 10000.0f) {
                    playCutscene(current_actor_pointer, 0x15, 1);
                    loadText(current_actor_pointer, 0x15, 1);
                    current_actor_pointer->control_state = 0x29;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            break;
        case 41:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                        playActorAnimation(current_actor_pointer, 0x358);
                        current_actor_pointer->control_state_progress = 1;
                    }
                    break;
                case 2:
                    func_global_asm_8061CB08();
                    D_global_asm_807FDC98->unk46 |= 0x24;
                    current_actor_pointer->control_state = 2;
                    func_global_asm_806FB370(5, 0, 1);
                    func_global_asm_806F8BC4(5, 1, 0);
                    a180->unk0 = 0x78;
                    D_global_asm_807FDC90->unk2C = 0x10;
                    current_actor_pointer->unk168 = 0;
                    playActorAnimation(current_actor_pointer, 0x357);
                    break;
            }
            break;
        case 42:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    current_actor_pointer->x_rotation = 0;
                    current_actor_pointer->z_rotation = 0;
                    if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        func_global_asm_806C4E8C();
                        if ((current_actor_pointer->animation_state->unk64 == 0x35A) && (player_pointer->control_state == 0x63)) {
                            func_global_asm_806ACC00(4);
                            current_actor_pointer->control_state_progress = 3;
                        } else {
                            current_actor_pointer->control_state_progress += 1;
                            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
                        }
                    }
                    break;
                case 1:
                    func_global_asm_8072DC7C(5);
                    break;
                case 2:
                    current_actor_pointer->control_state = 0x3C;
                    break;
                case 3:
                    func_global_asm_80724A20();
                    break;
            }
            break;
        case 48:
            playActorAnimation(current_actor_pointer, 0x355);
            func_global_asm_807266E8(current_actor_pointer, D_global_asm_807FDC9C);
            D_global_asm_807FDC90->unk25 = 0;
            current_actor_pointer->unk168 = 0;
            func_global_asm_80672C30(player_pointer);
            player_pointer->y_position = current_actor_pointer->y_position;
            player_pointer->x_position = (func_global_asm_80612794(current_actor_pointer->y_rotation) * 50.0f) + current_actor_pointer->x_position;
            player_pointer->z_position = (func_global_asm_80612790(current_actor_pointer->y_rotation) * 50.0f) + current_actor_pointer->z_position;
            player_pointer->y_rotation = func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position);
            playCutscene(current_actor_pointer, 0x15, 1);
            loadText(current_actor_pointer, 0x15, 1);
            current_actor_pointer->control_state = 0x29;
            current_actor_pointer->control_state_progress = 0;
            break;
    }
    extra_player_info_pointer->unk1F4 &= ~0x40;
    switch (func_global_asm_806C4AC4(0x78, 0x10)) {
        case 1:
            func_global_asm_807266E8(current_actor_pointer, D_global_asm_807FDC9C);
            loadText(current_actor_pointer, 0x15, 2);
            playActorAnimation(current_actor_pointer, 0x35A);
            current_actor_pointer->control_state = 0x2A;
            current_actor_pointer->control_state_progress = 0;
            playCutscene(current_actor_pointer, 0x16, 1);
            break;
        case 2:
            func_global_asm_807266E8(current_actor_pointer, D_global_asm_807FDC9C);
            loadText(current_actor_pointer, 0x15, 3);
            playActorAnimation(current_actor_pointer, 0x35B);
            current_actor_pointer->control_state = 0x2A;
            current_actor_pointer->control_state_progress = 0;
            playCutscene(current_actor_pointer, 0x14, 1);
            break;
    }
    if (current_actor_pointer->control_state != 0x1E) {
        func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    }
}

s16 func_global_asm_80731784(s16, s16, void *);
extern s16 D_807FD802;
extern s16 D_807FD804;
extern s16 D_807FD806;
extern s32 D_global_asm_8071FB08; // TODO: Sprite
extern s16 D_global_asm_8076A0AA;
extern int func_global_asm_8071C818(); // TODO: Proper signature

void func_global_asm_806C5C20(void) {
    f32 sp54;
    f32 sp50;
    f32 dz;
    f32 dx;
    s32 sp44; // TODO: What is this?
    f32 temp_f2_2;
    s32 temp_t1;

    initializeCharacterSpawnerActor();
    func_global_asm_80672C30(current_actor_pointer);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0x40;
        current_actor_pointer->draw_distance = 0xFA;
        func_global_asm_80724CA4(2, 1);
    }
    if (((rand() >> 0xF) % 1000) >= 0x3CB) {
        current_actor_pointer->unkB8 = D_global_asm_807FDC9C->unkC * 4;
    }
    func_global_asm_80724E48(6);
    func_global_asm_8072AB74(1, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x2C9, 0);
    if (!(object_timer & 3)) {
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(func_global_asm_8071C818);
        drawSpriteAtPosition(&D_global_asm_8071FB08, 1.6f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    }
    if (!(extra_player_info_pointer->unk1F0 & 0x8000)) {
        dz = character_change_array->look_at_eye_z - current_actor_pointer->z_position;
        dx = character_change_array->look_at_eye_x - current_actor_pointer->x_position;
        temp_f2_2 = sqrtf((dz * dz) + (dx * dx)) - character_change_array->near;
        if ((D_807FD804 >= 0x8A) && (D_807FD804 < 0xB1) && (D_807FD806 >= 0x61) && (D_807FD806 < 0x88) && (temp_f2_2 < D_807FD802)) {
            if ((extra_player_info_pointer->unk1EC != 1) && (func_global_asm_8072DE10(0x1388) != 0)) {
                playActorAnimation(current_actor_pointer, 0x2B6);
            }
            extra_player_info_pointer->unk1EC = 1;
        } else {
            if (extra_player_info_pointer->unk1EC != 2) {
                playActorAnimation(current_actor_pointer, 0x2B5);
            }
            extra_player_info_pointer->unk1EC = 2;
        }
    }
    if (((extra_player_info_pointer->unk1F0 & 0x8000)) && (extra_player_info_pointer->unk1EC == 1)) {
        if (current_actor_pointer->control_state != 0x40) {
            setFlag(func_global_asm_80731784(D_global_asm_8076A0AA, func_global_asm_80727194(current_actor_pointer), &sp44), TRUE, FLAG_TYPE_PERMANENT);
            func_global_asm_8060DEC8();
        }
        current_actor_pointer->control_state = 0x40;
    }
    if (current_actor_pointer->control_state != 0x40) {
        playSong(0x42, 1.0f);
    } else {
        func_global_asm_80602B60(0x42, 0);
    }
    func_global_asm_80626F8C(current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position, &sp54, &sp50, 0, 1.0f, 0);
    D_807FD804 = sp54;
    D_807FD806 = sp50;
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C5FEC(void) {
    YetAnotherAdditionalActorData5 *temp_v1;
    PlayerAdditionalActorData *temp_a0;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_v1->unk1C = 0;
        current_actor_pointer->object_properties_bitfield |= 0x400;
    }
    temp_v1->unk1C++;
    switch (temp_v1->unk1E) {
        case 1:
            if (player_pointer->control_state_progress == 3) {
                loadText(current_actor_pointer, 0x1E, 3);
                temp_v1->unk1E = 2;
            } else if (temp_v1->unk10->control_state != 0x83) {
                temp_v1->unk1E = 3;
            }
            break;
        case 2:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                temp_v1->unk1E = 3;
                func_global_asm_8061CB08();
            }
            break;
        default:
            if (temp_v1->unk10->control_state != 0x83) {
                temp_a0 = temp_v1->unk10->PaaD;
                temp_a0->unk1F4 &= ~0x10;
                temp_v1->unk10->object_properties_bitfield &= 0xBFFFFFFF;
                temp_v1->unk10->object_properties_bitfield |= 1;
                temp_v1->unk10->z_rotation = temp_v1->unk16;
                temp_v1->unk10->x_rotation = temp_v1->unk14;
                global_properties_bitfield |= 0x10030;
                func_global_asm_80659670(temp_v1->unk0, temp_v1->unk4, temp_v1->unk8, temp_v1->unk1A);
                func_global_asm_80602B60(0x3B, 0);
                deleteActor(temp_v1->unkC);
                deleteActor(current_actor_pointer);
                return;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C61C8(void) {
    f32 sp24;
    f32 sp20;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEC = 0x3C;
        playActorAnimation(current_actor_pointer, 0x23D);
        if (player_pointer->control_state == 0xC) {
            playAnimation(player_pointer, 0x87);
        }
    }
    sp24 = (func_global_asm_80612794(player_pointer->y_rotation) * 50.0f) + player_pointer->x_position;
    sp20 = (func_global_asm_80612790(player_pointer->y_rotation) * 50.0f) + player_pointer->z_position;
    current_actor_pointer->y_rotation = (player_pointer->y_rotation + 0x800) & 0xFFF;
    if (current_actor_pointer->unkEC == 0x3C) {
        current_actor_pointer->x_position = (func_global_asm_80612794(current_actor_pointer->unkEE) * 10.0f) + sp24;
        current_actor_pointer->z_position = (func_global_asm_80612790(current_actor_pointer->unkEE) * 10.0f) + sp20;
    }
    current_actor_pointer->y_position = (func_global_asm_80612794(object_timer * 0x64) * 5.0f) + (current_actor_pointer->unk15F + player_pointer->y_position + 3.0f + current_actor_pointer->unkEC);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (current_actor_pointer->unkF0 != 0) {
            current_actor_pointer->unk15F = 0x14;
            func_global_asm_8069E490(0x2D, func_global_asm_8073195C(current_actor_pointer->unkF0));
        }
    }
    if (current_actor_pointer->unkF0 != 0) {
        func_global_asm_8069E4E0(-0x1E);
    }
    current_actor_pointer->unkEE += 60.0f * func_global_asm_80612794(object_timer * 0x32);
    if (current_actor_pointer->object_properties_bitfield & 0x02000000) {
        current_actor_pointer->unk168 = 0x14;
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
    }
    if (current_actor_pointer->unk168 == 0) {
        current_actor_pointer->unkEC++;
        if (current_actor_pointer->unkEC >= 0x3D) {
            if (current_actor_pointer->unkF0 != 0) {
                func_global_asm_8069E5B8();
            }
            deleteActor(current_actor_pointer);
            func_global_asm_8061CB08();
            if (player_pointer->control_state == 0xC) {
                playAnimation(player_pointer, 9);
            }
        }
    } else {
        if (current_actor_pointer->unkEC >= 0x10) {
            current_actor_pointer->unkEC--;
        }
    }
    renderActor(current_actor_pointer, 0);
}
