#include <ultra64.h>
#include "functions.h"


extern s16 D_global_asm_807F6BF0[];
extern u8 D_global_asm_807F6C08;
extern s32 D_global_asm_807F6C28; // Number of chunks?
extern s16 D_global_asm_807F6C58[];
extern s32 D_global_asm_807F6C80;

extern u8 D_global_asm_807F7078[];
extern u8 D_global_asm_807F70AA;
extern u8 D_global_asm_807F70AB;
extern u8 D_global_asm_807F7140;

extern u16 D_global_asm_807F7358;
extern u16 D_global_asm_807F735A;
extern u16 D_global_asm_807F735C;
extern u16 D_global_asm_807F735E;

void func_global_asm_8063B4C0(Chunk14*, u8);
s32 func_global_asm_8063A38C(Chunk14*, Chunk14*, f32, f32, f32);

void func_global_asm_80652FDC(f32, f32, f32, s16, s16, s16*);
Chunk14* func_global_asm_80630890(Chunk14*, f32, f32, f32, void*);
u8 func_global_asm_80668E9C(s32, s16, f32, f32, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80650E20.s")

extern s32 D_global_asm_8076A0B4;
extern s32 D_global_asm_8076A0B8;
extern s32 D_global_asm_8076A0BC;
extern s32 D_global_asm_8076A0C0;
extern s32 D_global_asm_8076A0C4;
extern s32 D_global_asm_8076A0C8;

typedef struct global_asm_struct_18 {
    s32 unk0;
    u8 pad4[0x64 - 0x4];
    s32 *unk64;
} GlobalASMStruct18;

typedef struct {
    s8 unk0[1]; // TODO: How many elements?
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
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
} Struct80650E20_arg0;

/*
// TODO: Unaligned s32 read?
void func_global_asm_80650E20(Struct80650E20_arg0 *arg0) {
    s32 size;
    u8 phi_v1;
    s32 temp;

    temp = arg0->unk0[arg0->unk64];
    D_global_asm_807F6C28 = temp;
    if (D_global_asm_807F6C28 >= 2) {
        phi_v1 = D_global_asm_807F6C28;
    } else {
        phi_v1 = 1;
    }
    size = phi_v1 * 4;
    D_global_asm_8076A0B4 = malloc(size);
    D_global_asm_8076A0B8 = malloc(size);
    D_global_asm_8076A0BC = malloc(size);
    D_global_asm_8076A0C0 = malloc(size);
    D_global_asm_8076A0C4 = malloc(size);
    D_global_asm_8076A0C8 = malloc(size);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80650ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80651708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80651904.s")

// TODO: Any more cleanup possible?
u8 func_global_asm_80651B64(s16 arg0) {
    s32 phi_v1;
    s32 phi_v0;

    phi_v1 = (arg0 + 1) != 0;
    if (phi_v1) {
        phi_v0 = chunk_array_pointer[arg0].unk3 ? TRUE : FALSE;
        phi_v1 = phi_v0 != 0;
    }
    return phi_v1;
}

void func_global_asm_80651BC0(s16 arg0, u8 arg1) {
    D_global_asm_807F7078[arg0] = arg1;
}

// Note: Needs to be aligned in memory by maximum 0x2: {s32 unk0; s32 unk4; u8 unk8; u8 unk9;} doesn't match
typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} Struct807F6C1C;

extern Struct807F6C1C *D_global_asm_807F6C1C;

void func_global_asm_80651BE0(s16 arg0, u8 arg1, u8 arg2) {
    D_global_asm_807F6C1C[arg0 * 2 + arg1].unk9 = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80651C2C.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 unk19; // Used
    u8 unk1A;
    u8 unk1C;
} Struct807F70B0;
extern Struct807F70B0 *D_global_asm_807F70B0;

extern s32 D_global_asm_807F6C20;
extern s32 D_global_asm_807F6C28;
extern u8 *D_global_asm_807F6C2C;

extern s32 D_global_asm_807F70AC;

void func_global_asm_8065214C(void) {
    s32 i;
    s32 j;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        chunk_array_pointer[i].unk1 = 0;
        chunk_array_pointer[i].unk2 = 1;
        chunk_array_pointer[i].unk4 = 0;
    }
    for (j = 0; j < D_global_asm_807F70AC; j++) {
        D_global_asm_807F70B0[j].unk19 = 0;
    }
}

void func_global_asm_806521F8(void) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        chunk_array_pointer[i].loaded = 0;
        chunk_array_pointer[i].deload1 = 0;
        chunk_array_pointer[i].deload2 = 0;
        chunk_array_pointer[i].deload3 = 0;
        chunk_array_pointer[i].deload4 = 0;
    }
    for (i = 0; i < D_global_asm_807F6C20; i++) {
        D_global_asm_807F6C1C[i].unk8 = 0;
        D_global_asm_807F6C2C[i] = 0;
    }
}

s32 func_global_asm_806522CC(s16 arg0, s16 arg1, s16 arg2) {
    if (chunk_array_pointer[arg2].unk1 == 0) {
        return FALSE;
    }
    if ((arg0 >= chunk_array_pointer[arg2].deload1)
        && (arg1 >= chunk_array_pointer[arg2].deload2)
        && (chunk_array_pointer[arg2].deload3 >= arg0)
        && (chunk_array_pointer[arg2].deload4 >= arg1)) {
        return TRUE;
    }
    return FALSE;
}

s32 func_global_asm_80630324(u8, void *);

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
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    s32 unk110;
    s32 unk114;
    s32 unk118;
    s32 unk11C;
    s32 unk120;
    s32 unk124;
    s32 unk128;
    s16 unk12C;
} Struct80652374_arg0_unk0;

typedef struct {
    Struct80652374_arg0_unk0 *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    u8 unk22;
    u8 unk23;
    u8 unk24;
} Struct80652374_arg0;

void func_global_asm_80652374(Struct80652374_arg0 *arg0) {
    u8 temp_v1;
    Chunk14 **sp40;

    arg0->unk20 = func_global_asm_806531B8(arg0->unk4, arg0->unk8, arg0->unkC, arg0->unk20);
    temp_v1 = func_global_asm_80630324(arg0->unk24, arg0->unk0);
    if (arg0->unk24 == 0) {
        arg0->unk0->unk12C = arg0->unk20;
    }
    switch (temp_v1) {
        case 0:
            sp40 = &chunk_array_pointer[arg0->unk20].unk14;
            break;
        case 1:
            sp40 = &chunk_array_pointer[arg0->unk20].unk1C;
            break;
    }
    *sp40 = func_global_asm_806303C4(*sp40, arg0->unk24, arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC, arg0->unk1C, arg0->unk1E, arg0->unk22, arg0->unk20, 0);
}

void func_global_asm_806524A0(s32 arg0, u8 arg1) {
    u8 sp4F;
    s32 i;

    sp4F = 0;
    // TODO: While loop better for this? Multi condition in for loop is odd
    for (i = 0; i < D_global_asm_807F6C28 && !sp4F; i++) {
        func_global_asm_806307CC(chunk_array_pointer[i].unk14, arg0, 0, arg1, &sp4F);
        if (sp4F == 0) {
            func_global_asm_806307CC(chunk_array_pointer[i].unk1C, arg0, 0, arg1, &sp4F);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80652594.s")

Chunk14 *func_global_asm_80630588(Chunk14*, s32, s32, u8*);

/*
// TODO: Quite close
// Something to do with arg2? Loop condition? Break?
u8 func_global_asm_80652594(Model2Model *arg0, s16 *arg1, u8 arg2) {
    u8 sp4F;
    s16 i;
    s32 pad;

    sp4F = 0;
    i = 0;
    while (i < D_global_asm_807F6C28 && !sp4F && arg2) {
        chunk_array_pointer[i].unk14 = func_global_asm_80630588(chunk_array_pointer[i].unk14, arg0, 0, &sp4F);
        if (sp4F) {
            *arg1 = i;
        }
        if (!sp4F || arg2) {
            chunk_array_pointer[i].unk1C = func_global_asm_80630588(chunk_array_pointer[i].unk1C, arg0, 0, &sp4F);
            if (sp4F) {
                *arg1 = i;
            }
        }
        i++;
    }
    return sp4F;
}
*/

void func_global_asm_806526E0(u8 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if ((chunk_array_pointer[i].loaded == 1) || (arg0 != 0)) {
            func_global_asm_806307AC(chunk_array_pointer[i].unk14);
            func_global_asm_806307AC(chunk_array_pointer[i].unk1C);
        }
    }
}

Chunk14 *func_global_asm_8063070C(Chunk14 *arg0);

void func_global_asm_80652790(u8 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1 || (arg0 != 0)) {
            chunk_array_pointer[i].unk14 = func_global_asm_8063070C(chunk_array_pointer[i].unk14);
            chunk_array_pointer[i].unk1C = func_global_asm_8063070C(chunk_array_pointer[i].unk1C);
        }
    }
}

void func_global_asm_80652858(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1 || (arg3 != 0)) {
            chunk_array_pointer[i].unk14 = func_global_asm_80630890(chunk_array_pointer[i].unk14, arg0, arg1, arg2, &chunk_array_pointer[i].unk18);
            chunk_array_pointer[i].unk1C = func_global_asm_80630890(chunk_array_pointer[i].unk1C, arg0, arg1, arg2, &chunk_array_pointer[i].unk20);
        }
    }
}

void func_global_asm_8065297C(void) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        func_global_asm_806323C0(chunk_array_pointer[i].unk14);
        func_global_asm_806323C0(chunk_array_pointer[i].unk1C);
    }
}

void func_global_asm_80652A08(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1 || (arg3 != 0)) {
            if (chunk_array_pointer[i].unk6 != 0) {
                chunk_array_pointer[i].unk24 = 0;
            } else {
                chunk_array_pointer[i].unk24 = func_global_asm_8063A38C(chunk_array_pointer[i].unk14, chunk_array_pointer[i].unk1C, arg0, arg1, arg2);
            }
        }
    }
}

void func_global_asm_80652B04(void) {
    s32 i;
    u8 phi_s2;
    Chunk14 *current;
    Chunk14 *next;

    D_global_asm_807F7140 = 0;
    for (i = 0; i < D_global_asm_807F6C28; i++) {
        phi_s2 = chunk_array_pointer[i].unk1 != 0 ? TRUE : FALSE;
        current = chunk_array_pointer[i].unk14;
        while (current) {
            next = current->next;
            func_global_asm_8063B4C0(current, phi_s2);
            current = next;
        }
    }
}

u8 func_global_asm_80652BC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    Chunk14 *phi_s0;
    s16 temp_f8;
    s16 temp_f16;
    u8 phi_s1;
    u8 sp6E;
    s32 i;

    phi_s1 = 0;
    sp6E = func_global_asm_80630324(1, 0);
    temp_f8 = arg1 * 6.0f;
    temp_f16 = arg2 * 6.0f;
    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (temp_f8 >= (chunk_array_pointer[i].unk80 - 50)) {
            if ((temp_f16 >= (chunk_array_pointer[i].unk82 - 50)) && ((chunk_array_pointer[i].unk84 + 50) >= temp_f8) && ((chunk_array_pointer[i].unk86 + 50) >= temp_f16)) {
                switch (sp6E) {
                    case 0:
                        phi_s0 = chunk_array_pointer[i].unk14;
                        break;
                    case 1:
                        phi_s0 = chunk_array_pointer[i].unk1C;
                        break;
                }
                while (phi_s0) {
                    if (phi_s0->unk24 == 1) {
                        phi_s1 |= func_global_asm_80668E9C(arg0, phi_s0->unk1E, arg1, arg2, arg3, arg4);
                    }
                    phi_s0 = phi_s0->next;
                }
            }
        }
    }
    return phi_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80652DB4.s")

/*
// TODO: Surprisingly fiddly
s32 func_global_asm_80652DB4(f32 arg0, f32 arg1, f32 arg2) {
    s16 temp_v0;
    s16 i;

    if (D_global_asm_807F6C28 == 0) {
        return 0xFF;
    }
    temp_v0 = func_global_asm_806531B8(arg0, arg1, arg2, 0);
    for (i = 0; i < D_global_asm_807F6C80; i++) {
        if (D_global_asm_807F6C58[i] == temp_v0) {
            return 1;
        }
    }
    return 0;
}
*/

u8 func_global_asm_80652E58(s16 arg0) {
    if (D_global_asm_807F6C28 == 0) {
        return 0xFF;
    }
    return chunk_array_pointer[arg0].unk1 ? TRUE : FALSE;
}

u8 func_global_asm_80652EBC(s16 arg0) {
    if (D_global_asm_807F6C28 == 0) {
        return 0xFF;
    }
    return chunk_array_pointer[arg0].loaded == 1 ? TRUE : FALSE;
}

u8 func_global_asm_80652F24(s16 arg0, s16 arg1) {
    if (D_global_asm_807F6C28 == 0) {
        return TRUE;
    }
    return (chunk_array_pointer[arg1].unk1 & (1 << arg0)) ? TRUE : FALSE;
}

s16 func_global_asm_80652F9C(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    s16 sp26;
    func_global_asm_80652FDC(arg0, arg1, arg2, arg3, -1, &sp26);
    return sp26;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80652FDC.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct807F70B4;

extern s32 D_global_asm_807F70AC;
extern Struct807F70B4 *D_global_asm_807F70B4;

/*
// TODO: Fiddly, progress made
void func_global_asm_80652FDC(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4, s16 *arg5) {
    s32 i;
    Struct807F70B4 *temp_v0_2;
    s16 temp_v1;

    for (i = 0; i < D_global_asm_807F70AC; i++) {
        if ((arg3 == D_global_asm_807F70B0[i].unk0) && (arg4 == D_global_asm_807F70B0[i].unk4)) {
            temp_v1 = D_global_asm_807F70B0[i].unk2;
            temp_v0_2 = &D_global_asm_807F70B4[temp_v1];
            if ((temp_v0_2->unk0 <= arg0) && (arg0 <= temp_v0_2->unk6) && (temp_v0_2->unk2 <= arg1) && (arg1 <= temp_v0_2->unk8) && (temp_v0_2->unk4 <= arg2) && (arg2 <= temp_v0_2->unkA)) {
                *arg5 = temp_v1;
                func_global_asm_80652FDC(arg0, arg1, arg2, arg3, temp_v1, arg5);
            }
        }
    }
}
*/

// TODO: Struct (or struct array?) on the stack?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_806531B8.s")

s32 func_global_asm_806533C4(f32 arg0, f32 arg1, f32 arg2) {
    s32 phi_v0;
    s32 phi_v1;
    f32 phi_f0;
    f32 phi_f2;

    if (arg0 <= arg2) {
        phi_v0 = TRUE;
    } else {
        phi_v0 = (arg0 - arg2) < 60.0f ? TRUE : FALSE;
    }
    if (arg1 <= arg2) {
        phi_v1 = TRUE;
    } else {
        phi_v1 = (arg1 - arg2) < 60.0f ? TRUE : FALSE;
    }
    if (!phi_v0 && !phi_v1) {
        return FALSE;
    }
    if (!phi_v1) {
        return FALSE;
    }
    if (!phi_v0) {
        return TRUE;
    }
    phi_f0 = (arg2 < arg0) ? arg0 - arg2 : arg2 - arg0;
    phi_f2 = (arg2 < arg1) ? arg1 - arg2 : arg2 - arg1;
    if (phi_f0 < phi_f2) {
        return FALSE;
    } else {
        return TRUE;
    }
}

s32 func_global_asm_80653684(Chunk78_7C*, f32, f32);
s32 func_global_asm_80653804(Chunk78_7C*, f32, f32);

s32 func_global_asm_806534E0(f32 arg0, f32 arg1, f32 arg2, s16 chunkIndex, s8 *arg4, f32 *arg5) {
    Chunk78_7C *phi_s0;
    Chunk78_7C *temp;

    if (arg0 < chunk_array_pointer[chunkIndex].unk80) {
        return FALSE;
    }
    if (arg2 < chunk_array_pointer[chunkIndex].unk82) {
        return FALSE;
    }
    if (chunk_array_pointer[chunkIndex].unk84 < arg0) {
        return FALSE;
    }
    if (chunk_array_pointer[chunkIndex].unk86 < arg2) {
        return FALSE;
    }
    phi_s0 = chunk_array_pointer[chunkIndex].unk78;
    temp = chunk_array_pointer[chunkIndex].unk7C;
    while (phi_s0 != temp) {
        if (func_global_asm_80653684(phi_s0, arg0, arg2) && func_global_asm_80653804(phi_s0, arg0, arg2)) {
            if (phi_s0->unk12 & 1) {
                *arg4 = 0;
            } else {
                *arg4 = 1;
                *arg5 = phi_s0->unk6;
            }
            return TRUE;
        }
        phi_s0++;
    }
    return FALSE;
}

// TODO: Can this be cleaned up any more?
s32 func_global_asm_80653684(Chunk78_7C *arg0, f32 arg1, f32 arg2) {
    f32 phi_f0;

    phi_f0 = MIN(arg0->unk0, arg0->unk2);
    if (!(phi_f0 < arg0->unk4)) {
        phi_f0 = arg0->unk4;
    }
    if (arg1 < phi_f0) {
        return FALSE;
    }
    phi_f0 = MIN(arg0->unkC, arg0->unkE);
    if (!(phi_f0 < arg0->unk10)) {
        phi_f0 = arg0->unk10;
    }
    if (arg2 < phi_f0) {
        return FALSE;
    }
    phi_f0 = MAX(arg0->unk0, arg0->unk2);
    if (!(arg0->unk4 < phi_f0)) {
        phi_f0 = arg0->unk4;
    }
    if (phi_f0 < arg1) {
        return FALSE;
    }
    phi_f0 = MAX(arg0->unkC, arg0->unkE);
    if (!(arg0->unk10 < phi_f0)) {
        phi_f0 = arg0->unk10;
    }
    if (phi_f0 < arg2) {
        return FALSE;
    }
    return TRUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80653804.s")

/*
// TODO: WIP, needs a lot of TLC
s32 func_global_asm_80653804(Chunk78_7C *arg0, f32 arg1, f32 arg2) {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 temp_f12;
    f64 temp_f14;
    f64 temp_f22;
    f64 temp_f24;
    s32 temp_t2;
    s32 phi_t2;
    f64 phi_f2;
    f64 phi_f0;
    f64 phi_f20;
    s32 phi_a0;
    s32 phi_t3;
    f64 phi_f18;
    f64 phi_f16;
    f64 phi_f14;
    f64 phi_f12;
    s32 phi_v1;

    temp_f22 = (arg0->unk0 + ((arg0->unk4 + arg0->unk2) * 0.5)) * 0.5;
    temp_f24 = (arg0->unkC + ((arg0->unk10 + arg0->unkE) * 0.5)) * 0.5;
    phi_t2 = 0;
    phi_v1 = 0;
    do {
        switch (phi_t2) {
            default:
                phi_f2 = (arg2 - phi_f18) * phi_f12;
                phi_f0 = (arg1 - phi_f16) * phi_f14;
                phi_f20 = ((temp_f22 - phi_f16) * phi_f14) - ((temp_f24 - phi_f18) * phi_f12);
                break;
            case 0:
                temp_f14 = arg0->unkE - arg0->unkC;
                temp_f12 = arg0->unk2 - arg0->unk0;
                phi_f2 = (arg2 - arg0->unkC) * temp_f12;
                phi_f0 = (arg1 - arg0->unk0) * temp_f14;
                phi_f20 = ((temp_f22 - arg0->unk0) * temp_f14) - ((temp_f24 - arg0->unkC) * temp_f12);
                phi_f18 = arg0->unkC;
                phi_f16 = arg0->unk0;
                phi_f14 = temp_f14;
                phi_f12 = temp_f12;
                break;
            case 1:
                temp_f14 = arg0->unk10 - arg0->unkC;
                temp_f12 = arg0->unk4 - arg0->unk0;
                phi_f2 = (arg2 - arg0->unkC) * temp_f12;
                phi_f0 = (arg1 - arg0->unk0) * temp_f14;
                phi_f20 = ((temp_f22 - arg0->unk0) * temp_f14) - ((temp_f24 - arg0->unkC) * temp_f12);
                phi_f18 = arg0->unkC;
                phi_f16 = arg0->unk0;
                phi_f14 = temp_f14;
                phi_f12 = temp_f12;
                break;
            case 2:
                temp_f12 = arg0->unk4 - arg0->unk2;
                temp_f14 = arg0->unk10 - arg0->unkE;
                phi_f2 = (arg2 - arg0->unkE) * temp_f12;
                phi_f0 = (arg1 - arg0->unk2) * temp_f14;
                phi_f20 = ((temp_f22 - arg0->unk2) * temp_f14) - ((temp_f24 - arg0->unkE) * temp_f12);
                phi_f18 = arg0->unkE;
                phi_f16 = arg0->unk2;
                phi_f14 = temp_f14;
                phi_f12 = temp_f12;
                break;
        }
        temp_t2 = phi_t2 + 1;
        phi_t2 = temp_t2;
        phi_t3 = -1;
        if (phi_f2 <= phi_f0) {
            phi_t3 = 1;
        }
        phi_a0 = -1;
        if (phi_f20 >= 0.0) {
            phi_a0 = 1;
        }
        if (phi_a0 != phi_t3) {
            phi_v1 = 1;
        }
    } while (temp_t2 != 3);
    return (phi_v1 == 0) & 0xFF;
}
*/

void func_global_asm_80653A70(s16 chunkIndex) {
    chunk_array_pointer[chunkIndex].loaded = 1;
    chunk_array_pointer[chunkIndex].unk1 |= 1 << cc_player_index;
    chunk_array_pointer[chunkIndex].deload1 = character_change_array[cc_player_index].unk270;
    chunk_array_pointer[chunkIndex].deload2 = character_change_array[cc_player_index].unk272;
    chunk_array_pointer[chunkIndex].deload3 = character_change_array[cc_player_index].unk274;
    chunk_array_pointer[chunkIndex].deload4 = character_change_array[cc_player_index].unk276;
}

void func_global_asm_80653B70(u8 arg0) {
    D_global_asm_807F70AB = arg0;
}

void func_global_asm_8062A944(f32, f32, f32);
void func_global_asm_8062AC68(void *);
void func_global_asm_8062AD28(f32, f32, f32, void *, void *);
void func_global_asm_806521F8();
void func_global_asm_80654380(f32, f32, f32);
void func_global_asm_806547A8(f32, f32, f32);
void func_global_asm_80655410(f32, f32, f32);
void func_global_asm_80656F14(s16, s32, s16, s16, s32, s32, f32, f32, f32);
void func_global_asm_8065F678(f32, f32, f32, u8);
void func_global_asm_8066308C(f32, f32, f32);
extern s32 D_global_asm_807F5E20; // TODO: Datatype
extern f32 D_global_asm_807F5E68[2][4][4]; // TODO: How many? At least 2
extern f32 D_global_asm_807F5FB0;
extern u8 D_global_asm_807F70AB;
extern s16 D_global_asm_807F7138;
extern f32 D_global_asm_807F5FB4;

void func_global_asm_80653B80(f32 arg0, f32 arg1, f32 arg2) {
    character_change_array[cc_player_index].chunk = func_global_asm_806531B8(arg0, arg1, arg2, character_change_array[cc_player_index].chunk);
    if (D_global_asm_807F70AB != 0) {
        character_change_array[cc_player_index].chunk = character_change_array[cc_player_index].player_pointer->unk12C;
    }
    func_global_asm_80663C60(&character_change_array[cc_player_index].far, character_change_array[cc_player_index].chunk);
    D_global_asm_807F7138 = character_change_array[cc_player_index].far;
    func_global_asm_8062A944(D_global_asm_807F5FB4, D_global_asm_807F5FB0, D_global_asm_807F7138);
    func_global_asm_8062AC68(&character_change_array[cc_player_index].unk8[D_global_asm_807444FC]);
    func_global_asm_8062AD28(arg0, arg1, arg2, &D_global_asm_807F5E68, &D_global_asm_807F5E20);
    func_global_asm_806521F8();
    func_global_asm_80653A70(character_change_array[cc_player_index].chunk);
    func_global_asm_806547A8(arg0, arg1, arg2);
    D_global_asm_807F6C80 = 0;
    D_global_asm_807F6C08 = 0;
    func_global_asm_80656F14(
        character_change_array[cc_player_index].chunk,
        0,
        character_change_array[cc_player_index].unk270,
        character_change_array[cc_player_index].unk272,
        character_change_array[cc_player_index].unk274,
        character_change_array[cc_player_index].unk276,
        arg0,
        arg1,
        arg2);
    func_global_asm_80654380(arg0, arg1, arg2);
    func_global_asm_8065F678(arg0, arg1, arg2, cc_player_index);
    func_global_asm_8066308C(arg0, arg1, arg2);
    func_global_asm_80655410(arg0, arg1, arg2);
}

// Loops over a DL and replaces texture indices with RDRAM pointers for G_SETTIMG commands
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80653DF0.s")

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80653EA8.s")

/*
void func_global_asm_80653EA8(Gfx *arg0, Gfx *arg1) {
    s32 temp[2];
    s32 sp44;
    u32 sp40;
    u32 temp_a0;

    while (arg0 != arg1) {
        if ((arg0->words.w0 >> 0x18) == G_SETTIMG) {
            temp_a0 = arg0->words.w1;
            if (temp_a0 >= 0x80000000 && temp_a0 < 0xA0000000) {
                func_global_asm_8066B7AC(temp_a0, &sp44, &sp40);
                func_global_asm_8066B434(arg0->words.w1, 0x542, 0x22);
                arg0->words.w1 = sp40;
            }
        }
        arg0++;
    }
}
*/

void func_global_asm_80653F68(s16 index) {
    chunk_array_pointer[index].unk7 |= 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80653FA4.s")

void func_global_asm_80654418(f32, f32, f32);
void func_global_asm_80654A2C(f32, f32, f32);
void func_global_asm_80655258(f32, f32, f32, s32);
extern s32 D_global_asm_807F70AC;

void func_global_asm_80654380(f32 arg0, f32 arg1, f32 arg2) {
    s32 i;

    func_global_asm_80654418(arg0, arg1, arg2);
    for (i = 0; i < D_global_asm_807F70AC; i++) {
        D_global_asm_807F70B0[i].unk18 = 0;
    }
    func_global_asm_80655258(arg0, arg1, arg2, -1);
    func_global_asm_80654A2C(arg0, arg1, arg2);
}

s32 func_global_asm_806545D4(s32, s32, s32, s32, f32, f32, f32, s32, f32 (*)[4], u8 *, void *);
extern s32 D_global_asm_807482F4;
extern f32 D_global_asm_807F5FB4;
extern s32 D_global_asm_807F7148;
extern f32 D_global_asm_807F5FAC;
extern s32 D_global_asm_807F70AC;

void func_global_asm_80654418(f32 arg0, f32 arg1, f32 arg2) {
    f32 spF8[4][4];
    f32 spB8[4][4];
    s32 i;
    s32 sp84[12];

    func_global_asm_8062A944(D_global_asm_807F5FB4, D_global_asm_807F5FB0, D_global_asm_807F5FAC);
    guMtxL2F(&spF8[0], &character_change_array[cc_player_index].unk8[D_global_asm_807444FC]);
    func_global_asm_8062FF10(&spB8[0], &spF8[0]);
    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1) {
            func_global_asm_806545D4(chunk_array_pointer[i].deload1, chunk_array_pointer[i].deload2, chunk_array_pointer[i].deload3, chunk_array_pointer[i].deload4, arg0, arg1, arg2, cc_player_index, &spB8[0], &chunk_array_pointer[i].pad2, &sp84);
            if (i == D_global_asm_807482F4) {
                memcpy(&D_global_asm_807F7148, &chunk_array_pointer[i].pad2, 0x140);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_806545D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_806547A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80654A2C.s")

void func_global_asm_80654BC0(s32 arg0, u8 arg1) {
    s32 found;
    s32 i;
    s32 max;

    for (i = 0, found = 0; !found && i < D_global_asm_807F70AC; i++) {
        if (arg0 == D_global_asm_807F70B0[i].unk2) {
            D_global_asm_807F70B0[i].unk18 = arg1;
            if (arg1) {
                D_global_asm_807F70B0[i].unk19 = 1;
            }
            found = TRUE;
        }
    }
    for (i = 0; i < D_global_asm_807F70AC; i++) {
        if (arg0 == D_global_asm_807F70B0[i].unk4) {
            func_global_asm_80654BC0(D_global_asm_807F70B0[i].unk2, arg1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80654CCC.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Struct80654E84;

s32 func_global_asm_80654E84(Struct80654E84 *arg0, f32 arg1, f32 arg2) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f16;
    f32 var_f2;

    if (arg0->unk0 < arg0->unk2) {
        var_f0 = arg0->unk0;
    } else {
        var_f0 = arg0->unk2;
    }
    if (!(var_f0 < arg0->unk4)) {
        var_f0 = arg0->unk4;
    }
    if (arg0->unkC < arg0->unkE) {
        var_f12 = arg0->unkC;
    } else {
        var_f12 = arg0->unkE;
    }
    if (!(var_f12 < arg0->unk10)) {
        var_f12 = arg0->unk10;
    }
    if (arg0->unk2 < arg0->unk0) {
        var_f16 = arg0->unk0;
    } else {
        var_f16 = arg0->unk2;
    }
    if (!(arg0->unk4 < var_f16)) {
        var_f16 = arg0->unk4;
    }
    if (arg0->unkE < arg0->unkC) {
        var_f2 = arg0->unkC;
    } else {
        var_f2 = arg0->unkE;
    }
    if (!(arg0->unk10 < var_f2)) {
        var_f2 = arg0->unk10;
    }
    if (!(!(arg1 < var_f0) && !(var_f16 < arg1) && !(arg2 < var_f12) && !(var_f2 < arg2))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80654FEC.s")

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80655258.s")

s32 func_global_asm_8062DBDC(s16, s16, s16, s16, s32, s32, f32, f32, f32, f32, u8 *);

/*
void func_global_asm_80655258(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < D_global_asm_807F70AC; i++) {
        if (arg3 == D_global_asm_807F70B0[i].unk4) {
            if (chunk_array_pointer[D_global_asm_807F70B0[i].unk0].loaded == 1) {
                if (func_global_asm_8062DBDC(
                    D_global_asm_807F70B4[D_global_asm_807F70B0[i].unk2].unk0,
                    D_global_asm_807F70B4[D_global_asm_807F70B0[i].unk2].unk2,
                    D_global_asm_807F70B4[D_global_asm_807F70B0[i].unk2].unk4,
                    D_global_asm_807F70B4[D_global_asm_807F70B0[i].unk2].unk6,
                    D_global_asm_807F70B4[D_global_asm_807F70B0[i].unk2].unk8,
                    D_global_asm_807F70B4[D_global_asm_807F70B0[i].unk2].unkA,
                    arg0,
                    arg1,
                    arg2,
                    D_global_asm_807F5FAC,
                    chunk_array_pointer[D_global_asm_807F70B0[i].unk0].pad2) != 0) { // TODO: I believe issue is here
                    D_global_asm_807F70B0[i].unk18 = 1;
                    D_global_asm_807F70B0[i].unk19 = 1;
                }
                if (D_global_asm_807F70B0[i].unk18 != 0) {
                    func_global_asm_80655258(arg0, arg1, arg2, D_global_asm_807F70B0[i].unk2);
                }
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80655410.s")

extern s32 D_global_asm_807F6C28;
extern u8 D_global_asm_807F713A;

void func_global_asm_80655AD0(void) {
    s32 i;

    if (D_global_asm_807F713A) {
        func_global_asm_8065E81C(0, 0x190);
    }
    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (chunk_array_pointer[i].unk3 && chunk_array_pointer[i].visible != 2 && !chunk_array_pointer[i].unk4) {
            if (chunk_array_pointer[i].unk60[D_global_asm_807444FC]) {
                func_global_asm_8061130C(chunk_array_pointer[i].unk60[D_global_asm_807444FC]);
                chunk_array_pointer[i].unk60[D_global_asm_807444FC] = 0;
            }
        }
    }
}

void func_global_asm_80655BF0(void) {
    Chunk14 *current;

    if (func_global_asm_80652E58(D_global_asm_807F70AA) == 0) {
        current = chunk_array_pointer[D_global_asm_807F70AA].unk14;
        while (current) {
            func_global_asm_80636164(current->unk0, current->unk24);
            func_global_asm_80636210(current->unk0, current->unk24);
            current = current->next;
        }
        current = chunk_array_pointer[D_global_asm_807F70AA].unk1C;
        while (current) {
            func_global_asm_80636164(current->unk0, current->unk24);
            func_global_asm_80636210(current->unk0, current->unk24);
            current = current->next;
        }
    }
    D_global_asm_807F70AA++;
    if (D_global_asm_807F6C28 == D_global_asm_807F70AA) {
        D_global_asm_807F70AA = 0;
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80655CF8.s")

extern s16 D_global_asm_807F6C30[];

/*
// TODO: Close, it's an unrolled loop
s32 func_global_asm_80655CF8(s16 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        if (arg0 == D_global_asm_807F6C30[i]) {
            return 1;
        }
    }
    return 0;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80655DD0.s")

// Displaylist stuff, chunks
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80656B98.s")

void func_global_asm_80656E58(s16 arg0, s16 arg1, u8 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < chunk_array_pointer[arg0].unk50; i++) {
        if (arg1 == chunk_array_pointer[arg0].unk4C[i].unk0) {
            if (arg3) {
                chunk_array_pointer[arg0].unk4C[i].unk2 |= (1 << arg2);
                return;
            }
            chunk_array_pointer[arg0].unk4C[i].unk2 &= ~(1 << arg2);
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80656F14.s")

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_806574B8.s")

extern u8 D_global_asm_807F7060[];
extern u8 D_global_asm_807F7070;

/*
s32 func_global_asm_806574B8(s32 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F7070; i++) {
        if (D_global_asm_807F7060[i] == arg0) {
            return 0;
        }
    }
    return 1;
}
*/

void func_global_asm_80657508(s32 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C08; i++) {
        if (D_global_asm_807F6BF0[i] == arg0) {
            return;
        }
    }
    if (i != 0xC) {
        D_global_asm_807F6BF0[D_global_asm_807F6C08] = arg0;
        D_global_asm_807F6C08++;
    }
}

void func_global_asm_8065756C(s16 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6C80; i++) {
        if (D_global_asm_807F6C58[i] == arg0) {
            return;
        }
    }
    D_global_asm_807F6C58[D_global_asm_807F6C80++] = arg0;
}

void func_global_asm_80657CB0(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
} Struct807F6C14;

extern Struct807F6C14 *D_global_asm_807F6C14;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
} Struct80657974_arg4;

void func_global_asm_80657974(s32 arg0, f32 arg1, f32 arg2, f32 arg3, Struct80657974_arg4 *arg4);

typedef struct {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    f32 unk20;
    f32 unk24;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    f32 unk2C;
} Struct807F6C24;

extern Struct807F6C24 *D_global_asm_807F6C24;

s32 func_global_asm_806575D0(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 var_f2;
    s32 temp;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    u8 sp4C[40];
    f32 sp48;
    f32 sp44;
    f32 sp40;

    sp40 = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk10);
    sp44 = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk8);
    sp48 = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk0);
    var_f2 = (func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk18) + ((sp48 * arg1) + (sp44 * arg2) + (sp40 * arg3))) / D_global_asm_807F6C24[arg0].unk20;
    if (var_f2 < 0.0) {
        var_f2 = 0.0 - var_f2;
    }
    if (var_f2 > 80.0) {
        return 0;
    } else {
        func_global_asm_80657CB0(arg0, arg1, arg2, arg3, &sp7C, &sp78, &sp74);
        func_global_asm_80657974(arg0, sp7C, sp78, sp74, &sp4C);
        if (func_global_asm_8065776C(&sp4C) != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_8065776C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80657974.s")

/*
// TODO: Hmm, not sure what's missing here...
void func_global_asm_80657974(s32 arg0, f32 arg1, f32 arg2, f32 arg3, Struct80657974_arg4 *arg4) {
    switch (D_global_asm_807F6C24[arg0].unk28) {
        case 0:
            arg4->unk20 = arg1;
            arg4->unk24 = arg2;
            arg4->unk0 = D_global_asm_807F6C14[arg0].unk0;
            arg4->unk10 = D_global_asm_807F6C14[arg0].unk10;
            arg4->unk4 = D_global_asm_807F6C14[arg0].unk4;
            arg4->unk14 = D_global_asm_807F6C14[arg0].unk14;
            arg4->unk8 = D_global_asm_807F6C14[arg0].unk8;
            arg4->unk18 = D_global_asm_807F6C14[arg0].unk18;
            arg4->unkC = D_global_asm_807F6C14[arg0].unkC;
            arg4->unk1C = D_global_asm_807F6C14[arg0].unk1C;
            break;
        case 1:
            arg4->unk20 = arg1;
            arg4->unk24 = arg3;
            arg4->unk0 = D_global_asm_807F6C14[arg0].unk0;
            arg4->unk10 = D_global_asm_807F6C14[arg0].unk20;
            arg4->unk4 = D_global_asm_807F6C14[arg0].unk4;
            arg4->unk14 = D_global_asm_807F6C14[arg0].unk24;
            arg4->unk8 = D_global_asm_807F6C14[arg0].unk8;
            arg4->unk18 = D_global_asm_807F6C14[arg0].unk28;
            arg4->unkC = D_global_asm_807F6C14[arg0].unkC;
            arg4->unk1C = D_global_asm_807F6C14[arg0].unk2C;
            break;
        case 2:
            arg4->unk20 = arg2;
            arg4->unk24 = arg3;
            arg4->unk0 = D_global_asm_807F6C14[arg0].unk10;
            arg4->unk10 = D_global_asm_807F6C14[arg0].unk20;
            arg4->unk4 = D_global_asm_807F6C14[arg0].unk14;
            arg4->unk14 = D_global_asm_807F6C14[arg0].unk24;
            arg4->unk8 = D_global_asm_807F6C14[arg0].unk18;
            arg4->unk18 = D_global_asm_807F6C14[arg0].unk28;
            arg4->unkC = D_global_asm_807F6C14[arg0].unk1C;
            arg4->unk1C = D_global_asm_807F6C14[arg0].unk2C;
            break;
    }
}
*/

void func_global_asm_80657CB0(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    s32 temp;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp24 = func_dk64_boot_8000773C(-D_global_asm_807F6C24[arg0].unk18);
    sp28 = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk8);
    sp2C = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk0);
    sp30 = (sp24 - ((func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk10) * arg3) + ((sp2C * arg1) + (sp28 * arg2)))) / D_global_asm_807F6C24[arg0].unk24;
    *arg4 = (func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk0) * sp30) + arg1;
    *arg5 = (func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk8) * sp30) + arg2;
    *arg6 = (func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk10) * sp30) + arg3;
}

void func_global_asm_80657E24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB) {
    if (arg0 == arg2 || arg1 == arg3) {
        *arg8 = arg4;
        *arg9 = arg5;
        *argA = arg6;
        *argB = arg7;
        return;
    }
    if (arg4 == arg6 || arg5 == arg7) {
        *arg8 = arg0;
        *arg9 = arg1;
        *argA = arg2;
        *argB = arg3;
        return;
    }
    if (arg0 < arg4) {
        *arg8 = arg0;
    } else {
        *arg8 = arg4;
    }
    if (arg1 < arg5) {
        *arg9 = arg1;
    } else {
        *arg9 = arg5;
    }
    if (arg6 < arg2) {
        *argA = arg2;
    } else {
        *argA = arg6;
    }
    if (arg7 < arg3) {
        *argB = arg3;
    } else {
        *argB = arg7;
    }
}

s32 func_global_asm_80657F14(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB) {
    if (arg0 == -1) {
        return FALSE;
    }
    if (arg4 == -1) {
        return FALSE;
    }
    if (arg4 < arg0) {
        *arg8 = arg0;
    } else {
        *arg8 = arg4;
    }
    if (arg5 < arg1) {
        *arg9 = arg1;
    } else {
        *arg9 = arg5;
    }
    if (arg2 < arg6) {
        *argA = arg2;
    } else {
        *argA = arg6;
    }
    if (arg3 < arg7) {
        *argB = arg3;
    } else {
        *argB = arg7;
    }
    if (*arg8 >= *argA) {
        return FALSE;
    }
    if (*arg9 >= *argB) {
        return FALSE;
    }
    return TRUE;
}

u8 func_global_asm_80658000(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4) {
    f32 temp[2];
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 var_f12;

    sp24 = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk10);
    sp28 = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk8);
    sp2C = func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk0);
    var_f12 = (func_dk64_boot_8000773C(D_global_asm_807F6C24[arg0].unk18) + ((sp2C * arg1) + (sp28 * arg2) + (sp24 * arg3))) / D_global_asm_807F6C24[arg0].unk20;
    if (var_f12 < 0.0) {
        var_f12 = 0.0 - var_f12;
    }
    return var_f12 <= arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80658134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_806582F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_8065850C.s")

/*
// TODO: oof
void func_global_asm_8065850C(f32 arg0[4][4], f32 arg1[4][4], s32 arg2, f32 arg3[4][4]) {
    f32 (*temp_v0)[4];
    f64 temp_f24;

    temp_v0 = &D_global_asm_807F5E68[arg2][0][0];
    temp_f24 = (temp_v0[3][2] + ((temp_v0[2][0] * arg0[0][0]) + (temp_v0[2][2] * arg0[0][1]) + (temp_v0[3][0] * arg0[0][2]))) / (((arg0[0][2] - arg1[0][2]) * temp_v0[3][0]) + ((temp_v0[2][0] * (arg0[0][0] - arg1[0][0])) + (temp_v0[2][2] * (arg0[0][1] - arg1[0][1]))));
    arg3[0][0] = ((arg1[0][0] - arg0[0][0]) * temp_f24) + arg0[0][0];
    arg3[0][1] = ((arg1[0][1] - arg0[0][1]) * temp_f24) + arg0[0][1];
    arg3[0][2] = ((arg1[0][2] - arg0[0][2]) * temp_f24) + arg0[0][2];
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80658624.s")

void func_global_asm_806588E0(s32 fileIndex) {
    void *file = getPointerTableFile(0x14, fileIndex, 1, 1);
    func_global_asm_80658930(file);
    if (file) {
        func_global_asm_8066B434(file, 0xBED, 0x22);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80658930.s")

extern s32 D_global_asm_807F6C20;

s16 func_global_asm_80658B08(s8 arg0, u8 *arg1, s16 arg2) {
    s16 i;
    s16 count;
    Struct807F6C1C *temp;

    count = 0;
    if (arg0 == -1) {
        return 0;
    }
    for (i = 0; i < D_global_asm_807F6C20 && count < arg2;) {
        if (arg0 == D_global_asm_807F6C1C[i].unk2) {
            arg1[count] = D_global_asm_807F6C1C[i].unk4;
            count++;
        }
        i++;
    }
    return count;
}

s32 func_global_asm_807009F4(s16);
s16 func_global_asm_80700AE4(s16, s16);

typedef struct {
    s32 unk0; // Used
    s16 unk4; // Used
    s16 unk6; // Used
    s16 unk8;
    s16 unkA;
    s32 unkC;
    u8 unk10; // Used
    u8 unk11; // Used
    u8 unk12;
    u8 unk13;
} Struct807F72B8;

extern Struct807F72B8 D_global_asm_807F7290[];

void func_global_asm_80658BD0(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        D_global_asm_807F7290[i].unk10 = 0;
    }
}

void func_global_asm_80658C10(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 found;
    s32 i;

    found = FALSE;
    i = 0;
    while (i < 10 && !found) {
        if (D_global_asm_807F7290[i].unk10 != 0) {
            i++;
        } else {
            found = TRUE;
        }
    }
    if (found) {
        D_global_asm_807F7290[i].unk10 = 1;
        D_global_asm_807F7290[i].unkC = object_timer;
        D_global_asm_807F7290[i].unk0 = arg0;
        D_global_asm_807F7290[i].unk4 = arg1;
        D_global_asm_807F7290[i].unk6 = arg2;
        D_global_asm_807F7290[i].unk8 = arg3;
    }
}

void func_global_asm_80658CCC(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if ((D_global_asm_807F7290[i].unk10 != 0) && (object_timer == D_global_asm_807F7290[i].unkC)) {
            if (func_global_asm_807009F4(func_global_asm_80700AE4(D_global_asm_807F7290[i].unk4, D_global_asm_807F7290[i].unk6)) <= (f32)D_global_asm_807F7290[i].unk8) {
                D_global_asm_807F7290[i].unk11 = 1;
            } else {
                D_global_asm_807F7290[i].unk11 = 0;
            }
        }
        if ((object_timer - D_global_asm_807F7290[i].unkC) >= 3U) {
            D_global_asm_807F7290[i].unk10 = 0;
        }
    }
}

u8 func_global_asm_80658DAC(s32 arg0) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (arg0 == D_global_asm_807F7290[i].unk0) {
            return D_global_asm_807F7290[i].unk11;
        }
    }
    return 0;
}

void func_global_asm_80658E58(u16 arg0, u16 arg1, u16 arg2, u16 arg3) {
    D_global_asm_807F7358 = arg0;
    D_global_asm_807F735A = arg1;
    D_global_asm_807F735C = arg2;
    D_global_asm_807F735E = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80658E8C.s")
