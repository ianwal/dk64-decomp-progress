#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u16 unk1A;
    Actor *unk1C[1]; // TODO: How many?
} Struct8002EDD4_arg0;

// TODO: Is this the same as RaceStruct6?
typedef struct RaceStruct13 {
    u16 unk0;
    u16 unk2;
    u16 *unk4;
    u16 unk8;
    u16 unkA;
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
    s16 unk38;
    u16 unk3A;
    u16 unk3C;
} RaceStruct13;

// TODO: Any struct overlap with existing structs?
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10[4];
    s32 unk20;
    u8 unk24;
    u8 unk25;
    u16 unk26;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s16 unk34;
    s8 unk36;
    s8 unk37;
    s8 unk38;
    s8 unk39;
    u16 unk3A;
    s32 unk3C;
    f32 unk40;
} RaceStruct6;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} RaceStruct2_unkC;

typedef struct {
    u16 unk0;
    u8 pad2[2];
    s16 *unk4;
    u16 unk8;
    u8 padA[2];
} RaceStruct2_unk4;

typedef struct RaceStruct2 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    RaceStruct2_unk4 *unk4;
    u16 unk8;
    s16 unkA;
    RaceStruct2_unkC *unkC;
} RaceStruct2;

// .data
RaceStruct2 *D_race_8002FCF0 = NULL;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct8002F280_arg0;

typedef struct RaceStruct10 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
} RaceStruct10;

extern u16 D_global_asm_80750AC4;

void func_race_8002DCF0(void*, s32);
RaceStruct2_unkC *func_race_8002E9AC(u8);
void func_race_8002F36C(RaceStruct13*, RaceStruct13*);
void func_race_8002E9F8(u8 *checkpointFile);

u16 *func_race_8002E960(u8 arg0) {
    // This new_var fixes a regalloc, v1 => a1. Maybe this is missing a parameter?
    void *new_var;
    new_var = &D_race_8002FCF0->unk4[arg0];
    if ((D_race_8002FCF0 == NULL) || (arg0 >= D_race_8002FCF0->unk0))
    {
        return NULL;
    }
    new_var = &D_race_8002FCF0->unk4[arg0];
    return new_var;
}

RaceStruct2_unkC *func_race_8002E9AC(u8 arg0) {
    // This new_var fixes a regalloc, v1 => a1. Maybe this is missing a parameter?
    void* new_var;
    new_var = &D_race_8002FCF0->unkC[arg0];
    if ((D_race_8002FCF0 == NULL) || (arg0 >= D_race_8002FCF0->unk8)) {
        return NULL;
    }
    new_var = &D_race_8002FCF0->unkC[arg0];
    return new_var;
}

void func_race_8002EDD4(Struct8002EDD4_arg0 *);

void func_race_8002E9F8(u8 *arg0) {
    s32 l;
    s32 k;
    s32 j;
    RaceStruct2_unkC *var_s0;
    s32 var_s1;
    RaceStruct2_unk4 *var_s2;
    s32 size;
    s32 size_0;

    if (!arg0) {
        return;
    }
    var_s1 = arg0;
    memcpy(D_race_8002FCF0, var_s1, 1U);
    var_s1++;
    memcpy(&D_race_8002FCF0->unk8, var_s1, 2U);
    var_s1 += 2;
    D_race_8002FCF0->unk4 = malloc(D_race_8002FCF0->unk0 * sizeof(RaceStruct2_unk4));
    func_global_asm_80611690(D_race_8002FCF0->unk4);
    var_s2 = D_race_8002FCF0->unk4;
    for (l = 0; l < D_race_8002FCF0->unk0; l++) {
        memcpy(var_s2, var_s1, 2U);
        var_s1 += 2;
        var_s2->unk4 = malloc(var_s2->unk0 * sizeof(s16));
        size = var_s2->unk0 * 2;
        memcpy(var_s2->unk4, var_s1, size);
        var_s1 += size;
        var_s2++;
    }
    l = 0;
    D_race_8002FCF0->unkC = malloc(D_race_8002FCF0->unk8 * sizeof(RaceStruct2_unkC));
    func_global_asm_80611690(D_race_8002FCF0->unkC);
    var_s0 = D_race_8002FCF0->unkC;
    for (j = 0; j < D_race_8002FCF0->unk8; j++) {
        memcpy(var_s0, var_s1, 0x1CU);
        var_s1 += 0x1C;
        func_race_8002EDD4(var_s0);
        var_s0++;
    }
    var_s2 = D_race_8002FCF0->unk4;
    for (; l < D_race_8002FCF0->unk0; l++) {
        var_s2->unk8 = 0U;
        for (k = 0; k < var_s2->unk0; k++) {
            if (func_race_8002E9AC(var_s2->unk4[k])->unk10) {
                var_s2->unk8++;
            }
        }
        var_s2++;
    }
}



void setupRaceOnMapLoad(Maps map) {
    s32 *checkpointFile = getPointerTableFile(TABLE_24_CHECKPOINTS, map, 1, 1);
    D_race_8002FCF0 = malloc(sizeof(RaceStruct2));
    func_global_asm_80611690(D_race_8002FCF0);
    func_race_8002E9F8(checkpointFile);
    switch (map) {
        case MAP_FACTORY_CAR_RACE:
            func_race_80025FDC();
            break;
        case MAP_GALLEON_SEAL_RACE:
            sealRaceSetup();
            break;
        case MAP_AZTEC_BEETLE_RACE:
        case MAP_CAVES_BEETLE_RACE:
            func_race_8002D0FC();
            break;
        case MAP_CASTLE_CAR_RACE:
            castleCarRaceSetup();
            break;
    }
    D_global_asm_80750AC4 = 0;
}

void func_race_8002ECD4(Actor *arg0, f32 arg1) {
    arg0->animation_state->scale_x *= arg1;
    arg0->animation_state->scale_y = arg0->animation_state->scale_x;
    arg0->animation_state->scale_z = arg0->animation_state->scale_y;
}

void func_race_8002ED04(f32 arg0, s32 arg1, u8 arg2) {
    RaceAdditionalActorData2 *sp1C;

    switch (arg1) {
        case 1:
            if (arg2) {
                spawnActor(ACTOR_RACE_CHECKPOINT_0, 0xB0);
                playActorAnimation(gLastSpawnedActor, 0x2A9);
            } else {
                spawnActor(ACTOR_RACE_CHECKPOINT_0, 0xB1);
                playActorAnimation(gLastSpawnedActor, 0x2AA);
            }
            break;
        case 2:
            spawnActor(ACTOR_RACE_CHECKPOINT_0, arg2 ? 0xD8 : 0xD9); // Spawn checkpoint (actor 311)
            break;
    }
    sp1C = gLastSpawnedActor->RaaD2;
    func_race_8002ECD4(gLastSpawnedActor, arg0);
    sp1C->unk0 = arg1;
}

void func_race_8002EDD4(Struct8002EDD4_arg0 *arg0) {
    f32 spD0[4][4];
    f32 sp90[4][4];
    f32 var_f22;
    s32 temp[5];
    u8 i;
    if (arg0->unk10 != 0) {
        if (arg0->unk18 == 2) {
            var_f22 = arg0->unk1A * 0.5f;
            for (i = 0; i < 2; i++) {
                func_race_8002ED04(arg0->unk14, arg0->unk10, i ^ 1);
                arg0->unk1C[i] = gLastSpawnedActor;
                gLastSpawnedActor->y_rotation = (arg0->unk6 + 0x800) & 0xFFF;
                if (i) {
                    var_f22 *= -1.0f;
                }
                guRotateF(spD0, gLastSpawnedActor->y_rotation * 0.087890625f, 0.0f, 1.0f, 0.0f);
                guTranslateF(sp90, arg0->unk0, arg0->unk2, arg0->unk4);
                guMtxCatF(spD0, sp90, spD0);
                guMtxXFMF(spD0, var_f22, 0.0f, 0.0f, &gLastSpawnedActor->x_position, &gLastSpawnedActor->y_position, &gLastSpawnedActor->z_position);
            }
        } else {
            func_race_8002ED04(arg0->unk14, arg0->unk10, (arg0->unk18 == 1));
            arg0->unk1C[0] = gLastSpawnedActor;
            gLastSpawnedActor->y_rotation = (arg0->unk6 + 0x800) & 0xFFF;
            gLastSpawnedActor->x_position = arg0->unk0;
            gLastSpawnedActor->y_position = arg0->unk2;
            gLastSpawnedActor->z_position = arg0->unk4;
        }
    }
}

f32 func_race_8002F04C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 phi_f2;
    f32 temp;
    f32 temp2;

    phi_f2 = 0.0f;
    temp = (arg7 * arg2);
    temp2 = (arg6 * arg3);
    if (temp != temp2) {
        phi_f2 = (((arg4 - arg0) * arg3) + (arg2 * (arg1 - arg5))) / (temp - temp2);
    }
    return phi_f2;
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 pad11[0x18 - 0x11];
    u8 unk18[4];
    Actor *unk1C[2];
    s32 unk24;
} Struct8002F0AC;

u8 func_race_8002F0AC(Struct8002F0AC *arg0) {
    f32 sp44;
    f32 sp40;
    f32 dz;
    f32 dx;
    f32 sp34;
    f32 sp30;
    f32 temp_f0_2;
    u8 boolReturn;

    boolReturn = FALSE;
    if (arg0->unk10 == 0) {
        return 1;
    }
    switch (arg0->unk18[0]) {
        case 2:
            sp44 = arg0->unk1C[1]->x_position - arg0->unk1C[0]->x_position;
            sp40 = arg0->unk1C[1]->z_position - arg0->unk1C[0]->z_position;
            sp34 = arg0->unk1C[0]->x_position;
            sp30 = arg0->unk1C[0]->z_position;
            break;
        case 0:
            sp44 = -arg0->unkC;
            sp40 = arg0->unk8;
            sp34 = arg0->unk0;
            sp30 = arg0->unk4;
            break;
        case 1:
            sp44 = arg0->unkC;
            sp40 = -arg0->unk8;
            sp34 = arg0->unk0;
            sp30 = arg0->unk4;
            break;
    }
    dx = gCurrentActorPointer->unk88 - gCurrentActorPointer->x_position;
    dz = gCurrentActorPointer->unk90 - gCurrentActorPointer->z_position;
    temp_f0_2 = func_race_8002F04C(
        gCurrentActorPointer->x_position,
        gCurrentActorPointer->z_position,
        dx,
        dz,
        sp34,
        sp30,
        sp44,
        sp40
    );
    switch (arg0->unk18[0]) {
        case 2:
            if ((temp_f0_2 > 0.0f) && (temp_f0_2 < 1.0f)) {
                boolReturn = TRUE;
            }
            break;
        case 0:
        case 1:
            if (temp_f0_2 > 0.0f) {
                boolReturn = TRUE;
            }
            break;
    }
    return boolReturn;
}

u8 func_race_8002F280(Struct8002F280_arg0 *arg0) {
    f32 p1 = (gCurrentActorPointer->x_position - arg0->unk0);
    f32 p2 = (gCurrentActorPointer->z_position - arg0->unk4);
    return func_global_asm_806CC14C((s16)(((s32)(func_global_asm_80611BB4(p1, p2) * 651.8986f)) & 0xFFF), arg0->unk6) < 0x400;
}

f32 func_race_8002F304(RaceStruct10 *arg0, f32 arg1, f32 arg2) {
    return func_race_8002F04C(
        arg0->unk0,
        arg0->unk4,
        -arg0->unkC,
        arg0->unk8,
        arg1,
        arg2,
        arg0->unk8,
        arg0->unkC
    );
}

void func_race_8002F36C(RaceStruct13 *arg0, RaceStruct13 *arg1) {
    RaceStruct2_unkC *temp_v0;
    s32 temp;

    if (arg1->unk8) {
        do {
            arg0->unk3C++;
            arg0->unk3C = arg0->unk3C % arg1->unk0;
            temp = arg1->unk4[arg0->unk3C];
            temp_v0 = func_race_8002E9AC(temp);
        } while (!temp_v0->unk10);
        func_race_8002DCF0(temp_v0, 1);
    }
}

void func_race_8002F420(RaceStruct13 *arg0, RaceStruct13 *arg1) {
    if (arg1->unk8 && arg0->unk3C == arg0->unk3A) {
        s32 temp = arg1->unk4[arg0->unk3C];
        func_race_8002DCF0(func_race_8002E9AC(temp), 0);
        func_race_8002F36C(arg0, arg1);
    }
}

void func_race_8002F490(Struct8002F490 *arg0) {
    s32 pad[2];
    RaceStruct2_unk4 *temp_v0; // 44
    s32 pad2[2];
    f32 sp38;
    f32 temp_f12;
    f32 temp_f14;
    RaceStruct2_unkC *temp_v0_2;
    AADTemp0 *aadTemp;
    Actor *tempActor;
    u16 temp_v0_4;

    tempActor = arg0->unk30;
    aadTemp = tempActor->AAD_as_array[0];
    temp_v0 = func_race_8002E960(aadTemp->unk26);
    if (!temp_v0) {
        return;
    }
    temp_v0_4 = temp_v0->unk4[arg0->unk3A];
    temp_v0_2 = func_race_8002E9AC(temp_v0_4);
    if (!temp_v0_2) {
        return;
    }
    temp_f12 = gCurrentActorPointer->x_position;
    temp_f14 = gCurrentActorPointer->z_position;
    if ((SQ(temp_v0_2->unk0 - temp_f12) + SQ(temp_v0_2->unk4 - temp_f14)) > 900.0f) {
        sp38 = func_global_asm_80665AE4(
            temp_v0_2->unk0,
            temp_v0_2->unk4,
            temp_f12,
            temp_f14);

        gCurrentActorPointer->unkEC = sp38 - func_global_asm_80665AE4(
            character_change_array[arg0->unk28].look_at_at_x,
            character_change_array[arg0->unk28].look_at_at_z,
            character_change_array[arg0->unk28].look_at_eye[arg0->unk28],
            character_change_array->look_at_eye_z);
    }
    if (arg0->unk38 != 0) {
        arg0->unk38 = func_race_8002F280(temp_v0_2);
    } else if (func_race_8002F280(temp_v0_2) != 0) {
        if (arg0->unk27 == 0) {
            if (temp_v0_2->unk10 != 0) {
                if (func_race_8002F0AC(temp_v0_2) == 0) {
                    playSoundAtPosition(
                        temp_v0_2->unk0,
                        temp_v0_2->unk2,
                        temp_v0_2->unk4,
                        0x98, 0xFFU, 0x7F, 0U, 0U, 0.3f, 0U);
                    if (arg0->unk44 != 0) {
                        arg0->unk44--;
                    } else {
                        arg0->unk45 = 1;
                    }
                } else {
                    playSong(MUSIC_67_CHECKPOINT, 1.0f);
                }
            }
            func_race_8002F420(arg0, temp_v0);
        }
        arg0->unk3A++;
        arg0->unk3A %= temp_v0->unk0;
        if (arg0->unk3A == 0) {
            arg0->unk37++;
        }
        temp_v0_4 = temp_v0->unk4[arg0->unk3A];
        temp_v0_2 = func_race_8002E9AC(temp_v0_4);
        arg0->unk38 = func_race_8002F280(temp_v0_2);
    }
    arg0->unk40 = func_race_8002F304(temp_v0_2,
        gCurrentActorPointer->x_position,
        gCurrentActorPointer->z_position);
}

// close, doable, float, stack
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_race_8002F784.s")

typedef struct {
    u16 unk0;
    u16 unk2;
    s16 unk4[1]; // TODO: How many? This is probably a regular pointer.
} Struct8002F784;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct8002E9AC;

/*
f32 func_race_8002F784(Struct8002F784 *arg0, RaceStruct6 *arg1, RaceStruct6 *arg2) {
    f32 ret; // f20
    s32 n1;
    s32 boolCheck; // s2
    s32 n2;
    s32 sign;
    Struct8002E9AC *temp_s0;
    s32 d;

    n1 = (arg1->unk37 * arg0->unk0) + arg1->unk3A;
    n2 = (arg2->unk37 * arg0->unk0) + arg2->unk3A;
    d = n2 - n1;
    ret = arg1->unk40 - arg2->unk40;
    if (d < 0) {
        s32 temp_s1;
        temp_s1 = n1 ^ n2;
        n2 = n2 ^ temp_s1;
        n1 = temp_s1 ^ n2;
        ret = -ret;
    }
    boolCheck = 1;
    if (n1 != n2) {
        f32 var_f22;
        f32 var_f24;
        while (n1 <= n2) {
            u16 temp = arg0->unk4[n1 % arg0->unk0];
            temp_s0 = func_race_8002E9AC(temp);
            if (!boolCheck) {
                boolCheck = 0;
                ret += func_race_8002F304(temp_s0, var_f22, var_f24);
            }
            n1++;
            var_f22 = temp_s0->unk0;
            var_f24 = temp_s0->unk4;
        }
    }
    if (d >= 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    return ret * sign;
}
*/

f32 func_race_8002F90C(RaceStruct6 *arg0, RaceStruct6 *arg1, RaceStruct6 *arg2) {
    f32 temp = ((arg1->unk37 - 1) * arg0->unk0) + arg1->unk3A;
    f32 temp2 = arg2->unk24 * arg0->unk0;
    return temp / temp2;
}

// TODO: Any struct overlap with existing structs?
typedef struct Struct8002F950 {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10[4];
    s32 unk20;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s16 unk34;
    s8 unk36;
    s8 unk37;
    s8 unk38;
    s8 unk39;
    u16 unk3A;
    s32 unk3C;
    f32 unk40;
} Struct8002F950;

typedef struct Struct8002F950_temp_v0_2 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 pad11[0x1C - 0x11];
    Actor *unk1C[2];
    s32 unk24;
} Struct8002F950_temp_v0_2;

typedef struct Struct8002F950_temp_v0_sub4 {
    u8 unk0;
    u8 unk1;
} Struct8002F950_temp_v0_sub4;

typedef struct Struct8002F950_temp_v0 {
    u16 unk0;
    u8 pad2[2];
    Struct8002F950_temp_v0_sub4 *unk4;
    s16 unk8;
} Struct8002F950_temp_v0;

void func_race_8002F950(Struct8002F950 *arg0) {
    s32 i;
    s32 k;
    s32 var_s2;
    s32 j;
    Struct8002F950_temp_v0 *temp_v0;
    Struct8002F950_temp_v0_2 *cpoint;
    f32 d;
    tuple_f *t;

    temp_v0 = func_race_8002E960(arg0->unk26);
    if (temp_v0 == NULL) {
        return;
    }
    for (j = 0; j < temp_v0->unk0; j++) {
        cpoint = func_race_8002E9AC(temp_v0->unk4[j].unk1);
        if (cpoint->unk10) {
            var_s2 = 0;
            for (i = 0; i < cc_number_of_players; i++) {
                t = &character_change_array[i].look_at_eye_x;
                d = (
                    SQ(t->z - cpoint->unk4) +
                    (SQ(t->x - cpoint->unk0) +
                    SQ(t->y - cpoint->unk2))
                );
                var_s2 |= (d > 302500.0f);
            }
            if (var_s2 != cpoint->unk24) {
                for (k = 0; k < 2; k++) {
                    if (cpoint->unk1C[k]) {
                        if (var_s2 != 0) {
                            func_global_asm_80678458(cpoint->unk1C[k]);
                        } else {
                            func_global_asm_80678428(cpoint->unk1C[k]);
                        }
                    }
                }
                cpoint->unk24 = var_s2;
            }
        }
    }
}
