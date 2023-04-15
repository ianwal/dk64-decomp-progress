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

s32 func_80027250(f32, f32, f32, f32, f32, f32, f32, f32);

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8; // Used
    f32 unkC; // Used
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C; // Used
    s32 unk20;
    s32 unk24; // Used
    s32 unk28; // Used
    s32 unk2C; // Used
    s32 unk30; // Used
    s32 unk34;
    s32 unk38; // Used
    s32 unk3C;
} Struct80027510;

s32 func_80027510(Struct80027510 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    f32 var_f12;
    f32 var_f14;

    var_f12 = arg0->unk8;
    var_f14 = arg0->unkC;
    if (arg0->unk38 == 1) {
        return 0;
    }
    if (arg5 == 0) {
        var_f12 += arg0->unk24;
        var_f14 += arg0->unk28;
    }
    if ((arg0->unk1C >= 2) && (func_80027250(var_f12, var_f14, arg0->unk8 + arg0->unk2C, arg0->unkC + arg0->unk30, arg1, arg2, arg3, arg4) != 0)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_800275F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027D64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80027EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_800283EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028544.s")

extern JetpacPlayerStruct D_8002EC30;

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    void (*unk48)(void *, s32)
} Struct80028544;

/*

void func_80028544(void) {
    s32 i;
    Struct80028544 *var_s0;

    var_s0 = D_8002EC30.player[D_8002EC30.player_index].pad0;
    for (i = 0; i < 4; i++) {
        if (var_s0->unk1C >= 2) {
            if (var_s0->unk48 != NULL) {
                var_s0->unk48(var_s0, i);
            }
        }
        var_s0++;
    }
}
*/

void func_800285DC(void) {
    Competitor *player = &D_8002EC30.player[D_8002EC30.player_index];
    player->fun_ptr2(&player->next_item_pointer,5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028634.s")

/*
// TODO: Pretty close, not sure what's up with the last writes
void func_80028634(void) {
    Competitor *temp_v0;
    f32 var_f18;
    s32 temp_f16;
    s32 var_a1;
    Struct80028544 *var_v1;

    temp_v0 = &D_8002EC30.player[D_8002EC30.player_index];
    var_v1 = temp_v0->pad0;
    temp_v0->lives_consumed = 8;
    var_a1 = 0x0;
    for (var_a1 = 0x0; var_a1 < 0x30; var_a1 += 0x10) {
        var_v1->unk8 = 168.0f;
        var_v1->unkC = var_a1 + 136.0f;
        var_v1++;
    }
    var_v1[-1].unk8 = 168.0f;
    var_v1[-1].unkC = var_a1 + 136.0f;
}
*/

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

extern f32 D_8002EF80; // Mtx?
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

/*
// TODO: Hmm, is D_8002EC30 an array?
s32 func_80028E04(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    JetpacPlayerStruct *temp_v0;

    temp_v0 = &D_8002EC30[arg0];
    if (arg1 < temp_v0->unk36C) {
        if (arg2 < temp_v0->unk36C) {
            return -2;
        }
        return -1;
    }
    temp_v1 = temp_v0->unk374;
    if (temp_v1 < arg2) {
        if (temp_v1 < arg1) {
            return 2;
        }
        return 1;
    }
    return 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_80028E88.s")
