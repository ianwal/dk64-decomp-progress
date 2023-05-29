#include <ultra64.h>
#include "functions.h"


typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unkC;
    s32 unk8;
    s32 unk10;
    s32 unk14;
    s32 unk1C;
    s32 unk18;
} Struct807500B4;

extern Struct807500B4 D_807500B4; // TODO: Array?
extern Struct807500B4 D_807500D4; // TODO: D_807500D4[1]?

void func_80631F58(s32, void *, void **);
s16 func_806531B8(f32, f32, f32, s16);
void func_8066B424(void);
u16 func_80688C84(u16);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Struct80689250;

ActorSpawner *func_80689250(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5, void *arg6, u8 arg7, s32 arg8, s16 arg9);

typedef struct {
    s16 unk0;
    s16 unk2;
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
} GlobalASMStruct_8074E8B0;

extern f64 D_80759C80;
extern GlobalASMStruct_8074E8B0 D_8074E8B0[];

void func_80689710(ActorSpawner *arg0, u8 arg1);
f32 func_80689DD4(f32, f32, f32);
u8 func_80689F80(ActorSpawner*);
u8 func_80689FEC(ActorSpawner *spawner);

extern u8 D_807500B0;
extern u16 D_807FC408[];
extern s16 D_807FC5D0[];
extern s16 D_807FC5F0[];
extern u8 D_807FC610;
extern u8 D_807FC611;

// TODO: Use proper actor spawner struct
typedef struct global_asm_struct_18 {
    u8 pad0[0x32 - 0x0];
    s16 unk32;
    s32 unk34;
} GlobalASMStruct18;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_806886E0.s")

/*
extern f64 D_80759BB0;
extern s16 D_8076A0AA;
extern ? D_8076A160; // TODO: Define this struct array
extern s32 D_807F6010;
extern s32 D_807F6C28;

void func_806886E0(s32 arg0, s32 arg1, u8 arg2) {
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    u16 sp4E;
    f64 temp_f20;
    f64 var_f10;
    f64 var_f18;
    f64 var_f6;
    s16 var_s1_2;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    u8 temp_t3;
    u8 temp_t4;
    u8 temp_t5;
    void *temp_v0_2;
    void *var_s0_3;

    var_s0 = arg0;
    temp_s2 = arg1 & 0xFF;
    var_s1 = 0;
    func_80688A6C();
    temp_v0 = func_80600080(current_map);
    sp54 = temp_v0;
    if (temp_v0 == -1) {
        switch (temp_s2) {
            case 0:
                D_807F6010 = var_s0;
                sp4E = func_80631D8C(D_8076A0AB);
                var_s1 = 1;
                break;
            case 1:
                var_s0 = D_807F6010;
                break;
        }
    } else {
        D_807F6010 = var_s0;
        var_s0 = *(&D_8076A178 + (temp_v0 * 0xC0));
    }
    func_80631F58(var_s0, &sp5C, &sp58);
    if (arg2 != 0) {
        var_s0_2 = 0;
    } else {
        var_s0_2 = func_806C7B34();
    }
    func_80632084(sp5C, var_s0_2, var_s1 & 0xFF, sp4E, getLevelIndex(D_8076A0AB, 1));
    func_8063DBD8(D_8076A0AA);
    func_80688FC0(sp58);
    if (sp54 != -1) {
        temp_v0_2 = (sp54 * 0xC0) + &D_8076A160;
        temp_a0 = temp_v0_2->unk20;
        if (temp_a0 != 0) {
            func_8063BF34(temp_a0, temp_v0_2->unk1C);
        }
        var_s1_2 = 0;
        if (D_807F6C28 > 0) {
            temp_f20 = D_80759BB0;
            var_s0_3 = (sp54 * 0xC0) + &D_8076A160;
            do {
                var_f6 = var_s0_3->unk24;
                var_f18 = var_s0_3->unk25;
                var_f10 = var_s0_3->unk26;
                func_80659670(var_f6 / temp_f20, var_f18 / temp_f20, var_f10 / temp_f20, var_s1_2);
                var_s1_2 += 1;
                var_s0_3 += 3;
            } while (var_s1_2 < D_807F6C28);
        }
    }
}
*/

void func_80688940(void) {
    s32 actorIndex;
    s32 numActors;
    s32 mapIndex;
    s32 sp60;
    s32 *sp5C;
    s32 setup;
    u16 phi_s3;
    GlobalASMStruct18 *phi_s1;

    phi_s3 = 0;
    if (!D_807500B0) {
        D_807500B0 = 1;
        for (mapIndex = 0; mapIndex < 0xDD; mapIndex++) {
            D_807FC408[mapIndex] = phi_s3;
            setup = getPointerTableFile(9, mapIndex, 1, 1);
            if (setup) {
                func_80631F58(setup, &sp60, &sp5C);
                numActors = *sp5C;
                phi_s1 = &sp5C[1];
                for (actorIndex = 0; actorIndex < numActors; actorIndex++) {
                    phi_s3 += func_80688C84(phi_s1[actorIndex].unk32 + 0x10);
                }
                func_8066B424();
                func_8066B434(setup, 0x168, 0x34);
            }
        }
    }
}

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
} GlobalASMStruct79;

extern GlobalASMStruct79 *D_807FC5C4;
extern u8 D_807FC5C8;

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80688A6C.s")

// TODO: What struct is this?
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
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
} Struct80688A6C;

/*
// TODO: Very close, have another look at m2c output for the branches
void func_80688A6C(void) {
    Struct80688A6C *var_s0;
    Struct80688A6C *var_s5;
    s32 temp_v0_2;
    s32 i;
    s32 var_s2;
    s32 sp50;
    void *temp_v0;
    s32 sp48;
    s32 *sp44;
    s32 var_s6;

    temp_v0 = getPointerTableFile(9, current_map, 1, 1);
    D_807FC5C8 = 0;
    if (temp_v0 != NULL) {
        func_80631F58(temp_v0, &sp48, &sp44);
        var_s6 = *sp44;
        var_s5 = sp44 + 1;
    } else {
        var_s6 = 0;
        var_s5 = sp50;
    }
    for (i = 0; i < var_s6; i++) {
        if (func_80688C84((var_s5[i].unk32 + 0x10)) != 0) {
            D_807FC5C8 += 1;
        }
    }
    if (D_807FC5C8 == 0) {
        D_807FC5C4 = NULL;
    } else {
        if (D_807FC5C8 != 0) {
            D_807FC5C4 = malloc(D_807FC5C8 * 4);
            D_807FC5C8 = 0;
            var_s2 = 0;
            for (i = 0; i < var_s6; i++) {
                temp_v0_2 = func_80688C84((var_s5[i].unk32 + 0x10));
                if (temp_v0_2 != 0) {
                    D_807FC5C4[D_807FC5C8].unk0 = var_s5[i].unk34;
                    D_807FC5C4[D_807FC5C8].unk2 = D_807FC408[current_map] + var_s2 + 0x26B;
                    var_s2 += temp_v0_2;
                    D_807FC5C8 += 1;
                }
            }
            func_8066B424();
            func_8066B434(temp_v0, 0x1AA, 0x34);
        }
    }
}
*/

s16 func_80688C30(u16 arg0) {
    s32 i;

    for (i = 0; i < D_807FC5C8; i++) {
        if (arg0 == D_807FC5C4[i].unk0) {
            return D_807FC5C4[i].unk2;
        }
    }
    return -1;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80688C84.s")

/*
extern void (*D_80759BB8[])();

u16 func_80688C84(u16 arg0) {
    if (((arg0) - 0x5B) < 0x31U) {
        D_80759BB8[arg0]();
        return 1;
    }
    return 0;
}
*/

typedef struct {
    f32 unk0[8];
} A124_80688CC4;

void func_80688CC4(Actor *arg0, s16 arg1, f32 arg2) {
    if (arg1 < 8) {
        ((A124_80688CC4*)arg0->unk124)->unk0[arg1] = arg2;
    }
}

typedef struct {
    s32 unk0[8];
} A124_80688CF4;

void func_80688CF4(Actor *arg0, s16 arg1, s32 arg2) {
    if (arg1 < 8) {
        ((A124_80688CF4*)arg0->unk124)->unk0[arg1] = arg2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80688D20.s")

// TODO: Any way to clean this up?
s32 func_80688E08(void) {
    s32 found;
    s16 search = 0;
    ActorSpawner *spawner;

    do {
        found = FALSE;
        spawner = actor_spawner_pointer;
        while (spawner && !found) {
            if (search == spawner->id) {
                found = TRUE;
            }
            spawner = spawner->next_spawner;
        }
        if (found) {
            search++;
        }
    } while (found);

    return search;
}

// getSpawnerID(Actor*)
s16 func_80688E68(Actor *arg0) {
    ActorSpawner *spawner = actor_spawner_pointer;
    while (spawner) {
        if (arg0 == spawner->tied_actor) {
            return spawner->id;
        }
        spawner = spawner->next_spawner;
    }
    return 0;
}

// getActor(spawnerID)
Actor *func_80688EA4(s16 id) {
    ActorSpawner *spawner = actor_spawner_pointer;
    while (spawner) {
        if (id == spawner->id) {
            return spawner->tied_actor;
        }
        spawner = spawner->next_spawner;
    }
}

void func_80688EE4(s16 id, f32 x, f32 y, f32 z) {
    ActorSpawner *spawner = actor_spawner_pointer;
    while (spawner) {
        if (id == spawner->id) {
            spawner->x_position = x;
            spawner->y_position = y;
            spawner->z_position = z;
            spawner->unk10 = x;
            spawner->unk14 = y;
            spawner->unk18 = z;
            spawner->unk4A = func_806531B8(x, y, z, 0);
            return;
        }
        spawner = spawner->next_spawner;
    }
}

void func_80688F74(Actor *arg0, f32 x, f32 y, f32 z) {
    ActorSpawner *spawner = actor_spawner_pointer;
    while (spawner) {
        if (arg0 == spawner->tied_actor) {
            spawner->x_position = x;
            spawner->y_position = y;
            spawner->z_position = z;
            return;
        }
        spawner = spawner->next_spawner;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80688FC0.s")

void func_80689064(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5) {
    Struct807500B4 sp38 = D_807500B4;
    func_80689250(arg0, arg1, arg2, arg3, arg4, arg5, &sp38, 0, 0, func_80688E08());
}

void func_80689114(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5, s32 arg6) {
    Struct807500B4 sp38 = D_807500D4;
    func_80689250(arg0 - 0x10, arg1, arg2, arg3, arg4, arg5, &sp38, 1, arg6, func_80688E08());
}

void func_806891D8(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5, s32 arg6, Struct807500B4 *arg7) {
    func_80689250(arg0 - 0x10, arg1, arg2, arg3, arg4, arg5, arg7, 1, arg6, func_80688E08());
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80689250.s")

/*
// TODO: Close
ActorSpawner *func_80689250(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, f32 arg5, void *arg6, u8 arg7, s32 arg8, s16 arg9) {
    ActorSpawner *sp2C;
    ActorSpawner *temp_v0;
    ActorSpawner *var_v1;
    f32 temp_f0;
    f32 temp_f16;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_v0;
    Struct80689250 *var_a0;

    var_a1 = 0;
    var_v0 = FALSE;

    while ((var_v0 == FALSE) && (var_a1 < 0x80)) {
        if ((arg0 + 0x10) == D_8074E8B0[var_a1].unk0) {
            var_v0 = TRUE;
        } else {
            var_a1++;
        }
    }
    temp_v0 = malloc(0x6C);
    temp_v0->actor_type = arg0;
    temp_v0->z_position = arg3;
    temp_v0->unk18 = arg3;
    temp_v0->x_position = arg1;
    temp_v0->unk10 = arg1;
    temp_v0->y_position = arg2;
    temp_v0->unk14 = arg2;
    temp_v0->id = arg9;
    temp_v0->y_rotation = arg4;
    temp_v0->tied_actor = NULL;
    temp_v0->previous_spawner = NULL;
    temp_v0->unk48 = 0;
    temp_v0->unk20 = arg5;
    temp_v0->unk5C = D_8074E8B0[var_a1].unkC;
    temp_v0->drawing_code = D_8074E8B0[var_a1].unk10;
    temp_v0->unk58 = D_8074E8B0[var_a1].unk2;
    sp2C = temp_v0;
    var_a1_2 = 0;
    sp2C->unk4A = func_806531B8(arg1, arg2, arg3, 0);
    var_v1 = sp2C;
    sp2C->unk4C = arg7;
    sp2C->unk50 = arg8;
    temp_f0 = D_8074E8B0[var_a1].unk8;
    sp2C->unk54 = temp_f0 * temp_f0;
    var_a0 = arg6;
    do {
        var_a1_2 += 4;
        var_v1++;
        var_v1->unk14 = var_a0->unk0;
        var_v1->unk18 = var_a0->unk4;
        var_v1->y_rotation = var_a0->unk8;
        var_v1->unk20 = var_a0->unkC;
        var_a0++;
    } while (var_a1_2 != 8);
    sp2C->next_spawner = actor_spawner_pointer;
    if (actor_spawner_pointer != NULL) {
        actor_spawner_pointer->previous_spawner = sp2C;
    }
    actor_spawner_pointer = sp2C;
    return sp2C;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80689418.s")

void func_8068A1B8(void);
void func_80613794(Actor*, u8);

typedef struct {
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    s16 sp74;
    s16 sp76;
    u8* sp78;
} StackStructThing_80689418;

/*
// TODO: Extremely close
void func_80689418(void) {
    ActorSpawner *currentSpawner;
    StackStructThing_80689418 tempStruct;
    s32 max;
    f64 temp_f20;
    s32 i;

    max = 0x80;
    currentSpawner = actor_spawner_pointer;
    if (currentSpawner != NULL) {
        temp_f20 = D_80759C80;
        do {
            if (currentSpawner->unk48 != 0) {
                if (currentSpawner->drawing_code(currentSpawner) != 0) {
                    if (!(currentSpawner->tied_actor->object_properties_bitfield & 0x200000)) {
                        func_80678458(currentSpawner->tied_actor);
                        currentSpawner->unk48 = 0;
                        currentSpawner->unk10 = currentSpawner->tied_actor->x_position;
                        currentSpawner->unk14 = currentSpawner->tied_actor->y_position;
                        currentSpawner->unk18 = currentSpawner->tied_actor->z_position;
                        currentSpawner->unk4A = currentSpawner->tied_actor->unk12C;
                        func_80613794(currentSpawner->tied_actor, 0);
                        func_80613794(currentSpawner->tied_actor, 1);
                        func_80613794(currentSpawner->tied_actor, 2);
                    }
                }
            } else if (currentSpawner->unk5C(currentSpawner) != 0) {
                u8 var_a0;
                i = 0;
                var_a0 = FALSE;
                if (currentSpawner->tied_actor == NULL) {
                    s16 temp_a1;
                    temp_a1 = currentSpawner->actor_type + 0x10;
                    while (!var_a0 && (i < max)) {
                        if (temp_a1 == D_8074E8B0[i].unk0) {
                            var_a0 = TRUE;
                        } else {
                            i++;
                        }
                    }
                    tempStruct.sp5C = temp_a1;
                    tempStruct.sp64 = D_8074E8B0[i].unk4;
                    tempStruct.sp60 = D_8074E8B0[i].unk2;
                    tempStruct.sp68 = currentSpawner->x_position;
                    tempStruct.sp6C = currentSpawner->y_position;
                    tempStruct.sp70 = currentSpawner->z_position;
                    tempStruct.sp74 = currentSpawner->y_rotation;
                    tempStruct.sp76 = 0;
                    tempStruct.sp78 = &currentSpawner->pad24[0];
                    if (func_80677ED0(&tempStruct) != 0) {
                        currentSpawner->tied_actor = D_807FBB44;
                        currentSpawner->unk48 = 1;
                        D_807FBB44->unk11C = currentSpawner->unk50;
                        if (D_807FBB44->animation_state != NULL) {
                            D_807FBB44->animation_state->scale_x = currentSpawner->unk20 * temp_f20;
                            D_807FBB44->animation_state->scale_y = currentSpawner->unk20 * temp_f20;
                            D_807FBB44->animation_state->scale_z = currentSpawner->unk20 * temp_f20;
                        }
                    }
                } else if (currentSpawner->unk48 == 0) {
                    if (currentSpawner->unk58 != 0) {
                        currentSpawner->tied_actor->unk0 = func_80612E90(currentSpawner->tied_actor, currentSpawner->unk58, 0);
                    }
                    func_80678428(currentSpawner->tied_actor);
                    currentSpawner->unk48 = 1;
                }
            }
            currentSpawner = currentSpawner->next_spawner;
        } while (currentSpawner != NULL);
    }
    
    func_8068A1B8();
}
*/

void func_806896D0(s32 arg0) {
    func_80689710(arg0, 1);
}

void func_806896F0(s32 arg0) {
    func_80689710(arg0, 0);
}

void func_80689710(ActorSpawner *arg0, u8 arg1) {
    ActorSpawner *phi_s0 = actor_spawner_pointer;
    s32 found = FALSE;
    ActorSpawner *phi_s1 = NULL;

    while (!found && phi_s0) {
        if (phi_s0 == arg0) {
            found = TRUE;
            if (arg1 != 0) {
                if (phi_s0->tied_actor) {
                    func_806782C0(phi_s0->tied_actor);
                }
            }
            if (phi_s1) {
                phi_s1->next_spawner = phi_s0->next_spawner;
            } else {
                actor_spawner_pointer = phi_s0->next_spawner;
            }
            if (phi_s0->next_spawner) {
                phi_s0->next_spawner->previous_spawner = phi_s1;
            }
            func_8061130C(phi_s0);
        } else {
            phi_s1 = phi_s0;
            phi_s0 = phi_s0->next_spawner;
        }
    }
}

void func_806897F0(Actor *arg0) {
    ActorSpawner *phi_s0 = actor_spawner_pointer;
    s32 found = FALSE;
    ActorSpawner *phi_s1 = NULL;

    while (!found && phi_s0) {
        if (arg0 == phi_s0->tied_actor) {
            found = TRUE;
            if (phi_s1) {
                phi_s1->next_spawner = phi_s0->next_spawner;
            } else {
                actor_spawner_pointer = phi_s0->next_spawner;
            }
            if (phi_s0->next_spawner) {
                phi_s0->next_spawner->previous_spawner = phi_s1;
            }
            func_8061130C(phi_s0);
        } else {
            phi_s1 = phi_s0;
            phi_s0 = phi_s0->next_spawner;
        }
    }
}

void func_806898A8(void) {
    ActorSpawner *next;
    ActorSpawner *spawner = actor_spawner_pointer;

    while (spawner) {
        next = spawner->next_spawner;
        func_8061130C(spawner);
        spawner = next;
    }
    actor_spawner_pointer = NULL;
}

s32 func_806898F8(void) {
    ActorSpawner *spawner = actor_spawner_pointer;
    s32 count = 0;
    
    while (spawner) {
        if (spawner->unk4C == 0 || spawner->tied_actor != NULL && spawner->tied_actor->unk64 & 0x400) {
            count++;
        }
        spawner = spawner->next_spawner;
    }
    // TODO: What is this? Some sizeof()?
    return (count * 0x38) + 4;
}

typedef struct {
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40[8];
    s16 sp60;
    s16 sp62;
    s16 sp64;
} Struct80689958;

void func_80689958(s32 *arg0) {
    ActorSpawner *currentSpawner;
    s32 count;
    Struct80689958 sp30;
    s32 *var_s1;

    currentSpawner = actor_spawner_pointer;
    count = 0;
    while (currentSpawner != NULL) {
        if (currentSpawner->unk4C == 0 || currentSpawner->tied_actor != NULL && currentSpawner->tied_actor->unk64 & 0x400) {
            count++;
        }
        currentSpawner = currentSpawner->next_spawner;
    }
    *arg0 = count;
    currentSpawner = actor_spawner_pointer;
    var_s1 = arg0 + 1;
    while (currentSpawner != NULL) {
        if (currentSpawner->unk4C == 0 || currentSpawner->tied_actor != NULL && currentSpawner->tied_actor->unk64 & 0x400) {
            sp30.sp62 = currentSpawner->actor_type;
            sp30.sp3C = currentSpawner->unk20;
            sp30.sp60 = currentSpawner->y_rotation;
            sp30.sp30 = currentSpawner->x_position;
            sp30.sp34 = currentSpawner->y_position;
            sp30.sp38 = currentSpawner->z_position;
            sp30.sp64 = currentSpawner->id;
            memcpy(&sp30.sp40, &currentSpawner->pad24[0], 0x20);
            memcpy(var_s1, &sp30, 0x38);
            var_s1 += 14;
        }
        currentSpawner = currentSpawner->next_spawner;
    }
}

void func_80689A80(s16 arg0, s32 arg1) {
    s32 found = FALSE;
    ActorSpawner *spawner = actor_spawner_pointer;

    while (spawner && !found) {
        if (arg0 == spawner->id) {
            found = TRUE;
        } else {
            spawner = spawner->next_spawner;
        }
    }
    if (found) {
        if (spawner->tied_actor) {
            func_8067AB20(current_actor_pointer, spawner->tied_actor, 0x01000000, 1, arg1, 0);
        }
    }
}

u8 func_80689B10(s16 arg0, u8 arg1, u8 arg2) {
    s32 found = FALSE;
    ActorSpawner *spawner = actor_spawner_pointer;

    while (spawner && !found) {
        if (arg0 == spawner->id) {
            found = TRUE;
        } else {
            spawner = spawner->next_spawner;
        }
    }
    if (!found) {
        return 0;
    }
    if (!spawner->tied_actor) {
        return 0;
    }
    if (arg2) {
        spawner->tied_actor->control_state = arg1;
    }
    return spawner->tied_actor->control_state;
}

s32 func_80689BAC(s16 arg0) {
    s32 found = FALSE;
    ActorSpawner *spawner = actor_spawner_pointer;

    while (spawner && !found) {
        if (arg0 == spawner->id) {
            found = TRUE;
        } else {
            spawner = spawner->next_spawner;
        }
    }
    if (!found) {
        return FALSE;
    }
    if (spawner->unk48) {
        return TRUE;
    }
    return FALSE;
}

// Probably doable, looks like dxyz calculations in nested loops?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80689C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80689DD4.s")

/*
extern f32 D_80759C8C;

// TODO: Close, weird float regalloc
f32 func_80689DD4(f32 x, f32 y, f32 z) {
    f32 dx, dy, dz;
    f32 phi_f2;
    f32 temp_f0;
    s32 i;

    phi_f2 = D_80759C8C;
    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist) {
            dz = z - character_change_array[i].look_at_eye_z;
            dx = x - character_change_array[i].look_at_eye_x;
            dy = y - character_change_array[i].look_at_eye_y;
            temp_f0 = (dx * dx) + (dy * dy) + (dz * dz);
            phi_f2 = MIN(temp_f0, phi_f2);
        }
    }
    return phi_f2;
}
*/

s32 func_80689E98(s32 arg0) {
    return 1;
}

void func_80689EA4(ActorSpawner *spawner) {
    if (func_80689F2C()) {
        func_80652E58(spawner->unk4A);
        return;
    }
    func_80689F80(spawner);
}

u8 func_80689EE4(ActorSpawner *spawner) {
    if (func_80689F2C()) {
        return !func_80652E58(spawner->tied_actor->unk12C);
    }
    return func_80689FEC(spawner);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_8D3E0/func_80689F2C.s")

u8 func_80689F80(ActorSpawner *spawner) {
    return func_80652E58(spawner->unk4A)
        && func_80689DD4(spawner->unk10, spawner->unk14, spawner->unk18) < spawner->unk54;
}

u8 func_80689FEC(ActorSpawner *spawner) {
    return (!func_80652E58(spawner->tied_actor->unk12C)
        || !(func_80689DD4(spawner->unk10, spawner->unk14, spawner->unk18) < spawner->unk54))
    && spawner->tied_actor->unk114 == NULL;
}

u8 func_8068A074(ActorSpawner *spawner) {
    return (!func_80652E58(spawner->tied_actor->unk12C)
        || !(func_80689DD4(spawner->unk10, spawner->unk14, spawner->unk18) < spawner->unk54))
        && (spawner->tied_actor->unk114 == NULL
        && spawner->tied_actor->control_state == 0);
}

s32 func_8068A10C(s32 arg0) {
    return 0;
}

u8 func_8068A118(ActorSpawner *arg0) {
    // TODO: idk why this temporary variable is needed but... yeah
    u8 temp = func_80689DD4(arg0->unk10, arg0->unk14, arg0->unk18) < arg0->unk54;
    return temp;
}

u8 func_8068A164(ActorSpawner *spawner) {
    return !(func_80689DD4(spawner->tied_actor->x_position, spawner->tied_actor->y_position, spawner->tied_actor->z_position) < spawner->unk54);
}

void func_8068A1B8(void) {
    D_807FC610 = 0;
    D_807FC611 = 0;
}

void func_8068A1CC(s16 arg0) {
    if (D_807FC610 != 0x10) {
        D_807FC5D0[D_807FC610] = arg0;
        D_807FC610++;
    }
}

void func_8068A20C(s16 arg0) {
    if (D_807FC611 != 0x10) {
        D_807FC5F0[D_807FC611] = arg0;
        D_807FC611++;
    }
}

s32 func_8068A24C(ActorSpawner *spawner) {
    s32 i;
    for (i = 0; i < D_807FC610; i++) {
        if ((spawner->id == D_807FC5D0[i]) && (spawner->unk48 == 0)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_8068A2AC(ActorSpawner *spawner) {
    s32 i;
    for (i = 0; i < D_807FC611; i++) {
        if ((spawner->id == D_807FC5F0[i]) && (spawner->unk48 != 0)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_8068A2FC(Actor *actor) {
    actor->shadow_opacity = 0;
    actor->object_properties_bitfield &= ~0x8000;
    actor->noclip_byte = 1;
    actor->unk138 = 0;
    actor->control_state = 0x63;
    func_8066E6C8(actor, 0, 0);
}
