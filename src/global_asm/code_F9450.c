#include <ultra64.h>
#include "functions.h"


extern s16 D_807FD790[];
extern u8 D_807FD798;
extern s16 D_807FD722;
extern s16 D_807FD724;
extern u8 D_80754238[];
u8 func_806F6E58(s16);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct807FD740;

extern Struct807FD740 D_807FD740[];
extern s32 D_807FD780[];

void func_806F4750() {
    func_806F5270();
    func_806F4778();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F4778.s")

void func_806F4D70(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    D_807FD740[arg0].unk0 = arg1;
    D_807FD740[arg0].unk4 = arg2;
    D_807FD740[arg0].unk8 = arg3;
    D_807FD740[arg0].unkC = arg4;
    D_807FD780[arg0] = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F4DC0.s")

/*
// Close, nonsense at the top
void func_806F4DC0(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Struct807FD740 **var_v1;
    void *temp_v0_2;
    Struct807FD740 *var_v0;

    var_v1 = &D_807FD780[arg0];
    var_v0 = D_807FD780[arg0];
    while (var_v0 != NULL) {
        var_v1 = var_v0 + 1;
        var_v0 = *var_v1;
    }
    temp_v0_2 = malloc(0x14);
    *var_v1 = temp_v0_2;
    func_80611690(temp_v0_2);
    (*var_v1)->unk0 = arg1;
    (*var_v1)->unk4 = arg2;
    (*var_v1)->unk8 = arg3;
    (*var_v1)->unkC = arg4;
    func_8061134C(*var_v1);
}
*/

extern s16 D_80753EF0; // TODO: Array of 0xA structs?

// TODO: Array of 0xA structs?
s32 func_806F4E74(s16 arg0) {
    s32 b = 0;
    s32 a = FALSE;
    s16 *ptr = &D_80753EF0;

    while (!a) {
        if (arg0 == *ptr) {
            a = TRUE;
        } else {
            b++;
            ptr += 0xA;
        }
    }
    return b;
}

s32 func_806F4EBC(f32 arg0, f32 arg1) {
    s32 temp_f10;
    s32 temp_f6;

    temp_f10 = arg0 / 500.0f;
    temp_f6 = arg1 / 500.0f;
    if ((D_807FD722 < temp_f10) || (D_807FD724 < temp_f6) || (arg0 < 0.0f) || (arg1 < 0.0f)) {
        return -1;
    }
    return (D_807FD722 * temp_f6) + temp_f10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F4F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F50C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F5270.s")

typedef struct globalASMStruct36 GlobalASMStruct36;

// TODO: These fields might not all be correct
struct globalASMStruct36 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    GlobalASMStruct36 *next;
};

extern GlobalASMStruct36 *D_807FD730;
extern u8 D_807FD738;

void func_806F5378(void) {
    GlobalASMStruct36 *next;
    GlobalASMStruct36 *current;

    D_807FD738 = 1;
    current = D_807FD730;
    while (current) {
        next = current->next;
        func_806F54E0(0, current->unk2, current->unk1A);
        func_806355DC(current->unk0, 1);
        func_8061130C(current);
        current = next;
    }
    D_807FD730 = NULL;
}

// TODO: These fields might not all be correct
typedef struct GlobalASMStruct37 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
} GlobalASMStruct37;

GlobalASMStruct36 *func_806F53EC(GlobalASMStruct37 *arg0) {
    GlobalASMStruct36 *temp_v0 = malloc(0x20);
    temp_v0->unk10 = 0;
    temp_v0->unk14 = 0.0f;
    temp_v0->unk0 = arg0->unk0;
    temp_v0->unk18 = arg0->unk10;
    temp_v0->unk2 = arg0->unk2;
    temp_v0->unk19 = arg0->unk12;
    temp_v0->unk1A = arg0->unk13;
    return temp_v0;
}

s32 func_806F544C(s32 arg0, s32 actorBehaviourIndex, u8 arg2) {
    switch (actorBehaviourIndex) {
        case 0x91: // Peanut
        case 0x15D: // Feather
        case 0x15E: // Grape
        case 0x15F: // Pineapple
        case 0x160: // Coconut
            if (arg2) {
                arg0 = 3;
            }
    }
    return arg0;
}

// Rainbow coin FTT check
void func_806F5498(void) {
    if (!isFlagSet(0x16C, FLAG_TYPE_PERMANENT)) {
        playCutscene(NULL, 0x20, 5);
        setFlag(0x16C, TRUE, FLAG_TYPE_PERMANENT);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F54E0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F58A0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F5A48.s")

extern s32 D_80754248[];
extern s32 D_80754264[];

s32 func_806F5C30(s32 arg0) {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (arg0 == D_80754248[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_806F5CE4(s32 arg0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (arg0 == D_80754264[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_806F5D80(s32 *arg0, s32 *arg1) {
    *arg0 = D_80754248[((rand() >> 0xF) % 7U)];
    *arg1 = (((rand() >> 0xF) % 32767) % 391) + 0xD2;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
} Struct80754240;

extern Struct80754240 *D_80754240;

void func_806F5DF8(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    s32 found;
    s32 i;

    found = FALSE;
    for (i = 0; i < 60 && !found; i++) {
        if (D_80754240[i].unk10 == 0) {
            D_80754240[i].unk0 = arg1;
            D_80754240[i].unk4 = arg0;
            D_80754240[i].unk8 = arg2;
            D_80754240[i].unkA = arg3;
            D_80754240[i].unkC = arg4;
            D_80754240[i].unk10 = arg5;
            found = TRUE;
        }
    }
}

s32 func_806F5EB4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 found;

    found = FALSE;
    for (i = 0; i < 60 && !found; i++) {
        if (D_80754240[i].unk10 != 0) {
            if (arg0 == D_80754240[i].unk4) {
                if (arg1 == D_80754240[i].unk0) {
                    found = TRUE;
                }
            }
        }
    }
    return found;
}

void func_806F5F2C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    if (func_80714608(0) && func_806F5C30(arg0)) {
        func_806F5D80(&arg0, &arg1);
    }
    func_806F5DF8(arg0, 1, arg2, arg3, arg4, arg1);
}

void func_806F5FA0(s16 arg0, s16 arg1, s16 arg2) {
    func_806F5F2C(0x76, 0, arg0, arg1, arg2);
}

void func_806F5FE8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    if (func_806F5CE4(arg0)) {
        func_806F5DF8(arg0, 0, arg1, arg2, arg3, arg4);
    }
}

void func_80686E40(f32, f32, f32, s32);
void func_806A5DF0(s16, f32, f32, f32, s32, s32, s32, s32);
void func_806F50C8(s16, s16, s32, s32, s32, s32);

void func_806F603C(void) {
    s32 i;

    if (gameIsInAdventureMode() && !(global_properties_bitfield & 2)) {
        for (i = 0; i < 60; i++) {
            if (D_80754240[i].unk10 != 0) {
                D_80754240[i].unk10--;
                if (D_80754240[i].unk10 == 5) {
                    func_80686E40(D_80754240[i].unk8, D_80754240[i].unkA, D_80754240[i].unkC, 7);
                }
                if (D_80754240[i].unk10 == 0) {
                    if (D_80754240[i].unk0 != 0) {
                        func_806A5DF0(D_80754240[i].unk4, D_80754240[i].unk8, D_80754240[i].unkA, D_80754240[i].unkC, 0, 0x19, -1, 0);
                    } else {
                        func_806F50C8(func_80632630(D_80754240[i].unk4, D_80754240[i].unk8, D_80754240[i].unkA, D_80754240[i].unkC, 0.0f, 0), D_80754240[i].unk4, 0, 1, 0, 0);
                    }
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F6204.s")

extern s32 *D_80754244;
extern s16 D_807FD726;
extern s16 D_807FD728;
extern s32 D_807FD72C;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct806F6554_arg1;

void func_806F6554(u8 arg0, Struct806F6554_arg1 *arg1) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    s32 temp_v0;

    if (D_807FC950[arg0].health > 0) {
        if (arg1->unk0 <= (D_807FD726 + arg1->unkC)) {
            if (arg1->unk8 <= D_807FD728 + arg1->unkC) {
                temp_v0 = func_806F4EBC(arg1->unk0, arg1->unk8);
                if (temp_v0 >= 0) {
                    func_806F6204(D_80754244[temp_v0], arg0, arg1);
                }
            }
        }
        func_806F6204(D_807FD72C, arg0, arg1);
    }
}

s32 func_806F6644(s16 arg0, s32 arg1, u16 arg2) {
    PlayerAdditionalActorData *PaaD;
    ObjectModel2 *temp;
    u8 temp_a0;

    switch (arg2) {
        case 0x11:
            if ((D_807FC950[cc_player_index].character_progress[current_character_index[cc_player_index]].weapon & 3) != 3) {
                return 0;
            }
        default:
            break;
        case 0x8F:
            if (!((D_807FC950[cc_player_index].character_progress[current_character_index[cc_player_index]].weapon & 1))) {
                return 0;
            }
            break;
        case 0x98:
            PaaD = character_change_array[cc_player_index].player_pointer->PaaD;
            if (!(PaaD->unk1F4 & 1)) {
                return 0;
            }
            break;
        case 0x8E:
            PaaD = character_change_array[cc_player_index].player_pointer->PaaD;
            if (!(PaaD->unk1F4 & 2)) {
                return 0;
            }
            break;
        case 0x90:
            temp = &D_807F6000[func_80659470(arg0)];
            if (temp->unk7C->unk64 != 0xFF) {
                return 0;
            }
            break;
    }
    temp_a0 = D_807F6000[func_80659470(arg0)].unk8C;
    if (temp_a0 & 8 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_DK) {
        return 0;
    } else if (temp_a0 & 2 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_DIDDY) {
        return 0;
    } else if (temp_a0 & 4 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_TINY) {
        return 0;
    } else if (temp_a0 & 0x10 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_LANKY) {
        return 0;
    } else if (temp_a0 & 1 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_CHUNKY) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F69A8.s")

// TODO: Odd syntax, cleanup possible?
u8 func_806F6E58(s16 kongIndex) {
    u8 phi_v1;

    phi_v1 = 0;
    if (kongIndex < 5) {
        phi_v1 = D_807FC950->character_progress[kongIndex].moves >= D_80754238[kongIndex];
    }
    // Camera/Shockwave unlocked
    phi_v1 |= isFlagSet(0x179, FLAG_TYPE_PERMANENT);
    return phi_v1;
}

// TODO: Odd syntax, cleanup possible?
s32 func_806F6EDC(void) {
    s32 i;
    u8 temp_v1;

    i = 0;
    do {
        temp_v1 = func_806F6E58(i);
        i++;
    } while (i < 5 && !temp_v1);

    return temp_v1;
}

void func_806F6F28(void) {
    s16 pad; // TODO: Why is this needed? Fake match?
    u8 sp45;
    s8 cameraShockaveUnlocked;
    u8 playerIndex;
    PlayerAdditionalActorData *PaaD;

    cameraShockaveUnlocked = FALSE;
    sp45 = FALSE;
    if (D_807FBB64 & 0x10000) {
        func_806F603C();
    }
    // Camera/Shockwave unlocked
    if (isFlagSet(0x179, FLAG_TYPE_PERMANENT)) {
        cameraShockaveUnlocked = TRUE;
    }
    if (func_806F6E58(current_character_index[0])) {
        sp45 = TRUE;
    }
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        PaaD = character_change_array[playerIndex].player_pointer->additional_actor_data;
        if (cameraShockaveUnlocked) {
            PaaD->unk1F4 |= 1;
        } else {
            PaaD->unk1F4 &= ~1;
        }
        if (sp45) {
            PaaD->unk1F4 |= 2;
        } else {
            PaaD->unk1F4 &= ~2;
        }
        if ((character_change_array[playerIndex].player_pointer->control_state != 0x36) && (D_807FD738 == 0)) {
            func_806F69A8(playerIndex & 0xFF);
        }
    }
}

s32 func_806F70A8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_807FD798; i++) {
        if (arg0 == D_807FD790[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F70FC.s")

extern f64 D_8075D950;
extern s32 D_8071C48C; // TODO: Datatype
extern s32 D_8071FC58; // TODO: Datatype
extern s32 D_8071C620; // TODO: Datatype

/*
// TODO: Kinda close, stack 2 big and datatype issues?
void func_806F70FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    f64 temp_f20;
    s32 phi_s1;
    f32 phi_f4;
    f32 phi_f6;
    f32 phi_f4_2;

    func_80714950(0x1006E);
    func_8071498C(&D_8071C48C);
    func_807149B8(1);
    func_80714CC0(&D_8071FC58, arg3, arg0, arg1, arg2);
    temp_f20 = D_8075D950 / (arg4 + arg4);
    for (phi_s1 = 0; phi_s1 < arg5; phi_s1++) {
        phi_f4 = (func_806119A0() / 10000U) % 1000;
        phi_f6 = (func_806119A0() / 10000U) % 1000;
        phi_f4_2 = (func_806119A0() / 10000U) % 1000;
        func_8071498C(&D_8071C620);
        func_8071496C(phi_s1);
        func_807149B8(1);
        func_80714CC0(
            &D_8071FC58,
            arg3,
            arg0 + ((phi_f4 / arg4) - temp_f20),
            arg1 + ((phi_f6 / arg4) - temp_f20),
            arg2 + ((phi_f4_2 / arg4) - temp_f20)
        );
    }
}
*/

f32 func_806F7378(s32 arg0) {
    if (arg0 == 0x8C) {
        return -13.0f;
    } else {
        return 0.0f;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F73A0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_806F79E0.s")
