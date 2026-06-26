#include "common.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} AAD_critter_800296DC;

typedef struct {
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s16 unk4;
} AAD_critter_80029118;

// .data
s8 D_critter_80029FA0 = 0; // Referenced in func_global_asm_806F54E0
static u16 D_critter_80029FA4 = 0;
static s8 D_critter_80029FA8 = 0;

extern u16 D_global_asm_807FCC44;

s32 func_global_asm_806A2A10(s32, s32, u8);
u8 func_global_asm_806FDB8C(s16, s32, s32, f32, f32, f32);
s32 (*func_critter_80029110(s32))(s32 *, s32);

// rodata
// const char D_critter_8002A190[] = "WELL DONE!";
// const char D_critter_8002A19C[] = "TIME OUT!";

s32 (*func_critter_80029110(s32 arg0))(s32 *, s32) {
    return ~arg0;
}

extern OSIoMesg D_global_asm_807ECE00;
extern UnkMQStruct D_global_asm_807655F0;

extern u16 D_critter_80029FA4;
extern u16 D_global_asm_807FCC44;

void func_critter_80029118(void) {
    s32 pad;
    s32 (*temp_v1)(s32 *, s32);
    s32 *var_s0;
    s32 var_v0;
    s32 flagIndex;
    s32 (*dmafunc)(OSIoMesg *, s32, s32, u32, s32 *, u32, OSMesgQueue *);
    s32 textIndex;
    s32 sp58[7];
    s32 (*recvfunc)(OSMesgQueue *, OSMesg *, s32);
    s32 (*sp50)(s32 *, s32);
    s32 temp2;
    u32 temp;
    s32 pad2;
    AAD_critter_80029118 *aaD;
    Maps sp40;
    s32 sp3C;

    aaD = gCurrentActorPointer->additional_actor_data;
    temp2 = 0;
    if (ACTOR_UNINITIALIZED(gCurrentActorPointer)) {
        D_critter_80029FA8 = FALSE;
        playCutscene(NULL, 0, 1);
        temp = D_global_asm_807FCC44;
        D_critter_80029FA4 = temp;
        D_global_asm_807FCC44 = temp2;
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
        gCurrentActorPointer->control_state = 0;
    }
    
    switch (gCurrentActorPointer->control_state) {
        case 0x0:
            if (is_cutscene_active == 1) {
                if (func_global_asm_8061CB38()) {
                    switch (current_map) {
                        case MAP_DIVE_BARREL:
                            textIndex = 0;
                            break;
                        case MAP_VINE_BARREL:
                            textIndex = 1;
                            break;
                        case MAP_ORANGE_BARREL:
                            textIndex = 2;
                            break;
                        case MAP_BARREL_BARREL:
                            textIndex = 3;
                            break;
                    }
                    loadText(gCurrentActorPointer, 0x19, textIndex);
                    gCurrentActorPointer->control_state = 1;
                    
                    func_global_asm_806A2A10(0xDC, 0x2A, aaD->unk4);
                }
            }
            break;
        case 0x1:
            if (!(gCurrentActorPointer->object_properties_bitfield & 0x2000000)) {
                func_global_asm_8061CB08();
                gCurrentActorPointer->control_state = 2;
                func_global_asm_806A2B08(gCurrentActorPointer->unk11C);
                playSong(MUSIC_8_BONUS_MINIGAMES, 1.0f);
            }
            break;
        case 0x2:
            var_s0 = sp58;
            while ((u32)(var_s0) & 7) {
                var_s0++;
            }
            temp = &osWritebackDCache;
            temp_v1 = func_critter_80029110(~temp);
            if (D_critter_80029FA0 <= 0) {
                gCurrentActorPointer->control_state = 3;
            }
            temp_v1(var_s0, 0x10);

            sp50 = func_critter_80029110(-0xDC1);
            temp = &osPiStartDma;
            dmafunc = func_critter_80029110(~temp);
            dmafunc(&D_global_asm_807ECE00, 0, 0, sp50, var_s0, 0x10, &D_global_asm_807655F0);

            if (gCurrentActorPointer->unk11C->control_state == 5) {
                gCurrentActorPointer->control_state = 0xFF;
            }
            temp = &osRecvMesg;
            recvfunc = func_critter_80029110(~temp);
            recvfunc(&D_global_asm_807655F0, NULL, 1);

            temp = &osInvalDCache;
            temp_v1 = func_critter_80029110(~temp);
            temp_v1(var_s0, 0x10);
            // fake match
            if (D_critter_80029FA4 && D_critter_80029FA4) {}

            var_s0[0] += var_s0[1];
            // Anti tamper?
            if (var_s0[0] != 0x0A78F00E) {
                var_v0 = current_map == MAP_VINE_BARREL ? PERMFLAG_ITEM_MOVE_ORANGETHROWING : PERMFLAG_ITEM_MOVE_VINES;
                setFlag(var_v0, FALSE, FLAG_TYPE_PERMANENT);
            }
            break;
        case 0x3:
            gCurrentActorPointer->unk11C->control_state = 1;
            aaD->unk2 = func_global_asm_806FDB8C(1, "WELL DONE!", 2, 160.0f, 100.0f, 0.0f);
            playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
            aaD->unk0 = 0x78;
            gCurrentActorPointer->control_state = 0xFE;
            D_critter_80029FA8 = TRUE;
            break;
        case 0xFE:
            if (aaD->unk0 > 0) {
                aaD->unk0--;
                if (aaD->unk0 == 0) {
                    if ((s8)D_critter_80029FA8 != FALSE) {
                        if (current_map == MAP_ORANGE_BARREL) {
                            D_critter_80029FA4 = 20;
                        }

                        switch (current_map) {
                            case MAP_DIVE_BARREL:
                                flagIndex = PERMFLAG_ITEM_MOVE_DIVING;
                                break;
                            case MAP_VINE_BARREL:
                                flagIndex = PERMFLAG_ITEM_MOVE_VINES;
                                break;
                            case MAP_ORANGE_BARREL:
                                flagIndex = PERMFLAG_ITEM_MOVE_ORANGETHROWING;
                                break;
                            case MAP_BARREL_BARREL:
                                flagIndex = PERMFLAG_ITEM_MOVE_BARRELTHROWING;
                                break;
                            default:
                                flagIndex = sp58[6];
                                break;
                        }
                        setFlag(flagIndex, TRUE, FLAG_TYPE_PERMANENT);
                    }
                    D_global_asm_807FCC44 = D_critter_80029FA4;
                    func_global_asm_806F8A8C(4, 0, D_critter_80029FA4);
                    func_global_asm_805FF800(&sp40, &sp3C);
                    func_global_asm_805FF628(sp40, 0);
                }
            }
            break;
        case 0xFF:
            D_critter_80029FA8 = FALSE;
            aaD->unk2 = func_global_asm_806FDB8C(1, "TIME OUT!", 2, 160.0f, 100.0f, 0.0f);
            aaD->unk0 = 0x78;
            gCurrentActorPointer->control_state = 0xFE;
            break;
    }
    
    addActorToTextOverlayRenderArray(func_critter_800296DC, gCurrentActorPointer, 3);
}

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
