#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_8071FBC8;
extern s32 D_global_asm_8071FF18;
extern s32 D_global_asm_8071FFA0;
extern s32 D_global_asm_80720A7C;
extern s32 D_global_asm_80721530;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct80748280;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Struct8074828C;

extern u8 D_global_asm_80748214[];
extern Struct80748280 D_global_asm_80748280;
extern Struct8074828C D_global_asm_8074828C;
extern s16 D_global_asm_807480D0;
extern s16 D_global_asm_807480D4;
extern s16 D_global_asm_807480D8;
extern f32 D_global_asm_807480E0;
extern f32 D_global_asm_807480E4;
extern f32 D_global_asm_807482A4;

extern u8 D_global_asm_80750AB4;
extern s32 D_global_asm_807552E8;

extern f32 D_global_asm_80770B68[];
extern f32 D_global_asm_80770BC0[];
extern s16 D_global_asm_80770628[];

extern f32 D_global_asm_807F621C; // X
extern f32 D_global_asm_807F6220; // Y
extern f32 D_global_asm_807F6224; // Z
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C; // Y Rotation
extern f32 D_global_asm_807F6230;
extern f32 D_global_asm_807F6234;
extern f32 D_global_asm_807F6238;
extern s8 D_global_asm_807F6950;
extern s8 D_global_asm_807F6951;

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C;
extern f32 D_global_asm_807F6230;
extern f32 D_global_asm_807F6234;
extern s32 D_global_asm_807F6C28;

extern u16 D_global_asm_807FC930[];

s32 func_global_asm_806418E8(s16, s16, s16);
u8 func_global_asm_8064EC60(s32, s16, s16, s16);
extern void func_global_asm_8064EE08(void);

u8 func_global_asm_80661300(s32);

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

extern f32 D_global_asm_807F620C;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F622C;
extern u8 D_global_asm_807F693F;

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

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F622C;

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

// Close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806417BC.s")

/*
void func_global_asm_806417BC(s16 arg0, s16 arg1) {
    Actor *actor;
    s32 i;
    s16 temp;
    s16 sp44;

    sp44 = 0;
    for (i = 0; i < D_global_asm_807FBB34; i++) {
        actor = D_global_asm_807FB930[i].unk0;
        if (actor->unk58 == (u32)arg0) {
            func_global_asm_8067AB20(NULL, actor, 0x01000000, 1, &sp44, 0);
        }
    }
}
*/

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
                playCutscene(func_global_asm_807270C0(arg3, 0x400), arg1, (phi_v1 | 1 | D_global_asm_807F693C) & 0xFF);
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
            temp_v0 = func_global_asm_807270C0(var_s0, 0);
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

// close, doable, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80642500.s")

/*
s32 func_global_asm_80642500(f32 *arg0, s16 arg1, s16 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    f32 phi_f12;
    s32 phi_v1;

    phi_v1 = 0;
    temp_f0 = arg0[(u8)((u16)arg1 >> 8)];
    switch ((u8)arg1) {
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
*/

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806425FC.s")

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C;
extern f32 D_global_asm_807F6230;

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
    f32 var_f18;
    f32 var_f4;
    f32 var_f6;
    s32 i;

    for (i = 0; i < 1; i++) {
        var_f6 = (((func_global_asm_806119A0() / 10000U) % 200) / 10.0) - 10.0;
        var_f4 = (((func_global_asm_806119A0() / 10000U) % 200) / 10.0) - 7.0;
        var_f18 = (((func_global_asm_806119A0() / 10000U) % 200) / 10.0) - 10.0;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(2);
        func_global_asm_80714950(0x64);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_80714CC0(
            &D_global_asm_8071FC58,
            0.5f,
            D_global_asm_807F621C + var_f6,
            D_global_asm_807F6220 + var_f4,
            D_global_asm_807F6224 + var_f18
        );
    }
    func_global_asm_8065A708(D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, 0.0f, 0.0f, 0.0f, 300.0f, 0, 0xA6, 0x30, 0xFF);
}

void func_global_asm_80642BF0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_global_asm_80714B84(&D_global_asm_8071FF18, 0.3f, arg1, 1, 0);
    func_global_asm_80714B84(&D_global_asm_8071FF18, 0.3f, arg1, 2, 0);
    func_global_asm_80714B84(&D_global_asm_8071FF18, 0.3f, arg1, 3, 0);
}

// doable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80642C78.s")

/*
void func_global_asm_80642C78(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    u8 temp_v1;
    f32 sp6C;
    f32 sp68;
    f32 sp64;

    switch (D_global_asm_807F6000[(s16)func_global_asm_80659470(arg1)].unk78[2].unk5) {
        case 0xD:
        case 0x15:
        case 0x19:
            for (i = 1; i < 0xF; i++) {
                func_global_asm_806335B0(arg1, 1, i, &sp6C, &sp68, &sp64);
                func_global_asm_807149B8(1);
                func_global_asm_80714998(2);
                func_global_asm_80714950(-0x14 - ((func_global_asm_806119A0() / 10000U) % 50));
                func_global_asm_807149C8(0xE1, 0x87, 0x38, 0xFF);
                func_global_asm_8071498C(&func_global_asm_80717D4C);
                func_global_asm_80714CC0(&D_global_asm_8071FF18, 0.5f, sp6C, sp68 + 2.0f, sp64);
            }
            break;
    }
}
*/

// TODO: File split here?

void func_global_asm_80642E34(s32 **arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    s32 *var_v1;
    f32 var_f0;
    s32 sp48;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        **arg0 = arg2;
    }
    var_v1 = *arg0;
    var_f0 = ((20.0 - *var_v1) / 20.0);
    if (0.7 < var_f0) {
        var_f0 = 1.0f;
    }
    func_global_asm_806335B0(arg1, 1, 1, &sp5C, &sp58, &sp54);
    sp48 = ((func_global_asm_806119A0() / 10000U) % 200) + 0x37;
    func_global_asm_8065A708(sp5C, sp58, sp54, 0.0f, 0.0f, 0.0f, var_f0 * 200.0, 0, 0, sp48, ((func_global_asm_806119A0() / 10000U) % 80) + 0xAF);
    if (++(*var_v1) == 0x14) {
        *var_v1 = 0;
    }
}

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F6234;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80642FC4;

void func_global_asm_80642FC4(void **arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct80642FC4 *var_v1;
    u8 sp33;
    f32 sp2C;

    if (*arg0 == NULL) {
        var_v1 = malloc(0x10);
        *arg0 = var_v1;
        var_v1->unk0 = 7.0f;
        var_v1->unk4 = ((func_global_asm_806119A0() / 10000U) % 1548) + 0x5DC;
        var_v1->unk8 = (((func_global_asm_806119A0() / 10000U) % 100) / 40.0) + 2.5;
        D_global_asm_807F6234 = (((func_global_asm_806119A0() / 10000U) % 100) / 500.0) + 0.14;
    }
    var_v1 = *arg0;
    sp2C = D_global_asm_807F6220;
    sp33 = func_global_asm_80667110(D_global_asm_807F621C, D_global_asm_807F6224, &sp2C);
    var_v1->unk0 = var_v1->unk0 + -0.64;
    D_global_asm_807F621C += var_v1->unk8 * func_global_asm_80612794(var_v1->unk4);
    D_global_asm_807F6224 += var_v1->unk8 * func_global_asm_80612790(var_v1->unk4);
    if (var_v1->unk0 < -10.0f) {
        var_v1->unk0 = -10.0f;
    }
    D_global_asm_807F6220 += var_v1->unk0;
    if (sp33 != 0) {
        if (D_global_asm_807F6220 < sp2C) {
            var_v1->unk0 = (0.0 - var_v1->unk0) * 0.7;
            D_global_asm_807F6220 = sp2C;
        }
    }
}

void func_global_asm_80643274(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp24;

    if ((object_timer % (u32)arg3) == 0) {
        sp24 = ((func_global_asm_806119A0() / 10000U) % arg2) + 1;
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x64);
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.5f, arg1, sp24, 0);
    }
}

void func_global_asm_80643354(s32 arg0, u32 arg1, u32 arg2) {
    u32 sp24;
    Struct807F5FD4_unk0 *temp_v0;

    if ((object_timer % arg2) == 0) {
        sp24 = (func_global_asm_806119A0() / 10000U) % arg1;
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x64);
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        temp_v0 = &D_global_asm_807F5FD4->unk0[0][sp24];
        func_global_asm_80714CC0(&D_global_asm_8071FFA0, 1.5f, temp_v0->unk0, temp_v0->unk4, temp_v0->unk8);
    }
}

typedef struct {
    s16 unk0;
} Struct80643440_arg0_unk0;

typedef struct {
    Struct80643440_arg0_unk0 *unk0;
} Struct80643440_arg0;

void func_global_asm_80643440(Struct80643440_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_f24;
    Struct80643440_arg0_unk0 *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(Struct80643440_arg0_unk0));
        var_v1 = arg0->unk0;
        var_v1->unk0 = 0;
    }
    var_v1 = arg0->unk0;
    temp_f24 = D_global_asm_807F5FD4->unk0[1][0].unk4 + ((D_global_asm_807F5FD4->unk0[1][1].unk4 - D_global_asm_807F5FD4->unk0[1][0].unk4) * ((func_global_asm_80612794(var_v1->unk0) * 0.5) + 0.5));
    func_global_asm_80659610(1500);
    func_global_asm_8065A708(D_global_asm_807F5FD4->unk0[1][0].unk0, temp_f24, D_global_asm_807F5FD4->unk0[1][0].unk8, 0.0f, 0.0f, 0.0f, 500.0f, 0, 0xFF, 0xFF, 0xFF);
    temp_f24 = D_global_asm_807F5FD4->unk0[1][2].unk4 + ((D_global_asm_807F5FD4->unk0[1][3].unk4 - D_global_asm_807F5FD4->unk0[1][2].unk4) * ((func_global_asm_80612794(var_v1->unk0 + 1300) * 0.5) + 0.5));
    func_global_asm_80659610(1500);
    func_global_asm_8065A708(D_global_asm_807F5FD4->unk0[1][2].unk0, temp_f24, D_global_asm_807F5FD4->unk0[1][2].unk8, 0.0f, 0.0f, 0.0f, 500.0f, 0, 0xFF, 0xFF, 0xFF);
    temp_f24 = D_global_asm_807F5FD4->unk0[1][4].unk4 + ((D_global_asm_807F5FD4->unk0[1][5].unk4 - D_global_asm_807F5FD4->unk0[1][4].unk4) * ((func_global_asm_80612794(var_v1->unk0 + 2600) * 0.5) + 0.5));
    func_global_asm_80659610(1500);
    func_global_asm_8065A708(D_global_asm_807F5FD4->unk0[1][4].unk0, temp_f24, D_global_asm_807F5FD4->unk0[1][4].unk8, 0.0f, 0.0f, 0.0f, 500.0f, 0, 0xFF, 0xFF, 0xFF);
    var_v1->unk0 += 0x32;
}

void func_global_asm_806436A4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    func_global_asm_80643354(0, arg2, arg3);
}

extern s32 D_global_asm_8071FB54;

int func_global_asm_8071C004();

typedef struct {
    u32 unk0;
    s32 unk4;
} Struct806436E0_malloc;

typedef struct {
    Struct806436E0_malloc *unk0;
} Struct806436E0_arg0;

void func_global_asm_806436E0(Struct806436E0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct807F5FD4_unk0 *temp_v0_2;
    Struct806436E0_malloc *var_v1;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 count;

    if (arg0->unk0 == NULL) {
        var_v1 = malloc(sizeof(Struct806436E0_malloc));;
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = arg0->unk0;
    if (var_v1->unk0 == 0) {
        count = (D_global_asm_807F5FD4->unk0[1] - D_global_asm_807F5FD4->unk0[0]);
        var_v1->unk4++;
        if (count == var_v1->unk4) {
            var_v1->unk4 = 0;
        }
        temp_v0_2 = &D_global_asm_807F5FD4->unk0[0][var_v1->unk4];
        sp34 = temp_v0_2->unk0;
        sp30 = temp_v0_2->unk4;
        sp2C = temp_v0_2->unk8;
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0);
        func_global_asm_8071498C(&func_global_asm_8071C004);
        func_global_asm_80714CC0(&D_global_asm_8071FB54, 0.667f, sp34, sp30 + 0xA, sp2C);
        var_v1->unk0 = 0x19;
    }
    var_v1->unk0--;
}

void func_global_asm_8064384C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    ObjectModel2 *temp_v1 = &D_global_asm_807F6000[func_global_asm_80659470(arg1)];

    func_global_asm_8067DF44(temp_v1->x_position, temp_v1->y_position, temp_v1->z_position, temp_v1->hitbox_scale, 0, 1);
}

extern s32 D_global_asm_8071FE08; // TODO: Datatype
extern s32 D_global_asm_8071FE64;
extern s32 D_global_asm_8071FE88;
extern s32 D_global_asm_8071FEAC;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

int func_global_asm_8071910C(); // TODO: Signature

void func_global_asm_806438B8(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 pad;
    s32 temp_s0;
    s32 i;
    f32 sp60;
    f32 sp5C;
    f32 sp58;

    if (arg2 == 1) {
        func_global_asm_806335B0(arg1, 1, arg3, &sp60, &sp5C, &sp58);
    } else {
        sp60 = D_global_asm_807F621C;
        sp5C = D_global_asm_807F6220;
        sp58 = D_global_asm_807F6224;
    }
    func_global_asm_807149B8(0);
    func_global_asm_807149FC(1);
    func_global_asm_80714950(0x100C8);
    func_global_asm_8071498C(&func_global_asm_8071A8B0);
    func_global_asm_80714CC0(&D_global_asm_8071FE08, 1.5f, sp60, sp5C, sp58);
    for (i = 0; i < 7; i++) {
        temp_s0 = (s32)(func_global_asm_806119A0() / 10000U) % 3;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0xA);
        func_global_asm_8071498C(&func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(7);
        switch (temp_s0) {
            case 0:
                func_global_asm_80714CC0(&D_global_asm_8071FE64, 0.5f, sp60, sp5C, sp58);
                break;
            case 1:
                func_global_asm_80714CC0(&D_global_asm_8071FE88, 0.5f, sp60, sp5C, sp58);
                break;
            case 2:
                func_global_asm_80714CC0(&D_global_asm_8071FEAC, 0.5f, sp60, sp5C, sp58);
                break;
        }
    }
}

void func_global_asm_80643B24(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    if ((object_timer % 5U) == 0) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x96);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.0f, arg1, 1, 0);
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x96);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.0f, arg1, 2, 0);
    }
}

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern s32 D_global_asm_807201D4;

typedef struct {
    void *unk0;
    u8 unk4[0x49 - 0x4];
    u8 unk49;
} Struct80643C0C;

void func_global_asm_80643C0C(Struct80643C0C *arg0, s32 arg1, s16 arg2, s32 arg3) {
    f32 var_f2;
    f32 temp_f20;
    s32 *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(8);
    }
    var_v1 = arg0->unk0;
    if (arg2 == 1) {
        *var_v1 = 0;
    }
    temp_f20 = (0x46 - (*var_v1)++) / 70.0f;
    if (temp_f20 > 0.5) {
        var_f2 = 1.0 - (2.0 * (temp_f20 - 0.5));
    } else {
        var_f2 = 2.0 * temp_f20;
    }
    func_global_asm_8065A708(D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, 0.0f, 0.0f, 0.0f, 200.0f * var_f2, 0, 0xFF, (-80.0f * var_f2) + 255.0f, (-205.0f * var_f2) + 255.0f);
    if (0.6 < temp_f20) {
        if ((object_timer % 6U) == 0) {
            func_global_asm_807149FC(2);
            func_global_asm_807149B8(1);
            func_global_asm_80714950(-0x190);
            func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 1);
            func_global_asm_8071498C(&func_global_asm_80717CE8);
            func_global_asm_80714CC0(&D_global_asm_807201D4, 1.2f, D_global_asm_807F621C, D_global_asm_807F6220 + 30.0, D_global_asm_807F6224);
        }
    }
    if (temp_f20 < 0.1) {
        arg0->unk49 = 1;
    }
}

extern s32 D_global_asm_8074E880[];

void func_global_asm_80643F38(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 i;
    for (i = 0; i < 0x1E; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_8071498C(&func_global_asm_8071EA24);
        func_global_asm_8071496C(i / 7);
        func_global_asm_80714CC0(D_global_asm_8074E880[i % 3], 1.4f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064409C.s")

void func_global_asm_8064431C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    func_global_asm_806335B0(arg1, 1, 1, &sp48, &sp40, &sp38);
    func_global_asm_806335B0(arg1, 1, 2, &sp4C, &sp44, &sp3C);
    func_global_asm_8065A708(sp48, sp40, sp38, sp4C, sp44, sp3C, 0.0f, 1, D_global_asm_807480D0, D_global_asm_807480D4, D_global_asm_807480D8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806443E4.s")

void func_global_asm_806449C0(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_global_asm_80714998(2);
    func_global_asm_807149B8(1);
    func_global_asm_80714B84(&D_global_asm_8071FBC8, 1.5f, arg1, arg2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80644A18.s")

void func_global_asm_80644A18(s32, s32, s32, f32);

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80644CC0;

void func_global_asm_80644CC0(void **arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct80644CC0 *var_v1;

    if (*arg0 == NULL) {
        var_v1 = malloc(8);
        *arg0 = var_v1;
        var_v1->unk0 = 0.0f;
        var_v1->unk4 = 0.0f;
    }
    var_v1 = *arg0;
    func_global_asm_80644A18(var_v1, 2, 0x16, 1.0f);
    func_global_asm_80644A18(&var_v1->unk4, 4, 0x18, 0.8f);
}

void func_global_asm_8065A660(f32, f32);

void func_global_asm_80644D50(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    func_global_asm_806335B0(arg1, 1, 1, &sp48, &sp40, &sp38);
    func_global_asm_806335B0(arg1, 1, 2, &sp4C, &sp44, &sp3C);
    func_global_asm_8065A660(D_global_asm_807480E0, D_global_asm_807480E4);
    func_global_asm_8065A708(sp48, sp40, sp38, sp4C, sp44, sp3C, 0.0f, 1, D_global_asm_807480D0, D_global_asm_807480D4, D_global_asm_807480D8);
}

void func_global_asm_80644E2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_807149FC(-1);
    func_global_asm_8071498C(&func_global_asm_80717760);
    func_global_asm_80714950(0x50);
    func_global_asm_80714CC0(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3], 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
}

int func_global_asm_8071E3EC(); // TODO: Signature
extern s32 D_global_asm_80720BC4; // TODO: Datatype

typedef struct {
    f32 unk0;
    f32 unk4;
} Struct80645700_sp20;

void func_global_asm_80644EC8(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u32 sp2C;

    if (((func_global_asm_806119A0() / 10000U) % arg2) == 0) {
        sp2C = (func_global_asm_806119A0() / 10000U) % arg3;
        func_global_asm_80714998(2);
        func_global_asm_80714950(0x10064);
        func_global_asm_8071498C(&func_global_asm_8071AADC);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
        func_global_asm_80714CC0(&D_global_asm_80720A7C, 1.2f, D_global_asm_807F5FD4->unk0[0][sp2C].unk0, D_global_asm_807F5FD4->unk0[0][sp2C].unk4, D_global_asm_807F5FD4->unk0[0][sp2C].unk8);
    }
    if (((func_global_asm_806119A0() / 10000U) % arg2) == 0) {
        sp2C = (func_global_asm_806119A0() / 10000U) % arg3;
        func_global_asm_80714998(2);
        func_global_asm_80714950(0x10064);
        func_global_asm_8071498C(&func_global_asm_8071AADC);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
        func_global_asm_80714CC0(&D_global_asm_80720A7C, 1.2f, D_global_asm_807F5FD4->unk0[1][sp2C].unk0, D_global_asm_807F5FD4->unk0[1][sp2C].unk4, D_global_asm_807F5FD4->unk0[1][sp2C].unk8);
    }
}

extern s32 D_global_asm_80718188;
extern f32 D_global_asm_807480E8;
extern u8 D_global_asm_807480EF;
extern s32 D_global_asm_80720CD8;

void func_global_asm_806450C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u32 temp_hi;
    f32 sp30;

    if (((func_global_asm_806119A0() / 10000U) % 10) == 0) {
        temp_hi = (func_global_asm_806119A0() / 10000U) % arg3;
        sp30 = D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk4;
        if (func_global_asm_80667110(D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk0, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk8, &sp30) != 0) {
            func_global_asm_80714950(sp30 + 2.0);
            func_global_asm_8071498C(&func_global_asm_80718188);
            func_global_asm_807149FC(-1);
            func_global_asm_807149B8(1);
            func_global_asm_807149C8(0xFF, 0xFF, 0xFF, D_global_asm_807480EF);
            func_global_asm_80714CC0(&D_global_asm_80720CD8, D_global_asm_807480E8, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk0, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk4, D_global_asm_807F5FD4->unk0[arg2][temp_hi].unk8);
        }
    }
}

// doable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80645238.s")

void func_global_asm_80645614(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u32 sp24;

    if (((func_global_asm_806119A0() / 10000U) % arg2) == 0) {
        sp24 = (func_global_asm_806119A0() / 10000U) % arg3;
        func_global_asm_80714998(2);
        func_global_asm_80714950(0x10064);
        func_global_asm_8071498C(&func_global_asm_8071AADC);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0xFF);
        func_global_asm_807149B8(1);
        func_global_asm_80714B84(&D_global_asm_80720A7C, 0.5f, arg1, sp24 + 1, 0);
    }
}

void func_global_asm_80645700(Struct80645700_sp20 **arg0, s32 arg1, s16 arg2, s16 arg3) {
    u32 sp24;
    Struct80645700_sp20 *var_v1;
    Struct807F5FD4 *temp;

    if (*arg0 == NULL) {
        if (arg3) {
            var_v1 = malloc(8);
            *arg0 = var_v1;
            var_v1->unk0 = 0.0f;
            var_v1->unk4 = 0.0f;
        }
    }
    var_v1 = *arg0;
    sp24 = (func_global_asm_806119A0() / 10000U) % arg2;
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_80714950(3);
    func_global_asm_8071498C(&func_global_asm_8071E3EC);
    func_global_asm_807149A8(0x7D0);
    func_global_asm_80714CC0(&D_global_asm_80720BC4, 2.5f, D_global_asm_807F5FD4->unk0[0][sp24].unk0, D_global_asm_807F5FD4->unk0[0][sp24].unk4, D_global_asm_807F5FD4->unk0[0][sp24].unk8);
    if (arg3) {
        if (player_pointer->control_state == 0x42) {
            var_v1->unk0 = player_pointer->y_position;
        }
        if (((var_v1->unk0 - player_pointer->y_position) > 200.0) || player_pointer->y_position < 10.0f) {
            if (var_v1->unk4 == 0.0) {
                func_global_asm_805FF9AC(0x48, 0x1C, 0, 0);
                var_v1->unk4 = 1.0f;
            }
        }
    }
}

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F622C;

void func_global_asm_806458C8(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s16 sp2E;
    s16 sp2C;

    if (((u32)object_timer % arg2) == 0) {
        sp2E = ((rand() >> 0xF) % 2048) + (((D_global_asm_807F622C * 4096.0f) / 360.0f) - 1024.0f);
        sp2C = (((rand() >> 0xF) % 32767) % 6) + 0xF;
        func_global_asm_80714950(-0x32 - ((rand() >> 0xF) % 80));
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(2);
        func_global_asm_80714CC0(&D_global_asm_8071FFA0, 1.0f, (func_global_asm_80612794(sp2E) * sp2C) + D_global_asm_807F621C, D_global_asm_807F6220 + 50.0f, (func_global_asm_80612790(sp2E) * sp2C) + D_global_asm_807F6224);
    }
}

void func_global_asm_80645A64(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 i;

    for (i = 0; i < arg2; i++) {
        func_global_asm_80714950(-0x96 - ((rand() >> 0xF) % 80));
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(2);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.0f, arg1, i + 1, 0);
    }
}

void func_global_asm_80645B9C(gASMStruct3 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    if (((s32) (0x243 - arg0->unk44) % 60) == 0) {
        func_global_asm_806085DC(arg1, 0x38, 0xFF, 0x7F, 0, 0x3C, 0.0f);
    }
}

void func_global_asm_80645C04(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    func_global_asm_806335B0(arg1, 1, 1, &sp4C, &sp48, &sp44);
    func_global_asm_80659610(2500);
    func_global_asm_80659600(9);
    func_global_asm_806595F0(2);
    func_global_asm_8065A708(sp4C, sp48, sp44, 0.0f, 0.0f, 0.0f, 600.0f, 0, 0xFF, 0xFF, 0xFF);
    func_global_asm_80659610(2500);
    func_global_asm_80659600(0xA);
    func_global_asm_806595F0(2);
    func_global_asm_8065A708(sp4C, sp48, sp44, 0.0f, 0.0f, 0.0f, 600.0f, 0, 0xFF, 0xFF, 0xFF);
}

typedef struct {
    u8 unk0[0x90 - 0x0];
    f32 unk90;
    u8 unk94[0xFA - 0x94];
    u8 unkFA;
} AAD_global_asm_80645D14;

void func_global_asm_80645D14(s32 **arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 *var_v1;
    s32 pad;
    s32 pad2;
    AAD_global_asm_80645D14 *temp_a2;
    u8 sp1F;
    PlayerAdditionalActorData *PaaD;
    Actor *temp;

    sp1F = FALSE;
    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        var_v1 = *arg0;
        *var_v1 = 1;
    }
    var_v1 = *arg0;
    PaaD = character_change_array->player_pointer->PaaD;
    temp = PaaD->unk104;
    temp_a2 = temp->additional_actor_data;
    if (temp_a2->unkFA != 0) {
        if (character_change_array->look_at_eye_y < (temp_a2->unk90 + 3.0f)) {
            sp1F = TRUE;
        }
    }
    if (*var_v1 != 0) {
        if (sp1F == 0) {
            if (arg2 == 9) {
                func_global_asm_80656E58(9, 4, 1, 0);
                func_global_asm_80656E58(9, 5, 1, 0);
                func_global_asm_80656E58(9, 6, 1, 0);
            } else {
                func_global_asm_80656E58(0xF, 0xF, 1, 0);
                func_global_asm_80656E58(0xE, 0x11, 1, 0);
                func_global_asm_80656E58(0xD, 0x13, 1, 0);
                func_global_asm_80656E58(0xC, 0x15, 1, 0);
            }
            *var_v1 = 0;
        }
    }
    if (*var_v1 == 0) {
        if (sp1F != 0) {
            if (arg2 == 9) {
                func_global_asm_80656E58(9, 4, 1, 1);
                func_global_asm_80656E58(9, 5, 1, 1);
                func_global_asm_80656E58(9, 6, 1, 1);
            } else {
                func_global_asm_80656E58(0xF, 0xF, 1, 1);
                func_global_asm_80656E58(0xE, 0x11, 1, 1);
                func_global_asm_80656E58(0xD, 0x13, 1, 1);
                func_global_asm_80656E58(0xC, 0x15, 1, 1);
            }
            *var_v1 = 1;
        }
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80645F40.s")

/*
extern s32 D_global_asm_80720B00;

void func_global_asm_80645F40(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 phi_f22 = 0.0f;

    if ((object_timer & 0xF) == 0) {
        f64 temp_f26 = 0.05;
        f64 temp_f24 = 1.1;
        f64 temp;
        void* test = &D_global_asm_80720B00;
        for (i = 1; i < 0xB; i++) {
            func_global_asm_807149B8(1);
            func_global_asm_80714998(2);
            func_global_asm_8071498C(&func_global_asm_8071EB70);
            func_global_asm_80714950(700);
            func_global_asm_807149A8(700);
            func_global_asm_80714B84(test, phi_f22 + temp_f24, arg1, i, 1);
            phi_f22 += temp_f26;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80646058.s")

// doable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80646770.s")

extern f32 D_global_asm_807480F0;

/*
void func_global_asm_80646770(s32 **arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct807F5FD4_unk0 *temp_v1;
    Struct807F5FD4_unk0 *temp_v1_2;
    f32 dz;
    f32 dy;
    f32 dx;
    s32 *temp_v0;
    s32 *var_v1;
    s32 temp_fp;
    s32 count;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 found;

    var_v1 = *arg0;
    found = FALSE;
    if (var_v1 == NULL) {
        temp_v0 = malloc(4);
        *arg0 = temp_v0;
        *temp_v0 = 0;
        var_v1 = *arg0;
    }
    count = (D_global_asm_807F5FD4->unk0[1] - D_global_asm_807F5FD4->unk0[0]);
    temp_fp = *var_v1;
    (*var_v1)++;
    if (count == *var_v1) {
        *var_v1 = 0;
    }
    while (!found && temp_fp != *var_v1) {
        temp_v1 = &D_global_asm_807F5FD4->unk0[0][*var_v1];
        dz = (character_change_array->look_at_eye_z - temp_v1->unk8);
        dy = (character_change_array->look_at_eye_y - temp_v1->unk4);
        dx = (character_change_array->look_at_eye_x - temp_v1->unk0);
        if (sqrtf((dy * dy) + (dx * dx) + (dz * dz)) < D_global_asm_807480F0) {
            found = TRUE;
            func_global_asm_807149B8(1);
            func_global_asm_80714998(3);
            func_global_asm_80714950(0);
            func_global_asm_8071498C(&func_global_asm_8071E3EC);
            func_global_asm_807149A8(0x320);
            temp_v1_2 = &D_global_asm_807F5FD4->unk0[0][*var_v1];
            func_global_asm_80714CC0(&D_global_asm_80720BC4, 2.5f, temp_v1_2->unk0, temp_v1_2->unk4, temp_v1_2->unk8);
        } else {
            (*var_v1)++;
            if (count == *var_v1) {
                *var_v1 = 0;
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80646978.s")

extern s32 D_global_asm_80720BE8;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

void func_global_asm_80646DC4(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 pad2;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    s32 pad[6];
    f32 var_f28;
    s32 i;
    f32 sp84[3];
    s32 var_s5;

    if (arg2 != 0) {
        for (i = 1; i < 7; i++) {
            func_global_asm_806335B0(arg1, 1, i, &spB8, &spB4, &spB0);
            func_global_asm_8071496C(i);
            func_global_asm_807149B8(1);
            func_global_asm_8071498C(&func_global_asm_8071BB14);
            func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x96);
            func_global_asm_80714CC0(&D_global_asm_80720BE8, 1.5f, spB8, spB4, spB0);
        }
        return;
    }
    var_f28 = 0.3f;
    var_s5 = 7;
    if (arg3 != 0) {
        var_f28 = 0.2f;
        var_s5 = 0xA;
    }
    for (i = 1; i < var_s5; i++) {
        sp84[0] = (rand() % 300) + 300;
        sp84[1] = i * 0x2A8;
        sp84[2] = (rand() % 500) + 150;
        if (arg3 == 0) {
            func_global_asm_806335B0(arg1, 1, i, &spB8, &spB4, &spB0);
            spB4 += 10.0;
        } else {
            spB8 = ((func_global_asm_806119FC() * 30.0) + D_global_asm_807F621C) - 15.0;
            spB4 = (func_global_asm_806119FC() * 40.0) + D_global_asm_807F6220;
            spB0 = ((func_global_asm_806119FC() * 30.0) + D_global_asm_807F6224) - 15.0;
        }
        func_global_asm_806891D8(0x5A, spB8, spB4, spB0, 0, var_f28, NULL, &sp84[0]);
    }
}

void func_global_asm_80647108(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_global_asm_80714950(-0x78);
    func_global_asm_8071498C(&func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(3);
    func_global_asm_80714B84(&D_global_asm_8071FFA0, 1.5f, arg1, 1, 0);
}

void func_global_asm_80647170(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s32 var_v0;
    s32 var_v1;

    func_global_asm_806335B0(arg1, 1, 2, &sp4C, &sp48, &sp44);
    if (arg2 != 0) {
        var_v0 = 0;
        var_v1 = 0;
    } else {
        var_v0 = 0xFF;
        var_v1 = 0xC8;
    }
    func_global_asm_8065A708(sp4C, sp48, sp44, 0.0f, 0.0f, 0.0f, 80.0f, 0, 0xFF, var_v0, var_v1);
}

void func_global_asm_80647218(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 rand1;
    f32 rand2;
    f32 rand3;
    f32 rand4;

    for (i = 0; i < 6; i++) {
        rand1 = (f32)((func_global_asm_806119A0() / 1000U) % 20) - 10.0;
        rand2 = (f32)((func_global_asm_806119A0() / 1000U) % 20) - 10.0;
        rand3 = (f32)((func_global_asm_806119A0() / 1000U) % 20) - 10.0;
        rand4 = (f32)((f32)(((func_global_asm_806119A0() / 1000U) % 50) - 25.0) / 50.0);
        func_global_asm_80714950(-0xAA);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_8071496C(i << 1);
        func_global_asm_80714CC0(&D_global_asm_8071FFA0, (rand4) + 1.5, D_global_asm_807F621C + (rand1), D_global_asm_807F6220 + (rand2), D_global_asm_807F6224 + (rand3));
    }
}

void func_global_asm_80647508(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp34;
    f32 sp30, sp2C, sp28;

    sp34 = ((func_global_asm_806119A0() / 1000U) % 10) + 1;
    func_global_asm_80714950(-0x28A - ((func_global_asm_806119A0() / 1000U) % 200));
    func_global_asm_8071498C(&func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(9);
    func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x64);
    func_global_asm_80714944(5);
    func_global_asm_806335B0(arg1, 1, sp34, &sp30, &sp2C, &sp28);
    func_global_asm_80714CC0(&D_global_asm_8071FFA0, 1.5f, sp30, sp2C - 70, sp28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80647610.s")

extern f32 D_global_asm_8074816C;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Struct80748168;

extern Struct80748168 D_global_asm_80748168;

void func_global_asm_8064774C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;

    for (i = 1; i < 0xF; i++) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, D_global_asm_80748168.unk3);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, D_global_asm_8074816C, arg1, i, 0);
    }
}

extern s32 D_global_asm_80720EA4;
int func_global_asm_8071910C(); // TODO: Signature

void func_global_asm_80647834(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 temp;

    for (i = 0; i < 0xC; i++) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(0x3C);
        func_global_asm_8071498C(func_global_asm_8071910C);
        func_global_asm_80714998(2);
        func_global_asm_80714950(4);
        temp = ((func_global_asm_806119A0() / 1000U) % 80);
        func_global_asm_80714CC0(&D_global_asm_80720EA4, 1.0f, D_global_asm_807F621C, D_global_asm_807F6220 + temp, D_global_asm_807F6224);
    }
    for (i = 1; i != 6; i++) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x78);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 3.0f, arg1, i, 0);
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80647A14.s")

// extern s32 D_global_asm_8071FC8C; // TODO: Datatype

/*
void func_global_asm_80647A14(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    f32 temp_f26;
    f32 var_f20;

    temp_f26 = 682.0f;
    var_f20 = 0.0f;
    for (i = 0; i < 6; i++) {
        func_global_asm_8071496C(i << 1);
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(7);
        func_global_asm_8071498C(&func_global_asm_8071F1D0);
        func_global_asm_80714998(1);
        func_global_asm_80714950(var_f20);
        func_global_asm_80714CC0(&D_global_asm_8071FC8C, 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        func_global_asm_80714950(var_f20 + 2048.0f);
        func_global_asm_80714CC0(&D_global_asm_8071FC8C, 0.5f, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        var_f20 += temp_f26;
    }
}
*/

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80647B74.s")

typedef struct {
    u32 unk0;
    s32 unk4;
} Struct80647B74;

typedef struct {
    Struct80647B74 *unk0;
} Struct80647B74_arg0;

/*
void func_global_asm_80647B74(Struct80647B74_arg0 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    Struct80647B74 *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(Struct80647B74));
        var_v1 = arg0->unk0;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = arg0->unk0;
    if ((var_v1->unk0 + 0x32) < object_timer) {
        if (((rand() >> 0xF) % 1000) >= 0x353) {
            var_v1->unk4 = 1;
            var_v1->unk0 = object_timer;
        }
    }
    switch (var_v1->unk4) {
        case 1:
            func_global_asm_80635018(arg1, 1, 1, 0);
            break;
        case 3:
            func_global_asm_80635018(arg1, 1, 2, 0);
            break;
        case 5:
            func_global_asm_80635018(arg1, 1, 1, 0);
            break;
        case 7:
            func_global_asm_80635018(arg1, 1, 0, 0);
            var_v1->unk4 = 0;
            break;
    }
    if (var_v1->unk4 != 0) {
        var_v1->unk4++;
    }
}
*/

void func_global_asm_80647CF4(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_global_asm_80714998(2);
    if (arg2 != 0) {
        func_global_asm_80714CC0(&D_global_asm_8071FBC8, 3.0, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        return;
    }
    func_global_asm_80714B84(&D_global_asm_8071FBC8, 3.0, arg1, 1, 0);
}

extern s32 D_global_asm_8071FC40;

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

int func_global_asm_80718BF4();

void func_global_asm_80647D7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 randomX;
    f32 randomZ;
    f32 randomY;
    s32 i;

    if (!((func_global_asm_806119A0() / 10000U) & 1)) {
        for (i = 0; i < 0xC; i++) {
            randomX = (f32)((func_global_asm_806119A0() / 10000U) % 200) * 0.25 - 2.0;
            randomY = (f32)((func_global_asm_806119A0() / 10000U) % 200) * 0.25 - 2.0;
            randomZ = (f32)((func_global_asm_806119A0() / 10000U) % 200) * 0.25 - 2.0;
            func_global_asm_807149B8(1);
            func_global_asm_80714950(1);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(func_global_asm_80718BF4);
            func_global_asm_80714CC0(
                &D_global_asm_8071FC40,
                0.0f,
                D_global_asm_807F621C + randomX,
                D_global_asm_807F6220 + randomY,
                D_global_asm_807F6224 + randomZ
            );
        }
    }
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80648000.s")

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F6234;

/*
void func_global_asm_80648000(OM2_unk7C *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 (*temp_s0)[4];
    f32 (*temp_v0)[4];

    if (arg0->unk0 == NULL) {
        if (arg0->unk9A & 1) {
            arg0->unk0 = malloc(0x44);
            temp_v0 = arg0->unk0;
            func_global_asm_806335B0(arg1, 1, 1, &sp40, &temp_v0[4][0], &sp38);
            temp_v0[4][0] = temp_v0[4][0] - 10.0;
            guRotateF(temp_v0, D_global_asm_807F622C, 0.0f, 1.0f, 0.0f);
        }
    }
    if (arg0->unk9A & 1) {
        if (((func_global_asm_806119A0() / 10000U) % 20) == 0) {
            temp_s0 = arg0->unk0;
            sp48 = ((rand() >> 0xF) % 100) / 100.0;
            guMtxXFMF(temp_s0, (sp48 * 100.0) + -50.0, 0.0f, ((((rand() >> 0xF) % 100) / 100.0) * 150.0) + -75.0, &sp40, &sp3C, &sp38);
            sp40 = (sp40 * D_global_asm_807F6234) + D_global_asm_807F621C;
            sp38 = (sp38 * D_global_asm_807F6234) + D_global_asm_807F6224;
            func_global_asm_807149B8(1);
            func_global_asm_80714950(2);
            func_global_asm_807149FC(-1);
            func_global_asm_8071498C(&func_global_asm_80718BF4);
            func_global_asm_80714CC0(&D_global_asm_8071FC40, 0.0f, sp40, temp_s0[4][0], sp38);
        }
    }
}
*/

extern s32 D_global_asm_80721200;
extern s32 D_global_asm_8072121C;
extern s32 D_global_asm_80721238;
extern s32 D_global_asm_80721250;
extern s32 D_global_asm_8072126C;

extern u32 D_global_asm_8076A068;

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F622C;

void func_global_asm_80716F10(Struct80717D84 *arg0, s32 arg1);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct8064826C_malloc;

typedef struct {
    Struct8064826C_malloc *unk0;
} Struct8064826C_arg0;

void func_global_asm_8064826C(Struct8064826C_arg0 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 *sp3C;
    f32 sp38;
    s32 pad2;
    s32 pad;
    f32 sp2C;
    f32 sp28;
    f32 temp_f0;
    Struct8064826C_malloc *temp_v0;

    sp2C = func_global_asm_80612794(((D_global_asm_807F622C + 90.0f) * 4096.0f) / 360.0f) * 15.0f;
    sp28 = func_global_asm_80612790(((D_global_asm_807F622C + 90.0f) * 4096.0f) / 360.0f) * 15.0f;
    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(sizeof(Struct8064826C_malloc));
        temp_v0 = arg0->unk0;
        temp_v0->unk0 = 0;
        temp_v0->unk4 = 0;
        temp_v0->unk8 = 0;
    }
    temp_v0 = arg0->unk0;
    func_global_asm_807149B8(1);
    switch (arg2) {
        case 0:
            sp3C = &D_global_asm_80721200;
            break;
        case 1:
            sp3C = &D_global_asm_8072121C;
            break;
        case 2:
            sp3C = &D_global_asm_80721250;
            break;
        case 3:
            sp3C = &D_global_asm_80721238;
            break;
    }
    sp38 = func_global_asm_80612794(temp_v0->unk0) * 0.1;
    temp_f0 = func_global_asm_80612794(temp_v0->unk4);
    temp_v0->unk0 += 0x32;
    temp_v0->unk4 += 0x64;
    func_global_asm_80714A08(sp38 + 1.0, (f32)(temp_f0 * 0.1) + 1.0);
    func_global_asm_807149A8(1400);
    func_global_asm_80714A28(4);
    func_global_asm_80714CC0(sp3C, 0.0f, D_global_asm_807F621C + sp2C, (func_global_asm_80612794(temp_v0->unk8) * 10.0) + (D_global_asm_807F6220 + 80.0), D_global_asm_807F6224 + sp28);
    temp_v0->unk8 += 0x64;
    if ((D_global_asm_8076A068 % 12) == 0) {
        func_global_asm_807149B8(1);
        func_global_asm_80714950(0x5A);
        func_global_asm_8071498C(&func_global_asm_80716F10);
        func_global_asm_807149A8(1400);
        func_global_asm_80714A28(4);
        func_global_asm_80714CC0(&D_global_asm_8072126C, 2.0f, D_global_asm_807F621C + sp2C, D_global_asm_807F6220 + 30.0, D_global_asm_807F6224 + sp28);
    }
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806485A0.s")

extern s32 D_global_asm_8071FF18;
extern f32 D_global_asm_807F621C;

/*
void func_global_asm_806485A0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 sp80;
    f32 sp70;
    f32 sp6C;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f30;
    s32 temp_v1;
    s32 i;

    temp_v1 = arg3 & 0xFF;
    switch (arg2 >> 8) {
        case 0:
            sp80 = 1.0f;
            break;
        case 1:
            sp80 = 4.0f;
            break;
    }
        temp_f30 = arg2 & 0xFF;
        sp70 = arg3 >> 8;
        temp_f28 = 0.05f;
    for (i = 0; i != temp_v1; i++) {
        sp6C = sp80 * 1.5;
            func_global_asm_8071496C(func_global_asm_806119FC() * sp70);
loop_8:
            temp_f22 = (2.0f * func_global_asm_806119FC()) - 1.0f;
            temp_f20 = (2.0f * func_global_asm_806119FC()) - 1.0f;
            temp_f26 = (2.0f * func_global_asm_806119FC()) - 1.0f;
            temp_f0 = sqrtf((temp_f22 * temp_f22) + (temp_f20 * temp_f20) + (temp_f26 * temp_f26));
            if (temp_f0 < temp_f28) {
                goto loop_8;
            }
            temp_f2 = temp_f30 / temp_f0;
            func_global_asm_80714CC0(&D_global_asm_8071FF18, sp6C, D_global_asm_807F621C + (temp_f22 * temp_f2), D_global_asm_807F6220 + ((temp_f20 * temp_f2) + temp_f30), D_global_asm_807F6224 + (temp_f26 * temp_f2));
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806487C4.s")

int func_global_asm_80648C50() {
    s16 chunk = character_change_array[0].chunk;
    switch (chunk) {
        case 4:
        case 0xC:
            return 1;
        default:
            return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80648C84.s")

void func_global_asm_8064911C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;

    for (i = 1; i < 8; i++) {
        func_global_asm_80714950(-0x78);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_807149B8(1);
        func_global_asm_80714998(3);
        func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x96);
        func_global_asm_80714B84(&D_global_asm_8071FFA0, 3.5f, arg1, i, 0);
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806491F4.s")

extern s8 D_global_asm_80748170[];
extern s8 D_global_asm_80748178;
extern s16 D_global_asm_807505AE[];

extern u8 D_global_asm_807446F0[];

/*
void func_global_asm_806491F4(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 pad;
    s32 sp28;
    s32 levelIndex;
    s32 var_v0;
    s8 temp;

    if (arg2 == 0) {
        levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
        if (levelIndex >= 8) {
            levelIndex = 0;
        }
        sp28 = D_global_asm_807446F0[levelIndex];
        if (isFlagSet(D_global_asm_80744710[levelIndex], 0)) {
            func_global_asm_80635018(arg1, 1, 0xB, 0);
            func_global_asm_80635018(arg1, 2, 0xB, 0);
        } else if (func_global_asm_805FF0C8()) {
            func_global_asm_80635018(arg1, 1, D_global_asm_80748170[sp28], 0);
            func_global_asm_80635018(arg1, 2, D_global_asm_80748170[sp28], 0);
        } else {
            func_global_asm_80635018(arg1, 1, 0xA, 0);
            func_global_asm_80635018(arg1, 2, 0xA, 0);
        }
    } else {
        temp = D_global_asm_80748178 + 1;
        if (temp >= 0x15) {
            temp = 0;
        }
        D_global_asm_80748178 = temp;
        var_v0 = D_global_asm_80748170[temp >> 2];
        if (temp >> 2 > 0 && !isFlagSet(D_global_asm_807505AE[temp >> 2], 0)) {
            pad = 5;
        } else {
            pad = 0;
        }
        func_global_asm_80635018(arg1, 1, var_v0 + pad, 0);
        func_global_asm_80635018(arg1, 2, var_v0 + pad, 0);
    }
}
*/

extern s32 D_global_asm_80721298; // TODO: Datatype

int func_global_asm_8071F660(); // TODO: Signature

void func_global_asm_806493C4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u8 temp_s1;
    s32 i;

    for (i = 0; i < arg2; i++) {
        temp_s1 = (((rand() >> 0xF) % 32767) % (arg3 + 1));
        func_global_asm_807149B8(1);
        func_global_asm_807149A8(0x7D0);
        func_global_asm_8071498C(func_global_asm_8071F660);
        func_global_asm_807149FC(8);
        func_global_asm_80714CC0(&D_global_asm_80721298, 1.0f, D_global_asm_807F5FD4->unk0[0][temp_s1].unk0, D_global_asm_807F5FD4->unk0[0][temp_s1].unk4, D_global_asm_807F5FD4->unk0[0][temp_s1].unk8);
    }
}

void func_global_asm_8064954C(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 levelIndex;
    s32 var_s2;
    s32 var_v1;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    if (levelIndex >= 8) {
        levelIndex = 7;
    }
    var_v1 = D_global_asm_807446C0[levelIndex] - D_global_asm_807FC930[levelIndex];
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    var_s2 = var_v1;
    for (i = 1; i != 4; i++) {
        func_global_asm_80635018(arg1, i, ((0xA - i) + (var_s2 % 10)) % 10, 0);
        var_s2 /= 10;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_806496B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80649BF0.s")

typedef struct {
    s16 unk0;
    s16 unk2;
} Struct807481C0;

extern Struct807481C0 D_global_asm_807481C0[];

void func_global_asm_80649D74(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    Struct807481C0 *current;
    s16 target;
    s32 found;

    target = D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A;
    found = FALSE;
    current = &D_global_asm_807481C0;
    while (!found) {
        if (target == current->unk0) {
            found = TRUE;
        } else {
            current++;
        }
    }
    func_global_asm_806418E8(0x3D, current->unk2, 1);
}

void func_global_asm_80649E00(GlobalASMStruct49 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk14 = arg0->unk49;
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80649E34.s")

void func_global_asm_80649F64(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    // TODO: Might actually use unk88 which gets read as unk8A because of the explicit s16 in the function signature
    // We'll see what looks more logical when the fields shake out down the line
    func_global_asm_806418E8(0x5F, D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_80649FC0.s")

void func_global_asm_8064A180(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_global_asm_8064A194(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 found;
    s32 i;
    s16 temp_a0;
    u8 *var_v0_2;

    i = 0;
    found = FALSE;
    temp_a0 = D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A;
    while (!found) {
        if (temp_a0 == D_global_asm_80748214[i]) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (i == 0x16) {
        var_v0_2 = &D_global_asm_80748214[0];
    } else {
        // TODO: Yuk
        i++;var_v0_2 = &D_global_asm_80748214[i];
    }
    func_global_asm_806418E8(*var_v0_2, 0xA, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064A258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064A804.s")

void func_global_asm_8064AAC4(s32 arg0, s16 arg1, s8 arg2, s32 arg3) {
    func_global_asm_806BD094(D_global_asm_807F6000[func_global_asm_80659470(arg1)].unk8A, arg2);
}

s32 func_global_asm_8064AB1C(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 i;
    Actor *temp_v0;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_v0 = D_global_asm_807FB930[i].unk0;
        if (!((temp_v0->object_properties_bitfield & 0x2000)
            || (temp_v0->unk58 != ACTOR_LANKY)
            || (temp_v0->locked_to_pad != 1)
            || (arg1 != temp_v0->unk10C)
            || (arg2 == temp_v0->unk10E)
            || (temp_v0->unk10E == 0))) {
            func_global_asm_806508B4(arg1, temp_v0->unk10E, 2);
            func_global_asm_80641874(temp_v0->unk10E + 4, 0);
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064AC28.s")

void func_global_asm_8064B118(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_bonus_8002D6F8(arg1);
}

typedef struct {
    u8 unk0[0x14 - 0x0];
    f32 unk14[3]; // TODO: How many? At least 3
} Struct8064BAF4;

void func_global_asm_8064B150(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    arg0->unk14[arg2] = arg0->unk14[arg2] + arg0->unk14[arg3];
}

void func_global_asm_8064B190(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 temp = -10.0 - arg0->unk14[arg2];
    temp /= -10.0;
    arg0->unk14[arg3] = -1.0 * temp;
}

void func_global_asm_8064B204(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    arg0->unk14[arg2] = -1.0 - arg0->unk14[arg2];
    arg0->unk14[arg2] = 0.0 - arg0->unk14[arg2];
}

void func_global_asm_8064B260(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    arg0->unk14[arg2] = player_pointer->unk100;
    arg0->unk14[arg2 + 1] = player_pointer->unk104;
    arg0->unk14[arg2 + 2] = player_pointer->unk108;
}

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
} Struct8064B2AC;

void func_global_asm_8064B2AC(Struct8064B2AC **arg0, s32 arg1, s32 arg2, s32 arg3) {
    Struct8064B2AC *var_v1;

    if (*arg0 == NULL) {
        *arg0 = malloc(0x28);
    }
    var_v1 = *arg0;
    var_v1->unk0 = D_global_asm_807F621C;
    var_v1->unk4 = D_global_asm_807F6220;
    var_v1->unk8 = D_global_asm_807F6224;
    var_v1->unkC = D_global_asm_807F6228;
    var_v1->unk10 = D_global_asm_807F622C;
    var_v1->unk14 = D_global_asm_807F6230;
    var_v1->unk18 = D_global_asm_807F6234;
    var_v1->unk1C = D_global_asm_807F6234;
    var_v1->unk20 = D_global_asm_807F6234;
    var_v1->unk24 = D_global_asm_807F6238;
}

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

void func_global_asm_8064B370(GlobalASMStruct86 **arg0, s32 arg1, s32 arg2, s32 arg3) {
    GlobalASMStruct86* temp_v0 = *arg0;
    D_global_asm_807F621C = temp_v0->unk0;
    D_global_asm_807F6220 = temp_v0->unk4;
    D_global_asm_807F6224 = temp_v0->unk8;
    D_global_asm_807F6228 = temp_v0->unkC;
    D_global_asm_807F622C = temp_v0->unk10;
    D_global_asm_807F6230 = temp_v0->unk14;
    D_global_asm_807F6234 = temp_v0->unk18;
    D_global_asm_807F6234 = temp_v0->unk1C;
    D_global_asm_807F6234 = temp_v0->unk20;
    D_global_asm_807F6238 = temp_v0->unk24;
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064B3F8.s")

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Struct8064B3F8;

/*
void func_global_asm_8064B3F8(Struct8064B3F8 **arg0, s16 arg1, s16 arg2, s16 arg3) {
    Struct8064B3F8 *temp_t0;
    Struct8064B3F8 *temp_a0;
    f32 temp;
    f32 temp2;
    f32 temp3;
    s32 temp4;

    temp_t0 = *arg0;
    temp_a0 = &arg0[arg3];
    temp4 = func_global_asm_80659470(arg1);
    temp = D_global_asm_807F6000[temp4].x_position;
    temp2 = D_global_asm_807F6000[temp4].y_position;
    temp3 = D_global_asm_807F6000[temp4].z_position;
    temp_a0->unk14 = (temp_t0->unk0 - temp) / arg2;
    temp_a0->unk18 = (temp_t0->unk4 - temp2) / arg2;
    temp_a0->unk1C = (temp_t0->unk8 - temp3) / arg2;
}
*/

void func_global_asm_8064B4AC(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    func_global_asm_806335B0(D_global_asm_807F6240[arg2], 1, arg3, &D_global_asm_807F621C, &D_global_asm_807F6220, &D_global_asm_807F6224);
}

void func_global_asm_8064B514(u8 arg0, u8 arg1, s8 arg2, s16 arg3) {
    func_global_asm_806FAC64(arg2);
    if (arg3) {
        func_global_asm_806F8D58(0xD, 0);
    } else {
        func_global_asm_806F8BC4(0xD, 1, 0); 
    }
}

void func_global_asm_8064B574(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_80726EE0(3);
}

void func_global_asm_8064B5A4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 i;

    if (arg3 != 0) {
        for (i = 0; i < D_global_asm_807F6C28; i++) {
            func_global_asm_80659670(D_global_asm_80748280.unk0, D_global_asm_80748280.unk4, D_global_asm_80748280.unk8, i);
        }
    } else {
        func_global_asm_80659620(&sp3C, &sp38, &sp34, 0);
        if (arg2 != 0) {
            sp3C = sp3C + D_global_asm_807482A4;
            sp38 = sp38 + D_global_asm_807482A4;
            if (D_global_asm_8074828C.unk0 < sp3C) {
                sp3C = D_global_asm_8074828C.unk0;
            }
            if (D_global_asm_8074828C.unk4 < sp38) {
                sp38 = D_global_asm_8074828C.unk4;
            }
            sp34 = sp34 + D_global_asm_807482A4;
            if (D_global_asm_8074828C.unk8 < sp34) {
                sp34 = D_global_asm_8074828C.unk8;
            }
        } else {
            sp3C = sp3C - D_global_asm_807482A4;
            sp38 = sp38 - D_global_asm_807482A4;
            if (sp3C < D_global_asm_80748280.unk0) {
                sp3C = D_global_asm_80748280.unk0;
            }
            if (sp38 < D_global_asm_80748280.unk4) {
                sp38 = D_global_asm_80748280.unk4;
            }
            sp34 = sp34 - D_global_asm_807482A4;
            if (sp34 < D_global_asm_80748280.unk8) {
                sp34 = D_global_asm_80748280.unk8;
            }
        }
        for (i = 0; i < D_global_asm_807F6C28; i++) {
            func_global_asm_80659670(sp3C, sp38, sp34, i);
        }
    }
}

void func_global_asm_8064B798(s32 arg0, s32 arg1, s8 arg2, s32 arg3) {
    PlayerAdditionalActorData *temp_v0 = character_change_array[0].player_pointer->PaaD;
    temp_v0->unk1FC = arg2;
}

void func_global_asm_8064B7C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_global_asm_8064B7D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void func_global_asm_8064B7E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_806612B4(5, 1);
    func_global_asm_806612B4(6, 1);
}

void func_global_asm_8064B828(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_8066134C(5, 0xFF);
    func_global_asm_8066134C(6, 0xFF);
}

void func_global_asm_8064B868(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 temp_a2 = func_global_asm_80661300(5);
    func_global_asm_8066134C(5, temp_a2 < 0xFC ? temp_a2 + 3 : 0xFF);
    func_global_asm_8066134C(6, temp_a2 < 0xFC ? temp_a2 + 3 : 0xFF);
    func_global_asm_806612B4(5, 0);
    func_global_asm_806612B4(6, 0);
}

void func_global_asm_8064B900(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    Actor *temp_v0;
    Actor *temp_v0_2;

    if (arg2 != 0) {
        if (arg2 != 1) {
            if (arg2 == 2) {
                func_global_asm_807271F4(8, 0, 0, 0, 0, 0, 0);
                last_spawned_actor->object_properties_bitfield &= -5;
            }
        } else {
            temp_v0 = func_global_asm_807270C0(8, 0);
            if (temp_v0) {
                temp_v0->object_properties_bitfield |= 4;
                func_global_asm_80614EBC(temp_v0, 0x35C);
                func_global_asm_80614D00(temp_v0, 0.9f, 0);
            }
        }
    } else {
        temp_v0_2 = func_global_asm_807270C0(8, 0);
        if (temp_v0_2) {
            temp_v0_2->control_state = 0x3C;
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064B9E0.s")

u8 func_global_asm_8064BAF4(Struct8064BAF4 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    return arg0->unk14[arg2] < arg0->unk14[arg3];
}

// TODO: This probably returns the result of func_global_asm_805FF0C8, if not, this is cursed
void func_global_asm_8064BB4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_805FF0C8();
}

// This function checks whether the key has been turned in for the map stored at D_global_asm_8076A0AB
s32 func_global_asm_8064BB78(s32 arg0, s32 arg1, s32 levelIndex, s32 arg3) {
    levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    if (levelIndex >= 8) {
        levelIndex = 0;
    }
    return isFlagSet(D_global_asm_80744710[levelIndex], FLAG_TYPE_PERMANENT);
}

u8 func_global_asm_8064BBD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (func_global_asm_806CC14C(func_global_asm_80665DE0((s16)D_global_asm_807F621C, (s16)D_global_asm_807F6224, (s16)player_pointer->x_position, (s16)player_pointer->z_position), player_pointer->y_rotation) < 0x384);
}

s32 func_global_asm_8064BCB0(s32 arg0, s32 arg1) {
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

s32 func_global_asm_8064BD2C(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    s32 sp50;
    f32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_a0;
    s32 temp_v0;
    s32 sp3C;

    temp_v0 = func_global_asm_8064BCB0(arg1, arg3);
    if (temp_v0 < 0) {
        return 0;
    } else {
        temp_a0 = D_global_asm_807F6240[arg2];
        sp3C = temp_a0;
        if (func_global_asm_8064BCB0(temp_a0, arg3) != -1) {
            return 0;
        } else {
            func_global_asm_806357F8(temp_a0, &sp5C, &sp58, &sp54, &sp50, &sp4C, &sp48, &sp44, &sp40, 1);
            func_global_asm_8067ABC0(  0, character_change_array[temp_v0].player_pointer, 9, sp4C * 11.37777805f, 
                            0, sp5C, sp58, sp54);
        }
    }
    return 0;
}

u8 func_global_asm_8064BE58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return D_global_asm_807552E8 == 5;
}

// rodata, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064BE80.s")

/*
extern s32 D_global_asm_807552F0;

void func_global_asm_806F91B4(s32, u8, s32);

s32 func_global_asm_8064BE80(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 playerIndex;
    f32 temp;

    playerIndex = func_global_asm_8064BCB0(arg1, arg2);
    if (playerIndex < 0) {
        return 0;
    }
    if (func_global_asm_806F8AD4(1, playerIndex) != 0) {
        func_global_asm_806F91B4(7, playerIndex, 1);
        temp = func_global_asm_806F8AD4(7, playerIndex);
        temp /= D_global_asm_807552F0;
        // temp *= 0.5f;
        // temp += 0.5f;
        playSound(0x2A1, 0x7FFF, 63.0f, temp * 0.5f + 0.5f, 5, 0);
        return 1;
    }
    return 0;
}
*/

s32 func_global_asm_8064BF58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f64 dz, dx;

    dz = character_change_array[0].look_at_eye_z - 1274.0;
    dx = character_change_array[0].look_at_eye_x - 3081.0;
    if (((dz * dz) + (dx * dx)) < 10000.0) {
        return TRUE;
    }
    return FALSE;
}

extern f32 D_global_asm_807F6228;

typedef struct {
    u8 unk0[0x14 - 0x0];
    f32 unk14[1]; // TODO: How many?
} Struct8064BFD0;

void func_global_asm_8064BFD0(Struct8064BFD0 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    f32 temp_f12;

    temp_f12 = ((f64)ABS(arg0->unk14[arg2]) / arg0->unk14[arg3 + 1]);
    if (arg0->unk14[arg2] > 0.0) {
        if (arg0->unk14[arg3] < temp_f12) {
            arg0->unk14[arg3] += 0.1;
        }
    } else {
        if (-temp_f12 < arg0->unk14[arg3]) {
            arg0->unk14[arg3] -= 0.1;
        }
    }
    D_global_asm_807F6228 += arg0->unk14[arg3];
    if (D_global_asm_807F6228 > 8.0) {
        D_global_asm_807F6228 = 8.0f;
    }
    if (D_global_asm_807F6228 < -8.0) {
        D_global_asm_807F6228 = -8.0f;
    }
}

extern f32 D_global_asm_807F6228;

void func_global_asm_8064C134(Struct8064BFD0 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    if (1.2 < D_global_asm_807F6228 || D_global_asm_807F6228 < -1.2) {
        if (D_global_asm_807F6228 > 0.0) {
            if (arg0->unk14[arg2] > -1.0) {
                arg0->unk14[arg2] -= 0.1;
            }
        } else {
            if (arg0->unk14[arg2] < 1.0) {
                arg0->unk14[arg2] += 0.1;
            }
        }
        D_global_asm_807F6228 += arg0->unk14[arg2];
    } else {
        D_global_asm_807F6228 = 0.0f;
        arg0->unk14[arg2] = 0.0f;
    }
}

void func_global_asm_806A5DF0(s32, f32, f32, f32, s32, s32, s32, s32);

void func_global_asm_8064C250(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0, 1, -1, 0);
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0x400, 1, -1, 0);
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0x800, 1, -1, 0);
    func_global_asm_806A5DF0(0x2F, D_global_asm_807F621C, D_global_asm_807F6220 + 15.0f, D_global_asm_807F6224, 0xC00, 1, -1, 0);
    func_global_asm_807149B8(1);
    func_global_asm_80714CC0(&D_global_asm_8071FFA0, 2.5f, D_global_asm_807F621C, D_global_asm_807F6220 + 30.0f, D_global_asm_807F6224);
}

void func_global_asm_8061EF4C(s32, s32, s32, f32, f32, f32, f32, f32);
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct8064C3E8_malloc;

typedef struct {
    Struct8064C3E8_malloc *unk0;
    u8 unk4[0x6E - 0x4];
    u8 unk6E;
} Struct8064C3E8_arg0;

void func_global_asm_8064C3E8(Struct8064C3E8_arg0 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 pad54;
    s32 pad50;
    s32 pad4C;
    s32 pad48;
    s16 pad46;
    s16 sp44;
    f32 sp40;
    u8 sp3F;
    Struct8064C3E8_malloc *var_v1;
    PlayerAdditionalActorData *sp34;

    sp34 = character_change_array->player_pointer->additional_actor_data;
    if (arg0->unk0 == NULL) {
        var_v1 = malloc(sizeof(Struct8064C3E8_malloc));
        arg0->unk0 = var_v1;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = arg0->unk0;
    func_global_asm_80650D8C(arg1, 1, &sp44, &sp40, &sp3F);
    if (sp44 == 0) {
        var_v1->unk4 = 0xA;
    }
    if (sp44 == 2 && 0.8 <= sp40) {
        if (var_v1->unk4 != 0) {
            func_global_asm_8061EF4C(sp34->unk104, 4, 0xB, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, 200.0f, 600.0f);
            var_v1->unk4--;
        }
    } else {
        var_v1->unk0 = 0;
    }
    if (sp44 == 2) {
        arg0->unk6E = 1;
    } else {
        arg0->unk6E = 0;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} Struct8064C544;

void func_global_asm_8064C544(Struct8064C544 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 sp2E;
    f32 sp28;
    u8 sp27;
    u8 sp26;

    if (arg0->unk10 >= 0) {
        func_global_asm_80650D8C(arg1, arg2, &sp2E, &sp28, &sp27);
        sp26 = D_global_asm_80770628[arg0->unk10];
        D_global_asm_80770B68[sp26] = (func_global_asm_80612794(((sp2E + sp28) * 2048.0) - 1024.0) * 0.3) + 1.3;
        D_global_asm_80770BC0[sp26] = 1.0f;
    }
}

void func_global_asm_8064C644(Struct8064C544 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp2E;
    f32 sp28;
    u8 sp27;
    u8 sp26;

    if (arg0->unk10 >= 0) {
        func_global_asm_80650D8C(arg1, 1, &sp2E, &sp28, &sp27);
        sp26 = D_global_asm_80770628[arg0->unk10];
        D_global_asm_80770B68[sp26] = func_global_asm_80612794((sp2E << 0xB) / 27) + 0.3;
        D_global_asm_80770BC0[sp26] = 2.0f;
    }
}

void func_global_asm_8064C708(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp3E;
    f32 sp38;
    u8 sp37;
    s32 *var_v1;

    if (*arg0 == NULL) {
        var_v1 = malloc(4);
        *arg0 = var_v1;
        *var_v1 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 1, &sp3E, &sp38, &sp37);
    if (*var_v1 == 0xB) {
        if (sp3E == 3) {
            *var_v1 = 3;
            func_global_asm_806085DC(arg1, 0x257, 0x78, 0x7F, 0xA, 0x50, 0.3f);
        }
    } else if (sp3E == 0xB) {
        *var_v1 = 0xB;
        func_global_asm_806085DC(arg1, 0x258, 0x78, 0x7F, 0xA, 0x50, 0.3f);
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct8064C814;

void func_global_asm_8064C814(void **arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s16 sp42;
    f32 sp3C;
    u8 sp3B;
    Struct8064C814 *var_v1;

    if (*arg0 == NULL) {
        *arg0 = malloc(sizeof(Struct8064C814));
        var_v1 = *arg0;
        var_v1->unk0 = 0;
        var_v1->unk4 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 2, &sp42, &sp3C, &sp3B);
    sp42 = (sp42 + sp3C);
    if (sp42 == 0x28 || sp42 == 0x32) {
        if (sp42 != var_v1->unk0) {
            var_v1->unk0 = sp42;
            func_global_asm_806335B0(arg1, 1, 3, &sp4C, &sp48, &sp44);
            func_global_asm_806086CC(sp4C, sp48, sp44, 0x32, 0xFF, 0x7F, 0xA, 0x50, 0.3f, 0);
        }
    }
    func_global_asm_80650D8C(arg1, 3, &sp42, &sp3C, &sp3B);
    if (sp42 == 0x14 || sp42 == 0x18) {
        if (sp42 != var_v1->unk4) {
            var_v1->unk4 = sp42;
            func_global_asm_806335B0(arg1, 1, 2, &sp4C, &sp48, &sp44);
            func_global_asm_806086CC(sp4C, sp48, sp44, 0x332, 0xFF, 0x7F, 0, 0x50, 0.3f, 0);
        }
    }
}

typedef struct {
    s32 *unk0;
} Struct8064C9F8_arg0;

void func_global_asm_8064C9F8(Struct8064C9F8_arg0 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s16 sp42;
    f32 sp3C;
    u8 sp3B;
    s32 *var_v1;

    if (arg0->unk0 == NULL) {
        arg0->unk0 = malloc(4);
        var_v1 = arg0->unk0;
        *var_v1 = 0;
    }
    var_v1 = arg0->unk0;
    func_global_asm_80650D8C(arg1, 2, &sp42, &sp3C, &sp3B);
    sp42 = sp42 + sp3C;
    if (sp42 == 0x22 || sp42 == 0x2E) {
        if (sp42 != *var_v1) {
            *var_v1 = sp42;
            func_global_asm_806335B0(arg1, 1, 2, &sp4C, &sp48, &sp44);
            func_global_asm_806086CC(sp4C, sp48, sp44, (sp42 == 0xA) + 0x257, 0xFF, 0x7F, 0xA, 0x50, 0.3f, 0);
        }
    }
}

void func_global_asm_8064CB3C(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    s16 sp4A;
    f32 sp44;
    u8 sp43;
    s32 *var_v1;
    s32 pad;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        var_v1 = *arg0;
        *var_v1 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 2, &sp4A, &sp44, &sp43);
    sp4A = sp4A + sp44;
    if (sp4A != *var_v1) {
        if (sp4A == 0 || sp4A == 0xC || sp4A == 0x18 || sp4A == 0x24) {
            *var_v1 = sp4A;
            func_global_asm_806335B0(arg1, 1, 2, &sp54, &sp50, &sp4C);
            func_global_asm_806086CC(sp54, sp50, sp4C, 0x3A, 0x50, 0x7F, 0, 0x50, 0.3f, 0);
        }
    }
}

void func_global_asm_8064CC80(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp3E;
    u32 sp38;
    u8 sp37;
    s32 *var_v1;
    s32 *sp30;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        **arg0 = 0x64;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 1, &sp3E, &sp38, &sp37);
    if (sp3E != *var_v1) {
        *var_v1 = sp3E;
        func_global_asm_806085DC(arg1, 0x129, 0xFF, 0x7F, 3, 0x50, 0.3f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064CD3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064D0C4.s")

void func_global_asm_8065092C(s16, s16);
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

/*
void func_global_asm_8064D0C4(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 sp24;
    f32 sp20;
    u8 temp_v0; // TODO: Changing this to s32 fixes the bottom of the function but breaks the stack alignment and size
    u8 sp1E;

    sp1E = 2;
    sp24 = D_global_asm_807F6220 + 20.0f;
    if (func_global_asm_80667110(D_global_asm_807F621C, D_global_asm_807F6224, &sp24)) {
        if (func_global_asm_8066715C(&sp20)) {
            if (sp20 < sp24) {
                sp1E = 0;
                D_global_asm_807F6220 = sp24;
            } else {
                sp1E = 1;
                D_global_asm_807F6220 = sp20;
            }
        }
    }
    if (arg2 != 0) {
        temp_v0 = func_global_asm_80650D04(arg1, 1);
        if (sp1E == 1 && !temp_v0) {
            func_global_asm_806508B4(arg1, 1, -1);
            func_global_asm_806508B4(arg1, 2, -1);
        } else if (sp1E == 0 && temp_v0) {
            func_global_asm_8065092C(arg1, 1);
            func_global_asm_8065092C(arg1, 2);
        }
    }
}
*/

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064D1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064D418.s")

void func_global_asm_8064D880(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 phi_f0;
    s32 levelIndex;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    phi_f0 = (f32)D_global_asm_807FC930[levelIndex] / D_global_asm_807446C0[levelIndex];
    if (phi_f0 > 1.0) {
        phi_f0 = 1.0f;
    }
    if (arg2 == 0) {
        phi_f0 = 1.0f - phi_f0;
    }
    func_global_asm_80650AD8(arg1, 1, 0, phi_f0);
    func_global_asm_80650A04(arg1, 1, 0);
}

// stack, float, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064D978.s")

typedef struct {
    u8 unk0[0x48 - 0x0];
    u8 unk48;
} Struct8064D978;

/*
void func_global_asm_8064D978(Struct8064D978 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    u8 levelIndex;
    s16 sp36;
    f32 var_f2;
    u8 sp2F;
    f32 var_f0;

    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    var_f0 = (f32)D_global_asm_807FC930[levelIndex] / D_global_asm_807446C0[levelIndex];
    if (var_f0 > 1.0) {
        var_f0 = 1.0f;
    }
    if (arg2 == 0) {
        var_f0 = 1.0f - var_f0;
    }
    func_global_asm_80650D8C(arg1, 1, &sp36, &var_f2, &sp2F);
    func_global_asm_80650A04(arg1, 1, 0);
    if (var_f0 < var_f2) {
        var_f2 -= 0.1;
        if (var_f2 < var_f0) {
            var_f2 = var_f0;
        }
    } else {
        var_f2 += 0.1;
        if (var_f0 < var_f2) {
            var_f2 = var_f0;
        }
    }
    if (arg2 != 0) {
        // Note: These two doubles come from same rodata location
        // Possibliy a macro
        if (0.999 <= var_f2) {
            if (0.999 <= var_f0) {
                arg0->unk48 = 0x14;
            }
        }
    } else {
        // Note: These two doubles come from same rodata location
        // Possibliy a macro
        if (var_f2 <= 0.001) {
            if (var_f0 <= 0.001) {
                arg0->unk48 = 0x14;
            }
        }
    }
    func_global_asm_80650AD8(arg1, 1, sp36, var_f2);
    func_global_asm_806508B4(arg1, 1, 1);
}
*/

void func_global_asm_8064DB98(s32 **arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 sp5E;
    f32 sp58;
    u8 sp57;
    s32 *var_v1;
    f32 temp_f0;
    f32 temp_f2;

    if (*arg0 == NULL) {
        *arg0 = malloc(4);
        **arg0 = 0;
    }
    var_v1 = *arg0;
    func_global_asm_80650D8C(arg1, 1, &sp5E, &sp58, &sp57);
    if (sp5E != *var_v1) {
        switch (sp5E) {
            case 0xF:
                func_global_asm_806086CC(D_global_asm_807F6000[arg1].x_position, D_global_asm_807F6000[arg1].y_position + 300.0f, D_global_asm_807F6000[arg1].z_position, 0x8E, 0xFF, 0x50, 0, 0x50, 0.3f, 0);
                break;
            case 0:
                func_global_asm_806086CC(D_global_asm_807F6000[arg1].x_position, D_global_asm_807F6000[arg1].y_position + 300.0f, D_global_asm_807F6000[arg1].z_position, 0x8F, 0xFF, 0x64, 0, 0x50, 0.3f, 0);
                break;
        }
        *var_v1 = sp5E;
    }
    temp_f0 = ((sp5E + sp58) / 31.0) * 11.0;
    temp_f2 = (temp_f0 - (s32)temp_f0) * 64.0;
    func_global_asm_80635018(arg1, 1, temp_f0, temp_f2);
    func_global_asm_80635018(arg1, 2, temp_f0, temp_f2);
    func_global_asm_80635018(arg1, 3, temp_f0, temp_f2);
    func_global_asm_80635018(arg1, 4, temp_f0, temp_f2);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064DE04.s")

extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;

typedef struct {
    s32 unk0;
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
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 unk5C;
    u8 unk5D;
    u16 unk5E;
} Struct8064DE04_arg0;

/*
// TODO: Very close, just something up with the loop
void func_global_asm_8064DE04(Struct8064DE04_arg0 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    Actor *var_s0;
    f32 dx;
    f32 dz;
    f32 temp_f14;
    f32 dy;
    f32 var_f16;
    PlayerAdditionalActorData *PaaD;
    s32 i;

    var_s0 = NULL;
    var_f16 = 99999.0f;
    PaaD = player_pointer->additional_actor_data;
    if (arg0->unk5C != 0) {
        for (i = 0; i < D_global_asm_807FBB34; i++) {
            if (arg0->unk5E == D_global_asm_807FB930[i].unk0->unk58) {
                dx = D_global_asm_807FB930[i].unk0->x_position - D_global_asm_807F621C;
                dy = D_global_asm_807FB930[i].unk0->y_position - D_global_asm_807F6220;
                dz = D_global_asm_807FB930[i].unk0->z_position - D_global_asm_807F6224;
                temp_f14 = (dx * dx) + (dy * dy) + (dz * dz);
                if (temp_f14 < var_f16) {
                    var_f16 = temp_f14;
                    var_s0 = D_global_asm_807FB930[i].unk0;
                }
            }
        }
        if (var_s0 != NULL) {
            func_global_asm_80679200(var_s0, NULL, 8, 0, 0, 0);
        }
        if (arg2 == 0) {
            if (var_s0 != NULL) {
                if (var_s0->unk58 == ACTOR_STEEL_KEG) {
                    PaaD->unk1F0 &= 0xFFDFFFFF;
                }
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064DF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064E174.s")

s32 func_global_asm_8064E174(s32, s16, s16, s32 *, s32, s32, s32);

typedef struct {
    s32 unk0;
} Struct807482DC;

typedef struct {
    u8 unk0[5];
} Struct807482E0;

typedef struct {
    u8 unk0[3];
} Struct807482E8;

typedef struct {
    s32 unk0;
} Struct807482EC;

extern Struct807482E0 D_global_asm_807482E0;
extern Struct807482E8 D_global_asm_807482E8;
extern Struct807482EC D_global_asm_807482EC;
extern Struct807482DC D_global_asm_807482DC;

void func_global_asm_8064E428(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482DC sp2C = D_global_asm_807482DC;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp2C, 4, 5, 0x14);
}

void func_global_asm_8064E48C(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482E0 sp28 = D_global_asm_807482E0;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp28, 5, 4, 0x14);
}

void func_global_asm_8064E4F8(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482E8 sp2C = D_global_asm_807482E8;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp2C, 3, 7, 0x14);
}

void func_global_asm_8064E55C(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    Struct807482EC sp2C = D_global_asm_807482EC;
    func_global_asm_8064E174(arg0, arg1, arg2, &sp2C, 3, 7, 0x14);
}

typedef struct {
    u8 unk0[0x60 - 0x0];
    u8 unk60;
    u8 unk61;
    s16 unk62;
    s16 unk64;
    u8 unk66;
} Struct8064E5C0_arg0;

void func_global_asm_8064E5C0(Struct8064E5C0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
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

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064E65C.s")

void func_global_asm_8064EA48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_global_asm_806F8AD4(1, 0) >= 2) {
        func_global_asm_806F8BC4(1, 0, 0);
        func_global_asm_806F91B4(1, 0, -2);
        // DK Arcade Level 3?
        setFlag(0x83, TRUE, FLAG_TYPE_PERMANENT);
    }
}

typedef struct global_asm_struct_7 {
    u8 unk0[0x4B];
    s8 unk4B;
} GlobalASMStruct7;

void func_global_asm_8064EAB4(GlobalASMStruct7 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 numberOfGunSwitchesPressed;

    // Fungi Mushroom Gun Switches Pressed
    // Odd that they didn't use countSetFlags() for this
    numberOfGunSwitchesPressed = isFlagSet(0xE6, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xE8, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xE9, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xE7, FLAG_TYPE_PERMANENT);
    numberOfGunSwitchesPressed += isFlagSet(0xEA, FLAG_TYPE_PERMANENT);

    arg0->unk4B = numberOfGunSwitchesPressed;
}

s32 func_global_asm_8064EB3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
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

u8 func_global_asm_8064EB9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 levelIndex = getLevelIndex(D_global_asm_8076A0AB, FALSE);
    s32 temp;
    if (levelIndex >= 8) {
        levelIndex = 0;
    }
    temp = D_global_asm_807446F0[levelIndex];
    return temp == current_character_index[0];
}

extern s16 D_global_asm_807446D0[];

u8 func_global_asm_8064EC04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 sp1E;
    sp1E = func_global_asm_80600530();
    return ((s16)func_global_asm_806FB418() >= D_global_asm_807446D0[sp1E]);
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064EC60.s")

/*
// TODO: Pretty close
u8 func_global_asm_8064EC60(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u8 sp1B;
    s32 temp_v0;
    s32 kongIndex;
    u8 phi_t0;

    phi_t0 = 0;
    switch (arg2) {
        case 3:
            kongIndex = 1;
            break;
        case 4:
            kongIndex = 2;
            break;
        case 5:
            kongIndex = 3;
            break;
        case 6:
            kongIndex = 4;
            break;
        default:
            kongIndex = 0;
            break;
    }
    temp_v0 = func_global_asm_80600530();
    if ((D_global_asm_807FC950->character_progress[kongIndex].unk5 & 0x7F) == temp_v0) {
        phi_t0 = TRUE;
        if (arg3 == 0) {
            phi_t0 = TRUE;
            if ((D_global_asm_807FC950->character_progress[kongIndex].unk5 & 0x80)) {
                phi_t0 = FALSE;
            }
        }
    } else if (temp_v0 < (D_global_asm_807FC950->character_progress[kongIndex].unk5 & 0x7F)) {
        phi_t0 = TRUE;
    }
    if (phi_t0 == TRUE) {
        if (arg3 == 2) {
            D_global_asm_807FC950->character_progress[kongIndex].unk5 = (D_global_asm_807FC950->character_progress[kongIndex].unk5 & 0x7F);
        }
    }
    return phi_t0;
}
*/

s32 func_global_asm_8064ED68(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u8 phi_s0;
    s32 phi_s3;

    phi_s3 = FALSE;
    for (phi_s0 = 2; phi_s0 < 7; phi_s0++) {
        if (!func_global_asm_8064EC60(arg0, arg1, phi_s0, 1)) {
            phi_s3 = TRUE;
        }
    }
    return phi_s3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064EE08.s")

void func_global_asm_8064F028(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0x80);
    func_global_asm_8071498C(&func_global_asm_8064EE08);
    func_global_asm_807149FC(-1);
    func_global_asm_807149B8(1);
    func_global_asm_80714998(2);
    func_global_asm_80714CC0(&D_global_asm_80721530, 0, D_global_asm_807F621C, D_global_asm_807F6220 + 17.5, D_global_asm_807F6224);
    spawnActor(ACTOR_WRINKLY, 0x53);
    last_spawned_actor->x_position = D_global_asm_807F621C;
    last_spawned_actor->y_position = D_global_asm_807F6220;
    last_spawned_actor->z_position = D_global_asm_807F6224;
    last_spawned_actor->y_rotation = (D_global_asm_807F622C * 4096.0f) / 360.0f;
    if ((current_map == MAP_FUNGI_LOBBY) || ((current_map == MAP_AZTEC_LOBBY) && (arg2 == 4))) {
        // BUG(?): This angle addition does not truncate to 4096
        last_spawned_actor->y_rotation += 0x800;
    }
    playCutscene(last_spawned_actor, 0x22, 5);
    playSong(0xAB, 1.0f);
    playSound(0x2EA, 0x7FFF, 63.0f, 1.0f, 0, 0);
    D_global_asm_807F6951 = arg2;
    D_global_asm_807F6950 = 0;
}

extern s8 D_global_asm_807F6950;
extern s8 D_global_asm_807FC8D0;

u8 func_global_asm_8064F1C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_global_asm_807F6950) {
        func_global_asm_80602B60(0xAB, 0);
    }
    return D_global_asm_807F6950;
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8064F210.s")

extern f32 D_global_asm_807F622C;

/*
u8 func_global_asm_8064F210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp2C;
    f32 temp2;
    f32 temp3;
    f32 temp4;
    s16 temp_f18;
    f32 temp_f0;
    f32 temp;

    temp_f18 = (D_global_asm_807F622C * 4096.0f) / 360.0f;
    sp2C = func_global_asm_80612794(temp_f18);
    temp_f0 = func_global_asm_80612790(temp_f18);
    temp = -((D_global_asm_807F621C * sp2C) + (D_global_asm_807F6224 * temp_f0));
    temp2 = (player_pointer->x_position * sp2C);
    return (f64)(temp2 + (player_pointer->z_position * temp_f0) + temp) > 6;
}
*/

s32 func_global_asm_8064F2F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 1;
}

void func_global_asm_8064F308(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 flagIndex;

    if (D_global_asm_807FC8D0 == 5) {
        flagIndex = 0x1C1; // Key 6 turned
    } else {
        flagIndex = 0x1C2; // Key 7 turned
    }
    setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
}

u8 func_global_asm_8064F358(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    PlayerProgress *temp = &D_global_asm_807FC950[cc_player_index];
    return temp->character_progress[current_character_index[cc_player_index]].coloured_bananas[getLevelIndex(D_global_asm_8076A0AB, 0)] > 0;
}

u8 func_global_asm_8064F404(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // Has the player collected 4 or more Battle Crowns?
    return countSetFlags(0x261, 10, FLAG_TYPE_PERMANENT) >= 4;
}
