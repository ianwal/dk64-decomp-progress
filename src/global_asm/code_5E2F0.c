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

// RODATA
/*
const f32 D_global_asm_80758CA0 = 0.4363323152f;
const f32 D_global_asm_80758CA4 = 1.134464025f;
const f32 D_global_asm_80758CA8 = 0.01745329238f;
const f32 D_global_asm_80758CAC = 0.01745329238f;
const f32 D_global_asm_80758CB0 = 0.1000000015f;
const f32 D_global_asm_80758CB4 = 0.1000000015f;
const f32 D_global_asm_80758CB8 = 0.001000000047f;
const f32 D_global_asm_80758CBC = 0.1000000015f;
const f32 D_global_asm_80758CC0 = 0.400000006f;
const f32 D_global_asm_80758CC4 = 0.150000006f;
const f32 D_global_asm_80758CC8 = 0.150000006f;
const f64 D_global_asm_80758CD0 = 255.0;
const f32 D_global_asm_80758CD8 = 0.1000000015f;
const f32 D_global_asm_80758CDC = 1.299999952f;
const f32 D_global_asm_80758CE0 = 0.1000000015f;
const f32 D_global_asm_80758CE4 = 0.400000006f;
const f32 D_global_asm_80758CE8 = 0.150000006f;
const f32 D_global_asm_80758CEC = 0.150000006f;
const f64 D_global_asm_80758CF0 = 255.0;
const f64 D_global_asm_80758CF8 = 255.0;
const f32 D_global_asm_80758D00 = 0.150000006f;
const f64 D_global_asm_80758D08 = 255.0;
const f32 D_global_asm_80758D10 = 0.1000000015f;
const f64 D_global_asm_80758D18 = 255.0;
const f32 D_global_asm_80758D20 = 1.299999952f;
const f32 D_global_asm_80758D24 = 0.200000003f;
const f64 D_global_asm_80758D28 = 300.0;
const f32 D_global_asm_80758D30 = 0.1000000015f;
const f64 D_global_asm_80758D38 = 1100.0;
const f32 D_global_asm_80758D40 = 0.1000000015f;
*/
// RODATA END

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_80659F7C.s")

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
    D_global_asm_807F7ED8 = func_global_asm_80612D10(arg0 * 0.01745329238f);
    D_global_asm_807F7EDC = func_global_asm_80612D10(arg1 * 0.01745329238f);
    D_global_asm_807F7EE0 = 1.0f / (D_global_asm_807F7ED8 - D_global_asm_807F7EDC);
}

void func_global_asm_8065A6F8(u16 arg0) {
    D_global_asm_807F7EFE = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/createLight.s")

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
    s8 unk36;
    s8 unk37;
    s8 unk38;
    s8 unk39;
    s16 unk3A;
} Struct807F7500;

extern Struct807F7500 D_global_asm_807F7500[];
extern f32 D_global_asm_807F7ED0;
extern f32 D_global_asm_807F7ED4;
extern f32 D_global_asm_807F7ED8;
extern f32 D_global_asm_807F7EDC;
extern f32 D_global_asm_807F7EE0;
extern f32 D_global_asm_807F7EE4;

// TODO: I think I messed up the order of the writes
// Either that or it's doing some weird struct copy in one line?
// Or... We get rid of temp_v0 (shudder)
// Or... float tuples in the struct?
/*
void createLight(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA) {
    Struct807F7500 *temp_v0;
    s32 slot;

    if (D_global_asm_80748300 != 0x10) {
        temp_v0 = &D_global_asm_807F7500[D_global_asm_80748300];
        temp_v0->unk34 = D_global_asm_807F7EFE;
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
        D_global_asm_80748300++;
        temp_v0->unk10 = D_global_asm_807F7EE0;
        temp_v0->unk20 = arg2;
        temp_v0->unk24 = arg3;
        temp_v0->unk28 = arg4;
        temp_v0->unk2C = arg5;
        temp_v0->unk14 = arg6;
        temp_v0->unk36 = arg8;
        temp_v0->unk37 = arg9;
        temp_v0->unk38 = argA;
        D_global_asm_807F7ED8 = D_global_asm_807F7ECC;
        D_global_asm_807F7EDC = D_global_asm_807F7ED0;
        D_global_asm_807F7EF8 = 0;
        D_global_asm_807F7EFA = -1;
        D_global_asm_807F7EFC = 700;
        D_global_asm_807F7EFE = 600;
        D_global_asm_807F7EE0 = D_global_asm_807F7ED4;
        D_global_asm_807F7EE4 = 25.0f;
        D_global_asm_807F7EE8 = 65.0f;
    }
}
*/

// Huge
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065A884.s")

// Matrix stuff?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065BAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065BE74.s")

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

/*
// TODO: Fiddly, decent progress made
void func_global_asm_8065BE74(s16 arg0) {
    s32 i;

    if (D_global_asm_807F7EC8 != 0xC) {
        i = 0;
        if (D_global_asm_807F7EC8 > 0) {
            for (i = 0; i < D_global_asm_807F7EC8; i++) {
                if (D_global_asm_807F78C0[arg0].unk3F == D_global_asm_807F7BC8[i].unk3F) {
                    memcpy(&D_global_asm_807F7BC8[D_global_asm_807F7EC8++], &D_global_asm_807F78C0[arg0], sizeof(Struct807F78C0));
                    break;
                }
            }
        }
    }
}
*/

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065BF18.s")

extern u8 D_global_asm_80750AB4;

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

s32 func_global_asm_8065C240(Struct8065C240 *arg0) {
    f32 dz;
    f32 dy;
    f32 dx;
    s32 i;

    for (i = 0; i < D_global_asm_80750AB4; i++) {
        if (character_change_array[i].does_player_exist != 0) {
            dz = arg0->unk20 - character_change_array[i].look_at_eye_z;
            dx = arg0->unk18 - character_change_array[i].look_at_eye_x;
            dy = arg0->unk1C - character_change_array[i].look_at_eye_y;
            if (sqrtf((dz * dz) + ((dx * dx) + (dy * dy))) < arg0->unk32) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_5E2F0/func_global_asm_8065C334.s")

/*
// TODO: Decent progress made
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
