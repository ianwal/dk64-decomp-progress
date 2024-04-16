#include <ultra64.h>
#include "functions.h"

f32 func_global_asm_80665E48(f32, f32, f32, f32);
s32 func_global_asm_8072177C(void *, s16, s16, s16, s32, s32, s32, s32, s32);

typedef struct {
    u8 pad0[0x10 - 0x0];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
} RaceStruct1;

extern s32 D_global_asm_8071FFA0; // TODO: Datatype
extern s32 D_global_asm_80720340; // TODO: Datatype
extern s32 D_global_asm_80720120;

extern s16 D_global_asm_80770628[];
extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];

typedef struct RaceStruct15 {
    s16 unk0;
    u16 unk2;
} RaceStruct15;

typedef struct RaceStruct3 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} RaceStruct3;

typedef struct {
    u8 unk0[0x37 - 0x0];
    s8 unk37;
    u8 unk38;
    u8 unk39;
    u16 unk3A;
} Struct80027BD0_arg1;

typedef struct {
    u8 unk0[0x24 - 0x0];
    u8 unk24;
} Struct80027BD0_arg2;

typedef struct {
    u8 unk0;
} A180_race_800280E8;

typedef struct {
    u8 unk0[0x14 - 0x0];
    f32 unk14;
} A184_race_800280E8;

typedef struct {
    u8 unk0[0x30 - 0x0];
    Actor *unk30;
} Struct800280E8;

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
} Struct80028E20_arg0;

typedef struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x34 - 0x8];
    u8 unk34;
} A178_race_80029054;

typedef struct {
    u8 unk0[0x30 - 0x0];
    Actor *unk30;
} A17C_race_80029054;

s32 func_race_800276B0(s32 arg0, RaceStruct15 *arg1, RaceStruct15 *arg2) {
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

// Similar to below
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80027710.s")

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80027880.s")

/*
// TODO: Probably returns the float
void func_race_80027880(s32 arg0, u16 arg1, u16 arg2) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 temp;

    temp = func_race_80025770(arg0, arg2);

    dx = D_global_asm_807F5FD4->unk0[arg1][arg2].unk0 - D_global_asm_807F5FD4->unk0[arg1][temp].unk0;
    dy = D_global_asm_807F5FD4->unk0[arg1][arg2].unk4 - D_global_asm_807F5FD4->unk0[arg1][temp].unk4;
    dz = D_global_asm_807F5FD4->unk0[arg1][arg2].unk8 - D_global_asm_807F5FD4->unk0[arg1][temp].unk8;
    sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}
*/

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80027920.s")

void func_race_80027AF8(RaceStruct3 *arg0, s8 arg1) {
    if (arg1 > 0) {
        arg0->unk1++;
    } else {
        arg0->unk1--;
    }
    arg0->unk8 = 0.0f;
}

void func_race_80027B30(RaceStruct3 *arg0) {

    switch (arg0->unk0) {
        case 0:
            arg0->unk1++;
            break;
        case 1:
            if ((u8)func_global_asm_806119A0() >= 0x80U) {
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

f32 func_race_80027BD0(u8 *arg0, Struct80027BD0_arg1 *arg1, Struct80027BD0_arg2 *arg2) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f2;
    s32 count;

    var_f2 = 0.0f;
    if (arg1->unk37 > 0) {
        count = (D_global_asm_807F5FD4->unk0[*arg0 + 1] - D_global_asm_807F5FD4->unk0[*arg0]);
        var_f0 = (((arg1->unk37 - 1) * count) + arg1->unk3A);
        var_f12 = (arg2->unk24 * count);
        var_f2 = var_f0 / var_f12;
    }
    return var_f2;
}

void func_race_80027C60(void) {
    s32 i;

    for (i = 1; i != 3; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_80714C08(&D_global_asm_80720120, 1.0f, current_actor_pointer, i, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80027CE8.s")

void func_race_800280E8(Struct800280E8 *arg0) {
    Actor *temp_v1;
    void *sp34;
    A180_race_800280E8 *a180;
    A184_race_800280E8 *a184;
    f32 var_f0;

    temp_v1 = arg0->unk30;
    a180 = current_actor_pointer->unk180;
    a184 = current_actor_pointer->unk184;
    if (temp_v1->unkB8 < current_actor_pointer->unkB8) {
        var_f0 = current_actor_pointer->unkB8 - temp_v1->unkB8;
    } else {
        var_f0 = current_actor_pointer->unkB8 - temp_v1->unkB8;
        var_f0 = -var_f0;
    }
    if (a180->unk0 == 0) {
        var_f0 *= 1.5;
        var_f0 = MIN(10.0, var_f0);
        a180->unk0 = 3;
        func_global_asm_8060E7EC(0, (255.0f * var_f0 * 0.1f), a180->unk0);
        playSound(0x18A, 0x7FFF, 64.0f, 1.0f, 0xA, 0);
        if (a184->unk14 < 0.0f) {
            temp_v1->unkB8 -= var_f0;
            current_actor_pointer->unkB8 += var_f0;
        } else {
            temp_v1->unkB8 += var_f0;
            current_actor_pointer->unkB8 -= var_f0;
        }
    }
}

void func_race_800282D8(void) {
    s32 pad2;
    s32 pad;
    RaceAdditionalActorData *RaaD;
    Struct800280E8 *a178 = current_actor_pointer->unk178;
    Actor *actor = a178->unk30;

    RaaD = actor->RaaD;
    switch (RaaD->unk1C) {
        case 0x5A:
            func_global_asm_80604CBC(current_actor_pointer, 0x107, 0, 1, 0, 0xFF, 1.0f, 0);
        case 0x1D:
        case 0x25:
        case 0x2C:
        case 0x30:
        case 0x38:
        case 0x3F:
        case 0x43:
        case 0x47:
        case 0x4E:
        case 0x54:
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x187, 0xFF, ((RaaD->unk1C - 0x1D) * 0.5) + 157.0, 0, 0, 0.3f, 0);
            break;
    }
}

void func_race_800283D4(f32 arg0) {
    s32 temp_a0;

    temp_a0 = D_global_asm_80770628[current_actor_pointer->unk6E[0]];
    current_actor_pointer->unk74 = 1.0f;
    D_global_asm_80770B68[temp_a0] = (arg0 * 0.05f) + 1.0;
    D_global_asm_80770BC0[temp_a0] = 1.0f;
}

// Jumptable, doable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80028440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80028AD0.s")

// close, doable, unrolled loop, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_race_80028E20.s")

/*
void func_race_80028E20(Struct80028E20_arg0 *arg0) {
    f32 y;
    f32 z;
    f32 d;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 x;
    f32 lowest;
    s32 j;
    s32 count;
    s32 i;
    Struct807F5FD4_unk0 *var_a2;

    count = (D_global_asm_807F5FD4->unk0[1] - D_global_asm_807F5FD4->unk0[0]);
    var_a2 = D_global_asm_807F5FD4->unk0[0];
    lowest = 10000000.0f;
    x = current_actor_pointer->x_position;
    y = current_actor_pointer->y_position;
    z = current_actor_pointer->z_position;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < count; j++) {
            dx = x - var_a2[j].unk0;
            dy = y - var_a2[j].unk4;
            dz = z - var_a2[j].unk8;
            d = (dx * dx) + (dy * dy) + (dz * dz);
            if (d < lowest) {
                arg0->unk2 = j;
                arg0->unk0 = i;
                arg0->unk1 = i;
                lowest = d;
            }
        }
    }
}
*/

void func_race_80029054(void) {
    A178_race_80029054 *a178;
    A17C_race_80029054 *a17C;
    Actor *temp;
    A178_race_80029054 *sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;

    a178 = current_actor_pointer->unk178;
    a17C = current_actor_pointer->unk17C;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_race_80028E20(a17C);
        current_actor_pointer->noclip_byte = 0x3C;
        a178->unk4 = 0.5f;
        func_global_asm_8066EA90(current_actor_pointer, 1);
        a17C->unk30 = getSpawnerTiedActor(1, 0);
        current_actor_pointer->object_properties_bitfield &= ~1;
    }
    temp = a17C->unk30;
    sp48 = temp->unk178;
    if (!(D_global_asm_807FBB70.unk200 != 9 && D_global_asm_807FBB70.unk15 == 0)) {
        func_global_asm_8067E278(0, 1);
        current_actor_pointer->control_state = 0x40;
    }
    func_global_asm_80671C0C(current_actor_pointer, 6, &sp3C, &sp40, &sp44);
    func_global_asm_8072177C(current_actor_pointer, sp3C, sp40, sp44, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    func_global_asm_80671C0C(current_actor_pointer, 0xB, &sp3C, &sp40, &sp44);
    func_global_asm_8072177C(current_actor_pointer, sp3C, sp40, sp44, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    func_race_80026354(a17C, a178, 1);
    if (a178->unk34 == 0 && sp48->unk34 == 5) {
        D_global_asm_807FDC9C[1].pad0[0] = 0;
        current_actor_pointer->control_state = 0x40;
        a178->unk34++;
    }
    renderActor(current_actor_pointer, 0);
}
