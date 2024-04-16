#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3D20/func_dk64_boot_80003120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3D20/sprintf.s")

/*
int sprintf(char *str, const char *format, ...) {
    func_dk64_boot_8000320C(str, format);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3D20/func_dk64_boot_8000320C.s")
