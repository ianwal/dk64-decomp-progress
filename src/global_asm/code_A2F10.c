#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern SpriteData D_global_asm_80720BE8;

extern f32 D_global_asm_80750394;
extern f32 D_global_asm_80750398;
extern u8 D_global_asm_807503D4[];
extern u8 D_global_asm_807503E0[];

extern u8 D_global_asm_80750AB8;
extern u8 D_global_asm_80750AD4;

// rodata
const char D_global_asm_8075A410[] = "DONKEY";
const char D_global_asm_8075A418[] = "DIDDY";
const char D_global_asm_8075A420[] = "LANKY";
const char D_global_asm_8075A428[] = "TINY";
const char D_global_asm_8075A430[] = "CHUNKY";
const char D_global_asm_8075A438[] = "KING";
const char D_global_asm_8075A440[] = "K.";
const char D_global_asm_8075A444[] = "ROOL";
const char D_global_asm_8075A44C[] = "KONG";
// const char D_global_asm_8075A454[] = "ROUND";
// const char D_global_asm_8075A45C[] = "%d";
// const char D_global_asm_8075A460[] = "%d";
// const char D_global_asm_8075A464[] = "%d";
// const f64 D_global_asm_8075A498 = 1.04;
// const f64 D_global_asm_8075A4A0 = 0.01;
// const f64 D_global_asm_8075A4A8 = 6.66666666999999968;
// const f64 D_global_asm_8075A4B0 = 6.66666666999999968;
// const f64 D_global_asm_8075A4B8 = 6.66666666999999968;
// const f64 D_global_asm_8075A4C0 = 6.66666666999999968;
// const f64 D_global_asm_8075A4C8 = 0.02;
// const f64 D_global_asm_8075A4D0 = 0.01;
// const f64 D_global_asm_8075A4D8 = 0.3;
// const f32 D_global_asm_8075A504 = 99999.0f;
// const f32 D_global_asm_8075A508 = 99999.0f;
// const f64 D_global_asm_8075A510 = 0.1;
// const f64 D_global_asm_8075A518 = 0.15;
// const f64 D_global_asm_8075A520 = 0.8;
// const f64 D_global_asm_8075A528 = 0.3;
// const f64 D_global_asm_8075A530 = 1.2;
// const f64 D_global_asm_8075A538 = 0.3;
// const f64 D_global_asm_8075A540 = 0.15;

extern s32 D_global_asm_807FBB68;
extern u8 D_global_asm_807FBD70;

extern char *D_global_asm_80750338[];

// Jumptable, close, doable
// https://decomp.me/scratch/yqWRH
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_global_asm_8069E210.s")

s32 func_global_asm_80613CA8(Actor *, s32, f32, f32);

/*
void func_global_asm_8069E210(void) {
    s16 i;
    Struct807FBB70_unk278 *temp;
    s32 ya;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield &= ~4;
        func_global_asm_80613C48(current_actor_pointer, 0x407, 0.0f, 0.0f);
        func_global_asm_80614D00(current_actor_pointer, 0.0f, 0.0f);
    }

    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        temp = D_global_asm_807FBB70.unk278[i];
        if (temp->unk0 == 0) {
            ya = current_actor_pointer->object_properties_bitfield;
            current_actor_pointer->object_properties_bitfield = ya | 4;
            func_global_asm_80613CA8(current_actor_pointer, 0x407, 0.0f, 0.0f);
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            switch (func_global_asm_80688E68(current_actor_pointer)) {
                case 5:
                    playSound(0x1D7, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                    break;
                case 6:
                    playSound(0x1D8, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                    break;
                case 7:
                    playSound(0x1D9, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    break;
                case 8:
                    playSound(0x1DA, 0x7FFF, 63.0f, 1.0f, 2, 0);
                    break;
                case 9:
                    playSound(0x1DB, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                    break;
                case 10:
                    playSound(0x1DC, 0x7FFF, 63.0f, 1.0f, 0x1E, 0);
                    break;
            }
        }
    }
    if (current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
        current_actor_pointer->object_properties_bitfield &= ~4;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_8069E490(u16 arg0, s16 arg1) {
    func_global_asm_806A5DF0(arg0, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, arg1, current_actor_pointer);
}

void func_global_asm_8069E4E0(s16 arg0) {
    Actor *temp_a1;
    s16 i;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_a1 = D_global_asm_807FB930[i].unk0;
        if (current_actor_pointer == temp_a1->unk11C) {
            func_global_asm_8067A70C(current_actor_pointer, temp_a1, current_actor_pointer->x_position, current_actor_pointer->y_position + arg0, current_actor_pointer->z_position, 2, 1);
        }
    }
}

void func_global_asm_8069E5B8(void) {
    Actor *temp_a0;
    s16 phi_s0;

    for (phi_s0 = 0; phi_s0 < D_global_asm_807FBB34; phi_s0++) {
        temp_a0 = D_global_asm_807FB930[phi_s0].unk0;
        if (current_actor_pointer == temp_a0->unk11C) {
            func_global_asm_80679200(temp_a0, current_actor_pointer, 0x02000000, 1, 0, 0);
        }
    }
}

// TODO: Yikes, needs a dx dz macro or something...
int func_global_asm_8069E660(Actor *arg0, f32 arg1, f32 arg2) {
    return (arg0->y_position - 8.0f) <= current_actor_pointer->y_position
        && current_actor_pointer->y_position < (arg0->y_position + arg1)
        && ((((arg0->x_position - current_actor_pointer->x_position) * (arg0->x_position - current_actor_pointer->x_position)) + ((arg0->z_position - current_actor_pointer->z_position) * (arg0->z_position - current_actor_pointer->z_position))) < arg2)
        && (arg0->noclip_byte != 1);
}

s32 func_global_asm_8069E724(Actors actorBehaviourIndex) {
    switch (actorBehaviourIndex) {
        case ACTOR_DK:
            return 0xB;
        case ACTOR_DIDDY:
            return 0xE;
        case ACTOR_TINY:
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
            return 0xA;
        case ACTOR_LANKY:
            return 0xD;
        default:
            return 0;
    }
}

// Doable, close
// https://decomp.me/scratch/yDXeC
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_global_asm_8069E774.s")

// TODO: Add to aaD union
typedef struct {
    f32 unk0; // Used
    f32 unk4;
    f32 unk8;
    u16 unkC; // Used
    u16 unkE;
    u8 unk10; // Used
    u8 unk11; // Used
    u8 unk12; // Used
} AAD_global_asm_8069E774;

/*
void func_global_asm_8069E774(void) {
    u16 sp8E;
    f32 sp88;
    u8 sp87;
    PlayerAdditionalActorData *PaaD;
    u8 sp7F;
    Actor *sp78;
    s32 *sp74;
    AAD_global_asm_8069E774 *var_t0;
    s32 playerIndex;
    Actor *player;
    s32 sp60;
    PlayerAdditionalActorData *pad;

    sp8E = 300;
    sp87 = 0;
    sp7F = 0;
    var_t0 = current_actor_pointer->additional_actor_data;
    if ((current_actor_pointer->unk11C != NULL) && (current_actor_pointer->unk11C->interactable & 1)) {
        sp78 = current_actor_pointer->unk11C;
        sp7F = 1;
    } else {
        sp78 = player_pointer;
    }
    PaaD = sp78->additional_actor_data;
    if ((cc_number_of_players >= 2) && (D_global_asm_80750AB8 == 1)) {
        pad = player_pointer->PaaD;
        sp74 = &pad->unk1F0;
    } else {
        sp74 = &PaaD->unk1F0;
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        var_t0->unkC = sp78->ledge_info_pointer->unk14;
        current_actor_pointer->draw_distance = 1000;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_global_asm_8068842C(current_actor_pointer, 0, 1);
        func_global_asm_80688370(current_actor_pointer, 0, 1.0f);
        func_global_asm_80688460(current_actor_pointer, 0, 1);
        *sp74 |= 0x02000000;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        switch (func_global_asm_80613448(current_actor_pointer)) {
            case 0xAD:
                var_t0->unk10 = 0xFF;
                var_t0->unk11 = 0xFF;
                var_t0->unk12 = 0x32;
                break;
            case 0xAE:
                var_t0->unk10 = 0xFF;
                var_t0->unk11 = 0x32;
                var_t0->unk12 = 0x32;
                break;
            case 0xD1:
                var_t0->unk10 = 0xCA;
                var_t0->unk11 = 0x5B;
                var_t0->unk12 = 0xFF;
                break;
            case 0xD0:
                var_t0->unk10 = 0;
                var_t0->unk11 = 0x96;
                var_t0->unk12 = 0xFF;
                break;
            case 0xCF:
                var_t0->unk10 = 0x32;
                var_t0->unk11 = 0xFF;
                var_t0->unk12 = 0x32;
                break;
        }
        if (sp7F != 0) {
            var_t0->unk0 = 2.0f;
        } else {
            var_t0->unk0 = 1.5f;
        }
        if (current_actor_pointer->unk15F != 0) {
            func_global_asm_8066E8E4(current_actor_pointer, 0, 0, 0, 1.0f, 0);
        }
    }
    if (func_global_asm_8061CB50() != 0) {
        func_global_asm_8061F0B0(PaaD->unk104, 0xA, 0xA);
    }
    current_actor_pointer->animation_state->scale_x *= current_actor_pointer->unk160;
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->animation_state->scale_y *= 1.04;
    current_actor_pointer->animation_state->scale_y += (0.01 * func_global_asm_80612794(current_actor_pointer->unkEE));
    current_actor_pointer->unkEE += 0x1F4;
    current_actor_pointer->y_rotation += 0x32;
    current_actor_pointer->control_state++;
    if (current_actor_pointer->control_state == current_actor_pointer->unk168) {
        func_global_asm_80688460(current_actor_pointer, 0, 0);
    } else if (current_actor_pointer->unk168 < current_actor_pointer->control_state) {
        sp8E = 300 - ((current_actor_pointer->control_state - current_actor_pointer->unk168) * 40);
        if (func_global_asm_80688540(current_actor_pointer, 0) == 0) {
            sp87 = 1;
            *sp74 &= 0xFDFFFFFF;
            func_global_asm_8066EB40(sp78, var_t0->unkC);
            func_global_asm_8066E9EC(sp78, func_global_asm_8069E724(sp78->unk58), 0.0f);
            deleteActor(current_actor_pointer);
        }
    }
    func_global_asm_806595F0(1);
    createLight(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, 0, current_actor_pointer->animation_state->scale_x * sp8E * var_t0->unk0, 0, var_t0->unk10, var_t0->unk11, var_t0->unk12);
    if (current_map != MAP_DK_RAP) {
        if ((!sp7F) || (current_actor_pointer->unk15F != 0)) {
            s32 max;
            sp60 = 0x2E;
            if (func_global_asm_80714608(0)) {
                sp60 = 0xE;
            }
            sp88 = current_actor_pointer->animation_state->scale_x * sp8E;
            sp88 *= sp88;
            max = cc_number_of_players;
            for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
                player = character_change_array[playerIndex].player_pointer;
                if ((!sp7F) || ((playerIndex != PaaD->unk1A4) && (player->control_state != 0x84))) {
                    if (func_global_asm_8069E660(player, player->unk15E, sp88)) {
                        setAction(sp60, current_actor_pointer, playerIndex);
                    }
                }
            }
            if (current_actor_pointer->unk15F != 0) {
                func_global_asm_8066EB40(current_actor_pointer, 2.0 * ((current_actor_pointer->animation_state->scale_x * sp8E) * 6.66666666999999968));
                func_global_asm_8066E9EC(current_actor_pointer, 1, (current_actor_pointer->animation_state->scale_x * sp8E) * 6.66666666999999968);
            }
        } else if (!sp87) {
            func_global_asm_8066EB40(current_actor_pointer->unk11C, 2.0 * ((current_actor_pointer->animation_state->scale_x * sp8E) * 6.66666666999999968));
            func_global_asm_8066E9EC(current_actor_pointer->unk11C, func_global_asm_8069E724(sp78->unk58), (current_actor_pointer->animation_state->scale_x * sp8E) * 6.66666666999999968);
            func_global_asm_8066E5F8(sp78, func_global_asm_8069E724(sp78->unk58), 3);
        }
    }
    renderActor(current_actor_pointer, 0);
}
*/

s32 func_global_asm_8069EF50(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 dx = player_pointer->x_position - arg0;
    f32 dz = player_pointer->z_position - arg2;

    if (((dx * dx) + (dz * dz)) < (arg4 * arg4)) {
        if ((arg1 <= player_pointer->y_position) && (player_pointer->y_position < (arg1 + arg3))) {
            return TRUE;
        }
    }
    return FALSE;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_global_asm_8069F020.s")

/*
// TODO: Doable, good progress made
// Something sus going on with the big function call
// Something sus going on with gotos
// Something sus going on with missing logic in some if statements
void func_global_asm_8069F020(void) {
    u8 sp67;
    u16 sp64;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 var_f0;
    f32 var_f0_2;

    sp67 = current_actor_pointer->unkF0 == 0xBB ? 0x28 : 0x23;
    sp64 = current_actor_pointer->unkF0 == 0x6A ? 0x78 : 0x190;
    if (is_cutscene_active == 1) {
        deleteActor(current_actor_pointer);
    }
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->draw_distance = 1000;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_global_asm_8068842C(current_actor_pointer, 0, 1);
        func_global_asm_80688370(current_actor_pointer, 0, 0.5f);
        func_global_asm_80688460(current_actor_pointer, 0, 1);
        current_actor_pointer->unkEE = 0x3C;
    }
    if (current_actor_pointer->unk168 != 0) {
        var_f0 = 1.0f;
        if (current_actor_pointer->unkEE < 0x1E) {
            var_f0 = current_actor_pointer->unkEE / 30.0;
        }
        func_global_asm_806595F0(1);
        if (current_actor_pointer->unk16A < 0) {
            // TODO: Hmm
        }
        if (current_actor_pointer->unk16B < 0) {
            // TODO: Hmm
        }
        // TODO: Missing args here
        createLight(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0, 0, 0, 300.0f, 0, 0, 0, current_actor_pointer->unk16C * var_f0);
        current_actor_pointer->animation_state->scale_x *= current_actor_pointer->unk160;
        current_actor_pointer->animation_state->scale_z *= current_actor_pointer->unk160;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (current_actor_pointer->unk168 == 0) {
                current_actor_pointer->animation_state->scale_x *= current_actor_pointer->unk160;
                current_actor_pointer->animation_state->scale_z *= current_actor_pointer->unk160;
            }
            if ((current_actor_pointer->animation_state->unk0->unk24 == 0.0f) || (current_actor_pointer->animation_state->unk0->unk4 > 5.0f)) {
                current_actor_pointer->control_state = 1;
                func_global_asm_80688460(current_actor_pointer, 0, 0);
            }
            break;
        case 1:
            if (current_actor_pointer->animation_state->unk0->unk24 == 0.0f) {
                if (func_global_asm_80688584(current_actor_pointer, 0)->unkC < 0xE) {
                    goto block_33;
                }
                goto block_34;
            }
    block_33:
            if (current_actor_pointer->animation_state->unk0->unk4 > 9.0f) {
    block_34:
                current_actor_pointer->control_state = 2;
                if ((current_actor_pointer->unk15F != 0) && (spawnActor(ACTOR_BOSS_SHOCKWAVE, current_actor_pointer->unkF0))) {
                    if (current_actor_pointer->animation_state->unk0->unk4 > 9.0f) {
                        func_global_asm_80613C48(last_spawned_actor, 0x4F9, 0.0f, 0.0f);
                        func_global_asm_80614D00(last_spawned_actor, current_actor_pointer->animation_state->unk48, 0);
                    }
                    moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale_y);
                    last_spawned_actor->unkF0 = current_actor_pointer->unkF0;
                    last_spawned_actor->animation_state->scale_x = current_actor_pointer->animation_state->scale_x + D_global_asm_8075A4C8;
                    last_spawned_actor->animation_state->scale_z = current_actor_pointer->animation_state->scale_z + D_global_asm_8075A4C8;
                    last_spawned_actor->unk15F = current_actor_pointer->unk15F - 1;
                    last_spawned_actor->unk160 = current_actor_pointer->unk160;
                }
            }
            break;
        case 2:
            if (func_global_asm_80688540(current_actor_pointer, 0) == 0) {
                current_actor_pointer->control_state = 3;
                if (current_actor_pointer->unk168 != 0) {
                    current_actor_pointer->object_properties_bitfield &= ~4;
                } else {
                    deleteActor(current_actor_pointer);
                }
            }
            break;
        case 3:
            current_actor_pointer->unkEE -= 1;
            if (current_actor_pointer->unkEE == 0) {
                deleteActor(current_actor_pointer);
            }
            break;
    }
    if ((current_actor_pointer->unkF0 != 0x6A) && !(D_global_asm_807FBB68 & 2)) {
        if ((current_actor_pointer->object_properties_bitfield & 4) && (current_actor_pointer->object_properties_bitfield & 0x10)) {
            sp50 = current_actor_pointer->y_position;
            getBonePosition(current_actor_pointer, 1, &sp5C, &sp58, &sp54);
            sp58 += 50.0f;
            if (func_global_asm_80667110(sp5C, sp54, &sp58) != 0) {
                if (sp58 < sp50) {
                    var_f0_2 = sp50 - sp58;
                } else {
                    var_f0_2 = sp58 - sp50;
                }
                if ((var_f0_2 < 40.0f) || !(current_actor_pointer->object_properties_bitfield & 0x10)) {
                    current_actor_pointer->y_position = sp58;
                }
            }
        }
    }
    if ((current_actor_pointer->unk168 == 0) || (current_actor_pointer->control_state != 3)) {
        if ((func_global_asm_8069EF50(current_actor_pointer->x_position, current_actor_pointer->y_position - 20.0f, current_actor_pointer->z_position, sp67, current_actor_pointer->animation_state->scale_x * sp64) != 0)
         && (func_global_asm_8069EF50(current_actor_pointer->x_position, current_actor_pointer->y_position - 20.0f, current_actor_pointer->z_position, sp67, current_actor_pointer->animation_state->scale_x * (sp64 - 0x14)) == 0)) {
            setAction(0x2E, current_actor_pointer, 0);
        }
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_8069F904(Gfx *dl, Actor *arg1) {
    f32 temp_f0;

    temp_f0 = arg1->unkE0;
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gSPMatrix(dl++, &D_20000C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1->y_rotation);
    displayImage(dl, (arg1->unk15F + 0x61), 0, 2, 0x28, 0x33, arg1->x_position, arg1->y_position, temp_f0, temp_f0, 0, 0.0f);
}

Gfx *func_global_asm_8069FA40(Gfx *dl, Actor *arg1) {
    f32 spFC;
    f32 spBC[4][4];
    f32 sp7C[4][4];
    Mtx *sp78;
    char sp68[0x10];
    s16 center;
    u8 style;
    u8 sp64;

    spFC = 0.3 * MAX(0.01, arg1->unkE0 - 2.0);
    sp64 = FALSE;
    gSPDisplayList(dl++, &D_1000118);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1->y_rotation);
    dl = func_global_asm_8070068C(dl);
    sp78 = malloc(sizeof(Mtx));
    func_global_asm_8061134C(sp78);
    style = 1;
    switch (arg1->unk15F) {
        case 0:
            sprintf(sp68, "ROUND");
            break;
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
            sp64 = TRUE;
            // TODO: WTF
            sprintf(sp68, D_global_asm_80750338[arg1->unk15F << 0]);
            break;
        default:
            if (arg1->unk15F & 0x80) {
                spFC = 4.0 - spFC;
                style = 3;
                sprintf(sp68, "%d", 0xA - (arg1->unk15F & 0x3F));
            } else if (arg1->unk15F & 0x40) {
                spFC = 4.0 - spFC;
                style = 3;
                sprintf(sp68, "%d", 8 - (arg1->unk15F & 0x3F));
            } else {
                sprintf(sp68, "%d", arg1->unk15F);
            }
            break;
    }
    center = getCenterOfString(style, sp68);
    if (sp64) {
        arg1->x_position = (320 - center) << 1;
    }
    guScaleF(spBC, spFC, spFC, 1);
    guTranslateF(sp7C, arg1->x_position + (2.0 * center), arg1->y_position * 4.0f, 0);
    guMtxCatF(spBC, sp7C, spBC);
    guMtxF2L(spBC, sp78);
    gSPMatrix(dl++, sp78, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return printStyledText(dl, style, center * -2, 0, sp68, 0);
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_global_asm_8069FDA0.s")

/*
void func_global_asm_8069FDA0(void) {
    s16 sp22;
    f32 temp_f12;
    f64 temp_f2;
    s32 temp_v1;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEE = current_actor_pointer->unk160;
    }
    temp_f2 = (u32)D_global_asm_80744478 * 0.5;
    if (temp_f2 < current_actor_pointer->unk160) {
        current_actor_pointer->unk160 = current_actor_pointer->unk160 - temp_f2;
        temp_f12 = current_actor_pointer->unk160 / current_actor_pointer->unkEE;
        current_actor_pointer->unkE0 = (temp_f12 * -8.0) + 12.0;
        current_actor_pointer->y_rotation = 255.0f * temp_f12;
        if ((current_actor_pointer->unk15F >= 0x14) && (current_actor_pointer->unk15F < 0x1E)) {
            addActorToTextOverlayRenderArray(func_global_asm_8069F904, current_actor_pointer, 3);
        } else {
            addActorToTextOverlayRenderArray(func_global_asm_8069FA40, current_actor_pointer, 3);
        }
        if ((current_actor_pointer->unk15F == 0) && (current_actor_pointer->unk160 == 3)) {
            spawnActor(ACTOR_TEXT_OVERLAY, 0);
            last_spawned_actor->unk160 = current_actor_pointer->unkEE;
            last_spawned_actor->unk15F = D_global_asm_80750AD4;
            last_spawned_actor->y_position = 80.0f;
            last_spawned_actor->x_position = 640.0f;
            playSound(D_global_asm_80750AD4 + 0x3F3, 0x7FFF, 63.0f, 1.0f, 0, 0);
            return;
        }
        if ((current_actor_pointer->unk15F >= 0x1E) && (current_actor_pointer->unk15F < 0x25) && (current_actor_pointer->unk160 == 5)) {
            spawnActor(ACTOR_TEXT_OVERLAY, 0);
            last_spawned_actor->unk160 = current_actor_pointer->unkEE;
            if (current_actor_pointer->unk15F == 0x23) {
                last_spawned_actor->unk15F = 0x24;
            } else if (current_actor_pointer->unk15F == 0x24) {
                last_spawned_actor->unk15F = 0x25;
            } else {
                last_spawned_actor->unk15F = 0x26;
            }
            last_spawned_actor->y_position = 80.0f;
            last_spawned_actor->x_position = 500.0f;
        }
    } else {
        temp_v1 = current_actor_pointer->unk15F & 0x3F;
        if ((current_actor_pointer->unk15F & 0xC0) && (temp_v1 != 0)) {
            sp22 = 0x3FC - temp_v1;
            spawnActor(ACTOR_TEXT_OVERLAY, 0);
            last_spawned_actor->unk160 = current_actor_pointer->unkEE;
            last_spawned_actor->unk15F = ((current_actor_pointer->unk15F & 0xC0) + (current_actor_pointer->unk15F & 0x3F)) - 1;
            if (current_actor_pointer->unk15F & 0x80) {
                sp22 += 2;
            }
            playSound(sp22, 0x7FFF, 63.0f, 1.0f, 0, 0);
            last_spawned_actor->y_position = 80.0f;
            last_spawned_actor->x_position = 600.0f;
        }
        deleteActor(current_actor_pointer);
    }
}
*/

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
} AAD_global_asm_806A018C;

void func_global_asm_806A018C(void) {
    AAD_global_asm_806A018C *temp_s1;

    temp_s1 = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk0;
        current_actor_pointer->unkEE = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 1;
        temp_s1->unk0 = (rand() >> 0xF) % 70;
        temp_s1->unk4 = (rand() >> 0xF) % 200;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0);
    current_actor_pointer->y_velocity += D_global_asm_80750394;
    current_actor_pointer->z_rotation += temp_s1->unk4;
    current_actor_pointer->x_rotation += temp_s1->unk0;
    if ((current_actor_pointer->unkFC != 0) || ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1))) {
        deleteActor(current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806A02F0(void) {
    func_global_asm_806A018C();
}

void func_global_asm_806A0310(void) {
    func_global_asm_806A018C();
}

// Stalactite
void func_global_asm_806A0330(void) {
    s32 pad[8];
    s32 i;
    f32 x, y, z;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x1C;
        current_actor_pointer->y_velocity = 0.0f;
        current_actor_pointer->draw_distance = 2000;
        current_actor_pointer->floor = 99999.0f;
        func_global_asm_80665564(current_actor_pointer, 0.0f);
    }
    if (func_global_asm_8061CB50() != 0) {
        current_actor_pointer->unk132 = 2;
    } else {
        current_actor_pointer->unk132 = 1;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    current_actor_pointer->y_velocity += D_global_asm_80750398;
    if (99999.0f != current_actor_pointer->floor) {
        func_global_asm_8065D244(1);
        func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x18, 0x18, 1, 0x96, 0xB4, 0, 1.0f);
    } else {
        deleteActor(current_actor_pointer);
    }
    if ((D_global_asm_807FBD70 == 4) || (current_actor_pointer->unkFC != 0) || ((current_actor_pointer->unk6A & 1) && !(current_actor_pointer->unk6C & 1))) {
        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xF, 0xF);
        playSoundAtActorPosition(current_actor_pointer, 0x162, 0xE1, 0x3C, 1);
        for (i = 1; i < 7; i++) {
            getBonePosition(current_actor_pointer, i, &x, &y, &z);
            func_global_asm_8071496C(i);
            func_global_asm_807149B8(1);
            func_global_asm_8071498C(func_global_asm_8071BB14);
            changeActorColor(0xFF, 0xFF, 0xFF, 0x96);
            drawSpriteAtPosition(&D_global_asm_80720BE8, 1.5f, x, y, z);
        }
        deleteActor(current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806A05D4(void) {
    renderActor(current_actor_pointer, 0);
}

typedef struct {
    s8 unk0[0x200 - 0x0];
    s16 unk200;
} AAD_global_asm_806A05FC;

// Trap Bubble
void func_global_asm_806A05FC(void) {
    ActorAnimationState *temp_v0;
    f64 temp_f0;
    s32 var_v0_2;
    s32 var_v0_3;
    AAD_global_asm_806A05FC *temp_a3;

    temp_a3 = current_actor_pointer->unk11C->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->shadow_opacity = 0xFF;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        current_actor_pointer->unk160 = current_actor_pointer->unk11C->unk15E * 0.1 * 0.15;
    }
    current_actor_pointer->x_position = current_actor_pointer->unk11C->x_position;
    current_actor_pointer->y_position = current_actor_pointer->unk11C->y_position;
    current_actor_pointer->z_position = current_actor_pointer->unk11C->z_position;
    if (current_actor_pointer->shadow_opacity & 8) {
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale_x = (((current_actor_pointer->unk160 * 0.8) - temp_v0->scale_x) * 0.3) + temp_v0->scale_x;
    } else {
        temp_v0 = current_actor_pointer->animation_state;
        temp_v0->scale_x = (((current_actor_pointer->unk160 * 1.2) - temp_v0->scale_x) * 0.3) + temp_v0->scale_x;
    }
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    if (temp_a3->unk200 > 0) {
        var_v0_2 = temp_a3->unk200;
    } else {
        var_v0_2 = 0;
    }
    if (var_v0_2 < 0xFF) {
        if (temp_a3->unk200 > 0) {
            var_v0_3 = temp_a3->unk200;
        } else {
            var_v0_3 = 0;
        }
        current_actor_pointer->shadow_opacity = var_v0_3;
    } else {
        current_actor_pointer->shadow_opacity = 0xFF;
    }
    if ((current_actor_pointer->shadow_opacity == 0) || (current_actor_pointer->unk11C->control_state != 0x7C)) {
        deleteActor(current_actor_pointer);
        return;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806A081C(Actor *arg0) {
    spawnActor(ACTOR_KONG_REFLECTION, func_global_asm_80613448(arg0));
    last_spawned_actor->unk11C = arg0;
    arg0->unk6A |=  0x800;
}

typedef struct KongReflectionAAD {
    Actor* parent;
    s32 parent_spawn_index;
    enum actors_e parent_actor_type;
    s16 unkC;
    u8 unkE;
    u8 unkF;
} KongReflectionAAD;

// Kong reflection
void func_global_asm_806A0864(void) {
    Mtx sp108;
    f32 spC8[4][4];
    f32 sp88[4][4];
    f32 sp48[4][4];
    s32 i;
    Mtx *var_s1;
    KongReflectionAAD *aad;

    aad = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x08100000;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        func_global_asm_806131D4(current_actor_pointer,
            func_global_asm_80613448(current_actor_pointer)
        );
        aad->parent_spawn_index = current_actor_pointer->unk11C->unk54;
        aad->parent = current_actor_pointer->unk11C;
        aad->parent_actor_type = current_actor_pointer->unk11C->unk58;
    }
    if (
        (!func_global_asm_8067AF44(aad->parent)) ||
        (aad->parent_spawn_index != current_actor_pointer->unk11C->unk54)
    ) {
        deleteActor(current_actor_pointer);
        return;
    }
    if (
        (!func_global_asm_80665AAC(aad->parent)) || 
        (aad->parent_actor_type != current_actor_pointer->unk11C->unk58) || 
        (!func_global_asm_8067AE0C(aad->parent)) || 
        !(aad->parent->unk68 & 0x40)
    ) {
        deleteActor(current_actor_pointer);
        aad->parent->unk6A &= ~0x800;
        return;
    }
    current_actor_pointer->shadow_opacity = 0xFF;
    current_actor_pointer->unk146_s16 = aad->parent->unk146_s16;
    current_actor_pointer->x_position = aad->parent->x_position;
    current_actor_pointer->y_position = aad->parent->y_position;
    current_actor_pointer->unkA8 = aad->parent->unkA8;
    current_actor_pointer->z_position = aad->parent->z_position;
    current_actor_pointer->object_properties_bitfield |= 0x200;
    current_actor_pointer->unk8 = current_actor_pointer->animation_state->bone_arrays[D_global_asm_807444FC];
    memcpy(current_actor_pointer->unk8, current_actor_pointer->unk11C->unk8, current_actor_pointer->unk0->unk20 * sizeof(Mtx));
    guMtxIdentF(spC8);
    spC8[1][1] = -1.0f;
    guTranslateF(sp48, -current_actor_pointer->x_position, -current_actor_pointer->unkA8, -current_actor_pointer->z_position);
    guMtxCatF(sp48, spC8, spC8);
    guMtxF2L(spC8, &sp108);
    guTranslateF(sp48, current_actor_pointer->x_position, current_actor_pointer->unkA8, current_actor_pointer->z_position);
    var_s1 = current_actor_pointer->unk8;
    for (i = 0; i < current_actor_pointer->unk0->unk20; i++) {
        guMtxL2F(sp88, var_s1);
        guMtxCatF(sp88, spC8, sp88);
        guMtxCatF(sp88, sp48, sp88);
        guMtxF2L(sp88, var_s1);
        var_s1++;
    }
}

void func_global_asm_806A0B74(void) {
    Mtx sp128;
    f32 spE8[4][4];
    f32 spA8[4][4];
    f32 sp68[4][4];
    Actor *parent;
    s32 i;
    Mtx *var_s1;
    f32 x, y, z;
    KongReflectionAAD *aad;

    aad = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x08100000;
        current_actor_pointer->object_properties_bitfield &= ~0x8000;
        func_global_asm_806131D4(current_actor_pointer, 
            func_global_asm_80613448(current_actor_pointer)
        );
        aad->parent_spawn_index = current_actor_pointer->unk11C->unk54;
        aad->parent = current_actor_pointer->unk11C;
        aad->parent_actor_type = current_actor_pointer->unk11C->unk58;
    }
    if ((func_global_asm_8067AF44(aad->parent) == 0) || (aad->parent_spawn_index != current_actor_pointer->unk11C->unk54)) {
        deleteActor(current_actor_pointer);
        func_global_asm_80663BE8(current_actor_pointer);
        return;
    }
    if ((aad->parent_actor_type != current_actor_pointer->unk11C->unk58) || (func_global_asm_8067AE0C(aad->parent) == 0) || !(aad->parent->unk68 & 0x80)) {
        deleteActor(current_actor_pointer);
        func_global_asm_80663BE8(current_actor_pointer);
        aad->parent->unk156--;
        return;
    }
    current_actor_pointer->shadow_opacity = aad->unkF;
    current_actor_pointer->unk146_s16 = current_actor_pointer->unk11C->unk146_s16;
    current_actor_pointer->x_position = current_actor_pointer->unk11C->x_position;
    current_actor_pointer->y_position = current_actor_pointer->unk11C->y_position;
    current_actor_pointer->unkA8 = current_actor_pointer->unk11C->unkA8;
    current_actor_pointer->z_position = current_actor_pointer->unk11C->z_position;
    current_actor_pointer->object_properties_bitfield |= 0x200;
    current_actor_pointer->unk8 = current_actor_pointer->animation_state->bone_arrays[D_global_asm_807444FC];
    memcpy(current_actor_pointer->unk8, current_actor_pointer->unk11C->unk8, current_actor_pointer->unk0->unk20 * sizeof(Mtx));
    guMtxIdentF(spE8);
    if (aad->unkE & 1) {
        spE8[0][0] = -1.0f;
        guTranslateF(sp68, -aad->unkC, 0.0f, 0.0f);
        guMtxCatF(sp68, spE8, spE8);
        guMtxF2L(spE8, &sp128);
        guTranslateF(sp68, aad->unkC, 0.0f, 0.0f);
    } else {
        spE8[2][2] = -1.0f;
        guTranslateF(sp68, 0.0f, 0.0f, (f32) -aad->unkC);
        guMtxCatF(sp68, spE8, spE8);
        guMtxF2L(spE8, &sp128);
        guTranslateF(sp68, 0.0f, 0.0f, (f32) aad->unkC);
    }
    i = 0;
    var_s1 = current_actor_pointer->unk8;
    for (i = 0; i < current_actor_pointer->unk0->unk20; i++) {
        guMtxL2F(spA8, var_s1);
        guMtxCatF(spA8, spE8, spA8);
        guMtxCatF(spA8, sp68, spA8);
        guMtxF2L(spA8, var_s1);
        var_s1++;
    }
    guMtxXFMF(spE8, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, &x, &y, &z);
    guMtxXFMF(sp68, x, y, z, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
}

void func_global_asm_806A0F78(Actor *arg0, u8 arg1, u8 arg2) {
    func_global_asm_8068842C(arg0, 0, 1);
    func_global_asm_80688460(arg0, 0, 1);
    func_global_asm_806883F4(arg0, 0, arg1, 0.0f);
    func_global_asm_8068842C(arg0, 1, 1);
    func_global_asm_80688460(arg0, 1, 1);
    func_global_asm_806883F4(arg0, 1, arg2, 0.0f);
}

void func_global_asm_806A1008(u8 arg0, u8 arg1) {
    Actor *temp_a0;
    s16 i;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        temp_a0 = D_global_asm_807FB930[i].unk0;
        if (temp_a0->unk58 == ACTOR_ROPE && (temp_a0->unk15F / 3) == arg0) {
            temp_a0->control_state = arg1;
            temp_a0->control_state_progress = 0;
        }
    }
}

// AnimationState->unk24
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_global_asm_806A10BC.s")

/*
void func_global_asm_806A10BC(s32 *arg0) {
    AnimationStateUnk24 *var_v0;
    s16 i;

    var_v0 = current_actor_pointer->animation_state->unk24;
    for (i = 0; i < 7; i++) {
        var_v0[i].unkC = *(*arg0 + (i * 0x34 * 4) + (current_actor_pointer->unk168 * 4));
    }
}
*/

// TODO: Close, doable, try merging k and i
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A2F10/func_global_asm_806A112C.s")

typedef struct {
    void* unk0;
} AAD_806A112C;

typedef struct {
    void* unk0;
} AAD_806A112C_2;

/*
void func_global_asm_806A112C(void) {
    f32 scale;
    f32 temp_f20;
    s16 k;
    u8 j;
    s16 i;
    AAD_806A112C *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->object_properties_bitfield |= 0x400;
        func_global_asm_80724D28(0, 7);
        for (i = 0; i < 7; i++) {
            current_actor_pointer->animation_state->unk24[i].unk0 = i;
            current_actor_pointer->animation_state->unk24[i].unk1 = 0xFF;
        }
        if (current_actor_pointer->unk15F == 0) {
            scale = current_actor_pointer->animation_state->scale_y / 0.15;
            aaD->unk0 = getPointerTableFile(0x13, 6, 1, 1);
            func_global_asm_806A0F78(current_actor_pointer, D_global_asm_807503D4[0], D_global_asm_807503E0[0]);
            j = 1;
            temp_f20 = 75.0f * scale;
            k = 1;
            do {
                spawnActor(ACTOR_ROPE, 0xE1);
                ((AAD_806A112C_2*)last_spawned_actor->additional_actor_data)->unk0 = aaD->unk0;
                last_spawned_actor->unk15F = k;
                last_spawned_actor->y_rotation = current_actor_pointer->y_rotation + ((k / 3) << 0xA);
                last_spawned_actor->x_position = current_actor_pointer->x_position - (func_global_asm_80612794(last_spawned_actor->y_rotation) * temp_f20);
                last_spawned_actor->y_position = current_actor_pointer->y_position + (((k % 3) & 0xFF) * 0x11);
                last_spawned_actor->z_position = current_actor_pointer->z_position - (func_global_asm_80612790(last_spawned_actor->y_rotation) * temp_f20);
                func_global_asm_807248B0(last_spawned_actor, current_actor_pointer->animation_state->scale_y);
                j++;
                func_global_asm_806A0F78(last_spawned_actor, D_global_asm_807503D4[j], D_global_asm_807503E0[j]);
                k++;
            } while (k < 0xC);
            current_actor_pointer->x_position -= temp_f20 * func_global_asm_80612794(current_actor_pointer->y_rotation);
            current_actor_pointer->z_position -= temp_f20 * func_global_asm_80612790(current_actor_pointer->y_rotation);
        }
    }
    switch (current_actor_pointer->control_state) {
        case 1:
            current_actor_pointer->unk168++;
            if (current_actor_pointer->unk168 == 7) {
                current_actor_pointer->control_state++;
                current_actor_pointer->unk168 = 0;
            }
            break;
        case 2:
            func_global_asm_806A10BC(aaD);
            current_actor_pointer->unk168++;
            if (current_actor_pointer->unk168 == 0xB) {
                current_actor_pointer->control_state++;
            }
            break;
        case 3:
            func_global_asm_806A10BC(aaD);
            current_actor_pointer->unk168++;
            if (current_actor_pointer->unk168 >= 0x34) {
                current_actor_pointer->unk168 = RandClamp(1000) % 3;
                current_actor_pointer->control_state = 0;
            }
            break;
        case 10:
            current_actor_pointer->unk168 = 0xB;
            func_global_asm_806A10BC(aaD);
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/
