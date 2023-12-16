#include <ultra64.h>
#include "functions.h"

/*
rodata
D_race_800300C0 = "%d"
D_race_800300C4 = "%s %d %s %d"
D_race_800300F0 .float 0.6f
D_race_80030108 .float 0.3f
D_race_80030110 .double 0.15
*/

void func_race_8002E2C8(Actor *arg0);
void func_race_80025E9C(Actor *);

void func_race_8002BBD0(Actor *arg0, s32 arg1) {
    RaceAdditionalActorData *sp1C;
    RaaD_unk20 *temp_v0;

    sp1C = arg0->RaaD;
    temp_v0 = malloc(arg1 * sizeof(RaaD_unk20));
    sp1C->unk20 = temp_v0;
    func_global_asm_80611690(temp_v0);
    sp1C->unk1E = arg1;
    sp1C->unk1C = -1;
    arg0->control_state = 0;
}

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
    s8 unk24;
    s8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    s32 unk2C;
    s32 unk30;
    u8 unk34;
    s8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
    s16 unk3A;
    u16 unk3C;
    s8 unk3E[0x45 - 0x3E];
    u8 unk45;
    s8 unk46;
    u8 unk47;
    u32 unk48;
} Struct8002D148_unk4;

typedef struct {
    s32 unk0;
    Struct8002D148_unk4 *unk4;
} Struct8002D148;

u16 *func_race_8002E960(u8);

void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, Struct8002D148_unk4 *arg3) {
    u16 *temp_v0_2;
    RaceAdditionalActorData *RaaD;
    RaaD_unk20 *temp_v0;

    RaaD = arg0->RaaD;
    temp_v0 = RaaD->unk20;
    temp_v0[arg1].unk0 = arg2;
    temp_v0[arg1].unk4 = arg3;
    arg3->unk45 = 0;
    arg3->unk3A = 0;
    arg3->unk37 = 1;
    if (arg3->unk27 == 0) {
        temp_v0_2 = func_race_8002E960(RaaD->unk26);
        if (temp_v0_2 != NULL) {
            arg3->unk3C = *temp_v0_2 - 1;
            func_race_8002F36C(arg3, temp_v0_2);
        }
        arg3->unk48 = func_global_asm_806C7C94(arg3->unk28);
    }
}

void func_race_8002BCB0(Actor *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    RaceAdditionalActorData *aaD;
    RaaD_unk20 *temp_t0;

    aaD = arg0->RaaD;
    temp_t0 = aaD->unk20;
    *arg2 = temp_t0[arg1].unk0;
    *arg3 = temp_t0[arg1].unk4;
}

// rodata, close
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002BCD4.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} AAD_race_8002BCD4;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80027880;

/*
void func_race_8002BCD4(Actor *arg0) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f14;
    f32 var_f2;
    Struct80027880 *temp_a2;
    Struct80027880 *var_v1;
    AAD_race_8002BCD4 *aaD;

    var_f0 = 9999.0f;
    var_f2 = 9999.0f;
    var_f12 = -1.0f;
    var_f14 = -1.0f; 
    aaD = arg0->additional_actor_data;
    var_v1 = &D_global_asm_807F5FD4[0].unk0;
    temp_a2 = &D_global_asm_807F5FD4[1].unk0;
    while (var_v1 < temp_a2) {
        if (var_v1->unk0 < var_f0) {
            var_f0 = var_v1->unk0;
        }
        if (var_v1->unk8 < var_f2) {
            var_f2 = var_v1->unk8;
        }
        if (var_f12 < var_v1->unk0) {
            var_f12 = var_v1->unk0;
        }
        if (var_f14 < var_v1->unk8) {
            var_f14 = var_v1->unk8;
        }
        var_v1++;
    }
    aaD->unkC = (((var_f12 - var_f0) * 0.5f) + var_f0) - 10.0f;
    aaD->unk10 = (((var_f14 - var_f2) * 0.5f) + var_f2) - 20.0f;
    aaD->unk4 = 116.4800034f / (var_f12 - var_f0);
    aaD->unk8 = 121.5999985f / (var_f14 - var_f2);
}
*/

// Displaylist stuff, close
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002BDDC.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} AAD_race_8002BDDC;

/*
void func_race_8002BDDC(Gfx *dl, Actor *arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, u8 arg6) {
    f32 temp_f12;
    f32 temp_f14;
    AAD_race_8002BDDC *aaD;

    aaD = arg1->additional_actor_data;
    temp_f12 = aaD->unkC - arg2;
    temp_f14 = aaD->unk10 - arg3;
    temp_f12 *= aaD->unk4;
    temp_f14 *= aaD->unk8;
    temp_f12 *= 0.5f;
    temp_f14 *= 0.5f;
    gDPSetPrimColor(dl++, 0, 0, arg4, arg5, arg6, 0xC8);
    func_global_asm_8068C5A8(dl, 0x4A, 3, 1, 0x10, 0x10, ((temp_f12) + 50.0f) * 4.0f, ((temp_f14) + 60.0f) * 4.0f, 1.0f, 1.0f, 0, 0.0f);
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002BEE8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002C14C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002C2E8.s")

typedef struct {
    u8 unk0[0x50 - 0x0];
    f32 unk50[1][4][4];
} Struct8002C63C_arg1;

Gfx *func_race_8002C63C(Gfx *dl, Struct8002C63C_arg1 *arg1) {
    gDPPipeSync(dl++);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCycleType(dl++, G_CYC_1CYCLE);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    dl = func_global_asm_805FD030(dl);

    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    guScale(arg1->unk50[D_global_asm_807444FC], 0.5f, 0.5f, 1.0f);
    gSPMatrix(dl++, arg1->unk50[D_global_asm_807444FC], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002C76C.s")

s32 func_race_8002C14C(s32, void *);
s32 func_race_8002C2E8(s32, void *);
s32 func_race_8002C76C(s32, void *);

Gfx *func_race_8002CAC8(Gfx *dl, Actor *arg1, RaceAdditionalActorData *arg2) {
    RaceAdditionalActorData2 *sp24;
    PlayerAdditionalActorData *PaaD;

    sp24 = arg2->unk30->RaaD2;    
    if (arg2 == NULL || gameIsInDKTVMode()) {
        return dl;
    }
    if (character_change_array[arg2->unk28].player_pointer == NULL) {
        return dl;
    }
    PaaD = character_change_array[arg2->unk28].player_pointer->PaaD;
    if (arg1 != PaaD->vehicle_actor_pointer) {
        return dl;
    }

    dl = func_race_8002C63C(dl, arg2);
    if (sp24->unk0 & 8) {
        dl = func_race_8002C2E8(dl, arg2);
    } else if (sp24->unk0 & 0x10) {
        dl = func_race_8002C14C(dl, arg2);
    }
    if (sp24->unk0 & 6) {
        dl = func_race_8002C76C(dl, arg2);
    }

    return dl;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002CBEC.s")

void func_race_8002CFF0(void) {
    TempAAD *temp_v0;
    Actor *temp_a0;

    func_global_asm_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    temp_a0 = D_global_asm_807FBB44;
    func_race_80025E9C(temp_a0);
    func_race_8002BCD4(temp_a0);
    temp_v0 = temp_a0->TaaD;
    temp_v0->unk0 = 0x17;
    temp_v0->unk14 = 0x46;
    temp_v0->unk16 = 0x47;
    temp_v0->unk18 = 0x48;
    temp_v0->unk1A = 0x49;
    temp_v0->unk24 = 2;
}

void castleCarRaceSetup(void) {
    RaceAdditionalActorData2 *RaaD;

    func_global_asm_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_global_asm_807FBB44->RaaD2;
    initializeCastleCarRace(D_global_asm_807FBB44);
    RaaD->unk0 = 0xE;
    RaaD->unk24 = 2;
}

void initializeSealRace(void) {
    RaceAdditionalActorData2 *RaaD;

    func_global_asm_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_global_asm_807FBB44->RaaD2;
    func_race_800292D0(D_global_asm_807FBB44);
    RaaD->unk0 = 0xE;
    RaaD->unk24 = 2;
}

void func_race_8002D0FC(void) {
    RaceAdditionalActorData2 *RaaD;

    func_global_asm_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_global_asm_807FBB44->RaaD2;
    func_race_8002E2C8(D_global_asm_807FBB44);
    RaaD->unk0 = 2;
    RaaD->unk24 = 1;
}

s8 func_global_asm_806FDB8C(s32, s32, s32, f32, f32, f32);
s32 func_global_asm_8070E750(s32, s32, s32);

extern s32 D_race_8002FCD4[];

void func_race_8002D148(Struct8002D148 *arg0, u8 arg1) {
    u8 var_a3;
    RaceAdditionalActorData *aaD;

    if (arg0->unk4->unk34 != arg1) {
        arg0->unk4->unk34 = arg1;
        arg0->unk4->unk35 = 0;
        if (arg1 == 3) {
            aaD = current_actor_pointer->RaaD;
            var_a3 = arg0->unk4->unk36;
            if (((var_a3 + 1) == aaD->unk1E) || arg0->unk4->unk45) {
                var_a3 = 3;
            }
            if (arg0->unk4->unk27 == 0) {
                arg0->unk4->unk46 = func_global_asm_806FDB8C(1, func_global_asm_8070E750(0x26, D_race_8002FCD4[var_a3], 1), 2, 160.0f, 100.0f, 0.0f);
            }
        }
    }
}

void func_race_8002D224(u8 arg0) {
    RaaD_unk20 *var_s0;
    s32 i;
    RaceAdditionalActorData *RaaD;

    RaaD = current_actor_pointer->RaaD;
    var_s0 = RaaD->unk20;
    current_actor_pointer->control_state = arg0;
    for (i = 0; i < RaaD->unk1E; i++) {
        if (var_s0[i].unk0 != 0) {
            func_race_8002D148(&var_s0[i], arg0);
        }
    }
}

typedef struct RaceStruct12 {
    u8 pad0[0x26];
    u8 unk26;
    u8 unk27;
    u8 unk28;
} RaceStruct12;

f32 func_race_8002D2C0(RaceStruct12 *arg0) {
    if ((arg0->unk26 >= 0xB) && (arg0->unk26 < 0xF) && 
        (D_global_asm_807FD610[arg0->unk28].unk2A & 0x2000)) {
            f32 temp = (arg0->unk26 - 0xA);
            return temp * 0.2f;
    }
    return 0.0f;
}

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

void func_race_8002D338(Actor *arg0, RaceStruct0 *arg1) {
    Actor *temp = arg1->unkC;
    RaceAdditionalActorData *RaaD = temp->RaaD;
    RaaD->unk2C = 0;
    func_global_asm_806782C0(arg0);
}

// Appears to find the closest actor to whatever is passed in
Actor *func_race_8002D360(Actor *arg0) {
    f32 distance;
    f32 closestDistance;
    s32 i;
    RaaD_unk20 *var_a1;
    RaceAdditionalActorData *RaaD2;
    RaceAdditionalActorData *RaaD;
    Actor *examinedActor;
    Actor *temp;
    Actor *closestActor;

    closestDistance = 1000000000.0f;
    RaaD = arg0->RaaD;
    temp = RaaD->unk30;
    RaaD2 = temp->RaaD;
    closestActor = NULL;
    var_a1 = RaaD2->unk20;
    for (i = 0; i < RaaD2->unk1E; i++) {
        examinedActor = var_a1[i].unk0;
        if (examinedActor != NULL) {
            if (examinedActor != arg0) {
                distance = ((arg0->x_position - examinedActor->x_position) * (arg0->x_position - examinedActor->x_position)) + ((arg0->y_position - examinedActor->y_position) * (arg0->y_position - examinedActor->y_position)) + ((arg0->z_position - examinedActor->z_position) * (arg0->z_position - examinedActor->z_position));
                if (distance < closestDistance) {
                    closestActor = examinedActor;
                    closestDistance = distance;
                }
            }
        }
    }
    return closestActor;
}

void func_race_8002D40C(void) {
    s32 song;
    s32 i;
    RaceAdditionalActorData *RaaD;
    RaaD_unk20_unk4 *temp_v0_2;
    RaaD_unk20 *var_a0;

    RaaD = current_actor_pointer->RaaD;
    song = 0;
    i = RaaD->unk1E - 1;
    var_a0 = &RaaD->unk20[i];
    while (song == 0 && i >= 0) {
        if (RaaD->unk20[i].unk4->unk27 == 1) {
            if (RaaD->unk20[i].unk4->unk36 != 0) {
                song = 0x56;
            } else {
                song = 0x57;
            }
        }
        i--;
        var_a0--;
    }
    if (song == 0) {
        song = 0x56;
    }
    playSong(song, 1.0f);
}

void func_race_8002D4A0(void) {
    s32 song;
    f32 phi_f0;

    phi_f0 = 1.0f;
    switch (current_map) {
        case MAP_AZTEC_BEETLE_RACE:
            song = 0x13;
            phi_f0 = 0.6f;
            break;
        case MAP_GALLEON_SEAL_RACE:
            song = 0x3D;
            break;
        case MAP_CAVES_BEETLE_RACE:
            song = 0x66;
            break;
        case MAP_FACTORY_CAR_RACE:
        default:
            song = 0x1B;
    }

    playSong(song, phi_f0);
}

// RaaD 0x20 array
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002D524.s")

void func_race_8002D72C(Actor *arg0) {
    if (arg0 && arg0->control_state == 0) {
        RaceAdditionalActorData *RaaD = arg0->RaaD;
        RaaD->unk1C = 2;
    }
}

void func_race_8002D754(Actor *arg0) {
    if (arg0 && arg0->control_state == 0) {
        RaceAdditionalActorData* RaaD = arg0->RaaD;
        RaaD->unk1C = 0;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002D778.s")

typedef struct RaceStruct3 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} RaceStruct3;

void func_race_8002DA68(RaceStruct3 *arg0) {
    f32 temp_f2;
    s16 temp_v1;
    s16 phi_v0;

    switch (current_actor_pointer->control_state) {
        case 0:
            temp_v1 = arg0->unk2 % 2048;
            if ((temp_v1 >= 0x81) && ((0x800 - temp_v1) >= 0x81)) {
                arg0->unk2 += 0x80;
            }
            break;
        case 1:
            arg0->unk2 += 0x80;
            break;
    }

    arg0->unk2 &= 0xFFF;
    temp_f2 = (((func_global_asm_80612794(arg0->unk2) + 1.0f) * 1.5) + 1.0) * arg0->unk4;
    current_actor_pointer->animation_state->scale_x = \
    current_actor_pointer->animation_state->scale_y = \
    current_actor_pointer->animation_state->scale_z = temp_f2;
}

void func_race_8002DB90(void) {
    if (current_actor_pointer->control_state != 0) {
        if ((current_actor_pointer->control_state == 1) && (func_global_asm_80688540(current_actor_pointer, 0) == 0)) {
            func_global_asm_80688370(current_actor_pointer, 0, 1.0f);
            func_global_asm_8068842C(current_actor_pointer, 0, -1);
        }
    } else if (func_global_asm_80688540(current_actor_pointer, 0)) {
        func_global_asm_80688460(current_actor_pointer, 0, 1);
    }
}

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
} AAD_race_8002DC24;

void func_race_8002DC24(void) {
    AAD_race_8002DC24 *RaaD = current_actor_pointer->RaaD;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        RaaD->unk4 = current_actor_pointer->animation_state->scale_y;
    }
    switch (RaaD->unk0) {
        case 2:
            func_race_8002DB90();
            break;
        case 1:
            func_race_8002DB90();
            func_global_asm_80665564(current_actor_pointer, 0);
            current_actor_pointer->y_position = current_actor_pointer->unkAC;
            current_actor_pointer->unk6A |= 4;
            current_actor_pointer->unk6C |= 4;
            break;
        default:
            func_race_8002DA68(RaaD);
            break;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

typedef struct RaceStruct14 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Actor *unk1C[2]; // Used
} RaceStruct14;

// TODO: Any overlap with existing PaaD/RaaD?
typedef struct RaceAdditionalActorData3 {
    s32 unk0;
    s32 unk4;
    u8 unk8; // Used
} RaceAdditionalActorData3;

void func_race_8002DCF0(RaceStruct14 *arg0, s32 arg1);

void func_race_8002DCF0(RaceStruct14 *arg0, s32 arg1) {
    u8 i;
    RaceAdditionalActorData3 *RaaD;
    Actor *temp_v1;

    for (i = 0; i < 2; i++) {
        temp_v1 = arg0->unk1C[i];
        if (temp_v1 != NULL) {
            RaaD = temp_v1->RaaD;
            if (arg1 == 1) {
                if (RaaD->unk8 == 0) {
                    temp_v1->control_state = arg1;
                }
                RaaD->unk8++;
            } else {
                if (RaaD->unk8) {
                    RaaD->unk8--;
                }
                if (RaaD->unk8 == 0) {
                    temp_v1->control_state = arg1;
                }
            }
        }
    }
}

f32 func_race_8002DD70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return ((arg4 - arg2) * ((arg0 - arg1) / (arg3 - arg1))) + arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002DDA0.s")

typedef struct {
    u8 unk0[0xF - 0x0];
    u8 unkF;
    u8 unk10;
} Struct8002E1C8_arg0;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
} Struct8002E1C8_arg2;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct8002E1C8_arg3;

f32 func_race_8002DDA0(f32 arg0, Struct8002E1C8_arg2 *arg1);

void func_race_8002DE78(Struct8002E1C8_arg0 *arg0, u8 arg1, Struct8002E1C8_arg2 *arg2, Struct8002E1C8_arg3 *arg3) {
    switch (arg1) {
        case 0:
        case 1:
            arg2->unk4 = arg3->unk0;
            arg2->unkC = arg3->unk4;
            arg2->unk14 = arg3->unk4;
            arg2->unk1C = arg3->unk4;
            arg2->unk24 = arg3->unk4;
            arg2->unk2C = arg3->unk8;
            break;
        case 2:
        case 3:
            arg2->unk1C = arg3->unk8;
            arg2->unk24 = arg3->unk8;
            arg2->unk2C = arg3->unk8;
            break;
        case 5:
            arg2->unk4 = arg3->unk0;
            arg2->unkC = arg3->unk8;
            arg2->unk14 = arg3->unk8;
            arg2->unk1C = arg3->unk8;
            arg2->unk24 = arg3->unk8;
            arg2->unk2C = arg3->unk8;
            break;
    }
    current_actor_pointer->control_state_progress = 0;
    arg0->unkF = arg1;
}

// Jumptable, doable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_race_8002DF38.s")

f32 func_race_8002E1C8(Struct8002E1C8_arg0 *arg0, f32 arg1, Struct8002E1C8_arg2 *arg2, Struct8002E1C8_arg3 *arg3) {
    f32 var_f2;

    switch (arg0->unkF) {
        default:
            var_f2 = 0.0f;
            break;
        case 0:
            var_f2 = func_race_8002DDA0(arg1, arg2);
            break;
        case 1:
            var_f2 = func_race_8002DDA0(arg1, arg2);
            if (arg0->unk10 != 0) {
                if (arg2->unk20 < arg1) {
                    func_race_8002DE78(arg0, 5, arg2, arg3);
                }
            }
            break;
        case 5:
            var_f2 = func_race_8002DDA0(arg1, arg2);
            if (arg1 < arg2->unk8) {
                func_race_8002DE78(arg0, 1, arg2, arg3);
            }
            break;
    }
    return var_f2;
}

typedef struct {
    u8 unk0[0x25 - 0x0];
    u8 unk25;
    u8 unk26;
} AAD_race_8002E2C8;

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
    u8 unk28;
    u8 unk29[0x30 - 0x29];
    Actor *unk30;
    u8 unk34[0x36 - 0x34];
    u8 unk36;
} AAD_race_8002E2C8_Actor315;

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
} A178_race_8002E2C8;

void func_race_8002E2C8(Actor *arg0) {
    AAD_race_8002E2C8 *sp5C;
    AAD_race_8002E2C8_Actor315 *sp58;
    Actor *sp54;
    Actor17C *temp_a2;
    s32 var_s1;
    s32 i;
    s32 var_s4;

    var_s4 = cc_number_of_players;
    var_s1 = 0;
    sp5C = arg0->additional_actor_data;
    if (var_s4 == 1) {
        var_s4++;
    }
    func_race_8002BBD0(arg0, var_s4);
    if (cc_number_of_players == 1) {
        sp54 = func_global_asm_807271F4(1, 0, 0, 0, 0, 0, 0);
        sp58 = sp54->unk178;
        sp58->unk27 = 1;
        func_race_8002BC2C(arg0, 0, sp54, sp58);
        var_s1 = 1;
        temp_a2 = sp54->unk17C;
        func_race_8002BCB0(arg0, 0, temp_a2, &temp_a2->unk4);
        sp5C->unk25 = 1;
    } else {
        sp5C->unk25 = 0;
    }
    for (i = 0; i < cc_number_of_players; i++) {
        func_global_asm_80677FA8(ACTOR_UNKNOWN_315, 0);
        sp54 = D_global_asm_807FBB44;
        sp58 = sp54->additional_actor_data;
        sp58->unk27 = 0;
        func_race_8002BC2C(arg0, var_s1, sp54, sp58);
        var_s1 += 1;
        sp58->unk28 = i;
    }
    for (i = 0; i < var_s4; i++) {
        func_race_8002BCB0(arg0, i, &sp54, &sp58);
        sp58->unk36 = i;
        sp58->unk30 = arg0;
    }
    sp5C->unk26 = 0;
}

void func_race_8002E464(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_race_8002CAC8(arg0, arg1, arg1->PaaD);
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    s32 unk20;
    s32 unk24;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    s32 unk2C;
    s32 unk30;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    s16 unk38;
    u16 unk3A;
    s32 unk3C;
    f32 unk40;
} AAD_race_8002E484;

void func_race_8002E484(void) {
    Actor *var_a3;
    AAD_race_8002E484 *temp_s0;

    temp_s0 = current_actor_pointer->additional_actor_data;
    var_a3 = character_change_array[temp_s0->unk28].player_pointer;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806EB0C0(0x4E, current_actor_pointer, temp_s0->unk28);
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
    }
    if (temp_s0->unk34 == 2) {
        if (current_actor_pointer->control_state == 0) {
            func_global_asm_806EB0C0(0x57, NULL, temp_s0->unk28);
            current_actor_pointer->control_state += 1;
        }
    }
    current_actor_pointer->x_position = var_a3->x_position;
    current_actor_pointer->y_position = var_a3->y_position;
    current_actor_pointer->z_position = var_a3->z_position;
    if (temp_s0->unk34 == 2) {
        func_race_8002F490(temp_s0);
    }
    if (temp_s0->unk34 > 0) {
        if (temp_s0->unk34 < 5) {
            func_global_asm_8068C350(&func_race_8002E464, current_actor_pointer, 3);
        }
    }
    if (temp_s0->unk40 < temp_s0->unk1C) {
        temp_s0->unk1C = temp_s0->unk1C;
    } else {
        temp_s0->unk1C = temp_s0->unk40;
    }
    temp_s0->unk14 = (temp_s0->unk3A * 3000) - temp_s0->unk40;
    if (temp_s0->unk14 < temp_s0->unk18) {
        temp_s0->unk18 = temp_s0->unk18;
        return;
    }
    temp_s0->unk18 = temp_s0->unk14;
}

extern u8 D_global_asm_807FBD70;

// TODO: Merge back into original struct
typedef struct {
    Actor *unk0;
    s32 unk4; // Used
    s32 unk8;
    s8 unkC;
    s8 unkD;
    u8 unkE; // Used
    u8 unkF; // Used
    s8 unk10; // Used
    s8 unk11;
    s8 unk12;
    s8 unk13;
    f32 unk14; // Used
} A17C_race_8002B964;

void func_race_8002E644(A17C_race_8002B964 *arg0) {
    f32 sp5C;
    s32 pad58;
    f32 sp54;
    f32 sp50;
    s32 pad4C;
    s16 sp4A;
    s16 sp48;
    s16 sp46;
    s16 pad44;
    f32 sp40;
    s32 sp3C;
    f32 temp_f2_2;
    Actor *actor;

    actor = arg0->unk0;
    sp5C = (((actor->x_position - current_actor_pointer->x_position)) * ((actor->x_position - current_actor_pointer->x_position))) + (((actor->z_position - current_actor_pointer->z_position)) * ((actor->z_position - current_actor_pointer->z_position)));
    if (D_global_asm_807FBD70 == 4 && sp5C < arg0->unk14) {
        if (arg0->unkF == 1
            || arg0->unkF == 0
            || arg0->unkF == 4
            || (current_actor_pointer->unk58 == ACTOR_CAR_CASTLE_ENEMY && arg0->unkF == 5)) {
            sp46 = func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, actor->x_position, actor->z_position);
            sp40 = 1.0f;
            if (func_global_asm_806CC14C(actor->unkEE, sp46) < 0x200) {
                sp40 = 4.0f;
            }
            sp48 = (actor->unkEE - sp46);
            sp48 &= 0xFFF;
            
            sp4A = (current_actor_pointer->unkEE - sp46);
            sp4A &= 0xFFF;
            
            sp54 = func_global_asm_80612794(sp48) * actor->unkB8;
            sp50 = func_global_asm_80612790(sp48) * actor->unkB8;
            temp_f2_2 = func_global_asm_80612790(sp4A) * current_actor_pointer->unkB8;
            sp50 = ((temp_f2_2 - sp50) * sp40) + temp_f2_2;
            actor->unkB8 = sqrtf((sp54 * sp54) + (sp50 * sp50));
            
            actor->unkEE = (func_global_asm_80611BB4(sp54, sp50) * 4096.0) / 6.28318548202514648;
            actor->unkEE += sp46;
            actor->unkEE &= 0xFFF;
            
            if (arg0->unkE == 0) {
                switch (current_actor_pointer->unk58) {
                    case 0x134:
                        sp3C = 0x1F9;
                        break;
                    case 0x143:
                        sp3C = 0x18A;
                        break;
                }
                func_global_asm_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, sp3C, 0xFF, 0x7F, 0, 0, 0.0f, 0);
                arg0->unkE = 0x14;
            }
        }
    }
    arg0->unk14 = sp5C;
    if (arg0->unkE > 0) {
        arg0->unkE--;
    }
}

typedef struct {
    u8 unk0[0x36 - 0];
    u8 unk36;
} Struct8002E8EC_arg0;

typedef struct {
    u8 unk0[0x45 - 0];
    u8 unk45;
} Struct8002E8EC_arg1;

s32 func_race_8002E8EC(Struct8002E8EC_arg0 *arg0, Struct8002E8EC_arg1 *arg1, s32 arg2) {
    s32 var_v1;

    if (arg1->unk45 != 0) {
        var_v1 = 0;
    } else if (arg0->unk36 != 0) {
        if (func_global_asm_806F8AD4(0xB, 0) >= arg2) {
            var_v1 = 1;
        } else {
            var_v1 = 3;
        }
    } else {
        var_v1 = 2;
    }
    return var_v1;
}
