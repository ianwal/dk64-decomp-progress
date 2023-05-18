#include <ultra64.h>
#include "functions.h"

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80026690.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80026940.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80026CF0.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
} AAD_800271B4;

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

void func_800271B4(s16 arg0, s16 arg1, s16 arg2, u8 arg3, Struct800271B4 *arg4) {
    u8 var_a3;
    AAD_800271B4 *temp_v1;

    var_a3 = arg4->unk28 < ((rand() >> 0xF) % 100) ? 1 : 0;
    if (func_80677FA8(ACTOR_MINIGAME_KREMLING, var_a3 ? 0x32 : 0x33) != 0) {
        temp_v1 = D_807FBB44->additional_actor_data;
        func_80614EBC(D_807FBB44, var_a3 ? 0x211 : 0x20F);
        func_80614D00(D_807FBB44, arg4->unk2C, 0);
        D_807FBB44->x_position = arg0;
        D_807FBB44->y_position = arg1 - 0x19;
        D_807FBB44->z_position = arg2;
        D_807FBB44->y_rotation = 0xC00;
        temp_v1->unk9 = arg3;
        temp_v1->unk8 = var_a3;
        temp_v1->unk0 = arg4;
        arg4->unk0[arg3] = D_807FBB44;
    }
}

typedef struct bonus_struct_0 {
    u8 pad0[0x9];
    u8 unk9;
} BonusStruct0;

void func_80027308(BonusStruct0 *arg0, s32 *arg1) {
    *(arg1 + (arg0->unk9)) = 0;
    func_806782C0(current_actor_pointer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002733C.s")

/*
void func_8071A038();

void func_8002733C(s32 arg0) {
    s16 i;
    s16 var_s2;
    s32 temp_a0;
    void *temp_s1;
    void *temp_s3;

    var_s2 = 0x118;
    for (i = 0; i < 5; i++) {
        temp_s3 = arg0[i];
        temp_a0 = temp_s3->unk4;
        if (temp_a0 != 0) {
            func_80715908(temp_a0);
        }
        temp_s1 = arg0[i];
        temp_s1->unk18 = 0;
        func_8071495C();
        func_807149FC(-1);
        func_80714998(2);
        func_80714944(i * 3);
        func_8071498C(&func_8071A038);
        func_80714950(&temp_s1->unk18);
        temp_s3->unk4 = func_80714CC0(&D_8071FFD4, 1.0f, var_s2, 210.0f, -10.0f);
        var_s2 -= 0x1E;
    }
    playSound(0x3E4, 0x7FFF, 63.0f, 1.0f, 5, 0);
}
*/

void func_806907F0(f32, f32, f32);
void func_80690A28(s32, s32, f32, f32, f32, f32, f32, Actor *);
extern f32 D_8002DD28;

void func_800274A0(f32 arg0, f32 arg1, f32 arg2) {
    playSound(0x59, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
    func_806907F0(current_actor_pointer->x_position, current_actor_pointer->y_position - 10.0f, current_actor_pointer->z_position);
    func_80690A28(0x23, 1, 0.6f, arg0, arg1, arg2, D_8002DD28, current_actor_pointer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80027548.s")

extern f64 D_8002DD30;
extern f64 D_8002DD38;
extern u16 D_807FD63C;

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
} AAD_80027548;

f32 func_80611BB4(f32, f32);

void func_80626F8C(f32, f32, f32, f32*, f32*, s32, f32, s32);
f32 func_8000AC60(f32);

/*
// TODO: Very close, only thing left is the stack
u8 func_80027548(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    s16 i;
    f32 sp50;
    f32 sp4C;
    AAD_80027548 *aaD;
    u8 sp40;

    aaD = current_actor_pointer->additional_actor_data;
    sp40 = 0;
    aaD->unk26 = 1;
    func_80626F8C(arg0, arg1, arg2, &sp50, &sp4C, 0, 4.0f, 0);
    aaD->unk1E = sp50;
    aaD->unk20 = sp4C;
    current_actor_pointer->y_rotation = func_806CC190(current_actor_pointer->y_rotation, func_80665DE0(arg0, arg2, current_actor_pointer->x_position, current_actor_pointer->z_position), 10.0f);
    temp_f0 = current_actor_pointer->x_position - arg0;
    temp_f2 = current_actor_pointer->z_position - arg2;
    current_actor_pointer->z_rotation = func_806CC190(current_actor_pointer->z_rotation, ((func_80611BB4(current_actor_pointer->y_position - arg1, func_8000AC60((temp_f0 * temp_f0) + (temp_f2 * temp_f2))) * 2048.0) / D_8002DD30) + D_8002DD38, 5.0f);
    if ((D_807FD63C & 0xE000) && (current_actor_pointer->control_state == 0)) {
        sp40 = 1;
        if (aaD->unk22 != 0) {
            if ((aaD->unk23 != 0) && (aaD->unk18[0] == 0)) {
                func_800274A0(arg0, arg1, arg2);
                aaD->unk23--;
                func_80715908(aaD->unk4[aaD->unk23]);
                func_8060E7EC(0, 0xFF, 3);
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
            func_8002733C(aaD);
            current_actor_pointer->control_state_progress = 0;
        }
    }
    return sp40;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_800277F8.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct807F5FD4;
extern Struct807F5FD4 D_807F5FD4[]; // TODO: Seems to be a pointer to the struct array

extern f32 D_8002DD40;
extern f32 D_8002DD44;
extern f32 D_8002DD48;
extern f32 D_8002DD4C;
extern f32 D_8002DD50;
void func_80026940();

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
} AAD_800277F8;

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

u8 func_80027548(f32 arg0, f32 arg1, f32 arg2);
u8 func_806FDB8C(s16, s32, s32, f32, f32, f32);
void func_8061C464(Actor*, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);

/*
// TODO: Good progress made, doable
void func_800277F8(void) {
    AAD_800277F8 *aaD;
    Actor *temp_v0_4;
    A178_800277F8 *a178;
    f32 temp_f2;
    f32 var_f12;
    s32 temp_t2;
    Struct807F5FD4 *temp_v0;
    Actor* CAP;

    CAP = current_actor_pointer;
    a178 = CAP->unk178;
    aaD = CAP->additional_actor_data;
    if (!(CAP->object_properties_bitfield & 0x10)) {
        a178->unk25 = func_806FDB8C(1, func_8070E750(0x1A, 2, 1, CAP), 8, 0.0f, 0.0f, 0.0f);
        func_806FDAB8(a178->unk25, 0.0f);
        aaD->unk23 = 5;
        aaD->unk0 = -2;
        aaD->unk22 = 0;
        func_806EB0C0(0x48, NULL, 0);
        func_8061C464(extra_player_info_pointer->unk104, CAP, 4, 0x800, -7, 0, 0x16, 0x2C, 4, 0, D_8002DD40);
        playCutscene(NULL, 0, 1);
        current_actor_pointer->z_rotation = 0x310;
        switch (current_map) {
            case MAP_KREMLING_KOSH_VERY_EASY:
                a178->unk27 = 0x55;
                a178->unk28 = 0x46;
                a178->unk2C = D_8002DD44;
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
                a178->unk2C = D_8002DD48;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x19;
                a178->unk22 = a178->unk20;
                break;
            case MAP_KREMLING_KOSH_HARD:
                a178->unk27 = 0x5C;
                a178->unk28 = 0x50;
                a178->unk2C = D_8002DD4C;
                a178->unk29 = 0x3C;
                a178->unk20 = 0x1C;
                a178->unk22 = a178->unk20;
                break;
        }
    }
    if (aaD->unk0 > 0) {
        aaD->unk22 = 0;
        if ((current_actor_pointer->control_state == 0) && ((D_807FD610->unk30 >= 0x1F) || (D_807FD610->unk31 >= 0x1F))) {
            temp_f2 = ((func_80611BB4(D_807FD610->unk2F, D_807FD610->unk2E) / D_8002DD50) * 8.0) + 5.5;
            var_f12 = temp_f2;
            if (temp_f2 > 9.0f) {
                var_f12 = temp_f2 - 8.0f;
            }
            aaD->unk22 = var_f12;
        }
        temp_v0 = &D_807F5FD4[aaD->unk22];
        if (func_80027548(temp_v0->unk0, temp_v0->unk4, temp_v0->unk8) == 2) {
            aaD->unk25 = 0xFF;
            playSound(0x3BC, 0x7FFF, 63.0f, 1.0f, 0, 0);
        }
        switch (current_actor_pointer->control_state) {
            case 0x0:
                if (current_actor_pointer->unk11C->control_state == 5) {
                    current_actor_pointer->control_state = 0xFF;
                }
                if (a178->unk22 == 0) {
                    func_800264E0(0, 0);
                    playCutscene(NULL, 1, 0x11);
                    current_actor_pointer->control_state = 1;
                } else {
                    if (a178->unk27 < ((rand() >> 0xF) % 100)) {
                        temp_t2 = ((rand() >> 0xF) % 255) % 8;
                        if (a178->unk0[temp_t2] == 0) {
                            temp_v0 = &D_807F5FD4[temp_t2 + 1];
                            func_800271B4(temp_v0->unk0, temp_v0->unk4, temp_v0->unk8, temp_t2, a178);
                        }
                    }
                }
                temp_v0_4 = current_actor_pointer->unk11C;
                if ((temp_v0_4->control_state == 4) && (temp_v0_4->control_state_progress != 0xFF)) {
                    current_actor_pointer->control_state = 0xFE;
                }
                break;
            case 0xFE:
                aaD->unk24 = 0xFF;
                playSound(0x142, 0x7FFF, 63.0f, 1.0f, 0, 0);
                current_actor_pointer->control_state = 0;
                break;
            case 0xFF:
                func_800265C0(0, 5);
                playCutscene(NULL, 1, 0x11);
                current_actor_pointer->control_state = 1;
                break;
        }
    } else if (aaD->unk0 != -2) {
        if (aaD->unk0 != -1) {

        } else if (!(CAP->object_properties_bitfield & 0x02000000)) {
            aaD->unk0 = 1;
            func_806A2B08(CAP->unk11C);
            func_8002733C(aaD);
            playSong(8, 1.0f);
        }
    } else {
        if (is_cutscene_active != 1) {
            aaD->unk0++;
            func_806A2A10(0xDC, 0x2A, a178->unk29);
            func_8070D8C0(CAP, 0, 1);
        }
    }
    if (aaD->unk0 >= -1) {
        func_8068C350(&func_80026940, CAP, 3);
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

// TODO: Similar to above but for TTT
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80027F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_800284C0.s")

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
} AAD_800284C0_unk0;

typedef struct {
    AAD_800284C0_unk0 *unk0; // Used
    u32 unk4;
    u8 unk8; // Used
} AAD_800284C0;

extern u8 D_807FBB85;

void func_8072881C(s32, void*);

/*
// TODO: Extremely close
void func_800284C0(void) {
    AAD_800284C0 *temp_a2;
    AAD_800284C0_unk0 *temp_a3;
    s32 var_a1;

    temp_a2 = current_actor_pointer->additional_actor_data;
    temp_a3 = temp_a2->unk0;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x24;
    }
    func_8072881C(0, &temp_a2->unk4);
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_807FBB85 != 0) {
                if (temp_a2->unk8 != 0) {
                    var_a1 = 2;
                } else {
                    var_a1 = 1;
                }
                if ((temp_a3->unk22 - var_a1) < 0) {
                    temp_a3->unk22 = 0;
                } else {
                    temp_a3->unk22 -= temp_a2->unk8 ? 2 : 1;
                }
                func_806FDAB8(temp_a3->unk25, 3.1415927f);
                if (temp_a2->unk8 != 0) {
                    var_a1 = 0x212;
                } else {
                    var_a1 = 0x210;
                }
                func_80614EBC(current_actor_pointer, var_a1);
                current_actor_pointer->control_state = 1;
                current_actor_pointer->control_state_progress = 0;
                break;
            }
            if (current_actor_pointer->control_state_progress != 0) {
                func_80027308(temp_a2, temp_a3);
            }
            break;
        case 1:
            if (current_actor_pointer->control_state_progress != 0) {
                func_80027308(temp_a2, temp_a3);
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80028648.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
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
} AAD_80028648;

typedef struct {
    Actor* unk0; // Used
    s16 unk4;
    s8 unk6; // Used
    s8 unk7;
    s16 unk8; // Used
} AAD_80028648_2;

/*
// TODO: Pretty close
void func_80028648(ARG0_80028648 *arg0) {
    Actor *temp_s5;
    Actor *temp_v0;
    s32 i;
    u8 temp_v1;
    AAD_80028648 *temp_s2;
    Struct807F5FD4 *temp_s3;
    AAD_80028648_2 *temp_v0_2;

    for (i = 1; i < 7; i++) {
        if (func_80677FA8(ACTOR_SNAKE, 0x15) != 0) {
            temp_s2 = D_807FBB44->additional_actor_data;
            temp_s2->unk0 = current_actor_pointer;
            temp_s2->unk11 = (((rand() >> 0xF) % 32767) % ((arg0->unk1C - arg0->unk1B) + 1)) + arg0->unk1B;
            temp_s3 = &D_807F5FD4[i];
            func_80614EBC(D_807FBB44, 0x1F5);
            D_807FBB44->x_position = temp_s3->unk0;
            D_807FBB44->y_position = temp_s3->unk4;
            D_807FBB44->z_position = temp_s3->unk8;
            D_807FBB44->object_properties_bitfield |= 0x1000;
            D_807FBB44->y_rotation = 0x800;
            arg0[i].unk0 = D_807FBB44;
            if (func_80677FA8(ACTOR_TURTLE, 0x16) != 0) {
                temp_v0_2 = D_807FBB44->additional_actor_data;
                temp_v0_2->unk0 = D_807FBB44;
                temp_v0_2->unk6 = i - 1;
                temp_s2->unk4 = D_807FBB44;
                temp_v0_2->unk8 = -1;
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002881C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80028E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80029364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80029B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_80029E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002A010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002A398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002AAA4.s")

// AnimationState, aaD
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002AD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002AED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002B920.s")

extern f32 D_8002DE40;
extern f64 D_8002DE48;

typedef struct {
    Actor* unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} AAD_8002B920;

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
    s8 unk2C; // TODO: Sus, might be Actor*
    s8 unk2D; // TODO: Sus, might be Actor*
} AAD_8002B920_2;

/*
// TODO: Good progress made, our stack is too big and there's some regalloc issues
void func_8002B920(void) {
    f32 sp40;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f2_2;
    s16 temp_s0_3;
    s32 var_v0;
    AAD_8002B920 *temp_s1;
    AAD_8002B920_2 *temp_s2;
    Actor *temp_t6;
    AAD_8002B920_2 *temp_v1;

    temp_s1 = current_actor_pointer->additional_actor_data;
    temp_t6 = temp_s1->unk0;
    temp_s2 = temp_t6->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80614EBC(current_actor_pointer, 0x32F);
        current_actor_pointer->animation_state->scale_x = D_8002DE40;
        current_actor_pointer->animation_state->scale_y = D_8002DE40;
        current_actor_pointer->animation_state->scale_z = D_8002DE40;
        func_80604CBC(current_actor_pointer, 0x10E, 0x3C, 1, 0, 0xFF, 1.0f, 0);
    }
    if (current_actor_pointer->control_state == 0) {
        if (temp_s2->unk2C == 0) {
            if (temp_s1->unkC > 0) {
                if (temp_s1->unkC == 0x28) {
                    func_8060866C(temp_s2->unk2C, 0x801, 0xFF, 3.0f, 2, 0);
                }
                temp_s1->unkC--;
                sp40 = 5.0f;
            } else {
                sp40 = 3.0f;
            }
            current_actor_pointer->y_rotation -= func_806CC10C(func_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, temp_s1->unk4, temp_s1->unk8) + 0x800, current_actor_pointer->y_rotation) >> 3;
            current_actor_pointer->x_position += func_80612794(current_actor_pointer->y_rotation) * sp40;
            current_actor_pointer->z_position += func_80612790(current_actor_pointer->y_rotation) * sp40;
            temp_s1->unkE--;
            if (temp_s1->unkE <= 0) {
                if (temp_s1->unkC > 0) {
                    temp_s1->unkE = (func_806119A0() & 7) + 0xA;
                } else {
                    temp_s1->unkE = (func_806119A0() & 0x3F) + 0xF;
                }
                temp_s0_3 = func_80665DE0(temp_s2->unk0, temp_s2->unk4, temp_s1->unk4, temp_s1->unk8) + ((func_806119A0() & 7) << 8) + 0x400;
                temp_f10 = func_806119FC() * D_8002DE48;
                temp_s1->unk4 = (func_80612794(temp_s0_3) * temp_f10) + temp_s2->unk0;
                temp_s1->unk8 = (func_80612790(temp_s0_3) * temp_f10) + temp_s2->unk4;
            }
        } else {
            if (temp_s2->unk2C == 0x28) {
                func_8060866C(current_actor_pointer, 0x801, 0xFF, 3.0f, 2, 0);
            }
            current_actor_pointer->y_position = (func_80612794(temp_s2->unk18) * 5.0) + (temp_t6->y_position - 30.0);
        }
    } else {
        current_actor_pointer->shadow_opacity -= 4;
        if (current_actor_pointer->shadow_opacity < 5) {
            current_actor_pointer->shadow_opacity = 0;
            func_806782C0(current_actor_pointer);
        }
    }
    if (temp_t6->control_state == 2) {
        temp_f2_2 = ((func_80612794(temp_t6->y_rotation) * 65.0f) + temp_t6->x_position) - current_actor_pointer->x_position;
        temp_f12 = ((func_80612790(temp_t6->y_rotation) * 65.0f) + temp_t6->z_position) - current_actor_pointer->z_position;
        if (current_actor_pointer->control_state == 0) {
            if ((temp_f2_2 < 12.0) && (temp_f2_2 > -12.0) && ((temp_f12 < 12.0)) && (temp_f12 > -12.0)) {
                func_80605314(current_actor_pointer, 0);
                func_80614EBC(current_actor_pointer, 0x331);
                if (temp_s2->unk2A != 0) {
                    temp_s2->unk2A--;
                }
                var_v0 = 0;
                do {
                    temp_v1 = &((u8*)temp_s2)[var_v0];
                    if (temp_v1->unk2D == 0) {
                        temp_v1->unk2D = 0x1E;
                        var_v0 = 1;
                    }
                    var_v0++;
                } while (var_v0 <= 0);
                current_actor_pointer->control_state = 1;
                func_8060866C(current_actor_pointer, 0x16, 0xFF, 1.0f, 0x14, 0);
                current_actor_pointer->shadow_opacity = 0xFF;
                current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            } else if (((temp_f2_2 * temp_f2_2) + (temp_f12 * temp_f12)) < 900.0f) {
                temp_s1->unkC = 0x3C;
                temp_s1->unkE = 1;
            }
        }
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002BE44.s")

/*
// TODO: what a mess
void func_80614644(Actor *, ActorAnimationState *, s32);
void func_806319C4(Actor *, s32);
extern f32 D_8002DE50;
extern f64 D_8002DE58;
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

void func_8002BE44() {
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
        func_80613C48(temp_a0, 0x5FB, 0, 0);
        current_actor_pointer->animation_state->scale_x =// D_8002DE50;
        current_actor_pointer->animation_state->scale_z =// D_8002DE50;
        current_actor_pointer->animation_state->scale_y = D_8002DE50;
    }
    current_actor_pointer->x_position = temp_a0->x_position;
    current_actor_pointer->y_position = temp_a0->y_position - D_8002DE58;
    current_actor_pointer->z_position = temp_a0->z_position;
    if (sp24 && temp_t8) {
        phi_a1 = temp_t8->unk10;
        if (phi_a1 == 0x5FD) {
            phi_a1 = 0x5FE;
        }
        if (phi_a1 != sp24->unk10) {
            func_80613C48(current_actor_pointer, phi_a1, 0, 0);
        }
        func_80614644(current_actor_pointer, sp24, temp_t8->unk4);
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002BF98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002C8EC.s")

extern f32 D_8002D90C;
extern u8 D_807FBB85;

typedef struct {
    Actor* unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    s16 unkC;
} AAD_8002C8EC;

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
    s8 unk2A;
    s8 unk2B;
    s32 unk2C;
} AAD_8002C8EC_2;

/*
// TODO: Close, our stack is too small, and regalloc
void func_8002C8EC(void) {
    f32 sp40;
    f32 sp30;
    s16 temp_s0_2;
    s32 var_v0;
    AAD_8002C8EC *temp_s2;
    AAD_8002C8EC_2 *temp_s3;
    AAD_8002C8EC_2 *temp_v1_2;

    temp_s2 = current_actor_pointer->additional_actor_data;
    temp_s3 = temp_s2->unk0->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_80614EBC(current_actor_pointer, 0x232);
        current_actor_pointer->noclip_byte = 0x24;
        current_actor_pointer->animation_state->scale_x = 0.25f;
        current_actor_pointer->animation_state->scale_y = 0.25f;
        current_actor_pointer->animation_state->scale_z = 0.25f;
    }
    if (current_actor_pointer->control_state == 0) {
        sp40 = D_8002D90C;
        temp_s0_2 = (temp_s2->unk4 * 200) - 1400;
        sp30 = (func_80612794(temp_s0_2) * temp_s2->unk8) + temp_s3->unk4;
        current_actor_pointer->y_rotation -= func_806CC10C(func_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, sp30, (func_80612790(temp_s0_2) * temp_s2->unk8) + temp_s3->unk8) + 0x800, current_actor_pointer->y_rotation) >> 5;
        current_actor_pointer->x_position += func_80612794(current_actor_pointer->y_rotation) * sp40;
        current_actor_pointer->z_position += func_80612790(current_actor_pointer->y_rotation) * sp40;
        temp_s2->unkC--;
        if (temp_s2->unkC <= 0) {
            temp_s2->unkC = (func_806119A0() & 0x3F) + 0xF;
            temp_s2->unk4 += (func_806119A0() & 0xF) + 3;
            temp_s2->unk8 = (func_806119FC() * 40.0) + 10.0;
        }
        if (D_807FBB85 == 1) {
            current_actor_pointer->shadow_opacity = 0xFF;
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            func_80614EBC(current_actor_pointer, 0x332);
            current_actor_pointer->control_state = 1;
            playSound(0x16, 0x7FFF, 63.0f, 1.0f, 0, 0);
            var_v0 = 0;
            if (temp_s3->unk28 != 0) {
                temp_s3->unk28--;
            }
            while (var_v0 <= 0) {
                // TODO: What's going on here?
                temp_v1_2 = &((u8*)temp_s3)[var_v0];
                if (temp_v1_2->unk2A == 0) {
                    temp_v1_2->unk2A = 0x1E;
                    var_v0 = 1;
                }
                var_v0++;
            }
        }
    } else {
        current_actor_pointer->shadow_opacity -= 4;
        if (current_actor_pointer->shadow_opacity < 5) {
            current_actor_pointer->shadow_opacity = 0;
            func_806782C0(current_actor_pointer);
        }
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_2690/func_8002CC08.s")
