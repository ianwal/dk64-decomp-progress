#include <ultra64.h>
#include "functions.h"

typedef struct JetpacStruct44 {
    f32 unk0;
    f32 unk4;
    u8 pad0[0x1C - 0x8];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} JetpacStruct44;

s32 func_jetpac_80027060(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    arg0 = MAX(arg0, arg4);
    arg1 = MAX(arg1, arg5);
    arg2 = MIN(arg2, arg6);
    arg3 = MIN(arg3, arg7);
    if (arg0 <= arg2 && arg1 <= arg3) {
        return TRUE;
    }
    return FALSE;
}

void func_jetpac_80027108(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    if (arg0 < 0.0f) {
        if (arg1 <= 0.0f) {
            *arg2 = arg0 + 256.0f;
            *arg3 = arg1 + 256.0f;
            *arg4 = arg0 + 256.0f;
            *arg5 = arg1 + 256.0f;
            return;
        }
        *arg2 = 0.0f;
        *arg3 = arg1;
        *arg4 = arg0 + 256.0f;
        *arg5 = 256.0f;
        return;
    }
    if (arg0 >= 256.0f) {
        *arg2 = arg0 - 256.0f;
        *arg3 = arg1 - 256.0f;
        *arg4 = arg0 - 256.0f;
        *arg5 = arg1 - 256.0f;
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

f32 func_jetpac_80027210(void) {
    return RandClamp(60000) / 60000.0f;
}

int func_jetpac_80027250(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    func_jetpac_80027108(arg0, arg2, &sp44, &sp40, &sp3C, &sp38);
    func_jetpac_80027108(arg4, arg6, &sp34, &sp30, &sp2C, &sp28);
    return func_jetpac_80027060(sp44, arg1, sp40, arg3, sp34, arg5, sp30, arg7)
        || func_jetpac_80027060(sp3C, arg1, sp38, arg3, sp2C, arg5, sp28, arg7);
}

int func_jetpac_80027330(f32 arg0) {
    return (arg0 >= 165.0f) && (arg0 <= 171.0f);
}

f32 func_jetpac_80027380(JetpacSpatialState *arg0) {
    return (arg0->posX + arg0->unk1C) + ((f32)(arg0->unk24 - arg0->unk1C) * 0.5);
}

f32 func_jetpac_800273C8(JetpacSpatialState *arg0) {
    return (arg0->posY + arg0->unk20) + ((f32)(arg0->unk28 - arg0->unk20) * 0.5);
}

//math.ceil?
f32 func_jetpac_80027410(f32 arg0) {
    if (arg0 >= 0.0f) {
        return (s32)(arg0 + 0.5f);
    }
    return (s32)(arg0 - 0.5f);
}
