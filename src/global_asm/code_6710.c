#include "common.h"
#pragma intrinsic sqrtf


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
extern s16 D_global_asm_80770710[];
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

void func_global_asm_80601D24(s32 arg0) {
    s32 temp_v0;
    s32 sp58;
    s32 var_s0;
    s32 found;
    s32 var_s6;

    found = FALSE;
    var_s0 = 0;
    var_s6 = 1;
    func_global_asm_8060ED6C(&D_global_asm_80767A40, &D_global_asm_8076D4C0, &D_global_asm_8076D698, 2, 2);
    osSendMesg(&D_global_asm_8076D698, 5, 0);
    while (!found) {
        osRecvMesg(&D_global_asm_8076D698, &sp58, 1);
        switch (sp58) {
            case 5:
                if (*((s32 *) D_global_asm_80767A40.unk264)) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80601EE4.s")

extern s32 D_global_asm_807454E8;

void func_global_asm_80602104(s32 arg0)
{
    s32 *temp_t7 = &D_global_asm_807454E8;

    if (((osAiGetLength() >> 2) == 0) && (*temp_t7 == 0)) {
        *temp_t7 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80602144.s")

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    ALLink *unk4;
    ALLink *unk8;
} Struct80770188;

typedef struct Struct80602144 {
    ALLink unk0;
    s32 unk8;
    u32 unkC;
    s32 unk10;
} Struct80602144;

typedef struct Struct807701A8 {
    // size: 0x18
    s32 pad0[6];
} Struct807701A8;

u32 func_global_asm_80602144(u32, s32, void *);

extern Struct80770188 D_global_asm_80770188;

extern u32 D_global_asm_807452C4;
extern Struct807701A8 D_global_asm_807701A8[];
extern OSMesgQueue D_global_asm_807704A8;

/*
u32 func_global_asm_80602144(u32 arg0, s32 arg1, void *arg2) {
    void *temp_t0; // 44
    Struct80602144 *temp_s0;
    ALLink *var_s1;
    Struct80602144 *var_s0;
    ALLink *var_a2; // 30
    s32 temp_s1; // nis

    var_s1 = D_global_asm_80770188.unk4;
    var_a2 = NULL;
    var_s0 = var_s1;
    while (var_s0) {
        if (arg0 >= var_s0->unk8) {
            var_a2 = var_s0;
            if ((var_s0->unk8 + 0x800) >= (s32)(arg0 + arg1)) {
                var_s0->unkC = D_global_asm_807452C0;
                return osVirtualToPhysical((var_s0->unk10 + arg0) - var_s0->unk8);
            }
            var_s0 = var_s0->unk0.next;
        } else {
            break;
        }
    }
    temp_s0 = D_global_asm_80770188.unk8;
    if (!temp_s0) {
        return osVirtualToPhysical(var_s1);
    }
    D_global_asm_80770188.unk8 = temp_s0->unk0.next;
    alUnlink(temp_s0);
    if (var_a2 != NULL) {
        alLink(temp_s0, var_a2);
    } else {
        var_s1 = D_global_asm_80770188.unk4;
        if (var_s1 != NULL) {
            D_global_asm_80770188.unk4 = temp_s0;
            temp_s0->unk0.next = var_s1;
            temp_s0->unk0.prev = NULL;
            var_s1->prev = temp_s0;
        } else {
            D_global_asm_80770188.unk4 = temp_s0;
            temp_s0->unk0.next = NULL;
            temp_s0->unk0.prev = NULL;
        }
    }
    temp_s1 = arg0 & 1;
    temp_s0->unk8 = arg0 - temp_s1;
    temp_s0->unkC = D_global_asm_807452C0;
    temp_t0 = temp_s0->unk10;
    osPiStartDma(&D_global_asm_807701A8[D_global_asm_807452C4++], 1, 0, temp_s0->unk8, temp_t0, 0x800U, &D_global_asm_807704A8);
    return osVirtualToPhysical(temp_t0) + temp_s1;
}
*/

extern s32 D_global_asm_8076FE68;

void *func_global_asm_806022DC(s32 *arg0) {
    if (D_global_asm_80770188.unk0 == 0) {
        D_global_asm_80770188.unk4 = NULL;
        D_global_asm_80770188.unk8 = &D_global_asm_8076FE68;
        D_global_asm_80770188.unk0 = 1;
    }
    *arg0 = &D_global_asm_80770188;
    return func_global_asm_80602144;
}

extern OSMesgQueue D_global_asm_807704A8;
extern u32 D_global_asm_807452C0;

void func_global_asm_80602314(void) {
    ALLink *next;
    void *sp40;
    ALLink *current;
    u32 i;

    sp40 = NULL;
    for (i = 0; i < D_global_asm_807452C4; i++) {
        osRecvMesg(&D_global_asm_807704A8, &sp40, 0);
    }
    current = D_global_asm_80770188.unk4;
    while (current != NULL) {
        next = current->next;
        // TODO: What's going on in this comparison?
        if ((((s32*)current)[3] + 1) < D_global_asm_807452C0) {
            if (current == D_global_asm_80770188.unk4) {
                D_global_asm_80770188.unk4 = current->next;
            }
            alUnlink(current);
            if (D_global_asm_80770188.unk8 != NULL) {
                alLink(current, D_global_asm_80770188.unk8);
            } else {
                D_global_asm_80770188.unk8 = current;
                current->next = NULL;
                current->prev = NULL;
            }
        }
        current = next;
    }
    D_global_asm_807452C4 = 0;
    D_global_asm_807452C0++;
}

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

extern Struct80770DD8 D_global_asm_80770DD8;
extern u8 D_global_asm_80745650;

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
        if (D_global_asm_80770DD8.unk1 == 0xFF) {
            D_global_asm_80770DD8.unk1 = 0;
        }
    } else {
        max = 0x1D;
        temp_v0 = func_global_asm_806531B8(character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z, 0);
        for (i = 0; i < max; i++) {
            if ((current_map == D_global_asm_807459FC[i].unk0) && (temp_v0 == D_global_asm_807459FC[i].unk2)) {
                D_global_asm_80770DC9 = D_global_asm_807459FC[i].unk8;
                playSong(D_global_asm_807459FC[i].unk4, 1.0f);
                if (D_global_asm_807459FC[i].unk6 != 0) {
                    D_global_asm_80770DD8.unk1 = D_global_asm_807459FC[i].unk6;
                }
                return;
            }
        }
        D_global_asm_80770DD8.unk1 = 0xFF;
        return;
    }
}

void func_global_asm_806025AC(s32 arg0, s32 arg1, s32 arg2) {
    func_global_asm_80602498();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_806025D4.s")

void playSong(MUSIC_E song, f32 arg1) {
    u8 i;
    u8 temp_v0;

    temp_v0 = func_global_asm_8060245C(song);
    if (song != MUSIC_0_SILENCE) {
        s32 temp = D_global_asm_807458DC[temp_v0];
        if (song != temp || (D_global_asm_80745658[song] & 0x200)) {
            D_global_asm_807458DC[temp_v0] = song;
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

extern f32 D_global_asm_80770DDC;
extern f32 D_global_asm_80770DE0;
extern f32 D_80770DE4;

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
    if (0.8 < arg5) {
        var_f0 = arg5 - 0.8;
    } else {
        var_f0 = -(arg5 - 0.8);
    }
    if ((var_f0 < 0.1) && (dy < 0.0f)) {
        dy *= 20.0f;
    }
    D_global_asm_80770DE4 = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    if (0.8 <= arg5) {
        dz = character_change_array->look_at_at_z - character_change_array->look_at_eye_z;
        dx = character_change_array->look_at_at_x - character_change_array->look_at_eye_x;
        sp18 = func_global_asm_80665E48(character_change_array->look_at_eye_y, 0.0f, character_change_array->look_at_at_y, sqrtf(SQ(dz) + SQ(dx)));
        dz = arg2 - character_change_array->look_at_eye_z;
        dx = arg0 - character_change_array->look_at_eye_x;
        D_global_asm_80770DDC = func_global_asm_80665E48(character_change_array->look_at_eye_y, 0.0f, arg1, sqrtf(SQ(dz) + SQ(dx))) - sp18;
        if (D_global_asm_80770DDC < 0.0f) {
            D_global_asm_80770DDC += MATH_2PI_F;
        }
        if (0.3926991 < D_global_asm_80770DDC) {
            temp_f0 = D_global_asm_80770DDC;
            if (temp_f0 < 5.890486389398575) {
                D_80770DE4 *= 1.0f - (func_global_asm_80612D1C(((temp_f0 * 4.0) / 7.0) + 2.942101601958275) * 4.0f);
            }
        }
    }
    D_global_asm_80770DDC = func_global_asm_80665E48(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, arg0, arg2) - character_change_array->unk2C4;
    if (D_global_asm_80770DDC < 0.0f) {
        D_global_asm_80770DDC += MATH_2PI_F;
    }
    if (0.7853982 < D_global_asm_80770DDC) {
        if ((D_global_asm_80770DDC < 5.497787296772003) && (sp18 < 4.0)) {
            D_80770DE4 *= 1.0f - (func_global_asm_80612D1C(((2.0 * D_global_asm_80770DDC) / 3.0) + 2.617993950843811) * arg5);
        }
    }
    if (D_80770DE4 < 1.0f) {
        D_global_asm_80770DE4 = 1.0f;
    }
    temp_f2_4 = arg4 * 4000;
    temp_f8 = (temp_f2_4 / sqrtf(D_80770DE4)) - ((temp_f2_4 * 0.12909946) - 32767.0);
    temp_f16_3 = temp_f8 * arg3 * 0.00392156862745098;
    if (temp_f16_3 < 10.0f) {
        return 0.0f;
    }
    D_global_asm_80770DE0 = func_global_asm_80612D10(D_global_asm_80770DDC);
    D_global_asm_80770DDC = (1.0f - func_global_asm_80612D1C(D_global_asm_80770DDC)) * 63.5;
    if (temp_f16_3 < 10.0f) {
        return 0.0f;
    }
    if (32767.0 < temp_f16_3) {
        temp_f16_3 = 32767.0;
    }
    return temp_f16_3;
}
*/

extern f32 D_global_asm_80770DDC;
extern f32 D_global_asm_80770DE0;
extern f32 D_global_asm_80770DE8;
extern f32 D_global_asm_80770DEC;
extern f32 D_global_asm_80770DF0;
extern f32 D_global_asm_80770DF4;

f32 func_global_asm_80603340(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, f32 arg5) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_global_asm_80602E6C(arg0, arg1, arg2, arg3, arg4, arg5);
    if (temp_f0 < 10.0f) {
        return 0.0f;
    }
    temp_f2 = D_global_asm_80770DDC * 0.007874015748031496;
    D_global_asm_80770DE8 += temp_f0 * temp_f2;
    D_global_asm_80770DEC += temp_f0 * (1.0f - temp_f2);
    if (D_global_asm_80770DE0 > 0.0f) {
        D_global_asm_80770DF0 += temp_f0 * D_global_asm_80770DE0;
    }
    if (D_global_asm_80770DE0 < 0.0f) {
        D_global_asm_80770DF4 -= temp_f0 * D_global_asm_80770DE0;
    }
    return temp_f0;
}

// Jumptable, doable, decent progress
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80603450.s")

typedef struct MusicCylData {
    tuple_s position;
    s16 unk6;
    s16 range;
    u8 unkA;
    u8 enter_song;
    u8 leave_song;
    u8 ambient_song;
} MusicCylData;

typedef struct Struct80745B28 {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
} Struct80745B28;

typedef struct Struct80603450_0 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
} Struct80603450_0;

void func_global_asm_80737924(SoundState *);
extern s32 D_global_asm_807457DC;
extern u8 D_global_asm_80745838;
extern Struct80745B28 D_global_asm_80745B28[];
extern MapSongData D_global_asm_80745BDC[];
extern MusicCylData D_global_asm_80745F74[7];
extern MusicCylData D_global_asm_80745FD8[4];
extern MusicCylData D_global_asm_80746010[3];
extern MusicCylData D_global_asm_8074603C[4];
extern MusicCylData D_global_asm_80746074[4];
extern MusicCylData D_global_asm_807460AC[4];
extern MusicCylData D_global_asm_807460E4[10];
extern MusicCylData D_global_asm_80746170[8];
extern MusicCylData D_global_asm_807461E0[7];
extern MusicCylData D_global_asm_80746244[4];
extern MusicCylData D_global_asm_8074627C[3];
extern void *D_global_asm_8076D1F8;
extern void *D_global_asm_8076D1FC;
extern u8 D_global_asm_8077058C;
extern u8 D_global_asm_8077058D;
extern u8 D_global_asm_8077058E;
extern u8 D_global_asm_80770DC8;
extern u8 D_global_asm_80770DCA;
extern u8 D_global_asm_80770DCB;
extern f32 D_global_asm_80770DCC;
extern f32 D_global_asm_80770DD0;
extern f32 D_global_asm_80770DD4;
extern u8 D_global_asm_80770DD9;
extern SoundState *D_global_asm_80770DF8[];
extern u32 D_global_asm_80770E38[];
extern f32 D_global_asm_80770E78[];
extern f32 D_global_asm_80770EB8[];
extern f32 D_global_asm_80770EF8[];
extern f32 D_global_asm_80770DE4;

#define func_global_asm_80737AC4_f32(a, b, c) func_global_asm_80737AC4(a, b, *(s32*)(&c))

/*
void func_global_asm_80603450(void) {
    s8 spE7;
    u8 temp;
    u8 spE5;
    f32 spCC;
    s32 spC8;
    MusicCylData *spC0;
    Struct80603450_0 *spBC;
    f32 temp_f0;
    f32 dx;
    f32 dz;
    f32 dy;
    f32 var_f20;
    f32 var_f22;
    f32 var_f2;
    s16 temp_a1;
    s16 temp_v0;
    s16 j;
    SoundState *temp_s0_3;
    s32 var_s1;
    s32 var_t2;
    s16 i;
    u32 temp_lo;

    spE7 = -1;
    spE5 = 0;
    switch (current_map) {
    case MAP_JAPES:
        var_s1 = ARRAY_COUNT(D_global_asm_80745F74);
        spC0 = &D_global_asm_80745F74;
        break;
    case MAP_AZTEC:
        var_s1 = ARRAY_COUNT(D_global_asm_80745FD8);
        spC0 = &D_global_asm_80745FD8;
        break;
    case MAP_GALLEON:
        var_s1 = ARRAY_COUNT(D_global_asm_80746010);
        spC0 = &D_global_asm_80746010;
        break;
    case MAP_GALLEON_SEAL_RACE:
        var_s1 = ARRAY_COUNT(D_global_asm_8074603C);
        spC0 = &D_global_asm_8074603C;
        break;
    case MAP_FACTORY:
        var_s1 = ARRAY_COUNT(D_global_asm_80746074);
        spC0 = &D_global_asm_80746074;
        break;
    case MAP_AZTEC_BEETLE_RACE:
        var_s1 = ARRAY_COUNT(D_global_asm_807460AC);
        spC0 = &D_global_asm_807460AC;
        break;
    case MAP_FACTORY_CAR_RACE:
        var_s1 = ARRAY_COUNT(D_global_asm_807460E4);
        spC0 = &D_global_asm_807460E4;
        break;
    case MAP_FUNGI_MINECART:
        var_s1 = ARRAY_COUNT(D_global_asm_807461E0);
        spC0 = &D_global_asm_807461E0;
        break;
    case MAP_DK_ISLES_OVERWORLD:
        var_s1 = ARRAY_COUNT(D_global_asm_80746244);
        spC0 = &D_global_asm_80746244;
        break;
    case MAP_TRAINING_GROUNDS:
        var_s1 = ARRAY_COUNT(D_global_asm_8074627C);
        spC0 = &D_global_asm_8074627C;
        break;
    case MAP_FUNGI:
        spC0 = &D_global_asm_80746170;
        var_s1 = ARRAY_COUNT(D_global_asm_80746170);
        if (extra_player_info_pointer->unk1F0 & 0x100000) {
            func_global_asm_80602B60(0x44, 0U);
            if (func_global_asm_80602D4C(0x44) < 0.1) {
                playSong(MUSIC_70_FUNGI_FOREST_NIGHT, 1.0f);
            }
        } else {
            func_global_asm_80602B60(0x46, 0U);
            if (func_global_asm_80602D4C(0x46) < 0.1) {
                playSong(MUSIC_68_FUNGI_FOREST_DAY, 1.0f);
            }
        }
        break;
    default:
        var_s1 = 0;
        break;
    }
    if ((var_s1 != 0) && (D_global_asm_80745650) && (D_global_asm_80745654 == 0)) {
        D_global_asm_80770DD4 = 1000000.0f;
        var_f22 = 0.0f;
        for (i = 0; i < var_s1;) {
            dx = character_change_array->look_at_eye_x - spC0[i].position.x;
            dz = character_change_array->look_at_eye_z - spC0[i].position.z;
            if (spC0[i].unk6 == -1) {
                D_global_asm_80770DE4 = sqrtf(SQ(dx) + SQ(dz));
                temp_v0 = spC0[i].range;
                if (D_global_asm_80770DE4 < temp_v0 - 0x14) {
                    playSong(spC0[i].enter_song, 1.0f);
                } else if (temp_v0 < D_global_asm_80770DE4) {
                    func_global_asm_80602B60(spC0[i].enter_song, 0U);
                }
            } else {
                dy = character_change_array->look_at_eye_y - spC0[i].position.y;
                D_global_asm_80770DE4 = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
                if ((i == 0) || (D_global_asm_80770DE4 < D_global_asm_80770DD4)) {
                    spE7 = i;
                    D_global_asm_80770DD4 = D_global_asm_80770DE4;
                    var_f20 = ((func_global_asm_80611BB4(dx, dz) * 4096.0) / TWO_PI) - spC0[i].unk6;
                }
            }
            i++;
            D_global_asm_80770DE8 = 32767.0f - ((D_global_asm_80770DE4 - 50.0f) * 120.0f);
            if (D_global_asm_80770DE8 > 32767.0f) {
                D_global_asm_80770DE8 = 32767.0f;
            }
            if (D_global_asm_80770DE8 < 0.0f) {
                D_global_asm_80770DE8 = 0.0f;
            }
            var_f22 += D_global_asm_80770DE8;
        }
        D_global_asm_80770DE4 = D_global_asm_80770DD4;
        if ((spE7 >= 0) && ((D_global_asm_80770DE4 < spC0[spE7].range))) {
            if (spC0[spE7].unk6 >= 0x1001) {
                D_global_asm_80770DC9 = spC0[spE7].unk6 & 1;
            } else {
                if (var_f20 > 2048.0f) {
                    var_f20 -= 4096.0f;
                }
                if (var_f20 < -2048.0f) {
                    var_f20 += 4096.0f;
                }
                if ((var_f20 < 1024.0f) && (var_f20 > -1024.0f)) {
                    if (D_global_asm_80770DCB) {
                        D_global_asm_80770DC9 = 1;
                    }
                } else {
                    D_global_asm_80770DCB = 1;
                    D_global_asm_80770DC9 = 0;
                    playSong(spC0[spE7].leave_song, 1.0f);
                }
            }
            if (D_global_asm_80770DC9) {
                D_global_asm_80770DC8 = spC0[spE7].unkA;
            } else {
                D_global_asm_80770DC8 = 0U;
            }
            D_global_asm_80770DD9 = spC0[spE7].enter_song;
        } else {
            D_global_asm_80770DCB = 0;
        }
        if (D_global_asm_80745838) {
            var_f22 = 0.0f;
        } else {
            if (D_global_asm_80770DC9) {
                var_f22 = 32767.0f;
            } else {
                if (var_f22 > 32767.0f) {
                    var_f22 = 32767.0f;
                }
                if (var_f22 < 500.0f) {
                    var_f22 = 0.0f;
                }
            }
        }
        if (D_global_asm_80770DD8.unk1 == 0xFF) {
            D_global_asm_80770DD8.unk1 = spC0[spE7].enter_song;
            D_global_asm_80770DC8 = spC0[spE7].unkA;
            if (D_global_asm_80770DC9 == 0) {
                playSong(spC0[spE7].leave_song, 1.0f);
            }
        }
        if ((D_global_asm_80770DC9 != 0) && (D_global_asm_80770DD8.unk1 != 0)) {
            playSong(D_global_asm_80770DD8.unk1, 1.0f);
        } else if (D_global_asm_80745838 != 0) {
            func_global_asm_8060A60C(0, 1.0f);
        } else {
            func_global_asm_80602B60(D_global_asm_80770DD8.unk1, 0U);
        }
        D_global_asm_80770DCA = D_global_asm_80770DC9;
        if (var_f22 != 0.0f) {
            if (spC0[spE7].ambient_song != 0) {
                playSong(spC0[spE7].ambient_song, 1.0f);
            }
        }
        if (D_global_asm_80770560[2] == 0x26) {
            func_global_asm_8060A634(2, var_f22 / 32767.0);
        }
        var_f22 = ((var_f22 - 28384.0f) * 100.0f) / 4383.0f;
        if (var_f22 < 0.0f) {
            var_f22 = 0.0f;
        }
        temp = D_global_asm_80745BDC[current_map].unk1;
        D_global_asm_8077058E = (f32)((((255.0 - temp) * (D_global_asm_80770DC8 / 127.0) * var_f22) / 255.0) + temp);
    } else {
        D_global_asm_8077058E = D_global_asm_80745BDC[current_map].unk1;
    }
    if (D_global_asm_80745838) {
        D_global_asm_8077058E = 0xFF;
    }
    if (D_global_asm_8077058D != D_global_asm_8077058E) {
        var_f20 = ((D_global_asm_8077058E * 0.3) / 255.0);
        var_f22 = (((D_global_asm_8077058E * 0.35) / 255.0) + 1.0);
        if (current_map == MAP_AZTEC_BEETLE_RACE) {
            if (D_global_asm_8077058E != 0) {
                func_global_asm_8060A634(0, 1.0f);
            } else {
                func_global_asm_8060A634(0, 0.6f);
            }
            func_global_asm_807381D8(*D_global_asm_8076BF20, var_f20, var_f22);
        }
        for (j = 0; j < 4; j++) {
            if (D_global_asm_80745658[D_global_asm_80770560[j]] & 1) {
                func_global_asm_807381D8(D_global_asm_8076BF20[j], var_f20, var_f22);
            } else {
                func_global_asm_807381D8(D_global_asm_8076BF20[j], 0.0f, 1.0f);
            }
        }
        D_global_asm_8077058D = D_global_asm_8077058E;
    }
    spC8 = func_global_asm_8062F388(&spBC);
    for (i = 0; i < 0xF; i++) {
        D_global_asm_80770DE8 = 0.0f;
        D_global_asm_80770DEC = 0.0f;
        D_global_asm_80770DF0 = 0.0f;
        D_global_asm_80770DF4 = 0.0f;
        if ((global_properties_bitfield & 2) || !(global_properties_bitfield & 0x10)) {
            var_f22 = 0.0f;
        } else if ((i == 0xB) && (isFlagSet(PERMFLAG_PROGRESS_HELM_SHUTDOWN, FLAG_TYPE_PERMANENT))) {
            var_f22 = 0.0f;
        } else if ((i == 0xD) && (isFlagSet(PERMFLAG_PROGRESS_LLAMA_TEMPLE_WATER_COOLED, FLAG_TYPE_PERMANENT))) {
            var_f22 = 0.0f;
        } else {
            if (i == 1) {
                func_global_asm_80664044(1U, 0xFFU, 0xC8U, 0.3f);
            }
            for (j = spC8 - 1; j >= 0; j--) {
                if ((i + 1) == spBC[j].unk7) {
                    func_global_asm_80603340(
                        spBC[j].unk0, spBC[j].unk2, spBC[j].unk4,
                        (D_global_asm_80745B28[i].unk2 * spBC[j].unk6) / 255.0,
                        D_global_asm_80745B28[i].unk3, D_global_asm_80745B28[i].unk4);
                }
            }
            var_f22 = D_global_asm_80770DE8 + D_global_asm_80770DEC;
            if (var_f22 > 32767.0f) {
                var_f22 = 32767.0f;
            }
            if (var_f22 < 500.0f) {
                var_f22 = 0.0f;
            }
        }
        temp_a1 = D_global_asm_80745B28[i].unk0;
        if (temp_a1 == 0x1E) {
            var_f22 *= 0.6;
            if (D_global_asm_80767A40.unk280 / 12U != D_global_asm_80770E38[i]) {
                D_global_asm_80770E38[i] = D_global_asm_80767A40.unk280 / 12U;
                if (var_f22 > 10.0f) {
                    func_global_asm_80737638(D_global_asm_8076D1F8, temp_a1, var_f22, 0x3FU, 0.4f, 0U, &D_global_asm_80770DF8[i]);
                    D_global_asm_80770EB8[i] = var_f22 + 1.0f;
                    D_global_asm_80770EF8[i] = 300.0f;
                }
            }
        }
        if ((var_f22 != D_global_asm_80770EB8[i]) || (D_global_asm_80770DF8[i] == 0)) {
            temp_s0_3 = D_global_asm_80770DF8[i];
            if (var_f22 > 10.0f) {
                if (temp_s0_3 == 0) {
                    if (D_global_asm_80745B28[i].unk0 < 0x800) {
                        func_global_asm_80737638(D_global_asm_8076D1F8, D_global_asm_80745B28[i].unk0, var_f22, 0x3FU, D_global_asm_80745B28[i].unk8, 0U, &D_global_asm_80770DF8[i]);
                    } else {
                        func_global_asm_80737638(D_global_asm_8076D1FC, D_global_asm_80745B28[i].unk0 - 0x7FF, var_f22, 0x3FU, D_global_asm_80745B28[i].unk8, 0U, &D_global_asm_80770DF8[i]);
                    }
                    D_global_asm_80770E78[i] = 0.0f;
                    D_global_asm_80770EF8[i] = 255.0f;
                }
                if (D_global_asm_80770DF8[i] != 0) {
                    func_global_asm_80737AC4(D_global_asm_80770DF8[i], 8, var_f22);
                }
                if (D_global_asm_80770DF0 < D_global_asm_80770DF4) {
                    spE5 = 0x80;
                }
                if (D_global_asm_80770DF8[i] != 0) {
                    func_global_asm_80737AC4(D_global_asm_80770DF8[i], 0x100, spE5);
                }
            } else if (temp_s0_3 != 0) {
                func_global_asm_80737924(temp_s0_3);
            }
            D_global_asm_80770EB8[i] = var_f22;
        }
        if (D_global_asm_80770DF8[i] != 0) {
            if (D_global_asm_80770DE8 > 32767.0f) {
                D_global_asm_80770DE8 = 32767.0f;
            }
            if (D_global_asm_80770DEC > 32767.0f) {
                D_global_asm_80770DEC = 32767.0f;
            }
            if (D_global_asm_80770DEC < D_global_asm_80770DE8) {
                if (D_global_asm_80770DE8 > 0.0f) {
                    var_f20 = (127.0 - ((D_global_asm_80770DEC * 63.5) / D_global_asm_80770DE8));
                } else {
                    var_f20 = 0.0f;
                }
            } else if (D_global_asm_80770DEC > 0.0f) {
                var_f20 = ((D_global_asm_80770DE8 * 63.5) / D_global_asm_80770DEC);
            } else {
                var_f20 = 0.0f;
            }
            if (D_global_asm_80745838 != 0) {
                var_f2 = (D_global_asm_80745B28[i].unk8 * 0.5);
            } else if ((D_global_asm_80770DC9 != 0) && (D_global_asm_80745B28[i].unk0 == 0x106)) {
                var_f2 = (1.0 / ((D_global_asm_80770DD4 / 800.0) + 1.0));
            } else {
                var_f2 = D_global_asm_80745B28[i].unk8;
            }
            temp_f0 = D_global_asm_80770EF8[i];
            spCC = var_f2;
            if (var_f20 != temp_f0) {
                if (temp_f0 != 255.0f) {
                    if (temp_f0 < var_f20) {
                        var_f2 = temp_f0 + 8.0f;
                        if (var_f2 < var_f20) {
                            var_f20 = var_f2;
                        }
                    } else {
                        var_f2 = temp_f0 - 8.0f;
                        if (var_f20 < var_f2) {
                            var_f20 = var_f2;
                        }
                    }
                }
                func_global_asm_80737AC4(D_global_asm_80770DF8[i], 4, var_f20);
                D_global_asm_80770EF8[i] = var_f20;
            }
            if (spCC != D_global_asm_80770E78[i]) {
                func_global_asm_80737AC4_f32(D_global_asm_80770DF8[i], 0x10, spCC);
                D_global_asm_80770E78[i] = spCC;
            }
        }
    }
    if ((global_properties_bitfield & 2) || !(global_properties_bitfield & 0x10)) {
        D_global_asm_8077058C = 0;
    }
    if (D_global_asm_8077058C != 0) {
        if (D_global_asm_807457DC == 0) {
            func_global_asm_80737638(D_global_asm_8076D1F8, 0x125, 0U, 0x3FU, 1.0f, 0U, &D_global_asm_807457DC);
        }
        if (D_global_asm_807457DC != 0) {
            func_global_asm_80737AC4(D_global_asm_807457DC, 8, (D_global_asm_8077058C * 10767.0) / 255.0);
            var_t2 = 0;
            spCC = 1.0 - ((D_global_asm_8077058E * 0.5) / 255.0);
            if (D_global_asm_80770DD4 < 1000.0f) {
                var_t2 = 1;
            }
            if (D_global_asm_80770DC9 & var_t2) {
                var_f20 = func_global_asm_80665E48(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, (f32) spC0[spE7].position.x, (f32) spC0[spE7].position.z) - character_change_array->unk2C4;
                if (var_f20 < 0.0f) {
                    var_f20 += 6.2831855f;
                }
                if ((var_f20 > 1.5707964f) && (var_f20 < 4.71238911151886)) {
                    D_global_asm_80770DD0 = 128.0f;
                } else {
                    D_global_asm_80770DD0 = 0.0f;
                }
                D_global_asm_80770DCC = (1.0f - func_global_asm_80612D1C(var_f20)) * 63.5;
            } else {
                D_global_asm_80770DCC = 64.0f;
            }
            func_global_asm_80737AC4_f32(D_global_asm_807457DC, 0x10, spCC);
            func_global_asm_80737AC4(D_global_asm_807457DC, 0x100, D_global_asm_80770DD0);
            func_global_asm_80737AC4(D_global_asm_807457DC, 4, D_global_asm_80770DCC);
        }
    } else if (D_global_asm_807457DC != 0) {
        func_global_asm_80737924(D_global_asm_807457DC);
    }
}
*/

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

s16 func_global_asm_80604D70(Actor *arg0, s16 arg1, u8 arg2, s32 arg3, u8 arg4, f32 arg5, s8 arg6);

void func_global_asm_80604CBC(Actor *arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6, s8 arg7) {
    if (arg0->unk6E[arg4] != -1) {
        if (arg1 == D_global_asm_80770710[D_global_asm_80770628[arg0->unk6E[arg4]]]) {
            return;
        }
        func_global_asm_80605314(arg0, arg4);
    }
    arg0->unk6E[arg4] = func_global_asm_80604D70(arg0, arg1, arg2, arg3, arg5, arg6, arg7);
}

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

extern s32 D_global_asm_807705A0[];
extern s16 D_global_asm_807705F8[];
extern s16 D_global_asm_80770658[];
extern s8 D_global_asm_807706F8[];
extern s16 D_global_asm_80770740[];

typedef struct {
    s16 unk0[22];
} Struct807707A0;

extern Struct807707A0 D_global_asm_807707A0[];

void func_global_asm_80605380(s16 arg0) {
    if ((--D_global_asm_80770740[D_global_asm_80770628[arg0]]) != 0) {
        D_global_asm_80770658[D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770740[D_global_asm_80770628[arg0]]]] = D_global_asm_80770658[D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770658[arg0]]];
        D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770658[arg0]] = D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770740[D_global_asm_80770628[arg0]]];
    } else {
        D_global_asm_80770710[D_global_asm_80770628[arg0]] = 0;
        D_global_asm_807706F8[D_global_asm_80770628[arg0]] = 0;
    }
    if ((D_global_asm_80770740[D_global_asm_80770628[arg0]] < 0) || (D_global_asm_80770740[D_global_asm_80770628[arg0]] >= 0x17)) {
        raiseException(9, (s32) (u32) D_global_asm_80770740[D_global_asm_80770628[arg0]], 0, 0);
    }
    D_global_asm_807707A0[D_global_asm_80770628[arg0]].unk0[D_global_asm_80770740[D_global_asm_80770628[arg0]]] = -1;
    D_global_asm_807705F8[arg0] = -1;
    D_global_asm_807705A0[arg0] = 0;
    D_global_asm_80770628[arg0] = -1;
    D_global_asm_80770658[arg0] = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80605510.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_806057F8.s")

void playSoundAtActorPosition(Actor *arg0, s16 arg1, u8 arg2, s16 arg3, u8 arg4) {
    s32 var_v0;

    if (((arg0->y_position + 20.0f) < arg0->unkAC) && ((arg1 < 0x355) || (arg1 >= 0x35E))) {
        var_v0 = 0x5A;
    } else {
        var_v0 = 0;
    }
    playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, arg1, arg2, arg3, arg4, 0x4B, 0.3f, var_v0);
}

void playSoundAtProp(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6) {
    playSoundAtPosition(D_global_asm_807F6000[arg0].x_position, D_global_asm_807F6000[arg0].y_position, D_global_asm_807F6000[arg0].z_position, arg1, arg2, arg3, arg4, arg5, arg6, 0);
}

void func_global_asm_8060956C(f32, f32, f32, s16, u8, f32, u8, u8);

void func_global_asm_8060866C(Actor *arg0, s16 arg1, u8 arg2, f32 arg3, u8 arg4, u8 arg5) {
    func_global_asm_8060956C(arg0->x_position, arg0->y_position, arg0->z_position, arg1, arg2, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/playSoundAtPosition.s")

void func_global_asm_807375E0(N_ALVoice *, u8);
extern N_ALVoice *D_global_asm_807457D0[];
extern u8 D_global_asm_807457D8;
extern void *D_global_asm_8076D1F8;
extern u8 D_global_asm_8077058E;

void func_global_asm_80608DA8(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    s32 temp_f16;
    f32 sp40;
    f32 temp_f0;
    u8 var_t0; // 3b

    temp_f16 = (arg1 * 0x7FFF) / 255.0;
    var_t0 = 0;
    if (temp_f16 < 0x3E9) {
        return;
    }
    temp_f0 = arg2 / 127.0;
    sp40 = (((func_global_asm_806119A0() / (f64)0xFFFFFFFF) * (2.0 * arg3)) + (63.5 - arg3));
    if (arg3 != 0) {
        temp_f16 = ((1.0 - ((func_global_asm_806119A0() / (f64)0xFFFFFFFF) * (arg3 / 155.0))) * (f64) temp_f16);
        var_t0 = 0;
        temp_f0 = (((func_global_asm_806119A0() / (f64)0xFFFFFFFF) * (arg3 / 100.0)) + ((f64) temp_f0 - (arg3 / 255.0)));
    }
    if (D_global_asm_8077058E >= 0x15) {
        var_t0 = (D_global_asm_8077058E * 100) / 255;
    }
    if (arg4 != 0) {
        var_t0 |= 0x80;
    }
    if (D_global_asm_807457D0[D_global_asm_807457D8]) {
        func_global_asm_80737924(D_global_asm_807457D0[D_global_asm_807457D8]);
    }
    func_global_asm_80737638(D_global_asm_8076D1F8, arg0, temp_f16, sp40, temp_f0, var_t0, &D_global_asm_807457D0[D_global_asm_807457D8]);
    func_global_asm_807375E0(D_global_asm_807457D0[D_global_asm_807457D8], 0);
    D_global_asm_807457D8 ^= 1;
}



#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/playSound.s")

extern SoundState *D_global_asm_807457E4[];
extern u8 D_global_asm_80745834;
extern void *D_global_asm_8076D1F8;
extern void *D_global_asm_8076D1FC;
extern u8 D_global_asm_8077058E;

/*
s16 playSound(s16 arg0, s32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5) {
    s16 var_v1; // 36
    u8 temp;
    s32 var_v0;

    if ((u8) arg4 != 0) {
        arg1 = (1.0 - ((f64)func_global_asm_806119A0() / 0xFFFFFFFF) * (arg4 / 155.0)) * arg1; // Is 155.0 a typo?
        arg3 = ((((f64)func_global_asm_806119A0() / 0xFFFFFFFF) * (arg4 / 100.0)) + (arg3 - (arg4 / 255.0)));
    }
    for (var_v1 = 0x14; var_v1 > 0; var_v1--) {
        if (!D_global_asm_807457E4[D_global_asm_80745834]) {
            break;
        }
        D_global_asm_80745834++;
        if (D_global_asm_80745834 == 0x14) {
            D_global_asm_80745834 = 0;
        }

    }
    if (var_v1 > 0) {
        osSetThreadPri(NULL, 0x1A);
        if (D_global_asm_8077058E >= 0x15) {
            var_v0 = (D_global_asm_8077058E * 100) / 255;
            temp = arg5 & 0x7F;
            if (var_v0 < temp) {
                var_v0 = temp;
            } else {
            }
            arg5 &= 0x80;
            arg5 |= var_v0;
        } else {

        }
        if (arg0 < 0x800) {
            func_global_asm_80737638(D_global_asm_8076D1F8, arg0, arg1, arg2, arg3, arg5, &D_global_asm_807457E4[D_global_asm_80745834]);
        } else {
            func_global_asm_80737638(D_global_asm_8076D1FC, arg0 - 0x7FF, arg1, arg2, arg3, arg5, &D_global_asm_807457E4[D_global_asm_80745834]);
        }
        if (arg0 == 0x137) {
            func_global_asm_807375E0(D_global_asm_807457E4[D_global_asm_80745834], 0x64);
        }
        var_v0 = -1;
        if (D_global_asm_807457E4[D_global_asm_80745834]) {
            var_v0 = D_global_asm_80745834;
        }
        var_v1 = var_v0;
        osSetThreadPri(NULL, 0xA);
        return var_v1;
    }
    return -1;
}
*/

extern s32 D_global_asm_807457C8;
extern u8 D_global_asm_80745838;
extern void *D_global_asm_8076D1F8;
extern void *D_global_asm_8076D1FC;
extern u8 D_global_asm_8077058E;
extern f32 D_global_asm_80770DE4;

void func_global_asm_8060956C(f32 arg0, f32 arg1, f32 arg2, s16 arg3, u8 arg4, f32 arg5, u8 arg6, u8 arg7) {
    f32 temp_f2;
    f32 var_f14;
    SoundState *temp;
    s32 var_v1; // 48
    f32 temp_f14; // 44
    u8 sp43;
    f64 var_f6;

    sp43 = 0;
    D_global_asm_80770DE4 = sqrtf(
        SQ((s32)(character_change_array->look_at_eye_x - arg0)) +
        SQ((s32)(character_change_array->look_at_eye_y - arg1)) +
        SQ((s32)(character_change_array->look_at_eye_z - arg2)));
    if (D_global_asm_80770DE4 < 1.0f) {
        D_global_asm_80770DE4 = 1.0f;
    }
    temp_f2 = arg7 * 4000;
    var_v1 = ((temp_f2 / sqrtf(D_global_asm_80770DE4)) - ((temp_f2 / 7.745966) - 32767.0));
    if (var_v1 >= 0x8000) {
        var_v1 = 0x7FFF;
    }
    var_v1 = (arg4 * var_v1) / 255.0;
    if (var_v1 >= 0x8000) {
        var_v1 = 0x7FFF;
    }
    if (var_v1 >= 0x3E9) {
        var_v1 = (arg4 * var_v1) / 255.0;
        if (arg6 != 0) {
            var_f6 = func_global_asm_806119A0() / (f64)0xFFFFFFFF;
            var_f6 *= (arg6 / 155.0); // Is 155.0 a typo?
            var_v1 = (1.0 - var_f6) * var_v1;
            arg5 = ((func_global_asm_806119A0() / (f64)0xFFFFFFFF) * (arg6 / 100.0)) + (arg5 - (arg6 / 255.0));
        }
        temp_f14 = func_global_asm_80665E48(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, arg0, arg2) - character_change_array->unk2C4;
        if (temp_f14 < 0.0f) {
            temp_f14 += MATH_2PI_F;
        }
        if ((0.25f * MATH_PI_F) < temp_f14) {
            if (temp_f14 < (1.75 * MATH_PI_F)) {
                var_v1 = ((func_global_asm_80612D1C(((2.0 * temp_f14) / 3.0) + 2.617993950843811) * 0.3) + 1.0) * var_v1;
            }
        }
        temp_f14 = (1.0f - func_global_asm_80612D1C(temp_f14)) * 63.5;
        if (D_global_asm_80745838) {
            sp43 = 0x1E;
        } else if (D_global_asm_8077058E >= 0x15) {
            sp43 = (D_global_asm_8077058E * 100) / 255;
        }
        temp = D_global_asm_807457C8;
        if (temp) {
            func_global_asm_80737924(temp);
        }
        osSetThreadPri(NULL, 0x1A);
        if (arg3 < 0x800) {
            func_global_asm_80737638(D_global_asm_8076D1F8, arg3, var_v1, temp_f14, arg5, sp43, &D_global_asm_807457C8);
        } else {
            func_global_asm_80737638(D_global_asm_8076D1FC, arg3 - 0x7FF, var_v1, temp_f14, arg5, sp43, &D_global_asm_807457C8);
        }
        osSetThreadPri(NULL, 0xA);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_80609B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_6710/func_global_asm_8060A1B0.s")

extern s16 D_global_asm_807454F0[];
extern s8 D_global_asm_8074583C;
extern s8 D_global_asm_80745840;

void func_global_asm_8060A398(s32 arg0) {
    u8 *new_var;
    f32 var_f0;
    u8 temp_v1;

    new_var = &D_global_asm_80770560[arg0];
    var_f0 = (f32) D_global_asm_80745840;
    switch (D_global_asm_80745658[D_global_asm_80770560[arg0]] & 0xC00) {
        case 0x400:
            var_f0 = (f32) D_global_asm_8074583C;
            break;

        case 0x800:
            if (!(D_global_asm_8074583C < var_f0)) {
                var_f0 = (f32) D_global_asm_8074583C;
            }
            break;
    }

    alSepqSetVol(D_global_asm_8076BF20[arg0], (s16) ((s32) (((((f64) ((((f32) D_global_asm_807454F0[*new_var]) * D_global_asm_80770568[arg0]) * D_global_asm_807457B8[arg0])) * (((f64) var_f0) / 40.0)) * 25000.0) / 32767.0)));
}

void func_global_asm_8060A4D0(s32 arg0, f32 arg1) {
    D_global_asm_807457B8[arg0] = arg1;
    func_global_asm_8060A398(arg0);
}

void func_global_asm_8060A500(void) {
    f32 var_f12;
    f64 temp_f20;
    f64 temp_f22;
    s8 i;

    temp_f22 = 0.05;
    temp_f20 = 0.075;
    for (i = 0; i < 4; i++) {
        if (D_global_asm_80770598[i] != 0) {
            D_global_asm_80770568[i] += (D_global_asm_80770578[i] - D_global_asm_80770568[i]) * temp_f20;
            var_f12 = ABS(D_global_asm_80770578[i] - D_global_asm_80770568[i]);
            if (var_f12 < temp_f22) {
                D_global_asm_80770568[i] = D_global_asm_80770578[i];
                D_global_asm_80770598[i] = 0;
            }
            func_global_asm_8060A398(i);
        }
    }
}

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

/*
void func_global_asm_8060A6A0(s32 arg0, u8 arg1, f32 arg2) {
    f64 var_f0;
    f32 temp;
    f32 temp2;

    func_global_asm_8060A1B0(arg2, arg1, arg2);
    var_f0 = D_8077058E;
    temp = (var_f0 * 0.3) / 255.0;
    temp2 = ((var_f0 * 0.35) / 255.0) + 1.0f;
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
