#include <ultra64.h>
#include "functions.h"
#include "voiddeleteactor.h"

/* structs */
typedef struct {
    u8 unk0[0x10 - 0x0];
    u16 unk10;
    char unk12[0x1E];
    u8 *unk30;
    u8 *unk34;
    u8 unk38[2];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
    char unk3E[4];
    u8 unk42;
} AAD_minecart_80027DA0;

typedef struct MinecartStruct0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    char unk10[0x1C];
    s16 unk2C;
} MinecartStruct0;

typedef struct MinecartStruct1 {
    u8 pad0[0x3A];
    u8 unk3A;
    u8 unk3B;
    s16 unk3C;
} MinecartStruct1;

typedef struct {
    u8 unk0[0x10 - 0x0];
    s16 unk10; // Used
    s16 unk12;
    u8 unk14[0x34 - 0x14];
    u8 *unk34; // Used
} AAD_80027778;

typedef struct {
    u8 unk0[0x10 - 0x0];
    s16 unk10;
    u8 unk12[0x34 - 0x12];
    s32 unk34;
} A178_minecart_800280BC;

typedef struct {
    u8 unk0[0x88 - 0x0];
    Actor *unk88;
} AAD_800286EC;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10; // Used
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    void *unk34; // Used
} A178_800286EC;

/* variables */
extern s32 D_minecart_80028BD0;
extern s32 D_global_asm_8072030C;
extern s32 D_global_asm_80720120; // sprite
extern u8 D_global_asm_807FBB85;
extern s32 D_global_asm_8072030C; // TODO: Type
extern u8 D_global_asm_807FBD70;
extern u8 D_global_asm_807FBDC4;
extern s32 D_minecart_80028C34; // TODO: Type
extern s32 D_minecart_80028C40; // TODO: Type
extern s32 D_minecart_80028C48; // TODO: Type

/* function signatures */
void func_minecart_80024E78(AAD_minecart_80027DA0*, void*, s32, s32);
void func_minecart_800253C0(AAD_minecart_80027DA0*, s16, u8);
void func_minecart_80027EE8(AAD_minecart_80027DA0* arg0);
void func_global_asm_8061F0B0(s32, s32, s32);

void func_minecart_800265F0(void) {
    u8 sp47;

    sp47 = 0x96;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        playActorAnimation(current_actor_pointer, 0x310);
        spawnActor(ACTOR_UNKNOWN_284, 0x4C);
        moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale[1] * 1.5);
        last_spawned_actor->unk11C = current_actor_pointer;
        last_spawned_actor->unk168 = -1;
        last_spawned_actor->animation_state->scale[0] *= -1.0f;
        last_spawned_actor->unkEC = 0x2BC;
        func_global_asm_806131D4(last_spawned_actor, func_global_asm_80613448(last_spawned_actor));
        spawnActor(ACTOR_UNKNOWN_284, 0x4C);
        moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, current_actor_pointer->animation_state->scale[1] * 1.5);
        last_spawned_actor->unk11C = current_actor_pointer;
        last_spawned_actor->unk168 = 1;
        last_spawned_actor->unkEC = 0x2BC;
        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x301, 0xFF, 0x7F, 0, 0, 0.0f, 0);
        current_actor_pointer->control_state = 1;
        current_actor_pointer->z_rotation = 0x12C;
        current_actor_pointer->object_properties_bitfield &= ~0x00008000;
        current_actor_pointer->shadow_opacity = 0x96;
    }
    if (func_global_asm_80724A20()) {
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
            if (current_actor_pointer->control_state_progress++ >= 0x10) {
                current_actor_pointer->control_state = 0x3B;
            }
            break;
        case 6:
            sp47 = 0xFA;
            if (((u32)object_timer % D_global_asm_807FDC9C->unkA_u8[0]) == 0) {
                playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x182, 0xFF, 0x7F, 0, 0, 0.3f, 0);
                spawnActor(ACTOR_UNKNOWN_287, 0x50);
                last_spawned_actor->unk11C = current_actor_pointer;
                moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, 0.06f);
                current_actor_pointer->unk15F++;
            }
        case 2:
        case 3:
        case 4:
        case 5:
            if (current_actor_pointer->control_state_progress == 0xFF) {
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

void func_minecart_80026B6C(MinecartStruct0 *arg0, f32 arg1) {
    arg0->unkA = func_global_asm_80612794(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->x_position;
    arg0->unkC = extra_player_info_pointer->vehicle_actor_pointer->floor;
    arg0->unkE = func_global_asm_80612790(player_pointer->y_rotation) * (extra_player_info_pointer->vehicle_actor_pointer->unkB8 * arg1) + player_pointer->z_position;
}

void func_minecart_80026C54(void) {
    func_global_asm_80714950(((rand() >> 0xF) % 100) + 300);
    func_global_asm_8071498C(func_global_asm_80717D4C);
    func_global_asm_807149B8(1);
    func_global_asm_80714A28(4);
    drawSpriteAtPosition(
        D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        0.5f,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->x_position - 10.0f),
        current_actor_pointer->y_position,
        ((rand() >> 0xF) % 20) + (current_actor_pointer->z_position - 10.0f)
    );
}

void func_minecart_80026DA8(void) {
    char pad[4];
    MinecartStruct0* sp68;
    s16 sp66;
    char pad1[4];
    char pad2[4];
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    char pad3[4];
    Actor* a11C;
    f32 temp_f12;
    f32 temp_f16;
    f32 var_f2;

    s16* temp_s0_2; //unknown type

    a11C = current_actor_pointer->unk11C;
    sp68 = a11C->additional_actor_data;
    sp66 = current_actor_pointer->unk168 * current_actor_pointer->unkEC;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80613C48(current_actor_pointer, 0x59C, 0.0f, 0.0f);
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        current_actor_pointer->object_properties_bitfield &= ~0x00008000;
        current_actor_pointer->shadow_opacity = 0x96;
    }
    current_actor_pointer->y_rotation = a11C->y_rotation;
    current_actor_pointer->x_position = ((func_global_asm_80612794(a11C->y_rotation + sp66) * 47.0f + a11C->x_position) - current_actor_pointer->x_position) * 0.3 + current_actor_pointer->x_position;
    current_actor_pointer->z_position =  ((func_global_asm_80612790(a11C->y_rotation + sp66) * 47.0f + a11C->z_position) - current_actor_pointer->z_position) * 0.3 + current_actor_pointer->z_position;
    current_actor_pointer->y_position =  current_actor_pointer->y_position + (a11C->y_position - 10.0f - current_actor_pointer->y_position) * 0.3;
    switch (a11C->control_state) {
        case 0x2:
        case 0x3:
            if (((current_actor_pointer->unk168 == 1) && (a11C->control_state == 2)) || ((current_actor_pointer->unk168 == -1) && (a11C->control_state == 3))) {
                temp_s0_2 = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
                func_minecart_80026C54();
                switch (a11C->control_state_progress) {
                    case 0:
                        if (*temp_s0_2 == NULL) {
                            current_actor_pointer->control_state_progress = 0;
                            playActorAnimation(current_actor_pointer, 0x312);
                            a11C->control_state_progress = 1;
                            func_minecart_80026B6C(sp68, 2.2f);
                        }
                        break;
                    case 1:     
                        var_f2 = (current_actor_pointer->animation_state->unk0->unk4 / 17.0 > 1.0) ? 1.0 : current_actor_pointer->animation_state->unk0->unk4 / 17.0;
                        temp_f16 = func_global_asm_80612790(var_f2 * 2048.0f + 2048.0f) * 0.5 + 0.5;
                        current_actor_pointer->x_position = ((sp68->unkA - current_actor_pointer->x_position) * temp_f16) + current_actor_pointer->x_position;
                        current_actor_pointer->y_position = 10.0f + current_actor_pointer->y_position + ((extra_player_info_pointer->vehicle_actor_pointer->floor - (10.0f + current_actor_pointer->y_position)) * temp_f16);
                        current_actor_pointer->z_position = ((sp68->unkE - current_actor_pointer->z_position) * temp_f16) + current_actor_pointer->z_position;
                        if ((player_pointer->animation_state->unk64 == 0x294) || (( (current_actor_pointer->animation_state->unk0->unk4 > 16.0f)) && (current_actor_pointer->animation_state->unk0->unk4 < 18.0f))) {
                            current_actor_pointer->unk132 = 1;
                        } else {
                            current_actor_pointer->unk132 = 0;
                        }
                        if (current_actor_pointer->control_state_progress != 0) {
                            a11C->control_state_progress = 0xFF;
                        }
                        break;
                }
            }
            break;
        case 0x4:
        case 0x5:
            if (((current_actor_pointer->unk168 == 1) && (a11C->control_state == 4)) || ((current_actor_pointer->unk168 == -1) && (a11C->control_state == 5))) {
                func_minecart_80026C54();
                switch (a11C->control_state_progress) {
                    case 0:
                        sp68->unk2C = 0x46;
                        a11C->control_state_progress = 1;
                        current_actor_pointer->unk132 = 1;
                        playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0x301, 0xFFU, 0x7F, 0U, 0U, 0.0f, 0U);
                        // fallthrough
                    case 1:
                        func_minecart_80026B6C(sp68, 0.3f);
                        if (sp68->unk2C--) {
                            sp58 = func_global_asm_80612790(sp68->unk2C / 70.0 * 2048.0 + 2048.0) * 0.5 + 0.5;
                            sp54 = func_global_asm_80612794((2048.0f * sp58));
                            sp50 = func_global_asm_80612794(sp58 * 1536.0f + 1024.0f) * (current_actor_pointer->unk168 * -0x6E);
                            sp4C = (func_global_asm_80612790(sp58 * 4096.0f) * 0.5 + 0.5) * 50.0 + -30.0;
                            current_actor_pointer->x_position = ((((func_global_asm_80612794((player_pointer->y_rotation - 0x400)) * sp50) + sp68->unkA) - current_actor_pointer->x_position) * sp54) + current_actor_pointer->x_position;
                            current_actor_pointer->y_position = current_actor_pointer->y_position + (((extra_player_info_pointer->vehicle_actor_pointer->floor + sp4C) - current_actor_pointer->y_position) * sp54);
                            current_actor_pointer->z_position = ((((func_global_asm_80612790((s16) (player_pointer->y_rotation - 0x400)) * sp50) + sp68->unkE) - current_actor_pointer->z_position) * sp54) + current_actor_pointer->z_position;
                            if (sp68->unk2C < 0x10) {
                                current_actor_pointer->unk132 = 0;
                            }
                        } else {
                            a11C->control_state_progress = 0xFF;
                        }
                        break;
                }
                if (current_actor_pointer->unk168 == 1) {
                    current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, 0xC00, 7.0f);
                } else {
                    current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, 0x400, 7.0f);
                }
            }
            break;
        case 0x6:
            if (a11C->control_state_progress == 0) {
                sp68->unk2C = D_global_asm_807FDC9C->unkA_u8[1];
                a11C->control_state_progress = 1;
            }
            if (current_actor_pointer->unk168 == 1) {
                current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, 0xC00, 16.0f);
            } else {
                current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, 0x400, 16.0f);
            }
            if (sp68->unk2C != 0) {
                sp68->unk2C--;
            } else {
                a11C->control_state_progress = 0xFF;
            }
            if ((current_actor_pointer->control_state_progress == 0) && (a11C->unk15F == 4)) {
                extra_player_info_pointer->unk1F0 |= 0x10000000;
                current_actor_pointer->unk15F = 0xB4;
                current_actor_pointer->control_state_progress++;
            }
            current_actor_pointer->unkEC = func_global_asm_806CC190(current_actor_pointer->unkEC, 0x64, 10.0f);
            break;
        case 0x3B:
            deleteActor(current_actor_pointer);
            break;
        case 1:
            break;
    }
    if (a11C->control_state == 6) {
        if (current_actor_pointer->unk15F != 0) {
            current_actor_pointer->unk15F = current_actor_pointer->unk15F - 0xC;
            func_global_asm_8061C464(extra_player_info_pointer->unk104, extra_player_info_pointer->vehicle_actor_pointer, 4, (s32) (s16) ((s32) (current_actor_pointer->unk15F << 0xC) / 360), 0x64, 0, 5, 0x23, 0x14, 0, 0.2f);
        }
    }
    if (a11C->control_state != 6) {
        if (current_actor_pointer->x_rotation != 0) {
            current_actor_pointer->x_rotation = func_global_asm_806CC190(current_actor_pointer->x_rotation, 0, 8.0f);
            current_actor_pointer->unkEC = func_global_asm_806CC190(current_actor_pointer->unkEC, 0x2BC, 10.0f);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_minecart_80027778(void) {
    f32 temp;
    f32 dx;
    AAD_80027778 *aaD;
    f32 dy;
    s16 sp5E;
    s16 sp5C;

    aaD = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    sp5E = D_global_asm_807F5FD4->unk0[current_actor_pointer->unk15F][current_actor_pointer->unk168].unk0;
    sp5C = D_global_asm_807F5FD4->unk0[current_actor_pointer->unk15F][current_actor_pointer->unk168].unk8;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_80613C48(current_actor_pointer, 0x5FF, 0.0f, 0.0f);
        func_global_asm_80688370(current_actor_pointer, 0, 1.0f);
        func_global_asm_806883C8(current_actor_pointer, 0, 0);
        func_global_asm_8068842C(current_actor_pointer, 0, -1);
        current_actor_pointer->noclip_byte = 0x24;
        if (current_actor_pointer->unk11C->unk15F == 1) {
            current_actor_pointer->unk15F = *aaD->unk34 & 0xFF3F;
        } else {
            switch (*aaD->unk34 & ~0xC0) {
                case 1:
                case 2:
                    current_actor_pointer->unk15F = (current_actor_pointer->unk11C->unk15F ^ 1) + 1;
                    break;
                case 3:
                case 4:
                case 5:
                case 6:
                    current_actor_pointer->unk15F = (current_actor_pointer->unk11C->unk15F % 4) + 3;
                    break;
                case 7:
                case 8:
                    current_actor_pointer->unk15F = (current_actor_pointer->unk11C->unk15F ^ 1) + 7;
                    break;
            }
        }
        current_actor_pointer->unk168 = MAX(0, aaD->unk10 - 2);
        current_actor_pointer->unkB8 = 1100.0f;
        current_actor_pointer->y_velocity = 400.0f;
        current_actor_pointer->object_properties_bitfield |= 0x800000;
        current_actor_pointer->unk16A = 0xFF;
        current_actor_pointer->unk16B = 0xFF;
        current_actor_pointer->unk16C = 0xFF;
        current_actor_pointer->y_acceleration = -10.0f;
        current_actor_pointer->terminal_velocity = -200.0f;
        current_actor_pointer->unkF0 = 0xB4;
        current_actor_pointer->unkEC = 0;
    }
    if (((u32)object_timer % 3U) == 0) {
        func_global_asm_807149B8(1);
        drawSpriteAtPosition(&D_global_asm_80720120, 1.0f, current_actor_pointer->x_position, current_actor_pointer->y_position + 10.0f, current_actor_pointer->z_position);
    }
    dx = sp5E;
    dy = sp5C;
    current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, func_global_asm_80665DE0(dx, dy, current_actor_pointer->x_position, current_actor_pointer->z_position), 6.0f);
    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    func_global_asm_80729E6C();
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, (2.0 * func_global_asm_80612794(object_timer * 0x64)) + 10.0);
    //dy and dx loads are flipped
    dy = sp5E - current_actor_pointer->x_position;
    dx = sp5C - current_actor_pointer->z_position;
    if (((dy * dy) + (dx * dx)) < 1600.0f) {
        current_actor_pointer->unk168++;
    }
    if ((D_global_asm_807FBB85 != 0) || (current_actor_pointer->unkF0 -= 1, (current_actor_pointer->unkF0 == 0))) {
        if (current_actor_pointer->unk11C != NULL) {
            current_actor_pointer->unk11C->unk15F -= 1;
        }
        if ((current_actor_pointer->unk11C == NULL) || (current_actor_pointer->unk11C->unk15F == 0)) {
            if (extra_player_info_pointer->unk1F0 & 0x10000000) {
                extra_player_info_pointer->unk1F0 &= ~0x10000000;
                func_global_asm_8061C6A8(extra_player_info_pointer->unk104, extra_player_info_pointer->vehicle_actor_pointer, 4, 0x800, 0x28, 0, 5, 0x19, 0x14, 0, 0.15f);
            }
        }
        func_global_asm_8067E278(0, 1);
        deleteActor(current_actor_pointer);
    }
    
    dx = (current_actor_pointer->x_position - character_change_array->look_at_eye_x);
    dx = dx * dx;
    dy = (current_actor_pointer->y_position - character_change_array->look_at_eye_y);
    dx = dy * dy + dx;
    dy = (current_actor_pointer->z_position - character_change_array->look_at_eye_z);
    dx = dy * dy + dx;
    switch (current_actor_pointer->unkEC) {
        case 0:
        case 2:
            if (dx < 6400.0f) {
                playSoundAtActorPosition(current_actor_pointer, 0x128, 0xFF, 0x7F, 0);
                current_actor_pointer->unkEC++;
            }
            break;
        case 1:
            if (dx > 10000.0f) {
                current_actor_pointer->unkEC++;
            }
    }
    renderActor(current_actor_pointer, 0);
}

void func_minecart_80027CF4(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        if (func_global_asm_8072DE10(10000) != 0 || (((D_global_asm_807FDC94->x_position - current_actor_pointer->x_position) * (D_global_asm_807FDC94->x_position - current_actor_pointer->x_position))
                + ((D_global_asm_807FDC94->y_position - current_actor_pointer->y_position) * (D_global_asm_807FDC94->y_position - current_actor_pointer->y_position))
                + ((D_global_asm_807FDC94->z_position - current_actor_pointer->z_position) * (D_global_asm_807FDC94->z_position - current_actor_pointer->z_position))) < 2500.0f) {
            playActorAnimation(current_actor_pointer, 0x280);
        }
    }
}

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

void func_minecart_80027EE8(AAD_minecart_80027DA0 *arg0) {
    f32 dx, dy;
    
    dx = (current_actor_pointer->x_position - D_global_asm_807FDC94->x_position);
    dx = dx * dx;
    dy = (current_actor_pointer->y_position - D_global_asm_807FDC94->y_position);
    dx = dy * dy + dx;
    dy = (current_actor_pointer->z_position - D_global_asm_807FDC94->z_position);
    dx = dy * dy + dx;

    dx = sqrtf(dx);
    if (dx < 200.0f) {
        arg0->unk3A++;
        if (arg0->unk3A >= 9) {
            playSoundAtActorPosition(current_actor_pointer, 0x1F, 0xFF, 127.0f - (dx - arg0->unk3C), 0);
            arg0->unk3A = ( (func_global_asm_806119A0() / 4294967295.0) * 3.0);
        }
    }
    arg0->unk3C = dx;
}

void func_minecart_800280BC(void) {
    A178_minecart_800280BC *sp54;
    Struct807FBB70_unk278 *temp_v1;
    f32 z, y, x;
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
            getBonePosition(current_actor_pointer, 5, &x, &y, &z);
            addActorRecolor(current_actor_pointer, x, y, z, 0xFF, 0xFF, 0xFF, 0xFF, 0);
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

void func_minecart_8002835C(void) {
    AAD_minecart_80027DA0* sp74;
    Struct807FBB70_unk278* temp_v1;
    f32 z2, y2, x2;
    f32 z1, y1, x1;
    u8* temp_v0_2;
    char pad[12];
    
    sp74 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if ((current_map == MAP_MINECART_MAYHEM_EASY) || (current_map == MAP_MINECART_MAYHEM_NORMAL) || (current_map == MAP_MINECART_MAYHEM_HARD)) {
            func_global_asm_8066E9EC(current_actor_pointer, 1, 50.0f);
        }
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714C08(&D_global_asm_8072030C, 0.14f, current_actor_pointer, 0xB, 2);
        current_actor_pointer->control_state = 0;
    }
    if ((D_global_asm_807FBB70.unk200 == 9) || (D_global_asm_807FBB70.unk15 != 0)) {
        func_global_asm_8067E278(0, 1);
        current_actor_pointer->control_state = 0x40;
        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xA, 0x14);
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FBB70.unk254 != 0) {
                temp_v1 = D_global_asm_807FBB70.unk278[0];
                temp_v0_2 = (u8*)malloc(4);
                temp_v0_2[0] = temp_v1->unk2;
                temp_v0_2[1] = 0xFF;
                sp74->unk30 = temp_v0_2;
                sp74->unk34 = temp_v0_2;
                sp74->unk10 = 1;
                D_global_asm_807FDC90->unk26 = temp_v1->unk4;
                current_actor_pointer->unkB8 = 0.0f;
                current_actor_pointer->control_state++;
                // fallthrough
            } else {
                renderActor(current_actor_pointer, 0);
                return;
            }
            case 1:
                if ((current_map == MAP_MINECART_MAYHEM_EASY) || (current_map == MAP_MINECART_MAYHEM_NORMAL) || (current_map == MAP_MINECART_MAYHEM_HARD)) {
                    func_minecart_80027DA0(sp74);
                    func_minecart_80024E78(sp74, &D_minecart_80028BD0, 0, 3);
                    getBonePosition(current_actor_pointer, 1, &x1, &y1, &z1);
                    getBonePosition(current_actor_pointer, 2, &x2, &y2, &z2);
                }
                func_global_asm_8072B438(0x200);
                func_minecart_800253C0(sp74, 0x7FFF, 0x23);
                if ((current_actor_pointer->control_state == 2) && ((current_map == MAP_MINECART_MAYHEM_EASY) || (current_map == MAP_MINECART_MAYHEM_NORMAL) || (current_map == MAP_MINECART_MAYHEM_HARD))) {
                    current_actor_pointer->control_state = 1;
                    sp74->unk34--;
                }
                getBonePosition(current_actor_pointer, 5, &x1, &y1, &z1);
                addActorRecolor(current_actor_pointer, x1, y1, z1, 255, 255, 255, 255, 0);
                func_minecart_80027EE8(sp74);
                return;

        case 2:
            current_actor_pointer->control_state = 0x40;
            renderActor(current_actor_pointer, 0);
            return;
        default:
            renderActor(current_actor_pointer, 0);
            return;
    }
}

void func_minecart_800286EC(void) {
    A178_800286EC *a178;
    f32 dx;
    f32 z, y, x;
    AAD_800286EC *aaD;
    f32 dz;

    a178 = current_actor_pointer->unk178;
    initializeCharacterSpawnerActor();
    aaD = D_global_asm_807FDC94->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->noclip_byte = 0x3C;
        D_global_asm_807FDC90->unk35 = 2;
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(-1);
        func_global_asm_80714C08(&D_global_asm_8072030C, 0.14f, current_actor_pointer, 0xB, 2);
    }
    if (D_global_asm_807FBD70 == 4) {
        playSoundAtActorPosition(current_actor_pointer, 0xF6, 0xFF, 0x7F, 0x1E);
        func_global_asm_8061F0B0(D_global_asm_807F5D10, 0xA, 0x14);
        current_actor_pointer->unkB8 = -ABS(current_actor_pointer->unkB8 * 1.2);
        setAction(0x34, current_actor_pointer, 0);
    }
    func_global_asm_80724A20();
    switch (current_actor_pointer->control_state) {
        case 0:
            if (D_global_asm_807FBDC4) {
                switch (current_map) {
                    case MAP_FUNGI_MINECART:
                        a178->unk34 = &D_minecart_80028C40;
                        break;
                    case MAP_CASTLE_MINECART:
                        a178->unk34 = &D_minecart_80028C48;
                        break;
                    default:
                        a178->unk34 = &D_minecart_80028C34;
                }
                a178->unk10 = 1;
                current_actor_pointer->unkB8 = 0.0f;
                current_actor_pointer->control_state++;
                // fallthrough
            } else {
                renderActor(current_actor_pointer, 0);
                return;
            }
        case 1:
            if (D_global_asm_807FBDC4) {}
            if ((func_global_asm_806CC14C(func_global_asm_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position), current_actor_pointer->y_rotation) >= 0x201) && (dx = current_actor_pointer->x_position - player_pointer->x_position, dz = current_actor_pointer->z_position - player_pointer->z_position, (((dx * dx) + (dz * dz)) < 22500.0f))) {
                D_global_asm_807FDC90->unk26 = 0;
            } else {
                D_global_asm_807FDC90->unk26 = MIN(MAX(aaD->unk88->unkB8 * 1.4, 45.0), 90.0);
            }
            func_global_asm_8072B438(0x200);
            func_global_asm_8068ECF4(6, 0xFF);
            func_minecart_800253C0(a178, 0x7FFF, 0x23);
            getBonePosition(current_actor_pointer, 5, &x, &y, &z);
            addActorRecolor(current_actor_pointer, x, y, z, 0xFF, 0xFF, 0xFF, 0xFF, 0);
            if ((player_pointer->control_state == 0x70) || (a178->unk10 == 0x90)) {
                current_actor_pointer->control_state++;
            }
            return;
        case 2:
            func_global_asm_8067E278(0, 1);
            current_actor_pointer->control_state = 0x40;
            renderActor(current_actor_pointer, 0);
            return;
    }
    renderActor(current_actor_pointer, 0);
}
