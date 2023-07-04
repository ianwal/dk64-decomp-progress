#include <ultra64.h>
#include "functions.h"


extern s32 D_80744470[];

extern s8 D_807563B0;
extern u8 D_807563B4;

extern OSThread D_807FDDA0;

extern OSMesgQueue D_807FEF58;
extern s32 D_807FEF70;
extern s32 D_807FEF74;
extern s32 D_807FEF78;
extern s32 D_807FEF80;
extern u16 D_807FEF84;
extern s16 D_807FEF86;

extern OSMesgQueue D_807FEF58;
extern s32 D_807FEF80;

extern u8 D_807FF01C;
extern s32 D_807FF020;
extern s32 D_807FF024;
extern s32 D_807FF028;

void func_80732280(void *);
extern void *D_807FEF50;

void func_80731B20(s32 arg0, s32 arg1, s32 arg2) {
    D_807FEF80 = arg0;
    D_807FEF78 = 2;
    D_807FEF84 = 0xFFFF;
    D_807FEF86 = 1;
    D_807FEF70 = arg1;
    D_807FEF74 = arg2;
}

void func_80731B60(s32 arg0) {
    if (!arg0) {
        D_807FEF84 = 0xFFFF;
    } else {
        D_807FEF84 = 0xF801;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_80731B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_80731D20.s")

// regalloc, rodata?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_80731E68.s")

extern s32 D_80756360[];
extern s32 D_807563B8;

extern s32 D_80760168; // TODO: Datatype
extern s32 D_80760170; // TODO: Datatype
extern s32 D_80760174; // TODO: Datatype
extern s32 D_80760178; // TODO: Datatype
extern s32 D_8076017C; // TODO: Datatype

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct807FEF88;

extern Struct807FEF88 D_807FEF88[];
extern s32 D_807FF018;
extern s32 D_807FEF7C;

typedef struct {
    u8 unk0[0xE4 - 0x0];
    s32 unkE4;
    u8 unkE8[0xFC - 0xE8];
    s32 unkFC;
} Struct80731E68_unk20;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    Struct80731E68_unk20 *unk20;
} Struct80731E68;

/*
void func_80731E68(Struct80731E68 *arg0) {
    s32 *var_s1;
    s32 j;
    s32 i;
    Struct80731E68_unk20 *temp_s6;

    D_807FEF78 = 2;
    D_807FEF84 = 0xFFFF;
    D_807FEF86 = 1;
    temp_s6 = &arg0->unk20;
    for (i = 0; i < 0x18; i += 6) {
        D_807FEF7C = i * 3;
        D_807FEF70 = i * 3;
        D_807FEF74 = i;
        func_80731D20(&D_80760168);
        func_80731D20(&D_80760170, temp_s6->unkFC);
        func_80731D20(&D_80760174, temp_s6->unkE4);
        if (D_807563B8 >= 4) {
            for (j = 0; j < D_807FF018; j++) {
                func_80731D20(&D_80760178, D_807FEF88[j].unk0);
            }
        }
    }
    if (D_807FF01C != 0) {
        func_80731D20(&D_8076017C, D_80756360[D_807FF01C], D_807FF020, D_807FF024, D_807FF028);
    }
    if (D_807563B8 < 4) {
        D_807563B8++;
    }
    if (D_807563B8 == 4) {
        func_80732158(arg0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_8073202C.s")

/*
s32 func_8073202C(s32 arg0, s32 *arg1, s32 *arg2) {
    if ((arg0 & 0xFFFF0000) == 0x8FBF0000) {
        *arg2 = arg1[(s16)arg0];
        return TRUE;
    }
    return FALSE;
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_80732064.s")

/*
s32 func_80732064(s32 arg0, s32 *arg1) {
    if ((arg0 & 0xFFFF0000) == 0x27BD0000) {
        *arg1 += (s16)arg0;
        return TRUE;
    }
    return FALSE;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_8073209C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_80732158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_80732280.s")

/*
// TODO: Matches except for some extra NOPs being inserted in this version
// No idea why
void func_80732280(void* arg0) {
    OSMesg *sp3C;
    s32 *temp_s0;
    s32 temp_s1;
    s32 temp;

    osSetEventMesg(0xC, &D_807FEF58, 0x10);
    do {
        do {
            osRecvMesg(&D_807FEF58, &sp3C, 1);
        } while (!D_807563B4);
        temp_s1 = func_80005A70();
    } while (!temp_s1);

    while (TRUE) {
        for (temp = 0; temp < 2; temp++) {
            osViBlack(0);
            D_807FEF80 = D_80744470[temp];
            func_80731E68(temp_s1);
            func_80731E68(temp_s1);
        }
    }
}
*/

void func_80732354(u8 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_807FF01C = arg0;
    D_807FF020 = arg1;
    D_807FF024 = arg2;
    D_807FF028 = arg3;
    func_8061D4E4(0);
}

void func_8073239C(void) {
    __osSetFpcCsr(__osGetFpcCsr() | FPCSR_EZ);
    osCreateMesgQueue(&D_807FEF58, &D_807FEF50, 1);
    osCreateThread(&D_807FDDA0, 8, func_80732280, NULL, &D_807FEF50, 0x32);
    osStartThread(&D_807FDDA0);
    D_807563B0 = 1;
}
