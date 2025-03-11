#include "common.h"

typedef struct {
    void *unk0; // function pointer
    s8 unk4;
    s8 unk5;
    s16 unk6;
    f32 unk8;
    Actor *unkC;
    Actor *unk10;
} GlobalASMStruct61;

typedef struct {
    f32 unk0;
    Actor *unk4;
    Actor *unk8;
} Struct806CEFBC;

typedef struct {
    Actor *unk0;
    Actor *unk4;
} Struct806CF138;

typedef struct {
    void *unk0; // function pointer
    s8 unk4;
    s8 unk5;
    s16 unk6;
    Actor *unk8;
    Actor *unkC;
    Actor *unk10;
} GlobalASMStruct62;

typedef struct {
    void (*unk0)();
    s16 unk4; // Used
    s16 unk6;
} GlobalASMStruct63;

// TODO: Add to aaD union
typedef struct {
    u16 unk0;
    u16 unk2;
    Actor *unk4;
    s32 unk8;
    u16 unkC;
    u16 unkE;
    f32 unk10;
} AAD_global_asm_806D0A84;

extern u8 D_global_asm_80750AD0;
extern GlobalASMStruct63 D_global_asm_80750B50[];
extern f32 D_global_asm_80750FA8;

// .data
extern f32 D_global_asm_80753170[];
extern f32 D_global_asm_8075318C[];
extern f32 D_global_asm_807531A8[];
extern f32 D_global_asm_807531C4[];
extern f32 D_global_asm_807531E0[];
extern f32 D_global_asm_807531FC[]; // Kong Walking Maximum Velocity
extern f32 D_global_asm_80753218[];
extern f32 D_global_asm_80753234[];
extern f32 D_global_asm_80753250[];
extern s16 D_global_asm_8075326C[];
extern f32 D_global_asm_807532B8[];
extern f32 D_global_asm_807532D4[];
extern f32 D_global_asm_807532F0[];
extern f32 D_global_asm_8075330C[];
extern s16 D_global_asm_80753328[];
extern f32 D_global_asm_80753338[];
extern f32 D_global_asm_8075340C[];
extern f32 D_global_asm_80753428[];
extern f32 D_global_asm_80753578[]; // yAccelArray in ghidra
extern f32 D_global_asm_80753594[];
extern f32 D_global_asm_807535B0[];/*= {-17, -17, -17, -17, -10, -10, -17}; // Kong Jumping Y Acceleration*/
extern f32 D_global_asm_80753658[];
extern f32 D_global_asm_807536E4[];
extern f32 D_global_asm_80753700[];
extern f32 D_global_asm_80753754[];
extern s16 D_global_asm_8075387C[];
extern s16 D_global_asm_8075388C[];
extern s16 D_global_asm_807538B8[];
extern s16 D_global_asm_807538C8[];
extern f32 D_global_asm_807539C0[];
extern s16 D_global_asm_80753A2C[];
extern s16 D_global_asm_80753A3C[];
extern s16 D_global_asm_80753A4C[];
extern f32 D_global_asm_80753A5C[];
extern s16 D_global_asm_80753A78[];
extern f32 D_global_asm_80753AFC[];

extern s32 D_global_asm_807FBB68;
extern u8 D_global_asm_807FD586;

int func_global_asm_806FF358(); // TODO: Signature
int func_global_asm_806FF75C(); // TODO: Signature

s32 handleInputsForControlState(s32 arg0);
void func_global_asm_806D0468(Actor *arg0, u8 arg1);
void func_global_asm_806CD424(s16, f32, f32); // TODO: Is this signature correct?
void func_global_asm_806CEFBC(Struct806CEFBC*); // TODO: Proper signature, just for function pointer
void func_global_asm_806CF138(Struct806CF138 *arg0);
void func_global_asm_806CA5F8(s32 arg0);

void func_global_asm_806C9DE0(void) {
    // DK Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 0);
}

void func_global_asm_806C9E10(void) {
    // Lanky Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 2);
}

void func_global_asm_806C9E40(void) {
    // Tiny Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 3);
}

void func_global_asm_806C9E70(void) {
    // Chunky Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 4);
}

void func_global_asm_806C9EA0(void) {
    // Rambi Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 6);
}

void func_global_asm_806C9ED0(void) {
    // Diddy Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 1);
}

void func_global_asm_806C9F00(void) {
    // Enguarde Actor
    func_global_asm_8066E5F8(gCurrentActorPointer, 3, 8);
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 7);
}

void func_global_asm_806C9F44(void) {
    // Krusha Actor
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(gCurrentActorPointer, 5);
}

void func_global_asm_806C9F74(Actor *arg0) {
    if (D_global_asm_80750B50[arg0->control_state].unk4 & 0x200) {
        func_global_asm_806EAB44(arg0, arg0->control_state != 2);
    } else if (D_global_asm_80750B50[arg0->control_state].unk4 & 0x100) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

Actor *func_global_asm_806C9FD8(Actor *actor) {
    Actor *originalActor = actor;

    if (!actor) {
        return actor;
    }

    switch (actor->interactable) {
        case 4:
            actor = actor->unk11C;
            break;
        case 8:
            actor = actor->unk11C;
            break;
    }

    if (actor) {
        if (actor->interactable == 1 || actor->interactable == 2) {
            return actor;
        }
    }

    return originalActor;
}

void func_global_asm_806CA048(Actor *actor, PlayerAdditionalActorData *arg1) {
    s32 phi_v1 = FALSE;

    if (!actor) {
        phi_v1 = TRUE;
    } else {
        if (actor->interactable & 1) {
            PlayerAdditionalActorData *PaaD = actor->PaaD;
            arg1->unk248 = PaaD->unk1A4;
            arg1->unk249 = 0;
        } else if (actor->interactable & 2) {
            arg1->unk248 = -1;
            arg1->unk249 = func_global_asm_80727194(actor);
        } else {
            phi_v1 = TRUE;
        }
    }

    if (phi_v1) {
        extra_player_info_pointer->unk246 = 0;
        extra_player_info_pointer->unk247 = -1;
    }
    arg1->unk24A = 5;
}

void func_global_asm_806CA0E8(Actor *arg0, Actor *arg1, s32 arg2) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    s32 phi_t0 = FALSE;
    s32 phi_a3 = FALSE;

    if (!arg1) {
        phi_a3 = TRUE;
    } else {
        if (arg1->interactable == 1) {
            PlayerAdditionalActorData *PaaD2 = arg1->PaaD;
            PaaD->unk247 = PaaD2->unk1A4;
            PaaD->unk246 = 0;
            phi_t0 = TRUE;
        } else if (arg1->interactable == 2) {
            PaaD->unk246 = func_global_asm_80727194(arg1);
            PaaD->unk247 = -1;
            phi_t0 = TRUE;
        } else {
            phi_a3 = TRUE;
        }
    }
    if (phi_a3) {
        PaaD->unk246 = 0;
        PaaD->unk247 = -1;
    }
    if (phi_t0) {
        PaaD->unk24C = arg1->animation_state->unk0->unk10;
        PaaD->unk24E = arg2;
    }
}

s32 func_global_asm_806CA1B4(s32 arg0) {
    Actor *phi_v1;
    s32 phi_a2 = 1;
    phi_v1 = NULL;

    if (extra_player_info_pointer->unk247 >= 0) {
        phi_v1 = character_change_array[extra_player_info_pointer->unk247].playerPointer;
    } else if (extra_player_info_pointer->unk246 > 0) {
        phi_v1 = getSpawnerTiedActor(extra_player_info_pointer->unk246, 0);
    }

    if (phi_v1) {
        if ((extra_player_info_pointer->unk24C == phi_v1->animation_state->unk0->unk10) && (extra_player_info_pointer->unk24E >= arg0)) {
            phi_a2 = 0;
        }
    }
    return phi_a2;
}

void func_global_asm_806CA26C(void) {
    if (func_global_asm_806CA1B4(-1)) {
        extra_player_info_pointer->unk247 = -1;
        extra_player_info_pointer->unk246 = 0;
    }
}

void func_global_asm_806CA2AC(void) {
    extra_player_info_pointer->unkC8 = -1;
    func_global_asm_80605314(gCurrentActorPointer, 1);
}

void func_global_asm_806CA2E4(void) {
    if ((extra_player_info_pointer->unkC8 != -1) && ((!isFlagSet(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, FLAG_TYPE_PERMANENT)) || (gCurrentActorPointer->unkE0 != 0.0f) || ((D_global_asm_807FBB64 << 8) < 0) || (func_global_asm_806F8AD4(5, extra_player_info_pointer->unk1A4) == 0))) {
        func_global_asm_806CA2AC();
        extra_player_info_pointer->unkC8 = -1;
        return;
    }
    if (extra_player_info_pointer->unkC8 != -1) {
        if (D_global_asm_807FD610[cc_player_index].unk2A & B_BUTTON) {
            if (extra_player_info_pointer->unkC8 > 0) {
                if ((extra_player_info_pointer->unkC8 < 0x1E) && ((object_timer & 3) == 0)) {
                    func_global_asm_80684900(0);
                }
                extra_player_info_pointer->unkC8--;
                if (extra_player_info_pointer->unkC8 == 0x1E) {
                    func_global_asm_80604CBC(gCurrentActorPointer, 0x104, 0x3C, 1, 1, 0xFF, 1.0f, 0);
                }
            } else if ((object_timer & 1) == 0) {
                func_global_asm_80684900(1);
            }
        } else {
            if (extra_player_info_pointer->unkC8 == 0) {
                if ((gCurrentActorPointer->unk6A & 1)) {
                    gCurrentActorPointer->control_state = 0x2D;
                    gCurrentActorPointer->control_state_progress = 0;
                    func_global_asm_806F8BC4(5, 0, 0);
                    changeCollectableCount(5, extra_player_info_pointer->unk1A4, -1 * func_global_asm_806FA7A4(5));
                    playAnimation(gCurrentActorPointer, 0x42);
                    playSoundAtActorPosition(gCurrentActorPointer, 0xF2, 0xFF, 0x7F, 0);
                    gCurrentActorPointer->unkB8 = 0.0f;
                }
            }
            func_global_asm_806CA2AC();
        }
    }
}

void func_global_asm_806CA540(void) {
    if ((gCurrentActorPointer->unk6A & 0x221) == 1) {
        if (gCurrentActorPointer->unkE0 != 0.0f) {
            if (!(gCurrentActorPointer->unk6C & 1)
                || gCurrentActorPointer->unkDE < 0x226
                || ((gCurrentActorPointer->unk78 == 0xC) && (gCurrentActorPointer->unkB8 > 40.0f))) {
                extra_player_info_pointer->unkC2 = 0x32;
            }
            extra_player_info_pointer->unkC2++;
        } else {
            extra_player_info_pointer->unkC2 = 0;
        }
    }
}

// Jumptable, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CA5F8.s")

void func_global_asm_806CF9CC();
extern u8 D_80770561;
extern s16 D_807F5FE4;
extern s16 D_807F5FE6;
extern s16 D_807F5FE8;
extern s16 D_807F5FEA;
extern s32 D_global_asm_8076A068;
extern s32 D_global_asm_8076A090;
extern s32 D_global_asm_8076A098;
extern s32 D_global_asm_8076A094;

/*
void func_global_asm_806CA5F8(s32 arg0) {
    Actor *a;
    f32 xs, ys; // 70, 6c
    u8 sp6B;
    u8 sp6A;
    u8 sp69;
    u8 sp68;
    Actor *sp64;
    otherSpriteControl *var_a1;
    f32 x0, y0, z0; // 5C, 58, 54
    otherSpriteControl *temp_v1;
    f32 xs0, ys0; // 4c, 48
    s16 temp_a0;
    s16 var_a1_2;

    sp64 = gCurrentActorPointer;
    extra_player_info_pointer = gCurrentActorPointer->PaaD;
    if (is_autowalking == 0) {
        gCurrentActorPointer->object_properties_bitfield |= 0x400000;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~0x400000;
    }
    gCurrentActorPointer->object_properties_bitfield &= ~0x8000000;
    character_change_array[cc_player_index].unk28C = character_change_array[cc_player_index].fov_y;
    if (gCurrentActorPointer->unk64 & 0x100) {
        extra_player_info_pointer->unk120 = D_global_asm_8076A068;
    }
    if ((extra_player_info_pointer->scale1C0[0] == extra_player_info_pointer->scale1CC[0]) && (gCurrentActorPointer->control_state != 0x54)) {
        if (gCurrentActorPointer->unk58 == ACTOR_LANKY) {
            gCurrentActorPointer->unk15E = 0xB;
        } else {
            gCurrentActorPointer->unk15E = gCurrentActorPointer->ledge_info_pointer->unkC * 0.15 * 0.5;
        }
    }
    func_global_asm_806CBE44();
    temp_a0 = D_global_asm_80750B50[gCurrentActorPointer->control_state].unk4;
    if (temp_a0 & 8) {
        gCurrentActorPointer->unk68 |= 2;
    } else {
        gCurrentActorPointer->unk68 &= ~2;
    }
    if ((temp_a0 & 0x20) && (extra_player_info_pointer->unkFC_s32 == 0) && ((gCurrentActorPointer->unk58 != ACTOR_RAMBI)) && (gCurrentActorPointer->unk58 != ACTOR_ENGUARDE)) {
        gCurrentActorPointer->unk68 |= 0x10;
    } else {
        gCurrentActorPointer->unk68 &= ~0x10;
        gCurrentActorPointer->object_properties_bitfield &= ~0x800;
    }
    if (extra_player_info_pointer->unkFC_s32 != 0) {
        extra_player_info_pointer->unkFC_s32--;
    }
    if (temp_a0 & 0x40) {
        gCurrentActorPointer->object_properties_bitfield |= 0x4000;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~0x4000;
    }
    if ((temp_a0 & 0x80) && (extra_player_info_pointer->unk100 == 0) && ((gCurrentActorPointer->unk58 != ACTOR_RAMBI)) && (gCurrentActorPointer->unk58 != ACTOR_ENGUARDE)) {
        gCurrentActorPointer->unk68 |= 0x20;
    } else {
        gCurrentActorPointer->unk68 &= ~0x20;
    }
    if (extra_player_info_pointer->unk100 != 0) {
        extra_player_info_pointer->unk100--;
    }
    if (extra_player_info_pointer->unk245 != 0) {
        extra_player_info_pointer->unk245--;
    }
    func_global_asm_806CB53C();
    func_global_asm_806CA2E4();
    func_global_asm_806CA540();
    if ((D_global_asm_80770561 == 0x6B) && (gCurrentActorPointer->control_state != 0x6E)) {
        func_global_asm_80602B60(0x6B, 0U);
    }
    if (extra_player_info_pointer->unkCA != 0) {
        extra_player_info_pointer->unkCA--;
    }
    if (gCurrentActorPointer->unk68 & 0x20) {
        func_global_asm_8072F120();
    }
    func_global_asm_806F4D70(cc_player_index,
        gCurrentActorPointer->x_position,
        gCurrentActorPointer->y_position,
        gCurrentActorPointer->z_position,
        (gCurrentActorPointer->animation_state->scale[1] / 0.15) * 20.0);
    if (cc_number_of_players == 1) {
        if (gCurrentActorPointer->unk64 & 0x1000) {
            gCurrentActorPointer->unk64 |= 0x200;
        }
    }
    gCurrentActorPointer->unk64 &= ~0x1000;
    D_global_asm_80750B50[gCurrentActorPointer->control_state].unk0();
    extra_player_info_pointer->unk8D = func_global_asm_80666A88();
    if (cc_number_of_players == 1) {
        gCurrentActorPointer->unk64 &= ~0x200;
    }
    if ((extra_player_info_pointer->unk1F0 & 0x01000000) && (D_global_asm_807FBB70.unk1C != 0) && (gCurrentActorPointer->control_state != 0x47)) {
        setAction(3, NULL, cc_player_index);
    }
    sp6B = func_global_asm_80666AA0();
    sp6A = func_global_asm_80666A94();
    sp69 = func_global_asm_80666AAC();
    sp68 = func_global_asm_80666AB8();
    if (gCurrentActorPointer->unk68 & 0x10) {
        func_global_asm_806CF9CC();
    }
    extra_player_info_pointer->unkE8 = 0;
    extra_player_info_pointer->unk1F0 &= ~0x40000000;
    func_global_asm_806CF580();
    extra_player_info_pointer->unk0 = gCurrentPlayer->control_state;
    if (cc_number_of_players >= 2) {
        if (gCurrentActorPointer->unk6A & 1) {
            if (extra_player_info_pointer->unk24A != 0) {
                extra_player_info_pointer->unk24A--;
            } else {
                extra_player_info_pointer->unk248 = -1;
                extra_player_info_pointer->unk249 = 0;
            }
        }
        func_global_asm_806CA26C();
        if ((extra_player_info_pointer->unk248 >= 0) && (extra_player_info_pointer->unk248 != extra_player_info_pointer->unk1A4)) {
            sp64 = character_change_array[extra_player_info_pointer->unk248].playerPointer;
        } else {
            if (extra_player_info_pointer->unk249 > 0) {
                sp64 = getSpawnerTiedActor(extra_player_info_pointer->unk249, 0U);
            }
        }
        if (D_global_asm_807552E4.unk0 == 0) {
            if (gCurrentPlayer->control_state == 0x3C) {
                if (extra_player_info_pointer->unk250 != 0) {
                    extra_player_info_pointer->unk250--;
                }
                temp_v1 = extra_player_info_pointer->unk254;
                if (!temp_v1) {
                    func_global_asm_807149FC(-1);
                    func_global_asm_80714998(0U);
                    changeActorColor(0xFFU, 0xFFU, 0xFFU, 0x78U);
                    func_global_asm_8071495C();
                    extra_player_info_pointer->unk254 = drawSpriteAtPosition(
                        &D_global_asm_80720020,
                        0.7f,
                        gCurrentPlayer->position.x,
                        gCurrentPlayer->position.y,
                        gCurrentPlayer->position.z);
                }
            } else {
                if (extra_player_info_pointer->unk250 < 0x78) {
                    extra_player_info_pointer->unk250++;
                }
                temp_v1 = extra_player_info_pointer->unk254;
                if (temp_v1) {
                    extra_player_info_pointer->unk254 = 0;
                    func_global_asm_80715908(temp_v1);
                }
            }
            var_a1 = extra_player_info_pointer->unk254;
            if (var_a1) {
                getBonePosition(gCurrentPlayer, 1, &x0, &y0, &z0);
                func_global_asm_80626F8C(x0, y0, z0, &xs0, &ys0, 0, 1.0f, 0);
                var_a1->xPos = xs0 * 4.0f;
                var_a1->yPos = ys0 * 4.0f;
                var_a1->zPos = 5.0f;
                var_a1->xScale = (
                    (1000.0f / sqrtf(
                        SQ(character_change_array->look_at_eye_z - z0) +
                        (SQ(character_change_array->look_at_eye_x - x0) +
                        SQ(character_change_array->look_at_eye_y - y0))
                    ))) *
                    gCurrentActorPointer->animation_state->scale[0] *
                    6.666666666666667 * 0.7 * 0.008333333767950535 *
                    (f32)extra_player_info_pointer->unk250;
                var_a1->yScale = var_a1->xScale;
            }
        }
    }
    if (extra_player_info_pointer->unkD4 != 0) {
        extra_player_info_pointer->unkD4--;
    }
    if (sp6A != 0) {
        setAction(0x3F, sp64, cc_player_index);
    }
    switch (sp6B) {
        default:
            extra_player_info_pointer->unkD6 = 0;
            break;
        case 1:
            if (extra_player_info_pointer->unk1F0 & 0x10) {
                extra_player_info_pointer->unkD6 = 0;
            } else {
                extra_player_info_pointer->unkD6++;
                setAction(0x2E, sp64, cc_player_index);
                if ((gCurrentActorPointer->control_state != 0x36) && (gCurrentActorPointer->control_state != 0x3B) && (extra_player_info_pointer->unkD4 == 0)) {
                    var_a1_2 = 0x2C0;
                    if (current_map == MAP_FUNGI) {
                        var_a1_2 = 0x3B0;
                    }
                    playSoundAtActorPosition(gCurrentActorPointer, var_a1_2, 0xFFU, 0x7F, 0U);
                }
            }
            break;
        case 2:
            extra_player_info_pointer->unk1F0 |= 0x1000;
            if (!(extra_player_info_pointer->unk1F0 & 0x10)) {
                if ((gCurrentActorPointer->control_state != 0x36) && (gCurrentActorPointer->control_state != 0x3B) && (extra_player_info_pointer->unkD4 == 0)) {
                    playSoundAtActorPosition(gCurrentActorPointer, 0x2C0, 0xFFU, 0x7F, 0U);
                }
                if ((current_map == MAP_FUNGI_DOGADON) || (current_map == MAP_AZTEC_DOGADON)) {
                    setAction(0x40, sp64, cc_player_index);
                } else {
                    setAction(0x30, sp64, cc_player_index);
                }
            }
            break;
    }
    if (sp69 != 0) {
        setAction(0, sp64, cc_player_index);
        if (extra_player_info_pointer->unkD4 == 0) {
            playSoundAtActorPosition(gCurrentActorPointer, 0x2C0, 0xFFU, 0x7F, 0U);
        }
    }
    getBonePosition(
        gCurrentPlayer, 6,
        &character_change_array[cc_player_index].unk2B4.x,
        &character_change_array[cc_player_index].unk2B4.y,
        &character_change_array[cc_player_index].unk2B4.z);
    func_global_asm_80626F8C(
        gCurrentPlayer->x_position,
        character_change_array[cc_player_index].unk2B4.y,
        gCurrentPlayer->z_position, &xs, &ys, 0, 1.0f, cc_player_index);
    extra_player_info_pointer->unk10E = xs;
    extra_player_info_pointer->unk110 = ys;
    a = gCurrentPlayer;
    func_global_asm_80626F8C(
        a->position.x,
        a->position.y,
        a->position.z, &xs, &ys, 0, 1.0f, cc_player_index);
    extra_player_info_pointer->unk112 = ys;
    extra_player_info_pointer->unk1F8 = extra_player_info_pointer->unk1F0;
    if (extra_player_info_pointer->unk268 != 0) {
        extra_player_info_pointer->unk268--;
    }
    if (
        (
            (gCurrentActorPointer->x_position < D_807F5FE4) ||
            (gCurrentActorPointer->z_position < D_807F5FE6) ||
            (D_807F5FE8 < gCurrentActorPointer->x_position) ||
            (D_807F5FEA < gCurrentActorPointer->z_position) ||
            (sp68 != 0)
        ) && 
        (extra_player_info_pointer->unk244 == 0) && 
        (object_timer >= 0x65U) && 
        (!(D_global_asm_807FBB64 & 0x4000)) &&
        (current_map != MAP_AZTEC_BEETLE_RACE)
    ) {
        if (cc_number_of_players == 1) {
            if (isFlagSet(PERMFLAG_CUTSCENE_ISLES_FTCS, FLAG_TYPE_PERMANENT) == 0) {
                func_global_asm_805FF188(MAP_TRAINING_GROUNDS, 1U);
            }
            func_global_asm_80709464(cc_player_index);
            func_global_asm_805FF1B0(cc_player_index);
            extra_player_info_pointer->unk244 = 1;
        } else {
            func_multiplayer_80026D40(gCurrentActorPointer, (s32) cc_player_index);
        }
    }
    if (cc_player_index == 0) {
        switch (current_map) {
        case MAP_JAPES:
        case MAP_FACTORY:
        case MAP_GALLEON:
        case MAP_DK_ISLES_OVERWORLD:
        case MAP_AZTEC:
        case MAP_FUNGI:
        case MAP_CAVES:
        case MAP_CASTLE:
            if ((D_global_asm_8076A094 >= 0x5DD) && ((u8) extra_player_info_pointer->unk244 == 0)) {
                func_global_asm_805FF2F4();
                extra_player_info_pointer->unk244 = 1;
            }
            if ((D_global_asm_8076A098 >= 0x5DD) && !(global_properties_bitfield & 2) && ((u8) extra_player_info_pointer->unk244 == 0)) {
                func_global_asm_805FF2F4();
                extra_player_info_pointer->unk244 = 1;
            }
            if (((gCurrentActorPointer->unk88 != gCurrentActorPointer->x_position) || (gCurrentActorPointer->unk8C != gCurrentActorPointer->y_position) || (gCurrentActorPointer->unk90 != gCurrentActorPointer->z_position) || ((D_global_asm_807FD610[cc_player_index].unk2A != 0)) || (D_global_asm_807FD610[cc_player_index].unk2E != 0) || (D_global_asm_807FD610[cc_player_index].unk2F != 0)) && !(global_properties_bitfield & 2)) {
                D_global_asm_8076A090++;
                if (D_global_asm_8076A090 == 0x69780) {
                    func_global_asm_805FF2F4();
                    extra_player_info_pointer->unk244 = 1;
                }
            }
            break;
        }
    }
}
*/


void func_global_asm_806CB53C(void) {
    s32 phi_s0;
    f32 phi_f0;

    if (((gCurrentPlayer->unk58 == ACTOR_RAMBI) || (gCurrentPlayer->unk58 == ACTOR_ENGUARDE)) && (extra_player_info_pointer->unk1FD != 0)) {
        if ((extra_player_info_pointer->unk1F0 & 0x800) && extra_player_info_pointer->unk23E == 0) {
            extra_player_info_pointer->unk23E = 0x1E;
            func_global_asm_80687400();
        }
        if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS) && (D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && extra_player_info_pointer->unk23E == 0) {
            extra_player_info_pointer->unk23E = 0x1E;
        }
        if (extra_player_info_pointer->unk23E != 0) {
            func_global_asm_80714950(RandClamp(10) + 0x8008);
            func_global_asm_807149FC(2);
            func_global_asm_8071498C(func_global_asm_80717930);
            func_global_asm_807149B8(1);
            func_global_asm_80714A28(6);
            func_global_asm_80714C08(&D_global_asm_8071FFA0, (RandClamp(50) / 80.0) + 0.5, gCurrentActorPointer, 2, 0);
            extra_player_info_pointer->unk23E--;
        }
        if (extra_player_info_pointer->unk23E == 1) {
            setAction(0x3B, NULL, cc_player_index);
            extra_player_info_pointer->unk1FD = 0;
        }
    } else {
        extra_player_info_pointer->unk23E = 0;
    }
    extra_player_info_pointer->unk1F0 &= ~0x800;
    if ((character_change_array[cc_player_index].unk2C0 != 1) || (extra_player_info_pointer->unk1F0 & 0x30)) {
        if ((extra_player_info_pointer->unk1F0 & 0x80000000) && extra_player_info_pointer->unk23F == 0) {
            extra_player_info_pointer->unk23F = 0x1E;
            func_global_asm_80687400();
        }
        if (extra_player_info_pointer->unk23F) {
            extra_player_info_pointer->unk23F--;
        }
        if (extra_player_info_pointer->unk23F == 1) {
            D_global_asm_807FD610[cc_player_index].unk2C |= L_CBUTTONS;
            D_global_asm_807FD610[cc_player_index].unk2A |= Z_TRIG;
        }
        if (!(D_global_asm_80750B50[gCurrentActorPointer->control_state].unk4 & 0x300) && !(extra_player_info_pointer->unk1F0 & 0x14000) && !func_global_asm_8061CB50()) {
            if ((extra_player_info_pointer->unk1F4 & 0x10) == 0) {
                changeCollectableCount(5, extra_player_info_pointer->unk1A4, -1);
            }
        }
    } else {
        extra_player_info_pointer->unk23F = 0;
    }
    extra_player_info_pointer->unk1F0 &= 0x7FFFFFFF;
    if (((D_global_asm_807FD610[cc_player_index].unk2C & 2) && (D_global_asm_807FD610[cc_player_index].unk2A & 0x2000) && (cc_number_of_players == 1)) || !func_global_asm_806F8AD4(5, extra_player_info_pointer->unk1A4)) {
        if (!(extra_player_info_pointer->unk1F0 & 0x2000) && current_map != MAP_KROOL_FIGHT_CHUNKY_PHASE) {
            phi_s0 = FALSE;
            if (character_change_array[cc_player_index].unk2C0 != 1) {
                func_global_asm_806D0468(gCurrentPlayer, 1);
                phi_s0 = TRUE;
                if (extra_player_info_pointer->unk1AC != 0) {
                    if (gCurrentPlayer->unk58 == ACTOR_CHUNKY && gCurrentPlayer->control_state != 0x4A) {
                        gCurrentPlayer->control_state = 0x4A;
                        gCurrentPlayer->control_state_progress = 0;
                        playActorAnimation(gCurrentPlayer, 0x1CD);
                    }
                }
            }
            if (extra_player_info_pointer->unk1F0 & 0x10) {
                extra_player_info_pointer->unk1F0 &= ~0x10;
                gCurrentPlayer->object_properties_bitfield |= 0x8000;
                gCurrentPlayer->shadow_opacity = 0xFF;
                phi_s0 = TRUE;
            }
            if (extra_player_info_pointer->unk1F0 & 0x20) {
                extra_player_info_pointer->unk1F0 &= ~0x20;
                func_global_asm_806D0408();
                phi_s0 = TRUE;
            }
            if (phi_s0) {
                func_global_asm_806C9F74(gCurrentActorPointer);
            }
        }
    }
    if (extra_player_info_pointer->unk1F0 & 0x10) {
        extra_player_info_pointer->unkD4 = 2;
    }
    if (extra_player_info_pointer->unk1CC != extra_player_info_pointer->unk1C0) {
        gCurrentActorPointer->unk64 |= 0x800;
        switch (gCurrentActorPointer->unk58) {
            case ACTOR_TINY:
                gCurrentActorPointer->unk120 = 0.15f;
                break;
            case ACTOR_CHUNKY:
                gCurrentActorPointer->unk120 = 0.3f;
                break;
            default:
                gCurrentActorPointer->unk120 = 0.15f;
                break;
        }
        func_global_asm_806D06A0();
    } else {
        gCurrentActorPointer->unk64 &= ~0x800;
    }
    if (extra_player_info_pointer->unk1F0 & 0x40) {
        if (gCurrentActorPointer->unk58 != ACTOR_CHUNKY) {
            gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
            gCurrentActorPointer->shadow_opacity -= 4;
            if (gCurrentActorPointer->shadow_opacity < 100) {
                gCurrentActorPointer->shadow_opacity = 100;
            }
        }
        if (extra_player_info_pointer->unk1FE != -1) {
            extra_player_info_pointer->unk1FE -= 1;
            if (!(extra_player_info_pointer->unk1FE & 7)) {
                func_global_asm_8071498C(func_global_asm_80716FB4);
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(3);
                drawSpriteAtPosition(&D_global_asm_8071FB08, 1.0f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
            }
            if (extra_player_info_pointer->unk1FE == 0) {
                func_global_asm_80602B60(0x6C, 0);
                gCurrentActorPointer->object_properties_bitfield |= 0x8000;
                func_global_asm_806F12FC(gCurrentActorPointer);
            }
        }
    }
    if (extra_player_info_pointer->unk200 != 0) {
        if ((extra_player_info_pointer->unk1F0 * 0x10) < 0) {
            phi_f0 = 1.0f;
            if (extra_player_info_pointer->unk200 >= 2) {
                phi_f0 = 0.5f;
            }
            extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584] * phi_f0;
            extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584] * phi_f0;
            extra_player_info_pointer->unk48 = D_global_asm_8075326C[D_global_asm_807FD584] * phi_f0;
        }
        if ((gCurrentActorPointer->control_state != 0x7C) || (gCurrentActorPointer->control_state == 0x7C && extra_player_info_pointer->unk200 == 1)) {
            extra_player_info_pointer->unk200--;
        }
        if (extra_player_info_pointer->unk200 == 0) {
            extra_player_info_pointer->unk1F0 &= 0xF7FFFF7F;
            if (gCurrentActorPointer->control_state == 0x7C) {
                func_global_asm_806CFF9C(gCurrentActorPointer);
            }
        }
    }
    if ((extra_player_info_pointer->unk1F0 & 0x20) || (is_autowalking == 3)) {
        if (current_map == MAP_FUNGI) {
            extra_player_info_pointer->unk38 = 200.0f;
        } else {
            extra_player_info_pointer->unk38 = D_global_asm_80753218[D_global_asm_807FD584];
        }
    }
}

void func_global_asm_806CBE44(void) {
    if ((D_global_asm_807FBB70.unk2 != 0) && (D_global_asm_807FBB70.unk14 == 1)) {
        setAction(0x20, NULL, cc_player_index);
    }
}

void func_global_asm_806CBE90(void) {
    if ((gCurrentActorPointer->unk6A & 0x21) == 1) {
        if ((gCurrentActorPointer->unk6A & 0x200) != 0) {
            if (gCurrentActorPointer->unk6E[0] == -1) {
                func_global_asm_80604CBC(gCurrentActorPointer, 0x10D, 0, 1, 0, 0xFF, 1.0f, 0);
            }
            gCurrentActorPointer->control_state = 0xF;
            gCurrentActorPointer->control_state_progress = 0;
            gCurrentActorPointer->terminal_velocity = -900.0f;
            extra_player_info_pointer->unk48 = D_global_asm_8075326C[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
            extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584];
            playAnimation(gCurrentActorPointer, 0x5E);
            gCurrentActorPointer->unk6A |= 0x20;
            func_global_asm_80614D90(gCurrentActorPointer);
        } else if ((gCurrentActorPointer->unkE0 != 0.0f) && (extra_player_info_pointer->unkC2 >= 0x15) && (gCurrentActorPointer->control_state != 0x17)) {
            if (func_global_asm_806CC14C(gCurrentActorPointer->unkD8, gCurrentActorPointer->y_rotation) < 0x200) {
                if (D_global_asm_80750B50[gCurrentPlayer->control_state].unk4 & 0x200) {
                    func_global_asm_806EAB44(gCurrentActorPointer, 0);
                }
                setAction(0x21, NULL, cc_player_index);
            } else if ((func_global_asm_806CC14C(gCurrentActorPointer->unkD8, gCurrentActorPointer->unkEE) < 0x400) || (gCurrentActorPointer->unkB8 < 15.0f)) {
                if (D_global_asm_80750B50[gCurrentPlayer->control_state].unk4 & 0x200) {
                    func_global_asm_806EAB44(gCurrentActorPointer, 0);
                }
                setAction(0x22, NULL, cc_player_index);
            }
        }
    }
}

s16 func_global_asm_806CC10C(s16 arg0, s16 arg1) {
    s16 temp_t2 = (arg1 - arg0);
    temp_t2 &= 0xFFF;
    if (temp_t2 >= 0x801) {
        temp_t2 -= 0x1000;
    }
    return temp_t2;
}

s16 func_global_asm_806CC14C(s16 arg0, s16 arg1) {
    s16 phi_v1 = (arg1 - arg0);
    phi_v1 &= 0xFFF;
    if (phi_v1 >= 0x801) {
        phi_v1 = 0x1000 - phi_v1;
    }
    return phi_v1;
}

// TODO: Clean this up with the ABS macro if possible
s16 func_global_asm_806CC190(s16 arg0, s16 arg1, f32 arg2) {
    s16 temp_v0;
    s16 phi_v1;
    s16 phi_v0;

    temp_v0 = arg1 - arg0;
    if (temp_v0 > 0) {
        phi_v1 = temp_v0;
    } else {
        phi_v1 = -temp_v0;
    }
    if ((arg2 != 0.0f) && ((temp_v0 & 0xFFF) != 0)) {
        phi_v0 = temp_v0 >= 0 ? 1 : -1;
        if (phi_v1 >= 0x801) {
            phi_v1 = 0x1000 - phi_v1;
            phi_v0 = -phi_v0;
        }
        if (phi_v1 < arg2) {
            arg2 = phi_v1;
        }
        arg0 += (phi_v0 * (s16)(phi_v1 / arg2));
    }
    return arg0 & 0xFFF;
}

// TODO: Clean this up with the ABS macro if possible
s16 func_global_asm_806CC284(s16 arg0, s16 arg1, f32 arg2) {
    s16 phi_v1;
    s16 phi_v0;
    s16 temp_v0;

    temp_v0 = arg1 - arg0;
    if (temp_v0 > 0) {
        phi_v1 = temp_v0;
    } else {
        phi_v1 = -temp_v0;
    }
    if ((arg2 != 0) && (temp_v0 & 0xFFF) != 0) {
        phi_v0 = temp_v0 >= 0 ? 1 : -1;
        if (phi_v1 >= 0x801) {
            phi_v1 = 0x1000 - phi_v1;
            phi_v0 = -phi_v0;
        }
        arg0 += (phi_v0 * (s16)(phi_v1 * arg2));
    }
    return arg0 & 0xFFF;
}

void func_global_asm_806CC364(u8 arg0) {
    f32 sp1C;
    f32 phi_f12;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f12 = D_global_asm_80753A3C[D_global_asm_807FD584];
    } else {
        phi_f12 = D_global_asm_80753A4C[D_global_asm_807FD584];
    }
    sp1C = ABS(func_global_asm_80612794(gCurrentActorPointer->z_rotation) * phi_f12) + 1.5;
    sp1C += ABS(func_global_asm_80612790(gCurrentActorPointer->unkDA) * phi_f12);
    if (gCurrentActorPointer->distance_from_floor < sp1C) {
        if (gCurrentActorPointer->unkDA < 500) {
            gCurrentActorPointer->unkB8 = MIN(gCurrentActorPointer->unkB8, 50);
        }
        if (arg0 && gCurrentActorPointer->y_velocity < 0) {
            gCurrentActorPointer->y_velocity = 0;
        }
        if (phi_f12 < (gCurrentActorPointer->unkAC - gCurrentActorPointer->y_position)) {
            gCurrentActorPointer->y_position = gCurrentActorPointer->floor + sp1C;
        }
    }
}

void func_global_asm_806CC5DC(void) {
    gCurrentActorPointer->unkB8 = func_global_asm_806CD898(gCurrentActorPointer->unkB8, 0, D_global_asm_807539C0[D_global_asm_807FD584]);
    func_global_asm_806CC970();
    func_global_asm_806CC364(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CC638.s")

/*
// TODO: WIP, might need some more temp variables or split apart float operations into separate lines
void func_global_asm_806CC638(f32 arg0) {
    f32 sp34;
    f32 phi_f14;
    f32 phi_f2;
    f32 phi_f16;

    if (extra_player_info_pointer->unk10 != 0) {
        extra_player_info_pointer->unk10--;
        phi_f14 = extra_player_info_pointer->unk38 * -func_global_asm_80612794(extra_player_info_pointer->unk12);
        sp34 = extra_player_info_pointer->unk38 * func_global_asm_80612790(extra_player_info_pointer->unk12);
        if (extra_player_info_pointer->unk38 < gCurrentActorPointer->unkB8) {
            phi_f2 = extra_player_info_pointer->unk2C * 8.0f;
        } else {
            phi_f2 = extra_player_info_pointer->unk2C;
        }
    } else {
        phi_f14 = gCurrentActorPointer->unkB8 * -func_global_asm_80612794(gCurrentActorPointer->z_rotation);
        gCurrentActorPointer->y_velocity = func_global_asm_806CD898(gCurrentActorPointer->y_velocity, phi_f14, 2.0f);
        sp34 = 0.0f;
        phi_f2 = extra_player_info_pointer->unk30;
    }
    phi_f16 = 0.0f;
    if (phi_f14 >= 0.0f) {
        if ((gCurrentActorPointer->unkAC - gCurrentActorPointer->y_position) < D_global_asm_80753A2C[D_global_asm_807FD584]) {
            if (D_global_asm_80753A5C[D_global_asm_807FD584] > 0.0f) {
                phi_f16 = D_global_asm_80753A5C[D_global_asm_807FD584];
            } else {
                phi_f16 = -D_global_asm_80753A5C[D_global_asm_807FD584];
            }
        }
    }
    if ((gCurrentActorPointer->distance_from_floor == 0.0f) && (gCurrentActorPointer->y_velocity < -0.1)) {
        gCurrentActorPointer->y_velocity = -0.1f;
    }
    gCurrentActorPointer->y_velocity = func_global_asm_806CD898(gCurrentActorPointer->y_velocity, phi_f14 + phi_f16, 2.0 * phi_f2);
    gCurrentActorPointer->unkB8 = func_global_asm_806CD898(gCurrentActorPointer->unkB8, sp34, phi_f2);
    gCurrentActorPointer->unkEE = gCurrentActorPointer->y_rotation;
    func_global_asm_80665160(gCurrentActorPointer, gCurrentActorPointer->unkEE, gCurrentActorPointer->y_rotation);
    func_global_asm_806653C0(gCurrentActorPointer, gCurrentActorPointer->unkB8, gCurrentActorPointer->y_velocity);
    func_global_asm_80665564(gCurrentActorPointer, 0);
    func_global_asm_806CC364(0);
}
*/

void func_global_asm_806CC8A8(void) {
    D_global_asm_807FD586 = 1;
}

void func_global_asm_806CC8B8(void) {
    applyActorYAcceleration();
    func_global_asm_806CBE90();
    func_global_asm_806CCC54(1);
    func_global_asm_806CC970();
}

void func_global_asm_806CC8F0(void) {
    func_global_asm_806CBE90();
    func_global_asm_806CCC54(1);
    func_global_asm_806CC970();
}

void func_global_asm_806CC920(void) {
    func_global_asm_806CCC54(1);
    func_global_asm_806CC970();
}

void func_global_asm_806CC948(void) {
    applyActorYAcceleration();
    func_global_asm_806CC970();
}

void func_global_asm_806CC970(void) {
    f32 dx;
    f32 dz;
    s16 phi_a1;
    f64 phi_f2;

    func_global_asm_806CCC54(0);
    if (func_global_asm_806CC14C(gCurrentActorPointer->y_rotation, gCurrentActorPointer->unkEE) < 0x400) {
        phi_a1 = gCurrentActorPointer->y_rotation;
    } else {
        phi_a1 = (gCurrentActorPointer->y_rotation + 0x800) & 0xFFF;
    }
    func_global_asm_80665160(gCurrentActorPointer, phi_a1, phi_a1);
    func_global_asm_806651FC(gCurrentActorPointer);
    phi_f2 = MAX(-6, -extra_player_info_pointer->unkD6 * 0.125);
    func_global_asm_80665564(gCurrentActorPointer, phi_f2);
    gCurrentActorPointer->object_properties_bitfield |= 1;
    dx = gCurrentActorPointer->x_position - gCurrentActorPointer->unk88;
    dz = gCurrentActorPointer->z_position - gCurrentActorPointer->unk90;
    extra_player_info_pointer->unk20 = (((sqrtf(SQ(dx) + SQ(dz)) / D_global_asm_80744478) * 80.0) * 0.149999999999999994) / gCurrentActorPointer->animation_state->scale_x;
}

void applyActorYAcceleration(void) {
    if (extra_player_info_pointer->unk50 != 0) {
        extra_player_info_pointer->unk50--;
        return;
    }
    gCurrentActorPointer->y_velocity += gCurrentActorPointer->y_acceleration;
    if (gCurrentActorPointer->y_velocity < gCurrentActorPointer->terminal_velocity) {
        gCurrentActorPointer->y_velocity = gCurrentActorPointer->terminal_velocity;
    }
    if (-gCurrentActorPointer->terminal_velocity < gCurrentActorPointer->y_velocity) {
        gCurrentActorPointer->y_velocity = -gCurrentActorPointer->terminal_velocity;
    }
}

void func_global_asm_806CCB94(void) {
    f32 temp_f0 = func_global_asm_806DFFA0(extra_player_info_pointer->unk4, extra_player_info_pointer->unkA, gCurrentActorPointer->y_rotation);

    if (temp_f0 > 0.0f) {
        func_global_asm_806CD424(gCurrentActorPointer->y_rotation, temp_f0, extra_player_info_pointer->unk38);
    } else {
        func_global_asm_806CD8EC();
    }
}

s32 func_global_asm_806CCC10(void) {
    switch (gCurrentPlayer->control_state) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            return TRUE;
        default:
            return FALSE;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CCC54.s")

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CD424.s")

/*
void func_global_asm_806CD424(s16 arg0, f32 arg1, f32 arg2) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f16;
    f32 var_f16_2;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    s16 temp_a2;
    s16 temp_t2;
    s16 var_a0;

    if (gCurrentActorPointer->unkB8 == 0.0f) {
        gCurrentActorPointer->unkEE = arg0;
    }
    temp_a2 = gCurrentActorPointer->unkEE;
    sp1C = 0.0f;
    if (gCurrentActorPointer->unk6A & 1) {
        temp_t2 = (arg0 - temp_a2) & 0xFFF;
        var_f16 = (extra_player_info_pointer->unk2C * ((extra_player_info_pointer->unk26 * 3) + 0x64)) / 400.0f;
        if (extra_player_info_pointer->unk28 != 0) {
            var_a0 = temp_t2;
            if (temp_t2 >= 0x801) {
                var_a0 = 0x1000 - temp_t2;
            }
            sp1C = (extra_player_info_pointer->unk26 * (var_a0 / 2048.0f)) / 100.0f;
        }
    } else {
        var_f16 = extra_player_info_pointer->unk2C;
    }
    sp34 = func_global_asm_80612794(temp_a2) * gCurrentActorPointer->unkB8;
    temp_f2 = func_global_asm_80612794(arg0) * arg1;
    var_f16_2 = var_f16;
    sp30 = temp_f2;
    if (sp1C != 0.0f) {
        if (sp34 < temp_f2) {
            var_f0 = temp_f2 - sp34;
        } else {
            var_f0 = -(temp_f2 - sp34);
        }
        var_f2 = (((var_f0 * (((extra_player_info_pointer->unk26 * 63.0) + 100.0) / 6400.0)) - var_f16_2) * sp1C) + var_f16_2;
    } else {
        var_f2_2 = ABS(func_global_asm_80612794(arg0) * var_f16_2);
        sp24 = var_f2_2;
        if ((func_global_asm_80612790(arg0) * var_f16_2) > 0.0f) {
            var_f2 = var_f2_2;
            sp20 = func_global_asm_80612790(arg0) * var_f16_2;
        } else {
            var_f2 = var_f2_2;
            sp20 = -(func_global_asm_80612790(arg0) * var_f16_2);
        }
    }
    sp3C = func_global_asm_806CD898(sp34, sp30, var_f2);
    sp34 = func_global_asm_80612790(temp_a2) * gCurrentActorPointer->unkB8;
    sp30 = func_global_asm_80612790(arg0) * arg1;
    if (sp1C != 0.0f) {
        if (sp34 < sp30) {
            var_f0_2 = sp30 - sp34;
        } else {
            var_f0_2 = -(sp30 - sp34);
        }
        sp20 = (((var_f0_2 * (((extra_player_info_pointer->unk26 * 63.0) + 100.0) / 6400.0)) - var_f16_2) * sp1C) + var_f16_2;
    }
    sp38 = func_global_asm_806CD898(sp34, sp30, sp20);
    gCurrentActorPointer->unkB8 = sqrtf((sp3C * sp3C) + (sp38 * sp38));
    if (arg2 < gCurrentActorPointer->unkB8) {
        gCurrentActorPointer->unkB8 = arg2;
    }
    if (gCurrentActorPointer->unkB8 != 0.0) {
        gCurrentActorPointer->unkEE = (func_global_asm_80611BB4(sp3C, sp38) * 4096.0) / TWO_PI;
    }
}
*/

// boostSpeed()
f32 func_global_asm_806CD898(f32 currentSpeed, f32 desiredSpeed, f32 boostAmount) {
    if (currentSpeed < desiredSpeed) {
        currentSpeed += boostAmount;
        currentSpeed = MIN(desiredSpeed, currentSpeed);
    } else {
        currentSpeed -= boostAmount;
        currentSpeed = MAX(desiredSpeed, currentSpeed);
    }
    return currentSpeed;
}

void func_global_asm_806CD8EC(void) {
    u16 temp_v1;
    f32 phi_f0;

    if ((gCurrentActorPointer->unk6A & 1) && !(gCurrentActorPointer->unk6A & 0x200)) {
        phi_f0 = (extra_player_info_pointer->unk30 * ((extra_player_info_pointer->unk26 * 0xF) + 0x64)) / 1600.0f;
    } else {
        phi_f0 = extra_player_info_pointer->unk30;
    }
    gCurrentActorPointer->unkB8 -= phi_f0;
    if (gCurrentActorPointer->unkB8 < 0.0f) {
        gCurrentActorPointer->unkB8 = 0.0f;
    }
}

s16 func_global_asm_806CD988(Actor *arg0) {
    s16 temp = D_global_asm_80750B50[arg0->control_state].unk4;
    return temp;
}

s16 func_global_asm_806CD9A0(Actor *arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4) {
    f32 var_f0 = MAX(arg1, arg2);

    if ((arg0->unk6A | arg0->unk6C) & 1) {
        switch (arg3) {
            case 0:
            case 1:
            case 2:
                if (arg2 != 0.0f) {
                    if (arg2 < D_global_asm_8075318C[arg4]) {
                        arg3 = 3;
                    } else if (arg2 < D_global_asm_807531C4[arg4]) {
                        arg3 = 4;
                    } else {
                        arg3 = 5;
                    }
                }
                break;
            case 3:
                if ((arg2 == 0.0f) && (arg1 < D_global_asm_80753170[arg4])) {
                    arg3 = 0;
                } else if (D_global_asm_807531C4[arg4] < arg2) {
                    arg3 = 5;
                } else if (D_global_asm_8075318C[arg4] < arg2) {
                    arg3 = 4;
                }
                break;
            case 4:
                if (var_f0 < D_global_asm_807531A8[arg4]) {
                    if (arg2 < D_global_asm_80753170[arg4]) {
                        arg3 = 0;
                    } else {
                        arg3 = 3;
                    }
                } else if (D_global_asm_807531C4[arg4] < arg2) {
                    arg3 = 5;
                }
                break;
            case 5:
                if (var_f0 < D_global_asm_807531E0[arg4]) {
                    arg3 = 4;
                }
                break;
            default:
                if (arg1 < D_global_asm_80753170[arg4]) {
                    arg3 = 0;
                } else if (arg1 < D_global_asm_807531A8[arg4]) {
                    arg3 = 3;
                } else {
                    if (arg1 < D_global_asm_807531E0[arg4]) {
                        arg3 = 4;
                    } else {
                        arg3 = 5;
                    }
                }
                break;
        }
        if ((extra_player_info_pointer->unk1F0 & 0x100) && ((arg3 == 4) || (arg3 == 5))) {
            arg3 = 3;
        }
        if ((arg3 == 0) && ((current_map == MAP_FUNKYS_STORE) || (current_map == MAP_CRANKYS_LAB) || (current_map == MAP_CANDYS_MUSIC_SHOP) || (current_map == MAP_SNIDES_HQ))) {
            arg3 = 2;
        } else if ((arg3 == 0) && ((cc_number_of_players >= 2) || (extra_player_info_pointer->unk1F0 & 0x40) || !(arg0->object_properties_bitfield & 4) || (is_cutscene_active == 1))) {
            arg3 = 1;
        } else if ((arg3 == 1) && (cc_number_of_players < 2) && !(extra_player_info_pointer->unk1F0 & 0x40) && (arg0->object_properties_bitfield & 4) && (is_cutscene_active != 1)) {
            arg3 = 0;
        }
    } else {
        arg3 = 6;
    }
    return arg3;
}

s32 func_global_asm_806CDD24(Actor *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s16 var_v1;
    u8 pad[4];
    s16 sp2E;
    s16 sp2C;
    f32 var_f0;

    var_v1 = arg0->control_state;
    sp2E = extra_player_info_pointer->unk4C;
    sp2C = func_global_asm_806CD9A0(arg0, arg1, arg2, extra_player_info_pointer->unk4C, D_global_asm_807FD584);
    if (sp2C != 6) {
        arg0->y_velocity = 0.0f;
    }
    if (sp2E < 0) {
        func_global_asm_806D03BC();
    }
    if (sp2E != sp2C) {
        switch (sp2C) {
            case 0:
                if (extra_player_info_pointer->unk1F0 & 0x100) {
                    playActorAnimation(arg0, 0x1AD);
                } else {
                    playAnimation(arg0, 9);
                }
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                var_v1 = 0xC;
                break;
            case 1:
                if (extra_player_info_pointer->unk1F0 & 0x100) {
                    playActorAnimation(arg0, 0x1AD);
                } else {
                    playActorAnimation(arg0, 0x13);
                }
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                var_v1 = 0xC;
                break;
            case 2:
                playAnimation(arg0, 0x87);
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                var_v1 = 0xC;
                break;
            case 3:
                if (extra_player_info_pointer->unk1F0 & 0x100) {
                    playActorAnimation(arg0, 0x76);
                    func_global_asm_80613C48(arg0, 0x2AC, 0.0f, 6.0f);
                } else {
                    func_global_asm_80613AF8(arg0, 2, 0.0f, 6.0f);
                    playAnimation(arg0, 1);
                }
                switch (sp2E) {
                    case 4:
                    case 5:
                        func_global_asm_80613A50(arg0, 2);
                        break;
                }
                var_v1 = 0xD;
                break;
            case 4:
                playAnimation(arg0, 2);
                func_global_asm_80613AF8(arg0, 3, 0.0f, 6.0f);
                if (sp2E == 3) {
                    switch (current_character_index[cc_player_index]) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            func_global_asm_80613A50(arg0, 4);
                            break;
                    }
                }
                if (sp2E == 5) {
                    func_global_asm_80613A50(arg0, 2);
                }
                var_v1 = 0xD;
                break;
            case 5:
                playAnimation(arg0, 3);
                func_global_asm_80613AF8(arg0, 4, 0.0f, 6.0f);
                if ((sp2E == 3) || (sp2E == 4)) {
                    func_global_asm_80613A50(arg0, 4);
                }
                var_v1 = 0xD;
                break;
            case 6:
                playAnimation(arg0, 0x1B);
                func_global_asm_80614D90(arg0);
                var_v1 = 0x1E;
                gCurrentActorPointer->unk9C = gCurrentActorPointer->y_position;
                break;
        }
        extra_player_info_pointer->unk4C = sp2C;
    }
    if (extra_player_info_pointer->unk4C >= 3) {
        if (extra_player_info_pointer->unk26 == 0x64) {
            var_f0 = arg0->unkB8;
        } else {
            var_f0 = extra_player_info_pointer->unk4;
        }
        var_f0 *= 0.025;
        if (extra_player_info_pointer->unk4C == 5) {
            var_f0 *= 0.6;
        }
        if (var_f0 > 1.25f) {
            var_f0 = var_f0 - ((var_f0 - 1.25f) * 0.4);
        }
        if (arg0->animation_state->unk0->unk24 != 0.0f) {
            if (extra_player_info_pointer->unk26 == 0x64) {
                func_global_asm_80614D00(arg0, var_f0, 2.0f);
            } else {
                if (var_f0 < 0.5) {
                    var_f0 = 0.5f;
                }
                func_global_asm_80614D00(arg0, var_f0, 10.0f);
            }
        }
    }
    return var_v1;
}

u32 func_global_asm_806CE174(Actor *actor, f32 arg1, f32 arg2, s32 arg3) {
    s16 sp36;
    f32 var_f0;
    s16 sp2E;
    s16 sp2C;

    sp36 = actor->control_state;
    sp2E = extra_player_info_pointer->unk4C;
    sp2C = func_global_asm_806CD9A0(actor, arg1, arg2, extra_player_info_pointer->unk4C, D_global_asm_807FD584);
    actor->y_velocity = 0.0f;
    if (sp2E < 0) {
        func_global_asm_806D03BC();
    }
    if (sp2E != sp2C) {
        switch (sp2C) {
            case 0:
                playAnimation(actor, 0x51);
                func_global_asm_80614D00(actor, 1.0f, 0.0f);
                sp36 = 0x5D;
                break;
            case 1:
                playActorAnimation(actor, 0x23);
                func_global_asm_80614D00(actor, 1.0f, 0.0f);
                sp36 = 0x5D;
                break;
            case 3:
                playAnimation(actor, 0x57);
                func_global_asm_80613AF8(actor, 0x5C, 0, 6.0f);
                if (sp2E == 4 || sp2E == 5) {
                    func_global_asm_80613A50(actor, 2);
                }
                sp36 = 0x5E;
                break;
            case 4:
                playAnimation(actor, 0x56);
                func_global_asm_80613AF8(actor, 0x58, 0, 6.0f);
                if (sp2E == 3) {
                    switch (current_character_index[cc_player_index]) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            func_global_asm_80613A50(actor, 4);
                            break;
                    }
                }
                if (sp2E == 5) {
                    func_global_asm_80613A50(actor, 0xA);
                }
                sp36 = 0x5E;
                break;
            case 5:
                playAnimation(actor, 0x55);
                func_global_asm_80613AF8(actor, 0x60, 0, 6.0f);
                switch (current_character_index[cc_player_index]) {
                    case 4:
                    case 5:
                        if (sp2E == 3) {
                            func_global_asm_80613A50(actor, 8);
                        }
                        break;
                    default:
                        if ((sp2E == 3) || (sp2E == 4)) {
                            func_global_asm_80613A50(actor, 0);
                        }
                        break;
                }
                sp36 = 0x5E;
                break;
            case 6:
                playAnimation(actor, 0x58);
                func_global_asm_80614D90(actor);
                sp36 = 0x1F;
                gCurrentActorPointer->unk9C = gCurrentActorPointer->y_position;
                break;
        }
        extra_player_info_pointer->unk4C = sp2C;
    }
    if (extra_player_info_pointer->unk4C >= 3) {
        var_f0 = actor->unkB8;
        var_f0 *= 0.025;
        if (extra_player_info_pointer->unk4C == 5) {
            var_f0 *= 0.6;
        }
        if (var_f0 > 1.25f) {
            var_f0 -= ((var_f0 - 1.25f) * 0.4);
        }
        if (actor->animation_state->unk0->unk24 != 0.0f) {
            func_global_asm_80614D00(actor, var_f0, 2.0f);
        }
    }
    return sp36;
}

s16 func_global_asm_806CE4E4(Actor *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s16 sp36;
    f32 var_f0;
    s16 sp2E;
    s16 sp2C;

    sp36 = arg0->control_state;
    sp2E = extra_player_info_pointer->unk4C;
    sp2C = func_global_asm_806CE7A0(arg0, arg1, arg2, extra_player_info_pointer->unk4C, D_global_asm_807FD584);
    arg0->y_velocity = 0.0f;
    if (sp2E < 0) {
        func_global_asm_806D0408();
    }
    if (sp2E != sp2C) {
        switch (sp2C) {
            case 0:
            case 1:
            case 2:
                playActorAnimation(arg0, 0x150);
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                sp36 = 0x3F;
                break;
            case 4:
                playActorAnimation(arg0, 0x151);
                func_global_asm_80613C48(arg0, 0x163, 0.0f, 6.0f);
                if (sp2E == 5) {
                    func_global_asm_80613A50(arg0, 4);
                }
                sp36 = 0x40;
                break;
            case 5:
                playActorAnimation(arg0, 0x152);
                func_global_asm_80613C48(arg0, 0x162, 0.0f, 6.0f);
                if (sp2E == 4) {
                    func_global_asm_80613A50(arg0, 0xC);
                }
                sp36 = 0x40;
                break;
            case 6:
                playAnimation(arg0, 0x1B);
                func_global_asm_80614D90(arg0);
                sp36 = 0x1E;
                gCurrentActorPointer->unk9C = gCurrentActorPointer->y_position;
                break;
        }
        extra_player_info_pointer->unk4C = sp2C;
    }
    if (extra_player_info_pointer->unk4C >= 3) {
        if (extra_player_info_pointer->unk26 == 0x64) {
            var_f0 = arg0->unkB8;
        } else {
            var_f0 = extra_player_info_pointer->unk4;
        }
        var_f0 *= 0.025;
        if (extra_player_info_pointer->unk4C == 5) {
            var_f0 *= 0.6;
        }
        if (var_f0 > 1.25f) {
            var_f0 -= ((var_f0 - 1.25f) * 0.4);
        }
        if (arg0->animation_state->unk0->unk24 != 0.0f) {
            if (extra_player_info_pointer->unk26 == 0x64) {
                func_global_asm_80614D00(arg0, var_f0, 2.0f);
            } else {
                if (var_f0 < 0.5) {
                    var_f0 = 0.5f;
                }
                func_global_asm_80614D00(arg0, var_f0, 10.0f);
            }
        }
    }
    return sp36;
}

s32 func_global_asm_806CE7A0(Actor *arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4) {
    f32 var_f0;

    var_f0 = MAX(arg1, arg2);
    if ((arg0->unk6A | arg0->unk6C) & 1) {
        switch (arg3) {
            case 0:
            case 1:
            case 2:
                if (arg2 != 0.0f) {
                    if (arg2 < D_global_asm_807531C4[arg4]) {
                        arg3 = 4;
                    } else {
                        arg3 = 5;
                    }
                }
                break;
            case 4:
                if (arg2 < D_global_asm_80753170[arg4]) {
                    arg3 = 0;
                } else if (D_global_asm_807531C4[arg4] < arg2) {
                    arg3 = 5;
                }
                break;
            case 5:
                if (var_f0 < D_global_asm_807531E0[arg4]) {
                    arg3 = 4;
                }
                break;
            default:
                if (arg1 < D_global_asm_80753170[arg4]) {
                    arg3 = 0;
                } else if (arg1 < D_global_asm_807531E0[arg4]) {
                    arg3 = 4;
                } else {
                    arg3 = 5;
                }
                break;
        }
    } else {
        arg3 = 6;
    }
    return arg3;
}

s16 func_global_asm_806CE928(Actor *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s16 sp26;
    f32 temp;
    s16 sp1E;
    s16 sp1C;

    sp26 = arg0->control_state;
    sp1E = extra_player_info_pointer->unk4C;
    sp1C = func_global_asm_806CEB44(arg1, arg2);
    if (sp1E < 0) {
        func_global_asm_806D03BC();
    }
    if (sp1E != sp1C) {
        switch (sp1C) {
            case 0:
                switch ((u32)extra_player_info_pointer->unk1AC->unk58) {
                    case ACTOR_BOULDER:
                    case ACTOR_VASE_OVAL:
                    case ACTOR_VASE_DOTS:
                    case ACTOR_VASE_TRIANGLE:
                    case ACTOR_VASE_PLUS:
                    case ACTOR_STEEL_KEG:
                    case ACTOR_APPLE:
                        playActorAnimation(gCurrentPlayer, 0x1C9);
                        break;
                    default:
                        playAnimation(arg0, 0x2E);
                        break;
                }
                extra_player_info_pointer->unk4C = 0;
                sp26 = 0x48;
                break;
            case 1:
                switch ((u32)extra_player_info_pointer->unk1AC->unk58) {
                    case ACTOR_BOULDER:
                    case ACTOR_VASE_OVAL:
                    case ACTOR_VASE_DOTS:
                    case ACTOR_VASE_TRIANGLE:
                    case ACTOR_VASE_PLUS:
                    case ACTOR_CANNON_BALL:
                    case ACTOR_STEEL_KEG:
                    case ACTOR_APPLE:
                        playActorAnimation(gCurrentPlayer, 0x1CA);
                        break;
                    default:
                        playAnimation(arg0, 0x2F);
                        break;
                }
                extra_player_info_pointer->unk4C = 1;
                sp26 = 0x49;
                break;
        }
    }
    if (extra_player_info_pointer->unk4C > 0) {
        temp = arg0->unkB8 * 0.025;
        temp = 0.25 + (temp * 0.75);
        if (arg0->animation_state->unk0->unk24 != 0) {
            func_global_asm_80614D00(arg0, temp, 2.0f);
        }
    }
    return sp26;
}

s32 func_global_asm_806CEB44(f32 arg0, f32 arg1) {
    s32 phi_v1;

    phi_v1 = extra_player_info_pointer->unk4C;
    switch (phi_v1) {
        case 0:
            if (arg1 != 0.0f) {
                phi_v1 = 1;
            }
            break;
        case 1:
            if (arg1 == 0.0f) {
                if (arg0 < D_global_asm_807532B8[D_global_asm_807FD584]) {
                    phi_v1 = 0;
                }
            }
            break;
        default:
            if (arg0 < D_global_asm_807532B8[D_global_asm_807FD584]) {
                phi_v1 = 0;
            } else {
                phi_v1 = 1;
            }
    }

    return phi_v1;
}

// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CEC04.s")

extern s16 D_global_asm_807532A8[];

/*
void func_global_asm_806CEC04(Actor *arg0) {
    f32 sp84;
    s16 temp_f0;
    f32 sp40[4][4];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 var_f2;

    switch ((u32)arg0->unk58) {
        case 0x3D:
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x55:
        case 0x82:
            sp84 = 30.0f;
            break;
        default:
            sp84 = D_global_asm_807532A8[D_global_asm_807FD584];
            break;
    }
    if (extra_player_info_pointer->unk1F0 & 0x01000000) {
        var_f2 = (gCurrentActorPointer->y_rotation * 0x168) / 4096;
    } else {
        var_f2 = 360.0 - func_global_asm_80665AE4((s16)arg0->x_position, (s16)arg0->z_position, (s16)gCurrentActorPointer->x_position, (s16)gCurrentActorPointer->z_position);
    }
    extra_player_info_pointer->unk80 = (var_f2 * 4095.0) / 360.0;
    guRotateF(&sp40, var_f2, 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp40, 0, 0, sp84, &sp3C, &sp38, &sp34);
    temp_f0 = 0xF;
    extra_player_info_pointer->unk78 = (((arg0->x_position - sp3C) - gCurrentActorPointer->x_position) / temp_f0);
    extra_player_info_pointer->unk7C = (((arg0->z_position - sp34) - gCurrentActorPointer->z_position) / temp_f0);
}
*/

void func_global_asm_806CEE64(f32 arg0) {
    GlobalASMStruct61 *temp_v0;

    if (extra_player_info_pointer->unk1AC != 0) {
        temp_v0 = malloc(sizeof(GlobalASMStruct61));
        temp_v0->unk0 = func_global_asm_806CEFBC;
        temp_v0->unk8 = arg0;
        temp_v0->unkC = gCurrentActorPointer;
        temp_v0->unk10 = extra_player_info_pointer->unk1AC;
        temp_v0->unk4 = 0;
        func_global_asm_80679064(temp_v0);
    }
}

void func_global_asm_806CEED8(void) {
    f32 x2, x1;
    f32 y2, y1;
    f32 z2, z1;
    f32 dxz;
    f32 dy;
    s32 boneIndex1;
    s32 boneIndex2;

    func_global_asm_806CF2EC(&boneIndex1, &boneIndex2);
    getBonePosition(gCurrentActorPointer, boneIndex1, &x1, &y1, &z1);
    getBonePosition(gCurrentActorPointer, boneIndex2, &x2, &y2, &z2);
    dy = y2 - y1;
    dxz = sqrtf(((z2 - z1) * (z2 - z1)) + ((x2 - x1) * (x2 - x1)));
    extra_player_info_pointer->unk1BC = ((0.0 - (func_global_asm_80611BB4(dy, dxz) * 57.29577637f)) + 270.0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CEFBC.s")

/*
void func_global_asm_806CEFBC(Struct806CEFBC *arg0) {
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp34;
    s32 sp30;
    f32 temp_f10;
    f32 temp_f6;
    f32 temp_f8;

    func_global_asm_806CF2EC(&sp34, &sp30);
    getBonePosition(arg0->unk4, sp34, &sp60, &sp58, &sp50);
    getBonePosition(arg0->unk4, sp30, &sp64, &sp5C, &sp54);
    temp_f10 = ((((sp64 + sp60) / 2.0f) - arg0->unk8->x_position) * arg0->unk0) + arg0->unk8->x_position;
    temp_f6 = ((((sp5C + sp58) / 2.0f) - arg0->unk8->y_position) * arg0->unk0) + arg0->unk8->y_position;
    temp_f8 = ((((sp54 + sp50) / 2.0f) - arg0->unk8->z_position) * arg0->unk0) + arg0->unk8->z_position;
    func_global_asm_8067A70C(arg0->unk4, arg0->unk8, temp_f10, temp_f6, temp_f8, 2, 1);
}
*/

void func_global_asm_806CF0D0(void) {
    GlobalASMStruct62 *temp_v0;

    if (extra_player_info_pointer->unk1AC != 0) {
        temp_v0 = malloc(sizeof(GlobalASMStruct62));
        temp_v0->unk0 = func_global_asm_806CF138;
        temp_v0->unk8 = gCurrentActorPointer;
        temp_v0->unkC = extra_player_info_pointer->unk1AC;
        temp_v0->unk4 = 0;
        func_global_asm_80679064(temp_v0);
    }
}

// progress made, doable, float
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CF138.s")

/*
void func_global_asm_806CF138(Struct806CF138 *arg0) {
    f32 x2;
    f32 x1;
    f32 y2;
    f32 y1;
    f32 z2;
    f32 z1;
    f32 dy;
    f32 dx;
    f32 sp54;
    f32 pad;
    f32 sp4C;
    f32 sp48;
    f32 dz;
    f32 sp3C;
    f32 sp38;
    s32 boneIndex1;
    s32 boneIndex2;

    func_global_asm_806CF2EC(&boneIndex1, &boneIndex2);
    getBonePosition(arg0->unk0, boneIndex1, &x1, &y1, &z1);
    getBonePosition(arg0->unk0, boneIndex2, &x2, &y2, &z2);
    dx = (x2 - x1);
    dy = (y2 - y1);
    dz = (z2 - z1);
    sp54 = func_global_asm_806118FC(dy / sqrtf(SQ(dx) + SQ(dy) + SQ(dz))) * 57.29577637f;
    sp48 = func_global_asm_80612794(arg0->unk0->y_rotation) * 50.0f;
    sp4C = func_global_asm_80612790(arg0->unk0->y_rotation) * 50.0f;
    dx = (x2 - x1);
    sp3C = (dz * sp4C) + (sp48 * dx);
    sp38 = sqrtf((sp4C * sp4C) + (sp48 * sp48));
    func_global_asm_8067AA58(arg0->unk0, arg0->unk4, sp54, 90.0 - (func_global_asm_80611850(sp3C / (sp38 * sqrtf(SQ(dz) + SQ(dx)))) * 57.29577637f));
}
*/

void func_global_asm_806CF2EC(s32 *arg0, s32 *arg1) {
    s32 var_v0;
    u16 temp_v1;

    var_v0 = 0;
    if (gCurrentActorPointer->unk58 == ACTOR_CHUNKY) {
        switch (extra_player_info_pointer->unk1B8) {
            case 0x82:
                *arg0 = 0x13;
                *arg1 = 0x14;
                var_v0 = 1;
                break;
            case 0x3D:
            case 0x3F:
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x55:
                *arg0 = 0x12;
                *arg1 = 0x11;
                var_v0 = 1;
                break;
        }
    }
    if (var_v0 == 0) {
        *arg0 = 2;
        *arg1 = 3;
    }
}

void func_global_asm_806CF398(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;

    if (arg0->interactable & 1) {
        PaaD = arg0->PaaD;
        if (PaaD->unk1AC) {
            func_global_asm_8067A784(gCurrentActorPointer, PaaD->unk1AC, gCurrentPlayer->y_rotation, D_global_asm_80753428[D_global_asm_807FD584], D_global_asm_8075340C[D_global_asm_807FD584]);
            PaaD->unk1AC = NULL;
            PaaD->unk1B0 = NULL;
        }
    }
}

void func_global_asm_806CF42C(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;

    if (arg0->interactable & 1) {
        PaaD = arg0->PaaD;
        if (PaaD->unk1AC != 0) {
            func_global_asm_80679200(PaaD->unk1AC, arg0, 8, 0, 0, 0);
        } else if (PaaD->unk1B0 != 0) {
            func_global_asm_80679200(PaaD->unk1B0, arg0, 8, 0, 0, 0);
        }
        PaaD->unk1AC = NULL;
        PaaD->unk1B0 = NULL;
    }
}

void func_global_asm_806CF4B8(Actor *arg0) {
    s32 i;
    PlayerAdditionalActorData *PaaD;

    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist != 0) {
            PaaD = character_change_array[i].playerPointer->PaaD;
            if ((arg0 == PaaD->unk1AC && PaaD->unk1AC != 0)
                || (arg0 == PaaD->unk1B0 && PaaD->unk1B0 != 0)) {
                PaaD->unk1AC = 0;
                PaaD->unk1B0 = 0;
                func_global_asm_806CFF9C(character_change_array[i].playerPointer);
            }
        }
    }
}

void func_global_asm_806CF580(void) {
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        extra_player_info_pointer->unk84 = object_timer;
        extra_player_info_pointer->unkD0 = object_timer;
    }
    if (current_character_index[cc_player_index] == 1) {
        if ((gCurrentActorPointer->control_state == 0x36) && (extra_player_info_pointer->unk0 != 0x36)) {
            func_global_asm_806883F4(gCurrentActorPointer, 1, 0, 6.0f);
        }
        if (gCurrentActorPointer->control_state == 0x36) {
            func_global_asm_80688370(gCurrentActorPointer, 0, 0.5f);
            func_global_asm_806883C8(gCurrentActorPointer, 0, 0);
            func_global_asm_8068839C(gCurrentActorPointer, 0, 0);
            func_global_asm_806884E4(gCurrentActorPointer, 0);
            func_global_asm_8068848C(gCurrentActorPointer, 0, 4);
            func_global_asm_8068842C(gCurrentActorPointer, 0, 2);
            func_global_asm_80688370(gCurrentActorPointer, 1, 0.5f);
            func_global_asm_806883C8(gCurrentActorPointer, 1, 0);
            func_global_asm_8068839C(gCurrentActorPointer, 1, 0);
            func_global_asm_806884E4(gCurrentActorPointer, 1);
            func_global_asm_8068848C(gCurrentActorPointer, 1, 4);
            func_global_asm_8068842C(gCurrentActorPointer, 1, 2);
        }
        if (gCurrentActorPointer->control_state != 0x36) {
            if (extra_player_info_pointer->unk0 == 0x36) {
                extra_player_info_pointer->unk84 = 0;
            }
        }
    }
    if ((gCurrentActorPointer->control_state != 0x36)
        && (func_global_asm_8072881C(0, &extra_player_info_pointer->unk84) != 0)
        && (((current_character_index[cc_player_index] == 1))
            || ((cc_number_of_players == 1) && (current_character_index[cc_player_index] == 3)))) {
        func_global_asm_8072881C(0x81, &extra_player_info_pointer->unk84);
    }
    if (((gCurrentActorPointer->control_state == 0x4F) || (gCurrentActorPointer->control_state == 0x7F))
        && (D_global_asm_80750AD0 == 0)
        && ((extra_player_info_pointer->unkD0 + 9) < (u32)object_timer)
        && (((func_global_asm_806119A0() % 2500U) / 200) == 0)) {
        func_global_asm_8071498C(func_global_asm_80718BF4);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714C08(&D_global_asm_8071FC40, 0.0f, gCurrentActorPointer, 4, 0);
        extra_player_info_pointer->unkD0 = object_timer;
    }
}

void func_global_asm_806CF878(void) {
    if ((object_timer & 3) == 0) {
        if ((gCurrentActorPointer->control_state_progress >= 5) && (gCurrentActorPointer->y_velocity > 30.0f)) {
            func_global_asm_80714998(2);
            func_global_asm_807149B8(1);
            func_global_asm_8071498C(func_global_asm_80716FB4);
            drawSpriteAtPosition(&D_global_asm_8071FB08, 0.8f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
        }
    }
}

void func_global_asm_807195D4(void);

void func_global_asm_806CF918(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        func_global_asm_8071498C(func_global_asm_807195D4);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(i * 0x28);
        func_global_asm_807149FC(0x45);
        func_global_asm_80714C08(&D_global_asm_8071FF40, 0.05f, gCurrentActorPointer, 6, 2);
    }
}

extern f32 D_global_asm_80753E10[];
extern s16 D_global_asm_80753E00[];

void func_global_asm_806CF9CC(void) {
    f32 sp3C;
    u8 sp3B;
    u8 sp3A;
    s16 sp38;
    s16 sp36;
    u8 sp35;
    u8 var_v1;
    u8 var_t0;
    u8 temp_v1;
    u8 temp_a2;

    if (D_global_asm_807FBB64 & 0x20000) {
        return;
    }
    if (!gCurrentActorPointer->unkFC) {
        return;
    }
    if (extra_player_info_pointer->unk8C) {
        return;
    }
    if (gCurrentActorPointer->unk6A & 1) {
        return;
    }
    if (!extra_player_info_pointer->unkE8) {
        return;
    }
    if ((current_map == MAP_FUNGI_DOGADON) || (current_map == MAP_AZTEC_DOGADON)) {
        var_t0 = TRUE;
    } else {
        var_t0 = FALSE;
    }
    temp_a2 = temp_v1 = !func_global_asm_806725A0(gCurrentActorPointer, gCurrentActorPointer->y_rotation);
    if ((temp_a2) || !(D_global_asm_80753E10[D_global_asm_807FD584] < gCurrentActorPointer->unkB8) || (var_t0 != 0)) {
        sp3B = func_global_asm_806CFC90(gCurrentActorPointer, &sp3C, temp_a2, var_t0 ? 30.0 : 15.0);
        func_global_asm_80666AC4(&sp38, &sp36);
        var_v1 = FALSE;
        if ((sp3B) && (gCurrentActorPointer->y_velocity < 0.0) && (sp36 >= 0x385)) {
            var_v1 = FALSE;
            if (func_global_asm_80666AEC()) {
                if ((gCurrentActorPointer->y_position - gCurrentActorPointer->floor) > 15.0f) {
                    if (var_t0) {
                        if (((D_global_asm_80753E00[D_global_asm_807FD584] + gCurrentActorPointer->y_position) < (sp3C + 15.0f)) && (((sp3C - D_global_asm_80753E00[D_global_asm_807FD584]) - gCurrentActorPointer->y_position) < 80.0f)) {
                            var_v1 = TRUE;
                        }
                    } else {
                        if (((D_global_asm_80753E00[D_global_asm_807FD584] + gCurrentActorPointer->y_position) < (sp3C - 5.0f)) && (((sp3C - D_global_asm_80753E00[D_global_asm_807FD584]) - gCurrentActorPointer->y_position) < 15.0f)) {
                            var_v1 = TRUE;
                        }
                    }
                }
            }
        }
        if (!var_v1) {
            return;
        }
        if (!setAction(0xA, NULL, cc_player_index)) {
            return;
        }
        extra_player_info_pointer->unkF0_f32 = sp3C;
    }
}

u8 func_global_asm_806CFC90(Actor *arg0, f32 *arg1, u8 arg2, f32 arg3) {
    f32 sp34;
    f32 temp_a3;
    s16 phi_a3;
    u8 temp_v0;

    phi_a3 = arg0->y_rotation;
    if (!arg2) {
        phi_a3 = (phi_a3 + 0x800) & 0xFFF;
    }
    sp34 = (func_global_asm_80612794(phi_a3) * arg3);
    temp_a3 = (func_global_asm_80612790(phi_a3) * arg3);
    temp_v0 = func_global_asm_8066635C(
        arg0,
        arg0->x_position + sp34,
        arg0->y_position + 30.0f,
        arg0->z_position + temp_a3,
        arg1
    );

    arg0->unk78 = func_global_asm_80666AE0();
    return temp_v0;
}

void func_global_asm_806CFD68(void) {
    if (gCurrentActorPointer->y_velocity < 0.0f) {
        setYAccelerationFrom80753578();
    }
}

void func_global_asm_806CFDA8(void) {
    if (gCurrentActorPointer->y_velocity < 0.0f) {
        gCurrentActorPointer->y_acceleration = D_global_asm_80753700[D_global_asm_807FD584];
    }
}

void func_global_asm_806CFDEC(void) {
    if (gCurrentActorPointer->y_velocity < 0.0f) {
        gCurrentActorPointer->y_acceleration = D_global_asm_80753658[D_global_asm_807FD584];
    }
}

void func_global_asm_806CFE30(void) {
    if (gCurrentActorPointer->y_velocity < 0.0f) {
        gCurrentPlayer->y_acceleration = D_global_asm_80753754[D_global_asm_807FD584];
    }
}

void setYAccelerationFrom80753578(void) {
    gCurrentPlayer->y_acceleration = D_global_asm_80753578[D_global_asm_807FD584];
}

// TODO: rename to setYAccelerationFrom80753594
void func_global_asm_806CFEA4(void) {
    gCurrentPlayer->y_acceleration = D_global_asm_80753594[D_global_asm_807FD584];
}

// TODO: rename to setYAccelerationFrom807535B0
void func_global_asm_806CFECC(void) {
    gCurrentPlayer->y_acceleration = D_global_asm_807535B0[D_global_asm_807FD584];
}

// TODO: rename to setYAccelerationFrom807536E4
void func_global_asm_806CFEF4(void) {
    gCurrentPlayer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
}

void func_global_asm_806CFF1C(Actor *arg0) {
    gCurrentActorPointer->y_velocity = 0.0f;
    playAnimation(arg0, 0x1B);
    func_global_asm_80614D90(arg0);
    gCurrentActorPointer->unk9C = gCurrentActorPointer->y_position;
    if (extra_player_info_pointer->unk8C != 0) {
        arg0->control_state = 0x1F;
        arg0->control_state_progress = 0;
    } else {
        arg0->control_state = 0x1E;
        arg0->control_state_progress = 0;
    }
}

void func_global_asm_806CFF9C(Actor *arg0) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    Actor *vehicle;
    s32 temp;

    arg0->unk6A &= 0xFFDF;
    PaaD->unk4C = -1;
    PaaD->unk10C = 0;

    if (arg0->noclip_byte == 1) {
        func_global_asm_806C8D20(arg0);
    }

    if (D_global_asm_807FBB64 & 0x80000) {
        vehicle = PaaD->vehicle_actor_pointer;
        if ((vehicle) && (vehicle->unk58 == ACTOR_MINECART)) {
            func_global_asm_806D0150(arg0);
            return;
        }
    }

    if (current_character_index[cc_player_index] == 7) {
        arg0->control_state = 0x7E;
        arg0->control_state_progress = 0;
        return;
    }

    if ((PaaD->unk1F0 & 0x20) && (cc_number_of_players == 1)) {
        arg0->control_state = func_global_asm_806CE4E4(arg0, arg0->unkB8, PaaD->unk4, 1);
        arg0->control_state_progress = 0;
        if (arg0->control_state == 0x3F) {
            arg0->control_state_progress = 1;
        }
        return;
    }

    if (PaaD->unk1AC) {
        arg0->control_state = func_global_asm_806CE928(arg0, arg0->unkB8, PaaD->unk4, 1);
        arg0->control_state_progress = 0;
    } else {
        if (PaaD->unk8C != 0) {
            temp = func_global_asm_806CE174(arg0, arg0->unkB8, PaaD->unk4, 1);
            if (arg0->control_state != 2) {
                arg0->control_state = temp;
                arg0->control_state_progress = 0;
            }
        } else {
            temp = func_global_asm_806CDD24(arg0, arg0->unkB8, PaaD->unk4, 1);
            if (arg0->control_state != 2) {
                arg0->control_state = temp;
                arg0->control_state_progress = 0;
            }
        }
    }
}

void func_global_asm_806D0150(Actor *arg0) {
    arg0->unk6A &= ~0x20;
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk10C = 0;
    playAnimation(arg0, 0x7A);
    arg0->control_state = 7;
    arg0->control_state_progress = 0;
}

void func_global_asm_806D01AC(void) {
    extra_player_info_pointer->unk48 = D_global_asm_80753328[D_global_asm_807FD584];
    extra_player_info_pointer->unk2C = D_global_asm_807532F0[D_global_asm_807FD584];
    extra_player_info_pointer->unk30 = D_global_asm_8075330C[D_global_asm_807FD584];
    extra_player_info_pointer->unk34 = D_global_asm_807532B8[D_global_asm_807FD584];
    extra_player_info_pointer->unk38 = D_global_asm_807532D4[D_global_asm_807FD584];
}

void func_global_asm_806D024C(void) {
    extra_player_info_pointer->unk48 = D_global_asm_8075326C[D_global_asm_807FD584];
    extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584];
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    extra_player_info_pointer->unk34 = D_global_asm_80753170[D_global_asm_807FD584];
    if (extra_player_info_pointer->unk8C != 0) {
        extra_player_info_pointer->unk38 = D_global_asm_80753338[D_global_asm_807FD584];
        return;
    }
    if ((extra_player_info_pointer->unk1F0 & 0x20) || (is_autowalking == 3)) {
        if (current_map == MAP_FUNGI) {
            extra_player_info_pointer->unk38 = 200.0f;
        } else {
            extra_player_info_pointer->unk38 = D_global_asm_80753218[D_global_asm_807FD584];
        }
    } else {
        extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
    }
}

void func_global_asm_806D0378(void) {
    gCurrentPlayer->y_acceleration = D_global_asm_80753578[D_global_asm_807FD584];
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk28 = 1;
}

void func_global_asm_806D03BC(void) {
    if (extra_player_info_pointer->unk1AC != 0) {
        func_global_asm_806D01AC();
    } else {
        func_global_asm_806D024C();
    }
    func_global_asm_806D0378();
}

void func_global_asm_806D0408(void) {
    func_global_asm_806D024C();
    func_global_asm_806D0378();
}

void func_global_asm_806D0430(f32 arg0) {
    if (arg0 != 0.0f) {
        D_global_asm_80750FA8 = arg0;
        return;
    }
    D_global_asm_80750FA8 = 0.3f;
}

void func_global_asm_806D0468(Actor *arg0, u8 arg1) {
    f32 temp_f0_3;
    s32 i;
    PlayerAdditionalActorData *PaaD;
    u8 index;

    PaaD = arg0->PaaD;
    PaaD->unk1DC = 0.4f;
    PaaD->unk1D8 = 0.004f;
    index = PaaD->unk1A4;
    switch (arg1) {
        case 0:
            PaaD->unk1C0 = 0.05f;
            PaaD->unk1C4 = 0.05f;
            PaaD->unk1C8 = 0.05f;
            break;
        case 2:
            PaaD->unk1C0 = D_global_asm_80750FA8;
            PaaD->unk1C4 = D_global_asm_80750FA8;
            PaaD->unk1C8 = D_global_asm_80750FA8;
            break;
        default:
            PaaD->unk1C0 = 0.15f;
            PaaD->unk1C4 = 0.15f;
            PaaD->unk1C8 = 0.15f;
            if (character_change_array[index].unk2C0 == 0) {
                PaaD->unk1DC = 0.05f;
                PaaD->unk1D8 = 0.001f;
            }
            break;
    }
    if (arg1 != 1) {
        if (cc_number_of_players == 1) {
            for (i = 0; i < 3; i++) {
                PaaD->scale1CC[i] = PaaD->scale1C0[i];
                arg0->animation_state->scale[i] = PaaD->scale1C0[i];
            }
        }
    }
    character_change_array[index].unk2C0 = arg1;
    character_change_array[index].unk2C1 = 1;
    PaaD->unk1E4 = 0;
    if ((arg1 == 1) || (cc_number_of_players >= 2)) {
        temp_f0_3 = ABS(PaaD->unk1C0 - PaaD->unk1CC) / PaaD->unk1D8;
        if (temp_f0_3 != 0.0f) {
            PaaD->unk1E0 = PaaD->unk1DC / temp_f0_3;
        } else {
            PaaD->unk1E0 = 99999.0f;
        }
    }
    func_global_asm_8062217C(PaaD->unk104, 2);
}

void func_global_asm_806D06A0(void) {
    if (extra_player_info_pointer->unk1CC < extra_player_info_pointer->unk1C0) {
        extra_player_info_pointer->unk1CC += extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D0 += extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D4 += extra_player_info_pointer->unk1D8;
        if (extra_player_info_pointer->unk1C0 < extra_player_info_pointer->unk1CC) {
            extra_player_info_pointer->unk1CC = extra_player_info_pointer->unk1C0;
            extra_player_info_pointer->unk1D0 = extra_player_info_pointer->unk1C4;
            extra_player_info_pointer->unk1D4 = extra_player_info_pointer->unk1C8;
        }
    } else {
        extra_player_info_pointer->unk1CC -= extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D0 -= extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D4 -= extra_player_info_pointer->unk1D8;
        if (extra_player_info_pointer->unk1CC < extra_player_info_pointer->unk1C0) {
            extra_player_info_pointer->unk1CC = extra_player_info_pointer->unk1C0;
            extra_player_info_pointer->unk1D0 = extra_player_info_pointer->unk1C4;
            extra_player_info_pointer->unk1D4 = extra_player_info_pointer->unk1C8;
        }
    }
    if (extra_player_info_pointer->unk1C0 == extra_player_info_pointer->unk1CC) {
        gCurrentActorPointer->animation_state->scale_x = extra_player_info_pointer->unk1CC;
        gCurrentActorPointer->animation_state->scale_y = extra_player_info_pointer->unk1D0;
        gCurrentActorPointer->animation_state->scale_z = extra_player_info_pointer->unk1D4;
    } else {
        gCurrentActorPointer->animation_state->scale_x = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * 0.11) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1CC;
        gCurrentActorPointer->animation_state->scale_y = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * 0.235199999999999992) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1D0;
        gCurrentActorPointer->animation_state->scale_z = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * 0.17599999999999999) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1D4;
        extra_player_info_pointer->unk1DC -= extra_player_info_pointer->unk1E0;
        if (extra_player_info_pointer->unk1DC < 0.0) {
            extra_player_info_pointer->unk1DC = 0.0f;
        }
        extra_player_info_pointer->unk1E4++;
    }
}

s32 func_global_asm_806D0964(s32 arg0, u8 playerIndex) {
    s16 actorBehaviourIndex = character_change_array[playerIndex].playerPointer->unk58;
    if (actorBehaviourIndex != ACTOR_CHUNKY) {
        if ((actorBehaviourIndex == ACTOR_RAMBI) && (arg0 & 2)) {
            return TRUE;
        }
    } else {
        if ((arg0 & 1) && (character_change_array[playerIndex].unk2C0 != 1)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_global_asm_806D09E8(Actor *arg0) {
    if ((arg0->unk58 == ACTOR_LANKY)
        && (((arg0->control_state == 0x3F)) || (arg0->control_state == 0x40))
        && !(D_global_asm_807FBB68 & 0x40)
        && !func_global_asm_80666A88()) {
        arg0->unkD1 = 0x10;
    }
}

void func_global_asm_806D0A54(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1) {
        arg0->object_properties_bitfield |= 4;
    } else {
        arg0->object_properties_bitfield &= ~4;
    }
}

void func_global_asm_806D0A84(void) {
    AAD_global_asm_806D0A84 *temp_a3;
    Actor *sp30;
    f32 sp2C;
    ActorAnimationState *temp_v0;
    f32 temp_f10;
    f32 var_f0;

    temp_a3 = gCurrentActorPointer->additional_actor_data;
    sp30 = temp_a3->unk4;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        playActorAnimation(gCurrentActorPointer, temp_a3->unk0);
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        gCurrentActorPointer->unk168 = (rand() >> 0xF) % 4096;
    }
    temp_v0 = gCurrentActorPointer->animation_state;
    if (temp_v0 != NULL) {
        var_f0 = temp_v0->scale_y;
    } else {
        var_f0 = 0.15f;
    }
    sp2C = var_f0 * 6.66666666999999968;
    if ((func_global_asm_8067AF44(sp30) == 0) || (sp30->unk54 != temp_a3->unk8)) {
        deleteActor(gCurrentActorPointer);
        return;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (sp30->animation_state->unk64 != temp_a3->unkC) {
                playActorAnimation(gCurrentActorPointer, temp_a3->unk2);
            } else {
                moveAndScaleActorToAnother(gCurrentActorPointer, sp30, gCurrentActorPointer->animation_state->scale_x);
                gCurrentActorPointer->y_position += temp_a3->unk10;
            }
            break;
        case 1:
            gCurrentActorPointer->y_velocity = gCurrentActorPointer->y_velocity + 0.2;
            gCurrentActorPointer->y_position += sp2C * gCurrentActorPointer->y_velocity;
            break;
        case 2:
            gCurrentActorPointer->y_velocity = gCurrentActorPointer->y_velocity - 0.2;
            gCurrentActorPointer->y_position += sp2C * gCurrentActorPointer->y_velocity;
            break;
        case 3:
            gCurrentActorPointer->unk168 += 0x28;
            gCurrentActorPointer->unk168 &= 0xFFF;
            if (gCurrentActorPointer->unkB8 < 1.2) {
                gCurrentActorPointer->unkB8 = gCurrentActorPointer->unkB8 + 0.15;
            }
            temp_f10 = gCurrentActorPointer->unkB8 * sp2C;
            gCurrentActorPointer->x_position += temp_f10 * func_global_asm_80612794(gCurrentActorPointer->unk168);
            gCurrentActorPointer->z_position += temp_f10 * func_global_asm_80612790(gCurrentActorPointer->unk168);
            if (gCurrentActorPointer->y_velocity < 2.5) {
                gCurrentActorPointer->y_velocity = gCurrentActorPointer->y_velocity + 0.2;
            }
            gCurrentActorPointer->y_position += sp2C * gCurrentActorPointer->y_velocity;
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

u8 func_global_asm_806D0DE4(Actor *arg0, Actor *arg1) {
    s32 var_a2;
    u8 var_v0;
    u8 var_v1;

    var_v0 = 1;
    var_v1 = 1;
    var_a2 = 1;
    if (cc_number_of_players < 2 || arg0->interactable & 4 || arg1->interactable & 4) {
        return 0;
    }
    if (arg0->interactable & 1) {
        PlayerAdditionalActorData *PaaD = arg0->PaaD;
        var_v0 = character_change_array[PaaD->unk1A4].unk2C0;
    }
    if (arg1->interactable & 1) {
        PlayerAdditionalActorData *PaaD = arg1->PaaD;
        var_v1 = character_change_array[PaaD->unk1A4].unk2C0;
        var_a2 = arg1->control_state != 0x7C;
    }
    return var_v0 < var_v1 && var_a2;
}

void func_global_asm_806D0EBC(Actor *arg0) {
    f32 phi_f12;
    f32 phi_f0;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f12 = D_global_asm_8075388C[D_global_asm_807FD584];
    } else {
        phi_f12 = D_global_asm_807538C8[D_global_asm_807FD584];
    }
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f0 = D_global_asm_8075387C[D_global_asm_807FD584];
    } else {
        phi_f0 = D_global_asm_807538B8[D_global_asm_807FD584];
    }
    if ((gCurrentActorPointer->unkAC - gCurrentActorPointer->floor) < phi_f0) {
        setAction(2, NULL, cc_player_index);
        return;
    }
    if (gCurrentActorPointer->unkAC < (gCurrentActorPointer->y_position + phi_f12)) {
        playSoundAtActorPosition(gCurrentActorPointer, 0x10, 0xFF, 0x7F, 1);
        gCurrentActorPointer->y_position = gCurrentActorPointer->unkAC - phi_f12;
        gCurrentActorPointer->y_velocity = 0.0f;
        playAnimation(gCurrentActorPointer, 0x3D);
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
        gCurrentActorPointer->control_state = 0x4E;
        gCurrentActorPointer->control_state_progress = 0;
    }
}

// TODO: Can we simplify this?
s16 func_global_asm_806D1080(f32 arg0, f32 arg1) {
    return (s16)((s16)((func_global_asm_80611BB4(arg0, arg1) * 4096.0f) / MATH_2PI_F) - 0x400) & 0xFFF;
}

// TODO: Can we simplify this?
s32 func_global_asm_806D10D0(Actor *arg0) {
    s32 phi_v1;

    phi_v1 = TRUE;
    if ((arg0->interactable & 1) && (D_global_asm_80750B50[arg0->control_state].unk4 & 0x400)) {
        phi_v1 = FALSE;
    }
    return phi_v1;
}

void func_global_asm_806D1110(void) {
    setAction(0x3C, NULL, cc_player_index);
    handleInputsForControlState(0xB);
    gCurrentPlayer->unkB8 = extra_player_info_pointer->unk4;
    gCurrentPlayer->unkEE = extra_player_info_pointer->unkA;
    gCurrentPlayer->y_rotation = extra_player_info_pointer->unkA;
    func_global_asm_806CC8F0();
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & (Z_TRIG | U_CBUTTONS | D_CBUTTONS))) {
        func_global_asm_806CFF9C(gCurrentActorPointer);
        func_global_asm_806C8D20(gCurrentActorPointer);
    } else {
        gCurrentActorPointer->noclip_byte = 1;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D11FC(void) {
    if (gCurrentActorPointer->unkAC < (gCurrentActorPointer->y_position + 4.5f)) {
        gCurrentActorPointer->y_position = gCurrentActorPointer->unkAC - 4.5f;
    }
}

void func_global_asm_806D1238(void) {
    handleInputsForControlState(0x66);
    func_global_asm_806CC8B8();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1270(void) {

}

void func_global_asm_806D1278(void) {
    handleInputsForControlState(1);
    // TODO: Proper bitfield syntax
    if ((extra_player_info_pointer->unk1F0 << 0xF) >= 0) {
        func_global_asm_806CFF9C(gCurrentActorPointer);
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D12CC(void) {
    gCurrentActorPointer->y_velocity = func_global_asm_806CD898(gCurrentActorPointer->y_velocity, 50.0f, 4.0f);
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk24 = 0;
            extra_player_info_pointer->unk38 = 100.0f;
            handleInputsForControlState(0x67);
            func_global_asm_806CC8F0();
            gCurrentActorPointer->control_state_progress++;
            break;
        case 1:
            func_global_asm_806CC8F0();
            if ((gCurrentActorPointer->unkB8 > 10.0f) && (gCurrentActorPointer->animation_state->unk64 != 0x317)) {
                playActorAnimation(gCurrentActorPointer, 0x317);
            } else if ((gCurrentActorPointer->unkB8 == 0.0f) && (gCurrentActorPointer->animation_state->unk64 != 0x314)) {
                playActorAnimation(gCurrentActorPointer, 0x314);
            }
            handleInputsForControlState(0x67);
            break;
    }
    func_global_asm_806D11FC();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1420(void) {
    extra_player_info_pointer->unk24 = 0;
    if (gCurrentActorPointer->control_state_progress == 0) {
        extra_player_info_pointer->unk48 = 0xA;
        gCurrentActorPointer->y_acceleration = -8.0f;
        gCurrentActorPointer->z_rotation = func_global_asm_806D1080(gCurrentActorPointer->unkB8, gCurrentActorPointer->y_velocity);
        func_global_asm_806DF494(&gCurrentActorPointer->x_rotation, 0, 0x32);
        func_global_asm_806DF494(&gCurrentActorPointer->z_rotation, func_global_asm_806D1080(gCurrentActorPointer->unkB8, gCurrentActorPointer->y_velocity), 0xA);
        handleInputsForControlState(0x6A);
        gCurrentActorPointer->unkEE = gCurrentActorPointer->y_rotation;
        func_global_asm_806CC948();
    }
    if (((gCurrentActorPointer->y_position + 4.0f) < gCurrentActorPointer->unkAC)
        && (gCurrentActorPointer->y_velocity < 0.0f)) {
        gCurrentActorPointer->control_state = 0x7F;
        gCurrentActorPointer->control_state_progress = 0;
        extra_player_info_pointer->unk1C = 2;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1568(void) {
    f64 temp_f0;
    f64 temp_f2;
    f32 temp;

    extra_player_info_pointer->unk24++;
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x4C);
            temp = (f64)-gCurrentActorPointer->y_velocity * 0.125f;
            gCurrentActorPointer->y_velocity = func_global_asm_806CD898(gCurrentActorPointer->y_velocity, 0.0f, temp);
            if (extra_player_info_pointer->unk24 >= 6) {
                if ((gCurrentActorPointer->unkB8 != 0.0f) || (extra_player_info_pointer->unk10 != 0)) {
                    gCurrentActorPointer->control_state_progress = 3;
                } else {
                    gCurrentActorPointer->control_state_progress = 2;
                }
                gCurrentActorPointer->animation_state->unk78 &= -0x4001;
            }
            func_global_asm_806CC5DC();
            break;
        case 1:
            func_global_asm_806DF494(&gCurrentActorPointer->z_rotation, func_global_asm_806D1080(gCurrentActorPointer->unkB8, gCurrentActorPointer->y_velocity), 0x32);
            extra_player_info_pointer->unk38 = 500;
            handleInputsForControlState(0x57);
            func_global_asm_806CC638(0.0f);
            if (extra_player_info_pointer->unk10 == 0) {
                gCurrentActorPointer->control_state_progress = 3;
            }
            break;
        case 2:
            handleInputsForControlState(0x55);
            func_global_asm_806CC638(0);
            if (gCurrentActorPointer->control_state == 0x7F) {
                if (gCurrentActorPointer->unkB8 != 0) {
                    extra_player_info_pointer->unk18 = 0;
                    gCurrentActorPointer->control_state_progress = 3;
                } else {
                    if (extra_player_info_pointer->unk50 != 0) {
                        extra_player_info_pointer->unk50--;
                        if (extra_player_info_pointer->unk50 == 0) {
                            playActorAnimation(gCurrentActorPointer, 0x315);
                        }
                    }
                }
                if (gCurrentActorPointer->unkAC < (gCurrentActorPointer->y_position + 4.0f)) {
                    gCurrentActorPointer->control_state = 0x7E;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
            break;
        case 3:
            handleInputsForControlState(0x56);
            func_global_asm_806CC638(0);
            temp_f0 = gCurrentActorPointer->unkB8 / 200.0;
            temp_f2 = gCurrentActorPointer->y_velocity / 200.0;
            func_global_asm_80614D00(gCurrentActorPointer, sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)), 5);
            if ((gCurrentActorPointer->unkB8 == 0.0f) || (extra_player_info_pointer->unk18 != 0)) {
                extra_player_info_pointer->unk50 = D_global_asm_80753A78[D_global_asm_807FD584];
                func_global_asm_80614D00(gCurrentActorPointer, 0.5f, extra_player_info_pointer->unk50);
                gCurrentActorPointer->control_state_progress = 2;
            }
            if (gCurrentActorPointer->unkAC < (gCurrentActorPointer->y_position + 4)) {
                playSoundAtActorPosition(gCurrentActorPointer, 0x10, 0xFF, 0x7F, 1);
                if (gCurrentActorPointer->y_velocity > 150) {
                    gCurrentActorPointer->control_state = 0x82;
                    gCurrentActorPointer->control_state_progress = 0;
                    playActorAnimation(gCurrentActorPointer, 0);
                } else {
                    gCurrentActorPointer->control_state = 0x7E;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D19A8(void) {
    gCurrentActorPointer->y_velocity = func_global_asm_806CD898(gCurrentActorPointer->y_velocity, 50.0f, 4.0f);
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk48 = 0x50;
            handleInputsForControlState(0x68);
            func_global_asm_806CD8EC();
            func_global_asm_806CC970();
            break;
        case 1:
            extra_player_info_pointer->unk68 = 200.0f;
            extra_player_info_pointer->unk2C = 40.0f;
            func_global_asm_806CD424(gCurrentActorPointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
            handleInputsForControlState(0x68);
            func_global_asm_806CC970();
            break;
        case 2:
            handleInputsForControlState(0x68);
            func_global_asm_806CD424(gCurrentActorPointer->y_rotation, extra_player_info_pointer->unk4, extra_player_info_pointer->unk68);
            func_global_asm_806CC970();
            break;
        case 3:
            handleInputsForControlState(0x68);
            func_global_asm_806CC8F0();
            if (gCurrentActorPointer->unkAC < (gCurrentActorPointer->y_position + 4.0f)) {
                gCurrentActorPointer->control_state = 0x7E;
                gCurrentActorPointer->control_state_progress = 0;
            } else {
                gCurrentActorPointer->control_state = 0x7F;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
    }
    func_global_asm_806D11FC();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1B60(void) {
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x69);
            func_global_asm_806CD8EC();
            func_global_asm_806CC970();
            extra_player_info_pointer->unk12 = gCurrentActorPointer->z_rotation;
            extra_player_info_pointer->unk14 = gCurrentActorPointer->y_rotation;
            break;
        case 1:
            extra_player_info_pointer->unk2C = 40.0f;
            extra_player_info_pointer->unk10 = 0xA;
            extra_player_info_pointer->unk38 = 200.0f;
            handleInputsForControlState(0x69);
            func_global_asm_806CC638(0);
            break;
        case 2:
            handleInputsForControlState(0x69);
            func_global_asm_806CD424(gCurrentActorPointer->y_rotation,
                        extra_player_info_pointer->unk4,
                        extra_player_info_pointer->unk68);
            func_global_asm_806CC970();
            break;
        case 3:
            handleInputsForControlState(0x69);
            func_global_asm_806CC920();
            if (gCurrentActorPointer->unkAC < (gCurrentActorPointer->y_position + 4.0f)) {
                gCurrentActorPointer->control_state = 0x7E;
                gCurrentActorPointer->control_state_progress = 0;
                playActorAnimation(gCurrentActorPointer, 0x317);
            } else {
                gCurrentActorPointer->control_state = 0x7F;
                gCurrentActorPointer->control_state_progress = 3;
                playActorAnimation(gCurrentActorPointer, 0x318);
                extra_player_info_pointer->unk38 = 300.0f;
                extra_player_info_pointer->unk10 = 0xF;
            }
            break;
    }
    func_global_asm_806D11FC();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1D3C(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    handleInputsForControlState(0x65);
    func_global_asm_806CC8B8();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1D84(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    setAction(0x3C, NULL, cc_player_index);
    func_global_asm_806CC8B8();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1DEC(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    func_global_asm_806CC8B8();
    if ((func_global_asm_80629148()) ||
        (gCurrentActorPointer->control_state_progress == 1) ||
        (--extra_player_info_pointer->unk23C == 0) // TODO: Janky syntax
    ) {
        func_global_asm_805FF8F8();
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1E90(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    setAction(0x3C, NULL, cc_player_index);
    func_global_asm_806CC8B8();
    if (gCurrentActorPointer->control_state_progress != 0) {
        func_global_asm_805FF898();
        gCurrentActorPointer->control_state_progress++;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D1F28(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    setAction(0x3C, NULL, cc_player_index);
    if (!(gCurrentActorPointer->unk6A & 4)) {
        func_global_asm_806CC8B8();
    } else {
        func_global_asm_806D850C();
        if (!(gCurrentActorPointer->unk6C & 4)) {
            playAnimation(gPlayerPointer, 0x34);
        }
        gCurrentActorPointer->y_velocity *= 0.25;
        func_global_asm_806CC8B8();
    }
    if (func_global_asm_80629148() || ((--extra_player_info_pointer->unk23C == 0))) { // TODO: Janky syntax
        func_global_asm_806ACC00(0);
        gCurrentActorPointer->control_state_progress++;
    }
    renderActor(gCurrentActorPointer, 0);
}

typedef struct {
    u16 unk0[3];
} Struct80750FB0;

extern Struct80750FB0 D_global_asm_80750FB0;

void func_global_asm_80688D20(s16, s16, s16, f32);

void func_global_asm_806D205C(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    // s16 sp22;
    Struct80750FB0 sp1C;

    sp1C = D_global_asm_80750FB0;
    setAction(0x3C, NULL, cc_player_index);
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    if (!(gCurrentActorPointer->unk6A & 4)) {
        func_global_asm_806CC8B8();
    } else {
        func_global_asm_806D850C();
        if (!(gCurrentActorPointer->unk6C & 4)) {
            playAnimation(gPlayerPointer, 0x34);
        }
        gCurrentActorPointer->y_velocity = gCurrentActorPointer->y_velocity * 0.25;
        func_global_asm_806CC8F0();
    }
    if (func_global_asm_80629148() || --extra_player_info_pointer->unk23C == 0) {
        if (!gameIsInSnidesBonusGameMode()) {
            sp28 = func_global_asm_80600340(&sp1C, 3, &sp2C);
            func_global_asm_80688D20(sp2C, sp28, 7, 2.0f);
        }
        func_global_asm_805FF898();
        gCurrentActorPointer->control_state_progress++;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D21E4(void) {
    handleInputsForControlState(0);
    if (!(global_properties_bitfield & 0x4000) && !(global_properties_bitfield & 0x8000)) {
        func_global_asm_806CFF9C(gCurrentActorPointer);
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D2238(void) {
    handleInputsForControlState(1);
    if (gCurrentActorPointer->control_state_progress == 0) {
        playAnimation(gCurrentActorPointer, 0);
        gCurrentActorPointer->control_state_progress = 1;
        gCurrentActorPointer->object_properties_bitfield &= -5;
    }
}

void func_global_asm_806D22A0(void) {
    handleInputsForControlState(1);
}

void func_global_asm_806D22C0(void) {
    handleInputsForControlState(0x62);
    switch (gCurrentActorPointer->control_state_progress) {
        case 0x1:
        case 0x2:
            gCurrentActorPointer->control_state_progress++;
            return;
        default:
            gCurrentActorPointer->control_state_progress++;
        case 0x0:
        case 0x3C:
        case 0x3D:
            return;
    }
}

typedef struct {
    void *unk0; // Function pointer
    u8  unk4;
    s8  unk5;
    s16 unk6;
    Actor *unk8;
} Struct806D2330;

// TODO: Arg0 is a function pointer
void func_global_asm_806D2330(void *arg0) {
    Struct806D2330 *temp_v0 = malloc(0x14);
    temp_v0->unk0 = arg0;
    temp_v0->unk8 = gCurrentPlayer;
    temp_v0->unk4 = 1;
    func_global_asm_80679064(temp_v0);
}

void func_global_asm_806D2378(void) {
    func_global_asm_806D2330(func_global_asm_8068E9B0);
}

void func_global_asm_806D239C(void) {
    func_global_asm_806D2378();
    switch (current_map) {
        case MAP_FUNGI_MINECART:
            handleInputsForControlState(0x5F);
            func_global_asm_806CC970();
            return;
        case MAP_CASTLE_MINECART:
            handleInputsForControlState(0x60);
            func_global_asm_806CC970();
            return;
        case MAP_MINECART_MAYHEM_EASY:
        case MAP_MINECART_MAYHEM_NORMAL:
        case MAP_MINECART_MAYHEM_HARD:
            if ((extra_player_info_pointer->unk1F0 & 8) && func_global_asm_80629148()) {
                extra_player_info_pointer->vehicle_actor_pointer->control_state = 0xA;
                gCurrentActorPointer->control_state_progress++;
            }
            handleInputsForControlState(0x5B);
            func_global_asm_806CC970();
            return;
        default:
            handleInputsForControlState(0x5C);
            gCurrentActorPointer->y_velocity = gCurrentActorPointer->terminal_velocity;
            func_global_asm_806CC948();
            return;
    }
}

void func_global_asm_806D24A8(void) {
    func_global_asm_806D2378();
    handleInputsForControlState(0x5D);
    gCurrentActorPointer->y_velocity = gCurrentActorPointer->terminal_velocity;
    func_global_asm_806CC948();
}

void func_global_asm_806D24E4(void) {
    func_global_asm_806D2378();
    switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x5E);
            func_global_asm_806CC948();
            return;
        case 1:
            gCurrentActorPointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            gCurrentActorPointer->control_state_progress++;
            handleInputsForControlState(0x5E);
            func_global_asm_806CFD68();
            func_global_asm_806CC948();
            return;
        case 2:
            func_global_asm_806CC948();
            handleInputsForControlState(0x5E);
            func_global_asm_806CFD68();
            return;
        case 3:
            handleInputsForControlState(0x5C);
            func_global_asm_806CC948();
            return;
    }
}

void func_global_asm_806D25CC(void) {
    switch (current_map) {
        case MAP_CASTLE_MINECART:
            handleInputsForControlState(0x60);
            func_global_asm_806CC970();
            break;
        case MAP_FUNGI_MINECART:
            handleInputsForControlState(0x5F);
            func_global_asm_806CC970();
            break;
        case MAP_MINECART_MAYHEM_EASY:
            handleInputsForControlState(0x5B);
            func_global_asm_806CC970();
            break;
        default:
            handleInputsForControlState(0x5C);
            gCurrentActorPointer->y_velocity = gCurrentActorPointer->terminal_velocity;
            func_global_asm_806CC948();
    }
}

void func_global_asm_806D266C(void) {
    f32 x, y, z;

    func_global_asm_806D2378();
    func_global_asm_806D25CC();
    getBonePosition(gCurrentActorPointer, 3, &x, &y, &z);
    func_global_asm_806F4D70(cc_player_index, x, y, z, 25.0f);
}

void func_global_asm_806D26D8(void) {
    f32 x, y, z;

    func_global_asm_806D2378();
    func_global_asm_806D25CC();
    getBonePosition(gCurrentActorPointer, 2, &x, &y, &z);
    func_global_asm_806F4D70(cc_player_index, x, y, z, 25.0f);
}

void func_global_asm_806D2744(s32 arg0) {
    func_global_asm_806D2330(func_global_asm_8068EA38);
    handleInputsForControlState(arg0);
    gCurrentActorPointer->unk6C = gCurrentActorPointer->unk6A;
}

void func_global_asm_806D2784(void) {
    func_global_asm_806D2744(0x61);
}

void func_global_asm_806D27A4(void) {
    func_global_asm_806D2744(0x63);
    if (func_global_asm_8061CB98(5)) {
        if (gCurrentActorPointer->animation_state->unk64 != 0x3B0) {
            playActorAnimation(gCurrentActorPointer, 0x3B0);
        }
        if (func_global_asm_80629148() || (gCurrentActorPointer->control_state_progress != 0)) {
            func_global_asm_805FF8F8();
        }
    }
}

void func_global_asm_806D281C(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    if (gCurrentActorPointer->control_state_progress != 0) {
        gCurrentActorPointer->control_state = 0x6D;
        gCurrentActorPointer->control_state_progress = 0;
    } else {
        setAction(0x3C, NULL, cc_player_index);
    }
    RaaD->unk0 += extra_player_info_pointer->unkC2;
    if (extra_player_info_pointer->unkC2 >= 8) {
        extra_player_info_pointer->unkC2 -= 7;
    } else if (extra_player_info_pointer->unkC2 < -7) {
        extra_player_info_pointer->unkC2 += 7;
    } else {
        extra_player_info_pointer->unkC2 = 0;
    }
    func_global_asm_806D2744(1);
}

void func_global_asm_806D28E4(void) {
    func_global_asm_806D2744(0x64);
}

void func_global_asm_806D2904(void) {
    renderActor(gCurrentActorPointer, 0);
    if (gCurrentActorPointer->control_state_progress++ > 200) {
        func_global_asm_806CFF9C(gCurrentActorPointer);
    }
}

void func_global_asm_806D2954(s16 arg0) {
    if ((extra_player_info_pointer->unk8C != 0) && func_global_asm_805FCA64()) {
        if (D_global_asm_807FD568->weapon == 7) {
            arg0 = 0xF;
            addActorToTextOverlayRenderArray(func_global_asm_806FF75C, gCurrentActorPointer, 5);
        } else {
            arg0 = 0xE;
            addActorToTextOverlayRenderArray(func_global_asm_806FF01C, gCurrentActorPointer, 5);
        }
    }
    if (gCurrentActorPointer->control_state_progress != 0) {
        arg0 = 5;
        gCurrentActorPointer->control_state_progress--;
    }
    handleInputsForControlState(arg0);
}

void func_global_asm_806D2A14(s16 arg0) {
    if (gCurrentActorPointer->control_state_progress != 0) {
        arg0 = 5;
        gCurrentActorPointer->control_state_progress--;
    }
    if (func_global_asm_805FCA64()) {
        if (!handleInputsForControlState(arg0)) {
            addActorToTextOverlayRenderArray(func_global_asm_806FF358, gCurrentActorPointer, 3);
        }
        addActorToTextOverlayRenderArray(func_global_asm_806FF32C, gCurrentActorPointer, 3);
    }
}

typedef struct {
    PlayerAdditionalActorData *unk0;
} AAD_806D2AA0;

void func_global_asm_806D2AA0(s16 arg0) {
    handleInputsForControlState(1);
    if (gCurrentActorPointer->control_state_progress < 6) {
        addActorToTextOverlayRenderArray(func_global_asm_806FFB2C, gCurrentActorPointer, 3);
        gCurrentActorPointer->control_state_progress++;
    } else {
        gCurrentActorPointer->control_state = arg0;
        gCurrentActorPointer->control_state_progress = 0;
    }
    if (gCurrentActorPointer->control_state_progress == 2) {
        spawnActor(ACTOR_PICTURE, 0x8D);
        extra_player_info_pointer->vehicle_actor_pointer = gLastSpawnedActor;
        ((AAD_806D2AA0*)gLastSpawnedActor->additional_actor_data)->unk0 = extra_player_info_pointer;
        extra_player_info_pointer->unk1F0 |= 0x8000;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806D2B90(void) {
    func_global_asm_806D2AA0(4);
}

void func_global_asm_806D2BB0(void) {
    func_global_asm_806D2AA0(5);
}
