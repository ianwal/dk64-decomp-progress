#include <ultra64.h>
#include "functions.h"


// Jumptable, close
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_800265F0.s")

s32 func_global_asm_806131D4(Actor *, s16);
s16 func_global_asm_80613448(Actor *);

/*
void func_minecart_800265F0(void) {
    u8 sp47;
    u8 var_t6;

    sp47 = 0x96;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        playActorAnimation(current_actor_pointer, 0x310);
        spawnActor(ACTOR_UNKNOWN_284, 0x4C);
        func_global_asm_8067B238(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale[1] * 1.5);
        last_spawned_actor->unk11C = current_actor_pointer;
        last_spawned_actor->unk168 = -1;
        last_spawned_actor->animation_state->scale[0] *= -1.0f;
        last_spawned_actor->unkEC = 0x2BC;
        func_global_asm_806131D4(last_spawned_actor, func_global_asm_80613448(last_spawned_actor));
        spawnActor(ACTOR_UNKNOWN_284, 0x4C);
        func_global_asm_8067B238(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale[1] * 1.5);
        last_spawned_actor->unk11C = current_actor_pointer;
        last_spawned_actor->unk168 = 1;
        last_spawned_actor->unkEC = 0x2BC;
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x301, 0xFF, 0x7F, 0, 0, 0.0f, 0);
        current_actor_pointer->control_state = 1;
        current_actor_pointer->z_rotation = 0x12C;
        current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
        current_actor_pointer->shadow_opacity = 0x96;
    }
    if (func_global_asm_80724A20() != 0) {
        if (extra_player_info_pointer->vehicle_actor_pointer->control_state == 5) {
            if (current_actor_pointer->control_state == 6) {
                current_actor_pointer->control_state = 5;
            } else if (current_actor_pointer->control_state == 5) {
                current_actor_pointer->control_state = 6;
            }
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            current_actor_pointer->y_position += 5.0f;
            current_actor_pointer->control_state_progress++;
            if (current_actor_pointer->control_state_progress >= 0x10) {
                current_actor_pointer->control_state = 0x3B;
            }
            break;
        case 6:
            sp47 = 0xFA;
            if (((u32)object_timer % D_global_asm_807FDC9C->unkA_u8[0]) != 0) {
                var_t6 = current_actor_pointer->unk0;
            } else {
                playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x182, 0xFF, 0x7F, 0, 0, 0.3f, 0);
                spawnActor(ACTOR_UNKNOWN_287, 0x50);
                last_spawned_actor->unk11C = current_actor_pointer;
                func_global_asm_8067B238(last_spawned_actor, current_actor_pointer, 0.06f);
                current_actor_pointer->unk15F++;
        case 2:
        case 3:
        case 4:
        case 5:
                var_t6 = current_actor_pointer->control_state_progress;
            }
            if (var_t6 == 0xFF) {
                playActorAnimation(current_actor_pointer, 0x311);
                current_actor_pointer->control_state = 1;
            }
        case 1:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, (player_pointer->y_rotation + 0x800) & 0xFFF, 8.0f);
            current_actor_pointer->x_position = ((((func_global_asm_80612794(player_pointer->y_rotation) * sp47) + player_pointer->x_position) - current_actor_pointer->x_position) * 0.3) + current_actor_pointer->x_position;
            current_actor_pointer->z_position = ((((func_global_asm_80612790(player_pointer->y_rotation) * sp47) + player_pointer->z_position) - current_actor_pointer->z_position) * 0.3) + current_actor_pointer->z_position;
            current_actor_pointer->x_position += 4.0f * func_global_asm_80612794(object_timer * 0x35);
            current_actor_pointer->z_position += 4.0f * func_global_asm_80612790(object_timer * 0x3E);
            current_actor_pointer->y_position = (func_global_asm_80612794(object_timer * 0x32) * 10.0f) + (extra_player_info_pointer->vehicle_actor_pointer->floor + 30.0f);
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

typedef struct MinecartStruct0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} MinecartStruct0;

void func_minecart_80026B6C(MinecartStruct0 *arg0, f32 arg1) {
    arg0->unkA = func_global_asm_80612794(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->x_position;
    arg0->unkC = extra_player_info_pointer->vehicle_actor_pointer->floor;
    arg0->unkE = func_global_asm_80612790(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->z_position;
}

extern s32 D_global_asm_8074E880[];

void func_minecart_80026C54(void) {
    func_global_asm_80714950(((rand() >> 0xF) % 100) + 300);
    func_global_asm_8071498C(&func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714A28(4);
    drawSpriteAtPosition(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        0.5f,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->x_position - 10.0f),
        current_actor_pointer->y_position,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->z_position - 10.0f));
}

// Jumptable, huge
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_80026DA8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_80027778.s")

void func_minecart_80027CF4(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        if (func_global_asm_8072DE10(10000) != 0 || (((D_global_asm_807FDC94->x_position - current_actor_pointer->x_position) * (D_global_asm_807FDC94->x_position - current_actor_pointer->x_position))
                + ((D_global_asm_807FDC94->y_position - current_actor_pointer->y_position) * (D_global_asm_807FDC94->y_position - current_actor_pointer->y_position))
                + ((D_global_asm_807FDC94->z_position - current_actor_pointer->z_position) * (D_global_asm_807FDC94->z_position - current_actor_pointer->z_position))) < 2500.0f) {
            playActorAnimation(current_actor_pointer, 0x280);
        }
    }
}

typedef struct {
    u8 unk0[0x34 - 0x0];
    u8 *unk34;
    u8 unk38[0x42 - 0x38];
    u8 unk42;
} AAD_minecart_80027DA0;

// TODO: Any cleanup possible?
void func_minecart_80027DA0(AAD_minecart_80027DA0 *arg0) {
    u8 temp_a2;
    AAD_minecart_80027DA0 *temp;
    PlayerAdditionalActorData *PaaD;

    PaaD = D_global_asm_807FDC94->PaaD;
    temp = PaaD->vehicle_actor_pointer->additional_actor_data;
    temp_a2 = temp->unk34[0] - 0x10;
    if (temp_a2 < arg0->unk34[0]) {
        arg0->unk42 = 1;
    } else {
        if (arg0->unk34[0] < temp_a2) {
            arg0->unk42 = 2;
        } else {
            arg0->unk42 = 0;
        }
    }
}

void func_minecart_80027E04(void) {
    u16 temp_v1;
    PlayerAdditionalActorData *PaaD = D_global_asm_807FDC94->PaaD;

    temp_v1 = current_actor_pointer->animation_state->unk1C->unk4;
    if (temp_v1 >= 0x47D1 && temp_v1 < 0xB830) {
        D_global_asm_807FDC90->unk26 = MAX(9, D_global_asm_807FDC90->unk26 - 5);
    } else if (!(temp_v1 >= 0x3830 && temp_v1 < 0xC7D1)) {
        D_global_asm_807FDC90->unk26 = MIN(D_global_asm_807FDC9C->unkD, D_global_asm_807FDC90->unk26 + 5);
    } else {
        D_global_asm_807FDC90->unk26 = PaaD->vehicle_actor_pointer->unkB8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_80027EE8.s")

typedef struct MinecartStruct1 {
    u8 pad0[0x3A];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
} MinecartStruct1;

/*
// TODO: Good progress made
void func_minecart_80027EE8(MinecartStruct1 *arg0) {
    f32 d;
    f32 dx = (current_actor_pointer->x_position - D_global_asm_807FDC94->x_position);
    f32 dy = (current_actor_pointer->y_position - D_global_asm_807FDC94->y_position);
    f32 dz = (current_actor_pointer->z_position - D_global_asm_807FDC94->z_position);

    d = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    if (d < 200.0f) {
        arg0->unk3A++;
        if (arg0->unk3A >= 9) {
            playSoundAtActorPosition(current_actor_pointer, 0x1F, 0xFF, 127.0f - (d - arg0->unk3C), 0);
            arg0->unk3A = ((func_global_asm_806119A0() / 4294967295.0) * 3.0);
        }
    }
    arg0->unk3C = d;
}
*/

s32 func_global_asm_8072177C(void *, s16, s16, s16, s32, s32, s32, s32, s32);

typedef struct {
    u8 unk0[0x10 - 0x0];
    s16 unk10;
    u8 unk12[0x34 - 0x12];
    s32 unk34;
} A178_minecart_800280BC;

void func_minecart_800280BC(void) {
    A178_minecart_800280BC *sp54;
    Struct807FBB70_unk278 *temp_v1;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    u8 *temp_v0_2;

    sp54 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80724CA4(2, 1);
        D_global_asm_807FDC90->unk35 = 6;
    }
    if (D_global_asm_807FBB70.unk15 != 0) {
        playSoundAtActorPosition(current_actor_pointer, 0xF6, 0xFF, 0x7F, 0x1E);
        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xA, 0x14);
        current_actor_pointer->control_state = 0x40;
        func_global_asm_8067E278(0, 1);
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FBB70.unk254 != 0) {
                temp_v1 = D_global_asm_807FBB70.unk278[0];
                temp_v0_2 = malloc(2);
                temp_v0_2[0] = temp_v1->unk2;
                temp_v0_2[1] = 0xFF;
                sp54->unk34 = temp_v0_2;
                sp54->unk10 = temp_v1->unk4;
                D_global_asm_807FDC90->unk26 = 0x46;
                current_actor_pointer->unkB8 = 0.0f;
                current_actor_pointer->control_state++;
            } else {
                func_global_asm_80724E48(1);
                func_minecart_80027CF4();
                renderActor(current_actor_pointer, 0);
                break;
            }
        case 1:
            func_global_asm_80724E48(1);
            func_minecart_80027CF4();
            func_minecart_80027E04();
            func_global_asm_8068ECF4(6, 0xFF);
            func_global_asm_8072B438(0x200);
            func_minecart_800253C0(sp54, 0x7FFF, 0x23);
            func_global_asm_80671C0C(current_actor_pointer, 5, &sp44, &sp48, &sp4C);
            func_global_asm_8072177C(current_actor_pointer, sp44, sp48, sp4C, 0xFF, 0xFF, 0xFF, 0xFF, 0);
            func_minecart_80027EE8(sp54);
            break;
        case 2:
            current_actor_pointer->control_state = 0x40;
            renderActor(current_actor_pointer, 0);
            break;
        default:
            renderActor(current_actor_pointer, 0);
            break;
    }
}

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_8002835C.s")

// big, structs, floats
#pragma GLOBAL_ASM("asm/nonmatchings/minecart/code_25F0/func_minecart_800286EC.s")
