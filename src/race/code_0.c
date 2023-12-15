#include <ultra64.h>
#include "functions.h"

typedef struct RaceStruct8 {
    u8 pad0[0x36];
    u8 unk36;
} RaceStruct8;

typedef struct RaceStruct9 {
    u8 pad0[0x1A];
    s16 unk1A; // Flag index
    s32 unk1C;
} RaceStruct9;

typedef struct {
    u8 pad0[0x10 - 0x0];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
} RaceStruct1;

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

extern f32 D_race_8002FE68;
extern s32 D_global_asm_8071FFA0; // TODO: Datatype
extern s32 D_global_asm_80720340; // TODO: Datatype

typedef struct {
    s32 unk0;
    f32 unk4;
} AAD_race_800274C0;

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

extern f64 D_race_8002FD00;
extern f64 D_race_8002FD08;
extern f64 D_race_8002FD10;
extern f64 D_race_8002FD18;
extern f64 D_race_8002FD20;
extern f64 D_race_8002FD28;
extern f64 D_race_8002FDD8;
extern f64 D_race_8002FDE0;
extern f64 D_race_8002FDE8;

extern f64 D_race_8002FE40;
extern f64 D_race_8002FE48;
extern f64 D_race_8002FE50;
extern f64 D_race_8002FE58;

extern s16 D_global_asm_80770628[];
extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];

extern u16 D_global_asm_80750AC4;

u32 func_global_asm_806119A0(void);
void func_race_8002D338(Actor *arg0, RaceStruct0 *arg1);

extern void func_race_8002CFF0(void);

f32 func_global_asm_80665E48(f32, f32, f32, f32);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80026098;

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80024000.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Struct8002FB10_race_8002FB70;

extern Struct8002FB10_race_8002FB70 D_race_8002FB10[];
extern Struct8002FB10_race_8002FB70 D_race_8002FB70[];

/*
// TODO: Quite close, float nonsense
void func_race_80024000(void) {
    f32 var_f0;
    f32 sp50;
    f32 temp_f0_2;
    f32 var_f12;
    f32 sp44;
    f32 sp40;
    f32 var_f22;
    f32 var_f20;
    u8 sp37;
    Struct8002FB10_race_8002FB70 *var_t0;
    s16 var_v1;

    sp37 = D_global_asm_807FDC90->unk24;
    if (current_map == MAP_CAVES_BEETLE_RACE) {
        var_t0 = &D_race_8002FB10;
    } else {
        var_t0 = &D_race_8002FB70;
    }
    sp44 = current_actor_pointer->unkB8;
    sp40 = func_global_asm_80612794(current_actor_pointer->unkE0 * D_race_8002FD00) * 20.0f;
    if (sqrtf(((current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0) * (current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0)) + ((current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4) * (current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4))) < D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk7) {
        var_f12 = ABS(current_actor_pointer->y_position - (f32)D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk2);
        if (var_f12 < 80.0f) {
            if (D_global_asm_807FDC90->unk25 < (D_global_asm_807FDCA0->unk10 - 1)) {
                if (D_global_asm_807FDC90->unk25 == var_t0[sp37].unk0) {
                    current_actor_pointer->y_acceleration = var_t0[sp37].unk4;
                    if (var_t0[sp37].unk8 == 1) {
                        func_global_asm_80614EBC(current_actor_pointer, 0x286);
                        current_actor_pointer->y_velocity = 200.0f;
                        current_actor_pointer->control_state++;
                    }
                    D_global_asm_807FDC90->unk24++;
                }
                D_global_asm_807FDC90->unk25++;
            }
        }
    }
    var_f0 = (current_actor_pointer->y_position - D_global_asm_807FBB48->y_position);
    var_f0 *= 0.25f;
    var_f0 = MIN(6.0f, var_f0);
    var_f0 = MAX(-6.0f, var_f0);
    var_f0 += ((D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 - (current_actor_pointer->unkB8 / 10.0f)) * D_race_8002FD08);
    var_v1 = (s16)((func_global_asm_80611BB4(-(current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0), -(current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4)) * 4096.0) / D_race_8002FD10) - current_actor_pointer->unkEE;
    if (var_v1 >= 0x800) {
        var_v1 -= 4096.0;
    }
    if (var_v1 < -0x800) {
        var_v1 += 4096.0;
    }
    sp50 = (current_actor_pointer->unkB8 * var_v1) / D_race_8002FD18;
    var_f20 = func_global_asm_80612794(current_actor_pointer->unkEE) * sp44;
    var_f22 = func_global_asm_80612790(current_actor_pointer->unkEE) * sp44;
    if (current_actor_pointer->unk6A & 1) {
        var_f20 += func_global_asm_80612794(current_actor_pointer->unkDC) * sp40;
        var_f22 += func_global_asm_80612790(current_actor_pointer->unkDC) * sp40;
    }
    var_f20 += (func_global_asm_80612794(current_actor_pointer->unkEE) * var_f0) + (func_global_asm_80612790(current_actor_pointer->unkEE) * sp50);
    var_f22 += (func_global_asm_80612790(current_actor_pointer->unkEE) * var_f0) - (func_global_asm_80612794(current_actor_pointer->unkEE) * sp50);
    sp44 = sqrtf((var_f20 * var_f20) + (var_f22 * var_f22));
    temp_f0_2 = func_global_asm_80611BB4(var_f20, var_f22);
    if (current_actor_pointer->y_acceleration != -20.0f && current_actor_pointer->y_acceleration != -360.0f) {
        current_actor_pointer->unkB8 = D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 * 10.0;
    } else {
        current_actor_pointer->unkB8 = sp44;
    }
    current_actor_pointer->unkEE = (temp_f0_2 * 4096.0) / D_race_8002FD20;
    if (current_actor_pointer->unk6A & 1) {
        current_actor_pointer->unkB8 -= (f32)((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / D_race_8002FD28);
        if (current_actor_pointer->unkB8 < 0.0f) {
            current_actor_pointer->unkB8 = 0.0f;
        }
    }
}
*/

int func_race_80024634(RaceStruct8 *arg0, RaceStruct9 *arg1) {
    return arg0->unk36 && 
           !isFlagSet(arg1->unk1A, FLAG_TYPE_PERMANENT) &&
           arg1->unk1C <= D_global_asm_80750AC4;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80024690.s")

s32 func_race_80025770(s32 arg0, s32 arg1) {
    s32 temp_v1 = arg1 + 1;
    if (arg0 != temp_v1) {
        return arg1 + 1;
    }
    return 0;
}

s32 func_race_8002578C(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return arg0 - 1;
    }
    return arg1 - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_800257A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_8002597C.s")

// Close, doable, regalloc, stack
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80025E9C.s")

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
    s8 unk24;
    s8 unk25;
    s8 unk26;
    s8 unk27;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s8 unk34;
    s8 unk35;
    s8 unk36;
    s8 unk37;
} Actor178_race_80025E9C_2;

typedef struct {
    Actor *unk0;
    RaceAdditionalActorData *unk4;
} Actor184_race_80025E9C;

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
    s32 unk28;
    s32 unk2C;
    Actor *unk30;
    Actor *unk34;
} Actor17C_race_80025E9C;

void func_race_8002BBD0(Actor *arg0, s32 arg1);
void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, void *arg3);

/*
void func_race_80025E9C(Actor *arg0) {
    RaceAdditionalActorData *aaD;
    Actor178_race_80025E9C_2 *a178_2; // TODO: Shouldn't be on stack
    s32 pad2;
    s32 pad;
    Actor *playerCar;
    Actor *sp40; // sp40
    Actor *raceCamera; // sp3C
    Actor17C_race_80025E9C *a178;
    RaceAdditionalActorData *aaD_2;
    Actor184_race_80025E9C *a184;

    aaD = arg0->additional_actor_data;
    func_race_8002BBD0(arg0, 2);
    func_global_asm_80677FA8(ACTOR_CAR_FACTORY_PLAYER, 0x95);
    playerCar = D_global_asm_807FBB44;
    aaD_2 = playerCar->additional_actor_data;
    func_race_8002BC2C(arg0, 1, playerCar, aaD_2);
    aaD_2->unk37 = 0;
    aaD_2->unk27 = 0;
    aaD_2->unk30 = arg0;
    aaD_2->unk36 = 1;
    aaD_2->unk28 = 0;
    a178 = playerCar->unk178;
    sp40 = func_global_asm_807271F4(1, 0, 0, 0, 0, 0, 0);
    a178->unk30 = sp40;
    a184 = sp40->unk184;
    a184->unk4 = aaD_2;
    a184->unk0 = playerCar;
    func_global_asm_80677FA8(ACTOR_CAMERA_CARRACE, 0);
    raceCamera = D_global_asm_807FBB44;
    a178->unk34 = raceCamera;
    pad = 1;
    a178_2 = sp40->unk178;
    func_race_8002BC2C(arg0, 0, sp40, a178_2);
    a178_2->unk37 = 0;
    a178_2->unk27 = pad;
    a178_2->unk30 = arg0;
    a178_2->unk36 = 0;
    a178 = sp40->unk17C;
    a178->unk30 = playerCar;
    a178->unk34 = raceCamera;
    aaD_2 = raceCamera->RaaD;
    aaD_2->unk30 = arg0;
    a178_2 = raceCamera->unk178;
    a178_2->unk30 = playerCar;
    D_global_asm_80750AC4 = 0;
    aaD->unk25 = pad;
}
*/

void func_race_80025FDC() {
    func_race_8002597C();
    func_race_8002CFF0();
}

void func_race_80026004(RaceStruct1 *arg0, u8 arg1, f32 arg2) {
    arg0->unk10 = arg1;
    arg0->unk14 = arg2;
    playSound(0x1EB, 0x7FFF, 64.0f, 1.0f, 0, 0);
}

void func_race_80026050(RaceStruct6 *arg0, RaceStruct6 *arg1, s32 arg2) {
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

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80026098.s")

/*
void func_race_80026098(Struct80026098 *arg0, Struct80026098 *arg1) {
    s16 sp2E;
    s16 pad[2];
    f32 sp24;

    sp2E = (func_global_asm_80665E48(arg0->unk0, arg0->unk8, arg1->unk0, arg1->unk8) * 2048.0) / D_race_8002FDD8;
    sp24 = current_actor_pointer->unkB8 * D_race_8002FDE0 * sqrtf(((arg1->unk8 - arg0->unk8) * (arg1->unk8 - arg0->unk8)) + ((arg1->unk0 - arg0->unk0) * (arg1->unk0 - arg0->unk0)));
    current_actor_pointer->x_position = arg1->unk0 + (sp24 * func_global_asm_80612794(sp2E));
    current_actor_pointer->z_position = arg1->unk8 + (sp24 * func_global_asm_80612790(sp2E));
    current_actor_pointer->y_position = (D_race_8002FDE8 * (arg0->unk4 - current_actor_pointer->y_position)) + current_actor_pointer->y_position;
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

void func_race_800261E0(Struct800261E0_arg0 *arg0) {
    s16 temp;
    s16 sp24;
    f32 sp20;
    f32 temp_f0;
    s16 temp_t2;

    temp_t2 = ((arg0->unk18 + arg0->unkC));
    sp24 = func_global_asm_806CC10C(0, arg0->unk1C);
    temp_t2 &= 0xFFF;
    sp20 = func_global_asm_80612790(temp_t2);
    temp_f0 = func_global_asm_80612794(temp_t2);
    current_actor_pointer->y_rotation = current_actor_pointer->unkEE + temp_t2;
    current_actor_pointer->y_rotation &= 0xFFF;
    current_actor_pointer->z_rotation = sp24 * sp20;
    current_actor_pointer->z_rotation = current_actor_pointer->z_rotation + arg0->unk20;
    current_actor_pointer->z_rotation &= 0xFFF;
    current_actor_pointer->x_rotation = sp24 * temp_f0;
    current_actor_pointer->x_rotation = current_actor_pointer->x_rotation + arg0->unk24;
    current_actor_pointer->x_rotation &= 0xFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80026354.s")

Actor *func_race_8002D360(Actor *);

typedef struct {
    u8 unk0[0x29 - 0x0];
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    Actor *unk2C;
} Struct80026B20;

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
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
} A178_race_80026B20;

typedef struct {
    s32 unk0;
    s32 unk4;
    Actor *unk8;
    Actor *unkC;
} A17C_race_80026B20;

void func_race_80026B20(Struct80026B20 *arg0) {
    A178_race_80026B20 *a178_2;
    A178_race_80026B20 *a178;
    A17C_race_80026B20 *a17C;

    if (arg0->unk2C == NULL && arg0->unk2A != 0) {
        a178 = current_actor_pointer->unk178;
        arg0->unk2A--;
        func_global_asm_80677FA8(ACTOR_MISSILE_CAR, 0x96);
        a178_2 = D_global_asm_807FBB44->unk178;
        a17C = D_global_asm_807FBB44->unk17C;
        a17C->unkC = current_actor_pointer;
        a17C->unk8 = func_race_8002D360(current_actor_pointer);
        arg0->unk2C = D_global_asm_807FBB44;
        D_global_asm_807FBB44->x_position = current_actor_pointer->x_position;
        D_global_asm_807FBB44->y_position = current_actor_pointer->y_position;
        D_global_asm_807FBB44->z_position = current_actor_pointer->z_position;
        D_global_asm_807FBB44->unkEE = current_actor_pointer->unkEE;
        D_global_asm_807FBB44->y_rotation = current_actor_pointer->y_rotation;
        D_global_asm_807FBB44->unkB8 = current_actor_pointer->unkB8;
        *a178_2 = *a178;
        playSound(0x18B, 0x7FFF, 64.0f, 1.0f, 0, 0);
    } else {
        playSound(0xE2, 0x7FFF, 64.0f, 1.0f, 0, 0);
    }
    arg0->unk29 = 0;
}

void func_race_80026CA8(void) {
    func_global_asm_80604CBC(current_actor_pointer, 0x12D, 0, 1, 0, 0xFF, 1.0f, 0);
    func_global_asm_80604CBC(current_actor_pointer, 0x12E, 0, 1, 1, 0xFF, 1.0f, 0);
}

void func_race_80026D2C(f32 arg0) {
    s16 temp;
    s32 pad;
    temp = D_global_asm_80770628[current_actor_pointer->unk6E[0]];
    D_global_asm_80770B68[temp] = (arg0 / 20.0) + 1.0;
    D_global_asm_80770BC0[temp] = 1.0f;
    temp = D_global_asm_80770628[current_actor_pointer->unk70];
    current_actor_pointer->unk74 = arg0 / 20.0;
    if (current_actor_pointer->unk74 > 1.0) {
        current_actor_pointer->unk74 = 1.0f;
    }
    if (current_actor_pointer->unk74 < 0.0) {
        current_actor_pointer->unk74 = 0.0f;
    }

    if (D_global_asm_80770BC0[temp] == 0.0f) {
        D_global_asm_80770B68[temp] = (((func_global_asm_806119A0() / D_race_8002FE40) * D_race_8002FE48) + D_race_8002FE50) * (D_race_8002FE58 + (arg0 / 15.0));
        D_global_asm_80770BC0[temp] = 3.0f;
    }
}

void func_race_80026EE4(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_race_8002CAC8(arg0, arg1, arg1->PaaD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80026F04.s")

void func_race_800274C0(void) {
    AAD_race_800274C0 *sp4C;
    Actor178 *sp48;
    s32 temp;
    Actor17C *temp_s1;
    u8 temp2[3];
    u8 var_v1;

    var_v1 = 0;
    sp4C = current_actor_pointer->additional_actor_data;
    sp48 = current_actor_pointer->unk178;
    temp_s1 = current_actor_pointer->unk17C;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_s1->unk0_u16[0] = 0x78;
        current_actor_pointer->object_properties_bitfield |= 0x10;
        current_actor_pointer->noclip_byte = 0x3C;
        sp4C->unk4 = 5.0f;
    }
    if (D_global_asm_807FBB70.unk200 == 9 || D_global_asm_807FBB70.unk15 != 0 || D_global_asm_807FBB70.unk200 == 5) {
        func_global_asm_807149B8(1);
        func_global_asm_80714CC0(&D_global_asm_80720340, 3.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xF6, 0xFF, 0x7F, 0x14, 0x32, D_race_8002FE68, 0);
        var_v1 = 1;
    }
    func_race_80026354(sp48, sp4C, 0);
    current_actor_pointer->y_position += 5.0f;
    if (temp_s1->unk0_u16[0] != 0) {
        func_global_asm_807149B8(1);
        func_global_asm_80714CC0(&D_global_asm_8071FFA0, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
        temp_s1->unk0_u16[0]--;
        if (!(temp_s1->unk0_u16[0])) {
            var_v1 = 1;
        }
    }
    if (var_v1 != 0) {
        func_race_8002D338(current_actor_pointer, temp_s1);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}
