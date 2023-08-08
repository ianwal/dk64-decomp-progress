#include <ultra64.h>
#include "functions.h"

typedef struct CritterStruct5 {
    s16 x_position; // 0x00
    s16 y_position; // 0x02
    s16 z_position; // 0x04
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 pad1D[0x20 - 0x1D];
    f32 unk20;
    u8 unk24;
    u8 unk25;
    u8 unk26[0x2C - 0x26];
} CritterStruct5;

typedef struct Critter {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[2];
    f32 x_pos; // 0x8
    f32 y_pos; // 0xC
    f32 z_pos; // 0x10
    f32 unk14;
    u8 unk18[0x24-0x18];
    f32 unk24;
    f32 unk28;
    u8 unk2C[0x30-0x2C];
    f32 unk30;
    f32 unk34; // Used
    f32 unk38; // Used
    f32 unk3C; // Used
    u8 unk40; // Used
    u8 unk41;
    s16 unk42;
    s16 unk44;
    u8 unk46[0x48-0x46];
    f32 unk48;
    f32 unk4C;
    u8 unk50[0x54-0x50];
    CritterStruct5 *unk54;
    CritterStruct5 *unk58;
    u8 unk5C[0x1E0-0x5C];
    u8 unk1E0;
    u8 unk1E1;
    u8 unk1E2;
    u8 unk1E3;
    s16 unk1E4[2];
    s32 unk1E8[2];
} Critter;

typedef struct CritterController {
    u8 critter_count;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    Critter *critter;
} CritterController;

typedef struct CritterStruct6 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
} CritterStruct6;

typedef struct {
    u8 pad0[0x2C];
} CritterStruct0;

typedef struct {
    u8 pad0[0x4];
    CritterStruct0 *unk4;
} CritterStruct1;

// CritterController again?
typedef struct unkStruct_critter_80029BA0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
} unkStruct_critter_80029BA0;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} CritterStruct7;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[0x24 - 0x6];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s16 unk28;
    s16 unk2A;
} Struct80026E0C;

extern unkStruct_critter_80029BA0* D_critter_80029BA0;
extern s32 D_critter_80029BA8;
extern f64 D_critter_80029FF0;
extern f32 D_critter_80029FF8;
extern f64 D_critter_8002A000;
extern f64 D_critter_8002A008;
extern f64 D_critter_8002A010;
extern f32 D_critter_8002A018;
extern f64 D_critter_8002A020;
extern f32 D_critter_8002A028;
extern f64 D_critter_8002A078;

extern s32 D_global_asm_8071FC40;
extern u8 D_global_asm_80770DC9;
extern s32 D_global_asm_807F6C28;

void func_critter_80024000(Critter*, s32, f32);
void func_critter_80024578(Critter *);
s32 func_critter_80025AD0(s32, s32);
void func_critter_80025DB8(CritterStruct6*, CritterStruct6*, u8, s16, u8);
void func_critter_800262C0(Critter*, CritterController*);
void func_critter_8002646C(Critter*, Critter*);
void func_critter_80026E0C(s32);

void func_global_asm_8060956C(f32, f32, f32, s32, u8, f32, u8, u8);
void func_global_asm_80611690(void*);
s32 func_global_asm_8066B0F8(s32, s32, s32, s32);
u32 func_global_asm_806119A0();
void func_global_asm_80718BF4(void);

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80024000.s")

void func_critter_8002409C(CritterController *arg0) {
    Critter *phi_v0;
    s32 phi_v1;

    phi_v0 = arg0->critter;
    for (phi_v1 = 0; phi_v1 < arg0->unk2; phi_v1++) {
        phi_v0->unk24 = 7.0f;
        phi_v0->unk1E4[0] = 0x82;
        phi_v0->unk1E1 |= 2;
        phi_v0++;
    }
}

void func_critter_800240EC(CritterController *arg0) {
    Critter *critter;
    s16 phi_v1;
    s16 phi_a1;
    s32 i;

    critter = arg0->critter;
    phi_v1 = 0x7A;
    phi_a1 = 0x7B;
    if (arg0->critter_count == 1) {
        phi_v1 = 0x80;
        phi_a1 = 0x81;
    }
    for (i = 0; i < arg0->unk2; i++) {
        critter->unk24 = 5.0f;
        critter->unk1E4[0] = phi_v1;
        critter->unk1E4[1] = phi_a1;
        critter++;
    }
}

// Odd stack struct
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80024154.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_8002427C.s")

extern f64 D_critter_80029FE0;
extern f64 D_critter_80029FE8;

extern f32 *D_critter_80029F74;

/*
void func_critter_8002427C(CritterController *arg0) {
    f32 sp68[4][4];
    Critter *var_s0;
    f64 temp_f22;
    f64 temp_f24;
    s32 i;
    u8 var_s2;

    var_s0 = arg0->critter;
    sp68[0][0] = D_critter_80029F74[0];
    sp68[0][1] = D_critter_80029F74[1];
    var_s2 = 0;
    temp_f24 = D_critter_80029FE0;
    temp_f22 = D_critter_80029FE8;
    for (i = 0; i < arg0->unk2; i++) {
            if (var_s2 == 0) {
                if (!((arg0->unk2 * temp_f22) < i)) {
                    goto block_6;
                }
                goto block_14;
            }
block_6:
            if (var_s2 == 1) {
                if (!(( arg0->unk2 * 0.5) < i)) {
                    goto block_10;
                }
                goto block_14;
            }
block_10:
            if (var_s2 == 2) {
                if ((arg0->unk2 * temp_f24) < i) {
block_14:
                    var_s2++;
                }
            }
            var_s0->unk24 = 20.0f;
            var_s0->unk1E1 |= 4;
            var_s0->unk1E8[0] = 0;
            var_s0->unk1E4[0] = (&sp68[0])[var_s2];
            func_critter_80024000(var_s0, arg0, var_s0->unk38 * 0.5);
            var_s0++;
    }
}
*/

void func_critter_8002448C(Critter *arg0) {
    s32 i;
    u16 temp;

    for (i = 0; i < 2; i++) {
        temp = arg0->unk1E4[i];
        if (temp && arg0->unk1E8[i] == 0) {
            arg0->unk1E8[i] = func_global_asm_8066B0F8(0xE, temp, 0, 0);
        }
    }
}

void func_critter_80024518(Critter *arg0) {
    s32 i;
    s32 temp;

    for (i = 0; i < 2; i++) {
        temp = arg0->unk1E8[i];
        if (temp != 0) {
            func_global_asm_8066B434(temp, 0x179, 0x5A);
            arg0->unk1E8[i] = 0;
        }
    }
}

void func_critter_80024578(Critter *arg0) {
    if (arg0->unk1E1 & 1) {
        func_critter_8002448C(arg0);
    } else {
        func_critter_80024518(arg0);
    }
}

// Listed as "Bat Critter Behavior" in Ghidra
void func_critter_800245B8(Critter *arg0) {
    f32 temp_f2;
    u32 rng_val;
    f32 sp3C;
    
    if ((arg0->unk1E0 != 0) && (arg0->unk1E1 & 1)) {
        rng_val = func_global_asm_806119A0();
        sp3C = arg0->unk28 * D_critter_80029FF0;
        if ((s16)(rng_val % 255U) < 6) {
            func_global_asm_806086CC(arg0->x_pos, arg0->y_pos, arg0->z_pos, ((func_global_asm_806119A0() & 3) + 0x1A9), 0xFF, 0x7F, 0x1E, 0x5A, D_critter_80029FF8, 0);
        }
        arg0->unk42 = arg0->unk42 + (1200.0f * sp3C);
        arg0->unk42 &= 0xFFF;
        if (arg0->unk44 >= 0x801) {
            if (arg0->unk42 < 0x800) {
                func_global_asm_8060956C(arg0->x_pos, arg0->y_pos, arg0->z_pos, 0x5E, (D_global_asm_80770DC9 * 0x64) + 0x73, 2.0f, 0x1E, 0x4B);
            }
        } else {
            if (arg0->unk42 >= 0x801) {
                func_global_asm_8060956C(arg0->x_pos, arg0->y_pos, arg0->z_pos, 0x5F, (D_global_asm_80770DC9 * 0x64) + 0x73, 2.0f, 0x1E, 0x4B);
            }
        }
        temp_f2 = 1.0f - func_global_asm_80612790(arg0->unk42);
        arg0->unk48 = 60.0f * temp_f2;
        arg0->unk14 = (arg0->unk28 * temp_f2) * 0.5;
    }
    func_critter_80024578(arg0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_800247F4.s")

void func_critter_80024B78(Critter *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    if (arg0->unk1E1 & 1) {
        temp_f2 = (arg0->unk28 * D_critter_8002A000);
        arg0->unk42 = (arg0->unk42 + (D_critter_8002A008 * (0.5 + (10.0f * temp_f2))));
        arg0->unk42 &= 0xFFF;
        temp_f0 = func_global_asm_80612794(arg0->unk42);
        arg0->unk48 = ((((-15.0f * temp_f2) + 45.0f) * temp_f0) + (temp_f2 * 30.0f));
        arg0->unk14 = ((arg0->unk28 * temp_f0) * D_critter_8002A010);
    }
    func_critter_80024578(arg0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80024C88.s")

void func_critter_80024F28(Critter *arg0) {
    s16 temp_v1;
    f32 temp_f2;
    f32 sp44;
    f32 sp40;
    s16 sp3E;
    s32 temp;

    if (arg0->unk1E1 & 1) {
        temp_v1 = func_global_asm_806119A0() % 400U;
        sp40 = MAX(0.0f, arg0->unk30);
        sp3E = func_global_asm_806CC10C(arg0->unk0, arg0->unk4);
        if (temp_v1 <= 0) {
            func_global_asm_807149B8(1U);
            func_global_asm_80714950(1);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(&func_global_asm_80718BF4);
            func_global_asm_80714CC0(&D_global_asm_8071FC40, 0.0f, arg0->x_pos, arg0->y_pos, arg0->z_pos);
        }
        temp = ABS(sp3E);
        if (!(temp < 0x5B)) {
            func_global_asm_806086CC(arg0->x_pos, arg0->y_pos, arg0->z_pos, 0x16F, 0x46, 0xDC, 0x1E, 0x5A, D_critter_8002A018, 0);
        }
        arg0->unk42 = (arg0->unk42 + (200.0 * (1.5 + (150.0f * arg0->unk30))));
        arg0->unk42 &= 0xFFF;
        temp_f2 = func_global_asm_80612794(arg0->unk42) * (10.0f + (200.0f * sp40));
        temp_f2 += (temp_f2 * (sp3E * 0.00024414062f));
        sp44 = temp_f2;
        arg0->unk4C = (func_global_asm_80612794(arg0->unk42 + 0xC8) * 2);
        arg0->unk48 = (sp44 + (sp3E * D_critter_8002A020));
    }
    func_critter_80024578(arg0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_8002516C.s")

void func_critter_80025500(Critter *arg0) {
    if ((arg0->unk1E0 != 0) && (arg0->unk1E1 & 1) && ((s16) (func_global_asm_806119A0() % 255U) < 6)) {
        func_global_asm_806086CC(arg0->x_pos, arg0->y_pos, arg0->z_pos, ((func_global_asm_806119A0() & 3) + 0x1A9), 0xFF, 0x5A, 0x1E, 0x5A, D_critter_8002A028, 0);
    }
    func_critter_80024578(arg0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_800255C4.s")

extern Gfx D_1000118;
extern f32 D_2000180[];
extern f32 D_02000200[];

Gfx *func_critter_800257D4(Gfx *dl) {
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | 
                                    G_FOG | G_LIGHTING | G_TEXTURE_GEN | 
                                    G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 
                                    G_CLIPPING | 0x0040F9FA);
    gSPMatrix(dl++, 
                (&character_change_array[cc_player_index].unk88[D_global_asm_807444FC]), 
                G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_02000200, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return dl;
}

void func_critter_800258B0(f32 arg0[4][4], s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    s32 temp;
    f32 sp40;
    f32 sp3C;
    s32 temp2;
    f32 sp34;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f20 = func_global_asm_80612794(arg1);
    temp_f22 = func_global_asm_80612790(arg1);
    sp40 = func_global_asm_80612794(arg2);
    sp34 = func_global_asm_80612790(arg2);
    sp3C = func_global_asm_80612794(arg3);
    temp_f0 = func_global_asm_80612790(arg3);
    arg0[0][0] = sp34 * temp_f0 * arg4;
    arg0[0][1] = sp34 * sp3C * arg4;
    arg0[0][2] = -sp40 * arg4;
    arg0[0][3] = 0.0f;
    temp_f14 = temp_f20 * sp40;
    arg0[1][0] = ((temp_f14 * temp_f0) - (temp_f22 * sp3C)) * arg4;
    arg0[1][1] = ((temp_f14 * sp3C) + (temp_f22 * temp_f0)) * arg4;
    arg0[1][2] = temp_f20 * sp34 * arg4;
    arg0[1][3] = 0.0f;
    temp_f14_2 = temp_f22 * sp40;
    arg0[2][0] = ((temp_f14_2 * temp_f0) + (temp_f20 * sp3C)) * arg4;
    arg0[2][1] = ((temp_f14_2 * sp3C) - (temp_f20 * temp_f0)) * arg4;
    arg0[2][2] = temp_f22 * sp34 * arg4;
    arg0[2][3] = 0.0f;
    arg0[3][0] = arg5;
    arg0[3][1] = arg6;
    arg0[3][2] = arg7;
    arg0[3][3] = 1.0f;
}

void func_critter_800258B0(f32 arg0[4][4], s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
extern f32 D_critter_8002A02C;

typedef struct {
    s16 unk0;
    s16 unk2;
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
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    u8 unk40[0x60 - 0x40];
    f32 unk60[2][4][4]; // At least 2 4x4 matrices
} Struct80025A3C;

void func_critter_80025A3C(Struct80025A3C *arg0) {
    f32 sp30[4][4];

    func_critter_800258B0(&sp30, -arg0->unk2, arg0->unk0, 0, arg0->unk38 * D_critter_8002A02C, arg0->unk8, arg0->unkC + arg0->unk14, arg0->unk10);
    guMtxF2L(&sp30, arg0->unk60[D_global_asm_807444FC]);
}

// Displaylist stuff, jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80025AD0.s")

s32 func_critter_80025D1C(s32 arg0, CritterController *arg1) {
    s32 i;
    s32 var_s1;

    if (arg1 == NULL) {
        return arg0;
    }
    D_critter_80029BA8 = 0;
    var_s1 = arg1->unk4;
    if (var_s1 != 0) {
        arg0 = func_critter_800257D4(arg0);
    }
    for (i = 0; i < arg1->critter_count; i++) {
        arg0 = func_critter_80025AD0(arg0, var_s1);
        var_s1 += sizeof(CritterController);
    }
    return arg0;
}

void func_critter_80025DB8(CritterStruct6 *arg0, CritterStruct6 *arg1, u8 arg2, s16 arg3, u8 arg4) {
    f32 sp2C;
    s32 temp;
    f32 var_f0;
    f32 *var_v0;
    f32 *var_v1;
    f32 *var_a2;
    f32 temp_f2;

    var_f0 = arg0->unkC;
    if (!(arg2)) {
        sp2C = arg0->unk14;
        var_f0 += arg0->unk10;
    } else {
        sp2C = (func_global_asm_806119A0() & 0xFFF) * 0.00024414062f * arg0->unk8;
    }
    temp_f2 = ((func_global_asm_806119A0(arg0, arg1) & 0xFFF) * 0.00024414062f * var_f0) - (0.5 * var_f0);
    if (arg4 != 0) {
        var_v0 = &arg1->unk18;
        var_v1 = &arg1->unk1C;
        var_a2 = &arg1->unk20;
    } else {
        var_v0 = &arg1->unk8;
        var_v1 = &arg1->unkC;
        var_a2 = &arg1->unk10;
    }
    *var_v1 = temp_f2;
    *var_v0 = func_global_asm_80612794(arg3) * sp2C;
    *var_a2 = func_global_asm_80612790(arg3) * sp2C;
}

void func_critter_80025F3C(CritterStruct6 *arg0, CritterStruct6 *arg1, u8 arg2, u8 arg3) {
    func_critter_80025DB8(arg0, arg1, arg2, func_global_asm_806119A0() & 0xFFF, arg3);
}

void func_critter_80025F8C(CritterStruct7 *arg0, CritterStruct7 *arg1, u8 arg2) {
    func_critter_80025F3C(arg0, arg1, arg2, 0);
    arg1->unk8 += arg0->unk0;
    arg1->unkC += arg0->unk2;
    arg1->unk10 += arg0->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_8002601C.s")

extern f32 D_critter_8002A044;

extern CritterStruct5 *D_critter_80029BA4;

/*
// TODO: Kinda close, lots of float nonsense to sort out
void func_critter_8002601C(Critter *arg0) {
    CharacterChange *temp_v1_2;
    f32 temp_f12;
    f32 temp_f2;
    f32 var_f0;
    s32 temp_t4;
    s32 temp_v1;

    temp_f2 = arg0->unk58->unk18 + 122500;
    if (arg0->unk58->unk24 != D_global_asm_807444FC) {
        f32 x2, z2;
        var_f0 = 0.0f;
        x2 = arg0->unk58->x_position;
        z2 = arg0->unk58->z_position;
        temp_t4 = ((arg0->unk58->unkC + arg0->unk58->unk10) >> 1);
        arg0->unk58->unk25 = (((D_critter_80029BA4->y_position < (arg0->unk58->y_position + temp_t4)) && ((arg0->unk58->y_position - temp_t4) < D_critter_80029BA4->y_position))
            && (((x2 - D_global_asm_807FBB48->x_position) * (x2 - D_global_asm_807FBB48->x_position))
            + ((z2 - D_global_asm_807FBB48->z_position) * (z2 - D_global_asm_807FBB48->z_position))) < arg0->unk58->unk18);
        arg0->unk58->unk24 = D_global_asm_807444FC;
        temp_f12 = (((arg0->unk58->x_position - character_change_array[cc_player_index].look_at_eye_x) * (arg0->unk58->x_position - character_change_array[cc_player_index].look_at_eye_x))
            + ((arg0->unk58->y_position - character_change_array[cc_player_index].look_at_eye_y) * (arg0->unk58->y_position - character_change_array[cc_player_index].look_at_eye_y))
            + ((arg0->unk58->z_position - character_change_array[cc_player_index].look_at_eye_z) * (arg0->unk58->z_position - character_change_array[cc_player_index].look_at_eye_z)));
        arg0->unk58->unk20 = temp_f12;
        if (temp_f12 < temp_f2) {
            var_f0 = (temp_f2 - temp_f12) * D_critter_8002A044;
            if (var_f0 > 1.0f) {
                var_f0 = 1.0f;
            }
        }
        arg0->unk58->unk26[0] = 255.0f * var_f0;
    }
    if (arg0->unk58->unk20 < temp_f2) {
        arg0->unk1E1 |= 1;
    } else {
        arg0->unk1E1 &= ~1;
    }
}
*/

CritterStruct0 *func_critter_80026298(CritterStruct1 *arg0, u8 arg1) {
    CritterStruct0 *temp_v1 = arg0->unk4;
    return &temp_v1[arg1];
}

void func_critter_800262C0(Critter *arg0, CritterController *arg1) {
    u8 var_a1;

    var_a1 = (func_global_asm_806119A0() % (arg1->unk1 - 1));
    if (var_a1 >= arg0->unk50[0]) {
        var_a1++;
    }
    arg0->unk50[0] = var_a1;
    arg0->unk54 = func_critter_80026298(arg1, var_a1);
}

void func_critter_80026338(Critter *arg0, CritterController *arg1) {
    s32 phi_v0;

    switch (arg1->critter_count) {
        case 3:
            phi_v0 = 6400;
            break;
        case 0:
        case 1:
            phi_v0 = 22500;
            break;
        default:
            phi_v0 = 6400;
            break;
    }
    if ((arg0->unk3C < phi_v0) && (arg0->unk58->unk25)) {
        arg0->unk1E0 = 2;
        if (arg0->unk1E2 == 0) {
            arg0->unk54 = D_critter_80029BA4;
        } else {
            func_critter_800262C0(arg0, arg1);
        }
        func_critter_80025F3C(arg0->unk54, arg0, 1, 1);
        func_critter_80024000(arg0, arg1, arg0->unk38);
    }
}

void func_critter_80026410(Critter *arg0) {
    f32 dx, dz;

    if (arg0->unk40 != D_global_asm_807444FC) {
        Actor* temp = D_global_asm_807FBB48;
        dx = arg0->x_pos - temp->x_position;
        dz = arg0->z_pos - temp->z_position;
        arg0->unk3C = (dx * dx) + (dz * dz);
        arg0->unk40 = D_global_asm_807444FC;
    }
}

void func_critter_8002646C(Critter *arg0, Critter *arg1) {
    arg0->unk28 = arg1->unk28;
    arg0->unk58 = arg1->unk58;
    arg0->unk1E1 = arg1->unk1E1;
    if (arg0->unk54 != arg1->unk54) {
        arg0->unk54 = arg1->unk54;
        func_critter_80025F3C(arg0->unk54, arg0, 1, 1);
    }
    arg0->unk1E0 = arg1->unk1E0;
    if (!arg0->unk1E0 && !(arg0->unk1E1 & 4)) {
        arg0->unk2 = 0;
    } else if ((func_global_asm_806119A0() % 255U) < 0x32) {
        func_critter_80025F3C(arg0->unk54, arg0, 1, 1);
    }
}

s32 func_critter_80026530(Critter *arg0, s32 arg1) {
    func_critter_80024000(arg0, arg1, arg0->unk38 * 0.5);
    func_critter_80025F3C(arg0->unk54, arg0, 1, 1);
    return 0;
}

// Seems doable, lots of float bs though
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_8002658C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80026874.s")

void func_critter_80026904(Critter *arg0, CritterController *arg1) {
    if (arg0->unk1E2 == 2) {
        func_critter_8002646C(arg0, arg1->critter);
        return;
    }
    if (arg0->unk1E2 == 0) {
        if (arg0->unk58->unk25 != 0) {
            func_critter_80026410(arg0);
            if (D_critter_80029BA4 != arg0->unk54) {
                func_critter_80026338(arg0, arg1);
                return;
            }
            if ((arg0->unk1E0 == 2) && (arg0->unk3C < D_critter_80029BA4->unkA)) {
                s16 temp;
                temp = func_global_asm_80665DE0(arg0->x_pos, arg0->z_pos, D_global_asm_807FBB48->x_position, D_global_asm_807FBB48->z_position);
                temp += (func_global_asm_806119A0() & 0x7FF) - 0x400;
                arg0->unk1E0 = 1;
                func_critter_80025DB8(arg0->unk54, arg0, 0, temp, 1);
            }
        } else if (D_critter_80029BA4 == arg0->unk54) {
            arg0->unk54 = arg0->unk58;
            func_critter_80025F3C(arg0->unk58, arg0, 1, 1);
            arg0->unk40 = 0xFF;
        }
    }
}

s32 func_critter_80026A5C(Critter *arg0, s32 arg1) {
    CritterStruct5 *temp_v0;

    if (arg0->unk1E2 == 1) {
        temp_v0 = arg0->unk54;
        arg0->unk58 = temp_v0;
        if ((temp_v0->unk1C & 1) != 0) {
            arg0->unk2 = 0;
            arg0->unk1E0 = 0;
            arg0->unk28 = 0.0f;
            arg0->unk34 = 0;
            return TRUE;
        }
        func_critter_800262C0(arg0, arg1);
    } else if (D_critter_80029BA4 == arg0->unk54) {
        if (arg0->unk1E0 == 2) {
            arg0->unk1E0 = 1;
        } else {
            arg0->unk1E0 = 2;
        }
        func_critter_80025F3C(arg0->unk54, arg0, (arg0->unk1E0 == 2), 1);
    } else {
        arg0->unk2 = 0;
        arg0->unk34 = 0.0f;
        if (arg0->unk28 < D_critter_8002A078) {
            arg0->unk1E0 = 0;
            arg0->unk28 = 0;
            return TRUE;
        }
    }
    return FALSE;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80026B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80026C9C.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    s16 unk16;
} Struct80029BAC_inner;

typedef struct {
    Struct80029BAC_inner unk0[5];
} Struct80029BAC;

extern Struct80029BAC D_critter_80029BAC[];

/*
// TODO: Pretty close
void func_critter_80026C9C(CritterController *arg0) {
    CritterStruct5 *temp_t5;
    Struct80029BAC_inner *temp_v0;
    u8 *phi_s0;
    u8 phi_v1;
    s32 i;

    if (arg0 != NULL) {
        D_critter_80029BA4->x_position = D_global_asm_807FBB48->x_position;
        D_critter_80029BA4->z_position = D_global_asm_807FBB48->z_position;
        phi_s0 = arg0->unk4;
        for (i = 0; i < arg0->critter_count; i++) {
            phi_v1 = *phi_s0;
            if (phi_v1 > 0) {
                phi_v1--;
            }
            temp_v0 = &D_critter_80029BAC[current_character_index[0]].unk0[phi_v1];
            D_critter_80029BA4->y_position = D_global_asm_807FBB48->y_position + temp_v0->unk14;
            temp_t5 = D_critter_80029BA4;
            temp_t5->unk8 = temp_v0->unk0;
            temp_t5->unkC = temp_v0->unk4;
            temp_t5->unk10 = temp_v0->unk8;
            temp_t5->unk14 = temp_v0->unkC;
            temp_t5->unk18 = temp_v0->unk10;
            func_critter_80026B78(phi_s0);
            phi_s0 += 0xC;
        }
    }
}
*/

void func_critter_80026E0C(s32 arg0) {
    s32 j;
    unkStruct_critter_80029BA0 *var_s2;
    Struct80026E0C *var_s0;
    s32 i;
    s32 var_s3;

    if (arg0 != 0) {
        memcpy(D_critter_80029BA0, arg0, 1);
        var_s3 = arg0 + 1;
        for (i = 0; i < D_critter_80029BA0->unk0; i++) {
            j = 0;
            if (i == 0) {
                D_critter_80029BA0->unk4 = malloc(D_critter_80029BA0->unk0 * 0xC);
                func_global_asm_80611690(D_critter_80029BA0->unk4);
                var_s2 = D_critter_80029BA0->unk4;
            } else {
                var_s2++;
            }
            memcpy(var_s2, var_s3, 3);
            var_s3 += 3;
            while (j < var_s2->unk1) {
                if (j == 0) {
                    var_s2->unk4 = malloc(var_s2->unk1 * sizeof(Struct80026E0C));
                    func_global_asm_80611690(var_s2->unk4);
                    var_s0 = var_s2->unk4;
                } else {
                    var_s0++;
                }
                memcpy(var_s0, var_s3, 0x20);
                if (D_global_asm_807F6C28 != 0) {
                    var_s0->unk28 = func_global_asm_806531B8(var_s0->unk0, var_s0->unk2, var_s0->unk4, 0);
                    var_s0->unk24 = 0xFF;
                }
                j += 1;
                var_s3 += 0x20;
            }
            func_critter_80027118(var_s2);
        }
    }
}

void func_critter_80026FD0(s32 arg0) {
    D_critter_80029BA8 = 0;
    D_critter_80029BA0 = malloc(8); // TODO: Something up here...
    func_global_asm_80611690(D_critter_80029BA0);
    func_critter_80026E0C(arg0);
    D_critter_80029BA4 = malloc(sizeof(CritterStruct5));
    func_global_asm_80611690(D_critter_80029BA4);
}

s32 func_critter_80027034(s32 arg0) {
    if (global_properties_bitfield & 0x10) {
        if (!(global_properties_bitfield & 2)) {
            func_critter_80026C9C(D_critter_80029BA0);
        }
        arg0 = func_critter_80025D1C(arg0, D_critter_80029BA0);
    }
    return arg0;
}

void func_critter_8002708C(CritterController *arg0) {
    Critter *var_s0;
    s32 i;
    u8 temp_s2;

    var_s0 = arg0->critter;
    temp_s2 = arg0->unk2;
    for (i = 0; i < temp_s2 && var_s0 != NULL; i++) {
        func_critter_80024518(var_s0);
        var_s0++;
    }
    if (arg0->critter != NULL) {
        func_global_asm_8061134C(arg0->critter);
    }
    arg0->critter = NULL;
    arg0->unk2 = 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_0/func_critter_80027118.s")
