#include <ultra64.h>
#include "functions.h"


void func_8061134C(s32);
s32 func_8063367C(s32, s32, s32);
s32 func_80671D64(s32, s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s32 unk18;
} Unk34;

typedef struct {
    s32 unk0; // Used
    u8 unk4; // Used
    u8 unk5;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10[4];
    s32 unk20[4];
    s32 unk30;
    Unk34 *unk34;
} GlobalASMStruct82; // TODO: Might be D_807FDCC0

extern s32 D_807FDCC0;

void func_8072ED90(void) {
    D_807FDCC0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072ED9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072EE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072EE7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072EF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072F09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072F120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072F230.s")

u8 func_8072F4A8(Actor *arg0, u8 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s16 model2ArrayIndex;
    u8 phi_t0;

    phi_t0 = FALSE;
    switch (arg1) {
        case 0:
            *arg2 = arg0->x_position;
            *arg3 = arg0->y_position;
            *arg4 = arg0->z_position;
            break;
        case 1:
        case 2:
            model2ArrayIndex = func_80659470(arg0);
            *arg2 = D_807F6000[model2ArrayIndex].x_position;
            *arg3 = D_807F6000[model2ArrayIndex].y_position;
            *arg4 = D_807F6000[model2ArrayIndex].z_position;
            if (D_807F6000[model2ArrayIndex].unk24->unk0 & 1) {
                phi_t0 = TRUE;
            }
            break;
    }
    return phi_t0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072F59C.s")

s32 func_8072F8D4(GlobalASMStruct82 *arg0, s32 arg1, s16 arg2) {
    s16 model2ArrayIndex;
    s32 angle;

    if (!arg0->unk4) {
        return TRUE;
    }
    model2ArrayIndex = func_80659470(arg0->unk0);
    switch (D_807F6000[model2ArrayIndex].object_type) {
        case 0xC9: // Ladder
        case 0xCA: // Ladder
        case 0x1CB: // Ladder (Fungi)
        case 0x1F7: // Ladder (Fungi)
        case 0x1F8: // Ladder (Fungi)
            break;
        default:
            return TRUE;
    }
    angle = D_807F6000[model2ArrayIndex].y_rotation * 4096.0f / 360.0f;
    if (func_806725E4((arg0->unk34[arg1].unk10 + angle) & 0xFFF, (arg0->unk34[arg1].unk14 + angle) & 0xFFF, arg2, 0)) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072FA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072FCC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072FDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_8072FE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_807300BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_80730408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_80730AEC.s")

void func_80730D60(s32 arg0, u8 arg1, u8 arg2, u8 arg3, s32 *arg4, s32 *arg5) {
    switch (arg1) {
        case 0:
            *arg4 = func_80671D64(arg0, arg2);
            *arg5 = func_80671D64(arg0, arg3);
            break;
        case 1:
        case 2:
            *arg4 = func_8063367C(arg0, 1, arg2);
            func_8061134C(*arg4);
            *arg5 = func_8063367C(arg0, 1, arg3);
            func_8061134C(*arg5);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_80730E18.s")
