#include <ultra64.h>
#include "functions.h"

extern s32 D_global_asm_8071FFA0;
extern s32 D_global_asm_8074E880[]; // TODO: Datatype

extern f32 D_global_asm_8075B8B0;
extern f32 D_global_asm_8075B8B4;
extern f32 D_global_asm_8075B8B8;
extern s16 D_global_asm_807F6248;
extern s16 D_global_asm_807F624C;
extern f64 D_global_asm_8075B8C0;

int func_global_asm_8071C9E8(); // TODO: Signature

void func_global_asm_806B8B20(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_global_asm_8071498C(&func_global_asm_8071C9E8);
    func_global_asm_807149FC(-1);
    func_global_asm_807149B8(1);
    func_global_asm_8071496C(arg3);
    func_global_asm_80714CC0(D_global_asm_8074E880[((rand() >> 0xF) % 1000) % 3], 1.8f, arg0, arg1, arg2);
}

void func_global_asm_806B8BDC(s16 arg0, s16 arg1, s16 arg2) {
    func_global_asm_80714998(2);
    func_global_asm_8071498C(&func_global_asm_80717D4C);
    func_global_asm_80714950(-0x28);
    func_global_asm_807149B8(1);
    func_global_asm_807149C8(0xFF, 0xFF, 0xFF, 0xC8);
    func_global_asm_80714CC0(&D_global_asm_8071FFA0, 2.0f, arg0, arg1, arg2);
}

void func_global_asm_806B8C78(void) {
    switch (current_actor_pointer->control_state) {
        case 1:
            switch (current_actor_pointer->control_state_progress) {
                case 0:
                    current_actor_pointer->y_velocity = 0.0f;
                    func_global_asm_80614EBC(current_actor_pointer, 0x290);
                    current_actor_pointer->control_state_progress++;
                    break;
                case 2:
                    if (current_actor_pointer->y_position > -20.0f) {
                        current_actor_pointer->y_position -= current_actor_pointer->y_velocity;
                    }
                    current_actor_pointer->y_velocity = MIN(current_actor_pointer->y_velocity + 0.5, 8.0f);
                    break;
            }
            break;
        case 2:
            func_global_asm_806B8B20(0x258, 0x64, 0x1E5, 0x64);
            func_global_asm_806B8B20(0x258, 0x96, 0x1E5, 0x64);
            func_global_asm_806B8B20(0x258, 0xC8, 0x1E5, 0x67);
            func_global_asm_806B8B20(0x258, 0xFA, 0x1E5, 0x68);
            func_global_asm_806B8B20(0x258, 0x12C, 0x1E5, 0x6C);
            func_global_asm_806B8B20(0x258, 0x15E, 0x1E5, 0x6E);
            func_global_asm_806B8B20(0x258, 0x190, 0x1E5, 0x73);
            func_global_asm_806B8B20(0x258, 0x1C2, 0x1E5, 0x74);
            current_actor_pointer->control_state++;
            D_global_asm_807FDC90->unk2C = 0x46;
            break;
        case 3:
            if (D_global_asm_807FDC90->unk2C != 0) {
                D_global_asm_807FDC90->unk2C--;
            } else {
                current_actor_pointer->control_state = 0x40;
            }
            if (D_global_asm_807FDC90->unk2C < 0x28) {
                func_global_asm_8063C1EC(4, 0x10);
                func_global_asm_8063C1EC(6, 0x10);
                func_global_asm_8063C248(5, 0x10);
                func_global_asm_8063C248(7, 0x10);
                if (((D_global_asm_807FDC90->unk2C < 0x15) && (((rand() >> 0xF) % 1000) < 0x12C)) || (current_actor_pointer->control_state == 0x40)) {
                    if (current_actor_pointer->control_state == 0x40) {
                        func_global_asm_8063C1EC(5, 0x10);
                        func_global_asm_8063C1EC(7, 0x10);
                        playSound(0x1D0, 0x58EF, 63.0f, 1.0f, 0, 0);
                        playSong(0x3A, 1.0f);
                        func_global_asm_806B8BDC(0xBD, 0xAA, 0x2FB);
                        func_global_asm_806B8BDC(0x19A, 0xA6, 0x2F8);
                    }
                    func_global_asm_8065F134(D_global_asm_807F6248, 0);
                    func_global_asm_8065F134(D_global_asm_807F624C, 0);
                    func_global_asm_80659670(D_global_asm_8075B8B0, D_global_asm_8075B8B0, D_global_asm_8075B8B0, 0);
                    return;
                }
                if (D_global_asm_807FDC90->unk2C >= 0x15) {
                    func_global_asm_8065F134(D_global_asm_807F6248, 9);
                    func_global_asm_8065F134(D_global_asm_807F624C, 9);
                    func_global_asm_80659670(D_global_asm_8075B8B4, D_global_asm_8075B8B4, D_global_asm_8075B8B4, 0);
                    return;
                }
                func_global_asm_8065F134(D_global_asm_807F6248, 8);
                func_global_asm_8065F134(D_global_asm_807F624C, 8);
                func_global_asm_80659670(D_global_asm_8075B8B8, D_global_asm_8075B8B8, D_global_asm_8075B8B8, 0);
            }
    }
}

void func_global_asm_806B904C(void) {
    f32 temp_f0;
    s16 i;

    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        temp_f0 = (D_global_asm_807FDC9C->unkF / D_global_asm_8075B8C0) * 0.75;
        current_actor_pointer->animation_state->scale_x = temp_f0;
        current_actor_pointer->animation_state->scale_y = temp_f0;
        current_actor_pointer->animation_state->scale_z = temp_f0;
        if (func_global_asm_805FF0C8() != 0) {
            current_actor_pointer->control_state = 0x40;
        } else {
            current_actor_pointer->draw_distance = 1000;
            current_actor_pointer->unk130 = 0x3C;
            current_actor_pointer->unk131 = 0x3C;
            func_global_asm_80613C48(current_actor_pointer, 0x482, 0, 0);
        }
        func_global_asm_8063C1EC(5, 0x10);
        func_global_asm_8063C1EC(7, 0x10);
    }
    for (i = 0; i < D_global_asm_807FBB70.unk254; i++) {
        if (D_global_asm_807FBB70.unk258[i] == 3) {
            current_actor_pointer->control_state = D_global_asm_807FBB70.unk278[i]->unk2;
            current_actor_pointer->control_state_progress = 0;
        }
    }
    func_global_asm_806B8C78();
    func_global_asm_806319C4(current_actor_pointer, 0);
}
