#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8070F2FC(Gfx **arg0, s16 arg1, s16 arg2);
extern void func_8070E8F0(Gfx**, Sprite*);
extern void func_8070F2C8(s32, s32, s32, u8);

typedef struct jetpac_struct_0 {
    u8  pad0[0x14];
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
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

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025A60.s")

typedef struct JetpacStruct5 {
    f32 unk0;
    u8 pad0[0x1C - 0x4];
    s32 unk1C;
} JetpacStruct5;

s32 func_80025B70(JetpacStruct5 *arg0) {
    return (((s32) arg0->unk0 + arg0->unk1C) / 2) % 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025C40.s")

/*
// TODO: Sorry to whoever matched this, I messed up
s32 *func_80025C40(JetpacStruct1 *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0[i].unk60 == 0) {
            return &arg0[i].unk60;
        }
    }
    return 0;
}
*/

void func_80025CA0(JetpacStruct0 *arg0) {
    arg0->unk14 = 4;
    arg0->unk2C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80025FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_800260DC.s")

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

void func_80025FC4(JetpacStruct*);
extern JetpacStruct D_8002F09C;
extern JetpacStruct D_8002F1DC;

void func_80026CA4(void) {
    JetpacStruct *phi_s0;
    JetpacStruct *phi_s1;
    phi_s1 = (phi_s0 = &D_8002F09C) + 4;

    do {
        func_80025FC4(phi_s0);
        phi_s0++;
    } while (phi_s0 != phi_s1);
}

//function pointer from struct
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80026CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80026D48.s")

extern s32 D_8002F064;

/*
int func_80026FE0(void);
void func_80026318(s32*);
void func_80024E70(s32);
extern JetpacStruct10 D_8002F050;

// TODO: Very close, but wtf
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
        if (D_8002F064 == 4) {
            func_80026A3C(&D_8002F050);
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_1460/func_80026DC8.s")

extern s32 D_8002F07C;

int func_80026FE0(void) {
    return D_8002F064 == 1 && D_8002F07C < 0xB4;
}

typedef struct JetpacStruct3 {
    f32 unk0;
    f32 unk4;
    u8 pad0[0x3C - 0x8];
    s32 unk3C;
    s32 unk40;
    s32 unk44;
} JetpacStruct3;

void func_80027010(JetpacStruct3 *arg0) {
    if (arg0->unk44 >= 0xE) {
        arg0->unk44 = 0;
        arg0->unk3C = (s32) ((s32) arg0->unk0 & 0xFFF8);
        arg0->unk40 = (s32) (arg0->unk4 + 7.0f);
    }
}
