#include "common.h"

extern void *D_dk64_boot_80013AB0;
extern u8 *D_dk64_boot_80013AC0;
extern s32 D_dk64_boot_80013AC4;
extern s32 D_dk64_boot_80013AD8;
extern s32 D_dk64_boot_80013ADC;
extern s32 D_dk64_boot_80013AE8;
extern s32 D_dk64_boot_80013AEC;
extern s32 D_dk64_boot_80013AF0;

// .data
s32 D_dk64_boot_8000EEE0 = 8;
s32 D_dk64_boot_8000EEE4 = 0;

s32 func_dk64_boot_800025A4(void);

void func_dk64_boot_800024E0(u8 **arg0, s32 *arg1, void *arg2) {
    D_dk64_boot_80013AC0 = *arg0;
    D_dk64_boot_80013AC4 = *arg1;
    D_dk64_boot_80013AB0 = arg2;
    func_dk64_boot_80002750();
    if (D_dk64_boot_80013AC0[D_dk64_boot_80013AEC] != 0x1F) {
        D_dk64_boot_80013AEC++;
    }
    D_dk64_boot_8000EEE0 = func_dk64_boot_800025A4();
    if (D_dk64_boot_8000EEE0 >= 0) {
        func_dk64_boot_800023F4(); // inflate()
        (*arg0) += D_dk64_boot_80013AEC;
        (*arg1) += D_dk64_boot_80013AF0;
    }
}

extern s32 D_dk64_boot_80013ACC;

s32 func_dk64_boot_800025A4(void) {
    s32 temp_t4;
    u8 temp_t9;

    D_dk64_boot_80013AEC += 2;
    D_dk64_boot_8000EEE0 = -1;
    D_dk64_boot_80013ACC = 0;
    D_dk64_boot_8000EEE0 = D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++];
    if (D_dk64_boot_8000EEE0 != 8) {
        D_dk64_boot_8000EEE4 = 1;
        return -1;
    }

    temp_t9 = D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++];
    D_dk64_boot_80013AEC += 6;

    if (temp_t9 & 2) {
        D_dk64_boot_80013AEC += 2;
    }

    if (temp_t9 & 4) {
        temp_t4 = D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++];
        temp_t4 |= D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++] << 8;
        D_dk64_boot_80013AEC += temp_t4;
    }

    if (temp_t9 & 8) {
        while (D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++] != 0) {
        }
    }

    if (temp_t9 & 16) {
        while (D_dk64_boot_80013AC0[D_dk64_boot_80013AEC++] != 0) {
        }
    }

    D_dk64_boot_80013ACC = D_dk64_boot_80013AEC + 8;
    return D_dk64_boot_8000EEE0;
}

u32 func_dk64_boot_80002724(u32 arg0, s32 arg1) {
    u32 v1 = 0;
    do {
        v1 |= (arg0 & 1);
        arg0 >>= 1;v1 <<= 1;
    } while (--arg1 > 0);
    return v1 >> 1;
}

// Lol
void func_dk64_boot_80002750(void) {
    D_dk64_boot_80013AF0 = 0;
    D_dk64_boot_80013AE8 = \
    D_dk64_boot_80013AEC = 0;
    D_dk64_boot_80013AD8 = \
    D_dk64_boot_80013ADC = 0;
}
