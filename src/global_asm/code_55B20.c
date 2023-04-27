#include <ultra64.h>
#include "functions.h"


extern s16 D_807F6BF0[];
extern u8 D_807F6C08;
extern s32 D_807F6C28; // Number of chunks?
extern s16 D_807F6C58[];
extern s32 D_807F6C80;

extern u8 D_807F7078[];
extern u8 D_807F70AA;
extern u8 D_807F70AB;
extern u8 D_807F7140;

extern u16 D_807F7358;
extern u16 D_807F735A;
extern u16 D_807F735C;
extern u16 D_807F735E;

void func_80636164(s32, u8);
void func_80636210(s32, u8);
void func_8063B4C0(Chunk14*, u8);
s32 func_8063A38C(Chunk14*, Chunk14*, f32, f32, f32);

void func_80652FDC(f32, f32, f32, s16, s16, s16*);
Chunk14* func_80630890(Chunk14*, f32, f32, f32, void*);
u8 func_80668E9C(s32, s16, f32, f32, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80650E20.s")

/*
s32 malloc(s32);
extern s32 D_8076A0B4;
extern s32 D_8076A0B8;
extern s32 D_8076A0BC;
extern s32 D_8076A0C0;
extern s32 D_8076A0C4;
extern s32 D_8076A0C8;

typedef struct global_asm_struct_18 {
    s32 unk0;
    u8 pad4[0x64 - 0x4];
    s32 *unk64;
} GlobalASMStruct18;

// TODO: Single instruction off, I probably should be using the struct, idk
void func_80650E20(s32 *arg0) {
    s32 size;
    u8 phi_v1;

    D_807F6C28 = arg0[arg0[25]];
    if (D_807F6C28 >= 2) {
        phi_v1 = D_807F6C28;
    } else {
        phi_v1 = 1;
    }
    size = phi_v1 * 4;
    D_8076A0B4 = malloc(size);
    D_8076A0B8 = malloc(size);
    D_8076A0BC = malloc(size);
    D_8076A0C0 = malloc(size);
    D_8076A0C4 = malloc(size);
    D_8076A0C8 = malloc(size);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80650ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80651708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80651904.s")

// TODO: Any more cleanup possible?
u8 func_80651B64(s16 arg0) {
    s32 phi_v1;
    s32 phi_v0;

    phi_v1 = (arg0 + 1) != 0;
    if (phi_v1) {
        phi_v0 = chunk_array_pointer[arg0].unk3 ? TRUE : FALSE;
        phi_v1 = phi_v0 != 0;
    }
    return phi_v1;
}

void func_80651BC0(s16 arg0, u8 arg1) {
    D_807F7078[arg0] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80651BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80651C2C.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 unk19; // Used
    u8 unk1A;
    u8 unk1C;
} Struct807F70B0;
extern Struct807F70B0 *D_807F70B0;

// Note: Needs to be aligned in memory by maximum 0x2: {s32 unk0; s32 unk4; u8 unk8; u8 unk9;} doesn't match
typedef struct {
    u8 unk0[0xA];
} Struct807F6C1C;

extern Struct807F6C1C *D_807F6C1C;
extern s32 D_807F6C20;
extern s32 D_807F6C28;
extern u8 *D_807F6C2C;

extern s32 D_807F70AC;

void func_8065214C(void) {
    s32 i;
    s32 j;

    for (i = 0; i < D_807F6C28; i++) {
        chunk_array_pointer[i].unk1 = 0;
        chunk_array_pointer[i].unk2 = 1;
        chunk_array_pointer[i].unk4 = 0;
    }
    for (j = 0; j < D_807F70AC; j++) {
        D_807F70B0[j].unk19 = 0;
    }
}

void func_806521F8(void) {
    s32 i;

    for (i = 0; i < D_807F6C28; i++) {
        chunk_array_pointer[i].loaded = 0;
        chunk_array_pointer[i].deload1 = 0;
        chunk_array_pointer[i].deload2 = 0;
        chunk_array_pointer[i].deload3 = 0;
        chunk_array_pointer[i].deload4 = 0;
    }
    for (i = 0; i < D_807F6C20; i++) {
        D_807F6C1C[i].unk0[8] = 0;
        D_807F6C2C[i] = 0;
    }
}

s32 func_806522CC(s16 arg0, s16 arg1, s16 arg2) {
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

// TODO: Unknown struct arg0, doable other than that
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80652374.s")

void func_806524A0(s32 arg0, u8 arg1) {
    u8 sp4F;
    s32 i;

    sp4F = 0;
    // TODO: While loop better for this? Multi condition in for loop is odd
    for (i = 0; i < D_807F6C28 && !sp4F; i++) {
        func_806307CC(chunk_array_pointer[i].unk14, arg0, 0, arg1, &sp4F);
        if (sp4F == 0) {
            func_806307CC(chunk_array_pointer[i].unk1C, arg0, 0, arg1, &sp4F);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80652594.s")

Chunk14 *func_80630588(Chunk14*, s32, s32, u8*);

/*
// TODO: Quite close
// Something to do with arg2? Loop condition? Break?
u8 func_80652594(s32 arg0, s16 *arg1, u8 arg2) {
    u8 sp4F;
    s16 i;
    s32 pad;

    sp4F = 0;
    i = 0;
    while (i < D_807F6C28 && !sp4F && arg2) {
        chunk_array_pointer[i].unk14 = func_80630588(chunk_array_pointer[i].unk14, arg0, 0, &sp4F);
        if (sp4F) {
            *arg1 = i;
        }
        if (!sp4F || arg2) {
            chunk_array_pointer[i].unk1C = func_80630588(chunk_array_pointer[i].unk1C, arg0, 0, &sp4F);
            if (sp4F) {
                *arg1 = i;
            }
        }
        i++;
    }
    return sp4F;
}
*/

void func_806526E0(u8 arg0) {
    s32 i;

    for (i = 0; i < D_807F6C28; i++) {
        if ((chunk_array_pointer[i].loaded == 1) || (arg0 != 0)) {
            func_806307AC(chunk_array_pointer[i].unk14);
            func_806307AC(chunk_array_pointer[i].unk1C);
        }
    }
}

void func_80652790(u8 arg0) {
    s32 i;

    for (i = 0; i < D_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1 || (arg0 != 0)) {
            chunk_array_pointer[i].unk14 = func_8063070C(chunk_array_pointer[i].unk14);
            chunk_array_pointer[i].unk1C = func_8063070C(chunk_array_pointer[i].unk1C);
        }
    }
}

void func_80652858(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < D_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1 || (arg3 != 0)) {
            chunk_array_pointer[i].unk14 = func_80630890(chunk_array_pointer[i].unk14, arg0, arg1, arg2, &chunk_array_pointer[i].unk18);
            chunk_array_pointer[i].unk1C = func_80630890(chunk_array_pointer[i].unk1C, arg0, arg1, arg2, &chunk_array_pointer[i].unk20);
        }
    }
}

void func_8065297C(void) {
    s32 i;

    for (i = 0; i < D_807F6C28; i++) {
        func_806323C0(chunk_array_pointer[i].unk14);
        func_806323C0(chunk_array_pointer[i].unk1C);
    }
}

void func_80652A08(f32 arg0, f32 arg1, f32 arg2, u8 arg3) {
    s32 i;

    for (i = 0; i < D_807F6C28; i++) {
        if (chunk_array_pointer[i].loaded == 1 || (arg3 != 0)) {
            if (chunk_array_pointer[i].unk6 != 0) {
                chunk_array_pointer[i].unk24 = 0;
            } else {
                chunk_array_pointer[i].unk24 = func_8063A38C(chunk_array_pointer[i].unk14, chunk_array_pointer[i].unk1C, arg0, arg1, arg2);
            }
        }
    }
}

void func_80652B04(void) {
    s32 i;
    u8 phi_s2;
    Chunk14 *current;
    Chunk14 *next;

    D_807F7140 = 0;
    for (i = 0; i < D_807F6C28; i++) {
        phi_s2 = chunk_array_pointer[i].unk1 != 0 ? TRUE : FALSE;
        current = chunk_array_pointer[i].unk14;
        while (current) {
            next = current->next;
            func_8063B4C0(current, phi_s2);
            current = next;
        }
    }
}

u8 func_80652BC8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    Chunk14 *phi_s0;
    s16 temp_f8;
    s16 temp_f16;
    u8 phi_s1;
    u8 sp6E;
    s32 i;

    phi_s1 = 0;
    sp6E = func_80630324(1, 0);
    temp_f8 = arg1 * 6.0f;
    temp_f16 = arg2 * 6.0f;
    for (i = 0; i < D_807F6C28; i++) {
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
                        phi_s1 |= func_80668E9C(arg0, phi_s0->unk1E, arg1, arg2, arg3, arg4);
                    }
                    phi_s0 = phi_s0->next;
                }
            }
        }
    }
    return phi_s1;
}

// Doable, but surprisingly fiddly
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80652DB4.s")

u8 func_80652E58(s16 arg0) {
    if (D_807F6C28 == 0) {
        return 0xFF;
    }
    return chunk_array_pointer[arg0].unk1 ? TRUE : FALSE;
}

u8 func_80652EBC(s16 arg0) {
    if (D_807F6C28 == 0) {
        return 0xFF;
    }
    return chunk_array_pointer[arg0].loaded == 1 ? TRUE : FALSE;
}

u8 func_80652F24(s16 arg0, s16 arg1) {
    if (D_807F6C28 == 0) {
        return TRUE;
    }
    return (chunk_array_pointer[arg1].unk1 & (1 << arg0)) ? TRUE : FALSE;
}

s16 func_80652F9C(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    s16 sp26;
    func_80652FDC(arg0, arg1, arg2, arg3, -1, &sp26);
    return sp26;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80652FDC.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct807F70B4;

extern s32 D_807F70AC;
extern Struct807F70B4 *D_807F70B4;

/*
// TODO: Fiddly, progress made
void func_80652FDC(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4, s16 *arg5) {
    s32 i;
    Struct807F70B4 *temp_v0_2;
    s16 temp_v1;

    for (i = 0; i < D_807F70AC; i++) {
        if ((arg3 == D_807F70B0[i].unk0) && (arg4 == D_807F70B0[i].unk4)) {
            temp_v1 = D_807F70B0[i].unk2;
            temp_v0_2 = &D_807F70B4[temp_v1];
            if ((temp_v0_2->unk0 <= arg0) && (arg0 <= temp_v0_2->unk6) && (temp_v0_2->unk2 <= arg1) && (arg1 <= temp_v0_2->unk8) && (temp_v0_2->unk4 <= arg2) && (arg2 <= temp_v0_2->unkA)) {
                *arg5 = temp_v1;
                func_80652FDC(arg0, arg1, arg2, arg3, temp_v1, arg5);
            }
        }
    }
}
*/

// TODO: Struct (or struct array?) on the stack?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806531B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806533C4.s")

/*
// TODO: Stupidly close, v0/v1 mixup in the final return
s32 func_806533C4(f32 arg0, f32 arg1, f32 arg2) {
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
    return phi_f0 < phi_f2 ? FALSE : TRUE;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806534E0.s")

s32 func_80653684(Chunk78_7C*, f32, f32);
s32 func_80653804(Chunk78_7C*, f32, f32);

/*
// TODO: Very close
s32 func_806534E0(f32 arg0, f32 arg1, f32 arg2, s16 chunkIndex, s8 *arg4, f32 *arg5) {
    Chunk* chunk = &chunk_array_pointer[chunkIndex];
    Chunk78_7C *phi_s0;

    if (arg0 < chunk->unk80) {
        return FALSE;
    }
    if (arg2 < chunk->unk82) {
        return FALSE;
    }
    if (chunk->unk84 < arg0) {
        return FALSE;
    }
    if (chunk->unk86 < arg2) {
        return FALSE;
    }
    phi_s0 = chunk->unk78;
    while (phi_s0 != chunk->unk7C) {
        if (func_80653684(phi_s0, arg0, arg2) && func_80653804(phi_s0, arg0, arg2)) {
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
*/

// TODO: Can this be cleaned up any more?
s32 func_80653684(Chunk78_7C *arg0, f32 arg1, f32 arg2) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80653804.s")

/*
// TODO: WIP, needs a lot of TLC
s32 func_80653804(Chunk78_7C *arg0, f32 arg1, f32 arg2) {
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

void func_80653A70(s16 chunkIndex) {
    chunk_array_pointer[chunkIndex].loaded = 1;
    chunk_array_pointer[chunkIndex].unk1 |= 1 << cc_player_index;
    chunk_array_pointer[chunkIndex].deload1 = character_change_array[cc_player_index].unk270;
    chunk_array_pointer[chunkIndex].deload2 = character_change_array[cc_player_index].unk272;
    chunk_array_pointer[chunkIndex].deload3 = character_change_array[cc_player_index].unk274;
    chunk_array_pointer[chunkIndex].deload4 = character_change_array[cc_player_index].unk276;
}

void func_80653B70(u8 arg0) {
    D_807F70AB = arg0;
}

void func_8062A944(f32, f32, f32);
void func_8062AC68(void *);
void func_8062AD28(f32, f32, f32, void *, void *);
void func_806521F8();
s16 func_806531B8(f32 arg0, f32 arg1, f32 arg2, s16 arg3);
void func_80654380(f32, f32, f32);
void func_806547A8(f32, f32, f32);
void func_80655410(f32, f32, f32);
void func_80656F14(s16, s32, s16, s16, s32, s32, f32, f32, f32);
void func_8065F678(f32, f32, f32, u8);
void func_8066308C(f32, f32, f32);
extern u8 D_807444FC;
extern s32 D_807F5E20; // TODO: Datatype
extern s32 D_807F5E68; // TODO: Datatype
extern f32 D_807F5FB0;
extern s32 D_807F6C80;
extern u8 D_807F70AB;
extern s16 D_807F7138;
extern f32 D_807F5FB4;

void func_80653B80(f32 arg0, f32 arg1, f32 arg2) {
    character_change_array[cc_player_index].chunk = func_806531B8(arg0, arg1, arg2, character_change_array[cc_player_index].chunk);
    if (D_807F70AB != 0) {
        character_change_array[cc_player_index].chunk = character_change_array[cc_player_index].player_pointer->unk12C;
    }
    func_80663C60(&character_change_array[cc_player_index].far, character_change_array[cc_player_index].chunk);
    D_807F7138 = character_change_array[cc_player_index].far;
    func_8062A944(D_807F5FB4, D_807F5FB0, D_807F7138);
    func_8062AC68(&character_change_array[cc_player_index].unk8[D_807444FC]);
    func_8062AD28(arg0, arg1, arg2, &D_807F5E68, &D_807F5E20);
    func_806521F8();
    func_80653A70(character_change_array[cc_player_index].chunk);
    func_806547A8(arg0, arg1, arg2);
    D_807F6C80 = 0;
    D_807F6C08 = 0;
    func_80656F14(
        character_change_array[cc_player_index].chunk,
        0,
        character_change_array[cc_player_index].unk270,
        character_change_array[cc_player_index].unk272,
        character_change_array[cc_player_index].unk274,
        character_change_array[cc_player_index].unk276,
        arg0,
        arg1,
        arg2);
    func_80654380(arg0, arg1, arg2);
    func_8065F678(arg0, arg1, arg2, cc_player_index);
    func_8066308C(arg0, arg1, arg2);
    func_80655410(arg0, arg1, arg2);
}

// Loops over a DL and replaces texture indices with RDRAM pointers for G_SETTIMG commands
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80653DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80653EA8.s")

void func_80653F68(s16 index) {
    chunk_array_pointer[index].unk7 |= 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80653FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806545D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806547A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80654FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80655258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80655410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80655AD0.s")

void func_80655BF0(void) {
    Chunk14 *current;

    if (func_80652E58(D_807F70AA) == 0) {
        current = chunk_array_pointer[D_807F70AA].unk14;
        while (current) {
            func_80636164(current->unk0, current->unk24);
            func_80636210(current->unk0, current->unk24);
            current = current->next;
        }
        current = chunk_array_pointer[D_807F70AA].unk1C;
        while (current) {
            func_80636164(current->unk0, current->unk24);
            func_80636210(current->unk0, current->unk24);
            current = current->next;
        }
    }
    D_807F70AA++;
    if (D_807F6C28 == (D_807F70AA)) {
        D_807F70AA = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80655CF8.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80655DD0.s")

// Displaylist stuff, chunks
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80656B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80656E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80656F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806574B8.s")

extern u8 D_807F7060[];
extern u8 D_807F7070;

// TODO: Close
/*
s32 func_806574B8(s32 arg0) {
    s32 i;

    for (i = 0; i < D_807F7070; i++) {
        if (D_807F7060[i] == arg0) {
            return 0;
        }
    }
    return 1;
}
*/

void func_80657508(s32 arg0) {
    s32 i;

    for (i = 0; i < D_807F6C08; i++) {
        if (D_807F6BF0[i] == arg0) {
            return;
        }
    }
    if (i != 0xC) {
        D_807F6BF0[D_807F6C08] = arg0;
        D_807F6C08++;
    }
}

void func_8065756C(s16 arg0) {
    s32 i;

    for (i = 0; i < D_807F6C80; i++) {
        if (D_807F6C58[i] == arg0) {
            return;
        }
    }
    D_807F6C58[D_807F6C80++] = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806575D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_8065776C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80657974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80657CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80657E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80657F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_806582F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_8065850C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658624.s")

void func_806588E0(s32 fileIndex) {
    void *file = getPointerTableFile(0x14, fileIndex, 1, 1);
    func_80658930(file);
    if (file) {
        func_8066B434(file, 0xBED, 0x22);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658DAC.s")

void func_80658E58(u16 arg0, u16 arg1, u16 arg2, u16 arg3) {
    D_807F7358 = arg0;
    D_807F735A = arg1;
    D_807F735C = arg2;
    D_807F735E = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_55B20/func_80658E8C.s")
