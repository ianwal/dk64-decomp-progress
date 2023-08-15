#include <ultra64.h>
#include "functions.h"


extern s8 D_global_asm_807F6951;
extern s8 D_global_asm_807F6950;

extern f64 D_global_asm_8075A2D0;

void func_global_asm_80699070(s16 *arg0, s16 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_f0;
    f32 temp_f2;

    *arg1 = func_global_asm_80665DE0(arg2, arg4, arg5, arg7);
    temp_f0 = arg5 - arg2;
    temp_f2 = arg7 - arg4;
    *arg0 = (func_global_asm_80611BB4(arg6 - arg3, sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2))) * 2048.0) / D_global_asm_8075A2D0;
}

typedef struct {
    u8 unk0[0x128 - 0x0];
    s16 unk128;
} Struct80699128_arg1;

void func_global_asm_80699128(Gfx *dl, Struct80699128_arg1 *arg1) {
    gSPMatrix(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk88[D_global_asm_807444FC]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, osVirtualToPhysical(&character_change_array[cc_player_index].unk8[D_global_asm_807444FC]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    gSPClearGeometryMode(dl++, G_LIGHTING);
    gDPSetPrimColor(dl++, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    func_global_asm_80614B34(func_global_asm_8065D008(dl, arg1->unk128, 1), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_80699284.s")

void func_global_asm_806998C8(void) {
    func_global_asm_80699284();
}

void func_global_asm_806998E8(void) {

}

void func_global_asm_806998F0(void) {
    func_global_asm_80699958(8, 0);
}

void func_global_asm_80699914(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 1000;
    }
    func_global_asm_80699958(0x1C, 1);
}

// Huge, lots of ActorAnimationState stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_80699958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069A614.s")

// TODO: Needs some more shape on D_global_asm_807FBB70.unk0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069A750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069A7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069AB74.s")

void func_global_asm_8069AFF0(void) {
    func_global_asm_8069AB74();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069B010.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069B3FC.s")

extern s32 D_global_asm_8076A068;

s32 func_global_asm_8069B85C(void) {
    Actor *temp_v1;
    ActorCollision *collision = current_actor_pointer->collision_queue_pointer;

    while (collision) {
        if ((collision->unk0 == 0x8000) && (func_global_asm_8067AF44(collision->collisionSource))) {
            temp_v1 = collision->collisionSource;
            if (temp_v1->interactable & 1) {
                PlayerAdditionalActorData *PaaD = temp_v1->PaaD;
                if ((D_global_asm_8076A068 - PaaD->unk120) < 2U) {
                    return TRUE;
                }
            }
        }
        collision = collision->next;
    }
    return FALSE;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069B908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069CD9C.s")

void func_global_asm_8069B908();
extern f64 D_global_asm_8075A3F8;
extern f64 D_global_asm_8075A400;

/*
// TODO: Just some float nonsense to sort out
void func_global_asm_8069CD9C(void) {
    f32 dx, dy, dz;
    f32 phi_f0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        phi_f0 = (current_actor_pointer->animation_state->scale_x / D_global_asm_8075A3F8) - 1.0;
        if (phi_f0 < 0.0) {
            phi_f0 = 0.0f;
        }
        current_actor_pointer->unk130 = phi_f0 * 80;
        current_actor_pointer->unk131 = phi_f0 * 80;
        current_actor_pointer->draw_distance = 700;
    }
    dz = current_actor_pointer->z_position - character_change_array->look_at_eye_z;
    dx = current_actor_pointer->x_position - character_change_array->look_at_eye_x;
    dy = current_actor_pointer->y_position - character_change_array->look_at_eye_y;
    if (((dx * dx) + (dy * dy) + (dz * dz)) < D_global_asm_8075A400) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
    } else {
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
    func_global_asm_8069B908();
}
*/

void func_global_asm_8069CF54(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk130 = 0x3C;
        current_actor_pointer->unk131 = 0x3C;
        func_global_asm_80689114(0x83, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 1.0f, current_actor_pointer);
    }
    func_global_asm_8069B908();
    if ((!(current_actor_pointer->object_properties_bitfield & 0x10)) && (current_actor_pointer->unk124->unk8_s32 == 1) && isFlagSet(0xFD, FLAG_TYPE_PERMANENT)) {
        current_actor_pointer->unk132 = 4;
    }
}

void func_global_asm_8069D018(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 700;
    }
    func_global_asm_8069B908();
}

void func_global_asm_8069D058(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D078(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D098(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D0B8(void) {
    func_global_asm_8069D018();
}

void func_global_asm_8069D0D8(void) {
    func_global_asm_8069B908();
}

extern s16 D_global_asm_80744490;

// TODO: Put in aaD union
typedef struct {
    void* unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
} GlobalASMStruct_8069D0F8;

void func_global_asm_8069D0F8(u8 arg0, s16 arg1, s16 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7);

u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);
s32 func_global_asm_806FBD5C(s16, s32);

void func_global_asm_8069D0F8(u8 arg0, s16 arg1, s16 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {
    GlobalASMStruct_8069D0F8 *temp_s0;

    if (func_global_asm_80677FA8(ACTOR_TEXT_OVERLAY, 0) != 0) {
        temp_s0 = D_global_asm_807FBB44->additional_actor_data;
        if (arg0 & 0x80) {
            temp_s0->unkA = func_global_asm_806FDB8C(arg0 & 0xff7f, arg3, 2, 160.0f, arg2, 0.0f);
            D_global_asm_807FBB44->unkEE = 1;
            D_global_asm_807FBB44->y_position = arg2;
            return;
        }
        if (arg1 == 0) {
            D_global_asm_807FBB44->x_position = (D_global_asm_80744490 - func_global_asm_806FBD5C(arg0, arg3)) * 2;
        } else {
            D_global_asm_807FBB44->x_position = arg1 * 4;
        }
        D_global_asm_807FBB44->y_position = arg2 * 4;
        D_global_asm_807FBB44->z_position = arg0;
        D_global_asm_807FBB44->unk16A = 0xFF;
        D_global_asm_807FBB44->unk16B = 0xFF;
        D_global_asm_807FBB44->unk16C = 0xFF;
        temp_s0->unk0 = malloc(func_dk64_boot_80002F18(arg3) + 1);
        func_dk64_boot_80002A30(temp_s0->unk0, arg3);
        temp_s0->unk4 = arg4;
        temp_s0->unk6 = arg5;
        temp_s0->unk8 = arg6;
        temp_s0->unk9 = arg7;
    }
}

void func_global_asm_8069D2AC(u8 arg0, s16 arg1, s16 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {
    if ((cc_number_of_players < 2)
        && !gameIsInMainMenuMode()
        && !gameIsInDKTVMode()
        && (gameIsInAdventureMode() || gameIsInDKTheatreMode())) {
        func_global_asm_8069D0F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

Gfx *func_global_asm_8069D358(Gfx *dl, Actor *arg1, s16 arg2, f32 arg3) {
    f32 *spA4;
    f32 sp64[4][4];
    f32 sp24[4][4];

    spA4 = malloc(0x40);
    func_global_asm_8061134C(spA4);
    guScaleF(&sp64[0], arg3, arg3, 1.0f);
    guTranslateF(&sp24[0], arg1->x_position + (2.0 * arg2), arg1->y_position, 0.0f);
    guMtxCatF(&sp64[0], &sp24[0], &sp64[0]);
    guMtxF2L(&sp64[0], spA4);
    gSPMatrix(dl++, spA4, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069D424.s")

s32 func_global_asm_806FE078(void *, u8, s32, f32, f32, f32, f32);

typedef struct {
    u8 unk0[0xA - 0x0];
    u8 unkA;
} AAD_global_asm_8069D930;

s32 func_global_asm_8069D930(Gfx *dl, Actor *arg1) {
    AAD_global_asm_8069D930 *aaD;

    aaD = arg1->additional_actor_data;
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (arg1->unk168++ < 0x64) {
        dl = func_global_asm_806FE078(dl, aaD->unkA, 2, 160.0f, arg1->y_position, 0.0f, 1.0f);
    } else {
        dl = func_global_asm_806FE078(dl, aaD->unkA, 1, 160.0f, arg1->y_position, 0.0f, 1.0f);
    }
    return dl;
}

extern void func_global_asm_8069D424(); // TODO: Proper signature

typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
} AAD_global_asm_8069DA54;

void func_global_asm_8069DA54(void) {
    AAD_global_asm_8069DA54 *temp_a3;

    temp_a3 = current_actor_pointer->additional_actor_data;
    if (current_actor_pointer->unkEE != 0) {
        func_global_asm_8068C350(&func_global_asm_8069D930, current_actor_pointer, 3);
        return;
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk168 = temp_a3->unk4;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (current_actor_pointer->unk168 != 0) {
                current_actor_pointer->unk168--;
            } else {
                current_actor_pointer->control_state = 1;
            }
            break;
        case 1:
            if (current_actor_pointer->control_state_progress != 3) {
                func_global_asm_8068C350(&func_global_asm_8069D424, current_actor_pointer, 3);
            }
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    if ((0xFF - temp_a3->unk8) >= current_actor_pointer->unk15F) {
                        current_actor_pointer->unk15F = current_actor_pointer->unk15F + temp_a3->unk8;
                    } else {
                        current_actor_pointer->unk15F = 0xFF;
                        current_actor_pointer->control_state_progress++;
                        current_actor_pointer->unk168 = temp_a3->unk6;
                    }
                    break;
                case 1:
                    if (current_actor_pointer->unk168 != 0) {
                        current_actor_pointer->unk168--;
                    } else {
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 2:
                    if (current_actor_pointer->unk15F >= temp_a3->unk9) {
                        current_actor_pointer->unk15F -= temp_a3->unk9;
                    } else {
                        current_actor_pointer->control_state_progress++;
                        current_actor_pointer->unk15F = 0;
                    }
                    break;
                case 3:
                    func_global_asm_8061130C(temp_a3->unk0, current_actor_pointer);
                    func_global_asm_806782C0(current_actor_pointer);
                    break;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9DD70/func_global_asm_8069DC10.s")

void func_global_asm_8069DC10(s32 *arg0, s32 *arg1[], u8 arg2);

/*
void func_global_asm_8069DC10(s32 *arg0, s32 *arg1[], u8 arg2) {
    s16 i;
    s16 j;

    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < arg2; j++) {
            arg0[j] = arg1[j][i * arg2];
        }
    }
}
*/

s32 func_global_asm_806FBB9C(s16 textureIndex);

void *func_global_asm_8069DC80(u8 arg0, void *arg1, u8 arg2, u8 arg3, u8 arg4) {
    s32 sp24;

    sp24 = func_global_asm_806FBB9C(arg0 + arg3);
    if (arg1) {
        func_global_asm_8061134C(arg1);
    }
    arg1 = malloc(arg4 << 7);
    func_global_asm_8069DC10(arg1, sp24, arg4);
    func_global_asm_8068842C(current_actor_pointer, arg2, -1);
    func_global_asm_80688370(current_actor_pointer, arg2, 0);
    func_global_asm_80688320(current_actor_pointer, arg2, 0, arg1);
    return arg1;
}

extern u16 D_global_asm_807446C0[];
extern s16 D_global_asm_807FC930[];

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} AAD_global_asm_8069DD40;

void func_global_asm_8069DD40(void) {
    s32 pad[3]; // TODO: Can we get rid of this somehow?
    AAD_global_asm_8069DD40 *temp_s1;
    u16 temp_s0;
    s32 levelIndex;

    temp_s1 = current_actor_pointer->additional_actor_data;
    if (((current_actor_pointer->object_properties_bitfield & 0x10) == 0) || (extra_player_info_pointer->unk1F0 & 0x20000)) {
        levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
        if (levelIndex >= 8) {
            levelIndex = 0;
        }
        temp_s0 = D_global_asm_807FC930[levelIndex];
        temp_s1->unk0 = func_global_asm_8069DC80(0x21, temp_s1->unk0, 0, (temp_s0 / 100), 0x20);
        temp_s1->unk4 = func_global_asm_8069DC80(0x21, temp_s1->unk4, 1, ((temp_s0 % 100) / 10), 0x20);
        temp_s1->unk8 = func_global_asm_8069DC80(0x21, temp_s1->unk8, 2, (temp_s0 % 10), 0x20);
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        extra_player_info_pointer->unk1F0 &= 0xFFFDFFFF;
        if (temp_s0 >= D_global_asm_807446C0[levelIndex]) {
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity = 0;
            current_actor_pointer->noclip_byte = 1;
            func_global_asm_8063DA40(8, 2);
            func_global_asm_8063DA40(9, 0xA);
            func_global_asm_8063DA40(0xA, 0xA);
            func_global_asm_8063DA40(0xB, 0xA);
            func_global_asm_8063DA40(0xD, 0xA);
            func_global_asm_8063DA40(0xC, 0xA);
        }
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_global_asm_8069DF58;

void func_global_asm_8069DF58(void) {
    AAD_global_asm_8069DF58 *temp_v1;

    temp_v1 = current_actor_pointer->additional_actor_data;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        temp_v1->unk0 = func_global_asm_8069DC80(0x14, temp_v1->unk0, 0, (current_actor_pointer->control_state_progress / 10), 0x10);
        temp_v1->unk4 = func_global_asm_8069DC80(0x14, temp_v1->unk4, 1, (current_actor_pointer->control_state_progress % 10), 0x10);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_8069E018(void) {
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_8069E040() {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_80614EBC(current_actor_pointer, 0x299);
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_8069E088(void) {
    s16 phi_s0_2;

    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_80613C48(current_actor_pointer, 0x5ED, 0, 0);
    }
    current_actor_pointer->unk15E = 0x14;
    if (current_actor_pointer->control_state < 0x1E) {
        current_actor_pointer->control_state++;
    }
    if (current_actor_pointer->control_state == 0x1E) {
        phi_s0_2 = 0;
        current_actor_pointer->control_state = 0x64;
        func_global_asm_8070E8DC(1);
        if (!isFlagSet(0x178, FLAG_TYPE_PERMANENT)) { // Wrinkly FTT
            setFlag(0x178, TRUE, FLAG_TYPE_PERMANENT);
        } else {
            phi_s0_2 = (func_global_asm_80600530() * 5) + D_global_asm_807F6951 + 1;
        }
        func_global_asm_8070D8C0(current_actor_pointer, 0x29, phi_s0_2);
    }
    if (D_global_asm_807F6950 != 0) {
        func_global_asm_806782C0(current_actor_pointer);
    }
    current_actor_pointer->animation_state->scale_x = 0.0f;
    current_actor_pointer->animation_state->scale_y = 0.0f;
    current_actor_pointer->animation_state->scale_z = 0.0f;
    func_global_asm_806319C4(current_actor_pointer, 0);
}
