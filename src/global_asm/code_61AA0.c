#include <ultra64.h>
#include "functions.h"

// rodata
extern f64 D_global_asm_80758D60; // 600.0
extern f64 D_global_asm_80758D68; // 45.0

extern f32 D_global_asm_807F5FDC;
extern f32 D_global_asm_807F5FE0;

extern f32 D_global_asm_807F6940;

extern u8 D_global_asm_807F7F00;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct807F8E90;

extern s8 D_global_asm_807F8E88;
extern u16 D_global_asm_807F8E8A;
extern Struct807F8E90 D_global_asm_807F8E90[4];
extern s32 D_global_asm_807F8EC0[]; // size 100

extern s32 D_global_asm_807F9050;
extern s32 D_global_asm_807F9054;
extern u16 D_global_asm_807F9058;
extern u16 D_global_asm_807F905A;
extern s32 D_global_asm_807F905C;
extern s16 D_global_asm_807F9060;
extern u32 D_global_asm_807F9064;
extern s32 D_global_asm_807F9068;

s32 func_global_asm_8065E0CC(void);
s32 func_global_asm_8065E81C(s32, s32);

void func_global_asm_8065CDA0(u8 arg0) {
    D_global_asm_807F7F00 = arg0;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065CDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065CE4C.s")

f32 func_global_asm_8065CFB8(s16, f32);
f32 func_global_asm_8065D0FC(f32);

/*
// TODO: Quite close, annoying float nonsense
void func_global_asm_8065CE4C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 *arg5) {
    f32 dx, dy, dz;
    f32 phi_f14;

    dx = arg0 - character_change_array[cc_player_index].unk21C;
    dy = arg1 - character_change_array[cc_player_index].unk220;
    dz = arg2 - character_change_array[cc_player_index].unk224;
    phi_f14 = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    if (current_map == MAP_AZTEC) {
        arg3 = func_global_asm_8065CFB8(arg4, arg3);
        if (arg3 < phi_f14) {
            *arg5 = 0;
            return;
        }
    }
    dy = func_global_asm_8065D0FC(arg3);
    dx = (dy * 3.0f) / 4;
    if (phi_f14 < dx) {
        *arg5 = 0xFF;
        return;
    }
    *arg5 = ((phi_f14 - dx) / (dy - dx)) * 255.0f;
    if (*arg5 >= 0x100) {
        *arg5 = 0xFF;
    }
    *arg5 = 0xFF - *arg5;
}
*/

// rodata
f32 func_global_asm_8065CFB8(s16 arg0, f32 arg1) {
    if (arg0 == 0xB2 || arg0 == 0x253) {
        arg1 += (D_global_asm_80758D60 - arg1) * D_global_asm_807F6940;
    }
    return arg1;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065D008.s")

f32 func_global_asm_8065D0FC(f32 arg0) {
    if (D_global_asm_80758D68 == character_change_array[cc_player_index].fov_y) {
        return arg0;
    }
    return (arg0 / D_global_asm_807F5FDC) * D_global_asm_807F5FE0;
}

void func_global_asm_8065D170(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_global_asm_807F8E90[i].unk0 = -1;
    }
    D_global_asm_807F8E8A = 0;
}

void func_global_asm_8065D1AC(void) {
    s32 temp_v0;
    s32 i;

    D_global_asm_807F8E88 = 0;
    for (i = 0; i < 4; i++) {
        if ((D_global_asm_807F8E90[i].unk0 != -1) && ((object_timer - D_global_asm_807F8E90[i].unk0) >= 0x15U)) {
            func_global_asm_8066B434(D_global_asm_807F8E90[i].unk8, 0x65, 0x4D);
            D_global_asm_807F8E90[i].unk0 = -1;
        }
    }
}

void func_global_asm_8065D244(u16 arg0) {
    D_global_asm_807F8E8A = arg0;
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065D254.s")

typedef struct {
    s16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} GlobalASMStruct66;

void func_global_asm_8065D964(GlobalASMStruct66 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk0 = arg1;
    arg0->unk2 = 0;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3 << 5;
    arg0->unkA = arg4 << 5;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065D994.s")

void func_global_asm_8065E040(s32 arg0) {
    s32 i;
    for (i = 0; i < 100; i++) {
        D_global_asm_807F8EC0[i] = 0;
    }
    D_global_asm_807F9050 = 0;
    D_global_asm_807F9054 = 0;
    D_global_asm_807F905C = 0;
    D_global_asm_807F9060 = 0;
    if (func_global_asm_8065E0CC()) {
        D_global_asm_807F9064 = arg0 + 0x70000;
    } else {
        D_global_asm_807F9064 = arg0;
    }
}

s32 func_global_asm_8065E0CC(void) {
    switch (current_map) {
        case MAP_JAPES_MINECART:
        case MAP_JAPES_ARMY_DILLO:
        case MAP_FUNGI_MINECART:
        case MAP_FUNGI_DOGADON:
        case MAP_CASTLE_MINECART:
        case MAP_CAVES_ARMY_DILLO:
        case MAP_AZTEC_DOGADON:
            return FALSE;
    }
    return TRUE;
}

void func_global_asm_8065E124(void) {
    D_global_asm_807F9058 = 0;
    D_global_asm_807F905A = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065E138.s")

// Pretty doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065E634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_61AA0/func_global_asm_8065E81C.s")

s32 func_global_asm_8065EA44(void) {
    D_global_asm_807F9064 = (D_global_asm_807F9064 * 3) >> 2;
    if (D_global_asm_807F9064 < 0x10000) {
        return 0;
    }
    return func_global_asm_8065E81C(1, 0);
}

s32 func_global_asm_8065EA98(s32 arg0, s16 arg1, u8 arg2) {
    return ((arg1 * 0x10) + (arg0 * 4) + arg2) % 100;
}

void func_global_asm_8065EACC() {
    if (D_global_asm_807F9064 != 40000) {
        D_global_asm_807F9068 = D_global_asm_807F9064;
    }
    D_global_asm_807F9064 = 40000;
}

void func_global_asm_8065EAF4() {
    D_global_asm_807F9064 = D_global_asm_807F9068;
}
