#include <ultra64.h>
#include "functions.h"
#include "sched.h"

typedef struct Unk807F0540 {
	/* 0x00 */ char unk_00[0x18];
	/* 0x18 */ OSMesgQueue* queue;
	/* 0x1C */ OSMesg mesg;
} Unk807F0540;

extern Unk807F0540 D_global_asm_807F0540;

typedef struct Unk807F04E0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    void* framebuffer;
    char unk_10[0x44];
    s32 unk_54;
    s32 unk_58;
} Unk807F04E0;

extern s32 D_global_asm_80746810;
extern u8 D_global_asm_80746818;
extern u8 D_global_asm_8076A0B1;
extern u8 D_global_asm_807ECD09;
extern OSMesgQueue D_global_asm_807ECCF0;
void func_global_asm_8060FA5C(Struct131B0_2 *arg0);
void func_global_asm_8060EE60(void*);
extern s8 D_global_asm_80744510;
extern OSViMode D_dk64_boot_8000EF20[];
extern u16 *D_global_asm_80744470[2];

/* BSS */
OSPfs D_global_asm_807F02D0[4];
Struct807F0470 D_global_asm_807F0470[4];
OSTime D_global_asm_807F04C0;
OSTime D_global_asm_807F04C8;
OSTime D_global_asm_807F04D0;
s32 D_global_asm_807F04D8; //unk type
s32 D_global_asm_807F04DC; //unk type
OSScTask* D_global_asm_807F04E0;
s32 D_global_asm_807F04E4; //unk type
u32 D_global_asm_807F04E8;
u32 D_global_asm_807F04EC;
u32 D_global_asm_807F04F0;
u32 D_global_asm_807F04F4;

OSTime D_global_asm_807F04F8;
OSTime D_global_asm_807F0500;
OSTime D_global_asm_807F0508;
OSTime D_global_asm_807F0510;

typedef struct Unk807F0518 {
	u16 unk_00;
	char pad[0x26];
} Unk807F0518; //sizeof 0x28

Unk807F0518 D_global_asm_807F0518;

Unk807F0540 D_global_asm_807F0540;
s32 D_global_asm_807F0560; //unk type
s32 D_global_asm_807F0564; //unk type
s16 D_global_asm_807F0568; //unk type

/* .data */
s32 D_global_asm_80746810 = 1;
s32 D_global_asm_80746814 = 0; //unused?
u8 D_global_asm_80746818 = 1;
s32 D_global_asm_8074681C = 0;
// u8 D_global_asm_80746819[] = {0, 0, 0, 0, 0, 0, 0}; //unused?
s32 D_global_asm_80746820 = 2;
s32 D_global_asm_80746824 = 1;
u8 D_global_asm_80746828 = 1;
// u8 D_global_asm_80746829[] = {0, 0, 0}; //unused?
s16 D_global_asm_8074682C = 1000;
// s16 D_global_asm_8074682E = 0; //unused?
u8 D_global_asm_80746830 = 1;
// u8 D_global_asm_80746831[] = {0, 0, 0}; //unused
u8 D_global_asm_80746834 = 0;
// u8 D_global_asm_80746835[] = {0, 0, 0}; //unused


void func_global_asm_8060E4B0(Struct807F0470 *arg0) {
    bzero(arg0, sizeof(Struct807F0470));
}

void func_global_asm_8060E4D0(u8 arg0) {
    Struct807F0470 *temp = &D_global_asm_807F0470[arg0];

    if (__osMotorAccess(&D_global_asm_807F02D0[arg0], 1) == 4) {
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
    __osMotorAccess(&D_global_asm_807F02D0[arg0], 0);
    __osMotorAccess(&D_global_asm_807F02D0[arg0], 0);
    __osMotorAccess(&D_global_asm_807F02D0[arg0], 0);
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
            } else {
                return;
            }
        }
        temp_a0->unkC = arg2;
        temp_a0->unk5 = arg1;
        
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

s32 func_global_asm_8060E980(void) {
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
void func_global_asm_8060EC80(Struct131B0_2* arg0, void* arg1, s32 arg2, s32 arg3, u8 arg4) {
    s32 sp2C[3] = {15, 0, 28}; //D_global_asm_80746838

    arg0->unk26C = (Struct131B0_1* ) &arg0->unk264;
    arg0->unk270 = (Struct131B0_1* ) &arg0->unk268;
    D_global_asm_807F04E0 = NULL;
    osCreateMesgQueue((OSMesgQueue* ) arg0, &arg0->func, 0x10);
    osCreateMesgQueue((OSMesgQueue* ) &arg0->mesgQueue, &arg0->unk70, 0x10);
    osSetEventMesg(4, (OSMesgQueue* ) arg0, (void* )0x29B);
    osSetEventMesg(9, (OSMesgQueue* ) arg0, (void* )0x29C);
    osViSetEvent((OSMesgQueue* ) arg0, (void* )0x29A, (u32) arg4);
    osCreateThread(&arg0->unkB0, 5, func_global_asm_8060EE60, arg0, arg1, arg2);
    osStartThread(&arg0->unkB0);
}

/* .data continued */
s8 D_global_asm_80746844 = 1;
s8 D_global_asm_80746848 = 0;
s32 D_global_asm_8074684C[] = {15, 2, 30};

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

void func_global_asm_8060F960(Struct131B0_2 *, s32);

void func_global_asm_8060F1D0(Struct131B0_2 *arg0, Struct131B0_1 *arg1) {
    func_global_asm_8060F928(arg0, arg1);
    if (arg0->unk274 == 0) {
        func_global_asm_8060F960(arg0, 1);
    }
}

s32 func_global_asm_8060F854(Struct131B0_2 *, OSScTask *);

void func_global_asm_8060F208(Struct131B0_2 *arg0) {
    if (arg0->unk274 != NULL) {
        func_global_asm_8060FA5C(arg0);
    } else {
        D_global_asm_807F04D0 = 0;
        func_global_asm_8060F960(arg0, 0);
    }
}

void func_global_asm_8060F254(Struct131B0_2* arg0) {
    static s16 D_global_asm_80746858 = 0;
    Struct131B0_1* sp54;
    s32 temp_a0;
    Struct131B0_1* temp_v0_3;
    s32 sp48;
    s32 i;

    arg0->unk_284 += 1;
    arg0->unk_280 += 1;
    D_global_asm_807F04F8 = osGetTime();

    if (D_global_asm_80744510 != 0) {
        if (D_global_asm_80744510 == 1) {
            if (D_global_asm_80746858 == 0) {
                osViBlack(1);
            }
            if (D_global_asm_80746858 == 0x3C) {
                osViSetMode(&D_dk64_boot_8000EF20[D_global_asm_8074684C[osTvType]]);
                osViSetSpecialFeatures(0x42U);
                osViBlack(0);
                D_global_asm_80744510 = 2;
            }
            D_global_asm_80746858 += 1;
        }
        osViSwapBuffer(*D_global_asm_80744470);
    }

    if (D_global_asm_807F04E0 != NULL) {
        if (D_global_asm_8076A0B1 & 2) {
            D_global_asm_8076A0B1 ^= 2;
            osViBlack(0);
        }
        osViSwapBuffer(D_global_asm_807F04E0->framebuffer);
        D_global_asm_80746824 = D_global_asm_80746820;
        D_global_asm_80746820 = arg0->unk_284 + 1;
        osDpSetStatus(8);
        temp_a0 = D_global_asm_807F04E0->msgQ;
        if (temp_a0 != 0) {
            func_global_asm_8060FAA4((OSMesgQueue* ) temp_a0, (void* ) D_global_asm_807F04E0->msg, 0);
        }
        D_global_asm_807F04E0 = NULL;
    } else {
        if ((osViGetCurrentFramebuffer() == osViGetNextFramebuffer()) && (osDpGetStatus() & 2)) {
            arg0->unk_288 = osGetTime();
            osDpSetStatus(4U);
        }
    }
    for (i = 0, sp48 = arg0->unk_60; i < sp48; i++) {
        //the i == -1 is definitely fake, but we have no way to know what was actually written here
        if (osRecvMesg(&arg0->mesgQueue, &sp54, OS_MESG_NOBLOCK) == -1 || i == -1) {
            
        }
        if (((u32) arg0->unk_284 % (u32) sp54->unk_50->unk_08) == 0) {
            func_global_asm_8060F928(arg0, (Struct131B0_1* ) sp54);
        } else {
            osSendMesg(&arg0->mesgQueue, sp54, OS_MESG_NOBLOCK);
        }        
    }

    if ((arg0->unk264 != 0) && !(arg0->unk_284 & 1)) {
        osSetTimer(&D_global_asm_807F0540, 0x445C0, 0, arg0->unk264->unk_50->unk_04, (void* )5);
    }
    
    for (temp_v0_3 = arg0->unk260; temp_v0_3 != NULL; temp_v0_3 = temp_v0_3->next) {
        if (temp_v0_3->unkC == 3) {
            osSendMesg((OSMesgQueue* ) temp_v0_3->unk4, (void* )0x29A, 0);
        }  
    }
}

/* .data continued */
typedef struct RDPDebugStrings {
    /* 0x00 */ u8 type;
    /* 0x01 */ char string[13];
    /* 0x0E */ u16 unk_0E;
} RDPDebugStrings; //size of 0x10

RDPDebugStrings D_global_asm_8074685C[] = {
    {0xFF, "SETCIMG", 0x0800},
    {0xFE, "SETZIMG", 0x0800},
    {0xFD, "SETTIMG", 0x0800},
    {0xFC, "SETCMBMODE", 0x0800},
    {0xFB, "SETENVCOL", 0x0800},
    {0xFA, "SETPRIMCOL", 0x0800},
    {0xF9, "SETBLENDCOL", 0x0800},
    {0xF8, "SETFOGCOL", 0x0800},
    {0xF7, "SETFILLCOL", 0x0800},
    {0xF6, "FILLRECT", 0x0801},
    {0xF5, "SETTILE ", 0x0800},
    {0xF4, "LOADTILE", 0x0801},
    {0xF3, "LOADBLK ", 0x0801},
    {0xF2, "SETTILESZ", 0x0800},
    {0xF0, "LOADTLUT", 0x0800},
    {0xEF, "SETOTHRMODE", 0x0800},
    {0xEE, "SETPRMDP", 0x0800},
    {0xED, "SETSCSR", 0x0800},
    {0xEC, "SETCONV", 0x0800},
    {0xEB, "SETKEYR", 0x0800},
    {0xEA, "SETKEYGB", 0x0800},
    {0xE9, "FULLSYNC", 0x0800},
    {0xE8, "TILESYNC", 0x0800},
    {0xE7, "PIPESYNC", 0x0800},
    {0xE6, "LOADSYNC", 0x0800},
    {0xE5, "RECTFLIP", 0x1001},
    {0xE4, "TEXRECT", 0x1001},
};
char* D_global_asm_80746A0C[] = {D_global_asm_80757184, D_global_asm_80757188};
s32 D_global_asm_80746A14 = 0;
s32 D_global_asm_80746A18 = 0;
s16 D_global_asm_80746A1C = 0;
s32 D_global_asm_80746A20 = 0;
s32 D_global_asm_80746A24 = 0;
s32 D_global_asm_80746A28 = 0;
s8 D_global_asm_80746A2C = 4;

void func_global_asm_8060F54C(Struct131B0_2 *arg0) {
    OSScTask *temp_s0;
    Struct131B0_2_unk268 *temp_v0;

    temp_s0 = arg0->unk274;
    arg0->unk274 = NULL;
    if (temp_s0->state == OS_SC_RDP_DONE_MSG) {
        D_global_asm_807F04D0 = osGetTime() - D_global_asm_807F04C0;
        if (D_global_asm_807F04D0 > D_global_asm_807F04C8) {
            D_global_asm_807F04C8 = D_global_asm_807F04D0;
        }
        if (osSpTaskYielded(&temp_s0->list) == 0) {
            temp_s0->state = OS_SC_DONE_MSG;
            temp_s0->flags |= OS_SC_DRAM_DLIST;
            func_global_asm_8060F854(arg0, temp_s0);
        }
        func_global_asm_8060F960(arg0, 0);
        return;
    }
    if (temp_s0->flags & OS_SC_SWAPBUFFER) {
        D_global_asm_807F04E8 = (osGetTime() - arg0->unk290) / 0x1E91;
        D_global_asm_80746828 = 1;
    } else if (temp_s0->list.t.type == 2) {
        D_global_asm_807F0510 = osGetTime();
        D_global_asm_807F0500 = D_global_asm_807F0508;
    }
    temp_s0->state = OS_SC_DONE_MSG;
    temp_s0->flags |= OS_SC_DRAM_DLIST;
    if (func_global_asm_8060F854(arg0, temp_s0)) {
        temp_v0 = arg0->unk268;
        if ((temp_v0) && (temp_v0->unk8 != 0x47)) {
            func_global_asm_8060F960(arg0, 1);
        }
    }
}

void func_global_asm_8060F730(Struct131B0_2* arg0) {
    OSScTask* temp_s0;
    s32 var_v0;

    temp_s0 = arg0->unk_278;
    arg0->unk_278 = NULL;
    temp_s0->flags |= 8;
    var_v0 = 0;
    if ((is_cutscene_active == 3) || (is_cutscene_active == 4)) {
        var_v0 = 1;
    }
    if ((var_v0 != 0) || (D_global_asm_80746820 != arg0->unk_284)) {
        D_global_asm_807F04E0 = NULL;
        if (D_global_asm_8076A0B1 & 2) {
            D_global_asm_8076A0B1 ^= 2;
            osViBlack(0);
        }
        osViSwapBuffer(temp_s0->framebuffer);
        D_global_asm_80746824 = D_global_asm_80746820;
        D_global_asm_80746820 = arg0->unk_284 + 1;
        osDpSetStatus(8);
    } else {
        D_global_asm_807F04E0 = temp_s0;
    }
    D_global_asm_807F04E4 = (osGetTime() - arg0->unk_288) / 0x1E91;
    func_global_asm_8060F854(arg0, temp_s0);
}

s32 func_global_asm_8060F854(Struct131B0_2* arg0, OSScTask* arg1) {
    u32 temp_t6;
    s32 temp_v0;
    s32 var_v1;
    u32 var_v1_2;
    u32 temp_t0;

    temp_v0 = arg1->flags;
    temp_t0 = arg1->list.t.type;
    var_v1_2 = temp_v0 & 3;
    temp_t6 = ((u32) temp_v0 >> 2) & 3;

    if (!(temp_v0 & 0x40)) {
        var_v1_2 = var_v1_2 & 1;
        temp_v0 = 1;
        temp_t6 = temp_t6 & temp_v0;
    }
    if (var_v1_2 == temp_t6) {
        if (temp_t0 == 1) {
            arg0->unk268 = (Struct131B0_2_unk268*) arg0->unk268->unk0;
            if (arg0->unk268 == 0) {
                arg0->unk270 = (Struct131B0_1*) &arg0->unk268;
            }
        }
        if ((arg1->msgQ != NULL) && ((D_global_asm_807F04E0 == NULL) || (temp_t0 != 1))) {
            if (arg1->flags & 0x40) {
                func_global_asm_8060FAA4(arg1->msgQ, arg1->msg, 0);
            } else {
                osSendMesg(arg1->msgQ, arg1->msg, 0);
            }
        }
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    D_global_asm_807F0564 = var_v1;
    return var_v1;
}

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

void func_global_asm_8060F960(Struct131B0_2* arg0, s32 arg1) {
    OSScTask* var_s1;

    if (arg1 == 0) {
        var_s1 = arg0->unk264;
        if (arg0->unk264 != NULL) {
            arg0->unk264 = arg0->unk264->next;
            if (arg0->unk264 == NULL) {
                arg0->unk26C = (Struct131B0_1* ) &arg0->unk264;
            }
            D_global_asm_807F0508 = osGetTime();
        } else {
            return;
        }
    } else {
        var_s1 = arg0->unk268;
        if ((u8) D_global_asm_80746828 != 0) {
            arg0->unk290 = osGetTime();
            D_global_asm_807F04F0 = (osGetTime() - D_global_asm_807F04F8) / 0x1E91;
            D_global_asm_80746828 = 0;
        }
    }

    var_s1->state = 1;
    osSpTaskStart(&var_s1->list);
    arg0->unk274 = var_s1;
    if (var_s1->flags & 0x40) {
        arg0->unk_278 = var_s1;
    }
}

void func_global_asm_8060FA5C(Struct131B0_2 *arg0) {
    OSScTask *temp_v0;

    temp_v0 = arg0->unk274;
    if (temp_v0->list.t.type == 1) {
        temp_v0->state = 3;
        D_global_asm_807F04C0 = osGetTime();
        osSpTaskYield();
    }
}


void func_global_asm_8060FAA4(OSMesgQueue *arg0, OSMesg arg1, s32 arg2) {
    osGetTime();
    osGetTime();
    osSendMesg(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_131B0/func_global_asm_8060FAE4.s")
