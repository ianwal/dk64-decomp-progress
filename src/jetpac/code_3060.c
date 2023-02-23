#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 func_80027060(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    arg0 = MAX(arg0, arg4);
    arg1 = MAX(arg1, arg5);
    arg2 = MIN(arg2, arg6);
    arg3 = MIN(arg3, arg7);
    if (arg0 <= arg2 && arg1 <= arg3) {
        return 1;
    }
    return 0;
}

void func_80027108(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;

    if (arg0 < 0.0f) {
        if (arg1 <= 0.0f) {
            temp_f0 = arg0 + 256.0f;
            temp_f2 = arg1 + 256.0f;
            *arg2 = temp_f0;
            *arg3 = temp_f2;
            *arg4 = temp_f0;
            *arg5 = temp_f2;
            return;
        }
        *arg2 = 0.0f;
        *arg3 = arg1;
        *arg4 = arg0 + 256.0f;
        *arg5 = 256.0f;
        return;
    }
    if (arg0 >= 256.0f) {
        temp_f0_2 = arg0 - 256.0f;
        temp_f2_2 = arg1 - 256.0f;
        *arg2 = temp_f0_2;
        *arg3 = temp_f2_2;
        *arg4 = temp_f0_2;
        *arg5 = temp_f2_2;
        return;
    }
    if (arg1 > 256.0f) {
        *arg2 = 0.0f;
        *arg3 = arg1 - 256.0f;
        *arg4 = arg0;
        *arg5 = 256.0f;
        return;
    }
    *arg2 = arg0;
    *arg3 = arg1;
    *arg4 = arg0;
    *arg5 = arg1;
}

extern f32 D_8002EB70;

f32 func_80027210(void) {
    return (f32) ((s32) (rand() >> 0xF) % 60000) / D_8002EB70;
}

#pragma GLOBAL_ASM("asm/nonmatchings/jetpac/code_3060/func_80027250.s")

int func_80027330(f32 arg0) {
    return (arg0 >= 165.0f) && (arg0 <= 171.0f);
}

typedef struct JetpacStruct44 {
    f32 unk0;
    f32 unk4;
    u8 pad0[0x1C - 0x8];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} JetpacStruct44;

f32 func_80027380(JetpacStruct44 *arg0) {
    return (arg0->unk0 + arg0->unk1C) + ((f32)(arg0->unk24 - arg0->unk1C) * 0.5);
}


f32 func_800273C8(JetpacStruct44 *arg0) {
    return (arg0->unk4 + arg0->unk20) + ((f32)(arg0->unk28 - arg0->unk20) * 0.5);
}

//math.ceil?
f32 func_80027410(f32 arg0) {
    if (arg0 >= 0.0f) {
        return (f32) (s32) (arg0 + 0.5f);
    }
    return (f32) (s32) (arg0 - 0.5f);
}
