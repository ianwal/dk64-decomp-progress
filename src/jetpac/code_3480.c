#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_80027210();

s32 func_80027480(void) {
    return (s32) ((func_80027210() * 200.0f) + 90.0f);
}

extern s32 D_8002DC68[];
f32 func_80027210();
s32 func_800274C0(void) {
    return D_8002DC68[(s32)(func_80027210() * 13.0f) % 13];
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_800275F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027D64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_800283EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028544.s")

extern JetpacPlayerStruct D_8002EC30;
void func_800285DC(void) {
    Competitor *player = &D_8002EC30.player[D_8002EC30.player_index];
    player->fun_ptr2(&player->next_item_pointer,5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_800286D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_800289EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028B54.s")

void func_80028BD0(JetpacStruct*, s32, s32, s32, u8, u8, u8); 

void func_80028BD0(JetpacStruct *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6) {
    arg0->unk30 = arg3;
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk8 = 0.0f;
    arg0->unkC = 0.0f;
    arg0->unk10 = arg4;
    arg0->unk11 = arg5;
    arg0->unk12 = arg6;
    arg0->unk13 = 0xFF;
    arg0->unk20 = arg2;
    arg0->unk1C = arg1;
    // TODO: Why does this need to be on the same line? Just ido being shite?
    arg0->unk24 = arg3 * 8 + arg1 + 0x10; arg0->unk28 = arg2 + 0xC;
}

extern f32 D_8002EF80;
extern f32 D_8002EFB4;
extern f32 D_8002EFE8;
extern f32 D_8002F01C;

void func_80028C3C(void) {
    func_80028BD0(&D_8002EF80, 0xC0, 0x30, 4, 0, 0xBE, 0);
    func_80028BD0(&D_8002EFB4, 0x20, 0x48, 4, 0, 0xBE, 0);
    func_80028BD0(&D_8002EFE8, 0x78, 0x60, 2, 0, 0xBE, 0);
    func_80028BD0(&D_8002F01C, 0, 0xB8, 0x1E, 0xBE, 0xBE, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028E88.s")
