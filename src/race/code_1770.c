#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

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

typedef struct {
    s32 unk0;
    f32 unk4;
} AAD_race_800274C0;

typedef struct {
    u8 pad0[0xC];
    Actor *unkC;
} RaceStruct0;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80026098;

extern SpriteData D_global_asm_8071FFA0; // TODO: Datatype
extern SpriteData D_global_asm_80720340; // TODO: Datatype

extern u16 D_global_asm_80750AC4;

extern s16 D_global_asm_80770628[];
extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];

void func_race_8002D338(Actor *arg0, RaceStruct0 *arg1);

s32 func_race_80025770(s32 arg0, s32 arg1) {
    s32 temp_v1 = arg1 + 1;
    if (arg0 != temp_v1) {
        return arg1 + 1;
    }
    return 0;
}

s32 func_race_8002578C(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return arg0 - 1;
    }
    return arg1 - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_1770/func_race_800257A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_1770/func_race_8002597C.s")

// Close, doable, regalloc, stack
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_1770/func_race_80025E9C.s")

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
    s8 unk26;
    s8 unk27;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s8 unk34;
    s8 unk35;
    s8 unk36;
    s8 unk37;
} Actor178_race_80025E9C_2;

typedef struct {
    Actor *unk0;
    RaceAdditionalActorData *unk4;
} Actor184_race_80025E9C;

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
    Actor *unk30;
    Actor *unk34;
} Actor17C_race_80025E9C;

void func_race_8002BC2C(Actor *arg0, s32 arg1, Actor *arg2, void *arg3);

/*
void func_race_80025E9C(Actor *arg0) {
    RaceAdditionalActorData *aaD;
    Actor178_race_80025E9C_2 *a178_2; // TODO: Shouldn't be on stack
    s32 pad2;
    s32 pad;
    Actor *playerCar;
    Actor *sp40; // sp40
    Actor *raceCamera; // sp3C
    Actor17C_race_80025E9C *a178;
    RaceAdditionalActorData *aaD_2;
    Actor184_race_80025E9C *a184;

    aaD = arg0->additional_actor_data;
    func_race_8002BBD0(arg0, 2);
    spawnActor(ACTOR_CAR_FACTORY_PLAYER, 0x95);
    playerCar = last_spawned_actor;
    aaD_2 = playerCar->additional_actor_data;
    func_race_8002BC2C(arg0, 1, playerCar, aaD_2);
    aaD_2->unk37 = 0;
    aaD_2->unk27 = 0;
    aaD_2->unk30 = arg0;
    aaD_2->unk36 = 1;
    aaD_2->unk28 = 0;
    a178 = playerCar->unk178;
    sp40 = func_global_asm_807271F4(1, 0, 0, 0, 0, 0, 0);
    a178->unk30 = sp40;
    a184 = sp40->unk184;
    a184->unk4 = aaD_2;
    a184->unk0 = playerCar;
    spawnActor(ACTOR_CAMERA_CARRACE, 0);
    raceCamera = last_spawned_actor;
    a178->unk34 = raceCamera;
    pad = 1;
    a178_2 = sp40->unk178;
    func_race_8002BC2C(arg0, 0, sp40, a178_2);
    a178_2->unk37 = 0;
    a178_2->unk27 = pad;
    a178_2->unk30 = arg0;
    a178_2->unk36 = 0;
    a178 = sp40->unk17C;
    a178->unk30 = playerCar;
    a178->unk34 = raceCamera;
    aaD_2 = raceCamera->RaaD;
    aaD_2->unk30 = arg0;
    a178_2 = raceCamera->unk178;
    a178_2->unk30 = playerCar;
    D_global_asm_80750AC4 = 0;
    aaD->unk25 = pad;
}
*/

void func_race_80025FDC(void) {
    func_race_8002597C();
    func_race_8002CFF0();
}

void func_race_80026004(RaceStruct1 *arg0, u8 arg1, f32 arg2) {
    arg0->unk10 = arg1;
    arg0->unk14 = arg2;
    playSound(0x1EB, 0x7FFF, 64.0f, 1.0f, 0, 0);
}

void func_race_80026050(RaceStruct6 *arg0, RaceStruct6 *arg1, s32 arg2) {
    if (arg2 != (arg0->unk2 + 1)) {
        arg0->unk2++;
    } else {
        arg0->unk2 = 0;
        if (arg1 != 0) {
            arg1->unk37++;
        }
    }
    if (arg1 != 0) {
        arg1->unk3A = arg0->unk2 + 1;
    }
}

void func_race_80026098(Struct80026098 *arg0, Struct80026098 *arg1) {
    s16 sp2E;
    f32 temp;
    f32 sp24;

    sp2E = (func_global_asm_80665E48(arg0->unk0, arg0->unk8, arg1->unk0, arg1->unk8) * 2048.0) / M_PIF;
    temp = sqrtf(((arg1->unk8 - arg0->unk8) * (arg1->unk8 - arg0->unk8)) + ((arg1->unk0 - arg0->unk0) * (arg1->unk0 - arg0->unk0)));
    sp24 = current_actor_pointer->unkB8 * 0.03 * temp;
    current_actor_pointer->x_position = arg1->unk0 + (sp24 * func_global_asm_80612794(sp2E));
    current_actor_pointer->z_position = arg1->unk8 + (sp24 * func_global_asm_80612790(sp2E));
    current_actor_pointer->y_position = (0.8 * (arg0->unk4 - current_actor_pointer->y_position)) + current_actor_pointer->y_position;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Struct800261E0_arg0;

void func_race_800261E0(Struct800261E0_arg0 *arg0) {
    s16 temp;
    s16 sp24;
    f32 sp20;
    f32 temp_f0;
    s16 temp_t2;

    temp_t2 = ((arg0->unk18 + arg0->unkC));
    sp24 = func_global_asm_806CC10C(0, arg0->unk1C);
    temp_t2 &= 0xFFF;
    sp20 = func_global_asm_80612790(temp_t2);
    temp_f0 = func_global_asm_80612794(temp_t2);
    current_actor_pointer->y_rotation = current_actor_pointer->unkEE + temp_t2;
    current_actor_pointer->y_rotation &= 0xFFF;
    current_actor_pointer->z_rotation = sp24 * sp20;
    current_actor_pointer->z_rotation = current_actor_pointer->z_rotation + arg0->unk20;
    current_actor_pointer->z_rotation &= 0xFFF;
    current_actor_pointer->x_rotation = sp24 * temp_f0;
    current_actor_pointer->x_rotation = current_actor_pointer->x_rotation + arg0->unk24;
    current_actor_pointer->x_rotation &= 0xFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/race/code_1770/func_race_80026354.s")

typedef struct {
    u8 unk0[0x29 - 0x0];
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    Actor *unk2C;
} Struct80026B20;

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
} A178_race_80026B20;

typedef struct {
    s32 unk0;
    s32 unk4;
    Actor *unk8;
    Actor *unkC;
} A17C_race_80026B20;

void func_race_80026B20(Struct80026B20 *arg0) {
    A178_race_80026B20 *a178_2;
    A178_race_80026B20 *a178;
    A17C_race_80026B20 *a17C;

    if (arg0->unk2C == NULL && arg0->unk2A != 0) {
        a178 = current_actor_pointer->unk178;
        arg0->unk2A--;
        spawnActor(ACTOR_MISSILE_CAR, 0x96);
        a178_2 = last_spawned_actor->unk178;
        a17C = last_spawned_actor->unk17C;
        a17C->unkC = current_actor_pointer;
        a17C->unk8 = func_race_8002D360(current_actor_pointer);
        arg0->unk2C = last_spawned_actor;
        last_spawned_actor->x_position = current_actor_pointer->x_position;
        last_spawned_actor->y_position = current_actor_pointer->y_position;
        last_spawned_actor->z_position = current_actor_pointer->z_position;
        last_spawned_actor->unkEE = current_actor_pointer->unkEE;
        last_spawned_actor->y_rotation = current_actor_pointer->y_rotation;
        last_spawned_actor->unkB8 = current_actor_pointer->unkB8;
        *a178_2 = *a178;
        playSound(0x18B, 0x7FFF, 64.0f, 1.0f, 0, 0);
    } else {
        playSound(0xE2, 0x7FFF, 64.0f, 1.0f, 0, 0);
    }
    arg0->unk29 = 0;
}

void func_race_80026CA8(void) {
    func_global_asm_80604CBC(current_actor_pointer, 0x12D, 0, 1, 0, 0xFF, 1.0f, 0);
    func_global_asm_80604CBC(current_actor_pointer, 0x12E, 0, 1, 1, 0xFF, 1.0f, 0);
}

void func_race_80026D2C(f32 arg0) {
    s16 temp;
    s32 pad;
    temp = D_global_asm_80770628[current_actor_pointer->unk6E[0]];
    D_global_asm_80770B68[temp] = (arg0 / 20.0) + 1.0;
    D_global_asm_80770BC0[temp] = 1.0f;
    temp = D_global_asm_80770628[current_actor_pointer->unk70];
    current_actor_pointer->unk74 = arg0 / 20.0;
    if (current_actor_pointer->unk74 > 1.0) {
        current_actor_pointer->unk74 = 1.0f;
    }
    if (current_actor_pointer->unk74 < 0.0) {
        current_actor_pointer->unk74 = 0.0f;
    }

    if (D_global_asm_80770BC0[temp] == 0.0f) {
        D_global_asm_80770B68[temp] = ((((u32)func_global_asm_806119A0() / 4294967295.0) * 0.05) + 0.975) * (0.2 + (arg0 / 15.0));
        D_global_asm_80770BC0[temp] = 3.0f;
    }
}

Gfx *func_race_80026EE4(Gfx *dl, Actor *arg1) {
    return func_race_8002CAC8(dl, arg1, arg1->RaaD);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/race/code_1770/func_race_80026F04.s")

s32 func_global_asm_806F4DC0(s32, f32, u8, f32, f32, f32, f32);
f32 func_race_8002D2C0(void *);
extern u8 D_global_asm_807FBD70;

typedef struct {
    u8 unk0[0x26 - 0x0];
    u8 unk26; // Used
    u8 unk27;
    u8 unk28; // Used
    u8 unk29; // Used
    u8 unk2A; // Used
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    Actor *unk30; // Used
    u8 unk34; // Used
    u8 unk35; // Used
} AAD_80026F04;

typedef struct {
    u8 unk0; // Used
    u8 unk1;
    s16 unk2; // Used
    u8 unk4[0x20 - 0x4];
    f32 unk20; // Used
    f32 unk24; // Used
    u8 unk28[0x39 - 0x28];
    u8 unk39; // Used
} A178_80026F04;

/*
void func_race_80026F04(void) {
    f32 temp_f0;
    A178_80026F04 *a178;
    f32 x;
    f32 y;
    f32 z;
    f32 var_f12;
    s16 var_s0;
    s32 i;
    u16 temp_a0;
    AAD_80026F04 *aaD;
    s32 temp;

    aaD = current_actor_pointer->additional_actor_data;
    a178 = current_actor_pointer->unk178;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        Struct807F5FD4_unk0 *temp7F5unk0 = &D_global_asm_807F5FD4->unk0;
        temp = (temp7F5unk0[a178->unk0].unk4_s32 - temp7F5unk0[a178->unk0].unk0_s32) / 12;
        aaD->unk2A = 3;
        current_actor_pointer->noclip_byte = 0x3C;
        a178->unk2 = func_race_8002578C(temp, 0);
        func_race_80026354(a178, aaD, 1);
        if ((gameIsInDKTVMode()) || (isFlagSet(0x12, FLAG_TYPE_TEMPORARY))) {
            setAction(0x4B, current_actor_pointer, aaD->unk28);
        } else {
            func_global_asm_806F397C(player_pointer, current_actor_pointer, 0, 0x4B);
        }
        func_global_asm_8066EA90(current_actor_pointer, 2);
        func_race_80026CA8();
    }
    if ((D_global_asm_807FBD70 == 5) && (a178->unk39 == 0)) {
        if (aaD->unk34 == 2) {
            func_global_asm_8072DB68(3);
        }
        a178->unk39 = 0x1E;
    }
    if (aaD->unk35 == 0) {
        if (aaD->unk34 == 1) {
            func_global_asm_806F8BC4(0xB, 1, 0);
            aaD->unk35++;
        } else if (aaD->unk34 == 5) {
            func_global_asm_806F8D58(0xB, 0);
            aaD->unk35++;
        }
    }
    if (aaD->unk34 == 1) {
        Actor *tempActor = aaD->unk30;
        RaceAdditionalActorData *tempRaaD = tempActor->RaaD;
        temp_a0 = tempRaaD->unk1C;
        if ((temp_a0 == 8) || (temp_a0 == 0x13)) {
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x187, 0xFF, 0x7F, 0, 0, 0.3f, 0);
        }
        func_race_80026D2C(aaD->unk26 * 1.5);
    } else if (aaD->unk34 < 5) {
        var_s0 = 0;
        if (aaD->unk26 != 0) {
            temp_f0 = func_race_8002D2C0(aaD);
            if (temp_f0 != 0.0f) {
                func_race_80026004(a178, 0x1E, (1.5f * temp_f0) + 1.5f);
            }
            aaD->unk26 = 0;
        }
        if (a178->unk39 != 0) {
            if (a178->unk39 > 10.0f) {
                var_s0 = (a178->unk39 - 10.0f) * 204.8f;
                a178->unk20 = func_global_asm_80612794(var_s0) * 300.0f;
                a178->unk24 = func_global_asm_80612794(var_s0 * 2) * 300.0f;
            } else {
                a178->unk20 = 0.0f;
                a178->unk24 = 0.0f;
            }
        }
        func_race_80026354(a178, aaD, 1);
        current_actor_pointer->y_position += 20.0f * func_global_asm_80612794(var_s0 * 0.5f);
        func_race_80026D2C(current_actor_pointer->unkB8);
    } else if (aaD->unk34 == 5) {
        current_actor_pointer->object_properties_bitfield &= ~4;
        current_actor_pointer->unkB8 = 0.0f;
        for (i = 0; i != 2; i++) {
            if (current_actor_pointer->unk6E[i] != -1) {
                func_global_asm_80605314(current_actor_pointer, i);
            }
        }
    }
    if (aaD->unk29 != 0) {
        func_race_80026B20(aaD);
    }
    if (aaD->unk34 < 5) {
        if (aaD->unk34 == 2) {
            var_f12 = 10.0f;
        } else {
            var_f12 = -200.0f;
        }
        x = current_actor_pointer->x_position;
        y = current_actor_pointer->y_position + var_f12;
        z = current_actor_pointer->z_position;
        func_global_asm_806F4D70(aaD->unk28, x, y, z, 12.0f);
        func_global_asm_806F4DC0(0, y, aaD->unk28, (x + current_actor_pointer->unk88) * 0.5, y, (z + current_actor_pointer->unk90) * 0.5, 12.0f);
    }
    if (current_actor_pointer->object_properties_bitfield & 4) {
        func_global_asm_8068ECF4(1, 0xC8);
        func_global_asm_8068ECF4(2, 0xC8);
    }
    renderActor(current_actor_pointer, 0);
    if ((aaD->unk34 > 0) && (aaD->unk34 < 5)) {
        addActorToTextOverlayRenderArray(func_race_80026EE4, current_actor_pointer, 3);
    }
}
*/

void func_race_800274C0(void) {
    AAD_race_800274C0 *sp4C;
    Actor178 *sp48;
    s32 temp;
    Actor17C *temp_s1;
    u8 temp2[3];
    u8 var_v1;

    var_v1 = FALSE;
    sp4C = current_actor_pointer->additional_actor_data;
    sp48 = current_actor_pointer->unk178;
    temp_s1 = current_actor_pointer->unk17C;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_s1->unk0_u16[0] = 0x78;
        current_actor_pointer->object_properties_bitfield |= 0x10;
        current_actor_pointer->noclip_byte = 0x3C;
        sp4C->unk4 = 5.0f;
    }
    if (D_global_asm_807FBB70.unk200 == 9 || D_global_asm_807FBB70.unk15 != 0 || D_global_asm_807FBB70.unk200 == 5) {
        func_global_asm_807149B8(1);
        drawSpriteAtPosition(&D_global_asm_80720340, 3.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xF6, 0xFF, 0x7F, 0x14, 0x32, 0.3f, 0);
        var_v1 = TRUE;
    }
    func_race_80026354(sp48, sp4C, 0);
    current_actor_pointer->y_position += 5.0f;
    if (temp_s1->unk0_u16[0] != 0) {
        func_global_asm_807149B8(1);
        drawSpriteAtPosition(&D_global_asm_8071FFA0, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
        temp_s1->unk0_u16[0]--;
        if (!(temp_s1->unk0_u16[0])) {
            var_v1 = TRUE;
        }
    }
    if (var_v1) {
        func_race_8002D338(current_actor_pointer, temp_s1);
    }
    renderActor(current_actor_pointer, 0);
}
