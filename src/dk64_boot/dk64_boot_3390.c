#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_800028E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_800029EC.s")

u8 *strcpy(u8 *dest, u8 const *src) {
    u8 *const ptr = dest;
    while ((*dest++ = *src++) != '\0');
    return ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002CE8.s")

u8 *func_dk64_boot_80002D60(u8 *str, u8 *ptr) {
    u8 *temp_v0;
    u8 *var_s1;
    u8 character;

    var_s1 = strchr(str, *ptr);
    while (*ptr) {
        character = *ptr++;
        temp_v0 = strchr(str, character);
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

u8 *strchr(const u8 *str, s32 c) {
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


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3390/func_dk64_boot_80002F54.s")
