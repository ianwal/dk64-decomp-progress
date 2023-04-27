#include <ultra64.h>
#include "functions.h"

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_B6C50/func_806B1F50.s")

extern s32 D_8072030C;
extern f64 D_8075B3C0;

void func_80665564(Actor*, f32);
void func_806319C4(Actor*, s32);

/*
// TODO: Doable, very good progress made
void func_806B1F50(void) {
    u8 sp37;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_807FDC98->unk46 |= 0xA0;
        current_actor_pointer->object_properties_bitfield |= 0x400;
        current_actor_pointer->control_state = 0;
        current_actor_pointer->control_state_progress = 0;
        func_80677FA8(0x73, 0x7D);
        D_807FDC90->unk4 = D_807FBB44;
        func_8067B238(D_807FBB44, current_actor_pointer, 0.3f);
        D_807FBB44->x_position = (func_80612794(current_actor_pointer->y_rotation) * 14.0f) + current_actor_pointer->x_position;
        D_807FBB44->z_position = (func_80612790(current_actor_pointer->y_rotation) * 14.0f) + current_actor_pointer->z_position;
        func_8066EA90(D_807FBB44, 3);
        func_8066EA90(D_807FBB44, 1);
        func_80665564(D_807FBB44, 14.0f);
        current_actor_pointer->unk68 &= 0xFFBF;
        D_807FBB44->object_properties_bitfield |= 0x1000;
        func_807149B8(1);
        func_807149FC(-1);
        func_807149A8(D_807FBB44->draw_distance * 0.75); // Issue here
        func_80714C08(&D_8072030C, 0.28f, D_807FBB44, 1, 2);
        func_80614EBC(current_actor_pointer, 0x300);
        func_80604CBC(current_actor_pointer, 0x135, 0x64, 0, 0, 0x78, 1.0f, 0);
    }
    if ((D_807FBB70->unk15 != 0) || (D_807FBB70->unk200 == 9)) {
        current_actor_pointer->unk11C->control_state = 0;
        playCutscene(current_actor_pointer, 6, 5);
        current_actor_pointer->noclip_byte = 1;
        current_actor_pointer->control_state = 0x37;
        current_actor_pointer->control_state_progress = 0;
    } else if (D_807FBB70->unk200 == 4) {
        current_actor_pointer->control_state_progress++;
    }
    switch (current_actor_pointer->control_state) {
        case 0x27:
            break;
        case 0x0:
            if (func_80629148() != 0) {
                func_806A2A10(0xDC, 0x2A, 0x1E);
                func_806A2B08(current_actor_pointer->unk11C);
                current_actor_pointer->control_state = 7;
                current_actor_pointer->control_state_progress = 0;
            }
            break;
        case 0x37:
            switch (current_actor_pointer->control_state_progress) {
                case 0x3C:
                    current_actor_pointer->object_properties_bitfield &= ~4;
                    current_actor_pointer->unk68 &= 0xFFBF;
                    func_80608528(current_actor_pointer, 0xED, 0xFF, 0x7F, 0x14);
                    func_8067DF44(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, (current_actor_pointer->animation_state->scale_y * 2) / D_8075B3C0, 0, 1);
                    func_806782C0(D_807FDC94);
                    current_actor_pointer->control_state_progress += 1;
                    break;
                case 0x64:
                    func_806782C0(current_actor_pointer->unk11C);
                    current_actor_pointer->control_state = 0x40;
                    playSong(0x2A, 1.0f);
                    // Fallthrough
                default:
                    current_actor_pointer->control_state_progress++;
                    break;
                }
            break;
        default:
            if ((current_actor_pointer->unk11C != NULL) && (current_actor_pointer->unk11C->control_state == 5)) {
                current_actor_pointer->unk138 &= 0xFFFF7FFF;
                func_80605314(current_actor_pointer, 0);
                func_80726EE0(0);
                func_8071586C(D_807FDC94);
                func_806782C0(current_actor_pointer->unk11C);
                current_actor_pointer->control_state = 0x27;
                current_actor_pointer->control_state_progress = 0;
                playCutscene(current_actor_pointer, 3, 1);
                func_80614EBC(current_actor_pointer, 0x307);
                current_actor_pointer->y_rotation += 0x800;
                current_actor_pointer->z_position += 5.0f;
            }
            if ((current_actor_pointer->control_state_progress != 0) && (func_8067AF44(D_807FDC94) != 0) && ((object_timer % 7) == 0)) {
                sp37 = (current_actor_pointer->control_state_progress * -0x1E) + 0xB4;
                func_80714998(3);
                func_807149C8(sp37, sp37, sp37, current_actor_pointer->shadow_opacity);
                func_8068588C(D_807FDC94, 1, 1.0f, 0.0f, 0.0f, 0.0f, -0x96);
            }
            break;
    }
    func_806319C4(current_actor_pointer, 0);
}
*/

extern s32 D_80720340;
extern f32 D_8075B3C8;
extern f64 D_8075B3D0;
extern f64 D_8075B3D8;
extern f64 D_8075B3E0;

void func_8072AB74(s32, f32, f32, s32, f32);
void func_80613C48(Actor*, s32, f32, f32);

void func_806B24B8(void) {
    Actor *temp_v0;
    f32 dx;
    f32 dz;

    func_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_v0 = func_8067ADB4(0x110);
        if (temp_v0 != NULL) {
            D_807FDC90->unk4 = temp_v0;
        }
        D_807FDC9C->unk10 = 0x23;
        func_80613C48(current_actor_pointer, 0x599, 0, 0);
        current_actor_pointer->unk68 &= 0xFFBF;
        func_80604CBC(current_actor_pointer, 0x139, 0x78, 0, 1, 0x3C, D_8075B3C8, 0);
        current_actor_pointer->object_properties_bitfield |= 0x400;
    }
    if ((object_timer % 10U) == 0) {
        func_807149B8(1);
        func_80714C08(&D_80720340, current_actor_pointer->animation_state->scale_y * D_8075B3D0 * D_8075B3D8, current_actor_pointer, 1, 2);
    }
    if (func_8067AF44(D_807FDC94) == 0) {
        D_807FDC90->unk4 = player_pointer;
        D_807FDC94 = D_807FDC90->unk4;
    }
    if ((D_807FBB70->unk15 != 0) || (D_807FBB70->unk200 == 9)) {
        current_actor_pointer->noclip_byte = 1;
        current_actor_pointer->control_state = 0x40;
        func_8067DF44(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, current_actor_pointer->animation_state->scale_y / D_8075B3E0, 0, 1);
    }
    if (current_actor_pointer->control_state == 0x23) {
        if (current_actor_pointer->unkF0 == 0) {
            dx = current_actor_pointer->x_position - D_807FDC94->x_position;
            dz = current_actor_pointer->z_position - D_807FDC94->z_position;
            if (sqrtf((dx * dx) + (dz * dz)) < 30.0f) {
                func_80608528(current_actor_pointer, 0x2CA, 0xFF, 0x7F, 0x14);
                current_actor_pointer->unkF0 = 1;
            }
        }
        func_8072AB74(0x23, D_807FDC94->x_position, D_807FDC94->z_position, 0, 0.0f);
    } else {
        func_8072B7CC(0x1F8);
    }
    func_806319C4(current_actor_pointer, 0);
}
