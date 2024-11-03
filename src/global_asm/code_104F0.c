#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 score;
    unsigned char initials[3];
} Struct80757044;

u8 func_global_asm_8060BBE0(u16, u8);
void func_global_asm_8060C758(u8, s32);

extern s8 D_global_asm_80744460;

extern s32 D_global_asm_807463C0[];
extern Struct80757044 D_global_asm_80744548[];
extern Struct80757044 D_global_asm_80744568[];
extern s32 D_global_asm_807467C0;
extern s8 D_global_asm_807467C4;
extern s8 D_global_asm_807467CC;
extern s8 D_global_asm_80746834;
extern void (*D_global_asm_807467D0[])();
extern u8 D_global_asm_807467E0;
extern s32 D_global_asm_807467EC[];

// .rodata
const char D_global_asm_80757020[] = "7.2";

const char D_global_asm_80757024[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.- ";

const Struct80757044 D_global_asm_80757044[] = {
    {100, "AAA"},
    { 90, "AAA"},
    { 80, "AAA"},
    { 70, "AAA"},
    { 60, "AAA"},
};

const Struct80757044 D_global_asm_80757064[] = {
    {100, "AAA"},
    { 90, "AAA"},
    { 80, "AAA"},
    { 70, "AAA"},
    { 60, "AAA"},
};

extern OSMesgQueue D_global_asm_807ECCF0;
extern s16 D_global_asm_807ECEA0;
extern u8 D_global_asm_807ECEA8[];
extern u8 D_global_asm_807EDEA8[4]; // EEPROM file mapping
extern s32 D_global_asm_807EDEAC;
extern u8 D_global_asm_807EDEB0[];
extern OSMesg D_global_asm_807EE0B0;
extern OSMesgQueue D_global_asm_807EE0D0;
extern s32 D_global_asm_807EE0E8;

extern s32 D_global_asm_807F0298;
extern OSMesgQueue D_global_asm_807F02B8;
extern u8 D_global_asm_807FC952;

extern u8 D_global_asm_807ED6A8[];

#define	FILE_SIZE (((D_global_asm_807ECEA0 + 0x6B7 & -64) + 0x27) & -8)
#define	FILE_SIZE_BYTES FILE_SIZE / 8

void func_global_asm_8060B7F0(void) {
    s32 i;

    D_global_asm_807ECEA0 = 0;
    for (i = 0; i < 8; i++) {
        D_global_asm_807ECEA0 += func_global_asm_80631C20(i);
    }
}

void func_global_asm_8060B84C(f32 arg0) {
    OSTimer sp48;
    u64 temp_ret_3;
    OSMesg sp3C;
    void *sp38;

    temp_ret_3 = __ull_div(__ll_mul(__f_to_ull(arg0 * 1000.0f), 0xBB8), 0x40);
    osSetTimer(&sp48, temp_ret_3, 0, &D_global_asm_807EE0D0, sp3C);
    D_global_asm_80746834 = 1;
    osRecvMesg(&D_global_asm_807EE0D0, &sp38, 1);
    D_global_asm_80746834 = 0;
}

void func_global_asm_8060B8F8(s32 arg0) {
    if (osGetThreadId(0) == 9) {
        D_global_asm_807467D0[arg0]();
        return;
    }
    if (D_global_asm_80744460 == 0) {
        osSendMesg(&D_global_asm_807F02B8, arg0, 0);
    }
}

s32 func_global_asm_8060B968(u8 *arg0, u16 arg1) {
    u32 var_v1 = -1;
    u32 temp = arg1--;

    while (temp != 0) {
        var_v1 = D_global_asm_807463C0[(u8)(*arg0 ^ var_v1)] ^ (var_v1 >> 8);temp = arg1--;
        arg0++;
    }
    return var_v1 ^ -1;
}

u8 getEEPROMSaveSlot(s32 fileIndex) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if (fileIndex == D_global_asm_807EDEA8[i]) {
            return i;
        }
    }
    return 0;
}

// 2015 MMM Implications...
void func_global_asm_8060BA14(void) {
    u8 currentFileSaveSlot = getEEPROMSaveSlot(current_file);
    u8 temporaryFileSaveSlot = getEEPROMSaveSlot(3);

    if ((gameIsInAdventureMode() || gameIsInQuitGameMode()) && (currentFileSaveSlot != temporaryFileSaveSlot)) {
        void *src = &D_global_asm_807ECEA8[FILE_SIZE_BYTES * currentFileSaveSlot];
        void *dest = &D_global_asm_807ECEA8[FILE_SIZE_BYTES * temporaryFileSaveSlot];
        memcpy(dest, src, FILE_SIZE_BYTES);

        // Switch the two file indexes in the file mapping array using the XOR trick
        // It avoids using a temporary variable
        D_global_asm_807EDEA8[temporaryFileSaveSlot] = D_global_asm_807EDEA8[currentFileSaveSlot] ^ D_global_asm_807EDEA8[temporaryFileSaveSlot];
        D_global_asm_807EDEA8[currentFileSaveSlot] ^= D_global_asm_807EDEA8[temporaryFileSaveSlot];
        D_global_asm_807EDEA8[temporaryFileSaveSlot] = D_global_asm_807EDEA8[currentFileSaveSlot] ^ D_global_asm_807EDEA8[temporaryFileSaveSlot];
    }
}

// TODO: Double check signature
u8 func_global_asm_8060BB18(u32, u16, u8);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060BB18.s")

/*
u8 func_global_asm_8060BB18(u32 arg0, u16 arg1, u8 arg2) {
    s32 *var_t1;
    s32 temp_t2;
    s32 temp_t3;
    u8 temp_t9;
    u8 var_a3;
    s32 var_v0;
    s32 var_v1;
    u32 var_s0;

    var_s0 = arg0;
    var_v0 = -1;
    var_v1 = 0;
    var_a3 = arg1 & 0x1F;
    var_t1 = &D_global_asm_807ECEA8[arg1 >> 5];
    while (arg2 != 0) {
        temp_t9 = var_a3 + 1;
        arg2--;
        var_v0 ^= 1 << var_a3;
        var_v1 |= (var_s0 & 1) << var_a3;
        var_s0 = var_s0 >> 1;
        var_a3 = temp_t9;
        if (temp_t9 > 0x1F || arg2 == 0) {
            temp_t3 = *var_t1;
            var_t1++;
            var_a3 = 0;
            var_t1[-1] = (temp_t3 & var_v0) | var_v1;
            var_v1 = 0;
            var_v0 = -1;
        }
    }
    return var_v0; // Hmm, possible it doesn't return
}
*/

// Extremely fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060BBE0.s")

void func_global_asm_8060BCA0(s32 arg0, u8 arg1, u8 arg2, u16 *arg3, u8 *arg4) {
    *arg3 = *arg3 + D_global_asm_807ECEA0 + ((arg1) * 0xA1) + 0x320;
    *arg4 = 0;
    switch (arg0) {
        case 11:
            if (*arg4 == 0) {
                *arg4 = 1;
            }
            *arg3 += 3;
            // fallthrough
        case 10:
            if (*arg4 == 0) {
                *arg4 = 3;
            }
            *arg3 += 8;
            // fallthrough
        case 9:
            if (*arg4 == 0) {
                *arg4 = 8;
            }
            *arg3 += 4;
            // fallthrough
        case 8:
            if (*arg4 == 0) {
                *arg4 = 4;
            }
            *arg3 += 2;
            // fallthrough
        case 7:
            if (*arg4 == 0) {
                *arg4 = 2;
            }
            *arg3 += 3;
            // fallthrough
        case 6:
            if (*arg4 == 0) {
                *arg4 = 3;
            }
            *arg3 += 2;
            // fallthrough
        case 5:
            if (*arg4 == 0) {
                *arg4 = 2;
            }
            *arg3 += 2;
            // fallthrough
        case 4:
            if (*arg4 == 0) {
                *arg4 = 2;
            }
            *arg3 += 0x18;
            // fallthrough
        case 3:
            if (*arg4 == 0) {
                *arg4 = 3;
                *arg3 += arg2 * 3;
            }
            *arg3 += 0x38;
            // fallthrough
        case 2:
            if (*arg4 == 0) {
                *arg4 = 7;
                *arg3 += arg2 * 7;
            }
            *arg3 += 0x38;
        case 1:
            // fallthrough
            if (*arg4 == 0) {
                *arg4 = 7;
                *arg3 += arg2 * 7;
            }
            break;
    }
}

void func_global_asm_8060BEA8(s32 arg0, u8 arg1, u16 *arg2, u8 *arg3) {
    *arg2 = *arg2 + D_global_asm_807ECEA0 + 0x645;
    *arg3 = 0;
    switch (arg0) {
        case 15:
            if (*arg3 == 0) {
                *arg3 = 2;
            }
            *arg2 += 0x18;
            // fallthrough
        case 16:
            if (*arg3 == 0) {
                *arg3 = 0x18;
            }
            *arg2 += 0x16;
            // fallthrough
        case 14:
            if (*arg3 == 0) {
                *arg3 = 0x16;
            }
            *arg2 += 1;
            // fallthrough
        case 13:
            if (*arg3 == 0) {
                *arg3 = 1;
            }
            *arg2 += 2;
            // fallthrough
        case 12:
            if (*arg3 == 0) {
                *arg3 = 2;
            }
            break;
    }
}

void func_global_asm_8060BF84(s32 arg0, u8 arg1, u16 *arg2, u8 *arg3) {
    *arg2 = (((((((D_global_asm_807ECEA0 + 0x6B7) & 0xFFC0) + 0x27) & 0xFFF8) * 4) + 0x3F) & 0xFFC0) + 0x40;
    *arg3 = 0;
    switch (arg0) {
        case 32:
            if (*arg3 == 0) {
                *arg3 = 1;
            }
            *arg2 += 3;
            // fallthrough
        case 31:
            if (*arg3 == 0) {
                *arg3 = 3;
            }
            *arg2 += 2;
            // fallthrough
        case 30:
            if (*arg3 == 0) {
                *arg3 = 2;
            }
            *arg2 += 0x2D;
            // fallthrough
        case 29:
            if (*arg3 == 0) {
                *arg3 = 9;
                *arg2 += arg1 * 9;
            }
            *arg2 += 0x19;
            // fallthrough
        case 28:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x19;
            // fallthrough
        case 27:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x19;
            // fallthrough
        case 26:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x2D;
            // fallthrough
        case 25:
            if (*arg3 == 0) {
                *arg3 = 9;
                *arg2 += arg1 * 9;
            }
            *arg2 += 0x19;
            // fallthrough
        case 24:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x19;
            // fallthrough
        case 23:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x19;
            // fallthrough
        case 22:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x4B;
            // fallthrough
        case 21:
            if (*arg3 == 0) {
                *arg3 = 0xF;
                *arg2 += arg1 * 0xF;
            }
            *arg2 += 0x19;
            // fallthrough
        case 20:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x19;
            // fallthrough
        case 19:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x19;
            // fallthrough
        case 18:
            if (*arg3 == 0) {
                *arg3 = 5;
                *arg2 += arg1 * 5;
            }
            *arg2 += 0x11;
        case 17:
            // fallthrough
            if (*arg3 == 0) {
                *arg3 = 0x12;
            }
    }
}

void func_global_asm_8060C2C4(s32 arg0, s32 arg1, u8 arg2, u16 *arg3, s8 *arg4) {
    s32 i;
    *arg3 += 800;
    for (i = 0; i < arg2; i++) {
        *arg3 += func_global_asm_80631C20(i);
    }
    *arg4 = 1;
}

void func_global_asm_8060C340(u16 *arg0, u8 *arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5) {
    *arg0 = arg5 * FILE_SIZE;
    if (arg2 >= 0x11) {
        func_global_asm_8060BF84(arg2, arg4, arg0, arg1);
    } else if (arg2 >= 0xC) {
        func_global_asm_8060BEA8(arg2, arg4, arg0, arg1);
    } else if (arg2 > 0) {
        func_global_asm_8060BCA0(arg2, arg3, arg4, arg0, arg1);
    } else {
        func_global_asm_8060C2C4(arg2, arg3, arg4, arg0, arg1);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060C430.s")

// TODO: Is arg4 u8?
void func_global_asm_8060C648(s32 arg0, u8 arg1, u8 arg2, u8 fileIndex, s32 arg4) {
    u16 sp26;
    u8 sp25;

    func_global_asm_8060C340(&sp26, &sp25, arg0, arg1, arg2, getEEPROMSaveSlot(fileIndex));
    func_global_asm_8060BB18(func_global_asm_8060C430(arg0, arg4, 1), sp26, sp25);
}

s32 func_global_asm_8060C6B8(s32 arg0, u8 arg1, u8 arg2, u8 fileIndex) {
    s32 temp; // Pad
    u16 sp22;
    u8 sp21;

    func_global_asm_8060C340(&sp22, &sp21, arg0, arg1, arg2, getEEPROMSaveSlot(fileIndex));
    return func_global_asm_8060C430(arg0, func_global_asm_8060BBE0(sp22, sp21), 0);
}

s32 func_global_asm_8060C724(u8 fileIndex) {
    return func_global_asm_8060C6B8(0x10, 0, 0, fileIndex) + 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060C758.s")

/*
void func_global_asm_8060C758(u8 fileIndex, s32 arg1) {
    current_file = fileIndex;
    bzero(&D_global_asm_807ECEA8[getEEPROMSaveSlot(fileIndex) * FILE_SIZE_BYTES], FILE_SIZE_BYTES);
    func_global_asm_8060C648(0xC, 0, 0, fileIndex, 1);
    func_global_asm_8060C648(0xF, 0, 0, fileIndex, fileIndex);
    if (arg1 != 0) {
        func_global_asm_8060B8F8(1);
    }
}
*/

void func_global_asm_8060C830(u8 fileIndex, s32 arg1) {
    current_file = fileIndex;
    func_global_asm_8060C758(fileIndex, 0);
    if (func_global_asm_8060C6B8(0xF, 0, 0, 3) == fileIndex) {
        func_global_asm_8060C758(3, 0);
    }
    if (arg1) {
        func_global_asm_8060B8F8(1);
    }
}

void func_global_asm_8060C8AC(u8 arg0) {
    s32 i;

    if (arg0 & 1) {
        func_global_asm_8060C648(0x11, 0, 0, 0, 0);
    }
    if (arg0 & 2) {
        for (i = 0; i < 5; i++) {
            func_global_asm_8060C648(0x15, 0, i, 0, D_global_asm_807467EC[i]);
            func_global_asm_8060C648(0x12, 0, i, 0, ' ');
            func_global_asm_8060C648(0x13, 0, i, 0, ' ');
            func_global_asm_8060C648(0x14, 0, i, 0, ' ');
        }
    }
    if (arg0 & 4) {
        for (i = 0; i < 5; i++) {
            func_global_asm_8060C648(0x19, 0, i, 0, D_global_asm_80757044[i].score);
            func_global_asm_8060C648(0x16, 0, i, 0, D_global_asm_80757044[i].initials[0]);
            func_global_asm_8060C648(0x17, 0, i, 0, D_global_asm_80757044[i].initials[1]);
            func_global_asm_8060C648(0x18, 0, i, 0, D_global_asm_80757044[i].initials[2]);
            D_global_asm_80744548[i] = D_global_asm_80757044[i];
        }
    }
    if (arg0 & 8) {
        for (i = 0; i < 5; i++) {
            func_global_asm_8060C648(0x1D, 0, i, 0, D_global_asm_80757064[i].score);
            func_global_asm_8060C648(0x1A, 0, i, 0, D_global_asm_80757064[i].initials[0]);
            func_global_asm_8060C648(0x1B, 0, i, 0, D_global_asm_80757064[i].initials[1]);
            func_global_asm_8060C648(0x1C, 0, i, 0, D_global_asm_80757064[i].initials[2]);
            D_global_asm_80744568[i] = D_global_asm_80757064[i];
        }
    }
    if (arg0 & 0x10) {
        func_global_asm_8060C648(0x1E, 0, 0, 0, 0);
    }
    if (arg0 & 0x20) {
        func_global_asm_8060C648(0x1F, 0, 0, 0, 0);
    }
}

void func_global_asm_8060CB74(void) {
    clearGlobalFlags();
    func_global_asm_8060C8AC(0xFF);
}

void func_global_asm_8060CB9C(void) {
    func_global_asm_8060B8F8(3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060CBBC.s")

void func_global_asm_8060D0A8(void) {
    s32 fileIndex;
    s32 currentFileBackup;

    currentFileBackup = current_file;
    // Setup EEPROM file mapping in normal order: 0, 1, 2, 3
    for (fileIndex = 0; fileIndex < 4; fileIndex++) {
        D_global_asm_807EDEA8[fileIndex] = fileIndex;
    }
    bzero(&D_global_asm_807ECEA8, 0x800); // Clear the EEPROM copy
    func_global_asm_8060CB74();
    for (fileIndex = 0; fileIndex < 4; fileIndex++) {
        func_global_asm_8060C758(fileIndex, fileIndex == 3);
    }
    current_file = currentFileBackup;
}

void func_global_asm_8060D14C(void) {
    s32 i;
    s32 var_s2;
    u8 *var_s1;

    var_s2 = 0;
    var_s1 = &D_global_asm_807ED6A8[0];
    if (D_global_asm_807EDEAC != 2) {
        func_global_asm_8060D0A8();
        D_global_asm_807467CC = 1;
        return;
    }
    D_global_asm_807467C4 = 1;
    for (i = 0; i < 0x100 && (var_s2 == 0); i++) {
        var_s2 |= osEepromRead(&D_global_asm_807ECCF0, i, var_s1);
        func_global_asm_8060B84C(15.0f);
        if (D_global_asm_80744460 != 0) {
            D_global_asm_807467C4 = 0;
            return;
        }
        var_s1 += 8;
    }
    D_global_asm_807467C4 = 0;
    D_global_asm_807467CC = 1;
    if (var_s2 == 0) {
        var_s2 = func_dk64_boot_80002B0C(((((((((((D_global_asm_807ECEA0 + 0x6B7) & ~0x3F) + 0x27) & ~7) * 4) + 0x3F) & ~0x3F) + 0x207) & ~7) / 8) + &D_global_asm_807ED6A8[0], D_global_asm_807467C0);
    }
    if (var_s2 != 0) {
        func_global_asm_8060D0A8();
    }
    func_global_asm_8060CB9C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060D2C8.s")

void func_global_asm_8060D768(void) {
    func_global_asm_8060D2C8(0);
}

void func_global_asm_8060D788(void) {
    func_global_asm_8060D2C8(1);
}

void func_global_asm_8060D7A8(void) {
    s32 kongIndex;

    if (func_global_asm_806F6EDC()) {
        D_global_asm_807FC950[0].crystals = 0.5 * func_global_asm_806F8EDC(5, 0);
    }
    // Training Grounds: Orange Barrel Completed
    if (isFlagSet(0x184, FLAG_TYPE_PERMANENT)) {
        D_global_asm_807FC950[0].oranges = 0.5 * func_global_asm_806F8EDC(4, 0);
    }
    // Camera/Shockwave Unlocked
    if (isFlagSet(0x179, FLAG_TYPE_PERMANENT)) {
        D_global_asm_807FC950[0].film = 0.5 * func_global_asm_806F8EDC(6, 0);
    }
    if (D_global_asm_807FC952 != 0) {
        D_global_asm_807FC950[0].standardAmmo = 0.5 * func_global_asm_806F8EDC(2, 0);
    }
    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        current_character_index[0] = kongIndex;
        if (D_global_asm_807FC950[0].character_progress[kongIndex].instrument != 0) {
            D_global_asm_807FC950[0].character_progress[kongIndex].instrument_ammo = 0.5 * func_global_asm_806F8EDC(7, 0);
        }
    }
    current_character_index[0] = 0; // DK
}

// very close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/func_global_asm_8060DC3C.s")

extern s8 D_global_asm_80750AC0;
extern s32 D_global_asm_80750AB0;

/*
// loadTheGame()
void func_global_asm_8060DC3C(u8 fileIndex, s32 arg1) {
    CharacterProgress *phi_fp;
    s32 levelIndex;
    s32 kongIndex;
    s32 byteIndex;

    phi_fp = D_global_asm_807FC950[0].character_progress;
    D_global_asm_80750AC0 = 1;
    func_global_asm_806C9AE0();
    memcpy(&D_global_asm_807ECEA8, &D_global_asm_807ED6A8, 0x800);
    current_file = fileIndex;
    current_character_index[0] = 0; // DK
    if (func_global_asm_8060C6B8(0xD, 0, 0, fileIndex) == 0) {
        func_global_asm_8060C758(fileIndex, 0);
    }
    if (arg1 != 0) {
        func_global_asm_8060BA14();
    }
    cc_number_of_players = 0;
    D_global_asm_807FC950->melons = func_global_asm_8060C6B8(0xC, 0, 0, fileIndex);
    func_global_asm_80709464(0);
    func_global_asm_806C7B00();
    D_global_asm_80750AB0 = func_global_asm_8060C6B8(0xE, 0, 0, fileIndex);
    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        for (byteIndex = 0; byteIndex < 5; byteIndex++) {
            ((u8*)phi_fp)[byteIndex] = func_global_asm_8060C6B8(byteIndex + 4, kongIndex, 0, fileIndex);
        }
        phi_fp->coins = func_global_asm_8060C6B8(9, kongIndex, 0, fileIndex);
        phi_fp->unk5 = func_global_asm_8060C6B8(0xA, kongIndex, 0, fileIndex);
        if (func_global_asm_8060C6B8(0xB, kongIndex, 0, fileIndex)) {
            phi_fp->unk5 |= 0x80;
        }
        for (levelIndex = 0; levelIndex < 8; levelIndex++) {
            phi_fp->coloured_bananas[levelIndex] = func_global_asm_8060C6B8(1, kongIndex, levelIndex, fileIndex);
            phi_fp->coloured_bananas_fed_to_tns[levelIndex] = func_global_asm_8060C6B8(2, kongIndex, levelIndex, fileIndex);    
            phi_fp->golden_bananas[levelIndex] = func_global_asm_8060C6B8(3, kongIndex, levelIndex, fileIndex);
        }
        phi_fp++;
    }
    if (arg1 != 0) {
        func_global_asm_8060D7A8();
    }
    current_character_index[0] = 0;
}
*/

void func_global_asm_8060DEA8(void) {
    func_global_asm_8060B8F8(2);
}

// saveTheGame()
void func_global_asm_8060DEC8(void) {
    s32 kongIndex;
    u32 temp_s1;
    u32 phi_s0;
    s32 byteIndex;
    CharacterProgress *phi_s7;
    s32 levelIndex;

    if ((cc_number_of_players == 1) && (gameIsInQuitGameMode() || gameIsInAdventureMode())) {
        phi_s7 = D_global_asm_807FC950[0].character_progress;
        phi_s0 = func_global_asm_805FC98C();
        temp_s1 = func_global_asm_8060C724(current_file);
        if (phi_s0 >= 0x400000) {
            phi_s0 = -1;
        }
        func_global_asm_8060C648(0xD, 0, 0, current_file, 1);
        func_global_asm_8060C648(0xE, 0, 0, current_file, phi_s0);
        func_global_asm_8060C648(0xC, 0, 0, current_file, D_global_asm_807FC950[0].melons);
        func_global_asm_8060C648(0xF, 0, 0, current_file, current_file);
        func_global_asm_8060C648(0x10, 0, 0, current_file, temp_s1);
        for (kongIndex = 0; kongIndex < 5; kongIndex++) {
            for (byteIndex = 0; byteIndex < 5; byteIndex++) {
                // TODO: Better way to match this?
                func_global_asm_8060C648(byteIndex + 4, kongIndex, 0, current_file, ((u8*)phi_s7)[byteIndex]);
            }
            func_global_asm_8060C648(9, kongIndex, 0, current_file, phi_s7->coins);
            func_global_asm_8060C648(0xA, kongIndex, 0, current_file, phi_s7->unk5 & 0x7F);
            func_global_asm_8060C648(0xB, kongIndex, 0, current_file, (phi_s7->unk5 >> 7) & 1);
            for (levelIndex = 0; levelIndex < 8; levelIndex++) {
                func_global_asm_8060C648(1, kongIndex, levelIndex, current_file, phi_s7->coloured_bananas[levelIndex]);
                func_global_asm_8060C648(2, kongIndex, levelIndex, current_file, phi_s7->coloured_bananas_fed_to_tns[levelIndex]);
                func_global_asm_8060C648(3, kongIndex, levelIndex, current_file, phi_s7->golden_bananas[levelIndex]);
            }
            phi_s7++;
        }
        func_global_asm_8060B8F8(1);
    }
}

void func_global_asm_8060E128(s32 arg0) {
    s32 sp2C;

    while (TRUE) {
        osRecvMesg(&D_global_asm_807F02B8, &sp2C, 1);
        D_global_asm_807467D0[sp2C]();
    }
}

void func_global_asm_8060E1A8(void) {
    func_global_asm_8060B7F0();
    D_global_asm_807EDEAC = osEepromProbe(&D_global_asm_807ECCF0);
    osCreateMesgQueue(&D_global_asm_807EE0D0, &D_global_asm_807EE0B0, 8);
    osCreateMesgQueue(&D_global_asm_807F02B8, &D_global_asm_807F0298, 8);
    osCreateThread(&D_global_asm_807EE0E8, 9, func_global_asm_8060E128, 0, &D_global_asm_807F0298, 0xC);
    osStartThread(&D_global_asm_807EE0E8);
    D_global_asm_807467E0 = 1;
    func_global_asm_8060B8F8(0);
}

// TODO: Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_104F0/getFlagBlockAddress.s")

/*
u8 *getFlagBlockAddress(u8 flagType) {
    s32 temp_t6;
    u8 *phi_v1;
    phi_v1 = NULL;
    switch (flagType) {
        case FLAG_TYPE_PERMANENT:
            if ((gameIsInDKTVMode()) || (cc_number_of_players >= 2)) {
                func_global_asm_80731030(); // clearTemporaryFlags()
                bzero(&D_global_asm_807EDEB0, FILE_SIZE_BYTES);
                phi_v1 = &D_global_asm_807EDEB0;
            } else {
                phi_v1 = &D_global_asm_807ECEA8[getEEPROMSaveSlot(current_file) * FILE_SIZE_BYTES];
            }
            break;
        case FLAG_TYPE_GLOBAL:
            phi_v1 = &D_global_asm_807ECEA8[((((FILE_SIZE * 4) + 0x3F) & ~0x3F) / 8)];
            break;
    }
    return phi_v1;
}
*/

u8 func_global_asm_8060E3B0(u16 arg0, u8 arg1) {
    u8 phi_v1;
    u16 sp24;
    u8 sp23;

    phi_v1 = 0;
    if (gameIsInAdventureMode()) {
        func_global_asm_8060C340(&sp24, &sp23, 0, 0, arg1, getEEPROMSaveSlot(current_file));
        phi_v1 = func_global_asm_8060BBE0(sp24 + arg0, 1);
    }
    return phi_v1;
}

void func_global_asm_8060E430(u16 arg0, u8 arg1, u8 arg2) {
    u16 sp26;
    u8 sp25;

    if (gameIsInAdventureMode()) {
        func_global_asm_8060C340(&sp26, &sp25, 0, 0, arg2, getEEPROMSaveSlot(current_file));
        func_global_asm_8060BB18(arg1, sp26 + arg0, 1);
    }
}
