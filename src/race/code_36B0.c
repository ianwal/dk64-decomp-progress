#include <ultra64.h>
#include "functions.h"

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

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027880.s")

/*
void func_80027880(s32 arg0, u16 arg1, u16 arg2) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 temp;

    temp = func_80025770(arg0, arg2);

    dx = D_807F5FD4->unk0[arg1][arg2].unk0 - D_807F5FD4->unk0[arg1][temp].unk0;
    dy = D_807F5FD4->unk0[arg1][arg2].unk4 - D_807F5FD4->unk0[arg1][temp].unk4;
    dz = D_807F5FD4->unk0[arg1][arg2].unk8 - D_807F5FD4->unk0[arg1][temp].unk8;
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

// doable, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027BD0.s")

/*
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

f32 func_80027BD0(u8 *arg0, Struct80027BD0_arg1 *arg1, Struct80027BD0_arg2 *arg2) {
    f32 var_f2;
    s32 count;
    s8 temp_v0;
    u8 temp_a2;

    var_f2 = 0.0f;
    if (arg1->unk37 > 0) {
        count = (D_807F5FD4->unk0[*arg0 + 1] - D_807F5FD4->unk0[*arg0]);
        var_f2 = (f32)(((arg1->unk37 - 1) * count) + arg1->unk3A) / (arg2->unk24 * count);
    }
    return var_f2;
}
*/

void func_80027C60(void) {
    s32 i;

    for (i = 1; i != 3; i++) {
        func_807149B8(1);
        func_80714C08(&D_80720120, 1.0f, current_actor_pointer, i, 0);
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

// close, doable, unrolled loop
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028E20.s")

extern f32 D_8002FFA4;

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
} Struct80028E20_arg0;

/*
void func_80028E20(Struct80028E20_arg0 *arg0) {
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

    count = (D_807F5FD4->unk0[1] - D_807F5FD4->unk0[0]);
    var_a2 = D_807F5FD4->unk0[0];
    lowest = D_8002FFA4;
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

s32 func_8072177C(void *, s16, s16, s16, s32, s32, s32, s32, s32);

typedef struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x34 - 0x8];
    u8 unk34;
} A178_80029054;

typedef struct {
    u8 unk0[0x30 - 0x0];
    Actor *unk30;
} A17C_80029054;

void func_80029054(void) {
    A178_80029054 *a178;
    A17C_80029054 *a17C;
    Actor *temp;
    A178_80029054 *sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;

    a178 = current_actor_pointer->unk178;
    a17C = current_actor_pointer->unk17C;
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80028E20(a17C);
        current_actor_pointer->noclip_byte = 0x3C;
        a178->unk4 = 0.5f;
        func_8066EA90(current_actor_pointer, 1);
        a17C->unk30 = func_807270C0(1, 0);
        current_actor_pointer->object_properties_bitfield &= ~1;
    }
    temp = a17C->unk30;
    sp48 = temp->unk178;
    if (!(D_807FBB70.unk200 != 9 && D_807FBB70.unk15 == 0)) {
        func_8067E278(0, 1);
        current_actor_pointer->control_state = 0x40;
    }
    func_80671C0C(current_actor_pointer, 6, &sp3C, &sp40, &sp44);
    func_8072177C(current_actor_pointer, sp3C, sp40, sp44, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    func_80671C0C(current_actor_pointer, 0xB, &sp3C, &sp40, &sp44);
    func_8072177C(current_actor_pointer, sp3C, sp40, sp44, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    func_80026354(a17C, a178, 1);
    if (a178->unk34 == 0 && sp48->unk34 == 5) {
        D_807FDC9C[1].pad0[0] = 0;
        current_actor_pointer->control_state = 0x40;
        a178->unk34++;
    }
    func_806319C4(current_actor_pointer, 0);
}
