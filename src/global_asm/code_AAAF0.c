#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_807204BC;
extern s32 D_global_asm_80720508;
extern s32 D_global_asm_807205C4;
extern s32 D_global_asm_807205E8;

extern s32 D_global_asm_80720710;
extern s32 D_global_asm_80720768;
extern s32 *D_global_asm_807207BC;
extern s32 D_global_asm_807207E0;

extern s32 D_global_asm_807209EC;
extern s32 D_global_asm_80720A10;
extern s32 D_global_asm_80720A34;
extern s32 D_global_asm_80720A58;

extern s32 D_global_asm_80721170;
extern s32 D_global_asm_807211D0;
extern s32 D_global_asm_80721378;

extern s32 D_global_asm_80720FE0;
extern s32 D_global_asm_80720F98;
extern s32 D_global_asm_80720FBC;

extern s32 D_global_asm_80721028;
extern s32 D_global_asm_80721004;

typedef struct {
    s32 unk0[7];
} Struct807504A4;

extern Struct807504A4 D_global_asm_807504A4;

extern f32 D_global_asm_807504C0;
extern f32 D_global_asm_807504C4;
extern u8 D_global_asm_807504C8;
extern u8 D_global_asm_807504CC;
extern u8 D_global_asm_807504D0;

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_global_asm_806A5EAC;

extern s32 D_global_asm_8076A068;

extern s32 D_global_asm_807FBB68;
extern u8 D_global_asm_807FBD70;

typedef struct {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    u8 unk3;
    u16 unk4;
    s16 unk6;
} AAD_global_asm_806A7600;

void func_global_asm_80686CF8(Actor *actor);

void func_global_asm_806A5DF0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, u8 arg5, s16 arg6, s32 arg7);
void func_global_asm_806A664C(f32 arg0);
void func_global_asm_806A6DB4(s32 arg0);

s32 func_global_asm_80723020(Actor *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6);
void func_global_asm_80723484(s32, Actor*);

void func_global_asm_806A5DF0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, u8 arg5, s16 arg6, s32 arg7) {
    f32 var_f0;
    f32 sp2C[8];

    var_f0 = 0.15f;
    if (D_global_asm_807FBB68 & 0x10) {
        var_f0 = 2.0f * var_f0;
    }
    sp2C[0] = arg5;
    sp2C[1] = arg4;
    sp2C[2] = arg6;
    func_global_asm_806891D8(arg0, arg1, arg2, arg3, 0, var_f0, arg7, &sp2C);
}

void func_global_asm_806A5EAC(AAD_global_asm_806A5EAC *arg0, void *arg1, f32 arg2) {
    if (D_global_asm_807FBB68 & 0x10) {
        arg2 *= 2.0f;
    }
    func_global_asm_807149FC(-1);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(2);
    arg0->unk4 = func_global_asm_80714C08(arg1, arg2 * 0.35, current_actor_pointer, 1, 2);
}

void func_global_asm_806A5F44(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806A5EAC(sp1C, &D_global_asm_80720710, 1.0f);
    }
}

void func_global_asm_806A5FA4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806A5EAC(sp1C, &D_global_asm_80720508, 1.0f);
    }
}

void func_global_asm_806A6004(void *arg0, s32 arg1) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (arg1 != player_pointer->unk58) {
            changeActorColor(0xFF, 0xFF, 0xFF, 0x64);
        }
        func_global_asm_806A5EAC(sp1C, arg0, 1.0f);
    }
}

void func_global_asm_806A6094(void) {
    func_global_asm_806A6004(&D_global_asm_807209EC, 3);
}

void func_global_asm_806A60BC(void) {
    func_global_asm_806A6004(&D_global_asm_80720A10, 6);
}

void func_global_asm_806A60E4(void) {
    func_global_asm_806A6004(&D_global_asm_807207E0, 4);
}

void func_global_asm_806A610C(void) {
    func_global_asm_806A6004(&D_global_asm_80720A34, 2);
}

void func_global_asm_806A6134(void) {
    func_global_asm_806A6004(&D_global_asm_80720A58, 5);
}

void func_global_asm_806A615C(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_80714A08(-0.35f, 0.35f);
        func_global_asm_806A5EAC(sp1C, &D_global_asm_80720768, 1.0f);
    }
}

void func_global_asm_806A61D0(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_806A5EAC(sp1C, &D_global_asm_807204BC, 1.0f);
    }
}

void func_global_asm_806A6230(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    s32 temp_v1;

    func_global_asm_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        temp_v1 = D_global_asm_807FBB64; // shadow_display_bitfield, shockwave_bitfield, long_distance_actor_spawn
        if (((temp_v1 << 0xC) < 0) || (temp_v1 & 0x2000)) {
            current_actor_pointer->unk15F = 1;
        }
        func_global_asm_806A5EAC(sp1C, &D_global_asm_807207BC, 1.0f);
    }
}

void func_global_asm_806A62B4(void) {
    func_global_asm_806A6230();
}

void func_global_asm_806A62D4(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        changeActorColor(0xFF, 0xFF, 0, 0xFF);
        func_global_asm_806A5EAC(sp1C, &D_global_asm_807211D0, 1.5f);
    }
}

void func_global_asm_806A6348(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_806A5EAC(sp1C, &D_global_asm_807205C4, 1.0f);
    }
}

void func_global_asm_806A63A8(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_806A5EAC(sp1C, &D_global_asm_807205E8, 1.0f);
    }
}

void func_global_asm_806A6408(void) {
    // TODO: Which aaD type are they actually expecting here?
    void *sp1C = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(12.0f);
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_806A5EAC(sp1C, &D_global_asm_80721378, 2.0f);
    }
}

extern s32 D_global_asm_807203B0; // TODO: Type
extern s32 D_global_asm_807203D4; // TODO: Type
extern s32 D_global_asm_807203F8; // TODO: Type
extern s32 D_global_asm_8072041C; // TODO: Type
extern s32 D_global_asm_80720440; // TODO: Type

void func_global_asm_806A6468(void) {
    void *aaD;
    void *sp18;

    aaD = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        switch (player_pointer->unk58) {
            case ACTOR_DIDDY:
                sp18 = &D_global_asm_807203B0;
                break;
            case ACTOR_DK:
                sp18 = &D_global_asm_8072041C;
                break;
            case ACTOR_LANKY:
                sp18 = &D_global_asm_807203F8;
                break;
            case ACTOR_CHUNKY:
                sp18 = &D_global_asm_807203D4;
                break;
            case ACTOR_TINY:
                sp18 = &D_global_asm_80720440;
                break;
        }
        func_global_asm_806A5EAC(aaD, sp18, 1.0f);
        if (current_actor_pointer->control_state == 0x63) {
            current_actor_pointer->control_state = 1;
            current_actor_pointer->unk15F = 2;
        }
    }
}

extern s32 D_global_asm_80720EBC; // TODO: Type
extern s32 D_global_asm_80720EE8; // TODO: Type
extern s32 D_global_asm_80720F14; // TODO: Type
extern s32 D_global_asm_80720F40; // TODO: Type
extern s32 D_global_asm_80720F6C; // TODO: Type

void func_global_asm_806A6574(void) {
    void *aaD;
    void *sp18;

    aaD = current_actor_pointer->additional_actor_data;
    func_global_asm_806A664C(4.5f);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        switch (player_pointer->unk58) {
            case ACTOR_DIDDY:
                sp18 = &D_global_asm_80720EE8;
                break;
            case ACTOR_DK:
                sp18 = &D_global_asm_80720F40;
                break;
            case ACTOR_LANKY:
                sp18 = &D_global_asm_80720F14;
                break;
            case ACTOR_CHUNKY:
                sp18 = &D_global_asm_80720EBC;
                break;
            case ACTOR_TINY:
                sp18 = &D_global_asm_80720F6C;
                break;
        }
        func_global_asm_806A5EAC(aaD, sp18, 1.0f);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_AAAF0/func_global_asm_806A664C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_AAAF0/func_global_asm_806A6DB4.s")

void func_global_asm_806A734C(void) {
    func_global_asm_806A6DB4(1);
}

void func_global_asm_806A736C(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->unk64 |= 4;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_global_asm_80686CF8(current_actor_pointer);
    }
    // TODO: Get rid of typecasts
    if ((u16)PaaD->unk8 == 1) {
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x73, 0xFF, 0x7F, 1, 0, 0.0f, 0);
        playSong(0x3B, 0.7f);
    } else if ((u16)PaaD->unk8 == 0xA) {
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x19C, 0xB4, 0x7F, 1, 0, 0.0f, 0);
    }
    func_global_asm_806A6DB4(0);
    if (current_actor_pointer->y_position < current_actor_pointer->unkAC) {
        current_actor_pointer->unkB8 = 0.0f;
        current_actor_pointer->y_position = current_actor_pointer->unkAC;
        current_actor_pointer->y_velocity = current_actor_pointer->y_acceleration;
    }
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x1E, 0x1E, 1, 0x96, 0x78, 0, 1.0f);
}

void func_global_asm_806A7518(void) {
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_global_asm_80686A5C(current_actor_pointer, 20.0f, 40.0f, 0x1E);
        current_actor_pointer->floor = 99999.0f;
        func_global_asm_80665564(current_actor_pointer, 0.0f);
    }
    func_global_asm_806A6DB4(0);
    if (99999.0f != current_actor_pointer->floor) {
        func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x19, 0x19, 1, 0x96, 0x78, 0, 1.0f);
    }
}

void func_global_asm_806A7600(void *arg0) {
    AAD_global_asm_806A7600 *sp34;
    s16 permanentFlagIndex;
    s32 var_a0_2;
    s32 var_v0;

    sp34 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (current_actor_pointer->unk58 == ACTOR_BALLOON_KROOL) {
            sp34->unk6 = -1;
        } else {
            sp34->unk6 = func_global_asm_80688C30(func_global_asm_80688E68(current_actor_pointer));
        }
        if ((sp34->unk6 != -1) && (isFlagSet(sp34->unk6, FLAG_TYPE_PERMANENT))) {
            deleteActor(current_actor_pointer);
            return;
        }
        func_global_asm_8066E854(current_actor_pointer, 0, 0, 0, -1);
        func_global_asm_8066EB40(current_actor_pointer, 175.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0, 12.0f, 0, 80.0f, -1);
        sp34->unk0 = current_actor_pointer->unk124->unk0_s32;
        sp34->unk1 = current_actor_pointer->unk124->unk4_s32;
        sp34->unk2 = func_global_asm_80723020(current_actor_pointer, sp34->unk0, 0, 0.0f, 0.0f, 0.0f, 0);
        if (sp34->unk2 != -1) {
            func_global_asm_807232B8(sp34->unk2, 1);
            func_global_asm_80723284(sp34->unk2, sp34->unk1);
            func_global_asm_80723320(sp34->unk2, -1);
            func_global_asm_8072334C(sp34->unk2, 1);
        }
        sp34->unk4 = 0;
        return;
    }
    if (sp34->unk2 != -1) {
        // TODO: There might be only 1 param for the first call here
        func_global_asm_80723484(sp34->unk2, current_actor_pointer);
        func_global_asm_807238D4(sp34->unk2, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
    }
    current_actor_pointer->y_position += (5.0 * func_global_asm_80612794(sp34->unk4));
    sp34->unk4 = (sp34->unk4 + 0x50) & 0xFFF;
    if ((D_global_asm_8076A068 % 24U) == 0) {
        switch (current_actor_pointer->unk58) {
            default:
                permanentFlagIndex = -1;
                break;
            case ACTOR_BALLOON_DIDDY:
                permanentFlagIndex = 6;
                break;
            case ACTOR_BALLOON_CHUNKY:
                permanentFlagIndex = 0x75;
                break;
            case ACTOR_BALLOON_TINY:
                permanentFlagIndex = 0x42;
                break;
            case ACTOR_BALLOON_LANKY:
                permanentFlagIndex = 0x46;
                break;
        }
        if ((permanentFlagIndex == -1) || (isFlagSet(permanentFlagIndex, FLAG_TYPE_PERMANENT) != FALSE)) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            func_global_asm_807149B8(1);
            var_a0_2 = TRUE;
            if (current_actor_pointer->unk58 == ACTOR_BALLOON_KROOL) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == ACTOR_DIDDY) && (current_actor_pointer->unk58 == ACTOR_BALLOON_DIDDY)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == ACTOR_CHUNKY) && (current_actor_pointer->unk58 == ACTOR_BALLOON_CHUNKY)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == ACTOR_TINY) && (current_actor_pointer->unk58 == ACTOR_BALLOON_TINY)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == ACTOR_LANKY) && (current_actor_pointer->unk58 == ACTOR_BALLOON_LANKY)) {
                var_a0_2 = FALSE;
            } else if ((player_pointer->unk58 == ACTOR_DK) && (current_actor_pointer->unk58 == ACTOR_BALLOON_DK)) {
                var_a0_2 = FALSE;
            }
            if (var_a0_2 != 0) {
                changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
            } else {
                func_global_asm_8071498C(&func_global_asm_8071EB70);
                func_global_asm_80714950(0x226);
            }
            func_global_asm_80714A28(4);
            func_global_asm_80714998(3);
            func_global_asm_80714C08(arg0, 0.8f, current_actor_pointer, 1, 2);
            current_actor_pointer->noclip_byte = 2;
        } else {
            current_actor_pointer->noclip_byte = 1;
        }
    }
    if (D_global_asm_807FBD70 == 4) {
        func_global_asm_80686CF8(current_actor_pointer);
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x2BF, 0xFF, 0x7F, 0x1E, 0, 0.0f, 0);
        deleteActor(current_actor_pointer);
        if (current_actor_pointer->unk58 == ACTOR_BALLOON_KROOL) {
            func_global_asm_80724994(3, 1, 0x27, 0, 0);
            return;
        }
        if (sp34->unk6 != -1) {
            setFlag(sp34->unk6, TRUE, FLAG_TYPE_PERMANENT);
        }
        func_global_asm_806F8BC4(0, 0, 0);
        changeCollectableCount(0, 0, 10);
    }
}

void func_global_asm_806A7B04(void) {
    func_global_asm_806A7600(&D_global_asm_80720FBC);
}

void func_global_asm_806A7B28(void) {
    func_global_asm_806A7600(&D_global_asm_80720F98);
}

void func_global_asm_806A7B4C(void) {
    func_global_asm_806A7600(&D_global_asm_80721028);
}

void func_global_asm_806A7B70(void) {
    func_global_asm_806A7600(&D_global_asm_80721004);
}

void func_global_asm_806A7B94(void) {
    func_global_asm_806A7600(&D_global_asm_80720FE0);
}

void func_global_asm_806A7BB8(void) {
    func_global_asm_806A7600(&D_global_asm_80721004);
}

void func_global_asm_806A7BDC(void) {
    s32 sp64;
    s32 sp60;
    Struct807504A4 sp44;

    sp64 = D_global_asm_807FC950->character_progress[current_character_index[0]].instrument & 1;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_8066E854(current_actor_pointer, 0, 10.0f, 0, -1);
        func_global_asm_8066EB40(current_actor_pointer, 175.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0, 10.0f, 0, 80.0f, -1);
        current_actor_pointer->floor = 99999.0f;
        func_global_asm_80665564(current_actor_pointer, 0.0f);
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    if ((sp64 != 0) && (D_global_asm_807FBD70 == 4) && ((object_timer % 5U) == 0)) {
        sp60 = ((rand() >> 0xF) % 255) % 7;
        sp44 = D_global_asm_807504A4;
        func_global_asm_8071498C(&func_global_asm_8071D28C);
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x64);
        func_global_asm_80714C08(sp44.unk0[sp60], 0.2f, current_actor_pointer, 1, 0);
        playSong(0x7F, 1.0f);
        func_global_asm_806F8BC4(7, 0, 0);
        changeCollectableCount(7, 0, func_global_asm_806F8EDC(7, 0));
    }
    if (!(object_timer & 0xF)) {
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(&func_global_asm_8071EB70);
        func_global_asm_80714950(0x226);
        func_global_asm_80714998(2);
        changeActorColor(0xFF, 0xFF, 0xFF, sp64 != 0 ? 0xFF : 0x7F);
        func_global_asm_80714C08(&D_global_asm_80721170, 0.4f, current_actor_pointer, 1, 2);
    }
    if (99999.0f != current_actor_pointer->floor) {
        func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0xE, 0xE, 1, 0x96, 0x78, 0, 1.0f);
    }
}

typedef struct {
    f32 unk0;
    s16 unk4;
} AAD_global_asm_806A7EF0;

void func_global_asm_806A7EF0(void) {
    AAD_global_asm_806A7EF0 *aaD;
    AnimationStateUnk20 *temp_v0_2;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->animation_state->unk20 = malloc(0x20);
        func_global_asm_80611690(current_actor_pointer->animation_state->unk20);
        aaD->unk4 = 0;
        aaD->unk0 = 1.0f;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->object_properties_bitfield |= 0x40000000;
        current_actor_pointer->shadow_opacity = D_global_asm_807504CC;
    }
    if (D_global_asm_807504D0 < current_actor_pointer->shadow_opacity) {
        current_actor_pointer->shadow_opacity -= D_global_asm_807504D0;
    }
    aaD->unk4++;
    if (D_global_asm_807504C4 < aaD->unk4) {
        deleteActor(current_actor_pointer);
        return;
    }
    aaD->unk0 *= D_global_asm_807504C0;
    temp_v0_2 = current_actor_pointer->animation_state->unk20;
    temp_v0_2->unk0 = D_global_asm_807504C8;
    temp_v0_2->unk1 = 0xFF;
    temp_v0_2->unk4 = aaD->unk0;
    temp_v0_2->unk8 = aaD->unk0;
    temp_v0_2->unkC = aaD->unk0;
    temp_v0_2[1].unk0 = 0xFF;
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806A8070(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x40000000;
    }
    renderActor(current_actor_pointer, 0);
}
