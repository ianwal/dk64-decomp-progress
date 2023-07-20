#include <ultra64.h>
#include "functions.h"


extern void func_8070F2FC(Gfx **arg0, s16 arg1, s16 arg2);
extern void func_8070E8F0(Gfx**, Sprite*);

typedef struct jetpac_struct_0 {
    u8  pad0[0x14];
    u32 unk14;
    u32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    s32 unk40; // Used
} JetpacStruct0;

typedef struct
{
    s32 unk0;
    s32 unk4;
    u8 pad8[0x3];
    u8 unkB;
    Sprite *unkC;
} JetpacStruct2;


typedef struct {
    JetpacStruct2 unk0[6];
    s32 unk60;
    u8  unk64; // red
    u8  unk65; // green
    u8  unk66; // blue
    u8  unk67;
} JetpacStruct1;

JetpacStruct1 D_8002F3D0[0x18][0x20];
s32 D_80045BD0;

void func_80025460(void) {
    int x, y;
    JetpacStruct1 *ptr;

    ptr = &D_8002F3D0[0][0];
    for (x = 0; x < 0x18; x++) {
        for (y = 0; y < 0x20; y++) {
            ptr->unk60 = 0;
            ptr->unk67 = 0;
            ptr++;
        }
    }
}

// TODO: Needs shape on D_8002F3D0->unk60
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_800254B8.s")

void func_800255D4(Gfx **arg0) {
    Gfx *sp1C;

    sp1C = *arg0;
    gDPPipeSync(sp1C++);
    gDPSetScissor(sp1C++, G_SC_NON_INTERLACE, 32, 24, 288, 216);
    gSPClearGeometryMode(sp1C++, -1);
    gSPSetGeometryMode(sp1C++, G_SHADE | 0x00200000);
    gDPSetRenderMode(sp1C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(sp1C++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetTextureFilter(sp1C++, G_TF_POINT);
    gDPSetTexturePersp(sp1C++, G_TP_NONE);
    gDPSetTextureConvert(sp1C++, G_TC_FILT);
    gDPSetCycleType(sp1C++, G_CYC_1CYCLE);
    gDPSetEnvColor(sp1C++, 0x00, 0x00, 0x00, 0x00);
    D_80045BD0 = 0;
    func_80025460();
    *arg0 = sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025700.s")

#ifndef NONMATCHING
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025904.s")
#else
void func_80025904(Gfx **arg0) {
    JetpacStruct1 *s3;
    s32 s4;
    s32 s7;
    Gfx *sp50;
    s32 s1;
    s16 tmp_a1;
    s16 tmp_a2;


    s3 = &D_8002F3D0[0][0];
    sp50 = *arg0;
    for (s7 = 0; s7 < 0x18; s7++) {
        for (s4 = 0; s4 < 0x20; s4++) {
            if (s3->unk60) {
                gDPSetPrimColor(sp50++, 0, 0, s3->unk64, s3->unk65, s3->unk66, 0xff);
            }
            for (s1 = 0; s1 < s3->unk60; s1++) {
                func_8070E8F0(&sp50, s3->unk0[s1].unkC);
                func_8070F2C8(0x400, 0x400, s3->unk0[s1].unkB, 0);
                tmp_a1 = (s3->unk0[s1].unk0 + 0x20);
                tmp_a2 = (s3->unk0[s1].unk4 + 0x18);
                func_8070F2FC(&sp50, 4*tmp_a1, 4*tmp_a2);
            }
        s3++;
        }
    }
    *arg0 = sp50;
}
#endif

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct8002C4D0;

s32 func_80025700(Struct8002C4D0 *, s32, s32, s32, s32);

extern Struct8002C4D0 D_8002C4D0[];
extern Struct8002C4D0 D_8002B9C0[];

// TODO: Appears to be a substruct of JetpacStruct from 0x30 onwards
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
} Struct80025A60;

extern f32 func_80027210();

void func_80025A60(Struct80025A60 *arg0) {
    s32 sp2C;

    sp2C = (arg0->unk8 / 14.0f) * 6.0f;
    if ((arg0->unk8 % 7) == 0) {
        if (func_80027210() < 0.5) {
            arg0->unkD = 0;
        } else {
            arg0->unkD = 0xFF;
        }
        if (func_80027210() < 0.5) {
            arg0->unkE = 0;
        } else {
            arg0->unkE = 0xFF;
        }
    }
    func_80025700(&D_8002B9C0[sp2C], arg0->unk0, arg0->unk4, &arg0->unkC, 0);
    arg0->unk8++;
}

typedef struct JetpacStruct5 {
    f32 unk0;
    u8 pad0[0x1C - 0x4];
    s32 unk1C;
} JetpacStruct5;

s32 func_80025B70(JetpacStruct5 *arg0) {
    return (((s32) arg0->unk0 + arg0->unk1C) / 2) % 4;
}

typedef struct JetpacStruct3 {
    f32 unk0;
    f32 unk4;
    u8 pad0[0x1C - 0x8];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
} JetpacStruct3;

void func_80027010(JetpacStruct3 *arg0);

void func_80025BB8(JetpacStruct3 *arg0, s32 arg1) {
    if ((arg1 == 0) && (arg0->unk30 != 0)) {
        arg0->unk0 = (s32)arg0->unk0 & 0xFFFE;
    } else if ((arg1 != 0) && (arg0->unk30 == 0)) {
        func_80027010(arg0);
    }
    arg0->unk1C = 0;
    arg0->unk24 = 0x10;
    arg0->unk30 = arg1;
}

typedef struct {
    s32 unk0;s32 unk4;s32 unk8;s32 unkC;
    s32 unk10[20];
    s32 unk18[20];
} Struct80025C40;

// TODO: Fix this up, yikes lmao
s32 *func_80025C40(Struct80025C40 *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->unk18[i * 20 + 0] == 0) {
            return &arg0->unk18[i * 20 - 5];
        }
    }
    return 0;
}

void func_80025CA0(JetpacStruct0 *arg0) {
    arg0->unk14 = 4;
    arg0->unk2C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025CB0.s")

// TODO: These are sus
s32 func_80028CF8(f32, f32, f32, f32, s32);
s32 func_8002A974(f32, f32, f32, f32);
s32 func_800283EC(f32, f32, f32, f32);

void func_80025CB0(JetpacStruct0 *arg0);

/*
void func_80025CB0(JetpacStruct0 *arg0) {
    f32 var_f0;
    f32 var_f12;
    u32 temp_a1;
    u32 temp_a2;
    u32 temp_v0;
    u32 var_v0;
    u32 var_v1;

    if ((arg0->unk14 == 3) && (arg0->unk40 < (u32)arg0->unk2C)) {
        func_80025CA0(arg0);
    }
    if ((arg0->unk14 == 4) && (arg0->unk24 == arg0->unk1C)) {
        arg0->unk14 = 0;
        arg0->unk2C = 0;
    }
    if (arg0->unk14) {
        if (arg0->unk14 == 3) {
            if (arg0->unk18) {
                var_f12 = arg0->unk1C;
                if (arg0->unk2C < 4) {
                    var_v1 = arg0->unk2C;
                } else {
                    var_v1 = 4;
                }
                var_f0 = ((f32)(var_v1 * 8)) + arg0->unk1C;
            } else {
                var_f0 = arg0->unk24;
                if (arg0->unk2C < 4) {
                    var_v1 = arg0->unk2C;
                } else {
                    var_v1 = 4;
                }
                var_f12 = arg0->unk24 - ((f32)(var_v1 * 8));
            }
            // TODO: These function calls are sus, have a look at m2c output again
            if (func_8002A974(var_f12, arg0->unk20, var_f0, arg0->unk28)) {
                func_80025CA0(arg0);
                return;
            }
            if (func_80028CF8(var_f12, arg0->unk20, var_f0, arg0->unk28, 0) >= 0) {
                func_80025CA0(arg0);
                return;
            }
            if (func_800283EC(var_f12, arg0->unk20, var_f0, arg0->unk28)) {
                func_80025CA0(arg0);
                return;
            }
            if (arg0->unk18) {
                arg0->unk1C -= 8;
                if (arg0->unk2C >= 0xD) {
                    arg0->unk24 -= 8;
                }
            } else {
                arg0->unk24 += 8;
                if (arg0->unk2C >= 0xD) {
                    arg0->unk1C += 8;
                }
            }
            arg0->unk2C++;
            return;
        }
        if (arg0->unk14 == 4) {
            if ((arg0->unk2C + ((arg0->unk24 - arg0->unk1C) / 8)) >= 0xD) {
                if (arg0->unk18 != 0) {
                    arg0->unk24 -= 8;
                } else {
                    arg0->unk1C += 8;
                }
            }
            arg0->unk2C++;
        }
    }
}
*/

void func_80025F48(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_t2;

    func_80025700(&D_8002C4D0[arg0], *arg1, arg3, arg4, arg5);
    *arg1 += arg2;
    if (*arg1 < 0) {
        *arg1 += 0x100;
    }
}

void func_80025FC4(JetpacStruct *arg0) {
    s32 sp6C;
    s32 var_a0;
    s32 var_s4;
    s32 temp_s5;
    s32 temp_s7;
    s32 temp_t7;
    s32 var_s1;
    s32 i;

    if (var_s4) {} // TODO: This fixes regalloc but it's an awful way to get a match...

    temp_s5 = arg0->unk18;
    var_s1 = 0;
    if (arg0->unk14 >= 2) {
        var_s4 = -8;
        temp_s7 = arg0->unk4;
        temp_t7 = (arg0->unk24 - arg0->unk1C) / 8;
        if (arg0->unk14 == 4) {
            var_s1 = arg0->unk2C;
        }
        if (temp_s5 != 0) {
            var_s4 = 8;
            sp6C = arg0->unk1C;
        } else {
            sp6C = arg0->unk24 - 8;
        }
        for (i = 0; i < temp_t7; i++) {
            if (var_s1 < 4) {
                var_a0 = 0;
            } else if (var_s1 < 9) {
                var_a0 = 1;
            } else {
                var_a0 = 2;
            }
            func_80025F48(var_a0, &sp6C, var_s4, temp_s7, &arg0->unk10, temp_s5);
            var_s1 += 1;
        }
    }
}

extern f32 D_8002EB30;
void func_80024E70(s32);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10[2];
    u8 unk12;
    u8 unk13;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 (*unk48)(s32);
    s32 unk4C;
} Struct80025C40_ret;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
    s32 unk24;
} Struct800260DC;

void func_800260DC(Struct800260DC *arg0) {
    Struct80025C40_ret *temp_v0;
    s32 temp_f4;
    s32 temp_f16_2;

    temp_v0 = func_80025C40(arg0);
    if (temp_v0 == NULL) {
        if ((ABS(arg0->unkC)) < D_8002EB30) {
            if (arg0->unk4 < 152.0f) {
                func_80024E70(6);
            }
        }
    } else {
        temp_v0->unk18 = arg0->unk18;
        if (temp_v0->unk18 != 0) {
            temp_v0->unk0 = ((s32)(arg0->unk0 + arg0->unk1C) / 8) * 8;
            temp_v0->unk8 = -8.0f;
        } else {
            temp_v0->unk0 = ((s32)(arg0->unk0 + arg0->unk24 + 6.0f) / 8) * 8;
            temp_v0->unk8 = 8.0f;
        }
        temp_v0->unk1C = temp_v0->unk0;
        temp_v0->unk24 = temp_v0->unk0;
        temp_v0->unk4 = arg0->unk4 + 10.0f;
        temp_v0->unkC = 0.0f;
        temp_f16_2 = temp_v0->unk4;
        temp_v0->unk28 = temp_f16_2 + 1;
        temp_v0->unk20 = temp_f16_2;
        temp_f4 = func_80027210() * 3.0f;
        temp_v0->unk10[0] = 0xFF;
        temp_v0->unk10[1] = 0xFF;
        if (temp_f4 < 2) {
            temp_v0->unk10[temp_f4] = 0;
        }
        temp_v0->unk12 = 0xFF;
        temp_v0->unk13 = 1;
        temp_v0->unk14 = 3;
        temp_v0->unk2C = 0;
        temp_v0->unk40 = (s32)(func_80027210() * 8.0f) + 0xD;
        temp_v0->unk48 = &func_80025CB0;
        temp_v0->unk4C = 0;
        func_80024E70(6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80026318.s")

void func_80025368(Competitor*);

extern JetpacPlayerStruct D_8002EC30;

typedef struct JetpacStruct10 {
    u8 pad0[0x2C];
    s32 unk2C;
} JetpacStruct10;

void func_80026A3C(JetpacStruct10 *arg0) {
    Competitor *player;
    s32 temp_v0;

    player = &D_8002EC30.player[D_8002EC30.player_index];
    if (arg0->unk2C < 0xE) {
        arg0->unk2C++;
        return;
    }
    player->lives--;
    func_80025368(player);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80026AB0.s")

extern Struct8002C4D0 D_8002C330;
extern Struct8002C4D0 D_8002C348[];

extern Struct8002C4D0 D_8002C3A8[];
extern f32 D_8002F054;
extern s32 D_8002F060;
extern s32 D_8002F064;
extern s32 D_8002F068;
extern s32 D_8002F080;
extern s32 D_8002F08C;
extern s32 D_8002F094;

/*
void func_80026AB0(void) {
    f32 temp_f2;
    f32 var_f0;
    s32 temp_v0;
    s32 var_a1;

    var_a1 = 1;
    if (D_8002F064 >= 2) {
        if (D_8002F064 == 4 && D_8002F094 >= 8) {
            var_a1 = 0;
        }
        temp_v0 = func_80025B70(&D_8002F050);
        var_f0 = D_8002F050;
        temp_f2 = D_8002F054;
        if (var_a1 != 0) {
            if (D_8002F080 == 0) {
                func_80025700(&D_8002C3A8[temp_v0], (s16)var_f0 & 0xFFFE, temp_f2, &D_8002F060, D_8002F068);
            } else {
                func_80025700(&D_8002C330, var_f0, temp_f2, &D_8002F060, D_8002F068);
                if (D_8002F068 == 0) {
                    if (temp_v0 == 4) {
                        var_f0 -= 1.0f;
                    }
                    var_f0 -= 3.0f;
                } else {
                    if (temp_v0 == 4) {
                        var_f0 += 1.0f;
                    }
                    var_f0 += 10.0f;
                }
                func_80025700(&D_8002C348[temp_v0], var_f0, temp_f2 + 18.0f, &D_8002F060, D_8002F068);
            }
        }
        if (D_8002F094 < 0xE) {
            func_80025A60(&D_8002F08C);
        }
    }
}
*/

void func_80025FC4(JetpacStruct*);
extern JetpacStruct D_8002F09C[]; // At least 4 big

void func_80026CA4(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_80025FC4(&D_8002F09C[i]);
    }
}

extern s32 D_8002F064;

int func_80026FE0(void);
void func_80026318(s32*);
extern Struct80025C40_ret D_8002F050[4];

void func_80026CEC(void) {
    Struct80025C40_ret *temp_a0;
    s32 i;

    for (i = 0; i < 4; i++) {
        temp_a0 = &D_8002F050[i].unk4C;
        if (D_8002F050[i + 1].unk44 != 0) {
            temp_a0->unk48(temp_a0);
        }
    }
}

void func_80026D48(void) {
    s32 phi_v0;

    if (!func_80026FE0()) {
        phi_v0 = D_8002F064;
        if (phi_v0 == 1) {
            func_80024E70(3);
            phi_v0 = 3;
        }
        D_8002F064 = phi_v0;
        if (phi_v0 == 3) {
            func_80026318(&D_8002F050);
        }
        phi_v0 = D_8002F064;
        if (phi_v0 == 4) {
            func_80026A3C(&D_8002F050);
        }
    }
}

extern JetpacStruct D_8002C518;
extern s32 D_8002F084;
extern s32 D_8002F088;

void func_80026DC8(void) {
    s32 i;
    JetpacStruct sp1C;

    sp1C = D_8002C518;
    D_8002EC30.unk428 = 0.0f;
    D_8002EC30.unk42C = 0.0f;
    D_8002EC30.unk430 = 0xFF;
    D_8002EC30.unk431 = 0xFF;
    D_8002EC30.unk432 = 0xFF;
    D_8002EC30.unk433 = 1;
    D_8002EC30.unk434 = 1;
    D_8002EC30.unk44C = 0;
    D_8002EC30.unk438 = 0;
    D_8002EC30.unk464 = 0xE;
    D_8002EC30.unk468 = 0xFF;
    D_8002EC30.unk46B = 1;
    D_8002EC30.unk440 = 0;
    D_8002EC30.unk43C = 0;
    D_8002EC30.unk444 = 0x10;D_8002EC30.unk448 = 0x18;

    D_8002EC30.unk450 = 1;
    D_8002EC30.unk420 = 126.0f;
    D_8002EC30.unk424 = 160.0f;
    func_80025BB8(&D_8002F050, 0);
    D_8002F084 = 3;
    D_8002F088 = 4;
    for (i = 0; i < 4; i++) {
        D_8002F09C[i] = sp1C;
    }
}

extern s32 D_8002F07C;

int func_80026FE0(void) {
    return D_8002F064 == 1 && D_8002F07C < 0xB4;
}

void func_80027010(JetpacStruct3 *arg0) {
    if (arg0->unk44 >= 0xE) {
        arg0->unk44 = 0;
        arg0->unk3C = (s32)arg0->unk0 & 0xFFF8;
        arg0->unk40 = arg0->unk4 + 7.0f;
    }
}
