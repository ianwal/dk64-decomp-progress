#include <ultra64.h>
#include "functions.h"

/* structs */
typedef struct {
    u8 unk0[0x10 - 0x0];
    s16 unk10;
    char unk12[0x1E];
    u8 *unk30;
    u8 *unk34;
    u8 unk38[2];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
    char unk3E[4];
    u8 unk42;
} AAD_minecart_80027DA0;

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
    s16 unk3C;
    u8 unk3E;
    u8 unk3F;
} Struct80024254_arg0;

typedef struct minecart_struct_0 {
    u8 pad0[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
} MinecartStruct0;

typedef struct {
    s32 unk0;
    Actor *unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    u8 unk14[0x30 - 0x14];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s16 unk3C;
    s8 unk3E;
} AAD_minecart_8002430C;

typedef struct {
    s16 unk0;
    s16 unk2;
    Actor *unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    f32 unk28;
} AAD_minecart_80024890;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} TEMP3;

typedef struct {
    s32 unk0; // Unused
    Actor *unk4;
    u8 unk8[0x24 - 0x8]; // Unused
    f32 unk24;
    f32 unk28;
    s32 unk2C; // Unused
    u8 *unk30;
    s32 unk34;
    s32 unk38; // Unused
    s16 unk3C; // Unused
    u8 unk3E;
} AAD_minecart_80024FD0;

/* variables */
extern void *D_minecart_80028C30; // TODO: Proper datatype
extern s32 D_minecart_80028C34[]; // TODO: Datatype
extern s32 D_minecart_80028C3C[]; // TODO: Datatype
extern s32 D_minecart_80028C40[]; // TODO: Datatype
extern s16 D_global_asm_807502D0;
extern f32 D_global_asm_807502F8;
extern s16 D_global_asm_80750338;
extern s16 D_global_asm_80750AC4;
extern s32 D_minecart_80028C20;

/* function signatures */
void func_minecart_80024E78(AAD_minecart_80027DA0* arg0, s32* arg1[], u8 arg2, u8 arg3);
void func_minecart_800253C0(AAD_minecart_80027DA0*, s16, u8);
void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2);

void func_minecart_80024000(u8 arg0, u8 arg1) {
    playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_global_asm_8069D2AC(0x81, 0, 0x78, getTextString(0x1A, arg1, 1), 0, 0x28, 8, 8);
    gCurrentActorPointer->unk11C->control_state = 0;
    playSong(MUSIC_40_SUCCESS, 1.0f);
    setAction(0x44, NULL, 0);
    gCurrentActorPointer->control_state++;
    if (arg0 != 0) {
        playCutscene(gPlayerPointer, 5, 5);
    }
}

void func_minecart_800240DC(u8 arg0, u8 arg1) {
    char *temp = getTextString(0x1A, arg1, 1);
    func_global_asm_8069D2AC(0x81, 0, 0x78, temp, 0, 0x28, 8, 8);
    gCurrentActorPointer->unk11C->control_state = 0;
    playSong(MUSIC_42_FAILURE, 1.0f);
    setAction(0x43, NULL, 0);
    gCurrentActorPointer->control_state++;
    if (arg0 != 0) {
        playCutscene(gPlayerPointer, 5, 5);
    }
}

void func_minecart_800241A0(s16 *arg0, u8 arg1, u8 arg2) {
    // TODO: Get rid of this typecast if possible
    if (((func_global_asm_806119A0() & 0xFF) >= (u32)arg2) && (*arg0 == 0)) {
        playSoundAtActorPosition(gCurrentActorPointer, 0x8A, 0x96, 0x7F, 0x32);
        func_global_asm_80714950((s32)gCurrentActorPointer);
        func_global_asm_8071498C(func_global_asm_8071A440);
        D_minecart_80028C30 = func_global_asm_80714C08(&D_global_asm_8072006C, 0.4f, gCurrentActorPointer, arg1 + 7, 2);
    }
}

void func_minecart_80024254(Struct80024254_arg0 *arg0) {
    u8 temp = arg0->unk3E;
    if (gCurrentActorPointer->unkB8 != temp) {
        if (gCurrentActorPointer->unkB8 < temp) {
            if (temp < gCurrentActorPointer->unkB8 + 8.0f) {
                gCurrentActorPointer->unkB8 = temp;
            } else {
                gCurrentActorPointer->unkB8 += 8.0f;
            }
        } else if (temp < gCurrentActorPointer->unkB8) {
            if (gCurrentActorPointer->unkB8 - 8.0f < temp) {
                gCurrentActorPointer->unkB8 = temp;
            } else {   
                gCurrentActorPointer->unkB8 -= 8.0f;
            }
        }
    }
}

void func_minecart_8002430C(u8 arg0, s32 arg1, s16 arg2, u8 arg3) {
    AAD_minecart_8002430C *aaD;
    PlayerAdditionalActorData *PaaD;
    s32 pad8;
    s32 pad7;
    s32 pad6;
    s32 pad5;
    s32 pad4;
    s32 pad3;
    s32 pad2;
    s32 pad;
    f32 dx, dz, dy;
    f32 z, y, x;

    aaD = gCurrentActorPointer->additional_actor_data;
    PaaD = character_change_array->playerPointer->PaaD;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->object_properties_bitfield |= 0x1400;
        switch (current_map) {
            case MAP_JAPES_MINECART:
            case MAP_FUNGI_MINECART:
            case MAP_CASTLE_MINECART:
                func_global_asm_806F8BC4(0xB, 1, 0);
                D_global_asm_80750AC4 = 0;
                break;
        }
    }
    if (aaD->unk4 == NULL) {
        aaD->unk4 = character_change_array->playerPointer;
        aaD->unk8 = 0;
    }
    switch (gCurrentActorPointer->control_state) {
        case 0:
            dx = aaD->unk4->x_position - gCurrentActorPointer->x_position;
            dy = aaD->unk4->y_position - gCurrentActorPointer->y_position;
            dz = aaD->unk4->z_position - gCurrentActorPointer->z_position;
            if ((SQ(dx) + SQ(dy) + SQ(dz)) < SQ(20.0f)) {
                aaD->unk34 = arg1;
                aaD->unk10 = arg0;
                aaD->unk30 = arg1;
                setAction(0x45, gCurrentActorPointer, aaD->unk8);
                gCurrentActorPointer->control_state++;
            } else {
                renderActor(gCurrentActorPointer, 0);
                break;
            }
            // fallthrough
        case 1:
            func_minecart_800253C0(aaD, arg2, arg3);
            func_global_asm_8061C6A8(PaaD->unk104, gCurrentActorPointer, 4, 0x800, 0x28, 0, 5, 0x19, 0x14, 0, 0.15f);
            gCurrentActorPointer->control_state++;
            break;
        case 2:
            getBonePosition(gCurrentActorPointer, 9, &aaD->unk4->x_position, &aaD->unk4->y_position, &aaD->unk4->z_position);
            gCurrentActorPointer->control_state++;
            if (gCurrentActorPointer->unk168 == 0) {
                if (current_map != MAP_JAPES_MINECART) {
                    gCurrentActorPointer->unk168 = 2;
                }
            }
            // fallthrough
        case 3:
        case 5:
            if (gCurrentActorPointer->unk168 == 0) {
                if (func_global_asm_8061CB50() != 0) {
                    gCurrentActorPointer->unk168 = 1;
                }
            }
            if (gCurrentActorPointer->unk168 == 1) {
                if (gCurrentActorPointer->control_state_progress == 0) {
                    if (func_global_asm_8061CB50() != 0) {
                        PaaD->unk1F0 = PaaD->unk1F0 | 8;
                    } else {
                        func_global_asm_8061C6A8(PaaD->unk104, gCurrentActorPointer, 4, 0x800, 0x28, 0, 5, 0x19, 0x14, 0, 0.15f);
                        PaaD->unk1F0 = PaaD->unk1F0 & ~8;
                        aaD->unk3E = 0x3C;
                        gCurrentActorPointer->control_state_progress++;
                    }
                }
            }
            func_global_asm_8068ECF4(6, 0xFF);
            func_minecart_80024254(aaD);
            func_minecart_800253C0(aaD, arg2, arg3);
            getBonePosition(gCurrentActorPointer, 5, &x, &y, &z);
            addActorRecolor(gCurrentActorPointer, x, y, z, 0xFF, 0xFF, 0xFF, 0xFF, 0);
            addActorRecolor(aaD->unk4, x, y, z, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    }
}

void func_minecart_80024768(void) {
    f32 z2, y2, x2;
    f32 z1, y1, x1;

    if (extra_player_info_pointer->unk1F0 & 0x10000002) {
        getBonePosition(gCurrentActorPointer, 2, &x1, &y1, &z1);
        getBonePosition(gCurrentActorPointer, 1, &x2, &y2, &z2);
    } else {
        getBonePosition(gCurrentActorPointer, 1, &x1, &y1, &z1);
        getBonePosition(gCurrentActorPointer, 2, &x2, &y2, &z2);
    }
    func_global_asm_8065A6F8(0xC8);
    func_global_asm_8065A660(20.0f, 40.0f);
    createLight(x1, y1, z1, x2, y2, z2, 0.0f, 1, 0xFF, 0xFF, 0xFF);
}

void func_minecart_80024890(void) {
    AAD_minecart_80024890 *temp_v1;

    temp_v1 = gCurrentActorPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        temp_v1->unk24 = 0.1f;
        temp_v1->unk28 = 5.0f;
    }
    func_minecart_8002430C(1, current_map == 6 ? &D_minecart_80028C34 : &D_minecart_80028C3C, 0x7FFF, 0x23);
    func_minecart_80024768();
}

void func_minecart_80024914(void) {
    f32 temp;
    s32 temp2; // TODO: Hmm..
    s16 temp_a1;
    Actor *temp_v0_2;
    AAD_minecart_80024890 *temp_s0;

    temp = gCurrentActorPointer->animation_state->scale_y * 0.166666666749999998;
    temp_s0 = gCurrentActorPointer->additional_actor_data;
    temp_a1 = temp_s0->unk0;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->terminal_velocity = D_global_asm_807502D0;
        temp_s0->unk24 = 3.0f;
        temp_s0->unk28 = 12.0f;
    }
    if (temp_s0->unk10 == 0x90) {
        gCurrentActorPointer->unkB8 = 130.0f;
        gCurrentActorPointer->y_acceleration = D_global_asm_807502F8 * 0.6;
        if (temp_s0->unk0 == 0) {
            gCurrentActorPointer->y_velocity = D_global_asm_80750338 * 1.6;
        }
    } else {
        gCurrentActorPointer->y_acceleration = D_global_asm_807502F8;
    }
    temp_s0->unk0 = temp_s0->unk0 + (gCurrentActorPointer->y_velocity * temp);
    func_global_asm_80729E6C();
    if (temp_s0->unk0 < 0) {
        temp_s0->unk0 = 0;
        if (temp_a1 != 0) {
            playSoundAtActorPosition(gCurrentActorPointer, 0x8B, 0xFF, 0x7F, 0x1E);
        }
    }
    func_minecart_8002430C(3, &D_minecart_80028C40, temp_s0->unk2, 0x19);
    if ((gPlayerPointer->unk12C != 0x12) && (gPlayerPointer->unk12C != 0xB)) {
        func_minecart_80024768();
    }
    if (gCurrentActorPointer->control_state != 0) {
        temp_v0_2 = temp_s0->unk4;
        getBonePosition(gCurrentActorPointer, 9, &temp_v0_2->x_position, &temp_v0_2->y_position, &temp_v0_2->z_position);
    }
}

// long, structs
// https://decomp.me/scratch/3Hkbw
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_minecart_80024B00.s")

/*
extern s32 D_global_asm_807F5FD0;
extern s32 D_minecart_80028C48[];
extern s32 D_minecart_80028C50[];

typedef struct {
    s16 unk0;
    s16 unk2;
    Actor *unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    u8 unk14[0x24 - 0x14];
    f32 unk24;
    f32 unk28;
    s32 unk34;
} AAD_minecart_80024B00;

void func_minecart_80024B00(void) {
    s16 sp4E;
    tuple_f sp3C;
    Struct807F5FD4_unk0* temp_t7_2;
    tuple_f* temp_t8;
    Struct807F5FD4_unk0* temp_t8_2;
    Struct807F5FD4_unk0* temp_t9;
    Struct807F5FD4_unk0* temp_v0;
    Struct807F5FD4_unk0* temp_a2;
    Struct807F5FD4_unk0** temp_a2_2;
    f32 temp_f0;
    s16 j;
    s16 i;
    s32 temp_lo;
    s32 temp_t4;
    s32 temp_t7;
    Actor *temp_v0_2;
    u8 var_v0;
    AAD_minecart_80024B00* aaD;

    aaD = gCurrentActorPointer->additional_actor_data;
    temp_f0 = gCurrentActorPointer->animation_state->scale[1] * 0.16666666675;
    sp4E = aaD->unk0;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        func_global_asm_807248B0(gPlayerPointer, 0.12f);
        gCurrentActorPointer->y_acceleration = D_global_asm_807502F8;
        gCurrentActorPointer->terminal_velocity = D_global_asm_807502D0;
        aaD->unk24 = 0.1f;
        aaD->unk28 = 5.0f;
    }
    aaD->unk0 += (gCurrentActorPointer->y_velocity * temp_f0);
    func_global_asm_80729E6C();
    if (aaD->unk0 < 0) {
        aaD->unk0 = 0;
        if (sp4E != 0) {
            playSoundAtActorPosition(gCurrentActorPointer, 0x8B, 0xFFU, 0x7F, 0x1EU);
        }
    }
    if (gPlayerPointer->unk6A & 0x100) {
        gPlayerPointer->unk6A &= 0xFEFF;
        gCurrentActorPointer->unk168 = 2;
    }
    func_minecart_8002430C(1U, &D_minecart_80028C48, 0x7FFF, 0x23U);
    func_minecart_80024768();
    if ((aaD->unk34 >= 7) && (func_global_asm_8061CB50()) && (gCurrentActorPointer->control_state != 5)) {
        gCurrentActorPointer->unkB8 = 300.0f;
    }
    if (gCurrentActorPointer->control_state == 4) {
        for (i = 0; i < D_global_asm_807F5FD0; i++) {
            temp_a2 = &D_global_asm_807F5FD4->unk0[i];
            j = 0;
            temp_lo = (s32) (temp_a2->unk4 - temp_a2->unk0) / 12;
            temp_t4 = (s16) temp_lo / 2;
            while (j < temp_t4) {
                temp_a2_2 = &D_global_asm_807F5FD4->unk0[i];
                temp_t8 = &D_global_asm_807F5FD4->unk0[i][j];
                temp_t7 = (s16) temp_lo - j;
                sp3C.x = temp_t8->x;
                sp3C.y = temp_t8->y;
                sp3C.z = temp_t8->z;
                temp_v0 = *temp_a2_2;
                temp_t8_2 = &temp_v0[temp_t7];
                temp_t9 = &temp_v0[j];
                // temp_t9->unk0 = temp_t8_2->unk-C;
                // temp_t9->unk4 = temp_t8_2->unk-8;
                // temp_t9->unk8 = temp_t8_2->unk-4;
                temp_t7_2 = &D_global_asm_807F5FD4->unk0[i][temp_t7];
                // temp_t7_2->unk-C = (f32) sp3C.unk0;
                j += 1;
                // temp_t7_2->unk-8 = (f32) sp3C.unk4;
                // temp_t7_2->unk-4 = (f32) sp3C.unk8;                    
            }
        }
        aaD->unk34 = &D_minecart_80028C50;
        aaD->unk10 = 2;
        gCurrentActorPointer->control_state = 5;
        aaD->unkC = 0;
    }
    if (gCurrentActorPointer->control_state != 0) {
        temp_v0_2 = aaD->unk4;
        getBonePosition(gCurrentActorPointer, 9, &temp_v0_2->x_position, &temp_v0_2->y_position, &temp_v0_2->z_position);
    }
}
*/

void func_minecart_80024E78(AAD_minecart_80027DA0* arg0, s32* arg1[], u8 arg2, u8 arg3) {
    s32 var_s3;
    u8 temp_s5;
    TEMP3 *temp_v0_2;
    TEMP3 *temp_s1;
    u8 i;

    temp_s5 = *arg0->unk34;
    for (i = 0, var_s3 = FALSE; i < 4 && !var_s3; i++) {
        if (((arg0->unk42 == 1) && (i < 2)) || ((arg0->unk42 == 2) && (i >= 2))) {
            temp_s1 = arg1[temp_s5 - arg2] + i;
            if ((temp_s5 >= arg2) && (arg3 >= temp_s5) && (arg0->unk10 == temp_s1->unk0)) {
                free(arg0->unk30);
                var_s3 = TRUE;
                temp_v0_2 = malloc(3);
                arg0->unk34 = arg0->unk30 = temp_v0_2;
                arg0->unk34[0] = temp_s1->unk3;
                arg0->unk34[1] = temp_s1->unk1;
                arg0->unk34[2] = 0xFF;
                arg0->unk3E[3] = temp_s1->unk2;
                arg0->unk10 = 1;
            }
        }
    }
}

void func_minecart_80024FD0(void) {
    AAD_minecart_80024FD0 *aaD;
    PlayerAdditionalActorData* PaaD;
    s32 var_v0;
    s32 var_v1;

    aaD = gCurrentActorPointer->additional_actor_data;
    PaaD = gPlayerPointer->additional_actor_data;
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        aaD->unk30 = malloc(3);
        aaD->unk30[0] = 0x10;
        aaD->unk30[1] = 0xFF;
        aaD->unk24 = 3.0f;
        aaD->unk28 = 12.0f;
        gCurrentActorPointer->unk168 = 3;
        PaaD->unk1F0 = PaaD->unk1F0 | 8;
        playCutscene(gCurrentActorPointer, 0, 1);
        playActorAnimation(gCurrentActorPointer, 0);
    }
    if ((gCurrentActorPointer->control_state != 5) && (gCurrentActorPointer->control_state != 6)) {
        f32 dy = (character_change_array->look_at_eye_y - gCurrentActorPointer->y_position) - 100.0f;
        f32 temp = (dy / 650.0 * (3.0/20.0)) + 0.15;
        func_global_asm_807248B0(gCurrentActorPointer, temp);
        func_global_asm_807248B0(gPlayerPointer, temp);
    }
    if (PaaD->unk1F0 & 8) {
        aaD->unk3E = 3;
    }
    if (gCurrentActorPointer->control_state < 5) {
        func_minecart_8002430C(0x16, aaD->unk30, 0, 0x19);
    }
    if (func_global_asm_8061CB50() == 0) {
        func_global_asm_8061C2F0(PaaD->unk104, 322.0f, 900.0f, 268.0f, 325.0f, -9000.0f, 500.0f, 0);
    }
    switch (gCurrentActorPointer->control_state) {
        case 1:
        case 2:
        case 3:
            if (gCurrentActorPointer->animation_state->unk64 == 0x292) {
                func_minecart_800240DC(1, 0x14);
                gCurrentActorPointer->control_state = 5;
            } else if ((gCurrentActorPointer->unk11C != NULL) && (gCurrentActorPointer->unk11C->control_state == 5)) {
                func_global_asm_80726EE0(0);
                func_minecart_80024000(1, 0xE);
                gCurrentActorPointer->control_state = 5;
                break;
            }
            func_minecart_80024E78(aaD, &D_minecart_80028C20, 0x10, 0x13);
            getBonePosition(gCurrentActorPointer, 9, &aaD->unk4->x_position, &aaD->unk4->y_position, &aaD->unk4->z_position);
            break;
        case 4:
            gCurrentActorPointer->control_state = 3;
            aaD->unk34--;
            break;
        case 5:
            func_global_asm_807248B0(gCurrentActorPointer, 0.15f);
            func_global_asm_807248B0(gPlayerPointer, 0.225f);
            gCurrentActorPointer->x_rotation = 0;
            gCurrentActorPointer->control_state++;
            break;
        case 10:
            playSong(MUSIC_90_MINECART_MAYHEM, 1.0f);
            if (current_map == MAP_MINECART_MAYHEM_EASY) {
                var_v0 = 0x1E;
            } else {
                if (current_map == MAP_MINECART_MAYHEM_NORMAL) {
                    var_v1 = 0x2D;
                } else {
                    var_v1 = 0x3C;
                }
                var_v0 = var_v1;
            }
            func_global_asm_806A2A10(0x78, 0x78, var_v0);
            func_global_asm_806A2B08(gCurrentActorPointer->unk11C);
            PaaD->unk1F0 = PaaD->unk1F0 & ~8;
            gCurrentActorPointer->control_state = 3;
            break;
        default:
            break;
    }
}

void func_minecart_8002538C(MinecartStruct0 *arg0) {
    arg0->unk20 = arg0->unk20 + arg0->unk24;
    if (arg0->unk28 < arg0->unk20) {
        arg0->unk20 = arg0->unk28;
    }
}

// huge, struct, float, loop
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_0/func_minecart_800253C0.s")
