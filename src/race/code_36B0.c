#include <ultra64.h>
#include "functions.h"

extern s32 D_8002FC5C[];
extern s32 D_8002FCAC[];

typedef struct {
    u8 unk0[0x36 - 0];
    u8 unk36;
} Struct8002E8EC_arg0;

typedef struct {
    u8 unk0[0x45 - 0];
    u8 unk45;
} Struct8002E8EC_arg1;

s32 func_8002E8EC(Struct8002E8EC_arg0 *arg0, Struct8002E8EC_arg1 *arg1, s32 arg2);
void func_80025E9C(Actor *);
void func_80025FDC();
void func_80029488();
void func_8002E9F8(s32 *checkpointFile);
void func_8002BCD4(Actor *);
void func_8002D064();
void func_8002D0FC();

void func_805FF544();

typedef struct {
    u8 pad0[0x10 - 0x0];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
} RaceStruct1;

extern f32 D_8002FE68;
extern s32 D_8071FFA0; // TODO: Datatype
extern s32 D_80720340; // TODO: Datatype
extern s32 D_80720120;
extern f32 D_8002FF84;
extern s16 D_80770628[];
extern f32 D_80770B68[];
extern f32 D_80770BC0[];

extern void func_8002CFF0();

f32 func_8000AC60(f32);
f32 func_80665E48(f32, f32, f32, f32);
extern f64 D_8002FDD8;
extern f64 D_8002FDE0;
extern f64 D_8002FDE8;

typedef struct RaceStruct15 {
    s16 unk0;
    u16 unk2;
} RaceStruct15;
s32 func_800276B0(s32 arg0, RaceStruct15 *arg1, RaceStruct15 *arg2) {
    s32 var_v0;
    s32 sign;
    s32 var_v1;

    var_v1 = arg2->unk2 - arg1->unk2;
    if (var_v1 > 0) {
        var_v0 = var_v1;
    } else {
        var_v0 = -var_v1;
    }
    if ((arg0 / 2) < var_v0) {
        if (var_v1 >= 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        var_v1 -= sign * arg0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027880.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80027880;

extern Struct80027880 *D_807F5FD4;

/*
// TODO: Very close
void func_80027880(s32 arg0, u16 arg1, u16 arg2) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 temp;

    temp = func_80025770(arg0, arg1);
    
    dx = D_807F5FD4[arg1][arg2].unk0 - D_807F5FD4[arg1][temp].unk0;
    dy = D_807F5FD4[arg1][arg2].unk4 - D_807F5FD4[arg1][temp].unk4;
    dz = D_807F5FD4[arg1][arg2].unk8 - D_807F5FD4[arg1][temp].unk8;
    func_8000AC60((dx * dx) + (dy * dy) + (dz * dz));
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027920.s")

typedef struct RaceStruct3 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} RaceStruct3;

void func_80027AF8(RaceStruct3 *arg0, s8 arg1) {
    if (arg1 > 0) {
        arg0->unk1++;
    } else {
        arg0->unk1--;
    }
    arg0->unk8 = 0.0f;
}

s32 func_806119A0(void);

void func_80027B30(RaceStruct3 *arg0) {

    switch (arg0->unk0) {
        case 0:
            arg0->unk1++;
            break;
        case 1:
            if ((u8)func_806119A0() >= 0x80U) {
                arg0->unk1++;
            } else {
                arg0->unk1--;
            }
            break;
        case 2:
            arg0->unk1--;
            break;
    }
    arg0->unk8 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027BD0.s")

void func_80027C60(void) {
    s32 phi_s0;

    for (phi_s0 = 1; phi_s0 != 3; phi_s0++) {
        func_807149B8(1);
        func_80714C08(&D_80720120, 1.0f, current_actor_pointer, phi_s0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027CE8.s")

// Huh, actor184 stuff...?
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800280E8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800282D8.s")

void func_800283D4(f32 arg0) {
    s32 temp_a0;

    temp_a0 = D_80770628[current_actor_pointer->unk6E[0]];
    current_actor_pointer->unk74 = 1.0f;
    D_80770B68[temp_a0] = (arg0 * D_8002FF84) + 1.0;
    D_80770BC0[temp_a0] = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028AD0.s")

// Doable, looks like an unrolled loop
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028E20.s")

// TODO: Actor17C stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80029054.s")

s32 func_8002CAC8(s32 arg0, Actor *arg1, RaceAdditionalActorData *arg2);

void func_800292B0(s32 arg0, Actor *arg1) {
    func_8002CAC8(arg0, arg1, arg1->additional_actor_data);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800292D0.s")

// need this forward declaration
void initializeSealRace();
void sealRaceSetup() {
    initializeSealRace();
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800294A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002978C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80029F88.s")

extern f64 D_8002FFF0;
extern f32 D_8002FFEC;

/*
// TODO: hmm
void func_80029F88(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
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
                var_f12 = D_8002FFEC;
            }
            var_f12 /= MIN(temp_v0->unk24, D_8002FFF0);
            if (var_f12 > 2.0f) {
                var_f12 = 2.0f;
            }
            func_80614D00(arg0, var_f12, 0.0f);
        }
    }
}
*/

s32 func_8002A080(Struct8002E8EC_arg0 *arg0, Struct8002E8EC_arg1 *arg1) {
    return D_8002FC5C[func_8002E8EC(arg0, arg1, 0xA)];
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002A0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/initializeCastleCarRace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002A7F8.s")

void func_8002AE6C(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8068E474(func_8002CAC8(arg0, arg1, arg1->PaaD), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002AE9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B180.s")

typedef struct {
    u8 unk0[0x30 - 0x0];
    Actor *unk30;
    u8 unk34;
    u8 unk35;
} Struct8002B610_arg0;

void func_8002D72C(Actor *arg0);
void func_8002D754(Actor *arg0);

void func_8002B518(Struct8002B610_arg0 *arg0) {
    switch (arg0->unk35) {
        case 0:
            if (current_actor_pointer->object_properties_bitfield & 0x02000000) {
                arg0->unk35++;
            }
            break;
        case 1:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                func_8061CB08();
                arg0->unk35++;
            }
            break;
        case 2:
            if (func_80629148() != 0) {
                func_80629174();
                arg0->unk35++;
            }
            break;
    }
    if (arg0->unk35 < 3) {
        func_8002D72C(arg0->unk30);
        return;
    }
    func_8002D754(arg0->unk30);
}

extern f32 D_8003008C;

typedef struct {
    u8 unk0[0x28 - 0x0];
    u8 unk28;
} Struct8002B610_arg4;

typedef struct {
    s32 unk0;
    Struct8002B610_arg4 *unk4;
} Struct8002B610_arg1;

void func_8061C6A8(Actor *, Actor *, s32, s32, s32, s32, s32, s32, s32, s32, f32);

void func_8002B610(Struct8002B610_arg0 *arg0, Struct8002B610_arg1 *arg1) {
    if (arg0->unk35 == 0) {
        Struct8002B610_arg4 *T = arg1->unk4;
        Actor *A = character_change_array[T->unk28].player_pointer;
        PlayerAdditionalActorData *PaaD = A->PaaD;
        func_8061C6A8(PaaD->unk104, arg1->unk0, 4, 0x800, 0xBE, 0, 0x4A, 0xAE, 0x2D, 0, D_8003008C);
        arg0->unk35++;
    }
    func_800282D8();
}

s32 func_8002B6C8(Struct8002E8EC_arg1 *arg0, Struct8002E8EC_arg1 *arg1) {
    return D_8002FCAC[func_8002E8EC(arg0, arg1, 0xA)];
}

typedef struct RaceStruct7 {
    u8 pad0[0x35];
    u8 unk35;
} RaceStruct7;

void func_8002B6F4(RaceStruct7 *arg0, s32 arg1) {
    if (arg0->unk35 == 0) {
        // Castle: Tiny GB: Car Race
        if (!isFlagSet(0x145, FLAG_TYPE_PERMANENT)) {
            playCutscene(current_actor_pointer, 1, 1);
            func_80629174();
        } else {
            func_805FF544();
        }
        arg0->unk35++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B76C.s")

void func_8002DE78(void *, s32, void *, s32);

extern s32 D_8002FC70;
extern s32 D_8002FCA0;
extern f64 D_800300A8;
extern f32 D_800300B0;
extern s16 D_80750AC8;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10; // Used
    u8 unk14[0x34 - 0x14];
    u8 unk34; // Used
    u8 unk35; // Used
} A178_8002B964;

typedef struct {
    s32 unk0;
    s32 unk4; // Used
    s32 unk8;
    s32 unkC;
    s8 unk10; // Used
} A17C_8002B964;

void func_8002B964(void) {
    A178_8002B964 *a178;
    A17C_8002B964 *a17C;
    f64 temp_f18;
    s32 i;

    a178 = current_actor_pointer->unk178;
    a17C = current_actor_pointer->unk17C;
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        a17C->unk10 = 1;
        func_8002DE78(a17C, 5, &D_8002FC70, &D_8002FCA0);
        current_actor_pointer->noclip_byte = 0x3C;
        i = 0;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFE;
        a178->unk10 = 1.0f;
        temp_f18 = D_800300A8;
        for (i = 0; i < 3; i++) {
            current_actor_pointer->animation_state->scale[i] *= temp_f18;
        }
        if (isFlagSet(0x38, 2) == 0 && isFlagSet(0x145, 0) == 0) {
            playCutscene(current_actor_pointer, 0, 1);
            func_80629174();
            setFlag(0x38, 1, 2);
        } else {
            a178->unk35 = 3;
        }
        D_80750AC8 = 0xA;
        func_8066E5F8(current_actor_pointer, 4, 8);
    }
    switch (a178->unk34) {
        case 0:
            func_8002B518(a178);
            break;
        case 1:
            func_8002B610(a178, a17C);
            break;
        case 4:
            func_8002B6F4(a178, a17C->unk4);
            break;
        case 5:
            func_8002B76C(a178, a17C->unk4);
            break;
    }
    if (a178->unk34 < 5) {
        func_8002E644(a17C);
        func_8002B180(a178, a17C);
        func_8002A7F8(a178);
        func_800283D4(current_actor_pointer->unkB8 * D_800300B0);
    } else {
        current_actor_pointer->unkB8 = 0.0f;
    }
    func_806319C4(current_actor_pointer, 0);
}
