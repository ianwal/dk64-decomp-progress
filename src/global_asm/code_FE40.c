#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_FE40/func_global_asm_8060B140.s")

extern s8 D_global_asm_80746834;
extern OSMesgQueue D_global_asm_807655F0;
extern OSIoMesg D_global_asm_807ECE00;
extern void *D_global_asm_807ECE18;

/*
// Doable, datatype and stack issues
void func_global_asm_8060B140(u32 arg0, u8 *arg1, s32 *arg2, u8 arg3, u8 arg4, u8 arg5, u8 *arg6) {
    u8 *sp5C;
    u8 *sp58;
    u8 *sp50;
    s32 var_v1;
    u32 var_a0;
    u32 var_s0;
    u8 *var_s1;

    sp58 = arg1;
    if ((arg3 != 0) || (arg4 != 0)) {
        if (arg3 & 0x80) {
            sp5C = arg6;
            arg6 += 0x3800;
        } else if (arg6 != NULL) {
            sp5C = 0x80024000;
        } else {
            sp50 = malloc(*arg2);
            sp5C = sp50;
        }
    } else {
        sp5C = arg1;
    }
    osInvalDCache(sp5C, *arg2);
    var_v1 = *arg2;
    var_s0 = 0;
    var_s1 = sp5C;
    var_a0 = var_v1 >> 0xE;
    if (var_a0 != 0) {
        do {
            osPiStartDma(&D_global_asm_807ECE00, 0, 0, arg0, var_s1, 0x4000, &D_global_asm_807655F0);
            D_global_asm_80746834 = 4;
            osRecvMesg(&D_global_asm_807655F0, NULL, 1);
            D_global_asm_80746834 = 0;
            var_s0 += 1;
            var_v1 = *arg2;
            arg0 += 0x4000;
            var_s1 += 0x4000;
            var_a0 = var_v1 >> 0xE;
        } while (var_s0 < var_a0);
    }
    if (var_v1 - (var_a0 << 0xE) != 0) {
        osPiStartDma(&D_global_asm_807ECE00, 0, 0, arg0, var_s1, var_v1 - (var_a0 << 0xE), &D_global_asm_807655F0);
        D_global_asm_80746834 = 5;
        osRecvMesg(&D_global_asm_807655F0, NULL, 1);
        D_global_asm_80746834 = 0;
    }
    D_global_asm_807ECE18 = arg6;
    if ((arg6 == NULL) && ((arg5 == 1) || (arg5 == 2))) {
        D_global_asm_807ECE18 = malloc(0x4000);
    }
    switch (arg5) {
        case 1:
            if (arg3 != 0) {
                func_dk64_boot_800024E0(&sp5C, &arg1, D_global_asm_807ECE18);
            }
            if (arg4 != 0) {
                func_dk64_boot_800024E0(&sp5C, &arg1, D_global_asm_807ECE18);
            }
            break;
        case 2:
            if (arg3 != 0) {
                func_dk64_boot_80002790(&sp5C, &arg1, D_global_asm_807ECE18, arg3);
            }
            if (arg4 != 0) {
                func_dk64_boot_80002790(&sp5C, &arg1, D_global_asm_807ECE18, arg4);
            }
            break;
    }
    if ((arg6 == NULL) && ((arg5 == 1) || (arg5 == 2))) {
        func_global_asm_8061130C(D_global_asm_807ECE18);
    }
    if ((arg3 != 0) || (arg4 != 0)) {
        *arg2 = arg1 - sp58;
        if (arg6 == NULL) {
            func_global_asm_8061130C(sp50);
        }
    }
}
*/
