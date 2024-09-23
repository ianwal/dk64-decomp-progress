#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    f32 unk10;
    s16 unk14;
    s16 unk16;
    f32 unk18;
    f32 unk1C;
} Temp20Big;

extern Temp20Big D_global_asm_80748BA0[];
extern u8 D_global_asm_807F9440[];
extern s32 D_global_asm_807F9448;

void func_global_asm_80664CB0(s16 arg0) {
    s32 i;
    s32 max = 0xD;

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

extern SpriteData D_global_asm_8071FF18; // Sprite
extern SpriteData D_global_asm_8072140C; // Sprite

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
            if (sqrtf((dz * dz) + ((dx * dx) + (dy * dy))) < temp_s0->unk14) {
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
