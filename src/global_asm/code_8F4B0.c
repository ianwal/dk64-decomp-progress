#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_807501E0;
extern u8 D_807FC620;
extern u8 D_807FC621;
extern u8 D_807FC622;

// spawnPersistantActors
void func_8068A7B0(void) {
    func_80677FA8(ACTOR_UNKNOWN_10, 0);
    func_80677FA8(ACTOR_UNKNOWN_11, 0);
    func_80677FA8(ACTOR_LOADING_ZONE_CONTROLLER, 0);
    func_80677FA8(ACTOR_OBJECT_MODEL_2_CONTROLLER, 0);
    func_80677FA8(ACTOR_UNKNOWN_14, 0);
    func_80677FA8(ACTOR_UNKNOWN_15, 0);
}

void func_8068A810(void) {
    func_8072E868();
}

void func_8068A830(void) {
    func_80727678();
    func_80727958();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068A858.s")

// Jumptable, really interesting though, flag checks/sets and story skip
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068ABE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068AD7C.s")

void func_8068B80C(void) {
    D_807FC620 = 1;
}

void func_8068B81C(void) {
    D_807FC621 = 0;
    D_807FC622 = 0;
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
    f32 unk4;
    s16 unk8;
} AAD_8068B830;

void func_8068B830(s16 arg0, s16 arg1, s16 arg2) {
    Actor *sp1C;
    AAD_8068B830 *temp_v0;

    func_8072E7DC(0xC, &sp1C);
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
} AAD_8068B8A4;

void func_8068B8A4(f32 arg0) {
    Actor *sp1C;
    AAD_8068B8A4 *temp_v0;

    func_8072E7DC(0xC, &sp1C);
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
} AAD_8068B8FC;

void func_8068B8FC(void) {
    Actor *sp1C;
    AAD_8068B8FC *temp_v0;

    func_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068B930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068B9B4.s")

extern u8 D_807FBDC4;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068BA2C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068BBF8.s")

typedef struct {
    void *texturePointer; // Texture Pointer (from table 0xE)
    u16 textureIndex; // Texture Index
    u8 unk6;
    u8 unk7;
} Struct807FC690;

extern Struct807FC690 D_807FC690[];

void func_8068C080(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        D_807FC690[i].unk6 = 0;
    }
}

void func_8068C0B4(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if (D_807FC690[i].unk6 != 0) {
            D_807FC690[i].unk6--;
            if (D_807FC690[i].unk6 == 0) {
                func_8066B434(D_807FC690[i].texturePointer, 0x6A, 0x46);
            }
        }
    }
}

// Returns a texture pointer for a given texture index
void *func_8068C12C(u16 textureIndex) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if ((textureIndex == D_807FC690[i].textureIndex) && (D_807FC690[i].unk6 != 0)) {
            D_807FC690[i].unk6 = 2;
            return D_807FC690[i].texturePointer;
        }
    }
    
    for (i = 0; i < 0x20; i++) {
        if (D_807FC690[i].unk6 == 0) {
            D_807FC690[i].texturePointer = getPointerTableFile(0xE, textureIndex, 0, 0);
            D_807FC690[i].unk6 = 2;
            D_807FC690[i].textureIndex = textureIndex;
            return D_807FC690[i].texturePointer;
        }
    }

    D_807FC690[0].unk6 = 2;
    return D_807FC690[0].texturePointer;
}

typedef struct {
    s32 unk0;
    s32 unk4; // Used
    s8 unk8; // Used
    s8 unk9;
    s8 unkA;
    s8 unkB;
} TempCBig;

extern u8 D_807501E0;
extern TempCBig D_807FC630[];

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068C20C.s")

void func_8068C2EC(void) {
    D_807501E0 = 0;
}

void func_8068C2F8(s32 arg0) {
    u8 i;
    for (i = 0; i < D_807501E0; i++) {
        if (arg0 == D_807FC630[i].unk4) {
            D_807FC630[i].unk8 = 8;
        }
    }
}

// TODO: Arg0 is a function pointer
void func_8068C350(s32 arg0, Actor *arg1, u8 arg2) {
    if (D_807501E0 < 8) {
        D_807FC630[D_807501E0].unk0 = arg0;
        D_807FC630[D_807501E0].unk4 = arg1;
        D_807FC630[D_807501E0].unk8 = arg2;
        D_807501E0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068C3A0.s")

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068C5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068D264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068D8C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068D9DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068DAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068DBA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068DC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068E474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_8068E7B4.s")
