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

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} Struct807FD568;

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

typedef struct BoulderAAD {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    Actor *unk10;
    u16 unk14;
    u16 unk16;
    u32 unk18;
    u16 unk1C;
    s8 unk1E;
} BoulderAAD;

typedef struct {
    s16 unk0;
    s16 unk2;
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
    f32 unk2C;
    s32 unk30;
    u8 *unk34;
    s32 unk38;
    s16 unk3C;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
} AAD_global_asm_806E7C70;

extern s32 D_global_asm_8071FB08; // TODO: Proper datatype
extern s32 D_global_asm_8071FC40;
extern s32 D_global_asm_8071FFA0;
extern s32 D_global_asm_8071FF18;

extern s32 D_global_asm_8072014C;

extern void *D_global_asm_8074E880[];

extern s16 D_global_asm_80750338;
extern u8 D_global_asm_80750AB8;
extern u8 D_global_asm_80750AD0;
extern GlobalASMStruct63 D_global_asm_80750B54[];
extern f32 D_global_asm_80750FA8;
extern f32 D_global_asm_80750FC0;
extern s32 D_global_asm_80750FC4; // TODO: Datatype
extern s32 D_global_asm_80750FC8;
extern s32 D_global_asm_80750FCC;
extern s32 D_global_asm_80750FD0;
extern u8 D_global_asm_80750FD4;
extern f32 D_global_asm_80750FD8;
extern s32 D_global_asm_80750FDC;
extern s32 D_global_asm_80750FE0[];
extern s32 D_global_asm_80750FF0;
extern f32 D_global_asm_80750FF8;
extern f32 D_global_asm_80750FFC;
extern f32 D_global_asm_80751000;

// .data
extern f32 D_global_asm_80753024[];
extern f32 D_global_asm_8075305C[];
extern f32 D_global_asm_80753094[];
extern f32 D_global_asm_807530F0[];
extern f32 D_global_asm_80753144[];
extern f32 D_global_asm_80753170[];
extern f32 D_global_asm_807531E0[];
extern f32 D_global_asm_807531FC[]; // Kong Walking Maximum Velocity
extern f32 D_global_asm_80753218[];
extern f32 D_global_asm_80753234[];
extern f32 D_global_asm_80753250[];
extern s16 D_global_asm_8075326C[];
extern f32 D_global_asm_8075327C[];
extern s16 D_global_asm_80753298[];
extern f32 D_global_asm_807532B8[];
extern f32 D_global_asm_807532D4[];
extern f32 D_global_asm_807532F0[];
extern f32 D_global_asm_8075330C[];
extern s16 D_global_asm_80753328[];
extern f32 D_global_asm_80753338[];
extern s16 D_global_asm_80753354[];
extern f32 D_global_asm_8075339C[];
extern f32 D_global_asm_807533B8[];
extern f32 D_global_asm_80753380[];
extern f32 D_global_asm_80753364[];
extern f32 D_global_asm_807533D4[];
extern f32 D_global_asm_807533F0[];
extern f32 D_global_asm_8075340C[];
extern f32 D_global_asm_80753428[];
extern f32 D_global_asm_80753454[];
extern f32 D_global_asm_80753470[];
extern f32 D_global_asm_8075348C[];
extern s16 D_global_asm_807534A8[];
extern f32 D_global_asm_807534B8[];
extern s16 D_global_asm_807534D4[];
extern f32 D_global_asm_8075352C[];
extern s16 D_global_asm_80753548[];
extern f32 D_global_asm_80753578[]; // yAccelArray in ghidra
extern f32 D_global_asm_80753594[];
extern f32 D_global_asm_807535B0[] ;/*= {-17, -17, -17, -17, -10, -10, -17}; // Kong Jumping Y Acceleration*/
extern f32 D_global_asm_807535CC[];
extern f32 D_global_asm_80753604[];
extern f32 D_global_asm_80753658[];
extern f32 D_global_asm_807536E4[];
extern f32 D_global_asm_80753700[];
extern f32 D_global_asm_80753738[];
extern f32 D_global_asm_80753754[];
extern f32 D_global_asm_807537E0[];
extern s16 D_global_asm_8075380C[];
extern s16 D_global_asm_8075381C[];
extern s16 D_global_asm_8075382C[];
extern s16 D_global_asm_8075385C[];
extern s16 D_global_asm_8075386C[];
extern s16 D_global_asm_8075387C[];
extern s16 D_global_asm_8075388C[];
extern f32 D_global_asm_8075389C[];
extern s16 D_global_asm_807538B8[];
extern s16 D_global_asm_807538C8[];
extern s16 D_global_asm_8075395C[];
extern f32 D_global_asm_8075396C[];
extern f32 D_global_asm_807539C0[];
extern s16 D_global_asm_807539DC[];
extern s16 D_global_asm_807539EC[];
extern f32 D_global_asm_80753A5C[];
extern s16 D_global_asm_80753A78[];
extern s16 D_global_asm_80753A98[];
extern f32 D_global_asm_80753AA8[];
extern f32 D_global_asm_80753AC4[];
extern f32 D_global_asm_80753AFC[];
extern f32 D_global_asm_80753B18[];
extern f32 D_global_asm_80753BA4[];
extern f32 D_global_asm_80753BC0[];
extern f32 D_global_asm_80753BDC[];
extern f32 D_global_asm_80753BF8[];
extern s16 D_global_asm_80753C94[];
extern f32 D_global_asm_80753CB4[];
extern f32 D_global_asm_80753D08[];
extern f32 D_global_asm_80753DC8[];
extern f32 D_global_asm_80753DE4[];
extern s16 D_global_asm_80753E64[];

// rodata
extern f32 D_global_asm_8075C91C;
extern f32 D_global_asm_8075C920;
extern f32 D_global_asm_8075C924;
extern f32 D_global_asm_8075CC6C;
extern f64 D_global_asm_8075CC90;
extern f64 D_global_asm_8075CC98;
extern f64 D_global_asm_8075CCA0;
extern f32 D_global_asm_8075CCA8;
extern f64 D_global_asm_8075CCB0;
extern f64 D_global_asm_8075CCB8;
extern f64 D_global_asm_8075CCC0;
extern f64 D_global_asm_8075CCC8;
extern f64 D_global_asm_8075CCD0;
extern f64 D_global_asm_8075CCD8;
extern f32 D_global_asm_8075CCE0;
extern f32 D_global_asm_8075CCF0;
extern f32 D_global_asm_8075CCF4;
extern f32 D_global_asm_8075CCF8;
extern f32 D_global_asm_8075CCFC;
extern f64 D_global_asm_8075CD00;
extern f64 D_global_asm_8075CD08;
extern f32 D_global_asm_8075CD10;
extern f64 D_global_asm_8075CD78;
extern f64 D_global_asm_8075CD80;
extern f64 D_global_asm_8075CD98;
extern f32 D_global_asm_8075CDA0;
extern f64 D_global_asm_8075CDE0;
extern f64 D_global_asm_8075CDE8;
extern f64 D_global_asm_8075CE68;
extern f32 D_global_asm_8075CE70;

extern f32 D_global_asm_8075D080;
extern f64 D_global_asm_8075D0B8;
extern f32 D_global_asm_8075D0D0;
extern f64 D_global_asm_8075D0C8;
extern f64 D_global_asm_8075D0C0;
extern f64 D_global_asm_8075D0F0;
extern f32 D_global_asm_8075D0F8;
extern f64 D_global_asm_8075D100;
extern f64 D_global_asm_8075D108;
extern f32 D_global_asm_8075D110;
extern f64 D_global_asm_8075D118;
extern f64 D_global_asm_8075D120;
extern f64 D_global_asm_8075D128;
extern f32 D_global_asm_8075D130;
extern f32 D_global_asm_8075D214;
extern f32 D_global_asm_8075D218;
extern f32 D_global_asm_8075D21C;
extern f32 D_global_asm_8075D220;
extern f32 D_global_asm_8075D224;
extern f64 D_global_asm_8075D310;
extern f64 D_global_asm_8075D318;
extern f64 D_global_asm_8075D320;
extern f32 D_global_asm_8075D334;
extern f32 D_global_asm_8075D344;
extern f64 D_global_asm_8075D348;
extern f32 D_global_asm_8075D350;
extern f64 D_global_asm_8075D358;
extern f64 D_global_asm_8075D360;

extern s32 D_global_asm_80767CC0;

extern s32 D_global_asm_807FBB68;
extern u8 D_global_asm_807FBB8C;
extern f32 D_global_asm_807FBC58;

extern u8 D_global_asm_807FC8B9;

extern Struct807FD568 *D_global_asm_807FD568; // TODO: Unknown struct

extern s16 D_global_asm_807FD584; // index into a ton of arrays
extern u8 D_global_asm_807FD586;

extern f32 D_global_asm_807FD888;

extern void func_global_asm_8068E474(void);
void func_global_asm_8061C2F0(Actor *, f32, f32, f32, f32, f32, f32, s32);

void func_global_asm_8062217C(Actor*, u8);

void func_global_asm_806F91B4(s32, s32, s16);

int func_global_asm_806FF358(); // TODO: Signature
int func_global_asm_806FF75C(); // TODO: Signature

void func_global_asm_806CC970(void);
void func_global_asm_806CCB0C(void);
f32 func_global_asm_806CD898(f32 currentSpeed, f32 desiredSpeed, f32 boostAmount); // boostSpeed
void func_global_asm_806CEE64(f32);
void func_global_asm_806CEED8(void);
void func_global_asm_806CFD68(void);
u8 func_global_asm_806CE928(Actor*, f32, f32, s32);
f32 func_global_asm_806DFFA0(f32, s16, s16);
void func_global_asm_806EAB44(Actor *arg0, u8 arg1);

s32 func_global_asm_806DF6D4(s32 arg0);

f32 func_global_asm_806E0454(f32, f32);
void func_global_asm_8072FE60(f32);
void func_global_asm_806E1630(void);

void func_global_asm_806CC948();
void func_global_asm_806CFD68();
void func_global_asm_806CFECC(void);
void func_global_asm_806D2378();

void func_global_asm_806CC948();

u8 func_global_asm_806CDD24(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
u8 func_global_asm_806CE174(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);

s16 func_global_asm_806CE4E4(Actor*, f32, f32, s32);

void func_global_asm_806DF494(s16*, s16, s16);

u32 func_global_asm_806119A0(void);
void func_global_asm_806DF390(Actor*, PlayerAdditionalActorData*, u8);
void func_global_asm_806DF3D0(Actor*, PlayerAdditionalActorData*, u8);
s16 func_global_asm_8062773C(s32);

void func_global_asm_806D0468(Actor *arg0, u8 arg1);
void func_global_asm_806CD8EC(void);
void func_global_asm_806CD424(s16, f32, f32); // TODO: Is this signature correct?

void func_global_asm_80718BF4(void);
u8 func_global_asm_80666AE0();
void func_global_asm_806D0150(Actor *arg0);
void func_global_asm_806C8D20(Actor*);
void func_global_asm_806CC638(f32 arg0);
f32 func_global_asm_806F46B0(s16 arg0);
void func_global_asm_807149FC(s32);
void func_global_asm_806224CC(s32, Actor*);
s16 func_global_asm_806CC190(s16, s16, f32);
void func_global_asm_80613AF8(Actor*, s32, f32, f32);
void func_global_asm_806D9924(Actor*);
void func_global_asm_806E9804(s16 arg0);
void func_global_asm_80659620(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3);
void func_global_asm_806CEFBC(Struct806CEFBC*); // TODO: Proper signature, just for function pointer
void func_global_asm_806CF138(Struct806CF138 *arg0);

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

// jumptable
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
                current_actor_pointer->unk120 = D_global_asm_8075C920;
                break;
            case ACTOR_CHUNKY:
                current_actor_pointer->unk120 = D_global_asm_8075C924;
                break;
            default:
                current_actor_pointer->unk120 = D_global_asm_8075C91C;
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

extern s16 D_global_asm_80753A3C[];
extern s16 D_global_asm_80753A4C[];

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

extern f64 D_global_asm_8075C928;
extern f32 D_global_asm_8075C930;
extern s16 D_global_asm_80753A2C[];

void func_global_asm_80665160(Actor *, s16, s16);
void func_global_asm_806653C0(Actor *, f32, f32);

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

// close, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CC970.s")

extern s32 D_global_asm_80744478;
extern f64 D_global_asm_8075C938;

/*
void func_global_asm_806CC970(void) {
    f32 dx;
    f32 dz;
    s16 phi_a1;
    f64 phi_f2;
    f64 temp;

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
    // TODO: Just gotta figure out this fiddly float stuff, otherwise it matches :)
    extra_player_info_pointer->unk20 = ((sqrtf((dx * dx) + (dz * dz)) / D_global_asm_80744478) * 80.0 * D_global_asm_8075C938) / current_actor_pointer->animation_state->scale_x;
}
*/

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

// jumptable :(
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CCC10.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CCC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CD424.s")

f32 func_global_asm_806CD898(f32, f32, f32);
extern f64 D_global_asm_8075C9A0;
extern f64 D_global_asm_8075C9A8;
extern f64 D_global_asm_8075C9B0;

/*
TODO: Progress made, tricky but doable
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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CE174.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CE4E4.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CE7A0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CE928.s")

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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CEC04.s")

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

// stack, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CEED8.s")

extern f32 D_global_asm_8075CBE0;
extern f64 D_global_asm_8075CBE8;

void func_global_asm_806CF2EC(s32*, s32*);

/*
void func_global_asm_806CEED8(void) {
    f32 sp44; // 44
    f32 sp40; // 40
    f32 sp3C; // 3C
    f32 sp38; // 38
    f32 sp34; // 34
    f32 sp30; // 30
    s32 sp20; // 2C // TODO: Needs to move to sp20
    f32 sp28; // 28
    s32 sp24; // 24

    func_global_asm_806CF2EC(&sp24, &sp20);
    func_global_asm_80671C0C(current_actor_pointer, sp24, &sp40, &sp38, &sp30);
    func_global_asm_80671C0C(current_actor_pointer, sp20, &sp44, &sp3C, &sp34);
    sp28 = sp3C - sp38;
    extra_player_info_pointer->unk1BC = ((0.0 - (func_global_asm_80611BB4(sp28, sqrtf(((sp34 - sp30) * (sp34 - sp30)) + ((sp44 - sp40) * (sp44 - sp40)))) * D_global_asm_8075CBE0)) + D_global_asm_8075CBE8);
}
*/

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

extern f32 D_global_asm_8075CBF0;
extern f64 D_global_asm_8075CBF8;
extern f32 D_global_asm_8075CC00;

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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CF2EC.s")

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
        if ((current_actor_pointer->control_state == 0x36) && (extra_player_info_pointer->unk0_s16[0] != 0x36)) {
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
            if (extra_player_info_pointer->unk0_s16[0] == 0x36) {
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
        && (((func_global_asm_806119A0() % 2500) / 200) == 0)) {
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

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806CF918.s")

extern f32 D_global_asm_8075CC68;
void func_global_asm_807195D4(void);
extern s32 D_global_asm_8071FF40;

/*
void func_global_asm_806CF918(void) {
    s32 i;
    f32 uvar = D_global_asm_8075CC68;

    for (i = 0; i < 5; i++) {
        func_global_asm_8071498C(&func_global_asm_807195D4);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(i * 0x28);
        func_global_asm_807149FC(0x45);
        func_global_asm_80714C08(&D_global_asm_8071FF40, uvar, current_actor_pointer, 6, 2);
    }
}
*/

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
    D_global_asm_80750FA8 = D_global_asm_8075CC6C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D0468.s")

extern f32 D_global_asm_8075CC70;
extern f32 D_global_asm_8075CC74;
extern f32 D_global_asm_8075CC78;
extern f32 D_global_asm_8075CC7C;
extern f32 D_global_asm_8075CC80;
extern f32 D_global_asm_8075CC84;
extern f32 D_global_asm_8075CC88;

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
        current_actor_pointer->animation_state->scale_x = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * D_global_asm_8075CC90) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1CC;
        current_actor_pointer->animation_state->scale_y = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * D_global_asm_8075CC98) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1D0;
        current_actor_pointer->animation_state->scale_z = (func_global_asm_80612D1C(extra_player_info_pointer->unk1E4 * D_global_asm_8075CCA0) * extra_player_info_pointer->unk1DC) + extra_player_info_pointer->unk1D4;
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
        var_f0 = D_global_asm_8075CCA8;
    }
    sp2C = var_f0 * D_global_asm_8075CCB0;
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
            current_actor_pointer->y_velocity = current_actor_pointer->y_velocity + D_global_asm_8075CCB8;
            current_actor_pointer->y_position += sp2C * current_actor_pointer->y_velocity;
            break;
        case 2:
            current_actor_pointer->y_velocity = current_actor_pointer->y_velocity - D_global_asm_8075CCC0;
            current_actor_pointer->y_position += sp2C * current_actor_pointer->y_velocity;
            break;
        case 3:
            current_actor_pointer->unk168 += 0x28;
            current_actor_pointer->unk168 &= 0xFFF;
            if (current_actor_pointer->unkB8 < D_global_asm_8075CCC8) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 + D_global_asm_8075CCD0;
            }
            temp_f10 = current_actor_pointer->unkB8 * sp2C;
            current_actor_pointer->x_position += temp_f10 * func_global_asm_80612794(current_actor_pointer->unk168);
            current_actor_pointer->z_position += temp_f10 * func_global_asm_80612790(current_actor_pointer->unk168);
            if (current_actor_pointer->y_velocity < 2.5) {
                current_actor_pointer->y_velocity = current_actor_pointer->y_velocity + D_global_asm_8075CCD8;
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
    return (s16)((s16)((func_global_asm_80611BB4(arg0, arg1) * 4096.0f) / D_global_asm_8075CCE0) - 0x400) & 0xFFF;
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
    temp_v0->unk8 = current_player; // player_pointer
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
        if (D_global_asm_807FD568->unk2 == 7) {
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
        last_spawned_actor->PaaD->unk0 = extra_player_info_pointer;
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

void func_global_asm_806D2BD0(void) {
    func_global_asm_806D2954(0xC);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
    if (func_global_asm_8061CB50()) {
        if (current_actor_pointer->unk6E[0] != -1) {
            func_global_asm_80605314(current_actor_pointer, 0);
        }
    }
    if (is_autowalking == 3) {
        func_global_asm_806C9F74(current_actor_pointer);
    }
}

void func_global_asm_806D2C54(void) {
    func_global_asm_806D2A14(0x10);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
    if (is_autowalking == 3) {
        func_global_asm_806C9F74(current_actor_pointer);
    }
}

void func_global_asm_806D2CAC(void) {
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    func_global_asm_806D2954(0xD);
    func_global_asm_806CC638(D_global_asm_80753A5C[D_global_asm_807FD584]);
    if (func_global_asm_806D850C()) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2D38(void) {
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    func_global_asm_806D2A14(0x11);
    func_global_asm_806CC638(D_global_asm_80753A5C[D_global_asm_807FD584]);
    if (func_global_asm_806D850C()) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2DC4(void) {
    u8 newControlState;
    s32 phi_a1;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    current_actor_pointer->unk64 |= 0x200;
    phi_a1 = 0x13;
    if (current_actor_pointer->control_state_progress != 0) {
        current_actor_pointer->control_state_progress--;
        phi_a1 = 0x14;
    }
    if (object_timer > 1U && !func_global_asm_806DF6D4(phi_a1)) {
        newControlState = func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0xC) {
            current_actor_pointer->control_state = newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2E9C(void) {
    f32 var_f2;
    s32 var_a1;
    s32 var_v0;
    f32 temp;

    if (D_global_asm_807FBB68 & 2) {
        var_f2 = MAX((current_actor_pointer->y_position - 120.0f) * 0.5, 0.0);
        if (current_actor_pointer->x_position < D_global_asm_8075CCF0 - var_f2) {
            current_actor_pointer->x_position = D_global_asm_8075CCF0 - var_f2;
        }
        if (D_global_asm_8075CCF4 + var_f2 < current_actor_pointer->x_position) {
            current_actor_pointer->x_position = D_global_asm_8075CCF4 + var_f2;
        }
        if (current_actor_pointer->z_position < D_global_asm_8075CCF8 - var_f2) {
            current_actor_pointer->z_position = D_global_asm_8075CCF8 - var_f2;
        }
        if (D_global_asm_8075CCFC + var_f2 < current_actor_pointer->z_position) {
            current_actor_pointer->z_position = D_global_asm_8075CCFC + var_f2;
        }
        current_actor_pointer->noclip_byte &= 0xFFF7;
    }
    func_global_asm_806DF6D4(0x1B);

    if (func_global_asm_806F46B0(player_pointer->unk12C) < current_actor_pointer->y_position) {
        current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
        if (current_actor_pointer->y_velocity > 0.0f) {
            current_actor_pointer->y_velocity *= D_global_asm_8075CD00;
        }
    }
    if (extra_player_info_pointer->unk1A2 != 0) {
        var_v0 = extra_player_info_pointer->unk1A0;
        if (var_v0 >= 0x8000) {
            var_v0 += 0xFFFF0000;
        }
        var_v0 += 0x9E8;
        if (var_v0 >= 0x7D1) {
            var_a1 = 0x7D;
        } else if (var_v0 < -0x7D0) {
            var_a1 = 0x80;
        } else {
            var_a1 = 0x7F;
        }
    } else {
        var_a1 = 0x7E;
    }
    if ((var_a1 != current_actor_pointer->animation_state->unk64) && (current_actor_pointer->animation_state->unk64 != 0x81)) {
        func_global_asm_80614EBC(current_actor_pointer, var_a1);
    }
    if ((extra_player_info_pointer->unk1F0 & 0x40000000) && (extra_player_info_pointer->unk240 == 0)) {
        func_global_asm_80687400();
        extra_player_info_pointer->unk240 = 0x1E;
    }
    if (extra_player_info_pointer->unk240 != 0) {
        extra_player_info_pointer->unk240--;
    }
    if ((current_actor_pointer->unk6A & 1) || (extra_player_info_pointer->unk240 == 1)) {
        if (D_global_asm_807FBB68 & 2) {
            current_actor_pointer->noclip_byte |= 8;
        }
        func_global_asm_806CFF9C(current_actor_pointer);
        func_global_asm_80608528(current_actor_pointer, 1, 0xFF, 0x7F, 0x1E);
    }
    if (func_global_asm_8061CB50() == 0) {
        func_global_asm_806CC948();
        if ((func_global_asm_806F8AD4(5, cc_player_index) != 0) && !(extra_player_info_pointer->unk1F0 & 0x10000)) {
            func_global_asm_806F91B4(5, cc_player_index, -1);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3224(void) {
    u8 newControlState;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    if (func_global_asm_806DF6D4(0x1D) == 0) {
        newControlState = func_global_asm_806CE174(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0x5D) {
            current_actor_pointer->control_state = newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D32C0(void) {
    if ((current_map == MAP_BUSY_BARREL_BARRAGE_EASY)
        || (current_map == MAP_BUSY_BARREL_BARRAGE_NORMAL)
        || (current_map == MAP_BUSY_BARREL_BARRAGE_HARD)) {
        func_global_asm_806DF6D4(0x1F);
    } else {
        func_global_asm_806DF6D4(0x1E);
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D332C(void) {
    u8 newControlState;

    if (current_actor_pointer->control_state_progress == 0) {
        current_actor_pointer->control_state_progress++;
        extra_player_info_pointer->unkC = -1;
        extra_player_info_pointer->unkE = -1;
    }
    if (func_global_asm_806DF6D4(0x13) == 0) {
        newControlState = func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0xD) {
            current_actor_pointer->control_state = newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    if ((!func_global_asm_8061CB50())
        && (D_global_asm_807531E0[D_global_asm_807FD584] < current_actor_pointer->unkB8)
        && (D_global_asm_807531E0[D_global_asm_807FD584] < extra_player_info_pointer->unk4)
        && (extra_player_info_pointer->unkC >= 0)
        && (func_global_asm_806CC14C(extra_player_info_pointer->unkC, extra_player_info_pointer->unkA) >= 0x401)
        && (func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unkA) >= 0x539)) {
        current_actor_pointer->control_state = 0xE;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_806CC948();
    } else {
        func_global_asm_806CC8B8();
    }
    extra_player_info_pointer->unkC = extra_player_info_pointer->unkE;
    extra_player_info_pointer->unkE = extra_player_info_pointer->unkA;
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D34B4(void) {
    u8 newControlState;
    if (func_global_asm_806DF6D4(0x1C) == 0) {
        newControlState = func_global_asm_806CE174(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0x5E) {
            current_actor_pointer->control_state = newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3530(void) {
    if (((current_actor_pointer->unk9C - current_actor_pointer->y_position) > 50.0f) && (current_actor_pointer->distance_from_floor > 250.0f)) {
        extra_player_info_pointer->unk42++;
    } else {
        extra_player_info_pointer->unk42 = 0;
    }
    if ((extra_player_info_pointer->unk42++ >= 0xB) || (current_actor_pointer->y_position < -10.0f)) {
        func_global_asm_806EB0C0(0x2D, NULL, cc_player_index);
    }
}

void func_global_asm_806D3608(void) {
    f32 temp_f0 = current_actor_pointer->animation_state->scale_y / D_global_asm_8075CD08;
    if ((D_global_asm_807FBB64 << 0xD) >= 0) {
        if (!func_global_asm_8061CB50()) {
            if (current_map == MAP_AZTEC_BEETLE_RACE) {
                func_global_asm_806D3530();
                return;
            }
            if ((290.0f * temp_f0) < (current_actor_pointer->unk9C - current_actor_pointer->y_position)) {
                func_global_asm_806EB0C0(0x2C, NULL, cc_player_index);
            }
        }
    }
}

void func_global_asm_806D36CC(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x20);
            func_global_asm_806D3608();
            break;
        case 1:
            func_global_asm_806DF6D4(0x31);
            func_global_asm_806CFE7C();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D374C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x20);
            func_global_asm_806D3608();
            break;
        case 1:
            func_global_asm_806DF6D4(0x32);
            func_global_asm_806CFE7C();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D37CC(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_806DF6D4(0x20);
        func_global_asm_806CC8B8();
        if (current_actor_pointer->unk6A & 1) {
            if (current_actor_pointer->unkE0 != 0.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            } else {
                func_global_asm_806CFE7C();
                func_global_asm_806EB0C0(0x35, NULL, cc_player_index);
            }
        }
    } else {
        func_global_asm_806DF6D4(0x20);
        extra_player_info_pointer->unk4 = 0.0f;
        current_actor_pointer->unkB8 = 0.0f;
        func_global_asm_806CC8B8();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D38AC(s32 arg0) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    current_actor_pointer->unkF8 = 0x12C;
    if ((current_actor_pointer->y_position - current_actor_pointer->floor) > 5.0f) {
        if (current_actor_pointer->y_acceleration == -260.0f) {
            func_global_asm_806CFE7C();
        } else if (current_actor_pointer->y_acceleration != -30.0f) {
            current_actor_pointer->unk6A |= 0x1000;
        } else {
            if (current_actor_pointer->y_velocity > 0.0f) {
                current_actor_pointer->y_velocity = 0.0f;
            } else {
                current_actor_pointer->y_velocity = current_actor_pointer->y_velocity;
            }
        }
        current_actor_pointer->control_state = 0x14;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = current_actor_pointer->y_velocity;
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x67);
    }
    func_global_asm_806DF6D4(arg0);
    func_global_asm_806CC8B8();
    if ((current_actor_pointer->unk6A & 0x200) == 0) {
        func_global_asm_806CFF9C(current_actor_pointer);
        func_global_asm_80605314(current_actor_pointer, 0);
        func_global_asm_806224CC(extra_player_info_pointer->unk104, current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3A38(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_8061C464(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x800, 0x32, 0, 5, 0x32, 0x14, 0, D_global_asm_8075CD10);
        current_actor_pointer->control_state_progress++;
    }
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3AC8() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3AE8() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B08() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B28() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B48(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    current_actor_pointer->control_state_progress++;
    if (current_actor_pointer->control_state_progress == 0x32) {
        RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
        RaaD->unk45 = 1;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3BC8(void) {
    func_global_asm_806DF6D4(0x3E);
    func_global_asm_806CC8B8();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            if (current_map == MAP_AZTEC_BEETLE_RACE) {
                func_global_asm_806D3530();
            }
            break;
        case 2:
            if (current_actor_pointer->unk6A & 1) {
                current_actor_pointer->unk6A &= ~0x1000;
                func_global_asm_806CFE7C();
                current_actor_pointer->control_state = 0xF;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614E78(current_actor_pointer, 0x5E);
            } else {
                func_global_asm_806D3530();
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3CD4(void) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    func_global_asm_806DF6D4(0x3C);
    func_global_asm_806CC8B8();
    if (current_actor_pointer->unkB8 == 0.0f) {
        if (current_actor_pointer->unkE0 == 0.0f) {
            func_global_asm_806CFF9C(current_actor_pointer);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3D5C(void) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    func_global_asm_806DF6D4(0x3B);
    func_global_asm_806CC8B8();
    if (current_actor_pointer->unkB8 == 0.0f) {
        if (current_actor_pointer->unkE0 == 0.0f) {
            func_global_asm_806CFF9C(current_actor_pointer);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3DE4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_80614E78(current_actor_pointer, 5);
            extra_player_info_pointer->unk30 = D_global_asm_8075327C[D_global_asm_807FD584];
            func_global_asm_806CD8EC();
            func_global_asm_806CC948();
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_806CD8EC();
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_806CD8EC();
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, D_global_asm_80753298[D_global_asm_807FD584], 0xC00);
            func_global_asm_806CC948();
            break;
        case 3:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, D_global_asm_80753298[D_global_asm_807FD584], 0xC00);
            if (extra_player_info_pointer->unk4 == 0.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3FA0(void) {
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        current_actor_pointer->unkEA = extra_player_info_pointer->unkA;
    } else {
        current_actor_pointer->unkEA = current_actor_pointer->y_rotation;
    }
}

void func_global_asm_806D4010(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806CFD68();
            break;
        case 3:
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xAU) && (current_character_index[cc_player_index] == 1)) {
                if (current_actor_pointer->unkE0 == 0.0f) {
                    current_actor_pointer->control_state = 0x1A;
                    current_actor_pointer->control_state_progress = 0;
                    extra_player_info_pointer->unk54 = D_global_asm_80753604[D_global_asm_807FD584];
                    extra_player_info_pointer->unk50 = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x13);
                }
            }
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D423C(void) {
    current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
    func_global_asm_806DF6D4(5);
    func_global_asm_806CC8F0();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D428C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x2C);
            if (extra_player_info_pointer->unk3C != 0) {
                func_global_asm_806CC948();
                extra_player_info_pointer->unk3C--;
            } else {
                func_global_asm_806CC8B8();
            }
            break;
        case 1:
            if (extra_player_info_pointer->unk3C != 0) {
                extra_player_info_pointer->unk2C = 0.0f;
                func_global_asm_806CC8B8();
                extra_player_info_pointer->unk3C--;
                current_actor_pointer->unkEA = current_actor_pointer->y_rotation;
            } else {
                func_global_asm_806D3FA0();
                func_global_asm_806CC8B8();
            }
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            if (extra_player_info_pointer->unk3C != 0) {
                extra_player_info_pointer->unk2C = 0.0f;
                func_global_asm_806CC8B8();
                extra_player_info_pointer->unk3C--;
            } else {
                extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584];
                func_global_asm_806CC8B8();
            }
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806D3608();
            func_global_asm_806CFD68();
            break;
        case 3:
            extra_player_info_pointer->unk3C = 0;
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xAU) && (current_character_index[cc_player_index] == 1)) {
                if (current_actor_pointer->unkE0 == 0.0f) {
                    current_actor_pointer->control_state = 0x1A;
                    current_actor_pointer->control_state_progress = 0;
                    extra_player_info_pointer->unk54 = D_global_asm_80753604[D_global_asm_807FD584];
                    extra_player_info_pointer->unk50 = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x13);
                }
            }
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CC8B8();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D45A4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806D3608();
            func_global_asm_806CFD68();
            break;
        case 3:
            extra_player_info_pointer->unk4C = -1;
            current_actor_pointer->control_state = func_global_asm_806CE4E4(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
            current_actor_pointer->control_state_progress = 0;
            if (current_actor_pointer->control_state == 0x3F) {
                current_actor_pointer->control_state_progress = 1;
            }
            func_global_asm_806DF6D4(0x46);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// regalloc, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D4758.s")

extern f64 D_global_asm_8075CD18;
extern f64 D_global_asm_8075CD20;

/*
void func_global_asm_806D4758(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk3E != 0) {
                func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40);
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 50.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806DF6D4(0x23);
            switch (current_character_index[cc_player_index]) {
                case 2:
                    extra_player_info_pointer->unk4 *= D_global_asm_8075CD18;
            }
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806DF6D4(0x23);
            switch (current_character_index[cc_player_index]) {
                case 0:
                case 2:
                    extra_player_info_pointer->unk4 *= D_global_asm_8075CD20;
            }
            func_global_asm_806CFE7C();
            func_global_asm_806D3608();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (!func_global_asm_806DF6D4(0x31) && current_actor_pointer->unkB8 < extra_player_info_pointer->unk4) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D491C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x26);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x25);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x25);
            func_global_asm_806CFD68();
            func_global_asm_806D3608();
            break;
        case 3:
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            func_global_asm_806DF6D4(0x34);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D4A70.s")

/*
void func_global_asm_806D4A70(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk3E) {
                func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40);
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 50.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806CC8B8();
            if (current_actor_pointer->y_velocity <= -15.0f) {
                current_actor_pointer->y_velocity = -15.0f;
                current_actor_pointer->control_state_progress++;
            }
            func_global_asm_806DF6D4(0x24);
            if (current_actor_pointer->unk6A & 1) {
                func_global_asm_806F142C(current_actor_pointer);
            }
            break;
        case 1:
            func_global_asm_806DF6D4(0x24);
            if (extra_player_info_pointer->unk3E) {
                func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40);
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 30.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unk6A & 1) {
                func_global_asm_806F142C(current_actor_pointer);
                func_global_asm_80608528(current_actor_pointer, 1, 0xFF, 0x7F, 0x1E);
            }
            break;
        case 2:
            current_actor_pointer->y_acceleration = -4.0f;
            func_global_asm_806DF6D4(0x24);
            func_global_asm_806CC8B8();
            if ((current_actor_pointer->unk6A & 1) != 0) {
                func_global_asm_806F142C(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D4C7C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D4DE4.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D5008.s")

void func_global_asm_806D5218(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 = extra_player_info_pointer->unk30 / D_global_asm_8075CD78;
            current_actor_pointer->control_state_progress++;
        case 1:
            func_global_asm_806DF6D4(5);
            func_global_asm_806CC8B8();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5300(void) {
    s32 pad;
    f32 sp90, sp8C, sp88;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    s32 phi_s1;

    if ((current_actor_pointer->control_state_progress < 2) || (D_global_asm_80750FD8 < current_actor_pointer->unkB8)) {
        temp_f20 = current_actor_pointer->animation_state->scale_y / D_global_asm_8075CD80;
        func_global_asm_80671C0C(current_actor_pointer, 7, &sp90, &sp8C, &sp88);
        for (phi_s1 = 0; phi_s1 < D_global_asm_80750FD4; phi_s1++) {
            temp_f24 = (((rand() >> 0xF) % 10000) % D_global_asm_80750FC8) - (D_global_asm_80750FC8 / 2);
            temp_f26 = (((rand() >> 0xF) % 10000) % D_global_asm_80750FCC) - (D_global_asm_80750FCC / 2);
            temp_f22 = (((rand() >> 0xF) % 10000) % D_global_asm_80750FD0) - (D_global_asm_80750FD0 / 2);
            func_global_asm_80714950(D_global_asm_80750FC4);
            func_global_asm_8071498C(&func_global_asm_80717D4C);
            func_global_asm_807149B8(1);
            func_global_asm_80714CC0(D_global_asm_8074E880[((rand() % 10000) % 3)],
                D_global_asm_80750FC0 * temp_f20,
                (temp_f24 * temp_f20) + sp90,
                (temp_f26 * temp_f20) + sp8C,
                (temp_f22 * temp_f20) + sp88
            );
        }
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(5);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            func_global_asm_806DF6D4(5);
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            if ((extra_player_info_pointer->unk1F4 & 8) == 0) {
                current_actor_pointer->unkB8 = 140.0f;
            }
            extra_player_info_pointer->unk30 = 6.0f;
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            if (current_actor_pointer->unkFC != 0) {
                if ((D_global_asm_8075352C[D_global_asm_807FD584] < current_actor_pointer->unkB8) && ((extra_player_info_pointer->unk1F4 & 8) == 0)) {
                    current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                    extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
                }
            }
            func_global_asm_806DF6D4(5);
            break;
        case 3:
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806DF6D4(5);
            func_global_asm_806F142C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D57F0(void) {
    func_global_asm_806DF6D4(1);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

// rodata, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D5834.s")

extern f64 D_global_asm_8075CD88;
extern s32 D_global_asm_80767CC0;
extern f64 D_global_asm_8075CD90;
extern s32 D_global_asm_80767CC0;

/*
void func_global_asm_806D5834(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= D_global_asm_8075CD88;
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0 - 0x64;
            extra_player_info_pointer->unk48 = 0x50;
            // Fallthrough
        case 1:
            func_global_asm_806DF6D4(9);
            extra_player_info_pointer->unk30 = 10.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x32U) {
                if (current_character_index[cc_player_index] == 2) {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x40);
                } else {
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x41);
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D59E4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= D_global_asm_8075CD90;
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0 - 0x64;
            // Fallthrough
        case 1:
            func_global_asm_806DF6D4(9);
            extra_player_info_pointer->unk30 = 10.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x32U) {
                current_actor_pointer->control_state = 0x28;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614E78(current_actor_pointer, 0x41);
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5B44(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= D_global_asm_8075CD98;
            if (current_character_index[cc_player_index] == 3) {
                current_actor_pointer->unkB8 = 50.0f;
            }
            current_actor_pointer->control_state_progress++;
        case 1:
            func_global_asm_806DF6D4(0xA);
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            func_global_asm_806DF6D4(0xA);
            extra_player_info_pointer->unk30 = 50.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5CCC(void) {
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806D3608();
    switch (current_character_index[cc_player_index]) {
        case 1:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_806CFECC();
                    func_global_asm_806DF6D4(0x17);
                    func_global_asm_806CC948();
                    break;
                case 1:
                    func_global_asm_806CFECC();
                    func_global_asm_806DF6D4(0x16);
                    func_global_asm_806CC948();
                    break;
            }
            break;
        case 0:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    extra_player_info_pointer->unk30 = 7.0f;
                    extra_player_info_pointer->unk2C = 8.0f;
                    extra_player_info_pointer->unk48 = 0x12C;
                    func_global_asm_806DF6D4(0x15);
                    extra_player_info_pointer->unk4 = 0.0f;
                    func_global_asm_806CC8B8();
                    break;
                case 1:
                    current_actor_pointer->unkB8 = D_global_asm_807531FC[D_global_asm_807FD584];
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    current_actor_pointer->y_velocity = 150.0f;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = 200.0f;
                    func_global_asm_806DF6D4(0x15);
                    extra_player_info_pointer->unk4 = 200.0f;
                    func_global_asm_806CC8B8();
                    current_actor_pointer->control_state_progress++;
                    break;
                case 3:
                    current_actor_pointer->unkB8 = 200.0f;
                    extra_player_info_pointer->unk38 = 200.0f;
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
            }
            break;
        default:
        case 3:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    extra_player_info_pointer->unk28 = 0;
                    extra_player_info_pointer->unk30 = D_global_asm_8075CDA0;
                    extra_player_info_pointer->unk2C = 8.0f;
                    extra_player_info_pointer->unk48 = 0x12C;
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 1:
                    extra_player_info_pointer->unk30 = 20.0f;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    extra_player_info_pointer->unk28 = 1;
                    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x14U) {
                        current_actor_pointer->control_state = 0x26;
                        current_actor_pointer->control_state_progress = 0;
                        func_global_asm_80614E78(current_actor_pointer, 0x3F);
                    }
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC8B8();
                    break;
            }
            break;
        case 6:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    extra_player_info_pointer->unk28 = 0;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk48 = 0x12C;
                    func_global_asm_806DF6D4(0x15);
                    extra_player_info_pointer->unk30 = 10.0f;
                    func_global_asm_806CD8EC();
                    func_global_asm_806CC948();
                    break;
                case 1:
                    extra_player_info_pointer->unk2C = 30.0f;
                    extra_player_info_pointer->unk68 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    extra_player_info_pointer->unk28 = 1;
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC8B8();
                    break;
                }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D61B8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D6558.s")

s32 func_global_asm_806D69A4(void) {
    if (current_actor_pointer->unkFC != 0) {
        if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, ((((current_actor_pointer->unkF6 - current_actor_pointer->unkF4) & 0xFFF) / 2) + current_actor_pointer->unkF4 + 0x800) & 0xFFF) < 0x2BC) {
            if (current_actor_pointer->unkB8 > 150.0f) {
                func_global_asm_80614E78(current_actor_pointer, 0x49);
                current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
                current_actor_pointer->control_state_progress = 2;
                current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
            } else {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            return 1;
        }
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    }
    return 0;
}

void func_global_asm_806D6B00(void) {
    func_global_asm_806D3608();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk28 = 0;
            func_global_asm_806DF6D4(0x1A); // controlStateControl()
            if (extra_player_info_pointer->unk68 < current_actor_pointer->unkB8) {
                extra_player_info_pointer->unk68 = current_actor_pointer->unkB8;
            }
            if (func_global_asm_806D69A4()) {
                break;
            } else {
                func_global_asm_806CBE90();
                if (current_actor_pointer->unkE0 != 0.0f) {
                    extra_player_info_pointer->unk30 = 20.0f;
                    func_global_asm_806CD8EC();
                } else {
                    func_global_asm_806CD424(current_actor_pointer->y_rotation,
                                extra_player_info_pointer->unk68,
                                extra_player_info_pointer->unk38);
                }
                func_global_asm_806CC948();
                break;
            }
        case 1:
            func_global_asm_806DF6D4(0x1A); // controlStateControl()
            if (func_global_asm_806D69A4()) {
                break;
            } else {
                func_global_asm_806DF494(&current_actor_pointer->y_rotation,
                              current_actor_pointer->unkEE,
                              extra_player_info_pointer->unk48);
                func_global_asm_806CBE90();
                func_global_asm_806CD8EC();
                func_global_asm_806CC948();
                extra_player_info_pointer->unk30 = D_global_asm_80753548[D_global_asm_807FD584];
                if (current_actor_pointer->unkB8 > 20.0f) {
                    if ((func_global_asm_806119A0() % 3) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 2, 0);
                    }
                    if ((func_global_asm_806119A0() % 3) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 3, 0);
                    }
                    if ((func_global_asm_806119A0() % 3) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 9, 0);
                    }
                    if ((func_global_asm_806119A0() % 3) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 0xA, 0);
                    }
                }
                break;
            }
        case 2:
            func_global_asm_806DF6D4(5); // controlStateControl()
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
        case 3:
            func_global_asm_806DF6D4(5); // controlStateControl()
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            extra_player_info_pointer->unk30 = 5.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D6F0C(void) {
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806DF6D4(8); // controlStateControl()
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D6F64(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = D_global_asm_8075305C[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, ((current_actor_pointer->unkEE + 0x800) & 0xFFF), extra_player_info_pointer->unk48 << 1);
            break;
        case 1:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 2:
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7098(void) {
    func_global_asm_806DF6D4(3);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkDC->y_rotation + 0x800, 8.0f);
            extra_player_info_pointer->unk4 = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7170(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806DF6D4(3);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk4 = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_8068780C(1, 4, 5, 8);
            break;
        case 2:
            func_global_asm_806845B8(1, 8);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7238(void) {
    func_global_asm_806EB0C0(0x5C, NULL, cc_player_index);
    func_global_asm_806DF6D4(3);
    current_actor_pointer->noclip_byte = 1;
    extra_player_info_pointer->unk4 = 0.0f;
    current_actor_pointer->unkB8 = 0.0f;
    func_global_asm_806CC8B8();
    if (extra_player_info_pointer->unk21E == 0) {
        func_global_asm_80712830(current_actor_pointer, cc_player_index);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D72D4(void) {
    f32 temp_f0;

    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = D_global_asm_807530F0[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkDC->y_rotation + 0x800, 8.0f);
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = 0.0f;
            if (current_character_index[cc_player_index] == 4) {
                temp_f0 = current_actor_pointer->animation_state->unk0->unk4;
                if ((temp_f0 >= 29.0f) && (temp_f0 < 33.0f)) {
                    current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) & 0xFFF;
                    current_actor_pointer->unkB8 = 150.0f;
                    func_global_asm_806CC948();
                    break;
                } else if (temp_f0 >= 48.0f) {
                    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                    current_actor_pointer->unkB8 = 60.0f;
                    func_global_asm_806CC948();
                    break;
                }
            }
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC8B8();
            break;
        case 2:
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7510(void) {
    f32 temp_f0;
    f32 temp_f2;
    u8 temp_v1;

    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
            func_global_asm_806DF6D4(4);
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, (current_actor_pointer->unkEE + 0x800) & 0xFFF, (extra_player_info_pointer->unk48) << 0x1);
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.5;
            }
            break;
        case 1:
            func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
            extra_player_info_pointer->unk4 = 0.0f;
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.5;
            }
            break;
        case 2:
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806EB0C0(0x18, NULL, cc_player_index);
            break;
    }
    if (current_actor_pointer->unkAC < ( D_global_asm_807538C8[D_global_asm_807FD584] + current_actor_pointer->y_position)) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC -  D_global_asm_807538C8[D_global_asm_807FD584];
    }
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 2.0f;
    func_global_asm_806CC8F0();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7704(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->unkB8 = D_global_asm_80753144[D_global_asm_807FD584];
            func_global_asm_806DF6D4(5);
            extra_player_info_pointer->unk4 = D_global_asm_80753144[D_global_asm_807FD584];
            if (extra_player_info_pointer->unk1A3 != 0) {
                func_global_asm_80605314(current_actor_pointer, 0);
                extra_player_info_pointer->unk1A3 = 0;
            }
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation,
                          (current_actor_pointer->unkEE + 0x800) & 0xFFF,
                          (extra_player_info_pointer->unk48 << 0x1));
            break;
        case 1:
            func_global_asm_806DF6D4(3);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 2:
            func_global_asm_806DF6D4(3);
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7878(void) {
    f64 temp_f0 = current_actor_pointer->animation_state->scale_y;
    func_global_asm_807248B0(current_actor_pointer, ((D_global_asm_8075CDE0 - temp_f0) * D_global_asm_8075CDE8) + temp_f0);
    current_actor_pointer->shadow_opacity -= 0x14;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->shadow_opacity = 0;
    }
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806CC8B8();
            if (extra_player_info_pointer->unk11C-- == 0) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            if ((current_map != MAP_CAVES_BEETLE_RACE) && (current_map != MAP_AZTEC_BEETLE_RACE)) {
                func_global_asm_80712830(current_actor_pointer, cc_player_index);
            }
            current_actor_pointer->control_state_progress++;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D79E4(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7A28(void) {
    u8 temp_v0;

    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806DF6D4(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_acceleration = D_global_asm_80753024[D_global_asm_807FD584];
            if (D_global_asm_807FBB68 & 2) {
                playSound(0x424, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
            if (cc_number_of_players == 1) {
                func_global_asm_80627948(player_pointer, 0xC, 0x25, 0x85);
            }
            current_actor_pointer->control_state_progress++;
        case 1:
            extra_player_info_pointer->unk4 = D_global_asm_80753094[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, (current_actor_pointer->unkEE + 0x800) & 0xFFF, (extra_player_info_pointer->unk48 << 0x1));
            func_global_asm_806CC8B8();
            extra_player_info_pointer->unk11C = 0xF;
            extra_player_info_pointer->unk11D = 0;
            break;
        case 2:
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC970();
            break;
        case 3:
            temp_v0 = func_global_asm_80714608(0);
            if ((extra_player_info_pointer->unk11C == 0) && (extra_player_info_pointer->unk11D == 0)) {
                if ((temp_v0) == 0) {
                    func_global_asm_806CF918();
                }
                extra_player_info_pointer->unk11D = 1;
            } else {
                extra_player_info_pointer->unk11C--;
            }
            if (extra_player_info_pointer->unk11D != 0) {
                if (extra_player_info_pointer->unk11C >= 0xBF) {
                    if ((temp_v0 == 0) && ((extra_player_info_pointer->unk11C % 3) == 0)) {
                        func_global_asm_80608528(current_actor_pointer, ((extra_player_info_pointer->unk11C & 2) / 2) + 0x57, 0xFF, 0x7F, 0x1E);
                    }
                } else if (temp_v0 != 0) {
                    func_global_asm_80712830(current_actor_pointer, cc_player_index);
                }
            }
            if (((extra_player_info_pointer->unk1F0 & 0x1000) != 0) && ((object_timer & 3) == 0)) {
                func_global_asm_807149C8(0x64, 0x64, 0x64, 0xC8);
                func_global_asm_80714998(2);
                func_global_asm_8068588C(current_actor_pointer, (((rand() >> 0xF) % 32767) % 8) + 1, 0.4f, 0.0f, 0.0f, 0.0f, -0x50);
            }
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC970();
            break;
        default:
            if (cc_number_of_players >= 2) {
                func_global_asm_80712830(current_actor_pointer, cc_player_index);
            }
            extra_player_info_pointer->unk1F0 &= -0x1001;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7DF8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x45);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            func_global_asm_806DF6D4(0x44);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7E88(void) {
    s16 temp_v0;

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x46);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            if (func_global_asm_806DF6D4(0x46) == 0) {
                temp_v0 = func_global_asm_806CE4E4(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
                if (temp_v0 != 0x3F) {
                    current_actor_pointer->control_state = temp_v0;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7F48(void) {
    s16 temp_v0;

    func_global_asm_806CBE90();
    if (!func_global_asm_806DF6D4(0x46)) {
        temp_v0 = func_global_asm_806CE4E4(current_actor_pointer,
                                current_actor_pointer->unkB8,
                                extra_player_info_pointer->unk4,
                                1);

        if (temp_v0 != 0x40) {
            current_actor_pointer->control_state = temp_v0;
            current_actor_pointer->control_state_progress = 0;
            if (temp_v0 == 0x3F) {
                current_actor_pointer->control_state_progress = 1;
            }
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7FE8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(1);
            break;
        case 1:
            current_actor_pointer->control_state = 0x3C;
            current_actor_pointer->control_state_progress = 1;
            func_global_asm_80614E78(current_actor_pointer, 0xB);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D8070(void) {
    func_global_asm_806DF6D4(1);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D80A8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            func_global_asm_806DF6D4(0x47);
            func_global_asm_806CC948();
            func_global_asm_806CD8EC();
            extra_player_info_pointer->unk2C = D_global_asm_80753470[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = D_global_asm_8075348C[D_global_asm_807FD584];
            extra_player_info_pointer->unk38 = D_global_asm_80753454[D_global_asm_807FD584];
            extra_player_info_pointer->unk48 = D_global_asm_807534A8[D_global_asm_807FD584];
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_80753738[D_global_asm_807FD584];
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x47);
            func_global_asm_806CFE30();
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            func_global_asm_806CFE30();
            func_global_asm_806D3608();
            func_global_asm_806CC8B8();
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            func_global_asm_806DF6D4(0x47);
            break;
        case 3:
            func_global_asm_806DF6D4(0x35);
            if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
                func_global_asm_80614D00(current_actor_pointer, 3.0f, 0.0f);
            }
            extra_player_info_pointer->unk4 = 0.0f;
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D8308.s")

int func_global_asm_806D850C(void) {
    f32 sp2C;
    f32 phi_f2;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        sp2C = D_global_asm_8075388C[D_global_asm_807FD584];
    } else {
        sp2C = D_global_asm_807538C8[D_global_asm_807FD584];
    }
    if ((current_actor_pointer->control_state == 0x4E) && playerCanDive()) {
        if ((current_actor_pointer->control_state_progress != 0) && ((current_actor_pointer->y_position + sp2C) < (current_actor_pointer->unkAC - 10.0f))) {
            extra_player_info_pointer->unk12 = D_global_asm_807539EC[D_global_asm_807FD584];
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            extra_player_info_pointer->unk10 = D_global_asm_807539DC[D_global_asm_807FD584] * 0.5;
            current_actor_pointer->control_state = 0x4F;
            current_actor_pointer->control_state_progress = 1;
            if (current_actor_pointer->y_velocity > 0.0f) {
                current_actor_pointer->y_velocity = 0.0f;
            }
            func_global_asm_80614E78(current_actor_pointer, 0x36);
            func_global_asm_80613AF8(current_actor_pointer, 0x31, 0.0f, 8.0f);
            func_global_asm_80614D00(current_actor_pointer, 0.5f, 0.0f);
            func_global_asm_80608528(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
        }
    }
    if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + sp2C)) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC - sp2C;
    }
    phi_f2 = character_change_array[cc_player_index].unk2C0 == 1 ? D_global_asm_8075387C[D_global_asm_807FD584] : D_global_asm_807538B8[D_global_asm_807FD584];
    if ((current_actor_pointer->unkAC - current_actor_pointer->floor) < phi_f2) {
        func_global_asm_806EB0C0(2, NULL, cc_player_index);
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D87FC.s")

extern f32 D_global_asm_807539A4[];
extern f64 D_global_asm_8075CE08;
extern f32 D_global_asm_8075CE10;
extern f32 D_global_asm_80753988[];
extern s16 D_global_asm_80753B34[];

/*
// TODO: Very close, something iffy with the order of loading floats from those arrays
void func_global_asm_806D87FC(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp;
    f32 phi_f2;

    phi_f2 = D_global_asm_807539A4[D_global_asm_807FD584];
    temp = D_global_asm_80753988[D_global_asm_807FD584];
    if (current_actor_pointer->y_velocity < 0.0f) {
        if (!((-current_actor_pointer->y_velocity / 3.0f) < D_global_asm_807539A4[D_global_asm_807FD584])) {
            phi_f2 = -current_actor_pointer->y_velocity / 3.0f;
        }
    }
    if ((current_actor_pointer->distance_from_floor == 0.0f) && (current_actor_pointer->y_velocity < D_global_asm_8075CE08)) {
        current_actor_pointer->y_velocity = D_global_asm_8075CE10;
    }
    current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, temp, phi_f2);
    extra_player_info_pointer->unk24 = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x4E);
            func_global_asm_806CC8F0();
            break;
        case 1:
            func_global_asm_806DF6D4(0x4D);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkB8 != 0.0f) {
                func_global_asm_80614E78(current_actor_pointer, 0x3A);
                current_actor_pointer->control_state_progress = 2;
            }
            break;
        default:
            func_global_asm_806DF6D4(0x4D);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkB8 == 0.0f) {
                func_global_asm_80614E78(current_actor_pointer, 0x33);
                current_actor_pointer->control_state_progress = 1;
            } else {
                temp_f0_2 = (extra_player_info_pointer->unk4 * 1.5) / 40.0;
                if (current_actor_pointer->animation_state->unk48 < temp_f0_2) {
                    func_global_asm_80614D00(current_actor_pointer, temp_f0_2, 0.0f);
                } else {
                    func_global_asm_80614D00(current_actor_pointer, temp_f0_2, 5.0f);
                }
            }
            break;
    }
    func_global_asm_806D850C();
    current_actor_pointer->object_properties_bitfield &= -2;
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D8A64(void) {
    extra_player_info_pointer->unk24 = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            func_global_asm_806DF6D4(0x4B);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->z_rotation = 0;
            current_actor_pointer->x_rotation = 0;
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D8B08.s")

void func_global_asm_806D8FCC(void) {
    extra_player_info_pointer->unk24 = 0;
    current_actor_pointer->x_rotation = 0;
    current_actor_pointer->z_rotation = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806D3FA0();
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CC8F0();
            break;
        case 1:
            func_global_asm_806CC8B8();
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x21);
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806CFD68();
            break;
        case 3:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9134(void) {
    func_global_asm_806DF6D4(1);
    current_actor_pointer->unkB8 = 0.0f;
    current_actor_pointer->y_velocity = 0.0f;
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9184(void) {
    func_global_asm_806D9134();
}

void func_global_asm_806D91A4(void) {
    s32 phi_a2;

    if (current_actor_pointer->unkFC) {
        current_actor_pointer->unkB8 = 0.0f;
        func_global_asm_806CFF1C(current_actor_pointer);
    }
    if ((current_actor_pointer->unkFC != 0) || (current_actor_pointer->unk6A & 1 && (current_actor_pointer->unk6C & 1) == 0)) {
        func_global_asm_806224CC(extra_player_info_pointer->unk104, current_actor_pointer);
    }
    if (!(current_actor_pointer->unk6A & 1)) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_80714C08(&D_global_asm_8072014C, 0.8f, current_actor_pointer, 1, 0);
    }
    if (current_actor_pointer->unk6A & current_actor_pointer->unk6C & 1) {
        phi_a2 = 2;
    } else {
        phi_a2 = 1;
    }
    if ((!current_actor_pointer->unk6C & current_actor_pointer->unk6A & 1)) {
        current_actor_pointer->unkB8 *= 0.25;
    }
    if (current_actor_pointer->unkB8 < phi_a2) {
        current_actor_pointer->unkB8 = 0.0f;
    } else {
        current_actor_pointer->unkB8 -= phi_a2;
    }
    func_global_asm_806DF6D4(1);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D9320.s")

void func_global_asm_806D97A4(void) {
    func_global_asm_806DF6D4(5);
    if (current_actor_pointer->y_velocity < 0.0f) {
        extra_player_info_pointer->unk6C = 0.0f;
    }
    func_global_asm_806CD424(extra_player_info_pointer->unk70,
                  extra_player_info_pointer->unk6C,
                  extra_player_info_pointer->unk38);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9820(void) {
    f32 temp_f0;
    f32 temp_f4;

    func_global_asm_806DF6D4(0x4A);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk38 < current_actor_pointer->unkB8) {
                func_global_asm_806CD8EC();
                func_global_asm_806CC948();
            } else {
                func_global_asm_806CC8B8();
            }
            temp_f4 = current_actor_pointer->unkB8 * D_global_asm_8075CE68;
            temp_f0 = MAX((f64)(temp_f4), (s32)1.875);
            func_global_asm_80614D00(current_actor_pointer, temp_f0, 0.0f);
            break;
        case 1:
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9924(Actor *actor) {
    actor->z_rotation = 0;
    actor->x_rotation = 0;
    actor->object_properties_bitfield &= ~1;
}

void func_global_asm_806D9940(void) {
    s32 song;
    f32 phi_f0;

    func_global_asm_806DF6D4(1);
    if ((current_actor_pointer->control_state_progress < 3)
        || (func_global_asm_8061CB80()
        && (func_global_asm_8061CB98(7)
            || func_global_asm_8061CB98(0)
            || func_global_asm_8061CB98(4)
            || func_global_asm_8061CB98(9)
            || func_global_asm_8061CB98(8)))) {
        func_global_asm_80653B70(1);
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if ((D_global_asm_807FBB68 & 2) == 0) {
                current_actor_pointer->noclip_byte = 1;
            }
            break;
        case 1:
            song = 0xA;
            phi_f0 = 1.0f;
            switch (current_actor_pointer->unk58) {
                case 2:
                    song = 0xB;
                    break;
                case 5:
                    song = 0xD;
                    break;
                case 4:
                    song = 0xC;
                    if (!(D_global_asm_807FBB68 & 2)) {
                        phi_f0 = D_global_asm_8075CE70;
                    }
                    break;
                case 6:
                    song = 9;
                    break;
            }
            playSong(song, phi_f0);
            current_actor_pointer->control_state_progress++;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// close, doable, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D9AD4.s")

extern s32 D_global_asm_8071FC8C;
extern f64 D_global_asm_8075CE78;

int func_global_asm_80717100();

void func_global_asm_805FF9AC(enum map_e arg0, s32 arg1, s32 arg2, s16 arg3);

/*
void func_global_asm_806D9AD4(void) {
    s32 pad;
    f32 sp28;

    func_global_asm_806DF6D4(1);
    if ((current_actor_pointer->control_state_progress == 1) || (current_actor_pointer->control_state_progress == 2)) {
        rand();
        sp28 = current_actor_pointer->y_position + ((rand() >> 0xF) % 30);
        rand();
        func_global_asm_807149B8(1);
        func_global_asm_80714950((extra_player_info_pointer->unk23C << 0x10) + (s32)(15.0 * (current_actor_pointer->shadow_opacity / D_global_asm_8075CE78)));
        func_global_asm_8071498C(&func_global_asm_80717100);
        func_global_asm_80714CC0(&D_global_asm_8071FC8C, 0.5f, current_actor_pointer->x_position, sp28, current_actor_pointer->z_position);
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk23C = 0;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity = 0xFF;
            break;
        case 1:
            extra_player_info_pointer->unk23C += 0x1E;
            if (extra_player_info_pointer->unk23C > 0x190) {
                extra_player_info_pointer->unk23C = 0x190;
            }
            if (extra_player_info_pointer->unk23C == 0xD2) {
                func_global_asm_80608528(current_actor_pointer, 0x264, 0xFF, 0x64, 0x19);
            }
            if (extra_player_info_pointer->unk23C > 0x12C) {
                extra_player_info_pointer->unk1F0 &= ~0x40;
                current_actor_pointer->shadow_opacity -= 5;
                if (current_actor_pointer->shadow_opacity < 0xA) {
                    current_actor_pointer->control_state_progress++;
                }
            }
            break;
        case 2:
            func_global_asm_805FF9AC(extra_player_info_pointer->unk242, 0, 0, 3);
            current_actor_pointer->control_state_progress++;
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D9D58.s")

extern f32 D_global_asm_8075CE88;
extern f64 D_global_asm_8075CE80;

/*
void func_global_asm_806D9D58(void) {
    f32 phi_f0;

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_velocity = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            extra_player_info_pointer->unk30 = 1.0f;
            extra_player_info_pointer->unk2C = 3.0f;
            current_actor_pointer->y_acceleration = 2.0f;
            extra_player_info_pointer->unk23C = 0;
            extra_player_info_pointer->unk238 = current_actor_pointer->y_position;
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            func_global_asm_806DF6D4(0x43);
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            current_actor_pointer->y_position = extra_player_info_pointer->unk238;
            func_global_asm_806CC8B8();
            if ((extra_player_info_pointer->unk238 - current_actor_pointer->unk168) > 50.0f) {
                current_actor_pointer->y_position -= 1.0;
            }
            extra_player_info_pointer->unk238 = current_actor_pointer->y_position;
            current_actor_pointer->y_position = (func_global_asm_80612794(extra_player_info_pointer->unk23C) * 10.0) + extra_player_info_pointer->unk238;
            extra_player_info_pointer->unk23C += 0x64;
            phi_f0 = ABS(current_actor_pointer->y_position - current_actor_pointer->unk168);
            if (phi_f0 < D_global_asm_8075CE80) {
                current_actor_pointer->y_acceleration = 2.0 * ((current_actor_pointer->unk168 - current_actor_pointer->y_position) / D_global_asm_8075CE80);
            }
            if (current_actor_pointer->unk168 <= current_actor_pointer->y_position) {
                current_actor_pointer->y_velocity = 0.0f;
                current_actor_pointer->y_acceleration = D_global_asm_8075CE88;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806D9FD0.s")

void func_global_asm_806DA320(void) {
    f32 phi_f2;

    if (D_global_asm_807FBC58 != 0.0) {
        phi_f2 = D_global_asm_807FBC58;
    } else {
        phi_f2 = current_actor_pointer->unkB8;
    }
    func_global_asm_80614D00(current_actor_pointer, (phi_f2 / 25.0f) + 0.25, 2.0f);
    func_global_asm_806DF6D4(0x49);
    if ((current_actor_pointer->unk6A & 0x10) == 0) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

// regalloc, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DA3E4.s")

extern f64 D_global_asm_8075CEB8;

/*
void func_global_asm_806DA3E4(void) {
    f64 temp_f16;

    func_global_asm_806CA2AC();
    func_global_asm_806DF6D4(5);
    temp_f16 = D_global_asm_8075CEB8;
    current_actor_pointer->unkB8 = 0.0f;
    current_actor_pointer->x_position = ((extra_player_info_pointer->unk22C - current_actor_pointer->x_position) * temp_f16) + current_actor_pointer->x_position;
    current_actor_pointer->z_position = ((extra_player_info_pointer->unk234 - current_actor_pointer->z_position) * temp_f16) + current_actor_pointer->z_position;
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, func_global_asm_80665DE0(extra_player_info_pointer->unk220, extra_player_info_pointer->unk228, current_actor_pointer->x_position, current_actor_pointer->z_position), 0x32);
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DA4D8.s")

void func_global_asm_806DA7EC(void) {
    func_global_asm_806DF6D4(6);
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        func_global_asm_80614D00(current_actor_pointer, 3.0f, 0);
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA89C(void) {
    func_global_asm_806DF6D4(7);
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        func_global_asm_80614D00(current_actor_pointer, 2.0f, 0);
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA94C(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806CEE64(1.0f);
    func_global_asm_806CF0D0();
    func_global_asm_806CEED8();
    current_actor_pointer->control_state = func_global_asm_806CE928(current_actor_pointer,
                                                         current_actor_pointer->unkB8,
                                                         extra_player_info_pointer->unk4,
                                                         1);
    current_actor_pointer->control_state_progress = 0;
    func_global_asm_806DF6D4(0x37);
    if (!(current_actor_pointer->unk6A & 1)) {
        func_global_asm_806D3608();
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAA14(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806CEE64(1.0f);
    func_global_asm_806CF0D0();
    func_global_asm_806CEED8();
    current_actor_pointer->control_state = func_global_asm_806CE928(current_actor_pointer,
                                                         current_actor_pointer->unkB8,
                                                         extra_player_info_pointer->unk4,
                                                         1);
    current_actor_pointer->control_state_progress = 0;
    func_global_asm_806DF6D4(0x37);
    if ((current_actor_pointer->unk6A & 1) == 0) {
        func_global_asm_806D3608();
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAADC(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806DF6D4(0x3A);
    func_global_asm_806CEED8();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CEE64(0.5f);
            break;
        case 1:
            func_global_asm_806CEE64(0.5f);
            if (extra_player_info_pointer->unk1AC != 0) {
                func_global_asm_80679200(extra_player_info_pointer->unk1AC, current_actor_pointer, 0x2000, 0, 0, 0);
            }
            extra_player_info_pointer->unk1AC = NULL;
            extra_player_info_pointer->unk1B0 = 0;
            current_actor_pointer->control_state_progress += 1;
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DABE4(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806DF6D4(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CEE64(1.0f);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 1:
            func_global_asm_8067A784(current_actor_pointer, extra_player_info_pointer->unk1AC, current_player->y_rotation, D_global_asm_807533B8[D_global_asm_807FD584], D_global_asm_8075339C[D_global_asm_807FD584]);
            extra_player_info_pointer->unk1AC = NULL;
            extra_player_info_pointer->unk1B0 = 0;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unkB8 = D_global_asm_80753364[D_global_asm_807FD584];
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            break;
        default:
            if (current_actor_pointer->unkB8 != 0.0f) {
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                current_actor_pointer->unkB8 -= D_global_asm_80753380[D_global_asm_807FD584];
                if (current_actor_pointer->unkB8 < 0.0f) {
                    current_actor_pointer->unkB8 = 0.0f;
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DADA0(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806DF6D4(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CEE64(1.0f);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 1:
            func_global_asm_8067A784(current_actor_pointer, extra_player_info_pointer->unk1AC, current_player->y_rotation, D_global_asm_807533F0[D_global_asm_807FD584], D_global_asm_807533D4[D_global_asm_807FD584]);
            extra_player_info_pointer->unk1AC = NULL;
            extra_player_info_pointer->unk1B0 = 0;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unkB8 = D_global_asm_80753364[D_global_asm_807FD584];
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            break;
        default:
            if (current_actor_pointer->unkB8 != 0.0f) {
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                current_actor_pointer->unkB8 -= D_global_asm_80753380[D_global_asm_807FD584];
                if (current_actor_pointer->unkB8 < 0.0f) {
                    current_actor_pointer->unkB8 = 0.0f;
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAF5C(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806CEE64(1.0f);
    func_global_asm_806CEED8();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0);
            func_global_asm_806DF6D4(0x21);
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            func_global_asm_806D3608();
            func_global_asm_806DF6D4(0x39);
            func_global_asm_806CFD68();
            break;
        case 3:
            func_global_asm_806DF6D4(0x38);
            func_global_asm_806CFE7C();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DB08C(void) {
    func_global_asm_806DF6D4(0x12);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DB0C4.s")

extern f64 D_global_asm_8075CEF8;
extern f32 D_global_asm_8075CF00;
extern f64 D_global_asm_8075CF08;
extern f32 D_global_asm_8075CF10;

/*
void func_global_asm_806DB0C4(void) {
    Actor *temp_v1;
    f32 temp_f14;
    f32 temp_f20;

    if (D_global_asm_807FBB70.unkE4 != 0) {
        extra_player_info_pointer->unkDC = D_global_asm_807FBB70.unkEC;
        extra_player_info_pointer->unk9C = current_actor_pointer->x_position;
        extra_player_info_pointer->unkA0 = current_actor_pointer->z_position;
        extra_player_info_pointer->unkA4 = D_global_asm_807FBB70.unkD8;
        extra_player_info_pointer->unkA8 = D_global_asm_807FBB70.unkE0;
        extra_player_info_pointer->unkAC_f32 = 0.0f;
        temp_f20 = extra_player_info_pointer->unkA4 - extra_player_info_pointer->unk9C;
        temp_f14 = extra_player_info_pointer->unkA8 - extra_player_info_pointer->unkA0;
        extra_player_info_pointer->unk94 = sqrtf((temp_f20 * temp_f20) + (temp_f14 * temp_f14)) * D_global_asm_8075CEF8;
        extra_player_info_pointer->unk98 = ((func_global_asm_80611BB4(temp_f20, temp_f14) * 4096.0f) / D_global_asm_8075CF00);
        extra_player_info_pointer->unk4C = -1;
    }
    extra_player_info_pointer->unkAC_f32 += D_global_asm_8075CF08;
    if (extra_player_info_pointer->unkAC_f32 > 1.0) {
        if (extra_player_info_pointer->unkDC != NULL) {
            extra_player_info_pointer->unk98 = (func_global_asm_80611BB4(extra_player_info_pointer->unkDC->x_position - extra_player_info_pointer->unk9C, extra_player_info_pointer->unkDC->z_position - extra_player_info_pointer->unkA0) * 4096.0f) / D_global_asm_8075CF10;
            if (current_actor_pointer->y_rotation == extra_player_info_pointer->unk98) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
        }
        extra_player_info_pointer->unkAC_f32 = 1.0f;
    }
    current_actor_pointer->x_position = extra_player_info_pointer->unk9C + ((extra_player_info_pointer->unkA4 - extra_player_info_pointer->unk9C) * extra_player_info_pointer->unkAC_f32);
    current_actor_pointer->z_position = extra_player_info_pointer->unkA0 + ((extra_player_info_pointer->unkA8 - extra_player_info_pointer->unkA0) * extra_player_info_pointer->unkAC_f32);
    func_global_asm_806CC970();
    func_global_asm_806CDD24(current_actor_pointer, extra_player_info_pointer->unk94, extra_player_info_pointer->unk94, 0);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unk98, D_global_asm_8075326C[D_global_asm_807FD584] / 2);
    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DB3AC.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DB670.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DBB04.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DC170.s")

void func_global_asm_806DC3A4(f32 arg0) {
    f32 temp_f2;
    f32 phi_f0;

    phi_f0 = extra_player_info_pointer->unk94;
    temp_f2 = extra_player_info_pointer->unk4;
    if (phi_f0 < temp_f2) {
        phi_f0 = phi_f0 + arg0;
        phi_f0 = MIN(temp_f2, phi_f0);
    } else if (temp_f2 < phi_f0) {
        phi_f0 = phi_f0 - arg0;
        phi_f0 = MAX(temp_f2, phi_f0);
    }
    extra_player_info_pointer->unk94 = phi_f0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DC410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DCA7C.s")

extern f64 D_global_asm_8075CFD8;
extern f64 D_global_asm_8075CFE0;
extern f64 D_global_asm_8075CFE8;
extern f32 D_global_asm_8075CFF0;
extern f32 D_global_asm_80753CD0[];

/*
// TODO: Doable, made good progress, not sure what's going on with case 1
void func_global_asm_806DCA7C(Actor **arg0, s32 arg1) {
    f32 sp50;
    f32 sp4C;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 dx;
    f32 dz;
    s32 var_v0;
    s32 var_v1;

    current_actor_pointer->object_properties_bitfield &= 0xFFBFFFFF;
    current_actor_pointer->unk6A &= 0xFFBF;
    current_actor_pointer->z_rotation += (-current_actor_pointer->z_rotation * D_global_asm_8075CFD8);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DCF60();
            current_actor_pointer->unkB8 = extra_player_info_pointer->unk14C / 2;
            current_actor_pointer->unkEE = extra_player_info_pointer->unk154;
            var_v0 = current_actor_pointer->unkEE - current_actor_pointer->y_rotation;
            if (var_v0 < -0x800) {
                var_v0 += 0x1000;
            }
            if (var_v0 >= 0x801) {
                var_v0 -= 0x1000;
            }
            if (var_v0 > 0) {
                var_v1 = var_v0;
            } else {
                var_v1 = -var_v0;
            }
            if (var_v1 < 0x400) {
                func_global_asm_80614E78(current_actor_pointer, 0x6D);
            } else {
                func_global_asm_80614E78(current_actor_pointer, 0x6E);
            }
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x78, 0x600);
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk150;
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806DF6D4(0x27);
            extra_player_info_pointer->unk30 /= 2;
            func_global_asm_806CC948();
            break;
        case 2:
            if (extra_player_info_pointer->unk158 == 0) {
                func_global_asm_80614E78(current_player, 0x6F);
                current_actor_pointer->control_state_progress = 3;
            } else {
            case 1:
                func_global_asm_806DCF60();
                if (current_actor_pointer->unk58 == ACTOR_TINY) {
                    func_global_asm_806DF6D4(0x28);
                } else {
                    func_global_asm_806DF6D4(0x27);
                }
                current_actor_pointer->unkB8 = extra_player_info_pointer->unk14C;
                current_actor_pointer->unkEE = extra_player_info_pointer->unk154;
                func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x78, 0x600);
                extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
                extra_player_info_pointer->unk4 = 150.0f;
                extra_player_info_pointer->unk38 = 150.0f;
                if (extra_player_info_pointer->unk158 != 0) {
                    func_global_asm_80671C0C(extra_player_info_pointer->unk158, 1, &sp44, &sp40, &sp3C);
                    dx = sp44 - current_player->x_position;
                    dz = sp3C - current_player->z_position;
                    sp4C = (sp40 - current_player->y_position) / (current_player->animation_state->scale_y * D_global_asm_8075CFE0);
                    sp50 = ((sqrtf((dx * dx) + (dz * dz)) / (current_player->animation_state->scale_y * D_global_asm_8075CFE8)) / current_player->unkB8) - 1.0f;
                    if (sp50 < 1.0f) {
                        sp50 = 1.0f;
                    }
                }
                if ((extra_player_info_pointer->unk158 != 0) && (sp50 < 30.0f)) {
                    current_player->y_velocity = (((0.0 - (D_global_asm_80753CD0[D_global_asm_807FD584]) * 0.5 * (sp50 * sp50)) - sp4C)) / sp50;
                    current_player->y_acceleration = D_global_asm_8075CFF0;
                } else {
                    extra_player_info_pointer->unk158 = 0;
                    func_global_asm_806CFE7C();
                }
                func_global_asm_806CC948();
                break;
            }
            break;
        case 3:
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            extra_player_info_pointer->unk30 = 10.0f;
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DCF60.s")

f32 func_global_asm_80665E48(f32, f32, f32, f32);
extern f32 D_global_asm_8075CFF4;
extern f64 D_global_asm_8075CFF8;
extern f64 D_global_asm_8075D000;
extern f64 D_global_asm_8075D008;
extern f64 D_global_asm_8075D010;
extern f32 D_global_asm_8075D018;

/*
// TODO: Kinda close, good progress made
void func_global_asm_806DCF60(void) {
    Actor *temp_s0;
    f32 dx;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f28;
    f32 dz;
    f32 var_f14;
    f32 var_f26;
    s16 temp_s1;
    s16 temp_f16;
    s32 temp_f16_2;
    Actor *temp_v0;
    s32 i;
    Actor *temp_v1;

    temp_v0 = extra_player_info_pointer->unk158;
    var_f26 = 100.0f;
    if ((temp_v0 != NULL) || (current_actor_pointer->control_state_progress == 1)) {
        if (temp_v0 == NULL) {
            for (i = 0; i < i < D_global_asm_807FBB34; i++) {
                temp_s0 = D_global_asm_807FB930[i].unk0;
                if (!(temp_s0->object_properties_bitfield & 0x2000) && (temp_s0->object_properties_bitfield & 0x04000000) && (temp_s0 != extra_player_info_pointer->unk130) && (temp_s0 != current_player)) {
                    temp_f16 = ((func_global_asm_80665E48(temp_s0->x_position, temp_s0->z_position, current_player->x_position, current_player->z_position) * D_global_asm_8075CFF4) / D_global_asm_8075D000) * D_global_asm_8075CFF8;
                    dx = temp_s0->x_position - current_player->x_position;
                    temp_s1 = func_global_asm_806CC14C(temp_f16, extra_player_info_pointer->unk154);
                    dz = temp_s0->z_position - current_player->z_position;
                    temp_f0_2 = sqrtf((dx * dx) + (dz * dz));
                    if ((temp_s1 < 0x258) && (temp_f0_2 < var_f26)) {
                        if (current_player->y_position < temp_s0->y_position) {
                            var_f14 = temp_s0->y_position - current_player->y_position;
                        } else {
                            var_f14 = -(temp_s0->y_position - current_player->y_position);
                        }
                        if (var_f14 < 100.0) {
                            extra_player_info_pointer->unk154 = temp_f16;
                            extra_player_info_pointer->unk158 = temp_s0;
                        }
                    }
                }
            }
        } else {
            temp_f16_2 = ((func_global_asm_80665E48(temp_v0->x_position, temp_v0->z_position, current_player->x_position, current_player->z_position) * D_global_asm_8075D018) / D_global_asm_8075D008) * D_global_asm_8075D010;
            if (func_global_asm_806CC14C(temp_f16_2, extra_player_info_pointer->unk154) < 0x258) {
                extra_player_info_pointer->unk154 = temp_f16_2;
            }
        }
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DD24C.s")

void func_global_asm_806DD874(void) {
    current_actor_pointer->unkFA = 0x12C;
    func_global_asm_806CC8A8();
    switch (current_actor_pointer->control_state_progress) {
        case 1:
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) & 0xFFF;
            current_actor_pointer->y_velocity = D_global_asm_80753CB4[D_global_asm_807FD584];
            current_actor_pointer->unkB8 = 100.0f;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk3C = 3;
            func_global_asm_806DF6D4(0x29);
            extra_player_info_pointer->unk2C = 30.0f;
            extra_player_info_pointer->unk48 = 0x64;
            func_global_asm_806CFD68();
            extra_player_info_pointer->unk30 /= 2;
            func_global_asm_806CC948();
            break;
        case 2:
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x2A);
            } else {
                func_global_asm_806DF6D4(0x29);
            }
            extra_player_info_pointer->unk38 = 150.0f;
            func_global_asm_806D3608();
            func_global_asm_806CFD68();
            if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
                func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
            }
            if (extra_player_info_pointer->unk3C != 0) {
                func_global_asm_806CC948();
                extra_player_info_pointer->unk3C += -1;
            } else {
                func_global_asm_806CC8B8();
            }
            break;
        case 3:
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DDAB0.s")

extern f32 D_global_asm_80753D70[];
extern f32 D_global_asm_80753D8C[];
extern f64 D_global_asm_8075D048;
extern f64 D_global_asm_8075D050;
extern f64 D_global_asm_8075D058;
extern f64 D_global_asm_8075D060;

extern s16 D_global_asm_80753DA8[];
extern s16 D_global_asm_80753DB8[];

/*
// TODO: Very doable, made good progress
void func_global_asm_806DDAB0(void) {
    f32 sp64;
    u8 sp62;
    s16 sp60;
    f32 sp50;
    u8 sp4F;
    s8 sp4C;
    s16 sp4A;
    u8 sp49;
    f32 var_f2;
    s32 var_t6;
    s32 var_v0;
    s32 var_v0_2;
    u8 var_a2_2;
    u8 var_v1_2;

    sp49 = 0;
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        sp50 = D_global_asm_80753D70[D_global_asm_807FD584];
    } else {
        sp50 = D_global_asm_80753D8C[D_global_asm_807FD584];
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x5A);
            extra_player_info_pointer->unkEC = current_actor_pointer->y_rotation;
            extra_player_info_pointer->unkF8 = 5;
            current_actor_pointer->control_state_progress = 2;
            break;
        case 1:
        case 2:
        case 3:
            if (extra_player_info_pointer->unkF8 != 0) {
                extra_player_info_pointer->unkF8--;
            }
            if (func_global_asm_806DF6D4(0x5A) == 0) {
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        if (current_actor_pointer->control_state_progress == 1) {
                            var_f2 = MAX(current_actor_pointer->unkB8 * D_global_asm_8075D050, D_global_asm_8075D048);
                            func_global_asm_80614D00(current_actor_pointer, var_f2, 1.0f);
                            // func_global_asm_80614D00(current_actor_pointer, D_global_asm_8075D048, var_f2, 1.0f);
                        } else {
                            func_global_asm_80614E78(current_player, 0x77);
                            current_actor_pointer->control_state_progress = 1;
                        }
                        break;
                    case 0:
                        if (current_actor_pointer->control_state_progress != 2) {
                            func_global_asm_80614E78(current_player, 0x76);
                            current_actor_pointer->control_state_progress = 2;
                        }
                        break;
                    case 1:
                        if (current_actor_pointer->control_state_progress == 3) {
                            var_f2 = MAX(current_actor_pointer->unkB8 * D_global_asm_8075D060, D_global_asm_8075D058);
                            // func_global_asm_80614D00(D_global_asm_8075D058, current_actor_pointer, var_f2_2, 0, current_actor_pointer);
                            func_global_asm_80614D00(current_actor_pointer, var_f2, 0);
                        } else {
                            func_global_asm_80614E78(current_player, 0x78);
                            current_actor_pointer->control_state_progress = 3;
                        }
                        break;
                }
            }
            current_actor_pointer->y_velocity = 0.0f;
            current_actor_pointer->unkB8 = extra_player_info_pointer->unk4;
            if (func_global_asm_806CFC90(current_actor_pointer, &sp64, 1, 15.0f) != 0) {
                if ((current_actor_pointer->y_position <= sp64) && (((sp64 - sp50) - current_actor_pointer->y_position) < 10.0f) && (func_global_asm_80666AEC() != 0)) {
                    current_actor_pointer->y_position = sp64 - sp50;
                    sp49 = 1;
                }
            }
            if (current_actor_pointer->unkB8 < 0) {
                current_actor_pointer->unkB8 = ABS(current_actor_pointer->unkB8);
                current_actor_pointer->unkEE = current_actor_pointer->unkF4 + 0xA;
                sp60 = (extra_player_info_pointer->unkEA + 0x400) & 0xFFF;
            } else if (current_actor_pointer->unkB8 > 0) {
                current_actor_pointer->unkEE = current_actor_pointer->unkF6 - 0xA;
                sp60 = (extra_player_info_pointer->unkEA - 0x400) & 0xFFF;
            }
            sp62 = func_global_asm_8066F1F8(current_actor_pointer, sp60);
            if (sp62 == 0) {
                current_actor_pointer->unkB8 = 0;
            }
            extra_player_info_pointer->unkEC = func_global_asm_80672A70(current_actor_pointer->unkF4, current_actor_pointer->unkF6) + 0x800;
            extra_player_info_pointer->unkEC &= 0xFFF;
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkEC, 3.0f);
            current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
            current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
            if ((sp62 == 0) || (current_actor_pointer->unkB8 == 0.0)) {
                current_actor_pointer->object_properties_bitfield |= 0x800;
            } else {
                current_actor_pointer->object_properties_bitfield &= ~0x800;
            }
            break;
    }
    var_v0 = D_global_asm_807FD610[cc_player_index].unk2F < -0x32 && (D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG) != 0;
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        var_a2_2 = (var_v0 | ((current_actor_pointer->y_position - current_actor_pointer->floor) < D_global_asm_80753DA8[D_global_asm_807FD584]));
    } else {
        var_a2_2 = (var_v0 | ((current_actor_pointer->y_position - current_actor_pointer->floor) < D_global_asm_80753DB8[D_global_asm_807FD584]));
    }
    var_v1_2 = 0;
    if (extra_player_info_pointer->unkF8 == 0) {
        var_v0_2 = current_actor_pointer->unkFC == 0 || sp49 == 0;
        // var_v0_2 = current_actor_pointer->unkFC == 0;
        // if (var_v0_2 == 0) {
        //     var_v0_2 = sp49 == 0;
        // }
        sp4F = var_v0_2;
        func_global_asm_80666AC4(&sp4C, &sp4A);
        var_v1_2 = sp4F;
        if (sp4A < 0x385) {
            sp4F = (var_v0_2 | 1);
        }
    }
    if ((var_a2_2 != 0) || (sp4F != 0)) {
        extra_player_info_pointer->unkFC_s32 = 0x14;
        func_global_asm_806CFF9C(current_actor_pointer);
        current_actor_pointer->object_properties_bitfield &= ~0x800;
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2F >= 0x33) && (extra_player_info_pointer->unkF8 == 0) && (var_v1_2 == 0)) {
        func_global_asm_80614E78(current_player, 0x79);
        current_actor_pointer->control_state = 0x5C;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unkF0_f32 = current_actor_pointer->y_position + sp50;
        extra_player_info_pointer->unkF4_f32 = extra_player_info_pointer->unkF0_f32;
    }
    func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->unkEE);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665548();
    func_global_asm_80665564(current_actor_pointer, 0);
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DE264.s")

void func_global_asm_806DE930(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    if (!func_global_asm_806DF6D4(1)) {
        if (current_actor_pointer->unk6A & 1) {
            func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, 0.0f, 1);
        }
    }
    if (current_map == MAP_CAVES_BEETLE_RACE) {
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584] * 5.0;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DE9F4(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_8061C464(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x800, 0x32, 0, 5, 0x32, 0x14, 0, D_global_asm_8075D080);
        current_actor_pointer->control_state_progress += 1;
    }
    func_global_asm_806D38AC(1);
    extra_player_info_pointer->unk30 = D_global_asm_80750FDC;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DEAA4.s")

void func_global_asm_806DECD4(void) {
    if (current_actor_pointer->control_state_progress == 1) {
        func_global_asm_8061CB08();
        current_actor_pointer->control_state_progress++;
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DED44(void) {
    BoulderAAD *aaD;
    s8 phi_a1;
    s32 i;

    func_global_asm_806DF6D4(1);
    func_global_asm_806D9924(current_actor_pointer);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            // Have all fairies been photographed?
            if (func_global_asm_806F8EB4() == 20) {
                phi_a1 = 0x1A;
            } else {
                phi_a1 = 0x11;
            }
            playCutscene(current_actor_pointer, phi_a1, 5);
            current_actor_pointer->control_state_progress = 1;
            break;
        case 1:
            global_properties_bitfield &= 0xFFFEFFCF;
            spawnActor(ACTOR_FAIRY_REFILL, 0x3D);
            func_global_asm_8067B238(last_spawned_actor,
                          current_actor_pointer,
                          current_actor_pointer->animation_state->scale_y * 2);
            last_spawned_actor->object_properties_bitfield |= 0x40000000;
            last_spawned_actor->y_rotation += 0x800;
            last_spawned_actor->y_rotation &= 0xFFF;
            last_spawned_actor->unk11C = current_actor_pointer;
            func_global_asm_80614EBC(last_spawned_actor, 0x2B7);
            aaD = last_spawned_actor->additional_data_pointer;
            aaD->unk10 = current_actor_pointer;
            aaD->unk18 = current_actor_pointer->unk12C;
            if (aaD->unk18 == -1) {
                aaD->unk18 = 0;
            }
            aaD->unk16 = current_actor_pointer->z_rotation;
            aaD->unk14 = current_actor_pointer->x_rotation;
            func_global_asm_80659620(aaD, &aaD->unk4, &aaD->unk8, aaD->unk18);
            func_global_asm_80659670(1.0f, 1.0f, 1.0f, aaD->unk18);
            spawnActor(ACTOR_SPOTLIGHT, 0xA8);
            func_global_asm_8067B238(last_spawned_actor,
                          current_actor_pointer,
                          current_actor_pointer->animation_state->scale_x);
            last_spawned_actor->object_properties_bitfield |= 0x40000000;
            aaD->unkC = last_spawned_actor;
            aaD->unk1E = func_global_asm_806F8EB4() == 20; // Have all fairies been photographed?
            current_actor_pointer->control_state_progress = 2;
            break;
        case 2:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                func_global_asm_806874EC();
                playSong(0x3B, 1.0f);
                current_actor_pointer->control_state_progress = 3;
            }
            // fallthrough
        case 3:
            if (func_global_asm_80629148()) {
                PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
                func_global_asm_80629174();
                func_global_asm_806CFF9C(current_actor_pointer);
                func_global_asm_80709464(PaaD->unk1A4);
                
                for (i = 0; i < 4; i++) {
                    func_global_asm_806F91B4(D_global_asm_80750FE0[i], 0, 9999);
                    func_global_asm_806F8BC4(D_global_asm_80750FE0[i], 0, 0);
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF050(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    func_global_asm_806EB0C0(0x5C, NULL, cc_player_index);
    if (D_global_asm_80750AB8 == 0) {
        character_change_array[PaaD->unk1A4].unk2EA = 1;
    }
    character_change_array[PaaD->unk1A4].unk2EB = 1;
    current_actor_pointer->object_properties_bitfield &= ~0x8000;
    current_actor_pointer->shadow_opacity -= current_actor_pointer->shadow_opacity < 4 ? current_actor_pointer->shadow_opacity : 4;
    if (current_actor_pointer->shadow_opacity == 0) {
        if (D_global_asm_80750AB8 == 0) {
            // TODO: This is not ideal, conflicts with does_player_exist datatype
            *(u8*)(&character_change_array[PaaD->unk1A4]) = 0;
        }
        current_actor_pointer->object_properties_bitfield &= -5;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF1A0(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    current_actor_pointer->animation_state->scale_x = current_actor_pointer->animation_state->scale_x * D_global_asm_8075D0B8;
    current_actor_pointer->animation_state->scale_y = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->x_position += ((PaaD->unk22C - current_actor_pointer->x_position) * 0.125f);
    current_actor_pointer->y_position += ((PaaD->unk230 - current_actor_pointer->y_position) * 0.125f);
    current_actor_pointer->z_position += ((PaaD->unk234 - current_actor_pointer->z_position) * 0.125f);
    current_actor_pointer->x_rotation += 0xFF;
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF280(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;

    current_actor_pointer->animation_state->scale_x *= D_global_asm_8075D0C0;
    if (D_global_asm_8075D0C8 < current_actor_pointer->animation_state->scale_x) {
        current_actor_pointer->animation_state->scale_x = D_global_asm_8075D0D0;
        current_actor_pointer->control_state = 0xC;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->x_rotation = -0xFF;
    }
    current_actor_pointer->animation_state->scale_y = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->x_position += PaaD->unk220;
    current_actor_pointer->z_position += PaaD->unk228;
    current_actor_pointer->x_rotation += 0xFF;
    current_actor_pointer->x_rotation &= 0xFFF;
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF390(Actor *arg0, PlayerAdditionalActorData *arg1, u8 arg2) {
    s32 phi_a3;

    phi_a3 = 0x4A;
    if (arg2) {
        phi_a3 = 0x4C;
    }
    arg1->unk1A3 = 0;
    func_global_asm_80614E78(arg0, phi_a3);
}

void func_global_asm_806DF3D0(Actor *arg0, PlayerAdditionalActorData *arg1, u8 arg2) {
    s32 sp1C = 0x4B;
    s32 phi_a3 = 2;

    if (func_global_asm_806F8AD4(3, arg1->unk1A4)) {
        phi_a3 = 3;
    }
    func_global_asm_806F8BC4(phi_a3, 0, 0);
    if (arg2 != 0) {
        sp1C = 0x4D;
    }
    func_global_asm_80614E78(arg0, sp1C);
}

void func_global_asm_806DF44C(Actor* arg0, PlayerAdditionalActorData *arg1, u8 arg2) {
    if (arg1->unk8C != 0) {
        func_global_asm_806DF390(arg0, arg1, arg2);
        return;
    }
    func_global_asm_806DF3D0(arg0, arg1, arg2);
}

// Close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DF494.s")

/*
void func_global_asm_806DF494(s16 *arg0, s16 arg1, s16 arg2) {
    s16 phi_v0;
    s16 temp2;

    arg1 &= 0xFFF;
    phi_v0 = (arg1 - *arg0);
    if (phi_v0) {
        arg2 = ABS(phi_v0);
        phi_v0 /= arg2;
        if (arg2 >= 0x801) {
            arg2 = 0x1000 - arg2;
            phi_v0 *= -1;
        }
        if (arg2 < (ABS(arg2))) {
            *arg0 = arg1;
        } else {
            *arg0 += (phi_v0 * arg2);
            *arg0 &= 0xFFF;
        }
    }
}
*/

void func_global_asm_806DF5A0(s16 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 var_v0;
    s16 var_a2;

    arg1 &= 0xFFF;
    var_v0 = (arg1 - *arg0);
    if (var_v0) {
        var_a2 = ABS(var_v0);
        var_v0 &= 0xFFF;
        if (var_a2 >= 0x801) {
            var_a2 = 0x1000 - var_a2;
        }
        if (arg2 >= var_a2) {
            *arg0 = arg1;
        } else if (arg3 < var_v0) {
            *arg0 = *arg0 - arg2;
        } else {
            *arg0 = *arg0 + arg2;
        }
        *arg0 &= 0xFFF;
    }
}

void func_global_asm_806DF670(s16 *arg0, s16 arg1, s16 arg2) {
    s16 temp_v0 = arg1 - *arg0;
    if (temp_v0 != 0) {
        // TODO: Is there a better way to express this?
        if (((temp_v0 & 0xFFF) << 0x10 >> 0x10) + arg2 >= 0x1000) {
            *arg0 = arg1;
        } else {
            *arg0 = (*arg0 + arg2) & 0xFFF;
        }
    }
}

// doable, stack regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DF6D4.s")

/*
u16 func_global_asm_806DFF34(u16, s32 *);
extern s32 D_global_asm_80750FF0;
extern f64 D_global_asm_8075D0E0;
extern f32 D_global_asm_8075D0E8;

typedef struct {
    u16 unk0;
    s8 unk2;
    s8 unk3; // Used
} Struct807ECDEC;

extern Struct807ECDEC *D_global_asm_807ECDEC;

typedef struct {
    void (*unk0)(void); // Start Button Pressed Handler
    void (*unk4)(void); // Always Called (before input handlers)
    void (*unk8)(void); // A Button Pressed Handler
    void (*unkC)(void); // B Button Pressed Handler
    void (*unk10)(void); // Z Button Pressed Handler
    void (*unk14)(void); // A Button Released Handler
    void (*unk18)(void); // B Button Released Handler
    void (*unk1C)(void); // Z Button Released Handler
    void (*unk20)(void); // L Button Pressed Handler
    void (*unk24)(void); // R Button Pressed Handler
    void (*unk28)(void);
    void (*unk2C)(void); // R Button Released Handler
    void (*unk30)(void); // C-Up Pressed Handler
    void (*unk34)(void); // C-Left Pressed Handler
    void (*unk38)(void); // C-Right Pressed Handler
    void (*unk3C)(void); // C-Down Pressed Handler
    void (*unk40)(void); // Always Called (after input handlers)
} ControlStateInputHandler;
extern ControlStateInputHandler D_global_asm_80751004[]; // TODO: rodata?

extern u16 D_global_asm_807ECDF0;

s32 func_global_asm_806DF6D4(s32 controlState) {
    ControlStateInputHandler *inputHandler;
    f32 temp_f18;
    f32 var_f14; // sp44
    f32 var_f2; // sp40
    f32 temp_f8;
    f32 var_f16; // sp38
    s16 var_t0;
    s32 var_a0;
    s32 oldControlState; // sp2C
    f32 temp_f12;

    oldControlState = current_player->control_state;

    // Read button inputs
    D_global_asm_807FD610[cc_player_index].unk2A = func_global_asm_806DFF34(D_global_asm_807ECDEC->unk0, &D_global_asm_80750FF0);
    D_global_asm_807FD610[cc_player_index].unk2C = func_global_asm_806DFF34(D_global_asm_807ECDF0, &D_global_asm_80750FF0);

    // Buttons disabled?
    if (extra_player_info_pointer->unk1F4 & 0x20) {
        D_global_asm_807FD610[cc_player_index].unk2A = 0;
        D_global_asm_807FD610[cc_player_index].unk2C = 0;
    }

    // Read joystick inputs and clamp between -80 and 80
    D_global_asm_807ECDEC->unk2 = MIN(MAX(D_global_asm_807ECDEC->unk2, -80), 80);
    D_global_asm_807ECDEC->unk3 = MIN(MAX(D_global_asm_807ECDEC->unk3, -80), 80);
    D_global_asm_807FD610[cc_player_index].unk2E = D_global_asm_807ECDEC->unk2;
    D_global_asm_807FD610[cc_player_index].unk2F = D_global_asm_807ECDEC->unk3;

    // Joystick disabled?
    if (extra_player_info_pointer->unk1F4 & 0x20) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
        D_global_asm_807FD610[cc_player_index].unk2F = 0;
    }
    // Joystick movement halved?
    if (extra_player_info_pointer->unk1F0 & 0x100) {
        D_global_asm_807FD610[cc_player_index].unk2E *= 0.5;
        D_global_asm_807FD610[cc_player_index].unk2F *= 0.5;
    }
    // Joystick inverted?
    if (extra_player_info_pointer->unk1F0 & 0x80) {
        D_global_asm_807FD610[cc_player_index].unk2E = -D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2F = -D_global_asm_807FD610[cc_player_index].unk2F;
    }

    // Compute absolute joystick magnitude
    D_global_asm_807FD610[cc_player_index].unk30 = ABS(D_global_asm_807FD610[cc_player_index].unk2E);
    D_global_asm_807FD610[cc_player_index].unk31 = ABS(D_global_asm_807FD610[cc_player_index].unk2F);

    // Joystick deadzone
    if (D_global_asm_807FD610[cc_player_index].unk30 < 5 && D_global_asm_807FD610[cc_player_index].unk31 < 5) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
        D_global_asm_807FD610[cc_player_index].unk30 = 0;
        D_global_asm_807FD610[cc_player_index].unk2F = 0;
        D_global_asm_807FD610[cc_player_index].unk31 = 0;
    }
    if (D_global_asm_807FD610[cc_player_index].unk30 < 2) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
        D_global_asm_807FD610[cc_player_index].unk30 = 0;
    }
    if (D_global_asm_807FD610[cc_player_index].unk31 < 2) {
        D_global_asm_807FD610[cc_player_index].unk2F = 0;
        D_global_asm_807FD610[cc_player_index].unk31 = 0;
    }
    var_f14 = D_global_asm_807FD610[cc_player_index].unk30 * D_global_asm_807FD610[cc_player_index].unk30;
    var_f2 = D_global_asm_807FD610[cc_player_index].unk31 * D_global_asm_807FD610[cc_player_index].unk31;
    var_f16 = sqrtf(var_f14 + var_f2);
    if (var_f2 < var_f14) {
        temp_f12 = var_f14;
        var_f14 = var_f2;
        var_f2 = temp_f12;
    }
    if (var_f2 != 0.0f) {
        var_f16 *= (f32)(1.0 - ((var_f14 / var_f2) * D_global_asm_8075D0E0));
    }
    if (var_f16 > 70.0f) {
        var_f16 = 70.0f;
    }
    temp_f8 = D_global_asm_807FD610[cc_player_index].unk4;
    D_global_asm_807FD610[cc_player_index].unk4 = var_f16;
    D_global_asm_807FD610[cc_player_index].unkC = var_f16 - temp_f8;
    if (var_f16 != 0.0f) {
        D_global_asm_807FD610[cc_player_index].unk0 = 0;
        D_global_asm_807FD610[cc_player_index].unk8 = (var_f16 - 5.0f) / 65.0f;
    } else {
        D_global_asm_807FD610[cc_player_index].unk0++;
        D_global_asm_807FD610[cc_player_index].unk8 = 0.0f;
    }
    if (var_f16 != 0.0f) {
        var_t0 = (func_global_asm_80611BB4(D_global_asm_807FD610[cc_player_index].unk2E, -D_global_asm_807FD610[cc_player_index].unk2F) * 4096.0f) / D_global_asm_8075D0E8;
        D_global_asm_807FD610[cc_player_index].unk28 = (character_change_array[cc_player_index].unk2C8 + var_t0);
        D_global_asm_807FD610[cc_player_index].unk28 &= 0xFFF;
    } else {
        var_t0 = D_global_asm_807FD610[cc_player_index].unk20[0];
    }
    for (var_a0 = 3; var_a0 != 0; var_a0--) {
        D_global_asm_807FD610[cc_player_index].unk20[var_a0] = D_global_asm_807FD610[cc_player_index].unk20[var_a0 - 1];
        D_global_asm_807FD610[cc_player_index].unk10[var_a0] = D_global_asm_807FD610[cc_player_index].unk10[var_a0 - 1];
    }
    D_global_asm_807FD610[cc_player_index].unk20[var_a0] = var_t0;
    D_global_asm_807FD610[cc_player_index].unk10[var_a0] = var_f16;

    // Handle inputs for this control state
    inputHandler = &D_global_asm_80751004[controlState];
    inputHandler->unk4();
    if (D_global_asm_807FD610[cc_player_index].unk2A & START_BUTTON) {
        inputHandler->unk0();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & A_BUTTON) {
        inputHandler->unk8();
    } else {
        inputHandler->unk14();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & B_BUTTON) {
        inputHandler->unkC();
    } else {
        inputHandler->unk18();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) {
        inputHandler->unk10();
    } else {
        inputHandler->unk1C();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG) {
        inputHandler->unk24();
    } else {
        inputHandler->unk2C();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & L_TRIG) {
        inputHandler->unk20();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & U_CBUTTONS) {
        inputHandler->unk30();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & D_CBUTTONS) {
        inputHandler->unk3C();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & L_CBUTTONS) {
        inputHandler->unk34();
    }
    if (D_global_asm_807FD610[cc_player_index].unk2A & R_CBUTTONS) {
        inputHandler->unk38();
    }
    inputHandler->unk40();
    return current_player->control_state - oldControlState;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806DFF34.s")

/*
// TODO: Pretty close
u16 func_global_asm_806DFF34(u32 arg0, u16 *arg1) {
    u16 var_a2;
    u16 var_v1;
    u32 var_v0;

    var_v0 = *arg1;
    var_v1 = 0;
    var_a2 = 0;
    while (var_v0 != 0) {
        var_v1 |= var_v0;
        arg1++;
        if (var_v0 & arg0) {
            var_a2 |= arg1[0];
        }
        var_v0 = arg1[1];
        arg1++;
    }
    return (var_a2 | (arg0 & ~var_v1));
}
*/

f32 func_global_asm_806DFFA0(f32 arg0, s16 arg1, s16 arg2) {
    return func_global_asm_80612790(arg2 - arg1) * arg0;
}

void func_global_asm_806DFFDC(s16 arg0) {
    f32 temp_f0;

    temp_f0 = func_global_asm_806DFFA0(extra_player_info_pointer->unk4, extra_player_info_pointer->unkA, arg0);
    if (temp_f0 > 0.0f) {
        extra_player_info_pointer->unk4 = temp_f0;
    } else {
        extra_player_info_pointer->unk4 = 0.0f;
    }
    extra_player_info_pointer->unkA = arg0;
}

void func_global_asm_806E0050(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unkA = current_actor_pointer->y_rotation;
}

void func_global_asm_806E007C(void) {
    f32 temp_f2;
    f32 phi_f0 = extra_player_info_pointer->unk38;
    if (extra_player_info_pointer->unkC8 == 0) {
        phi_f0 *= 0.5;
    }
    if (extra_player_info_pointer->unkD6 != 0) {
        phi_f0 *= 0.5;
    }
    if ((D_global_asm_807FD610[cc_player_index].unk4 != 0.0f) && ((extra_player_info_pointer->unk1F4 & 8) == 0)) {
        temp_f2 = extra_player_info_pointer->unk34;
        extra_player_info_pointer->unk4 = ((D_global_asm_807FD610[cc_player_index].unk8 * (phi_f0 - temp_f2)) + temp_f2);
        extra_player_info_pointer->unkA = D_global_asm_807FD610[cc_player_index].unk28;
    } else {
        extra_player_info_pointer->unk4 = 0.0f;
        extra_player_info_pointer->unkA = current_actor_pointer->y_rotation;
    }
}

void func_global_asm_806E0178(void) {
    f32 phi_f0;
    f32 phi_f2;

    func_global_asm_806E007C();
    phi_f2 = D_global_asm_807FD610[cc_player_index].unk8;
    if (phi_f2 < D_global_asm_8075D0F0) {
        phi_f2 = D_global_asm_8075D0F8;
    }
    phi_f0 = ABS(current_actor_pointer->unkEE - extra_player_info_pointer->unkA);
    if (phi_f0 > 2048) {
        phi_f0 = 4096 - phi_f0;
    }
    phi_f0 = MIN(400, phi_f0);
    phi_f0 *= D_global_asm_8075D100;
    func_global_asm_806DF494(&current_actor_pointer->unkEE, extra_player_info_pointer->unkA,  phi_f0 * phi_f2);
}

void func_global_asm_806E0294(void) {
    f32 phi_f0;
    f32 phi_f2;

    func_global_asm_806E007C();
    phi_f2 = D_global_asm_807FD610[cc_player_index].unk8;
    if (D_global_asm_807FD610[cc_player_index].unk8 < D_global_asm_8075D108) {
        phi_f2 = D_global_asm_8075D110;
    }
    phi_f0 = ABS(current_actor_pointer->unkEE - extra_player_info_pointer->unkA);
    if (phi_f0 > 2048.0f) {
        phi_f0 = 4096.0f - phi_f0;
    }
    phi_f0 = MIN(400, phi_f0);
    phi_f0 *= (extra_player_info_pointer->unk48 / 400.0);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * phi_f2);
}

f32 func_global_asm_806E03C8(f32 arg0, f32 arg1) {
    f32 phi_f2;

    if (D_global_asm_807FD610[cc_player_index].unk30) {
        phi_f2 = MIN(70, D_global_asm_807FD610[cc_player_index].unk30);
        phi_f2 -= 2.0f;
        phi_f2 /= 68.0f;
        return ((arg1 - arg0) * phi_f2) + arg0;
    }
    return 0.0f;
}

f32 func_global_asm_806E0454(f32 arg0, f32 arg1) {
    f32 phi_f2;

    if (D_global_asm_807FD610[cc_player_index].unk31) {
        phi_f2 = MIN(70, D_global_asm_807FD610[cc_player_index].unk31);
        phi_f2 -= 2.0f;
        phi_f2 /= 68.0f;
        return ((arg1 - arg0) * phi_f2) + arg0;
    }
    return 0.0f;
}

void func_global_asm_806E04E0(void) {
    f32 phi_f2;
    f32 phi_f0;
    f32 phi_f3;

    func_global_asm_806E007C();
    if (D_global_asm_807FD610[cc_player_index].unkC > 0.0f) {
        phi_f2 = D_global_asm_807FD610[cc_player_index].unkC;
    } else {
        phi_f2 = -D_global_asm_807FD610[cc_player_index].unkC;
    }
    if (phi_f2 < 14.0f) {
        phi_f3 = (D_global_asm_807FD610[cc_player_index].unk8 * D_global_asm_8075D118) + D_global_asm_8075D120;
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        phi_f0 = MIN(400, phi_f0);
        phi_f0 *= (extra_player_info_pointer->unk48 / 400.0);
        phi_f2 = phi_f0 * phi_f3;
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f2);
    }
}

void func_global_asm_806E0654(void) {
    func_global_asm_806E007C();
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEA, extra_player_info_pointer->unk48);
}

void func_global_asm_806E0694(void) {
    func_global_asm_806E007C();
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
}

void func_global_asm_806E06E8(void) {
    s16 phi_a1;

    if (current_actor_pointer->unkDA < 0x3C7) {
        phi_a1 = current_actor_pointer->unkD8 + 0x800;
    } else {
        phi_a1 = current_actor_pointer->unkEE + 0x800;
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, phi_a1, extra_player_info_pointer->unk48 / 4);
    extra_player_info_pointer->unk4 = 0.0f;
}

void func_global_asm_806E077C(void) {
    s16 phi_a1;

    if (current_actor_pointer->unkDA < 0x3C7) {
        phi_a1 = current_actor_pointer->unkD8;
    } else {
        phi_a1 = current_actor_pointer->unkEE;
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, phi_a1, extra_player_info_pointer->unk48 / 4);
    extra_player_info_pointer->unk4 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E07F8.s")

/*
// TODO: WIP, quite close considering the size of it
void func_global_asm_806E07F8(void) {
    s16 temp_a1;
    s16 temp_v0_3;
    s32 temp_v0;
    f32 phi_f0;
    f32 phi_f0_2;
    Actor *phi_t9;
    u8 phi_v0;

    func_global_asm_806E007C();
    temp_a1 = current_actor_pointer->unkEE;
    temp_v0 = current_actor_pointer->y_rotation - temp_a1;
    if (temp_v0 > 0) {
        phi_f0 = temp_v0;
    } else {
        phi_f0 = -temp_v0;
    }
    phi_f0_2 = phi_f0;
    if (phi_f0 > 2048.0f) {
        phi_f0_2 = 4096.0f - phi_f0;
    }
    if (phi_f0_2 > 400.0f) {
        // TODO: Some float stuff missing here?
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, temp_a1, extra_player_info_pointer->unk48 / 4);
    if (current_actor_pointer->control_state != 0x14) {
        if ((current_actor_pointer->control_state == 0xF) && ((temp_v0_3 = ((s16*)current_actor_pointer->animation_state->unk0)[8], (temp_v0_3 == 0x1F2)) || (temp_v0_3 == 0x1B3))) {
            if (D_global_asm_807FD610[cc_player_index].unk2E < -0x1E) {
                func_global_asm_80614E78(current_actor_pointer, 0x61);
                current_actor_pointer->control_state = 0x10;
                current_actor_pointer->control_state_progress = 0;
            }
            if (D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) {
                func_global_asm_80614E78(current_actor_pointer, 0x5F);
                current_actor_pointer->control_state = 0x11;
                current_actor_pointer->control_state_progress = 0;
            } else {
                if (D_global_asm_807FD610[cc_player_index].unk2F >= 0x1F) {
                    func_global_asm_80614E78(current_actor_pointer, 0x63);
                    current_actor_pointer->control_state = 0x12;
                    current_actor_pointer->control_state_progress = 0;
                } else if (D_global_asm_807FD610[cc_player_index].unk2F < -0x1E) {
                    func_global_asm_80614E78(current_actor_pointer, 0x65);
                    current_actor_pointer->control_state = 0x13;
block_19:
                    current_actor_pointer->control_state_progress = 0;
                }
            }
        }
        // Joystick range check
        if (((D_global_asm_807FD610[cc_player_index].unk2E < 0x1E) && ((current_actor_pointer->control_state == 0x11))) || ((((D_global_asm_807FD610[cc_player_index].unk2F < -0x1D) == 0)) && ((current_actor_pointer->control_state == 0x13))) || ((D_global_asm_807FD610[cc_player_index].unk2F < 0x1E) && (current_actor_pointer->control_state == 0x12)) || ((D_global_asm_807FD610[cc_player_index].unk2E >= -0x1D) && (current_actor_pointer->control_state == 0x10))) {
            if ((current_character_index[cc_player_index] == 2) && (current_actor_pointer->control_state != 0x12)) {
                func_global_asm_80614EBC(current_actor_pointer, 0x191);
            } else {
                if (current_actor_pointer->control_state_progress == 1) {
                    switch (current_actor_pointer->control_state) {
                        case 17:
                            func_global_asm_80614E78(current_actor_pointer, 0x60);
                            break;
                        case 16:
                            func_global_asm_80614E78(current_actor_pointer, 0x62);
                            break;
                        case 18:
                            func_global_asm_80614E78(current_actor_pointer, 0x64);
                            break;
                        case 19:
                            func_global_asm_80614E78(current_actor_pointer, 0x66);
                            break;
                    }
                } else {
                    func_global_asm_80614E78(current_actor_pointer, 0x68);
                }
            }

            current_actor_pointer->control_state = 0xF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
}
*/

void func_global_asm_806E0BEC(void) {
    f32 phi_f0;
    f32 phi_f2;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        phi_f2 = D_global_asm_807FD610[cc_player_index].unk8;
        phi_f2 *= phi_f2;
        if (phi_f2 < D_global_asm_8075D128) {
            phi_f2 = D_global_asm_8075D130;
        }
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        phi_f0 = MIN(400, phi_f0);
        phi_f0 *= extra_player_info_pointer->unk48 / 400.0;
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * phi_f2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E0D40.s")

extern f64 D_global_asm_8075D138;
extern f64 D_global_asm_8075D140;

/*
// TODO: Something missing...
void func_global_asm_806E0D40(void) {
    f32 var_f0;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        var_f0 = ABS( current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (var_f0 > 2048.0f) {
            var_f0 = 4096.0f - var_f0;
        }
        if (var_f0 > 400.0f) {

        }
        current_actor_pointer->y_rotation -= ((D_global_asm_807FD610[cc_player_index].unk2E * extra_player_info_pointer->unk48) / 400);
        if (current_actor_pointer->y_rotation >= 0x1000) {
            current_actor_pointer->y_rotation -= 0x1000;
        }
        if (current_actor_pointer->y_rotation < 0) {
            current_actor_pointer->y_rotation += 0x1000;
        }
    }
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & 0x2000)) {
        extra_player_info_pointer->unk1A0 = ((D_global_asm_807FD610[cc_player_index].unk2F * 0xCC) * D_global_asm_8075D138) + D_global_asm_8075D140;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E0FAC.s")

extern f64 D_global_asm_8075D148;
extern f32 D_global_asm_8075D150;

typedef struct {
    u8 unk0[0x96 - 0x0];
    u16 unk96[1]; // TODO: How many elements?
    u8 unk98[0xA4 - 0x98];
    u16 unkA4[1]; // TODO: How many elements?
    u8 unkA6[0x478 - 0xA6];
    u16 unk478[1]; // TODO: How many elements?
    u16 unk47A;
    s32 unk47C;
    s32 unk480;
    s16 unk484;
    u16 unk486[1]; // TODO: How many elements?
} Struct807FBB54;

extern Struct807FBB54 D_global_asm_807FBB54;

/*
// TODO: Good progress
void func_global_asm_806E0FAC(void) {
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f2;
    f32 var_f2_2;
    s16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a1_5;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        if (current_actor_pointer->unkB8 == 0.0f) {
            temp_f2 = D_global_asm_807FD610[cc_player_index].unk8;
            var_f2 = temp_f2 * temp_f2;
            if (var_f2 < D_global_asm_8075D148) {
                var_f2 = D_global_asm_8075D150;
            }
            var_f0 = current_actor_pointer->y_rotation - extra_player_info_pointer->unkA;
            if (var_f0 >= 2048.0f) {
                var_f0 -= 4096.0f;
            }
            if (var_f0 <= -2048.0f) {
                var_f0 += 4096.0f;
            }
            if (var_f0 > 400.0f) {
                var_f0 = 400.0f;
            }
            if (var_f0 < -400.0f) {
                var_f0 = -400.0f;
            }
            temp_f0 = (var_f0 * (extra_player_info_pointer->unk48 / 400.0)) * var_f2;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, ABS(temp_f0));
            if (temp_f0 != 0.0f) {
                if (current_actor_pointer->control_state != 0x3C) {
                    if (current_actor_pointer->control_state == 0x62) {
                        temp_a1_2 = D_global_asm_807FBB54.unk478[current_actor_pointer->unk58];
                        if (temp_a1_2 != current_actor_pointer->animation_state->unk64) {
                            func_global_asm_80614EBC(current_actor_pointer, temp_a1_2);
                        }
                        func_global_asm_80614D00(current_actor_pointer, temp_f0 / 80.0, 0.0f);
                    }
                } else {
                    temp_a1_3 = D_global_asm_807FBB54.unkA4[current_actor_pointer->unk58];
                    if (temp_a1_3 != current_actor_pointer->animation_state->unk64) {
                        func_global_asm_80614EBC(current_actor_pointer, temp_a1_3);
                    }
                    func_global_asm_80614D00(current_actor_pointer, temp_f0 / 80.0, 0.0f);
                }
            }
            // goto block_32;
        }
        // goto block_25;
    }
block_25:
    if (current_actor_pointer->control_state != 0x3C) {
        if (current_actor_pointer->control_state == 0x62) {
            temp_a1_4 = D_global_asm_807FBB54.unk486[current_actor_pointer->unk58];
            if (temp_a1_4 != current_actor_pointer->animation_state->unk64) {
                func_global_asm_80614EBC(current_actor_pointer, temp_a1_4);
            }
        }
    } else if (current_actor_pointer->control_state_progress == 1) {
        temp_a1_5 = D_global_asm_807FBB54.unk96[current_actor_pointer->unk58];
        if (temp_a1_5 != current_actor_pointer->animation_state->unk64) {
            func_global_asm_80614EBC(current_actor_pointer, temp_a1_5);
        }
    }
    extra_player_info_pointer->unk4 = 0.0f;
}
*/

void func_global_asm_806E1334(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2F < 0) {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BDC[D_global_asm_807FD584], D_global_asm_80753BF8[D_global_asm_807FD584]);
    } else {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BA4[D_global_asm_807FD584], D_global_asm_80753BC0[D_global_asm_807FD584]);
    }
    if (extra_player_info_pointer->unk4 != 0.0f) {
        extra_player_info_pointer->unk8 = extra_player_info_pointer->unk4 > 0.0f ? 1 : -1;
    } else {
        extra_player_info_pointer->unk8 = 0;
    }
    func_global_asm_8072FE60(D_global_asm_807FD610[cc_player_index].unk2F / 80.0);
    current_actor_pointer->y_rotation += D_global_asm_807FD610[cc_player_index].unk2E;
    current_actor_pointer->y_rotation &= 0xFFF;
    func_global_asm_806E1630();
}

void func_global_asm_806E14DC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2F < 0) {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BDC[D_global_asm_807FD584], D_global_asm_80753BF8[D_global_asm_807FD584]);
    } else {
        extra_player_info_pointer->unk4 = func_global_asm_806E0454(D_global_asm_80753BA4[D_global_asm_807FD584], D_global_asm_80753BC0[D_global_asm_807FD584]);
    }
    if (extra_player_info_pointer->unk4 != 0.0f) {
        extra_player_info_pointer->unk8 = extra_player_info_pointer->unk4 > 0.0f ? 1 : -1;
    } else {
        extra_player_info_pointer->unk8 = 0;
    }
    func_global_asm_8072FE60(D_global_asm_807FD610[cc_player_index].unk2F / 80.0);
}

void func_global_asm_806E1630(void) {
    s16 phi_a1 = FALSE;
    if (extra_player_info_pointer->unk19C < extra_player_info_pointer->unk19E) {
        if ((current_actor_pointer->y_rotation < extra_player_info_pointer->unk19C) || (extra_player_info_pointer->unk19E < current_actor_pointer->y_rotation)) {
            phi_a1 = TRUE;
        }
    } else {
        if ((extra_player_info_pointer->unk19E < current_actor_pointer->y_rotation) && (current_actor_pointer->y_rotation < extra_player_info_pointer->unk19C)) {
            phi_a1 = TRUE;
        }
    }
    if (phi_a1) {
        if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, extra_player_info_pointer->unk19C) < func_global_asm_806CC14C(current_actor_pointer->y_rotation, extra_player_info_pointer->unk19E)) {
            current_actor_pointer->y_rotation = extra_player_info_pointer->unk19C;
        } else {
            current_actor_pointer->y_rotation = extra_player_info_pointer->unk19E;
        }
    }
}

void func_global_asm_806E1728(void) {
    f32 temp_f0 = func_global_asm_806E03C8(D_global_asm_80753DC8[D_global_asm_807FD584], D_global_asm_80753DE4[D_global_asm_807FD584]);
    if (D_global_asm_807FD610[cc_player_index].unk2E < 0) {
        extra_player_info_pointer->unk4 = -temp_f0;
        extra_player_info_pointer->unk8 = -1;
    } else {
        extra_player_info_pointer->unk4 = temp_f0;
        if (temp_f0 != 0.0f) {
            extra_player_info_pointer->unk8 = 1;
        } else {
            extra_player_info_pointer->unk8 = 0;
        }
    }
}

void func_global_asm_806E17F4(void) {
    func_global_asm_806E007C();
    func_global_asm_806DF494(&current_actor_pointer->unkEE, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806DFFDC(current_actor_pointer->y_rotation);
}

void func_global_asm_806E1864(void) {

}

void func_global_asm_806E186C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    current_actor_pointer->z_rotation = 0;
    current_actor_pointer->x_rotation = 0;
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (extra_player_info_pointer->unkC8 == -1)) {
        if (current_actor_pointer->unkE0 != 0.0f) {
            current_actor_pointer->unkEE = current_actor_pointer->unkDC;
            current_actor_pointer->unkB8 = 200.0f;
            extra_player_info_pointer->unk3E = 0x1E;
            extra_player_info_pointer->unk40 = current_actor_pointer->unkDC;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584] * 0.5;
        } else {
            extra_player_info_pointer->unk3C = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        }
        extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
        current_actor_pointer->control_state = 0x17;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x10);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E1A50() {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    // TODO: Get rid of this typecast if possible
    if ((u32) (D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if (((current_actor_pointer->unk6A & 1) == 0) || 
             (current_actor_pointer->unkE0 == 0.0f)) {
            extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
            current_actor_pointer->control_state = 0x17;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            func_global_asm_80614EBC(current_actor_pointer, 0xB0);
            extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        }
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E1BA4.s")

/*
void func_global_asm_806E1BA4(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (!(current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkE0 == 0.0f))) {
        extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
        current_actor_pointer->unkB8 = MIN(current_actor_pointer->unkB8, extra_player_info_pointer->unk38);
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
        extra_player_info_pointer->unk2C = 20.0f;
        current_actor_pointer->control_state = 0x17;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x10);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}
*/

void func_global_asm_806E1D38(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (!(current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkE0 == 0.0f))) {
        current_actor_pointer->control_state = 0x17;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614EBC(current_actor_pointer, 0xAF);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E1E54(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if (current_actor_pointer->y_acceleration == -260.0f) {
            current_actor_pointer->y_acceleration = -31.0f;
        } else {
            func_global_asm_806CFE7C();
        }
        current_actor_pointer->control_state = 0x14;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x67);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E1F8C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (extra_player_info_pointer->unk8D == 0)) {
        current_actor_pointer->control_state = 0x41;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614EBC(current_actor_pointer, 0x156);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E208C(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) && D_global_asm_807FC950[cc_player_index].character_progress[3].moves >= 2 && current_map != MAP_AZTEC_BEETLE_RACE) {
        func_global_asm_806EB0C0(9, NULL, cc_player_index);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

void func_global_asm_806E2140(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (D_global_asm_80767CC0 - extra_player_info_pointer->unk58 < 0xFU && (!(current_actor_pointer->unk6A & 1) || current_actor_pointer->unkE0 == 0.0f)) {
        current_actor_pointer->control_state = 0x61;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x50);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

// handle gunshots, jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E225C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E2B20.s")

extern f64 D_global_asm_8075D190;

u8 func_global_asm_80671E00(f32, f32, f32, f32, s16*, s16*, f32*, f32*);

/*
// TODO: Pretty close
u8 func_global_asm_806E2B20(Actor *arg0) {
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    s16 sp66;
    s16 sp64;
    f64 temp_f24;
    f32 phi_f20;
    u8 phi_v1;

    phi_v1 = 0;
    phi_f20 = 0.0f;
    func_global_asm_80671C0C(arg0, 4, &sp78, &sp70, &sp68);
    func_global_asm_80671C0C(arg0, 0xA, &sp7C, &sp74, &sp6C);
    phi_f20 = 0.0f;
    temp_f24 = D_global_asm_8075D190;
    while (!phi_v1 && phi_f20 <= 1.0) {
        phi_v1 = func_global_asm_80671E00(((sp7C - sp78) * phi_f20) + sp78,
                                ((sp74 - sp70) * phi_f20) + sp70,
                                ((sp6C - sp68) * phi_f20) + sp68,
                                10.0f,
                                &sp66,
                                &sp64,
                                0,
                                0);
        phi_f20 += temp_f24;
    }
    return phi_v1;
}
*/

// Jumptable lol
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E2C74.s")

u8 playerCanThrowOrange(void) {
    return !func_global_asm_80714608(0)
        && !(D_global_asm_807FBB64 & 0x200)
        && func_global_asm_806F8AD4(4, cc_player_index)
        && current_character_index[cc_player_index] < 6
        && func_global_asm_8067ACDC(current_actor_pointer, 4, 0) < D_global_asm_80753E64[D_global_asm_807FD584]
        && (isFlagSet(0x184, FLAG_TYPE_PERMANENT) // Is orange barrel completed?
            || (D_global_asm_807FBB64 & 0x10000000)
            || (cc_number_of_players > 1)
            || gameIsInDKTVMode()
            || gameIsInMysteryMenuMinigameMode());
}

void func_global_asm_806E2DE8(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS) && playerCanThrowOrange()) {
        func_global_asm_80614E78(current_actor_pointer, 0x47);
        current_actor_pointer->control_state = 0x2C; // Throwing orange
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E2E6C() {
    if (D_global_asm_807FD568->unk2 & 1) {
        func_global_asm_806E225C(0, 0);
    }
}

void func_global_asm_806E2EA8() {
    func_global_asm_806E225C(1, 0);
}

void func_global_asm_806E2ECC(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == B_BUTTON) {
        func_global_asm_80614E78(current_actor_pointer, 0x54);
    } else {
        func_global_asm_806E225C(0, 0);
    }
}

void func_global_asm_806E2F3C(void) {
    s32 phi_v1 = 1;
    if (cc_number_of_players >= 2) {
        phi_v1 = !func_global_asm_806E56EC();
    }
    if (phi_v1 != 0) {
        if ((current_actor_pointer->control_state != 0x62) && (current_actor_pointer->unk6A & 1)) {
            extra_player_info_pointer->unk48 = D_global_asm_80753354[D_global_asm_807FD584];
            current_actor_pointer->control_state = 0x62;
            current_actor_pointer->control_state_progress = 0;
            func_global_asm_80614E78(current_actor_pointer, 0x52);
        }
    }
}

void func_global_asm_806E2FE8(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG)) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E3040.s")

extern f32 D_global_asm_8075371C[];
extern f32 D_global_asm_8075378C[];

/*
void func_global_asm_806E3040(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && (current_character_index[cc_player_index] != 6) && ((((current_actor_pointer->unk6A & 1) == 0)) || (current_actor_pointer->unkE0 == 0.0f))) {
        PlayerAdditionalActorData *PaaD = extra_player_info_pointer;
        if (PaaD->unk20 > 70.0f) {
            current_actor_pointer->control_state = 0x1D;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_8075378C[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            func_global_asm_80614E78(current_actor_pointer, 0x1A);
            extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        } else {
            current_actor_pointer->control_state = 0x3E;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_8075371C[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            func_global_asm_80614E78(current_actor_pointer, 0xE);
            extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        }
    }
}
*/

void func_global_asm_806E31FC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if ((current_actor_pointer->control_state == 0x17) && (((current_actor_pointer->unk6A & 1) == 0) || (current_actor_pointer->unkE0 == 0.0f))) {
            current_actor_pointer->control_state = 0x17;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            func_global_asm_80614E78(current_actor_pointer, 0x10);
        }
    }
}

void func_global_asm_806E330C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        if ((current_actor_pointer->control_state == 0x61) && (((current_actor_pointer->unk6A & 1) == 0) || (current_actor_pointer->unkE0 == 0.0f))) {
            current_actor_pointer->control_state = 0x61;
            current_actor_pointer->control_state_progress = 0;
            extra_player_info_pointer->unk54 = D_global_asm_807535CC[D_global_asm_807FD584];
            extra_player_info_pointer->unk50 = 0;
            func_global_asm_80614E78(current_actor_pointer, 0x50);
        }
    }
}

void func_global_asm_806E341C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280;
    }
    if ((D_global_asm_80767A40.unk280 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 0x58;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk50 = 0;
        extra_player_info_pointer->unk3E = 0;
        extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280 - 0x1E;
    }
}

void func_global_asm_806E34D8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & R_TRIG) {
        current_actor_pointer->unkEE = (current_actor_pointer->unkEE + 0x800) & 0xFFF;
    }
}

void func_global_asm_806E352C(void) {
    current_actor_pointer->unk6A &= ~0x40;
    extra_player_info_pointer->unk100 = D_global_asm_80753C94[D_global_asm_807FD584];
    current_actor_pointer->control_state = 0x17;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->unkB8 = 0.0f;
    extra_player_info_pointer->unk54 = D_global_asm_80753D08[D_global_asm_807FD584];
    extra_player_info_pointer->unk50 = 0;
    func_global_asm_80614E78(current_actor_pointer, 0x10);
}

void func_global_asm_806E35D8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    // TODO: Get rid of this typecast if possible
    if ((u32) (D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 0x5A;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk3E = 0;
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x74);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E36B4.s")

void func_global_asm_806E380C(void) {
    func_global_asm_806CFEA4();
}

void func_global_asm_806E382C(void) {
    func_global_asm_806CFE7C();
}

void func_global_asm_806E384C(void) {
    s32 temp_f18;
    f32 temp_f2;
    f32 phi_f0;

    phi_f0 = extra_player_info_pointer->unk1A0 + 0x9E8;
    if (phi_f0 >= 32768) {
        phi_f0 -= 65536;
    }
    phi_f0 /= 16;
    if (current_actor_pointer->unk6E[0] == -1) {
        func_global_asm_80604CBC(current_actor_pointer, 0x114, 0, 0, 0, 0xFF, 1.0f, 0);
    }
    current_actor_pointer->y_acceleration = (-2 * D_global_asm_807536E4[D_global_asm_807FD584] * func_global_asm_80612790(phi_f0)) + D_global_asm_807536E4[D_global_asm_807FD584];
    if (current_actor_pointer->y_velocity < 0) {
        current_actor_pointer->y_acceleration -= (current_actor_pointer->y_velocity / 100.0);
    }
    if (current_actor_pointer->unk6A & 1) {
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
    } else {
        temp_f2 = func_global_asm_80612794(phi_f0) * 8.0f;
        if (temp_f2 >= 0) {
            phi_f0 = current_actor_pointer->y_rotation;
        } else {
            phi_f0 = current_actor_pointer->y_rotation + 0x800;
            if (phi_f0 > 4096) {
                phi_f0 -= 4096;
            }
        }
        extra_player_info_pointer->unk2C = ABS(temp_f2);
        func_global_asm_806CD424(phi_f0, 900, extra_player_info_pointer->unk38);
        extra_player_info_pointer->unk30 = ((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / D_global_asm_8075D214) + 1.0f;
    }
    extra_player_info_pointer->unk1A2 = 1;
}

void func_global_asm_806E3B00(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        if (func_global_asm_806F8AD4(5, cc_player_index) && (extra_player_info_pointer->unk1A3)) {
            func_global_asm_806E384C();
        } else {
            func_global_asm_80605314(current_actor_pointer, 0);
            current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = ((current_actor_pointer->unkB8 * current_actor_pointer->unkB8) / D_global_asm_8075D218) + 1.0f;
        }
    } else {
        current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
    }
    func_global_asm_806CD8EC();
}

void func_global_asm_806E3C14(void) {
    func_global_asm_806F142C(current_actor_pointer);
}

void func_global_asm_806E3C38(void) {
    f32 temp_f0;

    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        func_global_asm_80605314(current_actor_pointer, 0);
    }
    current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
    temp_f0 = current_actor_pointer->unkB8;
    extra_player_info_pointer->unk30 = ((temp_f0 * temp_f0) / D_global_asm_8075D21C) + 1.0f;
    func_global_asm_806CD8EC();
}

void func_global_asm_806E3CEC(void) {
    extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
}

void func_global_asm_806E3D14(f32 arg0) {
    f32 phi_f0;

    if (extra_player_info_pointer->unk1A0 < 0x8000) {
        phi_f0 = extra_player_info_pointer->unk1A0 + 0x10000;
    } else {
        phi_f0 = extra_player_info_pointer->unk1A0;
    }
    if (arg0 < phi_f0) {
        phi_f0 -= D_global_asm_8075D220;
        phi_f0 = MAX(arg0, phi_f0);
    }
    if (phi_f0 < arg0) {
        phi_f0 += D_global_asm_8075D224;
        phi_f0 = MIN(arg0, phi_f0);
    }
    extra_player_info_pointer->unk1A0 = phi_f0;
}

// rodata regalloc close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E3E40.s")

extern f32 D_global_asm_8075D228;
extern f64 D_global_asm_8075D230;
extern f64 D_global_asm_8075D238;
extern f32 D_global_asm_8075D240;
extern u8 D_global_asm_807FD6E0;
extern u8 D_global_asm_807FD6E1;

/*
void func_global_asm_806E3E40(void) {
    f32 sp34; // sp34
    s32 pad; // sp30
    f32 var_f12;
    f32 var_f2;

    if (!func_global_asm_806F8AD4(5, cc_player_index) || !extra_player_info_pointer->unk1A3) {
        return;
    }

    if (D_global_asm_807FD610[cc_player_index].unk2C & 0x2000) {
        D_global_asm_807FD6E0 = 0;
        D_global_asm_807FD6E1 = 0;
    }
    sp34 = (current_actor_pointer->unkEE - current_actor_pointer->y_rotation);
    if (sp34 < 0) {
        sp34 += 4096;
    }
    var_f2 = func_global_asm_80612794(sp34) * current_actor_pointer->unkB8;
    if (ABS(var_f2) > 10) {
        var_f12 = sp34 > 2048 ? 1024 : 3072;
        var_f12 += current_actor_pointer->y_rotation;
        if (var_f12 >= 4096) {
            var_f12 -= 4096;
        }
        extra_player_info_pointer->unk2C = 8;
        func_global_asm_806CD424(var_f12, 0, extra_player_info_pointer->unk38);
    }
    sp34 = func_global_asm_80612790(sp34) * current_actor_pointer->unkB8;
    var_f2 = current_actor_pointer->y_velocity;
    if (var_f2 > 0) {
        var_f2 = 0;
    }
    if (ABS(sp34) > 10) {
        var_f12 = D_global_asm_8075D238 + (((func_global_asm_80611BB4(ABS(var_f2), sp34) - D_global_asm_8075D228) * 16384.0) / D_global_asm_8075D230);
    } else {
        var_f12 = D_global_asm_8075D240;
    }
    func_global_asm_806E3D14(var_f12);
    if (((ABS(sp34) > 10) || (current_actor_pointer->y_velocity < 0))) {
        if (D_global_asm_807FD6E1 == 0) {
            D_global_asm_807FD6E0 = 4;
        }
    }
    if (D_global_asm_807FD6E0 != 0) {
        D_global_asm_807FD6E0 -= 1;
        if (D_global_asm_807FD6E0 == 0) {
            D_global_asm_807FD6E1 = 8;
        }
        func_global_asm_806E384C();
    } else {
        func_global_asm_80605314(current_actor_pointer, 0);
    }
    if (D_global_asm_807FD6E1 != 0) {
        D_global_asm_807FD6E1--;
    }
}
*/

void func_global_asm_806E41B4() {
    func_global_asm_80614E78(current_actor_pointer, 0x15);
    current_actor_pointer->control_state_progress = 7;
}

void func_global_asm_806E41EC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
    // Barrel Barrel Complete Flag Check
    if ((D_global_asm_807FBB8C != 0) && (isFlagSet(0x185, FLAG_TYPE_PERMANENT) || ((D_global_asm_807FBB64 * 8) < 0) || (cc_number_of_players >= 2) || gameIsInMysteryMenuMinigameMode())) {
        func_global_asm_806EB0C0(3, NULL, cc_player_index);
        return;
    }
    if (!func_global_asm_806E4580() && (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) && (current_actor_pointer->unk6A & 1)) {
        if (current_character_index[cc_player_index] == 6) {
            if (D_global_asm_807FD610[cc_player_index].unk2A & 0x2000) {
                current_actor_pointer->control_state = 0x2F;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614E78(current_actor_pointer, 0x48);
                extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
                extra_player_info_pointer->unk38 = D_global_asm_8075381C[D_global_asm_807FD584];
                extra_player_info_pointer->unk30 = D_global_asm_8075382C[D_global_asm_807FD584];
                extra_player_info_pointer->unk48 = D_global_asm_8075385C[D_global_asm_807FD584];
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                return;
            }
            current_actor_pointer->control_state = 0x29;
            current_actor_pointer->control_state_progress = 0;
            func_global_asm_80614EBC(current_actor_pointer, 0x1DF);
            extra_player_info_pointer->unk64 = 0;
            extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
            return;
        }
        if (!func_global_asm_80714608(0) && D_global_asm_807531E0[D_global_asm_807FD584] <= extra_player_info_pointer->unk20 && (current_actor_pointer->unkE0 == 0.0f)) {
            func_global_asm_80614E78(current_actor_pointer, 0x44);
            current_actor_pointer->control_state = 0x29;
            current_actor_pointer->control_state_progress = 0;
            current_actor_pointer->unkEA = current_actor_pointer->unkEE;
            current_actor_pointer->unkB8 = 150.0f;
            extra_player_info_pointer->unk38 = 150.0f;
        } else {
            func_global_asm_80614E78(current_actor_pointer, 0x3F);
            current_actor_pointer->control_state = 0x26;
            current_actor_pointer->control_state_progress = 0;
        }
        extra_player_info_pointer->unkC8 = 0x32;
        extra_player_info_pointer->unk64 = 0;
    }
}

s32 func_global_asm_806E4580(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) && D_global_asm_807FBB70.unk2 && D_global_asm_807FBB70.unk14 == 8) {
        extra_player_info_pointer->unk220 = D_global_asm_807FBB70.unk4;
        extra_player_info_pointer->unk224 = D_global_asm_807FBB70.unk8;
        extra_player_info_pointer->unk228 = D_global_asm_807FBB70.unkC;
        func_global_asm_806EB0C0(0x1F, NULL, cc_player_index);
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806E4634(void) {
    f32 temp_f2;
    f32 phi_f0;

    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        phi_f0 = current_actor_pointer->distance_from_floor;
        if (current_actor_pointer->unk6A & 2) {
            temp_f2 = current_actor_pointer->y_position - current_actor_pointer->unkAC;
            if (!(phi_f0 < temp_f2)) {
                phi_f0 = temp_f2;
            }
        }
        if ((phi_f0 > 3.0f) && current_character_index[cc_player_index] != 6) {
            func_global_asm_806EB0C0(0xF, NULL, cc_player_index);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E4740.s")

extern f32 D_global_asm_8075318C[];

/*
// TODO: Very close, just an issue with the branches in the first switch case
void func_global_asm_806E4740(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        if (D_global_asm_8075318C[D_global_asm_807FD584] < extra_player_info_pointer->unk20) {
            switch (current_character_index[cc_player_index]) {
                case 3:
                    current_actor_pointer->y_velocity = 200.0f;
                case 5:
                    func_global_asm_806CFE7C();
                    current_actor_pointer->control_state = 0x2B;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x45);
                    extra_player_info_pointer->unkC8 = 0x32;
                    break;
                default:
                case 0:
                    switch (current_character_index[cc_player_index]) {
                        case 2:
                            if (D_global_asm_807FC950[cc_player_index].character_progress[2].moves > 0) {
                                func_global_asm_806EB0C0(0x25, NULL, cc_player_index);
                            }
                            break;
                        case 4:
                            if (D_global_asm_807FC950[cc_player_index].character_progress[4].moves > 1) {
                                func_global_asm_806EB0C0(0x26, NULL, cc_player_index);
                            }
                            break;
                        case 1:
                            if (D_global_asm_807FC950[cc_player_index].character_progress[1].moves > 0) {
                                extra_player_info_pointer->unk48 = 0x64;
                                current_actor_pointer->control_state = 0x2E;
                                current_actor_pointer->control_state_progress = 0;
                                func_global_asm_80614E78(current_actor_pointer, 0x48);
                                extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584] * 4;
                                extra_player_info_pointer->unk38 = D_global_asm_8075381C[D_global_asm_807FD584] * 2;
                                extra_player_info_pointer->unk30 = D_global_asm_8075382C[D_global_asm_807FD584];
                            }
                            break;
                        case 6:
                            current_actor_pointer->control_state = 0x2F;
                            current_actor_pointer->control_state_progress = 0;
                            func_global_asm_80614E78(current_actor_pointer, 0x48);
                            extra_player_info_pointer->unk68 = D_global_asm_8075380C[D_global_asm_807FD584];
                            extra_player_info_pointer->unk38 = D_global_asm_8075381C[D_global_asm_807FD584];
                            extra_player_info_pointer->unk30 = D_global_asm_8075382C[D_global_asm_807FD584];
                            extra_player_info_pointer->unk48 = D_global_asm_8075385C[D_global_asm_807FD584];
                            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                            break;
                    }
                    break;
            }
        }
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E4AD8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E4C6C.s")

void func_global_asm_806E4D14(void) {
    u32 actorBehaviourIndex = extra_player_info_pointer->unk1AC->unk58;
    // Steel Keg & Apple
    if ((actorBehaviourIndex != 0x55) && (actorBehaviourIndex != 0x82)) {
        current_actor_pointer->y_velocity = 200.0f;
        current_actor_pointer->control_state = 0x4D;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x2D);
    }
}

void func_global_asm_806E4D84(void) {
    if (!func_global_asm_806E56EC()) {
        if (extra_player_info_pointer->unkC8 == -1) {
            if (current_character_index[cc_player_index] != 6 || current_actor_pointer->unkB8 < D_global_asm_807531E0[D_global_asm_807FD584]) {
                current_actor_pointer->control_state = 0x3C;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614E78(current_actor_pointer, 0xA);
                extra_player_info_pointer->unk48 = D_global_asm_807534D4[D_global_asm_807FD584];
            }
            extra_player_info_pointer->unk30 = D_global_asm_807534B8[D_global_asm_807FD584];
        }
    }
}

void func_global_asm_806E4E88(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS) && playerCanThrowOrange()) {
        func_global_asm_80618104(current_actor_pointer);
        func_global_asm_80617770(current_actor_pointer, 0x21, 0x19);
    }
    if (D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS) {
        if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk60) < 0xFU) {
            if (extra_player_info_pointer->unk8C != 0) {
                func_global_asm_806F0B34(current_actor_pointer);
            }
            extra_player_info_pointer->unk8C = 0;
            func_global_asm_806EAB44(current_actor_pointer, 0);
        } else if (!func_global_asm_80714608(0) && !(D_global_asm_807FBB64 & 0x80000200) && (D_global_asm_807FD568->unk2 & 1)) {
            if (((extra_player_info_pointer->unk1F0 & 0x30) == 0) && (character_change_array[cc_player_index].unk2C0 == 1)) {
                func_global_asm_806DF44C(current_actor_pointer, extra_player_info_pointer, 1);
            }
        }
        extra_player_info_pointer->unk60 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E5044(void) {
    if (((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS)) && (playerCanThrowOrange())) {
        func_global_asm_80618104(current_actor_pointer);
        func_global_asm_80617770(current_actor_pointer, 0x21, 0x19);
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS)) {
        if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk60) < 0xFU) {
            if (extra_player_info_pointer->unk8C != 0) {
                func_global_asm_806F0B34(current_actor_pointer);
            }
            extra_player_info_pointer->unk8C = 0;
            func_global_asm_806EAB44(current_actor_pointer, 0);
        } else if (!func_global_asm_80714608(0) && !(D_global_asm_807FBB64 & 0x200) && (D_global_asm_807FD568->unk2 & 1) && (character_change_array[cc_player_index].unk2C0 == 1)) {
            func_global_asm_806DF44C(current_actor_pointer, extra_player_info_pointer, 1);
            character_change_array[cc_player_index].fov_y = 45.0f;
        }
        extra_player_info_pointer->unk60 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E521C(void) {
    if (func_global_asm_80714608(0)) {
        switch (current_actor_pointer->control_state) {
            case 0x31:
            case 0x32:
                if (extra_player_info_pointer->unk8C == 0) {
                    func_global_asm_806E4D84();
                }
        }
    }
}

s32 func_global_asm_806E527C(void) {
    Actor *temp_v0;
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    for (i = 0; i < D_global_asm_807FBB34 && var_v1 == 0; i++) {
        temp_v0 = D_global_asm_807FB930[i].unk0;
        var_v1 = temp_v0->object_properties_bitfield & 0x02000000;
    }
    return var_v1;
}

// stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E52D0.s")

s32 func_global_asm_806E5488(Actor *arg0);
u32 func_global_asm_806E560C(Actor *arg0);

/*
void func_global_asm_806E52D0(void) {
    u32 temp_v1;

    if ((D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS)
        && (object_timer >= 3U)
        && (D_global_asm_807FD568->unk4 & 1)
        && !(D_global_asm_807FBB64 & 0x4000)
        && !(D_global_asm_807FBB68 & 1)
        && (character_change_array[cc_player_index].unk2C0 != 2)
        && (func_global_asm_806E5488(current_actor_pointer) == 0)
        && (func_global_asm_806E527C() == 0)
        && (extra_player_info_pointer->unk245 == 0)) {
        temp_v1 = func_global_asm_806E560C(current_actor_pointer);
        if ((current_map != MAP_KROOL_FIGHT_LANKY_PHASE || temp_v1)) {
            if (func_global_asm_806F8AD4(7, cc_player_index) != 0 || temp_v1) {
                func_global_asm_806EB0C0(0x53, NULL, extra_player_info_pointer->unk1A4);
                if (!(D_global_asm_807FBB68 & 2)) {
                    current_actor_pointer->noclip_byte = 1;
                }
                if (!temp_v1) {
                    func_global_asm_806F91B4(7, cc_player_index, -1);
                }
            }
            if (!temp_v1) {
                func_global_asm_806F8BC4(7, 0, 0);
            }
        }
    }
}
*/

s32 func_global_asm_806E5488(Actor *arg0) {
    f32 temp_f0;
    f32 dx;
    f32 dz;
    f32 temp_f2;
    f32 dy;

    if (arg0->locked_to_pad == 1) {
        temp_f0 = arg0->unk94 - arg0->unk88;
        temp_f2 = arg0->unk98 - arg0->unk90;
        if (sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)) > 1.0) {
            return TRUE;
        }
    }
    if ((arg0->unk6A & 8) != 0) {
        dx = arg0->x_position - arg0->unk88;
        dy = arg0->y_position - arg0->unk8C;
        dz = arg0->z_position - arg0->unk90;
        if (sqrtf((dx * dx) + (dy * dy) + (dz * dz)) > 1.0) {
            return TRUE;
        }
    }
    // Object Model 2 Behavior: Mushroom (0x88)
    if ((arg0->locked_to_pad == 1) && (func_global_asm_8063C328(arg0->unk10C) == 0x88)) {
        return TRUE;
    }
    // Object Model 2 Behavior: Wooden Platform (Castle) (0x219)
    if ((arg0->locked_to_pad == 1) && (func_global_asm_8063C328(arg0->unk10C) == 0x219)) {
        return TRUE;
    }
    // Object Model 2 Behavior: Metal Platform (0x132)
    if ((arg0->locked_to_pad == 1) && (func_global_asm_8063C328(arg0->unk10C) == 0x132)) {
        return TRUE;
    }
    return FALSE;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E560C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E56EC.s")

void func_global_asm_806E5C2C(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        setIntroStoryPlaying(2);
        func_global_asm_805FF158(0);
    }
    func_global_asm_805FF9AC(arg0, 0, 0, 0);
}

int func_global_asm_806E5C74(void) {
    f32 temp_f2;
    f32 phi_f0;

    phi_f0 = current_actor_pointer->distance_from_floor;
    if (current_actor_pointer->unk6A & 2) {
        temp_f2 = current_actor_pointer->y_position - current_actor_pointer->unkAC;
        if (!(phi_f0 < temp_f2)) {
            phi_f0 = temp_f2;
        }
    }
    return D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG
        && extra_player_info_pointer->unk1CC * D_global_asm_8075D310 < phi_f0
        && current_character_index[cc_player_index] != 6
        && D_global_asm_807FD568->unk1 != 0;
}

void func_global_asm_806E5D60(void) {
    if (func_global_asm_806E5C74()) {
        switch (D_global_asm_807FD568->unk1) {
            case 2:
                func_global_asm_80614E78(current_actor_pointer, 0x17);
                func_global_asm_80613AF8(current_actor_pointer, 0x18, 0, 3.0f);
                func_global_asm_80614D00(current_actor_pointer, 1.35f, 0);
                break;
            case 3:
                func_global_asm_80614E78(current_actor_pointer, 0x19);
                break;
            default:
                func_global_asm_80614E78(current_actor_pointer, 0x16);
                func_global_asm_80613AF8(current_actor_pointer, 0x17, 0, 3.0f);
                func_global_asm_80614D00(current_actor_pointer, 1.35f, 0);
                break;
        }
        current_actor_pointer->control_state = 0x1C;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E5E58(void) {

}

void func_global_asm_806E5E60(void) {

}

void func_global_asm_806E5E68(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x20)) {
        func_global_asm_806EB0C0(0x24, NULL, cc_player_index);
    }
}

void func_global_asm_806E5EA8() {
    func_global_asm_806EB0C0(0x24, NULL, cc_player_index);
}

void func_global_asm_806E5ED4(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS)
        && (D_global_asm_807FD568->unk2 & 1)
        && (character_change_array[cc_player_index].unk2C0 == 1)
        && !(extra_player_info_pointer->unk1F0 & 0x30)
        && !func_global_asm_80714608(0)) {
        func_global_asm_806EB0C0(0x14, NULL, cc_player_index);
    }
}

void func_global_asm_806E5FA0(void) {
    if (((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS))
        && (D_global_asm_807FD568->unk2 & 1)
        && !(D_global_asm_807FBB64 & 0x200)
        && (character_change_array[cc_player_index].unk2C0 == 1)
        && !(extra_player_info_pointer->unk1F0 & 0x30)
        && !func_global_asm_80714608(0)) {
        func_global_asm_806EB0C0(0x15, NULL, cc_player_index);
    }
}

void func_global_asm_806E607C(void) {
    PlayerAdditionalActorData *temp_v0; // TODO: Probably not actually a PaaD

    temp_v0 = extra_player_info_pointer->unk104->PaaD;
    temp_v0->unkAC |= 4;
    if (((D_global_asm_807FD610[cc_player_index].unk2C & R_TRIG))) {
        if ((D_global_asm_807FBB64 & 1) || ((cc_number_of_players >= 2) && (D_global_asm_80750AB8 == 0))) {
            if (temp_v0->unkAC & 0x10000) {
                func_global_asm_806261CC(extra_player_info_pointer->unk104);
                return;
            }
            func_global_asm_80626110(extra_player_info_pointer->unk104, 0, 0);
            return;
        }
        if ((temp_v0->unkAC & 0x4000) == 0) {
            temp_v0->unkAC ^= 2;
            if ((temp_v0->unkF0_u8[1] < 3) && (temp_v0->unkF4_u8[1] == 0) && (temp_v0->unkF0_u8[3] != 2)) {
                temp_v0->unkF0_u8[1] = 0x14;
                temp_v0->unkB2 = current_actor_pointer->y_rotation;
                extra_player_info_pointer->unk104->distance_from_floor = temp_v0->unkB8;
                temp_v0->unkF4_u8[1] = 0xA;
            }
        }
    }
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC;
    s32 unk10; s32 unk14; s32 unk18; s32 unk1C;
    s32 unk20; s32 unk24; s32 unk28; s32 unk2C;
    s32 unk30; s32 unk34; s32 unk38; s32 unk3C;
    s32 unk40; s32 unk44; s32 unk48; s32 unk4C;
    s32 unk50; s32 unk54; s32 unk58; s32 unk5C;
    s32 unk60; s32 unk64; s32 unk68; s32 unk6C;
    s32 unk70; s32 unk74; s32 unk78; s32 unk7C;
    s32 unk80; s32 unk84; s32 unk88; s32 unk8C;
    s32 unk90; s32 unk94; s32 unk98; s32 unk9C;
    s32 unkA0; s32 unkA4; s32 unkA8; s32 unkAC;
} AAD_global_asm_806E61D0;

void func_global_asm_806E61D0(void) {
    AAD_global_asm_806E61D0 *temp_v0;

    if (((D_global_asm_807FBB64 & 1) == 0) && ((cc_number_of_players < 2) || (D_global_asm_80750AB8 != 0))) {
        temp_v0 = extra_player_info_pointer->unk104->RaaD;
        temp_v0->unk4 = 0;
        temp_v0->unkAC &= ~4;
    }
}

void func_global_asm_806E6234(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & START_BUTTON)
        && !func_global_asm_8061CB50()
        && (D_global_asm_807FD888 == 0.0f)
        && (gameIsInAdventureMode() || gameIsInMysteryMenuMinigameMode() || gameIsInDKTVMode())
        && !func_global_asm_8062919C()
        && !func_global_asm_806291A8()) {
        D_global_asm_807FC8B9 = cc_player_index;
        global_properties_bitfield |= 1;
    }
}

void func_global_asm_806E6318(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E6368(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E63B8(void) {
    f32 temp_f0;

    if (D_global_asm_807FD610[cc_player_index].unk4 != 0.0f) {
        temp_f0 = extra_player_info_pointer->unk34;
        extra_player_info_pointer->unk4 = (D_global_asm_807FD610[cc_player_index].unk8 * (extra_player_info_pointer->unk38 - temp_f0)) + temp_f0;
    } else {
        extra_player_info_pointer->unk4 = 0.0f;
    }
    extra_player_info_pointer->unk4 /= 4;
    if (D_global_asm_807FD610[cc_player_index].unk4 != 0.0f) {
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, D_global_asm_807FD610[cc_player_index].unk28, extra_player_info_pointer->unk48);
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, 0, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x10);
}

void func_global_asm_806E64D0(void) {
    s16 phi_a1;
    s32 phi_v0;

    if (D_global_asm_807FD610[cc_player_index].unk30) {
        phi_a1 = D_global_asm_80753B34[D_global_asm_807FD584] * (D_global_asm_807FD610[cc_player_index].unk2E >= 0 ? 1 : -1);
        phi_a1 &= 0xFFF;
    } else {
        phi_a1 = 0;
    }
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, phi_a1, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, extra_player_info_pointer->unk12, 0x10);
    extra_player_info_pointer->unk38 = D_global_asm_80753988[D_global_asm_807FD584];
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E65BC.s")

extern s16 D_global_asm_80753B44[];
extern s16 D_global_asm_80753B54[];
extern s16 D_global_asm_80753B64[];

/*
// TODO: Surprisingly fiddly
void func_global_asm_806E65BC(void) {
    f64 temp_f0;
    s16 phi_t1;
    s16 phi_a1;
    f64 phi_f2;
    s32 phi_v0;

    phi_t1 = current_character_index[cc_player_index] == 7 ? 0x19 : 0x10;
    if (D_global_asm_807FD610[cc_player_index].unk30 != 0) {
        current_actor_pointer->y_rotation = (current_actor_pointer->y_rotation - (D_global_asm_807FD610[cc_player_index].unk2E / 2)) & 0xFFF;
        phi_v0 = -1;
        if (D_global_asm_807FD610[cc_player_index].unk2E >= 0) {
            phi_v0 = 1;
        }
        phi_a1 = (phi_v0 * D_global_asm_80753B54[D_global_asm_807FD584]) & 0xFFF;
    } else {
        phi_a1 = 0;
    }
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, phi_a1, 0x10);
    if (D_global_asm_807FD610[cc_player_index].unk2F != 0) {
        temp_f0 = D_global_asm_807FD610[cc_player_index].unk2F * 0.125;
        if (temp_f0 > 0.0) {
            phi_f2 = temp_f0;
        } else {
            phi_f2 = -temp_f0;
        }
        func_global_asm_806DF494(&current_actor_pointer->z_rotation, ((D_global_asm_807FD610[cc_player_index].unk2F * D_global_asm_80753B44[D_global_asm_807FD584]) / 70) & 0xFFF, phi_f2 + phi_t1);
        return;
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, D_global_asm_80753B64[D_global_asm_807FD584], 0x10);
}
*/

void func_global_asm_806E67D8(void) {
    f32 phi_f0;
    f32 phi_f0_2;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        phi_f0_2 = ((D_global_asm_807FD610[cc_player_index].unk8 * 0.5) + 0.5);
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        phi_f0 = MIN(400, phi_f0);
        phi_f0 *= (extra_player_info_pointer->unk48 / 400.0);
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * phi_f0_2);
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, 0, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x10);
    extra_player_info_pointer->unk12 = 0;
    extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
    extra_player_info_pointer->unk10 = D_global_asm_8075395C[D_global_asm_807FD584];
    extra_player_info_pointer->unk38 = D_global_asm_80753988[D_global_asm_807FD584] * D_global_asm_807FD610[cc_player_index].unk8;
    if ((D_global_asm_807FD610[cc_player_index].unk2A & B_BUTTON)) {
        extra_player_info_pointer->unk38 *= D_global_asm_8075D318;
    }
}

void func_global_asm_806E6A38(void) {
    f32 phi_f0;
    f32 phi_f0_2;
    f32 phi_f0_3;
    f32 temp;

    func_global_asm_806E007C();
    if (extra_player_info_pointer->unk4 != 0.0f) {
        temp = ((D_global_asm_807FD610[cc_player_index].unk8 * 0.5) + 0.5);
        phi_f0 = ABS(current_actor_pointer->y_rotation - extra_player_info_pointer->unkA);
        if (phi_f0 > 2048.0f) {
            phi_f0 = 4096.0f - phi_f0;
        }
        if (phi_f0 > 400.0f) {
            phi_f0 = 400.0f;
        }
        phi_f0 *= D_global_asm_8075D320;
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, phi_f0 * temp);
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, 0, 0x10);
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, 0, 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E6B98.s")

extern f64 D_global_asm_8075D328;

/*
// TODO: Very close
void func_global_asm_806E6B98(void) {
    f64 temp_f0;
    s16 phi_v0;
    s16 phi_a1;
    s16 phi_a2;
    s16 rot;

    phi_v0 = current_actor_pointer->y_rotation;
    phi_a2 = 0x10;
    if (D_global_asm_807FD610[cc_player_index].unk30 != 0) {
        if (current_character_index[cc_player_index] == 7) {
            phi_v0 -= (D_global_asm_807FD610[cc_player_index].unk2E * D_global_asm_8075D328);
        } else {
            phi_v0 -= (D_global_asm_807FD610[cc_player_index].unk2E * 0.5);
        }
        current_actor_pointer->y_rotation = phi_v0 & 0xFFF;
        if (D_global_asm_807FD610[cc_player_index].unk2E >= 0) {
            phi_v0 = 1;
        } else {
            phi_v0 = -1;
        }
        phi_a1 = (phi_v0 * D_global_asm_80753B34[D_global_asm_807FD584]) & 0xFFF;
    } else {
        phi_a1 = 0;
    }
    func_global_asm_806DF494(&current_actor_pointer->x_rotation, phi_a1, 0x10);
    rot = ((D_global_asm_80753B44[D_global_asm_807FD584] * D_global_asm_807FD610[cc_player_index].unk2F) / 70) & 0xFFF;
    if (current_character_index[cc_player_index] == 7) {
        phi_a2 = (ABS(D_global_asm_807FD610[cc_player_index].unk2F * 0.5)) + 16.0;
    }
    func_global_asm_806DF494(&current_actor_pointer->z_rotation, rot, phi_a2);
}
*/

void func_global_asm_806E6DE8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        func_global_asm_806EB0C0(1, NULL, cc_player_index);
    }
}

void func_global_asm_806E6E7C(void) {
    extra_player_info_pointer->unk12 = 0;
    extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
    if (extra_player_info_pointer->unk10 == 0) {
        extra_player_info_pointer->unk10 = 1;
        extra_player_info_pointer->unk38 = D_global_asm_8075396C[D_global_asm_807FD584];
    }
}

void func_global_asm_806E6EE0(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        func_global_asm_80614E78(current_actor_pointer, 0x37);
        current_actor_pointer->control_state_progress = 4;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E6F74(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        func_global_asm_80614E78(current_actor_pointer, 0x37);
        current_actor_pointer->control_state_progress = 4;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E6FF0(void) {
    extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    func_global_asm_80614D00(current_actor_pointer, 2.0f, 0);
    func_global_asm_80614E78(current_actor_pointer, 0x38);
    current_actor_pointer->control_state_progress = 7;
}

void func_global_asm_806E7050(void) {
    func_global_asm_80614E78(current_actor_pointer, 0x39);
    current_actor_pointer->control_state_progress = 7;
}

void func_global_asm_806E7088(void) {
    current_actor_pointer->control_state_progress = 6;
}

void func_global_asm_806E709C(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
            extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            if (extra_player_info_pointer->unk10 == 0) {
                extra_player_info_pointer->unk38 = D_global_asm_80753AC4[D_global_asm_807FD584];
                func_global_asm_80614E78(current_actor_pointer, 0x36);
            } else {
                extra_player_info_pointer->unk38 = D_global_asm_80753AA8[D_global_asm_807FD584];
            }
            extra_player_info_pointer->unk10 = D_global_asm_80753A98[D_global_asm_807FD584];
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
        } else if (!(D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
            extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            if (extra_player_info_pointer->unk10 == 0) {
                extra_player_info_pointer->unk10 = 1;
                extra_player_info_pointer->unk38 = D_global_asm_80753AA8[D_global_asm_807FD584];
            }
        }
    }
}

void func_global_asm_806E7230(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk38 = D_global_asm_80753AC4[D_global_asm_807FD584];
            func_global_asm_80614E78(current_actor_pointer, 0x36);
        } else {
            extra_player_info_pointer->unk38 = D_global_asm_80753AA8[D_global_asm_807FD584];
        }
        extra_player_info_pointer->unk10 = D_global_asm_80753A98[D_global_asm_807FD584];
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E7338(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        current_actor_pointer->control_state_progress = 3;
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk38 = 300.0f;
            func_global_asm_80614EBC(current_actor_pointer, 0x318);
        } else {
            extra_player_info_pointer->unk38 = 250.0f;
        }
        extra_player_info_pointer->unk10 = 0xF;
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    } else if (!(D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON)) {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk10 = 1;
            extra_player_info_pointer->unk38 = 250.0f;
        }
    }
}

void func_global_asm_806E7484(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        current_actor_pointer->control_state_progress = 3;
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk38 = 300.0f;
            func_global_asm_80614EBC(current_actor_pointer, 0x318);
        } else {
            extra_player_info_pointer->unk38 = 250.0f;
        }
        extra_player_info_pointer->unk10 = 0xF;
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E7568(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        extra_player_info_pointer->unk38 = D_global_asm_80753AC4[D_global_asm_807FD584];
        func_global_asm_80614E78(current_actor_pointer, 0x36);
        current_actor_pointer->control_state_progress = 3;
        extra_player_info_pointer->unk10 = D_global_asm_80753A98[D_global_asm_807FD584];
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E7658(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS) && !(D_global_asm_807FBB64 & 2)) {
        func_global_asm_806E9804(8);
    } else {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        extra_player_info_pointer->unk10 = 0;
        extra_player_info_pointer->unk30 = 8.0f;
    }
}

u8 playerCanDive(void) {
    return isFlagSet(0x182, FLAG_TYPE_PERMANENT) // Check whether dive barrel is complete
        || (D_global_asm_807FBB64 & 0x10000000)
        || (cc_number_of_players > 1)
        || gameIsInMysteryMenuMinigameMode();
}

void func_global_asm_806E7780(void) {
    f32 phi_f0;

    if ((D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS) && !(D_global_asm_807FBB64 & 2)) {
        func_global_asm_806E9804(8);
        return;
    }
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f0 = D_global_asm_8075386C[D_global_asm_807FD584];
    } else {
        phi_f0 = D_global_asm_8075389C[D_global_asm_807FD584];
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG) && (phi_f0 < current_actor_pointer->distance_from_floor) && playerCanDive()) {
        func_global_asm_806EB0C0(0x3E, NULL, cc_player_index);
        func_global_asm_80608528(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
    }
}

void func_global_asm_806E78B8() {
    extra_player_info_pointer->unk30 = D_global_asm_80753B18[D_global_asm_807FD584];
}

void func_global_asm_806E78E0(void) {
    extra_player_info_pointer->unk30 = 1.0f;
}

void func_global_asm_806E78F8(void) {

}

void func_global_asm_806E7900(void) {
    // TODO: There might be a special aaD type for minecart
    // Could also be a RaaD, not sure yet
    PlayerAdditionalActorData *PaaD = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (current_actor_pointer->control_state == 7) {
        if (!(D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG)) {
            if ((D_global_asm_807FD610[cc_player_index].unk2E < -0x1E) && (current_actor_pointer->animation_state->unk0->unk10 != 0xFB)) {
                func_global_asm_80614E78(current_actor_pointer, 0x81);
                current_actor_pointer->control_state = 0xA; // Minecart (Left)
                current_actor_pointer->control_state_progress = 0;
                PaaD->unk42 = 1;
            } else if ((D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) && (current_actor_pointer->animation_state->unk0->unk10 != 0xFF)) {
                func_global_asm_80614E78(current_actor_pointer, 0x7D);
                current_actor_pointer->control_state = 0xB; // Minecart (Right)
                current_actor_pointer->control_state_progress = 0;
                PaaD->unk42 = 2;
            }
        }
    }
    if (((D_global_asm_807FD610[cc_player_index].unk2E < 0x1E) && (current_actor_pointer->control_state != 0xA)) || ((D_global_asm_807FD610[cc_player_index].unk2E >= -0x1D) && (current_actor_pointer->control_state != 0xB))) {
        PaaD->unk42 = 0;
        switch (current_actor_pointer->control_state) {
            case 0xB:
                if (current_actor_pointer->control_state_progress == 1) {
                    func_global_asm_80614E78(current_actor_pointer, 0x7E);
                } else {
                    func_global_asm_80614E78(current_actor_pointer, 0x80);
                }
                current_actor_pointer->control_state = 7; // Minecart (Idle)
                current_actor_pointer->control_state_progress = 0;
                break;
            case 0xA:
                if (current_actor_pointer->control_state_progress == 1) {
                    func_global_asm_80614E78(current_actor_pointer, 0x82);
                } else {
                    func_global_asm_80614E78(current_actor_pointer, 0x80);
                }
                current_actor_pointer->control_state = 7; // Minecart (Idle)
                current_actor_pointer->control_state_progress = 0;
                break;
        }
    }
}

void func_global_asm_806E7B48(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    if (extra_player_info_pointer->unk1F0 & 8) {
        RaaD->unk3E = 4;
    } else {
        RaaD->unk3E = (D_global_asm_807FD610[cc_player_index].unk2F * 0.5) + 60.0;
    }
    func_global_asm_806E7900();
}

void func_global_asm_806E7C70(void) {
    AAD_global_asm_806E7C70 *temp_v0;

    temp_v0 = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (temp_v0->unk0 != 0) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
    }
    func_global_asm_806E7900();
    if (extra_player_info_pointer->unk1F0 & 8) {
        temp_v0->unk3E = 3;
    } else {
        temp_v0->unk3E = (D_global_asm_807FD610[cc_player_index].unk2F / 1.5) + 80.0;
    }
    temp_v0->unk2 = D_global_asm_807FD610[cc_player_index].unk2E;
}

void func_global_asm_806E7DF4(void) {
    AAD_global_asm_806E7C70 *var_a2;

    var_a2 = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (var_a2->unk0 != 0) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
    } else {
        u8 var_a3 = extra_player_info_pointer->vehicle_actor_pointer->control_state == 5 ? 1 : 0;
        s32 var_a1 = (var_a2->unk34[0] & 0x80) ? 1 : 3;
        if (var_a3 != 0) {
            D_global_asm_807FD610[cc_player_index].unk2E *= -1;
        }
        if ((extra_player_info_pointer->unk1F0 & 0x10000002) != 0) {
            D_global_asm_807FD610[cc_player_index].unk2E *= -1;
        }
        if ((extra_player_info_pointer->unk1F0 & 0x10000002) != 0) {
            D_global_asm_807FD610[cc_player_index].unk2F *= -1;
        }
        if (var_a2->unk34[0] & 0xC0) {
            if ((D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F && var_a2->unk3F > 0) || (D_global_asm_807FD610[cc_player_index].unk2E < -0x1E && var_a2->unk3F < var_a1)) {
                extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280;
                extra_player_info_pointer->vehicle_actor_pointer->y_velocity = D_global_asm_80750338;
                extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280 - 0x1E;
                var_a2->unk2C = 1.0f;
                var_a2->unk40 = var_a2->unk3F;
                if (D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) {
                    var_a2->unk3F--;
                    if (var_a2->unk3F == 1) {
                        var_a2->unk3F = 0;
                    }
                    func_global_asm_80614E78(current_actor_pointer, var_a3 ? 0x81 : 0x7D);
                    func_global_asm_80614EBC(extra_player_info_pointer->vehicle_actor_pointer, var_a3 ? 0x295 : 0x296);
                } else {
                    var_a2->unk3F++;
                    if (var_a2->unk3F == 1) {
                        if (var_a2->unk34[0] & 0x40) {
                            var_a2->unk3F = 2;
                        }
                    }
                    func_global_asm_80614E78(current_actor_pointer, var_a3 ? 0x7D : 0x81);
                    func_global_asm_80614EBC(extra_player_info_pointer->vehicle_actor_pointer, var_a3 ? 0x296 : 0x295);
                }
            }
        }
    }
    if (extra_player_info_pointer->unk1F0 & 8) {
        var_a2->unk3E = 3;
        extra_player_info_pointer->vehicle_actor_pointer->unkB8 = 3.0f;
        return;
    }
    var_a2->unk3E = (D_global_asm_807FD610[cc_player_index].unk2F / 1.5) + 80.0;
}

void func_global_asm_806E8244(void) {
    RaceAdditionalActorData *RaaD;
    s8 temp_t4;

    RaaD = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (func_global_asm_805FCA64()) {
        func_global_asm_8068C350(&func_global_asm_8068E474, extra_player_info_pointer->vehicle_actor_pointer, 5);
    }
    if ((current_actor_pointer->y_rotation < 0x200) || (current_actor_pointer->y_rotation >= 0xE01)) {
        RaaD->unk2 = D_global_asm_807FD610[cc_player_index].unk2E;
    } else if ((current_actor_pointer->y_rotation >= 0x201) && (current_actor_pointer->y_rotation < 0x600)) {
        RaaD->unk2 = D_global_asm_807FD610[cc_player_index].unk2F;
        temp_t4 = D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2E = D_global_asm_807FD610[cc_player_index].unk2F;
        D_global_asm_807FD610[cc_player_index].unk2F = temp_t4;
    } else if ((current_actor_pointer->y_rotation >= 0x601) && (current_actor_pointer->y_rotation < 0xA00)) {
        RaaD->unk2 = -D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2E = -D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2F = -D_global_asm_807FD610[cc_player_index].unk2F;
    } else {
        RaaD->unk2 = -D_global_asm_807FD610[cc_player_index].unk2F;
        temp_t4 = D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2E = -D_global_asm_807FD610[cc_player_index].unk2F;
        D_global_asm_807FD610[cc_player_index].unk2F = -temp_t4;
    }
    if (D_global_asm_807FD610[cc_player_index].unk2E < -0x1E) {
        extra_player_info_pointer->unk23C = 0x28;
        RaaD->unk42 = 1;
    } else if (D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) {
        extra_player_info_pointer->unk23C = 0x28;
        RaaD->unk42 = 2;
    } else if (extra_player_info_pointer->unk23C != 0) {
        extra_player_info_pointer->unk23C--;
    } else {
        RaaD->unk42 = 0;
    }
}

void func_global_asm_806E84A4(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    RaaD->unk3E = 0x14;
}

void func_global_asm_806E84C0(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    RaaD->unk3E = 0x64;
    if (extra_player_info_pointer->unk23C) {
        extra_player_info_pointer->unk23C--;
    }
}

void func_global_asm_806E84F8(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & (A_BUTTON | B_BUTTON | Z_TRIG))) {
        RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
        RaaD->unk3E = 0x32;
    }
}

// ActorAnimationState->unk0, possible datatype conflicts, not sure what is passed into arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E854C.s")

void func_global_asm_806E8724(Actor *arg0, RaceAdditionalActorData *arg1) {
    f32 temp_f0;
    s32 temp_t1;
    s32 phi_a0;

    if ((arg1->unk45 == 0) && (arg1->unk34 == 2)) {
        temp_t1 = D_global_asm_807FD610[cc_player_index].unk2F < -0x14;
        phi_a0 = D_global_asm_807FD610[cc_player_index].unk2E >= 0 ? 1 : -1;
        temp_f0 = D_global_asm_807FD610[cc_player_index].unk30;
        temp_f0 = MIN(80.0f, temp_f0) * phi_a0 * D_global_asm_8075D334;
        arg1->unkC = temp_f0;
        arg1->unkC = temp_f0 * D_global_asm_80750FFC;
        if (arg1->unk20 == 0) {
            arg1->unk20 = (arg0->unkB8 < D_global_asm_80750FF8) & temp_t1;
            return;
        } else {
            arg1->unk20 = temp_t1;
            return;
        }
    }
    arg1->unk20 = 0;
    arg1->unkC = 0.0f;
}

void func_global_asm_806E884C(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        func_global_asm_806E8724(vehicle, vehicle->additional_actor_data);
    }
}

void func_global_asm_806E8880() {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        PaaD0 *paad = vehicle->PaaD0;
        paad->unk8 = D_global_asm_80751000;
    }
}

void func_global_asm_806E88AC() {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        PaaD0 *paad = vehicle->PaaD0;
        paad->unk8 = 0.0f;
    }
}

// Actor->animation_state->unk0->stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E88D8.s")

void func_global_asm_806E8A8C(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if ((RaaD->unk45 == 0) && (RaaD->unk34 == 2)) {
            if (RaaD->unk25 == 0) {
                RaaD->unk4 = D_global_asm_8075D344;
            }
        } else {
            RaaD->unk4 = 0.0f;
        }
    }
}

void func_global_asm_806E8AF0(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if (RaaD->unk25 == 0) {
            RaaD->unk4 = 0.0f;
        }
    }
}

void func_global_asm_806E8B28(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if ((RaaD->unk45 == 0) && (RaaD->unk34 == 2)) {
            Actor178 *r178 = vehicle->unk178;
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                r178->unk4 = 1;
            }
        }
    }
}

void func_global_asm_806E8BA4(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if ((RaaD->unk45 == 0) && (RaaD->unk34 == 2)) {
            RaaD->unk10 = 2.0f;
        } else {
            RaaD->unk10 = 1.0f;
        }
    }
}

void func_global_asm_806E8BFC() {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaceAdditionalActorData* RaaD = vehicle->RaaD;
        RaaD->unk10 = 1.0f;
    }
}

// TODO: Actor->animation_state->unk0->unk10
// TODO: Pointer to something at aaD->unk30, size at least 0x154
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E8C2C.s")

void func_global_asm_806E8D54(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        if (vehicle->RaaD->unk34 && (vehicle->RaaD->unk34 < 3) && !vehicle->RaaD->unk45) {
            RaceActor178 *r178 = vehicle->race178;
            vehicle->RaaD->unk4 = r178->unk14 + D_global_asm_8075D348;
        }
    }
}

void func_global_asm_806E8DB4(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        if ((vehicle->RaaD->unk34) && (vehicle->RaaD->unk34 < 3) && !vehicle->RaaD->unk45) {
            RaceActor178 *r178 = vehicle->race178;
            vehicle->RaaD->unk4 = r178->unk14;
        }
    }
}

void func_global_asm_806E8E00(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->additional_actor_data;
        if (RaaD->unk45 == 0 && RaaD->unk34 == 2 && (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
            RaaD->unk29 = 1;
        }
    }
}

void func_global_asm_806E8E78(void) {
    if (current_actor_pointer->control_state == 7 && !(D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG)) {
        func_global_asm_80614E78(current_actor_pointer, 0x7F);
        current_actor_pointer->control_state = 8;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E8F04(void) {
    if (current_actor_pointer->control_state_progress == 1) {
        func_global_asm_80614E78(current_actor_pointer, 0x7B);
    } else {
        func_global_asm_80614E78(current_actor_pointer, 0x80);
    }
    current_actor_pointer->control_state = 7;
    current_actor_pointer->control_state_progress = 0;
}

void func_global_asm_806E8F68(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) && (!(D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG))) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 9;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807537E0[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x7C);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E9070.s")

/*
// TODO: D_global_asm_80767CC0 might be a struct.280 access, or an array? idk
void func_global_asm_806E9070(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && extra_player_info_pointer->vehicle_actor_pointer->RaaD->unk0 == 0) {
        extra_player_info_pointer->vehicle_actor_pointer->y_velocity = D_global_asm_80750338;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        func_global_asm_80614E78(current_actor_pointer, 0x7C);
        if (current_actor_pointer->unk58 == ACTOR_DK) {
            func_global_asm_80614EBC(extra_player_info_pointer->vehicle_actor_pointer, 0x294);
        } else {
            func_global_asm_80614EBC(extra_player_info_pointer->vehicle_actor_pointer, 0x293);
        }
    }
}
*/

void func_global_asm_806E918C(void) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    if (!(extra_player_info_pointer->unk1F0 & 0x10000000)) {
        if (D_global_asm_807FD610[cc_player_index].unk2A & 0x10) {
            if (current_actor_pointer->control_state == 7) {
                func_global_asm_80671C0C(extra_player_info_pointer->vehicle_actor_pointer, 3, &sp54, &sp50, &sp4C);
                func_global_asm_80671C0C(extra_player_info_pointer->vehicle_actor_pointer, 4, &sp48, &sp44, &sp40);
                func_global_asm_8061C2F0(extra_player_info_pointer->unk104, sp48, sp44 + 8.0f, sp40, (sp48 - sp54) + sp48, (sp44 - sp50) + sp44 + 5.0f, (sp40 - sp4C) + sp40, 1);
                extra_player_info_pointer->unk1F0 |= 2;
                current_actor_pointer->object_properties_bitfield |= 0x400;
                return;
            }
        }
        if (extra_player_info_pointer->unk1F0 & 2) {
            extra_player_info_pointer->unk1F0 &= ~2;
            func_global_asm_8061C6A8(extra_player_info_pointer->unk104, extra_player_info_pointer->vehicle_actor_pointer, 4, 0x800, 0x28, 0, 5, 0x19, 0x14, 0, D_global_asm_8075D350);
            if (current_actor_pointer->control_state == 7) {
                func_global_asm_80614E78(current_actor_pointer, 0x84);
            }
        }
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
}

void func_global_asm_806E9388(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        current_actor_pointer->control_state = 0x80; // Enguarde Attacking (surface)
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_80614EBC(current_actor_pointer, 0x316);
    }
}

void func_global_asm_806E93F8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        current_actor_pointer->control_state = 0x81; // Enguarde Attacking
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_80614EBC(current_actor_pointer, 0x316);
    }
}

void func_global_asm_806E9468(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | Z_TRIG)) {
        extra_player_info_pointer->unk12 = D_global_asm_807539EC[D_global_asm_807FD584];
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        extra_player_info_pointer->unk10 = D_global_asm_807539DC[D_global_asm_807FD584];
        current_actor_pointer->control_state = 0x7F;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->control_state_progress = 1;
        if (current_actor_pointer->y_velocity > 0.0f) {
            current_actor_pointer->y_velocity = 0.0f;
        }
        func_global_asm_80614EBC(current_actor_pointer, 0x318);
        func_global_asm_80608528(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
    }
}

u8 func_global_asm_806E9580(void) {
    f32 temp_f2;
    f32 sp24; // TODO: Hmm, can we get rid of this?
    f32 var_f0;
    u8 sp1B;
    s32 var_v1;

    sp1B = 0;
    extra_player_info_pointer->unk24 = 0;
    var_v1 = 0x1E;
    if (current_actor_pointer->unk6A & 4) {
        if (current_actor_pointer->y_velocity <= 0.0f) {
            if (current_actor_pointer->y_velocity > -150.0f) {
                current_actor_pointer->y_velocity = current_actor_pointer->y_velocity;
            } else {
                current_actor_pointer->y_velocity = -150.0f;
            }
            temp_f2 = current_actor_pointer->unkAC - current_actor_pointer->y_position;
            if (character_change_array[cc_player_index].unk2C0 == 2) {
                var_v1 = 0x3C;
            }
            if ((var_v1 < temp_f2) && (sp24 = temp_f2, (playerCanDive() != 0))) {
                func_global_asm_806EB0C0(0x3E, NULL, cc_player_index);
                func_global_asm_806CA2AC();
            } else {
                if (current_actor_pointer->unk6A & 1) {
                    if (character_change_array[cc_player_index].unk2C0 == 1) {
                        var_f0 = D_global_asm_8075386C[D_global_asm_807FD584];
                    } else {
                        var_f0 = D_global_asm_8075389C[D_global_asm_807FD584];
                    }
                    if (var_f0 < temp_f2) {
                        func_global_asm_806EB0C0(0x3D, NULL, cc_player_index);
                        sp1B = 1;
                        func_global_asm_806CA2AC();
                    }
                } else {
                    if (character_change_array[cc_player_index].unk2C0 == 1) {
                        var_f0 = D_global_asm_8075388C[D_global_asm_807FD584];
                    } else {
                        var_f0 = D_global_asm_807538C8[D_global_asm_807FD584];
                    }
                    if (var_f0 < (current_actor_pointer->distance_from_floor + temp_f2)) {
                        func_global_asm_806EB0C0(0x3D, NULL, cc_player_index);
                        func_global_asm_80614EBC(current_actor_pointer, 0);
                        if (extra_player_info_pointer->unkC4 != 0) {
                            func_global_asm_80737924(extra_player_info_pointer->unkC4);
                        }
                        sp1B = 1;
                        func_global_asm_806CA2AC();
                    }
                }
            }
        }
    }
    return sp1B;
}

void func_global_asm_806E9804(s16 arg0) {
    // Do we have the camera and are we pressing C-Down
    if (isFlagSet(0x179, FLAG_TYPE_PERMANENT) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        func_global_asm_806E9D1C(arg0, 0xB, 0);
    }
}

void func_global_asm_806E9874(void) {
    if (!(D_global_asm_807FBB64 & 2) && current_character_index[cc_player_index] < 5) {
        func_global_asm_806E9804(6);
        character_change_array[cc_player_index].fov_y = 45.0f;
    }
}

void func_global_asm_806E98F8(void) {
    // Are we pressing Z and C-Down?
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806E9874();
    }
}

void func_global_asm_806E9964(PlayerAdditionalActorData *arg0) {
    s32 phi_v0 = current_actor_pointer->control_state == 5 || current_actor_pointer->control_state == 0x65;
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        if (phi_v0) {
            func_global_asm_806E9D1C(7, 3, 0);
        } else {
            func_global_asm_806E9D1C(5, 3, 0);
        }
    } else {
        func_global_asm_806EAB44(current_actor_pointer, phi_v0);
    }
    func_global_asm_806F8D58(6, 1);
    func_global_asm_806F8D58(0xC, 1);
    arg0->unk1F0 &= ~0x8000;
}

void func_global_asm_806E9A5C(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x8000) && (D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == U_CBUTTONS) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

void func_global_asm_806E9ACC(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x8000) && (D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

void func_global_asm_806E9B3C(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x8000) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806E9BA8.s")

/*
void func_global_asm_806E9BA8(s32 arg0) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) && !(extra_player_info_pointer->unk1F0 & 0x8000) && func_global_asm_806F8AD4(6, cc_player_index) > 0) {
        playSound(0x263, 0x7FFF, 63.0f, 1.0f, 0xA, 0);
        current_actor_pointer->control_state = arg0;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_806F91B4(6, cc_player_index, -1);
        func_global_asm_8065A708(character_change_array[cc_player_index].look_at_eye_x,
                      character_change_array[cc_player_index].look_at_eye_y,
                      character_change_array[cc_player_index].look_at_eye_z,
                      character_change_array[cc_player_index].look_at_at_x,
                      character_change_array[cc_player_index].look_at_at_y,
                      character_change_array[cc_player_index].look_at_at_z,
                      0.0f,
                      1,
                      0xFF,
                      0xFF,
                      0xFF);
    }
}
*/

void func_global_asm_806E9CDC(void) {
    func_global_asm_806E9BA8(0x64);
}

void func_global_asm_806E9CFC(void) {
    func_global_asm_806E9BA8(0x65);
}

s32 func_global_asm_806E9D1C(s16 arg0, u8 arg1, u8 arg2) {
    if (((cc_number_of_players < 2) || (D_global_asm_80750AB8 != 1)) && (D_global_asm_807FD888 == 0.0f) && (current_actor_pointer->unkE0 == 0.0f)) {
        func_global_asm_806EB178(cc_player_index, arg1, arg2, 0);
        func_global_asm_806EB0C0(arg0, NULL, cc_player_index);
        current_actor_pointer->unkB8 = 0.0f;
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806E9DE0(void) {
    PlayerAdditionalActorData *sp1C; // TODO: This is probably not a PaaD

    if (D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS) {
        sp1C = extra_player_info_pointer->unk104->additional_actor_data;
        if ((func_global_asm_80714608(0) == 0) && !(sp1C->unkAC & 0x80000000) && (((((current_actor_pointer->control_state == 0x5D)) || (current_actor_pointer->control_state == 0x5E) || (current_actor_pointer->control_state == 0x62)) && !(D_global_asm_807FBB64 & 0x80000000)) || (current_actor_pointer->control_state == 0x4E) || (current_actor_pointer->control_state == 0x4F) || (current_actor_pointer->control_state == 0xD) || (current_actor_pointer->control_state == 0xC))) {
            func_global_asm_806E9D1C(5, 3, 0);
        }
    }
}

void func_global_asm_806E9ECC(void) {
    PlayerAdditionalActorData *sp1C;

    if (D_global_asm_807FD610[cc_player_index].unk2C & 2) {
        if (current_actor_pointer->unk6A & 1) {
            sp1C = extra_player_info_pointer->unk104->additional_actor_data;
            if (func_global_asm_80714608(0) == 0) {
                if (!(sp1C->unkAC & 0x80000000)) {
                    if (!(D_global_asm_807FBB64 & 0x80000000)) {
                        func_global_asm_806E9D1C(5, 3, 1);
                    }
                }
            }
        }
    }
}

void func_global_asm_806E9F8C(void) {
    PlayerAdditionalActorData *sp1C;

    if (D_global_asm_807FD610[cc_player_index].unk2C & 8) {
        if (current_actor_pointer->unk6A & 1) {
            sp1C = extra_player_info_pointer->unk104->additional_actor_data;
            if (func_global_asm_80714608(0) == 0) {
                if (!(sp1C->unkAC & 0x80000000)) {
                    if (!(D_global_asm_807FBB64 & 0x80000000)) {
                        func_global_asm_806E9D1C(5, 3, 1);
                    }
                }
            }
        }
    }
}

void func_global_asm_806EA04C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS) {
        func_global_asm_806E9D1C(7, 3, 0);
    }
}

void func_global_asm_806EA0A4(void) {
    PlayerAdditionalActorData *PaaD; // TODO: Probably not actually PaaD
    u16 temp;
    u8 phi_a0;

    PaaD = extra_player_info_pointer->unk104->PaaD;
    if ((D_global_asm_807FBB64 & 1) && !(D_global_asm_807FBB68 & 2)) {
        phi_a0 = 2;
    } else {
        phi_a0 = 3;
    }
    if ((PaaD->unkEF) && ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) && ((PaaD->unkEE == phi_a0) || (PaaD->unkFC == 0))) {
        PaaD->unkF0_u8[0] = PaaD->unkEF;
        if (PaaD->unkEF < phi_a0) {
            PaaD->unkEF++;
        } else {
            PaaD->unkEF = 1;
        }
        func_global_asm_8062217C(extra_player_info_pointer->unk104, PaaD->unkEF);
        PaaD->unkEE = PaaD->unkEF;
        if (PaaD->unkEF != PaaD->unkF0) {
            temp = PaaD->unk8;
            if ((((temp == 0)) || (temp >= 0x96)) && (PaaD->unkF0_u8[3] != 2)) {
                playSound(0x27, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
        }
        PaaD->unkF0_u8[1] = 0xB;
        PaaD->unkF4_u8[2] = 0xF;
    }
}

void func_global_asm_806EA200(void) {
    PlayerAdditionalActorData *PaaD = extra_player_info_pointer->unk104->PaaD;
    if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS) && (PaaD->unkF0_u8[1] < 3)) {
        PaaD->unkB0 -= 0x2D;
        PaaD->unkF0_u8[1] = 0xB;
    }
}

void func_global_asm_806EA26C(void) {
    PlayerAdditionalActorData *PaaD = extra_player_info_pointer->unk104->PaaD;
    if ((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS) && (PaaD->unkF0_u8[1] < 3)) {
        PaaD->unkB0 += 0x2D;
        PaaD->unkF0_u8[1] = 0xB;
    }
}

f32 func_global_asm_806EA2D8(void) {
    return D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG ? D_global_asm_8075D358 : 1;
}

void func_global_asm_806EA334(void) {
    f32 temp_f2;
    f32 phi_f0;

    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && !(D_global_asm_807FD610[cc_player_index].unk2A & L_CBUTTONS) && current_actor_pointer->control_state == 2) {
        phi_f0 = current_map == MAP_DK_ISLES_OVERWORLD ? 15.0 : 13.0;
        temp_f2 = character_change_array[cc_player_index].fov_y - 1.5f;
        if (phi_f0 < temp_f2) {
            character_change_array[cc_player_index].fov_y = temp_f2;
            func_global_asm_80604CBC(current_actor_pointer, 0x1F0, 0, 0, 0, 0xFF, 1.0f, -1);
        } else {
            character_change_array[cc_player_index].fov_y = phi_f0;
            func_global_asm_80605314(current_actor_pointer, 0);
        }
    }
}

void func_global_asm_806EA460(void) {
    f32 temp_f0;
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && !(D_global_asm_807FD610[cc_player_index].unk2A & R_CBUTTONS) && current_actor_pointer->control_state == 2) {
        temp_f0 = character_change_array[cc_player_index].fov_y + 1.5f;
        if (temp_f0 < D_global_asm_8075D360) {
            character_change_array[cc_player_index].fov_y = temp_f0;
            func_global_asm_80604CBC(current_actor_pointer, 0x1F0, 0, 0, 0, 0xFF, 1.0f, -1);
        } else {
            character_change_array[cc_player_index].fov_y = 45.0f;
            func_global_asm_80605314(current_actor_pointer, 0);
        }
    }
}

void func_global_asm_806EA568(void) {
    u16 temp = D_global_asm_807FD610[cc_player_index].unk2A & (L_CBUTTONS | R_CBUTTONS);
    if (temp != L_CBUTTONS && temp != R_CBUTTONS) {
        func_global_asm_80605314(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA5CC(void) {
    if (func_global_asm_806E9580()) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EA600(void) {
    func_global_asm_806EA568();
    func_global_asm_806EA5CC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_CEAE0/func_global_asm_806EA628.s")

f32 func_global_asm_806EA2D8(void);
extern f64 D_global_asm_8075D368;
extern f64 D_global_asm_8075D370;
extern f64 D_global_asm_8075D378;

/*
// TODO: Pretty close, float and stack nonsense
void func_global_asm_806EA628(void) {
    PlayerAdditionalActorData *temp_a0;
    f32 *temp_v0;
    s16 *temp_v1;

    if (!(extra_player_info_pointer->unk1F0 & 0x8000)) {
        temp_a0 = extra_player_info_pointer->unk104->additional_actor_data;
        temp_v1 = &temp_a0->unkB2;
        *temp_v1 = (D_global_asm_807FD610[cc_player_index].unk2E * D_global_asm_8075D368 * func_global_asm_806EA2D8() * 4096.0) / D_global_asm_8075D370;
        temp_v0 = &temp_a0->unkB8;
        *temp_v0 = D_global_asm_807FD610[cc_player_index].unk2F * D_global_asm_8075D378 * func_global_asm_806EA2D8();
        *temp_v1 &= 0xFFF;
        if (temp_a0->unkBC + 0x32 < *temp_v0) {
            *temp_v0 = temp_a0->unkBC + 0x32;
        } else if (*temp_v0 < temp_a0->unkBC - 0x50) {
            *temp_v0 = temp_a0->unkBC - 0x50;
        }
        extra_player_info_pointer->unk104->distance_from_floor = *temp_v0;
        current_actor_pointer->y_rotation = (temp_a0->unkB2 + 0x800) & 0xFFF;
    }
}
*/

void func_global_asm_806EA7E8(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == A_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA844(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == B_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA8A0(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == A_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EA8FC(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == B_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EA958(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == U_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA9B4(void) {
    // TODO: Bitfield syntax?
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        func_global_asm_806E9874();
    } else if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EAA44(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == U_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EAAA0(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS) && !(D_global_asm_807FBB64 & 2)) {
        func_global_asm_806E9804(8);
        return;
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EAB44(Actor *arg0, u8 arg1) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    if ((PaaD->unk1F4 & 0x10) == 0) {
        playSound(0x27, 0x7FFF, 63.0f, 1.0f, 0, 0);
    }
    if (arg1 != 0) {
        if (current_character_index[cc_player_index] == 7) {
            if ((arg0->unkAC - arg0->y_position) < 20.0f) {
                arg0->control_state = 0x7E;
                arg0->control_state_progress = 0;
            } else {
                arg0->control_state = 0x7F;
                arg0->control_state_progress = 0;
            }
        } else {
            arg0->control_state = 0x4F;
            arg0->control_state_progress = 3;
        }
    } else {
        arg0->control_state = 1;
        arg0->control_state_progress = 0;
        func_global_asm_806CFF9C(arg0);
        if (arg0->control_state == 0xC) {
            arg0->control_state_progress = 0xA;
        }
    }
    if (PaaD->unk8C != 0) {
        func_global_asm_806F0D68(arg0);
    } else {
        func_global_asm_806F0C18(arg0);
    }
    arg0->unkB8 = 0.0f;
    arg0->y_rotation = func_global_asm_8062773C(PaaD->unk104);
}

void func_global_asm_806EAC8C() {
    Actor178 *temp_v0 = extra_player_info_pointer->vehicle_actor_pointer->unk178;
    if (temp_v0->unkE == 5) {
        temp_v0->unkE = 0xA;
    }
}

void func_global_asm_806EACBC() {
    Actor178 *temp_v0 = extra_player_info_pointer->vehicle_actor_pointer->unk178;
    if (temp_v0->unkE == 5) {
        temp_v0->unkE = 0xF;
    }
}

void func_global_asm_806EACEC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((current_actor_pointer->unk6A & 1) && ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU)) {
        func_global_asm_806CFECC();
        current_actor_pointer->y_velocity = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        extra_player_info_pointer->unk3C = 0;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        func_global_asm_80608528(current_actor_pointer, 0x309, 0xFF, 0x7F, 0);
    }
}

void func_global_asm_806EAE04(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if ((vehicle->control_state == 0) && (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON)) {
        vehicle->control_state = 1;
    }
}

void func_global_asm_806EAE60(void) {
    // Joystick range check
    if ((D_global_asm_807FD610[cc_player_index].unk2E >= 41) || (D_global_asm_807FD610[cc_player_index].unk2F >= 41)) {
        if (extra_player_info_pointer->unk108 != 0.0f) {
            extra_player_info_pointer->unk108 = 0.0f;
            extra_player_info_pointer->unk200 = MAX(1, extra_player_info_pointer->unk200 - 5);
            return;
        }
    }
    // Joystick range check
    if (((D_global_asm_807FD610[cc_player_index].unk2E < -40) || (D_global_asm_807FD610[cc_player_index].unk2F < -40)) && extra_player_info_pointer->unk108 == 0.0f) {
        extra_player_info_pointer->unk108 = 1.0f;
        extra_player_info_pointer->unk200 = MAX(1, extra_player_info_pointer->unk200 - 5);
    }
}

void func_global_asm_806EAF6C(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        switch (vehicle->control_state) {
            case 2:
                vehicle->control_state = 4;
                vehicle->control_state_progress = 0;
                break;
            case 5:
                vehicle->control_state_progress++;
                break;
            }
    }
}

void func_global_asm_806EAFEC(void) {

}

void func_global_asm_806EAFF4(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) {
        current_actor_pointer->y_velocity = 0.0f;
    } else {
        current_actor_pointer->y_velocity = 120.0f;
    }
}

void func_global_asm_806EB058(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2A & (U_CBUTTONS | D_CBUTTONS)) {
        current_actor_pointer->y_velocity = 0.0f;
    } else {
        current_actor_pointer->y_velocity = -120.0f;
    }
}
