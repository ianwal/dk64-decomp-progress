#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_807F93C4;
extern f32 D_global_asm_807F93C8[2]; // x, y (TODO: probably z too)
extern f32 D_global_asm_807F93D0; // z
extern f32 D_global_asm_807F93D4;
extern f32 D_global_asm_807F93D8;
extern f32 D_global_asm_807F93DC;
extern f32 D_global_asm_807F93E0;
extern f32 D_global_asm_807F93E4;
extern f32 D_global_asm_807F93E8;

typedef struct global_asm_struct_18 {
    void* unk0; // Texture pointer usually
    void* unk4;
    void* unk8;
    void* unkC; // Texture pointer usually
    void* unk10; // Texture pointer usually
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
} GlobalASMStruct18;

// TODO: Could this just be an array of void*?
// The offsets overlap in weird ways
extern GlobalASMStruct18 D_global_asm_80748A9C[];
extern GlobalASMStruct18 D_global_asm_80748A90[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_8065F1C0.s")

void func_global_asm_8065F49C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

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

void func_global_asm_8065F4F4(GlobalASMStruct58 *arg0) {
    if (arg0->unk0->unkC < arg0->unk10) {
        arg0->unk0->unkC += arg0->unk18;
        if (arg0->unk10 < arg0->unk0->unkC) {
            arg0->unk0->unkC = arg0->unk10;
        }
    } else {
        arg0->unk0->unkC -= arg0->unk18;
        if (arg0->unk0->unkC < arg0->unk10) {
            arg0->unk0->unkC = arg0->unk10;
        }
    }
    if (arg0->unk0->unk10 < arg0->unk14) {
        arg0->unk0->unk10 += arg0->unk18;
        if (arg0->unk14 < arg0->unk0->unk10) {
            arg0->unk0->unk10 = arg0->unk14;
        }
    } else {
        arg0->unk0->unk10 -= arg0->unk18;
        if (arg0->unk0->unk10 < arg0->unk14) {
            arg0->unk0->unk10 = arg0->unk14;
        }
    }
}

u8 func_global_asm_8065F5F0(GlobalASMStruct58 *arg0) {
    return D_global_asm_80748A90[arg0->unk0->unk66].unk15;
}

void func_global_asm_8065F614(void) {
    GlobalASMStruct58 *phi_s0 = D_global_asm_807F93C0;

    while (phi_s0) {
        phi_s0->unk4C = 0;
        func_global_asm_8065F4F4(phi_s0);
        phi_s0 = phi_s0->next;
    }
    if (!(global_properties_bitfield & 2)) {
        func_global_asm_806615BC();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_8065F678.s")

// close, stack, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_8065F964.s")

void func_global_asm_806545D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7, f32 (*arg8)[4], s32 arg9, f32 *argA);

/*
void func_global_asm_8065F964(GlobalASMStruct58 *arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, f32 arg5[4][4], s32 arg6) {
    Chunk *chunk;
    s32 i;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 spA8[4];
    f32 sp70[4][4];
    GlobalASMStruct58_unk0 *temp = arg0->unk0;

    var_s2 = 0;
    var_s3 = 0;
    var_s4 = 0;
    var_s5 = 0;
    for (i = 0; i < temp->unk67; i++) {
        chunk = &chunk_array_pointer[temp->unk50[i]];
        if (chunk->loaded == TRUE) {
            func_global_asm_80657E24(
                var_s2, var_s3, var_s4, var_s5,
                chunk->deload1, chunk->deload2, chunk->deload3, chunk->deload4,
                &spA8[3], &spA8[2], &spA8[1], &spA8[0]
            );
            var_s2 = spA8[3];
            var_s3 = spA8[2];
            var_s4 = spA8[1];
            var_s5 = spA8[0];
        }
    }
    func_global_asm_806545D4(var_s2, var_s3, var_s4, var_s5, arg1, arg2, arg3, arg4, arg5, arg6, &sp70);
    arg0->unk40 = var_s2;
    arg0->unk42 = var_s3;
    arg0->unk44 = var_s4;
    arg0->unk46 = var_s5;
}
*/

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

s32 func_global_asm_8065FB04(GlobalASMStruct81 *arg0) {
    s32 i;

    for (i = 0; i < arg0->unk67; i++) {
        if (chunk_array_pointer[arg0->unk50[i]].loaded == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_8065FB64.s")

void func_global_asm_8065C990(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg26, s32 arg27);
extern f32 D_global_asm_8076A0B4[];
extern s32 D_807F78C0;
extern f32 D_807F7EEC[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Struct8065FB64;

/*
void func_global_asm_8065FB64(f32 arg0, f32 arg1, s32 arg2) {
    u8 sp8F;
    GlobalASMStruct58 *current;
    GlobalASMStruct58_unk0 *temp_v0_2;
    f32 temp_f0;
    f32 temp_f2;
    s16 temp_s1;
    Struct8065FB64 *temp_a0;
    s32 temp_v0_3;
    u8 temp_v0;

    current = D_global_asm_807F93C0;
    while (current != NULL) {
        if (current->unk4C & 1 && !(current->unk4C & 2)) {
            temp_v0_2 = current->unk0;
            temp_s1 = temp_v0_2->unk50[0];
            if (temp_v0_2->unk68 != 0) {
                temp_f2 = temp_v0_2->unk10 + temp_v0_2->unkC;
                temp_f0 = temp_v0_2->unk4E + current->unk4;
                temp_v0_3 = func_global_asm_8065BAA0(arg0, arg1, arg2, temp_v0_2->unk46, temp_f0 - temp_f2, temp_v0_2->unk48, temp_v0_2->unk4A, temp_f0 + temp_f2, temp_v0_2->unk4C, temp_s1, &sp8F);
                // TODO: For loop?
                D_807F7EEC[0] = D_global_asm_8076A0B4[temp_s1];
                D_807F7EEC[1] = D_global_asm_8076A0B4[temp_s1 + 1];
                D_807F7EEC[2] = D_global_asm_8076A0B4[temp_s1 + 2];
                if (global_properties_bitfield & 0x10) {
                    temp_a0 = current->unk1C[D_global_asm_807444FC];
                    func_global_asm_8065C990(temp_a0, &temp_a0[current->unk48], 1, &D_807F78C0, temp_v0_3, chunk_array_pointer[temp_s1].unk3 == 1);
                }
                current->unk4C |= 2;
            }
        }
        current = current->next;
    }
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_8065FD88.s")

typedef struct {
    u8 unk0[0x50 - 0x0];
    s16 unk50; // Used
    s16 unk52;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67; // Used
} Struct8065FEB8_arg1_unk0;

typedef struct {
    Struct8065FEB8_arg1_unk0 *unk0; // Used
    u8 unk4[0x40 - 0x4];
    s16 unk40; // Used
    s16 unk42; // Used
    s16 unk44; // Used
    s16 unk46; // Used
} Struct8065FEB8_arg1;

Gfx *func_global_asm_8065FEB8(Gfx *dl, Struct8065FEB8_arg1 *arg1) {
    s16 chunkIndex;
    Struct8065FEB8_arg1_unk0 *temp_v1;

    gDPPipeSync(dl++);
    temp_v1 = arg1->unk0;
    if (temp_v1->unk67 == 1) {
        chunkIndex = temp_v1->unk50;
        gDPSetScissor(
            dl++,
            G_SC_NON_INTERLACE,
            chunk_array_pointer[chunkIndex].deload1,
            chunk_array_pointer[chunkIndex].deload2,
            chunk_array_pointer[chunkIndex].deload3,
            chunk_array_pointer[chunkIndex].deload4
        );
    } else {
        gDPSetScissor(
            dl++,
            G_SC_NON_INTERLACE,
            arg1->unk40,
            arg1->unk42,
            arg1->unk44,
            arg1->unk46
        );
    }
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_80660070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_80660520.s")

// doable, Related to GlobalASMStruct58
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_80660830.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s8 unkC; // Used
    s8 unkD; // Used
    s8 unkE; // Used
    s8 unkF;
} Struct80660830_arg0;

/*
void func_global_asm_80660830(Struct80660830_arg0 *arg0, GlobalASMStruct58 *arg1) {
    u32 count;
    u32 i;
    s32 temp61;
    s32 temp62;
    s32 temp63;
    s32 temp1;
    s32 temp2;

    temp61 = arg1->unk0->unk61;
    temp62 = arg1->unk0->unk62;
    temp63 = arg1->unk0->unk63;
    temp1 = (((arg1->unk0->unk4A - arg1->unk0->unk46) / arg1->unk2C) + 2);
    temp2 = (((arg1->unk0->unk4C - arg1->unk0->unk48) / arg1->unk2C) + 2);
    count = temp1 * temp2;
    for (i = count - 1; i > 0;) {
        arg0->unkC = temp61;
        arg0->unkD = temp62;
        arg0->unkE = temp63;
        arg0++;
        i--;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_806608FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_80660D38.s")

s32 func_global_asm_8066104C(s32 arg0) {
    return ~arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_80661054.s")

void func_global_asm_80661264(s32 arg0, u8 arg1) {
    GlobalASMStruct58 *current;
    current = D_global_asm_807F93C0;
    while (current != NULL && arg0 != 0) {
        current = current->next;
        arg0 -= 1;
    }
    if (current != NULL) {
        current->unk0->unk64 = arg1;
    }
}

void func_global_asm_806612B4(s32 arg0, u8 arg1) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk4A = arg1;
    }
}

u8 func_global_asm_80661300(s32 arg0) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        return phi_v0->unk4B;
    }
    return 0;
}

void func_global_asm_8066134C(s32 arg0, u8 arg1) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk4B = arg1;
    }
}

void func_global_asm_80661398(s32 arg0, f32 arg1, f32 arg2) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk8 = arg1;
        phi_v0->unkC = arg2;
    }
}

void func_global_asm_806613E8(s32 arg0, f32 arg1, f32 arg2) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        phi_v0->unk8 += arg1;
        phi_v0->unkC = arg2;
    }
}

void func_global_asm_80661440(f32 *arg0) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;
    s32 phi_a1 = 0;

    while (phi_v0 && phi_a1 < 32) {
        arg0[phi_a1++] = phi_v0->unk8;
        phi_v0 = phi_v0->next;
    }
}

void func_global_asm_80661484(f32 *arg0) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;
    s32 phi_a1 = 0;

    while (phi_v0 && phi_a1 < 32) {
        phi_v0->unk8 = arg0[phi_a1++];
        phi_v0->unk4 = phi_v0->unk8;
        phi_v0 = phi_v0->next;
    }
}

f32 func_global_asm_806614D0(s32 arg0) {
    GlobalASMStruct58 *phi_v0 = D_global_asm_807F93C0;

    while (phi_v0 && arg0) {
        phi_v0 = phi_v0->next;
        arg0--;
    }
    if (phi_v0) {
        return phi_v0->unk4;
    }
    return 0.0f;
}

void func_global_asm_80661520(f32 x, f32 y, f32 z, f32 arg3, f32 arg4, f32 arg5) {
    if (D_global_asm_807F93C4 == 0) {
        D_global_asm_807F93C8[0] = x;
        D_global_asm_807F93C8[1] = y;
        D_global_asm_807F93D4 = 0.0f;
        D_global_asm_807F93D0 = z;
        D_global_asm_807F93D8 = arg3;
        D_global_asm_807F93DC = 0.0f;
        D_global_asm_807F93E0 = arg4;
        D_global_asm_807F93E4 = arg5;
        D_global_asm_807F93E8 = (arg5 * 2) / 3.0f;
        D_global_asm_807F93C4 = 1;
    }
}

void func_global_asm_806615BC(void) {
    if (D_global_asm_807F93C4 != 0) {
        D_global_asm_807F93D4 += D_global_asm_807F93D8;
        if (D_global_asm_807F93D0 < D_global_asm_807F93D4) {
            D_global_asm_807F93D4 = D_global_asm_807F93D0;
        }
        D_global_asm_807F93DC += D_global_asm_807F93E0;
        if (D_global_asm_807F93E4 < D_global_asm_807F93DC) {
            D_global_asm_807F93C4 = 0;
        }
    }
}

void func_global_asm_8066164C(void) {
    D_global_asm_807F93C4 = 0;
}

void func_global_asm_80661658(u8 arg0) {
    // Texture (Uncompressed)
    D_global_asm_80748A9C[arg0].unk0 = getPointerTableFile(7, 0x3C5, 1, 0);
}

// Displaylist stuff, similar to below
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_806616A0.s")

// Displaylist stuff, close
// https://decomp.me/scratch/BWl97
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_806618A0.s")

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
    u8 unk44[0x64 - 0x44];
    u8 unk64;
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

/*
Gfx *func_global_asm_806618A0(Gfx *dl, Struct80661AB4_1 *arg1, u8 arg2) {
    gDPPipeSync(dl++);
    gDPLoadTextureBlock(dl++, D_global_asm_80748A9C[arg2].unk0, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 14, 14);
    gDPSetCombineLERP(dl++, TEXEL1, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, PRIMITIVE, 0);
    gDPSetPrimColor(dl++, 0, 0, 0, 0, 0, arg1->unk0->unk64);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_TILE);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 1, 1, G_ON);
    gDPSetRenderMode(dl++, G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2);
    gDPSetTileSize(dl++, 1, 0, (s32)arg1->unk0->unk3C, 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 14, G_TX_NOMIRROR | G_TX_WRAP, 5, 14);
    gDPSetTileSize(dl++, 2, (s32)arg1->unk0->unk40, (s32)arg1->unk0->unk40, 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 13, G_TX_NOMIRROR | G_TX_WRAP, 5, 13);
    return dl;
}
*/

void func_global_asm_80661AB4(Struct80661AB4_1 *arg0) {
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

void func_global_asm_80661B84(u8 arg0) {
    // Textures
    D_global_asm_80748A90[arg0].unkC = getPointerTableFile(0x19, 0x2EE, 1, 0);
    D_global_asm_80748A90[arg0].unk10 = getPointerTableFile(0x19, 0x2EF, 1, 0);
}

Gfx *func_global_asm_80661BF0(Gfx *dl, Struct80661AB4_1 *arg1, u8 arg2) {
    GlobalASMStruct18 *temp_v0 = &D_global_asm_80748A90[arg2];

    gDPPipeSync(dl++);
    gDPLoadTextureBlock_4b(dl++, temp_v0->unkC, G_IM_FMT_CI, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, (s32)arg1->unk0->unk3C, 0x00FC, 0x00FC);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 14, G_TX_NOMIRROR | G_TX_WRAP, 5, 14);
    gDPLoadTLUT_pal16(dl++, 0, temp_v0->unk10);
    gDPSetTextureLUT(dl++, G_TT_RGBA16);
    return dl;
}

void func_global_asm_80661E34(Struct80661AB4_1 *arg0) {
    arg0->unk0->unk3C -= arg0->unk0->unk34;
    if (arg0->unk0->unk3C < 0.0) {
        arg0->unk0->unk3C = 255.0f;
    }
    arg0->unk30 += arg0->unk0->unk14;
    arg0->unk34 += arg0->unk0->unk18;
    arg0->unk38 += arg0->unk0->unk2C;
    arg0->unk3C += arg0->unk0->unk30;
}

void func_global_asm_80661EC4(u8 arg0) {
    // Texture
    D_global_asm_80748A9C[arg0].unk0 = getPointerTableFile(0x19, 0xF0, 1, 0);
}

Gfx *func_global_asm_80661F0C(Gfx *dl, s32 arg1, u8 arg2) {
    gDPPipeSync(dl++);
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_global_asm_80748A9C[arg2].unk0);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1359, 0);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0x0002, 0x0002, 0x007E, 0x007E);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
    gDPSetTileSize(dl++, 1, 0x0002, 0x0002, 0x003E, 0x003E);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
    gDPSetTileSize(dl++, 2, 0x0002, 0x0002, 0x001E, 0x001E);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
    gDPSetTileSize(dl++, 3, 0x0002, 0x0002, 0x000E, 0x000E);
    gDPSetCombineMode(dl++, G_CC_TRILERP, G_CC_MODULATEIA2);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 3, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_PASS, G_RM_ZB_OPA_SURF2);
    return dl;
}

void func_global_asm_80662108(s32 arg0) {

}

void func_global_asm_80662110(u8 arg0) {
    // Texture
    D_global_asm_80748A9C[arg0].unk0 = getPointerTableFile(0x19, 0xAF4, 1, 0);
}

void func_global_asm_80662158(Gfx *dl, s32 arg1, u8 arg2) {
    func_global_asm_80661F0C(dl, arg1, arg2);
}

void func_global_asm_80662180(s32 arg0) {

}

void func_global_asm_80662188(u8 arg0) {
    // Texture
    D_global_asm_80748A9C[arg0].unk0 = getPointerTableFile(0x19, 0x75C, 1, 0);
}

Gfx *func_global_asm_806621D0(Gfx *dl, s32 arg1, u8 arg2) {
    gDPPipeSync(dl++);
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_global_asm_80748A9C[arg2].unk0);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1359, 0);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0x0002, 0x0002, 0x007E, 0x007E);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
    gDPSetTileSize(dl++, 1, 0x0002, 0x0002, 0x003E, 0x003E);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
    gDPSetTileSize(dl++, 2, 0x0002, 0x0002, 0x001E, 0x001E);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
    gDPSetTileSize(dl++, 3, 0x0002, 0x0002, 0x000E, 0x000E);
    gDPSetCombineMode(dl++, G_CC_TRILERP, G_CC_MODULATEIA2);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 3, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_PASS, G_RM_ZB_OPA_SURF2);
    return dl;
}

void func_global_asm_806623CC(s32 arg0) {

}

void func_global_asm_806623D4(u8 arg0) {
    // Texture (Uncompressed)
    D_global_asm_80748A9C[arg0].unk0 = getPointerTableFile(7, 0x3B9, 1, 0);
}

typedef struct {
    u8 unk0[0x3C - 0];
    f32 unk3C;
} Struct8066241C_arg1_unk0;

typedef struct {
    Struct8066241C_arg1_unk0 *unk0;
} Struct8066241C_arg1;

Gfx *func_global_asm_8066241C(Gfx *dl, Struct8066241C_arg1 *arg1, u8 arg2) {
    gDPPipeSync(dl++);
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_global_asm_80748A9C[arg2].unk0);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(dl++);\
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 256);\
    gDPPipeSync(dl++);\
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);\
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, (s32)(arg1->unk0->unk3C), 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 14, G_TX_NOMIRROR | G_TX_WRAP, 5, 14);
    return dl;
}

void func_global_asm_806625D0(u8 arg0) {
    // Texture (Uncompressed)
    D_global_asm_80748A9C[arg0].unk0 = getPointerTableFile(7, 0x3D2, 1, 0);
}

Gfx *func_global_asm_80662618(Gfx *dl, Struct80661AB4_1 *arg1, u8 arg2) {
    gDPPipeSync(dl++);
    gDPLoadTextureBlock(dl++, D_global_asm_80748A9C[arg2].unk0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, (s32)arg1->unk0->unk3C, 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 14, G_TX_NOMIRROR | G_TX_WRAP, 5, 14);
    return dl;
}

void func_global_asm_806627CC(u8 arg0) {
    // Texture (Uncompressed)
    D_global_asm_80748A90[arg0].unkC = getPointerTableFile(7, 0x3BA, 1, 0);
    D_global_asm_80748A90[arg0].unk10 = getPointerTableFile(7, 0x3DB, 1, 0);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_63EC0/func_global_asm_80662838.s")

void func_global_asm_80662AB4(Struct80661AB4_1 *arg0) {
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
