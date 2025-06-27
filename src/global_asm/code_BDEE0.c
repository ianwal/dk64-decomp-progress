#include "common.h"

extern u8 D_global_asm_807FBD70;
extern u8 D_global_asm_80750628[];

void func_global_asm_8072A450(void);
void func_global_asm_8072C918(s16, s16, s16);
extern s16 D_global_asm_80770628[];
extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];

typedef struct {
    s16 unk0;
} RoboKremAAD2;

void func_global_asm_806B91E0(void) {
    u16 sp36;
    RoboKremAAD2 *aaD;
    AnimationStateUnk1C *temp_v0;
    f32 temp_f0;
    u8 temp_v0_8;
    s16 temp_v1;

    sp36 = 0;
    aaD = gCurrentActorPointer->AAD_as_array[1];
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_8072B79C(0x321, 0x322, 0x323);
        func_global_asm_80724CA4(0x11, 1);
        func_global_asm_8066EA90(gCurrentActorPointer, 4);
        aaD->unk0 = D_global_asm_807FDC9C->unkA_s16 * 0xA;
    }
    if (((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) && (gCurrentActorPointer->control_state != 0x37)) {
        D_global_asm_807FDC90->unk2C = 5000;
        func_global_asm_8072D714(D_global_asm_807FBB70.unk1FC, 0x327);
        gCurrentActorPointer->unk138 &= ~0x8000;
    } else {
        if (D_global_asm_807FBB70.unk200 == 4) {
            func_global_asm_8072DEA8(0x325, 0x31U, D_global_asm_807FBB70.unk1FC);
        } else if (D_global_asm_807FBB70.unk200 == 5) {
            func_global_asm_8072DEA8(0x326, 0x31U, D_global_asm_807FBB70.unk1FC);
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x18:
        switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                gCurrentActorPointer->control_state_progress++;
                D_global_asm_807FDC90->unk2C = 0xD;
            }
            gCurrentActorPointer->animation_state->unk1C->unk6_u16 += 0x7D0;
            break;
        case 1:
            if (D_global_asm_807FDC90->unk2C) {
                D_global_asm_807FDC90->unk2C--;
                break;
            }
            if (D_global_asm_807FDC90->unk2E) {
                gCurrentActorPointer->control_state_progress = 0;
                D_global_asm_807FDC90->unk2E--;
                D_global_asm_807FDC90->unk2C = 0xA;
                playSoundAtActorPosition(gCurrentActorPointer, 0x1BA, 0x96U, 0x7F, 0U);
                break;
            }
            func_global_asm_8072DE44(0x322);
            break;
        }
        break;
    case 0x31:
        if ((gCurrentActorPointer->control_state_progress) || (gCurrentActorPointer->animation_state->unk0->unk24 == 0.0f)) {
            func_global_asm_8072DE44(0x322);
        }
        func_global_asm_8072AB74(0U, 0.0f, 0.0f, 0x4300U, 0.0f);
        break;
    case 0x11:
        switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            func_global_asm_8072B324(gCurrentActorPointer, 0);
            playActorAnimation(gCurrentActorPointer, 0x321);
            gCurrentActorPointer->control_state_progress++;
        case 1:
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200U, 0.0f);
            if (gCurrentActorPointer->unkB8 < 1.0f) {
                gCurrentActorPointer->control_state_progress++;
                break;
            }
            break;
        case 2:
            func_global_asm_8072A450();
            if (RandChance(0.005)) {
                func_global_asm_8072DE44(0x322);
            }
            break;
        }
        break;
    case 0x27:
        gCurrentActorPointer->animation_state->unk1C->unk6_u16 -= (gCurrentActorPointer->unkB8 * 50.0f);
        func_global_asm_8072AB74(0x23U, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0x200U, 0.0f);
        switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            func_global_asm_8072B324(gCurrentActorPointer, 0);
            playActorAnimation(gCurrentActorPointer, 0x324);
            gCurrentActorPointer->control_state_progress = 1;
            break;
        case 2:
            gCurrentActorPointer->unk132 = 2;
            break;
        case 3:
            gCurrentActorPointer->unk132 = 1;
            break;
        case 4:
            func_global_asm_8072DE44(0x322);
            break;
        }
        break;
    case 0x1:
        if (func_global_asm_8072E54C()) {
            gCurrentActorPointer->control_state = 0x11;
            gCurrentActorPointer->control_state_progress = 0;
        }
    case 0x23:
        if (D_global_asm_807FBB70.unk200 == 2) {
            if (func_global_asm_8072DE10(0x2710U) != 0) {
                gCurrentActorPointer->control_state = 0x27;
                gCurrentActorPointer->control_state_progress = 0;
            }
        }
    case 0x10:
        if ((gCurrentActorPointer->control_state != 0x11) && (gCurrentActorPointer->control_state != 0x27)) {
            if (gCurrentActorPointer->control_state_progress == 0) {
                aaD->unk0 = D_global_asm_807FDC9C->unkA_s16 * 2;
                gCurrentActorPointer->control_state_progress = 1;
            }
            if (aaD->unk0 != 0) {
                aaD->unk0--;
            } else {
                sp36 = 0x20;
                func_global_asm_8072B330(0U);
                if (gCurrentActorPointer->unkB8 != 0.0f) {
                    gCurrentActorPointer->unkB8 = gCurrentActorPointer->unkB8 - 1.0f;
                } else {
                    gCurrentActorPointer->control_state = 0x18;
                    gCurrentActorPointer->control_state_progress = 0;
                    gCurrentActorPointer->control_state_progress = 1;
                    D_global_asm_807FDC90->unk2C = 0;
                    D_global_asm_807FDC90->unk2E = 4;
                }
            }
        }
        gCurrentActorPointer->animation_state->unk1C->unk6_u16 -= (gCurrentActorPointer->unkB8 * 50.0f);
        func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, sp36, 0.0f);
        break;
    case 0x2:
    case 0x3:
    case 0x7:
    case 0x35:
        func_global_asm_8072AB74(gCurrentActorPointer->control_state, (f32) D_global_asm_807FDC90->unkA, (f32) D_global_asm_807FDC90->unkE, 0U, 0.0f);
        break;
    case 0x37:
        gCurrentActorPointer->animation_state->unk1C->unk6_u16 -= D_global_asm_807FDC90->unk2C;
        if (D_global_asm_807FDC90->unk2C != 0) {
            D_global_asm_807FDC90->unk2C -= 0x32;
        }
        switch (gCurrentActorPointer->control_state_progress) {
        case 0:
            func_global_asm_8072AB74(0x37U, 0.0f, 0.0f, 0x200U, 0.0f);
            break;
        case 1:
            func_global_asm_806A5C60(gCurrentActorPointer);
            gCurrentActorPointer->control_state_progress += 1;
        case 2:
            func_global_asm_8072AB74(0x37U, 0.0f, 0.0f, 0x200U, 0.0f);
            func_global_asm_8072DC7C(8U);
            break;
        case 3:
            gCurrentActorPointer->control_state = 0x40;
            break;
        }
        break;
    case 0x40:
        break;
    default:
        func_global_asm_8072B7CC(0x322);
        break;
    }
    if (gCurrentActorPointer->unkB8 != 0.0f) {
        if (gCurrentActorPointer->unk70 == -1) {
            func_global_asm_80604CBC(gCurrentActorPointer, 0x10A, 0U, 1U, 1U, 0xFFU, 1.0f, 0);
        } else {
            temp_v0_8 = D_global_asm_80770628[gCurrentActorPointer->unk70];
            D_global_asm_80770B68[temp_v0_8] = MAX(0.0, (gCurrentActorPointer->unkB8 * 0.6) / 40.0) + 0.4;
            D_global_asm_80770BC0[temp_v0_8] = 1.0f;
        }
    } else {
        func_global_asm_80605314(gCurrentActorPointer, 1U);
    }
    switch (gCurrentActorPointer->control_state) {
    case 0x31:
    case 0x37:
    case 0x40:
        break;
    case 0x2:
    case 0x3:
        func_global_asm_8072D13C(gCurrentActorPointer->control_state, 1);
    default:
        func_global_asm_8072C918(0x57E4, 0x322, 0x323);
        break;
    }
    renderActor(gCurrentActorPointer, 0U);
}

void func_global_asm_806B9CB0(void) {
    initializeCharacterSpawnerActor();
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806B9CE0(u8 arg0, s8 yOffset) {
    switch (arg0) {
        case 0:
            func_global_asm_8071498C(func_global_asm_8071720C);
            break;
        case 1:
            func_global_asm_80714950(-0x258);
            func_global_asm_8071498C(func_global_asm_80717D4C);
            break;
    }
    func_global_asm_807149B8(1);
    drawSpriteAtPosition(
        D_global_asm_8074E880[RandClamp(1000) % 3],
        (RandClamp(256) * 0.001953125) + 0.5,
        RandClamp(6) + (gCurrentActorPointer->x_position - 3.0f),
        gCurrentActorPointer->y_position + yOffset,
        RandClamp(6) + (gCurrentActorPointer->z_position - 3.0f)
    );
}

s32 func_global_asm_806B9EB4(u8 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp80[4][4];
    f32 sp40[4][4];
    f32 x, y, z;
    f32 temp;
    f32 sp2C;

    if (D_global_asm_80750628[arg0]) {
        getBonePosition(D_global_asm_807FDCA0->unk1C, D_global_asm_80750628[arg0], &x, &y, &z);
        func_global_asm_80611A70(arg2, arg4, &x, &z);
        sp2C = func_global_asm_80611BB4(x - arg2, z - arg4);
        guTranslateF(sp80, 0.0f, -arg1, 0.0f);
        func_global_asm_80612C30(sp40, (gCurrentActorPointer->y_rotation * 360) / 4096);
        guMtxCatF(sp80, sp40, sp80);
        func_global_asm_80612BC0(sp40, -90.0f);
        guMtxCatF(sp80, sp40, sp80);
        guAlignF(sp40, (sp2C * 57.29577637f) + 180.0f, x - arg2, y - arg3, z - arg4);
        guMtxCatF(sp80, sp40, sp80);
        guTranslateF(sp40, 0.0f, arg1, 0.0f);
        guMtxCatF(sp80, sp40, sp80);
        guScaleF(sp40,
                 gCurrentActorPointer->animation_state->scale_x,
                 gCurrentActorPointer->animation_state->scale_y,
                 gCurrentActorPointer->animation_state->scale_z);
        guMtxCatF(sp80, sp40, sp80);
        guTranslateF(sp40,
                     gCurrentActorPointer->x_position,
                     gCurrentActorPointer->y_position,
                     gCurrentActorPointer->z_position);
        guMtxCatF(sp80, sp40, &gCurrentActorPointer->unkC);
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806BA130(void) {
    gCurrentActorPointer->interactable = 2;
    gCurrentActorPointer->control_state = 0x23;
    gCurrentActorPointer->control_state_progress = 0;
    gCurrentActorPointer->health = 1;
    gCurrentActorPointer->unk132 = 1;
    D_global_asm_807FDC90->unk4 = gPlayerPointer;
    playActorAnimation(gCurrentActorPointer, D_global_asm_807FDC98->unk2A);
    gCurrentActorPointer->y_rotation = (RandClamp(1024) + gPlayerPointer->y_rotation) - 0x200;
    gCurrentActorPointer->unkB8 = RandClamp(100) + 50;
    gCurrentActorPointer->y_velocity = RandClamp(150) + 100;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BA240.s")

/*
s32 func_global_asm_806BA240(u8 arg0, s16 arg1) {
    Actor178 *sp54;
    Actor *temp_s0;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s32 temp_t5; // TODO: Might be u8/s8
    f64 temp_f0;

    sp54 = gCurrentActorPointer->unk178;
    temp_s0 = D_global_asm_807FDCA0->unk1C;
    if ((temp_s0 != NULL) && (temp_s0->control_state == 0x23) && (D_global_asm_807FDCA0->unk20 < 0xA)) {
        if ((gCurrentActorPointer->control_state != 0x15) && (gCurrentActorPointer->control_state != 0x17)) {
            gCurrentActorPointer->interactable = 0x80;
            gCurrentActorPointer->control_state = 0x15;
            gCurrentActorPointer->control_state_progress = 0;
            playActorAnimation(gCurrentActorPointer, 0);
            gCurrentActorPointer->unk132 = 2;
            sp54->unk6 = gCurrentActorPointer->x_position;
            sp54->unk8 = gCurrentActorPointer->z_position;
        }
    }
    if ((gCurrentActorPointer->control_state == 0x15) && ((temp_s0 == NULL) || (temp_s0->control_state != 0x23))) {
        func_global_asm_806BA130();
    }
    if (gCurrentActorPointer->control_state == 0x15) {
        temp_t5 = D_global_asm_807FDC9C->unkA_u8[0];
        if ((temp_t5 == 5) || (temp_t5 == 7)) {
            if (((temp_s0->animation_state->unk64 == 0x21E) || (temp_s0->animation_state->unk64 == 0x21F)) && ((temp_s0->animation_state->unk0->unk4 >= 4.0f)) && (temp_s0->animation_state->unk0->unk4 <= 12.0f)) {
                gCurrentActorPointer->unk132 = 4;
            } else {
                gCurrentActorPointer->unk132 = 2;
            }
        }
        if (temp_t5 == 1) {
            gCurrentActorPointer->unk132 = 8;
        }
        if (gCurrentActorPointer->unkF0 != 0) {
            gCurrentActorPointer->unkF0--;
        }
        if (temp_s0->control_state_progress != 0) {
            if ((temp_s0->control_state_progress == 1) && (D_global_asm_807FBD70 == 2) && (func_global_asm_8072DCF4(temp_s0, gPlayerPointer, 8000) != 0)) {
                if (character_change_array->unk2C0 == 1) {
                    setAction(0x32, gCurrentActorPointer, 0);
                } else {
                    playActorAnimation(temp_s0, RandChance(0.5) ? 0x21F : 0x21E);
                    temp_s0->control_state_progress = 2;
                }
            } else if (D_global_asm_807FBD70 == 4) {
                D_global_asm_807FDC90->unk16 = D_global_asm_807FDC94->animation_state->unk0->unk10;
                gCurrentActorPointer->object_properties_bitfield |= 0x20000000;
                if (gCurrentActorPointer->unkF0 == 0) {
                    gCurrentActorPointer->unkF0 = 0x28;
                    drawSpriteAtPosition(&D_global_asm_8071FB34, 2.0f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
                    playSound(0x1CA, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    playActorAnimation(temp_s0, 0x220);
                    temp_s0->control_state_progress = 2;
                    temp_s0->health--;
                    if (temp_s0->health == 0) {
                        temp_s0->control_state = 0x37;
                        temp_s0->control_state_progress = 0;
                    }
                }
            }
        }
        D_global_asm_807FDCA0->unk20++;
        getBonePosition(temp_s0, temp_t5, &sp4C, &sp48, &sp44);
        if (D_global_asm_807FDC90->unk1A & 0x80) {
            if (!(D_global_asm_807FDC90->unk1C & 0x80)) {
                gCurrentActorPointer->y_velocity = 300.0f;
            }
            if (gCurrentActorPointer->y_velocity > 0.0f) {
                return 0;
            }
            gCurrentActorPointer->noclip_byte = 0x24;
            if (arg1 != 0) {
                func_global_asm_80613C48(gCurrentActorPointer, arg1, 0.0f, 4.0f);
            }
            temp_f0 = 0.1;
            sp54->unk0 += (-sp54->unk0 * temp_f0);
            sp54->unk2 += (-sp54->unk2 * temp_f0);
            if (temp_t5 < 0xB) {
                gCurrentActorPointer->y_rotation = temp_s0->y_rotation;
            }
            gCurrentActorPointer->x_position = sp4C;
            gCurrentActorPointer->z_position = sp44;
            gCurrentActorPointer->y_position = sp48;
            if (func_global_asm_806B9EB4(temp_t5, arg0, sp4C, sp48, sp44) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
*/

void func_global_asm_806BA76C(f32 arg0) {
    Actor178 *a178;
    f32 x, z;

    a178 = gCurrentActorPointer->unk178;
    x = D_global_asm_807FDC90->unkA;
    z = D_global_asm_807FDC90->unkE;
    switch (gCurrentActorPointer->control_state) {
        case 0x1:
        case 0x10:
        case 0x15:
        case 0x23:
            x = D_global_asm_807FDC94->x_position;
            z = D_global_asm_807FDC94->z_position;
            // fallthrough
        case 0x2:
        case 0x3:
        case 0x7:
        case 0x35:
            if (!(func_global_asm_8072AB74(gCurrentActorPointer->control_state, x, z, (gCurrentActorPointer->unkFC ? 0x10 : 0x810), 0) & 1) && (gCurrentActorPointer->unkFC == 0)) {
                a178->unk0 += arg0;
            }
            break;
        case 0x37:
            switch (gCurrentActorPointer->control_state_progress) {
                case 2:
                    func_global_asm_8072DC7C(0xA);
                    break;
                case 3:
                    gCurrentActorPointer->control_state = 0x40;
                    break;
            }
            break;
        case 0x4:
            func_global_asm_8072AB74(0x37, 0, 0, 0x12, 0);
            break;
        default:
            func_global_asm_8072B7CC(0);
            break;
    }
}

void func_global_asm_806BA8C8(void) {
    switch (gCurrentActorPointer->control_state) {
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(gCurrentActorPointer->control_state, 0);
        default:
            func_global_asm_8072C918(10000, 0, 0);
            break;
        case 0x15:
        case 0x37:
        case 0x40:
            break;
    }
}

// Huge, float matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BA93C.s")

void func_global_asm_806BB32C(void) {
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        gCurrentActorPointer->unk16A = 0xFA;
        gCurrentActorPointer->unk16B = 0xFA;
        gCurrentActorPointer->unk16C = 0xFA;
    }
    if (gCurrentActorPointer->control_state == 0x17) {
        func_global_asm_806B9CE0(0, 0);
    }
    if (D_global_asm_807FDC90->unk2E != 0) {
        D_global_asm_807FDC90->unk2E--;
        gCurrentActorPointer->unkFC = 0;
        if ((D_global_asm_807FDC90->unk2E == 0) && (D_global_asm_807FDC94 == gPlayerPointer)) {
            gCurrentActorPointer->noclip_byte = 0x24;
        }
    }
}

// doable, close
// https://decomp.me/scratch/jNSL1
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BB400.s")

/*
// TODO: Very close, 1 extra instruction related to default case in the second switch
void func_global_asm_806BB400(void) {
    initializeCharacterSpawnerActor();
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        func_global_asm_806D0430(0.5249999762f);
        gPlayerPointer->object_properties_bitfield |= 0x400;
        gPlayerPointer->draw_distance = 0x7D0;
        gCurrentActorPointer->object_properties_bitfield &= -5;
        func_global_asm_807248B0(gCurrentActorPointer, 1.0f);
        gCurrentActorPointer->unk15F = 0;
        gCurrentActorPointer->y_rotation = func_global_asm_80665DE0(gPlayerPointer->x_position, gPlayerPointer->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position);
        playActorAnimation(gCurrentActorPointer, 0x21B);
        D_global_asm_807FDC98->unk46 |= 8;
        D_global_asm_807FDC98->unk28 = 0x21C;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x4:
            gCurrentActorPointer->control_state = 0x23;
            gCurrentActorPointer->control_state_progress = 0;
            // Fallthrough
        case 0x23:
            switch (gCurrentActorPointer->control_state_progress) {
                case 2:
                    break;
                case 0:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x202, 0.0f);
                    break;
                default: 
                    gCurrentActorPointer->control_state_progress = 1;
                case 1:
                    if (gCurrentActorPointer->animation_state->unk64 != 0x21C) {
                        playActorAnimation(gCurrentActorPointer, 0x21C);
                    }
                    func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
                    break;
            }
            break;
        case 0x37:
            func_global_asm_806D0430(0.3000000119f);
            gCurrentActorPointer->control_state = 0x40;
            break;
    }
    D_global_asm_807FDCA0->unk20 = 0;
    renderActor(gCurrentActorPointer, 0);
}
*/

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
    u16 unk44;
    u16 unk46; // Used
} AAD_global_asm_806BB604_unk0;

typedef struct {
    AAD_global_asm_806BB604_unk0 *unk0;
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
    s16 unk2C;
    s16 unk2E; // Used
} AAD_global_asm_806BB604;

s32 func_global_asm_806BB604(u8 arg0, s16 arg1, s16 arg2, s32 arg3) {
    AAD_global_asm_806BB604 *aaD;

    if (D_global_asm_807FDC90->unk2C != 0) {
        func_global_asm_806B9CE0(0, 0xA);
        D_global_asm_807FDC90->unk2C -= 1;
        return FALSE;
    }
    if (func_global_asm_807271F4(arg0, RandClamp(10) + (gCurrentActorPointer->x_position - 5.0f), gCurrentActorPointer->y_position + 5.0f, RandClamp(10) + (gCurrentActorPointer->z_position - 5.0f), (RandClamp(1024) + gCurrentActorPointer->y_rotation) - 0x200, arg1, arg2) != 0) {
        gLastSpawnedActor->control_state = 0x17;
        gLastSpawnedActor->control_state_progress = 0;
        aaD = gLastSpawnedActor->additional_actor_data;
        aaD->unk2E = 0x1E;
        if (arg3 != 0) {
            aaD->unk0->unk46 &= 0xFFF7;
            aaD->unk4 = arg3;
        }
        gLastSpawnedActor->noclip_byte = 1;
        gLastSpawnedActor->draw_distance = 0x3E8;
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806BB81C(void) {
    func_global_asm_80604CBC(gCurrentActorPointer, 0x11F, 0, 0, 0, 0xFF, 1.0f, 0);
    playSong(MUSIC_59_GENERIC_TWINKLY_SOUNDS, 1.0f);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BB874.s")

void func_global_asm_806BC080(void) {
    func_global_asm_806BB32C();
    if ((D_global_asm_807FDC9C->unkA_u8[0] == 0) || (func_global_asm_806BA240(0, 0x446) == 0)) {
        func_global_asm_806AD260(0x2ED, 1, 0);
        renderActor(gCurrentActorPointer, 0);
    }
}

void func_global_asm_806BC0E4(void) {
    func_global_asm_806BB32C();
    if ((D_global_asm_807FDC9C->unkA_u8[0] == 0) || (func_global_asm_806BA240(0x32, 0x44E) == 0)) {
        func_global_asm_806AD260(0x2EC, 1, 0);
        renderActor(gCurrentActorPointer, 0);
    }
}

void func_global_asm_806BC148(void) {
    func_global_asm_806BB32C();
    if ((D_global_asm_807FDC9C->unkA_u8[0] == 0) || (func_global_asm_806BA240(0x14, 0x44A) == 0)) {
        func_global_asm_806AD260(0x2EE, 1, 0);
        renderActor(gCurrentActorPointer, 0);
    }
}

void func_global_asm_806BC1AC(void) {
    func_global_asm_806BB32C();
    func_global_asm_806BA93C(0x24, 0x14, 0x1E);
}
