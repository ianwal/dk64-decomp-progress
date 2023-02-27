#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_80676ED0.s")

extern s8 D_807FB5FD;
extern u8 D_807FB5FF;
extern s8 D_807FB600;
extern u16 D_807FBB34;

/*
// TODO: Painfully close, only difference is it's using 0x50 on the stack instead of 0x54 for a variable
u8 func_80676ED0(Actor *arg0, s16 *arg1, s16 *arg2) {
    LedgeInfo *sp7C;
    LedgeInfo *temp_s2;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 i;
    LedgeInfo8C *var_s0;
    Actor *temp_s7;
    u8 var_s3;
    u8 sp5A;

    sp5A = 0;
    var_s3 = 0;
    if (!(arg0->object_properties_bitfield & 0x10)) {
        return 0;
    }
    sp7C = arg0->ledge_info_pointer;
    sp74 = sp7C->unk0;
    sp70 = sp7C->unk4;
    sp6C = sp7C->unk8;
    sp68 = sp7C->unkC;
    D_807FB600 = 0;
    i = 0;
    while (i < D_807FBB34) {
        temp_s7 = D_807FB930[i].unk0;
        temp_s2 = temp_s7->ledge_info_pointer;
        if (!(temp_s7->object_properties_bitfield & 0x2000) && (sp7C != temp_s2) && (temp_s7->noclip_byte != 1) && (temp_s7->object_properties_bitfield & 0x10) && (func_80674ADC(sp74, sp70, sp6C, sp68, temp_s2->unk0, temp_s2->unk4, temp_s2->unk8, temp_s2->unkC) != 0)) {
            var_s0 = sp7C->unk8C;
            D_807FB5FF = 0;
            if (temp_s7->unk64 & 0x20) {
                D_807FB5FD = 0;
            } else {
                D_807FB5FD = 1;
            }
            while ((var_s0 != NULL) && (D_807FB5FF == 0)) {
                if ((var_s0->unk26 != 0) && !(var_s0->unk27 & 2)) {
                    var_s3 |= func_80673708(var_s0->unk10, var_s0->unk14, var_s0->unk18, var_s0->unk1C, temp_s2->unkA4, temp_s2->unkA8, arg1, arg2);
                }
                var_s0 = var_s0->next;
            }
            if (temp_s7->unk64 & 0x20) {
                arg0->unkFC |= var_s3;
            }
            if (D_807FB5FF != 0) {
                sp5A |= func_80677148(arg0, temp_s7);
            }
        }
        i++;
    }
    return sp5A;
}
*/

// Actor* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_80677148.s")

// guMtxL2F, memcpy, object_timer, struct->unk88
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_8067760C.s")

// Bleh matrix nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_806776A0.s")

typedef struct  {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s16 unk48; // Used
    s16 unk4A;
    u8 unk4C; // Used
} Struct807FB5D8;

extern Struct807FB5D8 *D_807FB5D8;

s32 func_80677CAC(s16 arg0, s16 arg1) {
    s16 phi_v0;
    s16 phi_v1;

    phi_v0 = D_807FB5D8->unk48;
    if (D_807FB5D8->unk4C != 0) {
        phi_v0 -= 0x800;
    }
    if (phi_v0 < 0) {
        phi_v0 += 0x1000;
    }
    phi_v1 = phi_v0 - arg0;
    if (phi_v1 < 0) {
        phi_v1 = -phi_v1;
    }
    if (phi_v1 >= 0x801) {
        phi_v1 = 0xFFF - phi_v1;
    }
    if (phi_v1 < arg1) {
        return TRUE;
    }
    return FALSE;
}

void func_80677D58(Actor *arg0) {
    func_80677CAC(arg0->y_rotation, 0x190);
}
