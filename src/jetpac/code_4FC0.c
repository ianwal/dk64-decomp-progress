#include "common.h"

typedef struct JetpacStruct9 {
    u8 pad0[0x18];
} JetpacStruct9;

extern s32 D_jetpac_8002BA6C;
extern JetpacStruct9 D_jetpac_8002E800[];
extern s32 D_jetpac_8002E830;
extern void* D_jetpac_8002E878;
extern s32 D_jetpac_8002E890;
extern s32 D_jetpac_8002E8A8;
extern s32 D_jetpac_8002E8C0;
extern s32 D_jetpac_8002E8D8;
extern u8 D_jetpac_8002E9C0;
extern u8 D_jetpac_8002E9C4;
extern u8 D_jetpac_8002E9C8;
extern u8 D_jetpac_8002E9CC;

extern JetpacGameStruct D_jetpac_8002EC30;
extern s32 D_jetpac_8002E8F0;
extern JetpacPlayerStruct D_jetpac_8002F050; // TODO: Datatype
extern s32 D_jetpac_8002F064;
extern s32 D_jetpac_8002F07C;
extern s32 D_jetpac_8002F078;
extern JetpacStruct D_jetpac_8002F1DC[6];
extern s32 D_jetpac_8002F3BC;

extern u8 D_jetpac_80045BE0;
extern u8 D_jetpac_80045BE1;
extern u8 D_jetpac_80045BE2;
extern u8 D_jetpac_80045BE3;

void func_jetpac_80025700(uSprite*, s32, s32, rgba*, s32);
void func_jetpac_80025A60(void*);
void func_jetpac_80029640(JetpacStruct*, f32, f32);
void func_jetpac_80029B90(JetpacStruct *);
f32 func_jetpac_80027380(JetpacSpatialState *);
f32 func_jetpac_800273C8(JetpacStruct *);

void func_jetpac_80029F7C(JetpacStruct *arg0);
void *func_global_asm_806FD490(Gfx *, s32, s16 x, s16 y, char *string);

JetpacStruct *func_jetpac_80028FC0(void) {
    s32 i;
    JetpacStruct *temp = &D_jetpac_8002F1DC[0];
    for (i = 0; i < 6; i++) {
        if (temp->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_DEAD) {
            return temp;
        }
        temp++;
    }
    return NULL;
}

void func_jetpac_800291AC(JetpacStruct *arg0);

s32 func_jetpac_80029064(JetpacStruct* arg0) {
    JetpacPlayerStruct* ms;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 p3;
    f32 p4;
    f32 p5;
    f32 p6;
    f32 p7;
    s32 var_v1;

    ms = &D_jetpac_8002F050;
    var_v1 = 0;

    p0 = arg0->unk0.spatial_state.posX;
    p1 = arg0->unk0.spatial_state.posY;
    p2 = p0 + arg0->unk0.spatial_state.unk1C.right;
    p3 = p1 + arg0->unk0.spatial_state.unk1C.bottom;

    p5 = D_jetpac_8002EC30.unk420;
    p4 = D_jetpac_8002EC30.unk424;
    p6 = p5 + D_jetpac_8002EC30.unk444 - 2;
    p7 = p4 + D_jetpac_8002EC30.unk448;

    p0 += arg0->unk0.spatial_state.unk1C.left;
    p1 += arg0->unk0.spatial_state.unk1C.top;
    p5 += (D_jetpac_8002EC30.unk43C + 2);
    p4 += (D_jetpac_8002EC30.unk440 + 4);

    if (D_jetpac_8002EC30.unk434 == 3) {
        var_v1 = func_jetpac_80027250(
            p0,
            p1,
            p2,
            p3,
            p5,
            p4,
            p6,
            p7);
    }
    if (var_v1 != 0) {
        ms->spatial_state.entity_state = JETPAC_ENTITY_STATE_DYING;
        ms->spatial_state.unk1C.counter = 0;
        func_jetpac_80027010(ms, arg0);
        func_jetpac_800291AC(arg0);
    }
    return var_v1;
}

void func_jetpac_800291AC(JetpacStruct *arg0) {
    arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DYING;
    arg0->unk0.spatial_state.unk1C.counter = 0;
    arg0->unk0.explosion_sprite.frame_counter = 0;
    arg0->unk0.explosion_sprite.posX = (s32)arg0->unk0.spatial_state.posX & 0xFFF8;
    arg0->unk0.explosion_sprite.posY = (s32)arg0->unk0.spatial_state.posY & 0xFFF8;
    func_jetpac_80024E70(5);
}

void func_jetpac_80029204(JetpacStruct *arg0) {
    if (arg0->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_ACTIVE) {
        func_jetpac_80025700(arg0->unk48.unk4, arg0->unk0.spatial_state.posX, arg0->unk0.spatial_state.posY, &arg0->unk0.spatial_state.color, arg0->unk0.spatial_state.is_facing_left);
        return;
    }
    if (arg0->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_DYING) {
        func_jetpac_80025A60(&arg0->unk0.explosion_sprite);
        if (arg0->unk0.explosion_sprite.frame_counter < 7) {
            func_jetpac_80025700(arg0->unk48.unk4, arg0->unk0.spatial_state.posX, arg0->unk0.spatial_state.posY, &arg0->unk0.spatial_state.color, arg0->unk0.spatial_state.is_facing_left);
        }
    }
}

extern JetpacStruct D_jetpac_8002E914[2];

JetpacStruct *func_jetpac_800292C4(void) {
    JetpacStruct *temp;
    JetpacStruct *sp70;
    JetpacStruct sp20;

    sp70 = func_jetpac_80028FC0();
    temp = &sp20;
    sp20 = D_jetpac_8002E914[0];
    if (!sp70) {
        return NULL;
    }
    *sp70 = sp20;
    sp70->unk0.spatial_state.posX = 0.0f;
    sp70->unk0.spatial_state.posY = (((s32) (func_jetpac_80027210() * 15.0f) % 15) * 8) + 0x20;
    switch ((s32) (func_jetpac_80027210() * 4.0f) % 4) {
        case 0:
            sp70->unk0.spatial_state.color.red = 0;
            break;
        case 1:
            sp70->unk0.spatial_state.color.green = 0;
            break;
        case 2:
            sp70->unk0.spatial_state.color.red = 0;
            sp70->unk0.spatial_state.color.blue = 0;
            break;
        case 3:
            sp70->unk0.spatial_state.color.green = 0;
            sp70->unk0.spatial_state.color.blue = 0;
            break;
        }
    return sp70;
}

extern void* D_jetpac_8002E8F4[8];
extern JetpacGameStruct D_jetpac_8002EC30;

void func_jetpac_80029450(void) {
    JetpacStruct *sp18;
    Competitor * player;
    void (*sp1C)(JetpacStruct *);
    JetpacStruct *temp_v0;
    s32 level;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    level = player->level % 8;
    sp1C = D_jetpac_8002E8F4[level];
    temp_v0 = func_jetpac_800292C4();
    if (temp_v0) {
        sp18 = temp_v0;
        sp1C(temp_v0);
        sp18->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_ACTIVE;
    }
}

void func_jetpac_800294EC(JetpacStruct *arg0, s32 arg1) {
    f32 temp = (arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.unk1C.left);
    f32 temp2 = (arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.unk1C.right);
    f32 temp_0 = D_jetpac_8002EC30.platforms[arg1].spatial_state.unk1C.left;
    f32 temp_8 = D_jetpac_8002EC30.platforms[arg1].spatial_state.unk1C.right;

    s32 pad;

    f32 temp3 = (arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.unk1C.top);
    f32 temp4 = (arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.unk1C.bottom);
    f32 temp_4 = D_jetpac_8002EC30.platforms[arg1].spatial_state.unk1C.top;
    f32 temp_C = D_jetpac_8002EC30.platforms[arg1].spatial_state.unk1C.bottom;

    if (((temp_8 <= temp) && (temp_8 <= temp2)) || ((temp2 <= temp_0) && (temp <= temp_0))) {
        arg0->unk0.spatial_state.velX = -arg0->unk0.spatial_state.velX;
    }
    if (((temp_C <= temp3) && (temp_C <= temp4)) || ((temp4 <= temp_4) && (temp3 <= temp_4))) {
        arg0->unk0.spatial_state.velY = -arg0->unk0.spatial_state.velY;
    }
}

void func_jetpac_80029640(JetpacStruct *arg0, f32 arg1, f32 arg2) {
    JetpacStruct *var_v0;
    s32 var_a1;
    s32 var_a2;
    s32 i;
    s32 rng;

    // TODO: Why? Any way to avoid this?
    var_a1 = 0;var_a2 = 0;

    arg0->unk0.score_value = 25;
    if (arg0->unk0.spatial_state.posY < 88.0f) {
        arg0->unk0.spatial_state.velX = arg1;
        arg0->unk0.spatial_state.is_facing_left = 0;
    } else {
        arg0->unk0.spatial_state.velX = -arg1;
        arg0->unk0.spatial_state.is_facing_left = 1;
    }
    var_v0 = &D_jetpac_8002F1DC[0];
    for (i = 0; i < 6; i++) {
        if (var_v0->unk0.spatial_state.entity_state > JETPAC_ENTITY_STATE_DEAD) {
            if (var_v0->unk0.spatial_state.velY == 0.0f) {
                var_a1++;
            } else {
                var_a2++;
            }
        }
        var_v0++;
    }
    if (var_a1 == 3) {
        arg0->unk0.spatial_state.velY = arg2;
    } else {
        if (var_a2 == 3) {
            arg0->unk0.spatial_state.velY = 0.0f;
        } else {
            rng = func_jetpac_80027210() * 2;
            if (rng % 2) {
                arg0->unk0.spatial_state.velY = 0.0f;
            } else {
                arg0->unk0.spatial_state.velY = arg2;
            }
        }
    }
}

void func_jetpac_8002976C(JetpacStruct *arg0) {
    switch (arg0->unk0.spatial_state.entity_state) {
        case JETPAC_ENTITY_STATE_ACTIVE:
            if (func_jetpac_80028CF8(
                arg0->unk0.spatial_state.unk1C.left + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.top + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                arg0->unk0.spatial_state.unk1C.right + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.bottom + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY, 1) >= 0) {
                func_jetpac_800291AC(arg0);
                return;
            }
            if (func_jetpac_80029064(arg0) == 0) {
                arg0->unk0.spatial_state.posX += arg0->unk0.spatial_state.velX;
                arg0->unk0.spatial_state.posY += arg0->unk0.spatial_state.velY;
                return;
            }
            return;
        case JETPAC_ENTITY_STATE_DYING:
            arg0->unk0.spatial_state.unk1C.counter++;
            if (arg0->unk0.spatial_state.unk1C.counter >= 0xF) {
                arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DEAD;
            }
            break;
    }
}

void func_jetpac_80029884(JetpacStruct *arg0) {
    arg0->unk0.spatial_state.unk1C.bottom = 0xB;
    func_jetpac_80029640(arg0, 1.6f, 0.5f);
    arg0->unk48.unk0 = func_jetpac_800298C8;
}

void func_jetpac_800298C8(JetpacStruct *arg0) {
    func_jetpac_8002976C(arg0);
    arg0->unk48.unk4 = &D_jetpac_8002E800[(s32)arg0->unk0.spatial_state.posX % 2];
}

void func_jetpac_8002992C(JetpacStruct *arg0) {
    arg0->unk48.unk0 = func_jetpac_8002998C;
    arg0->unk0.score_value = 80;
    if (arg0->unk0.spatial_state.posY < 88.0f) {
        arg0->unk0.spatial_state.velX = -1.2f;
    } else {
        arg0->unk0.spatial_state.velX = 1.2f;
    }
    arg0->unk0.spatial_state.velY = -0.8f;
    arg0->unk48.unk4 = &D_jetpac_8002E830;
}

void func_jetpac_8002998C(JetpacStruct *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk0.spatial_state.entity_state) {                              
        case 3:
            temp_v0_2 = func_jetpac_80028CF8(
                        arg0->unk0.spatial_state.unk1C.left + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                        arg0->unk0.spatial_state.unk1C.top + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                        arg0->unk0.spatial_state.unk1C.right + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                        arg0->unk0.spatial_state.unk1C.bottom + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY, 1);
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
            }
            if (!func_jetpac_80029064(arg0)) {
                if (arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY < 24.0f) {
                    arg0->unk0.spatial_state.velY = -arg0->unk0.spatial_state.velY;
                }
                arg0->unk0.spatial_state.posY = arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY;
                arg0->unk0.spatial_state.posX += arg0->unk0.spatial_state.velX;
                if ((s32)arg0->unk0.spatial_state.posX & 2) {
                    arg0->unk0.spatial_state.is_facing_left ^= 1;
                }
            }
            break;
        case 4:
            arg0->unk0.spatial_state.unk1C.counter++;
            if (arg0->unk0.spatial_state.unk1C.counter >= 0xF) {
                arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DEAD;
            }
            break;
    }
}

void func_jetpac_80029AF8(JetpacStruct *arg0) {
    arg0->unk48.unk0 = func_jetpac_80029C1C;
    arg0->unk0.score_value = 40;
    if (arg0->unk0.spatial_state.posY < 88.0f) {
        arg0->unk0.spatial_state.velX = -1.2f;
    } else {
        arg0->unk0.spatial_state.velX = 1.2f;
    }
    func_jetpac_80029B90(arg0);
    arg0->unk0.spatial_state.unk1C.counter = (func_jetpac_80027210() * 60.0f) + 10.0f;
}

void func_jetpac_80029B90(JetpacStruct *arg0) {
    if (arg0->unk0.spatial_state.velY == 0.0) {
        if (func_jetpac_80027210() < 0.5) {
            arg0->unk0.spatial_state.velY = -0.6f;
            return;
        }
        arg0->unk0.spatial_state.velY = 0.6f;
        return;
    }
    arg0->unk0.spatial_state.velY = 0.0f;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Struct8002E848;

extern Struct8002E848 D_jetpac_8002E848[];

void func_jetpac_80029C1C(JetpacStruct *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk0.spatial_state.entity_state) {
        case 3:
            arg0->unk0.spatial_state.unk1C.counter--;
            if (arg0->unk0.spatial_state.unk1C.counter == 0) {
                func_jetpac_80029B90(arg0);
                arg0->unk0.spatial_state.unk1C.counter = (func_jetpac_80027210() * 60.0f) + 10.0f;
            }
            temp_v0_2 = func_jetpac_80028CF8(
                arg0->unk0.spatial_state.unk1C.left + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.top + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                arg0->unk0.spatial_state.unk1C.right + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.bottom + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                1
            );
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
                if (arg0->unk0.spatial_state.unk1C.counter < 0xA) {
                    arg0->unk0.spatial_state.unk1C.counter = 0xA;
                }
            }
            if (!func_jetpac_80029064(arg0)) {
                if ((arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY) < 24.0f) {
                    arg0->unk0.spatial_state.velY = -arg0->unk0.spatial_state.velY;
                }
                arg0->unk0.spatial_state.posY = arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY;
                arg0->unk0.spatial_state.posX = arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX;
                arg0->unk48.unk4 = &D_jetpac_8002E848[(((s32)(arg0->unk0.spatial_state.posX / 4) % 2))];
            }
            break;
        case 4:
            arg0->unk0.spatial_state.unk1C.counter++;
            if (arg0->unk0.spatial_state.unk1C.counter >= 0xF) {
                arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DEAD;
            }
            break;
    }
}

void func_jetpac_80029E0C(JetpacStruct *arg0) {
    arg0->unk48.unk0 = func_jetpac_80029F7C;
    arg0->unk0.score_value = 55;
    arg0->unk0.spatial_state.unk1C.counter = (func_jetpac_80027210() * 60.0f) + 10.0f;
    arg0->unk0.counter_limit = (func_jetpac_80027210() * 180.0f) + 10.0f;
    arg0->unk0.spatial_state.unk1C.bottom = 8;
    if (arg0->unk0.spatial_state.posY < 88.0f) {
        arg0->unk0.spatial_state.is_facing_left = 0;
    } else {
        arg0->unk0.spatial_state.is_facing_left = 1;
    }
    arg0->unk0.spatial_state.velX = 0.0f;
    if (D_jetpac_8002BA6C) {
        arg0->unk0.spatial_state.velY = -0.8f;
    } else {
        arg0->unk0.spatial_state.velY = 0.8f;
    }
    arg0->unk48.unk4 = &D_jetpac_8002E878;
}

void func_jetpac_80029F7C(JetpacStruct* arg0) {
    JetpacPlayerStruct* ms = &D_jetpac_8002F050;
    switch (arg0->unk0.spatial_state.entity_state) {
    case 3:
        if (arg0->unk0.spatial_state.unk1C.counter == 0) {
            if (func_jetpac_80028CF8(
                arg0->unk0.spatial_state.unk1C.left + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.top + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                arg0->unk0.spatial_state.unk1C.right + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.bottom + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY, 1) >= 0)
            {
                func_jetpac_800291AC(arg0);
            } else {
                arg0->unk0.counter_limit--;
            }
            if (arg0->unk0.counter_limit == 0) {
                func_jetpac_800291AC(arg0);
            }
        }
        else if ((D_jetpac_8002BA6C != 0) && (arg0->unk0.spatial_state.posY < 32.0f)) {
            func_jetpac_800291AC(arg0);
        }

        if (arg0->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_ACTIVE) {
            func_jetpac_80029064(arg0);
        }
        if (arg0->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_DYING) {
            Competitor* competitor = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
            competitor->current_score += arg0->unk0.score_value;
            break;
        }
        if (arg0->unk0.spatial_state.unk1C.counter != 0) {
            arg0->unk0.spatial_state.unk1C.counter--;
            if (D_jetpac_8002BA6C != 0) {
                arg0->unk0.spatial_state.velY = -0.8f;
            } else {
                arg0->unk0.spatial_state.velY = 0.8f;
            }
            if (arg0->unk0.spatial_state.unk1C.counter == 0) {
                if (arg0->unk0.spatial_state.is_facing_left != 0) {
                    arg0->unk0.spatial_state.velX = -1.6f;
                } else {
                    arg0->unk0.spatial_state.velX = 1.6f;
                }
                arg0->unk0.spatial_state.color.red = 0xFF;
                arg0->unk0.spatial_state.color.green = 0xFF;
                arg0->unk0.spatial_state.color.blue = 0xFF;
            }
        }
        if ((arg0->unk0.spatial_state.unk1C.counter == 0) && (D_jetpac_8002EC30.unk790 & 2)) {
            if (func_jetpac_800273C8(arg0) < (ms->spatial_state.posY + ms->spatial_state.unk1C.bottom)) {
                arg0->unk0.spatial_state.velY = 0.8f;
            } else {
                arg0->unk0.spatial_state.velY = -0.8f;
            }
        }
        arg0->unk0.spatial_state.posX += arg0->unk0.spatial_state.velX;
        arg0->unk0.spatial_state.posY += arg0->unk0.spatial_state.velY;
        break;
    case 4:
        arg0->unk0.spatial_state.unk1C.counter++;
        if (arg0->unk0.spatial_state.unk1C.counter >= 0xF) {
            arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DEAD;
        }
        break;
    }
}

void func_jetpac_8002A254(JetpacStruct *arg0) {
    arg0->unk48.unk0 = func_jetpac_8002A530;
    arg0->unk0.score_value = 50;
    if (arg0->unk0.spatial_state.posY < 88.0f) {
        arg0->unk0.spatial_state.is_facing_left = 0;
    } else {
        arg0->unk0.spatial_state.is_facing_left = 1;
    }
    func_jetpac_8002A374(arg0);
}

void func_jetpac_8002A2AC(JetpacStruct *arg0) {
    arg0->unk0.spatial_state.unk1C.bottom = 8;
    arg0->unk48.unk4 = &D_jetpac_8002E890;
    func_jetpac_8002A254(arg0);
}

f32 func_jetpac_8002A2DC(f32 arg0, f32 arg1) {
    f64 temp;
    if (arg0 < 0.0f) {
        arg1 -= 0.08;
    } else {
        arg1 += 0.08;
    }

    temp = -1.2;

    return (arg1 < temp) ? temp: MIN(1.2, arg1);
}

void func_jetpac_8002A374(JetpacStruct *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f14;
    f32 sp28;
    f32 temp_f12;
    f32 var_f18;
    f32 sp1C;
    f32 sp18;
    JetpacSpatialState* player_state = &D_jetpac_8002F050.spatial_state;
    JetpacSpatialState* obj_state = &arg0->unk0.spatial_state;

    sp18 = func_jetpac_80027380(obj_state);
    temp_f0 = func_jetpac_80027380(player_state);
    temp_f2 = temp_f0 - sp18;
    if (sp18 < temp_f0) {
        var_f14 = temp_f2 - 256.0f;
    } else {
        var_f14 = temp_f2 + 256.0f;
    }
    temp_f12 = (player_state->posY + player_state->unk1C.bottom) - func_jetpac_800273C8(arg0);
    if (temp_f12 > 0.0f) {
        var_f18 = temp_f12 - 288.0;
    } else {
        var_f18 = temp_f12 + 192.0f;
    }
    if ((ABS(temp_f2)) < (ABS(var_f14))) {
        sp28 = temp_f2;
    } else {
        sp28 = var_f14;
    }
    if ((ABS(temp_f12)) < (ABS(var_f18))) {
        sp1C = temp_f12;
    } else {
        sp1C = var_f18;
    }
    obj_state->velX = func_jetpac_8002A2DC(sp28, obj_state->velX);
    obj_state->velY = func_jetpac_8002A2DC(sp1C, obj_state->velY);
}

void func_jetpac_8002A530(JetpacStruct *arg0) {
    s32 temp_v0_2;

    switch (arg0->unk0.spatial_state.entity_state) {
        case 3:
            func_jetpac_8002A374(arg0);
            temp_v0_2 = func_jetpac_80028CF8(
                arg0->unk0.spatial_state.unk1C.left + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.top + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                arg0->unk0.spatial_state.unk1C.right + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
                arg0->unk0.spatial_state.unk1C.bottom + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
                1
            );
            if (temp_v0_2 >= 0) {
                func_jetpac_800294EC(arg0, temp_v0_2);
            }
            if (func_jetpac_80029064(arg0) == 0) {
                if ((arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY) < 24.0f) {
                    arg0->unk0.spatial_state.velY = -arg0->unk0.spatial_state.velY;
                }
                arg0->unk0.spatial_state.posY += arg0->unk0.spatial_state.velY;
                arg0->unk0.spatial_state.posX += arg0->unk0.spatial_state.velX;
                return;
            }
            return;
        case 4:
            arg0->unk0.spatial_state.unk1C.counter++;
            if (arg0->unk0.spatial_state.unk1C.counter >= 0xF) {
                arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DEAD;
            }
            break;
    }
}

void func_jetpac_8002A67C(JetpacStruct *arg0) {
    s32 temp_f6;

    temp_f6 = (arg0->unk0.spatial_state.unk1C.counter % 4) + 1;
    arg0->unk0.spatial_state.velY = (-1.2 / (f64)temp_f6);
    arg0->unk0.spatial_state.unk1C.counter++;
}

void func_jetpac_8002A6C0(JetpacStruct *arg0) {
    arg0->unk48.unk0 = func_jetpac_8002A758;
    arg0->unk0.score_value = 60;
    arg0->unk0.spatial_state.unk1C.counter = (s32) (func_jetpac_80027210() * 16.0f);
    if (arg0->unk0.spatial_state.posY < 88.0f) {
        arg0->unk0.spatial_state.velX = -1.2f;
    } else {
        arg0->unk0.spatial_state.velX = 1.2f;
    }
    func_jetpac_8002A67C(arg0);
    arg0->unk48.unk4 = &D_jetpac_8002E8A8;
}

void func_jetpac_8002A758(JetpacStruct* arg0) {
    f32 newUnkC;
    f32 oldUnkC;
    s32 returnValue;
    switch (arg0->unk0.spatial_state.entity_state) {
    case 3:
        arg0->unk0.spatial_state.velY += 0.005;
        oldUnkC = arg0->unk0.spatial_state.velY;
        returnValue = func_jetpac_80028CF8(
            arg0->unk0.spatial_state.unk1C.left + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
            arg0->unk0.spatial_state.unk1C.top + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
            arg0->unk0.spatial_state.unk1C.right + arg0->unk0.spatial_state.posX + arg0->unk0.spatial_state.velX,
            arg0->unk0.spatial_state.unk1C.bottom + arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY,
            1);
        if (returnValue >= 0) {
            func_jetpac_800294EC(arg0, returnValue);
            newUnkC = arg0->unk0.spatial_state.velY;
            if ((oldUnkC > 0.f) && (newUnkC < 0.f)) {
                func_jetpac_8002A67C(arg0);
            }
        }
        if (func_jetpac_80029064(arg0) == 0) {
            newUnkC = arg0->unk0.spatial_state.velY;
            if (arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY < 24.0f) {
                arg0->unk0.spatial_state.velY = -arg0->unk0.spatial_state.velY;
            }
            arg0->unk0.spatial_state.posY = arg0->unk0.spatial_state.posY + arg0->unk0.spatial_state.velY;
            arg0->unk0.spatial_state.posX += arg0->unk0.spatial_state.velX;
        }
        break;
    case 4:
        arg0->unk0.spatial_state.unk1C.counter++;
        if (arg0->unk0.spatial_state.unk1C.counter >= 0xF) {
            arg0->unk0.spatial_state.entity_state = JETPAC_ENTITY_STATE_DEAD;
        }
        break;
    }
}

void func_jetpac_8002A8F0(JetpacStruct *arg0) {
    arg0->unk0.spatial_state.unk1C.bottom = 0xE;
    arg0->unk48.unk4 = &D_jetpac_8002E8C0;
    func_jetpac_80029640(arg0, 1.2f, 0.3f);
    arg0->unk48.unk0 = func_jetpac_8002976C;
}

void func_jetpac_8002A944(JetpacStruct *arg0) {
    arg0->unk0.spatial_state.unk1C.bottom = 0xE;
    arg0->unk48.unk4 = &D_jetpac_8002E8D8;
    func_jetpac_8002A254(arg0);
}

s32 func_jetpac_8002A974(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Competitor *player;
    s32 i;
    JetpacStruct *var_s0;

    var_s0 = &D_jetpac_8002F1DC[0];
    for (i = 0; i < 6; i++) {
        if (var_s0->unk0.spatial_state.entity_state == JETPAC_ENTITY_STATE_ACTIVE) {
            if (func_jetpac_80027250(arg0, arg1, arg2, arg3, var_s0->unk0.spatial_state.posX + var_s0->unk0.spatial_state.unk1C.left, var_s0->unk0.spatial_state.posY + var_s0->unk0.spatial_state.unk1C.top, var_s0->unk0.spatial_state.posX + var_s0->unk0.spatial_state.unk1C.right, var_s0->unk0.spatial_state.posY + var_s0->unk0.spatial_state.unk1C.bottom) != 0) {
                player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
                func_jetpac_800291AC(var_s0);
                player->current_score += var_s0->unk0.score_value;
                return TRUE;
            }
        }
        var_s0++;
    }
    return FALSE;
}

extern JetpacStruct D_jetpac_8002E964;

void func_jetpac_8002AAD4(void) {
    s32 i;
    JetpacStruct sp24;
    JetpacStruct *var_v0;

    sp24 = D_jetpac_8002E964;
    var_v0 = &D_jetpac_8002F1DC[0];
    for (i = 0; i < 6; i++) {
        *var_v0 = sp24;
        var_v0++;
    }
    for (i = 0; i < 3; i++) {
        func_jetpac_80029450();
    }
    D_jetpac_8002E8F0 = func_jetpac_80027210() * 180.0f;
}

void func_jetpac_8002ABDC(void) {
    JetpacStruct *var_s0;
    s32 count;
    s32 i;

    var_s0 = D_jetpac_8002F1DC;
    count = 0;

    if (func_jetpac_80026FE0()) {
        return;
    }

    if (D_jetpac_8002E8F0 > 0) {
        D_jetpac_8002E8F0--;
    }

    for (i = 0; i != 6; i++) {
        if (var_s0->unk0.spatial_state.entity_state > JETPAC_ENTITY_STATE_DEAD) {
            if (var_s0->unk48.unk0 != NULL) {
                var_s0->unk48.unk0(var_s0);
                if (var_s0->unk0.spatial_state.posX < 0.0f) {
                    var_s0->unk0.spatial_state.posX += 256.0f;
                }
                if (var_s0->unk0.spatial_state.posX > 256.0f) {
                    var_s0->unk0.spatial_state.posX -= 256.0f;
                }
                count++;
            }
        }
        var_s0++;
    }
    if (count < 3 && D_jetpac_8002E8F0 >= 6) {
        D_jetpac_8002E8F0 = func_jetpac_80027210() * 5.0f;
    }
    if (D_jetpac_8002E8F0 == 0 && D_jetpac_8002F3BC == 2) {
        func_jetpac_80029450();
        count++;
        if (count < 3) {
            D_jetpac_8002E8F0 = func_jetpac_80027210() * 5.0f;
        } else {
            D_jetpac_8002E8F0 = func_jetpac_80027210() * 180.0f;
        }
    }
}

void func_jetpac_8002AD8C(void) {
    JetpacStruct *var_s0;
    s32 i;

    var_s0 = &D_jetpac_8002F1DC[0];
    if (!func_jetpac_80026FE0()) {
        for (i = 0; i < 6; i++) {
            if (var_s0->unk0.spatial_state.entity_state >= JETPAC_ENTITY_STATE_ALLOCATED) {
                if (var_s0->unk48.unk4) {
                    func_jetpac_80029204(var_s0);
                }
            }
            var_s0++;
        }
    }
}

void func_jetpac_8002AE00(Gfx **arg0) {
    Gfx *dl = *arg0;
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetCombineMode(dl++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA)
    gDPSetRenderMode(dl++, G_RM_OPA_SURF, G_RM_OPA_SURF2)
    *arg0 = dl;
}

void func_jetpac_8002AE94(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_jetpac_80045BE0 = arg0;
    D_jetpac_80045BE1 = arg1;
    D_jetpac_80045BE2 = arg2;
    D_jetpac_80045BE3 = arg3;
}

void func_jetpac_8002AEC8(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_jetpac_8002E9C0 = arg0;
    D_jetpac_8002E9C4 = arg1;
    D_jetpac_8002E9C8 = arg2;
    D_jetpac_8002E9CC = arg3;
}

void func_jetpac_8002AEFC(Gfx **arg0, char *string, s32 x, s32 y, s32 arg4) {
    Gfx *dl;

    dl = *arg0;
    if (arg4 != 0) {
        gDPSetPrimColor(dl++, 0, 0, D_jetpac_8002E9C0, D_jetpac_8002E9C4, D_jetpac_8002E9C8, D_jetpac_8002E9CC);
        gDPSetEnvColor(dl++, D_jetpac_80045BE0, D_jetpac_80045BE1, D_jetpac_80045BE2, D_jetpac_80045BE3);
    } else {
        gDPSetPrimColor(dl++, 0, 0, D_jetpac_80045BE0, D_jetpac_80045BE1, D_jetpac_80045BE2, D_jetpac_80045BE3);
        gDPSetEnvColor(dl++, D_jetpac_8002E9C0, D_jetpac_8002E9C4, D_jetpac_8002E9C8, D_jetpac_8002E9CC);
    }
    *arg0 = func_global_asm_806FD490(dl, 4, x, y, string);
}
