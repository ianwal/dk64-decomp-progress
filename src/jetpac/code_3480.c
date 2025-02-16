#include <ultra64.h>
#include "functions.h"

s32 func_jetpac_80027480(void) {
    return (s32) ((func_jetpac_80027210() * 200.0f) + 90.0f);
}

extern s32 D_jetpac_8002DC68[];
s32 func_jetpac_800274C0(void) {
    return D_jetpac_8002DC68[(s32)(func_jetpac_80027210() * 13.0f) % 13];
}

s32 func_jetpac_80027510(JetpacPickupStruct *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    f32 var_f12;
    f32 var_f14;

    var_f12 = arg0->primary_info.posX;
    var_f14 = arg0->primary_info.posY;
    if (arg0->primary_info.unk38 == 1) {
        return FALSE;
    }
    if (arg5 == 0) {
        var_f12 += arg0->primary_info.unk24.left;
        var_f14 += arg0->primary_info.unk24.top;
    }
    if ((arg0->primary_info.unk1C >= 2) && (func_jetpac_80027250(var_f12, var_f14, arg0->primary_info.posX + arg0->primary_info.unk24.right, arg0->primary_info.posY + arg0->primary_info.unk24.bottom, arg1, arg2, arg3, arg4) != 0)) {
        return TRUE;
    }
    return FALSE;
}

extern uSprite D_jetpac_8002D1A0[6];
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

extern JetpacGameStruct D_jetpac_8002EC30;
extern JetpacPlayerStruct D_jetpac_8002F050;

void func_jetpac_80027728(JetpacPickupStruct* arg0) {
    Competitor* player;
    f32 temp_f0_3;
    s32 temp_v0_2;
    JetpacPlayerStruct* ms;
    ms = &D_jetpac_8002F050;
    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if ((arg0->primary_info.unk1C != 0) && (player->rocket_stage < 8)) {
        if (arg0->primary_info.unk24.counter < 0x14) {
            arg0->primary_info.unk24.counter = arg0->primary_info.unk24.counter + 1;
            return;
        }
        if (arg0->primary_info.unk1C == 1) {
            arg0->primary_info.unk1C = 2;
        }
        if (arg0->primary_info.unk38 == 0) {
            if ((arg0->primary_info.velY > 0.0f) && (ms->spatial_state.entity_state != JETPAC_ENTITY_STATE_DYING)) {
                temp_v0_2 = func_jetpac_80028CF8(
                    (f32) arg0->primary_info.unk24.left + arg0->primary_info.posX + arg0->primary_info.velX,
                    (f32) arg0->primary_info.unk24.top + arg0->primary_info.posY + arg0->primary_info.velY,
                    (f32) arg0->primary_info.unk24.right + arg0->primary_info.posX + arg0->primary_info.velX,
                    (f32) arg0->primary_info.unk24.bottom + arg0->primary_info.posY + arg0->primary_info.velY, 0);
                if (temp_v0_2 >= 0) {
                    arg0->primary_info.posY = D_jetpac_8002EC30.platforms[temp_v0_2].spatial_state.posY - 16.0f;
                    arg0->primary_info.velY = 0.0f;
                } else {
                    arg0->primary_info.posY = arg0->primary_info.posY + arg0->primary_info.velY;
                }
            }

            if (ms->spatial_state.entity_state == JETPAC_ENTITY_STATE_ACTIVE) {
                if (func_jetpac_80027250(
                    arg0->primary_info.posX + arg0->primary_info.unk24.left,
                    arg0->primary_info.posY + arg0->primary_info.unk24.top,
                    arg0->primary_info.posX + arg0->primary_info.unk24.right,
                    arg0->primary_info.posY + arg0->primary_info.unk24.bottom,
                    ms->spatial_state.posX + ms->spatial_state.unk1C.left,
                    ms->spatial_state.posY + ms->spatial_state.unk1C.top,
                    ms->spatial_state.posX + ms->spatial_state.unk1C.right,
                    ms->spatial_state.posY + ms->spatial_state.unk1C.bottom)) {
                    arg0->primary_info.unk38 = 1;
                    player->current_score += arg0->primary_info.point_bonus;
                    func_jetpac_80024E70(4);
                }
            }
        }
        if (arg0->primary_info.unk38 == 1) {
            if (ms->spatial_state.entity_state == JETPAC_ENTITY_STATE_DYING) {
                arg0->primary_info.unk38 = 0;
                arg0->primary_info.velY = 0.8f;
            } else {
                arg0->primary_info.posX =
                    ((ms->spatial_state.posX - (2 * ms->spatial_state.velX)) + ms->spatial_state.unk1C.left) +
                    ((((ms->spatial_state.unk1C.right - ms->spatial_state.unk1C.left) - arg0->primary_info.unk24.right) + arg0->primary_info.unk24.left) * 0.5);
                arg0->primary_info.posY = ((ms->spatial_state.posY - ms->spatial_state.velY) + ms->spatial_state.unk1C.bottom) - arg0->primary_info.unk24.bottom;
                if (func_jetpac_80027330(arg0->primary_info.posX) != 0) {
                    arg0->primary_info.posX = 168.0f;
                    arg0->primary_info.velY = 0.8f;
                    arg0->primary_info.unk38 = 2;
                }
            }
        }
        if (arg0->primary_info.unk38 == 2) {
            arg0->primary_info.posY += arg0->primary_info.velY;
            if (player->rocket_stage < 2) {
                temp_f0_3 = (152 - (player->rocket_stage * 16));
                if (temp_f0_3 <= arg0->primary_info.posY) {
                    arg0->primary_info.posY = temp_f0_3;
                    player->rocket_stage += 1;
                    func_jetpac_80024E70(2);
                    if (player->rocket_stage < 2) {
                        player->unk10 -= 1;
                        return;
                    }
                    func_jetpac_80028340(player);
                }
            } else if (arg0->primary_info.posY >= 168.0f) {
                player->rocket_stage = player->rocket_stage + 1;
                func_jetpac_80024E70(2);
                if (player->rocket_stage < 8) {
                    func_jetpac_80028340(player);
                    return;
                }
                arg0->primary_info.unk1C = 0;
            }
        }
    }
}

typedef struct JetpacStruct8002DCE8 { // P sure this is RGBA
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} JetpacStruct8002DCE8;

void func_jetpac_80025700(void*, s32, s32, rgba*, s32);
extern s32 D_8002F3C0[];
extern rgba D_jetpac_8002DCE8;
extern JetpacGameStruct D_jetpac_8002EC30;

void func_jetpac_80027BE8(JetpacPickupStruct* arg0, s32 arg1) {
    Competitor* player;
    s32 temp_s6;
    s32 var_s0;
    rgba sp58;
    s32 var_s2;
    s32* ptr;

    sp58 = D_jetpac_8002DCE8;
    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (arg0->primary_info.unk1C >= 2) {
        temp_s6 = arg0->primary_info.posX;
        var_s2 = func_jetpac_80027410(arg0->primary_info.posY);
        if (arg1 < 3) {
            for (var_s0 = 0; var_s0 < 2; var_s0++)
            {
                ptr = D_8002F3C0;
                if (((player->rocket_stage < 8) && ((player->rocket_stage + (arg1 * 2) + var_s0) >= 8)) || ((player->rocket_stage == 8) && (*ptr & 0x10))) {
                    sp58.green = 0;
                }
                if (arg0->primary_info.sprite[var_s0] != NULL) {
                    func_jetpac_80025700(arg0->primary_info.sprite[var_s0], temp_s6, var_s2, &sp58, arg0->primary_info.unk20);
                }
                var_s2 += 8;
            }
        }
        else
        {
            func_jetpac_80025700(arg0->primary_info.sprite[0], temp_s6, var_s2, &arg0->primary_info.color, arg0->primary_info.unk20);
        }
    }
}

extern u8 D_8002F3C8;
extern uSprite D_jetpac_8002D968[7];
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
    arg0->bonus_item_counter_limit = func_jetpac_80027480();
}

// Close...
// https://decomp.me/scratch/eraHv
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3480/func_jetpac_80027EC0.s")

/*
void func_jetpac_80027EC0(JetpacPickupStruct *arg0) {
    Competitor *competitor;
    s32 temp_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    JetpacPlayerStruct* player;
    
    player = &D_jetpac_8002F050;
    competitor = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (competitor->rocket_stage == 0) {
        return;
    }
    
    if (arg0->primary_info.unk24.counter < competitor->bonus_item_counter_limit) {
        arg0->primary_info.unk24.counter++;
        return;
    }
    
    if (arg0->primary_info.unk1C == 1) {
        arg0->primary_info.unk1C = 2;
    }
    
    if (arg0->primary_info.unk38 == 0) {
        if (arg0->primary_info.velY > 0.0f) {
            temp_v0_3 = func_jetpac_80028CF8(
                arg0->primary_info.unk24.left + arg0->primary_info.posX + arg0->primary_info.velX,
                arg0->primary_info.unk24.top + arg0->primary_info.posY + arg0->primary_info.velY,
                arg0->primary_info.unk24.right + arg0->primary_info.posX + arg0->primary_info.velX,
                arg0->primary_info.unk24.bottom + arg0->primary_info.posY + arg0->primary_info.velY, 0);
            if (temp_v0_3 >= 0) {
                arg0->primary_info.posY = D_jetpac_8002EC30.platforms[temp_v0_3].spatial_state.posY - 16.0f;
                arg0->primary_info.velY = 0.0f;
            } else {
                arg0->primary_info.posY += arg0->primary_info.velY;
            }
        }

        if ((D_jetpac_8002EC30.unk78C == 2) && (player->spatial_state.entity_state == 3)) {
            if (func_jetpac_80027250( 
                arg0->primary_info.posX + arg0->primary_info.unk24.left, 
                arg0->primary_info.posY + arg0->primary_info.unk24.top,
                arg0->primary_info.posX + arg0->primary_info.unk24.right,
                arg0->primary_info.posY + arg0->primary_info.unk24.bottom,
                player->spatial_state.posX + player->spatial_state.unk1C.left,
                player->spatial_state.posY + player->spatial_state.unk1C.top,
                player->spatial_state.posX + player->spatial_state.unk1C.right,
                player->spatial_state.posY + player->spatial_state.unk1C.bottom)) {
                if (arg0->primary_info.drop_type == 6) {
                    setFlag(0x62, TRUE, FLAG_TYPE_TEMPORARY);
                }
                competitor->current_score += arg0->primary_info.point_bonus;
                func_jetpac_80024E70(3);
                func_jetpac_80027D64(competitor);
                return;
            }
        }
    }
    switch (arg0->primary_info.drop_type) {
        case 6:
            arg0->primary_info.unk24.counter++;
            temp_v0_3 = (arg0->primary_info.unk24.counter - competitor->bonus_item_counter_limit);
            if (temp_v0_3 >= 0x97) {
                func_jetpac_80027D64(competitor);
            }
            else
            {
                temp_v0_3 %= 24;
                if (temp_v0_3 < 0xC) {
                    arg0->primary_info.color.blue = 0xFF;
                    arg0->primary_info.color.red = 0;
                    arg0->primary_info.color.green = 0;
                }
                else if (temp_v0_3 < 0x18) {
                    arg0->primary_info.color.red = 0xFF;
                    arg0->primary_info.color.green = 0xFF;
                    arg0->primary_info.color.blue = 0;
                }
            }
            break;
        case 1:
            arg0->primary_info.unk24.counter++;
            var_v1 = arg0->primary_info.unk24.counter - competitor->bonus_item_counter_limit;
            if (var_v1 >= 0x1C) {
                var_v1 -= 0x1C;
                arg0->primary_info.unk24.counter = competitor->bonus_item_counter_limit;
            }
            if (var_v1 < 0x1C) {
                var_v1 = (var_v1 / 4) + 1;
                arg0->primary_info.color.blue = (var_v1 & 1) ? 0xFF : 0;
                arg0->primary_info.color.red = (var_v1 & 2) ? 0xFF : 0;
                arg0->primary_info.color.green = (var_v1 & 4) ? 0xFF : 0;
            }
            break;
        case 2:
            arg0->primary_info.color.red = 0xFF;
            arg0->primary_info.color.green = 0xFF;
            arg0->primary_info.color.blue = 0;
            break;
        case 5:
            arg0->primary_info.color.green = 0xFF;
            arg0->primary_info.color.red = 0;
            arg0->primary_info.color.blue = 0;
            break;
        case 3:
        case 4:
            arg0->primary_info.unk24.counter++;
            var_v1_2 = arg0->primary_info.unk24.counter - competitor->bonus_item_counter_limit;
            if (var_v1_2 >= 0x18) {
                var_v1_2 -= 0x18;
                arg0->primary_info.unk24.counter = competitor->bonus_item_counter_limit;
            }
            if (var_v1_2 < 0xC) {
                arg0->primary_info.color.red = 0;
                arg0->primary_info.color.green = 0;
                arg0->primary_info.color.blue = 0;
            }
            else if (var_v1_2 < 0x18) {
                arg0->primary_info.color.red = 0;
                arg0->primary_info.color.green = 0xFF;
                arg0->primary_info.color.blue = 0xFF;
            }
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
    s32 i;
    JetpacPickupStruct *rocket_segment;
    Competitor* player;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    rocket_segment = &player->rocket_segments[0];
    for (i = 0; i < 4; i++) {
        if (rocket_segment->primary_info.unk1C >= 2) {
            if (rocket_segment->code != NULL) {
                rocket_segment->code(rocket_segment, i);
            }
        }
        rocket_segment++;
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

extern s32 D_global_asm_80770DF8;
extern s32 D_global_asm_80770DFC;

void func_jetpac_800286D0(void) {
    s32 pad;
    JetpacPickupStruct* sp28;
    f32 sp24;
    f32 temp_f0;
    f32 var_f2;
    f32 var_f3;
    s32 i;

    sp28 = D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index].rocket_segments;
    var_f2 = (sp28->primary_info.posY - -8.0f) / 144.0f;
    var_f2 = CLAMP(var_f2, 0.0f, 1.0f);
    if (D_jetpac_8002EC30.unk78C == 1) {
        if (D_global_asm_80770DFC == 0) {
            func_jetpac_80024E70(1);
        }
        var_f2 *= 0.059466f;
        var_f2 = 1.0f - var_f2;
        func_jetpac_80024F24(1, var_f2);
        
        if (sp28->primary_info.posY >= 136.0f) {
            for (i = 0; i < 3; i++, sp28++)
            {
                sp28->primary_info.posX = 168.0f;
                sp28->primary_info.posY = (i * 16) + 136.0f;
            }
            func_jetpac_80024F64(1);
            func_jetpac_80024F9C(2);
            return;
        }
        sp24 = 0.4f;
    }
    else if (D_jetpac_8002EC30.unk78C == 4) {
        if (D_global_asm_80770DF8 == 0) {
            func_jetpac_80024E70(0);
        }
        var_f2 = (1.0f - var_f2);
        var_f2 *= 0.059466f;
        var_f2 += 1.0f;
        func_jetpac_80024F24(0, var_f2);

        if (sp28->primary_info.posY < -8.0f) {
            func_jetpac_80024F64(0);
            func_jetpac_800250A0();
            return;
        }
        sp24 = -0.4f;
    }

    var_f3 = sp28->primary_info.posY + sp24;
    for (i = 0; i != 3; i++)
    {
        sp28->primary_info.posY = var_f3;
        var_f3 += 16.0f;
        sp28++;
    }
}

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

extern uSprite D_jetpac_8002DC38[2];
extern rgba D_jetpac_8002DD88;
void func_jetpac_80025700(void*, s32, s32, rgba*, s32);

void func_jetpac_800289EC(void) {
    Competitor* player;
    JetpacPickupStruct* rocket_segment;
    rgba rgba;
    f32 rocket_y;
    s32 i;

    rocket_segment = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index].rocket_segments[0];
    rgba = D_jetpac_8002DD88;
    if ((rocket_y = rocket_segment->primary_info.posY) < 116.0f)
    {
        uSprite* ptr = &D_jetpac_8002DC38[ABS(((s32)rocket_y / 3) % 2)];
        func_jetpac_80025700(ptr, rocket_segment->primary_info.posX, (rocket_y + 48.0f + 4.0f), &rgba, 0);
    }

    for (i = 0; i != 3; i++)
    {
        rocket_segment->code(rocket_segment, i);
        rocket_segment++;
    }
}

extern void* D_jetpac_8002D190[];

void func_jetpac_80028B54(Competitor *arg0) {
    s32 i;
    s32 temp = arg0->level / 4;
    for (i = 0; i < 6; i++) {
        D_jetpac_8002D1A0[i].s.SourceImagePointer = D_jetpac_8002D190[temp % 4];
    }    
}

void func_jetpac_80028BD0(JetpacGroundPlatform *ground_platform, s32 posX, s32 posY, s32 width, u8 red, u8 green, u8 blue) {
    ground_platform->unk30 = width;
    ground_platform->spatial_state.posX = posX;
    ground_platform->spatial_state.posY = posY;
    ground_platform->spatial_state.velX = 0.0f;
    ground_platform->spatial_state.velY = 0.0f;
    ground_platform->spatial_state.color.red = red;
    ground_platform->spatial_state.color.green = green;
    ground_platform->spatial_state.color.blue = blue;
    ground_platform->spatial_state.color.alpha = 0xFF;
    ground_platform->spatial_state.unk1C.top = posY;
    ground_platform->spatial_state.unk1C.left = posX;
    // TODO: Why does this need to be on the same line? Just ido being shite?
    ground_platform->spatial_state.unk1C.right = width * 8 + posX + 0x10; ground_platform->spatial_state.unk1C.bottom = posY + 0xC;
}

void func_jetpac_80028C3C(void) {
    func_jetpac_80028BD0(&D_jetpac_8002EC30.platforms[0], 0xC0, 0x30, 4, 0, 0xBE, 0);
    func_jetpac_80028BD0(&D_jetpac_8002EC30.platforms[1], 0x20, 0x48, 4, 0, 0xBE, 0);
    func_jetpac_80028BD0(&D_jetpac_8002EC30.platforms[2], 0x78, 0x60, 2, 0, 0xBE, 0);
    func_jetpac_80028BD0(&D_jetpac_8002EC30.platforms[3], 0, 0xB8, 0x1E, 0xBE, 0xBE, 0);
}

s32 func_jetpac_80028CF8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 var_f0;
    s32 i;
    JetpacGroundPlatform *var_s0;

    var_s0 = &D_jetpac_8002EC30.platforms[0];
    for (i = 0; i < 4; i++) {
        var_f0 = var_s0->spatial_state.unk1C.bottom;
        if (arg4 == 0) {
            var_f0 -= 4.0f;
        }
        if (func_jetpac_80027250(arg0, arg1, arg2, arg3, var_s0->spatial_state.unk1C.left, var_s0->spatial_state.unk1C.top, var_s0->spatial_state.unk1C.right, var_f0)) {
            return i;
        }
        var_s0++;
    }
    return -1;
}

s32 func_jetpac_80028E04(s32 arg0, s32 left, s32 right) {
    s32 platform_right;
    JetpacSpatialState *temp_v0;

    temp_v0 = &D_jetpac_8002EC30.platforms[arg0].spatial_state;
    if (left < temp_v0->unk1C.left) {
        if (right < temp_v0->unk1C.left) {
            return -2;
        }
        return -1;
    }
    platform_right = temp_v0->unk1C.right;
    if (platform_right < right) {
        if (platform_right < left) {
            return 2;
        }
        return 1;
    }
    return 0;
}

extern uSprite D_jetpac_8002DE68;
extern uSprite D_jetpac_8002DE80;
extern uSprite D_jetpac_8002DE98;

void func_jetpac_80028E88(void) {
    JetpacGroundPlatform* platform;
    s32 y;
    s32 x;
    s32 i;
    s32 j;
    
    for (i = 0; i < 4; i++)
    {
        platform = &D_jetpac_8002EC30.platforms[i];
        x = platform->spatial_state.posX;
        y = platform->spatial_state.posY;
        func_jetpac_80025700(&D_jetpac_8002DE68, x, y, &platform->spatial_state.color, 0);
        x += 8;
        for (j = 0; j < platform->unk30; j++)
        {
            func_jetpac_80025700(&D_jetpac_8002DE80, x, y, &platform->spatial_state.color, 0);
            x += 8;
        }
        func_jetpac_80025700(&D_jetpac_8002DE98, x, y, &platform->spatial_state.color, 0);
    }
}
