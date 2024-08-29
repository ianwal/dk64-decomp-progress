#include <ultra64.h>
#include "functions.h"

extern s8 D_global_asm_80746834;

extern OSContStatus D_global_asm_807ECCD0;
extern void *D_global_asm_807ECCE0;
extern OSMesgQueue D_global_asm_807ECCF0;
extern u8 D_global_asm_807ECD08;
extern u8 D_global_asm_807ECD09;
extern OSContPad D_global_asm_807ECD10[];
extern OSContPad D_global_asm_807ECD28;
extern OSContPad *D_global_asm_807ECDE8;
extern OSContPad *D_global_asm_807ECDF4;

u8 func_global_asm_8060A900(void) {
    osCreateMesgQueue(&D_global_asm_807ECCF0, &D_global_asm_807ECCE0, 4);
    osSetEventMesg(5, &D_global_asm_807ECCF0, NULL);
    osContInit(&D_global_asm_807ECCF0, &D_global_asm_807ECD09, &D_global_asm_807ECCD0);
    osContSetCh(4);
    if (!(D_global_asm_807ECD09 & 1)) {
        D_global_asm_807ECD09 = 0;
    }
    D_global_asm_807ECD08 = 0;
    D_global_asm_807ECDE8 = &D_global_asm_807ECD10[0];
    D_global_asm_807ECDF4 = &D_global_asm_807ECD28;
    func_global_asm_8060AA58(0xFF);
    func_global_asm_8060E958();
    return D_global_asm_807ECD09;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060A9BC.s")

extern u8 D_global_asm_807467C4; // should_poll_input

/*
// TODO: Hmm, might need complete segment defintions for this file for this to match
void func_global_asm_8060A9BC(void) {
    func_global_asm_8060AA04();
    if (!(D_global_asm_807467C4 & 0xFF)) {
        D_global_asm_807ECD08 = 1;
        func_dk64_boot_800073D0(&D_global_asm_807ECCF0);
    }
}
*/

void func_global_asm_8060AA04(void) {
    if (D_global_asm_807ECD08 != 0) {
        D_global_asm_80746834 = 2;
        osRecvMesg(&D_global_asm_807ECCF0, NULL, 1);
        D_global_asm_80746834 = 0;
        D_global_asm_807ECD08 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AA58.s")

extern u8 D_global_asm_807ECDFC[];

u8 func_global_asm_8060AB38(s32 arg0) {
    return D_global_asm_807ECDFC[arg0];
}

extern u8 D_global_asm_807ECDF8;

void func_global_asm_8060AB48(OSContPad * arg0) {
    s32 i, j;

    j = 0;
    for (i = 0; i < 4; i++) {
        if (D_global_asm_807ECDF8 & (1 << i)) {
            if (j != i) {
                arg0[j] = arg0[i];
            }
            j += 1;
        }
    }
}

u8 func_global_asm_8060AC28(void) {
    return D_global_asm_807ECDF8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AC34.s")

/*
void func_global_asm_8060AC34(OSContPad *arg0) {
    u8 * unk0;
    
    unk0 = &D_global_asm_807ECD08;
    if ((!D_global_asm_807467C4) && (*unk0)) {
        func_dk64_boot_80007454(arg0);
    }
    *unk0 = 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F600/func_global_asm_8060AC7C.s")

/*
void func_global_asm_806F3E0C(OSContPad *, OSContPad *);
void func_global_asm_80712944(OSContPad *);
extern u16 D_807ECD40[];
extern u16 D_807ECD50[];
extern OSContPad D_807ECD60;
extern u16 D_807ECD68[0x10];
extern u8 D_global_asm_807467C4;
extern s8 D_global_asm_80746834;
extern u8 D_global_asm_8076A0B1;
extern OSMesgQueue D_global_asm_807ECCF0;
extern u8 D_global_asm_807ECD09;
extern u16 D_global_asm_807ECDF0;
extern u8 D_global_asm_807ECDF8;
extern s32 func_global_asm_80611730;

void func_global_asm_8060AC7C(void) {
    OSContPad *temp_a1_2;
    OSContPad *temp_v1;
    OSContPad *var_t0;
    s16 *var_a0;
    s16 temp_a1_3;
    s16 var_t2;
    s32 *var_v0_2;
    s32 temp_t7;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 i;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    u16 *temp_t0;
    u16 *temp_v0_2;
    u16 temp_a1;
    u16 temp_a2;
    u16 temp_t6;
    u16 var_a3;
    u16 var_t9;

    temp_v0 = gameIsInAdventureMode();
    var_t0 = &D_global_asm_807ECD58;
    D_807ECD60 = D_global_asm_807ECD58;
    D_global_asm_807ECD58.button = 0;
    D_global_asm_807ECD58.stick_x = 0;
    D_global_asm_807ECD58.stick_y = 0;
    if ((D_global_asm_807ECD08) || (D_global_asm_807467C4)) {
        if ((!D_global_asm_807467C4) && (D_global_asm_807ECD08)) {
            D_global_asm_80746834 = 3;
            osRecvMesg(&D_global_asm_807ECCF0, NULL, 1);
            D_global_asm_80746834 = 0;
            func_global_asm_8060EA28();
            var_t0 = &D_global_asm_807ECD58;
        }
        switch (is_autowalking) {
        case 0:
            func_global_asm_80712944(D_global_asm_807ECDE8);
            func_global_asm_8060B110(D_global_asm_807ECDE8);
            var_t0 = &D_global_asm_807ECD58;
            break;
        case 2:
            func_global_asm_80712944(D_global_asm_807ECDF4);
            func_global_asm_8060B110(D_global_asm_807ECDF4);
            func_global_asm_8060B4D4(D_global_asm_807ECDE8);
            for (i = 0; i < 4; i++) {
                if (D_global_asm_807ECD09 & (1 << i)) {
                    temp_v1 = &D_global_asm_807ECDE8[i];
                    temp_v1->button |= (D_global_asm_807ECDF4[i].button & 0x1000);
                }
            }
            var_t0 = &D_global_asm_807ECD58;
            break;
        case 3:
            func_global_asm_80712944(D_global_asm_807ECDF4);
            func_global_asm_8060B110(D_global_asm_807ECDF4);
            func_global_asm_806F3E0C(D_global_asm_807ECDE8, D_global_asm_807ECDF4);
            var_t0 = &D_global_asm_807ECD58;
        }
    }
    if (temp_v0 != 0) {
        func_global_asm_8060AB48(D_global_asm_807ECDE8);
        var_t0 = &D_global_asm_807ECD58;
    }
    temp_a1 = var_t0->button;
    // Anti-tamper
    newly_pressed_input_copy = (temp_a1 ^ D_807ECD60.button) & temp_a1;
    var_v1 = 0;
    for (var_v0_2 = &func_global_asm_80611730; var_v0_2 < (s32 *)func_global_asm_80611844; var_v0_2++) {
        var_v1 += *var_v0_2;
    }
    var_s2 = 0;
    if (var_v1 != 0x624C9A6C) {
        object_timer = 0;
    }
    //
    var_s1_2 = 0;
    var_v0_3 = 0;
    for (var_v0_3 = 0; var_v0_3 < 4; var_v0_3++) {
        if (temp_v0 != 0) {
            var_v1_2 = D_global_asm_807ECDF8 & (1 << var_v0_3) & 0xFF;
        } else {
            var_v1_2 = D_global_asm_807ECD09 & (1 << var_v0_3) & 0xFF;
            var_s2 = var_v0_3;
        }
        if ((var_v0_3 == 0) && (is_autowalking == 2)) {
            var_v1_2 = (var_v1_2 | 1) & 0xFF;
        }
        if (var_v1_2 != 0) {
            temp_v1_2 = var_s2 * 2;
            temp_a1_2 = &D_global_asm_807ECD10[var_s2];
            temp_t0 = &D_807ECD40[var_s2];
            temp_a2 = temp_a1_2->button;
            var_t2 = (*temp_t0 ^ temp_a2) & temp_a2 & 0xFFFF;
            temp_v0_2 = &D_807ECD50[var_s2];
            *temp_t0 = temp_a2;
            var_a3 = temp_a2;
            if (is_autowalking == 0) {
                temp_t6 = temp_a2 & 0x1000;
                if (D_global_asm_8076A0B1 & 0x11) {
                    temp_a1_2->button = temp_t6;
                    temp_a1_2->stick_x = 0;
                    temp_a1_2->stick_y = 0;
                    var_t2 = 0;
                    var_a3 = temp_t6 & 0xFFFF;
                }
            }
            newly_pressed_input[temp_v1_2] = var_t2;
            var_a2 = 0;
            var_a0 = (var_s2 << 5) + &D_807ECD68;
            do {
                temp_v1_3 = 1 << var_a2;
                var_a2 += 1;
                if (var_a3 & temp_v1_3) {
                    *var_a0 -= 1;
                    temp_a1_3 = *var_a0;
                    if (temp_a1_3 <= 0) {
                        *var_a0 = 2;
                        var_t9 = *temp_v0_2 | temp_v1_3;
                        goto block_42;
                    }
                    if (temp_a1_3 == 0xB) {
                        *temp_v0_2 |= temp_v1_3;
                    } else {
                        *temp_v0_2 &= ~temp_v1_3;
                    }
                } else {
                    *var_a0 = 0xC;
                    var_t9 = *temp_v0_2 & ~temp_v1_3;
block_42:
                    *temp_v0_2 = var_t9;
                }
                var_a0 += 2;
            } while (var_a2 != 0x10);
            if (temp_v0 != 0) {
                var_s2 += 1;
            }
        }
    }
    D_global_asm_807ECDEC = &D_global_asm_807ECD10;
    D_global_asm_807ECDF0 = newly_pressed_input[0];
}
*/


void func_global_asm_8060B110(OSContPad *arg0) {
    D_global_asm_807ECD58.button = arg0->button;
    D_global_asm_807ECD58.stick_x = arg0->stick_x;
    D_global_asm_807ECD58.stick_y = arg0->stick_y;
}
