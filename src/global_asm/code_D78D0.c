#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

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

extern SpriteData D_global_asm_8071FC58; // TODO: Sprite
extern SpriteData D_global_asm_8071FCC0; // TODO: Sprite
extern SpriteData D_global_asm_8071FF18;
extern SpriteData D_global_asm_8072014C;

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
extern s16 D_global_asm_80753558[];
extern s16 D_global_asm_80753568[];
extern f32 D_global_asm_80753604[];
extern f32 D_global_asm_80753620[];
extern f32 D_global_asm_8075363C[];
extern f32 D_global_asm_80753674[];
extern f32 D_global_asm_80753690[];
extern f32 D_global_asm_807536C8[];
extern f32 D_global_asm_807536E4[];
extern f32 D_global_asm_80753738[];
extern f32 D_global_asm_80753770[];
extern f32 D_global_asm_807537A8[];
extern f32 D_global_asm_807537C4[];
extern s16 D_global_asm_8075387C[];
extern s16 D_global_asm_8075388C[];
extern s16 D_global_asm_807538B8[];
extern s16 D_global_asm_807538C8[];
extern s16 D_global_asm_807539DC[];
extern s16 D_global_asm_807539EC[];
extern f32 D_global_asm_80753A5C[];
extern f32 D_global_asm_80753AFC[];
extern f32 D_global_asm_80753C30[];
extern f32 D_global_asm_80753C4C[];
extern f32 D_global_asm_80753C68[];
extern s16 D_global_asm_80753C84[];
extern s16 D_global_asm_80753CA4[];
extern f32 D_global_asm_80753CB4[];

extern s32 D_global_asm_80767CC0;

extern s32 D_global_asm_807FBB68;
extern f32 D_global_asm_807FBC58;

s32 handleInputsForControlState(s32 arg0);
void func_global_asm_806CD424(s16, f32, f32); // TODO: Is this signature correct?
extern void func_global_asm_807300BC(); // TODO: Proper signature

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
    s32 newControlState;
    s32 phi_a1;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    current_actor_pointer->unk64 |= 0x200;
    phi_a1 = 0x13;
    if (current_actor_pointer->control_state_progress != 0) {
        current_actor_pointer->control_state_progress--;
        phi_a1 = 0x14;
    }
    if (object_timer > 1U && !handleInputsForControlState(phi_a1)) {
        newControlState = func_global_asm_806CDD24(current_actor_pointer, current_actor_pointer->unkB8, extra_player_info_pointer->unk4, 1);
        if (newControlState != 0xC) {
            current_actor_pointer->control_state = (u8)newControlState & 0xFF;
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
    handleInputsForControlState(0x1B);

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
        playActorAnimation(current_actor_pointer, var_a1);
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
        playSoundAtActorPosition(current_actor_pointer, 1, 0xFF, 0x7F, 0x1E);
    }
    if (func_global_asm_8061CB50() == 0) {
        func_global_asm_806CC948();
        if ((func_global_asm_806F8AD4(5, cc_player_index) != 0) && !(extra_player_info_pointer->unk1F0 & 0x10000)) {
            changeCollectableCount(5, cc_player_index, -1);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3224(void) {
    u32 newControlState;

    current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
    if (handleInputsForControlState(0x1D) == 0) {
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
        handleInputsForControlState(0x1F);
    } else {
        handleInputsForControlState(0x1E);
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
    if (handleInputsForControlState(0x13) == 0) {
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
    if (handleInputsForControlState(0x1C) == 0) {
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
        setAction(0x2D, NULL, cc_player_index);
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
                setAction(0x2C, NULL, cc_player_index);
            }
        }
    }
}

void func_global_asm_806D36CC(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x20);
            func_global_asm_806D3608();
            break;
        case 1:
            handleInputsForControlState(0x31);
            setYAccelerationFrom80753578();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D374C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x20);
            func_global_asm_806D3608();
            break;
        case 1:
            handleInputsForControlState(0x32);
            setYAccelerationFrom80753578();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D37CC(void) {
    if (current_actor_pointer->control_state_progress == 0) {
        handleInputsForControlState(0x20);
        func_global_asm_806CC8B8();
        if (current_actor_pointer->unk6A & 1) {
            if (current_actor_pointer->unkE0 != 0.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            } else {
                setYAccelerationFrom80753578();
                setAction(0x35, NULL, cc_player_index);
            }
        }
    } else {
        handleInputsForControlState(0x20);
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
            setYAccelerationFrom80753578();
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
        playAnimation(current_actor_pointer, 0x67);
    }
    handleInputsForControlState(arg0);
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

void func_global_asm_806D3AC8(void) {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3AE8(void) {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B08(void) {
    func_global_asm_806D38AC(0x3D);
}

void func_global_asm_806D3B28(void) {
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
    handleInputsForControlState(0x3E);
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
                setYAccelerationFrom80753578();
                current_actor_pointer->control_state = 0xF;
                current_actor_pointer->control_state_progress = 0;
                playAnimation(current_actor_pointer, 0x5E);
            } else {
                func_global_asm_806D3530();
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D3CD4(void) {
    func_global_asm_80685210(0.5f, 0x64, 5);
    handleInputsForControlState(0x3C);
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
    handleInputsForControlState(0x3B);
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
            handleInputsForControlState(0x41);
            playAnimation(current_actor_pointer, 5);
            extra_player_info_pointer->unk30 = D_global_asm_8075327C[D_global_asm_807FD584];
            func_global_asm_806CD8EC();
            func_global_asm_806CC948();
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            handleInputsForControlState(0x41);
            func_global_asm_806CD8EC();
            func_global_asm_806CC948();
            break;
        case 2:
            handleInputsForControlState(0x41);
            func_global_asm_806CD8EC();
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, D_global_asm_80753298[D_global_asm_807FD584], 0xC00);
            func_global_asm_806CC948();
            break;
        case 3:
            handleInputsForControlState(0x41);
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
            handleInputsForControlState(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x21);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                handleInputsForControlState(0x22);
            } else {
                handleInputsForControlState(0x21);
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
                    playAnimation(current_actor_pointer, 0x13);
                }
            }
            handleInputsForControlState(0x30);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D423C(void) {
    current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
    handleInputsForControlState(5);
    func_global_asm_806CC8F0();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D428C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x2C);
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
            handleInputsForControlState(0x21);
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
                handleInputsForControlState(0x22);
            } else {
                handleInputsForControlState(0x21);
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
                    playAnimation(current_actor_pointer, 0x13);
                }
            }
            handleInputsForControlState(0x30);
            func_global_asm_806CC8B8();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D45A4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x21);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                handleInputsForControlState(0x22);
            } else {
                handleInputsForControlState(0x21);
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
            handleInputsForControlState(0x46);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D4758(void) {
    if (current_actor_pointer->control_state_progress) {
        // Probably some ifdef'd out code
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk3E != 0) {
                if (func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40)) {
                    // Probably some ifdef'd out code
                }
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 50.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            handleInputsForControlState(0x23);
            if (current_character_index[cc_player_index] == 2) {
                extra_player_info_pointer->unk4 *= 0.63;
            }
            func_global_asm_806CC8B8();
            break;
        case 1:
            handleInputsForControlState(0x23);
            if (current_character_index[cc_player_index] == 0 || current_character_index[cc_player_index] == 2) {
                extra_player_info_pointer->unk4 *= 0.63;
            }
            setYAccelerationFrom80753578();
            func_global_asm_806D3608();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            if (!handleInputsForControlState(0x31)) {
                if (current_actor_pointer->unkB8 < extra_player_info_pointer->unk4) {
                    func_global_asm_806CFF9C(current_actor_pointer);
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D491C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x26);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x25);
            func_global_asm_806CFD68();
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            handleInputsForControlState(0x25);
            func_global_asm_806CFD68();
            func_global_asm_806D3608();
            break;
        case 3:
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
            }
            handleInputsForControlState(0x34);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D4A70(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            if (extra_player_info_pointer->unk3E) {
                if (func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40)) {
                    // Probably some ifdef'd out code
                }
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 50.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806CC8B8();
            if (current_actor_pointer->y_velocity <= -15.0f) {
                current_actor_pointer->y_velocity = -15.0f;
                current_actor_pointer->control_state_progress++;
            }
            handleInputsForControlState(0x24);
            if (current_actor_pointer->unk6A & 1) {
                func_global_asm_806F142C(current_actor_pointer);
            }
            break;
        case 1:
            handleInputsForControlState(0x24);
            if (extra_player_info_pointer->unk3E) {
                if (func_global_asm_806CC14C(current_actor_pointer->unkEE, extra_player_info_pointer->unk40)) {
                    // Probably some ifdef'd out code
                }
                func_global_asm_806CD424(extra_player_info_pointer->unk40, 30.0f, extra_player_info_pointer->unk38);
                extra_player_info_pointer->unk3E--;
            }
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unk6A & 1) {
                func_global_asm_806F142C(current_actor_pointer);
                playSoundAtActorPosition(current_actor_pointer, 1, 0xFF, 0x7F, 0x1E);
            }
            break;
        case 2:
            current_actor_pointer->y_acceleration = -4.0f;
            handleInputsForControlState(0x24);
            func_global_asm_806CC8B8();
            if ((current_actor_pointer->unk6A & 1) != 0) {
                func_global_asm_806F142C(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D4C7C(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            handleInputsForControlState(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_8075363C[D_global_asm_807FD584];
            current_actor_pointer->control_state_progress++;
            func_global_asm_806D3FA0();
            handleInputsForControlState(0x2B);
            extra_player_info_pointer->unk38 = D_global_asm_80753620[D_global_asm_807FD584];
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            handleInputsForControlState(0x2B);
            func_global_asm_806CFDEC();
            func_global_asm_806D3608();
            break;
        case 3:
            handleInputsForControlState(0x2B);
            setYAccelerationFrom80753578();
            func_global_asm_806CC8B8();
            break;
        case 4:
            handleInputsForControlState(0x30);
            setYAccelerationFrom80753578();
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
            handleInputsForControlState(0x2C);
            func_global_asm_806CC8B8();
            break;
        case 1:
            current_actor_pointer->y_velocity = D_global_asm_80753674[D_global_asm_807FD584];
            current_actor_pointer->y_acceleration = D_global_asm_80753690[D_global_asm_807FD584];
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x2B);
            func_global_asm_806CC8B8();
            break;
        case 2:
            func_global_asm_806CC8B8();
            handleInputsForControlState(0x2D);
            func_global_asm_806D3608();
            break;
        case 3:
            handleInputsForControlState(0x36);
            func_global_asm_806CC8B8();
            break;
        case 4:
            handleInputsForControlState(0x36);
            func_global_asm_806CC8B8();
            break;
        case 5:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_807536E4[D_global_asm_807FD584];
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x2B);
            extra_player_info_pointer->unk38 = D_global_asm_807536C8[D_global_asm_807FD584];
            func_global_asm_806CC8B8();
            break;
        case 6:
            func_global_asm_806CC8B8();
            handleInputsForControlState(0x2C);
            func_global_asm_806CFDA8();
            func_global_asm_806D3608();
            break;
        case 7:
            handleInputsForControlState(0x30);
            setYAccelerationFrom80753578();
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
            handleInputsForControlState(0x2E);
            func_global_asm_806CC970();
            break;
        case 1:
            handleInputsForControlState(0x2E);
            current_actor_pointer->y_acceleration = -30.0f;
            current_actor_pointer->unkB8 = 0.0f;
            current_actor_pointer->y_velocity = -100.0f;
            current_actor_pointer->control_state_progress++;
            func_global_asm_806CC948();
            break;
        case 2:
            handleInputsForControlState(0x2E);
            func_global_asm_806D3608();
            func_global_asm_806CC948();
            break;
        case 3:
            handleInputsForControlState(0x2E);
            if (!(current_actor_pointer->unk6A & 4)) {
                playSoundAtActorPosition(current_actor_pointer, 0x96, 0xFF, 0x7F, 0x19);
                func_global_asm_80685708(current_actor_pointer, D_global_asm_807FD568->simian_slam);
                func_global_asm_8061F0B0(extra_player_info_pointer->unk104, 0x14, (D_global_asm_807FD568->simian_slam * 5));
            }
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            current_actor_pointer->control_state_progress++;
            func_global_asm_806CC948();
            break;
        case 4:
            handleInputsForControlState(0x2E);
            func_global_asm_806CC948();
            break;
        case 5:
            handleInputsForControlState(0x2F);
            current_actor_pointer->control_state_progress++;
            func_global_asm_806CC8B8();
            break;
        case 6:
            handleInputsForControlState(0x2F);
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
            handleInputsForControlState(5);
            func_global_asm_806CC8B8();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5300(void) {
    s32 pad;
    f32 x, y, z;
    f32 scale;
    f32 randomZOffset;
    f32 randomXOffset;
    f32 randomYOffset;
    s32 phi_s1;

    if ((current_actor_pointer->control_state_progress < 2) || (D_global_asm_80750FD8 < current_actor_pointer->unkB8)) {
        scale = current_actor_pointer->animation_state->scale_y / 0.15;
        getBonePosition(current_actor_pointer, 7, &x, &y, &z);
        for (phi_s1 = 0; phi_s1 < D_global_asm_80750FD4; phi_s1++) {
            randomXOffset = (((rand() >> 0xF) % 10000) % D_global_asm_80750FC8) - (D_global_asm_80750FC8 / 2);
            randomYOffset = (((rand() >> 0xF) % 10000) % D_global_asm_80750FCC) - (D_global_asm_80750FCC / 2);
            randomZOffset = (((rand() >> 0xF) % 10000) % D_global_asm_80750FD0) - (D_global_asm_80750FD0 / 2);
            func_global_asm_80714950(D_global_asm_80750FC4);
            func_global_asm_8071498C(func_global_asm_80717D4C);
            func_global_asm_807149B8(1);
            drawSpriteAtPosition(D_global_asm_8074E880[((rand() % 10000) % 3)],
                D_global_asm_80750FC0 * scale,
                (randomXOffset * scale) + x,
                (randomYOffset * scale) + y,
                (randomZOffset * scale) + z
            );
        }
    }
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(5);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            handleInputsForControlState(5);
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
            handleInputsForControlState(5);
            break;
        case 3:
            current_actor_pointer->unkB8 = 0.0f;
            handleInputsForControlState(5);
            func_global_asm_806F142C(current_actor_pointer);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D57F0(void) {
    handleInputsForControlState(1);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D5834(void) {
    if (current_actor_pointer); // TODO: Yikes, fakematch? fake match?

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= 1.8;
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0 - 0x64;
            extra_player_info_pointer->unk48 = 0x50;
            // Fallthrough
        case 1:
            handleInputsForControlState(9);
            extra_player_info_pointer->unk30 = 10.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x32U) {
                if (current_character_index[cc_player_index] == 2) {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                    playAnimation(current_actor_pointer, 0x40);
                } else {
                    current_actor_pointer->control_state = 0x28;
                    current_actor_pointer->control_state_progress = 0;
                    playAnimation(current_actor_pointer, 0x41);
                }
            }
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D59E4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 /= 1.8;
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0 - 0x64;
            // Fallthrough
        case 1:
            handleInputsForControlState(9);
            extra_player_info_pointer->unk30 = 10.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x32U) {
                current_actor_pointer->control_state = 0x28;
                current_actor_pointer->control_state_progress = 0;
                playAnimation(current_actor_pointer, 0x41);
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
            handleInputsForControlState(0xA);
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48 * 1.25);
            break;
        case 2:
            handleInputsForControlState(0xA);
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
                    handleInputsForControlState(0x17);
                    func_global_asm_806CC948();
                    break;
                case 1:
                    func_global_asm_806CFECC();
                    handleInputsForControlState(0x16);
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
                    handleInputsForControlState(0x15);
                    extra_player_info_pointer->unk4 = 0.0f;
                    func_global_asm_806CC8B8();
                    break;
                case 1:
                    current_actor_pointer->unkB8 = D_global_asm_807531FC[D_global_asm_807FD584];
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
                    handleInputsForControlState(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    current_actor_pointer->y_velocity = 150.0f;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = 200.0f;
                    handleInputsForControlState(0x15);
                    extra_player_info_pointer->unk4 = 200.0f;
                    func_global_asm_806CC8B8();
                    current_actor_pointer->control_state_progress++;
                    break;
                case 3:
                    current_actor_pointer->unkB8 = 200.0f;
                    extra_player_info_pointer->unk38 = 200.0f;
                    handleInputsForControlState(0x15);
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
                    handleInputsForControlState(0x15);
                    func_global_asm_806CC948();
                    break;
                case 1:
                    extra_player_info_pointer->unk30 = 20.0f;
                    extra_player_info_pointer->unk2C = 20.0f;
                    extra_player_info_pointer->unk38 = D_global_asm_807531FC[D_global_asm_807FD584];
                    handleInputsForControlState(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    extra_player_info_pointer->unk28 = 1;
                    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk5C) < 0x14U) {
                        current_actor_pointer->control_state = 0x26;
                        current_actor_pointer->control_state_progress = 0;
                        playAnimation(current_actor_pointer, 0x3F);
                    }
                    handleInputsForControlState(0x15);
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
                    handleInputsForControlState(0x15);
                    extra_player_info_pointer->unk30 = 10.0f;
                    func_global_asm_806CD8EC();
                    func_global_asm_806CC948();
                    break;
                case 1:
                    extra_player_info_pointer->unk2C = 30.0f;
                    extra_player_info_pointer->unk68 = D_global_asm_807531FC[D_global_asm_807FD584];
                    func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
                    handleInputsForControlState(0x15);
                    func_global_asm_806CC948();
                    break;
                case 2:
                    extra_player_info_pointer->unk28 = 1;
                    handleInputsForControlState(0x15);
                    func_global_asm_806CC8B8();
                    break;
                }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D61B8(void) {
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    func_global_asm_806D3608();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 = 0.2f;
            extra_player_info_pointer->unk2C = 10.0f;
            extra_player_info_pointer->unk48 = 0x32;
            extra_player_info_pointer->unk68 = D_global_asm_80753568[D_global_asm_807FD584];
            handleInputsForControlState(0x18);
            if (current_actor_pointer->unkE0 != 0.0f) {
                extra_player_info_pointer->unk30 = 20.0f;
                func_global_asm_806CD8EC();
            } else {
                func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
            }
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48);
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.9;
            }
            break;
        case 1:
            handleInputsForControlState(0x18);
            func_global_asm_806CC948();
            current_actor_pointer->y_velocity = 150.0f;
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            handleInputsForControlState(0x18);
            func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk68);
            func_global_asm_806CC948();
            func_global_asm_806DF494(&current_actor_pointer->unkEE, current_actor_pointer->y_rotation, extra_player_info_pointer->unk48);
            break;
        case 3:
            extra_player_info_pointer->unk30 = D_global_asm_80753558[D_global_asm_807FD584];
            if (current_character_index[cc_player_index] == 0) {
                handleInputsForControlState(0x19);
            } else {
                handleInputsForControlState(0x19);
            }
            func_global_asm_806CC8B8();
            break;
        case 4:
            extra_player_info_pointer->unk30 = D_global_asm_80753558[D_global_asm_807FD584];
            if (current_character_index[cc_player_index] == 0) {
                handleInputsForControlState(0x19);
            } else {
                handleInputsForControlState(0x19);
            }
            func_global_asm_806CC8B8();
            if (extra_player_info_pointer->unk4 != 0.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            break;
        case 5:
            handleInputsForControlState(5);
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D6558(void) {
    func_global_asm_806D3608();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk30 = 20.0f;
            func_global_asm_806CD8EC();
            func_global_asm_806CC970();
            break;
        case 1:
            handleInputsForControlState(0x1A);
            if (extra_player_info_pointer->unk68 < current_actor_pointer->unkB8) {
                extra_player_info_pointer->unk68 = current_actor_pointer->unkB8;
            }
            if (current_actor_pointer->unkFC != 0) {
                if (D_global_asm_8075352C[D_global_asm_807FD584] < current_actor_pointer->unkB8) {
                    current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                    extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
                }
            }
            if ((current_actor_pointer->unkFC != 0) && (func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->y_rotation) == 0)) {
                playAnimation(current_actor_pointer, 0x49);
                current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
                current_actor_pointer->control_state_progress = 3;
                current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
            } else {
                func_global_asm_806CBE90();
                if (current_actor_pointer->unkE0 != 0.0f) {
                    extra_player_info_pointer->unk30 = 20.0f;
                    func_global_asm_806CD8EC();
                } else {
                    func_global_asm_806CD424(current_actor_pointer->y_rotation, extra_player_info_pointer->unk68, extra_player_info_pointer->unk38);
                }
                func_global_asm_806CC948();
                break;
            }
            break;
        case 2:
            handleInputsForControlState(0x1A);
            if ((current_actor_pointer->unkFC != 0) && (func_global_asm_806725A0(current_actor_pointer, current_actor_pointer->y_rotation) == 0)) {
                playAnimation(current_actor_pointer, 0x49);
                current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
                current_actor_pointer->control_state_progress++;
                current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
            } else {
                func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
                func_global_asm_806CBE90();
                func_global_asm_806CD8EC();
                func_global_asm_806CC948();
                extra_player_info_pointer->unk30 = D_global_asm_80753548[D_global_asm_807FD584];
                break;
            }
            break;
        case 3:
            handleInputsForControlState(5);
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
        case 4:
            handleInputsForControlState(5);
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

s32 func_global_asm_806D69A4(void) {
    if (current_actor_pointer->unkFC != 0) {
        if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, ((((current_actor_pointer->unkF6 - current_actor_pointer->unkF4) & 0xFFF) / 2) + current_actor_pointer->unkF4 + 0x800) & 0xFFF) < 0x2BC) {
            if (current_actor_pointer->unkB8 > 150.0f) {
                playAnimation(current_actor_pointer, 0x49);
                current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
                current_actor_pointer->control_state_progress = 2;
                current_actor_pointer->unkB8 = D_global_asm_8075352C[D_global_asm_807FD584];
                extra_player_info_pointer->unk68 = D_global_asm_8075352C[D_global_asm_807FD584];
            } else {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            return TRUE;
        }
        func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, extra_player_info_pointer->unk48);
    }
    return FALSE;
}

void func_global_asm_806D6B00(void) {
    func_global_asm_806D3608();
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk28 = 0;
            handleInputsForControlState(0x1A);
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
            handleInputsForControlState(0x1A);
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
                        func_global_asm_8071498C(func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 2, 0);
                    }
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 3, 0);
                    }
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 9, 0);
                    }
                    if ((func_global_asm_806119A0() % 3U) == 0) { // RNG
                        func_global_asm_8071498C(func_global_asm_8071B2EC);
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_80714C08(&D_global_asm_8071FF18, 0.2f, current_actor_pointer, 0xA, 0);
                    }
                }
                break;
            }
        case 2:
            handleInputsForControlState(5);
            current_actor_pointer->unkEE = (current_actor_pointer->y_rotation + 0x800) % 4096;
            func_global_asm_806CC8A8();
            func_global_asm_806CBE90();
            func_global_asm_806CC948();
            break;
        case 3:
            handleInputsForControlState(5);
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
    handleInputsForControlState(8);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D6F64(void) {
    setAction(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(3);
            extra_player_info_pointer->unk4 = D_global_asm_8075305C[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, ((current_actor_pointer->unkEE + 0x800) & 0xFFF), extra_player_info_pointer->unk48 << 1);
            break;
        case 1:
            handleInputsForControlState(3);
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
    handleInputsForControlState(3);
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
    setAction(0x3C, NULL, cc_player_index);
    handleInputsForControlState(3);
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
    setAction(0x5C, NULL, cc_player_index);
    handleInputsForControlState(3);
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

    setAction(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(3);
            extra_player_info_pointer->unk4 = D_global_asm_807530F0[D_global_asm_807FD584];
            extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
            current_actor_pointer->y_rotation = func_global_asm_806CC190(current_actor_pointer->y_rotation, extra_player_info_pointer->unkDC->y_rotation + 0x800, 8.0f);
            func_global_asm_806CC8B8();
            break;
        case 1:
            handleInputsForControlState(3);
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
            setAction(0x3C, NULL, cc_player_index);
            handleInputsForControlState(4);
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, (current_actor_pointer->unkEE + 0x800) & 0xFFF, (extra_player_info_pointer->unk48) << 0x1);
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.5;
            }
            break;
        case 1:
            setAction(0x3C, NULL, cc_player_index);
            extra_player_info_pointer->unk4 = 0.0f;
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = current_actor_pointer->unkB8 * 0.5;
            }
            break;
        case 2:
            current_actor_pointer->unkB8 = 0.0f;
            setAction(0x18, NULL, cc_player_index);
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
    setAction(0x3C, NULL, cc_player_index);
    current_actor_pointer->unk64 |= 0x200;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->unkB8 = D_global_asm_80753144[D_global_asm_807FD584];
            handleInputsForControlState(5);
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
            handleInputsForControlState(3);
            current_actor_pointer->unkB8 = 0.0f;
            break;
        case 2:
            handleInputsForControlState(3);
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
    setAction(0x3C, NULL, cc_player_index);
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
    setAction(0x3C, NULL, cc_player_index);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D7A28(void) {
    u8 temp_v0;

    setAction(0x3C, NULL, cc_player_index);
    handleInputsForControlState(1);
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
                        playSoundAtActorPosition(current_actor_pointer, ((extra_player_info_pointer->unk11C & 2) / 2) + 0x57, 0xFF, 0x7F, 0x1E);
                    }
                } else if (temp_v0 != 0) {
                    func_global_asm_80712830(current_actor_pointer, cc_player_index);
                }
            }
            if (((extra_player_info_pointer->unk1F0 & 0x1000) != 0) && ((object_timer & 3) == 0)) {
                changeActorColor(0x64, 0x64, 0x64, 0xC8);
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
            handleInputsForControlState(0x45);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            handleInputsForControlState(0x44);
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
            handleInputsForControlState(0x46);
            extra_player_info_pointer->unk4 = 0.0f;
            break;
        case 1:
            if (handleInputsForControlState(0x46) == 0) {
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
    if (!handleInputsForControlState(0x46)) {
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
            handleInputsForControlState(1);
            break;
        case 1:
            current_actor_pointer->control_state = 0x3C;
            current_actor_pointer->control_state_progress = 1;
            playAnimation(current_actor_pointer, 0xB);
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D8070(void) {
    handleInputsForControlState(1);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D80A8(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            handleInputsForControlState(0x47);
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
            handleInputsForControlState(0x47);
            func_global_asm_806CFE30();
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            func_global_asm_806CFE30();
            func_global_asm_806D3608();
            func_global_asm_806CC8B8();
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            handleInputsForControlState(0x47);
            break;
        case 3:
            handleInputsForControlState(0x35);
            if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
                func_global_asm_80614D00(current_actor_pointer, 3.0f, 0.0f);
            }
            extra_player_info_pointer->unk4 = 0.0f;
            setYAccelerationFrom80753578();
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D8308(void) {
    Actor *var_a3;
    PlayerAdditionalActorData *temp_v0;

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->unkEA = current_actor_pointer->unkEE;
            func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            handleInputsForControlState(0x48);
            func_global_asm_806CC948();
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            current_actor_pointer->y_acceleration = D_global_asm_807537A8[D_global_asm_807FD584];
            current_actor_pointer->unkB8 = D_global_asm_80753770[D_global_asm_807FD584];
            current_actor_pointer->unkEA = current_actor_pointer->unkEE;
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x48);
            func_global_asm_806CFE30();
            func_global_asm_806CC948();
            break;
        case 2:
            func_global_asm_806CFE30();
            func_global_asm_806D3608();
            func_global_asm_806CC948();
            handleInputsForControlState(0x48);
            break;
        case 3:
            extra_player_info_pointer->unk30 = D_global_asm_807537C4[D_global_asm_807FD584];
            handleInputsForControlState(0x33);
            setYAccelerationFrom80753578();
            func_global_asm_806CC8B8();
            break;
        case 4:
            if (extra_player_info_pointer->unk4 > 10.0f) {
                func_global_asm_806CFF9C(current_actor_pointer);
            }
            extra_player_info_pointer->unk30 = D_global_asm_807537C4[D_global_asm_807FD584];
            handleInputsForControlState(0x33);
            setYAccelerationFrom80753578();
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
            playAnimation(current_actor_pointer, 0x36);
            func_global_asm_80613AF8(current_actor_pointer, 0x31, 0.0f, 8.0f);
            func_global_asm_80614D00(current_actor_pointer, 0.5f, 0.0f);
            playSoundAtActorPosition(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
        }
    }
    if (current_actor_pointer->unkAC < (current_actor_pointer->y_position + sp2C)) {
        current_actor_pointer->y_position = current_actor_pointer->unkAC - sp2C;
    }
    phi_f2 = character_change_array[cc_player_index].unk2C0 == 1 ? D_global_asm_8075387C[D_global_asm_807FD584] : D_global_asm_807538B8[D_global_asm_807FD584];
    if ((current_actor_pointer->unkAC - current_actor_pointer->floor) < phi_f2) {
        setAction(2, NULL, cc_player_index);
        return TRUE;
    }
    return FALSE;
}

// close, float
// https://decomp.me/scratch/en55B
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
            handleInputsForControlState(0x4E);
            func_global_asm_806CC8F0();
            break;
        case 1:
            handleInputsForControlState(0x4D);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkB8 != 0.0f) {
                playAnimation(current_actor_pointer, 0x3A);
                current_actor_pointer->control_state_progress = 2;
            }
            break;
        default:
            handleInputsForControlState(0x4D);
            func_global_asm_806CC8F0();
            if (current_actor_pointer->unkB8 == 0.0f) {
                playAnimation(current_actor_pointer, 0x33);
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
            handleInputsForControlState(0x4B);
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

// Jumptable, very close
// https://decomp.me/scratch/6V0uT
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D8B08.s")

extern s16 D_global_asm_80753A78[];
extern s16 D_global_asm_80753A88[];
extern f32 D_global_asm_80753AE0[];

/*
void func_global_asm_806D8B08(void) {
    f32 temp_f14;
    f32 temp_f0;

    extra_player_info_pointer->unk24++;
    extra_player_info_pointer->unk2C = D_global_asm_80753AFC[D_global_asm_807FD584];
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(0x4C);
            temp_f14 = D_global_asm_80753A5C[D_global_asm_807FD584];
            current_actor_pointer->y_velocity = func_global_asm_806CD898(current_actor_pointer->y_velocity, temp_f14, extra_player_info_pointer->unk1C);
            if (temp_f14 <= current_actor_pointer->y_velocity) {
                if ((current_actor_pointer->unkB8 != 0) || (extra_player_info_pointer->unk10 != 0)) {
                    current_actor_pointer->control_state_progress = 3;
                } else {
                    current_actor_pointer->control_state_progress = 2;
                }
                current_actor_pointer->animation_state->unk78 &= ~0x4000;
            }
            func_global_asm_806CC5DC();
            func_global_asm_80684D98(1);
            break;
        case 1:
            handleInputsForControlState(0x4F);
            func_global_asm_806CC638(0);
            if (extra_player_info_pointer->unk10 == 0) {
                current_actor_pointer->control_state_progress = 3;
            }
            temp_f14 = (extra_player_info_pointer->unk10 / 7.5) + 1;
            if (current_actor_pointer->animation_state->unk48 < temp_f14) {
                func_global_asm_80614D00(current_actor_pointer, temp_f14, 0);
            } else {
                func_global_asm_80614D00(current_actor_pointer, temp_f14, 15.0f);
            }
            func_global_asm_80684D98(2);
            if (current_actor_pointer->unkAC < (D_global_asm_807538C8[D_global_asm_807FD584] + current_actor_pointer->y_position)) {
                current_actor_pointer->y_position = current_actor_pointer->unkAC - D_global_asm_807538C8[D_global_asm_807FD584];
            }
            break;
        default:
            handleInputsForControlState(0x54);
            func_global_asm_806CC638(D_global_asm_80753A5C[D_global_asm_807FD584]);
            if (current_actor_pointer->unkB8 != 0) {
                extra_player_info_pointer->unk18 = 0;
                current_actor_pointer->control_state_progress = 3;
            } else {
                if (extra_player_info_pointer->unk50 != 0) {
                    extra_player_info_pointer->unk50--;
                    if (extra_player_info_pointer->unk50 == 0) {
                        playAnimation(current_actor_pointer, 0x34);
                    }
                }
            }
            func_global_asm_806D0EBC(current_actor_pointer);
            break;
        case 3:
            handleInputsForControlState(0x50);
            func_global_asm_806CC638(0);
            break;
        case 4:
            handleInputsForControlState(0x51);
            extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            extra_player_info_pointer->unk38 = D_global_asm_80753AE0[D_global_asm_807FD584];
            extra_player_info_pointer->unk10 = D_global_asm_80753A88[D_global_asm_807FD584];
            func_global_asm_806CC638(0);
            current_actor_pointer->control_state_progress++;
            break;
        case 5:
            handleInputsForControlState(0x51);
            func_global_asm_806CC638(0);
            break;
        case 6:
            handleInputsForControlState(0x52);
            func_global_asm_806CC638(0);
            break;
        case 7:
            handleInputsForControlState(0x51);
            func_global_asm_806CC638(0);
            break;
        case 8:
            handleInputsForControlState(0x53);
            func_global_asm_806CC638(0);
            break;
    }
    if ((current_actor_pointer->unkB8 == 0) || (extra_player_info_pointer->unk18 != 0)) {
        extra_player_info_pointer->unk50 = D_global_asm_80753A78[D_global_asm_807FD584];
        func_global_asm_80614D00(current_actor_pointer, 0.5f, extra_player_info_pointer->unk50);
        current_actor_pointer->control_state_progress = 2;
    }
    func_global_asm_806D0EBC(current_actor_pointer);
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D8FCC(void) {
    extra_player_info_pointer->unk24 = 0;
    current_actor_pointer->x_rotation = 0;
    current_actor_pointer->z_rotation = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_806D3FA0();
            handleInputsForControlState(0x21);
            func_global_asm_806CC8F0();
            break;
        case 1:
            func_global_asm_806CC8B8();
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            func_global_asm_806CC8B8();
            handleInputsForControlState(0x21);
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                handleInputsForControlState(0x22);
            } else {
                handleInputsForControlState(0x21);
            }
            func_global_asm_806CFD68();
            break;
        case 3:
            func_global_asm_806CC8B8();
            handleInputsForControlState(0x30);
            setYAccelerationFrom80753578();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9134(void) {
    handleInputsForControlState(1);
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
    handleInputsForControlState(1);
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}

// Jumptable, close, float
// https://decomp.me/scratch/WkVsv
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D9320.s")

extern f32 D_global_asm_80753CD0[];

/*
void func_global_asm_806D9320(void) {
    f32 temp_f0;
    f32 dz;
    f32 dy;
    f32 d;
    f32 temp_f2;
    f32 dx;
    f32 var_f0;
    f32 var_f12;
    s32 var_a1;

    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->object_properties_bitfield &= 0xFFBFFFFF;
            if ((current_actor_pointer->unkFC != 0) || (((current_actor_pointer->unk6A & 1)) && !(current_actor_pointer->unk6C & 1))) {
                func_global_asm_806224CC(extra_player_info_pointer->unk104, current_actor_pointer);
            }
            if (!(current_actor_pointer->unk6A & 1)) {
                func_global_asm_807149B8(1);
                func_global_asm_807149FC(1);
                func_global_asm_80714C08(&D_global_asm_8072014C, 0.8f, current_actor_pointer, 1, 0);
            }
            if (current_actor_pointer->unk6A & current_actor_pointer->unk6C & 1) {
                var_a1 = 2;
            } else {
                var_a1 = 1;
            }
            if ((!current_actor_pointer->unk6C) & current_actor_pointer->unk6A & 1) {
                current_actor_pointer->unkB8 *= 0.25;
            }
            if (current_actor_pointer->unkB8 < var_a1) {
                current_actor_pointer->unkB8 = 0.0f;
            } else {
                current_actor_pointer->unkB8 -= var_a1;
            }
            current_actor_pointer->z_rotation = (func_global_asm_80611BB4(current_actor_pointer->unkB8, current_actor_pointer->y_velocity) * 4096.0f) / 6.2831855f;
            current_actor_pointer->unkEE = current_actor_pointer->y_rotation = (func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, extra_player_info_pointer->unkB0_f32, extra_player_info_pointer->unkB8) + 0x800) % 4095;
            dz = extra_player_info_pointer->unkB8 - player_pointer->z_position;
            dy = (extra_player_info_pointer->unkB4 - player_pointer->y_position) / (player_pointer->animation_state->scale[1] * 0.16666666675);
            dx = extra_player_info_pointer->unkB0_f32 - player_pointer->x_position;
            var_f12 = player_pointer->unkB8;
            d = sqrtf((dz * dz) + (dx * dx)) / (player_pointer->animation_state->scale[1] * 0.16666666675);
            if (var_f12 == 0.0) {
                var_f12 = 1.0f;
            }
            var_f0 = (d / var_f12) - 1.0f;
            if (var_f0 < 1.0f) {
                var_f0 = 1.0f;
            }
            player_pointer->y_velocity = ((0.0 - D_global_asm_80753CD0[D_global_asm_807FD584] * 0.5 * (var_f0 * var_f0)) - dy) / var_f0;
            player_pointer->y_acceleration = -0.001f;
            if ((var_f0 < 2.0f) || (var_f12 < 2.0)) {
                setYAccelerationFrom80753578();
                current_actor_pointer->control_state_progress++;
            }
            if (current_actor_pointer->unkFC != 0) {
                current_actor_pointer->unkB8 = 0.0f;
                setYAccelerationFrom80753578();
                current_actor_pointer->control_state_progress++;
            }
            handleInputsForControlState(1);
            break;
        case 1:
            handleInputsForControlState(0x20);
            playAnimation(current_actor_pointer, 0x23);
            current_actor_pointer->z_rotation = 0;
            setYAccelerationFrom80753578();
            current_actor_pointer->control_state_progress++;
            break;
        case 2:
            handleInputsForControlState(0x20);
            break;
        case 3:
            func_global_asm_80617770(current_actor_pointer, 0x10, 0);
            extra_player_info_pointer->unk30 = D_global_asm_80753250[D_global_asm_807FD584];
            current_actor_pointer->control_state_progress++;
            // fallthrough
        case 4:
            func_global_asm_806CD8EC();
            handleInputsForControlState(0x30);
            break;
    }
    func_global_asm_806CC948();
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806D97A4(void) {
    handleInputsForControlState(5);
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

    handleInputsForControlState(0x4A);
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

    handleInputsForControlState(1);
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
                case ACTOR_DK:
                    song = 0xB;
                    break;
                case ACTOR_TINY:
                    song = 0xD;
                    break;
                case ACTOR_LANKY:
                    song = 0xC;
                    if (!(D_global_asm_807FBB68 & 2)) {
                        phi_f0 = 0.82f;
                    }
                    break;
                case ACTOR_CHUNKY:
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
// https://decomp.me/scratch/YQGZn
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806D9AD4.s")

extern SpriteData D_global_asm_8071FC8C;

int func_global_asm_80717100();

void func_global_asm_805FF9AC(Maps arg0, s32 arg1, s32 arg2, s16 arg3);

/*
void func_global_asm_806D9AD4(void) {
    s32 pad;
    f32 sp28;

    handleInputsForControlState(1);
    if ((current_actor_pointer->control_state_progress == 1) || (current_actor_pointer->control_state_progress == 2)) {
        rand();
        sp28 = current_actor_pointer->y_position + ((rand() >> 0xF) % 30);
        rand();
        func_global_asm_807149B8(1);
        func_global_asm_80714950((extra_player_info_pointer->unk23C << 0x10) + (s32)(15.0 * (current_actor_pointer->shadow_opacity / 255.0)));
        func_global_asm_8071498C(func_global_asm_80717100);
        drawSpriteAtPosition(&D_global_asm_8071FC8C, 0.5f, current_actor_pointer->x_position, sp28, current_actor_pointer->z_position);
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
                playSoundAtActorPosition(current_actor_pointer, 0x264, 0xFF, 0x64, 0x19);
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
            handleInputsForControlState(0x43);
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
                current_actor_pointer->y_acceleration = -0.01f;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806D9FD0(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->y_velocity = 0.0f;
            current_actor_pointer->unkB8 = 0.0f;
            extra_player_info_pointer->unk30 = 2.0f;
            extra_player_info_pointer->unk2C = 5.0f;
            break;
        case 1:
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            handleInputsForControlState(0x43);
            current_actor_pointer->y_acceleration -= 0.036;
            func_global_asm_806CC8B8();
            func_global_asm_80602DC4(0x6B, 0.995f);
            if ((current_actor_pointer->y_velocity <= 0.0f) && (current_actor_pointer->y_acceleration < 0.0f)) {
                current_actor_pointer->y_velocity = 0.0f;
                current_actor_pointer->y_acceleration = -0.01f;
                current_actor_pointer->unk168 = 0;
                current_actor_pointer->control_state_progress++;
            }
            if (D_global_asm_807FD610[cc_player_index].unk2C & 0x2000) {
                current_actor_pointer->control_state_progress = 3;
                current_actor_pointer->y_acceleration = -1.0f;
            }
            break;
        case 2:
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            handleInputsForControlState(0x43);
            func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x32);
            current_actor_pointer->unk168++;
            current_actor_pointer->y_position += (func_global_asm_80612794(current_actor_pointer->unk168 << 5) * 0.25);
            func_global_asm_806CC8F0();
            func_global_asm_80602DC4(0x6B, 0.995f);
            extra_player_info_pointer->unkC0 -= 1;
            if ((extra_player_info_pointer->unkC0 < 0) || (D_global_asm_807FD610[cc_player_index].unk2C & 0x2000)) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 3:
            playActorAnimation(current_actor_pointer, 0x16A);
            handleInputsForControlState(0x43);
            func_global_asm_806CC8B8();
            current_actor_pointer->control_state_progress++;
            break;
        case 4:
            current_actor_pointer->y_acceleration -= 1.0f;
            handleInputsForControlState(0x43);
            func_global_asm_806CC8B8();
            break;
        case 5:
            func_global_asm_80602B60(0x6B, 0);
            handleInputsForControlState(0x43);
            func_global_asm_806CC8B8();
            break;
        case 6:
            func_global_asm_80602B60(0x6B, 0);
            handleInputsForControlState(0x43);
            func_global_asm_806CC8B8();
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA320(void) {
    f32 phi_f2;

    if (D_global_asm_807FBC58 != 0.0) {
        phi_f2 = D_global_asm_807FBC58;
    } else {
        phi_f2 = current_actor_pointer->unkB8;
    }
    func_global_asm_80614D00(current_actor_pointer, (phi_f2 / 25.0f) + 0.25, 2.0f);
    handleInputsForControlState(0x49);
    if ((current_actor_pointer->unk6A & 0x10) == 0) {
        func_global_asm_806CFF9C(current_actor_pointer);
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA3E4(void) {
    func_global_asm_806CA2AC();
    handleInputsForControlState(5);
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
            current_actor_pointer->control_state_progress++;
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
            current_actor_pointer->control_state_progress++;
            break;
        case 3:
            handleInputsForControlState(5);
            func_global_asm_806CEE64(0.4f);
            func_global_asm_806CEED8();
            break;
        case 4:
            handleInputsForControlState(5);
            func_global_asm_8067A784(current_actor_pointer, extra_player_info_pointer->unk1AC, current_player->y_rotation, ((D_global_asm_807533B8[D_global_asm_807FD584] * 3.0) * current_actor_pointer->animation_state->scale[0]) / 0.15, 0);
            current_actor_pointer->control_state_progress++;
            break;
        case 5:
            handleInputsForControlState(5);
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
    handleInputsForControlState(6);
    if (D_global_asm_807FD610[cc_player_index].unk8 != 0.0f) {
        func_global_asm_80614D00(current_actor_pointer, 3.0f, 0);
    }
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, extra_player_info_pointer->unkA, extra_player_info_pointer->unk48);
    extra_player_info_pointer->unk4 = 0.0f;
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DA89C(void) {
    handleInputsForControlState(7);
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
    handleInputsForControlState(0x37);
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
    handleInputsForControlState(0x37);
    if ((current_actor_pointer->unk6A & 1) == 0) {
        func_global_asm_806D3608();
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DAADC(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    handleInputsForControlState(0x3A);
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
            current_actor_pointer->control_state_progress++;
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DABE4(void) {
    extra_player_info_pointer->unk1F0 &= ~0x1000000;
    handleInputsForControlState(1);
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
    handleInputsForControlState(1);
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
            handleInputsForControlState(0x21);
            break;
        case 1:
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk54;
            func_global_asm_806CFECC();
            func_global_asm_806D3FA0();
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x21);
            func_global_asm_806CFD68();
            break;
        case 2:
            func_global_asm_806D3608();
            handleInputsForControlState(0x39);
            func_global_asm_806CFD68();
            break;
        case 3:
            handleInputsForControlState(0x38);
            setYAccelerationFrom80753578();
            break;
    }
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DB08C(void) {
    handleInputsForControlState(0x12);
    func_global_asm_806CC8B8();
    renderActor(current_actor_pointer, 0);
}

// close
// https://decomp.me/scratch/ZffnL
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DB0C4.s")

/*
void func_global_asm_806DB0C4(void) {
    Actor *temp_v1;
    f32 dz, dx;

    if (D_global_asm_807FBB70.unkE4 != 0) {
        extra_player_info_pointer->unkDC = D_global_asm_807FBB70.unkEC;
        extra_player_info_pointer->unk9C = current_actor_pointer->x_position;
        extra_player_info_pointer->unkA0 = current_actor_pointer->z_position;
        extra_player_info_pointer->unkA4 = D_global_asm_807FBB70.unkD8;
        extra_player_info_pointer->unkA8 = D_global_asm_807FBB70.unkE0;
        extra_player_info_pointer->unkAC_f32 = 0.0f;
        dx = extra_player_info_pointer->unkA4 - extra_player_info_pointer->unk9C;
        dz = extra_player_info_pointer->unkA8 - extra_player_info_pointer->unkA0;
        extra_player_info_pointer->unk94 = sqrtf((dx * dx) + (dz * dz)) * 0.8;
        extra_player_info_pointer->unk98 = ((func_global_asm_80611BB4(dx, dz) * 4096.0f) / 6.283185482f);
        extra_player_info_pointer->unk4C = -1;
    }
    extra_player_info_pointer->unkAC_f32 += 0.02;
    if (extra_player_info_pointer->unkAC_f32 > 1.0) {
        if (extra_player_info_pointer->unkDC != NULL) {
            extra_player_info_pointer->unk98 = (func_global_asm_80611BB4(extra_player_info_pointer->unkDC->x_position - extra_player_info_pointer->unk9C, extra_player_info_pointer->unkDC->z_position - extra_player_info_pointer->unkA0) * 4096.0f) / 6.283185482f;
            if (current_actor_pointer->y_rotation == (s16)extra_player_info_pointer->unk98) {
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

void func_global_asm_806DB3AC(void) {
    current_actor_pointer->unkB8 = 0.0f;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->noclip_byte = 1;
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity = 0xFF;
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xE6, 0xFF, 0x7F, 0, 0, 0.3f, 0);
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            current_actor_pointer->shadow_opacity -= 0xF;
            if (current_actor_pointer->shadow_opacity < 0x10) {
                func_global_asm_8065EACC();
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            func_global_asm_80672C30(current_actor_pointer);
            current_actor_pointer->x_position = extra_player_info_pointer->unk204;
            current_actor_pointer->y_position = extra_player_info_pointer->unk208 + 10.0;
            current_actor_pointer->unk8C = current_actor_pointer->y_position;
            current_actor_pointer->z_position = extra_player_info_pointer->unk20C;
            func_global_asm_806C8220(0, current_actor_pointer->unk178, current_actor_pointer->unk58);
            func_global_asm_8061EB04(current_actor_pointer, extra_player_info_pointer->unk1A4);
            func_global_asm_806291B4(6);
            extra_player_info_pointer->unk23C = 0x14;
            playSoundAtPosition(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0xE6, 0xFF, 0x7F, 0, 0, 0.3f, 0);
            current_actor_pointer->control_state_progress++;
            break;
        case 3:
            extra_player_info_pointer->unk23C -= 1;
            if (extra_player_info_pointer->unk23C == 0) {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 4:
            current_actor_pointer->shadow_opacity += 0xF;
            if (current_actor_pointer->shadow_opacity >= 0xF1) {
                current_actor_pointer->object_properties_bitfield |= 0x8000;
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 5:
            func_global_asm_806C8D20(current_actor_pointer);
            func_global_asm_8065EAF4();
            func_global_asm_806CFF9C(current_actor_pointer);
            handleInputsForControlState(0x30);
            break;
    }
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DB670(void) {
    current_actor_pointer->unkB8 = 0;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->noclip_byte = 1;
            if (spawnActor(ACTOR_BANAPORTER, 0x98)) {
                moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, 0.15f);
            }
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            current_actor_pointer->control_state_progress++;
            extra_player_info_pointer->unk23C = 4;
            break;
        case 2:
            current_actor_pointer->x_position = ((extra_player_info_pointer->unk210 - current_actor_pointer->x_position) * 0.5) + current_actor_pointer->x_position;
            current_actor_pointer->y_position = ((extra_player_info_pointer->unk214 - current_actor_pointer->y_position) * 0.5) + current_actor_pointer->y_position;
            current_actor_pointer->z_position = ((extra_player_info_pointer->unk218 - current_actor_pointer->z_position) * 0.5) + current_actor_pointer->z_position;
            if (extra_player_info_pointer->unk23C != 0) {
                extra_player_info_pointer->unk23C--;
                if (extra_player_info_pointer->unk23C == 0) {
                    current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
                    current_actor_pointer->shadow_opacity = 0;
                }
            }
            break;
        case 3:
            current_actor_pointer->object_properties_bitfield &= 0xFFFF7FFF;
            current_actor_pointer->shadow_opacity = 0;
            current_actor_pointer->control_state_progress++;
            break;
        case 5:
            extra_player_info_pointer->unk23C = 0x14;
            break;
        case 6:
            extra_player_info_pointer->unk23C -= 1;
            if (extra_player_info_pointer->unk23C == 0) {
                func_global_asm_8065EACC();
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 7:
            global_properties_bitfield &= 0xFFFCFFDF;
            func_global_asm_80672C30(current_actor_pointer);
            current_actor_pointer->x_position = extra_player_info_pointer->unk204;
            current_actor_pointer->y_position = extra_player_info_pointer->unk208;
            current_actor_pointer->unk8C = current_actor_pointer->y_position;
            current_actor_pointer->z_position = extra_player_info_pointer->unk20C;
            func_global_asm_806C8220(0, current_actor_pointer->unk178, current_actor_pointer->unk58, current_actor_pointer);
            func_global_asm_8061EB04(current_actor_pointer, extra_player_info_pointer->unk1A4);
            extra_player_info_pointer->unk23C = 0x14;
            func_global_asm_806291B4(2);
            current_actor_pointer->control_state_progress++;
            break;
        case 8:
            global_properties_bitfield |= 0x30020;
            extra_player_info_pointer->unk23C -= 1;
            if (extra_player_info_pointer->unk23C == 0) {
                func_global_asm_80602498();
                if (spawnActor(ACTOR_BANAPORTER, 0x98)) {
                    moveAndScaleActorToAnother(last_spawned_actor, current_actor_pointer, 0.15f);
                }
                current_actor_pointer->control_state_progress++;
                extra_player_info_pointer->unk23C = 0xC;
            }
            break;
        case 10:
            if (extra_player_info_pointer->unk23C != 0) {
                extra_player_info_pointer->unk23C--;
                if (extra_player_info_pointer->unk23C == 0) {
                    current_actor_pointer->x_position = extra_player_info_pointer->unk210;
                    current_actor_pointer->y_position = extra_player_info_pointer->unk214;
                    current_actor_pointer->z_position = extra_player_info_pointer->unk218;
                    current_actor_pointer->object_properties_bitfield |= 0x8000;
                }
            }
            break;
        case 11:
            handleInputsForControlState(0x20);
            playAnimation(current_actor_pointer, 0x1B);
            setYAccelerationFrom80753578();
            current_actor_pointer->control_state_progress++;
            break;
        case 12:
        case 13:
            handleInputsForControlState(0x20);
            applyActorYAcceleration();
            break;
        case 14:
            func_global_asm_80617770(current_actor_pointer, 0x2F, 0);
            current_actor_pointer->control_state_progress++;
            // fallthrough
        case 15:
            func_global_asm_806C8D20(current_actor_pointer);
            func_global_asm_8065EAF4();
            handleInputsForControlState(0x30);
            break;
    }
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DBB04(void) {
    f32 x2, y2, z2;
    u8 sp63;
    f32 x, y, z;

    handleInputsForControlState(1);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            extra_player_info_pointer->unk108 = 50.0f;
            current_actor_pointer->control_state_progress++;
            break;
        case 1:
            if (extra_player_info_pointer->unk108 != 0.0f) {
                extra_player_info_pointer->unk108 -= 1.0f;
            } else {
                if ((current_actor_pointer->y_position - current_actor_pointer->floor) < 60.0f) {
                    current_actor_pointer->y_position += 1.0f;
                } else {
                    extra_player_info_pointer->unk108 = 150.0f;
                    current_actor_pointer->control_state_progress++;
                    func_global_asm_8061C6A8(extra_player_info_pointer->unk104, current_actor_pointer, 6, 0, 0x1E, 0, 5, 0x2D, 0x14, 0xC8, 0.15f);
                }
            }
            break;
        case 2:
            extra_player_info_pointer->unk108 -= 1.0f;
            if (extra_player_info_pointer->unk108 == 0.0f) {
                extra_player_info_pointer->unk108 = 150.0f;
                current_actor_pointer->control_state_progress++;
            }
            current_actor_pointer->y_rotation += (120.0 * (0.5 + ABS(func_global_asm_80612794(extra_player_info_pointer->unkCC))));
            break;
        case 3:
            extra_player_info_pointer->unk108 -= 1.0f;
            if (extra_player_info_pointer->unk108 == 0.0f) {
                extra_player_info_pointer->unk108 = 500.0f;
                current_actor_pointer->control_state_progress++;
            }
            current_actor_pointer->y_rotation += (120.0 * (0.5 + ABS(func_global_asm_80612794(extra_player_info_pointer->unkCC))));
            current_actor_pointer->x_rotation += (60.0f * func_global_asm_80612794(extra_player_info_pointer->unkCC + 0x400));
            break;
        case 4:
            setAction(0x1B, NULL, 0);
            extra_player_info_pointer->unk1F0 |= 4;
            current_actor_pointer->x_rotation = 0;
            current_actor_pointer->y_rotation = 0;
            break;
    }
    extra_player_info_pointer->unkCC = extra_player_info_pointer->unkCC + 6;
    extra_player_info_pointer->unkCC = extra_player_info_pointer->unkCC & 0xFFF;
    if (!(object_timer & 1)) {
        sp63 = ((rand() >> 0xF) % 65535) % 3;
        getBonePosition(current_actor_pointer, 5, &x, &y, &z);
        x += (((rand() >> 0xF) % 65535) % 16) - 8;
        y += (((rand() >> 0xF) % 65535) % 16) - 8;
        z += (((rand() >> 0xF) % 65535) % 16) - 8;
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_8071498C(func_global_asm_8071720C);
        func_global_asm_80714950(((rand() >> 0xF) % 100) + 0x64);
        if (sp63 == 2) {
            drawSpriteAtPosition(&D_global_asm_8071FCC0, 0.5f, x, y, z);
        } else if (sp63 == 1) {
            drawSpriteAtPosition(&D_global_asm_8071FC8C, 0.5f, x, y, z);
        } else {
            drawSpriteAtPosition(&D_global_asm_8071FC58, 0.5f, x, y, z);
        }
    }
    current_actor_pointer->y_velocity = 0.0f;
    current_actor_pointer->unkB8 = 0.0f;
    func_global_asm_806CC970();
    getBonePosition(current_actor_pointer, 0xC, &x2, &y2, &z2);
    createLight(x2, y2, z2, 0.0f, 0.0f, 0.0f, 80.0f, 0, 0xFF, 0xFF, 0);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DC170(void) {
    f32 var_f4;
    s32 i;

    handleInputsForControlState(1);
    current_actor_pointer->unkB8 = 0.0f;
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            current_actor_pointer->noclip_byte = 1;
            extra_player_info_pointer->unk23C = 0xA;
            current_actor_pointer->control_state_progress++;
            playSoundAtActorPosition(current_actor_pointer, 0x2EB, 0xFF, 0x7F, 2);
            break;
        case 1:
            if (extra_player_info_pointer->unk23C >= 2) {
                extra_player_info_pointer->unk23C--;
            } else {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 2:
            func_global_asm_80672C30(current_actor_pointer);
            current_actor_pointer->x_position = extra_player_info_pointer->unk204;
            current_actor_pointer->y_position = extra_player_info_pointer->unk208;
            current_actor_pointer->unk8C = current_actor_pointer->y_position;
            current_actor_pointer->z_position = extra_player_info_pointer->unk20C;
            current_actor_pointer->y_rotation = \
            current_actor_pointer->unkEE = extra_player_info_pointer->unk21C;
            func_global_asm_8061EB04(current_actor_pointer, extra_player_info_pointer->unk1A4);
            func_global_asm_806C8220(0, current_actor_pointer->unk178, current_actor_pointer->unk58);
            current_actor_pointer->control_state_progress++;
            break;
        case 3:
            if (extra_player_info_pointer->unk23C < 0xA) {
                extra_player_info_pointer->unk23C++;
            } else {
                current_actor_pointer->control_state_progress++;
            }
            break;
        case 4:
            extra_player_info_pointer->unk268 = 0x3C;
            func_global_asm_806CFF9C(current_actor_pointer);
            break;
    }
    var_f4 = (f32)extra_player_info_pointer->unk23C * 0.015;
    for (i = 0; i != 3; i++) {
        current_actor_pointer->animation_state->scale[i] = var_f4;
    }
    func_global_asm_806CC970();
    renderActor(current_actor_pointer, 0);
}

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

typedef struct {
    void *unk0; // Used
    s8 unk4; // Used
    Actor *unk8; // Used
    s32 unkC;
    s32 unk10;
} Struct806DC410;

void func_global_asm_806DC410(void) {
    s32 pad[2];
    f32 sp1C;
    f32 var_f2;
    Struct806DC410 *temp_v0;

    if ((current_actor_pointer->control_state_progress != 0) && !(current_actor_pointer->unk6A & 0x40)) {
        func_global_asm_806CFF1C(current_actor_pointer);
        if (extra_player_info_pointer->unk8C != 0) {
            func_global_asm_806D374C();
        } else {
            func_global_asm_806D36CC();
        }
        return;
    }
    extra_player_info_pointer->unk100 = D_global_asm_80753C84[D_global_asm_807FD584];
    temp_v0 = malloc(sizeof(Struct806DC410));
    temp_v0->unk0 = func_global_asm_807300BC;
    temp_v0->unk8 = current_player;
    temp_v0->unk4 = 1;
    func_global_asm_80679064(temp_v0);
    func_global_asm_806DF494(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0xC8);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(5);
            extra_player_info_pointer->unk94 = 0.0f;
            extra_player_info_pointer->unk158 = NULL;
            current_actor_pointer->unkEE = extra_player_info_pointer->unk130->y_rotation;
            if (func_global_asm_806CC14C(current_actor_pointer->y_rotation, extra_player_info_pointer->unk130->y_rotation) >= 0x400) {
                current_actor_pointer->unkEE = (current_actor_pointer->unkEE + 0x800) & 0xFFF;
            }
            break;
        case 1:
            if (handleInputsForControlState(0x58) == 0) {
                switch (extra_player_info_pointer->unk8) {
                    case 1:
                        sp1C = D_global_asm_80753C30[D_global_asm_807FD584];
                        current_actor_pointer->control_state_progress = 3;
                        playAnimation(current_player, 0x6A);
                        break;
                    case 0:
                        sp1C = D_global_asm_80753C68[D_global_asm_807FD584];
                        break;
                    case -1:
                        sp1C = D_global_asm_80753C4C[D_global_asm_807FD584];
                        current_actor_pointer->control_state_progress = 4;
                        playAnimation(current_player, 0x6B);
                        break;
                }
                func_global_asm_806DC3A4(sp1C);
                func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            }
            break;
        case 2:
            if (handleInputsForControlState(0x58) == 0) {
                if ((extra_player_info_pointer->unk94 == 0.0f) && (extra_player_info_pointer->unk4 == 0.0f)) {
                    current_actor_pointer->control_state_progress = 1;
                    playAnimation(current_player, 0x6C);
                } else if ((extra_player_info_pointer->unk94 > 0.0f) && (extra_player_info_pointer->unk4 > 0.0f)) {
                    current_actor_pointer->control_state_progress = 3;
                    playAnimation(current_player, 0x6A);
                } else if ((extra_player_info_pointer->unk94 < 0.0f) && (extra_player_info_pointer->unk4 < 0.0f)) {
                    current_actor_pointer->control_state_progress = 4;
                    playAnimation(current_player, 0x6B);
                }
                func_global_asm_806DC3A4(D_global_asm_80753C68[D_global_asm_807FD584]);
                var_f2 = ABS(extra_player_info_pointer->unk94 * 0.025);
                func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
            }
            break;
        case 3:
            if (handleInputsForControlState(0x58) == 0) {
                if (extra_player_info_pointer->unk94 <= 0.0f) {
                    current_actor_pointer->control_state_progress = 2;
                }
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        sp1C = D_global_asm_80753C4C[D_global_asm_807FD584] * 2;
                        break;
                    case 0:
                        sp1C = D_global_asm_80753C68[D_global_asm_807FD584];
                        break;
                    case 1:
                        sp1C = D_global_asm_80753C30[D_global_asm_807FD584];
                        break;
                }
                func_global_asm_806DC3A4(sp1C);
                var_f2 = ABS(extra_player_info_pointer->unk94 * 0.025);
                func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
            }
            break;
        case 4:
            if (handleInputsForControlState(0x58) == 0) {
                if (extra_player_info_pointer->unk94 >= 0.0f) {
                    current_actor_pointer->control_state_progress = 2;
                }
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        sp1C = D_global_asm_80753C4C[D_global_asm_807FD584];
                        break;
                    case 0:
                        sp1C = D_global_asm_80753C68[D_global_asm_807FD584];
                        break;
                    case 1:
                        sp1C = D_global_asm_80753C30[D_global_asm_807FD584];
                        break;
                }
                func_global_asm_806DC3A4(sp1C);
                var_f2 = ABS(extra_player_info_pointer->unk94 * 0.025);
                func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
            }
            break;
    }
    func_global_asm_806CC970();
}

// doable, switch case woes, float
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DCA7C.s")

/*
void func_global_asm_806DCA7C(Actor **arg0, s32 arg1) {
    f32 d;
    f32 dy;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dz;
    s32 var_v0;
    s32 var_v1;

    current_actor_pointer->object_properties_bitfield &= ~0x400000;
    current_actor_pointer->unk6A &= ~0x40;
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
                playAnimation(current_actor_pointer, 0x6D);
            } else {
                playAnimation(current_actor_pointer, 0x6E);
            }
            func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x78, 0x600);
            current_actor_pointer->y_velocity = extra_player_info_pointer->unk150;
            current_actor_pointer->control_state_progress++;
            handleInputsForControlState(0x27);
            extra_player_info_pointer->unk30 /= 2;
            func_global_asm_806CC948();
            break;
        case 2:
            if (extra_player_info_pointer->unk158 == 0) {
                playAnimation(current_player, 0x6F);
                current_actor_pointer->control_state_progress = 3;
            } else {
            case 1:
                func_global_asm_806DCF60();
                if (current_actor_pointer->unk58 == ACTOR_TINY) {
                    handleInputsForControlState(0x28);
                } else {
                    handleInputsForControlState(0x27);
                }
                current_actor_pointer->unkB8 = extra_player_info_pointer->unk14C;
                current_actor_pointer->unkEE = extra_player_info_pointer->unk154;
                func_global_asm_806DF5A0(&current_actor_pointer->y_rotation, current_actor_pointer->unkEE, 0x78, 0x600);
                extra_player_info_pointer->unkA = current_actor_pointer->unkEE;
                extra_player_info_pointer->unk4 = 150.0f;
                extra_player_info_pointer->unk38 = 150.0f;
                if (extra_player_info_pointer->unk158 != 0) {
                    getBonePosition(extra_player_info_pointer->unk158, 1, &x, &y, &z);
                    dx = x - current_player->x_position;
                    dz = z - current_player->z_position;
                    dy = (y - current_player->y_position) / (current_player->animation_state->scale_y * 0.166666666749999998);
                    d = ((sqrtf((dx * dx) + (dz * dz)) / (current_player->animation_state->scale_y * 0.166666666749999998)) / current_player->unkB8) - 1.0f;
                    if (d < 1.0f) {
                        d = 1.0f;
                    }
                }
                if ((extra_player_info_pointer->unk158 != 0) && (d < 30.0f)) {
                    current_player->y_velocity = (((0.0 - (D_global_asm_80753CD0[D_global_asm_807FD584]) * 0.5 * (d * d)) - dy)) / d;
                    current_player->y_acceleration = -0.001f;
                } else {
                    extra_player_info_pointer->unk158 = 0;
                    setYAccelerationFrom80753578();
                }
                func_global_asm_806CC948();
                break;
            }
            break;
        case 3:
            handleInputsForControlState(0x30);
            setYAccelerationFrom80753578();
            func_global_asm_806CC8B8();
            extra_player_info_pointer->unk30 = 10.0f;
            break;
    }
    renderActor(current_actor_pointer, 0);
}
*/

// TODO: Kinda close, good progress made
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_D78D0/func_global_asm_806DCF60.s")

/*
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

typedef struct {
    void *unk0; // Used
    s8 unk4; // Used
    Actor *unk8; // Used
    s32 unkC;
    s32 unk10;
} Struct806DD24C;

void func_global_asm_806DD24C(void) {
    s32 pad[2];
    f32 sp1C;
    f32 temp_f0;
    f32 var_f2;
    u16 temp_v0;
    Struct806DD24C *temp_v0_2;

    if ((current_actor_pointer->control_state_progress != 0) && (((!(current_actor_pointer->unk6A & 0x40))) || ((current_actor_pointer->unk6A & 4) && ((current_actor_pointer->unkAC - current_actor_pointer->y_position) > 3.0)))) {
        func_global_asm_806CFF1C(current_actor_pointer);
        if (extra_player_info_pointer->unk8C != 0) {
            func_global_asm_806D374C();
        } else {
            func_global_asm_806D36CC();
        }
        return;
    }
    extra_player_info_pointer->unk100 = D_global_asm_80753CA4[D_global_asm_807FD584];
    temp_v0_2 = malloc(0x14);
    temp_v0_2->unk0 = func_global_asm_807300BC;
    temp_v0_2->unk8 = current_player;
    temp_v0_2->unk4 = 1;
    func_global_asm_80679064(temp_v0_2);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            handleInputsForControlState(5);
            extra_player_info_pointer->unk94 = 0.0f;
            break;
        case 1:
            if (handleInputsForControlState(0x59) == 0) {
                switch (extra_player_info_pointer->unk8) {
                    case 1:
                        sp1C = D_global_asm_80753C30[D_global_asm_807FD584];
                        current_actor_pointer->control_state_progress = 3;
                        playAnimation(current_player, 0x71);
                        break;
                    case 0:
                        sp1C = D_global_asm_80753C68[D_global_asm_807FD584];
                        break;
                    case -1:
                        sp1C = D_global_asm_80753C4C[D_global_asm_807FD584];
                        current_actor_pointer->control_state_progress = 4;
                        playAnimation(current_player, 0x72);
                        break;
                }
                func_global_asm_806DC3A4(sp1C);
                func_global_asm_80614D00(current_actor_pointer, 1.0f, 0.0f);
            }
            break;
        case 2:
            if (handleInputsForControlState(0x59) == 0) {
                if ((extra_player_info_pointer->unk94 == 0.0f) && (extra_player_info_pointer->unk4 == 0.0f)) {
                    current_actor_pointer->control_state_progress = 1;
                    playAnimation(current_player, 0x73);
                } else if ((extra_player_info_pointer->unk94 > 0.0f) && (extra_player_info_pointer->unk4 > 0.0f)) {
                    current_actor_pointer->control_state_progress = 3;
                    playAnimation(current_player, 0x71);
                } else if ((extra_player_info_pointer->unk94 < 0.0f) && (extra_player_info_pointer->unk4 < 0.0f)) {
                    current_actor_pointer->control_state_progress = 4;
                    playAnimation(current_player, 0x72);
                }
                func_global_asm_806DC3A4(D_global_asm_80753C68[D_global_asm_807FD584]);
                var_f2 = ABS(extra_player_info_pointer->unk94 * 0.025);
                func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
            }
            break;
        case 3:
            if (handleInputsForControlState(0x59) == 0) {
                if (extra_player_info_pointer->unk94 <= 0.0f) {
                    current_actor_pointer->control_state_progress = 2;
                }
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        sp1C = D_global_asm_80753C4C[D_global_asm_807FD584] * 2;
                        break;
                    case 0:
                        sp1C = D_global_asm_80753C68[D_global_asm_807FD584];
                        break;
                    case 1:
                        sp1C = D_global_asm_80753C30[D_global_asm_807FD584];
                        break;
                }
                func_global_asm_806DC3A4(sp1C);
                var_f2 = ABS(extra_player_info_pointer->unk94 * 0.025);
                func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
            }
            break;
        case 4:
            if (handleInputsForControlState(0x59) == 0) {
                if (extra_player_info_pointer->unk94 >= 0.0f) {
                    current_actor_pointer->control_state_progress = 2;
                }
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        sp1C = D_global_asm_80753C4C[D_global_asm_807FD584];
                        break;
                    case 0:
                        sp1C = D_global_asm_80753C68[D_global_asm_807FD584];
                        break;
                    case 1:
                        sp1C = D_global_asm_80753C30[D_global_asm_807FD584];
                        break;
                }
                func_global_asm_806DC3A4(sp1C);
                var_f2 = ABS(extra_player_info_pointer->unk94 * 0.025);
                func_global_asm_80614D00(current_actor_pointer, var_f2, 0.0f);
            }
            break;
    }
    func_global_asm_806CC970();
}

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
            handleInputsForControlState(0x29);
            extra_player_info_pointer->unk2C = 30.0f;
            extra_player_info_pointer->unk48 = 0x64;
            func_global_asm_806CFD68();
            extra_player_info_pointer->unk30 /= 2;
            func_global_asm_806CC948();
            break;
        case 2:
            if (current_actor_pointer->unk58 == ACTOR_TINY) {
                handleInputsForControlState(0x2A);
            } else {
                handleInputsForControlState(0x29);
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
            handleInputsForControlState(0x30);
            setYAccelerationFrom80753578();
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
            handleInputsForControlState(0x5A);
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
            if (handleInputsForControlState(0x5A) == 0) {
                switch (extra_player_info_pointer->unk8) {
                    case -1:
                        if (current_actor_pointer->control_state_progress == 1) {
                            var_f2 = MAX(current_actor_pointer->unkB8 * 0.025, 0.1);
                            func_global_asm_80614D00(current_actor_pointer, var_f2, 1.0f);
                            // func_global_asm_80614D00(current_actor_pointer, 0.1, var_f2, 1.0f);
                        } else {
                            playAnimation(current_player, 0x77);
                            current_actor_pointer->control_state_progress = 1;
                        }
                        break;
                    case 0:
                        if (current_actor_pointer->control_state_progress != 2) {
                            playAnimation(current_player, 0x76);
                            current_actor_pointer->control_state_progress = 2;
                        }
                        break;
                    case 1:
                        if (current_actor_pointer->control_state_progress == 3) {
                            var_f2 = MAX(current_actor_pointer->unkB8 * 0.025, 0.1);
                            // func_global_asm_80614D00(0.1, current_actor_pointer, var_f2_2, 0, current_actor_pointer);
                            func_global_asm_80614D00(current_actor_pointer, var_f2, 0);
                        } else {
                            playAnimation(current_player, 0x78);
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
        playAnimation(current_player, 0x79);
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

/*
void func_global_asm_806DE264(void) {
    f32 z;
    f32 y;
    f32 x;
    f32 var_f2;
    f32 sp3C;

    current_actor_pointer->y_velocity = 0.0f;
    current_actor_pointer->unkB8 = 0.0f;
    handleInputsForControlState(1);
    if (func_global_asm_806CFC90(current_actor_pointer, &sp3C, 1, 15.0f)) {
        extra_player_info_pointer->unkF0_f32 = sp3C;
    }
    if (ABS_DIFF(extra_player_info_pointer->unkF4_f32, extra_player_info_pointer->unkF0_f32) > 20.0) {
        func_global_asm_806CFF1C(current_actor_pointer);
        renderActor(current_actor_pointer, 0);
        return;
    }
    extra_player_info_pointer->unkF4_f32 = extra_player_info_pointer->unkF0_f32;
    current_actor_pointer->object_properties_bitfield |= 0x08000000;
    renderActor(current_actor_pointer, 0);
    func_global_asm_80678DD8(current_actor_pointer);
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            switch (current_actor_pointer->unk58) {
                case ACTOR_LANKY:
                    if (current_actor_pointer->animation_state->unk0->unk4 < 25.0f) {
                        getBonePosition(current_actor_pointer, 7, &x, &y, &z);
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32 - (y - current_actor_pointer->y_position);
                    }
                    if (current_actor_pointer->animation_state->unk0->unk4 < 25.0f) {
                        current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
                        current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
                    } else if (current_actor_pointer->animation_state->unk0->unk4 < 31.0f) {
                        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                        current_actor_pointer->unkB8 = 70.0f;
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                    } else {
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                    }
                    break;
                case ACTOR_TINY:
                    if (current_actor_pointer->animation_state->unk0->unk4 < 17.0f) {
                        getBonePosition(current_actor_pointer, 7, &x, &y, &z);
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32 - (y - current_actor_pointer->y_position);
                    }
                    if (current_actor_pointer->animation_state->unk0->unk4 < 19.0f) {
                        current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
                        current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
                    } else if (current_actor_pointer->animation_state->unk0->unk4 < 29.0f) {
                        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                        current_actor_pointer->unkB8 = 40.0f;
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                    } else {
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                    }
                    break;
                case ACTOR_DK:
                    getBonePosition(current_actor_pointer, 7, &x, &y, &z);
                    current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32 - (y - current_actor_pointer->y_position);
                    if (current_actor_pointer->animation_state->unk0->unk4 > 16.0f) {
                        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                        current_actor_pointer->unkB8 = 30.0f;
                    } else {
                        current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
                        current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
                    }
                    break;
                case ACTOR_CHUNKY:
                case ACTOR_KRUSHA:
                    if (current_actor_pointer->animation_state->unk0->unk4 < 18.0f) {
                        getBonePosition(current_actor_pointer, 7, &x, &y, &z);
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32 - (y - current_actor_pointer->y_position);
                        current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
                        current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
                    } else if (current_actor_pointer->animation_state->unk0->unk4 < 26.0f) {
                        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                        current_actor_pointer->unkB8 = 50.0f;
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                    } else {
                        if (ABS_DIFF(current_actor_pointer->floor, extra_player_info_pointer->unkF0_f32) >= 20.0) {
                            func_global_asm_806CFF1C(current_actor_pointer);
                        } else {
                            current_actor_pointer->y_position = current_actor_pointer->floor;
                        }
                    }
                    break;
                default:
                    getBonePosition(current_actor_pointer, 7, &x, &y, &z);
                    current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32 - (y - current_actor_pointer->y_position);
                    if (current_actor_pointer->animation_state->unk0->unk4 > 14.0f) {
                        current_actor_pointer->unkEE = current_actor_pointer->y_rotation;
                        current_actor_pointer->unkB8 = 10.0f;
                        current_actor_pointer->y_position = extra_player_info_pointer->unkF0_f32;
                    } else {
                        current_actor_pointer->x_position = extra_player_info_pointer->unkE0;
                        current_actor_pointer->z_position = extra_player_info_pointer->unkE4;
                    }
                    break;
            }
            func_global_asm_806CC970();
            break;
        case 1:
            func_global_asm_806CC970();
            if (ABS_DIFF(current_actor_pointer->floor, extra_player_info_pointer->unkF0_f32) < 20.0) {
                current_actor_pointer->y_position = current_actor_pointer->floor;
                current_actor_pointer->unk6A |= 1;
                current_actor_pointer->y_velocity = -50.0f;
                func_global_asm_806CFF9C(current_actor_pointer);
            } else {
                func_global_asm_806CFF1C(current_actor_pointer);
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
    func_global_asm_80614A64(current_actor_pointer);
}
*/

void func_global_asm_806DE930(void) {
    extra_player_info_pointer->unk4 = 0.0f;
    if (!handleInputsForControlState(1)) {
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
        current_actor_pointer->control_state_progress++;
    }
    func_global_asm_806D38AC(1);
    extra_player_info_pointer->unk30 = D_global_asm_80750FDC;
}

s32 func_global_asm_8061EB04(Actor *, s32);

void func_global_asm_806DEAA4(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 0:
            func_global_asm_8061C6A8(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0, 0x19, 0, 5, -3, 0xA, 0, 0.15f);
            playAnimation(current_actor_pointer, 0x85);
            current_actor_pointer->control_state_progress++;
            // fallthrough
        case 2:
            func_global_asm_8061C6A8(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x396, 0x19, 0, 5, 0xB, 0xB, 0, 0.15f);
            current_actor_pointer->control_state_progress++;
            break;
        case 4:
            func_global_asm_8061C6A8(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0xE74, 0x14, 0, 5, 0x13, 0xA, 0, 0.15f);
            current_actor_pointer->control_state_progress++;
            break;
        case 6:
            func_global_asm_8061C6A8(extra_player_info_pointer->unk104, current_actor_pointer, 4, 0x800, 0x11, 0, 5, 0x29, 0xA, 0, 0.15f);
            current_actor_pointer->control_state_progress++;
            break;
        case 8:
            func_global_asm_8061EB04(current_actor_pointer, 0);
            extra_player_info_pointer->unk1F0 |= 4;
            break;
    }
    renderActor(current_actor_pointer, 0);
}

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

    handleInputsForControlState(1);
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
            moveAndScaleActorToAnother(
                last_spawned_actor,
                current_actor_pointer,
                current_actor_pointer->animation_state->scale_y * 2
            );
            last_spawned_actor->object_properties_bitfield |= 0x40000000;
            last_spawned_actor->y_rotation += 0x800;
            last_spawned_actor->y_rotation &= 0xFFF;
            last_spawned_actor->unk11C = current_actor_pointer;
            playActorAnimation(last_spawned_actor, 0x2B7);
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
            moveAndScaleActorToAnother(last_spawned_actor,
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
                    changeCollectableCount(D_global_asm_80750FE0[i], 0, 9999);
                    func_global_asm_806F8BC4(D_global_asm_80750FE0[i], 0, 0);
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806DF050(void) {
    PlayerAdditionalActorData *PaaD = current_actor_pointer->PaaD;
    setAction(0x5C, NULL, cc_player_index);
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
    current_actor_pointer->x_position += (PaaD->unk22C - current_actor_pointer->x_position) * 0.125f;
    current_actor_pointer->y_position += (PaaD->unk230 - current_actor_pointer->y_position) * 0.125f;
    current_actor_pointer->z_position += (PaaD->unk234 - current_actor_pointer->z_position) * 0.125f;
    current_actor_pointer->x_rotation += 0xFF;
    renderActor(current_actor_pointer, 0);
}

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
