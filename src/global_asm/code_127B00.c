#include <ultra64.h>
#include "functions.h"

typedef struct PathPoint {
    u8 pad0[2];
    s16 x;
    s16 y;
    s16 z;
    u8 speed;
    u8 pad9;
} PathPoint;

typedef struct PathItemSub {
    s16 count;
    s16 unk2;
    s16 data;
} PathItemSub;

typedef struct PathItem {
    s16 id;
    PathItemSub sub;
} PathItem;

typedef struct PathUnk {
    PathPoint *unk0;
    s16 unk4;
} PathUnk;

typedef struct PathFile {
    s16 count;
    s16 data[];
} PathFile;

typedef struct {
    Actor *unk0;
    u8 pad4[0x14 - 0x4];
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 unk17;
    s32 unk18;
    s32 unk1C;
    s8  unk20;
    s8  unk21;
} GlobalASMStruct00;

void func_global_asm_80722E48(PathFile *);

void func_global_asm_80722E00(Maps map) {
    void *paths;

    paths = getPointerTableFile(TABLE_15_PATHS, map, 1, 1);
    func_global_asm_80722E48(paths);
    func_global_asm_8066B434(paths, 0x47, 0x27);
}

extern PathUnk *D_global_asm_807FDB90[];
extern GlobalASMStruct00* D_global_asm_807FDBF8[];

void func_global_asm_80722E48(PathFile *arg0) {
    s16 *var_s2;
    s16 k;
    s16 i, j;
    s16 count;
    s16 *var_s1;
    PathPoint *arg0_dupe;

    for (i = 0; i < 0x1A; i++) {
        D_global_asm_807FDB90[i] = 0;
    }
    count = arg0->count;
    var_s2 = &arg0->data;
    for (i = 0; i < count; i++) {
        k = *var_s2++;
        D_global_asm_807FDB90[k] = malloc(sizeof(PathUnk));
        D_global_asm_807FDB90[k]->unk4 = *var_s2++;
        var_s2++;
        D_global_asm_807FDB90[k]->unk0 = malloc((D_global_asm_807FDB90[k]->unk4 + 1) * sizeof(PathPoint));
        arg0_dupe = var_s2;
        for (j = 0; j < D_global_asm_807FDB90[k]->unk4; j++) {
            D_global_asm_807FDB90[k]->unk0[j] = *(PathPoint *)arg0_dupe++;
        }
        var_s2 = arg0_dupe;
    }
    for (i = 0; i < 0x20; i++) {
        D_global_asm_807FDBF8[i] = 0;
    }
}

// Used in func_global_asm_80722FEC as well as func_global_asm_807245D8.

s32 func_global_asm_80722FEC(u8 arg0) {
    if (D_global_asm_807FDB90[arg0]) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723020.s")

void func_global_asm_80723284(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk20 = arg1;
    }
}

void func_global_asm_807232B8(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk16 = arg1;
    }
}

void func_global_asm_807232EC(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk15 = arg1;
    }
}

void func_global_asm_80723320(s32 arg0, s32 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk18 = arg1;
    }
}

void func_global_asm_8072334C(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk21 = arg1;
    }
}

void func_global_asm_80723380(s32 arg0, u8 arg1) {
    if (arg0 != -1 && D_global_asm_807FDBF8[arg0]) {
        D_global_asm_807FDBF8[arg0]->unk14 = arg1;
    }
}

void func_global_asm_807233B4(Actor *arg0) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FDBF8[i] != NULL) {
            if (arg0 == D_global_asm_807FDBF8[i]->unk0) {
                func_global_asm_80723428(i);
            }
        }
    }
}

void func_global_asm_80723428(s32 arg0) {
    if (arg0 == -1 || D_global_asm_807FDBF8[arg0]) {
        free(D_global_asm_807FDBF8[arg0]);
        D_global_asm_807FDBF8[arg0] = NULL;
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_807238D4.s")

u8 func_global_asm_80723C98(s32 arg0) {
    if (arg0 == -1 || !D_global_asm_807FDBF8[arg0]) {
        return 0;
    }
    return D_global_asm_807FDBF8[arg0]->unk21;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723CCC.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80723F88.s")

f32 func_global_asm_80724308(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, f32 arg5);

void func_global_asm_80724154(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 *arg4, f32 *arg5) {
    f32 test;
    f32 var_f22;
    f32 highest;
    s32 var_s0;
    s32 i;

    highest = 999999.0f;
    var_s0 = *arg4;
    var_f22 = *arg5 - 0.5;
    i = 0x14;
    if (var_f22 < 0.0) {
        if (var_s0 > 0) {
            var_s0--;
            var_f22 += 1.0f;
        } else {
            var_f22 = 0.0f;
        }
    }
    while (i--) {
        test = func_global_asm_80724308(arg0, arg1, arg2, arg3, var_s0, var_f22);
        if (test < highest) {
            *arg4 = var_s0;
            *arg5 = var_f22;
            highest = test;
        }
        var_f22 += 0.05;
        if (var_f22 >= 1.0f && var_s0 < D_global_asm_807FDB90[arg0]->unk4) {
            var_s0++;
            var_f22 -= 1.0f;
        } else if (var_f22 >= 1.0f) {
            var_f22 = 1.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_127B00/func_global_asm_80724308.s")

s16 func_global_asm_807245D8(s32 arg0) {
    return D_global_asm_807FDB90[arg0]->unk4;
}
