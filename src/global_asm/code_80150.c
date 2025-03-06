#include "common.h"

typedef struct {
    u16 unk0;
    u8 unk2; // Actor Spawner ID
    u8 unk3;
    s16 unk4; // Permanent Flag Index
} GlobalASMStruct47;

extern GlobalASMStruct47 D_global_asm_8074E7A0[];

// stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067B450.s")

/*
// Don't know what this needs, our stack is too big though
u8 func_global_asm_8067B450(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((current_map == D_global_asm_8074E7A0[i].unk0) && (func_global_asm_80688E68(4) == D_global_asm_8074E7A0[i].unk2)) {
            return isFlagSet(D_global_asm_8074E7A0[i].unk4, FLAG_TYPE_PERMANENT);
        }
    }
    return FALSE;
}
*/

// Jumptable, close, regalloc
// https://decomp.me/scratch/2C6WT
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067B4C8.s")

void func_global_asm_80613CA8(Actor*, s32, f32, f32);
extern u8 D_global_asm_807FBDC4;

typedef struct {
    Actor *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 unk15;
} AAD_8067B4C8;

typedef struct {
    u8 unk0[0xB0 - 0x0];
    f32 unkB0;
    f32 unkB4;
    f32 unkB8;
} AAD_8067B4C8_2;

/*
void func_global_asm_8067B4C8(void) {
    s32 i;
    AAD_8067B4C8 *aaD;
    AAD_8067B4C8_2 *aaD2;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->animation_state->unk1C = malloc(2 * sizeof(AnimationStateUnk1C));

        // 1
        gCurrentActorPointer->animation_state->unk1C[0].unk0 = 0x7F;
        gCurrentActorPointer->animation_state->unk1C[0].unk1 = 2;
        gCurrentActorPointer->animation_state->unk1C[0].unk2 = (u32)((gCurrentActorPointer->unk124->unk0 * 65536.0f) / 360.0f);
        gCurrentActorPointer->animation_state->unk1C[0].unk4 = 0;
        gCurrentActorPointer->animation_state->unk1C[0].unk6 = 0;

        // 2
        gCurrentActorPointer->animation_state->unk1C[1].unk0 = 0;

        aaD->unk4 = gCurrentActorPointer->unk124->unk4;
        aaD->unk8 = gCurrentActorPointer->unk124->unk8;
        aaD->unkC = gCurrentActorPointer->unk124->unkC;
        aaD->unk10 = gCurrentActorPointer->unk124->unk10;
        aaD->unk15 = gCurrentActorPointer->unk124->unk14_s32;
        if ((gCurrentActorPointer->unk124->unk18 == 1) && (func_global_asm_8067B450(gCurrentActorPointer) == 0)) {
            gCurrentActorPointer->control_state = 0x14;
            gCurrentActorPointer->noclip_byte = 1;
            gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
            gCurrentActorPointer->shadow_opacity = 0;
        }
        if (current_map == MAP_DK_ISLES_OVERWORLD) {
            gCurrentActorPointer->object_properties_bitfield |= 0x400;
        }
        if (current_map == MAP_CASTLE_KING_KUT_OUT) {
            gCurrentActorPointer->draw_distance = 0x226;
        }
    }
    if (D_global_asm_807FBB70.unk200 == 4) {
        aaD->unk0 = D_global_asm_807FBB70.unk1FC;
        gCurrentActorPointer->control_state = 1;
        aaD->unk14 = 0xA;
        gCurrentActorPointer->noclip_byte = 1;
        aaD->unk0->y_rotation = gCurrentActorPointer->y_rotation;
        playCutscene(NULL, aaD->unk15, 1);
    }
    switch (gCurrentActorPointer->control_state) {
        case 1:
            aaD->unk14--;
            if (aaD->unk14 == 6) {
                func_global_asm_80614D00(gCurrentActorPointer, 1.0f, 0.0f);
                func_global_asm_80613CA8(gCurrentActorPointer, 0x346, 0, 0);
            }
            if (aaD->unk14 == 0) {
                gCurrentActorPointer->control_state = 2;
            }
            break;
        case 2:
            func_global_asm_80679200(aaD->unk0, gCurrentActorPointer, 0x40, 1, 0, NULL);
            aaD2 = aaD->unk0->additional_actor_data;
            aaD2->unkB0 = aaD->unk8;
            aaD2->unkB4 = aaD->unkC;
            aaD2->unkB8 = aaD->unk10;
            func_global_asm_8067AAB8(gCurrentActorPointer, aaD->unk0, gCurrentActorPointer->y_rotation, 0.0f, aaD->unk4);
            func_global_asm_80679290(gCurrentActorPointer, gCurrentActorPointer, 0x800, 2, 0, 0, 0xA);
            func_global_asm_80714998(2);
            func_global_asm_807149B8(1);
            func_global_asm_80714C08(&D_global_asm_8071FBC8, 2.0f, gCurrentActorPointer, 1, 2);
            playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x17, 0xFF, 0x7F, 0x19, 0x1E, 0.3f, 0);
            gCurrentActorPointer->control_state++;
            aaD->unk14 = 4;
            break;
        case 3:
            aaD->unk14--;
            if (aaD->unk14 == 0) {
                gCurrentActorPointer->control_state = 0;
            }
            break;
        case 20:
            for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
                if (D_global_asm_807FBB70.unk258[i] == 1) {
                    gCurrentActorPointer->unk0 = 2;
                    gCurrentActorPointer->control_state = 0x15;
                }
            }
            if (func_global_asm_8067B450(gCurrentActorPointer) != 0) {
                gCurrentActorPointer->shadow_opacity = 0xFF;
                gCurrentActorPointer->object_properties_bitfield |= 0x8000;
                gCurrentActorPointer->control_state = 0;
            }
            break;
        case 21:
            // TODO: Hmm
            gCurrentActorPointer->unk0 = gCurrentActorPointer->unk0 + 0xA;
            if (gCurrentActorPointer->shadow_opacity >= 0xF1) {
                gCurrentActorPointer->object_properties_bitfield |= 0x8000;
                gCurrentActorPointer->control_state = 0;
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
*/

void func_global_asm_8067BA3C(void) {
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->draw_distance = 2000;
    }
    func_global_asm_8067B4C8();
}

// Jumptable, close
// https://decomp.me/scratch/xIcYq
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067BA7C.s")

extern u8 D_global_asm_807FBBA8;

/*
void func_global_asm_8067BA7C(s32 arg0) {
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10) && (arg0 == 0x13)) {
        func_global_asm_80688370(gCurrentActorPointer, 0, 0.5f);
        func_global_asm_806883C8(gCurrentActorPointer, 0, 0);
        func_global_asm_8068839C(gCurrentActorPointer, 0, 0);
        func_global_asm_8068842C(gCurrentActorPointer, 0, -1);
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        case 10:
            playSoundAtActorPosition(gCurrentActorPointer, 0x31, 0xFF, 0x7F, 1);
            func_global_asm_807149B8(0);
            func_global_asm_807149FC(1);
            drawSpriteAtPosition(&D_global_asm_8071FE08, 0.5f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 7.0f, gCurrentActorPointer->z_position);
            func_global_asm_80689114(arg0, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 8.3, gCurrentActorPointer->z_position, 0, 1.0f, gCurrentActorPointer);
            gCurrentActorPointer->control_state++;
            break;
        case 11:
            if (D_global_asm_807FBBA8 != 0) {
                gCurrentActorPointer->control_state = 0x14;
            }
            break;
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
        case 20:
            if (arg0 == 0x95) {
                gCurrentActorPointer->unk168 = 0x1E;
                gCurrentActorPointer->control_state = 0x15;
            }
            break;
        case 21:
            if (gCurrentActorPointer->unk168 != 0) {
                gCurrentActorPointer->unk168--;
            } else {
                gCurrentActorPointer->control_state = 0xA;
            }
            break;
    }
    if (arg0 == 0x13) {
        renderActor(gCurrentActorPointer, 0);
    }
}
*/

void func_global_asm_8067BC68(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BC88(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BCA8(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BCC8(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BCE8(void) {
    func_global_asm_8067BA7C(0x13);
}

void func_global_asm_8067BD08(void) {
    func_global_asm_8067BA7C(0x13);
}

extern u8 D_global_asm_807FBBA8;

void func_global_asm_8067BD28(void) {
    s32 phi_v1;
    PlayerAdditionalActorData *PaaD = gPlayerPointer->PaaD;

    phi_v1 = FALSE;
    if (D_global_asm_807FBBA8 && (PaaD->unk1F0 & 0x200000)) {
        phi_v1 = TRUE;
    }
    if (((gCurrentActorPointer->object_properties_bitfield & 0x10) == 0) || (phi_v1 != 0)) {
        func_global_asm_80689114(0x55, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0, 1.0f, gCurrentActorPointer);
    }
}

void func_global_asm_8067BDB8(void) {
    func_global_asm_8067BA7C(0x95);
    func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
}

typedef struct {
    u8 unk0;
    u8 unk1;
} AAD_8067BDF8;

void func_global_asm_8067BDF8(void) {
    s8 sp1F = 0;
    AAD_8067BDF8 *temp_a1 = gCurrentActorPointer->additional_actor_data;
    func_global_asm_8067BF84(0x13, temp_a1, &temp_a1->unk1, &sp1F);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067BE30.s")

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s8 unk4;
} AAD_global_asm_8067BE30;

/*
void func_global_asm_8067BE30(void) {
    AAD_global_asm_8067BE30 *aaD;
    s16 i;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->draw_distance = 2000;
        aaD->unk0 = 0x1A;
    }
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        switch (D_global_asm_807FBB70.unk258[i]) {
            case 1:
                aaD->unk0 = 0x60;
                break;
            case 2:
                aaD->unk0 = 0;
                break;
            case 3:
                aaD->unk0 = 0x1A;
                break;
        }
        continue;
    }
    if (aaD->unk0) {
        if (func_global_asm_8067BF84(aaD->unk0, &aaD->unk2, &aaD->unk3, &aaD->unk4)) {
            aaD->unk0 = 0x1A;
        }
    } else {
        if (D_global_asm_807FBB70.unk38) {
            aaD->unk4 = 1;
        }
        renderActor(gCurrentActorPointer, 0);
    }
}
*/

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} AAD_8067BF4C;

void func_global_asm_8067BF4C(void) {
    AAD_8067BF4C *temp_v0 = gCurrentActorPointer->additional_actor_data;
    func_global_asm_8067BF84(0x1A, &temp_v0->unk2, &temp_v0->unk3, &temp_v0->unk4);
}

u8 func_global_asm_8067BF84(s16 arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 sp47;
    f32 d;
    f32 minDistance;
    u8 playerIndex;
    f32 dz;
    f32 dx;

    sp47 = 0;
    minDistance = 99999.0f;
    if (gCurrentActorPointer->object_properties_bitfield & 0x10) {
        func_global_asm_80688370(gCurrentActorPointer, 0, 0.5f);
        func_global_asm_806883C8(gCurrentActorPointer, 0, 0);
        func_global_asm_8068839C(gCurrentActorPointer, 0, 0);
        func_global_asm_8068842C(gCurrentActorPointer, 0, -1);
        if ((D_global_asm_807FBBA8 != 0) || (*arg1 != 0) || (*arg3 != 0)) {
            *arg3 = 0;
            sp47 = 1;
        }
        if (sp47 != 0) {
            for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
                if (character_change_array[playerIndex].does_player_exist != 0) {
                    dz = character_change_array[playerIndex].playerPointer->z_position - gCurrentActorPointer->z_position;
                    dx = character_change_array[playerIndex].playerPointer->x_position - gCurrentActorPointer->x_position;
                    
                    d = sqrtf(SQ(dz) + SQ(dx));
                    if (d < minDistance) {
                        minDistance = d;
                    }
                }
            }
            if (minDistance > 12.0) {
                *arg1 = 0;
            } else {
                *arg1 = 1;
                sp47 = 0;
            }
        }
    } else {
        sp47 = 1;
        *arg1 = 0;
        gCurrentActorPointer->y_velocity = -10.0f;
        func_global_asm_806651FC(gCurrentActorPointer);
        func_global_asm_80665564(gCurrentActorPointer, 0);
        if (func_global_asm_80672BD4(gCurrentActorPointer) != 0) {
            *arg2 = 1;
        } else {
            *arg2 = 0;
        }
    }
    if (sp47) {
        func_global_asm_80689114(arg0, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 8.3, gCurrentActorPointer->z_position, 0, 1.0f, gCurrentActorPointer);
        if (gCurrentActorPointer->object_properties_bitfield & 0x10) {
            playSoundAtActorPosition(gCurrentActorPointer, 0x31, 0xFF, 0x7F, 1);
            func_global_asm_807149B8(0);
            func_global_asm_807149FC(1);
            drawSpriteAtPosition(&D_global_asm_8071FE08, 0.5f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 7.0f, gCurrentActorPointer->z_position);
        }
    }
    if (*arg2 != 0) {
        gCurrentActorPointer->y_velocity = -10.0f;
        func_global_asm_806651FC(gCurrentActorPointer);
        func_global_asm_80665564(gCurrentActorPointer, 0);
    }
    renderActor(gCurrentActorPointer, 0);
    return sp47;
}

typedef struct {
    u8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} AAD_global_asm_8067C2B8;

void func_global_asm_8067C2B8(void) {
    AAD_global_asm_8067C2B8 *temp_v0;

    temp_v0 = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk68 |= 4;
        gCurrentActorPointer->object_properties_bitfield |= 0x80;
        temp_v0->unk0 = 0;
        temp_v0->unk8 = 0;
        temp_v0->unk4 = 0.0f;
    }
    if (!(gCurrentActorPointer->unk68 & 4)) {
        gCurrentActorPointer->unkB8 = 0.0f;
    }
    if (D_global_asm_807FBB70.unk90 != 0) {
        temp_v0->unk8 = 1;
    }
    if (D_global_asm_807FBB70.unk91 != 0) {
        if (temp_v0->unk0 == 0) {
            func_global_asm_80604CBC(gCurrentActorPointer, 0x10C, 0, 1, 0, 0xFF, 1.0f, 0);
            temp_v0->unk0 = 1;
        }
        temp_v0->unk4 = D_global_asm_807FBB70.unk94 / 1.1;
        gCurrentActorPointer->unkEE = D_global_asm_807FBB70.unk92;
        if (gCurrentActorPointer->unkB8 < temp_v0->unk4) {
            gCurrentActorPointer->unkB8 += 0.8;
            if (temp_v0->unk4 < gCurrentActorPointer->unkB8) {
                gCurrentActorPointer->unkB8 = temp_v0->unk4;
            }
        } else {
            gCurrentActorPointer->unkB8 -= 1.5;
            if (gCurrentActorPointer->unkB8 < 0.0f) {
                gCurrentActorPointer->unkB8 = 0.0f;
            }
        }
        gCurrentActorPointer->unkFA = 0x64;
        func_global_asm_80665160(gCurrentActorPointer, gCurrentActorPointer->unkEE, gCurrentActorPointer->unkEE);
        func_global_asm_806651FC(gCurrentActorPointer);
        func_global_asm_80665564(gCurrentActorPointer, 0.0f);
        gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
        if (temp_v0->unk8 == 0) {
            gCurrentActorPointer->noclip_byte = 0x3C;
        }
    } else {
        if ((temp_v0->unk0 != 0) && (gCurrentActorPointer->unkB8 == 0.0)) {
            temp_v0->unk0 = 0;
            func_global_asm_80605314(gCurrentActorPointer, 0);
        }
        temp_v0->unk4 = 0.0f;
        if (gCurrentActorPointer->unkB8 < 0.0f) {
            gCurrentActorPointer->unkB8 += 0.8;
            if (temp_v0->unk4 < gCurrentActorPointer->unkB8) {
                gCurrentActorPointer->unkB8 = temp_v0->unk4;
            }
        } else {
            gCurrentActorPointer->unkB8 -= 1.5;
            if (gCurrentActorPointer->unkB8 < 0.0f) {
                gCurrentActorPointer->unkB8 = 0.0f;
            }
        }
        gCurrentActorPointer->unkFA = 0x64;
        func_global_asm_80665160(gCurrentActorPointer, gCurrentActorPointer->unkEE, gCurrentActorPointer->unkEE);
        func_global_asm_806651FC(gCurrentActorPointer);
        func_global_asm_80665564(gCurrentActorPointer, 0.0f);
        if (temp_v0->unk8 == 0) {
            if ((gCurrentActorPointer->unkB8 == 0.0) || !(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
                gCurrentActorPointer->noclip_byte = 2;
            } else {
                gCurrentActorPointer->noclip_byte = 0x3C;
            }
        }
        gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_8067C67C(void) {
    func_global_asm_8067C71C();
}

void func_global_asm_8067C69C(void) {
    func_global_asm_8067C71C();
}

void func_global_asm_8067C6BC(void) {
    func_global_asm_8067C71C();
}

void func_global_asm_8067C6DC(void) {
    func_global_asm_8069B908();
}

void func_global_asm_8067C6FC(void) {
    func_global_asm_8067C71C();
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067C71C.s")

int func_global_asm_8071910C(); // TODO: Signature

void func_global_asm_8067DCC0(void) {
    f32 scale;
    s32 temp_s0;
    s32 i;
    s32 pad;

    scale = gCurrentActorPointer->animation_state->scale_y / 0.15;
    func_global_asm_8060E7EC(0, 0xB4, 0xA);
    func_global_asm_807149B8(0);
    func_global_asm_807149FC(1);
    drawSpriteAtPosition(&D_global_asm_8071FE08, scale * 0.75, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
    playSoundAtActorPosition(gCurrentActorPointer, 0x23, 0xFF, 0x7F, 1);
    for (i = 0; i < 7; i++) {
        temp_s0 = (s32)(func_global_asm_806119A0() / 10000U) % 3;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(2);
        switch (temp_s0) {
            case 0:
                drawSpriteAtPosition(&D_global_asm_8071FE64, scale * 0.25, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
                break;
            case 1:
                drawSpriteAtPosition(&D_global_asm_8071FE88, scale * 0.25, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
                break;
            case 2:
                drawSpriteAtPosition(&D_global_asm_8071FEAC, scale * 0.25, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
                break;
        }
    }
}

void func_global_asm_8067DF44(f32 x, f32 y, f32 z, f32 arg3, u8 arg4, u8 arg5) {
    f64 sp80;
    f32 sp7C;
    f32 randomZOffset;
    f32 randomXOffset;
    f32 randomYOffset;
    s32 i;

    if (arg5 != 0) {
        playSoundAtPosition(x, y, z, 0xF6, 0xFF, 0x7F, 0x19, 0x1E, 0.3f, 0);
    }
    func_global_asm_807149B8(1);
    func_global_asm_8071498C(func_global_asm_8071B89C);
    drawSpriteAtPosition(&D_global_asm_80720120, 0.0f, x, y + 5.0f, z);
    sp80 = arg3;
    sp7C = arg3 * 1.5;
    for (i = 0; i < 5; i++) {
        randomXOffset = (RandClamp(20) - 0xA) * arg3;
        randomYOffset = (RandClamp(20) - 0xA) * arg3;
        randomZOffset = (RandClamp(20) - 0xA) * arg3;
        func_global_asm_8071496C(4);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_8071498C(func_global_asm_8071BB14);
        drawSpriteAtPosition(&D_global_asm_80720340, sp7C, x + randomXOffset, y + randomYOffset, z + randomZOffset);
    }
    func_global_asm_8071496C(4);
    func_global_asm_807149B8(1);
    func_global_asm_807149FC(1);
    func_global_asm_8071498C(func_global_asm_8071BB14);
    drawSpriteAtPosition(&D_global_asm_80720340, sp7C, x, y, z);
    if (arg4 != 0) {
        for (i = 0; i < 0xC; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_807149FC(2);
            func_global_asm_80714950(i + 0x0B020000);
            func_global_asm_8071498C(func_global_asm_8071ABDC);
            func_global_asm_80714998(1);
            drawSpriteAtPosition(&D_global_asm_8072038C, sp80 * 0.5, x, y, z);
        }
    }
}

void func_global_asm_8067E278(u8 arg0, u8 arg1) {
    func_global_asm_8067DF44(
        gCurrentActorPointer->x_position,
        gCurrentActorPointer->y_position,
        gCurrentActorPointer->z_position,
        gCurrentActorPointer->animation_state->scale_y / 0.15,
        arg0,
        arg1
    );
}

void func_global_asm_8067E2E4(Actor *actor, u8 boneIndex, f32 arg2) {
    f32 x, y, z;

    getBonePosition(gCurrentActorPointer, boneIndex, &x, &y, &z);
    func_global_asm_8067DF44(x, y, z, arg2, 0, 1);
}

void func_global_asm_8067E348(void) {
    OtherAdditionalActorData *temp_v0;

    temp_v0 = gCurrentActorPointer->OaaD;
    gCurrentActorPointer->animation_state->scale_x = temp_v0->unkC;
    gCurrentActorPointer->animation_state->scale_y = temp_v0->unkC;
    gCurrentActorPointer->animation_state->scale_z = temp_v0->unkC;
    gCurrentActorPointer->y_position = temp_v0->unk14;
    temp_v0->unk8 = 0;
    temp_v0->unk18 = 0;
    temp_v0->unk10 = temp_v0->unkC;
    gCurrentActorPointer->control_state = 0;
    gCurrentActorPointer->noclip_byte = 2;
    gCurrentActorPointer->object_properties_bitfield &= ~0x200000;
}

void func_global_asm_8067E3D0(void) {
    func_global_asm_8067E348();
    gCurrentActorPointer->control_state = 0x14;
    gCurrentActorPointer->noclip_byte = 1;
    gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
    gCurrentActorPointer->shadow_opacity = 0;
    func_global_asm_806F8D58(5, 0);
}

void func_global_asm_8067E43C(void) {
    s16 i;

    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if ((D_global_asm_807FBB70.unk258[i] == 1) && (D_global_asm_807FBB70.unk278[i]->unk0) == 0xFF) {
            func_global_asm_8067E3D0();
        }
    }
}

void func_global_asm_8067E4D4(void) {
    func_global_asm_8067E784();
    if (gCurrentActorPointer->control_state == 0) {
        func_global_asm_8067E43C();
    }
}

void func_global_asm_8067E510(void) {
    s16 i;

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->animation_state->scale_x *= 1.5;
        gCurrentActorPointer->animation_state->scale_y *= 1.5;
        gCurrentActorPointer->animation_state->scale_z *= 1.5;
        gCurrentActorPointer->draw_distance = 2000;
    }
    if (gCurrentActorPointer->control_state == 0) {
        for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
            if (D_global_asm_807FBB70.unk258[i] == 1) {
                func_global_asm_807149B8(0);
                func_global_asm_807149FC(1);
                drawSpriteAtPosition(&D_global_asm_8071FE08, 0.5f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 7.0f, gCurrentActorPointer->z_position);
                deleteActor(gCurrentActorPointer);
            }
        }
    }
    func_global_asm_8067E784();
}

void func_global_asm_8067E69C(void) {
    func_global_asm_8067E784();
    func_global_asm_8067E43C();
}

void func_global_asm_8067E6C4(void) {
    func_global_asm_8067E784();
}

void func_global_asm_8067E6E4(void) {
    func_global_asm_8067E784();
}

void func_global_asm_8067E704(void) {
    func_global_asm_8067E784();
}

void func_global_asm_8067E724(void) {
    if ((gCurrentActorPointer->object_properties_bitfield & 0x10) == 0) {
        gCurrentActorPointer->draw_distance = 800;
    }
    func_global_asm_8067E784();
}

void func_global_asm_8067E764(void) {
    func_global_asm_8067E784();
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067E784.s")

void func_global_asm_8067FAC8(void) {
    s16 i;

    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if ((D_global_asm_807FBB70.unk258[i] == 1) && (D_global_asm_807FBB70.unk278[i]->unk0 == 1)) {
            func_global_asm_8067DCC0();
            deleteActor(gCurrentActorPointer);
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_8067FB6C.s")

void func_global_asm_80680774(void) {
    if ((character_change_array->unk2C0 != 1) || (((extra_player_info_pointer->unk1F4 & 0x40))) || (((current_character_index[0] >= 5)))) {
        gCurrentActorPointer->unk132 = 4;
        gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
        gCurrentActorPointer->shadow_opacity = 0x7F;
    } else if ((character_change_array->unk2C0 == 1) && (!(extra_player_info_pointer->unk1F0 & 0x40)) && (current_character_index[0] < 5)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x8000;
        gCurrentActorPointer->unk132 = 1;
    }
    if (extra_player_info_pointer->unkCA != 0) {
        gCurrentActorPointer->unk132 = 4;
    }
}

void func_global_asm_8068086C(void) {
    if (current_character_index[0] >= 5) {
        gCurrentActorPointer->unk132 = 4;
        gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
        gCurrentActorPointer->shadow_opacity = 0x7F;
    } else {
        gCurrentActorPointer->object_properties_bitfield |= 0x8000;
        gCurrentActorPointer->unk132 = 1;
    }
    if (extra_player_info_pointer->unkCA != 0) {
        gCurrentActorPointer->unk132 = 4;
    }
}

u8 func_global_asm_80680908(void) {
    u8 phi_v1 = 0x64;
    switch (current_map) {
        case MAP_FACTORY:
            if (func_global_asm_80688E68(gCurrentActorPointer) == 0xD
            || func_global_asm_80688E68(gCurrentActorPointer) == 0xF) {
                phi_v1 = 2;
            }
            break;
        case MAP_FUNGI_DK_BARN:
            if (func_global_asm_80688E68(gCurrentActorPointer) == 3) {
                phi_v1 = 2;
            }
            break;
        case MAP_FUNGI:
            if (func_global_asm_80688E68(gCurrentActorPointer) == 0x12) {
                phi_v1 = 2;
            }
            break;
        case MAP_AZTEC_LOBBY:
        case MAP_DK_ISLES_SNIDES_ROOM:
            phi_v1 = 2;
            break;
    }
    return phi_v1;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806809F0.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
} AAD_global_asm_80681B14;

extern s16 D_global_asm_8074E7E0[];

void func_global_asm_80681B14(void) {
    AAD_global_asm_80681B14 *aaD;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        if (isFlagSet(0x302, FLAG_TYPE_PERMANENT)) {
            deleteActor(gCurrentActorPointer);
            return;
        }
    }
    func_global_asm_806809F0();
    if ((gCurrentActorPointer->control_state == 0xC) && (aaD->unkD < 3)) {
        setFlag(D_global_asm_8074E7E0[aaD->unkA], TRUE, FLAG_TYPE_TEMPORARY);
        func_global_asm_8067DCC0();
        deleteActor(gCurrentActorPointer);
    }
}

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
} AAD_global_asm_80681BD8;

void func_global_asm_80681BD8(void) {
    AAD_global_asm_80681BD8 *aaD;
    s32 sp28;
    s32 i;
    s32 var_s1;

    aaD = gCurrentActorPointer->additional_actor_data;
    func_global_asm_806809F0();
    if (!isFlagSet(PERMFLAG_PROGRESS_TRAINING_SPAWNED, FLAG_TYPE_PERMANENT)) {
        gCurrentActorPointer->control_state = 0x14;
        gCurrentActorPointer->noclip_byte = 1;
        gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
        gCurrentActorPointer->shadow_opacity = 0;
    } else {
        if (!isFlagSet(PERMFLAG_PROGRESS_ALL_TRAINING_COMPLETE, FLAG_TYPE_PERMANENT)) {
            if (gCurrentActorPointer->control_state == 0xB) {
                var_s1 = 0;
                i = 0;
                do {
                    var_s1 += isFlagSet(i + PERMFLAG_ITEM_MOVE_DIVING, FLAG_TYPE_PERMANENT) != FALSE;
                    i++;
                } while (i < 4);
                if (var_s1 == 4) {
                    playCutscene(gPlayerPointer, 3, 1);
                    setFlag(PERMFLAG_PROGRESS_ALL_TRAINING_COMPLETE, TRUE, FLAG_TYPE_PERMANENT);
                }
            }
        }
        switch (aaD->unk6) {
            case 0xB1:
                sp28 = PERMFLAG_ITEM_MOVE_DIVING;
                break;
            case 0xB6:
                sp28 = PERMFLAG_ITEM_MOVE_VINES;
                break;
            case 0xB4:
                sp28 = PERMFLAG_ITEM_MOVE_ORANGETHROWING;
                break;
            case 0xB5:
                sp28 = PERMFLAG_ITEM_MOVE_BARRELTHROWING;
                break;
        }
        if (isFlagSet(sp28, FLAG_TYPE_PERMANENT) != FALSE) {
            aaD->unkC = 1;
            aaD->unkA = 0;
            if (gCurrentActorPointer->control_state == 0) {
                gCurrentActorPointer->control_state = 0x14;
                gCurrentActorPointer->noclip_byte = 1;
                gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
                gCurrentActorPointer->shadow_opacity = 0;
            }
        } else {
            if (gCurrentActorPointer->control_state == 0x14) {
                gCurrentActorPointer->noclip_byte = 2;
                gCurrentActorPointer->control_state = 0x15;
            }
        }
    }
    if ((gCurrentActorPointer->control_state == 0xC) && (aaD->unkD < 3)) {
        func_global_asm_8067DCC0();
        deleteActor(gCurrentActorPointer);
    }
}

s32 func_global_asm_8067B450(Actor *);
extern s16 D_global_asm_80750390;

typedef struct {
    s16 unk0;
    Actor *unk4;
} AAD_80681E18;

extern s32 D_global_asm_807FBB68;

void func_global_asm_80681E18(void) {
    AAD_80681E18 *aaD;
    s16 i;
    Actor *temp_a1;
    s32 pad3;
    s32 moves;
    s32 pad2;
    s32 pad;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->floor = 99999.0f;
        func_global_asm_80667110(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, &gCurrentActorPointer->floor);
        if (gCurrentActorPointer->unk124->unk0_s32 == 1) {
            if (func_global_asm_8067B450(gCurrentActorPointer) == 0) {
                gCurrentActorPointer->control_state = 0x14;
                gCurrentActorPointer->noclip_byte = 1;
                gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
                gCurrentActorPointer->shadow_opacity = 0;
            }
        }
    }
    if ((gCurrentActorPointer->control_state == 0) && (D_global_asm_807FBB70.unk200 == 4)) {
        aaD->unk0 = 0xA;
        gCurrentActorPointer->control_state = 1;
        gCurrentActorPointer->noclip_byte = 1;
        aaD->unk4 = D_global_asm_807FBB70.unk1FC;
        gCurrentActorPointer->object_properties_bitfield |= 0x200000;
        switch (current_map) {
            case MAP_HELM:
            case MAP_KROOL_BARREL_DIDDY_ROCKETBARREL_GAME:
            case MAP_KROOL_FIGHT_DIDDY_PHASE:
                break;
            default:
                playSong(MUSIC_72_ROCKETBARREL_BOOST, 1.0f);
                break;
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (current_character_index[0] < 5) {
                moves = D_global_asm_807FC950->character_progress[current_character_index[0]].moves;
            }
            if ((gPlayerPointer->unk58 == ACTOR_DIDDY) && (moves >= 2)) {
                gCurrentActorPointer->object_properties_bitfield |= 0x8000;
                gCurrentActorPointer->unk132 = 1;
            } else {
                gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
                gCurrentActorPointer->shadow_opacity = 0x78;
                gCurrentActorPointer->unk132 = 2;
            }
            func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0xC, 0xC, 1, 0x64, 0x78, 0, 1.0f);
            break;
        case 1:
            aaD->unk0--;
            if (aaD->unk0 == 0) {
                playSoundAtActorPosition(gCurrentActorPointer, 0x1C6, 0xFF, 0x7F, 0);
                gCurrentActorPointer->control_state = 2;
                func_global_asm_806F8BC4(5, D_global_asm_807FBB68 & 2 ? 0 : 1, 0);
            }
            break;
        case 2:
            func_global_asm_8067DCC0();
            gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
            gCurrentActorPointer->shadow_opacity = 0;
            func_global_asm_80679200(aaD->unk4, gCurrentActorPointer, 0x40, 1, 0, NULL);
            temp_a1 = aaD->unk4;
            func_global_asm_8067AAB8(gCurrentActorPointer, temp_a1, temp_a1->y_rotation, D_global_asm_80750390, 0);
            func_global_asm_806C7BAC(aaD->unk4, gCurrentActorPointer);
            extra_player_info_pointer->unk1A3 = 1;
            gCurrentActorPointer->control_state = 3;
            break;
        case 3:
            if (D_global_asm_807FBB70.unk0 != 0) {
                gCurrentActorPointer->object_properties_bitfield |= 0x8000;
                gCurrentActorPointer->noclip_byte = 2;
                gCurrentActorPointer->object_properties_bitfield &= 0xFFDFFFFF;
                gCurrentActorPointer->control_state = 0;
            }
            break;
        case 20:
            for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
                if (D_global_asm_807FBB70.unk258[i] == 1) {
                    gCurrentActorPointer->noclip_byte = 2;
                    gCurrentActorPointer->control_state = 0x15;
                }
            }
            break;
        case 21:
            gCurrentActorPointer->shadow_opacity += 0xA;
            if (gCurrentActorPointer->shadow_opacity >= 0xF1) {
                gCurrentActorPointer->object_properties_bitfield |= 0x8000;
                gCurrentActorPointer->control_state = 0;
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806822FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80682AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80682DF4.s")

void func_global_asm_80682DF4(Actor *, u16 *, s32);

/*
extern u16 D_global_asm_807FBB54[];
void func_global_asm_80682DF4(Actor *arg0, u16 *arg1, s32 arg2) {
    playActorAnimation(arg0, D_global_asm_807FBB54[(((arg2 * 7) + *arg1) - 2)]);
}
*/
void func_global_asm_80682AB4(void *);

typedef struct {
    s32 unk0;
    s16 unk4;
    s8 unk6;
    u8 unk7;
    Actor *unk8[5];
    Actor *unk1C;
} Struct80682E38_arg0;

typedef struct {
    s16 unk0;
} AAD_global_asm_80682E38;

void func_global_asm_80682E38(Struct80682E38_arg0 *arg0) {
    s32 var_a2;
    s16 modelIndex;
    Actors actorIndex;
    s32 i;
    AAD_global_asm_80682E38 *aaD;

    spawnActor(ACTOR_SPOTLIGHT, 0xA8);
    arg0->unk1C = gLastSpawnedActor;
    gLastSpawnedActor->x_position = (func_global_asm_80612794(gCurrentActorPointer->y_rotation) * 35.0f) + gCurrentActorPointer->x_position;
    gLastSpawnedActor->y_position = (gCurrentActorPointer->y_position - 10.0f) - 2.0f;
    gLastSpawnedActor->z_position = (func_global_asm_80612790(gCurrentActorPointer->y_rotation) * 35.0f) + gCurrentActorPointer->z_position;
    for (i = 0; i < 5; i++) {
        if (isFlagSet(func_global_asm_805FF018(gCurrentActorPointer->unk58, i), FLAG_TYPE_PERMANENT) != FALSE) {
            actorIndex = ACTOR_TAGBARREL_KONG;
            modelIndex = D_global_asm_8074E814[i].unk0;
        } else {
            actorIndex = ACTOR_TAGBARREL_LOCKED;
            modelIndex = 0xD2;
        }
        spawnActor(actorIndex, modelIndex);
        arg0->unk8[i] = gLastSpawnedActor;
        gLastSpawnedActor->y_rotation = gCurrentActorPointer->y_rotation;
        gLastSpawnedActor->object_properties_bitfield |= 0x40000000;
        if (actorIndex == ACTOR_TAGBARREL_KONG) {
            aaD = gLastSpawnedActor->additional_actor_data;
            aaD->unk0 = D_global_asm_8074E814[i].unk2;
            func_global_asm_806F09F0(gLastSpawnedActor, aaD->unk0);
            if (i == arg0->unk6) {
                var_a2 = 0x8B;
            } else {
                var_a2 = 0x8A;
            }
            func_global_asm_80682DF4(gLastSpawnedActor, aaD, var_a2);
        } else {
            RaceAdditionalActorData2 *RaaD2 = gLastSpawnedActor->RaaD2;
            RaaD2->unk0 = i;
        }
    }
    func_global_asm_80682AB4(arg0);
}

typedef struct {
    s32 unk0[5];
} Struct8074E834;

extern Struct8074E834 D_global_asm_8074E834;

typedef struct {
    u8 unk0;
} AAD_global_asm_8068304C;

void func_global_asm_8068304C(void) {
    Struct8074E834 sp2C;
    AAD_global_asm_8068304C *sp28;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        sp2C = D_global_asm_8074E834;
        sp28 = gCurrentActorPointer->additional_actor_data;
        gCurrentActorPointer->object_properties_bitfield |= 0x1000;
        func_global_asm_8068842C(gCurrentActorPointer, 0, 1);
        func_global_asm_80688460(gCurrentActorPointer, 0, 1);
        func_global_asm_806883F4(gCurrentActorPointer, 0, sp2C.unk0[sp28->unk0], 0);
        playActorAnimation(gCurrentActorPointer, 0x329);
    }
    gCurrentActorPointer->unk16D = gCurrentActorPointer->unk15F;
    gCurrentActorPointer->y_rotation += 0x32;
    gCurrentActorPointer->y_rotation &= 0xFFF;
    renderActor(gCurrentActorPointer, 0);
}

typedef struct {
    u16 unk0;
    u16 unk2;
    void *unk4; // TODO: Function pointer
    s32 unk8;
} AAD_80683158;

void func_global_asm_806F22A8(void);
void func_global_asm_806F1EB0(void);

void func_global_asm_806C8220(s32, s32, s32);

void func_global_asm_80683158(void) {
    s32 sp3C;
    AAD_80683158 *aaD;
    s32 (*temp_v0_3)(Actor *, AnimationStateUnk1C *, s32 *);

    sp3C = 0;
    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x1000;
        gCurrentActorPointer->animation_state->unk1C = malloc(32 * sizeof(AnimationStateUnk1C));
        func_global_asm_80611690(gCurrentActorPointer->animation_state->unk1C);
        func_global_asm_806C8220(0, gCurrentActorPointer->unk178, aaD->unk0);
        switch (aaD->unk0) {
            case 2:
                aaD->unk4 = func_global_asm_806F1C04;
                break;
            case 3:
                aaD->unk4 = func_global_asm_806F22A8;
                break;
            case 5:
                aaD->unk4 = func_global_asm_806F1EB0;
                break;
        }
    } else {
        temp_v0_3 = aaD->unk4;
        if (temp_v0_3 != NULL) {
            temp_v0_3(gCurrentActorPointer, gCurrentActorPointer->animation_state->unk1C, &sp3C);
        }
    }
    gCurrentActorPointer->animation_state->unk1C[sp3C].unk0 = 0;
    gCurrentActorPointer->unk16D = gCurrentActorPointer->unk15F;
    gCurrentActorPointer->y_rotation = func_global_asm_80665DE0(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position);
    if ((func_global_asm_8072881C(0, &aaD->unk8) != 0) && (((aaD->unk0 == 3)) || (aaD->unk0 == 5))) {
        func_global_asm_8072881C(0x81, &aaD->unk8);
    }
    renderActor(gCurrentActorPointer, 0);
}

s32 func_global_asm_806832F4(Actors arg0, s32 arg1) {
    s32 pad;
    s32 sp28;
    s32 flagIsSet;
    s32 flagIndex;

    flagIsSet = FALSE;
    switch (current_map) {
        default:
            return FALSE;
        case MAP_JAPES:
        case MAP_FACTORY:
        case MAP_GALLEON:
        case MAP_AZTEC:
        case MAP_TROFF_N_SCOFF:
        case MAP_FUNGI:
            sp28 = func_global_asm_805FEF10(&flagIndex);
            if (sp28 != 0) {
                flagIsSet = isFlagSet(flagIndex, FLAG_TYPE_PERMANENT);
                if ((arg1 != 0) && (!flagIsSet)) {
                    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
                    playCutscene(gPlayerPointer, 0x19, 4);
                    gCurrentActorPointer->noclip_byte = 1;
                    gCurrentActorPointer->control_state_progress = 0xB;
                }
            }
            return sp28 != 0 && !flagIsSet;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806833DC.s")

/*
// Needs some PaaD untangling I think
// Switch case for control_state_progress?
void func_global_asm_806833DC(YetAnotherAdditionalActorData *arg0) {
    void *sp34;
    void *sp30;
    s32 sp28;
    s32 sp20;
    s16 temp_v0_3;
    s16 temp_v0_4;
    u16 temp_v0_2;
    u8 temp_v0;
    Actor *temp_a0;
    void *temp_a1;
    Actor *temp_t1;
    void *temp_v0_5;
    s32 phi_v0;
    s32 phi_a1;

    temp_v0 = gCurrentActorPointer->control_state_progress;
    if (temp_v0 != 0) {
        if (temp_v0 != 1) {
            if (temp_v0 != 0xA) {
                if ((temp_v0 == 0xB) && (func_global_asm_8061CB50(&gCurrentActorPointer) == 0)) {
                    gCurrentActorPointer->noclip_byte = 2;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            } else {
                goto block_6;
            }
        } else {
            temp_v0_2 = arg0->unk4;
            if (temp_v0_2 != 0) {
                arg0->unk4 = temp_v0_2 - 1;
                return;
            }
            temp_a0 = arg0->unk0;
            temp_v0_3 = temp_a0->unk12C;
            temp_a1 = temp_a0->unk174;
            phi_v0 = temp_v0_3;
            if (temp_v0_3 == -1) {
                phi_v0 = 0;
            }
            sp28 = phi_v0;
            sp34 = temp_a0;
            sp30 = temp_a1;
            func_global_asm_806C93E4(temp_a0, temp_a1, &gCurrentActorPointer);
            func_global_asm_806C9304(arg0->unk0, temp_a1);
            sp20 = phi_v0;
            func_global_asm_80659620(&arg0->unk2C, &arg0->unk30, &arg0->unk34, phi_v0);
            func_global_asm_80659670(1.0f, 1.0f, 1.0f, sp20);
            gCurrentActorPointer->y_rotation = arg0->unk22;
            gCurrentActorPointer->noclip_byte = 1;
            temp_v0_4 = sp34->unk5A;
            global_properties_bitfield &= 0xFFFCFFCF;
            arg0->unk6 = 0;
            if (temp_v0_4 != D_global_asm_8074E814[arg0->unk6].unk2) {
                do {
                    arg0->unk6 = arg0->unk6 + 1;
                } while (temp_v0_4 != D_global_asm_8074E814[arg0->unk6].unk2);
            }
            arg0->unk7 = arg0->unk6;
            phi_a1 = arg0->unk6;
            if (current_map != MAP_HELM) {
                playSong(MUSIC_101_TAG_BARREL_ALL_OF_THEM, 1.0f);
                func_global_asm_80602CE0(0x65, 0x7E - *(&D_global_asm_8074E848 + (arg0->unk6 * 4)), 1);
                phi_a1 = arg0->unk6;
            }
            setFlag(func_global_asm_805FF018(gCurrentActorPointer->unk58, phi_a1), TRUE, FLAG_TYPE_PERMANENT);
            func_global_asm_80682E38(arg0);
            func_global_asm_80627878(sp30->unk104);
            arg0->unk38 = sp34->unkE6;
            sp34->unkE6 = gCurrentActorPointer->y_rotation;
            func_global_asm_8060DEC8(); // saveTheGame()
            playCutscene(gCurrentActorPointer, 0xE, 0xC);
            func_global_asm_8061B650(sp30->unk104);
            func_global_asm_806FB218();
            gCurrentActorPointer->control_state = 1;
            gCurrentActorPointer->control_state_progress = 0;
        }
    } else {
block_6:
        if (D_global_asm_807FBB70.unk200 == 4) {
            temp_t1 = D_global_asm_807FBB70.unk1FC;
            arg0->unk0 = temp_t1;
            temp_t1->unk144 = 1;
            temp_v0_5 = arg0->unk0->unk174;
            temp_v0_5->unk1F0 |= 0x20000000;
            gCurrentActorPointer->control_state_progress = 1;
            arg0->unk4 = 2;
            arg0->unk3C = 0;
        }
    }
}
*/

// Doable, might need some structs?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_806836D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80683A80.s")

/*
// TODO: This is probably wrong
typedef struct {
    Actor *unk8;
} Struct80683A80_arg0;

extern s32 D_global_asm_8074E87C[];

// TODO: sus
s32 func_global_asm_80683A80(Struct80683A80_arg0 *arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = 0;
    if ((arg0[arg1 + 2].unk8->unk58 ^ 0x13C) == 0) {
        var_a2 = getTextString(2, D_global_asm_8074E87C[arg1 - 8], 1);
    }
    return var_a2;
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_80150/func_global_asm_80683AD8.s")

void func_global_asm_8068408C(Actor *arg0) {
    s32 kongIndex;

    for (kongIndex = 0; kongIndex < 5; kongIndex++) {
        if (isFlagSet(func_global_asm_805FF018(arg0->unk58, kongIndex), FLAG_TYPE_PERMANENT)) {
            func_global_asm_8068A764(arg0, D_global_asm_8074E814[kongIndex].unk4);
        }
    }
}

// Tag barrel
void func_global_asm_8068412C(void) {
    YetAnotherAdditionalActorData *YaaD;

    YaaD = gCurrentActorPointer->YaaD;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        YaaD->unk22 = gCurrentActorPointer->y_rotation;
        YaaD->unk24 = gCurrentActorPointer->y_position;
        gCurrentActorPointer->unk146 = 0;
        gCurrentActorPointer->unk15E = 0;
        func_global_asm_80714998(2);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_807149A8(1000);
        func_global_asm_80714A28(4);
        drawSpriteAtPosition(
            &D_global_asm_8071FC8C,
            1.3f,
            gCurrentActorPointer->x_position,
            gCurrentActorPointer->y_position + 13.0,
            gCurrentActorPointer->z_position
        );
        if (func_global_asm_80689F2C()) {
            gCurrentActorPointer->draw_distance = 2000;
        } else {
            gCurrentActorPointer->draw_distance = 350;
        }
        gCurrentActorPointer->floor = gCurrentActorPointer->y_position;
        func_global_asm_80665564(gCurrentActorPointer, 0.0f);
        gCurrentActorPointer->locked_to_pad = 0;
        gCurrentActorPointer->object_properties_bitfield |= 2;
    }
    func_global_asm_8068408C(gCurrentActorPointer);
    func_global_asm_80680774();
    func_global_asm_8067ACB4(gCurrentActorPointer);

    switch (gCurrentActorPointer->control_state) {
        case 0:
            if (YaaD->unk4) {
                YaaD->unk4--;
                if (!YaaD->unk4) {
                    gCurrentActorPointer->noclip_byte = 2;
                }
            } else {
                func_global_asm_806833DC(YaaD);
            }
            if (gCurrentActorPointer->control_state_progress == 0xA) {
                if ((gPlayerPointer->unk6A & 4) || func_global_asm_806C9D7C()) {
                    gCurrentActorPointer->control_state_progress = 0;
                } else {
                    if ((gPlayerPointer->locked_to_pad != 1) && (gPlayerPointer->unk6A & gPlayerPointer->unk6C & 1)) {
                        func_global_asm_806832F4(gPlayerPointer->unk58, 1);
                    }
                }
            }
            break;
        case 1:
            func_global_asm_806836D0(YaaD);
            addActorToTextOverlayRenderArray(func_global_asm_80683AD8, gCurrentActorPointer, 3);
            break;
        case 2:
            if (YaaD->unk4) {
                YaaD->unk4--;
            } else {
                func_global_asm_8067AAB8(gCurrentActorPointer, YaaD->unk0, YaaD->unk38, 180.0f, 0x46);
                func_global_asm_80679200(YaaD->unk0, gCurrentActorPointer, 0x40, 1, 0, 0);
                func_global_asm_806FB2B8();
                gCurrentActorPointer->control_state = 0;
                gCurrentActorPointer->control_state_progress = 0;
                if (func_global_asm_806832F4(gPlayerPointer->unk58, 0)) {
                    gCurrentActorPointer->control_state_progress = 0xA;
                }
                YaaD->unk4 = 0x1E;
            }
            break;
    }
    func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x64, 0x78, 0, 1.0f);
    if (gCurrentActorPointer->control_state != 1) {
        gCurrentActorPointer->y_rotation += 0x32;
        gCurrentActorPointer->y_rotation &= 0xFFF;
        gCurrentActorPointer->y_position = func_global_asm_80612794(YaaD->unk28) * 5.0f + YaaD->unk24;
        YaaD->unk28 += 0x32;
        YaaD->unk28 &= 0xFFF;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806844EC(void) {
    func_global_asm_8068412C();
}

void func_global_asm_8068450C(void) {
    func_global_asm_8068412C();
}

void func_global_asm_8068452C(void) {
    func_global_asm_8068412C();
}
