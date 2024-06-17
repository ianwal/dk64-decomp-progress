#include <ultra64.h>
#include "functions.h"

typedef struct {
    s32 unk0;
    f32 unk4; // Used
    f32 unk8; // Used
    f32 unkC; // Used
    f32 unk10; // Used
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20; // Used
    u8 unk24[0x34 - 0x24];
    u8 unk34; // Used
    u8 unk35; // Used
} A178_race_8002B964;

typedef struct {
    s32 unk0;
    s32 unk4; // Used
    s32 unk8;
    s32 unkC;
    s8 unk10; // Used
} A17C_race_8002B964;

typedef struct {
    u8 unk0[0x45 - 0];
    u8 unk45;
} Struct8002E8EC_arg1;

typedef struct {
    u8 unk0[0x30 - 0x0];
    Actor *unk30;
    u8 unk34;
    u8 unk35;
} Struct8002B610_arg0;

typedef struct {
    u8 unk0[0x28 - 0x0];
    u8 unk28;
} Struct8002B610_arg4;

typedef struct {
    s32 unk0;
    Struct8002B610_arg4 *unk4;
} Struct8002B610_arg1;

typedef struct RaceStruct7 {
    u8 pad0[0x35];
    u8 unk35;
} RaceStruct7;

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
    u8 unk28;
    u8 unk29[0x30 - 0x29];
    Actor *unk30;
    u8 unk34[0x36 - 0x34];
    u8 unk36;
} AAD_Car_Castle_Player;

typedef struct {
    u8 unk0[0x25 - 0x0];
    u8 unk25;
    u8 unk26;
} AAD_initializeCastleCarRace_arg0;

typedef struct {
    s32 unk0;
    s32 unk4;
} A17C_initializeCastleCarRace;

void func_race_800283D4(f32 arg0);
void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, void *arg3);
void func_race_8002BCB0(Actor *arg0, s32 arg1, s32 *arg2, s32 *arg3);
void func_race_8002D754(Actor *arg0);
void func_race_8002DE78(void *, s32, void *, s32);
s32 func_race_8002E8EC(void *arg0, void *arg1, s32 arg2);

extern s32 D_race_8002FC70;
extern s32 D_race_8002FCA0;
extern s32 D_race_8002FCAC[];

extern s16 D_global_asm_80750AC8;

void initializeCastleCarRace(Actor *arg0) {
    AAD_initializeCastleCarRace_arg0 *aaD;
    AAD_Car_Castle_Player *sp58;
    Actor *sp54;
    A17C_initializeCastleCarRace *temp_a2;
    s32 var_s1;
    s32 playerIndex;
    s32 numRacers;

    numRacers = cc_number_of_players;
    var_s1 = 0;
    aaD = arg0->additional_actor_data;
    if (numRacers == 1) {
        numRacers++;
    }
    func_race_8002BBD0(arg0, numRacers);
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        spawnActor(ACTOR_CAR_CASTLE_PLAYER, 0x95);
        sp54 = last_spawned_actor;
        sp58 = sp54->additional_actor_data;
        sp58->unk27 = 0;
        func_race_8002BC2C(arg0, var_s1, sp54, sp58);
        sp58->unk28 = playerIndex;
        var_s1++;
    }
    if (cc_number_of_players == 1) {
        sp54 = func_global_asm_807271F4(1, 0, 0, 0, 0, 0, 0);
        sp58 = sp54->unk178;
        sp58->unk27 = 1;
        func_race_8002BC2C(arg0, var_s1, sp54, sp58);
        temp_a2 = sp54->unk17C;
        func_race_8002BCB0(arg0, 0, temp_a2, &temp_a2->unk4);
        aaD->unk25 = 1;
    } else {
        aaD->unk25 = 0;
    }
    for (playerIndex = 0; playerIndex < numRacers; playerIndex++) {
        func_race_8002BCB0(arg0, playerIndex, &sp54, &sp58);
        sp58->unk36 = playerIndex;
        sp58->unk30 = arg0;
        func_global_asm_806903BC(sp54, sp58);
    }
    aaD->unk26 = 0;
}

void func_race_8002A7F8(A178_race_8002B964 *arg0) {
    f32 sp5C;
    f32 sp58;
    f32 var_f14;
    u8 sp53;
    s16 sp50;
    s16 sp4E;
    s16 sp4C;
    f32 var_f0;
    f32 sp44;
    f32 var_f12;
    s16 var_a0;
    s32 pad;
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 pad2;

    sp53 = current_actor_pointer->unk6A & 1;
    sp50 = current_actor_pointer->y_rotation;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x3C;
        current_actor_pointer->object_properties_bitfield |= 0x10400;
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkB8 = 0;
        current_actor_pointer->y_acceleration = -20.0f;
        current_actor_pointer->terminal_velocity = -900.0f;
        current_actor_pointer->unkF8 = 0x12C;
    }
    sp5C = func_global_asm_80612794(current_actor_pointer->unkEE) * current_actor_pointer->unkB8;
    sp58 = func_global_asm_80612790(current_actor_pointer->unkEE) * current_actor_pointer->unkB8;
    if (arg0->unk20 != 0) {
        sp50 += 0x800;
        sp50 &= 0xFFF;
        arg0->unk4 *= 0.85;
    }
    if (sp53) {
        var_f0 = (arg0->unk8 * current_actor_pointer->unkB8) * 0.2;
        if (!(var_f0 > 1)) {
            var_f0 = 1;
        }
        var_f14 = (arg0->unk4 * 35.0f) + (current_actor_pointer->unkB8 * 0.13);
        sp44 = (current_actor_pointer->unkB8 * current_actor_pointer->unkB8 * 0.00025f) + (27.0 + var_f0);
    } else {
        var_f14 = arg0->unk4 * 2;
        sp44 = (current_actor_pointer->unkB8 * current_actor_pointer->unkB8 * 0.00002f) + 2;
    }
    sp5C += func_global_asm_80612794(sp50) * var_f14;
    sp58 += func_global_asm_80612790(sp50) * var_f14;
    current_actor_pointer->unkB8 = sqrtf((sp5C * sp5C) + (sp58 * sp58));
    current_actor_pointer->unkEE = func_global_asm_80611BB4(sp5C, sp58) * 651.8986f;
    if (sp53) {
        sp34 = 0x400 - current_actor_pointer->unkDE;
        sp36 = func_global_asm_806CC10C(current_actor_pointer->unkDC, current_actor_pointer->y_rotation);
        sp4E = func_global_asm_80612790(sp36) * sp34;
        sp4C = func_global_asm_80612794(sp36) * sp34;
        sp4E = sp4E & 0xFFF;
        sp4C = sp4C & 0xFFF;
    } else {
        sp30 = func_global_asm_806D1080(current_actor_pointer->unkB8, current_actor_pointer->y_velocity);
        var_a0 = current_actor_pointer->unkEE;
        if (sp30 >= 0x800) {
            sp30 = 0xFFF - sp30;
            var_a0 += 0x800;
            var_a0 &= 0xFFF;
        }
        sp32 = func_global_asm_806CC10C(var_a0, current_actor_pointer->y_rotation);
        sp4E = func_global_asm_80612790(sp32) * sp30;
        sp4C = func_global_asm_80612794(sp32) * sp30;
        sp4E = sp4E & 0xFFF;
        sp4C = sp4C & 0xFFF;
    }
    var_f12 = arg0->unk10 * arg0->unkC;
    if (arg0->unk8 > 0.0f) {
        if (ABS(var_f12) > 0.1f) {
            var_f12 += 2.0f * (var_f12 >= 0 ? 1 : -1) * arg0->unk8;
        }
    }
    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, sp4E, 4.0f);
    current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, sp4C, 4.0f);
    current_actor_pointer->unkB8 -= sp44;
    if (current_actor_pointer->unkB8 < 0) {
        current_actor_pointer->unkB8 = 0;
    }
    if (arg0->unk20 != 0) {
        if (current_actor_pointer->unkB8 < 100.0f) {
            current_actor_pointer->unkB8 = current_actor_pointer->unkB8;
        } else {
            current_actor_pointer->unkB8 = 100.0f;
        }
    }
    var_f0 = current_actor_pointer->unkB8 - current_actor_pointer->unkBC;
    if (var_f0 < 0) {
        var_f0 = 0;
    }
    current_actor_pointer->y_rotation += ((var_f12 * -40.0f) * (1.0 + (var_f0 * 0.05)));
    current_actor_pointer->y_rotation &= 0xFFF;
    current_actor_pointer->y_velocity += current_actor_pointer->y_acceleration;
    if (current_actor_pointer->y_velocity < current_actor_pointer->terminal_velocity) {
        current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
    }
    func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->unkEE);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0);
    if (D_global_asm_807FBB64 & 0x2000) {
        func_race_8002F490(arg0);
    }
}

void func_race_8002AE6C(Gfx *dl, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_global_asm_8068E474(func_race_8002CAC8(dl, arg1, arg1->PaaD), arg1);
}

typedef struct {
    s32 unk0;
    f32 unk4; // Used
    f32 unk8; // Used
    u8 unkC[0x28 - 0xC];
    u8 unk28; // Player index
    u8 unk29[0x34 - 0x29];
    u8 unk34; // Used
    u8 unk35; // Used
    u8 unk36[0x44 - 0x36];
    s8 unk44; // Used
} AAD_8002AE9C;

void func_race_8002AE9C(void) {
    s32 i;
    s32 var_v0;
    AAD_8002AE9C *aaD;
    u8 sp43;
    u8 playerIndex;
    s32 sp34;

    aaD = current_actor_pointer->additional_actor_data;
    playerIndex = aaD->unk28;
    sp43 = 0xB4;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        setAction(0x4D, current_actor_pointer, playerIndex);
        current_actor_pointer->noclip_byte = 0x3C;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFF;
        for (i = 0; i != 3; i++) {
            current_actor_pointer->animation_state->scale[i] *= 0.3;
        }
        aaD->unk44 = 5;
        func_global_asm_8066E5F8(current_actor_pointer, 2, 8);
        func_race_80026CA8();
    }
    switch (aaD->unk34) {
        case 1:
            if (aaD->unk35 == 0) {
                aaD->unk35++;
                func_global_asm_806F8BC4(0xB, 1, 0);
            }
            // fallthrough
        case 0:
        case 2:
        case 3:
        case 4:
            func_race_80026D2C(current_actor_pointer->unkB8 * 0.03076923f);
            func_race_8002A7F8(aaD);
            break;
        case 5:
            if (aaD->unk35 == 0) {
                aaD->unk35++;
                func_global_asm_806F8D58(0xB, 0);
                current_actor_pointer->object_properties_bitfield &= ~4;
                current_actor_pointer->unkB8 = 0;
                for (i = 0; i != 2; i++) {
                    if (current_actor_pointer->unk6E[i] != -1) {
                        func_global_asm_80605314(current_actor_pointer, i);
                    }
                }
            }
            break;
    }
    if ((aaD->unk4 <= 0.0f) || (aaD->unk8 > 0.0f)) {
        sp43 = 0xF0;
    }
    if (current_actor_pointer->object_properties_bitfield & 4) {
        func_global_asm_8068ECF4(1, sp43);
        func_global_asm_8068ECF4(2, sp43);
    }
    if ((aaD->unk34 > 0) && (aaD->unk34 < 5)) {
        func_global_asm_806F4D70(aaD->unk28, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, (current_actor_pointer->animation_state->scale_y / 0.15) * 40.0);
        addActorToTextOverlayRenderArray(func_race_8002AE6C, current_actor_pointer, 3);
    }
    renderActor(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_6650/func_race_8002B180.s")

void func_race_8002B518(Struct8002B610_arg0 *arg0) {
    switch (arg0->unk35) {
        case 0:
            if (current_actor_pointer->object_properties_bitfield & 0x02000000) {
                arg0->unk35++;
            }
            break;
        case 1:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                arg0->unk35++;
            }
            break;
        case 2:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                arg0->unk35++;
            }
            break;
    }
    if (arg0->unk35 < 3) {
        func_race_8002D72C(arg0->unk30);
        return;
    }
    func_race_8002D754(arg0->unk30);
}

void func_race_8002B610(Struct8002B610_arg0 *arg0, Struct8002B610_arg1 *arg1) {
    if (arg0->unk35 == 0) {
        Struct8002B610_arg4 *T = arg1->unk4;
        Actor *A = character_change_array[T->unk28].player_pointer;
        PlayerAdditionalActorData *PaaD = A->PaaD;
        func_global_asm_8061C6A8(PaaD->unk104, arg1->unk0, 4, 0x800, 0xBE, 0, 0x4A, 0xAE, 0x2D, 0, 0.2f);
        arg0->unk35++;
    }
    func_race_800282D8();
}

s32 func_race_8002B6C8(Struct8002E8EC_arg1 *arg0, Struct8002E8EC_arg1 *arg1) {
    return D_race_8002FCAC[func_race_8002E8EC(arg0, arg1, 0xA)];
}

void func_race_8002B6F4(RaceStruct7 *arg0, s32 arg1) {
    if (arg0->unk35 == 0) {
        // Castle: Tiny GB: Car Race
        if (!isFlagSet(0x145, FLAG_TYPE_PERMANENT)) {
            playCutscene(current_actor_pointer, 1, 1);
            func_global_asm_80629174();
        } else {
            func_global_asm_805FF544();
        }
        arg0->unk35++;
    }
}

void func_race_8002B76C(RaceAdditionalActorData *arg0, void *arg1) {
    s32 i;
    s32 temp_s0;

    switch (arg0->unk35) {
        case 0:
            if (!isFlagSet(0x145, FLAG_TYPE_PERMANENT)) {
                setAction(0x55, NULL, 0);
                current_actor_pointer->x_rotation = 0;
                current_actor_pointer->z_rotation = 0;
                for (i = 0; i < 2; i++) {
                    if (current_actor_pointer->unk6E[i] != -1) {
                        func_global_asm_80605314(current_actor_pointer, i);
                    }
                }
            }
            arg0->unk35++;
            break;
        case 1:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                loadText(current_actor_pointer, 0x22, func_race_8002B6C8(arg0, arg1));
                arg0->unk35++;
            }
            break;
        case 2:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                arg0->unk35++;
            }
            break;
        case 3:
            if (func_global_asm_80629148()) {
                temp_s0 = func_race_8002B6C8(arg0, arg1);
                func_global_asm_80629174();
                if (temp_s0 == 0) {
                    func_global_asm_8063DA40(1, 0xA);
                    setFlag(0x145, TRUE, FLAG_TYPE_PERMANENT);
                } else {
                    func_global_asm_806ACC00(1);
                    arg0->unk35++;
                }
                arg0->unk35++;
            }
            break;
        case 4:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                func_global_asm_805FF544();
                arg0->unk35++;
            }
            break;
    }
}

void func_race_8002B964(void) {
    A178_race_8002B964 *a178;
    A17C_race_8002B964 *a17C;
    s32 i;

    a178 = current_actor_pointer->unk178;
    a17C = current_actor_pointer->unk17C;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        a17C->unk10 = 1;
        func_race_8002DE78(a17C, 5, &D_race_8002FC70, &D_race_8002FCA0);
        current_actor_pointer->noclip_byte = 0x3C;
        current_actor_pointer->object_properties_bitfield &= ~0x20001;
        a178->unk10 = 1.0f;
        for (i = 0; i < 3; i++) {
            current_actor_pointer->animation_state->scale[i] *= 0.3;
        }
        if (!isFlagSet(0x38, FLAG_TYPE_TEMPORARY) && !isFlagSet(0x145, FLAG_TYPE_PERMANENT)) {
            playCutscene(current_actor_pointer, 0, 1);
            func_global_asm_80629174();
            setFlag(0x38, TRUE, FLAG_TYPE_TEMPORARY);
        } else {
            a178->unk35 = 3;
        }
        D_global_asm_80750AC8 = 0xA;
        func_global_asm_8066E5F8(current_actor_pointer, 4, 8);
    }
    switch (a178->unk34) {
        case 0:
            func_race_8002B518(a178);
            break;
        case 1:
            func_race_8002B610(a178, a17C);
            break;
        case 4:
            func_race_8002B6F4(a178, a17C->unk4);
            break;
        case 5:
            func_race_8002B76C(a178, a17C->unk4);
            break;
    }
    if (a178->unk34 < 5) {
        func_race_8002E644(a17C);
        func_race_8002B180(a178, a17C);
        func_race_8002A7F8(a178);
        func_race_800283D4(current_actor_pointer->unkB8 * 0.0307692308f);
    } else {
        current_actor_pointer->unkB8 = 0.0f;
    }
    renderActor(current_actor_pointer, 0);
}
