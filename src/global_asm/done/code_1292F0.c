#include "common.h"

void func_global_asm_80723CCC(s32, s32, f32, f32 *, f32 *, f32 *);
void func_global_asm_80723F88(s16, f32, f32, f32, void *, void *);

void func_global_asm_807245F0(Actor *arg0, u8 arg1) {
    s32 temp_a0;
    s32 var_v1;
    s32 temp_a1; // 6C
    f32 temp_f0; // 68
    f32 sp64, sp60, sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s16 temp1;
    Actor118 *var_s0;
    u8 sp47;

    sp47 = FALSE;
    if (arg0->unk118 == NULL) {
        arg0->unk118 = malloc(0x14);
        var_s0 = arg0->unk118;
        if ((arg0->unkB0 != -1) && (func_global_asm_80722FEC(arg0->unkB0))) {
            var_s0->unk12 = arg0->unkB0;
        } else {
            var_s0->unk12 = -1;
        }
        var_s0->unkC = 0;
        var_v1 = TRUE;
    } else {
        var_s0 = arg0->unk118;
        var_v1 = FALSE;
    }
    if ((arg1 != 0) || (var_s0->unkC == 0)) {
        if (var_s0->unk12 == -1) {
            var_s0->unkC = 1U;
            var_s0->unk10 = 0;
            var_s0->unkE = 0;
            return;
        }
        if (var_v1) {
            func_global_asm_80723F88(var_s0->unk12, arg0->x_position, arg0->y_position, arg0->z_position, &var_s0->unk4, &var_s0->unk8);
        } else {
            func_global_asm_80724154(var_s0->unk12, arg0->x_position, arg0->y_position, arg0->z_position, &var_s0->unk4, &var_s0->unk8);
        }
        temp_f0 = var_s0->unk8;
        temp_a1 = var_s0->unk4;
        func_global_asm_80723CCC(var_s0->unk12, temp_a1, temp_f0, &sp64, &sp60, &sp5C);
        temp_f0 += 0.4;
        if (temp_f0 >= 1.0) {
            temp_a1++;
            temp_f0 -= 1.0;
        }
        func_global_asm_80723CCC(var_s0->unk12, temp_a1, temp_f0, &sp58, &sp54, &sp50);
        temp1 = (func_global_asm_80665AE4(sp64, sp5C, sp58, sp50) * 2048.0) / 3.1415927410125732;
        temp1 = (0x1000 - temp1);
        temp1 += 0x800;
        var_s0->unkE = temp1 & 0xFFF;
        var_s0->unk10 = 0x23;
        temp_a0 = func_global_asm_807245D8(var_s0->unk12) - 1;
        if (var_s0->unk4 >= temp_a0) {
            if (temp_a0 == var_s0->unk4) {
                sp47 = TRUE;
                var_s0->unk10 = 0;
            } else {
                sp47 = TRUE;
                var_s0->unk10 = 0;
            }
        }
        if ((sp47 != 0) && (arg1 == 0)) {
            var_s0->unkC = 1;
        }
    }
}

void func_global_asm_80724874(Actor *arg0) {
    if (arg0->unk118 != NULL) {
        free(arg0->unk118);
        arg0->unk118 = NULL;
    }
}
