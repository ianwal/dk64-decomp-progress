#include "common.h"

typedef struct RaceStruct8 {
    u8 pad0[0x36];
    u8 unk36;
} RaceStruct8;

typedef struct RaceStruct9 {
    u8 pad0[0x1A];
    s16 unk1A; // Flag index
    s32 unk1C;
} RaceStruct9;

extern u16 D_global_asm_80750AC4;

// .data
typedef struct {
    s16 unk0;
    // s16 unk2; // PADDING
    f32 unk4;
    u8 unk8;
    // u8 unk9; // PADDING
    // u8 unkA; // PADDING
    // u8 unkB; // PADDING
} Struct8002FB10_race_8002FB70;

static Struct8002FB10_race_8002FB70 D_race_8002FB10[] = {
    { 0x0010, -360.0f, 0x00 },
    { 0x0011, -19.0f,  0x00 },
    { 0x0017, -20.0f,  0x01 },
    { 0x001B, -360.0f, 0x00 },
    { 0x001C, -17.0f,  0x00 },
    { 0x0033, -20.0f,  0x01 },
    { 0x0038, -20.0f,  0x02 },
    { 0x003C, -20.0f,  0x02 },
};
static Struct8002FB10_race_8002FB70 D_race_8002FB70[] = {
    { 0x0026, -20.0f, 0x01 },
    { 0x0028, -20.0f, 0x02 },
    { 0x0032, -20.0f, 0x02 },
};

static s32 D_race_8002FB94[] = {
    0x00000004,
    0x00000001,
    0x00000003,
    0x00000002,
    0x00000000, // PADDING
    0x00000000, // PADDING
    0x00000000, // PADDING
};

// TODO: Quite close, float nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80024000.s")

/*
void func_race_80024000(void) {
    f32 var_f0;
    f32 sp50;
    f32 temp_f0_2;
    f32 var_f12;
    f32 sp44;
    f32 sp40;
    f32 var_f22;
    f32 var_f20;
    u8 sp37;
    Struct8002FB10_race_8002FB70 *var_t0;
    s16 var_v1;

    sp37 = D_global_asm_807FDC90->unk24;
    if (current_map == MAP_CAVES_BEETLE_RACE) {
        var_t0 = &D_race_8002FB10;
    } else {
        var_t0 = &D_race_8002FB70;
    }
    sp44 = gCurrentActorPointer->unkB8;
    sp40 = func_global_asm_80612794(gCurrentActorPointer->unkE0 * 11.4) * 20.0f;
    if (sqrtf(((gCurrentActorPointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0) * (gCurrentActorPointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0)) + ((gCurrentActorPointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4) * (gCurrentActorPointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4))) < D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk7) {
        var_f12 = ABS(gCurrentActorPointer->y_position - (f32)D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk2);
        if (var_f12 < 80.0f) {
            if (D_global_asm_807FDC90->unk25 < (D_global_asm_807FDCA0->unk10 - 1)) {
                if (D_global_asm_807FDC90->unk25 == var_t0[sp37].unk0) {
                    gCurrentActorPointer->y_acceleration = var_t0[sp37].unk4;
                    if (var_t0[sp37].unk8 == 1) {
                        playActorAnimation(gCurrentActorPointer, 0x286);
                        gCurrentActorPointer->y_velocity = 200.0f;
                        gCurrentActorPointer->control_state++;
                    }
                    D_global_asm_807FDC90->unk24++;
                }
                D_global_asm_807FDC90->unk25++;
            }
        }
    }
    var_f0 = (gCurrentActorPointer->y_position - gCurrentPlayer->y_position);
    var_f0 *= 0.25f;
    var_f0 = MIN(6.0f, var_f0);
    var_f0 = MAX(-6.0f, var_f0);
    var_f0 += ((D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 - (gCurrentActorPointer->unkB8 / 10.0f)) * 0.8);
    var_v1 = (s16)((func_global_asm_80611BB4(-(gCurrentActorPointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0), -(gCurrentActorPointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4)) * 4096.0) / 6.28318548202514648) - gCurrentActorPointer->unkEE;
    if (var_v1 >= 0x800) {
        var_v1 -= 4096.0;
    }
    if (var_v1 < -0x800) {
        var_v1 += 4096.0;
    }
    sp50 = (gCurrentActorPointer->unkB8 * var_v1) / 10000.0;
    var_f20 = func_global_asm_80612794(gCurrentActorPointer->unkEE) * sp44;
    var_f22 = func_global_asm_80612790(gCurrentActorPointer->unkEE) * sp44;
    if (gCurrentActorPointer->unk6A & 1) {
        var_f20 += func_global_asm_80612794(gCurrentActorPointer->unkDC) * sp40;
        var_f22 += func_global_asm_80612790(gCurrentActorPointer->unkDC) * sp40;
    }
    var_f20 += (func_global_asm_80612794(gCurrentActorPointer->unkEE) * var_f0) + (func_global_asm_80612790(gCurrentActorPointer->unkEE) * sp50);
    var_f22 += (func_global_asm_80612790(gCurrentActorPointer->unkEE) * var_f0) - (func_global_asm_80612794(gCurrentActorPointer->unkEE) * sp50);
    sp44 = sqrtf((var_f20 * var_f20) + (var_f22 * var_f22));
    temp_f0_2 = func_global_asm_80611BB4(var_f20, var_f22);
    if (gCurrentActorPointer->y_acceleration != -20.0f && gCurrentActorPointer->y_acceleration != -360.0f) {
        gCurrentActorPointer->unkB8 = D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 * 10.0;
    } else {
        gCurrentActorPointer->unkB8 = sp44;
    }
    gCurrentActorPointer->unkEE = (temp_f0_2 * 4096.0) / 6.28318548202514648;
    if (gCurrentActorPointer->unk6A & 1) {
        gCurrentActorPointer->unkB8 -= (f32)((gCurrentActorPointer->unkB8 * gCurrentActorPointer->unkB8) / 15000.0);
        if (gCurrentActorPointer->unkB8 < 0.0f) {
            gCurrentActorPointer->unkB8 = 0.0f;
        }
    }
}
*/

int func_race_80024634(RaceStruct8 *arg0, RaceStruct9 *arg1) {
    return arg0->unk36 && 
           !isFlagSet(arg1->unk1A, FLAG_TYPE_PERMANENT) &&
           arg1->unk1C <= D_global_asm_80750AC4;
}

// Jumptable, doable, close, regalloc v0 v1
// https://decomp.me/scratch/1joCC
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_0/func_race_80024690.s")

s32 func_race_8002E8EC(void *, s32, s32);
extern u16 D_global_asm_80750AC8;
extern u8 D_global_asm_807FBD70;
extern s32 D_race_8002FB94[];

typedef struct {
    u8 unk0[0x1C - 0x0]; // Unused
    u16 unk1C;
} AAD_80024690;

typedef struct {
    u8 unk0[0x30 - 0]; // Unused
    Actor *unk30;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37[0xD0 - 0x37]; // Unused
    s16 unkD0;
} A178_80024690;

typedef struct {
    s32 unk0; // Unused
    s32 unk4;
    u8 unk8[0x18 - 0x8]; // Unused
    s32 unk18;
    s32 unk1C;
} A17C_80024690;

/*
void func_race_80024690(void) {
    f32 sp6C;
    f32 sp68;
    s16 sp66;
    s32 flagIndex;
    f32 var_f2;
    u8 sp5B;
    A178_80024690 *a178; // 54
    A17C_80024690 *a17C; // 50
    Actor *sp4C; // 4c
    AAD_80024690 *aaD; // 48
    Struct8002FB10_race_8002FB70 *sp44; // 44
    s32 cutsceneIndex;
    s16 temp;
    f32 d;
    Struct807FDCA0_unk14 *pt;

    a178 = gCurrentActorPointer->unk178;
    a17C = gCurrentActorPointer->unk17C;
    aaD = NULL;
    sp4C = a178->unk30;
    if (current_map == MAP_CAVES_BEETLE_RACE) {
        sp44 = D_race_8002FB10;
    } else {
        sp44 = D_race_8002FB70;
    }
    if (sp4C != NULL) {
        aaD = sp4C->additional_actor_data;
    }
    initializeCharacterSpawnerActor();
    if (!(gCurrentActorPointer->object_properties_bitfield & 0x10)) {
        gCurrentActorPointer->noclip_byte = 0x1C;
        gCurrentActorPointer->object_properties_bitfield |= 0x10400;
        gCurrentActorPointer->object_properties_bitfield &= 0xFFFDFFFF;
        gCurrentActorPointer->control_state = 0;
        gCurrentActorPointer->control_state_progress = 0;
        gCurrentActorPointer->unkB8 = 0.0f;
        gCurrentActorPointer->y_acceleration = -20.0f;
        gCurrentActorPointer->terminal_velocity = -900.0f;
        gCurrentActorPointer->draw_distance = 0x7D0;
        D_global_asm_807FDC90->unk35 = 0;
        D_global_asm_807FDC90->unk2C = 0x64;
        D_global_asm_807FDC90->unk2C = 0;
        D_global_asm_807FDC90->unk24 = 0;
        gCurrentActorPointer->unk68 &= 0xFFBF;
        if (current_map == MAP_CAVES_BEETLE_RACE) {
            D_global_asm_80750AC8 = 0x32;
            a17C->unk1C = D_global_asm_80750AC8;
            a17C->unk18 = 0x103;
            flagIndex = TEMPFLAG_CAVES_BEETLE_INTRO;
        } else {
            D_global_asm_80750AC8 = 0x32;
            a17C->unk1C = D_global_asm_80750AC8;
            a17C->unk18 = 0x4B;
            flagIndex = TEMPFLAG_AZTEC_BEETLE_INTRO;
        }
        if (!isFlagSet(flagIndex, FLAG_TYPE_TEMPORARY) && !isFlagSet(a17C->unk18, FLAG_TYPE_PERMANENT)) {
            playCutscene(gCurrentActorPointer, 0, 1);
            func_global_asm_80629174();
            setFlag(flagIndex, TRUE, FLAG_TYPE_TEMPORARY);
        } else {
            a178->unk35 = 3;
        }
    }
    sp5B = D_global_asm_807FDC90->unk24;
    if (aaD && (a178->unk34 < 3) && (D_global_asm_807FBD70 == 4)) {
        setAction(0x33, gCurrentActorPointer, 0);
    }
    if ((a178->unk34 < 3) && (gCurrentActorPointer->control_state == 2) && (D_global_asm_807FBD70 == 5)) {
        playSoundAtActorPosition(gCurrentActorPointer, 0x1CA, 0xFF, 0x7F, 0xA);
        playSoundAtActorPosition(gCurrentActorPointer, 0x209, 0xFF, 0x7F, 0xA);
        gCurrentActorPointer->unkB8 = 0.0f;
        gCurrentActorPointer->control_state = 0x14;
        gCurrentActorPointer->y_acceleration = -40.0f;
        gCurrentActorPointer->y_velocity = 400.0f;
    }
    if (func_global_asm_806CCC10()) {
        gCurrentActorPointer->unk132 = 1;
    } else {
        gCurrentActorPointer->unk132 = 2;
    }
    switch (gCurrentActorPointer->control_state) { // switch 1
        case 20: // switch 1
            gCurrentActorPointer->z_rotation = (gCurrentActorPointer->z_rotation - 0xC8) & 0xFFF;
            if ((gCurrentActorPointer->unk6A & 1) && (gCurrentActorPointer->y_velocity <= 0)) {
                gCurrentActorPointer->control_state = 2;
                gCurrentActorPointer->z_rotation = 0;
            }
            break;
        case 0: // switch 1
            if (aaD && (!aaD->unk1C)) {
                gCurrentActorPointer->control_state++;
                gCurrentActorPointer->control_state_progress = 0;
                gCurrentActorPointer->unk6A |= 0x200;
            }
            break;
        case 1: // switch 1
            if (a178->unk34 == 2) {
                if (current_map == MAP_CAVES_BEETLE_RACE) {
                    func_global_asm_8072B324(gCurrentActorPointer, 0x10E);
                } else {
                    func_global_asm_8072B324(gCurrentActorPointer, 0xAA);
                }
                D_global_asm_807FDC90->unk35 = 0xA;
                playActorAnimation(gCurrentActorPointer, 0x282);
                gCurrentActorPointer->control_state++;
                break;
            }
        case 2: // switch 1
            func_global_asm_8072B438(0);
            sp6C = gCurrentActorPointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0;
            sp68 = gCurrentActorPointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4;
            if (sqrtf(SQ(sp68) + SQ(sp6C)) < D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk7) {
                if (ABS(gCurrentActorPointer->y_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk2) < 80.0f) {
                    if (D_global_asm_807FDC90->unk25 < (D_global_asm_807FDCA0->unk10 - 1)) {
                        if (!D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8) {
                            playActorAnimation(gCurrentActorPointer, 0x283);
                            gCurrentActorPointer->control_state++;
                        }
                        if (D_global_asm_807FDC90->unk25 == sp44[sp5B].unk0) {
                            gCurrentActorPointer->y_acceleration = sp44[sp5B].unk4;
                            D_global_asm_807FDC90->unk24++;
                        }
                        D_global_asm_807FDC90->unk25++;
                    }
                }
            }
            sp66 = (func_global_asm_80611BB4(-sp6C, -sp68) * 4096.0) / (2.0 * M_PI);
            temp = (sp66 + sp66 - gCurrentActorPointer->unkEE) & 0xFFF;
            func_global_asm_806DF494(&gCurrentActorPointer->y_rotation, temp, 0x32);
            func_global_asm_806DF494(&gCurrentActorPointer->unkEE, sp66, 0xF);
            if ((sp44[D_global_asm_807FDC90->unk24].unk0 == D_global_asm_807FDC90->unk25) && (sp44[D_global_asm_807FDC90->unk24].unk8 == 2) && (a178->unk34 == 3)) {
                if (a178->unk36 == 1) {
                    gCurrentActorPointer->control_state = 0xA;
                } else {
                    gCurrentActorPointer->control_state = 9;
                }
                playActorAnimation(gCurrentActorPointer, 0);
                gCurrentActorPointer->control_state_progress = 0;
            }
            break;
        case 3: // switch 1
            func_global_asm_8072B438(0x200);
            break;
        case 4: // switch 1
            func_global_asm_8072B438(0x200);
            gCurrentActorPointer->y_velocity = 200.0f;
            gCurrentActorPointer->control_state++;
            break;
        case 5: // switch 1
            func_global_asm_8072B438(0x200);
            break;
        case 6: // switch 1
            if (D_global_asm_807FDC90->unk2E) {
                D_global_asm_807FDC90->unk2E--;
            } else if (gCurrentActorPointer->unkFC) {
                playSoundAtActorPosition(gCurrentActorPointer, 0xFF, 0x46, 0x7F, 2);
                D_global_asm_807FDC90->unk2E = 0x14;
            }
            if ((D_global_asm_807FDC90->unk25 == sp44[D_global_asm_807FDC90->unk24].unk0) && (sp44[D_global_asm_807FDC90->unk24].unk8 == 1)) {
                var_f2 = gCurrentActorPointer->unkEE - gCurrentActorPointer->y_rotation;
                if (var_f2 > 2048.0f) {
                    var_f2 -= 4096.0f;
                }
                if (var_f2 < -2048.0f) {
                    var_f2 += 4096.0f;
                }
                if (var_f2 > 50.0f) {
                    var_f2 = 50.0f;
                }
                if (var_f2 < -50.0f) {
                    var_f2 = -50.0f;
                }
                D_global_asm_807FDC90->unk2C += var_f2;
                D_global_asm_807FDC90->unk2C -= (D_global_asm_807FDC90->unk2C * 0.3);
            } else {
                if ((gCurrentActorPointer->unk6A & 1) && !(gCurrentActorPointer->unk6C & 1)) {
                    playActorAnimation(gCurrentActorPointer, 0x285);
                    gCurrentActorPointer->y_acceleration = -20.0f;
                }
                var_f2 = gCurrentActorPointer->unkEE - gCurrentActorPointer->unkDC;
                if (var_f2 > 2048.0f) {
                    var_f2 -= 4096.0f;
                }
                if (var_f2 < -2048.0f) {
                    var_f2 += 4096.0f;
                }
                D_global_asm_807FDC90->unk2C += ((var_f2 * gCurrentActorPointer->unkB8) / 8000.0);
                if (D_global_asm_807FDC90->unk2C > 0x1F4) {
                    D_global_asm_807FDC90->unk2C = 0x1F4;
                }
                if (D_global_asm_807FDC90->unk2C < -0x1F4) {
                    D_global_asm_807FDC90->unk2C = -0x1F4;
                }
            }
            gCurrentActorPointer->y_rotation = (gCurrentActorPointer->y_rotation + D_global_asm_807FDC90->unk2C) & 0xFFF;
            func_race_80024000();
            break;
        case 7: // switch 1
            if (current_map == MAP_AZTEC_BEETLE_RACE) {
                func_global_asm_8072B324(gCurrentActorPointer, 0xB4);
            }
            func_race_80024000();
            break;
        case 8: // switch 1
            gCurrentActorPointer->control_state = 2;
            gCurrentActorPointer->y_rotation = gCurrentActorPointer->unkEE;
            break;
        case 9: // switch 1
            D_global_asm_807FDC90->unk35 = 8;
            func_global_asm_8072B324(gCurrentActorPointer, 0);
            func_global_asm_8072B438(0x200);
            if (gCurrentActorPointer->control_state_progress == 0) {
                playActorAnimation(gCurrentActorPointer, 0x287);
                gCurrentActorPointer->control_state_progress += 1;
            }
            break;
        case 10: // switch 1
            switch (gCurrentActorPointer->control_state_progress) { // switch 4; irregular
                case 0: // switch 4
                    func_global_asm_8072B324(gCurrentActorPointer, 0);
                    D_global_asm_807FDC90->unk35 = 8;
                    gCurrentActorPointer->control_state_progress = 1;
                    break;
                case 1: // switch 4
                    if (gCurrentActorPointer->unkB8 == 0.0f) {
                        gCurrentActorPointer->control_state_progress++;
                    }
                    break;
                case 2: // switch 4
                    D_global_asm_807FDC90->unk35 = 0;
                    playActorAnimation(gCurrentActorPointer, 0x288);
                    gCurrentActorPointer->control_state_progress++;
                    break;
            }
            func_global_asm_8072B438(0x200);
            break;
    }
    switch (a178->unk34) { // switch 2
        case 0: // switch 2
            switch (a178->unk35) { // switch 5; irregular
                case 0: // switch 5
                    if (gCurrentActorPointer->object_properties_bitfield & 0x02000000) {
                        a178->unk35++;
                    }
                    break;
                case 1: // switch 5
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        a178->unk35++;
                    }
                    break;
                case 2: // switch 5
                    if (func_global_asm_80629148() != 0) {
                        func_global_asm_80629174();
                        a178->unk35++;
                    }
                    break;
            }
            if (a178->unk35 < 3) {
                func_race_8002D72C(sp4C);
            }
            break;
        case 1: // switch 2
            if (a178->unk35 == 0) {
                func_global_asm_806F8BC4(0xB, 1, 0);
                a178->unk35++;
            }
            break;
        case 3: // switch 2
            if (a178->unk35 == 0) {
                s32 var_v0_3 = 0x55;
                if (gPlayerPointer->unk6A & 0x200) {
                    var_v0_3 = 0x56;
                }
                setAction(var_v0_3, NULL, 0);
                a178->unk35++;
            }
            break;
        case 4: // switch 2
            if (a178->unk35 == 0) {
                func_global_asm_806F8D58(0xB, 0);
                a178->unkD0 = 0;
                if (!isFlagSet(a17C->unk18, FLAG_TYPE_PERMANENT)) {
                    cutsceneIndex = D_race_8002FB94[func_race_8002E8EC(a178, a17C->unk4, a17C->unk1C)];
                    playCutscene(gCurrentActorPointer, cutsceneIndex, 1);
                    func_global_asm_80629174();
                } else {
                    func_global_asm_805FF544();
                }
                a178->unk35++;
            }
            break;
        case 5: // switch 2
            switch (a178->unk35) { // switch 3
                case 0: // switch 3
                    if (!isFlagSet(a17C->unk18, FLAG_TYPE_PERMANENT)) {
                        func_global_asm_80605314(gCurrentPlayer, 0);
                        setAction(0x55, NULL, 0);
                        gCurrentActorPointer->unkB8 = 0.0f;
                        if (func_race_80024634(a178, a17C)) {
                            gCurrentActorPointer->control_state = 0xA;
                            gCurrentActorPointer->control_state_progress = 0;
                        } else {
                            gCurrentActorPointer->control_state = 9;
                            gCurrentActorPointer->control_state_progress = 0;
                        }
                    }
                    a178->unk35++;
                    break;
                case 1: // switch 3
                    if (gCurrentActorPointer->object_properties_bitfield & 0x02000000) {
                        a178->unk35++;
                    }
                    break;
                case 2: // switch 3
                    if (!(gCurrentActorPointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        if (!func_race_80024634(a178, a17C)) {
                            a178->unk35 = 4;
                        }
                        a178->unk35++;
                        gCurrentActorPointer->unk15F = 0;
                    }
                    break;
                case 3: // switch 3
                    if (func_global_asm_80629148()) {
                        func_global_asm_80629174();
                        if (current_map == MAP_AZTEC_BEETLE_RACE) {
                            func_global_asm_8063DA40(0x48, 0xA);
                        } else {
                            func_global_asm_8063DA40(1, 0xA);
                        }
                        a178->unk35++;
                    }
                    break;
                case 4: // switch 3
                    if (isFlagSet(a17C->unk18, FLAG_TYPE_PERMANENT)) {
                        a178->unk35++;
                    }
                    break;
                case 5: // switch 3
                    if (func_global_asm_80629148()) {
                        func_global_asm_80629174();
                        if (isFlagSet(a17C->unk18, FLAG_TYPE_PERMANENT)) {
                            func_global_asm_805FF544();
                        } else {
                            func_global_asm_806ACC00(1);
                        }
                        a178->unk35++;
                    }
                    break;
            }
            break;
    }
    func_global_asm_80729E6C();
    func_global_asm_80665160(gCurrentActorPointer, gCurrentActorPointer->unkEE, gCurrentActorPointer->unkEE);
    func_global_asm_806651FC(gCurrentActorPointer);
    func_global_asm_80665564(gCurrentActorPointer, 0.0f);
    func_global_asm_8065D254(gCurrentActorPointer, 0x3C8, 0x40, 0x40, 0xE, 0xE, 1, 0x96, 0x78, 0, 1.0f);
    if (a178->unk34 == 2) {
        func_race_8002F490(a178);
    }
    renderActor(gCurrentActorPointer, 0);
}
*/
