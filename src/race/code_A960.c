#include <ultra64.h>
#include "functions.h"

extern u16 D_80750AC4;

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
    s32 unk0;
    s32 unk4;
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
    s32 unk0;
    s32 unk4;
    s32 unk8;
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
extern RaceStruct2 *D_8002FCF0;

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002E960.s")

/*
void *func_8002E960(u8 arg0) {
    if (D_8002FCF0 == NULL || arg0 >= D_8002FCF0->unk0) {
        return NULL;
    }
    return &D_8002FCF0->unk4[arg0];
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002E9AC.s")

/*
void *func_8002E9AC(u8 arg0) {
    if ((D_8002FCF0 == NULL) || (arg0 >= D_8002FCF0->unk8)) {
        return NULL;
    }
    return &D_8002FCF0->unkC[arg0];
}
*/

// arg0 is checkpoint file pointer
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002E9F8.s")

void setupRaceOnMapLoad(s32 map) {
    s32 *checkpointFile = getPointerTableFile(0x18, map, 1, 1);
    D_8002FCF0 = malloc(0x10);
    func_80611690(D_8002FCF0);
    func_8002E9F8(checkpointFile);
    switch (map) {
        case MAP_FACTORY_CAR_RACE:
            func_80025FDC();
            break;
        case MAP_GALLEON_SEAL_RACE:
            sealRaceSetup();
            break;
        case MAP_AZTEC_BEETLE_RACE:
        case MAP_CAVES_BEETLE_RACE:
            func_8002D0FC();
            break;
        case MAP_CASTLE_CAR_RACE:
            castleCarRaceSetup();
            break;
    }
    D_80750AC4 = 0;
}

void func_8002ECD4(Actor *arg0, f32 arg1) {
    arg0->animation_state->scale_x *= arg1;
    arg0->animation_state->scale_y = arg0->animation_state->scale_x;
    arg0->animation_state->scale_z = arg0->animation_state->scale_y;
}

void func_8002ED04(f32 arg0, s32 arg1, u8 arg2) {
    RaceAdditionalActorData2 *sp1C;

    switch (arg1) {
        case 1:
            if (arg2) {
                func_80677FA8(ACTOR_RACE_CHECKPOINT_0, 0xB0); // Spawn checkpoint (actor 311)
                func_80614EBC(D_807FBB44, 0x2A9);
            } else {
                func_80677FA8(ACTOR_RACE_CHECKPOINT_0, 0xB1); // Spawn checkpoint (actor 311)
                func_80614EBC(D_807FBB44, 0x2AA);
            }
            break;
        case 2:
            func_80677FA8(ACTOR_RACE_CHECKPOINT_0, arg2 ? 0xD8 : 0xD9); // Spawn checkpoint (actor 311)
            break;
    }
    sp1C = D_807FBB44->RaaD2;
    func_8002ECD4(D_807FBB44, arg0);
    sp1C->unk0 = arg1;
}

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
    s32 unk1C[1]; // TODO: How many?
} Struct8002EDD4_arg0;

void func_80008620(f32*, f32, f32, f32, f32);
void func_80008810(f32*, f32, f32, f32, f32*, f32*, f32*);
void func_80005D80(f32*, f32, f32, f32);
void func_800088B0(void*, void*, void*);

void func_8002EDD4(Struct8002EDD4_arg0 *arg0) {
    f32 spD0[4][4];
    f32 sp90[4][4];
    f32 var_f22;
    s32 temp[5];
    u8 i;
    if (arg0->unk10 != 0) {
        if (arg0->unk18 == 2) {
            var_f22 = arg0->unk1A * 0.5f;
            for (i = 0; i < 2; i++) {
                func_8002ED04(arg0->unk14, arg0->unk10, i ^ 1);
                arg0->unk1C[i] = D_807FBB44;
                D_807FBB44->y_rotation = (arg0->unk6 + 0x800) & 0xFFF;
                if (i) {
                    var_f22 *= -1.0f;
                }
                func_80008620(&spD0, D_807FBB44->y_rotation * 0.087890625f, 0.0f, 1.0f, 0.0f);
                func_80005D80(&sp90, arg0->unk0, arg0->unk2, arg0->unk4);
                func_800088B0(&spD0, &sp90, &spD0);
                func_80008810(&spD0, var_f22, 0.0f, 0.0f, &D_807FBB44->x_position, &D_807FBB44->y_position, &D_807FBB44->z_position);
            }
        } else {
            func_8002ED04(arg0->unk14, arg0->unk10, (arg0->unk18 == 1));
            arg0->unk1C[0] = D_807FBB44;
            D_807FBB44->y_rotation = (arg0->unk6 + 0x800) & 0xFFF;
            D_807FBB44->x_position = arg0->unk0;
            D_807FBB44->y_position = arg0->unk2;
            D_807FBB44->z_position = arg0->unk4;
        }
    }
}

f32 func_8002F04C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002F0AC.s")

extern f32 D_80030150;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct8002F280_arg0;

u8 func_8002F280(Struct8002F280_arg0 *arg0) {
    f32 p1 = (current_actor_pointer->x_position - arg0->unk0);
    f32 p2 = (current_actor_pointer->z_position - arg0->unk4);
    return func_806CC14C((s16)(((s32)(func_80611BB4(p1, p2) * D_80030150)) & 0xFFF), arg0->unk6) < 0x400;
}

f32 func_8002F04C(f32, f32, f32, f32, f32, f32, f32, f32);
typedef struct RaceStruct10 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
} RaceStruct10;

f32 func_8002F304(RaceStruct10 *arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0->unkC;
    temp_f2 = arg0->unk8;
    return func_8002F04C(arg0->unk0, 
                    arg0->unk4, 
                    -temp_f0, 
                    temp_f2, 
                    arg1, 
                    arg2, 
                    temp_f2, 
                    temp_f0);
}

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

void func_8002DCF0(void*, s32);
void func_8002F36C(RaceStruct13*, RaceStruct13*);
void *func_8002E9AC(u8);

void func_8002F36C(RaceStruct13 *arg0, RaceStruct13 *arg1) {
    RaceStruct2_unkC *temp_v0;
    s32 temp;

    if (arg1->unk8) {
        do {
            arg0->unk3C++;
            arg0->unk3C = arg0->unk3C % arg1->unk0;
            temp = arg1->unk4[arg0->unk3C];
            temp_v0 = func_8002E9AC(temp);
        } while (!temp_v0->unk10);
        func_8002DCF0(temp_v0, 1);
    }
}

void func_8002F420(RaceStruct13 *arg0, RaceStruct13 *arg1) {
    if (arg1->unk8 && arg0->unk3C == arg0->unk3A) {
        s32 temp = arg1->unk4[arg0->unk3C];
        func_8002DCF0(func_8002E9AC(temp), 0);
        func_8002F36C(arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002F784.s")

typedef struct {
    u16 unk0;
    u16 unk2;
    s16 unk4[1]; // TODO: How many?
} Struct8002F784;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct8002E9AC;

/*
// TODO: Quite close
f32 func_8002F784(Struct8002F784 *arg0, RaceStruct6 *arg1, RaceStruct6 *arg2) {
    s32 sp54;
    f32 temp;
    f32 temp2;
    f32 var_f20;
    f32 var_f22;
    f32 var_f24;
    s32 temp_s1;
    s32 i;
    s32 var_s2;
    s32 var_s4;
    s32 var_v0;
    Struct8002E9AC *temp_s0;

    i = (arg1->unk37 * arg0->unk0) + arg1->unk3A;
    var_s4 = (arg2->unk37 * arg0->unk0) + arg2->unk3A;
    sp54 = var_s4 - i;
    var_f20 = arg1->unk40 - arg2->unk40;
    if (sp54 < 0) {
        temp_s1 = i ^ var_s4;
        var_s4 ^= temp_s1;
        i = temp_s1 ^ var_s4;
        var_f20 = -var_f20;
    }
    var_s2 = 1;
    if (i != var_s4) {
        for (; i <= var_s4; i++) {
            temp_s0 = func_8002E9AC(arg0->unk4[i % arg0->unk0]);
            var_s2 = 0;
            if (var_s2 == 0) {
                var_f20 += func_8002F304(temp_s0, var_f22, var_f24);
            }
            var_f22 = temp_s0->unk0;
            var_f24 = temp_s0->unk4;
        }
    }
    if (sp54 >= 0) {
        var_v0 = 1;
    } else {
        var_v0 = -1;
    }
    return var_f20 * var_v0;
}
*/

f32 func_8002F90C(RaceStruct6 *arg0, RaceStruct6 *arg1, RaceStruct6 *arg2) {
    f32 temp = ((arg1->unk37 - 1) * arg0->unk0) + arg1->unk3A;
    f32 temp2 = arg2->unk24 * arg0->unk0;
    return temp / temp2;
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_A960/func_8002F950.s")

/*
void *func_8002E960(u8);
void *func_8002E9AC(u8);
extern f32 D_80030158;

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
} Struct8002F950;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Struct8002F950_temp_v0_2;

void func_8002F950(Struct8002F950 *arg0) {
    Actor *temp_a0;
    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f8;
    s32 playerIndex;
    s32 var_s0;
    s32 var_s2;
    s32 var_s5;
    s32 var_s6;
    s32 var_t3;
    void *temp_v0;
    Struct8002F950_temp_v0_2 *temp_v0_2;
    void *var_s1;

    temp_v0 = func_8002E960(arg0->unk26);
    if (temp_v0 != NULL) {
        var_s5 = 0;
        var_s6 = 0;
        if (temp_v0->unk0 > 0) {
            temp_f22 = D_80030158;
            do {
                temp_v0_2 = func_8002E9AC((temp_v0->unk4 + var_s6)->unk1);
                if (temp_v0_2->unk10 != 0) {
                    var_s2 = 0;
                    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
                        do {
                            temp_f10 = character_change_array[playerIndex].look_at_eye_z;
                            temp_f2 = character_change_array[playerIndex].look_at_eye_x - temp_v0_2->unk0;
                            temp_f12 = character_change_array[playerIndex].look_at_eye_y - temp_v0_2->unk2;
                            temp_f8 = temp_f2 * temp_f2;
                            temp_f0 = temp_f10 - temp_v0_2->unk4;
                            var_t3 = 0;
                            if (temp_f22 < ((temp_f0 * temp_f0) + (temp_f8 + (temp_f12 * temp_f12)))) {
                                var_t3 = 1;
                            }
                            var_s2 |= var_t3;
                    }
                    var_s0 = 0;
                    var_s1 = temp_v0_2;
                    if (var_s2 != temp_v0_2->unk24) {
                        do {
                            temp_a0 = var_s1->unk1C;
                            if (temp_a0 != NULL) {
                                if (var_s2 != 0) {
                                    func_80678458(temp_a0);
                                } else {
                                    func_80678428(temp_a0);
                                }
                            }
                            var_s0 += 4;
                            var_s1 += 4;
                        } while (var_s0 != 8);
                        temp_v0_2->unk24 = var_s2;
                    }
                }
                var_s5 += 1;
                var_s6 += 2;
            } while (var_s5 < temp_v0->unk0);
        }
    }
}
*/
