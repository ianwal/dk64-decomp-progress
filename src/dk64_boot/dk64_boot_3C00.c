#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/dk64_boot/dk64_boot_3C00/memcpy.s")

/*
void *memcpy(u32 dest, u32 src, u32 n)
{
    void* _dest = dest;
    if (n != 0)
    {
        if ((((n | 7) ^ 7) != n) || (((dest | 7) ^ 7) != dest) || (((src | 7) ^ 7) != src))
        {
            if ((((n | 3) ^ 3) != n) || (((dest | 3) ^ 3) != dest) || (((src | 3) ^ 3) != src))
            {
                if ((((n | 1) ^ 1) != n) || (((dest | 1) ^ 1) != dest) || (((src | 1) ^ 1) != src))
                {
                    while(n > 0) {
                        *((u8 *)dest)++ = *((u8 *)src)++;
                        n--;
                    }
                } else {
                    while(n > 0) {
                        *((u16 *)dest)++ = *((u16 *)src)++;
                        n -= sizeof(u16);
                    }
                }
            } else {
                while(n > 0) {
                    *((u32 *)dest)++ = *((u32 *)src)++;
                    n -= sizeof(u32);
                }
            }
        } else {
            while(n > 0) {
                *((u64 *)dest)++ = *((u64 *)src)++;
                n -= sizeof(u64);
            }
        }
    }
    return _dest;
}
*/