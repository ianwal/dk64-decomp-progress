#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x36 - 0];
    u8 unk36;
} Struct8002E8EC_arg0;

typedef struct {
    u8 unk0[0x45 - 0];
    u8 unk45;
} Struct8002E8EC_arg1;

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

void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, void *arg3);
void func_race_8002BCB0(Actor *arg0, s32 arg1, s32 *arg2, s32 *arg3);
f32 func_race_8002D2C0(void *arg0);
s32 func_race_8002E8EC(void *arg0, void *arg1, s32 arg2);

void func_global_asm_80690190(void *arg0, void *arg1);
void func_global_asm_8068F72C(void*, void*, s32, s32);
void func_global_asm_8068FF40(s32, void*, void*);

extern s32 D_race_8002FC5C[];

Gfx *func_race_800292B0(Gfx *dl, Actor *arg1) {
    return func_race_8002CAC8(dl, arg1, arg1->additional_actor_data);
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
    Actor178 *a178;
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
    RaceAdditionalActorData *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    a178 = current_actor_pointer->unk178;
    Player = character_change_array[aaD->unk28].player_pointer;
    PaaD = Player->additional_actor_data;
    sp52 = current_actor_pointer->unk6A & 1;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80690094(current_actor_pointer, Player);
        current_actor_pointer->noclip_byte |= 0x10;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFF;
        aaD->unk44 = 5;
        func_global_asm_8066E5F8(current_actor_pointer, 2, 0xC);
    }
    func_global_asm_80690190(aaD, a178);
    if (aaD->unk34 < 5) {
        if (aaD->unk34 == 1) {
            Actor *temp = aaD->unk30;
            temp_s0 = temp->additional_actor_data;
            if (aaD->unk35 == 0) {
                func_global_asm_806F8BC4(0xB, 1, 0);
                aaD->unk35++;
            }
            if (temp_s0->unk1C == 0x3C) {
                func_global_asm_8061C6A8(PaaD->unk104, current_actor_pointer, 4, 0x800, 0x32, 0, 0x28, 0x1E, 0x14, 0, 0.4f);
            }
        }
        if (aaD->unk34 == 2) {
            if (aaD->unk26 != 0) {
                aaD->unk4 = func_race_8002D2C0(aaD) * 2;
                if (aaD->unk4 > 1.0) {
                    aaD->unk25 = 0x14;
                }
                aaD->unk26 = 0;
            }
            if (aaD->unk25 != 0) {
                aaD->unk25--;
            }
        }
        func_global_asm_8068F72C(aaD, a178, 1, 1);
        if (!gameIsInDKTVMode()) {
            addActorToTextOverlayRenderArray(func_race_800292B0, current_actor_pointer, 3);
        }
    } else if (aaD->unk34 == 5) {
        if (aaD->unk35 == 0) {
            current_actor_pointer->object_properties_bitfield &= ~4;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806F8D58(0xB, 0);
            aaD->unk35++;
            for (i = 0; i < 2; i++) {
                if (current_actor_pointer->unk6E[i] != -1) {
                    func_global_asm_80605314(current_actor_pointer, i);
                }
            }
        }
    }
    func_global_asm_8068FF40(sp52, aaD, a178);
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
