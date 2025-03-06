#include <ultra64.h>
#include "functions.h"

extern s16 D_global_asm_80750AC8;

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
} Struct80747B00;
extern Struct80747B00 D_global_asm_80747B00[];

extern f32 D_global_asm_807502F4;
extern u8 D_global_asm_807506C0[];

extern s16 D_global_asm_807F62B4;
extern u8 D_global_asm_807FBDC4;
extern s32 D_global_asm_807FBDC8[];
extern u16 D_global_asm_807FC930[];

void func_global_asm_8061F510(s32, s32);
u8 func_global_asm_8072881C(u8 arg0, u32 *arg1);
void func_global_asm_8072A450(void);

int func_global_asm_807035C4(); // TODO: Signature
int func_global_asm_807197B4(); // TODO: Signature

u8 func_global_asm_806BDD90(void) {
    s16 i;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        if (func_global_asm_805FF0C8()) {
            gCurrentActorPointer->control_state = 0x40;
        } else {
            gCurrentActorPointer->unk130 = 0x3C;
            gCurrentActorPointer->unk131 = 0x3C;
            gCurrentActorPointer->draw_distance = 0x3E8;
            func_global_asm_80724CA4(2, 1);
            D_global_asm_807FDC90->unk30 = gCurrentActorPointer->animation_state->scale_y;
            gCurrentActorPointer->y_acceleration = gCurrentActorPointer->y_acceleration / 1.5;
        }
    }
    func_global_asm_80729E6C();
    func_global_asm_806651FC(gCurrentActorPointer);
    func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if (D_global_asm_807FBB70.unk258[i] == 3) {
            return D_global_asm_807FBB70.unk278[i]->unk2;
        }
    }
    return 0;
}

void func_global_asm_806BDEC8(void) {
    PlayerAdditionalActorData *PaaD = gPlayerPointer->PaaD;

    if (func_global_asm_806BDD90() == 1) {
        gCurrentActorPointer->control_state = 0x12;
        gCurrentActorPointer->control_state_progress = 0;
    }
    if (gCurrentActorPointer->control_state == 0x12) {
        switch (gCurrentActorPointer->control_state_progress) {
            case 0:
                gCurrentActorPointer->y_velocity = 150.0f;
                playActorAnimation(gCurrentActorPointer, 0x28E);
                func_global_asm_8061C600(PaaD->unk104, gCurrentActorPointer, 4, 0xE77, 0xFA, 2, 0x32, 0x20, 0x3F, 0x4A, 0.1599999964f);
                D_global_asm_807FDC90->unk2C = 0x32;
                gCurrentActorPointer->control_state_progress++;
                break;
            case 2:
                if (D_global_asm_807FDC90->unk2C != 0) {
                    D_global_asm_807FDC90->unk2C--;
                } else {
                    playActorAnimation(gCurrentActorPointer, 0x28F);
                    gCurrentActorPointer->control_state_progress++;
                    D_global_asm_807FDC90->unk2C = 0x78;
                }
                break;
            case 3:
                if (D_global_asm_807FDC90->unk2C != 0) {
                    D_global_asm_807FDC90->unk2C--;
                } else if (!func_global_asm_805FF0C8()) {
                    gCurrentActorPointer->control_state = 0;
                    gCurrentActorPointer->control_state_progress = 0;
                }
                break;
        }
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806BE09C(void) {
    PlayerAdditionalActorData *sp4C;
    u8 temp;
    u8 temp2;
    u8 levelIndex;
    f32 sp44;
    f32 temp_f2;
    CharacterProgress *sp3C;
    f32 sp40;
    s32 i;
    s32 count = 0;

    sp4C = gPlayerPointer->additional_actor_data;
    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    sp44 = D_global_asm_807FC930[levelIndex] / (f32)D_global_asm_807446C0[levelIndex];
    if (func_global_asm_806BDD90() == 1) {
        D_global_asm_807FDC90->unk2C = func_global_asm_806F8AD4(0, 0);
        if (D_global_asm_807FDC90->unk2C != 0) {
            gCurrentActorPointer->control_state = 0x12;
            gCurrentActorPointer->control_state_progress = 0;
            D_global_asm_807FDC90->unk2E = 0x32;
            playActorAnimation(gCurrentActorPointer, 0x28A);
            func_global_asm_8061C518(sp4C->unk104, gPlayerPointer, 4, 0x990, 0x5A, -0x2E, 0x3C, 0xA, 0x20, 0, 0.3000000119f);
            gPlayerPointer->y_rotation = func_global_asm_80665DE0(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, gPlayerPointer->x_position, gPlayerPointer->z_position);
            gPlayerPointer->unkEE = gPlayerPointer->y_rotation;
        }
    }
    func_global_asm_80724E48(0);
    if (sp44 > 1.0f) {
        sp44 = 1.0f;
    }
    temp_f2 = D_global_asm_807FDC90->unk30 + ((0.44 - D_global_asm_807FDC90->unk30) * sp44);
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_807248B0(gCurrentActorPointer, temp_f2);
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x12:
            func_global_asm_807248B0(gCurrentActorPointer, ((temp_f2 - gCurrentActorPointer->animation_state->scale_x) * 0.1) + gCurrentActorPointer->animation_state->scale_x);
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if (D_global_asm_807FDC90->unk2E != 0) {
                        D_global_asm_807FDC90->unk2E--;
                        if (D_global_asm_807FDC90->unk2E == 0) {
                            func_global_asm_8061C518(sp4C->unk104, gCurrentActorPointer, 4, 0x305, 0x14A, 3, 0x32, 0x7F, 0x5A, 0, 0.02999999933f);
                        }
                    }
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        if (!(object_timer & 3)) {
                            sp3C = &D_global_asm_807FC950->character_progress[*current_character_index];
                            D_global_asm_807FDC90->unk2C--;
                            changeCollectableCount(0, 0, -1);
                            sp3C->coloured_bananas_fed_to_tns[levelIndex]++;
                            for (i = 0; i < 5; i++) { count += D_global_asm_807FC950[0].character_progress[i].coloured_bananas_fed_to_tns[levelIndex]; }
                            if (count >= D_global_asm_807446C0[levelIndex]) {
                                D_global_asm_807FDC90->unk2C = 0;
                                func_global_asm_806F8D58(0, 0);
                            }
                            func_global_asm_8071498C(func_global_asm_8071D0F0);
                            func_global_asm_807149FC(-1);
                            func_global_asm_807149B8(1);
                            func_global_asm_80714950((s32)gCurrentActorPointer);
                            func_global_asm_80714C08(func_global_asm_806FACE8(0), 0.3f, gPlayerPointer, 4, 0);
                        }
                    } else if (D_global_asm_807FDC90->unk2E == 0) {
                        D_global_asm_807FDC90->unk2C = 0x1E;
                        gCurrentActorPointer->control_state_progress = 1;
                    }
                    break;
                case 1:
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        playActorAnimation(gCurrentActorPointer, 0x28B);
                        gCurrentActorPointer->control_state = 0x27;
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                    break;
            }
            break;
        case 0x27:
            if (gCurrentActorPointer->control_state_progress == 1) {
                func_global_asm_80685520(4.0f, 1, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 5.0f, gCurrentActorPointer->z_position);
                gCurrentActorPointer->control_state = 0x28;
                gCurrentActorPointer->control_state_progress = 0;
                D_global_asm_807FDC90->unk2C = 0x3C;
            }
            break;
        case 0x28:
            D_global_asm_807FDC90->unk2C -= 1;
            if (D_global_asm_807FDC90->unk2C == 0) {
                gCurrentActorPointer->control_state = 0;
                gCurrentActorPointer->control_state_progress = 0;
                D_global_asm_807FDC90->unk2E = 0;
            }
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806BE674(u8 arg0) {
    s16 i;
    for (i = 0; i < 0x10U; i++) {
        if (arg0) {
            func_global_asm_8068A1CC(D_global_asm_807506C0[i]);
        } else {
            func_global_asm_8068A20C(D_global_asm_807506C0[i]);
        }
    }
}

Gfx *func_global_asm_806BE6F0(Gfx *dl, Actor *arg1) {
    u8 temp_t7;
    char sp4C[2];
    u16 temp;
    
    temp_t7 = (arg1->unk168 / 30);
    if (temp_t7) {
        sprintf(sp4C, "%d", MIN(3, temp_t7));
    } else {
        sprintf(sp4C, getTextString(0x26, 9, 1));
    }
    if ((arg1->unk168 % 30) == 0) {
        if (temp_t7) {
            playSound(temp_t7 > 1 ? 0x75 : 0x74, 0x7FFF, 64.0f, 1.0f, 0, 0x80);
        }
    }

    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

    dl = func_global_asm_8070068C(dl);
    dl = printStyledText(dl, 1, (320 - getCenterOfString(1, sp4C)) << 1, 0xAA, sp4C, 1);
    if (arg1->unk168-- == 0) {
        arg1->control_state_progress++;
    }
    return dl;
}

void func_global_asm_806BE8BC(void) {
    u8 sp37;
    s16 j;
    s16 i;
    s16 var_v0;

    sp37 = isFlagSet(PERMFLAG_PROGRESS_RABBIT_RACE_1_COMPLETE, FLAG_TYPE_PERMANENT);
    initializeCharacterSpawnerActor();
    if (extra_player_info_pointer->unk1F0 & 0x100000) {
        gCurrentActorPointer->control_state = 0x40;
        return;
    }
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724CA4(2, 1);
        D_global_asm_807FDC98->unk46 |= 0x20;
        playActorAnimation(gCurrentActorPointer, 0x306);
        func_global_asm_80728950(0);
        gCurrentActorPointer->control_state = 0x1E;
        gCurrentActorPointer->control_state_progress = 0;
        gCurrentActorPointer->unk15F = 0;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0x26:
            playActorAnimation(gCurrentActorPointer, 0x307);
            gCurrentActorPointer->control_state = 0x27;
            gCurrentActorPointer->control_state_progress = 0;
            break;
        case 0x1E:
            func_global_asm_80684850(1);
            if (gCurrentActorPointer->shadow_opacity < 0xFF) {
                gCurrentActorPointer->shadow_opacity += 5;
            }
            if (func_global_asm_80629148()) {
                func_global_asm_8063DA40(0x1F, 3);
                func_global_asm_80672C30(gPlayerPointer);
                func_global_asm_80726EE0(1);
                D_global_asm_807FDC98->unk46 |= 4;
                func_global_asm_806BE674(1);
                func_global_asm_807289B0(0, 0);
                if (sp37) {
                    func_global_asm_80641874(0x17, 0x14);
                    loadText(gCurrentActorPointer, 0x14, 1);
                } else {
                    loadText(gCurrentActorPointer, 0x14, 0);
                }
                playActorAnimation(gCurrentActorPointer, 0x309);
                gCurrentActorPointer->control_state = 0x1F;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 0x1F:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if (func_global_asm_80629148()) {
                        func_global_asm_8061CAD8();
                        func_global_asm_8061CAD8();
                        gCurrentActorPointer->control_state_progress++;
                        gCurrentActorPointer->unk168 = 0x78;
                    }
                    break;
                case 1:
                    addActorToTextOverlayRenderArray(func_global_asm_806BE6F0, gCurrentActorPointer, 3);
                    break;
                case 2:
                    playSong(MUSIC_169_FUNGI_FOREST_RABBIT_RACE, 1.0f);
                    D_global_asm_807FBB64 |= 4;
                    func_global_asm_8061CB08();
                    func_global_asm_8062217C(D_global_asm_807F5D10, 3);
                    playActorAnimation(gCurrentActorPointer, 0x302);
                    func_global_asm_8072B324(gCurrentActorPointer, (sp37 ? 1.5 : 1.0) * D_global_asm_807FDC9C->unkD);
                    gCurrentActorPointer->control_state = 2;
                    gCurrentActorPointer->control_state_progress = 0;
                    func_global_asm_8061F510(1, 0xA);
                    extra_player_info_pointer->unk1F4 |= 0x40;
                    break;
            }
            break;
        case 0x27:
            if (gCurrentActorPointer->control_state_progress == 0) {
                func_global_asm_80602B60(0xA9, 0);
                gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
                gCurrentActorPointer->shadow_opacity = 0xFF;
                func_global_asm_806BE674(0);
                playCutscene(gCurrentActorPointer, 0xF, 5);
                gCurrentActorPointer->y_rotation = func_global_asm_80665DE0(gPlayerPointer->x_position, gPlayerPointer->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position);
                loadText(gCurrentActorPointer, 0x14, 4);
                gCurrentActorPointer->control_state = 0x37;
                gCurrentActorPointer->control_state_progress = 0;
                gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
            }
            break;
        case 0x28:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_80602B60(0xA9, 0);
                    gCurrentActorPointer->object_properties_bitfield &= ~0x8000;
                    gCurrentActorPointer->shadow_opacity = 0xFF;
                    func_global_asm_806BE674(0);
                    playCutscene(gCurrentActorPointer, 0x1F, 1);
                    gCurrentActorPointer->y_rotation = func_global_asm_80665DE0(gPlayerPointer->x_position, gPlayerPointer->z_position, gCurrentActorPointer->x_position, gCurrentActorPointer->z_position);
                    playActorAnimation(gCurrentActorPointer, 0x308);
                    func_global_asm_8070E8DC(1);
                    if (sp37) {
                        loadText(gCurrentActorPointer, 0x14, 3);
                    } else {
                        loadText(gCurrentActorPointer, 0x14, 2);
                    }
                    gCurrentActorPointer->control_state_progress = 1;
                    gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
                    break;
                case 1:
                    if (func_global_asm_80629148()) {
                        if (sp37) {
                            func_global_asm_8063DA40(0x57, 0xA);
                            D_global_asm_807FDC90->unk1A |= 0x8000;
                        } else {
                            var_v0 = gCurrentActorPointer->y_rotation - 0x12C;
                            playSong(MUSIC_47_MELON_SLICE_DROP, 1.0f);
                            for (i = 0; i < 3; i++, var_v0 += 0x12C) {
                                func_global_asm_806A5DF0(
                                    0x35,
                                    gCurrentActorPointer->x_position,
                                    gCurrentActorPointer->y_position,
                                    gCurrentActorPointer->z_position,
                                    var_v0,
                                    0x63,
                                    -1,
                                    0
                                );
                            }
                        }
                        setFlag(PERMFLAG_PROGRESS_RABBIT_RACE_1_COMPLETE, TRUE, FLAG_TYPE_PERMANENT);
                        gCurrentActorPointer->control_state = 0x37;
                        gCurrentActorPointer->control_state_progress = 0;
                        gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
                    }
                    break;
            }
            break;
        case 0x37:
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8072DC7C(2);
                if (gCurrentActorPointer->control_state_progress != 0) {
                    D_global_asm_807FBB64 &= ~4;
                    extra_player_info_pointer->unk23F = 2;
                    func_global_asm_8061F510(1, 0);
                    extra_player_info_pointer->unk1F4 &= ~0x40;
                    func_global_asm_8072EC94(0x16, 0);
                    func_global_asm_80726EE0(2);
                    if (D_global_asm_807FDC90->unk1A & 0x8000) {
                        gCurrentActorPointer->control_state = 0x40;
                    } else {
                        if (gCurrentActorPointer->animation_state->unk64 != 0x308) {
                            func_global_asm_806ACC00(2);
                        }
                        func_global_asm_8063DA40(0x1F, 1);
                        gCurrentActorPointer->control_state = 0x3C;
                    }
                }
            }
            break;
        case 0x13:
            playActorAnimation(gCurrentActorPointer, 0x305);
            gCurrentActorPointer->y_velocity = 200.0f;
            gCurrentActorPointer->control_state = 2;
            gCurrentActorPointer->control_state_progress = 0;
            // fallthrough
        default:
            if (gCurrentActorPointer->unk15F < 0x10U) {
                addActorToTextOverlayRenderArray(func_global_asm_8068E474, gCurrentActorPointer, 3);
            }
            if ((RandChance(0.01)) && (gCurrentActorPointer->animation_state->unk64 == 0x302)) {
                playActorAnimation(gCurrentActorPointer, (object_timer & 1) ? 0x303 : 0x304);
            }
            if (D_global_asm_807FBB70.unk0 != 0) {
                if ((D_global_asm_807FBB70.unk1 >= D_global_asm_807506C0[gCurrentActorPointer->unk15F]) && (gCurrentActorPointer->unk15F < 0x10U)) {
                    if (D_global_asm_807FBB70.unk1 != D_global_asm_807506C0[gCurrentActorPointer->unk15F]) {
                        playActorAnimation(gCurrentActorPointer, 0x301);
                        gCurrentActorPointer->control_state = 0x27;
                        gCurrentActorPointer->control_state_progress = 0;
                    } else {
                        gCurrentActorPointer->unk15F++;
                        if (gCurrentActorPointer->unk15F >= 0x10U) {
                            func_global_asm_8072EC94(0x16, 1);
                        }
                    }
                }
            }
            for (j = 0; j < D_global_asm_807FBB70.unk254; j++) {
                if (D_global_asm_807FBB70.unk258[j] == 3) {
                    gCurrentActorPointer->control_state = 0x28;
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
            func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
            func_global_asm_8072AB74(gCurrentActorPointer->control_state, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x10, 0);
            func_global_asm_8072D13C(gCurrentActorPointer->control_state, 0);
            break;
    }
    if ((gCurrentActorPointer->animation_state->unk64 == 0x301) || (gCurrentActorPointer->animation_state->unk64 == 0x302)) {
        func_global_asm_80724E48(0);
    }
    func_global_asm_8072A450();
    renderActor(gCurrentActorPointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BF218.s")

void func_global_asm_806BF920(void) {
    Actor17C *a17C;
    s32 sp20;
    s32 var_a2;

    a17C = gCurrentActorPointer->unk17C;
    sp20 = 0;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        var_a2 = 0;
        switch (a17C->unk0_u16[0]) {
            case 1:
            case 2:
            case 3:
                var_a2 = 3;
                break;
            case 9:
            case 10:
            case 11:
                var_a2 = 5;
                break;
            case 4:
            case 5:
                var_a2 = 2;
                break;
        }
        if (var_a2 != 0) {
            gCurrentActorPointer->animation_state->unk1C = malloc(0x100);
            func_global_asm_806C8220(0, gCurrentActorPointer->unk178, var_a2);
        }
    }
    switch (a17C->unk0_u16[0]) {
        case 1:
        case 2:
        case 3:
            func_global_asm_806F22A8(gCurrentActorPointer, gCurrentActorPointer->animation_state->unk1C, &sp20);
            break;
        case 9:
        case 10:
        case 11:
            func_global_asm_806F1EB0(gCurrentActorPointer, gCurrentActorPointer->animation_state->unk1C, &sp20);
            break;
        case 4:
        case 5:
            func_global_asm_806F1C04(gCurrentActorPointer, gCurrentActorPointer->animation_state->unk1C, &sp20);
            break;
    }
    if (sp20 != 0) {
        gCurrentActorPointer->animation_state->unk1C[sp20].unk0 = 0;
    }
}

void func_global_asm_80613CA8(Actor*, s32, f32, f32);

void func_global_asm_806BFA8C(u16 arg0) {
    switch (arg0) {
        case 0xEA:
        case 0x23E:
        case 0x23F:
        case 0x240:
        case 0x4C7:
            gCurrentActorPointer->control_state_progress = 1;
            break;
        case 0x112:
            func_global_asm_806F0D68(gCurrentActorPointer);
            // fallthrough
        case 0x113:
        case 0x128:
        case 0x129:
        case 0x12A:
        case 0x12B:
        case 0x12C:
        case 0x12D:
        case 0x12E:
        case 0x12F:
        case 0x130:
            func_global_asm_806C7BAC(gCurrentActorPointer, NULL);
            break;
        case 0x114:
            func_global_asm_806F0C18(gCurrentActorPointer);
            func_global_asm_806F10E8(gCurrentActorPointer);
            break;
        case 0x2CF:
            func_global_asm_80613214(gCurrentActorPointer);
            func_global_asm_80613CA8(gCurrentActorPointer, 0x2CF, 0, 0);
            break;
    }
}

void func_global_asm_806BFBB4(void) {
    func_global_asm_8061421C(gCurrentActorPointer);
    renderActor(gCurrentActorPointer, 0);
    func_global_asm_80614A64(gCurrentActorPointer);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BFBF4.s")

void func_global_asm_806C10A0(u8 textIndex, u16 fileIndex, s16 animationIndex) {
    f32 sp34;

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806F0C18(gCurrentActorPointer);
        D_global_asm_807FDC98->unk46 |= 0x200;
        func_global_asm_8072B324(gCurrentActorPointer, 0);
    }
    func_global_asm_80724A20();
    switch (gCurrentActorPointer->control_state) {
        case 5:
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 2, 0.0f);
            // fallthrough
        case 0:
            if (func_global_asm_80629148()) {
                gCurrentActorPointer->control_state = 0x12;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 2:
            func_global_asm_8072AB74(2, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            func_global_asm_8072D13C(2, 0);
            break;
        case 18:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    loadText(gCurrentActorPointer, fileIndex, textIndex);
                    playActorAnimation(gCurrentActorPointer, animationIndex);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 2:
                    // TODO: Proper bitfield syntax
                    if (((s32)(gCurrentActorPointer->object_properties_bitfield << 6) >= 0)) {
                        func_global_asm_80613C48(gCurrentActorPointer, 0xE4, 0.0f, 2.0f);
                        spawnActor(ACTOR_UNKNOWN_225, 0x98);
                        moveAndScaleActorToAnother(gLastSpawnedActor, gCurrentActorPointer, 0.21f);
                        getBonePosition(gCurrentActorPointer, 1, &gLastSpawnedActor->x_position, &sp34, &gLastSpawnedActor->z_position);
                        playActorAnimation(gLastSpawnedActor, 0x298);
                        gLastSpawnedActor->unk11C = gCurrentActorPointer;
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 3:
                    gCurrentActorPointer->y_position += 0.5;
                    break;
            }
            break;
    }
}

void func_global_asm_806C1300(void) {
    switch (gCurrentActorPointer->control_state_progress) {
        case 1:
            gCurrentActorPointer->unk11C->object_properties_bitfield &= -5;
            gCurrentActorPointer->control_state_progress++;
            break;
        case 3:
            func_global_asm_8061D4E4(D_global_asm_807F5D10);
            gCurrentActorPointer->unk11C->control_state = 0x40;
            deleteActor(gCurrentActorPointer);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C13AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 temp_v0;

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk6A |= 1;
        func_global_asm_8067ACB4(gCurrentActorPointer);
        gCurrentActorPointer->unkCC = 1;
    }
    temp_v0 = func_global_asm_806CD9A0(gCurrentActorPointer, gCurrentActorPointer->unkB8, D_global_asm_807FDC90->unk26, D_global_asm_807FDC90->unk34, arg0);
    if (temp_v0 != D_global_asm_807FDC90->unk34) {
        switch (temp_v0) {
            case 0:
            case 1:
            case 2:
                func_global_asm_80613C48(gCurrentActorPointer, arg1, 0.0f, 6.0f);
                break;
            case 3:
                func_global_asm_80613C48(gCurrentActorPointer, arg2, 0.0f, 6.0f);
                break;
            case 4:
                func_global_asm_80613C48(gCurrentActorPointer, arg3, 0.0f, 6.0f);
                break;
            case 5:
                func_global_asm_80613C48(gCurrentActorPointer, arg4, 0.0f, 6.0f);
                break;
        }
        D_global_asm_807FDC90->unk34 = temp_v0;
    }
}

void func_global_asm_806C151C(u16 fileIndex, u8 textIndex, s16 tempFlagIndex) {
    f32 dx, dy, dz;
    s32 phi_a3;

    dx = gPlayerPointer->x_position - gCurrentActorPointer->x_position;
    dy = gPlayerPointer->y_position - gCurrentActorPointer->y_position;
    dz = gPlayerPointer->z_position - gCurrentActorPointer->z_position;
    phi_a3 = FALSE;
    if ((SQ(dx) + SQ(dy) + SQ(dz)) < SQ(70.0f)) {
        phi_a3 = TRUE;
    }
    if ((phi_a3 & 0xFF) && !isFlagSet(tempFlagIndex, FLAG_TYPE_TEMPORARY)) {
        loadText(gCurrentActorPointer, fileIndex, textIndex);
        setFlag(tempFlagIndex, TRUE, FLAG_TYPE_TEMPORARY);
    }
}

void func_global_asm_806C15E8(void) {
    D_global_asm_807FDC98->unk46 |= 0x1000;
    gCurrentActorPointer->unk146 = 0;
    func_global_asm_8072B324(gCurrentActorPointer, 0);
    gCurrentActorPointer->unkCC = 1;
}

void func_global_asm_806C1640(void) {
    f64 temp_f0;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
        if (current_map == MAP_DK_RAP) {
            temp_f0 = 0.8;
            gCurrentActorPointer->animation_state->scale_x *= temp_f0;
            gCurrentActorPointer->animation_state->scale_y *= temp_f0;
            gCurrentActorPointer->animation_state->scale_z *= temp_f0;
        }
    }
    func_global_asm_806BF920();
    // TODO: Bitfield syntax
    if (!(((s32)gCurrentActorPointer->object_properties_bitfield << 3) >= 0)) {
        func_global_asm_806BFBF4();
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C1734(void) {
    s32 pad2; // TODO: Can we get rid of these?
    s32 pad; // TODO: Can we get rid of these?
    ActorAnimationState *temp_v1;
    s16 sp2A;
    u8 sp29;
    AnimationStateUnk0 *temp_a0;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
    }
    func_global_asm_806BF920();
    if (gCurrentActorPointer->object_properties_bitfield & 0x10000000) {
        sp2A = gCurrentActorPointer->animation_state->unk0->unk4;
        func_global_asm_806BFBF4();
        temp_v1 = gCurrentActorPointer->animation_state;
        if (temp_v1->unk8->unk0 == 0) {
            temp_a0 = temp_v1->unk0;
            switch (temp_a0->unk10) {
                case 0xBB:
                    if ((gCurrentActorPointer->y_velocity > 30.0f) && !(object_timer & 3)) {
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_8071498C(func_global_asm_8071C818);
                        func_global_asm_80714C08(&D_global_asm_8071FB08, 0.8f, gCurrentActorPointer, 5, 0);
                    }
                    break;
                case 0x114:
                    if (temp_a0->unk24 == 0.0f) {
                        func_global_asm_806F1048(gCurrentActorPointer);
                    }
                    break;
                case 0xEA:
                    if ((gCurrentActorPointer->control_state_progress != 0) && (sp2A >= 0xA)) {
                        gCurrentActorPointer->control_state_progress = 0;
                        func_global_asm_80690814(gCurrentActorPointer, 7);
                        func_global_asm_8069084C(0x29, 0xCA, 0.4f, gCurrentActorPointer->y_rotation, 250.0f, 0.0f, gCurrentActorPointer);
                    }
                    break;
                case 0x112:
                    if ((sp2A >= 0x44) && (sp2A < 0x64) && ((object_timer % 3U) == 0)) {
                        sp29 = RandClamp(32767) % 2;
                        func_global_asm_807149B8(1);
                        func_global_asm_80714950(0x50);
                        func_global_asm_8071498C(func_global_asm_8071A8B0);
                        func_global_asm_80714C08(&D_global_asm_807200D4, 0.5f, gCurrentActorPointer, sp29 + 9, 2);
                    }
                    break;
            }
        }
    } else {
        func_global_asm_806C10A0(0, 3, 0x3D8);
        if (isFlagSet(PERMFLAG_ITEM_GB_JAPES_FRONT_OF_DIDDY_CAGE, FLAG_TYPE_PERMANENT) != 0) {
            func_global_asm_806C151C(3, 3, TEMPFLAG_TEXT_DIDDY_CAGE);
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C19F4(void) {
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
        gCurrentActorPointer->ledge_info_pointer->unk14 = 180.0f;
        func_global_asm_80724CA4(2, 1);
        // Note: This is read as u16 at 0x5A instead of u32 at 0x58
        func_global_asm_806F09F0(gCurrentActorPointer, gCurrentActorPointer->unk58);
    }

    // TODO: Bitfield syntax
    if (((s32)gCurrentActorPointer->object_properties_bitfield * 8) < 0) {
        func_global_asm_806BFBF4();
        if (gCurrentActorPointer->animation_state->unk0->unk10 == 0x1A4) {
            func_global_asm_807149B8(1);
            changeActorColor(0x96, 0xFF, 0xFF, 0xFF);
            func_global_asm_80714C08(&D_global_asm_8071FBA0, 0.7f, gCurrentActorPointer, 5, 0);
        }
        func_global_asm_80724E48(D_global_asm_807FDC94 == gPlayerPointer ? 5 : 7);
    } else {
        func_global_asm_806C10A0(2, 6, 0x3D9);
        func_global_asm_80724E48(0);
        func_global_asm_806C151C(6, 1, TEMPFLAG_TEXT_LANKY_CAGE); // Aztec: Caged Lanky Text Cleared
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C1B50(void) {
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
        func_global_asm_806F09F0(gCurrentActorPointer, gCurrentActorPointer->unk58);
    }
    func_global_asm_806BF920();
    if (gCurrentActorPointer->object_properties_bitfield & 0x10000000) {
        func_global_asm_806BFBF4();
        if (gCurrentActorPointer->object_properties_bitfield & 4) {
            if (gCurrentActorPointer->control_state_progress) {
                u8 var_v1;
                u8 boneIndex = 0x11;
                switch (gCurrentActorPointer->animation_state->unk0->unk10) {
                    case 0x23E:
                        var_v1 = 7;
                        boneIndex = 0xD;
                        break;
                    case 0x23F:
                        var_v1 = 7;
                        boneIndex = 0xE;
                        break;
                    case 0x240:
                        var_v1 = 3;
                        boneIndex = 0x11;
                        break;
                    default:
                        // TODO: Do it without a label... hmm...
                        goto render_806C1B50;

                }
                if (var_v1 < gCurrentActorPointer->animation_state->unk0->unk4) {
                    func_global_asm_80714C08(&D_global_asm_8071FB34, 0.5f, gCurrentActorPointer, boneIndex, 0);
                    gCurrentActorPointer->control_state_progress = 0;
                }
            }
        }
    } else {
        func_global_asm_806C10A0(2, 4, 0x3DB);
        func_global_asm_806C151C(4, 1, TEMPFLAG_TEXT_TINY_CAGE);
    }
render_806C1B50:
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C1CCC(void) {
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->terminal_velocity = -2000.0f;
        gCurrentActorPointer->y_acceleration = -200.0f;
        func_global_asm_806C15E8();
        func_global_asm_80724CA4(2, 1);
        if (current_map == MAP_DK_RAP) {
            func_global_asm_80613194(gCurrentActorPointer, 0xE);
        }
        func_global_asm_806F09F0(gCurrentActorPointer, gCurrentActorPointer->unk58);
    }
    // TODO: Better way to do this
    if (((s32) gCurrentActorPointer->object_properties_bitfield * 8) < 0) {
        func_global_asm_806BFBF4();
        if (gCurrentActorPointer->object_properties_bitfield & 4) {
            if ((gCurrentActorPointer->animation_state->unk0->unk10 == 0x2C4) && (gCurrentActorPointer->animation_state->unk0->unk4 > 25.0f)) {
                addActorToTextOverlayRenderArray(func_global_asm_807035C4, NULL, 3);
            }
        }
        func_global_asm_80724E48(D_global_asm_807FDC94 == gPlayerPointer ? 5 : 7);
    } else {
        func_global_asm_806C10A0(2, 5, 0x3DA);
        func_global_asm_80724E48(0);
        func_global_asm_806C151C(5, 1, TEMPFLAG_TEXT_CHUNKY_CAGE); // Factory: Caged Chunky Text Cleared
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C1E44(void) {
    s32 i;

    initializeCharacterSpawnerActor();
    if ((gCurrentActorPointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_8068842C(gCurrentActorPointer, 0, 1);
        func_global_asm_80688460(gCurrentActorPointer, 0, 1);
        switch (current_map) {
            case MAP_AZTEC_LLAMA_TEMPLE:
                gCurrentActorPointer->unk130 = 0xFF;
                gCurrentActorPointer->unk131 = 0xFF;
                // Aztec: Water Cooled Down
                if (!isFlagSet(PERMFLAG_PROGRESS_LLAMA_TEMPLE_WATER_COOLED, FLAG_TYPE_PERMANENT)) {
                    func_global_asm_806883F4(gCurrentActorPointer, 0, 1, 0);
                    playActorAnimation(gCurrentActorPointer, 0x2BD);
                    gCurrentActorPointer->control_state = 0;
                    gCurrentActorPointer->control_state_progress = 0;
                } else {
                    gCurrentActorPointer->control_state = 0x27;
                    gCurrentActorPointer->control_state_progress = 0;
                    gCurrentActorPointer->control_state_progress = 4;
                }
                break;
            case MAP_AZTEC:
                func_global_asm_806883F4(gCurrentActorPointer, 0, 0, 0);
                gCurrentActorPointer->control_state = 5;
                gCurrentActorPointer->control_state_progress = 0;
                break;
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            func_global_asm_80724A20();
            switch (gCurrentActorPointer->control_state_progress) {
                case 1:
                    D_global_asm_807FDC90->unk2C = 3;
                    gCurrentActorPointer->control_state_progress = 2;
                    // Fallthrough
                case 2:
                    if (!(object_timer & 7)) {
                        if (D_global_asm_807FDC90->unk2C != 0) {
                            D_global_asm_807FDC90->unk2C--;
                            if (D_global_asm_807FDC90->unk2C == 0) {
                                gCurrentActorPointer->control_state_progress = 0;
                            }
                            func_global_asm_80714998(2);
                            func_global_asm_807149B8(1);
                            func_global_asm_807149FC(0x28);
                            func_global_asm_8071498C(func_global_asm_807197B4);
                            func_global_asm_80714C08(&D_global_asm_8071FF58, 0.05f, gCurrentActorPointer, 1, 0);
                        }
                    }
            }
            break;
        case 39:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    func_global_asm_806883F4(gCurrentActorPointer, 0, 0, 0);
                    playActorAnimation(gCurrentActorPointer, 0x2BE);
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 3:
                    for (i = 0; i < 0xA; i++) {
                        func_global_asm_807149B8(1);
                        func_global_asm_807149FC(0x28);
                        func_global_asm_8071498C(func_global_asm_8071F078);
                        func_global_asm_80714950(gCurrentActorPointer->y_rotation);
                        func_global_asm_80714C08(&D_global_asm_80720B58, 0.7f, gCurrentActorPointer, 1, 0);
                    }
                    gCurrentActorPointer->control_state_progress++;
            }
            break;
        case 5:
            func_global_asm_80724A20();
            func_global_asm_806C151C(0xA, 1, TEMPFLAG_TEXT_LLAMA_CAGE);
            func_global_asm_806C13AC(4, 0x4F1, 0x4F7, 0x4F7, 0x4F7);
            if (func_global_asm_80629148()) {
                gCurrentActorPointer->control_state = 0x12;
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 18:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    playActorAnimation(gCurrentActorPointer, 0x2BF);
                    func_global_asm_806883F4(gCurrentActorPointer, 0, 2, 0);
                    func_global_asm_8072B324(gCurrentActorPointer, D_global_asm_807FDC9C->unkC);
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 2:
                    func_global_asm_8072AB74(2, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
                    func_global_asm_8072D13C(2, 0);
                    break;
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C226C(void) {
    s16 i;

    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->y_acceleration = D_global_asm_807502F4;
        gCurrentActorPointer->y_position = gCurrentActorPointer->floor;
        gCurrentActorPointer->draw_distance = 0x4B0;
        if (isFlagSet(PERMFLAG_PROGRESS_SEAL_FREED, FLAG_TYPE_PERMANENT)) {
            if (D_global_asm_807FDC9C->unk13 == 0x16) {
                gCurrentActorPointer->control_state = 0x28;
                gCurrentActorPointer->control_state_progress = 0;
            } else {
                gCurrentActorPointer->control_state = 0x40;
            }
        } else if (D_global_asm_807FDC9C->unk13 == 0x16) {
            gCurrentActorPointer->control_state = 0x40;
        }
    }
    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        if (D_global_asm_807FBDC8[i] == 3) {
            playActorAnimation(gCurrentActorPointer, 0x2A3);
            gCurrentActorPointer->control_state = 0x27;
            gCurrentActorPointer->control_state_progress = 0;
            playCutscene(gCurrentActorPointer, 0x16, 1);
            setFlag(PERMFLAG_PROGRESS_SEAL_FREED, TRUE, FLAG_TYPE_PERMANENT);
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 39:
            if (gCurrentActorPointer->unk6A & 4) {
                func_global_asm_8072A920(2, 0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkC, D_global_asm_807FDC90->unkE, 0x46, 30.0f, 100.0f, 0);
                if (RandChance(0.07)) {
                    func_global_asm_8071498C(func_global_asm_80718BF4);
                    func_global_asm_807149B8(1);
                    func_global_asm_807149FC(-1);
                    drawSpriteAtPosition(&D_global_asm_8071FC40, 0.0f, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position);
                }
            } else {
                if ((gCurrentActorPointer->unk6A ^ gCurrentActorPointer->unk6C) & 1) {
                    playActorAnimation(gCurrentActorPointer, 0x2A4);
                }
                func_global_asm_8072AB74(2, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x200, 0.0f);
                if (gCurrentActorPointer->y_velocity < -10.0f) {
                    gCurrentActorPointer->z_rotation = func_global_asm_806CC190(gCurrentActorPointer->z_rotation, 0x400, 10.0f);
                }
            }
            func_global_asm_8072D13C(2, 0);
            if (func_global_asm_80629148()) {
                gCurrentActorPointer->control_state = 0x40;
            }
            break;
        case 40:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0x0:
                    func_global_asm_80724B5C(2, 3, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
                    playActorAnimation(gCurrentActorPointer, 0x2A6);
                    gCurrentActorPointer->z_rotation = 0;
                    gCurrentActorPointer->control_state_progress++;
                    // Fallthrough
                case 0x1:
                    if (func_global_asm_8072E22C(0xC8) != 0) {
                        gCurrentActorPointer->control_state_progress++;
                        if (isFlagSet(PERMFLAG_ITEM_GB_GALLEON_SEALFREE, FLAG_TYPE_PERMANENT) != 0) {
                            if ((current_character_index[0] == 0) && !isFlagSet(PERMFLAG_ITEM_GB_GALLEON_SEALRACE, FLAG_TYPE_PERMANENT)) {
                                loadText(gCurrentActorPointer, 0x1C, 2);
                            } else if (current_character_index[0] != 0) {
                                loadText(gCurrentActorPointer, 0x1C, 0);
                            }
                        } else if (current_character_index[0] == 0) {
                            playCutscene(gCurrentActorPointer, 0x1E, 1);
                            func_global_asm_8070E8DC(1);
                            loadText(gCurrentActorPointer, 0x1C, 1);
                            gCurrentActorPointer->control_state_progress = 0x63;
                        } else {
                            loadText(gCurrentActorPointer, 0x1C, 0);
                        }
                    }
                    break;
                case 0x2:
                    if (!isFlagSet(PERMFLAG_ITEM_GB_GALLEON_SEALFREE, FLAG_TYPE_PERMANENT) && (func_global_asm_8072E22C(0x12C) == 0)) {
                        gCurrentActorPointer->control_state_progress = 1;
                    }
                    break;
                case 0x63:
                    if ((func_global_asm_8061CB50() == 0) && !(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        loadText(gCurrentActorPointer, 0x1C, 2);
                        gCurrentActorPointer->control_state_progress = 3;
                    }
                    break;
            }
            func_global_asm_806335B0(D_global_asm_807F62B4, 1, 1, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806C27DC(void) {
    f32 scale;

    scale = gCurrentActorPointer->animation_state->scale_y / 0.15;
    func_global_asm_80604CBC(gCurrentActorPointer, 0x114, 0x50, 0, 0, 0xFF, 0.5f, 0);
    if (object_timer & 1) {
        func_global_asm_80684550(gCurrentActorPointer, 1, scale);
        func_global_asm_80684550(gCurrentActorPointer, 3, scale);
    } else {
        func_global_asm_80684550(gCurrentActorPointer, 2, scale);
        func_global_asm_80684550(gCurrentActorPointer, 4, scale);
    }
}

void func_global_asm_806C28B8(void) {
    f32 temp_f20;
    f32 x, y, z;
    f32 phi_f2;
    s16 i;
    s32 pad;

    phi_f2 = gCurrentActorPointer->animation_state->unk0->unk4;
    if (phi_f2 > 83.0f) {
        func_global_asm_806C27DC();
        phi_f2 = gCurrentActorPointer->animation_state->unk0->unk4;
    }
    if ((phi_f2 > 2.0f) && (phi_f2 < 90.0f)) {
        if ((object_timer % 6U) == 0) {
            temp_f20 = MIN(1, phi_f2 / 70.0);
            for (i = 1; i < 5; i++) {
                getBonePosition(gCurrentActorPointer, i, &x, &y, &z);
                func_global_asm_806852C4(MAX(0.15, temp_f20 * 0.3), x, y + 3.0f, z);
            }
        }
    }
}

void func_global_asm_806C2A64(u8 red, u8 green, u8 blue, f32 x, f32 y, f32 z, void *sprite, f32 scale) {
    func_global_asm_807149A8(1000);
    func_global_asm_80714998(0xFF);
    func_global_asm_80714944(RandClamp(32767) % 11);
    changeActorColor(red, green, blue, 0xFF);
    func_global_asm_8071498C(func_global_asm_80717D84);
    func_global_asm_80714950(2);
    drawSpriteAtPosition(sprite, scale * 0.2, x, y, z);
}

// close, stack, float, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806C2B2C.s")

void func_global_asm_806C2B2C(u8 boneIndex, u8 arg1, u8 colorIndex, void *sprite);

/*
void func_global_asm_806C2B2C(u8 boneIndex, u8 arg1, u8 colorIndex, void *sprite) {
    f32 temp_f20;
    f32 temp_f24;
    s16 i;
    f32 x1;
    f32 y1;
    f32 z1;
    f32 x2;
    f32 y2;
    f32 z2;

    temp_f24 = (gCurrentActorPointer->animation_state->scale_y / 0.3) / 1.5;
    while (arg1 >= boneIndex) {
        for (i = 0; i < 3.0; i++) {
            temp_f20 = (i / 3.0);
            getBonePosition(gCurrentActorPointer, boneIndex, &x1, &y1, &z1);
            if (boneIndex < arg1) {
                getBonePosition(gCurrentActorPointer, boneIndex + 1, &x2, &y2, &z2);
            } else {
                getBonePosition(gCurrentActorPointer, boneIndex, &x2, &y2, &z2);
            }
            func_global_asm_806C2A64(
                D_global_asm_80747B00[colorIndex].unk0,
                D_global_asm_80747B00[colorIndex].unk1,
                D_global_asm_80747B00[colorIndex].unk2,
                ((x2 - x1) * temp_f20) + x1,
                ((y2 - y1) * temp_f20) + y1,
                ((z2 - z1) * temp_f20) + z1,
                sprite,
                temp_f24
            );
        }
        boneIndex++;
    }
}
*/

void func_global_asm_806C2D7C(void) {
    func_global_asm_806C2B2C(1, 0xB, 6, &D_global_asm_8071FFA0);
    func_global_asm_806C2B2C(0x20, 0x30, 6, &D_global_asm_8071FFA0);
    func_global_asm_806C2B2C(0xC, 0x16, 2, &D_global_asm_8071FFA0);
    func_global_asm_806C2B2C(0x17, 0x1F, 2, &D_global_asm_8071FFA0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806C2DF4.s")

void func_global_asm_806C3A8C(void) {
    s32 d;
    u8 pad;

    d = (((gPlayerPointer->x_position - gCurrentActorPointer->x_position) * (gPlayerPointer->x_position - gCurrentActorPointer->x_position)) + ((gPlayerPointer->y_position - gCurrentActorPointer->y_position) * (gPlayerPointer->y_position - gCurrentActorPointer->y_position)) + ((gPlayerPointer->z_position - gCurrentActorPointer->z_position) * (gPlayerPointer->z_position - gCurrentActorPointer->z_position)));
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk15E = 0x19;
        func_global_asm_8067ACB4(gCurrentActorPointer);
        if (!isFlagSet(TEMPFLAG_CUTSCENE_MERMAID_FTCS, FLAG_TYPE_TEMPORARY)) {
            playCutscene(gCurrentActorPointer, 0x14, 1);
            setFlag(TEMPFLAG_CUTSCENE_MERMAID_FTCS, TRUE, FLAG_TYPE_TEMPORARY);
        }
        if (!isFlagSet(PERMFLAG_ITEM_GB_GALLEON_MERMAID, FLAG_TYPE_PERMANENT)) {
            if (isFlagSet(PERMFLAG_ITEM_PEARL_1, FLAG_TYPE_PERMANENT)
                && isFlagSet(PERMFLAG_ITEM_PEARL_2, FLAG_TYPE_PERMANENT)
                && isFlagSet(PERMFLAG_ITEM_PEARL_3, FLAG_TYPE_PERMANENT)
                && isFlagSet(PERMFLAG_ITEM_PEARL_4, FLAG_TYPE_PERMANENT)
                && isFlagSet(PERMFLAG_ITEM_PEARL_5, FLAG_TYPE_PERMANENT)) {
                gCurrentActorPointer->control_state = 0x27;
                gCurrentActorPointer->control_state_progress = 0;
            } else {
                if (isFlagSet(PERMFLAG_ITEM_PEARL_1, FLAG_TYPE_PERMANENT)
                    || isFlagSet(PERMFLAG_ITEM_PEARL_2, FLAG_TYPE_PERMANENT)
                    || isFlagSet(PERMFLAG_ITEM_PEARL_3, FLAG_TYPE_PERMANENT)
                    || isFlagSet(PERMFLAG_ITEM_PEARL_4, FLAG_TYPE_PERMANENT)
                    || isFlagSet(PERMFLAG_ITEM_PEARL_5, FLAG_TYPE_PERMANENT)) {
                        gCurrentActorPointer->control_state = 0x1F;
                        gCurrentActorPointer->control_state_progress = 0;
                    } else {
                        gCurrentActorPointer->control_state = 0x1E;
                        gCurrentActorPointer->control_state_progress = 0;
                    }
                }
        } else {
            gCurrentActorPointer->control_state = 0x20;
            gCurrentActorPointer->control_state_progress = 0;
        }
    }
    func_global_asm_806BFBF4();
    switch (gCurrentActorPointer->control_state) {
        case 30:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if ((u8)(d < 62500)) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 1:
                    if ((u8)(d < 10000)) {
                        playActorAnimation(gCurrentActorPointer, 0x3A4);
                        loadText(gCurrentActorPointer, 0x17, 0);
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
            }
            break;
        case 31:
            if ((u8)(d < 10000)) {
                if (gCurrentActorPointer->control_state_progress == 0) {
                    D_global_asm_80750AC8 = isFlagSet(PERMFLAG_ITEM_PEARL_1, FLAG_TYPE_PERMANENT)
                        + isFlagSet(PERMFLAG_ITEM_PEARL_2, FLAG_TYPE_PERMANENT)
                        + isFlagSet(PERMFLAG_ITEM_PEARL_3, FLAG_TYPE_PERMANENT)
                        + isFlagSet(PERMFLAG_ITEM_PEARL_4, FLAG_TYPE_PERMANENT)
                        + isFlagSet(PERMFLAG_ITEM_PEARL_5, FLAG_TYPE_PERMANENT);
                    loadText(gCurrentActorPointer, 0x17, 2);
                    gCurrentActorPointer->control_state_progress++;
                }
            }
            break;
        case 32:
            if ((u8)(d < 10000)) {
                if (gCurrentActorPointer->control_state_progress == 0) {
                    if (func_global_asm_8061CB50() == 0) {
                        playCutscene(gCurrentActorPointer, 0x18, 1);
                        loadText(gCurrentActorPointer, 0x17, 3);
                        gCurrentActorPointer->control_state_progress++;
                    }
                }
            }
            break;
        case 39:
            if (!func_global_asm_8061CB50()) {
                switch (gCurrentActorPointer->control_state_progress) {
                    case 0:
                        playCutscene(gCurrentActorPointer, 0x17, 1);
                        func_global_asm_8070E8DC(1);
                        loadText(gCurrentActorPointer, 0x17, 1);
                        gCurrentActorPointer->control_state_progress++;
                        break;
                    case 1:
                        if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                            func_global_asm_8063DA40(0xE, 0xA);
                            gCurrentActorPointer->control_state = 0x20;
                            gCurrentActorPointer->control_state_progress = 0;
                        }
                        break;
                }
            }
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}
