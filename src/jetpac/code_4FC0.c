#include <ultra64.h>
#include "functions.h"



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
    arg0->unk30 = (s32)arg0->unk0 & 0xFFF8;
    arg0->unk34 = (s32)arg0->unk4 & 0xFFF8;
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
        func_80025A60(&arg0->unk30);
        if (arg0->unk38 < 7) {
            func_80025700(arg0->unk4C, arg0->unk0, arg0->unk4, ((s8*)(&(*arg0))) + 0x10, arg0->unk18);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_800292C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029450.s")

/*
Competitor *func_800292C4(void);
extern void* D_80029884[8];
extern JetpacPlayerStruct D_8002EC30;

void func_80029450(void) {
    void (*sp1C)(void *);
    Competitor* sp18;
    Competitor* temp_v0;

    sp1C = D_80029884[D_8002EC30.player[D_8002EC30.player_index * 0x194].level % 8];
    temp_v0 = func_800292C4();
    if (temp_v0 != NULL) {
        sp18 = temp_v0;
        sp1C(temp_v0);
        *(u32*)(&sp18->unk14[0].unk0) = 3;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_800294EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_80029640.s")

f32 func_80027210();
extern JetpacStruct D_8002F1DC;

typedef struct {
    // Enemy Struct?
    u8 unk0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10[0x18-0x10];
    s32 unk18;
    u8 unk1C[0x28-0x1C];
    s32 unk28;
    s32 unk2C;
    u8 unk30[0x40-0x30];
    u32 unk40;
    s32 unk44;
    void* unk48;
    void* unk4C;
} struct_80029640;

/*
Minor regalloc
issues with it doing rng + rng rather than rng * 2.0f
void func_80029640(struct_80029640 *arg0, f32 arg1, f32 arg2) {
    JetpacStruct *var_v0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v1;
    s32 rng;

    var_a1 = 0;
    var_a2 = 0;
    arg0->unk44 = 0x19;
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = arg1;
        arg0->unk18 = 0;
    } else {
        arg0->unk8 = -arg1;
        arg0->unk18 = 1;
    }
    var_v0 = &D_8002F1DC;
    var_v1 = 0;
    for (var_v1 = 0; var_v1 < 6; var_v1++) {
        if (var_v0->unk14 > 0) {
            if (var_v0->unkC == 0.0f) {
                var_a1 += 1;
            } else {
                var_a2 += 1;
            }
        }
        var_v0 += 1;
    }
    if (var_a1 == 3) {
        arg0->unkC = arg2;
    } else {
        if (var_a2 == 3) {
            arg0->unkC = 0.0f;
        } else {
            rng = func_80027210() * 2.0f;
            if (rng % 2) {
                arg0->unkC = arg2;
            } else {
                arg0->unkC = 0.0f;
            }
        }
    }
}
*/


#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002976C.s")

void func_80029640(struct_80029640*, f32, f32);
extern void func_800298C8(JetpacStruct *arg0);

void func_80029884(struct_80029640 *arg0) {
    arg0->unk28 = 0xB;
    func_80029640(arg0, 1.60000002384f, 0.5f);
    arg0->unk48 = &func_800298C8;
}

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

s32 func_80028CF8(f32, f32, f32, f32, s32);         
s32 func_80029064(void *);                          
void func_800294EC(void *, s32);                       

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} struct_8002998C;

/*
Floating reg alloc
Also a missing load offset 0x4 instruction
void func_8002998C(struct_8002998C *arg0) {
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f2;
    f32 var_f0;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = arg0->unk14;
    switch (temp_v0) {                              
    case 3:
        temp_f0 = arg0->unk0;
        temp_f2 = arg0->unk8;
        temp_f16 = arg0->unk4;
        temp_f18 = arg0->unkC;
        temp_v0_2 = func_80028CF8(
                    arg0->unk1C + arg0->unk0 + arg0->unk8,
                    arg0->unk20 + arg0->unk4 + arg0->unkC,
                    arg0->unk24 + arg0->unk0 + arg0->unk8,
                    arg0->unk28 + arg0->unk4 + arg0->unkC, 1);
        if (temp_v0_2 >= 0) {
            func_800294EC(arg0, temp_v0_2);
        }
        if (!func_80029064(arg0)) {
            var_f0 = arg0->unkC;
            temp_f16 = arg0->unk4;
            var_f0 = arg0->unk4 + var_f0;
            if (var_f0 < 24.0f) {
                arg0->unkC = -arg0->unkC;
                var_f0 = arg0->unk4 + arg0->unkC;
            }
            arg0->unk4 = var_f0;
            arg0->unk0 += arg0->unk8;
            if ((s32) arg0->unk0 & 2) {
                arg0->unk18 ^= 1;
            }
        }
        break;
    case 4:
        arg0->unk2C++;
        if (arg0->unk2C >= 0xF) {
            arg0->unk14 = 0;
        }
        break;
    }
}
*/


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
    func_80029B90(arg0);
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

f32 func_80027210();
extern void* D_8002E878;
extern f32 D_8002EBCC;
extern void func_80029F7C(struct_8002998C*, s32);

extern s32 D_8002BA6C;
extern f32 D_8002EBD0;

void func_80029E0C(struct_80029640 *arg0) {
    arg0->unk48 = &func_80029F7C;
    arg0->unk44 = 0x37;
    arg0->unk2C = (func_80027210() * 60.0f) + 10.0f;
    arg0->unk40 = (func_80027210() * 180.0f) + 10.0f;
    arg0->unk28 = 8;
    if (arg0->unk4 < 88.0f) {
        arg0->unk18 = 0;
    } else {
        arg0->unk18 = 1;
    }
    arg0->unk8 = 0.0f;
    if (D_8002BA6C) {
        arg0->unkC = D_8002EBCC;
    } else {
        arg0->unkC = D_8002EBD0;
    }
    arg0->unk4C = &D_8002E878;
}

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

extern s32 D_8002E890;

void func_8002A2AC(JetpacStruct *arg0) {
    arg0->unk28 = 8;
    arg0->unk4C = &D_8002E890;
    func_8002A254(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002A2DC.s")

extern f64 D_8002EBF0;
extern f64 D_8002EBF8;
extern f64 D_8002EC00;
extern f64 D_8002EC08;

/*
// TODO: Close
f32 func_8002A2DC(f32 arg0, f32 arg1) {
    if (arg0 < 0.0f) {
        arg1 -= D_8002EBF0;
    } else {
        arg1 += D_8002EBF8;
    }
    if (arg1 < D_8002EC00) {
        return D_8002EC00;
    }
    return MIN(D_8002EC08, arg1);
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

extern s32 D_8002E8C0;
void func_8002A8F0(struct_80029640 *arg0) {
    arg0->unk28 = 0xE;
    arg0->unk4C = &D_8002E8C0;
    func_80029640(arg0, 1.2f, 0.3f);
    arg0->unk48 = &func_8002976C;
}

extern s32 D_8002E8D8;

void func_8002A944(JetpacStruct *arg0) {
    arg0->unk28 = 0xE;
    arg0->unk4C = &D_8002E8D8;
    func_8002A254(arg0);
}

extern JetpacStruct D_8002F1DC; // TODO: Array?
extern JetpacPlayerStruct D_8002EC30;

s32 func_80027250(f32, f32, f32, f32, f32, f32, f32, f32);

s32 func_8002A974(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Competitor *player;
    s32 i;
    JetpacStruct *var_s0;

    var_s0 = &D_8002F1DC;
    for (i = 0; i < 6; i++) {
        if (var_s0->unk14 == 3) {
            if (func_80027250(arg0, arg1, arg2, arg3, var_s0->unk0 + var_s0->unk1C, var_s0->unk4 + var_s0->unk20, var_s0->unk0 + var_s0->unk24, var_s0->unk4 + var_s0->unk28) != 0) {
                player = &D_8002EC30.player[D_8002EC30.player_index];
                func_800291AC(var_s0);
                player->current_score += var_s0->unk44;
                return 1;
            }
        }
        var_s0++;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002AAD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_8002ABDC.s")

void func_8002AD8C(void) {
    JetpacStruct *var_s0;
    s32 i;

    var_s0 = &D_8002F1DC;
    if (func_80026FE0() == 0) {
        for (i = 0; i < 6; i++) {
            if (var_s0->unk14 >= 2) {
                if (var_s0->unk4C != 0) {
                    func_80029204(var_s0);
                }
            }
            var_s0++;
        }
    }
}

// Displaylist stuff
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
