#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_8071FB08; // TODO: Proper datatype
extern s32 D_global_asm_8071FBA0;
extern s32 D_global_asm_8071FC40; // TODO: Proper datatype
extern s32 D_global_asm_8071FF58; // TODO: Datatype
extern s32 D_global_asm_8071FFA0;

extern s32 D_global_asm_807200D4; // TODO: Proper datatype
extern s32 D_global_asm_80720B58; // TODO: Datatype
extern s16 D_global_asm_80750AC8;

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
} Struct80747B00;
extern Struct80747B00 D_global_asm_80747B00[];

extern f32 D_global_asm_807502F4;
extern u8 D_global_asm_807506C0[];

extern s16 D_global_asm_807F62B4;
extern u8 D_global_asm_807FBDC4;
extern s32 D_global_asm_807FBDC8[];
extern u16 D_global_asm_807FC930[];

void func_global_asm_8061C518(Actor*, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_global_asm_8061C600(Actor*, Actor*, s32, s32, s32, s32, s32, s32, s32, s32, f32);
void func_global_asm_806BF920(void);
void func_global_asm_806F91B4(s32, u8, s32);
int func_global_asm_807035C4(); // TODO: Signature
void func_global_asm_80718BF4(void);
int func_global_asm_807197B4(); // TODO: Signature
int func_global_asm_8071C818(); // TODO: Signature
void func_global_asm_8072AB74(s32, f32, f32, s32, f32);

u8 func_global_asm_806BDD90(void) {
    s16 i;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        if (func_global_asm_805FF0C8() != 0) {
            current_actor_pointer->control_state = 0x40;
        } else {
            current_actor_pointer->unk130 = 0x3C;
            current_actor_pointer->unk131 = 0x3C;
            current_actor_pointer->draw_distance = 0x3E8;
            func_global_asm_80724CA4(2, 1);
            D_global_asm_807FDC90->unk30 = current_actor_pointer->animation_state->scale_y;
            current_actor_pointer->y_acceleration = current_actor_pointer->y_acceleration / 1.5;
        }
    }
    func_global_asm_80729E6C();
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 0.0f);
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if (D_global_asm_807FBB70.unk258[i] == 3) {
            return D_global_asm_807FBB70.unk278[i]->unk2;
        }
    }
    return 0;
}

void func_global_asm_806BDEC8(void) {
    PlayerAdditionalActorData *PaaD = player_pointer->PaaD;

    if (func_global_asm_806BDD90() == 1) {
        current_actor_pointer->control_state = 0x12;
        current_actor_pointer->control_state_progress = 0;
    }
    if (current_actor_pointer->control_state == 0x12) {
        switch (current_actor_pointer->control_state_progress) {
            case 0:
                current_actor_pointer->y_velocity = 150.0f;
                func_global_asm_80614EBC(current_actor_pointer, 0x28E);
                func_global_asm_8061C600(PaaD->unk104, current_actor_pointer, 4, 0xE77, 0xFA, 2, 0x32, 0x20, 0x3F, 0x4A, 0.1599999964f);
                D_global_asm_807FDC90->unk2C = 0x32;
                current_actor_pointer->control_state_progress += 1;
                break;
            case 2:
                if (D_global_asm_807FDC90->unk2C != 0) {
                    D_global_asm_807FDC90->unk2C--;
                } else {
                    func_global_asm_80614EBC(current_actor_pointer, 0x28F);
                    current_actor_pointer->control_state_progress++;
                    D_global_asm_807FDC90->unk2C = 0x78;
                }
                break;
            case 3:
                if (D_global_asm_807FDC90->unk2C != 0) {
                    D_global_asm_807FDC90->unk2C--;
                } else if (!func_global_asm_805FF0C8()) {
                    current_actor_pointer->control_state = 0;
                    current_actor_pointer->control_state_progress = 0;
                }
                break;
        }
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806BE09C(void) {
    PlayerAdditionalActorData *sp4C;
    u8 temp;
    u8 temp2;
    u8 levelIndex;
    f32 sp44;
    f32 temp_f2;
    CharacterProgress *sp3C;
    f32 sp40;
    s32 i;
    s32 count = 0;

    sp4C = player_pointer->additional_actor_data;
    levelIndex = getLevelIndex(D_global_asm_8076A0AB, 0);
    sp44 = D_global_asm_807FC930[levelIndex] / (f32)D_global_asm_807446C0[levelIndex];
    if (func_global_asm_806BDD90() == 1) {
        D_global_asm_807FDC90->unk2C = func_global_asm_806F8AD4(0, 0);
        if (D_global_asm_807FDC90->unk2C != 0) {
            current_actor_pointer->control_state = 0x12;
            current_actor_pointer->control_state_progress = 0;
            D_global_asm_807FDC90->unk2E = 0x32;
            func_global_asm_80614EBC(current_actor_pointer, 0x28A);
            func_global_asm_8061C518(sp4C->unk104, player_pointer, 4, 0x990, 0x5A, -0x2E, 0x3C, 0xA, 0x20, 0, 0.3000000119f);
            player_pointer->y_rotation = func_global_asm_80665DE0(current_actor_pointer->x_position, current_actor_pointer->z_position, player_pointer->x_position, player_pointer->z_position);
            player_pointer->unkEE = player_pointer->y_rotation;
        }
    }
    func_global_asm_80724E48(0);
    if (sp44 > 1.0f) {
        sp44 = 1.0f;
    }
    temp_f2 = D_global_asm_807FDC90->unk30 + ((0.44 - D_global_asm_807FDC90->unk30) * sp44);
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_807248B0(current_actor_pointer, temp_f2);
    }
    switch (current_actor_pointer->control_state) {
        case 0x12:
            func_global_asm_807248B0(current_actor_pointer, ((temp_f2 - current_actor_pointer->animation_state->scale_x) * 0.1) + current_actor_pointer->animation_state->scale_x);
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    if (D_global_asm_807FDC90->unk2E != 0) {
                        D_global_asm_807FDC90->unk2E--;
                        if (D_global_asm_807FDC90->unk2E == 0) {
                            func_global_asm_8061C518(sp4C->unk104, current_actor_pointer, 4, 0x305, 0x14A, 3, 0x32, 0x7F, 0x5A, 0, 0.02999999933f);
                        }
                    }
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        if (!(object_timer & 3)) {
                            sp3C = &D_global_asm_807FC950->character_progress[*current_character_index];
                            D_global_asm_807FDC90->unk2C--;
                            func_global_asm_806F91B4(0, 0, -1);
                            sp3C->coloured_bananas_fed_to_tns[levelIndex]++;
                            for (i = 0; i < 5; i++) { count += D_global_asm_807FC950[0].character_progress[i].coloured_bananas_fed_to_tns[levelIndex]; }
                            if (count >= D_global_asm_807446C0[levelIndex]) {
                                D_global_asm_807FDC90->unk2C = 0;
                                func_global_asm_806F8D58(0, 0);
                            }
                            func_global_asm_8071498C(&func_global_asm_8071D0F0);
                            func_global_asm_807149FC(-1);
                            func_global_asm_807149B8(1);
                            func_global_asm_80714950(current_actor_pointer);
                            func_global_asm_80714C08(func_global_asm_806FACE8(0), 0.3f, player_pointer, 4, 0);
                        }
                    } else if (D_global_asm_807FDC90->unk2E == 0) {
                        D_global_asm_807FDC90->unk2C = 0x1E;
                        current_actor_pointer->control_state_progress = 1;
                    }
                    break;
                case 1:
                    if (D_global_asm_807FDC90->unk2C != 0) {
                        D_global_asm_807FDC90->unk2C--;
                    } else {
                        func_global_asm_80614EBC(current_actor_pointer, 0x28B);
                        current_actor_pointer->control_state = 0x27;
                        current_actor_pointer->control_state_progress = 0;
                    }
                    break;
            }
            break;
        case 0x27:
            if (current_actor_pointer->control_state_progress == 1) {
                func_global_asm_80685520(4.0f, 1, current_actor_pointer->x_position, current_actor_pointer->y_position + 5.0f, current_actor_pointer->z_position);
                current_actor_pointer->control_state = 0x28;
                current_actor_pointer->control_state_progress = 0;
                D_global_asm_807FDC90->unk2C = 0x3C;
            }
            break;
        case 0x28:
            D_global_asm_807FDC90->unk2C -= 1;
            if (D_global_asm_807FDC90->unk2C == 0) {
                current_actor_pointer->control_state = 0;
                current_actor_pointer->control_state_progress = 0;
                D_global_asm_807FDC90->unk2E = 0;
            }
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806BE674(u8 arg0) {
    s16 i;
    for (i = 0; i < 0x10U; i++) {
        if (arg0) {
            func_global_asm_8068A1CC(D_global_asm_807506C0[i]);
        } else {
            func_global_asm_8068A20C(D_global_asm_807506C0[i]);
        }
    }
}

// Displaylist stuff, dl arg0, actor arg1?
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BE6F0.s")

/*
Gfx *func_global_asm_806BE6F0(Gfx *dl, Actor *arg1) {
    char sp4C[2];
    s16 sfx;
    u8 temp_t7;
    s32 var_s0;

    temp_t7 = (arg1->unk168 / 30);
    if (temp_t7 != 0) {
        if (temp_t7 >= 4) {
            var_s0 = 3;
        } else {
            var_s0 = temp_t7;
        }
        func_dk64_boot_800031E0(&sp4C, "%d", var_s0);
    } else {
        func_dk64_boot_800031E0(&sp4C, func_global_asm_8070E750(0x26, 9, 1));
    }
    if ((arg1->unk168 % 30) == 0) {
        if (temp_t7 != 0) {
            playSound(temp_t7 >= 2 ? 0x75 : 0x74, 0x7FFF, 64.0f, 1.0f, 0, 0x80);
        }
    }

    gSPDisplayList(dl++, &D_1000118);
    gDPPipeSync(dl++);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetColorImage(dl++, 7, G_IM_SIZ_32b, 4096, 0xFA000000);

    dl = func_global_asm_8070068C(dl);
    dl = func_global_asm_806FC530(dl, 1, (0x140 - func_global_asm_806FBD5C(1, &sp4C)) * 2, 0xAA, &sp4C, 1);
    if (arg1->unk168-- == 0) {
        arg1->control_state_progress++;
    }
    return dl;
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BE8BC.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BF218.s")

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BF920.s")

void func_global_asm_80613CA8(Actor*, s32, f32, f32);

void func_global_asm_806BFA8C(u16 arg0) {
    switch (arg0) {
        case 0xEA:
        case 0x23E:
        case 0x23F:
        case 0x240:
        case 0x4C7:
            current_actor_pointer->control_state_progress = 1;
            break;
        case 0x112:
            func_global_asm_806F0D68(current_actor_pointer);
            // fallthrough
        case 0x113:
        case 0x128:
        case 0x129:
        case 0x12A:
        case 0x12B:
        case 0x12C:
        case 0x12D:
        case 0x12E:
        case 0x12F:
        case 0x130:
            func_global_asm_806C7BAC(current_actor_pointer, 0);
            break;
        case 0x114:
            func_global_asm_806F0C18(current_actor_pointer);
            func_global_asm_806F10E8(current_actor_pointer);
            break;
        case 0x2CF:
            func_global_asm_80613214(current_actor_pointer);
            func_global_asm_80613CA8(current_actor_pointer, 0x2CF, 0, 0);
            break;
    }
}

void func_global_asm_806BFBB4() {
    func_global_asm_8061421C(current_actor_pointer);
    renderActor(current_actor_pointer, 0);
    func_global_asm_80614A64(current_actor_pointer);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806BFBF4.s")

void func_global_asm_806C10A0(u8 arg0, u16 arg1, s16 arg2) {
    f32 sp34;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806F0C18(current_actor_pointer);
        D_global_asm_807FDC98->unk46 |= 0x200;
        func_global_asm_8072B324(current_actor_pointer, 0);
    }
    func_global_asm_80724A20();
    switch (current_actor_pointer->control_state) {
        case 5:
            func_global_asm_8072AB74(0, 0.0f, 0.0f, 2, 0.0f);
            // fallthrough
        case 0:
            if (func_global_asm_80629148()) {
                current_actor_pointer->control_state = 0x12;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 2:
            func_global_asm_8072AB74(2, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
            func_global_asm_8072D13C(2, 0);
            break;
        case 18:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_8070D8C0(current_actor_pointer, arg1, arg0);
                    func_global_asm_80614EBC(current_actor_pointer, arg2);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 2:
                    // TODO: Proper bitfield syntax
                    if (((s32)(current_actor_pointer->object_properties_bitfield << 6) >= 0)) {
                        func_global_asm_80613C48(current_actor_pointer, 0xE4, 0.0f, 2.0f);
                        spawnActor(ACTOR_UNKNOWN_225, 0x98);
                        func_global_asm_8067B238(last_spawned_actor, current_actor_pointer, 0.21f);
                        func_global_asm_80671C0C(current_actor_pointer, 1, &last_spawned_actor->x_position, &sp34, &last_spawned_actor->z_position);
                        func_global_asm_80614EBC(last_spawned_actor, 0x298);
                        last_spawned_actor->unk11C = current_actor_pointer;
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 3:
                    current_actor_pointer->y_position += 0.5;
                    break;
            }
            break;
    }
}

void func_global_asm_806C1300(void) {
    switch (current_actor_pointer->control_state_progress) {
        case 1:
            current_actor_pointer->unk11C->object_properties_bitfield &= -5;
            current_actor_pointer->control_state_progress++;
            break;
        case 3:
            func_global_asm_8061D4E4(D_global_asm_807F5D10);
            current_actor_pointer->unk11C->control_state = 0x40;
            deleteActor(current_actor_pointer);
            break;
    }
    renderActor(current_actor_pointer, 0);
}

s16 func_global_asm_806CD9A0(Actor *, f32, f32, u8, s32);

void func_global_asm_806C13AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 temp_v0;

    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk6A |= 1;
        func_global_asm_8067ACB4(current_actor_pointer);
        current_actor_pointer->unkCC = 1;
    }
    temp_v0 = func_global_asm_806CD9A0(current_actor_pointer, current_actor_pointer->unkB8, D_global_asm_807FDC90->unk26, D_global_asm_807FDC90->unk34, arg0);
    if (temp_v0 != D_global_asm_807FDC90->unk34) {
        switch (temp_v0) {
            case 0:
            case 1:
            case 2:
                func_global_asm_80613C48(current_actor_pointer, arg1, 0.0f, 6.0f);
                break;
            case 3:
                func_global_asm_80613C48(current_actor_pointer, arg2, 0.0f, 6.0f);
                break;
            case 4:
                func_global_asm_80613C48(current_actor_pointer, arg3, 0.0f, 6.0f);
                break;
            case 5:
                func_global_asm_80613C48(current_actor_pointer, arg4, 0.0f, 6.0f);
                break;
        }
        D_global_asm_807FDC90->unk34 = temp_v0;
    }
}

void func_global_asm_806C151C(u16 arg0, u8 arg1, s16 tempFlagIndex) {
    f32 dx, dy, dz;
    s32 phi_a3;

    dx = player_pointer->x_position - current_actor_pointer->x_position;
    dy = player_pointer->y_position - current_actor_pointer->y_position;
    dz = player_pointer->z_position - current_actor_pointer->z_position;
    phi_a3 = FALSE;
    if (((dx * dx) + (dy * dy) + (dz * dz)) < 4900.0f) {
        phi_a3 = TRUE;
    }
    if ((phi_a3 & 0xFF) && !isFlagSet(tempFlagIndex, FLAG_TYPE_TEMPORARY)) {
        func_global_asm_8070D8C0(current_actor_pointer, arg0, arg1);
        setFlag(tempFlagIndex, TRUE, FLAG_TYPE_TEMPORARY);
    }
}

void func_global_asm_806C15E8() {
    D_global_asm_807FDC98->unk46 |= 0x1000;
    current_actor_pointer->unk146 = 0;
    func_global_asm_8072B324(current_actor_pointer, 0);
    current_actor_pointer->unkCC = 1;
}

void func_global_asm_806C1640(void) {
    f64 temp_f0;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
        if (current_map == MAP_DK_RAP) {
            temp_f0 = 0.8;
            current_actor_pointer->animation_state->scale_x *= temp_f0;
            current_actor_pointer->animation_state->scale_y *= temp_f0;
            current_actor_pointer->animation_state->scale_z *= temp_f0;
        }
    }
    func_global_asm_806BF920();
    // TODO: Bitfield syntax
    if (!(((s32)current_actor_pointer->object_properties_bitfield << 3) >= 0)) {
        func_global_asm_806BFBF4();
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C1734(void) {
    s32 pad2; // TODO: Can we get rid of these?
    s32 pad; // TODO: Can we get rid of these?
    ActorAnimationState *temp_v1;
    s16 sp2A;
    u8 sp29;
    AnimationStateUnk0 *temp_a0;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
    }
    func_global_asm_806BF920();
    if (current_actor_pointer->object_properties_bitfield & 0x10000000) {
        sp2A = current_actor_pointer->animation_state->unk0->unk4;
        func_global_asm_806BFBF4();
        temp_v1 = current_actor_pointer->animation_state;
        if (temp_v1->unk8->unk0 == 0) {
            temp_a0 = temp_v1->unk0;
            switch (temp_a0->unk10) {
                case 0xBB:
                    if ((current_actor_pointer->y_velocity > 30.0f) && !(object_timer & 3)) {
                        func_global_asm_80714998(2);
                        func_global_asm_807149B8(1);
                        func_global_asm_8071498C(&func_global_asm_8071C818);
                        func_global_asm_80714C08(&D_global_asm_8071FB08, 0.8f, current_actor_pointer, 5, 0);
                    }
                    break;
                case 0x114:
                    if (temp_a0->unk24 == 0.0f) {
                        func_global_asm_806F1048(current_actor_pointer);
                    }
                    break;
                case 0xEA:
                    if ((current_actor_pointer->control_state_progress != 0) && (sp2A >= 0xA)) {
                        current_actor_pointer->control_state_progress = 0;
                        func_global_asm_80690814(current_actor_pointer, 7);
                        func_global_asm_8069084C(0x29, 0xCA, 0.4f, current_actor_pointer->y_rotation, 250.0f, 0.0f, current_actor_pointer);
                    }
                    break;
                case 0x112:
                    if ((sp2A >= 0x44) && (sp2A < 0x64) && ((object_timer % 3U) == 0)) {
                        sp29 = ((rand() >> 0xF) % 32767) % 2;
                        func_global_asm_807149B8(1);
                        func_global_asm_80714950(0x50);
                        func_global_asm_8071498C(&func_global_asm_8071A8B0);
                        func_global_asm_80714C08(&D_global_asm_807200D4, 0.5f, current_actor_pointer, sp29 + 9, 2);
                    }
                    break;
            }
        }
    } else {
        func_global_asm_806C10A0(0, 3, 0x3D8);
        if (isFlagSet(4, FLAG_TYPE_PERMANENT) != 0) {
            func_global_asm_806C151C(3, 3, 0);
        }
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C19F4(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
        current_actor_pointer->ledge_info_pointer->unk14 = 180.0f;
        func_global_asm_80724CA4(2, 1);
        // Note: This is read as u16 at 0x5A instead of u32 at 0x58
        func_global_asm_806F09F0(current_actor_pointer, current_actor_pointer->unk58);
    }

    // TODO: Bitfield syntax
    if (((s32)current_actor_pointer->object_properties_bitfield * 8) < 0) {
        func_global_asm_806BFBF4();
        if (current_actor_pointer->animation_state->unk0->unk10 == 0x1A4) {
            func_global_asm_807149B8(1);
            func_global_asm_807149C8(0x96, 0xFF, 0xFF, 0xFF);
            func_global_asm_80714C08(&D_global_asm_8071FBA0, 0.7f, current_actor_pointer, 5, 0);
        }
        func_global_asm_80724E48(D_global_asm_807FDC94 == player_pointer ? 5 : 7);
    } else {
        func_global_asm_806C10A0(2, 6, 0x3D9);
        func_global_asm_80724E48(0);
        func_global_asm_806C151C(6, 1, 6); // Aztec: Caged Lanky Text Cleared
    }
    renderActor(current_actor_pointer, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806C1B50.s")

extern s32 D_global_asm_8071FB34; // TODO: Datatype

/*
// TODO: Switch case woes
void func_global_asm_806C1B50(void) {
    s32 var_v0;
    u32 var_v1;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        func_global_asm_806C15E8();
        func_global_asm_806F09F0(current_actor_pointer, current_actor_pointer->unk58);
    }
    func_global_asm_806BF920();
    if (current_actor_pointer->object_properties_bitfield & 0x10000000) {
        func_global_asm_806BFBF4();
        if (current_actor_pointer->object_properties_bitfield & 4) {
            if (current_actor_pointer->control_state_progress != 0) {
                var_v1 = 7;
                switch (current_actor_pointer->animation_state->unk0->unk10) {
                    case 0x23E:
                        var_v0 = 0xD;
                        break;
                    case 0x23F:
                        var_v1 = 7;
                        var_v0 = 0xE;
                        break;
                    case 0x240:
                        var_v1 = 3;
                        var_v0 = 0x11;
                        // fallthrough
                    default:
                        var_v1 = 3;
                        break;

                }
                // if (current_actor_pointer->control_state_progress != 0x23E) {
                //     var_v1 = 7;
                //     if (current_actor_pointer->control_state_progress != 0x23F) {
                //         var_v1 = 3;
                //         if (current_actor_pointer->control_state_progress != 0x240) {

                //         } else {
                //             var_v0 = 0x11;
                //         }
                //     } else {
                //         var_v0 = 0xE;
                //     }
                // } else {
                //     var_v0 = 0xD;
                // }
                if (var_v1 < current_actor_pointer->animation_state->unk0->unk4) {
                    func_global_asm_80714C08(&D_global_asm_8071FB34, 0.5f, current_actor_pointer, var_v0, 0);
                    current_actor_pointer->control_state_progress = 0;
                }
            }
        }
    } else {
        func_global_asm_806C10A0(2, 4, 0x3DB);
        func_global_asm_806C151C(4, 1, 8);
    }
    renderActor(current_actor_pointer, 0);
}
*/

void func_global_asm_806C1CCC(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->terminal_velocity = -2000.0f;
        current_actor_pointer->y_acceleration = -200.0f;
        func_global_asm_806C15E8();
        func_global_asm_80724CA4(2, 1);
        if (current_map == MAP_DK_RAP) {
            func_global_asm_80613194(current_actor_pointer, 0xE);
        }
        func_global_asm_806F09F0(current_actor_pointer, current_actor_pointer->unk58);
    }
    // TODO: Better way to do this
    if (((s32) current_actor_pointer->object_properties_bitfield * 8) < 0) {
        func_global_asm_806BFBF4();
        if (current_actor_pointer->object_properties_bitfield & 4) {
            if ((current_actor_pointer->animation_state->unk0->unk10 == 0x2C4) && (current_actor_pointer->animation_state->unk0->unk4 > 25.0f)) {
                func_global_asm_8068C350(&func_global_asm_807035C4, NULL, 3);
            }
        }
        func_global_asm_80724E48(D_global_asm_807FDC94 == player_pointer ? 5 : 7);
    } else {
        func_global_asm_806C10A0(2, 5, 0x3DA);
        func_global_asm_80724E48(0);
        func_global_asm_806C151C(5, 1, 0xF); // Factory: Caged Chunky Text Cleared
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C1E44(void) {
    s32 i;

    func_global_asm_80729B00();
    if ((current_actor_pointer->object_properties_bitfield & 0x10) == 0) {
        func_global_asm_8068842C(current_actor_pointer, 0, 1);
        func_global_asm_80688460(current_actor_pointer, 0, 1);
        switch (current_map) {
            case MAP_AZTEC_LLAMA_TEMPLE:
                current_actor_pointer->unk130 = 0xFF;
                current_actor_pointer->unk131 = 0xFF;
                // Aztec: Water Cooled Down
                if (!isFlagSet(0x4C, FLAG_TYPE_PERMANENT)) {
                    func_global_asm_806883F4(current_actor_pointer, 0, 1, 0);
                    func_global_asm_80614EBC(current_actor_pointer, 0x2BD);
                    current_actor_pointer->control_state = 0;
                    current_actor_pointer->control_state_progress = 0;
                } else {
                    current_actor_pointer->control_state = 0x27;
                    current_actor_pointer->control_state_progress = 0;
                    current_actor_pointer->control_state_progress = 4;
                }
                break;
            case MAP_AZTEC:
                func_global_asm_806883F4(current_actor_pointer, 0, 0, 0);
                current_actor_pointer->control_state = 5;
                current_actor_pointer->control_state_progress = 0;
                break;
        }
    }
    switch (current_actor_pointer->control_state) {
        case 0:
            func_global_asm_80724A20();
            switch (current_actor_pointer->control_state_progress) {
                case 1:
                    D_global_asm_807FDC90->unk2C = 3;
                    current_actor_pointer->control_state_progress = 2;
                    // Fallthrough
                case 2:
                    if (!(object_timer & 7)) {
                        if (D_global_asm_807FDC90->unk2C != 0) {
                            D_global_asm_807FDC90->unk2C--;
                            if (D_global_asm_807FDC90->unk2C == 0) {
                                current_actor_pointer->control_state_progress = 0;
                            }
                            func_global_asm_80714998(2);
                            func_global_asm_807149B8(1);
                            func_global_asm_807149FC(0x28);
                            func_global_asm_8071498C(&func_global_asm_807197B4);
                            func_global_asm_80714C08(&D_global_asm_8071FF58, 0.05f, current_actor_pointer, 1, 0);
                        }
                    }
            }
            break;
        case 39:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_806883F4(current_actor_pointer, 0, 0, 0);
                    func_global_asm_80614EBC(current_actor_pointer, 0x2BE);
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 3:
                    for (i = 0; i < 0xA; i++) {
                        func_global_asm_807149B8(1);
                        func_global_asm_807149FC(0x28);
                        func_global_asm_8071498C(&func_global_asm_8071F078);
                        func_global_asm_80714950(current_actor_pointer->y_rotation);
                        func_global_asm_80714C08(&D_global_asm_80720B58, 0.7f, current_actor_pointer, 1, 0);
                    }
                    current_actor_pointer->control_state_progress++;
            }
            break;
        case 5:
            func_global_asm_80724A20();
            func_global_asm_806C151C(0xA, 1, 7);
            func_global_asm_806C13AC(4, 0x4F1, 0x4F7, 0x4F7, 0x4F7);
            if (func_global_asm_80629148()) {
                current_actor_pointer->control_state = 0x12;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 18:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    func_global_asm_80614EBC(current_actor_pointer, 0x2BF);
                    func_global_asm_806883F4(current_actor_pointer, 0, 2, 0);
                    func_global_asm_8072B324(current_actor_pointer, D_global_asm_807FDC9C->unkC);
                    current_actor_pointer->control_state_progress = 1;
                    break;
                case 2:
                    func_global_asm_8072AB74(2, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0, 0.0f);
                    func_global_asm_8072D13C(2, 0);
                    break;
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C226C(void) {
    s16 i;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->y_acceleration = D_global_asm_807502F4;
        current_actor_pointer->y_position = current_actor_pointer->floor;
        current_actor_pointer->draw_distance = 0x4B0;
        if (isFlagSet(0x9E, FLAG_TYPE_PERMANENT)) {
            if (D_global_asm_807FDC9C->unk13 == 0x16) {
                current_actor_pointer->control_state = 0x28;
                current_actor_pointer->control_state_progress = 0;
            } else {
                current_actor_pointer->control_state = 0x40;
            }
        } else if (D_global_asm_807FDC9C->unk13 == 0x16) {
            current_actor_pointer->control_state = 0x40;
        }
    }
    for (i = 0; i < D_global_asm_807FBDC4; i++) {
        if (D_global_asm_807FBDC8[i] == 3) {
            func_global_asm_80614EBC(current_actor_pointer, 0x2A3);
            current_actor_pointer->control_state = 0x27;
            current_actor_pointer->control_state_progress = 0;
            playCutscene(current_actor_pointer, 0x16, 1);
            setFlag(0x9E, TRUE, FLAG_TYPE_PERMANENT);
        }
    }
    switch (current_actor_pointer->control_state) {
        case 39:
            if (current_actor_pointer->unk6A & 4) {
                func_global_asm_8072A920(2, 0, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkC, D_global_asm_807FDC90->unkE, 0x46, 30.0f, 100.0f, 0);
                if (((rand() >> 0xF) % 1000) >= 0x3A3) {
                    func_global_asm_8071498C(&func_global_asm_80718BF4);
                    func_global_asm_807149B8(1);
                    func_global_asm_807149FC(-1);
                    func_global_asm_80714CC0(&D_global_asm_8071FC40, 0.0f, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
                }
            } else {
                if ((current_actor_pointer->unk6A ^ current_actor_pointer->unk6C) & 1) {
                    func_global_asm_80614EBC(current_actor_pointer, 0x2A4);
                }
                func_global_asm_8072AB74(2, D_global_asm_807FDC90->unkA, D_global_asm_807FDC90->unkE, 0x200, 0.0f);
                if (current_actor_pointer->y_velocity < -10.0f) {
                    current_actor_pointer->z_rotation = func_global_asm_806CC190(current_actor_pointer->z_rotation, 0x400, 10.0f);
                }
            }
            func_global_asm_8072D13C(2, 0);
            if (func_global_asm_80629148()) {
                current_actor_pointer->control_state = 0x40;
            }
            break;
        case 40:
            switch (current_actor_pointer->control_state_progress) {
                case 0x0:
                    func_global_asm_80724B5C(2, 3, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
                    func_global_asm_80614EBC(current_actor_pointer, 0x2A6);
                    current_actor_pointer->z_rotation = 0;
                    current_actor_pointer->control_state_progress += 1;
                    // Fallthrough
                case 0x1:
                    if (func_global_asm_8072E22C(0xC8) != 0) {
                        current_actor_pointer->control_state_progress += 1;
                        if (isFlagSet(0xC1, FLAG_TYPE_PERMANENT) != 0) {
                            if ((current_character_index[0] == 0) && (isFlagSet(0xA5, FLAG_TYPE_PERMANENT) == 0)) {
                                func_global_asm_8070D8C0(current_actor_pointer, 0x1C, 2);
                            } else if (current_character_index[0] != 0) {
                                func_global_asm_8070D8C0(current_actor_pointer, 0x1C, 0);
                            }
                        } else if (current_character_index[0] == 0) {
                            playCutscene(current_actor_pointer, 0x1E, 1);
                            func_global_asm_8070E8DC(1);
                            func_global_asm_8070D8C0(current_actor_pointer, 0x1C, 1);
                            current_actor_pointer->control_state_progress = 0x63;
                        } else {
                            func_global_asm_8070D8C0(current_actor_pointer, 0x1C, 0);
                        }
                    }
                    break;
                case 0x2:
                    if ((isFlagSet(0xC1, FLAG_TYPE_PERMANENT) == FALSE) && (func_global_asm_8072E22C(0x12C) == 0)) {
                        current_actor_pointer->control_state_progress = 1;
                    }
                    break;
                case 0x63:
                    if ((func_global_asm_8061CB50() == 0) && !(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                        func_global_asm_8070D8C0(current_actor_pointer, 0x1C, 2);
                        current_actor_pointer->control_state_progress = 3;
                    }
                    break;
            }
            func_global_asm_806335B0(D_global_asm_807F62B4, 1, 1, &current_actor_pointer->x_position, &current_actor_pointer->y_position, &current_actor_pointer->z_position);
            func_global_asm_8072E1A4(0xA, D_global_asm_807FDC94);
            break;
    }
    func_global_asm_8072881C(0, &D_global_asm_807FDC90->unk28);
    renderActor(current_actor_pointer, 0);
}

void func_global_asm_806C27DC(void) {
    f32 temp_f20;

    temp_f20 = current_actor_pointer->animation_state->scale_y / 0.15;
    func_global_asm_80604CBC(current_actor_pointer, 0x114, 0x50, 0, 0, 0xFF, 0.5f, 0);
    if (object_timer & 1) {
        func_global_asm_80684550(current_actor_pointer, 1, temp_f20);
        func_global_asm_80684550(current_actor_pointer, 3, temp_f20);
    } else {
        func_global_asm_80684550(current_actor_pointer, 2, temp_f20);
        func_global_asm_80684550(current_actor_pointer, 4, temp_f20);
    }
}

// Doable, floaty loop, rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806C28B8.s")

/*
// TODO: Float and stack nonsense
void func_global_asm_806C28B8(void) {
    f64 temp_f20;
    f32 sp78;
    f32 sp74;
    s32 sp70;
    f32 phi_f2;
    s16 i;
    f64 phi_f0;

    phi_f2 = current_actor_pointer->animation_state->unk0->unk4;
    if (phi_f2 > 83.0f) {
        func_global_asm_806C27DC();
        phi_f2 = current_actor_pointer->animation_state->unk0->unk4;
    }
    if ((phi_f2 > 2.0f) && (phi_f2 < 90.0f)) {
        if ((object_timer % 6U) == 0) {
            temp_f20 = MIN(1, phi_f2 / 70.0) * 0.3;
            for (i = 1; i < 5; i++) {
                func_global_asm_80671C0C(current_actor_pointer, i, &sp78, &sp74, &sp70);
                phi_f0 = MAX(0.15, temp_f20);
                func_global_asm_806852C4(phi_f0, sp78, sp74 + 3.0f, sp70);
            }
        }
    }
}
*/

void func_global_asm_806C2A64(u8 arg0, u8 arg1, u8 arg2, f32 arg3, f32 arg4, f32 arg5, void *arg6, f32 arg7) {
    func_global_asm_807149A8(1000);
    func_global_asm_80714998(0xFF);
    func_global_asm_80714944(((rand() >> 0xF) % 32767) % 11);
    func_global_asm_807149C8(arg0, arg1, arg2, 0xFF);
    func_global_asm_8071498C(&func_global_asm_80717D84);
    func_global_asm_80714950(2);
    func_global_asm_80714CC0(arg6, arg7 * 0.2, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806C2B2C.s")

/*
void func_global_asm_806C2B2C(s32 arg0, s32 arg1, u8 arg2, s32 arg3) {
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

    temp_f24 = (current_actor_pointer->animation_state->scale_y / 0.3f) / 1.5;
    while (arg1 >= arg0) {
        for (i = 0; i < 3.0; i++) {
            temp_s0 = &D_global_asm_80747B00[arg2];
            temp_f20 = i / 3.0;
            func_global_asm_80671C0C(current_actor_pointer, arg0, &spA8, &spA4, &spA0);
            if (arg0 < arg1) {
                func_global_asm_80671C0C(current_actor_pointer, arg0 + 1, &sp9C, &sp98, &sp94);
            } else {
                func_global_asm_80671C0C(current_actor_pointer, arg0, &sp9C, &sp98, &sp94);
            }
            func_global_asm_806C2A64(spA0, temp_s0->unk0, temp_s0->unk1, temp_s0->unk2, ((sp9C - spA8) * temp_f20) + spA8, ((sp98 - spA4) * temp_f20) + spA4, ((sp94 - spA0) * temp_f20) + spA0, arg3);
        }
    }
}
*/

void func_global_asm_806C2D7C() {
    func_global_asm_806C2B2C(1, 0xB, 6, &D_global_asm_8071FFA0);
    func_global_asm_806C2B2C(0x20, 0x30, 6, &D_global_asm_8071FFA0);
    func_global_asm_806C2B2C(0xC, 0x16, 2, &D_global_asm_8071FFA0);
    func_global_asm_806C2B2C(0x17, 0x1F, 2, &D_global_asm_8071FFA0);
}

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_C2A90/func_global_asm_806C2DF4.s")

void func_global_asm_806C3A8C(void) {
    s32 sp2C;
    u8 pad;

    sp2C = (((player_pointer->x_position - current_actor_pointer->x_position) * (player_pointer->x_position - current_actor_pointer->x_position)) + ((player_pointer->y_position - current_actor_pointer->y_position) * (player_pointer->y_position - current_actor_pointer->y_position)) + ((player_pointer->z_position - current_actor_pointer->z_position) * (player_pointer->z_position - current_actor_pointer->z_position)));
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unk15E = 0x19;
        func_global_asm_8067ACB4(current_actor_pointer);
        if (isFlagSet(0x1E, FLAG_TYPE_TEMPORARY) == FALSE) {
            playCutscene(current_actor_pointer, 0x14, 1);
            setFlag(0x1E, TRUE, FLAG_TYPE_TEMPORARY);
        }
        if (isFlagSet(0xBF, FLAG_TYPE_PERMANENT) == FALSE) {
            if (isFlagSet(0xBA, FLAG_TYPE_PERMANENT)
                && isFlagSet(0xBB, FLAG_TYPE_PERMANENT)
                && isFlagSet(0xBC, FLAG_TYPE_PERMANENT)
                && isFlagSet(0xBD, FLAG_TYPE_PERMANENT)
                && isFlagSet(0xBE, FLAG_TYPE_PERMANENT)) {
                current_actor_pointer->control_state = 0x27;
                current_actor_pointer->control_state_progress = 0;
            } else {
                if (isFlagSet(0xBA, FLAG_TYPE_PERMANENT)
                    || isFlagSet(0xBB, FLAG_TYPE_PERMANENT)
                    || isFlagSet(0xBC, FLAG_TYPE_PERMANENT)
                    || isFlagSet(0xBD, FLAG_TYPE_PERMANENT)
                    || isFlagSet(0xBE, FLAG_TYPE_PERMANENT)) {
                        current_actor_pointer->control_state = 0x1F;
                        current_actor_pointer->control_state_progress = 0;
                    } else {
                        current_actor_pointer->control_state = 0x1E;
                        current_actor_pointer->control_state_progress = 0;
                    }
                }
        } else {
            current_actor_pointer->control_state = 0x20;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806BFBF4();
    switch (current_actor_pointer->control_state) {
        case 30:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    if ((u8)(sp2C < 62500)) {
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
                case 1:
                    if ((u8)(sp2C < 10000)) {
                        func_global_asm_80614EBC(current_actor_pointer, 0x3A4);
                        func_global_asm_8070D8C0(current_actor_pointer, 0x17, 0);
                        current_actor_pointer->control_state_progress++;
                    }
                    break;
            }
            break;
        case 31:
            if ((u8)(sp2C < 10000)) {
                if (current_actor_pointer->control_state_progress == 0) {
                    D_global_asm_80750AC8 = isFlagSet(0xBA, FLAG_TYPE_PERMANENT)
                        + isFlagSet(0xBB, FLAG_TYPE_PERMANENT)
                        + isFlagSet(0xBC, FLAG_TYPE_PERMANENT)
                        + isFlagSet(0xBD, FLAG_TYPE_PERMANENT)
                        + isFlagSet(0xBE, FLAG_TYPE_PERMANENT);
                    func_global_asm_8070D8C0(current_actor_pointer, 0x17, 2);
                    current_actor_pointer->control_state_progress++;
                }
            }
            break;
        case 32:
            if ((u8)(sp2C < 10000)) {
                if (current_actor_pointer->control_state_progress == 0) {
                    if (func_global_asm_8061CB50() == 0) {
                        playCutscene(current_actor_pointer, 0x18, 1);
                        func_global_asm_8070D8C0(current_actor_pointer, 0x17, 3);
                        current_actor_pointer->control_state_progress++;
                    }
                }
            }
            break;
        case 39:
            if (!func_global_asm_8061CB50()) {
                switch (current_actor_pointer->control_state_progress) {
                    case 0:
                        playCutscene(current_actor_pointer, 0x17, 1);
                        func_global_asm_8070E8DC(1);
                        func_global_asm_8070D8C0(current_actor_pointer, 0x17, 1);
                        current_actor_pointer->control_state_progress++;
                        break;
                    case 1:
                        if (!(current_actor_pointer->object_properties_bitfield & 0x02000000)) {
                            func_global_asm_8063DA40(0xE, 0xA);
                            current_actor_pointer->control_state = 0x20;
                            current_actor_pointer->control_state_progress = 0;
                        }
                        break;
                }
            }
            break;
    }
    renderActor(current_actor_pointer, 0);
}
