#include <ultra64.h>
#include "functions.h"

typedef struct Struct807F05A8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;

    s32 unk10;
    s32 unk14;
    void *unk18;
    s32 unk1C;

    void *unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;

    void *unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;

    void *unk40;
    s32 unk44;
    void* unk48;
    s32 unk4C;

    void *unk50;
    void *unk54;
    s32 unk58;
    s32 unk5C;
} Struct807F05A8;

typedef struct Struct80767CE8 {
    Mtx unk0;
    u8 pad40[0x11B0 - 0x40];
} Struct80767CE8;

void osWritebackDCacheAll(void);
extern s32 D_805FB000; // Unsure on type
extern s32 D_805FB0D0; // Unsure on type

// .data
extern s8 D_global_asm_80744460;
extern void *D_global_asm_80744470[];
extern s8 D_global_asm_80746834;

extern UnkMQStruct D_global_asm_807659E8;
extern s32 D_global_asm_80767CD8; // Unsure on type
extern Struct80767CE8 D_global_asm_80767CE8[];
extern s32 D_global_asm_8076AF20; // Unsure on type
extern s32 D_global_asm_8076B320; // Unsure on type

extern s8 D_global_asm_807F059C[];
extern u8 *D_global_asm_807F05A4;
extern Struct807F05A8 D_global_asm_807F05A8[][2];
extern s32 D_global_asm_807F0984;

void func_global_asm_8060FFF0(void) {
    D_global_asm_807F0570[0] = &D_global_asm_807432D0;
    D_global_asm_807F0588[0] = &D_global_asm_80760C60;
    D_global_asm_807F0570[1] = &D_global_asm_80741F40;
    D_global_asm_807F0588[1] = &D_global_asm_80760840;
    D_global_asm_807F0570[2] = &D_global_asm_80741F40;
    D_global_asm_807F0588[2] = &D_global_asm_80760840;
    D_global_asm_807F0570[3] = &D_global_asm_80741F40;
    D_global_asm_807F0588[3] = &D_global_asm_80760840;
}

void func_global_asm_80610044(void *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, u8 arg5) {
    s32 temp_v0;
    Struct807F05A8 *temp_s0;

    if (D_global_asm_80744460 == 0) {
        temp_s0 = &D_global_asm_807F05A8[arg2][D_global_asm_807444FC];
        D_global_asm_807F059C[arg2] = 1;
        temp_s0->unk10 = 1;
        temp_s0->unk14 = 0;
        temp_s0->unk18 = &D_805FB000;
        temp_s0->unk1C = (s32)&D_805FB0D0 - (s32)&D_805FB000;

        temp_s0->unk20 = D_global_asm_807F0570[arg2];
        temp_s0->unk28 = D_global_asm_807F0588[arg2];
        temp_s0->unk24 = 0x1000;
        temp_s0->unk2C = 0x800;

        temp_s0->unk30 = &D_global_asm_8076AF20;
        temp_s0->unk34 = 0x400;
        temp_s0->unk38 = D_global_asm_807F05A4;
        temp_s0->unk3C = &D_global_asm_807F05A4[D_global_asm_807F0984];

        temp_s0->unk40 = arg0;
        temp_s0->unk44 = arg1 * 8;
        temp_s0->unk48 = &D_global_asm_8076B320;
        temp_s0->unk4C = 0xC00;

        temp_s0->unk0 = 0;
        temp_s0->unk54 = &D_global_asm_807659E8;
        temp_s0->unk58 = (arg2 << 0x10) | arg4;
        temp_s0->unk8 = 3;
        if (arg3) {
            temp_s0->unk8 |= 0x40;
        }
        temp_s0->unkC = D_global_asm_80744470[D_global_asm_807444FC];
        temp_s0->unk50 = &D_global_asm_80767CD8;
        if (arg5 != 0) {
            osWritebackDCacheAll();
        } else {
            osWritebackDCache(temp_s0, sizeof(Struct807F05A8));
            osWritebackDCache(arg0, arg1 * 8);
            osWritebackDCache(&D_global_asm_80767CE8[D_global_asm_807444FC], sizeof(Struct80767CE8));
        }
        osSendMesg(&D_global_asm_80767A40, temp_s0, 1);
    }
}

void func_global_asm_80610268(s32 arg0) {
    u32 sp34;

    do {
        D_global_asm_80746834 = 8;
        osRecvMesg(&D_global_asm_807659E8, &sp34, 1);
        D_global_asm_80746834 = 0;
        D_global_asm_807F059C[sp34 >> 0x10] = 0;
        sp34 &= 0xFFFF;
    } while ((s32)sp34 != arg0);
}
