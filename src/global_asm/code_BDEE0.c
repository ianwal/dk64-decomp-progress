#include <ultra64.h>
#include "functions.h"


extern u8 D_global_asm_807FBD70;
extern s32 D_global_asm_8071FB34;
extern s32 D_global_asm_8074E880[];
extern u8 D_global_asm_80750628[];

void func_global_asm_80612BC0(Mtx*, f32);
void func_global_asm_80612C30(Mtx*, f32);
void func_global_asm_80611A70(f32, f32, f32*, f32*);
void func_global_asm_8072AB74(s32, f32, f32, s32, f32);

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806B91E0.s")

void func_global_asm_806B9CB0() {
    func_global_asm_80729B00();
    func_global_asm_806319C4(current_actor_pointer, 0);
}

void func_global_asm_806B9CE0(u8 arg0, s8 arg1) {
    switch (arg0) {
        case 0:
            func_global_asm_8071498C(&func_global_asm_8071720C);
            break;
        case 1:
            func_global_asm_80714950(-0x258);
            func_global_asm_8071498C(&func_global_asm_80717D4C);
            break;
    }
    func_global_asm_807149B8(1);
    func_global_asm_80714CC0(
        D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3],
        (((rand() >> 0xF) % 256) * 0.001953125) + 0.5,
        ((rand() >> 0xF) % 6) + (current_actor_pointer->x_position - 3.0f),
        current_actor_pointer->y_position + arg1,
        ((rand() >> 0xF) % 6) + (current_actor_pointer->z_position - 3.0f)
    );
}

s32 func_global_asm_806B9EB4(u8 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Mtx sp80;
    Mtx sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 temp;
    f32 sp2C;

    if (D_global_asm_80750628[arg0]) {
        func_global_asm_80671C0C(D_global_asm_807FDCA0->unk1C, D_global_asm_80750628[arg0], &sp3C, &sp38, &sp34);
        func_global_asm_80611A70(arg2, arg4, &sp3C, &sp34);
        sp2C = func_global_asm_80611BB4(sp3C - arg2, sp34 - arg4);
        guTranslateF(&sp80, 0.0f, -arg1, 0.0f);
        func_global_asm_80612C30(&sp40, (current_actor_pointer->y_rotation * 360) / 4096);
        guMtxCatF(&sp80, &sp40, &sp80);
        func_global_asm_80612BC0(&sp40, -90.0f);
        guMtxCatF(&sp80, &sp40, &sp80);
        guAlignF(&sp40, (sp2C * 57.29577637f) + 180.0f, sp3C - arg2, sp38 - arg3, sp34 - arg4);
        guMtxCatF(&sp80, &sp40, &sp80);
        guTranslateF(&sp40, 0.0f, arg1, 0.0f);
        guMtxCatF(&sp80, &sp40, &sp80);
        guScaleF(&sp40,
                 current_actor_pointer->animation_state->scale_x,
                 current_actor_pointer->animation_state->scale_y,
                 current_actor_pointer->animation_state->scale_z);
        guMtxCatF(&sp80, &sp40, &sp80);
        guTranslateF(&sp40,
                     current_actor_pointer->x_position,
                     current_actor_pointer->y_position,
                     current_actor_pointer->z_position);
        guMtxCatF(&sp80, &sp40, &current_actor_pointer->unkC);
        return TRUE;
    }
    return FALSE;
}

void func_global_asm_806BA130(void) {
    current_actor_pointer->interactable = 2;
    current_actor_pointer->control_state = 0x23;
    current_actor_pointer->control_state_progress = 0;
    current_actor_pointer->health = 1;
    current_actor_pointer->unk132 = 1;
    D_global_asm_807FDC90->unk4 = player_pointer;
    func_global_asm_80614EBC(current_actor_pointer, D_global_asm_807FDC98->unk2A);
    current_actor_pointer->y_rotation = (((rand() >> 0xF) % 1024) + player_pointer->y_rotation) - 0x200;
    current_actor_pointer->unkB8 = ((rand() >> 0xF) % 100) + 50;
    current_actor_pointer->y_velocity = ((rand() >> 0xF) % 150) + 100;
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BA240.s")

/*
s32 func_global_asm_806BA240(u8 arg0, s16 arg1) {
    Actor178 *sp54;
    Actor *temp_s0;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s32 temp_t5; // TODO: Might be u8/s8
    f64 temp_f0;

    sp54 = current_actor_pointer->unk178;
    temp_s0 = D_global_asm_807FDCA0->unk1C;
    if ((temp_s0 != NULL) && (temp_s0->control_state == 0x23) && (D_global_asm_807FDCA0->unk20 < 0xA)) {
        if ((current_actor_pointer->control_state != 0x15) && (current_actor_pointer->control_state != 0x17)) {
            current_actor_pointer->interactable = 0x80;
            current_actor_pointer->control_state = 0x15;
            current_actor_pointer->control_state_progress = 0;
            func_global_asm_80614EBC(current_actor_pointer, 0);
            current_actor_pointer->unk132 = 2;
            sp54->unk6 = current_actor_pointer->x_position;
            sp54->unk8 = current_actor_pointer->z_position;
        }
    }
    if ((current_actor_pointer->control_state == 0x15) && ((temp_s0 == NULL) || (temp_s0->control_state != 0x23))) {
        func_global_asm_806BA130();
    }
    if (current_actor_pointer->control_state == 0x15) {
        temp_t5 = D_global_asm_807FDC9C->unkA_u8[0];
        if ((temp_t5 == 5) || (temp_t5 == 7)) {
            if (((temp_s0->animation_state->unk64 == 0x21E) || (temp_s0->animation_state->unk64 == 0x21F)) && ((temp_s0->animation_state->unk0->unk4 >= 4.0f)) && (temp_s0->animation_state->unk0->unk4 <= 12.0f)) {
                current_actor_pointer->unk132 = 4;
            } else {
                current_actor_pointer->unk132 = 2;
            }
        }
        if (temp_t5 == 1) {
            current_actor_pointer->unk132 = 8;
        }
        if (current_actor_pointer->unkF0 != 0) {
            current_actor_pointer->unkF0--;
        }
        if (temp_s0->control_state_progress != 0) {
            if ((temp_s0->control_state_progress == 1) && (D_global_asm_807FBD70 == 2) && (func_global_asm_8072DCF4(temp_s0, player_pointer, 8000) != 0)) {
                if (character_change_array->unk2C0 == 1) {
                    func_global_asm_806EB0C0(0x32, current_actor_pointer, 0);
                } else {
                    func_global_asm_80614EBC(temp_s0, (((rand() >> 0xF) % 1000) >= 0x1F5) ? 0x21F : 0x21E);
                    temp_s0->control_state_progress = 2;
                }
            } else if (D_global_asm_807FBD70 == 4) {
                D_global_asm_807FDC90->unk16 = D_global_asm_807FDC94->animation_state->unk0->unk10;
                current_actor_pointer->object_properties_bitfield |= 0x20000000;
                if (current_actor_pointer->unkF0 == 0) {
                    current_actor_pointer->unkF0 = 0x28;
                    func_global_asm_80714CC0(&D_global_asm_8071FB34, 2.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                    playSound(0x1CA, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    func_global_asm_80614EBC(temp_s0, 0x220);
                    temp_s0->control_state_progress = 2;
                    temp_s0->health--;
                    if (temp_s0->health == 0) {
                        temp_s0->control_state = 0x37;
                        temp_s0->control_state_progress = 0;
                    }
                }
            }
        }
        D_global_asm_807FDCA0->unk20++;
        func_global_asm_80671C0C(temp_s0, temp_t5, &sp4C, &sp48, &sp44);
        if (D_global_asm_807FDC90->unk1A & 0x80) {
            if (!(D_global_asm_807FDC90->unk1C & 0x80)) {
                current_actor_pointer->y_velocity = 300.0f;
            }
            if (current_actor_pointer->y_velocity > 0.0f) {
                return 0;
            }
            current_actor_pointer->noclip_byte = 0x24;
            if (arg1 != 0) {
                func_global_asm_80613C48(current_actor_pointer, arg1, 0.0f, 4.0f);
            }
            temp_f0 = 0.1;
            sp54->unk0 += (-sp54->unk0 * temp_f0);
            sp54->unk2 += (-sp54->unk2 * temp_f0);
            if (temp_t5 < 0xB) {
                current_actor_pointer->y_rotation = temp_s0->y_rotation;
            }
            current_actor_pointer->x_position = sp4C;
            current_actor_pointer->z_position = sp44;
            current_actor_pointer->y_position = sp48;
            if (func_global_asm_806B9EB4(temp_t5, arg0, sp4C, sp48, sp44) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
*/

// Jumptable, doable, use new context for function signatures
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BA76C.s")

void func_global_asm_806BA8C8(void) {
    switch (current_actor_pointer->control_state) {
        case 0x2:
        case 0x3:
            func_global_asm_8072D13C(current_actor_pointer->control_state, 0);
        default:
            func_global_asm_8072C918(10000, 0, 0);
            break;
        case 0x15:
        case 0x37:
        case 0x40:
            break;
    }
}

// Huge, float matrix stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BA93C.s")

void func_global_asm_806BB32C(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk16A = 0xFA;
        current_actor_pointer->unk16B = 0xFA;
        current_actor_pointer->unk16C = 0xFA;
    }
    if (current_actor_pointer->control_state == 0x17) {
        func_global_asm_806B9CE0(0, 0);
    }
    if (D_global_asm_807FDC90->unk2E != 0) {
        D_global_asm_807FDC90->unk2E--;
        current_actor_pointer->unkFC = 0;
        if ((D_global_asm_807FDC90->unk2E == 0) && (D_global_asm_807FDC94 == player_pointer)) {
            current_actor_pointer->noclip_byte = 0x24;
        }
    }
}

// doable, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BB400.s")

/*
// TODO: Very close, 1 extra instruction related to default case in the second switch
void func_global_asm_806BB400(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806D0430(0.5249999762f);
        player_pointer->object_properties_bitfield |= 0x400;
        player_pointer->draw_distance = 0x7D0;
        current_actor_pointer->object_properties_bitfield &= -5;
        func_global_asm_807248B0(current_actor_pointer, 1.0f);
        current_actor_pointer->unk15F = 0;
        current_actor_pointer->y_rotation = func_global_asm_80665DE0(player_pointer->x_position, player_pointer->z_position, current_actor_pointer->x_position, current_actor_pointer->z_position);
        func_global_asm_80614EBC(current_actor_pointer, 0x21B);
        D_global_asm_807FDC98->unk46 |= 8;
        D_global_asm_807FDC98->unk28 = 0x21C;
    }
    switch (current_actor_pointer->control_state) {
        case 0x4:
            current_actor_pointer->control_state = 0x23;
            current_actor_pointer->control_state_progress = 0;
            // Fallthrough
        case 0x23:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8072AB74(0x37, 0.0f, 0.0f, 0x202, 0.0f);
                    break;
                default:
                    current_actor_pointer->control_state_progress = 1;
                    // break;
                case 1:
                    if (current_actor_pointer->animation_state->unk64 != 0x21C) {
                        func_global_asm_80614EBC(current_actor_pointer, 0x21C);
                    }
                    func_global_asm_8072AB74(current_actor_pointer->control_state, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->z_position, 0, 0.0f);
                    break;
                case 2:
                    break;
            }
            break;
        case 0x37:
            func_global_asm_806D0430(0.3000000119f);
            current_actor_pointer->control_state = 0x40;
            break;
    }
    D_global_asm_807FDCA0->unk20 = 0;
    func_global_asm_806319C4(current_actor_pointer, 0);
}
*/

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
    u16 unk44;
    u16 unk46; // Used
} AAD_global_asm_806BB604_unk0;

typedef struct {
    AAD_global_asm_806BB604_unk0 *unk0;
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
    s16 unk2C;
    s16 unk2E; // Used
} AAD_global_asm_806BB604;

s32 func_global_asm_806BB604(u8 arg0, s16 arg1, s16 arg2, s32 arg3) {
    AAD_global_asm_806BB604 *aaD;

    if (D_global_asm_807FDC90->unk2C != 0) {
        func_global_asm_806B9CE0(0, 0xA);
        D_global_asm_807FDC90->unk2C -= 1;
        return 0;
    }
    if (func_global_asm_807271F4(arg0, ((rand() >> 0xF) % 10) + (current_actor_pointer->x_position - 5.0f), current_actor_pointer->y_position + 5.0f, ((rand() >> 0xF) % 10) + (current_actor_pointer->z_position - 5.0f), (((rand() >> 0xF) % 1024) + current_actor_pointer->y_rotation) - 0x200, arg1, arg2) != 0) {
        D_global_asm_807FBB44->control_state = 0x17;
        D_global_asm_807FBB44->control_state_progress = 0;
        aaD = D_global_asm_807FBB44->additional_actor_data;
        aaD->unk2E = 0x1E;
        if (arg3 != 0) {
            aaD->unk0->unk46 &= 0xFFF7;
            aaD->unk4 = arg3;
        }
        D_global_asm_807FBB44->noclip_byte = 1;
        D_global_asm_807FBB44->draw_distance = 0x3E8;
        return 1;
    }
    return 0;
}

void func_global_asm_806BB81C() {
    func_global_asm_80604CBC(current_actor_pointer, 0x11F, 0, 0, 0, 0xFF, 1.0f, 0);
    playSong(0x3B, 1.0f);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BDEE0/func_global_asm_806BB874.s")

void func_global_asm_806BC080() {
    func_global_asm_806BB32C();
    if ((D_global_asm_807FDC9C->unkA_u8[0] == 0) || (func_global_asm_806BA240(0, 0x446) == 0)) {
        func_global_asm_806AD260(0x2ED, 1, 0);
        func_global_asm_806319C4(current_actor_pointer, 0);
    }
}

void func_global_asm_806BC0E4() {
    func_global_asm_806BB32C();
    if ((D_global_asm_807FDC9C->unkA_u8[0] == 0) || (func_global_asm_806BA240(0x32, 0x44E) == 0)) {
        func_global_asm_806AD260(0x2EC, 1, 0);
        func_global_asm_806319C4(current_actor_pointer, 0);
    }
}

void func_global_asm_806BC148() {
    func_global_asm_806BB32C();
    if ((D_global_asm_807FDC9C->unkA_u8[0] == 0) || (func_global_asm_806BA240(0x14, 0x44A) == 0)) {
        func_global_asm_806AD260(0x2EE, 1, 0);
        func_global_asm_806319C4(current_actor_pointer, 0);
    }
}

void func_global_asm_806BC1AC() {
    func_global_asm_806BB32C();
    func_global_asm_806BA93C(0x24, 0x14, 0x1E);
}
