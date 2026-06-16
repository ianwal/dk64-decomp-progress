#include "common.h"

extern s32 D_global_asm_8076A0B4;
extern s32 D_global_asm_8076A0B8;
extern s32 D_global_asm_8076A0BC;
extern s32 D_global_asm_8076A0C0;
extern s32 D_global_asm_8076A0C4;
extern s32 D_global_asm_8076A0C8;

extern s16 D_global_asm_807F6BF0[];
extern u8 D_global_asm_807F6C08;
extern s32 D_global_asm_807F6C28; // Number of chunks?
extern s16 D_global_asm_807F6C58[];
extern s32 D_global_asm_807F6C80;

extern u8 D_global_asm_807F7078[];
extern u8 D_global_asm_807F70AA;
extern u8 D_global_asm_807F70AB;
extern u8 D_global_asm_807F7140;

extern s16 D_global_asm_807F7358;
extern s16 D_global_asm_807F735A;
extern s16 D_global_asm_807F735C;
extern s16 D_global_asm_807F735E;
extern s32 D_global_asm_807F5E20; // TODO: Datatype
extern f32 D_global_asm_807F5E68[2][4][4]; // TODO: How many? At least 2
extern f32 D_global_asm_807F5FB0;
extern f32 D_global_asm_807F5FB4;
extern s16 D_global_asm_807F7138;

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

extern s32 D_global_asm_807F70AC;
extern s32 D_global_asm_807482F4;
extern f32 D_global_asm_807F5FB4;
extern s32 D_global_asm_807F7148;
extern f32 D_global_asm_807F5FAC;
extern s32 D_global_asm_807F70AC;

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

extern s32 D_global_asm_807F6C28;
extern u8 D_global_asm_807F713A;

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

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct807F6D78;

extern Struct807F6D78 D_global_asm_807F6D78[];

extern s32 D_global_asm_807F6C20;

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

Chunk14* func_global_asm_80630890(Chunk14*, f32, f32, f32, void*);
void func_global_asm_8063B4C0(Chunk14*, u8);
s32 func_global_asm_806545D4(s32, s32, s32, s32, f32, f32, f32, s32, f32 (*)[4], u8 *, void *);
void func_global_asm_80656F14(s16, s32, s16, s16, s32, s32, f32, f32, f32);
void func_global_asm_80657974(s32 arg0, f32 arg1, f32 arg2, f32 arg3, Struct80657974_arg4 *arg4);

typedef struct global_asm_struct_18 {
    s32 unk0;
    u8 pad4[0x64 - 0x4];
    s32 *unk64;
} GlobalASMStruct18;

void func_global_asm_80650E20(MapGeometryHeader *arg0) {
    s32 size;
    u8 phi_v1;

    D_global_asm_807F6C28 = *(u32*)(arg0->unk64 + (s32)&arg0->unk0);
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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80650ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80651708.s")

typedef struct Struct807F70B8_sub8 {
    s16 unk0[3];
    s16 unk6[3];
    s16 unkC[3];
} Struct807F70B8_sub8;

typedef struct Struct807F70B8 {
    s16 *unk0;
    s16 unk4;
    s16 unk6;
    Struct807F70B8_sub8 *unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
} Struct807F70B8;
extern Struct807F70B8 *D_807F70B8[];

/*
void func_global_asm_80651708(s32 arg0) {
    Struct807F70B8 *var_v1; // 1c
    s32 var_a1; // 18
    s32 i;

    var_v1 = D_807F70B8[arg0];
    if (var_v1->unk8 != NULL) {
        free(var_v1->unk8);
    }
    var_a1 = var_v1->unk4 - 2;
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_a1 != 0) {
        var_v1->unk8 = malloc(var_a1 * sizeof(Struct807F70B8_sub8));
        var_v1->unkC = var_a1;
        for (i = 2; i < var_v1->unk4; i++) {
            var_v1->unk8[i - 2].unk0[0] = var_v1->unk0[i + 0];
            var_v1->unk8[i - 2].unk6[0] = var_v1->unk0[i + 1];
            var_v1->unk8[i - 2].unkC[0] = var_v1->unk0[i + 2];
            var_v1->unk8[i - 2].unk0[1] = var_v1->unk0[i + 3];
            var_v1->unk8[i - 2].unk6[1] = var_v1->unk0[i + 4];
            var_v1->unk8[i - 2].unkC[1] = var_v1->unk0[i + 5];
            var_v1->unk8[i - 2].unk0[2] = var_v1->unk0[i + 6];
            var_v1->unk8[i - 2].unk6[2] = var_v1->unk0[i + 7];
            var_v1->unk8[i - 2].unkC[2] = var_v1->unk0[i + 8];
        }
    }
    var_v1->unk12 = -0x8000;
    var_v1->unk10 = 0x7FFF;
    for (i = 0; i < var_v1->unk4; i++) {
        if (var_v1->unk12 < var_v1->unk0[i + 1]) {
            var_v1->unk12 = var_v1->unk0[i + 1];
        }
        if (var_v1->unk0[i + 1] < var_v1->unk10) {
            var_v1->unk10 = var_v1->unk0[i + 1];
        }
    }
}
*/


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

// 64 bit stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80651C2C.s")

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

void func_global_asm_806524A0(PropModel *arg0, u8 arg1) {
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

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80652594.s")

/*
// Something to do with arg2? Loop condition? Break?
u8 func_global_asm_80652594(PropModel *arg0, s16 *arg1, u8 arg2) {
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
    sp6E = func_global_asm_80630324(1, NULL);
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

s32 func_global_asm_80652DB4(f32 arg0, f32 arg1, f32 arg2) {
    s16 temp_v0;
    s32 i;
    s16 new_var;
    f32 new_var2;
    s16 *ptr;

    i = 0;
    if (D_global_asm_807F6C28 == 0) {
        return 0xFF;
    }
    new_var2 = arg1;
    temp_v0 = func_global_asm_806531B8(arg0, new_var2, arg2, 0);
    while (i < D_global_asm_807F6C80) {
        ptr = &D_global_asm_807F6C58[i];
        new_var = temp_v0;
        if (D_global_asm_807F6C58[i] == new_var) {
            return 1;
        }
        i++;

        // fake match
        if (0) {
        }
    }

    return 0;
}

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

// fiddly
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
extern Struct807F70B4 *D_807F70B4;

/*
void func_global_asm_80652FDC(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4, s16 *arg5) {
    s32 i;
    Struct807F70B4 *temp_v0_2;
    s16 temp_v1;

    for (i = 0; i < D_global_asm_807F70AC; i++) {
        if ((arg3 == D_global_asm_807F70B0[i].unk0) && (arg4 == D_global_asm_807F70B0[i].unk4)) {
            temp_v1 = D_global_asm_807F70B0[i].unk2;
            temp_v0_2 = &D_807F70B4[temp_v1];
            if ((temp_v0_2->unk0 <= arg0) && (arg0 <= temp_v0_2->unk6) && (temp_v0_2->unk2 <= arg1) && (arg1 <= temp_v0_2->unk8) && (temp_v0_2->unk4 <= arg2) && (arg2 <= temp_v0_2->unkA)) {
                *arg5 = temp_v1;
                func_global_asm_80652FDC(arg0, arg1, arg2, arg3, temp_v1, arg5);
            }
        }
    }
}
*/

typedef struct Struct806531B8 {
    s16 chunk;
    u8 pad[2];
    f32 y;
} Struct806531B8;

s16 func_global_asm_806531B8(f32 x, f32 y, f32 z, s16 chunk) {
    s32 var_s3;
    f32 var_f20;
    u8 sp207;
    u8 var_s0;
    f32 sp200;
    Struct806531B8 sp70[50];
    s32 pad[2];
    s32 i;
    s32 j = 0;

    if (D_global_asm_807F6C28 == 0) {
        return -1;
    }
    x *= 6;
    y *= 6;
    z *= 6;
    if (func_global_asm_806534E0(x, y, z, chunk, &sp207, &sp200)) {
        if (!sp207) {
            return chunk;
        }
        sp70[0].chunk = chunk;
        sp70[0].y = sp200;
        j = 1;
    }
    var_s0 = FALSE;
    i = 0;
    while (i < D_global_asm_807F6C28) {
        if (chunk != i) {
            if (func_global_asm_806534E0(x, y, z, i, &sp207, &sp200)) {
                if (!sp207) {
                    var_s0 = TRUE;
                } else {
                    sp70[j].chunk = i;
                    sp70[j].y = sp200;
                    j++;
                    i++;
                }
            } else {
                i++;
            }
        } else {
            i++;
        }
        if (var_s0) {
            break;
        }
    }
    if (var_s0) {
        return i;
    }
    if (j == 0) {
        return chunk;
    }
    var_f20 = sp70[0].y;
    var_s3 = sp70[0].chunk;
    for (i = 0; i < j; i++) {
        if (func_global_asm_806533C4(var_f20, sp70[i].y, y)) {
            var_f20 = sp70[i].y;
            var_s3 = sp70[i].chunk;
        }
    }
    return var_s3;
}

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
u8 func_global_asm_80653804(Chunk78_7C *arg0, f32 arg1, f32 arg2) {
    f64 temp_f12;
    f64 temp_f14;
    f64 temp_f22;
    f64 temp_f24;
    s32 i;
    f64 phi_f2;
    f64 phi_f0;
    f64 phi_f20;
    s32 phi_a0;
    s32 phi_t3;
    f64 phi_f18;
    u8 phi_v1;
    f64 var_0;
    f64 var_2;
    f64 var_c;
    f64 a1;
    f64 a2;
    f64 temp_0;

    temp_f22 = (arg0->unk0 + ((arg0->unk4 + arg0->unk2) * 0.5)) * 0.5;
    var_c = arg0->unkC;
    temp_f24 = (var_c + ((arg0->unk10 + arg0->unkE) * 0.5)) * 0.5;
    a1 = arg1;
    a2 = arg2;
    var_2 = arg0->unk2;
    phi_v1 = FALSE;
    for (i = 0; i != 3; i++) {
        switch (i) {
            default:
                // 3
                phi_f2 = (a2 - phi_f18) * temp_f12;
                phi_f0 = (a1 - var_2) * temp_f14;
                phi_f20 = ((temp_f22 - var_2) * temp_f14) - ((temp_f24 - phi_f18) * temp_f12);
                break;
            case 0:
                temp_f14 = arg0->unkE - arg0->unkC;
                temp_f12 = arg0->unk2 - arg0->unk0;
                phi_f2 = (a2 - var_c) * temp_f12;
                phi_f0 = (a1 - arg0->unk0) * temp_f14;
                phi_f20 = ((temp_f22 - arg0->unk0) * temp_f14) - ((temp_f24 - arg0->unkC) * temp_f12);
                break;
            case 1:
                temp_f14 = arg0->unk10 - arg0->unkC;
                temp_f12 = arg0->unk4 - arg0->unk0;
                phi_f2 = (a2 - arg0->unkC) * temp_f12;
                phi_f0 = (a1 - arg0->unk0) * temp_f14;
                phi_f20 = ((temp_f22 - arg0->unk0) * temp_f14) - ((temp_f24 - arg0->unkC) * temp_f12);
                break;
            case 2:
                temp_f12 = arg0->unk4 - arg0->unk2;
                temp_f14 = arg0->unk10 - arg0->unkE;
                phi_f2 = (a2 - arg0->unkE) * temp_f12;
                phi_f0 = (a1 - arg0->unk2) * temp_f14;
                phi_f20 = ((temp_f22 - arg0->unk2) * temp_f14) - ((temp_f24 - arg0->unkE) * temp_f12);
                phi_f18 = arg0->unkE;
                break;
        }
        phi_t3 = phi_f2 <= phi_f0 ? 1 : -1;
        phi_a0 = phi_f20 >= 0.0 ? 1 : -1;
        if (phi_a0 != phi_t3) {
            phi_v1 = TRUE;
        }
    }
    return !phi_v1;
}
*/

void func_global_asm_80653A70(s16 chunkIndex) {
    chunk_array_pointer[chunkIndex].loaded = 1;
    chunk_array_pointer[chunkIndex].unk1 |= 1 << cc_player_index;
    chunk_array_pointer[chunkIndex].deload1 = character_change_array[cc_player_index].unk270[0];
    chunk_array_pointer[chunkIndex].deload2 = character_change_array[cc_player_index].unk270[1];
    chunk_array_pointer[chunkIndex].deload3 = character_change_array[cc_player_index].unk270[2];
    chunk_array_pointer[chunkIndex].deload4 = character_change_array[cc_player_index].unk270[3];
}

void func_global_asm_80653B70(u8 arg0) {
    D_global_asm_807F70AB = arg0;
}

void func_global_asm_80653B80(f32 arg0, f32 arg1, f32 arg2) {
    character_change_array[cc_player_index].chunk = func_global_asm_806531B8(arg0, arg1, arg2, character_change_array[cc_player_index].chunk);
    if (D_global_asm_807F70AB != 0) {
        character_change_array[cc_player_index].chunk = character_change_array[cc_player_index].playerPointer->unk12C;
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
        character_change_array[cc_player_index].unk270[0],
        character_change_array[cc_player_index].unk270[1],
        character_change_array[cc_player_index].unk270[2],
        character_change_array[cc_player_index].unk270[3],
        arg0,
        arg1,
        arg2);
    func_global_asm_80654380(arg0, arg1, arg2);
    func_global_asm_8065F678(arg0, arg1, arg2, cc_player_index);
    func_global_asm_8066308C(arg0, arg1, arg2);
    func_global_asm_80655410(arg0, arg1, arg2);
}

// Loops over a DL and replaces texture indices with RDRAM pointers for G_SETTIMG commands
// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80653DF0.s")

/*
Gfx *func_global_asm_80653DF0(Gfx *dl, Gfx* arg1, s16 arg2) {
    s32 cmd;
    s32 i = 0;

    while ((dl != arg1) && (i < arg2)) {
        cmd = dl->words.w0 >> 0x18;
        if (cmd == G_SETTIMG) {
            if (((dl->setimg.dram * 0x10) >> 0x1C) == 0) {
                dl->setimg.dram = getPointerTableFile(TABLE_25_TEXTURES_GEOMETRY, dl->setimg.dram, 0U, 0U);
                i++;
            }
        }
        dl++;
    }
    return dl;
}
*/

void func_global_asm_80653EA8(Gfx *arg0, Gfx *arg1) {
    s32 temp[2];
    s32 sp44;
    u32 sp40;
    u32 new_var;
    u32 temp_a0;
    while (arg0 != arg1) {
        new_var = arg0->words.w0 >> 0x18;
        if (new_var == G_SETTIMG)
        {
            temp_a0 = arg0->words.w1;
            do {
                if ((temp_a0 >= 0x80000000) && (temp_a0 < 0xA0000000)) {
                    func_global_asm_8066B7AC(temp_a0, &sp44, &sp40);
                    func_global_asm_8066B434(arg0->words.w1, 0x542, 0x22);
                    arg0->words.w1 = sp40;
                }
            } while (0);
        }
        arg0++;
    }
}

void func_global_asm_80653F68(s16 index) {
    chunk_array_pointer[index].unk7 |= 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80653FA4.s")

void func_global_asm_80654380(f32 arg0, f32 arg1, f32 arg2) {
    s32 i;

    func_global_asm_80654418(arg0, arg1, arg2);
    for (i = 0; i < D_global_asm_807F70AC; i++) {
        D_global_asm_807F70B0[i].unk18 = 0;
    }
    func_global_asm_80655258(arg0, arg1, arg2, -1);
    func_global_asm_80654A2C(arg0, arg1, arg2);
}

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

// cc, matrix, loop
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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80654CCC.s")

s32 func_global_asm_80654E84(Struct80654E84 *arg0, f32 arg1, f32 arg2) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f16;
    f32 var_f2;

    var_f0 = MIN(arg0->unk0, arg0->unk2);
    if (!(var_f0 < arg0->unk4)) {
        var_f0 = arg0->unk4;
    }
    var_f12 = MIN(arg0->unkC, arg0->unkE);
    if (!(var_f12 < arg0->unk10)) {
        var_f12 = arg0->unk10;
    }
    var_f16 = MAX(arg0->unk0, arg0->unk2);
    if (!(arg0->unk4 < var_f16)) {
        var_f16 = arg0->unk4;
    }
    var_f2 = MAX(arg0->unkC, arg0->unkE);
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
                    D_807F70B4[D_global_asm_807F70B0[i].unk2].unk0,
                    D_807F70B4[D_global_asm_807F70B0[i].unk2].unk2,
                    D_807F70B4[D_global_asm_807F70B0[i].unk2].unk4,
                    D_807F70B4[D_global_asm_807F70B0[i].unk2].unk6,
                    D_807F70B4[D_global_asm_807F70B0[i].unk2].unk8,
                    D_807F70B4[D_global_asm_807F70B0[i].unk2].unkA,
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

void func_global_asm_80655AD0(void) {
    s32 i;

    if (D_global_asm_807F713A) {
        func_global_asm_8065E81C(0, 0x190);
    }
    for (i = 0; i < D_global_asm_807F6C28; i++) {
        if (chunk_array_pointer[i].unk3 && chunk_array_pointer[i].visible != 2 && !chunk_array_pointer[i].unk4) {
            void *temp = chunk_array_pointer[i].unk60[D_global_asm_807444FC];
            if (temp != NULL) {
                free(temp);
                chunk_array_pointer[i].unk60[D_global_asm_807444FC] = NULL;
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

extern s16 D_807F6C30[];

/*
// It's an unrolled loop
s32 func_global_asm_80655CF8(s16 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        if (arg0 == D_807F6C30[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
*/

// Displaylist stuff, rodata
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

extern u8 D_global_asm_807F7060[];
extern u8 D_global_asm_807F7070;

s32 func_global_asm_806574B8(s32 arg0) {
    u8 *ptr;
    ptr = D_global_asm_807F7060;
    if (D_global_asm_807F7070 > 0) {
        // fake match, whitespace matters here so formatting is disabled.
        // clang-format off
        do { do { if (arg0 == (*ptr)) { return 0; } ptr++; if (ptr) { } } while (ptr < (&D_global_asm_807F7060[D_global_asm_807F7070])); } while (0);
        // clang-format on
    }
    return 1;
}

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

    sp40 = __ll_to_f(D_global_asm_807F6C24[arg0].unk10);
    sp44 = __ll_to_f(D_global_asm_807F6C24[arg0].unk8);
    sp48 = __ll_to_f(D_global_asm_807F6C24[arg0].unk0);
    var_f2 = (__ll_to_f(D_global_asm_807F6C24[arg0].unk18) + ((sp48 * arg1) + (sp44 * arg2) + (sp40 * arg3))) / D_global_asm_807F6C24[arg0].unk20;
    if (var_f2 < 0.0) {
        var_f2 = 0.0 - var_f2;
    }
    if (var_f2 > 80.0) {
        return FALSE;
    } else {
        func_global_asm_80657CB0(arg0, arg1, arg2, arg3, &sp7C, &sp78, &sp74);
        func_global_asm_80657974(arg0, sp7C, sp78, sp74, &sp4C);
        if (func_global_asm_8065776C(&sp4C) != 0) {
            return TRUE;
        }
    }
    return FALSE;
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

    sp24 = __ll_to_f(-D_global_asm_807F6C24[arg0].unk18);
    sp28 = __ll_to_f(D_global_asm_807F6C24[arg0].unk8);
    sp2C = __ll_to_f(D_global_asm_807F6C24[arg0].unk0);
    sp30 = (sp24 - ((__ll_to_f(D_global_asm_807F6C24[arg0].unk10) * arg3) + ((sp2C * arg1) + (sp28 * arg2)))) / D_global_asm_807F6C24[arg0].unk24;
    *arg4 = (__ll_to_f(D_global_asm_807F6C24[arg0].unk0) * sp30) + arg1;
    *arg5 = (__ll_to_f(D_global_asm_807F6C24[arg0].unk8) * sp30) + arg2;
    *arg6 = (__ll_to_f(D_global_asm_807F6C24[arg0].unk10) * sp30) + arg3;
}

void func_global_asm_80657E24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB) {
    if (arg0 == arg2 || arg1 == arg3) {
        *arg8 = arg4;
        *arg9 = arg5;
        *argA = arg6;
        *argB = arg7;
    } else if (arg4 == arg6 || arg5 == arg7) {
        *arg8 = arg0;
        *arg9 = arg1;
        *argA = arg2;
        *argB = arg3;
    } else {
        *arg8 = MIN(arg0, arg4);
        *arg9 = MIN(arg1, arg5);
        *argA = MAX(arg2, arg6);
        *argB = MAX(arg3, arg7);
    }
}

s32 func_global_asm_80657F14(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 *arg8, s32 *arg9, s32 *argA, s32 *argB) {
    if (arg0 == -1) {
        return FALSE;
    }
    if (arg4 == -1) {
        return FALSE;
    }
    *arg8 = MAX(arg0, arg4);
    *arg9 = MAX(arg1, arg5);
    *argA = MIN(arg2, arg6);
    *argB = MIN(arg3, arg7);
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

    sp24 = __ll_to_f(D_global_asm_807F6C24[arg0].unk10);
    sp28 = __ll_to_f(D_global_asm_807F6C24[arg0].unk8);
    sp2C = __ll_to_f(D_global_asm_807F6C24[arg0].unk0);
    var_f12 = (__ll_to_f(D_global_asm_807F6C24[arg0].unk18) + ((sp2C * arg1) + (sp28 * arg2) + (sp24 * arg3))) / D_global_asm_807F6C24[arg0].unk20;
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

void func_global_asm_80658624(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    f32 sp7C;
    f32 sp78;
    s16 var_a1;
    s16 var_a2;
    s32 i;
    u8 var_s3;

    *arg1 = character_change_array[cc_player_index].unk270[2];
    *arg2 = character_change_array[cc_player_index].unk270[3];
    *arg3 = character_change_array[cc_player_index].unk270[0];
    *arg4 = character_change_array[cc_player_index].unk270[1];
    var_s3 = 0;
    for (i = 0; i < arg0; i++) {
        var_s3 |= func_global_asm_80626F8C(D_global_asm_807F6D78[i].unk0, D_global_asm_807F6D78[i].unk4, D_global_asm_807F6D78[i].unk8, &sp7C, &sp78, 0, 1.0f, cc_player_index);
        var_a1 = sp7C;\
        var_a2 = sp78;
        if (var_a1 < character_change_array[cc_player_index].unk270[0]) {
            var_a1 = character_change_array[cc_player_index].unk270[0];
        }
        if (var_a2 < character_change_array[cc_player_index].unk270[1]) {
            var_a2 = character_change_array[cc_player_index].unk270[1];
        }
        if (character_change_array[cc_player_index].unk270[2] < var_a1) {
            var_a1 = character_change_array[cc_player_index].unk270[2];
        }
        if (character_change_array[cc_player_index].unk270[3] < var_a2) {
            var_a2 = character_change_array[cc_player_index].unk270[3];
        }
        if (var_a1 < *arg1) {
            *arg1 = var_a1;
        }
        if (var_a2 < *arg2) {
            *arg2 = var_a2;
        }
        if (*arg3 < var_a1) {
            *arg3 = var_a1;
        }
        if (*arg4 < var_a2) {
            *arg4 = var_a2;
        }
    }
    if ((*arg1 == *arg3) || (*arg2 == *arg4) || (var_s3)) {
        *arg1 = -1;
        *arg2 = -1;
        *arg3 = -1;
        *arg4 = -1;
    }
}

typedef struct Pointer20Struct_sub0 {
    u8 pad0[0x20];
} Pointer20Struct_sub0;

typedef struct Pointer20Struct_sub1 {
    u8 pad0[0x10];
} Pointer20Struct_sub1;

typedef struct Pointer20Struct_sub {
    Pointer20Struct_sub0 unk0;
    s16 unk20;
} Pointer20Struct_sub;

typedef struct Pointer20Struct {
    void *unk0;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    u8 padC[0xE - 0xC];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    Pointer20Struct_sub0 unk14;
    s8 unk34;
    u8 pad35;
    Pointer20Struct_sub0 unk36;
    s8 unk56;
    u8 pad57;
    Pointer20Struct_sub1 unk58;
    s8 unk68;
    u8 pad69[0x6C - 0x69];
} Pointer20Struct;

typedef struct Pointer20Struct_sub2 {
    s16 unk0;
    s16 unk2;
} Pointer20Struct_sub2;

typedef struct Pointer20File {
    s16 count;
    s16 data[];
} Pointer20File;

void func_global_asm_80658930(Pointer20File *);

void func_global_asm_806588E0(s32 fileIndex) {
    void *file = getPointerTableFile(TABLE_20_UNKNOWN, fileIndex, 1, 1);
    func_global_asm_80658930(file);
    if (file) {
        func_global_asm_8066B434(file, 0xBED, 0x22);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_global_asm_80658930.s")

void func_global_asm_80651708(s32);
// extern Pointer20Struct *D_807F70B8[];

/*
void func_global_asm_80658930(Pointer20File *arg0) {
    s16 sp46;
    Pointer20Struct_sub2 *temp_s0_2;
    s16 *var_s0;
    s16 temp_s3;
    s16 count;
    s32 i;
    Pointer20Struct_sub *temp_s0_3;
    Pointer20Struct_sub1 *temp_s0_5;
    Pointer20Struct *temp_s2;
    Pointer20Struct *temp_s2_2;
    s16 temp = -0x8000;

    for (i = 0; i < 0x20; i++) {
        D_807F70B8[i] = 0;
    }
    if (arg0 == NULL) {
        return;
    }
    count = arg0->count;
    var_s0 = &arg0->data;
    for (i = 0; i < count; i++) {
        temp_s3 = *var_s0++;
        D_807F70B8[temp_s3] = malloc(sizeof(Pointer20Struct));
        D_807F70B8[temp_s3]->unk12 = temp;
        D_807F70B8[temp_s3]->unk10 = 0x7FFF;
        D_807F70B8[temp_s3]->unk8 = 0;
        D_807F70B8[temp_s3]->unk4 = *var_s0++;
        D_807F70B8[temp_s3]->unk0 = malloc(D_807F70B8[temp_s3]->unk4 * 6);
        memcpy(D_807F70B8[temp_s3]->unk0, var_s0, D_807F70B8[temp_s3]->unk4 * 6);
        temp_s0_2 = var_s0 + ((u32) (D_807F70B8[temp_s3]->unk4 * 6) >> 1);
        temp_s0_3 = temp_s0_2 + 1;
        D_807F70B8[temp_s3]->unkE = temp_s0_2->unk0;
        D_807F70B8[temp_s3]->unk34 = temp_s0_2->unk2;
        memcpy(&D_807F70B8[temp_s3]->unk14, temp_s0_3, sizeof(Pointer20Struct_sub0));
        D_807F70B8[temp_s3]->unk56 = temp_s0_3->unk20;
        temp_s0_3++;
        memcpy(&D_807F70B8[temp_s3]->unk36, temp_s0_3, sizeof(Pointer20Struct_sub0));
        D_807F70B8[temp_s3]->unk68 = temp_s0_3->unk20;
        temp_s0_5 = temp_s0_3 + 1;
        memcpy(&D_807F70B8[temp_s3]->unk58, temp_s0_5, sizeof(Pointer20Struct_sub1));
        var_s0 = temp_s0_5 + 1;
        func_global_asm_80651708(temp_s3);
    }
}
*/

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

s32 func_global_asm_80658E8C(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4) {
    f32 sp44;
    f32 sp40;
    s16 sp3E;
    s16 sp3C;
    f32 d;
    f32 temp_f2_2;
    s16 var_a0;
    s16 var_a1;
    s16 var_a2;
    s16 var_v1;

    func_global_asm_80626F8C(arg0, arg1, arg2, &sp44, &sp40, 0, 1.0f, cc_player_index);
    sp3E = sp44;
    sp3C = sp40;
    d = sqrtf(
        SQ(arg0 - character_change_array[cc_player_index].unk21C) +
        SQ(arg1 - character_change_array[cc_player_index].unk220) +
        SQ(arg2 - character_change_array[cc_player_index].unk224)
    );
    if (d < 90.0f) {
        return 0;
    }
    if (d >= 180.0f) {
        var_v1 = 0x14;
        var_a0 = 0x14;
        var_a1 = 0;
        var_a2 = 0x32;
    } else {
        temp_f2_2 = (d - 60.0f) / 120.0f;
        if (temp_f2_2 > 0.0) {
            var_v1 = (-60.0f * temp_f2_2) + 80.0f;
            var_a0 = (-60.0f * temp_f2_2) + 80.0f;
            var_a1 = (-130.0f * temp_f2_2) + 130.0f;
            var_a2 = (-80.0f * temp_f2_2) + 130.0f;
        } else {
            var_v1 = 0x50;
            var_a0 = 0x50;
            var_a1 = 0x82;
            var_a2 = 0x82;
        }
    }
    if ((sp3E < ((D_global_asm_807F7358 - var_v1) - arg3)) || ((D_global_asm_807F735C + var_a0 + arg3) < sp3E) || (sp3C < ((D_global_asm_807F735A - var_a1) - arg4)) || ((((D_global_asm_807F735E + var_a2 + arg4) < sp3C)))) {
        return 1;
    } else {
        return 0;
    }
}
