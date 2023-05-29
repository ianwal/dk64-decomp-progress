#include <ultra64.h>
#include "functions.h"


void func_8061134C(s32);
s32 func_8063367C(s32, s32, s32);
s32 func_80671D64(s32, s32);

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
} Unk34;

typedef struct GlobalASMStruct82 GlobalASMStruct82;

struct GlobalASMStruct82 {
    Actor *unk0; // Used
    u8 unk4; // Used
    u8 unk5;
    u8 unk6;
    u8 unk7;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    f32 unk14;
    s8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s8 unk30;
    s8 unk31;
    s8 unk32;
    s8 unk33;
    Unk34 *unk34;
    GlobalASMStruct82 *next;
};

extern GlobalASMStruct82 *D_807FDCC0;

void func_8072ED90(void) {
    D_807FDCC0 = NULL;
}

void func_8072ED9C(Actor *arg0, u8 arg1, u8 arg2) {
    s32 found;
    GlobalASMStruct82 *current;

    current = D_807FDCC0;
    found = FALSE;
    while (current != NULL && !found) {
        if (arg0 == current->unk0 && current->unk5 == arg1) {
            found = TRUE;
        } else {
            current = current->next;
        }
    }
    if (found) {
        current->unk31 = arg2;
    }
}

void func_8072EE0C(Actor *arg0, u8 arg1, u8 arg2) {
    s32 found;
    GlobalASMStruct82 *current;

    current = D_807FDCC0;
    found = FALSE;
    while (current != NULL && !found) {
        if (arg0 == current->unk0 && current->unk5 == arg1) {
            found = TRUE;
        } else {
            current = current->next;
        }
    }
    if (found) {
        current->unk18 = arg2;
    }
}

void func_8072EE7C(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, u8 argB, f32 argC, f32 argD, u8 argE) {
    GlobalASMStruct82 **var_t0;
    GlobalASMStruct82 *current;
    GlobalASMStruct82 *sp18;

    var_t0 = &D_807FDCC0;
    current = D_807FDCC0;
    while (current != NULL) {
        var_t0 = &current->next;
        current = current->next;
    }
    current = malloc(sizeof(GlobalASMStruct82));
    *var_t0 = current;
    current->unk0 = arg0;
    current->unk4 = arg1;
    current->unk5 = arg2;
    current->unk6 = arg3;
    current->unk7 = arg4;
    current->unk8 = arg5;
    current->unkC = arg6;
    current->unk14 = arg7;
    current->unk1C = arg8;
    current->unk20 = arg9;
    current->unk24 = argA;
    current->unk18 = argB;
    current->unk28 = argC;
    current->unk2C = argD;
    current->unk30 = argE;
    current->unk31 = 1;
    current->next = NULL;
    current->unk34 = malloc(arg4 * sizeof(Unk34));
}

void func_8072EF7C(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8, s16 arg9, s16 argA, s16 argB, s16 argC) {
    GlobalASMStruct82 *current;
    s32 found;

    current = D_807FDCC0;
    found = FALSE;
    while (current != NULL && !found) {
        if (arg0 == current->unk0 && current->unk5 == arg1) {
            found = TRUE;
        } else {
            current = current->next;
        }
    }
    if (found) {
        current->unk34[arg2].unk0 = arg3;
        current->unk34[arg2].unk1 = arg4;
        current->unk34[arg2].unk4 = arg5;
        current->unk34[arg2].unk8 = arg6;
        current->unk34[arg2].unkC = arg7;
        current->unk34[arg2].unk18 = arg8;
        current->unk34[arg2].unk10 = arg9;
        current->unk34[arg2].unk14 = argA;
        current->unk34[arg2].unk12 = argB;
        current->unk34[arg2].unk16 = argC;
    }
}

void func_8072F09C(Actor *arg0) {
    GlobalASMStruct82 **var_s2;
    GlobalASMStruct82 *next;
    GlobalASMStruct82 *current;

    var_s2 = &D_807FDCC0;
    current = D_807FDCC0;
    while (current != NULL) {
        if (arg0 == current->unk0) {
            *var_s2 = current->next;
            next = current->next;
            func_8061130C(current);
            current = next;
        } else {
            var_s2 = &current->next;
            current = current->next;
        }
    }
}

void func_8072F230(Actor*, u8, u8);

void func_8072F120(void) {
    u8 i;
    s32 var_v1;

    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist) {
            var_v1 = isFlagSet(0x183, FLAG_TYPE_PERMANENT)
                || (D_807FBB64 & 0x10000000)
                || (cc_number_of_players > 1)
                || gameIsInDKTVMode();
            func_8072F230(character_change_array[i].player_pointer, i, var_v1);
        }
    }
}

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
