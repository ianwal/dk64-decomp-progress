#include <ultra64.h>
#include "functions.h"
#include "sprites.h"

extern SpriteData D_global_asm_8071FBA0; // TODO: Datatype

typedef struct {
    s32 unk0[3];
} Struct807502C0;

extern Struct807502C0 D_global_asm_807502C0;

extern s32 D_global_asm_8076A068;

extern u8 D_global_asm_807FBB85;
extern u16 **D_global_asm_807FC7C0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    u8 unk12;
    u8 unk13;
} AAD_global_asm_80697CEC;

// Displaylist stuff, close, stack
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_global_asm_80697230.s")

extern void *D_global_asm_80750280;

typedef struct Struct80697230 {
    s16 unk0;
    u8 pad2[2];
    Mtx *unk4;
    f32 unk8;
    u8 padC[0x10 - 0xC];
    u8 unk10;
    u8 unk11;
} Struct80697230;

/*
Gfx *func_global_asm_80697230(Gfx *dl, Actor *arg1) {
    Mtx sp154; // 154
    Mtx sp114; // 114
    Struct80697230 *AAD; // not on stack
    u8 idx; // not on stack
    s16 sp110; // 110
    s16 i; // Not on stack
    

    AAD = arg1->AAD_as_array[0];
    sp110 = 0x1000 / AAD->unk0;
    idx = (AAD->unk10++ % 16) + arg1->unk168;
    gSPDisplayList(dl++, &D_1000118);
    gSPMatrix(dl++, &D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dl++, &D_2000200, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPTexture(dl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(dl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetTextureFilter(dl++, G_TF_BILERP);
    gSPSetGeometryMode(dl++, G_ZBUFFER);
    gDPSetRenderMode(dl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_global_asm_8066E990(arg1);
    {
        f32 spE4; // e4

        if (arg1->unk15F != 0) {
            switch (AAD->unk11) {
            case 0:
                spE4 = AAD->unk8 * 10.0;
                break;
            case 1:
                spE4 = AAD->unk8 * 0.15 * 2048.0;
                break;
            }
            func_global_asm_8066EB40(arg1, spE4);
        }
        for (i = 0; i < AAD->unk0; i++) {
            f32 spE0; // e0
            f32 spDC; // dc
            f32 spD8; // d8
            f32 spD4; // d4
            s16 temp;
            f32 temp_f0_2; // not on stack

            temp = i * sp110;
            
            switch (AAD->unk11) {
            case 0:
                spD4 = 1.0f;
                spDC = 0.0f;
                spE0 = func_global_asm_80612794(temp) * AAD->unk8;
                spD8 = func_global_asm_80612790(temp) * AAD->unk8;
                break;
            case 1:
                temp_f0_2 = (MIN(1.0, (arg1->unkEE - arg1->unk15F) * 0.05) * 0.028999999999999998) + 0.001;
                spD4 = 130.0f * temp_f0_2;
                spDC = 1500.0f * temp_f0_2;
                spE0 = func_global_asm_80612794(arg1->y_rotation + 0x400) * (temp_f0_2 * AAD->unk8 * (0x800 - temp));
                spD8 = func_global_asm_80612790(arg1->y_rotation + 0x400) * (temp_f0_2 * AAD->unk8 * (0x800 - temp));
            }
            if (arg1->unk15F) {
                func_global_asm_8066E8E4(arg1, spE0, spDC, spD8, spD4 * 80.0, -1);
            }
            gDPLoadTextureBlock(dl++, D_global_asm_807FC7C0[idx], G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            guScaleF(&sp154, spD4, spD4, spD4);
            func_global_asm_80612C30(&sp114, ((character_change_array->unk2C8 * 0x168) / 4096));
            guMtxCatF(&sp154, &sp114, &sp154);
            guTranslateF(&sp114, arg1->x_position + spE0, arg1->y_position, arg1->z_position + spD8);
            guMtxCatF(&sp154, &sp114, &sp154);
            guMtxF2L(&sp154, &AAD->unk4[(i * 2) + D_global_asm_807444FC]);
            gSPMatrix(dl++, &AAD->unk4[(i * 2) + D_global_asm_807444FC], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(dl++, osVirtualToPhysical(&D_global_asm_80750280), 4, 0);
            gSP2Triangles(dl++, 0, 1, 2, 0, 0, 2, 3, 0);
            gDPPipeSync(dl++);
        }
    }
    return dl;
}
*/


void func_global_asm_806978FC(void) {
    s16 phi_s0;
    s16 i;

    phi_s0 = 0;
    D_global_asm_807FC7C0 = malloc(48 * sizeof(void*));
    for (i = 0; i < 48; i++) {
        D_global_asm_807FC7C0[phi_s0] = getPointerTableFile(0x19, phi_s0 + 0x1654, 1, 1);
        phi_s0++;
    }
}

// close, doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_9BF30/func_global_asm_80697988.s")

Gfx *func_global_asm_80697230(Gfx *, Actor *);

typedef struct {
    s16 unk0;
    s16 unk2;
    void* unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 unk11;
} AAD_global_asm_80697988;

/*
void func_global_asm_80697988(void) {
    AAD_global_asm_80697988 *aaD;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        current_actor_pointer->unkEE = current_actor_pointer->unk15F;
        aaD->unk4 = malloc(0x1000);
        if (current_actor_pointer->unk15F != 0) {
            current_actor_pointer->noclip_byte = 0x24;
        }
        if (aaD->unk11 == 1) {
            func_global_asm_80604CBC(current_actor_pointer, 0x128, 1, 1, 0, 0xFF, 0.2f, 0);
            func_global_asm_80604CBC(current_actor_pointer, 0x139, 0x3C, 1, 1, 0xFF, 1.0f, 0);
        }
    }
    switch (aaD->unk11) {
        case 1:
            current_actor_pointer->x_position += aaD->unkC * func_global_asm_80612794(current_actor_pointer->y_rotation);
            current_actor_pointer->z_position += aaD->unkC * func_global_asm_80612790(current_actor_pointer->y_rotation);
            if (current_actor_pointer->unk15F != 0) {
                current_actor_pointer->unk15F--;
            }
            if (current_actor_pointer->unk168 == 0x20) {
                current_actor_pointer->unk168 = 0x10;
                aaD->unk10 = 0;
            }
            if (aaD->unk10 >= 0x10) {
                free(aaD->unk4);
                deleteActor(current_actor_pointer);
            }
            break;
        case 0:
            if (current_actor_pointer->unk15F != 0) {
                aaD->unk8 += aaD->unkC;
                aaD->unk0 = MIN(aaD->unk8 * 0.3, 32.0);
            } else {
                aaD->unk8 += (((current_actor_pointer->unk168 - aaD->unk10) + 0x10) * (aaD->unkC * 0.0625));
            }
            if ((aaD->unk10 - current_actor_pointer->unk168) >= 0x10) {
                current_actor_pointer->unk15F--;
                if (current_actor_pointer->unk15F != 0) {
                    func_global_asm_80691930(0, aaD->unk0, aaD->unk8, aaD->unkC, 0, 0x10);
                    if (current_actor_pointer->unk15F == 0) {
                        current_actor_pointer->unk168 = 0x10;
                    } else {
                        aaD->unk10 = 0;
                    }
                } else {
                    free(aaD->unk4);
                    deleteActor(current_actor_pointer);
                }
            }
            break;
    }
    addActorToTextOverlayRenderArray(func_global_asm_80697230, current_actor_pointer, 1);
}
*/

void func_global_asm_80697CEC(void) {
    AAD_global_asm_80697CEC *aaD;
    Struct807502C0 sp68;

    aaD = current_actor_pointer->additional_actor_data;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        sp68 = D_global_asm_807502C0;
        current_actor_pointer->unk6E[0] = -2;
        current_actor_pointer->unk6A &= ~1;
        current_actor_pointer->unkEE = (current_actor_pointer->unk124->unk0 / 6.283185482f) * 4095.0f;
        current_actor_pointer->unkB8 = current_actor_pointer->unk124->unk4;
        current_actor_pointer->y_velocity = current_actor_pointer->unk124->unk8;
        current_actor_pointer->noclip_byte = 0x3C;
        func_global_asm_8066EB40(current_actor_pointer, 40.0f);
        func_global_asm_8066E8E4(current_actor_pointer, 0.0f, 0.0f, 0.0f, 30.0f, -1);
        func_global_asm_8066E854(current_actor_pointer, 0.0f, 0.0f, 0.0f, -1);
        aaD->unk13 = current_actor_pointer->unk124->unk10;
        func_global_asm_807149FC(-1);
        func_global_asm_80714998(2);
        func_global_asm_807149B8(1);
        func_global_asm_807149A8(0x7D0);
        if (aaD->unk13 == 1) {
            changeActorColor(0, 0xFF, 0, 0xC8);
        } else {
            changeActorColor(0xFF, 0xFF, 0xFF, 0xFF);
        }
        if (aaD->unk13 == 3) {
            func_global_asm_8071498C(func_global_asm_8071F758);
        }
        func_global_asm_80714C08(sp68.unk0[aaD->unk13 - 1], current_actor_pointer->unk124->unkC, current_actor_pointer, 1, 2);
        aaD->unk0 = D_global_asm_8076A068;
        aaD->unk12 = 0;
        current_actor_pointer->object_properties_bitfield |= 0x80000;
        current_actor_pointer->control_state_progress = aaD->unk13;
    }
    func_global_asm_8067ACB4(current_actor_pointer);
    func_global_asm_806651FC(current_actor_pointer);
    func_global_asm_80665564(current_actor_pointer, 4.0f);
    func_global_asm_8065D254(current_actor_pointer, 0x3C8, 0x40, 0x40, 0x14, 0x14, 1, 0x96, 0x78, 0, 1.0f);
    if ((current_actor_pointer->unk6A & 1) || (current_actor_pointer->unkFC != 0) || (D_global_asm_807FBB85 != 0)) {
        if (aaD->unk13 == 3) {
            playSoundAtActorPosition(current_actor_pointer, 0x16, 0xFF, 0x7F, 0x14);
        }
        if (D_global_asm_807FBB85 == 0) {
            s16 i;
            for (i = 0; i < 0xC; i += 2) {
                func_global_asm_807149B8(1);
                func_global_asm_80714950(i + 0x0B000000);
                func_global_asm_8071498C(func_global_asm_8071ABDC);
                drawSpriteAtPosition(&D_global_asm_8071FBA0, (((rand() >> 0xF) % 10) * 0.05) + 0.2, current_actor_pointer->x_position, current_actor_pointer->y_position, current_actor_pointer->z_position);
            }
        }
        deleteActor(current_actor_pointer);
    }
}
