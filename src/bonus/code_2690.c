#include <ultra64.h>
#include "functions.h"

// TODO: Is there a file split somewhere in here? Rodata messes up around D_bonus_8002DDD4
//rodata
extern const f32 D_bonus_8002DD20; // = 3.2f;
extern const f32 D_bonus_8002DD28; // = 385.0f;
extern const f32 D_bonus_8002DDEC; // = 0.8f;

typedef struct {
    u8 unk0[0x1E - 0];
    s16 unk1E;
    s16 unk20;
} AAD_80026690;

Gfx *func_bonus_80026690(Gfx *dl, Actor *arg1) {
    f32 temp_f20;
    s16 sp6A;
    s16 sp68;
    AAD_80026690 *aaD;

    aaD = arg1->additional_actor_data;
    sp6A = aaD->unk1E;
    sp68 = aaD->unk20;
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(dl++, &D_1000118);
    temp_f20 = D_bonus_8002DD20;
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    dl =   func_global_asm_8068C5A8(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A - 0x34), (s16)(sp68 - 0x34), temp_f20, temp_f20, 0xE1, 0.0f);
    dl =   func_global_asm_8068C5A8(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A + 0x34), (s16)(sp68 - 0x34), temp_f20, temp_f20, 0x13B, 0.0f);
    dl =   func_global_asm_8068C5A8(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A + 0x34), (s16)(sp68 + 0x34), temp_f20, temp_f20, 0x2D, 0.0f);
    return func_global_asm_8068C5A8(dl, (((object_timer / 2U) % 12U) + 0x83), 0, 2, 0x20, 0x10, (s16)(sp6A - 0x34), (s16)(sp68 + 0x34), temp_f20, temp_f20, 0x87, 0.0f);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80026940.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80026CF0.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} AAD_bonus_800271B4;

typedef struct {
    Actor* unk0[4]; // Used, might be bigger
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u8 unk28; // Used
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    f32 unk2C; // Used
} Struct800271B4;

void func_bonus_800271B4(s16 arg0, s16 arg1, s16 arg2, u8 arg3, Struct800271B4 *arg4) {
    u8 var_a3;
    AAD_bonus_800271B4 *temp_v1;

    var_a3 = arg4->unk28 < ((rand() >> 0xF) % 100) ? 1 : 0;
    if (func_global_asm_80677FA8(ACTOR_MINIGAME_KREMLING, var_a3 ? 0x32 : 0x33) != 0) {
        temp_v1 = D_global_asm_807FBB44->additional_actor_data;
        func_global_asm_80614EBC(D_global_asm_807FBB44, var_a3 ? 0x211 : 0x20F);
        func_global_asm_80614D00(D_global_asm_807FBB44, arg4->unk2C, 0);
        D_global_asm_807FBB44->x_position = arg0;
        D_global_asm_807FBB44->y_position = arg1 - 0x19;
        D_global_asm_807FBB44->z_position = arg2;
        D_global_asm_807FBB44->y_rotation = 0xC00;
        temp_v1->unk9 = arg3;
        temp_v1->unk8 = var_a3;
        temp_v1->unk0 = arg4;
        arg4->unk0[arg3] = D_global_asm_807FBB44;
    }
}

typedef struct bonus_struct_0 {
    u8 pad0[0x9];
    u8 unk9;
} BonusStruct0;

void func_bonus_80027308(BonusStruct0 *arg0, s32 *arg1) {
    *(arg1 + (arg0->unk9)) = 0;
    func_global_asm_806782C0(current_actor_pointer);
}

extern s32 D_global_asm_8071FFD4;

typedef struct {
    s32 unk0;
    void *unk4[1];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s8 unk18[1];
} Struct8002733C;

void func_bonus_8002733C(Struct8002733C *arg0) {
    s16 i;
    s16 var_s2;

    var_s2 = 0x118;
    for (i = 0; i < 5; i++) {
        if (arg0->unk4[i] != NULL) {
            func_global_asm_80715908(arg0->unk4[i]);
        }
        arg0->unk18[i] = 0;
        func_global_asm_8071495C();
        func_global_asm_807149FC(-1);
        func_global_asm_80714998(2);
        func_global_asm_80714944(i * 3);
        func_global_asm_8071498C(&func_global_asm_8071A038);
        func_global_asm_80714950(&arg0->unk18[i]);
        arg0->unk4[i] = func_global_asm_80714CC0(&D_global_asm_8071FFD4, 1.0f, var_s2, 210.0f, -10.0f);
        var_s2 -= 0x1E;
    }
    playSound(0x3E4, 0x7FFF, 63.0f, 1.0f, 5, 0);
}

void func_bonus_800274A0(f32 arg0, f32 arg1, f32 arg2) {
    playSound(0x59, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
    func_global_asm_806907F0(current_actor_pointer->x_position, current_actor_pointer->y_position - 10.0f, current_actor_pointer->z_position);
    func_global_asm_80690A28(0x23, 1, 0.6f, arg0, arg1, arg2, D_bonus_8002DD28, current_actor_pointer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80027548.s")

extern f64 D_bonus_8002DD30;
extern f64 D_bonus_8002DD38;
extern u16 D_global_asm_807FD63C;

typedef struct {
    s32 unk0;
    s32 unk4[1];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18[1]; // Used
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s16 unk1C;
    s16 unk1E; // Used
    s16 unk20; // Used
    u8 unk22; // Used
    u8 unk23; // Used
    s16 unk24;
    s8 unk26; // Used
    s8 unk27;
    s32 unk28;
    s32 unk2C;
} AAD_bonus_80027548;

/*
// TODO: Extremely close, stack
u8 func_bonus_80027548(f32 arg0, f32 arg1, f32 arg2) {
    AAD_bonus_80027548 *aaD;
    f32 sp50;
    f32 sp4C;
    u8 sp40; // TODO: Need to move this from 0x4B to 0x40 without growing the stack

    aaD = current_actor_pointer->additional_actor_data;
    sp40 = 0;
    aaD->unk26 = 1;
    func_global_asm_80626F8C(arg0, arg1, arg2, &sp50, &sp4C, 0, 4.0f, 0);
    aaD->unk1E = sp50;
    aaD->unk20 = sp4C;
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(arg0, arg2, current_actor_pointer->x_position, current_actor_pointer->z_position), 10.0f);
    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, ((func_global_asm_80611BB4(current_actor_pointer->y_position - arg1, sqrtf(((current_actor_pointer->x_position - arg0) * (current_actor_pointer->x_position - arg0)) + ((current_actor_pointer->z_position - arg2) * (current_actor_pointer->z_position - arg2)))) * 2048.0) / D_bonus_8002DD30) + D_bonus_8002DD38, 5.0f);
    if ((D_global_asm_807FD63C & 0xE000) && (current_actor_pointer->control_state == 0)) {
        sp40 = 1;
        if (aaD->unk22 != 0) {
            if ((aaD->unk23 != 0) && (aaD->unk18[0] == 0)) {
                s16 i;
                func_bonus_800274A0(arg0, arg1, arg2);
                aaD->unk23--;
                func_global_asm_80715908(aaD->unk4[aaD->unk23]);
                func_global_asm_8060E7EC(0, 0xFF, 3);
                aaD->unk4[aaD->unk23] = 0;
                for (i = 0; i < aaD->unk23; i++) {
                    aaD->unk18[i] = 0xA;
                }
            } else if ((aaD->unk23 == 0) && (current_actor_pointer->control_state_progress == 0)) {
                sp40 = 2;
                current_actor_pointer->control_state_progress = 1;
            }
        } else if (aaD->unk23 < 5) {
            aaD->unk23 = 5;
            func_bonus_8002733C(aaD);
            current_actor_pointer->control_state_progress = 0;
        }
    }
    return sp40;
}
*/

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_800277F8.s")

extern f32 D_bonus_8002DD40;
extern f32 D_bonus_8002DD44;
extern f32 D_bonus_8002DD48;
extern f32 D_bonus_8002DD4C;
extern f32 D_bonus_8002DD50;
void func_bonus_80026940();

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
} AAD_bonus_800277F8;

typedef struct {
    s32 unk0[4]; // TODO: Might be bigger
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    f32 unk2C;
} A178_800277F8;

u8 func_bonus_80027548(f32 arg0, f32 arg1, f32 arg2);
u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);
void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2);

/*
void func_bonus_800277F8(void) {
    AAD_bonus_800277F8 *aaD;
    A178_800277F8 *a178;
    f32 temp_f2;
    f32 var_f12;
    u8 temp_t2;
    Struct807F5FD4_unk0 *temp_v0;

    aaD = current_actor_pointer->additional_actor_data;
    a178 = ((A178_800277F8*)current_actor_pointer->unk178);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        a178->unk25 = func_global_asm_806FDB8C(1, func_global_asm_8070E750(0x1A, 2, 1), 8, 0.0f, 0.0f, 0.0f);
        func_global_asm_806FDAB8(a178->unk25, 0.0f);
        aaD->unk23 = 5;
        aaD->unk0 = -2;
        aaD->unk22 = 0;
        func_global_asm_806EB0C0(0x48, NULL, 0);
        func_global_asm_8061C464(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x800, -7, 0, 0x16, 0x2C, 4, 0, D_bonus_8002DD40);
        playCutscene(NULL, 0, 1);
        current_actor_pointer->z_rotation = 0x310;
        switch (current_map) {
            case MAP_KREMLING_KOSH_VERY_EASY:
                a178->unk27 = 0x55;
                a178->unk28 = 0x46;
                a178->unk2C = D_bonus_8002DD44;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x12;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_EASY:
                a178->unk27 = 0x5A;
                a178->unk28 = 0x46;
                a178->unk29 = 0x3C;
                a178->unk2C = 1.0f;
                a178->unk20 = 0x16;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_NORMAL:
                a178->unk27 = 0x57;
                a178->unk28 = 0x50;
                a178->unk2C = D_bonus_8002DD48;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x19;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_HARD:
                a178->unk27 = 0x5C;
                a178->unk28 = 0x50;
                a178->unk2C = D_bonus_8002DD4C;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x1C;
                a178->unk22 = a178->unk20;
                break;
        }
    }
    if (aaD->unk0 > 0) {
        aaD->unk22 = 0;
        if ((current_actor_pointer->control_state == 0) && ((D_global_asm_807FD610->unk30 >= 0x1F) || (D_global_asm_807FD610->unk31 >= 0x1F))) {
            temp_f2 = ((func_global_asm_80611BB4(D_global_asm_807FD610->unk2F, D_global_asm_807FD610->unk2E) / D_bonus_8002DD50) * 8.0) + 5.5;
            var_f12 = temp_f2;
            if (temp_f2 > 9.0f) {
                var_f12 = temp_f2 - 8.0f;
            }
            aaD->unk22 = var_f12;
        }
        if (func_bonus_80027548(D_global_asm_807F5FD4->unk0[0][aaD->unk22].unk0, D_global_asm_807F5FD4->unk0[0][aaD->unk22].unk4, D_global_asm_807F5FD4->unk0[0][aaD->unk22].unk8) == 2) {
            aaD->unk25 = 0xFF;
            playSound(0x3BC, 0x7FFF, 63.0f, 1.0f, 0, 0);
        }
        switch (current_actor_pointer->control_state) {
            case 0x0:
                if (current_actor_pointer->unk11C->control_state == 5) {
                    current_actor_pointer->control_state = 0xFF;
                }
                if (a178->unk22 == 0) {
                    func_bonus_800264E0(0, 0);
                    playCutscene(NULL, 1, 0x11);
                    current_actor_pointer->control_state = 1;
                } else {
                    if (a178->unk27 < ((rand() >> 0xF) % 100)) {
                        temp_t2 = ((rand() >> 0xF) % 255) % 8;
                        if (a178->unk0[temp_t2] == 0) {
                            temp_v0 = &D_global_asm_807F5FD4->unk0[0][temp_t2 + 1];
                            func_bonus_800271B4(temp_v0->unk0, temp_v0->unk4, temp_v0->unk8, temp_t2, a178);
                        }
                    }
                }
                if ((current_actor_pointer->unk11C->control_state == 4) && (current_actor_pointer->unk11C->control_state_progress != 0xFF)) {
                    current_actor_pointer->control_state = 0xFE;
                }
                break;
            case 0xFE:
                aaD->unk24 = 0xFF;
                playSound(0x142, 0x7FFF, 63.0f, 1.0f, 0, 0);
                current_actor_pointer->control_state = 0;
                break;
            case 0xFF:
                func_bonus_800265C0(0, 5);
                playCutscene(NULL, 1, 0x11);
                current_actor_pointer->control_state = 1;
                break;
        }
    } else if (aaD->unk0 != -2 && aaD->unk0 != -1) {
        if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
            aaD->unk0 = 1;
            func_global_asm_806A2B08(current_actor_pointer->unk11C);
            func_bonus_8002733C(aaD);
            playSong(8, 1.0f);
        }
    } else if (is_cutscene_active != 1) {
        aaD->unk0++;
        func_global_asm_806A2A10(0xDC, 0x2A, a178->unk29);
        func_global_asm_8070D8C0(current_actor_pointer, 0, 1);
    }
    if (aaD->unk0 >= -1) {
        func_global_asm_8068C350(&func_bonus_80026940, current_actor_pointer, 3);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/

// TODO: Similar to above but for TTT
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80027F14.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u16 unk20;
    s16 unk22; // Used
    u8 unk24;
    u8 unk25; // Used
    u16 unk26;
} AAD_bonus_800284C0_unk0;

typedef struct {
    AAD_bonus_800284C0_unk0 *unk0; // Used
    u32 unk4;
    u8 unk8; // Used
} AAD_bonus_800284C0;

extern u8 D_global_asm_807FBB85;

void func_global_asm_8072881C(s32, void*);

void func_bonus_800284C0(void) {
    AAD_bonus_800284C0 *temp_a2;
    AAD_bonus_800284C0_unk0 *temp_a3;
    s32 var_a1;

    temp_a2 = current_actor_pointer->additional_actor_data;
    temp_a3 = temp_a2->unk0;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x24;
    }
    func_global_asm_8072881C(0, &temp_a2->unk4);
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FBB85 != 0) {
                temp_a3->unk22 = MAX(0, temp_a3->unk22 - (temp_a2->unk8 ? 2 : 1));
                func_global_asm_806FDAB8(temp_a3->unk25, 3.1415927f);
                func_global_asm_80614EBC(current_actor_pointer, (temp_a2->unk8 ? 0x212 : 0x210));
                current_actor_pointer->control_state = 1;
                current_actor_pointer->control_state_progress = 0;
                break;
            }
            if (current_actor_pointer->control_state_progress != 0) {
                func_bonus_80027308(temp_a2, temp_a3);
            }
            break;
        case 1:
            if (current_actor_pointer->control_state_progress != 0) {
                func_bonus_80027308(temp_a2, temp_a3);
            }
            break;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// doable close regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80028648.s")

typedef struct {
    s32 unk0[6]; // Used
    s16 unk18;
    u8 unk1A;
    u8 unk1B; // Used
    u8 unk1C; // Used
} ARG0_80028648;

typedef struct {
    Actor* unk0; // Used
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11; // Used
} AAD_bonus_80028648;

typedef struct {
    Actor* unk0; // Used
    s16 unk4;
    s8 unk6; // Used
    s8 unk7;
    s16 unk8; // Used
} AAD_bonus_80028648_2;

/*
void func_bonus_80028648(ARG0_80028648 *arg0) {
    s32 i;
    AAD_bonus_80028648 *snakeAAD;
    AAD_bonus_80028648_2 *turtleAAD;
    Struct807F5FD4_unk0 *temp;

    for (i = 1; i < 7; i++) {
        if (func_global_asm_80677FA8(ACTOR_SNAKE, 0x15) != 0) {
            snakeAAD = D_global_asm_807FBB44->additional_actor_data;
            snakeAAD->unk0 = current_actor_pointer;
            snakeAAD->unk11 = (((rand() >> 0xF) % 32767) % ((arg0->unk1C - arg0->unk1B) + 1)) + arg0->unk1B;
            temp = &D_global_asm_807F5FD4->unk0[0][i];
            func_global_asm_80614EBC(D_global_asm_807FBB44, 0x1F5);
            D_global_asm_807FBB44->x_position = temp->unk0;
            D_global_asm_807FBB44->y_position = temp->unk4;
            D_global_asm_807FBB44->z_position = temp->unk8;
            D_global_asm_807FBB44->object_properties_bitfield |= 0x1000;
            D_global_asm_807FBB44->y_rotation = 0x800;
            arg0->unk0[i - 1] = D_global_asm_807FBB44;
            if (func_global_asm_80677FA8(ACTOR_TURTLE, 0x16) != 0) {
                turtleAAD = D_global_asm_807FBB44->additional_actor_data;
                turtleAAD->unk0 = D_global_asm_807FBB44;
                turtleAAD->unk6 = i - 1;
                snakeAAD->unk4 = D_global_asm_807FBB44;
                turtleAAD->unk8 = -1;
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002881C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80028E3C.s")

extern s16 D_bonus_8002D8C0[];

extern f64 D_bonus_8002DD98;
extern f32 D_bonus_8002DDA0;
extern f32 D_bonus_8002DDA4;
extern f32 D_bonus_8002DDA8;

typedef struct {
    Actor *unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    f32 unkC;
} AAD_bonus_80028E3C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s8 unk10;
} AAD_bonus_80028E3C_2;

/*
// TODO: Very close
void func_bonus_80028E3C(void) {
    AAD_bonus_80028E3C *aaD;
    AAD_bonus_80028E3C_2 *aaD2;
    f32 temp_f2;
    f64 temp_f0;
    f32 var_f0_2;
    f32 var_f2;
    s16 var_a3;
    s32 var_a0;

    aaD = current_actor_pointer->additional_actor_data;
    aaD2 = aaD->unk0->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->y_rotation = (rand() >> 0xF) % 4096;
        current_actor_pointer->y_acceleration = -10.0f;
        current_actor_pointer->unk6A &= 0xFFFE;
        func_global_asm_80613C48(current_actor_pointer, 0x688, 0.0f, 0.0f);
        func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
    }
    if (aaD2->unk10 == -1) {
        if (aaD->unk4 == 0) {
            if (aaD2->unkC < 220.0f) {
                if (aaD->unk5 == 0) {
                    var_a0 = 0x7F;
                    aaD->unk5 = 1;
                    var_a3 = aaD->unk6 % 3;
                    if ((aaD->unk6 / 3) != 0) {
                        var_a3 = 2 - var_a3;
                        var_a0 = 0x64;
                    }
                    func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, D_bonus_8002D8C0[var_a3], 0xFF, var_a0, 0, 0, 0.0f, 0);
                }
                if (aaD2->unkC < 40.0f) {
                    aaD->unk4 = 1;
                    func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x1ED, 0xFF, 0x7F, 0, 0, 0.0f, 0);
                    func_global_asm_80608528(current_actor_pointer, 0x76, 0xFF, 0x7F, 0x1E);
                    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                    current_actor_pointer->unkB8 = 10.0f;
                    func_global_asm_80614EBC(aaD->unk0, 0x1F7);
                }
            }
        }
    }
    if (aaD->unk4 == 0) {
        func_global_asm_80671C0C(aaD->unk0, 1, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    } else {
        if (current_actor_pointer->unk6A & 1) {
            if (!(current_actor_pointer->unk6C & 1)) {
                f64 temp = D_bonus_8002DD98;
                current_actor_pointer->y_velocity = aaD->unkC * D_bonus_8002DDA0;
                func_global_asm_80608528(current_actor_pointer, 0xFF, (u32)MAX(temp, -aaD->unkC * 1.5), 0x7F, 0xA);
            }
        }
        current_actor_pointer->y_velocity += current_actor_pointer->y_acceleration;
        aaD->unkC = current_actor_pointer->y_velocity;
        func_global_asm_8067ACB4(current_actor_pointer);
        func_global_asm_806651FC(current_actor_pointer);
        func_global_asm_80665564(current_actor_pointer, 0);
    }
    current_actor_pointer->y_rotation = current_actor_pointer->y_rotation + aaD2->unkC;
    if (current_actor_pointer->y_rotation >= 0x1000) {
        current_actor_pointer->y_rotation = current_actor_pointer->y_rotation - 0x1000;
    }
    temp_f2 = D_bonus_8002DDA4 / aaD2->unkC;
    current_actor_pointer->x_rotation = func_global_asm_80612794(current_actor_pointer->y_rotation) * -temp_f2;
    current_actor_pointer->z_rotation = func_global_asm_80612790(current_actor_pointer->y_rotation) * temp_f2;
    temp_f2 = temp_f2 * D_bonus_8002DDA8;
    if (temp_f2 < 1) {
        var_f2 = 1;
    } else {
        var_f2 = MIN(2.5f, temp_f2);
    }
    func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80029364.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80029B9C.s")

// rodata, needs D_global_asm_807F5FD4 shape, otherwise doable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_80029E54.s")

/*
? func_global_asm_806F0C18(Actor *, s16 *);
extern s16 D_bonus_8002D8C8[];
extern ? D_bonus_8002D8D4;
extern f32 D_bonus_8002DDB8;

void func_bonus_80029E54(Actor *arg0) {
    s16 *var_s2;
    Actor *temp_v0;
    Actor *temp_v0_2;
    f32 temp_f22;
    f32 var_f0;
    s16 *a17C;
    s32 temp_s7;
    s32 var_s1;
    s32 var_s4;
    s8 temp_t7;
    void *temp_a0;
    void *aaD;

    temp_f22 = D_bonus_8002DDB8;
    temp_s7 = arg0->unk178;
    var_s2 = &D_bonus_8002D8C8;
    var_s1 = 1;
    do {
        if (func_global_asm_80677FA8(ACTOR_MINIGAME_KRAZYKONGKLAMOUR_KONG, var_s2[var_s1]) != 0) {
            temp_t7 = var_s1 - 1;
            aaD = current_actor_pointer->additional_actor_data;
            a17C = current_actor_pointer->unk17C;
            a17C->unk0 = var_s2[var_s1];
            aaD->unk0 = arg0;
            aaD->unk4 = temp_t7;
            temp_a0 = (((temp_s7 + (temp_t7 & 0xFF))->unk8 & 0x7F) * 0xC) + *D_global_asm_807F5FD4 + 0xC;
            current_actor_pointer->x_position = temp_a0->unk0;
            current_actor_pointer->y_position = temp_a0->unk4;
            current_actor_pointer->z_position = temp_a0->unk8;
            current_actor_pointer->control_state = 0;
            temp_v0_2 = D_global_asm_807FBB44;
            temp_v0_2->object_properties_bitfield |= 0x1000;
            D_global_asm_807FBB44->y_rotation = 0x800;
            if (var_s1 != 6) {
                func_global_asm_806F0C18(D_global_asm_807FBB44, a17C);
                func_global_asm_80614EBC(D_global_asm_807FBB44, D_bonus_8002D8D4[var_s1]);
            }
            if (var_s1 != 6) {
                var_f0 = 0.25f;
            } else {
                var_f0 = temp_f22;
            }
            D_global_asm_807FBB44->animation_state->scale[0] = var_f0;
            D_global_asm_807FBB44->animation_state->scale[1] = var_f0;
            D_global_asm_807FBB44->animation_state->scale[2] = var_f0;
        }
        var_s1 += 1;
    } while (var_s1 != 7);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002A010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002A398.s")

s32 func_global_asm_806119A0();
extern s16 D_bonus_8002D900;

typedef struct {
    s32 unk0;
    s8 unk4;
} AAD_PPPFairy;

typedef struct {
    u8 unk0[0x06 - 0x0];
    s16 unk6;
} AAD_bonus_8002AAA4;

void func_bonus_8002AAA4(void) {
    AAD_bonus_8002AAA4 *aaD;
    s32 pad;
    s32 pad2;
    Actor *fairy;
    s32 sp54;
    AnimationStateUnk0 *sp50;
    ActorAnimationState *animationState;
    GlobalASMStruct53 *var_s0;
    f32 dy;
    f32 dx;
    s32 i;
    AAD_PPPFairy *fairyAAD;

    aaD = current_actor_pointer->additional_actor_data;
    animationState = current_actor_pointer->animation_state;
    sp50 = animationState->unk0;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80614EBC(current_actor_pointer, 0x239);
        current_actor_pointer->noclip_byte = 0x24;
        animationState = current_actor_pointer->animation_state;
    }
    sp54 = animationState->unk64;
    if (sp54 == 0x239) {
        for (i = 0; i < D_global_asm_807FBB34; i++) {
            fairy = D_global_asm_807FB930[i].unk0;
            if (fairy->unk58 == ACTOR_MINIGAME_PERILPATHPANIC_FAIRY) {
                dx = fairy->x_position - current_actor_pointer->x_position;
                dy = fairy->y_position - current_actor_pointer->y_position;
                if (dx < 5.0 && dx > -5.0 ) {
                    if (dy < 20.0f && dy > -20.0) {
                        fairyAAD = fairy->additional_actor_data;
                        fairyAAD->unk4 = 8;
                        func_global_asm_80614EBC(current_actor_pointer, 0x23B);
                    }
                }
            }
        }
    }
    if (sp54 == 0x239 || sp54 == 0x23B || (sp54 == 0x238 && sp50 != NULL && sp50->unk4 > 48.0f)) {
        if (D_global_asm_807FBB85 == 1) {
            func_global_asm_80614EBC(current_actor_pointer, 0x23C);
            aaD->unk6 = ((func_global_asm_806119A0() & 7) + 6) * D_bonus_8002D900;
        }
    }
    if (sp54 == 0x23A) {
        aaD->unk6--;
        if (aaD->unk6 == 0) {
            func_global_asm_80614EBC(current_actor_pointer, 0x238);
        }
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

typedef struct {
    Actor *unk0;
    s8 unk4;
} aaD_bonus_8002AD10;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} a8D_bonus_8002AD10;

void func_bonus_8002AD10(void) {
    Struct807F5FD4_unk0 *pad1;
    aaD_bonus_8002AD10 *var_t0;
    Actor *pad2;
    a8D_bonus_8002AD10 *temp_a2;

    var_t0 = current_actor_pointer->additional_actor_data;
    pad2 = var_t0->unk0;
    temp_a2 = pad2->unk178;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80614EBC(current_actor_pointer, 0x2B5);
    }
    if (var_t0->unk4 == 0 || var_t0->unk4 >= 5) {
        current_actor_pointer->x_position -= 1.5;
    }
    pad1 = &D_global_asm_807F5FD4->unk0[0][3];
    if (current_actor_pointer->x_position < pad1->unk0 - 50.0) {
        if (temp_a2->unkA > 0) {
            temp_a2->unkA--;
        }
        func_global_asm_806782C0(current_actor_pointer);
    }
    if (var_t0->unk4 != 0) {
        var_t0->unk4--;
        if (var_t0->unk4 < 4) {
            f32 temp;
            if (var_t0->unk4 == 3) {
                playSound(0x2D2, 0x7FFF, 63.0f, 7.12f, 0, 1);
            }
            temp = D_bonus_8002DDEC;
            current_actor_pointer->animation_state->scale_x *= temp;
            current_actor_pointer->animation_state->scale_y *= temp;
            current_actor_pointer->animation_state->scale_z *= temp;
        }
        if (var_t0->unk4 == 0) {
            func_global_asm_806782C0(current_actor_pointer);
        }
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002AED8.s")

// regalloc, stack
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002B920.s")

extern f32 D_bonus_8002DE40;
extern f64 D_bonus_8002DE48;

typedef struct {
    Actor* unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} AAD_bonus_8002B920;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s16 unk28;
    s16 unk2A;
    s8 unk2C;
    s8 unk2D[1];
} AAD_bonus_8002B920_2;

/*
void func_bonus_8002B920(void) {
    AAD_bonus_8002B920 *aaD1;
    AAD_bonus_8002B920_2 *aaD2;
    Actor *temp_t6;

    aaD1 = current_actor_pointer->additional_actor_data;
    temp_t6 = aaD1->unk0;
    aaD2 = temp_t6->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        f32 temp;
        func_global_asm_80614EBC(current_actor_pointer, 0x32F);
        current_actor_pointer->animation_state->scale_z = \
        current_actor_pointer->animation_state->scale_y = \
        current_actor_pointer->animation_state->scale_x = temp = D_bonus_8002DE40;
        func_global_asm_80604CBC(current_actor_pointer, 0x10E, 0x3C, 1, 0, 0xFF, 1.0f, 0);
    }
    if (current_actor_pointer->control_state == 0) {
        f32 sp40;
        if (aaD2->unk2C == 0) {
            if (aaD1->unkC > 0) {
                if (aaD1->unkC == 0x28) {
                    func_global_asm_8060866C(current_actor_pointer, 0x801, 0xFF, 3.0f, 2, 0);
                }
                aaD1->unkC--;
                sp40 = 5.0f;
            } else {
                sp40 = 3.0f;
            }
            current_actor_pointer->y_rotation -= func_global_asm_806CC10C(func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, aaD1->unk4, aaD1->unk8) + 0x800, current_actor_pointer->y_rotation) >> 3;
            current_actor_pointer->x_position += func_global_asm_80612794(current_actor_pointer->y_rotation) * sp40;
            current_actor_pointer->z_position += func_global_asm_80612790(current_actor_pointer->y_rotation) * sp40;
            aaD1->unkE--;
            if (aaD1->unkE <= 0) {
                s32 temp_s0_3;
                f32 temp_f10;
                if (aaD1->unkC > 0) {
                    aaD1->unkE = (func_global_asm_806119A0() & 7) + 0xA;
                } else {
                    aaD1->unkE = (func_global_asm_806119A0() & 0x3F) + 0xF;
                }
                temp_s0_3 = func_global_asm_80665DE0(aaD2->unk0, aaD2->unk4, aaD1->unk4, aaD1->unk8) + ((func_global_asm_806119A0() & 7) << 8) + 0x400;
                temp_f10 = func_global_asm_806119FC() * D_bonus_8002DE48;
                aaD1->unk4 = (func_global_asm_80612794(temp_s0_3) * temp_f10) + aaD2->unk0;
                aaD1->unk8 = (func_global_asm_80612790(temp_s0_3) * temp_f10) + aaD2->unk4;
            }
        } else {
            if (aaD2->unk2C == 0x28) {
                func_global_asm_8060866C(current_actor_pointer, 0x801, 0xFF, 3.0f, 2, 0);
            }
            current_actor_pointer->y_position = (func_global_asm_80612794(aaD2->unk18) * 5.0) + (temp_t6->y_position - 30.0);
        }
    } else {
        current_actor_pointer->shadow_opacity -= 4;
        if (current_actor_pointer->shadow_opacity < 5) {
            current_actor_pointer->shadow_opacity = 0;
            func_global_asm_806782C0(current_actor_pointer);
        }
    }
    if (temp_t6->control_state == 2) {
        f32 dz;
        f32 dx;
        dx = ((func_global_asm_80612794(temp_t6->y_rotation) * 65.0f) + temp_t6->x_position) - current_actor_pointer->x_position;
        dz = ((func_global_asm_80612790(temp_t6->y_rotation) * 65.0f) + temp_t6->z_position) - current_actor_pointer->z_position;
        if (current_actor_pointer->control_state == 0) {
            if ((dx < 12.0) && (dx > -12.0) && ((dz < 12.0)) && (dz > -12.0)) {
                s32 var_v0;
                func_global_asm_80605314(current_actor_pointer, 0);
                func_global_asm_80614EBC(current_actor_pointer, 0x331);
                if (aaD2->unk2A != 0) {
                    aaD2->unk2A--;
                }
                var_v0 = 0;
                do {
                    if (aaD2->unk2D[var_v0] == 0) {
                        aaD2->unk2D[var_v0] = 0x1E;
                        var_v0 = 1;
                    }
                    var_v0++;
                } while (var_v0 <= 0);
                current_actor_pointer->control_state = 1;
                func_global_asm_8060866C(current_actor_pointer, 0x16, 0xFF, 1.0f, 0x14, 0);
                current_actor_pointer->shadow_opacity = 0xFF;
                current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            } else if (((dx * dx) + (dz * dz)) < 900.0f) {
                aaD1->unkC = 0x3C;
                aaD1->unkE = 1;
            }
        }
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002BE44.s")

/*
// TODO: what a mess
void func_global_asm_80614644(Actor *, ActorAnimationState *, s32);
extern f32 D_bonus_8002DE50;
extern f64 D_bonus_8002DE58;
typedef struct BonusStruct1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} BonusStruct1;

typedef struct bonus_additional_actor_data {
    s32 unk0;
    BonusStruct1* unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad0[0x7C - 0x14];
    f32 x_position;
    f32 y_position;
    f32 z_position;
} BonusAdditionalActorData;

void func_bonus_8002BE44() {
    ActorAnimationState *sp24;
    BonusAdditionalActorData *temp_a0;
    BonusStruct1 *temp_t8;
    s16 phi_a1;

    temp_a0 = ((BonusAdditionalActorData*)current_actor_pointer->additional_data_pointer);
    sp24 = current_actor_pointer->animation_state;
    temp_t8 = temp_a0->unk4;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->z_rotation = 0;
        current_actor_pointer->y_rotation = 0x800;
        func_global_asm_80613C48(temp_a0, 0x5FB, 0, 0);
        current_actor_pointer->animation_state->scale_x =// D_bonus_8002DE50;
        current_actor_pointer->animation_state->scale_z =// D_bonus_8002DE50;
        current_actor_pointer->animation_state->scale_y = D_bonus_8002DE50;
    }
    current_actor_pointer->x_position = temp_a0->x_position;
    current_actor_pointer->y_position = temp_a0->y_position - D_bonus_8002DE58;
    current_actor_pointer->z_position = temp_a0->z_position;
    if (sp24 && temp_t8) {
        phi_a1 = temp_t8->unk10;
        if (phi_a1 == 0x5FD) {
            phi_a1 = 0x5FE;
        }
        if (phi_a1 != sp24->unk10) {
            func_global_asm_80613C48(current_actor_pointer, phi_a1, 0, 0);
        }
        func_global_asm_80614644(current_actor_pointer, sp24, temp_t8->unk4);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002BF98.s")

extern f32 D_bonus_8002D90C;
extern u8 D_global_asm_807FBB85;

typedef struct {
    Actor* unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    s16 unkC;
} AAD_bonus_8002C8EC;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s16 unk28;
    s8 unk2A[1];
    s32 unk2C;
} AAD_bonus_8002C8EC_2;

void func_bonus_8002C8EC(void) {
    s32 pad[3];
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    s16 temp_s0_2;
    s32 var_v0;
    Actor *temp;
    AAD_bonus_8002C8EC *temp_s2;
    AAD_bonus_8002C8EC_2 *temp_s3;
    AAD_bonus_8002C8EC_2 *temp_v1_2;

    temp_s2 = current_actor_pointer->additional_actor_data;
    temp = temp_s2->unk0;
    temp_s3 = temp->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80614EBC(current_actor_pointer, 0x232);
        current_actor_pointer->noclip_byte = 0x24;
        current_actor_pointer->animation_state->scale_x = 0.25f;
        current_actor_pointer->animation_state->scale_y = 0.25f;
        current_actor_pointer->animation_state->scale_z = 0.25f;
    }
    if (current_actor_pointer->control_state == 0) {
        sp40 = D_bonus_8002D90C;
        temp_s0_2 = (temp_s2->unk4 * 200) - 1400;
        sp30 = (func_global_asm_80612794(temp_s0_2) * temp_s2->unk8) + temp_s3->unk4;
        sp34 = (func_global_asm_80612790(temp_s0_2) * temp_s2->unk8) + temp_s3->unk8;
        current_actor_pointer->y_rotation -= func_global_asm_806CC10C(func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, sp30, sp34) + 0x800, current_actor_pointer->y_rotation) >> 5;
        current_actor_pointer->x_position += func_global_asm_80612794(current_actor_pointer->y_rotation) * sp40;
        current_actor_pointer->z_position += func_global_asm_80612790(current_actor_pointer->y_rotation) * sp40;
        temp_s2->unkC--;
        if (temp_s2->unkC <= 0) {
            temp_s2->unkC = (func_global_asm_806119A0() & 0x3F) + 0xF;
            temp_s2->unk4 += (func_global_asm_806119A0() & 0xF) + 3;
            temp_s2->unk8 = (func_global_asm_806119FC() * 40.0) + 10.0;
        }
        if (D_global_asm_807FBB85 == 1) {
            current_actor_pointer->shadow_opacity = 0xFF;
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            func_global_asm_80614EBC(current_actor_pointer, 0x332);
            current_actor_pointer->control_state = 1;
            playSound(0x16, 0x7FFF, 63.0f, 1.0f, 0, 0);
            var_v0 = 0;
            if (temp_s3->unk28 != 0) {
                temp_s3->unk28--;
            }
            while (var_v0 <= 0) {
                if (temp_s3->unk2A[var_v0] == 0) {
                    temp_s3->unk2A[var_v0] = 0x1E;
                    var_v0 = 1;
                }
                var_v0++;
            }
        }
    } else {
        current_actor_pointer->shadow_opacity -= 4;
        if (current_actor_pointer->shadow_opacity < 5) {
            current_actor_pointer->shadow_opacity = 0;
            func_global_asm_806782C0(current_actor_pointer);
        }
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_bonus_8002CC08.s")
