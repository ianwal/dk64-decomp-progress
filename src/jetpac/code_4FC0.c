#include <ultra64.h>
#include "functions.h"

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
} struct_jetpac_80029640;

typedef struct JetpacStruct9 {
    u8 pad0[0x18];
} JetpacStruct9;

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
} struct_jetpac_8002998C;

extern JetpacStruct9 D_jetpac_8002E800[];
extern JetpacStruct D_jetpac_8002F1DC[6];
extern f32 D_jetpac_8002EBB0;
extern f32 D_jetpac_8002EBB4;
extern f32 D_jetpac_8002EBB8;
extern s32 D_jetpac_8002E830;
extern f32 D_jetpac_8002EBBC;
extern f32 D_jetpac_8002EBC0;
extern f32 D_jetpac_8002EBC4;
extern f32 D_jetpac_8002EBC8;
extern void* D_jetpac_8002E878;
extern f32 D_jetpac_8002EBCC;
extern s32 D_jetpac_8002BA6C;
extern f32 D_jetpac_8002EBD0;
extern s32 D_jetpac_8002E890;
extern s32 D_jetpac_8002F050; // TODO: Datatype
extern f32 D_jetpac_8002F054;
extern s32 D_jetpac_8002F078;
extern f64 D_jetpac_8002EC10;
extern s32 D_jetpac_8002E8A8;
extern f32 D_jetpac_8002EC18;
extern f32 D_jetpac_8002EC1C;
extern s32 D_jetpac_8002E8C0;
extern s32 D_jetpac_8002E8D8;
extern JetpacPlayerStruct D_jetpac_8002EC30;
extern s32 D_jetpac_8002E8F0;
extern s32 D_jetpac_8002F3BC;
extern u8 D_jetpac_8002E9C0;
extern u8 D_jetpac_8002E9C4;
extern u8 D_jetpac_8002E9C8;
extern u8 D_jetpac_8002E9CC;
extern u8 D_jetpac_80045BE0;
extern u8 D_jetpac_80045BE1;
extern u8 D_jetpac_80045BE2;
extern u8 D_jetpac_80045BE3;

void func_jetpac_80025700(s32, s32, s32, s32, s32);
void func_jetpac_80025A60(s32);
f32 func_jetpac_80027210();
void func_jetpac_80024E70(u8);
void func_jetpac_80029640(struct_jetpac_80029640*, f32, f32);
extern void func_jetpac_800298C8(JetpacStruct *arg0);
void func_jetpac_8002976C(JetpacStruct*);
extern void (func_jetpac_8002998C)();
f32 func_jetpac_80027210();
void func_jetpac_80029B90(JetpacStruct *);
f32 func_jetpac_80027380(s32 *);
f32 func_jetpac_800273C8(JetpacStruct *);
f32 func_jetpac_8002A2DC(f32, f32);
//void func_jetpac_8002A67C(JetpacStruct *);
f32 func_jetpac_80027210();
s32 func_jetpac_80027250(f32, f32, f32, f32, f32, f32, f32, f32);
extern void (func_jetpac_8002A758)();
void func_jetpac_8002A374(JetpacStruct*);
void func_jetpac_8002A530(JetpacStruct *arg0);
extern void func_jetpac_80029F7C(struct_jetpac_8002998C*, s32);
f32 func_jetpac_80027210();
extern void (func_jetpac_80029C1C)();
s32 func_jetpac_80028CF8(f32, f32, f32, f32, s32);
void func_jetpac_800294EC(void *, s32);
void *func_global_asm_806FD490(Gfx *, s32, s16, s16, s32);

void *func_jetpac_80028FC0(void) {
    s32 i;
    JetpacStruct *temp = &D_jetpac_8002F1DC[0];
    for (i = 0; i < 6; i++) {
        if (temp->unk14 == 0) {
            return temp;
        }
        temp++;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_80029064.s")

extern s32 D_jetpac_8002F064;
extern s32 D_jetpac_8002F07C;

void func_jetpac_800291AC(JetpacStruct5 *arg0);

/*
s32 func_jetpac_80029064(JetpacStruct *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (D_jetpac_8002EC30.unk434 == 3) {
        var_v1 = func_jetpac_80027250(
            arg0->unk0 + arg0->unk1C,
            arg0->unk4 + arg0->unk20,
            arg0->unk24 + arg0->unk0,
            arg0->unk28 + arg0->unk4,
            D_jetpac_8002EC30.unk420 + (D_jetpac_8002EC30.unk43C + 2),
            D_jetpac_8002EC30.unk424 + (D_jetpac_8002EC30.unk440 + 4),
            D_jetpac_8002EC30.unk444 + (D_jetpac_8002EC30.unk420 - 2),
            D_jetpac_8002EC30.unk448 + D_jetpac_8002EC30.unk424
        );
    }
    if (var_v1 != 0) {
        D_jetpac_8002F064 = 4;
        D_jetpac_8002F07C = 0;
        func_jetpac_80027010(&D_jetpac_8002F050, arg0);
        func_jetpac_800291AC(arg0);
    }
    return var_v1;
}
*/

void func_jetpac_800291AC(JetpacStruct5 *arg0) {
    arg0->unk14 = 4;
    arg0->unk2C = 0;
    arg0->unk38 = 0;
    arg0->unk30 = (s32)arg0->unk0 & 0xFFF8;
    arg0->unk34 = (s32)arg0->unk4 & 0xFFF8;
    func_jetpac_80024E70(5);
}

void func_jetpac_80029204(JetpacStruct *arg0) {
    if (arg0->unk14 == 3) {
        func_jetpac_80025700(arg0->unk4C, arg0->unk0, arg0->unk4, &arg0->unk10, arg0->unk18);
        return;
    }
    if (arg0->unk14 == 4) {
        func_jetpac_80025A60(&arg0->unk30);
        if (arg0->unk38 < 7) {
            func_jetpac_80025700(arg0->unk4C, arg0->unk0, arg0->unk4, &arg0->unk10, arg0->unk18);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_800292C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_80029450.s")

/*
Competitor *func_jetpac_800292C4(void);
extern void* D_jetpac_80029884[8];
extern JetpacPlayerStruct D_jetpac_8002EC30;

void func_jetpac_80029450(void) {
    void (*sp1C)(void *);
    Competitor* sp18;
    Competitor* temp_v0;

    sp1C = D_jetpac_80029884[D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index * 0x194].level % 8];
    temp_v0 = func_jetpac_800292C4();
    if (temp_v0 != NULL) {
        sp18 = temp_v0;
        sp1C(temp_v0);
        *(u32*)(&sp18->unk14[0].unk0) = 3;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_800294EC.s")

void func_jetpac_80029640(struct_jetpac_80029640 *arg0, f32 arg1, f32 arg2) {
    JetpacStruct *var_v0;
    s32 var_a1;
    s32 var_a2;
    s32 i;
    s32 rng;

    // TODO: Why? Any way to avoid this?
    var_a1 = 0;var_a2 = 0;

    arg0->unk44 = 0x19;
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = arg1;
        arg0->unk18 = 0;
    } else {
        arg0->unk8 = -arg1;
        arg0->unk18 = 1;
    }
    var_v0 = &D_jetpac_8002F1DC;
    for (i = 0; i < 6; i++) {
        if (var_v0->unk14 > 0) {
            if (var_v0->unkC == 0.0f) {
                var_a1++;
            } else {
                var_a2++;
            }
        }
        var_v0++;
    }
    if (var_a1 == 3) {
        arg0->unkC = arg2;
    } else {
        if (var_a2 == 3) {
            arg0->unkC = 0.0f;
        } else {
            rng = func_jetpac_80027210() * 2;
            if (rng % 2) {
                arg0->unkC = 0.0f;
            } else {
                arg0->unkC = arg2;
            }
        }
    }
}

void func_jetpac_8002976C(JetpacStruct *arg0) {
    switch (arg0->unk14) {
        case 3:
            if (func_jetpac_80028CF8(
                arg0->unk1C + arg0->unk0 + arg0->unk8,
                arg0->unk20 + arg0->unk4 + arg0->unkC,
                arg0->unk24 + arg0->unk0 + arg0->unk8,
                arg0->unk28 + arg0->unk4 + arg0->unkC, 1) >= 0) {
                func_jetpac_800291AC(arg0);
                return;
            }
            if (func_jetpac_80029064(arg0) == 0) {
                arg0->unk0 += arg0->unk8;
                arg0->unk4 += arg0->unkC;
                return;
            }
            return;
        case 4:
            arg0->unk2C++;
            if (arg0->unk2C >= 0xF) {
                arg0->unk14 = 0;
            }
            break;
    }
}

void func_jetpac_80029884(struct_jetpac_80029640 *arg0) {
    arg0->unk28 = 0xB;
    func_jetpac_80029640(arg0, 1.60000002384f, 0.5f);
    arg0->unk48 = &func_jetpac_800298C8;
}

void func_jetpac_800298C8(JetpacStruct *arg0) {
    func_jetpac_8002976C(arg0);
    arg0->unk4C = &D_jetpac_8002E800[(s32)arg0->unk0 % 2];
}

void func_jetpac_8002992C(JetpacStruct *arg0) {
    arg0->unk48 = &func_jetpac_8002998C;
    arg0->unk44 = 0x50;
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = D_jetpac_8002EBB0;
    } else {
        arg0->unk8 = D_jetpac_8002EBB4;
    }
    arg0->unkC = D_jetpac_8002EBB8;
    arg0->unk4C = &D_jetpac_8002E830;
}

void func_jetpac_8002998C(struct_jetpac_8002998C *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk14) {                              
        case 3:
            temp_v0_2 = func_jetpac_80028CF8(
                        arg0->unk1C + arg0->unk0 + arg0->unk8,
                        arg0->unk20 + arg0->unk4 + arg0->unkC,
                        arg0->unk24 + arg0->unk0 + arg0->unk8,
                        arg0->unk28 + arg0->unk4 + arg0->unkC, 1);
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
            }
            if (!func_jetpac_80029064(arg0)) {
                if (arg0->unk4 + arg0->unkC < 24.0f) {
                    arg0->unkC = -arg0->unkC;
                }
                arg0->unk4 = arg0->unk4 + arg0->unkC;
                arg0->unk0 += arg0->unk8;
                if ((s32)arg0->unk0 & 2) {
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

void func_jetpac_80029AF8(JetpacStruct *arg0) {
    arg0->unk48 = &func_jetpac_80029C1C;
    arg0->unk44 = 0x28;
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = D_jetpac_8002EBBC;
    } else {
        arg0->unk8 = D_jetpac_8002EBC0;
    }
    func_jetpac_80029B90(arg0);
    arg0->unk2C = (func_jetpac_80027210() * 60.0f) + 10.0f;
}

void func_jetpac_80029B90(JetpacStruct *arg0) {
    if (arg0->unkC == 0.0) {
        if (func_jetpac_80027210() < 0.5) {
            arg0->unkC = (f32) D_jetpac_8002EBC4;
            return;
        }
        arg0->unkC = D_jetpac_8002EBC8;
        return;
    }
    arg0->unkC = 0.0f;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct8002E848;

extern Struct8002E848 D_jetpac_8002E848[];

void func_jetpac_80029C1C(JetpacStruct *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk14) {
        case 3:
            arg0->unk2C--;
            if (arg0->unk2C == 0) {
                func_jetpac_80029B90(arg0);
                arg0->unk2C = (func_jetpac_80027210() * 60.0f) + 10.0f;
            }
            temp_v0_2 = func_jetpac_80028CF8(
                arg0->unk1C + arg0->unk0 + arg0->unk8,
                arg0->unk20 + arg0->unk4 + arg0->unkC,
                arg0->unk24 + arg0->unk0 + arg0->unk8,
                arg0->unk28 + arg0->unk4 + arg0->unkC,
                1
            );
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
                if (arg0->unk2C < 0xA) {
                    arg0->unk2C = 0xA;
                }
            }
            if (!func_jetpac_80029064(arg0)) {
                if ((arg0->unk4 + arg0->unkC) < 24.0f) {
                    arg0->unkC = -arg0->unkC;
                }
                arg0->unk4 = arg0->unk4 + arg0->unkC;
                arg0->unk0 = arg0->unk0 + arg0->unk8;
                arg0->unk4C = &D_jetpac_8002E848[(((s32)(arg0->unk0 / 4) % 2))];
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

void func_jetpac_80029E0C(struct_jetpac_80029640 *arg0) {
    arg0->unk48 = &func_jetpac_80029F7C;
    arg0->unk44 = 0x37;
    arg0->unk2C = (func_jetpac_80027210() * 60.0f) + 10.0f;
    arg0->unk40 = (func_jetpac_80027210() * 180.0f) + 10.0f;
    arg0->unk28 = 8;
    if (arg0->unk4 < 88.0f) {
        arg0->unk18 = 0;
    } else {
        arg0->unk18 = 1;
    }
    arg0->unk8 = 0.0f;
    if (D_jetpac_8002BA6C) {
        arg0->unkC = D_jetpac_8002EBCC;
    } else {
        arg0->unkC = D_jetpac_8002EBD0;
    }
    arg0->unk4C = &D_jetpac_8002E878;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_80029F7C.s")

void func_jetpac_8002A254(JetpacStruct *arg0) {
    arg0->unk48 = &func_jetpac_8002A530;
    arg0->unk44 = 0x32;
    if (arg0->unk4 < 88.0f) {
        arg0->unk18 = 0;
    } else {
        arg0->unk18 = 1;
    }
    func_jetpac_8002A374(arg0);
}

void func_jetpac_8002A2AC(JetpacStruct *arg0) {
    arg0->unk28 = 8;
    arg0->unk4C = &D_jetpac_8002E890;
    func_jetpac_8002A254(arg0);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_8002A2DC.s")

extern f64 D_jetpac_8002EBF0;
extern f64 D_jetpac_8002EBF8;
extern f64 D_jetpac_8002EC00;
extern f64 D_jetpac_8002EC08;

/*
f32 func_jetpac_8002A2DC(f32 arg0, f32 arg1) {
    if (arg0 < 0.0f) {
        arg1 -= D_jetpac_8002EBF0;
    } else {
        arg1 += D_jetpac_8002EBF8;
    }
    if (arg1 < D_jetpac_8002EC00) {
        return D_jetpac_8002EC00;
    }
    return MIN(D_jetpac_8002EC08, arg1);
}
*/

void func_jetpac_8002A374(JetpacStruct *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f14;
    f32 sp28;
    f32 temp_f12;
    f32 var_f18;
    f32 sp1C;
    f32 sp18;

    sp18 = func_jetpac_80027380(arg0);
    temp_f0 = func_jetpac_80027380(&D_jetpac_8002F050);
    temp_f2 = temp_f0 - sp18;
    if (sp18 < temp_f0) {
        var_f14 = temp_f2 - 256.0f;
    } else {
        var_f14 = temp_f2 + 256.0f;
    }
    temp_f12 = (D_jetpac_8002F054 + D_jetpac_8002F078) - func_jetpac_800273C8(arg0);
    if (temp_f12 > 0.0f) {
        var_f18 = temp_f12 - 288.0;
    } else {
        var_f18 = temp_f12 + 192.0f;
    }
    if ((ABS(temp_f2)) < (ABS(var_f14))) {
        sp28 = temp_f2;
    } else {
        sp28 = var_f14;
    }
    if ((ABS(temp_f12)) < (ABS(var_f18))) {
        sp1C = temp_f12;
    } else {
        sp1C = var_f18;
    }
    arg0->unk8 = func_jetpac_8002A2DC(sp28, arg0->unk8);
    arg0->unkC = func_jetpac_8002A2DC(sp1C, arg0->unkC);
}

void func_jetpac_8002A530(JetpacStruct *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk14) {
        case 3:
            func_jetpac_8002A374(arg0);
            temp_v0_2 = func_jetpac_80028CF8(
                arg0->unk1C + arg0->unk0 + arg0->unk8,
                arg0->unk20 + arg0->unk4 + arg0->unkC,
                arg0->unk24 + arg0->unk0 + arg0->unk8,
                arg0->unk28 + arg0->unk4 + arg0->unkC,
                1
            );
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
            }
            if (func_jetpac_80029064(arg0) == 0) {
                if ((arg0->unk4 + arg0->unkC) < 24.0f) {
                    arg0->unkC = -arg0->unkC;
                }
                arg0->unk4 += arg0->unkC;
                arg0->unk0 += arg0->unk8;
                return;
            }
            return;
        case 4:
            arg0->unk2C++;
            if (arg0->unk2C >= 0xF) {
                arg0->unk14 = 0;
            }
            break;
    }
}

void func_jetpac_8002A67C(JetpacStruct *arg0) {
    s32 temp_f6;

    temp_f6 = (arg0->unk2C % 4) + 1;
    arg0->unkC = ((f64)D_jetpac_8002EC10 / (f64)temp_f6);
    arg0->unk2C++;
}

void func_jetpac_8002A6C0(JetpacStruct *arg0) {
    arg0->unk48 = &func_jetpac_8002A758;
    arg0->unk44 = 0x3C;
    arg0->unk2C = (s32) (func_jetpac_80027210() * 16.0f);
    if (arg0->unk4 < 88.0f) {
        arg0->unk8 = D_jetpac_8002EC18;
    } else {
        arg0->unk8 = D_jetpac_8002EC1C;
    }
    func_jetpac_8002A67C(arg0);
    arg0->unk4C = &D_jetpac_8002E8A8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_4FC0/func_jetpac_8002A758.s")

extern f64 D_jetpac_8002EC20;

/*
// TODO: Close...ish
void func_jetpac_8002A758(JetpacStruct *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk14) {
        case 3:
            arg0->unkC = arg0->unkC + D_jetpac_8002EC20;
            temp_v0_2 = func_jetpac_80028CF8(
                        arg0->unk1C + arg0->unk0 + arg0->unk8,
                        arg0->unk20 + arg0->unk4 + arg0->unkC,
                        arg0->unk24 + arg0->unk0 + arg0->unk8,
                        arg0->unk28 + arg0->unk4 + arg0->unkC, 1);
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
                if (arg0->unkC > 0.0f && arg0->unkC < 0.0f) {
                    func_jetpac_8002A67C(arg0);
                }
            }
            if (!func_jetpac_80029064(arg0)) {
                if ((arg0->unk4 + arg0->unkC) < 24.0f) {
                    arg0->unkC = -arg0->unkC;
                }
                arg0->unk4 = arg0->unk4 + arg0->unkC;
                arg0->unk0 = arg0->unk0 + arg0->unk8;
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

void func_jetpac_8002A8F0(struct_jetpac_80029640 *arg0) {
    arg0->unk28 = 0xE;
    arg0->unk4C = &D_jetpac_8002E8C0;
    func_jetpac_80029640(arg0, 1.2f, 0.3f);
    arg0->unk48 = &func_jetpac_8002976C;
}

void func_jetpac_8002A944(JetpacStruct *arg0) {
    arg0->unk28 = 0xE;
    arg0->unk4C = &D_jetpac_8002E8D8;
    func_jetpac_8002A254(arg0);
}

s32 func_jetpac_8002A974(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Competitor *player;
    s32 i;
    JetpacStruct *var_s0;

    var_s0 = &D_jetpac_8002F1DC;
    for (i = 0; i < 6; i++) {
        if (var_s0->unk14 == 3) {
            if (func_jetpac_80027250(arg0, arg1, arg2, arg3, var_s0->unk0 + var_s0->unk1C, var_s0->unk4 + var_s0->unk20, var_s0->unk0 + var_s0->unk24, var_s0->unk4 + var_s0->unk28) != 0) {
                player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
                func_jetpac_800291AC(var_s0);
                player->current_score += var_s0->unk44;
                return 1;
            }
        }
        var_s0++;
    }
    return 0;
}

void func_jetpac_80029450();
extern JetpacStruct D_jetpac_8002E964;

void func_jetpac_8002AAD4(void) {
    s32 i;
    JetpacStruct sp24;
    JetpacStruct *var_v0;

    sp24 = D_jetpac_8002E964;
    var_v0 = &D_jetpac_8002F1DC;
    for (i = 0; i < 6; i++) {
        *var_v0 = sp24;
        var_v0++;
    }
    for (i = 0; i < 3; i++) {
        func_jetpac_80029450();
    }
    D_jetpac_8002E8F0 = func_jetpac_80027210() * 180.0f;
}

void func_jetpac_8002ABDC(void) {
    JetpacStruct *var_s0;
    s32 count;
    s32 i;

    var_s0 = D_jetpac_8002F1DC;
    count = 0;

    if (func_jetpac_80026FE0()) {
        return;
    }

    if (D_jetpac_8002E8F0 > 0) {
        D_jetpac_8002E8F0--;
    }

    for (i = 0; i != 6; i++) {
        if (var_s0->unk14 > 0) {
            if (var_s0->unk48 != NULL) {
                var_s0->unk48(var_s0);
                if (var_s0->unk0 < 0.0f) {
                    var_s0->unk0 += 256.0f;
                }
                if (var_s0->unk0 > 256.0f) {
                    var_s0->unk0 -= 256.0f;
                }
                count++;
            }
        }
        var_s0++;
    }
    if (count < 3 && D_jetpac_8002E8F0 >= 6) {
        D_jetpac_8002E8F0 = func_jetpac_80027210() * 5.0f;
    }
    if (D_jetpac_8002E8F0 == 0 && D_jetpac_8002F3BC == 2) {
        func_jetpac_80029450();
        count++;
        if (count < 3) {
            D_jetpac_8002E8F0 = func_jetpac_80027210() * 5.0f;
        } else {
            D_jetpac_8002E8F0 = func_jetpac_80027210() * 180.0f;
        }
    }
}

void func_jetpac_8002AD8C(void) {
    JetpacStruct *var_s0;
    s32 i;

    var_s0 = &D_jetpac_8002F1DC;
    if (func_jetpac_80026FE0() == 0) {
        for (i = 0; i < 6; i++) {
            if (var_s0->unk14 >= 2) {
                if (var_s0->unk4C != 0) {
                    func_jetpac_80029204(var_s0);
                }
            }
            var_s0++;
        }
    }
}

void func_jetpac_8002AE00(Gfx **arg0) {
    Gfx *dl = *arg0;
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetCombineMode(dl++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA)
    gDPSetRenderMode(dl++, G_RM_OPA_SURF, G_RM_OPA_SURF2)
    *arg0 = dl;
}

void func_jetpac_8002AE94(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    D_jetpac_80045BE0 = arg0;
    D_jetpac_80045BE1 = arg1;
    D_jetpac_80045BE2 = arg2;
    D_jetpac_80045BE3 = arg3;
}

void func_jetpac_8002AEC8(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    D_jetpac_8002E9C0 = arg0;
    D_jetpac_8002E9C4 = arg1;
    D_jetpac_8002E9C8 = arg2;
    D_jetpac_8002E9CC = arg3;
}

void func_jetpac_8002AEFC(Gfx **arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4) {
    Gfx *dl;

    dl = *arg0;
    if (arg4 != 0) {
        gDPSetPrimColor(dl++, 0, 0, D_jetpac_8002E9C0, D_jetpac_8002E9C4, D_jetpac_8002E9C8, D_jetpac_8002E9CC);
        gDPSetEnvColor(dl++, D_jetpac_80045BE0, D_jetpac_80045BE1, D_jetpac_80045BE2, D_jetpac_80045BE3);
    } else {
        gDPSetPrimColor(dl++, 0, 0, D_jetpac_80045BE0, D_jetpac_80045BE1, D_jetpac_80045BE2, D_jetpac_80045BE3);
        gDPSetEnvColor(dl++, D_jetpac_8002E9C0, D_jetpac_8002E9C4, D_jetpac_8002E9C8, D_jetpac_8002E9CC);
    }
    *arg0 = func_global_asm_806FD490(dl, 4, arg2, arg3, arg1);
}
