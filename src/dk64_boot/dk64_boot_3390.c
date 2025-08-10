#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002828.s")

// Related to decompression? Handwritten.
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_800028E0.s")

// Related to decompression? Maybe extracting bits from stream and turning into values?
// https://decomp.me/scratch/TARdJ
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_800029EC.s")
/*
// Kind of close?
u32 func_dk64_boot_800029EC(u8 *a0, u32 a3, u32 s4, u32 s5) {
    u32 v0 = 0;
    u32 t4 = s4;

    while (a3 != 0) {
        if (t4 == s4) {
            if (*a0 & t4) {
                v0 |= a3;
            }
            a0 += s5;
        }
        t4 >>= 1;
        a3 >>= 1;
        if (t4 == 0) {
            t4 = s4;
        }
    }
    return v0;
}
*/

u8 *_strcpy(u8 *dest, const u8 *src) {
    u8 *ptr = dest;
    while ((*dest++ = *src++) != '\0');
    return ptr;
}

// Same as the standard strncpy, but doesn't pad remaining buffer with zeroes.
// It only writes a single null-terminator.
u8 *_strncpy(u8 *dest, const u8 *src, u32 count) {
    u8 *ptr = dest;

    while (count-- && (*dest++ = *src++) != '\0');

    if (count == 0) {
        *dest = '\0';
    }
    return ptr;
}

u8 *func_dk64_boot_80002ABC(u8 *str, u8 *arg1) {
    u8 *start_str;
    u8 temp_t7;
    
    start_str = str;
    while (*str) {
        str++;
    }
    str++;
    temp_t7 = *arg1;
    arg1++;
    str[-1] = temp_t7;
    while (temp_t7) {
        str++;
        temp_t7 = *arg1++;
        str[-1] = temp_t7;
    }
    return start_str;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002B0C.s")

// Case-insensitive strncmp
s32 dk64_strncasecmp(const u8 *str1, const u8 *str2, u32 count) {
    u8 c1;
    u8 c2;

    if (*str1 != '\0' || *str2 != '\0') {
        while (count > 0) {
            c1 = *str1;
            // TODO: This is probably a TOUPPER macro? Doesn't affect matching though.
            if (c1 >= 'a' && c1 <= 'z') {
                c1 -= 0x20;
            }

            c2 = *str2;
            if (c2 >= 'a' && c2 <= 'z') {
                c2 -= 0x20;
            }

            if (c1 < c2) {
                return -1;
            }
            if (c1 > c2) {
                return 1;
            }

            str1++;
            str2++;
            count--;

            if (*str1 == '\0' && *str2 == '\0') {
                break;
            }
        }
    }

    return 0;
}

u32 _strcspn(const u8 *str, const u8 *src) {
    u32 count;
    u8 ch;

    count = 0;
    while (*str & 0xFFU) {
        ch = *str & 0xFFU;
        if (_strchr(src, ch)) {
            return count;
        }
        str++;
        count++;
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002CE8.s")

u8 *_strpbrk(const u8 *dest, const u8 *breakset) {
    u8 *curr_match;
    u8 *earliest_match;
    u8 delimiter;

    earliest_match = _strchr(dest, *breakset);
    while (*breakset != '\0') {
        delimiter = *breakset++;
        curr_match = _strchr(dest, delimiter);
        if ((curr_match) && ((curr_match < earliest_match) || (!earliest_match))) {
            earliest_match = curr_match;
        }
    }
    return earliest_match;
}

u8 *_strtok(u8 *str, const u8 *delim) {
    static u8 *oldstr = NULL;

    u8 *token;

    if (str != NULL) {
        // New string to tokenize.
        oldstr = str;
    }

    token = oldstr;

    if (oldstr == NULL) {
        return NULL;
    }

    oldstr = _strpbrk(oldstr, delim);
    if (oldstr != NULL) {
        *oldstr++ = '\0';

        while (_strchr(delim, *oldstr) != NULL) {
            oldstr++;
        }
        return token;
    }

    return token;
}

void *memset(void *dest, s32 val, u32 len)
{
  u8 *ptr = dest;
  while (len-- > 0) {
    *ptr++ = val;
  }
  return dest;
}

u8 *_strchr(const u8 *str, s32 c) {
    if (str == NULL) {
        return NULL;
    }

    while(*str != '\0') {
        if ((u8)c == *str) {
            return (u8*)str; // cast to remove const. it's ok.
        }
        ++str;
    }
    return NULL;
}

u32 strlen(const u8 *str) {
    u32 len = 0;

    if (str == NULL) {
        return 0;
    }

    while(*str != '\0')
    {
        ++len;
        ++str;
    }
    return len;
}

u8 *_strstr(const u8 *str, const u8 *substr) {
    s32 i;
    s32 len;

    len = strlen(substr);
    i = 0;
    if ((!str) || (!substr)) {
        return NULL;
    }
    while ((i < len) && (*str)) {
        if (*(str + i) == substr[i]) {
            i += 1;
        } else {
            i = 0;
            str += 1;
        }
    }
    if (i != len) {
        str = NULL;
    }
    return (u8*)str;
}
