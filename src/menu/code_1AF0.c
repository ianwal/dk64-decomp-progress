#include <ultra64.h>
#include "functions.h"

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
    u8  unk12;
} MenuStruct1;

extern u8 D_800334DC[];

void func_806F91B4(s32, s32, s16);
void func_80025FB4(MenuStruct1*, s32, s32);

void func_806F397C(Actor*, Actor*, s16, s16);

s32 func_80025AF0(MenuStruct1 *arg0, s32 characterIndex) {
    s32 phi_v1;
    s32 phi_v0;

    phi_v1 = 0;
    for (phi_v0 = 0; !phi_v1 && phi_v0 < 5; phi_v0++) {
        if (phi_v0 != current_character_index[0]) {
            phi_v1 |= D_807FC950[0].character_progress_as_bytes[phi_v0][arg0->unkB] & (1 << (characterIndex + 0x1F));
        }
    }
    return phi_v1;
}

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

extern u8 D_807FCC4C;

/*
void func_80025FB4(MenuStruct1 *arg0, s32 arg1, ? arg2) {
    ? *var_v1;
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_s0;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    u32 temp_v1;
    void *var_a1;

    var_s1 = 0;
    var_s0 = 6;
    if (isFlagSet(0x1CB, FLAG_TYPE_PERMANENT) == 0) {
loop_1:
        var_s0 -= 1;
        if (var_s0 >= 0) {
            if (isFlagSet(var_s0 + 0x1C5, FLAG_TYPE_PERMANENT) == 0) {
                goto loop_1;
            }
        }
    }
    temp_s0 = var_s0 + 1;
    arg0->unkC = getLevelIndex(D_8076A0AB, 0);
    temp_v1 = current_actor_pointer->unk58;
    var_a2 = 0 * 6;
    switch (temp_v1) {
        default:
            var_v1 = sp2C;
            break;
        case ACTOR_CRANKY: // Cranky
            var_v1 = &D_80033260;
            break;
        case ACTOR_CANDY: // Candy
            var_v1 = &D_80033334;
            break;
        case ACTOR_FUNKY: // Funky
            var_v1 = &D_80033408;
            break;
    }
    if (temp_s0 > 0) {
        var_a1 = var_v1 + (current_character_index * 0x2A) + var_a2;
loop_12:
        temp_a0 = var_a1->unk0;
        var_a2 += 6;
        if (temp_a0 >= 0) {
            if ((temp_a0 == 2) || (temp_a0 == 4)) {
                if (!((1 << (var_a1->unk2 + 0x1F)) & *(arg1 + temp_a0))) {
                    goto block_18;
                }
            } else if (*(arg1 + temp_a0) < var_a1->unk2) {
block_18:
                var_s1 = 1;
            }
            if (var_s1 != 0) {
                arg0->unkB = temp_a0;
                temp_v0 = var_a1->unk4;
                arg0->unk4 = temp_v0;
                D_80750AC8 = temp_v0;
                arg0->unk11 = var_a1->unk2;
            }
        }
        var_a1 += 6;
        if ((var_a2 < (temp_s0 * 6)) && (var_s1 == 0)) {
            goto loop_12;
        }
    }
    if (var_s1 == 0) {
        arg0->unk4 = 0;
        arg0->unkB = -1;
        D_80750AC8 = arg0->unk4;
        if (temp_s0 >= 7) {
            arg0->unkB = -2;
        }
    }
    arg0->unk10 = D_807FCC4C;
}
*/

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

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_800262A8.s")

extern MenuStruct1 D_800334EC;
extern MenuStruct1 D_80033500;
extern MenuStruct1 D_80033514;
extern u16 D_80033528;
extern u16 D_80750AC8;

extern u8 D_807FCC4C;
extern u8 D_800334DD[];

/*
// TODO: Doable, good progress made
void func_800262A8(MenuStruct1 *arg0, u8 *arg1, s32 arg2) {
    MenuStruct1 *sp44;
    u16 sp42;
    s32 sp3C;
    u16 sp3A;
    u16 sp38;
    u16 sp36;
    u16 sp34;
    u16 sp2C;
    s32 sp28;
    s16 var_a0;
    s32 temp_v0_2;
    u16 var_a2;
    u16 var_t0;
    u16 var_t1;
    u16 var_v1;

    if (func_80629148() != 0) {
        sp44 = NULL;
        sp3C = func_800261C0(arg0, arg2);
        func_80629174();
        arg0->unk12 = 0;
        arg0->unkE++;
        switch (current_actor_pointer->unk58) {
            case ACTOR_CANDY: // Candy
                var_v1 = 3;
                var_a2 = 7;
                var_t0 = 0xC;
                var_t1 = 0xE;
                if (arg0->unkB >= 0) {
                    sp3A = 3;
                    sp38 = 7;
                    sp36 = 0xC;
                    sp34 = 0xE;
                    var_v1 = 3;
                    var_a2 = 7;
                    var_t0 = 0xC;
                    var_t1 = 0xE;
                    temp_v0_2 = func_80025AF0(arg0, 1, 7, arg0);
                    if (arg1[arg0->unkB] & 1) {
                        var_a2 = 9;
                        var_v1 = 5;
                        if (D_807FCC4C < D_800334DD[arg1[arg0->unkB]]) {
                            var_v1 = 6;
                            var_t0 = 0xD;
                            var_t1 = 0xF;
                            arg0->unk12 = 1;
                        } else {
                            var_a2 = 8;
                        }
                    } else if (temp_v0_2 == 0) {
                        var_v1 = 4;
                    }
                }
                D_80033500.unk4 = var_v1;
                D_80033500.unk6 = var_a2;
                D_80033500.unkC = var_t0;
                D_80033500.unkE = var_t1;
                sp44 = &D_80033500;
                sp42 = 9;
                break;
            case ACTOR_CRANKY: // Cranky
                arg2 = 0;
                sp2C = D_80750AC8;
                var_v1 = 0;
                sp3C = func_800261C0(arg0, 0);
                if ((sp3C == 0) || (sp3C == 1)) {
                    sp3C = 0;
                    sp2C = 0xF;
                }
                sp42 = 8;
                sp44 = &D_800334EC;
                if (arg0->unkA == 0) {
                    if (isFlagSet(0x61, 2) != 0) {
                        setFlag(0x61, 0, 2);
                        func_80026290(arg0, &sp3C);
                        if (isFlagSet(0x17B, FLAG_TYPE_PERMANENT) != 0) {
                            var_v1 = 0x20;
                        } else if (isFlagSet(0x62, 2) != 0) {
                            setFlag(0x62, 0, 2);
                            var_v1 = 0x22;
                        } else {
                            var_v1 = 0x21;
                        }
                    } else {
                        sp28 = func_80731AA8(0x225, 0x28, 0);
                        if (sp28 >= 0xF) {
                            func_80026290(arg0, &sp3C);
                            if (isFlagSet(0x17B, FLAG_TYPE_PERMANENT) != 0) {
                                var_v1 = 0x20;
                            } else {
                                var_v1 = 2;
                                sp2C = sp28;
                            }
                        }
                    }
                }
                D_80750AC8 = sp2C;
                D_800334EC.unk0 = var_v1;
                break;
            case ACTOR_FUNKY: // Funky
                sp44 = &D_80033514;
                var_v1 = 3;
                if (arg0->unkB == 3) {
                    sp44 = &D_80033528;
                } else {
                    var_a0 = 4;
                    if ((arg0->unkB >= 0) && (arg1[arg0->unkB] & 1)) {
                        var_v1 = 5;
                        var_a0 = 6;
                    }
                    D_80033514.unk4 = var_v1;
                    D_80033514.unk6 = var_a0;
                }
                sp42 = 7;
                break;
        }
        if (arg2 != 0) {
            func_8070D8C0(current_actor_pointer, sp42, sp44[0].unk11);
        }
        func_8070D8C0(current_actor_pointer, sp42, sp44[sp3C].unk11);
        if ((sp3C == 2) || (sp3C == 3) || (sp3C == 6) || (sp3C == 7)) {
            func_806F833C(0);
            func_806F8BC4(1, 1, 0);
            func_806F8BC4(0xE, 1, 0);
        }
    }
}
*/

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

void func_80027738(void) {
    Actor178 *temp;
    CharacterProgress *var1;
    func_80729B00();

    if (current_map == MAP_FUNKYS_STORE) {
        temp = current_actor_pointer->unk178;
        var1 = &D_807FC950[0].character_progress[current_character_index[0]];
        if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
            func_800266F0(temp, var1, 0x176);
        }
        func_80027028(temp, var1, 0x176);
    }
    if ((current_actor_pointer->object_properties_bitfield & (0x80000000 >> 3))) {
        func_80729B00();
        func_806BFBF4();
    }
    func_806319C4(current_actor_pointer, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80027808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_80027988.s")

void func_80027DEC() {
    func_80027988();
}