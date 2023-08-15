#include <ultra64.h>
#include "functions.h"

typedef struct {
    u8 unk0[0x2C - 0x0];
    s16 unk2C;
} AAD_global_asm_806B76B0;

typedef struct {
    f32 unk0;
    f32 unk4;
} A178_806B76B0;

/*
// rodata
D_global_asm_8075B870 .double 0.100000000000000006
D_global_asm_8075B878 .float 285
D_global_asm_8075B880 .double 0.599999999999999978
D_global_asm_8075B888 .double 0.599999999999999978
D_global_asm_8075B890 .double 0.599999999999999978
D_global_asm_8075B898 .double 0.179999999999999993
D_global_asm_8075B8A0 .double 0.00100000000000000002
D_global_asm_8075B8A8 .double 0.00100000000000000002
*/

void func_global_asm_806907F0(f32, f32, f32);
typedef struct GlobalASMStruct90 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} GlobalASMStruct90;

extern s16 D_global_asm_80744490;
extern s16 D_global_asm_80744494;
extern s32 D_global_asm_807201D4; // TODO: Datatype

void func_global_asm_8066EB40(Actor*, f32);
void func_global_asm_8066E854(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
void func_global_asm_806B88B8(void);

void func_global_asm_806B76B0(Gfx *dl, Actor *arg1) {
    A178_806B76B0 *a178;
    AAD_global_asm_806B76B0 *aaD;

    aaD = arg1->additional_actor_data;
    a178 = arg1->unk178;
    gDPPipeSync(dl++);
    if (arg1->control_state == 0x11) {
        gDPSetPrimColor(dl++, 0, 0, 0xC8, 0x00, 0x00, 0xFF);
    } else if (aaD->unk2C != 0) {
        gDPSetPrimColor(dl++, 0, 0, 0x00, 0xC8, 0x00, 0xFF);
    } else {
        gDPSetPrimColor(dl++, 0, 0, 0xDC, 0xB4, 0x00, 0xFF);
    }
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(dl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_2000080, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    func_global_asm_8068C5A8(dl, 0x38, 3, 1, 0x40, 0x40, a178->unk0, a178->unk4, 0.5f, 0.5f, 0x2D, 0.0f);
}

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_global_asm_806B7830.s")

void func_global_asm_806B7BB8(s32 arg0) {
    s32 phi_v1;

    if ((current_map != MAP_CAVES_SHACK_CHUNKY) && (current_map != MAP_CAVES_IGLOO_DIDDY)) {
        phi_v1 = 30;
    } else {
        phi_v1 = 99;
    }
    func_global_asm_806907F0(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position + 100.0f, D_global_asm_807FDC94->z_position);
    func_global_asm_80690A28(phi_v1, 1, 0.5f, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, 285.0f, current_actor_pointer);
}

void func_global_asm_806B7C74(GlobalASMStruct90 *arg0, f32 arg1, f32 arg2) {
    f32 var_f2;

    if (arg1 < arg0->unk0) {
        arg0->unk8 -= 0.6;
        if (arg0->unk8 < -5.0f) {
            arg0->unk8 = -5.0f;
        }
    } else if (arg0->unk0 < arg1) {
        arg0->unk8 += 0.6;
        if (arg0->unk8 > 5.0f) {
            arg0->unk8 = 5.0f;
        }
    }
    if (arg2 < arg0->unk4) {
        arg0->unkC -= 0.6;
        if (arg0->unkC < -5.0f) {
            arg0->unkC = -5.0f;
        }
    } else if (arg0->unk4 < arg2) {
        arg0->unkC += 0.6;
        if (arg0->unkC > 5.0f) {
            arg0->unkC = 5.0f;
        }
    }
    var_f2 = MAX(arg0->unk0 + arg0->unk8, 0.0f);
    if (var_f2 < D_global_asm_80744490) {
        var_f2 = MAX(arg0->unk0 + arg0->unk8, 0.0f);
        arg0->unk0 = var_f2;
    } else {
        arg0->unk0 = D_global_asm_80744490;
    }
    var_f2 = MAX(arg0->unk4 + arg0->unkC, 0.0f);
    if (var_f2 < D_global_asm_80744494) {
        var_f2 = MAX(arg0->unk4 + arg0->unkC, 0.0f);
        arg0->unk4 = var_f2;
    } else {
        arg0->unk4 = D_global_asm_80744494;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_BC3B0/func_global_asm_806B7EA0.s")

extern s32 D_global_asm_807FBB68;
int func_global_asm_806B7830();

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10; // X Position
    s16 unk12; // Y Position
    s16 unk14; // Z Position
    s16 unk16;
    f32 unk18;
} Actor178_806B7EA0;

void func_global_asm_806A2A10(s16 arg0, s16 arg1, u8 arg2);
void func_global_asm_80626F8C(f32, f32, f32, f32 *, f32 *, s32, f32, s32);
void func_global_asm_806A2B08(Actor *arg0);
void func_global_asm_806B7C74(GlobalASMStruct90 *arg0, f32 arg1, f32 arg2);

/*
// TODO: Excruciatingly close, just an issue with some function calls
void func_global_asm_806B7EA0(void) {
    Actor178_806B7EA0 *a178;
    f32 sp40;
    f32 sp3C;

    a178 = current_actor_pointer->unk178;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC98->unk46 |= 0x60;
        D_global_asm_807FBB64 |= 2;
        func_global_asm_806A2A10(0xDC, 0x2A, D_global_asm_807FDC9C->unkA_s16 != 0 ? D_global_asm_807FDC9C->unkA_s16 : 0xA);
        D_global_asm_807FDC90->unk2E       = D_global_asm_807FDC9C->unkA_s16 != 0 ? 0xF : 0x78;
        a178->unk18          = D_global_asm_807FDC9C->unkA_s16 != 0 ? D_global_asm_807FDC9C->unkA_s16 : 10.0f;
    }

    if (D_global_asm_807FDC90->unk2E != 0) {
        if (!func_global_asm_8061CB50()) {
            D_global_asm_807FDC90->unk2E--;
        }
    }

    if (D_global_asm_807FDC90->unk2E == 0) {
        current_actor_pointer->control_state = 0x23;
        current_actor_pointer->control_state_progress = 0;
        playSound(0x1A2, 0x7FFF, 63.0f, 1.0f, 0, 0);
        func_global_asm_806A2B08(current_actor_pointer->unk11C);
        D_global_asm_807FBB68 |= 1;
        D_global_asm_807FBB64 |= 2;
        if ((current_actor_pointer->unk11C->control_state == 5) && (current_actor_pointer->control_state != 0x11)) {
            if (D_global_asm_807FDC94->unkFC != 0) {
                D_global_asm_807FDC94->y_rotation = func_global_asm_80672A70(D_global_asm_807FDC94->unkF4, D_global_asm_807FDC94->unkF6);
            }
            playCutscene(NULL, 6, 5);
            current_actor_pointer->control_state = 0x11;
            current_actor_pointer->control_state_progress = 0;
            a178->unk10 = D_global_asm_807FDC94->x_position;
            a178->unk12 = D_global_asm_807FDC94->y_position + D_global_asm_807FDC94->unk15E;
            a178->unk14 = D_global_asm_807FDC94->z_position;
            D_global_asm_807FDC90->unk2C = 0x14;
        }
        current_actor_pointer->unk6E[0]++;
        if (a178->unk18 < current_actor_pointer->unk6E[0]) {
            playSound(0x15B, 0x7FFF, 63.0f, 1.0f, 0, 0x80);
            current_actor_pointer->unk6E[0] = 0;
            if (a178->unk18 > 2.0f) {
                a178->unk18 -= 0.18;
            }
        }
        switch (current_actor_pointer->control_state) {
            case 0x23:
                if (!func_global_asm_8061CC00()) {
                    func_global_asm_80626F8C(D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position + D_global_asm_807FDC94->unk15E, D_global_asm_807FDC94->z_position, &sp40, &sp3C, 0, 1.0f, 0);
                    func_global_asm_806B7C74(a178, sp40, sp3C);
                }
                break;
            case 0x11:
                if (!func_global_asm_8061CC00()) {
                    func_global_asm_8068C350(&func_global_asm_806B7830, current_actor_pointer, 3);
                }
                if (D_global_asm_807FDC90->unk2C != 0) {
                    D_global_asm_807FDC90->unk2C--;
                    if (D_global_asm_807FDC90->unk2C == 5) {
                        playSound(0x175, 0x7FFF, 63.0f, 1.0f, 0, 0);
                    }
                } else {
                    func_global_asm_806B7BB8(a178);
                    D_global_asm_807FDC90->unk2E = 0x64;
                    a178->unk18 = D_global_asm_807FDC9C->unkA_s16 != 0 ? D_global_asm_807FDC9C->unkA_s16 : 10.0f;
                }
                func_global_asm_80626F8C(a178->unk10, a178->unk12, a178->unk14, a178, &a178->unk4, 0, 1.0f, 0);
                break;

        }
        if (!func_global_asm_8061CC00()) {
            func_global_asm_8068C350(&func_global_asm_806B76B0, current_actor_pointer, 3);
        }
    }
}
*/

void func_global_asm_806B83E4(void) {
    u8 temp;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC90->unk30 = D_global_asm_807FDC9C->unkA_u8[1];
        func_global_asm_8066EB40(current_actor_pointer, 300.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 280.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
    }
    if (D_global_asm_807FDC90->unk30 <= 0.001) {
        D_global_asm_807FDC90->unk2C = D_global_asm_807FDC9C->unkA_u8[0];
        D_global_asm_807FDC90->unk30 = D_global_asm_807FDC9C->unkA_u8[1];
        func_global_asm_8066EA64(current_actor_pointer, 1);
        func_global_asm_80608528(current_actor_pointer, 0x182, 0xFF, 0x7F, 0x1E);
    }
    D_global_asm_807FDC90->unk30 -= 1.0;
    if ((D_global_asm_807FDC90->unk2C != 0) && ((object_timer % 5U) == 0)) {
        func_global_asm_807149FC(3);
        func_global_asm_807149B8(1);
        func_global_asm_80714950(-0x1C2);
        func_global_asm_8071498C(&func_global_asm_80717D4C);
        func_global_asm_80714CC0(&D_global_asm_807201D4, 1.2f, current_actor_pointer->x_position, current_actor_pointer->y_position + 7.0, current_actor_pointer->z_position);
    }
    if (D_global_asm_807FDC90->unk2C != 0) {
        func_global_asm_8065A708(current_actor_pointer->x_position, current_actor_pointer->y_position + 7.0, current_actor_pointer->z_position, 0.0f, 0.0f, 0.0f, 200.0f, 0, 0xFF, 0xC8, 0);
        D_global_asm_807FDC90->unk2C -= 1;
        if (D_global_asm_807FDC90->unk2C == 0) {
            func_global_asm_8066EA90(current_actor_pointer, 1);
        }
    }
}

void func_global_asm_806B86AC(void) {
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC90->unk2E = D_global_asm_807FDC98->unkB;
    }
    if (D_global_asm_807FDC90->unk2E == 0) {
        D_global_asm_807FDC90->unk2C = D_global_asm_807FDC98->cutscene_model_index;
        D_global_asm_807FDC90->unk2E = D_global_asm_807FDC98->unkB;
        func_global_asm_80608528(current_actor_pointer, 0x182, 0xFF, 0x7F, 0x1E);
    }
    D_global_asm_807FDC90->unk2E--;
    if ((D_global_asm_807FDC90->unk2C != 0) && ((object_timer % 5U) == 0)) {
        func_global_asm_806907F0(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        func_global_asm_80690A28(0x51, 1, 0.3f, D_global_asm_807FDC94->x_position, D_global_asm_807FDC94->y_position, D_global_asm_807FDC94->z_position, 80.0f, current_actor_pointer);
    }
    if (D_global_asm_807FDC90->unk2C != 0) {
        func_global_asm_8065A708(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position, 0.0f, 0.0f, 0.0f, 200.0f, 0, 0xFF, 0xC8, 0);
        D_global_asm_807FDC90->unk2C -= 1;
    }
}

void func_global_asm_806B8878(void) {
    func_global_asm_806B88B8();
}

void func_global_asm_806B8898(void) {
    func_global_asm_806B88B8();
}


void func_global_asm_806B88B8(void) {
    Actor178 *temp_v1;
    Actor178 *sp3C;
    s16 sp36;
    Actor17C *temp_s0;

    temp_v1 = current_actor_pointer->unk178;
    temp_s0 = current_actor_pointer->unk17C;
    sp3C = temp_v1;
    func_global_asm_80729B00();
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        D_global_asm_807FDC90->unk30 = D_global_asm_807FDC9C->unkA_u8[1];
        temp_v1->unk0 = D_global_asm_807FDC9C->unkD;
    }
    if (temp_v1->unk0 != 0) {
        temp_v1->unk0--;
        return;
    }
    if (D_global_asm_807FDC90->unk30 <= 0.001) {
        D_global_asm_807FDC90->unk2C = D_global_asm_807FDC9C->unkA_u8[0];
        D_global_asm_807FDC90->unk30 = D_global_asm_807FDC9C->unkA_u8[1];
        temp_s0->unk0_s16[0] = 0;
        func_global_asm_80608528(current_actor_pointer, 0x17, 0xFF, 0x7F, 0x19);
    }
    D_global_asm_807FDC90->unk30 -= 1.0;
    if ((D_global_asm_807FDC90->unk2C != 0) && (temp_s0->unk0_s16[0] == 0)) {
        func_global_asm_806907F0(current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
        switch (current_actor_pointer->unk58) {
            case ACTOR_CANNON_SEASICK_0:
                sp36 = 0x37;
                break;
            case ACTOR_FIREBALL_SPAWNER:
                sp36 = 0x1E;
                break;
        }
        func_global_asm_8069084C(sp36, 0, 0.6f, current_actor_pointer->y_rotation, D_global_asm_807FDC9C->unkC * 0xA, 0.0f, 0);
        D_global_asm_807FDC90->unk2C -= 1;
        temp_s0->unk0_s16[0] = D_global_asm_807FDC9C->unkF;
    }
    if (temp_s0->unk0_s16[0] != 0) {
        temp_s0->unk0_s16[0]--;
    }
}
