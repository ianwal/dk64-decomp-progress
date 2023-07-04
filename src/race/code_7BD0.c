#include <ultra64.h>
#include "functions.h"

void func_8002BBD0(Actor *arg0, s32 arg1) {
    RaceAdditionalActorData *sp1C;
    RaaD_unk20 *temp_v0;

    sp1C = arg0->RaaD;
    temp_v0 = malloc(arg1 * sizeof(RaaD_unk20));
    sp1C->unk20 = temp_v0;
    func_80611690(temp_v0);
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

u16 *func_8002E960(u8);

void func_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, Struct8002D148_unk4 *arg3) {
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
        temp_v0_2 = func_8002E960(RaaD->unk26);
        if (temp_v0_2 != NULL) {
            arg3->unk3C = *temp_v0_2 - 1;
            func_8002F36C(arg3, temp_v0_2);
        }
        arg3->unk48 = func_806C7C94(arg3->unk28);
    }
}

void func_8002BCB0(Actor *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    RaceAdditionalActorData *aaD;
    RaaD_unk20 *temp_t0;

    aaD = arg0->RaaD;
    temp_t0 = aaD->unk20;
    *arg2 = temp_t0[arg1].unk0;
    *arg3 = temp_t0[arg1].unk4;
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002BCD4.s")

extern f32 D_800300D0;
extern f32 D_800300D4;
extern f32 D_800300D8;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} AAD_8002BCD4;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80027880;

extern Struct80027880 *D_807F5FD4;

/*
void func_8002BCD4(Actor *arg0) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f14;
    f32 var_f2;
    Struct80027880 *temp_a2;
    Struct80027880 *var_v1;
    AAD_8002BCD4 *aaD;

    var_f12 = -1.0f;
    var_f14 = -1.0f; 
    var_f0 = D_800300D0;
    var_f2 = D_800300D0;
    aaD = arg0->additional_actor_data;
    var_v1 = &D_807F5FD4[0].unk0;
    temp_a2 = &D_807F5FD4[1].unk0;
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
    aaD->unk4 = D_800300D4 / (var_f12 - var_f0);
    aaD->unk8 = D_800300D8 / (var_f14 - var_f2);
}
*/

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002BDDC.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002BEE8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002C14C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002C2E8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002C63C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002C76C.s")

s32 func_8002C14C(s32, void *);
s32 func_8002C2E8(s32, void *);
s32 func_8002C63C(s32, void *);
s32 func_8002C76C(s32, void *);

s32 func_8002CAC8(s32 arg0, Actor *arg1, RaceAdditionalActorData *arg2) {
    RaceAdditionalActorData2 *sp24;
    PlayerAdditionalActorData *PaaD;

    sp24 = arg2->unk30->RaaD2;    
    if (arg2 == NULL || gameIsInDKTVMode()) {
        return arg0;
    }
    if (character_change_array[arg2->unk28].player_pointer == NULL) {
        return arg0;
    }
    PaaD = character_change_array[arg2->unk28].player_pointer->PaaD;
    if (arg1 != PaaD->vehicle_actor_pointer) {
        return arg0;
    }

    arg0 = func_8002C63C(arg0, arg2);
    if (sp24->unk0 & 8) {
        arg0 = func_8002C2E8(arg0, arg2);
    } else if (sp24->unk0 & 0x10) {
        arg0 = func_8002C14C(arg0, arg2);
    }
    if (sp24->unk0 & 6) {
        arg0 = func_8002C76C(arg0, arg2);
    }
        
    return arg0;
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002CBEC.s")

void func_8002CFF0(void) {
    TempAAD *temp_v0;
    Actor *temp_a0;

    func_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    temp_a0 = D_807FBB44;
    func_80025E9C(temp_a0);
    func_8002BCD4(temp_a0);
    temp_v0 = temp_a0->TaaD;
    temp_v0->unk0 = 0x17;
    temp_v0->unk14 = 0x46;
    temp_v0->unk16 = 0x47;
    temp_v0->unk18 = 0x48;
    temp_v0->unk1A = 0x49;
    temp_v0->unk24 = 2;
}

void castleCarRaceSetup() {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    initializeCastleCarRace(D_807FBB44);
    RaaD->unk0 = 0xE;
    RaaD->unk24 = 2;
}

void func_8002D0B0() {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    func_800292D0(D_807FBB44);
    RaaD->unk0 = 0xE;
    RaaD->unk24 = 2;
}

void func_8002E2C8(Actor *arg0);

void func_8002D0FC(void) {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    func_8002E2C8(D_807FBB44);
    RaaD->unk0 = 2;
    RaaD->unk24 = 1;
}

s8 func_806FDB8C(s32, s32, s32, f32, f32, f32);
s32 func_8070E750(s32, s32, s32);

extern s32 D_8002FCD4[];

void func_8002D148(Struct8002D148 *arg0, u8 arg1) {
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
                arg0->unk4->unk46 = func_806FDB8C(1, func_8070E750(0x26, D_8002FCD4[var_a3], 1), 2, 160.0f, 100.0f, 0.0f);
            }
        }
    }
}

void func_8002D224(u8 arg0) {
    RaaD_unk20 *var_s0;
    s32 i;
    RaceAdditionalActorData *RaaD;

    RaaD = current_actor_pointer->RaaD;
    var_s0 = RaaD->unk20;
    current_actor_pointer->control_state = arg0;
    for (i = 0; i < RaaD->unk1E; i++) {
        if (var_s0[i].unk0 != 0) {
            func_8002D148(&var_s0[i], arg0);
        }
    }
}

extern f32 D_800300E8;

typedef struct RaceStruct12 {
    u8 pad0[0x26];
    u8 unk26;
    u8 unk27;
    u8 unk28;
} RaceStruct12;

f32 func_8002D2C0(RaceStruct12 *arg0) {
    if ((arg0->unk26 >= 0xB) && (arg0->unk26 < 0xF) && 
        (D_807FD610[arg0->unk28].unk2A & 0x2000)) {
            f32 temp = (arg0->unk26 - 0xA);
            return temp * D_800300E8;
    }
    return 0.0f;
}

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

void func_8002D338(Actor *arg0, RaceStruct0 *arg1) {
    Actor *temp = arg1->unkC;
    RaceAdditionalActorData *RaaD = temp->RaaD;
    RaaD->unk2C = 0;
    func_806782C0(arg0);
}

extern f32 D_800300EC;
extern f32 D_800300F0;

// Appears to find the closest actor to whatever is passed in
Actor *func_8002D360(Actor *arg0) {
    f32 distance;
    f32 closestDistance;
    s32 i;
    RaaD_unk20 *var_a1;
    RaceAdditionalActorData *RaaD2;
    RaceAdditionalActorData *RaaD;
    Actor *examinedActor;
    Actor *temp;
    Actor *closestActor;

    closestDistance = D_800300EC;
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

void func_8002D40C(void) {
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

void func_8002D4A0(void) {
    s32 song;
    f32 phi_f0;

    phi_f0 = 1.0f;
    switch (current_map) {
        case MAP_AZTEC_BEETLE_RACE:
            song = 0x13;
            phi_f0 = D_800300F0;
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
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002D524.s")

void func_8002D72C(Actor *arg0) {
    if (arg0 && arg0->control_state == 0) {
        RaceAdditionalActorData *RaaD = arg0->RaaD;
        RaaD->unk1C = 2;
    }
}

void func_8002D754(Actor *arg0) {
    if (arg0 && arg0->control_state == 0) {
        RaceAdditionalActorData* RaaD = arg0->RaaD;
        RaaD->unk1C = 0;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002D778.s")

typedef struct RaceStruct3 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} RaceStruct3;

void func_8002DA68(RaceStruct3 *arg0) {
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
    temp_f2 = (((func_80612794(arg0->unk2) + 1.0f) * 1.5) + 1.0) * arg0->unk4;
    current_actor_pointer->animation_state->scale_x = \
    current_actor_pointer->animation_state->scale_y = \
    current_actor_pointer->animation_state->scale_z = temp_f2;
}

void func_8002DB90(void) {
    if (current_actor_pointer->control_state != 0) {
        if ((current_actor_pointer->control_state == 1) && (func_80688540(current_actor_pointer, 0) == 0)) {
            func_80688370(current_actor_pointer, 0, 1.0f);
            func_8068842C(current_actor_pointer, 0, -1);
        }
    } else if (func_80688540(current_actor_pointer, 0)) {
        func_80688460(current_actor_pointer, 0, 1);
    }
}

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
} AAD_8002DC24;

void func_8002DC24(void) {
    AAD_8002DC24 *RaaD = current_actor_pointer->RaaD;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        RaaD->unk4 = current_actor_pointer->animation_state->scale_y;
    }
    switch (RaaD->unk0) {
        case 2:
            func_8002DB90();
            break;
        case 1:
            func_8002DB90();
            func_80665564(current_actor_pointer, 0);
            current_actor_pointer->y_position = current_actor_pointer->unkAC;
            current_actor_pointer->unk6A |= 4;
            current_actor_pointer->unk6C |= 4;
            break;
        default:
            func_8002DA68(RaaD);
            break;
    }
    func_806319C4(current_actor_pointer, 0);
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

void func_8002DCF0(RaceStruct14 *arg0, s32 arg1);

void func_8002DCF0(RaceStruct14 *arg0, s32 arg1) {
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

f32 func_8002DD70(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return ((arg4 - arg2) * ((arg0 - arg1) / (arg3 - arg1))) + arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002DDA0.s")

typedef struct {
    u8 unk0[0xF - 0x0];
    u8 unkF;
    u8 unk10;
} Struct8002E1C8_arg0;

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
} Struct8002E1C8_arg2;

f32 func_8002DDA0(f32 arg0, Struct8002E1C8_arg2 *arg1);

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002DE78.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002DF38.s")

f32 func_8002E1C8(Struct8002E1C8_arg0 *arg0, f32 arg1, Struct8002E1C8_arg2 *arg2, s32 arg3) {
    f32 var_f2;

    switch (arg0->unkF) {
        default:
            var_f2 = 0.0f;
            break;
        case 0:
            var_f2 = func_8002DDA0(arg1, arg2);
            break;
        case 1:
            var_f2 = func_8002DDA0(arg1, arg2);
            if (arg0->unk10 != 0) {
                if (arg2->unk20 < arg1) {
                    func_8002DE78(arg0, 5, arg2, arg3);
                }
            }
            break;
        case 5:
            var_f2 = func_8002DDA0(arg1, arg2);
            if (arg1 < arg2->unk8) {
                func_8002DE78(arg0, 1, arg2, arg3);
            }
            break;
    }
    return var_f2;
}

typedef struct {
    u8 unk0[0x25 - 0x0];
    u8 unk25;
    u8 unk26;
} AAD_8002E2C8;

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
    u8 unk28;
    u8 unk29[0x30 - 0x29];
    s32 unk30;
    u8 unk34[0x36 - 0x34];
    u8 unk36;
} AAD_8002E2C8_Actor315;

typedef struct {
    u8 unk0[0x27 - 0x0];
    u8 unk27;
} A178_8002E2C8;

void func_8002E2C8(Actor *arg0) {
    AAD_8002E2C8 *sp5C;
    AAD_8002E2C8_Actor315 *sp58;
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
    func_8002BBD0(arg0, var_s4);
    if (cc_number_of_players == 1) {
        sp54 = func_807271F4(1, 0, 0, 0, 0, 0, 0);
        sp58 = sp54->unk178;
        sp58->unk27 = 1;
        func_8002BC2C(arg0, 0, sp54, sp58);
        var_s1 = 1;
        temp_a2 = sp54->unk17C;
        func_8002BCB0(arg0, 0, temp_a2, &temp_a2->unk4);
        sp5C->unk25 = 1;
    } else {
        sp5C->unk25 = 0;
    }
    for (i = 0; i < cc_number_of_players; i++) {
        func_80677FA8(ACTOR_UNKNOWN_315, 0);
        sp54 = D_807FBB44;
        sp58 = sp54->additional_actor_data;
        sp58->unk27 = 0;
        func_8002BC2C(arg0, var_s1, sp54, sp58);
        var_s1 += 1;
        sp58->unk28 = i;
    }
    for (i = 0; i < var_s4; i++) {
        func_8002BCB0(arg0, i, &sp54, &sp58);
        sp58->unk36 = i;
        sp58->unk30 = arg0;
    }
    sp5C->unk26 = 0;
}

void func_8002E464(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8002CAC8(arg0, arg1, arg1->PaaD);
}

extern void func_8002E464(); // TODO: Signature

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
} AAD_8002E484;

void func_8002E484(void) {
    Actor *var_a3;
    AAD_8002E484 *temp_s0;

    temp_s0 = current_actor_pointer->additional_actor_data;
    var_a3 = character_change_array[temp_s0->unk28].player_pointer;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806EB0C0(0x4E, current_actor_pointer, temp_s0->unk28);
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
    }
    if (temp_s0->unk34 == 2) {
        if (current_actor_pointer->control_state == 0) {
            func_806EB0C0(0x57, NULL, temp_s0->unk28);
            current_actor_pointer->control_state += 1;
        }
    }
    current_actor_pointer->x_position = var_a3->x_position;
    current_actor_pointer->y_position = var_a3->y_position;
    current_actor_pointer->z_position = var_a3->z_position;
    if (temp_s0->unk34 == 2) {
        func_8002F490(temp_s0);
    }
    if (temp_s0->unk34 > 0) {
        if (temp_s0->unk34 < 5) {
            func_8068C350(&func_8002E464, current_actor_pointer, 3);
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

// Doable, kinda annoying though
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_7BD0/func_8002E644.s")

typedef struct {
    u8 unk0[0x36 - 0];
    u8 unk36;
} Struct8002E8EC_arg0;

typedef struct {
    u8 unk0[0x45 - 0];
    u8 unk45;
} Struct8002E8EC_arg1;

s32 func_8002E8EC(Struct8002E8EC_arg0 *arg0, Struct8002E8EC_arg1 *arg1, s32 arg2) {
    s32 var_v1;

    if (arg1->unk45 != 0) {
        var_v1 = 0;
    } else {
        if (arg0->unk36 != 0) {
            if (func_806F8AD4(0xB, 0) >= arg2) {
                var_v1 = 1;
            } else {
                var_v1 = 3;
            }
        } else {
            var_v1 = 2;
        }
    }
    return var_v1;
}
