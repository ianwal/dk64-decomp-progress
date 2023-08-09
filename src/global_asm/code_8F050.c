#include <ultra64.h>
#include "functions.h"


// TODO: What are the actual datatypes?
s32 func_global_asm_8068A3A0(s32, u32 *);
void func_global_asm_8068A404(Actor*, s32, s32);
void func_global_asm_80613794(Actor*, u8);
s32 func_global_asm_80612E90(Actor*, s16, s32);

void func_global_asm_8068A350(Actor *arg0, s32 arg1, s32 arg2) {
    func_global_asm_8068842C(arg0, arg1, -1);
    func_global_asm_80688460(arg0, arg1, 1);
    func_global_asm_806883F4(arg0, arg1, arg2, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_global_asm_8068A3A0.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4; // Used
    u8 unk8; // Used
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC[2];
} GlobalASMStruct76;

extern GlobalASMStruct76 D_global_asm_80750100[];

/*
// TODO: Fiddly, might want another look at the mips_to_c output
s32 func_global_asm_8068A3A0(s32 arg0, u32 *arg1) {
    u16 i;
    s32 found;

    found = FALSE;
    i = 0;
    *arg1 = i;
    for (i = 0; i < 7U & !found; i++) {
        if (arg0 == D_global_asm_80750100[i].unk0) {
            found = TRUE;
        } else {
            *arg1 = i;
        }
    }
    return found;
}
*/

void func_global_asm_8068A404(Actor *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 var_s0;

    if (arg0->unk4C == 0) {
        arg0->unk4C = func_global_asm_80612E90(arg0, D_global_asm_80750100[arg1].unk2, 0);
    }
    for (var_s0 = 0; var_s0 < 2; var_s0++) {
        temp_a1 = D_global_asm_80750100[arg1].unkC[var_s0];
        if (temp_a1 != -1) {
            func_global_asm_8068A350(arg0, temp_a1, arg2);
        }
    }
}

void func_global_asm_8068A4C8(Actor *arg0, s32 arg1, s32 arg2) {
    s32 sp1C;

    if (func_global_asm_8068A3A0(arg1, &sp1C)) {
        func_global_asm_8068A404(arg0, sp1C, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F050/func_global_asm_8068A508.s")

extern s32 D_global_asm_807552F4[];

/*
// TODO: Close, float nonsense
void func_global_asm_8068A508(void) {
    s32 sp80;
    f32 dz;
    f32 temp_f0_2;
    f32 dy;
    f32 temp_f20;
    f32 dx;
    s32 temp_a2;
    s32 i;
    Actor *temp_s0;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_s0 = D_global_asm_807FB930[i].unk0;
        if (!(temp_s0->object_properties_bitfield & 0x2000) && (temp_s0->object_properties_bitfield & 0x100)) {
            dx = temp_s0->x_position - character_change_array->look_at_eye_x;
            dz = temp_s0->z_position - character_change_array->look_at_eye_z;
            dy = temp_s0->y_position - character_change_array->look_at_eye_y;
            temp_f20 = (dz * dz) + ((dx * dx) + (dy * dy));
            if (func_global_asm_8068A3A0(temp_s0->unk58, &sp80) != 0) {
                temp_f0_2 = func_global_asm_8065D0FC(D_global_asm_80750100[sp80].unk4);
                switch (D_global_asm_80750100[sp80].unk8) {
                    case 0:
                        if (cc_number_of_players >= 2) {
                            temp_a2 = D_global_asm_807552F4[temp_s0->PaaD->unk1A4];
                            if (temp_a2 >= 0) {
                                func_global_asm_8068A404(temp_s0, sp80, temp_a2);
                            }
                        }
                        break;
                    case 1:
                        if ((temp_f0_2 * temp_f0_2) < temp_f20) {
                            if (temp_s0->unk4C == 0) {
                                temp_s0->unk4C = func_global_asm_80612E90(temp_s0, D_global_asm_80750100[sp80].unk2, 0);
                            }
                        } else if (temp_s0->unk4C != 0) {
                            func_global_asm_80613794(temp_s0, 1);
                        }
                        break;
                    case 2:
                        if (temp_f20 < (temp_f0_2 * temp_f0_2)) {
                            if (temp_s0->unk4C == 0) {
                                temp_s0->unk4C = func_global_asm_80612E90(temp_s0, D_global_asm_80750100[sp80].unk2, 0);
                            }
                        } else if (temp_s0->unk4C != 0) {
                            func_global_asm_80613794(temp_s0, 1);
                        }
                        break;
                    }
            }
        }
    }
}
*/

void func_global_asm_8068A764(Actor *arg0, u8 arg1) {
    arg0->unk146_s16 |= 1 << arg1;
}

void func_global_asm_8068A784(Actor *arg0, u8 arg1) {
    arg0->unk146_s16 &= ~(1 << arg1);
}
