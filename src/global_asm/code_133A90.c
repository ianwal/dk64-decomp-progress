#include <ultra64.h>
#include "functions.h"

s32 func_global_asm_8063367C(s32, u8, s32);
s32 func_global_asm_80671D64(Actor*, s32);
void func_global_asm_8072F230(Actor*, u8, u8);
s32 func_global_asm_8061F2B8(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32 *, f32 *, f32 *);
f32 func_global_asm_80627A00(f64, f32, f32, f32, f32);

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
    u8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s8 unk30;
    u8 unk31;
    s8 unk32;
    s8 unk33;
    Unk34 *unk34;
    GlobalASMStruct82 *next;
};

extern GlobalASMStruct82 *D_global_asm_807FDCC0;

void func_global_asm_8072ED90(void) {
    D_global_asm_807FDCC0 = NULL;
}

void func_global_asm_8072ED9C(Actor *arg0, u8 arg1, u8 arg2) {
    s32 found;
    GlobalASMStruct82 *current;

    current = D_global_asm_807FDCC0;
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

void func_global_asm_8072EE0C(Actor *arg0, u8 arg1, u8 arg2) {
    s32 found;
    GlobalASMStruct82 *current;

    current = D_global_asm_807FDCC0;
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

void func_global_asm_8072EE7C(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, u8 argB, f32 argC, f32 argD, u8 argE) {
    GlobalASMStruct82 **var_t0;
    GlobalASMStruct82 *current;
    GlobalASMStruct82 *sp18;

    var_t0 = &D_global_asm_807FDCC0;
    current = D_global_asm_807FDCC0;
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

void func_global_asm_8072EF7C(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8, s16 arg9, s16 argA, s16 argB, s16 argC) {
    GlobalASMStruct82 *current;
    s32 found;

    current = D_global_asm_807FDCC0;
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

void func_global_asm_8072F09C(Actor *arg0) {
    GlobalASMStruct82 **var_s2;
    GlobalASMStruct82 *next;
    GlobalASMStruct82 *current;

    var_s2 = &D_global_asm_807FDCC0;
    current = D_global_asm_807FDCC0;
    while (current != NULL) {
        if (arg0 == current->unk0) {
            *var_s2 = current->next;
            next = current->next;
            free(current);
            current = next;
        } else {
            var_s2 = &current->next;
            current = current->next;
        }
    }
}

void func_global_asm_8072F120(void) {
    u8 i;
    s32 var_v1;

    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist) {
            var_v1 = isFlagSet(0x183, FLAG_TYPE_PERMANENT)
                || (D_global_asm_807FBB64 & 0x10000000)
                || (cc_number_of_players > 1)
                || gameIsInDKTVMode();
            func_global_asm_8072F230(character_change_array[i].player_pointer, i, var_v1);
        }
    }
}

// close, beq vs beql and beqz vs beqzl
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_8072F230.s")

extern f32 D_global_asm_8075FF50;

f32 func_global_asm_8072FA14(Actor *arg0, PlayerAdditionalActorData *arg1, GlobalASMStruct82 *arg2, u8 arg3);
void func_global_asm_8072FCC4(void *arg0, s32 arg1, f32 arg2, f32 *arg3);
u8 func_global_asm_8072F59C(void *arg0, GlobalASMStruct82 *arg1, f32 *arg2, s8 *arg3);

/*
void func_global_asm_8072F230(Actor *arg0, u8 arg1, u8 arg2) {
    s32 pad;
    f32 sp90; // sp90
    f32 sp8C; // sp8C
    f32 sp88; // sp88
    f32 dx;
    f32 dy;
    f32 sp7C; // sp7C
    f32 dz;
    f32 least;
    u8 sp73;
    u8 sp72;
    f32 sp6C; // sp6C
    GlobalASMStruct82 *current;
    PlayerAdditionalActorData *PaaD; // sp64
    GlobalASMStruct82 *found;
    u8 temp_s1;
    u8 var_s4;

    PaaD = arg0->additional_actor_data;
    current = D_global_asm_807FDCC0;
    least = D_global_asm_8075FF50;
    found = NULL;
    var_s4 = arg0->unk58 == ACTOR_CHUNKY && character_change_array[PaaD->unk1A4].unk2C0 == 2;
    while (current != NULL) {
        temp_s1 = func_global_asm_8072F4A8(current->unk0, current->unk4, &sp90, &sp8C, &sp88);
        dx = (arg0->x_position - sp90);
        dy = (arg0->y_position - sp8C);
        dz = (arg0->z_position - sp88);
        if (sqrtf((dx * dx) + (dy * dy) + (dz * dz)) < current->unk1C) {
            if (!current->unk31 || (current->unk6 != 1 && arg2 && current->unk0->object_properties_bitfield & 0x04000000)) {
                if (!temp_s1 || !var_s4) {
                    if (func_global_asm_8072F59C(arg0, current, &sp7C, &sp72)) {
                        if (sp7C < least) {
                            least = sp7C;
                            found = current;
                            sp73 = sp72;
                        }
                    }
                }
            }
        }
        current = current->next;
    }
    if (found != NULL) {
        func_global_asm_8072FCC4(found, sp73, func_global_asm_8072FA14(arg0, PaaD, found, sp73), &sp6C);
        PaaD->unk138 = sp6C;
        PaaD->unk130 = found->unk0;
        PaaD->unk134 = found->unk5;
        PaaD->unk19C = 0;
        PaaD->unk19E = 0xFFF;
        arg0->unkB8 = 0.0f;
        switch (found->unk6) {
            case 0:
                setAction(0xC, NULL, arg1);
                break;
            case 1:
                setAction(0xB, NULL, arg1);
                break;
        }
    }
}
*/

u8 func_global_asm_8072F4A8(Actor *arg0, u8 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
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
            model2ArrayIndex = func_global_asm_80659470(arg0);
            *arg2 = D_global_asm_807F6000[model2ArrayIndex].x_position;
            *arg3 = D_global_asm_807F6000[model2ArrayIndex].y_position;
            *arg4 = D_global_asm_807F6000[model2ArrayIndex].z_position;
            if (D_global_asm_807F6000[model2ArrayIndex].unk24->unk0 & 1) {
                phi_t0 = TRUE;
            }
            break;
    }
    return phi_t0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_8072F59C.s")

s32 func_global_asm_8072F8D4(GlobalASMStruct82 *arg0, s32 arg1, s16 arg2) {
    s16 model2ArrayIndex;
    s32 angle;

    if (!arg0->unk4) {
        return TRUE;
    }
    model2ArrayIndex = func_global_asm_80659470(arg0->unk0);
    switch (D_global_asm_807F6000[model2ArrayIndex].object_type) {
        case 0xC9: // Ladder
        case 0xCA: // Ladder
        case 0x1CB: // Ladder (Fungi)
        case 0x1F7: // Ladder (Fungi)
        case 0x1F8: // Ladder (Fungi)
            break;
        default:
            return TRUE;
    }
    angle = D_global_asm_807F6000[model2ArrayIndex].y_rotation * 4096.0f / 360.0f;
    if (func_global_asm_806725E4((arg0->unk34[arg1].unk10 + angle) & 0xFFF, (arg0->unk34[arg1].unk14 + angle) & 0xFFF, arg2, 0)) {
        return TRUE;
    }
    return FALSE;
}

f32 func_global_asm_8072FA14(Actor *arg0, PlayerAdditionalActorData *arg1, GlobalASMStruct82 *arg2, u8 arg3) {
    u8 boneIndex1;
    u8 boneIndex2;
    f32 z2;
    f32 y2;
    f32 x2;
    f32 z1;
    f32 y1;
    f32 x1;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 var_f2;
    f32 x3;
    f32 y3;
    f32 z3;

    boneIndex1 = arg2->unk34[arg3].unk0;
    boneIndex2 = arg2->unk34[arg3].unk1;
    switch (arg2->unk4) {
        case 0:
            getBonePosition(arg2->unk0, boneIndex1, &x1, &y1, &z1);
            getBonePosition(arg2->unk0, boneIndex2, &x2, &y2, &z2);
            break;
        case 1:
        case 2:
            func_global_asm_806335B0(arg2->unk0, 1, boneIndex1, &x1, &y1, &z1);
            func_global_asm_806335B0(arg2->unk0, 1, boneIndex2, &x2, &y2, &z2);
            break;
    }
    getBonePosition(arg0, 1, &x3, &y3, &z3);
    func_global_asm_8061F2B8(x3, y3, z3, x1, y1, z1, x2, y2, z2, &sp68, &sp64, &sp60);
    var_f2 = (sp64 - y1) / (y2 - y1);
    if (arg2->unk18 == 2 || arg2->unk18 == 3) {
        if (arg3 == 0) {
            if (var_f2 < 0.05) {
                var_f2 = 0.05f;
            }
        }
    }
    if (arg2->unk18 == 1 || arg2->unk18 == 3) {
        if ((arg3 + 1) == arg2->unk7) {
            if (0.95 < var_f2) {
                var_f2 = 0.95f;
            }
        }
    }
    arg1->unk13C = arg0->x_position;
    arg1->unk140 = arg0->y_position;
    arg1->unk144 = arg0->z_position;
    arg1->unk148 = 0.0f;
    memcpy(&arg1->unk15C, &arg0->unkC, 0x40);
    arg0->y_rotation = ((func_global_asm_80665E48(sp68, sp60, arg0->x_position, arg0->z_position) * 57.29577637f) / 360.0) * 4095.0;
    return var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_8072FCC4.s")

// TODO: Any cleanup possible? This is an odd one...
void func_global_asm_8072FDD4(GlobalASMStruct82 *arg0, f32 arg1, s8 *arg2, f32 *arg3) {
    f32 var_f0;
    u8 i;

    var_f0 = arg1;
    i = 0;
    while (TRUE) {
        arg1 = var_f0;
        var_f0 -= arg0->unk34[i].unk4;
        i++;
        if (!(var_f0 > 0.0) || i >= arg0->unk7) {
            i--;
            break;
        }
    }
    *arg2 = i;
    *arg3 = arg1 / arg0->unk34[i].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_8072FE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_807300BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_80730408.s")

void func_global_asm_80730AEC(u8 arg0, f32 arg1, GlobalASMStruct82 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    u8 bones[4];
    f32 sp4C[4][3];

    bones[0] = arg2->unk34[MAX(arg0 - 1, 0)].unk0;
    bones[1] = arg2->unk34[arg0].unk0;
    bones[2] = arg2->unk34[arg0].unk1;
    bones[3] = arg2->unk34[MIN((arg0 + 1), (arg2->unk7 - 1))].unk1;
    switch (arg2->unk4) {
        case 1:
        case 2:
            func_global_asm_806335B0(arg2->unk0, 1, bones[0], &sp4C[0][0], &sp4C[0][1], &sp4C[0][2]);
            func_global_asm_806335B0(arg2->unk0, 1, bones[1], &sp4C[1][0], &sp4C[1][1], &sp4C[1][2]);
            func_global_asm_806335B0(arg2->unk0, 1, bones[2], &sp4C[2][0], &sp4C[2][1], &sp4C[2][2]);
            func_global_asm_806335B0(arg2->unk0, 1, bones[3], &sp4C[3][0], &sp4C[3][1], &sp4C[3][2]);
            break;
        case 0:
            getBonePosition(arg2->unk0, bones[0], &sp4C[0][0], &sp4C[0][1], &sp4C[0][2]);
            getBonePosition(arg2->unk0, bones[1], &sp4C[0][0], &sp4C[0][1], &sp4C[0][2]);
            getBonePosition(arg2->unk0, bones[1], &sp4C[0][0], &sp4C[0][1], &sp4C[0][2]);
            getBonePosition(arg2->unk0, bones[2], &sp4C[0][0], &sp4C[0][1], &sp4C[0][2]);
            break;
    }
    *arg3 = func_global_asm_80627A00(arg1, sp4C[0][0], sp4C[1][0], sp4C[2][0], sp4C[3][0]);
    *arg4 = func_global_asm_80627A00(arg1, sp4C[0][1], sp4C[1][1], sp4C[2][1], sp4C[3][1]);
    *arg5 = func_global_asm_80627A00(arg1, sp4C[0][2], sp4C[1][2], sp4C[2][2], sp4C[3][2]);
}

void func_global_asm_80730D60(Actor *arg0, u8 arg1, u8 arg2, u8 arg3, void **arg4, void **arg5) {
    switch (arg1) {
        case 0:
            *arg4 = func_global_asm_80671D64(arg0, arg2);
            *arg5 = func_global_asm_80671D64(arg0, arg3);
            break;
        case 1:
        case 2:
            *arg4 = func_global_asm_8063367C(arg0, 1, arg2);
            func_global_asm_8061134C(*arg4);
            *arg5 = func_global_asm_8063367C(arg0, 1, arg3);
            func_global_asm_8061134C(*arg5);
            break;
    }
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_133A90/func_global_asm_80730E18.s")
