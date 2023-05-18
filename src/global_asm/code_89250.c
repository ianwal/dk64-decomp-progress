#include <ultra64.h>
#include "functions.h"


extern s32 D_80717D4C;
extern s32 D_80717930;
extern s32 D_80718BF4;
extern s32 D_807197B4;
extern s32 D_8071827C;
extern s32 D_80719B88;
extern s32 D_80719C00[];
extern s32 D_8071AF30;
extern s32 D_8071EFDC;
extern s32 D_8071FC40;
extern s32 D_8071FF18;
extern s32 D_8071FF40;
extern s32 D_8071FF58;
extern s32 D_8071FFA0;
extern s32 *D_8072006C;
extern s32 D_80720120;
extern s32 D_80720558;
extern s32 D_807210EC;
extern s32 D_80721158;
extern s32 D_8072139C;

extern s32 D_8074E880[];
extern u8 D_80750AD0;
extern f64 D_80759AB8;
extern f64 D_80759AC0;
extern f64 D_80759AB0;
extern f64 D_80759A90;
extern f64 D_80759A98;
extern f64 D_80759AA0;
extern f64 D_80759AA8;
extern f64 D_80759B60; // y
extern f64 D_80759B70;
extern f64 D_80759B68;

void func_80719A0C(void); // Function pointer
void func_806858E8(Actor*, s16, f32, f32, f32, f32, s32);
void func_80686390(Actor*, f32, f32, f32, f32);
void func_80685F60(Actor *actor);

void func_80684550(Actor *arg0, u8 arg1, f32 arg2) {
    func_807149B8(1);
    func_8071498C(&D_8071AF30);
    func_80714950(arg0);
    func_80714A28(4);
    func_80714C08(&D_80720120, arg2, current_actor_pointer, arg1, 0);
}

void func_806845B8(u8 arg0, u8 arg1) {
    f32 sp2C;
    u8 sp2B;

    if ((object_timer & 3) == 0) {
        sp2C = current_actor_pointer->animation_state->scale_y / D_80759A90;
        sp2B = (((rand() >> 0xF) % 0x7FFF) % ((arg1 - arg0) + 1)) + arg0;
        func_80714998(3);
        func_807149C8(0xE6, 0xE6, 0xE6, 0xE6);
        func_8068588C(current_actor_pointer, sp2B, sp2C, 0.0f, 0.0f, 0.0f, -0x78);
    }
}

// spawnShockwave(xPosition, yPosition, zPosition, xzScale, yScale, parentActor, arg6)
void func_806846B4(f32 xPosition, f32 yPosition, f32 zPosition, f32 xzScale, f32 yScale, Actor *arg5, u8 arg6) {
    s32 phi_a1;

    phi_a1 = 0xAD;
    if (arg5) {
        switch (arg5->unk58) {
            case ACTOR_TINY:
            case ACTOR_KASPLAT_TINY:
                phi_a1 = 0xD1;
                break;
            case ACTOR_LANKY:
            case ACTOR_KASPLAT_LANKY:
                phi_a1 = 0xD0;
                break;
            case ACTOR_CHUNKY:
            case ACTOR_KASPLAT_CHUNKY:
                phi_a1 = 0xCF;
                break;
            case ACTOR_DIDDY:
            case ACTOR_KASPLAT_DIDDY:
                phi_a1 = 0xAE;
                break;
        }
    }
    func_80677FA8(0xFF, phi_a1); // Spawn actor: Shockwave
    D_807FBB44->unk11C = arg5;
    D_807FBB44->animation_state->scale_x = xzScale;
    D_807FBB44->animation_state->scale_z = xzScale;
    D_807FBB44->animation_state->scale_y = yScale;
    D_807FBB44->x_position = xPosition;
    D_807FBB44->y_position = yPosition;
    D_807FBB44->z_position = zPosition;
    if (arg5 && (arg5->interactable & 1)) {
        if (arg6) {
            D_807FBB44->unk168 = 0xF;
            D_807FBB44->unk160 = D_80759A98;
            D_807FBB44->unk15F = 1;
        } else {
            D_807FBB44->unk168 = 0x19;
            D_807FBB44->unk160 = D_80759AA0;
        }
    } else {
        D_807FBB44->unk168 = 0x20;
        D_807FBB44->unk160 = D_80759AA8;
        D_807FBB44->unk15F = 0;
    }
}

void func_80684850(u8 arg0) {
    if ((object_timer & 0x1F) == 0) {
        func_80714998(2);
        func_807149B8(1);
        func_807149FC(0x3C);
        func_8071498C(&D_807197B4);
        if (arg0) {
            func_80714C08(&D_8071FF58, 0.05f, current_actor_pointer, arg0, 0);
            return;
        }
        func_80714CC0(&D_8071FF58, 0.05f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    }
}

void func_80684900(u8 arg0) {
    if (arg0 != 0) {
        func_80714950(((rand() >> 0xF) % 10) + 0x8008);
    } else {
        func_80714950(((rand() >> 0xF) % 8) + 6);
    }
    func_807149FC(2);
    func_8071498C(&D_80717930);
    func_807149B8(1);
    func_80714A28(4);
    func_80714C08(&D_8072139C, (((rand() >> 0xF) % 50) / 80.0) + D_80759AB0, current_actor_pointer, 8, 0);
}

void func_80684A00(s16 arg0, s8 arg1) {
    f32 sp3C, sp38, sp34, sp30;

    sp30 = current_actor_pointer->animation_state->scale_y / D_80759AB8;
    func_80671C0C(current_actor_pointer, arg0, &sp3C, &sp38, &sp34);
    func_80714950((((rand() >> 0xF) % 100) + 400) * arg1);
    func_8071498C(&D_80717D4C);
    func_807149B8(1);
    func_80714CC0(D_8074E880[((rand() >> 0xF) % 1000) % 3],
        sp30 * D_80759AC0,
        ((rand() >> 0xF) % 20) + (sp3C - 10.0f),
        sp38,
        ((rand() >> 0xF) % 20) + (sp34 - 10.0f)
    );
}

// Similar to above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80684BB0.s")

extern f64 D_80759AC8;
extern f64 D_80759AD0;
extern f64 D_80759AD8;
extern s32 D_8071F2F8;

/*
void func_80684BB0(s16 arg0, s16 arg1, s16 arg2) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    s32 temp; // Padding, TODO: Can we get rid of this?
    f64 temp_f0;
    f64 phi_f2;

    sp48 = current_actor_pointer->animation_state->scale_y / D_80759AC8;
    func_80671C0C(current_actor_pointer, arg0, &sp54, &sp50, &sp4C);
    func_80714950(arg1 + (arg2 << 0x10));
    func_8071498C(&D_8071F2F8);
    func_807149B8(1);
    temp_f0 = arg2 * D_80759AD0;
    if (temp_f0 < 2.0) {
        phi_f2 = 2.0;
    } else {
        phi_f2 = temp_f0;
    }
    func_807149FC(0, phi_f2); // TODO: This might be wrong
    func_80714CC0(
        D_8074E880[((rand() >> 0xF) % 1000) % 3],
        sp48 * D_80759AD8,
        ((rand() >> 0xF) % 60) + (sp54 - 30.0f),
        sp50,
        ((rand() >> 0xF) % 60) + (sp4C - 30.0f)
    );
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80684D98.s")

void func_80685020(u8 arg0, u8 arg1) {
    if ((arg0 & object_timer) == 0) {
        func_8071498C(&D_80718BF4);
        func_807149B8(1);
        func_807149FC(-1);
        func_80714A28(4);
        if (arg1) {
            func_80714C08(&D_8071FC40, 0, current_actor_pointer, arg1, 0);
            return;
        }
        func_80714CC0(&D_8071FC40, 0, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_806850D0.s")

/*
extern s32 D_8071FE08;
extern f64 D_80759AE8;
extern f64 D_80759AE0;
extern s32 D_8071910C;
extern s32 D_8072073C;

void func_806850D0(void) {
    f32 temp_f20;
    s32 temp_s0;

    temp_f20 = current_actor_pointer->animation_state->scale_y / D_80759AE0;
    func_807149B8(0);
    func_807149FC(1);
    func_80714CC0(&D_8071FE08,
        temp_f20 * 0.75,
        current_actor_pointer->x_position,
        current_actor_pointer->y_position,
        current_actor_pointer->z_position
    );
    for (temp_s0 = 0; temp_s0 < 7; temp_s0++) {
        func_807149B8(1);
        func_807149FC(0xA);
        func_8071498C(&D_8071910C);
        func_80714998(2);
        func_80714950(0);
        func_80714CC0(&D_8072073C,
            temp_f20 * D_80759AE8,
            current_actor_pointer->x_position,
            current_actor_pointer->y_position,
            current_actor_pointer->z_position
        );
    }
}
*/

void func_80685210(f32 arg0, s16 arg1, s16 arg2) {
    if ((((u32) object_timer % 3) == 0) && (arg1 < current_actor_pointer->unkB8)) {
        func_80714998(2);
        func_807149B8(1);
        func_8071498C(&D_80717D4C);
        func_80714950(-0x32);
        func_80714A28(4);
        func_80714C08(&D_8071FF18, arg0, current_actor_pointer, arg2, 0);
    }
}

void func_806852C4(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s16 phi_s0;

    for (phi_s0 = 0; phi_s0 < 8; phi_s0++) {
        func_8071498C(&func_80719A0C);
        func_80714950(phi_s0);
        func_807149B8(1);
        func_807149C8(0xFF, 0xFF, 0xFF, 0xC8);
        func_80714CC0(&D_8071FFA0, arg0, arg1, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80685390.s")

/*
typedef struct {
    f32 *unk0;
    s32 unk4;
    s32 unk8;
} Struct8074E88C;

extern Struct8074E88C D_8074E88C;
extern f32 D_80759AF0;

typedef struct {
    f32 unk0;
    u16 unk4;
    u8 unk6;
} AAD_80685390;

// TODO: Eh doable, kinda fiddly
void func_80685390(void) {
    AAD_80685390 *temp_v0;
    Struct8074E88C sp20;

    temp_v0 = current_actor_pointer->additional_actor_data;
    sp20 = D_8074E88C;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_v0->unk0 = current_actor_pointer->animation_state->scale_y;
    }
    temp_v0->unk4++;
    switch (current_actor_pointer->control_state) {
        case 0:
            current_actor_pointer->animation_state->scale_y = sp20.unk0[temp_v0->unk6] * (temp_v0->unk4 * temp_v0->unk0 * D_80759AF0);
            if (temp_v0->unk4 > 3.0f) {
                current_actor_pointer->control_state = 1;
                temp_v0->unk4 = 0;
                func_8068842C(current_actor_pointer, 0, 1);
                func_80688370(current_actor_pointer, 0, 0.5f);
            }
            break;
        case 1:
            if (func_80688540(current_actor_pointer, 0) == 0) {
                func_806782C0(current_actor_pointer);
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

void func_80685520(f32 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_s0;
    s32 phi_s0;

    if (D_80750AD0 == 0) {
        if (arg1 > 0) {
            func_806852C4(arg0, arg2, arg3, arg4);
        }
        if (arg1 >= 2) {
            temp_s0 = &D_80719B88;
            for (phi_s0 = 0; phi_s0 < 8; phi_s0++) {
                func_8071498C(temp_s0);
                func_80714950(phi_s0);
                func_807149B8(1);
                func_807149FC(-1);
                func_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
                func_80714CC0(&D_8071FF40, arg0 * 0.5, arg2, arg3, arg4);
            }
        }
        if (arg1 >= 3) {
            temp_s0 = &D_80719C00;
            for (phi_s0 = 0; phi_s0 < 9; phi_s0++) {
                func_8071498C(temp_s0);
                func_80714950(phi_s0);
                func_807149B8(1);
                func_807149FC(-1);
                func_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
                func_80714CC0(D_8074E880[phi_s0 % 3], arg0, arg2, arg3, arg4);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80685708.s")

typedef struct {
    s32 unk0[4];
} Struct8074E898;

extern Struct8074E898 D_8074E898;
extern f64 D_80759AF8;
extern f64 D_80759B00;

typedef struct {
    s32 unk0;
    s16 unk4;
    s8 unk6;
} AAD_80685708;

/*
// TODO: Very close, stack/arg1 nonsense
void func_80685708(Actor *arg0, u8 arg1) {
    s32 temp;
    Struct8074E898 sp34;
    f32 p1 = (arg0->animation_state->scale_y / D_80759AF8);

    sp34 = D_8074E898;
    if (arg1 != 0) {
        func_80685520(p1 * D_80759B00, arg1, arg0->x_position, arg0->y_position + 4.0f, arg0->z_position);
        func_80677FA8(0x145, sp34.unk0[arg1]);
        func_8067B238(D_807FBB44, arg0, arg0->animation_state->scale_y * 0.5f);
        ((AAD_80685708*)D_807FBB44->additional_actor_data)->unk6 = arg1 - 1;
    }
}
*/

void func_8068581C(s32 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    func_80714998(2);
    func_807149C8(0xFF, 0xFF, 0xFF, 0xC8);
    func_8068588C(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

void func_8068588C(Actor *arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    func_807149B8(1);
    func_806858E8(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

// Returns struct from function call in a weird way... Doable once we figure out which struct is returned.
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_806858E8.s")

// Surprisingly doable, just a huge function call that will be interesting to decipher
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80685984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80685B44.s")

extern s32 D_807180F4; // TODO: Datatype, just for pointer

/*
// TODO: Pretty close
void func_80685B44(void *arg0, s32 arg1, f32 arg2, u8 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8) {
    s8 temp_s0;
    s8 temp_s4;
    s16 i;

    for (i = 0; i < arg3; i++) {
        temp_s4 = (((rand() >> 0xF) % 32767) % (arg4 * 2)) + -arg4;
        temp_s0 = (((rand() >> 0xF) % 32767) % (arg4 * 2)) + -arg4;
        func_80714950(-arg5 - ((rand() >> 0xF) % 80));
        func_8071498C(&D_807180F4);
        func_807149B8(1);
        func_80714998(2);
        if (arg1 != 0) {
            func_8071496C(arg1);
        }
        func_80714CC0(arg0, arg2, arg6 + temp_s4, arg7, arg8 + temp_s0);
    }
}
*/

void func_80685D84(Actor *arg0) {
    if (!(arg0->unk64 & 4)) {
        if ((arg0->object_properties_bitfield & 0x10) && ((arg0->unk6A ^ arg0->unk6C) & 4)) {
            func_80686390(arg0, 0, arg0->x_position, arg0->unkAC, arg0->z_position);
        }
        if (arg0->unk6A & 4) {
            func_80685F60(arg0);
        }
    }
    if ((arg0->unk68 & 0x40) && func_80665AAC(arg0) && (!(arg0->unk6A & 0x800)) && arg0->floor <= arg0->y_position) {
        func_806A081C(arg0);
    }
    if (arg0->unk68 & 0x80) {
        func_80663844(arg0);
    }
}

// Returns struct from function call in a weird way... Doable once we figure out which struct is returned.
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80685E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80685F60.s")

/*
extern f32 D_80753A08[];
extern f32 D_80753A18[];

// TODO: Doable, just need to figure out what actor118 points to
void func_80685F60(Actor *actor) {
    u8 sp1B;
    Actor *temp_a1;
    f32 temp_f0;
    u32 temp_a0;
    u32 temp_v0;
    u8 temp_t9;
    f32 phi_f0;
    u8 phi_v1;
    u8 phi_v1_2;
    Actor *phi_a1;
    u8 phi_v1_3;

    temp_a1 = actor;
    phi_v1 = 0;
    phi_a1 = temp_a1;
    phi_v1_3 = 0;
    if ((actor->unk0 != 0) && (actor->animation_state != 0)) {
        if (actor->interactable == 1) {
            if (character_change_array[cc_player_index].unk2C0 == 1) { // TODO: This is marked f32 in the struct, which is correct?
                phi_f0 = D_80753A08[actor->unk58 * 2];
            } else {
                phi_f0 = D_80753A18[actor->unk58 * 2];
            }
        } else {
            phi_f0 = temp_a1->unk15E;
        }
        if ((temp_a1->unkAC - phi_f0) <= temp_a1->y_position) {
            temp_a0 = object_timer;
            if ((object_timer & 3) == 0) {
                if (temp_a1->unkB8 != 0.0) {
                    phi_v1_3 = 1;
                }
                temp_v0 = temp_a1->unk118;
                phi_v1 = phi_v1_3 & 0xFF;
                if ((temp_v0) && (temp_v0->unk10 != 0)) {
                    phi_v1 = 1;
                }
            }
            phi_v1_2 = phi_v1;
            if (phi_v1 != 0) {
                sp1B = phi_v1;
                actor = temp_a1;
                func_80714950(1, temp_a1);
                phi_v1_2 = phi_v1;
                phi_a1 = actor;
            } else if ((temp_a1->unkB8 == 0.0) && (((object_timer % 24) == 0) || (temp_a1->unkBC != 0.0))) {
                phi_v1_2 = 1;
            }
            if (phi_v1_2 != 0) {
                func_80685E78(phi_a1, phi_a1);
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_8068613C.s")

void func_80608528(Actor *, s32, s32, s32, s32);
s32 func_806119A0();
extern s32 D_8071DB74; // TODO: Datatype
extern s32 D_8071FC0C; // TODO: Datatype
extern s32 D_80720B58; // TODO: Datatype
extern u8 D_80750AD0;
extern f64 D_80759B18;
extern f64 D_80759B20;
extern f64 D_80759B28;

/*
// TODO: Pretty close
void func_8068613C(Actor *arg0) {
    f64 sp48;
    ActorAnimationState *temp_v0;
    f32 temp_f20;
    f32 var_f20;
    u8 temp_v1;
    u8 i;

    temp_v0 = arg0->animation_state;
    if (temp_v0 != NULL) {
        var_f20 = temp_v0->scale_y / D_80759B18;
    } else {
        var_f20 = 1.0f;
    }
    if (arg0->unk58 == ACTOR_BOSS_PROJECTILE_FIREBALL) {
        var_f20 *= 2;
        func_8068588C(arg0, 0, 4.0f, arg0->x_position, arg0->y_position, arg0->z_position, -0x96);
        func_806782C0(arg0);
    }
    func_80608528(arg0, 0xC, 0xFF, 0x7F, 1);
    func_807149B8(1);
    func_807149FC(1);
    func_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
    func_80714CC0(&D_8071FC0C, var_f20 * D_80759B20, arg0->x_position, arg0->unkAC + 15.0f, arg0->z_position);
    if (D_80750AD0 == 0) {
        temp_v1 = (func_806119A0() & 3) + 4;
        temp_f20 = var_f20 * D_80759B28;
        for (i = 0; i < temp_v1; i++) {
            func_807149B8(1);
            func_807149FC(-1);
            func_8071498C(&D_8071DB74);
            func_80714A28(4);
            func_80714CC0(&D_80720B58, temp_f20, arg0->x_position, arg0->unkAC, arg0->z_position);
        }
    }
}
*/

void func_80686340(void) {
    func_807149B8(1);
    func_807149FC(0x14);
    func_8071498C(&D_8071827C);
    func_807149C8(0xFF, 0xFF, 0xFF, 0xC8);
    func_80714A28(4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80686390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_8068696C.s")

extern f32 D_80759B50;

extern void func_8071DC90(void); // Function pointer

/*
// TODO: Weird regalloc again, at s2, s3
void func_8068696C(Actor *arg0) {
    s32 phi_s0;
    f32 temp_f20 = D_80759B50;
    for (phi_s0 = 0; phi_s0 < 0x10; phi_s0++) {
        func_807149B8(1);
        func_807149FC(-1);
        func_80714950(arg0);
        func_8071498C(&func_8071DC90);
        func_80714CC0(D_8074E880[phi_s0 % 3], temp_f20, arg0->x_position, arg0->y_position, arg0->z_position);
    }
}
*/

// Probably will have the same regalloc as above
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80686A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80686CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80686E40.s")

void func_80686F90(u8 arg0, s16 arg1, s16 arg2) {
    func_80677FA8(0x109, 0xC0); // Spawn actor: Light beam (boss fights)
    if (arg0) {
        func_80671C0C(current_actor_pointer, arg0, &D_807FBB44->x_position, &D_807FBB44->y_position, &D_807FBB44->z_position);
    } else {
        D_807FBB44->x_position = current_actor_pointer->x_position;
        D_807FBB44->y_position = current_actor_pointer->y_position;
        D_807FBB44->z_position = current_actor_pointer->z_position;
    }
    D_807FBB44->y_rotation = arg1;
    D_807FBB44->z_rotation = arg2;
    D_807FBB44->animation_state->scale_y *= D_80759B60;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_80687080.s")

/*
void func_806782C0(Actor*);
void func_806319C4(Actor*, s32);

void func_80687080(void) {
    f64 scaleMult;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = ((rand() >> 0xF) % 75) + 180;
        current_actor_pointer->unk16C = 0x28;
        current_actor_pointer->shadow_opacity = 0xFF;
    }
    if (current_actor_pointer->animation_state->scale_y > 1.0) {
        current_actor_pointer->shadow_opacity -= 0x28;
        if (current_actor_pointer->shadow_opacity < 0) {
            func_806782C0(current_actor_pointer);
        }
    } else {
        // TODO: Needs .rodata defined
        scaleMult = 0.3333; // D_80759B68
        current_actor_pointer->animation_state->scale_y *= D_80759B70;
        current_actor_pointer->animation_state->scale_x *= scaleMult;
        current_actor_pointer->animation_state->scale_z *= scaleMult;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_806871DC.s")

void func_80687400(void) {
    playSound(0x2D4, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_807149FC(0xC8);
    func_8071495C();
    func_8071498C(&D_8071EFDC);
    func_80714CC0(&D_80721158, 1.0f, 160.0f, 120.0f, -10.0f);
}

void func_80687474(Actor *arg0, f32 arg1) {
    func_80677FA8(0xB3, 0x5D); // Spawn actor: Shockwave (Mad Jack)
    D_807FBB44->object_properties_bitfield |= 0x400;
    func_80614EBC(D_807FBB44, 0x334);
    func_8067B238(D_807FBB44, arg0, arg0->animation_state->scale_y * arg1);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_806874EC.s")

void func_806877C8(u8 arg0) {
    func_807149B8(1);
    func_80714C08(&D_8072006C, 1.0f, current_actor_pointer, arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_89250/func_8068780C.s")

void func_80626F8C(f32, f32, f32, f32 *, f32 *, s32, f32, s32);
void func_8065A708(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

extern s32 D_8071E028;
extern s32 D_80720B24;

extern f64 D_80759BA0;
extern f32 D_80759BA8;

/*
// TODO: Very close, our stack is too big
void func_8068780C(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    f32 dx;
    f32 dz;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    u16 sp46; // Padding, not used
    u8 sp45;
    u8 sp44;

    sp45 = (((rand() >> 0xF) % 32767) % ((arg1 - arg0) + 1)) + arg0;
    sp44 = (((rand() >> 0xF) % 32767) % ((arg3 - arg2) + 1)) + arg2;
    func_80671C0C(current_actor_pointer, sp45, &sp74, &sp70, &sp6C);
    func_80671C0C(current_actor_pointer, sp44, &sp68, &sp64, &sp60);
    func_80626F8C(sp74, sp70, sp6C, &sp58, &sp54, 0, 1.0f, 0);
    func_80626F8C(sp68, sp64, sp60, &sp50, &sp4C, 0, 1.0f, 0);
    sp5C = ((func_80665DE0(sp50, sp4C, sp58, sp54) * 0x168) / 4096) + 0x5A;
    if (sp5C < 270.0f) {
        sp5C += 180.0f;
    }
    dx = sp58 - sp50;
    dz = sp54 - sp4C;
    sp48 = sqrtf((dx * dx) + (dz * dz));
    func_807149B8(1);
    func_807149FC(1);
    func_80714950(sp5C);
    func_8071498C(&D_8071E028);
    func_80714CC0(&D_80720B24, sp48 * D_80759BA0, (sp74 + sp68) * 0.5, (sp70 + sp64) * 0.5, (sp6C + sp60) * 0.5);
    if (((rand() >> 0xF) % 1000) & 1) {
        func_806595F0(1);
        func_8065A708(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0.0f, 0.0f, 0.0f, 150.0f, 0, 0x96, 0x64, 0xFF);
    }
    if ((current_actor_pointer->unk58 == ACTOR_BOSS_ARMY_DILLO) && (((rand() >> 0xF) % 1000) >= 0x385)) {
        func_806877C8(((((rand() >> 0xF) % 32767) % 10) + 0xD));
        func_806086CC(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, ((rand() >> 0xF) % 1000) >= 0x1F5 ? 0x8A : 0xA1, 0xFF, 0x7F, 0x28, 0, D_80759BA8, 0);
    }
}
*/

void func_80687C48(void) {
    playSound(0xF2, 0x7FFF, 63.0f, 1.0f, 0, 0);
    playSong(0x97, 1.0f);
    func_807149FC(0xC8);
    func_8071495C();
    func_8071498C(&D_8071EFDC);
    func_80714CC0(&D_80720558, 1.0f, 160.0f, 120.0f, -10.0f);
}

void func_80687CC8(void) {
    playSound(0xF2, 0x7FFF, 63.0f, 1.0f, 0, 0);
    playSong(0x97, 1.0f);
    func_807149FC(0xC8);
    func_8071495C();
    func_8071498C(&D_8071EFDC);
    func_80714CC0(&D_807210EC, 1.0f, 160.0f, 120.0f, -10.0f);
}
