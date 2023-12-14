#include <ultra64.h>
#include "functions.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
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
    s32 unk50[8];
    u8 unk70;
} Struct80025FFC;

typedef struct {
    u8 unk0[0x4C];
    u8 unk4C;
} struct_unknown_mp_aad;

void func_multiplayer_800242FC(MultiplayerStruct4 *);
s32 func_multiplayer_80025404(void);
void func_multiplayer_80025F84();
s32 func_multiplayer_80026BD8(s32);

void *func_global_asm_805FD030(Gfx*);
s32 func_global_asm_8063254C(s32, s32 *, f32 *, f32 *, f32 *, s16 *, s16*);
void func_global_asm_8068E7B4(Gfx *, f32, f32, s32);
void func_global_asm_806A5DF0(u16, f32, f32, f32, s32, s32, s32, s32);
void func_global_asm_806C9434(s32);
void func_global_asm_806CFF9C(Actor*);
void func_global_asm_806F0C18(Actor*);
void func_global_asm_806F91B4(s32, u8, s16);
void func_global_asm_806F54E0(u8, s32, s32);
void func_global_asm_80715908(Struct80717D84 *);
extern int func_global_asm_8071F3C0(); // TODO: Signature

extern u8 D_multiplayer_80026F70;

extern s32 D_global_asm_807207BC; // TODO: Type
extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern u8 D_global_asm_80750AB8;
extern u32 D_global_asm_807552E8;
extern s32 D_global_asm_807552EC;
extern s8 D_global_asm_8076A105; // A player index

void func_multiplayer_80024000(Gfx *dl, Actor *arg1) {
    AAD_multiplayer_80024000 *sp44;
    f32 var_f2;
    f32 var_f12;

    sp44 = arg1->additional_actor_data;
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
        dl = func_global_asm_8068C5A8(dl, 0x60, 4, 0, 0x40, 0x40, var_f2 * 4.0f, var_f12 * 4.0f, 3.7f, 2.0f, 0xB4, 0.0f);
    }
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_global_asm_8068E7B4(dl, var_f2, var_f12, sp44->unk8);
}

s32 func_multiplayer_800241F4(PlayerProgress *arg0, s32 arg1) {
    s32 var_v1;
    s32 temp = arg1;

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

s32 func_multiplayer_80024254(s32 arg0) {
    s32 var_v0;

    var_v0 = 0;
    switch (D_global_asm_807552E8) {
        case 2:
        case 3:
            var_v0 = func_global_asm_806F8AD4(1, arg0);
            break;
        case 4:
        case 5:
            var_v0 = func_global_asm_806F8AD4(7, arg0);
            break;
        case 0:
        case 1:
            var_v0 = func_multiplayer_800241F4(&D_global_asm_807FC950[arg0], arg0);
            break;
    }
    return var_v0;
}

void func_multiplayer_800242FC(MultiplayerStruct4 *arg0) {
    s32 temp_v0;
    s32 playerIndex;
    s32 phi_s1;
    s32 phi_s2;

    D_global_asm_807552EC = 2;
    phi_s2 = 0;
    phi_s1 = -99999;
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        temp_v0 = func_multiplayer_80024254(playerIndex);
        if (phi_s1 < temp_v0) {
            phi_s1 = temp_v0;
            phi_s2 = playerIndex;
        } else if (temp_v0 == phi_s1) {
            phi_s2 = -1;
        }
    }   
    global_properties_bitfield |= 0x40001;
    func_global_asm_80714638();
    D_global_asm_8076A105 = phi_s2;
}

void func_multiplayer_800243C8(void) {
    s32 pad;
    u64 temp_ret_3;
    u64 temp;
    AAD_multiplayer_800243C8 *temp_s0;

    temp_s0 = current_actor_pointer->additional_actor_data;
    temp = func_dk64_boot_80005918(osGetTime() - temp_s0->unk0, 0x40);
    temp_ret_3 = func_dk64_boot_80005818(temp, 0xBB8);
    if (!(global_properties_bitfield & 2)) {
        temp_s0->unk8 = temp_s0->unkC - func_dk64_boot_80005818(temp_ret_3, 1000000);
    }
    if (!(temp_s0->unk8 > 0)) {
        temp_s0->unk8 = 0;
        func_multiplayer_800242FC(temp_s0);
    }
    func_global_asm_8068C350(&func_multiplayer_80024000, current_actor_pointer, 7);
}

void func_multiplayer_8002449C(void) {
    s32 temp_v0;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        temp_v0 = func_multiplayer_80024254(playerIndex);
        if ((temp_v0 >= D_global_asm_807552E4.unkC) || (temp_v0 < -999)) {
            func_multiplayer_800242FC(current_actor_pointer->additional_actor_data);
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
        // TODO: Which aaD type are they actually expecting here?
        func_multiplayer_800242FC(current_actor_pointer->PaaD);
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_800245B0.s")

/*
void *func_multiplayer_800245B0(Gfx *dl, s16 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, arg3);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 63, 1024);
    gDPPipeSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x001C, 0x001C);

    // TODO: wut?
    dl->unk0 = 0xE4000000 | ((((*arg1 + arg4 * 8) * 4) & 0xFFF) << 0xC) | (((arg2 + 8) * 4) & 0xFFF);
    dl->unk4 = (((*arg1 * 4) & 0xFFF) << 0xC) | ((arg2 * 4) & 0xFFF);

    // TODO: wut?
    gsDPHalf1(dl++, 0x00000000);
    gsDPHalf2(dl++, 0x04000400);


    *arg1 += arg4 * 8;
    return dl;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_800246EC.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_800249D8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80024CA4.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80025264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80025378.s")

typedef struct {
    s32 map; // TODO: ?
    s32 unk4;
    s32 unk8;
    s32 unkC[4];
    s32 unk1C;
} Struct80025F84;

Struct80025F84 *func_multiplayer_80025378();

extern Struct80025F84 D_multiplayer_80026FA4[];

/*
// TODO: Close
Struct80025F84 *func_multiplayer_80025378(void) {
    Struct80025F84 *var_v1;
    u32 i;

    var_v1 = NULL;
    for (i = 0; var_v1 == NULL && i < 4U; i++) {
        if (current_map == D_multiplayer_80026FA4[i].map) {
            var_v1 = &D_multiplayer_80026FA4[i];
        }
    }
    return var_v1;
}
*/

s32 func_multiplayer_800253C8(void) {
    return (((rand() >> 0xF) % 32767) % 211) + 90;
}

s32 func_multiplayer_80025404(void) {
    s32 pad;
    s32 sp50;
    Struct80717D84 *temp_a0;
    s32 i;
    s32 chosenPlayer;
    s32 var_s6;
    s32 temp_s3;
    u8 temp_t4;
    PlayerAdditionalActorData *PaaD;

    chosenPlayer = -1;
    for (i = 0; i < cc_number_of_players; i++) {
        PaaD = character_change_array[i].player_pointer->PaaD;
        if (func_global_asm_806F8AD4(1, i) != 0) {
            temp_s3 = D_global_asm_807FC950[i].health + D_global_asm_807FC950[i].unk2FD;
            if (PaaD->unk260 == NULL) {
                switch (current_character_index[i]) {
                    case 0:
                    case 3:
                        var_s6 = 0xF;
                        break;
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                        var_s6 = 0xD;
                        break;
                }
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(-1);
                func_global_asm_80714998(2);
                func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x7F);
                func_global_asm_8071498C(&func_global_asm_8071F3C0);
                PaaD->unk260 = func_global_asm_80714C08(&D_global_asm_807207BC, 0.5f, character_change_array[i].player_pointer, var_s6, 2);
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

s32 func_multiplayer_80025608(s32 arg0) {
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp_1;
    s16 sp2E;
    s16 sp2C;

    sp38 = 0;
    sp2E = 0;
    sp2C = 0;
    return func_global_asm_8063254C(arg0, &sp38, &sp34, &sp30, &sp_1, &sp2E, &sp2C);
}

// close, issue is with call to func_global_asm_806F5EB4, extra param on the stack doesn't match global_asm signature
#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80025654.s")

void func_multiplayer_800243C8();
typedef struct MultiplayerStruct3 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} MultiplayerStruct3;
s32 func_multiplayer_80025608(s32);
void func_global_asm_806F5FE8(s32, s16, s16, s16, s32);
extern s32 D_global_asm_807552F0;

/*
void func_multiplayer_80025654(MultiplayerStruct4 *arg0) {
    s32 temp_v0;
    MultiplayerStruct3 *sp20;

    sp20 = func_multiplayer_80025378()->unk8;
    if (gameIsInAdventureMode() && ((global_properties_bitfield & 2) == 0)) {
        if (D_global_asm_807552E8 == 3) {
            func_multiplayer_800243C8();
        }
        temp_v0 = func_multiplayer_80025404();
        if (temp_v0 == -1) {
            if ((arg0->unk4C == 0) && 
                (!func_global_asm_8067ADB4(0x7A)) && // DK Coin (Multiplayer)
                (func_multiplayer_80025608(0x1D2) == 0) && 
                (!func_global_asm_806F5EB4(0x1D2, 0, sp20->unk0, sp20->unk2))) {
                    func_global_asm_806F5FE8(0x1D2, sp20->unk0, sp20->unk2, sp20->unk4, 0xA);
            }
        } else if ((D_global_asm_807552E8 == 5) && (func_multiplayer_80024254(temp_v0) >= D_global_asm_807552F0)) {
            func_multiplayer_800242FC(arg0);
        }
        if (arg0->unk4C != 0) {
            arg0->unk4C--;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/multiplayer/code_0/func_multiplayer_80025794.s")

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
            arg0->unk1C = (((rand() >> 0xF) % 32767) % 271) + 0x1E;
        }
    } else {
        arg0->unk1C--;
    }
    if (var_a2) {
        if (arg0->unk1C == 0) {
            var_a2 = (((rand() >> 0xF) % 32767) % 3) + 1;
            if (var_a2 == 3) {
                var_a2 += (((rand() >> 0xF) % 32767) % 5);
            }
            arg0->unk18 = func_global_asm_807270C0(var_a2, 0);
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

void func_multiplayer_80025CE8(s32 arg0) {
    Actor *temp_s3;
    s32 temp_t4;
    s32 temp_t5;
    s32 playerIndex;
    u32 temp_hi;
    u32 temp_t9;
    PlayerAdditionalActorData *PaaD;
    PlayerAdditionalActorData *PaaD2;
    Actor *player;

    temp_s3 = character_change_array[arg0].player_pointer;
    PaaD = temp_s3->PaaD;
    switch (PaaD->unk264) {
        case 0:
            func_global_asm_806D0468(temp_s3, 2);
            func_global_asm_806F54E0(arg0, 0x8E, 0);
            break;
        case 1:
            for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
                player = character_change_array[playerIndex].player_pointer;
                PaaD2 = player->PaaD;
                if (playerIndex != arg0) {
                    if (PaaD2->unkD4 == 0) {
                        if (player->control_state != 0x84) {
                            func_global_asm_806EB0C0(0x27, temp_s3, playerIndex);
                            PaaD2->unk200 = 0x96;
                        }
                    }
                }
            }
            break;
        case 2:
            PaaD->unk1F0 |= 0x20;
            PaaD->unk1F0 &= 0xF7FFFFFF;
            func_global_asm_806F54E0(arg0, 0x8E, 0);
            break;
        case 3:
            func_global_asm_806846B4(temp_s3->x_position, temp_s3->y_position, temp_s3->z_position, 0.1f, 0.1f, temp_s3, 1);
            break;
        case 4:
            temp_hi = (rand() >> 0xF) % 5;
            switch (temp_hi) {
                case 0:
                    func_global_asm_806D0468(temp_s3, 0);
                    func_global_asm_806F54E0(arg0, 0x8E, 0);
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
                    func_global_asm_806C9974(arg0, 0x40);
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
    Struct80025F84 *temp_v0;

    temp_v0 = func_multiplayer_80025378();
    for (i = 0; i < 4 && temp_v0->unkC[i] != -1; i++) {
        func_global_asm_8063DA40(temp_v0->unkC[i], 0);
    }
}

void func_multiplayer_80025FFC(Struct80025FFC *arg0) {
    s32 temp_a0;
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
        func_global_asm_806F91B4(1, arg1->unk1A4, -10);
    }
}

void func_multiplayer_8002698C(MultiplayerStruct0 *arg0) {
    if (D_global_asm_807552E8 == 2) {
        func_global_asm_806F91B4(1, arg0->unk1A4, -3);
    }
}

void func_multiplayer_800269C8(u8 arg0, s8 arg1) {
    Actor *temp_s0;
    struct_unknown_mp_aad* phi_v1;
    s32 temp_v1;
    s32 sp30;
    PlayerProgress *temp_s1;

    temp_s0 = character_change_array[arg0].player_pointer;
    temp_s1 = &D_global_asm_807FC950[arg0];
    temp_v1 = temp_s1->health + temp_s1->unk2FD + arg1;
    sp30 = temp_s1->unk2FA - temp_v1;
    if ((func_global_asm_806F8AD4(1U, arg0) != 0) && ((temp_v1 <= 0) || (sp30 >= 2))) {
        struct_unknown_mp_aad* aad = func_global_asm_8067ADB4(0x13E)->additional_actor_data;
        aad->unk4C = 1;
        func_global_asm_806F91B4(1, arg0, -0xA);
        if (D_global_asm_807552E8 == 5) {
            func_multiplayer_80025F84();
        }
        func_global_asm_806A5DF0(0x7A, temp_s0->x_position, temp_s0->y_position, temp_s0->z_position, (s32) temp_s0->y_rotation, 1, -1, 0);
        temp_s1->unk2FA = 0;
    }
}

void func_multiplayer_80026B0C(s32 arg0) {
    Actor *player = character_change_array[arg0].player_pointer;
    player->noclip_byte = 0xC;
    switch (D_global_asm_807552E8) {
        case 2:
            func_global_asm_806F91B4(1, arg0, -3);
            break;
        case 5:
            func_global_asm_806F91B4(7, arg0, -0x40);
            // fallthrough
        case 3:
            func_multiplayer_800269C8(arg0, 0);
            break;
        case 4:
            func_global_asm_806F91B4(7, arg0, -1);
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
            player = character_change_array[playerIndex].player_pointer;
            if ((character_change_array[playerIndex].does_player_exist != 0) && (player->control_state != 0x84)) {
                dx = exit->x_pos - player->x_position;
                dy = exit->y_pos - player->y_position;
                dz = exit->z_pos - player->z_position;
                d = (dx * dx) + (dy * dy) + (dz * dz);
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

void func_multiplayer_80026D40(Actor *arg0, s32 arg1) {
    if ((D_global_asm_807552E8 == 4) && (func_multiplayer_80024254(arg1) == 0)) {
        D_global_asm_807FC950[arg1].health = 0;
        arg0->control_state_progress++;
        func_global_asm_806EB0C0(0x5B, NULL, arg1);
        arg0->noclip_byte = 1;
    } else {
        func_global_asm_806C9434(func_multiplayer_80026BD8(arg1));
        character_change_array[arg1].unk2E2 |= 1;
        func_global_asm_806CFF9C(arg0);
    }
}

void func_multiplayer_80026E20(u8 arg0, s8 arg1) {
    Actor *temp_v0;
    PlayerAdditionalActorData *PaaD;
    s32 temp[3];
    PlayerProgress *PP = &D_global_asm_807FC950[arg0];
    CharacterChange *CC = &character_change_array[arg0];

    if ((PP->health + PP->unk2FD) > 0) {
        if (CC->unk2A0 != NULL) {
            temp_v0 = func_global_asm_806C9FD8(CC->unk2A0);
            if (temp_v0 != NULL) {
                if (temp_v0->interactable == 1) {
                    PaaD = temp_v0->PaaD;
                    if ((PP->health + PP->unk2FD + arg1) <= 0) {
                        D_global_asm_807FC950[PaaD->unk1A4].unk2FE[arg0]++;
                    }
                }
            }
        }
    }
    if (D_global_asm_807552E8 == 3 || D_global_asm_807552E8 == 5) {
        func_multiplayer_800269C8(arg0, arg1);
    }
}
