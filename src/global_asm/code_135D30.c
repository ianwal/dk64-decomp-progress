#include <ultra64.h>
#include "functions.h"


extern u8 temporary_flag_block[];
u8* getFlagBlockAddress(u8 flagType); // TODO: Can we use the FlagTypes enum? Needs to be a u8 to match

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_80731030.s")

/*
// TODO: Not sure why this doesn't match, maybe turn it into a while loop?
void func_80731030(void) { // clearTemporaryFlags()
    s32 flagIndex;
    for (flagIndex = 0; flagIndex != 0xE; flagIndex++) {
        temporary_flag_block[flagIndex] = 0;
    }
}
*/

void clearPermanentFlags(void) {
    s32 flagIndex;
    for (flagIndex = 0; flagIndex < 0x316; flagIndex++) {
        setFlag(flagIndex, FALSE, FLAG_TYPE_PERMANENT);
    }
}

void clearGlobalFlags(void) {
    s32 flagIndex;
    for (flagIndex = 0; flagIndex < 0x2C; flagIndex++) {
        setFlag(flagIndex, FALSE, FLAG_TYPE_GLOBAL);
    }
}

u8 isFlagSet(s16 flagIndex, u8 flagType) { // TODO: Can we use the FlagTypes enum? Needs to be a u8 to match
    u8 *flagBlock;
    s16 flagByte;

    if (flagIndex == -1) {
        return 0;
    }
    switch (flagType) {
        case FLAG_TYPE_PERMANENT:
        case FLAG_TYPE_GLOBAL:
            flagBlock = getFlagBlockAddress(flagType);
            break;
        case FLAG_TYPE_TEMPORARY:
            flagBlock = &temporary_flag_block;
    }
    flagByte = flagIndex >> 3;
    return flagBlock[flagByte] >> (s16)(flagIndex - flagByte * 8) & 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_807311C4.s")

typedef struct {
    s16 unk0; // Start Permanent Flag Index
    s16 unk2; // End Permanent Flag Index
    s16 unk4; // Flag Count Required
    s16 unk6; // Global Flag To Set
} Struct80756024;
extern Struct80756024 D_80756024[];

void func_807311C4(s16, s32);

/*
void func_807311C4(s16 arg0, s32 arg1) {
    s32 i;
    s32 chosenFlag;

    chosenFlag = -1;
    for (i = 0; i < 0x21 && chosenFlag == -1; i++) {
        if (arg0 >= D_80756024[i].unk0 && D_80756024[i].unk2 >= arg0) {
            if (func_80731AA8(D_80756024[i].unk0, (D_80756024[i].unk2 - D_80756024[i].unk0) + 1, FLAG_TYPE_PERMANENT) == D_80756024[i].unk4) {
                chosenFlag = D_80756024[i].unk6;
            }
        }
    }

    if (chosenFlag >= 0) {
        setFlag(chosenFlag, TRUE, FLAG_TYPE_GLOBAL);
    }
}
*/

void setFlag(s16 flagIndex, u8 newValue, u8 flagType) {
    u8 *flagBlock;
    s16 flagByte;
    s32 sp2C; // This is load bearing, cannot remove

    if (flagIndex != -1) {
        switch (flagType) {
            case FLAG_TYPE_PERMANENT:
            case FLAG_TYPE_GLOBAL:
                flagBlock = getFlagBlockAddress(flagType);
                break;
            case FLAG_TYPE_TEMPORARY:
                flagBlock = &temporary_flag_block;
                break;
        }
        flagByte = flagIndex >> 3;
        if (newValue) {
            flagBlock[flagByte] |= 1 << (s16)(flagIndex - (flagByte * 8));
        } else {
            flagBlock[flagByte] &= ~(1 << (s16)(flagIndex - (flagByte * 8)));
        }
        if (newValue && (flagType == FLAG_TYPE_PERMANENT)) {
            func_807311C4(flagIndex, flagType);
        }
    }
}

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4; // Used, permanent flag index
    s16 unk6;
} Struct80755A20;

extern Struct80755A20 D_80755A20[];

typedef struct {
    u8 unk0; // Used, likely map
    u8 unk1;
    s16 unk2; // Used
    u16 unk4; // Used
    u8 unk6; // Used
    u8 unk7; // Used
} Struct807FDCD0;

extern Struct807FDCD0 D_807FDCD0[];

void func_807313BC(void) {
    s32 i;

    for (i = 0; i < 24; i++) {
        if (!func_805FF938(D_807FDCD0[i].unk0)) {
            D_807FDCD0[i].unk7 = 0;
        }
    }
}

void func_80731410(s16 arg0, s16 arg1, s16 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < 24; i++) {
        if (D_807FDCD0[i].unk7 == 0) {
            D_807FDCD0[i].unk0 = arg0;
            D_807FDCD0[i].unk2 = arg1;
            D_807FDCD0[i].unk4 = arg2;
            D_807FDCD0[i].unk6 = arg3;
            D_807FDCD0[i].unk7 = 1;
            return;
        }
    }
}

void func_807314F4(s16 arg0, s16 arg1) {
    s32 max = 0x71;
    s32 i;

    for (i = 0; i < max; i++) {
        if ((arg0 == D_80755A20[i].unk0) && (arg1 == D_80755A20[i].unk2)) {
            setFlag(D_80755A20[i].unk4, TRUE, FLAG_TYPE_PERMANENT);
            return;
        }
    }

    for (i = 0; i < 24; i++) {
        if (D_807FDCD0[i].unk7 && arg0 == D_807FDCD0[i].unk0 && arg1 == D_807FDCD0[i].unk2) {
            setFlag(D_807FDCD0[i].unk4, TRUE, FLAG_TYPE_PERMANENT);
            D_807FDCD0[i].unk7 = 0;
            return;
        }
    }
}

u8 func_807315D4(s16 arg0, s16 arg1) {
    s32 i;
    s32 max = 0x71;

    for (i = 0; i < max; i++) {
        if ((arg0 == D_80755A20[i].unk0) && (arg1 == D_80755A20[i].unk2)) {
            return isFlagSet(D_80755A20[i].unk4, FLAG_TYPE_PERMANENT);
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_80731654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_80731784.s")

typedef struct {
    u8 map;
    s8 unk1;
    s16 spawnerID;
    s16 flagIndex;
    s8 unk6;
    s8 unk7;
} Struct80755DA8;

extern Struct80755DA8 D_80755DA8[]; // 0x1F

/*
// TODO: Close
s16 func_80731784(s16 map, s16 spawnerID, s32 *arg2) {
    s16 i;
    s16 max = 0x1F;

    *arg2 = 0;
    for (i = 0; i < max; i++) {
        if (map == D_80755DA8[i].map) {
            if (spawnerID == D_80755DA8[i].spawnerID) {
                *arg2 = i;
                return D_80755DA8[i].flagIndex;
            }
        }
    }
    return -1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_807317FC.s")

// Seems doable, but stack/datatype/address issues, hmm
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_135D30/func_807318AC.s")

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct80755F4C;

extern Struct80755F4C D_80755F4C[];

// TODO: This might not be right, the struct array is not used anywhere else
s16 func_8073195C(s16 arg0) {
    if (arg0 == 0) {
        return -1;
    }
    return D_80755F4C[arg0].unk0;
}

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
} Struct80755F50;

extern Struct80755F50 D_80755F50[];

u8 func_8073198C(s16 arg0) {
    s32 i;
    s32 max = 0x35;

    for (i = 0; i < max; i++) {
        if (arg0 == D_80755F50[i].unk0) {
            return D_80755F50[i].unk2;
        }
    }
    return 0;
}

// Returns a permanent flag index
s32 func_807319D8(s32 arg0, s32 arg1, s32 arg2) {
    s32 tmp = -1;
    if (arg1 < 8) {
        if (arg2 < 5) {
            tmp = (arg1 * 5) + arg0 + arg2;
        }
    }
    return tmp;
}

s32 func_80731A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 flagIndex;
    s32 i;
    s32 count;

    count = 0;
    if (arg3 >= 5) {
        return 0;
    }
    
    for (i = arg1; i <= arg2; i++) {
        flagIndex = func_807319D8(arg0, i, arg3);
        if (flagIndex >= 0) {
            count += isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
        }
    }
    return count;
}

// countSetFlags(startIndex, length, flagType);
s32 func_80731AA8(s32 startIndex, s32 length, u8 flagType) {
    s32 flagIndex;
    s32 count = 0;
    for (flagIndex = startIndex; flagIndex < startIndex + length; flagIndex++) {
        count += isFlagSet(flagIndex, flagType);
    }
    return count;
}
