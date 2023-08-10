#include <ultra64.h>
#include "functions.h"

extern u32 D_critter_8002A1C0;
extern u32 D_critter_8002A1C4;
extern void* D_critter_8002A1C8[];
extern u16 D_critter_8002A1CE;
extern u16 D_critter_8002A1CC;

void func_critter_80027340(s32 arg0) {
    s32 phi_s0;
    s32 phi_s2;

    phi_s2 = arg0;
    for (phi_s0 = 2; phi_s0 > -1; phi_s0--) {
        func_global_asm_8068842C(current_actor_pointer, phi_s0, 1);
        func_global_asm_80688370(current_actor_pointer, phi_s0, 0);
        func_global_asm_806883F4(current_actor_pointer, phi_s0, (phi_s2 % 10) + 1, 0);
        func_global_asm_80688460(current_actor_pointer, phi_s0, 0);
        phi_s2 /= 10;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80027448.s")

extern f32 D_critter_8002A110;
extern f32 D_critter_8002A114;

void func_critter_80027DC0(void) {
    s32 temp[2];
    Actor *sp34;
    f32 dx;
    f32 dz;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80604CBC(current_actor_pointer, 0x10F, 0x46, 1, 0, 0x1E, 1.0f, 0);
        current_actor_pointer->control_state = 0;
        // Is the camera not unlocked?
        if (!isFlagSet(0x179, FLAG_TYPE_PERMANENT)) {
            current_actor_pointer->control_state = 1;
        // Is the Rareware GB room open?
        } else if (isFlagSet(0x189, FLAG_TYPE_PERMANENT)) {
            func_global_asm_80614EBC(current_actor_pointer, 0x2B5);
        // Has the player photographed all 20 fairies?
        } else if (func_global_asm_80731AA8(0x24D, 20, FLAG_TYPE_PERMANENT) == 20) {
            func_global_asm_80614EBC(current_actor_pointer, 0x2B5);
            current_actor_pointer->control_state = 3;
        }
    }
    dx = current_actor_pointer->x_position - player_pointer->x_position;
    dz = current_actor_pointer->z_position - player_pointer->z_position;
    switch (current_actor_pointer->control_state) {
        case 1:
            if ((((dx * dx) + (dz * dz)) < D_critter_8002A110) != 0) {
                // Unlock the camera
                setFlag(0x179, TRUE, FLAG_TYPE_PERMANENT);
                playCutscene(player_pointer, 0, 1);
                func_global_asm_80629174();
                current_actor_pointer->control_state = 2;
            }
            break;
        case 2:
            sp34 = current_actor_pointer;
            if (current_actor_pointer->control_state_progress != 0) {
                current_actor_pointer->control_state_progress++;
                if (current_actor_pointer->control_state_progress < 0x4B) {
                    current_actor_pointer = player_pointer;
                    if ((object_timer & 3) == 0) {
                        func_global_asm_80684900(0);
                    }
                    current_actor_pointer = sp34;
                } else {
                    current_actor_pointer = player_pointer;
                    player_pointer->control_state = 0x2D;
                    player_pointer->control_state_progress = 0;
                    func_global_asm_80614E78(player_pointer, 0x42);
                    func_global_asm_80608528(player_pointer, 0xF2, 0xFF, 0x7F, 0);
                    current_actor_pointer = sp34;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80605314(player_pointer, 1);
                }
            } else if (func_global_asm_80629148()) {
                current_actor_pointer->control_state_progress = 1;
                func_global_asm_80604CBC(player_pointer, 0x104, 0x3C, 1, 1, 0xFF, 1.0f, 0);
                func_global_asm_806F8BC4(6, 0, 0);
                func_global_asm_806F91B4(6, extra_player_info_pointer->unk1A4, 999);
            }
            break;
        case 3:
            if ((((dx * dx) + (dz * dz)) < D_critter_8002A114) != 0) {
                playCutscene(current_actor_pointer, 1, 1);
                func_global_asm_80629174();
                current_actor_pointer->control_state = 4;
            }
            break;
        case 4:
            break;
    }
    func_global_asm_806319C4(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80028120.s")

void func_critter_80028840() {
    D_critter_8002A1C0 = getPointerTableFile(0x13, 4, 1, 1);
    D_critter_8002A1C8[0] = getPointerTableFile(0x13, 5, 1, 1);
    D_critter_8002A1C4 = 0;
    D_critter_8002A1CE = 0;
    D_critter_8002A1CC = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_800288A8.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80028A9C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80028DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80028EE8.s")

// close
#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_8002904C.s")

extern u16 D_critter_8002A1CC;
extern u16 D_critter_8002A1CE;
extern void *func_critter_80028DE8(Gfx *arg0, Actor *arg1);

typedef struct {
    u8 unk0[0x810 - 0x0];
    u8 unk810[1]; // TODO: How many elements?
} AAD_critter_8002904C;

/*
void func_critter_8002904C(void) {
    AAD_critter_8002904C *aaD;
    s32 temp;
    aaD = current_actor_pointer->additional_actor_data;
    if (D_critter_8002A1CC < 0xF0) {
        if (D_critter_8002A1CE >= *((u16*)D_critter_8002A1C8[D_critter_8002A1CC])) {
            D_critter_8002A1CC++;
            aaD->unk810[++current_actor_pointer->unkEE] = 0xC;
        }
    }
    if (current_actor_pointer->unk168 != 0) {
        current_actor_pointer->unk168--;
        func_global_asm_8068C350(&func_critter_80028DE8, current_actor_pointer, 3);
    }
    D_critter_8002A1CE += 1;
}
*/

s32 (*func_critter_80029110(s32 arg0))(s32 *, s32) {
    return ~arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/critter/code_3340/func_critter_80029118.s")

Gfx *func_critter_800296DC(Gfx *dl, Actor *arg1);

s32 (*func_critter_80029110(s32))(s32 *, s32);
s32 func_global_asm_8061CB08();
s32 func_global_asm_8061CB38();
s32 func_global_asm_806A2A10(s32, s32, u8);
u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);
extern s32 D_critter_80004520;
extern s32 D_critter_800046C0;
extern s32 D_critter_80006F10;
extern s8 D_critter_80029FA0;
extern u16 D_critter_80029FA4;
extern s8 D_critter_80029FA8;
extern s32 D_critter_8002A190;
extern s32 D_critter_8002A19C;
extern s32 D_global_asm_807655F0;
extern s32 D_global_asm_807ECE00;
extern u16 D_global_asm_807FCC44;

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s16 unk4;
} AAD_critter_80029118;

/*
// TODO: Pretty close considering size
void func_critter_80029118(void) {
    s32 sp74;
    s32 sp70;
    s32 sp58[6];
    s32 (*sp50)(s32 *, s32);
    enum map_e sp3C;
    s32 sp38;
    s32 (*temp_v1)(s32 *, s32);
    s32 *var_s0;
    s32 var_v0;
    s32 temp_t3;
    s32 var_v0_2;
    AAD_critter_80029118 *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_critter_80029FA8 = 0;
        playCutscene(NULL, 0, 1);
        D_critter_80029FA4 = D_global_asm_807FCC44;
        D_global_asm_807FCC44 = 0;
        func_global_asm_806F8A8C(4, 0, 0);
        switch (current_map) {
            case MAP_DIVE_BARREL:
                aaD->unk4 = 60; // 60 seconds on the clock?
                D_critter_80029FA0 = 1; // 1 coin to collect?
                break;
            case MAP_VINE_BARREL:
                aaD->unk4 = 60; // 60 seconds on the clock?
                D_critter_80029FA0 = 1; // 1 coin to collect?
                break;
            case MAP_ORANGE_BARREL:
                aaD->unk4 = 60; // 60 seconds on the clock?
                D_critter_80029FA0 = 5; // 5 oranges to throw?
                break;
            case MAP_BARREL_BARREL:
                aaD->unk4 = 60; // 60 seconds on the clock?
                D_critter_80029FA0 = 5; // 5 barrels to break?
                break;
        }
        current_actor_pointer->control_state = 0;
    }
    switch (current_actor_pointer->control_state) {
        case 0x0:
            if (is_cutscene_active == 1) {
                if (func_global_asm_8061CB38() != 0) {
                    switch (current_map) {
                        case MAP_DIVE_BARREL:
                            sp74 = 0;
                            break;
                        case MAP_VINE_BARREL:
                            sp74 = 1;
                            break;
                        case MAP_ORANGE_BARREL:
                            sp74 = 2;
                            break;
                        case MAP_BARREL_BARREL:
                            sp74 = 3;
                            break;
                    }
                    func_global_asm_8070D8C0(current_actor_pointer, 0x19, sp74);
                    current_actor_pointer->control_state = 1;
                    func_global_asm_806A2A10(0xDC, 0x2A, aaD->unk4);
                }
            }
            break;
        case 0x1:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                func_global_asm_8061CB08();
                current_actor_pointer->control_state = 2;
                func_global_asm_806A2B08(current_actor_pointer->unk11C);
                playSong(8, 1.0f);
            }
            break;
        case 0x2:
            var_s0 = &sp58;
            while ((u32)(var_s0) & 7) {
                var_s0++;
            }
            temp_v1 = func_critter_80029110(~(u32)(&osWritebackDCache));
            if (D_critter_80029FA0 <= 0) {
                current_actor_pointer->control_state = 3;
            }
            temp_v1(var_s0, 0x10);
            sp50 = func_critter_80029110(-0xDC1);
            func_critter_80029110(~(u32)(&D_critter_80006F10))(var_s0, 0x10);
            if (current_actor_pointer->unk11C->control_state == 5) {
                current_actor_pointer->control_state = 0xFF;
            }
            func_critter_80029110(~(u32)(&D_critter_800046C0))(NULL, 1);
            func_critter_80029110(~(u32)(&D_critter_80004520))(var_s0, 0x10);
            temp_t3 = var_s0[0] + var_s0[1];
            var_s0[0] = temp_t3;
            // Anti tamper?
            if (temp_t3 != 0x0A78F00E) {
                if (current_map == MAP_VINE_BARREL) {
                    var_v0 = 0x184;
                } else {
                    var_v0 = 0x183;
                }
                setFlag(var_v0, FALSE, FLAG_TYPE_PERMANENT);
            }
            break;
        case 0x3:
            current_actor_pointer->unk11C->control_state = 1;
            aaD->unk2 = func_global_asm_806FDB8C(1, &D_critter_8002A190, 2, 160.0f, 100.0f, 0.0f);
            playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
            aaD->unk0 = 0x78;
            current_actor_pointer->control_state = 0xFE;
            D_critter_80029FA8 = 1;
            break;
        case 0xFE:
            if (aaD->unk0 > 0) {
                aaD->unk0--;
                if (aaD->unk0 == 0) {
                    if (D_critter_80029FA8 != 0) {
                        if (current_map == MAP_ORANGE_BARREL) {
                            D_critter_80029FA4 = 20;
                        }
                        switch (current_map) {
                            case MAP_DIVE_BARREL:
                                var_v0_2 = 0x182;
                                break;
                            case MAP_VINE_BARREL:
                                var_v0_2 = 0x183;
                                break;
                            case MAP_ORANGE_BARREL:
                                var_v0_2 = 0x184;
                                break;
                            case MAP_BARREL_BARREL:
                                var_v0_2 = 0x185;
                                break;
                            default:
                                var_v0_2 = sp70;
                                break;
                        }
                        setFlag(var_v0_2, TRUE, FLAG_TYPE_PERMANENT);
                    }
                    D_global_asm_807FCC44 = D_critter_80029FA4;
                    func_global_asm_806F8A8C(4, 0, D_critter_80029FA4);
                    func_global_asm_805FF800(&sp3C, &sp38);
                    func_global_asm_805FF628(sp3C, 0);
                }
            }
            break;
        case 0xFF:
            D_critter_80029FA8 = 0;
            aaD->unk2 = func_global_asm_806FDB8C(1, &D_critter_8002A19C, 2, 160.0f, 100.0f, 0.0f);
            aaD->unk0 = 0x78;
            current_actor_pointer->control_state = 0xFE;
            break;
    }
    func_global_asm_8068C350(&func_critter_800296DC, current_actor_pointer, 3);
}
*/

Gfx *func_global_asm_806FE078(Gfx *, u8, s32, f32, f32, f32, f32); // extern

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} AAD_critter_800296DC;

Gfx *func_critter_800296DC(Gfx *dl, Actor *arg1) {
    AAD_critter_800296DC* aaD = arg1->additional_actor_data;
    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xC8, 0xC8, 0xC8, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetRenderMode(dl++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (arg1->control_state == 0xFE) {
        dl = func_global_asm_806FE078(dl, aaD->unk2, 2, 160.0f, 100.0f, 0.0f, 1.5f);
    }
    return dl;
}
