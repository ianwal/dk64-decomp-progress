#include <ultra64.h>
#include "functions.h"

// .rodata
const char D_global_asm_8075FFF0[] = "CLIP ARRAY OVERFLOW";
const char D_global_asm_80760004[] = "MAIN STACK OVERFLOW";
const char D_global_asm_80760018[] = "DFS OVERFLOW";
const char D_global_asm_80760028[] = "OUT OF MEMORY";
const char D_global_asm_80760038[] = "DATABASE ERROR";
const char D_global_asm_80760048[] = "DMA ERROR";
const char D_global_asm_80760054[] = "LOOKUP ERROR";
const char D_global_asm_80760064[] = "TOO MANY OBJECTS";
const char D_global_asm_80760078[] = "KILL SOUND ERROR";
const char D_global_asm_8076008C[] = "STORED STATE ERROR";
const char D_global_asm_807600A0[] = "MATRIX COPY ERROR";
const char D_global_asm_807600B4[] = "DELAYED KILLS OVERFLOW";
const char D_global_asm_807600CC[] = "LOCK STACK OVERFLOW";
const char D_global_asm_807600E0[] = "POSTFUNCTIONS OVERFLOW";
const char D_global_asm_807600F8[] = "SIGNALS OVERFLOW";
const char D_global_asm_8076010C[] = "SORT LIST EARLY ERROR";
const char D_global_asm_80760124[] = "SORT LIST LATE ERROR";
const char D_global_asm_8076013C[] = "DISPLAY LIST ERROR";
const char D_global_asm_80760150[] = "OBJECT EXIST OVERFLOW";

/*
const char D_global_asm_80760168[] = "DK 64\n";
const char D_global_asm_80760170[] = "%X\n";
const char D_global_asm_80760174[] = "%X\n";
const char D_global_asm_80760178[] = "%X\n";
const char D_global_asm_8076017C[] = "%s %x %x %x";
*/

extern s32 D_global_asm_80744470[];

extern s8 D_global_asm_807563B0;
extern u8 D_global_asm_807563B4;

extern OSThread D_global_asm_807FDDA0;

extern OSMesgQueue D_global_asm_807FEF58;
extern s32 D_global_asm_807FEF70;
extern s32 D_global_asm_807FEF74;
extern s32 D_global_asm_807FEF78;
extern u16 *D_global_asm_807FEF80;
extern u16 D_global_asm_807FEF84;
extern u16 D_global_asm_807FEF86;

extern OSMesgQueue D_global_asm_807FEF58;

extern u8 D_global_asm_807FF01C;
extern s32 D_global_asm_807FF020;
extern s32 D_global_asm_807FF024;
extern s32 D_global_asm_807FF028;

void func_global_asm_80732280(void *);
extern void *D_global_asm_807FEF50;

void func_global_asm_80731B20(s32 arg0, s32 arg1, s32 arg2) {
    D_global_asm_807FEF80 = arg0;
    D_global_asm_807FEF78 = 2;
    D_global_asm_807FEF84 = 0xFFFF;
    D_global_asm_807FEF86 = 1;
    D_global_asm_807FEF70 = arg1;
    D_global_asm_807FEF74 = arg2;
}

void func_global_asm_80731B60(s32 arg0) {
    if (!arg0) {
        D_global_asm_807FEF84 = 0xFFFF;
    } else {
        D_global_asm_807FEF84 = 0xF801;
    }
}

typedef struct StackTraceLetterStruct {
    u8 line[6];
} StackTraceLetterStruct;

extern s16 D_global_asm_80744490;
extern u8 D_global_asm_8074450C;
extern StackTraceLetterStruct D_global_asm_80756130[];

void func_global_asm_80731B88(u8 arg0) {
    s32 i, j, k, l;
    u16 *var_v1;
    u8 *var_v0;

    var_v0 = &D_global_asm_80756130[arg0 - '!'];
    var_v1 = ((D_global_asm_807FEF70 + 3) * D_global_asm_8074450C * 4) + D_global_asm_807FEF80 + (D_global_asm_80744490 * (D_global_asm_807FEF74 + 3) * D_global_asm_8074450C * 6);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < D_global_asm_8074450C * D_global_asm_807FEF78; j++) {
            for (k = 3; k >= 0; k--) {
                for (l = 0; l < D_global_asm_8074450C * D_global_asm_807FEF78; l++) {
                    *var_v1++ = *var_v0 & (1 << k) ? D_global_asm_807FEF84 : D_global_asm_807FEF86;
                }
            }
            var_v1 += (D_global_asm_80744490 - (D_global_asm_807FEF78 * 4 * D_global_asm_8074450C));

        }
        var_v0++;
    }
}



// Close, regalloc, stack
// https://decomp.me/scratch/3IeSa
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_80731D20.s")

extern s32 D_global_asm_807FEF70;
extern s32 D_global_asm_807FEF74;
extern s32 D_global_asm_807FEF78;
extern s32 D_global_asm_807FEF7C;

/*
void func_global_asm_80731D20(char *arg0, ...) {
    unsigned char sp4D[0x81];
    unsigned char *var_s1;
    unsigned char character;

    func_dk64_boot_8000320C(&sp4D);
    var_s1 = &sp4D;
    character = *var_s1;
    while (character != '\0') {
        switch (character) {
            case ' ':
                D_global_asm_807FEF70 += D_global_asm_807FEF78;
                break;
            case '\t':
                D_global_asm_807FEF70 /= 8;
                D_global_asm_807FEF70++;
                D_global_asm_807FEF70 *= 8;
                break;
            case '\n':
                D_global_asm_807FEF74 += D_global_asm_807FEF78;
                D_global_asm_807FEF70 = D_global_asm_807FEF7C;
                break;
            default:
                func_global_asm_80731B88(character);
                D_global_asm_807FEF70 += D_global_asm_807FEF78;
                break;
        }
        character = *var_s1;
        var_s1++;
    }
}
*/

// regalloc, rodata, close, doable
// https://decomp.me/scratch/x50qz
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_80731E68.s")

extern s32 D_global_asm_80756360[];
extern s32 D_global_asm_807563B8;

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct807FEF88;

extern Struct807FEF88 D_global_asm_807FEF88[];
extern s32 D_global_asm_807FF018;
extern s32 D_global_asm_807FEF7C;

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
void func_global_asm_80731E68(Struct80731E68 *arg0) {
    s32 *var_s1;
    s32 j;
    s32 i;
    Struct80731E68_unk20 *temp_s6;

    D_global_asm_807FEF78 = 2;
    D_global_asm_807FEF84 = 0xFFFF;
    D_global_asm_807FEF86 = 1;
    temp_s6 = &arg0->unk20;
    for (i = 0; i < 0x18; i += 6) {
        D_global_asm_807FEF7C = i * 3;
        D_global_asm_807FEF70 = i * 3;
        D_global_asm_807FEF74 = i;
        func_global_asm_80731D20("DK 64\n");
        func_global_asm_80731D20("%X\n", temp_s6->unkFC);
        func_global_asm_80731D20("%X\n", temp_s6->unkE4);
        if (D_global_asm_807563B8 >= 4) {
            for (j = 0; j < D_global_asm_807FF018; j++) {
                func_global_asm_80731D20("%X\n", D_global_asm_807FEF88[j].unk0);
            }
        }
    }
    if (D_global_asm_807FF01C != 0) {
        func_global_asm_80731D20("%s %x %x %x", D_global_asm_80756360[D_global_asm_807FF01C], D_global_asm_807FF020, D_global_asm_807FF024, D_global_asm_807FF028);
    }
    if (D_global_asm_807563B8 < 4) {
        D_global_asm_807563B8++;
    }
    if (D_global_asm_807563B8 == 4) {
        func_global_asm_80732158(arg0);
    }
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_8073202C.s")

/*
s32 func_global_asm_8073202C(s32 arg0, u8 *arg1, s32 *arg2) {
    if ((arg0 & 0xFFFF0000) == 0x8FBF0000) {
        arg0 = (s16)arg0;
        *arg2 = *(s32*)(&arg1[arg0]);
        return TRUE;
    }
    return FALSE;
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_80732064.s")

/*
s32 func_global_asm_80732064(s32 arg0, s32 *arg1) {
    if ((arg0 & 0xFFFF0000) == 0x27BD0000) {
        *arg1 += (s16)arg0;
        return TRUE;
    }
    return FALSE;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_8073209C.s")

// doable, close, not 100% on signature
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_80732158.s")

/*
void func_global_asm_80732158(Actor *arg0) {
    Actor *sp48; // compiler-managed
    s32 sp40;
    f32 sp3C;
    s32 var_v0;
    s32 var_v1;
    u32 *temp_s0;

    sp48 = arg0->unk11C;
    sp40 = arg0->unkF4;
    sp3C = arg0->unk104;
    D_global_asm_807FF018 = 0;
    while ((sp48 != NULL) && (D_global_asm_807FF018 < 0x12)) {
        temp_s0 = sp48->unk0;
        sp48 = &sp48->animation_state;
        var_v0 = func_global_asm_8073209C(temp_s0, &sp40, sp3C, &sp48);
        if (var_v0 == 0) {
            var_v0 = func_global_asm_8073202C(temp_s0, sp40, &sp3C);
        }
        if (var_v0 == 0) {
            func_global_asm_80732064(temp_s0, &sp40);
        }
        var_v1 = (D_global_asm_807FF018 != 0 && !(D_global_asm_807FEF88[D_global_asm_807FF018 - 1].unk4 < 0x10));
        if (var_v1) {
            break;
        }
    }
    D_global_asm_807563B8 += 1;
}
*/

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_136820/func_global_asm_80732280.s")

/*
// TODO: Matches except for some extra NOPs being inserted in this version
// No idea why
void func_global_asm_80732280(void* arg0) {
    OSMesg *sp3C;
    s32 *temp_s0;
    s32 temp_s1;
    s32 temp;

    osSetEventMesg(0xC, &D_global_asm_807FEF58, 0x10);
    do {
        do {
            osRecvMesg(&D_global_asm_807FEF58, &sp3C, 1);
        } while (!D_global_asm_807563B4);
        temp_s1 = func_dk64_boot_80005A70();
    } while (!temp_s1);

    while (TRUE) {
        for (temp = 0; temp < 2; temp++) {
            osViBlack(0);
            D_global_asm_807FEF80 = D_global_asm_80744470[temp];
            func_global_asm_80731E68(temp_s1);
            func_global_asm_80731E68(temp_s1);
        }
    }
}
*/

void raiseException(u8 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_global_asm_807FF01C = arg0;
    D_global_asm_807FF020 = arg1;
    D_global_asm_807FF024 = arg2;
    D_global_asm_807FF028 = arg3;
    func_global_asm_8061D4E4(NULL);
}

void func_global_asm_8073239C(void) {
    __osSetFpcCsr(__osGetFpcCsr() | FPCSR_EZ);
    osCreateMesgQueue(&D_global_asm_807FEF58, &D_global_asm_807FEF50, 1);
    osCreateThread(&D_global_asm_807FDDA0, 8, func_global_asm_80732280, NULL, &D_global_asm_807FEF50, 0x32);
    osStartThread(&D_global_asm_807FDDA0);
    D_global_asm_807563B0 = 1;
}
