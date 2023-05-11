#include <ultra64.h>
#include "functions.h"


void func_80002750(void);

s32 D_8000EEE0;

void *D_80013AB0;
u8 *D_80013AC0;
s32 D_80013AC4;
s32 D_80013AD8;
s32 D_80013ADC;
s32 D_80013AE8;
s32 D_80013AEC;
s32 D_80013AF0;

void func_800024E0(u8 **arg0, s32 *arg1, void *arg2) {
    D_80013AC0 = *arg0;
    D_80013AC4 = *arg1;
    D_80013AB0 = arg2;
    func_80002750();
    if (D_80013AC0[D_80013AEC] != 0x1F) {
        D_80013AEC++;
    }
    D_8000EEE0 = func_800025A4();
    if (D_8000EEE0 >= 0) {
        func_800023F4();
        (*arg0) += D_80013AEC;
        (*arg1) += D_80013AF0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_30E0/func_800025A4.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_30E0/func_80002724.s")
#else
u32 func_80002724(u32 arg0, s32 arg1) {
    u32 v1 = 0;
    do {
        v1 |= (arg0 & 1);
        arg1--;
        arg0 >>= 1;
        v1 <<= 1;
    } while (arg1 > 0);
    return v1 >> 1;
}
#endif

// Lol
void func_80002750(void) {
    D_80013AF0 = 0;
    D_80013AE8 = \
    D_80013AEC = 0;
    D_80013AD8 = \
    D_80013ADC = 0;
}
