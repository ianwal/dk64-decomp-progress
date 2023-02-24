#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80717D4C;
extern s32 D_8071AADC;
extern s32 D_8071FBC8;
extern s32 D_8071FF18;
extern s32 D_8071FFA0;
extern s32 D_80720A7C;
extern s32 D_80721530;

extern u8 D_80750AB4;
extern s32 D_807552E8;
extern f64 D_80758AA8; // Z position
extern f64 D_80758AB0; // X position
extern f64 D_80758AB8; // Radius for dx/dz
extern f64 D_80758BD8;

extern f32 D_807F621C; // X
extern f32 D_807F6220; // Y
extern f32 D_807F6224; // Z
extern f32 D_807F6228;
extern f32 D_807F622C;
extern f32 D_807F6230;
extern f32 D_807F6234;
extern f32 D_807F6238;
extern s8 D_807F6950;
extern s8 D_807F6951;

void func_80614D00(Actor*, f32, f32);

void func_806335B0(s16, s32, s32, f32*, f32*, f32*);

s32 func_806418E8(s16, s16, s16);
u8 func_8064EC60(s32, s16, s16, s16);
extern void func_8064EE08(void);

void func_8065A708(f32, f32, s32, f32, f32, f32, f32, s32, u8, u8, u8); // TODO: Is this signature correct?

u8 func_80661300(s32);
void func_8066134C(s32, u8);

void func_8067DF44(f32, f32, f32, f32, s32, s32);

void func_80714950(s32);
void func_80714998(s32);
void func_807149B8(s32);
void func_80714B84(void*, f32, s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063D930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063D990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063D9D0.s")

void func_8063DA40(s16 arg0, s16 arg1) {
    func_8063DA78(arg0, arg1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063DA78.s")

void func_8063DA40(s16, s16);

typedef struct {
    s16 unk0; // Used
    s16 unk2; // Used
    s16 unk4; // Used
    u8 unk6; // Used
    u8 unk7;
} Struct807F61B0;

extern Struct807F61B0 D_807F61B0[];

void func_8063DB0C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_807F61B0[i].unk6 = FALSE;
    }
}

void func_8063DB3C(s16 arg0, s16 arg1, s16 arg2) {
    s16 phi_v0 = 0;
    s32 phi_v1 = FALSE;

    while (!phi_v1 && phi_v0 < 8) {
        if (!D_807F61B0[phi_v0].unk6) {
            phi_v1 = TRUE;
        } else {
            phi_v0++;
        }
    }

    if (phi_v1) {
        D_807F61B0[phi_v0].unk6 = TRUE;
        D_807F61B0[phi_v0].unk0 = arg0;
        D_807F61B0[phi_v0].unk2 = arg1;
        D_807F61B0[phi_v0].unk4 = arg2;
    }
}

void func_8063DBD8(s16 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_807F61B0[i].unk6 && (arg0 == D_807F61B0[i].unk0)) {
            func_8063DA40(D_807F61B0[i].unk2, D_807F61B0[i].unk4);
            D_807F61B0[i].unk6 = FALSE;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063DC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063DE68.s")

// Probably initting a struct, easy way to figure out the shape
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063DED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063DFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063E078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063E0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063E5B4.s")

// Object model 2 behaviour passed in?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063E6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063E72C.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063EA14.s")

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8063FA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806417BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806418E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064199C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806419F8.s")

/*
// TODO: Likely needs to be split into switch cases
s32 func_806419F8(void) {
    CharacterChange *temp_v1;
    s16 temp_a1;
    temp_v1 = &character_change_array[0];

    if (
        ((player_pointer->control_state == 0x42) && ((temp_a1 = temp_v1->player_pointer->PaaD->unkBC, (temp_a1 == 0x62)) || (temp_a1 == 0x88) || (temp_a1 == 0x17)))
        || (player_pointer->control_state == 0x52)
        || (player_pointer->control_state == 0x67)
        || ((temp_v1->action_initiated == 0x1C)) || (temp_v1->action_initiated == 0x53)) {
        return 0;
    }
    return 1;

    // TODO: aaa
    // switch (player_pointer->control_state) {
    //     case 0x42:
    //         switch (character_change_array[0].player_pointer->PaaD->unkBC) {
    //             case 0x62:
    //             case 0x88:
    //             case 0x17:
    //                 return 0;
    //         }
    //         break;
    //     case 0x52:
    //     case 0x67:
    //         return 0;
    // }
    // switch (character_change_array[0].action_initiated) {
    //     case 0x1C:
    //     case 0x53:
    //         return 0;
    // }
}
*/

extern u8 D_807F6938;
extern s16 D_807F6918[];

// TODO: This does match but the types on the externs are sus
void func_80641A78(void) {
    s32 phi_s0;

    for (phi_s0 = 0; phi_s0 < D_807F6938; phi_s0++) {
        func_806355DC(D_807F6240[D_807F6918[phi_s0]], 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641B00.s")

/*
// TODO: Doable, just need to figure out object model2 behaviour pointer struct
void func_80641B00(s16 arg0, s16 arg1, s16 arg2) {
    s32 sp1C;

    arg0 = func_80659470(arg0);
    arg1 = func_80659470(arg1);
    D_807F6000[arg0].unk7C = malloc(0xA4);
    func_8063DED0(D_807F6000[arg0].unk7C, &D_807F6000);
    D_807F6000[arg0].unk7C->unk48 = arg2;
    D_807F6000[arg0].unk7C->unkA0 = D_807F6000[arg1].unk7C->unkA0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641DA0.s")

typedef struct {
    u8 pad0[0x94 - 0x0];
    Actor *unk94;
} GlobalASMStruct44;

s32 func_80678014(s32);
Actor *func_807270C0(s16, s32); // getSpawnerTiedActor()
extern f32 D_807F621C; // X
extern f32 D_807F6220; // Y
extern f32 D_807F6224; // Z
extern f32 D_807F622C; // Y Rotation
extern s16 D_807F693C;
extern u8 D_807F693F;

/*
// TODO: Pretty close, datatytpe issues?
void func_80641DA0(GlobalASMStruct44 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 phi_v1;

    if ((arg0->unk94 == 0) && ((func_80678014(0x14)))) {
        arg0->unk94 = D_807FBB44;
        D_807FBB44->noclip_byte = 1;
        D_807FBB44->x_position = D_807F621C;
        D_807FBB44->y_position = D_807F6220;
        D_807FBB44->z_position = D_807F6224;
        D_807FBB44->y_rotation = (D_807F622C * 4096.0f) / 360.0f;
        if (D_807F693F != 0) {
            D_807FBB44->unk15E = arg3;
        }
        if (D_807F693F != 0) {
            phi_v1 = 4;
        } else {
            phi_v1 = 0;
        }
        switch (arg2) {
            case 0:
                playCutscene(arg0->unk94, arg1, (phi_v1 | 1 | D_807F693C) & 0xFF);
                return;
            case 1:
                playCutscene(NULL, arg1, (phi_v1 | 1 | D_807F693C) & 0xFF);
                return;
            case 2:
                playCutscene(func_807270C0(arg3, 0x400), arg1, (phi_v1 | 1 | D_807F693C) & 0xFF);
                break;
        }
    }
}
*/

void func_80641F68(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80641F70.s")

u8 func_8064216C(s16 cap, f32 x, f32 y, f32 z) {
    f32 dx = D_807F621C - x;
    f32 dy = D_807F6220 - y;
    f32 dz = D_807F6224 - z;
    dx *= dx;
    dy *= dy;
    dz *= dz;
    return sqrtf(dx + dy + dz) < cap;
}

s32 func_80642204(s16 arg0) {
    u8 playerIndex;
    for (playerIndex = 0; playerIndex < D_80750AB4; playerIndex++) {
        if ((character_change_array[playerIndex].does_player_exist)
            && (func_8064216C(arg0,
                              character_change_array[playerIndex].player_pointer->x_position,
                              character_change_array[playerIndex].player_pointer->y_position,
                              character_change_array[playerIndex].player_pointer->z_position))) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_806422D8(s16 arg0) {
    u8 playerIndex;
    for (playerIndex = 0; playerIndex < D_80750AB4; playerIndex++) {
        if ((character_change_array[playerIndex].does_player_exist)
            && (func_8064216C(arg0,
                              character_change_array[playerIndex].look_at_eye_x,
                              character_change_array[playerIndex].look_at_eye_y,
                              character_change_array[playerIndex].look_at_eye_z))) {
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806423A8.s")

s32 func_80667110(f32, f32, f32 *);
extern f32 D_807F621C;
extern f32 D_807F6220;
extern f32 D_807F6224;
extern f32 D_807F6238;

void func_80642480(s16 arg0, s32 arg1) {
    s32 temp; // TODO: Why is this needed?
    f32 sp20;

    switch (arg0) {
        case 0:
            sp20 = D_807F6220;
            if (func_80667110(D_807F621C, D_807F6224, &sp20)) {
                D_807F6220 = sp20 + D_807F6238;
            }
        case 1:
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642500.s")

extern f64 D_80758918;

/*
// TODO: Pretty close
s32 func_80642500(f32 *arg0, u8 arg1, s16 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_t5;
    f32 phi_f12;
    s32 phi_v1;

    phi_v1 = 0;
    temp_f0 = arg0[arg1];
    switch (arg1) {
        default:
            return 0;
        case 0:
            temp_f2 = arg2 / 10.0f;
            if (temp_f2 < temp_f0) {
                phi_f12 = temp_f0 - temp_f2;
            } else {
                phi_f12 = temp_f2 - temp_f0;
            }
            if (phi_f12 < D_80758918) {
                return 1;
            }
            break;
        case 1:
            if ((arg2 / 10.0f) < temp_f0) {
                return 1;
            }
            break;
        case 2:
            if (temp_f0 < (arg2 / 10.0f)) {
                phi_v1 = 1;
            }
            break;
    }
    return phi_v1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806425FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642940.s")

void func_80642BF0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_80714B84(&D_8071FF18, 0.3f, arg1, 1, 0);
    func_80714B84(&D_8071FF18, 0.3f, arg1, 2, 0);
    func_80714B84(&D_8071FF18, 0.3f, arg1, 3, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80642FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80643274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80643354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80643440.s")

void func_806436A4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    func_80643354(0, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806436E0.s")

void func_8064384C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    ObjectModel2 *temp_v1 = &D_807F6000[func_80659470(arg1)];

    func_8067DF44(temp_v1->x_position, temp_v1->y_position, temp_v1->z_position, temp_v1->hitbox_scale, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806438B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80643B24.s")

void func_80714950(s32);
void func_8071498C(void*);
void func_80714998(s32);
void func_807149B8(s32);
void func_807149C8(s32, s32, s32, s32);
extern s32 D_80717D4C;

/*
// TODO: Close, minor stack issue
void func_80643B24(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 temp = &D_80717D4C;
    if ((object_timer % 5U) == 0) {
        func_80714950(-0x78);
        func_8071498C(temp);
        func_807149B8(1);
        func_80714998(3);
        func_807149C8(0xFF, 0xFF, 0xFF, 0x96);
        func_80714B84(&D_8071FFA0, 1.0f, arg1, 1, 0);
        func_80714950(-0x78);
        func_8071498C(temp);
        func_807149B8(1);
        func_80714998(3);
        func_807149C8(0xFF, 0xFF, 0xFF, 0x96);
        func_80714B84(&D_8071FFA0, 1.0f, arg1, 2, 0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80643C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80643F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064409C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064431C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806443E4.s")

void func_806449C0(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_80714998(2);
    func_807149B8(1);
    func_80714B84(&D_8071FBC8, 1.5f, arg1, arg2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80644A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80644CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80644D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80644E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80644EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806450C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80645238.s")

void func_80645614(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u32 sp24;

    if (((func_806119A0() / 10000U) % arg2) == 0) {
        sp24 = (func_806119A0() / 10000U) % arg3;
        func_80714998(2);
        func_80714950(0x10064);
        func_8071498C(&D_8071AADC);
        func_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
        func_807149B8(1);
        func_80714B84(&D_80720A7C, 0.5f, arg1, sp24 + 1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80645700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806458C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80645A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80645B9C.s")

void func_80645C04(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    s32 sp44;

    func_806335B0(arg1, 1, 1, &sp4C, &sp48, &sp44);
    func_80659610(2500);
    func_80659600(9);
    func_806595F0(2);
    func_8065A708(sp4C, sp48, sp44, 0.0f, 0.0f, 0.0f, 600.0f, 0, 0xFF, 0xFF, 0xFF);
    func_80659610(2500);
    func_80659600(0xA);
    func_806595F0(2);
    func_8065A708(sp4C, sp48, sp44, 0.0f, 0.0f, 0.0f, 600.0f, 0, 0xFF, 0xFF, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80645D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80645F40.s")

/*
extern s32 D_8071EB70;
extern f64 D_807589E8;
extern f64 D_807589F0;
extern s32 D_80720B00;

// TODO: Very close, doable
void func_80645F40(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 phi_f22 = 0.0f;

    if ((object_timer & 0xF) == 0) {
        f64 temp_f26 = D_807589E8;
        f64 temp_f24 = D_807589F0;
        f64 temp;
        void* test = &D_80720B00;
        for (i = 1; i < 0xB; i++) {
            func_807149B8(1);
            func_80714998(2);
            func_8071498C(&D_8071EB70);
            func_80714950(700);
            func_807149A8(700);
            func_80714B84(test, phi_f22 + temp_f24, arg1, i, 1);
            phi_f22 += temp_f26;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80646058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80646770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80646978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80646DC4.s")

void func_80647108(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_80714950(-0x78);
    func_8071498C(&D_80717D4C);
    func_807149B8(1);
    func_80714998(3);
    func_80714B84(&D_8071FFA0, 1.5f, arg1, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647218.s")

void func_80647508(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp34;
    f32 sp30, sp2C, sp28;

    sp34 = ((func_806119A0() / 1000U) % 10) + 1;
    func_80714950(-0x28A - ((func_806119A0() / 1000U) % 200));
    func_8071498C(&D_80717D4C);
    func_807149B8(1);
    func_80714998(9);
    func_807149C8(0xFF, 0xFF, 0xFF, 0x64);
    func_80714944(5);
    func_806335B0(arg1, 1, sp34, &sp30, &sp2C, &sp28);
    func_80714CC0(&D_8071FFA0, 1.5f, sp30, sp2C - 70, sp28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064774C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647B74.s")

void func_80647CF4(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_80714998(2);
    if (arg2 != 0) {
        func_80714CC0(&D_8071FBC8, 3.0, D_807F621C, D_807F6220, D_807F6224);
        return;
    }
    func_80714B84(&D_8071FBC8, 3.0, arg1, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80647D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80648000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064826C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806485A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806487C4.s")

int func_80648C50() {
    s16 chunk = character_change_array[0].chunk;
    switch(chunk) {
        case 4:
        case 0xC:
            return 1;
        default:
            return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80648C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064911C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806491F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806493C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064954C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_806496B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80649BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80649D74.s")

typedef struct {
    u8  pad0[0x14];
    f32 unk14;
    u8  pad1[0x31];
    u8 unk49;
} GlobalASMStruct49;

void func_80649E00(GlobalASMStruct49 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk14 = arg0->unk49;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80649E34.s")

void func_80649F64(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    // TODO: Might actually use unk88 which gets read as unk8A because of the explicit s16 in the function signature
    // We'll see what looks more logical when the fields shake out down the line
    func_806418E8(0x5F, D_807F6000[func_80659470(arg1)].unk8A, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_80649FC0.s")

void func_8064A180(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064A194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064A258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064A804.s")

// Something to do with caves ice tomato board
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064AAC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064AB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064AC28.s")

void func_8002D6F8(s16);

void func_8064B118(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_8002D6F8(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B260.s")

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} GlobalASMStruct54;

/*
// TODO: Wrong register order t8 a0
void func_8064B260(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    GlobalASMStruct54 *temp_v0;

    temp_v0 = arg0 + (arg2 * 4);
    temp_v0->unk14 = player_pointer->unk100;
    temp_v0->unk18 = player_pointer->unk104;
    temp_v0->unk1C = player_pointer->unk108;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B2AC.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} GlobalASMStruct86;

void func_8064B370(GlobalASMStruct86 **arg0, s32 arg1, s32 arg2, s32 arg3) {
    GlobalASMStruct86* temp_v0 = *arg0;
    D_807F621C = temp_v0->unk0;
    D_807F6220 = temp_v0->unk4;
    D_807F6224 = temp_v0->unk8;
    D_807F6228 = temp_v0->unkC;
    D_807F622C = temp_v0->unk10;
    D_807F6230 = temp_v0->unk14;
    D_807F6234 = temp_v0->unk18;
    D_807F6234 = temp_v0->unk1C;
    D_807F6234 = temp_v0->unk20;
    D_807F6238 = temp_v0->unk24;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B514.s")

/*
void func_806FAC64(u8);
void func_806F8D58(s32, s32);
void func_806F8BC4(s32, u8, s32);

// TODO: Regalloc, using t6 instead of t8
void func_8064B514(u8 arg0, u8 arg1, u8 arg2, s16 arg3) {
    func_806FAC64(arg2);
    if (arg3) {
        func_806F8D58(0xD, 0);
    } else {
        func_806F8BC4(0xD, 1, 0); 
    }
}
*/

void func_8064B574(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80726EE0(3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B5A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B798.s")

/*
// TODO: Regalloc (t7 t8 t9)
void func_8064B798(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
    PlayerAdditionalActorData *temp_v0 = character_change_array[0].player_pointer->PaaD;
    temp_v0->unk1FC = arg2;
}
*/

void func_8064B7C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_8064B7D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_8064B7E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_806612B4(5, 1);
    func_806612B4(6, 1);
}

void func_8064B828(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8066134C(5, 0xFF);
    func_8066134C(6, 0xFF);
}

void func_8064B868(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 temp_a2 = func_80661300(5);
    func_8066134C(5, temp_a2 < 0xFC ? temp_a2 + 3 : 0xFF);
    func_8066134C(6, temp_a2 < 0xFC ? temp_a2 + 3 : 0xFF);
    func_806612B4(5, 0);
    func_806612B4(6, 0);
}

void func_8064B900(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    Actor *temp_v0;
    Actor *temp_v0_2;

    if (arg2 != 0) {
        if (arg2 != 1) {
            if (arg2 == 2) {
                func_807271F4(8, 0, 0, 0, 0, 0, 0);
                D_807FBB44->object_properties_bitfield &= -5;
            }
        } else {
            temp_v0 = func_807270C0(8, 0);
            if (temp_v0) {
                temp_v0->object_properties_bitfield |= 4;
                func_80614EBC(temp_v0, 0x35C);
                func_80614D00(temp_v0, 0.9f, 0);
            }
        }
    } else {
        temp_v0_2 = func_807270C0(8, 0);
        if (temp_v0_2) {
            temp_v0_2->control_state = 0x3C;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064B9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064BAF4.s")

// TODO: This probably returns the result of func_805FF0C8, if not, this is cursed
void func_8064BB4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_805FF0C8();
}

// This function checks whether the key has been turned in for the map stored at D_8076A0AB
s32 func_8064BB78(s32 arg0, s32 arg1, s32 levelIndex, s32 arg3) {
    levelIndex = getLevelIndex(D_8076A0AB, FALSE);
    if (levelIndex >= 8) {
        levelIndex = 0;
    }
    return isFlagSet(D_80744710[levelIndex], FLAG_TYPE_PERMANENT);
}

// Seems doable, but very odd float/s16 nonsense in params
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064BBD8.s")

s32 func_8064BCB0(s32 arg0, s32 arg1) {
    Actor *player;
    s32 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (character_change_array[playerIndex].does_player_exist) {
            player = character_change_array[playerIndex].player_pointer;
            if ((player->locked_to_pad == 1) && (arg0 == player->unk10C) && (arg1 == player->unk10E)) {
                return playerIndex;
            }
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064BD2C.s")

u8 func_8064BE58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return D_807552E8 == 5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064BE80.s")

s32 func_8064BF58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f64 dz, dx;

    dz = character_change_array[0].look_at_eye_z - D_80758AA8;
    dx = character_change_array[0].look_at_eye_x - D_80758AB0;
    if (((dz * dz) + (dx * dx)) < D_80758AB8) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064BFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064C9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064CB3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064CC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064CD3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064D0C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064D1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064D418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064D880.s")

extern u16 D_807446C0[];
extern u16 D_807FC930[];

void func_80650AD8(s16, s32, s32, f32);

/*
// TODO: Float regalloc
void func_8064D880(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 phi_f0;
    f32 temp;
    f32 temp2;
    s32 levelIndex;

    levelIndex = getLevelIndex(D_8076A0AB, FALSE);
    temp = D_807FC930[levelIndex];
    temp2 = D_807446C0[levelIndex];
    phi_f0 = temp / temp2;
    if (phi_f0 > 1.0) {
        phi_f0 = 1.0f;
    }
    if (arg2 == 0) {
        phi_f0 = 1.0f - phi_f0;
    }
    func_80650AD8(arg1, 1, 0, phi_f0);
    func_80650A04(arg1, 1, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064D978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064DB98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064DE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064DF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E4F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E55C.s")

/*
extern s32 D_807482EC;

void func_8064E55C(s16 arg1, s16 arg2, s32 arg3) {
    s32 sp2C = D_807482EC;
    func_8064E174(arg1, arg2, &sp2C, 3, 7, 0x14);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E5C0.s")

/*
// TODO: Which struct is arg0?
void func_8064E5C0(void *arg0, ? arg1, ? arg2, ? arg3) {
    s16 sp26;

    sp26 = arg0->unk62;
    arg0->unk66 = 0xFF;
    arg0->unk60 = 1;
    if (((rand() >> 0xF) % 100) >= 0x29) {
        arg0->unk62 = 0;
    } else {
        arg0->unk62 = 0xFF;
    }
    if (sp26 != arg0->unk62) {
        playSound(0x8A, 0xBB8, 63.0f, 1.0f, 0x1E, 0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064E65C.s")

void func_8064EA48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_806F8AD4(1, 0) >= 2) {
        func_806F8BC4(1, 0, 0);
        func_806F91B4(1, 0, -2);
        // DK Arcade Level 3?
        setFlag(0x83, TRUE, FLAG_TYPE_PERMANENT);
    }
}

typedef struct global_asm_struct_7 {
    u8 unk0[0x4B];
    s8 unk4B;
} GlobalASMStruct7;

void func_8064EAB4(GlobalASMStruct7 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 numberOfGunSwitchesPressed;

    // Fungi Mushroom Gun Switches Pressed
    // Odd that they didn't use func_80731AA8() countSetFlags() for this
    numberOfGunSwitchesPressed = isFlagSet(0xE6, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xE8, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xE9, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xE7, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xEA, FLAG_TYPE_PERMANENT);

    arg0->unk4B = numberOfGunSwitchesPressed;
}

s32 func_8064EB3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // DK Arcade GB Collected
    if (!isFlagSet(0x82, FLAG_TYPE_PERMANENT)) {
        return 1;
    }
    // DK Arcade Level 3?
    if (isFlagSet(0x83, FLAG_TYPE_PERMANENT)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064EB9C.s")

extern u8 D_807446F0[];

/*
// TODO: Regalloc
u8 func_8064EB9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 levelIndex = getLevelIndex(D_8076A0AB, FALSE);
    if (levelIndex >= 8) {
        levelIndex = 0;
    }
    return D_807446F0[levelIndex] == current_character_index[0];
}
*/

// Doable, but tricky, maybe array lookup
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064EC04.s")

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064EC60.s")

/*
// TODO: Pretty close
u8 func_8064EC60(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u8 sp1B;
    s32 temp_v0;
    s32 kongIndex;
    u8 phi_t0;

    phi_t0 = 0;
    switch (arg2) {
        default:
            kongIndex = 4;
            if (arg2 != 6) {
                kongIndex = 0;
            }
            break;
        case 3:
            kongIndex = 1;
            break;
        case 4:
            kongIndex = 2;
            break;
        case 5:
            kongIndex = 3;
            break;
    }
    temp_v0 = func_80600530();
    if ((D_807FC950->character_progress[kongIndex].unk5 & 0x7F) == temp_v0) {
        phi_t0 = TRUE;
        if (arg3 == 0) {
            phi_t0 = TRUE;
            if ((D_807FC950->character_progress[kongIndex].unk5 & 0x80)) {
                phi_t0 = FALSE;
            }
        }
    } else if (temp_v0 < (D_807FC950->character_progress[kongIndex].unk5 & 0x7F)) {
        phi_t0 = TRUE;
    }
    if (phi_t0 == TRUE) {
        if (arg3 == 2) {
            D_807FC950->character_progress[kongIndex].unk5 = (D_807FC950->character_progress[kongIndex].unk5 & 0x7F);
        }
    }
    return phi_t0;
}
*/

s32 func_8064ED68(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 phi_s0;
    s32 phi_s3;

    phi_s3 = FALSE;
    for (phi_s0 = 2; phi_s0 < 7; phi_s0++) {
        if (!func_8064EC60(arg0, arg1, phi_s0, 1)) {
            phi_s3 = TRUE;
        }
    }
    return phi_s3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064EE08.s")

void func_8064F028(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    func_807149C8(0xFF, 0xFF, 0xFF, 0x80);
    func_8071498C(&func_8064EE08);
    func_807149FC(-1);
    func_807149B8(1);
    func_80714998(2);
    func_80714CC0(&D_80721530, 0, D_807F621C, D_807F6220 + D_80758BD8, D_807F6224);
    func_80677FA8(0x9C, 0x53); // Spawn actor: Wrinkly
    D_807FBB44->x_position = D_807F621C;
    D_807FBB44->y_position = D_807F6220;
    D_807FBB44->z_position = D_807F6224;
    D_807FBB44->y_rotation = (D_807F622C * 4096.0f) / 360.0f;
    if ((current_map == MAP_FUNGI_LOBBY) || ((current_map == MAP_AZTEC_LOBBY) && (arg2 == 4))) {
        // BUG(?): This angle addition does not truncate to 4096
        D_807FBB44->y_rotation += 0x800;
    }
    playCutscene(D_807FBB44, 0x22, 5);
    playSong(0xAB, 1.0f);
    playSound(0x2EA, 0x7FFF, 63.0f, 1.0f, 0, 0);
    D_807F6951 = arg2;
    D_807F6950 = 0;
}

extern s8 D_807F6950;
extern s8 D_807FC8D0;

u8 func_8064F1C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_807F6950) {
        func_80602B60(0xAB, 0);
    }
    return D_807F6950;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064F210.s")

/*
f32 func_80612794(s16);
extern f32 D_807F621C;
extern f32 D_807F6224;
extern f32 D_807F622C;

s32 func_8064F210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp2C;
    f32 temp_f0;
    s32 temp_f18;
    u8 phi_v0;

    temp_f18 = (D_807F622C * 4096.0f) / 360.0f;
    sp2C = func_80612794(temp_f18);
    temp_f0 = func_80612790(temp_f18);
    phi_v0 = FALSE;
    if (((player_pointer->x_position * sp2C) + (temp_f0 * player_pointer->z_position) + -((D_807F621C * sp2C) + (D_807F6224 * temp_f0))) > 6.0) {
        phi_v0 = TRUE;
    }
    return phi_v0;
}
*/

s32 func_8064F2F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 1;
}

void func_8064F308(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 flagIndex;

    if (D_807FC8D0 == 5) {
        flagIndex = 0x1C1; // Key 6 turned
    } else {
        flagIndex = 0x1C2; // Key 7 turned
    }
    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_8064F358.s")

u8 func_8064F404(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // Has the player collected 4 or more Battle Crowns?
    return func_80731AA8(0x261, 10, FLAG_TYPE_PERMANENT) >= 4;
}
