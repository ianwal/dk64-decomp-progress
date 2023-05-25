#include <ultra64.h>
#include "functions.h"

extern s32 D_8002FC5C[];
extern s32 D_8002FCAC[];

extern u16 D_80750AC4;

s32 func_8002E8EC(s32, s32, s32);
s32 func_8002E8EC(s32 arg0, s32 arg1, s32 arg2);
void func_80025E9C(Actor *);
void func_80025FDC();
void func_80029488();
void func_8002E9F8(s32 *checkpointFile);
void func_8002BCD4(Actor *);
void func_8002D064();
void func_8002D0FC();

void func_805FF544();

typedef struct {
    u8 pad0[0x10 - 0x0];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
} RaceStruct1;

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
} RaceStruct6;

extern f32 D_8002FE68;
extern s32 D_8071FFA0; // TODO: Datatype
extern s32 D_80720340; // TODO: Datatype
extern s32 D_80720120;
extern f32 D_8002FF84;
extern s16 D_80770628[];
extern f32 D_80770B68[];
extern f32 D_80770BC0[];

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

extern void func_8002CFF0();

f32 func_8000AC60(f32);
f32 func_80665E48(f32, f32, f32, f32);
extern f64 D_8002FDD8;
extern f64 D_8002FDE0;
extern f64 D_8002FDE8;

typedef struct RaceStruct15 {
    s16 unk0;
    u16 unk2;
} RaceStruct15;
s32 func_800276B0(s32 arg0, RaceStruct15 *arg1, RaceStruct15 *arg2) {
    s32 var_v0;
    s32 sign;
    s32 var_v1;

    var_v1 = arg2->unk2 - arg1->unk2;
    if (var_v1 > 0) {
        var_v0 = var_v1;
    } else {
        var_v0 = -var_v1;
    }
    if ((arg0 / 2) < var_v0) {
        if (var_v1 >= 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        var_v1 -= sign * arg0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027880.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80027880;

extern Struct80027880 *D_807F5FD4[];

/*
// TODO: Very close
void func_80027880(s32 arg0, u16 arg1, u16 arg2) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 temp;

    temp = func_80025770(arg0, arg1);
    
    dx = D_807F5FD4[arg1][arg2].unk0 - D_807F5FD4[arg1][temp].unk0;
    dy = D_807F5FD4[arg1][arg2].unk4 - D_807F5FD4[arg1][temp].unk4;
    dz = D_807F5FD4[arg1][arg2].unk8 - D_807F5FD4[arg1][temp].unk8;
    func_8000AC60((dx * dx) + (dy * dy) + (dz * dz));
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027920.s")

typedef struct RaceStruct3 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} RaceStruct3;

void func_80027AF8(RaceStruct3 *arg0, s8 arg1) {
    if (arg1 > 0) {
        arg0->unk1++;
    } else {
        arg0->unk1--;
    }
    arg0->unk8 = 0.0f;
}

s32 func_806119A0(void);

void func_80027B30(RaceStruct3 *arg0) {

    switch (arg0->unk0) {
        case 0:
            arg0->unk1++;
            break;
        case 1:
            if ((u8)func_806119A0() >= 0x80U) {
                arg0->unk1++;
            } else {
                arg0->unk1--;
            }
            break;
        case 2:
            arg0->unk1--;
            break;
    }
    arg0->unk8 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027BD0.s")

void func_80027C60(void) {
    s32 phi_s0;

    for (phi_s0 = 1; phi_s0 != 3; phi_s0++) {
        func_807149B8(1);
        func_80714C08(&D_80720120, 1.0f, current_actor_pointer, phi_s0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80027CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800280E8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800282D8.s")

void func_800283D4(f32 arg0) {
    s32 temp_a0;

    temp_a0 = D_80770628[current_actor_pointer->unk6E[0]];
    current_actor_pointer->unk74 = 1.0f;
    D_80770B68[temp_a0] = (arg0 * D_8002FF84) + 1.0;
    D_80770BC0[temp_a0] = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80028E20.s")

// TODO: Actor17C stuff
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80029054.s")

void func_800292B0(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8002CAC8(arg0, arg1, arg1->PaaD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800292D0.s")

// need this forward declaration
void initializeSealRace();
void sealRaceSetup() {
    initializeSealRace();
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_800294A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002978C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_80029F88.s")

s32 func_8002A080(s32 arg0, s32 arg1) {
    return D_8002FC5C[func_8002E8EC(arg0, arg1, 0xA)];
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002A0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/initializeCastleCarRace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002A7F8.s")

void func_8002AE6C(s32 arg0, Actor *arg1) {
    // TODO: Which aaD type are they actually expecting here?
    func_8068E474(func_8002CAC8(arg0, arg1, arg1->PaaD), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002AE9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B610.s")

s32 func_8002B6C8(s32 arg0, s32 arg1) {
    return D_8002FCAC[func_8002E8EC(arg0, arg1, 0xA)];
}

typedef struct RaceStruct7 {
    u8 pad0[0x35];
    u8 unk35;
} RaceStruct7;

void func_8002B6F4(RaceStruct7 *arg0, s32 arg1) {
    if (arg0->unk35 == 0) {
        // Castle: Tiny GB: Car Race
        if (!isFlagSet(0x145, FLAG_TYPE_PERMANENT)) {
            playCutscene(current_actor_pointer, 1, 1);
            func_80629174();
        } else {
            func_805FF544();
        }
        arg0->unk35++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002B964.s")

void func_80611690(void*);

void func_8002BBD0(Actor *arg0, s32 arg1) {
    RaceAdditionalActorData *sp1C;
    void *temp_v0;

    sp1C = arg0->RaaD;
    temp_v0 = malloc(arg1 * 8);
    sp1C->unk20 = temp_v0;
    func_80611690(temp_v0);
    sp1C->unk1E = arg1;
    sp1C->unk1C = -1;
    arg0->control_state = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002BC2C.s")

// aaD use
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002BCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002BCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002BDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002BEE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002C14C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002C2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002C63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002C76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002CAC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002CBEC.s")

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

void func_8002D0FC(void) {
    RaceAdditionalActorData2 *RaaD;

    func_80677FA8(ACTOR_UNKNOWN_306, 0); // Spawn actor 306
    RaaD = D_807FBB44->RaaD2;
    func_8002E2C8(D_807FBB44);
    RaaD->unk0 = 2;
    RaaD->unk24 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002D148.s")

/*
s8 func_806FDB8C(s32, s32, s32, f32, f32, f32);
s32 func_8070E750(s32, s32, s32, u8);

void func_8002D148(void *arg0, s32 arg1) {
    u8 temp_t6;
    u8 var_a3;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = arg0->unk4;
    temp_t6 = arg1 & 0xFF;
    if (temp_t6 != temp_v0->unk34) {
        temp_v0->unk34 = temp_t6;
        arg0->unk4->unk35 = 0;
        if (temp_t6 == 3) {
            temp_v0_2 = arg0->unk4;
            var_a3 = temp_v0_2->unk36;
            if (current_actor_pointer->RaaD->unk1E != (var_a3 + 1)) {
                if (temp_v0_2->unk45 != 0) {
                    goto block_4;
                }
            } else {
block_4:
                var_a3 = 3;
            }
            if (temp_v0_2->unk27 == 0) {
                arg0->unk4->unk46 = func_806FDB8C(1, func_8070E750(0x26, D_8002FCD4[var_a3], 1, var_a3), 2, 160.0f, 100.0f, 0.0f);
            }
        }
    }
}
*/

// RaaD->unk20 struct array use
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002D224.s")

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

void func_8002D338(Actor *arg0, RaceStruct0 *arg1) {
    Actor *temp = arg1->unkC;
    RaceAdditionalActorData *RaaD = temp->RaaD;
    RaaD->unk2C = 0;
    func_806782C0(arg0);
}

extern f32 D_800300EC;
extern f32 D_800300F0;

// RaaD->actor30?->Raad->stuff
// dx dy dz calculation
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002D360.s")

// RaaD->unk20-> struct array 0x8 big loop
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002D40C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002D524.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002D778.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002DDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002DE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002DF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002E1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002E2C8.s")

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
    temp_s0->unk14 = (temp_s0->unk3A * 0xBB8) - temp_s0->unk40;
    if (temp_s0->unk14 < temp_s0->unk18) {
        temp_s0->unk18 = temp_s0->unk18;
        return;
    }
    temp_s0->unk18 = temp_s0->unk14;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002E644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002E8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002E960.s")

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
} RaceStruct2_unkC;

typedef struct RaceStruct2 {
    s32 unk0;
    s32 unk4;
    u16 unk8;
    s16 unkA;
    RaceStruct2_unkC *unkC;
} RaceStruct2;
extern RaceStruct2 *D_8002FCF0;

void *func_8002E9AC(u8 arg0, RaceStruct2 *arg1) {
    arg1 = D_8002FCF0;
    if ((arg1 == 0) || (arg0 >= arg1->unk8)) {
        return 0;
    }
    return &arg1->unkC[arg0];
}

// arg0 is checkpoint file pointer
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002E9F8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002EDD4.s")

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

/*
// TODO: Very close, it's using too many s registers
void func_8002EDD4(Struct8002EDD4_arg0 *arg0) {
    f32 spD0[16];
    f32 sp90[16];
    s32 temp[5];
    f32 var_f22;
    u8 i;

    if (arg0->unk10 != 0) {
        if (arg0->unk18 == 2) {
            var_f22 = arg0->unk1A * 0.5f;
            for (i = 0; i < 2; i++) {
                func_8002ED04(arg0->unk14, arg0->unk10, i ^ 1);
                arg0->unk1C[i] = D_807FBB44;
                D_807FBB44->y_rotation = (arg0->unk6 + 0x800) & 0xFFF;
                if (i != 0) {
                    var_f22 *= -1.0f;
                }
                func_80008620(&spD0, D_807FBB44->y_rotation * 0.087890625f, 0.0f, 1.0f, 0.0f);
                func_80005D80(&sp90, arg0->unk0, arg0->unk2, arg0->unk4);
                func_800088B0(&spD0, &sp90, &spD0);
                func_80008810(&spD0, var_f22, 0.0f, 0.0f, &D_807FBB44->x_position, &D_807FBB44->y_position, &D_807FBB44->z_position);
            }
            return;
        }
        func_8002ED04(arg0->unk14, arg0->unk10, (arg0->unk18 == 1));
        arg0->unk1C[0] = D_807FBB44;
        D_807FBB44->y_rotation = (arg0->unk6 + 0x800) & 0xFFF;
        D_807FBB44->x_position = arg0->unk0;
        D_807FBB44->y_position = arg0->unk2;
        D_807FBB44->z_position = arg0->unk4;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F04C.s")

/*
// TODO: REGALLOC
f32 func_8002F04C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_f0;
    f32 temp_f16;
    f32 phi_f2;

    temp_f16 = arg6 * arg3;
    temp_f0 = arg7 * arg2;
    phi_f2 = 0.0f;
    if (temp_f16 != temp_f0) {
        phi_f2 = (((arg4 - arg0) * arg3) + (arg2 * (arg1 - arg5))) / (temp_f0 - temp_f16);
    }
    return phi_f2;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F280.s")

f32 func_80611BB4(f32, f32);
extern f32 D_80030150;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct8002F280_arg0;

/*
// TODO: Regalloc
u8 func_8002F280(Struct8002F280_arg0 *arg0) {
    f32 p1 = current_actor_pointer->x_position - arg0->unk0;
    f32 p2 = current_actor_pointer->z_position - arg0->unk4;
    return (func_806CC14C((s16)(func_80611BB4(p1, p2) * D_80030150) & 0xFFF, arg0->unk6) < 0x400);
}
*/

void func_8002F04C(f32, f32, f32, f32, f32, f32, f32, f32);
typedef struct RaceStruct10 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
} RaceStruct10;

void func_8002F304(RaceStruct10 *arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0->unkC;
    temp_f2 = arg0->unk8;
    func_8002F04C(  arg0->unk0, 
                    arg0->unk4, 
                    -temp_f0, 
                    temp_f2, 
                    arg1, 
                    arg2, 
                    temp_f2, 
                    temp_f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F420.s")

// TODO: Is this the same as RaceStruct6?
typedef struct RaceStruct13 {
    s32 unk0;
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

void func_8002F36C(s32, s32);

/*
// TODO: Regalloc, boo
void func_8002F420(RaceStruct13 *arg0, RaceStruct13 *arg1) {
    if (arg1->unk8) {
        if (arg0->unk3C == arg0->unk3A) {
            u8 temp2 = arg1->unk4[arg0->unk3C] & 0xFF;
            func_8002DCF0(func_8002E9AC(temp2, arg1), 0);
            func_8002F36C(arg0, arg1);
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F784.s")

f32 func_8002F90C(RaceStruct6 *arg0, RaceStruct6 *arg1, RaceStruct6 *arg2) {
    f32 temp = ((arg1->unk37 - 1) * arg0->unk0) + arg1->unk3A;
    f32 temp2 = arg2->unk24 * arg0->unk0;
    return temp / temp2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_36B0/func_8002F950.s")
