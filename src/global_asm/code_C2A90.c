#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_807F5D10;
extern f32 D_8075BEA8;
extern f64 D_8075BEB0;
extern u8 D_807506C0[];
extern s32 D_8071FBA0;

void func_8072B324(Actor*, s32);
void func_80729B00(void);
void func_806319C4(Actor*, s32);

void func_80714C08(s32*, f32, Actor*, s32, s32);
void func_80724E48(u8);
void func_806F09F0(Actor*, u16);

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BDD90.s")

extern f32 D_8075BBE4;
void func_8061C600(Actor*, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);

void func_806BDEC8(void) {
    PlayerAdditionalActorData *PaaD = player_pointer->PaaD;

    if (func_806BDD90() == 1) {
        current_actor_pointer->control_state = 0x12;
        current_actor_pointer->control_state_progress = 0;
    }
    if (current_actor_pointer->control_state == 0x12) {
        switch (current_actor_pointer->control_state_progress) {
            case 0:
                current_actor_pointer->y_velocity = 150.0f;
                func_80614EBC(current_actor_pointer, 0x28E);
                func_8061C600(PaaD->unk104, current_actor_pointer, 4, 0xE77, 0xFA, 2, 0x32, 0x20, 0x3F, 0x4A, D_8075BBE4);
                D_807FDC90->unk2C = 0x32;
                current_actor_pointer->control_state_progress += 1;
                break;
            case 2:
                if (D_807FDC90->unk2C != 0) {
                    D_807FDC90->unk2C--;
                } else {
                    func_80614EBC(current_actor_pointer, 0x28F);
                    current_actor_pointer->control_state_progress++;
                    D_807FDC90->unk2C = 0x78;
                }
                break;
            case 3:
                if (D_807FDC90->unk2C != 0) {
                    D_807FDC90->unk2C--;
                } else if (!func_805FF0C8()) {
                    current_actor_pointer->control_state = 0;
                    current_actor_pointer->control_state_progress = 0;
                }
                break;
        }
    }
    func_8072881C(0, &D_807FDC90->unk28);
    func_806319C4(current_actor_pointer, 0);
}

// Doable lookin
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BE09C.s")

void func_806BE674(u8 arg0) {
    s16 i;
    for (i = 0; i < 0x10U; i++) {
        if (arg0) {
            func_8068A1CC(D_807506C0[i]);
        } else {
            func_8068A20C(D_807506C0[i]);
        }
    }
}

// Displaylist stuff, dl arg0, actor arg1?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BE6F0.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BE8BC.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BF218.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BF920.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BFA8C.s")

void func_806BFBB4() {
    func_8061421C(current_actor_pointer);
    func_806319C4(current_actor_pointer, 0);
    func_80614A64(current_actor_pointer);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806BFBF4.s")

void func_8072AB74(s32, f32, f32, s32, f32);
void func_80613C48(Actor*, s32, f32, f32);
void func_806F0C18(Actor*);

void func_806C10A0(u8 arg0, u16 arg1, s16 arg2) {
    f32 sp34;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806F0C18(current_actor_pointer);
        D_807FDC98->unk46 |= 0x200;
        func_8072B324(current_actor_pointer, 0);
    }
    func_80724A20();
    switch (current_actor_pointer->control_state) {
        case 5:
            func_8072AB74(0, 0.0f, 0.0f, 2, 0.0f);
            /* fallthrough */
        case 0:
            if (func_80629148()) {
                current_actor_pointer->control_state = 0x12;
                current_actor_pointer->control_state_progress = 0;
                return;
            }
            return;
        case 2:
            func_8072AB74(2, D_807FDC90->unkA, D_807FDC90->unkE, 0, 0.0f);
            func_8072D13C(2, 0);
            return;
        case 18:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_8070D8C0(current_actor_pointer, arg1, arg0);
                    func_80614EBC(current_actor_pointer, arg2);
                    current_actor_pointer->control_state_progress++;
                    return;
                case 2:
                    // TODO: Proper bitfield syntax
                    if (((s32)(current_actor_pointer->object_properties_bitfield << 6) >= 0)) {
                        func_80613C48(current_actor_pointer, 0xE4, 0.0f, 2.0f);
                        func_80677FA8(0xE1, 0x98);
                        func_8067B238(D_807FBB44, current_actor_pointer, 0.21f);
                        func_80671C0C(current_actor_pointer, 1, &D_807FBB44->x_position, &sp34, &D_807FBB44->z_position);
                        func_80614EBC(D_807FBB44, 0x298);
                        D_807FBB44->unk11C = current_actor_pointer;
                        current_actor_pointer->control_state_progress++;
                        return;
                    }
                    break;
                case 3:
                    current_actor_pointer->y_position += 0.5;
                    break;
            }
            break;
    }
}

void func_806C1300(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 1:
            current_actor_pointer->unk11C->object_properties_bitfield &= -5;
            current_actor_pointer->control_state_progress++;
            break;
        case 3:
            func_8061D4E4(D_807F5D10);
            current_actor_pointer->unk11C->control_state = 0x40;
            func_806782C0(current_actor_pointer);
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C13AC.s")

void func_806C151C(u16 arg0, u8 arg1, s16 tempFlagIndex) {
    f32 dx, dy, dz;
    s32 phi_a3;

    dx = player_pointer->x_position - current_actor_pointer->x_position;
    dy = player_pointer->y_position - current_actor_pointer->y_position;
    dz = player_pointer->z_position - current_actor_pointer->z_position;
    phi_a3 = FALSE;
    if (((dx * dx) + (dy * dy) + (dz * dz)) < D_8075BEA8) {
        phi_a3 = TRUE;
    }
    if ((phi_a3 & 0xFF) && !isFlagSet(tempFlagIndex, FLAG_TYPE_TEMPORARY)) {
        func_8070D8C0(current_actor_pointer, arg0, arg1);
        setFlag(tempFlagIndex, TRUE, FLAG_TYPE_TEMPORARY);
    }
}

void func_806C15E8() {
    D_807FDC98->unk46 |= 0x1000;
    current_actor_pointer->unk146 = 0;
    func_8072B324(current_actor_pointer, 0);
    current_actor_pointer->unkCC = 1;
}

void func_806C1640(void) {
    f64 temp_f0;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806C15E8();
        if (current_map == MAP_DK_RAP) {
            temp_f0 = D_8075BEB0;
            current_actor_pointer->animation_state->scale_x *= temp_f0;
            current_actor_pointer->animation_state->scale_y *= temp_f0;
            current_actor_pointer->animation_state->scale_z *= temp_f0;
        }
    }
    func_806BF920();
    // TODO: Bitfield syntax
    if (!(((s32)current_actor_pointer->object_properties_bitfield << 3) >= 0)) {
        func_806BFBF4(current_actor_pointer);
    }
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C1734.s")

void func_806C19F4(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_806C15E8();
        current_actor_pointer->ledge_info_pointer->unk14 = 180.0f;
        func_80724CA4(2, 1);
        // Note: This is read as u16 at 0x5A instead of u32 at 0x58
        func_806F09F0(current_actor_pointer, current_actor_pointer->unk58);
    }

    // TODO: Bitfield syntax
    if (((s32)current_actor_pointer->object_properties_bitfield * 8) < 0) {
        func_806BFBF4();
        if (current_actor_pointer->animation_state->unk0->unk10 == 0x1A4) {
            func_807149B8(1);
            func_807149C8(0x96, 0xFF, 0xFF, 0xFF);
            func_80714C08(&D_8071FBA0, 0.7f, current_actor_pointer, 5, 0);
        }
        func_80724E48(D_807FDC94 == player_pointer ? 5 : 7);
    } else {
        func_806C10A0(2, 6, 0x3D9);
        func_80724E48(0);
        func_806C151C(6, 1, 6); // Aztec: Caged Lanky Text Cleared
    }
    func_806319C4(current_actor_pointer, 0);
}

// Doable, need to untangle some switch cases/labels probably
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C1B50.s")

extern s32 D_807035C4; // TODO: Datatype

void func_806C1CCC(void) {
    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->terminal_velocity = -2000.0f;
        current_actor_pointer->y_acceleration = -200.0f;
        func_806C15E8();
        func_80724CA4(2, 1);
        if (current_map == MAP_DK_RAP) {
            func_80613194(current_actor_pointer, 0xE);
        }
        func_806F09F0(current_actor_pointer, current_actor_pointer->unk58);
    }
    // TODO: Better way to do this
    if (((s32) current_actor_pointer->object_properties_bitfield * 8) < 0) {
        func_806BFBF4();
        if (current_actor_pointer->object_properties_bitfield & 4) {
            if ((current_actor_pointer->animation_state->unk0->unk10 == 0x2C4) && (current_actor_pointer->animation_state->unk0->unk4 > 25.0f)) {
                func_8068C350(&D_807035C4, 0, 3);
            }
        }
        func_80724E48(D_807FDC94 == player_pointer ? 5 : 7);
    } else {
        func_806C10A0(2, 5, 0x3DA);
        func_80724E48(0);
        func_806C151C(5, 1, 0xF); // Factory: Caged Chunky Text Cleared
    }
    func_806319C4(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C1E44.s")

extern s32 D_80720B58; // TODO: Datatype

extern s32 D_807197B4; // TODO: Datatype
extern s32 D_8071FF58; // TODO: Datatype
extern s32 D_8071F078; // TODO: Datatype

void func_806883F4(Actor*, s32, s32, f32);

/*
// TODO: Not sure what's going on here
// It keeps messing a0 and s0 up around the function calls
// Also, our stack is 0x10 too small
void func_806C1E44(void) {
    s32 phi_s0;

    func_80729B00();
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_8068842C(current_actor_pointer, 0, 1);
        func_80688460(current_actor_pointer, 0, 1);
        switch (current_map) {
            case MAP_AZTEC_LLAMA_TEMPLE:
                current_actor_pointer->unk130 = 0xFF;
                current_actor_pointer->unk131 = 0xFF;
                // Aztec: Water Cooled Down
                if (!isFlagSet(0x4C, FLAG_TYPE_PERMANENT)) {
                    func_806883F4(current_actor_pointer, 0, 1, 0);
                    func_80614EBC(current_actor_pointer, 0x2BD);
                    current_actor_pointer->control_state = 0;
                    current_actor_pointer->control_state_progress = 0;
                } else {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                    current_actor_pointer->control_state_progress = 4;
                }
                break;
            case MAP_AZTEC:
                func_806883F4(current_actor_pointer, 0, 0, 0);
                current_actor_pointer->control_state = 5;
                current_actor_pointer->control_state_progress = 0;
                break;
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            func_80724A20();
            switch (current_actor_pointer->control_state_progress) {
                case 1:
                    D_807FDC90->unk2C = 3;
                    current_actor_pointer->control_state_progress = 2;
                    // Fallthrough
                case 2:
                    if (!(object_timer & 7)) {
                        if (D_807FDC90->unk2C != 0) {
                            D_807FDC90->unk2C--;
                            if (D_807FDC90->unk2C == 0) {
                                current_actor_pointer->control_state_progress = 0;
                            }
                            func_80714998(2);
                            func_807149B8(1);
                            func_807149FC(0x28);
                            func_8071498C(&D_807197B4);
                            func_80714C08(&D_8071FF58, 0.05f, current_actor_pointer, 1, 0);
                        }
                    }
                    break;
            }
            break;
        case 39:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_806883F4(current_actor_pointer, 0, 0, 0);
                    func_80614EBC(current_actor_pointer, 0x2BE);
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 3:
                    for (phi_s0 = 0; phi_s0 < 0xA; phi_s0++) {
                        func_807149B8(1);
                        func_807149FC(0x28);
                        func_8071498C(&D_8071F078);
                        func_80714950(current_actor_pointer->y_rotation);
                        func_80714C08(&D_80720B58, 0.7f, current_actor_pointer, 1, 0);
                    }
                    current_actor_pointer->control_state_progress++;
            }
            break;
        case 5:
            func_80724A20();
            func_806C151C(0xA, 1, 7);
            func_806C13AC(4, 0x4F1, 0x4F7, 0x4F7, 0x4F7);
            if (func_80629148()) {
                current_actor_pointer->control_state = 0x12;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 18:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_80614EBC(current_actor_pointer, 0x2BF);
                    func_806883F4(current_actor_pointer, 0, 2, 0);
                    func_8072B324(current_actor_pointer, D_807FDC9C->unkC);
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 2:
                    func_8072AB74(2, D_807FDC90->unkA, D_807FDC90->unkE, 0, 0.0f);
                    func_8072D13C(2, 0);
                    break;
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

// Doable and quite interesting, but it's a big project and may require some struct definitions
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C226C.s")

extern f64 D_8075BEB8;

void func_80684550(Actor*, s32, f32);
void func_80604CBC(Actor*, s32, s32, s32, s32, s32, f32, s32); // TODO: Are the datatypes correct?

void func_806C27DC(void) {
    f32 temp_f20;

    temp_f20 = current_actor_pointer->animation_state->scale_y / D_8075BEB8;
    func_80604CBC(current_actor_pointer, 0x114, 0x50, 0, 0, 0xFF, 0.5f, 0);
    if (object_timer & 1) {
        func_80684550(current_actor_pointer, 1, temp_f20);
        func_80684550(current_actor_pointer, 3, temp_f20);
    } else {
        func_80684550(current_actor_pointer, 2, temp_f20);
        func_80684550(current_actor_pointer, 4, temp_f20);
    }
}

// Doable, floaty loop
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C28B8.s")

extern f64 D_8075BEC0;
extern f64 D_8075BEC8;
extern f64 D_8075BED0;

void func_806852C4(f32, f32, f32, s32);

/*
// TODO: Float and stack nonsense
void func_806C28B8(void) {
    f64 temp_f20;
    f32 sp78;
    f64 temp_f22;
    f32 sp74;
    s32 sp70;
    f32 phi_f2;
    s16 phi_s0;
    f64 phi_f0;

    phi_f2 = current_actor_pointer->animation_state->unk0->unk4;
    if (phi_f2 > 83.0f) {
        func_806C27DC();
        phi_f2 = current_actor_pointer->animation_state->unk0->unk4;
    }
    if ((phi_f2 > 2.0f) && (phi_f2 < 90.0f)) {
        if ((object_timer % 6U) == 0) {
            temp_f20 = MIN(1, phi_f2 / D_8075BEC0) * D_8075BEC8;
            temp_f22 = D_8075BED0;
            for (phi_s0 = 1; phi_s0 < 5; phi_s0++) {
                func_80671C0C(current_actor_pointer, phi_s0, &sp78, &sp74, &sp70);
                phi_f0 = MAX(temp_f22, temp_f20);
                func_806852C4(phi_f0, sp78, sp74 + 3.0f, sp70);
            }
        }
    }
}
*/

extern s32 D_80717D84;
extern f64 D_8075BED8;

void func_806C2A64(u8 arg0, u8 arg1, u8 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, f32 arg7) {
    func_807149A8(1000);
    func_80714998(0xFF);
    func_80714944(((rand() >> 0xF) % 32767) % 11);
    func_807149C8(arg0, arg1, arg2, 0xFF);
    func_8071498C(&D_80717D84);
    func_80714950(2);
    func_80714CC0(arg6, arg7 * D_8075BED8, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C2B2C.s")

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
} Struct80747B00;

extern Struct80747B00 D_80747B00[];
extern f64 D_8075BEE0;

/*
void func_806C2B2C(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 temp_f20;
    f32 temp_f24;
    s16 i;
    Struct80747B00 *temp_s0;

    temp_f24 = (current_actor_pointer->animation_state->scale_y / D_8075BEE0) / 1.5;
    while (arg1 >= arg0) {
        for (i = 0; i < 3.0; i++) {
            temp_s0 = &D_80747B00[arg2];
            temp_f20 = i / 3.0;
            func_80671C0C(current_actor_pointer, arg0, &spA8, &spA4, &spA0);
            if (arg0 < arg1) {
                func_80671C0C(current_actor_pointer, arg0 + 1, &sp9C, &sp98, &sp94);
            } else {
                func_80671C0C(current_actor_pointer, arg0, &sp9C, &sp98, &sp94);
            }
            func_806C2A64(spA0, temp_s0->unk0, temp_s0->unk1, temp_s0->unk2, ((sp9C - spA8) * temp_f20) + spA8, ((sp98 - spA4) * temp_f20) + spA4, ((sp94 - spA0) * temp_f20) + spA0, arg3);
        }
    }
}
*/

extern s32 D_8071FFA0;

void func_806C2D7C() {
    func_806C2B2C(1, 0xB, 6, &D_8071FFA0);
    func_806C2B2C(0x20, 0x30, 6, &D_8071FFA0);
    func_806C2B2C(0xC, 0x16, 2, &D_8071FFA0);
    func_806C2B2C(0x17, 0x1F, 2, &D_8071FFA0);
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C2DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_806C3A8C.s")
