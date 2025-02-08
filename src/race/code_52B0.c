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

// .data
typedef struct {
    f32 unk0;
    f32 unk4;
} Struct8002FC20;

static Struct8002FC20 D_race_8002FC20[] = {
    { -1000.0f, 0.8f },
};

static Struct8002FC20 D_race_8002FC28[] = {
    { -150.0f, 1.0f },
};

static Struct8002FC20 D_race_8002FC30[] = {
    { -70.0f, 1.0f },
    { 90.0f, 1.0f },
    { 100.0f, 1.0f },
    { 200.0f, 2.5f },
};

static f32 D_race_8002FC50[] = {
    0.8f,
    1.0f,
};

static f32 D_race_8002FC58 = 2.5f;

static s32 D_race_8002FC5C[] = {
    0x00000003,
    0x00000000,
    0x00000001,
    0x00000002,
    0x00000000, // PADDING
};

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
            if (var_f12 < 0) {
                var_f12 = 0.01f;
            }
            var_f12 /= MAX(0.01, temp_v0->unk24);
            if (var_f12 > 2) {
                var_f12 = 2;
            }
            func_global_asm_80614D00(arg0, var_f12, 0);
        }
    }
}

s32 func_race_8002A080(Struct8002E8EC_arg0 *arg0, Struct8002E8EC_arg1 *arg1) {
    return D_race_8002FC5C[func_race_8002E8EC(arg0, arg1, 0xA)];
}

// Jumptable, doable, close, stack
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002A0AC.s")

extern s16 D_global_asm_80750AC8;

typedef struct {
    Actor *unk0;
    Struct8002E8EC_arg1 *unk4;
    u8 unk8;
    u8 unk9;
    u16 unkA;
} A180_8002A0AC;

typedef struct {
    s32 unk0; // Unused?
    f32 unk4;
    s32 unk8; // Unused?
    s32 unkC; // Unused?
    f32 unk10;
    u8 unk14[0x30 - 0x14];
    Actor *unk30;
    u8 unk34;
    u8 unk35;
} A178_8002A0AC;

typedef struct {
    u8 unk0[0x1C - 0x0];
    u16 unk1C;
} AAD_8002A0AC;

/*
void func_race_8002A0AC(void) {
    void *sp50;
    A180_8002A0AC *a180; // 4C
    f32 sp48;
    AAD_8002A0AC *aaD;
    A178_8002A0AC *a178;
    Struct8002E8EC_arg1 *sp34;
    ActorAnimationState *aaS;
    f32 var_f2;
    s32 pad;
    s32 sp2C;
    u16 temp_a0;
    u8 temp_a1;

    a178 = current_actor_pointer->a178;
    sp50 = current_actor_pointer->unk17C;
    a180 = current_actor_pointer->unk180;
    sp48 = 0.0f;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        aaD = a178->unk30->additional_actor_data;
        a178->unk10 = 1.0f;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFE;
        current_actor_pointer->draw_distance = 1500;
        func_race_8002DE78(a180, 5, &D_race_8002FC20, &D_race_8002FC50);
        a178->unk34 = 0;
        func_global_asm_8061CC30();
        temp_a0 = playCutscene(current_actor_pointer, 1, 1) - 0x3C;
        aaD->unk1C = temp_a0;
        a180->unkA = temp_a0;
        a178->unk4 = 1.0f;
        D_global_asm_807FDC90->unk25 = D_global_asm_807FDC9C->unk11 - 5;
        temp_a1 = D_global_asm_807FDC98->unk20[D_global_asm_807FDC90->unk25].unk0;
        current_actor_pointer->x_position = D_global_asm_807FDCA0->unk14[temp_a1].unk0;
        current_actor_pointer->y_position = D_global_asm_807FDCA0->unk14[temp_a1].unk2;
        current_actor_pointer->z_position = D_global_asm_807FDCA0->unk14[temp_a1].unk4;
        D_global_asm_80750AC8 = 0xA;
    }
    if (a180->unkA != 0) {
        a180->unkA--;
    }
    if (a178->unk34 < 5) {
        sp48 = func_race_8002978C();
        if (a178->unk34 == 2) {
            func_race_8002E644(a180);
        } else if (a178->unk34 == 4) {
            if (a180->unk8 == 0) {
                a180->unk8 = 1;
                if (!isFlagSet(0xA5, FLAG_TYPE_PERMANENT)) {
                    playCutscene(a180->unk0, 0, 1);
                    func_global_asm_80629174();
                } else {
                    func_global_asm_805FF544();
                }
            }
        }
        func_global_asm_8068F72C(a178, sp50, 0, 0);
    }
    if (a178->unk34 == 5) {
        switch (a178->unk35) {
            case 0:
                if (!isFlagSet(0xA5, FLAG_TYPE_PERMANENT)) {
                    setAction(0x55, NULL, 0);
                    current_actor_pointer->x_rotation = 0;
                    current_actor_pointer->z_rotation = 0;
                    playActorAnimation(current_actor_pointer, 0x29A);
                }
                a178->unk35++;
                break;
            case 1:
                if (func_global_asm_80629148()) {
                    sp34 = a180->unk4;
                    func_global_asm_80629174();
                    loadText(current_actor_pointer, 0x12, func_race_8002A080(a178, sp34));
                    a178->unk35++;
                }
                break;
            case 2:
                if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                    func_global_asm_8061CB08();
                    a178->unk35++;
                }
                break;
            case 3:
                if (func_global_asm_80629148()) {
                    sp2C = func_race_8002A080(a178, a180->unk4);
                    func_global_asm_80629174();
                    if (!sp2C) {
                        func_global_asm_8063DA40(0x3B, 0xA);
                        setFlag(0xA5, TRUE, FLAG_TYPE_PERMANENT);
                    } else {
                        func_global_asm_806ACC00(1);
                        a178->unk35++;
                    }
                    a178->unk35++;
                }
                break;
            case 4:
                if (func_global_asm_80629148()) {
                    func_global_asm_80629174();
                    func_global_asm_805FF544();
                    a178->unk35++;
                }
                break;
        }
    } else {
        //
    }
    aaS = current_actor_pointer->animation_state;
    switch (aaS->unk64) {
        case 0x29E:
        case 0x2A2:
            var_f2 = MAX(0.1, current_actor_pointer->unkB8 * 0.0025f);
            func_global_asm_80614D00(current_actor_pointer, var_f2, 10.0f);
            break;
        case 0x2A0:
            if (aaS->unk0->unk10 == 0x4A7) {
                // TODO: a1 is wrong
                func_race_80029F88(current_actor_pointer, 0, current_actor_pointer->unkB8 - a180->unk0->unkB8, (sp48 - D_race_8002FC30[0].unk0) * 40.0f, 23.0f);
                break;
            }
        default:
            if (aaS->unk0->unk10 != 0x49B) {
                func_global_asm_80614D00(current_actor_pointer, 1.0f, 10.0f);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
}
*/
