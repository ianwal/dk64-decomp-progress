#include "common.h"

typedef struct {
    u8 unk0;
    //u8 pad1;
    s16 unk2; // x
    s16 unk4; // y
    s16 unk6; // z
    s16 unk8; // x2
    s16 unkA; // y2
    s16 unkC; // z2
    // s16 padE;
    f32 unk10; // gap
    s16 unk14; // distance
    // s16 pad16;
    f32 unk18; // scale
    f32 unk1C; // scale2
} Temp20Big;

// .data
static Temp20Big D_global_asm_80748BA0[13] = {
    // ?   x     y    z     x2    y2   z2    gap    dist  scale scale
    {0xB0, 1985, 25,  1136, 1985, 25,  1212, 0.25f, 1000, 2.0f, 2.0f},
    {0xBD, 296,  51,  289,  313,  51,  257,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 414,  51,  159,  440,  51,  141,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 869,  51,  154,  900,  51,  167,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 999,  51,  275,  1017, 51,  304,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 1009, 51,  733,  994,  51,  759,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 887,  51,  857,  857,  51,  876,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 428,  51,  863,  400,  51,  851,  0.25f, 400,  1.0f, 1.0f},
    {0xBD, 302,  51,  745,  284,  51,  718,  0.25f, 400,  1.0f, 1.0f},
    {0x22, 3020, 490, 1087, 2930, 490, 1071, 0.25f, 800,  2.0f, 2.0f},
    {0x48, 3086, 40,  1342, 2968, 40,  1402, 0.25f, 800,  2.0f, 2.0f},
    {0x48, 2345, 50,  2264, 2286, 50,  2088, 0.15f, 800,  2.0f, 2.0f},
    {0x57, 984,  370, 260,  986,  370, 280,  0.25f, 700,  1.0f, 1.0f},
};

extern u8 D_global_asm_807F9440[];
extern s32 D_global_asm_807F9448;

void func_global_asm_80664CB0(s16 arg0) {
    s32 i;
    s32 max = 13;

    D_global_asm_807F9448 = 0;
    for (i = 0; i < max; i++) {
        if (arg0 == D_global_asm_80748BA0[i].unk0) {
            if (D_global_asm_807F9448 != 8) {
                D_global_asm_807F9440[D_global_asm_807F9448] = i;
                D_global_asm_807F9448++;
            }
        }
    }
}

void func_global_asm_80664D20(void) {
    Temp20Big *temp_s0;
    f32 dz;
    f32 positionOffset;
    f32 dy;
    f32 dx;
    s32 i;
    u8 j;

    if (cc_number_of_players < 2) {
        for (i = 0; i < D_global_asm_807F9448; i++) {
            j = D_global_asm_807F9440[i];
            temp_s0 = &D_global_asm_80748BA0[j];
            dz = character_change_array->unk224 - temp_s0->unk6;
            dx = character_change_array->unk21C - temp_s0->unk2;
            dy = character_change_array->unk220 - temp_s0->unk4;
            if (sqrtf(SQ(dz) + (SQ(dx) + SQ(dy))) < temp_s0->unk14) {
                if ((object_timer % 18U) == 0) {
                    for (positionOffset = 0.0f; positionOffset <= 1.0; positionOffset += temp_s0->unk10) {
                        func_global_asm_807149B8(1);
                        func_global_asm_80714998(3);
                        changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
                        func_global_asm_80714A28(4);
                        func_global_asm_8071498C(func_global_asm_80717B64);
                        func_global_asm_807149FC(2);
                        func_global_asm_80714944((rand() % 10000) % 6);
                        func_global_asm_807149A8(temp_s0->unk14);
                        drawSpriteAtPosition(
                            &D_global_asm_8072140C,
                            temp_s0->unk18,
                            ((temp_s0->unk8 - temp_s0->unk2) * positionOffset) + temp_s0->unk2,
                            ((temp_s0->unkA - temp_s0->unk4) * positionOffset) + temp_s0->unk4,
                            ((temp_s0->unkC - temp_s0->unk6) * positionOffset) + temp_s0->unk6
                        );
                    }
                }
                if ((object_timer % 10U) == 0) {
                    func_global_asm_807149B8(1);
                    func_global_asm_80714998(3);
                    changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
                    func_global_asm_80714A28(4);
                    func_global_asm_8071498C(func_global_asm_80717D4C);
                    func_global_asm_80714950(-0xAA);
                    func_global_asm_807149A8(temp_s0->unk14);
                    positionOffset = ((rand() % 10000) % 1000) / 1000.0;
                    drawSpriteAtPosition(
                        &D_global_asm_8071FF18,
                        temp_s0->unk1C,
                        ((temp_s0->unk8 - temp_s0->unk2) * positionOffset) + temp_s0->unk2,
                        ((temp_s0->unkA - temp_s0->unk4) * positionOffset) + temp_s0->unk4,
                        ((temp_s0->unkC - temp_s0->unk6) * positionOffset) + temp_s0->unk6
                    );
                }
            }
        }
    }
}
