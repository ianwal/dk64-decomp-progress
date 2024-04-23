#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_80750AB4;

extern f32 D_global_asm_807F620C;
extern f32 D_global_asm_807F621C; // X
extern f32 D_global_asm_807F6220; // Y
extern f32 D_global_asm_807F6224; // Z
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C; // Y Rotation
extern f32 D_global_asm_807F6230;
extern f32 D_global_asm_807F6238;

extern u8 D_global_asm_807F693F;

s32 func_global_asm_806418E8(s16, s16, s16);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063D930.s")

extern u8 D_global_asm_807F66F0[];

/*
// TODO: Pretty close, last loop is wrong somehow
void func_global_asm_8063D930(void) {
    s32 i;

    for (i = 0; i < 600; i++) {
        D_global_asm_807F6240[i] = -1;
    }
    for (i = 0; i < 530; i++) {
        D_global_asm_807F66F0[i] = 0;
    }
}
*/

s16 func_global_asm_8063D990(s16 arg0) {
    return D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk8A;
}

s16 func_global_asm_8063D9D0(s16 arg0, u8 arg1) {
    s32 var_v1;

    if (!arg1) {
        var_v1 = 0x226;
    } else {
        var_v1 = 0;
    }
    while (D_global_asm_807F6240[var_v1] != -1) {
        var_v1++;
    }
    D_global_asm_807F6240[var_v1] = arg0;
    return var_v1;
}

void func_global_asm_8063DA78(s16 arg0, s16 arg1, s16 arg2);

void func_global_asm_8063DA40(s16 arg0, s16 arg1) {
    func_global_asm_8063DA78(arg0, arg1, 0);
}

void func_global_asm_8063DA78(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;

    temp_v0 = func_global_asm_80659470(D_global_asm_807F6240[arg0]);
    if (temp_v0 != -1) {
        D_global_asm_807F6000[temp_v0].unk7C->unk48[arg2] = arg1;
        D_global_asm_807F6000[temp_v0].unk7C->unk54 = 1;
    }
}

typedef struct {
    s16 unk0; // Used
    s16 unk2; // Used
    s16 unk4; // Used
    u8 unk6; // Used
    u8 unk7;
} Struct807F61B0;

extern Struct807F61B0 D_global_asm_807F61B0[];

void func_global_asm_8063DB0C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_global_asm_807F61B0[i].unk6 = FALSE;
    }
}

void func_global_asm_8063DB3C(s16 arg0, s16 arg1, s16 arg2) {
    s16 phi_v0 = 0;
    s32 phi_v1 = FALSE;

    while (!phi_v1 && phi_v0 < 8) {
        if (!D_global_asm_807F61B0[phi_v0].unk6) {
            phi_v1 = TRUE;
        } else {
            phi_v0++;
        }
    }

    if (phi_v1) {
        D_global_asm_807F61B0[phi_v0].unk6 = TRUE;
        D_global_asm_807F61B0[phi_v0].unk0 = arg0;
        D_global_asm_807F61B0[phi_v0].unk2 = arg1;
        D_global_asm_807F61B0[phi_v0].unk4 = arg2;
    }
}

void func_global_asm_8063DBD8(s16 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_global_asm_807F61B0[i].unk6 && (arg0 == D_global_asm_807F61B0[i].unk0)) {
            func_global_asm_8063DA40(D_global_asm_807F61B0[i].unk2, D_global_asm_807F61B0[i].unk4);
            D_global_asm_807F61B0[i].unk6 = FALSE;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063DC58.s")

typedef struct Struct8063DE68_arg0_unkA0 Struct8063DE68_arg0_unkA0;

struct Struct8063DE68_arg0_unkA0 {
    u8 unk0[0x4C - 0x0];
    Struct8063DE68_arg0_unkA0 *next; // 0x4C
};

typedef struct {
    void *unk0;
    u8 unk4[0xA0 - 0x4];
    void *unkA0;
} Struct8063DE68_arg0;

void func_global_asm_8063DE68(Struct8063DE68_arg0 *arg0) {
    void *temp_a1;
    Struct8063DE68_arg0_unkA0 *next;
    Struct8063DE68_arg0_unkA0 *current;

    temp_a1 = arg0->unk0;
    if (temp_a1 != NULL) {
        free(temp_a1);
    }
    current = arg0->unkA0;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(arg0);
}

void func_global_asm_8063DED0(OM2_unk7C *arg0) {
    s32 i = 0;
    f32 *temp = arg0;
    
    // TODO: Hmm...
    while (i < 8) {
        temp[6] = 1.0f;
        temp[7] = 1.0f;
        temp[8] = 1.0f;
        temp += 4;
        temp[1] = 1.0f;
        i += 4;
    }
    arg0->unk10 = -1;
    arg0->unk12 = -1;
    arg0->unk38 = -1;
    arg0->unk0 = 0;
    arg0->unk40 = 0;
    arg0->unk42 = 0;
    arg0->unk44[0] = 0;
    arg0->unk44[1] = 0;
    arg0->unk48[0] = 0;
    arg0->unk48[1] = 0;
    arg0->unk48[2] = 0;
    arg0->unk4B[0] = 0;
    arg0->unk4B[1] = 0;
    arg0->unk4B[2] = 0;
    arg0->unk4E = 0;
    arg0->unk4F = 0;
    arg0->unk50 = 0;
    arg0->unk51 = 0;
    arg0->unk52 = 0;
    arg0->unk53 = 0;
    arg0->unk80 = 0;
    arg0->unk82 = 0;
    arg0->unk84 = 0x7FFF;
    arg0->unk86 = 0x7FFF;
    arg0->unk88 = 0;
    arg0->unk8A = 0xFFF;
    arg0->unk94 = 0;
    arg0->unk54 = 0;
    arg0->unk5C = 0;
    arg0->unk67 = 0;
    arg0->unk6E = 1;
    arg0->unk6F = 0;
    arg0->unk62 = 0;
    arg0->unk64 = 0;
    arg0->unk60 = 0;
    arg0->unk66 = 0xFF;
    arg0->unk70 = 1;
    arg0->unk71 = 1;
    arg0->unk9A = 0;
    arg0->unk9B = 0;
    arg0->unk98 = 0;
    arg0->unk4 = -1;
    arg0->unk8 = 0.0f;
    arg0->unkC = 0.0f;
    arg0->unk34 = 0.0f;
    arg0->unk3C = 0.0f;
    arg0->unk74 = 0.0f;
    arg0->unk78 = 0.0f;
    arg0->unk7C = 0.0f;
    arg0->unk8C = 0.0f;
    arg0->unk90 = 0.0f;
}

void func_global_asm_8063DFEC(s32 arg0, void *arg1) {
    s16 temp_v0;

    temp_v0 = func_global_asm_80659470(D_global_asm_807F6240[arg0]);
    if (temp_v0 != -1) {
        memcpy(&D_global_asm_807F6000[temp_v0].unk7C->unk14, arg1, 0x20);
        D_global_asm_807F66F0[arg0] = 1;
    }
}

void func_global_asm_8063E078(OM2_unk7C *arg0) {
    u8 i;

    for (i = 0; i < 2; i++) {
        if (arg0->unk44[i] != 0) {
            arg0->unk44[i]--;
        }
    }
    for (i = 0; i < 3; i++) {
        arg0->unk4B[i] = arg0->unk48[i];
    }
    arg0->unk4E = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063E0D4.s")

void func_global_asm_8063E5B4(OM2_unk7C *arg0) {
    Actor *temp_v1;

    arg0->unk34 = D_global_asm_807F622C - D_global_asm_807F620C;
    arg0->unk48[0] = arg0->unk4B[0];
    arg0->unk48[1] = arg0->unk4B[1];
    arg0->unk48[2] = arg0->unk4B[2];
    arg0->unk53 = arg0->unk52;
    arg0->unk51 = 0;
    arg0->unk52 = 0;
    arg0->unk5C = 0;
    arg0->unk9A |= 1;
    if (arg0->unk94 != NULL) {
        temp_v1 = arg0->unk94;
        temp_v1->x_position = D_global_asm_807F621C;
        temp_v1->y_position = D_global_asm_807F6220;
        temp_v1->z_position = D_global_asm_807F6224;
        temp_v1->y_rotation = (D_global_asm_807F622C * 4096.0f) / 360.0f;
        if (global_properties_bitfield & 0x1000) {
            global_properties_bitfield &= ~0x1000;
            deleteActor(arg0->unk94);
            arg0->unk94 = NULL;
        }
    }
    D_global_asm_807F693F = 0;
}

void func_global_asm_8063E6B4(OM2_unk7C *arg0) {
    if (arg0->unk4 != object_timer) {
        arg0->unk4 = object_timer;
        if (arg0->unk64 < arg0->unk62) {
            arg0->unk64 += arg0->unk66;
            if (arg0->unk62 < arg0->unk64) {
                arg0->unk64 = arg0->unk62;
            }
        } else {
            arg0->unk64 -= arg0->unk66;
            if (arg0->unk64 < arg0->unk62) {
                arg0->unk64 = arg0->unk62;
            }
        }
    }
}

void func_global_asm_8063E72C(OM2_unk7C *arg0) {
    switch (arg0->unk50) {
        case 0:
            break;
        case 1:
            if (arg0->unk52 != 0) {
                arg0->unk74 += arg0->unk7C;
                if (arg0->unk78 < arg0->unk74) {
                    arg0->unk74 = arg0->unk78;
                }
            } else {
                arg0->unk74 -= arg0->unk7C;
                if (arg0->unk74 < 0.0) {
                    arg0->unk74 = 0.0f;
                }
            }
            if (0.01 < arg0->unk74) {
                D_global_asm_807F621C += arg0->unk8C * arg0->unk74;
                D_global_asm_807F6224 += arg0->unk90 * arg0->unk74;
                if (D_global_asm_807F621C < arg0->unk80) {
                    D_global_asm_807F621C = arg0->unk80;
                }
                if (D_global_asm_807F6224 < arg0->unk82) {
                    D_global_asm_807F6224 = arg0->unk82;
                }
                if (arg0->unk84 < D_global_asm_807F621C) {
                    D_global_asm_807F621C = arg0->unk84;
                }
                if (arg0->unk86 < D_global_asm_807F6224) {
                    D_global_asm_807F6224 = arg0->unk86;
                }
            }
            break;
        case 2:
            if (arg0->unk52 != 0) {
                switch (arg0->unk52) {
                    case 1:
                        arg0->unk74 += arg0->unk7C;
                        break;
                    case 2:
                        arg0->unk74 -= arg0->unk7C;
                        break;
                }
                if (arg0->unk78 < arg0->unk74) {
                    arg0->unk74 = arg0->unk78;
                }
                if (arg0->unk74 < -arg0->unk78) {
                    arg0->unk74 = -arg0->unk78;
                }
                D_global_asm_807F622C += arg0->unk74;
            } else {
                if (arg0->unk74 > 0.0) {
                    arg0->unk74 -= arg0->unk7C;
                    if (arg0->unk74 < 0.0) {
                        arg0->unk74 = 0.0f;
                    }
                } else {
                    arg0->unk74 += arg0->unk7C;
                    if (arg0->unk74 > 0.0) {
                        arg0->unk74 = 0.0f;
                    }
                }
                D_global_asm_807F622C += arg0->unk74;
            }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063EA14.s")

// Jumptable, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063FA48.s")

void func_global_asm_80641724(s16 arg0) {
    PlayerAdditionalActorData *PaaD = character_change_array->player_pointer->PaaD;
    switch (arg0) {
        case 0x33:
        case 0xBC:
        case 0x125:
        case 0x126:
        case 0x127:
        case 0x128:
        case 0x129:
        case 0x229:
        case 0x22A:
        case 0x22B:
            PaaD->unk245 = 0x3C;
    }
}

void func_global_asm_806417BC(s16 arg0, s16 arg1) {
    Actor *actor;
    s32 i;
    s16 sp44[2];

    sp44[0] = 0;
    sp44[1] = arg1;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        actor = D_global_asm_807FB930[i].unk0;
        if (actor->unk58 == (u32)arg0) {
            func_global_asm_8067AB20(NULL, actor, 0x01000000, 1, &sp44, 0);
        }
    }
}

void func_global_asm_80641874(s16 arg0, s16 arg1) {
    s16 *temp_v0;
    Actor *sp20;

    temp_v0 = malloc(sizeof(s16) * 2);
    func_global_asm_8061134C(temp_v0);
    temp_v0[1] = arg0;
    temp_v0[0] = arg1;
    func_global_asm_8072E7DC(0xE, &sp20);
    func_global_asm_8067AB20(NULL, sp20, 0x01000000, 1, temp_v0, 0);
}

s32 func_global_asm_806418E8(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_a3;
    s16 temp_v0;

    temp_a3 = D_global_asm_807F6240[arg0];
    if (temp_a3 != -1) {
        temp_v0 = func_global_asm_80659470(temp_a3);
        if ((temp_v0 != -1) && (D_global_asm_807F6000[temp_v0].unk7C != NULL)) {
            D_global_asm_807F6000[temp_v0].unk7C->unk48[arg2] = arg1;
            return TRUE;
        }
    }
    return FALSE;
}

void func_global_asm_8064199C(Struct8064199C_arg0 *arg0, s8 arg1, s16 arg2) {
    arg0->unk54 = arg1;
    switch (arg1 & 0xFF) {
        case 3:
        case 4:
        case 6:
            arg0->unk58 = arg2 * arg2;
            break;
        case 5:
            arg0->unk58 = arg2;
            break;
    }
}

// TODO: Get rid of GOTOs
s32 func_global_asm_806419F8(void) {
    PlayerAdditionalActorData *PaaD = character_change_array->player_pointer->PaaD;

    if (player_pointer->control_state == 0x42) {
        if (PaaD->unkBC == 0x62 || PaaD->unkBC == 0x88 || PaaD->unkBC == 0x17) {
            goto block_8;
        }
    }
    if (player_pointer->control_state == 0x52 || player_pointer->control_state == 0x67) {
        goto block_8;
    }
    if (character_change_array->action_initiated == 0x1C) {
        goto block_8;
    }
    if (character_change_array->action_initiated != 0x53) {
        goto block_9;
    }
block_8:
    return 0;
block_9:
    return 1;
}

extern u8 D_global_asm_807F6938;
extern s16 D_global_asm_807F6918[];

// TODO: This does match but the types on the externs are sus
void func_global_asm_80641A78(void) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6938; i++) {
        func_global_asm_806355DC(D_global_asm_807F6240[D_global_asm_807F6918[i]], 1);
    }
}

void func_global_asm_8063DED0(OM2_unk7C*);

void func_global_asm_80641B00(s16 arg0, s16 arg1, s16 arg2) {
    arg0 = func_global_asm_80659470(arg0);
    arg1 = func_global_asm_80659470(arg1);
    D_global_asm_807F6000[arg0].unk7C = malloc(sizeof(OM2_unk7C));
    func_global_asm_8063DED0(D_global_asm_807F6000[arg0].unk7C);
    D_global_asm_807F6000[arg0].unk7C->unk48[0] = arg2;
    D_global_asm_807F6000[arg0].unk7C->unkA0 = D_global_asm_807F6000[arg1].unk7C->unkA0;
}

void func_global_asm_80641BCC(s16 arg0, s16 arg1, s16 arg2) {
    s32 i;
    Actor *temp;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp = D_global_asm_807FB930[i].unk0;
        if (!(temp->object_properties_bitfield & 0x2000)
            && (arg0 == temp->unk58)
            && (arg2 == temp->unk10C)) {
            if (arg1 != 0) {
                temp->unk68 |= 4;
            } else {
                temp->unk68 &= ~4;
            }
        }
    }
}

void func_global_asm_80641C98(s16 arg0, s16 arg1, s16 arg2) {
    s32 var_s2;
    s32 i;

    switch (arg1) {
        case 0:
            var_s2 = 1;
            break;
        case 1:
            var_s2 = 2;
            break;
        case 2:
            var_s2 = 0x3C;
            break;
    }

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        if (!(D_global_asm_807FB930[i].unk0->object_properties_bitfield & 0x2000)
            && (arg0 == D_global_asm_807FB930[i].unk0->unk58)
            && (arg2 == D_global_asm_807FB930[i].unk0->unk10C)) {
            func_global_asm_80679200(D_global_asm_807FB930[i].unk0, NULL, 0x800, var_s2, 0, 0);
        }
    }
}

typedef struct {
    u8 pad0[0x94 - 0x0];
    Actor *unk94;
} GlobalASMStruct44;

s32 func_global_asm_80678014(s32);
extern s16 D_global_asm_807F693C;
extern u8 D_global_asm_807F693F;

void func_global_asm_80641DA0(GlobalASMStruct44 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 phi_v1;

    if ((arg0->unk94 == 0) && ((func_global_asm_80678014(0x14)))) {
        arg0->unk94 = last_spawned_actor;
        last_spawned_actor->noclip_byte = 1;
        last_spawned_actor->x_position = D_global_asm_807F621C;
        last_spawned_actor->y_position = D_global_asm_807F6220;
        last_spawned_actor->z_position = D_global_asm_807F6224;
        last_spawned_actor->y_rotation = (D_global_asm_807F622C * 4096.0f) / 360.0f;
        if (D_global_asm_807F693F != 0) {
            last_spawned_actor->unk15E = arg3;
        }
        if (D_global_asm_807F693F != 0) {
            phi_v1 = 4;
        } else {
            phi_v1 = 0;
        }
        switch (arg2) {
            case 0:
                playCutscene(arg0->unk94, arg1, (phi_v1 | 1 | D_global_asm_807F693C) & 0xFF);
                return;
            case 1:
                playCutscene(NULL, arg1, (phi_v1 | 1 | D_global_asm_807F693C) & 0xFF);
                return;
            case 2:
                playCutscene(getSpawnerTiedActor(arg3, 0x400), arg1, (phi_v1 | 1 | D_global_asm_807F693C) & 0xFF);
                break;
        }
    }
}

void func_global_asm_80641F68(void) {

}

u8 func_global_asm_80641F70(s16 arg0) {
    f32 sp8C;
    f32 sp88;
    f32 dx;
    f32 dz;
    f32 dy;
    s32 pad[2];
    u8 sp73;
    u8 i;
    Actor *player;

    sp73 = FALSE;
    for (i = 0; i < D_global_asm_80750AB4; i++) {
        if (character_change_array[i].does_player_exist != 0) {
            player = character_change_array[i].player_pointer;
            dx = D_global_asm_807F621C - player->x_position;
            dy = D_global_asm_807F6220 - player->y_position;
            dz = D_global_asm_807F6224 - player->z_position;
            dx *= dx;
            dy *= dy;
            dz *= dz;
            if (sqrtf(dx + dy + dz) < arg0) {
                func_global_asm_80626F8C(D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, &sp8C, &sp88, 0, 1.0f, i);
                if ((s16)sp8C >= (character_change_array[i].unk270 + 0x14)
                    && ((s16)sp88 >= (character_change_array[i].unk272 + 0x14))
                    && (((s16)sp8C <= character_change_array[i].unk274 - 0x14))
                    && ((character_change_array[i].unk276 - 0x14) >= (s16)sp88)) {
                        sp73 = TRUE;
                }
            }
        }
    }
    return sp73;
}

u8 func_global_asm_8064216C(s16 cap, f32 x, f32 y, f32 z) {
    f32 dx = D_global_asm_807F621C - x;
    f32 dy = D_global_asm_807F6220 - y;
    f32 dz = D_global_asm_807F6224 - z;
    dx *= dx;
    dy *= dy;
    dz *= dz;
    return sqrtf(dx + dy + dz) < cap;
}

s32 func_global_asm_80642204(s16 arg0) {
    u8 playerIndex;
    for (playerIndex = 0; playerIndex < D_global_asm_80750AB4; playerIndex++) {
        if ((character_change_array[playerIndex].does_player_exist)
            && (func_global_asm_8064216C(arg0,
                              character_change_array[playerIndex].player_pointer->x_position,
                              character_change_array[playerIndex].player_pointer->y_position,
                              character_change_array[playerIndex].player_pointer->z_position))) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_global_asm_806422D8(s16 arg0) {
    u8 playerIndex;
    for (playerIndex = 0; playerIndex < D_global_asm_80750AB4; playerIndex++) {
        if ((character_change_array[playerIndex].does_player_exist)
            && (func_global_asm_8064216C(arg0,
                              character_change_array[playerIndex].look_at_eye_x,
                              character_change_array[playerIndex].look_at_eye_y,
                              character_change_array[playerIndex].look_at_eye_z))) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_global_asm_806423A8(s16 arg0, s16 arg1, s16 arg2) {
    s16 var_s0;
    Actor *temp_v0;

    var_s0 = arg1;
    while (arg2 >= var_s0) {
        if (func_global_asm_80726D7C(var_s0) != 0) {
            temp_v0 = getSpawnerTiedActor(var_s0, 0);
            if (temp_v0 != NULL) {
                if (func_global_asm_8064216C(arg0, temp_v0->x_position, temp_v0->y_position, temp_v0->z_position) != 0) {
                    return TRUE;
                }
            }
        }
        var_s0 += 1;
    }
    return FALSE;
}

extern f32 D_global_asm_807F6238;

void func_global_asm_80642480(s16 arg0, s32 arg1) {
    s32 temp; // TODO: Why is this needed?
    f32 sp20;

    switch (arg0) {
        case 0:
            sp20 = D_global_asm_807F6220;
            if (func_global_asm_80667110(D_global_asm_807F621C, D_global_asm_807F6224, &sp20)) {
                D_global_asm_807F6220 = sp20 + D_global_asm_807F6238;
            }
        case 1:
            return;
    }
}

s32 func_global_asm_80642500(f32 *arg0, s16 arg1, s16 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    f32 phi_f12;
    s32 phi_v1;

    phi_v1 = 0;
    temp_f0 = arg0[(u8)((u16)arg1 >> 8)];
    switch ((u8)arg1 & 0xFF) {
        case 0:
            temp_f2 = arg2 / 10.0f;
            if (temp_f2 < temp_f0) {
                phi_f12 = temp_f0 - temp_f2;
            } else {
                phi_f12 = temp_f2 - temp_f0;
            }
            if (phi_f12 < 0.05) {
                phi_v1 = 1;
            }
            break;
        case 1:
            if ((arg2 / 10.0f) < temp_f0) {
                phi_v1 = 1;
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

extern f32 D_807F6208;
extern f32 D_807F6210;
extern f32 D_global_asm_807F620C;

s32 func_global_asm_806425FC(s16 arg0, s16 arg1) {
    f32 var_f2;
    f32 var_f12;
    s32 var_v1;
    f32 temp = (arg1 / 10.0f);

    var_v1 = 0;
    switch (((arg0 >> 8) % 255) & 0xFF) {
        case 0:
            var_f2 = D_807F6208;
            break;
        case 1:
            var_f2 = D_global_asm_807F620C;
            break;
        case 2:
            var_f2 = D_807F6210;
            break;
    }

    switch ((u8)arg0 & 0xFF) {
        case 0:
            if (temp < var_f2) {
                var_f12 = var_f2 - temp;
            } else {
                var_f12 = temp - var_f2;
            }
            if (var_f12 != 0.1) {
                var_v1 = 1;
            }
            break;
        case 1:
            if (temp < var_f2) {
                var_v1 = 1;
            }
            break;
        case 2:
            if (var_f2 < temp) {
                var_v1 = 1;
            }
            break;
    }
    return var_v1;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14[1]; // TODO: How many?
} Struct80642844;

void func_global_asm_80642748(s16 arg0, s16 arg1, Struct80642844 *arg2, s32 arg3, u8 arg4) {
    f32 var_f0;

    var_f0 = arg1 / 10.0f;
    if ((u8)(arg0 & 0xFF) == 1) {
        var_f0 = arg2->unk14[arg1];
    }
    switch ((u8)(arg0 >> 8) & 0xFF) {
        case 0:
            if (arg4 == 1) {
                D_global_asm_807F6228 += var_f0;
            } else {
                D_global_asm_807F6228 = var_f0;
            }
            break;
        case 1:
            if (arg4 == 1) {
                D_global_asm_807F622C += var_f0;
                return;
            } else {
                D_global_asm_807F622C = var_f0;
            }
            break;
        case 2:
            if (arg4 == 1) {
                D_global_asm_807F6230 += var_f0;
                return;
            } else {
                D_global_asm_807F6230 = var_f0;
            }
            break;
    }
}

void func_global_asm_80642844(s16 arg0, s16 arg1, Struct80642844 *arg2, s32 arg3, u8 arg4) {
    f32 var_f0;

    var_f0 = arg1 / 10.0f;
    // TODO: Wtf
    if (((u8)arg0 & 0xFF) == 1) {
        var_f0 = arg2->unk14[arg1];
    }
    // TODO: Wtf
    switch ((u8)(arg0 >> 8) & 0xFF) {
        case 0:
            if (arg4 == 1) {
                D_global_asm_807F621C += var_f0;
            } else {
                D_global_asm_807F621C = var_f0;
            }
            break;
        case 1:
            if (arg4 == 1) {
                D_global_asm_807F6220 += var_f0;
            } else {
                D_global_asm_807F6220 = var_f0;
            }
            break;
        case 2:
            if (arg4 == 1) {
                D_global_asm_807F6224 += var_f0;
            } else {
                D_global_asm_807F6224 = var_f0;
            }
            break;
    }
}

extern s32 D_global_asm_8071FC58;

void func_global_asm_80642940(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 randomZOffset;
    f32 randomYOffset;
    f32 randomXOffset;
    s32 i;

    for (i = 0; i < 1; i++) {
        randomXOffset = (((func_global_asm_806119A0() / 10000U) % 200) / 10.0) - 10.0;
        randomYOffset = (((func_global_asm_806119A0() / 10000U) % 200) / 10.0) - 7.0;
        randomZOffset = (((func_global_asm_806119A0() / 10000U) % 200) / 10.0) - 10.0;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(2);
        func_global_asm_80714950(0x64);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        drawSpriteAtPosition(
            &D_global_asm_8071FC58,
            0.5f,
            D_global_asm_807F621C + randomXOffset,
            D_global_asm_807F6220 + randomYOffset,
            D_global_asm_807F6224 + randomZOffset
        );
    }
    createLight(D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, 0.0f, 0.0f, 0.0f, 300.0f, 0, 0xA6, 0x30, 0xFF);
}
