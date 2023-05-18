#include <ultra64.h>
#include "functions.h"

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

extern f32 D_8002FE68;
extern s32 D_8071FFA0; // TODO: Datatype
extern s32 D_80720340; // TODO: Datatype

typedef struct {
    s32 unk0;
    f32 unk4;
} AAD_800274C0;

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

extern void func_8002CFF0();

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_80024000.s")

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
    func_80677FA8(ACTOR_CAR_FACTORY_PLAYER, 0x95);
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
    func_80677FA8(ACTOR_CAMERA_CARRACE, 0);
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

void func_80025FDC() {
    func_8002597C();
    func_8002CFF0();
}

void func_80026004(RaceStruct1 *arg0, u8 arg1, f32 arg2) {
    arg0->unk10 = arg1;
    arg0->unk14 = arg2;
    playSound(0x1EB, 0x7FFF, 64.0f, 1.0f, 0, 0);
}

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

// Actor17C stuff, bit of a can of worms...
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

void func_8002D338(Actor *arg0, RaceStruct0 *arg1);

void func_800274C0(void) {
    AAD_800274C0 *sp4C;
    Actor178 *sp48;
    s32 temp;
    Actor17C *temp_s1;
    u8 temp2[3];
    u8 var_v1;

    if (temp_s1); // TODO: Gross
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
    if (D_807FBB70.unk200 != 9) {
        if (D_807FBB70.unk15 == 0) {
            if (D_807FBB70.unk200 == 5) {
                goto block_5;
            }
        } else {
            goto block_5;
        }
    } else {
block_5:
        func_807149B8(1);
        func_80714CC0(&D_80720340, 3.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xF6, 0xFF, 0x7F, 0x14, 0x32, D_8002FE68, 0);
        var_v1 = 1;
    }
    func_80026354(sp48, sp4C, 0);
    current_actor_pointer->y_position += 5.0f;
    if (temp_s1->unk0_u16[0] != 0) {
        func_807149B8(1);
        func_80714CC0(&D_8071FFA0, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
        temp_s1->unk0_u16[0]--;
        if (!(temp_s1->unk0_u16[0])) {
            var_v1 = 1;
        }
    }
    if (var_v1 != 0) {
        func_8002D338(current_actor_pointer, temp_s1);
    }
    func_806319C4(current_actor_pointer, 0);
}
