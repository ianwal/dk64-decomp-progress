#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_80746810;
extern u8 D_global_asm_80746818;
extern u8 D_global_asm_8076A0B1;
extern u8 D_global_asm_807ECD09;
extern OSMesgQueue D_global_asm_807ECCF0;

void func_global_asm_8060E4B0(Struct807F0470 *arg0) {
    bzero(arg0, sizeof(Struct807F0470));
}

void func_global_asm_8060E4D0(u8 arg0) {
    Struct807F0470 *temp = &D_global_asm_807F0470[arg0];

    if (osMotorStartStop(&D_global_asm_807F02D0[arg0], 1) == 4) {
        func_global_asm_8060E4B0(temp);
        temp->unk0 = 3;
    } else {
        temp->unk4 = 1;
    }
}

void func_global_asm_8060E574(u8 arg0) {
    OSPfs *temp_a1;

    switch (osMotorInit(&D_global_asm_807ECCF0, &D_global_asm_807F02D0[arg0], arg0)) {
        case 0:
            D_global_asm_807F0470[arg0].unk0 = 1;
            return;
        case 1:
            D_global_asm_807F0470[arg0].unk0 = 0;
            return;
        case 11:
            D_global_asm_807F0470[arg0].unk0 = 2;
            return;
        case 4:
            D_global_asm_807F0470[arg0].unk0 = 3;
            return;
    }
}

void func_global_asm_8060E664(u8 arg0) {
    func_global_asm_8060E574(arg0);
    osMotorStartStop(&D_global_asm_807F02D0[arg0], 0);
    osMotorStartStop(&D_global_asm_807F02D0[arg0], 0);
    osMotorStartStop(&D_global_asm_807F02D0[arg0], 0);
    D_global_asm_807F0470[arg0].unk4 = 0;
}

void func_global_asm_8060E6E8(s32 arg0) {
    s32 phi_s0;
    s32 phi_s3;

    for (phi_s3 = 0; phi_s3 < 4; phi_s3++) {
        func_global_asm_8060E4B0(&D_global_asm_807F0470[phi_s3]);
        D_global_asm_807F0470[phi_s3].unk0 = 0;
        if (D_global_asm_807ECD09 & (1 << phi_s3)) {
            for (phi_s0 = 0; phi_s0 < 2; phi_s0++) {
                func_global_asm_8060E664(phi_s3);
            }
        }
    }
}

s32 func_global_asm_8060E79C(u8 arg0) {
    if (arg0 >= 4) {
        return 0;
    }
    return D_global_asm_807F0470[func_global_asm_8060AB38(arg0)].unk0;
}

// TODO: Cleanup, get rid of the block label
void func_global_asm_8060E7EC(u8 arg0, u8 arg1, s32 arg2) {
    Struct807F0470 *temp_a0 = &D_global_asm_807F0470[func_global_asm_8060AB38(arg0)];

    if ((D_global_asm_80746810 != 1)
        && (temp_a0->unk0 == 1)
        && (character_change_array[arg0].unk2EB == 0)
        && (gameIsInAdventureMode() || gameIsInMysteryMenuMinigameMode())
    ) {
        if (temp_a0->unk12 != 0) {
            if (temp_a0->unk10 < 0x1F) {
                temp_a0->unk12 = 0;
                temp_a0->unk10 = 0;
                goto block_8;
            }
        } else {
block_8:
            temp_a0->unkC = arg2;
            temp_a0->unk5 = arg1;
        }
    }
}

void func_global_asm_8060E8CC(Struct807F0470 *arg0) {
    if (arg0->unk0 == 1) {
        arg0->unk5 = 0;
        arg0->unkC = 0;
    }
}

void func_global_asm_8060E8EC(u8 arg0) {
    func_global_asm_8060E8CC(&D_global_asm_807F0470[func_global_asm_8060AB38(arg0)]);
}

void func_global_asm_8060E930(void) {
    func_global_asm_8060E6E8(1);
    func_global_asm_8060EC54(1);
}

void func_global_asm_8060E958(void) {
    func_global_asm_8060E6E8(0);
    func_global_asm_8060EC54(1);
}

// TODO: Why can't this be s32 and still match?
int func_global_asm_8060E980(void) {
    return (global_properties_bitfield & 0x4002)
        || (D_global_asm_8076A0B1 & 1)
        || func_global_asm_8062919C()
        || func_global_asm_8061CB50()
        || (!gameIsInAdventureMode() && !gameIsInMysteryMenuMinigameMode() && !gameIsInSnidesBonusGameMode());
}

void func_global_asm_8060EA28(void) {
    Struct807F0470 *phi_s0;
    s32 temp;
    s32 phi_s1;
    u8 sp23;

    phi_s0 = &D_global_asm_807F0470[0];
    if (D_global_asm_80746810 == 1) {
        if (!func_global_asm_8060E980()) {
            func_global_asm_8060EC54(0);
        }
    } else if (func_global_asm_8060E980()) {
        func_global_asm_8060EC54(1);
    }
    if (D_global_asm_80746818) {
        func_global_asm_8060E6E8(0);
    }
    D_global_asm_80746818 = 0;
    if (D_global_asm_80746810 != 1) {
        sp23 = func_global_asm_8060AC28();
        for (phi_s1 = 0; phi_s1 < 4; phi_s1++) {
            if (phi_s0->unk0 != 1) {
                if (((D_global_asm_807ECD09 & (1 << phi_s1))) && ((sp23 & (1 << phi_s1))) && ((object_timer % 15U) == 0)) {
                    func_global_asm_8060E664(phi_s1);
                }
            } else {
                if (phi_s0->unk12 == 0) {
                    phi_s0->unk12 = (phi_s0->unk10 >= 0x33);
                }
                if ((phi_s0->unkC == 0) && (phi_s0->unk5 == 0)) {
                    if (phi_s0->unk10 != 0) {
                        phi_s0->unk10--;
                    }
                }
                if (phi_s0->unk5 == 0) {
                    if (phi_s0->unk4) {
                        func_global_asm_8060E664(phi_s1);
                    }
                } else {
                    if (phi_s0->unkC) {
                        phi_s0->unkC--;
                        phi_s0->unk10++;
                    }
                    if ((phi_s0->unkC == 0) || phi_s0->unk12) {
                        func_global_asm_8060E8CC(phi_s0);
                    } else {
                        if (phi_s0->unk8 >= 0x100U) {
                            if (phi_s0->unk4 == 0) {
                                func_global_asm_8060E4D0(phi_s1);
                            }
                            phi_s0->unk8 -= 0x100;
                        } else {
                            temp = phi_s0->unk5;
                            phi_s0->unk8 += temp * 4;
                            if (phi_s0->unk4) {
                                func_global_asm_8060E664(phi_s1);
                            }
                        }
                    }
                }
            }
            phi_s0++;
        }
    }
}

void func_global_asm_8060EC54(s32 arg0) {
    if (arg0 != D_global_asm_80746810) {
        D_global_asm_80746810 = arg0;
        D_global_asm_80746818 = 1;
    }
}

// osCreateThread, osStartThread, function pointer, neat
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060EC80.s")

void func_global_asm_8060ED6C(Struct131B0_2 *arg0, Struct131B0_1 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    OSIntMask oldInterruptMask = osSetIntMask(OS_IM_NONE);
    arg1->unk4 = arg2;
    arg1->next = arg0->unk260;
    arg0->unk260 = arg1;
    arg1->unk8 = arg3;
    arg1->unkC = arg4;
    osSetIntMask(oldInterruptMask);
}

void func_global_asm_8060EDD0(Struct131B0_2 *arg0, Struct131B0_1 *arg1) {
    Struct131B0_1 *current;
    Struct131B0_1 *var_a2;
    OSIntMask oldInterruptMask;

    current = arg0->unk260;
    var_a2 = NULL;
    oldInterruptMask = osSetIntMask(1);
    while (current != NULL) {
        if (current == arg1) {
            if (var_a2 != NULL) {
                var_a2->next = arg1->next;
            } else {
                arg0->unk260 = arg1->next;
            }
            break;
        } else {
            var_a2 = current;
            current = current->next;
        }
    }
    osSetIntMask(oldInterruptMask);
}

// TODO: Is this returning &struct->unk58? Likely actor
s32 func_global_asm_8060EE58(s32 arg0) {
    return arg0 + 0x58;
}

// Jumptable, appears to be the main function of a thread
// rodata
// const char D_global_asm_80757140[] = "CURRENT=%x\n";
// const char D_global_asm_8075714C[] = "START=%x\n";
// const char D_global_asm_80757158[] = "END=%x\n";
// const char D_global_asm_80757160[] = "DPSTAT=%x\n";
// const char D_global_asm_8075716C[] = "SPSTAT=%x\n";
// const char D_global_asm_80757178[] = "MAIN-PC=%x\n";
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060EE60.s")

const u8 D_global_asm_80757184[] = {0,0,0,0};
const char D_global_asm_80757188[] = "WARNING!!";
// const char D_global_asm_80757194[] = "  %05x.:Triangle:.(%s)....\n";
// const char D_global_asm_807571B0[] = "  %08x.%08x.%08x.%08x\n";
// const char D_global_asm_807571C8[] = "  ----------------------------------\n";
// const char D_global_asm_807571F0[] = "  %05x.:.%s...%s.\n";
// const char D_global_asm_80757204[] = "  %08x..%08x............\n";
// const char D_global_asm_80757220[] = "  %08x.%08x.%08x.%08x...\n";
// const char D_global_asm_8075723C[] = " %05x  NOOP..........\n";
// const char D_global_asm_80757254[] = "  %05x Undef.............\n";

void func_global_asm_8060F1D0(Struct131B0_2 *arg0, Struct131B0_1 *arg1) {
    func_global_asm_8060F928(arg0, arg1);
    if (arg0->unk274 == 0) {
        func_global_asm_8060F960(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060F208.s")

extern OSTime D_global_asm_807F04D0;

/*
void func_global_asm_8060F208(Struct131B0_2 *arg0) {
    if (arg0->unk274 != 0) {
        func_global_asm_8060FA5C();
    } else {
        D_global_asm_807F04D0 = 0;
        func_global_asm_8060F960(arg0, 0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060F254.s")

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060F730.s")

// Struct131B0_2* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060F854.s")

void func_global_asm_8060F928(Struct131B0_2 *arg0, Struct131B0_1 *arg1) {
    s32 temp_v0;

    temp_v0 = arg1->unk10;
    if (temp_v0 == 2) {
        arg0->unk26C->next = arg1;
        arg0->unk26C = arg1;
    } else {
        arg0->unk270->next = arg1;
        arg0->unk270 = arg1;
    }
    arg1->next = NULL;
    arg1->unk4 = 2;
}

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060F960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060FA5C.s")

/*
extern OSTime D_global_asm_807F04C0;

// TODO: Something up with the OSTime write
void func_global_asm_8060FA5C(Struct131B0_2 *arg0) {
    Struct131B0_2_unk274 *temp_v0;

    temp_v0 = arg0->unk274;
    if (temp_v0->unk10 == 1) {
        temp_v0->unk4 = 3;
        D_global_asm_807F04C0 = osGetTime();
        osSpTaskYield();
    }
}
*/

void func_global_asm_8060FAA4(OSMesgQueue *arg0, OSMesg arg1, s32 arg2) {
    osGetTime();
    osGetTime();
    osSendMesg(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060FAE4.s")
