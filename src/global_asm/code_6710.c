#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s8 D_807452CC;
extern u16 D_80745658[];
extern u8 D_80745654;
extern f32 D_807457B8[];
extern s16 D_807458DC[]; // music_track_channels
extern OSThread D_8076D4E8;
extern f32 D_80770578[];
extern u8 D_80770598[];

extern u8 D_80770560[];
extern f32 D_80770568[];
extern s16 D_80770628[];
extern s16 D_80770710[];
extern f32 D_80770B68[];
extern f32 D_80770BC0[];
extern f32 D_80770C18[];
extern f32 D_80770C70[];
extern u8 D_80770CE0[];

extern s32 func_80737E30(s32, u8);

u8 func_80602430(s16 arg0);
u8 func_8060245C(s16 arg0);
void func_80602B60(s16 arg0, s32 arg1);
void func_8060A60C(s32 arg0, f32 arg1);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80601A10.s")

void func_80601CC0(void) {
    D_807452CC = TRUE;
    osStartThread(&D_8076D4E8);
}

void func_80601CF0(s32 arg0) {
    if (D_807452CC) {
        osStopThread(&D_8076D4E8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80601D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80601EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602104.s")

extern s32 D_807454E8;

/*
void func_80602104(s32 arg0) {
    if (((osAiGetLength() >> 2) == 0) && (D_807454E8 == 0)) {
        D_807454E8 = 0;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806022DC.s")

/*
void *func_806022DC(void *arg0) {
    if (D_80770188.unk0 == 0) {
        D_80770188.unk4 = 0;
        D_80770188.unk8 = &D_8076FE68;
        D_80770188.unk0 = (u8)1U;
    }
    *arg0 = &D_80770188;
    return &func_80602144;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602430.s")

u8 func_8060245C(s16 arg0) {
    return (D_80745658[arg0] & 0x78) >> 3;
}

void func_80602488(u8 arg0) {
    D_80745654 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602498.s")

void func_806025AC(s32 arg0, s32 arg1, s32 arg2) {
    func_80602498();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806025D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/playSong.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602B60.s")

void func_80602C0C(void) {
    u8 i;
    for (i = 0; i < 0xC; i++) {
        if (D_807458DC[i] != 0) {
            func_80602B60(D_807458DC[i], 1); // playMusic()?
        }
    }
}

void func_80602C6C(s32 arg0, f32 arg1) {
    u8 sp1F;

    sp1F = func_80602430(arg0);
    if ((arg0 == D_807458DC[func_8060245C(arg0)]) && (arg0 == D_80770560[sp1F])) {
        func_8060A60C(sp1F, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602CE0.s")

extern s32 D_8074593C[];

/*
void func_80602CE0(s32 arg0, s32 arg1, u8 arg2) {
    s32 temp_v0;

    temp_v0 = func_8060245C(arg0);
    if (arg0 == D_807458DC[temp_v0]) {
        D_8074593C[temp_v0 + arg2 * 0xC] = arg1;
    }
}
*/

f32 func_80602D4C(s32 arg0) {
    u8 temp_v0 = func_80602430(arg0);

    if (arg0 == D_80770560[temp_v0]) {
        if (func_80737E30(D_8076BF20[temp_v0], temp_v0) == 1) {
            return D_80770568[temp_v0];
        }
    }
    return 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80603340.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80603450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806049CC.s")

void func_80604BE8(u8 arg0, f32 arg1, f32 arg2) {
    if (arg0 != -1) {
        if (arg2 == 0.0f) {
            D_80770C18[D_80770628[arg0]] = arg1;
            D_80770C70[D_80770628[arg0]] = arg1;
        } else {
            D_80770B68[D_80770628[arg0]] = arg1;
        }
        D_80770BC0[D_80770628[arg0]] = arg2;
    }
}

void func_80604C80(u8 arg0, u8 arg1) {
    if (arg0 != -1) {
        D_80770CE0[D_80770628[arg0]] = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80604CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80604D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605314.s")

void func_80605380(s16);

/*
// TODO: Very close
void func_80605314(Actor *arg0, u8 arg1) {
    if (arg0[arg1].unk6E >= 0) {
        func_80605380(arg0[arg1].unk6E);
        arg0[arg1].unk6E = -1;
        if (arg1 == 0) {
            arg0->unk72 = 0;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806057F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80608528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806085DC.s")

void func_8060956C(f32, f32, f32, s16, s32, f32, s32, s32);

void func_8060866C(Actor *arg0, s16 arg1, u8 arg2, f32 arg3, u8 arg4, u8 arg5) {
    func_8060956C(arg0->x_position, arg0->y_position, arg0->z_position, arg1, arg2, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806086CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80608DA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/playSound.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_8060956C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80609B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_8060A1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_8060A398.s")

void func_8060A4D0(s32 arg0, f32 arg1) {
    D_807457B8[arg0] = arg1;
    func_8060A398(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_8060A500.s")

void func_8060A60C(s32 arg0, f32 arg1) {
    D_80770578[arg0] = arg1;
    D_80770598[arg0] = 1;
}

void func_8060A634(s32 arg0, f32 arg1) {
    D_80770578[arg0] = arg1;
    D_80770568[arg0] = arg1;
    func_8060A398(arg0);
}

extern s32 D_80770588; // TODO: f32?

void func_8060A1B0(s32, u8, s32);

void func_8060A670(s32 arg0, u8 arg1) {
    func_8060A1B0(arg0, arg1, D_80770588);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_8060A6A0.s")
