
#include <ultra64.h>
#include "functions.h"

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
    f32 unk2C;
    s32 unk30;
    u8 *unk34;
    s32 unk38;
    s16 unk3C;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
} AAD_global_asm_806E7C70;

extern s16 D_global_asm_80750338;
extern u8 D_global_asm_80750AB8;
extern f32 D_global_asm_80750FF8;
extern f32 D_global_asm_80750FFC;
extern f32 D_global_asm_80751000;

// .data
extern f32 D_global_asm_807535CC[];
extern f32 D_global_asm_807537E0[];
extern s16 D_global_asm_8075386C[];
extern s16 D_global_asm_8075388C[];
extern f32 D_global_asm_8075389C[];
extern s16 D_global_asm_807538C8[];
extern s16 D_global_asm_807539DC[];
extern s16 D_global_asm_807539EC[];
extern s16 D_global_asm_80753A98[];
extern f32 D_global_asm_80753AA8[];
extern f32 D_global_asm_80753AC4[];
extern f32 D_global_asm_80753B18[];

extern s32 D_global_asm_80767CC0;

extern s32 D_global_asm_807FBB68;
extern f32 D_global_asm_807FD888;

extern void func_global_asm_8068E474(void);
void func_global_asm_8061C2F0(Actor *, f32, f32, f32, f32, f32, f32, s32);
void func_global_asm_8062217C(Actor*, u8);
s16 func_global_asm_8062773C(s32);
void func_global_asm_806E9804(s16 arg0);

void func_global_asm_806E6EE0(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        playAnimation(current_actor_pointer, 0x37);
        current_actor_pointer->control_state_progress = 4;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E6F74(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        playAnimation(current_actor_pointer, 0x37);
        current_actor_pointer->control_state_progress = 4;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E6FF0(void) {
    extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    func_global_asm_80614D00(current_actor_pointer, 2.0f, 0);
    playAnimation(current_actor_pointer, 0x38);
    current_actor_pointer->control_state_progress = 7;
}

void func_global_asm_806E7050(void) {
    playAnimation(current_actor_pointer, 0x39);
    current_actor_pointer->control_state_progress = 7;
}

void func_global_asm_806E7088(void) {
    current_actor_pointer->control_state_progress = 6;
}

void func_global_asm_806E709C(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
            extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            if (extra_player_info_pointer->unk10 == 0) {
                extra_player_info_pointer->unk38 = D_global_asm_80753AC4[D_global_asm_807FD584];
                playAnimation(current_actor_pointer, 0x36);
            } else {
                extra_player_info_pointer->unk38 = D_global_asm_80753AA8[D_global_asm_807FD584];
            }
            extra_player_info_pointer->unk10 = D_global_asm_80753A98[D_global_asm_807FD584];
            extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
        } else if (!(D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
            extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
            extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
            if (extra_player_info_pointer->unk10 == 0) {
                extra_player_info_pointer->unk10 = 1;
                extra_player_info_pointer->unk38 = D_global_asm_80753AA8[D_global_asm_807FD584];
            }
        }
    }
}

void func_global_asm_806E7230(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG)) {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk38 = D_global_asm_80753AC4[D_global_asm_807FD584];
            playAnimation(current_actor_pointer, 0x36);
        } else {
            extra_player_info_pointer->unk38 = D_global_asm_80753AA8[D_global_asm_807FD584];
        }
        extra_player_info_pointer->unk10 = D_global_asm_80753A98[D_global_asm_807FD584];
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E7338(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        current_actor_pointer->control_state_progress = 3;
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk38 = 300.0f;
            playActorAnimation(current_actor_pointer, 0x318);
        } else {
            extra_player_info_pointer->unk38 = 250.0f;
        }
        extra_player_info_pointer->unk10 = 0xF;
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    } else if (!(D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON)) {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk10 = 1;
            extra_player_info_pointer->unk38 = 250.0f;
        }
    }
}

void func_global_asm_806E7484(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        current_actor_pointer->control_state_progress = 3;
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        if (extra_player_info_pointer->unk10 == 0) {
            extra_player_info_pointer->unk38 = 300.0f;
            playActorAnimation(current_actor_pointer, 0x318);
        } else {
            extra_player_info_pointer->unk38 = 250.0f;
        }
        extra_player_info_pointer->unk10 = 0xF;
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E7568(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        extra_player_info_pointer->unk38 = D_global_asm_80753AC4[D_global_asm_807FD584];
        playAnimation(current_actor_pointer, 0x36);
        current_actor_pointer->control_state_progress = 3;
        extra_player_info_pointer->unk10 = D_global_asm_80753A98[D_global_asm_807FD584];
        extra_player_info_pointer->unk5C = D_global_asm_80767CC0;
    }
}

void func_global_asm_806E7658(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS) && !(D_global_asm_807FBB64 & 2)) {
        func_global_asm_806E9804(8);
    } else {
        extra_player_info_pointer->unk12 = current_actor_pointer->z_rotation;
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        extra_player_info_pointer->unk10 = 0;
        extra_player_info_pointer->unk30 = 8.0f;
    }
}

u8 playerCanDive(void) {
    return isFlagSet(0x182, FLAG_TYPE_PERMANENT) // Check whether dive barrel is complete
        || (D_global_asm_807FBB64 & 0x10000000)
        || (cc_number_of_players > 1)
        || gameIsInMysteryMenuMinigameMode();
}

void func_global_asm_806E7780(void) {
    f32 phi_f0;

    if ((D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS) && !(D_global_asm_807FBB64 & 2)) {
        func_global_asm_806E9804(8);
        return;
    }
    if (character_change_array[cc_player_index].unk2C0 == 1) {
        phi_f0 = D_global_asm_8075386C[D_global_asm_807FD584];
    } else {
        phi_f0 = D_global_asm_8075389C[D_global_asm_807FD584];
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2C & Z_TRIG) && (phi_f0 < current_actor_pointer->distance_from_floor) && playerCanDive()) {
        setAction(0x3E, NULL, cc_player_index);
        playSoundAtActorPosition(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
    }
}

void func_global_asm_806E78B8(void) {
    extra_player_info_pointer->unk30 = D_global_asm_80753B18[D_global_asm_807FD584];
}

void func_global_asm_806E78E0(void) {
    extra_player_info_pointer->unk30 = 1.0f;
}

void func_global_asm_806E78F8(void) {

}

void func_global_asm_806E7900(void) {
    // TODO: There might be a special aaD type for minecart
    // Could also be a RaaD, not sure yet
    PlayerAdditionalActorData *PaaD = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (current_actor_pointer->control_state == 7) {
        if (!(D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG)) {
            if ((D_global_asm_807FD610[cc_player_index].unk2E < -0x1E) && (current_actor_pointer->animation_state->unk0->unk10 != 0xFB)) {
                playAnimation(current_actor_pointer, 0x81);
                current_actor_pointer->control_state = 0xA; // Minecart (Left)
                current_actor_pointer->control_state_progress = 0;
                PaaD->unk42 = 1;
            } else if ((D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) && (current_actor_pointer->animation_state->unk0->unk10 != 0xFF)) {
                playAnimation(current_actor_pointer, 0x7D);
                current_actor_pointer->control_state = 0xB; // Minecart (Right)
                current_actor_pointer->control_state_progress = 0;
                PaaD->unk42 = 2;
            }
        }
    }
    if (((D_global_asm_807FD610[cc_player_index].unk2E < 0x1E) && (current_actor_pointer->control_state != 0xA)) || ((D_global_asm_807FD610[cc_player_index].unk2E >= -0x1D) && (current_actor_pointer->control_state != 0xB))) {
        PaaD->unk42 = 0;
        switch (current_actor_pointer->control_state) {
            case 0xB:
                if (current_actor_pointer->control_state_progress == 1) {
                    playAnimation(current_actor_pointer, 0x7E);
                } else {
                    playAnimation(current_actor_pointer, 0x80);
                }
                current_actor_pointer->control_state = 7; // Minecart (Idle)
                current_actor_pointer->control_state_progress = 0;
                break;
            case 0xA:
                if (current_actor_pointer->control_state_progress == 1) {
                    playAnimation(current_actor_pointer, 0x82);
                } else {
                    playAnimation(current_actor_pointer, 0x80);
                }
                current_actor_pointer->control_state = 7; // Minecart (Idle)
                current_actor_pointer->control_state_progress = 0;
                break;
        }
    }
}

void func_global_asm_806E7B48(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    if (extra_player_info_pointer->unk1F0 & 8) {
        RaaD->unk3E = 4;
    } else {
        RaaD->unk3E = (D_global_asm_807FD610[cc_player_index].unk2F * 0.5) + 60.0;
    }
    func_global_asm_806E7900();
}

void func_global_asm_806E7C70(void) {
    AAD_global_asm_806E7C70 *temp_v0;

    temp_v0 = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (temp_v0->unk0 != 0) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
    }
    func_global_asm_806E7900();
    if (extra_player_info_pointer->unk1F0 & 8) {
        temp_v0->unk3E = 3;
    } else {
        temp_v0->unk3E = (D_global_asm_807FD610[cc_player_index].unk2F / 1.5) + 80.0;
    }
    temp_v0->unk2 = D_global_asm_807FD610[cc_player_index].unk2E;
}

void func_global_asm_806E7DF4(void) {
    AAD_global_asm_806E7C70 *var_a2;

    var_a2 = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (var_a2->unk0 != 0) {
        D_global_asm_807FD610[cc_player_index].unk2E = 0;
    } else {
        u8 var_a3 = extra_player_info_pointer->vehicle_actor_pointer->control_state == 5 ? 1 : 0;
        s32 var_a1 = (var_a2->unk34[0] & 0x80) ? 1 : 3;
        if (var_a3 != 0) {
            D_global_asm_807FD610[cc_player_index].unk2E *= -1;
        }
        if ((extra_player_info_pointer->unk1F0 & 0x10000002) != 0) {
            D_global_asm_807FD610[cc_player_index].unk2E *= -1;
        }
        if ((extra_player_info_pointer->unk1F0 & 0x10000002) != 0) {
            D_global_asm_807FD610[cc_player_index].unk2F *= -1;
        }
        if (var_a2->unk34[0] & 0xC0) {
            if ((D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F && var_a2->unk3F > 0) || (D_global_asm_807FD610[cc_player_index].unk2E < -0x1E && var_a2->unk3F < var_a1)) {
                extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280;
                extra_player_info_pointer->vehicle_actor_pointer->y_velocity = D_global_asm_80750338;
                extra_player_info_pointer->unk58 = D_global_asm_80767A40.unk280 - 0x1E;
                var_a2->unk2C = 1.0f;
                var_a2->unk40 = var_a2->unk3F;
                if (D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) {
                    var_a2->unk3F--;
                    if (var_a2->unk3F == 1) {
                        var_a2->unk3F = 0;
                    }
                    playAnimation(current_actor_pointer, var_a3 ? 0x81 : 0x7D);
                    playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, var_a3 ? 0x295 : 0x296);
                } else {
                    var_a2->unk3F++;
                    if (var_a2->unk3F == 1) {
                        if (var_a2->unk34[0] & 0x40) {
                            var_a2->unk3F = 2;
                        }
                    }
                    playAnimation(current_actor_pointer, var_a3 ? 0x7D : 0x81);
                    playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, var_a3 ? 0x296 : 0x295);
                }
            }
        }
    }
    if (extra_player_info_pointer->unk1F0 & 8) {
        var_a2->unk3E = 3;
        extra_player_info_pointer->vehicle_actor_pointer->unkB8 = 3.0f;
        return;
    }
    var_a2->unk3E = (D_global_asm_807FD610[cc_player_index].unk2F / 1.5) + 80.0;
}

void func_global_asm_806E8244(void) {
    RaceAdditionalActorData *RaaD;
    s8 temp_t4;

    RaaD = extra_player_info_pointer->vehicle_actor_pointer->additional_actor_data;
    if (func_global_asm_805FCA64()) {
        addActorToTextOverlayRenderArray(func_global_asm_8068E474, extra_player_info_pointer->vehicle_actor_pointer, 5);
    }
    if ((current_actor_pointer->y_rotation < 0x200) || (current_actor_pointer->y_rotation >= 0xE01)) {
        RaaD->unk2 = D_global_asm_807FD610[cc_player_index].unk2E;
    } else if ((current_actor_pointer->y_rotation >= 0x201) && (current_actor_pointer->y_rotation < 0x600)) {
        RaaD->unk2 = D_global_asm_807FD610[cc_player_index].unk2F;
        temp_t4 = D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2E = D_global_asm_807FD610[cc_player_index].unk2F;
        D_global_asm_807FD610[cc_player_index].unk2F = temp_t4;
    } else if ((current_actor_pointer->y_rotation >= 0x601) && (current_actor_pointer->y_rotation < 0xA00)) {
        RaaD->unk2 = -D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2E = -D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2F = -D_global_asm_807FD610[cc_player_index].unk2F;
    } else {
        RaaD->unk2 = -D_global_asm_807FD610[cc_player_index].unk2F;
        temp_t4 = D_global_asm_807FD610[cc_player_index].unk2E;
        D_global_asm_807FD610[cc_player_index].unk2E = -D_global_asm_807FD610[cc_player_index].unk2F;
        D_global_asm_807FD610[cc_player_index].unk2F = -temp_t4;
    }
    if (D_global_asm_807FD610[cc_player_index].unk2E < -0x1E) {
        extra_player_info_pointer->unk23C = 0x28;
        RaaD->unk42 = 1;
    } else if (D_global_asm_807FD610[cc_player_index].unk2E >= 0x1F) {
        extra_player_info_pointer->unk23C = 0x28;
        RaaD->unk42 = 2;
    } else if (extra_player_info_pointer->unk23C != 0) {
        extra_player_info_pointer->unk23C--;
    } else {
        RaaD->unk42 = 0;
    }
}

void func_global_asm_806E84A4(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    RaaD->unk3E = 0x14;
}

void func_global_asm_806E84C0(void) {
    RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
    RaaD->unk3E = 0x64;
    if (extra_player_info_pointer->unk23C) {
        extra_player_info_pointer->unk23C--;
    }
}

void func_global_asm_806E84F8(void) {
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & (A_BUTTON | B_BUTTON | Z_TRIG))) {
        RaceAdditionalActorData *RaaD = extra_player_info_pointer->vehicle_actor_pointer->RaaD;
        RaaD->unk3E = 0x32;
    }
}

typedef struct {
    u8 unk0[0xC - 0x0];
    f32 unkC;
    f32 unk10;
} Struct806E854C_arg0;

void func_global_asm_806E854C(Struct806E854C_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 var_v0_2;
    f32 temp_f2;
    f32 var_f2;

    if (arg2 != current_player->animation_state->unk0->unk10) {
        if (arg1 == current_player->animation_state->unk0->unk10) {
            func_global_asm_80613C48(current_player, arg2, 0, 5.0f);
        } else {    
            if ((current_actor_pointer->animation_state->unk0->unk24 >= 0) && (current_player->animation_state->unk0->unk4 > 0)) {
                func_global_asm_80614D48(current_player, -1.0f, 0);
            }
            if (current_actor_pointer->animation_state->unk0->unk4 == 0) {
                func_global_asm_80613C48(current_player, arg2, 0, 5.0f);
            }
        }
    } else {
        var_f2 = ABS(arg0->unkC) - 0.2f;
        temp_f2 = (arg0->unk10 > 1.0 ? 8 : 5) * var_f2 * 1.25f;
        if (((temp_f2 - 1) <= current_player->animation_state->unk0->unk4) && (current_player->animation_state->unk0->unk4 <= (temp_f2 + 1))) {
            var_v0_2 = 0;
        } else {
            if (temp_f2 <= current_player->animation_state->unk0->unk4) {
                var_v0_2 = -1;
            } else {
                var_v0_2 = 1;
            }
        }
        func_global_asm_80614D48(current_player, var_v0_2, 5.0f);
    }
}

void func_global_asm_806E8724(Actor *arg0, RaceAdditionalActorData *arg1) {
    f32 temp_f0;
    s32 temp_t1;
    s32 phi_a0;

    if ((arg1->unk45 == 0) && (arg1->unk34 == 2)) {
        temp_t1 = D_global_asm_807FD610[cc_player_index].unk2F < -0x14;
        phi_a0 = D_global_asm_807FD610[cc_player_index].unk2E >= 0 ? 1 : -1;
        arg1->unkC = 0.0125f * (MIN(80.0f, D_global_asm_807FD610[cc_player_index].unk30) * phi_a0);
        arg1->unkC *= D_global_asm_80750FFC;
        if (arg1->unk20 == 0) {
            arg1->unk20 = (arg0->unkB8 < D_global_asm_80750FF8) & temp_t1;
            return;
        } else {
            arg1->unk20 = temp_t1;
            return;
        }
    }
    arg1->unk20 = 0;
    arg1->unkC = 0.0f;
}

void func_global_asm_806E884C(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        func_global_asm_806E8724(vehicle, vehicle->additional_actor_data);
    }
}

void func_global_asm_806E8880(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        PaaD0 *paad = vehicle->PaaD0;
        paad->unk8 = D_global_asm_80751000;
    }
}

void func_global_asm_806E88AC(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        PaaD0 *paad = vehicle->PaaD0;
        paad->unk8 = 0.0f;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
} AAD_806E88D8;

void func_global_asm_806E88D8(void) {
    Actor *vehicle;
    AAD_806E88D8 *aaD;
    s32 sp24;
    s32 var_a2;
    s32 sp1C;
    ActorAnimationState *playerAnimationState;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle != NULL) {
        if (current_actor_pointer->unk58 == ACTOR_LANKY) {
            sp24 = 0x1C7;
            var_a2 = 0x1C5;
            sp1C = 0x1C6;
        } else {
            sp24 = 0x53;
            var_a2 = 0x54;  
            sp1C = 0x55;
        }
        aaD = vehicle->additional_actor_data;
        func_global_asm_806E8724(vehicle, aaD);
        if ((func_global_asm_8061CB50() == 0) && (playerAnimationState = current_player->animation_state, (playerAnimationState->unk64 != 0x3B5))) {
            if ((aaD->unkC < 0.2f) && (aaD->unkC > -0.2f) && ((sp24 != playerAnimationState->unk0->unk10))) {
                if ((playerAnimationState->unk0->unk24 >= 0.0f) && (playerAnimationState->unk0->unk4 > 0.0f)) {
                    func_global_asm_80614D48(current_player, -1.0f, 5.0f);
                    return;
                }
                if (current_actor_pointer->animation_state->unk0->unk4 == 0.0f) {
                    func_global_asm_80613C48(current_player, sp24, 0.0f, 5.0f);
                }
            } else {
                if (aaD->unkC < -0.2f) {
                    func_global_asm_806E854C(aaD, sp24, var_a2);
                    return;
                }
                if (aaD->unkC > 0.2f) {
                    func_global_asm_806E854C(aaD, sp24, sp1C);
                }
            }
        }
    }
}

void func_global_asm_806E8A8C(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if ((RaaD->unk45 == 0) && (RaaD->unk34 == 2)) {
            if (!RaaD->unk25) {
                RaaD->unk4 = 1.1f;
            }
        } else {
            RaaD->unk4 = 0;
        }
    }
}

void func_global_asm_806E8AF0(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if (RaaD->unk25 == 0) {
            RaaD->unk4 = 0.0f;
        }
    }
}

void func_global_asm_806E8B28(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if ((RaaD->unk45 == 0) && (RaaD->unk34 == 2)) {
            Actor178 *r178 = vehicle->unk178;
            if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
                r178->unk4 = 1;
            }
        }
    }
}

void func_global_asm_806E8BA4(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->RaaD;
        if ((RaaD->unk45 == 0) && (RaaD->unk34 == 2)) {
            RaaD->unk10 = 2.0f;
        } else {
            RaaD->unk10 = 1.0f;
        }
    }
}

void func_global_asm_806E8BFC(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaceAdditionalActorData* RaaD = vehicle->RaaD;
        RaaD->unk10 = 1.0f;
    }
}

// TODO: Actor->animation_state->unk0->unk10
// TODO: Pointer to something at aaD->unk30, size at least 0x154
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EBBE0/func_global_asm_806E8C2C.s")

void func_global_asm_806E8D54(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        if (vehicle->RaaD->unk34 && (vehicle->RaaD->unk34 < 3) && !vehicle->RaaD->unk45) {
            RaceActor178 *r178 = vehicle->race178;
            vehicle->RaaD->unk4 = r178->unk14 + 1.1;
        }
    }
}

void func_global_asm_806E8DB4(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        if ((vehicle->RaaD->unk34) && (vehicle->RaaD->unk34 < 3) && !vehicle->RaaD->unk45) {
            RaceActor178 *r178 = vehicle->race178;
            vehicle->RaaD->unk4 = r178->unk14;
        }
    }
}

void func_global_asm_806E8E00(void) {
    Actor *vehicle;
    RaceAdditionalActorData *RaaD;

    vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (vehicle) {
        RaaD = vehicle->additional_actor_data;
        if (RaaD->unk45 == 0 && RaaD->unk34 == 2 && (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON)) {
            RaaD->unk29 = 1;
        }
    }
}

void func_global_asm_806E8E78(void) {
    if (current_actor_pointer->control_state == 7 && !(D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG)) {
        playAnimation(current_actor_pointer, 0x7F);
        current_actor_pointer->control_state = 8;
        current_actor_pointer->control_state_progress = 0;
    }
}

void func_global_asm_806E8F04(void) {
    if (current_actor_pointer->control_state_progress == 1) {
        playAnimation(current_actor_pointer, 0x7B);
    } else {
        playAnimation(current_actor_pointer, 0x80);
    }
    current_actor_pointer->control_state = 7;
    current_actor_pointer->control_state_progress = 0;
}

void func_global_asm_806E8F68(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) && (!(D_global_asm_807FD610[cc_player_index].unk2A & R_TRIG))) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) {
        current_actor_pointer->control_state = 9;
        current_actor_pointer->control_state_progress = 0;
        extra_player_info_pointer->unk54 = D_global_asm_807537E0[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        playAnimation(current_actor_pointer, 0x7C);
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EBBE0/func_global_asm_806E9070.s")

/*
// TODO: D_global_asm_80767CC0 might be a struct.280 access, or an array? idk
void func_global_asm_806E9070(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if (((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU) && extra_player_info_pointer->vehicle_actor_pointer->RaaD->unk0 == 0) {
        extra_player_info_pointer->vehicle_actor_pointer->y_velocity = D_global_asm_80750338;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        playAnimation(current_actor_pointer, 0x7C);
        if (current_actor_pointer->unk58 == ACTOR_DK) {
            playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x294);
        } else {
            playActorAnimation(extra_player_info_pointer->vehicle_actor_pointer, 0x293);
        }
    }
}
*/

void func_global_asm_806E918C(void) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    if (!(extra_player_info_pointer->unk1F0 & 0x10000000)) {
        if (D_global_asm_807FD610[cc_player_index].unk2A & 0x10) {
            if (current_actor_pointer->control_state == 7) {
                getBonePosition(extra_player_info_pointer->vehicle_actor_pointer, 3, &sp54, &sp50, &sp4C);
                getBonePosition(extra_player_info_pointer->vehicle_actor_pointer, 4, &sp48, &sp44, &sp40);
                func_global_asm_8061C2F0(extra_player_info_pointer->unk104, sp48, sp44 + 8.0f, sp40, (sp48 - sp54) + sp48, (sp44 - sp50) + sp44 + 5.0f, (sp40 - sp4C) + sp40, 1);
                extra_player_info_pointer->unk1F0 |= 2;
                current_actor_pointer->object_properties_bitfield |= 0x400;
                return;
            }
        }
        if (extra_player_info_pointer->unk1F0 & 2) {
            extra_player_info_pointer->unk1F0 &= ~2;
            func_global_asm_8061C6A8(extra_player_info_pointer->unk104, extra_player_info_pointer->vehicle_actor_pointer, 4, 0x800, 0x28, 0, 5, 0x19, 0x14, 0, 0.15f);
            if (current_actor_pointer->control_state == 7) {
                playAnimation(current_actor_pointer, 0x84);
            }
        }
        current_actor_pointer->object_properties_bitfield &= ~0x400;
    }
}

void func_global_asm_806E9388(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        current_actor_pointer->control_state = 0x80; // Enguarde Attacking (surface)
        current_actor_pointer->control_state_progress = 0;
        playActorAnimation(current_actor_pointer, 0x316);
    }
}

void func_global_asm_806E93F8(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) {
        current_actor_pointer->control_state = 0x81; // Enguarde Attacking
        current_actor_pointer->control_state_progress = 0;
        playActorAnimation(current_actor_pointer, 0x316);
    }
}

void func_global_asm_806E9468(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | Z_TRIG)) {
        extra_player_info_pointer->unk12 = D_global_asm_807539EC[D_global_asm_807FD584];
        extra_player_info_pointer->unk14 = current_actor_pointer->y_rotation;
        extra_player_info_pointer->unk10 = D_global_asm_807539DC[D_global_asm_807FD584];
        current_actor_pointer->control_state = 0x7F;
        current_actor_pointer->control_state_progress = 0;
        current_actor_pointer->control_state_progress = 1;
        if (current_actor_pointer->y_velocity > 0.0f) {
            current_actor_pointer->y_velocity = 0.0f;
        }
        playActorAnimation(current_actor_pointer, 0x318);
        playSoundAtActorPosition(current_actor_pointer, 0x10, 0xFF, 0x7F, 1);
    }
}

u8 func_global_asm_806E9580(void) {
    f32 temp_f2;
    f32 sp24; // TODO: Hmm, can we get rid of this?
    f32 var_f0;
    u8 sp1B;
    s32 var_v1;

    sp1B = 0;
    extra_player_info_pointer->unk24 = 0;
    var_v1 = 0x1E;
    if (current_actor_pointer->unk6A & 4) {
        if (current_actor_pointer->y_velocity <= 0.0f) {
            if (current_actor_pointer->y_velocity > -150.0f) {
                current_actor_pointer->y_velocity = current_actor_pointer->y_velocity;
            } else {
                current_actor_pointer->y_velocity = -150.0f;
            }
            temp_f2 = current_actor_pointer->unkAC - current_actor_pointer->y_position;
            if (character_change_array[cc_player_index].unk2C0 == 2) {
                var_v1 = 0x3C;
            }
            if ((var_v1 < temp_f2) && (sp24 = temp_f2, (playerCanDive() != 0))) {
                setAction(0x3E, NULL, cc_player_index);
                func_global_asm_806CA2AC();
            } else {
                if (current_actor_pointer->unk6A & 1) {
                    if (character_change_array[cc_player_index].unk2C0 == 1) {
                        var_f0 = D_global_asm_8075386C[D_global_asm_807FD584];
                    } else {
                        var_f0 = D_global_asm_8075389C[D_global_asm_807FD584];
                    }
                    if (var_f0 < temp_f2) {
                        setAction(0x3D, NULL, cc_player_index);
                        sp1B = 1;
                        func_global_asm_806CA2AC();
                    }
                } else {
                    if (character_change_array[cc_player_index].unk2C0 == 1) {
                        var_f0 = D_global_asm_8075388C[D_global_asm_807FD584];
                    } else {
                        var_f0 = D_global_asm_807538C8[D_global_asm_807FD584];
                    }
                    if (var_f0 < (current_actor_pointer->distance_from_floor + temp_f2)) {
                        setAction(0x3D, NULL, cc_player_index);
                        playActorAnimation(current_actor_pointer, 0);
                        if (extra_player_info_pointer->unkC4 != 0) {
                            func_global_asm_80737924(extra_player_info_pointer->unkC4);
                        }
                        sp1B = 1;
                        func_global_asm_806CA2AC();
                    }
                }
            }
        }
    }
    return sp1B;
}

void func_global_asm_806E9804(s16 arg0) {
    // Do we have the camera and are we pressing C-Down
    if (isFlagSet(0x179, FLAG_TYPE_PERMANENT) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        func_global_asm_806E9D1C(arg0, 0xB, 0);
    }
}

void func_global_asm_806E9874(void) {
    if (!(D_global_asm_807FBB64 & 2) && current_character_index[cc_player_index] < 5) {
        func_global_asm_806E9804(6);
        character_change_array[cc_player_index].fov_y = 45.0f;
    }
}

void func_global_asm_806E98F8(void) {
    // Are we pressing Z and C-Down?
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806E9874();
    }
}

void func_global_asm_806E9964(PlayerAdditionalActorData *arg0) {
    s32 phi_v0 = current_actor_pointer->control_state == 5 || current_actor_pointer->control_state == 0x65;
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        if (phi_v0) {
            func_global_asm_806E9D1C(7, 3, 0);
        } else {
            func_global_asm_806E9D1C(5, 3, 0);
        }
    } else {
        func_global_asm_806EAB44(current_actor_pointer, phi_v0);
    }
    func_global_asm_806F8D58(6, 1);
    func_global_asm_806F8D58(0xC, 1);
    arg0->unk1F0 &= ~0x8000;
}

void func_global_asm_806E9A5C(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x8000) && (D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == U_CBUTTONS) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

void func_global_asm_806E9ACC(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x8000) && (D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

void func_global_asm_806E9B3C(void) {
    if (!(extra_player_info_pointer->unk1F0 & 0x8000) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        func_global_asm_806E9964(extra_player_info_pointer);
    }
}

// close, regalloc
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EBBE0/func_global_asm_806E9BA8.s")

/*
void func_global_asm_806E9BA8(s32 arg0) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON) && !(extra_player_info_pointer->unk1F0 & 0x8000) && func_global_asm_806F8AD4(6, cc_player_index) > 0) {
        playSound(0x263, 0x7FFF, 63.0f, 1.0f, 0xA, 0);
        current_actor_pointer->control_state = arg0;
        current_actor_pointer->control_state_progress = 0;
        changeCollectableCount(6, cc_player_index, -1);
        createLight(
            character_change_array[cc_player_index].look_at_eye_x,
            character_change_array[cc_player_index].look_at_eye_y,
            character_change_array[cc_player_index].look_at_eye_z,
            character_change_array[cc_player_index].look_at_at_x,
            character_change_array[cc_player_index].look_at_at_y,
            character_change_array[cc_player_index].look_at_at_z,
            0.0f,
            1,
            0xFF,
            0xFF,
            0xFF
        );
    }
}
*/

void func_global_asm_806E9CDC(void) {
    func_global_asm_806E9BA8(0x64);
}

void func_global_asm_806E9CFC(void) {
    func_global_asm_806E9BA8(0x65);
}

s32 func_global_asm_806E9D1C(s16 arg0, u8 arg1, u8 arg2) {
    if (((cc_number_of_players < 2) || (D_global_asm_80750AB8 != 1)) && (D_global_asm_807FD888 == 0.0f) && (current_actor_pointer->unkE0 == 0.0f)) {
        func_global_asm_806EB178(cc_player_index, arg1, arg2, 0);
        setAction(arg0, NULL, cc_player_index);
        current_actor_pointer->unkB8 = 0.0f;
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806E9DE0(void) {
    PlayerAdditionalActorData *sp1C; // TODO: This is probably not a PaaD

    if (D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS) {
        sp1C = extra_player_info_pointer->unk104->additional_actor_data;
        if ((func_global_asm_80714608(0) == 0) && !(sp1C->unkAC & 0x80000000) && (((((current_actor_pointer->control_state == 0x5D)) || (current_actor_pointer->control_state == 0x5E) || (current_actor_pointer->control_state == 0x62)) && !(D_global_asm_807FBB64 & 0x80000000)) || (current_actor_pointer->control_state == 0x4E) || (current_actor_pointer->control_state == 0x4F) || (current_actor_pointer->control_state == 0xD) || (current_actor_pointer->control_state == 0xC))) {
            func_global_asm_806E9D1C(5, 3, 0);
        }
    }
}

void func_global_asm_806E9ECC(void) {
    PlayerAdditionalActorData *sp1C;

    if (D_global_asm_807FD610[cc_player_index].unk2C & 2) {
        if (current_actor_pointer->unk6A & 1) {
            sp1C = extra_player_info_pointer->unk104->additional_actor_data;
            if (func_global_asm_80714608(0) == 0) {
                if (!(sp1C->unkAC & 0x80000000)) {
                    if (!(D_global_asm_807FBB64 & 0x80000000)) {
                        func_global_asm_806E9D1C(5, 3, 1);
                    }
                }
            }
        }
    }
}

void func_global_asm_806E9F8C(void) {
    PlayerAdditionalActorData *sp1C;

    if (D_global_asm_807FD610[cc_player_index].unk2C & 8) {
        if (current_actor_pointer->unk6A & 1) {
            sp1C = extra_player_info_pointer->unk104->additional_actor_data;
            if (func_global_asm_80714608(0) == 0) {
                if (!(sp1C->unkAC & 0x80000000)) {
                    if (!(D_global_asm_807FBB64 & 0x80000000)) {
                        func_global_asm_806E9D1C(5, 3, 1);
                    }
                }
            }
        }
    }
}

void func_global_asm_806EA04C(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & U_CBUTTONS) {
        func_global_asm_806E9D1C(7, 3, 0);
    }
}

void func_global_asm_806EA0A4(void) {
    PlayerAdditionalActorData *PaaD; // TODO: Probably not actually PaaD
    u16 temp;
    u8 phi_a0;

    PaaD = extra_player_info_pointer->unk104->PaaD;
    if ((D_global_asm_807FBB64 & 1) && !(D_global_asm_807FBB68 & 2)) {
        phi_a0 = 2;
    } else {
        phi_a0 = 3;
    }
    if ((PaaD->unkEF) && ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) && ((PaaD->unkEE == phi_a0) || (PaaD->unkFC == 0))) {
        PaaD->unkF0_u8[0] = PaaD->unkEF;
        if (PaaD->unkEF < phi_a0) {
            PaaD->unkEF++;
        } else {
            PaaD->unkEF = 1;
        }
        func_global_asm_8062217C(extra_player_info_pointer->unk104, PaaD->unkEF);
        PaaD->unkEE = PaaD->unkEF;
        if (PaaD->unkEF != PaaD->unkF0) {
            temp = PaaD->unk8;
            if ((((temp == 0)) || (temp >= 0x96)) && (PaaD->unkF0_u8[3] != 2)) {
                playSound(0x27, 0x7FFF, 63.0f, 1.0f, 0, 0);
            }
        }
        PaaD->unkF0_u8[1] = 0xB;
        PaaD->unkF4_u8[2] = 0xF;
    }
}

void func_global_asm_806EA200(void) {
    PlayerAdditionalActorData *PaaD = extra_player_info_pointer->unk104->PaaD;
    if ((D_global_asm_807FD610[cc_player_index].unk2C & L_CBUTTONS) && (PaaD->unkF0_u8[1] < 3)) {
        PaaD->unkB0 -= 0x2D;
        PaaD->unkF0_u8[1] = 0xB;
    }
}

void func_global_asm_806EA26C(void) {
    PlayerAdditionalActorData *PaaD = extra_player_info_pointer->unk104->PaaD;
    if ((D_global_asm_807FD610[cc_player_index].unk2C & R_CBUTTONS) && (PaaD->unkF0_u8[1] < 3)) {
        PaaD->unkB0 += 0x2D;
        PaaD->unkF0_u8[1] = 0xB;
    }
}

f32 func_global_asm_806EA2D8(void) {
    return D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG ? 0.2 : 1;
}

void func_global_asm_806EA334(void) {
    f32 temp_f2;
    f32 phi_f0;

    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && !(D_global_asm_807FD610[cc_player_index].unk2A & L_CBUTTONS) && current_actor_pointer->control_state == 2) {
        phi_f0 = current_map == MAP_DK_ISLES_OVERWORLD ? 15.0 : 13.0;
        temp_f2 = character_change_array[cc_player_index].fov_y - 1.5f;
        if (phi_f0 < temp_f2) {
            character_change_array[cc_player_index].fov_y = temp_f2;
            func_global_asm_80604CBC(current_actor_pointer, 0x1F0, 0, 0, 0, 0xFF, 1.0f, -1);
        } else {
            character_change_array[cc_player_index].fov_y = phi_f0;
            func_global_asm_80605314(current_actor_pointer, 0);
        }
    }
}

void func_global_asm_806EA460(void) {
    f32 temp_f0;
    if (!(D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && !(D_global_asm_807FD610[cc_player_index].unk2A & R_CBUTTONS) && current_actor_pointer->control_state == 2) {
        temp_f0 = character_change_array[cc_player_index].fov_y + 1.5f;
        if (temp_f0 < 45.0) {
            character_change_array[cc_player_index].fov_y = temp_f0;
            func_global_asm_80604CBC(current_actor_pointer, 0x1F0, 0, 0, 0, 0xFF, 1.0f, -1);
        } else {
            character_change_array[cc_player_index].fov_y = 45.0f;
            func_global_asm_80605314(current_actor_pointer, 0);
        }
    }
}

void func_global_asm_806EA568(void) {
    u16 temp = D_global_asm_807FD610[cc_player_index].unk2A & (L_CBUTTONS | R_CBUTTONS);
    if (temp != L_CBUTTONS && temp != R_CBUTTONS) {
        func_global_asm_80605314(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA5CC(void) {
    if (func_global_asm_806E9580()) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EA600(void) {
    func_global_asm_806EA568();
    func_global_asm_806EA5CC();
}

// close, float, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_EBBE0/func_global_asm_806EA628.s")

f32 func_global_asm_806EA2D8(void);

/*
void func_global_asm_806EA628(void) {
    PlayerAdditionalActorData *temp_a0;
    f32 *temp_v0;
    s16 *temp_v1;

    if (!(extra_player_info_pointer->unk1F0 & 0x8000)) {
        temp_a0 = extra_player_info_pointer->unk104->additional_actor_data;
        temp_v1 = &temp_a0->unkB2;
        *temp_v1 = (D_global_asm_807FD610[cc_player_index].unk2E * 0.08 * func_global_asm_806EA2D8() * 4096.0) / 360.0;
        temp_v0 = &temp_a0->unkB8;
        *temp_v0 = D_global_asm_807FD610[cc_player_index].unk2F * 0.04 * func_global_asm_806EA2D8();
        *temp_v1 &= 0xFFF;
        if (temp_a0->unkBC + 0x32 < *temp_v0) {
            *temp_v0 = temp_a0->unkBC + 0x32;
        } else if (*temp_v0 < temp_a0->unkBC - 0x50) {
            *temp_v0 = temp_a0->unkBC - 0x50;
        }
        extra_player_info_pointer->unk104->distance_from_floor = *temp_v0;
        current_actor_pointer->y_rotation = (temp_a0->unkB2 + 0x800) & 0xFFF;
    }
}
*/

void func_global_asm_806EA7E8(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == A_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA844(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == B_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA8A0(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == A_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EA8FC(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (A_BUTTON | B_BUTTON)) == B_BUTTON) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EA958(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == U_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EA9B4(void) {
    // TODO: Bitfield syntax?
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS)) {
        func_global_asm_806E9874();
    } else if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 0);
    }
}

void func_global_asm_806EAA44(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == U_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EAAA0(void) {
    if ((D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) && (D_global_asm_807FD610[cc_player_index].unk2C & D_CBUTTONS) && !(D_global_asm_807FBB64 & 2)) {
        func_global_asm_806E9804(8);
        return;
    }
    if ((D_global_asm_807FD610[cc_player_index].unk2C & (U_CBUTTONS | D_CBUTTONS)) == D_CBUTTONS) {
        func_global_asm_806EAB44(current_actor_pointer, 1);
    }
}

void func_global_asm_806EAB44(Actor *arg0, u8 arg1) {
    PlayerAdditionalActorData *PaaD = arg0->PaaD;
    if ((PaaD->unk1F4 & 0x10) == 0) {
        playSound(0x27, 0x7FFF, 63.0f, 1.0f, 0, 0);
    }
    if (arg1 != 0) {
        if (current_character_index[cc_player_index] == 7) {
            if ((arg0->unkAC - arg0->y_position) < 20.0f) {
                arg0->control_state = 0x7E;
                arg0->control_state_progress = 0;
            } else {
                arg0->control_state = 0x7F;
                arg0->control_state_progress = 0;
            }
        } else {
            arg0->control_state = 0x4F;
            arg0->control_state_progress = 3;
        }
    } else {
        arg0->control_state = 1;
        arg0->control_state_progress = 0;
        func_global_asm_806CFF9C(arg0);
        if (arg0->control_state == 0xC) {
            arg0->control_state_progress = 0xA;
        }
    }
    if (PaaD->unk8C != 0) {
        func_global_asm_806F0D68(arg0);
    } else {
        func_global_asm_806F0C18(arg0);
    }
    arg0->unkB8 = 0.0f;
    arg0->y_rotation = func_global_asm_8062773C(PaaD->unk104);
}

void func_global_asm_806EAC8C(void) {
    Actor178 *temp_v0 = extra_player_info_pointer->vehicle_actor_pointer->unk178;
    if (temp_v0->unkE == 5) {
        temp_v0->unkE = 0xA;
    }
}

void func_global_asm_806EACBC(void) {
    Actor178 *temp_v0 = extra_player_info_pointer->vehicle_actor_pointer->unk178;
    if (temp_v0->unkE == 5) {
        temp_v0->unkE = 0xF;
    }
}

void func_global_asm_806EACEC(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0;
    }
    if ((current_actor_pointer->unk6A & 1) && ((D_global_asm_80767CC0 - extra_player_info_pointer->unk58) < 0xFU)) {
        func_global_asm_806CFECC();
        current_actor_pointer->y_velocity = D_global_asm_807535CC[D_global_asm_807FD584];
        extra_player_info_pointer->unk50 = 0;
        extra_player_info_pointer->unk3C = 0;
        extra_player_info_pointer->unk58 = D_global_asm_80767CC0 - 0x1E;
        playSoundAtActorPosition(current_actor_pointer, 0x309, 0xFF, 0x7F, 0);
    }
}

void func_global_asm_806EAE04(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if ((vehicle->control_state == 0) && (D_global_asm_807FD610[cc_player_index].unk2C & B_BUTTON)) {
        vehicle->control_state = 1;
    }
}

void func_global_asm_806EAE60(void) {
    // Joystick range check
    if ((D_global_asm_807FD610[cc_player_index].unk2E >= 41) || (D_global_asm_807FD610[cc_player_index].unk2F >= 41)) {
        if (extra_player_info_pointer->unk108 != 0.0f) {
            extra_player_info_pointer->unk108 = 0.0f;
            extra_player_info_pointer->unk200 = MAX(1, extra_player_info_pointer->unk200 - 5);
            return;
        }
    }
    // Joystick range check
    if (((D_global_asm_807FD610[cc_player_index].unk2E < -40) || (D_global_asm_807FD610[cc_player_index].unk2F < -40)) && extra_player_info_pointer->unk108 == 0.0f) {
        extra_player_info_pointer->unk108 = 1.0f;
        extra_player_info_pointer->unk200 = MAX(1, extra_player_info_pointer->unk200 - 5);
    }
}

void func_global_asm_806EAF6C(void) {
    Actor *vehicle = extra_player_info_pointer->vehicle_actor_pointer;
    if (D_global_asm_807FD610[cc_player_index].unk2C & A_BUTTON) {
        switch (vehicle->control_state) {
            case 2:
                vehicle->control_state = 4;
                vehicle->control_state_progress = 0;
                break;
            case 5:
                vehicle->control_state_progress++;
                break;
            }
    }
}

void func_global_asm_806EAFEC(void) {

}

void func_global_asm_806EAFF4(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2A & Z_TRIG) {
        current_actor_pointer->y_velocity = 0.0f;
    } else {
        current_actor_pointer->y_velocity = 120.0f;
    }
}

void func_global_asm_806EB058(void) {
    if (D_global_asm_807FD610[cc_player_index].unk2A & (U_CBUTTONS | D_CBUTTONS)) {
        current_actor_pointer->y_velocity = 0.0f;
    } else {
        current_actor_pointer->y_velocity = -120.0f;
    }
}
