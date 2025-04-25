#include "common.h"

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

// close, last loop is wrong somehow
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063D930.s")

extern u8 D_global_asm_807F66F0[];

/*
void func_global_asm_8063D930(void) {
    s32 i;

    for (i = 0; i < 600; i++) {
        D_global_asm_807F6240[i] = -1;
    }
    for (i = 0; i < 530; i++) {\
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

void func_global_asm_8063DED0(Prop_ScriptData *arg0) {
    s32 i = 0;
    
    for (i = 0; i < 8; i++) {
        arg0->unk14[i] = 1.0f;
    }
    arg0->unk10[0] = -1;
    arg0->unk10[1] = -1;
    arg0->unk38 = -1;
    arg0->unk0 = 0;
    arg0->unk40 = 0;
    arg0->unk42 = 0;
    arg0->unk44[0] = 0;
    arg0->unk44[1] = 0;
    arg0->unk48[0] = 0;
    arg0->unk48[1] = 0;
    arg0->unk48[2] = 0;
    arg0->next_state[0] = 0;
    arg0->next_state[1] = 0;
    arg0->next_state[2] = 0;
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

void func_global_asm_8063E078(Prop_ScriptData *arg0) {
    u8 i;

    for (i = 0; i < 2; i++) {
        if (arg0->unk44[i] != 0) {
            arg0->unk44[i]--;
        }
    }
    for (i = 0; i < 3; i++) {
        arg0->next_state[i] = arg0->unk48[i];
    }
    arg0->unk4E = 0;
}

// Doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063E0D4.s")

s32 func_global_asm_806358E8(s16, f32, f32, f32, f32, f32, f32, f32, f32, u8, s32, u8, u8, s32);
u8 func_global_asm_8063EA14(PropScriptInstruction *, Prop_ScriptData *, s16);
void func_global_asm_8063FA48(PropScriptInstruction *, Prop_ScriptData *, s16);
extern f32 D_global_asm_807F61FC;
extern f32 D_global_asm_807F6200;
extern f32 D_global_asm_807F6204;
extern f32 D_global_asm_807F6208;
extern f32 D_global_asm_807F620C;
extern f32 D_global_asm_807F6210;
extern f32 D_global_asm_807F6214;
extern f32 D_global_asm_807F6218;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C;
extern f32 D_global_asm_807F6230;
extern f32 D_global_asm_807F6234;
extern f32 D_global_asm_807F6238;
extern s16 D_global_asm_807F6904;
extern s16 D_global_asm_807F6906;
extern s16 D_global_asm_807F6908;
extern f32 D_global_asm_807F690C;
extern f32 D_global_asm_807F6910;
extern f32 D_global_asm_807F6914;

/*
void func_global_asm_8063E0D4(Prop_ScriptData *arg0, s16 arg1) {
    f32 sp78;
    f32 sp58;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s0_2;
    s32 i;
    s32 var_t0;
    s32 var_t2;
    s32 var_v0;
    s32 var_v0_2;
    u8 var_v1;
    s32 var_v1_2;
    PropScriptInstruction *var_s0;
    void *var_s1_2;
    PropScriptBlock *var_s2;

    var_s2 = arg0->unkA0;
    if (var_s2 != NULL) {
        func_global_asm_806357F8((s32) arg1, &D_global_asm_807F61FC, &D_global_asm_807F6200, &D_global_asm_807F6204, &D_global_asm_807F6208, &D_global_asm_807F620C, &D_global_asm_807F6210, &D_global_asm_807F6214, &D_global_asm_807F6218, 1U);
        func_global_asm_806357F8((s32) arg1, &D_global_asm_807F621C, &D_global_asm_807F6220, &D_global_asm_807F6224, &D_global_asm_807F6228, &D_global_asm_807F622C, &D_global_asm_807F6230, &D_global_asm_807F6234, &D_global_asm_807F6238, 1U);
        func_global_asm_8063E72C(arg0);
        D_global_asm_807F6904 = 0;
        D_global_asm_807F6908 = 0x7FFF;
        D_global_asm_807F6906 = D_global_asm_807F6908;
        D_global_asm_807F690C = D_global_asm_807F61FC;
        D_global_asm_807F6910 = D_global_asm_807F6200;
        D_global_asm_807F6914 = D_global_asm_807F6204;
        while (var_s2) {
            var_v1 = TRUE;
            for (i = 0; i < var_s2->condition_count && var_v1; i++) {
                var_s0 = &var_s2->conditions[i];
                var_v1 = func_global_asm_8063EA14(var_s0, arg0, arg1);
            }
            if (var_v1) {
                for (var_s0_2 = 0; var_s0_2 < var_s2->execution_count; var_s0_2++) {
                    func_global_asm_8063FA48(&var_s2->executions[var_s0_2], arg0, arg1);
                }
            }
            var_s2 = var_s2->next;
        }
        temp_v0 = func_global_asm_8064F84C(arg1);
        var_a0 = 0;
        sp78 = D_global_asm_807F621C;
        if (D_global_asm_807F621C != D_global_asm_807F61FC) {
            var_a0 = 1;
        }
        if ((var_a0 != 0) || (D_global_asm_807F6220 != D_global_asm_807F6200) || (D_global_asm_807F6224 != D_global_asm_807F6204) || (D_global_asm_807F6228 != D_global_asm_807F6208) || (D_global_asm_807F622C != D_global_asm_807F620C) || (D_global_asm_807F6230 != D_global_asm_807F6210) || (D_global_asm_807F6234 != D_global_asm_807F6214) || (temp_v0 != 0)) {
            var_v0 = var_a0;
            var_v1_2 = 0;
            if (D_global_asm_807F6228 != D_global_asm_807F6208) {
                var_v1_2 = 1;
            }
            var_t2 = 0;
            sp58 = D_global_asm_807F6234;
            if (D_global_asm_807F6234 != D_global_asm_807F6214) {
                var_t2 = 1;
            }
            if (var_v0 == 0) {
                var_v0 = 0;
                if (D_global_asm_807F6220 != D_global_asm_807F6200) {
                    var_v0 = 1;
                }
                if (var_v0 == 0) {
                    var_v0 = 0;
                    if (D_global_asm_807F6224 != D_global_asm_807F6204) {
                        var_v0 = 1;
                    }
                }
            }
            var_v0_2 = var_v1_2;
            if (var_v1_2 == 0) {
                var_v0_2 = 0;
                if (D_global_asm_807F622C != D_global_asm_807F620C) {
                    var_v0_2 = 1;
                }
                if (var_v0_2 == 0) {
                    var_v0_2 = 0;
                    if (D_global_asm_807F6230 != D_global_asm_807F6210) {
                        var_v0_2 = 1;
                    }
                }
            }
            var_t0 = 0;
            if (D_global_asm_807F6238 != D_global_asm_807F6218) {
                var_t0 = 1;
            }
            func_global_asm_806358E8(arg1,
                D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224,
                D_global_asm_807F6228, D_global_asm_807F622C, D_global_asm_807F6230,
                sp58, D_global_asm_807F6238,
                var_v0, var_v0_2, var_t2, var_t0, 1);
            arg0->unk4E = 1;
        }
        if (D_global_asm_807F6904 != 0) {
            func_global_asm_80632FCC(arg1, 1U);
        }
        func_global_asm_8063E5B4(arg0);
    }
}
*/

void func_global_asm_8063E5B4(Prop_ScriptData *arg0) {
    Actor *temp_v1;

    arg0->unk34 = D_global_asm_807F622C - D_global_asm_807F620C;
    arg0->unk48[0] = arg0->next_state[0];
    arg0->unk48[1] = arg0->next_state[1];
    arg0->unk48[2] = arg0->next_state[2];
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

void func_global_asm_8063E6B4(Prop_ScriptData *arg0) {
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

void func_global_asm_8063E72C(Prop_ScriptData *arg0) {
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

typedef u8 (*ScriptCheck)(Prop_ScriptData *, s16, s16, s16);
typedef void (*ScriptExec)(Prop_ScriptData *, s16, s16, s16);

typedef struct TimerData {
    Actor *unk0;
    Actor *unk4;
    u8 unk8;
} TimerData;

extern ScriptCheck D_global_asm_80748048[];
extern s16 D_global_asm_8076AEF2;
extern TimerData D_global_asm_807F61F0;
extern f32 D_global_asm_807F61FC;
extern f32 D_global_asm_807F6200;
extern f32 D_global_asm_807F6204;
extern f32 D_global_asm_807F6208;
extern f32 D_global_asm_807F620C;
extern f32 D_global_asm_807F6210;
extern f32 D_global_asm_807F6214;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern f32 D_global_asm_807F6228;
extern f32 D_global_asm_807F622C;
extern f32 D_global_asm_807F6230;
extern f32 D_global_asm_807F6234;
extern u8 D_global_asm_807F6903;
extern u8 D_global_asm_807F693E;
extern Actor *gPlayerPointer;

#define STANDING_ON_PROP(actor, actor_type, target) (!(actor->object_properties_bitfield & 0x2000)) && (temp_v0_6->unk58 == actor_type) && (actor->locked_to_pad == 1) && (target == actor->unk10C)

/*
u8 func_global_asm_8063EA14(PropScriptInstruction *arg0, Prop_ScriptData *arg1, s16 arg2) {
    u8 sp77;
    s16 temp_v0_2;
    s16 temp_v1;
    s32 temp_t3;
    s32 temp_t5;
    Actor *temp_v0_6;
    s32 obj_id;
    Actor *player;
    s16 sp5A;
    f32 sp54;
    u8 sp53;
    PlayerAdditionalActorData *PaaD;
    s32 var_a0;
    s32 temp;
    u8 var_t1;
    u8 kong;
    u8 var_a0_u8;
    
    if (arg0->instruction & 0x8000) {
        sp77 = TRUE;
    } else {
        sp77 = FALSE;
    }
    temp_v1 = arg0->instruction & 0x7FFF;
    switch (temp_v1) {
    case 0x0:
        var_t1 = TRUE;
        break;
    case 0x3D:
        var_t1 = D_global_asm_807F6903;
        break;
    case 0x3C:
        var_t1 = (character_change_array->chunk == arg0->args[0]);
        break;
    case 0x3A:
        if ((1 << arg0->args[0]) & D_global_asm_807F693E) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x39:
        if (arg0->args[0] & gPlayerPointer->unk132) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x38:
        var_t1 = current_character_index[0] < 5;
        break;
    case 0x37:
        func_global_asm_80650D8C(arg2, arg0->args[0], &sp5A, &sp54, &sp53);
        if (sp5A == arg0->args[1]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x32:
        var_t1 = D_global_asm_8076AEF2 == arg0->args[0];
        break;
    case 0x30:
        if (gPlayerPointer->unkD1 == arg0->args[0]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x35:
        if (gPlayerPointer->unkD0 == arg0->args[0]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;    
        }
        break;
    case 0x2E:
        if (func_global_asm_80689B10(arg0->args[0], 0U, 0U) == arg0->args[1]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x2D:
        var_t1 = isFlagSet(arg0->args[0], FLAG_TYPE_PERMANENT);
        break;
    case 0x36:
        var_t1 = isFlagSet(arg0->args[0], FLAG_TYPE_TEMPORARY);
        break;
    case 0x3B:
        var_t1 = isFlagSet(arg0->args[0], FLAG_TYPE_GLOBAL);
        break;
    case 0x2C:
        if (func_global_asm_80689BAC(arg0->args[0])) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x28:
        if (arg1->unk9A & 1) {
            var_t1 = FALSE;
        } else {
            var_t1 = TRUE;
        }
        break;
    case 0x26:
        PaaD = character_change_array->playerPointer->PaaD;
        if (PaaD->unk1F0 & (arg0->args[1] + (arg0->args[0] << 0x10))) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x27:
        PaaD = character_change_array->playerPointer->PaaD;
        if (PaaD->unk1F0 & (arg0->args[1] + (arg0->args[0] << 0x10))) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x25:
        if (D_global_asm_807FD568->simian_slam >= arg0->args[0]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x34:
        kong = func_global_asm_806C8D2C(arg0->args[0]);
        if (D_global_asm_807FC950[cc_player_index].character_progress[kong].moves >= arg0->args[1]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x24:
        temp_v0_6 = getSpawnerTiedActor(arg0->args[0], 0U);
        if (temp_v0_6->control_state == arg0->args[1]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x23:
        if (is_cutscene_active == 1) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x1D:
        if (((arg0->args[0] == 0) && (arg1->unk48[arg0->args[2]] < arg0->args[1])) || ((arg0->args[0] == 1) && (arg0->args[1] < arg1->unk48[arg0->args[2]]))) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x1C:
        temp_v0_2 = func_global_asm_80650A70(arg2, arg0->args[0]);
        if (((arg0->args[1] == 0) && (temp_v0_2 <  arg0->args[2])) || ((arg0->args[1] == 1) && ( arg0->args[2] < temp_v0_2))) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x16:
        temp_t3 = arg0->args[1] + (arg0->args[0] << 0x10);
        if (global_properties_bitfield & temp_t3) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x15:
        var_t1 = func_global_asm_80650D04(arg2, arg0->args[0]);
        break;
    case 0xC:
    if ((D_global_asm_807F621C != D_global_asm_807F61FC) || (D_global_asm_807F6220 != D_global_asm_807F6200) || (D_global_asm_807F6224 != D_global_asm_807F6204) || (D_global_asm_807F6228 != D_global_asm_807F6208) || (D_global_asm_807F622C != D_global_asm_807F620C) || (D_global_asm_807F6230 != D_global_asm_807F6210) || (D_global_asm_807F6234 != D_global_asm_807F6214)) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x8:
        var_t1 = arg1->unk51;
        break;
    case 0x9:
        if (arg1->unk52 != 0) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x7:
        var_t1 = func_global_asm_80642500(&arg1->unk14, arg0->args[0], arg0->args[1]);
        break;
    case 0x31:
        obj_id = func_global_asm_80659470(D_global_asm_807F6240[arg0->args[0]]);
        if (D_global_asm_807F6000[obj_id].unk7C->unk48[arg0->args[2]] == arg0->args[1]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x1:
        if (arg1->unk48[arg0->args[1]] == arg0->args[0]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x5:
        var_t1 = func_global_asm_806425FC(arg0->args[0], arg0->args[1]);
        break;
    case 0x4:
        var_t1 = FALSE;
        if (arg1->unk44[arg0->args[1]] == arg0->args[0]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x2:
        var_t1 = FALSE;
        for (var_a0_u8 = 0; var_a0_u8 < cc_number_of_players; var_a0_u8++) {
            if (character_change_array[var_a0_u8].does_player_exist) {
                player = character_change_array[var_a0_u8].playerPointer;
                if ((player->locked_to_pad == 1) && (arg2 == player->unk10C)) {
                    var_t1 = TRUE;
                }
            }
        }
        break;
    case 0xD:
        var_t1 = FALSE;
        for (var_a0_u8 = 0; var_a0_u8 < cc_number_of_players; var_a0_u8++) {
            if (character_change_array[var_a0_u8].does_player_exist) {
                player = character_change_array[var_a0_u8].playerPointer;
                if ((player->locked_to_pad == 1) && (arg2 == player->unk10C) && (player->unk10E == arg0->args[0])) {
                    var_t1 = TRUE;
                }
            }
        }
        break;
    case 0x11:
        temp = FALSE;
        for (var_a0 = 0; var_a0 < D_global_asm_807FBB34 && !temp; var_a0++) {
            temp_v0_6 = D_global_asm_807FB930[var_a0].unk0;
            if (STANDING_ON_PROP(temp_v0_6, arg0->args[0], arg2)) {
                temp = TRUE;
            }

        }
        if (temp) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x12:
        temp = FALSE;
        for (var_a0 = 0; var_a0 < D_global_asm_807FBB34; var_a0++) {
            temp_v0_6 = &D_global_asm_807FB930[var_a0].unk0;
            if (STANDING_ON_PROP(temp_v0_6, arg0->args[0], arg2)) {
                if (temp_v0_6->unk10E == arg0->args[1]) {
                    temp = TRUE;
                }
            }
        }
        if (temp) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x14:
        temp = 0;
        for (var_a0 = 0; var_a0 < D_global_asm_807FBB34; var_a0++) {
            temp_v0_6 = D_global_asm_807FB930[var_a0].unk0;
            if (!(temp_v0_6->object_properties_bitfield & 0x2000)) {
                if (temp_v0_6->unk58 == arg0->args[0]) {
                    if (arg2 == temp_v0_6->unk10C) {
                        if (temp_v0_6->unk10E == arg0->args[1]) {
                            temp++;
                        }
                    }
                }
            }
        }
        if (temp == arg0->args[2]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0xB:
        var_t1 = FALSE;
        for (var_a0_u8 = 0; var_a0_u8 < cc_number_of_players; var_a0_u8++) {
            if (character_change_array[var_a0_u8].does_player_exist != 0) {
                player = character_change_array[var_a0_u8].playerPointer;
                if ((player->locked_to_pad == 3) && (player->unk12F == arg0->args[0]) && (arg2 == player->unk10C)) {
                    var_t1 = TRUE;
                }
            }
        }
        break;
    case 0xA:
        var_t1 = FALSE;
        for (var_a0_u8 = 0; var_a0_u8 < cc_number_of_players; var_a0_u8++) {
            if (character_change_array[var_a0_u8].does_player_exist != 0) {
                player = character_change_array[var_a0_u8].playerPointer;
                if ((player->locked_to_pad == 2) && (arg2 == player->unk10C)) {
                    var_t1 = TRUE;
                } else {
                    var_t1 = FALSE;
                }
            }
        }
        break;
    case 0xE:
        var_t1 = func_global_asm_80641F70(arg0->args[0]);
        break;
    case 0x13:
        var_t1 = func_global_asm_80642204(arg0->args[0]);
        break;
    case 0x20:
        var_t1 = func_global_asm_806422D8(arg0->args[0]);
        break;
    case 0x29:
        var_t1 = func_global_asm_806423A8(arg0->args[0], arg0->args[1],  arg0->args[2]);
        break;
    case 0x6:
        var_t1 = D_global_asm_80748048[arg0->args[0]](arg1, arg2, arg0->args[1],  arg0->args[2]);
        break;
    case 0xF:
        var_t1 = func_global_asm_80723C98(arg1->unk38);
        break;
    case 0x10:
        if ((arg1->unk5C != 0) && ((arg0->args[1] == -1) || (arg1->unk5C == arg0->args[1])) && (func_global_asm_8067ACC0(arg1->unk5E) & arg0->args[0]) && (func_global_asm_806419F8() != 0)) {
            func_global_asm_80641724(D_global_asm_807F6000[func_global_asm_80659470((s32) arg2)].object_type);
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x18:
        if ((arg1->unk5C != 0) && ((arg0->args[1] == -1) || (arg1->unk5C == arg0->args[1])) && (arg1->unk5E == arg0->args[0]) && (func_global_asm_806419F8() != 0)) {
            func_global_asm_80641724(D_global_asm_807F6000[func_global_asm_80659470((s32) arg2)].object_type);
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x17:
        var_t1 = FALSE;
        for (var_a0_u8 = 0; var_a0_u8 < cc_number_of_players; var_a0_u8++) {
            if (character_change_array[var_a0_u8].does_player_exist != 0) {
                player = character_change_array[var_a0_u8].playerPointer;
                if (player->control_state == arg0->args[0]) {
                    if (arg0->args[1]) {
                        if (arg0->args[1] == player->control_state_progress) {
                            var_t1 = TRUE;
                        }
                    } else {
                        var_t1 = TRUE;
                    }
                }
            }
        }
        break;
    case 0x21:
        var_t1 = FALSE;
        for (var_a0_u8 = 0; var_a0_u8 < cc_number_of_players; var_a0_u8++) {
            if (character_change_array[var_a0_u8].does_player_exist != 0) {
                if (character_change_array[var_a0_u8].playerPointer->control_state_progress == arg0->args[0]) {
                    var_t1 = TRUE;
                }
            }
        }
        break;
    case 0x19:
        if (gPlayerPointer->unk58 == arg0->args[0]) {
            var_t1 = TRUE;
        } else {
            var_t1 = FALSE;
        }
        break;
    case 0x1A:
        var_t1 = character_change_array->unk2C0 == arg0->args[0];
        break;
    case 0x1B:
        var_t1 = character_change_array->unk2C1;
        break;
    case 0x1E:
        var_t1 = func_global_asm_80726D7C(arg0->args[0]);
        break;
    case 0x2F:
        var_t1 = func_global_asm_80726DC0(arg0->args[0]);
        break;
    case 0x1F:
        var_t1 = FALSE;
        break;
    case 0x22:
        var_t1 = func_global_asm_806F70A8(arg0->args[0]);
        break;
    case 0x2A:
        if (D_global_asm_807F61F0.unk8 != 0) {
            if (D_global_asm_807F61F0.unk0->control_state == 5) {
                var_t1 = TRUE;
            } else {
                var_t1 = FALSE;
            }
        } else {
            var_t1 = TRUE;
        }
        break;
    case 0x2B:
        var_t1 = D_global_asm_807F61F0.unk8;
        break;
    case 0x33:
        temp_v1 = func_global_asm_80614A54(gPlayerPointer);
        var_t1 = FALSE;
        if ((arg0->args[0] == 0) && (arg0->args[1] < temp_v1)) {
            var_t1 = TRUE;
        }
        if ((arg0->args[0] == 1) && (temp_v1 < arg0->args[1])) {
            var_t1 = TRUE;
        }
        break;
    default:
        var_t1 = FALSE;
        break;
    }
    if (sp77) {
        var_t1 = 1 - var_t1;
    }
    return var_t1;
}
*/

// Jumptable, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_42630/func_global_asm_8063FA48.s")


void func_global_asm_805FF9AC(s16, s16, s16, s16);
s16 func_global_asm_80605044(s16, s16, s32, s32, f32, s32);
void func_global_asm_8061F510(u8, u8);
// void func_global_asm_80641DA0(GlobalASMStruct44 *, s16, s16, s16);
// void func_global_asm_80642748(s16, s16, Struct80642844 *, s32, u8);
// void func_global_asm_80642844(s16, s16, Struct80642844 *, s32, u8);
void func_global_asm_806A2A10(s32, s32, s32);
void func_global_asm_806F4F50(s16, f32, f32, f32);
void func_global_asm_807238D4(s32, f32 *, f32 *, f32 *);
extern s8 D_global_asm_80744824;
extern ScriptExec D_global_asm_80747E70[];
extern s8 D_global_asm_80748094;
extern s16 D_global_asm_8074809C[];
extern s16 D_global_asm_807480AC[];
extern s16 D_global_asm_807480BC[];
extern Actor *D_global_asm_807F61F4;
extern f32 D_global_asm_807F61FC;
extern f32 D_global_asm_807F6204;
extern f32 D_global_asm_807F6218;
extern f32 D_global_asm_807F621C;
extern f32 D_global_asm_807F6220;
extern f32 D_global_asm_807F6224;
extern s8 D_global_asm_807F6902;
extern s16 D_global_asm_807F6904;
extern s16 D_global_asm_807F6906;
extern s16 D_global_asm_807F6908;
extern f32 D_global_asm_807F690C;
extern f32 D_global_asm_807F6910;
extern f32 D_global_asm_807F6914;
extern s16 D_global_asm_807F6918[];
extern u8 D_global_asm_807F6938;
extern s16 D_global_asm_807F693A;
extern s16 D_global_asm_807F693C;
extern u8 D_global_asm_807F693E;
extern Actor *gCurrentActorPointer;
extern Actor *gLastSpawnedActor;
extern s32 D_global_asm_807FBB68;

/*
void func_global_asm_8063FA48(PropScriptInstruction *arg0, Prop_ScriptData *arg1, s16 arg2) {
    u8 spC3;
    s32 spBC;
    u8 spB3;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    s32 sp70;
    s16 sp6E;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    u8 sp55;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    s32 sp3C;
    GlobalASMStruct53 *sp38;
    Actor *temp_a0_2;
    Actor *temp_s0;
    Actor *temp_s0_2;
    Actor *temp_s0_5;
    GlobalASMStruct53 *temp_t1;
    GlobalASMStruct53 *temp_t1_2;
    GlobalASMStruct53 *var_v0;
    GlobalASMStruct53 *var_v0_2;
    Prop_ScriptData *temp_a0_6;
    f64 var_f10;
    f64 var_f16;
    f64 var_f8;
    s16 temp_a0;
    s16 temp_a0_3;
    s16 temp_a0_4;
    s16 temp_a0_5;
    s16 temp_a0_7;
    s16 temp_a2;
    s16 temp_s1;
    s16 temp_t5;
    s16 temp_v0_10;
    s16 temp_v0_11;
    s16 temp_v0_12;
    s16 temp_v0_13;
    s16 temp_v0_15;
    s16 temp_v0_16;
    s16 temp_v0_7;
    s16 temp_v1;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 temp_v1_5;
    s16 temp_v1_6;
    s16 var_a2;
    s16 var_a2_2;
    s32 temp_s0_3;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 var_a2_3;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_s0;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t1;
    s32 var_t2;
    u8 var_t2_2;
    u16 temp_t6;
    u16 var_v1;
    u8 temp_s0_4;
    PlayerAdditionalActorData *temp_v0;
    void *temp_v0_14;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;

    temp_t6 = arg0->instruction;
    var_a3 = 0;
    switch (temp_t6) {
    case 0x95:
        D_global_asm_807F693C = 0x80;
        return;
    case 0x92:
        temp_v0 = character_change_array->playerPointer->PaaD;
        temp_v0->unk1F0 = (s32) (temp_v0->unk1F0 | 0x40000800);
        return;
    case 0x91:
        gPlayerPointer->unkB8 = (f32) arg0->args[0];
        return;
    case 0x93:
        func_global_asm_8061F510(arg0->args[0], arg0->args[1]);
        return;
    case 0x94:
        func_global_asm_80724994(2U, arg0->args[0], 0, 0, 0);
        return;
    case 0x90:
        D_global_asm_807F6902 = (s8) arg0->args[0];
        return;
    case 0x96:
        D_global_asm_807F6903 = (s8) arg0->args[0];
        return;
    case 0x8E:
        func_global_asm_8066C904(&D_global_asm_807F6000[func_global_asm_80659470((s32) arg2)].unk28);
        return;
    case 0x8F:
        func_global_asm_806348B4(&D_global_asm_807F6000[func_global_asm_80659470((s32) arg2)].unk48);
        return;
    case 0x85:
        func_global_asm_8062D1A8();
        return;
    case 0x83:
        func_global_asm_806FB370(arg0->args[0], arg0->args[1], arg0->args[2]);
        return;
    case 0x80:
        func_global_asm_8060DEC8();
        return;
    case 0x81:
        D_global_asm_807F693E |= 1 << arg0->args[0];
        return;
    case 0x82:
        D_global_asm_807F693E &= ~(1 << arg0->args[0]);
        return;
    case 0x7F:
        temp_v1 = arg0->args[1];
        switch (temp_v1) {                          // switch 1; irregular
        case 0:                                     // switch 1
            spB3 = 0;
            break;
        case 1:                                     // switch 1
            spB3 = 1;
            break;
        case 2:                                     // switch 1
            spB3 = 2;
            break;
        case 3:                                     // switch 1
            spB3 = 3;
            break;
        }
        func_global_asm_8072EE0C((Actor *) arg2, arg0->args[0], spB3);
        return;
    case 0x7C:
        D_global_asm_80748094 = (s8) arg0->args[0];
        return;
    case 0x7B:
        func_global_asm_806335B0((s32) arg2, 1U, (s32) arg0->args[1], &spAC, &spA8, &spA4);
        func_global_asm_8072ECFC((s32) arg0->args[0], (s16) (s32) spAC, (s16) (s32) spA8, (s16) (s32) spA4);
        return;
    case 0x7A:
        func_global_asm_80661264((s32) arg0->args[0], arg0->args[1]);
        return;
    case 0x76:
        var_v0 = D_global_asm_807FB930;
        for (var_t0 = 0; var_t0 < D_global_asm_807FBB34; var_t0++) {
            temp_s0 = var_v0->unk0;
            if (!(temp_s0->object_properties_bitfield & 0x2000) && (temp_s0->locked_to_pad == 1) && (arg2 == temp_s0->unk10C)) {
                sp38 = var_v0;
                spBC = var_t0;
                func_global_asm_80679200(temp_s0, NULL, 8, 0U, 0, NULL);
            }
            var_v0 += 8;
        }
    default:
        return;
    case 0x75:
        func_global_asm_8072EC94((s32) arg0->args[0], arg0->args[1]);
        return;
    case 0x78:
        func_global_asm_806335B0((s32) arg2, 1U, (s32) arg0->args[0], &spA0, &sp9C, &sp98);
        temp_v0 = character_change_array->playerPointer->PaaD;
        temp_v0->unk22C = spA0;
        temp_v0->unk230 = sp9C;
        temp_v0->unk234 = sp98;
        return;
    case 0x74:
        arg1->unk9B = (u8) (arg1->unk9B | arg0->args[0]);
        return;
    case 0x73:
        func_global_asm_806EB178(0, (s32) arg0->args[0], (s32) arg0->args[1], (s32) arg0->args[2]);
        return;
    case 0x72:
        func_global_asm_80689B10(arg0->args[0], arg0->args[1], 1U);
        return;
    case 0x6E:
        D_global_asm_807F693F = (s8) arg0->args[0];
        return;
    case 0x6D:
        func_global_asm_8063A8C4(arg2, 1U, (f32) ((f64) arg0->args[0] / 100.0));
        return;
    case 0x6C:
        func_global_asm_80631B8C(arg0->args[0]);
        return;
    case 0x6B:
        setFlag(arg0->args[0], arg0->args[1], 0U);
        return;
    case 0x79:
        setFlag(arg0->args[0], arg0->args[1], 2U);
        return;
    case 0x84:
        setFlag(arg0->args[0], arg0->args[1], 1U);
        return;
    case 0x66:
        if (D_global_asm_807F61F0.unk8 == 0) {
            spawnActor(ACTOR_TIMER_CONTROLLER, 0);
            temp_s0_2 = gCurrentActorPointer;
            D_global_asm_807F61F0.unk4 = (Actor *) gLastSpawnedActor;
            gCurrentActorPointer = gLastSpawnedActor;
            func_global_asm_806A2A10(0xDC, 0x2A, arg0->args[0]);
            D_global_asm_807F61F0.unk8 = 1U;
            D_global_asm_807F61F0.unk0 = (Actor *) gLastSpawnedActor;
            gCurrentActorPointer = temp_s0_2;
            return;
        }
        break;
    case 0x67:
        if (D_global_asm_807F61F0.unk8 != 0) {
            func_global_asm_806A2B08(D_global_asm_807F61F0.unk0);
            return;
        }
        break;
    case 0x68:
        if (D_global_asm_807F61F0.unk8 != 0) {
            deleteActor(D_global_asm_807F61F0.unk0);
            deleteActor(D_global_asm_807F61F4);
            D_global_asm_807F61F0.unk8 = 0U;
            return;
        }
        break;
    case 0x62:
        D_global_asm_807F693A = arg0->args[0];
        return;
    case 0x60:
        func_global_asm_8065F134((s32) arg2, arg0->args[0]);
        return;
    case 0x5F:
        temp_v0 = character_change_array->playerPointer->PaaD;
        temp_v0->unk1F0 |= ((arg0->args[0] << 0x10) + arg0->args[1]);
        return;
    case 0x3B:
        temp_v0 = character_change_array->playerPointer->PaaD;
        temp_v0->unk1F0 &= ~((arg0->args[0] << 0x10) + arg0->args[1]);
        return;
    case 0x8C:
        temp_v0 = character_change_array->playerPointer->PaaD;
        temp_v0->unk1F4 |= ((arg0->args[0] << 0x10) + arg0->args[1]);
        return;
    case 0x8B:
        temp_v0 = character_change_array->playerPointer->PaaD;
        temp_v0->unk1F4 &= ~((arg0->args[0] << 0x10) + arg0->args[1]);
        return;
    case 0x5D:
        func_global_asm_805FF158(arg0->args[0]);
        return;
    case 0x5C:
        func_global_asm_80724A9C(arg0->args[0], arg0->args[1], arg0->args[2]);
        return;
    case 0x5B:
        func_global_asm_806C92C4((s32) arg0->args[0]);
        return;
    case 0x5A:
        arg1->unk68 = (s16) arg0->args[0];
        arg1->unk6A = (s16) arg0->args[1];
        arg1->unk6C = (s16) arg0->args[2];
        return;
    case 0x57:
        func_global_asm_80659620(&sp94, &sp90, &sp8C, D_global_asm_807F693A);
        func_global_asm_80659670((f32) (((f64) arg0->args[0] / 1000.0) + (f64) sp94), (f32) (((f64) arg0->args[1] / 1000.0) + (f64) sp90), (f32) (((f64) arg0->args[2] / 1000.0) + (f64) sp8C), D_global_asm_807F693A);
        return;
    case 0x4F:
        if (D_global_asm_807F6938 != 0x10) {
            temp_v0_7 = arg0->args[0];
            if (temp_v0_7 != -2) {
                D_global_asm_807F6918[D_global_asm_807F6938] = temp_v0_7;
                D_global_asm_807F6938 += 1;
                return;
            }
            D_global_asm_807F6918[D_global_asm_807F6938] = D_global_asm_807F6000[func_global_asm_80659470((s32) arg2)].unk8A;
            D_global_asm_807F6938 += 1;
            return;
        }
        break;
    case 0x50:
        temp_a0 = D_global_asm_807F6240[arg0->args[0]];
        if (temp_a0 != -1) {
            func_global_asm_806335B0((s32) temp_a0, 1U, (s32) arg0->args[1], &D_global_asm_807F690C, &D_global_asm_807F6910, &D_global_asm_807F6914);
            return;
        }
        break;
    case 0x4E:
        temp_s0_3 = func_global_asm_807146A4((s32) arg0->args[0]);
        func_global_asm_807149B8(1U);
        func_global_asm_80714B84((void *) temp_s0_3, (f32) ((f64) arg0->args[1] / 100.0), (s32) arg2, (s32) arg0->args[2], 0U);
        return;
    case 0x4C:
        var_a2 = func_global_asm_80650A70(arg2, arg0->args[0]) + arg0->args[1];
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        func_global_asm_80650A04(arg2, arg0->args[0], var_a2);
        return;
    case 0x4B:
        func_global_asm_8072ED9C((Actor *) arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x46:
        arg1->unk70 = (s8) arg0->args[0];
        return;
    case 0x47:
        arg1->unk71 = (s8) arg0->args[0];
        return;
    case 0x4A:
        func_global_asm_8063393C((s32) arg2, 1U, arg0->args[0], arg0->args[1]);
        return;
    case 0x45:
        arg1->unk60 = (s8) arg0->args[0];
        arg1->unk62 = (s16) arg0->args[1];
        arg1->unk66 = (s8) arg0->args[2];
        return;
    case 0x40:
        global_properties_bitfield |= ((u16) arg0->args[0] << 0x10) + (u16) arg0->args[1];
        return;
    case 0x88:
        D_global_asm_807FBB68 |= ((u16) arg0->args[0] << 0x10) + (u16) arg0->args[1];
        return;
    case 0x89:
        D_global_asm_807FBB68 &= ~(((u16) arg0->args[0] << 0x10) + (u16) arg0->args[1]);
        return;
    case 0x3F:
        arg1->unk6E = (s8) arg0->args[0];
        return;
    case 0x3E:
        arg1->unk6F = (s8) arg0->args[0];
        return;
    case 0x3D:
        arg1->unk67 = (s8) arg0->args[0];
        return;
    case 0x39:
        arg1->unk4F = (s8) arg0->args[0];
        return;
    case 0x36:
        func_global_asm_80641BCC(arg0->args[0], arg0->args[1], arg2);
        return;
    case 0x35:
        func_global_asm_80641C98(arg0->args[0], arg0->args[1], arg2);
        return;
    case 0x33:
        func_global_asm_8062B86C((s32) arg0->args[0], (f32) arg0->args[1], (f32) arg0->args[2] / 100.0f);
        return;
    case 0x55:
        func_global_asm_8062B630(arg0->args[0], arg0->args[1]);
        return;
    case 0x34:
        func_global_asm_8062B8A4((s32) arg0->args[0], (f32) arg0->args[1], (f32) arg0->args[2] / 100.0f);
        return;
    case 0x6A:
        func_global_asm_806613E8((s32) arg0->args[0], (f32) arg0->args[1], (f32) arg0->args[2] / 100.0f);
        return;
    case 0x69:
        func_global_asm_80661398((s32) arg0->args[0], (f32) arg0->args[1], (f32) arg0->args[2] / 100.0f);
        return;
    case 0x26:
        func_global_asm_8064199C(arg1, (s8) arg0->args[0], arg0->args[1]);
        return;
    case 0x54:
        temp_v0_8 = func_global_asm_80659470((s32) D_global_asm_807F6240[arg0->args[0]]);
        if (temp_v0_8 != -1) {
            func_global_asm_8064199C((Struct8064199C_arg0 *) D_global_asm_807F6000[temp_v0_8].unk7C, (s8) arg0->args[1], arg0->args[2]);
            return;
        }
        break;
    case 0x25:
        func_global_asm_80641DA0(arg1, arg0->args[0], arg0->args[1], arg0->args[2]);
        return;
    case 0x3C:
        temp_a0_2 = arg1->unk94;
        if (temp_a0_2 != NULL) {
            deleteActor(temp_a0_2);
            arg1->unk94 = NULL;
            return;
        }
        break;
    case 0x30:
        func_global_asm_805FF378((enum map_e) arg0->args[0], 0);
        return;
    case 0x86:
        func_global_asm_806CF398(gCurrentPlayer);
        func_global_asm_805FF9AC(0x2A, 0, arg0->args[0], 2);
        return;
    case 0x87:
        func_global_asm_805FF898();
        return;
    case 0x8D:
        D_global_asm_80744824 = 2;
        func_global_asm_806CF398(gCurrentPlayer);
        temp_s0_4 = getLevelIndex(current_map, 0U);
        if (func_global_asm_805FEF74(current_map) != 0) {
            temp_v0_9 = temp_s0_4 * 2;
            temp_a2 = D_global_asm_807480AC[temp_s0_4];
            temp_s1 = D_global_asm_8074809C[temp_s0_4];
            sp70 = (s32) temp_a2;
            var_a2_2 = temp_a2;
            if (!isFlagSet(D_global_asm_807480BC[temp_s0_4], FLAG_TYPE_PERMANENT)) {
                var_a2_2 = 0;
                if (temp_s1 == 0x57) {
                    var_a2_2 = 0x15;
                }
            }
            sp70 = (s32) var_a2_2;
            if (func_global_asm_8068ABE0(temp_s1) == 0) {
                func_global_asm_805FF378((enum map_e) temp_s1, (s32) var_a2_2);
                return;
            }
        } else {
            func_global_asm_80600044((s32) temp_s0_4);
            return;
        }
        break;
    case 0x31:
        if (arg0->args[2] & 0x100) {
            setIntroStoryPlaying(2U);
            func_global_asm_805FF158(0U);
        }
        temp_v1_2 = arg0->args[2] & 0xFF;
        switch (temp_v1_2) {                        // switch 2; irregular
        case 0:                                     // switch 2
            sp6E = 0;
            break;
        case 1:                                     // switch 2
            sp6E = 1;
            break;
        case 2:                                     // switch 2
            sp6E = 3;
            break;
        }
        func_global_asm_805FF9AC(arg0->args[0], arg0->args[1], 0, sp6E);
        return;
    case 0x32:
        func_global_asm_805FF628((enum map_e) arg0->args[0], (s32) arg0->args[1]);
        return;
    case 0x2F:
        func_global_asm_8060B49C(gCurrentPlayer, (s32) arg0->args[0]);
        return;
    case 0x11:
        func_global_asm_806508B4(arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x12:
        func_global_asm_8065092C(arg2, arg0->args[0]);
        return;
    case 0x13:
        func_global_asm_80650998(arg2, arg0->args[0]);
        return;
    case 0x14:
        func_global_asm_80650A04(arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x15:
        func_global_asm_80650B50(arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x16:
        func_global_asm_80650BBC(arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x17:
        func_global_asm_80650C28(arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x18:
        func_global_asm_80650C98(arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x1A:
        func_global_asm_80650AD8(arg2, arg0->args[0], arg0->args[1], (f32) ((f64) arg0->args[2] / 100.0));
        return;
    case 0xE:
        temp_v1_3 = arg0->args[1];
        temp_v0_10 = arg0->args[2];
        var_t2 = (temp_v1_3 / 128) & 0xFF;
        if (var_t2 == 0) {
            var_t2 = 0x7F;
        }
        if (!((temp_v0_10 / 128) & 0xFF)) {

        }
        if (arg1->unk10[temp_v1_3 & 1] < 0) {
            var_f8 = (f64) var_t2;
            if (var_t2 < 0) {
                var_f8 += 4294967296.0;
            }
            sp38 = temp_t1;
            arg1->unk10[temp_v1_3 & 1] = func_global_asm_80605044(arg2, arg0->args[0], temp_v0_10 & 0x7F, temp_v1_3 & 2, (f32) (var_f8 / 127.0), 0);
            return;
        }
        break;
    case 0x7D:
        temp_v1_4 = arg0->args[1];
        temp_v0_11 = arg0->args[2];
        var_t2_2 = (temp_v1_4 / 128);
        if (var_t2_2 == 0) {
            var_t2_2 = 0x7F;
        }
        if (!((temp_v0_11 / 128) & 0xFF)) {

        }
        if (arg1->unk10[temp_v1_4 & 1] < 0) {
            arg1->unk10[temp_v1_4 & 1] = func_global_asm_80605044(arg2, arg0->args[0], temp_v0_11 & 0x7F, temp_v1_4 & 2, (f32) (var_t2_2 / 127.0), (s32) D_global_asm_80748094);
            return;
        }
        break;
    case 0xF:
        temp_v1_5 = arg0->args[1];
        temp_v0_12 = arg0->args[2];
        var_a3_2 = (temp_v1_5 / 128) & 0xFF;
        var_a2_3 = (temp_v0_12 / 128) & 0xFF;
        if (var_a3_2 == 0) {
            var_a3_2 = 0x7F;
        }
        if (var_a2_3 == 0) {
            var_a2_3 = 0xFF;
        }
        playSoundAtProp(arg2, arg0->args[0], var_a2_3, var_a3_2, temp_v1_5 & 0x7F, temp_v0_12 & 0x7F, 0.3f);
        return;
    case 0x7E:
        temp_v1_6 = arg0->args[1];
        temp_v0_13 = arg0->args[2];
        var_t1 = (temp_v1_6 / 128) & 0xFF;
        var_s0 = (temp_v0_13 / 128) & 0xFF;
        if (var_t1 == 0) {
            var_t1 = 0x7F;
        }
        if (var_s0 == 0) {
            var_s0 = 0xFF;
        }
        if (D_global_asm_80748094 > 0) {
            sp3C = var_t1;
            spBC = temp_v1_6 & 0x7F;
            sp55 = temp_v0_13 & 0x7F;
            func_global_asm_806335B0((s32) arg2, 1U, (s32) D_global_asm_80748094, &sp60, &sp5C, &sp58);
            playSoundAtPosition(sp60, sp5C, sp58, arg0->args[0], (u8) var_s0, (s16) sp3C, (u8) spBC, (u8) (s32) sp55, 0.3f, 0U);
            return;
        }
        var_f16 = (f64) var_t1;
        if (var_t1 < 0) {
            var_f16 += 4294967296.0;
        }
        playSound(arg0->args[0], 0x7FFFU, 63.0f, (f32) (var_f16 / 127.0), 0, 0);
        return;
    case 0x10:
        temp_a0_3 = arg1->unk10[arg0->args[1]];
        if (temp_a0_3 >= 0) {
            func_global_asm_80605380(temp_a0_3);
            arg1->unk10[arg0->args[1]] = -1;
            return;
        }
        break;
    case 0x48:
        func_global_asm_80604BE8(arg1->unk10[arg0->args[0]], (f32) ((f64) arg0->args[1] * 0.0001220703125), (f32) arg0->args[2]);
        return;
    case 0xA:
        arg1->unk50 = (s8) arg0->args[0];
        arg1->unk78 = (f32) ((f32) arg0->args[1] / 100.0f);
        arg1->unk7C = (f32) ((f32) arg0->args[2] / 100.0f);
        return;
    case 0xB:
        arg1->unk80 = (s16) (s32) (f32) arg0->args[0];
        arg1->unk82 = (s16) (s32) (f32) arg0->args[1];
        return;
    case 0xC:
        arg1->unk84 = (s16) (s32) (f32) arg0->args[0];
        arg1->unk86 = (s16) (s32) (f32) arg0->args[1];
        return;
    case 0xD:
        arg1->unk88 = (s16) (s32) (f32) arg0->args[0];
        arg1->unk8A = (s16) (s32) (f32) arg0->args[1];
        return;
    case 0x9:
        if ((D_global_asm_807F621C != D_global_asm_807F61FC) || (D_global_asm_807F6224 != D_global_asm_807F6204)) {
            func_global_asm_80642480(arg0->args[0], (s32) arg2);
            return;
        }
        break;
    case 0x41:
        D_global_asm_807F6904 = 1;
        return;
    case 0x6:
        arg1->unk0[arg0->args[0]].unk14 = (f32) ((f32) arg0->args[1] / 10.0f);
        return;
    case 0x0:
        func_global_asm_80642748(arg0->args[0], arg0->args[1], arg1, arg2, 1);
        return;
    case 0x8:
        func_global_asm_80642844(arg0->args[0], arg0->args[1], arg1, arg2, 1);
        return;
    case 0x1E:
        func_global_asm_80642748(arg0->args[0], arg0->args[1], arg1, arg2, 0);
        return;
    case 0x1D:
        func_global_asm_80642844(arg0->args[0], arg0->args[1], arg1, arg2, 0);
        return;
    case 0x3:
        if (arg0->args[0] == 0) {
            arg1->unk44[arg0->args[2]] = (s16) arg0->args[1];
            return;
        }
        arg1->unk44[arg0->args[2]] = (s16) (s32) arg1->unk0[arg0->args[1]].unk14;
        return;
    case 0x65:
        arg1->next_state[arg0->args[1]] += arg0->args[0];
        return;
    case 0x1:
        arg1->next_state[arg0->args[1]] = (s8) arg0->args[0];
        return;
    case 0x5:
        if (func_global_asm_806418E8(arg0->args[0], arg0->args[1], arg0->args[2]) == 0) {
            return;
        }
        break;
    case 0x2D:
        var_v1 = D_global_asm_807FBB34;
        var_t0_2 = 0;
        var_v0_2 = D_global_asm_807FB930;
        if ((s32) var_v1 > 0) {
            do {
                temp_s0_5 = var_v0_2->unk0;
                var_t0_2 += 1;
                if (!(temp_s0_5->object_properties_bitfield & 0x2000) && (temp_s0_5->locked_to_pad == 1) && (arg2 == temp_s0_5->unk10C)) {
                    if (arg0->args[0] != 0) {
                        temp_s0_5->unk68 |= 4;
                    } else {
                        temp_s0_5->unk68 &= ~4;
                    }
                    var_v1 = D_global_asm_807FBB34;
                }
                var_v0_2 += 8;
            } while (var_t0_2 < (s32) var_v1);
            return;
        }
        break;
    case 0x7:
        D_global_asm_80747E70[arg0->args[0]](arg1, arg2, arg0->args[1], arg0->args[2]);
        return;
    case 0x37:
        func_global_asm_80679200(character_change_array->playerPointer, NULL, 0x400000, arg0->args[0], 0, NULL);
        return;
    case 0x19:
        setAction(arg0->args[0], NULL, 0U);
        return;
    case 0x2C:
        func_global_asm_806335B0((s32) arg2, 1U, (s32) arg0->args[0], &sp50, &sp4C, &sp48);
        func_global_asm_8067A9F0(NULL, character_change_array->playerPointer sp50, sp4C, sp48);
        return;
    case 0x2B:
        func_global_asm_80636014((s32) arg2, 1U, arg0->args[0]);
        return;
    case 0x1B:
        temp_a0_4 = D_global_asm_807F6240[arg0->args[0]];
        if (temp_a0_4 != -1) {
            func_global_asm_806335B0((s32) temp_a0_4, 1U, (s32) arg0->args[1], &D_global_asm_807F621C, &D_global_asm_807F6220, &D_global_asm_807F6224);
            return;
        }
        break;
    case 0x1C:
        temp_a0_5 = D_global_asm_807F6240[arg0->args[0]];
        if (temp_a0_5 != -1) {
            spC3 = 0;
            temp_v0_15 = func_global_asm_80659470((s32) temp_a0_5);
            var_a3 = 0;
            if (temp_v0_15 != -1) {
                temp_a0_6 = D_global_asm_807F6000[temp_v0_15].unk7C;
                if (temp_a0_6 != NULL) {
                    temp_t5 = arg0->args[1];
                    var_a3 = 1;
                    temp_a0_6->unk48[temp_t5] += arg0->args[2];
                }
            }
        }
        if (var_a3 == 0) {
            return;
        }
        break;
    case 0x2:
        func_global_asm_80723284(arg1->unk0[0xE], arg0->args[0]);
        return;
    case 0x1F:
        func_global_asm_807232EC(arg1->unk0[0xE], arg0->args[0]);
        return;
    case 0x20:
        func_global_asm_80723380(arg1->unk0[0xE], arg0->args[0]);
        return;
    case 0x21:
        func_global_asm_80723320(arg1->unk0[0xE], (s32) arg0->args[0]);
        return;
    case 0x24:
        func_global_asm_8072334C(arg1->unk0[0xE], arg0->args[0]);
        return;
    case 0x22:
        arg1->unk0[0xE] = func_global_asm_80723020(NULL, (s32) arg0->args[0], (s32) arg0->args[1], D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, (u8) (s32) arg0->args[2]);
        return;
    case 0x23:
        func_global_asm_80723428(arg1->unk0[0xE]);
        arg1->unk0[0xE] = -1;
        return;
    case 0x4:
        func_global_asm_80723484(arg1->unk0[0xE], (Actor *) arg1);
        func_global_asm_807238D4(arg1->unk0[0xE], &D_global_asm_807F621C, &D_global_asm_807F6220, &D_global_asm_807F6224);
        return;
    case 0x27:
        func_global_asm_80634EA4((s32) arg2, arg0->args[0], arg0->args[1]);
        return;
    case 0x28:
        func_global_asm_80635018((s32) arg2, arg0->args[0], (s32) arg0->args[1], (s32) arg0->args[2]);
        return;
    case 0x42:
        func_global_asm_80634CC8((s32) arg2, arg0->args[0], arg0->args[1], arg0->args[2]);
        return;
    case 0x29:
        func_global_asm_8061EF4C(character_change_array->playerPointer->PaaD->unk104, arg0->args[0], (u16) arg0->args[1], D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, (f32) D_global_asm_807F6906, (f32) D_global_asm_807F6908);
        return;
    case 0x44:
        D_global_asm_807F6906 = arg0->args[0];
        D_global_asm_807F6908 = arg0->args[1];
        return;
    case 0x2A:
        D_global_asm_807F6000[func_global_asm_80659470((s32) arg2)].unk3C = (s8) arg0->args[0];
        return;
    case 0x2E:
        func_global_asm_80651BC0(arg0->args[0], arg0->args[1]);
        return;
    case 0x38:
        func_global_asm_80651BE0(arg0->args[0], arg0->args[1], arg0->args[2]);
        return;
    case 0x61:
        temp_v0_16 = arg0->args[2];
        if (temp_v0_16 != 0) {
            playSong((s32) arg0->args[0], (f32) ((f64) temp_v0_16 / 255.0));
            return;
        }
        playSong((s32) arg0->args[0], 1.0f);
        return;
    case 0x6F:
        func_global_asm_80602B60((s32) arg0->args[0], arg0->args[1]);
        return;
    case 0x70:
        func_global_asm_80602C6C((s32) arg0->args[0], (f32) ((f64) arg0->args[1] / 255.0));
        return;
    case 0x71:
        func_global_asm_80602DC4((s32) arg0->args[0], (f32) ((f64) arg0->args[1] * 0.0001220703125));
        return;
    case 0x43:
        if (arg0->args[0] == 1) {
            arg1->unk0[2] = arg1->unk0[arg0->args[1]].unk14;
            arg1->unk0[3] = arg1->unk0[arg0->args[2]].unk14;
            return;
        }
        arg1->unk0[2] = ((f32) arg0->args[1] / 10.0f);
        arg1->unk0[3] = ((f32) arg0->args[2] / 10.0f);
        return;
    case 0x49:
        func_global_asm_8067ABC0(NULL, character_change_array->playerPointer, arg0->unk3, arg0->args[1], (s16) (s32) arg0->args[2], D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        return;
    case 0x4D:
        temp_a0_7 = func_global_asm_80632630((s32) arg0->args[0], D_global_asm_807F690C, D_global_asm_807F6910, D_global_asm_807F6914, D_global_asm_807F6910 - D_global_asm_807F6218, 0U);
        if (arg0->args[1] == 0) {
            func_global_asm_80641B00(temp_a0_7, arg2, arg0->args[2]);
            return;
        }
        break;
    case 0x51:
        func_global_asm_806F4F50(arg2, D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224);
        return;
    case 0x5E:
        func_global_asm_80641874(arg0->args[0], arg0->args[1]);
        return;
    case 0x8A:
        func_global_asm_806417BC(arg0->args[0], arg0->args[1]);
        return;
    case 0x63:
        func_global_asm_8068B830(arg0->args[0], arg0->args[1], arg0->args[2]);
        return;
    case 0x64:
        func_global_asm_8068B8FC();
        return;
    case 0x56:
        func_global_asm_80724994(1U, arg0->args[0], 0, 0, 0);
        return;
    case 0x59:
        func_global_asm_80724994(3U, arg0->args[0], arg0->args[1], 0, 0);
        return;
    case 0x58:
        if (func_global_asm_805FFE50((s32) arg0->args[0], arg0->args[1], arg0->args[2]) == 0) {
            func_global_asm_8063DB3C(arg0->args[0], arg0->args[1], arg0->args[2]);
            return;
        }
        break;
    case 0x77:
        func_global_asm_80650794(arg2, arg0->args[0], arg0->args[1], (f32) ((f64) arg0->args[2] / 1000.0));
        break;
    }
}
*/


void func_global_asm_80641724(s16 arg0) {
    PlayerAdditionalActorData *PaaD = character_change_array->playerPointer->PaaD;
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
    PlayerAdditionalActorData *PaaD = character_change_array->playerPointer->PaaD;

    if (gPlayerPointer->control_state == 0x42) {
        if (PaaD->unkBC == 0x62 || PaaD->unkBC == 0x88 || PaaD->unkBC == 0x17) {
            goto block_8;
        }
    }
    if (gPlayerPointer->control_state == 0x52 || gPlayerPointer->control_state == 0x67) {
        goto block_8;
    }
    if (character_change_array->action_initiated == 0x1C) {
        goto block_8;
    }
    if (character_change_array->action_initiated != 0x53) {
        goto block_9;
    }
block_8:
    return FALSE;
block_9:
    return TRUE;
}

extern u8 D_global_asm_807F6938;

// TODO: This does match but the types on the externs are sus
void func_global_asm_80641A78(void) {
    s32 i;

    for (i = 0; i < D_global_asm_807F6938; i++) {
        func_global_asm_806355DC(D_global_asm_807F6240[D_global_asm_807F6918[i]], 1);
    }
}

void func_global_asm_80641B00(s16 arg0, s16 arg1, s16 arg2) {
    arg0 = func_global_asm_80659470(arg0);
    arg1 = func_global_asm_80659470(arg1);
    D_global_asm_807F6000[arg0].unk7C = malloc(sizeof(Prop_ScriptData));
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

extern s16 D_global_asm_807F693C;
extern u8 D_global_asm_807F693F;

void func_global_asm_80641DA0(GlobalASMStruct44 *arg0, s16 arg1, s16 arg2, s16 spawn_trigger) {
    s32 phi_v1;

    if ((arg0->unk94 == 0) && ((func_global_asm_80678014(0x14)))) {
        arg0->unk94 = gLastSpawnedActor;
        gLastSpawnedActor->noclip_byte = 1;
        gLastSpawnedActor->x_position = D_global_asm_807F621C;
        gLastSpawnedActor->y_position = D_global_asm_807F6220;
        gLastSpawnedActor->z_position = D_global_asm_807F6224;
        gLastSpawnedActor->y_rotation = (D_global_asm_807F622C * 4096.0f) / 360.0f;
        if (D_global_asm_807F693F != 0) {
            gLastSpawnedActor->unk15E = spawn_trigger;
        }
        if (D_global_asm_807F693F != 0) {
            phi_v1 = 4;
        } else {
            phi_v1 = 0;
        }
        switch (arg2) {
            case 0:
                playCutscene(arg0->unk94, arg1, phi_v1 | 1 | D_global_asm_807F693C);
                return;
            case 1:
                playCutscene(NULL, arg1, phi_v1 | 1 | D_global_asm_807F693C);
                return;
            case 2:
                playCutscene(getSpawnerTiedActor(spawn_trigger, 0x400), arg1, phi_v1 | 1 | D_global_asm_807F693C);
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
            player = character_change_array[i].playerPointer;
            dx = D_global_asm_807F621C - player->x_position;
            dy = D_global_asm_807F6220 - player->y_position;
            dz = D_global_asm_807F6224 - player->z_position;
            dx *= dx;
            dy *= dy;
            dz *= dz;
            if (sqrtf(dx + dy + dz) < arg0) {
                func_global_asm_80626F8C(D_global_asm_807F621C, D_global_asm_807F6220, D_global_asm_807F6224, &sp8C, &sp88, 0, 1.0f, i);
                if ((s16)sp8C >= (character_change_array[i].unk270[0] + 0x14)
                    && ((s16)sp88 >= (character_change_array[i].unk270[1] + 0x14))
                    && (((s16)sp8C <= character_change_array[i].unk270[2] - 0x14))
                    && ((character_change_array[i].unk270[3] - 0x14) >= (s16)sp88)) {
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
                              character_change_array[playerIndex].playerPointer->x_position,
                              character_change_array[playerIndex].playerPointer->y_position,
                              character_change_array[playerIndex].playerPointer->z_position))) {
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

s32 func_global_asm_806423A8(s16 distance, s16 startSpawnTrigger, s16 endSpawnTrigger) {
    s16 spawn_trigger;
    Actor *actor;

    for (spawn_trigger = startSpawnTrigger; endSpawnTrigger >= spawn_trigger; spawn_trigger++) {
        if (func_global_asm_80726D7C(spawn_trigger)) {
            actor = getSpawnerTiedActor(spawn_trigger, 0);
            if (actor != NULL) {
                if (func_global_asm_8064216C(distance, actor->x_position, actor->y_position, actor->z_position)) {
                    return TRUE;
                }
            }
        }
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

extern f32 D_global_asm_807F6208;
extern f32 D_global_asm_807F6210;
extern f32 D_global_asm_807F620C;

s32 func_global_asm_806425FC(s16 arg0, s16 arg1) {
    f32 var_f2;
    f32 var_f12;
    s32 var_v1;
    f32 temp = (arg1 / 10.0f);

    var_v1 = 0;
    switch (((arg0 >> 8) % 255) & 0xFF) {
        case 0:
            var_f2 = D_global_asm_807F6208;
            break;
        case 1:
            var_f2 = D_global_asm_807F620C;
            break;
        case 2:
            var_f2 = D_global_asm_807F6210;
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
