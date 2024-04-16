#include <ultra64.h>
#include "functions.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10; // Used
    u8 unk14[0x34 - 0x14];
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
    u8 unk0[0x36 - 0];
    u8 unk36;
} Struct8002E8EC_arg0;

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
    u8 unk0[0x27 - 0x0];
    u8 unk27;
} A178_initializeCastleCarRace;

typedef struct {
    s32 unk0;
    s32 unk4;
} A17C_initializeCastleCarRace;

void func_race_800283D4(f32 arg0);
void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, void *arg3);
void func_race_8002BCB0(Actor *arg0, s32 arg1, s32 *arg2, s32 *arg3);
f32 func_race_8002D2C0(void *arg0);
void func_race_8002D72C(Actor *arg0);
void func_race_8002D754(Actor *arg0);
void func_race_8002DE78(void *, s32, void *, s32);
s32 func_race_8002E8EC(void *arg0, void *arg1, s32 arg2);
void initializeSealRace(void);

void func_global_asm_80690190(void *arg0, s32 arg1);
void func_global_asm_8068F72C(s32, s32, s32, s32);
void func_global_asm_8068FF40(s32, s32, s32);

extern s32 D_race_8002FC5C[];
extern s32 D_race_8002FC70;
extern s32 D_race_8002FCA0;
extern s32 D_race_8002FCAC[];

extern s16 D_global_asm_80750AC8;

Gfx *func_race_800292B0(Gfx *dl, Actor *arg1) {
    return func_race_8002CAC8(dl, arg1, arg1->RaaD);
}

void func_race_800292D0(Actor *arg0) {
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
        spawnActor(ACTOR_UNKNOWN_307, 0x9F);
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
        temp_a2 = sp54->unk180;
        func_race_8002BCB0(arg0, 0, temp_a2, &temp_a2->unk4);
        aaD->unk25 = 1;
    } else {
        aaD->unk25 = 0;
    }
    for (playerIndex = 0; playerIndex < numRacers; playerIndex++) {
        func_race_8002BCB0(arg0, playerIndex, &sp54, &sp58);
        sp58->unk36 = playerIndex;
        sp58->unk30 = arg0;
        if (sp58->unk27 == 0) {
        func_global_asm_806903BC(sp54, sp58);
        }
    }
    aaD->unk26 = 0;
}

void sealRaceSetup(void) {
    initializeSealRace();
}

void func_race_800294A8(void) {
    s32 pad;
    Actor178 *sp68;
    s32 pad2;
    s32 pad3;
    s32 pad4;
    s32 pad7;
    s32 pad5;
    u8 pad6;
    u8 sp52;
    s32 pad8;
    s32 pad9;
    Actor *Player;
    s32 i;
    s32 var_s1;
    RaceAdditionalActorData *temp_s0;
    PlayerAdditionalActorData *PaaD;
    RaceAdditionalActorData *temp_s4;

    temp_s4 = current_actor_pointer->additional_actor_data;
    sp68 = current_actor_pointer->unk178;
    Player = character_change_array[temp_s4->unk28].player_pointer;
    PaaD = Player->additional_actor_data;
    sp52 = current_actor_pointer->unk6A & 1;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80690094(current_actor_pointer, Player);
        current_actor_pointer->noclip_byte |= 0x10;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFF;
        temp_s4->unk44 = 5;
        func_global_asm_8066E5F8(current_actor_pointer, 2, 0xC);
    }
    func_global_asm_80690190(temp_s4, sp68);
    if (temp_s4->unk34 < 5) {
        if (temp_s4->unk34 == 1) {
            Actor *temp = temp_s4->unk30;
            temp_s0 = temp->additional_actor_data;
            if (temp_s4->unk35 == 0) {
                func_global_asm_806F8BC4(0xB, 1, 0);
                temp_s4->unk35++;
            }
            if (temp_s0->unk1C == 0x3C) {
                func_global_asm_8061C6A8(PaaD->unk104, current_actor_pointer, 4, 0x800, 0x32, 0, 0x28, 0x1E, 0x14, 0, 0.4f);
            }
        }
        if (temp_s4->unk34 == 2) {
            if (temp_s4->unk26 != 0) {
                temp_s4->unk4 = func_race_8002D2C0(temp_s4) * 2;
                if (temp_s4->unk4 > 1.0) {
                    temp_s4->unk25 = 0x14;
                }
                temp_s4->unk26 = 0;
            }
            if (temp_s4->unk25 != 0) {
                temp_s4->unk25--;
            }
        }
        func_global_asm_8068F72C(temp_s4, sp68, 1, 1);
        if (!gameIsInDKTVMode()) {
            addActorToTextOverlayRenderArray(&func_race_800292B0, current_actor_pointer, 3);
        }
    } else if (temp_s4->unk34 == 5) {
        if (temp_s4->unk35 == 0) {
            current_actor_pointer->object_properties_bitfield &= ~4;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806F8D58(0xB, 0);
            temp_s4->unk35++;
            for (i = 0; i < 2; i++) {
                if (current_actor_pointer->unk6E[i] != -1) {
                    func_global_asm_80605314(current_actor_pointer, i);
                }
            }
        }
    }
    func_global_asm_8068FF40(sp52, temp_s4, sp68);
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002978C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_80029F88.s")

/*
// TODO: hmm
void func_race_80029F88(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_f2;
    f32 var_f12;
    f64 var_f2;
    AnimationStateUnk0 *temp_v0;
    f32 temp;

    temp_v0 = arg0->animation_state->unk0;
    temp_f2 = arg3 / arg2;
    temp = temp_v0->unk4;
    if (arg2 != 0.0f) {
        if (!(temp_f2 <= 0.0f)) {
            var_f12 = (arg4 - temp) / temp_f2;
            if (var_f12 < 0.0f) {
                var_f12 = 0.01f;
            }
            var_f12 /= MIN(0.01, temp_v0->unk24);
            if (var_f12 > 2.0f) {
                var_f12 = 2.0f;
            }
            func_global_asm_80614D00(arg0, var_f12, 0.0f);
        }
    }
}
*/

s32 func_race_8002A080(Struct8002E8EC_arg0 *arg0, Struct8002E8EC_arg1 *arg1) {
    return D_race_8002FC5C[func_race_8002E8EC(arg0, arg1, 0xA)];
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002A0AC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002A7F8.s")

void func_race_8002AE6C(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_global_asm_8068E474(func_race_8002CAC8(arg0, arg1, arg1->PaaD), arg1);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002AE9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002B180.s")

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
                    setFlag(0x145, 1, 0);
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
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFE;
        a178->unk10 = 1.0f;
        for (i = 0; i < 3; i++) {
            current_actor_pointer->animation_state->scale[i] *= 0.3;
        }
        if (isFlagSet(0x38, 2) == 0 && isFlagSet(0x145, 0) == 0) {
            playCutscene(current_actor_pointer, 0, 1);
            func_global_asm_80629174();
            setFlag(0x38, 1, 2);
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
