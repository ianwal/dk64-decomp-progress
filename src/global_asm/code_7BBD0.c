#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_global_asm_80676ED0.s")

extern s8 D_global_asm_807FB5FD;
extern u8 D_global_asm_807FB5FF;
extern s8 D_global_asm_807FB600;

/*
// TODO: Painfully close, only difference is it's using 0x50 on the stack instead of 0x54 for a variable
u8 func_global_asm_80676ED0(Actor *arg0, s16 *arg1, s16 *arg2) {
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
    D_global_asm_807FB600 = 0;
    i = 0;
    while (i < D_global_asm_807FBB34) {
        temp_s7 = D_global_asm_807FB930[i].unk0;
        temp_s2 = temp_s7->ledge_info_pointer;
        if (!(temp_s7->object_properties_bitfield & 0x2000) && (sp7C != temp_s2) && (temp_s7->noclip_byte != 1) && (temp_s7->object_properties_bitfield & 0x10) && (func_global_asm_80674ADC(sp74, sp70, sp6C, sp68, temp_s2->unk0, temp_s2->unk4, temp_s2->unk8, temp_s2->unkC) != 0)) {
            var_s0 = sp7C->unk8C;
            D_global_asm_807FB5FF = 0;
            if (temp_s7->unk64 & 0x20) {
                D_global_asm_807FB5FD = 0;
            } else {
                D_global_asm_807FB5FD = 1;
            }
            while ((var_s0 != NULL) && (D_global_asm_807FB5FF == 0)) {
                if ((var_s0->unk26 != 0) && !(var_s0->unk27 & 2)) {
                    var_s3 |= func_global_asm_80673708(var_s0->unk10, var_s0->unk14, var_s0->unk18, var_s0->unk1C, temp_s2->unkA4, temp_s2->unkA8, arg1, arg2);
                }
                var_s0 = var_s0->next;
            }
            if (temp_s7->unk64 & 0x20) {
                arg0->unkFC |= var_s3;
            }
            if (D_global_asm_807FB5FF != 0) {
                sp5A |= func_global_asm_80677148(arg0, temp_s7);
            }
        }
        i++;
    }
    return sp5A;
}
*/

// Actor* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_global_asm_80677148.s")

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
    u8 unk4D;
    u8 unk4E; // Used, not sure on datatype yet though
} Struct807FB5D8;

extern Struct807FB5D8 *D_global_asm_807FB5D8;

extern f32 D_global_asm_807FB5C4;
extern f32 D_global_asm_807FB5C8;
extern f32 D_global_asm_807FB5CC;

extern s32 D_global_asm_807FB5D0; // TODO: Proper datatype

/*
s32 func_global_asm_80677148(Actor *arg0, Actor *arg1) {
    u8 sp15F;
    ? sp11C;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    LedgeInfo *temp_s6;
    f32 *var_s0;
    f32 *var_s1_2;
    f32 *var_s2;
    f32 *var_s3;
    f32 *var_s4;
    f32 *var_s5;
    f32 var_f12;
    f32 var_f14;
    f32 var_f2;
    s16 temp_v0_2;
    s32 var_s1;
    LedgeInfo *temp_s0;
    Struct807FB5D8 *temp_v0;

    sp15F = 0;
    temp_s6 = arg0->ledge_info_pointer;
    temp_s0 = arg1->ledge_info_pointer;
    if (func_global_asm_806744A8(D_global_asm_807FB5D8, temp_s6->unk0, temp_s6->unk4, temp_s6->unk8, temp_s6->unkC) == 0) {
        return 0;
    }
    if ((arg0->unk68 & 2) && (arg1->unk68 & 4)) {
        sp15F = 1;
    }
    if (func_global_asm_80677D58(arg0) == 0) {
        sp15F = 0;
    }
    if (arg1->unk68 & 8) {
        sp15F = 2;
    }
    temp_s6->unk58 = (D_global_asm_807FB5D8 - temp_s0->unkA4) / 88;
    func_global_asm_8067760C(temp_s0, &sp11C, D_global_asm_807FB5D8->unk4E);
    func_global_asm_8062FF10(&spDC[0], &sp11C);
    if (arg1->unk64 & 0x10) {
        var_f2 = arg0->x_position;
        var_f12 = arg0->y_position;
        var_f14 = arg0->z_position;
    } else {
        var_f2 = D_global_asm_807FB5C4 / 8.0f;
        var_f12 = D_global_asm_807FB5C8 / 8.0f;
        var_f14 = D_global_asm_807FB5CC / 8.0f;
    }
    if (!(arg0->object_properties_bitfield & 0x800)) {
        guMtxXFMF(&spDC[0], var_f2, var_f12, var_f14, &spC4, &spC8, &spCC);
    } else {
        spC4 = temp_s6->unkB8;
        spC8 = temp_s6->unkBC;
        spCC = temp_s6->unkC0;
    }
    var_s1_2 = &spB8;
    temp_s6->unkB8 = spC4;
    var_s2 = &spAC;
    var_s3 = &spA0;
    temp_s6->unkBC = spC8;
    var_s4 = &sp7C;
    var_s5 = &sp80;
    temp_s6->unkC0 = spCC;
    temp_v0 = D_global_asm_807FB5D8;
    var_s0 = &sp84;
    spB8 = temp_v0->unk24 / 8.0f;
    spAC = temp_v0->unk28 / 8.0f;
    spA0 = temp_v0->unk2C / 8.0f;
    spBC = temp_v0->unk30 / 8.0f;
    spB0 = temp_v0->unk34 / 8.0f;
    spA4 = temp_v0->unk38 / 8.0f;
    spC0 = temp_v0->unk3C / 8.0f;
    spB4 = temp_v0->unk40 / 8.0f;
    spA8 = temp_v0->unk44 / 8.0f;
    do {
        guMtxXFMF(&spDC[0], *var_s1_2, *var_s2, *var_s3, var_s4, var_s5, var_s0);
        var_s0 += 0xC;
        var_s1_2 += 4;
        var_s2 += 4;
        var_s3 += 4;
        var_s4 += 0xC;
        var_s5 += 0xC;
    } while (var_s0 != &spA8);
    temp_s6->unk66 = D_global_asm_807FB5D8->unk48;
    if (D_global_asm_807FB5D8->unk4C != 0) {
        temp_s6->unk66 = temp_s6->unk66 - 0x800;
    }
    temp_v0_2 = temp_s6->unk66;
    if (temp_v0_2 < 0) {
        temp_s6->unk66 = temp_v0_2 + 0x1000;
    }
    if (sp15F != 0) {
        var_s1 = sp15F == 1;
        if (var_s1 == 0) {
            if (sp15F == 2) {
                if (arg0->interactable & 1) {
                    func_global_asm_8066FC0C(arg0, D_global_asm_807FB5D8, temp_s6);
                }
                goto block_26;
            }
        } else {
            func_global_asm_8067A864(arg0, arg1, arg0->y_rotation, arg0->unkB8, &spC4, &sp7C, D_global_asm_807FB5D8->unk4E, D_global_asm_807FB5D0, func_global_asm_8066FD6C(arg0));
            if ((func_global_asm_80677CAC(D_global_asm_807FD610->unk28, 0x190) != 0) && (D_global_asm_807FD610->unk4 > 30.0)) {
                arg0->y_rotation = temp_s6->unk66;
            }
        }
    } else {
block_26:
        var_s1 = sp15F == 1;
        func_global_asm_8067A908(arg0, arg1, &spC4, &sp7C, D_global_asm_807FB5D8->unk4E, D_global_asm_807FB5D0, func_global_asm_8066FD6C(arg0));
    }
    return var_s1 & 0xFF;
}
*/

// guMtxL2F, memcpy, object_timer, struct->unk88
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_global_asm_8067760C.s")

/*
void func_global_asm_8067760C(LedgeInfo *arg0, f32 (*arg1)[4], s8 arg2) {
    u8 var_v0;
    LedgeInfo74 *temp;

    if (object_timer == arg0->unk88) {
        var_v0 = D_global_asm_807444FC;
    } else {
        var_v0 = (D_global_asm_807444FC ^ 1);
    }
    if (arg2 == -1) {
        memcpy(arg1, arg0->unk70, 0x40);
        return;
    }
    temp = &arg0->unk74[var_v0]->unk0;
    guMtxL2F(arg1, temp->unk0[arg2]);
}
*/

// Bleh matrix nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_global_asm_806776A0.s")

s32 func_global_asm_80677CAC(s16 arg0, s16 arg1) {
    s16 phi_v0;
    s16 phi_v1;

    phi_v0 = D_global_asm_807FB5D8->unk48;
    if (D_global_asm_807FB5D8->unk4C != 0) {
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

s32 func_global_asm_80677D58(Actor *arg0) {
    return func_global_asm_80677CAC(arg0->y_rotation, 0x190);
}
