#include <ultra64.h>
#include "functions.h"


#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C0FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C2D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C39C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C518.s")

extern u8 D_global_asm_8076A0B1;
extern s8 D_global_asm_8076A0B3;

void func_global_asm_8061C600(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA) {
    if (is_cutscene_active == 1) {
        func_global_asm_8061D4E4(arg0);
    }
    D_global_asm_8076A0B3 = 0;
    D_global_asm_8076A0B1 |= 0x10;
    func_global_asm_8061C464(arg0, arg1, (s32) arg2, (s32) arg3, (s32) arg4, (s32) arg5, (s32) arg6, (s32) arg7, (s32) arg8, (s32) arg9, argA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C804.s")

typedef struct CutsceneBank_unk0 {
    u8 pad0[4];
    void* unk4;
} CutsceneBank_unk0;

typedef struct CutsceneBank_FuncBank {
    u8 unk0;
    u8 command;
    u8 unk2;
    u8 unk3;
    s32 params[3];
    u8 pad10[4];
} CutsceneBank_FuncBank;

typedef struct CutsceneBank_CamBank {
    s16 point_count;
    s16 unk2;
    s16 * point_array;
    s16 * length_array;
} CutsceneBank_CamBank;

typedef struct CutsceneBank {
    CutsceneBank_unk0 unk0[24];
    s16 lock_count;
    u8 padC2[2];
    void * lock_regions;
    u8 * lock_chunks;
    s16 cutscene_count;
    u8 padCE[2];
    CutsceneBank_CamBank * camera_bank;
    u8 unkD4[4];
    CutsceneBank_FuncBank * function_bank;
    f32 unkDC;
} CutsceneBank;

void func_global_asm_8061D898(void);
void func_global_asm_80622B24(Actor *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, void *); /* extern */
extern Actor *D_807F5CE8;
extern s16 D_807F5CEC;
extern s16 D_807F5CF0;
extern u16 D_807F5CF4;
extern f32 D_807F5CFC;
extern f32 D_807F5D00;
extern s16 D_807F5D04;
extern s16 D_807F5D06;
extern s16 D_807F5D08;
extern s16 D_807F5D0A;
extern s16 D_global_asm_807476F4;
extern CutsceneBank *D_global_asm_807476FC;

/*
s16 func_global_asm_8061C804(s16 arg0) {
    s16 spA6;
    u8 spA0;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s16 temp_s1;
    s16 point_count;
    s16 i;
    s32 var_s4;
    CutsceneBank_CamBank * var_a2;
    s32 var_s6;
    CutsceneBank_FuncBank *temp_a0;
    CutsceneBank_CamBank *cam_bank;

    spA6 = 0;
    var_s6 = 0;
    var_s4 = arg0;
    var_a2 = D_global_asm_807476FC->camera_bank;
    do {
        spA0 = 0;
        point_count = D_global_asm_807476FC->camera_bank[var_s4].point_count;
        for (i = 0; i < point_count; i++) {
            cam_bank = &var_a2[var_s4];
            temp_a0 = &D_global_asm_807476FC->function_bank[cam_bank->point_array[i]];
            switch (temp_a0->command) {
            case 6:
            case 14:
                break;
            case 13:
                if ((temp_a0->params[0] & 0xFF) == 8) {
                    spA0 = 1;
                    var_s4 = temp_a0->params[1] >> 0x10;
                }
                break;
            default:
                if (!var_s6) {
                    temp_s1 = D_807F5CE8->unk168;
                    var_s6 = 1;
                    sp94 = character_change_array->look_at_eye_x;
                    sp90 = character_change_array->look_at_eye_y;
                    sp8C = character_change_array->look_at_eye_z;
                    sp88 = character_change_array->look_at_at_x;
                    sp84 = character_change_array->look_at_at_y;
                    D_807F5CFC = 1.0f;
                    D_807F5D00 = 0.0f;
                    D_global_asm_807476F4 = var_s4;
                    D_807F5CF0 = i;
                    sp80 = character_change_array->look_at_at_z;
                    func_global_asm_8061D898();
                    func_global_asm_80622B24(D_global_asm_807F5D10, &sp94, &sp90, &sp8C, &sp88, &sp84, &sp80, D_807F5CE8);
                    D_807F5CF0 = 0;
                    D_global_asm_807476F4 = arg0;
                    D_807F5D04 = sp94;
                    D_807F5D06 = sp90;
                    D_807F5D08 = sp8C;
                    D_807F5D0A = func_global_asm_80665DE0(sp88, sp80, sp94, sp8C);
                    D_807F5CF4 |= 0x20;
                    D_807F5CEC = 0;
                    D_807F5CE8->unk168 = temp_s1;
                    cam_bank = &var_a2[var_s4];
                }
                spA6 += cam_bank[1].point_count;
                break;
            }
        }
    } while (spA0 != 0);
    return spA6;
}
*/

extern u16 D_807F5CF4;

void func_global_asm_8061CAD8(void) {
    if (!(D_807F5CF4 & 2)) {
        D_807F5CF4 |= 0x40;
        return;
    }
    D_807F5CF4 &= 0xFFFD;
}

extern u16 D_807F5CF4;

void func_global_asm_8061CB08(void) {
    if (D_807F5CF4 & 0x40) {
        D_807F5CF4 &= 0xFFBF;
        return;
    }
    D_807F5CF4 |= 2;
}

extern u16 D_807F5CF4;

u8 func_global_asm_8061CB38(void) {
    return (D_807F5CF4 & 0x40) != 0;
}

u8 func_global_asm_8061CB50(void) {
    return (is_cutscene_active == 1) || (D_global_asm_8076A0B1 & 0x10);
}

extern u16 D_807F5CF4;

u8 func_global_asm_8061CB80(void) {
    return (D_807F5CF4 & 4) != 0;
}

extern s16 D_global_asm_807476F8;

u8 func_global_asm_8061CB98(u8 arg0) {
    return (is_cutscene_active == 1) && (arg0 == D_global_asm_807476F8);
}

void func_global_asm_8061D898(void);
extern s16 D_807F5CF0;
extern s16 D_global_asm_807476F4;
extern s16 D_global_asm_807476F8;

void func_global_asm_8061CBCC(void) {
    D_global_asm_807476F4 = D_global_asm_807476F8;
    D_807F5CF0 = 0;
    func_global_asm_8061D898();
}

extern Actor * D_global_asm_807F5D10;

u8 func_global_asm_8061CC00(void) {
    if (D_global_asm_807F5D10->CaaD);
    return (D_global_asm_807F5D10->CaaD->unkF3 == 3) || (D_global_asm_807F5D10->CaaD->unkF3 == 0xB);
}

extern u8 D_global_asm_807476EC;

void func_global_asm_8061CC30(void) {
    D_global_asm_807476EC = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/playCutscene.s")



void func_global_asm_806119F0(u32);
extern CutsceneBank D_807F5B10[2];
extern OSTime D_807F5CE0;
extern Actor *D_807F5CE8;
extern s16 D_807F5CEC;
extern s16 D_807F5CEE;
extern s16 D_807F5CF0;
extern s16 D_807F5CF2;
extern u16 D_807F5CF4;
extern u8 D_807F5CF6;
extern s8 D_807F5CFA;
extern Actor *D_807F5D0C;
extern s8 D_807F5D14;
extern OSTime D_global_asm_807476D0;
extern s8 D_global_asm_807476D8;
extern s16 D_global_asm_807476E4;
extern s16 D_global_asm_807476F0;
extern s16 D_global_asm_807476F4;
extern s16 D_global_asm_807476F8;
extern u8 D_global_asm_8076A0B1;
extern s8 D_global_asm_8076A0B3;
extern u8 D_global_asm_80770DC9;

/*
s32 playCutscene(Actor *arg0, s16 arg1, s32 arg2) {
    u16 sp26;
    s32 is_global;
    s32 temp_a2;

    sp26 = 0;
    if ((is_cutscene_active == 1) && (D_807F5CF4 & 0x80)) {
        return 0;
    }
    is_global = (u8) arg2 & 4;
    temp_a2 = (u8) arg2;
    if ((is_global != 0) && (current_map != MAP_TEST_MAP)) {
        D_global_asm_807476FC = &D_807F5B10[1];
    } else {
        D_global_asm_807476FC = &D_807F5B10[0];
    }
    if (spawnActor(ACTOR_CUTSCENE_CONTROLLER, 0) != 0) {
        D_807F5D0C = last_spawned_actor;
        last_spawned_actor->noclip_byte = 1;
        if ((is_global == 0) && (D_global_asm_807FBB64 & 1)) {
            func_boss_80029140(&arg1);
        }
        if (arg0 != NULL) {
            D_807F5CE8 = arg0;
        } else {
            D_807F5CE8 = character_change_array->player_pointer;
        }
        is_cutscene_active = 1;
        if (!(temp_a2 & 8)) {
            D_global_asm_8076A0B1 |= 0x10;
            D_global_asm_8076A0B3 = 0;
        }
        D_global_asm_807476D0 = osGetTime();
        D_global_asm_807476F4 = arg1;
        D_global_asm_807476F8 = arg1;
        D_807F5CF4 = (u8) arg2;
        D_807F5CFA = 0;
        D_global_asm_807476D8 = 0;
        D_global_asm_807476E4 = 0;
        D_807F5CEC = 0;
        D_807F5CF0 = 0;
        D_807F5CF2 = 0;
        D_807F5CEE = 0;
        D_global_asm_807476F0 = 0;
        D_807F5CF6 = D_global_asm_80770DC9;
        global_properties_bitfield |= 0x2000;
        global_properties_bitfield &= ~0x1001;
        player_pointer->unkB8 = 0.0f;
        if (*current_character_index == 7) {
            player_pointer->y_velocity = 0.0f;
        }
        player_pointer->object_properties_bitfield |= 0x400;
        extra_player_info_pointer->unk10 = 0;
        D_global_asm_807F5D10->x_rotation = 0;
        func_global_asm_80629174();
        if (D_global_asm_807476EC != 0) {
            sp26 = func_global_asm_8061C804(arg1);
        }
        D_global_asm_807476EC = 0;
        if ((arg1 == 0) && (current_map == MAP_DK_ISLES_DK_THEATRE)) {
            func_global_asm_806119F0(0x8E32B6F7);
            D_807F5CE0 = osGetTime();
            D_807F5D14 = 0;
        } else if (isIntroStoryPlaying() == 0) {
            D_807F5CE0 = 0;
        }
        return sp26;
    }
    return 0;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061CF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061CF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061CF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061CFCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D9EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DA84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80621174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062133C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80621E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062210C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062217C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80622334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806224CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806225C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806225D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806227F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806228BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80622ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80622B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80624978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80624CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806252CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806256D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806259FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806261CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806261EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806264DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062754C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806276AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062773C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627948.s")
