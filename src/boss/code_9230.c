#include <ultra64.h>
#include "functions.h"

const s32 D_boss_80036660[] = {
    0x00546C51,
    0x03E44100,
    0x283C283C,
    0x283C5F00,
    0x2B4F2878,
    0x29037850,
};

const s32 D_boss_80036678[] = {
    0x28055103,
    0xE441004F,
    0x28142904,
    0x2D500000,
};

const s32 D_boss_80036688[] = {
    0x28055103,
    0xE441004F,
    0x2C0F2A02,
    0x14290428,
    0x50000000,
};

const s32 D_boss_8003669C[] = {
    0x28055103,
    0xE441004F,
    0x2C0A2906,
    0x1E500000,
};

// Jumptable, 2608 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_9230/func_boss_8002D230.s")
