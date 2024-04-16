#include <ultra64.h>
#include "functions.h"


const u8 D_global_asm_80757F70[] = {    
    0xFF,
    0xFF,
    0xFF,
    0xC8,
    0x00,
    0x32,
    0xDC,
    0xC8,
    0x00,
    0x32,
    0xC8,
    0x00,
    0xCA,
    0x5B,
    0xFF,
    0x00,
    0x96,
    0xFF,
    0x32,
    0x32,
    0xFA,
    0x00,
    0x00,
    0x00,
};

/*
const char D_global_asm_80757F88[] = ":";
const f64 D_global_asm_807580A8 = 0.01;
const f64 D_global_asm_807580B0 = 127.5;
const f64 D_global_asm_807580B8 = 255.0;
const f64 D_global_asm_807580C0 = 32767.0;
const f64 D_global_asm_807580C8 = 16383.5;
const f64 D_global_asm_807580D0 = 127.0;
const f64 D_global_asm_807580D8 = 255.0;
const f64 D_global_asm_807580E0 = 32767.0;
const f64 D_global_asm_807580E8 = 16383.5;
const f64 D_global_asm_807580F0 = 127.0;
const f64 D_global_asm_807580F8 = 255.0;
*/

void func_global_asm_80627C10(u8 arg0) {
    s32 index = arg0 * 3;
    last_spawned_actor->unk16A = D_global_asm_80757F70[index + 0];
    last_spawned_actor->unk16B = D_global_asm_80757F70[index + 1];
    last_spawned_actor->unk16C = D_global_asm_80757F70[index + 2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_global_asm_80627C5C.s")

/*
// Seems doable, struct on the stack?
void func_global_asm_80627C5C(s32 arg0, s16 arg1, u8 arg2) {
    ? sp98;
    ? sp58;
    ? sp44;
    s16 sp42;
    s32 sp38;
    void *sp34;
    ? *temp_v0;
    ? *var_s0;
    s16 temp_a3_2;
    s16 var_v1;
    s32 temp_a1;
    s32 temp_a3;

    temp_a3 = arg0 & 0xFF;
    temp_v0 = func_global_asm_8070E750(1, temp_a3, 1, temp_a3);
    var_s0 = temp_v0;
    if (strchr(temp_v0, ':') != 0) {
        temp_a3_2 = func_dk64_boot_80002C74(var_s0, ":") + 1;
        sp42 = temp_a3_2;
        func_dk64_boot_80002A64(&sp44, var_s0, temp_a3_2, temp_a3_2);
        *(&sp44 + sp42) = 0;
        func_global_asm_8069D2AC(0xA, 0x14, 0x18, &sp44, 0, arg1, 0x32, 0x32);
        func_global_asm_80627C10(arg2);
        var_s0 += strlen(&sp44);
    }
    sp38 = arg1;
    if (getCenterOfString(6, var_s0) >= 0x12D) {
        temp_a1 = strlen(var_s0) / 2;
        var_v1 = temp_a1;
        if (*(temp_a1 + var_s0) != 0x20) {
            do {
                var_v1 -= 1;
            } while (*(var_v1 + var_s0) != 0x20);
        }
        sp34 = var_v1 + var_s0;
        sp42 = var_v1;
        func_dk64_boot_80002A64(&sp98, var_s0, var_v1);
        (sp + sp42)->unk98 = 0;
        func_dk64_boot_80002A64(&sp58, sp34 + 1, 0xFF);
        func_global_asm_8069D2AC(0, 0, 0xCD, &sp98, 0, sp38, 0x32, 0x32);
        func_global_asm_80627C10(arg2);
        func_global_asm_8069D2AC(0, 0, 0xD7, &sp58, 0, sp38, 0x32, 0x32);
        func_global_asm_80627C10(arg2);
        return;
    }
    func_global_asm_8069D2AC(0, 0, 0xCD, var_s0, 0, sp38, 0x32, 0x32);
    func_global_asm_80627C10(arg2);
}
*/

Actor *func_global_asm_80627EA8(s16 arg0) {
    Actor *actor;

    if (arg0) {
        actor = func_global_asm_807270C0(arg0, 0); // getSpawnerTiedActor()
    }
    if (!arg0 || !actor) {
        actor = player_pointer;
    }
    return actor;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_2C910/func_global_asm_80627F04.s")

s32 func_global_asm_80629148(void) {
    s32 phi_v1 = FALSE;
    if (current_actor_pointer->unk6A & 0x100) {
        current_actor_pointer->unk6A &= ~0x100;
        phi_v1 = TRUE;
    }
    return phi_v1;
}

void func_global_asm_80629174(void) {
    current_actor_pointer->unk6A &= ~0x100;
}
