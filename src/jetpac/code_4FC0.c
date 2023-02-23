#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80028FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029064.s")

void func_80024E70(u8);
typedef struct JetpacStruct5 {
    f32 unk0;
    f32 unk4;
    u8 pad0[0x14 - 0x8];
    s32 unk14;
    u8 pad1[0x2C - 0x18];
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
} JetpacStruct5;
void func_800291AC(JetpacStruct5 *arg0) {
    arg0->unk14 = 4;
    arg0->unk2C = 0;
    arg0->unk38 = 0;
    arg0->unk30 = (s32) ((s32) arg0->unk0 & 0xFFF8);
    arg0->unk34 = (s32) ((s32) arg0->unk4 & 0xFFF8);
    func_80024E70(5);
}

void func_80025700(s32, s32, s32, s32, s32);
void func_80025A60(s32);

void func_80029204(JetpacStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 == 3) {
        func_80025700(arg0->unk4C, arg0->unk0, arg0->unk4, ((s8*)(&(*arg0))) + 0x10, arg0->unk18);
        return;
    }
    if (temp_v0 == 4) {
        func_80025A60(((s8*)(&(*arg0))) + 0x30);
        if (arg0->unk38 < 7) {
            func_80025700(arg0->unk4C, arg0->unk0, arg0->unk4, ((s8*)(&(*arg0))) + 0x10, arg0->unk18);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_800292C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_800294EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002976C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029884.s")

void func_8002976C(JetpacStruct*);
typedef struct JetpacStruct9 {
    u8 pad0[0x18];
} JetpacStruct9;
extern JetpacStruct9 D_8002E800[];

void func_800298C8(JetpacStruct *arg0) {
    func_8002976C(arg0);
    arg0->unk4C = &D_8002E800[(s32)arg0->unk0 % 2];
}

extern f32 D_8002EBB0;
extern f32 D_8002EBB4;
extern f32 D_8002EBB8;
extern s32 D_8002E830;
extern void (func_8002998C)();

void func_8002992C(JetpacStruct *arg0) {
    arg0->unk48 = &func_8002998C;
    arg0->unk44 = 0x50;
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = D_8002EBB0;
    } else {
        arg0->unk8 = D_8002EBB4;
    }
    arg0->unkC = D_8002EBB8;
    arg0->unk4C = &D_8002E830;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002998C.s")

f32 func_80027210();
void func_80029B90();
extern f32 D_8002EBBC;
extern f32 D_8002EBC0;
extern void (func_80029C1C)();

void func_80029AF8(JetpacStruct *arg0) {
    arg0->unk48 = &func_80029C1C;
    arg0->unk44 = 0x28;
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = D_8002EBBC;
    } else {
        arg0->unk8 = D_8002EBC0;
    }
    func_80029B90();
    arg0->unk2C = (func_80027210() * 60.0f) + 10.0f;
}

extern f32 D_8002EBC4;
extern f32 D_8002EBC8;
typedef struct JetpacStruct8 {
    u8 pad0[0xC];
    f32 unkC;
} JetpacStruct8;

void func_80029B90(JetpacStruct8 *arg0) {
    if (arg0->unkC == 0.0) {
        if (func_80027210() < 0.5) {
            arg0->unkC = (f32) D_8002EBC4;
            return;
        }
        arg0->unkC = D_8002EBC8;
        return;
    }
    arg0->unkC = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029F7C.s")

void  func_8002A374();
extern void (func_8002A530)();

void func_8002A254(JetpacStruct *arg0) {
    arg0->unk48 = &func_8002A530;
    arg0->unk44 = 0x32;
    if (arg0->unk4 < 88.0f) {
        arg0->unk18 = 0;
    } else {
        arg0->unk18 = 1;
    }
    func_8002A374();
}


#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A2AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A2DC.s")

extern f64 D_8002EBF0;
extern f64 D_8002EBF8;
extern f64 D_8002EC00;
extern f64 D_8002EC08;

/*
// TODO: Close
f32 func_8002A2DC(f32 arg0, f32 arg1) {
    f32 phi_f14;

    if (arg0 < 0.0f) {
        phi_f14 = arg1 - D_8002EBF0;
    } else {
        phi_f14 = arg1 + D_8002EBF8;
    }
    if (phi_f14 < D_8002EC00) {
        return D_8002EC00;
    }
    return MIN(D_8002EC08, phi_f14);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A530.s")

extern f64 D_8002EC10;

void func_8002A67C(JetpacStruct *arg0) {
    s32 temp_f6;

    temp_f6 = (arg0->unk2C % 4) + 1;
    arg0->unkC = ((f64)D_8002EC10 / (f64) temp_f6);
    arg0->unk2C++;
}


f32 func_80027210();
//void func_8002A67C(JetpacStruct *);
extern s32 D_8002E8A8;
extern f32 D_8002EC18;
extern f32 D_8002EC1C;
extern void (func_8002A758)();

void func_8002A6C0(JetpacStruct *arg0) {
    arg0->unk48 = &func_8002A758;
    arg0->unk44 = 0x3C;
    arg0->unk2C = (s32) (func_80027210() * 16.0f);
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = D_8002EC18;
    } else {
        arg0->unk8 = D_8002EC1C;
    }
    func_8002A67C(arg0);
    arg0->unk4C = &D_8002E8A8;
}


#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A8F0.s")
/* .rodata error*/
/*void func_80029640(f32, f32);
extern s32 D_8002E8C0;
extern void (func_8002976C)();
typedef struct JetpacStruct4 {
    u8 pad0[0x28];
    u8 unk28;
    u8 pad1[0x48 - 0x29];
    void *unk48;
    s32 *unk4C;
} JetpacStruct4;

void func_8002A8F0(JetpacStruct4 *arg0) {
    arg0->unk28 = 0xE;
    arg0->unk4C = &D_8002E8C0;
    func_80029640(1.2f, 0.3f);
    arg0->unk48 = &func_8002976C;
}*/

extern s32 D_8002E8D8;

void func_8002A944(JetpacStruct *arg0) {
    arg0->unk28 = 0xE;
    arg0->unk4C = &D_8002E8D8;
    func_8002A254(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002AAD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002ABDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002AD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002AE00.s")

extern s8 D_80045BE0;
extern s8 D_80045BE1;
extern s8 D_80045BE2;
extern s8 D_80045BE3;

void func_8002AE94(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    D_80045BE0 = arg0;
    D_80045BE1 = arg1;
    D_80045BE2 = arg2;
    D_80045BE3 = arg3;
}

extern s8 D_8002E9C0;
extern s8 D_8002E9C4;
extern s8 D_8002E9C8;
extern s8 D_8002E9CC;

void func_8002AEC8(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    D_8002E9C0 = arg0;
    D_8002E9C4 = arg1;
    D_8002E9C8 = arg2;
    D_8002E9CC = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002AEFC.s")
