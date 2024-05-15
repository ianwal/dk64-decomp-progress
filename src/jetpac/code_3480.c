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

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027BE8.s")

void func_jetpac_80025700(void*, s32, s32, void*, s32);
f32 func_jetpac_80027410(f32);
extern s32 D_8002F3C0;
extern s32 D_jetpac_8002DCE8;

extern JetpacPlayerStruct D_jetpac_8002EC30;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Struct80027BE8_arg0;

/*
void func_jetpac_80027BE8(Struct80027BE8_arg0 *arg0, s32 arg1) {
    s32 sp58;
    Competitor *temp_s7;
    s32 *var_s1;
    s32 temp_a0;
    s32 temp_s6;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s2;

    sp58 = D_jetpac_8002DCE8;
    temp_s7 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (arg0->unk1C >= 2) {
        temp_s6 = arg0->unk8;
        var_s0 = 0;
        var_s2 = func_jetpac_80027410(arg0->unkC);
        if (arg1 < 3) {
            var_s1 = arg0;
            do {
                temp_v0 = temp_s7->lives_consumed;
                if (((temp_v0 < 8) && ((temp_v0 + (arg1 * 2) + var_s0) >= 8)) || ((temp_v0 == 8) && (D_8002F3C0 & 0x10))) {
                    sp58 = 0;
                }
                temp_a0 = *var_s1;
                if (temp_a0 != 0) {
                    func_jetpac_80025700(temp_a0, temp_s6, var_s2, &sp58, arg0->unk20);
                }
                var_s0 += 1;
                var_s1++;
                var_s2 += 8;
            } while (var_s0 != 2);
            return;
        }
        func_jetpac_80025700(arg0->unk0, temp_s6, var_s2, &arg0->unk18, arg0->unk20);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027D64.s")

/*
typedef struct JetpacItemData {
    void* image;
    u8 pad[0x14];
} JetpacItemData;

f32 func_jetpac_80027210();                        
s32 func_jetpac_80027480();                        
s32 func_jetpac_800274C0();                        
extern u8 D_8002F3C8;
extern JetpacItemData D_jetpac_8002D968[7];
extern f32 D_jetpac_8002DCEC;

void func_jetpac_80027D64(Competitor *arg0) {
    s32 sp64;
    s32 *sp24;
    void *sp18;
    s32 *temp_v1;
    s32 i;

    for (i = 0; i < 0x13; i++) {
        *(s32*)(&sp24 + i) = *(s32*)(&D_jetpac_8002DCEC + i);
    }
    if ((D_8002F3C8 != 0) && (arg0->current_score >= 0x1388) && (isFlagSet(0x17B, 0U) == 0) && (isFlagSet(0x62, 2U) == 0)) {
        sp64 = 6;
    } else {
        sp64 = (s32) (func_jetpac_80027210() * (f32) 5) + 1;
    }
    temp_v1 = &arg0->next_item_pointer;
    sp24 = (sp64 * 0x18) + &D_jetpac_8002D968;
    for (i = 0; i < 0x12; i++) {
        *(s32*)(temp_v1 + i) = *(s32*)(&sp24 + i);
    }
    *(temp_v1 + 0x12) = *(&sp24 + 0x12);
    sp18 = temp_v1;
    *(f32 *)(temp_v1 + 2) = (f32) func_jetpac_800274C0();
    arg0->unk_144 = func_jetpac_80027480();
}
*/

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
// Weird struct stuff surrounding Jetpac Player Struct
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

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800289EC.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct8002DC38;

extern Struct8002DC38 D_jetpac_8002DC38[2];
extern s32 D_jetpac_8002DD88;

/*
void func_jetpac_800289EC(void) {
    s32 sp44;
    CompetitorSub14 *var_s1;
    s32 i;
    s32 var_v1;

    var_s1 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index].unk14;
    sp44 = D_jetpac_8002DD88;
    if (var_s1->unkC < 116.0f) {
        var_v1 = ABS(((s32)var_s1->unkC / 3) % 2);
        func_jetpac_80025700(&D_jetpac_8002DC38[var_v1], var_s1->unk8, var_s1->unkC + 48.0f + 4.0f, &sp44, 0);
    }
    for (i = 0; i < 3; i++) {
        var_s1[i].code(var_s1, i);
    }
}
*/

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

s32 func_jetpac_80028E04(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    JetpacPlayerSub36C *temp_v0;

    temp_v0 = &D_jetpac_8002EC30.unk350[arg0];
    if (arg1 < temp_v0->unk1C) {
        if (arg2 < temp_v0->unk1C) {
            return -2;
        }
        return -1;
    }
    temp_v1 = temp_v0->unk24;
    if (temp_v1 < arg2) {
        if (temp_v1 < arg1) {
            return 2;
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80028E88.s")

extern JetpacPlayerSub36C D_8002EF90[4];
extern JetpacPlayerSub36C D_jetpac_8002DE68;
extern JetpacPlayerSub36C D_jetpac_8002DE80;
extern JetpacPlayerSub36C D_jetpac_8002DE98;
extern JetpacPlayerStruct D_jetpac_8002EC30;
extern s32 D_jetpac_8002F060;

/*
void func_jetpac_80028E88(void) {
    s32 i, j;
    s32 temp_f10;
    s32 temp_f6;
    s32 var_s1;
    JetpacPlayerStruct *var_s6;
    JetpacPlayerSub36C * var_sub;

    var_s6 = &D_jetpac_8002EC30;
    for (i = 0; i < 4; i++) {
        var_sub = &var_s6->unk350[i];
        temp_f6 = var_sub->unk0;
        temp_f10 = var_sub->unk4;
        func_jetpac_80025700(&D_jetpac_8002DE68, temp_f6, temp_f10, var_sub->unk10, 0);
        var_s1 = temp_f6 + 8;
        for (j = 0; j < var_sub->unk30; j++) {
            func_jetpac_80025700(&D_jetpac_8002DE80, var_s1, temp_f10, var_sub->unk10, 0);
            var_s1 += 8;
        }
        func_jetpac_80025700(&D_jetpac_8002DE98, var_s1, temp_f10, var_sub->unk10, 0);
    }
}
*/