#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024000.s")

/*
extern s32 D_8076A048;
extern f32 D_807FD888;
extern s32 D_8076A088;
extern u8 D_80767CE8[];
extern u8 D_807444FC;
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

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_8002419C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024408.s")
void func_800250A0();

void func_8002463C() {
    func_80028C3C();
    func_80024390();
    func_800250A0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_8002466C.s")

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
extern JetpacPlayerStruct D_8002EC30;
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
    player->fun_ptr(player->next_item_pointer);
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

extern s32 D_8002EC48;
void func_80024A4C(void) {
    func_8060C648(0x11, 0, 0, 0, D_8002EC48);
    func_8060DEA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024A8C.s")

extern JetpacPlayerStruct D_8002EC30;

void func_80024C90(s32 arg0) {
    Competitor *player = &D_8002EC30.player[D_8002EC30.player_index];
    func_80024408();
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

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024F24.s")

extern s32 D_80770DF8[];

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

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80024F9C.s")

void func_80024F9C(u8);
void func_800275F4(Competitor *);
void func_80027D64(Competitor *);
void func_80028340(Competitor *);
extern JetpacPlayerStruct D_8002EC30;

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
        player->unk114 = 0;
        player->unk10 = 1;
        func_80024F9C(2);
        return;
    }
    func_80028340(player);
    func_80024F9C(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80025168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_0/func_80025368.s")
