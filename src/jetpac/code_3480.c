#include <ultra64.h>
#include "functions.h"


f32 func_jetpac_80027210();

s32 func_jetpac_80027480(void) {
    return (s32) ((func_jetpac_80027210() * 200.0f) + 90.0f);
}

extern s32 D_jetpac_8002DC68[];
f32 func_jetpac_80027210();
s32 func_jetpac_800274C0(void) {
    return D_jetpac_8002DC68[(s32)(func_jetpac_80027210() * 13.0f) % 13];
}

s32 func_jetpac_80027250(f32, f32, f32, f32, f32, f32, f32, f32);

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
    s32 unk40;
    s32 unk44;
    s32 unk48;
} Struct80027510;

s32 func_jetpac_80027510(Struct80027510 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
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
    if ((arg0->unk1C >= 2) && (func_jetpac_80027250(var_f12, var_f14, arg0->unk8 + arg0->unk2C, arg0->unkC + arg0->unk30, arg1, arg2, arg3, arg4) != 0)) {
        return 1;
    }
    return 0;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800275F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027D64.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027EC0.s")

s32 func_jetpac_800274C0();
extern CompetitorSub14 D_jetpac_8002DD38;

void func_jetpac_80028340(Competitor *arg0) {
    CompetitorSub14 sp1C;
    f32 sp24;

    sp1C = D_jetpac_8002DD38;
    sp1C.unk8 = func_jetpac_800274C0();
    arg0->unk14[3] = sp1C;
    arg0->unk10 = 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800283EC.s")

/*
Weird struct stuff surrounding Jetpac Player Struct
extern JetpacPlayerStruct D_jetpac_8002EC30;

s32 func_jetpac_800283EC(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    s32 temp_v0;
    s32 var_s1;
    u8 *temp_s3;
    u8 *temp_s3_2;
    u8 *var_s0;

    temp_s3 = &D_jetpac_8002EC30 + (D_jetpac_8002EC30.player_index * 0x194);
    temp_v0 = *(s32*)(&temp_s3 + 0x28);
    temp_s3_2 = *(s32*)(&temp_s3 + 0x1C);
    if (temp_v0 < 2) {
        var_s0 = temp_s3_2 + 0x14;
        var_s1 = 0;
        if ((2 - temp_v0) > 0) {
loop_2:
            if (func_jetpac_80027510((Struct80027510*)&var_s0, arg0, arg1, arg2, arg3, 1) != 0) {
                return 1;
            }
            var_s1 += 1;
            var_s0 += 0x4C;
            if (var_s1 >= (2 - *(s32*)(&temp_s3_2 + 0xC))) {
                goto block_5;
            }
            goto loop_2;
        }
    }
block_5:
    if (func_jetpac_80027510((Struct80027510*)(&temp_s3_2 + 0xF8), arg0, arg1, arg2, arg3, 0) != 0) {
        return 1;
    }
    if (func_jetpac_80027510((Struct80027510*)(&temp_s3_2 + 0x148), arg0, arg1, arg2, arg3, 0) != 0) {
        return 1;
    }
    return 0;
}
*/

extern JetpacPlayerStruct D_jetpac_8002EC30;

void func_jetpac_80028544(void) {
    void (*temp_v0)(void *, s32);
    s32 i;
    CompetitorSub14 *var_s0;
    JetpacPlayerStruct* player;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    var_s0 = &player->unk14;
    for (i = 0; i < 4; i++) {
        if (var_s0->unk1C >= 2) {
            temp_v0 = var_s0->code;
            if (temp_v0 != NULL) {
                temp_v0(var_s0, i);
            }
        }
        var_s0++;
    }
}

void func_jetpac_800285DC(void) {
    Competitor *player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    player->fun_ptr2(&player->next_item_pointer,5);
}

void func_jetpac_80028634(void) {
    s32 i;
    Competitor *temp_v0;
    CompetitorSub14 *temp;

    temp_v0 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    temp = temp_v0->unk14;
    temp_v0->lives_consumed = 8;
    for (i = 0; i < 3; i++, temp++) {
        temp->unk8 = 168.0f;
        temp->unkC = (i * 16) + 136.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800286D0.s")

void func_jetpac_80028950(void) {
    s32 i;
    Competitor *temp_v0;
    CompetitorSub14 *var_v1;

    temp_v0 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    var_v1 = &temp_v0->unk14[0].unk0;
    temp_v0->lives_consumed = 2;
    for (i = 0; i < 3; i++, var_v1++) {
        var_v1->unk8 = 168.0f;
        var_v1->unkC = (i * 16) + -8.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800289EC.s")

extern s32 D_jetpac_8002D190[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct8002D1A0;

extern Struct8002D1A0 D_jetpac_8002D1A0[];

void func_jetpac_80028B54(s32 *arg0) {
    s32 i;
    s32 temp = *arg0 / 4;
    for (i = 0; i < 6; i++) {
        D_jetpac_8002D1A0[i].unk0 = D_jetpac_8002D190[temp % 4];
    }    
}

typedef struct Struct8002EF80 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} Struct8002EF80;

void func_jetpac_80028BD0(Struct8002EF80*, s32, s32, s32, u8, u8, u8); 

void func_jetpac_80028BD0(Struct8002EF80 *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6) {
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

extern Struct8002EF80 D_jetpac_8002EF80[4];

void func_jetpac_80028C3C(void) {
    func_jetpac_80028BD0(&D_jetpac_8002EF80[0], 0xC0, 0x30, 4, 0, 0xBE, 0);
    func_jetpac_80028BD0(&D_jetpac_8002EF80[1], 0x20, 0x48, 4, 0, 0xBE, 0);
    func_jetpac_80028BD0(&D_jetpac_8002EF80[2], 0x78, 0x60, 2, 0, 0xBE, 0);
    func_jetpac_80028BD0(&D_jetpac_8002EF80[3], 0, 0xB8, 0x1E, 0xBE, 0xBE, 0);
}

s32 func_jetpac_80028CF8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 var_f0;
    s32 i;
    Struct8002EF80 *var_s0;

    var_s0 = &D_jetpac_8002EF80;
    for (i = 0; i < 4; i++) {
        var_f0 = var_s0->unk28;
        if (arg4 == 0) {
            var_f0 -= 4.0f;
        }
        if (func_jetpac_80027250(arg0, arg1, arg2, arg3, var_s0->unk1C, var_s0->unk20, var_s0->unk24, var_f0)) {
            return i;
        }
        var_s0++;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80028E04.s")

/*
// TODO: Hmm, is D_jetpac_8002EC30 an array?
s32 func_jetpac_80028E04(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    JetpacPlayerStruct *temp_v0;

    temp_v0 = &D_jetpac_8002EC30[arg0];
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

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80028E88.s")
