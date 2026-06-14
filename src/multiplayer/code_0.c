#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8; // Seconds
} AAD_multiplayer_80024000;

typedef struct {
    u8 unk0[0x2FE - 0x0];
    u16 unk2FE[4]; // TODO: how many?
} Struct800241F4;

typedef struct MultiplayerStruct4 {
    u8 pad0[0x4C];
    u8 unk4C;
} MultiplayerStruct4;

// TODO: Is this a PaaD?
typedef struct MultiplayerStruct0 {
    u8 pad0[0x1A4];
    u8 unk1A4;
} MultiplayerStruct0;

typedef struct {
    OSTime unk0;
    s32 unk8;
    u32 unkC;
} AAD_multiplayer_800243C8;

typedef struct {
    u8 unk0[0x18 - 0x0];
    Actor *unk18;
    s16 unk1C;
} Struct80025B48;

typedef struct {
    u8 unk0[0x50 - 0x0];
    void *unk50[8];
    u8 unk70;
} Struct80025FFC;

typedef struct {
    u8 unk0[0x4C];
    u8 unk4C;
} struct_unknown_mp_aad;

void func_global_asm_806F54E0(u8, s32, s32);

extern u8 D_multiplayer_80026F70;

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern u8 D_global_asm_80750AB8;
extern u32 D_global_asm_807552E8;
extern s32 D_global_asm_807552EC;
extern s8 D_global_asm_8076A105; // A player index

// .data
u8 D_multiplayer_80026F70 = 0;

s32 D_multiplayer_80026F74[] = {
    0x024900EB,
    0x02440050,
    0x00000000, // TODO: Padding?
};

s32 D_multiplayer_80026F80[] = {
    0x057E0160,
    0x057900C8,
    0x00000000, // TODO: Padding?
};

s32 D_multiplayer_80026F8C[] = {
    0x04B00025,
    0x02BC00AA,
    0x00000000, // TODO: Padding?
};

s32 D_multiplayer_80026F98[] = {
    0x03E80050,
    0x0384005A,
    0x00000000, // TODO: Padding?
};

typedef struct MultiplayerStruct3 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} MultiplayerStruct3;

typedef struct {
    Maps map;
    s32 unk4;
    MultiplayerStruct3 *unk8;
    s32 unkC[4];
    s32 unk1C;
} Struct80026FA4;

static Struct80026FA4 D_multiplayer_80026FA4[4] = {
    {
        MAP_KONG_BATTLE_BATTLE_ARENA,
        0x00000001,
        D_multiplayer_80026F74,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
    },
    {
        MAP_KONG_BATTLE_ARENA_1,
        0x00000001,
        D_multiplayer_80026F80,
        0x00000050,
        0x00000051,
        0x00000052,
        0x00000053,
        0xFFFFFFFF,
    },
    {
        MAP_KONG_BATTLE_ARENA_2,
        0x00000001,
        D_multiplayer_80026F8C,
        0x00000028,
        0x00000046,
        0x00000049,
        0x00000052,
        0x00000053,
    },
    {
        MAP_KONG_BATTLE_ARENA_3,
        0x00000001,
        D_multiplayer_80026F98,
        0x00000026,
        0x00000028,
        0x00000027,
        0x00000025,
        0xFFFFFFFF,
    }
};

typedef struct Struct80027024 {
    void* unk0;
    f32 unk4;
    s32 unk8;
} Struct80027024;

Struct80027024 D_multiplayer_80027024[] = {
    {
        &D_global_asm_80720768,
        0.3f,
        0x0000000C,
    },
    {
        &D_global_asm_807204BC,
        0.5f,
        0x00000000,
    },
};

Gfx *func_multiplayer_80024000(Gfx *dl, Actor *arg1) {
    AAD_multiplayer_80024000 *aaD;
    f32 var_f2;
    f32 var_f12;

    aaD = arg1->additional_actor_data;
    if (D_global_asm_80750AB8 == 1) {
        var_f2 = 278.0f;
        var_f12 = 210.0f;
    } else {
        var_f2 = D_global_asm_80744490 * 0.5;
        var_f12 = D_global_asm_80744494 * 0.5;
    }
    dl = func_global_asm_805FD030(dl);
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(dl++);

    if (D_global_asm_80750AB8 == 1) {
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0x78, 0xFF, 0x50);
        dl = displayImage(dl, 0x60, 4, 0, 0x40, 0x40, var_f2 * 4.0f, var_f12 * 4.0f, 3.7f, 2.0f, 0xB4, 0.0f);
    }
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    return func_global_asm_8068E7B4(dl, var_f2, var_f12, aaD->unk8);
}

s32 func_multiplayer_800241F4(PlayerProgress *arg0, s32 playerIndex) {
    s32 var_v1;
    s32 temp = playerIndex;

    var_v1 = -arg0->unk2FE[temp];
    if (temp != 0) {
        var_v1 += arg0->unk2FE[0];
    }
    if (temp != 1) {
        var_v1 += arg0->unk2FE[1];
    }
    if (temp != 2) {
        var_v1 += arg0->unk2FE[2];
    }
    if (temp != 3) {
        var_v1 += arg0->unk2FE[3];
    }
    return var_v1;
}

s32 func_multiplayer_80024254(s32 playerIndex) {
    s32 var_v0;

    var_v0 = 0;
    switch (D_global_asm_807552E8) {
        case 2:
        case 3:
            var_v0 = func_global_asm_806F8AD4(1, playerIndex);
            break;
        case 4:
        case 5:
            var_v0 = func_global_asm_806F8AD4(7, playerIndex);
            break;
        case 0:
        case 1:
            var_v0 = func_multiplayer_800241F4(&D_global_asm_807FC950[playerIndex], playerIndex);
            break;
    }
    return var_v0;
}

// TODO: which aaD are they expecting? It's not PaaD
void func_multiplayer_800242FC(void *aaD) {
    s32 check;
    s32 playerIndex;
    s32 highest;
    s32 chosenPlayerIndex;

    D_global_asm_807552EC = 2;
    chosenPlayerIndex = 0;
    highest = -99999;
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        check = func_multiplayer_80024254(playerIndex);
        if (highest < check) {
            highest = check;
            chosenPlayerIndex = playerIndex;
        } else if (check == highest) {
            chosenPlayerIndex = -1;
        }
    }
    global_properties_bitfield |= 0x40001;
    func_global_asm_80714638();
    D_global_asm_8076A105 = chosenPlayerIndex;
}

void func_multiplayer_800243C8(void) {
    AAD_multiplayer_800243C8 *aaD;
    OSTime temp_ret_3;

    aaD = gCurrentActorPointer->additional_actor_data;
    temp_ret_3 = ((osGetTime() - aaD->unk0) * 64) / 3000;
    if (!(global_properties_bitfield & 2)) {
        aaD->unk8 = aaD->unkC - temp_ret_3 / 1000000;
    }
    if (!(aaD->unk8 > 0)) {
        aaD->unk8 = 0;
        func_multiplayer_800242FC(aaD);
    }
    addActorToTextOverlayRenderArray(func_multiplayer_80024000, gCurrentActorPointer, 7);
}

void func_multiplayer_8002449C(void) {
    s32 temp_v0;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        temp_v0 = func_multiplayer_80024254(playerIndex);
        if ((temp_v0 >= D_global_asm_807552E4.unkC) || (temp_v0 < -999)) {
            func_multiplayer_800242FC(gCurrentActorPointer->additional_actor_data);
            return;
        }
    }
}

void func_multiplayer_8002452C(void) {
    s32 a = 0;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (func_multiplayer_80024254(playerIndex)) {
            a++;
        }
    }
    if (a < 2) {
        func_multiplayer_800242FC(gCurrentActorPointer->additional_actor_data);
    }
}

Gfx *func_multiplayer_800245B0(Gfx *dl, s16 *arg1, s16 arg2, void *arg3, s32 arg4) {
    gDPLoadTextureBlock(dl++, arg3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
    // TODO: Issue is here
    gSPTextureRectangle(
        dl++,
        *arg1 << 2,
        arg2 << 2,
        (*arg1 + (arg4 * 8)) << 2,
        (arg2 + 8) << 2,
        G_TX_RENDERTILE,
        0,
        0,
        0x0400,
        0x0400
    );
    *arg1 += (arg4 * 8);
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_800246EC.s")

Gfx *func_multiplayer_800245B0(Gfx *, s16 *, s16, void *, s32);
extern u8 D_global_asm_80750AB8;

/*
Gfx *func_multiplayer_800246EC(Gfx *dl, Struct800246EC *aaD, f32 arg2) {
    s16 spAE;
    s16 temp_s4;
    s32 temp_s0;
    s32 temp_v0_3;
    s32 i;
    u8 var_v1;
    s32 var_s1;
    Struct800246EC_unk20 *temp_a2;
    CharacterChange *temp_v0;

    gDPPipeSync(dl++);
    gSPDisplayList(dl++, &D_1000118);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_NOOP2);
    gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPSetTextureFilter(dl++, G_TF_POINT);
    gDPSetTexturePersp(dl++, G_TP_NONE);
    for (i = 0; i < cc_number_of_players; i++) {
        temp_a2 = aaD->unk20[i];
        var_v1 = 0xFF;
        temp_v0 = &character_change_array[i];
        if (temp_v0->unk2EA) {
            var_v1 = temp_v0->playerPointer->shadow_opacity;
            if (temp_v0->playerPointer->shadow_opacity > 0xFF) {
                var_v1 = 0xFF;
            }
        }
        if ((!temp_v0->does_player_exist) || (var_v1 == 0)) {
            continue;
        }
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, var_v1);
        if (D_global_asm_80750AB8 == 0) {
            spAE = temp_a2->unk8 - 0x30;
        } else {
            spAE = ((i + 1) * arg2) - 20.0;
        }
        temp_s4 = temp_a2->unk6 + 8;
        var_s1 = MAX(0, D_global_asm_807FC950[i].health);
        temp_s0 = var_s1 / 2;
        if (temp_s0) {
            dl = func_multiplayer_800245B0(dl, &spAE, temp_s4, aaD->unk44, temp_s0);
        }
        temp_v0_3 = var_s1 - (var_s1 << 1);
        if (temp_v0_3) {
            dl = func_multiplayer_800245B0(dl, &spAE, temp_s4, aaD->unk48, temp_v0_3);
        }
    }
    return dl;
}
*/

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;

typedef struct {
    u8 unk0[0x6 - 0x0];
    s16 unk6;
} AAD_800249D8_unk20;

typedef struct {
    u8 unk0[0x20 - 0x0];
    AAD_800249D8_unk20 *unk20;
    u8 unk24[0x30 - 0x24];
    s32 unk30;
} AAD_800249D8;

Gfx *func_multiplayer_800249D8(Gfx *dl, Actor *arg1) {
    AAD_800249D8 *aaD;
    s32 i;
    f32 v;
    char sp98[0x14];
    f32 x;
    f32 temp_f20;
    f32 temp_f24;
    AAD_800249D8_unk20 *temp0;
    f32 temp1;
    s16 temp2;
    s16 temp3;

    aaD = arg1->additional_actor_data;
    temp_f24 = (f32)D_global_asm_80744490 / (cc_number_of_players + 1);
    temp0 = aaD->unk20;
    temp_f20 = temp0->unk6 + 8;
    gDPSetScissor(dl++, G_SC_NON_INTERLACE, 0, 0, D_global_asm_80744490, D_global_asm_80744494);
    dl = func_multiplayer_800246EC(dl, aaD, temp_f24);
    if (D_global_asm_807552E8 != 3) {
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xB4);
        gSPDisplayList(dl++, &D_1000118);
        gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(dl++, aaD->unk30, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(dl++);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xB4);
        temp_f20 += 8.0f;
        for (i = 0; i < cc_number_of_players; i++) {
            temp0 = func_multiplayer_80024254(i);
            _sprintf(&sp98, "%d", temp0);
            temp1 = getCenterOfString(1, &sp98);
            x = (((i + 1) * temp_f24) - ((f32)(temp1 * 0.25))) * 8.0f;
            dl = printStyledText(dl, 1, x, temp_f20 * 8.0f, &sp98, 4);
        }
    }
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80024CA4.s")

typedef struct MultiplayerActor318AAD_Sub50 {
    void *unk0[4];
} MultiplayerActor318AAD_Sub50;

typedef struct MultiplayerActor318AAD {
    OSTime unk0;
    u8 pad8[0xC - 0x8];
    s32 unkC;
    s32 unk10;
    u8 pad14[0x20 - 0x14];
    Struct80750948 *unk20[4];
    Mtx *unk30;
    s32 unk34;
    u8 unk38;
    u8 pad39[0x3C - 0x39];
    s32 unk3C;
    s16 unk40;
    s16 unk42;
    void *unk44;
    void *unk48;
    u8 pad4C[0x50 - 0x4C];
    void *unk50[8];
    u8 unk70;
} MultiplayerActor318AAD;

/*
Gfx *func_multiplayer_80024CA4(Gfx *dl, Actor *arg1) {
    MultiplayerActor318AAD *aaD; // 104
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f22_2;
    Struct80750948 *temp_s4;
    f32 spF0;
    s32 temp1;
    s32 i;
    s32 temp_v0_3;
    u32 temp_s6;
    u8 alpha;
    Actor *temp_a3;
    s32 temp2;
    f32 temp;
    s8 spCC;
    f32 temp4;
    f32 temp3;
    f32 spC0;

    aaD = arg1->AAD_as_array[0];
    spF0 = func_global_asm_806FD894(1);
    spC0 = func_global_asm_806FD894(1);
    dl = func_multiplayer_800246EC(dl, aaD, 0.0f);
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, aaD->unk30, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    for (i = 0; i < cc_number_of_players; i++) {
        temp_a3 = character_change_array[i].playerPointer;
        temp_s4 = aaD->unk20[i];
        if (temp_a3->control_state == 0x84) {
            alpha = temp_a3->shadow_opacity;
            temp_f20 = (temp_s4->unk6 + ((temp_s4->unkA - temp_s4->unk6) * 0.5));
            temp_f22 = (temp_s4->unk4 + ((temp_s4->unk8 - temp_s4->unk4) * 0.5));
            gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF - alpha);
            _sprintf(&spCC, "BAD LUCK");
            temp_f22 -= (getCenterOfString(1, &spCC) * 0.25);
            dl = printStyledText(dl, 1, temp_f22 * 8.0f, (temp_f20 - (spF0 * 0.25)) * 8.0f, &spCC, 4U);
        } else {
            alpha = 0xFF;
        }
        if (alpha == 0) {
            continue;
        }
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
        if (aaD->unk70 == 0) {
            temp_f22_2 = temp_s4->unk4 + 4.0f;
            temp_f20 = (temp_s4->unkA - ((8.0f + spC0) * 0.5f)) * 8.0f;
            temp_v0_3 = func_global_asm_806F8AD4(3, i);
            if (temp_v0_3) {
                gDPSetPrimColor(dl++, 0, 0, 0x64, 0x1E, 0x00, alpha);
                _sprintf(&spCC, "%d", temp_v0_3);
            } else {
                temp1 = func_global_asm_806F8AD4(2, i);
                _sprintf(&spCC, "%d", temp1);
            }
            dl = printStyledText(dl, 1, temp_f22_2 * 8.0f, temp_f20, &spCC, 4U);
            if (temp_v0_3) {
                gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
            }
            temp1 = func_global_asm_806F8AD4(4, i);
            _sprintf(&spCC, "%d", temp1);
            temp2 = getCenterOfString(1, &spCC);
            dl = printStyledText(dl, 1, ((temp_s4->unk8 - ((temp2 + 8) * 0.5f)) * 8.0f), temp_f20, &spCC, 4U);
        }
        _sprintf(&spCC, "%d", func_multiplayer_80024254(i));
        temp3 = getCenterOfString(1, &spCC) * 0.5f;
        temp = temp_s4->unk6;
        temp4 = temp_s4->unk8;
        temp += (8.0 + ((8.0f - (spC0 * 0.5f)) * 0.5));
        temp4 -= temp3 + 50.0f;
        dl = printStyledText(dl, 1, temp4 * 8.0f, temp * 8.0f, &spCC, 4U);
    }
    return dl;
}
*/

Gfx *func_multiplayer_800249D8(Gfx *, Actor *);
Gfx *func_multiplayer_80024CA4(Gfx *, Actor *);

Gfx *func_multiplayer_80025264(Gfx *dl, Actor *arg1) {
    s32 temp_t0 = (D_global_asm_807552E4.unk8 > 1);
    s32 temp_t7 = global_properties_bitfield & 3;

    gDPPipeSync(dl++);
    gDPSetScissor(dl++, G_SC_NON_INTERLACE, 0, 0, D_global_asm_80744490, D_global_asm_80744494);

    if (!temp_t7) {
        if (D_global_asm_807552E4.unk0 == 0) {
            if ((D_global_asm_807552E4.unk8 == 1) || (temp_t0)) {
                dl = func_multiplayer_800249D8(dl, arg1);
            }
        } else if ((D_global_asm_807552E4.unk8 == 1) || (temp_t0)) {
            dl = func_multiplayer_80024CA4(dl, arg1);
        }
    }
    return dl;
}

Struct80026FA4 *func_multiplayer_80025378(void) {
    Struct80026FA4 *entry = 0;
    s32 *new_var;
    u32 new_var2;
    s32 i;

    // fake match, whitespace matters here
    // clang-format off
 new_var = &i; i = 0; do { new_var2 = 4; do {
    // clang-format on
            if (current_map == D_multiplayer_80026FA4[*new_var].map) {
                entry = &D_multiplayer_80026FA4[*new_var];
            }
            i++;
        } while (((*new_var) < new_var2) && (entry == 0));
    } while (0);

    return entry;
}

s32 func_multiplayer_800253C8(void) {
    return (RandClamp(32767) % 211) + 90;
}

s32 func_multiplayer_80025404(void) {
    s32 pad;
    s32 sp50;
    Struct80717D84 *temp_a0;
    s32 i;
    s32 chosenPlayer;
    s32 boneIndex;
    s32 temp_s3;
    u8 temp_t4;
    PlayerAdditionalActorData *PaaD;

    chosenPlayer = -1;
    for (i = 0; i < cc_number_of_players; i++) {
        PaaD = character_change_array[i].playerPointer->PaaD;
        if (func_global_asm_806F8AD4(1, i) != 0) {
            temp_s3 = D_global_asm_807FC950[i].health + D_global_asm_807FC950[i].unk2FD;
            if (PaaD->unk260 == NULL) {
                switch (current_character_index[i]) {
                    case 0:
                    case 3:
                        boneIndex = 0xF;
                        break;
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                        boneIndex = 0xD;
                        break;
                }
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(-1);
                func_global_asm_80714998(2);
                changeActorColor(0xFF, 0xFF, 0xFF, 0x7F);
                func_global_asm_8071498C(func_global_asm_8071F3C0);
                PaaD->unk260 = func_global_asm_80714C08(&D_global_asm_807207BC, 0.5f, character_change_array[i].playerPointer, boneIndex, 2);
                D_global_asm_807FC950[i].unk2FA = temp_s3;
            }
            if (D_global_asm_807FC950[i].unk2FA < temp_s3) {
                D_global_asm_807FC950[i].unk2FA = temp_s3;
            }
            chosenPlayer = i;
        } else {
            temp_a0 = PaaD->unk260;
            if (temp_a0 != NULL) {
                func_global_asm_80715908(temp_a0);
                PaaD->unk260 = NULL;
                D_global_asm_807FC950[i].unk2FA = 0;
            }
        }
    }
    return chosenPlayer;
}

s32 func_multiplayer_80025608(s32 objectType) {
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp_1;
    s16 sp2E;
    s16 sp2C;

    sp38 = 0;
    sp2E = 0;
    sp2C = 0;
    return func_global_asm_8063254C(objectType, &sp38, &sp34, &sp30, &sp_1, &sp2E, &sp2C);
}

void func_global_asm_806F5FE8(s32, s16, s16, s16, s32);
extern s32 D_global_asm_807552F0;

void func_multiplayer_80025654(MultiplayerStruct4 *arg0) {
    s32 temp_v0;
    MultiplayerStruct3 *sp20;
    u8 temp_v0_2;

    sp20 = func_multiplayer_80025378()->unk8;
    if ((!gameIsInAdventureMode()) || (global_properties_bitfield & 2)) {
        return;
    }
    if (D_global_asm_807552E8 == 3) {
        func_multiplayer_800243C8();
    }
    temp_v0 = func_multiplayer_80025404();
    if (temp_v0 == -1) {
        if (
            (!arg0->unk4C) &&
            (!func_global_asm_8067ADB4(0x7AU)) &&
            (!func_multiplayer_80025608(0x1D2)) &&
            (!func_global_asm_806F5EB4(0x1D2, 0, sp20->unk0, sp20->unk2, sp20->unk4))
            ) {
            func_global_asm_806F5FE8(0x1D2, sp20->unk0, sp20->unk2, sp20->unk4, 0xA);
        }
    } else if ((D_global_asm_807552E8 == 5) && (func_multiplayer_80024254(temp_v0) >= D_global_asm_807552F0)) {
        func_multiplayer_800242FC(arg0);
    }
    if (arg0->unk4C) {
        arg0->unk4C--;
    }
}

void func_multiplayer_80025794(void) {

    Struct80026FA4 *temp_v0; // 84
    MultiplayerStruct3 *temp_s0;
    s32 i; // 7C
    s32 var_s7;
    MultiplayerStruct3 *temp_s5;
    s32 temp_s3;
    s16 temp_s4;
    s16 var_s0;

    temp_v0 = func_multiplayer_80025378();
    temp_s0 = temp_v0->unk8;
    func_multiplayer_800243C8();
    if ((!gameIsInAdventureMode()) || (global_properties_bitfield & 2)) {
        return;
    }
    temp_s5 = temp_s0;
    for (i = 0; i < temp_v0->unk4; i++) {
        s32 j, k; // nis
        f32 temp_f26; // nis
        f32 temp_f28; // nis
        f32 mult;
        f32 temp_f20;
        f32 var_f24;
        f32 var_f4;
        f32 var_f20;

        if (temp_s5->unk8) {
            temp_s5->unk8--;
        } else {
            if (!temp_s5->unk6) {
                var_s7 = 1;
            } else {
                var_s7 = (RandClamp(32767) % 3) + 1;
            }
            for (j = 0; j < var_s7; j++) {
                temp_s3 = (RandClamp(32767) % 3) + 1;
                temp_s4 = func_multiplayer_800253C8();
                mult = ((func_global_asm_806119FC() * 0.8) + 0.2) * temp_s5->unk6;
                var_s0 = (rand() >> 0xF) % 4096;
                temp_f26 = temp_s5->unk0;
                temp_f20 = temp_s5->unk2 - 0x17;
                temp_f28 = temp_s5->unk4;
                temp_f26 += (mult * func_global_asm_80612794(var_s0));
                temp_f28 += (mult * func_global_asm_80612790(var_s0));
                if (temp_s3 > 1) {
                    var_s0 = (rand() >> 0xF) % 4096;
                    mult = 15.0f;
                    var_f24 = 4096.0f / temp_s3;
                } else {
                    mult = 0.0f;
                    var_f24 = 0.0f;
                    var_s0 = 0;
                }
                for (k = 0; k < temp_s3; k++) {
                    var_f20 = (func_global_asm_80612794(var_s0) * mult) + temp_f26;
                    var_f4 = (func_global_asm_80612790(var_s0) * mult) + temp_f28;
                    func_global_asm_806F5F2C(0x7A, temp_s4, var_f20, temp_f20, var_f4);
                    var_s0 += var_f24;
                    var_s0 &= 0xFFF;
                }
            }
            temp_s5->unk8 = func_multiplayer_800253C8();
        }
        temp_s5++;
    }
}

void func_multiplayer_80025B48(Struct80025B48 *arg0) {
    s32 var_a2;

    var_a2 = 0;
    if (arg0->unk18 != NULL) {
        if (arg0->unk18->control_state == 0x40) {
            arg0->unk18 = NULL;
            var_a2 = 1;
        }
    } else {
        var_a2 = 1;
    }
    if (arg0->unk1C == 0) {
        if (var_a2) {
            arg0->unk1C = (RandClamp(32767) % 271) + 0x1E;
        }
    } else {
        arg0->unk1C--;
    }
    if (var_a2) {
        if (arg0->unk1C == 0) {
            var_a2 = (RandClamp(32767) % 3) + 1;
            if (var_a2 == 3) {
                var_a2 += (RandClamp(32767) % 5);
            }
            arg0->unk18 = getSpawnerTiedActor(var_a2, 0);
            if (arg0->unk18 == NULL) {
                arg0->unk18 = func_global_asm_807271F4(var_a2, 0, 0, 0, 0, 0, 0);
            }
            if (arg0->unk18 != NULL) {
                arg0->unk18->control_state = 0x36;
                arg0->unk18->control_state_progress = 0;
            }
        }
    }
}

void func_multiplayer_80025CE8(s32 playerIndex) {
    Actor *temp_s3;
    s32 temp_t4;
    s32 temp_t5;
    s32 i;
    u32 temp_hi;
    u32 temp_t9;
    PlayerAdditionalActorData *PaaD;
    PlayerAdditionalActorData *PaaD2;
    Actor *player;

    temp_s3 = character_change_array[playerIndex].playerPointer;
    PaaD = temp_s3->PaaD;
    switch (PaaD->unk264) {
        case 0:
            func_global_asm_806D0468(temp_s3, 2);
            func_global_asm_806F54E0(playerIndex, 0x8E, 0);
            break;
        case 1:
            for (i = 0; i < cc_number_of_players; i++) {
                player = character_change_array[i].playerPointer;
                PaaD2 = player->PaaD;
                if (i != playerIndex) {
                    if (PaaD2->unkD4 == 0) {
                        if (player->control_state != 0x84) {
                            setAction(0x27, temp_s3, i);
                            PaaD2->unk200 = 0x96;
                        }
                    }
                }
            }
            break;
        case 2:
            PaaD->unk1F0 |= 0x20;
            PaaD->unk1F0 &= ~0x8000000;
            func_global_asm_806F54E0(playerIndex, 0x8E, 0);
            break;
        case 3:
            func_global_asm_806846B4(temp_s3->x_position, temp_s3->y_position, temp_s3->z_position, 0.1f, 0.1f, temp_s3, 1);
            break;
        case 4:
            temp_hi = (rand() >> 0xF) % 5;
            switch (temp_hi) {
                case 0:
                    func_global_asm_806D0468(temp_s3, 0);
                    func_global_asm_806F54E0(playerIndex, 0x8E, 0);
                    break;
                case 1:
                    PaaD->unk200 = 0x96;
                    PaaD->unk1F0 |= 0x80;
                    break;
                case 2:
                    PaaD->unk1F0 |= 0x08000000;
                    PaaD->unk1F0 &= ~0x20;
                    PaaD->unk200 = 0x96;
                    break;
                case 3:
                    func_global_asm_806C9974(playerIndex, 0x40);
                    break;
                case 4:
                    func_global_asm_806846B4(temp_s3->x_position, temp_s3->y_position, temp_s3->z_position, 0.1f, 0.1f, temp_s3, 1);
                    break;
            }
            break;
    }
    PaaD->unk264 = -1;
}

void func_multiplayer_80025F84(void) {
    s32 i;
    Struct80026FA4 *temp_v0;

    temp_v0 = func_multiplayer_80025378();
    for (i = 0; i < 4 && temp_v0->unkC[i] != -1; i++) {
        func_global_asm_8063DA40(temp_v0->unkC[i], 0);
    }
}

void func_multiplayer_80025FFC(Struct80025FFC *arg0) {
    void *temp_a0;
    s32 i;

    if (arg0->unk70 != 0) {
        for (i = 0; i < cc_number_of_players * 2; i++) {
            temp_a0 = arg0->unk50[i];
            if (temp_a0 != NULL) {
                func_global_asm_80715908(temp_a0);
            }
            arg0->unk50[i] = NULL;
        }
    }
    arg0->unk70 = 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80026094.s")

typedef struct Struct80026094_0 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct80026094_0;

typedef struct Struct80026094_1 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct80026094_1;

Struct80750948 *func_global_asm_806C7C94(u8);
Gfx *func_multiplayer_80025264(Gfx *, Actor *);
void func_multiplayer_80025794(void);
extern OSTime D_global_asm_807445B0;
extern s32 D_global_asm_80767CC0;
extern void *D_global_asm_8076D1F8;
extern Struct80027024 D_multiplayer_80027024[];

/*
void func_multiplayer_80026094(void) {
    f32 var_f2;
    s16 var_s0_4;
    s32 var_s2;
    s32 i, j;
    Struct80026094_1 *temp_s0;
    Struct80027024 *temp_s1;
    MultiplayerActor318AAD *aad;
    Struct80026094_0 *temp_t0;

    aad = gCurrentActorPointer->additional_actor_data;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        var_s2 = FALSE;
        func_global_asm_806C9AE0();
        for (i = 0; i < cc_number_of_players; i++) {
            aad->unk20[i] = func_global_asm_806C7C94(i);
        }
        D_global_asm_807552E4.unk8 = 1;
        aad->unk0 = osGetTime();
        aad->unk34 = D_global_asm_80767CC0;
        aad->unk38 = 0U;
        aad->unk42 = 0;
        aad->unk40 = 0;
        func_global_asm_80737638(D_global_asm_8076D1F8, 0x1E6, 0U, 0x40U, 1.0f, 0x80U, &aad->unk3C);
        D_multiplayer_80026F70 = 0;
        switch (D_global_asm_807552E4.unk4) {
            case 3:
            case 5:
                var_s2 = TRUE;
            case 2:
                if (var_s2) {
                    temp_t0 = func_multiplayer_80025378()->unk8;
                    func_global_asm_806F5FE8(0x1D2, temp_t0->unk0, temp_t0->unk2, temp_t0->unk4, 0xA);
                }
                break;
            case 4:
                for (i = 0; i < cc_number_of_players; i++) {
                    changeCollectableCount(7, i, D_global_asm_807552E4.unkC);
                }
                func_global_asm_806F833C(0);
                break;
        }
        if ((D_global_asm_807552E4.unk0 == 0) && (current_map == MAP_KONG_BATTLE_BATTLE_ARENA)) {
            func_global_asm_806F5FA0(0x24E, 0xD4, 0x205);
            func_global_asm_806F5FA0(0x24E, 0xD4, 0x285);
            func_global_asm_806F5FA0(0x212, 0xD4, 0x24E);
            func_global_asm_806F5FA0(0x28E, 0xD4, 0x247);
        }

        aad->unk30 = malloc(0x40);
        guScale(aad->unk30, 0.5f, 0.5f, 1.0f);
        aad->unkC = D_global_asm_807552E4.unkC;
        aad->unkC *= 60;
        gCurrentActorPointer->unk64 |= 2;
        aad->unk44 = getPointerTableFile(TABLE_14_TEXTURES_HUD, 0xB9, 0U, 0U);
        aad->unk48 = getPointerTableFile(TABLE_14_TEXTURES_HUD, 0xBA, 0U, 0U);
        aad->unk10 = 0;
    }
    aad->unk0 += D_global_asm_807445B0;
    switch (D_global_asm_807552E4.unk8) {
        case 2:
        case 3:
            break;
        case 1:
            switch (D_global_asm_807552E4.unk4) {
                case 3:
                case 5:
                    func_multiplayer_80025654(aad);
                    break;
                case 2:
                    func_multiplayer_80025794();
                    break;
                case 0:
                    func_multiplayer_800243C8();
                    break;
                case 1:
                    func_multiplayer_8002449C();
                    break;
                case 4:
                    func_multiplayer_8002452C();
                    break;
                }
            break;
    }
    if (D_global_asm_807552E4.unk0 == 0) {
        for (i = 0; i < cc_number_of_players; i++) {
            func_multiplayer_80025CE8(i);
        }
        if (cc_number_of_players == 2) {
            func_multiplayer_80025B48(aad);
        }
    } else if ((global_properties_bitfield & 2) || ((s32) ((f32) aad->unk10 * 0.033333335f) & 1)) {
        func_multiplayer_80025FFC(aad);
    } else if (aad->unk70 == 0) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < cc_number_of_players; j++) {
                if (character_change_array[j].does_player_exist) {
                    temp_s0 = aad->unk20[j];
                    temp_s1 = &D_multiplayer_80027024[i];
                    func_global_asm_8071495C();
                    func_global_asm_807149FC(-1);
                    func_global_asm_80714998(0U);
                    func_global_asm_80714944(temp_s1->unk8);
                    if (!i) {
                        var_f2 = temp_s0->unk8 + 0xB;
                    } else {
                        var_f2 = temp_s0->unk4 - 0xB;
                    }
                    aad->unk50[(cc_number_of_players * i) + j] = drawSpriteAtPosition(
                        temp_s1->unk0,
                        temp_s1->unk4,
                        var_f2,
                        temp_s0->unkA - 0xB,
                        -10.0f);
                }
            }
        }
        aad->unk70 = 1U;
    }
    aad->unk10++;
    aad->unk10 %= 180;
    aad->unk40 = MAX(0x1F40, aad->unk40 - 100);
    aad->unk42 = MIN(aad->unk40, aad->unk42 + 0x3E8);
    func_global_asm_80737AC4(aad->unk3C, 8, aad->unk42);
    if (D_multiplayer_80026F70 & 0x80) {
        aad->unk40 = 0x7FFF;
        D_multiplayer_80026F70 &= 0xFF7F;
    }
    if (D_multiplayer_80026F70 & 7) {
        if ((D_global_asm_80767CC0 - aad->unk34) >= 6U) {
            aad->unk34 = D_global_asm_80767CC0;
            aad->unk38 = 0U;
            var_s0_4 = 0x1E8;
            if (D_multiplayer_80026F70 & 4) {
                var_s0_4 = 0x1EA;
            } else if ((D_multiplayer_80026F70 & 3) && ((((D_multiplayer_80026F70 & 2) * 0x12C) + 0x1F4) < ((s32) (rand() >> 0xF) % 1000))) {
                var_s0_4 = RandClamp(1000) & 1 ? 0x1E7 : 0x1EA;
            }
            playSound(var_s0_4, 0x7FFFU, 64.0f, 1.0f, 0x14, 0x80);
        }
        aad->unk40 = MIN(0x7FFF, aad->unk40 + 0x4650);
        D_multiplayer_80026F70 &= 0xFFF8;
    }
    if ((u32) ((aad->unk38 * 35) + 0x384) < (u32) (D_global_asm_80767CC0 - aad->unk34)) {
        playSound(0x1E9, (aad->unk38 * 0xBB8) + 0x511F, 64.0f, 1.0f, 0xA, 0x80);
        aad->unk38++;
        if (aad->unk38  == 5) {
            aad->unk38 = 0U;
            aad->unk34 = (s32) D_global_asm_80767CC0;
        }
    }
    addActorToTextOverlayRenderArray(&func_multiplayer_80025264, gCurrentActorPointer, 7U);
}
*/

void func_multiplayer_800268C0(u8 arg0) {
    D_multiplayer_80026F70 |= arg0;
}

void func_multiplayer_800268DC(Actor *arg0, PlayerAdditionalActorData *arg1, PlayerProgress *arg2) {
    arg2->crystals = 0;
    arg2->standardAmmo = 0;
    arg2->oranges = 0;
    arg2->homingAmmo = 0;
    arg1->unkD4 = 0x5A;
    func_global_asm_806F0C18(arg0);
    arg0->object_properties_bitfield &= 0xDFFFFFFF;
    arg1->unk247 = -1;
    arg1->unk246 = 0;
    if (func_global_asm_80714608(0) != 0) {
        extra_player_info_pointer->unk21E = 0;
    }
    if ((D_global_asm_807552E8 == 3) || (D_global_asm_807552E8 == 5)) {
        changeCollectableCount(1, arg1->unk1A4, -10);
    }
}

void func_multiplayer_8002698C(MultiplayerStruct0 *arg0) {
    if (D_global_asm_807552E8 == 2) {
        changeCollectableCount(1, arg0->unk1A4, -3);
    }
}

void func_multiplayer_800269C8(u8 playerIndex, s8 arg1) {
    Actor *temp_s0;
    struct_unknown_mp_aad* phi_v1;
    s32 temp_v1;
    s32 sp30;
    PlayerProgress *temp_s1;

    temp_s0 = character_change_array[playerIndex].playerPointer;
    temp_s1 = &D_global_asm_807FC950[playerIndex];
    temp_v1 = temp_s1->health + temp_s1->unk2FD + arg1;
    sp30 = temp_s1->unk2FA - temp_v1;
    if ((func_global_asm_806F8AD4(1U, playerIndex) != 0) && ((temp_v1 <= 0) || (sp30 >= 2))) {
        struct_unknown_mp_aad* aad = func_global_asm_8067ADB4(0x13E)->additional_actor_data;
        aad->unk4C = 1;
        changeCollectableCount(1, playerIndex, -10);
        if (D_global_asm_807552E8 == 5) {
            func_multiplayer_80025F84();
        }
        func_global_asm_806A5DF0(0x7A, temp_s0->x_position, temp_s0->y_position, temp_s0->z_position, (s32) temp_s0->y_rotation, 1, -1, 0);
        temp_s1->unk2FA = 0;
    }
}

void func_multiplayer_80026B0C(s32 playerIndex) {
    Actor *player = character_change_array[playerIndex].playerPointer;
    player->noclip_byte = 0xC;
    switch (D_global_asm_807552E8) {
        case 2:
            changeCollectableCount(1, playerIndex, -3);
            break;
        case 5:
            changeCollectableCount(7, playerIndex, -64);
            // fallthrough
        case 3:
            func_multiplayer_800269C8(playerIndex, 0);
            break;
        case 4:
            changeCollectableCount(7, playerIndex, -1);
            break;
    }
}

s32 func_multiplayer_80026BD8(s32 arg0) {
    ExitData *exit;
    f32 dx;
    f32 dz;
    f32 d;
    f32 dy;
    f32 closest;
    f32 var_f22;
    s32 playerIndex;
    s32 exitIndex;
    s32 chosenExit;
    Actor *player;

    var_f22 = 0.0f;
    chosenExit = 0;
    for (exitIndex = 0; exitIndex < 4; exitIndex++) {
        closest = 9999999.0f;
        exit = getExitData(exitIndex);
        for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
            player = character_change_array[playerIndex].playerPointer;
            if ((character_change_array[playerIndex].does_player_exist != 0) && (player->control_state != 0x84)) {
                dx = exit->pos.x - player->x_position;
                dy = exit->pos.y - player->y_position;
                dz = exit->pos.z - player->z_position;
                d = SQ(dx) + SQ(dy) + SQ(dz);
                if (d < closest) {
                    closest = d;
                }
            }
        }
        if (var_f22 < closest) {
            var_f22 = closest;
            chosenExit = exitIndex;
        }
    }
    return chosenExit;
}

void func_multiplayer_80026D40(Actor *arg0, s32 playerIndex) {
    if ((D_global_asm_807552E8 == 4) && (func_multiplayer_80024254(playerIndex) == 0)) {
        D_global_asm_807FC950[playerIndex].health = 0;
        arg0->control_state_progress++;
        setAction(0x5B, NULL, playerIndex);
        arg0->noclip_byte = 1;
    } else {
        func_global_asm_806C9434(func_multiplayer_80026BD8(playerIndex));
        character_change_array[playerIndex].unk2DC.unk6 |= 1;
        func_global_asm_806CFF9C(arg0);
    }
}

void func_multiplayer_80026E20(u8 playerIndex, s8 arg1) {
    Actor *temp_v0;
    PlayerAdditionalActorData *PaaD;
    s32 temp[3];
    PlayerProgress *PP = &D_global_asm_807FC950[playerIndex];
    CharacterChange *CC = &character_change_array[playerIndex];

    if ((PP->health + PP->unk2FD) > 0) {
        if (CC->unk2A0 != NULL) {
            temp_v0 = func_global_asm_806C9FD8(CC->unk2A0);
            if (temp_v0 != NULL) {
                if (temp_v0->interactable == 1) {
                    PaaD = temp_v0->PaaD;
                    if ((PP->health + PP->unk2FD + arg1) <= 0) {
                        D_global_asm_807FC950[PaaD->unk1A4].unk2FE[playerIndex]++;
                    }
                }
            }
        }
    }
    if (D_global_asm_807552E8 == 3 || D_global_asm_807552E8 == 5) {
        func_multiplayer_800269C8(playerIndex, arg1);
    }
}
