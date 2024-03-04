#include <ultra64.h>
#include "functions.h"

typedef struct {
    void *unk0; // function pointer
    s8 unk4;
    s8 unk5;
    s16 unk6;
    f32 unk8;
    Actor *unkC;
    Actor *unk10;
} GlobalASMStruct61;

typedef struct {
    f32 unk0;
    Actor *unk4;
    Actor *unk8;
} Struct806CEFBC;

typedef struct {
    Actor *unk0;
    Actor *unk4;
} Struct806CF138;

typedef struct {
    void *unk0; // function pointer
    s8 unk4;
    s8 unk5;
    s16 unk6;
    Actor *unk8;
    Actor *unkC;
    Actor *unk10;
} GlobalASMStruct62;

typedef struct {
    s16 unk0; // Used
    s16 unk2;
    s32 unk4;
} GlobalASMStruct63;

// TODO: Add to aaD union
typedef struct {
    u16 unk0;
    u16 unk2;
    Actor *unk4;
    s32 unk8;
    u16 unkC;
    u16 unkE;
    f32 unk10;
} AAD_global_asm_806D0A84;

extern s32 D_global_asm_8071FB08; // TODO: Proper datatype
extern s32 D_global_asm_8071FC40;
extern s32 D_global_asm_8071FFA0;

extern u8 D_global_asm_80750AD0;
extern GlobalASMStruct63 D_global_asm_80750B54[];
extern f32 D_global_asm_80750FA8;

// .data
extern f32 D_global_asm_80753170[];
extern f32 D_global_asm_807531FC[]; // Kong Walking Maximum Velocity
extern f32 D_global_asm_80753218[];
extern f32 D_global_asm_80753234[];
extern f32 D_global_asm_80753250[];
extern s16 D_global_asm_8075326C[];
extern f32 D_global_asm_807532B8[];
extern f32 D_global_asm_807532D4[];
extern f32 D_global_asm_807532F0[];
extern f32 D_global_asm_8075330C[];
extern s16 D_global_asm_80753328[];
extern f32 D_global_asm_80753338[];
extern f32 D_global_asm_8075340C[];
extern f32 D_global_asm_80753428[];
extern f32 D_global_asm_80753578[]; // yAccelArray in ghidra
extern f32 D_global_asm_80753594[];
extern f32 D_global_asm_807535B0[] ;/*= {-17, -17, -17, -17, -10, -10, -17}; // Kong Jumping Y Acceleration*/
extern f32 D_global_asm_80753658[];
extern f32 D_global_asm_807536E4[];
extern f32 D_global_asm_80753700[];
extern f32 D_global_asm_80753754[];
extern s16 D_global_asm_8075387C[];
extern s16 D_global_asm_8075388C[];
extern s16 D_global_asm_807538B8[];
extern s16 D_global_asm_807538C8[];
extern f32 D_global_asm_807539C0[];
extern s16 D_global_asm_80753A2C[];
extern s16 D_global_asm_80753A3C[];
extern s16 D_global_asm_80753A4C[];
extern f32 D_global_asm_80753A5C[];
extern s16 D_global_asm_80753A78[];
extern f32 D_global_asm_80753AFC[];

// rodata
/*
extern f32 D_global_asm_8075C91C;// = 0.15f;
extern f32 D_global_asm_8075C920;// = 0.15f;
extern f32 D_global_asm_8075C924;// = 0.3f;
extern f64 D_global_asm_8075C928;// = -0.1;
extern f32 D_global_asm_8075C930;// = -0.1f;
extern f64 D_global_asm_8075C938;// = 0.149999999999999994;

extern f64 D_global_asm_8075C9A0;// = 63.0;
extern f64 D_global_asm_8075C9A8;// = 63.0;
extern f64 D_global_asm_8075C9B0;// = 6.28318548202514648; //TWO_PI;

extern f32 D_global_asm_8075CBE0;// = 57.29577637f;
extern f64 D_global_asm_8075CBE8;// = 270.0;
extern f32 D_global_asm_8075CBF0;// = 57.29577637f;
extern f64 D_global_asm_8075CBF8;// = 90.0;
extern f32 D_global_asm_8075CC00;// = 57.29577637f;

extern f32 D_global_asm_8075CC68;// = 0.05f;
extern f32 D_global_asm_8075CC6C;// = 0.3f;
extern f32 D_global_asm_8075CC70;// = 0.4f;
extern f32 D_global_asm_8075CC74;// = 0.004f;
extern f32 D_global_asm_8075CC78;// = 0.05f;
extern f32 D_global_asm_8075CC7C;// = 0.15f;
extern f32 D_global_asm_8075CC80;// = 0.05f;
extern f32 D_global_asm_8075CC84;// = 0.001f;
extern f32 D_global_asm_8075CC88;// = 99999.0f;
extern f64 D_global_asm_8075CC90;// = 0.11;
extern f64 D_global_asm_8075CC98;// = 0.235199999999999992;
extern f64 D_global_asm_8075CCA0;// = 0.17599999999999999;
extern f32 D_global_asm_8075CCA8;// = 0.15f;
extern f64 D_global_asm_8075CCB0;// = 6.66666666999999968;
extern f64 D_global_asm_8075CCB8;// = 0.2;
extern f64 D_global_asm_8075CCC0;// = 0.2;
extern f64 D_global_asm_8075CCC8;// = 1.19999999999999996;
extern f64 D_global_asm_8075CCD0;// = 0.149999999999999994;
extern f64 D_global_asm_8075CCD8;// = 0.2;
extern f32 D_global_asm_8075CCE0;// = 6.283185482f;
*/
// end rodata

extern s32 D_global_asm_807FBB68;
extern s16 D_global_asm_807FD584; // index into a ton of arrays
extern u8 D_global_asm_807FD586;

void func_global_asm_8062217C(Actor*, u8);
void func_global_asm_806F91B4(s32, s32, s16);
int func_global_asm_806FF358(); // TODO: Signature
int func_global_asm_806FF75C(); // TODO: Signature
void func_global_asm_80665160(Actor *, s16, s16);
void func_global_asm_806653C0(Actor *, f32, f32);
void func_global_asm_806CC970(void);
void func_global_asm_806CCB0C(void);
f32 func_global_asm_806CD898(f32 currentSpeed, f32 desiredSpeed, f32 boostAmount); // boostSpeed
void func_global_asm_806CEE64(f32);
void func_global_asm_806CEED8(void);
void func_global_asm_806CFD68(void);

f32 func_global_asm_806DFFA0(f32, s16, s16);
void func_global_asm_806EAB44(Actor *arg0, u8 arg1);
s32 func_global_asm_806DF6D4(s32 arg0);
void func_global_asm_806CC948();
void func_global_asm_806CFECC(void);
void func_global_asm_806D2378();
void func_global_asm_806CC948();
u8 func_global_asm_806CDD24(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
s16 func_global_asm_806CE4E4(Actor*, f32, f32, s32);
void func_global_asm_806DF494(s16*, s16, s16);
void func_global_asm_806D0468(Actor *arg0, u8 arg1);
void func_global_asm_806CD8EC(void);
void func_global_asm_806CD424(s16, f32, f32); // TODO: Is this signature correct?
void func_global_asm_80718BF4(void);
u8 func_global_asm_80666AE0();
void func_global_asm_806D0150(Actor *arg0);
void func_global_asm_806C8D20(Actor*);
void func_global_asm_806CC638(f32 arg0);
void func_global_asm_807149FC(s32);
s16 func_global_asm_806CC190(s16, s16, f32);
void func_global_asm_806CEFBC(Struct806CEFBC*); // TODO: Proper signature, just for function pointer
void func_global_asm_806CF138(Struct806CF138 *arg0);
void func_global_asm_80613AF8(Actor*, s32, f32, f32);
s32 func_global_asm_806CD9A0(Actor*, f32, f32, s16, s16);
void func_global_asm_80613A50(Actor*, s32);
s32 func_global_asm_806CE7A0(Actor*, f32, f32, s16, s16);

void func_global_asm_806C9DE0(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 0);
}

void func_global_asm_806C9E10(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 2);
}

void func_global_asm_806C9E40(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 3);
}

void func_global_asm_806C9E70(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 4);
}

void func_global_asm_806C9EA0(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 6);
}

void func_global_asm_806C9ED0(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 1);
}

void func_global_asm_806C9F00(void) {
    func_global_asm_8066E5F8(current_actor_pointer, 3, 8);
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 7);
}

void func_global_asm_806C9F44(void) {
    func_global_asm_806CA5F8(0);
    func_global_asm_806F3190(current_actor_pointer, 5);
}

void func_global_asm_806C9F74(Actor *arg0) {
    if (D_global_asm_80750B54[arg0->control_state].unk0 & 0x200) {
        func_global_asm_806EAB44(arg0, arg0->control_state != 2);
    } else if (D_global_asm_80750B54[arg0->control_state].unk0 & 0x100) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

Actor *func_global_asm_806C9FD8(Actor *actor) {
    Actor *originalActor = actor;

    if (!actor) {
        return actor;
    }

    switch (actor->interactable) {
        case 4:
            actor = actor->unk11C;
            break;
        case 8:
            actor = actor->unk11C;
            break;
    }

    if (actor) {
        if (actor->interactable == 1 || actor->interactable == 2) {
            return actor;
        }
    }

    return originalActor;
}

void func_global_asm_806CA048(Actor *actor, PlayerAdditionalActorData *arg1) {
    s32 phi_v1 = FALSE;

    if (!actor) {
        phi_v1 = TRUE;
    } else {
        if (actor->interactable & 1) {
            PlayerAdditionalActorData *PaaD = actor->PaaD;
            arg1->unk248 = PaaD->unk1A4;
            arg1->unk249 = 0;
        } else if (actor->interactable & 2) {
            arg1->unk248 = -1;
            arg1->unk249 = func_global_asm_80727194(actor);
        } else {
            phi_v1 = TRUE;
        }
    }

    if (phi_v1) {
        extra_player_info_pointer->unk246 = 0;
        extra_player_info_pointer->unk247 = -1;
    }
    arg1->unk24A = 5;
}

void func_global_asm_806CA0E8(Actor *arg0, Actor *arg1, s32 arg2) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    s32 phi_t0 = FALSE;
    s32 phi_a3 = FALSE;

    if (!arg1) {
        phi_a3 = TRUE;
    } else {
        if (arg1->interactable == 1) {
            PlayerAdditionalActorData *PaaD2 = arg1->PaaD;
            PaaD->unk247 = PaaD2->unk1A4;
            PaaD->unk246 = 0;
            phi_t0 = TRUE;
        } else if (arg1->interactable == 2) {
            PaaD->unk246 = func_global_asm_80727194(arg1);
            PaaD->unk247 = -1;
            phi_t0 = TRUE;
        } else {
            phi_a3 = TRUE;
        }
    }
    if (phi_a3) {
        PaaD->unk246 = 0;
        PaaD->unk247 = -1;
    }
    if (phi_t0) {
        PaaD->unk24C = arg1->animation_state->unk0->unk10;
        PaaD->unk24E = arg2;
    }
}

s32 func_global_asm_806CA1B4(s32 arg0) {
    Actor *phi_v1;
    s32 phi_a2 = 1;
    phi_v1 = NULL;

    if (extra_player_info_pointer->unk247 >= 0) {
        phi_v1 = character_change_array[extra_player_info_pointer->unk247].player_pointer;
    } else if (extra_player_info_pointer->unk246 > 0) {
        phi_v1 = func_global_asm_807270C0(extra_player_info_pointer->unk246, 0);
    }

    if (phi_v1) {
        if ((extra_player_info_pointer->unk24C == phi_v1->animation_state->unk0->unk10) && (extra_player_info_pointer->unk24E >= arg0)) {
            phi_a2 = 0;
        }
    }
    return phi_a2;
}

void func_global_asm_806CA26C(void) {
    if (func_global_asm_806CA1B4(-1)) {
        extra_player_info_pointer->unk247 = -1;
        extra_player_info_pointer->unk246 = 0;
    }
}

void func_global_asm_806CA2AC(void) {
    extra_player_info_pointer->unkC8 = -1;
    func_global_asm_80605314(current_actor_pointer, 1);
}

void func_global_asm_806CA2E4(void) {
    if ((extra_player_info_pointer->unkC8 != -1) && ((!isFlagSet(0x179, FLAG_TYPE_PERMANENT)) || (current_actor_pointer->unkE0 != 0.0f) || ((D_global_asm_807FBB64 << 8) < 0) || (func_global_asm_806F8AD4(5, extra_player_info_pointer->unk1A4) == 0))) {
        func_global_asm_806CA2AC();
        extra_player_info_pointer->unkC8 = -1;
        return;
    }
    if (extra_player_info_pointer->unkC8 != -1) {
        if (D_global_asm_807FD610[cc_player_index].unk2A & B_BUTTON) {
            if (extra_player_info_pointer->unkC8 > 0) {
                if ((extra_player_info_pointer->unkC8 < 0x1E) && ((object_timer & 3) == 0)) {
                    func_global_asm_80684900(0);
                }
                extra_player_info_pointer->unkC8--;
                if (extra_player_info_pointer->unkC8 == 0x1E) {
                    func_global_asm_80604CBC(current_actor_pointer, 0x104, 0x3C, 1, 1, 0xFF, 1.0f, 0);
                }
            } else if ((object_timer & 1) == 0) {
                func_global_asm_80684900(1);
            }
        } else {
            if (extra_player_info_pointer->unkC8 == 0) {
                if ((current_actor_pointer->unk6A & 1)) {
                    current_actor_pointer->control_state = 0x2D;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_806F8BC4(5, 0, 0);
                    func_global_asm_806F91B4(5, extra_player_info_pointer->unk1A4, -1 * func_global_asm_806FA7A4(5));
                    func_global_asm_80614E78(current_actor_pointer, 0x42);
                    func_global_asm_80608528(current_actor_pointer, 0xF2, 0xFF, 0x7F, 0);
                    current_actor_pointer->unkB8 = 0.0f;
                }
            }
            func_global_asm_806CA2AC();
        }
    }
}

void func_global_asm_806CA540(void) {
    if ((current_actor_pointer->unk6A & 0x221) == 1) {
        if (current_actor_pointer->unkE0 != 0.0f) {
            if (!(current_actor_pointer->unk6C & 1)
                || current_actor_pointer->unkDE < 0x226
                || ((current_actor_pointer->unk78 == 0xC) && (current_actor_pointer->unkB8 > 40.0f))) {
                extra_player_info_pointer->unkC2 = 0x32;
            }
            extra_player_info_pointer->unkC2++;
        } else {
            extra_player_info_pointer->unkC2 = 0;
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CA5F8.s")

void func_global_asm_806CB53C(void) {
    s32 phi_s0;
    f32 phi_f0;

    if (((current_player->unk58 == ACTOR_RAMBI) || (current_player->unk58 == ACTOR_ENGUARDE)) && (extra_player_info_pointer->unk1FD != 0)) {
        if ((extra_player_info_pointer->unk1F0 & 0x800) && extra_player_info_pointer->unk23E == 0) {
            extra_player_info_pointer->unk23E = 0x1E;
            func_global_asm_80687400();
        }
        if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS) && (D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && extra_player_info_pointer->unk23E == 0) {
            extra_player_info_pointer->unk23E = 0x1E;
        }
        if (extra_player_info_pointer->unk23E != 0) {
            func_global_asm_80714950(((rand() >> 0xF) % 10) + 0x8008);
            func_global_asm_807149FC(2);
            func_global_asm_8071498C(&func_global_asm_80717930);
            func_global_asm_807149B8(1);
            func_global_asm_80714A28(6);
            func_global_asm_80714C08(&D_global_asm_8071FFA0, (((rand() >> 0xF) % 50) / 80.0) + 0.5, current_actor_pointer, 2, 0);
            extra_player_info_pointer->unk23E--;
        }
        if (extra_player_info_pointer->unk23E == 1) {
            func_global_asm_806EB0C0(0x3B, NULL, cc_player_index);
            extra_player_info_pointer->unk1FD = 0;
        }
    } else {
        extra_player_info_pointer->unk23E = 0;
    }
    extra_player_info_pointer->unk1F0 &= ~0x800;
    if ((character_change_array[cc_player_index].unk2C0 != 1) || (extra_player_info_pointer->unk1F0 & 0x30)) {
        if ((extra_player_info_pointer->unk1F0 & 0x80000000) && extra_player_info_pointer->unk23F == 0) {
            extra_player_info_pointer->unk23F = 0x1E;
            func_global_asm_80687400();
        }
        if (extra_player_info_pointer->unk23F) {
            extra_player_info_pointer->unk23F--;
        }
        if (extra_player_info_pointer->unk23F == 1) {
            D_global_asm_807FD610[cc_player_index].unk2C |= L_CBUTTONS;
            D_global_asm_807FD610[cc_player_index].unk2A |= Z_TRIG;
        }
        if (!(D_global_asm_80750B54[current_actor_pointer->control_state].unk0 & 0x300) && !(extra_player_info_pointer->unk1F0 & 0x14000) && !func_global_asm_8061CB50()) {
            if ((extra_player_info_pointer->unk1F4 & 0x10) == 0) {
                func_global_asm_806F91B4(5, extra_player_info_pointer->unk1A4, -1);
            }
        }
    } else {
        extra_player_info_pointer->unk23F = 0;
    }
    extra_player_info_pointer->unk1F0 &= 0x7FFFFFFF;
    if (((D_global_asm_807FD610[cc_player_index].unk2C & 2) && (D_global_asm_807FD610[cc_player_index].unk2A & 0x2000) && (cc_number_of_players == 1)) || !func_global_asm_806F8AD4(5, extra_player_info_pointer->unk1A4)) {
        if (!(extra_player_info_pointer->unk1F0 & 0x2000) && current_map != MAP_KROOL_FIGHT_CHUNKY_PHASE) {
            phi_s0 = FALSE;
            if (character_change_array[cc_player_index].unk2C0 != 1) {
                func_global_asm_806D0468(current_player, 1);
                phi_s0 = TRUE;
                if (extra_player_info_pointer->unk1AC != 0) {
                    if (current_player->unk58 == ACTOR_CHUNKY && current_player->control_state != 0x4A) {
                        current_player->control_state = 0x4A;
                        current_player->control_state_progress = 0;
                        func_global_asm_80614EBC(current_player, 0x1CD);
                    }
                }
            }
            if (extra_player_info_pointer->unk1F0 & 0x10) {
                extra_player_info_pointer->unk1F0 &= ~0x10;
                current_player->object_properties_bitfield |= 0x8000;
                current_player->shadow_opacity = 0xFF;
                phi_s0 = TRUE;
            }
            if (extra_player_info_pointer->unk1F0 & 0x20) {
                extra_player_info_pointer->unk1F0 &= ~0x20;
                func_global_asm_806D0408();
                phi_s0 = TRUE;
            }
            if (phi_s0) {
                func_global_asm_806C9F74(current_actor_pointer);
            }
        }
    }
    if (extra_player_info_pointer->unk1F0 & 0x10) {
        extra_player_info_pointer->unkD4 = 2;
    }
    if (extra_player_info_pointer->unk1CC != extra_player_info_pointer->unk1C0) {
        current_actor_pointer->unk64 |= 0x800;
        switch (current_actor_pointer->unk58) {
            case ACTOR_TINY:
                current_actor_pointer->unk120 = 0.15f;
                break;
            case ACTOR_CHUNKY:
                current_actor_pointer->unk120 = 0.3f;
                break;
            default:
                current_actor_pointer->unk120 = 0.15f;
                break;
        }
        func_global_asm_806D06A0();
    } else {
        current_actor_pointer->unk64 &= ~0x800;
    }
    if (extra_player_info_pointer->unk1F0 & 0x40) {
        if (current_actor_pointer->unk58 != ACTOR_CHUNKY) {
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity -= 4;
            if (current_actor_pointer->shadow_opacity < 100) {
                current_actor_pointer->shadow_opacity = 100;
            }
        }
        if (extra_player_info_pointer->unk1FE != -1) {
            extra_player_info_pointer->unk1FE -= 1;
            if (!(extra_player_info_pointer->unk1FE & 7)) {
                func_global_asm_8071498C(&func_global_asm_80716FB4);
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(3);
                func_global_asm_80714CC0(&D_global_asm_8071FB08, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
            if (extra_player_info_pointer->unk1FE == 0) {
                func_global_asm_80602B60(0x6C, 0);
                current_actor_pointer->object_properties_bitfield |= 0x8000;
                func_global_asm_806F12FC(current_actor_pointer);
            }
        }
    }
    if (extra_player_info_pointer->unk200 != 0) {
        if ((extra_player_info_pointer->unk1F0 * 0x10) < 0) {
            phi_f0 = 1.0f;
            if (extra_player_info_pointer->unk200 >= 2) {
                phi_f0 = 0.5f;
            }
            extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584] * phi_f0;
            extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584] * phi_f0;
            extra_player_info_pointer->unk48 = D_global_asm_8075326C[D_global_asm_807FD584] * phi_f0;
        }
        if ((current_actor_pointer->control_state != 0x7C) || (current_actor_pointer->control_state == 0x7C && extra_player_info_pointer->unk200 == 1)) {
            extra_player_info_pointer->unk200--;
        }
        if (extra_player_info_pointer->unk200 == 0) {
            extra_player_info_pointer->unk1F0 &= 0xF7FFFF7F;
            if (current_actor_pointer->control_state == 0x7C) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
        }
    }
    if ((extra_player_info_pointer->unk1F0 & 0x20) || (is_autowalking == 3)) {
        if (current_map == MAP_FUNGI) {
            extra_player_info_pointer->unk38 = 200.0f;
        } else {
            extra_player_info_pointer->unk38 = D_global_asm_80753218[D_global_asm_807FD584];
        }
    }
}

void func_global_asm_806CBE44(void) {
    if ((D_global_asm_807FBB70.unk2 != 0) && (D_global_asm_807FBB70.unk14 == 1)) {
        func_global_asm_806EB0C0(0x20, NULL, cc_player_index);
    }
}

void func_global_asm_806CBE90(void) {
    if ((current_actor_pointer->unk6A & 0x21) == 1) {
        if ((current_actor_pointer->unk6A & 0x200) != 0) {
            if (current_actor_pointer->unk6E[0] == -1) {
                func_global_asm_80604CBC(current_actor_pointer, 0x10D, 0, 1, 0, 0xFF, 1.0f, 0);
            }
            current_actor_pointer->control_state = 0xF;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer->terminal_velocity = -900.0f;
            extra_player_info_pointer->unk48 = D_global_asm_8075326C[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
            extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584];
            func_global_asm_80614E78(current_actor_pointer, 0x5E);
            current_actor_pointer->unk6A |= 0x20;
            func_global_asm_80614D90(current_actor_pointer);
        } else if ((current_actor_pointer->unkE0 != 0.0f) && (extra_player_info_pointer->unkC2 >= 0x15) && (current_actor_pointer->control_state != 0x17)) {
            if (func_global_asm_806CC14C(current_actor_pointer->unkD8, current_actor_pointer->y_rotation) < 0x200) {
                if (D_global_asm_80750B54[current_player->control_state].unk0 & 0x200) {
                    func_global_asm_806EAB44(current_actor_pointer, 0);
                }
                func_global_asm_806EB0C0(0x21, NULL, cc_player_index);
            } else if ((func_global_asm_806CC14C(current_actor_pointer->unkD8, current_actor_pointer->unkEE) < 0x400) || (current_actor_pointer->unkB8 < 15.0f)) {
                if (D_global_asm_80750B54[current_player->control_state].unk0 & 0x200) {
                    func_global_asm_806EAB44(current_actor_pointer, 0);
                }
                func_global_asm_806EB0C0(0x22, NULL, cc_player_index);
            }
        }
    }
}

s16 func_global_asm_806CC10C(s16 arg0, s16 arg1) {
    s16 temp_t2 = (arg1 - arg0);
    temp_t2 &= 0xFFF;
    if (temp_t2 >= 0x801) {
        temp_t2 -= 0x1000;
    }
    return temp_t2;
}

s16 func_global_asm_806CC14C(s16 arg0, s16 arg1) {
    s16 phi_v1 = (arg1 - arg0);
    phi_v1 &= 0xFFF;
    if (phi_v1 >= 0x801) {
        phi_v1 = 0x1000 - phi_v1;
    }
    return phi_v1;
}

// TODO: Clean this up with the ABS macro if possible
s16 func_global_asm_806CC190(s16 arg0, s16 arg1, f32 arg2) {
    s16 temp_v0;
    s16 phi_v1;
    s16 phi_v0;

    temp_v0 = arg1 - arg0;
    if (temp_v0 > 0) {
        phi_v1 = temp_v0;
    } else {
        phi_v1 = -temp_v0;
    }
    if ((arg2 != 0.0f) && ((temp_v0 & 0xFFF) != 0)) {
        phi_v0 = temp_v0 >= 0 ? 1 : -1;
        if (phi_v1 >= 0x801) {
            phi_v1 = 0x1000 - phi_v1;
            phi_v0 = -phi_v0;
        }
        if (phi_v1 < arg2) {
            arg2 = phi_v1;
        }
        arg0 += (phi_v0 * (s16)(phi_v1 / arg2));
    }
    return arg0 & 0xFFF;
}

// TODO: Clean this up with the ABS macro if possible
s16 func_global_asm_806CC284(s16 arg0, s16 arg1, f32 arg2) {
    s16 phi_v1;
    s16 phi_v0;
    s16 temp_v0;

    temp_v0 = arg1 - arg0;
    if (temp_v0 > 0) {
        phi_v1 = temp_v0;
    } else {
        phi_v1 = -temp_v0;
    }
    if ((arg2 != 0) && (temp_v0 & 0xFFF) != 0) {
        phi_v0 = temp_v0 >= 0 ? 1 : -1;
        if (phi_v1 >= 0x801) {
            phi_v1 = 0x1000 - phi_v1;
            phi_v0 = -phi_v0;
        }
        arg0 += (phi_v0 * (s16)(phi_v1 * arg2));
    }
    return arg0 & 0xFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CC364.s")

/*
// TODO: Close, float & stack nonsense
void func_global_asm_806CC364(u8 arg0) {
    f32 temp_f14_2;
    f32 phi_f12;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f12 = D_global_asm_80753A3C[D_global_asm_807FD584];
    } else {
        phi_f12 = D_global_asm_80753A4C[D_global_asm_807FD584];
    }
    temp_f14_2 = (ABS(func_global_asm_80612794(current_actor_pointer->z_rotation) * phi_f12) + 1.5f) + ABS(func_global_asm_80612790(current_actor_pointer->unkDA) * phi_f12);
    if (current_actor_pointer->distance_from_floor < temp_f14_2) {
        if (current_actor_pointer->unkDA < 500) {
            current_actor_pointer->unkB8 = MAX(current_actor_pointer->unkB8, 50);
        }
        if (arg0 && current_actor_pointer->y_velocity < 0) {
            current_actor_pointer->y_velocity = 0;
        }
        if (phi_f12 < (current_actor_pointer->unkAC - current_actor_pointer->y_position)) {
            current_actor_pointer->y_position = current_actor_pointer->floor + temp_f14_2;
        }
    }
}
*/

void func_global_asm_806CC5DC(void) {
    current_actor_pointer->unkB8 = func_global_asm_806CD898(current_actor_pointer->unkB8, 0, D_global_asm_807539C0[D_global_asm_807FD584]);
    func_global_asm_806CC970();
    func_global_asm_806CC364(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CC638.s")

/*
// TODO: WIP, might need some more temp variables or split apart float operations into separate lines
void func_global_asm_806CC638(f32 arg0) {
    f32 sp34;
    f32 phi_f14;
    f32 phi_f2;
    f32 phi_f16;

    if (extra_player_info_pointer->unk10 != 0) {
        extra_player_info_pointer->unk10--;
        phi_f14 = extra_player_info_pointer->unk38 * -func_global_asm_80612794(extra_player_info_pointer->unk12);
        sp34 = extra_player_info_pointer->unk38 * func_global_asm_80612790(extra_player_info_pointer->unk12);
        if (extra_player_info_pointer->unk38 < current_actor_pointer->unkB8) {
            phi_f2 = extra_player_info_pointer->unk2C * 8.0f;
        } else {
            phi_f2 = extra_player_info_pointer->unk2C;
        }
    } else {
        phi_f14 = current_actor_pointer->unkB8 * -func_global_asm_80612794(current_actor_pointer->z_rotation);
        current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, phi_f14, 2.0f);
        sp34 = 0.0f;
        phi_f2 = extra_player_info_pointer->unk30;
    }
    phi_f16 = 0.0f;
    if (phi_f14 >= 0.0f) {
        if ((current_actor_pointer->unkAC - current_actor_pointer->y_position) < D_global_asm_80753A2C[D_global_asm_807FD584]) {
            if (D_global_asm_80753A5C[D_global_asm_807FD584] > 0.0f) {
                phi_f16 = D_global_asm_80753A5C[D_global_asm_807FD584];
            } else {
                phi_f16 = -D_global_asm_80753A5C[D_global_asm_807FD584];
            }
        }
    }
    if ((current_actor_pointer->distance_from_floor == 0.0f) && (current_actor_pointer->y_velocity < D_global_asm_8075C928)) {
        current_actor_pointer->y_velocity = D_global_asm_8075C930;
    }
    current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, phi_f14 + phi_f16, 2.0 * phi_f2);
    current_actor_pointer->unkB8 = func_global_asm_806CD898(current_actor_pointer->unkB8, sp34, phi_f2);
    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->y_rotation);
    func_global_asm_806653C0(current_actor_pointer, current_actor_pointer->unkB8, current_actor_pointer->y_velocity);
    func_global_asm_80665564(current_actor_pointer, 0);
    func_global_asm_806CC364(0);
}
*/

void func_global_asm_806CC8A8(void) {
    D_global_asm_807FD586 = 1;
}

void func_global_asm_806CC8B8(void) {
    func_global_asm_806CCB0C();
    func_global_asm_806CBE90();
    func_global_asm_806CCC54(1);
    func_global_asm_806CC970();
}

void func_global_asm_806CC8F0(void) {
    func_global_asm_806CBE90();
    func_global_asm_806CCC54(1);
    func_global_asm_806CC970();
}

void func_global_asm_806CC920(void) {
    func_global_asm_806CCC54(1);
    func_global_asm_806CC970();
}

void func_global_asm_806CC948(void) {
    func_global_asm_806CCB0C();
    func_global_asm_806CC970();
}

extern u32 D_global_asm_80744478;

void func_global_asm_806CC970(void) {
    f32 dx;
    f32 dz;
    s16 phi_a1;
    f64 phi_f2;

    func_global_asm_806CCC54(0);
    if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, current_actor_pointer->unkEE) < 0x400) {
        phi_a1 = current_actor_pointer->y_rotation;
    } else {
        phi_a1 = (current_actor_pointer->y_rotation + 0x800) & 0xFFF;
    }
    func_global_asm_80665160(current_actor_pointer, phi_a1, phi_a1);
    func_global_asm_806651FC(current_actor_pointer);
    phi_f2 = MAX(-6, -extra_player_info_pointer->unkD6 * 0.125);
    func_global_asm_80665564(current_actor_pointer, phi_f2);
    current_actor_pointer->object_properties_bitfield |= 1;
    dx = current_actor_pointer->x_position - current_actor_pointer->unk88;
    dz = current_actor_pointer->z_position - current_actor_pointer->unk90;
    extra_player_info_pointer->unk20 = (((sqrtf((dx * dx) + (dz * dz)) / D_global_asm_80744478) * 80.0) * 0.149999999999999994) / current_actor_pointer->animation_state->scale_x;
}

void func_global_asm_806CCB0C(void) { // applyActorYAccel()
    if (extra_player_info_pointer->unk50 != 0) {
        extra_player_info_pointer->unk50--;
        return;
    }
    current_actor_pointer->y_velocity += current_actor_pointer->y_acceleration;
    if (current_actor_pointer->y_velocity < current_actor_pointer->terminal_velocity) {
        current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
    }
    if (-current_actor_pointer->terminal_velocity < current_actor_pointer->y_velocity) {
        current_actor_pointer->y_velocity = -current_actor_pointer->terminal_velocity;
    }
}

void func_global_asm_806CCB94(void) {
    f32 temp_f0 = func_global_asm_806DFFA0(extra_player_info_pointer->unk4, extra_player_info_pointer->unkA, current_actor_pointer->y_rotation);

    if (temp_f0 > 0.0f) {
        func_global_asm_806CD424(current_actor_pointer->y_rotation, temp_f0, extra_player_info_pointer->unk38);
    } else {
        func_global_asm_806CD8EC();
    }
}

s32 func_global_asm_806CCC10(void) {
    switch (current_player->control_state) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            return TRUE;
        default:
            return FALSE;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CCC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CD424.s")

/*
// TODO: Progress made, tricky but doable
void func_global_asm_806CD424(s16 arg0, f32 arg1, f32 arg2) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f16;
    f32 var_f16_2;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    s16 temp_a2;
    s16 temp_t2;
    s16 var_a0;

    if (current_actor_pointer->unkB8 == 0.0f) {
        current_actor_pointer->unkEE = arg0;
    }
    temp_a2 = current_actor_pointer->unkEE;
    sp1C = 0.0f;
    if (current_actor_pointer->unk6A & 1) {
        temp_t2 = (arg0 - temp_a2) & 0xFFF;
        var_f16 = (extra_player_info_pointer->unk2C * ((extra_player_info_pointer->unk26 * 3) + 0x64)) / 400.0f;
        if (extra_player_info_pointer->unk28 != 0) {
            var_a0 = temp_t2;
            if (temp_t2 >= 0x801) {
                var_a0 = 0x1000 - temp_t2;
            }
            sp1C = (extra_player_info_pointer->unk26 * (var_a0 / 2048.0f)) / 100.0f;
        }
    } else {
        var_f16 = extra_player_info_pointer->unk2C;
    }
    sp34 = func_global_asm_80612794(temp_a2) * current_actor_pointer->unkB8;
    temp_f2 = func_global_asm_80612794(arg0) * arg1;
    var_f16_2 = var_f16;
    sp30 = temp_f2;
    if (sp1C != 0.0f) {
        if (sp34 < temp_f2) {
            var_f0 = temp_f2 - sp34;
        } else {
            var_f0 = -(temp_f2 - sp34);
        }
        var_f2 = (((var_f0 * (((extra_player_info_pointer->unk26 * D_global_asm_8075C9A0) + 100.0) / 6400.0)) - var_f16_2) * sp1C) + var_f16_2;
    } else {
        var_f2_2 = ABS(func_global_asm_80612794(arg0) * var_f16_2);
        sp24 = var_f2_2;
        if ((func_global_asm_80612790(arg0) * var_f16_2) > 0.0f) {
            var_f2 = var_f2_2;
            sp20 = func_global_asm_80612790(arg0) * var_f16_2;
        } else {
            var_f2 = var_f2_2;
            sp20 = -(func_global_asm_80612790(arg0) * var_f16_2);
        }
    }
    sp3C = func_global_asm_806CD898(sp34, sp30, var_f2);
    sp34 = func_global_asm_80612790(temp_a2) * current_actor_pointer->unkB8;
    sp30 = func_global_asm_80612790(arg0) * arg1;
    if (sp1C != 0.0f) {
        if (sp34 < sp30) {
            var_f0_2 = sp30 - sp34;
        } else {
            var_f0_2 = -(sp30 - sp34);
        }
        sp20 = (((var_f0_2 * (((extra_player_info_pointer->unk26 * D_global_asm_8075C9A8) + 100.0) / 6400.0)) - var_f16_2) * sp1C) + var_f16_2;
    }
    sp38 = func_global_asm_806CD898(sp34, sp30, sp20);
    current_actor_pointer->unkB8 = sqrtf((sp3C * sp3C) + (sp38 * sp38));
    if (arg2 < current_actor_pointer->unkB8) {
        current_actor_pointer->unkB8 = arg2;
    }
    if (current_actor_pointer->unkB8 != 0.0) {
        current_actor_pointer->unkEE = (func_global_asm_80611BB4(sp3C, sp38) * 4096.0) / D_global_asm_8075C9B0;
    }
}
*/

// boostSpeed()
f32 func_global_asm_806CD898(f32 currentSpeed, f32 desiredSpeed, f32 boostAmount) {
    if (currentSpeed < desiredSpeed) {
        currentSpeed += boostAmount;
        currentSpeed = MIN(desiredSpeed, currentSpeed);
    } else {
        currentSpeed -= boostAmount;
        currentSpeed = MAX(desiredSpeed, currentSpeed);
    }
    return currentSpeed;
}

void func_global_asm_806CD8EC(void) {
    u16 temp_v1;
    f32 phi_f0;

    if ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6A & 0x200)) {
        phi_f0 = (extra_player_info_pointer->unk30 * ((extra_player_info_pointer->unk26 * 0xF) + 0x64)) / 1600.0f;
    } else {
        phi_f0 = extra_player_info_pointer->unk30;
    }
    current_actor_pointer->unkB8 -= phi_f0;
    if (current_actor_pointer->unkB8 < 0.0f) {
        current_actor_pointer->unkB8 = 0.0f;
    }
}

s16 func_global_asm_806CD988(Actor *arg0) {
    s16 temp = D_global_asm_80750B54[arg0->control_state].unk0;
    return temp;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CD9A0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CDD24.s")

u32 func_global_asm_806CE174(Actor *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s16 sp36;
    f32 var_f0;
    s16 sp2E;
    s16 sp2C;

    sp36 = arg0->control_state;
    sp2E = extra_player_info_pointer->unk4C;
    sp2C = func_global_asm_806CD9A0(arg0, arg1, arg2, extra_player_info_pointer->unk4C, D_global_asm_807FD584);
    arg0->y_velocity = 0.0f;
    if (sp2E < 0) {
        func_global_asm_806D03BC();
    }
    if (sp2E != sp2C) {
        switch (sp2C) {
            case 0:
                func_global_asm_80614E78(arg0, 0x51);
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                sp36 = 0x5D;
                break;
            case 1:
                func_global_asm_80614EBC(arg0, 0x23);
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                sp36 = 0x5D;
                break;
            case 3:
                func_global_asm_80614E78(arg0, 0x57);
                func_global_asm_80613AF8(arg0, 0x5C, 0, 6.0f);
                if (sp2E == 4 || sp2E == 5) {
                    func_global_asm_80613A50(arg0, 2);
                }
                sp36 = 0x5E;
                break;
            case 4:
                func_global_asm_80614E78(arg0, 0x56);
                func_global_asm_80613AF8(arg0, 0x58, 0, 6.0f);
                if (sp2E == 3) {
                    switch (current_character_index[cc_player_index]) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            func_global_asm_80613A50(arg0, 4);
                            break;
                    }
                }
                if (sp2E == 5) {
                    func_global_asm_80613A50(arg0, 0xA);
                }
                sp36 = 0x5E;
                break;
            case 5:
                func_global_asm_80614E78(arg0, 0x55);
                func_global_asm_80613AF8(arg0, 0x60, 0, 6.0f);
                switch (current_character_index[cc_player_index]) {
                    case 4:
                    case 5:
                        if (sp2E == 3) {
                            func_global_asm_80613A50(arg0, 8);
                        }
                        break;
                    default:
                        if ((sp2E == 3) || (sp2E == 4)) {
                            func_global_asm_80613A50(arg0, 0);
                        }
                        break;
                }
                sp36 = 0x5E;
                break;
            case 6:
                func_global_asm_80614E78(arg0, 0x58);
                func_global_asm_80614D90(arg0);
                sp36 = 0x1F;
                current_actor_pointer->unk9C = current_actor_pointer->y_position;
                break;
        }
        extra_player_info_pointer->unk4C = sp2C;
    }
    if (extra_player_info_pointer->unk4C >= 3) {
        var_f0 = arg0->unkB8;
        var_f0 *= 0.025;
        if (extra_player_info_pointer->unk4C == 5) {
            var_f0 *= 0.6;
        }
        if (var_f0 > 1.25f) {
            var_f0 -= ((var_f0 - 1.25f) * 0.4);
        }
        if (arg0->animation_state->unk0->unk24 != 0.0f) {
            func_global_asm_80614D00(arg0, var_f0, 2.0f);
        }
    }
    return sp36;
}

s16 func_global_asm_806CE4E4(Actor *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s16 sp36;
    f32 var_f0;
    s16 sp2E;
    s16 sp2C;

    sp36 = arg0->control_state;
    sp2E = extra_player_info_pointer->unk4C;
    sp2C = func_global_asm_806CE7A0(arg0, arg1, arg2, extra_player_info_pointer->unk4C, D_global_asm_807FD584);
    arg0->y_velocity = 0.0f;
    if (sp2E < 0) {
        func_global_asm_806D0408();
    }
    if (sp2E != sp2C) {
        switch (sp2C) {
            case 0:
            case 1:
            case 2:
                func_global_asm_80614EBC(arg0, 0x150);
                func_global_asm_80614D00(arg0, 1.0f, 0.0f);
                sp36 = 0x3F;
                break;
            case 4:
                func_global_asm_80614EBC(arg0, 0x151);
                func_global_asm_80613C48(arg0, 0x163, 0.0f, 6.0f);
                if (sp2E == 5) {
                    func_global_asm_80613A50(arg0, 4);
                }
                sp36 = 0x40;
                break;
            case 5:
                func_global_asm_80614EBC(arg0, 0x152);
                func_global_asm_80613C48(arg0, 0x162, 0.0f, 6.0f);
                if (sp2E == 4) {
                    func_global_asm_80613A50(arg0, 0xC);
                }
                sp36 = 0x40;
                break;
            case 6:
                func_global_asm_80614E78(arg0, 0x1B);
                func_global_asm_80614D90(arg0);
                sp36 = 0x1E;
                current_actor_pointer->unk9C = current_actor_pointer->y_position;
                break;
        }
        extra_player_info_pointer->unk4C = sp2C;
    }
    if (extra_player_info_pointer->unk4C >= 3) {
        if (extra_player_info_pointer->unk26 == 0x64) {
            var_f0 = arg0->unkB8;
        } else {
            var_f0 = extra_player_info_pointer->unk4;
        }
        var_f0 *= 0.025;
        if (extra_player_info_pointer->unk4C == 5) {
            var_f0 *= 0.6;
        }
        if (var_f0 > 1.25f) {
            var_f0 -= ((var_f0 - 1.25f) * 0.4);
        }
        if (arg0->animation_state->unk0->unk24 != 0.0f) {
            if (extra_player_info_pointer->unk26 == 0x64) {
                func_global_asm_80614D00(arg0, var_f0, 2.0f);
            } else {
                if (var_f0 < 0.5) {
                    var_f0 = 0.5f;
                }
                func_global_asm_80614D00(arg0, var_f0, 10.0f);
            }
        }
    }
    return sp36;
}

extern f32 D_global_asm_80753170[];
extern f32 D_global_asm_807531C4[];
extern f32 D_global_asm_807531E0[];

s32 func_global_asm_806CE7A0(Actor *arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4) {
    f32 var_f0;

    var_f0 = MAX(arg1, arg2);
    if ((arg0->unk6A | arg0->unk6C) & 1) {
        switch (arg3) {
            case 0:
            case 1:
            case 2:
                if (arg2 != 0.0f) {
                    if (arg2 < D_global_asm_807531C4[arg4]) {
                        arg3 = 4;
                    } else {
                        arg3 = 5;
                    }
                }
                break;
            case 4:
                if (arg2 < D_global_asm_80753170[arg4]) {
                    arg3 = 0;
                } else if (D_global_asm_807531C4[arg4] < arg2) {
                    arg3 = 5;
                }
                break;
            case 5:
                if (var_f0 < D_global_asm_807531E0[arg4]) {
                    arg3 = 4;
                }
                break;
            default:
                if (arg1 < D_global_asm_80753170[arg4]) {
                    arg3 = 0;
                } else if (arg1 < D_global_asm_807531E0[arg4]) {
                    arg3 = 4;
                } else {
                    arg3 = 5;
                }
                break;
        }
    } else {
        arg3 = 6;
    }
    return arg3;
}

s16 func_global_asm_806CE928(Actor *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s16 sp26;
    f32 temp;
    s16 sp1E;
    s16 sp1C;

    sp26 = arg0->control_state;
    sp1E = extra_player_info_pointer->unk4C;
    sp1C = func_global_asm_806CEB44(arg1, arg2);
    if (sp1E < 0) {
        func_global_asm_806D03BC();
    }
    if (sp1E != sp1C) {
        switch (sp1C) {
            case 0:
                switch ((u32)extra_player_info_pointer->unk1AC->unk58) {
                    case 0x3D:
                    case 0x3F:
                    case 0x40:
                    case 0x41:
                    case 0x42:
                    case 0x55:
                    case 0x82:
                        func_global_asm_80614EBC(current_player, 0x1C9);
                        break;
                    default:
                        func_global_asm_80614E78(arg0, 0x2E);
                        break;
                }
                extra_player_info_pointer->unk4C = 0;
                sp26 = 0x48;
                break;
            case 1:
                switch ((u32)extra_player_info_pointer->unk1AC->unk58) {
                    case 0x3D:
                    case 0x3F:
                    case 0x40:
                    case 0x41:
                    case 0x42:
                    case 0x43:
                    case 0x55:
                    case 0x82:
                        func_global_asm_80614EBC(current_player, 0x1CA);
                        break;
                    default:
                        func_global_asm_80614E78(arg0, 0x2F);
                        break;
                }
                extra_player_info_pointer->unk4C = 1;
                sp26 = 0x49;
                break;
        }
    }
    if (extra_player_info_pointer->unk4C > 0) {
        temp = arg0->unkB8 * 0.025;
        temp = 0.25 + (temp * 0.75);
        if (arg0->animation_state->unk0->unk24 != 0) {
            func_global_asm_80614D00(arg0, temp, 2.0f);
        }
    }
    return sp26;
}

s32 func_global_asm_806CEB44(f32 arg0, f32 arg1) {
    s32 phi_v1;

    phi_v1 = extra_player_info_pointer->unk4C;
    switch (phi_v1) {
        case 0:
            if (arg1 != 0.0f) {
                phi_v1 = 1;
            }
            break;
        case 1:
            if (arg1 == 0.0f) {
                if (arg0 < D_global_asm_807532B8[D_global_asm_807FD584]) {
                    phi_v1 = 0;
                }
            }
            break;
        default:
            if (arg0 < D_global_asm_807532B8[D_global_asm_807FD584]) {
                phi_v1 = 0;
            } else {
                phi_v1 = 1;
            }
    }

    return phi_v1;
}

// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CEC04.s")

extern s16 D_global_asm_807532A8[];

/*
void func_global_asm_806CEC04(Actor *arg0) {
    f32 sp84;
    s16 temp_f0;
    f32 sp40[4][4];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 var_f2;

    switch ((u32)arg0->unk58) {
        case 0x3D:
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x55:
        case 0x82:
            sp84 = 30.0f;
            break;
        default:
            sp84 = D_global_asm_807532A8[D_global_asm_807FD584];
            break;
    }
    if (extra_player_info_pointer->unk1F0 & 0x01000000) {
        var_f2 = (current_actor_pointer->y_rotation * 0x168) / 4096;
    } else {
        var_f2 = 360.0 - func_global_asm_80665AE4((s16)arg0->x_position, (s16)arg0->z_position, (s16)current_actor_pointer->x_position, (s16)current_actor_pointer->z_position);
    }
    extra_player_info_pointer->unk80 = (var_f2 * 4095.0) / 360.0;
    guRotateF(&sp40, var_f2, 0.0f, 1.0f, 0.0f);
    guMtxXFMF(&sp40, 0, 0, sp84, &sp3C, &sp38, &sp34);
    temp_f0 = 0xF;
    extra_player_info_pointer->unk78 = (((arg0->x_position - sp3C) - current_actor_pointer->x_position) / temp_f0);
    extra_player_info_pointer->unk7C = (((arg0->z_position - sp34) - current_actor_pointer->z_position) / temp_f0);
}
*/

void func_global_asm_806CEE64(f32 arg0) {
    GlobalASMStruct61 *temp_v0;

    if (extra_player_info_pointer->unk1AC != 0) {
        temp_v0 = malloc(0x14);
        temp_v0->unk0 = &func_global_asm_806CEFBC;
        temp_v0->unk8 = arg0;
        temp_v0->unkC = current_actor_pointer;
        temp_v0->unk10 = extra_player_info_pointer->unk1AC;
        temp_v0->unk4 = 0;
        func_global_asm_80679064(temp_v0);
    }
}

void func_global_asm_806CF2EC(s32*, s32*);

void func_global_asm_806CEED8(void) {
    f32 sp44; // 44
    f32 sp40; // 40
    f32 sp3C; // 3C
    f32 sp38; // 38
    f32 sp34; // 34
    f32 sp30; // 30
    f32 d; // 2C
    f32 sp28; // 28
    s32 sp24; // 24
    s32 sp20; // 20

    func_global_asm_806CF2EC(&sp24, &sp20);
    func_global_asm_80671C0C(current_actor_pointer, sp24, &sp40, &sp38, &sp30);
    func_global_asm_80671C0C(current_actor_pointer, sp20, &sp44, &sp3C, &sp34);
    sp28 = sp3C - sp38;
    d = sqrtf(((sp34 - sp30) * (sp34 - sp30)) + ((sp44 - sp40) * (sp44 - sp40)));
    extra_player_info_pointer->unk1BC = ((0.0 - (func_global_asm_80611BB4(sp28, d) * 57.29577637f)) + 270.0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CEFBC.s")

/*
void func_global_asm_806CEFBC(Struct806CEFBC *arg0) {
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp34;
    s32 sp30;
    f32 temp_f10;
    f32 temp_f6;
    f32 temp_f8;

    func_global_asm_806CF2EC(&sp34, &sp30);
    func_global_asm_80671C0C(arg0->unk4, sp34, &sp60, &sp58, &sp50);
    func_global_asm_80671C0C(arg0->unk4, sp30, &sp64, &sp5C, &sp54);
    temp_f10 = ((((sp64 + sp60) / 2.0f) - arg0->unk8->x_position) * arg0->unk0) + arg0->unk8->x_position;
    temp_f6 = ((((sp5C + sp58) / 2.0f) - arg0->unk8->y_position) * arg0->unk0) + arg0->unk8->y_position;
    temp_f8 = ((((sp54 + sp50) / 2.0f) - arg0->unk8->z_position) * arg0->unk0) + arg0->unk8->z_position;
    func_global_asm_8067A70C(arg0->unk4, arg0->unk8, temp_f10, temp_f6, temp_f8, 2, 1);
}
*/

void func_global_asm_806CF0D0(void) {
    GlobalASMStruct62 *temp_v0;

    if (extra_player_info_pointer->unk1AC != 0) {
        temp_v0 = malloc(0x14);
        temp_v0->unk0 = &func_global_asm_806CF138;
        temp_v0->unk8 = current_actor_pointer;
        temp_v0->unkC = extra_player_info_pointer->unk1AC;
        temp_v0->unk4 = 0;
        func_global_asm_80679064(temp_v0);
    }
}

// progress made, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CF138.s")

/*
void func_global_asm_806CF138(Struct806CF138 *arg0) {
    // TODO: This could be a matrix
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 pad2;
    f32 sp54;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp_f14;
    s32 sp30;
    s32 sp2C;

    func_global_asm_806CF2EC(&sp30, &sp2C);
    func_global_asm_80671C0C(arg0->unk0, sp30, &sp70, &sp68, &sp60);
    func_global_asm_80671C0C(arg0->unk0, sp2C, &sp74, &sp6C, &sp64);
    sp5C = (sp6C - sp68);
    temp_f14 = (sp74 - sp70);
    sp54 = func_global_asm_806118FC(sp5C / sqrtf(((sp64 - sp60) * (sp64 - sp60)) + ((temp_f14 * temp_f14) + (sp5C * sp5C)))) * D_global_asm_8075CBF0;
    sp48 = func_global_asm_80612794(arg0->unk0->y_rotation) * 50.0f;
    sp4C = func_global_asm_80612790(arg0->unk0->y_rotation) * 50.0f;
    sp40 = (sp74 - sp70);
    sp44 = (sp64 - sp60);
    sp3C = (sp44 * sp4C) + (sp48 * sp40);
    sp38 = sqrtf((sp4C * sp4C) + (sp48 * sp48));
    func_global_asm_8067AA58(arg0->unk0, arg0->unk4, sp54, D_global_asm_8075CBF8 - (func_global_asm_80611850(sp3C / (sp38 * sqrtf((sp44 * sp44) + (sp40 * sp40)))) * D_global_asm_8075CC00));
}
*/

void func_global_asm_806CF2EC(s32 *arg0, s32 *arg1) {
    s32 var_v0;
    u16 temp_v1;

    var_v0 = 0;
    if (current_actor_pointer->unk58 == ACTOR_CHUNKY) {
        switch (extra_player_info_pointer->unk1B8) {
            case 0x82:
                *arg0 = 0x13;
                *arg1 = 0x14;
                var_v0 = 1;
                break;
            case 0x3D:
            case 0x3F:
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x55:
                *arg0 = 0x12;
                *arg1 = 0x11;
                var_v0 = 1;
                break;
        }
    }
    if (var_v0 == 0) {
        *arg0 = 2;
        *arg1 = 3;
    }
}

void func_global_asm_806CF398(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;

    if (arg0->interactable & 1) {
        PaaD = arg0->PaaD;
        if (PaaD->unk1AC) {
            func_global_asm_8067A784(current_actor_pointer, PaaD->unk1AC, current_player->y_rotation, D_global_asm_80753428[D_global_asm_807FD584], D_global_asm_8075340C[D_global_asm_807FD584]);
            PaaD->unk1AC = NULL;
            PaaD->unk1B0 = NULL;
        }
    }
}

void func_global_asm_806CF42C(Actor *arg0) {
    PlayerAdditionalActorData *PaaD;

    if (arg0->interactable & 1) {
        PaaD = arg0->PaaD;
        if (PaaD->unk1AC != 0) {
            func_global_asm_80679200(PaaD->unk1AC, arg0, 8, 0, 0, 0);
        } else if (PaaD->unk1B0 != 0) {
            func_global_asm_80679200(PaaD->unk1B0, arg0, 8, 0, 0, 0);
        }
        PaaD->unk1AC = NULL;
        PaaD->unk1B0 = NULL;
    }
}

void func_global_asm_806CF4B8(Actor *arg0) {
    s32 i;
    PlayerAdditionalActorData *PaaD;

    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist != 0) {
            PaaD = character_change_array[i].player_pointer->PaaD;
            if ((arg0 == PaaD->unk1AC && PaaD->unk1AC != 0)
                || (arg0 == PaaD->unk1B0 && PaaD->unk1B0 != 0)) {
                PaaD->unk1AC = 0;
                PaaD->unk1B0 = 0;
                func_global_asm_806CFF9C(character_change_array[i].player_pointer);
            }
        }
    }
}

void func_global_asm_806CF580(void) {
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        extra_player_info_pointer->unk84 = object_timer;
        extra_player_info_pointer->unkD0 = object_timer;
    }
    if (current_character_index[cc_player_index] == 1) {
        if ((current_actor_pointer->control_state == 0x36) && (extra_player_info_pointer->unk0 != 0x36)) {
            func_global_asm_806883F4(current_actor_pointer, 1, 0, 6.0f);
        }
        if (current_actor_pointer->control_state == 0x36) {
            func_global_asm_80688370(current_actor_pointer, 0, 0.5f);
            func_global_asm_806883C8(current_actor_pointer, 0, 0);
            func_global_asm_8068839C(current_actor_pointer, 0, 0);
            func_global_asm_806884E4(current_actor_pointer, 0);
            func_global_asm_8068848C(current_actor_pointer, 0, 4);
            func_global_asm_8068842C(current_actor_pointer, 0, 2);
            func_global_asm_80688370(current_actor_pointer, 1, 0.5f);
            func_global_asm_806883C8(current_actor_pointer, 1, 0);
            func_global_asm_8068839C(current_actor_pointer, 1, 0);
            func_global_asm_806884E4(current_actor_pointer, 1);
            func_global_asm_8068848C(current_actor_pointer, 1, 4);
            func_global_asm_8068842C(current_actor_pointer, 1, 2);
        }
        if (current_actor_pointer->control_state != 0x36) {
            if (extra_player_info_pointer->unk0 == 0x36) {
                extra_player_info_pointer->unk84 = 0;
            }
        }
    }
    if ((current_actor_pointer->control_state != 0x36)
        && (func_global_asm_8072881C(0, &extra_player_info_pointer->unk84) != 0)
        && (((current_character_index[cc_player_index] == 1))
            || ((cc_number_of_players == 1) && (current_character_index[cc_player_index] == 3)))) {
        func_global_asm_8072881C(0x81, &extra_player_info_pointer->unk84);
    }
    if (((current_actor_pointer->control_state == 0x4F) || (current_actor_pointer->control_state == 0x7F))
        && (D_global_asm_80750AD0 == 0)
        && ((extra_player_info_pointer->unkD0 + 9) < (u32)object_timer)
        && (((func_global_asm_806119A0() % 2500U) / 200) == 0)) {
        func_global_asm_8071498C(&func_global_asm_80718BF4);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714C08(&D_global_asm_8071FC40, 0.0f, current_actor_pointer, 4, 0);
        extra_player_info_pointer->unkD0 = object_timer;
    }
}

void func_global_asm_806CF878(void) {
    if ((object_timer & 3) == 0) {
        if ((current_actor_pointer->control_state_progress >= 5) && (current_actor_pointer->y_velocity > 30.0f)) {
            func_global_asm_80714998(2);
            func_global_asm_807149B8(1);
            func_global_asm_8071498C(&func_global_asm_80716FB4);
            func_global_asm_80714CC0(&D_global_asm_8071FB08, 0.8f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        }
    }
}

void func_global_asm_807195D4(void);
extern s32 D_global_asm_8071FF40;

void func_global_asm_806CF918(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        func_global_asm_8071498C(&func_global_asm_807195D4);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(i * 0x28);
        func_global_asm_807149FC(0x45);
        func_global_asm_80714C08(&D_global_asm_8071FF40, 0.05f, current_actor_pointer, 6, 2);
    }
}

// Something to do with ledge grabs
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CF9CC.s")

extern f32 D_global_asm_80753E10[];
extern s16 D_global_asm_80753E00[];

/*
// Kinda close
void func_global_asm_806CF9CC(void) {
    f32 sp3C;
    u8 sp3B;
    s16 sp38;
    s16 sp36;
    u8 sp34;
    u8 sp33;
    u8 temp_v1;
    u8 var_t0;
    u8 var_v1;

    if (!(D_global_asm_807FBB64 & 0x20000) && (current_actor_pointer->unkFC != 0) && (extra_player_info_pointer->unk8C == 0) && !(current_actor_pointer->unk6A & 1) && (extra_player_info_pointer->unkE8 != 0)) {
        if ((current_map == MAP_FUNGI_DOGADON) || (var_t0 = 0, (current_map == MAP_AZTEC_DOGADON))) {
            var_t0 = 1;
        }
        sp33 = var_t0;
        temp_v1 = func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->y_rotation) == 0;
        if ((temp_v1) || !(D_global_asm_80753E10[D_global_asm_807FD584] < current_actor_pointer->unkB8) || (var_t0 != 0)) {
            if (var_t0 != 0) {
                
            }
            sp33 = var_t0;
            sp3B = func_global_asm_806CFC90(current_actor_pointer, &sp3C, temp_v1, 0.0);
            func_global_asm_80666AC4(&sp38, &sp36);
            var_v1 = 0;
            if ((sp3B != 0) && (current_actor_pointer->y_velocity < 0.0) && (sp36 >= 0x385)) {
                sp34 = 0;
                var_v1 = sp34;
                if (func_global_asm_80666AEC() != 0) {
                    if ((current_actor_pointer->y_position - current_actor_pointer->floor) > 15.0f) {
                        if (sp33 != 0) {
                            if (((D_global_asm_80753E00[D_global_asm_807FD584] + current_actor_pointer->y_position) < (sp3C + 15.0f)) && (((sp3C - D_global_asm_80753E00[D_global_asm_807FD584]) - current_actor_pointer->y_position) < 80.0f)) {
                                var_v1 = 1;
                            }
                        } else {
                            if (((D_global_asm_80753E00[D_global_asm_807FD584] + current_actor_pointer->y_position) < (sp3C - 5.0f)) && (((sp3C - D_global_asm_80753E00[D_global_asm_807FD584]) - current_actor_pointer->y_position) < 15.0f)) {
                                var_v1 = 1;
                            }
                        }
                    }
                }
            }
            if ((var_v1 != 0) && (func_global_asm_806EB0C0(0xA, NULL, cc_player_index) != 0)) {
                extra_player_info_pointer->unkF0_f32 = sp3C;
            }
        }
    }
}
*/

u8 func_global_asm_806CFC90(Actor *arg0, s32 arg1, u8 arg2, f32 arg3) {
    f32 sp34;
    f32 temp_a3;
    s16 phi_a3;
    u8 temp_v0;

    phi_a3 = arg0->y_rotation;
    if (!arg2) {
        phi_a3 = (phi_a3 + 0x800) & 0xFFF;
    }
    sp34 = (func_global_asm_80612794(phi_a3) * arg3);
    temp_a3 = (func_global_asm_80612790(phi_a3) * arg3);
    temp_v0 = func_global_asm_8066635C(
        arg0,
        arg0->x_position + sp34,
        arg0->y_position + 30.0f,
        arg0->z_position + temp_a3,
        arg1
    );

    arg0->unk78 = func_global_asm_80666AE0();
    return temp_v0;
}

void func_global_asm_806CFD68() {
    if (current_actor_pointer->y_velocity < 0.0f) {
        func_global_asm_806CFE7C();
    }
}

void func_global_asm_806CFDA8() {
    if (current_actor_pointer->y_velocity < 0.0f) {
        current_actor_pointer->y_acceleration = D_global_asm_80753700[D_global_asm_807FD584];
    }
}

void func_global_asm_806CFDEC() {
    if (current_actor_pointer->y_velocity < 0.0f) {
        current_actor_pointer->y_acceleration = D_global_asm_80753658[D_global_asm_807FD584];
    }
}

void func_global_asm_806CFE30() {
    if (current_actor_pointer->y_velocity < 0.0f) {
        current_player->y_acceleration = D_global_asm_80753754[D_global_asm_807FD584];
    }
}

void func_global_asm_806CFE7C() {
    current_player->y_acceleration = D_global_asm_80753578[D_global_asm_807FD584];
}

void func_global_asm_806CFEA4() {
    current_player->y_acceleration = D_global_asm_80753594[D_global_asm_807FD584];
}

void func_global_asm_806CFECC() {
    current_player->y_acceleration = D_global_asm_807535B0[D_global_asm_807FD584];
}

void func_global_asm_806CFEF4() {
    current_player->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
}

void func_global_asm_806CFF1C(Actor *arg0) {
    current_actor_pointer->y_velocity = 0.0f;
    func_global_asm_80614E78(arg0, 0x1B);
    func_global_asm_80614D90(arg0);
    current_actor_pointer->unk9C = current_actor_pointer->y_position;
    if (extra_player_info_pointer->unk8C != 0) {
        arg0->control_state = 0x1F;
        arg0->control_state_progress = 0;
    } else {
        arg0->control_state = 0x1E;
        arg0->control_state_progress = 0;
    }
}

void func_global_asm_806CFF9C(Actor *arg0) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    Actor *vehicle;
    s32 temp;

    arg0->unk6A &= 0xFFDF;
    PaaD->unk4C = -1;
    PaaD->unk10C = 0;

    if (arg0->noclip_byte == 1) {
        func_global_asm_806C8D20(arg0);
    }

    if (D_global_asm_807FBB64 & 0x80000) {
        vehicle = PaaD->vehicle_actor_pointer;
        if ((vehicle) && (vehicle->unk58 == ACTOR_MINECART)) {
            func_global_asm_806D0150(arg0);
            return;
        }
    }

    if (current_character_index[cc_player_index] == 7) {
        arg0->control_state = 0x7E;
        arg0->control_state_progress = 0;
        return;
    }

    if ((PaaD->unk1F0 & 0x20) && (cc_number_of_players == 1)) {
        arg0->control_state = func_global_asm_806CE4E4(arg0, arg0->unkB8, PaaD->unk4, 1);
        arg0->control_state_progress = 0;
        if (arg0->control_state == 0x3F) {
            arg0->control_state_progress = 1;
        }
        return;
    }

    if (PaaD->unk1AC) {
        arg0->control_state = func_global_asm_806CE928(arg0, arg0->unkB8, PaaD->unk4, 1);
        arg0->control_state_progress = 0;
    } else {
        if (PaaD->unk8C != 0) {
            temp = func_global_asm_806CE174(arg0, arg0->unkB8, PaaD->unk4, 1);
            if (arg0->control_state != 2) {
                arg0->control_state = temp;
                arg0->control_state_progress = 0;
            }
        } else {
            temp = func_global_asm_806CDD24(arg0, arg0->unkB8, PaaD->unk4, 1);
            if (arg0->control_state != 2) {
                arg0->control_state = temp;
                arg0->control_state_progress = 0;
            }
        }
    }
}

void func_global_asm_806D0150(Actor *arg0) {
    arg0->unk6A &= ~0x20;
    extra_player_info_pointer->unk4C = -1;
    extra_player_info_pointer->unk10C = 0;
    func_global_asm_80614E78(arg0, 0x7A);
    arg0->control_state = 7;
    arg0->control_state_progress = 0;
}

void func_global_asm_806D01AC(void) {
    extra_player_info_pointer->unk48 = D_global_asm_80753328[D_global_asm_807FD584];
    extra_player_info_pointer->unk2C = D_global_asm_807532F0[D_global_asm_807FD584];
    extra_player_info_pointer->unk30 = D_global_asm_8075330C[D_global_asm_807FD584];
    extra_player_info_pointer->unk34 = D_global_asm_807532B8[D_global_asm_807FD584];
    extra_player_info_pointer->unk38 = D_global_asm_807532D4[D_global_asm_807FD584];
}

void func_global_asm_806D024C(void) {
    extra_player_info_pointer->unk48 = D_global_asm_8075326C[D_global_asm_807FD584];
    extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584];
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    extra_player_info_pointer->unk34 = D_global_asm_80753170[D_global_asm_807FD584];
    if (extra_player_info_pointer->unk8C != 0) {
        extra_player_info_pointer->unk38 = D_global_asm_80753338[D_global_asm_807FD584];
        return;
    }
    if ((extra_player_info_pointer->unk1F0 & 0x20) || (is_autowalking == 3)) {
        if (current_map == MAP_FUNGI) {
            extra_player_info_pointer->unk38 = 200.0f;
        } else {
            extra_player_info_pointer->unk38 = D_global_asm_80753218[D_global_asm_807FD584];
        }
    } else {
        extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
    }
}

void func_global_asm_806D0378(void) {
    current_player->y_acceleration = D_global_asm_80753578[D_global_asm_807FD584];
    extra_player_info_pointer->unk50 = 0;
    extra_player_info_pointer->unk28 = 1;
}

void func_global_asm_806D03BC(void) {
    if (extra_player_info_pointer->unk1AC != 0) {
        func_global_asm_806D01AC();
    } else {
        func_global_asm_806D024C();
    }
    func_global_asm_806D0378();
}

void func_global_asm_806D0408(void) {
    func_global_asm_806D024C();
    func_global_asm_806D0378();
}

void func_global_asm_806D0430(f32 arg0) {
    if (arg0 != 0.0f) {
        D_global_asm_80750FA8 = arg0;
        return;
    }
    D_global_asm_80750FA8 = 0.3f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D0468.s")

/*
void func_global_asm_806D0468(Actor *arg0, u8 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f18;
    s32 var_v0;
    PlayerAdditionalActorData *PaaD;
    PlayerAdditionalActorData *var_v1;

    PaaD = arg0->PaaD;
    PaaD->unk1DC = D_global_asm_8075CC70;
    PaaD->unk1D8 = D_global_asm_8075CC74;
    switch (arg1) {
        case 0:
            temp_f0 = D_global_asm_8075CC78;
            PaaD->unk1C0 = temp_f0;
            PaaD->unk1C4 = temp_f0;
            PaaD->unk1C8 = temp_f0;
            break;
        case 2:
            PaaD->unk1C0 = D_global_asm_80750FA8;
            PaaD->unk1C4 = D_global_asm_80750FA8;
            PaaD->unk1C8 = D_global_asm_80750FA8;
            break;
        default:
            PaaD->unk1C0 = D_global_asm_8075CC7C;
            PaaD->unk1C4 = D_global_asm_8075CC7C;
            PaaD->unk1C8 = D_global_asm_8075CC7C;
            if (character_change_array[PaaD->unk1A4].unk2C0 == 0) {
                PaaD->unk1DC = D_global_asm_8075CC80;
                PaaD->unk1D8 = D_global_asm_8075CC84;
            }
            break;
    }
    if (arg1 != 1) {
        var_v0 = 0;
        var_v1 = PaaD;
        if (cc_number_of_players == 1) {
            var_f18 = var_v1->unk1C0;
            if (var_v0 != 8) {
                do {
                    var_v1->unk1CC = var_f18;
                    var_v1 += 4;
                    (arg0->animation_state + var_v0)->scale_x = var_f18;
                    var_f18 = var_v1->unk1C0;
                    var_v0 += 4;
                } while (var_v0 != 8);
            }
            var_v1->unk1CC = var_f18;
            (arg0->animation_state + var_v0)->scale_x = var_f18;
        }
    }
    character_change_array[PaaD->unk1A4].unk2C0 = arg1;
    character_change_array[PaaD->unk1A4].unk2C1 = 1;
    PaaD->unk1E4 = 0;
    if ((arg1 == 1) || (cc_number_of_players >= 2)) {
        temp_f0_2 = PaaD->unk1CC;
        temp_f2 = PaaD->unk1C0;
        if (temp_f0_2 < temp_f2) {
            var_f12 = temp_f2 - temp_f0_2;
        } else {
            var_f12 = -(temp_f2 - temp_f0_2);
        }
        temp_f0_3 = var_f12 / PaaD->unk1D8;
        if (temp_f0_3 != 0.0f) {
            PaaD->unk1E0 = PaaD->unk1DC / temp_f0_3;
        } else {
            PaaD->unk1E0 = D_global_asm_8075CC88;
        }
    }
    func_global_asm_8062217C(PaaD->unk104, 2);
}
*/

void func_global_asm_806D06A0(void) {
    if (extra_player_info_pointer->unk1CC < extra_player_info_pointer->unk1C0) {
        extra_player_info_pointer->unk1CC += extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D0 += extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D4 += extra_player_info_pointer->unk1D8;
        if (extra_player_info_pointer->unk1C0 < extra_player_info_pointer->unk1CC) {
            extra_player_info_pointer->unk1CC = extra_player_info_pointer->unk1C0;
            extra_player_info_pointer->unk1D0 = extra_player_info_pointer->unk1C4;
            extra_player_info_pointer->unk1D4 = extra_player_info_pointer->unk1C8;
        }
    } else {
        extra_player_info_pointer->unk1CC -= extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D0 -= extra_player_info_pointer->unk1D8;
        extra_player_info_pointer->unk1D4 -= extra_player_info_pointer->unk1D8;
        if (extra_player_info_pointer->unk1CC < extra_player_info_pointer->unk1C0) {
            extra_player_info_pointer->unk1CC = extra_player_info_pointer->unk1C0;
            extra_player_info_pointer->unk1D0 = extra_player_info_pointer->unk1C4;
            extra_player_info_pointer->unk1D4 = extra_player_info_pointer->unk1C8;
        }
    }
    if (extra_player_info_pointer->unk1C0 == extra_player_info_pointer->unk1CC) {
        current_actor_pointer->animation_state->scale_x = extra_player_info_pointer->unk1CC;
        current_actor_pointer->animation_state->scale_y = extra_player_info_pointer->unk1D0;
        current_actor_pointer->animation_state->scale_z = extra_player_info_pointer->unk1D4;
    } else {
        current_actor_pointer->animation_state->scale_x = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * 0.11) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1CC;
        current_actor_pointer->animation_state->scale_y = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * 0.235199999999999992) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1D0;
        current_actor_pointer->animation_state->scale_z = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * 0.17599999999999999) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1D4;
        extra_player_info_pointer->unk1DC -= extra_player_info_pointer->unk1E0;
        if (extra_player_info_pointer->unk1DC < 0.0) {
            extra_player_info_pointer->unk1DC = 0.0f;
        }
        extra_player_info_pointer->unk1E4++;
    }
}

s32 func_global_asm_806D0964(s32 arg0, u8 playerIndex) {
    s16 actorBehaviourIndex = character_change_array[playerIndex].player_pointer->unk58;
    if (actorBehaviourIndex != ACTOR_CHUNKY) {
        if ((actorBehaviourIndex == ACTOR_RAMBI) && (arg0 & 2)) {
            return TRUE;
        }
    } else {
        if ((arg0 & 1) && (character_change_array[playerIndex].unk2C0 != 1)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_global_asm_806D09E8(Actor *arg0) {
    if ((arg0->unk58 == ACTOR_LANKY)
        && (((arg0->control_state == 0x3F)) || (arg0->control_state == 0x40))
        && !(D_global_asm_807FBB68 & 0x40)
        && !func_global_asm_80666A88()) {
        arg0->unkD1 = 0x10;
    }
}

void func_global_asm_806D0A54(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1) {
        arg0->object_properties_bitfield |= 4;
    } else {
        arg0->object_properties_bitfield &= ~4;
    }
}

void func_global_asm_806D0A84(void) {
    AAD_global_asm_806D0A84 *temp_a3;
    Actor *sp30;
    f32 sp2C;
    ActorAnimationState *temp_v0;
    f32 temp_f10;
    f32 var_f0;

    temp_a3 = current_actor_pointer->additional_actor_data;
    sp30 = temp_a3->unk4;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80614EBC(current_actor_pointer, temp_a3->unk0);
        current_actor_pointer->object_properties_bitfield |= 0x400;
        current_actor_pointer->unk168 = (rand() >> 0xF) % 4096;
    }
    temp_v0 = current_actor_pointer->animation_state;
    if (temp_v0 != NULL) {
        var_f0 = temp_v0->scale_y;
    } else {
        var_f0 = 0.15f;
    }
    sp2C = var_f0 * 6.66666666999999968;
    if ((func_global_asm_8067AF44(sp30) == 0) || (sp30->unk54 != temp_a3->unk8)) {
        deleteActor(current_actor_pointer);
        return;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (sp30->animation_state->unk64 != temp_a3->unkC) {
                func_global_asm_80614EBC(current_actor_pointer, temp_a3->unk2);
            } else {
                func_global_asm_8067B238(current_actor_pointer, sp30, current_actor_pointer->animation_state->scale_x);
                current_actor_pointer->y_position += temp_a3->unk10;
            }
            break;
        case 1:
            current_actor_pointer->y_velocity = current_actor_pointer->y_velocity + 0.2;
            current_actor_pointer->y_position += sp2C * current_actor_pointer->y_velocity;
            break;
        case 2:
            current_actor_pointer->y_velocity = current_actor_pointer->y_velocity - 0.2;
            current_actor_pointer->y_position += sp2C * current_actor_pointer->y_velocity;
            break;
        case 3:
            current_actor_pointer->unk168 += 0x28;
            current_actor_pointer->unk168 &= 0xFFF;
            if (current_actor_pointer->unkB8 < 1.2) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 + 0.15;
            }
            temp_f10 = current_actor_pointer->unkB8 * sp2C;
            current_actor_pointer->x_position += temp_f10 * func_global_asm_80612794(current_actor_pointer->unk168);
            current_actor_pointer->z_position += temp_f10 * func_global_asm_80612790(current_actor_pointer->unk168);
            if (current_actor_pointer->y_velocity < 2.5) {
                current_actor_pointer->y_velocity = current_actor_pointer->y_velocity + 0.2;
            }
            current_actor_pointer->y_position += sp2C * current_actor_pointer->y_velocity;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

u8 func_global_asm_806D0DE4(Actor *arg0, Actor *arg1) {
    s32 var_a2;
    u8 var_v0;
    u8 var_v1;

    var_v0 = 1;
    var_v1 = 1;
    var_a2 = 1;
    if (cc_number_of_players < 2 || arg0->interactable & 4 || arg1->interactable & 4) {
        return 0;
    }
    if (arg0->interactable & 1) {
        PlayerAdditionalActorData *PaaD = arg0->PaaD;
        var_v0 = character_change_array[PaaD->unk1A4].unk2C0;
    }
    if (arg1->interactable & 1) {
        PlayerAdditionalActorData *PaaD = arg1->PaaD;
        var_v1 = character_change_array[PaaD->unk1A4].unk2C0;
        var_a2 = arg1->control_state != 0x7C;
    }
    return var_v0 < var_v1 && var_a2;
}

void func_global_asm_806D0EBC(s32 arg0) {
    f32 phi_f12;
    f32 phi_f0;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f12 = D_global_asm_8075388C[D_global_asm_807FD584];
    } else {
        phi_f12 = D_global_asm_807538C8[D_global_asm_807FD584];
    }
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f0 = D_global_asm_8075387C[D_global_asm_807FD584];
    } else {
        phi_f0 = D_global_asm_807538B8[D_global_asm_807FD584];
    }
    if ((current_actor_pointer->unkAC - current_actor_pointer->floor) < phi_f0) {
        func_global_asm_806EB0C0(2, NULL, cc_player_index);
        return;
    }
    if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + phi_f12)) {
        func_global_asm_80608528(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
        current_actor_pointer->y_position = current_actor_pointer->unkAC - phi_f12;
        current_actor_pointer->y_velocity = 0.0f;
        func_global_asm_80614E78(current_actor_pointer, 0x3D);
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
        current_actor_pointer->control_state = 0x4E;
        current_actor_pointer->control_state_progress = 0;
    }
}

// TODO: Can we simplify this?
s16 func_global_asm_806D1080(f32 arg0, f32 arg1) {
    return (s16)((s16)((func_global_asm_80611BB4(arg0, arg1) * 4096.0f) / 6.283185482f) - 0x400) & 0xFFF;
}

// TODO: Can we simplify this?
s32 func_global_asm_806D10D0(Actor *arg0) {
    s32 phi_v1;

    phi_v1 = TRUE;
    if ((arg0->interactable & 1) && (D_global_asm_80750B54[arg0->control_state].unk0 & 0x400)) {
        phi_v1 = FALSE;
    }
    return phi_v1;
}

void func_global_asm_806D1110(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806DF6D4(0xB);
    current_player->unkB8 = extra_player_info_pointer->unk4;
    current_player->unkEE = extra_player_info_pointer->unkA;
    current_player->y_rotation = extra_player_info_pointer->unkA;
    func_global_asm_806CC8F0();
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & (Z_TRIG | U_CBUTTONS | D_CBUTTONS))) {
        func_global_asm_806CFF9C(current_actor_pointer);
        func_global_asm_806C8D20(current_actor_pointer);
    } else {
        current_actor_pointer->noclip_byte = 1;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D11FC(void) {
    if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + 4.5f)) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC - 4.5f;
    }
}

void func_global_asm_806D1238(void) {
    func_global_asm_806DF6D4(0x66);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1270(void) {

}

void func_global_asm_806D1278(void) {
    func_global_asm_806DF6D4(1);
    // TODO: Proper bitfield syntax
    if ((extra_player_info_pointer->unk1F0 << 0xF) >= 0) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D12CC(void) {
    current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, 50.0f, 4.0f);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk24 = 0;
            extra_player_info_pointer->unk38 = 100.0f;
            func_global_asm_806DF6D4(0x67);
            func_global_asm_806CC8F0();
            current_actor_pointer->control_state_progress += 1;
            break;
        case 1:
            func_global_asm_806CC8F0();
            if ((current_actor_pointer->unkB8 > 10.0f) && (current_actor_pointer->animation_state->unk64 != 0x317)) {
                func_global_asm_80614EBC(current_actor_pointer, 0x317);
            } else if ((current_actor_pointer->unkB8 == 0.0f) && (current_actor_pointer->animation_state->unk64 != 0x314)) {
                func_global_asm_80614EBC(current_actor_pointer, 0x314);
            }
            func_global_asm_806DF6D4(0x67);
            break;
    }
    func_global_asm_806D11FC();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1420(void) {
    extra_player_info_pointer->unk24 = 0;
    if (current_actor_pointer->control_state_progress == 0) {
        extra_player_info_pointer->unk48 = 0xA;
        current_actor_pointer->y_acceleration = -8.0f;
        current_actor_pointer->z_rotation = func_global_asm_806D1080(current_actor_pointer->unkB8, current_actor_pointer->y_velocity);
        func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x32);
        func_global_asm_806DF494(&current_actor_pointer->z_rotation, func_global_asm_806D1080(current_actor_pointer->unkB8, current_actor_pointer->y_velocity), 0xA);
        func_global_asm_806DF6D4(0x6A);
        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
        func_global_asm_806CC948();
    }
    if (((current_actor_pointer->y_position + 4.0f) < current_actor_pointer->unkAC)
        && (current_actor_pointer->y_velocity < 0.0f)) {
        current_actor_pointer->control_state = 0x7F;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk1C = 2;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1568(void) {
    f64 temp_f0;
    f64 temp_f2;
    f32 temp;

    extra_player_info_pointer->unk24++;
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x4C);
            temp = (f64)-current_actor_pointer->y_velocity * 0.125f;
            current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, 0.0f, temp);
            if (extra_player_info_pointer->unk24 >= 6) {
                if ((current_actor_pointer->unkB8 != 0.0f) || (extra_player_info_pointer->unk10 != 0)) {
                    current_actor_pointer->control_state_progress = 3;
                } else {
                    current_actor_pointer->control_state_progress = 2;
                }
                current_actor_pointer->animation_state->unk78 &= -0x4001;
            }
            func_global_asm_806CC5DC();
            break;
        case 1:
            func_global_asm_806DF494(&current_actor_pointer->z_rotation, func_global_asm_806D1080(current_actor_pointer->unkB8, current_actor_pointer->y_velocity), 0x32);
            extra_player_info_pointer->unk38 = 500;
            func_global_asm_806DF6D4(0x57);
            func_global_asm_806CC638(0.0f);
            if (extra_player_info_pointer->unk10 == 0) {
                current_actor_pointer->control_state_progress = 3;
            }
            break;
        case 2:
            func_global_asm_806DF6D4(0x55);
            func_global_asm_806CC638(0);
            if (current_actor_pointer->control_state == 0x7F) {
                if (current_actor_pointer->unkB8 != 0) {
                    extra_player_info_pointer->unk18 = 0;
                    current_actor_pointer->control_state_progress = 3;
                } else {
                    if (extra_player_info_pointer->unk50 != 0) {
                        extra_player_info_pointer->unk50--;
                        if (extra_player_info_pointer->unk50 == 0) {
                            func_global_asm_80614EBC(current_actor_pointer, 0x315);
                        }
                    }
                }
                if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + 4.0f)) {
                    current_actor_pointer->control_state = 0x7E;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            break;
        case 3:
            func_global_asm_806DF6D4(0x56);
            func_global_asm_806CC638(0);
            temp_f0 = current_actor_pointer->unkB8 / 200.0;
            temp_f2 = current_actor_pointer->y_velocity / 200.0;
            func_global_asm_80614D00(current_actor_pointer, sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)), 5);
            if ((current_actor_pointer->unkB8 == 0.0f) || (extra_player_info_pointer->unk18 != 0)) {
                extra_player_info_pointer->unk50 = D_global_asm_80753A78[D_global_asm_807FD584];
                func_global_asm_80614D00(current_actor_pointer, 0.5f, extra_player_info_pointer->unk50);
                current_actor_pointer->control_state_progress = 2;
            }
            if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + 4)) {
                func_global_asm_80608528(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
                if (current_actor_pointer->y_velocity > 150) {
                    current_actor_pointer->control_state = 0x82;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80614EBC(current_actor_pointer, 0);
                } else {
                    current_actor_pointer->control_state = 0x7E;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D19A8(void) {
    current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, 50.0f, 4.0f);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk48 = 0x50;
            func_global_asm_806DF6D4(0x68);
            func_global_asm_806CD8EC();
            func_global_asm_806CC970();
            break;
        case 1:
            extra_player_info_pointer->unk68 = 200.0f;
            extra_player_info_pointer->unk2C = 40.0f;
            func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
            func_global_asm_806DF6D4(0x68);
            func_global_asm_806CC970();
            break;
        case 2:
            func_global_asm_806DF6D4(0x68);
            func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk4, extra_player_info_pointer->unk68);
            func_global_asm_806CC970();
            break;
        case 3:
            func_global_asm_806DF6D4(0x68);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + 4.0f)) {
                current_actor_pointer->control_state = 0x7E;
                current_actor_pointer->control_state_progress = 0;
            } else {
                current_actor_pointer->control_state = 0x7F;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
    }
    func_global_asm_806D11FC();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1B60(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x69);
            func_global_asm_806CD8EC();
            func_global_asm_806CC970();
            extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            break;
        case 1:
            extra_player_info_pointer->unk2C = 40.0f;
            extra_player_info_pointer->unk10 = 0xA;
            extra_player_info_pointer->unk38 = 200.0f;
            func_global_asm_806DF6D4(0x69);
            func_global_asm_806CC638(0);
            break;
        case 2:
            func_global_asm_806DF6D4(0x69);
            func_global_asm_806CD424(current_actor_pointer->y_rotation,
                        extra_player_info_pointer->unk4,
                        extra_player_info_pointer->unk68);
            func_global_asm_806CC970();
            break;
        case 3:
            func_global_asm_806DF6D4(0x69);
            func_global_asm_806CC920();
            if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + 4.0f)) {
                current_actor_pointer->control_state = 0x7E;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614EBC(current_actor_pointer, 0x317);
            } else {
                current_actor_pointer->control_state = 0x7F;
                current_actor_pointer->control_state_progress = 3;
                func_global_asm_80614EBC(current_actor_pointer, 0x318);
                extra_player_info_pointer->unk38 = 300.0f;
                extra_player_info_pointer->unk10 = 0xF;
            }
            break;
    }
    func_global_asm_806D11FC();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1D3C() {
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806DF6D4(0x65);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1D84(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1DEC(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    func_global_asm_806CC8B8();
    if ((func_global_asm_80629148()) ||
        (current_actor_pointer->control_state_progress == 1) ||
        (--extra_player_info_pointer->unk23C == 0) // TODO: Janky syntax
    ) {
        func_global_asm_805FF8F8();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1E90(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806CC8B8();
    if (current_actor_pointer->control_state_progress != 0) {
        func_global_asm_805FF898();
        current_actor_pointer->control_state_progress++;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D1F28(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    if (!(current_actor_pointer->unk6A & 4)) {
        func_global_asm_806CC8B8();
    } else {
        func_global_asm_806D850C();
        if (!(current_actor_pointer->unk6C & 4)) {
            func_global_asm_80614E78(player_pointer, 0x34);
        }
        current_actor_pointer->y_velocity *= 0.25;
        func_global_asm_806CC8B8();
    }
    if (func_global_asm_80629148() || ((--extra_player_info_pointer->unk23C == 0))) { // TODO: Janky syntax
        func_global_asm_806ACC00(0);
        current_actor_pointer->control_state_progress++;
    }
    renderActor(current_actor_pointer, 0);
}

// doable, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D205C.s")

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Struct80750FB0;

extern Struct80750FB0 D_global_asm_80750FB0;

void func_global_asm_80688D20(s16, s16, s16, f32);

/*
void func_global_asm_806D205C(void) {
    s16 unk2E;
    Struct80750FB0 sp2C;
    Struct80750FB0 sp1C;

    sp1C = D_global_asm_80750FB0;
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 20.0f;
    if (!(current_actor_pointer->unk6A & 4)) {
        func_global_asm_806CC8B8();
    } else {
        func_global_asm_806D850C();
        if (!(current_actor_pointer->unk6C & 4)) {
            func_global_asm_80614E78(player_pointer, 0x34);
        }
        current_actor_pointer->y_velocity = current_actor_pointer->y_velocity * 0.25;
        func_global_asm_806CC8F0();
    }
    if (func_global_asm_80629148() || --extra_player_info_pointer->unk23C == 0) {
        if (gameIsInSnidesBonusGameMode() == FALSE) {
            func_global_asm_80688D20(unk2E, func_global_asm_80600340(&sp1C, 3, &sp2C.unk4), 7, 2.0f);
        }
        func_global_asm_805FF898();
        current_actor_pointer->control_state_progress += 1;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D21E4(void) {
    func_global_asm_806DF6D4(0);
    if (!(global_properties_bitfield & 0x4000) && !(global_properties_bitfield & 0x8000)) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2238(void) {
    func_global_asm_806DF6D4(1);
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_80614E78(current_actor_pointer, 0);
        current_actor_pointer->control_state_progress = 1;
        current_actor_pointer->object_properties_bitfield &= -5;
    }
}

void func_global_asm_806D22A0() {
    func_global_asm_806DF6D4(1);
}

void func_global_asm_806D22C0(void) {
    func_global_asm_806DF6D4(0x62);
    switch (current_actor_pointer->control_state_progress) {
        case 0x1:
        case 0x2:
            current_actor_pointer->control_state_progress++;
            return;
        default:
            current_actor_pointer->control_state_progress++;
        case 0x0:
        case 0x3C:
        case 0x3D:
            return;
    }
}

typedef struct {
    void *unk0; // Function pointer
    u8  unk4;
    s8  unk5;
    s16 unk6;
    Actor *unk8;
} Struct806D2330;

// TODO: Arg0 is a function pointer
void func_global_asm_806D2330(void *arg0) {
    Struct806D2330 *temp_v0 = malloc(0x14);
    temp_v0->unk0 = arg0;
    temp_v0->unk8 = current_player;
    temp_v0->unk4 = 1;
    func_global_asm_80679064(temp_v0);
}

void func_global_asm_806D2378(void) {
    func_global_asm_806D2330(&func_global_asm_8068E9B0);
}

void func_global_asm_806D239C(void) {
    func_global_asm_806D2378();
    switch (current_map) {
        case MAP_FUNGI_MINECART:
            func_global_asm_806DF6D4(0x5F);
            func_global_asm_806CC970();
            return;
        case MAP_CASTLE_MINECART:
            func_global_asm_806DF6D4(0x60);
            func_global_asm_806CC970();
            return;
        case MAP_MINECART_MAYHEM_EASY:
        case MAP_MINECART_MAYHEM_NORMAL:
        case MAP_MINECART_MAYHEM_HARD:
            if ((extra_player_info_pointer->unk1F0 & 8) && func_global_asm_80629148()) {
                extra_player_info_pointer->vehicle_actor_pointer->control_state = 0xA;
                current_actor_pointer->control_state_progress++;
            }
            func_global_asm_806DF6D4(0x5B);
            func_global_asm_806CC970();
            return;
        default:
            func_global_asm_806DF6D4(0x5C);
            current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
            func_global_asm_806CC948();
            return;
    }
}

void func_global_asm_806D24A8(void) {
    func_global_asm_806D2378();
    func_global_asm_806DF6D4(0x5D);
    current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
    func_global_asm_806CC948();
}

void func_global_asm_806D24E4(void) {
    func_global_asm_806D2378();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x5E);
            func_global_asm_806CC948();
            return;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x5E);
            func_global_asm_806CFD68();
            func_global_asm_806CC948();
            return;
        case 2:
            func_global_asm_806CC948();
            func_global_asm_806DF6D4(0x5E);
            func_global_asm_806CFD68();
            return;
        case 3:
            func_global_asm_806DF6D4(0x5C);
            func_global_asm_806CC948();
            return;
    }
}

void func_global_asm_806D25CC(void) {
    switch (current_map) {
        case MAP_CASTLE_MINECART:
            func_global_asm_806DF6D4(0x60);
            func_global_asm_806CC970();
            break;
        case MAP_FUNGI_MINECART:
            func_global_asm_806DF6D4(0x5F);
            func_global_asm_806CC970();
            break;
        case MAP_MINECART_MAYHEM_EASY:
            func_global_asm_806DF6D4(0x5B);
            func_global_asm_806CC970();
            break;
        default:
            func_global_asm_806DF6D4(0x5C);
            current_actor_pointer->y_velocity = current_actor_pointer->terminal_velocity;
            func_global_asm_806CC948();
    }
}

void func_global_asm_806D266C(void) {
    f32 sp2C, sp28, sp24;

    func_global_asm_806D2378();
    func_global_asm_806D25CC();
    func_global_asm_80671C0C(current_actor_pointer, 3, &sp2C, &sp28, &sp24);
    func_global_asm_806F4D70(cc_player_index, sp2C, sp28, sp24, 25.0f);
}

void func_global_asm_806D26D8(void) {
    f32 sp2C, sp28, sp24;

    func_global_asm_806D2378();
    func_global_asm_806D25CC();
    func_global_asm_80671C0C(current_actor_pointer, 2, &sp2C, &sp28, &sp24);
    func_global_asm_806F4D70(cc_player_index, sp2C, sp28, sp24, 25.0f);
}

void func_global_asm_806D2744(s32 arg0) {
    func_global_asm_806D2330(&func_global_asm_8068EA38);
    func_global_asm_806DF6D4(arg0);
    current_actor_pointer->unk6C = current_actor_pointer->unk6A;
}

void func_global_asm_806D2784() {
    func_global_asm_806D2744(0x61);
}

void func_global_asm_806D27A4(void) {
    func_global_asm_806D2744(0x63);
    if (func_global_asm_8061CB98(5)) {
        if (current_actor_pointer->animation_state->unk64 != 0x3B0) {
            func_global_asm_80614EBC(current_actor_pointer, 0x3B0);
        }
        if (func_global_asm_80629148() || (current_actor_pointer->control_state_progress != 0)) {
            func_global_asm_805FF8F8();
        }
    }
}

void func_global_asm_806D281C(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    if (current_actor_pointer->control_state_progress != 0) {
        current_actor_pointer->control_state = 0x6D;
        current_actor_pointer->control_state_progress = 0;
    } else {
        func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    }
    RaaD->unk0 += extra_player_info_pointer->unkC2;
    if (extra_player_info_pointer->unkC2 >= 8) {
        extra_player_info_pointer->unkC2 -= 7;
    } else if (extra_player_info_pointer->unkC2 < -7) {
        extra_player_info_pointer->unkC2 += 7;
    } else {
        extra_player_info_pointer->unkC2 = 0;
    }
    func_global_asm_806D2744(1);
}

void func_global_asm_806D28E4(void) {
    func_global_asm_806D2744(0x64);
}

void func_global_asm_806D2904(void) {
    renderActor(current_actor_pointer, 0);
    if (current_actor_pointer->control_state_progress++ > 200) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
}

void func_global_asm_806D2954(s16 arg0) {
    if ((extra_player_info_pointer->unk8C != 0) && func_global_asm_805FCA64()) {
        if (D_global_asm_807FD568->weapon == 7) {
            arg0 = 0xF;
            func_global_asm_8068C350(&func_global_asm_806FF75C, current_actor_pointer, 5);
        } else {
            arg0 = 0xE;
            func_global_asm_8068C350(&func_global_asm_806FF01C, current_actor_pointer, 5);
        }
    }
    if (current_actor_pointer->control_state_progress != 0) {
        arg0 = 5;
        current_actor_pointer->control_state_progress--;
    }
    func_global_asm_806DF6D4(arg0);
}

void func_global_asm_806D2A14(s16 arg0) {
    if (current_actor_pointer->control_state_progress != 0) {
        arg0 = 5;
        current_actor_pointer->control_state_progress--;
    }
    if (func_global_asm_805FCA64()) {
        if (!func_global_asm_806DF6D4(arg0)) {
            func_global_asm_8068C350(&func_global_asm_806FF358, current_actor_pointer, 3);
        }
        func_global_asm_8068C350(&func_global_asm_806FF32C, current_actor_pointer, 3);
    }
}

typedef struct {
    PlayerAdditionalActorData *unk0;
} AAD_806D2AA0;

void func_global_asm_806D2AA0(s16 arg0) {
    func_global_asm_806DF6D4(1);
    if (current_actor_pointer->control_state_progress < 6) {
        func_global_asm_8068C350(&func_global_asm_806FFB2C, current_actor_pointer, 3);
        current_actor_pointer->control_state_progress++;
    } else {
        current_actor_pointer->control_state = arg0;
        current_actor_pointer->control_state_progress = 0;
    }
    if (current_actor_pointer->control_state_progress == 2) {
        spawnActor(ACTOR_PICTURE, 0x8D);
        extra_player_info_pointer->vehicle_actor_pointer = last_spawned_actor;
        ((AAD_806D2AA0*)last_spawned_actor->additional_actor_data)->unk0 = extra_player_info_pointer;
        extra_player_info_pointer->unk1F0 |= 0x8000;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2B90(void) {
    func_global_asm_806D2AA0(4);
}

void func_global_asm_806D2BB0(void) {
    func_global_asm_806D2AA0(5);
}
