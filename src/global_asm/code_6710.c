#include <ultra64.h>
#include "functions.h"


extern s8 D_global_asm_807452CC;
extern u16 D_global_asm_80745658[];
extern u8 D_global_asm_80745654;
extern f32 D_global_asm_807457B8[];
extern s16 D_global_asm_807458DC[]; // music_track_channels
extern OSThread D_global_asm_8076D4E8;
extern f32 D_global_asm_80770578[];
extern u8 D_global_asm_80770598[];

extern u8 D_global_asm_80770560[];
extern f32 D_global_asm_80770568[];
extern s16 D_global_asm_80770628[];
extern s16 D_80770710[];
extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];
extern f32 D_global_asm_80770C18[];
extern f32 D_global_asm_80770C70[];
extern u8 D_global_asm_80770CE0[];

extern f32 D_global_asm_807458F4[];
extern s16 D_global_asm_80745924[];

typedef struct {
    s32 unk0[12];
} Struct8074593C;

extern Struct8074593C D_global_asm_8074593C[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80601A10.s")

void func_global_asm_80601CC0(void) {
    D_global_asm_807452CC = TRUE;
    osStartThread(&D_global_asm_8076D4E8);
}

void func_global_asm_80601CF0(s32 arg0) {
    if (D_global_asm_807452CC) {
        osStopThread(&D_global_asm_8076D4E8);
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80601D24.s")

extern u32 D_global_asm_807452C0;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8[1];
} Struct8076D4D0;
extern Struct8076D4D0 D_global_asm_8076D4D0;
extern OSMesgQueue D_global_asm_8076D698;
extern OSMesgQueue D_global_asm_8076D6D0;
extern N_ALGlobals D_global_asm_8076D708;
extern s32 D_global_asm_8076D4C0;

void func_global_asm_80602104(s32 arg0);
void func_global_asm_8060A500(void);
s32 func_global_asm_80601EE4(void *arg0, void *arg1);

/*
void func_global_asm_80601D24(s32 arg0) {
    s32 temp_v0;
    s32 sp58;
    s32 var_s0;
    s32 found;
    s32 var_s6;

    found = 0;
    var_s0 = 0;
    var_s6 = 1;
    func_global_asm_8060ED6C(&D_global_asm_80767A40, &D_global_asm_8076D4C0, &D_global_asm_8076D698, 2, 2);
    osSendMesg(&D_global_asm_8076D698, 5, 0);
    while (!found) {
        osRecvMesg(&D_global_asm_8076D698, &sp58, 1);
        switch (sp58) {
            case 5:
                if (D_global_asm_80767A40.unk264) {
                    osSendMesg(&D_global_asm_80767A40, 0x29E, 1);
                }
                func_global_asm_80601EE4(D_global_asm_8076D4D0.unk8[D_global_asm_807452C0 % 3], var_s0);
                temp_v0 = var_s6 != 0;
                var_s6 = 0;
                var_s0 = D_global_asm_8076D4D0.unk8[(D_global_asm_807452C0 + 1) % 3];
                if (!temp_v0) {
                    osRecvMesg(&D_global_asm_8076D6D0, &sp58, 1);
                    func_global_asm_80602104(var_s0);
                }
                func_global_asm_8060A500();
                break;
            case 10:
                found = TRUE;
                break;
        }
    }
    n_alClose(&D_global_asm_8076D708);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80601EE4.s")

// rodata?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80602104.s")

extern s32 D_global_asm_807454E8;

/*
void func_global_asm_80602104(s32 arg0) {
    if (!(osAiGetLength() >> 2)) {
        if (!D_global_asm_807454E8) {
            D_global_asm_807454E8 = 0;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80602144.s")

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
} Struct80770188;

int func_global_asm_80602144();

extern Struct80770188 D_global_asm_80770188;
extern s32 D_global_asm_8076FE68;

void *func_global_asm_806022DC(s32 *arg0) {
    if (D_global_asm_80770188.unk0 == 0) {
        D_global_asm_80770188.unk4 = 0;
        D_global_asm_80770188.unk8 = &D_global_asm_8076FE68;
        D_global_asm_80770188.unk0 = 1;
    }
    *arg0 = &D_global_asm_80770188;
    return func_global_asm_80602144;
}

// Libultra stuff osRecvMesg, alUnlink, alLink
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80602314.s")

/*
extern OSMesgQueue D_807704A8;
extern u32 D_global_asm_807452C0;
extern u32 D_global_asm_807452C4;
extern ? D_global_asm_80770188;

void func_global_asm_80602314(void) {
    void *sp40;
    ALLink *temp_v0;
    ALLink *var_s0_2;
    u32 var_s0;

    sp40 = NULL;
    var_s0 = 0;
    if (D_global_asm_807452C4 != 0) {
        do {
            osRecvMesg(&D_807704A8, &sp40, 0);
            var_s0 += 1;
        } while (var_s0 < D_global_asm_807452C4);
    }
    var_s0_2 = D_global_asm_80770188.unk4;
    if (var_s0_2 != NULL) {
        do {
            temp_v0 = var_s0_2->next;
            if ((var_s0_2->unkC + 1) < D_global_asm_807452C0) {
                if (var_s0_2 == D_global_asm_80770188.unk4) {
                    D_global_asm_80770188.unk4 = temp_v0;
                }
                alUnlink(var_s0_2);
                if (D_global_asm_80770188.unk8 != NULL) {
                    alLink(var_s0_2, D_global_asm_80770188.unk8);
                } else {
                    D_global_asm_80770188.unk8 = var_s0_2;
                    var_s0_2->next = NULL;
                    var_s0_2->prev = NULL;
                }
            }
            var_s0_2 = temp_v0;
        } while (temp_v0 != NULL);
    }
    D_global_asm_807452C4 = 0;
    D_global_asm_807452C0 += 1;
}
*/

u8 func_global_asm_80602430(s16 arg0) {
    return ((D_global_asm_80745658[arg0] & 6) >> 1);
}

u8 func_global_asm_8060245C(s16 arg0) {
    return (D_global_asm_80745658[arg0] & 0x78) >> 3;
}

void func_global_asm_80602488(u8 arg0) {
    D_global_asm_80745654 = arg0;
}

typedef struct {
    u8 unk0;
    u8 unk1;
} Struct80770DD8;

extern Struct80770DD8 D_80770DD8;
extern s8 D_global_asm_80745650;

typedef struct {
    s16 unk0; // map
    s16 unk2;
    s16 unk4; // song index
    s16 unk6;
    u8 unk8;
    u8 unk9;
} Struct807459FC;

extern Struct807459FC D_global_asm_807459FC[];
extern u8 D_global_asm_80770DC9;

void func_global_asm_80602498(void) {
    s16 temp_v0;
    s16 max;
    u8 i;

    D_global_asm_80745650 = 1;
    if (D_global_asm_80745654 != 0) {
        if (D_80770DD8.unk1 == 0xFF) {
            D_80770DD8.unk1 = 0;
        }
    } else {
        max = 0x1D;
        temp_v0 = func_global_asm_806531B8(character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z, 0);
        for (i = 0; i < max; i++) {
            if ((current_map == D_global_asm_807459FC[i].unk0) && (temp_v0 == D_global_asm_807459FC[i].unk2)) {
                D_global_asm_80770DC9 = D_global_asm_807459FC[i].unk8;
                playSong(D_global_asm_807459FC[i].unk4, 1.0f);
                if (D_global_asm_807459FC[i].unk6 != 0) {
                    D_80770DD8.unk1 = D_global_asm_807459FC[i].unk6;
                }
                return;
            }
        }
        D_80770DD8.unk1 = 0xFF;
        return;
    }
}

void func_global_asm_806025AC(s32 arg0, s32 arg1, s32 arg2) {
    func_global_asm_80602498();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_806025D4.s")

void playSong(s32 arg0, f32 arg1) {
    u8 i;
    u8 temp_v0;

    temp_v0 = func_global_asm_8060245C(arg0);
    if (arg0 != 0) {
        s32 temp = D_global_asm_807458DC[temp_v0];
        if (arg0 != temp || (D_global_asm_80745658[arg0] & 0x200)) {
            D_global_asm_807458DC[temp_v0] = arg0;
            D_global_asm_807458F4[temp_v0] = arg1;
            D_global_asm_80745924[temp_v0] = 0;
            for (i = 0; i < 4; i++) {
                D_global_asm_8074593C[i].unk0[temp_v0] = 0;
            }
        }
    }
}

void func_global_asm_80602B60(s32 arg0, u8 arg1) {
    u8 sp1F;
    u8 temp_v0;

    sp1F = func_global_asm_8060245C(arg0);
    temp_v0 = func_global_asm_80602430(arg0);
    if (arg0 != 0) {
        if (arg0 == D_global_asm_807458DC[sp1F]) {
            D_global_asm_807458DC[sp1F] = 0;
            D_global_asm_80745924[sp1F] = 0;
            if (arg1 != 0) {
                if (arg0 == D_global_asm_80770560[temp_v0]) {
                    alSeqpStop(D_global_asm_8076BF20[temp_v0]);
                }
            }
        }
    }
}

void func_global_asm_80602C0C(void) {
    u8 i;
    for (i = 0; i < 0xC; i++) {
        if (D_global_asm_807458DC[i] != 0) {
            func_global_asm_80602B60(D_global_asm_807458DC[i], 1); // playMusic()?
        }
    }
}

void func_global_asm_80602C6C(s32 arg0, f32 arg1) {
    u8 sp1F;

    sp1F = func_global_asm_80602430(arg0);
    if ((arg0 == D_global_asm_807458DC[func_global_asm_8060245C(arg0)]) && (arg0 == D_global_asm_80770560[sp1F])) {
        func_global_asm_8060A60C(sp1F, arg1);
    }
}

void func_global_asm_80602CE0(s32 arg0, s32 arg1, u8 arg2) {
    s32 temp_v0;

    temp_v0 = func_global_asm_8060245C(arg0);
    if (arg0 == D_global_asm_807458DC[temp_v0]) {
        D_global_asm_8074593C[arg2].unk0[temp_v0] = arg1;
    }
}

f32 func_global_asm_80602D4C(s32 arg0) {
    u8 temp_v0 = func_global_asm_80602430(arg0);

    if (arg0 == D_global_asm_80770560[temp_v0]) {
        if (func_global_asm_80737E30(D_global_asm_8076BF20[temp_v0]) == 1) {
            return D_global_asm_80770568[temp_v0];
        }
    }
    return 0.0f;
}

void func_global_asm_80738320(void *arg0, s32 arg1);

void func_global_asm_80602DC4(s32 arg0, f32 arg1) {
    u8 sp27;
    sp27 = func_global_asm_80602430(arg0);
    if (arg0 == D_global_asm_807458DC[func_global_asm_8060245C(arg0)]) {
        if (arg0 == D_global_asm_80770560[sp27]) {
            func_global_asm_80738320(D_global_asm_8076BF20[sp27], func_global_asm_807383B0(D_global_asm_8076BF20[sp27]) * arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80602E6C.s")

extern f32 D_80770DDC;
extern f32 D_80770DE0;
extern f32 D_80770DE4;
extern f64 D_global_asm_807567B8;
extern f64 D_global_asm_807567C0;
extern f32 D_global_asm_807567C8;
extern f32 D_global_asm_807567CC;
extern f64 D_global_asm_807567D0;
extern f64 D_global_asm_807567D8;
extern f32 D_global_asm_807567E0;
extern f32 D_global_asm_807567E4;
extern f64 D_global_asm_807567E8;
extern f64 D_global_asm_807567F0;
extern f64 D_global_asm_807567F8;
extern f64 D_global_asm_80756800;
extern f64 D_global_asm_80756808;
extern f64 D_global_asm_80756810;
extern f32 D_global_asm_80756818;

f32 func_global_asm_80602E6C(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, f32 arg5);

/*
f32 func_global_asm_80602E6C(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, f32 arg5) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sp18;
    f32 temp_f16_3;
    f32 temp_f2_4;
    f64 temp_f0;
    f64 temp_f8;
    f64 var_f0;

    sp18 = 0.0f;
    dx = character_change_array->look_at_eye_x - arg0;
    dy = character_change_array->look_at_eye_y - arg1;
    dz = character_change_array->look_at_eye_z - arg2;
    if (D_global_asm_807567B8 < arg5) {
        var_f0 = arg5 - D_global_asm_807567B8;
    } else {
        var_f0 = -(arg5 - D_global_asm_807567B8);
    }
    if ((var_f0 < D_global_asm_807567C0) && (dy < 0.0f)) {
        dy *= 20.0f;
    }
    D_80770DE4 = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    if (D_global_asm_807567B8 <= arg5) {
        dz = character_change_array->look_at_at_z - character_change_array->look_at_eye_z;
        dx = character_change_array->look_at_at_x - character_change_array->look_at_eye_x;
        sp18 = func_global_asm_80665E48(character_change_array->look_at_eye_y, 0.0f, character_change_array->look_at_at_y, sqrtf(SQ(dz) + SQ(dx)));
        dz = arg2 - character_change_array->look_at_eye_z;
        dx = arg0 - character_change_array->look_at_eye_x;
        D_80770DDC = func_global_asm_80665E48(character_change_array->look_at_eye_y, 0.0f, arg1, sqrtf(SQ(dz) + SQ(dx))) - sp18;
        if (D_80770DDC < 0.0f) {
            D_80770DDC += D_global_asm_807567C8;
        }
        if (D_global_asm_807567CC < D_80770DDC) {
            temp_f0 = D_80770DDC;
            if (temp_f0 < D_global_asm_807567D0) {
                D_80770DE4 *= 1.0f - (func_global_asm_80612D1C(((temp_f0 * 4.0) / 7.0) + D_global_asm_807567D8) * 4.0f);
            }
        }
    }
    D_80770DDC = func_global_asm_80665E48(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, arg0, arg2) - character_change_array->unk2C4;
    if (D_80770DDC < 0.0f) {
        D_80770DDC += D_global_asm_807567E0;
    }
    if (D_global_asm_807567E4 < D_80770DDC) {
        if ((D_80770DDC < D_global_asm_807567E8) && (sp18 < 4.0)) {
            D_80770DE4 *= 1.0f - (func_global_asm_80612D1C(((2.0 * D_80770DDC) / 3.0) + D_global_asm_807567F0) * arg5);
        }
    }
    if (D_80770DE4 < 1.0f) {
        D_80770DE4 = 1.0f;
    }
    temp_f2_4 = arg4 * 4000;
    temp_f8 = (temp_f2_4 / sqrtf(D_80770DE4)) - ((temp_f2_4 * D_global_asm_807567F8) - D_global_asm_80756800);
    temp_f16_3 = temp_f8 * arg3 * D_global_asm_80756808;
    if (temp_f16_3 < 10.0f) {
        return 0.0f;
    }
    D_80770DE0 = func_global_asm_80612D10(D_80770DDC);
    D_80770DDC = (1.0f - func_global_asm_80612D1C(D_80770DDC)) * D_global_asm_80756810;
    if (temp_f16_3 < 10.0f) {
        return 0.0f;
    }
    if (D_global_asm_80756818 < temp_f16_3) {
        temp_f16_3 = D_global_asm_80756818;
    }
    return temp_f16_3;
}
*/

extern f32 D_80770DDC;
extern f32 D_80770DE0;
extern f32 D_80770DE8;
extern f32 D_80770DEC;
extern f32 D_80770DF0;
extern f32 D_80770DF4;
extern f64 D_global_asm_80756820;

f32 func_global_asm_80603340(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, f32 arg5) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_global_asm_80602E6C(arg0, arg1, arg2, arg3, arg4, arg5);
    if (temp_f0 < 10.0f) {
        return 0.0f;
    }
    temp_f2 = D_80770DDC * D_global_asm_80756820;
    D_80770DE8 += temp_f0 * temp_f2;
    D_80770DEC += temp_f0 * (1.0f - temp_f2);
    if (D_80770DE0 > 0.0f) {
        D_80770DF0 += temp_f0 * D_80770DE0;
    }
    if (D_80770DE0 < 0.0f) {
        D_80770DF4 -= temp_f0 * D_80770DE0;
    }
    return temp_f0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80603450.s")

extern u8 D_global_asm_80745838;
extern ALSeqPlayer *D_global_asm_8076BF24;

void func_global_asm_806049CC(s32 arg0) {
    if (D_global_asm_80745838 != 0) {
        if (arg0 == 0) {
            if (D_global_asm_80745658[D_global_asm_80770560[arg0]] & 1) {
                func_global_asm_807381D8(*D_global_asm_8076BF20, 0.3f, 1.35f);
            }
        }
        if (D_global_asm_80770560[arg0] == 0x38) {
            func_global_asm_80602CE0(0x38, 0x3C00, 1);
        }
        if (D_global_asm_80770560[arg0] == 0x60) {
            if (current_map == MAP_ENGUARDE_ARENA) {
                func_global_asm_80602CE0(0x60, 0xE, 1);
            } else {
                func_global_asm_80602CE0(0x60, 8, 1);
                func_global_asm_80738170(D_global_asm_8076BF24, 1, 0x7F);
                func_global_asm_80738170(D_global_asm_8076BF24, 2, 0x7F);
            }
            func_global_asm_80602CE0(0x60, 0x10, 0);
        }
    } else {
        if (arg0 == 0) {
            if (D_global_asm_80745658[D_global_asm_80770560[arg0]] & 1) {
                func_global_asm_807381D8(*D_global_asm_8076BF20, 0.0f, 1.0f);
            }
        }
        if (D_global_asm_80770560[arg0] == 0x38) {
            func_global_asm_80602CE0(0x38, 0x3C00, 0);
        }
        if (D_global_asm_80770560[arg0] == 0x60) {
            if (current_map == MAP_ENGUARDE_ARENA) {
                func_global_asm_80602CE0(0x60, 0x1E, 1);
                return;
            }
            func_global_asm_80602CE0(0x60, 0x10, 1);
            func_global_asm_80602CE0(0x60, 8, 0);
            func_global_asm_80738170(D_global_asm_8076BF24, 1, 0x64);
            func_global_asm_80738170(D_global_asm_8076BF24, 2, 0x64);
        }
    }
}

void func_global_asm_80604BE8(u8 arg0, f32 arg1, f32 arg2) {
    if (arg0 != -1) {
        if (arg2 == 0.0f) {
            D_global_asm_80770C18[D_global_asm_80770628[arg0]] = arg1;
            D_global_asm_80770C70[D_global_asm_80770628[arg0]] = arg1;
        } else {
            D_global_asm_80770B68[D_global_asm_80770628[arg0]] = arg1;
        }
        D_global_asm_80770BC0[D_global_asm_80770628[arg0]] = arg2;
    }
}

void func_global_asm_80604C80(u8 arg0, u8 arg1) {
    if (arg0 != -1) {
        D_global_asm_80770CE0[D_global_asm_80770628[arg0]] = arg1;
    }
}

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80604CBC.s")

s16 func_global_asm_80604D70(Actor *arg0, s16 arg1, u8 arg2, s32 arg3, u8 arg4, f32 arg5, s8 arg6);

/*
// TODO: Very close, call to func_global_asm_80605314 is pulling a1 from temp reg instead of stack
void func_global_asm_80604CBC(Actor *arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, s8 arg7) {
    if (arg0->unk6E[arg4] != -1) {
        if (arg1 != D_80770710[D_global_asm_80770628[arg0->unk6E[arg4]]]) {
            func_global_asm_80605314(arg0, arg4);
        } else {
            return;
        }
    }
    arg0->unk6E[arg4] = func_global_asm_80604D70(arg0, arg1, arg2, arg3, arg5, arg6, arg7);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80604D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80605044.s")

void func_global_asm_80605314(Actor *arg0, u8 arg1) {
    if (arg0->unk6E[arg1] >= 0) {
        func_global_asm_80605380(arg0->unk6E[arg1]);
        arg0->unk6E[arg1] = -1;
        if (arg1 == 0) {
            arg0->unk72 = 0;
        }
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80605380.s")

extern s32 D_global_asm_807705A0[];
extern s16 D_global_asm_807705F8[];
extern s16 D_global_asm_80770658[];
extern s8 D_global_asm_807706F8[];
extern s16 D_global_asm_80770740[];

typedef struct {
    s16 unk0[22];
} Struct807707A0;

extern Struct807707A0 D_global_asm_807707A0[];

/*
// TODO: Close, maybe needs some temp variables?
void func_global_asm_80605380(s16 arg0) {
    if (--D_global_asm_80770740[D_global_asm_80770628[arg0]] != 0) {
        D_global_asm_80770658[D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770740[D_global_asm_80770628[arg0]]]] = D_global_asm_80770658[D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770658[arg0]]];
        D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770658[arg0]] = D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770740[D_global_asm_80770628[arg0]]];
    } else {
        D_80770710[D_global_asm_80770628[arg0]] = 0;
        D_global_asm_807706F8[D_global_asm_80770628[arg0]] = 0;
    }
    if (D_global_asm_80770740[D_global_asm_80770628[arg0]] < 0 || D_global_asm_80770740[D_global_asm_80770628[arg0]] >= 0x17) {
        s32 temp = D_global_asm_80770740[D_global_asm_80770628[arg0]];
        raiseException(9, temp, 0, 0);
    }
    D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770740[D_global_asm_80770628[arg0]]] = -1;
    D_global_asm_807705F8[arg0] = -1;
    D_global_asm_807705A0[arg0] = 0;
    D_global_asm_80770628[arg0] = -1;
    D_global_asm_80770658[arg0] = -1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80605510.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_806057F8.s")

extern f32 D_global_asm_80756DFC;
extern f64 D_global_asm_80756FF0;
extern f64 D_global_asm_80756FF8;

void playSoundAtActorPosition(Actor *arg0, s16 arg1, u8 arg2, s16 arg3, u8 arg4) {
    s32 var_v0;

    if (((arg0->y_position + 20.0f) < arg0->unkAC) && ((arg1 < 0x355) || (arg1 >= 0x35E))) {
        var_v0 = 0x5A;
    } else {
        var_v0 = 0;
    }
    playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, arg1, arg2, arg3, arg4, 0x4B, D_global_asm_80756DFC, var_v0);
}

void playSoundAtProp(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6) {
    playSoundAtPosition(D_global_asm_807F6000[arg0].x_position, D_global_asm_807F6000[arg0].y_position, D_global_asm_807F6000[arg0].z_position, arg1, arg2, arg3, arg4, arg5, arg6, 0);
}

void func_global_asm_8060956C(f32, f32, f32, s16, s32, f32, s32, s32);

void func_global_asm_8060866C(Actor *arg0, s16 arg1, u8 arg2, f32 arg3, u8 arg4, u8 arg5) {
    func_global_asm_8060956C(arg0->x_position, arg0->y_position, arg0->z_position, arg1, arg2, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/playSoundAtPosition.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80608DA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/playSound.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_8060956C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80609B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_8060A1B0.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_8060A398.s")

void func_global_asm_8060A4D0(s32 arg0, f32 arg1) {
    D_global_asm_807457B8[arg0] = arg1;
    func_global_asm_8060A398(arg0);
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_8060A500.s")

/*
void func_global_asm_8060A500(void) {
    f32 var_f12;
    f64 temp_f20;
    f64 temp_f22;
    s8 i;

    temp_f22 = D_global_asm_80756FF0;
    temp_f20 = D_global_asm_80756FF8;
    for (i = 0; i < 4; i++) {
        if (D_global_asm_80770598[i] != 0) {
            D_global_asm_80770568[D_global_asm_80770598[i]] = D_global_asm_80770568[D_global_asm_80770598[i]] + ((D_global_asm_80770578[i] - D_global_asm_80770568[D_global_asm_80770598[i]]) * temp_f20);
            var_f12 = ABS(D_global_asm_80770578[i] - D_global_asm_80770568[D_global_asm_80770598[i]]);
            if (var_f12 < temp_f22) {
                D_global_asm_80770568[D_global_asm_80770598[i]] = D_global_asm_80770578[i];
                D_global_asm_80770598[i] = 0;
            }
            func_global_asm_8060A398(i);
        }
    }
}
*/

void func_global_asm_8060A60C(s32 arg0, f32 arg1) {
    D_global_asm_80770578[arg0] = arg1;
    D_global_asm_80770598[arg0] = 1;
}

void func_global_asm_8060A634(s32 arg0, f32 arg1) {
    D_global_asm_80770578[arg0] = arg1;
    D_global_asm_80770568[arg0] = arg1;
    func_global_asm_8060A398(arg0);
}

extern f32 D_global_asm_80770588; // TODO: f32?

void func_global_asm_8060A1B0(s32, u8, f32);

void func_global_asm_8060A670(s32 arg0, u8 arg1) {
    func_global_asm_8060A1B0(arg0, arg1, D_global_asm_80770588);
}

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_8060A6A0.s")

extern u8 D_8077058E;
extern f64 D_global_asm_80757000;
extern f64 D_global_asm_80757008;
extern f64 D_global_asm_80757010;

/*
void func_global_asm_8060A6A0(s32 arg0, u8 arg1, f32 arg2) {
    f64 var_f0;
    f32 temp;
    f32 temp2;

    func_global_asm_8060A1B0(arg2, arg1, arg2);
    var_f0 = D_8077058E;
    temp = (var_f0 * D_global_asm_80757008) / D_global_asm_80757000;
    temp2 = ((var_f0 * D_global_asm_80757010) / D_global_asm_80757000) + 1.0f;
    if (arg0) {
        if (D_global_asm_80745658[D_global_asm_80770560[arg0]] & 1) {
            func_global_asm_807381D8(
                D_global_asm_8076BF20[arg0],
                temp,
                temp2
            );
        } else {
            func_global_asm_807381D8(D_global_asm_8076BF20[arg0], 0.0f, 1.0f);
        }
    }
    func_global_asm_806049CC(arg0);
}
*/
