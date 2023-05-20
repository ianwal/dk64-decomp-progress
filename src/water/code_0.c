#include <ultra64.h>
#include "functions.h"


extern u8 D_807444FC;

typedef struct WaterStruct2 { //this and Critter are the same?
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    struct WaterStruct2 *next; // At 0x8
    u8 padC[0x24 - 0xC];
    f32 unk24;
    u8 pad28[0x1E1 - 0x28];
    u8 unk1E1;
    u8 unk1E2;
    u8 unk1E3;
    s16 unk1E4;
    s16 unk1E6;
    s32 unk1E8;
    s32 unk1EC;
} WaterStruct2;

typedef struct Critter {  //this and Critter are the same?
    s16 unk0;
    u8 unk2[2];
    s16 unk4;
    u8 unk6[2];
    f32 x_pos; // 0x8
    f32 y_pos; // 0xC
    f32 z_pos; // 0x10
    f32 unk14;
    u8 unk18[0x28-0x18];
    f32 unk28;
    u8 unk2C[0x30-0x2C];
    f32 unk30;
    u8 unk34[0x42-0x34];
    s16 unk42;
    s16 unk44;
    u8 unk46[0x48-0x46];
    f32 unk48;
    f32 unk4C;
    u8 unk50[0x1E0-0x50];
    u8 unk1E0;
    u8 unk1E1;
} Critter;

typedef struct WaterStruct5 {
    u8 pad0[0x1C - 0x0];
    u8 unk1C;
    u8 pad1D[0x25 - 0x1D];
    u8 unk25;
} WaterStruct5;

typedef struct WaterStruct6 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} WaterStruct6;

// TODO: Merge into WaterStruct2, they're likely the same type
typedef struct WaterStruct4 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 pad0[0x28 - 0x14];
    f32 unk28;
    s32 unk2C;
    s32 unk30;
    f32 unk34; // Used
    f32 unk38; // Used
    f32 unk3C; // Used
    u8 unk40; // Used
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 pad2[0x54 - 0x44];
    void *unk54;
    WaterStruct5 *unk58;
    u8 pad3[0x1E0 - 0x5C];
    u8 unk1E0;
    u8 unk1E1;
    u8 unk1E2;
} WaterStruct4;

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80024000.s")

void func_8002409C(WaterStruct2 *arg0) {
    WaterStruct2 *phi_v0;
    s32 phi_v1;

    phi_v0 = arg0->next;
    for (phi_v1 = 0; phi_v1 < arg0->unk2; phi_v1++) {
        phi_v0->unk24 = 7.0f;
        phi_v0->unk1E4 = 0x82;
        phi_v0->unk1E1 |= 2;
        phi_v0++;
    }
}

void func_800240EC(WaterStruct2 *arg0) {
    WaterStruct2 *phi_v0;
    s16 phi_v1;
    s16 phi_a1;
    s32 phi_a2;

    phi_v0 = arg0->next;
    phi_v1 = 0x7A;
    phi_a1 = 0x7B;
    if (arg0->unk0 == 1) {
        phi_v1 = 0x80;
        phi_a1 = 0x81;
    }
    for (phi_a2 = 0; phi_a2 < arg0->unk2; phi_a2++) {
        phi_v0->unk24 = 5.0f;
        phi_v0->unk1E4 = phi_v1;
        phi_v0->unk1E6 = phi_a1;
        phi_v0++;
    }
}

// Odd stack struct
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80024154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_8002427C.s")

// Doable, similar to below
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_8002448C.s")

s32 func_8066B0F8(s32, u16, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80024518.s")

// TODO: Very doable, we are passed an array of pointers I think
// Not sure on how to write that right now
/*
void func_80024518(WaterStruct2 *arg0) {
    WaterStruct2 *phi_s0;
    s32 i;

    phi_s0 = arg0;
    for (i = 0; i < 8; i += 4) {
        if (phi_s0->unk1E8 != 0) {
            func_8066B434(phi_s0->unk1E8, 0x179, 0x5A);
            phi_s0->unk1E8 = 0;
        }
        phi_s0++;
    }
}
*/

void func_80024578(WaterStruct2 *arg0) {
    if (arg0->unk1E1 & 1) {
        func_8002448C(arg0);
    } else {
        func_80024518(arg0);
    }
}

void func_80024578(WaterStruct2 *);                            /* extern */
void func_8060956C(f32, f32, f32, s32, u8, f32, u8, u8); /* extern */
u32 func_806119A0();                                /* extern */
extern f64 D_80029FF0;
extern f32 D_80029FF8;
extern u8 D_80770DC9;

// Listed as "Bat Critter Behavior" in Ghidra
void func_800245B8(Critter *arg0) {
    f32 temp_f2;
    s32 temp_a0;
    f32 sp3C;
    u32 rng_val;
    s32 temp_a0_2;

    if (rng_val);
    
    if ((arg0->unk1E0 != 0) && (arg0->unk1E1 & 1)) {
        rng_val = func_806119A0();
        sp3C = (f32) ((f64) arg0->unk28 * D_80029FF0);
        if ((s16) (rng_val % 255U) < 6) {
            func_806086CC(arg0->x_pos, arg0->y_pos, arg0->z_pos, (s16) ((func_806119A0() & 3) + 0x1A9), (u8) 0xFF, (s16) 0x7F, (u8) 0x1E, (u8) 0x5A, D_80029FF8, (u8) 0);
        }
        arg0->unk42 = (s16) (s32) ((f32) arg0->unk42 + (1200.0f * sp3C));
        arg0->unk42 = (s16) (arg0->unk42 & 0xFFF);
        if (arg0->unk44 >= 0x801) {
            temp_a0 = arg0->unk42;
            if (temp_a0 < 0x800) {
                func_8060956C(arg0->x_pos, arg0->y_pos, arg0->z_pos, 0x5E, (D_80770DC9 * 0x64) + 0x73, 2.0f, 0x1E, 0x4B);
            }
        } else {
            temp_a0_2 = arg0->unk42;
            if (temp_a0_2 >= 0x801) {
                func_8060956C(arg0->x_pos, arg0->y_pos, arg0->z_pos, 0x5F, (D_80770DC9 * 0x64) + 0x73, 2.0f, 0x1E, 0x4B);
            }
        }
        temp_f2 = 1.0f - func_80612790(arg0->unk42);
        arg0->unk48 = (f32) (60.0f * temp_f2);
        arg0->unk14 = (f32) ((f64) (arg0->unk28 * temp_f2) * 0.5);
    }
    func_80024578(arg0);
}


// Display list stuff
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_800247F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80024B78.s")

extern f64 D_8002A000;
extern f64 D_8002A008;

/*
Regalloc
void func_80024B78(Critter *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    if (arg0->unk1E1 & 1) {
        temp_f2 = (f32) ((f64) arg0->unk28 * D_8002A000);
        arg0->unk42 = (s16) (s32) ((f64) arg0->unk42 + (D_8002A008 * (0.5 + (f64) (10.0f * temp_f2))));
        arg0->unk42 = (s16) (arg0->unk42 & 0xFFF);
        temp_f0 = func_80612794(arg0->unk42);
        arg0->unk48 = (f32) ((((-15.0f * temp_f2) + 45.0f) * temp_f0) + (temp_f2 * 30.0f));
        arg0->unk14 = (f32) ((f64) (arg0->unk28 * temp_f0) * *(f64 *)0x8002A010);
    }
    func_80024578(arg0);
}
*/

// Display List
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80024C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80024F28.s")

extern f32 D_8002A018;
extern f64 D_8002A020;
void D_80718BF4(void);
void D_8071FC40(void);

/*
Bunch of stack/regalloc issues
void func_80024F28(Critter *arg0) {
    f32 sp44;
    s16 sp3E;
    f32 temp_f2;
    f32 temp_f0;
    s16 var_v0;
    s16 temp_v1;
    f32 sp40;

    if (arg0->unk1E1 & 1) {
        temp_f0 = arg0->unk30;
        temp_v1 = func_806119A0() % 400U;
        if (temp_f0 < 0.0f) {
            sp40 = 0.0f;
        } else {
            sp40 = temp_f0;
        }
        sp3E = func_806CC10C(arg0->unk0, arg0->unk4);
        if (temp_v1 <= 0) {
            func_807149B8(1U);
            func_80714950(1);
            func_807149FC(-1);
            func_8071498C(&D_80718BF4);
            func_80714CC0(&D_8071FC40, 0.0f, arg0->x_pos, arg0->y_pos, arg0->z_pos);
        }
        var_v0 = -sp3E;
        if (sp3E > 0) {
            var_v0 = sp3E;
        }
        if (var_v0 >= 0x5B) {
            func_806086CC(arg0->x_pos, arg0->y_pos, arg0->z_pos, 0x16F, 0x46, 0xDC, 0x1E, 0x5A, D_8002A018, 0);
        }
        arg0->unk42 = ((f64) arg0->unk42 + (200.0 * (1.5 + (f64) (150.0f * arg0->unk30))));
        arg0->unk42 = arg0->unk42 & 0xFFF;
        temp_f2 = func_80612794(arg0->unk42) * (10.0f + (200.0f * sp40));
        sp44 = temp_f2 + (temp_f2 * ((f32) sp3E * 0.00024414062f));
        arg0->unk4C = (func_80612794(arg0->unk42 + 0xC8) * 2.0f);
        arg0->unk48 = ((f64) sp44 + ((f64) sp3E * D_8002A020));
    }
    func_80024578(arg0);
}
*/

// Display List
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_8002516C.s")

extern f32 D_8002A028;

void func_80025500(Critter *arg0) {
    if ((arg0->unk1E0 != 0) && (arg0->unk1E1 & 1) && ((s16) (func_806119A0() % 255U) < 6)) {
        func_806086CC(arg0->x_pos, arg0->y_pos, arg0->z_pos, ((func_806119A0() & 3) + 0x1A9), 0xFF, 0x5A, 0x1E, 0x5A, D_8002A028, 0);
    }
    func_80024578(arg0);
}

// Display List
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_800255C4.s")

// Display List
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_800257D4.s")

/*
// TODO: Displaylist stuff
Gfx *func_800257D4(Gfx *arg0) {
  gSPDisplayList(arg0++, 0x01000118);
  gDPPipeSync(arg0++);
  gDPSetCycleType(arg0++, G_CYC_1CYCLE);
  gSPClearGeometryMode(arg0++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | 
                                  G_FOG | G_LIGHTING | G_TEXTURE_GEN | 
                                  G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 
                                  G_CLIPPING | 0x0040F9FA);
  gSPMatrix(arg0++, 
            (&character_change_array[cc_player_index] + (D_807444FC << 6) + 0x88), 
            G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
  gSPMatrix(arg0++, 0x20002000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
  gSPMatrix(arg0++, 0x20001800, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
  return arg0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_800258B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80025A3C.s")

// Display List
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80025AD0.s")

s32 func_800257D4(s32);                             /* extern */
s32 func_80025AD0(s32, s32);                        /* extern */
extern s32 D_80029BA8;

typedef struct {
    u8 critter_count;
    u8 unk1[3];
    s32 unk4;
    s32 unk8;
} struct_master_critter_ctrlr;

s32 func_80025D1C(s32 arg0, struct_master_critter_ctrlr *arg1) {
    s32 var_s0;
    s32 var_s1;

    if (arg1 == NULL) {
        return arg0;
    }
    D_80029BA8 = 0;
    var_s1 = arg1->unk4;
    if (var_s1 != 0) {
        arg0 = func_800257D4(arg0);
    }
    for (var_s0 = 0; var_s0 < arg1->critter_count; var_s0++) {
        arg0 = func_80025AD0(arg0, var_s1);
        var_s1 += sizeof(struct_master_critter_ctrlr);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80025DB8.s")

void func_80025DB8(WaterStruct6*, WaterStruct6*, s32, s16, s32);

void func_80025F3C(WaterStruct6 *arg0, WaterStruct6 *arg1, u8 arg2, u8 arg3) {
    func_80025DB8(arg0, arg1, arg2, func_806119A0() & 0xFFF, arg3);
}

void func_80025F8C(WaterStruct6 *arg0, WaterStruct6 *arg1, u8 arg2) {
    func_80025F3C(arg0, arg1, arg2, 0);
    arg1->unk8 += arg0->unk0;
    arg1->unkC += arg0->unk2;
    arg1->unk10 += arg0->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_8002601C.s")

typedef struct {
    u8 pad0[0x2C];
} WaterStruct0;

typedef struct {
    u8 pad0[0x4];
    WaterStruct0 *unk4;
} WaterStruct1;

WaterStruct0 *func_80026298(WaterStruct1 *arg0, u8 arg1) {
    WaterStruct0 *temp_v1 = arg0->unk4;
    return &temp_v1[arg1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_800262C0.s")

void func_80024000(WaterStruct4*, s32, f32);
void func_800262C0(WaterStruct4*, s32);
extern s32 D_80029BA8;

typedef struct WaterStruct7 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ char unk_0C[0x20];
} WaterStruct7;

extern WaterStruct7 *D_80029BA4;

typedef struct unkStruct_80029BA0 {
/* 0x00 */ char unk_00[8];
} unkStruct_80029BA0;

extern unkStruct_80029BA0* D_80029BA0;

// TODO: arg1 might be a different type
void func_80026338(WaterStruct4 *arg0, WaterStruct5 *arg1) {
    s32 phi_v0;

    switch (arg1->pad0[0]) {
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
    if ((arg0->unk3C < phi_v0) && 
        (((WaterStruct5*)arg0->unk58)->unk25)) {
          arg0->unk1E0 = 2;
          if (arg0->unk1E2 == 0) {
              arg0->unk54 = D_80029BA4;
          } else {
              func_800262C0(arg0, arg1);
          }
          func_80025F3C(arg0->unk54, arg0, 1, 1);
          func_80024000(arg0, arg1, arg0->unk38);
    }
}

void func_80026410(WaterStruct4 *arg0) {
    f32 dx, dz;

    if (arg0->unk40 != D_807444FC) {
        Actor* temp = D_807FBB48;
        dx = arg0->unk8 - temp->x_position;
        dz = arg0->unk10 - temp->z_position;
        arg0->unk3C = (dx * dx) + (dz * dz);
        arg0->unk40 = D_807444FC;
    }
}

void func_8002646C(WaterStruct4*, WaterStruct4*);

void func_8002646C(WaterStruct4 *arg0, WaterStruct4 *arg1) {
    arg0->unk28 = arg1->unk28;
    arg0->unk58 = arg1->unk58;
    arg0->unk1E1 = arg1->unk1E1;
    if (arg0->unk54 != arg1->unk54) {
        arg0->unk54 = arg1->unk54;
        func_80025F3C(arg0->unk54, arg0, 1, 1);
    }
    arg0->unk1E0 = arg1->unk1E0;
    if (!arg0->unk1E0 && !(arg0->unk1E1 & 4)) {
        arg0->unk2 = 0;
    } else if ((func_806119A0() % 255U) < 0x32) {
        func_80025F3C(arg0->unk54, arg0, 1, 1);
    }
}

s32 func_80026530(WaterStruct4 *arg0, s32 arg1) {
    func_80024000(arg0, arg1, arg0->unk38 * 0.5);
    func_80025F3C(arg0->unk54, arg0, 1, 1);
    return 0;
}

// Seems doable, lots of float bs though
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_8002658C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80026874.s")

extern f64 D_8002A078;

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80026904.s")

// Doable, pretty close
/*
void func_80026904(WaterStruct4 *arg0, WaterStruct2 *arg1) {
    if (arg0->unk1E2 == 2) {
        func_8002646C(arg1->next, arg1);
        return;
    }
    if (arg0->unk1E2 == 0) {
        if (arg0->unk58->unk25 != 0) {
            func_80026410(arg0);
            if (D_80029BA4 != arg0->unk54) {
                func_80026338(arg0, arg1);
                return;
            }
            if ((arg0->unk1E0 == 2) && (arg0->unk3C < D_80029BA4->unkA)) {
                func_80025DB8(arg0->unk54, arg0, 0, ((func_80665DE0(arg0->unk8, arg0->unk10, D_807FBB48->x_position, D_807FBB48->z_position) + (func_806119A0() & 0x7FF)) - 0x400), 1);
                arg0->unk1E0 = 1;
            }
        } else if (D_80029BA4 == arg0->unk54) {
            arg0->unk54 = arg0->unk58;
            func_80025F3C(arg0->unk58, arg0, 1, 1);
            arg0->unk40 = 0xFF;
        }
    }
}
*/

// TODO: Collapse some structs into 1, ws4, ws5, ws2(?)
s32 func_80026A5C(WaterStruct4 *arg0, s32 arg1) {
    WaterStruct5 *temp_v0;

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
        func_800262C0(arg0, arg1);
    } else if (D_80029BA4 == arg0->unk54) {
        if (arg0->unk1E0 == 2) {
            arg0->unk1E0 = 1;
        } else {
            arg0->unk1E0 = 2;
        }
        func_80025F3C(arg0->unk54, arg0, (arg0->unk1E0 == 2), 1);
    } else {
        arg0->unk2 = 0;
        arg0->unk34 = 0.0f;
        if (arg0->unk28 < D_8002A078) {
            arg0->unk1E0 = 0;
            arg0->unk28 = 0;
            return TRUE;
        }
    }
    return FALSE;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80026B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80026C9C.s")

/*
void func_80026C9C(void *arg0) {
    s32 temp_s1;
    u8 temp_v1;
    void *temp_t5;
    void *temp_v0;
    u8 *phi_s0;
    u8 phi_v1;
    s32 phi_s1;

    if (arg0 != 0) {
        D_80029BA4->unk0 = D_807FBB48->x_position;
        D_80029BA4->unk4 = D_807FBB48->z_position;
        phi_s0 = arg0->unk4;
        phi_s1 = 0;
        if (arg0->unk0 > 0) {
            do {
                temp_v1 = *phi_s0;
                phi_v1 = temp_v1;
                if (temp_v1 > 0) {
                    phi_v1 = temp_v1 - 1;
                }
                temp_v0 = (phi_v1 * 0x18) + ((current_character_index * 0x78) + &D_80029BAC);
                D_80029BA4->unk2 = D_807FBB48->y_position + temp_v0->unk14;
                temp_t5 = D_80029BA4;
                temp_t5->unk8 = temp_v0->unk0;
                temp_t5->unkC = temp_v0->unk4;
                temp_t5->unk10 = temp_v0->unk8;
                temp_t5->unk14 = temp_v0->unkC;
                temp_t5->unk18 = temp_v0->unk10;
                func_80026B78(phi_s0);
                temp_s1 = phi_s1 + 1;
                phi_s0 += 0xC;
                phi_s1 = temp_s1;
            } while (temp_s1 < arg0->unk0);
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80026E0C.s")

extern void func_80026E0C(s32);
extern void func_80611690(void*);

void func_80026FD0(s32 arg0) {
    D_80029BA8 = 0;
    D_80029BA0 = malloc(sizeof(unkStruct_80029BA0));
    func_80611690(D_80029BA0);
    func_80026E0C(arg0);
    D_80029BA4 = malloc(sizeof(WaterStruct7));
    func_80611690(D_80029BA4);
}

s32 func_80027034(s32 arg0) {
    if (global_properties_bitfield & 0x10) {
        if (!(global_properties_bitfield & 2)) {
            func_80026C9C(D_80029BA0);
        }
        arg0 = func_80025D1C(arg0, D_80029BA0);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_8002708C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/water/code_0/func_80027118.s")
