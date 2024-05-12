#include <ultra64.h>
#include "functions.h"

const u16 D_global_asm_8075A740[] = {
    0, 0, 0, 0
};

extern u8 D_global_asm_807503F0;

typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
} Struct80750400;

extern Struct80750400 D_global_asm_80750400[];

int func_global_asm_806A4284();
void func_global_asm_806A4DDC(Actor *arg0);
void func_global_asm_806A5174(Actor*, void*, f32);
void func_global_asm_806A5DF0(s16 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, u8 arg5, s16 arg6, s32 arg7);

void func_global_asm_8070DA74(Actor*);
void func_global_asm_8070E808(Actor *arg0, Actor *arg1);

void func_global_asm_806A3700(s32 arg0, s32 arg1) {

}

// Displaylist stuff (matrix), doable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A370C.s")

void func_global_asm_806A3B78(s32 *arg0, AAD_global_asm_806A4DDC *arg1, Struct806A57C0_2 *arg2, u8 arg3, u8 *arg4) {
    s32 sp44;
    s32 i;
    Struct806A57C0_3 *var_s0;

    sp44 = *arg0;
    var_s0 = arg2->unkC;
    i = 0;
    while ((var_s0 != NULL) && (*arg4 == 0)) {
        if (arg3 && (i == arg1->unk11)) {
            *arg4 = 1;
        }
        if (arg2->unk0 & 1) {
            func_global_asm_806A370C(&sp44, arg1, arg2, var_s0);
        }
        var_s0 = var_s0->unkA0;
        i += 1;
    }
    *arg0 = sp44;
}

Gfx *func_global_asm_806A3C6C(Gfx *dl, s32 arg1, u8 arg2, s32 arg3) {
    void *texture;

    texture = func_global_asm_8068C12C(0x52 + arg3);
    gDPPipeSync(dl++);
    gDPSetPrimColor(dl++, 0, 0, 0xFF, 0xFF, 0xFF, arg2);
    gSPMatrix(dl++, arg1, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_global_asm_80702464(&dl, texture, 3, 0x60, 0x40, 0x20, 0x20, 0.0f, 0.0f, 96.0f, 64.0f, 0.0f, 0.0f, 1, 8);
    gSPPopMatrix(dl++, G_MTX_MODELVIEW);
    gDPPipeSync(dl++);
    return dl;
}

// stack, close
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A3DA0.s")

void func_global_asm_806A3DA0(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, AAD_global_asm_806A4DDC *arg4);

/*
void func_global_asm_806A3DA0(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, AAD_global_asm_806A4DDC *arg4) {
    f32 sp20;

    sp20 = arg2 * 3000.0f;
    *arg0 += arg2 * arg3 * 24.0f * func_global_asm_80612794((s16)(arg4->unk38 + sp20) & 0xFFF);
    *arg1 += arg2 * arg3 * 16.0f * func_global_asm_80612790((s16)(arg4->unk3A + sp20) & 0xFFF);
}
*/

// Matrix stuff
// rodata
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A3E9C.s")

// Displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A4284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A495C.s")

/*
void func_global_asm_806A495C(void *arg0, void *arg1, void *arg2) {
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 temp_f2;
    s32 temp_v0;
    void *temp_v1;
    void *temp_v1_2;

    sp38 = arg0->unk0 * 0.5f;
    temp_f2 = arg0->unk4;
    sp34 = temp_f2;
    sp30 = arg0->unk8;
    if (arg0->unk14 == 0) {
        sp34 = temp_f2;
        func_global_asm_807149FC(-1);
        func_global_asm_807149B8(0);
        func_global_asm_8071495C();
        func_global_asm_80714998(2);
        func_global_asm_80714A68(arg2->unk44, arg2->unk48, arg2->unk4C, arg2->unk50);
        temp_v1 = &arg0->unk10;
        temp_v0 = drawSpriteAtPosition(D_global_asm_80755390[temp_v1->unk0], 1.0f, arg2->unk44, arg2->unk48, 1.0f);
        temp_v1->unk4 = temp_v0;
        if (temp_v1->unk2 != 0) {
            temp_v0->unk360 = temp_v0->unk360 * -1.0f;
        }
    }
    temp_v1_2 = &arg0->unk10;
    temp_v1_2->unk4->unk340 = (arg2->unk44 + (sp34 + sp38)) * 4.0;
    temp_v1_2->unk4->unk344 = (arg2->unk48 + (sp30 + (arg1->unk18 * 0.5f))) * 4.0;
    temp_v1_2->unk4->unk36D = arg0->unk3;
    temp_v1_2->unk4->unk38E = arg2->unk44;
    temp_v1_2->unk4->unk390 = arg2->unk48;
    temp_v1_2->unk4->unk392 = arg2->unk4C;
    temp_v1_2->unk4->unk394 = arg2->unk50;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A4B84.s")

void func_global_asm_806A4B84(f32 arg0, Actor *arg1, AAD_global_asm_806A4DDC *arg2, Struct806A57C0_2 *arg3, u8 arg4, u8 *arg5);

/*
// TODO: Progress made, fiddly
void func_global_asm_806A4B84(f32 arg0, Actor *arg1, AAD_global_asm_806A4DDC *arg2, Struct806A57C0_2 *arg3, u8 arg4, u8 *arg5) {
    f32 var_f20;
    s32 var_a0;
    s32 i;
    u8 var_a0_2;
    Struct806A57C0_3 *var_s0;

    i = 0;
    var_s0 = arg3->unkC;
    var_f20 = (136.800003051757812 - arg3->unk14) * 0.5;
    while ((var_s0 != NULL) && (*arg5 == 0)) {
        if ((arg4 != 0) && (i == arg2->unk11)) {
            if (!(arg2->unk55 & 4)) {
                *arg5 = 1;
            }
            if (arg1->control_state == 1) {
                if ((i == 0) && (var_s0->unk2 == 0)) {
                    func_global_asm_806A3700(arg2->unk4, arg3->unk8);
                }
                if (var_s0->unk2 != 0xFF) {
                    var_a0 = 0x96;
                    if (arg2->unk55 & 2) {
                        var_a0 = 0x96 * 0.5;
                    }
                    if (!(arg2->unk55 & 4) && (var_a0 < (0xFF - var_s0->unk2))) {
                        var_s0->unk2 += var_a0;
                    } else {
                        var_s0->unk2 = 0xFF;
                        if (var_s0->unkA0 != NULL) {
                            arg2->unk11++;
                        } else {
                            arg2->unk11 = 0;
                            arg2->unk10++;
                            *arg5 = 1;
                            if (arg3->unk10 != 0) {
                                arg1->control_state = 3;
                                arg2->unk12 = arg3->unk10;
                            }
                        }
                    }
                }
            }
        }
        var_a0_2 = MIN(arg2->unk1D, var_s0->unk2);
        var_s0->unk4 = var_f20;
        var_s0->unk8 = arg0;
        var_s0->unk3 = var_a0_2;
        if (arg3->unk0 & 2) {
            func_global_asm_806A495C(var_s0, arg3, arg2);
        }
        var_f20 += var_s0->unk0;
        var_s0 = var_s0->unkA0;
        i += 1;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A4DDC.s")

/*
// TODO: Progress made, fiddly
void func_global_asm_806A4DDC(Actor *arg0) {
    u8 sp103;
    f32 sp50;
    f32 temp_f2_5;
    f32 var_f0;
    f32 var_f22;
    f64 temp_f0;
    f64 temp_f2;
    s32 var_s0;
    u8 var_v0;
    void *temp_a0;
    void *temp_a3;
    AAD_global_asm_806A4DDC *aaD;
    Struct806A57C0_2 *var_s1;

    aaD = arg0->additional_actor_data;
    var_s1 = aaD->unkC;
    sp103 = FALSE;
    var_f0 = (1.0f - aaD->unk20) * 1.47058823529411775;
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    }
    aaD->unk40 = var_f0;
    func_global_asm_806A3DA0(&arg0->x_position, &arg0->y_position, aaD->unk20, var_f0, aaD);
    temp_f0 = (aaD->unk20 * 136.8000031f) * 0.5;
    aaD->unk44 = arg0->x_position - temp_f0;
    temp_f2 = (aaD->unk20 * 79.79999542f) * 0.5;
    aaD->unk48 = arg0->y_position - temp_f2;
    aaD->unk4C = arg0->x_position + temp_f0;
    aaD->unk50 = arg0->y_position + temp_f2;

    aaD->unk44 = MAX(aaD->unk44, character_change_array->unk270);
    aaD->unk48 = MAX(aaD->unk48, character_change_array->unk272);
    aaD->unk4C = MAX(aaD->unk4C, character_change_array->unk274);
    aaD->unk50 = MAX(aaD->unk50, character_change_array->unk276);

    var_f22 = aaD->unk14;
    var_s0 = 0;
    while ((aaD->unk10 >= var_s0) && (var_s1 != NULL) && (sp103 == 0)) {
        temp_f2_5 = var_f22 + var_s1->unk18;
        if ((73.7999954223632812 < temp_f2_5) && (arg0->control_state == 1)) {
            arg0->control_state = 2;
            aaD->unk18 = temp_f2_5 - 73.7999954223632812;
            sp103 = TRUE;
        } else {
            temp_a3 = var_s1;
            if ((temp_f2_5 < 0.0f) && (arg0->control_state == 2)) {
                temp_a0 = var_s1;
                var_s0 -= 1;
                var_f22 = temp_f2_5;
                aaD->unk14 = aaD->unk14 + var_s1->unk18;
                aaD->unkC = var_s1->unk1C;
                aaD->unk10 = aaD->unk10 - 1;
                var_s1 = var_s1->unk1C;
                func_global_asm_8070D9AC(temp_a0);
            } else {
                sp50 = temp_f2_5;
                func_global_asm_806A4B84(var_f22, arg0, aaD, temp_a3, (var_s0 == aaD->unk10), &sp103);
                if (sp103 == 0) {
                    var_s1 = var_s1->unk1C;
                    var_f22 = sp50;
                }
            }
        }
        var_s0 += 1;
    }
    var_v0 = arg0->control_state;
    if (var_v0 == 3) {
        var_v0 = 1 & 0xFF;
        if (aaD->unk12 != 0) {
            aaD->unk12--;
            var_v0 = arg0->control_state;
        } else {
            arg0->control_state = 1;
        }
    }
    if ((var_v0 == 1) && (var_s1 == NULL)) {
        func_global_asm_8070E808(arg0, aaD->unk4);
    }
}
*/

// Jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A5174.s")

void func_global_asm_806A57C0(AAD_global_asm_806A4DDC *arg0) {
    s32 var_v0;
    Struct806A57C0_2 *var_v1;

    var_v0 = 0;
    var_v1 = arg0->unkC;
    if ((var_v1 != NULL) && (var_v1->unkC->unk2 == 0)) {
        while (var_v1 != NULL) {
            var_v0 += var_v1->unk18;
            var_v1 = var_v1->next;
        }
        if (var_v0 < 79.7999954223632812) {
            arg0->unk14 = (79.7999954223632812 - var_v0) * 0.5;
        } else {
            arg0->unk14 = 6.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A5868.s")

/*
// TODO: Extremely close, one statement left to fix
void func_global_asm_806A5868(void) {
    AAD_global_asm_806A4DDC *var_a3;
    f32 sp18;
    f32 var_f0;
    s32 var_v0_2;
    f32 temp;

    var_a3 = current_actor_pointer->additional_actor_data;
    sp18 = 0.05000000075f;
    if (!(current_actor_pointer->object_properties_bitfield & 0x10)) {
        sp18 = 1.0f;
        var_a3->unk34 = malloc(0x280);
        var_a3->unk55 = 0;
    } else {
        if (!(var_a3->unk55 & 1)) {
            if ((current_actor_pointer->control_state != 4) && (current_actor_pointer->control_state != 5)) {
                if (var_a3->unk0 > 15.0) {
                    if (newly_pressed_input_copy & B_BUTTON) {
                        var_a3->unk55 |= 1;
                    }
                    if (D_global_asm_807ECD58.unk0 & Z_TRIG) {
                        var_a3->unk55 |=  2;
                    } else {
                        var_a3->unk55 &= 0xFFFD;
                    }
                    if (!(var_a3->unk55 & 2) && (D_global_asm_807ECD58.unk0 == A_BUTTON)) {
                        var_a3->unk55 |= 4;
                    } else {
                        var_a3->unk55 &= 0xFFFB;
                    }
                    if (var_a3->unk55 & 1) {
                        // func_global_asm_8061CB08(0x280, current_actor_pointer, var_a3);
                        func_global_asm_8061CB08();
                        current_actor_pointer->control_state = 5;
                    }
                }
            }
        }
    }
    var_a3->unk38 += 0x14;
    var_a3->unk3A += 0x32;
    switch (current_actor_pointer->control_state) {
        case 0:
            if (var_a3->unk0 < 0x1E) {
                var_a3->unk0++;
            } else {
                current_actor_pointer->control_state = 1;
                var_a3->unk1D = D_global_asm_807503F0;
                func_global_asm_8070E808(current_actor_pointer, var_a3->unk4);
                func_global_asm_806A57C0(var_a3);
            }
            break;
        case 2:
            var_f0 = 2.0f;
            if (var_a3->unk55 & 4) {
                temp = 3.0f;
                var_f0 = 2.0f * temp;
            } else if (var_a3->unk55 & 2) {
                temp = 0.5f;
                var_f0 = 2.0f * temp;
            }
            if (!(var_f0 < var_a3->unk18)) {
                var_f0 = var_a3->unk18;
            }
            var_a3->unk14 -= var_f0;
            var_a3->unk18 -= var_f0;
            if (var_a3->unk18 < 0.0001) {
                current_actor_pointer->control_state = 1;
            }
            break;
        case 4:
            if (var_a3->unk1D != 0) {
                // Option 1
                // if (var_a3->unk1D >= 0x34) {
                //     var_v0_2 = 0x33;
                // } else {
                //     var_v0_2 = var_a3->unk1D;
                // }
                // var_a3->unk1D -= var_v0_2;

                // Option 2
                var_v0_2 = MIN(0x33, var_a3->unk1D);
                var_a3->unk1D -= var_v0_2;

                // Option 3
                // var_v0_2 = (var_a3->unk1D >= 0x34) ? 0x33 : var_a3->unk1D;
                // var_a3->unk1D -= var_v0_2;

                // Option 4
                // var_a3->unk1D -= MIN(0x33, var_a3->unk1D);

                // Option 5
                // if (var_a3->unk1D >= 0x34) {
                //     var_a3->unk1D -= 0x33;
                // } else {
                //     var_a3->unk1D -= var_a3->unk1D;
                // }
            } else {
                if (var_a3->unk0 != 0) {
                    if (var_a3->unkC != 0) {
                        func_global_asm_8070DA28(var_a3);
                    }
                    var_a3->unk0--;
                } else {
                    current_actor_pointer->control_state = 5;
                }
            }
            break;
        case 5:
            func_global_asm_8070DA74(var_a3->unk4);
            break;
    }
    if (current_actor_pointer->control_state != 5) {
        var_a3->unk20 = var_a3->unk0 * 0.03333333507f;
        func_global_asm_806A5174(current_actor_pointer, var_a3, sp18);
        if (var_a3->unk0 != 0) {
            func_global_asm_806A4DDC(current_actor_pointer);
            addActorToTextOverlayRenderArray(&func_global_asm_806A4284, current_actor_pointer, 3);
        }
    }
}
*/

// TODO: Progress made, kinda fiddly, last loop is sus
#pragma GLOBAL_ASM("asm/nonmatchings/global_asm/code_A8400/func_global_asm_806A5C60.s")

/*
void func_global_asm_806A5C60(Actor *arg0) {
    s32 var_a1;
    s32 j;
    s16 var_s3;
    s32 i;
    u8 temp_v0;

    i = 0;
    var_a1 = FALSE;
    var_s3 = 0;
    if ((cc_number_of_players < 2) && !(D_global_asm_807FBB64 & 0x4000)) {
        while (var_a1 == 0 && D_global_asm_80750400[i].unk0 != 0) {
            if (arg0->unk58 == D_global_asm_80750400[i].unk0) {
                var_a1 = TRUE;
            } else {
                i++;
            }
        }
        if (var_a1 != FALSE) {
            if (D_global_asm_80750400[i].unk4 != 0) {
                playSong(D_global_asm_80750400[i].unk4, 1.0f);
            }
            for (j = 0; j < D_global_asm_80750400[i].unk5; j++) {
                var_s3 += (0xFFF / D_global_asm_80750400[i].unk5);
                func_global_asm_806A5DF0(D_global_asm_80750400[i].unk2, arg0->x_position, arg0->y_position, arg0->z_position, var_s3, 1, -1, 0);
            }
        }
    }
}
*/
