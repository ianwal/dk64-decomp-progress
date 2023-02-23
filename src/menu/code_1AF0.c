#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct menu_struct_1 {
    u32 unk0;
    s16 unk4;
    u16 unk6;
    u16 unk8;
    u8  unkA;
    s8  unkB;
    u8  unkC;
    u8  unkD;
    u8  unkE;
    u8  unkF;
    u8  unk10;
    u8  unk11;
} MenuStruct1;

extern u8 D_800334DC[];

void func_806F91B4(s32, s32, s16);
void func_80709464(s32);
void func_80025FB4(MenuStruct1*, s32, s32);

void func_806F397C(Actor*, Actor*, s16, s16);

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80025AF0.s")

/*
// TODO: Close, regalloc? Extra args?
s32 func_80025AF0(MenuStruct1 *arg0, s32 characterIndex) {
    s32 phi_v1;
    s32 phi_v0;

    phi_v1 = 0;
    for (phi_v0 = 0; phi_v0 < 5; phi_v0++) {
        if (phi_v0 != current_character_index[0]) {
            phi_v1 |= D_807FC950[0].character_progress_as_bytes[phi_v0][arg0->unkB] & (1 << (characterIndex + 0x1F));
        }
        if (phi_v1) {
            break;
        }
    }
    return phi_v1;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80025B64.s")

void func_80025D14(MenuStruct1 *arg0, s32 arg1) {
    D_807FC950[0].character_progress_as_bytes[arg1][arg0->unkB] = arg0->unk11;
}

void func_80025D44(MenuStruct1 *arg0, s32 arg1) {
    D_807FC950[0].character_progress_as_bytes[arg1][arg0->unkB] |= 1 << (arg0->unk11 + 0x1F);
}

void func_80025D8C(MenuStruct1 *arg0, u8 arg1) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arg1) {
            func_80025D44(arg0, i);
        } else {
            func_80025D14(arg0, i);
        }
    }
}

void func_80025E04(MenuStruct1 *arg0, s32 arg1) {
    s16 sp1E;
    u8 sp1D;

    sp1E = -1;
    sp1D = func_806F6E58(current_character_index[0]);
    switch (arg0->unkB) {
        case 2:
        case 4:
            if (arg0->unk11 >= 2) {
                func_80025D8C(arg0, 1);
            } else {
                func_80025D44(arg0, current_character_index[0]);
            }
            break;
        case 1:
        case 3:
            func_80025D8C(arg0, 0);
            break;
        default:
            func_80025D14(arg0, current_character_index[0]);
            break;
    }

    if (arg0->unkB == 4) {
        if (D_807FC950[0].melons < D_800334DC[arg0->unk11]) {
            D_807FC950[0].melons = D_800334DC[arg0->unk11];
            func_80709464(0);
            character_change_array->unk2E2 |= 0x11;
        }
    }

    switch (arg0->unkB) {
        case 2:
        case 3:
            sp1E = 2;
            break;
        case 4:
            sp1E = 7;
            break;
        case 0:
            if ((sp1D == 0) && (func_806F6E58(current_character_index[0]))) {
                sp1E = 5;
            }
            break;
    }
    func_806F91B4(1, 0, -arg0->unk4);
    if (sp1E >= 0) {
        func_806F91B4(sp1E, 0, 9999);
    }
    func_8060DEC8(); // saveTheGame()
}

// Doable, big project though
// It checks whether levels have been entered and does stuff with actor behaviour index
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80025FB4.s")

s32 func_800261C0(MenuStruct1 *arg0, s32 arg1) {
    s32 ret = 0;
    arg0->unkF = 3;
    if (arg0->unkB >= 0) {
        if (func_806F8AD4(1, 0) >= arg0->unk4) {
            ret = 2;
            arg0->unkF = 1;
        } else {
            ret = 3;
        }
    } else if (arg0->unkB == -2) {
        ret = 1;
    }
    if (arg0->unkA != 0) {
        ret += 4;
    }
    return ret;
}

int func_80026250(MenuStruct1 *arg0) {
    // TODO: ACTOR_CRANKY?
    return (current_actor_pointer->unk58 == 0xBD) &&
            (arg0->unkA == 0) &&
            (arg0->unkB < 0);
}

void func_80026290(MenuStruct1 *arg0, u32 *arg1) {
    *arg1 = 0;
    arg0->unkF = 1;
    arg0->unkB = -1;
}

// Doable, big though
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_800262A8.s")

void func_80026684(MenuStruct1 *arg0, s32 arg1, s32 arg2) {
    switch (arg0->unkE) {
        case 0:
            func_800262A8(arg0, arg1, arg2);
            return;
        case 1:
            // TODO: Proper bitfield syntax
            if ((s32)(current_actor_pointer->object_properties_bitfield << 6) >= 0) {
                arg0->unkE = 0;
                arg0->unkD = arg0->unkF;
                func_8061CB08(arg0, arg1, arg2);
            }
            return;
    }
}

s32 func_800266F0(MenuStruct1 *arg0, s32 arg1, s32 flagIndex) {
    s32 temp_a2 = !isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
    func_80025FB4(arg0, arg1, temp_a2);
    arg0->unkD = 0;
    arg0->unkE = 0;
    // Global: Jetpac in Story Mode
    if (!isFlagSet(0x61, FLAG_TYPE_TEMPORARY)) {
        if (temp_a2) {
            func_806F397C(player_pointer, current_actor_pointer, 0, 0x1B);
            playCutscene(NULL, 0, 1);
        } else {
            playCutscene(NULL, 4, 1);
            func_806EB0C0(0x1B, current_actor_pointer, 0);
        }
    } else {
        func_806EB0C0(0x1B, current_actor_pointer, 0);
        playCutscene(NULL, 0xB, 1);
    }
    func_80629174();
    current_actor_pointer->object_properties_bitfield |= 0x10000000;
    return temp_a2;
}

void func_80026804(MenuStruct1 *arg0, s32 arg1) {
    arg0->unkA = 1;
    playCutscene(NULL, 0xF, 1);
    func_80629174();
    func_80025FB4(arg0, arg1, 0);
    arg0->unkD = 0;
    arg0->unkE = 0;
    func_806EB0C0(0x1B, current_actor_pointer, 0);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80026874.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80026B28.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80026DAC.s")

void func_80026B28(MenuStruct1*, s32, s32);
void func_80026DAC(MenuStruct1*, s32, s32);

void func_80027028(MenuStruct1 *arg0, s32 arg1, s32 flagIndex) {
    s32 flagIsNotSet = !isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
    switch (arg0->unkD) {
        case 0:
            func_80026684(arg0, arg1, flagIsNotSet);
            break;
        case 1:
            func_80026874(arg0, arg1);
            break;
        case 2:
            func_80026B28(arg0, arg1, flagIndex);
            break;
        case 3:
            func_80026DAC(arg0, arg1, flagIndex);
            break;
    }
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_800270E0.s")

s32 func_800275EC(s32 arg0) {
    return arg0 + 0x21F44F;
}

// Appears to CRC some code and compare to a fixed value
// Perhaps a tamper protection mechanism
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_800275FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80027738.s")

/*
// TODO: Pretty close, some minor issues with stack, args, regalloc?
void func_80027738(void) {
    s32 var1;
    func_80729B00();
    if (current_map == 1) {
        s32 var1 = D_807FC950[current_character_index];
        if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
            func_800266F0(current_actor_pointer->unk178, var1, 0x176);
        }
        func_80027028(current_actor_pointer->unk178, var1, 0x176);
    }
    if ((current_actor_pointer->object_properties_bitfield << 3) != 0) {
        func_80729B00();
        func_806BFBF4();
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80027808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80027988.s")

void func_80027DEC() {
    func_80027988();
}