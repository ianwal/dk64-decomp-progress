#include <ultra64.h>
#include "functions.h"

void func_80627948(Actor*, s32, s32, s32);
u8 func_8070E750(u8, s32, s32);
void func_8061C464(s32, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);

extern f32 D_8002DCB8;

void *func_8068DC54(s32, s32, s32, void *, s32, void *);
s32 func_806FE078(void *, u8, s32, f32, f32, f32, f32); // extern

extern Gfx D_01000118;
extern Mtx D_02000080;
extern Mtx D_02000180;

typedef struct {
    u8 unk0[0x14 - 0x0];
    u8 unk14;
    u8 unk15;
    s16 unk16;
    u8 unk18;
    u8 unk19;
} AAD_800252A0;

void func_800252A0(Gfx *dl, Actor *arg1) {
    AAD_800252A0 *aaD;
    aaD = arg1->additional_actor_data;
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xC8, 0xC8, 0xC8, 0xFF);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(dl++, &D_01000118);
    gSPMatrix(dl++, &D_02000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_02000180, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_8068DC54(func_806FE078(dl, aaD->unk19, 8, 30.0f, 36.0f, 0.0f, 1.5f), 0x26, 0x32, &aaD->unk14, aaD->unk16, &aaD->unk18);
}

Actor* func_800253E4(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    BaaD2 *tmp;
    if (func_80677FA8(ACTOR_BANDIT_SLOT, arg0)) { // Spawn actor 219 (slot, BBB I guess?)
        tmp = D_807FBB44->BaaD2;
        D_807FBB44->x_position = arg1;
        D_807FBB44->y_position = arg2;
        D_807FBB44->z_position = arg3;
        tmp->unk0 = current_actor_pointer;
    }
    return D_807FBB44;
}

extern u8* D_8002D8B0[];

u8 func_80025480(Actor **arg0, u8 arg1) {
    return D_8002D8B0[arg1][arg0[arg1]->unk15F];
}

// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_12A0/func_800254B0.s")

extern f32 D_8002DCB4;
int func_80717404(); // TODO: Signature
extern void* D_8074E880[];

/*
void func_800254B0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 i;

    for (i = 0; i < arg3; i++) {
        func_807149B8(1);
        func_8071498C(&func_80717404);
        func_80714950(1);
        func_80714CC0(D_8074E880[((rand() >> 0xF) % 1000) % 3], D_8002DCB4, arg0, arg1, arg2);
    }
}
*/

void func_8002563C(s32 arg0) {
    PlayerAdditionalActorData *PaaD = player_pointer->PaaD;
    func_8061C464(PaaD->unk104, player_pointer, 4, 0, 0xAA, 0, 0, 0, 0, 0, D_8002DCB8);
    current_actor_pointer->control_state = 3;
    current_actor_pointer->control_state_progress = 1;
    current_actor_pointer->unk168 = 0;
}

void func_800256C4(Actor **arg0, u8 arg1) {
    u8 i;

    for (i = 0; i < 4; i++) {
        arg0[i]->control_state++;
        arg0[i]->unkF0 = arg1;
    }
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_12A0/func_8002570C.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/bonus/code_12A0/func_800261B8.s")

void func_800264E0(u8 arg0, u8 arg1) {
    playSound(0x143, 0x7FFF, 63.0f, 1.0f, 0, 0);
    func_8069D2AC(0x81, 0, 0x78, func_8070E750(0x1A, arg1, 1), 0, 0x28, 8, 8);
    current_actor_pointer->unk11C->control_state = 0;
    playSong(0x28, 1.0f);
    func_806EB0C0(0x44, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        func_80627948(player_pointer, 5, 0x21, 5);
    }
}

void func_800265C0(u8 arg0, u8 arg1) {
    u8 temp;

    current_actor_pointer->unk11C->control_state = 0;
    temp = (u8) arg1;
    func_8069D2AC(0x81, 0, 0x78, func_8070E750(0x1A, temp, 1), 0, 0x28, 8, 8);
    playSong(0x57, 1.0f);
    func_806EB0C0(0x43, NULL, 0);
    current_actor_pointer->control_state++;
    if (arg0 != 0) {
        func_80627948(player_pointer, 5, 0x21, 5);
    }
}
