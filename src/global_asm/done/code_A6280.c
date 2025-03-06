#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_807506C0[];

extern u8 D_global_asm_807FBD70;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} AAD_global_asm_806A1FD8;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} AAD_806A2328;

void func_global_asm_806A1580(void) {
    s16 sp36;
    Actor *sp30;

    sp36 = func_global_asm_80688E68(gCurrentActorPointer);
    sp30 = getSpawnerTiedActor(2, 0);
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk130 = 0x46;
        gCurrentActorPointer->unk131 = 0x32;
        gCurrentActorPointer->unk6A &= 0xFFFE;
        gCurrentActorPointer->noclip_byte = 2;
        gCurrentActorPointer->object_properties_bitfield |= 0x80000000;
        gCurrentActorPointer->unk64 |= 0x28;
        func_global_asm_8068848C(gCurrentActorPointer, 0, 1);
    }
    if ((((gPlayerPointer->x_position - gCurrentActorPointer->x_position) * (gPlayerPointer->x_position - gCurrentActorPointer->x_position)) + ((gPlayerPointer->z_position - gCurrentActorPointer->z_position) * (gPlayerPointer->z_position - gCurrentActorPointer->z_position))) < 50000.0f) {
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
    } else {
        gCurrentActorPointer->object_properties_bitfield &= ~0x400;
    }
    if (sp30) {
        if (sp36 == D_global_asm_807506C0[sp30->unk15F]) {
            if ((((gCurrentActorPointer->x_position - gPlayerPointer->x_position) * (gCurrentActorPointer->x_position - gPlayerPointer->x_position)) + ((gCurrentActorPointer->z_position - gPlayerPointer->z_position) * (gCurrentActorPointer->z_position - gPlayerPointer->z_position))) > 900.0f) {
                sp30->unkEC = func_global_asm_80665AE4(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, gPlayerPointer->x_position, gPlayerPointer->z_position) - func_global_asm_80665AE4(character_change_array->look_at_at_x, character_change_array->look_at_at_z, character_change_array->look_at_eye_x, character_change_array->look_at_eye_z);
            }
            if (func_global_asm_80688540(gCurrentActorPointer, 0) == 0) {
                func_global_asm_80688370(gCurrentActorPointer, 0, 1.0f);
                func_global_asm_8068842C(gCurrentActorPointer, 0, -1);
            }
        } else if (func_global_asm_80688540(gCurrentActorPointer, 0) != 0) {
            func_global_asm_80688460(gCurrentActorPointer, 0, 1);
            func_global_asm_806883F4(gCurrentActorPointer, 0, 0, 0.0f);
        }
        if (D_global_asm_807FBD70 == 4) {
            if (gCurrentActorPointer->unk132 == 4) {
                gCurrentActorPointer->unk132 = 8;
                playSong(MUSIC_67_CHECKPOINT, 1.0f);
                func_global_asm_80679200(sp30, gCurrentActorPointer, 0x02000000, sp36, 0, 0);
            } else {
                gCurrentActorPointer->unk132 *= 2;
            }
        }
        if ((gPlayerPointer->unk6A & 1) && !gPlayerPointer->locked_to_pad) {
            gCurrentActorPointer->unk132 = 1;
        }
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A18A8(void) {
    A178_806A18A8 *sp44;
    Actor *sp40;

    sp44 = gCurrentActorPointer->a178_806A18A8;
    sp40 = gCurrentActorPointer->unk11C;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724CA4(2, 2);
    }
    moveAndScaleActorToAnother(gCurrentActorPointer, sp40, 0.15f);
    if (gCurrentActorPointer->control_state != 0) {
        func_global_asm_806B6600(1);
        if (sp44->unk1 == 0) {
            gCurrentActorPointer->control_state = 0;
        }
    }
    if (sp40->unkB8 != 0.0f) {
        if ((sp40->unkB8 > 50.0f) && (gCurrentActorPointer->animation_state->unk64 != 0x233)) {
            playActorAnimation(gCurrentActorPointer, 0x233);
        } else if ((sp40->unkB8 <= 50.0f) && (gCurrentActorPointer->animation_state->unk64 != 0x232)) {
            playActorAnimation(gCurrentActorPointer, 0x232);
        }
        func_global_asm_80614D00(gCurrentActorPointer, sp40->unkB8 * 0.01, 4.0f);
    } else if (gCurrentActorPointer->animation_state->unk64 != 0x234) {
        playActorAnimation(gCurrentActorPointer, 0x234);
    }
    func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0xA, 0xA, 1, 0x12C, 0xC8, 0, 1.0f);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A1ABC(void) {

}

void func_global_asm_806A1AC4(void) {
    f32 randomScale;
    s16 i;

    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->object_properties_bitfield &= 0xFFFF7FFF;
        func_global_asm_80728950(0);
        func_global_asm_807248B0(gCurrentActorPointer, 1.2f);
        gCurrentActorPointer->object_properties_bitfield |= 0x400;
        gCurrentActorPointer->draw_distance = 1000;
        if (isFlagSet(PERMFLAG_PROGRESS_BEANSTALK_GROWN, FLAG_TYPE_PERMANENT)) {
            func_global_asm_80613C48(gCurrentActorPointer, 0x597, 0, 0);
            func_global_asm_807289B0(0, 0);
            gCurrentActorPointer->control_state = 3;
        } else {
            func_global_asm_80613C48(gCurrentActorPointer, 0x598, 0, 0);
            func_global_asm_80614D00(gCurrentActorPointer, 0, 0);
            gCurrentActorPointer->noclip_byte = 1;
            gCurrentActorPointer->object_properties_bitfield &= ~4;
        }
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            if ((D_global_asm_807FBB70.unk254 != 0) && (D_global_asm_807FBB70.unk258[0] == 1)) {
                func_global_asm_8070DA74(gCurrentActorPointer);
                loadText(gCurrentActorPointer, 0x1F, 1);
                playCutscene(gCurrentActorPointer, 0x12, 1);
                setFlag(PERMFLAG_PROGRESS_BEANSTALK_GROWN, TRUE, FLAG_TYPE_PERMANENT);
                gCurrentActorPointer->control_state = 1;
            } else if (!isFlagSet(PERMFLAG_PROGRESS_BEANSTALK_GROWN, FLAG_TYPE_PERMANENT) && !isFlagSet(TEMPFLAG_FTT_NO_BEAN, FLAG_TYPE_TEMPORARY)) {
                if ((((gCurrentActorPointer->x_position - gPlayerPointer->x_position) * (gCurrentActorPointer->x_position - gPlayerPointer->x_position)) + ((gCurrentActorPointer->z_position - gPlayerPointer->z_position) * (gCurrentActorPointer->z_position - gPlayerPointer->z_position))) < 19600.0f) {
                    loadText(gPlayerPointer, 0x1F, 0);
                    setFlag(TEMPFLAG_FTT_NO_BEAN, TRUE, FLAG_TYPE_TEMPORARY);
                }
            }
            break;
        case 1:
            if ((D_global_asm_807FBB70.unk254 != 0) && (D_global_asm_807FBB70.unk258[0] == 1)) {
                playActorAnimation(gCurrentActorPointer, 0x328);
                gCurrentActorPointer->control_state = 2;
                gCurrentActorPointer->noclip_byte = 2;
                gCurrentActorPointer->object_properties_bitfield |= 4;
            }
            break;
        case 2:
            switch (gCurrentActorPointer->control_state_progress) {
                case 0:
                    if ((object_timer & 7) == 0) {
                        for (i = 0; i < 0xC; i++) {
                            randomScale = ((RandClamp(32767) % 171) + 0x96) * 0.01;
                            func_global_asm_8071498C(func_global_asm_8071E864);
                            func_global_asm_80714950(i);
                            func_global_asm_807149B8(1);
                            changeActorColor(0x8C, 0x8C, 0x8C, 0xFF);
                            func_global_asm_80714998(5);
                            drawSpriteAtPosition(&D_global_asm_8071FFA0, randomScale, gCurrentActorPointer->x_position, gCurrentActorPointer->y_position + 50.0f, gCurrentActorPointer->z_position);
                        }
                    }
                    break;
                case 2:
                    func_global_asm_807289B0(0, 0);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 4:
                    func_global_asm_807289B0(0, 2);
                    gCurrentActorPointer->control_state_progress++;
                    break;
                case 6:
                    func_global_asm_807289B0(0, 0);
                    gCurrentActorPointer->control_state++;
                    break;
            }
            break;
        case 3:
            func_global_asm_8072881C(0, &gCurrentActorPointer->unkEC);
            break;
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A1F28(void) {
    gCurrentActorPointer->object_properties_bitfield |= 0x400;
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A1F64(void) {
    if (func_global_asm_8061CB50()) {
        func_global_asm_80613C48(gCurrentActorPointer, 0x640, 0, 8.0f);
    } else {
        func_global_asm_80613C48(gCurrentActorPointer, 0x63F, 0, 8.0f);
    }
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A1FD0(void) {

}

void func_global_asm_806A1FD8(void) {
    s32 var_v1;
    AAD_global_asm_806A1FD8 *aaD;
    s32 i;
    u8 var_a1;
    f32 x, y, z;
    Actor *temp_s0;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->unk64 |= 8;
        aaD->unk0 = 0;
        aaD->unk4 = 0.0f;
        aaD->unk8 = gCurrentActorPointer->y_position;
        gCurrentActorPointer->unk130 = 0x46;
        gCurrentActorPointer->unk131 = 0x14;
        if (isFlagSet(func_global_asm_80688C30(func_global_asm_80688E68(gCurrentActorPointer)), FLAG_TYPE_PERMANENT)) {
            deleteActor(gCurrentActorPointer);
        }
    }
    if ((gPlayerPointer->control_state == 0x2D) && (gPlayerPointer->control_state_progress != 0)) {
        var_a1 = FALSE;
        if (gCurrentActorPointer->unk114 != NULL) {
            var_v1 = gCurrentActorPointer->unk114->unk10;
            i = 0;
            while (var_v1 != 0 && !var_a1) {
                temp_s0 = gCurrentActorPointer->unk114->unk0[i];
                if ((func_global_asm_8067AF44(temp_s0) != 0) && (temp_s0 == gPlayerPointer)) {
                    var_a1 = TRUE;
                }
                var_v1--;
                i++;
            }
        }
        if (var_a1 && aaD->unk0 == 0) {
            for (i = 1; i < 9; i++) {
                func_global_asm_80714998(2);
                func_global_asm_807149B8(1);
                func_global_asm_8071498C(func_global_asm_80717D4C);
                func_global_asm_80714950(-0x64);
                changeActorColor(0x64, 0x46, 0x1E, 0xFF);
                getBonePosition(gCurrentActorPointer, i, &x, &y, &z);
                drawSpriteAtPosition(&D_global_asm_8071FF18, 2.0f, x, y + 10.0, z);
            }
            aaD->unk0 = 0xF;
            playSoundAtActorPosition(gCurrentActorPointer, 0x1C1, 0xFF, 0x7F, 1);
        }
    }
    if (aaD->unk0 >= 2) {
        aaD->unk0--;
    }
    if (aaD->unk0 == 2) {
        func_global_asm_806A5DF0(0x8C,
            gCurrentActorPointer->x_position,
            gCurrentActorPointer->y_position + 10.0f,
            gCurrentActorPointer->z_position,
            0,
            1,
            func_global_asm_80688C30(func_global_asm_80688E68(gCurrentActorPointer)),
            0
        );
    }
    if ((aaD->unk0 < 0xA) && (aaD->unk0 != 0)) {
        aaD->unk4 = aaD->unk4 + 1.0;
        if (aaD->unk4 > 20.0) {
            playSong(MUSIC_144_DROP_RAINBOW_COIN, 1.0f);
            deleteActor(gCurrentActorPointer);
        }
    }
    gCurrentActorPointer->y_position -= aaD->unk4;
    renderActor(gCurrentActorPointer, 0);
    gCurrentActorPointer->y_position = aaD->unk8;
}

void func_global_asm_806A2328(void) {
    f32 dx;
    f32 temp_f0_2;
    Actor *temp_v0_3;
    f32 dz;
    f64 temp_f12;
    AAD_806A2328 *aaD;

    aaD = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x1000;
        func_global_asm_807248B0(gCurrentActorPointer, gCurrentActorPointer->unk124->unkC);
        gCurrentActorPointer->unk168 = func_global_asm_80665DE0(gCurrentActorPointer->x_position, gCurrentActorPointer->z_position, gPlayerPointer->x_position, gPlayerPointer->z_position);
        gCurrentActorPointer->unkF0 = ((gPlayerPointer->y_position + gPlayerPointer->unk15E) - gCurrentActorPointer->y_position) * 0.5;
        dx = gCurrentActorPointer->x_position - gPlayerPointer->x_position;
        dz = gCurrentActorPointer->z_position - gPlayerPointer->z_position;
        gCurrentActorPointer->unkEC = sqrtf(SQ(dx) + SQ(dz)) * 0.5;
        aaD->unk0 = gCurrentActorPointer->x_position + ((gPlayerPointer->x_position - gCurrentActorPointer->x_position) * 0.5);
        aaD->unk2 = gCurrentActorPointer->y_position + ((gPlayerPointer->y_position - gCurrentActorPointer->y_position) * 0.5);
        aaD->unk4 = gCurrentActorPointer->z_position + ((gPlayerPointer->z_position - gCurrentActorPointer->z_position) * 0.5);
        gCurrentActorPointer->noclip_byte = 0x24;
        gCurrentActorPointer->unkFA = 9000;
        gCurrentActorPointer->unk160 = gCurrentActorPointer->unk124->unk4;
        temp_f12 = (gCurrentActorPointer->unk160) * (gCurrentActorPointer->unkEC * 0.01);
        gCurrentActorPointer->unk160 = MIN(MAX(temp_f12, 15.0), 150.0);
        aaD->unk8 = gCurrentActorPointer->unk160;
    }
    func_global_asm_8067ACB4(gCurrentActorPointer);
    temp_f0_2 = ((aaD->unk8 / gCurrentActorPointer->unk160) * -4096.0) + 4096.0;
    aaD->unk6 = gCurrentActorPointer->unk168 + temp_f0_2;
    gCurrentActorPointer->x_position = (func_global_asm_80612794(aaD->unk6) * gCurrentActorPointer->unkEC) + aaD->unk0;
    gCurrentActorPointer->z_position = (func_global_asm_80612790(aaD->unk6) * gCurrentActorPointer->unkEC) + aaD->unk4;
    gCurrentActorPointer->y_position = (func_global_asm_80612790(2048.0f + temp_f0_2) * gCurrentActorPointer->unkF0) + aaD->unk2;
    func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    gCurrentActorPointer->y_rotation += 0x12C;
    if ((gCurrentActorPointer->y_rotation & 0x7FF) < 0x12C) {
        playSoundAtPosition(gCurrentActorPointer->x_position, gCurrentActorPointer->y_position, gCurrentActorPointer->z_position, 0x1DF, 0xFF, 0x7F, 0x14, 0x3C, 0.7f, 0);
    }
    if (aaD->unk8 != 0) {
        aaD->unk8--;
        if (aaD->unk8 == 0xB) {
            temp_v0_3 = gCurrentActorPointer->unk11C;
            if (temp_v0_3 != NULL) {
                temp_v0_3->control_state_progress++;
            }
        }
    } else {
        deleteActor(gCurrentActorPointer);
    }
    func_global_asm_8065D244(1);
    func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x12C, 0xB4, 0, 1.0f);
    renderActor(gCurrentActorPointer, 0);
}

void func_global_asm_806A285C(void) {
    s16 spBE;
    s16 spBC;
    f32 sp7C[4][4];
    f32 sp3C[4][4];

    func_global_asm_80699070(&spBE, &spBC, character_change_array[0].look_at_eye_x, character_change_array[0].look_at_eye_y, character_change_array[0].look_at_eye_z, character_change_array[0].look_at_at_x, character_change_array[0].look_at_at_y, character_change_array[0].look_at_at_z);
    gCurrentActorPointer->y_rotation = spBC;
    gCurrentActorPointer->z_rotation = spBE;
    guRotateF(sp7C, (spBE / 4095.0) * 360.0, 1.0f, 0.0f, 0.0f);
    guRotateF(sp3C, (spBC / 4095.0) * 360.0, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp7C, sp3C, sp7C);
    guTranslateF(sp3C, character_change_array[0].look_at_eye_x, character_change_array[0].look_at_eye_y, character_change_array[0].look_at_eye_z);
    guMtxCatF(sp7C, sp3C, sp7C);
    guMtxXFMF(sp7C, 0.0f, 0.0f, -11.0f, &gCurrentActorPointer->x_position, &gCurrentActorPointer->y_position, &gCurrentActorPointer->z_position);
    guTranslateF(&gCurrentActorPointer->unkC, 0.0f, -20.0f, 0.0f);
    renderActor(gCurrentActorPointer, 1);
}
