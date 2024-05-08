#include <ultra64.h>
#include "functions.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    void *unk4;
    void *unk8;
    u8 unkC[0x810 - 0xC];
    u8 unk810[1]; // TODO: How many elements?
} AAD_critter_8002904C;

// PTR TABLE 0x13
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Struct8002A1C0;

extern Struct8002A1C0 *D_critter_8002A1C0;
extern Actor *D_critter_8002A1C4;
extern void* D_critter_8002A1C8[];
extern u16 D_critter_8002A1CE;
extern u16 D_critter_8002A1CC;

Gfx *func_critter_80028DE8(Gfx *dl, Actor *arg1);
Gfx *func_critter_80028A9C(Gfx *dl, void *arg1, void *arg2, u8 arg3);
void *func_dk64_boot_80002DE4(void*, char*);

void func_critter_80028840() {
    D_critter_8002A1C0 = getPointerTableFile(0x13, 4, 1, 1);
    D_critter_8002A1C8[0] = getPointerTableFile(0x13, 5, 1, 1);
    D_critter_8002A1C4 = NULL;
    D_critter_8002A1CE = 0;
    D_critter_8002A1CC = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_4840/func_critter_800288A8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_4840/func_critter_80028A9C.s")

Gfx *func_critter_80028DE8(Gfx *dl, Actor *arg1) {
    void *var_a2;
    u8 i;
    AAD_critter_8002904C *aaD;
    char sp38[7 * 4];

    aaD = arg1->additional_actor_data;
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    strcpy(sp38, &aaD->unk810[0x10]);
    i = 0;
    dl = func_critter_80028A9C(dl, aaD, func_dk64_boot_80002DE4(sp38, " "), i++);
    while (var_a2 = func_dk64_boot_80002DE4(NULL, " ")) {
        dl = func_critter_80028A9C(dl, aaD, var_a2, i++);
    }
    return dl;
}

// TODO: Very close
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_4840/func_critter_80028EE8.s")

s32 func_critter_800288A8(void *, s32, s16); // extern
extern s16 D_global_asm_80744490;

/*
void func_critter_80028EE8(u8 arg0, s32 arg1, s16 arg2, u8 arg3, u16 arg5) {
    AAD_critter_8002904C *aaD;
    s16 sp2A;
    s16 i;

    sp2A = (D_global_asm_80744490 - getCenterOfString(arg0, &D_critter_8002A1C0[arg3])) * 2;
    if (D_critter_8002A1C4 != NULL) {
        aaD = D_critter_8002A1C4->additional_actor_data;
        free(aaD->unk8);
        free(aaD->unk4);
    } else {
        spawnActor(ACTOR_DK_RAP_CONTROLLER, 0);
        aaD = last_spawned_actor->additional_actor_data;
        aaD->unk0 = arg2 * 4;
        D_critter_8002A1C4 = last_spawned_actor;
        D_critter_8002A1C4->unkEC = 0;
    }
    D_critter_8002A1C4->x_position = func_critter_800288A8(aaD, &D_critter_8002A1C0[arg3], sp2A);
    D_critter_8002A1C4->unkEE = 0;
    D_critter_8002A1C4->unk168 = arg5 + 0xE;
    strcpy(&aaD->unk810[0x10], &D_critter_8002A1C0[arg3]);
    for (i = 1; i < 0x10; i++) {
        aaD->unk810[i] = 0;
    }
    aaD->unk810[0] = 0xC;
}
*/

// close
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_4840/func_critter_8002904C.s")

/*
void func_critter_8002904C(void) {
    AAD_critter_8002904C *aaD;
    s32 temp;
    aaD = current_actor_pointer->additional_actor_data;
    if (D_critter_8002A1CC < 0xF0) {
        if (D_critter_8002A1CE >= *((u16*)D_critter_8002A1C8[D_critter_8002A1CC])) {
            D_critter_8002A1CC++;
            aaD->unk810[++current_actor_pointer->unkEE] = 0xC;
        }
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
        addActorToTextOverlayRenderArray(&func_critter_80028DE8, current_actor_pointer, 3);
    }
    D_critter_8002A1CE++;
}
*/
