#include <ultra64.h>
#include <stdarg.h>
#include "functions.h"

const char D_dk64_boot_80010310[] = "0123456789abcdefghijklmnopqrstuvwxyz";
const char D_dk64_boot_80010338[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char D_dk64_boot_80010360[] = "";
const char D_dk64_boot_80010364[] = "(null)";
const char D_dk64_boot_8001036C[] = "(nil)";

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3D20/func_dk64_boot_80003120.s")

int sprintf(char *str, const char *format, ...) {
    s32 ret;
    va_list args;
    va_start(args, format);

    ret = _Printf(str, format, args);
    va_end(args);
    return ret;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3D20/_Printf.s")

/*
#define isdigit(x) (((x) >= '0' && (x) <= '9'))
#define LDSIGN(x) (((unsigned short*)&(x))[0] & 0x8000)

#define ATOI(i, a)                \
    for (i = 0; isdigit(*a); a++) \
        if (i < 999)              \
            i = *a + i * 10 - '0';

#define PUT(fmt, _size)             \
    if (_size > 0) {                \
        arg = pfn(arg, fmt, _size); \
        if (arg != NULL)            \
            x.nchar += _size;       \
        else                        \
            return x.nchar;         \
    }

#define MAX_PAD ((int)sizeof(spaces) - 1)

#define PAD(src, m)                    \
    if (m > 0) {                       \
        int i;                         \
        int j;                         \
        for (j = m; j > 0; j -= i) {   \
            if ((unsigned)j > MAX_PAD) \
                i = MAX_PAD;           \
            else                       \
                i = j;                 \
            PUT(src, i);               \
        }                              \
    }

void *func_dk64_boot_80003120(s32, s32, u8 **, s32, s32);

s32 _Printf(u8 *arg, u8 *fmt, va_list arg2) {
    u8 *sp1B4;
    u8 sp1A4;
    s32 sp1A0;
    s32 sp19C;
    u8 sp19A;
    s32 sp194;
    s32 sp18C;
    s32 sp188;
    u32 sp184;
    s32 sp180;
    u8 *sp17C;
    u8 sp17B;
    u8 *spF8;
    f64 spE0;
    f64 spD0;
    s32 spC8;
    f64 temp_f2;
    f64 temp_f6;
    f64 var_f0;
    f64 var_f0_2;
    f64 var_f0_3;
    f64 var_f0_4;
    f64 var_f0_5;
    f64 var_f12;
    f64 var_f12_2;
    f64 var_f14;
    f64 var_f16;
    f64 var_f2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s4;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t7;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_10;
    s32 var_a0_5;
    s32 var_a0_8;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 has_h;
    s32 var_a2_2;
    s32 var_a3;
    s32 has_hash;
    s32 var_s2;
    s32 var_s3;
    s32 has_plus;
    s32 has_space;
    s32 has_hyphen;
    s32 var_t0;
    s32 var_t0_10;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_t0_4;
    s32 var_t0_5;
    s32 var_t0_6;
    s32 var_t0_7;
    s32 var_t0_8;
    s32 var_t0_9;
    s32 counter;
    s32 var_t2;
    s32 var_t2_2;
    s32 var_t7;
    s32 var_t8;
    s32 var_v0_10;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_8;
    s32 var_v0_9;
    s32 var_v1_4;
    s32 var_v1_7;
    s8 *temp_a1;
    s8 *var_a0_2;
    s8 *var_s0_2;
    s8 *var_s0_3;
    s8 var_a0_6;
    s8 var_v0_7;
    s8 var_v1_5;
    u32 var_a0_9;
    u8 *temp_a1_4;
    u8 *var_a0_11;
    u8 *var_a0_3;
    u8 *var_a1_4;
    u8 var_t4;
    u8 var_v0_11;
    u8 var_v0_12;
    u8 var_v0_13;
    u8 var_v0_6;
    u8 var_v0_2;
    u8 *temp_s0;
    u8 *temp_v0;
    void *var_a0_4;
    void *var_a0_7;
    u32 *var_v1_3;
    u32 *var_v1_6;

    counter = 0;
    var_f16 = spE0;
    var_s3 = spC8;
    while (*fmt) {
        if (*fmt != '%') {
            while ((*fmt != '%') && (*fmt != 0)) {
                *arg = *fmt++;
                counter++;
                arg++;
            }
        } else {
            var_v0_2 = fmt[-1];
            fmt++;
            has_hash = 0;
            if (var_v0_2 == '%') {
                *arg = '%';
                fmt++;
                counter++;
                arg += 1;
            } else {
                has_hyphen = FALSE;
                has_plus = FALSE;
                has_space = FALSE;
                var_t4 = ' ';
                var_t0 = 0;
                var_t2 = -1;
                var_a0 = 0;
                var_a1 = 0;
                has_h = 0;
                while ((var_v0_2 == ' ') || (var_v0_2 == '+') || (var_v0_2 == '-') || (var_v0_2 == '#') || (var_v0_2 == '0')) {
                    fmt++;
                    switch (var_v0_2) {
                        case ' ':
                            has_space = TRUE;
                            break;
                        case '+':
                            has_plus = TRUE;
                            break;
                        case '-':
                            has_hyphen = TRUE;
                            break;
                        case '#':
                            has_hash = TRUE;
                            break;
                        case '0':
                            var_t4 = '0';
                            break;
                    }
                    var_v0_2 = *fmt;
                }
                if (has_hyphen) {
                    var_t4 = ' ';
                }
                if (var_v0_2 == '*') {
                    arg2 = (u32*)(((u32)arg2 + 3) & ~3) + 4;
                    var_t0 = arg2[-1];
                    if (var_t0 < 0) {
                        var_t0 = -var_t0;
                        has_hyphen = TRUE;
                    }
                    var_v0_2 = fmt[1];
                    fmt++;
                } else {
                    while (isdigit(var_v0_2)) {
                        var_v0_2 = fmt[1];
                        var_t0 = ((var_t0 * 0xA) + var_v0_2) - '0';
                        fmt++;
                    }
                }
                if (var_v0_2 == '.') {
                    var_v0_2 = fmt[1];
                    fmt++;
                    if (var_v0_2 == '*') {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        var_t2 = arg2[-1];
                        if (var_t2 < 0) {
                            var_t2 = -1;
                        }
                        var_v0_2 = fmt[1];
                        fmt++;
                    } else if (isdigit(var_v0_2)) {
                        var_t2 = 0;
                        while (isdigit(var_v0_2)) {
                            var_v0_2 = fmt[1];
                            var_t2 = ((var_t2 * 0xA) + var_v0_2) - '0';
                            fmt++;
                        }
                    }
                }
                while ((var_v0_2 == 'h') || (var_v0_2 == 'l') || (var_v0_2 == 'L') || (var_v0_2 == 'Z') || (var_v0_2 == 'q')) {
                    fmt++;
                    switch (var_v0_2) {
                    case 'h':
                        has_h = TRUE;
                        break;
                    case 'l':
                        if (var_a1 != 0) {
                        case 'q':
block_61:
                            var_a0 = TRUE;
                        } else {
                            var_a1 = TRUE;
                        }
                        break;
                    case 'L':
                        goto block_61;
                    case 'Z':
                        var_a1 = TRUE;
                        break;
                    }
                    var_v0_2 = *fmt;
                }
                fmt++;
                sp19A = var_v0_2;
                switch (var_v0_2) {
                case 'd':
                case 'i':
                    var_a3 = 0xA;
                    if (var_a0 != 0) {
                        arg2 = ((s32) (arg2 + 7) & ~7) + 8;
                        sp180 = arg2[-2];
                        sp184 = arg2[-1];
                    } else {
                        if (var_a1 != 0) {
                            arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                            var_t7 = arg2[-1];
                            sp180 = var_t7 >> 0x1F;
                        } else if (has_h == 0) {
                            arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                            var_t7 = arg2[-1];
                            sp180 = var_t7 >> 0x1F;
                        } else {
                            arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                            var_t7 = (s32) ((s16*)arg2)[-1];
                            sp180 = var_t7 >> 0x1F;
                        }
                        sp184 = var_t7;
                    }
                    var_v0_3 = sp180 < 0;
                    if ((var_v0_3 <= 0) && (sp180 <= 0)) {
                        var_v0_3 = (u32) sp184 < 0U;
                    }
                    var_s2 = var_v0_3 & 0xFF;
                    if (var_v0_3 & 0xFF) {
                        sp18C = -sp184;
                        sp188 = ~sp180 + (sp184 == 0);
                    } else {
                        sp188 = sp180;
                        sp18C = sp184;
                    }
block_94:
                    if (var_t2 >= 0) {
                        var_t4 = ' ';
                    }
                    if (var_t2 == -1) {
                        var_t2 = 1;
                    }
                    spF8 = &sp17B;
                    sp194 = var_a3;
                    sp1A0 = var_t0;
                    sp19C = var_t2;
                    sp1B4 = fmt;
                    sp1A4 = var_t4;
                    spE0 = var_f16;
                    temp_v0 = func_dk64_boot_80003120(sp188, sp18C, &sp17C, var_a3, var_v0_2 == 'X');
                    temp_a1 = temp_v0 - 1;
                    temp_v1 = (&sp17B - temp_v0) + 1;
                    temp_a2 = has_hash != 0;
                    var_a0_2 = temp_a1;
                    fmt = sp1B4;
                    var_f16 = spE0;
                    var_t0_2 = sp1A0 - temp_v1;
                    temp_t2 = sp19C - temp_v1;
                    if ((temp_a2 != 0) && (sp194 == 8) && (temp_t2 <= 0)) {
                        temp_v0[-1] = '0';
                        var_a0_2 = temp_a1 - 1;
                        var_t0_2--;
                    }
                    if (temp_t2 > 0) {
                        var_t0_2 -= temp_t2;
                        var_t2_2 = temp_t2 - 1;
                        while (temp_t2 > 0) {
                            var_t2_2 -= 1;
                            *var_a0_2 = 0x30;
                            var_a0_2 -= 1;
                        }
                    }
                    var_a0_3 = var_a0_2 + 1;
                    if ((temp_a2) && (sp194 == 0x10)) {
                        var_t0_2 -= 2;
                    }
                    if ((var_s2) || (has_plus) || (has_space)) {
                        var_t0_2--;
                    }
                    if ((has_hyphen == 0) && (sp1A4 == ' ')) {
                        var_t0_2--;
                        while (var_t0_2 > 0) {
                            counter++;
                            *arg++ = ' ';
                            var_t0_2--;
                        }
                    }
                    if (var_s2) {
                        counter++;
                        *arg++ = '-';
                    } else if (has_plus) {
                        counter++;
                        *arg++ = '+';
                    } else if (has_space) {
                        counter++;
                        *arg++ = ' ';
                    }
                    if ((temp_a2) && (sp194 == 0x10)) {
                        *arg = '0';
                        counter += 2;
                        arg += 2;
                        arg[-1] = sp19A;
                    }
                    if ((has_hyphen == 0) && (sp1A4 == '0')) {
                        var_t0_2--;
                        while (var_t0_2 > 0) {
                            var_t0_2--;
                            *arg = '0';
                            counter++;
                            arg += 1;
                        }
                    }
                    while ((u32)spF8 >= (u32)var_a0_3) {
                        counter++;
                        *arg++ = *var_a0_3++;
                    }
                    if (has_hyphen != 0) {
                        var_t0_3 = var_t0_2 - 1;
                        while (var_t0_2 > 0) {
                            var_t0_3 -= 1;
                            counter++;
                            *arg = 0x20;
                            arg += 1;
                        }
                    }
                    break;
                case 'u':
                    var_a3 = '\n';
                    has_plus = 0;
                    has_space = 0;
                    var_s2 = 0;
block_86:
                    if (var_a0 != 0) {
                        arg2 = ((s32) (arg2 + 7) & ~7) + 8;
                        sp188 = arg2[-2];
                        sp18C = arg2[-1];
                    } else {
                        if (var_a1 != 0) {
                            arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                            var_t8 = arg2[-1];
                            sp188 = 0;
                        } else if (has_h == 0) {
                            arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                            var_t8 = arg2[-1];
                            sp188 = 0;
                        } else {
                            arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                            var_t8 = (s32) ((s16 *)arg2)[-1];
                            sp188 = 0;
                        }
                        sp18C = var_t8;
                    }
                    goto block_94;
                case 'o':
                    var_a3 = 8;
                    has_plus = FALSE;
                    has_space = FALSE;
                    var_s2 = 0;
                    goto block_86;
                case 'X':
                case 'x':
                    var_a3 = 0x10;
                    has_plus = FALSE;
                    has_space = FALSE;
                    var_s2 = 0;
                    goto block_86;
                case 'E':
                case 'e':
                    var_a1_2 = 0;
                    if (var_t2 < 0) {
                        var_t2 = 6;
                    }
                    if (has_h != 0) {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        spD0 = (f64) arg2[-1];
                    } else {
                        if ((s32) arg2 & 1) {
                            arg2 += 7;
                            var_v1_3 = arg2 - 0x16;
                        } else {
                            if ((s32) arg2 & 2) {
                                arg2 += 0xA;
                                var_a0_4 = arg2 - 0x28;
                            } else {
                                arg2 = ((s32) (arg2 + 7) & ~7) + 8;
                                var_a0_4 = arg2;
                            }
                            var_v1_3 = var_a0_4;
                        }
                        spD0 = var_v1_3[-2];
                    }
                    if (spD0 < 0) {
                        var_a1_2 = 1;
                        spD0 = -spD0;
                    }
                    temp_a0 = -(var_t2 & 3);
                    if (spD0 == 0.0) {
                        var_s3 = 0;
                        var_f16 = 1.0;
                    } else if (spD0 < 1.0) {
                        var_s3 = 0;
                        var_f16 = 1.0;
                        while (spD0 < var_f16) {
                            var_f16 /= 10.0;
                            var_s3 -= 1;
                        }
                    }
                    if (spD0 >= 1.0) {
                        var_s3 = 0;
                        var_f16 = 1.0;
                        var_f0 = 10.0;
                        while (var_f0 <= spD0) {
                            var_f16 = var_f0;
                            var_f0 *= 10.0;
                            var_s3 += 1;
                        }
                    }
                    var_f0_2 = var_f16 * 0.5;
                    var_v0_4 = var_t2;
                    if (var_t2 > 0) {
                        if (temp_a0 != 0) {
                            do {
                                var_v0_4 -= 1;
                                var_f0_2 /= 10.0;
                            } while ((temp_a0 + var_t2) != var_v0_4);
                            if (var_v0_4 != 0) {
                                goto block_164;
                            }
                        } else {
block_164:
                            var_v0_5 = var_v0_4 - 4;
                            var_f0_3 = var_f0_2 / 10.0;
                            while (var_v0_5 != 0) {
                                var_v0_5 -= 4;
                                var_f0_3 = (((var_f0_3 / 10.0) / 10.0) / 10.0) / 10.0;
                            }
                            var_f0_2 = ((var_f0_3 / 10.0) / 10.0) / 10.0;
                        }
                    }
                    temp_f2 = var_f16 * 10.0;
                    temp_v0_2 = var_a1_2 != 0;
                    var_a0_5 = temp_v0_2;
                    temp_f6 = spD0 + var_f0_2;
                    spD0 = temp_f6;
                    if (temp_f2 <= temp_f6) {
                        var_f16 = temp_f2;
                        var_s3 += 1;
                    }
                    var_a2_2 = (var_s3 < 0x64) ^ 1;
                    if (temp_v0_2 == 0) {
                        var_a0_5 = has_plus != 0;
                        if (var_a0_5 == 0) {
                            var_a0_5 = has_space != 0;
                        }
                    }
                    var_v1_4 = var_t2 > 0;
                    if (var_t2 <= 0) {
                        var_v1_4 = has_hash != 0;
                    }
                    temp_a1_2 = var_v1_4 + var_a0_5 + var_t2 + var_a2_2 + 5;
                    if ((has_hyphen == 0) && (var_t4 == ' ')) {
                        var_t0 -= 1;
                        while (temp_a1_2 < var_t0) {
                            var_t0 -= 1;
                            counter++;
                            *arg++ = var_t4;
                        }
                    }
                    if (temp_v0_2 != 0) {
                        counter++;
                        *arg++ = '-';
                    } else if (has_plus != 0) {
                        counter++;
                        *arg++ = '+';
                    } else if (has_space != 0) {
                        counter++;
                        *arg++ = ' ';
                    }
                    if ((has_hyphen == 0) && (var_t4 == '0')) {
                        var_t0--;
                        while (temp_a1_2 < var_t0) {
                            var_t0--;
                            counter++;
                            *arg++ = var_t4;
                        }
                    }
                    var_v0_6 = '0';
                    counter++;
                    while (var_f16 <= spD0) {
                        var_v0_6++;
                        spD0 -= var_f16;
                    }
                    *arg = var_v0_6;
                    var_s0_2 = arg + 1;
                    var_f16 /= 10.0;
                    if ((var_t2 > 0) || (has_hash != 0)) {
                        counter++;
                        *var_s0_2 = '.';
                        var_s0_2++;
                    }
                    while (var_t2 > 0) {
                        var_v0_7 = '0';
                        counter++;
                        var_t2--;
                        while (var_f16 <= spD0) {
                            var_v0_7++;
                            spD0 -= var_f16;
                        }
                        *var_s0_2 = var_v0_7;
                        var_s0_2++;
                        var_f16 /= 10.0;
                    }
                    counter++;
                    temp_s0 = var_s0_2 + 1;
                    temp_s0[-1] = sp19A;
                    if (var_s3 < 0) {
                        var_s3 = -var_s3;
                        var_a2_2 = (var_s3 < 100) ^ 1;
                        var_v1_5 = ((s32) (var_s3 / 10) % 10) + '0';
                        counter++;
                        var_a0_6 = (var_s3 % 10) + '0';
                        *temp_s0 = '-';
                    } else {
                        *temp_s0 = '+';
                        var_v1_5 = ((s32) (var_s3 / 10) % 10) + '0';
                        counter++;
                        var_a0_6 = (var_s3 % 10) + '0';
                    }
                    var_s0_3 = temp_s0 + 1;
                    if (var_a2_2 != 0) {
                        *var_s0_3 = (var_s3 / 100) + '0';
                        counter++;
                        var_s0_3 += 1;
                    }
                    *var_s0_3 = var_v1_5;
                    counter += 2;
                    var_s0_3[1] = var_a0_6;
                    arg = var_s0_3 + 2;
                    if (has_hyphen != 0) {
                        var_t0_4 = var_t0 - 1;
                        while (temp_a1_2 < var_t0) {
                            var_t0_4--;
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    break;
                case 'G':
                case 'g':
                    break;
                case 'f':
                    var_f12 = 1.0;
                    var_a1_3 = 0;
                    var_f14 = 10.0;
                    if (var_t2 < 0) {
                        var_t2 = 6;
                    }
                    var_v0_8 = 0;
                    if (var_t2 > 0) {
                        temp_a0_2 = var_t2 & 3;
                        if (temp_a0_2 != 0) {
                            do {
                                var_v0_8 += 1;
                                var_f12 /= 10.0;
                            } while (temp_a0_2 != var_v0_8);
                            if (var_v0_8 != var_t2) {
                                goto block_216;
                            }
                        } else {
block_216:
                            var_v0_9 = var_v0_8 + 4;
                            var_f12_2 = var_f12 / 10.0;
                            while (var_v0_9 != var_t2) {
                                var_v0_9 += 4;
                                var_f12_2 = (((var_f12_2 / 10.0) / 10.0) / 10.0) / 10.0;
                            }
                            var_f12 = ((var_f12_2 / 10.0) / 10.0) / 10.0;
                        }
                    }
                    if (has_h != 0) {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        var_f0_4 = (f64) arg2[-1];
                    } else {
                        if ((s32) arg2 & 1) {
                            arg2 += 7;
                            var_v1_6 = arg2 - 0x16;
                        } else {
                            if ((s32) arg2 & 2) {
                                arg2 += 0xA;
                                var_a0_7 = arg2 - 0x28;
                            } else {
                                arg2 = ((s32) (arg2 + 7) & ~7) + 8;
                                var_a0_7 = arg2;
                            }
                            var_v1_6 = var_a0_7;
                        }
                        var_f0_4 = var_v1_6[-2];
                    }
                    if (var_f0_4 < 0.0) {
                        var_a1_3 = 1;
                        var_f0_4 = -var_f0_4;
                    }
                    var_f0_5 = var_f0_4 + (var_f12 * 0.5);
                    var_v0_10 = 1;
                    var_f2 = 1.0;
                    temp_a2_2 = var_a1_3 != 0;
                    while (var_f14 <= var_f0_5) {
                        var_f2 = var_f14;
                        var_f14 *= 10.0;
                        var_v0_10 += 1;
                    }
                    var_a0_8 = temp_a2_2;
                    if (temp_a2_2 == 0) {
                        var_a0_8 = has_plus != 0;
                        if (var_a0_8 == 0) {
                            var_a0_8 = has_space != 0;
                        }
                    }
                    var_v1_7 = var_t2 > 0;
                    if (var_t2 <= 0) {
                        var_v1_7 = has_hash != 0;
                    }
                    temp_a1_3 = var_v1_7 + var_a0_8 + var_v0_10 + var_t2;
                    if ((has_hyphen == 0) && (var_t4 == 0x20)) {
                        var_t0 -= 1;
                        while (temp_a1_3 < var_t0) {
                            var_t0 -= 1;
                            counter++;
                            *arg = var_t4;
                            arg += 1;
                        }
                    }
                    if (temp_a2_2 != 0) {
                        counter++;
                        *arg++ = '-';
                    } else if (has_plus != 0) {
                        counter++;
                        *arg++ = '+';
                    } else if (has_space != 0) {
                        counter++;
                        *arg++ = ' ';
                    }
                    if ((has_hyphen == 0) && (var_t4 == '0')) {
                        var_t0--;
                        while (temp_a1_3 < var_t0) {
                            var_t0--;
                            counter++;
                            *arg++ = var_t4;
                        }
                    }
                    do {
                        var_v0_11 = '0';
                        while (var_f2 <= var_f0_5) {
                            var_f0_5 -= var_f2;
                            var_v0_11++;
                        }
                        var_f2 /= 10.0;
                        counter++;
                        *arg++ = var_v0_11;
                    } while (var_f2 >= 1.0);
                    if ((var_t2 > 0) || (has_hash != 0)) {
                        counter++;
                        *arg++ = '.';
                    }
                    while (var_t2 > 0) {
                        var_v0_12 = '0';
                        counter++;
                        var_t2 -= 1;
                        while (var_f2 <= var_f0_5) {
                            var_f0_5 -= var_f2;
                            var_v0_12++;
                        }
                        *arg = var_v0_12;
                        arg++;
                        var_f2 /= 10.0;
                    }
                    if (has_hyphen != 0) {
                        var_t0_5 = var_t0 - 1;
                        while (temp_a1_3 < var_t0) {
                            var_t0_5 -= 1;
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    break;
                case 'c':
                    arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                    temp_t7 = arg2[-1];
                    sp188 = temp_t7 >> 0x1F;
                    sp18C = temp_t7;
                    if (has_hyphen == 0) {
                        var_t0 -= 1;
                        while (var_t0 > 0) {
                            var_t0 -= 1;
                            counter++;
                            *arg++ = var_t4;
                        }
                    }
                    counter++;
                    arg += 1;
                    arg[-1] = (s8) sp18C;
                    if (has_hyphen != 0) {
                        var_t0_6 = var_t0 - 1;
                        while (var_t0_6 > 0) {
                            var_t0_6 -= 1;
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    break;
                case 's':
                    arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                    temp_a1_4 = arg2[-1];
                    if (temp_a1_4 == NULL) {
                        if ((var_t2 == -1) || (var_a0_9 = 0, ((var_t2 < 6) == 0))) {
                            var_a1_4 = &D_dk64_boot_80010364;
                            var_a0_9 = 6;
                        } else {
                            var_a1_4 = &D_dk64_boot_80010360;
                        }
                    } else {
                        sp17C = temp_a1_4;
                        sp1A0 = var_t0;
                        sp19C = var_t2;
                        sp1B4 = fmt;
                        spE0 = var_f16;
                        var_a1_4 = temp_a1_4;
                        var_a0_9 = strlen(temp_a1_4);
                    }
                    if ((var_t2 != -1) && (var_t2 < var_a0_9)) {
                        var_a0_9 = var_t2;
                    }
                    var_t0_7 = var_t0 - var_a0_9;
                    if (!has_hyphen) {
                        var_t0_7--;
                        while (var_t0_7 > 0) {
                            var_t0_7--;
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    var_a0_10 = var_a0_9 - 1;
                    while ((!var_a0_9) ^ 1) {
                        var_a0_10--;
                        counter++;
                        *arg++ = *var_a1_4++;
                    }
                    if (has_hyphen) {
                        while (var_t0_8-- > 0) {
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    break;
                case 'p':
                    arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                    var_a0_11 = &D_dk64_boot_8001036C;
                    if (arg2[-1]) {
                        var_a3 = 0x10;
                        sp19A = 0x78;
                        has_hash = 1;
                        sp188 = 0;
                        sp18C = arg2[-1];
                        var_s2 = 0;
                        var_v0_2 = 0x78;
                        goto block_94;
                    }
                    var_t0_9 = var_t0 - 5;
                    if (!has_hyphen) {
                        var_t0_9--;
                        while (var_t0_9 > 0) {
                            var_t0_9--;
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    var_v0_13 = D_dk64_boot_8001036C;
                    while (var_v0_13) {
                        *arg++ = var_v0_13;
                        var_v0_13 = var_a0_11[1];
                        counter++;
                        var_a0_11++;
                    }
                    if (has_hyphen) {
                        var_t0_10 = var_t0_9 - 1;
                        while (var_t0_9 > 0) {
                            var_t0_10--;
                            counter++;
                            *arg++ = ' ';
                        }
                    }
                    break;
                case 'n':
                    if (var_a0) {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        arg2[-1] = (s32) (counter >> 0x1F);
                        arg2[0] = counter;
                    } else if (var_a1) {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        arg2[-1] = counter;
                    } else if (!has_h) {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        arg2[-1] = counter;
                    } else {
                        arg2 = ((s32) (arg2 + 3) & ~3) + 4;
                        arg2[-1] = (s16) counter;
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    spE0 = var_f16;
    spC8 = var_s3;
    *arg = 0;
    return counter;
}
*/
