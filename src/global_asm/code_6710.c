#include <ultra64.h>
#include "functions.h"


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

extern f32 D_807458F4[];
extern s16 D_80745924[];

typedef struct {
    s32 unk0[12];
} Struct8074593C;

extern Struct8074593C D_8074593C[];

u8 func_80602430(s16 arg0);
u8 func_8060245C(s16 arg0);
void func_80602B60(s32 arg0, u8 arg1);
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

// Libultra stuff osRecvMesg, alUnlink, alLink
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602314.s")

u8 func_80602430(s16 arg0) {
    return ((D_80745658[arg0] & 6) >> 1);
}

u8 func_8060245C(s16 arg0) {
    return (D_80745658[arg0] & 0x78) >> 3;
}

void func_80602488(u8 arg0) {
    D_80745654 = arg0;
}

// Doable, kinda annoying
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602498.s")

void func_806025AC(s32 arg0, s32 arg1, s32 arg2) {
    func_80602498();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806025D4.s")

void playSong(s32 arg0, f32 arg1) {
    u8 i;
    u8 temp_v0;

    temp_v0 = func_8060245C(arg0);
    if (arg0 != 0) {
        s32 temp = D_807458DC[temp_v0];
        if (arg0 != temp || (D_80745658[arg0] & 0x200)) {
            D_807458DC[temp_v0] = arg0;
            D_807458F4[temp_v0] = arg1;
            D_80745924[temp_v0] = 0;
            for (i = 0; i < 4; i++) {
                D_8074593C[i].unk0[temp_v0] = 0;
            }
        }
    }
}

void func_80602B60(s32 arg0, u8 arg1) {
    u8 sp1F;
    u8 temp_v0;

    sp1F = func_8060245C(arg0);
    temp_v0 = func_80602430(arg0);
    if (arg0 != 0) {
        if (arg0 == D_807458DC[sp1F]) {
            D_807458DC[sp1F] = 0;
            D_80745924[sp1F] = 0;
            if (arg1 != 0) {
                if (arg0 == D_80770560[temp_v0]) {
                    alSeqpStop(D_8076BF20[temp_v0]);
                }
            }
        }
    }
}

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

void func_80602CE0(s32 arg0, s32 arg1, u8 arg2) {
    s32 temp_v0;

    temp_v0 = func_8060245C(arg0);
    if (arg0 == D_807458DC[temp_v0]) {
        D_8074593C[arg2].unk0[temp_v0] = arg1;
    }
}

f32 func_80602D4C(s32 arg0) {
    u8 temp_v0 = func_80602430(arg0);

    if (arg0 == D_80770560[temp_v0]) {
        if (func_80737E30(D_8076BF20[temp_v0]) == 1) {
            return D_80770568[temp_v0];
        }
    }
    return 0.0f;
}

void func_80738320(void *arg0, s32 arg1);

void func_80602DC4(s32 arg0, f32 arg1) {
    u8 sp27;
    sp27 = func_80602430(arg0);
    if (arg0 == D_807458DC[func_8060245C(arg0)]) {
        if (arg0 == D_80770560[sp27]) {
            func_80738320(D_8076BF20[sp27], func_807383B0(D_8076BF20[sp27]) * arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80602E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80603340.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80603450.s")

extern u8 D_80745838;
extern ALSeqPlayer *D_8076BF24;

void func_806049CC(s32 arg0) {
    if (D_80745838 != 0) {
        if (arg0 == 0) {
            if (D_80745658[D_80770560[arg0]] & 1) {
                func_807381D8(*D_8076BF20, 0.3f, 1.35f);
            }
        }
        if (D_80770560[arg0] == 0x38) {
            func_80602CE0(0x38, 0x3C00, 1);
        }
        if (D_80770560[arg0] == 0x60) {
            if (current_map == MAP_ENGUARDE_ARENA) {
                func_80602CE0(0x60, 0xE, 1);
            } else {
                func_80602CE0(0x60, 8, 1);
                func_80738170(D_8076BF24, 1, 0x7F);
                func_80738170(D_8076BF24, 2, 0x7F);
            }
            func_80602CE0(0x60, 0x10, 0);
        }
    } else {
        if (arg0 == 0) {
            if (D_80745658[D_80770560[arg0]] & 1) {
                func_807381D8(*D_8076BF20, 0.0f, 1.0f);
            }
        }
        if (D_80770560[arg0] == 0x38) {
            func_80602CE0(0x38, 0x3C00, 0);
        }
        if (D_80770560[arg0] == 0x60) {
            if (current_map == MAP_ENGUARDE_ARENA) {
                func_80602CE0(0x60, 0x1E, 1);
                return;
            }
            func_80602CE0(0x60, 0x10, 1);
            func_80602CE0(0x60, 8, 0);
            func_80738170(D_8076BF24, 1, 0x64);
            func_80738170(D_8076BF24, 2, 0x64);
        }
    }
}

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

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80604CBC.s")

s16 func_80604D70(Actor *arg0, s16 arg1, u8 arg2, s32 arg3, u8 arg4, f32 arg5, s8 arg6);
void func_80605380(s16);

/*
// TODO: Very close, call to func_80605314 is pulling a1 from temp reg instead of stack
void func_80604CBC(Actor *arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, s8 arg7) {
    if (arg0->unk6E[arg4] != -1) {
        if (arg1 != D_80770710[D_80770628[arg0->unk6E[arg4]]]) {
            func_80605314(arg0, arg4);
        } else {
            return;
        }
    }
    arg0->unk6E[arg4] = func_80604D70(arg0, arg1, arg2, arg3, arg5, arg6, arg7);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80604D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605044.s")

void func_80605314(Actor *arg0, u8 arg1) {
    if (arg0->unk6E[arg1] >= 0) {
        func_80605380(arg0->unk6E[arg1]);
        arg0->unk6E[arg1] = -1;
        if (arg1 == 0) {
            arg0->unk72 = 0;
        }
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605380.s")

extern s32 D_807705A0[];
extern s16 D_807705F8[];
extern s16 D_80770658[];
extern s8 D_807706F8[];
extern s16 D_80770740[];

typedef struct {
    s16 unk0[22];
} Struct807707A0;

extern Struct807707A0 D_807707A0[];

/*
// TODO: Close, maybe needs some temp variables?
void func_80605380(s16 arg0) {
    if (--D_80770740[D_80770628[arg0]] != 0) {
        D_80770658[D_807707A0[D_80770628[arg0]].unk0[D_80770740[D_80770628[arg0]]]] = D_80770658[D_807707A0[D_80770628[arg0]].unk0[D_80770658[arg0]]];
        D_807707A0[D_80770628[arg0]].unk0[D_80770658[arg0]] = D_807707A0[D_80770628[arg0]].unk0[D_80770740[D_80770628[arg0]]];
    } else {
        D_80770710[D_80770628[arg0]] = 0;
        D_807706F8[D_80770628[arg0]] = 0;
    }
    if (D_80770740[D_80770628[arg0]] < 0 || D_80770740[D_80770628[arg0]] >= 0x17) {
        func_80732354(9, D_80770740[D_80770628[arg0]], 0, 0);
    }
    D_807707A0[D_80770628[arg0]].unk0[D_80770740[D_80770628[arg0]]] = -1;
    D_807705F8[arg0] = -1;
    D_807705A0[arg0] = 0;
    D_80770628[arg0] = -1;
    D_80770658[arg0] = -1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_80605510.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_806057F8.s")

extern f32 D_80756DFC;

void func_80608528(Actor *arg0, s16 arg1, u8 arg2, s16 arg3, u8 arg4) {
    s32 var_v0;

    if (((arg0->y_position + 20.0f) < arg0->unkAC) && ((arg1 < 0x355) || (arg1 >= 0x35E))) {
        var_v0 = 0x5A;
    } else {
        var_v0 = 0;
    }
    func_806086CC(arg0->x_position, arg0->y_position, arg0->z_position, arg1, arg2, arg3, arg4, 0x4B, D_80756DFC, var_v0);
}

void func_806085DC(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6) {
    func_806086CC(D_807F6000[arg0].x_position, D_807F6000[arg0].y_position, D_807F6000[arg0].z_position, arg1, arg2, arg3, arg4, arg5, arg6, 0);
}

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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_8060A500.s")

extern f64 D_80756FF0;
extern f64 D_80756FF8;

/*
void func_8060A500(void) {
    f32 var_f12;
    f64 temp_f20;
    f64 temp_f22;
    s8 i;

    temp_f22 = D_80756FF0;
    temp_f20 = D_80756FF8;
    for (i = 0; i < 4; i++) {
        if (D_80770598[i] != 0) {
            D_80770568[D_80770598[i]] = D_80770568[D_80770598[i]] + ((D_80770578[i] - D_80770568[D_80770598[i]]) * temp_f20);
            var_f12 = ABS(D_80770578[i] - D_80770568[D_80770598[i]]);
            if (var_f12 < temp_f22) {
                D_80770568[D_80770598[i]] = D_80770578[i];
                D_80770598[i] = 0;
            }
            func_8060A398(i);
        }
    }
}
*/

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
