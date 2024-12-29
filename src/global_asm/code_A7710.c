#include <ultra64.h>
#include "functions.h"

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2A10.s")

typedef struct {
    OSTime unk0;
    u32 unk8;
    s32 unkC;
    u8 unk10;
} AAD_global_asm_806A2A10;

/*
void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2) {
    spawnActor(ACTOR_TIMER_CONTROLLER, 0);
    if (arg0 & 0x8000) {
        arg2--;
        last_spawned_actor->unk15F = 0xB;
    } else {
        last_spawned_actor->unk15F = 6;
    }
    current_actor_pointer->unk11C = last_spawned_actor;
    extra_player_info_pointer->unk1A8 = last_spawned_actor;
    ((AAD_global_asm_806A2A10*)last_spawned_actor->additional_data_pointer)->unkC = arg2;
    last_spawned_actor->x_position = (s16)(arg0 & 0x7FFF);
    last_spawned_actor->y_position = arg1;
    last_spawned_actor->control_state = 1;
    last_spawned_actor->shadow_opacity = 0;
}
*/

void func_global_asm_806A2B08(Actor *arg0) {
    arg0->control_state = 2;
    arg0->control_state_progress = 0;
    arg0->shadow_opacity = 0xFF;
}

void func_global_asm_806A2B20(Actor *arg0) {
    if (arg0 != 0) {
        arg0->control_state = 1;
        arg0->control_state_progress = 0;
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A7710/func_global_asm_806A2B38.s")

extern OSTime D_global_asm_807FC7D0;

typedef struct {
    OSTime unk0;
} AAD_global_asm_806A2B38;

/*
void func_global_asm_806A2B38(Actor *arg0) {
    D_global_asm_807FC7D0 = osGetTime() - 
        ((AAD_global_asm_806A2B38 *)arg0->additional_actor_data)->unk0;
}
*/

void func_global_asm_806A2B80(Actor *arg0) {
    arg0->control_state = 3;
    arg0->control_state_progress = 0;
}

extern SpriteData D_global_asm_8071FC58;

Gfx *func_global_asm_806A2B90(Gfx *dl, Actor *arg1) {
    AAD_global_asm_806A2A10 *sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 var_v0; // 48
    Struct80754AD0 *temp; // 44
    f32 sp40;
    s32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp5C = arg1->additional_actor_data;
    if (func_global_asm_805FCA64()) {
        gSPDisplayList(dl++, &D_1000118);
        gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg1->shadow_opacity);
        gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        sp30 = arg1->unk15F;
        if (sp30 == 0xB) {
            dl = func_global_asm_8070068C(dl);
            temp = func_global_asm_806FD9B4(sp5C->unk10);
            dl = printStyledText(dl, 0x86, 
                arg1->x_position * 4.0f,
                ((character_change_array->unk276 * 4) - 0x3C),
                temp->unk4, 1U);
        } else {
            var_v0 = 8;
            sp40 = 6.2831854820251465 - (2.0 * arg1->unk160);
            if (arg1->unk168 == 3) {
                var_v0 = -7;
            }
            dl = func_global_asm_806FE078(dl, 
                sp5C->unk10, sp30, 
                arg1->x_position + var_v0, 
                arg1->y_position + 5.0f, 0.0f, 1.0f);
            if (arg1->control_state == 2) {
                dl = func_global_asm_8070068C(dl);
                func_global_asm_8071495C();
                sp34 = func_global_asm_80612D1C(sp40);
                sp38 = func_global_asm_80612D10(sp40);
                drawSpriteAtPosition(&D_global_asm_8071FC58, 0.5f,
                    (sp34 * 40.0) + (40.0f + arg1->x_position), 
                    (sp38 * 25.0) + arg1->y_position,
                    0.0f);
            }
        }
    }
    return dl;
}

u8 func_global_asm_806FDB8C(s16, s8 *, u8, f32, f32, f32);
extern u32 D_807FC7D4;
extern u8 D_807FC7D8;
extern OSTime D_global_asm_807445B0;
extern OSTime D_global_asm_807476C8;

void func_global_asm_806A2E30(void) {
    f32 sp84;
    f32 temp_f2;
    char sp60[0x20]; // 60
    AAD_global_asm_806A2A10 *aad; // 5c
    u64 res; // 50
    s32 delta;
    s32 var_v0;

    aad = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (current_actor_pointer->unk15F == 6) {
            sprintf(&sp60, "%.2d", aad->unkC);
        } else {
            sprintf(&sp60, "%.2d:%.2d:00", aad->unkC / 60U, aad->unkC % 60U);
        }
        aad->unk10 = func_global_asm_806FDB8C(current_actor_pointer->unk15F == 0xB ? 6 : 3, &sp60, current_actor_pointer->unk15F, 0.0f, 0.0f, 0.0f);
    }
    if (current_actor_pointer->control_state == 3) {
        aad->unk0 = osGetTime() - D_global_asm_807FC7D0;
        current_actor_pointer->control_state = 2;
        current_actor_pointer->control_state_progress = 1;
    }
    aad->unk0 += D_global_asm_807445B0;
    if (current_actor_pointer->unk15F == 0xB) {
        aad->unk0 += D_global_asm_807476C8;
    }
    res = __ll_mul(osGetTime() - aad->unk0, 0x40);
    res = __ull_div(res, 0xBB8);
    aad->unk8 = __ull_div(res, 0xF4240);
    if (D_global_asm_807476C8 == 0) {
        D_807FC7D8 = __ull_rem(__ull_div(res, 0x2710), 0x64);
    }
    sp84 = ((f32) (s32) ((func_global_asm_806FDA8C(aad->unk10) - 1.5707964f) / 3.1415927f) * 3.1415927f) + 3.1415927f + 1.5707964f;
    temp_f2 = (f32) ((((__ull_to_d(res) / 10000.0) / 100.0) * 3.1415927410125732) + 1.5707963705062866);
    func_global_asm_806FDAB8(aad->unk10, 0.0f);
    
    delta = aad->unkC - aad->unk8;
    switch (current_actor_pointer->control_state) {
    case 1:
        if (current_actor_pointer->shadow_opacity < 0xFF) {
            current_actor_pointer->shadow_opacity = MIN(0xFF, current_actor_pointer->shadow_opacity + 3);
        }
        func_global_asm_806FDAB8(aad->unk10, 1.5707964f);
        current_actor_pointer->unk168 = 0;
        break;
    case 4:
        current_actor_pointer->control_state = 2;
        current_actor_pointer->control_state_progress = 0xFF;
    case 2:
        if (current_actor_pointer->control_state_progress == 0) {
            current_actor_pointer->control_state_progress++;
            aad->unk0 = osGetTime();
            aad->unk8 = 0;
            temp_f2 = 1.5707964f;
        }
        delta = aad->unkC - aad->unk8;
        if (delta >= 0) {
            func_global_asm_806FDAB8(aad->unk10, MAX(0.0f, temp_f2));
            current_actor_pointer->unk160 = MAX(0.0f, temp_f2);
            if (sp84 <= temp_f2) {
                if (
                    (aad->unk8 >= aad->unkC) && 
                    (
                        (current_actor_pointer->unk15F == 6) || 
                        (aad->unkC < aad->unk8) || 
                        (D_807FC7D8 >= 0x5B)
                    )) {
                    current_actor_pointer->control_state = 5;
                    current_actor_pointer->control_state_progress = 0;
                } else if (current_actor_pointer->unk15F == 6) {
                    if ((s32) (sp84 / 3.1415927f) & 1) {
                        playSound(0x8E, 0x58EFU, 63.0f, 1.0f, 5, 0);
                    } else {
                        playSound(0x8F, 0x58EFU, 63.0f, 1.0f, 5, 0);
                    }
                }
                if (delta == 0xA) {
                    current_actor_pointer->control_state = 4;
                }
            }
            if (current_actor_pointer->unk15F == 6) {
                sprintf(&sp60, "%.2d", delta);
            } else if (current_actor_pointer->control_state != 5) {
                sprintf(&sp60, "%.2d:%.2d:%.2d", delta / 60, delta % 60, 0x63 - D_807FC7D8);
            } else {
                sprintf(&sp60, "00:00:00");
            }
            current_actor_pointer->unk168 = strlen(&sp60);
            func_global_asm_806FDF1C(aad->unk10, &sp60);
        } else {
            current_actor_pointer->control_state = 5;
            current_actor_pointer->control_state_progress = 0;
            func_global_asm_806FDF1C(aad->unk10, "00:00:00");
        }
        break;
    case 5:
        switch (current_map) {
            case MAP_BATTLE_ARENA_BEAVER_BRAWL:
            case MAP_BATTLE_ARENA_KRITTER_KARNAGE:
            case MAP_BATTLE_ARENA_ARENA_AMBUSH:
            case MAP_BATTLE_ARENA_MORE_KRITTER_KARNAGE:
            case MAP_BATTLE_ARENA_FOREST_FRACAS:
            case MAP_BATTLE_ARENA_BISH_BASH_BRAWL:
            case MAP_BATTLE_ARENA_KAMIKAZE_KREMLINGS:
            case MAP_BATTLE_ARENA_PLINTH_PANIC:
            case MAP_BATTLE_ARENA_PINNACLE_PALAVER:
            case MAP_BATTLE_ARENA_SHOCKWAVE_SHOWDOWN:
                switch (current_actor_pointer->control_state_progress) {               /* switch 4 */
                    case 0:
                    case 7:
                    case 14:
                    case 21:
                    case 28:
                    case 35:
                    case 42:
                        playSound(0x3BD, 0x7FFFU, 63.0f, 1.15f, 1, 0x80);
                        break;
                }
                current_actor_pointer->control_state_progress++;
                break;
            case MAP_AZTEC_FIVE_DOOR_TEMPLE_DK:
            case MAP_AZTEC_FIVE_DOOR_TEMPLE_DIDDY:
            case MAP_AZTEC_FIVE_DOOR_TEMPLE_TINY:
            case MAP_AZTEC_FIVE_DOOR_TEMPLE_LANKY:
            case MAP_AZTEC_FIVE_DOOR_TEMPLE_CHUNKY:
                break;
            case MAP_KROOL_FIGHT_DK_PHASE:
            case MAP_KROOL_FIGHT_DIDDY_PHASE:
            case MAP_KROOL_FIGHT_LANKY_PHASE:
            case MAP_KROOL_FIGHT_TINY_PHASE:
            case MAP_KROOL_FIGHT_CHUNKY_PHASE:
                break;
            default:
            case MAP_AZTEC_LLAMA_TEMPLE:
                if (current_actor_pointer->control_state_progress == 0) {
                    playSound(0x1BB, 0x7FFFU, 63.0f, 1.0f, 0, 0);
                    current_actor_pointer->control_state_progress++;                    
                }
                break;
        }
        current_actor_pointer->unk168 = 0;
        if ((delta <= 0) && (delta >= -2)) {
            func_global_asm_806FDAB8(aad->unk10,
                (
                    (
                        (rand() >> 0xF) % 180 / 180.0
                    ) * 3.1415927410125732
                ) + 1.5707963705062866
            );
        }
        break;
    }
    addActorToTextOverlayRenderArray(func_global_asm_806A2B90, current_actor_pointer, 7U);
}

void func_global_asm_806A36F4(void) {

}

