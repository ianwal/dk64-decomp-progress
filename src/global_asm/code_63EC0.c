#include <ultra64.h>
#include "functions.h"

typedef struct global_asm_struct_18 {
    void* unk0; // Texture pointer usually
    void* unk4;
    void* unk8;
    void* unkC; // Texture pointer usually
    void* unk10; // Texture pointer usually
    u8 pad8[0x18 - 0x14];
} GlobalASMStruct18;

// TODO: Could this just be an array of void*?
// The offsets overlap in weird ways
extern GlobalASMStruct18 D_80748A9C[];
extern GlobalASMStruct18 D_80748A90[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065F1C0.s")

void func_8065F49C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk10 = arg1;
        phi_v0->unk14 = arg2;
        phi_v0->unk18 = arg3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065F4F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065F5F0.s")

s32 func_8065F5F0(GlobalASMStruct58 *); 
void func_806615BC(void);

void func_8065F614(void) {
    GlobalASMStruct58 *phi_s0 = D_807F93C0;

    while (phi_s0) {
        phi_s0->unk4C = 0;
        func_8065F4F4(phi_s0);
        phi_s0 = phi_s0->next;
    }
    if (!(global_properties_bitfield & 2)) {
        func_806615BC();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065F678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065F964.s")

typedef struct {
    s32 unk0[4];
    s32 unk10[4];
    s32 unk20[4];
    s32 unk30[4];
    s32 unk40[4];
    s16 unk50[8]; // Used, not sure if count is correct
    s32 unk60;
    s16 unk64;
    s8 unk66;
    u8 unk67; // Used
} GlobalASMStruct81;

s32 func_8065FB04(GlobalASMStruct81 *arg0) {
    s32 i;

    for (i = 0; i < arg0->unk67; i++) {
        if (chunk_array_pointer[arg0->unk50[i]].loaded == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065FB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065FD88.s")

// Displaylist stuff (chunk)
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8065FEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80660070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80660520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80660830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_806608FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80660D38.s")

s32 func_8066104C(s32 arg0) {
    return ~arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80661054.s")

void func_80661264(s32 arg0, u8 arg1) {
    GlobalASMStruct58 *current;
    current = D_807F93C0;
    while (current != NULL && arg0 != 0) {
        current = current->next;
        arg0 -= 1;
    }
    if (current != NULL) {
        current->unk0->unk64 = arg1;
    }
}

void func_806612B4(s32 arg0, u8 arg1) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk4A = arg1;
    }
}

u8 func_80661300(s32 arg0) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        return phi_v0->unk4B;
    }
    return 0;
}

void func_8066134C(s32 arg0, u8 arg1) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk4B = arg1;
    }
}

void func_80661398(s32 arg0, f32 arg1, f32 arg2) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk8 = arg1;
        phi_v0->unkC = arg2;
    }
}

void func_806613E8(s32 arg0, f32 arg1, f32 arg2) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk8 += arg1;
        phi_v0->unkC = arg2;
    }
}

void func_80661440(f32 *arg0) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;
    s32 phi_a1 = 0;

    while (phi_v0 && phi_a1 < 32) {
        arg0[phi_a1++] = phi_v0->unk8;
        phi_v0 = phi_v0->next;
    }
}

void func_80661484(f32 *arg0) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;
    s32 phi_a1 = 0;

    while (phi_v0 && phi_a1 < 32) {
        phi_v0->unk8 = arg0[phi_a1++];
        phi_v0->unk4 = phi_v0->unk8;
        phi_v0 = phi_v0->next;
    }
}

f32 func_806614D0(s32 arg0) {
    GlobalASMStruct58 *phi_v0 = D_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        return phi_v0->unk4;
    }
    return 0.0f;
}

extern u8 D_807F93C4;
extern f32 D_807F93C8[2];
extern f32 D_807F93D0;
extern f32 D_807F93D4;
extern f32 D_807F93D8;
extern f32 D_807F93DC;
extern f32 D_807F93E0;
extern f32 D_807F93E4;
extern f32 D_807F93E8;

void func_80661520(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if (D_807F93C4 == 0) {
        D_807F93C8[0] = arg0;
        D_807F93C8[1] = arg1;
        D_807F93D4 = 0.0f;
        D_807F93D0 = arg2;
        D_807F93D8 = arg3;
        D_807F93DC = 0.0f;
        D_807F93E0 = arg4;
        D_807F93E4 = arg5;
        D_807F93E8 = (arg5 * 2) / 3.0f;
        D_807F93C4 = 1;
    }
}

void func_806615BC(void) {
    if (D_807F93C4 != 0) {
        D_807F93D4 += D_807F93D8;
        if (D_807F93D0 < D_807F93D4) {
            D_807F93D4 = D_807F93D0;
        }
        D_807F93DC += D_807F93E0;
        if (D_807F93E4 < D_807F93DC) {
            D_807F93C4 = 0;
        }
    }
}

void func_8066164C(void) {
    D_807F93C4 = 0;
}

void func_80661658(u8 arg0) {
    // Texture (Uncompressed)
    D_80748A9C[arg0].unk0 = getPointerTableFile(7, 0x3C5, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_806616A0.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_806618A0.s")

typedef struct {
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
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
} Struct80661AB4_2;

typedef struct {
    Struct80661AB4_2 *unk0;
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
} Struct80661AB4_1;

void func_80661AB4(Struct80661AB4_1 *arg0) {
    arg0->unk0->unk3C -= arg0->unk0->unk34;
    if (arg0->unk0->unk3C < 0.0) {
        arg0->unk0->unk3C = 255.0f;
    }
    arg0->unk0->unk40 -= arg0->unk0->unk38;
    if (arg0->unk0->unk40 < 0.0) {
        arg0->unk0->unk40 = 255.0f;
    }
    arg0->unk30 += arg0->unk0->unk14;
    arg0->unk34 += arg0->unk0->unk18;
    arg0->unk38 += arg0->unk0->unk2C;
    arg0->unk3C += arg0->unk0->unk30;
}

void func_80661B84(u8 arg0) {
    // Textures
    D_80748A90[arg0].unkC = getPointerTableFile(0x19, 0x2EE, 1, 0);
    D_80748A90[arg0].unk10 = getPointerTableFile(0x19, 0x2EF, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80661BF0.s")

void func_80661E34(Struct80661AB4_1 *arg0) {
    arg0->unk0->unk3C -= arg0->unk0->unk34;
    if (arg0->unk0->unk3C < 0.0) {
        arg0->unk0->unk3C = 255.0f;
    }
    arg0->unk30 += arg0->unk0->unk14;
    arg0->unk34 += arg0->unk0->unk18;
    arg0->unk38 += arg0->unk0->unk2C;
    arg0->unk3C += arg0->unk0->unk30;
}

void func_80661EC4(u8 arg0) {
    // Texture
    D_80748A9C[arg0].unk0 = getPointerTableFile(0x19, 0xF0, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80661F0C.s")

void func_80662108(s32 arg0) {

}

void func_80662110(u8 arg0) {
    // Texture
    D_80748A9C[arg0].unk0 = getPointerTableFile(0x19, 0xAF4, 1, 0);
}

void func_80661F0C(s32, s32, u8);

void func_80662158(s32 arg0, s32 arg1, u8 arg2) {
    func_80661F0C(arg0, arg1, arg2);
}

void func_80662180(s32 arg0) {

}

void func_80662188(u8 arg0) {
    // Texture
    D_80748A9C[arg0].unk0 = getPointerTableFile(0x19, 0x75C, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_806621D0.s")

void func_806623CC(s32 arg0) {

}

void func_806623D4(u8 arg0) {
    // Texture (Uncompressed)
    D_80748A9C[arg0].unk0 = getPointerTableFile(7, 0x3B9, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_8066241C.s")

void func_806625D0(u8 arg0) {
    // Texture (Uncompressed)
    D_80748A9C[arg0].unk0 = getPointerTableFile(7, 0x3D2, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80662618.s")

void func_806627CC(u8 arg0) {
    // Texture (Uncompressed)
    D_80748A90[arg0].unkC = getPointerTableFile(7, 0x3BA, 1, 0);
    D_80748A90[arg0].unk10 = getPointerTableFile(7, 0x3DB, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_80662838.s")

void func_80662AB4(Struct80661AB4_1 *arg0) {
    Struct80661AB4_2 *temp_v0;
    Struct80661AB4_2 *temp_v0_2;
    Struct80661AB4_2 *temp_v0_3;

    arg0->unk0->unk3C -= arg0->unk0->unk34;
    if (arg0->unk0->unk3C < 0.0) {
        arg0->unk0->unk3C = 255.0f;
    }
    arg0->unk0->unk40 -= arg0->unk0->unk38;
    if (arg0->unk0->unk40 < 0.0) {
        arg0->unk0->unk40 = 255.0f;
    }
    arg0->unk30 += arg0->unk0->unk14;
    arg0->unk34 += arg0->unk0->unk18;
    arg0->unk38 += arg0->unk0->unk2C;
    arg0->unk3C += arg0->unk0->unk30;
}
