#include <ultra64.h>
#include "functions.h"

s32 func_jetpac_80027480(void) {
    return (s32) ((func_jetpac_80027210() * 200.0f) + 90.0f);
}

extern s32 D_jetpac_8002DC68[];
s32 func_jetpac_800274C0(void) {
    return D_jetpac_8002DC68[(s32)(func_jetpac_80027210() * 13.0f) % 13];
}

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
        return FALSE;
    }
    if (arg5 == 0) {
        var_f12 += arg0->unk24;
        var_f14 += arg0->unk28;
    }
    if ((arg0->unk1C >= 2) && (func_jetpac_80027250(var_f12, var_f14, arg0->unk8 + arg0->unk2C, arg0->unkC + arg0->unk30, arg1, arg2, arg3, arg4) != 0)) {
        return TRUE;
    }
    return FALSE;
}

extern JetpacSpawningInfo D_jetpac_8002D1A0[6];
extern JetpacPickupStruct D_jetpac_8002DC9C;

void func_jetpac_800275F4(Competitor *arg0) {
    // Spawn Rocket Segments
    s32 i;
    JetpacPickupStruct sp38;
    s32 j;

    sp38 = D_jetpac_8002DC9C;
    for (i = 0; i < 3; i++) {
        arg0->rocket_segments[i] = sp38;
        for (j = 0; j < 2; j++) {
            arg0->rocket_segments[i].primary_info.sprite[j] = &D_jetpac_8002D1A0[(2 * i) + j];
        }
    }
    func_jetpac_80028B54(arg0);
    arg0->rocket_stage = 0;
    arg0->rocket_segments[2].primary_info.posX = 168.0f;
    arg0->rocket_segments[2].primary_info.posY = 168.0f;
    arg0->rocket_segments[0].primary_info.posX = 48.0f;
    arg0->rocket_segments[0].primary_info.posY = 56.0f;
    arg0->rocket_segments[1].primary_info.posX = 128.0f;
    arg0->rocket_segments[1].primary_info.posY = 80.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027728.s")

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027BE8.s")

typedef struct JetpacStruct8002DCE8 { // P sure this is RGBA
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} JetpacStruct8002DCE8;

void func_jetpac_80025700(void*, s32, s32, void*, s32);
extern s32 D_8002F3C0;
extern JetpacStruct8002DCE8 D_jetpac_8002DCE8;
extern JetpacPlayerStruct D_jetpac_8002EC30;

/*
void func_jetpac_80027BE8(JetpacPickupStruct *arg0, s32 arg1) {
    JetpacStruct8002DCE8 sp58;
    JetpacPickupStruct *var_s1;
    s32 temp_a0;
    s32 temp_s6;
    s32 temp_v0;
    s32 i;
    s32 var_s2;
    Competitor *temp_s7;

    sp58 = D_jetpac_8002DCE8;
    temp_s7 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (arg0->primary_info.unk1C < 2) {
        return;
    }
    temp_s6 = arg0->primary_info.posX;
    var_s2 = func_jetpac_80027410(arg0->primary_info.posY);
    if (arg1 < 3) {
        for (i = 0; i < 2; i++) {
            temp_v0 = temp_s7->rocket_stage;
            if ((
                    (temp_v0 < 8) && 
                    ((temp_v0 + (arg1 * 2) + i) >= 8)
                ) || (
                    (temp_v0 == 8) &&
                    (D_8002F3C0 & 0x10)
                )) {
                sp58.green = 0;
            }
            temp_a0 = var_s1->primary_info.sprite[i];
            if (temp_a0) {
                func_jetpac_80025700(
                    temp_a0,
                    temp_s6,
                    var_s2,
                    &sp58,
                    arg0->primary_info.unk20);
            }
            var_s2 += 8;
        }
        return;
    }
    func_jetpac_80025700(
        arg0->primary_info.sprite[0],
        temp_s6,
        var_s2,
        &arg0->primary_info.red,
        arg0->primary_info.unk20);
}
*/

extern u8 D_8002F3C8;
extern JetpacSpawningInfo D_jetpac_8002D968[7];
extern JetpacPickupStruct D_jetpac_8002DCEC;

void func_jetpac_80027D64(Competitor *arg0) {
    // Spawn Jetpac Bonus Item
    JetpacPickupStruct sp24;
    JetpacPickupStruct *temp_v1;
    s32 temp;

    sp24 = D_jetpac_8002DCEC;
    if ((D_8002F3C8) && (arg0->current_score >= 5000) && (isFlagSet(0x17B, 0U) == 0) && (isFlagSet(0x62, 2U) == 0)) {
        sp24.primary_info.drop_type = 6;
    } else {
        temp = 5;
        sp24.primary_info.drop_type = (s32)(func_jetpac_80027210() * temp) + 1;
    }
    temp_v1 = &arg0->next_bonus_item;
    sp24.primary_info.sprite[0] = &D_jetpac_8002D968[sp24.primary_info.drop_type];
    *temp_v1 = sp24;
    temp_v1->primary_info.posX = func_jetpac_800274C0();
    arg0->unk_144 = func_jetpac_80027480();
}

// Jumptable, close
// https://decomp.me/scratch/5Smwc
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027EC0.s")

extern s32 D_8002F06C;
extern s32 D_8002F070;
extern s32 D_8002F074;
extern f32 D_jetpac_8002F050;
extern f32 D_jetpac_8002F054;
extern s32 D_jetpac_8002F064;
extern s32 D_jetpac_8002F078;

/*
void func_jetpac_80027EC0(JetpacPickupStruct *arg0) {
    Competitor *player;
    f32 temp_f18;
    s32 temp_hi;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v1;
    s32 var_v1_2;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (!player->rocket_stage) {
        return;
    }
    if (arg0->counter < player->unk_144) {
        arg0->counter++;
        return;
    }
    if (arg0->unk1C == 1) {
        arg0->unk1C = 2;
    }
    if (!arg0->unk38) {
        temp_f18 = arg0->velY;
        if (temp_f18 > 0.0f) {
            temp_v0_2 = func_jetpac_80028CF8(
                arg0->unk24 + arg0->posX + arg0->velX,
                arg0->unk28 + arg0->posY + temp_f18,
                arg0->unk2C + arg0->posX + arg0->velX,
                arg0->unk30 + arg0->posY + temp_f18,
                0);
            if (temp_v0_2 >= 0) {
                arg0->posY = D_jetpac_8002EC30.unk350[temp_v0_2].unk4 - 16.0f;
                arg0->velY = 0.0f;
            } else {
                arg0->posY += arg0->velY;
            }
        }
        if ((D_jetpac_8002EC30.unk78C == 2) && (D_jetpac_8002F064 == 3)) {
            if (func_jetpac_80027250( 
                arg0->posX + arg0->unk24, 
                arg0->posY + arg0->unk28,
                arg0->posX + arg0->unk2C,
                arg0->posY + arg0->unk30,
                D_8002F06C + D_jetpac_8002F050,
                D_8002F070 + D_jetpac_8002F054,
                D_8002F074 + D_jetpac_8002F050,
                D_jetpac_8002F078 + D_jetpac_8002F054)) {
                if (arg0->drop_type == 6) {
                    setFlag(0x62, TRUE, FLAG_TYPE_TEMPORARY);
                }
                player->current_score += arg0->point_bonus;
                func_jetpac_80024E70(3);
                func_jetpac_80027D64(player);
                return;
            }
        }
    }
    switch (arg0->drop_type) {
        case 6:
            arg0->counter++;
            temp_v0_3 = (arg0->counter - player->unk_144);
            if (temp_v0_3 >= 0x97) {
                func_jetpac_80027D64(player);
                return;
            }
            temp_hi = temp_v0_3 % 24;
            if (temp_hi < 0xC) {
                arg0->blue = 0xFF;
                arg0->red = 0;
                arg0->green = 0;
                return;
            }
            if (temp_hi < 0x18) {
                arg0->red = 0xFF;
                arg0->green = 0xFF;
                arg0->blue = 0;
                return;
            }
            break;
        case 1:
            arg0->counter++;
            var_v1 = arg0->counter - player->unk_144;
            if (var_v1 >= 0x1C) {
                var_v1 -= 0x1C;
                arg0->counter = player->unk_144;
            }
            if (var_v1 < 0x1C) {
                var_v1 = (var_v1 / 4) + 1;
                if (var_v1 & 1) {
                    arg0->blue = 0xFF;
                } else {
                    arg0->blue = 0;
                }
                if (var_v1 & 2) {
                    arg0->red = 0xFF;
                } else {
                    arg0->red = 0;
                }
                if (var_v1 & 4) {
                    arg0->green = 0xFF;
                    return;
                }
                arg0->green = 0;
                return;
            }
            break;
        case 2:
            arg0->red = 0xFF;
            arg0->green = 0xFF;
            arg0->blue = 0;
            return;
        case 5:
            arg0->green = 0xFF;
            arg0->red = 0;
            arg0->blue = 0;
            return;
        case 3:
        case 4:
            arg0->counter++;
            var_v1_2 = arg0->counter - player->unk_144;
            if (var_v1_2 >= 0x18) {
                var_v1_2 -= 0x18;
                arg0->counter = player->unk_144;
            }
            if (var_v1_2 < 0xC) {
                arg0->red = 0;
                arg0->green = 0;
                arg0->blue = 0;
                return;
            }
            if (var_v1_2 < 0x18) {
                arg0->red = 0;
                arg0->green = 0xFF;
                arg0->blue = 0xFF;
            }
            break;
        default:
            break;
    }
}
*/

extern JetpacPickupStruct D_jetpac_8002DD38;

void func_jetpac_80028340(Competitor *arg0) {
    JetpacPickupStruct sp1C;
    f32 sp24;

    sp1C = D_jetpac_8002DD38;
    sp1C.primary_info.posX = func_jetpac_800274C0();
    arg0->fuel_item = sp1C;
    arg0->unk10 = 3;
}

s32 func_jetpac_800283EC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Competitor *player;
    JetpacPickupStruct *rocket;
    s32 i;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (player->rocket_stage < 2) {
        rocket = player->rocket_segments;
        for (i = 0; i < (2 - player->rocket_stage); i++) {
            if (func_jetpac_80027510(rocket, arg0, arg1, arg2, arg3, 1)) {
                return TRUE;
            }
            rocket++;
        }
    }
    if (func_jetpac_80027510(&player->fuel_item, arg0, arg1, arg2, arg3, 0)) {
        return TRUE;
    }
    if (func_jetpac_80027510(&player->next_bonus_item, arg0, arg1, arg2, arg3, 0)) {
        return TRUE;
    }
    return FALSE;
}

void func_jetpac_80028544(void) {
    void (*temp_v0)(void *, s32);
    s32 i;
    JetpacPickupStruct *var_s0;
    JetpacPlayerStruct* player;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    var_s0 = &player->unk14;
    for (i = 0; i < 4; i++) {
        if (var_s0->primary_info.unk1C >= 2) {
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
    player->next_bonus_item.code(&player->next_bonus_item,5);
}

void func_jetpac_80028634(void) {
    s32 i;
    Competitor *temp_v0;
    JetpacPickupStruct *temp;

    temp_v0 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    temp = temp_v0->rocket_segments;
    temp_v0->rocket_stage = 8;
    for (i = 0; i < 3; i++, temp++) {
        temp->primary_info.posX = 168.0f;
        temp->primary_info.posY = (i * 16) + 136.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800286D0.s")

/*
extern s32 D_global_asm_80770DF8[];

void func_jetpac_800286D0(void) {
  
    JetpacPickupStruct *sp28;
    f32 sp24;
    f32 sp1C;
    JetpacPickupStruct *var_a2;
    f32 temp_f0;
    f32 var_f0;
    f32 var_f12;
    f32 var_f18;
    f32 var_f2;
    s32 temp_f16;
    s32 var_v0;
    s32 var_v1;
    Competitor *player;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    var_f12 = player->rocket_segments[0].primary_info.posY;
    var_f2 = 0.0f;
    var_a2 = player->rocket_segments;
    temp_f0 = (var_f12 - -8.0f) / 144.0f;
    if (temp_f0 < 0.0f) {

    } else if (temp_f0 > 1.0f) {
        var_f2 = 1.0f;
    } else {
        var_f2 = temp_f0;
    }
    if (D_jetpac_8002EC30.unk78C == 1) {
        if (!D_global_asm_80770DF8[1]) {
            sp28 = var_a2;
            sp1C = var_f2;
            func_jetpac_80024E70(1);
        }
        sp28 = var_a2;
        func_jetpac_80024F24(1, (1.0f - (var_f2 * 0.059466f)));
        var_f12 = var_a2->primary_info.posY;
        if (var_f12 >= 136.0f) {
            for (var_v0 = 0; var_v0 < 0x30; var_v0 += 0x10) {
                var_a2->primary_info.posX = 168.0f;
                var_a2->primary_info.posY = var_v0 + 136.0f;
                var_a2++;
            }
            func_jetpac_80024F64(1);
            func_jetpac_80024F9C(2);
            return;
        }
        sp24 = 0.4f;
    } else if (D_jetpac_8002EC30.unk78C == 4) {
        if (D_global_asm_80770DF8[0] == 0) {
            sp28 = var_a2;
            sp1C = var_f2;
            func_jetpac_80024E70(0);
        }
        sp28 = var_a2;
        func_jetpac_80024F24(0, (((1.0f - var_f2) * 0.059466f) + 1.0f));
        var_f12 = var_a2->primary_info.posY;
        if (var_f12 < -8.0f) {
            func_jetpac_80024F64(0);
            func_jetpac_800250A0();
            return;
        }
        sp24 = -0.4f;
    }
    var_f0 = var_f12 + sp24;
    for (var_v1 = 0; var_v1 < 3; var_v1++) {
        var_a2->primary_info.posY = var_f0;
        var_f0 += 16.0f;
        var_a2++;
    }
}
*/

void func_jetpac_80028950(void) {
    s32 i;
    Competitor *temp_v0;
    JetpacPickupStruct *var_v1;

    temp_v0 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    var_v1 = &temp_v0->rocket_segments[0];
    temp_v0->rocket_stage = 2;
    for (i = 0; i < 3; i++, var_v1++) {
        var_v1->primary_info.posX = 168.0f;
        var_v1->primary_info.posY = (i * 16) + -8.0f;
    }
}

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_800289EC.s")

typedef struct {
    void* unk0;
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
    s32 pad[6];
    s32* sp44;
    f32 rocket_base_y;
    s32 i;
    s32 var_v1;
    Competitor *player;
    JetpacPickupStruct *rocket_segment;
    s32 player_index;

    player_index = D_jetpac_8002EC30.player_index; \
    *sp44 = D_jetpac_8002DD88;
    player = &D_jetpac_8002EC30.player[player_index];
    rocket_base_y = player->rocket_segments[0].primary_info.posY;
    rocket_segment = &player->rocket_segments[0];
    if (rocket_base_y < 116.0f) {
        var_v1 = ABS(((s32) rocket_base_y / 3) % 2);
        func_jetpac_80025700(
            &D_jetpac_8002DC38[var_v1], 
            rocket_segment->primary_info.posX, 
            rocket_base_y + 48.0f + 4.0f, 
            sp44,
            0);
    }
    for (i = 0; i < 3; i++) {
        rocket_segment->code(rocket_segment, i);
        rocket_segment++;
    }
}
*/

extern s32 D_jetpac_8002D190[];

void func_jetpac_80028B54(Competitor *arg0) {
    s32 i;
    s32 temp = arg0->level / 4;
    for (i = 0; i < 6; i++) {
        D_jetpac_8002D1A0[i].sprite = D_jetpac_8002D190[temp % 4];
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