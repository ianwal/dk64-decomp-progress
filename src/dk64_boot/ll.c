#include "common.h"


u64 __ull_rshift(u64 arg0, u64 arg1) {
    return arg0 >> arg1;
}

u64 __ull_rem(u64 arg0, u64 arg1) {
    return arg0 % arg1;
}

u64 __ull_div(u64 arg0, u64 arg1) {
    return arg0 / arg1;
}

s64 __ll_lshift(u64 arg0, u64 arg1) {
    return arg0 << arg1;
}

s64 __ll_rem(u64 arg0, u64 arg1) {
    return arg0 % arg1;
}

s64 __ll_div(s64 arg0, s64 arg1) {
    return arg0 / arg1;
}

u64 __ll_mul(u64 arg0, u64 arg1) {
    return arg0 * arg1;
}

void __ull_divremi(u64 *div, u64 *rem, u64 arg2, u16 arg3) {
    *div = arg2 / arg3;
    *rem = arg2 % arg3;
}

s64 __ll_mod(s64 arg0, s64 arg1) {
    s64 temp = arg0 % arg1;
    if ((temp < 0 && arg1 > 0) || (temp > 0 && arg1 < 0)) {
        temp += arg1;
    }
    return temp;
}

s64 __ll_rshift(s64 arg0, s64 arg1) {
    return arg0 >> arg1;
}
