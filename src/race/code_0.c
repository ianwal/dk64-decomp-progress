#include <ultra64.h>
#include "functions.h"

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

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Struct8002FB10_race_8002FB70;

extern Struct8002FB10_race_8002FB70 D_race_8002FB10[];
extern Struct8002FB10_race_8002FB70 D_race_8002FB70[];

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
    sp44 = current_actor_pointer->unkB8;
    sp40 = func_global_asm_80612794(current_actor_pointer->unkE0 * 11.4) * 20.0f;
    if (sqrtf(((current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0) * (current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0)) + ((current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4) * (current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4))) < D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk7) {
        var_f12 = ABS(current_actor_pointer->y_position - (f32)D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk2);
        if (var_f12 < 80.0f) {
            if (D_global_asm_807FDC90->unk25 < (D_global_asm_807FDCA0->unk10 - 1)) {
                if (D_global_asm_807FDC90->unk25 == var_t0[sp37].unk0) {
                    current_actor_pointer->y_acceleration = var_t0[sp37].unk4;
                    if (var_t0[sp37].unk8 == 1) {
                        playActorAnimation(current_actor_pointer, 0x286);
                        current_actor_pointer->y_velocity = 200.0f;
                        current_actor_pointer->control_state++;
                    }
                    D_global_asm_807FDC90->unk24++;
                }
                D_global_asm_807FDC90->unk25++;
            }
        }
    }
    var_f0 = (current_actor_pointer->y_position - current_player->y_position);
    var_f0 *= 0.25f;
    var_f0 = MIN(6.0f, var_f0);
    var_f0 = MAX(-6.0f, var_f0);
    var_f0 += ((D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 - (current_actor_pointer->unkB8 / 10.0f)) * 0.8);
    var_v1 = (s16)((func_global_asm_80611BB4(-(current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0), -(current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4)) * 4096.0) / 6.28318548202514648) - current_actor_pointer->unkEE;
    if (var_v1 >= 0x800) {
        var_v1 -= 4096.0;
    }
    if (var_v1 < -0x800) {
        var_v1 += 4096.0;
    }
    sp50 = (current_actor_pointer->unkB8 * var_v1) / 10000.0;
    var_f20 = func_global_asm_80612794(current_actor_pointer->unkEE) * sp44;
    var_f22 = func_global_asm_80612790(current_actor_pointer->unkEE) * sp44;
    if (current_actor_pointer->unk6A & 1) {
        var_f20 += func_global_asm_80612794(current_actor_pointer->unkDC) * sp40;
        var_f22 += func_global_asm_80612790(current_actor_pointer->unkDC) * sp40;
    }
    var_f20 += (func_global_asm_80612794(current_actor_pointer->unkEE) * var_f0) + (func_global_asm_80612790(current_actor_pointer->unkEE) * sp50);
    var_f22 += (func_global_asm_80612790(current_actor_pointer->unkEE) * var_f0) - (func_global_asm_80612794(current_actor_pointer->unkEE) * sp50);
    sp44 = sqrtf((var_f20 * var_f20) + (var_f22 * var_f22));
    temp_f0_2 = func_global_asm_80611BB4(var_f20, var_f22);
    if (current_actor_pointer->y_acceleration != -20.0f && current_actor_pointer->y_acceleration != -360.0f) {
        current_actor_pointer->unkB8 = D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8 * 10.0;
    } else {
        current_actor_pointer->unkB8 = sp44;
    }
    current_actor_pointer->unkEE = (temp_f0_2 * 4096.0) / 6.28318548202514648;
    if (current_actor_pointer->unk6A & 1) {
        current_actor_pointer->unkB8 -= (f32)((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / 15000.0);
        if (current_actor_pointer->unkB8 < 0.0f) {
            current_actor_pointer->unkB8 = 0.0f;
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

    a178 = current_actor_pointer->unk178;
    a17C = current_actor_pointer->unk17C;
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
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x1C;
        current_actor_pointer->object_properties_bitfield |= 0x10400;
        current_actor_pointer->object_properties_bitfield &= 0xFFFDFFFF;
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->unkB8 = 0.0f;
        current_actor_pointer->y_acceleration = -20.0f;
        current_actor_pointer->terminal_velocity = -900.0f;
        current_actor_pointer->draw_distance = 0x7D0;
        D_global_asm_807FDC90->unk35 = 0;
        D_global_asm_807FDC90->unk2C = 0x64;
        D_global_asm_807FDC90->unk2C = 0;
        D_global_asm_807FDC90->unk24 = 0;
        current_actor_pointer->unk68 &= 0xFFBF;
        if (current_map == MAP_CAVES_BEETLE_RACE) {
            D_global_asm_80750AC8 = 0x32;
            a17C->unk1C = D_global_asm_80750AC8;
            a17C->unk18 = 0x103;
            flagIndex = 0x65;
        } else {
            D_global_asm_80750AC8 = 0x32;
            a17C->unk1C = D_global_asm_80750AC8;
            a17C->unk18 = 0x4B;
            flagIndex = 0x66;
        }
        if (!isFlagSet(flagIndex, FLAG_TYPE_TEMPORARY) && !isFlagSet(a17C->unk18, FLAG_TYPE_PERMANENT)) {
            playCutscene(current_actor_pointer, 0, 1);
            func_global_asm_80629174();
            setFlag(flagIndex, TRUE, FLAG_TYPE_TEMPORARY);
        } else {
            a178->unk35 = 3;
        }
    }
    sp5B = D_global_asm_807FDC90->unk24;
    if ((aaD != NULL) && (a178->unk34 < 3) && (D_global_asm_807FBD70 == 4)) {
        setAction(0x33, current_actor_pointer, 0);
    }
    if ((a178->unk34 < 3) && (current_actor_pointer->control_state == 2) && (D_global_asm_807FBD70 == 5)) {
        playSoundAtActorPosition(current_actor_pointer, 0x1CA, 0xFF, 0x7F, 0xA);
        playSoundAtActorPosition(current_actor_pointer, 0x209, 0xFF, 0x7F, 0xA);
        current_actor_pointer->unkB8 = 0.0f;
        current_actor_pointer->control_state = 0x14;
        current_actor_pointer->y_acceleration = -40.0f;
        current_actor_pointer->y_velocity = 400.0f;
    }
    if (func_global_asm_806CCC10() != 0) {
        current_actor_pointer->unk132 = 1;
    } else {
        current_actor_pointer->unk132 = 2;
    }
    switch (current_actor_pointer->control_state) { // switch 1
        case 20: // switch 1
            current_actor_pointer->z_rotation = (current_actor_pointer->z_rotation - 0xC8) & 0xFFF;
            if ((current_actor_pointer->unk6A & 1) && (current_actor_pointer->y_velocity <= 0)) {
                current_actor_pointer->control_state = 2;
                current_actor_pointer->z_rotation = 0;
            }
            break;
        case 0: // switch 1
            if (aaD && (aaD->unk1C == 0)) {
                current_actor_pointer->control_state++;
                current_actor_pointer->control_state_progress = 0;
                current_actor_pointer->unk6A |= 0x200;
            }
            break;
        case 1: // switch 1
            if (a178->unk34 == 2) {
                if (current_map == MAP_CAVES_BEETLE_RACE) {
                    func_global_asm_8072B324(current_actor_pointer, 0x10E);
                } else {
                    func_global_asm_8072B324(current_actor_pointer, 0xAA);
                }
                D_global_asm_807FDC90->unk35 = 0xA;
                playActorAnimation(current_actor_pointer, 0x282);
                current_actor_pointer->control_state++;
                break;
            }
        case 2: // switch 1
            func_global_asm_8072B438(0);
            sp6C = current_actor_pointer->x_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk0;
            sp68 = current_actor_pointer->z_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk4;
            if (sqrtf(SQ(sp68) + SQ(sp6C)) < D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk7) {
                if (ABS(current_actor_pointer->y_position - D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk2) < 80.0f) {
                    if (D_global_asm_807FDC90->unk25 < (D_global_asm_807FDCA0->unk10 - 1)) {
                        if (!D_global_asm_807FDCA0->unk14[D_global_asm_807FDC90->unk25].unk8) {
                            playActorAnimation(current_actor_pointer, 0x283);
                            current_actor_pointer->control_state++;
                        }
                        if (D_global_asm_807FDC90->unk25 == sp44[sp5B].unk0) {
                            current_actor_pointer->y_acceleration = sp44[sp5B].unk4;
                            D_global_asm_807FDC90->unk24++;
                        }
                        D_global_asm_807FDC90->unk25++;
                    }
                }
            }
            sp66 = (func_global_asm_80611BB4(-sp6C, -sp68) * 4096.0) / (2.0 * M_PI);
            temp = (sp66 + sp66 - current_actor_pointer->unkEE) & 0xFFF;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, temp, 0x32);
            func_global_asm_806DF494(&current_actor_pointer->unkEE, sp66, 0xF);
            if ((sp44[D_global_asm_807FDC90->unk24].unk0 == D_global_asm_807FDC90->unk25) && (sp44[D_global_asm_807FDC90->unk24].unk8 == 2) && (a178->unk34 == 3)) {
                if (a178->unk36 == 1) {
                    current_actor_pointer->control_state = 0xA;
                } else {
                    current_actor_pointer->control_state = 9;
                }
                playActorAnimation(current_actor_pointer, 0);
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 3: // switch 1
            func_global_asm_8072B438(0x200);
            break;
        case 4: // switch 1
            func_global_asm_8072B438(0x200);
            current_actor_pointer->y_velocity = 200.0f;
            current_actor_pointer->control_state++;
            break;
        case 5: // switch 1
            func_global_asm_8072B438(0x200);
            break;
        case 6: // switch 1
            if (D_global_asm_807FDC90->unk2E != 0) {
                D_global_asm_807FDC90->unk2E--;
            } else if (current_actor_pointer->unkFC != 0) {
                playSoundAtActorPosition(current_actor_pointer, 0xFF, 0x46, 0x7F, 2);
                D_global_asm_807FDC90->unk2E = 0x14;
            }
            if ((D_global_asm_807FDC90->unk25 == sp44[D_global_asm_807FDC90->unk24].unk0) && (sp44[D_global_asm_807FDC90->unk24].unk8 == 1)) {
                var_f2 = current_actor_pointer->unkEE - current_actor_pointer->y_rotation;
                if (var_f2 > 2048.0f) {
                    var_f2 -= 4096.0f;
                }
                if (var_f2 < -2048.0f) {
                    var_f2 += 4096.0f;
                }
                var_f2 = MIN(50.0f, var_f2);
                var_f2 = MAX(-50.0f, var_f2);
                D_global_asm_807FDC90->unk2C += var_f2;
                D_global_asm_807FDC90->unk2C = D_global_asm_807FDC90->unk2C - (D_global_asm_807FDC90->unk2C * 0.3);
            } else {
                if ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1)) {
                    playActorAnimation(current_actor_pointer, 0x285);
                    current_actor_pointer->y_acceleration = -20.0f;
                }
                var_f2 = current_actor_pointer->unkEE - current_actor_pointer->unkDC;
                if (var_f2 > 2048.0f) {
                    var_f2 -= 4096.0f;
                }
                if (var_f2 < -2048.0f) {
                    var_f2 += 4096.0f;
                }
                D_global_asm_807FDC90->unk2C = D_global_asm_807FDC90->unk2C + ((var_f2 * current_actor_pointer->unkB8) / 8000.0);
                if (D_global_asm_807FDC90->unk2C > 0x1F4) {
                    D_global_asm_807FDC90->unk2C = 0x1F4;
                }
                if (D_global_asm_807FDC90->unk2C < -0x1F4) {
                    D_global_asm_807FDC90->unk2C = -0x1F4;
                }
            }
            current_actor_pointer->y_rotation = (current_actor_pointer->y_rotation + D_global_asm_807FDC90->unk2C) & 0xFFF;
            func_race_80024000();
            break;
        case 7: // switch 1
            if (current_map == MAP_AZTEC_BEETLE_RACE) {
                func_global_asm_8072B324(current_actor_pointer, 0xB4);
            }
            func_race_80024000();
            break;
        case 8: // switch 1
            current_actor_pointer->control_state = 2;
            current_actor_pointer->y_rotation = current_actor_pointer->unkEE;
            break;
        case 9: // switch 1
            D_global_asm_807FDC90->unk35 = 8;
            func_global_asm_8072B324(current_actor_pointer, 0);
            func_global_asm_8072B438(0x200);
            if (current_actor_pointer->control_state_progress == 0) {
                playActorAnimation(current_actor_pointer, 0x287);
                current_actor_pointer->control_state_progress += 1;
            }
            break;
        case 10: // switch 1
            switch (current_actor_pointer->control_state_progress) { // switch 4; irregular
                case 0: // switch 4
                    func_global_asm_8072B324(current_actor_pointer, 0);
                    D_global_asm_807FDC90->unk35 = 8;
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 1: // switch 4
                    if (current_actor_pointer->unkB8 == 0.0f) {
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 2: // switch 4
                    D_global_asm_807FDC90->unk35 = 0;
                    playActorAnimation(current_actor_pointer, 0x288);
                    current_actor_pointer->control_state_progress++;
                    break;
            }
            func_global_asm_8072B438(0x200);
            break;
    }
    switch (a178->unk34) { // switch 2
        case 0: // switch 2
            switch (a178->unk35) { // switch 5; irregular
                case 0: // switch 5
                    if (current_actor_pointer->object_properties_bitfield & 0x02000000) {
                        a178->unk35++;
                    }
                    break;
                case 1: // switch 5
                    if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
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
                if (player_pointer->unk6A & 0x200) {
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
                    playCutscene(current_actor_pointer, cutsceneIndex, 1);
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
                        func_global_asm_80605314(current_player, 0);
                        setAction(0x55, NULL, 0);
                        current_actor_pointer->unkB8 = 0.0f;
                        if (func_race_80024634(a178, a17C)) {
                            current_actor_pointer->control_state = 0xA;
                            current_actor_pointer->control_state_progress = 0;
                        } else {
                            current_actor_pointer->control_state = 9;
                            current_actor_pointer->control_state_progress = 0;
                        }
                    }
                    a178->unk35++;
                    break;
                case 1: // switch 3
                    if (current_actor_pointer->object_properties_bitfield & 0x02000000) {
                        a178->unk35++;
                    }
                    break;
                case 2: // switch 3
                    if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8061CB08();
                        if (!func_race_80024634(a178, a17C)) {
                            a178->unk35 = 4;
                        }
                        a178->unk35++;
                        current_actor_pointer->unk15F = 0;
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
    func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->unkEE);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xE, 0xE, 1, 0x96, 0x78, 0, 1.0f);
    if (a178->unk34 == 2) {
        func_race_8002F490(a178);
    }
    renderActor(current_actor_pointer, 0);
}
*/
