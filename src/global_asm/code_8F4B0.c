#include <ultra64.h>
#include "functions.h"

extern u8 D_global_asm_807501E0;

extern u8 D_global_asm_807FC620;
extern u8 D_global_asm_807FC621;
extern u8 D_global_asm_807FC622;

// spawnPersistantActors
void func_global_asm_8068A7B0(void) {
    spawnActor(ACTOR_UNKNOWN_10, 0);
    spawnActor(ACTOR_UNKNOWN_11, 0);
    spawnActor(ACTOR_LOADING_ZONE_CONTROLLER, 0);
    spawnActor(ACTOR_OBJECT_MODEL_2_CONTROLLER, 0);
    spawnActor(ACTOR_UNKNOWN_14, 0);
    spawnActor(ACTOR_UNKNOWN_15, 0);
}

void func_global_asm_8068A810(void) {
    func_global_asm_8072E868();
}

void func_global_asm_8068A830(void) {
    func_global_asm_80727678();
    func_global_asm_80727958();
}

// Hmm, negative struct offsets
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068A858.s")

s32 func_global_asm_8068ABE0(s16 arg0) {
    s16 cutsceneIndex;
    s32 sp20;
    s32 found;
    s32 i;
    Maps map;
    s32 exit; // 20

    cutsceneIndex = -1;
    i = 0, found = 0;
    while (!found && i < 8) {
        if (current_map == D_global_asm_80744734[i]) {
            found = 1;
        } else {
            i++;
        }
    }
    if (found) {
        if (!isFlagSet(0x1C5 + i, FLAG_TYPE_PERMANENT)) {
            exit = 0;
            switch (arg0) {
                case 0x7:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0xF;
                    break;
                case 0x26:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x10;
                    break;
                case 0x1A:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x11;
                    break;
                case 0x1E:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x12;
                    break;
                case 0x30:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x13;
                    break;
                case 0x48:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x14;
                    break;
                case 0x57:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x15;
                    exit = 0x15;
                    break;
                case 0x11:
                    map = MAP_HELM_LEVEL_INTROS_GAME_OVER;
                    cutsceneIndex = 0x16;
                    break;
            }
            if (cutsceneIndex != -1) {
                setFlag(0x1C5 + i, TRUE, FLAG_TYPE_PERMANENT);
                if (story_skip) {
                    func_global_asm_805FF378(arg0, exit);
                    return 1;
                } else {
                    func_global_asm_80712524(map, cutsceneIndex);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068AD7C.s")

void func_global_asm_8068B80C(void) {
    D_global_asm_807FC620 = 1;
}

void func_global_asm_8068B81C(void) {
    D_global_asm_807FC621 = 0;
    D_global_asm_807FC622 = 0;
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
    f32 unk4;
    s16 unk8;
} AAD_global_asm_8068B830;

void func_global_asm_8068B830(s16 arg0, s16 arg1, s16 arg2) {
    Actor *sp1C;
    AAD_global_asm_8068B830 *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = (f32)arg1 / 100.0; // TODO: Get rid of this typecast?
    temp_v0->unk8 = arg2;
}

// TODO: Add to aaD union
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    s16 unk1C;
    s16 unk1E;
} AAD_global_asm_8068B8A4;

void func_global_asm_8068B8A4(f32 arg0) {
    Actor *sp1C;
    AAD_global_asm_8068B8A4 *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unkC = arg0;
    temp_v0->unk10 = arg0;
    temp_v0->unk14 = arg0;
    if (temp_v0->unk18 == 0) {
        temp_v0->unk1C = 1;
        temp_v0->unk1E = temp_v0->unk1C;
    }
}

// TODO: Add to aaD union
typedef struct {
    u8 unk0;
} AAD_global_asm_8068B8FC;

void func_global_asm_8068B8FC(void) {
    Actor *sp1C;
    AAD_global_asm_8068B8FC *temp_v0;

    func_global_asm_8072E7DC(0xC, &sp1C);
    temp_v0 = sp1C->additional_actor_data;
    temp_v0->unk0 = 0xFF;
}

extern u8 D_global_asm_807FBDC4;

void func_global_asm_8068B930(void) {
    Struct807FBB70_unk278 *temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        if (D_global_asm_807FBB70.unk258[i] == 1) {
            func_global_asm_8063DA40(temp_v0->unk0, temp_v0->unk2);
        }
    }
    func_global_asm_8062BAE4();
}

void func_global_asm_8068B9B4(void) {
    Struct807FBB70_unk278 *temp_v0;
    s32 i;

    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        temp_v0 = D_global_asm_807FBB70.unk278[i];
        if (D_global_asm_807FBB70.unk258[i] == 1) {
            func_global_asm_80689A80(temp_v0->unk2, temp_v0);
        }
    }
}

void func_global_asm_8072167C(s16, s16, s16, s16);

// TODO: Probably overlap with an existing aaD
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
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC; // Used
} AAD_global_asm_8068BA2C;

void func_global_asm_8068BA2C(void) {
    s16 i;
    AAD_global_asm_8068BA2C *sp58;
    Struct807FBB70_unk278 *temp_v1;
    u8 var_s3;
    s32 var_v0;
    PlayerAdditionalActorData *temp_s1;

    temp_s1 = current_player->PaaD;
    var_s3 = 0;
    sp58 = temp_s1->unk104->additional_actor_data;
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        temp_v1 = D_global_asm_807FBB70.unk278[i];
        switch (D_global_asm_807FBB70.unk258[i]) {
            case 1:
                if (temp_v1->unk2 != 0) {
                    var_v0 = 4;
                } else {
                    var_v0 = 0;
                }
                playCutscene(NULL, temp_v1->unk0, (var_v0 | 1) & 0xFF);
                break;
            case 2:
                func_global_asm_8072167C(temp_v1->unk0, temp_v1->unk2, temp_v1->unk4, temp_v1->unk6);
                break;
            case 3:
                var_s3 = 1;
                if (!(temp_s1->unk1F0 & 0x04000000)) {
                    temp_s1->unk1F0 |= 0x04000000;
                }
                break;
        }
    }
    if (var_s3 == 0) {
        temp_s1->unk1F0 &= 0xFBFFFFFF;
    }
    if (sp58->unkAC & 1) {
        createLight(character_change_array->look_at_eye_x, character_change_array->look_at_eye_y, character_change_array->look_at_eye_z, character_change_array->look_at_at_x, character_change_array->look_at_at_y, character_change_array->look_at_at_z, 0.0f, 1, 0xFF, 0xFF, 0xFF);
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068BBF8.s")

typedef struct {
    void *texturePointer; // Texture Pointer (from table 0xE)
    u16 textureIndex; // Texture Index
    u8 unk6;
    u8 unk7;
} Struct807FC690;

extern Struct807FC690 D_global_asm_807FC690[];

void func_global_asm_8068C080(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        D_global_asm_807FC690[i].unk6 = 0;
    }
}

void func_global_asm_8068C0B4(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FC690[i].unk6 != 0) {
            D_global_asm_807FC690[i].unk6--;
            if (D_global_asm_807FC690[i].unk6 == 0) {
                func_global_asm_8066B434(D_global_asm_807FC690[i].texturePointer, 0x6A, 0x46);
            }
        }
    }
}

// Returns a texture pointer for a given texture index
void *func_global_asm_8068C12C(u16 textureIndex) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        if ((textureIndex == D_global_asm_807FC690[i].textureIndex) && (D_global_asm_807FC690[i].unk6 != 0)) {
            D_global_asm_807FC690[i].unk6 = 2;
            return D_global_asm_807FC690[i].texturePointer;
        }
    }
    
    for (i = 0; i < 0x20; i++) {
        if (D_global_asm_807FC690[i].unk6 == 0) {
            D_global_asm_807FC690[i].texturePointer = getPointerTableFile(0xE, textureIndex, 0, 0);
            D_global_asm_807FC690[i].unk6 = 2;
            D_global_asm_807FC690[i].textureIndex = textureIndex;
            return D_global_asm_807FC690[i].texturePointer;
        }
    }

    D_global_asm_807FC690[0].unk6 = 2;
    return D_global_asm_807FC690[0].texturePointer;
}

typedef struct {
    Gfx *(*unk0)(Gfx*, Actor*); // Used
    Actor *unk4; // Used
    u8 unk8; // Used
    s8 unk9;
    s8 unkA;
    s8 unkB;
} TempCBig;

extern TempCBig D_global_asm_807FC630[];

// Displaylist stuff, uses TempCBig, close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8F4B0/func_global_asm_8068C20C.s")

/*
Gfx *func_global_asm_8068C20C(Gfx *dl, u8 arg1) {
    TempCBig *temp_v1;
    u8 i;

    i = D_global_asm_807501E0;

    while (i != 0) {
        temp_v1 = &D_global_asm_807FC630[--i];
        if (arg1 == temp_v1->unk8) {
            gDPPipeSync(dl++);\
            dl = temp_v1->unk0(dl, temp_v1->unk4);
        }
    }

    if (arg1 == 7) {
        D_global_asm_807501E0 = 0;
    }
    return dl;
}
*/

void func_global_asm_8068C2EC(void) {
    D_global_asm_807501E0 = 0;
}

void func_global_asm_8068C2F8(Actor *arg0) {
    u8 i;
    for (i = 0; i < D_global_asm_807501E0; i++) {
        if (arg0 == D_global_asm_807FC630[i].unk4) {
            D_global_asm_807FC630[i].unk8 = 8;
        }
    }
}

// TODO: Arg0 is a function pointer
void addActorToTextOverlayRenderArray(void *arg0, Actor *arg1, u8 arg2) {
    if (D_global_asm_807501E0 < 8) {
        D_global_asm_807FC630[D_global_asm_807501E0].unk0 = arg0;
        D_global_asm_807FC630[D_global_asm_807501E0].unk4 = arg1;
        D_global_asm_807FC630[D_global_asm_807501E0].unk8 = arg2;
        D_global_asm_807501E0++;
    }
}
