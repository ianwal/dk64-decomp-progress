#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80748300;

extern f32 *D_global_asm_8076A0B4;
extern f32 *D_global_asm_8076A0B8;
extern f32 *D_global_asm_8076A0BC;
extern f32 *D_global_asm_8076A0C0; // pointer to an array of floats
extern f32 *D_global_asm_8076A0C4;
extern f32 *D_global_asm_8076A0C8;

extern s32 D_global_asm_807F6C28;
extern s16 D_global_asm_807F7EC8;

extern u8 D_global_asm_807F7EF8;
extern f32 D_global_asm_807F7ECC;
extern f32 D_global_asm_807F7ED0;
extern f32 D_global_asm_807F7ED4;
extern f32 D_global_asm_807F7ED8;
extern f32 D_global_asm_807F7EDC;
extern f32 D_global_asm_807F7EE0;
extern f32 D_global_asm_807F7EE4;
extern f32 D_global_asm_807F7EE8;
extern s16 D_global_asm_807F7EFA;
extern s16 D_global_asm_807F7EFC;
extern s16 D_global_asm_807F7EFE;

void func_global_asm_806595F0(u8 arg0) {
    D_global_asm_807F7EF8 = arg0;
}

void func_global_asm_80659600(s16 arg0) {
    D_global_asm_807F7EFA = arg0;
}

void func_global_asm_80659610(s16 arg0) {
    D_global_asm_807F7EFC = arg0;
}

void func_global_asm_80659620(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3) {
    *arg0 = D_global_asm_8076A0B4[arg3];
    *arg1 = D_global_asm_8076A0B8[arg3];
    *arg2 = D_global_asm_8076A0BC[arg3];
}

void func_global_asm_80659670(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    u8 var_v1;
    s32 iChunk;

    if (D_global_asm_807F6C28 <= 0) {
        var_v1 = 1;
    } else {
        var_v1 = D_global_asm_807F6C28;
    }
    if (arg3 != -1) {
        if (arg3 < var_v1) {
            D_global_asm_8076A0B4[arg3] = arg0 <= 1.0f ? arg0 : 1.0f;
            D_global_asm_8076A0B8[arg3] = arg1 <= 1.0f ? arg1 : 1.0f;
            D_global_asm_8076A0BC[arg3] = arg2 <= 1.0f ? arg2 : 1.0f;
        }
    } else {
        for (iChunk = 0; iChunk < var_v1; iChunk++) {
            D_global_asm_8076A0B4[iChunk] = arg0 <= 1.0f ? arg0 : 1.0f;
            D_global_asm_8076A0B8[iChunk] = arg1 <= 1.0f ? arg1 : 1.0f;
            D_global_asm_8076A0BC[iChunk] = arg2 <= 1.0f ? arg2 : 1.0f;
        }
    }
}

void func_global_asm_8065996C(s16 arg0) {
    u8 max;
    s32 i;

    max = MAX(1, D_global_asm_807F6C28);
    if (arg0 != -1) {
        if (arg0 < max) {
            D_global_asm_8076A0B4[arg0] = D_global_asm_8076A0C0[arg0];
            D_global_asm_8076A0B8[arg0] = D_global_asm_8076A0C4[arg0];
            D_global_asm_8076A0BC[arg0] = D_global_asm_8076A0C8[arg0];
        }
    } else {
        for (i = 0; i < max; i++) {
            D_global_asm_8076A0B4[i] = D_global_asm_8076A0C0[i];
            D_global_asm_8076A0B8[i] = D_global_asm_8076A0C4[i];
            D_global_asm_8076A0BC[i] = D_global_asm_8076A0C8[i];
        }
    }
}

void func_global_asm_80659DB0(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    u8 phi_v1;
    u8 iChunk;

    if (D_global_asm_807F6C28 <= 0) {
        phi_v1 = 1;
    } else {
        phi_v1 = D_global_asm_807F6C28;
    }
    if (arg3 != -1) {
        D_global_asm_8076A0C0[arg3] = arg0 <= 1.0f ? arg0 : 1.0f;
        D_global_asm_8076A0C4[arg3] = arg1 <= 1.0f ? arg1 : 1.0f;
        D_global_asm_8076A0C8[arg3] = arg2 <= 1.0f ? arg2 : 1.0f;
    } else {
        for (iChunk = 0; iChunk < phi_v1; iChunk++) {
            D_global_asm_8076A0C0[iChunk] = arg0 <= 1.0f ? arg0 : 1.0f;
            D_global_asm_8076A0C4[iChunk] = arg1 <= 1.0f ? arg1 : 1.0f;
            D_global_asm_8076A0C8[iChunk] = arg2 <= 1.0f ? arg2 : 1.0f;
        }
    }
}

void func_global_asm_80659F7C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4) {
    s32 i;
    u8 var_v1;

    var_v1 = MAX(1, D_global_asm_807F6C28);
    if (arg4 != -1) {
        if (arg4 < var_v1) {
            D_global_asm_8076A0B4[arg4] = ((D_global_asm_8076A0C0[arg4] - arg0) * arg3) + arg0;
            D_global_asm_8076A0B8[arg4] = ((D_global_asm_8076A0C4[arg4] - arg1) * arg3) + arg1;
            D_global_asm_8076A0BC[arg4] = ((D_global_asm_8076A0C8[arg4] - arg2) * arg3) + arg2;
        }
    } else {
        for (i = 0; i < var_v1; i++) {
            D_global_asm_8076A0B4[i] = ((D_global_asm_8076A0C0[i] - arg0) * arg3) + arg0;
            D_global_asm_8076A0B8[i] = ((D_global_asm_8076A0C4[i] - arg1) * arg3) + arg1;
            D_global_asm_8076A0BC[i] = ((D_global_asm_8076A0C8[i] - arg2) * arg3) + arg2;
        }
    }
}

void func_global_asm_8065A570(void) {
    D_global_asm_807F7ECC = func_global_asm_80612D10(0.4363323152f);
    D_global_asm_807F7ED0 = func_global_asm_80612D10(1.134464025f);
    D_global_asm_807F7ED4 = 1.0f / (D_global_asm_807F7ECC - D_global_asm_807F7ED0);
    D_global_asm_807F7ED8 = D_global_asm_807F7ECC;
    D_global_asm_807F7EDC = D_global_asm_807F7ED0;
    D_global_asm_807F7EE0 = D_global_asm_807F7ED4;
    D_global_asm_807F7EE4 = 25.0f;
    D_global_asm_807F7EE8 = 65.0f;
    D_global_asm_80748300 = 0;
    D_global_asm_807F7EF8 = 0;
    D_global_asm_807F7EFA = -1;
    D_global_asm_807F7EFC = 700;
    D_global_asm_807F7EFE = 600;
}

void func_global_asm_8065A648(void) {
    D_global_asm_80748300 = 0;
}

void func_global_asm_8065A654(void) {
    D_global_asm_807F7EC8 = 0;
}

void func_global_asm_8065A660(f32 arg0, f32 arg1) {
    D_global_asm_807F7EE4 = arg0;
    D_global_asm_807F7EE8 = arg1;
    D_global_asm_807F7ED8 = func_global_asm_80612D10(arg0 * (MATH_PI_F / 180.0f));
    D_global_asm_807F7EDC = func_global_asm_80612D10(arg1 * (MATH_PI_F / 180.0f));
    D_global_asm_807F7EE0 = 1.0f / (D_global_asm_807F7ED8 - D_global_asm_807F7EDC);
}

void func_global_asm_8065A6F8(u16 arg0) {
    D_global_asm_807F7EFE = arg0;
}

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
    s8 unk3A;
    s8 unk3B;
} Struct807F7500;

extern Struct807F7500 D_global_asm_807F7500[];
extern f32 D_global_asm_807F7ED0;
extern f32 D_global_asm_807F7ED4;
extern f32 D_global_asm_807F7ED8;
extern f32 D_global_asm_807F7EDC;
extern f32 D_global_asm_807F7EE0;
extern f32 D_global_asm_807F7EE4;

void createLight(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA) {
    if (D_global_asm_80748300 == 0x10) return;
    D_global_asm_807F7500[D_global_asm_80748300].unk34 = D_global_asm_807F7EFE;
    D_global_asm_807F7500[D_global_asm_80748300].unk3A = D_global_asm_807F7EF8;
    D_global_asm_807F7500[D_global_asm_80748300].unk30 = D_global_asm_807F7EFA;
    D_global_asm_807F7500[D_global_asm_80748300].unk32 = D_global_asm_807F7EFC;
    D_global_asm_807F7500[D_global_asm_80748300].unk8 = D_global_asm_807F7EE8;
    D_global_asm_807F7500[D_global_asm_80748300].unk0 = D_global_asm_807F7EE4;
    D_global_asm_807F7500[D_global_asm_80748300].unk18 = arg0;
    D_global_asm_807F7500[D_global_asm_80748300].unk1C = arg1;
    D_global_asm_807F7500[D_global_asm_80748300].unkC = D_global_asm_807F7EDC;
    D_global_asm_807F7500[D_global_asm_80748300].unk4 = D_global_asm_807F7ED8;
    D_global_asm_807F7500[D_global_asm_80748300].unk39 = arg7;
    D_global_asm_807F7500[D_global_asm_80748300].unk10 = D_global_asm_807F7EE0;
    D_global_asm_807F7500[D_global_asm_80748300].unk20 = arg2;
    D_global_asm_807F7500[D_global_asm_80748300].unk24 = arg3;
    D_global_asm_807F7500[D_global_asm_80748300].unk28 = arg4;
    D_global_asm_807F7500[D_global_asm_80748300].unk2C = arg5;
    D_global_asm_807F7500[D_global_asm_80748300].unk14 = arg6;
    D_global_asm_807F7500[D_global_asm_80748300].unk36 = arg8;
    D_global_asm_807F7500[D_global_asm_80748300].unk37 = arg9;
    D_global_asm_807F7500[D_global_asm_80748300].unk38 = argA;
    D_global_asm_80748300++;
    D_global_asm_807F7ED8 = D_global_asm_807F7ECC;
    D_global_asm_807F7EDC = D_global_asm_807F7ED0;
    D_global_asm_807F7EE0 = D_global_asm_807F7ED4;
    D_global_asm_807F7EF8 = 0;
    D_global_asm_807F7EFA = -1;
    D_global_asm_807F7EFC = 700;
    D_global_asm_807F7EFE = 600;
    D_global_asm_807F7EE4 = 25.0f;
    D_global_asm_807F7EE8 = 65.0f;
}

// Huge, close considering size
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065A884.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s16 unk30;
    s16 unk32;
} Struct8065C240;

s32 func_global_asm_8065C240(Struct8065C240 *);
extern s32 D_global_asm_80748304;
extern s32 D_global_asm_80748308;

/*
void func_global_asm_8065A884(void) {
    s32 i; // 154
    s32 j;
    s32 sp14C;
    Actor *temp_s0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 dz; // 13c
    f32 dy; // 138
    f32 dx; // 134
    f32 temp_f20;
    f32 temp_f18; // 12C
    f32 temp_f16; // 128
    f32 temp_f12; // 124
    f32 temp_f22;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2_5;
    f32 temp_f30;
    f32 var_f24_3; // 10C
    s16 var_s3;
    u8 spC8[0x40];
    f32 spC4;
    f32 spC0;
    f32 var_f20_2;
    f32 var_f22_3;
    f32 var_f2;
    f32 v;
    f32 sq_temp;

    sp14C = 0;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        spC8[i] = FALSE;
    }
    for (i = 0; (i < D_global_asm_80748300) && (cc_number_of_players < 3); i++) {
        if ((func_global_asm_8065C240(&D_global_asm_807F7500[i])) && (sp14C < 0xC)) {
            sp14C++;
            for (j = 0; j < D_global_asm_807FBB34; j++) {
                temp_s0 = D_global_asm_807FB930[j].unk0;
                if ((temp_s0->object_properties_bitfield & 0x2000)) continue;
                switch (D_global_asm_807F7500[i].unk39) {
                    case 1:
                        dx = D_global_asm_807F7500[i].unk24 - D_global_asm_807F7500[i].unk18;
                        dy = D_global_asm_807F7500[i].unk28 - D_global_asm_807F7500[i].unk1C;
                        dz = D_global_asm_807F7500[i].unk2C - D_global_asm_807F7500[i].unk20;
                        sq_temp = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
                        if (sq_temp == 0.0f) {
                            sq_temp = 0.1f;
                        }
                        temp_f26 = dx / sq_temp;
                        temp_f28 = dy / sq_temp;
                        temp_f30 = dz / sq_temp;
                        dx = temp_s0->x_position - D_global_asm_807F7500[i].unk18;
                        dy = temp_s0->y_position - D_global_asm_807F7500[i].unk1C;
                        dz = temp_s0->z_position - D_global_asm_807F7500[i].unk20;
                        sq_temp = sqrtf(SQ(dz) + (SQ(dx) + SQ(dy)));
                        if (sq_temp == 0.0f) {
                            sq_temp = 0.1f;
                        }
                        temp_f12 = (dx / sq_temp) * temp_f26;
                        temp_f16 = (dy / sq_temp) * temp_f28;
                        temp_f18 = (dz / sq_temp) * temp_f30;
                        var_f22_3 = temp_f12 + temp_f16 + temp_f18;
                        if (var_f22_3 < 0.0f) {
                            var_f22_3 = 0.0f;
                        }
                        if (D_global_asm_807F7500[i].unkC <= var_f22_3) {
                            if (D_global_asm_807F7500[i].unk4 <= var_f22_3) {
                                var_f22_3 = 1.0f;
                            } else {
                                var_f22_3 = (var_f22_3 - D_global_asm_807F7500[i].unkC) * D_global_asm_807F7500[i].unk10;
                            }
                            addActorRecolor(temp_s0, 
                                D_global_asm_807F7500[i].unk18, 
                                D_global_asm_807F7500[i].unk1C, 
                                D_global_asm_807F7500[i].unk20, 
                                0xFF, 
                                D_global_asm_807F7500[i].unk36 * var_f22_3, 
                                D_global_asm_807F7500[i].unk37 * var_f22_3, 
                                D_global_asm_807F7500[i].unk38 * var_f22_3, 0U);
                            if ((temp_s0->object_properties_bitfield & 0x01000000) && (temp_s0->object_properties_bitfield & 4)) {
                                sq_temp = sqrtf(
                                    SQ(D_global_asm_807F7500[i].unk18 - temp_s0->x_position) +
                                    SQ(D_global_asm_807F7500[i].unk20 - temp_s0->z_position) 
                                    );
                                var_f2 = sq_temp != 0.0f ? sq_temp : 0.001f;
                                var_f24_3 = (D_global_asm_807F7500[i].unk1C - temp_s0->y_position) / var_f2;
                                if (!(var_f24_3 > 0.0f)) {
                                    var_f24_3 = -var_f24_3;
                                }
                                if (var_f24_3 == 0.0f) {
                                    var_f24_3 = 0.1f;
                                }
                                var_f24_3 = (temp_s0->unk15E * 0.4f) / var_f24_3;
                                var_s3 = func_global_asm_80665DE0(
                                    D_global_asm_807F7500[i].unk18,
                                    D_global_asm_807F7500[i].unk20,
                                    temp_s0->x_position,
                                    temp_s0->z_position);
                                if (temp_s0->animation_state != NULL) {
                                    spC0 = temp_s0->animation_state->scale_x;
                                    spC4 = temp_s0->animation_state->scale_z;
                                } else {
                                    spC0 = 0.15f;
                                    spC4 = 0.15f;
                                }
                                v = temp_s0->shadow_opacity / 255.0;
                                v = D_global_asm_80748304 * v;
                                v *= var_f22_3;
                                func_global_asm_8065D254(
                                    temp_s0,
                                    0x3C9,
                                    0x40,
                                    0x40,
                                    spC0 * temp_s0->unk16E,
                                    spC4 * temp_s0->unk16F,
                                    1, 0x64,
                                    v,
                                    var_s3 + 0xC00, var_f24_3 * var_f22_3);
                                spC8[j] = TRUE;
                            }
                        }
                        break;
                    case 0:
                        var_f22_3 = sqrtf(
                            SQ(D_global_asm_807F7500[i].unk18 - temp_s0->x_position) + 
                            SQ(D_global_asm_807F7500[i].unk1C - temp_s0->y_position) +
                            SQ(D_global_asm_807F7500[i].unk20 - temp_s0->z_position) 
                        );
                        var_f22_3 -= temp_s0->unkCE;
                        if (var_f22_3 < 0.0) {
                            var_f22_3 = 0.1f;
                        }
                        temp_f20 = D_global_asm_807F7500[i].unk14 * 1.3f;
                        if ((temp_s0->object_properties_bitfield & 0x01000000) && (var_f22_3 < temp_f20) && (temp_s0->object_properties_bitfield & 4)) {
                            sq_temp = sqrtf(
                                SQ(D_global_asm_807F7500[i].unk18 - temp_s0->x_position) +
                                SQ(D_global_asm_807F7500[i].unk20 - temp_s0->z_position));
                            if (sq_temp == 0.0f) {
                                sq_temp = 1.0f;
                            }
                            var_f24_3 = (D_global_asm_807F7500[i].unk1C - temp_s0->y_position) / sq_temp;
                            if (!(var_f24_3 > 0.0f)) {
                                var_f24_3 = -var_f24_3;
                            }
                            if (var_f24_3 == 0.0f) {
                                var_f24_3 = 0.1f;
                            }
                            var_f24_3 = (temp_s0->unk15E * 0.4f) / var_f24_3;
                            var_s3 = func_global_asm_80665DE0(D_global_asm_807F7500[i].unk18, D_global_asm_807F7500[i].unk20, temp_s0->x_position, temp_s0->z_position);
                            if (var_f24_3 > 10.0f) {
                                var_f24_3 = 10.0f;
                            }
                            if (temp_s0->animation_state != NULL) {
                                spC0 = temp_s0->animation_state->scale_x;
                                spC4 = temp_s0->animation_state->scale_z;
                            } else {
                                spC0 = 0.15f;
                                spC4 = 0.15f;
                            }
                            spC8[j] = TRUE;
                        }
                        temp_f0_10 = temp_f20 / 3.0f;
                        if (var_f22_3 < temp_f0_10) {
                            addActorRecolor(temp_s0,
                                D_global_asm_807F7500[i].unk18,
                                D_global_asm_807F7500[i].unk1C,
                                D_global_asm_807F7500[i].unk20, 
                                0xFFU, 
                                D_global_asm_807F7500[i].unk36,
                                D_global_asm_807F7500[i].unk37, 
                                D_global_asm_807F7500[i].unk38, 0U);
                            if ((temp_s0->object_properties_bitfield & 0x01000000) && (temp_s0->object_properties_bitfield & 4)) {
                                v = temp_s0->shadow_opacity / 255.0;
                                v = D_global_asm_80748304 * v;
                                func_global_asm_8065D254(
                                    temp_s0,
                                    0x3C9,
                                    0x40,
                                    0x40,
                                    spC0 * temp_s0->unk16E,
                                    spC4 * temp_s0->unk16F,
                                    1, 0x64,
                                    v, var_s3 + 0xC00, var_f24_3);
                            }
                        } else {
                            temp_f22 = var_f22_3 - temp_f0_10;
                            temp_f2_5 = temp_f20 - temp_f0_10;
                            if (temp_f22 < temp_f2_5) {
                                temp_f0_11 = 1.0f - (temp_f22 / temp_f2_5);
                                addActorRecolor(
                                    temp_s0, 
                                    D_global_asm_807F7500[i].unk18, 
                                    D_global_asm_807F7500[i].unk1C, 
                                    D_global_asm_807F7500[i].unk20, 
                                    0xFF, 
                                    D_global_asm_807F7500[i].unk36 * temp_f0_11, 
                                    D_global_asm_807F7500[i].unk37 * temp_f0_11, 
                                    D_global_asm_807F7500[i].unk38 * temp_f0_11, 0U);
                                if ((temp_s0->object_properties_bitfield & 0x01000000) && (temp_s0->object_properties_bitfield & 4)) {
                                    v = D_global_asm_80748304 * temp_f0_11 * (f32) (temp_s0->shadow_opacity / 255.0);
                                    func_global_asm_8065D254(
                                        temp_s0, 0x3C9, 0x40, 0x40, 
                                        spC0 * temp_s0->unk16E, 
                                        spC4 * temp_s0->unk16F, 
                                        1, 0x64,
                                        v, var_s3 + 0xC00,
                                        var_f24_3 * temp_f0_11);
                                }
                            }
                        }
                        break;
                }
            }
        }
    }
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        if (!spC8[i]) {
            temp_s0 = D_global_asm_807FB930[i].unk0;
            if ((temp_s0->object_properties_bitfield & 0x01000000) && (temp_s0->object_properties_bitfield & 4)) {
                if (temp_s0->animation_state) {
                    spC0 = temp_s0->animation_state->scale_x;
                    spC4 = temp_s0->animation_state->scale_z;
                } else {
                    spC0 = 0.15f;
                    spC4 = 0.15f;
                }
                v = D_global_asm_80748308 * (f32) (temp_s0->shadow_opacity / 255.0);
                func_global_asm_8065D254(
                    temp_s0, 0x3C9, 0x40, 0x40, 
                    spC0 * temp_s0->unk16E, 
                    spC4 * temp_s0->unk16F,
                    1, 0x64,
                    v, 0, 1.0f);
            }
        }
    }
}
*/


// Matrix stuff?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065BAA0.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    u8 unk3E;
    u8 unk3F; // Used
} Struct807F78C0;

extern Struct807F78C0 D_global_asm_807F78C0[];
extern Struct807F78C0 D_global_asm_807F7BC8[];

void func_global_asm_8065BE74(s16 arg0) {
    s32 i;
    u8 temp2;

    if (D_global_asm_807F7EC8 == 0xC) {
        return;
    }
    temp2 = D_global_asm_807F78C0[arg0].unk3F;
    for (i = 0; i < D_global_asm_807F7EC8; i++) {
        if (temp2 == D_global_asm_807F7BC8[i].unk3F) {
            return;
        }
    }
    memcpy(&D_global_asm_807F7BC8[D_global_asm_807F7EC8++], &D_global_asm_807F78C0[arg0], sizeof(Struct807F78C0));
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065BF18.s")

extern u8 D_global_asm_80750AB4;

s32 func_global_asm_8065C240(Struct8065C240 *arg0) {
    f32 dz, dy, dx;
    s32 i;

    for (i = 0; i < D_global_asm_80750AB4; i++) {
        if (character_change_array[i].does_player_exist != 0) {
            dz = arg0->unk20 - character_change_array[i].look_at_eye_z;
            dx = arg0->unk18 - character_change_array[i].look_at_eye_x;
            dy = arg0->unk1C - character_change_array[i].look_at_eye_y;
            if (sqrtf(SQ(dz) + (SQ(dx) + SQ(dy))) < arg0->unk32) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// TODO: Decent progress made
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065C334.s")

/*
void func_global_asm_8065C334(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s8 *arg4, s8 *arg5, s8 *arg6, s16 arg7) {
    f32 sp64;
    f32 sp5C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f12;
    f32 var_f22;
    f32 var_f24;
    f32 var_f26;
    f32 var_f2;
    f32 var_f6;
    f64 temp_f30;
    s32 temp_v1;
    s32 i;

    if (func_global_asm_80651B64(arg7) == 0) {
        *arg6 = 0xFF;
        *arg5 = 0xFF;
        *arg4 = 0xFF;
        return;
    }
    temp_v1 = D_global_asm_807F7EC8;
    if (temp_v1 == 0) {
        *arg4 = D_global_asm_8076A0B4[arg7] * 255.0f;
        *arg5 = D_global_asm_8076A0B8[arg7] * 255.0f;
        *arg6 = D_global_asm_8076A0BC[arg7] * 255.0f;
        return;
    }
    var_f24 = D_global_asm_8076A0B8[arg7];
    var_f22 = D_global_asm_8076A0B4[arg7];
    var_f26 = D_global_asm_8076A0BC[arg7];
    if (temp_v1 > 0) {
        temp_f30 = 300.0;
        for (i = 0; i < D_global_asm_807F7EC8; i++) {
            switch (D_global_asm_807F7BC8[i].unk3E) {
                case 1:
                    temp_f2 = arg0 - (D_global_asm_807F7BC8[i].unk38 / 3);
                    temp_f14 = arg1 - (D_global_asm_807F7BC8[i].unk3A / 3);
                    temp_f16 = arg2 - (D_global_asm_807F7BC8[i].unk3C / 3);
                    sp64 = temp_f14;
                    temp_f0 = sqrtf((temp_f16 * temp_f16) + ((temp_f2 * temp_f2) + (temp_f14 * temp_f14)));
                    var_f12 = temp_f0;
                    if (temp_f0 == 0.0f) {
                        var_f12 = 0.1f;
                    }
                    temp_f18 = temp_f2 / var_f12;
                    sp5C = temp_f16 / var_f12;
                    temp_f20 = sp64 / var_f12;
                    var_f0 = (D_global_asm_807F7BC8[i].unk14 * sp5C) + ((temp_f18 * D_global_asm_807F7BC8[i].unkC) + (temp_f20 * D_global_asm_807F7BC8[i].unk10));
                    if (var_f0 < 0.0f) {
                        var_f0 = 0.0f;
                    }
                    if (D_global_asm_807F7BC8[i].unk0 <= var_f0) {
                        if (D_global_asm_807F7BC8[i].unk4 <= var_f0) {
                            var_f0_2 = 1.0f;
                        } else {
                            var_f0_2 = (var_f0 - D_global_asm_807F7BC8[i].unk0) * D_global_asm_807F7BC8[i].unk8;
                        }
                        if (temp_f30 < var_f12) {
                            if (1100.0 < var_f12) {
                                var_f0_2 = 0.0f;
                            } else {
                                var_f0_2 = var_f0_2 * (1.0 - ((var_f12 - temp_f30) / 800.0));
                            }
                        }
                        var_f22 += D_global_asm_807F7BC8[i].unk2C * var_f0_2;
                        var_f24 += D_global_asm_807F7BC8[i].unk30 * var_f0_2;
                        var_f26 += D_global_asm_807F7BC8[i].unk34 * var_f0_2;
                    }
                    break;
                case 0:
                    temp_f0_2 = (D_global_asm_807F7BC8[i].unk3C / 3) - arg2;
                    temp_f2_4 = (D_global_asm_807F7BC8[i].unk38 / 3) - arg0;
                    temp_f14_2 = (D_global_asm_807F7BC8[i].unk3A / 3) - arg1;
                    temp_f0_3 = sqrtf((temp_f0_2 * temp_f0_2) + ((temp_f2_4 * temp_f2_4) + (temp_f14_2 * temp_f14_2)));
                    var_f2 = temp_f0_3 - arg3;
                    if (temp_f0_3 <= arg3) {
                        var_f2 = 0.1f;
                    }
                    temp_f0_4 = D_global_asm_807F7BC8[i].unk28 / 3.0f;
                    if (var_f2 < temp_f0_4) {
                        var_f6 = D_global_asm_807F7BC8[i].unk34;
                        var_f22 += D_global_asm_807F7BC8[i].unk2C;
                        var_f24 += D_global_asm_807F7BC8[i].unk30;
                    } else {
                        temp_f2_5 = var_f2 - temp_f0_4;
                        temp_f12 = ((1.0f / D_global_asm_807F7BC8[i].unk24) / 3.0f) - temp_f0_4;
                        if (temp_f2_5 < temp_f12) {
                            temp_f0_5 = 1.0f - (temp_f2_5 / temp_f12);
                            var_f22 += D_global_asm_807F7BC8[i].unk2C * temp_f0_5;
                            var_f6 = D_global_asm_807F7BC8[i].unk34 * temp_f0_5;
                            var_f24 += D_global_asm_807F7BC8[i].unk30 * temp_f0_5;
                        }
                    }
                    var_f26 += var_f6;
                    break;
            }
        }
    }
    if (var_f22 > 1.0f) {
        var_f22 = 1.0f;
    }
    if (var_f24 > 1.0f) {
        var_f24 = 1.0f;
    }
    if (var_f26 > 1.0f) {
        var_f26 = 1.0f;
    }
    *arg4 = var_f22 * 255.0f;
    *arg5 = var_f24 * 255.0f;
    *arg6 = var_f26 * 255.0f;
}
*/
