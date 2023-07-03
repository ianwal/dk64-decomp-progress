#include <ultra64.h>
#include "functions.h"


void func_8060EC54(s32);
void func_8060E6E8(s32);
u8 func_8060AC28();
void func_8060E4D0(u8);
void func_8060E664(u8);
void func_8060EC54(s32);
void func_8060E8CC(Struct807F0470*);
u8 func_8060AB38(s32);

extern s32 D_80746810;
extern u8 D_80746818;
extern u8 D_8076A0B1;
extern u8 D_807ECD09;
extern OSMesgQueue D_807ECCF0;

void func_8060E4B0(Struct807F0470 *arg0) {
    bzero(arg0, sizeof(Struct807F0470));
}

void func_8060E4D0(u8 arg0) {
    Struct807F0470 *temp = &D_807F0470[arg0];

    if (osMotorStartStop(&D_807F02D0[arg0], 1) == 4) {
        func_8060E4B0(temp);
        temp->unk0 = 3;
    } else {
        temp->unk4 = 1;
    }
}

void func_8060E574(u8 arg0) {
    OSPfs *temp_a1;

    switch (osMotorInit(&D_807ECCF0, &D_807F02D0[arg0], arg0)) {
        case 0:
            D_807F0470[arg0].unk0 = 1;
            return;
        case 1:
            D_807F0470[arg0].unk0 = 0;
            return;
        case 11:
            D_807F0470[arg0].unk0 = 2;
            return;
        case 4:
            D_807F0470[arg0].unk0 = 3;
            return;
    }
}

void func_8060E664(u8 arg0) {
    func_8060E574(arg0);
    osMotorStartStop(&D_807F02D0[arg0], 0);
    osMotorStartStop(&D_807F02D0[arg0], 0);
    osMotorStartStop(&D_807F02D0[arg0], 0);
    D_807F0470[arg0].unk4 = 0;
}

void func_8060E6E8(s32 arg0) {
    s32 phi_s0;
    s32 phi_s3;

    for (phi_s3 = 0; phi_s3 < 4; phi_s3++) {
        func_8060E4B0(&D_807F0470[phi_s3]);
        D_807F0470[phi_s3].unk0 = 0;
        if (D_807ECD09 & (1 << phi_s3)) {
            for (phi_s0 = 0; phi_s0 < 2; phi_s0++) {
                func_8060E664(phi_s3);
            }
        }
    }
}

s32 func_8060E79C(u8 arg0) {
    if (arg0 >= 4) {
        return 0;
    }
    return D_807F0470[func_8060AB38(arg0)].unk0;
}

// TODO: Cleanup, get rid of the block label
void func_8060E7EC(u8 arg0, u8 arg1, s32 arg2) {
    Struct807F0470 *temp_a0 = &D_807F0470[func_8060AB38(arg0)];

    if ((D_80746810 != 1)
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

void func_8060E8CC(Struct807F0470 *arg0) {
    if (arg0->unk0 == 1) {
        arg0->unk5 = 0;
        arg0->unkC = 0;
    }
}

void func_8060E8EC(u8 arg0) {
    func_8060E8CC(&D_807F0470[func_8060AB38(arg0)]);
}

void func_8060E930() {
    func_8060E6E8(1);
    func_8060EC54(1);
}

void func_8060E958() {
    func_8060E6E8(0);
    func_8060EC54(1);
}

// TODO: Why can't this be s32 and still match?
int func_8060E980(void) {
    return (global_properties_bitfield & 0x4002)
        || (D_8076A0B1 & 1)
        || func_8062919C()
        || func_8061CB50()
        || (!gameIsInAdventureMode() && !gameIsInMysteryMenuMinigameMode() && !gameIsInSnidesBonusGameMode());
}

void func_8060EA28(void) {
    Struct807F0470 *phi_s0;
    s32 temp;
    s32 phi_s1;
    u8 sp23;

    phi_s0 = &D_807F0470[0];
    if (D_80746810 == 1) {
        if (!func_8060E980()) {
            func_8060EC54(0);
        }
    } else if (func_8060E980()) {
        func_8060EC54(1);
    }
    if (D_80746818) {
        func_8060E6E8(0);
    }
    D_80746818 = 0;
    if (D_80746810 != 1) {
        sp23 = func_8060AC28();
        for (phi_s1 = 0; phi_s1 < 4; phi_s1++) {
            if (phi_s0->unk0 != 1) {
                if (((D_807ECD09 & (1 << phi_s1))) && ((sp23 & (1 << phi_s1))) && ((object_timer % 15U) == 0)) {
                    func_8060E664(phi_s1);
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
                        func_8060E664(phi_s1);
                    }
                } else {
                    if (phi_s0->unkC) {
                        phi_s0->unkC--;
                        phi_s0->unk10++;
                    }
                    if ((phi_s0->unkC == 0) || phi_s0->unk12) {
                        func_8060E8CC(phi_s0);
                    } else {
                        if (phi_s0->unk8 >= 0x100U) {
                            if (phi_s0->unk4 == 0) {
                                func_8060E4D0(phi_s1);
                            }
                            phi_s0->unk8 -= 0x100;
                        } else {
                            temp = phi_s0->unk5;
                            phi_s0->unk8 += temp * 4;
                            if (phi_s0->unk4) {
                                func_8060E664(phi_s1);
                            }
                        }
                    }
                }
            }
            phi_s0++;
        }
    }
}

void func_8060EC54(s32 arg0) {
    if (arg0 != D_80746810) {
        D_80746810 = arg0;
        D_80746818 = 1;
    }
}

// osCreateThread, osStartThread, function pointer, neat
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060EC80.s")

typedef struct GlobalASMStruct6 GlobalASMStruct6;

struct GlobalASMStruct6 {
    GlobalASMStruct6 *next;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

typedef struct {
    u8  pad0[0x260 - 0x0];
    GlobalASMStruct6 *unk260;
    s32 unk264;
    s32 unk268;
    GlobalASMStruct6 *unk26C;
    GlobalASMStruct6 *unk270;
    s32 unk274;
} GlobalASMStruct87;

void func_8060ED6C(GlobalASMStruct87 *arg0, GlobalASMStruct6 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    OSIntMask oldInterruptMask = osSetIntMask(OS_IM_NONE);
    arg1->unk4 = arg2;
    arg1->next = arg0->unk260;
    arg0->unk260 = arg1;
    arg1->unk8 = arg3;
    arg1->unkC = arg4;
    osSetIntMask(oldInterruptMask);
}

void func_8060EDD0(GlobalASMStruct87 *arg0, GlobalASMStruct6 *arg1) {
    GlobalASMStruct6 *current;
    GlobalASMStruct6 *var_a2;
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
s32 func_8060EE58(s32 arg0) {
    return arg0 + 0x58;
}

// Jumptable, appears to be the main function of a thread
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060EE60.s")

void func_8060F928(GlobalASMStruct87*, GlobalASMStruct6*);

void func_8060F1D0(GlobalASMStruct87 *arg0, GlobalASMStruct6 *arg1) {
    func_8060F928(arg0, arg1);
    if (arg0->unk274 == 0) {
        func_8060F960(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060F208.s")

extern OSTime D_807F04D0;

/*
void func_8060F208(GlobalASMStruct87 *arg0) {
    if (arg0->unk274 != 0) {
        func_8060FA5C();
    } else {
        D_807F04D0 = 0;
        func_8060F960(arg0, 0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060F254.s")

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060F730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060F854.s")

void func_8060F928(GlobalASMStruct87 *arg0, GlobalASMStruct6 *arg1) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060F960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060FA5C.s")

/*
extern OSTime D_807F04C0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} GlobalASMStruct87_unk274;

// TODO: Something up with the OSTime write
void func_8060FA5C(GlobalASMStruct87 *arg0) {
    GlobalASMStruct87_unk274 *temp_v0;

    temp_v0 = arg0->unk274;
    if (temp_v0->unk10 == 1) {
        temp_v0->unk4 = 3;
        D_807F04C0 = osGetTime();
        osSpTaskYield();
    }
}
*/

void func_8060FAA4(OSMesgQueue *arg0, OSMesg arg1, s32 arg2) {
    osGetTime();
    osGetTime();
    osSendMesg(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_8060FAE4.s")
