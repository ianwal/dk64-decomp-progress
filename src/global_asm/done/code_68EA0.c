#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern SpriteData D_global_asm_80720A7C; // TODO: Datatype
extern SpriteData D_global_asm_807213D0; // TODO: Datatype

extern s32 D_global_asm_80747D70;

typedef struct {
    u16 unk0; // Object Model 2 Type
    s16 unk2; // X Position
    s16 unk4; // Y Position
    s16 unk6; // Z Position
    s16 unk8; // Scale
    s16 unkA;
} Struct807F9430;

extern Struct807F9430 *D_global_asm_807F9430;
extern s16 D_global_asm_807F9434;

void func_global_asm_806641A0(void) {
    s32 i, count;

    count = 0;
    for (i = 0; i < D_global_asm_80747D70; i++) {
        if (func_global_asm_8066461C(D_global_asm_807F6000[i].object_type) != 0) {
            count++;
        }
    }
    D_global_asm_807F9434 = count;
    if (count != 0) {
        D_global_asm_807F9430 = malloc(count * sizeof(Struct807F9430));
        count = 0;
        for (i = 0; i < D_global_asm_80747D70; i++) {
            if (func_global_asm_8066461C(D_global_asm_807F6000[i].object_type) != 0) {
                D_global_asm_807F9430[count].unk0 = D_global_asm_807F6000[i].object_type;
                D_global_asm_807F9430[count].unk2 = D_global_asm_807F6000[i].x_position;
                D_global_asm_807F9430[count].unk4 = D_global_asm_807F6000[i].y_position;
                D_global_asm_807F9430[count].unk6 = D_global_asm_807F6000[i].z_position;
                func_global_asm_806643C4(count, D_global_asm_807F6000[i].object_type, D_global_asm_807F6000[i].y_rotation);
                D_global_asm_807F9430[count].unk8 = D_global_asm_807F6000[i].hitbox_scale * 100.0;
                D_global_asm_807F9430[count].unkA = D_global_asm_807F6000[i].unk88;
                count++;
            }
        }
    }
}

void func_global_asm_806643C4(s32 arg0, s32 arg1, f32 angle) {
    f32 temp[2];
    f32 x, y, z;
    f32 sp2C[4][4];

    if (arg1 == 0x138) {
        guRotateF(sp2C, angle, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp2C, 0.0f, 0.0f, -10.0f, &x, &y, &z);
        D_global_asm_807F9430[arg0].unk2 += x;
        D_global_asm_807F9430[arg0].unk6 += z;
    }
}

void func_global_asm_806644B0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 i;

    for (i = 0; i < D_global_asm_807F9434; i++) {
        if (arg0 == D_global_asm_807F9430[i].unkA) {
            D_global_asm_807F9430[i].unk2 = arg1;
            D_global_asm_807F9430[i].unk4 = arg2;
            D_global_asm_807F9430[i].unk6 = arg3;
            func_global_asm_806643C4(i, D_global_asm_807F9430[i].unk0, arg5);
            D_global_asm_807F9430[i].unk8 = arg4 * 100.0;
            return;
        }
    }
}

void func_global_asm_806645B8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F9434; i++) {
        if (arg0 == D_global_asm_807F9430[i].unkA) {
            D_global_asm_807F9430[i].unkA = -1;
        }
    }
}

s32 func_global_asm_8066461C(s16 arg0) {
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

void func_global_asm_8066466C(void) {
    s32 i;
    f32 d;

    if (cc_number_of_players < 2) {
        for (i = 0; i < D_global_asm_807F9434; i++) {
            d = ((character_change_array->unk21C - D_global_asm_807F9430[i].unk2) * (character_change_array->unk21C - D_global_asm_807F9430[i].unk2)) + ((character_change_array->unk220 - D_global_asm_807F9430[i].unk4) * (character_change_array->unk220 - D_global_asm_807F9430[i].unk4)) + ((character_change_array->unk224 - D_global_asm_807F9430[i].unk6) * (character_change_array->unk224 - D_global_asm_807F9430[i].unk6));
            if (d < 90000.0) {
                if (D_global_asm_807F9430[i].unkA != -1) {
                    if (func_global_asm_8063C2A8(D_global_asm_807F9430[i].unkA) != 0) {
                        switch (D_global_asm_807F9430[i].unk0) {
                            case 0x1:
                            case 0x10:
                            case 0xF3:
                            case 0x138:
                                func_global_asm_80664834(i);
                                break;
                            case 0x74:
                            case 0x288:
                                func_global_asm_80664A38(i);
                                break;
                        }
                    }
                }
            }
        }
    }
}

void func_global_asm_80664834(s16 arg0) {
    if (((rand() % 10000) % 12) == 0) {
        func_global_asm_807149B8(1);
        func_global_asm_80714998(7);
        func_global_asm_80714950(((rand() % 10000) % 50) - 0x78);
        func_global_asm_8071498C(func_global_asm_80717DB4);
        changeActorColor(0xFF, 0xC8, 0xC8, 0xC8);
        func_global_asm_80714A08(0.2f, 0.1f);
        func_global_asm_80714A28(4);
        drawSpriteAtPosition(
            &D_global_asm_807213D0,
            0.0f,
            (D_global_asm_807F9430[arg0].unk2 + (((rand() % 10000) % 100) / 20.0)) - 2.5,
            D_global_asm_807F9430[arg0].unk4 + 4.0,
            (D_global_asm_807F9430[arg0].unk6 + (((rand() % 10000) % 100) / 20.0)) - 2.5
        );
    }
}

void func_global_asm_80664A38(s16 arg0) {
    f32 sp34;

    if (((rand() % 10000) % 10) == 0) {
        sp34 = D_global_asm_807F9430[arg0].unk8 / 25.0;
        func_global_asm_807149B8(1);
        func_global_asm_80714998(2);
        func_global_asm_80714A28(4);
        drawSpriteAtPosition(
            &D_global_asm_80720A7C,
            0.4f,
            D_global_asm_807F9430[arg0].unk2 + (((((rand() % 10000) % 300) / 20.0) - 7.5) * sp34),
            D_global_asm_807F9430[arg0].unk4 + ((((rand() % 10000) % 600) / 20.0) * sp34),
            D_global_asm_807F9430[arg0].unk6 + (((((rand() % 10000) % 300) / 20.0) - 7.5) * sp34)
        );
    }
}
