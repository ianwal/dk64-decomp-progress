#include <ultra64.h>
#include "functions.h"


void func_8002920C(void);

void func_805FF168(void);

void func_807313BC(void);
void func_805FFFC8(void);

extern u8 D_807445E0[]; // level_index_mapping
extern s32 D_80744720[] = {
    0x181, // Kong Unlocked: DK
    0x6, // Kong Unlocked: Diddy
    0x46, // Kong Unlocked: Lanky
    0x42, // Kong Unlocked: Tiny
    0x75, // Kong Unlocked: Chunky
}; // kong_unlocked_flag_mapping

extern u16 D_80744734[] = { // lobby_array
   MAP_JAPES_LOBBY,
   MAP_AZTEC_LOBBY,
   MAP_FACTORY_LOBBY,
   MAP_GALLEON_LOBBY,
   MAP_FUNGI_LOBBY,
   MAP_CAVES_LOBBY,
   MAP_CASTLE_LOBBY,
   MAP_HELM_LOBBY,
   MAP_HELM_LOBBY, // TODO: Why is this here twice?
}; // lobby_array

typedef struct {
    s32 unk0;
    s32 unk4; // Permanent Flag Index
} GlobalASMStruct41;
extern GlobalASMStruct41 D_80744800[];
extern u8 D_80744820;
extern u8 D_80744824;
extern u8 D_80744828;
extern u8 D_807444F8;
extern u8 D_807565E0[];
extern u8 D_80756630[];
extern u16 D_807446C0[];
extern s16 D_8076AEF2;
extern u8 D_8076A0B1;
extern u8 D_8076A0B2;
extern u8 loading_zone_transition_type;
extern f32 loading_zone_transition_speed;
extern u16 D_8076AEF4;
extern u8 D_8076AEF6;

typedef struct global_asm_struct_1 {
    u8 unk0; // inSubmap?
    u8 unk1;
    s16 unk2;
    f32 unk4; // X Position
    f32 unk8; // Y Position
    f32 unkC; // Z Position
    s16 unk10; // Y Rotation
    s16 unk12; // Map
    u8 unk14; // Used
    u8 unk15;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20; // Used
    u8 pad24[0x9C];
} GlobalASMStruct1; // Size 0xC0

extern GlobalASMStruct1 D_8076A160[];
extern s16 D_8076AEE2;
extern f32 D_8076AEE4; // X Position
extern f32 D_8076AEE8; // Y Position
extern f32 D_8076AEEC; // Z Position
extern s16 D_8076AEF0; // Angle?

extern s32 D_807F6010;
extern s32 D_807FBB68;
extern u16 D_807FC930[];

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_3C10/func_805FEF10.s")

/*
// TODO: Close
// arg0 appears to be a pointer to a flag index
s32 func_805FEF10(s32 *arg0) {
    s32 found;
    s32 i;
    s32 max = 4;

    found = FALSE;
    for (i = 0; !found && i < max; i++) {
        found = player_pointer->unk58 == D_80744800[i].unk0;
        if (found) {
            *arg0 = D_80744800[i].unk4;
        }
    }
    return found;
}
*/

s32 func_805FEF74(Maps map) {
    s32 lobbyIndex;

    for (lobbyIndex = 0; lobbyIndex < 9; lobbyIndex++) {
        if (map == D_80744734[lobbyIndex]) {
            return TRUE;
        }
    }

    return FALSE;
}

// level_index_mapping lookup
u8 func_805FF000(u8 map) {
    return D_807445E0[map];
}

// TODO: Yuk, get rid of temp variable if possible
// getKongUnlockedFlagIndex(s32 actorBehaviour, s32 kongIndex);
s32 func_805FF018(s32 actorBehaviour, s32 kongIndex) {
    s32 temp;
    temp = D_80744720[kongIndex];
    return temp;
}

// Returns a level index for a given map
u8 getLevelIndex(u8 map, u8 arg1) {
    u8 levelIndex;
    Maps _map;
    s32 sp24;
    s32 temp;

    _map = map;
    levelIndex = D_807445E0[_map];
    if ((levelIndex == 0xD) || (levelIndex == 9)) {
        if (func_805FF800(&_map, &sp24)) {
            levelIndex = D_807445E0[_map];
        }
    }
    if (arg1) {
        if (func_805FEF74(_map)) {
            levelIndex = 7;
        }
    }
    return levelIndex;
}

u8 func_805FF0C8(void) {
    s32 levelIndex = getLevelIndex(D_8076A0AB, FALSE);
    return D_807FC930[levelIndex] >= D_807446C0[levelIndex];
}

void func_805FF118(void) {
    s32 i;
    for (i = 0; i < 18; i++) {
        D_8076A160[i].unk0 = FALSE;
    }
}

void func_805FF158(u8 arg0) {
    D_80744824 = arg0;
}

void func_805FF168(void) {
    loading_zone_transition_type = D_80744824;
    D_80744824 = 1;
}

void func_805FF188(s16 arg0, u8 arg1) {
    D_80744828 = 1;
    D_8076AEF4 = arg0;
    D_8076AEF6 = arg1;
}

typedef struct {
    u16 void_map;
    u16 dest_map;
    u8 dest_exit;
    u8 unk5;
} struct_void_location;

extern struct_void_location D_8074475C[];
extern u8 D_80744828;
extern u16 D_8076AEF4;
extern u8 D_8076AEF6;

extern u16 D_80744748[];

void func_805FF1B0(s32 player_index) {
    u16 pad;
    u16 new_map;
    s32 limit;
    s32 i;
    u16 new_exit;
    u8 found_special_void;

    limit = 0xB;
    i = 0;
    new_exit = 0;
    found_special_void = FALSE;
    if (D_80744828 != 0) {
        new_map = D_8076AEF4; // Void Map
        new_exit = D_8076AEF6; // Void Exit
    } else {
        found_special_void = FALSE;
        if (func_805FEF74(current_map) != 0) {
            new_map = (u16)current_map;
        } else {
            s32 level_index;
            found_special_void = 0;
            new_exit = 0;
            level_index = getLevelIndex((u8)current_map, 0U);
            new_map = D_80744748[level_index];
            while ((!found_special_void) && (i < limit)) {
                if (current_map == D_8074475C[i].void_map) {
                    new_map = D_8074475C[i].dest_map;
                    new_exit = D_8074475C[i].dest_exit;
                    found_special_void = TRUE;
                }
                i++;
            }
        }
    }
    if (!found_special_void) {
        func_805FFFC8();
    }
    func_805FF378(new_map, new_exit);
    D_80744828 = 0;
}

void func_805FF2F4(void) {
    Maps map;
    s32 exit;

    if (current_map != MAP_DK_ISLES_OVERWORLD) {
        func_805FFFC8();
        map = D_80744734[getLevelIndex(D_8076A0AB, FALSE)];
        exit = 1;
    } else {
        map = current_map;
        exit = 0;
    }
    setFlag(0x6E, TRUE, FLAG_TYPE_TEMPORARY);
    func_805FF378(map, exit);
}

void func_805FF378(Maps nextMap, s32 nextExit) {
    func_806F5378();
    if (is_cutscene_active == 6 || !func_80712798()) {
        func_80712F10(&nextMap, &nextExit);
        if (nextMap != -1) {
            if (current_character_index[0] >= 6) {
                current_character_index[0] = func_806C8DE0(0);
            }
            D_8076A0B1 |= 1;
            D_8076AEF2 = current_map;
            next_map = nextMap;
            next_exit = nextExit;
            D_8076A0B2 = 3;
            func_805FF168();
            loading_zone_transition_speed = 1.0f;
            if (D_807444F8 != 1 && loading_zone_transition_type == 1 && !(D_807FBB68 & 2) && current_map != MAP_DK_RAP) {
                playSong(0x2C, 1.0f);
            }
            func_807313BC();
            func_805FF5A0(nextMap);
            if (D_807FBB64 & 1) {
                func_8002920C();
            }
        }
    }
}

void func_805FF4D8(Maps map, s32 exit) {
    func_806F5378();
    global_properties_bitfield |= 0x100;
    next_map = map;
    next_exit = exit;
    D_8076AEF2 = current_map;
    func_807313BC();
    func_805FF5A0(map);
}

typedef struct {
    s32 unk0; // Map
    s32 unk4; // Map
    s32 unk8; // Exit
} GlobalASMStruct42;

extern GlobalASMStruct42 D_807447A0[];

void func_805FF544(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (current_map == D_807447A0[i].unk0) {
            func_805FF378(D_807447A0[i].unk4, D_807447A0[i].unk8);
            return;
        }
    }
}

void func_805FF5A0(Maps map) {
    s32 index = func_80600080(map);

    if (index != -1) {
        D_8076AEE2 = D_8076A160[index].unk2;
        D_8076AEE4 = D_8076A160[index].unk4; // X Position (exit)
        D_8076AEE8 = D_8076A160[index].unk8; // Y Position (exit)
        D_8076AEEC = D_8076A160[index].unkC; // Z Position (exit)
        D_8076AEF0 = D_8076A160[index].unk10; // Angle? (exit)
    } else {
        D_8076AEE2 = 0;
    }
}

void func_805FF628(Maps map, s32 exit) {
    func_805FFEF8(current_map);
    func_805FF378(map, exit);
}

void func_805FF660(u8 arg0) {
    D_80744820 = arg0;
}

void func_806A5DF0(s32, f32, f32, f32, u16, s32, s32, s32);

void func_805FF670(void) {
    f32 temp_f20;
    s16 spawn_x;
    s16 spawn_z;
    s16 phi_s1;

    if (D_80744820 != 0) {
        playCutscene(player_pointer, 2, 5);
        func_806F8BC4(1, 0, 0);
        for (phi_s1 = 0; phi_s1 < D_80744820; phi_s1++) {
            temp_f20 = (phi_s1 * 2) + 0x1E;
            spawn_x = player_pointer->x_position - (func_80612794(player_pointer->y_rotation) * temp_f20);
            spawn_z = player_pointer->z_position - (func_80612790(player_pointer->y_rotation) * temp_f20);
            func_806A5DF0(
                0x35,
                spawn_x,
                player_pointer->y_position + 20.0f + (phi_s1 * 5),
                spawn_z,
                player_pointer->y_rotation,
                1,
                -1,
                0
            );
        }
        D_80744820 = 0;
    }
}

s32 func_805FF800(Maps *arg0, s32 *arg1) {
    s32 phi_v1 = FALSE;
    s32 i = 0;

    while (i < 18 && !phi_v1) {
        if (D_8076A160[i].unk0 && (D_8076A160[i].unk2 & 2)) {
            phi_v1 = TRUE;
        } else {
            i++;
        }
    }
    if (phi_v1) {
        *arg0 = D_8076A160[i].unk12; // Map
        *arg1 = D_8076A160[i].unk14;
    }
    return phi_v1;
}

void func_805FF898(void) {
    Maps map;
    s32 exit;

    if (func_805FF800(&map, &exit)) {
        func_805FFEF8(current_map);
        func_805FF378(map, exit);
        return;
    }
    if (gameIsInSnidesBonusGameMode()) {
        func_805FF378(MAP_SNIDES_HQ, 0);
    }
}

void func_805FF8F8(void) {
    if (gameIsInMysteryMenuMinigameMode()) {
        func_805FF378(MAP_MAIN_MENU, 0);
    } else {
        func_805FF898();
    }
}

// arg0 likely map
s32 func_805FF938(s16 arg0) {
    s32 phi_v1 = FALSE;
    s32 i = 0;

    while (i < 18 && !phi_v1) {
        if (D_8076A160[i].unk0 && (arg0 == D_8076A160[i].unk12)) {
            phi_v1 = TRUE;
        } else {
            i++;
        }
    }
    return phi_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_3C10/func_805FF9AC.s")

extern u8 D_80750ACC;
extern f64 D_80756680;
extern s32 D_807FD56C;
extern s16 D_807FD570;

extern s32 D_807F6C28;

/*
// Eh, made some progress...
void func_805FF9AC(enum map_e arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 sp50;
    s32 sp4C;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    GlobalASMStruct1 *var_s1;
    GlobalASMStruct1 *var_v0_3;
    f64 temp_f20;
    s16 var_s0;
    s32 var_v0;
    s32 i;
    PlayerAdditionalActorData *temp_v0;

    var_v0 = FALSE;
    i = 0;
    while ((i < 0x12) && (!var_v0)) {
        if ((D_8076A160[i].unk0 != 0) && (current_map == D_8076A160[i].unk12)) {
            var_v0 = TRUE;
        } else {
            i += 1;
        }
    }
    if (var_v0) {
        var_s1 = &D_8076A160[i];
        sp4C = i;
        func_805FFEF8(current_map);
        goto block_17;
    }
    var_v0 = FALSE;
    i = 0;
    while ((i < 0x12) && (!var_v0)) {
        if (D_8076A160[i].unk0 == 0) {
            var_v0 = TRUE;
        } else {
            i++;
        }
    }
    var_s1 = &D_8076A160[i];
    if (!var_v0) {
        sp4C = i;
        func_80732354(0xA, 0, 0, 0);
block_17:
        i = sp4C;
    }
    sp4C = i;
    func_806F5378();
    func_8063B8D8(&var_s1->unk18, &sp50);
    func_806115A8(&var_s1->unk18);
    func_8063BBB0(&var_s1->unk20, &var_s1->unk1C);
    if (var_s1->unk20 != 0) {
        func_806115A8(&var_s1->unk20);
    }
    var_s1->unk2 = arg3;
    if (arg3 & 1) {
        var_s1->unk4 = player_pointer->x_position;
        var_s1->unk8 = player_pointer->y_position;
        var_s1->unkC = player_pointer->z_position;
        var_s1->unk10 = player_pointer->y_rotation;
    }
    var_s1->unk12 = current_map;
    if (arg3 & 2) {
        var_s1->unk14 = arg2;
    }
    var_s0 = 0;
    temp_f20 = D_80756680;
    var_v0_3 = &D_8076A160[sp4C];
    for (var_s0 = 0; var_s0 < D_807F6C28; var_s0++) {
        func_80659620(&sp40, &sp3C, &sp38, var_s0);
        var_v0_3->pad24[0] = sp40 * temp_f20;
        var_v0_3->pad24[1] = sp3C * temp_f20;
        var_v0_3->pad24[2] = sp38 * temp_f20;
        var_v0_3 += 3;
    }
    D_80750ACC = 1;
    temp_v0 = player_pointer->PaaD;
    D_807FD56C = temp_v0->unk1F0;
    if (temp_v0->unk1AC != NULL) {
        D_807FD570 = temp_v0->unk1AC->unk58;
    } else {
        D_807FD570 = 0;
    }
    var_s1->unk0 = 1;
    func_805FF378(arg0, arg1);
}
*/

// arg0 likely map
s32 func_805FFE50(s32 arg0, s16 arg1, s16 arg2) {
    s32 i = 0;
    s32 phi_a3 = FALSE;

    while (!phi_a3 && i < 18) {
        if (arg0 == D_8076A160[i].unk12) {
            phi_a3 = TRUE;
        } else {
            i++;
        }
    }
    if (!phi_a3) {
        return FALSE;
    }
    func_8063BEC0(D_8076A160[i].unk20, D_8076A160[i].unk1C, arg1, arg2);
    return TRUE;
}

void func_805FFEF8(Maps map) {
    s32 phi_v1 = FALSE;
    s32 i = 0;

    while (i < 18 && !phi_v1) {
        if (D_8076A160[i].unk0 && (map == D_8076A160[i].unk12)) {
            phi_v1 = TRUE;
        } else {
            i++;
        }
    }
    if (phi_v1) {
        func_80611614(&D_8076A160[i].unk18);
        func_8061130C(D_8076A160[i].unk18);
        if (D_8076A160[i].unk1C != 0) {
            func_80611614(&D_8076A160[i].unk20);
            func_8061130C(D_8076A160[i].unk20);
        }
        D_8076A160[i].unk0 = FALSE;
        D_807F6010 = 0;
    }
}

void func_805FFFC8(void) {
    s32 i;
    for (i = 0; i < 18; i++) {
        if (D_8076A160[i].unk0) {
            func_80611614(&D_8076A160[i].unk18);
            func_8061130C(D_8076A160[i].unk18);
            if (D_8076A160[i].unk1C != 0) {
                func_80611614(&D_8076A160[i].unk20);
                func_8061130C(D_8076A160[i].unk20);
            }
            D_8076A160[i].unk0 = FALSE;
        }
    }
}

void func_80600044(s32 arg0) {
    func_805FFFC8();
    func_805FF378(D_80744734[arg0], 1);
}

s32 func_80600080(Maps map) {
    s32 i;
    for (i = 0; i < 18; i++) {
        if (D_8076A160[i].unk0 && map == D_8076A160[i].unk12) {
            return i;
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_3C10/func_80600174.s")

/*
// TODO: Bleh, matches everything except for some extra lui instructions being generated for some reason
s16 func_80600174(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;
    GlobalASMStruct1* focused_parent;
    for (i = 0; i < 18; i++) {
        if (D_8076A160[i].unk0) {
            if ((D_8076A160[i].unk2 & 1)) {
                focused_parent = &D_8076A160[i];
                *arg0 = focused_parent->unk4;
                *arg1 = focused_parent->unk8;
                *arg2 = focused_parent->unkC;
                return i;
            }
        }
    }
    return -1;
}
*/

int func_80689C20(s32, s32, s32, s32, f32, f32);
void func_80631F58(s32, s32, s32);
s16 func_80600174(f32*, f32*, f32*);

s32 func_80600340(s32 arg0, u8 arg1, s32 *arg2) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 sp30;
    f32 sp2C;
    u8 temp_1 = func_80600174(&sp34, &sp30, &sp2C);
    if (temp_1 == -1) {
        return -1;
    }
    func_80631F58(D_8076A160[temp_1].unk18, &sp3C, &sp38);
    *arg2 = D_8076A160[temp_1].unk12;
    return func_80689C20(sp38, arg0, arg1, sp34, sp30, sp2C);
}

typedef struct global_asm_struct_2 {
    s32 unk0; // Bitfield
    s32 unk4;
    s32 unk8;
} GlobalASMStruct2;

extern GlobalASMStruct2 D_8074482C[];
extern GlobalASMStruct2 D_80744834[];

void func_806003EC(s16 arg0) {
    D_807FBB64 = D_8074482C[arg0].unk0;
    D_807FBB68 = D_8074482C[arg0].unk4;
}

s32 func_8060042C(s16 arg0) {
    return D_80744834[arg0].unk0;
}

u8 func_80600454(s16 arg0, u8 *arg1) {
    u8 i = 0;
    u8 hadSeenFirstTimeText = FALSE;

    while (D_807565E0[i] && arg0 != D_807565E0[i]) {
        i++;
    }
    if (D_807565E0[i] != 0) {
        *arg1 = D_80756630[i];
        if (i < 0xD) {
            // Level first time caption (FTT) seen
            hadSeenFirstTimeText = !isFlagSet(0x307 + i, FLAG_TYPE_PERMANENT);
            setFlag(0x307 + i, TRUE, FLAG_TYPE_PERMANENT);
        } else {
            hadSeenFirstTimeText = TRUE;
        }
    }
    return hadSeenFirstTimeText;
}

// TODO: This is pretty ugly, can it be turned into a for loop while still matching?
s32 func_80600530(void) { // getLobbyIndex()
    s32 foundLobby;
    s32 i;

    i = 0;
    foundLobby = FALSE;

    while (!foundLobby && i < 8) {
        if (current_map == D_80744734[i]) {
            foundLobby = TRUE;
        } else {
            i++;
        }
    }

    if (!foundLobby) {
        i = 0;
    }
    return i;
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_3C10/func_80600590.s")

// Delay slot problem
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_3C10/func_80600674.s")

extern u32 D_80744478;
extern u8 D_80745290;
extern u32 D_80767CC4;
extern s16 D_8076AF00[8];
extern u32 D_8076AF10;
extern u8 D_8076AF14;

/*
Lag calculation formula
incredibly beefy
void func_80600674(void) {
    s16 *lagboost_arrayaddr;
    s32 lagboost_currtest;
    s32 lagboost_pasttest;
    s32 lagboost_min;
    s32 lagboost_max;
    s32 lagboost_new;
    s32 temp_s0;
    s32 lagboost_initialslot;
    s32 lagboost_searchrange;
    s32 var_t3;
    s32 counter;
    u32 temp_a2;
    s32 i;

    lagboost_min = 1;
    lagboost_max = 0x14;
    if (D_8076AF14 != 0) {
        lagboost_new = D_80767A40.frame_count - D_8076AF10;
        if (lagboost_new <= 0) {
            lagboost_new = 1;
        }
        counter = 0;
        D_8076AF00[D_80745290] = lagboost_new;
        lagboost_initialslot = D_80745290 + 1;
        D_80745290 = lagboost_initialslot;
        if (lagboost_initialslot == 8) {
            D_80745290 = 0;
            lagboost_initialslot = 0;
        }
        if (D_80744478 >= 4U) {
            lagboost_searchrange = 1;
        } else {
            lagboost_searchrange = 4;
            if (D_80744478 < lagboost_new) {
                lagboost_searchrange = 2;
            }
        }
        var_t3 = lagboost_initialslot;
        if (lagboost_searchrange > 0) {
            temp_s0 = lagboost_searchrange & 3;
            if (temp_s0 != 0) {
                do {
                    var_t3--;
                    if (var_t3 < 0) {
                        var_t3 = 7;
                    }
                    lagboost_currtest = D_8076AF00[var_t3];
                    counter += 1;
                    if (lagboost_currtest >= lagboost_min) {
                        lagboost_min = lagboost_currtest;
                    }
                    if (lagboost_max >= lagboost_currtest) {
                        lagboost_max = lagboost_currtest;
                    }
                } while (temp_s0 != counter);
                if (counter != lagboost_searchrange) {
                    goto loop_21;
                }
            } else {
                do {
loop_21:
                    var_t3--;
                    if (var_t3 < 0) {
                        var_t3 = 7;
                    }
                    lagboost_arrayaddr = &D_8076AF00[var_t3];
                    lagboost_pasttest = *lagboost_arrayaddr;
                    var_t3--;
                    counter += 4;
                    if (lagboost_pasttest >= lagboost_min) {
                        lagboost_min = lagboost_pasttest;
                    }
                    if (lagboost_max >= lagboost_pasttest) {
                        lagboost_max = lagboost_pasttest;
                    }
                    for (i = 0; i < 3; i++) {
                        lagboost_arrayaddr = &lagboost_arrayaddr[-1];
                        if (var_t3 < 0) {
                            lagboost_arrayaddr = &D_8076AF00[7];
                            var_t3 = 7;
                        }
                        lagboost_pasttest = *lagboost_arrayaddr;
                        if (i < 2) {
                            var_t3--;
                        }
                        if (lagboost_pasttest >= lagboost_min) {
                            lagboost_min = lagboost_pasttest;
                        }
                        if (lagboost_max >= lagboost_pasttest) {
                            lagboost_max = lagboost_pasttest;
                        }
                    }
                } while (counter != lagboost_searchrange);
            }
        }
        if (
            ((D_80744478 < lagboost_new) && (D_80744478 < lagboost_max)) ||
            (lagboost_new < D_80744478) && (lagboost_min < D_80744478)
        ) {
            D_80744478 = lagboost_new;
        }
        if (object_timer >= 11U) {
            temp_a2 = D_8076AF10 + D_80744478;
            if (D_80767A40.frame_count < temp_a2) {
                do {

                } while (D_80767CC4 < temp_a2);
            }
        }
    } else {
        D_80744478 = D_80767A40.frame_count - D_8076AF10;
    }
    D_8076AF10 = D_80767A40.frame_count;
}
*/
