#include <ultra64.h>
#include "functions.h"

typedef struct BoulderAAD {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Actor *unkC;
    Actor *unk10;
    u16 unk14;
    u16 unk16;
    u32 unk18;
    u16 unk1C;
    s8 unk1E;
} BoulderAAD;

extern s32 D_global_asm_8071FF18;
extern s32 D_global_asm_8072014C;

extern void *D_global_asm_8074E880[];

extern u8 D_global_asm_80750AB8;
extern f32 D_global_asm_80750FC0;
extern s32 D_global_asm_80750FC4; // TODO: Datatype
extern s32 D_global_asm_80750FC8;
extern s32 D_global_asm_80750FCC;
extern s32 D_global_asm_80750FD0;
extern u8 D_global_asm_80750FD4;
extern f32 D_global_asm_80750FD8;
extern s32 D_global_asm_80750FDC;
extern s32 D_global_asm_80750FE0[];

// .data
extern f32 D_global_asm_80753024[];
extern f32 D_global_asm_8075305C[];
extern f32 D_global_asm_80753094[];
extern f32 D_global_asm_807530F0[];
extern f32 D_global_asm_80753144[];
extern f32 D_global_asm_807531E0[];
extern f32 D_global_asm_807531FC[]; // Kong Walking Maximum Velocity
extern f32 D_global_asm_80753234[];
extern f32 D_global_asm_80753250[];
extern s16 D_global_asm_8075326C[];
extern f32 D_global_asm_8075327C[];
extern s16 D_global_asm_80753298[];
extern f32 D_global_asm_8075339C[];
extern f32 D_global_asm_807533B8[];
extern f32 D_global_asm_80753380[];
extern f32 D_global_asm_80753364[];
extern f32 D_global_asm_807533D4[];
extern f32 D_global_asm_807533F0[];
extern f32 D_global_asm_80753454[];
extern f32 D_global_asm_80753470[];
extern f32 D_global_asm_8075348C[];
extern s16 D_global_asm_807534A8[];
extern f32 D_global_asm_8075352C[];
extern s16 D_global_asm_80753548[];
extern f32 D_global_asm_80753604[];
extern f32 D_global_asm_80753620[];
extern f32 D_global_asm_8075363C[];
extern f32 D_global_asm_80753674[];
extern f32 D_global_asm_80753690[];
extern f32 D_global_asm_807536C8[];
extern f32 D_global_asm_807536E4[];
extern f32 D_global_asm_80753738[];
extern s16 D_global_asm_8075387C[];
extern s16 D_global_asm_8075388C[];
extern s16 D_global_asm_807538B8[];
extern s16 D_global_asm_807538C8[];
extern s16 D_global_asm_807539DC[];
extern s16 D_global_asm_807539EC[];
extern f32 D_global_asm_80753A5C[];
extern f32 D_global_asm_80753AFC[];
extern f32 D_global_asm_80753CB4[];

extern s32 D_global_asm_80767CC0;
extern s32 D_global_asm_807FBB68;
extern f32 D_global_asm_807FBC58;
extern s16 D_global_asm_807FD584; // index into a ton of arrays

void func_global_asm_806F91B4(s32, s32, s16);
void func_global_asm_80665160(Actor *, s16, s16);
f32 func_global_asm_806CD898(f32 currentSpeed, f32 desiredSpeed, f32 boostAmount); // boostSpeed
void func_global_asm_806CEE64(f32);
void func_global_asm_806CFD68(void);
void func_global_asm_806EAB44(Actor *arg0, u8 arg1);
s32 func_global_asm_806DF6D4(s32 arg0);
void func_global_asm_806CC948();
void func_global_asm_806CFECC(void);
u8 func_global_asm_806CDD24(Actor *arg0, f32 arg1, f32 arg2, s32 arg3);
void func_global_asm_806CD8EC(void);
void func_global_asm_806CD424(s16, f32, f32); // TODO: Is this signature correct?
void func_global_asm_806CC638(f32 arg0);
f32 func_global_asm_806F46B0(s16 arg0);
void func_global_asm_807149FC(s32);
void func_global_asm_806224CC(s32, Actor*);
s16 func_global_asm_806CC190(s16, s16, f32);
void func_global_asm_80613AF8(Actor*, s32, f32, f32);
void func_global_asm_806D9924(Actor*);
void func_global_asm_80659620(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3);

void func_global_asm_806D2BD0(void) {
    func_global_asm_806D2954(0xC);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
    if (func_global_asm_8061CB50()) {
        if (current_actor_pointer->unk6E[0] != -1) {
            func_global_asm_80605314(current_actor_pointer, 0);
        }
    }
    if (is_autowalking == 3) {
        func_global_asm_806C9F74(current_actor_pointer);
    }
}

void func_global_asm_806D2C54(void) {
    func_global_asm_806D2A14(0x10);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
    if (is_autowalking == 3) {
        func_global_asm_806C9F74(current_actor_pointer);
    }
}

void func_global_asm_806D2CAC(void) {
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    func_global_asm_806D2954(0xD);
    func_global_asm_806CC638(D_global_asm_80753A5C[D_global_asm_807FD584]);
    if (func_global_asm_806D850C()) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2D38(void) {
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    func_global_asm_806D2A14(0x11);
    func_global_asm_806CC638(D_global_asm_80753A5C[D_global_asm_807FD584]);
    if (func_global_asm_806D850C()) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2DC4(void) {
    u8 newControlState;
    s32 phi_a1;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    current_actor_pointer->unk64 |= 0x200;
    phi_a1 = 0x13;
    if (current_actor_pointer->control_state_progress != 0) {
        current_actor_pointer->control_state_progress--;
        phi_a1 = 0x14;
    }
    if (object_timer > 1U && !func_global_asm_806DF6D4(phi_a1)) {
        newControlState = func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0xC) {
            current_actor_pointer->control_state = newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D2E9C(void) {
    f32 var_f2;
    s32 var_a1;
    s32 var_v0;
    f32 temp;
    f64 temp2;

    if (D_global_asm_807FBB68 & 2) {
        temp2 = (current_actor_pointer->y_position - 120.0f) * 0.5;
        var_f2 = MAX((temp2), 0.0);
        temp = 590.0f - var_f2;
        if (current_actor_pointer->x_position < temp) {
            current_actor_pointer->x_position = temp;
        }
        temp = 987.0f + var_f2;
        if (temp < current_actor_pointer->x_position) {
            current_actor_pointer->x_position = temp;
        }
        temp = 571.0f - var_f2;
        if (current_actor_pointer->z_position < temp) {
            current_actor_pointer->z_position = temp;
        }
        temp = 965.0f + var_f2;
        if (temp < current_actor_pointer->z_position) {
            current_actor_pointer->z_position = temp;
        }
        current_actor_pointer->noclip_byte &= 0xFFF7;
    }
    func_global_asm_806DF6D4(0x1B);

    if (func_global_asm_806F46B0(player_pointer->unk12C) < current_actor_pointer->y_position) {
        current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
        if (current_actor_pointer->y_velocity > 0.0f) {
            current_actor_pointer->y_velocity *= 0.7;
        }
    }
    if (extra_player_info_pointer->unk1A2 != 0) {
        var_v0 = extra_player_info_pointer->unk1A0;
        if (var_v0 >= 0x8000) {
            var_v0 += 0xFFFF0000;
        }
        var_v0 += 0x9E8;
        if (var_v0 >= 0x7D1) {
            var_a1 = 0x7D;
        } else if (var_v0 < -0x7D0) {
            var_a1 = 0x80;
        } else {
            var_a1 = 0x7F;
        }
    } else {
        var_a1 = 0x7E;
    }
    if ((var_a1 != current_actor_pointer->animation_state->unk64) && (current_actor_pointer->animation_state->unk64 != 0x81)) {
        func_global_asm_80614EBC(current_actor_pointer, var_a1);
    }
    if ((extra_player_info_pointer->unk1F0 & 0x40000000) && (extra_player_info_pointer->unk240 == 0)) {
        func_global_asm_80687400();
        extra_player_info_pointer->unk240 = 0x1E;
    }
    if (extra_player_info_pointer->unk240 != 0) {
        extra_player_info_pointer->unk240--;
    }
    if ((current_actor_pointer->unk6A & 1) || (extra_player_info_pointer->unk240 == 1)) {
        if (D_global_asm_807FBB68 & 2) {
            current_actor_pointer->noclip_byte |= 8;
        }
        func_global_asm_806CFF9C(current_actor_pointer);
        func_global_asm_80608528(current_actor_pointer, 1, 0xFF, 0x7F, 0x1E);
    }
    if (func_global_asm_8061CB50() == 0) {
        func_global_asm_806CC948();
        if ((func_global_asm_806F8AD4(5, cc_player_index) != 0) && !(extra_player_info_pointer->unk1F0 & 0x10000)) {
            func_global_asm_806F91B4(5, cc_player_index, -1);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3224(void) {
    u32 newControlState;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    if (func_global_asm_806DF6D4(0x1D) == 0) {
        newControlState = func_global_asm_806CE174(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0x5D) {
            current_actor_pointer->control_state = (u8)newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D32C0(void) {
    if ((current_map == MAP_BUSY_BARREL_BARRAGE_EASY)
        || (current_map == MAP_BUSY_BARREL_BARRAGE_NORMAL)
        || (current_map == MAP_BUSY_BARREL_BARRAGE_HARD)) {
        func_global_asm_806DF6D4(0x1F);
    } else {
        func_global_asm_806DF6D4(0x1E);
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D332C(void) {
    u32 newControlState;

    if (current_actor_pointer->control_state_progress == 0) {
        current_actor_pointer->control_state_progress++;
        extra_player_info_pointer->unkC = -1;
        extra_player_info_pointer->unkE = -1;
    }
    if (func_global_asm_806DF6D4(0x13) == 0) {
        newControlState = func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0xD) {
            current_actor_pointer->control_state = (u8)newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    if ((!func_global_asm_8061CB50())
        && (D_global_asm_807531E0[D_global_asm_807FD584] < current_actor_pointer->unkB8)
        && (D_global_asm_807531E0[D_global_asm_807FD584] < extra_player_info_pointer->unk4)
        && (extra_player_info_pointer->unkC >= 0)
        && (func_global_asm_806CC14C(extra_player_info_pointer->unkC, extra_player_info_pointer->unkA) >= 0x401)
        && (func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unkA) >= 0x539)) {
        current_actor_pointer->control_state = 0xE;
        current_actor_pointer->control_state_progress = 0;
        func_global_asm_806CC948();
    } else {
        func_global_asm_806CC8B8();
    }
    extra_player_info_pointer->unkC = extra_player_info_pointer->unkE;
    extra_player_info_pointer->unkE = extra_player_info_pointer->unkA;
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D34B4(void) {
    u32 newControlState;
    if (func_global_asm_806DF6D4(0x1C) == 0) {
        newControlState = func_global_asm_806CE174(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0x5E) {
            current_actor_pointer->control_state = (u8)newControlState & 0xFF;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3530(void) {
    if (((current_actor_pointer->unk9C - current_actor_pointer->y_position) > 50.0f) && (current_actor_pointer->distance_from_floor > 250.0f)) {
        extra_player_info_pointer->unk42++;
    } else {
        extra_player_info_pointer->unk42 = 0;
    }
    if ((extra_player_info_pointer->unk42++ >= 0xB) || (current_actor_pointer->y_position < -10.0f)) {
        func_global_asm_806EB0C0(0x2D, NULL, cc_player_index);
    }
}

void func_global_asm_806D3608(void) {
    f32 temp_f0 = current_actor_pointer->animation_state->scale_y / 0.15;
    if ((D_global_asm_807FBB64 << 0xD) >= 0) {
        if (!func_global_asm_8061CB50()) {
            if (current_map == MAP_AZTEC_BEETLE_RACE) {
                func_global_asm_806D3530();
                return;
            }
            if ((290.0f * temp_f0) < (current_actor_pointer->unk9C - current_actor_pointer->y_position)) {
                func_global_asm_806EB0C0(0x2C, NULL, cc_player_index);
            }
        }
    }
}

void func_global_asm_806D36CC(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x20);
            func_global_asm_806D3608();
            break;
        case 1:
            func_global_asm_806DF6D4(0x31);
            func_global_asm_806CFE7C();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D374C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x20);
            func_global_asm_806D3608();
            break;
        case 1:
            func_global_asm_806DF6D4(0x32);
            func_global_asm_806CFE7C();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D37CC(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_806DF6D4(0x20);
        func_global_asm_806CC8B8();
        if (current_actor_pointer->unk6A & 1) {
            if (current_actor_pointer->unkE0 != 0.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            } else {
                func_global_asm_806CFE7C();
                func_global_asm_806EB0C0(0x35, NULL, cc_player_index);
            }
        }
    } else {
        func_global_asm_806DF6D4(0x20);
        extra_player_info_pointer->unk4 = 0.0f;
        current_actor_pointer->unkB8 = 0.0f;
        func_global_asm_806CC8B8();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D38AC(s32 arg0) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    current_actor_pointer->unkF8 = 0x12C;
    if ((current_actor_pointer->y_position - current_actor_pointer->floor) > 5.0f) {
        if (current_actor_pointer->y_acceleration == -260.0f) {
            func_global_asm_806CFE7C();
        } else if (current_actor_pointer->y_acceleration != -30.0f) {
            current_actor_pointer->unk6A |= 0x1000;
        } else {
            if (current_actor_pointer->y_velocity > 0.0f) {
                current_actor_pointer->y_velocity = 0.0f;
            } else {
                current_actor_pointer->y_velocity = current_actor_pointer->y_velocity;
            }
        }
        current_actor_pointer->control_state = 0x14;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = current_actor_pointer->y_velocity;
        extra_player_info_pointer->unk50 = 0;
        func_global_asm_80614E78(current_actor_pointer, 0x67);
    }
    func_global_asm_806DF6D4(arg0);
    func_global_asm_806CC8B8();
    if ((current_actor_pointer->unk6A & 0x200) == 0) {
        func_global_asm_806CFF9C(current_actor_pointer);
        func_global_asm_80605314(current_actor_pointer, 0);
        func_global_asm_806224CC(extra_player_info_pointer->unk104, current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3A38(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_8061C464(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x800, 0x32, 0, 5, 0x32, 0x14, 0, 0.2f);
        current_actor_pointer->control_state_progress++;
    }
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3AC8() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3AE8() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B08() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B28() {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B48(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    current_actor_pointer->control_state_progress++;
    if (current_actor_pointer->control_state_progress == 0x32) {
        RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
        RaaD->unk45 = 1;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3BC8(void) {
    func_global_asm_806DF6D4(0x3E);
    func_global_asm_806CC8B8();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            if (current_map == MAP_AZTEC_BEETLE_RACE) {
                func_global_asm_806D3530();
            }
            break;
        case 2:
            if (current_actor_pointer->unk6A & 1) {
                current_actor_pointer->unk6A &= ~0x1000;
                func_global_asm_806CFE7C();
                current_actor_pointer->control_state = 0xF;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614E78(current_actor_pointer, 0x5E);
            } else {
                func_global_asm_806D3530();
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3CD4(void) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    func_global_asm_806DF6D4(0x3C);
    func_global_asm_806CC8B8();
    if (current_actor_pointer->unkB8 == 0.0f) {
        if (current_actor_pointer->unkE0 == 0.0f) {
            func_global_asm_806CFF9C(current_actor_pointer);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3D5C(void) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    func_global_asm_806DF6D4(0x3B);
    func_global_asm_806CC8B8();
    if (current_actor_pointer->unkB8 == 0.0f) {
        if (current_actor_pointer->unkE0 == 0.0f) {
            func_global_asm_806CFF9C(current_actor_pointer);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3DE4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_80614E78(current_actor_pointer, 5);
            extra_player_info_pointer->unk30 = D_global_asm_8075327C[D_global_asm_807FD584];
            func_global_asm_806CD8EC();
            func_global_asm_806CC948();
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_806CD8EC();
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_806CD8EC();
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, D_global_asm_80753298[D_global_asm_807FD584], 0xC00);
            func_global_asm_806CC948();
            break;
        case 3:
            func_global_asm_806DF6D4(0x41);
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, D_global_asm_80753298[D_global_asm_807FD584], 0xC00);
            if (extra_player_info_pointer->unk4 == 0.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3FA0(void) {
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        current_actor_pointer->unkEA = extra_player_info_pointer->unkA;
    } else {
        current_actor_pointer->unkEA = current_actor_pointer->y_rotation;
    }
}

void func_global_asm_806D4010(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806CFD68();
            break;
        case 3:
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xAU) && (current_character_index[cc_player_index] == 1)) {
                if (current_actor_pointer->unkE0 == 0.0f) {
                    current_actor_pointer->control_state = 0x1A;
                    current_actor_pointer->control_state_progress = 0;
                    extra_player_info_pointer->unk54 = D_global_asm_80753604[D_global_asm_807FD584];
                    extra_player_info_pointer->unk50 = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x13);
                }
            }
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D423C(void) {
    current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
    func_global_asm_806DF6D4(5);
    func_global_asm_806CC8F0();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D428C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x2C);
            if (extra_player_info_pointer->unk3C != 0) {
                func_global_asm_806CC948();
                extra_player_info_pointer->unk3C--;
            } else {
                func_global_asm_806CC8B8();
            }
            break;
        case 1:
            if (extra_player_info_pointer->unk3C != 0) {
                extra_player_info_pointer->unk2C = 0.0f;
                func_global_asm_806CC8B8();
                extra_player_info_pointer->unk3C--;
                current_actor_pointer->unkEA = current_actor_pointer->y_rotation;
            } else {
                func_global_asm_806D3FA0();
                func_global_asm_806CC8B8();
            }
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            if (extra_player_info_pointer->unk3C != 0) {
                extra_player_info_pointer->unk2C = 0.0f;
                func_global_asm_806CC8B8();
                extra_player_info_pointer->unk3C--;
            } else {
                extra_player_info_pointer->unk2C = D_global_asm_80753234[D_global_asm_807FD584];
                func_global_asm_806CC8B8();
            }
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806D3608();
            func_global_asm_806CFD68();
            break;
        case 3:
            extra_player_info_pointer->unk3C = 0;
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xAU) && (current_character_index[cc_player_index] == 1)) {
                if (current_actor_pointer->unkE0 == 0.0f) {
                    current_actor_pointer->control_state = 0x1A;
                    current_actor_pointer->control_state_progress = 0;
                    extra_player_info_pointer->unk54 = D_global_asm_80753604[D_global_asm_807FD584];
                    extra_player_info_pointer->unk50 = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x13);
                }
            }
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CC8B8();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D45A4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806D3608();
            func_global_asm_806CFD68();
            break;
        case 3:
            extra_player_info_pointer->unk4C = -1;
            current_actor_pointer->control_state = func_global_asm_806CE4E4(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
            current_actor_pointer->control_state_progress = 0;
            if (current_actor_pointer->control_state == 0x3F) {
                current_actor_pointer->control_state_progress = 1;
            }
            func_global_asm_806DF6D4(0x46);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// regalloc, rodata, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D4758.s")

/*
void func_global_asm_806D4758(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk3E != 0) {
                func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40);
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 50.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806DF6D4(0x23);
            switch (current_character_index[cc_player_index]) {
                case 2:
                    extra_player_info_pointer->unk4 *= 0.63;
            }
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806DF6D4(0x23);
            switch (current_character_index[cc_player_index]) {
                case 0:
                case 2:
                    extra_player_info_pointer->unk4 *= 0.63;
            }
            func_global_asm_806CFE7C();
            func_global_asm_806D3608();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (!func_global_asm_806DF6D4(0x31) && current_actor_pointer->unkB8 < extra_player_info_pointer->unk4) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D491C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x26);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x25);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x25);
            func_global_asm_806CFD68();
            func_global_asm_806D3608();
            break;
        case 3:
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            func_global_asm_806DF6D4(0x34);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D4A70.s")

/*
void func_global_asm_806D4A70(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk3E) {
                func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40);
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 50.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806CC8B8();
            if (current_actor_pointer->y_velocity <= -15.0f) {
                current_actor_pointer->y_velocity = -15.0f;
                current_actor_pointer->control_state_progress++;
            }
            func_global_asm_806DF6D4(0x24);
            if (current_actor_pointer->unk6A & 1) {
                func_global_asm_806F142C(current_actor_pointer);
            }
            break;
        case 1:
            func_global_asm_806DF6D4(0x24);
            if (extra_player_info_pointer->unk3E) {
                func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40);
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 30.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unk6A & 1) {
                func_global_asm_806F142C(current_actor_pointer);
                func_global_asm_80608528(current_actor_pointer, 1, 0xFF, 0x7F, 0x1E);
            }
            break;
        case 2:
            current_actor_pointer->y_acceleration = -4.0f;
            func_global_asm_806DF6D4(0x24);
            func_global_asm_806CC8B8();
            if ((current_actor_pointer->unk6A & 1) != 0) {
                func_global_asm_806F142C(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D4C7C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_8075363C[D_global_asm_807FD584];
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806D3FA0();
            func_global_asm_806DF6D4(0x2B);
            extra_player_info_pointer->unk38 = D_global_asm_80753620[D_global_asm_807FD584];
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x2B);
            func_global_asm_806CFDEC();
            func_global_asm_806D3608();
            break;
        case 3:
            func_global_asm_806DF6D4(0x2B);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
        case 4:
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D4DE4(void) {
    func_global_asm_806CF878();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = D_global_asm_80753674[D_global_asm_807FD584];
            current_actor_pointer->y_acceleration = D_global_asm_80753690[D_global_asm_807FD584];
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806DF6D4(0x2B);
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x2D);
            func_global_asm_806D3608();
            break;
        case 3:
            func_global_asm_806DF6D4(0x36);
            func_global_asm_806CC8B8();
            break;
        case 4:
            func_global_asm_806DF6D4(0x36);
            func_global_asm_806CC8B8();
            break;
        case 5:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x2B);
            extra_player_info_pointer->unk38 = D_global_asm_807536C8[D_global_asm_807FD584];
            func_global_asm_806CC8B8();
            break;
        case 6:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x2C);
            func_global_asm_806CFDA8();
            func_global_asm_806D3608();
            break;
        case 7:
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5008(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->y_velocity = 0.0f;
            func_global_asm_806DF6D4(0x2E);
            func_global_asm_806CC970();
            break;
        case 1:
            func_global_asm_806DF6D4(0x2E);
            current_actor_pointer->y_acceleration = -30.0f;
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->y_velocity = -100.0f;
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806DF6D4(0x2E);
            func_global_asm_806D3608();
            func_global_asm_806CC948();
            break;
        case 3:
            func_global_asm_806DF6D4(0x2E);
            if (!(current_actor_pointer->unk6A & 4)) {
                func_global_asm_80608528(current_actor_pointer, 0x96, 0xFF, 0x7F, 0x19);
                func_global_asm_80685708(current_actor_pointer, D_global_asm_807FD568->simian_slam);
                func_global_asm_8061F0B0(extra_player_info_pointer->unk104, 0x14, (D_global_asm_807FD568->simian_slam * 5) & 0xFFFF);
            }
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806CC948();
            break;
        case 4:
            func_global_asm_806DF6D4(0x2E);
            func_global_asm_806CC948();
            break;
        case 5:
            func_global_asm_806DF6D4(0x2F);
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806CC8B8();
            break;
        case 6:
            func_global_asm_806DF6D4(0x2F);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5218(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 = extra_player_info_pointer->unk30 / 1.8;
            current_actor_pointer->control_state_progress++;
        case 1:
            func_global_asm_806DF6D4(5);
            func_global_asm_806CC8B8();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5300(void) {
    s32 pad;
    f32 sp90, sp8C, sp88;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    s32 phi_s1;

    if ((current_actor_pointer->control_state_progress < 2) || (D_global_asm_80750FD8 < current_actor_pointer->unkB8)) {
        temp_f20 = current_actor_pointer->animation_state->scale_y / 0.15;
        func_global_asm_80671C0C(current_actor_pointer, 7, &sp90, &sp8C, &sp88);
        for (phi_s1 = 0; phi_s1 < D_global_asm_80750FD4; phi_s1++) {
            temp_f24 = (((rand() >> 0xF) % 10000) % D_global_asm_80750FC8) - (D_global_asm_80750FC8 / 2);
            temp_f26 = (((rand() >> 0xF) % 10000) % D_global_asm_80750FCC) - (D_global_asm_80750FCC / 2);
            temp_f22 = (((rand() >> 0xF) % 10000) % D_global_asm_80750FD0) - (D_global_asm_80750FD0 / 2);
            func_global_asm_80714950(D_global_asm_80750FC4);
            func_global_asm_8071498C(&func_global_asm_80717D4C);
            func_global_asm_807149B8(1);
            func_global_asm_80714CC0(D_global_asm_8074E880[((rand() % 10000) % 3)],
                D_global_asm_80750FC0 * temp_f20,
                (temp_f24 * temp_f20) + sp90,
                (temp_f26 * temp_f20) + sp8C,
                (temp_f22 * temp_f20) + sp88
            );
        }
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(5);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            func_global_asm_806DF6D4(5);
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            if ((extra_player_info_pointer->unk1F4 & 8) == 0) {
                current_actor_pointer->unkB8 = 140.0f;
            }
            extra_player_info_pointer->unk30 = 6.0f;
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            if (current_actor_pointer->unkFC != 0) {
                if ((D_global_asm_8075352C[D_global_asm_807FD584] < current_actor_pointer->unkB8) && ((extra_player_info_pointer->unk1F4 & 8) == 0)) {
                    current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                    extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
                }
            }
            func_global_asm_806DF6D4(5);
            break;
        case 3:
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806DF6D4(5);
            func_global_asm_806F142C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D57F0(void) {
    func_global_asm_806DF6D4(1);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

// rodata, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D5834.s")

extern s32 D_global_asm_80767CC0;
extern s32 D_global_asm_80767CC0;

/*
void func_global_asm_806D5834(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= 1.8;
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0 - 0x64;
            extra_player_info_pointer->unk48 = 0x50;
            // Fallthrough
        case 1:
            func_global_asm_806DF6D4(9);
            extra_player_info_pointer->unk30 = 10.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x32U) {
                if (current_character_index[cc_player_index] == 2) {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x40);
                } else {
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    func_global_asm_80614E78(current_actor_pointer, 0x41);
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D59E4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= 1.8;
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0 - 0x64;
            // Fallthrough
        case 1:
            func_global_asm_806DF6D4(9);
            extra_player_info_pointer->unk30 = 10.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x32U) {
                current_actor_pointer->control_state = 0x28;
                current_actor_pointer->control_state_progress = 0;
                func_global_asm_80614E78(current_actor_pointer, 0x41);
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5B44(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= 1.8;
            if (current_character_index[cc_player_index] == 3) {
                current_actor_pointer->unkB8 = 50.0f;
            }
            current_actor_pointer->control_state_progress++;
        case 1:
            func_global_asm_806DF6D4(0xA);
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            func_global_asm_806DF6D4(0xA);
            extra_player_info_pointer->unk30 = 50.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5CCC(void) {
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806D3608();
    switch (current_character_index[cc_player_index]) {
        case 1:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_806CFECC();
                    func_global_asm_806DF6D4(0x17);
                    func_global_asm_806CC948();
                    break;
                case 1:
                    func_global_asm_806CFECC();
                    func_global_asm_806DF6D4(0x16);
                    func_global_asm_806CC948();
                    break;
            }
            break;
        case 0:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    extra_player_info_pointer->unk30 = 7.0f;
                    extra_player_info_pointer->unk2C = 8.0f;
                    extra_player_info_pointer->unk48 = 0x12C;
                    func_global_asm_806DF6D4(0x15);
                    extra_player_info_pointer->unk4 = 0.0f;
                    func_global_asm_806CC8B8();
                    break;
                case 1:
                    current_actor_pointer->unkB8 = D_global_asm_807531FC[D_global_asm_807FD584];
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    current_actor_pointer->y_velocity = 150.0f;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = 200.0f;
                    func_global_asm_806DF6D4(0x15);
                    extra_player_info_pointer->unk4 = 200.0f;
                    func_global_asm_806CC8B8();
                    current_actor_pointer->control_state_progress++;
                    break;
                case 3:
                    current_actor_pointer->unkB8 = 200.0f;
                    extra_player_info_pointer->unk38 = 200.0f;
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
            }
            break;
        default:
        case 3:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    extra_player_info_pointer->unk28 = 0;
                    extra_player_info_pointer->unk30 = 0.2f;
                    extra_player_info_pointer->unk2C = 8.0f;
                    extra_player_info_pointer->unk48 = 0x12C;
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 1:
                    extra_player_info_pointer->unk30 = 20.0f;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    extra_player_info_pointer->unk28 = 1;
                    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x14U) {
                        current_actor_pointer->control_state = 0x26;
                        current_actor_pointer->control_state_progress = 0;
                        func_global_asm_80614E78(current_actor_pointer, 0x3F);
                    }
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC8B8();
                    break;
            }
            break;
        case 6:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    extra_player_info_pointer->unk28 = 0;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk48 = 0x12C;
                    func_global_asm_806DF6D4(0x15);
                    extra_player_info_pointer->unk30 = 10.0f;
                    func_global_asm_806CD8EC();
                    func_global_asm_806CC948();
                    break;
                case 1:
                    extra_player_info_pointer->unk2C = 30.0f;
                    extra_player_info_pointer->unk68 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    extra_player_info_pointer->unk28 = 1;
                    func_global_asm_806DF6D4(0x15);
                    func_global_asm_806CC8B8();
                    break;
                }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D61B8.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D6558.s")

s32 func_global_asm_806D69A4(void) {
    if (current_actor_pointer->unkFC != 0) {
        if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, ((((current_actor_pointer->unkF6 - current_actor_pointer->unkF4) & 0xFFF) / 2) + current_actor_pointer->unkF4 + 0x800) & 0xFFF) < 0x2BC) {
            if (current_actor_pointer->unkB8 > 150.0f) {
                func_global_asm_80614E78(current_actor_pointer, 0x49);
                current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
                current_actor_pointer->control_state_progress = 2;
                current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
            } else {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            return 1;
        }
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    }
    return 0;
}

void func_global_asm_806D6B00(void) {
    func_global_asm_806D3608();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk28 = 0;
            func_global_asm_806DF6D4(0x1A); // controlStateControl()
            if (extra_player_info_pointer->unk68 < current_actor_pointer->unkB8) {
                extra_player_info_pointer->unk68 = current_actor_pointer->unkB8;
            }
            if (func_global_asm_806D69A4()) {
                break;
            } else {
                func_global_asm_806CBE90();
                if (current_actor_pointer->unkE0 != 0.0f) {
                    extra_player_info_pointer->unk30 = 20.0f;
                    func_global_asm_806CD8EC();
                } else {
                    func_global_asm_806CD424(current_actor_pointer->y_rotation,
                                extra_player_info_pointer->unk68,
                                extra_player_info_pointer->unk38);
                }
                func_global_asm_806CC948();
                break;
            }
        case 1:
            func_global_asm_806DF6D4(0x1A); // controlStateControl()
            if (func_global_asm_806D69A4()) {
                break;
            } else {
                func_global_asm_806DF494(&current_actor_pointer->y_rotation,
                              current_actor_pointer->unkEE,
                              extra_player_info_pointer->unk48);
                func_global_asm_806CBE90();
                func_global_asm_806CD8EC();
                func_global_asm_806CC948();
                extra_player_info_pointer->unk30 = D_global_asm_80753548[D_global_asm_807FD584];
                if (current_actor_pointer->unkB8 > 20.0f) {
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 2, 0);
                    }
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 3, 0);
                    }
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 9, 0);
                    }
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(&func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 0xA, 0);
                    }
                }
                break;
            }
        case 2:
            func_global_asm_806DF6D4(5); // controlStateControl()
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
        case 3:
            func_global_asm_806DF6D4(5); // controlStateControl()
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            extra_player_info_pointer->unk30 = 5.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D6F0C(void) {
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806DF6D4(8); // controlStateControl()
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D6F64(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = D_global_asm_8075305C[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, ((current_actor_pointer->unkEE + 0x800) & 0xFFF), extra_player_info_pointer->unk48 << 1);
            break;
        case 1:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 2:
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7098(void) {
    func_global_asm_806DF6D4(3);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkDC->y_rotation + 0x800, 8.0f);
            extra_player_info_pointer->unk4 = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7170(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806DF6D4(3);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk4 = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_8068780C(1, 4, 5, 8);
            break;
        case 2:
            func_global_asm_806845B8(1, 8);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7238(void) {
    func_global_asm_806EB0C0(0x5C, NULL, cc_player_index);
    func_global_asm_806DF6D4(3);
    current_actor_pointer->noclip_byte = 1;
    extra_player_info_pointer->unk4 = 0.0f;
    current_actor_pointer->unkB8 = 0.0f;
    func_global_asm_806CC8B8();
    if (extra_player_info_pointer->unk21E == 0) {
        func_global_asm_80712830(current_actor_pointer, cc_player_index);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D72D4(void) {
    f32 temp_f0;

    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = D_global_asm_807530F0[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkDC->y_rotation + 0x800, 8.0f);
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806DF6D4(3);
            extra_player_info_pointer->unk4 = 0.0f;
            if (current_character_index[cc_player_index] == 4) {
                temp_f0 = current_actor_pointer->animation_state->unk0->unk4;
                if ((temp_f0 >= 29.0f) && (temp_f0 < 33.0f)) {
                    current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) & 0xFFF;
                    current_actor_pointer->unkB8 = 150.0f;
                    func_global_asm_806CC948();
                    break;
                } else if (temp_f0 >= 48.0f) {
                    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                    current_actor_pointer->unkB8 = 60.0f;
                    func_global_asm_806CC948();
                    break;
                }
            }
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC8B8();
            break;
        case 2:
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7510(void) {
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
            func_global_asm_806DF6D4(4);
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, (current_actor_pointer->unkEE + 0x800) & 0xFFF, (extra_player_info_pointer->unk48) << 0x1);
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.5;
            }
            break;
        case 1:
            func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
            extra_player_info_pointer->unk4 = 0.0f;
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.5;
            }
            break;
        case 2:
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806EB0C0(0x18, NULL, cc_player_index);
            break;
    }
    if (current_actor_pointer->unkAC < ( D_global_asm_807538C8[D_global_asm_807FD584] + current_actor_pointer->y_position)) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC -  D_global_asm_807538C8[D_global_asm_807FD584];
    }
    extra_player_info_pointer->unk4 = 0.0f;
    extra_player_info_pointer->unk30 = 2.0f;
    func_global_asm_806CC8F0();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7704(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->unkB8 = D_global_asm_80753144[D_global_asm_807FD584];
            func_global_asm_806DF6D4(5);
            extra_player_info_pointer->unk4 = D_global_asm_80753144[D_global_asm_807FD584];
            if (extra_player_info_pointer->unk1A3 != 0) {
                func_global_asm_80605314(current_actor_pointer, 0);
                extra_player_info_pointer->unk1A3 = 0;
            }
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(
                &current_actor_pointer->y_rotation,
                (current_actor_pointer->unkEE + 0x800) & 0xFFF,
                extra_player_info_pointer->unk48 << 0x1
            );
            break;
        case 1:
            func_global_asm_806DF6D4(3);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 2:
            func_global_asm_806DF6D4(3);
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7878(void) {
    f64 temp_f0 = current_actor_pointer->animation_state->scale_y;
    func_global_asm_807248B0(current_actor_pointer, ((0.001 - temp_f0) * 0.01) + temp_f0);
    current_actor_pointer->shadow_opacity -= 0x14;
    if (current_actor_pointer->shadow_opacity < 0) {
        current_actor_pointer->shadow_opacity = 0;
    }
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CC8B8();
            break;
        case 1:
            func_global_asm_806CC8B8();
            if (extra_player_info_pointer->unk11C-- == 0) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            if ((current_map != MAP_CAVES_BEETLE_RACE) && (current_map != MAP_AZTEC_BEETLE_RACE)) {
                func_global_asm_80712830(current_actor_pointer, cc_player_index);
            }
            current_actor_pointer->control_state_progress++;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D79E4(void) {
    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7A28(void) {
    u8 temp_v0;

    func_global_asm_806EB0C0(0x3C, NULL, cc_player_index);
    func_global_asm_806DF6D4(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_acceleration = D_global_asm_80753024[D_global_asm_807FD584];
            if (D_global_asm_807FBB68 & 2) {
                playSound(0x424, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
            if (cc_number_of_players == 1) {
                func_global_asm_80627948(player_pointer, 0xC, 0x25, 0x85);
            }
            current_actor_pointer->control_state_progress++;
        case 1:
            extra_player_info_pointer->unk4 = D_global_asm_80753094[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, (current_actor_pointer->unkEE + 0x800) & 0xFFF, (extra_player_info_pointer->unk48 << 0x1));
            func_global_asm_806CC8B8();
            extra_player_info_pointer->unk11C = 0xF;
            extra_player_info_pointer->unk11D = 0;
            break;
        case 2:
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC970();
            break;
        case 3:
            temp_v0 = func_global_asm_80714608(0);
            if ((extra_player_info_pointer->unk11C == 0) && (extra_player_info_pointer->unk11D == 0)) {
                if ((temp_v0) == 0) {
                    func_global_asm_806CF918();
                }
                extra_player_info_pointer->unk11D = 1;
            } else {
                extra_player_info_pointer->unk11C--;
            }
            if (extra_player_info_pointer->unk11D != 0) {
                if (extra_player_info_pointer->unk11C >= 0xBF) {
                    if ((temp_v0 == 0) && ((extra_player_info_pointer->unk11C % 3) == 0)) {
                        func_global_asm_80608528(current_actor_pointer, ((extra_player_info_pointer->unk11C & 2) / 2) + 0x57, 0xFF, 0x7F, 0x1E);
                    }
                } else if (temp_v0 != 0) {
                    func_global_asm_80712830(current_actor_pointer, cc_player_index);
                }
            }
            if (((extra_player_info_pointer->unk1F0 & 0x1000) != 0) && ((object_timer & 3) == 0)) {
                func_global_asm_807149C8(0x64, 0x64, 0x64, 0xC8);
                func_global_asm_80714998(2);
                func_global_asm_8068588C(current_actor_pointer, (((rand() >> 0xF) % 32767) % 8) + 1, 0.4f, 0.0f, 0.0f, 0.0f, -0x50);
            }
            current_actor_pointer->unkB8 = 0.0f;
            func_global_asm_806CC970();
            break;
        default:
            if (cc_number_of_players >= 2) {
                func_global_asm_80712830(current_actor_pointer, cc_player_index);
            }
            extra_player_info_pointer->unk1F0 &= -0x1001;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7DF8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x45);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            func_global_asm_806DF6D4(0x44);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7E88(void) {
    s16 temp_v0;

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x46);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            if (func_global_asm_806DF6D4(0x46) == 0) {
                temp_v0 = func_global_asm_806CE4E4(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
                if (temp_v0 != 0x3F) {
                    current_actor_pointer->control_state = temp_v0;
                    current_actor_pointer->control_state_progress = 0;
                }
            }
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7F48(void) {
    s16 temp_v0;

    func_global_asm_806CBE90();
    if (!func_global_asm_806DF6D4(0x46)) {
        temp_v0 = func_global_asm_806CE4E4(
            current_actor_pointer,
            current_actor_pointer->unkB8,
            extra_player_info_pointer->unk4,
            1
        );

        if (temp_v0 != 0x40) {
            current_actor_pointer->control_state = temp_v0;
            current_actor_pointer->control_state_progress = 0;
            if (temp_v0 == 0x3F) {
                current_actor_pointer->control_state_progress = 1;
            }
        }
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7FE8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(1);
            break;
        case 1:
            current_actor_pointer->control_state = 0x3C;
            current_actor_pointer->control_state_progress = 1;
            func_global_asm_80614E78(current_actor_pointer, 0xB);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D8070(void) {
    func_global_asm_806DF6D4(1);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D80A8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            func_global_asm_806DF6D4(0x47);
            func_global_asm_806CC948();
            func_global_asm_806CD8EC();
            extra_player_info_pointer->unk2C = D_global_asm_80753470[D_global_asm_807FD584];
            extra_player_info_pointer->unk30 = D_global_asm_8075348C[D_global_asm_807FD584];
            extra_player_info_pointer->unk38 = D_global_asm_80753454[D_global_asm_807FD584];
            extra_player_info_pointer->unk48 = D_global_asm_807534A8[D_global_asm_807FD584];
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_80753738[D_global_asm_807FD584];
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x47);
            func_global_asm_806CFE30();
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            func_global_asm_806CFE30();
            func_global_asm_806D3608();
            func_global_asm_806CC8B8();
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            func_global_asm_806DF6D4(0x47);
            break;
        case 3:
            func_global_asm_806DF6D4(0x35);
            if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
                func_global_asm_80614D00(current_actor_pointer, 3.0f, 0.0f);
            }
            extra_player_info_pointer->unk4 = 0.0f;
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

extern f32 D_global_asm_80753770[];
extern f32 D_global_asm_807537A8[];
extern f32 D_global_asm_807537C4[];

void func_global_asm_806D8308(void) {
    Actor *var_a3;
    PlayerAdditionalActorData *temp_v0;

    switch (current_actor_pointer->control_state_progress) {
    case 0:
        current_actor_pointer->unkEA = current_actor_pointer->unkEE;
        func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
        func_global_asm_806DF6D4(0x48);
        func_global_asm_806CC948();
        break;
    case 1:
        current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
        current_actor_pointer->y_acceleration = D_global_asm_807537A8[D_global_asm_807FD584];
        current_actor_pointer->unkB8 = D_global_asm_80753770[D_global_asm_807FD584];
        current_actor_pointer->unkEA = current_actor_pointer->unkEE;
        current_actor_pointer->control_state_progress += 1;
        func_global_asm_806DF6D4(0x48);
        func_global_asm_806CFE30();
        func_global_asm_806CC948();
        break;
    case 2:
        func_global_asm_806CFE30();
        func_global_asm_806D3608();
        func_global_asm_806CC948();
        func_global_asm_806DF6D4(0x48);
        break;
    case 3:
        extra_player_info_pointer->unk30 = D_global_asm_807537C4[D_global_asm_807FD584];
        func_global_asm_806DF6D4(0x33);
        func_global_asm_806CFE7C();
        func_global_asm_806CC8B8();
        break;
    case 4:
        if (extra_player_info_pointer->unk4 > 10.0f) {
            func_global_asm_806CFF9C(current_actor_pointer);
        }
        extra_player_info_pointer->unk30 = D_global_asm_807537C4[D_global_asm_807FD584];
        func_global_asm_806DF6D4(0x33);
        func_global_asm_806CFE7C();
        func_global_asm_806CC8B8();
        break;
    }
    renderActor(current_actor_pointer, 0);
}

int func_global_asm_806D850C(void) {
    f32 sp2C;
    f32 phi_f2;

    if (character_change_array[cc_player_index].unk2C0 == 1) {
        sp2C = D_global_asm_8075388C[D_global_asm_807FD584];
    } else {
        sp2C = D_global_asm_807538C8[D_global_asm_807FD584];
    }
    if ((current_actor_pointer->control_state == 0x4E) && playerCanDive()) {
        if ((current_actor_pointer->control_state_progress != 0) && ((current_actor_pointer->y_position + sp2C) < (current_actor_pointer->unkAC - 10.0f))) {
            extra_player_info_pointer->unk12 = D_global_asm_807539EC[D_global_asm_807FD584];
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            extra_player_info_pointer->unk10 = D_global_asm_807539DC[D_global_asm_807FD584] * 0.5;
            current_actor_pointer->control_state = 0x4F;
            current_actor_pointer->control_state_progress = 1;
            if (current_actor_pointer->y_velocity > 0.0f) {
                current_actor_pointer->y_velocity = 0.0f;
            }
            func_global_asm_80614E78(current_actor_pointer, 0x36);
            func_global_asm_80613AF8(current_actor_pointer, 0x31, 0.0f, 8.0f);
            func_global_asm_80614D00(current_actor_pointer, 0.5f, 0.0f);
            func_global_asm_80608528(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
        }
    }
    if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + sp2C)) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC - sp2C;
    }
    phi_f2 = character_change_array[cc_player_index].unk2C0 == 1 ? D_global_asm_8075387C[D_global_asm_807FD584] : D_global_asm_807538B8[D_global_asm_807FD584];
    if ((current_actor_pointer->unkAC - current_actor_pointer->floor) < phi_f2) {
        func_global_asm_806EB0C0(2, NULL, cc_player_index);
        return TRUE;
    }
    return FALSE;
}

// close, float
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D87FC.s")

extern f32 D_global_asm_807539A4[];
extern f32 D_global_asm_80753988[];
extern s16 D_global_asm_80753B34[];

/*
// TODO: Very close, something iffy with the order of loading floats from those arrays
void func_global_asm_806D87FC(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp;
    f32 phi_f2;

    phi_f2 = D_global_asm_807539A4[D_global_asm_807FD584];
    temp = D_global_asm_80753988[D_global_asm_807FD584];
    if (current_actor_pointer->y_velocity < 0.0f) {
        temp_f0 = -current_actor_pointer->y_velocity / 3.0f;
        if (!(temp_f0 < D_global_asm_807539A4[D_global_asm_807FD584])) {
            phi_f2 = temp_f0;
        }
    }
    if ((current_actor_pointer->distance_from_floor == 0.0f) && (current_actor_pointer->y_velocity < -0.1)) {
        current_actor_pointer->y_velocity = -0.1f;
    }
    current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, temp, phi_f2);
    extra_player_info_pointer->unk24 = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x4E);
            func_global_asm_806CC8F0();
            break;
        case 1:
            func_global_asm_806DF6D4(0x4D);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkB8 != 0.0f) {
                func_global_asm_80614E78(current_actor_pointer, 0x3A);
                current_actor_pointer->control_state_progress = 2;
            }
            break;
        default:
            func_global_asm_806DF6D4(0x4D);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkB8 == 0.0f) {
                func_global_asm_80614E78(current_actor_pointer, 0x33);
                current_actor_pointer->control_state_progress = 1;
            } else {
                temp_f0_2 = (extra_player_info_pointer->unk4 * 1.5) / 40.0;
                if (current_actor_pointer->animation_state->unk48 < temp_f0_2) {
                    func_global_asm_80614D00(current_actor_pointer, temp_f0_2, 0.0f);
                } else {
                    func_global_asm_80614D00(current_actor_pointer, temp_f0_2, 5.0f);
                }
            }
            break;
    }
    func_global_asm_806D850C();
    current_actor_pointer->object_properties_bitfield &= -2;
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D8A64(void) {
    extra_player_info_pointer->unk24 = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            func_global_asm_806DF6D4(0x4B);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->z_rotation = 0;
            current_actor_pointer->x_rotation = 0;
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D8B08.s")

void func_global_asm_806D8FCC(void) {
    extra_player_info_pointer->unk24 = 0;
    current_actor_pointer->x_rotation = 0;
    current_actor_pointer->z_rotation = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806D3FA0();
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CC8F0();
            break;
        case 1:
            func_global_asm_806CC8B8();
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x21);
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x22);
            } else {
                func_global_asm_806DF6D4(0x21);
            }
            func_global_asm_806CFD68();
            break;
        case 3:
            func_global_asm_806CC8B8();
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9134(void) {
    func_global_asm_806DF6D4(1);
    current_actor_pointer->unkB8 = 0.0f;
    current_actor_pointer->y_velocity = 0.0f;
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9184(void) {
    func_global_asm_806D9134();
}

void func_global_asm_806D91A4(void) {
    s32 phi_a2;

    if (current_actor_pointer->unkFC) {
        current_actor_pointer->unkB8 = 0.0f;
        func_global_asm_806CFF1C(current_actor_pointer);
    }
    if ((current_actor_pointer->unkFC != 0) || (current_actor_pointer->unk6A & 1 && (current_actor_pointer->unk6C & 1) == 0)) {
        func_global_asm_806224CC(extra_player_info_pointer->unk104, current_actor_pointer);
    }
    if (!(current_actor_pointer->unk6A & 1)) {
        func_global_asm_807149B8(1);
        func_global_asm_807149FC(1);
        func_global_asm_80714C08(&D_global_asm_8072014C, 0.8f, current_actor_pointer, 1, 0);
    }
    if (current_actor_pointer->unk6A & current_actor_pointer->unk6C & 1) {
        phi_a2 = 2;
    } else {
        phi_a2 = 1;
    }
    if ((!current_actor_pointer->unk6C & current_actor_pointer->unk6A & 1)) {
        current_actor_pointer->unkB8 *= 0.25;
    }
    if (current_actor_pointer->unkB8 < phi_a2) {
        current_actor_pointer->unkB8 = 0.0f;
    } else {
        current_actor_pointer->unkB8 -= phi_a2;
    }
    func_global_asm_806DF6D4(1);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D9320.s")

void func_global_asm_806D97A4(void) {
    func_global_asm_806DF6D4(5);
    if (current_actor_pointer->y_velocity < 0.0f) {
        extra_player_info_pointer->unk6C = 0.0f;
    }
    func_global_asm_806CD424(extra_player_info_pointer->unk70,
                  extra_player_info_pointer->unk6C,
                  extra_player_info_pointer->unk38);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9820(void) {
    f32 temp_f0;
    f32 temp_f4;

    func_global_asm_806DF6D4(0x4A);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk38 < current_actor_pointer->unkB8) {
                func_global_asm_806CD8EC();
                func_global_asm_806CC948();
            } else {
                func_global_asm_806CC8B8();
            }
            temp_f4 = current_actor_pointer->unkB8 * 0.025;
            temp_f0 = MAX((f64)(temp_f4), (s32)1.875);
            func_global_asm_80614D00(current_actor_pointer, temp_f0, 0.0f);
            break;
        case 1:
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9924(Actor *actor) {
    actor->z_rotation = 0;
    actor->x_rotation = 0;
    actor->object_properties_bitfield &= ~1;
}

void func_global_asm_806D9940(void) {
    s32 song;
    f32 phi_f0;

    func_global_asm_806DF6D4(1);
    if ((current_actor_pointer->control_state_progress < 3)
        || (func_global_asm_8061CB80()
        && (func_global_asm_8061CB98(7)
            || func_global_asm_8061CB98(0)
            || func_global_asm_8061CB98(4)
            || func_global_asm_8061CB98(9)
            || func_global_asm_8061CB98(8)))) {
        func_global_asm_80653B70(1);
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if ((D_global_asm_807FBB68 & 2) == 0) {
                current_actor_pointer->noclip_byte = 1;
            }
            break;
        case 1:
            song = 0xA;
            phi_f0 = 1.0f;
            switch (current_actor_pointer->unk58) {
                case 2:
                    song = 0xB;
                    break;
                case 5:
                    song = 0xD;
                    break;
                case 4:
                    song = 0xC;
                    if (!(D_global_asm_807FBB68 & 2)) {
                        phi_f0 = 0.8199999928f;
                    }
                    break;
                case 6:
                    song = 9;
                    break;
            }
            playSong(song, phi_f0);
            current_actor_pointer->control_state_progress++;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// close, doable, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D9AD4.s")

extern s32 D_global_asm_8071FC8C;

int func_global_asm_80717100();

void func_global_asm_805FF9AC(enum map_e arg0, s32 arg1, s32 arg2, s16 arg3);

/*
void func_global_asm_806D9AD4(void) {
    s32 pad;
    f32 sp28;

    func_global_asm_806DF6D4(1);
    if ((current_actor_pointer->control_state_progress == 1) || (current_actor_pointer->control_state_progress == 2)) {
        rand();
        sp28 = current_actor_pointer->y_position + ((rand() >> 0xF) % 30);
        rand();
        func_global_asm_807149B8(1);
        func_global_asm_80714950((extra_player_info_pointer->unk23C << 0x10) + (s32)(15.0 * (current_actor_pointer->shadow_opacity / 255.0)));
        func_global_asm_8071498C(&func_global_asm_80717100);
        func_global_asm_80714CC0(&D_global_asm_8071FC8C, 0.5f, current_actor_pointer->x_position, sp28, current_actor_pointer->z_position);
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk23C = 0;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity = 0xFF;
            break;
        case 1:
            extra_player_info_pointer->unk23C += 0x1E;
            if (extra_player_info_pointer->unk23C > 0x190) {
                extra_player_info_pointer->unk23C = 0x190;
            }
            if (extra_player_info_pointer->unk23C == 0xD2) {
                func_global_asm_80608528(current_actor_pointer, 0x264, 0xFF, 0x64, 0x19);
            }
            if (extra_player_info_pointer->unk23C > 0x12C) {
                extra_player_info_pointer->unk1F0 &= ~0x40;
                current_actor_pointer->shadow_opacity -= 5;
                if (current_actor_pointer->shadow_opacity < 0xA) {
                    current_actor_pointer->control_state_progress++;
                }
            }
            break;
        case 2:
            func_global_asm_805FF9AC(extra_player_info_pointer->unk242, 0, 0, 3);
            current_actor_pointer->control_state_progress++;
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

// regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D9D58.s")

/*
void func_global_asm_806D9D58(void) {
    f32 phi_f0;
    f64 temp;

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_velocity = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            extra_player_info_pointer->unk30 = 1.0f;
            extra_player_info_pointer->unk2C = 3.0f;
            current_actor_pointer->y_acceleration = 2.0f;
            extra_player_info_pointer->unk23C = 0;
            extra_player_info_pointer->unk238 = current_actor_pointer->y_position;
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            func_global_asm_806DF6D4(0x43);
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            current_actor_pointer->y_position = extra_player_info_pointer->unk238;
            func_global_asm_806CC8B8();
            if ((extra_player_info_pointer->unk238 - current_actor_pointer->unk168) > 50.0f) {
                current_actor_pointer->y_position -= 1.0;
            }
            extra_player_info_pointer->unk238 = current_actor_pointer->y_position;
            current_actor_pointer->y_position = (func_global_asm_80612794(extra_player_info_pointer->unk23C) * 10.0) + extra_player_info_pointer->unk238;
            extra_player_info_pointer->unk23C += 0x64;
            phi_f0 = ABS(current_actor_pointer->y_position - current_actor_pointer->unk168);
            if (phi_f0 < 150.0) {
                current_actor_pointer->y_acceleration = ((current_actor_pointer->unk168 - current_actor_pointer->y_position) / 150.0) * 2.0;
            }
            if (current_actor_pointer->unk168 <= current_actor_pointer->y_position) {
                current_actor_pointer->y_velocity = 0.0f;
                current_actor_pointer->y_acceleration = 150.0;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D9FD0.s")

void func_global_asm_806DA320(void) {
    f32 phi_f2;

    if (D_global_asm_807FBC58 != 0.0) {
        phi_f2 = D_global_asm_807FBC58;
    } else {
        phi_f2 = current_actor_pointer->unkB8;
    }
    func_global_asm_80614D00(current_actor_pointer, (phi_f2 / 25.0f) + 0.25, 2.0f);
    func_global_asm_806DF6D4(0x49);
    if ((current_actor_pointer->unk6A & 0x10) == 0) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA3E4(void) {
    func_global_asm_806CA2AC();
    func_global_asm_806DF6D4(5);
    current_actor_pointer->unkB8 = 0.0f;
    current_actor_pointer->x_position = ((extra_player_info_pointer->unk22C - current_actor_pointer->x_position) * 0.2) + current_actor_pointer->x_position;
    current_actor_pointer->z_position = ((extra_player_info_pointer->unk234 - current_actor_pointer->z_position) * 0.2) + current_actor_pointer->z_position;
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, func_global_asm_80665DE0(extra_player_info_pointer->unk220, extra_player_info_pointer->unk228, current_actor_pointer->x_position, current_actor_pointer->z_position), 0x32);
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA4D8(void) {
    if ((func_global_asm_8067AF44(extra_player_info_pointer->unk1B0) == 0) || ((extra_player_info_pointer->unk1B0->unk54 != extra_player_info_pointer->unk1B4))) {
        extra_player_info_pointer->unk1AC = NULL;
        extra_player_info_pointer->unk1B0 = NULL;
        func_global_asm_806CFF9C(current_actor_pointer);
        func_global_asm_806CC8B8();
        renderActor(current_actor_pointer, 0);
        return;
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->unkB8 = 0.0f;
            extra_player_info_pointer->unk4 = 0.0f;
            func_global_asm_806CEC04(extra_player_info_pointer->unk1B0);
            current_actor_pointer->x_position += extra_player_info_pointer->unk78;
            current_actor_pointer->z_position += extra_player_info_pointer->unk7C;
            current_actor_pointer->y_rotation = extra_player_info_pointer->unk80;
            current_actor_pointer->control_state_progress += 1;
            break;
        case 1:
            current_actor_pointer->x_position += extra_player_info_pointer->unk78;
            current_actor_pointer->z_position += extra_player_info_pointer->unk7C;
            current_actor_pointer->y_rotation = extra_player_info_pointer->unk80;
            break;
        case 2:
            extra_player_info_pointer->unk1AC = extra_player_info_pointer->unk1B0;
            extra_player_info_pointer->unk1B8 = extra_player_info_pointer->unk1AC->unk58;
            func_global_asm_80679200(extra_player_info_pointer->unk1AC, current_actor_pointer, 0x2000, 1, 0, NULL);
            func_global_asm_806CEE64(0.4f);
            func_global_asm_806CEED8();
            current_actor_pointer->control_state_progress += 1;
            break;
        case 3:
            func_global_asm_806DF6D4(5);
            func_global_asm_806CEE64(0.4f);
            func_global_asm_806CEED8();
            break;
        case 4:
            func_global_asm_806DF6D4(5);
            func_global_asm_8067A784(current_actor_pointer, extra_player_info_pointer->unk1AC, current_player->y_rotation, ((D_global_asm_807533B8[D_global_asm_807FD584] * 3.0) * current_actor_pointer->animation_state->scale[0]) / 0.15, 0);
            current_actor_pointer->control_state_progress += 1;
            break;
        case 5:
            func_global_asm_806DF6D4(5);
            break;
        case 6:
            extra_player_info_pointer->unk1AC = extra_player_info_pointer->unk1B0;
            extra_player_info_pointer->unk1B8 = extra_player_info_pointer->unk1AC->unk58;
            func_global_asm_80679200(extra_player_info_pointer->unk1AC, current_actor_pointer, 0x2000, 1, 0, NULL);
            func_global_asm_806CEE64(0.4f);
            func_global_asm_806CEED8();
            current_actor_pointer->control_state_progress = 3;
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA7EC(void) {
    func_global_asm_806DF6D4(6);
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        func_global_asm_80614D00(current_actor_pointer, 3.0f, 0);
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA89C(void) {
    func_global_asm_806DF6D4(7);
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        func_global_asm_80614D00(current_actor_pointer, 2.0f, 0);
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA94C(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806CEE64(1.0f);
    func_global_asm_806CF0D0();
    func_global_asm_806CEED8();
    current_actor_pointer->control_state = func_global_asm_806CE928(
        current_actor_pointer,
        current_actor_pointer->unkB8,
        extra_player_info_pointer->unk4,
        1
    );
    current_actor_pointer->control_state_progress = 0;
    func_global_asm_806DF6D4(0x37);
    if (!(current_actor_pointer->unk6A & 1)) {
        func_global_asm_806D3608();
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAA14(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806CEE64(1.0f);
    func_global_asm_806CF0D0();
    func_global_asm_806CEED8();
    current_actor_pointer->control_state = func_global_asm_806CE928(
        current_actor_pointer,
        current_actor_pointer->unkB8,
        extra_player_info_pointer->unk4,
        1
    );
    current_actor_pointer->control_state_progress = 0;
    func_global_asm_806DF6D4(0x37);
    if ((current_actor_pointer->unk6A & 1) == 0) {
        func_global_asm_806D3608();
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAADC(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806DF6D4(0x3A);
    func_global_asm_806CEED8();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CEE64(0.5f);
            break;
        case 1:
            func_global_asm_806CEE64(0.5f);
            if (extra_player_info_pointer->unk1AC != 0) {
                func_global_asm_80679200(extra_player_info_pointer->unk1AC, current_actor_pointer, 0x2000, 0, 0, 0);
            }
            extra_player_info_pointer->unk1AC = NULL;
            extra_player_info_pointer->unk1B0 = 0;
            current_actor_pointer->control_state_progress += 1;
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DABE4(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806DF6D4(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CEE64(1.0f);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 1:
            func_global_asm_8067A784(current_actor_pointer, extra_player_info_pointer->unk1AC, current_player->y_rotation, D_global_asm_807533B8[D_global_asm_807FD584], D_global_asm_8075339C[D_global_asm_807FD584]);
            extra_player_info_pointer->unk1AC = NULL;
            extra_player_info_pointer->unk1B0 = 0;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unkB8 = D_global_asm_80753364[D_global_asm_807FD584];
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            break;
        default:
            if (current_actor_pointer->unkB8 != 0.0f) {
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                current_actor_pointer->unkB8 -= D_global_asm_80753380[D_global_asm_807FD584];
                if (current_actor_pointer->unkB8 < 0.0f) {
                    current_actor_pointer->unkB8 = 0.0f;
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DADA0(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806DF6D4(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806CEE64(1.0f);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 1:
            func_global_asm_8067A784(current_actor_pointer, extra_player_info_pointer->unk1AC, current_player->y_rotation, D_global_asm_807533F0[D_global_asm_807FD584], D_global_asm_807533D4[D_global_asm_807FD584]);
            extra_player_info_pointer->unk1AC = NULL;
            extra_player_info_pointer->unk1B0 = 0;
            current_actor_pointer->control_state_progress++;
            current_actor_pointer->unkB8 = D_global_asm_80753364[D_global_asm_807FD584];
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
            break;
        default:
            if (current_actor_pointer->unkB8 != 0.0f) {
                current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                current_actor_pointer->unkB8 -= D_global_asm_80753380[D_global_asm_807FD584];
                if (current_actor_pointer->unkB8 < 0.0f) {
                    current_actor_pointer->unkB8 = 0.0f;
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAF5C(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    func_global_asm_806CEE64(1.0f);
    func_global_asm_806CEED8();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0);
            func_global_asm_806DF6D4(0x21);
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            func_global_asm_806DF6D4(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            func_global_asm_806D3608();
            func_global_asm_806DF6D4(0x39);
            func_global_asm_806CFD68();
            break;
        case 3:
            func_global_asm_806DF6D4(0x38);
            func_global_asm_806CFE7C();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DB08C(void) {
    func_global_asm_806DF6D4(0x12);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DB0C4.s")

/*
void func_global_asm_806DB0C4(void) {
    Actor *temp_v1;
    f32 temp_f14;
    f32 temp_f20;

    if (D_global_asm_807FBB70.unkE4 != 0) {
        extra_player_info_pointer->unkDC = D_global_asm_807FBB70.unkEC;
        extra_player_info_pointer->unk9C = current_actor_pointer->x_position;
        extra_player_info_pointer->unkA0 = current_actor_pointer->z_position;
        extra_player_info_pointer->unkA4 = D_global_asm_807FBB70.unkD8;
        extra_player_info_pointer->unkA8 = D_global_asm_807FBB70.unkE0;
        extra_player_info_pointer->unkAC_f32 = 0.0f;
        temp_f20 = extra_player_info_pointer->unkA4 - extra_player_info_pointer->unk9C;
        temp_f14 = extra_player_info_pointer->unkA8 - extra_player_info_pointer->unkA0;
        extra_player_info_pointer->unk94 = sqrtf((temp_f20 * temp_f20) + (temp_f14 * temp_f14)) * 0.8;
        extra_player_info_pointer->unk98 = ((func_global_asm_80611BB4(temp_f20, temp_f14) * 4096.0f) / 6.283185482f);
        extra_player_info_pointer->unk4C = -1;
    }
    extra_player_info_pointer->unkAC_f32 += 0.02;
    if (extra_player_info_pointer->unkAC_f32 > 1.0) {
        if (extra_player_info_pointer->unkDC != NULL) {
            extra_player_info_pointer->unk98 = (func_global_asm_80611BB4(extra_player_info_pointer->unkDC->x_position - extra_player_info_pointer->unk9C, extra_player_info_pointer->unkDC->z_position - extra_player_info_pointer->unkA0) * 4096.0f) / 6.283185482f;
            if (current_actor_pointer->y_rotation == extra_player_info_pointer->unk98) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
        }
        extra_player_info_pointer->unkAC_f32 = 1.0f;
    }
    current_actor_pointer->x_position = extra_player_info_pointer->unk9C + ((extra_player_info_pointer->unkA4 - extra_player_info_pointer->unk9C) * extra_player_info_pointer->unkAC_f32);
    current_actor_pointer->z_position = extra_player_info_pointer->unkA0 + ((extra_player_info_pointer->unkA8 - extra_player_info_pointer->unkA0) * extra_player_info_pointer->unkAC_f32);
    func_global_asm_806CC970();
    func_global_asm_806CDD24(current_actor_pointer, extra_player_info_pointer->unk94, extra_player_info_pointer->unk94, 0);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unk98, D_global_asm_8075326C[D_global_asm_807FD584] / 2);
    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DB3AC.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DB670.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DBB04.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DC170.s")

void func_global_asm_806DC3A4(f32 arg0) {
    f32 temp_f2;
    f32 phi_f0;

    phi_f0 = extra_player_info_pointer->unk94;
    temp_f2 = extra_player_info_pointer->unk4;
    if (phi_f0 < temp_f2) {
        phi_f0 = phi_f0 + arg0;
        phi_f0 = MIN(temp_f2, phi_f0);
    } else if (temp_f2 < phi_f0) {
        phi_f0 = phi_f0 - arg0;
        phi_f0 = MAX(temp_f2, phi_f0);
    }
    extra_player_info_pointer->unk94 = phi_f0;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DC410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DCA7C.s")

extern f32 D_global_asm_80753CD0[];

/*
// TODO: Doable, made good progress, not sure what's going on with case 1
void func_global_asm_806DCA7C(Actor **arg0, s32 arg1) {
    f32 sp50;
    f32 sp4C;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 dx;
    f32 dz;
    s32 var_v0;
    s32 var_v1;

    current_actor_pointer->object_properties_bitfield &= 0xFFBFFFFF;
    current_actor_pointer->unk6A &= 0xFFBF;
    current_actor_pointer->z_rotation += (-current_actor_pointer->z_rotation * 0.1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DCF60();
            current_actor_pointer->unkB8 = extra_player_info_pointer->unk14C / 2;
            current_actor_pointer->unkEE = extra_player_info_pointer->unk154;
            var_v0 = current_actor_pointer->unkEE - current_actor_pointer->y_rotation;
            if (var_v0 < -0x800) {
                var_v0 += 0x1000;
            }
            if (var_v0 >= 0x801) {
                var_v0 -= 0x1000;
            }
            if (var_v0 > 0) {
                var_v1 = var_v0;
            } else {
                var_v1 = -var_v0;
            }
            if (var_v1 < 0x400) {
                func_global_asm_80614E78(current_actor_pointer, 0x6D);
            } else {
                func_global_asm_80614E78(current_actor_pointer, 0x6E);
            }
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x78, 0x600);
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk150;
            current_actor_pointer->control_state_progress += 1;
            func_global_asm_806DF6D4(0x27);
            extra_player_info_pointer->unk30 /= 2;
            func_global_asm_806CC948();
            break;
        case 2:
            if (extra_player_info_pointer->unk158 == 0) {
                func_global_asm_80614E78(current_player, 0x6F);
                current_actor_pointer->control_state_progress = 3;
            } else {
            case 1:
                func_global_asm_806DCF60();
                if (current_actor_pointer->unk58 == ACTOR_TINY) {
                    func_global_asm_806DF6D4(0x28);
                } else {
                    func_global_asm_806DF6D4(0x27);
                }
                current_actor_pointer->unkB8 = extra_player_info_pointer->unk14C;
                current_actor_pointer->unkEE = extra_player_info_pointer->unk154;
                func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x78, 0x600);
                extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
                extra_player_info_pointer->unk4 = 150.0f;
                extra_player_info_pointer->unk38 = 150.0f;
                if (extra_player_info_pointer->unk158 != 0) {
                    func_global_asm_80671C0C(extra_player_info_pointer->unk158, 1, &sp44, &sp40, &sp3C);
                    dx = sp44 - current_player->x_position;
                    dz = sp3C - current_player->z_position;
                    sp4C = (sp40 - current_player->y_position) / (current_player->animation_state->scale_y * 0.166666666749999998);
                    sp50 = ((sqrtf((dx * dx) + (dz * dz)) / (current_player->animation_state->scale_y * 0.166666666749999998)) / current_player->unkB8) - 1.0f;
                    if (sp50 < 1.0f) {
                        sp50 = 1.0f;
                    }
                }
                if ((extra_player_info_pointer->unk158 != 0) && (sp50 < 30.0f)) {
                    current_player->y_velocity = (((0.0 - (D_global_asm_80753CD0[D_global_asm_807FD584]) * 0.5 * (sp50 * sp50)) - sp4C)) / sp50;
                    current_player->y_acceleration = -0.001f;
                } else {
                    extra_player_info_pointer->unk158 = 0;
                    func_global_asm_806CFE7C();
                }
                func_global_asm_806CC948();
                break;
            }
            break;
        case 3:
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            extra_player_info_pointer->unk30 = 10.0f;
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DCF60.s")

f32 func_global_asm_80665E48(f32, f32, f32, f32);

/*
// TODO: Kinda close, good progress made
void func_global_asm_806DCF60(void) {
    Actor *temp_s0;
    f32 dx;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f28;
    f32 dz;
    f32 var_f14;
    f32 var_f26;
    s16 temp_s1;
    s16 temp_f16;
    s32 temp_f16_2;
    Actor *temp_v0;
    s32 i;
    Actor *temp_v1;

    temp_v0 = extra_player_info_pointer->unk158;
    var_f26 = 100.0f;
    if ((temp_v0 != NULL) || (current_actor_pointer->control_state_progress == 1)) {
        if (temp_v0 == NULL) {
            for (i = 0; i < i < D_global_asm_807FBB34; i++) {
                temp_s0 = D_global_asm_807FB930[i].unk0;
                if (!(temp_s0->object_properties_bitfield & 0x2000) && (temp_s0->object_properties_bitfield & 0x04000000) && (temp_s0 != extra_player_info_pointer->unk130) && (temp_s0 != current_player)) {
                    temp_f16 = ((func_global_asm_80665E48(temp_s0->x_position, temp_s0->z_position, current_player->x_position, current_player->z_position) * 57.29577637f) / 360.0) * 4095.0;
                    dx = temp_s0->x_position - current_player->x_position;
                    temp_s1 = func_global_asm_806CC14C(temp_f16, extra_player_info_pointer->unk154);
                    dz = temp_s0->z_position - current_player->z_position;
                    temp_f0_2 = sqrtf((dx * dx) + (dz * dz));
                    if ((temp_s1 < 0x258) && (temp_f0_2 < var_f26)) {
                        if (current_player->y_position < temp_s0->y_position) {
                            var_f14 = temp_s0->y_position - current_player->y_position;
                        } else {
                            var_f14 = -(temp_s0->y_position - current_player->y_position);
                        }
                        if (var_f14 < 100.0) {
                            extra_player_info_pointer->unk154 = temp_f16;
                            extra_player_info_pointer->unk158 = temp_s0;
                        }
                    }
                }
            }
        } else {
            temp_f16_2 = ((func_global_asm_80665E48(temp_v0->x_position, temp_v0->z_position, current_player->x_position, current_player->z_position) * 57.29577637f) / 360.0) * 4095.0;
            if (func_global_asm_806CC14C(temp_f16_2, extra_player_info_pointer->unk154) < 0x258) {
                extra_player_info_pointer->unk154 = temp_f16_2;
            }
        }
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DD24C.s")

void func_global_asm_806DD874(void) {
    current_actor_pointer->unkFA = 0x12C;
    func_global_asm_806CC8A8();
    switch (current_actor_pointer->control_state_progress) {
        case 1:
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) & 0xFFF;
            current_actor_pointer->y_velocity = D_global_asm_80753CB4[D_global_asm_807FD584];
            current_actor_pointer->unkB8 = 100.0f;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk3C = 3;
            func_global_asm_806DF6D4(0x29);
            extra_player_info_pointer->unk2C = 30.0f;
            extra_player_info_pointer->unk48 = 0x64;
            func_global_asm_806CFD68();
            extra_player_info_pointer->unk30 /= 2;
            func_global_asm_806CC948();
            break;
        case 2:
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                func_global_asm_806DF6D4(0x2A);
            } else {
                func_global_asm_806DF6D4(0x29);
            }
            extra_player_info_pointer->unk38 = 150.0f;
            func_global_asm_806D3608();
            func_global_asm_806CFD68();
            if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
                func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
            }
            if (extra_player_info_pointer->unk3C != 0) {
                func_global_asm_806CC948();
                extra_player_info_pointer->unk3C += -1;
            } else {
                func_global_asm_806CC8B8();
            }
            break;
        case 3:
            func_global_asm_806DF6D4(0x30);
            func_global_asm_806CFE7C();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

// doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DDAB0.s")

extern f32 D_global_asm_80753D70[];
extern f32 D_global_asm_80753D8C[];

extern s16 D_global_asm_80753DA8[];
extern s16 D_global_asm_80753DB8[];

/*
void func_global_asm_806DDAB0(void) {
    f32 sp64;
    u8 sp62;
    s16 sp60;
    f32 sp50;
    u8 sp4F;
    s8 sp4C;
    s16 sp4A;
    u8 sp49;
    f32 var_f2;
    s32 var_t6;
    s32 var_v0;
    s32 var_v0_2;
    u8 var_a2_2;
    u8 var_v1_2;

    sp49 = 0;
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        sp50 = D_global_asm_80753D70[D_global_asm_807FD584];
    } else {
        sp50 = D_global_asm_80753D8C[D_global_asm_807FD584];
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806DF6D4(0x5A);
            extra_player_info_pointer->unkEC = current_actor_pointer->y_rotation;
            extra_player_info_pointer->unkF8 = 5;
            current_actor_pointer->control_state_progress = 2;
            break;
        case 1:
        case 2:
        case 3:
            if (extra_player_info_pointer->unkF8 != 0) {
                extra_player_info_pointer->unkF8--;
            }
            if (func_global_asm_806DF6D4(0x5A) == 0) {
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        if (current_actor_pointer->control_state_progress == 1) {
                            var_f2 = MAX(current_actor_pointer->unkB8 * 0.025, 0.1);
                            func_global_asm_80614D00(current_actor_pointer, var_f2, 1.0f);
                            // func_global_asm_80614D00(current_actor_pointer, 0.1, var_f2, 1.0f);
                        } else {
                            func_global_asm_80614E78(current_player, 0x77);
                            current_actor_pointer->control_state_progress = 1;
                        }
                        break;
                    case 0:
                        if (current_actor_pointer->control_state_progress != 2) {
                            func_global_asm_80614E78(current_player, 0x76);
                            current_actor_pointer->control_state_progress = 2;
                        }
                        break;
                    case 1:
                        if (current_actor_pointer->control_state_progress == 3) {
                            var_f2 = MAX(current_actor_pointer->unkB8 * 0.025, 0.1);
                            // func_global_asm_80614D00(0.1, current_actor_pointer, var_f2_2, 0, current_actor_pointer);
                            func_global_asm_80614D00(current_actor_pointer, var_f2, 0);
                        } else {
                            func_global_asm_80614E78(current_player, 0x78);
                            current_actor_pointer->control_state_progress = 3;
                        }
                        break;
                }
            }
            current_actor_pointer->y_velocity = 0.0f;
            current_actor_pointer->unkB8 = extra_player_info_pointer->unk4;
            if (func_global_asm_806CFC90(current_actor_pointer, &sp64, 1, 15.0f) != 0) {
                if ((current_actor_pointer->y_position <= sp64) && (((sp64 - sp50) - current_actor_pointer->y_position) < 10.0f) && (func_global_asm_80666AEC() != 0)) {
                    current_actor_pointer->y_position = sp64 - sp50;
                    sp49 = 1;
                }
            }
            if (current_actor_pointer->unkB8 < 0) {
                current_actor_pointer->unkB8 = ABS(current_actor_pointer->unkB8);
                current_actor_pointer->unkEE = current_actor_pointer->unkF4 + 0xA;
                sp60 = (extra_player_info_pointer->unkEA + 0x400) & 0xFFF;
            } else if (current_actor_pointer->unkB8 > 0) {
                current_actor_pointer->unkEE = current_actor_pointer->unkF6 - 0xA;
                sp60 = (extra_player_info_pointer->unkEA - 0x400) & 0xFFF;
            }
            sp62 = func_global_asm_8066F1F8(current_actor_pointer, sp60);
            if (sp62 == 0) {
                current_actor_pointer->unkB8 = 0;
            }
            extra_player_info_pointer->unkEC = func_global_asm_80672A70(current_actor_pointer->unkF4, current_actor_pointer->unkF6) + 0x800;
            extra_player_info_pointer->unkEC &= 0xFFF;
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkEC, 3.0f);
            current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
            current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
            if ((sp62 == 0) || (current_actor_pointer->unkB8 == 0.0)) {
                current_actor_pointer->object_properties_bitfield |= 0x800;
            } else {
                current_actor_pointer->object_properties_bitfield &= ~0x800;
            }
            break;
    }
    var_v0 = D_global_asm_807FD610[cc_player_index].unk2F < -0x32 && (D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG) != 0;
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        var_a2_2 = (var_v0 | ((current_actor_pointer->y_position - current_actor_pointer->floor) < D_global_asm_80753DA8[D_global_asm_807FD584]));
    } else {
        var_a2_2 = (var_v0 | ((current_actor_pointer->y_position - current_actor_pointer->floor) < D_global_asm_80753DB8[D_global_asm_807FD584]));
    }
    var_v1_2 = 0;
    if (extra_player_info_pointer->unkF8 == 0) {
        var_v0_2 = current_actor_pointer->unkFC == 0 || sp49 == 0;
        // var_v0_2 = current_actor_pointer->unkFC == 0;
        // if (var_v0_2 == 0) {
        //     var_v0_2 = sp49 == 0;
        // }
        sp4F = var_v0_2;
        func_global_asm_80666AC4(&sp4C, &sp4A);
        var_v1_2 = sp4F;
        if (sp4A < 0x385) {
            sp4F = (var_v0_2 | 1);
        }
    }
    if ((var_a2_2 != 0) || (sp4F != 0)) {
        extra_player_info_pointer->unkFC_s32 = 0x14;
        func_global_asm_806CFF9C(current_actor_pointer);
        current_actor_pointer->object_properties_bitfield &= ~0x800;
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2F >= 0x33) && (extra_player_info_pointer->unkF8 == 0) && (var_v1_2 == 0)) {
        func_global_asm_80614E78(current_player, 0x79);
        current_actor_pointer->control_state = 0x5C;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unkF0_f32 = current_actor_pointer->y_position + sp50;
        extra_player_info_pointer->unkF4_f32 = extra_player_info_pointer->unkF0_f32;
    }
    func_global_asm_80665160(current_actor_pointer, current_actor_pointer->unkEE, current_actor_pointer->unkEE);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665548();
    func_global_asm_80665564(current_actor_pointer, 0);
    renderActor(current_actor_pointer, 0);
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DE264.s")

void func_global_asm_806DE930(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    if (!func_global_asm_806DF6D4(1)) {
        if (current_actor_pointer->unk6A & 1) {
            func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, 0.0f, 1);
        }
    }
    if (current_map == MAP_CAVES_BEETLE_RACE) {
        extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584] * 5.0;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DE9F4(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        func_global_asm_8061C464(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x800, 0x32, 0, 5, 0x32, 0x14, 0, 0.2f);
        current_actor_pointer->control_state_progress += 1;
    }
    func_global_asm_806D38AC(1);
    extra_player_info_pointer->unk30 = D_global_asm_80750FDC;
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DEAA4.s")

void func_global_asm_806DECD4(void) {
    if (current_actor_pointer->control_state_progress == 1) {
        func_global_asm_8061CB08();
        current_actor_pointer->control_state_progress++;
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DED44(void) {
    BoulderAAD *aaD;
    s8 cutsceneIndex;
    s32 i;

    func_global_asm_806DF6D4(1);
    func_global_asm_806D9924(current_actor_pointer);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            // Have all fairies been photographed?
            if (func_global_asm_806F8EB4() == 20) {
                cutsceneIndex = 0x1A;
            } else {
                cutsceneIndex = 0x11;
            }
            playCutscene(current_actor_pointer, cutsceneIndex, 5);
            current_actor_pointer->control_state_progress = 1;
            break;
        case 1:
            global_properties_bitfield &= 0xFFFEFFCF;
            spawnActor(ACTOR_FAIRY_REFILL, 0x3D);
            func_global_asm_8067B238(
                last_spawned_actor,
                current_actor_pointer,
                current_actor_pointer->animation_state->scale_y * 2
            );
            last_spawned_actor->object_properties_bitfield |= 0x40000000;
            last_spawned_actor->y_rotation += 0x800;
            last_spawned_actor->y_rotation &= 0xFFF;
            last_spawned_actor->unk11C = current_actor_pointer;
            func_global_asm_80614EBC(last_spawned_actor, 0x2B7);
            aaD = last_spawned_actor->additional_data_pointer;
            aaD->unk10 = current_actor_pointer;
            aaD->unk18 = current_actor_pointer->unk12C;
            if (aaD->unk18 == -1) {
                aaD->unk18 = 0;
            }
            aaD->unk16 = current_actor_pointer->z_rotation;
            aaD->unk14 = current_actor_pointer->x_rotation;
            func_global_asm_80659620(aaD, &aaD->unk4, &aaD->unk8, aaD->unk18);
            func_global_asm_80659670(1.0f, 1.0f, 1.0f, aaD->unk18);
            spawnActor(ACTOR_SPOTLIGHT, 0xA8);
            func_global_asm_8067B238(last_spawned_actor,
                          current_actor_pointer,
                          current_actor_pointer->animation_state->scale_x);
            last_spawned_actor->object_properties_bitfield |= 0x40000000;
            aaD->unkC = last_spawned_actor;
            aaD->unk1E = func_global_asm_806F8EB4() == 20; // Have all fairies been photographed?
            current_actor_pointer->control_state_progress = 2;
            break;
        case 2:
            if (func_global_asm_80629148()) {
                func_global_asm_80629174();
                func_global_asm_806874EC();
                playSong(0x3B, 1.0f);
                current_actor_pointer->control_state_progress = 3;
            }
            // fallthrough
        case 3:
            if (func_global_asm_80629148()) {
                PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
                func_global_asm_80629174();
                func_global_asm_806CFF9C(current_actor_pointer);
                func_global_asm_80709464(PaaD->unk1A4);
                
                for (i = 0; i < 4; i++) {
                    func_global_asm_806F91B4(D_global_asm_80750FE0[i], 0, 9999);
                    func_global_asm_806F8BC4(D_global_asm_80750FE0[i], 0, 0);
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF050(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    func_global_asm_806EB0C0(0x5C, NULL, cc_player_index);
    if (D_global_asm_80750AB8 == 0) {
        character_change_array[PaaD->unk1A4].unk2EA = 1;
    }
    character_change_array[PaaD->unk1A4].unk2EB = 1;
    current_actor_pointer->object_properties_bitfield &= ~0x8000;
    current_actor_pointer->shadow_opacity -= current_actor_pointer->shadow_opacity < 4 ? current_actor_pointer->shadow_opacity : 4;
    if (current_actor_pointer->shadow_opacity == 0) {
        if (D_global_asm_80750AB8 == 0) {
            character_change_array[PaaD->unk1A4].does_player_exist = 0;
        }
        current_actor_pointer->object_properties_bitfield &= -5;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF1A0(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    current_actor_pointer->animation_state->scale_x = current_actor_pointer->animation_state->scale_x * 0.92;
    current_actor_pointer->animation_state->scale_y = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->x_position += ((PaaD->unk22C - current_actor_pointer->x_position) * 0.125f);
    current_actor_pointer->y_position += ((PaaD->unk230 - current_actor_pointer->y_position) * 0.125f);
    current_actor_pointer->z_position += ((PaaD->unk234 - current_actor_pointer->z_position) * 0.125f);
    current_actor_pointer->x_rotation += 0xFF;
    renderActor(current_actor_pointer, 0);
}

// GOOD RODATA
void func_global_asm_806DF280(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;

    current_actor_pointer->animation_state->scale_x *= 1.08;
    if (0.15 < current_actor_pointer->animation_state->scale_x) {
        current_actor_pointer->animation_state->scale_x = 0.15f;
        current_actor_pointer->control_state = 0xC;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->x_rotation = -0xFF;
    }
    current_actor_pointer->animation_state->scale_y = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->animation_state->scale_z = current_actor_pointer->animation_state->scale_x;
    current_actor_pointer->x_position += PaaD->unk220;
    current_actor_pointer->z_position += PaaD->unk228;
    current_actor_pointer->x_rotation += 0xFF;
    current_actor_pointer->x_rotation &= 0xFFF;
    renderActor(current_actor_pointer, 0);
}
