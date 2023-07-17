#include <ultra64.h>
#include "functions.h"


extern f64 D_80759380;
extern u8 D_807F94B4;

extern u8 D_807FBC55;
extern u8 D_807FBE08;
extern u8 D_807FBE09;
extern Actor *D_807FBE10;
extern s16 D_807FBF10;

extern u16 D_8074D624[];
Actor *actor_list[256];
s16 actor_count;

s32 func_8067B2C0(s32);
void func_80678F64(Actor*);
void func_8067B01C(void);
void func_8067B100(Actor *player);
s16 func_8067AF74(Actor*);
s32 func_806782E8(Actor *arg0);

void func_806785D4(Actor*);
void func_8062D26C(Actor*);
void func_806783BC();
void func_806136B4();
void func_8066E21C(LedgeInfo*);
// Note: The pointer can be to any one of the above 10 structs, maybe more
void func_8067AEFC(Actor*);
void func_8070DA74(Actor*);
void func_8071586C(Actor*);
void func_807233B4(Actor*);

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_80677D80.s")

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
} Struct807FB630;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct807FB7B0;

extern Struct807FB630 D_807FB630[];
extern Struct807FB7B0 D_807FB7B0[];
extern s16 D_807FBB30;
extern s16 D_807FBB32;
extern s32 D_807FBB38;
extern s32 *D_807FBB50;
extern void *D_807FBB54;
extern void *D_807FBB58;
extern void *D_807FBB5C;
extern s16 D_807FBFD8;

/*
void func_80677D80(void) {
    u16 i;

    for (i = 0; i < 0x20; i++) {
        D_807FB630[i].unk0 = 0;
        D_807FB630[i].unk2 = 0;
        D_807FB630[i].unk4 = 0;
    }
    D_807FBB30 = 0;
    for (i = 0; i < 0x20; i++) {
        D_807FB7B0[i].unk0 = 0xFFFF;
        D_807FB7B0[i].unk4 = 0;
        D_807FB7B0[i].unk8 = 0;
    }
    D_807FBB32 = 0;
    D_807FBB50 = getPointerTableFile(0xD, 0, 1, 1);
    D_807FBB54 = (u8*)D_807FBB50 + D_807FBB50[3];
    D_807FBB58 = (u8*)D_807FBB50 + D_807FBB50[2];
    D_807FBB5C = (u8*)D_807FBB50 + D_807FBB50[1];
    for (i = 0; i < 0x40; i++) {
        D_807FB930[i].unk0 = NULL;
        D_807FB930[i].unk4 = 0;
    }
    D_807FBB34 = 0;
    func_8067AE58();
    D_807FBB38 = 0;
    D_807FBE09 = 0;
    D_807FBFD8 = 0;
    D_807FBB48 = NULL;
}
*/

void func_80677EC8(s32 arg0) {

}

/*
Functions in this table (D_8074DA30):
All take 1 param and are tiny (some are empty bodies)
func_8067B2B0
func_8067B2C0
func_8067B2DC
func_8067B42C
func_8067B3F4
func_8067B2B8
func_8067B290
func_8067B298
func_8067B2A0
func_8067B2A8
*/

extern s32 (*D_8074DA30[])(s32);
extern u8 D_8074D8D4[];

typedef struct {
    s32 unk0; // Actor Behaviour Index
    s32 unk4;
    s32 unk8;
    f32 unkC; // X Position
    f32 unk10; // Y Position
    f32 unk14; // Z Position
    s16 unk18; // Y Rotation
    s16 unk1A;
    Actor124 *unk1C;
} Struct80677ED0;

extern s32 func_80678050(u16);

s32 func_80677ED0(Struct80677ED0 *arg0) {
    s32 master_type;

    if (func_80678050(arg0->unk0)) {
        master_type = D_8074D8D4[arg0->unk0];
        if(D_8074DA30[master_type](&arg0->unk4)) {
            D_807FBB44->x_position = arg0->unkC;
            D_807FBB44->y_position = arg0->unk10;
            D_807FBB44->z_position = arg0->unk14;
            D_807FBB44->unk124 = arg0->unk1C;
            D_807FBB44->y_rotation = arg0->unk18;
            D_807FBB44->unk15C = arg0->unk1A;
            if (arg0->unk8 != 0) {
                func_80614EBC(D_807FBB44, arg0->unk8);
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_80677FA8(Actors arg0, s32 arg1) {
    s32 master_type;

    if (func_80678050(arg0)) {
        master_type = D_8074D8D4[arg0];
        if (D_8074DA30[master_type](&arg1)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_80678014(s32 arg0) {
    if (func_80678050(arg0)) {
        func_8067B2C0(0);
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_80678050.s")

extern u16 D_807FBB3E;
extern u16 *D_8074E218[];
extern u16 D_8074DA58[];

void func_8067AE90(Actor *arg0);
void func_80611690(void*);
void func_806761D0(Actor *arg0);

/*
// Doable, initializeActor(behaviour)
s32 func_80678050(u16 arg0) {
    Actor *newActor;
    u16 var_a1;
    u16 var_a2;
    u16 *var_v0;
    u16 *var_v0_2;
    u16 temp_t4;
    u16 var_v1;
    void **var_v1_2;
    s32 *var_a0;

    var_v0 = D_8074E218[arg0];
    var_v1 = *var_v0;
    var_a1 = 0x174;
    var_a2 = 0;
    while (var_v1 != 0) {
        var_a2 += D_8074DA58[var_v1];
        var_v1 = var_v0[1];
        var_a1 += 4;
        var_v0++;
    }
    // Align to next 8 byte boundary
    var_a1 = (var_a1 + 7) & 0xFFF8;
    newActor = malloc((var_a2 + var_a1) & 0xFFFF);
    if (newActor != NULL) {
        func_80611690(newActor); // Something with the heap
        var_v0_2 = D_8074E218[arg0];
        var_v1_2 = &newActor->additional_actor_data;
        var_a0 = &newActor + var_a1;
        while (var_v0_2[0] != 0) {
            *var_v1_2 = var_a0;
            var_v1_2++;
            temp_t4 = D_8074DA58[var_v0_2[0]];
            var_v0_2++;
            var_a0 += temp_t4;
        }
        newActor->collision_queue_pointer = NULL;
        newActor->unk138 = -1;
        newActor->noclip_byte = 2;
        newActor->locked_to_pad = 0;
        newActor->unkF8 = 0x50;
        newActor->object_properties_bitfield = 0x58144;
        newActor->unk64 = 0;
        newActor->shadow_opacity = 0xFF;
        newActor->unk58 = arg0;
        if (D_807FBB64 & 0x100) {
            newActor->draw_distance = 2000;
        } else {
            newActor->draw_distance = 500;
        }
        newActor->unk68 = 0;
        newActor->unk156 = 0;
        newActor->unk78 = 0;
        newActor->unk6C = 1;
        newActor->unk6A = 1;
        newActor->unk132 = 1;
        newActor->unk114 = NULL;
        newActor->unk118 = 0;
        newActor->unk11C = NULL;
        newActor->unk6E[0] = -1;
        newActor->unk70 = -1;
        newActor->unk150 = NULL;
        newActor->unk12C = -1;
        newActor->unk124 = 0;
        newActor->unk148 = 0;
        newActor->unk14C = 0;
        newActor->unkD4 = 0x80748D4A;
        newActor->unk146 = -1;
        newActor->unkDA = 0x400;
        newActor->unkCC = 0;
        newActor->unkCD = 0;
        newActor->unk130 = 0;
        newActor->unk131 = 0;
        newActor->unk16D = 0xF;
        newActor->unkCE = 0;
        newActor->unkB0 = -1;
        newActor->interactable = D_8074D624[arg0];
        newActor->unk54 = D_807FBB38;
        D_807FBB38++;
        func_8067AE90(newActor); // Add to actor list
        func_806761D0(newActor); // Set initial health
        D_807FB930[D_807FBB34].unk0 = newActor;
        D_807FB930[D_807FBB34].unk4 = 0;
        D_807FBB3E = D_807FBB34;
        D_807FBB34++;
        D_807FBB44 = newActor;
        return TRUE;
    }
    return FALSE;
}
*/

void func_806782C0(Actor *arg0) {
    func_806897F0(arg0);
    func_806782E8(arg0);
}

s32 func_806782E8(Actor *arg0) {
    s32 i;

    if (D_807FBE09 != 0) {
        if (D_807FBF10 == 0x40) {
            func_80732354(0xC, 0, 0, 0);
        }
        if (arg0 == current_actor_pointer) {
            D_807FBE08 = 1;
        }
        for (i = 0; i < D_807FBF10; i++) {
            if (arg0 == (&D_807FBE10)[i]) {
                return FALSE;
            }
        }
        (&D_807FBE10)[D_807FBF10] = arg0;
        D_807FBF10++;
    } else {
        func_806785D4(arg0);
    }
    return TRUE;
}

// TODO: Cleanup
void func_806783BC(void) {
    s32 *var_s1;
    s32 var_s0;

    var_s0 = 0;
    if (D_807FBF10 > 0) {
        var_s1 = &D_807FBE10;
        do {
            func_806785D4(*var_s1);
            var_s0++;
            var_s1++;
        } while (var_s0 < D_807FBF10);
    }
    D_807FBF10 = 0;
}

void func_80678428(Actor *arg0) {
    D_807FB930[D_807FBB34].unk0 = arg0;
    D_807FB930[D_807FBB34].unk4 = 0;
    D_807FBB34++;
}

void func_80678458(Actor *arg0) {
    s16 i;

    func_80605314(arg0, 0);
    func_80605314(arg0, 1);
    // Absolutely baffling way to write this
    i = 0;
    while ((arg0 != D_807FB930[i].unk0) && (i < D_807FBB34)) {
        i++;
    }
    D_807FBB34--;
    if (D_807FBB34 != 0) {
        D_807FB930[i].unk0 = D_807FB930[D_807FBB34].unk0;
        D_807FB930[i].unk4 = D_807FB930[D_807FBB34].unk4;
    }
    func_8062D26C(arg0);
    arg0->unk150 = NULL;
}

void func_80678530(Actor *arg0) {
    Actor *actor;
    s32 i;

    D_807FBE09 = 1;
    D_807FBF10 = 0;
    for (i = 0; i < D_807FBB34; i++) {
        actor = D_807FB930[i].unk0;
        if (arg0 == actor->unk11C) {
            func_806782C0(actor);
            actor->unk11C = NULL;
        }
    }
    D_807FBE09 = 0;
    func_806783BC();
}

void func_806785D4(Actor *arg0) {
    s16 i;
    Actor *temp_v0;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_6;

    if (arg0->unk0 != 0) {
        func_806136B4();
    }
    temp_a0_6 = arg0->unk11C;
    if (temp_a0_6 != 0) {
        func_80679200(temp_a0_6, arg0, 0x80000, 0, 0, 0);
    }
    for (i = 0; i < D_807FBB34; i++) {
        temp_v0 = D_807FB930[i].unk0;
        if (arg0 == temp_v0->unk11C) {
            temp_v0->unk11C = NULL;
        }
    }            
    func_8071586C(arg0);
    func_807233B4(arg0);
    func_80605314(arg0, 0);
    func_80605314(arg0, 1);
    // Absolutely baffling way to write this
    i = 0;
    while (arg0 != D_807FB930[i].unk0 && i < D_807FBB34) {
        i++;
    }
    if (i != D_807FBB34) {
        D_807FBB34--;
        if (D_807FBB34 != 0) {
            D_807FB930[i].unk0 = D_807FB930[D_807FBB34].unk0;
            D_807FB930[i].unk4 = D_807FB930[D_807FBB34].unk4;
        }
    }
    func_8066E21C(arg0->ledge_info_pointer);
    func_8072F09C(arg0);
    temp_a0_3 = arg0->unk118;
    if (temp_a0_3 != NULL) {
        func_8061130C(temp_a0_3);
    }
    temp_a0_4 = arg0->unk148;
    if (temp_a0_4 != NULL) {
        func_8061130C(temp_a0_4);
    }
    temp_a0_5 = arg0->unk14C;
    if (temp_a0_5 != NULL) {
        func_8061130C(temp_a0_5);
    }
    func_8062D26C(arg0);
    if (arg0->unk58 != ACTOR_TEXT_BUBBLE) {
        func_8070DA74(arg0);
    }
    func_8068C2F8(arg0);
    func_8067AEFC(arg0);
    func_8061130C(arg0);
}

void func_806787CC(void) {
    func_80689418();
}

void func_806787EC(void) {

}

void func_806787F4(void) {

}

void func_806787FC(void) {

}

void func_80678804(void) {

}

void func_8067880C(void) {

}

void func_80678814(void) {

}

void func_8067881C(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_80678824.s")

extern s16 D_807FBF10;
extern void* D_807FBFE0[];

/*
void func_80678824(void) {
    s32 i;
    D_807FBE09 = 1;
    D_807FBF10 = 0;
    for (i = 0; i < 4; i++) {
        D_807FBFE0[i] = NULL;
    }
    func_8067889C(1); // updateLoadedActors()?
    func_8067889C(2); // updateLoadedActors()?
    func_806790F4(1);
    func_80678B04();
    D_807FBE09 = 0;
    func_806783BC();
    func_80679334();
}
*/

// Jumptable, can auto decompile for some reason...
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_8067889C.s")

// Jumptable, can auto decompile for some reason...
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_806789E4.s")

void func_80678B04(void) {
    Actor *temp_s0;
    s32 i;

    for (i = 0; i < D_807FBB34; i++) {
        temp_s0 = D_807FB930[i].unk0;
        if (!(temp_s0->object_properties_bitfield & 0x08000000) && (temp_s0->object_properties_bitfield & 0x500) && (temp_s0->object_properties_bitfield & 0x4000)) {
            func_80614A64(temp_s0);
        }
        temp_s0->object_properties_bitfield &= ~0x100;
    }
}

void func_80678BBC(Actor *arg0) {
    func_806663F8();
    if (arg0->interactable & 1) {
        func_8067B100(arg0);
    }
    arg0->unk88 = arg0->x_position;
    arg0->unk8C = arg0->y_position;
    arg0->unk90 = arg0->z_position;
    arg0->unkBC = arg0->unkB8;
    D_807F94B4 = 0;
    if (arg0->ledge_info_pointer) {
        arg0->ledge_info_pointer->unk68 = 0;
    }
    func_80678F64(arg0);
    if (arg0 == D_807FBB48) {
        func_80675EE0(arg0);
    } else {
        func_806761EC(arg0);
    }
    func_806794EC(arg0);
    if (arg0 == D_807FBB48) {
        func_806EB194();
    }
    if (arg0->noclip_byte & 4) {
        func_80672B1C(arg0);
    } else {
        if (arg0->ledge_info_pointer) {
            arg0->ledge_info_pointer->unk6C = 0;
        }
    }
    if (arg0->locked_to_pad) {
        func_80669A6C(arg0);
    }
}

s32 func_8067B3F4(s32 arg0);
void func_80679178(Actor *arg0);
void func_80678E6C(Actor *arg0);
void func_80678E14(Actor *arg0);
void func_806790F4(u8);

void func_80678CC8(Actor *arg0) {
    u32 temp_v0;
    u32 temp_v0_2;

    if (*(s32*)(&D_8074DA30[D_8074D8D4[arg0->unk58]]) == (s32)&func_8067B3F4) {
        guTranslateF(&arg0->unkC, arg0->x_position, arg0->y_position, arg0->z_position);
    }
    func_80665FB4(arg0);
    func_80678E6C(arg0);
    if (!(arg0->object_properties_bitfield & 0x8000000)) {
        arg0->object_properties_bitfield &= ~0x200;
        if (arg0->animation_state && ((func_8061421C(arg0), temp_v0_2 = arg0->object_properties_bitfield, ((temp_v0_2 & 0x500) != 0)) || (arg0->unk156 != 0)) && ((temp_v0_2 & 0x4000) == 0)) {
            func_80614A64(arg0);
        }
    }
    func_80678E14(arg0);
    func_8066EBF4(arg0);
    func_806790F4(0);
    func_8067A1DC(arg0);
    func_80679178(arg0);
    func_80685D84(arg0);
    func_80687F7C(arg0);
    arg0->object_properties_bitfield |= 0x10;
}

void func_80678DD8(Actor *arg0) {
    func_8061421C();
    if (arg0->object_properties_bitfield & 0x500) {
        func_80614A64(arg0);
    }
}

void func_80678E14(Actor *arg0) {
    if (arg0->unk8C < arg0->y_position) {
        arg0->unk9C = arg0->y_position;
        return;
    }
    if (arg0->unk6A & 5) {
        if (arg0->unk6C & 5) {
            arg0->unk9C = arg0->y_position;
            return;
        }
        arg0->unkA0 = arg0->unk9C;
    }
}

void func_80678E6C(Actor *arg0) {
    u8 sp27;

    if ((arg0->noclip_byte & 4) && (D_807FBE08 == 0)) {
        if (arg0->object_properties_bitfield & 0x10000) {
            arg0->unkFC = 0;
            arg0->unkFD = 0;
        }
        arg0->unkFC |= func_8066F250(arg0, &arg0->unkF4, &arg0->unkF6, &sp27);
        sp27 |= D_807FBC55;
        if (sp27 != 0) {
            if (!(arg0->unk6A & 0x10)) {
                arg0->unk6A |= 0x10;
                if (arg0 == D_807FBB48) {
                    func_806EB0C0(4, NULL, cc_player_index);
                }
            }
        }
        if (sp27 == 0) {
            arg0->unk6A &= ~0x10;
            return;
        }
    } else {
        arg0->unkFC = 0;
        arg0->unkFD = 0;
        arg0->unk6A &= ~0x10;
    }
}

// This matched without a temp before, now it needs one
// This compiler owns
void func_80678F64(Actor *arg0) {
    Actor114* temp = arg0->unk114;
    if (temp) {
        func_8061130C(temp);
        arg0->unk114 = NULL;
    }
}

void func_80678F9C(Actor *arg0, s32 arg1) {
    if (arg0->unk114 == NULL) {
        arg0->unk114 = malloc(sizeof(Actor114));
        arg0->unk114->unk10 = 0;
    }
    if (arg0->unk114->unk10 != 4) {
        arg0->unk114->unk0[arg0->unk114->unk10] = arg1;
        arg0->unk114->unk10++;
    }
}

s32 func_80679010(Actor *arg0, Actor *arg1) {
    Actor114 *temp_v0;
    s32 i;

    temp_v0 = arg0->unk114;
    if (temp_v0 == NULL) {
        return FALSE;
    }
    for (i = 0; i < temp_v0->unk10; i++) {
        if (arg1 == temp_v0->unk0[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

// Several different types of structs are passed into this function
void func_80679064(void *arg0) {
    s32 i = 0;
    s32 found = FALSE;

    while (i < 4 && !found) {
        if (!D_807FBFE0[i]) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (!found) {
        func_80732354(0xE, 0, 0, 0);
    } else {
        D_807FBFE0[i] = arg0;
    }
}

typedef struct {
    void(* unk0)(void*);
    u8 unk4[4];
    s32 unk8;
} struct_807FBFE0;

void func_806790F4(u8 arg0) {
    struct_807FBFE0 *temp_v0;
    s32 i = 0;

    for (i = 0; i < 4; i++) {
        temp_v0 = D_807FBFE0[i];
        if ((temp_v0 != NULL) && (arg0 == temp_v0->unk4[0])) {
            temp_v0->unk0(&temp_v0->unk8);
            func_8061130C(D_807FBFE0[i]);
            D_807FBFE0[i] = NULL;
        }
    }
}

// This matched without a temp before, now it needs one
// This compiler owns
// resolveActorCollisions()?
void func_80679178(Actor *arg0) {
    ActorCollision *nextCollision; // TODO: Can we get rid of this somehow?
    ActorCollision *currentCollision;
    ActorCollision *temp;

    currentCollision = arg0->collision_queue_pointer;
    if (currentCollision) {
        arg0->collision_queue_pointer = NULL;
    }
    while (currentCollision) {
        nextCollision = currentCollision->next;
        temp = currentCollision->unk10;
        if (temp) {
            func_8061130C(temp);
        }
        func_8061130C(currentCollision);
        currentCollision = nextCollision;
    }
}

void func_806791DC(Actor *arg0, s32 arg1) {
    arg0->unk138 |= arg1;
}

void func_806791EC(Actor *arg0, s32 arg1) {
    arg0->unk138 &= ~arg1;
}

// TODO: Clean this up
void func_80679200(Actor *arg0, Actor *arg1, s32 arg2, u8 arg3, s32 arg4, void *arg5) {
    ActorCollision **sp28;
    ActorCollision **var_v1;
    ActorCollision *var_t0;
    ActorCollision *temp_v0;
    ActorCollision *var_v0;

    var_t0 = NULL;
    if (func_8067AF44(arg0) != 0) {
        var_v0 = arg0->collision_queue_pointer;
        var_v1 = &arg0->collision_queue_pointer;
        if (var_v0 != NULL) {
            do {
                var_v1 = &var_v0->next;
                var_t0 = var_v0;
                var_v0 = var_v0->next;
            } while (var_v0 != NULL);
        }
        sp28 = var_v1;
        temp_v0 = func_80679490(arg1, arg2, arg3, arg4, arg5);
        *var_v1 = temp_v0;
        temp_v0->prev = var_t0;
    }
}

typedef struct {
    ActorCollision *unk0;
    Actor *unk4;
    s32 unk8;
} Struct807FBF18;

extern Struct807FBF18 D_807FBF18[];
extern s16 D_807FBFD8;

void func_80679290(Actor *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (D_807FBFD8 == 0x10) {
        func_80732354(0xF, 0, 0, 0);
    }
    D_807FBF18[D_807FBFD8].unk0 = func_80679490(arg1, arg2, arg3, arg4, arg5);
    D_807FBF18[D_807FBFD8].unk4 = arg0;
    D_807FBF18[D_807FBFD8].unk8 = arg6;
    D_807FBFD8++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_80679334.s")

/*
// TODO: Close
void func_80679334(void) {
    Struct807FBF18 *var_s0;
    Actor *temp_s2;
    ActorCollision **var_a0;
    ActorCollision *temp_s2_2;
    ActorCollision *temp_t9;
    ActorCollision *var_a1;
    ActorCollision *var_v0;
    s32 temp_t7;
    s32 var_a0_2;
    s32 i;
    u32 temp_a0;
    Struct807FBF18 *temp_v0;

    for (i = 0; i < D_807FBFD8; i++) {
        temp_t7 = D_807FBF18[i].unk8 - 1;
        D_807FBF18[i].unk8 = temp_t7;
        if (temp_t7 == 0) {
            temp_s2 = D_807FBF18[i].unk4;
            if (func_8067AF44(temp_s2) != 0) {
                var_v0 = temp_s2->collision_queue_pointer;
                var_a0 = &temp_s2->collision_queue_pointer;
                var_a1 = NULL;
                while (var_v0) {
                    var_a0 = &var_v0->next;
                    var_a1 = var_v0;
                    var_v0 = var_v0->next;
                }
                temp_t9 = D_807FBF18[i].unk0;
                *var_a0 = temp_t9;
                temp_t9->prev = var_a1;
            } else {
                temp_s2_2 = D_807FBF18[i].unk0;
                temp_a0 = temp_s2_2->unk10;
                if (temp_a0 != 0) {
                    func_8061130C(temp_a0);
                }
                func_8061130C(temp_s2_2);
            }
        }
    }
    do {
        var_a0_2 = FALSE;
        for (i = 0; i < D_807FBFD8; i++) {
            if (D_807FBF18[i].unk8 == 0) {
                D_807FBFD8--;
                var_a0_2 = TRUE;
                temp_v0 = &D_807FBF18[D_807FBFD8];
                D_807FBF18[i].unk0 = temp_v0->unk0;
                D_807FBF18[i].unk4 = temp_v0->unk4;
                D_807FBF18[i].unk8 = temp_v0->unk8;
            }
        }
    } while (var_a0_2 != FALSE);
}
*/

ActorCollision *func_80679490(Actor * arg0, s32 arg1, u8 arg2, s32 arg3, void *arg4) {
    ActorCollision *temp_v0 = malloc(sizeof(ActorCollision));
    temp_v0->unk0 = arg1;
    temp_v0->unk4 = arg2;
    temp_v0->collisionSource = arg0;
    temp_v0->unkC = arg3;
    temp_v0->unk10 = arg4;
    temp_v0->next = NULL;
    return temp_v0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_806794EC.s")

extern u8 D_807FBB85;
extern s32 D_80720E2C; // TODO: Datatype

void func_80686CF8(Actor *actor);

void func_80679DC4(Actor *arg0, Actor *arg1, u8 arg2) {
    s32 sp3C;
    s32 var_a2;
    u16 temp_v0_2;
    s32 var_v0;
    s32 temp;

    var_a2 = arg2;
    D_807FBB85 = 1;
    if ((arg0 == D_807FBB48)) {
        if ((((character_change_array[extra_player_info_pointer->unk1A4].unk2C0 != 2)) || (arg1 == NULL) || !(arg1->interactable & 2))) {
            sp3C = 0x2E;
            var_a2 = TRUE;
            if (arg2) {
                sp3C = 0x30;
            }
            if ((arg1 != NULL) && (arg1->unk58 == ACTOR_PROJECTILE_SPIDER)) {
                func_80686CF8(arg0);
                switch (arg1->control_state_progress) {
                    case 1:
                        var_a2 = FALSE;
                        extra_player_info_pointer->unk1F0 = extra_player_info_pointer->unk1F0 ^ 0x80;
                        break;
                    case 2:
                        sp3C = 0x27;
                        break;
                    case 3:
                        temp = &func_8071F758;
                        func_807149FC(0xF0);
                        func_807149B8(1);
                        func_8071498C(temp);
                        func_80714C08(&D_80720E2C, 0.4f, arg0, 1, 2);
                        func_807149FC(0xF0);
                        func_807149B8(1);
                        func_8071498C(temp);
                        func_80714C08(&D_80720E2C, 0.38f, arg0, 5, 2);
                        func_807149FC(0xF0);
                        func_807149B8(1);
                        func_8071498C(temp);
                        func_80714C08(&D_80720E2C, 0.3f, arg0, 6, 2);
                        var_a2 = FALSE;
                        extra_player_info_pointer->unk1F0 |= 0x08000000;
                        break;
                }
                extra_player_info_pointer->unk200 = 0xF0;
            } else if ((arg1 != NULL) && ((((arg1->interactable & 1) != 0)) || (arg1->interactable & 4) || (arg1->interactable & 2))) {
                if (func_80714608(0) != 0) {
                    if (func_806D0DE4(arg0, arg1) != 0) {
                        sp3C = 0x31;
                    } else {
                        var_v0 = 1;
                        if (arg1->interactable & 4) {
                            var_v0 = 3;
                        }
                        if ((arg1->control_state != 0x28) && (var_v0 < 3)) {
                            sp3C = 0x2B;
                        } else {
                            sp3C = 0xE;
                        }
                    }
                }
            }
            if (var_a2 != 0) {
                func_806EB0C0(sp3C, arg1, cc_player_index);
            }
        }
    }
}

typedef struct Struct8067A09C Struct8067A09C;

// TODO: Any overlap with existing structs?
struct Struct8067A09C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    Struct8067A09C *unk14; // Doubly linked list
    Struct8067A09C *unk18; // Doubly linked list
};

Struct8067A09C *func_8067A09C(Struct8067A09C *arg0) {
    s32 found;
    Struct8067A09C *temp;
    Struct8067A09C *current;
    Struct8067A09C *var_v1;

    var_v1 = arg0;
    if (arg0 != NULL) {
        current = arg0->unk14;
        while (current != NULL) {
            arg0 = current->unk18;
            found = FALSE;
            while (arg0 != NULL && !found) {
                if (current->unk0 >= arg0->unk0) {
                    found = TRUE;
                    current->unk18->unk14 = current->unk14;
                    if (current->unk14 != NULL) {
                        current->unk14->unk18 = current->unk18;
                    }
                    temp = arg0->unk14;
                    arg0->unk14 = current;
                    current->unk14 = temp;
                    if (current->unk14 != NULL) {
                        current->unk14->unk18 = current;
                    }
                    current->unk18 = arg0;
                }
                arg0 = arg0->unk18;
            }
            if (found == FALSE) {
                current->unk18->unk14 = current->unk14;
                if (current->unk14 != NULL) {
                    current->unk14->unk18 = current->unk18;
                }
                current->unk18 = NULL;
                current->unk14 = var_v1;
                var_v1->unk18 = current;
                var_v1 = current;
            }
            current = current->unk14;
        }
    }
    return var_v1;
}

void func_8067A170(Actor* arg0, u8 arg1) {
    s32 i;

    for (i = 0; i < D_807FBB70.unk201; i++) {
        if (arg1 == D_807FBB70.unk244[i] && arg0 == D_807FBB70.unk204[i]) {
            D_807FBB70.unk244[i] = 0;
        }
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_8067A1DC.s")

// TODO: What type is this actually?
typedef struct {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    s16 unkA;
} GlobalASMStruct38;

// TODO: What type is this actually?
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8  unkC;
    u8  unkD;
} GlobalASMStruct26;

// TODO: What type is this actually?
typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    s16 unk8;
    s16 unkA;
} GlobalASMStruct27;

// TODO: What type is this actually?
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} GlobalASMStruct28;

// TODO: What type is this actually?
typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0xC - 0x4];
    s32 unkC;
    s32 unk10;
    u8 pad14[0x30 - 0x14];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} GlobalASMStruct29;

// TODO: What type is this actually?
typedef struct {
    s32 unk0;
} GlobalASMStruct30;

// TODO: Position?
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} GlobalASMStruct31;

// TODO: What type is this actually?
typedef struct {
    f32 unk0;
    f32 unk4;
} GlobalASMStruct32;

// TODO: What type is this actually?
typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    s16 unk8;
} GlobalASMStruct33;

// TODO: What type is this actually?
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
} GlobalASMStruct34;

void func_8067A69C(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5) {
    GlobalASMStruct38 *temp_v0 = malloc(0xC);
    temp_v0->unk0 = arg2;
    temp_v0->unk4 = arg3;
    temp_v0->unk8 = arg4;
    temp_v0->unk9 = arg5;
    func_80679200(arg1, arg0, 0x10, 0, 1, temp_v0);
}

void func_8067A70C(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6) {
    GlobalASMStruct26 *temp_v0 = malloc(0x10);
    temp_v0->unk0 = arg2;
    temp_v0->unk4 = arg3;
    temp_v0->unk8 = arg4;
    temp_v0->unkC = arg5;
    temp_v0->unkD = arg6;
    func_80679200(arg1, arg0, 0x20, 0, 1, temp_v0);
}

void func_8067A784(Actor *arg0, Actor *arg1, s16 arg2, f32 arg3, s16 arg4) {
    GlobalASMStruct27 *temp_v0;

    temp_v0 = malloc(0xC);
    temp_v0->unk0 = arg2;
    temp_v0->unk4 = arg3;
    temp_v0->unk8 = arg4;
    func_80679200(arg1, arg0, 0x4000, 0, 1, temp_v0);
}

void func_8067A7EC(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, u8 arg6) {
    GlobalASMStruct28 *temp_v0;

    temp_v0 = malloc(0x14);
    temp_v0->unk0 = arg2;
    temp_v0->unk4 = arg3;
    temp_v0->unk8 = arg4;
    temp_v0->unkC = arg5;
    temp_v0->unk10 = arg6;
    func_80679200(arg1, arg0, 1, 0, 1, temp_v0);
}

void func_8067A864(Actor *arg0, Actor *arg1, s16 arg2, s16 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7, s32 arg8) {
    GlobalASMStruct29 *temp_v0;

    temp_v0 = malloc(0x40);
    temp_v0->unk0 = arg2;
    temp_v0->unk2 = arg3;
    memcpy(&temp_v0->pad4, arg4, 0xC);
    memcpy(&temp_v0->unk10, arg5, 0x24);
    temp_v0->unk34 = arg6;
    temp_v0->unk38 = arg7;
    temp_v0->unk3C = arg8;
    func_80679200(arg1, arg0, 0x10000, 0, 1, temp_v0);
}

void func_8067A908(Actor *arg0, Actor *arg1, void *arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6) {
    GlobalASMStruct29 *temp_v0; // TODO: What type is this actually? It's probably not the same struct as above since there's 0x40 vs 0x3C in the malloc call

    temp_v0 = malloc(0x3C);
    memcpy(&temp_v0->unk0, arg2, 0xC);
    memcpy(&temp_v0->unkC, arg3, 0x24);
    temp_v0->unk30 = arg4;
    temp_v0->unk34 = arg5;
    temp_v0->unk38 = arg6;
    func_80679200(arg1, arg0, 0x20000, 0, 1, temp_v0);
}

void func_8067A99C(Actor *arg0, Actor *arg1, s32 arg2) {
    GlobalASMStruct30 *temp_v0; // TODO: What type is this actually?

    temp_v0 = malloc(4);
    temp_v0->unk0 = arg2;
    func_80679200(arg1, arg0, 0x40000, 0, 1, temp_v0);
}

void func_8067A9F0(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3, f32 arg4) {
    GlobalASMStruct31 *temp_v0;

    temp_v0 = malloc(0xC);
    temp_v0->unk0 = arg2;
    temp_v0->unk4 = arg3;
    temp_v0->unk8 = arg4;
    func_80679200(arg1, arg0, 0x100000, 0, 1, temp_v0);
}

void func_8067AA58(Actor *arg0, Actor *arg1, f32 arg2, f32 arg3) {
    GlobalASMStruct32 *temp_v0;

    temp_v0 = malloc(8);
    temp_v0->unk0 = arg2;
    temp_v0->unk4 = arg3;
    func_80679200(arg1, arg0, 0x200000, 0, 1, temp_v0);
}

void func_8067AAB8(Actor* arg0, Actor *arg1, s16 arg2, f32 arg3, s16 arg4) {
    GlobalASMStruct33 *temp_v0;

    temp_v0 = malloc(0xC);
    temp_v0->unk4 = arg3;
    temp_v0->unk8 = arg4;
    temp_v0->unk0 = arg2;
    func_80679200(arg1, arg0, 0x400, 0, 1, temp_v0);
}

void func_8067AB20(Actor *arg0, Actor *arg1, s32 arg2, u8 arg3, void *arg4, u8 arg5) {
    void *sp2C;

    sp2C = malloc(8);
    memcpy(sp2C, arg4, 8);
    if (arg5 == 0) {
        func_80679200(arg1, arg0, arg2, arg3, 1, sp2C);
        return;
    }
    func_80679290(arg1, arg0, arg2, arg3, 1, sp2C, 1);
}

void func_8067ABC0(Actor *arg0, Actor *arg1, u8 arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6, f32 arg7) {
    GlobalASMStruct34 *temp_v0;

    temp_v0 = malloc(0x10);
    temp_v0->unk0 = arg5;
    temp_v0->unk4 = arg6;
    temp_v0->unk8 = arg7;
    temp_v0->unkC = arg3;
    temp_v0->unkE = arg4;
    func_80679200(arg1, arg0, 0x800000, arg2, 1, temp_v0);
}

void func_8067AC38(void) {
    D_807FBB70.unkE5 = 0;
    D_807FBB70.unk15 = 0;
    D_807FBB70.unk16 = 0;
    D_807FBB70.unk17 = 0;
    D_807FBB70.unk18 = 0;
    D_807FBB70.unk19 = 0;
    D_807FBB70.unk1B = 0;
    D_807FBB70.unk1A = 0;
    D_807FBB70.unk1C = 0;
    D_807FBB70.unk24 = 0;
    D_807FBB70.unk25 = 0;
    D_807FBB70.unk2C = 0;
    D_807FBB70.unk38 = 0;
    D_807FBB70.unkE4 = 0;
    D_807FBB70.unk90 = 0;
    D_807FBB70.unk39 = 0;
    D_807FBB70.unk91 = 0;
    D_807FBB70.unk1F8 = 0;
    D_807FBB70.unk1FC = 0;
    D_807FBB70.unk200 = 0;
    D_807FBB70.unk201 = 0;
    D_807FBB70.unk254 = 0;
    D_807FBB70.unk2 = 0;
    D_807FBB70.unk0 = 0;
    D_807FBB70.unkE8 = 0.0f;
    D_807FBB70.unkF0 = 0.0f;
    D_807FBB70.unkF4 = 0.0f;
}

void func_8067ACB4(Actor *arg0) {
    arg0->unk6C = arg0->unk6A;
}

u16 func_8067ACC0(u16 index) {
    return D_8074D624[index];
}

s32 func_8067ACDC(Actor *arg0, u16 arg1, s32 (*arg2)(Actor *)) {
    Actor *temp_a0;
    s32 i;
    u16 count = 0;
    for (i = 0; i < D_807FBB34; i++) {
        temp_a0 = D_807FB930[i].unk0;
        if ((arg0 == temp_a0->unk11C) && (temp_a0->interactable == arg1) && ((arg2 == NULL) || (arg2(temp_a0) != 0))) {
            count++;
        }
    }
    return count;
}

Actor *func_8067ADB4(u16 arg0) {
    s32 i;
    Actor *temp;
    for (i = 0; i < D_807FBB34; i++) {
        temp = D_807FB930[i].unk0;
        if (temp->unk58 == arg0) {
            return temp;
        }
    }
    return NULL;
}

s32 func_8067AE0C(Actor *arg0) {
    s32 i;
    Actor *temp;

    i = 0;
    while (i < D_807FBB34) {
        temp = D_807FB930[i].unk0;
        if (arg0 == temp) {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

void func_8067AE58(void) { // clearActorList()
    s32 i;
    for (i = 0; i < 256; i++) {
        actor_list[i] = -1;
    }
    actor_count = 0;
}

void func_8067AE90(Actor *arg0) { // addActorToList()
    if (actor_count < 256) {
        actor_list[actor_count] = arg0;
        actor_count++;
    } else {
        func_80732354(0x13, arg0->unk58, 0, 0);
    }
    func_8067B01C();
}

void func_8067AEFC(Actor *arg0) {
    s16 temp_v0;

    temp_v0 = func_8067AF74(arg0);
    if (temp_v0 != -1) {
        actor_list[temp_v0] = -1;
        func_8067B01C();
    }
}

s32 func_8067AF44(Actor *arg0) {
    if (func_8067AF74(arg0) != -1) {
        return TRUE;
    }
    return FALSE;
}

s16 func_8067AF74(Actor *arg0) {
    s16 earlyIndex;
    s16 lateIndex;
    s16 combinedIndex;

    earlyIndex = 0;
    lateIndex = actor_count - 1;
    if (actor_count == 0) {
        return -1;
    }
    combinedIndex = lateIndex;
    if (-1 < lateIndex) {
        while (TRUE) {
            combinedIndex = earlyIndex + lateIndex >> 1;
            if (arg0 == actor_list[combinedIndex]) {
                return combinedIndex;
            }
            if (arg0 < actor_list[combinedIndex]) {
                lateIndex = combinedIndex - 1;
            } else {
                earlyIndex = combinedIndex + 1;
            }
            if (lateIndex < earlyIndex) {
                break;
            }
        } 
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_8067B01C.s")

/*
// TODO: Close
void func_8067B01C(void) {
    Actor *temp_a1;
    s32 temp_a0_2;
    s32 temp_a3;
    s16 i;
    s16 newSlot;
    Actor *phi_a3_2;
    s32 phi_v0;

    // TODO: Problem is somewhere in this loop (probably the inner loop)
    phi_v0 = FALSE;
    for (i = 1; i < actor_count; i++) {
        temp_a1 = actor_list[i];
        newSlot = i;
        phi_a3_2 = actor_list[newSlot - 1];
        while (actor_list[newSlot] < phi_a3_2) {
            phi_a3_2 = actor_list[newSlot - 1];
            newSlot--;
        }
        actor_list[newSlot] = temp_a1;
    }

    actor_count = 0;
    while (!phi_v0) {
        if ((s32)actor_list[actor_count] == -1) {
            phi_v0 = TRUE;
        } else {
            actor_count++;
        }
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_7CA80/func_8067B100.s")

extern s32 D_807ECDEC;
extern u16 D_807ECDF0;
extern CharacterProgress *D_807FD568;
extern s16 D_807FD584;

/*
// TODO: Very close
void func_8067B100(Actor *player) {
    extra_player_info_pointer = player->PaaD;
    cc_player_index = extra_player_info_pointer->unk1A4;
    D_807FBB48 = character_change_array[cc_player_index].player_pointer;
    D_807FD568 = &D_807FC950[cc_player_index].character_progress[current_character_index[cc_player_index]];
    D_807ECDEC = character_change_array[cc_player_index].unk294;
    D_807ECDF0 = character_change_array[cc_player_index].new_controller_inputs;
    D_807FD584 = D_8075C410[current_character_index[cc_player_index]].unk4;
    character_change_array[cc_player_index].unk2C1 = 0;
}
*/

u8 func_8067B1E0(Actor *arg0) {
    s32 i;
    for (i = 0; i < cc_number_of_players; i++) {
        if (character_change_array[i].does_player_exist && (arg0 == character_change_array[i].player_pointer)) {
            return i;
        }
    }
    return 0;
}

void func_8067B238(Actor *destination, Actor *source, f32 scale) {
    destination->x_position = source->x_position;
    destination->y_position = source->y_position;
    destination->z_position = source->z_position;
    destination->y_rotation = source->y_rotation;
    if (destination->animation_state) {
        destination->animation_state->scale_x = scale;
        destination->animation_state->scale_y = scale;
        destination->animation_state->scale_z = scale;
    }
}

void func_8067B280(void) {

}

void func_8067B288(void) {

}

void func_8067B290(void) {

}

void func_8067B298(void) {

}

void func_8067B2A0(void) {

}

void func_8067B2A8(void) {

}

void func_8067B2B0(s32 arg0) {

}

void func_8067B2B8(s32 arg0) {

}

s32 func_8067B2C0(s32 arg0) {
    D_807FBB44->noclip_byte = 1;
    return 1;
}

// TODO: arg0 is probably not an actor spawner, it just so happened to have a u16 at unk2 for the match
s32 func_8067B2DC(ActorSpawner *arg0) {
    if (func_806134B4(D_807FBB44, arg0->unk2, arg0)) {
        D_807FBB44->ledge_info_pointer = func_80665F24(D_807FBB44);
        D_807FBB44->unk15E = D_807FBB44->ledge_info_pointer->unkC * D_80759380 * 0.5;
        return TRUE;
    }
    return FALSE;
}

s32 func_8067B3F4(s32 arg0) {
    D_807FBB44->ledge_info_pointer = func_80665F24(D_807FBB44);
    return 1;
}

s32 func_8067B42C(s32 arg0) {
    D_807FBB44->object_properties_bitfield |= 0x2000;
    return 1;
}
