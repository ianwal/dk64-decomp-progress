#include <ultra64.h>
#include "functions.h"

extern s32 D_80747D70;
extern s16 D_807F9434;

typedef struct {
    u16 unk0; // Object Model 2 Type
    s16 unk2; // X Position
    s16 unk4; // Y Position
    s16 unk6; // Z Position
    s16 unk8; // Scale
    s16 unkA;
} Struct807F9430;

extern Struct807F9430 *D_807F9430;

void func_806643C4(s32 arg0, s32 arg1, f32 arg2);

void func_806641A0(void) {
    s32 i, count;

    count = 0;
    for (i = 0; i < D_80747D70; i++) {
        if (func_8066461C(D_807F6000[i].object_type) != 0) {
            count++;
        }
    }
    D_807F9434 = count;
    if (count != 0) {
        D_807F9430 = malloc(count * sizeof(Struct807F9430));
        count = 0;
        for (i = 0; i < D_80747D70; i++) {
            if (func_8066461C(D_807F6000[i].object_type) != 0) {
                D_807F9430[count].unk0 = D_807F6000[i].object_type;
                D_807F9430[count].unk2 = D_807F6000[i].x_position;
                D_807F9430[count].unk4 = D_807F6000[i].y_position;
                D_807F9430[count].unk6 = D_807F6000[i].z_position;
                func_806643C4(count, D_807F6000[i].object_type, D_807F6000[i].y_rotation);
                D_807F9430[count].unk8 = D_807F6000[i].hitbox_scale * 100.0;
                D_807F9430[count].unkA = D_807F6000[i].unk88;
                count++;
            }
        }
    }
}

void func_806643C4(s32 arg0, s32 arg1, f32 arg2) {
    f32 temp[2];
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp2C[4][4];

    if (arg1 == 0x138) {
        guRotateF(&sp2C[0], arg2, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(&sp2C[0], 0.0f, 0.0f, -10.0f, &sp74, &sp70, &sp6C);
        D_807F9430[arg0].unk2 += sp74;
        D_807F9430[arg0].unk6 += sp6C;
    }
}

void func_806644B0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 i;

    for (i = 0; i < D_807F9434; i++) {
        if (arg0 == D_807F9430[i].unkA) {
            D_807F9430[i].unk2 = arg1;
            D_807F9430[i].unk4 = arg2;
            D_807F9430[i].unk6 = arg3;
            func_806643C4(i, D_807F9430[i].unk0, arg5);
            D_807F9430[i].unk8 = arg4 * 100.0;
            return;
        }
    }
}

void func_806645B8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_807F9434; i++) {
        if (arg0 == D_807F9430[i].unkA) {
            D_807F9430[i].unkA = -1;
        }
    }
}

s32 func_8066461C(s16 arg0) {
    switch (arg0) {
        case 1: // Thin Flame? (2D)
        case 0x10: // Flame (2D)
        case 0x74: // Golden Banana
        case 0xF3: // Torch
        case 0x138: // Torch
        case 0x288: // Rareware GB
            return TRUE;
        default:
            return FALSE;
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_68EA0/func_8066466C.s")

s32 func_8063C2A8(s16);
extern f64 D_80758E10;
void func_80664A38(s16 arg0);
void func_80664834(s16 arg0);

/*
void func_8066466C(void) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f64 temp_f20;
    s16 temp_a0;
    s32 i;
    u16 temp_v0;
    void *temp_v1;

    if (cc_number_of_players < 2) {
        temp_f20 = D_80758E10;
        for (i = 0; i < D_807F9434; i++) {
            temp_f0 = character_change_array->unk224 - D_807F9430[i].unk6;
            temp_f2 = character_change_array->unk21C - D_807F9430[i].unk2;
            temp_f12 = character_change_array->unk220 - D_807F9430[i].unk4;
            if ((temp_f0 * temp_f0) + ((temp_f2 * temp_f2) + (temp_f12 * temp_f12)) < temp_f20) {
                if (D_807F9430[i].unkA != -1) {
                    if (func_8063C2A8(D_807F9430[i].unkA) != 0) {
                        switch (D_807F9430[i].unk0) {
                            case 0x1:
                            case 0x10:
                            case 0xF3:
                            case 0x138:
                                func_80664834(i);
                                break;
                            case 0x74:
                            case 0x288:
                                func_80664A38(i);
                                break;
                        }
                    }
                }
            }
        }
    }
}
*/

extern s32 D_807213D0; // TODO: Datatype
extern f32 D_80758E18;
extern f32 D_80758E1C;

void func_80664834(s16 arg0) {
    if (((rand() % 10000) % 12) == 0) {
        func_807149B8(1);
        func_80714998(7);
        func_80714950(((rand() % 10000) % 50) - 0x78);
        func_8071498C(&func_80717DB4);
        func_807149C8(0xFF, 0xC8, 0xC8, 0xC8);
        func_80714A08(D_80758E18, D_80758E1C);
        func_80714A28(4);
        func_80714CC0(
            &D_807213D0,
            0.0f,
            (D_807F9430[arg0].unk2 + (((rand() % 10000) % 100) / 20.0)) - 2.5,
            D_807F9430[arg0].unk4 + 4.0,
            (D_807F9430[arg0].unk6 + (((rand() % 10000) % 100) / 20.0)) - 2.5
        );
    }
}

extern s32 D_80720A7C; // TODO: Datatype

void func_80664A38(s16 arg0) {
    f32 sp34;

    if (((rand() % 10000) % 10) == 0) {
        sp34 = D_807F9430[arg0].unk8 / 25.0;
        func_807149B8(1);
        func_80714998(2);
        func_80714A28(4);
        func_80714CC0(
            &D_80720A7C,
            0.4f,
            D_807F9430[arg0].unk2 + (((((rand() % 10000) % 300) / 20.0) - 7.5) * sp34),
            D_807F9430[arg0].unk4 + ((((rand() % 10000) % 600) / 20.0) * sp34),
            D_807F9430[arg0].unk6 + (((((rand() % 10000) % 300) / 20.0) - 7.5) * sp34)
        );
    }
}
