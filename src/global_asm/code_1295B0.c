#include <ultra64.h>
#include "functions.h"

typedef struct Struct80755690_unk4 Struct80755690_unk4;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    s8 unk7;
    s16 unk8;
} Struct80755690_unk4_unk14;

struct Struct80755690_unk4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u8 unkE;
    u8 unkF;
    s16 unk10;
    s16 unk12;
    Struct80755690_unk4_unk14 *unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    Struct80755690_unk4 *unk1C;
    s8 unk20;
    s8 unk21;
    s8 unk22;
    s8 unk23;
};

typedef struct {
    s16 unk0;
    s16 unk2;
    Struct80755690_unk4 *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Struct80755690;

typedef struct {
    s16 count;
    s16 unk2;
    EnemySpawner *firstSpawner;
} EnemySpawnerLocator;

typedef struct global_asm_struct_8 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} GlobalASMStruct8;

void func_global_asm_80728300(s16 *, FenceDataStruct *, SpawnerDataStruct *);
void func_global_asm_80726744(Actor *, EnemySpawner *);


// .data
Struct80755690 *D_global_asm_80755690 = 0x807FDC80; // TODO: Symbol
EnemySpawnerLocator* D_global_asm_80755694 = 0x807FDC88;

u8 D_global_asm_80755698[] = {
    0x02,
    0x05,
    0x00,
    0x04,
    0x00,
    0x04,
    0x00,
    0x09,
    0x07,
    0x00,
    0x00,
    0x06,
    0x06,
    0x06,
    0x02,
    0x06,
    0x00,
    0x04,
    0x0A,
    0x06,
    0x06,
    0x06,
    0x06,
    0x06,
    0x09,
    0x06,
    0x07,
    0x02,
    0x04,
    0x04,
    0x02,
    0x02,
    0x08,
    0x02,
    0x00,
    0x08,
    0x00,
    0x00,
    0x07,
    0x08,
    0x07,
    0x00,
    0x08,
    0x00,
    0x00,
    0x00,
    0x0A,
    0x00,
    0x08,
    0x00,
    0x00,
    0x03,
    0x03,
    0x0A,
    0x03,
    0x0A,
    0x03,
    0x07,
    0x00,
    0x00,
    0x05,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x05,
    0x06,
    0x0A,
    0x0A,
    0x00,
    0x00,
    0x0A,
    0x0A,
    0x09,
    0x08,
    0x08,
    0x08,
    0x03,
    0x03,
    0x06,
    0x00,
    0x09,
    0x04,
    0x00,
    0x05,
    0x05,
    0x03,
    0x03,
    0x03,
    0x02,
    0x00,
    0x02,
    0x00,
    0x02,
    0x02,
    0x0A,
    0x07,
    0x00,
    0x04,
    0x02,
    0x00,
    0x05,
    0x00,
    0x00,
    0x03,
    0x07,
    0x07,
    0x07,
    0x07,
    0x04,
    0x0A,
    0x02,
    0x00,
    0x00,
    0x00,
};

typedef struct {
    u16 modelIndex;
    u16 unk2;
} CSModelMap;

CSModelMap D_global_asm_8075570C[] = {
    {0x003E, 0x00A0},
    {0x0021, 0x0022},
    {0x0023, 0x003A},
    {0x0011, 0x0041},
    {0x0099, 0x000C},
    {0x001C, 0x003B},
    {0x003C, 0x0025},
    {0x0046, 0x0049},
    {0x003A, 0x0037},
    {0x0031, 0x001D},
    {0x0058, 0x0001},
    {0x000C, 0x0006},
    {0x0009, 0x0004},
    {0x0017, 0x0060},
    {0x0063, 0x0088},
    {0x005B, 0x0045},
    {0x0066, 0x0099},
    {0x0018, 0x0038},
    {0x0067, 0x00DA},
    {0x0013, 0x0012},
    {0x003D, 0x0027},
    {0x002D, 0x0014},
    {0x0068, 0x0069},
    {0x00E2, 0x0061},
    {0x00DC, 0x00DD},
    {0x00DE, 0x00DF},
    {0x00E3, 0x002C},
    {0x0070, 0x0071},
    {0x0072, 0x006B},
    {0x00EA, 0x00E9},
    {0x001A, 0x001B},
    {0x0044, 0x0080},
    {0x00EC, 0x00EB},
    {0x00C3, 0x0000},
};

void *D_global_asm_80755794[] = {
    &D_global_asm_8071FFA0,
    &D_global_asm_8071FF40,
};

s16 D_global_asm_8075579C = 0x112;

void func_global_asm_807248B0(Actor *arg0, f32 arg1) {
    LedgeInfo *temp_v0;

    arg0->animation_state->scale_x = arg1;
    arg0->animation_state->scale_y = arg1;
    arg0->animation_state->scale_z = arg1;
    temp_v0 = arg0->ledge_info_pointer;
    if (temp_v0 != NULL) {
        arg0->unk15E = (temp_v0->unkC * arg1) * 0.5;
    }
}

void func_global_asm_80724994(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 *sp24;
    Actor *sp20;

    sp24 = malloc(8);
    func_global_asm_8061134C(sp24);
    sp24[0] = arg1;
    sp24[1] = arg2;
    sp24[2] = arg3;
    sp24[3] = arg4;
    func_global_asm_8072E7DC(0xB, &sp20);
    func_global_asm_8067AB20(NULL, sp20, 0x01000000, arg0, sp24, 0);
}

s32 func_global_asm_80724A20(void) {
    s16 i;
    s32 found;

    found = FALSE;
    for (i = 0; !found && i < D_global_asm_807FBB70.unk254; i++) {
        if (D_global_asm_807FBB70.unk258[i] == 3) {
            found = TRUE;
            gCurrentActorPointer->control_state = D_global_asm_807FBB70.unk278[i]->unk2;
            gCurrentActorPointer->control_state_progress = 0;
        }
    }
    return found;
}

void func_global_asm_80724A9C(u8 arg0, u8 arg1, u8 arg2) {
    Struct80755690_unk4 *var_v0;
    s16 i;

    var_v0 = D_global_asm_80755690->unk4;
    for (i = 0; i < D_global_asm_80755690->unk0; i++) {
        if (var_v0->unk18 == arg0) {
            if (arg1 < var_v0->unk10) {
                if (arg2) {
                    var_v0->unk14[arg1].unk6 |= 0x80;
                    return;
                }
                var_v0->unk14[arg1].unk6 &= 0xFF7F;
            }
            break;
        }
        var_v0++;
    }
}

void func_global_asm_80724B5C(u8 arg0, u8 arg1, f32 *x, f32 *y, f32 *z) {
    Struct80755690_unk4 *var_v0;
    s16 i;

    var_v0 = D_global_asm_80755690->unk4;
    for (i = 0; i < D_global_asm_80755690->unk0; i++) {
        if (var_v0->unk18 == arg0) {
            if (arg1 < var_v0->unk10) {
                *x = var_v0->unk14[arg1].unk0;
                *y = var_v0->unk14[arg1].unk2;
                *z = var_v0->unk14[arg1].unk4;
            }
            break;
        }
        var_v0++;
    }
}

void func_global_asm_80724C2C(s16 arg0) {
    gCurrentActorPointer->y_rotation = \
    gCurrentActorPointer->unkEE = D_global_asm_807FBD6C->unkEE + 0x800 & 0xFFF;
    gCurrentActorPointer->unkB8 = arg0;
}

void func_global_asm_80724C78(void* arg0) {
    func_global_asm_80728300(arg0, D_global_asm_80755690, D_global_asm_80755694);
}

void func_global_asm_80724CA4(s16 arg0, s16 arg1) {
    AnimationStateUnk1C *temp_v0;
    gCurrentActorPointer->animation_state->unk1C = malloc(8 + (arg1 * 8U));
    func_global_asm_80611690(gCurrentActorPointer->animation_state->unk1C);
    temp_v0 = gCurrentActorPointer->animation_state->unk1C;
    temp_v0->unk0 = 0x7F;
    temp_v0->unk1 = arg0;
    temp_v0[arg1].unk0 = 0;
}

void func_global_asm_80724D28(s16 arg0, s16 arg1) {
    AnimationStateUnk24 *temp_v0;

    gCurrentActorPointer->animation_state->unk24 = malloc(arg1 * 0x10U + 0x10);
    func_global_asm_80611690(gCurrentActorPointer->animation_state->unk24);
    temp_v0 = gCurrentActorPointer->animation_state->unk24;
    temp_v0->unk0 = arg0;
    temp_v0->unk1 = arg0 + 1;
    temp_v0[arg1].unk0 = 0xFF;
}

void func_global_asm_80724DB0(s16 arg0, s16 arg1) {
    AnimationStateUnk20 *temp_v0;

    gCurrentActorPointer->animation_state->unk20 = malloc((arg1 * 0x10U) + 0x10);
    func_global_asm_80611690(gCurrentActorPointer->animation_state->unk20);
    temp_v0 = gCurrentActorPointer->animation_state->unk20;
    temp_v0->unk4 = 1.0f;
    temp_v0->unk8 = 1.0f;
    temp_v0->unkC = 1.0f;
    temp_v0->unk0 = arg0;
    temp_v0->unk1 = arg0;
    temp_v0[arg1].unk0 = 0xFF;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80724E48.s")

// Fiddly floats
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_807255A8.s")

u8 func_global_asm_80725B38(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return (arg0 >= arg2)
        && (arg4 >= arg0)
        && (arg1 >= arg3)
        && (arg5 >= arg1);
}

s32 func_global_asm_807255A8(s16, s16, s16, s16, s32, s32, s32, s32, void *, void *);

s32 func_global_asm_80725BA4(s16 x, s16 z, FenceStruct *arg2) {
    s32 var_v0;
    f32 sp68;
    f32 sp64;
    s16 i;
    u8 c0;
    u8 v0;
    s16 c1;

    c1 = 0;
    if (func_global_asm_80725B38(x, z, arg2->unk0, arg2->unk2, arg2->unk4, arg2->unk6)) {
        c0 = 0;
        for (i = 1; i < arg2->unk8; i++) {
            if ((i + 1) != arg2->unk8) {
                var_v0 = func_global_asm_807255A8(x, z, -0x8000, -0x8000, arg2->unkC[i].x, arg2->unkC[i].z, arg2->unkC[i + 1].x, arg2->unkC[i + 1].z, &sp68, &sp64);
            } else {
                var_v0 = func_global_asm_807255A8(x, z, -0x8000, -0x8000, arg2->unkC[i].x, arg2->unkC[i].z, arg2->unkC[1].x, arg2->unkC[1].z, &sp68, &sp64);
            }
            c1 += var_v0 != 0;
            if (var_v0 == 3) {
                c0++;
            }
        }
        if ((c0 != 0) && !(c0 & 1) && (c1 == c0)) {
            c1--;
        }
    }
    v0 = c1;
    return v0 & 1;
}

u8 func_global_asm_80725DC0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    func_global_asm_8061F2B8(arg4, 0.0f, arg5, arg0, 0.0f, arg1, arg2, 0.0f, arg3, &sp4C, &sp48, &sp44);
    return ((sp4C - arg4) * (sp4C - arg4) + (sp44 - arg5) * (sp44 - arg5)) < (arg6 * arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80725ED4.s")

s32 func_global_asm_80726164(Actor *actor, s16 x, s16 y, s16 z, FenceStruct *arg4) {
    s32 var_v0;
    f32 sp98;
    f32 sp94;
    f32 x0, y0, z0;
    u8 var_s3;
    u8 var_s5;
    s16 i;
    s16 var_s6;
    FenceAStruct *a;

    var_s6 = 0;
    var_s5 = 0;
    x0 = actor->x_position;
    y0 = actor->y_position + actor->unk15E;
    z0 = actor->z_position;
    for (i = 1; i < arg4->unk8; i++) {
        if ((i + 1) != arg4->unk8) {
            var_v0 = func_global_asm_807255A8(x, z, -0x8000, -0x8000, arg4->unkC[i].x, arg4->unkC[i].z, arg4->unkC[i + 1].x, arg4->unkC[i + 1].z, &sp98, &sp94);
        } else {
            var_v0 = func_global_asm_807255A8(x, z, -0x8000, -0x8000, arg4->unkC[i].x, arg4->unkC[i].z, arg4->unkC[1].x, arg4->unkC[1].z, &sp98, &sp94);
        }
        var_s6 += var_v0 != 0;
        if (var_v0 == 3) {
            var_s5++;
        }
    }
    if ((var_s5 != 0) && !(var_s5 & 1) && (var_s6 == var_s5)) {
        var_s6--;
    }
    var_s3 = TRUE;
    if (var_s6 & 1) {
        for (i = 0; var_s3 && i < arg4->unk10; i++) {
            a = &arg4->unk14[i];
            if (a->unk6 & 0x80) {
                continue;
            }
            if ((((a->unk6 & 0x7F) != 0) && ((a->unk6 & 0x7F) != 5))) {
                continue;
            }
            if (!func_global_asm_80725DC0(x0, z0, x, z, a->unk0, a->unk4, a->unk7)) {
                continue;
            }
            a = &arg4->unk14[i];
            if ((a->unk2 <= y0) && (y0 <= (a->unk8 + a->unk2))) {
                var_s3 = FALSE;
            }
        }
    } else {
        var_s3 = FALSE;
    }
    return var_s3;
}

// arg0 Actor, doable, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_807264B0.s")

void func_global_asm_807266E8(Actor *arg0, CharacterSpawner *arg1) {
    arg0->x_position = arg1->unk4;
    arg0->y_position = arg1->unk6;
    arg0->unk8C = arg1->unk6;
    arg0->z_position = arg1->unk8;
    arg0->y_rotation = arg1->unk2;
}

// Jumptable, references the cutscene model mapping table at D_global_asm_8075570C
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80726744.s")

u8 func_global_asm_80726D7C(u8 arg0) {
    return func_global_asm_80726DEC(arg0, 5) || func_global_asm_80726DEC(arg0, 6);
}

u8 func_global_asm_80726DC0(u8 arg0) {
    return func_global_asm_80726DEC(arg0, 7);
}

u8 func_global_asm_80726DEC(u8 arg0, u8 arg1) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (var_v1->init.spawn_trigger == arg0) {
            return (var_v1->spawn_state == arg1);
        }
        var_v1++;
    }
    return 0;
}

void func_global_asm_80726E60(u16 arg0, u8 arg1) {
    Actor *temp_v1;
    EnemySpawner *var_v0;
    s16 i;

    var_v0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (var_v0->spawn_state == 5) {
            temp_v1 = var_v0->tied_actor;
            if (temp_v1->interactable & arg0) {
                temp_v1->control_state = arg1;
            }
        }
        var_v0++;
    }
}

void func_global_asm_80726EE0(u8 arg0) {
    EnemySpawner *var_s0;
    s16 i;

    var_s0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++)  {
        if (!(var_s0->properties_bitfield & 0x80)) {
            if (var_s0->spawn_state == 5 && (var_s0->tied_actor->interactable & 2)) {
                func_global_asm_80679290(var_s0->tied_actor, 0, 8, 0, 0, 0, 1);
            } else if (var_s0->spawn_state == 6 && (var_s0->tied_actor->interactable & 2)) {
                var_s0->spawn_state = 7;
                var_s0->respawn_time = var_s0->init.respawn_timer_init * 0x1E;
                func_global_asm_8061CFCC(var_s0->tied_actor);
                deleteActor(var_s0->tied_actor);
            }
            switch (arg0) {
                case 0:
                case 1:
                    var_s0->properties_bitfield |= 2;
                    break;
                case 2:
                    var_s0->properties_bitfield &= ~2;
                    break;
                default:
                    break;
            }
        }
        var_s0++;
    }
}

void func_global_asm_8072707C(s16 spawn_trigger, u8 arg1, u16 arg2) {
    Actor *actor = getSpawnerTiedActor(spawn_trigger, arg2);
    if (actor) {
        actor->control_state = arg1;
        actor->control_state_progress = 0;
    }
}

Actor *getSpawnerTiedActor(s16 spawn_trigger, u16 arg1) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (spawn_trigger == var_v1->init.spawn_trigger) {
            if (var_v1->spawn_state == 5) {
                var_v1->properties_bitfield |= arg1;
                return var_v1->tied_actor;
            }
            if ((var_v1->spawn_state == 6) && (arg1 & 0x400)) {
                func_global_asm_80678428(var_v1->tied_actor);
                var_v1->spawn_state = 5;
                return var_v1->tied_actor;
            }
        }
        var_v1++;
    }
    return NULL;
}

u8 func_global_asm_80727194(Actor *arg0) {
    s16 i;
    EnemySpawner *var_v1;

    var_v1 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (arg0 == var_v1->tied_actor) {
            if (var_v1->spawn_state == 5) {
                return var_v1->init.spawn_trigger;
            }
        }
        var_v1++;
    }
    return 0;
}

Actor *func_global_asm_807271F4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s16 i;
    Struct8075EB80 *temp_v0;
    EnemySpawner *var_s0;

    var_s0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        if (arg0 == var_s0->init.spawn_trigger) {
            if (var_s0->spawn_state != 5) {
                temp_v0 = &D_global_asm_8075EB80[var_s0->alternative_enemy_spawn];
                if (spawnActor(temp_v0->unk0, temp_v0->unk2) != 0) {
                    var_s0->properties_bitfield |= 4;
                    func_global_asm_80726744(gLastSpawnedActor, var_s0);
                    if (arg1 != 0) {
                        gLastSpawnedActor->x_position = arg1;
                        gLastSpawnedActor->y_position = arg2;
                        gLastSpawnedActor->z_position = arg3;
                        gLastSpawnedActor->unkEE = arg4;
                        gLastSpawnedActor->y_rotation = arg4;
                    }
                    gLastSpawnedActor->unkB8 = arg5;
                    gLastSpawnedActor->y_velocity = arg6;
                    gLastSpawnedActor->unk6A = 0;
                    return gLastSpawnedActor;
                }
            }
        }
        var_s0++;
    }
    return NULL;
}

void func_global_asm_807273A8(s16 arg0, u8 arg1) {
    u8 temp_t0;
    s16 sp34;

    temp_t0 = D_global_asm_807FDC98->unk20[arg1].unk0;
    sp34 = (func_global_asm_80665AE4(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, D_global_asm_807FDCA0->unk14[temp_t0].unk0, D_global_asm_807FDCA0->unk14[temp_t0].unk4) * 4096.0f) / 360.0f;
    if (func_global_asm_807271F4(arg0, D_global_asm_807FDCA0->unk14[temp_t0].unk0, D_global_asm_807FDCA0->unk14[temp_t0].unk2, D_global_asm_807FDCA0->unk14[temp_t0].unk4, sp34, RandClamp(100) + 0x64, RandClamp(100) + 0xC8) != 0) {
        gLastSpawnedActor->control_state = 0x17;
        gLastSpawnedActor->control_state_progress = 0;
    }
}

void func_global_asm_8072752C(s16 arg0, s16 x1, s16 y1, s16 z1, s16 x2, s16 y2, s16 z2, s16 arg7, s16 arg8) {
    s16 sp46;
    f32 sp40;
    s32 pad[2];

    sp46 = func_global_asm_80665DE0(x2, z2, x1, z1);
    sp40 = sqrtf(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) + ((z2 - z1) * (z2 - z1)));
    if (func_global_asm_807271F4(arg0, x1, y1, z1, sp46, sqrtf(((x2 - x1) * (x2 - x1)) + ((z2 - z1) * (z2 - z1))) / (sp40 / arg7), arg8)) {
        gLastSpawnedActor->control_state = 0x17;
        gLastSpawnedActor->control_state_progress = 0;
    }
}

void func_global_asm_80727678(void) {
    s32 pad;
    s16 i, j;
    EnemySpawner *var_s0;
    Struct807FBB70_unk278 *temp_t0;

    var_s0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        for (j = 0; j < D_global_asm_807FBB70.unk254; j++) {
            temp_t0 = D_global_asm_807FBB70.unk278[j];
            if (temp_t0->unk0 != var_s0->init.spawn_trigger) {
                continue;
            }
            switch (D_global_asm_807FBB70.unk258[j]) {
            case 1:
                if (
                    (var_s0->spawn_state == 0) && 
                    func_global_asm_807317FC(current_map, var_s0->init.spawn_trigger) && 
                    spawnActor(D_global_asm_8075EB80[var_s0->alternative_enemy_spawn].unk0, D_global_asm_8075EB80[var_s0->alternative_enemy_spawn].unk2)) {
                    func_global_asm_80726744(gLastSpawnedActor, var_s0);
                } else if ((var_s0->spawn_state == 3) && 
                    func_global_asm_807317FC(current_map, var_s0->init.spawn_trigger)) {
                    if (spawnActor(D_global_asm_8075EB80[var_s0->alternative_enemy_spawn].unk0, D_global_asm_8075EB80[var_s0->alternative_enemy_spawn].unk2)) {
                        func_global_asm_80726744(gLastSpawnedActor, var_s0);
                        gLastSpawnedActor->control_state = 0x36;
                    }
                }
                break;
            case 2:
                if (var_s0->spawn_state == 7) {
                    var_s0->spawn_state = var_s0->init.something_spawn_state;
                    break;
                }
                break;
            case 3:
            case 4:
                if (var_s0->spawn_state == 5) {
                    func_global_asm_8067AB20(gCurrentActorPointer, var_s0->tied_actor, 0x01000000, D_global_asm_807FBB70.unk258[j], temp_t0, 0U);
                    break;
                }
                break;
            }
        }
        var_s0++;
    }
}

void func_global_asm_807278C0(EnemySpawner *arg0) {
    u8 temp_v0;

    if (current_map == MAP_FUNGI && extra_player_info_pointer->unk1F0 & 0x100000 && D_global_asm_80755698[arg0->init.enemy_value] != 0xA) {
        switch (arg0->init.enemy_value) {
            case 28: // TODO: Enemy type enum
                arg0->alternative_enemy_spawn = 0x63;
                return;
            case 9: // TODO: Enemy type enum
                arg0->alternative_enemy_spawn = 0x54;
                return;
            case 44: // TODO: Enemy type enum
                arg0->alternative_enemy_spawn = 0x67;
                return;
        }
    } else {
        arg0->alternative_enemy_spawn = arg0->init.enemy_value;
    }
}

u8 func_global_asm_8072818C(EnemySpawner *, s32);

void func_global_asm_80727958(void) {
    Actor *temp_a0;
    Actor *temp_a0_2;
    Actor *temp_a0_3;
    Actor *temp_a0_4;
    Actor *temp_a0_5;
    Actor *temp_a0_6;
    Actor *temp_v0_5;
    EnemyMovementBox *temp_v0_4;
    EnemySpawner *var_s0;
    Struct8075EB80 *temp_v0_2;
    Struct8075EB80 *temp_v0_3;
    f32 dz;
    f32 dx;
    s16 temp_v0;
    s16 j;
    s16 i;
    u8 temp_a1;
    s32 temp_f16;
    s32 temp_lo;
    s32 temp_t4;
    s32 var_s1;
    s32 min_dist;
    s32 var_v0;
    u8 temp_v0_6;
    u8 temp_v0_7;
    PlayerAdditionalActorData *PaaD;

    var_s0 = D_global_asm_80755694->firstSpawner;
    for (i = 0; i < D_global_asm_80755694->count; i++) {
        temp_a1 = (var_s0->spawn_state > 4) && (var_s0->spawn_state < 7);
        if (temp_a1 != 0) {
            D_global_asm_807FDC90 = var_s0->tied_actor->additional_actor_data;
        }
        var_s1 = D_global_asm_8075EB80[var_s0->alternative_enemy_spawn].unkE * 100;
        var_s1 = var_s1 * var_s1;
        if (temp_a1 != 0) {
            var_s0->chunk = var_s0->tied_actor->unk12C;
        }
        if ((var_s1 == 0) || (var_s0->properties_bitfield & 4) || (D_global_asm_807FBB64 & 0x100)) {
            var_s1 = 0x7FFFFFFF;
        }
        if ((temp_a1 != 0) && var_s0->tied_actor->control_state == 0x3B) {
            func_global_asm_8061CFCC(var_s0->tied_actor);
            deleteActor(var_s0->tied_actor);
            var_s0->spawn_state = 0;
        } else if ((temp_a1 != 0) && var_s0->tied_actor->control_state == 0x3C) {
            func_global_asm_8061CFCC(var_s0->tied_actor);
            deleteActor(var_s0->tied_actor);
            var_s0->spawn_state = var_s0->init.something_spawn_state;
            var_s0->properties_bitfield &= 0xFFFB;
        } else {
            if ((var_s0->spawn_state == 7) && (var_s0->respawn_time != 0)) {
                if (!(var_s0->properties_bitfield & 2)) {
                    var_s0->respawn_time--;
                    if (var_s0->respawn_time == 0) {
                        var_s0->counter += 1;
                        var_s0->spawn_state = var_s0->init.something_spawn_state;
                        var_s0->chunk = func_global_asm_806531B8(var_s0->init.x_pos, var_s0->init.y_pos, var_s0->init.z_pos, 0);
                        func_global_asm_807278C0(var_s0);
                        temp_v0_2 = &D_global_asm_8075EB80[var_s0->alternative_enemy_spawn];
                        if (spawnActor(temp_v0_2->unk0, temp_v0_2->unk2)) {
                            func_global_asm_80726744(gLastSpawnedActor, var_s0);
                            gLastSpawnedActor->control_state = 0x36;
                            var_s0->properties_bitfield |= 1;
                        }
                    }
                }
            } else if (var_s0->spawn_state == 2) {
                if ((func_global_asm_80727F20(var_s0, var_s1)) && (func_global_asm_807317FC(current_map, var_s0->init.spawn_trigger))) {
                    func_global_asm_807278C0(var_s0);
                    temp_v0_3 = &D_global_asm_8075EB80[var_s0->alternative_enemy_spawn];
                    if (spawnActor(temp_v0_3->unk0, temp_v0_3->unk2)) {
                        func_global_asm_80726744(gLastSpawnedActor, var_s0);
                    }
                }
            } else if ((temp_a1 != 0) && var_s0->tied_actor->control_state == 0x40) {
                temp_v0_4 = var_s0->movement_box_pointer;
                var_s0->spawn_state = 7;
                var_s0->respawn_time = var_s0->init.respawn_timer_init * 30;
                if (temp_v0_4->unk1C == var_s0->tied_actor) {
                    temp_v0_4->unk1C = 0;
                }
                func_global_asm_8061CFCC(var_s0->tied_actor);
                deleteActor(var_s0->tied_actor);
            } else if (temp_a1 != 0) {
                min_dist = 999999;
                temp_v0_5 = D_global_asm_807FDC90->unk4;
                if ((temp_v0_5->interactable & 1) && (temp_v0_5->control_state == 0x67)) {
                    temp_a0_4 = var_s0->tied_actor;
                    if ((temp_a0_4->interactable & 2) && (var_s0->spawn_state == 5)) {
                        temp_v0_6 = temp_a0_4->control_state;
                        if ((temp_v0_6 != 0x16) && (temp_v0_6 != 0x37) && !(var_s0->properties_bitfield & 0x40)) {
                            temp_a0_4->control_state = 0x16;
                            var_s0->tied_actor->control_state_progress = 0;
                        }
                    }
                }
                if (cc_number_of_players > 1) {
                    for (j = 0; j < cc_number_of_players; j++) {
                        PaaD = character_change_array->playerPointer->PaaD;
                        dz = gCurrentActorPointer->z_position - character_change_array[j].playerPointer->z_position;
                        dx = gCurrentActorPointer->x_position - character_change_array[j].playerPointer->x_position;
                        temp_f16 = SQ(dz) + SQ(dx);
                        if ((temp_f16 < min_dist) || (PaaD->unkD4 != 0)) {
                            min_dist = temp_f16;
                            D_global_asm_807FDC90->unk4 = character_change_array[j].playerPointer;
                        }

                    }
                }
                if (var_s0->spawn_state == 6) {
                    if (func_global_asm_8072818C(var_s0, var_s1) != 0) {
                        deleteActor(var_s0->tied_actor);
                        var_s0->spawn_state = var_s0->init.something_spawn_state;
                    } else if (func_global_asm_80728004(var_s0, var_s1) != 0) {
                        func_global_asm_80678428(var_s0->tied_actor);
                        var_s0->spawn_state = 5;
                        var_s0->properties_bitfield |= 0x8000;
                    }
                } else if ((var_s0->spawn_state == 5) && (func_global_asm_807280C8(var_s0, var_s1) != 0)) {
                    if ((var_s0->tied_actor->control_state != 0x16) && (var_s0->tied_actor->control_state != 0x37)) {
                        if (var_s0->tied_actor->unk58 == ACTOR_FAIRY) {
                            func_global_asm_80602B60(0x42, 0U);
                        }
                        func_global_asm_80605314(var_s0->tied_actor, 0U);
                        func_global_asm_80605314(var_s0->tied_actor, 1U);
                        func_global_asm_80678458(var_s0->tied_actor);
                        var_s0->spawn_state = 6;
                        D_global_asm_807FDC90->unk18 = 0;
                    }
                }
            }
        }
        var_s0++;
    }
}

u8 func_global_asm_80727F20(EnemyInfo *arg0, s32 arg1) {
    return (((character_change_array[0].look_at_eye_x - arg0->x_position) * (character_change_array[0].look_at_eye_x - arg0->x_position))
        + ((character_change_array[0].look_at_eye_y - arg0->y_position) * (character_change_array[0].look_at_eye_y - arg0->y_position))
        + ((character_change_array[0].look_at_eye_z - arg0->z_position) * (character_change_array[0].look_at_eye_z - arg0->z_position)) < arg1)
        && ((D_global_asm_80755698[arg0->unk44] == 6)
            || (arg0->unk46 & 0x20)
            || func_global_asm_80652F24(0, arg0->unk40));
}

u8 func_global_asm_80728004(EnemyInfo *arg0, s32 arg1) {
    return (arg1 > (((character_change_array[0].look_at_eye_x - arg0->unk18->x_position) * (character_change_array[0].look_at_eye_x - arg0->unk18->x_position))
        + ((character_change_array[0].look_at_eye_y - arg0->unk18->y_position) * (character_change_array[0].look_at_eye_y - arg0->unk18->y_position))
        + ((character_change_array[0].look_at_eye_z - arg0->unk18->z_position) * (character_change_array[0].look_at_eye_z - arg0->unk18->z_position))))
        && ((arg0->unk18->interactable & 0x40)
            || (arg0->unk46 & 0x20)
            || func_global_asm_80652F24(0, arg0->unk40));
}

u8 func_global_asm_807280C8(EnemyInfo *arg0, s32 arg1) {
    return (arg1 < (((character_change_array[0].look_at_eye_x - arg0->unk18->x_position) * (character_change_array[0].look_at_eye_x - arg0->unk18->x_position))
        + ((character_change_array[0].look_at_eye_y - arg0->unk18->y_position) * (character_change_array[0].look_at_eye_y - arg0->unk18->y_position))
        + ((character_change_array[0].look_at_eye_z - arg0->unk18->z_position) * (character_change_array[0].look_at_eye_z - arg0->unk18->z_position))))
        || (!(arg0->unk18->interactable & 0x40)
            && !(arg0->unk46 & 0x20)
            && !func_global_asm_80652F24(0, arg0->unk40));
}

u8 func_global_asm_8072818C(EnemySpawner *arg0, s32 arg1) {
    s32 temp_f0;

    temp_f0 = sqrtf(arg1) * 1.5;
    return ((arg0->tied_actor->interactable & 2) && !(arg0->properties_bitfield & 0x20) && arg0->init.something_spawn_state == 2)
        && (SQ(temp_f0)) < 
            (SQ(character_change_array[0].look_at_eye_x - arg0->tied_actor->x_position))
            + (SQ(character_change_array[0].look_at_eye_y - arg0->tied_actor->y_position))
            + (SQ(character_change_array[0].look_at_eye_z - arg0->tied_actor->z_position));
}

void func_global_asm_8072827C(Struct80755690_unk4 *arg0) {
    s16 i;
    Struct80755690_unk4 *var_v0;

    var_v0 = D_global_asm_80755690->unk4;
    for (i = 0; i < D_global_asm_80755690->unk0; i++) {
        var_v0->unk1C = 0;
        var_v0->unk20 = 0;
        if (var_v0->unk18 == arg0->unkE) {
            arg0->unk1C = var_v0;
            break;
        } else {
            var_v0++;
        }
    }
    if (arg0->unk1C == NULL) {
        arg0->unk1C = D_global_asm_80755690->unk4;
    }
}

// close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_80728300.s")

/*
// Enemy spawner loader
void func_global_asm_80728300(s16 *file, FenceDataStruct *fence, SpawnerDataStruct *spawner) {
    s16 j;
    s16 var_s3;
    s16 i;
    s32 var_s4;
    s16 fence_count;
    s16 fence_6_count;
    s16 fence_a_count;
    s16 spawner_count;
    s16 *file_copy;
    FenceStruct *var_s0;
    EnemySpawner *var_s0_2;
    SpawnerData_unk20 *var_s0_3;
    SpawnerFileData *file_spawner;
    FenceAStruct *file_fence_a;
    Fence6Struct *file_fence_6;
    SpawnerData_unk20 *file_spawner_sub;

    if (file) {
        fence_count = fence->count = *file++;
    } else {
        fence_count = fence->count = 0;
    }
    file_copy = file;
    fence->data = var_s0 = malloc(fence_count * sizeof(FenceStruct));
    for (i = 0; i < fence->count; i++) {
        var_s4 = TRUE;
        if (i) var_s0++;
        var_s0->unk0 = 0x7FFF;
        var_s0->unk4 = -0x8000;
        var_s0->unk2 = var_s0->unk0;
        var_s0->unk6 = var_s0->unk4;
        if (file_copy) {
            fence_6_count = var_s0->unk8 = *file_copy++;
        } else {
            fence_6_count = var_s0->unk8 = 0;
        }
        file_fence_6 = file_copy;
        if (fence_6_count != 0) {
            var_s0->unkC = malloc(fence_6_count * sizeof(Fence6Struct));
        }
        for (j = 0; j < fence_6_count; j++) {
            var_s0->unkC[j] = *file_fence_6++;
            var_s0->unk0 = MIN(var_s0->unk0, var_s0->unkC[j].x);
            var_s0->unk2 = MIN(var_s0->unk2, var_s0->unkC[j].z);
            var_s0->unk4 = MAX(var_s0->unk4, var_s0->unkC[j].x);
            var_s0->unk6 = MAX(var_s0->unk6, var_s0->unkC[j].z);
            if (j == 0) {
                var_s3 = var_s0->unkC[j].y;
            } else {
                if (var_s3 != var_s0->unkC[j].y) {
                    var_s4 = FALSE;
                }
                var_s3 = var_s0->unkC[j].y;
            }
        }
        file_copy = file_fence_6;
        if (file_copy) {
            fence_a_count = var_s0->unk10 = *file_copy++;
        } else {
            fence_a_count = var_s0->unk10 = 0;
        }
        file_fence_a = file_copy;
        if (fence_a_count != 0) {
            var_s0->unk14 = malloc(fence_a_count * sizeof(FenceAStruct));
        }
        for (j = 0; j < fence_a_count; j++) {
            var_s0->unk14[j] = *file_fence_a++;
        }
        file_copy = file_fence_a;
        if (file_copy) {
            var_s0->unk18 = *file_copy++;
            var_s0->unk19 = *file_copy++;
            if (var_s4) {
                var_s0->unk19 = TRUE;
            }
        }
    }
    if (file_copy) {
        spawner_count = spawner->count = *file_copy++;
    } else {
        spawner_count = spawner->count = 0;
    }
    spawner->data = malloc(spawner_count * sizeof(SpawnerData));
    func_global_asm_80611690(spawner->data);
    var_s0_2 = spawner->data;
    for (i = 0; i < spawner->count; i++) {
        if (i) {
            var_s0_2++;
        }
        file_spawner = file_copy;
        var_s0_2->init = *file_spawner++;
        file_spawner_sub = file_spawner;
        var_s0_2->spawn_state = var_s0_2->init.unk12;
        var_s0_2->alt_enemy_spawn = var_s0_2->init.enemy_value;
        var_s0_2->tied_actor = 0;
        var_s0_2->unk46 = 0;
        var_s0_2->respawn_timer = 0;
        var_s0_2->counter = 0;
        var_s0_2->unk3C = 0.0f;
        var_s0_2->chunk = func_global_asm_806531B8(var_s0_2->init.x, var_s0_2->init.y, var_s0_2->init.z, 0);
        var_s0_2->unk20 = malloc(var_s0_2->init.extra_data_count * sizeof(SpawnerData_unk20));
        for (j = 0; j < var_s0_2->init.extra_data_count; j++) {
            var_s0_3 = &var_s0_2->unk20[j];
            var_s0_3->unk0 = file_spawner_sub->unk0;
            var_s0_3->unk1 = file_spawner_sub->unk1;
            file_spawner_sub++;
        }
        file_copy = file_spawner_sub;
        func_global_asm_8072827C(var_s0_2);
    }
}
*/

u8 func_global_asm_8072881C(u8 arg0, u32 *arg1) {
    u8 phi_v1 = FALSE;
    if ((arg0 & 0x80)
        || (*arg1 + 50 < object_timer
            && (RandChance(0.04))
            && !func_global_asm_80688540(gCurrentActorPointer, arg0))) {
        arg0 &= 0x7F;
        func_global_asm_80688370(gCurrentActorPointer, arg0, 1.0f);
        func_global_asm_806883C8(gCurrentActorPointer, arg0, 1);
        func_global_asm_8068839C(gCurrentActorPointer, arg0, 0);
        func_global_asm_806884B8(gCurrentActorPointer, arg0, 3);
        func_global_asm_80688514(gCurrentActorPointer, arg0);
        func_global_asm_806883F4(gCurrentActorPointer, arg0, 0, 0);
        func_global_asm_8068842C(gCurrentActorPointer, arg0, 2);
        *arg1 = object_timer;
        phi_v1 = TRUE;
    }
    return phi_v1;
}

void func_global_asm_80728950(u8 arg0) {
    func_global_asm_8068842C(gCurrentActorPointer, arg0, 1);
    func_global_asm_80688460(gCurrentActorPointer, arg0, 1);
    func_global_asm_806883F4(gCurrentActorPointer, arg0, 2, 0);
}

void func_global_asm_807289B0(u8 arg0, u8 arg1) {
    func_global_asm_806883F4(gCurrentActorPointer, arg0, arg1, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_1295B0/func_global_asm_807289E8.s")

void func_global_asm_80729AA4(u8 spawn_trigger) {
    Actor *actor = getSpawnerTiedActor(spawn_trigger, 0);
    if (!actor) {
        actor = gPlayerPointer;
    }
    actor->unk6A |= 0x100;
}
