#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern s16 D_global_asm_807FD790[];
extern u8 D_global_asm_807FD798;
extern s16 D_global_asm_807FD722;
extern s16 D_global_asm_807FD724;
extern u8 D_global_asm_80754238[];

typedef struct {
    f32 unk0; // x
    f32 unk4; // y
    f32 unk8; // z
    f32 unkC;
} Struct807FD740;

extern Struct807FD740 D_global_asm_807FD740[];
extern Struct807FD740 *D_global_asm_807FD780[];

void func_global_asm_806F5270(void);
void func_global_asm_806F54E0(u8, s32, u8);

void func_global_asm_806F4750(void) {
    func_global_asm_806F5270();
    func_global_asm_806F4778();
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_global_asm_806F4778.s")

void func_global_asm_806F4D70(u8 playerIndex, f32 x, f32 y, f32 z, f32 arg4) {
    D_global_asm_807FD740[playerIndex].unk0 = x;
    D_global_asm_807FD740[playerIndex].unk4 = y;
    D_global_asm_807FD740[playerIndex].unk8 = z;
    D_global_asm_807FD740[playerIndex].unkC = arg4;
    D_global_asm_807FD780[playerIndex] = NULL;
}

void func_global_asm_806F4DC0(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Struct807FD740 **temp_v0_2;

    temp_v0_2 = &D_global_asm_807FD780[arg0];
    while (*temp_v0_2) {
        temp_v0_2 = *temp_v0_2 + 1;
    }
    *temp_v0_2 = malloc(0x14);
    func_global_asm_80611690(*temp_v0_2);
    (*temp_v0_2)->unk0 = arg1;
    (*temp_v0_2)->unk4 = arg2;
    (*temp_v0_2)->unk8 = arg3;
    (*temp_v0_2)->unkC = arg4;
    func_global_asm_8061134C(*temp_v0_2);
}

typedef struct {
    u16 unk0;
    s8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
} Struct80753EFC;

extern Struct80753EFC D_global_asm_80753EF0[]; // TODO: Array of 0xA structs?

// TODO: Array of 0xA structs?
s32 func_global_asm_806F4E74(s16 arg0) {
    s32 b = 0;
    s32 a = FALSE;
    s16 *ptr = &D_global_asm_80753EF0;

    while (!a) {
        if (arg0 == *ptr) {
            a = TRUE;
        } else {
            b++;
            ptr += 0xA;
        }
    }
    return b;
}

s32 func_global_asm_806F4EBC(f32 arg0, f32 arg1) {
    s32 temp_f10;
    s32 temp_f6;

    temp_f10 = arg0 / 500.0f;
    temp_f6 = arg1 / 500.0f;
    if ((D_global_asm_807FD722 < temp_f10) || (D_global_asm_807FD724 < temp_f6) || (arg0 < 0.0f) || (arg1 < 0.0f)) {
        return -1;
    }
    return (D_global_asm_807FD722 * temp_f6) + temp_f10;
}

// Very close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_global_asm_806F4F50.s")

typedef struct Struct80754244 Struct80754244;
struct Struct80754244 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u8 unkE;
    u8 unkF;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    Struct80754244 *unk18;
};

extern Struct80754244 **D_global_asm_80754244;
extern s16 D_global_asm_807FD720;

/*
void func_global_asm_806F4F50(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    Struct80754244 **temp_a1;
    Struct80754244 *prev;
    s32 pad;
    s32 j;
    Struct80754244 *curr;
    s32 temp_v0;
    s32 i;
    s32 var_t0;

    for (i = 0, var_t0 = FALSE; !var_t0 && i < D_global_asm_807FD720; i++) {
        prev = NULL;
        curr = D_global_asm_80754244[i];
        while ((curr) && (arg0 != curr->unk0)) {
            prev = curr;
            curr = curr->unk18;
        }
        if ((curr) && (arg0 == curr->unk0)) {
            var_t0 = TRUE;
            if (prev) {
                prev->unk18 = curr->unk18;
            } else {
                D_global_asm_80754244[i] = curr->unk18;
            }
        }
    }
    temp_v0 = func_global_asm_806F4EBC(arg1, arg3);
    if ((D_global_asm_807FD720 >= temp_v0) && (temp_v0 >= 0)) {
        curr->unk18 = D_global_asm_80754244[temp_v0];
        D_global_asm_80754244[temp_v0] = curr;
        curr->unk8 = arg1;
        curr->unkA = arg2;
        curr->unkC = arg3;
    }
}
*/

extern s16 D_global_asm_807FD720;
extern Struct80754244 *D_global_asm_807FD72C;

void func_global_asm_806F50C8(s16 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) {
    Struct80754244 *temp_v0_2;
    f32 x, y, z;
    f32 xRot, yRot, zRot;
    f32 scale;
    f32 sp44;
    s32 sp40;
    s32 temp_v0_3;
    Struct80754244 **var_v1;
    Struct80754244 *current;

    func_global_asm_806357F8(arg0, &x, &y, &z, &xRot, &yRot, &zRot, &scale, &sp44, 1);

    if (!arg5) {
        sp40 = func_global_asm_806F4EBC(x, z);
        if (!(D_global_asm_807FD720 >= sp40 && sp40 >= 0)) {
            return;
        }
    }

    temp_v0_2 = malloc(sizeof(Struct80754244));
    temp_v0_2->unk8 = x;
    temp_v0_2->unkA = y;
    temp_v0_2->unkC = z;
    temp_v0_2->unk0 = arg0;

    temp_v0_3 = func_global_asm_806F4E74(arg1);
    temp_v0_2->unk4 = D_global_asm_80753EF0[temp_v0_3].unkC;
    temp_v0_2->unk2 = arg1;
    temp_v0_2->unkE = 0;
    temp_v0_2->unk10 = arg2;
    temp_v0_2->unk12 = arg3;
    temp_v0_2->unk6 = -1;
    temp_v0_2->unk13 = arg4;
    temp_v0_2->unk14 = temp_v0_3;
    temp_v0_2->unk18 = 0;
    if (arg5) {
        current = D_global_asm_807FD72C;
        var_v1 = &D_global_asm_807FD72C;
    } else {
        current = D_global_asm_80754244[sp40];
        var_v1 = &D_global_asm_80754244[sp40];
    }
    while (current != NULL) {
        var_v1 = &current->unk18;
        current = current->unk18;
    }
    *var_v1 = temp_v0_2;
}

typedef struct globalASMStruct36 GlobalASMStruct36;

// TODO: These fields might not all be correct
struct globalASMStruct36 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    GlobalASMStruct36 *next;
};

extern GlobalASMStruct36 *D_global_asm_807FD730;
extern u8 D_global_asm_807FD738;

extern s16 D_global_asm_807FD720;

// TODO: Hmm, stack and s0 s1 is a bit sus
// Not sure about which local variables are shared
void func_global_asm_806F5270(void) {
    Struct80754244 *current2;
    GlobalASMStruct36 *current3;
    
    if (D_global_asm_80754244 != NULL) {
        s32 i;
        for (i = 0; i < D_global_asm_807FD720; i++) {
            void *next;
            current2 = D_global_asm_80754244[i];
            if (current2) {
                do {
                    next = current2->unk18;
                    free(current2);
                    current2 = next;
                } while (next != NULL);
            }
        }
        free(D_global_asm_80754244);
        D_global_asm_80754244 = NULL;
    }
    current2 = D_global_asm_807FD72C;
    if (current2) {
        void *next;
        do {
            next = current2->unk18;
            free(current2);
            current2 = next;
        } while (next != NULL);
    }
    if (D_global_asm_807FD730) {
        void *next;
        current3 = D_global_asm_807FD730;
        if (current3) {
            do {
                next = current3->next;
                free(current3);
                current3 = next;
            } while (next != NULL);
        }
        D_global_asm_807FD730 = NULL;
    }
    func_global_asm_806F95C8();
}

void func_global_asm_806F5378(void) {
    GlobalASMStruct36 *next;
    GlobalASMStruct36 *current;

    D_global_asm_807FD738 = TRUE;
    current = D_global_asm_807FD730;
    while (current) {
        next = current->next;
        func_global_asm_806F54E0(0, current->unk2, current->unk1A);
        func_global_asm_806355DC(current->unk0, 1);
        free(current);
        current = next;
    }
    D_global_asm_807FD730 = NULL;
}

// TODO: These fields might not all be correct
typedef struct GlobalASMStruct37 {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
} GlobalASMStruct37;

GlobalASMStruct36 *func_global_asm_806F53EC(GlobalASMStruct37 *arg0) {
    GlobalASMStruct36 *temp_v0 = malloc(sizeof(GlobalASMStruct36));
    temp_v0->unk10 = 0;
    temp_v0->unk14 = 0.0f;
    temp_v0->unk0 = arg0->unk0;
    temp_v0->unk18 = arg0->unk10;
    temp_v0->unk2 = arg0->unk2;
    temp_v0->unk19 = arg0->unk12;
    temp_v0->unk1A = arg0->unk13;
    return temp_v0;
}

s32 func_global_asm_806F544C(s32 arg0, s32 actorBehaviourIndex, u8 arg2) {
    switch (actorBehaviourIndex) {
        case 0x91: // Peanut
        case 0x15D: // Feather
        case 0x15E: // Grape
        case 0x15F: // Pineapple
        case 0x160: // Coconut
            if (arg2) {
                arg0 = 3;
            }
    }
    return arg0;
}

// Rainbow coin FTT check
void func_global_asm_806F5498(void) {
    if (!isFlagSet(PERMFLAG_CUTSCENE_RAINBOW_COIN_FTCS, FLAG_TYPE_PERMANENT)) {
        playCutscene(NULL, 0x20, 5);
        setFlag(PERMFLAG_CUTSCENE_RAINBOW_COIN_FTCS, TRUE, FLAG_TYPE_PERMANENT);
    }
}

extern s8 D_critter_80029FA0;

void func_global_asm_806F54E0(u8 playerIndex, s32 actorBehaviourIndex, u8 arg2) {
    CharacterProgress *temp_v0_2;
    s32 sp28;
    u8 sp27;
    PlayerProgress *temp_v1;
    s8 *temp_v0;
    s32 i;
    u8 lvl;
    u32 tmp;

    sp27 = 0;
    if (D_global_asm_807FBB64 & 0x10000000) {
        if (actorBehaviourIndex != 0x56) {
            D_critter_80029FA0--;
            return;
        }
    }
    if (current_map == MAP_SNIDES_HQ) {
        return;
    }
    tmp = func_global_asm_806F4E74(actorBehaviourIndex);
    sp28 = func_global_asm_806F544C(D_global_asm_80753EF0[tmp].unk2, actorBehaviourIndex, arg2);
    switch (actorBehaviourIndex) {
        case 0xDD:
        case 0xDE:
        case 0xDF:
        case 0xE0:
        case 0xE1:
            lvl = getLevelIndex(D_global_asm_8076A0AB, 1);
            setFlag(func_global_asm_807319D8(PERMFLAG_ITEM_BLUEPRINT_JAPES_DK, lvl, current_character_index[playerIndex]), 1, 0);
        case 0x74:
        case 0x288:
            changeCollectableCount(sp28, playerIndex, 1);
            sp27 = 1;
            break;
        case 0x91:
        case 0x15D:
        case 0x15E:
        case 0x15F:
        case 0x160:
            if (cc_number_of_players == 1) {
                playSound(0x331, 0x7FFF, 63.0f, 1.0f, 5, 0);
            }
        case 0xA:
        case 0xD:
        case 0x16:
        case 0x1E:
        case 0x1F:
            setFlag(PERMFLAG_PROGRESS_FIRST_AMMO_OR_CB_OR_BUNCH_COLLECTED, TRUE, FLAG_TYPE_PERMANENT);
            changeCollectableCount(sp28, playerIndex, 1);
            break;
        case 0x1C:
        case 0x1D:
        case 0x23:
        case 0x24:
        case 0x27:
            setFlag(PERMFLAG_PROGRESS_FIRST_COIN_COLLECTED, TRUE, FLAG_TYPE_PERMANENT);
        case 0x98:
        case 0xEC:
        case 0x1D2:
            changeCollectableCount(sp28, playerIndex, 1);
            break;
        case 0x56:
            setFlag(PERMFLAG_PROGRESS_FIRST_ORANGE_COLLECTED, TRUE, FLAG_TYPE_PERMANENT);
            changeCollectableCount(sp28, playerIndex, 1);
            break;
        case 0xB7:
            for (i = 0; i < 5; i++) {
                D_global_asm_807FC950[playerIndex].character_progress[i].coins += 5;
            }
            func_global_asm_806F5498();
            break;
        case 0x8E:
            changeCollectableCount(sp28, playerIndex, 0x96);
            break;
        case 0x57:
            func_global_asm_806C9974(playerIndex, 1);
            break;
        case 0x13C:
            sp27 = 1;
            break;
        case 0x18D:
            sp27 = 1;
            break;
    }
    if (sp27 != 0) {
        func_global_asm_8060DEC8(); // saveTheGame()
    }
}

void func_global_asm_806F58A0(u8 arg0, s16 arg1, Actor *arg2) {
    s32 var_s0;
    s32 i;
    f32 x, y, z;
    f32 xRot, yRot, zRot;
    f32 scale;
    f32 sp60;
    s16 var_s2;

    if (cc_number_of_players == 1) {
        func_global_asm_806357F8(arg1, &x, &y, &z, &xRot, &yRot, &zRot, &scale, &sp60, 1);
    }
    
    switch (arg2->unk58) {
        case ACTOR_DIDDY:
            var_s2 = 0xA;
            break;
        case ACTOR_TINY:
            var_s2 = 0x16;
            break;
        case ACTOR_LANKY:
        case ACTOR_ENGUARDE:
            var_s2 = 0x1E;
            break;
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
            var_s2 = 0x1F;
            break;
        case ACTOR_DK:
        case ACTOR_RAMBI:
            var_s2 = 0xD;
            break;
        default:
            var_s2 = 0xD;
            break;
    }
    var_s0 = 0;
    for (i = 0; i != 5; i++) {
        if (cc_number_of_players == 1) {
            func_global_asm_806F50C8(func_global_asm_80632630(var_s2, x, y, z, 0.0f, 0), var_s2, var_s0, 1, 0, 1);
        } else {
            func_global_asm_806F54E0(arg0, var_s2, 0);
        }
        var_s0 += 3;
    }
}

void func_global_asm_806F5A48(u8 arg0, s16 arg1, Actor *arg2, u16 arg3) {
    s32 i;
    f32 x, y, z;
    f32 xRot, yRot, zRot;
    f32 scale;
    f32 sp74;
    s32 var_s0;
    s16 var_s2;

    if (cc_number_of_players == 1) {
        func_global_asm_806357F8(arg1, &x, &y, &z, &xRot, &yRot, &zRot, &scale, &sp74, 1);
    }
    switch (arg2->unk58) {
        case ACTOR_DIDDY:
            var_s2 = 0x91;
            break;
        case ACTOR_TINY:
            var_s2 = 0x15D;
            break;
        case ACTOR_LANKY:
            var_s2 = 0x15E;
            break;
        case ACTOR_CHUNKY:
        case ACTOR_KRUSHA:
            var_s2 = 0x15F;
            break;
        case ACTOR_DK:
            var_s2 = 0x160;
            break;
        default:
            var_s2 = 0x91;
            break;
    }
    var_s0 = 0;
    for (i = 0; i != 5; i++) {
        if (cc_number_of_players == 1) {
            func_global_asm_806F50C8(func_global_asm_80632630(var_s2, x, y, z, 0.0f, 0), var_s2, var_s0, 1, (u8)(arg3 == 0x11 ? 1 : 0), 1);
        } else {
            func_global_asm_806F54E0(arg0, var_s2, (u8)(arg3 == 0x11 ? 1 : 0));
        }
        var_s0 += 3;
    }
}

extern s32 D_global_asm_80754248[];
extern s32 D_global_asm_80754264[];

s32 func_global_asm_806F5C30(s32 arg0) {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (arg0 == D_global_asm_80754248[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_global_asm_806F5CE4(s32 arg0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (arg0 == D_global_asm_80754264[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_global_asm_806F5D80(s32 *arg0, s32 *arg1) {
    *arg0 = D_global_asm_80754248[RandClamp(7U)];
    *arg1 = (RandClamp(32767) % 391) + 0xD2;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
} Struct80754240;

extern Struct80754240 *D_global_asm_80754240;

void func_global_asm_806F5DF8(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    s32 found;
    s32 i;

    found = FALSE;
    for (i = 0; i < 60 && !found; i++) {
        if (D_global_asm_80754240[i].unk10 == 0) {
            D_global_asm_80754240[i].unk0 = arg1;
            D_global_asm_80754240[i].unk4 = arg0;
            D_global_asm_80754240[i].unk8 = arg2;
            D_global_asm_80754240[i].unkA = arg3;
            D_global_asm_80754240[i].unkC = arg4;
            D_global_asm_80754240[i].unk10 = arg5;
            found = TRUE;
        }
    }
}

s32 func_global_asm_806F5EB4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 found;

    found = FALSE;
    for (i = 0; i < 60 && !found; i++) {
        if (D_global_asm_80754240[i].unk10 != 0) {
            if (arg0 == D_global_asm_80754240[i].unk4) {
                if (arg1 == D_global_asm_80754240[i].unk0) {
                    found = TRUE;
                }
            }
        }
    }
    return found;
}

void func_global_asm_806F5F2C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    if (func_global_asm_80714608(0) && func_global_asm_806F5C30(arg0)) {
        func_global_asm_806F5D80(&arg0, &arg1);
    }
    func_global_asm_806F5DF8(arg0, 1, arg2, arg3, arg4, arg1);
}

void func_global_asm_806F5FA0(s16 arg0, s16 arg1, s16 arg2) {
    func_global_asm_806F5F2C(0x76, 0, arg0, arg1, arg2);
}

void func_global_asm_806F5FE8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    if (func_global_asm_806F5CE4(arg0)) {
        func_global_asm_806F5DF8(arg0, 0, arg1, arg2, arg3, arg4);
    }
}

void func_global_asm_806F603C(void) {
    s32 i;

    if (gameIsInAdventureMode() && !(global_properties_bitfield & 2)) {
        for (i = 0; i < 60; i++) {
            if (D_global_asm_80754240[i].unk10 != 0) {
                D_global_asm_80754240[i].unk10--;
                if (D_global_asm_80754240[i].unk10 == 5) {
                    func_global_asm_80686E40(D_global_asm_80754240[i].unk8, D_global_asm_80754240[i].unkA, D_global_asm_80754240[i].unkC, 7);
                }
                if (D_global_asm_80754240[i].unk10 == 0) {
                    if (D_global_asm_80754240[i].unk0 != 0) {
                        func_global_asm_806A5DF0(D_global_asm_80754240[i].unk4, D_global_asm_80754240[i].unk8, D_global_asm_80754240[i].unkA, D_global_asm_80754240[i].unkC, 0, 0x19, -1, 0);
                    } else {
                        func_global_asm_806F50C8(func_global_asm_80632630(D_global_asm_80754240[i].unk4, D_global_asm_80754240[i].unk8, D_global_asm_80754240[i].unkA, D_global_asm_80754240[i].unkC, 0.0f, 0), D_global_asm_80754240[i].unk4, 0, 1, 0, 0);
                    }
                }
            }
        }
    }
}

s32 func_global_asm_80626BC8(s32, s32, s32, s32, s32, s32);
void func_global_asm_806F79E0(s16, u8);

typedef struct Struct807FD734 Struct807FD734;
struct Struct807FD734 {
    u8 pad0[0x1C];
    Struct807FD734 *unk1C;
};

extern Struct807FD734 *D_807FD734;

void func_global_asm_806F6204(Struct80754244 *arg0, u8 arg1, Struct807FD740 *arg2) {
    Actor *temp_s5;
    s16 temp_s1;
    s32 temp_v0;
    Struct807FD734 *temp_v0_3;
    Struct807FD734 *var_v0;
    u8 lvl;

    temp_s5 = character_change_array[arg1].player_pointer;
    while (arg0) {
        temp_v0 = func_global_asm_80626BC8(arg0->unk8,
                D_global_asm_80753EF0[arg0->unk14].unk10 + arg0->unkA,
                arg0->unkC,
                arg2->unk0,
                arg2->unk4,
                arg2->unk8);
        if (arg0->unkE) goto next;
        if (temp_v0 < (D_global_asm_80753EF0[arg0->unk14].unk12 + arg2->unkC)) {
            if ((arg0->unk4) && (temp_s5->unk58 != arg0->unk4)) goto next;
            if (!func_global_asm_8063C2A8(arg0->unk0)) goto next;
            if (!func_global_asm_806F6644(arg0->unk0, arg1, arg0->unk2)) goto next;
            arg0->unkE = 1;
            func_global_asm_806362C4(arg0->unk0, 1U);
            if (arg0->unk6 != -1) {
                lvl = getLevelIndex(current_map, 1U);
                func_global_asm_8060E430(arg0->unk6, 1U, lvl);
            }
            if (cc_number_of_players == 1) {
                if (!D_807FD734) {
                    var_v0 = D_global_asm_807FD730;
                    D_807FD734 = var_v0;
                    while (var_v0) {
                        D_807FD734 = var_v0;
                        var_v0 = var_v0->unk1C;
                    }
                }
                temp_v0_3 = func_global_asm_806F53EC(arg0);
                temp_v0_3->unk1C = 0;
                if (D_global_asm_807FD730 != NULL) {
                    D_807FD734->unk1C = temp_v0_3;
                    D_807FD734 = temp_v0_3;
                } else {
                    D_global_asm_807FD730 = temp_v0_3;
                    D_807FD734 = temp_v0_3;
                }
            }
            switch (arg0->unk2) {
                case 0x2B:
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                    func_global_asm_806F58A0(arg1, arg0->unk0, temp_s5);
                    break;
                case 0x11:
                case 0x8F:
                    func_global_asm_806F5A48(arg1, arg0->unk0, temp_s5, arg0->unk2);
                    break;
                default:
                    if (cc_number_of_players >= 2) {
                        func_global_asm_806F54E0(arg1, arg0->unk2, arg0->unk13);
                    }
                    break;
            }
            if (cc_number_of_players >= 2) {
                func_global_asm_806F79E0(arg0->unk2, arg1);
                func_global_asm_806355DC(arg0->unk0, 1U);
            }
            if (D_global_asm_807FBB64 & 0x10000) {
                if (arg0->unk2 != 0x1D2) {
                    func_global_asm_806F5FE8(arg0->unk2, arg0->unk8, arg0->unkA, arg0->unkC, 0x258);
                }
            }
        }
        next:
        arg0 = arg0->unk18;
    } 
}



extern s16 D_global_asm_807FD726;
extern s16 D_global_asm_807FD728;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct806F6554_arg1;

void func_global_asm_806F6554(u8 arg0, Struct806F6554_arg1 *arg1) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    s32 temp_v0;

    if (D_global_asm_807FC950[arg0].health > 0) {
        if (arg1->unk0 <= (D_global_asm_807FD726 + arg1->unkC)) {
            if (arg1->unk8 <= D_global_asm_807FD728 + arg1->unkC) {
                temp_v0 = func_global_asm_806F4EBC(arg1->unk0, arg1->unk8);
                if (temp_v0 >= 0) {
                    func_global_asm_806F6204(D_global_asm_80754244[temp_v0], arg0, arg1);
                }
            }
        }
        func_global_asm_806F6204(D_global_asm_807FD72C, arg0, arg1);
    }
}

s32 func_global_asm_806F6644(s16 arg0, u8 arg1, u16 arg2) {
    PlayerAdditionalActorData *PaaD;
    Prop *temp;
    u8 temp_a0;

    switch (arg2) {
        case 0x11:
            if ((D_global_asm_807FC950[cc_player_index].character_progress[current_character_index[cc_player_index]].weapon & 3) != 3) {
                return FALSE;
            }
        default:
            break;
        case 0x8F:
            if (!((D_global_asm_807FC950[cc_player_index].character_progress[current_character_index[cc_player_index]].weapon & 1))) {
                return FALSE;
            }
            break;
        case 0x98:
            PaaD = character_change_array[cc_player_index].player_pointer->PaaD;
            if (!(PaaD->unk1F4 & 1)) {
                return FALSE;
            }
            break;
        case 0x8E:
            PaaD = character_change_array[cc_player_index].player_pointer->PaaD;
            if (!(PaaD->unk1F4 & 2)) {
                return FALSE;
            }
            break;
        case 0x90:
            temp = &D_global_asm_807F6000[func_global_asm_80659470(arg0)];
            if (temp->unk7C->unk64 != 0xFF) {
                return FALSE;
            }
            break;
    }
    temp_a0 = D_global_asm_807F6000[func_global_asm_80659470(arg0)].unk8C;
    if (temp_a0 & 8 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_DK) {
        return FALSE;
    } else if (temp_a0 & 2 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_DIDDY) {
        return FALSE;
    } else if (temp_a0 & 4 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_TINY) {
        return FALSE;
    } else if (temp_a0 & 0x10 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_LANKY) {
        return FALSE;
    } else if (temp_a0 & 1 && character_change_array[cc_player_index].player_pointer->unk58 != ACTOR_CHUNKY) {
        return FALSE;
    }
    return TRUE;
}

// matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_global_asm_806F69A8.s")

// TODO: Odd syntax, cleanup possible?
u8 func_global_asm_806F6E58(s16 kongIndex) {
    u8 phi_v1;

    phi_v1 = 0;
    if (kongIndex < 5) {
        phi_v1 = D_global_asm_807FC950->character_progress[kongIndex].moves >= D_global_asm_80754238[kongIndex];
    }
    // Camera/Shockwave unlocked
    phi_v1 |= isFlagSet(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, FLAG_TYPE_PERMANENT);
    return phi_v1;
}

// TODO: Odd syntax, cleanup possible?
s32 func_global_asm_806F6EDC(void) {
    s32 i;
    u8 temp_v1;

    i = 0;
    do {
        temp_v1 = func_global_asm_806F6E58(i);
        i++;
    } while (i < 5 && !temp_v1);

    return temp_v1;
}

void func_global_asm_806F6F28(void) {
    s16 pad; // TODO: Why is this needed? Fake match?
    u8 sp45;
    s8 cameraShockaveUnlocked;
    u8 playerIndex;
    PlayerAdditionalActorData *PaaD;

    cameraShockaveUnlocked = FALSE;
    sp45 = FALSE;
    if (D_global_asm_807FBB64 & 0x10000) {
        func_global_asm_806F603C();
    }
    // Camera/Shockwave unlocked
    if (isFlagSet(PERMFLAG_ITEM_MOVE_SHOCKWAVE_CAMERA, FLAG_TYPE_PERMANENT)) {
        cameraShockaveUnlocked = TRUE;
    }
    if (func_global_asm_806F6E58(current_character_index[0])) {
        sp45 = TRUE;
    }
    for (playerIndex = 0; playerIndex < cc_number_of_players; playerIndex++) {
        PaaD = character_change_array[playerIndex].player_pointer->additional_actor_data;
        if (cameraShockaveUnlocked) {
            PaaD->unk1F4 |= 1;
        } else {
            PaaD->unk1F4 &= ~1;
        }
        if (sp45) {
            PaaD->unk1F4 |= 2;
        } else {
            PaaD->unk1F4 &= ~2;
        }
        if ((character_change_array[playerIndex].player_pointer->control_state != 0x36) && !D_global_asm_807FD738) {
            func_global_asm_806F69A8(playerIndex);
        }
    }
}

s32 func_global_asm_806F70A8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_global_asm_807FD798; i++) {
        if (arg0 == D_global_asm_807FD790[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_global_asm_8071C48C(otherSpriteControl *, s8 *);
extern SpriteData D_global_asm_8071FC58;

void func_global_asm_806F70FC(f32 x, f32 y, f32 z, f32 scale, f32 arg4, s32 count) {
    f64 temp_f20;
    s32 i;
    s32 j;
    f32 xOffset;
    f32 yOffset;
    f32 zOffset;

    func_global_asm_80714950(0x1006E);
    func_global_asm_8071498C(func_global_asm_8071C48C);
    func_global_asm_807149B8(1);
    drawSpriteAtPosition(&D_global_asm_8071FC58, scale, x, y, z);
    temp_f20 = 1000.0 / ((f64)arg4 + arg4);
    for (i = 0; i < count; i++) {
        xOffset = ((((func_global_asm_806119A0() / 10000U) % 1000)) / arg4) - temp_f20;
        yOffset = ((((func_global_asm_806119A0() / 10000U) % 1000)) / arg4) - temp_f20;
        zOffset = ((((func_global_asm_806119A0() / 10000U) % 1000)) / arg4) - temp_f20;
        func_global_asm_8071498C(func_global_asm_8071C620);
        func_global_asm_8071496C(i + 1);
        func_global_asm_807149B8(1);
        drawSpriteAtPosition(
            &D_global_asm_8071FC58,
            scale,
            x + xOffset,
            y + yOffset,
            z + zOffset
        );
    }
}

f32 func_global_asm_806F7378(s32 arg0) {
    if (arg0 == 0x8C) {
        return -13.0f;
    } else {
        return 0.0f;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_F9450/func_global_asm_806F73A0.s")

typedef struct Struct806FD73A0_0 Struct806FD73A0_0;

struct Struct806FD73A0_0 {
    u8 pad0[0x10];
    Struct806FD73A0_0 *unk10;
};

typedef struct Struct806FD73A0_1 {
    u8 unk0;
    u8 unk1;
} Struct806FD73A0_1;

/*
void func_global_asm_806F73A0(s32 arg0) {
    s32 j;
    GlobalASMStruct53 *sp58;
    Struct806F73A0 *var_s3;
    Actor *player;
    Actor *temp_s2;
    enum actors_e temp_a0;
    enum actors_e temp_v0_2;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_v0;
    s16 temp_v0_3;
    u8 temp_s6;
    s32 temp_t3;
    s32 var_s5;
    s32 var_v1;
    Struct807FD740 *temp_s1;
    Struct806FD73A0_1 *temp_s4;
    PlayerAdditionalActorData *PaaD;
    Struct806FD73A0_0 *var_s0;
    s32 i;

    temp_s6 = arg0;
    player = character_change_array[temp_s6].player_pointer;
    PaaD = player->additional_actor_data;
    if (D_global_asm_807FC950[temp_s6].health <= 0) {
        return;
    }
    for (i = 0; i < 42; i++) {
        var_s3 = &D_global_asm_80753EF0[i];
        if (var_s3->unkE != 0) {
            for (j = 0; j < D_global_asm_807FBB34; j++) {
                sp58 = &D_global_asm_807FB930[j];
                temp_s2 = sp58->unk0;
                if ((global_properties_bitfield & 0x10000) && (temp_s2->unk58 == var_s3->unkE) && ((temp_v0 = var_s3->unkC, (temp_v0 == 0)) || (player->unk58 == temp_v0))) {
                    temp_s1 = &D_global_asm_807FD740[temp_s6];
                    var_s0 = D_global_asm_807FD780[temp_s6];
                    var_v1 = 0;
                    if ((f32) func_global_asm_80626BC8((s32) temp_s2->x_position, (s32) ((f32) var_s3->unk10 + temp_s2->y_position), (s32) temp_s2->z_position, (s32) temp_s1->unk0, (s32) temp_s1->unk4, (s32) temp_s1->unk8) < (((f32) var_s3->unk12 + temp_s1->unkC) - 1.0f)) {
                        var_v1 = 1;
                    }
                    if ((var_v1 == 0) && (var_s0 != NULL)) {
loop_13:
                        var_v1 = 0;
                        if ((f32) func_global_asm_80626BC8((s32) temp_s2->x_position, (s32) ((f32) var_s3->unk10 + temp_s2->y_position), (s32) temp_s2->z_position, (s32) var_s0->unk0, (s32) var_s0->unk4, (s32) var_s0->unk8) < (((f32) var_s3->unk12 + var_s0->unkC) - 1.0f)) {
                            var_v1 = 1;
                        }
                        var_s0 = var_s0->unk10;
                        if ((var_v1 == 0) && (var_s0 != NULL)) {
                            goto loop_13;
                        }
                    }
                    if ((temp_s2->control_state == 0x64) || (var_v1 != 0)) {
                        if ((D_global_asm_807FBB64 & 0x10000) && (func_global_asm_806F5C30(temp_s2->unk58) != 0)) {
                            func_global_asm_806F5F2C(temp_s2->unk58, 0x258, (s16) (s32) temp_s2->x_position, (s16) (s32) temp_s2->y_position, (s16) (s32) temp_s2->z_position);
                        }
                        temp_s4 = temp_s2->additional_actor_data;
                        if (temp_s4->unk1 != 0) {
                            if ((s32) cc_number_of_players >= 2) {
                                temp_v0_2 = temp_s2->unk58;
                                switch ((u32) temp_v0_2) {
                                case 0x7A:
                                    func_global_asm_806F79E0(0x1D2, temp_s6 & 0xFF);
                                    func_global_asm_806F54E0(temp_s6 & 0xFF, 0x1D2, 0);
                                    break;
                                case 0x79:
                                    func_global_asm_806F79E0(0x8E, temp_s6 & 0xFF);
                                    PaaD->unk264 = 0;
                                    break;
                                case 0x2F:
                                    func_global_asm_806F79E0(0x57, temp_s6 & 0xFF);
                                    func_global_asm_806F54E0(temp_s6 & 0xFF, 0x57, 0);
                                    break;
                                case 0x77:
                                    func_global_asm_806F79E0(0x1D0, temp_s6 & 0xFF);
                                    PaaD->unk264 = 1;
                                    break;
                                case 0x78:
                                    func_global_asm_806F79E0(0x1CF, temp_s6 & 0xFF);
                                    PaaD->unk264 = 2;
                                    break;
                                case 0x33:
                                    func_global_asm_806F79E0(0x8F, temp_s6 & 0xFF);
                                    if ((func_global_asm_80714608(0) != 0) && (player->additional_actor_data->unk8C == 0)) {
                                        func_global_asm_806F0D68(player);
                                        func_global_asm_806CFF9C(player);
                                    }
                                    break;
                                case 0x34:
                                    func_global_asm_806F79E0(0x56, temp_s6 & 0xFF);
                                    PaaD->unk264 = 3;
                                    break;
                                case 0x76:
                                    func_global_asm_806F79E0(0x1D1, temp_s6 & 0xFF);
                                    PaaD->unk264 = 4;
                                    break;
                                }
                            } else {
                                temp_a0 = temp_s2->unk58;
                                var_s5 = 1;
                                if ((temp_a0 != ACTOR_WATERMELON_SLICE) && (temp_a0 != ACTOR_BOSS_KEY) && (temp_a0 != ACTOR_CROWN)) {
                                    var_s5 = 0;
                                }
                                temp_v0_3 = func_global_asm_80632630((s32) var_s3->unk0, temp_s2->x_position, func_global_asm_806F7378(temp_a0) + temp_s2->y_position, temp_s2->z_position, 0.0f, 0U);
                                temp_s0 = func_global_asm_8063D990(temp_v0_3);
                                func_global_asm_80731410(*(&current_map + 2), temp_s0, temp_s4->unkA, func_global_asm_8073198C(temp_s4->unkA) & 0xFF);
                                temp_s0_2 = func_global_asm_8063D990(temp_v0_3);
                                func_global_asm_80632E74(*(&current_map + 2), temp_s0_2, &D_global_asm_807F6000[func_global_asm_80659470((s32) temp_v0_3)].unk8C);
                                func_global_asm_806F50C8(temp_v0_3, var_s3->unk0, 0, 1U, 0U, (u8) var_s5);
                                temp_s2->unk11C = NULL;
                            }
                            deleteActor(temp_s2);
                        }
                    }
                }
            }
        }
    }
}
*/

extern u8 D_global_asm_80745838;

void func_global_asm_806F79E0(s16 arg0, u8 arg1) {
    s32 var_v0;

    switch (arg0) {
        case 0x8E:
            playSong(MUSIC_35_CRYSTAL_COCONUT_GET, 1.0 - (D_global_asm_80745838 * 0.3));
            break;
        case 0x57:
            playSong(MUSIC_33_MELON_SLICE_GET, 1.0 - (D_global_asm_80745838 * 0.3));
            break;
        case 0x56:
            playSound(0x147, 0x7FFF, 63.0f, 1.0f, 5, 0);
            break;
        case 0x11:
        case 0x8F:
            playSound(0x157, 0x7FFF, 63.0f, 1.0f, 5, 0);
            break;
        case 0x98:
            playSound(0x263, 0x7FFF, 63.0f, 1.0f, 5, 0);
            break;;
        case 0xDD:
        case 0xDE:
        case 0xDF:
        case 0xE0:
        case 0xE1:
            playSong(MUSIC_69_BLUEPRINT_GET, 1.0f);
            break;
        case 0x90:
            playSong(MUSIC_18_GB_KEY_GET, 1.0f);
            func_global_asm_80687C48();
            if ((player_pointer->y_position - player_pointer->floor) < 100.0f) {
                if (player_pointer->control_state != 0x63) {
                    if (!(player_pointer->unk6A & 4) || !((player_pointer->unkAC - player_pointer->y_position) > 20.0f)) {
                        setAction(0x29, 0, extra_player_info_pointer->unk1A4);
                    }
                }
            }
            break;
        case 0x74:
        case 0x288:
            playSong(MUSIC_18_GB_KEY_GET, 1.0f);
            if ((player_pointer->y_position - player_pointer->floor) < 100.0f) {
                if (player_pointer->control_state != 0x63) {
                    if (!(player_pointer->unk6A & 4) || !((player_pointer->unkAC - player_pointer->y_position) > 20.0f)) {
                        setAction(0x29, 0, extra_player_info_pointer->unk1A4);
                    }
                }
            }
            break;
        case 0xA:
        case 0xD:
        case 0x16:
        case 0x1E:
        case 0x1F:
        case 0x1CF:
        case 0x1D0:
            playSound(0x2A0, 0x7FFF, 63.0f, 1.0f, 5, 0);
            break;
        case 0x1C:
        case 0x1D:
        case 0x23:
        case 0x24:
        case 0x27:
            playSong(MUSIC_23_BANANA_COIN_GET, 1.0 - (D_global_asm_80745838 * 0.3));
        case 0x2B:
            break;
        case 0xB7:
            playSong(MUSIC_145_RAINBOW_COIN_GET, 1.0 - (D_global_asm_80745838 * 0.3));
            break;
        case 0xEC:
        case 0x1D2:
            playSong(MUSIC_32_MINECART_COIN_GET, 1.0 - (D_global_asm_80745838 * 0.3));
            break;
        case 0x13C:
            playSong(MUSIC_18_GB_KEY_GET, 1.0f);
            var_v0 = 0x41;
            if (current_map == MAP_HELM) {
                var_v0 = 0x29;
            }
            setAction(var_v0, 0, extra_player_info_pointer->unk1A4);
            break;
        case 0x18D:
            playSong(MUSIC_18_GB_KEY_GET, 1.0f);
            setAction(0x42, 0, extra_player_info_pointer->unk1A4);
            func_global_asm_80687CC8();
            break;
        case 0x1D1:
            playSound(0xAE, 0x7FFF, 63.0f, 1.0f, 5, 0);
            break;
    }
}
