#include <ultra64.h>
#include "functions.h"

typedef struct CutsceneBank_unk0 {
    u8 pad0[4];
    void *unk4;
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
    s16 *point_array;
    s16 *length_array;
} CutsceneBank_CamBank;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s32 unk18;
} CutsceneBank_LockRegion;

typedef struct CutsceneBank {
    CutsceneBank_unk0 unk0[24];
    s16 lock_count;
    u8 padC2[2];
    CutsceneBank_LockRegion *lock_regions;
    u8 *lock_chunks;
    s16 cutscene_count;
    u8 padCE[2];
    CutsceneBank_CamBank *camera_bank;
    u8 unkD4[4];
    CutsceneBank_FuncBank *function_bank;
    f32 unkDC;
} CutsceneBank;

void func_global_asm_80622B24(Actor *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, void *);

extern OSTime D_807F5CE0;
extern f32 D_global_asm_807574E0;
extern u8 D_global_asm_8076A0B1;
extern u8 D_global_asm_8076A0B3;
extern Actor *D_807F5CE8;
extern s16 D_807F5CEC;
extern u16 D_807F5CF0;
extern u16 D_807F5CF4;
extern f32 D_807F5CFC;
extern f32 D_807F5D00;
extern s16 D_807F5D04;
extern s16 D_807F5D06;
extern s16 D_807F5D08;
extern s16 D_807F5D0A;
extern s16 D_global_asm_807476F4;
extern CutsceneBank *D_global_asm_807476FC;
extern u16 D_807F5CF4;
extern s16 D_global_asm_807476F8;
extern Actor *D_global_asm_807F5D10;
extern u8 D_global_asm_807476EC;
extern CutsceneBank D_807F5B10[2];
extern s16 D_807F5CEE;
extern s16 D_807F5CF2;
extern u8 D_807F5CF6;
extern s8 D_807F5CFA;
extern Actor *D_807F5D0C;
extern s8 D_807F5D14;
extern OSTime D_global_asm_807476D0;
extern u8 D_global_asm_807476D8;
extern s16 D_global_asm_807476E4;
extern s16 D_global_asm_807476F0;
extern u8 D_global_asm_80770DC9;
extern f32 loading_zone_transition_speed;
extern s8 loading_zone_transition_type;
extern f32 D_global_asm_807576E0;
extern s16 D_global_asm_807476DC;
extern s16 D_global_asm_807476E0;
extern s16 D_global_asm_807476E8;

u8 func_global_asm_8061B4B0(void) {
    return D_807F5CE0 != 0;
}

// doable, 64 bit maths, timestamp
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B4E4.s")

void func_global_asm_8061B5C4(s16 playerIndex) {
    character_change_array[playerIndex].unk2D0 = character_change_array[playerIndex].unk2C4;
    character_change_array[playerIndex].unk2E9 = 0x18;
}

typedef struct {
    Actor *unk0;
    u8 unk4[0xF3 - 0x4];
    u8 unkF3;
} AAD_8061B610;

void func_global_asm_8061B610(Actor *arg0) {
    AAD_8061B610 *aaD;

    aaD = arg0->additional_actor_data;
    arg0->x_position = aaD->unk0->x_position;
    arg0->y_position = aaD->unk0->y_position + 170.0f;
    arg0->z_position = aaD->unk0->z_position;
    aaD->unkF3 = 7;
}

typedef struct {
    u8 unk0[0xF3 - 0x0];
    u8 unkF3;
} AAD_8061B650;

void func_global_asm_8061B650(Actor *arg0) {
    AAD_8061B650 *aaD = arg0->additional_actor_data;
    aaD->unkF3 = 9;
}

typedef struct {
    u8 unk0[0xB2 - 0x0];
    s16 unkB2;
} Struct8061B660;

void func_global_asm_8061B660(Struct8061B660 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    *arg1 += arg4 * func_global_asm_80612794(object_timer * arg6) * func_global_asm_80612794(arg0->unkB2 + 0x400);
    *arg3 += arg4 * func_global_asm_80612794(object_timer * arg6) * func_global_asm_80612790(arg0->unkB2 + 0x400);
    *arg2 += arg5 * func_global_asm_80612794(object_timer * arg7);
}

typedef struct {
    u8 unk0[0x90 - 0x0];
    f32 unk90;
    u8 unk94[0xFA - 0x94];
    s8 unkFA;
} Struct8061B7E0;

void func_global_asm_8061B7E0(Actor *arg0, Struct8061B7E0 *arg1, f32 x, f32 z) {
    f32 y;

    y = 99999.0f;
    arg1->unkFA = 0;
    func_global_asm_8066635C(arg0, x, y, z, &y);
    arg1->unkFA = func_global_asm_8066715C(&arg1->unk90);
}

typedef struct {
    u8 unk0[0xF7 - 0x0];
    u8 unkF7;
} Struct8061B840;

void func_global_asm_8061B840(Struct8061B840 *arg0, s8 arg1) {
    arg0->unkF7 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B9B0.s")

typedef struct {
    u8 unk0[0xC - 0x0];
    f32 unkC;
    u8 unk10[0xA8 - 0x10];
    f32 unkA8;
    s32 unkAC;
    u8 unkB0[0xFB - 0xB0];
    u8 unkFB;
} AAD_8061C0FC;

void func_global_asm_8061C0FC(AAD_8061C0FC *arg0) {
    character_change_array[arg0->unkFB].unk2C4 = func_global_asm_80665E48(
        character_change_array[arg0->unkFB].look_at_eye_x,
        character_change_array[arg0->unkFB].look_at_eye_z,
        character_change_array[arg0->unkFB].look_at_at_x,
        character_change_array[arg0->unkFB].look_at_at_z
    );
    arg0->unkA8 = character_change_array[arg0->unkFB].unk2C4;
    switch (is_autowalking) {
        case 0:
            character_change_array[arg0->unkFB].unk2C8 = (arg0->unkA8 * 4096.0) / 6.28318548202514648;
            break;
        case 2:
            func_global_asm_8060B55C(&character_change_array[arg0->unkFB].unk2C8);
            break;
        case 3:
            character_change_array[arg0->unkFB].unk2C8 = (arg0->unkA8 * 4096.0) / 6.28318548202514648;
            break;
    }
    if (character_change_array[arg0->unkFB].unk2E9) {
        character_change_array[arg0->unkFB].unk2E9--;
    }
}

void func_global_asm_8061C2C4(Actor *arg0, s32 arg1) {
    s32 temp;
    temp = arg0->CaaD->unkAC | arg1;
    arg0->CaaD->unkAC = temp;
}

void func_global_asm_8061C2D8(Actor *camera, s32 arg1) {
    CameraPaad *aaD;

    aaD = camera->CaaD;
    aaD->unkAC &= ~arg1;
}

void func_global_asm_8061C2F0(Actor *camera, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7) {
    CameraPaad *aaD;

    aaD = camera->CaaD;
    if ((is_cutscene_active == 1) && (arg7 != 0)) {
        func_global_asm_8061D4E4(camera);
    }
    if ((is_cutscene_active != 1) || (arg7 != 0)) {
        aaD->unkAC |= 0x80000000;
    }
    aaD->unk20 = arg1;
    aaD->unk24 = arg2;
    aaD->unk28 = arg3;
    aaD->unk2C = arg4;
    aaD->unk30 = arg5;
    aaD->unk34 = arg6;
}

void func_global_asm_8061C39C(Actor *camera) {
    CameraPaad *aaD;

    aaD = camera->CaaD;
    character_change_array[aaD->unkFB].look_at_eye_x = aaD->unk20;
    character_change_array[aaD->unkFB].look_at_eye_y = aaD->unk24;
    character_change_array[aaD->unkFB].look_at_eye_z = aaD->unk28;
    character_change_array[aaD->unkFB].look_at_at_x = aaD->unk2C;
    character_change_array[aaD->unkFB].look_at_at_y = aaD->unk30;
    character_change_array[aaD->unkFB].look_at_at_z = aaD->unk34;
}

void func_global_asm_8061C458(Actor *camera, s32 arg1) {
    CameraPaad *aaD;

    aaD = camera->CaaD;
    aaD->unk48 = arg1;
}

typedef struct {
    Actor *unk0;
    Actor *unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    // s16 unk16 padding, appears to be unused
    f32 unk18;
} AAD_8061C464_unk44;

typedef struct {
    s32 *unk0;
    u8 unk4[0x44 - 0x4];
    AAD_8061C464_unk44 unk44; // This is really weird, the function below uses a pointer to the substruct
    u8 unk48[0xF3 - 0x60];
    u8 unkF3;
    u8 unkF4[0xFB - 0xF4];
    u8 unkFB;
} AAD_8061C464;

void func_global_asm_8061C464(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA) {
    AAD_8061C464 *aaD;
    AAD_8061C464_unk44 *aaD44;

    aaD = ((AAD_8061C464*)arg0->additional_actor_data);
    aaD44 = &aaD->unk44;
    if (arg1) {
        aaD44->unk0 = arg1;
        aaD44->unk4 = arg1;
        aaD44->unk8 = arg3;
        aaD44->unkA = arg4;
        aaD44->unkC = arg5;
        aaD44->unkE = arg6;
        aaD44->unk10 = arg7;
        aaD44->unk12 = arg8;
        aaD44->unk14 = arg9;
        aaD44->unk18 = argA;
        if (aaD->unkF3 == 3) {
            func_global_asm_806EAB44(player_pointer, 0);
        }
        aaD->unkF3 = arg2;
    } else {
        func_global_asm_806224CC(arg0, aaD->unk0);
    }
}

void func_global_asm_8061C518(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA) {
    f32 sp3C;

    sp3C = arg1->animation_state->scale[1];
    if (is_cutscene_active == 1) {
        func_global_asm_8061D4E4(arg0);
    }
    D_global_asm_8076A0B3 = 0;
    D_global_asm_8076A0B1 |= 0x10;
    arg1->animation_state->scale[1] = 0.15f;
    func_global_asm_8061C6A8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA);
    arg1->animation_state->scale[1] = sp3C;
    global_properties_bitfield &= ~1;
}

void func_global_asm_8061C600(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA) {
    if (is_cutscene_active == 1) {
        func_global_asm_8061D4E4(arg0);
    }
    D_global_asm_8076A0B3 = 0;
    D_global_asm_8076A0B1 |= 0x10;
    func_global_asm_8061C464(
        arg0,
        arg1,
        arg2,
        arg3,
        arg4,
        arg5,
        arg6,
        arg7,
        arg8,
        arg9,
        argA
    );
}

// doable, close, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C6A8.s")

/*
void func_global_asm_8061C6A8(Actor *arg0, Actor *arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 arg10) {
    f32 scale;
    AAD_8061C464_unk44 *aaD44;
    AAD_8061C464 *aaD;

    aaD = arg0->additional_actor_data;
    if (arg1 != NULL) {
        aaD44 = &aaD->unk44;
        aaD44->unk0 = arg1;
        aaD44->unk4 = arg1;
        scale = arg1->animation_state->scale_y / 0.149999999999999994;
        aaD44->unk8 = arg3;
        aaD44->unkA = arg4 * scale;
        aaD44->unkC = arg5;
        aaD44->unkE = arg6 * scale;
        aaD44->unk10 = arg7 * scale;
        aaD44->unk12 = arg8 * scale;
        aaD44->unk14 = arg9;
        aaD44->unk18 = arg10;
        if (aaD->unkF3 == 3) {
            func_global_asm_806EAB44(player_pointer, 0);
        }
        aaD->unkF3 = arg2;
        global_properties_bitfield |= 0x2000;
        func_global_asm_8061B5C4(aaD->unkFB);
    } else {
        func_global_asm_806224CC(arg0, aaD->unk0);
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C804.s")

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

void func_global_asm_8061CAD8(void) {
    if (!(D_807F5CF4 & 2)) {
        D_807F5CF4 |= 0x40;
    } else {
        D_807F5CF4 &= 0xFFFD;
    }
}

void func_global_asm_8061CB08(void) {
    if (D_807F5CF4 & 0x40) {
        D_807F5CF4 &= 0xFFBF;
    } else {
        D_807F5CF4 |= 2;
    }
}

u8 func_global_asm_8061CB38(void) {
    return (D_807F5CF4 & 0x40) != 0;
}

u8 func_global_asm_8061CB50(void) {
    return (is_cutscene_active == 1) || (D_global_asm_8076A0B1 & 0x10);
}

u8 func_global_asm_8061CB80(void) {
    return (D_807F5CF4 & 4) != 0;
}

u8 func_global_asm_8061CB98(u8 arg0) {
    return (is_cutscene_active == 1) && (arg0 == D_global_asm_807476F8);
}

void func_global_asm_8061CBCC(void) {
    D_global_asm_807476F4 = D_global_asm_807476F8;
    D_807F5CF0 = 0;
    func_global_asm_8061D898();
}

u8 func_global_asm_8061CC00(void) {
    if (D_global_asm_807F5D10->CaaD);
    return (D_global_asm_807F5D10->CaaD->unkF3 == 3) || (D_global_asm_807F5D10->CaaD->unkF3 == 0xB);
}

void func_global_asm_8061CC30(void) {
    D_global_asm_807476EC = 1;
}

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/playCutscene.s")

/*
s32 playCutscene(Actor *arg0, s16 arg1, u8 arg2) {
    u16 sp26;
    s32 is_global;

    sp26 = 0;
    if ((is_cutscene_active == 1) && (D_807F5CF4 & 0x80)) {
        return 0;
    }
    is_global = arg2 & 4;
    if ((is_global) && (current_map != MAP_TEST_MAP)) {
        D_global_asm_807476FC = &D_807F5B10[1];
    } else {
        D_global_asm_807476FC = &D_807F5B10[0];
    }
    if (spawnActor(ACTOR_CUTSCENE_CONTROLLER, 0)) {
        D_807F5D0C = last_spawned_actor;
        last_spawned_actor->noclip_byte = 1;
        if ((!is_global) && (D_global_asm_807FBB64 & 1)) {
            func_boss_80029140(&arg1);
        }
        if (arg0 != NULL) {
            D_807F5CE8 = arg0;
        } else {
            D_807F5CE8 = character_change_array->player_pointer;
        }
        is_cutscene_active = 1;
        if (!(arg2 & 8)) {
            D_global_asm_8076A0B1 |= 0x10;
            D_global_asm_8076A0B3 = 0;
        }
        D_global_asm_807476D0 = osGetTime();
        D_global_asm_807476F4 = arg1;
        D_global_asm_807476F8 = arg1;
        D_807F5CF4 = arg2;
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
            func_global_asm_806119F0(0x8E32B6F7U);
            D_807F5CE0 = osGetTime();
            D_807F5D14 = 0;
        } else if (!isIntroStoryPlaying()) {
            D_807F5CE0 = 0;
        }
    }
    return sp26;
}
*/

void func_global_asm_8061CF24(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    if (D_807F5CF4 & 0x20) {
        *arg0 = D_807F5D04;
        *arg1 = D_807F5D06;
        *arg2 = D_807F5D08;
        *arg3 = D_807F5D0A;
        D_807F5CF4 &= 0xFFDF;
    }
}

void func_global_asm_8061CF80(s16 arg0) {
    D_807F5CEE = arg0;
}

void func_global_asm_8061CF90(Actor *arg0, s16 arg1) {
    if (arg0 != NULL) {
        D_807F5CE8 = arg0;
    } else {
        D_807F5CE8 = character_change_array->player_pointer;
    }
    D_807F5CFA = arg1;
}

typedef struct {
    Actor *unk0;
    Actor *unk4;
    u8 unk8[0xAC - 0x8];
    s32 unkAC;
} AAD_8061CFCC;

void func_global_asm_8061CFCC(Actor *arg0) {
    AAD_8061CFCC *aaD;

    aaD = D_global_asm_807F5D10->additional_actor_data;
    if (arg0 == D_807F5CE8) {
        func_global_asm_8061CF90(NULL, 0);
    }
    if (arg0 == aaD->unk4) {
        aaD->unk4 = NULL;
        aaD->unkAC &= 0xFFFEFFFB;
    }
    if (arg0 == aaD->unk0) {
        aaD->unk0 = player_pointer;
    }
}

void func_global_asm_8061D058(void) {
    
}

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D060.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D1FC.s")

// close, doable, 64 bit?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D4E4.s")

extern OSTime D_global_asm_807476C8; // TODO: Not 100% on datatype
extern s32 D_global_asm_8076A068;

typedef struct {
    u8 unk0[0xC - 0x0];
    f32 unkC;
    u8 unk[0xAC - 0x10];
    s32 unkAC;
    u8 unkB0[0xFB - 0xB0];
    u8 unkFB;
} AAD_8061D4E4;

/*
void func_global_asm_8061D4E4(Actor *arg0) {
    AAD_8061D4E4 *aaD;

    aaD = arg0->additional_actor_data;
    if (is_cutscene_active == 1) {
        if (D_807F5CF4 & 4) {
            D_global_asm_807476FC = &D_807F5B10;
        }
        func_global_asm_80602488(0);
        is_cutscene_active = 0;
        D_global_asm_8076A0B1 &= 0xFFEF;
        if (!(D_807F5CF4 & 8)) {
            D_global_asm_8076A0B3 = 0xFF;
        }
        deleteActor(D_807F5D0C);
        global_properties_bitfield |= 0x1000;
        aaD->unkAC |= 0x40000;
        aaD->unkC = -32768.0f;
        if (D_807F5CF4 & 1) {
            global_properties_bitfield |= 0x2000;
            func_global_asm_8061B5C4(aaD->unkFB);
        }
        character_change_array[aaD->unkFB].fov_y = 45.0f;
        arg0->x_rotation = 0;
        D_global_asm_80770DC9 = D_807F5CF6;
        D_global_asm_8076A068 += 0x1869F;
        func_global_asm_80600C68();
        D_global_asm_8076A068 += 0xFFFE7961;
        D_807F5CF4 = 0;
        // TODO: Issue here
        D_global_asm_807476C8 = 0;
        player_pointer->object_properties_bitfield &= ~0x400;
    }
}
*/

// rodata, Actor* arg0
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D6A8.s")

void func_global_asm_8061D898(void) {
    D_807F5D0C->unk168 = 0;
    D_807F5D0C->unk160 = 0.0;
    D_807F5CF2 = D_global_asm_807476FC->camera_bank[D_global_asm_807476F4].point_array[D_807F5CF0];
    D_807F5CEC = D_global_asm_807476FC->camera_bank[D_global_asm_807476F4].length_array[D_807F5CF0];
    func_global_asm_806F3DB0();
}

void func_global_asm_8061D934(u8 arg0) {
    D_global_asm_807476F4 = arg0;
    D_807F5CF0 = 0;
    func_global_asm_8061D898();
}

extern u16 D_807F5CF8;

void func_global_asm_8061D968(u8 arg0, u8 arg1) {
    if (D_global_asm_807476D8) {
        if (--D_global_asm_807476D8) {
            D_807F5CF0 = D_807F5CF8;
            func_global_asm_8061D898();
        }
    } else {
        D_global_asm_807476D8 = arg1;
        D_807F5CF8 = arg0;
        D_807F5CF0 = arg0;
        func_global_asm_8061D898();
    }
}

void func_global_asm_8061D9EC(s32 arg0, s32 arg1, s32 arg2) {
    loading_zone_transition_type = 0;
    loading_zone_transition_speed = -0.8f;
}

void func_global_asm_8061DA14(s32 arg0, s32 arg1, s32 arg2) {
    D_global_asm_8076A0B1 |= 0x40;
    loading_zone_transition_type = 0;
    loading_zone_transition_speed = 0.8f;
    func_global_asm_8060098C(&func_global_asm_8061D9EC, 0x8000003C, 0, 0, 0);
}

void func_global_asm_8061DA84(s32 arg0, s32 arg1, s32 arg2) {
    func_global_asm_8061CB08();
}

void func_global_asm_8061DAAC(s16 arg0, s16 arg1, u16 arg2) {
    D_global_asm_807476E4 = arg2;
    D_global_asm_807476E8 = arg2;
    D_global_asm_807476DC = (arg0 << 0xC) / 360;
    D_global_asm_807476E0 = (arg1 << 0xC) / 360;
}

s32 func_global_asm_80620628(Actor*, f32, s32, s32);

typedef struct {
    Actor *unk0;
    u8 unk4[0xAC - 0x4];
    s32 unkAC;
    u8 unkB0[0xF3 - 0xB0];
    u8 unkF3;
    u8 unkF4;
    u8 unkF5;
    u8 unkF6;
} AAD_8061DB64;

void func_global_asm_8061DB64(Actor *arg0) {
    AAD_8061DB64 *aaD;

    aaD = arg0->additional_actor_data;
    func_global_asm_80620628(arg0, -1.0f, aaD->unk0->y_rotation, 0);
    aaD->unkF5 = 0xF;
    aaD->unkF6 = 0xF;
    global_properties_bitfield &= ~0x2000;
    aaD->unkAC &= 0xFFEFFFFF;
}

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DBD4.s")

s32 func_global_asm_8061EB04(Actor *playerPointer, u8 playerIndex);

void func_global_asm_8061EA78(void) {
    u8 playerIndex;
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        if (character_change_array[playerIndex].does_player_exist) {
            func_global_asm_8061EB04(character_change_array[playerIndex].player_pointer, playerIndex);
        }
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EB04.s")

typedef struct {
    u8 unk0[0xC0 - 0x0];
    s32 unkC0;
    u8 unkC4[0xF2 - 0xC4];
    u8 unkF2;
} Struct8061EDA0;

void func_global_asm_8061EDA0(Struct8061EDA0 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, s32 arg4, u8 arg5) {
    s32 random;
    s32 temp_v1;

    random = rand();
    if (arg4 == 0) {
        arg4 = 1;
    }
    temp_v1 = arg4 >> 1;
    *arg1 = *arg1 + (((random % arg4) - temp_v1) * 0.01);
    *arg2 = *arg2 + ((((random / 100) % arg4) - temp_v1) * 0.01);
    *arg3 = *arg3 + ((((random / 10000) % arg4) - temp_v1) * 0.01);
    if (arg5 != 0) {
        arg0->unkF2 = arg0->unkF2 - 1;
        arg0->unkC0 = arg0->unkC0 - (arg0->unkC0 * 0.111);
        arg0->unkC0 = arg0->unkC0 + 1;
    }
}

void func_global_asm_8061EF4C(Actor *arg0, u8 arg1, u16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 dX;
    f32 d;
    f32 dZ;
    f32 dY;

    dX = arg3 - arg0->x_position;
    dY = arg4 - arg0->y_position;
    dZ = arg5 - arg0->z_position;
    d = sqrtf((dX * dX) + (dY * dY) + (dZ * dZ));
    if (!(arg7 < d)) {
        if (d < arg6) {
            func_global_asm_8061F0B0(arg0, arg1, arg2);
        } else {
            func_global_asm_8061F0B0(arg0, arg1, (arg2 * ((arg7 - d) / (arg7 - arg6))));
        }
    }
}

typedef struct {
    u8 unk0[0xC0 - 0x0];
    s32 unkC0;
    u8 unkC4[0xF2 - 0xC4];
    u8 unkF2;
    u8 unkF3[0xFB - 0xF3];
    u8 unkFB;
} AAD_8061F0B0;

void func_global_asm_8061F0B0(Actor *arg0, u8 arg1, u16 arg2) {
    AAD_8061F0B0 *aaD;

    aaD = arg0->additional_actor_data;
    if (is_cutscene_active == 1) {
        arg2 >>= 2;
    }
    if (aaD->unkF2 <= arg1) {
        aaD->unkF2 = arg1;
    }
    if (aaD->unkC0 <= arg2 * 100) {
        aaD->unkC0 = arg2 * 100;
    }
    func_global_asm_8060E7EC(aaD->unkFB, MIN(0xFF, arg2 * 9), arg1 + 1);
}

typedef struct {
    u8 unk0[0xE8 - 0x0];
    s16 unkE8;
    s16 unkEA;
} AAD_8061F164;

void func_global_asm_8061F164(AAD_8061F164 *aaD, s16 arg1) {
    if (arg1 >= 0xB) {
        aaD->unkE8 = arg1;
        aaD->unkEA = aaD->unkE8;
    }
}

typedef struct {
    Actor *unk0;
} AAD_8061F18C;

void func_global_asm_8061F18C(Actor *arg0, f32 arg1, f32 arg2, f32 arg3) {
    AAD_8061F18C *aaD;
    s16 sp2A;
    s16 pad;
    s16 sp26;
    f32 d;

    aaD = arg0->additional_actor_data;
    sp2A = func_global_asm_80665DE0(aaD->unk0->x_position, aaD->unk0->z_position, arg1, arg3);
    sp26 = func_global_asm_806CC14C(sp2A, func_global_asm_80665DE0(aaD->unk0->x_position, aaD->unk0->z_position, arg0->unk88, arg0->unk90));
    d = sqrtf(((arg1 - arg0->unk88) * (arg1 - arg0->unk88)) + ((arg2 - arg0->unk8C) * (arg2 - arg0->unk8C)) + ((arg3 - arg0->unk90) * (arg3 - arg0->unk90)));
    func_global_asm_8061F164(aaD, d * MAX(1.0, sp26 * 0.0009765625));
}

void func_global_asm_8061F2B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 *arg9, f32 *argA, f32 *argB) {
    f32 d2;
    f32 d3;
    f32 d;
    f32 temp_f2_3;

    d =   ((arg3 - arg6) * (arg3 - arg6))
        + ((arg4 - arg7) * (arg4 - arg7))
        + ((arg5 - arg8) * (arg5 - arg8));
    if (d == 0.0f) {
        *arg9 = arg3;
        *argA = arg4;
        *argB = arg5;
        return;
    }
    d2 =  ((arg6 - arg0) * (arg6 - arg0))
        + ((arg7 - arg1) * (arg7 - arg1))
        + ((arg8 - arg2) * (arg8 - arg2));
    d3 =  ((arg3 - arg0) * (arg3 - arg0))
        + ((arg4 - arg1) * (arg4 - arg1))
        + ((arg5 - arg2) * (arg5 - arg2));
    temp_f2_3 = ((d3 + d) - d2) / (2 * d);
    if ((temp_f2_3 >= 1.0f) || (d2 == 0.0f)) {
        *arg9 = arg6;
        *argA = arg7;
        *argB = arg8;
    } else if ((temp_f2_3 <= 0.0f) || (d3 == 0.0f)) {
        *arg9 = arg3;
        *argA = arg4;
        *argB = arg5;
    } else {
        *arg9 = (temp_f2_3 * (arg6 - arg3)) + arg3;
        *argA = (temp_f2_3 * (arg7 - arg4)) + arg4;
        *argB = (temp_f2_3 * (arg8 - arg5)) + arg5;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F4B0.s")

// regalloc, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F510.s")

/*
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;
} Struct807F5BD4;

extern Struct807F5BD4 *D_807F5BD4;

void func_global_asm_8061F510(u8 arg0, s8 arg1) {
    D_807F5BD4[arg0].unk18 = arg1;
}
*/

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F53C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620628.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80621174.s")

// jumptable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062133C.s")

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80621E9C.s")

typedef struct {
    u8 unk0[0x9E - 0x0];
    s16 unk9E;
} Struct8062210C;

void func_global_asm_8062210C(Struct8062210C *arg0, f32 *arg1, s32 arg2, f32 *arg3, f32 arg4) {
    func_global_asm_80621E9C(arg0, arg1, arg2);
    *arg1 += arg4 * func_global_asm_80612794(arg0->unk9E);
    *arg3 += arg4 * func_global_asm_80612790(arg0->unk9E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062217C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80622334.s")

typedef struct {
    u8 unk0[0xC - 0x0];
    f32 unkC;
    u8 unk10[0x44 - 0x10];
    s32 unk44;
    u8 unk48[0xB0 - 0x48];
    s16 unkB0;
    s16 unkB2;
    u8 unkB4[0xED - 0xB4];
    u8 unkED;
    u8 unkEE[0xF3 - 0xEE];
    u8 unkF3;
} AAD_806224CC;

void func_global_asm_806224CC(Actor *arg0, Actor *arg1) {
    AAD_806224CC *aaD;
    s32 pad2;
    s32 pad3;
    u8 pad;
    u8 oldF3Value;

    aaD = arg0->additional_actor_data;
    oldF3Value = aaD->unkF3;
    if (current_player->unk6E[0] != -1) {
        func_global_asm_80605314(current_player, 0);
    }
    aaD->unk44 = 0;
    aaD->unkB0 = 0;
    aaD->unkF3 = 1;
    aaD->unkC = -32768.0f;
    // TODO: Sort this out, possibly a switch case or an else if situation
    if (oldF3Value != 2) {
        if ((oldF3Value == 3) || (oldF3Value == 0xB)) {
            func_global_asm_8061F164(aaD, 0xA);
            aaD->unkB2 = arg1->y_rotation;
            return;
        }
        goto block_10;
    }
    if ((aaD->unkED == 8) && (func_global_asm_806CC14C(aaD->unkB2, arg1->y_rotation) < 0x400)) {
        func_global_asm_8061DB64(arg0);
    }
    aaD->unkED = 0xFF;
block_10:
    func_global_asm_8061F164(aaD, 0x14);
}

typedef struct {
    u8 unk0[0x44 - 0x0];
    s32 unk44;
    u8 unk48[0xF3 - 0x48];
    u8 unkF3;
} AAD_806225C0;

void func_global_asm_806225C0(Actor *arg0) {
    AAD_806225C0 *aaD;

    aaD = arg0->additional_actor_data;
    aaD->unk44 = 0;
    aaD->unkF3 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806225D4.s")

typedef struct {
    Actor *unk0;
    Actor *unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0xAC - 0x16];
    s32 unkAC;
    s16 unkB0;
    s16 unkB2;
} AAD_806228BC;

typedef struct {
    u8 unk0[0x44 - 0x0];
    AAD_806228BC unk44; // TODO: Is this the right struct?
} Struct806227F0_arg0;

void func_global_asm_806227F0(Struct806227F0_arg0 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    AAD_806228BC *aaD = &arg0->unk44;
    s16 angle;

    angle = (aaD->unk0->y_rotation + aaD->unkC) & 0xFFF;
    *arg1 = (func_global_asm_80612794(angle) * aaD->unkE) + aaD->unk4->x_position;
    *arg3 = (func_global_asm_80612790(angle) * aaD->unkE) + aaD->unk4->z_position;
    *arg2 = aaD->unk4->y_position + aaD->unk12;
}

void func_global_asm_806228BC(Actor *actor, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    AAD_806228BC *aaD;
    Actor *aaDActor;
    s16 temp_v0_5;
    s32 var_v1;

    aaD = actor->additional_actor_data;
    aaDActor = aaD->unk0;
    *arg1 = aaDActor->x_position;
    if ((aaDActor->control_state == 3) || (aaDActor->control_state == 5)) {
        *arg2 = MAX(0xF, aaDActor->unk15E) + aaDActor->y_position;
    } else if (current_map == MAP_FUNGI) {
        *arg2 = MAX(0x16, aaDActor->unk15E) + aaDActor->y_position;
    } else {
        *arg2 = MAX(0xA, aaDActor->unk15E) + aaDActor->y_position;
    }
    *arg3 = aaDActor->z_position;
    if (aaDActor->unkFC != 0) {
        temp_v0_5 = func_global_asm_80672A70(aaDActor->unkF4, aaDActor->unkF6);
        *arg1 += (5.0 * func_global_asm_80612794(temp_v0_5));
        *arg3 += (5.0 * func_global_asm_80612790(temp_v0_5));
    }
    *arg4 = aaDActor->x_position - (func_global_asm_80612794(aaD->unkB2) * 50.0f);
    *arg5 = aaDActor->y_position - (actor->distance_from_floor - 138.0f);
    *arg6 = aaDActor->z_position - (func_global_asm_80612790(aaD->unkB2) * 50.0f);
}

f32 func_global_asm_80622ABC(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;

    temp_f0 = arg0 - arg1;
    if (3.141592741f < temp_f0) {
        arg1 += 6.283185482f;
    } else if (temp_f0 < -3.141592741f) {
        arg0 += 6.283185482f;
    }
    return ((arg1 - arg0) * arg2) + arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80622B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80624978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80624CA4.s")

f32 func_global_asm_806252CC(f32 arg0, f32 arg1, f32 arg2) {
    if (arg0 < arg1) {
        arg0 = arg0 + arg2;
        if (arg1 < arg0) {
            arg0 = arg1;
        }
    } else {
        arg0 = arg0 - arg2;
        if (arg0 < arg1) {
            arg0 = arg1;
        }
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806256D0.s")

extern f32 D_global_asm_807476A4;

typedef struct {
    u8 unk0[0x78 - 0x0];
    f32 unk78;
    f32 unk7C;
    f32 unk80;
} AAD_80625994;

void func_global_asm_80625994(Actor *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    AAD_80625994 *aaD;

    aaD = arg0->additional_actor_data;
    *arg2 = *arg2 + ((aaD->unk78 - *arg2) * D_global_asm_807476A4);
    *arg3 = *arg3 + ((aaD->unk7C - *arg3) * arg1);
    *arg4 = *arg4 + ((aaD->unk80 - *arg4) * D_global_asm_807476A4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806259FC.s")

extern s16 D_807F5CD2;
extern s16 D_807F5CD4;
extern s16 D_807F5CD8;

s16 func_global_asm_80625A80(s32 lockRegionIndex) {
    CutsceneBank_LockRegion *lockRegion;

    lockRegion = &D_global_asm_807476FC->lock_regions[lockRegionIndex];
    return ((lockRegion->unk10 - D_807F5CD2) / 400) + (((lockRegion->unk14 - D_807F5CD4) / 400) * D_807F5CD8);
}

void func_global_asm_80625B3C(s16 *arg0, s16 *arg1, s16 *arg2) {
    s16 i;

    *arg0 = 0x7FFF;
    *arg2 = 0x7FFF;
    *arg1 = -0x8000;
    for (i = 0; i < D_global_asm_807476FC->lock_count; i++) {
        if (D_global_asm_807476FC->lock_regions[i].unk10 < *arg0) {
            *arg0 = D_global_asm_807476FC->lock_regions[i].unk10;
        }
        if (*arg1 < D_global_asm_807476FC->lock_regions[i].unk10) {
            *arg1 = D_global_asm_807476FC->lock_regions[i].unk10;
        }
        if (D_global_asm_807476FC->lock_regions[i].unk14 < *arg2) {
            *arg2 = D_global_asm_807476FC->lock_regions[i].unk14;
        }
    }
    *arg0 -= 200;
    *arg1 += 200;
    *arg2 -= 200;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625C30.s")

typedef struct {
    Actor *unk0;
    Actor *unk4;
    u8 unk8[0x12 - 0x8];
    s16 unk12;
    s16 unk14;
    u8 unk16[0xAC - 0x16];
    s32 unkAC;
    s16 unkB0;
    s16 unkB2;
} AAD_80626110;

void func_global_asm_80626110(Actor *arg0, s16 arg1, s16 arg2) {
    AAD_80626110 *aaD;

    aaD = arg0->additional_actor_data;
    aaD->unk4 = getSpawnerTiedActor(1, 0);
    if (aaD->unk4 != NULL) {
        aaD->unkB2 = func_global_asm_80665DE0(aaD->unk4->x_position, aaD->unk4->z_position, aaD->unk0->x_position, aaD->unk0->z_position);
    } else {
        aaD->unkB2 = aaD->unk0->y_rotation;
    }
    if (arg1 != 0) {
        aaD->unk12 = arg1;
        aaD->unk14 = arg2;
        aaD->unkB2 = func_global_asm_80665DE0(arg1, arg2, aaD->unk0->x_position, aaD->unk0->z_position);
    }
    aaD->unkAC |= 0x10004;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0xAC - 0x8];
    s32 unkAC;
} AAD_806261CC;

void func_global_asm_806261CC(Actor *arg0) {
    AAD_806261CC *aaD;

    aaD = arg0->additional_actor_data;
    aaD->unk4 = 0;
    aaD->unkAC &= 0xFFFEFFFB;
}

s32 func_global_asm_806264DC(s32, void*, u8);

typedef struct {
    u8 unk0[0x3C1 - 0x0];
    u8 unk3C1;
    u8 unk3C2[0x3D5 - 0x3C2];
    u8 unk3D5;
    u8 unk3D6[0x3E9 - 0x3D6];
    u8 unk3E9;
    u8 unk3EA[0x3FD - 0x3EA];
    u8 unk3FD;
    u8 unk3FE[0x411 - 0x3FE];
    u8 unk411;
    u8 unk412[0x425 - 0x412];
    u8 unk425;
} Struct806261EC_arg1_unkD8;

typedef struct {
    u8 unk0[0xD8 - 0x0];
    Struct806261EC_arg1_unkD8 *unkD8;
} Struct806261EC_arg1;

void func_global_asm_806261EC(s32 arg0, Struct806261EC_arg1 *arg1, u8 arg2) {
    func_global_asm_806264DC(arg0, arg1, arg2);
    arg1->unkD8->unk3C1 = 0xE;
    arg1->unkD8->unk3D5 = 0xB;
    arg1->unkD8->unk3E9 = 6;
    arg1->unkD8->unk3FD = 0x11;
    arg1->unkD8->unk411 = 7;
    arg1->unkD8->unk425 = 8;
}

// jumptable, rodata, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626264.s")

void func_global_asm_80625C30();
extern f32 D_807F5CCC;
extern s8 D_global_asm_807476B4;
extern s16 D_global_asm_807476B8;
extern s16 D_global_asm_807476BC;
extern s32 D_global_asm_807476C0;
extern Struct806261EC_arg1 *D_global_asm_80747700;
extern s32 D_global_asm_80747704;

/*
void func_global_asm_80626264(s32 arg0) {
    void *sp1C;

    sp1C = getPointerTableFile(8, 0, 1, 1);
    func_global_asm_80627B58(0.5f);
    D_global_asm_807476FC = D_807F5B10;
    D_807F5CF4 = 0;
    D_global_asm_807476C0 = 0;
    D_global_asm_80747704 = 0;
    func_global_asm_806261EC(arg0, D_global_asm_807476FC, 1);
    func_global_asm_806261EC(sp1C, D_global_asm_80747700, 0);
    func_global_asm_8066B434(sp1C, 0x10B4, 0xC);
    func_global_asm_80625C30();
    D_global_asm_807476B4 = 0;
    D_global_asm_807476B8 = 0;
    D_global_asm_807476BC = 0;
    D_807F5CCC = 6.0f;
    if (D_global_asm_807FBB64 & 1) {
        D_807F5CCC = 12.0f;
    }
    switch (current_map) {
        case MAP_BUSY_BARREL_BARRAGE_EASY:
        case MAP_BUSY_BARREL_BARRAGE_NORMAL:
        case MAP_BUSY_BARREL_BARRAGE_HARD:
            D_global_asm_807476B4 = 0x1E;
            break;
        case MAP_JAPES_BARREL_BLAST:
        case MAP_AZTEC_BARREL_BLAST:
            D_global_asm_807476B8 = 0x1F4;
            break;
        case MAP_GALLEON_BARREL_BLAST:
            D_global_asm_807476B8 = 0xFA;
            break;
        case MAP_FACTORY_BARREL_BLAST:
            D_global_asm_807476B8 = 0x226;
            break;
        case MAP_CAVES_BARREL_BLAST:
            D_global_asm_807476B8 = 0xFA;
            break;
        case MAP_CASTLE_BARREL_BLAST:
        case MAP_FUNGI_BARREL_BLAST:
            D_global_asm_807476B8 = 0x12C;
            break;
        case MAP_GALLEON_SEAL_RACE:
            D_807F5CCC = 10.0f;
            break;
        case MAP_GALLEON_MERMAID:
            D_global_asm_807476BC = 0x78;
            break;
    }
    // TODO: Issue with these writes
    D_global_asm_807476C8 = 0;
    D_global_asm_807476D0 = 0;
}
*/

// doable, weird negative offsets
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626478.s")

// memcpy concat, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806264DC.s")

// 64 bit maths
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626F8C.s")

// stack, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627388.s")

/*
void func_global_asm_80627388(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg8) {
    f32 sp18[4][4];
    guMtxL2F(sp18, arg0);
    *arg5 = ((sp18[0][0] * arg1) + (sp18[1][0] * arg2) + (sp18[2][0] * arg3)) + sp18[3][0];
    *arg6 = ((sp18[0][1] * arg1) + (sp18[1][1] * arg2) + (sp18[2][1] * arg3)) + sp18[3][1];
    *arg7 = ((sp18[0][2] * arg1) + (sp18[1][2] * arg2) + (sp18[2][2] * arg3)) + sp18[3][2];
    *arg8 = ((sp18[0][3] * arg1) + (sp18[1][3] * arg2) + (sp18[2][3] * arg3)) + sp18[3][3];
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627490.s")

void func_global_asm_8062754C(f32 arg0) {
    s16 playerIndex;

    func_global_asm_8061F2B8(
        character_change_array->look_at_at_x,
        character_change_array->look_at_at_y,
        character_change_array->look_at_at_z,
        517.0f,
        312.0f,
        346.0f,
        347.0f,
        312.0f,
        494.0f,
        &character_change_array->look_at_eye_x,
        &character_change_array->look_at_eye_y,
        &character_change_array->look_at_eye_z
    );
    playerIndex = 0;
    character_change_array->look_at_eye_x = ((character_change_array->look_at_eye_x - character_change_array->look_at_at_x) * arg0) + character_change_array->look_at_at_x;
    character_change_array->look_at_eye_y = ((character_change_array->look_at_eye_y - character_change_array->look_at_at_y) * arg0) + character_change_array->look_at_at_y;
    character_change_array->look_at_eye_z = ((character_change_array->look_at_eye_z - character_change_array->look_at_at_z) * arg0) + character_change_array->look_at_at_z;
    while (++playerIndex < cc_number_of_players) {
        character_change_array[playerIndex].look_at_eye_x = character_change_array->look_at_eye_x;
        character_change_array[playerIndex].look_at_eye_y = character_change_array->look_at_eye_y;
        character_change_array[playerIndex].look_at_eye_z = character_change_array->look_at_eye_z;
    }
}

f32 func_global_asm_806276AC(void) {
    s16 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        character_change_array[playerIndex].look_at_at_x = 586.0f;
        character_change_array[playerIndex].look_at_at_y = 205.0f;
        character_change_array[playerIndex].look_at_at_z = 584.0f;
    }
    return 1.0f;
}

typedef struct {
    Actor *unk0;
    u8 unk4[0x78 - 0x4];
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    u8 unk84[0x94 - 0x84];
    f32 unk94;
    u8 unk98[0xA0 - 0x98];
    f32 unkA0;
    u8 unkA4[0xB2 - 0xA4];
    s16 unkB2;
    s16 unkB4;
    u8 unkB6[0xB8 - 0xB6];
    f32 unkB8;
    u8 unkBC[0xF0 - 0xBC];
    u8 unkF0;
    u8 unkF1;
    u8 unkF2;
    u8 unkF3;
    u8 unkF4[0xFB - 0xF4];
    u8 unkFB;
} AAD_8062773C;

s16 func_global_asm_8062773C(Actor *arg0) {
    AAD_8062773C *aaD;
    s16 sp22;

    aaD = arg0->additional_actor_data;
    sp22 = aaD->unkB2 + 0x800;
    if (aaD->unkF0 != 0) {
        func_global_asm_8062217C(arg0, aaD->unkF0);
    } else {
        func_global_asm_8062217C(arg0, 1);
    }
    arg0->distance_from_floor = aaD->unkB8;
    aaD->unkF1 = 0xB;
    aaD->unkF3 = 1;
    func_global_asm_80627888(arg0);
    aaD->unk94 = aaD->unkA0 / 3.0;
    character_change_array[aaD->unkFB].fov_y = 45.0f;
    aaD->unk78 = aaD->unk0->x_position;
    aaD->unk7C = aaD->unk0->y_position + aaD->unk0->unk15E;
    aaD->unk80 = aaD->unk0->z_position;
    func_global_asm_8061B840(aaD, 0xB);
    func_global_asm_80605314(aaD->unk0, 0);
    aaD->unk0->unk6A &= 0xDFFF;
    return sp22;
}

typedef struct {
    u8 unk0[0xB2 - 0x0];
    s16 unkB2;
    s16 unkB4;
} AAD_80627878;

void func_global_asm_80627878(Actor *arg0) {
    AAD_80627878 *aaD;

    aaD = arg0->additional_actor_data;
    aaD->unkB4 = aaD->unkB2;
}

typedef struct {
    u8 unk0[0xB2 - 0x0];
    s16 unkB2;
    s16 unkB4;
} AAD_80627888;

void func_global_asm_80627888(Actor *arg0) {
    AAD_80627888 *aaD;

    aaD = arg0->additional_actor_data;
    aaD->unkB2 = aaD->unkB4;
    arg0->unk15F = (aaD->unkB2 / 4095.0) * 255.0;
}

s32 func_global_asm_80671E00(f32, f32, f32, f32, s16*, s16*, s32, s32);

void func_global_asm_80627948(Actor *arg0, u8 arg1, u8 arg2, u8 arg3) {
    s16 sp2E;
    s16 sp2C;

    if (func_global_asm_80671E00(arg0->x_position, arg0->y_position, arg0->z_position, 80.0f, &sp2E, &sp2C, 1, 0xBC)) {
        arg0->y_rotation = func_global_asm_80665DE0(character_change_array->look_at_eye_x, character_change_array->look_at_eye_z, arg0->x_position, arg0->z_position);
        playCutscene(arg0, arg2, arg3);
    } else {
        playCutscene(arg0, arg1, arg3);
    }
}
