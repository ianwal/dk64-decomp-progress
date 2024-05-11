#include <ultra64.h>
#include "functions.h"

extern void func_global_asm_8071CDE0(void* arg0, s32 arg1);

void func_global_asm_806A5DF0(s32, f32, f32, f32, s32, s32, s16, s32);

void func_boss_80027840(u8 *arg0) {
    s16 i;
    Struct80027840 *var_v1;

    if (D_global_asm_807FDC98->unk20 != NULL) {
        free(D_global_asm_807FDC98->unk20);
    }
    D_global_asm_807FDC9C->unk11 = *arg0;
    D_global_asm_807FDC98->unk20 = malloc(*arg0 * sizeof(Struct80027840));
    var_v1 = D_global_asm_807FDC98->unk20;
    for (i = 0; i < *arg0; i++, var_v1++) {
        var_v1->unk0 = arg0[i + 1];
        var_v1->unk1 = 0;
    }
}

typedef struct BossStruct2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} BossStruct2;

void func_boss_800278F4(BossStruct2 *arg0, f32 arg1, s16 arg2, s16 arg3) {
    arg0->unkC += ((arg2 - arg0->unkC) * arg1);
    arg0->unk8 += ((arg3 - arg0->unk8) * arg1);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s8 unk14;
    u8 unk15;
} Struct80027A30_arg0;

void func_boss_80027950(Struct80027A30_arg0 *arg0, u8 *arg1) {
    u8 temp_s3;
    u8 temp_v1;

    temp_s3 = D_global_asm_807FDC90->unk25;
    do {
        D_global_asm_807FDC90->unk25 = arg1[arg0->unk15] + (((rand() >> 0xF) % 65536) % (((arg1[arg0->unk15 + 1] - arg1[arg0->unk15]) + 1)));
    } while (D_global_asm_807FDC90->unk25 == temp_s3);
    arg0->unk15 += 2;
}

void func_boss_80027A30(Struct80027A30_arg0 *arg0, u8 *arg1) {
    f32 dz;
    f32 dy;
    f32 dx;
    s32 temp_f6;
    s32 var_s1;
    u8 temp_a0;
    s16 i;

    var_s1 = 0;
    for (i = arg1[arg0->unk15]; i <= arg1[arg0->unk15 + 1]; i++) {
        temp_a0 = D_global_asm_807FDC98->unk20[i].unk0;
        dz = current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[temp_a0].unk4;
        dx = current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[temp_a0].unk0;
        dy = current_actor_pointer->y_position - D_global_asm_807FDCA0->unk14[temp_a0].unk2;
        temp_f6 = sqrtf((dz * dz) + ((dx * dx) + (dy * dy)));
        if (var_s1 < temp_f6) {
            var_s1 = temp_f6;
            D_global_asm_807FDC90->unk25 = i;
        }
    }
    arg0->unk15 += 2;
}

// Jumptable, 2224 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_boss_80027BA8.s")

void func_boss_80028458(void) {
    func_global_asm_805FF8F8();
}

void func_boss_80028478(u16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5) {
    s16 i;
    
    playSong(0x36, 1.0f);
    if (isFlagSet(arg0, FLAG_TYPE_PERMANENT)) {
        func_boss_80028458();
        return;
    }
    for (i = 0; i < 6; i++) {
        func_global_asm_8071498C(&func_global_asm_8071CDE0);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714950((s32)D_global_asm_807FDC94);
        drawSpriteAtPosition(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3], 1.8f, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position + D_global_asm_807FDC94->unk15E, D_global_asm_807FDC94->z_position);
    }
    func_global_asm_806A5DF0(0x48, arg1, arg2, arg3, arg4, arg5, arg0, 0);
}

void func_boss_80028680() {
    func_global_asm_806A2A10(-0x7F83, 0xD2, 0xB4);
    func_global_asm_806A2B08(current_actor_pointer->unk11C);
}

extern u8 D_global_asm_80750AD4;

Gfx *func_boss_800286B8(Gfx *dl, s32 arg1) {
    f32 sp90[4][4];
    f32 sp50[4][4];
    Mtx *sp4C;
    char sp3C[13];

    sp4C = malloc(sizeof(Mtx));
    func_global_asm_8061134C(sp4C);
    guScaleF(&sp90, 0.6f, 0.6f, 1.0f);
    guTranslateF(&sp50, 100.0f, (character_change_array->unk276 * 4) - 0x3C, 0);
    guMtxCatF(&sp90, &sp50, &sp90);
    guMtxF2L(&sp90, sp4C);
    gSPMatrix(dl++, sp4C, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    sprintf(&sp3C, "ROUND %d", D_global_asm_80750AD4);
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++ , G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    dl = func_global_asm_8070068C(dl++);
    return printStyledText(dl, 1, 0, 0, &sp3C, 0);
}

void func_boss_80028818() {

}

void func_boss_80028820() {
    // K. Rool Tiny Phase Toes Complete
    setFlag(0x51, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x52, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x53, FALSE, FLAG_TYPE_TEMPORARY);
    setFlag(0x54, FALSE, FLAG_TYPE_TEMPORARY);
}

// Jumptable, 2140 bytes of code
#pragma GLOBAL_ASM("asm/nonmatchings/boss/code_3840/func_boss_80028878.s")

void func_boss_800290D4(u8 arg0) {
    if (arg0) {
        func_global_asm_8066EA64(current_actor_pointer, 2);
        func_global_asm_8066EA64(current_actor_pointer, 3);
    } else {
        func_global_asm_8066EA90(current_actor_pointer, 2);
        func_global_asm_8066EA90(current_actor_pointer, 3);
    }
}

typedef struct BossStruct1 {
    u8 unk0; // Map
    u8 unk1;
    s16 unk2; // Flag
    u8 unk4;
    u8 unk5;
} BossStruct1;

extern BossStruct1 D_boss_800359D0[];

void func_boss_80029140(s16* arg0) {
    s16 i = 0;
    while (D_boss_800359D0[i].unk0 != 0 && D_boss_800359D0[i].unk0 != current_map) {
        i++;
    }
    if (D_boss_800359D0[i].unk0 != 0 && D_boss_800359D0[i].unk4 == *arg0) {
        if (isFlagSet(D_boss_800359D0[i].unk2, FLAG_TYPE_TEMPORARY)) {
            *arg0 = D_boss_800359D0[i].unk5;
        }
    }
}

void func_boss_8002920C(void) {
    s16 i = 0;
    while (D_boss_800359D0[i].unk0 != 0 && D_boss_800359D0[i].unk0 != current_map) {
        i++;
    }
    if (D_boss_800359D0[i].unk0 != 0) {
        setFlag(D_boss_800359D0[i].unk2, TRUE, FLAG_TYPE_TEMPORARY);
    }
}
