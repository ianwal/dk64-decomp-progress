#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_80676ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_80677148.s")

// guMtxL2F, memcpy, object_timer, struct->unk88
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7BBD0/func_8067760C.s")

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
