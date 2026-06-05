#include "common.h"


extern u8 D_global_asm_80747D78;

extern f32 D_global_asm_80747E00;
extern f32 D_global_asm_80747E04;

extern u16 D_global_asm_807F6028;
extern u16 D_global_asm_807F60A8;

extern u8 D_global_asm_807F6148;
extern s16 D_global_asm_807F6140[];
extern s16 D_global_asm_807F6150[];
extern f32 D_global_asm_807F6170;
extern f32 D_global_asm_807F6174;
extern f32 D_global_asm_807F6178;
extern void* D_global_asm_807F617C; // Texture
extern f32 D_global_asm_807F6180;
extern f32 D_global_asm_807F6184;
extern void* D_global_asm_807F6188; // Texture
extern void* D_global_asm_807F618C; // Texture
extern void* D_global_asm_807F6190; // Texture
extern u8 D_global_asm_807F6194;
extern f32 D_global_asm_807F6198;
extern void* D_global_asm_807F619C; // Texture
extern f32 D_global_asm_807F61A0;
extern u8 D_global_asm_807F6938;

void func_global_asm_80631B80(void) {
    D_global_asm_807F6148 = 0;
}

void func_global_asm_80631B8C(s16 arg0) {
    if (D_global_asm_807F6148 != 4) {
        D_global_asm_807F6140[D_global_asm_807F6148] = arg0;
        D_global_asm_807F6148++;
    }
}

s32 func_global_asm_80631BCC(s16 arg0) {
    s32 i;

    for (i = 0; i <  D_global_asm_807F6148; i++) {
        if (arg0 == D_global_asm_807F6140[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

s16 func_global_asm_80631C20(u8 arg0) {
    return D_global_asm_807F6150[arg0];
}

typedef struct PropSetup {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[0x18 - 0x10];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s16 unk2A;
    u8 pad2C[2];
    u8 unk2E;
    u8 unk2F;
} PropSetup;

typedef struct PropData {
    s32 count;
    PropSetup setup[];
} PropData;

typedef struct MysterySetup {
    s32 unk0;
    s32 unk4; // unsure of type, using for reference
    u8 pad8[0x24 - 0x8];
} MysterySetup;

typedef struct MysteryData {
    s32 count;
    MysterySetup setup[];
} MysteryData;

typedef struct ActorSetup {
    u8 pad0[0x38];
} ActorSetup;

typedef struct ActorData {
    s32 count;
    ActorSetup setup[];
} ActorData;

typedef struct SetupFile {
    PropData props;
    MysteryData mys;
    ActorData actors;
} SetupFile;

void func_global_asm_80631F58(SetupFile *arg0, PropData **arg1, ActorData **arg2);

void func_global_asm_80631C3C(void) {
    void *setupFile;
    PropSetup *var_s0;
    s32 propCount;
    s32 *sp58;
    s32 sp54;
    s32 i;
    u8 levelIndex;
    s32 j;

    if (D_global_asm_80747D78 == 0) {
        D_global_asm_80747D78 = 1;
        for (i = 0; i < 8; i++) {
            D_global_asm_807F6150[i] = 0;
        }
        for (i = 0; i < 0xDD; i++) {
            // Load setup for map
            setupFile = getPointerTableFile(9, i, 1, 1);
            if (setupFile != NULL) {
                levelIndex = getLevelIndex(i, 1);
                func_global_asm_80631F58(setupFile, &sp58, &sp54);
                propCount = *sp58;
                var_s0 = sp58 + 1;
                for (j = 0; j < propCount; j++) {
                    if (func_global_asm_80631EB8(var_s0->unk28)) {
                        D_global_asm_807F6150[levelIndex]++;
                    }
                    var_s0++;
                }
                func_global_asm_8066B424();
                func_global_asm_8066B434(setupFile, 0x10C, 7);
            }
        }
    }
}

s32 func_global_asm_80631D8C(u8 map) {
    s32 temp;
    s32 j;
    s32 propCount;
    s32 i;
    s32 *sp5C;
    s32 sp58;
    u8 levelIndex;
    u16 singleCoinOrBunchCount;
    PropSetup *phi_s0;

    levelIndex = getLevelIndex(map, 1);
    singleCoinOrBunchCount = 0;
    for (i = 0; i < map; i++) {
        if (levelIndex == getLevelIndex(i, 1)) {
            // Load setup for map
            void *setupFile = getPointerTableFile(9, i, 1, 1);
            if (setupFile) {
                func_global_asm_80631F58(setupFile, &sp5C, &sp58);
                propCount = *sp5C;
                phi_s0 = sp5C + 1;
                for (j = 0; j < propCount; j++) {
                    if (func_global_asm_80631EB8(phi_s0->unk28)) {
                        singleCoinOrBunchCount++;
                    }
                    phi_s0++;
                }
                func_global_asm_8066B424();
                func_global_asm_8066B434(setupFile, 0x13A, 7);
            }
        }
    }
    return singleCoinOrBunchCount;
}

s32 func_global_asm_80631EB8(u16 arg0) {
    switch (arg0) {
        case 10:
        case 13:
        case 22:
        case 28:
        case 29:
        case 30:
        case 31:
        case 35:
        case 36:
        case 39:
        case 43:
        case 517:
        case 518:
        case 519:
        case 520:
            return TRUE;
    }
    return FALSE;
}

// regalloc, close, doable
// https://decomp.me/scratch/L4Vuz
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80631F58.s")

/*
void func_global_asm_80631F58(SetupFile *arg0, PropData **arg1, ActorData **arg2) {
    MysteryData *temp;
    if (arg0 == NULL) {
        *arg1 = NULL;
        *arg2 = NULL;
        return;
    }
    *arg1 = arg0;
    temp = &arg0->props.setup[arg0->props.count];
    arg0 = &temp->setup[temp->count];
    *arg2 = arg0;
}
*/

extern s16 D_global_asm_807F614A;

// TODO: Rename to allocatePropArray
s16 func_global_asm_80631FAC(Maps map, u8 arg1) {
    switch (map) {
        case MAP_FUNGI:
            D_global_asm_807F614A = 530;
            break;
        case MAP_FACTORY:
            D_global_asm_807F614A = 500;
            break;
        case MAP_AZTEC:
            D_global_asm_807F614A = 500;
            break;
        case MAP_GALLEON:
            D_global_asm_807F614A = 485;
            break;
        case MAP_JAPES:
            D_global_asm_807F614A = 465;
            break;
        default:
            D_global_asm_807F614A = 450;
            break;
    }
    if (arg1) {
        D_global_asm_807F6000 = malloc(D_global_asm_807F614A * sizeof(Prop));
        func_global_asm_80611690(D_global_asm_807F6000);
    }
    return D_global_asm_807F614A;
}

// doable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80632084.s")

s16 func_global_asm_80632860(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u8 argA, u8 argB, Chunk14 **argC);
void func_global_asm_8063DC58(void *);
extern s32 D_global_asm_80747D70;
extern s32 D_global_asm_807F6004;

/*
void func_global_asm_80632084(PropData *arg0, s32 arg1, u8 arg2, u16 arg3, u8 arg4) {
    Chunk14 *sp94;
    s32 sp90;
    PropSetup *var_s1; // 8C?
    s16 temp_s3;
    MysterySetup *var_s0_2;
    s32 j;
    u8 var_s0;
    s32 var_s4;
    s32 var_s5;
    s32 i;
    u16 var_s7;
    void *script;

    sp94 = NULL;
    var_s5 = 0;
    var_s7 = 0;
    D_global_asm_80747D70 = 0;
    if (arg0 == NULL) {
        sp90 = 0;
    } else {
        var_s1 = &arg0->setup;
        sp90 = arg0->count;
    }
    D_global_asm_807F6004 = 0;
    func_global_asm_80659320();
    func_global_asm_8063D930();
    func_global_asm_8065051C();
    if (arg0 == NULL) {
        return;
    }
    for (i = 0; i < sp90; i++) {
        var_s0 = 0;
        var_s4 = FALSE;
        if (arg2 && func_global_asm_80631EB8(var_s1->unk28)) {
            var_s0 = func_global_asm_8060E3B0(arg3 + var_s7, arg4);
            var_s4 = TRUE;
        }
        if (!var_s0) {
            if (!func_global_asm_80631BCC(var_s1->unk28)) {
                if (!func_global_asm_807315D4(current_map, var_s1->unk2A)) {
                    if (func_global_asm_8063253C(var_s1->unk28, arg1)) {
                        D_global_asm_807F6000[var_s5].x_position = var_s1->unk0;
                        D_global_asm_807F6000[var_s5].y_position = var_s1->unk4;
                        D_global_asm_807F6000[var_s5].z_position = var_s1->unk8;
                        D_global_asm_807F6000[var_s5].hitbox_scale = var_s1->unkC;
                        D_global_asm_807F6000[var_s5].x_rotation = var_s1->unk18;
                        D_global_asm_807F6000[var_s5].y_rotation = var_s1->unk1C;
                        D_global_asm_807F6000[var_s5].z_rotation = var_s1->unk20;
                        D_global_asm_807F6000[var_s5].unk1C = var_s1->unk24;
                        D_global_asm_807F6000[var_s5].unk8A = var_s1->unk2A;
                        temp_s3 = func_global_asm_80632860(var_s5, var_s1->unk28, var_s1->unk0,
                            var_s1->unk4, var_s1->unk8, var_s1->unk18, var_s1->unk1C,
                            var_s1->unk20, var_s1->unkC, var_s1->unk24, 
                            var_s1->unk2F, var_s1->unk2E, &sp94);
                        func_global_asm_80632E74(current_map, D_global_asm_807F6000[var_s5].unk8A, &D_global_asm_807F6000[var_s5].unk8C);
                        D_global_asm_807F6240[var_s1->unk2A] = temp_s3;
                        D_global_asm_80747D70++;
                        var_s5++;
                    }
                }
            }
        }
        if (var_s4) {
            var_s7++;
        }
        var_s1++;
    }
    func_global_asm_8062D3E4(sp94);
    func_global_asm_806306D0(sp94);
    func_global_asm_8062D1A8();
    script = getPointerTableFile(TABLE_10_SCRIPTS, current_map, 1U, 0U);
    func_global_asm_8063DC58(script);
    var_s0_2 = &((MysteryData *) var_s1)->setup;
    j--;
    for (j = ((MysteryData *) var_s1)->count; j != 0; j--, var_s0_2++) {
        func_global_asm_8063DFEC(var_s0_2->unk0, &var_s0_2->unk4);
    }
    func_global_asm_80631B80();
}
*/

void func_global_asm_806323C0(Chunk14 *arg0) {
    s16 flagIndex;
    PropModel *temp_s0;

    while (arg0 != NULL) {
        if (arg0->unk24 == 2) {
            temp_s0 = arg0->unk0;
            switch (temp_s0->unk4A) {
                case 0xA:
                case 0x24:
                case 0x208:
                    flagIndex = PERMFLAG_KONG_DIDDY;
                    break;
                case 0x1F:
                case 0x27:
                case 0x206:
                    flagIndex = PERMFLAG_KONG_CHUNKY;
                    break;
                case 0x16:
                case 0x1C:
                case 0x207:
                    flagIndex = PERMFLAG_KONG_TINY;
                    break;
                case 0x1E:
                case 0x23:
                case 0x205:
                    flagIndex = PERMFLAG_KONG_LANKY;
                    break;
                default:
                    flagIndex = -1;
                    break;
            }
            if (flagIndex != -1) {
                if (!isFlagSet(flagIndex, FLAG_TYPE_PERMANENT)) {
                    temp_s0->unk4E |= 0x10;
                } else {
                    temp_s0->unk4E &= ~0x10;
                }
            }
        }
        arg0 = arg0->next;
    }
}

s32 func_global_asm_8063253C(s32 arg0, s32 arg1) {
    return 1;
}

s32 func_global_asm_8063254C(s32 objectType, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s16 *arg5, s16 *arg6) {
    s32 found;
    s32 i;
    found = FALSE;
    i = *arg1;

    while (!found && i < D_global_asm_80747D70) {
        if (objectType == D_global_asm_807F6000[i].object_type) {
            found = TRUE;
            *arg5 = D_global_asm_807F6000[i].unk88;
            *arg6 = D_global_asm_807F6000[i].unk8A;
            *arg2 = D_global_asm_807F6000[i].x_position;
            *arg3 = D_global_asm_807F6000[i].y_position;
            *arg4 = D_global_asm_807F6000[i].z_position;
        }
        i++;
    }
    *arg1 = i;
    return found;
}

extern u8 D_global_asm_807F6008;
extern s16 D_global_asm_807F614A;

s16 func_global_asm_80632630(s32 arg0, f32 x, f32 y, f32 z, f32 arg4, u8 arg5) {
    void *sp5C;
    s16 temp_v0;
    f32 hitboxScale;

    sp5C = NULL;
    if (D_global_asm_80747D70 >= D_global_asm_807F614A) {
        raiseException(8, 0, 0, 0);
    }
    if (arg5 == 0 && D_global_asm_807F6008 != 0) {
        return -1;
    }
    hitboxScale = func_global_asm_80636A44(arg0);
    D_global_asm_807F6000[D_global_asm_80747D70].x_position = x;
    D_global_asm_807F6000[D_global_asm_80747D70].y_position = y;
    D_global_asm_807F6000[D_global_asm_80747D70].z_position = z;
    D_global_asm_807F6000[D_global_asm_80747D70].hitbox_scale = hitboxScale;
    D_global_asm_807F6000[D_global_asm_80747D70].x_rotation = 0.0f;
    D_global_asm_807F6000[D_global_asm_80747D70].y_rotation = 0.0f;
    D_global_asm_807F6000[D_global_asm_80747D70].z_rotation = 0.0f;
    D_global_asm_807F6000[D_global_asm_80747D70].unk1C = (y - arg4);
    D_global_asm_807F6000[D_global_asm_80747D70].unk8C = 0;
    temp_v0 = func_global_asm_80632860(D_global_asm_80747D70, arg0, x, y, z, 0.0f, 0.0f, 0.0f, hitboxScale, (y - arg4), 1, 0, &sp5C);
    func_global_asm_8062D3E4(sp5C);
    func_global_asm_806306D0(sp5C);
    D_global_asm_807F6000[D_global_asm_80747D70].unk8A = func_global_asm_8063D9D0(temp_v0, arg5);
    D_global_asm_80747D70++;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80632860.s")

typedef struct {
    u16 unk0; // Map
    u16 unk2;
} Struct80747D50;

extern Struct80747D50 D_global_asm_80747D50[];

void func_global_asm_80632E10(s16 arg0, u8 *arg1) {
    s32 i = 0;
    s32 max = 8;
    Maps map;
    Struct80747D50 *temp;

    map = current_map;temp = D_global_asm_80747D50; // Unreal...

    while (i < max) {
        if (temp->unk0 == map && temp->unk2 == arg0) {
            *arg1 |= 1;
            return;
        } else {
            i++;
            temp++;
        }
    }
}

void func_global_asm_80632E74(s16 arg0, s16 arg1, u8 *arg2) {
    switch (func_global_asm_80731654(arg0, arg1)) {
        case 2:
            *arg2 |= 8;
            break;
        case 5:
            *arg2 |= 4;
            break;
        case 6:
            *arg2 |= 1;
            break;
        case 3:
            *arg2 |= 2;
            break;
        case 4:
            *arg2 |= 0x10;
            break;
    }
    return;
}

typedef struct {
    u16 unk0; // Map
    u16 unk2;
    u16 unk4;
} Struct80747D30;

extern Struct80747D30 D_global_asm_80747D30[];

typedef struct {
    u8 unk0[0x1E - 0x0];
    s16 unk1E;
} Struct80632F20;

void func_global_asm_80632F20(s32 arg0, Struct80632F20 *arg1) {
    s32 i;
    s32 max;
    Maps map;
    Struct80747D30 *var_a3;

    max = 5;
    i = 0;map = current_map;var_a3 = &D_global_asm_80747D30; // Cringe...

    while (i < max) {
        if (map == var_a3->unk0 && arg0 == var_a3->unk2) {
            arg1->unk1E = var_a3->unk4;
            return;
        } else {
            i++;
            var_a3++;
        }
    }
}

u8 func_global_asm_80632F74(f32 arg0, f32 arg1, f32 arg2) {
    f32 sp1C;

    sp1C = arg1 + 10.0f;
    if (func_global_asm_80667110(arg0, arg2, &sp1C) != 0) {
        return func_global_asm_80667174();
    }
    return 0xF;
}

void func_global_asm_80632FCC(s16 arg0, u8 arg1) {
    s32 pad[4];
    PropModel *model;
    PropModel54_BC *var_a0_2;
    Prop_unk24 *temp;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    sp28 = D_global_asm_807F6000[arg0].y_position + 20.0f;
    if (func_global_asm_80667110(D_global_asm_807F6000[arg0].x_position, D_global_asm_807F6000[arg0].z_position, &sp28) != 0) {
        func_global_asm_80666AC4(&sp26, &sp24);
        temp = D_global_asm_807F6000[arg0].unk24;
        switch (temp->unk1C) {
            case 1:
                model = D_global_asm_807F6000[arg0].model_pointer;
                var_a0_2 = model->unkBC;
                break;
            case 2:
                model = D_global_asm_807F6000[arg0].model_pointer;
                var_a0_2 = model->unk54;
                break;
        }
        if (var_a0_2 != NULL) {
            var_a0_2->unk20 = sp26;
            var_a0_2->unk22 = sp24;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806330C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806333F8.s")

void func_global_asm_80633570(GlobalASMStruct83 *arg0) {
    GlobalASMStruct83 *next;

    while (arg0 != NULL) {
        next = arg0->next;
        free(arg0);
        arg0 = next;
    }
}

void func_global_asm_806335B0(s32 arg0, u8 arg1, s32 boneIndex, f32 *x, f32 *y, f32 *z) {
    s32 var_v0;
    Prop_unk74 *var_v1;

    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    var_v1 = D_global_asm_807F6000[arg0].unk74;
    var_v0 = boneIndex - 1;
    while (var_v1 != 0 && var_v0 != 0) {
        var_v1 = var_v1->next;
        var_v0 -= 1;
    }
    if (var_v1 != 0) {
        *x = var_v1->unk0;
        *y = var_v1->unk4;
        *z = var_v1->unk8;
    } else {
        *z = 0.0f;
        *y = 0.0f;
        *x = 0.0f;
    }
}

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063367C.s")

// Matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063373C.s")

void func_global_asm_806338B4(Prop_unk74 *current) {
    Prop_unk74 *next;

    if (current != NULL) {
        do {
            next = current->next;
            free(current);
            current = next;
        } while (next != NULL);
    }
}

void func_global_asm_806338F4(s32 arg0) {
    Prop_unk48 *temp_v0;
    u8 i;

    temp_v0 = &D_global_asm_807F6000[arg0].unk48;
    for (i = 0; i < 2; i++) {
        temp_v0->unk25[i] = 0xFF;
    }
    temp_v0->unk24 = 0;
}

void func_global_asm_8063393C(s32 arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 i;
    u8 var_t0;
    u8 var_a1;
    u8 *temp_a2;

    i = 0;
    var_t0 = FALSE;
    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    temp_a2 = &D_global_asm_807F6000[arg0].unk6D[i];
    if (arg3) {
        var_a1 = arg2;
    } else {
        var_a1 = 0xFF;
    }
    while (i < 2 && !var_t0) {
        if (var_a1 == temp_a2[i]) {
            var_t0 = TRUE;
        } else {
            i++;
        }
    }
    if (arg3) {
        temp_a2[i] = 0xFF;
    } else {
        temp_a2[i] = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80633A1C.s")

void func_global_asm_80633D30(f32 *arg0, f32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0[i] < arg1[0]) {
            arg1[0] = arg0[i];
        }
        if (arg0[i + 6] < arg1[2]) {
            arg1[2] = arg0[i + 6];
        }
        if (arg1[3] < arg0[i + 0]) {
            arg1[3] = arg0[i + 0];
        }
        if (arg1[5] < arg0[i + 6]) {
            arg1[5] = arg0[i + 6];
        }
    }
}

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Struct80633DC0_arg1;

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
} Struct80633DC0_arg2;

void func_global_asm_80633DC0(f32 (*arg0)[4], Struct80633DC0_arg1 *arg1, Struct80633DC0_arg2 *arg2) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    guMtxXFMF(arg0, arg1->unk0, arg1->unk2, arg1->unk4, &sp3C, &sp38, &sp34);
    arg2->unkC = sp3C;
    arg2->unk10 = sp38;
    arg2->unk14 = sp34;
    arg2->unk18 = sp3C;
    arg2->unk1C = sp38;
    arg2->unk20 = sp34;
    guMtxXFMF(arg0, arg1->unk6, arg1->unk2, arg1->unk4, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
    guMtxXFMF(arg0, arg1->unk0, arg1->unk2, arg1->unkA, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
    guMtxXFMF(arg0, arg1->unk6, arg1->unk2, arg1->unkA, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
    guMtxXFMF(arg0, arg1->unk0, arg1->unk8, arg1->unk4, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
    guMtxXFMF(arg0, arg1->unk6, arg1->unk8, arg1->unk4, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
    guMtxXFMF(arg0, arg1->unk0, arg1->unk8, arg1->unkA, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
    guMtxXFMF(arg0, arg1->unk6, arg1->unk8, arg1->unkA, &sp3C, &sp38, &sp34);
    arg2->unkC = MIN(arg2->unkC, sp3C);
    arg2->unk10 = MIN(arg2->unk10, sp38);
    arg2->unk14 = MIN(arg2->unk14, sp34);
    arg2->unk18 = MAX(arg2->unk18, sp3C);
    arg2->unk1C = MAX(arg2->unk1C, sp38);
    arg2->unk20 = MAX(arg2->unk20, sp34);
}

typedef struct {
    s16 unk0; // X1
    s16 unk2; // Y1
    s16 unk4; // Z1
    s16 unk6; // X2
    s16 unk8; // Y2
    s16 unkA; // Z2
    s16 unkC; // X3
    s16 unkE; // Y3
    s16 unk10; // Z3
    u8 unk12;
    s8 unk13;
    u8 unk14;
    u8 unk15;
} Struct80634768;

typedef struct {
    f32 unk0; // X1
    f32 unk4; // Y1
    f32 unk8; // Z1
    f32 unkC; // X2
    f32 unk10; // Y2
    f32 unk14; // Z2
    f32 unk18; // X3
    f32 unk1C; // Y3
    f32 unk20; // Z3
    s8 unk24;
    s8 unk25;
    s8 unk26;
    s8 unk27;
} Struct80634768_arg1;

s32 func_global_asm_80634768(Struct80634768 *arg0, Struct80634768_arg1 *arg1, f32 (*arg2)[4]) {
    guMtxXFMF(arg2, arg0->unk0, arg0->unk2, arg0->unk4, &arg1->unk0, &arg1->unkC, &arg1->unk18);
    guMtxXFMF(arg2, arg0->unk6, arg0->unk8, arg0->unkA, &arg1->unk4, &arg1->unk10, &arg1->unk1C);
    guMtxXFMF(arg2, arg0->unkC, arg0->unkE, arg0->unk10, &arg1->unk8, &arg1->unk14, &arg1->unk20);
    arg1->unk24 = arg0->unk12;
    arg1->unk25 = arg0->unk14;
    arg1->unk26 = arg0->unk13;
    arg1->unk27 = arg0->unk15;
    return 1;
}

void func_global_asm_806348B4(Prop_unk48 *arg0) {
    void *temp_a2 = arg0->unk0;

    if (temp_a2 != NULL) {
        if (arg0->unk24 & 1) {
            free(temp_a2);
        }
    }
    arg0->unk24 &= 0xFFFE;
}

void func_global_asm_80633A1C(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);

void func_global_asm_80634908(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    func_global_asm_80633A1C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

// TODO: Needs more shape on Prop_unk24
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063495C.s")

/*
void func_global_asm_8063495C(Prop_unk24 *arg0, Prop *arg1) {
    PropModel50_B8 *var_v0;
    s16 *var_t0;
    s32 *temp_a3;
    s32 var_a0;
    s32 var_t1;
    s32 var_t2;

    var_v0 = arg1->model_pointer->unk50;
    if (var_v0 != NULL) {
        do {
            var_t1 = 0;
            temp_a3 = arg0->unk70 + arg0;
            var_a0 = *temp_a3;
            var_t0 = temp_a3 + 4;
            var_t2 = 0;
            if (var_a0 != 0) {
loop_2:
                if (var_v0->unk5C == *var_t0) {
                    var_t1 = 1;
                } else {
                    var_a0 -= 1;
                    var_t0 += 0x30;
                    var_t2 += 1;
                }
                if (var_a0 != 0) {
                    if (var_t1 == 0) {
                        goto loop_2;
                    }
                }
            }
            if (var_t1 != 0) {
                var_v0->unk44 = arg1->model_pointer->unk0[var_t2].unk24;
            } else {
                var_v0->unk44 = 0;
            }
            var_v0 = var_v0->next;
        } while (var_v0 != NULL);
    }
}
*/

// Init for PropModel50_B8
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806349FC.s")

void func_global_asm_80634CC8(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_global_asm_80634D64(arg0, arg1, arg2, arg3, &arg2, &arg3, 0);
}

void func_global_asm_80634D14(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 temp2;
    s16 temp;
    func_global_asm_80634D64(arg0, arg1, temp2, temp, arg2, arg3, 1);
}

void func_global_asm_80634D64(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, u8 arg6) {
    s32 propIndex = func_global_asm_80659470(arg0);
    PropModel *model = D_global_asm_807F6000[propIndex].model_pointer;

    switch (D_global_asm_807F6000[propIndex].unk86) {
        case 2:
            func_global_asm_80634E10(model->unk50, arg1, arg2, arg3, arg4, arg5, arg6);
            break;
        case 1:
            func_global_asm_80634E10(model->unkB8, arg1, arg2, arg3, arg4, arg5, arg6);
            break;
    }
}

void func_global_asm_80634E10(PropModel50_B8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 *arg4, s16 *arg5, u8 arg6) {
    // TODO: Better match for arg1--, this syntax is weird
    arg1--;
    while (arg0 && arg1) {
        arg1--;
        arg0 = arg0->next;
    }
    if (arg0) {
        if (arg6) {
            *arg4 = arg0->unk38;
            *arg5 = arg0->unk3A;
        } else {
            arg0->unk38 = arg2;
            arg0->unk3A = arg3;
        }
    }
}

void func_global_asm_80634EA4(s32 arg0, s16 arg1, u8 arg2) {
    func_global_asm_80634F14(arg0, arg1, arg2, &arg2, 0);
}

void func_global_asm_80634EDC(s32 arg0, s16 arg1, u8 *arg2) {
    u8 temp;
    func_global_asm_80634F14(arg0, arg1, temp, arg2, 1);
}

void func_global_asm_80634F14(s32 arg0, s16 arg1, u8 arg2, u8 *arg3, u8 arg4) {
    s32 propIndex = func_global_asm_80659470(arg0);
    PropModel *model = D_global_asm_807F6000[propIndex].model_pointer;

    switch (D_global_asm_807F6000[propIndex].unk86) {
        case 2:
            func_global_asm_80634FA0(model->unk50, arg1, arg2, arg3, arg4);
            break;
        case 1:
            func_global_asm_80634FA0(model->unkB8, arg1, arg2, arg3, arg4);
            break;
    }
}

void func_global_asm_80634FA0(PropModel50_B8 *arg0, s16 arg1, u8 arg2, u8 *arg3, u8 arg4) {
    // TODO: Better match for arg1--, this syntax is weird
    arg1--;
    while (arg0 && arg1) {
        arg1--;
        arg0 = arg0->next;
    }
    if (arg0) {
        if (arg4) {
            *arg3 = arg0->unk48;
        } else {
            arg0->unk48 = arg2;
        }
    }
}

void func_global_asm_80635018(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 propIndex = func_global_asm_80659470(arg0);
    PropModel *model = D_global_asm_807F6000[propIndex].model_pointer;

    switch (D_global_asm_807F6000[propIndex].unk86) {
        case 2:
            func_global_asm_80635098(model->unk50, arg1, arg2, arg3);
            break;
        case 1:
            func_global_asm_80635098(model->unkB8, arg1, arg2, arg3);
            break;
    }
}

void func_global_asm_80635098(PropModel50_B8 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    // TODO: Better match for arg1--, this syntax is weird
    arg1--;
    while (arg0 && arg1) {
        arg1--;
        arg0 = arg0->next;
    }
    if (arg0) {
        if (arg2 != arg0->unk54 || arg3 != arg0->unk50) {
            arg0->unk49 = 1;
        }
        arg0->unk54 = arg2;
        arg0->unk50 = arg3;
    }
}

// Similar to below, loops over DL looking for specific commands (G_SETTIMG (0xFD), G_SETPRIMCOLOR (0xFA))
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80635114.s")

// Finds the offset (byte length) of the first G_ENDDL command in a Display List,
// counting 8 bytes per command.
s32 func_global_asm_80635214(Gfx *dl) {
    s32 found;
    s32 offset;
    u32 command;

    offset = 0;
    found = FALSE;
    while (!found) {
        command = dl->words.w0 >> 0x18;
        if (command == G_ENDDL) {
            found = TRUE;
        }
        offset += 8;
        dl++;
    }
    return offset;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063524C.s")

typedef struct {
    s32 unk0; // TODO: proper members
} Struct80635548_unk24;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    Struct80635548_unk24 *unk24[1]; // TODO: How many?
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    void *unk34[1]; // TODO: How many?
} Struct80635548;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80635468.s")

/*
// TODO: Hmm
void func_global_asm_80635468(Struct80635548_unk24 *arg0, Struct80635548 *arg1) {
    s16 temp_a1;
    s32 i;
    s32 var_v0;
    void *var_s2;

    var_s2 = arg0->unk70 + arg0 + 4;
    if (*(arg0->unk6C + arg0) != 0) {
        var_v0 = 7;
    } else {
        var_v0 = 0x19;
    }
    for (i = 0; i < arg1->unk20; i++) {
        arg1->unk24[i] = getPointerTableFile(var_v0, var_s2->unk0, 1, 0);
        temp_a1 = var_s2->unk2;
        if (temp_a1 != -1) {
            arg1->unk34[i] = getPointerTableFile(var_v0, temp_a1, 1, 0);
        } else {
            arg1->unk34[i] = NULL;
        }
        var_s2 += 0x30;
    }
}
*/

void func_global_asm_80635548(s32 arg0, Struct80635548 *arg1) {
    s32 i;

    for (i = 0; i < arg1->unk20; i++) {
        arg1->unk24[i] = 0;
        arg1->unk34[i] = 0;
    }
}

extern s32 D_global_asm_80747D70;

void func_global_asm_80635588(void) {
    s32 temp_s1;
    s32 i;

    temp_s1 = D_global_asm_80747D70;
    for (i = 0; i < temp_s1; i++) {
        func_global_asm_806355DC(0, 0);
    }
    func_global_asm_80659350();
}

void func_global_asm_8063DE68(void*);

void func_global_asm_8066C904(Prop_unk28 *arg0);

void func_global_asm_806355DC(s32 arg0, u8 arg1) {
    s16 sp36;
    s16 sp34;
    u8 sp33;

    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    func_global_asm_8062D2AC(D_global_asm_807F6000[arg0].model_pointer, &sp34, 0);
    func_global_asm_80630588(0, D_global_asm_807F6000[arg0].model_pointer, 2, &sp33);
    func_global_asm_8066C904(&D_global_asm_807F6000[arg0].unk28);
    func_global_asm_806348B4(&D_global_asm_807F6000[arg0].unk48);
    func_global_asm_80633570(D_global_asm_807F6000[arg0].unk70);
    func_global_asm_806338B4(D_global_asm_807F6000[arg0].unk74);
    func_global_asm_8064F804(D_global_asm_807F6000[arg0].unk78);
    func_global_asm_80636074(&D_global_asm_807F6000[arg0]);
    if (D_global_asm_807F6000[arg0].unk7C != NULL) {
        func_global_asm_8063DE68(D_global_asm_807F6000[arg0].unk7C);
    }
    D_global_asm_807F6240[D_global_asm_807F6000[arg0].unk8A] = -1;
    func_global_asm_806645B8(D_global_asm_807F6000[arg0].unk88);
    sp36 = D_global_asm_807F6000[arg0].unk88;
    func_global_asm_806594C8(sp36);
    func_global_asm_8072F09C(sp36);
    if (D_global_asm_807F6000[arg0].unk7C != NULL) {
        if (D_global_asm_807F6000[arg0].unk7C->unk10[0] != -1) {
            func_global_asm_80605380(D_global_asm_807F6000[arg0].unk7C->unk10[0]);
        }
        if (D_global_asm_807F6000[arg0].unk7C->unk10[1] != -1) {
            func_global_asm_80605380(D_global_asm_807F6000[arg0].unk7C->unk10[1]);
        }
    }
    if ((arg0 + 1) != D_global_asm_80747D70) {
        func_global_asm_806593C8(D_global_asm_807F6000[D_global_asm_80747D70 - 1].unk88, arg0);
    }
    memcpy(&D_global_asm_807F6000[arg0], &D_global_asm_807F6000[D_global_asm_80747D70 - 1], sizeof(Prop));
    D_global_asm_80747D70 -= 1;
}

void func_global_asm_806357F8(s32 arg0, f32 *x, f32 *y, f32 *z, f32 *xRot, f32 *yRot, f32 *zRot, f32 *scale, f32 *arg8, u8 arg9) {
    if (arg9 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    *x = D_global_asm_807F6000[arg0].x_position;
    *y = D_global_asm_807F6000[arg0].y_position;
    *z = D_global_asm_807F6000[arg0].z_position;
    *xRot = D_global_asm_807F6000[arg0].x_rotation;
    *yRot = D_global_asm_807F6000[arg0].y_rotation;
    *zRot = D_global_asm_807F6000[arg0].z_rotation;
    *scale = D_global_asm_807F6000[arg0].hitbox_scale;
    *arg8 = D_global_asm_807F6000[arg0].unk1C;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806358E8.s")

s32 func_global_asm_80635EF0(f32 x1, f32 y1, f32 z1, s16 x2, s16 y2, s16 z2, u16 arg6) {
    s32 i;
    f32 dx = x1 - x2;
    f32 dy = y1 - y2;
    f32 dz = z1 - z2;
    f32 dx2 = x2 + x1;
    f32 dy2 = y2 + y1;
    f32 dz2 = z2 + z1;

    for (i = 0; i < D_global_asm_807FBB34; i++) {
        Actor *temp = D_global_asm_807FB930[i].unk0;
        if (temp->interactable & arg6) {
            if (dx <= temp->x_position
            && dy <= temp->y_position
            && dz <= temp->z_position
            && temp->x_position <= dx2
            && temp->y_position <= dy2
            && temp->z_position <= dz2) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void func_global_asm_80636014(s32 arg0, u8 arg1, u8 arg2) {
    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    func_global_asm_8062D094(D_global_asm_807F6000[arg0].model_pointer, arg2);
}

void func_global_asm_80636380(Prop_unk24 *arg0, Struct80635548 *arg1);

void func_global_asm_80636074(Prop *arg0) {
    PropModel50_B8 *var_s0;
    PropModel50_B8 *temp_a0_3;
    PropModel54_BC *sp24;
    s32 temp_a0;

    switch (arg0->unk86) {
        case 2:
            var_s0 = arg0->model_pointer->unk50;
            sp24 = arg0->model_pointer->unk54;
            func_global_asm_80636380(arg0->unk24, arg0->model_pointer);
            break;
        case 1:
            var_s0 = arg0->model_pointer->unkB8;
            sp24 = arg0->model_pointer->unkBC;
            func_global_asm_806365D0(arg0, arg0->unk24, arg0->model_pointer);
            break;
    }
    while (var_s0 != NULL) {
        temp_a0 = var_s0->unk3C;
        if (temp_a0 != 0) {
            func_global_asm_8066B434(temp_a0, 0x9DB, 7);
        }
        temp_a0 = var_s0->unk40;
        if (temp_a0 != 0) {
            func_global_asm_8066B434(temp_a0, 0x9DC, 7);
        }
        temp_a0_3 = var_s0;
        var_s0 = var_s0->next;
        free(temp_a0_3);
    }
    if (sp24 != NULL) {
        func_global_asm_8066B434(sp24->unk0, 0x9E5, 7);
        free(sp24);
    }
}

void func_global_asm_80636164(PropModel *arg0, u8 arg1) {
    PropModel50_B8 *temp_a0;
    PropModel50_B8 *var_s0;

    switch (arg1) {
        case 2:
            var_s0 = arg0->unk50;
            break;
        case 1:
            var_s0 = arg0->unkB8;
            break;
        default:
            return;
    }

    while (var_s0 != NULL) {
        temp_a0 = var_s0->unk3C;
        if (temp_a0 != NULL) {
            if (var_s0->unkD0 == 0) {
                func_global_asm_8066B434(temp_a0, 0xA09, 7);
                var_s0->unk3C = NULL;
            }
        }
        temp_a0 = var_s0->unk40;
        if (temp_a0 != NULL) {
            if (var_s0->unkD0 == 0) {
                func_global_asm_8066B434(temp_a0, 0xA0E, 7);
                var_s0->unk40 = NULL;
            }
        }
        var_s0 = var_s0->next;
    }
}

void func_global_asm_80636210(PropModel *arg0, u8 arg1) {
    if (arg1 == 2) {
        if (arg0->unk50 == 0) {
            s32 i;
            PropModel *temp = arg0;
            for (i = 0; i < temp->unk20; i++) {
                if (temp->unk24[i] != NULL) {
                    func_global_asm_8066B434(temp->unk24[i], 0xA2B, 7);
                    temp->unk24[i] = NULL;
                }
                if (temp->unk34[i] != NULL) {
                    func_global_asm_8066B434(temp->unk34[i], 0xA30, 7);
                    temp->unk34[i] = NULL;
                }
            }
        }
    }
}

void func_global_asm_806362C4(s32 arg0, u8 arg1) {
    PropModel54_BC *temp_a3;
    PropModel54_BC **sp18;
    Prop *temp_v0;
    s16 temp_v1;

    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    temp_v0 = &D_global_asm_807F6000[arg0];
    switch (temp_v0->unk86) {
        case 2:
            sp18 = &temp_v0->model_pointer->unk54;
            break;
        case 1:
            sp18 = &temp_v0->model_pointer->unkBC;
            break;
    }
    if (sp18 != NULL) {
        temp_a3 = *sp18;
        if (temp_a3 != NULL) {
            func_global_asm_8066B434(temp_a3->unk0, 0xA56, 7);
            free(temp_a3);
            *sp18 = NULL;
        }
    }
}

void func_global_asm_80636380(Prop_unk24 *arg0, Struct80635548 *arg1) {
    s32 i;

    for (i = 0; i < arg1->unk20; i++) {
        if (arg1->unk24[i] != NULL) {
            func_global_asm_8066B434(arg1->unk24[i], 0xA69, 7);
        }
        if (arg1->unk34[i] != NULL) {
            func_global_asm_8066B434(arg1->unk34[i], 0xA6A, 7);
        }
    }
    func_global_asm_8066B434(arg0, 0xA6E, 7);
    func_global_asm_8061134C(arg1->unk1C);
    func_global_asm_8061134C(arg1);
    func_global_asm_8061134C(arg1->unk14);
    func_global_asm_8061134C(arg1->unk18);
}

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
    s16 unk3C; // Used
} Struct807F6160_unk10;

typedef struct struct_807F6160 Struct807F6160;

struct struct_807F6160 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    Struct807F6160_unk10 *unk10; // Pointer to something at least 0x3C big, see func_global_asm_806364C4
    s32 unk14;
    Struct807F6160 *unk18; // Linked list
};

extern Struct807F6160 *D_global_asm_807F6160;

void func_global_asm_8063643C(void) {
    D_global_asm_807F6160 = NULL;
}

void func_global_asm_80636448(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    Struct807F6160 *new;
    Struct807F6160 *old;

    new = malloc(sizeof(Struct807F6160));
    old = D_global_asm_807F6160;
    D_global_asm_807F6160 = new;
    new->unk18 = old;
    new->unk0 = arg0;
    new->unk4 = arg1;
    new->unk8 = arg2;
    new->unkC = arg3;
    new->unk14 = object_timer + 2;
    new->unk10 = arg4;
}

void func_global_asm_80636784(s32, s32, s32, s32, s32);

void func_global_asm_806364C4(void) {
    Struct807F6160 *next;
    Struct807F6160 *current;
    Struct807F6160 *var_s1;

    current = D_global_asm_807F6160;
    var_s1 = NULL;
    while (current != NULL) {
        next = current->unk18;
        if (object_timer == current->unk14) {
            current->unk10->unk3C--;
            func_global_asm_80636784(current->unk0, current->unk4, 0, 0, current->unk10->unk3C == 0);
            func_global_asm_80636784(current->unk8, current->unkC, 0, 1, current->unk10->unk3C == 0);
            func_global_asm_8066B434(current->unk10, 0xAB1, 7);
            if (var_s1 == NULL) {
                D_global_asm_807F6160 = current->unk18;
            } else {
                var_s1->unk18 = current->unk18;
            }
            free(current);
        } else {
            var_s1 = current;
        }
        current = next;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806365D0.s")

/*
// TODO: I think temp_v1 and temp_t0 is a count of the different between pointers to struct arrays
void func_global_asm_806365D0(Prop *arg0, Prop_unk24 *arg1, PropModel *arg2) {
    u8 sp33;
    s32 var_v0;
    u32 temp_t0;
    u32 temp_v1;

    temp_v1 = (arg2->unkA0[2] - arg2->unkA0[0]);
    temp_t0 = (arg2->unkB0 - arg2->unkA0[2]);
    if (arg2->unkB8 == NULL) {
        var_v0 = arg0->unk8C & 0x20;
        if (var_v0 != 0) {
            sp33 = 0;
        } else {
            goto block_3;
        }
    } else {
block_3:
        sp33 = 1;
        var_v0 = arg0->unk8C & 0x20;
    }
    if (var_v0 != 0) {
        if (sp33) {
            arg1->unk3C -= 1;
            func_global_asm_80636784(arg2->unkA0[0], arg2->unkA0[0] + (temp_v1), arg2->unkB8, 0, 0);
            func_global_asm_80636784(arg2->unkA0[2], arg2->unkA0[2] + (temp_t0), arg2->unkB8, 1, 0);
        } else {
            func_global_asm_80636448(arg2->unkA0[0], arg2->unkA0[0] + (temp_v1), arg2->unkA0[2], arg2->unkA0[2] + (temp_t0), arg1);
        }
    }
    if (arg2->unkB8 != NULL) {
        func_global_asm_80636784(arg2->unkA0[1], arg2->unkA0[1] + (temp_v1), arg2->unkB8, 0, 0);
        func_global_asm_80636784(arg2->unkA0[3], arg2->unkA0[3] + (temp_t0), arg2->unkB8, 1, 0);
        func_global_asm_8061134C(arg2->unkA0[1]);
        func_global_asm_8061134C(arg2->unkA0[3]);
    }
    if (sp33) {
        func_global_asm_8066B434(arg1, 0xAF7, 7);
    }
    func_global_asm_8061134C(arg2);
}
*/

// Appears to parse a displaylist looking for 0xFD command
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636784.s")

// Prop Geometry, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806368F0.s")

extern u8 D_global_asm_80750AB4;

// TODO: Move this to structs.h once the shape is locked in
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
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    u8 unk4E;
    u8 unk4F;
    s32 unk50;
    s32 unk54;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    s32 unk5C;
} PropModelAlt;

/*
void func_global_asm_806368F0(Prop *arg0, s32 propType) {
    void *sp28;
    u8 temp_v0;
    PropModelAlt *temp_v0_2;
    PropModel *temp_v0_3;
    Prop_unk24 *temp_v1;
    void *var_v0;

    if (func_global_asm_80636A8C(propType) != 0) {
        var_v0 = getPointerTableFile(4, propType, 1, 1);
    } else {
        var_v0 = getPointerTableFile(4, propType, 1, 0);
    }
    temp_v1 = arg0->unk24;
    arg0->unk24 = var_v0;
    arg0->unk8C = 0;
    arg0->unk86 = temp_v1->unk1C;
    arg0->object_type = propType;
    switch (temp_v1->unk1C) {
        case 2:
            temp_v0_2 = malloc(0x60);
            sp28 = temp_v0_2;
            temp_v0_2->unk4A = propType;
            temp_v0_2->unk50 = 0;
            temp_v0_2->unk54 = 0;
            temp_v0_2->unk4C = -1;
            temp_v0_2->unk4E = 0;
            temp_v0_2->unk5B = 0;
            temp_v0_2->unk14 = malloc(D_global_asm_80750AB4 << 6);
            temp_v0_2->unk18 = malloc(D_global_asm_80750AB4 << 6);
            break;
        case 1:
            temp_v0_3 = malloc(0xC8);
            sp28 = temp_v0_3;
            temp_v0_3->unkB4 = propType;
            temp_v0_3->unkB8 = 0;
            temp_v0_3->unkA0[0] = temp_v1->unk40 + temp_v1;
            temp_v0_3->unkA0[2] = temp_v1->unk44 + temp_v1;
            temp_v0_3->unkBC = 0;
            temp_v0_3->unkB6 = -1;
            temp_v0_3->unkB0 = temp_v1->unk48 + temp_v1;
            temp_v0_3->unkC3 = 0;
            break;
    }
    arg0->model_pointer = sp28;
}
*/

f32 func_global_asm_80636A44(s32 arg0) {
    s32 pad2; // TODO: Why is this needed?
    s32 pad; // TODO: Why is this needed?
    f32 sp1C;
    f32 *propGeometry;

    // Prop Geometry
    propGeometry = getPointerTableFile(4, arg0, 1, 0);
    sp1C = propGeometry[1];
    func_global_asm_8066B434(propGeometry, 0xB87, 7);
    return sp1C;
}

u8 func_global_asm_80636A8C(s32 arg0) {
    s32 pad; // TODO: Why is this needed?
    s32 pad2; // TODO: Why is this needed?
    s32 phi_v1;
    s32 *propGeometry;

    // Prop Geometry
    propGeometry = getPointerTableFile(4, arg0, 1, 0);
    if (*propGeometry & 8) {
        phi_v1 = TRUE;
    } else {
        phi_v1 = FALSE;
    }
    func_global_asm_8066B434(propGeometry, 0xBA3, 7);
    return phi_v1;
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636AE8.s")

/*
void func_global_asm_80636AE8(Prop *arg0) {
    PropModel *model;
    s32 count1;
    s32 count2;

    model = arg0->model_pointer;
    count1 = model->unkA0[2] - model->unkA0[0];
    count2 = model->unkA0[4] - model->unkA0[2];
    func_global_asm_8065CDB0(model->unkA0[0], &model->unkA0[0][count1]);
    func_global_asm_8065CDB0(model->unkA0[2], &model->unkA0[2][count2]);
}
*/

// Appears to parse a displaylist looking for 0xFD commands
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636B50.s")

// close
// https://decomp.me/scratch/DuYBv
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636C00.s")

extern s32 D_global_asm_80747D70;
extern s16 D_global_asm_80747D74;

void func_global_asm_80636B50(void *arg0, void *arg1, u8 arg2);

/*
// TODO: Pretty close, I think the params in the last function calls might need to be temp variables
void func_global_asm_80636C00(void) {
    u32 sp20;
    u8 var_a2;
    PropModel *temp_a3;
    Prop *temp_a0;
    s32 temp_v1_2;
    u8 temp_v1;
    Prop_unk24 *temp_v0;

    if (D_global_asm_80747D70 != 0) {
        D_global_asm_80747D74 += 1;
        if (D_global_asm_80747D74 >= D_global_asm_80747D70) {
            D_global_asm_80747D74 = 0;
        }
        temp_a0 = &D_global_asm_807F6000[D_global_asm_80747D74];
        temp_v0 = temp_a0->unk24;
        if (temp_v0->unk0 & 0x10) {
            if ((temp_a0->unk8C & 0x20) && (object_timer != temp_v0->unk8)) {
                temp_a0->unk8C &= 0xFFDF;
                temp_v0->unk3C--;
                if (temp_v0->unk3C != 0) {
                    var_a2 = 0;
                } else {
                    var_a2 = 1;
                }
                temp_a3 = D_global_asm_807F6000[D_global_asm_80747D74].model_pointer;
                func_global_asm_80636B50(temp_a3->unkA0[0], temp_a3->unkA0[0] + (((temp_a3->unkA0[2] - temp_a3->unkA0[0]) >> 3) * 8), var_a2);
                func_global_asm_80636B50(temp_a3->unkA0[2], temp_a3->unkA0[2] + (((temp_a3->unkB0 - temp_a3->unkA0[2]) >> 3) * 8), var_a2);
            }
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636D38.s")

// Appears to parse a displaylist looking for 0xFD commands
// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636EFC.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80636FFC.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80637B6C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_806392BC.s")

void func_global_asm_806398E4(s32 propIndex, u8 arg1, u8 arg2) {
    PropModel *temp_v0;

    if (arg1 == 1) {
        propIndex = func_global_asm_80659470(propIndex);
    }
    temp_v0 = D_global_asm_807F6000[propIndex].model_pointer;
    if (arg2 != 0) {
        temp_v0->unk4E |= 1;
    } else {
        temp_v0->unk4E &= 0xFFFE;
    }
    temp_v0->unk4E &= 0xFFFD;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80639968.s")

typedef struct {
    u8 unk0[0x30 - 0x0];
    s32 unk30;
    u8 unk34[0x44 - 0x34];
    s32 unk44;
    u8 unk48[0xD4 - 0x48];
    s32 unkD4;
} Struct80639C04_arg0_unk50;

typedef struct {
    u8 unk0[0x24 - 0x0];
    s32 unk24[1];
    u8 unk28[0x50 - 0x28];
    Struct80639C04_arg0_unk50 *unk50;
} Struct80639C04_arg0;

typedef struct {
    u8 unk0[0x30 - 0x0];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    void *unk3C;
    void *unk40;
    s32 unk44;
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 unk4B;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C[1]; // TODO: How many?
    u8 unk60[0xD0 - 0x60];
    u8 unkD0;
} Struct80639CD0;

void func_global_asm_80639CD0(Struct80639CD0 *arg0, void **arg1, void **arg2, u8 *arg3, s16 *arg4);

void func_global_asm_80639C04(Struct80639C04_arg0 *arg0, s32 arg1, s32 *arg2, s32 arg3, s8 *arg4, s32 arg5) {
    s32 temp_v1;
    s32 found;
    Struct80639C04_arg0_unk50 *current;

    current = arg0->unk50;
    if (current != NULL) {
        temp_v1 = arg0->unk24[arg1];
        found = FALSE;
        while (current != NULL && !found) {
            if (temp_v1 == current->unk44) {
                found = TRUE;
            } else {
                current = current->unkD4;
            }
        }
        if (found) {
            func_global_asm_80639CD0(current, arg2, arg3, arg4, arg5);
            current->unk30 = object_timer;
        } else {
            *arg4 = 0;
            *arg2 = temp_v1;
        }
    } else {
        *arg4 = 0;
        *arg2 = arg0->unk24[arg1];
    }
}

void func_global_asm_80639CD0(Struct80639CD0 *arg0, void **arg1, void **arg2, u8 *arg3, s16 *arg4) {
    u8 var_v1;
    s32 sp30;
    s32 sp2C;

    if (object_timer == arg0->unk30) {
        var_v1 = 0;
    } else {
        var_v1 = func_global_asm_80639F1C(arg0, &sp30, &sp2C);
    }
    if (var_v1 || arg0->unk3C == NULL) {
        if (arg0->unk4A) {
            if (!(arg0->unk40 != NULL && !arg0->unk49)) {
                if (arg0->unk3C != NULL) {
                    func_global_asm_8066B434(arg0->unk3C, 0xFCB, 7);
                }
                if (arg0->unkD0) {
                    func_global_asm_8066B0DC();
                }
                arg0->unk3C = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, arg0->unk5C[sp30], 0, 0);
                if (arg0->unk40 != NULL) {
                    func_global_asm_8066B434(arg0->unk40, 0xFCE, 7);
                }
                if (arg0->unkD0) {
                    func_global_asm_8066B0DC();
                }
                arg0->unk40 = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, arg0->unk5C[sp2C], 0, 0);
            } else {
                if (arg0->unk3C != NULL) {
                    func_global_asm_8066B434(arg0->unk3C, 0xFD5, 7);
                }
                arg0->unk3C = arg0->unk40;
                if (arg0->unkD0) {
                    func_global_asm_8066B0DC();
                }
                arg0->unk40 = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, arg0->unk5C[sp2C], 0, 0);
            }
        } else {
            if (arg0->unk3C != NULL) {
                func_global_asm_8066B434(arg0->unk3C, 0xFDF, 7);
            }
            if (arg0->unkD0) {
                func_global_asm_8066B0DC();
            }
            arg0->unk3C = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, arg0->unk5C[sp30], 0, 0);
        }
    }
    arg0->unk49 = 0;
    *arg3 = arg0->unk4A;
    if (arg0->unk4A != 0) {
        *arg4 = ((f32)arg0->unk50 / arg0->unk4C) * 255.0f;
    }
    *arg1 = arg0->unk3C;
    *arg2 = arg0->unk40;
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80639F1C.s")

/*
s32 func_global_asm_80639F1C(PropModel50_B8 *arg0, s32 *arg1, s32 *arg2) {
    s32 var_v1;
    s32 temp;

    var_v1 = FALSE;
    switch (arg0->unk48) {
        case 1:
            if (arg0->unk4C == ++arg0->unk50) {
                arg0->unk50 = 0;
                if (arg0->unk58 == ++arg0->unk54) {
                    arg0->unk54 = 0;
                }
                var_v1 = TRUE;
            }
            break;
        case 0:
            if (arg0->unk49) {
                var_v1 = TRUE;
            }
            break;
    }
    *arg1 = arg0->unk54;
    temp = arg0->unk54 + 1;
    if (arg0->unk54 + 1 == arg0->unk58) {
        *arg2 = 0;
    } else {
        *arg2 = arg0->unk54;
    }
    return var_v1;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_80639FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063A38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063A848.s")

void func_global_asm_8063A8C4(s16 arg0, u8 arg1, f32 arg2) {
    PropModel *temp_v1;
    PropModel54_BC *phi_v0;

    if (arg1 == 1) {
        arg0 = func_global_asm_80659470(arg0);
    }
    temp_v1 = D_global_asm_807F6000[arg0].model_pointer;
    if (D_global_asm_807F6000[arg0].unk86 != 1) {
        if (D_global_asm_807F6000[arg0].unk86 != 2) {

        } else {
            phi_v0 = temp_v1->unk54;
        }
    } else {
        phi_v0 = temp_v1->unkBC;
    }
    if (phi_v0 != NULL) {
        phi_v0->unk4 = arg2;
    }
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063A968.s")

void func_global_asm_8063B4A4(void) {
    D_global_asm_807F6028 = 0;
    D_global_asm_807F60A8 = 0;
    D_global_asm_807F6938 = 0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063B4C0.s")

// big, prop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063B758.s")

// big, prop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063B8D8.s")

// big, prop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063BBB0.s")

typedef struct {
    s16 unk0;
    u8 unk2[0x117 - 0x2];
    u8 unk117;
    u8 unk118[0x120 - 0x118];
    u8 unk120;
    u8 unk121[0x250 - 0x121];
    u8 unk250; // Index into array at unk254
    u8 unk251[0x254 - 0x251];
    s32 unk254[1][16]; // TODO: What is this? Matrix array? Substruct array?
} Struct8063BEC0_arg0;

void func_global_asm_8063BEC0(Struct8063BEC0_arg0 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 found;
    s32 i;

    found = FALSE;
    for (i = 0; !found && i < arg1;) {
        if (arg2 == arg0->unk0) {
            found = TRUE;
        } else {
            i++;
            arg0 = arg0->unk254[arg0->unk250];
        }
    }
    if (found) {
        arg0->unk117 = arg3;
        arg0->unk120 = 1;
    }
}

// Prop -> 0x48, 0x49, 0x4E, 0x7C -> 0x10, 0x12, 0x38, 0x94, 0x9A
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063BF34.s")

void func_global_asm_8063C1EC(s32 arg0, u8 arg1) {
    D_global_asm_807F6000[func_global_asm_80659470(D_global_asm_807F6240[arg0])].model_pointer->unk4E |= arg1;
}

void func_global_asm_8063C248(s32 arg0, u8 arg1) {
    D_global_asm_807F6000[func_global_asm_80659470(D_global_asm_807F6240[arg0])].model_pointer->unk4E &= ~arg1;
}

s32 func_global_asm_8063C2A8(s16 arg0) {
    Prop_ScriptData *temp_v1;

    // TODO: Find a way to get rid of s16 typecast...?
    temp_v1 = D_global_asm_807F6000[(s16)func_global_asm_80659470(arg0)].unk7C;
    if (temp_v1 != NULL) {
        if ((temp_v1->unk60 == 1) && (temp_v1->unk64 == 0)) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

s16 func_global_asm_8063C328(s16 arg0) {
    s16 propIndex = func_global_asm_80659470(arg0);
    if (propIndex == -1) {
        return -1;
    }
    return D_global_asm_807F6000[propIndex].object_type;
}

typedef struct {
    void (*unk0)(void); // Function pointer, used
    Gfx *(*unk4)(Gfx*); // Function pointer, used
    void (*unk8)(void); // Function pointer, used
    u8 unkC; // Used
    s8 unkD;
    s8 unkE;
    s8 unkF;
} Struct80747D80;

extern Struct80747D80 D_global_asm_80747D80[];

void func_global_asm_8063C390(void) {
    s32 i = 0;

    for (i = 0; i < 8; i++) {
        D_global_asm_80747D80[i].unkC = FALSE;
    }
}

void func_global_asm_8063C3C0(s16 arg0) {
    if (!D_global_asm_80747D80[arg0].unkC) {
        D_global_asm_80747D80[arg0].unk0();
        D_global_asm_80747D80[arg0].unkC = TRUE;
    }
}

Gfx *func_global_asm_8063C418(Gfx *dl, s16 arg1) {
    return D_global_asm_80747D80[arg1].unk4(dl);
}

void func_global_asm_8063C450(void) {
    s32 i = 0;

    for (i = 0; i < 8; i++) {
        if (D_global_asm_80747D80[i].unkC) {
            D_global_asm_80747D80[i].unk8();
        }
    }
}

void func_global_asm_8063C4A8(void) {
    D_global_asm_807F6170 = 255.0f;
    D_global_asm_807F6174 = 255.0f;
}

Gfx *func_global_asm_8063C4C4(Gfx *dl) {
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_TILE);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 3, 1, G_ON);
    gDPSetRenderMode(dl++, G_RM_PASS, G_RM_RA_OPA_SURF2);
    gDPSetCombineLERP(dl++, TEXEL0, 0, TEXEL1, 0, TEXEL0, 0, TEXEL1, 0, 1, 0, COMBINED, PRIMITIVE, 0, 0, 0, SHADE);
    gDPSetEnvColor(dl++, 0x00, 0x40, 0x7F, 0xFF);
    gDPSetPrimColor(dl++, 0, 0, 0x50, 0x50, 0xB4, 0x46);
    gDPSetTileSize(dl++, 1, (s32)D_global_asm_807F6170, 0, 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 512);
    gDPTileSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, 15);
    gDPSetTileSize(dl++, 2, (s32)D_global_asm_807F6174, 0, 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 512);
    gDPTileSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, 15);
    return dl;
}

void func_global_asm_8063C6D8(void) {
    D_global_asm_807F6170 -= 1.0;
    if (D_global_asm_807F6170 < 0.0) {
        D_global_asm_807F6170 = 255.0f;
    }
    D_global_asm_807F6174 -= 0.439;
    if (D_global_asm_807F6174 < 0.0) {
        D_global_asm_807F6174 = 255.0f;
    }
}

void func_global_asm_8063C784(void) {
    D_global_asm_807F6178 = 255.0f;
    D_global_asm_807F617C = getPointerTableFile(TABLE_25_TEXTURES_GEOMETRY, 0x565, 1, 0); // Texture
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063C7C4.s")

void func_global_asm_8063CA7C(void) {
    D_global_asm_807F6178 -= 1.0;
    if (D_global_asm_807F6178 < 0.0) {
        D_global_asm_807F6178 = 255.0f;
    }
}

void func_global_asm_8063CADC(void) {
    D_global_asm_807F6180 = 255.0f;
    D_global_asm_807F6184 = 255.0f;
    D_global_asm_807F6188 = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, 0x3B7, 0, 0); // Texture
    D_global_asm_807F618C = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, 0x3B8, 0, 0); // Texture
}

// Jumptable, Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063CB40.s")

void func_global_asm_8063CE64(void) {
    D_global_asm_807F6180 -= 1.234;
    if (D_global_asm_807F6180 < 0.0) {
        D_global_asm_807F6180 = 255.0f;
    }
    D_global_asm_807F6184 -= 0.45;
    if (D_global_asm_807F6184 < 0.0) {
        D_global_asm_807F6184 = 255.0f;
    }
}

void func_global_asm_8063CF0C(void) {
    D_global_asm_807F6190 = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, 0x3E0, 1, 0); // Texture
}

extern f32 D_global_asm_80747E00;
extern f32 D_global_asm_80747E04;
extern s16 D_global_asm_80747E08;

Gfx *func_global_asm_8063CF3C(Gfx *dl) {
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPSetTextureLOD(dl++, G_TL_TILE);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 1, 1, G_ON);
    if (func_global_asm_80659190()) {
        gSPSetGeometryMode(dl++, G_FOG);
        gDPSetRenderMode(dl++, G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2);
        gDPSetCombineLERP(dl++, 0, 0, 0, 0, TEXEL0, 0, TEXEL1, 0, TEXEL1, 0, TEXEL0, 0, COMBINED, 0, PRIMITIVE, 0);
        gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, D_global_asm_80747E08);
    } else {
        gDPSetRenderMode(dl++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
        gDPSetCombineLERP(dl++, 0, 0, 0, 0, TEXEL0, 0, TEXEL1, 0, TEXEL1, 0, TEXEL0, 0, COMBINED, 0, SHADE, 0);
    }
    gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, (s32)D_global_asm_807F6190 + 0x80000000);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 2047, 256);
    gDPPipeSync(dl++);\
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD);\
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x00FC, 0x00FC);
    gDPSetTileSize(dl++, 1, 0, (s32)D_global_asm_80747E00, 0x00FC, 0x00FC);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, 1, G_TX_NOMIRROR | G_TX_WRAP, 6, 1);
    gDPSetTileSize(dl++, 2, 0, (s32)D_global_asm_80747E04, 0x00FC, 0x00FC);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, 1, G_TX_NOMIRROR | G_TX_WRAP, 6, 1);
    return dl;
}

void func_global_asm_8063D1D8(void) {
    D_global_asm_80747E00 -= 5.0;
    if (D_global_asm_80747E00 < 0.0) {
        D_global_asm_80747E00 = 255.0f;
    }
    D_global_asm_80747E04 -= 2.0;
    if (D_global_asm_80747E04 < 0.0) {
        D_global_asm_80747E04 = 255.0f;
    }
}

typedef struct {
    s16 unk0; // Texture index
    s16 unk2;
    void *unk4; // Pointer to an uncompressed texture
} GlobalASMStruct77;

extern GlobalASMStruct77 D_global_asm_80747E0C[];

void func_global_asm_8063D288(void) {
    s32 i;

    D_global_asm_807F6194 = 0;
    for (i = 0; i < 11; i++) {
        // Texture (Uncompressed)
        D_global_asm_80747E0C[i].unk4 = getPointerTableFile(TABLE_07_TEXTURES_UNCOMPRESSED, D_global_asm_80747E0C[i].unk0, 1, 0);
    }
}

// Displaylist stuff, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_36880/func_global_asm_8063D2E4.s")

/*
Gfx *func_global_asm_8063D2E4(Gfx *dl) {
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
    gDPSetCombineMode(dl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_global_asm_80747E0C[D_global_asm_807F6194].unk4);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD);
    gDPLoadSync(dl++);
    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gDPPipeSync(dl++);
    gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, 0, 0x00FC, 0x007C);
    return dl;
}
*/

void func_global_asm_8063D468(void) {
    D_global_asm_807F6194++;
    if (D_global_asm_807F6194 == 11) {
        D_global_asm_807F6194 = 0;
    }
}

void func_global_asm_8063D494(void) {
    D_global_asm_807F6198 = 0.0f;
}

extern f32 D_global_asm_807F6198;

Gfx *func_global_asm_8063D4A4(Gfx *dl) {
    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, (s32)D_global_asm_807F6198, 0x00FC, 0x00FC);
    return dl;
}

void func_global_asm_8063D5AC(void) {
    D_global_asm_807F6198 -= 0.865;
    if (D_global_asm_807F6198 < 0.0) {
        D_global_asm_807F6198 = 255.0f;
    }
}

void func_global_asm_8063D608(void) {
    D_global_asm_807F619C = getPointerTableFile(TABLE_25_TEXTURES_GEOMETRY, 0x1765, 1, 0); // Texture
}

extern f32 D_global_asm_807F61A0;

Gfx *func_global_asm_8063D638(Gfx *dl) {
    s32 alpha;

    gDPPipeSync(dl++);
    gDPSetCycleType(dl++, G_CYC_2CYCLE);
    gDPSetTextureLOD(dl++, G_TL_LOD);
    gSPClearGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(dl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(dl++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA, G_CC_MODULATEIA_PRIM2);
    
    switch (current_map) {
        case MAP_DK_ISLES_OVERWORLD:
        case MAP_CASTLE_BARREL_BLAST:
            alpha = 0xFF;
            break;
        case MAP_GALLEON_BARREL_BLAST:
        case MAP_FUNGI_BARREL_BLAST:
            alpha = 0x96;
            break;
        default:
            alpha = 0x50;
            break;
    }

    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    // TODO: Better match for this
    gDPLoadTextureBlock(dl++, (s32)D_global_asm_807F619C + 0x80000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTileSize(dl++, G_TX_RENDERTILE, 0, (s32)D_global_asm_807F61A0, 0x007C, 0x007C);
    gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

    return dl;
}

void func_global_asm_8063D854(void) {
    switch (current_map) {
        case MAP_CASTLE_BARREL_BLAST:
            D_global_asm_807F61A0 -= 2.0;
            break;
        case MAP_FUNGI_BARREL_BLAST:
            D_global_asm_807F61A0 -= 1.0;
            break;
        default:
            D_global_asm_807F61A0 -= 1.0;
            break;
    }
    if (D_global_asm_807F61A0 < 0.0) {
        D_global_asm_807F61A0 = 255.0f;
    }
}
