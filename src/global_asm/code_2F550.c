#include "common.h"

extern u8 D_global_asm_807444F0;
extern f32 D_global_asm_80747CD0;

extern void *D_global_asm_807F5DE4; // TODO: Actually a pointer to a struct (map model?)
extern void *D_global_asm_807F5E60;
extern u8 D_global_asm_807F5FEC;
extern s32 D_global_asm_807F6C28;

// close, float
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062A850.s")

/*
// getFieldOfView()
f32 func_global_asm_8062A850(void) {
    s32 phi_v1;
    f32 phi_f0;
    f32 phi_f2;
    f32 phi_f12;

    phi_f0 = 1.0f;
    if (D_global_asm_807444F0 != 1 && is_cutscene_active == 1) {
        phi_f2 = 999.0f;
    } else {
        phi_f2 = 0.02f;
    }

    phi_v1 = is_cutscene_active == 1 && current_map != MAP_MAIN_MENU;
    if (widescreen_enabled && !phi_v1) {
        phi_f0 *= 1.2;
    }

    phi_f12 = D_global_asm_80747CD0;
    if (phi_f12 < phi_f0) {
        phi_f12 += phi_f2;
        if (phi_f0 < phi_f12) {
            phi_f12 = phi_f0;
        }
    } else {
        phi_f12 -= phi_f2;
        if (phi_f12 < phi_f0) {
            phi_f12 = phi_f0;
        }
    }

    D_global_asm_80747CD0 = phi_f12;
    return phi_f12;
}
*/

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062A944.s")

extern f32 D_global_asm_807F5DF0[][3];

/*
void func_global_asm_8062A944(f32 arg0, f32 arg1, f32 arg2) {
    s32 i;
    Mtx spB0;
    Mtx sp70;
    f32 z, y, x;
    // 60
    // 5c
    f32 temp_f0; // 58
    f32 *temp0;

    temp_f0 = arg0 * 0.5;
    guRotateF(&spB0, temp_f0, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(&spB0, 0.0f, 0.0f, -arg2, &x, &y, &z);
    guRotateF(&sp70, temp_f0 * arg1, 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp70, x, y, z, &D_global_asm_807F5DF0[0][0], &D_global_asm_807F5DF0[0][1], &D_global_asm_807F5DF0[0][2]);
    guRotateF(&sp70, -(temp_f0 * arg1), 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp70, x, y, z, &D_global_asm_807F5DF0[1][0], &D_global_asm_807F5DF0[1][1], &D_global_asm_807F5DF0[1][2]);
    guRotateF(&spB0, -temp_f0, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(&spB0, 0.0f, 0.0f, -arg2, &x, &y, &z);
    guRotateF(&sp70, temp_f0 * arg1, 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp70, x, y, z, &D_global_asm_807F5DF0[2][0], &D_global_asm_807F5DF0[2][1], &D_global_asm_807F5DF0[2][2]);
    guRotateF(&sp70, -(temp_f0 * arg1), 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp70, x, y, z, &D_global_asm_807F5DF0[3][0], &D_global_asm_807F5DF0[3][1], &D_global_asm_807F5DF0[3][2]);
    for (i = 0; i < 4; i++) {
        temp_f0 = -arg2 / D_global_asm_807F5DF0[i][2];
        D_global_asm_807F5DF0[i][0] *= temp_f0;
        D_global_asm_807F5DF0[i][1] *= temp_f0;
        D_global_asm_807F5DF0[i][2] = -arg2;
    }
}
*/

void func_global_asm_8062FF10(f32 (*)[4], f32 (*)[4]);
extern f32 D_global_asm_807F5E20[][3];

void func_global_asm_8062AC68(void *arg0) {
    f32 sp98[4][4];
    f32 sp58[4][4];
    s32 i;

    guMtxL2F(sp98, arg0);
    func_global_asm_8062FF10(sp58, sp98);
    for (i = 0; i < 4; i++) {
        guMtxXFMF(sp58, D_global_asm_807F5DF0[i][0], D_global_asm_807F5DF0[i][1], D_global_asm_807F5DF0[i][2], &D_global_asm_807F5E20[i][0], &D_global_asm_807F5E20[i][1], &D_global_asm_807F5E20[i][2]);
    }
}

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062AD28.s")

void func_global_asm_8062B220(GlobalASMStruct64 *);

/*
void func_global_asm_8062AD28(f32 arg0, f32 arg1, f32 arg2, GlobalASMStruct64 *arg3, f32 *arg4) {
    f32 x;
    f32 sp78[5];
    f32 sp64[5];
    f32 sp50[5];
    GlobalASMStruct64 *var_s0;
    s32 i;

    var_s0 = arg3;
    for (i = 0; i < 4; i++) {
        var_s0++;
        var_s0[-1].unk0 = arg0;
        var_s0[-1].unk2 = arg1;
        var_s0[-1].unk4 = arg2;
        var_s0[-1].unk18 = 3;
    }
    var_s0 = arg3;

    arg3[0].unk6 = arg4[0];
    arg3[0].unk8 = arg4[1];
    arg3[0].unkA = arg4[2];
    arg3[0].unkC = arg4[3];
    arg3[0].unkE = arg4[4];
    arg3[0].unk10 = arg4[5];
    sp78[0] = arg4[6];
    sp64[0] = arg4[7];
    sp50[0] = arg4[8];

    arg3[1].unk6 = arg4[6];
    arg3[1].unk8 = arg4[7];
    arg3[1].unkA = arg4[8];
    arg3[1].unkC = arg4[0];
    arg3[1].unkE = arg4[1];
    arg3[1].unk10 = arg4[2];
    sp78[1] = arg4[9];
    sp64[1] = arg4[10];
    sp50[1] = arg4[11];

    arg3[2].unk6 = arg4[9];
    arg3[2].unk8 = arg4[10];
    arg3[2].unkA = arg4[11];
    arg3[2].unkC = arg4[6];
    arg3[2].unkE = arg4[7];
    arg3[2].unk10 = arg4[8];
    sp78[2] = arg4[0];
    sp64[2] = arg4[1];
    sp50[2] = arg4[2];

    arg3[3].unk6 = arg4[3];
    arg3[3].unk8 = arg4[4];
    arg3[3].unkA = arg4[5];
    arg3[3].unkC = arg4[9];
    arg3[3].unkE = arg4[10];
    arg3[3].unk10 = arg4[11];
    sp78[3] = arg4[0];
    sp64[3] = arg4[1];
    sp50[3] = arg4[2];

    arg3[4].unk18 = 4;
    arg3[4].unk0 = arg4[6];
    arg3[4].unk2 = arg4[7];
    arg3[4].unk4 = arg4[8];
    arg3[4].unk6 = arg4[9];
    arg3[4].unk8 = arg4[10];
    arg3[4].unkA = arg4[11];
    arg3[4].unkC = arg4[0];
    arg3[4].unkE = arg4[1];
    arg3[4].unk10 = arg4[2];
    arg3[4].unk12 = arg4[3];
    arg3[4].unk14 = arg4[4];
    arg3[4].unk16 = arg4[5];
    sp50[4] = arg2;
    sp64[4] = arg1;
    sp78[4] = arg0;
    for (i = 0; i < 5; i++) {
        func_global_asm_8062B220(var_s0);
        if ((
            (var_s0->unk20 * sp78[i]) + 
            (var_s0->unk30 * sp50[i]) +
            (var_s0->unk28 * sp64[i]) + 
            var_s0->unk38) < 0.0) {
            func_global_asm_8062B194(var_s0);
            func_global_asm_8062B220(var_s0);
        }
        var_s0++;
    }
}
*/

void func_global_asm_8062B194(GlobalASMStruct64 *arg0) {
    s16 temp1;
    s16 temp2;
    s16 temp3;

    switch ((u8)arg0->unk18) {
        case 3:
            temp1 = arg0->unk0;
            temp2 = arg0->unk2;
            temp3 = arg0->unk4;
            arg0->unk0 = arg0->unk6;
            arg0->unk2 = arg0->unk8;
            arg0->unk4 = arg0->unkA;
            arg0->unk6 = temp1;
            arg0->unk8 = temp2;
            arg0->unkA = temp3;
            return;
        case 4:
            temp1 = arg0->unk0;
            temp2 = arg0->unk2;
            temp3 = arg0->unk4;
            arg0->unk0 = arg0->unkC;
            arg0->unk2 = arg0->unkE;
            arg0->unk4 = arg0->unk10;
            arg0->unkC = temp1;
            arg0->unkE = temp2;
            arg0->unk10 = temp3;
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062B220.s")

/*
// D'oh, temp variables I guess?
void func_global_asm_8062B220(GlobalASMStruct64 *arg0) {
    arg0->unk20 = ((arg0->unk4 - arg0->unkA) * arg0->unkE) + ((arg0->unk2 * (arg0->unkA - arg0->unk10)) + (arg0->unk8 * (arg0->unk10 - arg0->unk4)));
    arg0->unk28 = ((arg0->unk0 - arg0->unk6) * arg0->unk10) + ((arg0->unk4 * (arg0->unk6 - arg0->unkC)) + (arg0->unkA * (arg0->unkC - arg0->unk0)));
    arg0->unk30 = ((arg0->unk2 - arg0->unk8) * arg0->unkC) + ((arg0->unk0 * (arg0->unk8 - arg0->unkE)) + (arg0->unk6 * (arg0->unkE - arg0->unk2)));
    arg0->unk38 = -((((arg0->unk2 * arg0->unkA) - (arg0->unk4 * arg0->unk8)) * arg0->unkC) + ((arg0->unk0 * ((arg0->unk8 * arg0->unk10) - (arg0->unkE * arg0->unkA))) + (arg0->unk6 * ((arg0->unkE * arg0->unk4) - (arg0->unk2 * arg0->unk10)))));
}
*/

typedef struct Struct8062F420 Struct8062F420;

struct Struct8062F420 {
    s32 unk0;
    Struct8062F420 *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C[1]; // TODO: How many?
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
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s16 unk70[1]; // TODO: How many?
    s16 unk72;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    u8 unkAC[4]; // TODO: How many?
    s32 unkB0;
    s32 unkB4;
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    s32 unkBC;
    s32 unkC0;
    u8 unkC4;
    u8 unkC5;
};

void func_global_asm_8062B3C4(Struct8062F420 *arg0, s32 *arg1) {
    s32 i;
    do {
        if (!arg0) {
            break;
        }
        for (i = 0; i < arg0->unkC5; i++) {
            func_global_asm_8063C3C0(arg0->unk70[i]);
            if (*arg1 < arg0->unkAC[i] + 1) {
                *arg1 = arg0->unkAC[i] + 1;
            }
        }
        func_global_asm_8062B3C4(arg0->unk0, arg1);
        arg0 = arg0->unk4;
    } while (TRUE);
}

typedef struct {
    Mtx unk0[2];
    f32 unk80; // Used
    f32 unk84; // Used
    f32 unk88; // Used
    u8 unk8C; // Used
    s8 unk8D;
    s16 unk8E;
} GlobalASMStruct73;

extern GlobalASMStruct73 *D_global_asm_807F5FB8;
extern s32 D_global_asm_807F5FBC;
extern s8 D_global_asm_807F5FC0;

void func_global_asm_8062B478(s32 arg0) {
    s32 i;

    if (arg0 == 0) {
        D_global_asm_807F5FB8 = NULL;
        D_global_asm_807F5FBC = 0;
        return;
    }
    D_global_asm_807F5FB8 = malloc(arg0 * sizeof(GlobalASMStruct73));
    D_global_asm_807F5FBC = arg0;
    for (i = 0; i < arg0; i++) {
        D_global_asm_807F5FB8[i].unk80 = 0.0f;
        D_global_asm_807F5FB8[i].unk84 = 0.0f;
        D_global_asm_807F5FB8[i].unk88 = 0.0f;
        D_global_asm_807F5FB8[i].unk8C = 1;
    }
    D_global_asm_807F5FC0 = 0;
}

void func_global_asm_8062B630(s16 arg0, u8 arg1) {
    D_global_asm_807F5FB8[arg0].unk8C = arg1;
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062B660.s")

f32 func_global_asm_8062B840(s8 arg0) {
    return D_global_asm_807F5FB8[arg0].unk80;
}

void func_global_asm_8062B86C(s32 arg0, f32 arg1, f32 arg2) {
    D_global_asm_807F5FB8[arg0].unk84 = arg1;
    D_global_asm_807F5FB8[arg0].unk88 = arg2;
}

void func_global_asm_8062B8A4(s32 arg0, f32 arg1, f32 arg2) {
    D_global_asm_807F5FB8[arg0].unk84 += arg1;
    D_global_asm_807F5FB8[arg0].unk88 = arg2;
}

void func_global_asm_8062B8E4(f32 *arg0) {
    s32 temp_t0;
    s32 i;

    temp_t0 = D_global_asm_807F5FBC;
    for (i = 0; i < temp_t0; i++) {
        arg0[i] = D_global_asm_807F5FB8[i].unk84;
    }
}

void func_global_asm_8062BA0C(f32 *arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F5FBC; i++) {
        D_global_asm_807F5FB8[i].unk84 = arg0[i];
        D_global_asm_807F5FB8[i].unk80 = arg0[i];
    }
}

typedef struct {
    void* unk0;
    void* unk4;
} Struct8062BA74_1;

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Struct8062BA74_2;

void *func_global_asm_8062BA74(Struct8062BA74_1 *arg0) {
    Struct8062BA74_2 *temp_v0;

    if (arg0 == NULL) {
        return NULL;
    }
    temp_v0 = malloc(sizeof(Struct8062BA74_2));
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0;
    temp_v0->unk1 = 3;
    temp_v0->unkC = func_global_asm_8062BA74(arg0->unk0);
    temp_v0->unk10 = func_global_asm_8062BA74(arg0->unk4);
    return temp_v0;
}

typedef struct Struct8062BB2C_arg0 Struct8062BB2C_arg0;

struct Struct8062BB2C_arg0 {
    s32 unk0;
    Struct8062BB2C_arg0* unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
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
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    s32 unkBC;
};

typedef struct Struct8062BB2C_arg1 Struct8062BB2C_arg1;

typedef struct Struct8062BB2C_arg1_unk4 Struct8062BB2C_arg1_unk4;

struct Struct8062BB2C_arg1_unk4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Struct8062BB2C_arg1_unk4 *unk14;
};

struct Struct8062BB2C_arg1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    Struct8062BB2C_arg1_unk4 *unk4;
    s32 unk8;
    Struct8062BB2C_arg1 *unkC;
    Struct8062BB2C_arg1 *unk10;
};

void func_global_asm_8062BB2C(Struct8062BB2C_arg0 *arg0, Struct8062BB2C_arg1 *arg1, u8 arg2);

void func_global_asm_8062BAE4(void) {
    func_global_asm_8063B4A4();
    func_global_asm_8062BB2C(D_global_asm_807F5DE4, D_global_asm_807F5E60, 1);
    func_global_asm_8063B758();
    func_global_asm_80641A78();
}

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062BB2C.s")

void func_global_asm_8063B4C0(Chunk14*, s32);

/*
void func_global_asm_8062BB2C(Struct8062BB2C_arg0 *arg0, Struct8062BB2C_arg1 *arg1, u8 arg2) {
    Struct8062BB2C_arg1_unk4 *next;
    Struct8062BB2C_arg1_unk4 *current;

loop_1:
    if (arg0 != NULL) {
        switch (arg1->unk1) {
            case 3:
                func_global_asm_8062BB2C(arg0->unk0, arg1->unkC, 0);
                arg2 = 0;
                arg0 = arg0->unk4;
                arg1 = arg1->unk10;
                goto loop_1;
                break;
            default:
                switch (arg0->unkB8) {
                    case 2:
                        func_global_asm_80652B04();
                        break;
                    case 1:
                        current = arg1->unk4;
                        while (current != NULL) {
                            next = current->unk14;
                            func_global_asm_8063B4C0(current, arg2);
                            current = next;
                        }
                        break;
                    case 0:
                        switch (arg1->unk1) {
                            case 1:
                            case 2:
                                if (arg1->unk0 != 0) {
                                    func_global_asm_8062BB2C(arg0->unk4, arg1->unk10, arg2);
                                    arg2 = 0;
                                    arg0 = arg0->unk0;
                                    arg1 = arg1->unkC;
                                    goto loop_1;
                                } else {
                                    func_global_asm_8062BB2C(arg0->unk0, arg1->unkC, arg2);
                                    arg2 = 0;
                                    arg0 = arg0->unk4;
                                    arg1 = arg1->unk10;
                                    goto loop_1;
                                }
                                break;
                            case 0:
                                if (arg1->unk0 == 0) {
                                    func_global_asm_8062BB2C(arg0->unk0, arg1->unkC, arg2);
                                    arg2 &= 0xFF;
                                    arg0 = arg0->unk4;
                                    arg1 = arg1->unk10;
                                    goto loop_1;
                                } else {
                                    func_global_asm_8062BB2C(arg0->unk4, arg1->unk10, arg2);
                                    arg2 &= 0xFF;
                                    arg0 = arg0->unk0;
                                    arg1 = arg1->unkC;
                                    goto loop_1;
                                }
                                break;
                        }
                        break;
                }
                break;
        }
    }
}
*/

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
    u8 unk24;
} Struct8062BDB0_arg2_unk4;

typedef struct {
    s32 unk0;
    Struct8062BDB0_arg2_unk4 *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Struct8062BDB0_arg2;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
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
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    u8 unkB8;
} Struct8062BDB0_arg1;

u8 func_global_asm_8062BDB0(s32 arg0, Struct8062BDB0_arg1 *arg1, Struct8062BDB0_arg2 *arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6);

extern void *D_global_asm_807F5DE4;

typedef struct Struct807F5FF4 Struct807F5FF4;

struct Struct807F5FF4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Struct807F5FF4 *unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
    u8 unk24;
};

extern Struct807F5FF4 *D_global_asm_807F5FF4;

u8 func_global_asm_8062BCC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    u8 var_s1;
    Struct807F5FF4 *var_s0;

    var_s1 = func_global_asm_8062BDB0(arg0, D_global_asm_807F5DE4, D_global_asm_807F5E60, arg1, arg2, arg3, arg4);
    var_s0 = D_global_asm_807F5FF4;
    while (var_s0 != NULL) {
        if (var_s0->unk24 == 1) {
            var_s1 |= func_global_asm_80668E9C(arg0, var_s0->unk1E, arg1, arg2, arg3, arg4);
        }
        var_s0 = var_s0->unk14;
    }
    return var_s1;
}

// close
// https://decomp.me/scratch/5GC3h
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062BDB0.s")

/*
// TODO: Just operands flipped in an OR instruction...
u8 func_global_asm_8062BDB0(s32 arg0, Struct8062BDB0_arg1 *arg1, Struct8062BDB0_arg2 *arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    u8 var_s1;
    Struct8062BDB0_arg2_unk4 *var_s0;

    var_s1 = 0;
    switch (arg1->unkB8) {
        case 2:
            return func_global_asm_80652BC8(arg0, arg3, arg4, arg5, arg6);
        case 1:
            var_s0 = arg2->unk4;
            if (var_s0 != NULL) {
                do {
                    if (var_s0->unk24 == 1) {
                        var_s1 |= func_global_asm_80668E9C(arg0, var_s0->unk1E, arg3, arg4, arg5, arg6);
                    }
                    var_s0 = var_s0->unk14;
                } while (var_s0 != NULL);
            }
            return var_s1;
        case 0:
            // TODO: Problem here
            var_s1 |= func_global_asm_8062BDB0(arg0, arg1->unk0, arg2->unkC, arg3, arg4, arg5, arg6);
            return var_s1 | func_global_asm_8062BDB0(arg0, arg1->unk4, arg2->unk10, arg3, arg4, arg5, arg6);
    }
    return 0;
}
*/

// Displaylist stuff, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062BF24.s")

void func_global_asm_8062C1C0(s32 arg0) {
    func_global_asm_8065EFF0();
    func_global_asm_8062D3E4(D_global_asm_807F5FF4);
    func_global_asm_8063039C();
    if (D_global_asm_807F6C28 == 0) {
        func_global_asm_8062EE48(0xFF);
    }
    func_global_asm_8065214C();
    func_global_asm_8065A884();
    func_global_asm_8065F614();
    D_global_asm_807F5FEC = 1;
}

void func_global_asm_8062C22C(void) {
    if (D_global_asm_807F6C28 != 0) {
        func_global_asm_80655BF0();
        func_global_asm_8062EFA0();
        func_global_asm_80655AD0();
        func_global_asm_80653FA4();
        func_global_asm_80653B70(0);
    }
    func_global_asm_8063C450();
    func_global_asm_8062B660();
    func_global_asm_80636C00();
    func_global_asm_806364C4();
}

// Displaylist Stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062C29C.s")

typedef struct Struct8062CA70_arg1 Struct8062CA70_arg1;

struct Struct8062CA70_arg1 {
    Struct8062CA70_arg1 *unk0;
    Struct8062CA70_arg1 *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C[1]; // Unknown count, same as unk70
    u8 pad20[0x6E - 0x20];
    s16 unk6E;
    s16 unk70[1]; // Unknown count
    u8 pad72[0x88 - 0x72];
    s16 unk88[1]; // Unknown count, same as unk70
    u8 pad8A[0xAC - 0x8A];
    u8 unkAC;
    u8 padAD[0xB8 - 0xAD];
    u8 unkB8;
    u8 unkB9[1]; // Unknown count, same as unk70
    u8 padBA[0xC5 - 0xBA];
    u8 unkC5;
};

typedef struct Struct8062CA70_arg2 Struct8062CA70_arg2;

struct Struct8062CA70_arg2 {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    s32 unk4;
    s32 unk8;
    Struct8062CA70_arg2 *unkC;
    Struct8062CA70_arg2 *unk10;
};

void func_global_asm_8062C99C(CharacterChange250 *, s32, s32, s32, s32);
Gfx *func_global_asm_8062CA70(Gfx *, Struct8062CA70_arg1 *, Struct8062CA70_arg2 *, f32, f32, f32, s32);
void func_global_asm_8062D620(s32, s32, s32, f32, f32, f32, s32, s32, s32);
s32 *func_global_asm_8070835C(Gfx *, u8);
s32 *func_global_asm_80722294(void *, Actor *, s16);
extern void *D_807F5DE8;
extern void *D_807F5DEC;
extern s32 D_807F5E64;
extern u8 D_global_asm_80750AB4;
extern f32 D_global_asm_807F5E68;
extern f32 D_global_asm_807F5FA8;
extern f32 D_global_asm_807F5FAC;
extern f32 D_global_asm_807F5FB0;
extern f32 D_global_asm_807F5FB4;
extern f32 D_global_asm_807F5FDC;
extern f32 D_global_asm_807F5FE0;
extern s32 D_global_asm_807F5FF0;

/*
Gfx *func_global_asm_8062C29C(Gfx *dl, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    void *temp_s3;

    D_807F5E64 = 0;
    D_global_asm_807F5FB4 = arg7;
    D_global_asm_807F5FB0 = arg8;
    D_global_asm_807F5FAC = arg9;
    D_global_asm_807F5FA8 = D_global_asm_807F5FAC;
    temp_s3 = &character_change_array[cc_player_index].unk1F0[D_global_asm_807444FC];
    D_global_asm_807F5FE0 = func_global_asm_80612D10(arg7 * 0.017453292f);
    D_global_asm_807F5FE0 = (((D_global_asm_807F5FE0 - D_global_asm_807F5FDC) * 3.0) + D_global_asm_807F5FDC);
    func_global_asm_8062DB70(arg1, arg2, arg3, arg4, arg5, arg6);
    func_global_asm_8062A944(D_global_asm_807F5FB4, D_global_asm_807F5FB0, D_global_asm_807F5FA8);
    func_global_asm_8062AC68(&character_change_array[cc_player_index].unk8[D_global_asm_807444FC]);
    func_global_asm_8062AD28(arg1, arg2, arg3, &D_global_asm_807F5E68, &D_global_asm_807F5E20);
    func_global_asm_8062D620(D_global_asm_807F5DE4, D_global_asm_807F5E60, D_global_asm_807F5FF0, arg1, arg2, arg3, 0, D_global_asm_807F5FEC == 0, ((s32) D_global_asm_80750AB4 < 2) ^ 1);
    gSPSegment(dl++, 0x06, osVirtualToPhysical(D_807F5DE8));
    gSPSegment(dl++, 0x07, osVirtualToPhysical(D_807F5DEC));
    dl = func_global_asm_80722294(dl, character_change_array[cc_player_index].playerPointer, cc_player_index);
    gSPSegment(dl++, 0x05, osVirtualToPhysical(temp_s3));
    gDPSetHilite1Tile(dl++, G_TX_RENDERTILE, &character_change_array[cc_player_index].unk1D0[D_global_asm_807444FC], 32, 32);
    gSPEndDisplayList(dl++);
    func_global_asm_8062C99C(&character_change_array[cc_player_index].unk250[D_global_asm_807444FC], character_change_array[cc_player_index].unk270[0], character_change_array[cc_player_index].unk270[1], character_change_array[cc_player_index].unk270[2], character_change_array[cc_player_index].unk270[3]);
    gSPPerspNormalize(dl++, character_change_array[cc_player_index].unk188);
    gSPViewport(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk250[D_global_asm_807444FC]));
    gDPSetScissorFrac(dl++, G_SC_NON_INTERLACE, character_change_array[cc_player_index].unk270[0] * 4.0f, character_change_array[cc_player_index].unk270[1] * 4.0f, character_change_array[cc_player_index].unk270[2] * 4.0f, character_change_array[cc_player_index].unk270[3] * 4.0f);
    gSPLookAt(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk190[D_global_asm_807444FC]));
    func_global_asm_80658E58(character_change_array[cc_player_index].unk270[0], character_change_array[cc_player_index].unk270[1], character_change_array[cc_player_index].unk270[2], character_change_array[cc_player_index].unk270[3]);
    dl = func_global_asm_8065919C(dl);
    dl = func_global_asm_8070835C(dl, cc_player_index);
    gSPMatrix(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk88[D_global_asm_807444FC]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk8[D_global_asm_807444FC]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    dl = func_global_asm_8062CA70(dl, D_global_asm_807F5DE4, D_global_asm_807F5E60, arg1, arg2, arg3, global_properties_bitfield);
    gDPPipeSync(dl++);
    return dl;
}
*/

void func_global_asm_8062C99C(CharacterChange250 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk0 = (arg3 - arg1) * 2;
    arg0->unk2 = (arg4 - arg2) * 2;
    arg0->unk4 = 0x1FF;
    arg0->unk6 = 0;
    arg0->unk8 = ((arg1 + arg3) / 2) * 4;
    arg0->unkA = ((arg2 + arg4) / 2) * 4;
    arg0->unkC = 0x1FF;
    arg0->unkE = 0;
}

extern s32 D_global_asm_807F5FF8;
extern u8 D_global_asm_807F6009;

// TODO: Might be a fake match?
Gfx *func_global_asm_8062CA0C(Gfx *dl, f32 arg1, f32 arg2, f32 arg3) {
    D_global_asm_807F6009 = 0xFF;
    return func_global_asm_80630B70(dl, D_global_asm_807F5FF8, arg1, arg2, arg3, 0x30030, -1, 0);
}

// Displaylist stuff, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062CA70.s")

Gfx *func_global_asm_8062CEA8(Gfx *, Struct8062CA70_arg1 *, u8);
Gfx *func_global_asm_8063A968(Gfx *, s32);
Gfx *func_global_asm_80655DD0(Gfx *, void *, f32, f32, f32, s32);
Gfx *func_global_asm_8065D994(Gfx *, s32);
extern s32 D_global_asm_807F5FFC;

/*
Gfx *func_global_asm_8062CA70(Gfx *dl, Struct8062CA70_arg1 *arg1, Struct8062CA70_arg2 *arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    u8 temp;

    loop_1:
    if (arg1 == NULL) {
        return dl;
    }
    if (arg2->unk1 == 3) {
        return dl;
    }
    switch (arg1->unkB8) {
        case 2:
            dl = func_global_asm_80655DD0(dl, arg1, arg3, arg4, arg5, arg6);
            break;
        case 1:
            D_807F5E64 += arg1->unk6E;
            if (arg6 & 0x10) {
                gSPSegment(dl++, 0x06, osVirtualToPhysical(D_807F5DE8));
                gSPSegment(dl++, 0x07, osVirtualToPhysical(D_807F5DEC));
                dl = func_global_asm_8062CEA8(dl, arg1, 1);
                dl = func_global_asm_806592B4(dl);
                dl = func_global_asm_8062EDA8(dl, 0xFFU);
                if (arg1->unk8 != -1) {
                    gSPDisplayList(dl++, osVirtualToPhysical(arg1->unk8));
                }
                if (arg1->unkC != -1) {
                    gSPDisplayList(dl++, osVirtualToPhysical(arg1->unkC));
                }
                if (arg1->unk14 != -1) {
                    gSPDisplayList(dl++, osVirtualToPhysical(arg1->unk14));
                }
                if (arg1->unk10 != -1) {
                    gSPDisplayList(dl++, osVirtualToPhysical(arg1->unk10));
                }
                if (arg1->unk18 != -1) {
                    gSPDisplayList(dl++, osVirtualToPhysical(arg1->unk18));
                }
                dl = func_global_asm_8062CEA8(dl, arg1, 2);
            }
            dl = func_global_asm_8063A968(dl, arg2->unk8);
            dl = func_global_asm_8065D994(dl, -1);
            D_global_asm_807F6009 = 0xFF;
            dl = func_global_asm_80630B70(dl, arg2->unk4, arg3, arg4, arg5, arg6, -1, 0);
            if (arg6 & 0x10) {
                gSPSegment(dl++, 0x06, osVirtualToPhysical(D_807F5DE8));
                gSPSegment(dl++, 0x07, osVirtualToPhysical(D_807F5DEC));
                dl = func_global_asm_8062CEA8(dl, arg1, 3);
                gDPPipeSync(dl++);
            }
            dl = func_global_asm_80630B70(dl, D_global_asm_807F5FFC, arg3, arg4, arg5, arg6, -1, 0);
            break;
        case 0:
            switch (arg2->unk1) {
                case 1:
                case 2:
                    if (arg2->unk0 != 0) {
                        arg1 = arg1->unk4;
                        arg2 = arg2->unk10;
                    } else {
                        arg1 = arg1->unk0;
                        arg2 = arg2->unkC;
                    }
                    goto loop_1;
                case 0:
                    if (arg2->unk0 != 0) {
                        dl = func_global_asm_8062CA70(dl, arg1->unk0, arg2->unkC, arg3, arg4, arg5, arg6);
                        arg1 = arg1->unk4;
                        arg2 = arg2->unk10;
                    } else {
                        dl = func_global_asm_8062CA70(dl, arg1->unk4, arg2->unk10, arg3, arg4, arg5, arg6);
                        arg1 = arg1->unk0;
                        arg2 = arg2->unkC;
                    }
                    goto loop_1;
            }
            break;
    }
    return dl;
}
*/

// Displaylist stuff, close, regalloc s5 s6
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062CEA8.s")

/*
Gfx *func_global_asm_8062CEA8(Gfx *dl, Struct8062CA70_arg1 *arg1, u8 arg2) {
    s32 i;
    u8 temp_v1;

    for (i = 0; i < arg1->unkC5; i++) {
        if ((arg1->unkB9[i] == arg2) && (((arg1->unk88[i] == -1)) || (func_global_asm_80652EBC(arg1->unk88[i])))) {
            dl = func_global_asm_8063C418(dl, arg1->unk70[i]);
            gSPClearGeometryMode(dl++, G_CULL_BACK);
            temp_v1 = arg1->unkAC;
            if ((D_global_asm_807F5FB8[temp_v1].unk80 != 0.0) && (D_global_asm_807F5FB8[temp_v1].unk8C)) {
                gSPMatrix(dl++, osVirtualToPhysical(&D_global_asm_807F5FB8[temp_v1].unk0[D_global_asm_807444FC]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gSPDisplayList(dl++, osVirtualToPhysical(arg1->unk1C[i]));
                gSPPopMatrix(dl++, G_MTX_MODELVIEW);
            } else {
                gSPDisplayList(dl++, osVirtualToPhysical(arg1->unk1C[i]));
            }
            gDPPipeSync(dl++);
        }
    }
    return dl;
}
*/

typedef struct Struct8062D0CC_arg0 Struct8062D0CC_arg0;
typedef struct Struct8062D0CC_arg1 Struct8062D0CC_arg1;

struct Struct8062D0CC_arg0 {
    Struct8062D0CC_arg0 *unk0;
    Struct8062D0CC_arg0 *unk4;
    u8 unk8[0xB8 - 0x8];
    u8 unkB8;
};

struct Struct8062D0CC_arg1 {
    s32 unk0;
    Chunk14 *unk4;
    s32 unk8;
    Struct8062D0CC_arg1 *unkC;
    Struct8062D0CC_arg1 *unk10;
};

u8 func_global_asm_8062D0CC(Struct8062D0CC_arg0 *arg0, Struct8062D0CC_arg1 *arg1, PropModel *arg2, u8 arg3);

void func_global_asm_8062D094(PropModel *arg0, u8 arg1) {
    func_global_asm_8062D0CC(D_global_asm_807F5DE4, D_global_asm_807F5E60, arg0, arg1);
}

u8 func_global_asm_8062D0CC(Struct8062D0CC_arg0 *arg0, Struct8062D0CC_arg1 *arg1, PropModel *arg2, u8 arg3) {
    u8 temp;
    s8 sp26;

    sp26 = 0;
    if (arg0 == NULL) {
        return 0;
    }
    switch (arg0->unkB8) {
        case 2:
            func_global_asm_806524A0(arg2, arg3);
            return 1;
        case 1:
            func_global_asm_806307CC(arg1->unk4, arg2, 0, arg3, &sp26);
            return sp26;
        case 0:
            if (func_global_asm_8062D0CC(arg0->unk0, arg1->unkC, arg2, arg3) != 0) {
                return 1;
            }
            return func_global_asm_8062D0CC(arg0->unk4, arg1->unk10, arg2, arg3);
    }
}

typedef struct Struct8062D1E0_arg0 Struct8062D1E0_arg0;
typedef struct Struct8062D1E0_arg1 Struct8062D1E0_arg1;

struct Struct8062D1E0_arg0 {
    Struct8062D1E0_arg0 *unk0;
    Struct8062D1E0_arg0 *next;
    u8 unk8[0xB8 - 0x8];
    u8 unkB8;
};

struct Struct8062D1E0_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Struct8062D1E0_arg1 *unkC;
    s32 unk10;
};

void func_global_asm_8062D1E0(Struct8062D1E0_arg0 *arg0, Struct8062D1E0_arg1 *arg1);

void func_global_asm_8062D1A8(void) {
    if (!gameIsInDKTVMode()) {
        func_global_asm_8062D1E0(D_global_asm_807F5DE4, D_global_asm_807F5E60);
    }
}

void func_global_asm_8062D1E0(Struct8062D1E0_arg0 *arg0, Struct8062D1E0_arg1 *arg1) {
    do {
        if (!arg0) {
            break;
        }
        switch (arg0->unkB8) {
            default:
                return;
            case 2:
                func_global_asm_8065297C();
                return;
            case 1:
                func_global_asm_806323C0(arg1->unk4);
                return;
            case 0:
                func_global_asm_8062D1E0(arg0->unk0, arg1->unkC);
                arg0 = arg0->next;
                arg1 = arg1->unk10;
                break;
        }
    } while (TRUE);
}

// TODO: Any cleanup possible for this?
void func_global_asm_8062D26C(Actor *arg0) {
    s32 sp1C;

    func_global_asm_80630588(0, arg0, 1, ((u8*)&sp1C+3));
    func_global_asm_8062D2AC(arg0, &sp1C, 1);
}

u8 func_global_asm_8062D2F0(Struct8062D0CC_arg0 *arg0, Struct8062D0CC_arg1 *arg1, PropModel *arg2, s32 arg3, u8 arg4);

u8 func_global_asm_8062D2AC(void *arg0, void *arg1, u8 arg2) {
    return func_global_asm_8062D2F0(D_global_asm_807F5DE4, D_global_asm_807F5E60, arg0, arg1, arg2);
}

u8 func_global_asm_8062D2F0(Struct8062D0CC_arg0 *arg0, Struct8062D0CC_arg1 *arg1, PropModel *arg2, s32 arg3, u8 arg4) {
    u8 sp27;

    if (arg0 == NULL) {
        return FALSE;
    }
    switch (arg0->unkB8) {
        case 2:
            return func_global_asm_80652594(arg2, arg3, arg4);
        case 1:
            arg1->unk4 = func_global_asm_80630588(arg1->unk4, arg2, 0, &sp27);
            return sp27;
        case 0:
            if (func_global_asm_8062D2F0(arg0->unk0, arg1->unkC, arg2, arg3, arg4)) {
                if (arg4 == 0) {
                    return TRUE;
                }
            }
            return func_global_asm_8062D2F0(arg0->unk4, arg1->unk10, arg2, arg3, arg4);
    }
    return FALSE;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0xB8 - 0x8];
    u8 unkB8;
} Struct8062D414_arg0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Struct8062D414_arg1;

void func_global_asm_8062D414(Struct8062D414_arg0 *arg0, Struct8062D414_arg1 *arg1, Chunk14 *arg2);

void func_global_asm_8062D3E4(void *arg0) {
    func_global_asm_8062D414(D_global_asm_807F5DE4, D_global_asm_807F5E60, arg0);
}

s32 func_global_asm_8062E898(void *, void *, f32, f32, f32);
void func_global_asm_80652374(Chunk14 *);

// Arg0 might be map model
void func_global_asm_8062D414(Struct8062D414_arg0 *arg0, Struct8062D414_arg1 *arg1, Chunk14 *arg2) {
    s32 temp;
    Chunk14 *var_s1;
    Chunk14 *var_s2;
    s16 sp5A;

    var_s1 = NULL;
    var_s2 = NULL;
    if (arg0 != NULL) {
        switch (arg0->unkB8) {
            case 2:
                while (arg2 != NULL) {
                    func_global_asm_80652374(arg2);
                    arg2 = arg2->next;
                }
                break;
            case 1:
                while (arg2 != NULL) {
                    arg1->unk4 = func_global_asm_806303C4(arg1->unk4, arg2->unk24, arg2->unk0, arg2->unk4, arg2->unk8, arg2->unkC, arg2->unk1C, arg2->unk1E, arg2->unk22, arg2->unk20, 0);
                    arg2 = arg2->next;
                }
                break;
            case 0:
                while (arg2 != NULL) {
                    if (func_global_asm_8062E898(arg0, &sp5A, arg2->unk4, arg2->unk8, arg2->unkC) != 0) {
                        var_s2 = func_global_asm_806303C4(var_s2, arg2->unk24, arg2->unk0, arg2->unk4, arg2->unk8, arg2->unkC, arg2->unk1C, arg2->unk1E, arg2->unk22, arg2->unk20, 0);
                    } else {
                        var_s1 = func_global_asm_806303C4(var_s1, arg2->unk24, arg2->unk0, arg2->unk4, arg2->unk8, arg2->unkC, arg2->unk1C, arg2->unk1E, arg2->unk22, arg2->unk20, 0);
                    }
                    arg2 = arg2->next;
                }
                func_global_asm_8062D414(arg0->unk0, arg1->unkC, var_s1);
                func_global_asm_8062D414(arg0->unk4, arg1->unk10, var_s2);
                func_global_asm_806306D0(var_s1);
                func_global_asm_806306D0(var_s2);
                break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062D620.s")

s32 func_global_asm_8062DBDC(s16, s16, s16, s16, s32, s32, f32, f32, f32, f32, s32 *);
extern f32 D_global_asm_807F5FA8;

typedef struct {
    u8 unk0[0xA0 - 0x0];
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
    s16 unkAA;
} Struct8062DAF4;

void func_global_asm_8062DAF4(Struct8062DAF4 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_global_asm_8062DBDC(arg0->unkA0, arg0->unkA2, arg0->unkA4, arg0->unkA6, arg0->unkA8, arg0->unkAA, arg1, arg2, arg3, D_global_asm_807F5FA8, &D_global_asm_807F5E68);
}

extern f32 D_global_asm_807F5E50[4];

void func_global_asm_8062DB70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    D_global_asm_807F5E50[0] = arg3 - arg0;
    D_global_asm_807F5E50[1] = arg4 - arg1;
    D_global_asm_807F5E50[2] = arg5 - arg2;
    D_global_asm_807F5E50[3] = -((D_global_asm_807F5E50[0] * arg0) + (D_global_asm_807F5E50[1] * arg1) + (D_global_asm_807F5E50[2] * arg2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062DBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062E040.s")

/*
f32 func_global_asm_8062E040(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 sp3C;
    f32 sp30;
    f32 sp38;
    f32 var_f20;
    f32 temp_f24;
    f32 temp_f16_2;
    f32 temp_f22;

    sp3C = (arg0 - arg6) * (arg0 - arg6);
    sp38 = (arg1 - arg7) * (arg1 - arg7);
    temp_f22 = (arg2 - arg8) * (arg2 - arg8);
    temp_f24 = (arg5 - arg8) * (arg5 - arg8);
    var_f20 = (sp3C + sp38) + temp_f22;
    sp30 = (sp3C + sp38) + temp_f24;
    if (sp30 < var_f20) {
        var_f20 = sp30;
    }
    temp_f16_2 = (arg4 - arg7) * (arg4 - arg7);
    if (((sp3C + temp_f16_2) + temp_f22) < var_f20) {
        var_f20 = ((sp3C + temp_f16_2) + temp_f22);
    }
    if (((sp3C + temp_f16_2) + temp_f24) < var_f20) {
        var_f20 = ((sp3C + temp_f16_2) + temp_f24);
    }
    if (((((arg3 - arg6) * (arg3 - arg6)) + sp38) + temp_f22) < var_f20) {
        var_f20 = ((((arg3 - arg6) * (arg3 - arg6)) + sp38) + temp_f22);
    }
    if (((((arg3 - arg6) * (arg3 - arg6)) + sp38) + temp_f24) < var_f20) {
        var_f20 = ((((arg3 - arg6) * (arg3 - arg6)) + sp38) + temp_f24);
    }
    if (((((arg3 - arg6) * (arg3 - arg6)) + temp_f16_2) + temp_f22) < var_f20) {
        var_f20 = ((((arg3 - arg6) * (arg3 - arg6)) + temp_f16_2) + temp_f22);
    }
    if (((((arg3 - arg6) * (arg3 - arg6)) + temp_f16_2) + temp_f24) < var_f20) {
        var_f20 = ((((arg3 - arg6) * (arg3 - arg6)) + temp_f16_2) + temp_f24);
    }
    return sqrtf(var_f20);
}
*/

// regalloc
// https://decomp.me/scratch/QdSOv
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062E1F8.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct8062E67C;

void func_global_asm_8062E3B4(Struct8062E67C *arg0, f32 *arg1, s32 arg2, s32 *arg3, s32 arg4, f64 arg6, s32 arg8);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34[3];
} Struct8062E1F8;

/*
s32 func_global_asm_8062E1F8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, Struct8062E1F8 *arg7) {
    Struct8062E1F8 *temp_a0;
    s32 pad[1];
    f32 sp88[4][4];
    s32 pad3[2];
    f32 sp40[4][4];
    s32 sp3C;
    s32 pad2;
    temp_a0 = &arg7[arg0];
    func_global_asm_8062E3B4(temp_a0, &sp88, temp_a0->unk18, &sp3C, 0, arg1, 0);
    if (sp3C == 0) {
        return FALSE;
    }
    func_global_asm_8062E3B4(&sp88, &sp40, sp3C, &sp3C, 0, arg4, 1);
    if (sp3C == 0) {
        return FALSE;
    }
    func_global_asm_8062E3B4(&sp40, &sp88, sp3C, &sp3C, 1, arg2, 0);
    if (sp3C == 0) {
        return FALSE;
    }
    func_global_asm_8062E3B4(&sp88, &sp40, sp3C, &sp3C, 1, arg5, 1);
    if (sp3C == 0) {
        return FALSE;
    }
    func_global_asm_8062E3B4(&sp40, &sp88, sp3C, &sp3C, 2, arg3, 0);
    if (sp3C == 0) {
        return FALSE;
    }
    func_global_asm_8062E3B4(&sp88, &sp40, sp3C, &sp3C, 2, arg6, 1);
    if (sp3C != 0) {
        return TRUE;
    }
    return FALSE;
}
*/

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062E3B4.s")

void func_global_asm_8062E67C(Struct8062E67C *arg0, Struct8062E67C *arg1, u8 arg2, f64 arg4, Struct8062E67C *arg6);

/*
void func_global_asm_8062E3B4(Struct8062E67C *arg0, f32 *arg1, s32 arg2, s32 *arg3, s32 arg4, f64 arg6, s32 arg8) {
    s32 i;
    Struct8062E67C sp60;
    Struct8062E67C *temp;

    *arg3 = 0;
    temp = &arg0[arg2 - 1];
    for (i = 0; i < arg2; i++, temp++, arg0++) {
        if (func_global_asm_8062E548(&arg0, arg4, arg6, arg8)) {
            if (func_global_asm_8062E548(temp, arg4, arg6, arg8)) {
                func_global_asm_8062E608(&arg0, arg3, arg1);
            } else {
                func_global_asm_8062E67C(temp, &arg0, arg4, arg6, &sp60);
                func_global_asm_8062E608(&sp60, arg3, arg1);
                func_global_asm_8062E608(&arg0, arg3, arg1);
            }
        } else if (func_global_asm_8062E548(temp, arg4, arg6, arg8)) {
            func_global_asm_8062E67C(temp, &arg0, arg4, arg6, &sp60);
            func_global_asm_8062E608(&sp60, arg3, arg1);
        }
    }
}
*/

s32 func_global_asm_8062E548(s16 *arg0, u8 arg1, f64 arg3, u8 arg4) {
    f64 phi_f0;

    switch (arg1) {
        case 0:
            phi_f0 = arg0[0];
            break;
        case 1:
            phi_f0 = arg0[1];
            break;
        case 2:
            phi_f0 = arg0[2];
            break;
    }
    switch (arg4) {
        case 0:
            if (arg3 <= phi_f0) {
                return TRUE;
            }
            break;
        case 1:
            if (phi_f0 <= arg3) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void func_global_asm_8062E608(void *arg0, s32 *arg1, s32 arg2) {
    // TODO: sizeof()?
    memcpy((*arg1 * 6) + arg2, arg0, 6);
    *arg1 += 1;
    if (*arg1 >= 0xD) {
        raiseException(1, 0, 0, 0);
    }
}

void func_global_asm_8062E67C(Struct8062E67C *arg0, Struct8062E67C *arg1, u8 arg2, f64 arg4, Struct8062E67C *arg6) {
    f32 temp_f0;

    switch (arg2) {
        case 0:
            temp_f0 = (arg4 - arg0->unk0) / (arg1->unk0 - arg0->unk0);
            arg6->unk2 = arg0->unk2 + ((arg1->unk2 - arg0->unk2) * temp_f0);
            arg6->unk4 = arg0->unk4 + ((arg1->unk4 - arg0->unk4) * temp_f0);
            arg6->unk0 = arg4;
            return;
        case 1:
            temp_f0 = (arg4 - arg0->unk2) / (arg1->unk2 - arg0->unk2);
            arg6->unk0 = arg0->unk0 + ((arg1->unk0 - arg0->unk0) * temp_f0);
            arg6->unk4 = arg0->unk4 + ((arg1->unk4 - arg0->unk4) * temp_f0);
            arg6->unk2 = arg4;
            return;
        case 2:
            temp_f0 = (arg4 - arg0->unk4) / (arg1->unk4 - arg0->unk4);
            arg6->unk0 = arg0->unk0 + ((arg1->unk0 - arg0->unk0) * temp_f0);
            arg6->unk2 = arg0->unk2 + ((arg1->unk2 - arg0->unk2) * temp_f0);
            arg6->unk4 = arg4;
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062E898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062EBB8.s")

typedef struct {
    u8 unk0[0x4C - 0x00];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
} Struct8062EBB8_arg0;

/*
s32 func_global_asm_8062EBB8(Struct8062EBB8_arg0 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 i;
    f64 temp_f0_2;
    f64 temp_f2_3;
    f32 temp_f30;
    f64 var_f12;
    f32 temp00;
    f32 temp01;
    f32 temp02;
    f64 temp;
    f64 temp2;
    f64 temp3;

    i = 0;

    temp_f30 = arg0->unk58;
    temp_f30 += arg0->unk4C * arg1;
    temp_f30 += arg0->unk50 * arg2;
    temp_f30 += arg0->unk54 * arg3;

    // temp_f30 = temp_f30 + temp00 + temp01 + temp02;
    var_f12 = (f64)temp_f30 / sqrtf((arg0->unk4C * arg0->unk4C) + (arg0->unk50 * arg0->unk50) + (arg0->unk54 * arg0->unk54));
    if (var_f12 < 0.0) {
        var_f12 = 0.0 - var_f12;
    }
    if (var_f12 > 300.0) {
        return 2;
    }
    while (i < 4) {
        temp = arg0->unk4C;
        temp2 = arg0->unk50;
        temp3 = arg0->unk54;

        temp *= (D_global_asm_807F5E20[i][0] - arg1);
        temp2 *= (D_global_asm_807F5E20[i][1] - arg2);
        temp3 *= (D_global_asm_807F5E20[i][2] - arg3);

        temp_f0_2 = 
            temp +
            temp2 +
            temp3;

        if ((temp_f0_2 > 0.01) || (temp_f0_2 < -0.01)) {
            temp_f2_3 = temp_f30 / temp_f0_2;
            if ((temp_f2_3 <= 0.0) && ((0.0 - temp_f2_3) <= 1.0)) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}
*/

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    void *unk8;
    s32 unkC[1]; // TODO: How many?
    u8 unk10[0x7C - 0x10];
} Struct807F5FC4;

extern u8 D_global_asm_807F5FC1;
extern Struct807F5FC4 *D_global_asm_807F5FC4;

Gfx *func_global_asm_8062EDA8(Gfx *dl, u8 arg1) {
    s32 i;
    for (i = 0; i < D_global_asm_807F5FC1; i++) {
        if (arg1 == D_global_asm_807F5FC4[i].unk1) {
            gSPSegment(dl++, D_global_asm_807F5FC4[i].unk0, D_global_asm_807F5FC4[i].unk8);
        }
    }
    return dl;
}

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062EE48.s")

/*
void func_global_asm_8062EE48(u8 arg0) {
    s32 i;
    s32 var_v1;
    void *temp_a0;

    for (i = 0; i < D_global_asm_807F5FC1; i++) {
        if (arg0 == D_global_asm_807F5FC4[i].unk1) {
            var_v1 = FALSE;
            D_global_asm_807F5FC4[i].unk4++;
            if (D_global_asm_807F5FC4[i].unk4 == D_global_asm_807F5FC4[i].unk2) {
                var_v1 = TRUE;
                D_global_asm_807F5FC4[i].unk4 = 0;
                D_global_asm_807F5FC4[i].unk5++;
                if (D_global_asm_807F5FC4[i].unk5 == D_global_asm_807F5FC4[i].unk3) {
                    D_global_asm_807F5FC4[i].unk5 = 0;
                }
            }
            if (D_global_asm_807F5FC4[i].unk8 == NULL) {
                var_v1 = TRUE;
            }
            if (var_v1) {
                if (D_global_asm_807F5FC4[i].unk8 != NULL) {
                    func_global_asm_8066B434(D_global_asm_807F5FC4[i].unk8, 0x7E3, 5);
                }
                D_global_asm_807F5FC4[i].unk8 = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, D_global_asm_807F5FC4[i].unkC[D_global_asm_807F5FC4[i].unk5], 0, 0);
            }
        }
    }
}
*/

void func_global_asm_8062EFA0(void) {
    s32 i;
    void *temp_a0;

    for (i = 0; i < D_global_asm_807F5FC1; i++) {
        if (func_global_asm_80652E58(D_global_asm_807F5FC4[i].unk1) == 0) {
            temp_a0 = D_global_asm_807F5FC4[i].unk8;
            if (temp_a0 != NULL) {
                func_global_asm_8066B434(temp_a0, 0x7FB, 5);
                D_global_asm_807F5FC4[i].unk8 = NULL;
            }
        }
    }
}

// close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062F050.s")

extern MapGeometryHeader *D_807F5DE0;
extern s32 D_global_asm_807F5FC8;
extern void *D_global_asm_807F5FCC;
extern s32 D_global_asm_807F5FD0;
extern f32 D_global_asm_807F5FDC;
extern s16 D_807F5FE4;
extern s16 D_807F5FE6;
extern s16 D_807F5FE8;
extern s16 D_807F5FEA;
extern s16 D_807F9450;
extern s16 D_807F9452;
extern s16 D_807F9454;
extern s16 D_807F9456;
extern s32 D_807FB5E0;
extern s32 D_807FB5E4;
extern s16 D_807FB5E8;
extern s16 D_807FB5EA;
extern u8 D_global_asm_807F5FED;

extern f32 D_global_asm_807444C4;

extern s16 D_global_asm_807FD576;
extern s16 D_global_asm_807FD578;

/*
void func_global_asm_8062F050(MapGeometryHeader *arg0) {
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 *temp_a0;
    s32 sp44;
    s32 *temp_a1;
    s32 *temp_v1;
    s32 *temp_0;
    s32 *temp_1;
    s32 *temp_2;
    s32 pad;
    s32 sp28;

    sp28 = 0;
    D_807F5DE0 = arg0;
    D_global_asm_807F5FDC = func_global_asm_80612D10(0.7853981853);
    func_global_asm_80659110(arg0->unk8 & 1);
    func_global_asm_8065CDA0((arg0->unk8 >> 1) & 1);
    D_global_asm_807444C4 = arg0->unkA;
    D_807FB5E0 = arg0->unk14 * 8;
    D_807FB5E4 = arg0->unk16 * 8;
    D_807FB5E8 = arg0->unk10;
    D_807FB5EA = arg0->unk12;
    D_807F9450 = arg0->unk1C;
    D_807F9452 = arg0->unk1E;
    D_807F9454 = arg0->unk18;
    D_807F9456 = arg0->unk1A;
    D_global_asm_807FD574.pos.x = arg0->unk20.x;
    D_global_asm_807FD576 = arg0->unk20.y; // Kinda yuck
    D_global_asm_807FD578 = arg0->unk20.z;
    D_807F5FE4 = arg0->unk26;
    D_807F5FE6 = arg0->unk28;
    D_807F5FE8 = arg0->unk2A;
    D_807F5FEA = arg0->unk2C;
    sp54 = arg0->unk30;
    sp50 = arg0->unk34;
    sp4C = arg0->unk38;
    sp44 = arg0->unk40;
    temp_v1 = FILEOFFSET(&D_807F5DE0->unk0, sp44);
    temp_a0 = FILEOFFSET(&D_807F5DE0->unk0, arg0->unk44);
    temp_a1 = FILEOFFSET(&D_807F5DE0->unk0, arg0->unk48);
    D_global_asm_807F5FD0 = *temp_v1 + 1;
    D_global_asm_807F5FD4 = temp_v1 + 1;
    D_global_asm_807F5FC8 = *temp_a0;
    D_global_asm_807F5FCC = temp_a0 + 1;
    D_global_asm_807F5FC1 = *temp_a1;
    D_global_asm_807F5FC4 = temp_a1 + 1;
    D_global_asm_807F5DE4 = FILEOFFSET(&D_807F5DE0->unk0, sp54);
    D_807F5DE8 = FILEOFFSET(&D_807F5DE0->unk0, sp4C);
    D_807F5DEC = FILEOFFSET(&D_807F5DE0->unk0, sp50);
    func_global_asm_80659DB0(1.0f, 1.0f, 1.0f, -1);
    func_global_asm_8065996C(-1);
    func_global_asm_8065E040(arg0->unkE << 0xA);
    func_global_asm_8062F420(FILEOFFSET(&D_807F5DE0->unk0, sp54), FILEOFFSET(&D_807F5DE0->unk0, sp54), FILEOFFSET(&D_807F5DE0->unk0, sp50));
    func_global_asm_8062F3A0(FILEOFFSET(&D_807F5DE0->unk0, sp50), FILEOFFSET(&D_807F5DE0->unk0, sp4C));
    func_global_asm_8062F328(FILEOFFSET(&D_807F5DE0->unk0, sp44));
    func_global_asm_8063C390();
    func_global_asm_8062B3C4(D_global_asm_807F5DE4, &sp28);
    func_global_asm_8062B478(sp28);
    D_global_asm_807F5E60 = func_global_asm_8062BA74(D_global_asm_807F5DE4);
    func_global_asm_80650ECC(arg0);
    func_global_asm_8066C958(arg0);
    func_global_asm_80666090(arg0);
    func_global_asm_8065F1C0(arg0);
    func_global_asm_80662B90(arg0);
    func_global_asm_806637C0(arg0);
    func_global_asm_8062F318();
}
*/

void func_global_asm_8062F318(void) {
    D_global_asm_807F5FED = 1;
}

void func_global_asm_8062F328(s32 arg0) {
    s32 i;
    s32 temp;

    if (D_global_asm_807F5FD0 != 0) {
        for (i = 0; i <= D_global_asm_807F5FD0; i++) {
            temp = D_global_asm_807F5FD4->unk0[i];
            D_global_asm_807F5FD4->unk0[i] = temp + arg0;
        }
    }
}

s32 func_global_asm_8062F388(s32 *arg0) {
    *arg0 = D_global_asm_807F5FCC;
    return D_global_asm_807F5FC8;
}

// Regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062F3A0.s")

/*
void func_global_asm_8062F3A0(Gfx *arg0, void *arg1) {
    while (arg0 != arg1) {
        if ((arg0->words.w0 >> 0x18) == G_SETTIMG) {
            if (((arg0->words.w1 << 4) >> 28) == 0) { // TODO: Bitfield?
                arg0->words.w1 = getPointerTableFile(TABLE_25_TEXTURES_GEOMETRY, arg0->words.w1, 1, 0);
            }
        }
        arg0++;
    }
}
*/

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062F420.s")

/*
void func_global_asm_8062F420(Struct8062F420 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    if (arg0 != NULL) {
        switch (arg0->unkB8) {
            case 0:
                do {
                    arg0->unk0 += arg1;
                    arg0->unk4 += arg1;
                    func_global_asm_8062F420(arg0->unk0, arg1, arg2);
                    arg0 = arg0->unk4;
                } while (arg0 != NULL);
                break;
            case 1:
            case 2:
                if (arg0->unk8 != -1) {
                    arg0->unk8 += arg2;
                }
                if (arg0->unkC != -1) {
                    arg0->unkC += arg2;
                }
                if (arg0->unk10 != -1) {
                    arg0->unk10 += arg2;
                }
                if (arg0->unk14 != -1) {
                    arg0->unk14 += arg2;
                }
                if (arg0->unk18 != -1) {
                    arg0->unk18 += arg2;
                }
                for (i = 0; i < arg0->unkC5; i++) {
                    arg0->unk1C[i] += arg2;
                }
                break;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062F538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062F640.s")

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062F998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062FBC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_global_asm_8062FF10.s")
