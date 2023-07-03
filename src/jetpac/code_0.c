#include <ultra64.h>
#include "functions.h"



#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024000.s")

/*
extern s32 D_8076A048;
extern f32 D_807FD888;
extern s32 D_8076A088;
extern u8 D_80767CE8[];
extern u8 D_8076A0B1;
extern s32 D_8076A08C;
extern s32 D_8076A050[];

// TODO: Pretty close
void func_80024000(void) {
    s32 sp2C;
    void *sp28;
    s32 temp_a0;
    s32 temp_t5;
    u8 temp_t1;

    func_8060A9BC();
    func_80610044(D_8076A050[D_807444FC], D_8076A088, 3, 1, 0x4D2, 1);
    temp_t1 = D_807444FC ^ 1;
    temp_t5 = (temp_t1 & 0xFF) * 0x11B0;
    D_807444FC = temp_t1;
    object_timer++;
    D_8076A048 = D_80767CE8[temp_t5];
    func_8060AC7C();
    if ((D_8076A0B1 & 1) && (D_807FD888 == 31.0f)) {
        sp2C = D_8076A050[D_807444FC];
    } else {
        func_8002419C(D_8076A048, &sp2C);
    }
    temp_a0 = func_80704484(sp2C, 0);
    if (is_cutscene_active != 4) {
        sp28 = D_8076A048 + 0xDB0;
        func_805FE71C(temp_a0, D_807444FC, &D_8076A088, 0);
        func_805FE7B4(sp28, D_8076A048, &D_8076A08C, 1);
    } else {
        func_805FE71C(temp_a0, D_807444FC, &D_8076A088, 1);
    }
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_8002419C.s")

extern JetpacPlayerStruct D_8002EC30;

void func_80024390(void) {
    s32 playerIndex;
    Competitor *player;

    for (playerIndex = 0; playerIndex < 2; playerIndex++) {
        player = &D_8002EC30.player[playerIndex];
        player->level = -1;
        player->current_score = 0;
        if (playerIndex < D_8002EC30.unk348) {
            if (D_8002EC30.unk798 != 0) {
                player->lives = 3;
            } else {
                player->lives = 5;
            }
        } else {
            player->lives = -1;
        }
    }
    D_8002EC30.player_index = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024408.s")

extern s32 D_8002EC48;
extern s32 D_8002BA6C;
extern s32 D_8002EF74;
extern u8 D_8002E9D0;
extern u8 D_8002E9D4;
extern u8 D_8002E9D8;
extern u8 D_8002E9DC;
extern u8 D_8002E9E0;
extern s32 D_8002EC50;
extern u8 D_8002E9E8;
extern u8 D_8002E9F0;
extern s32 D_8002EDE4;

Gfx **func_8002AE00(Gfx**);
void func_8002AE94(u8 arg0, u8 arg1, u8 arg2, u8 arg3);

// TODO: Arg2 might be s16... Causes a mismatch in func_80024D48.
void func_8002AEFC(Gfx **arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4);

/*
// TODO: Annoyingly close, just weird offset nonsense on the lives read
void func_80024408(Gfx **arg0) {
    s32 sp60[20];
    Competitor *player;
    s32 temp_s0;
    s32 playerIndex;

    temp_s0 = func_80026FE0() & D_8002BA6C;
    func_8002AE00(arg0);
    func_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_8002AEFC(arg0, &D_8002E9D0, 0x38, 0x18, temp_s0 != 0 && D_8002EF74 == 0);
    for (playerIndex = 0; playerIndex < 2; playerIndex++) {
        player = &D_8002EC30.player[playerIndex];
        if (D_8002EC30.player[playerIndex].lives > 0) {
            func_800031E0(&sp60, &D_8002E9D4, D_8002EC30.player[playerIndex].lives);
            func_8002AEFC(arg0, &sp60, (playerIndex * 0x70) + 0x60, 0x18, 0);
        }
    }
    func_8002AEFC(arg0, &D_8002E9D8, 0xF8, 0x18, temp_s0 != 0 && D_8002EF74 == 1);
    func_8002AE94(0, 0xFF, 0xFF, 0xFF);
    func_8002AEFC(arg0, &D_8002E9DC, 0x98, 0x18, 0);
    func_8002AE94(0xFF, 0xFF, 0, 0xFF);
    func_800031E0(&sp60, &D_8002E9E0, D_8002EC50);
    func_8002AEFC(arg0, &sp60, 0x28, 0x20, 0);
    func_800031E0(&sp60, &D_8002E9E8, D_8002EC48);
    func_8002AEFC(arg0, &sp60, 0x88, 0x20, 0);
    func_800031E0(&sp60, &D_8002E9F0, D_8002EDE4);
    func_8002AEFC(arg0, &sp60, 0xE8, 0x20, 0);
}
*/

void func_800250A0();

void func_8002463C() {
    func_80028C3C();
    func_80024390();
    func_800250A0();
}

extern s32 D_8002E9F8;
extern s32 D_8002EA10;
extern s32 D_8002EA24;
extern s32 D_8002EA38;
extern s32 D_8002EA48;
extern s32 D_8002EA60;
extern s32 D_8002EA70;

void func_8002466C(Gfx **arg0) {
    s32 sp28[10]; // TODO: Datatype

    func_80024408();
    func_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_8002AEFC(arg0, &D_8002E9F8, 0x50, 0x38, 0);
    func_8002AEFC(arg0, &D_8002EA10, 0x50, 0x50, D_8002BA6C != 0 && D_8002EC30.unk348 == 1);
    func_8002AEFC(arg0, &D_8002EA24, 0x50, 0x60, D_8002BA6C != 0 && D_8002EC30.unk348 == 2);
    func_8002AEFC(arg0, &D_8002EA38, 0x50, 0x70, D_8002BA6C != 0 && D_8002EC30.unk34C == 0);
    func_8002AEFC(arg0, &D_8002EA48, 0x50, 0x80, D_8002BA6C != 0 && D_8002EC30.unk34C != 0);
    func_8002AEFC(arg0, &D_8002EA60, 0x50, 0xB8, 0);
    func_800031E0(&sp28, &D_8002EA70, 0x7F);
    func_8002AEFC(arg0, &sp28, 0x20, 0xD8, 0);
    if (D_8002EC30.unk798 != 0) {
        if (!(D_8002EC30.unk8 & 0x1000) && (D_8002EC30.unk799 < 0x78)) {
            D_8002EC30.unk799 = D_8002EC30.unk799 + 1;
            return;
        }
        D_8002EC30.unk799 = 0;
        func_8002463C();
        return;
    }
    if (D_8002EC30.unk8 & 0x4000) {
        D_8002EC30.unk348 = D_8002EC30.unk348 ^ 3;
    }
    if (D_8002EC30.unk8 & 0x8000) {
        D_8002EC30.unk34C = D_8002EC30.unk34C ^ 1;
    }
    if (D_8002EC30.unk8 & 0x1000) {
        func_8002463C();
    }
}

void func_800248A0(Gfx **arg0) {
    func_80024408(arg0);
    func_800286D0();
    func_800255D4(arg0);
    func_80028E88();
    func_800289EC();
    func_80025904(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_800248E8.s")

/*
// TODO: Doable
void func_800248E8(s32 arg0) {
    void *sp1C;
    int score;
    void *temp_a0;
    Competitor *player;
    void *temp_v0_2;

    player = &D_8002EC30.player[D_8002EC30.player_index];
    score = player->current_score;
    if (score >= 1000000) {
        player->current_score = score - 1000000;
    }
    func_80024408(arg0, &D_8002EC30);
    func_80026D48();
    func_80026CEC();
    player->fun_ptr(&player->next_item_pointer);
    temp_a0 = player + (player->unk10 * 0x4C);
    temp_a0->unk58(temp_a0 + 0x14);
    func_8002ABDC();
    func_800255D4(arg0);
    func_80028E88();
    func_80026AB0();
    func_8002AD8C();
    func_80028544();
    func_800285DC();
    func_80026CA4();
    func_80025904(arg0);
    if (func_80026FE0()) {
        D_8002EC30.unk44C++;
    }
    if (D_8002EC30.unk8 & 0x1000) {
        D_8002EC30.unk78C = 3;
        D_8002EC30.unkC = 1;
    }
}
*/

void func_80024A4C(void) {
    func_8060C648(0x11, 0, 0, 0, D_8002EC48);
    func_8060DEA8();
}

extern s32 D_8002BA6C;
extern s32 D_8002EA94; // TODO: Datatype
extern s32 D_8002EA9C; // TODO: Datatype
extern s32 D_8002EAAC; // TODO: Datatype

void func_80024A8C(Gfx **arg0) {
    enum map_e var_a0;

    func_80024408();
    func_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_8002AEFC(arg0, &D_8002EA94, 0x88, 0x70, D_8002BA6C != 0 && D_8002EC30.unkC == 1);
    func_8002AEFC(arg0, &D_8002EA9C, 0x68, 0x80, D_8002BA6C != 0 && D_8002EC30.unkC == 2);
    func_8002AEFC(arg0, &D_8002EAAC, 0x70, 0x90, D_8002BA6C != 0 && D_8002EC30.unkC == 0);
    if (D_8002EC30.unk8 & 0xE000) {
        switch (D_8002EC30.unkC) {
            default:
            case 0:
                if (D_8002EC30.unk798 != 0) {
                    var_a0 = MAP_CRANKYS_LAB;
                } else {
                    var_a0 = MAP_MAIN_MENU;
                }
                func_805FF378(var_a0, 0);
                break;
            case 1:
                D_8002EC30.unk78C = 2;
                break;
            case 2:
                if (D_8002EC30.unk18 != 0) {
                    func_8060C8AC(1);
                    D_8002EC30.unk18 = func_8060C6B8(0x11, 0, 0, 0);
                    func_80024A4C();
                    break;
                }
                break;
        }
    }
    if (D_8002EC30.unk8 & 0x400) {
        D_8002EC30.unkC++;
    }
    if (D_8002EC30.unk8 & 0x800) {
        D_8002EC30.unkC--;
    }
    if (D_8002EC30.unkC >= 3) {
        D_8002EC30.unkC = 0;
    }
    if (D_8002EC30.unkC < 0) {
        D_8002EC30.unkC = 2;
    }
}

void func_80024C90(s32 arg0) {
    Competitor *player = &D_8002EC30.player[D_8002EC30.player_index];
    func_80024408(arg0);
    func_80026CEC();
    player->fun_ptr(&player->next_item_pointer);
    func_800286D0();
    func_8002ABDC();
    func_800255D4(arg0);
    func_80028E88();
    func_8002AD8C();
    func_800289EC();
    func_800285DC();
    func_80026CA4();
    func_80025904(arg0);
}

extern s32 D_8002EABC;
extern s32 D_8002EAD4;
void func_80024F9C(u8);
void func_800275F4(Competitor *);
void func_80027D64(Competitor *);
void func_80028340(Competitor *);
void func_80025368(Competitor *arg0);

void func_80024D48(Gfx **arg0) {
    s32 sp4C;
    s32 sp2C[8];

    sp4C = 7;
    func_80024408();
    if ((D_8002EC30.unk798 != 0) && (isFlagSet(0x62, FLAG_TYPE_TEMPORARY) != 0)) {
        func_800031E0(&sp2C, &D_8002EABC);
        sp4C = 5;
    } else {
        func_800031E0(&sp2C, &D_8002EAD4, D_8002EC30.player_index + 1);
    }
    func_8002AE94(0xFF, 0xFF, 0xFF, 0xFF);
    func_8002AEFC(arg0, &sp2C, (sp4C * 8) + 0x20, 0x88, 0);
    if (D_8002EC30.unk790 >= 0x79U) {
        if (D_8002EC30.unk798 != 0) {
            if (D_8002EC30.unk799 == 0) {
                D_8002EC30.unk799 = 1;
                func_805FF378(MAP_CRANKYS_LAB, 0);
            }
        } else {
            func_80025368(&D_8002EC30.player[D_8002EC30.player_index]);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024E70.s")

extern s32 D_80770DF8[];
extern s32 D_8076D1F8;
extern s16 D_8002BA52[];

void func_80737638(s32, s16, u16, s32, f32, s32, s32);
void func_80737924(s32);

/*
// TODO: Pretty close...
void func_80024E70(s32 arg0) {
    s32 i;
    s32 temp_a0;

    if (arg0 < 7) {
        while (i < 7) {
            temp_a0 = D_80770DF8[arg0];
            if (temp_a0 != 0) {
                func_80737924(temp_a0);
            }
            i++;
        }
    }
    func_80737638(D_8076D1F8, D_8002BA52[arg0], 0x7FFF, 0x3F, 1.0f, 0, &D_80770DF8[arg0]);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024F24.s")

/*
// It's not putting arg1 on the stack, not sure why
void func_80024F24(s32 arg0, s32 arg1) {
    if (D_80770DF8[arg0]) {
        func_80737AC4(D_80770DF8[arg0], 0x10, arg1);
    }
}
*/

void func_80024F64(s32 arg0) {
    s32 temp_a1;

    temp_a1 = D_80770DF8[arg0];
    if (temp_a1 != 0) {
        func_80737924(temp_a1);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024F9C.s")

void func_800250A0(void) {
    Competitor *player;

    player = &D_8002EC30.player[D_8002EC30.player_index];
    if (player->level < 0) {
        player->lives--;
    }
    player->level++;
    func_80027D64(player);
    if ((player->level & 3) == 0) {
        func_800275F4(player);
        player->unk14[3].unk1C = 0;
        player->unk10 = 1;
        func_80024F9C(2);
        return;
    }
    func_80028340(player);
    func_80024F9C(1);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80025168.s")

void func_80025368(Competitor *arg0) {
    s32 temp_t6;
    Competitor *player;

    temp_t6 = D_8002EC30.player_index ^ 1;
    player = &D_8002EC30.player[temp_t6];
    if ((arg0->lives < 0) && (D_8002EC30.unk78C != 5)) {
        if (D_8002EC30.unk18 < arg0->current_score) {
            D_8002EC30.unk18 = arg0->current_score;
            func_80024A4C();
        }
        func_80024F9C(5);
    } else {
        if (player->lives >= 0) {
            D_8002EC30.player_index = temp_t6;
            if (player->level < 0) {
                func_800250A0();
            } else {
                func_80024F9C(2);
            }
        } else {
            if (arg0->lives >= 0) {
                func_80024F9C(2);
            } else {
                func_80024F9C(0);
            }
        }        
    }
}
