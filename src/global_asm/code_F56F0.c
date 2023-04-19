#include <ultra64.h>
#include "functions.h"


// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F09F0.s")

void func_80608528(Actor*, s32, s32, s32, s32);

void func_80614FD8(void*);
void func_80614F28(void*);

void func_806F0B34(Actor *arg0) {
    switch (current_character_index[cc_player_index]) {
        case 0:
            func_80608528(arg0, 0x17C, 0xFF, 0x7F, 0x19);
            return;
        case 1:
            func_80608528(arg0, 0x17C, 0xC8, 0xA0, 5);
            return;
        case 2:
            func_80608528(arg0, 0x17C, 0xFF, 0x7F, 5);
            return;
        case 3:
            func_80608528(arg0, 0x185, 0xFF, 0x7F, 0x19);
            return;
        default:
            func_80608528(arg0, 0x18F, 0xFF, 0x7F, 0x19);
            return;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F0C18.s")

/*
// TODO: Jumptable, Actor
void func_806F0C18(Actor *arg0) {
    void *sp20;
    s32 temp_v0;
    void *temp_v0_2; // TODO: Which aaD?

    temp_v0 = func_80613448(arg0);
    if (temp_v0 >= 0x11) {
        if (temp_v0 != 0xDB) {
            // TODO: Call D_8075D61C[something]()
        } else {
            func_8068A764(arg0, 1);
            func_8068A784(arg0, 0);
        }
    } else if ((temp_v0 - 1) < 0x10) {
        func_8068A784(arg0, 0);
        func_8068A784(arg0, 1);
    }
    if (arg0->unk5C & 1) {
        temp_v0_2 = arg0->unk174;
        if (temp_v0_2->unk8C != 0) {
            sp20 = temp_v0_2;
            func_806F0B34(arg0);
            temp_v0_2->unk8C = 0;
        }
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F0D68.s")

void func_806F1048(Actor *arg0) {
    s32 actorBehaviourIndex = arg0->unk58;
    PlayerAdditionalActorData *PaaD = arg0->PaaD;

    switch (actorBehaviourIndex) {
        case ACTOR_LANKY:
        case 0xC6: // ACTOR_CUTSCENE_LANKY
            PaaD->unk1F0 &= ~0x100;
        case ACTOR_DIDDY:
        case ACTOR_TINY:
        case ACTOR_CHUNKY:
        case 0xC5: // ACTOR_CUTSCENE_DIDDY
        case 0xC7: // ACTOR_CUTSCENE_TINY
        case 0xC8: // ACTOR_CUTSCENE_CHUNKY
            if (!(PaaD->unk1F0 & 0x40)) {
                func_80613214();
            }
            break;
    }
    func_806C8D20(current_actor_pointer);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F10E8.s")

extern s32 D_807FBB68;

void func_806086CC(f32, f32, f32, s32, s32, s32, s32, s32, f32, s32);

void func_806F1250(Actor *arg0) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    if (arg0->unk58 == ACTOR_CHUNKY) {
        func_80613194(arg0, 0x10);
        func_806086CC(arg0->x_position, arg0->y_position, arg0->z_position, 0x2E2, 0xFF, 0xA0, 0, 0x32, 0.0f, 0);
        if ((D_807FBB68 & 2) == 0) {
            // Gorilla Gone
            playSong(0x6C, 1.0f);
        }
    }
    PaaD->unk1F0 |= 0x40;
}

void func_806F12FC(Actor *arg0) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    if (arg0->unk58 == ACTOR_CHUNKY) {
        func_80613214();
        func_80602B60(0x6C, 0);
    }
    PaaD->unk1F0 &= ~0x40;
}

void func_806F1350(s32 arg0) {
    func_806E225C(0, 1);
}

void func_806F1378(s32 arg0) {

}

void func_806F1380(Actor *arg0) {
    f32 sp1C;

    func_80614FD8(&sp1C);
    arg0->animation_state->unk88 = arg0->unkB8 - sp1C;
}

extern s16 D_807FD584;

s32 func_806CD9A0(Actor*, f32, f32, s16, s16);

void func_806F13C8(Actor *arg0) {
    u8 sp27;

    func_80614F28(&sp27);
    arg0->animation_state->unk88 = func_806CD9A0(arg0, arg0->unkB8, arg0->unkB8, extra_player_info_pointer->unk4C, D_807FD584) - sp27;
}

void func_806F142C(Actor *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    func_806CFF9C(arg0);
    temp_f0 = current_actor_pointer->unkB8;
    temp_f2 = temp_f0 / 2;
    current_actor_pointer->unkB8 = (D_807FD610[cc_player_index].unk8 * (temp_f0 - temp_f2)) + temp_f2;
}

void func_806F149C(Actor *arg0) {
    func_806D0150(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F14BC.s")

extern f64 D_8075D6C8;
extern f32 D_8075D6C4;

/*
// TODO: Float regalloc, stack too big
void func_806F14BC(Actor *arg0) {
    s32 temp_v0;
    f32 var_f0;
    f32 sp54;
    u8 sp53;
    f32 var_f12;
    f32 temp_f16;

    func_80614FD8(&sp54);
    func_80614F28(&sp53);
    temp_f16 = arg0->animation_state->unk0->unk4;
    arg0->animation_state->unk88 = 0;
    if ((arg0->unk6A & 2) && (((arg0->unkAC - arg0->floor) > 12.0f))) {
        var_f0 = arg0->y_position - MAX(arg0->floor, arg0->unkAC);
        if (var_f0 < 0.0f) {
            var_f0 = 0.0f;
        }
    } else {
        var_f0 = arg0->distance_from_floor;
    }
    temp_v0 = func_806F1668(var_f0 * 40.0f, arg0->y_velocity, arg0->terminal_velocity, arg0->y_acceleration);
    if (temp_v0 == 0) {
        arg0->animation_state->unk88 = 1;
        return;
    }
    var_f12 = (sp53 - temp_f16) / temp_v0;
    if (var_f12 < 0.0f) {
        var_f12 = D_8075D6C4;
    }
    var_f12 /= MAX(D_8075D6C8, arg0->animation_state->unk0->unk24);
    if (sp54 < var_f12) {
        var_f12 = sp54;
    }
    func_80614D00(arg0, var_f12, 0.0f);
}
*/

s32 func_806F1668(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0, temp_f2, phi_f12;

    if ((arg0 < 0.0f) || (arg2 > 0.0f) || (arg3 >= 0.0f)) {
        return 0;
    }
    temp_f0 = (arg2 - arg1);
    temp_f0 /= arg3;
    temp_f2 = arg0;
    temp_f2 += (((arg1 + arg2) / 2) * temp_f0);
    if (temp_f2 > 0.0f) {
        phi_f12 = temp_f0 - (temp_f2 / arg2);
    } else {
        phi_f12 = (-sqrtf((arg1 * arg1) - (2 * arg3 * arg0)) - arg1) / arg3;
    }
    return phi_f12 + 0.5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F1768.s")

extern u16 D_80752F20[];
extern u16 D_80752F30[];
extern u16 D_80752F38[];
extern u16 D_80752F40[];

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    u16 unk4;
    u16 unk6;
} Struct806F1858;

/*
// TOOD: Regalloc v0 v1
void func_806F1768(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    s32 temp_v1;
    u16 temp_v0;

    temp_v1 = extra_player_info_pointer->unk8E - 0x14;
    if ((temp_v1 >= 0) && (temp_v1 < 7U)) {
        temp_v0 = D_80752F20[extra_player_info_pointer->unk8E];
        arg1[*arg2].unk0 = 0x7F;
        if (extra_player_info_pointer->unk91 != 0) {
            arg1[*arg2].unk1 = 9;
        } else {
            arg1[*arg2].unk1 = 8;
        }
        arg1[*arg2].unk2 = 0;
        if (extra_player_info_pointer->unk91 != 0) {
            arg1[*arg2].unk4 = temp_v0;
        } else {
            arg1[*arg2].unk4 = -temp_v0;
        }
        arg1[*arg2].unk6 = 0;
        *arg2 += 1;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F1858.s")

/*
// TOOD: Regalloc v0 v1
void func_806F1858(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    s32 temp_v1;
    s32 temp;

    temp_v1 = extra_player_info_pointer->unk8E - 0x14;
    if ((temp_v1 >= 0) && (temp_v1 < 4U)) {
        temp = D_80752F30[extra_player_info_pointer->unk8E];
        arg1[*arg2].unk0 = 0x7F;
        arg1[*arg2].unk1 = 4;
        arg1[*arg2].unk2 = 0;
        arg1[*arg2].unk4 = temp;
        arg1[*arg2].unk6 = 0;
        *arg2 += 1;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F18F4.s")

/*
// TODO: Regalloc v0 v1
void func_806F18F4(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    s32 temp_v1;
    s32 temp;

    temp_v1 = extra_player_info_pointer->unk8E - 0x16;
    if ((temp_v1 >= 0) && (temp_v1 < 4U)) {
        temp = D_80752F38[extra_player_info_pointer->unk8E];
        arg1[*arg2].unk0 = 0x7F;
        arg1[*arg2].unk1 = 1;
        arg1[*arg2].unk2 = 0;
        arg1[*arg2].unk4 = temp;
        arg1[*arg2].unk6 = 0;
        *arg2 += 1;
    }
}
*/

void func_806F1990(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    u16 temp_v0;

    temp_v0 = D_80752F40[extra_player_info_pointer->unk8E];
    arg1[*arg2].unk0 = 0x7F;
    arg1[*arg2].unk1 = 1;
    arg1[*arg2].unk2 = temp_v0;
    arg1[*arg2].unk4 = temp_v0;
    arg1[*arg2].unk6 = 0;
    *arg2 += 1;
}

extern f64 D_8075D6D0;
extern f32 D_8075D6D8;
extern f32 D_8075D6DC;
extern f32 D_8075D6E0;
extern f32 D_8075D6E4;
extern f32 D_8075D6E8;
extern f32 D_8075D6EC;

// TODO: Is this just a float array? Matrix? idk
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} GlobalASMStruct74;

void func_806F1A18(f32 arg0, f32 arg1, GlobalASMStruct74 *arg2, f32 *arg3) {
    s32 temp;
    f32 sp20;

    sp20 = func_80612D10(arg2->unk4);
    arg2->unk8 += (arg0 * func_80612D10(*arg3) * sp20);
    arg2->unk8 -= (arg1 * func_80612D1C(arg2->unk4));
    arg2->unk8 *= D_8075D6D0;
    arg2->unk4 += arg2->unk8;
    *arg3 += arg2->unk4 + arg2->unk0;
}

f32 func_806F1AE0(Actor *arg0, GlobalASMStruct74 *arg1, f32 arg2) {
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = func_80612790(arg0->y_rotation - arg0->unkEE) * (arg0->unkB8 * D_8075D6D8);
    temp_f12 = temp_f2 - arg1->unkC;
    arg1->unkC = temp_f2;
    return (temp_f12 + temp_f2) * arg2;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14; // Used
    u8 unk15;
    u8 unk16;
    u8 unk17;
    s32 unk18; // Used
} Struct806F1B58;

int func_806F1B58(Actor *arg0, Struct806F1B58 *arg1, s32 arg2) {
    return (arg0->object_properties_bitfield & 0x100)
        && arg1->unk14 == 0
        && arg2 == arg1->unk18;
}

f32 func_806F1B90(f32 *arg0, f32 arg1) {
    f32 phi_f2;

    phi_f2 = arg1 - *arg0;
    *arg0 = arg1;
    if (D_8075D6DC < phi_f2) {
        phi_f2 = D_8075D6E0 - phi_f2;
    } else if (phi_f2 < D_8075D6E4) {
        phi_f2 = -(D_8075D6E8 + phi_f2);
    }
    phi_f2 *= D_8075D6EC;
    return phi_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F1C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F1EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F22A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F2754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F2A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F2C48.s")

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct806F2EDC;

void func_806F2EDC(s32 arg0, Struct806F2EDC *arg1, s32 *arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6) {
    f32 temp_f0;

    temp_f0 = func_80612794(arg5 * 2048.0f);
    arg1[*arg2].unk0 = arg3;
    arg1[*arg2].unk1 = arg4;
    arg1[*arg2].unk4 = 1.0f;
    arg1[*arg2].unk8 = (temp_f0 * arg6) + 1.0;
    arg1[*arg2].unkC = 1.0f;
    *arg2 += 1;
}

typedef struct {
    u8 unk0[0x8E - 0x0];
    u8 unk8E;
    u8 unk8F;
    u8 unk90;
    u8 unk91;
} Struct806F2FC0;

void func_8068581C(s32, s16, f32, f32, f32, f32, s32);

void func_806F2FC0(s32 arg0, Struct806F2FC0 *arg1, u16 arg2) {
    s32 var_v0;
    s32 var_v1;

    switch (arg2) {
        case 0:
            if (arg1->unk8E != 0) {
                if ((arg1->unk8E == 0x10) && (arg1->unk8F < 4)) {
                    arg1->unk8F = 0;
                    return;
                }
            } else {
                if (arg1->unk8F >= 4) {
                    func_8068581C(arg0, 0xA, 0.3f, 0.0f, 0.0f, 0.0f, -0xA);
                    return;
                }
                return;
            }
            break;
        case 1:
            var_v1 = 0;
            if ((arg1->unk8E != 0) && (arg1->unk8E != 3)) {
                if ((arg1->unk8E == 0x10) && (arg1->unk8F < 6)) {
                    arg1->unk8F = 0;
                }
            } else if (arg1->unk8F >= 6) {
                var_v1 = 1;
            }
            if (var_v1 != 0) {
                if (arg1->unk8E != 0) {
                    var_v0 = arg1->unk90 + 9 & 0xFFFF;
                } else {
                    var_v0 = arg1->unk91 + 9 & 0xFFFF;
                }
                func_8068581C(arg0, var_v0, 0.2f, 0.0f, 0.0f, 0.0f, -0xA);
                return;
            }
            break;
        case 4:
        case 5:
            if (arg1->unk8E != 0) {
                if ((arg1->unk8E == 0x10) && (arg1->unk8F < 3)) {
                    arg1->unk8F = 0;
                    return;
                }
            } else if (arg1->unk8F >= 3) {
                func_8068581C(arg0, 0xA, 0.6f, 0.0f, 0.0f, 0.0f, -0xA);
            }
            break;
    }
}

// Jumptable, Actor* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F3190.s")

void func_806F3760(s16 map) {
    void *autowalkFile;

    autowalkFile = getPointerTableFile(0x15, map, 1, 0);
    func_806F4528(autowalkFile);
    if (autowalkFile) {
        func_8066B434(autowalkFile, 0x4C, 0x56);
    }
}

typedef struct {
    s16 unk0; // X
    s16 unk2; // Y
    s16 unk4; // Z
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
} Struct806F37BC;

void func_806F37BC(Actor *arg0, Struct806F37BC *arg1) {
    s16 temp_v0;

    func_80672C30(arg0);
    arg0->x_position = arg1->unk0;
    arg0->y_position = arg1->unk2;
    arg0->z_position = arg1->unk4;
    temp_v0 = func_80665DE0(arg1->unk12, arg1->unk16, arg1->unk0, arg1->unk4);
    arg0->unkEE = temp_v0;
    arg0->y_rotation = temp_v0;
}

void func_806F386C(u8, Actor*, Actor*, s16, u8);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F386C.s")

typedef struct {
    s16 unk0;
    s32 unk4;
} Struct80753E90_2;

// TODO: Same as GlobalASMStruct75?
typedef struct {
    s16 unk0;
    s16 unk2;
    Struct80753E90_2 *unk4;
} Struct80753E90;

extern Struct80753E90 *D_80753E90;
extern u8 D_8076A0B1;
extern s32 D_807FD70C;
extern Struct80753E90_2 *D_807FD708;
extern Actor *D_807FD710;
extern s16 D_807FD714;
extern s16 D_807FD718;
extern Actor *D_807FD71C;

/*
// TODO: Close
void func_806F386C(u8 arg0, Actor *arg1, Actor *arg2, s16 arg3, u8 arg4) {
    PlayerAdditionalActorData *temp_v0;

    temp_v0 = arg1->PaaD;
    if (D_80753E90[0].unk0 >= arg0) {
        is_autowalking = 3;
        D_8076A0B1 |= 0x10;
        D_807FD710 = arg1;
        temp_v0->unk1F0 &= ~1;
        D_807FD714 = 0;
        D_807FD708 = D_80753E90[arg0].unk4;
        D_807FD70C = D_807FD708->unk4;
        D_807FD718 = arg3;
        D_807FD71C = arg2;
        if (arg4 == 0) {
            func_806F37BC(arg1, D_807FD70C);
        }
    }
}
*/

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} GlobalASMStruct75;

void func_806F3950(GlobalASMStruct75 *arg0) {
    func_8061134C(arg0->unk4);
    arg0->unk0 = 0;
}

extern u8 D_807FD716; // bitfield, idk what it's for

void func_806F397C(Actor *arg0, Actor *arg1, s16 arg2, s16 arg3) {
    s32 phi_v0;

    if (arg2 & 0x8000) {
        phi_v0 = 1;
    } else {
        phi_v0 = 0;
    }
    arg2 &= ~0x8000;
    func_806F386C(arg2, arg0, arg1, arg3, phi_v0);
    D_807FD716 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F39E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F3BEC.s")

f32 func_80612794(s16);

typedef struct {
    s16 unk0; // X Position
    s16 unk2; // Y Position
    s16 unk4; // Z Position
    s16 unk6;
    u8 unk8;
    u8 unk9; // Used
} Struct806F3BEC;

/*
void func_806F3BEC(Actor *arg0, s16 arg1, s16 arg2, u8 arg3) {
    s16 sp3A;
    f32 temp_f0;
    f32 temp_f16;
    Struct80753E90_2 *temp_a1;
    Struct806F3BEC *temp_t0;
    void *temp_v0;
    Struct806F3BEC *temp_v0_2;

    sp3A = func_80665DE0(arg1, arg2, arg0->x_position, arg0->z_position);
    temp_a1 = &D_80753E90[0].unk4[D_80753E90[0].unk0];
    if (arg0->control_state != 0x44) {
        temp_a1->unk0 = 2;
        temp_v0 = malloc(0x24);
        temp_a1->unk4 = temp_v0;
        func_80611690(temp_v0);
        temp_v0_2 = temp_a1->unk4;
        temp_t0 = temp_v0_2 + 0x12;
        temp_v0_2->unk0 = arg0->x_position;
        temp_v0_2->unk2 = arg0->y_position;
        temp_v0_2->unk4 = arg0->z_position;
        temp_v0_2->unk9 = 0x28;
        temp_f0 = func_80612794(sp3A);

        temp_t0->unk0 = (temp_f0 * arg3) + arg0->x_position;
        temp_t0->unk2 = arg0->y_position;
        temp_f16 = func_80612790(sp3A) * arg3;
        temp_t0->unk4 = temp_f16 + arg0->z_position;
        temp_t0->unk9 = 0x28;
        func_806F386C(D_80753E90[0].unk0, arg0, 0, 0, 0);
        D_807FD716 = 0;
        global_properties_bitfield |= 0x400;
    }
}
*/

void func_806F3DB0(void) {
    D_807FD716 |= 2;
}

// Baffling lmao
void func_806F3DC8(u16 *arg0, s16 *arg1, u8 *arg2, u16 arg3) {
    if (arg1[0]) {
        arg1[0]--;
        return;
    }
    if (arg2[0]) {
        arg2[0]--;
        arg0[0] |= arg3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F3E0C.s")

// Autowalk file arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_806F4528.s")

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s16 unk4;
} Struct80753EA0;

extern Struct80753EA0 D_80753EA0[];
extern f32 D_8075D850;

f32 func_806F46B0(s16 arg0) {
    s16 i;
    s32 max = 0xD; // TODO: Why does this need to be a temp variable?

    for (i = 0; i < max; i++) {
        if ((current_map == D_80753EA0[i].unk0) && (((arg0 == D_80753EA0[i].unk2)) || (D_80753EA0[i].unk2 == -1))) {
            return D_80753EA0[i].unk4;
        }    
    }
    return D_8075D850;
}
