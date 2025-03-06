#include "common.h"

typedef struct {
    u8 unk0[0xF8];
} struct_8076BF48;

typedef struct {
    u8 unk0[0xEC];
} struct_sub_8076C328;

typedef struct {
    struct_sub_8076C328 unk0[4];
} struct_8076C328;

extern s32 D_dk64_boot_8000DDCC;
extern s32 D_global_asm_8076D200;

extern struct_8076BF48 D_global_asm_8076BF48[];
extern struct_8076C328 D_global_asm_8076C328[];

void func_global_asm_8060B140(s32, ALBankFile *, s32*, s32, s32, s32, s32);
void func_global_asm_80737E50(ALCSPlayer *);
void func_global_asm_80737F0C(ALSeqPlayer*, s32, u8);
void func_global_asm_80738080(ALSeqPlayer*, u8, u8);
void func_global_asm_807380CC(ALSeqPlayer*, s32, u8);
void func_global_asm_80738118(ALSeqPlayer*, s32, u8);
void func_global_asm_80738E58(struct_8076BF48*, struct_8076C328*, u8, s32);

void func_global_asm_80601A10(s32 *, s32, s32 *);
void func_global_asm_80732DEC(s32 *, s32);
void func_global_asm_80732F10(ALSeqPlayer *, s32 *);
void func_global_asm_80735AA0(s32 *);
extern u16 D_global_asm_8076BF30[];
extern void *D_global_asm_8076BF38[];
extern ALHeap D_global_asm_8076D1E8;
extern ALBank *D_global_asm_8076D1FC;
extern u8 D_global_asm_80770F50;
extern dk64_boot_struct_0 D_dk64_boot_8000DCC4[];
extern s32 D_global_asm_807452B0[];
extern ALBank *D_global_asm_8076D1F8;

typedef struct SynthConfig {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    ALHeap *unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
    s32 unk24;
} SynthConfig;

typedef struct Struct80600D50_sp60 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct80600D50_sp60;

typedef struct SeqpConfig {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 padA[2];
    ALHeap *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    s32 unk1C;
} SeqpConfig;

typedef struct UnkConfig {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    ALHeap *unkC;
    s16 unk10;
} UnkConfig;

void func_global_asm_80600D50(void) {
    UnkConfig spCC;
    ALBankFile *temp_v0_2;
    ALBankFile *temp_v0_3;
    s32 spC0;
    SynthConfig sp98;
    SeqpConfig sp78;
    Struct80600D50_sp60 sp6C;
    ALSeqPlayer *player;
    void *temp_v0;
    s32 i;

    alHeapInit(&D_global_asm_8076D1E8, &D_global_asm_80770F50, 0x7BD80);
    sp98.unk0 = 0x2C;
    sp98.unk4 = 0x1E;
    sp98.unk8 = 0x40;
    sp98.unkC = 1;
    sp98.unk10 = 0;
    sp98.unk1C = 6;
    sp98.unk1D = 6;
    sp98.unk18 = 0;
    sp98.unk14 = &D_global_asm_8076D1E8;
    sp6C.unk0 = 22050;
    sp6C.unk4 = 2;
    sp6C.unk8 = 0xC00;
    func_global_asm_80601A10(&sp98, 0x14, &sp6C);
    spC0 = D_dk64_boot_8000DCC4[15].unk4 - D_dk64_boot_8000DCC4[15].unk0;
    temp_v0 = malloc(0x38000);
    func_global_asm_8060B140(D_dk64_boot_8000DCC4[15].unk0, temp_v0, &spC0, 0xD, 0, 2, 0);
    temp_v0_2 = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, spC0);
    func_global_asm_8060B140(D_dk64_boot_8000DCC4[15].unk0, temp_v0_2, &spC0, 0xD, 0, 2, 0);
    alBnkfNew(temp_v0_2, D_dk64_boot_8000DCC4[14].unk0);
    D_global_asm_8076D1FC = temp_v0_2->bankArray[0];
    spC0 = D_dk64_boot_8000DCC4[0x10].unk4 - D_dk64_boot_8000DCC4[0x10].unk0;
    func_global_asm_8060B140(D_dk64_boot_8000DCC4[0x10].unk0, temp_v0, &spC0, 0xD, 0, 2, 0);
    free(temp_v0);
    temp_v0_3 = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, spC0);
    func_global_asm_8060B140(D_dk64_boot_8000DCC4[0x10].unk0, temp_v0_3, &spC0, 0xD, 0, 2, 0);
    alBnkfNew(temp_v0_3, D_dk64_boot_8000DCC4[0x11].unk0);
    D_global_asm_8076D1F8 = temp_v0_3->bankArray[0];
    sp78.unk0 = 0x2C;
    sp78.unk4 = 0x40;
    sp78.unk9 = 0;
    sp78.unk8 = 0x10;
    sp78.unkC = &D_global_asm_8076D1E8;
    func_global_asm_80732DEC(&sp78, 0x58);
    for (i = 0; i < 4; i++) {
        D_global_asm_8076BF30[i] = 0xFFFF;
        D_global_asm_8076BF38[i] = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, D_global_asm_807452B0[i]);
        D_global_asm_8076BF20[i] = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, 0x8C);
        player = D_global_asm_8076BF20[i];
        if ((!D_global_asm_8076BF38[i]) || (player = D_global_asm_8076BF20[i], !player)) {
            player = D_global_asm_8076BF20[i];
        }
        func_global_asm_80732F10(player, &sp78);
        func_global_asm_80735A50(D_global_asm_8076BF20[i], temp_v0_2->bankArray[0]);
    }
    func_global_asm_806010A0();
    spCC.unk4 = 0x40;
    spCC.unk0 = 0x40;
    spCC.unk8 = 0x14;
    spCC.unk10 = 8;
    spCC.unkC = &D_global_asm_8076D1E8;
    func_global_asm_80735AA0(&spCC);
    func_global_asm_80737C20(4);
    func_global_asm_80737CF4(0, 4);
    func_global_asm_80601CC0();
}

void func_global_asm_806010A0(void) {
    s32 sp34, sp30, sp2C;

    sp34 = 0x80;
    func_global_asm_8060B140(D_dk64_boot_8000DDCC, &D_global_asm_8076D200, &sp34, 0, 0, 0, 0);
    sp30 = 0x2C0;
    sp2C = D_global_asm_8076D200;
    func_global_asm_8060B140(D_dk64_boot_8000DDCC + sp2C, &D_global_asm_8076D200, &sp30, 0, 0, 0, 0);
}

void func_global_asm_80601120(u8 arg0) {
    if (func_global_asm_80737E30(D_global_asm_8076BF20[arg0]) == 0) {
        func_global_asm_80737E50(D_global_asm_8076BF20[arg0]);
    }
}

void func_global_asm_8060116C(u8 arg0) {
    func_global_asm_80737E30(D_global_asm_8076BF20[arg0]);
}

void func_global_asm_806011A0(u8 arg0, s32 arg1) {
    func_global_asm_80737E90(D_global_asm_8076BF20[arg0], arg1, arg0);
}

void func_global_asm_806011D4(s32 arg0, s32 arg1, s32 arg2) {

}

void func_global_asm_806011E4(u8 arg0, s32 arg1, u8 arg2) {
    func_global_asm_80737F0C(D_global_asm_8076BF20[arg0], arg1, arg2);
}

void func_global_asm_80601224(u8 arg0, s32 arg1) {
    func_global_asm_80737FD8(D_global_asm_8076BF20[arg0], arg1, arg0);
}

void func_global_asm_80601258(u8 arg0, s32 arg1) {
    func_global_asm_8073801C(D_global_asm_8076BF20[arg0], arg1, arg0);
}

void func_global_asm_8060128C(u8 arg0, s32 arg1, u8 arg2) {
    func_global_asm_80738080(D_global_asm_8076BF20[arg0], arg1, arg2);
}

void func_global_asm_806012D4(u8 arg0, u8 arg1, u8 arg2) {
    func_global_asm_807380CC(D_global_asm_8076BF20[arg0], arg1, arg2);
}

void func_global_asm_8060131C(u8 arg0, s32 arg1, u8 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            func_global_asm_8060128C(arg0, i & 0xFF, arg2);
        }
    }
}

void func_global_asm_806013A0(u8 arg0, u8 arg1, u8 arg2) {
    func_global_asm_80738118(D_global_asm_8076BF20[arg0], arg1, arg2);
}

void func_global_asm_806013E8(u8 arg0, s32 arg1, u8 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            func_global_asm_80738118(D_global_asm_8076BF20[arg0], i, arg2);
        }
    }
}

void func_global_asm_80601484(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            if (arg2 != 0) {
                func_global_asm_80601258(arg0, i);
            } else {
                func_global_asm_80601224(arg0, i);
            }
        }
    }
}

void func_global_asm_8060151C(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            if (arg2 != 0) {
                D_global_asm_8076BF20[arg0]->chanMask |= arg1;
            } else {
                D_global_asm_8076BF20[arg0]->chanMask &= (arg1 ^ 0xFFFF);
            }
        }
    }
}

void func_global_asm_806015E0(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((1 << i) & arg1) {
            func_global_asm_80738230(D_global_asm_8076BF20[arg0], i, arg2);
        }
    }
}

void func_global_asm_80601678(u8 arg0, u8 arg1, u8 arg2) {
    func_global_asm_807382A0(D_global_asm_8076BF20[arg0], 0, arg1 | 0xB0, 0x21, arg2);
}

void func_global_asm_806016D0(u8 arg0, u8 arg1, u8 arg2) {
    func_global_asm_807382A0(D_global_asm_8076BF20[arg0], 0, arg1 | 0xB0, 0x22, arg2);
}

void func_global_asm_80601728(u8 arg0, u8 arg1, u8 arg2) {
    func_global_asm_807382A0(D_global_asm_8076BF20[arg0], 0, arg1 | 0xB0, 0x23, arg2);
}

void func_global_asm_80601780(u8 arg0, s32 arg1) {
    func_global_asm_80738320(D_global_asm_8076BF20[arg0], arg1, arg0);
}

void func_global_asm_806017B4(u8 arg0) {
    func_global_asm_807383B0(D_global_asm_8076BF20[arg0]);
}

void func_global_asm_806017E8(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    func_global_asm_80738400(D_global_asm_8076BF20[arg0], arg1, arg2, arg3, arg4);
}

void func_global_asm_80601848(u8 arg0, f32 arg1, f32 arg2) {
    func_global_asm_807381D8(D_global_asm_8076BF20[arg0], arg1, arg2);
}

void func_global_asm_8060188C(u8 arg0, s32 arg1) {
    D_global_asm_8076BF20[arg0]->nextDelta += arg1;
}

ALMicroTime func_global_asm_806018B4(u8 arg0) {
    return D_global_asm_8076BF20[arg0]->curTime;
}

void func_global_asm_806018D4(u8 arg0, u8 arg1, s32 arg2) {
    func_global_asm_80738E58(&D_global_asm_8076BF48[arg0], &D_global_asm_8076C328[arg0], arg1, arg2);
}

void func_global_asm_8060193C(u8 arg0, u8 arg1) {
    alCSeqSetLoc(
        &D_global_asm_8076BF48[arg0], 
        &D_global_asm_8076C328[arg0].unk0[arg1]);
}

void func_global_asm_806019B8(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_global_asm_807382A0(D_global_asm_8076BF20[arg0], arg1, arg2, arg3, arg4);
}
