#include <ultra64.h>
#include "functions.h"


extern s32 *D_807FC7E0;
extern s8 D_80750560[];

extern void func_806ACA88(void);

s32 func_806A80C0(s8 arg0) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (arg0 == D_80750560[i]) {
            return i;
        }
    }
    return 0;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A8158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A9124.s")

void func_8061134C(s32);
extern s32 *D_807FC7E8;

typedef struct TempStruct807FC7F0 {
    s32 unk0;
    s32 unk4;
} TempStruct807FC7F0;

typedef struct TempStruct807FC7F8 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
} TempStruct807FC7F8;

extern TempStruct807FC7F0 D_807FC7F0;
extern TempStruct807FC7F8 D_807FC7F8;

/*
// TODO: Close, doable
// TODO: Regalloc, something iffy with global_properties_bitfield set
void func_806A9124(void) {
    s32 temp_t8;
    s32 i;

    temp_t8 = global_properties_bitfield | 0x40;
    global_properties_bitfield = temp_t8;
    if (!(player_pointer->PaaD->unk1F0 & 0x20000000)) {
        global_properties_bitfield |= 0x10030;
    }
    func_8061130C(D_807FC7F0.unk0);
    D_807FC7F0.unk0 = 0;
    D_807FC7F0.unk4 = 0;
    D_807FC7F8.unk0 = 0;
    D_807FC7F8.unk1 = 0;
    for (i = 0; i < 27; i++) {
        func_8061134C(D_807FC7E0[i]);
    }
    func_8061134C(D_807FC7E0);
    for (i = 0; i < 9; i++) {
        func_8061134C(D_807FC7E8[i]);
    }
    func_8061134C(D_807FC7E8);
}
*/

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A921C.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A92B4.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AA09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AA304.s")

/*
f32 func_80612E40(f32);
? func_806AB4EC(void *, ? *, s32, s32, f32, s32, s32);
? func_806AB808(void *, ?, ?, ?, s32, s32, s32, s32);
s32 func_806C8DE0(?);
s32 func_806F6E58(u8);
s32 func_806FA7A4(?);
s16 func_807319D8(?, s32, u8);
extern ? D_80720C34;
extern ? D_80720D38;
extern ? D_80720D5C;
extern ? D_80720D80;
extern ? D_8072104C;
extern ? D_80721094;
extern ? D_807210EC;
extern ? D_807211D0;
extern ? D_80721474;
extern ? D_80721518;
extern ? D_80750518;
extern s16 D_80750530;
extern ? D_80750560;
extern s16 D_807505A4[];
extern ? D_807505B8;
extern s16 D_807505CA;
extern s8 D_807505D0;
extern ? D_807505D8;
extern u8 D_80755DA8;
extern f32 D_8075AC38;
extern f32 D_8075AC3C;
extern f32 D_8075AC40;
extern f32 D_8075AC44;
extern f32 D_8075AC48;
extern f32 D_8075AC4C;
extern ? D_807FC7F8;
extern s8 D_807FC800;
extern f32 D_807FC804;
extern s8 D_807FC80C;
extern s8 D_807FC80D;
extern u8 D_807FC80F;
extern ? D_807FC818;
extern s16 D_807FC828;
extern s16 D_807FC82A;
extern s16 D_807FC82E;
extern ? D_807FC838;
extern s16 D_807FC83A;
extern s8 D_807FC83C;
extern u16 D_807FCC40;
extern u16 D_807FCC44;
extern u16 D_807FCC46;
extern u16 D_807FCC48;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s8 unk14;
    s8 unk15;
} Struct806AA304_arg0;

// TODO: Good target, progress made but does not yet compile
void func_806AA304(Struct806AA304_arg0 *arg0, s32 arg1) {
    s32 sp8C;
    CharacterProgress *sp84;
    s32 sp7C;
    s32 sp74;
    s8 sp6B;
    ? sp68;
    s8 sp64;
    void *sp5C;
    s32 sp58;
    s32 sp50;
    s32 sp4C;
    s16 *sp3C;
    s16 *sp38;
    s8 *sp34;
    void *var_a1;
    CharacterProgress *temp_t0;
    f32 temp_f6;
    f32 var_f0;
    f32 var_f16;
    s16 *var_v0;
    s16 *var_v1_2;
    s16 *var_v1_3;
    s16 temp_a0;
    s16 temp_t7_2;
    s16 temp_t9_2;
    s32 temp_a2;
    s32 temp_t5;
    s32 temp_t7;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_4;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_t1;
    s8 *temp_v0_6;
    s8 *var_v0_3;
    s8 temp_v1;
    s8 var_s0_7;
    s8 var_v1;
    u16 *temp_s0;
    u16 *var_v0_2;
    u16 temp_t6;
    u16 temp_t9;
    u8 *var_s0_5;
    u8 var_a0;
    u8 var_s0_3;
    u8 var_s0_6;
    void *temp_t4;
    void *temp_v0_4;
    void *temp_v0_5;

    sp8C = current_character_index[0];
    temp_v0 = func_806C8DE0(0);
    temp_t7 = temp_v0 * 4;
    current_character_index[0] = arg0->unk14;
    temp_v1 = arg0->unk15;
    temp_s0 = &D_807FC950->character_progress_as_shorts[0][((temp_t7 - temp_v0) * 0x10) - temp_v0];
    temp_t7_2 = (arg0 + (temp_v1 * 2))->unk8;
    temp_t0 = &D_807FC950->character_progress[arg0->unk14];
    sp7C = temp_t7_2;
    *(&D_807FC7F8 + temp_v1) = 0;
    sp7C = D_80750560[temp_t7_2];
    if (arg1 == 0) {
        D_807FC800 = arg0->unk14;
        D_807FC80D = D_807FC80C;
        arg0->unk10 = 0;
        arg0->unk4 = 0.0f;
        D_807FC804 = 0.0f;
    }
    D_807FC80F = 1;
    switch (arg0->unk12) {
        case 0:
            sp84 = temp_t0;
            current_character_index[0] = sp8C;
            temp_v0_3 = getLevelIndex(D_8076A0AB, 1);
            sp7C = temp_v0_3;
            if (temp_v0_3 >= 9) {
                sp7C = 7;
            }
            if ((sp7C != 7) && (isFlagSet(0x18B, FLAG_TYPE_PERMANENT) != 0)) {
                func_806AB808(arg0, 0x1E, 0x1E, 0xC, -0xA, temp_s0[sp7C].unkA, 1, 0);
                func_806AB4EC(arg0, NULL, 0x1E, 0x1E, 0.75f, 2, 1);
            }
            if (isFlagSet(0x184, FLAG_TYPE_PERMANENT) != 0) {
                func_806AB808(arg0, 0x1E, 0x5A, 0xC, -0xA, D_807FCC44, 1, 1);
                func_806AB4EC(arg0, 4, 0x1E, 0x5A, 0.75f, 2, 1);
            }
            if (temp_s0->unk2 != 0) {
                func_806AB808(arg0, 0x1E, 0x7D, 0xC, -0xA, D_807FCC40, 1, 1);
                func_806AB4EC(arg0, 2, 0x1E, 0x7D, D_8075AC38, 2, 1);
            }
            if (func_806F6E58(current_character_index[0]) != 0) {
                temp_f6 = func_806FA7A4(5);
                var_f16 = D_807FCC46;
                func_806AB808(arg0, 0x1E, 0xA0, 0xC, -0xA, func_80612E40(var_f16 / temp_f6), 1, 1);
                func_806AB4EC(arg0, 5, 0x1E, 0xA0, D_8075AC3C, 2, 1);
            }
            if (isFlagSet(0x18C, FLAG_TYPE_PERMANENT) != 0) {
                func_806AB808(arg0, 0x122, 0x5A, -0xF, -0xA, temp_s0->unk6, 1, 0x80);
                func_806AB4EC(arg0, 1, 0x122, 0x5A, 0.75f, 2, 1);
            }
            if (sp84->instrument & 1) {
                func_806AB808(arg0, 0x122, 0x7D, -0xC, -0xA, sp84->instrument_ammo, 2, 0x81);
                func_806AB4EC(arg0, 7, 0x122, 0x7D, 0.75f, 2, 7);
            }
            if (isFlagSet(0x179, FLAG_TYPE_PERMANENT) != 0) {
                func_806AB808(arg0, 0x122, 0xA0, -0xC, -0xA, D_807FCC48, 1, 0x81);
                func_806AB4EC(arg0, 6, 0x122, 0xA0, D_8075AC40, 2, 1);
            }
            if (D_807FC828 > 0) {
                func_806AB808(arg0, 0x91, 0xBE, 0xF, -0xA, D_807FC828, 1, 0);
                func_806AB4EC(arg0, 9, 0x91, 0xBE, 1.0f, 2, 1);
            }
            current_character_index[0] = arg0->unk14;
            break;
        case 1:
            if (sp7C != 7) {
                var_s0 = sp7C;
                if (sp7C != 8) {
                    func_806AB808(arg0, 0x1E, 0x2A, 0xC, -0xA, temp_t0->coloured_bananas_fed_to_tns[sp7C] + temp_t0->coloured_bananas[sp7C], 2, 0);
                    func_806AB4EC(arg0, NULL, 0x1E, 0x2A, 0.75f, 2, 2);
                } else {
                    var_s0 = 7;
                }
                if (D_807FC82E > 0) {
                    if (sp7C != 8) {
                        temp_v0_4 = D_807FC950->character_progress_as_shorts[current_character_index[0]][sp7C];
                        D_807FC80F = ((temp_v0_4->unk26 + temp_v0_4->unkA) < 75) ^ 1;
                    } else {
                        D_807FC80F = func_80731A04(0x225, var_s0, var_s0, current_character_index[0]);
                    }
                    func_806AB4EC(arg0, 0xA, 0x113, 0x7D, 0.75f, 2, 2);
                    if (func_80731A04(0x225, var_s0, var_s0, current_character_index[0]) != 0) {
                        func_806AB4EC(arg0, &D_80721518, 0x113, 0x7D, D_8075AC44, 2, 0xD);
                    }
                }
            }
            var_v0 = &D_80750530;
            var_s0_2 = 0;
            if (arg1 == 0) {
                do {
                    if (*var_v0 != 0) {
                        var_a1 = D_80750518[var_s0_2];
                    } else {
                        var_a1 = &D_807211D0;
                    }
                    sp3C = var_v0;
                    sp5C = var_a1;
                    func_806AB4EC(arg0, var_a1, var_s0_2, var_s0_2, 0.75f, 2, 0xA);
                    temp_a2 = var_s0_2 + 5;
                    func_806AB4EC(arg0, var_a1, temp_a2, temp_a2, 0.75f, 2, 0xA);
                    var_s0_2 += 1;
                    var_v0 += 1;
                } while (var_s0_2 != 5);
            }
            if (sp7C != 8) {
                func_806AB4EC(arg0, 9, 0x91, 0xCB, 1.0f, 2, 2);
                var_t0 = 0;
                var_s0_3 = 0;
                do {
                    sp74 = var_t0;
                    if (func_80731A04(0x1D5, 0, 7, var_s0_3) != 0) {
                        var_t0 = 1;
                    }
                    var_s0_3 += 1;
                } while (var_s0_3 < 5);
                if (var_t0 != 0) {
                    D_807FC80F = isFlagSet(func_807319D8(0x1D5, sp7C, current_character_index[0]), 0);
                    func_806AB4EC(arg0, 0xC, 0x26, 0x7D, 0.75f, 2, 2);
                    if (isFlagSet(func_807319D8(0x1FD, sp7C, current_character_index[0]), 0) != 0) {
                        func_806AB4EC(arg0, &D_80721518, 0x26, 0x7D, D_8075AC48, 2, 0xD);
                    }
                }
            }
            if (arg1 == 0) {
                arg0->unk10 = D_807505A4[arg0->unk14];
                func_806AB4EC(arg0, &D_80720C34, 0xA0, 0x78, 0.75f, 2, 0);
                if (D_807505D0 > 0) {
                    func_806AB4EC(arg0, &D_80720D80, 0xA0, 0x19, 0.5f, 2, 0xB);
                    func_806AB4EC(arg0, &D_80720D5C, 0xA0, 0x19, 0.5f, 2, 0xC);
                }
            }
            break;
        case 2:
            var_t0_2 = 0;
            sp3C = sp7C * 2;
            var_v0_2 = &D_807FC950->character_progress_as_shorts[0][sp7C];
            var_s0_4 = 0;
            do {
                temp_t6 = var_v0_2->unk26;
                temp_t9 = var_v0_2->unk42;
                var_s0_4 += 1;
                temp_t5 = var_t0_2 + var_v0_2->unkA;
                var_v0_2 += 0x5E;
                var_t0_2 = temp_t5 + temp_t6;
            } while (var_s0_4 < 5);
            var_v1 = 0;
            var_v0_3 = &sp64;
            do {
                var_v0_3 += 1;
                var_v0_3->unk-1 = 0;
            } while (var_v0_3 < &sp68);
            var_s0_5 = &D_80755DA8;
            if (D_80755DA8 != 0xFF) {
                var_a0 = D_80755DA8;
                do {
                    sp6B = var_v1;
                    sp74 = var_t0_2;
                    if (sp7C == getLevelIndex(var_a0, 1)) {
                        temp_a0 = var_s0_5->unk4;
                        if ((temp_a0 >= 0x24D) && (temp_a0 < 0x261) && (var_v1 < 4)) {
                            sp6B = var_v1;
                            sp74 = var_t0_2;
                            temp_t4 = sp + var_v1;
                            var_v1 += 1;
                            temp_t4->unk64 = isFlagSet(temp_a0, FLAG_TYPE_PERMANENT);
                        }
                    }
                    var_a0 = var_s0_5->unk8;
                    var_s0_5 += 8;
                } while (var_a0 != 0xFF);
            }
            if (sp7C != 7) {
                sp58 = sp7C;
                var_s0_6 = 0;
                if (sp3C != 0x10) {
                    func_806AB808(arg0, 0x24, 0x2A, 0xC, -0xA, var_t0_2, 1, 0);
                    func_806AB4EC(arg0, &D_80721474, 0x24, 0x2A, 0.75f, 2, 1);
                } else {
                    sp58 = 7;
                }
                sp38 = &D_807505A4;
                do {
                    if (sp3C != 0x10) {
                        temp_v0_5 = (var_s0_6 * 0x5E) + sp3C + D_807FC950;
                        D_807FC80F = ((temp_v0_5->unk26 + temp_v0_5->unkA) < 0x4B) ^ 1;
                    } else {
                        D_807FC80F = func_80731A04(0x225, sp58, sp58, var_s0_6);
                    }
                    func_806AB4EC(arg0, 0xA, *sp38, 0, 0.75f, 2, 3);
                    if (func_80731A04(0x225, sp58, sp58, var_s0_6) != 0) {
                        func_806AB4EC(arg0, &D_80721518, *sp38, 0, D_8075AC4C, 2, 0xE);
                    }
                    var_s0_6 += 1;
                    sp38 += 2;
                } while (var_s0_6 != 5);
                if (D_807FC82A > 0) {
                    D_807FC80F = isFlagSet(*(&D_807505B8 + sp3C), 0);
                    func_806AB4EC(arg0, &D_807210EC, 0xA0, 0x78, 1.0f, 2, 4);
                }
                if (isFlagSet(0x179, FLAG_TYPE_PERMANENT) != 0) {
                    D_807FC80F = sp64;
                    func_806AB4EC(arg0, &D_80721094, 0x3C, 0x78, 1.0f, 2, 6);
                    D_807FC80F = sp65;
                    func_806AB4EC(arg0, &D_80721094, 0x104, 0x78, 1.0f, 2, 6);
                }
            } else {
                if (*0x807FC82A > 0) {
                    D_807FC80F = isFlagSet(*(&D_807505B8 + sp3C), FLAG_TYPE_PERMANENT);
                    func_806AB4EC(arg0, &D_807210EC, 0xA0, 0x55, 1.0f, 2, 4);
                    D_807FC80F = isFlagSet(D_807505CA, 0);
                    func_806AB4EC(arg0, &D_807210EC, 0xA0, 0x91, 1.0f, 2, 4);
                }
                if (isFlagSet(0x179, FLAG_TYPE_PERMANENT) != 0) {
                    D_807FC80F = sp64;
                    func_806AB4EC(arg0, &D_80721094, 0x3C, 0x5A, 1.0f, 2, 6);
                    D_807FC80F = sp65;
                    func_806AB4EC(arg0, &D_80721094, 0x46, 0x96, 1.0f, 2, 6);
                    D_807FC80F = sp66;
                    func_806AB4EC(arg0, &D_80721094, 0x104, 0x5A, 1.0f, 2, 6);
                    D_807FC80F = sp67;
                    func_806AB4EC(arg0, &D_80721094, 0xFA, 0x96, 1.0f, 2, 6);
                }
            }
            if (sp3C != 0x10) {
                func_806AB4EC(arg0, 9, 0x91, 0xCB, 1.0f, 2, 2);
            }
            if ((arg1 == 0) && (D_807505D0 > 0)) {
                func_806AB4EC(arg0, &D_80720D80, 0xA0, 0x19, 0.5f, 2, 0xB);
                func_806AB4EC(arg0, &D_80720D5C, 0xA0, 0x19, 0.5f, 2, 0xC);
            }
            break;
        case 3:
            D_807FC83C = 0;
            var_v1_2 = &D_807FC828;
            do {
                temp_t9_2 = *var_v1_2;
                var_v1_2 += 2;
                if (temp_t9_2 > 0) {
                    D_807FC83C += 1;
                }
            } while (var_v1_2 < &D_807FC838);
            D_807FC83A = 0x1000 / D_807FC83C;
            var_a2 = 0;
            var_t1 = 0;
            var_v1_3 = 0x807FC828;
            var_s0_7 = 0;
            do {
                if (*var_v1_3 > 0) {
                    temp_v0_6 = var_t1 + &D_807FC818;
                    if (var_s0_7 != 5) {
                        var_f0 = 0.75f;
                        var_t0_3 = 5;
                    } else {
                        var_f0 = 1.0f;
                        var_t0_3 = 8;
                    }
                    sp34 = temp_v0_6;
                    sp3C = var_v1_3;
                    sp50 = var_a2;
                    sp4C = var_t1;
                    func_806AB4EC(arg0, D_807505D8[var_s0_7], var_a2, 0, var_f0, 2, var_t0_3);
                    *temp_v0_6 = var_s0_7;
                    var_t1 += 1;
                    var_a2 += D_807FC83A;
                }
                var_s0_7 += 1;
                var_v1_3 += 2;
            } while (var_s0_7 != 8);
            arg0->unk10 = D_807FC83A * D_807FC80C;
            func_806AB4EC(arg0, &D_80720C34, 0xA0, 0x78, 0.75f, 2, 0);
            break;
    }
    if ((arg1 == 0) && (D_807FC828 > 0)) {
        func_806AB4EC(arg0, &D_80720D38, 0x2D, 0xC8, 1.0f, 2, 1);
        func_806AB4EC(arg0, &D_8072104C, 0x113, 0xC8, 1.0f, 2, 1);
    }
    current_character_index[0] = sp8C;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AB4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AB808.s")

/*
void func_806AB808(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp50;
    s32 sp38;
    s8 sp37;
    u8 sp2C;
    f32 sp24;
    f32 sp20;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f2;
    s32 temp_a3;
    s32 var_a1;
    s8 *temp_v0_2;
    s8 temp_a2;
    s8 temp_v1;
    u8 *var_v1;
    u8 var_a0;
    void *temp_v0;
    void *var_v0;

    sp37 = 0;
    if (arg7 & 0x80) {
        sp37 = 1;
        arg7 &= ~0x80;
    }
    switch (arg7) {
        case 1:
            func_800031E0(&sp2C, &D_8075AB04, arg5);
            break;
        case 2:
            func_800031E0(&sp2C, &D_8075AB0C, arg5);
            arg3 -= func_806FBD5C(1, &sp2C) >> 1;
            break;
        default:
            func_800031E0(&sp2C, &D_8075AB10, arg5);
            break;
    }
    if (sp37 != 0) {
        arg3 -= func_806FBD5C(1, &sp2C);
    }
    D_807FC810 = func_806FBD5C(1, &sp2C);
    temp_f14 = 640.0f - (arg1 * 4);
    temp_v1 = arg0->unk15;
    temp_f16 = 480.0f - (arg2 * 4);
    temp_a2 = D_807FC7F8[temp_v1];
    temp_a3 = D_807FC7F0[temp_v1];
    sp20 = temp_f16;
    sp24 = temp_f14;
    sp50 = temp_a2;
    sp38 = temp_a3;
    temp_f0 = sqrtf((temp_f14 * temp_f14) + (temp_f16 * temp_f16));
    temp_f2 = 1040.0f - temp_f0;
    temp_v0 = temp_a3 + (temp_a2 * 0x18);
    var_a1 = 0;
    var_v1 = &sp2C;
    temp_v0->unk0 = -(temp_f14 / temp_f0) * temp_f2;
    temp_v0->unk4 = -(temp_f16 / temp_f0) * temp_f2;
    temp_v0->unk8 = arg1;
    temp_v0->unkA = arg2;
    temp_v0->unkC = arg3;
    temp_v0->unkE = arg4;
    temp_v0->unk10 = arg6;
    var_v0 = temp_a3 + (temp_a2 * 0x18);
    if (sp2C != 0) {
        var_a0 = *var_v1;
        do {
            var_v0->unk11 = var_a0;
            var_a0 = var_v1->unk1;
            var_a1 += 1;
            var_v0 += 1;
            var_v1 += 1;
        } while (var_a0 != 0);
    }
    (temp_a3 + (temp_a2 * 0x18) + var_a1)->unk11 = 0;
    temp_v0_2 = arg0->unk15 + &D_807FC7F8;
    *temp_v0_2 += 1;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABA6C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABB98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABC94.s")

extern s16 D_80744720[];
extern s8 D_80750530[];
extern s16 D_807505B0[];
extern s16 D_807505B8[];
extern s16 D_807FC828[];
extern s16 D_807FC82A;
extern s16 D_807FC82C;
extern s16 D_807FC82E;
extern s16 D_807FC830;
extern s16 D_807FC832;
extern s16 D_807FC834;
extern s16 D_807FC836;
extern s16 D_807FC838;

void func_806ABE3C(void) {
    CharacterProgress *var_a1;
    s32 var_s0;
    s32 i;
    s32 j;

    for (i = 0; i < 7; i++) {
        D_807FC828[i] = 0;
    }
    var_s0 = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 14; j++) {
            var_s0 += D_807FC950[0].character_progress[i].golden_bananas[j];
        }
    }
    D_807FC828[0] = var_s0;
    var_s0 = 0;
    for (i = 0; i < 8; i++) {
        if (isFlagSet(D_80744710[i], FLAG_TYPE_PERMANENT) != 0) {
            var_s0++;
        }
    }
    D_807FC82C = var_s0;
    D_807FC832 = func_80731AA8(0x24D, 20, FLAG_TYPE_PERMANENT);
    D_807FC82E = func_80731AA8(0x225, 40, FLAG_TYPE_PERMANENT);

    // TODO: Get rid of this empty if statement, I don't like doing this...
    if (var_s0);

    var_s0 = 0;
    for (i = 0; i < 10; i++) {
        if ((D_807505B8[i] >= 0) && (isFlagSet(D_807505B8[i], FLAG_TYPE_PERMANENT) != FALSE)) {
            var_s0++;
        }
    }
    D_807FC82A = var_s0;
    D_807FC834 = isFlagSet(0x84, FLAG_TYPE_PERMANENT);
    D_807FC830 = isFlagSet(0x17B, FLAG_TYPE_PERMANENT);
    D_807FC836 = func_80731AA8(0x1FD, 40, FLAG_TYPE_PERMANENT);
    D_80750530[0] = 1;
    for (i = 1; i < 5; i++) {
        D_80750530[i] = isFlagSet(D_807505B0[i - 1], FLAG_TYPE_PERMANENT);
    }
    D_807FC838 = 1;
}

void func_806AC048(s32 arg0, s32 arg1) {
    func_80703374(arg0, 0, 0, 0, 0x46);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AC07C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ACA88.s")

void func_806ACC00(u8 arg0) {
    func_80677FA8(0x156, 0); // Spawn actor: Try Again Dialog
    D_807FBB44->unk15F = arg0;
    D_807FBB44->unk64 |= 2;
    global_properties_bitfield |= 0x40001;
}

void func_806ACC64() {
    s16 i;

    global_properties_bitfield |= 0x40;
    for (i = 0; i < 3; i++) {
        func_8061134C(D_807FC7E0[i]);
    }
    func_8061134C(D_807FC7E0);
    func_806782C0(current_actor_pointer);
}

void func_806ACCE8(void) {
    s32 i;

    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->unk168 = 0x1E;
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        D_807FC7E0 = malloc(0xC);
        for (i = 0; i < 3; i++) {
            D_807FC7E0[i] = func_8070E750(0x24, i + 0xF, 0);
        }
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
    } else if (current_actor_pointer->control_state == 0) {
        if (D_807ECD58.unk0 & 0x8000) {
            switch (current_actor_pointer->unk15F) {
                case 2:
                    playCutscene(NULL, 0x20, 1);
                    func_806ACC64();
                    break;
                case 3:
                case 4:
                    func_80724994(3, 7, 0x30, 0, 0);
                    func_806ACC64();
                    break;
                default:
                    func_805FF378(current_map, 0);
                    break;
            }
            current_actor_pointer->control_state = 1;
        } else if (D_807ECD58.unk0 & 0x4000) {
            switch (current_actor_pointer->unk15F) {
                case 3:
                case 4:
                    func_80724994(3, 7, 0x3C, 0, 0);
                case 2:
                    func_806ACC64();
                    break;
                case 1:
                    func_805FF544();
                    break;
                default:
                    func_805FF898();
                    break;
            }
            current_actor_pointer->control_state = 1;
        }
    }
    func_8068C350(&func_806ACA88, current_actor_pointer, 5);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ACF10.s")

// TODO: Good target, doable, as long as NOPs don't screw us at end of function
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ACFFC.s")

/*
extern s8 D_8076A105;
extern s8 D_807FC80E;
extern s8 D_807FC8B9;

void func_806ACF10(void);

// TODO: Very close, something wrong with the do while loops?
void func_806ACFFC(void) {
    s32 var_s1;
    s8 temp_v0_2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FC7E0 = malloc(0x10);
        var_s1 = 0;
        do {
            D_807FC7E0[var_s1] = func_8070E750(0x24, var_s1, 0);
            var_s1++;
        } while (var_s1 != 4);
        global_properties_bitfield &= 0xFFFEFFCF;
        func_806291B4(7);
        D_807FC80E = 0;
        current_actor_pointer->control_state_progress = 0;
    }
    temp_v0_2 = character_change_array[D_807FC8B9].unk294->unk3;
    if ((temp_v0_2 >= 0x33) || (temp_v0_2 < -0x32)) {
        if (!(D_807FC80E & 1)) {
            current_actor_pointer->control_state_progress = 1 - current_actor_pointer->control_state_progress;
            D_807FC80E |= 1;
            playSound(0x2A0, 0x7FFF, 63.0f, 1.0f, 0, 0);
        }
    } else {
        D_807FC80E &= 0xFFFE;
    }
    if (character_change_array[D_807FC8B9].new_controller_inputs & A_BUTTON) {
        if (current_actor_pointer->control_state_progress == 0) {
            global_properties_bitfield |= 0x10070;
            var_s1 = 0;
            do {
                func_8061134C(D_807FC7E0[var_s1]);
                var_s1++;
            } while (var_s1 != 0x10);
            func_8061134C(D_807FC7E0);
        } else if (current_actor_pointer->control_state_progress == 1) {
            D_8076A105 = -1;
            func_80714638();
            current_actor_pointer->control_state_progress = 2;
        }
    }
    func_8068C350(&func_806AC048, current_actor_pointer, 1);
    func_8068C350(&func_806ACF10, current_actor_pointer, 5);
}
*/
