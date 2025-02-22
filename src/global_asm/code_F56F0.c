#include <ultra64.h>
#include "functions.h"

// TODO: Is this just a float array? Matrix? idk
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} GlobalASMStruct74;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct806F2EDC;

typedef struct {
    u8 unk0[0x8E - 0x0];
    u8 unk8E;
    u8 unk8F;
    u8 unk90;
    u8 unk91;
} Struct806F2FC0;

typedef struct {
    s16 unk0; // X
    s16 unk2; // Y
    s16 unk4; // Z
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
} Struct806F37BC;

typedef struct {
    s16 unk0; // Used, X Position
    s16 unk2; // Used, Y Position
    s16 unk4; // Used, Z Position
    s16 unk6;
    u8 unk8;
    u8 unk9; // Used
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
} Struct80753E90_unk4;

typedef struct {
    s16 unk0;
    Struct80753E90_unk4 *unk4;
} Struct80753E90_2;

// TODO: Same as GlobalASMStruct75?
typedef struct {
    s16 unk0;
    s16 unk2;
    Struct80753E90_2 *unk4;
} Struct80753E90;

typedef struct {
    s16 unk0;
    s16 unk2;
    void *unk4;
} GlobalASMStruct75;

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s16 unk4;
} Struct80753EA0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14; // Used
    u8 unk15;
    u8 unk16;
    u8 unk17;
    s32 unk18; // Used
} Struct806F1B58;

typedef struct AutowalkFile {
    s16 count;
    s16 data[];
} AutowalkFile;

typedef struct AutowalkRDRAM AutowalkRDRAM;

struct AutowalkRDRAM {
    s16 count;
    AutowalkRDRAM *items;
};

extern AutowalkRDRAM *D_global_asm_80753E90;
extern u8 D_global_asm_8076A0B1;
extern void *D_global_asm_807FD70C;
extern Struct80753E90_2 *D_global_asm_807FD708;
extern Actor *D_global_asm_807FD710;
extern s16 D_global_asm_807FD714;
extern s16 D_global_asm_807FD718;
extern Actor *D_global_asm_807FD71C;

extern u8 D_global_asm_807FD716; // bitfield, idk what it's for

extern s32 D_global_asm_807FBB68;

extern Struct80753EA0 D_global_asm_80753EA0[];

void func_global_asm_806F4528(AutowalkFile *);
void func_global_asm_806F386C(u8, Actor*, Actor*, s16, u8);

void func_global_asm_806F09F0(Actor *arg0, u16 arg1) {
    switch (arg1) {
        case 0x3:
        case 0xC5:
            func_global_asm_8068A784(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            func_global_asm_8068A784(arg0, 2);
            return;
        case 0x6:
        case 0xC8:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            return;
        case 0x4:
        case 0xC6:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            return;
        case 0x5:
        case 0xC7:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            return;
        case 0x2:
        case 0xC4:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            return;
        case 0x7:
            func_global_asm_8068A764(arg0, 1);
            func_global_asm_8068A784(arg0, 0);
            return;
    }
}

void func_global_asm_806F0B34(Actor *arg0) {
    switch (current_character_index[cc_player_index]) {
        case 0:
            playSoundAtActorPosition(arg0, 0x17C, 0xFF, 0x7F, 0x19);
            return;
        case 1:
            playSoundAtActorPosition(arg0, 0x17C, 0xC8, 0xA0, 5);
            return;
        case 2:
            playSoundAtActorPosition(arg0, 0x17C, 0xFF, 0x7F, 5);
            return;
        case 3:
            playSoundAtActorPosition(arg0, 0x185, 0xFF, 0x7F, 0x19);
            return;
        default:
            playSoundAtActorPosition(arg0, 0x18F, 0xFF, 0x7F, 0x19);
            return;
    }
}

// TODO: Why is s16 required in the signature here? u16 breaks the switch case codegen
s16 func_global_asm_80613448(Actor *arg0);

void func_global_asm_806F0C18(Actor *arg0) {
    s32 temp_v0 = func_global_asm_80613448(arg0);
    switch (temp_v0) {
        case 0x1:
        case 0x2:
        case 0x3:
            func_global_asm_8068A784(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            break;
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            break;
        case 0xDB:
            func_global_asm_8068A764(arg0, 1);
            func_global_asm_8068A784(arg0, 0);
            break;
        case 0x6:
        case 0x7:
        case 0x8:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            break;
        case 0x9:
        case 0xA:
        case 0xB:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            break;
        case 0x4:
        case 0x5:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A784(arg0, 1);
            break;
    }
    if (arg0->interactable & 1) {
        PlayerAdditionalActorData *aaD;
        aaD = arg0->PaaD;
        if (aaD->unk8C != 0) {
            func_global_asm_806F0B34(arg0);
            aaD->unk8C = 0;
        }
    }
}

void func_global_asm_806F0D68(Actor *arg0) {
    s32 temp_v0;
    PlayerAdditionalActorData *PaaD;

    temp_v0 = func_global_asm_80613448(arg0);
    switch (temp_v0) {
        case 0x1:
        case 0x2:
            func_global_asm_8068A764(arg0, 0);
            func_global_asm_8068A764(arg0, 1);
            break;
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
            func_global_asm_8068A784(arg0, 0);
            func_global_asm_8068A764(arg0, 1);
            break;
        case 0xDB:
            func_global_asm_8068A784(arg0, 1);
            func_global_asm_8068A764(arg0, 0);
            break;
        case 0x6:
        case 0x7:
            func_global_asm_8068A784(arg0, 0);
            func_global_asm_8068A764(arg0, 1);
            break;
        case 0x9:
        case 0xA:
            func_global_asm_8068A784(arg0, 0);
            func_global_asm_8068A764(arg0, 1);
            break;
        case 0x4:
            func_global_asm_8068A784(arg0, 0);
            func_global_asm_8068A764(arg0, 1);
            break;
    }
    if (arg0->interactable & 1) {
        PaaD = arg0->PaaD;
        if (PaaD->unk8C == 0) {
            switch (current_character_index[cc_player_index]) {
                case 0:
                    playSoundAtActorPosition(arg0, 0x186, 0xFF, 0x64, 0x19);
                    playSoundAtActorPosition(arg0, 0x17C, 0xFF, 0x64, 0x19);
                    break;
                case 1:
                    playSoundAtActorPosition(arg0, 0x17C, 0xC8, 0xBE, 5);
                    break;
                case 2:
                    playSoundAtActorPosition(arg0, 0x186, 0xFF, 0x7F, 0x19);
                    playSoundAtActorPosition(arg0, 0x17C, 0xFF, 0xA0, 5);
                    break;
                case 3:
                    playSoundAtActorPosition(arg0, 0x185, 0xFF, 0x7F, 0x19);
                    break;
                default:
                    playSoundAtActorPosition(arg0, 0x18E, 0xFF, 0x7F, 0x19);
                    break;
            }
            PaaD->unk8C = 1;
        }
        if (func_global_asm_80714608(0) != 0) {
            D_global_asm_807FC950[PaaD->unk1A4].character_progress[func_global_asm_806C8DE0(PaaD->unk1A4)].weapon = 1;
            func_global_asm_806F5A48(PaaD->unk1A4, 0, arg0, 0x8F);
        }
    }
}

void func_global_asm_806F1048(Actor *actor) {
    s32 actorBehaviourIndex = actor->unk58;
    PlayerAdditionalActorData *PaaD = actor->PaaD;

    switch (actorBehaviourIndex) {
        case ACTOR_LANKY:
        case ACTOR_CUTSCENE_LANKY:
            PaaD->unk1F0 &= ~0x100;
        case ACTOR_DIDDY:
        case ACTOR_TINY:
        case ACTOR_CHUNKY:
        case ACTOR_CUTSCENE_DIDDY:
        case ACTOR_CUTSCENE_TINY:
        case ACTOR_CUTSCENE_CHUNKY:
            if (!(PaaD->unk1F0 & 0x40)) {
                func_global_asm_80613214(actor);
            }
            break;
    }
    func_global_asm_806C8D20(current_actor_pointer);
}

void func_global_asm_806F10E8(Actor *actor) {
    switch ((u32)actor->unk58) {
        case ACTOR_DK:
        case ACTOR_CUTSCENE_DK:
            func_global_asm_806F0C18(actor);
            spawnActor(ACTOR_BONGOS, 0xA6);
            moveAndScaleActorToAnother(last_spawned_actor, actor, actor->animation_state->scale[1] * 1.25);
            last_spawned_actor->x_rotation = actor->x_rotation;
            last_spawned_actor->z_rotation = actor->z_rotation;
            last_spawned_actor->object_properties_bitfield |= 0x40000000;
            return;
        case ACTOR_DIDDY:
        case ACTOR_CUTSCENE_DIDDY:
            func_global_asm_806F0C18(actor);
            func_global_asm_80613194(actor, 2);
            return;
        case ACTOR_LANKY:
        case ACTOR_CUTSCENE_LANKY:
            func_global_asm_806F0C18(actor);
            func_global_asm_80613194(actor, 7);
            return;
        case ACTOR_TINY:
        case ACTOR_CUTSCENE_TINY:
            func_global_asm_806F0C18(actor);
            func_global_asm_80613194(actor, 0xA);
            return;
        case ACTOR_CHUNKY:
        case ACTOR_CUTSCENE_CHUNKY:
            func_global_asm_806F0C18(actor);
            func_global_asm_80613194(actor, 0xD);
            return;
    }
}

void func_global_asm_806F1250(Actor *arg0) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    if (arg0->unk58 == ACTOR_CHUNKY) {
        func_global_asm_80613194(arg0, 0x10);
        playSoundAtPosition(arg0->x_position, arg0->y_position, arg0->z_position, 0x2E2, 0xFF, 0xA0, 0, 0x32, 0.0f, 0);
        if ((D_global_asm_807FBB68 & 2) == 0) {
            // Gorilla Gone
            playSong(MUSIC_108_GORILLA_GONE, 1.0f);
        }
    }
    PaaD->unk1F0 |= 0x40;
}

void func_global_asm_806F12FC(Actor *actor) {
    PlayerAdditionalActorData *PaaD = actor->PaaD;
    if (actor->unk58 == ACTOR_CHUNKY) {
        func_global_asm_80613214(actor);
        func_global_asm_80602B60(0x6C, 0);
    }
    PaaD->unk1F0 &= ~0x40;
}

void func_global_asm_806F1350(s32 arg0) {
    func_global_asm_806E225C(0, 1);
}

void func_global_asm_806F1378(s32 arg0) {

}

void func_global_asm_806F1380(Actor *arg0) {
    f32 sp1C;

    getAnimationArg32(&sp1C);
    arg0->animation_state->unk88 = arg0->unkB8 - sp1C;
}

void func_global_asm_806F13C8(Actor *arg0) {
    u8 sp27;

    getAnimationArg8(&sp27);
    arg0->animation_state->unk88 = func_global_asm_806CD9A0(arg0, arg0->unkB8, arg0->unkB8, extra_player_info_pointer->unk4C, D_global_asm_807FD584) - sp27;
}

void func_global_asm_806F142C(Actor *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    func_global_asm_806CFF9C(arg0);
    temp_f0 = current_actor_pointer->unkB8;
    temp_f2 = temp_f0 / 2;
    current_actor_pointer->unkB8 = (D_global_asm_807FD610[cc_player_index].unk8 * (temp_f0 - temp_f2)) + temp_f2;
}

void func_global_asm_806F149C(Actor *arg0) {
    func_global_asm_806D0150(arg0);
}

void func_global_asm_806F14BC(Actor *arg0) {
    f32 sp54;
    u8 sp53;
    f32 var_f0;
    f32 var_f12;
    f32 temp_f16;
    s32 temp_v0;

    getAnimationArg32(&sp54);
    getAnimationArg8(&sp53);
    temp_f16 = arg0->animation_state->unk0->unk4;
    arg0->animation_state->unk88 = 0;
    if ((arg0->unk6A & 2) && (((arg0->unkAC - arg0->floor) > 12.0f))) {
        var_f0 = arg0->y_position - MAX(arg0->floor, arg0->unkAC);
        if (var_f0 < 0.0f) {
            var_f0 = 0.0f;
        }
    } else {
        var_f0 = arg0->distance_from_floor;
    }
    temp_v0 = func_global_asm_806F1668(var_f0 * 40.0f, arg0->y_velocity, arg0->terminal_velocity, arg0->y_acceleration);
    if (temp_v0 == 0) {
        arg0->animation_state->unk88 = 1;
        return;
    }
    var_f12 = (sp53 - temp_f16) / temp_v0;
    if (var_f12 < 0.0f) {
        var_f12 = 0.01f;
    }
    var_f12 /= MAX(0.01, arg0->animation_state->unk0->unk24);
    if (sp54 < var_f12) {
        var_f12 = sp54;
    }
    func_global_asm_80614D00(arg0, var_f12, 0.0f);
}

s32 func_global_asm_806F1668(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0, temp_f2, phi_f12;

    if ((arg0 < 0.0f) || (arg2 > 0.0f) || (arg3 >= 0.0f)) {
        return 0;
    }
    temp_f0 = (arg2 - arg1);
    temp_f0 /= arg3;
    temp_f2 = arg0;
    temp_f2 += (((arg1 + arg2) / 2) * temp_f0);
    if (temp_f2 > 0.0f) {
        phi_f12 = temp_f0 - (temp_f2 / arg2);
    } else {
        phi_f12 = (-sqrtf((arg1 * arg1) - (2 * arg3 * arg0)) - arg1) / arg3;
    }
    return phi_f12 + 0.5;
}

extern u16 D_global_asm_80752F20[];
extern u16 D_global_asm_80752F30[];
extern u16 D_global_asm_80752F38[];
extern u16 D_global_asm_80752F40[];

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    u16 unk4;
    u16 unk6;
} Struct806F1858;

void func_global_asm_806F1768(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    s32 temp_v1;
    u16 temp_v0;

    temp_v1 = extra_player_info_pointer->unk8E - 20;
    if (temp_v1 < 0) {
        return;
    }
    if (temp_v1 > 6U) {
        return;
    }
    temp_v0 = D_global_asm_80752F20[(u32)(extra_player_info_pointer->unk8E - 20)];
    arg1[*arg2].unk0 = 0x7F;
    if (extra_player_info_pointer->unk91) {
        arg1[*arg2].unk1 = 9;
    } else {
        arg1[*arg2].unk1 = 8;
    }
    arg1[*arg2].unk2 = 0;
    if (extra_player_info_pointer->unk91) {
        arg1[*arg2].unk4 = temp_v0;
    } else {
        arg1[*arg2].unk4 = -temp_v0;
    }
    arg1[*arg2].unk6 = 0;
    *arg2 += 1;
}

void func_global_asm_806F1858(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    s32 temp_v1;
    s32 temp;

    temp_v1 = extra_player_info_pointer->unk8E - 0x14;
    if ((temp_v1 >= 0) && (temp_v1 < 4U)) {
        temp = D_global_asm_80752F30[(u32)(extra_player_info_pointer->unk8E - 0x14)];
        arg1[*arg2].unk0 = 0x7F;
        arg1[*arg2].unk1 = 4;
        arg1[*arg2].unk2 = 0;
        arg1[*arg2].unk4 = temp;
        arg1[*arg2].unk6 = 0;
        *arg2 += 1;
    }
}

void func_global_asm_806F18F4(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    s32 temp_v1;
    s32 temp;

    temp_v1 = extra_player_info_pointer->unk8E - 0x16;
    if ((temp_v1 >= 0) && (temp_v1 < 4U)) {
        temp = D_global_asm_80752F38[(u32)(extra_player_info_pointer->unk8E - 0x16)];
        arg1[*arg2].unk0 = 0x7F;
        arg1[*arg2].unk1 = 1;
        arg1[*arg2].unk2 = 0;
        arg1[*arg2].unk4 = temp;
        arg1[*arg2].unk6 = 0;
        *arg2 += 1;
    }
}

void func_global_asm_806F1990(s32 arg0, Struct806F1858 *arg1, s32 *arg2) {
    u16 temp_v0;

    temp_v0 = D_global_asm_80752F40[extra_player_info_pointer->unk8E];
    arg1[*arg2].unk0 = 0x7F;
    arg1[*arg2].unk1 = 1;
    arg1[*arg2].unk2 = temp_v0;
    arg1[*arg2].unk4 = temp_v0;
    arg1[*arg2].unk6 = 0;
    *arg2 += 1;
}

void func_global_asm_806F1A18(f32 arg0, f32 arg1, GlobalASMStruct74 *arg2, f32 *arg3) {
    s32 temp;
    f32 sp20;

    sp20 = func_global_asm_80612D10(arg2->unk4);
    arg2->unk8 += (arg0 * func_global_asm_80612D10(*arg3) * sp20);
    arg2->unk8 -= (arg1 * func_global_asm_80612D1C(arg2->unk4));
    arg2->unk8 *= 0.93;
    arg2->unk4 += arg2->unk8;
    *arg3 += arg2->unk4 + arg2->unk0;
}

f32 func_global_asm_806F1AE0(Actor *arg0, GlobalASMStruct74 *arg1, f32 arg2) {
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = func_global_asm_80612790(arg0->y_rotation - arg0->unkEE) * (arg0->unkB8 * 0.007692307699f);
    temp_f12 = temp_f2 - arg1->unkC;
    arg1->unkC = temp_f2;
    return (temp_f12 + temp_f2) * arg2;
}

int func_global_asm_806F1B58(Actor *arg0, Struct806F1B58 *arg1, s32 arg2) {
    return (arg0->object_properties_bitfield & 0x100)
        && arg1->unk14 == 0
        && arg2 == arg1->unk18;
}

f32 func_global_asm_806F1B90(f32 *arg0, f32 arg1) {
    f32 phi_f2;

    phi_f2 = arg1 - *arg0;
    *arg0 = arg1;
    if (M_PIF < phi_f2) {
        phi_f2 = MATH_2PI_F - phi_f2;
    } else if (phi_f2 < -M_PIF) {
        phi_f2 = -(MATH_2PI_F + phi_f2);
    }
    phi_f2 *= 0.1591549367f;
    return phi_f2;
}

typedef struct KongTagBarrelAAD178_sub1C {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
} KongTagBarrelAAD178_sub1C;

typedef struct KongTagBarrelAAD178 {
    f32 unk0;
    f32 unk4;
    u8 pad8[0x10 - 0x8];
    f32 unk10;
    u8 unk14;
    u8 pad15[0x18 - 0x15];
    s32 unk18;
    KongTagBarrelAAD178_sub1C unk1C[];
} KongTagBarrelAAD178;

void func_global_asm_806F1C04(Actor *arg0, AnimationStateUnk1C *arg1, s32 *arg2) {
    s32 pad[2];
    f32 temp_f0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 var_f24;
    f32 var_f26;
    s32 sp90;
    KongTagBarrelAAD178 *temp_s0;
    s32 var_s3;
    KongTagBarrelAAD178_sub1C *var_s1;
    f32 sp80;
    f32 sp7C;
    s32 i;
    s32 var_s4;
    s8 var_fp;

    temp_s0 = arg0->unk178;
    var_fp = -0x80;
    var_f24 = 0.0f;
    var_f26 = 0.0f;
    var_s1 = &temp_s0->unk1C;
    sp90 = func_global_asm_806F1B58(arg0, temp_s0, 2);
    sp80 = 0.0f;
    sp7C = 0.0f;
    var_s4 = *arg2;
    var_s3 = 0x14;
    getBonePosition(arg0, 0xD, &spA4, &spA8, &spAC);
    getBonePosition(arg0, 0xE, &spB0, &spB4, &spB8);
    temp_f0 = func_global_asm_80611BB4(spAC - spB8, spA4 - spB0);
    if (sp90 == 0) {
        temp_s0->unk0 = temp_f0;
        temp_s0->unk4 = spA8;
        if ((temp_s0->unk14 != 0) && (arg0->object_properties_bitfield & 0x100) && (temp_s0->unk18 == 2)) {
            temp_s0->unk14--;
        }
    } else {
        temp_f0_2 = func_global_asm_806F1B90(temp_s0, temp_f0);
        temp_s0->unk10 += ((-128.0f - temp_s0->unk10) * 0.3);
        var_fp = temp_s0->unk10;
        var_f26 = 0.4f * temp_f0_2;
        var_f24 = func_global_asm_806F1AE0(arg0, temp_s0, 0.02f);
    }
    for (i = 0; i < 4; i++) {
        if (sp90) {
            func_global_asm_806F1A18(var_f24, 0.06f, var_s1, &sp80);
            func_global_asm_806F1A18(var_f26, 0.06f, &var_s1->unkC, &sp7C);
        }
        arg1[var_s4].unk0 = var_fp;
        arg1[var_s4].unk1 = var_s3;
        arg1[var_s4].unk2 = (var_s1->unk4 + var_s1->unk0) * 10430.218905280077;
        arg1[var_s4].unk4 = 0;
        arg1[var_s4].unk6 = (var_s1->unk10 + var_s1->unkC) * 10430.218905280077;
        var_s1++;
        var_s4++;
        var_s3++;
    }
    *arg2 = var_s4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_global_asm_806F1EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_global_asm_806F22A8.s")

// regalloc
// https://decomp.me/scratch/nTpwl
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_global_asm_806F2754.s")

typedef struct {
    s8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    s16 unk6;
} Struct806F2754;

/*
void func_global_asm_806F2754(Actor *arg0, Struct806F2754 *arg1, s32 *arg2) {
    f32 dz;
    s16 angle;
    f32 temp_f0_2;
    f32 dx;

    dz = (character_change_array[cc_player_index].look_at_eye_z - character_change_array[cc_player_index].look_at_at_z);
    dx = (character_change_array[cc_player_index].look_at_eye_x - character_change_array[cc_player_index].look_at_at_x);
    angle = (arg0->PaaD->unk104->PaaD->unkB2 - arg0->y_rotation) - 0x800;
    temp_f0_2 = func_global_asm_80611BB4(
        character_change_array[cc_player_index].look_at_eye_y - character_change_array[cc_player_index].look_at_at_y,
        sqrtf(SQ(dz) + SQ(dx))
    );
    angle &= 0xFFF;
    if ((angle < 0xC00) && (angle > 0x800)) {
        arg0->y_rotation = (arg0->y_rotation + angle) - 0xC00;
        angle = 0xC00;
    } else if ((angle >= 0x401) && (angle < 0x800)) {
        arg0->y_rotation = (arg0->y_rotation + angle) - 0x400;
        angle = 0x400;
    }
    arg1[*arg2].unk0 = -0x80;
    arg1[*arg2].unk1 = 2;
    arg1[*arg2].unk4 = (angle / 4095.0) * 65535.0;
    arg1[*arg2].unk2 = (temp_f0_2 / MATH_2PI_F) * 65535.0;
    arg1[*arg2].unk6 = 0;
    *arg2 += 1;
}
*/

void func_global_asm_806F2A40(Actor *arg0, Struct806F2EDC *arg1, s32 *arg2) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f2;
    f32 var_f6;
    u8 temp_a0;

    var_f0 = extra_player_info_pointer->unk21E * 0.03333333507f;
    if (var_f0 < 1.0e-05) {
        var_f0 = 1.0e-05f;
    }
    switch (arg0->control_state) {
        case 0x34:
        case 0x84:
            if (0.01 < extra_player_info_pointer->unk25C) {
                extra_player_info_pointer->unk258 = extra_player_info_pointer->unk258 * 1.07;
                extra_player_info_pointer->unk25C = extra_player_info_pointer->unk25C * 0.7;
            } else {
                arg0->object_properties_bitfield &= 0xFFFF7FFF;
                if (extra_player_info_pointer->unk21E != 0) {
                    extra_player_info_pointer->unk21E--;
                }
                arg0->shadow_opacity = 255.0f * var_f0;
            }
            var_f2 = extra_player_info_pointer->unk258;
            var_f12 = extra_player_info_pointer->unk25C;
            break;
        default:
            var_f12 = var_f0;
            var_f2 = var_f0;
            if (extra_player_info_pointer->unk21E < 0x1E) {
                arg0->object_properties_bitfield |= 0x8000;
                extra_player_info_pointer->unk21E += MIN(2,0x1E - extra_player_info_pointer->unk21E);;
                extra_player_info_pointer->unk258 = 1.0f;
                extra_player_info_pointer->unk25C = extra_player_info_pointer->unk258;
            }
        break;
    }
    arg1[*arg2].unk0 = 0;
    arg1[*arg2].unk1 = 0xFF;
    arg1[*arg2].unk4 = var_f2;
    arg1[*arg2].unk8 = var_f12;
    arg1[*arg2].unkC = var_f2;
    *arg2 += 1;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_global_asm_806F2C48.s")

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Struct806F2C48;

/*
void func_global_asm_806F2C48(Actor *arg0, Struct806F2C48 *arg1, s32 *arg2) {
    f32 temp_f0;
    f32 temp_f12;
    s32 var_a3;
    s8 temp_lo;
    s32 var_v0;
    s16 sp28;
    u32 sp24;

    var_a3 = *arg2;
    if (arg0->unk6A & 1) {
        extra_player_info_pointer->unk16 += 2;
        if (extra_player_info_pointer->unk16 >= 0x80) {
            extra_player_info_pointer->unk16 = 0x7F;
        }
    } else {
        extra_player_info_pointer->unk16 -= 2;
        if (extra_player_info_pointer->unk16 < 0) {
            extra_player_info_pointer->unk16 = 0;
        }
    }
    if (extra_player_info_pointer->unk16 != 0) {
        var_v0 = (0x400 - arg0->unkDE) & 0xFFF;
        if (var_v0 >= 0x156) {
            var_v0 = 0x155;
        }
        sp28 = func_global_asm_806CC10C(arg0->y_rotation, (arg0->unkDC - 0x800) & 0xFFF);
        sp24 = var_v0 * 0x10;
        temp_f12 = func_global_asm_80612790(sp28) * sp24;
        temp_f0 = -func_global_asm_80612794(sp28) * sp24;
        temp_lo = (extra_player_info_pointer->unk16 * 6) / 10;
        if (temp_lo != 0) {
            arg1[var_a3].unk1 = 1;
            arg1[var_a3].unk4 = 0;
            arg1[var_a3].unk0 = temp_lo;
            arg1[var_a3].unk2 = temp_f12;
            arg1[var_a3].unk6 = temp_f0;
            var_a3 += 1;
        }
        temp_lo = (extra_player_info_pointer->unk16 * 3) / 10;
        if (temp_lo != 0) {
            arg1[var_a3].unk1 = 2;
            arg1[var_a3].unk4 = 0;
            arg1[var_a3].unk0 = temp_lo;
            arg1[var_a3].unk2 = temp_f12;
            arg1[var_a3].unk6 = temp_f0;
            var_a3 += 1;
        }
    }
    *arg2 = var_a3;
}
*/

void func_global_asm_806F2EDC(s32 arg0, Struct806F2EDC *arg1, s32 *arg2, u8 arg3, u8 arg4, f32 arg5, f32 arg6) {
    f32 temp_f0;

    temp_f0 = func_global_asm_80612794(arg5 * 2048.0f);
    arg1[*arg2].unk0 = arg3;
    arg1[*arg2].unk1 = arg4;
    arg1[*arg2].unk4 = 1.0f;
    arg1[*arg2].unk8 = (temp_f0 * arg6) + 1.0;
    arg1[*arg2].unkC = 1.0f;
    *arg2 += 1;
}

void func_global_asm_806F2FC0(Actor *arg0, Struct806F2FC0 *arg1, u16 arg2) {
    s32 var_v0;
    s32 var_v1;

    switch (arg2) {
        case 0:
            if (arg1->unk8E != 0) {
                if ((arg1->unk8E == 0x10) && (arg1->unk8F < 4)) {
                    arg1->unk8F = 0;
                    return;
                }
            } else {
                if (arg1->unk8F >= 4) {
                    func_global_asm_8068581C(arg0, 0xA, 0.3f, 0.0f, 0.0f, 0.0f, -0xA);
                    return;
                }
                return;
            }
            break;
        case 1:
            var_v1 = 0;
            if ((arg1->unk8E != 0) && (arg1->unk8E != 3)) {
                if ((arg1->unk8E == 0x10) && (arg1->unk8F < 6)) {
                    arg1->unk8F = 0;
                }
            } else if (arg1->unk8F >= 6) {
                var_v1 = 1;
            }
            if (var_v1 != 0) {
                if (arg1->unk8E != 0) {
                    var_v0 = arg1->unk90 + 9 & 0xFFFF;
                } else {
                    var_v0 = arg1->unk91 + 9 & 0xFFFF;
                }
                func_global_asm_8068581C(arg0, var_v0, 0.2f, 0.0f, 0.0f, 0.0f, -0xA);
                return;
            }
            break;
        case 4:
        case 5:
            if (arg1->unk8E != 0) {
                if ((arg1->unk8E == 0x10) && (arg1->unk8F < 3)) {
                    arg1->unk8F = 0;
                    return;
                }
            } else if (arg1->unk8F >= 3) {
                func_global_asm_8068581C(arg0, 0xA, 0.6f, 0.0f, 0.0f, 0.0f, -0xA);
            }
            break;
    }
}

// Jumptable, Actor* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_global_asm_806F3190.s")

void func_global_asm_806F3760(s16 map) {
    void *autowalkFile;

    autowalkFile = getPointerTableFile(TABLE_21_AUTOWALKS, map, 1, 0);
    func_global_asm_806F4528(autowalkFile);
    if (autowalkFile) {
        func_global_asm_8066B434(autowalkFile, 0x4C, 0x56);
    }
}

void func_global_asm_806F37BC(Actor *arg0, Struct806F37BC *arg1) {
    s16 temp_v0;

    func_global_asm_80672C30(arg0);
    arg0->x_position = arg1->unk0;
    arg0->y_position = arg1->unk2;
    arg0->z_position = arg1->unk4;
    temp_v0 = func_global_asm_80665DE0(arg1->unk12, arg1->unk16, arg1->unk0, arg1->unk4);
    arg0->unkEE = temp_v0;
    arg0->y_rotation = temp_v0;
}

void func_global_asm_806F386C(u8 arg0, Actor *arg1, Actor *arg2, s16 arg3, u8 arg4) {
    PlayerAdditionalActorData *temp_v0;

    temp_v0 = arg1->PaaD;
    if (D_global_asm_80753E90[0].count >= arg0) {
        is_autowalking = 3;
        D_global_asm_8076A0B1 |= 0x10;
        D_global_asm_807FD710 = arg1;
        temp_v0->unk1F0 &= ~1;
        D_global_asm_807FD714 = 0;
        D_global_asm_807FD708 = &D_global_asm_80753E90->items[arg0];
        D_global_asm_807FD70C = D_global_asm_807FD708->unk4;
        D_global_asm_807FD718 = arg3;
        D_global_asm_807FD71C = arg2;
        if (arg4 == 0) {
            func_global_asm_806F37BC(arg1, D_global_asm_807FD70C);
        }
    }
}

void func_global_asm_806F3950(GlobalASMStruct75 *arg0) {
    func_global_asm_8061134C(arg0->unk4);
    arg0->unk0 = 0;
}

void func_global_asm_806F397C(Actor *arg0, Actor *arg1, s16 arg2, s16 arg3) {
    s32 phi_v0;

    if (arg2 & 0x8000) {
        phi_v0 = 1;
    } else {
        phi_v0 = 0;
    }
    arg2 &= ~0x8000;
    func_global_asm_806F386C(arg2, arg0, arg1, arg3, phi_v0);
    D_global_asm_807FD716 = 0;
}

void func_global_asm_806F39E8(Actor *arg0, ExitData *arg1, u8 arg2) {
    Struct80753E90_unk4 *temp_v0_2;
    Struct80753E90_unk4 *temp;
    Struct80753E90_2 *temp_v1;

    temp_v1 = &D_global_asm_80753E90->items[D_global_asm_80753E90->count];
    temp_v1->unk0 = 2;
    temp_v1->unk4 = malloc(0x24);
    func_global_asm_80611690(temp_v1->unk4);
    temp = &temp_v1->unk4[1];
    temp_v0_2 = temp_v1->unk4;
    temp_v0_2->unk0 = arg1->pos.x;
    temp_v0_2->unk2 = arg1->pos.y;
    temp_v0_2->unk4 = arg1->pos.z;
    temp_v0_2->unk9 = 0x32;
    temp->unk0 = (func_global_asm_80612794((arg1->angle / 255.0) * 4095.0) * arg2) + arg1->pos.x;
    temp->unk2 = arg1->pos.y;
    temp->unk4 = (func_global_asm_80612790((arg1->angle / 255.0) * 4095.0) * arg2) + arg1->pos.z;
    temp->unk9 = 0x32;
    func_global_asm_806F386C(D_global_asm_80753E90->count, arg0, 0, 0, 0);
    D_global_asm_807FD716 = 0;
    global_properties_bitfield |= 0x400;
}

void func_global_asm_806F3BEC(Actor *arg0, s16 arg1, s16 arg2, u8 arg3) {
    Struct80753E90_unk4 *temp_v0_2;
    s16 sp3A;
    Struct80753E90_unk4 *temp_t0;
    Struct80753E90_2 *temp_a1;

    sp3A = func_global_asm_80665DE0(arg1, arg2, arg0->x_position, arg0->z_position);
    temp_a1 = &D_global_asm_80753E90->items[D_global_asm_80753E90->count];
    if (arg0->control_state != 0x44) {
        temp_a1->unk0 = 2;
        temp_a1->unk4 = malloc(0x24);
        func_global_asm_80611690(temp_a1->unk4);
        temp_t0 = &temp_a1->unk4[1];
        temp_v0_2 = temp_a1->unk4;
        temp_v0_2->unk0 = arg0->x_position;
        temp_v0_2->unk2 = arg0->y_position;
        temp_v0_2->unk4 = arg0->z_position;
        temp_v0_2->unk9 = 0x28;

        temp_t0->unk0 = (func_global_asm_80612794(sp3A) * arg3) + arg0->x_position;
        temp_t0->unk2 = arg0->y_position;
        temp_t0->unk4 = (func_global_asm_80612790(sp3A) * arg3) + arg0->z_position;
        temp_t0->unk9 = 0x28;
        func_global_asm_806F386C(D_global_asm_80753E90->count, arg0, 0, 0, 0);
        D_global_asm_807FD716 = 0;
        global_properties_bitfield |= 0x400;
    }
}

void func_global_asm_806F3DB0(void) {
    D_global_asm_807FD716 |= 2;
}

// Baffling lmao
void func_global_asm_806F3DC8(u16 *arg0, s16 *arg1, u8 *arg2, u16 arg3) {
    if (arg1[0]) {
        arg1[0]--;
        return;
    }
    if (arg2[0]) {
        arg2[0]--;
        arg0[0] |= arg3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F56F0/func_global_asm_806F3E0C.s")

typedef struct AutowalkInternal {
    s16 x;
    s16 y;
    s16 z;
    u8 pad6[0x12 - 6];
} AutowalkInternal;

typedef struct AutowalkInternal2 {
    s16 count;
    AutowalkInternal *data;
} AutowalkInternal2;

void func_global_asm_806F4528(AutowalkFile *arg0) {
    s16 sp34;
    AutowalkInternal *sp38;
    AutowalkFile *temp_a1;
    AutowalkInternal *var_s1;
    AutowalkRDRAM *var_s2;
    s16 i, j;

    if (arg0 != NULL) {
        temp_a1 = &arg0->data;
        D_global_asm_80753E90->count = arg0->count;
        sp34 = temp_a1;
        D_global_asm_80753E90->items = malloc((D_global_asm_80753E90->count * 8) + 8);
        var_s2 = D_global_asm_80753E90->items;
        for (i = 0; i < D_global_asm_80753E90->count; i++) {
            var_s1 = &temp_a1->data;
            var_s2->count = temp_a1->count;
            for (j = 0; j < var_s2->count; j++) {
                if (j == 0) {
                    sp38++;
                    var_s2->items = malloc(var_s2->count * sizeof(AutowalkInternal));
                    sp38 = var_s2->items;
                } else {
                    sp38++;
                }
                *sp38 = *var_s1++;
            }
            temp_a1 = var_s1;
            var_s2++;

        }
    } else {
        D_global_asm_80753E90->count = 0;
    }
}

f32 func_global_asm_806F46B0(s16 arg0) {
    s16 i;
    s32 max = 0xD; // TODO: Why does this need to be a temp variable?

    for (i = 0; i < max; i++) {
        if ((current_map == D_global_asm_80753EA0[i].unk0) && (((arg0 == D_global_asm_80753EA0[i].unk2)) || (D_global_asm_80753EA0[i].unk2 == -1))) {
            return D_global_asm_80753EA0[i].unk4;
        }    
    }
    return 20000.0f;
}
