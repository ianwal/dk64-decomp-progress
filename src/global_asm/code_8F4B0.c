#include <ultra64.h>
#include "functions.h"


extern u8 D_global_asm_807501E0;
extern u8 D_global_asm_807FC620;
extern u8 D_global_asm_807FC621;
extern u8 D_global_asm_807FC622;

// spawnPersistantActors
void func_global_asm_8068A7B0(void) {
    func_global_asm_80677FA8(ACTOR_UNKNOWN_10, 0);
    func_global_asm_80677FA8(ACTOR_UNKNOWN_11, 0);
    func_global_asm_80677FA8(ACTOR_LOADING_ZONE_CONTROLLER, 0);
    func_global_asm_80677FA8(ACTOR_OBJECT_MODEL_2_CONTROLLER, 0);
    func_global_asm_80677FA8(ACTOR_UNKNOWN_14, 0);
    func_global_asm_80677FA8(ACTOR_UNKNOWN_15, 0);
}

void func_global_asm_8068A810(void) {
    func_global_asm_8072E868();
}

void func_global_asm_8068A830(void) {
    func_global_asm_80727678();
    func_global_asm_80727958();
}

// Hmm, negative struct offsets
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068A858.s")

// Jumptable, really interesting though, flag checks/sets and story skip
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068ABE0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068AD7C.s")

void func_global_asm_8068B80C(void) {
    D_global_asm_807FC620 = 1;
}

void func_global_asm_8068B81C(void) {
    D_global_asm_807FC621 = 0;
    D_global_asm_807FC622 = 0;
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
    f32 unk4;
    s16 unk8;
} AAD_global_asm_8068B830;

void func_global_asm_8068B830(s16 arg0, s16 arg1, s16 arg2) {
    Actor *sp1C;
    AAD_global_asm_8068B830 *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = (f32)arg1 / 100.0; // TODO: Get rid of this typecast?
    temp_v0->unk8 = arg2;
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s16 unk1C;
    s16 unk1E;
} AAD_global_asm_8068B8A4;

void func_global_asm_8068B8A4(f32 arg0) {
    Actor *sp1C;
    AAD_global_asm_8068B8A4 *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unkC = arg0;
    temp_v0->unk10 = arg0;
    temp_v0->unk14 = arg0;
    if (temp_v0->unk18 == 0) {
        temp_v0->unk1C = 1;
        temp_v0->unk1E = temp_v0->unk1C;
    }
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
} AAD_global_asm_8068B8FC;

void func_global_asm_8068B8FC(void) {
    Actor *sp1C;
    AAD_global_asm_8068B8FC *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = 0xFF;
}

extern u8 D_global_asm_807FBDC4;

void func_global_asm_8068B930(void) {
    Struct807FBB70_unk278 *temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        if (D_global_asm_807FBB70.unk258[i] == 1) {
            func_global_asm_8063DA40(temp_v0->unk0, temp_v0->unk2);
        }
    }
    func_global_asm_8062BAE4();
}

void func_global_asm_8068B9B4(void) {
    Struct807FBB70_unk278 *temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        if (D_global_asm_807FBB70.unk258[i] == 1) {
            func_global_asm_80689A80(temp_v0->unk2, temp_v0);
        }
    }
}

void func_global_asm_8072167C(s16, s16, s16, s16);

// TODO: Probably overlap with an existing aaD
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
    s32 unkAC; // Used
} AAD_global_asm_8068BA2C;

void func_global_asm_8068BA2C(void) {
    s16 i;
    AAD_global_asm_8068BA2C *sp58;
    Struct807FBB70_unk278 *temp_v1;
    u8 var_s3;
    s32 var_v0;
    PlayerAdditionalActorData *temp_s1;

    temp_s1 = D_global_asm_807FBB48->additional_actor_data;
    var_s3 = 0;
    sp58 = temp_s1->unk104->additional_actor_data;
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        temp_v1 = D_global_asm_807FBB70.unk278[i];
        switch (D_global_asm_807FBB70.unk258[i]) {
            case 1:
                if (temp_v1->unk2 != 0) {
                    var_v0 = 4;
                } else {
                    var_v0 = 0;
                }
                playCutscene(NULL, temp_v1->unk0, (var_v0 | 1) & 0xFF);
                break;
            case 2:
                func_global_asm_8072167C(temp_v1->unk0, temp_v1->unk2, temp_v1->unk4, temp_v1->unk6);
                break;
            case 3:
                var_s3 = 1;
                if (!(temp_s1->unk1F0 & 0x04000000)) {
                    temp_s1->unk1F0 |= 0x04000000;
                }
                break;
        }
    }
    if (var_s3 == 0) {
        temp_s1->unk1F0 &= 0xFBFFFFFF;
    }
    if (sp58->unkAC & 1) {
        func_global_asm_8065A708(character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z, character_change_array->look_at_at_x, character_change_array->look_at_at_y, character_change_array->look_at_at_z, 0.0f, 1, 0xFF, 0xFF, 0xFF);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068BBF8.s")

typedef struct {
    void *texturePointer; // Texture Pointer (from table 0xE)
    u16 textureIndex; // Texture Index
    u8 unk6;
    u8 unk7;
} Struct807FC690;

extern Struct807FC690 D_global_asm_807FC690[];

void func_global_asm_8068C080(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        D_global_asm_807FC690[i].unk6 = 0;
    }
}

void func_global_asm_8068C0B4(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FC690[i].unk6 != 0) {
            D_global_asm_807FC690[i].unk6--;
            if (D_global_asm_807FC690[i].unk6 == 0) {
                func_global_asm_8066B434(D_global_asm_807FC690[i].texturePointer, 0x6A, 0x46);
            }
        }
    }
}

// Returns a texture pointer for a given texture index
void *func_global_asm_8068C12C(u16 textureIndex) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if ((textureIndex == D_global_asm_807FC690[i].textureIndex) && (D_global_asm_807FC690[i].unk6 != 0)) {
            D_global_asm_807FC690[i].unk6 = 2;
            return D_global_asm_807FC690[i].texturePointer;
        }
    }
    
    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FC690[i].unk6 == 0) {
            D_global_asm_807FC690[i].texturePointer = getPointerTableFile(0xE, textureIndex, 0, 0);
            D_global_asm_807FC690[i].unk6 = 2;
            D_global_asm_807FC690[i].textureIndex = textureIndex;
            return D_global_asm_807FC690[i].texturePointer;
        }
    }

    D_global_asm_807FC690[0].unk6 = 2;
    return D_global_asm_807FC690[0].texturePointer;
}

typedef struct {
    void *unk0; // TODO: Function pointer
    Actor *unk4; // Used
    s8 unk8; // Used
    s8 unk9;
    s8 unkA;
    s8 unkB;
} TempCBig;

extern u8 D_global_asm_807501E0;
extern TempCBig D_global_asm_807FC630[];

// Displaylist stuff, uses TempCBig
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068C20C.s")

void func_global_asm_8068C2EC(void) {
    D_global_asm_807501E0 = 0;
}

void func_global_asm_8068C2F8(Actor *arg0) {
    u8 i;
    for (i = 0; i < D_global_asm_807501E0; i++) {
        if (arg0 == D_global_asm_807FC630[i].unk4) {
            D_global_asm_807FC630[i].unk8 = 8;
        }
    }
}

// TODO: Arg0 is a function pointer
void func_global_asm_8068C350(void *arg0, Actor *arg1, u8 arg2) {
    if (D_global_asm_807501E0 < 8) {
        D_global_asm_807FC630[D_global_asm_807501E0].unk0 = arg0;
        D_global_asm_807FC630[D_global_asm_807501E0].unk4 = arg1;
        D_global_asm_807FC630[D_global_asm_807501E0].unk8 = arg2;
        D_global_asm_807501E0++;
    }
}

// Displaylist stuff, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068C3A0.s")

void func_global_asm_80612CA0(f32 (*)[4], f32);
extern s32 D_global_asm_807501E8; // TODO: Type

/*
Gfx *func_global_asm_8068C3A0(Gfx *dl, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    f32 spA0[4][4];
    f32 sp60[4][4];
    f32 *sp5C;
    void *padA4;

    sp5C = malloc(0x40);
    func_global_asm_8061134C(sp5C);
    gDPPipeSync(dl++);
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, arg1 + 0x80000000);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gDPPipeSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
    func_global_asm_80612CA0(&spA0[0], arg4);
    guTranslateF(&sp60[0], arg2, arg3, 0.0f);
    guMtxCatF(&spA0[0], &sp60[0], &spA0[0]);
    guMtxF2L(&spA0[0], sp5C);
    gSPMatrix(dl++, sp5C, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPVertex(dl++, osVirtualToPhysical(&D_global_asm_807501E8), 4, 0);
    gSP2Triangles(dl++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSPPopMatrix(dl++, G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    return dl;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068C5A8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068D264.s")

extern Gfx D_1000118;
extern Mtx D_2000080;

void func_global_asm_8068D8C8(Gfx *dl, s32 arg1) {
    gSPDisplayList(dl++, &D_1000118);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xA0);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPMatrix(dl++, &D_2000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    // TODO: What does the object_timer expression do? Any better way to represent it?
    func_global_asm_8068C5A8(dl, ((((u32)object_timer >> 1) & 0xF) + 0x8F), 0, 2, 0x20, 0x20, 0x118, 0xD2, 1.0f, 1.0f, 0, 0.0f);
}

// Displaylist stuff, regalloc, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068D9DC.s")

extern s32 D_global_asm_80759F30;
extern s32 D_global_asm_80759F34;
extern s32 D_global_asm_80759F38;
extern s32 D_global_asm_80759F3C; // TODO: Type
extern s32 D_global_asm_80759F40; // TODO: Type

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 *unk14;
    s32 unk18;
    u8 *unk1C;
} Struct8068D9DC_arg1;

void *func_global_asm_806FC530(void *arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4, u8 arg5);

/*
void func_global_asm_8068D9DC(Gfx *dl, Struct8068D9DC_arg1 *arg1) {
    s32 pad2;
    s32 pad;
    s32 sp3C;
    s32 sp38;

    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x96);

    func_dk64_boot_800031E0(&sp3C, &D_global_asm_80759F30, arg1->unk14);
    dl = func_global_asm_806FC530(func_global_asm_806FC530(dl, 3, 0x424, 0x50, &sp3C, 1), 1, 0x50, 0x50, &D_global_asm_80759F34, 1);
    func_dk64_boot_800031E0(&sp38, &D_global_asm_80759F38, arg1->unk1C);
    func_global_asm_806FC530(dl, 3, 0x50, 0xB0, &sp38, 1);
}
*/

void func_global_asm_8068DAF4(Gfx *dl, u8 *arg1) {
    s32 pad;
    s32 sp38; // TODO: Type

    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x96);

    func_dk64_boot_800031E0(&sp38, &D_global_asm_80759F3C, *arg1);
    func_global_asm_806FC530(dl, 3, 0x104, 0x50, &sp38, 1);
}

// Displaylist stuff, regalloc, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068DBA4.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 *unk14;
} Struct8068DBA4_arg1;

/*
void func_global_asm_8068DBA4(Gfx *dl, Struct8068DBA4_arg1 *arg1) {
    s32 pad2;
    s32 pad;
    s32 sp34;

    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x96);

    func_dk64_boot_800031E0(&sp34, &D_global_asm_80759F40, arg1->unk14);
    func_global_asm_806FC530(dl, 3, 0x370, 0x50, &sp34, 1);
}
*/

// Displaylist stuff, huge
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068DC54.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068E474.s")

extern char D_global_asm_80759F4C[];
extern char D_global_asm_80759F50[];
extern char D_global_asm_80759F54[];

s32 func_global_asm_806FBD5C(s16, void*);

void func_global_asm_8068E7B4(Gfx *dl, f32 arg1, f32 arg2, s32 seconds) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 pad48;
    s32 pad44;
    s32 minutes;
    s32 sp3C;
    s32 sp2C;

    sp50 = arg2 - (func_global_asm_806FD894(0x86) * 0.5f);
    func_dk64_boot_800031E0(&sp3C, &D_global_asm_80759F4C);
    sp4C = func_global_asm_806FBD5C(6, &sp3C) * 0.5f;
    sp54 = arg1 - sp4C;
    sp2C = sp50 * 4.0f;
    minutes = seconds / 60;
    dl = func_global_asm_806FC530(dl, 6, sp54 * 4.0f, sp2C, &sp3C, 1);
    func_dk64_boot_800031E0(&sp3C, &D_global_asm_80759F50, minutes);
    sp54 -= func_global_asm_806FBD5C(0x86, &sp3C);
    dl = func_global_asm_806FC530(dl, 0x86, sp54 * 4.0f, sp2C, &sp3C, 1);
    func_dk64_boot_800031E0(&sp3C, &D_global_asm_80759F54, seconds - (minutes * 60));
    func_global_asm_806FC530(dl, 0x86, (arg1 + sp4C) * 4.0f, sp2C, &sp3C, 1);
}
