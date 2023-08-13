#include <ultra64.h>
#include "functions.h"


s32 func_race_8002CAC8(s32 arg0, Actor *arg1, RaceAdditionalActorData *arg2);
void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, void *arg3);
void func_race_8002BBD0(Actor *arg0, s32 arg1);
void func_race_8002BCB0(Actor *arg0, s32 arg1, s32 *arg2, s32 *arg3);

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
    u8 unk28;
    u8 unk29[0x30 - 0x29];
    s32 unk30;
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

void func_race_800292B0(s32 arg0, Actor *arg1) {
    func_race_8002CAC8(arg0, arg1, arg1->additional_actor_data);
}

void func_race_800292D0(Actor *arg0) {
    AAD_initializeCastleCarRace_arg0 *aaD;
    AAD_Car_Castle_Player *sp58;
    Actor *sp54;
    A17C_initializeCastleCarRace *temp_a2;
    s32 var_s1;
    s32 playerIndex;
    s32 var_s5;

    var_s5 = cc_number_of_players;
    var_s1 = 0;
    aaD = arg0->additional_actor_data;
    if (var_s5 == 1) {
        var_s5++;
    }
    func_race_8002BBD0(arg0, var_s5);
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        func_global_asm_80677FA8(ACTOR_UNKNOWN_307, 0x9F);
        sp54 = D_global_asm_807FBB44;
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
    for (playerIndex = 0; playerIndex < var_s5; playerIndex++) {
        func_race_8002BCB0(arg0, playerIndex, &sp54, &sp58);
        sp58->unk36 = playerIndex;
        sp58->unk30 = arg0;
        if (sp58->unk27 == 0) {
        func_global_asm_806903BC(sp54, sp58);
        }
    }
    aaD->unk26 = 0;
}

// need this forward declaration
void initializeSealRace();
void sealRaceSetup() {
    initializeSealRace();
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_800294A8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002978C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_80029F88.s")

extern f64 D_race_8002FFF0;
extern f32 D_race_8002FFEC;

/*
// TODO: hmm
void func_race_80029F88(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_f2;
    f32 var_f12;
    f64 var_f2;
    AnimationStateUnk0 *temp_v0;

    temp_v0 = arg0->animation_state->unk0;
    if (arg2 != 0.0f) {
        temp_f2 = arg3 / arg2;
        if (!(temp_f2 <= 0.0f)) {
            var_f12 = (arg4 - temp_v0->unk4) / temp_f2;
            if (var_f12 < 0.0f) {
                var_f12 = D_race_8002FFEC;
            }
            var_f12 /= MIN(temp_v0->unk24, D_race_8002FFF0);
            if (var_f12 > 2.0f) {
                var_f12 = 2.0f;
            }
            func_global_asm_80614D00(arg0, var_f12, 0.0f);
        }
    }
}
*/

typedef struct {
    u8 unk0[0x36 - 0];
    u8 unk36;
} Struct8002E8EC_arg0;

typedef struct {
    u8 unk0[0x45 - 0];
    u8 unk45;
} Struct8002E8EC_arg1;

extern s32 D_race_8002FC5C[];

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
    s32 var_s5;

    var_s5 = cc_number_of_players;
    var_s1 = 0;
    aaD = arg0->additional_actor_data;
    if (var_s5 == 1) {
        var_s5++;
    }
    func_race_8002BBD0(arg0, var_s5);
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        func_global_asm_80677FA8(ACTOR_CAR_CASTLE_PLAYER, 0x95);
        sp54 = D_global_asm_807FBB44;
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
    for (playerIndex = 0; playerIndex < var_s5; playerIndex++) {
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

typedef struct {
    u8 unk0[0x30 - 0x0];
    Actor *unk30;
    u8 unk34;
    u8 unk35;
} Struct8002B610_arg0;

void func_race_8002D72C(Actor *arg0);
void func_race_8002D754(Actor *arg0);

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
            if (func_global_asm_80629148() != 0) {
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

extern f32 D_race_8003008C;

typedef struct {
    u8 unk0[0x28 - 0x0];
    u8 unk28;
} Struct8002B610_arg4;

typedef struct {
    s32 unk0;
    Struct8002B610_arg4 *unk4;
} Struct8002B610_arg1;

void func_global_asm_8061C6A8(Actor *, Actor *, s32, s32, s32, s32, s32, s32, s32, s32, f32);

void func_race_8002B610(Struct8002B610_arg0 *arg0, Struct8002B610_arg1 *arg1) {
    if (arg0->unk35 == 0) {
        Struct8002B610_arg4 *T = arg1->unk4;
        Actor *A = character_change_array[T->unk28].player_pointer;
        PlayerAdditionalActorData *PaaD = A->PaaD;
        func_global_asm_8061C6A8(PaaD->unk104, arg1->unk0, 4, 0x800, 0xBE, 0, 0x4A, 0xAE, 0x2D, 0, D_race_8003008C);
        arg0->unk35++;
    }
    func_race_800282D8();
}

extern s32 D_race_8002FCAC[];

s32 func_race_8002B6C8(Struct8002E8EC_arg1 *arg0, Struct8002E8EC_arg1 *arg1) {
    return D_race_8002FCAC[func_race_8002E8EC(arg0, arg1, 0xA)];
}

typedef struct RaceStruct7 {
    u8 pad0[0x35];
    u8 unk35;
} RaceStruct7;

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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_52B0/func_race_8002B76C.s")

void func_race_8002DE78(void *, s32, void *, s32);

extern s32 D_race_8002FC70;
extern s32 D_race_8002FCA0;
extern f64 D_race_800300A8;
extern f32 D_race_800300B0;
extern s16 D_global_asm_80750AC8;

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

void func_race_800283D4(f32 arg0);

void func_race_8002B964(void) {
    A178_race_8002B964 *a178;
    A17C_race_8002B964 *a17C;
    f64 temp_f18;
    s32 i;

    a178 = current_actor_pointer->unk178;
    a17C = current_actor_pointer->unk17C;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        a17C->unk10 = 1;
        func_race_8002DE78(a17C, 5, &D_race_8002FC70, &D_race_8002FCA0);
        current_actor_pointer->noclip_byte = 0x3C;
        i = 0;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFE;
        a178->unk10 = 1.0f;
        temp_f18 = D_race_800300A8;
        for (i = 0; i < 3; i++) {
            current_actor_pointer->animation_state->scale[i] *= temp_f18;
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
        func_race_800283D4(current_actor_pointer->unkB8 * D_race_800300B0);
    } else {
        current_actor_pointer->unkB8 = 0.0f;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}
