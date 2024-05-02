#ifndef _MINECART_H_
#define _MINECART_H_

#include <ultra64.h>
#include "functions.h"


typedef struct {
    u8 unk0[0x10 - 0x0];
    u16 unk10;
    char unk12[0x1E];
    u8 *unk30;
    u8 *unk34;
    u8 unk38[0x42 - 0x38];
    u8 unk42;
} AAD_minecart_80027DA0;

extern s32 D_minecart_80028BD0;
extern s32 D_global_asm_8072030C;

void func_global_asm_8066E9EC(Actor*, s32, f32);
void func_minecart_80024E78(AAD_minecart_80027DA0*, void*, s32, s32);
void func_minecart_800253C0(AAD_minecart_80027DA0*, s16, u8);
void func_minecart_80027EE8(AAD_minecart_80027DA0* arg0);
void func_global_asm_8061F0B0(s32, s32, s32);
s32 func_global_asm_806131D4(Actor *, s16);
s16 func_global_asm_80613448(Actor *);

#endif
