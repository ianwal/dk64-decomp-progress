#include <ultra64.h>
#include "functions.h"

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    u8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    s16 unkA;
    u8 unkC;
    u8 unkD;
} AAD_8002D010;

typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    s16 unkA;
    u8 unkC;
    u8 unkD;
} AAD_8002D2F0;

extern s8 D_bonus_8002D910[];
extern s8 D_bonus_8002D91C[];
extern s8 D_bonus_8002D920;
extern s8 D_bonus_8002D924;
extern s8 D_bonus_8002D928;
extern s8 D_bonus_8002D92C;
extern s8 D_bonus_8002D930;
extern s8 D_bonus_8002DEF0[];

extern s16 D_80744518;
extern u16 D_807ECD60;

void func_global_asm_8061CB08(void);
Gfx *func_global_asm_8068DC54(Gfx*, s32, s32, void*, s16, void*);
s32 func_global_asm_806A2A10(s32, s32, u8);
s8 func_global_asm_806FDB8C(s32, void*, s32, f32, f32, f32);

Gfx *func_bonus_8002D010(Gfx *dl, Actor *arg1) {
    s16 pad;
    s16 i;
    s16 y;
    AAD_8002D010 *aaD;
    char sp70[17];

    aaD = arg1->additional_actor_data;

    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xC8, 0xC8, 0xC8, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetRenderMode(dl++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gSPMatrix(dl++, &D_2000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    dl = func_global_asm_806FE078(dl, aaD->unk3, 8, 30.0f, 36.0f, 0.0f, 1.0f);
    dl = func_global_asm_8068DC54(dl, 0x26, 0x2D, &aaD->unk8, aaD->unkA, &aaD->unk6);

    if (aaD->unk6 > 0) {
        aaD->unk6 -= 2;
    }
    if (current_map != MAP_ENGUARDE_ARENA) {
        if ((current_map == MAP_RAMBI_ARENA) && (arg1->control_state == 2)) {
            y = 480 - (u16)(D_bonus_8002D92C * 48);
            for (i = -1; i < D_bonus_8002D92C; i++) {
                if (i >= 0) {
                    sprintf(sp70, "HIT %d", D_bonus_8002DEF0[i]);
                } else if (D_bonus_8002D92C >= 2) {
                    sprintf(sp70, "COMBO x2");
                } else {
                    sp70[0] = '\0';
                }
                dl = printStyledText(dl, 6, 640 - (getCenterOfString(6, sp70) * 2), y, sp70, 1);
                y += 48;
            }
        }
    } else {
        if (aaD->unkC != 0) {
            aaD->unkC--;
            if ((aaD->unkC & 0x1F) < 0x14) {
                dl = func_global_asm_806FE078(dl, aaD->unkD, 8, 100.0f, 100.0f, 0.0f, 1.0f);
            }
        }
    }
    return dl;
}

void func_bonus_8002D2F0(void) {
    s32 var_a0;
    u32 textIndex;
    AAD_8002D2F0 *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        playCutscene(NULL, 0, 1);
        current_actor_pointer->control_state = 0;
        aaD->unk4 = 0x3C;
        D_bonus_8002D92C = 0;
        D_bonus_8002D930 = 0;
        D_80744518 = 0;
        aaD->unk3 = func_global_asm_806FDB8C(1, "SCORE", 8, 0.0f, 0.0f, 0.0f);
        aaD->unkD = func_global_asm_806FDB8C(1, "LAP BONUS", 8, 0.0f, 0.0f, 0.0f);
        D_bonus_8002D920 = 0;
        D_bonus_8002D924 = 0;
        D_bonus_8002D928 = 0;
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (is_cutscene_active == 1) {
                if (func_global_asm_8061CB38() != 0) {
                    switch (current_map) {
                        case MAP_RAMBI_ARENA:
                            textIndex = 0x1F;
                            break;
                        case MAP_ENGUARDE_ARENA:
                            textIndex = 0x20;
                            break;
                    }
                    loadText(current_actor_pointer, 0, textIndex);
                    current_actor_pointer->control_state = 1;
                    func_global_asm_806A2A10(0xDC, 0x2A, aaD->unk4);
                } else if ((D_global_asm_807ECD58.unk0 & 0x8000) && !(D_807ECD60 & 0x8000)) {
                    playCutscene(player_pointer, 1, 1);
                    current_actor_pointer->control_state = 2;
                    func_global_asm_806A2A10(0xDC, 0x2A, aaD->unk4);
                    func_global_asm_806A2B08(current_actor_pointer->unk11C);
                }
            }
            break;
        case 1:
            if (!(current_actor_pointer->object_properties_bitfield & 0x02000000) || ((D_global_asm_807ECD58.unk0 & 0x8000) && !(D_807ECD60 & 0x8000))) {
                func_global_asm_8061CB08();
                current_actor_pointer->control_state = 2;
                func_global_asm_806A2B08(current_actor_pointer->unk11C);
            }
            break;
        case 2:
            if (current_actor_pointer->unk11C->control_state == 5) {
                D_bonus_8002D930 = 0;
                current_actor_pointer->control_state = 3;
                aaD->unk0 = 0x78;
            }
            switch (current_map) {
                case MAP_RAMBI_ARENA:
                    D_bonus_8002D930--;
                    if (D_bonus_8002D930 <= 0) {
                        D_bonus_8002D930 = 0;
                        if (D_bonus_8002D92C > 0) {
                            var_a0 = 0;
                            if (D_bonus_8002D92C >= 2) {
                                var_a0 = 1;
                            }
                            while (D_bonus_8002D92C > 0) {
                                D_bonus_8002D92C -= 1;
                                aaD->unkA += (D_bonus_8002DEF0[D_bonus_8002D92C] << var_a0);
                            }
                        }
                    }
                    break;
                case MAP_ENGUARDE_ARENA:
                    if (D_bonus_8002D928 != 0) {
                        aaD->unkA += D_bonus_8002D928;
                        if (D_bonus_8002D928 >= 0x33) {
                            aaD->unkC = 0x3C;
                        }
                        D_bonus_8002D928 = 0;
                    }
                    break;
            }
            break;
        case 3:
            current_actor_pointer->unk11C->control_state = 1;
            aaD->unk0--;
            if (aaD->unk0 == 0) {
                func_global_asm_805FF378(MAP_MAIN_MENU, 0);
                current_actor_pointer->control_state = 4;
            }
            break;
    }
    D_80744518 = aaD->unkA;
    addActorToTextOverlayRenderArray(func_bonus_8002D010, current_actor_pointer, 3);
}

void func_bonus_8002D6F8(s16 arg0) {
    s32 var_v1_2;
    s32 i;
    s32 j;

    D_bonus_8002D928 = 5;
    j = 0;
    do {
        if (arg0 == D_bonus_8002D91C[j]) {
            D_bonus_8002D928 += 0xF;
        }
        j++; // TODO: Ouch...
        j--; // TODO: Ouch...
    } while (++j < 4);
    i = 0;
    while (i < 0xA && arg0 != D_bonus_8002D910[i]) {
        i++;
    }
    var_v1_2 = i - 1;
    if (var_v1_2 < 0) {
        var_v1_2 = 0xA;
    }
    if (var_v1_2 == D_bonus_8002D920) {
        D_bonus_8002D924++;
        if (D_bonus_8002D924 >= 0xA) {
            D_bonus_8002D924 = 0;
            D_bonus_8002D928 += 0x32;
        }
    } else {
        D_bonus_8002D924 = 0;
    }
    D_bonus_8002D920 = i;
}

void func_bonus_8002D7E8(s16 arg0) {
    s8 phi_v0 = arg0 == 0xD4 ? 0xA : 2;

    if (D_bonus_8002D92C < 6) {
        D_bonus_8002DEF0[D_bonus_8002D92C] = phi_v0;
        D_bonus_8002D92C++;
        D_bonus_8002D930 = 0x14;
    }
    if (D_bonus_8002D92C >= 5) {
        D_bonus_8002D930 = 0;
    }
}
