#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_80767CE8[];
extern s32 D_global_asm_8076A048;
extern s32 D_global_asm_8076A088;
extern u8 D_global_asm_8076A0B1;
extern s32 D_global_asm_8076A08C;
extern s32 D_global_asm_8076A080;

extern f32 D_global_asm_807FD888;

// TODO: Pretty close
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_jetpac_80024000.s")

typedef struct {
    u8 unk0[0x80 - 0x0];
    u8 unk80;
} Struct8002419C_arg0;
void func_jetpac_8002419C(Struct8002419C_arg0 *arg0, Gfx **arg1);

/*
void func_jetpac_80024000(void) {
    s32 sp2C;
    Gfx **sp28;
    s32 temp_a0;
    s32 temp_t5;
    u8 temp_t1;

    func_global_asm_8060A9BC();
    func_global_asm_80610044(D_global_asm_8076A050[D_global_asm_807444FC], D_global_asm_8076A088, 3, 1, 0x4D2, 1);
    temp_t1 = D_global_asm_807444FC ^ 1;
    D_global_asm_807444FC = temp_t1;
    object_timer++;
    D_global_asm_8076A048 = D_global_asm_80767CE8[(temp_t1 & 0xFF) * 0x11B0];
    func_global_asm_8060AC7C();
    if ((D_global_asm_8076A0B1 & 1) && (D_global_asm_807FD888 == 31.0f)) {
        sp2C = D_global_asm_8076A050[D_global_asm_807444FC];
    } else {
        func_jetpac_8002419C(D_global_asm_8076A048, &sp2C);
    }
    temp_a0 = func_global_asm_80704484(sp2C, 0);
    if (is_cutscene_active != 4) {
        sp28 = D_global_asm_8076A048 + 0xDB0;
        func_global_asm_805FE71C(temp_a0, D_global_asm_807444FC, &D_global_asm_8076A088, 0);
        func_global_asm_805FE7B4(sp28, D_global_asm_8076A048, &D_global_asm_8076A08C, 1);
    } else {
        func_global_asm_805FE71C(temp_a0, D_global_asm_807444FC, &D_global_asm_8076A088, 1);
    }
}
*/

void func_jetpac_8002419C(Struct8002419C_arg0 *arg0, Gfx **arg1) {
    Gfx *sp6C;
    void *sp68;
    Gfx *dl;

    dl = D_global_asm_8076A050[D_global_asm_807444FC];
    gSPSegment(dl++, 0x00, 0x00000000);
    gSPSegment(dl++, 0x02, osVirtualToPhysical(arg0));
    gSPSegment(dl++, 0x01, osVirtualToPhysical(D_global_asm_8076A080));
    gSPDisplayList(dl++, &D_1000090);
    gSPDisplayList(dl++, &D_1000040);
    guOrtho(&arg0->unk80, 0, 320.0f, 0, 240.0f, 1.0f, 10.0f, 1.0f);
    gDPPipeSync(dl++);
    dl = func_global_asm_805FE4D4(dl);
    gDPSetColorDither(dl++, G_CD_MAGICSQ);
    gDPSetAlphaDither(dl++, G_AD_PATTERN);
    gDPSetFillColor(dl++, 0x00010001);
    gDPFillRectangle(dl++, 0, 0, 319, 239);
    gSPMatrix(dl++, &D_2000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    sp68 = malloc(3000 * sizeof(Gfx));
    func_global_asm_8061134C(sp68);
    sp6C = sp68;
    func_jetpac_80025168(&sp6C);
    gSPEndDisplayList(sp6C++);
    gSPDisplayList(dl++, sp68);
    *arg1 = dl;
}

extern JetpacPlayerStruct D_jetpac_8002EC30;

void func_jetpac_80024390(void) {
    s32 playerIndex;
    Competitor *player;

    for (playerIndex = 0; playerIndex < 2; playerIndex++) {
        player = &D_jetpac_8002EC30.player[playerIndex];
        player->level = -1;
        player->current_score = 0;
        if (playerIndex < D_jetpac_8002EC30.unk348) {
            if (D_jetpac_8002EC30.unk798 != 0) {
                player->lives = 3;
            } else {
                player->lives = 5;
            }
        } else {
            player->lives = -1;
        }
    }
    D_jetpac_8002EC30.player_index = 0;
}

extern s32 D_jetpac_8002EC48;
extern s32 D_jetpac_8002BA6C;
extern s32 D_jetpac_8002EF74;
extern s32 D_jetpac_8002EC50;
extern s32 D_jetpac_8002EDE4;

void func_jetpac_80024408(Gfx **arg0) {
    Competitor *player;
    s32 pad[15];
    s8 sp60[16];
    s32 temp_s0;
    s32 playerIndex;
    s32 pad2;

    temp_s0 = func_jetpac_80026FE0() & D_jetpac_8002BA6C;
    func_jetpac_8002AE00(arg0);
    func_jetpac_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_jetpac_8002AEFC(arg0, "1UP", 0x38, 0x18, temp_s0 && !D_jetpac_8002EF74);
    player = &D_jetpac_8002EC30.player[0];
    for (playerIndex = 0; playerIndex < 2; playerIndex++) {
        if (player->lives > 0) {
            sprintf(sp60, "%d!", player->lives);
            func_jetpac_8002AEFC(arg0, &sp60, 0x60 + (playerIndex * 0x70), 0x18, 0);
        }
        player++;
    }
    func_jetpac_8002AEFC(arg0, "2UP", 0xF8, 0x18, temp_s0 && D_jetpac_8002EF74 == 1);
    func_jetpac_8002AE94(0, 0xFF, 0xFF, 0xFF);
    func_jetpac_8002AEFC(arg0, "HI", 0x98, 0x18, 0);
    player = &D_jetpac_8002EC30.player[0];
    func_jetpac_8002AE94(0xFF, 0xFF, 0, 0xFF);
    sprintf(sp60, "%06d", player[0].current_score);
    func_jetpac_8002AEFC(arg0, &sp60, 0x28, 0x20, 0);
    sprintf(sp60, "%06d", D_jetpac_8002EC30.unk18);
    func_jetpac_8002AEFC(arg0, &sp60, 0x88, 0x20, 0);
    sprintf(sp60, "%06d", player[1].current_score);
    func_jetpac_8002AEFC(arg0, &sp60, 0xE8, 0x20, 0);
}

void func_jetpac_8002463C(void) {
    func_jetpac_80028C3C();
    func_jetpac_80024390();
    func_jetpac_800250A0();
}

void func_jetpac_8002466C(Gfx **arg0) {
    char sp28[40];

    func_jetpac_80024408(arg0);
    func_jetpac_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_jetpac_8002AEFC(arg0, "JETPAC GAME SELECTION", 0x50, 0x38, 0);
    func_jetpac_8002AEFC(arg0, "1@@@1@PLAYER@GAME", 0x50, 0x50, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unk348 == 1);
    func_jetpac_8002AEFC(arg0, "2@@@2@PLAYER@GAME", 0x50, 0x60, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unk348 == 2);
    func_jetpac_8002AEFC(arg0, "3@@@KEYBOARD", 0x50, 0x70, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unk34C == 0);
    func_jetpac_8002AEFC(arg0, "4@@@KEMPSTON@JOYSTICK", 0x50, 0x80, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unk34C != 0);
    func_jetpac_8002AEFC(arg0, "5   START GAME", 0x50, 0xB8, 0);
    sprintf(sp28, "%c1983 A.C.G. ALL RIGHTS RESERVED", 0x7F);
    func_jetpac_8002AEFC(arg0, sp28, 0x20, 0xD8, 0);
    if (D_jetpac_8002EC30.unk798 != 0) {
        if (!(D_jetpac_8002EC30.unk8 & 0x1000) && (D_jetpac_8002EC30.unk799 < 0x78)) {
            D_jetpac_8002EC30.unk799 = D_jetpac_8002EC30.unk799 + 1;
            return;
        }
        D_jetpac_8002EC30.unk799 = 0;
        func_jetpac_8002463C();
        return;
    }
    if (D_jetpac_8002EC30.unk8 & 0x4000) {
        D_jetpac_8002EC30.unk348 = D_jetpac_8002EC30.unk348 ^ 3;
    }
    if (D_jetpac_8002EC30.unk8 & 0x8000) {
        D_jetpac_8002EC30.unk34C = D_jetpac_8002EC30.unk34C ^ 1;
    }
    if (D_jetpac_8002EC30.unk8 & 0x1000) {
        func_jetpac_8002463C();
    }
}

void func_jetpac_800248A0(Gfx **arg0) {
    func_jetpac_80024408(arg0);
    func_jetpac_800286D0();
    func_jetpac_800255D4(arg0);
    func_jetpac_80028E88();
    func_jetpac_800289EC();
    func_jetpac_80025904(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_jetpac_800248E8.s")

/*
// TODO: Doable
void func_jetpac_800248E8(Gfx **arg0) {
    Competitor *player;
    JetpacPickupStruct *rocket;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (player->current_score >= 1000000) {
        player->current_score -= 1000000;
    }
    func_jetpac_80024408(arg0);
    func_jetpac_80026D48();
    func_jetpac_80026CEC();
    player->next_bonus_item.primary_info.unk44(&player->next_bonus_item);
    rocket = &player->rocket_segments[player->unk10];
    rocket->primary_info.unk44(rocket);
    func_jetpac_8002ABDC();
    func_jetpac_800255D4(arg0);
    func_jetpac_80028E88();
    func_jetpac_80026AB0();
    func_jetpac_8002AD8C();
    func_jetpac_80028544();
    func_jetpac_800285DC();
    func_jetpac_80026CA4();
    func_jetpac_80025904(arg0);
    if (func_jetpac_80026FE0()) {
        D_jetpac_8002EC30.unk44C++;
    }
    if (D_jetpac_8002EC30.unk8 & 0x1000) {
        D_jetpac_8002EC30.unk78C = 3;
        D_jetpac_8002EC30.unkC = 1;
    }
}
*/

void func_jetpac_80024A4C(void) {
    func_global_asm_8060C648(0x11, 0, 0, 0, D_jetpac_8002EC48);
    func_global_asm_8060DEA8();
}

extern s32 D_jetpac_8002BA6C;

void func_jetpac_80024A8C(Gfx **arg0) {
    Maps nextMap;

    func_jetpac_80024408(arg0);
    func_jetpac_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_jetpac_8002AEFC(arg0, "RETURN", 0x88, 0x70, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unkC == 1);
    func_jetpac_8002AEFC(arg0, "DELETE@HISCORE", 0x68, 0x80, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unkC == 2);
    func_jetpac_8002AEFC(arg0, "EXIT@@JETPAC", 0x70, 0x90, D_jetpac_8002BA6C != 0 && D_jetpac_8002EC30.unkC == 0);
    if (D_jetpac_8002EC30.unk8 & 0xE000) {
        switch (D_jetpac_8002EC30.unkC) {
            default:
            case 0:
                if (D_jetpac_8002EC30.unk798 != 0) {
                    nextMap = MAP_CRANKYS_LAB;
                } else {
                    nextMap = MAP_MAIN_MENU;
                }
                func_global_asm_805FF378(nextMap, 0);
                break;
            case 1:
                D_jetpac_8002EC30.unk78C = 2;
                break;
            case 2:
                if (D_jetpac_8002EC30.unk18 != 0) {
                    func_global_asm_8060C8AC(1);
                    D_jetpac_8002EC30.unk18 = func_global_asm_8060C6B8(0x11, 0, 0, 0);
                    func_jetpac_80024A4C();
                    break;
                }
                break;
        }
    }
    if (D_jetpac_8002EC30.unk8 & 0x400) {
        D_jetpac_8002EC30.unkC++;
    }
    if (D_jetpac_8002EC30.unk8 & 0x800) {
        D_jetpac_8002EC30.unkC--;
    }
    if (D_jetpac_8002EC30.unkC >= 3) {
        D_jetpac_8002EC30.unkC = 0;
    }
    if (D_jetpac_8002EC30.unkC < 0) {
        D_jetpac_8002EC30.unkC = 2;
    }
}

void func_jetpac_80024C90(Gfx **arg0) {
    Competitor *player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    func_jetpac_80024408(arg0);
    func_jetpac_80026CEC();
    player->next_bonus_item.primary_info.unk44(&player->next_bonus_item);
    func_jetpac_800286D0();
    func_jetpac_8002ABDC();
    func_jetpac_800255D4(arg0);
    func_jetpac_80028E88();
    func_jetpac_8002AD8C();
    func_jetpac_800289EC();
    func_jetpac_800285DC();
    func_jetpac_80026CA4();
    func_jetpac_80025904(arg0);
}

void func_jetpac_80024D48(Gfx **arg0) {
    s32 sp4C;
    char sp2C[32];

    sp4C = 7;
    func_jetpac_80024408(arg0);
    if ((D_jetpac_8002EC30.unk798 != 0) && isFlagSet(0x62, FLAG_TYPE_TEMPORARY)) {
        sprintf(sp2C, "RAREWARE COIN COLLECTED");
        sp4C = 5;
    } else {
        sprintf(sp2C, "GAME OVER PLAYER %d", D_jetpac_8002EC30.player_index + 1);
    }
    func_jetpac_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_jetpac_8002AEFC(arg0, &sp2C, (sp4C * 8) + 0x20, 0x88, 0);
    if (D_jetpac_8002EC30.unk790 >= 0x79U) {
        if (D_jetpac_8002EC30.unk798 != 0) {
            if (D_jetpac_8002EC30.unk799 == 0) {
                D_jetpac_8002EC30.unk799 = 1;
                func_global_asm_805FF378(MAP_CRANKYS_LAB, 0);
            }
        } else {
            func_jetpac_80025368(&D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index]);
        }
    }
}

typedef struct StructJetpac8002BA52 {
    s16 unk0;
    s16 unk2;
} StructJetpac8002BA52;

extern s32 D_global_asm_80770DF8[];
extern void *D_global_asm_8076D1F8;
extern StructJetpac8002BA52 D_jetpac_8002BA52[]; // likely 8002ba50 s32, but read as a s16

void func_global_asm_80737924(s32);

void func_global_asm_80737638(void *arg0, enum sfx_e arg1, u32 arg2, u32 arg3, f32 arg4, u32 arg5, void *arg6);

void func_jetpac_80024E70(s32 arg0) {
    s32 i;
    s16 sfx;
    void* temp;
    for (i = arg0; i < 7; i++) {
        if (D_global_asm_80770DF8[i] != 0) {
            func_global_asm_80737924(D_global_asm_80770DF8[i]);
        }
    }
    func_global_asm_80737638(D_global_asm_8076D1F8, D_jetpac_8002BA52[arg0].unk0, 0x7FFF, 0x3F, 1.0f, 0, &D_global_asm_80770DF8[arg0]);
}

void func_jetpac_80024F24(s32 arg0, s32 arg1) {
    if (D_global_asm_80770DF8[arg0]) {
        func_global_asm_80737AC4(D_global_asm_80770DF8[arg0], 0x10, arg1);
        if (arg1) {};
    }
}

void func_jetpac_80024F64(s32 arg0) {
    s32 temp_a1;

    temp_a1 = D_global_asm_80770DF8[arg0];
    if (temp_a1 != 0) {
        func_global_asm_80737924(temp_a1);
    }
}

extern s32 D_jetpac_8002F064;

void func_jetpac_80024F9C(s32 arg0) {
    s32 pad24;
    Competitor *temp_a1;

    temp_a1 = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    D_jetpac_8002EC30.unk794 = 0;
    switch (arg0) {
        case 0:
        case 3:
            break;
        case 1:
            func_jetpac_80028950();
            break;
        case 2:
            if (D_jetpac_8002EC30.unk78C == 1) {
                D_jetpac_8002EC30.unk794 = 3;
                temp_a1->lives -= 1;
            }
            func_jetpac_80026DC8();
            func_jetpac_8002AAD4();
            func_jetpac_80028B54(temp_a1);
            break;
        case 4:
            D_jetpac_8002F064 = 1;
            func_jetpac_80028634();
            D_jetpac_8002EC30.unk794 = 3;
            temp_a1->lives += 1;
            break;
        case 5:
            D_jetpac_8002EC30.unk790 = 0;
            break;
    }
    D_jetpac_8002EC30.unk78C = arg0;
}

void func_jetpac_800250A0(void) {
    Competitor *player;

    player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (player->level < 0) {
        player->lives--;
    }
    player->level++;
    func_jetpac_80027D64(player);
    if ((player->level & 3) == 0) {
        func_jetpac_800275F4(player);
        player->fuel_item.primary_info.unk1C = 0;
        player->unk10 = 1;
        func_jetpac_80024F9C(2);
        return;
    }
    func_jetpac_80028340(player);
    func_jetpac_80024F9C(1);
}

typedef struct {
    u16 unk0;
    s8 unk2;
    s8 unk3;
} Struct807ECDE8;

extern Struct807ECDE8 *D_global_asm_807ECDE8;
extern u8 D_jetpac_8002BA70;

void func_jetpac_80025168(Gfx **arg0) {
    u8 *temp = &D_jetpac_8002BA70;
    if (*temp) {
        D_jetpac_8002EC30.unk78C = 0;
        D_jetpac_8002EC30.unk790 = 0;
        D_jetpac_8002EC30.unk794 = 3;
        D_jetpac_8002EC30.unk348 = 1;
        D_jetpac_8002EC30.unk34C = 0;
        *temp = 0;
        D_jetpac_8002EC30.unk18 = func_global_asm_8060C6B8(0x11, 0, 0, 0);
        D_jetpac_8002EC30.unk798 = isFlagSet(0x61, FLAG_TYPE_TEMPORARY);
        if (D_jetpac_8002EC30.unk798) {
            D_jetpac_8002EC30.unk799 = 0;
        }
    }
    D_jetpac_8002BA6C = D_jetpac_8002EC30.unk790;
    D_jetpac_8002BA6C %= 60;
    D_jetpac_8002BA6C /= 30;
    D_jetpac_8002EC30.unk4 = D_jetpac_8002EC30.unk0;
    D_jetpac_8002EC30.unk0 = D_global_asm_807ECDE8->unk0;
    if (D_global_asm_807ECDE8->unk2 >= 0x1F) {
        D_jetpac_8002EC30.unk0 |= 0x100;
    }
    if (D_global_asm_807ECDE8->unk2 < -0x1E) {
        D_jetpac_8002EC30.unk0 |= 0x200;
    }
    if (D_global_asm_807ECDE8->unk3 >= 0x1F) {
        D_jetpac_8002EC30.unk0 |= 0x800;
    }
    if (D_global_asm_807ECDE8->unk3 < -0x1E) {
        D_jetpac_8002EC30.unk0 |= 0x400;
    }
    D_jetpac_8002EC30.unk8 = (D_jetpac_8002EC30.unk0 ^ D_jetpac_8002EC30.unk4) & D_jetpac_8002EC30.unk0;
    if (D_jetpac_8002EC30.unk794 < 3U) {
        D_jetpac_8002EC30.unk794 += 1;
        return;
    }
    switch (D_jetpac_8002EC30.unk78C) {
        case 0:
            func_jetpac_8002466C(arg0);
            break;
        case 1:
            func_jetpac_800248A0(arg0);
            break;
        case 2:
            func_jetpac_800248E8(arg0);
            break;
        case 3:
            func_jetpac_80024A8C(arg0);
            break;
        case 4:
            func_jetpac_80024C90(arg0);
            break;
        case 5:
            func_jetpac_80024D48(arg0);
            break;
    }
    D_jetpac_8002EC30.unk790++;
}

void func_jetpac_80025368(Competitor *arg0) {
    s32 temp_t6;
    Competitor *player;

    temp_t6 = D_jetpac_8002EC30.player_index ^ 1;
    player = &D_jetpac_8002EC30.player[temp_t6];
    if ((arg0->lives < 0) && (D_jetpac_8002EC30.unk78C != 5)) {
        if (D_jetpac_8002EC30.unk18 < arg0->current_score) {
            D_jetpac_8002EC30.unk18 = arg0->current_score;
            func_jetpac_80024A4C();
        }
        func_jetpac_80024F9C(5);
    } else {
        if (player->lives >= 0) {
            D_jetpac_8002EC30.player_index = temp_t6;
            if (player->level < 0) {
                func_jetpac_800250A0();
            } else {
                func_jetpac_80024F9C(2);
            }
        } else {
            if (arg0->lives >= 0) {
                func_jetpac_80024F9C(2);
            } else {
                func_jetpac_80024F9C(0);
            }
        }        
    }
}
