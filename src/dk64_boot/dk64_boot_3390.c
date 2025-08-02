#include "common.h"

// .data
s32 D_dk64_boot_8000EEF0 = 0;

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_800028E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_800029EC.s")

u8 *_strcpy(u8 *dest, const u8 *src) {
    u8 *ptr = dest;
    while ((*dest++ = *src++) != '\0');
    return ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002A64.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002BB8.s")

s32 func_dk64_boot_80002C74(u8 *str, u8 *arg1) {
    s32 var_s1;
    u8 character;

    var_s1 = 0;
    while (*str & 0xFF) {
        character = *str & 0xFF;
        if (_strchr(arg1, character)) {
            return var_s1;
        }
        str++;
        var_s1++;
    }
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002CE8.s")

u8 *func_dk64_boot_80002D60(u8 *str, u8 *ptr) {
    u8 *temp_v0;
    u8 *var_s1;
    u8 character;

    var_s1 = _strchr(str, *ptr);
    while (*ptr) {
        character = *ptr++;
        temp_v0 = _strchr(str, character);
        if ((temp_v0) && ((temp_v0 < var_s1) || (!var_s1))) {
            var_s1 = temp_v0;
        }
    }
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002DE4.s")

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
