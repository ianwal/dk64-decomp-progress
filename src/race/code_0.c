#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80024000.s")

extern s32 D_8002FC5C[];
extern s32 D_8002FCAC[];

extern u16 D_80750AC4;

s32 func_8002E8EC(s32, s32, s32);
s32 func_8002E8EC(s32 arg0, s32 arg1, s32 arg2);
void func_80025E9C(Actor *);
void func_80025FDC();
void func_80029488();
void func_8002E9F8(s32 *checkpointFile);
void func_8002BCD4(Actor *);
void func_8002D064();
void func_8002D0FC();

void func_805FF544();

typedef struct RaceStruct8 {
    u8 pad0[0x36];
    u8 unk36;
} RaceStruct8;

typedef struct RaceStruct9 {
    u8 pad0[0x1A];
    s16 unk1A; // Flag index
    s32 unk1C;
} RaceStruct9;

int func_80024634(RaceStruct8 *arg0, RaceStruct9 *arg1) {
    return arg0->unk36 && 
           !isFlagSet(arg1->unk1A, FLAG_TYPE_PERMANENT) &&
           arg1->unk1C <= D_80750AC4;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80024690.s")

s32 func_80025770(s32 arg0, s32 arg1) {
    s32 temp_v1 = arg1 + 1;
    if (arg0 != temp_v1) {
        return arg1 + 1;
    }
    return 0;
}

s32 func_8002578C(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return arg0 - 1;
    }
    return arg1 - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800257A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002597C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80025E9C.s")

/*
void func_80025E9C(Actor *arg0) {
    RaceAdditionalActorData *sp54;
    Actor *sp40;
    Actor *sp3C;
    Actor *temp_s2;
    Actor *temp_v0;
    Actor *temp_v1_2;
    Actor178 *temp_s0_2;
    Actor178 *temp_s1;
    Actor17C *temp_s1_2;
    RaceAdditionalActorData *temp_s0;
    void *temp_v1;

    sp54 = arg0->additional_actor_data;
    func_8002BBD0(2);
    func_80677FA8(0x12E, 0x95);
    temp_s2 = D_807FBB44;
    temp_s0 = temp_s2->additional_actor_data;
    func_8002BC2C(arg0, 1, temp_s2, temp_s0);
    temp_s0->unk37 = 0;
    temp_s0->unk27 = 0;
    temp_s0->unk30 = arg0;
    temp_s0->unk36 = 1;
    temp_s0->unk28 = 0;
    temp_s1 = temp_s2->unk178;
    temp_v0 = func_807271F4(1, 0, 0, 0, 0, 0, 0);
    sp40 = temp_v0;
    temp_s1->unk30 = temp_v0;
    temp_v1 = temp_v0->unk184;
    temp_v1->unk4 = temp_s0;
    temp_v1->unk0 = temp_s2;
    func_80677FA8(0x130, 0);
    temp_v1_2 = D_807FBB44;
    temp_s1->unk34 = temp_v1_2;
    temp_s0_2 = sp40->unk178;
    sp3C = temp_v1_2;
    func_8002BC2C(arg0, 0, sp40, temp_s0_2);
    temp_s0_2->unk37 = 0;
    temp_s0_2->unk27 = 1;
    temp_s0_2->unk30 = arg0;
    temp_s0_2->unk36 = 0;
    temp_s1_2 = sp40->unk17C;
    temp_s1_2->unk30 = temp_s2;
    temp_s1_2->unk34 = temp_v1_2;
    temp_v1_2->RaaD->unk30 = arg0;
    temp_v1_2->unk178->unk30 = temp_s2;
    D_80750AC4 = 0;
    sp54->unk25 = 1;
}
*/

extern void func_8002CFF0();

void func_80025FDC() {
    func_8002597C();
    func_8002CFF0();
}

typedef struct {
    u8 pad0[0x10 - 0x0];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
} RaceStruct1;

void func_80026004(RaceStruct1 *arg0, u8 arg1, f32 arg2) {
    arg0->unk10 = arg1;
    arg0->unk14 = arg2;
    playSound(0x1EB, 0x7FFF, 64.0f, 1.0f, 0, 0);
}

// TODO: Any struct overlap with existing structs?
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10[4];
    s32 unk20;
    u8 unk24;
    u8 unk25;
    u16 unk26;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s16 unk34;
    s8 unk36;
    s8 unk37;
    s8 unk38;
    s8 unk39;
    u16 unk3A;
} RaceStruct6;

void func_80026050(RaceStruct6 *arg0, RaceStruct6 *arg1, s32 arg2) {
    if (arg2 != (arg0->unk2 + 1)) {
        arg0->unk2++;
    } else {
        arg0->unk2 = 0;
        if (arg1 != 0) {
            arg1->unk37++;
        }
    }
    if (arg1 != 0) {
        arg1->unk3A = arg0->unk2 + 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80026098.s")

f32 func_8000AC60(f32);
f32 func_80665E48(f32, f32, f32, f32);
extern f64 D_8002FDD8;
extern f64 D_8002FDE0;
extern f64 D_8002FDE8;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80026098;

/*
// TODO: Float regalloc and stack nonsense
void func_80026098(Struct80026098 *arg0, Struct80026098 *arg1) {
    s16 sp2E;
    f32 sp24;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp;

    sp2E = (func_80665E48(arg0->unk0, arg0->unk8, arg1->unk0, arg1->unk8) * 2048.0) / D_8002FDD8;
    temp_f2 = arg1->unk8 - arg0->unk8;
    temp_f14 = arg1->unk0 - arg0->unk0;
    sp24 = current_actor_pointer->unkB8 * D_8002FDE0 * func_8000AC60((temp_f2 * temp_f2) + (temp_f14 * temp_f14));
    current_actor_pointer->x_position = arg1->unk0 + (sp24 * func_80612794(sp2E));
    current_actor_pointer->z_position = arg1->unk8 + (sp24 * func_80612790(sp2E));
    current_actor_pointer->y_position = (D_8002FDE8 * (arg0->unk4 - current_actor_pointer->y_position)) + current_actor_pointer->y_position;
}
*/

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Struct800261E0_arg0;

void func_800261E0(Struct800261E0_arg0 *arg0) {
    s16 temp;
    s16 sp24;
    f32 sp20;
    f32 temp_f0;
    s16 temp_t2;

    temp_t2 = ((arg0->unk18 + arg0->unkC));
    sp24 = func_806CC10C(0, arg0->unk1C);
    temp_t2 &= 0xFFF;
    sp20 = func_80612790(temp_t2);
    temp_f0 = func_80612794(temp_t2);
    current_actor_pointer->y_rotation = current_actor_pointer->unkEE + temp_t2;
    current_actor_pointer->y_rotation &= 0xFFF;
    current_actor_pointer->z_rotation = sp24 * sp20;
    current_actor_pointer->z_rotation = current_actor_pointer->z_rotation + arg0->unk20;
    current_actor_pointer->z_rotation &= 0xFFF;
    current_actor_pointer->x_rotation = sp24 * temp_f0;
    current_actor_pointer->x_rotation = current_actor_pointer->x_rotation + arg0->unk24;
    current_actor_pointer->x_rotation &= 0xFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80026354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80026B20.s")

void func_80026CA8(void) {
    func_80604CBC(current_actor_pointer, 0x12D, 0, 1, 0, 0xFF, 1.0f, 0);
    func_80604CBC(current_actor_pointer, 0x12E, 0, 1, 1, 0xFF, 1.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80026D2C.s")

void func_80026EE4(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8002CAC8(arg0, arg1, arg1->PaaD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80026F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800274C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800276B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80027710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80027880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80027920.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80027BD0.s")

extern s32 D_80720120;

void func_80027C60(void) {
    s32 phi_s0;

    for (phi_s0 = 1; phi_s0 != 3; phi_s0++) {
        func_807149B8(1);
        func_80714C08(&D_80720120, 1.0f, current_actor_pointer, phi_s0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80027CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800280E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800282D8.s")

extern f32 D_8002FF84;
extern s16 D_80770628[];
extern f32 D_80770B68[];
extern f32 D_80770BC0[];

void func_800283D4(f32 arg0) {
    s32 temp_a0;

    temp_a0 = D_80770628[current_actor_pointer->unk6E];
    current_actor_pointer->unk74 = 1.0f;
    D_80770B68[temp_a0] = (arg0 * D_8002FF84) + 1.0;
    D_80770BC0[temp_a0] = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80028440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80028AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80028E20.s")

// TODO: Actor17C stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80029054.s")

void func_800292B0(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8002CAC8(arg0, arg1, arg1->PaaD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800292D0.s")

// need this forward declaration
void initializeSealRace();
void sealRaceSetup() {
    initializeSealRace();
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_800294A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002978C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80029F88.s")

s32 func_8002A080(s32 arg0, s32 arg1) {
    return D_8002FC5C[func_8002E8EC(arg0, arg1, 0xA)];
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002A0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/initializeCastleCarRace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002A7F8.s")

void func_8002AE6C(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8068E474(func_8002CAC8(arg0, arg1, arg1->PaaD), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002AE9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002B180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002B518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002B610.s")

s32 func_8002B6C8(s32 arg0, s32 arg1) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002B76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002B964.s")

void func_80611690(void*);

void func_8002BBD0(Actor *arg0, s32 arg1) {
    RaceAdditionalActorData *sp1C;
    void *temp_v0;

    sp1C = arg0->RaaD;
    temp_v0 = malloc(arg1 * 8);
    sp1C->unk20 = temp_v0;
    func_80611690(temp_v0);
    sp1C->unk1E = arg1;
    sp1C->unk1C = -1;
    arg0->control_state = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002BC2C.s")

// aaD use
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002BCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002BCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002BDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002BEE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002C14C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002C2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002C63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002C76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002CAC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002CBEC.s")

void func_8002CFF0(void) {
    TempAAD *temp_v0;
    Actor *temp_a0;

    func_80677FA8(0x132, 0); // Spawn actor 306
    temp_a0 = D_807FBB44;
    func_80025E9C(temp_a0);
    func_8002BCD4(temp_a0);
    temp_v0 = temp_a0->TaaD;
    temp_v0->unk0 = 0x17;
    temp_v0->unk14 = 0x46;
    temp_v0->unk16 = 0x47;
    temp_v0->unk18 = 0x48;
    temp_v0->unk1A = 0x49;
    temp_v0->unk24 = 2;
}

void castleCarRaceSetup() {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(0x132, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    initializeCastleCarRace(D_807FBB44);
    RaaD->unk0 = 0xE;
    RaaD->unk24 = 2;
}

void func_8002D0B0() {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(0x132, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    func_800292D0(D_807FBB44);
    RaaD->unk0 = 0xE;
    RaaD->unk24 = 2;
}

void func_8002D0FC(void) {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(0x132, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    func_8002E2C8(D_807FBB44);
    RaaD->unk0 = 2;
    RaaD->unk24 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D148.s")

/*
s8 func_806FDB8C(s32, s32, s32, f32, f32, f32);
s32 func_8070E750(s32, s32, s32, u8);

void func_8002D148(void *arg0, s32 arg1) {
    u8 temp_t6;
    u8 var_a3;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = arg0->unk4;
    temp_t6 = arg1 & 0xFF;
    if (temp_t6 != temp_v0->unk34) {
        temp_v0->unk34 = temp_t6;
        arg0->unk4->unk35 = 0;
        if (temp_t6 == 3) {
            temp_v0_2 = arg0->unk4;
            var_a3 = temp_v0_2->unk36;
            if (current_actor_pointer->RaaD->unk1E != (var_a3 + 1)) {
                if (temp_v0_2->unk45 != 0) {
                    goto block_4;
                }
            } else {
block_4:
                var_a3 = 3;
            }
            if (temp_v0_2->unk27 == 0) {
                arg0->unk4->unk46 = func_806FDB8C(1, func_8070E750(0x26, D_8002FCD4[var_a3], 1, var_a3), 2, 160.0f, 100.0f, 0.0f);
            }
        }
    }
}
*/

// RaaD->unk20 struct array use
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D2C0.s")

extern f32 D_800300E8;

typedef struct RaceStruct12 {
    u8 pad0[0x26];
    u8 unk26;
    u8 unk27;
    u8 unk28;
} RaceStruct12;

/*
f32 func_8002D2C0(RaceStruct12 *arg0) {
    if ((arg0->unk26 >= 0xB) && (arg0->unk26 < 0xF) && 
        (D_807FD610[arg0->unk28].unk2A & 0x2000)) {
            return (arg0->unk26 - 0xA) * D_800300E8;
    }
    return 0.0f;
}
*/

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

void func_8002D338(Actor *arg0, RaceStruct0 *arg1) {
    Actor *temp = arg1->unkC;
    RaceAdditionalActorData *RaaD = temp->RaaD;
    RaaD->unk2C = 0;
    func_806782C0(arg0);
}

extern f32 D_800300EC;
extern f32 D_800300F0;

// RaaD->actor30?->Raad->stuff
// dx dy dz calculation
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D360.s")

// RaaD->unk20-> struct array 0x8 big loop
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D40C.s")

void func_8002D4A0(void) {
    s32 song;
    f32 phi_f0;

    phi_f0 = 1.0f;
    switch (current_map) {
        case MAP_AZTEC_BEETLE_RACE:
            song = 0x13;
            phi_f0 = D_800300F0;
            break;
        case MAP_GALLEON_SEAL_RACE:
            song = 0x3D;
            break;
        case MAP_CAVES_BEETLE_RACE:
            song = 0x66;
            break;
        case MAP_FACTORY_CAR_RACE:
        default:
            song = 0x1B;
    }

    playSong(song, phi_f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D524.s")

void func_8002D72C(Actor *arg0) {
    if (arg0 && arg0->control_state == 0) {
        RaceAdditionalActorData *RaaD = arg0->RaaD;
        RaaD->unk1C = 2;
    }
}

void func_8002D754(Actor *arg0) {
    if (arg0 && arg0->control_state == 0) {
        RaceAdditionalActorData* RaaD = arg0->RaaD;
        RaaD->unk1C = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002D778.s")

void func_8002DA68(RaceStruct3 *arg0) {
    f32 temp_f2;
    s16 temp_v1;
    s16 phi_v0;

    switch (current_actor_pointer->control_state) {
        case 0:
            temp_v1 = arg0->unk2 % 2048;
            if ((temp_v1 >= 0x81) && ((0x800 - temp_v1) >= 0x81)) {
                arg0->unk2 += 0x80;
            }
            break;
        case 1:
            arg0->unk2 += 0x80;
            break;
    }

    arg0->unk2 &= 0xFFF;
    temp_f2 = (((func_80612794(arg0->unk2) + 1.0f) * 1.5) + 1.0) * arg0->unk4;
    current_actor_pointer->animation_state->scale_x = \
    current_actor_pointer->animation_state->scale_y = \
    current_actor_pointer->animation_state->scale_z = temp_f2;
}

void func_8002DB90(void) {
    if (current_actor_pointer->control_state != 0) {
        if ((current_actor_pointer->control_state == 1) && (func_80688540(current_actor_pointer, 0) == 0)) {
            func_80688370(current_actor_pointer, 0, 1.0f);
            func_8068842C(current_actor_pointer, 0, -1);
        }
    } else if (func_80688540(current_actor_pointer, 0)) {
        func_80688460(current_actor_pointer, 0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002DC24.s")

void func_80665564(Actor*, f32);

/*
// TODO: Pretty close, datatype issue for RaaD->unk0 though
// Case 2 function call and default function call may be swapped
void func_8002DC24(void) {
    RaceAdditionalActorData *RaaD = current_actor_pointer->RaaD;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        RaaD->unk4 = current_actor_pointer->animation_state->scale_y;
    }
    switch (RaaD->unk0) {
        default:
            func_8002DB90();
            break;
        case 1:
            func_8002DB90();
            func_80665564(current_actor_pointer, 0);
            current_actor_pointer->y_position = current_actor_pointer->unkAC;
            current_actor_pointer->unk6A |= 4;
            current_actor_pointer->unk6C |= 4;
            break;
        case 2:
            func_8002DA68();
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002DCF0.s")

typedef struct RaceStruct14 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Actor *unk1C; // Used
} RaceStruct14;

// TODO: Any overlap with existing PaaD/RaaD?
typedef struct RaceAdditionalActorData3 {
    s32 unk0;
    s32 unk4;
    u8 unk8; // Used
} RaceAdditionalActorData3;

void func_8002DCF0(RaceStruct14 *arg0, s32 arg1);

/*
// TODO: Doable, pretty close
void func_8002DCF0(RaceStruct14 *arg0, s32 arg1) {
    s32 temp_t1;
    s32 var_v0;
    RaceAdditionalActorData3 *temp_a1;
    Actor *temp_v1;

    var_v0 = 0;
    do {
        temp_v1 = arg0[var_v0].unk1C;
        temp_t1 = (var_v0 + 1);
        if (temp_v1 != NULL) {
            temp_a1 = temp_v1->RaaD;
            if (arg1 == 1) {
                if (temp_a1->unk8 == 0) {
                    temp_v1->control_state = arg1;
                }
                temp_a1->unk8++;
            } else {
                if (temp_a1->unk8 != 0) {
                    temp_a1->unk8--;
                }
                if (temp_a1->unk8 == 0) {
                    temp_v1->control_state = arg1;
                }
            }
        }
        var_v0 = temp_t1;
    } while (temp_t1 < 2);
}
*/

f32 func_8002DD70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return ((arg4 - arg2) * ((arg0 - arg1) / (arg3 - arg1))) + arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002DDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002DE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002DF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E2C8.s")

void func_8002E464(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8002CAC8(arg0, arg1, arg1->PaaD);
}

// Doable, some aaD stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E960.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} RaceStruct2_unkC;

typedef struct RaceStruct2 {
    s32 unk0;
    s32 unk4;
    u16 unk8;
    s16 unkA;
    RaceStruct2_unkC *unkC;
} RaceStruct2;
extern RaceStruct2 *D_8002FCF0;

void *func_8002E9AC(u8 arg0, RaceStruct2 *arg1) {
    arg1 = D_8002FCF0;
    if ((arg1 == 0) || (arg0 >= arg1->unk8)) {
        return 0;
    }
    return &arg1->unkC[arg0];
}

// arg0 is checkpoint file pointer
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002E9F8.s")

void setupRaceOnMapLoad(s32 map) {
    s32 *checkpointFile = getPointerTableFile(0x18, map, 1, 1);
    D_8002FCF0 = malloc(0x10);
    func_80611690(D_8002FCF0);
    func_8002E9F8(checkpointFile);
    switch (map) {
        case MAP_FACTORY_CAR_RACE:
            func_80025FDC();
            break;
        case MAP_GALLEON_SEAL_RACE:
            sealRaceSetup();
            break;
        case MAP_AZTEC_BEETLE_RACE:
        case MAP_CAVES_BEETLE_RACE:
            func_8002D0FC();
            break;
        case MAP_CASTLE_CAR_RACE:
            castleCarRaceSetup();
            break;
    }
    D_80750AC4 = 0;
}

void func_8002ECD4(Actor *arg0, f32 arg1) {
    arg0->animation_state->scale_x *= arg1;
    arg0->animation_state->scale_y = arg0->animation_state->scale_x;
    arg0->animation_state->scale_z = arg0->animation_state->scale_y;
}

void func_8002ED04(f32 arg0, s32 arg1, u8 arg2) {
    RaceAdditionalActorData2 *sp1C;

    switch (arg1) {
        case 1:
            if (arg2) {
                func_80677FA8(0x137, 0xB0); // Spawn checkpoint (actor 311)
                func_80614EBC(D_807FBB44, 0x2A9);
            } else {
                func_80677FA8(0x137, 0xB1); // Spawn checkpoint (actor 311)
                func_80614EBC(D_807FBB44, 0x2AA);
            }
            break;
        case 2:
            func_80677FA8(0x137, arg2 ? 0xD8 : 0xD9); // Spawn checkpoint (actor 311)
            break;
    }
    sp1C = D_807FBB44->RaaD2;
    func_8002ECD4(D_807FBB44, arg0);
    sp1C->unk0 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002EDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F04C.s")

/*
// TODO: REGALLOC
f32 func_8002F04C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_f0;
    f32 temp_f16;
    f32 phi_f2;

    temp_f16 = arg6 * arg3;
    temp_f0 = arg7 * arg2;
    phi_f2 = 0.0f;
    if (temp_f16 != temp_f0) {
        phi_f2 = (((arg4 - arg0) * arg3) + (arg2 * (arg1 - arg5))) / (temp_f0 - temp_f16);
    }
    return phi_f2;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F280.s")

f32 func_80611BB4(f32, f32);
extern f32 D_80030150;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct8002F280_arg0;

/*
// TODO: Regalloc
u8 func_8002F280(Struct8002F280_arg0 *arg0) {
    f32 p1 = current_actor_pointer->x_position - arg0->unk0;
    f32 p2 = current_actor_pointer->z_position - arg0->unk4;
    return (func_806CC14C((s16)(func_80611BB4(p1, p2) * D_80030150) & 0xFFF, arg0->unk6) < 0x400);
}
*/

void func_8002F04C(f32, f32, f32, f32, f32, f32, f32, f32);
typedef struct RaceStruct10 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
} RaceStruct10;

void func_8002F304(RaceStruct10 *arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0->unkC;
    temp_f2 = arg0->unk8;
    func_8002F04C(  arg0->unk0, 
                    arg0->unk4, 
                    -temp_f0, 
                    temp_f2, 
                    arg1, 
                    arg2, 
                    temp_f2, 
                    temp_f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F420.s")

// TODO: Is this the same as RaceStruct6?
typedef struct RaceStruct13 {
    s32 unk0;
    u16 *unk4;
    u16 unk8;
    u16 unkA;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s16 unk38;
    u16 unk3A;
    u16 unk3C;
} RaceStruct13;

void func_8002F36C(s32, s32);
// s32 func_8002E9AC(s32);

/*
// TODO: Regalloc, boo
void func_8002F420(RaceStruct13 *arg0, RaceStruct13 *arg1) {
    if (arg1->unk8) {
        if (arg0->unk3C == arg0->unk3A) {
            u8 temp2 = arg1->unk4[arg0->unk3C] & 0xFF;
            s32 temp = func_8002E9AC(temp2); // TODO: This might take 2 params
            func_8002DCF0(temp, 0);
            func_8002F36C(arg0, arg1);
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F784.s")

f32 func_8002F90C(RaceStruct6 *arg0, RaceStruct6 *arg1, RaceStruct6 *arg2) {
    f32 temp = ((arg1->unk37 - 1) * arg0->unk0) + arg1->unk3A;
    f32 temp2 = arg2->unk24 * arg0->unk0;
    return temp / temp2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_8002F950.s")
