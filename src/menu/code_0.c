#include "common.h"

typedef struct menu_struct_0 {
    u8  unk0;
    u8  unk1;
    u8  pad2;
    u8  pad3;
    u8  pad4;
    u8  pad5;
    u8  unk6;
    u8  unk7;
    otherSpriteControl *unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
} MenuStruct0;

extern s16 D_global_asm_80750AC8;

typedef struct {
    s32 unk0[6];
} Struct80032F48;

extern Struct80032F48 D_menu_80032F48[];
extern s32 D_menu_800330A0[];

void func_menu_80024000(MenuStruct80024000 *arg0) {
    s32 temp_v1;

    temp_v1 = D_menu_80032F48[getLevelIndex(D_global_asm_8076A0AB, 0)].unk0[arg0->unk1];
    if (temp_v1 == 0) {
        func_global_asm_8063DA40(D_menu_800330A0[arg0->unk1A], 9);
        arg0->unk0 = 4;
        arg0->unk1 = 0;
        return;
    }
    if (temp_v1 == 4) {
        arg0->unk6 = 1;
    }
    playCutscene(NULL, temp_v1, 1);
    arg0->unk1++;
}

void func_menu_800240BC(MenuStruct0 *arg0) {
    arg0->unk10 = 11.35f;
    arg0->unkC = -6.55f;
    arg0->unk14 = 6.6f;
    arg0->unk6 = 0;
    func_global_asm_80714998(0);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(-1);
    func_global_asm_80714998(0);
    arg0->unk8 = drawSpriteAtPosition(&D_global_asm_80720268, 0.3f, 181.0f, 3.0f, 82.0f);
}

void func_menu_80024154(MenuStruct0 *arg0) {
    otherSpriteControl *sprite = arg0->unk8;

    sprite->xPos += arg0->unkC;
    sprite->zPos += arg0->unk14;
    arg0->unk10 += -1.0f;
    sprite->yPos += arg0->unk10;
    arg0->unk6++;
    if (arg0->unk6 >= 0x16) {
        arg0->unk6 = 0;
        func_global_asm_80715908(arg0->unk8);
        arg0->unk8 = NULL;
    }
}

void func_menu_800241E8(void) {
    func_global_asm_806CFF9C(gPlayerPointer);
    func_global_asm_805FF898();
    playCutscene(NULL, 7, 1);
}

void func_menu_80024224(MenuStruct0 *arg0, s32 arg1) {
    s32 textIndex;
    s32 temp;

    switch (arg0->unk1) {
        case 0:
            if (func_global_asm_80629148()) {
                if (arg1 != 0) {
                    func_global_asm_80629174();
                    loadText(gCurrentActorPointer, 0xB, 0);
                    temp = arg0->unk1A;
                    if (temp == 1) {
                        textIndex = 1;
                    } else if (temp > 1) {
                        textIndex = 2;
                    } else {
                        textIndex = 3;
                    }
                    D_global_asm_80750AC8 = arg0->unk1A;
                    loadText(gCurrentActorPointer, 0xB, textIndex);
                } else {
                    if (arg0->unk1A == 1) {
                        textIndex = 5;
                    } else {
                        textIndex = 6;
                    }
                    D_global_asm_80750AC8 = arg0->unk1A;
                    loadText(gCurrentActorPointer, 0xB, textIndex);
                }
                arg0->unk1++;
            }
            break;
        case 1:
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                arg0->unk1++;
            }
            break;
        case 2:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                if (arg0->unk1A != 0) {
                    playCutscene(NULL, 5, 1);
                    arg0->unk1++;
                } else {
                    arg0->unk0 = 4;
                    arg0->unk1 = 0;
                }
            }
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            if (arg0->unk6 != 0) {
                if (arg0->unk6 == 1) {
                    if (func_global_asm_80629148()) {
                        func_global_asm_80629174();
                        arg0->unk6 = 2;
                    }
                } else {
                    func_menu_80024154(arg0);
                }
            }
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                func_menu_80024000(arg0);
            }
            break;
    }
}

void func_menu_80024418(MenuStruct0 *arg0, s32 textIndex) {
    switch (arg0->unk1) {
        case 0:
            if (func_global_asm_80629148()) {
                loadText(gCurrentActorPointer, 0xB, textIndex);
                arg0->unk1++;
            }
            break;
        case 1:
            // TODO: Use proper bitfield syntax
            if ((s32)gCurrentActorPointer->object_properties_bitfield << 6 >= 0) {
                func_global_asm_8061CB08();
                arg0->unk1++;
            }
            break;
        case 2:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                arg0->unk0 = 4;
                arg0->unk1 = 0;
            }
            break;
    }
}

Gfx *func_menu_800244EC(Gfx *dl, Actor *arg1) {
    // DrawSnidesMenu
    s32 y;
    s32 i;
    SnideAaD180 *snide_aad;
    void *var_s1;
    char sp70[0x20];
    const f32 menu_scale = 0.6f;

    snide_aad = arg1->snide_aad_180;
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    if ((s32) snide_aad->screen >= 4) {
        gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gDPPipeSync(dl++);
        y = 240;
        for (i = 0; i < 8; i++) {
            if ((i + 4) == snide_aad->screen) {
                gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x80);
            }
            dl = printText(dl, 640, y, menu_scale, getTextString(0x2A, i + 3, 1));
            y += 60;
        }
    } else {
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1->unk15F);
        _sprintf(sp70, "q %s", getTextString(0x2A, 0, 1));
        dl = printStyledText(dl, 1, 350, 400, sp70, 1);
        _sprintf(sp70, "b %s", getTextString(0x2A, 1, 1));
        dl = printStyledText(dl, 1, 350, 500, sp70, 1);
        if (snide_aad->minigame_menu_unlocked) {
            _sprintf(sp70, "n %s", getTextString(0x2A, 2, 1));
            dl = printStyledText(dl, 1, 350, 600, sp70, 1);
        }
    }
    return dl;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_80024788.s")

extern s16 D_menu_800330D8;
extern s8 D_menu_80032F50;

typedef struct {
    u8 unk0;
    u8 unk1; // Used
    u8 unk2;
    u8 unk3;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    s8 unk18; // Used
    s8 unk19; // Used
} Struct80024788;

extern u8 D_menu_800330C0[];

/*
void func_menu_80024788(SnideAaD180 *arg0) {
    s32 temp_v0;
    s32 sp40;
    CharacterProgress *sp3C;
    s32 i;
    s32 new_screen;

    sp40 = 0;
    D_menu_800330D8 = 0;
    switch (arg0->screen) {
        case 0x2:
        case 0x37:
            break;
        case 0x0:
            if (func_global_asm_806F70A8(4) != 0) {
                sp3C = &D_global_asm_807FC950->character_progress[*current_character_index];
                for (i = 0; i < 8; i++) {
                    if (isFlagSet(func_global_asm_807319D8(PERMFLAG_ITEM_BLUEPRINT_JAPES_DK, i, *current_character_index), FLAG_TYPE_PERMANENT) != 0) {
                        temp_v0 = func_global_asm_807319D8(PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK, i, *current_character_index);
                        if (isFlagSet(temp_v0, FLAG_TYPE_PERMANENT) == FALSE) {
                            setFlag(temp_v0, TRUE, FLAG_TYPE_PERMANENT);
                            sp3C->golden_bananas[i] += 1;
                            sp40 = 1;
                        }
                    }
                }
                func_global_asm_806F8278(0);
            }
            if (sp40 != 0) {
                // Save the game
                func_global_asm_8060DEC8();
            }
            if (func_global_asm_8061CB50() == 0) {
                arg0->screen++;
                setAction(0x55, NULL, 0);
            }
            break;
        case 0x1:
            // Issue starts here, it's wanting to use sll/subu instead of multu for the offset of 807fd610
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                gCurrentActorPointer->unk15F = 0;
                arg0->screen = 3;
            } else {
                arg0->minigame_menu_unlocked = TRUE;
                for (i = PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK; i < 0x225; i++) {
                    if (!isFlagSet(i, FLAG_TYPE_PERMANENT)) {
                        arg0->minigame_menu_unlocked = FALSE;
                        i = 0x224;
                    }
                }
                gCurrentActorPointer->unk15F += 0xFF - gCurrentActorPointer->unk15F >= 9 ? 8 : 0xFF - gCurrentActorPointer->unk15F;
                addActorToTextOverlayRenderArray(func_menu_800244EC, gCurrentActorPointer, 3);
                if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
                    func_menu_800241E8();
                    arg0->screen = 2;
                } else if ((arg0->minigame_menu_unlocked != 0) && (D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS)) {
                    arg0->screen = 4;
                }
            }
            break;
        case 0x3:
            D_menu_800330D8 = 1;
            if (D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) {
                arg0->screen = 1;
            }
            break;
        default:
            if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
                new_screen = 1;
            } else {
                if ((D_global_asm_807ECDEC->stick_y >= 0x29) && (arg0->previous_y < 0x29)) {
                    arg0->screen--;
                    playSound(0x2A0, 0x7FFF, 64.0f, 1.0f, 0, 0);
                }
                if ((D_global_asm_807ECDEC->stick_y < -0x28) && (arg0->previous_y >= -0x28)) {
                    arg0->screen++;
                    playSound(0x2A0, 0x7FFF, 64.0f, 1.0f, 0, 0);
                }
                new_screen = ((arg0->screen - 4) & 7) + 4;
            }
            arg0->screen = new_screen;
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                func_global_asm_80712774(D_menu_800330C0[new_screen]);
                D_menu_80032F50 = 1;
                arg0->screen = 0x37;
            }
            addActorToTextOverlayRenderArray(func_menu_800244EC, gCurrentActorPointer, 3);
            break;
    }
    arg0->previous_y = D_global_asm_807ECDEC->stick_y;
}
*/

void func_menu_80024BFC(MenuStruct0 *arg0) {
    switch (arg0->unk1) {
        case 0:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                arg0->unk1++;
                D_global_asm_80750AC8 = func_global_asm_80712548();
                loadText(gCurrentActorPointer, 0xB, 8);
            }
            break;
        case 1:
            // TODO: Use proper bitfield syntax
            if (((s32)gCurrentActorPointer->object_properties_bitfield << 6) >= 0) {
                func_global_asm_8061CB08();
                arg0->unk1++;
            }
            break;
    }
}

extern s16 D_global_asm_8076AEF2;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3[0x1A - 0x03];
    u8 unk1A;
} A180_80024CB0;

void func_menu_80024CB0(void) {
    A180_80024CB0 *a180;
    s32 sp28;
    u8 var_v1;
    s32 sp20;

    sp28 = -1;
    var_v1 = 0;
    a180 = gCurrentActorPointer->unk180;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        sp20 = 1;
        sp28 = -1;
        // Count blueprints turned
        a180->unk2 = countSetFlags(PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK, 40, FLAG_TYPE_PERMANENT);
        a180->unk1A = func_global_asm_80731A04(PERMFLAG_ITEM_BLUEPRINT_JAPES_DK, 0, 7, *current_character_index);
        a180->unk1A = a180->unk1A - func_global_asm_80731A04(PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK, 0, 7, *current_character_index);
        if (D_global_asm_8076AEF2 != 0x1C) {
            if (!isFlagSet(PERMFLAG_CUTSCENE_SNIDE_FTCS, FLAG_TYPE_PERMANENT)) {
                a180->unk0 = 0;
                a180->unk1 = 0;
                sp20 = 0;
                func_global_asm_806F397C(gPlayerPointer, 0, 0, 0);
                setFlag(PERMFLAG_CUTSCENE_SNIDE_FTCS, TRUE, FLAG_TYPE_PERMANENT);
            } else {
                if (a180->unk2 == 0x28) {
                    a180->unk0 = 2;
                    a180->unk1 = 0;
                } else if (a180->unk1A == 0) {
                    a180->unk0 = 1;
                    a180->unk1 = 0;
                } else {
                    a180->unk0 = 3;
                    a180->unk1 = 0;
                }
            }
            playCutscene(NULL, sp20, 1);
        } else {
            a180->unk0 = 5;
            a180->unk1 = 0;
        }
        func_global_asm_80629174();
        func_menu_800240BC(a180);
        var_v1 = D_menu_80032F50;
        D_menu_80032F50 = 0;
    }
    switch (a180->unk0) {
        case 0:
            func_menu_80024224(a180, 1);
            break;
        case 3:
            func_menu_80024224(a180, 0);
            break;
        case 1:
            sp28 = 4;
            // fallthrough
        case 2:
            if (sp28 < 0) {
                sp28 = 7;
            }
            if (var_v1 != 0) {
                sp28 = 0xB;
            }
            func_menu_80024418(a180, sp28);
            break;
        case 4:
            func_menu_80024788(a180);
            break;
        case 5:
            func_menu_80024BFC(a180);
            break;
    }
    initializeCharacterSpawnerActor();
    func_global_asm_806BFBF4();
    renderActor(gCurrentActorPointer, 0);
}

// Checks if all blueprints turned in, malloc, gCurrentActorPointer, playSFX
// close
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_80024EF0.s")

typedef struct RGB {
    u8 red;
    u8 green;
    u8 blue;
} RGB;

extern Vtx *D_menu_80033F10;
extern Mtx *D_menu_800330D0;
extern void *D_menu_800330D4;
extern s16 D_menu_800330D8;
extern u8 D_menu_800330E0[0x140]; // Is this the BoM image?
extern s16 D_menu_80033220[];
extern RGB D_menu_80033228[];
extern s8 D_menu_80033258;
Gfx *func_menu_800252AC(Gfx *, Actor *);

/*
void func_menu_80024EF0(void) {
    s32 color_index;
    s32 i, j, k;
    s32 var_s3;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 vtx_i;
    s8 all_bps_turned;
    s16 *var_s0;
    RGB *color_data;

    var_s0 = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        *var_s0 = 0xF0;
        gCurrentActorPointer->control_state = 0;
        D_menu_800330D0 = malloc(2 * sizeof(Mtx));
        D_menu_800330D4 = malloc(0x140);
        memcpy(D_menu_800330D4, &D_menu_800330E0, 0x140U);
        *var_s0 = -1000;
        D_menu_80033F10 = malloc(0x1400);
        all_bps_turned = countSetFlags(PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK, 40, FLAG_TYPE_PERMANENT) == 40;
        var_s7 = 0;
        vtx_i = 0;
        for (i = 0; i != 0x96; i += 0x1E) {
            var_s3 = 0;
            var_s5 = 0x28;
            var_s6 = 0x46;
            for (k = 0x1E; k < 0x10E; k += 0x1E) {
                color_index = var_s7;
                for (j = 0; j < 5; j++) {
                    if (all_bps_turned) {
                        color_index = 0x15;
                    }
                    color_data = &D_menu_80033228[color_index++];
                    D_menu_80033F10[vtx_i].v.ob[0] = var_s5 << 2;
                    D_menu_80033F10[vtx_i].v.ob[1] = (D_menu_80033220[j] + i + 0x2D) << 2;
                    D_menu_80033F10[vtx_i].v.ob[2] = -10;
                    D_menu_80033F10[vtx_i].v.tc[0] = var_s3 << 6;
                    D_menu_80033F10[vtx_i].v.tc[1] = (D_menu_80033220[j] + i) << 6;
                    D_menu_80033F10[vtx_i].v.cn[0] = color_data->red;
                    D_menu_80033F10[vtx_i].v.cn[1] = color_data->green;
                    D_menu_80033F10[vtx_i].v.cn[2] = color_data->blue;
                    D_menu_80033F10[vtx_i].v.cn[3] = 0xFF;
                    D_menu_80033F10[vtx_i].v.flag = 0;
                    vtx_i++;
                    // Might not be needed
                    D_menu_80033F10[vtx_i].v.ob[0] = var_s6 << 2;
                    D_menu_80033F10[vtx_i].v.ob[1] = (D_menu_80033220[j] + i + 0x2D) << 2;
                    D_menu_80033F10[vtx_i].v.ob[2] = 0x16;
                    D_menu_80033F10[vtx_i].v.tc[0] = k << 6;
                    D_menu_80033F10[vtx_i].v.tc[1] = (D_menu_80033220[j] + i) << 6;
                    D_menu_80033F10[vtx_i].v.cn[0] = color_data->red;
                    D_menu_80033F10[vtx_i].v.cn[1] = color_data->green;
                    D_menu_80033F10[vtx_i].v.cn[2] = color_data->blue;
                    D_menu_80033F10[vtx_i].v.cn[3] = 0xFF;
                    D_menu_80033F10[vtx_i].v.flag = 0;
                    vtx_i++;
                }
                // Loop stuff
                var_s3 += 0x1E;
                var_s5 += 0x1E;
                var_s6 += 0x1E;
            }
            var_s7 += 9;
        }
        D_menu_80033258 = all_bps_turned;
    }
    if (D_menu_800330D8 != 0) {
        if (*var_s0 == -1000) {
            playSound(0x2A3, 0x7FFFU, 63.0f, 1.0f, 0, 0);
        }
        *var_s0 += 0x80;
        if (*var_s0 > 0) {
            *var_s0 = 0;
        }
    } else {
        if (*var_s0 == 0) {
            playSound(0x2A3, 0x7FFFU, 63.0f, 1.0f, 0, 0);
        }
        *var_s0 -= 0x80;
        if (*var_s0 < -1000) {
            *var_s0 = -1000;
        }
    }
    D_menu_800330D8 = 0;
    if (*var_s0 >= -0x3E7) {
        addActorToTextOverlayRenderArray(&func_menu_800252AC, gCurrentActorPointer, 3U);
    }
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/menu/code_0/func_menu_800252AC.s")

typedef struct snide_menu_aad_174 {
    f32 unk0;
} snide_menu_aad_174;

extern void *D_menu_800330D4;
extern s8 D_menu_80033258;

/*
Good start, but lots wrong
Gfx *func_menu_800252AC(Gfx *dl, Actor *arg1) {
    void *sp188;
    f32 sp12C[4];
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_s2;
    s32 temp_t6;
    s32 temp_t7;
    s32 var_v0;
    s32 var_fp;
    s32 var_s1;
    s32 var_s4;
    s32 var_v1;
    void *temp_v0_2;
    void *var_s0;
    void *var_s0_2;
    s8 *var_s5;
    snide_menu_aad_174* aad = (snide_menu_aad_174*)arg1->AaaD;
    s8 sp12B;

    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gDPSetRenderMode(dl++, G_RM_NOOP, G_RM_OPA_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA_PRIM2);
    gSPMatrix(dl++, 0x020000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    guTranslateF((f32 (*)[4]) &sp12C[0], 8.0f, aad->unk0, 0.0f);
    guMtxF2L((f32 (*)[4]) &sp12C[0], &D_menu_800330D0[D_global_asm_807444FC]);
    gSPMatrix(dl++, &D_menu_800330D0[D_global_asm_807444FC], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetTextureFilter(dl++, G_TF_POINT);
    sp188 = func_global_asm_8068C12C(0xA3U);
    var_s5 = (s8*)D_menu_80033F10;
    sp12B = 1;
    var_v1 = 0;
    for (var_fp = 0; var_fp < 5; var_fp++, var_v1 += 0x1E) {
        temp_a3 = var_v1 + 0x1E;
        temp_t6 = (var_v1 * 4) & 0xFFF;
        temp_t7 = (temp_a3 * 4) & 0xFFF;
        var_s1 = 0;
        for (var_s4 = 0; var_s4 < 8; var_s4++, var_s5 += 0x80) {
            gDPPipeSync(dl++);
            if (isFlagSet(func_global_asm_807319D8(PERMFLAG_ITEM_GB_JAPES_BLUEPRINT_DK, var_s4, var_fp), 0U) != 0) {
                gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                sp12B = 0;
                gDPSetPrimColor(dl++, 0, 0, 0x00, 0x00, 0x00, 0x00);
            }
            temp_a1 = (((s32) (((s32) ((var_s1 - var_s1) + 0x1F) >> 1) + 7) >> 3) & 0x1FF);
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 120, sp188);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, temp_a1, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
            temp_s2 = var_s1 + 0x1E;
            gDPLoadSync(dl++);
            gDPLoadTile(dl++, 2, (var_s1 * 2) & 0xFFF, temp_t6, (temp_s2 * 2) & 0xFFF, temp_t7);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_4b, temp_a1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(dl++, 2, (var_s1 * 4) & 0xFFF, (var_v1 * 4) & 0xFFF, (temp_s2 * 4) & 0xFFF, temp_t7);
            gSPVertex(dl++, osVirtualToPhysical(var_s5), 8, 0);
            gSP2Triangles(dl++, 0, 1, 2, 0, 1, 3, 2, 0);
            gSP2Triangles(dl++, 2, 3, 4, 0, 3, 5, 4, 0);
            gSP2Triangles(dl++, 4, 5, 6, 0, 5, 7, 6, 0);
        }
    }
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetTextureFilter(dl++, G_TF_BILERP);
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, func_global_asm_8068C12C(0xA2U));
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gDPPipeSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
    gSPVertex(dl++, osVirtualToPhysical(D_menu_800330D4), 20, 0);
    gSP2Triangles(dl++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(dl++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(dl++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(dl++, 12, 13, 14, 0, 12, 14, 15, 0);
    gDPPipeSync(dl++);
    if ((sp12B != 0) && ((u32) (object_timer & 0x1F) < 0x14U)) {
        temp_v0_2 = func_global_asm_8068C12C(0x44U);
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0xFF, 0x00, 0xFF)
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, temp_v0_2);
        gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD);
        gDPLoadSync(dl++);
        gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 2047, 256);
        gDPPipeSync(dl++);
        gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD);
        gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x00FC, 0x00FC);
        gSP2Triangles(dl++, 16, 17, 18, 0, 16, 18, 19, 0);
        var_v0 = 0;
        if (D_menu_80033258 == 0) {
            for (; var_v0 < 0x50; var_v0++) {
                D_menu_80033F10->vertices[(4 * var_v0) + 0].red = 0;
                D_menu_80033F10->vertices[(4 * var_v0) + 0].green = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 0].blue = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 1].red = 0;
                D_menu_80033F10->vertices[(4 * var_v0) + 1].green = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 1].blue = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 2].red = 0;
                D_menu_80033F10->vertices[(4 * var_v0) + 2].green = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 2].blue = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 3].red = 0;
                D_menu_80033F10->vertices[(4 * var_v0) + 3].green = 0xFF;
                D_menu_80033F10->vertices[(4 * var_v0) + 3].blue = 0xFF;
            }
            D_menu_80033258 = 1;
        }
    }
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return dl;
}
*/

void func_menu_80025AE0(void) {

}
