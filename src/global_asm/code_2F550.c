#include <ultra64.h>
#include "functions.h"


extern u8 D_807444F0;
extern f32 D_80747CD0;
extern f32 D_80758160;
extern f32 D_80758164;
extern f64 D_80758168;

extern void *D_807F5DE4; // TODO: Actually a pointer to a struct (map model?)
extern s32 D_807F5E60;
extern s8 D_807F5FEC;
extern s32 D_807F6C28;

extern s32 D_807F5E60;

void func_8062D0CC(s32, s32, s32, u8);
void func_8062D3E4(s32 arg0);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062A850.s")

/*
// TODO: Pretty close :)
// getFieldOfView()
f32 func_8062A850(void) {
    s32 phi_v1;
    f32 phi_f0;
    f32 phi_f2;
    f32 phi_f12;

    phi_f0 = 1.0f;
    if (D_807444F0 != 1 && is_cutscene_active == 1) {
        phi_f2 = D_80758160;
    } else {
        phi_f2 = D_80758164;
    }

    phi_v1 = is_cutscene_active == 1 && current_map != MAP_MAIN_MENU;
    if (widescreen_enabled && !phi_v1) {
        phi_f0 *= D_80758168;
    }

    if (D_80747CD0 < phi_f0) {
        phi_f12 = D_80747CD0 + phi_f2;
        if (phi_f0 < phi_f12) {
            phi_f12 = phi_f0;
        }
    } else {
        phi_f12 = D_80747CD0 - phi_f2;
        if (phi_f12 < phi_f0) {
            phi_f12 = phi_f0;
        }
    }

    D_80747CD0 = phi_f12;
    return phi_f12;
}
*/

// Rotating a bunch of matrices
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062A944.s")

// Matrix, loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062AC68.s")

// Copying matrices?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062AD28.s")

typedef struct {
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
    s16 unk14;
    s16 unk16;
    u8 unk18;
    u8 unk19;
    u16 unk1A;
    u32 unk1C;
    f64 unk20;
    f64 unk28;
    f64 unk30;
    f64 unk38;
} GlobalASMStruct64;

void func_8062B194(GlobalASMStruct64 *arg0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062B220.s")

/*
// D'oh, temp variables I guess?
void func_8062B220(GlobalASMStruct64 *arg0) {
    arg0->unk20 = ((arg0->unk4 - arg0->unkA) * arg0->unkE) + ((arg0->unk2 * (arg0->unkA - arg0->unk10)) + (arg0->unk8 * (arg0->unk10 - arg0->unk4)));
    arg0->unk28 = ((arg0->unk0 - arg0->unk6) * arg0->unk10) + ((arg0->unk4 * (arg0->unk6 - arg0->unkC)) + (arg0->unkA * (arg0->unkC - arg0->unk0)));
    arg0->unk30 = ((arg0->unk2 - arg0->unk8) * arg0->unkC) + ((arg0->unk0 * (arg0->unk8 - arg0->unkE)) + (arg0->unk6 * (arg0->unkE - arg0->unk2)));
    arg0->unk38 = -((((arg0->unk2 * arg0->unkA) - (arg0->unk4 * arg0->unk8)) * arg0->unkC) + ((arg0->unk0 * ((arg0->unk8 * arg0->unk10) - (arg0->unkE * arg0->unkA))) + (arg0->unk6 * ((arg0->unkE * arg0->unk4) - (arg0->unk2 * arg0->unk10)))));
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062B3C4.s")

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
    f32 unk80; // Used
    f32 unk84; // Used
    f32 unk88; // Used
    s8 unk8C; // Used
    s8 unk8D;
    s16 unk8E;
} GlobalASMStruct73;

extern GlobalASMStruct73 *D_807F5FB8;
extern s32 D_807F5FBC;
extern s8 D_807F5FC0;

void func_8062B478(s32 arg0) {
    s32 i;

    if (arg0 == 0) {
        D_807F5FB8 = NULL;
        D_807F5FBC = 0;
        return;
    }
    D_807F5FB8 = malloc(arg0 * sizeof(GlobalASMStruct73));
    D_807F5FBC = arg0;
    for (i = 0; i < arg0; i++) {
        D_807F5FB8[i].unk80 = 0.0f;
        D_807F5FB8[i].unk84 = 0.0f;
        D_807F5FB8[i].unk88 = 0.0f;
        D_807F5FB8[i].unk8C = 1;
    }
    D_807F5FC0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062B630.s")

/*
// TODO: Regalloc, hmm
// Eliminating the temp variable doesn't fix it
// Datatypes are correct for the params I believe
void func_8062B630(s16 arg0, s8 arg1) {
    GlobalASMStruct73 *temp = &D_807F5FB8[arg0];
    temp->unk8C = arg1;
}
*/

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062B660.s")

f32 func_8062B840(s8 arg0) {
    return D_807F5FB8[arg0].unk80;
}

void func_8062B86C(s32 arg0, f32 arg1, f32 arg2) {
    D_807F5FB8[arg0].unk84 = arg1;
    D_807F5FB8[arg0].unk88 = arg2;
}

void func_8062B8A4(s32 arg0, f32 arg1, f32 arg2) {
    D_807F5FB8[arg0].unk84 += arg1;
    D_807F5FB8[arg0].unk88 = arg2;
}

void func_8062B8E4(f32 *arg0) {
    s32 temp_t0;
    s32 i;

    temp_t0 = D_807F5FBC;
    for (i = 0; i < temp_t0; i++) {
        arg0[i] = D_807F5FB8[i].unk84;
    }
}

void func_8062BA0C(f32 *arg0) {
    s32 i;

    for (i = 0; i < D_807F5FBC; i++) {
        D_807F5FB8[i].unk84 = arg0[i];
        D_807F5FB8[i].unk80 = arg0[i];
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

void *func_8062BA74(Struct8062BA74_1 *arg0) {
    Struct8062BA74_2 *temp_v0;

    if (arg0 == NULL) {
        return NULL;
    }
    temp_v0 = malloc(sizeof(Struct8062BA74_2));
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0;
    temp_v0->unk1 = 3;
    temp_v0->unkC = func_8062BA74(arg0->unk0);
    temp_v0->unk10 = func_8062BA74(arg0->unk4);
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

void func_8062BB2C(Struct8062BB2C_arg0 *arg0, Struct8062BB2C_arg1 *arg1, u8 arg2);

void func_8062BAE4(void) {
    func_8063B4A4();
    func_8062BB2C(D_807F5DE4, D_807F5E60, 1);
    func_8063B758();
    func_80641A78();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062BB2C.s")

void func_8063B4C0(Chunk14*, u8);

/*
// TODO: Pretty close, need to untangle the conditionals
void func_8062BB2C(Struct8062BB2C_arg0 *arg0, Struct8062BB2C_arg1 *arg1, u8 arg2) {
    Struct8062BB2C_arg1_unk4 *temp_s1;
    Struct8062BB2C_arg1_unk4 *var_s0_2;

loop_1:
    if (arg0 != NULL) {
loop_2:
        if (arg1->unk1 == 3) {
            arg2 = 0;
            func_8062BB2C(arg0->unk0, arg1->unkC, 0);
            arg0 = arg0->unk4;
            arg1 = arg1->unk10;
            goto loop_1;
        } else {
            if (arg0->unkB8 != 0) {
                if (arg0->unkB8 != 1) {
                    if (arg0->unkB8 == 2) {
                        func_80652B04();
                    }
                } else {
                    var_s0_2 = arg1->unk4;
                    while (var_s0_2 != NULL) {
                        temp_s1 = var_s0_2->unk14;
                        func_8063B4C0(var_s0_2, arg2);
                        var_s0_2 = temp_s1;
                    }
                }
            } else if (arg1->unk1 != 0) {
                if (arg1->unk1 != 1) {
                    if (arg1->unk1 == 2) {
                        goto block_14;
                    }
                } else {
block_14:
                    if (arg1->unk0 != 0) {
                        arg2 = 0;
                        func_8062BB2C(arg0->unk4, arg1->unk10, arg2);
                        arg0 = arg0->unk0;
                        arg1 = arg1->unkC;
                    } else {
                        arg2 = 0;
                        func_8062BB2C(arg0->unk0, arg1->unkC, arg2);
                        arg0 = arg0->unk4;
                        arg1 = arg1->unk10;
                    }
                    goto loop_1;
                }
            } else {
                if (arg1->unk0 != 0) {
                    func_8062BB2C(arg0->unk0, arg1->unkC, arg2);
                    arg2 &= 0xFF;
                    arg0 = arg0->unk4;
                    arg1 = arg1->unk10;
                    goto loop_1;
                }
                func_8062BB2C(arg0->unk4, arg1->unk10, arg2);
                arg2 &= 0xFF;
                arg0 = arg0->unk0;
                arg1 = arg1->unkC;
                if (arg0 == NULL) {

                } else {
                    goto loop_2;
                }
            }
        }
    }
}
*/

u8 func_8062BDB0(s32 arg0, void *arg1, void *arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6);      // extern
u8 func_80668E9C(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5);
extern void *D_807F5DE4;

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

extern Struct807F5FF4 *D_807F5FF4;

u8 func_8062BCC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    u8 var_s1;
    Struct807F5FF4 *var_s0;

    var_s1 = func_8062BDB0(arg0, D_807F5DE4, D_807F5E60, arg1, arg2, arg3, arg4);
    var_s0 = D_807F5FF4;
    while (var_s0 != NULL) {
        if (var_s0->unk24 == 1) {
            var_s1 |= func_80668E9C(arg0, var_s0->unk1E, arg1, arg2, arg3, arg4);
        }
        var_s0 = var_s0->unk14;
    }
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062BDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062BF24.s")

void func_8062C1C0(s32 arg0) {
    func_8065EFF0();
    func_8062D3E4(D_807F5FF4);
    func_8063039C();
    if (D_807F6C28 == 0) {
        func_8062EE48(0xFF);
    }
    func_8065214C();
    func_8065A884();
    func_8065F614();
    D_807F5FEC = 1;
}

void func_8062C22C(void) {
    if (D_807F6C28 != 0) {
        func_80655BF0();
        func_8062EFA0();
        func_80655AD0();
        func_80653FA4();
        func_80653B70(0);
    }
    func_8063C450();
    func_8062B660();
    func_80636C00();
    func_806364C4();
}

// Displaylist Stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062C29C.s")

// TODO: Just a s16*?
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} GlobalASMStruct_8062C99C;

void func_8062C99C(GlobalASMStruct_8062C99C *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk0 = (arg3 - arg1) * 2;
    arg0->unk2 = (arg4 - arg2) * 2;
    arg0->unk4 = 0x1FF;
    arg0->unk6 = 0;
    arg0->unk8 = ((arg1 + arg3) / 2) * 4;
    arg0->unkA = ((arg2 + arg4) / 2) * 4;
    arg0->unkC = 0x1FF;
    arg0->unkE = 0;
}

// TODO: What is the actual signature?
void func_80630B70(s32, s32, f32, f32, f32, s32, s32, s32);

extern s32 D_807F5FF8;
extern u8 D_807F6009;

// TODO: Might be a fake match?
void func_8062CA0C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_807F6009 = 0xFF;
    func_80630B70(arg0, D_807F5FF8, arg1, arg2, arg3, 0x30030, -1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062CA70.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062CEA8.s")

void func_8062D094(s32 arg0, u8 arg1) {
    func_8062D0CC(D_807F5DE4, D_807F5E60, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062D0CC.s")

void func_8062D1A8() {
    if (!gameIsInDKTVMode()) {
        func_8062D1E0(D_807F5DE4, D_807F5E60);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062D1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062D26C.s")

/*
void func_8062D2AC(s32 arg0, s32 arg1, u8 arg2);

// TODO: Something weird going on with stack
void func_8062D26C(Actor *arg0) {
    s32 sp1F;
    s32 sp1C;

    func_80630588(0, arg0, 1, &sp1F);
    func_8062D2AC(arg0, &sp1C, 1);
}
*/

void func_8062D2AC(s32 arg0, s32 arg1, u8 arg2) {
    func_8062D2F0(D_807F5DE4, D_807F5E60, arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062D2F0.s")

void func_8062D3E4(s32 arg0) {
    func_8062D414(D_807F5DE4, D_807F5E60, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062D414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062D620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062DAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062DB70.s")

/*
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct807F5E50;

extern Struct807F5E50 D_807F5E50;

void func_8062DB70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    D_807F5E50.unk0 = arg3 - arg0;
    D_807F5E50.unk8 = arg5 - arg2;
    D_807F5E50.unk4 = arg4 - arg1;
    D_807F5E50.unkC = -((D_807F5E50.unk8 * arg2) + ((D_807F5E50.unk0 * arg0) + (D_807F5E50.unk4 * arg1)));
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062DBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062E1F8.s")

/*
s32 func_8062E3B4(f32 *, f32 *, s32, s32 *, s32, f64, s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Struct8062E1F8;

s32 func_8062E1F8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s32 *arg7) {
    f32 sp88[4][4];
    f32 sp40[4][4];
    s32 sp3C;
    Struct8062E1F8 *temp_a0;
    int var_v0;

    temp_a0 = &(arg7[arg0 << 6]);
    func_8062E3B4(temp_a0, &sp88, temp_a0->unk18, &sp3C, 0, arg1, 0);
    if (sp3C == 0) {
        return 0;
    }
    func_8062E3B4(&sp88, &sp40, sp3C, &sp3C, 0, arg4, 1);
    if (sp3C == 0) {
        return 0;
    }
    func_8062E3B4(&sp40, &sp88, sp3C, &sp3C, 1, arg2, 0);
    if (sp3C == 0) {
        return 0;
    }
    func_8062E3B4(&sp88, &sp40, sp3C, &sp3C, 1, arg5, 1);
    if (sp3C == 0) {
        return 0;
    }
    func_8062E3B4(&sp40, &sp88, sp3C, &sp3C, 2, arg3, 0);
    if (sp3C == 0) {
        return 0;
    }
    func_8062E3B4(&sp88, &sp40, sp3C, &sp3C, 2, arg6, 1);
    var_v0 = 0;
    if (sp3C != 0) {
        var_v0 = 1;
    }
    return var_v0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062E3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062E548.s")

/*
s32 func_8062E548(s16 *arg0, u8 arg1, f64 arg2, f64 arg3, u8 arg4) {
    f64 phi_f0;

    switch (arg1) {
        default:
            phi_f0 = phi_f0; // ??
            break;
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
                return 1;
            }
            break;
        case 1:
            if (phi_f0 <= arg3) {
                return 1;
            }
            break;
    }
    return 0;
}
*/

void func_8062E608(void *arg0, s32 *arg1, s32 arg2) {
    // TODO: sizeof()?
    memcpy((*arg1 * 6) + arg2, arg0, 6);
    *arg1 += 1;
    if (*arg1 >= 0xD) {
        func_80732354(1, 0, 0, 0);
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct8062E67C;

void func_8062E67C(Struct8062E67C *arg0, Struct8062E67C *arg1, u8 arg2, f64 arg4, Struct8062E67C *arg6) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062E898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062EBB8.s")

// Hmm, DisplayList stuff?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062EDA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062EE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062EFA0.s")

// Appears to parse the map geometry format!
// Surprisingly doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F050.s")

void func_80659DB0(f32, f32, f32, s32);
void func_8063C390(void);
void func_8065E040(s32);
/*
? func_8062B3C4(void *, s32 *);
? func_8062B478(s32);
s32 func_8062BA74(void *);
? func_8062F318();
? func_8062F328(void *);
? func_8062F3A0(void *, void *);
? func_8062F420(void *, void *, void *);
? func_80650ECC(void *);
? func_80659110(s32);
? func_8065996C(?);
? func_8065CDA0(s32);
? func_8065F1C0(void *);
? func_80662B90(void *);
? func_806637C0(void *);
? func_80666090(void *);
? func_8066C958(void *);
*/

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
} MapGeometryHeader;

extern f32 D_80758190;
extern MapGeometryHeader *D_807F5DE0;
extern void *D_807F5DE8;
extern void *D_807F5DEC;
extern s32 D_807F5E60;
extern s8 D_807F5FC1;
extern void *D_807F5FC4;
extern s32 D_807F5FC8;
extern void *D_807F5FCC;
extern s32 D_807F5FD0;
extern void *D_807F5FD4;
extern f32 D_807F5FDC;
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
extern s16 D_807FD574;
extern s16 D_807FD576;
extern s16 D_807FD578;
extern f32 D_807444C4;

void func_8062F318(void);

void func_80659110(u8);
void func_8065CDA0(u8);

void func_8065996C(s16);

/*
void func_8062F050(MapGeometryHeader *arg0) {
    s32 sp50;
    s32 *temp_a0;
    s32 *temp_a1;
    s32 *temp_v1;
    void *temp_a1_2;
    s32 sp28;

    D_807F5DE0 = arg0;
    sp28 = 0;
    D_807F5FDC = func_80612D10(D_80758190);
    func_80659110(arg0->unk8 & 1);
    func_8065CDA0((arg0->unk8 >> 1) & 1);
    D_807444C4 = arg0->unkA;
    D_807FB5E0 = arg0->unk14 * 8;
    D_807FB5E4 = arg0->unk16 * 8;
    D_807FB5E8 = arg0->unk10;
    D_807FB5EA = arg0->unk12;
    D_807F9450 = arg0->unk1C;
    D_807F9452 = arg0->unk1E;
    D_807F9454 = arg0->unk18;
    D_807F9456 = arg0->unk1A;
    D_807FD574 = arg0->unk20;
    D_807FD576 = arg0->unk22;
    D_807FD578 = arg0->unk24;
    D_807F5FE4 = arg0->unk26;
    D_807F5FE6 = arg0->unk28;
    D_807F5FE8 = arg0->unk2A;
    D_807F5FEA = arg0->unk2C;
    temp_v1 = &D_807F5DE0->unk0 + arg0->unk40;
    D_807F5FD0 = *temp_v1 + 1;
    D_807F5FD4 = temp_v1 + 1;
    temp_a0 = &D_807F5DE0->unk0 + arg0->unk44;
    D_807F5FC8 = *temp_a0;
    D_807F5FCC = temp_a0 + 1;
    temp_a1 = &D_807F5DE0->unk0 + arg0->unk48;
    D_807F5FC1 = *temp_a1;
    D_807F5FC4 = temp_a1 + 1;
    D_807F5DE4 = &D_807F5DE0->unk0 + arg0->unk30;
    D_807F5DE8 = &D_807F5DE0->unk0 + arg0->unk38;
    D_807F5DEC = &D_807F5DE0->unk0 + arg0->unk34;
    func_80659DB0(1.0f, 1.0f, 1.0f, -1);
    func_8065996C(-1);
    func_8065E040(arg0->unkE << 0xA);
    temp_a1_2 = &D_807F5DE0->unk0 + arg0->unk30;
    func_8062F420(temp_a1_2, temp_a1_2, &D_807F5DE0->unk0 + arg0->unk34);
    func_8062F3A0(&D_807F5DE0->unk0 + arg0->unk34, &D_807F5DE0->unk0 + arg0->unk38);
    func_8062F328(&D_807F5DE0->unk0 + arg0->unk40);
    func_8063C390();
    func_8062B3C4(D_807F5DE4, &sp28);
    func_8062B478(sp28);
    D_807F5E60 = func_8062BA74(D_807F5DE4);
    func_80650ECC(arg0);
    func_8066C958(arg0);
    func_80666090(arg0);
    func_8065F1C0(arg0);
    func_80662B90(arg0);
    func_806637C0(arg0);
    func_8062F318();
}
*/

extern s32 D_807F5FC8;
// extern s32 D_807F5FCC;
extern u8 D_807F5FED;

void func_8062F318(void) {
    D_807F5FED = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F328.s")

// extern s32 D_807F5FD0;
// extern s32 *D_807F5FD4;

/*
// Regalloc
void func_8062F328(s32 arg0) {
    s32 temp_a1;
    s32 i;

    if (D_807F5FD0 != 0) {
        for (i = 0; i <= D_807F5FD0; i++) {
            D_807F5FD4[i] += arg0;
        }
    }
}
*/

s32 func_8062F388(s32 *arg0) {
    *arg0 = D_807F5FCC;
    return D_807F5FC8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F3A0.s")

typedef struct {
    s32 unk0;
    union {
        void *texturePointer;
        s32 textureIndex;
    };
} GlobalASMStruct_8062F3A0;

/*
void func_8062F3A0(GlobalASMStruct_8062F3A0 *arg0, GlobalASMStruct_8062F3A0 *arg1) {
    while (arg0 != arg1) {
        if ((arg0->unk0 >> 0x18) == 0xFD) {
            if (((arg0->textureIndex << 4) >> 28) == 0) { // TODO: Bitfield?
                arg0->texturePointer = getPointerTableFile(0x19, arg0->textureIndex, 1, 0);
            }
        }
        arg0++;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F420.s")

typedef struct Struct8062F420 Struct8062F420;

struct Struct8062F420 {
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
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    s32 unkBC;
    s32 unkC0;
    u8 unkC4;
    u8 unkC5;
};

/*
void func_8062F420(Struct8062F420 *arg0, s32 arg1, s32 arg2) {
    s32 temp_t6;
    s32 i;
    Struct8062F420 *var_v0;

loop_1:
    if (arg0 != NULL) {
        switch (arg0->unkB8) {
            case 0:
                arg0->unk0 += arg1;
                arg0->unk4 += arg1;
                func_8062F420(arg0->unk0, arg1, arg2);
                arg0 = arg0->unk4;
                goto loop_1;
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
                var_v0 = arg0;
                for (i = 0; i < arg0->unkC5; i++) {
                    temp_t6 = var_v0->unk1C;
                    var_v0 += 4;
                    var_v0->unk18 = temp_t6 + arg2;
                }
                return;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062F998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062FBC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2F550/func_8062FF10.s")
