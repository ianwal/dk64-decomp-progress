#include <ultra64.h>
#include "functions.h"

extern OSTime D_807F5CE0;

u8 func_global_asm_8061B4B0(void) {
    return D_807F5CE0 != 0;
}

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B7E0.s")

typedef struct {
    u8 unk0[0xF7 - 0x0];
    u8 unkF7;
} Struct8061B840;

void func_global_asm_8061B840(Struct8061B840 *arg0, s8 arg1) {
    arg0->unkF7 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061B9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C0FC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061C464.s")

extern f32 D_global_asm_807574E0;
extern u8 D_global_asm_8076A0B1;
extern s8 D_global_asm_8076A0B3;

void func_global_asm_8061C518(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, f32 argA) {
    f32 sp3C;

    sp3C = arg1->animation_state->scale[1];
    if (is_cutscene_active == 1) {
        func_global_asm_8061D4E4(arg0);
    }
    D_global_asm_8076A0B3 = 0;
    D_global_asm_8076A0B1 |= 0x10;
    arg1->animation_state->scale[1] = D_global_asm_807574E0;
    func_global_asm_8061C6A8(arg0, arg1, (s32) arg2, (s32) arg3, (s32) arg4, (s32) arg5, (s32) arg6, (s32) arg7, (s32) arg8, (s32) arg9, argA);
    arg1->animation_state->scale[1] = sp3C;
    global_properties_bitfield &= ~1;
}

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

typedef struct CutsceneBank {
    CutsceneBank_unk0 unk0[24];
    s16 lock_count;
    u8 padC2[2];
    void *lock_regions;
    u8 *lock_chunks;
    s16 cutscene_count;
    u8 padCE[2];
    CutsceneBank_CamBank *camera_bank;
    u8 unkD4[4];
    CutsceneBank_FuncBank *function_bank;
    f32 unkDC;
} CutsceneBank;

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

void func_global_asm_8061CB08(void) {
    if (D_807F5CF4 & 0x40) {
        D_807F5CF4 &= 0xFFBF;
        return;
    }
    D_807F5CF4 |= 2;
}

extern s16 D_global_asm_807476F8;
extern s16 D_global_asm_807476F4;
extern s16 D_global_asm_807476F8;
extern Actor * D_global_asm_807F5D10;
extern u8 D_global_asm_807476EC;
extern CutsceneBank D_807F5B10[2];
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/playCutscene.s")

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
            func_global_asm_806119F0(0x8E32B6F7U);
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

extern s16 D_807F5CEE;
extern Actor *D_807F5CE8;
extern s8 D_807F5CFA;
extern s16 D_807F5CF0;
extern s16 D_global_asm_807476F4;
extern f32 D_global_asm_807576DC;
extern f32 loading_zone_transition_speed;
extern s8 loading_zone_transition_type;

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

extern Actor *D_807F5CE8;

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D898.s")

void func_global_asm_8061D934(u8 arg0) {
    D_global_asm_807476F4 = arg0;
    D_807F5CF0 = 0;
    func_global_asm_8061D898();
}

// hmm, causes fiddly signature for func_global_asm_8061D898
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061D968.s")

void func_global_asm_8061D9EC(s32 arg0, s32 arg1, s32 arg2) {
    loading_zone_transition_type = 0;
    loading_zone_transition_speed = D_global_asm_807576DC;
}

extern f32 D_global_asm_807576E0;

void func_global_asm_8061DA14(s32 arg0, s32 arg1, s32 arg2) {
    D_global_asm_8076A0B1 |= 0x40;
    loading_zone_transition_type = 0;
    loading_zone_transition_speed = D_global_asm_807576E0;
    func_global_asm_8060098C(&func_global_asm_8061D9EC, 0x8000003C, 0, 0, 0);
}

void func_global_asm_8061DA84(s32 arg0, s32 arg1, s32 arg2) {
    func_global_asm_8061CB08();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061DAAC.s")

s32 func_global_asm_80620628(Actor*, f32, s32, s32); // extern

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061EF4C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F2B8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8061F53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80620F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80621174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062133C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806224CC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806227F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806228BC.s")

extern f32 D_global_asm_80757A18;
extern f32 D_global_asm_80757A1C;
extern f32 D_global_asm_80757A20;
extern f32 D_global_asm_80757A24;

f32 func_global_asm_80622ABC(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f0;

    temp_f0 = arg0 - arg1;
    if (D_global_asm_80757A18 < temp_f0) {
        arg1 += D_global_asm_80757A1C;
    } else if (temp_f0 < D_global_asm_80757A20) {
        arg0 += D_global_asm_80757A24;
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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80625C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626110.s")

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

s32 func_global_asm_806264DC(s32, void*, u8); // extern

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626264.s")

// doable, weird negative offsets
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626478.s")

// memcpy concat, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806264DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80626F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062754C.s")

// rodata, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_806276AC.s")

extern f32 D_global_asm_80757F58;

/*
f32 func_global_asm_806276AC(void) {
    s16 playerIndex;

    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        character_change_array[playerIndex].look_at_at_x = D_global_asm_80757F58;
        character_change_array[playerIndex].look_at_at_y = 205.0f;
        character_change_array[playerIndex].look_at_at_z = 584.0f;
    }
    return 1.0f;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_8062773C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_201B0/func_global_asm_80627948.s")
