#include <ultra64.h>
#include "functions.h"

// TODO: Needs MIPS3 support

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/__ull_to_f.s")

// float __ull_to_f(unsigned long long u) {
//    return u;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_800075CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_800075E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_80007688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_80007724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_8000773C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_80007754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/libc/llcvt/func_80007788.s")

// Not sure whcih order these are in yet

// long long __d_to_ll(double d) {
//    return d;
// }
// long long __f_to_ll(float f) {
//    return f;
// }
// unsigned long long __d_to_ull(double d) {
//    return d;
// }
// unsigned long long __f_to_ull(float f) {
//    return f;
// }
// double __ll_to_d(long long s) {
//    return s;
// }
// float __ll_to_f(long long s) {
//    return s;
// }
// double __ull_to_d(unsigned long long u) {
//    return u;
// }
