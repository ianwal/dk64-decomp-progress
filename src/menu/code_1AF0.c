#include <ultra64.h>
#include "functions.h"

typedef struct menu_struct_1 {
    u32 unk0;
    s16 unk4;
    u16 unk6;
    u16 unk8;
    u8  unkA;
    s8  unkB;
    union {
        struct {
            u8  unkC;
            u8  unkD;
        };
        s16 unkC_s16;
    };
    union {
        struct {
            u8  unkE;
            u8  unkF;
        };
        s16 unkE_s16;
    };
    u8  unk10;
    u8  unk11;
    u8  unk12;
} MenuStruct1;

typedef struct {
    s16 unk0; // TODO: Is this an array[4]?
    s16 unk2;
    s16 unk4;
    s16 unk6;
} MenuStruct80033A50;

const MenuStruct80033A50 D_menu_80033A50[] = {
    {0x0000, 0x000B, 0x000F, 0x0014}, // Donkey
    {0x0000, 0x000C, 0x0010, 0x0015}, // Diddy
    {0x0000, 0x000E, 0x0013, 0x0016}, // Lanky
    {0x0000, 0x000D, 0x0011, 0x0017}, // Tiny
    {0x0000, 0x000D, 0x0012, 0x0018}, // Chunky
    {0x0000, 0x0019, 0x001A, 0x001B}, // Krusha
};

extern u8 D_menu_800334DC[];

void func_menu_80025FB4(MenuStruct1*, CharacterProgress*, s32);
void func_menu_80026B28(MenuStruct1*, CharacterProgress*, s32);
void func_menu_80026DAC(MenuStruct1*, CharacterProgress*, s32);

s32 func_menu_80025AF0(MenuStruct1 *arg0, s32 characterIndex) {
    s32 phi_v1;
    s32 phi_v0;

    phi_v1 = 0;
    for (phi_v0 = 0; !phi_v1 && phi_v0 < 5; phi_v0++) {
        if (phi_v0 != current_character_index[0]) {
            phi_v1 |= D_global_asm_807FC950[0].character_progress_as_bytes[phi_v0][arg0->unkB] & (1 << (characterIndex + 0x1F));
        }
    }
    return phi_v1;
}

typedef struct {
    u8 unk0[0xD - 0x0];
    u8 unkD;
    u8 unkE;
} A178_menu_80025B64;

Gfx *func_menu_80025B64(Gfx *dl, Actor *arg1) {
    s32 pad2;
    s32 pad[8];
    A178_menu_80025B64 *a178;
    char sp4C[4]; // TODO: Proper size

    a178 = arg1->unk178;
    if (a178->unkD == 1) {
        gSPDisplayList(dl++, &D_1000118);
        gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gDPPipeSync(dl++);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM)
        switch (a178->unkE) {
            case 1:
                arg1->unk15F = 0;
                a178->unkE = 5;
                // fallthrough
            case 5:
                arg1->unk15F += MIN(8, 0xFF - arg1->unk15F);
                gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1->unk15F);
                sprintf(sp4C, "q %s", getTextString(0x24, 0x10, 1));
                dl = printStyledText(dl, 1, 500, 400, sp4C, 1);
                sprintf(sp4C, "b %s", getTextString(0x24, 0x11, 1));
                dl = printStyledText(dl, 1, 500, 500, sp4C, 1);
                break;
        }
    }
    return dl;
}

void func_menu_80025D14(MenuStruct1 *arg0, s32 arg1) {
    D_global_asm_807FC950[0].character_progress_as_bytes[arg1][arg0->unkB] = arg0->unk11;
}

void func_menu_80025D44(MenuStruct1 *arg0, s32 arg1) {
    D_global_asm_807FC950[0].character_progress_as_bytes[arg1][arg0->unkB] |= 1 << (arg0->unk11 + 0x1F);
}

void func_menu_80025D8C(MenuStruct1 *arg0, u8 arg1) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arg1) {
            func_menu_80025D44(arg0, i);
        } else {
            func_menu_80025D14(arg0, i);
        }
    }
}

void func_menu_80025E04(MenuStruct1 *arg0, CharacterProgress *arg1) {
    s16 sp1E;
    u8 sp1D;

    sp1E = -1;
    sp1D = func_global_asm_806F6E58(current_character_index[0]);
    switch (arg0->unkB) {
        case 2:
        case 4:
            if (arg0->unk11 >= 2) {
                func_menu_80025D8C(arg0, 1);
            } else {
                func_menu_80025D44(arg0, current_character_index[0]);
            }
            break;
        case 1:
        case 3:
            func_menu_80025D8C(arg0, 0);
            break;
        default:
            func_menu_80025D14(arg0, current_character_index[0]);
            break;
    }

    if (arg0->unkB == 4) {
        if (D_global_asm_807FC950[0].melons < D_menu_800334DC[arg0->unk11]) {
            D_global_asm_807FC950[0].melons = D_menu_800334DC[arg0->unk11];
            func_global_asm_80709464(0);
            character_change_array->unk2DC.unk6 |= 0x11;
        }
    }

    switch (arg0->unkB) {
        case 2:
        case 3:
            sp1E = 2;
            break;
        case 4:
            sp1E = 7;
            break;
        case 0:
            if ((sp1D == 0) && (func_global_asm_806F6E58(current_character_index[0]))) {
                sp1E = 5;
            }
            break;
    }
    changeCollectableCount(1, 0, -arg0->unk4);
    if (sp1E >= 0) {
        changeCollectableCount(sp1E, 0, 9999);
    }
    func_global_asm_8060DEC8(); // saveTheGame()
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_menu_80025FB4.s")

typedef struct PurchaseStruct {
    s16 purchase_type;
    s16 purchase_value;
    s16 price;
} PurchaseStruct;

typedef enum PurchaseTypes {
    /* 0x000 */ PURCHASE_TYPE_SPECIAL,
    /* 0x001 */ PURCHASE_TYPE_SLAM,
    /* 0x002 */ PURCHASE_TYPE_GUN,
    /* 0x003 */ PURCHASE_TYPE_AMMOBELT,
    /* 0x004 */ PURCHASE_TYPE_INSTRUMENT
} PurchaseTypes;

extern u8 D_807FCC4C;
extern PurchaseStruct D_menu_80033260[5][7];
extern PurchaseStruct D_menu_80033334[5][7];
extern PurchaseStruct D_menu_80033408[5][7];
extern u16 D_global_asm_80750AC8;

/*
void func_menu_80025FB4(MenuStruct1 *arg0, CharacterProgress *arg1, s32 arg2) {
    PurchaseStruct (*var_v1)[5][7];
    s16 p_type;
    s32 i;
    s32 latest_level_entered;
    s32 found_purchase;
    PurchaseStruct *var_a1;
    PurchaseStruct *default_purchase; // sp2C

    found_purchase = FALSE;
    latest_level_entered = 6;
    while (latest_level_entered >= 0 && !isFlagSet(latest_level_entered + PERMFLAG_LEVEL_ENTERED_JAPES, FLAG_TYPE_PERMANENT)) {
        latest_level_entered--;
    }
    latest_level_entered++;
    arg0->unkC = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    i = 0;
    switch (gCurrentActorPointer->unk58) {
        default:
            var_v1 = default_purchase;
            break;
        case ACTOR_CRANKY: // Cranky
            var_v1 = &D_menu_80033260;
            break;
        case ACTOR_CANDY: // Candy
            var_v1 = &D_menu_80033334;
            break;
        case ACTOR_FUNKY: // Funky
            var_v1 = &D_menu_80033408;
            break;
    }
    var_a1 = &var_v1[current_character_index[0]][i];
    while ((latest_level_entered > i) && (!found_purchase)) {
        p_type = var_a1->purchase_type;
        if (p_type >= 0) {
            if ((p_type == PURCHASE_TYPE_GUN) || (p_type == PURCHASE_TYPE_INSTRUMENT)) {
                if (!((1 << (var_a1->purchase_value - 1)) & *((u8*)&arg1 + p_type))) {
                    found_purchase = TRUE;
                }
            } else if (*((u8*)&arg1 + p_type) < var_a1->purchase_value) {
                found_purchase = TRUE;
            }
            if (found_purchase) {
                arg0->unkB = p_type;
                D_global_asm_80750AC8 = arg0->unk4 = var_a1->price;
                arg0->unk11 = var_a1->purchase_value;
            }
        }
        var_a1++;
        i++;
    }
    if (!found_purchase) {
        arg0->unk4 = 0;
        arg0->unkB = -1;
        D_global_asm_80750AC8 = arg0->unk4;
        if (latest_level_entered > 6) {
            arg0->unkB = -2;
        }
    }
    arg0->unk10 = D_807FCC4C;
}
*/

s32 func_menu_800261C0(MenuStruct1 *arg0, s32 arg1) {
    s32 ret = 0;
    arg0->unkF = 3;
    if (arg0->unkB >= 0) {
        if (func_global_asm_806F8AD4(1, 0) >= arg0->unk4) {
            ret = 2;
            arg0->unkF = 1;
        } else {
            ret = 3;
        }
    } else if (arg0->unkB == -2) {
        ret = 1;
    }
    if (arg0->unkA != 0) {
        ret += 4;
    }
    return ret;
}

int func_menu_80026250(MenuStruct1 *arg0) {
    // TODO: ACTOR_CRANKY?
    return (gCurrentActorPointer->unk58 == 0xBD) &&
            (arg0->unkA == 0) &&
            (arg0->unkB < 0);
}

void func_menu_80026290(MenuStruct1 *arg0, u32 *arg1) {
    *arg1 = 0;
    arg0->unkF = 1;
    arg0->unkB = -1;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_menu_800262A8.s")

extern MenuStruct1 D_menu_800334EC;
extern MenuStruct1 D_menu_80033500;
extern MenuStruct1 D_menu_80033514;
extern u16 D_menu_80033528;

extern u8 D_menu_800334DD[];

void func_menu_800262A8(MenuStruct1*, CharacterProgress*, s32);

/*
void func_menu_800262A8(MenuStruct1 *arg0, CharacterProgress *arg1, s32 arg2) {
    MenuStruct1 *sp44;
    u16 sp42;
    s32 sp3C;
    u16 var_v1;
    u16 var_a2;
    u16 var_t0;
    u16 var_t1;
    u16 sp2C;
    s32 sp28;
    s16 var_a0;
    s32 temp_v0_2;

    if (func_global_asm_80629148()) {
        sp44 = NULL;
        sp3C = func_menu_800261C0(arg0, arg2);
        func_global_asm_80629174();
        arg0->unk12 = 0;
        arg0->unkE++;
        switch (gCurrentActorPointer->unk58) {
            case ACTOR_CANDY: // Candy
                var_v1 = 3;
                var_a2 = 7;
                var_t0 = 0xC;
                var_t1 = 0xE;
                if (arg0->unkB >= 0) {
                    temp_v0_2 = func_menu_80025AF0(arg0, 1);
                    if (((u8*)arg1)[arg0->unkB] & 1) {
                        var_a2 = 9;
                        var_v1 = 5;
                        if (D_807FCC4C < D_menu_800334DD[((u8*)arg1)[arg0->unkB]]) {
                            var_v1 = 6;
                            var_t0 = 0xD;
                            var_t1 = 0xF;
                            arg0->unk12 = 1;
                        } else {
                            var_a2 = 8;
                        }
                    } else if (temp_v0_2 == 0) {
                        var_v1 = 4;
                    }
                }
                D_menu_80033500.unk4 = var_v1;
                D_menu_80033500.unk6 = var_a2;
                D_menu_80033500.unkC_s16 = var_t0;
                D_menu_80033500.unkE_s16 = var_t1;
                sp44 = &D_menu_80033500;
                sp42 = 9;
                break;
            case ACTOR_CRANKY: // Cranky
                arg2 = 0;
                sp2C = D_global_asm_80750AC8;
                var_v1 = 0;
                sp3C = func_menu_800261C0(arg0, 0);
                if ((sp3C == 0) || (sp3C == 1)) {
                    sp3C = 0;
                    sp2C = 0xF;
                }
                sp42 = 8;
                sp44 = &D_menu_800334EC;
                if (arg0->unkA == 0) {
                    if (isFlagSet(TEMPFLAG_JETPAC_IN_STORY_MODE, FLAG_TYPE_TEMPORARY)) {
                        setFlag(TEMPFLAG_JETPAC_IN_STORY_MODE, FALSE, FLAG_TYPE_TEMPORARY);
                        func_menu_80026290(arg0, &sp3C);
                        if (isFlagSet(PERMFLAG_ITEM_RAREWARE_COIN, FLAG_TYPE_PERMANENT) != 0) {
                            var_v1 = 0x20;
                        } else if (isFlagSet(TEMPFLAG_RAREWARE_COIN_SPAWN_PENDING, FLAG_TYPE_TEMPORARY)) {
                            setFlag(TEMPFLAG_RAREWARE_COIN_SPAWN_PENDING, FALSE, FLAG_TYPE_TEMPORARY);
                            var_v1 = 0x22;
                        } else {
                            var_v1 = 0x21;
                        }
                    } else {
                        sp28 = countSetFlags(PERMFLAG_ITEM_MEDAL_JAPES_DK, 0x28, FLAG_TYPE_PERMANENT);
                        if (sp28 >= 0xF) {
                            func_menu_80026290(arg0, &sp3C);
                            if (isFlagSet(PERMFLAG_ITEM_RAREWARE_COIN, FLAG_TYPE_PERMANENT)) {
                                var_v1 = 0x20;
                            } else {
                                var_v1 = 2;
                                sp2C = sp28;
                            }
                        }
                    }
                }
                D_global_asm_80750AC8 = sp2C;
                D_menu_800334EC.unk0 = var_v1;
                break;
            case ACTOR_FUNKY: // Funky
                sp44 = &D_menu_80033514;
                var_v1 = 3;
                if (arg0->unkB == 3) {
                    sp44 = &D_menu_80033528;
                } else {
                    var_a0 = 4;
                    if ((arg0->unkB >= 0) && (((u8*)arg1)[arg0->unkB] & 1)) {
                        var_v1 = 5;
                        var_a0 = 6;
                    }
                    D_menu_80033514.unk4 = var_v1;
                    D_menu_80033514.unk6 = var_a0;
                }
                sp42 = 7;
                break;
        }
        if (arg2 != 0) {
            loadText(gCurrentActorPointer, sp42, sp44[0].unk11);
        }
        loadText(gCurrentActorPointer, sp42, sp44[sp3C].unk11);
        if ((sp3C == 2) || (sp3C == 3) || (sp3C == 6) || (sp3C == 7)) {
            func_global_asm_806F833C(0);
            func_global_asm_806F8BC4(1, 1, 0);
            func_global_asm_806F8BC4(0xE, 1, 0);
        }
    }
}
*/

void func_menu_80026684(MenuStruct1 *arg0, CharacterProgress *arg1, s32 arg2) {
    switch (arg0->unkE) {
        case 0:
            func_menu_800262A8(arg0, arg1, arg2);
            return;
        case 1:
            // TODO: Proper bitfield syntax
            if ((s32)(gCurrentActorPointer->object_properties_bitfield << 6) >= 0) {
                arg0->unkE = 0;
                arg0->unkD = arg0->unkF;
                func_global_asm_8061CB08();
            }
            return;
    }
}

s32 func_menu_800266F0(MenuStruct1 *arg0, CharacterProgress *arg1, s32 flagIndex) {
    s32 temp_a2 = !isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
    func_menu_80025FB4(arg0, arg1, temp_a2);
    arg0->unkD = 0;
    arg0->unkE = 0;
    if (!isFlagSet(TEMPFLAG_JETPAC_IN_STORY_MODE, FLAG_TYPE_TEMPORARY)) {
        if (temp_a2) {
            func_global_asm_806F397C(gPlayerPointer, gCurrentActorPointer, 0, 0x1B);
            playCutscene(NULL, 0, 1);
        } else {
            playCutscene(NULL, 4, 1);
            setAction(0x1B, gCurrentActorPointer, 0);
        }
    } else {
        setAction(0x1B, gCurrentActorPointer, 0);
        playCutscene(NULL, 0xB, 1);
    }
    func_global_asm_80629174();
    gCurrentActorPointer->object_properties_bitfield |= 0x10000000;
    return temp_a2;
}

void func_menu_80026804(MenuStruct1 *arg0, CharacterProgress *arg1) {
    arg0->unkA = 1;
    playCutscene(NULL, 0xF, 1);
    func_global_asm_80629174();
    func_menu_80025FB4(arg0, arg1, 0);
    arg0->unkD = 0;
    arg0->unkE = 0;
    setAction(0x1B, gCurrentActorPointer, 0);
}

void func_menu_80026874(MenuStruct1 *arg0, CharacterProgress *arg1) {
    s32 textFileIndex;
    s32 textIndex;
    Actor *player;

    switch (arg0->unkE) {
        case 0:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                arg0->unkE++;
            }
            break;
        case 1:
        case 5:
            addActorToTextOverlayRenderArray(func_menu_80025B64, gCurrentActorPointer, 3);
            break;
        case 10:
            if (func_menu_80026250(arg0) == 0) {
                func_global_asm_806F8D58(1, 0);
                func_global_asm_806F8D58(0xE, 0);
                func_menu_80025E04(arg0, arg1);
                switch (arg0->unkB) {
                    case 0:
                    case 1:
                        setAction(0x52, NULL, 0);
                        global_properties_bitfield &= 0xFFFEFFCF;
                        player = character_change_array->playerPointer;
                        player->object_properties_bitfield |= 0x40000000;
                        break;
                    case 4:
                        spawnActor(ACTOR_PURCHASE_TEXT_OVERLAY, 0);
                        setAction(0x53, NULL, 0);
                        break;
                    case 2:
                    case 3:
                        spawnActor(ACTOR_PURCHASE_TEXT_OVERLAY, 0);
                        playAnimation(character_change_array->playerPointer, 0x85);
                        break;
                }
                playCutscene(character_change_array->playerPointer, 2, 1);
                arg0->unkD = 2;
                arg0->unkE = 0;
            } else {
                playCutscene(NULL, 0xA, 1);
                setFlag(TEMPFLAG_JETPAC_IN_STORY_MODE, TRUE, FLAG_TYPE_TEMPORARY);
                arg0->unkE++;
            }
            break;
        case 15:
            textFileIndex = -1;
            switch (gCurrentActorPointer->unk58) {
                case ACTOR_CRANKY:
                    textFileIndex = 8;
                    if (func_menu_80026250(arg0) != 0) {
                        arg0->unkA = 1;
                        func_menu_80026804(arg0, arg1);
                        return;
                    }
                    textIndex = 0xA;
                    break;
                case ACTOR_CANDY:
                    textFileIndex = 9;
                    textIndex = 0x11;
                    break;
                case ACTOR_FUNKY:
                    textFileIndex = 7;
                    textIndex = 0x10;
                    break;
            }
            func_global_asm_806F8D58(1, 0);
            func_global_asm_806F8D58(0xE, 0);
            playCutscene(character_change_array->playerPointer, 3, 1);
            arg0->unkD = 3;
            arg0->unkE = 0;
            loadText(gCurrentActorPointer, textFileIndex, textIndex);
            break;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_menu_80026B28.s")

extern s16 D_menu_800334E4[];

// Jumptable, very close
// https://decomp.me/scratch/ssEq8
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_menu_80026DAC.s")

/*
void func_menu_80026DAC(MenuStruct1 *arg0, CharacterProgress *arg1, s32 flagIndex) {
    s32 var_a0;
    s32 cutsceneIndex;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 var_v0;
    s32 temp;
    s32 temp2;

    switch (arg0->unkE) {
        case 0:
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                arg0->unkE++;
                setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
            }
            break;
        case 2:
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                var_a0 = -1;
                func_global_asm_8061CB08();
                arg0->unkE = 4;
                switch (gCurrentActorPointer->unk58) {
                case ACTOR_FUNKY:
                    var_a0 = 2;
                    // fallthrough
                case ACTOR_CANDY:
                    if (var_a0 < 0) {
                        var_a0 = 7;
                    }
                    func_global_asm_806F8BC4(var_a0, 0, 0);
                }
            }
            break;
        case 1:
            if (func_global_asm_80629148()) {
                cutsceneIndex = 1;
                sp24 = -1;
                var_v0 = -1;
                func_global_asm_80629174();
                func_global_asm_806CFF9C(gPlayerPointer);
                switch (gCurrentActorPointer->unk58) {
                    case ACTOR_FUNKY:
                        sp2C = 7;
                        sp28 = 0x11;
                        sp24 = 2;
                        var_v0 = 2;
                        // fallthrough
                    case ACTOR_CANDY:
                        if (sp24 < 0) {
                            sp2C = 9;
                            sp28 = 0x10;
                            sp24 = 7;
                            var_v0 = 4;
                        }
                        if ((var_v0 >= 0) && ((u8*)arg1)[var_v0] & 1) {
                            // Problem is here
                            temp = func_global_asm_806F8AD4(sp24, 0);
                            temp2 = func_global_asm_806F8EDC(sp24, 0);
                            if (temp < temp2) {
                                loadText(gCurrentActorPointer, sp2C, sp28);
                                changeCollectableCount(sp24, 0, 999);
                                arg0->unkE = 0;
                                cutsceneIndex = 5;
                            }
                        }
                        break;
                }
                arg0->unkE += 2;
                playCutscene(NULL, cutsceneIndex, 1);
            }
            break;
        case 3:
        case 4:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                func_global_asm_805FF898();
                arg0->unkE = 0xA;
            }
            break;
    }
}
*/

void func_menu_80027028(MenuStruct1 *arg0, CharacterProgress *arg1, s32 flagIndex) {
    s32 flagIsNotSet = !isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
    switch (arg0->unkD) {
        case 0:
            func_menu_80026684(arg0, arg1, flagIsNotSet);
            break;
        case 1:
            func_menu_80026874(arg0, arg1);
            break;
        case 2:
            func_menu_80026B28(arg0, arg1, flagIndex);
            break;
        case 3:
            func_menu_80026DAC(arg0, arg1, flagIndex);
            break;
    }
}

// Jumptable, very close, stack, regalloc
// https://decomp.me/scratch/BWUlC
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_menu_800270E0.s")

typedef struct {
    s32 unk0;
    s16 unk4; // Used
    s16 unk6;
    u8 unk8[0xB - 0x8];
    s8 unkB; // Used
    s8 unkC; // Used
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11; // Used
} A178_800270E0;

/*
void func_menu_800270E0(void) {
    s32 cutsceneIndex;
    s32 count;
    A178_800270E0 *a178;
    s32 i;
    CharacterProgress *characterProgress;
    s32 sp1C;
    s32 var_a3;

    initializeCharacterSpawnerActor();
    if (current_map == MAP_CRANKYS_LAB) {
        a178 = gCurrentActorPointer->unk178;
        characterProgress = &D_global_asm_807FC950->character_progress[current_character_index[0]];
        if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
            if (isFlagSet(PERMFLAG_PROGRESS_GIVEN_FIRST_SLAM, FLAG_TYPE_PERMANENT)) {
                gCurrentActorPointer->control_state_progress = 0;
            } else {
                gCurrentActorPointer->control_state_progress = 0xFF;
            }
        }
        if (gCurrentActorPointer->control_state_progress != 0xFF) {
            sp1C = PERMFLAG_PROGRESS_TRAINING_SPAWNED;
            if (getLevelIndex(D_global_asm_8076A0AB, 0) != 7) {
                sp1C = PERMFLAG_CUTSCENE_CRANKY_FTCS;
            }
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
                var_a3 = 0x26E;
                if (func_menu_800266F0(a178, characterProgress, sp1C)) {
                    var_a3 = 0x26F;
                }
                playActorAnimation(gCurrentActorPointer, var_a3);
            }
            func_menu_80027028(a178, characterProgress, sp1C);
        } else {
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
                a178->unkC = 7;
                if (!isFlagSet(PERMFLAG_PROGRESS_TRAINING_SPAWNED, FLAG_TYPE_PERMANENT)) {
                    playActorAnimation(gCurrentActorPointer, 0x26E);
                    playCutscene(NULL, 5, 1);
                    gCurrentActorPointer->control_state = 0;
                    setFlag(TEMPFLAG_TRAINING_SPAWN_PENDING, TRUE, FLAG_TYPE_TEMPORARY);
                } else {
                    count = 0;
                    for (i = 0; i != 4; i++) {
                        count += isFlagSet(i + PERMFLAG_ITEM_MOVE_DIVING, FLAG_TYPE_PERMANENT) != 0;
                    }
                    if (count != 4) {
                        cutsceneIndex = 0;
                        gCurrentActorPointer->control_state = 3;
                    } else {
                        cutsceneIndex = 6;
                        gCurrentActorPointer->control_state = 4;
                        a178->unkB = 1;
                        a178->unk4 = 0;
                        a178->unk11 = 1;
                        func_menu_80025E04(a178, characterProgress);
                        setFlag(PERMFLAG_PROGRESS_GIVEN_FIRST_SLAM, TRUE, FLAG_TYPE_PERMANENT);
                    }
                    func_global_asm_806F397C(gPlayerPointer, gCurrentActorPointer, 0, 0x1B);
                    playCutscene(NULL, cutsceneIndex, 1);
                    func_global_asm_80629174();
                    playActorAnimation(gCurrentActorPointer, 0x26E);
                }
            }
            switch (gCurrentActorPointer->control_state) {
                case 0:
                    if (func_global_asm_80629148()) {
                        loadText(gCurrentActorPointer, 8, 0x1C);
                        gCurrentActorPointer->control_state = 1;
                    }
                    break;
                case 1:
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_806CFF9C(gPlayerPointer);
                        func_global_asm_80629174();
                        playCutscene(NULL, 1, 1);
                        func_global_asm_805FF898();
                        gCurrentActorPointer->control_state = 2;
                    }
                    break;
                case 3:
                    if (func_global_asm_80629148()) {
                        loadText(gCurrentActorPointer, 8, 0x1D);
                        gCurrentActorPointer->control_state = 1;
                    }
                    break;
                case 4:
                    if (func_global_asm_80629148()) {
                        loadText(gCurrentActorPointer, 8, 0x1E);
                        gCurrentActorPointer->control_state = 5;
                    }
                    break;
                case 5:
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        gCurrentActorPointer->control_state = 6;
                    }
                    break;
                case 6:
                    if (func_global_asm_80629148()) {
                        setAction(0x52, NULL, 0);
                        global_properties_bitfield &= 0xFFFEFFCF;
                        character_change_array->playerPointer->object_properties_bitfield |= 0x40000000;
                        gCurrentActorPointer->control_state = 7;
                        func_global_asm_80629174();
                        playCutscene(character_change_array->playerPointer, 2, 1);
                    }
                    break;
                case 7:
                    if (func_global_asm_80629148()) {
                        global_properties_bitfield |= 0x10030;
                        D_global_asm_80750AC8 = 0xF;
                        loadText(gCurrentActorPointer, 8, 0x1F);
                        gCurrentActorPointer->control_state = 1;
                    }
                    break;
            }
        }
    }
    if (gCurrentActorPointer->object_properties_bitfield & 0x10000000) {
        initializeCharacterSpawnerActor();
        func_global_asm_806BFBF4();
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

s32 func_menu_800275EC(s32 arg0) {
    return arg0 + 0x21F44F;
}

extern void func_global_asm_8063FA48(void*, void*, s32, s32); // Unsure of this, it's just using this addr for a checksum
extern void func_global_asm_8060AC7C(void);

void func_menu_800275FC(void) {
    // Candy Code
    Actor178 *a178;
    CharacterProgress *sp30;
    u8 pad[0xC];
    s32* lim;
    s32 *sp1C;
    Actor *temp_a0;
    s32 var_v1;
    s32* var_v0;

    initializeCharacterSpawnerActor();
    if (current_map == MAP_CANDYS_MUSIC_SHOP) {
        a178 = gCurrentActorPointer->unk178;
        sp30 = &D_global_asm_807FC950->character_progress[*current_character_index];
        if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
            // Anti-tamper
            var_v1 = 0;
            var_v0 = (s32*)&func_global_asm_8060AC7C;
            lim = (s32*)&func_global_asm_8060B110;
            for (; var_v0 < lim; var_v0++) {
                var_v1 += *var_v0;
            }
            if (var_v1 != 0xA1C0EB24) {
                sp1C = func_menu_800275EC((s32)(&func_global_asm_8063FA48) + 0xFFDE0BB1);
                *sp1C = func_menu_800275EC(0x03BE0BB9);
            }
            func_menu_800266F0(a178, sp30, 0x175);
        }
        func_menu_80027028(a178, sp30, 0x175);
    }
    if (gCurrentActorPointer->object_properties_bitfield & 0x10000000) {
        initializeCharacterSpawnerActor();
        func_global_asm_806BFBF4();
    }
    renderActor(gCurrentActorPointer, 0U);
}

void func_menu_80027738(void) {
    MenuStruct1 *a178;
    CharacterProgress *var1;
    initializeCharacterSpawnerActor();

    if (current_map == MAP_FUNKYS_STORE) {
        a178 = gCurrentActorPointer->unk178;
        var1 = &D_global_asm_807FC950[0].character_progress[current_character_index[0]];
        if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
            func_menu_800266F0(a178, var1, 0x176);
        }
        func_menu_80027028(a178, var1, 0x176);
    }
    if ((gCurrentActorPointer->object_properties_bitfield & (0x80000000 >> 3))) {
        initializeCharacterSpawnerActor();
        func_global_asm_806BFBF4();
    }
    renderActor(gCurrentActorPointer, 0);
}

typedef struct {
    s16 unk0;
    s16 unk2; // Text style
} Struct8003353C;

extern Struct8003353C D_menu_8003353C[];

typedef struct {
    s32 unk0[2];
    u8 unk8; // Used
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
    f32 unk10[2][4][4];
} AAD_80027808;

Gfx *func_menu_80027808(Gfx *dl, Actor *arg1) {
    s32 i;
    AAD_80027808 *aaD = arg1->additional_actor_data;

    gSPDisplayList(dl++, &D_1000118);    
    gSPMatrix(dl++, &D_2000180, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    gDPSetCombineLERP(dl++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, aaD->unk8);

    for (i = 0; i < 2; i++) {
        if (aaD->unk0[i] != NULL) {
            gSPMatrix(dl++, &aaD->unk10[i], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            dl = printStyledText(dl, D_menu_8003353C[i].unk2, 0, 0, aaD->unk0[i], 0x80);
            gSPPopMatrix(dl++, G_MTX_MODELVIEW);
        }
    }

    return dl;
}

// matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_1AF0/func_menu_80027988.s")

void func_menu_80027DEC(void) {
    func_menu_80027988();
}
