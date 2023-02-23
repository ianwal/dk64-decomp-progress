#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 *D_807FC7E0;
extern u16 D_807ECD58;
extern s8 D_80750560[];

extern void func_806ACA88(void);

s32 func_806A80C0(s8 arg0) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (arg0 == D_80750560[i]) {
            return i;
        }
    }
    return 0;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A8158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A9124.s")

void func_8061130C(s32);
void func_8061134C(s32);
extern s32 *D_807FC7E8;

typedef struct TempStruct807FC7F0 {
    s32 unk0;
    s32 unk4;
} TempStruct807FC7F0;

typedef struct TempStruct807FC7F8 {
s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
} TempStruct807FC7F8;

extern TempStruct807FC7F0 D_807FC7F0;
extern TempStruct807FC7F8 D_807FC7F8;

/*
// TODO: Close, doable
// TODO: Regalloc, something iffy with global_properties_bitfield set
void func_806A9124(void) {
    s32 temp_t8;
    s32 var_s0;
    s32 var_s0_2;

    temp_t8 = global_properties_bitfield | 0x40;
    global_properties_bitfield = temp_t8;
    if (!(player_pointer->PaaD->unk1F0 & 0x20000000)) {
        global_properties_bitfield |= 0x10030;
    }
    func_8061130C(D_807FC7F0.unk0);
    D_807FC7F0.unk0 = 0;
    D_807FC7F0.unk4 = 0;
    D_807FC7F8.unk0 = 0;
    D_807FC7F8.unk1 = 0;
    for (var_s0 = 0; var_s0 < 27; var_s0++) {
        func_8061134C(D_807FC7E0[var_s0]);
    }
    func_8061134C(D_807FC7E0);
    for (var_s0 = 0; var_s0 < 9; var_s0++) {
        func_8061134C(D_807FC7E8[var_s0]);
    }
    func_8061134C(D_807FC7E8);
}
*/

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A921C.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806A92B4.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AA09C.s")

// TODO: Surprisingly doable, good target
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AA304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AB4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AB808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABA6C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABB98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ABE3C.s")

void func_806AC048(s32 arg0, s32 arg1) {
    func_80703374(arg0, 0, 0, 0, 0x46);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806AC07C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ACA88.s")

void func_806ACC00(u8 arg0) {
    func_80677FA8(0x156, 0); // Spawn actor: Try Again Dialog
    D_807FBB44->unk15F = arg0;
    D_807FBB44->unk64 |= 2;
    global_properties_bitfield |= 0x40001;
}

void func_806ACC64() {
    s16 i;

    global_properties_bitfield |= 0x40;
    for (i = 0; i < 3; i++) {
        func_8061134C(D_807FC7E0[i]);
    }
    func_8061134C(D_807FC7E0);
    func_806782C0(current_actor_pointer);
}

void func_806ACCE8(void) {
    s32 i;

    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->unk168 = 0x1E;
        current_actor_pointer->shadow_opacity = 0;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        D_807FC7E0 = malloc(0xC);
        for (i = 0; i < 3; i++) {
            D_807FC7E0[i] = func_8070E750(0x24, i + 0xF, 0);
        }
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
    } else if (current_actor_pointer->control_state == 0) {
        if (D_807ECD58 & 0x8000) {
            switch (current_actor_pointer->unk15F) {
                case 2:
                    playCutscene(NULL, 0x20, 1);
                    func_806ACC64();
                    break;
                case 3:
                case 4:
                    func_80724994(3, 7, 0x30, 0, 0);
                    func_806ACC64();
                    break;
                default:
                    func_805FF378(current_map, 0);
                    break;
            }
            current_actor_pointer->control_state = 1;
        } else if (D_807ECD58 & 0x4000) {
            switch (current_actor_pointer->unk15F) {
                case 3:
                case 4:
                    func_80724994(3, 7, 0x3C, 0, 0);
                case 2:
                    func_806ACC64();
                    break;
                case 1:
                    func_805FF544();
                    break;
                default:
                    func_805FF898();
                    break;
            }
            current_actor_pointer->control_state = 1;
        }
    }
    func_8068C350(&func_806ACA88, current_actor_pointer, 5);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ACF10.s")

// TODO: Good target, doable, as long as NOPs don't screw us at end of function
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_ACDC0/func_806ACFFC.s")

/*
extern s8 D_8076A105;
extern s8 D_807FC80E;
extern s8 D_807FC8B9;

void func_806ACF10(void);

// TODO: Very close, something wrong with the do while loops?
void func_806ACFFC(void) {
    s32 var_s1;
    s8 temp_v0_2;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FC7E0 = malloc(0x10);
        var_s1 = 0;
        do {
            D_807FC7E0[var_s1] = func_8070E750(0x24, var_s1, 0);
            var_s1++;
        } while (var_s1 != 4);
        global_properties_bitfield &= 0xFFFEFFCF;
        func_806291B4(7);
        D_807FC80E = 0;
        current_actor_pointer->control_state_progress = 0;
    }
    temp_v0_2 = character_change_array[D_807FC8B9].unk294->unk3;
    if ((temp_v0_2 >= 0x33) || (temp_v0_2 < -0x32)) {
        if (!(D_807FC80E & 1)) {
            current_actor_pointer->control_state_progress = 1 - current_actor_pointer->control_state_progress;
            D_807FC80E |= 1;
            playSound(0x2A0, 0x7FFF, 63.0f, 1.0f, 0, 0);
        }
    } else {
        D_807FC80E &= 0xFFFE;
    }
    if (character_change_array[D_807FC8B9].new_controller_inputs & A_BUTTON) {
        if (current_actor_pointer->control_state_progress == 0) {
            global_properties_bitfield |= 0x10070;
            var_s1 = 0;
            do {
                func_8061134C(D_807FC7E0[var_s1]);
                var_s1++;
            } while (var_s1 != 0x10);
            func_8061134C(D_807FC7E0);
        } else if (current_actor_pointer->control_state_progress == 1) {
            D_8076A105 = -1;
            func_80714638();
            current_actor_pointer->control_state_progress = 2;
        }
    }
    func_8068C350(&func_806AC048, current_actor_pointer, 1);
    func_8068C350(&func_806ACF10, current_actor_pointer, 5);
}
*/
